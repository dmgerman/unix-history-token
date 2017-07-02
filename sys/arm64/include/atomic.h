begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Andrew Turner<andrew@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_define
define|#
directive|define
name|isb
parameter_list|()
value|__asm __volatile("isb" : : : "memory")
end_define

begin_comment
comment|/*  * Options for DMB and DSB:  *	oshld	Outer Shareable, load  *	oshst	Outer Shareable, store  *	osh	Outer Shareable, all  *	nshld	Non-shareable, load  *	nshst	Non-shareable, store  *	nsh	Non-shareable, all  *	ishld	Inner Shareable, load  *	ishst	Inner Shareable, store  *	ish	Inner Shareable, all  *	ld	Full system, load  *	st	Full system, store  *	sy	Full system, all  */
end_comment

begin_define
define|#
directive|define
name|dsb
parameter_list|(
name|opt
parameter_list|)
value|__asm __volatile("dsb " __STRING(opt) : : : "memory")
end_define

begin_define
define|#
directive|define
name|dmb
parameter_list|(
name|opt
parameter_list|)
value|__asm __volatile("dmb " __STRING(opt) : : : "memory")
end_define

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|dmb(sy)
end_define

begin_comment
comment|/* Full system memory barrier all */
end_comment

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|dmb(st)
end_define

begin_comment
comment|/* Full system memory barrier store */
end_comment

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|dmb(ld)
end_define

