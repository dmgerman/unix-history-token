begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Marcel Moolenaar  * Copyright (c) 2001 Benno Rice  * Copyright (c) 2001 David E. O'Brien  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|__ATOMIC_BARRIER
define|\
value|__asm __volatile("sync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__ATOMIC_BARRIER
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|mb()
end_define

begin_comment
comment|/*  * atomic_add(p, v)  * { *p += v; }  */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_ADD_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|8-bit atomic_add not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_ADD_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|16-bit atomic_add not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_ADD_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	lwarx	%0, 0, %2\n"				\ 	"	add	%0, %3, %0\n"				\ 	"	stwcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __ATOMIC_ADD_32 */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_ADD_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|64-bit atomic_add not implemented
end_define

begin_define
define|#
directive|define
name|_ATOMIC_ADD
parameter_list|(
name|width
parameter_list|,
name|suffix
parameter_list|,
name|type
parameter_list|)
define|\
value|static __inline void					\     atomic_add_##suffix(volatile type *p, type v) {		\ 	type t;							\ 	__ATOMIC_ADD_##width(p, v, t);				\     }								\ 								\     static __inline void					\     atomic_add_acq_##suffix(volatile type *p, type v) {		\ 	type t;							\ 	__ATOMIC_ADD_##width(p, v, t);				\ 	__ATOMIC_BARRIER;					\     }								\ 								\     static __inline void					\     atomic_add_rel_##suffix(volatile type *p, type v) {		\ 	type t;							\ 	__ATOMIC_BARRIER;					\ 	__ATOMIC_ADD_##width(p, v, t);				\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_ADD */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_ADD(8, 8, uint8_t) _ATOMIC_ADD(8, char, u_char) _ATOMIC_ADD(16, 16, uint16_t) _ATOMIC_ADD(16, short, u_short)
endif|#
directive|endif
end_endif

begin_macro
name|_ATOMIC_ADD
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|_ATOMIC_ADD
argument_list|(
literal|32
argument_list|,
argument|int
argument_list|,
argument|u_int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_ADD
argument_list|(
literal|32
argument_list|,
argument|long
argument_list|,
argument|u_long
argument_list|)
end_macro

begin_macro
name|_ATOMIC_ADD
argument_list|(
literal|32
argument_list|,
argument|ptr
argument_list|,
argument|uintptr_t
argument_list|)
end_macro

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_ADD(64, 64, uint64_t) _ATOMIC_ADD(64, long_long, u_long_long)
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|_ATOMIC_ADD
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_ADD_64
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_ADD_32
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_ADD_16
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_ADD_8
end_undef

begin_comment
comment|/*  * atomic_clear(p, v)  * { *p&= ~v; }  */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_CLEAR_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|8-bit atomic_clear not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_CLEAR_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|16-bit atomic_clear not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_CLEAR_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	lwarx	%0, 0, %2\n"				\ 	"	andc	%0, %0, %3\n"				\ 	"	stwcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __ATOMIC_CLEAR_32 */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_CLEAR_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|64-bit atomic_clear not implemented
end_define

begin_define
define|#
directive|define
name|_ATOMIC_CLEAR
parameter_list|(
name|width
parameter_list|,
name|suffix
parameter_list|,
name|type
parameter_list|)
define|\
value|static __inline void					\     atomic_clear_##suffix(volatile type *p, type v) {		\ 	type t;							\ 	__ATOMIC_CLEAR_##width(p, v, t);			\     }								\ 								\     static __inline void					\     atomic_clear_acq_##suffix(volatile type *p, type v) {	\ 	type t;							\ 	__ATOMIC_CLEAR_##width(p, v, t);			\ 	__ATOMIC_BARRIER;					\     }								\ 								\     static __inline void					\     atomic_clear_rel_##suffix(volatile type *p, type v) {	\ 	type t;							\ 	__ATOMIC_BARRIER;					\ 	__ATOMIC_CLEAR_##width(p, v, t);			\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_CLEAR */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_CLEAR(8, 8, uint8_t) _ATOMIC_CLEAR(8, char, u_char) _ATOMIC_CLEAR(16, 16, uint16_t) _ATOMIC_CLEAR(16, short, u_short)
endif|#
directive|endif
end_endif

begin_macro
name|_ATOMIC_CLEAR
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|_ATOMIC_CLEAR
argument_list|(
literal|32
argument_list|,
argument|int
argument_list|,
argument|u_int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_CLEAR
argument_list|(
literal|32
argument_list|,
argument|long
argument_list|,
argument|u_long
argument_list|)
end_macro

begin_macro
name|_ATOMIC_CLEAR
argument_list|(
literal|32
argument_list|,
argument|ptr
argument_list|,
argument|uintptr_t
argument_list|)
end_macro

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_CLEAR(64, 64, uint64_t) _ATOMIC_CLEAR(64, long_long, u_long_long)
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|_ATOMIC_CLEAR
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_CLEAR_64
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_CLEAR_32
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_CLEAR_16
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_CLEAR_8
end_undef

begin_comment
comment|/*  * atomic_cmpset(p, o, n)  */
end_comment

begin_comment
comment|/* TODO -- see below */
end_comment

begin_comment
comment|/*  * atomic_load_acq(p)  */
end_comment

begin_comment
comment|/* TODO -- see below */
end_comment

begin_comment
comment|/*  * atomic_readandclear(p)  */
end_comment

begin_comment
comment|/* TODO -- see below */
end_comment

begin_comment
comment|/*  * atomic_set(p, v)  * { *p |= v; }  */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_SET_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|8-bit atomic_set not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_SET_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|16-bit atomic_set not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_SET_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	lwarx	%0, 0, %2\n"				\ 	"	or	%0, %3, %0\n"				\ 	"	stwcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __ATOMIC_SET_32 */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_SET_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|64-bit atomic_set not implemented
end_define

begin_define
define|#
directive|define
name|_ATOMIC_SET
parameter_list|(
name|width
parameter_list|,
name|suffix
parameter_list|,
name|type
parameter_list|)
define|\
value|static __inline void					\     atomic_set_##suffix(volatile type *p, type v) {		\ 	type t;							\ 	__ATOMIC_SET_##width(p, v, t);				\     }								\ 								\     static __inline void					\     atomic_set_acq_##suffix(volatile type *p, type v) {		\ 	type t;							\ 	__ATOMIC_SET_##width(p, v, t);				\ 	__ATOMIC_BARRIER;					\     }								\ 								\     static __inline void					\     atomic_set_rel_##suffix(volatile type *p, type v) {		\ 	type t;							\ 	__ATOMIC_BARRIER;					\ 	__ATOMIC_SET_##width(p, v, t);				\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_SET */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_SET(8, 8, uint8_t) _ATOMIC_SET(8, char, u_char) _ATOMIC_SET(16, 16, uint16_t) _ATOMIC_SET(16, short, u_short)
endif|#
directive|endif
end_endif

begin_macro
name|_ATOMIC_SET
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SET
argument_list|(
literal|32
argument_list|,
argument|int
argument_list|,
argument|u_int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SET
argument_list|(
literal|32
argument_list|,
argument|long
argument_list|,
argument|u_long
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SET
argument_list|(
literal|32
argument_list|,
argument|ptr
argument_list|,
argument|uintptr_t
argument_list|)
end_macro

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_SET(64, 64, uint64_t) _ATOMIC_SET(64, long_long, u_long_long)
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|_ATOMIC_SET
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SET_64
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SET_32
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SET_16
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SET_8
end_undef

begin_comment
comment|/*  * atomic_subtract(p, v)  * { *p -= v; }  */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_SUBTRACT_8
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|8-bit atomic_subtract not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_SUBTRACT_16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|16-bit atomic_subtract not implemented
end_define

begin_define
define|#
directive|define
name|__ATOMIC_SUBTRACT_32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	lwarx	%0, 0, %2\n"				\ 	"	subf	%0, %3, %0\n"				\ 	"	stwcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __ATOMIC_SUBTRACT_32 */
end_comment

begin_define
define|#
directive|define
name|__ATOMIC_SUBTRACT_64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|64-bit atomic_subtract not implemented
end_define

begin_define
define|#
directive|define
name|_ATOMIC_SUBTRACT
parameter_list|(
name|width
parameter_list|,
name|suffix
parameter_list|,
name|type
parameter_list|)
define|\
value|static __inline void					\     atomic_subtract_##suffix(volatile type *p, type v) {	\ 	type t;							\ 	__ATOMIC_SUBTRACT_##width(p, v, t);			\     }								\ 								\     static __inline void					\     atomic_subtract_acq_##suffix(volatile type *p, type v) {	\ 	type t;							\ 	__ATOMIC_SUBTRACT_##width(p, v, t);			\ 	__ATOMIC_BARRIER;					\     }								\ 								\     static __inline void					\     atomic_subtract_rel_##suffix(volatile type *p, type v) {	\ 	type t;							\ 	__ATOMIC_BARRIER;					\ 	__ATOMIC_SUBTRACT_##width(p, v, t);			\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_SUBTRACT */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_SUBTRACT(8, 8, uint8_t) _ATOMIC_SUBTRACT(8, char, u_char) _ATOMIC_SUBTRACT(16, 16, uint16_t) _ATOMIC_SUBTRACT(16, short, u_short)
endif|#
directive|endif
end_endif

begin_macro
name|_ATOMIC_SUBTRACT
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SUBTRACT
argument_list|(
literal|32
argument_list|,
argument|int
argument_list|,
argument|u_int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SUBTRACT
argument_list|(
literal|32
argument_list|,
argument|long
argument_list|,
argument|u_long
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SUBTRACT
argument_list|(
literal|32
argument_list|,
argument|ptr
argument_list|,
argument|uintptr_t
argument_list|)
end_macro

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|_ATOMIC_SUBTRACT(64, 64, uint64_t) _ATOMIC_SUBTRACT(64, long_long, u_long_long)
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|_ATOMIC_SUBTRACT
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SUBTRACT_64
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SUBTRACT_32
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SUBTRACT_16
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_SUBTRACT_8
end_undef

begin_comment
comment|/*  * atomic_store_rel(p, v)  */
end_comment

begin_comment
comment|/* TODO -- see below */
end_comment

begin_comment
comment|/*  * Old/original implementations that still need revisiting.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
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
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
asm|__asm __volatile (
literal|"\tsync\n"
comment|/* drain writes */
literal|"1:\tlwarx %0, 0, %3\n\t"
comment|/* load old value */
literal|"li %1, 0\n\t"
comment|/* load new value */
literal|"stwcx. %1, 0, %3\n\t"
comment|/* attempt to store */
literal|"bne- 1b\n\t"
comment|/* spin if failed */
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
literal|"r"
operator|(
name|addr
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|atomic_readandclear_int
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_32
end_define

begin_comment
comment|/*  * We assume that a = b will do atomic loads and stores.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|TYPE
parameter_list|,
name|WIDTH
parameter_list|)
define|\
value|static __inline u_##TYPE					\ atomic_load_acq_##WIDTH(volatile u_##TYPE *p)			\ {								\ 	u_##TYPE v;						\ 								\ 	v = *p;							\ 	__ATOMIC_BARRIER;					\ 	return (v);						\ }								\ 								\ static __inline void						\ atomic_store_rel_##WIDTH(volatile u_##TYPE *p, u_##TYPE v)	\ {								\ 	__ATOMIC_BARRIER;					\ 	*p = v;							\ }								\ 								\ static __inline u_##TYPE					\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)			\ {								\ 	u_##TYPE v;						\ 								\ 	v = *p;							\ 	__ATOMIC_BARRIER;					\ 	return (v);						\ }								\ 								\ static __inline void						\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)	\ {								\ 	__ATOMIC_BARRIER;					\ 	*p = v;							\ }
end_define

begin_expr_stmt
unit|ATOMIC_STORE_LOAD
operator|(
name|char
operator|,
literal|8
operator|)
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
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_32
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_32
undef|#
directive|undef
name|ATOMIC_STORE_LOAD
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
specifier|static
name|__inline
name|uint32_t
name|atomic_cmpset_32
argument_list|(
argument|volatile uint32_t* p
argument_list|,
argument|uint32_t cmpval
argument_list|,
argument|uint32_t newval
argument_list|)
block|{
name|uint32_t
name|ret
block|;
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
asm|__asm __volatile (
literal|"1:\tlwarx %0, 0, %2\n\t"
comment|/* load old value */
literal|"cmplw %3, %0\n\t"
comment|/* compare */
literal|"bne 2f\n\t"
comment|/* exit if not equal */
literal|"stwcx. %4, 0, %2\n\t"
comment|/* attempt to store */
literal|"bne- 1b\n\t"
comment|/* spin if failed */
literal|"li %0, 1\n\t"
comment|/* success - retval = 1 */
literal|"b 3f\n\t"
comment|/* we've succeeded */
literal|"2:\n\t"
literal|"stwcx. %0, 0, %2\n\t"
comment|/* clear reservation (74xx) */
literal|"li %0, 0\n\t"
comment|/* failure - retval = 0 */
literal|"3:\n\t"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
block|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
block|,
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
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"cc"
block|,
literal|"memory"
block|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|u_long
name|atomic_cmpset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
asm|__asm __volatile (
literal|"1:\tlwarx %0, 0, %2\n\t"
comment|/* load old value */
literal|"cmplw %3, %0\n\t"
comment|/* compare */
literal|"bne 2f\n\t"
comment|/* exit if not equal */
literal|"stwcx. %4, 0, %2\n\t"
comment|/* attempt to store */
literal|"bne- 1b\n\t"
comment|/* spin if failed */
literal|"li %0, 1\n\t"
comment|/* success - retval = 1 */
literal|"b 3f\n\t"
comment|/* we've succeeded */
literal|"2:\n\t"
literal|"stwcx. %0, 0, %2\n\t"
comment|/* clear reservation (74xx) */
literal|"li %0, 0\n\t"
comment|/* failure - retval = 0 */
literal|"3:\n\t"
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
name|p
operator|)
operator|,
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
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_cmpset_32((volatile u_int *)(dst), (u_int)(old), (u_int)(new))
end_define

begin_function
unit|static
name|__inline
name|uint32_t
name|atomic_cmpset_acq_32
parameter_list|(
specifier|volatile
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
name|__ATOMIC_BARRIER
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
specifier|volatile
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
name|__ATOMIC_BARRIER
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
name|u_long
name|atomic_cmpset_acq_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
name|int
name|retval
decl_stmt|;
name|retval
operator|=
name|atomic_cmpset_long
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|__ATOMIC_BARRIER
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
name|atomic_cmpset_rel_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
name|__ATOMIC_BARRIER
expr_stmt|;
return|return
operator|(
name|atomic_cmpset_long
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
name|atomic_cmpset_acq_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_cmpset_acq_32((volatile u_int *)(dst), (u_int)(old), (u_int)(new))
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_cmpset_rel_32((volatile u_int *)(dst), (u_int)(old), (u_int)(new))
end_define

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
name|v
parameter_list|)
block|{
name|uint32_t
name|value
decl_stmt|;
do|do
block|{
name|value
operator|=
operator|*
name|p
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|value
argument_list|,
name|value
operator|+
name|v
argument_list|)
condition|)
do|;
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_fetchadd_int
value|atomic_fetchadd_32
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
value|(u_long)atomic_fetchadd_32((volatile u_int *)(p), (u_int)(v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

