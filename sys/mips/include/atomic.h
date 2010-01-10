begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: src/sys/alpha/include/atomic.h,v 1.21.2.3 2005/10/06 18:12:05 jhb  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Note: All the 64-bit atomic operations are only atomic when running  * in 64-bit mode.  It is assumed that code compiled for n32 and n64  * fits into this definition and no further safeties are needed.  *  * It is also assumed that the add, subtract and other arithmetic is  * done on numbers not pointers.  The special rules for n32 pointers  * do not have atomic operations defined for them, but generally shouldn't  * need atomic operations.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mips_sync
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile (".set noreorder\n\t"
literal|"sync\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|".set reorder\n"
operator|:
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|mb
parameter_list|()
value|mips_sync()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mips_sync()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mips_sync()
end_define

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts and SMP safe.  */
end_comment

begin_macro
unit|void
name|atomic_set_8
argument_list|(
argument|__volatile uint8_t *
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|atomic_clear_8
parameter_list|(
name|__volatile
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_8
parameter_list|(
name|__volatile
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_8
parameter_list|(
name|__volatile
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_set_16
parameter_list|(
name|__volatile
name|uint16_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_16
parameter_list|(
name|__volatile
name|uint16_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_16
parameter_list|(
name|__volatile
name|uint16_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_16
parameter_list|(
name|__volatile
name|uint16_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|atomic_set_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tll	%0, %3\n\t"
comment|/* load old value */
literal|"or	%0, %2, %0\n\t"
comment|/* calculate new value */
literal|"sc	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|atomic_clear_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|temp
decl_stmt|;
name|v
operator|=
operator|~
name|v
expr_stmt|;
asm|__asm __volatile (
literal|"1:\tll	%0, %3\n\t"
comment|/* load old value */
literal|"and	%0, %2, %0\n\t"
comment|/* calculate new value */
literal|"sc	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|atomic_add_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tll	%0, %3\n\t"
comment|/* load old value */
literal|"addu	%0, %2, %0\n\t"
comment|/* calculate new value */
literal|"sc	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|atomic_subtract_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tll	%0, %3\n\t"
comment|/* load old value */
literal|"subu	%0, %2\n\t"
comment|/* calculate new value */
literal|"sc	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|uint32_t
name|atomic_readandclear_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|addr
parameter_list|)
block|{
name|uint32_t
name|result
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tll	 %0,%3\n\t"
comment|/* load current value, asserting lock */
literal|"li	 %1,0\n\t"
comment|/* value to store */
literal|"sc	 %1,%2\n\t"
comment|/* attempt to store */
literal|"beqz	 %1, 1b\n\t"
comment|/* if the store failed, spin */
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|result
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_readandset_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|addr
parameter_list|,
name|uint32_t
name|value
parameter_list|)
block|{
name|uint32_t
name|result
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tll	 %0,%3\n\t"
comment|/* load current value, asserting lock */
literal|"or      %1,$0,%4\n\t"
literal|"sc	 %1,%2\n\t"
comment|/* attempt to store */
literal|"beqz	 %1, 1b\n\t"
comment|/* if the store failed, spin */
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
operator|,
literal|"r"
operator|(
name|value
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|result
return|;
end_return

begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_function
unit|static
name|__inline
name|void
name|atomic_set_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
name|uint64_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	%0, %3\n\t"
comment|/* load old value */
literal|"or	%0, %2, %0\n\t"
comment|/* calculate new value */
literal|"scd	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|atomic_clear_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
name|uint64_t
name|temp
decl_stmt|;
name|v
operator|=
operator|~
name|v
expr_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	%0, %3\n\t"
comment|/* load old value */
literal|"and	%0, %2, %0\n\t"
comment|/* calculate new value */
literal|"scd	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|atomic_add_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
name|uint64_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	%0, %3\n\t"
comment|/* load old value */
literal|"daddu	%0, %2, %0\n\t"
comment|/* calculate new value */
literal|"scd	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|atomic_subtract_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
name|uint64_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	%0, %3\n\t"
comment|/* load old value */
literal|"dsubu	%0, %2\n\t"
comment|/* calculate new value */
literal|"scd	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
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
name|uint64_t
name|atomic_readandclear_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|addr
parameter_list|)
block|{
name|uint64_t
name|result
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	 %0, %3\n\t"
comment|/* load old value */
literal|"li	 %1, 0\n\t"
comment|/* value to store */
literal|"scd	 %1, %2\n\t"
comment|/* attempt to store */
literal|"beqz	 %1, 1b\n\t"
comment|/* if the store failed, spin */
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|result
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_readandset_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|addr
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
name|uint64_t
name|result
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	 %0,%3\n\t"
comment|/* Load old value*/
literal|"or      %1,$0,%4\n\t"
literal|"scd	 %1,%2\n\t"
comment|/* attempt to store */
literal|"beqz	 %1, 1b\n\t"
comment|/* if the store failed, spin */
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
operator|,
literal|"r"
operator|(
name|value
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|result
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATOMIC_ACQ_REL
parameter_list|(
name|NAME
parameter_list|,
name|WIDTH
parameter_list|)
define|\
value|static __inline  void							\ atomic_##NAME##_acq_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	atomic_##NAME##_##WIDTH(p, v);					\ 	mips_sync(); 							\ }									\ 									\ static __inline  void							\ atomic_##NAME##_rel_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	mips_sync();							\ 	atomic_##NAME##_##WIDTH(p, v);					\ }
end_define

begin_comment
comment|/* Variants of simple arithmetic with memory barriers. */
end_comment

begin_expr_stmt
unit|ATOMIC_ACQ_REL
operator|(
name|set
operator|,
literal|8
operator|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|8
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|8
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|8
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|16
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|16
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|16
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|16
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|32
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|32
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|32
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|32
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|64
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|64
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|64
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|64
argument_list|)
endif|#
directive|endif
undef|#
directive|undef
name|ATOMIC_ACQ_REL
comment|/*  * We assume that a = b will do atomic loads and stores.  */
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|WIDTH
parameter_list|)
define|\
value|static __inline  uint##WIDTH##_t			\ atomic_load_acq_##WIDTH(__volatile uint##WIDTH##_t *p)	\ {							\ 	uint##WIDTH##_t v;				\ 							\ 	v = *p;						\ 	mips_sync();					\ 	return (v);					\ }							\ 							\ static __inline  void					\ atomic_store_rel_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {							\ 	mips_sync();					\ 	*p = v;						\ }
name|ATOMIC_STORE_LOAD
argument_list|(
literal|32
argument_list|)
name|ATOMIC_STORE_LOAD
argument_list|(
literal|64
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_n32
argument_list|)
name|void
name|atomic_store_64
argument_list|(
argument|__volatile uint64_t *
argument_list|,
argument|uint64_t *
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|atomic_load_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
modifier|*
name|v
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|v
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_load_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
modifier|*
name|v
parameter_list|)
block|{
operator|*
name|v
operator|=
operator|*
name|p
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ATOMIC_STORE_LOAD
end_undef

begin_comment
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_cmpset_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tll	%0, %4\n\t"
comment|/* load old value */
literal|"bne %0, %2, 2f\n\t"
comment|/* compare */
literal|"move %0, %3\n\t"
comment|/* value to store */
literal|"sc %0, %1\n\t"
comment|/* attempt to store */
literal|"beqz %0, 1b\n\t"
comment|/* if it failed, spin */
literal|"j 3f\n\t"
literal|"2:\n\t"
literal|"li	%0, 0\n\t"
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|cmpval
operator|)
operator|,
literal|"r"
operator|(
name|newval
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|ret
return|;
end_return

begin_comment
unit|}
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
unit|static
name|__inline
name|uint32_t
name|atomic_cmpset_acq_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|int
name|retval
decl_stmt|;
name|retval
operator|=
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|mips_sync
argument_list|()
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_cmpset_rel_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|mips_sync
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Atomically add the value of v to the integer pointed to by p and return  * the previous value of *p.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_fetchadd_32
parameter_list|(
name|__volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|value
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tll %0, %1\n\t"
comment|/* load old value */
literal|"addu %2, %3, %0\n\t"
comment|/* calculate new value */
literal|"sc %2, %1\n\t"
comment|/* attempt to store */
literal|"beqz %2, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|value
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|value
operator|)
return|;
end_return

begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_comment
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
unit|static
name|__inline
name|uint64_t
name|atomic_cmpset_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	%0, %4\n\t"
comment|/* load old value */
literal|"bne	%0, %2, 2f\n\t"
comment|/* compare */
literal|"move	%0, %3\n\t"
comment|/* value to store */
literal|"scd	%0, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%0, 1b\n\t"
comment|/* if it failed, spin */
literal|"j	3f\n\t"
literal|"2:\n\t"
literal|"li	%0, 0\n\t"
literal|"3:\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|cmpval
operator|)
operator|,
literal|"r"
operator|(
name|newval
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|ret
return|;
end_return

begin_comment
unit|}
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
unit|static
name|__inline
name|uint64_t
name|atomic_cmpset_acq_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|int
name|retval
decl_stmt|;
name|retval
operator|=
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|mips_sync
argument_list|()
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|atomic_cmpset_rel_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|mips_sync
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Atomically add the value of v to the integer pointed to by p and return  * the previous value of *p.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|atomic_fetchadd_64
parameter_list|(
name|__volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
name|uint64_t
name|value
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\n\t"
literal|"lld	%0, %1\n\t"
comment|/* load old value */
literal|"daddu	%2, %3, %0\n\t"
comment|/* calculate new value */
literal|"scd	%2, %1\n\t"
comment|/* attempt to store */
literal|"beqz	%2, 1b\n\t"
comment|/* spin if failed */
operator|:
literal|"=&r"
operator|(
name|value
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|v
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|value
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* Operations on chars. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_char
value|atomic_set_8
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_char
value|atomic_set_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_char
value|atomic_set_rel_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_char
value|atomic_clear_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_char
value|atomic_clear_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_char
value|atomic_clear_rel_8
end_define

begin_define
define|#
directive|define
name|atomic_add_char
value|atomic_add_8
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_char
value|atomic_add_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_char
value|atomic_add_rel_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_char
value|atomic_subtract_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_char
value|atomic_subtract_acq_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_char
value|atomic_subtract_rel_8
end_define

begin_comment
comment|/* Operations on shorts. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_short
value|atomic_set_16
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_short
value|atomic_set_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_short
value|atomic_set_rel_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_short
value|atomic_clear_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_short
value|atomic_clear_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_short
value|atomic_clear_rel_16
end_define

begin_define
define|#
directive|define
name|atomic_add_short
value|atomic_add_16
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_short
value|atomic_add_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_short
value|atomic_add_rel_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_short
value|atomic_subtract_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_short
value|atomic_subtract_acq_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_short
value|atomic_subtract_rel_16
end_define

begin_comment
comment|/* Operations on ints. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_int
value|atomic_set_32
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
name|atomic_set_rel_int
value|atomic_set_rel_32
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
name|atomic_clear_acq_int
value|atomic_clear_acq_32
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
name|atomic_add_int
value|atomic_add_32
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
name|atomic_add_rel_int
value|atomic_add_rel_32
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
name|atomic_subtract_acq_int
value|atomic_subtract_acq_32
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
name|atomic_cmpset_int
value|atomic_cmpset_32
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
name|atomic_cmpset_rel_int
value|atomic_cmpset_rel_32
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
name|atomic_store_rel_int
value|atomic_store_rel_32
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
name|atomic_readandset_int
value|atomic_readandset_32
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_int
value|atomic_fetchadd_32
end_define

begin_comment
comment|/*  * I think the following is right, even for n32.  For n32 the pointers  * are still 32-bits, so we need to operate on them as 32-bit quantities,  * even though they are sign extended in operation.  For longs, there's  * no question because they are always 32-bits.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_comment
comment|/* Operations on longs. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_64
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
name|atomic_set_rel_long
value|atomic_set_rel_64
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
name|atomic_clear_acq_long
value|atomic_clear_acq_64
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
name|atomic_add_long
value|atomic_add_64
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
name|atomic_add_rel_long
value|atomic_add_rel_64
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
name|atomic_subtract_acq_long
value|atomic_subtract_acq_64
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
name|atomic_cmpset_long
value|atomic_cmpset_64
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
name|atomic_cmpset_rel_long
value|atomic_cmpset_rel_64
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
name|atomic_store_rel_long
value|atomic_store_rel_64
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__mips_n64 */
end_comment

begin_comment
comment|/* Operations on longs. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_add_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_add_32((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_subtract_32((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
parameter_list|(
name|p
parameter_list|,
name|cmpval
parameter_list|,
name|newval
parameter_list|)
define|\
value|atomic_cmpset_acq_32((volatile u_int *)(p), \ 	    (u_int)(cmpval), (u_int)(newval))
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
parameter_list|(
name|p
parameter_list|,
name|cmpval
parameter_list|,
name|newval
parameter_list|)
define|\
value|atomic_cmpset_rel_32((volatile u_int *)(p), \ 	    (u_int)(cmpval), (u_int)(newval))
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
value|atomic_load_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_long
value|atomic_store_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_fetchadd_32((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n64 */
end_comment

begin_comment
comment|/* Operations on pointers. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_clear_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
value|atomic_add_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
value|atomic_add_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
value|atomic_subtract_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
value|atomic_subtract_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