begin_comment
comment|/* Full system memory barrier load */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_OP
parameter_list|(
name|op
parameter_list|,
name|asm_op
parameter_list|,
name|bar
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
define|\
value|static __inline void							\ atomic_##op##_##bar##32(volatile uint32_t *p, uint32_t val)		\ {									\ 	uint32_t tmp;							\ 	int res;							\ 									\ 	__asm __volatile(						\ 	    "1: ld"#a"xr   %w0, [%2]      \n"				\ 	    "   "#asm_op"  %w0, %w0, %w3  \n"				\ 	    "   st"#l"xr   %w1, %w0, [%2] \n"				\             "   cbnz       %w1, 1b        \n"				\ 	    : "=&r"(tmp), "=&r"(res)					\ 	    : "r" (p), "r" (val)					\ 	    : "memory"							\ 	);								\ }									\ 									\ static __inline void							\ atomic_##op##_##bar##64(volatile uint64_t *p, uint64_t val)		\ {									\ 	uint64_t tmp;							\ 	int res;							\ 									\ 	__asm __volatile(						\ 	    "1: ld"#a"xr   %0, [%2]      \n"				\ 	    "   "#asm_op"  %0, %0, %3    \n"				\ 	    "   st"#l"xr   %w1, %0, [%2] \n"				\             "   cbnz       %w1, 1b       \n"				\ 	    : "=&r"(tmp), "=&r"(res)					\ 	    : "r" (p), "r" (val)					\ 	    : "memory"							\ 	);								\ }
end_define

begin_define
define|#
directive|define
name|ATOMIC
parameter_list|(
name|op
parameter_list|,
name|asm_op
parameter_list|)
define|\
value|ATOMIC_OP(op, asm_op,     ,  ,  )					\     ATOMIC_OP(op, asm_op, acq_, a,  )					\     ATOMIC_OP(op, asm_op, rel_,  , l)					\  ATOMIC(add,      add)
end_define

begin_macro
name|ATOMIC
argument_list|(
argument|clear
argument_list|,
argument|bic
argument_list|)
end_macro

begin_macro
name|ATOMIC
argument_list|(
argument|set
argument_list|,
argument|orr
argument_list|)
end_macro

begin_macro
name|ATOMIC
argument_list|(
argument|subtract
argument_list|,
argument|sub
argument_list|)
end_macro

begin_define
define|#
directive|define
name|ATOMIC_FCMPSET
parameter_list|(
name|bar
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
define|\
value|static __inline int							\ atomic_fcmpset_##bar##32(volatile uint32_t *p, uint32_t *cmpval,	\     uint32_t newval)		 					\ {									\ 	uint32_t tmp;							\ 	uint32_t _cmpval = *cmpval;					\ 	int res;							\ 									\ 	__asm __volatile(						\ 	    "1: mov      %w1, #1        \n"				\ 	    "   ld"#a"xr %w0, [%2]      \n"				\ 	    "   cmp      %w0, %w3       \n"				\ 	    "   b.ne     2f             \n"				\ 	    "   st"#l"xr %w1, %w4, [%2] \n"				\ 	    "2:"							\ 	    : "=&r"(tmp), "=&r"(res)					\ 	    : "r" (p), "r" (_cmpval), "r" (newval)			\ 	    : "cc", "memory"						\ 	);								\ 	*cmpval = tmp;							\ 									\ 	return (!res);							\ }									\ 									\ static __inline int							\ atomic_fcmpset_##bar##64(volatile uint64_t *p, uint64_t *cmpval,	\     uint64_t newval)							\ {									\ 	uint64_t tmp;							\ 	uint64_t _cmpval = *cmpval;					\ 	int res;							\ 									\ 	__asm __volatile(						\ 	    "1: mov      %w1, #1       \n"				\ 	    "   ld"#a"xr %0, [%2]      \n"				\ 	    "   cmp      %0, %3        \n"				\ 	    "   b.ne     2f            \n"				\ 	    "   st"#l"xr %w1, %4, [%2] \n"				\ 	    "2:"							\ 	    : "=&r"(tmp), "=&r"(res)					\ 	    : "r" (p), "r" (_cmpval), "r" (newval)			\ 	    : "cc", "memory"						\ 	);								\ 	*cmpval = tmp;							\ 									\ 	return (!res);							\ }
end_define

begin_macro
name|ATOMIC_FCMPSET
argument_list|(
argument_list|,
argument_list|, )
end_macro

begin_macro
name|ATOMIC_FCMPSET
argument_list|(
argument|acq_
argument_list|,
argument|a
argument_list|, )
end_macro

begin_macro
name|ATOMIC_FCMPSET
argument_list|(
argument|rel_
argument_list|,
argument_list|,
argument|l
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|ATOMIC_FCMPSET
end_undef

begin_define
define|#
directive|define
name|ATOMIC_CMPSET
parameter_list|(
name|bar
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
define|\
value|static __inline int							\ atomic_cmpset_##bar##32(volatile uint32_t *p, uint32_t cmpval,		\     uint32_t newval)							\ {									\ 	uint32_t tmp;							\ 	int res;							\ 									\ 	__asm __volatile(						\ 	    "1: mov      %w1, #1        \n"				\ 	    "   ld"#a"xr %w0, [%2]      \n"				\ 	    "   cmp      %w0, %w3       \n"				\ 	    "   b.ne     2f             \n"				\ 	    "   st"#l"xr %w1, %w4, [%2] \n"				\             "   cbnz     %w1, 1b        \n"				\ 	    "2:"							\ 	    : "=&r"(tmp), "=&r"(res)					\ 	    : "r" (p), "r" (cmpval), "r" (newval)			\ 	    : "cc", "memory"							\ 	);								\ 									\ 	return (!res);							\ }									\ 									\ static __inline int							\ atomic_cmpset_##bar##64(volatile uint64_t *p, uint64_t cmpval,		\     uint64_t newval)							\ {									\ 	uint64_t tmp;							\ 	int res;							\ 									\ 	__asm __volatile(						\ 	    "1: mov      %w1, #1       \n"				\ 	    "   ld"#a"xr %0, [%2]      \n"				\ 	    "   cmp      %0, %3        \n"				\ 	    "   b.ne     2f            \n"				\ 	    "   st"#l"xr %w1, %4, [%2] \n"				\             "   cbnz     %w1, 1b       \n"				\ 	    "2:"							\ 	    : "=&r"(tmp), "=&r"(res)					\ 	    : "r" (p), "r" (cmpval), "r" (newval)			\ 	    : "cc", "memory"							\ 	);								\ 									\ 	return (!res);							\ }
end_define

begin_macro
name|ATOMIC_CMPSET
argument_list|(
argument_list|,
argument_list|, )
end_macro

begin_macro
name|ATOMIC_CMPSET
argument_list|(
argument|acq_
argument_list|,
argument|a
argument_list|, )
end_macro

begin_macro
name|ATOMIC_CMPSET
argument_list|(
argument|rel_
argument_list|,
argument_list|,
argument|l
argument_list|)
end_macro

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_fetchadd_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|,
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w2, [%3]      \n"
literal|"   add	%w0, %w2, %w4  \n"
literal|"   stxr	%w1, %w0, [%3] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_fetchadd_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|,
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%2, [%3]      \n"
literal|"   add	%0, %2, %4    \n"
literal|"   stxr	%w1, %0, [%3] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w1, [%2]      \n"
literal|"   stxr	%w0, wzr, [%2] \n"
literal|"   cbnz	%w0, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_readandclear_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%1, [%2]      \n"
literal|"   stxr	%w0, xzr, [%2] \n"
literal|"   cbnz	%w0, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_swap_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   stxr	%w1, %w3, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   stxr	%w1, %3, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_load_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"ldar	%w0, [%1] \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_load_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"ldar	%0, [%1] \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_store_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile(
literal|"stlr	%w0, [%1] \n"
operator|:
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_store_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
asm|__asm __volatile(
literal|"stlr	%0, [%1] \n"
operator|:
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|atomic_add_int
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_int
value|atomic_fcmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_int
value|atomic_fetchadd_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_int
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_set_int
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_swap_int
value|atomic_swap_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_int
value|atomic_fcmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_int
value|atomic_load_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_int
value|atomic_fcmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_clear_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
value|atomic_cmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
value|atomic_store_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_add_long
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_long
value|atomic_fcmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_long
value|atomic_fetchadd_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_64
end_define

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_swap_long
value|atomic_swap_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_ptr
value|atomic_fcmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_ptr
value|atomic_fetchadd_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_64
end_define

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_swap_ptr
value|atomic_swap_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_long
value|atomic_fcmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
value|atomic_load_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_ptr
value|atomic_fcmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_clear_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
value|atomic_subtract_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_long
value|atomic_fcmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_long
value|atomic_store_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_ptr
value|atomic_fcmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
value|atomic_subtract_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_64
end_define

begin_function
unit|static
name|__inline
name|void
name|atomic_thread_fence_acq
parameter_list|(
name|void
parameter_list|)
block|{
name|dmb
argument_list|(
name|ld
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_rel
parameter_list|(
name|void
parameter_list|)
block|{
name|dmb
argument_list|(
name|sy
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_acq_rel
parameter_list|(
name|void
parameter_list|)
block|{
name|dmb
argument_list|(
name|sy
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_seq_cst
parameter_list|(
name|void
parameter_list|)
block|{
name|dmb
argument_list|(
name|sy
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_H_ */
end_comment

end_unit

