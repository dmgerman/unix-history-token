begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Benno Rice  * Copyright (c) 2001 David E. O'Brien  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts and SMP safe.  */
end_comment

begin_function_decl
name|void
name|atomic_set_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_set_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|atomic_set_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tlwarx %0, 0, %1\n\t"
comment|/* load old value */
literal|"or %0, %0, %2\n\t"
comment|/* calculate new value */
literal|"stwcx. %0, 0, %1\n\t"
comment|/* attempt to store */
literal|"bne- 1\n\t"
comment|/* spin if failed */
literal|"eieio\n"
comment|/* drain to memory */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
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
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tlwarx %0, 0, %1\n\t"
comment|/* load old value */
literal|"andc %0, %0, %2\n\t"
comment|/* calculate new value */
literal|"stwcx. %0, 0, %1\n\t"
comment|/* attempt to store */
literal|"bne- 1\n\t"
comment|/* spin if failed */
literal|"eieio\n"
comment|/* drain to memory */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
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
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tlwarx %0, 0, %1\n\t"
comment|/* load old value */
literal|"add %0, %0, %2\n\t"
comment|/* calculate new value */
literal|"stwcx. %0, 0, %1\n\t"
comment|/* attempt to store */
literal|"bne- 1\n\t"
comment|/* spin if failed */
literal|"eieio\n"
comment|/* Old McDonald had a farm */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
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
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tlwarx %0, 0, %1\n\t"
comment|/* load old value */
literal|"sub %0, %2, %0\n\t"
comment|/* calculate new value */
literal|"stwcx. %0, 0, %1\n\t"
comment|/* attempt to store */
literal|"bne- 1\n\t"
comment|/* spin if failed */
literal|"eieio\n"
comment|/* drain to memory */
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|u_int32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|addr
parameter_list|)
block|{
name|u_int32_t
name|result
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"\teieio\n"
comment|/* memory barrier */
literal|"1:\tlwarx %0, 0, %2\n\t"
comment|/* load old value */
literal|"li %1, 0\n\t"
comment|/* load new value */
literal|"stwcx. %1, 0, %2\n\t"
comment|/* attempt to store */
literal|"bne- 1\n\t"
comment|/* spin if failed */
literal|"eieio\n"
comment|/* drain to memory */
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
operator|:
literal|"r"
operator|(
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

begin_if
unit|}
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * So far I haven't found a way to implement atomic 64-bit ops on the  * 32-bit PowerPC without involving major headaches.  If anyone has  * any ideas, please let me know. =)  * 	- benno@FreeBSD.org  */
end_comment

begin_endif
unit|static __inline void atomic_set_64(volatile u_int64_t *p, u_int64_t v) { 	u_int64_t temp;  	__asm __volatile ( 		: "=&r" (temp), "=r" (*p) 		: "r" (*p), "r" (v) 		: "memory"); }  static __inline void atomic_clear_64(volatile u_int64_t *p, u_int64_t v) { 	u_int64_t temp;  	__asm __volatile ( 		: "=&r" (temp), "=r" (*p) 		: "r" (*p), "r" (v) 		: "memory"); }  static __inline void atomic_add_64(volatile u_int64_t *p, u_int64_t v) { 	u_int64_t temp;  	__asm __volatile ( 		: "=&r" (temp), "=r" (*p) 		: "r" (*p), "r" (v) 		: "memory"); }  static __inline void atomic_subtract_64(volatile u_int64_t *p, u_int64_t v) { 	u_int64_t temp;  	__asm __volatile ( 		: "=&r" (temp), "=r" (*p) 		: "r" (*p), "r" (v) 		: "memory"); }  static __inline u_int64_t atomic_readandclear_64(volatile u_int64_t *addr) { 	u_int64_t result,temp;  	__asm __volatile ( 		: "=&r"(result), "=&r"(temp), "=r" (*addr) 		: "r"(*addr) 		: "memory");  	return result; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
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
name|atomic_clear_char
value|atomic_clear_8
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
name|atomic_subtract_char
value|atomic_subtract_8
end_define

begin_define
define|#
directive|define
name|atomic_set_short
value|atomic_set_16
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
name|atomic_add_short
value|atomic_add_16
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
name|atomic_set_int
value|atomic_set_32
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
name|atomic_add_int
value|atomic_add_32
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
name|atomic_readandclear_int
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_32
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
name|atomic_add_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|atomic_add_32((u_int32_t *)p, (u_int32_t)v)
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_32
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* See above. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_long_long
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_long_long
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_add_long_long
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long_long
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long_long
value|atomic_readandclear_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_ACQ_REL
parameter_list|(
name|NAME
parameter_list|,
name|WIDTH
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|static __inline void							\ atomic_##NAME##_acq_##WIDTH(volatile u_int##WIDTH##_t *p, u_int##WIDTH##_t v) \ {									\ 	powerpc_mb();							\ 	atomic_##NAME##_##WIDTH(p, v);					\ }									\ 									\ static __inline void							\ atomic_##NAME##_rel_##WIDTH(volatile u_int##WIDTH##_t *p, u_int##WIDTH##_t v) \ {									\ 	atomic_##NAME##_##WIDTH(p, v);					\ 	powerpc_mb();							\ }									\ 									\ static __inline void							\ atomic_##NAME##_acq_##TYPE(volatile u_int##WIDTH##_t *p, u_int##WIDTH##_t v) \ {									\ 	powerpc_mb();							\ 	atomic_##NAME##_##WIDTH(p, v);					\ }									\ 									\ static __inline void							\ atomic_##NAME##_rel_##TYPE(volatile u_int##WIDTH##_t *p, u_int##WIDTH##_t v) \ {									\ 	atomic_##NAME##_##WIDTH(p, v);					\ 	powerpc_mb();							\ }
end_define

begin_expr_stmt
unit|ATOMIC_ACQ_REL
operator|(
name|set
operator|,
literal|8
operator|,
name|char
operator|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|8
argument_list|,
argument|char
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|8
argument_list|,
argument|char
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|8
argument_list|,
argument|char
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|16
argument_list|,
argument|short
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|16
argument_list|,
argument|short
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|16
argument_list|,
argument|short
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|16
argument_list|,
argument|short
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|32
argument_list|,
argument|int
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|32
argument_list|,
argument|int
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|32
argument_list|,
argument|int
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|32
argument_list|,
argument|int
argument_list|)
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_acq_32
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_rel_32
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_acq_32
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_rel_32
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_acq_32
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_rel_32
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_acq_32
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_rel_32
undef|#
directive|undef
name|ATOMIC_ACQ_REL
comment|/*  * We assume that a = b will do atomic loads and stores.  */
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|TYPE
parameter_list|,
name|WIDTH
parameter_list|)
define|\
value|static __inline u_##TYPE					\ atomic_load_acq_##WIDTH(volatile u_##TYPE *p)			\ {								\ 	powerpc_mb();						\ 	return (*p);						\ }								\ 								\ static __inline void						\ atomic_store_rel_##WIDTH(volatile u_##TYPE *p, u_##TYPE v)	\ {								\ 	*p = v;							\ 	powerpc_mb();						\ }								\ static __inline u_##TYPE					\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)			\ {								\ 	powerpc_mb();						\ 	return (*p);						\ }								\ 								\ static __inline void						\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)	\ {								\ 	*p = v;							\ 	powerpc_mb();						\ }
name|ATOMIC_STORE_LOAD
argument_list|(
argument|char
argument_list|,
literal|8
argument_list|)
name|ATOMIC_STORE_LOAD
argument_list|(
argument|short
argument_list|,
literal|16
argument_list|)
name|ATOMIC_STORE_LOAD
argument_list|(
argument|int
argument_list|,
literal|32
argument_list|)
define|#
directive|define
name|atomic_load_acq_long
value|atomic_load_acq_32
define|#
directive|define
name|atomic_store_rel_long
value|atomic_store_rel_32
undef|#
directive|undef
name|ATOMIC_STORE_LOAD
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
specifier|static
name|__inline
name|u_int32_t
name|atomic_cmpset_32
argument_list|(
argument|volatile u_int32_t* p
argument_list|,
argument|u_int32_t cmpval
argument_list|,
argument|u_int32_t newval
argument_list|)
block|{
name|u_int32_t
name|ret
block|;
asm|__asm __volatile (
literal|"1:\tlwarx %0, 0, %3\n\t"
comment|/* load old value */
literal|"cmplw 0, %1, %0\n\t"
comment|/* compare */
literal|"bne 2f\n\t"
comment|/* exit if not equal */
literal|"mr %0, %2\n\t"
comment|/* value to store */
literal|"stwcx. %0, 0, %3\n\t"
comment|/* attempt to store */
literal|"bne- 1b\n\t"
comment|/* spin if failed */
literal|"eieio\n"
comment|/* memory barrier */
literal|"sync\n"
literal|"b 3f\n\t"
comment|/* we've succeeded */
literal|"2:\t\n"
literal|"xor %0,%0,%0\t\n"
comment|/* failure, so return 0 */
literal|"3:\t\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|cmpval
operator|)
block|,
literal|"r"
operator|(
name|newval
operator|)
block|,
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|ret
return|;
end_return

begin_if
unit|}
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_endif
unit|static __inline u_int64_t atomic_cmpset_64(volatile u_int64_t* p, u_int64_t cmpval, u_int64_t newval) { 	u_int64_t ret;  	__asm __volatile ( 		: "=&r" (ret), "=r" (*p) 		: "r" (cmpval), "r" (newval), "r" (*p) 		: "memory");  	return ret; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
value|atomic_cmpset_32
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|atomic_cmpset_long_long
value|atomic_cmpset_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_function
unit|static
name|__inline
name|int
name|atomic_cmpset_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|dst
parameter_list|,
name|void
modifier|*
name|exp
parameter_list|,
name|void
modifier|*
name|src
parameter_list|)
block|{
return|return
operator|(
name|atomic_cmpset_32
argument_list|(
operator|(
specifier|volatile
name|u_int32_t
operator|*
operator|)
name|dst
argument_list|,
operator|(
name|u_int32_t
operator|)
name|exp
argument_list|,
operator|(
name|u_int32_t
operator|)
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|atomic_cmpset_acq_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|cmpval
parameter_list|,
name|u_int32_t
name|newval
parameter_list|)
block|{
name|powerpc_mb
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

begin_function
specifier|static
name|__inline
name|u_int32_t
name|atomic_cmpset_rel_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|cmpval
parameter_list|,
name|u_int32_t
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
name|powerpc_mb
argument_list|()
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

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
name|atomic_cmpset_acq_long
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_rel_32
end_define

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_acq_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|dst
parameter_list|,
name|void
modifier|*
name|exp
parameter_list|,
name|void
modifier|*
name|src
parameter_list|)
block|{
return|return
operator|(
name|atomic_cmpset_acq_32
argument_list|(
operator|(
specifier|volatile
name|u_int32_t
operator|*
operator|)
name|dst
argument_list|,
operator|(
name|u_int32_t
operator|)
name|exp
argument_list|,
operator|(
name|u_int32_t
operator|)
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_rel_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|dst
parameter_list|,
name|void
modifier|*
name|exp
parameter_list|,
name|void
modifier|*
name|src
parameter_list|)
block|{
return|return
operator|(
name|atomic_cmpset_rel_32
argument_list|(
operator|(
specifier|volatile
name|u_int32_t
operator|*
operator|)
name|dst
argument_list|,
operator|(
name|u_int32_t
operator|)
name|exp
argument_list|,
operator|(
name|u_int32_t
operator|)
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|atomic_load_acq_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|atomic_load_acq_32
argument_list|(
operator|(
specifier|volatile
name|u_int32_t
operator|*
operator|)
name|p
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_rel_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|p
parameter_list|,
name|void
modifier|*
name|v
parameter_list|)
block|{
name|atomic_store_rel_32
argument_list|(
operator|(
specifier|volatile
name|u_int32_t
operator|*
operator|)
name|p
argument_list|,
operator|(
name|u_int32_t
operator|)
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|ATOMIC_PTR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|static __inline void						\ atomic_##NAME##_ptr(volatile void *p, uintptr_t v)		\ {								\ 	atomic_##NAME##_32((volatile u_int32_t *)p, v);	\ }								\ 								\ static __inline void						\ atomic_##NAME##_acq_ptr(volatile void *p, uintptr_t v)		\ {								\ 	atomic_##NAME##_acq_32((volatile u_int32_t *)p, v);	\ }								\ 								\ static __inline void						\ atomic_##NAME##_rel_ptr(volatile void *p, uintptr_t v)		\ {								\ 	atomic_##NAME##_rel_32((volatile u_int32_t *)p, v);	\ }
end_define

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|set
argument_list|)
end_macro

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|clear
argument_list|)
end_macro

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|add
argument_list|)
end_macro

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|subtract
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|ATOMIC_PTR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

