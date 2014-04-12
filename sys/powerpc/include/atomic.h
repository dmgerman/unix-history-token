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

begin_comment
comment|/*  * The __ATOMIC_REL/ACQ() macros provide memory barriers only in conjunction  * with the atomic lXarx/stXcx. sequences below. They are not exposed outside  * of this file. See also Appendix B.2 of Book II of the architecture manual.  *  * Note that not all Book-E processors accept the light-weight sync variant.  * In particular, early models of E500 cores are known to wedge. Bank on all  * 64-bit capable CPUs to accept lwsync properly and pressimize 32-bit CPUs  * to use the heavier-weight sync.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__asm __volatile("lwsync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__asm __volatile("lwsync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__asm __volatile("lwsync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|__ATOMIC_REL
parameter_list|()
value|__asm __volatile("lwsync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|__ATOMIC_ACQ
parameter_list|()
value|__asm __volatile("isync" : : : "memory")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__asm __volatile("sync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__asm __volatile("sync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__asm __volatile("sync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|__ATOMIC_REL
parameter_list|()
value|__asm __volatile("sync" : : : "memory")
end_define

begin_define
define|#
directive|define
name|__ATOMIC_ACQ
parameter_list|()
value|__asm __volatile("isync" : : : "memory")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * atomic_add(p, v)  * { *p += v; }  */
end_comment

begin_define
define|#
directive|define
name|__atomic_add_int
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
comment|/* __atomic_add_int */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|__atomic_add_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	ldarx	%0, 0, %2\n"				\ 	"	add	%0, %3, %0\n"				\ 	"	stdcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __atomic_add_long */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__atomic_add_long
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
comment|/* __atomic_add_long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_ATOMIC_ADD
parameter_list|(
name|type
parameter_list|)
define|\
value|static __inline void					\     atomic_add_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__atomic_add_##type(p, v, t);				\     }								\ 								\     static __inline void					\     atomic_add_acq_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__atomic_add_##type(p, v, t);				\ 	__ATOMIC_ACQ();						\     }								\ 								\     static __inline void					\     atomic_add_rel_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__ATOMIC_REL();						\ 	__atomic_add_##type(p, v, t);				\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_ADD */
end_comment

begin_macro
name|_ATOMIC_ADD
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_ADD
argument_list|(
argument|long
argument_list|)
end_macro

begin_define
define|#
directive|define
name|atomic_add_32
value|atomic_add_int
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_32
value|atomic_add_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_32
value|atomic_add_rel_int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|atomic_add_64
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_64
value|atomic_add_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_64
value|atomic_add_rel_long
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_add_ptr
value|atomic_add_int
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
value|atomic_add_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
value|atomic_add_rel_int
end_define

begin_endif
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
name|__atomic_add_long
end_undef

begin_undef
undef|#
directive|undef
name|__atomic_add_int
end_undef

begin_comment
comment|/*  * atomic_clear(p, v)  * { *p&= ~v; }  */
end_comment

begin_define
define|#
directive|define
name|__atomic_clear_int
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
comment|/* __atomic_clear_int */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|__atomic_clear_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	ldarx	%0, 0, %2\n"				\ 	"	andc	%0, %0, %3\n"				\ 	"	stdcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __atomic_clear_long */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__atomic_clear_long
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
comment|/* __atomic_clear_long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_ATOMIC_CLEAR
parameter_list|(
name|type
parameter_list|)
define|\
value|static __inline void					\     atomic_clear_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__atomic_clear_##type(p, v, t);				\     }								\ 								\     static __inline void					\     atomic_clear_acq_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__atomic_clear_##type(p, v, t);				\ 	__ATOMIC_ACQ();						\     }								\ 								\     static __inline void					\     atomic_clear_rel_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__ATOMIC_REL();						\ 	__atomic_clear_##type(p, v, t);				\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_CLEAR */
end_comment

begin_macro
name|_ATOMIC_CLEAR
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_CLEAR
argument_list|(
argument|long
argument_list|)
end_macro

begin_define
define|#
directive|define
name|atomic_clear_32
value|atomic_clear_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_32
value|atomic_clear_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_32
value|atomic_clear_rel_int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|atomic_clear_64
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_64
value|atomic_clear_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_64
value|atomic_clear_rel_long
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_clear_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_int
end_define

begin_endif
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
name|__atomic_clear_long
end_undef

begin_undef
undef|#
directive|undef
name|__atomic_clear_int
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
name|__atomic_set_int
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
comment|/* __atomic_set_int */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|__atomic_set_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	ldarx	%0, 0, %2\n"				\ 	"	or	%0, %3, %0\n"				\ 	"	stdcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __atomic_set_long */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__atomic_set_long
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
comment|/* __atomic_set_long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_ATOMIC_SET
parameter_list|(
name|type
parameter_list|)
define|\
value|static __inline void					\     atomic_set_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__atomic_set_##type(p, v, t);				\     }								\ 								\     static __inline void					\     atomic_set_acq_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__atomic_set_##type(p, v, t);				\ 	__ATOMIC_ACQ();						\     }								\ 								\     static __inline void					\     atomic_set_rel_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;						\ 	__ATOMIC_REL();						\ 	__atomic_set_##type(p, v, t);				\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_SET */
end_comment

begin_macro
name|_ATOMIC_SET
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SET
argument_list|(
argument|long
argument_list|)
end_macro

begin_define
define|#
directive|define
name|atomic_set_32
value|atomic_set_int
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_32
value|atomic_set_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_32
value|atomic_set_rel_int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|atomic_set_64
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_64
value|atomic_set_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_64
value|atomic_set_rel_long
end_define

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_int
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_int
end_define

begin_endif
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
name|__atomic_set_long
end_undef

begin_undef
undef|#
directive|undef
name|__atomic_set_int
end_undef

begin_comment
comment|/*  * atomic_subtract(p, v)  * { *p -= v; }  */
end_comment

begin_define
define|#
directive|define
name|__atomic_subtract_int
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
comment|/* __atomic_subtract_int */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|__atomic_subtract_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|t
parameter_list|)
define|\
value|__asm __volatile(						\ 	"1:	ldarx	%0, 0, %2\n"				\ 	"	subf	%0, %3, %0\n"				\ 	"	stdcx.	%0, 0, %2\n"				\ 	"	bne-	1b\n"					\ 	: "=&r" (t), "=m" (*p)					\ 	: "r" (p), "r" (v), "m" (*p)				\ 	: "cc", "memory")
end_define

begin_comment
unit|\
comment|/* __atomic_subtract_long */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__atomic_subtract_long
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
comment|/* __atomic_subtract_long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_ATOMIC_SUBTRACT
parameter_list|(
name|type
parameter_list|)
define|\
value|static __inline void						\     atomic_subtract_##type(volatile u_##type *p, u_##type v) {		\ 	u_##type t;							\ 	__atomic_subtract_##type(p, v, t);				\     }									\ 									\     static __inline void						\     atomic_subtract_acq_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;							\ 	__atomic_subtract_##type(p, v, t);				\ 	__ATOMIC_ACQ();							\     }									\ 									\     static __inline void						\     atomic_subtract_rel_##type(volatile u_##type *p, u_##type v) {	\ 	u_##type t;							\ 	__ATOMIC_REL();							\ 	__atomic_subtract_##type(p, v, t);				\     }
end_define

begin_comment
unit|\
comment|/* _ATOMIC_SUBTRACT */
end_comment

begin_macro
name|_ATOMIC_SUBTRACT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|_ATOMIC_SUBTRACT
argument_list|(
argument|long
argument_list|)
end_macro

begin_define
define|#
directive|define
name|atomic_subtract_32
value|atomic_subtract_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_32
value|atomic_subtract_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_32
value|atomic_subtract_rel_int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|atomic_subtract_64
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_64
value|atomic_subract_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_64
value|atomic_subtract_rel_long
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_subtract_ptr
value|atomic_subtract_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
value|atomic_subtract_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
value|atomic_subtract_rel_int
end_define

begin_endif
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
name|__atomic_subtract_long
end_undef

begin_undef
undef|#
directive|undef
name|__atomic_subtract_int
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
name|u_int
name|atomic_readandclear_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|addr
parameter_list|)
block|{
name|u_int
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

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_function
unit|static
name|__inline
name|u_long
name|atomic_readandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|addr
parameter_list|)
block|{
name|u_long
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
literal|"1:\tldarx %0, 0, %3\n\t"
comment|/* load old value */
literal|"li %1, 0\n\t"
comment|/* load new value */
literal|"stdcx. %1, 0, %3\n\t"
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

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|atomic_readandclear_32
value|atomic_readandclear_int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|atomic_readandclear_64
value|atomic_readandclear_long
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_long
end_define

begin_else
else|#
directive|else
end_else

begin_function
unit|static
name|__inline
name|u_long
name|atomic_readandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
operator|(
name|u_long
operator|)
name|atomic_readandclear_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|addr
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We assume that a = b will do atomic loads and stores.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|static __inline u_##TYPE					\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)			\ {								\ 	u_##TYPE v;						\ 								\ 	v = *p;							\ 	mb();							\ 	return (v);						\ }								\ 								\ static __inline void						\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)	\ {								\ 	mb();							\ 	*p = v;							\ }
end_define

begin_macro
name|ATOMIC_STORE_LOAD
argument_list|(
argument|int
argument_list|)
end_macro

begin_define
define|#
directive|define
name|atomic_load_acq_32
value|atomic_load_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_32
value|atomic_store_rel_int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_macro
name|ATOMIC_STORE_LOAD
argument_list|(
argument|long
argument_list|)
end_macro

begin_define
define|#
directive|define
name|atomic_load_acq_64
value|atomic_load_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_64
value|atomic_store_rel_long
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

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|u_long
name|atomic_load_acq_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
operator|(
name|u_long
operator|)
name|atomic_load_acq_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|addr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_rel_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|addr
parameter_list|,
name|u_long
name|val
parameter_list|)
block|{
name|atomic_store_rel_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|addr
argument_list|,
operator|(
name|u_int
operator|)
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_int
end_define

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
name|int
name|atomic_cmpset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|cmpval
parameter_list|,
name|u_int
name|newval
parameter_list|)
block|{
name|int
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

begin_function
unit|} static
name|__inline
name|int
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
name|int
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
asm|__asm __volatile (
ifdef|#
directive|ifdef
name|__powerpc64__
literal|"1:\tldarx %0, 0, %2\n\t"
comment|/* load old value */
literal|"cmpld %3, %0\n\t"
comment|/* compare */
literal|"bne 2f\n\t"
comment|/* exit if not equal */
literal|"stdcx. %4, 0, %2\n\t"
comment|/* attempt to store */
else|#
directive|else
literal|"1:\tlwarx %0, 0, %2\n\t"
comment|/* load old value */
literal|"cmplw %3, %0\n\t"
comment|/* compare */
literal|"bne 2f\n\t"
comment|/* exit if not equal */
literal|"stwcx. %4, 0, %2\n\t"
comment|/* attempt to store */
endif|#
directive|endif
literal|"bne- 1b\n\t"
comment|/* spin if failed */
literal|"li %0, 1\n\t"
comment|/* success - retval = 1 */
literal|"b 3f\n\t"
comment|/* we've succeeded */
literal|"2:\n\t"
ifdef|#
directive|ifdef
name|__powerpc64__
literal|"stdcx. %0, 0, %2\n\t"
comment|/* clear reservation (74xx) */
else|#
directive|else
literal|"stwcx. %0, 0, %2\n\t"
comment|/* clear reservation (74xx) */
endif|#
directive|endif
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

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_acq_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|cmpval
parameter_list|,
name|u_int
name|newval
parameter_list|)
block|{
name|int
name|retval
decl_stmt|;
name|retval
operator|=
name|atomic_cmpset_int
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|__ATOMIC_ACQ
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
name|int
name|atomic_cmpset_rel_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|cmpval
parameter_list|,
name|u_int
name|newval
parameter_list|)
block|{
name|__ATOMIC_REL
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_cmpset_int
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
name|int
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
name|u_long
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
name|__ATOMIC_ACQ
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
name|int
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
name|__ATOMIC_REL
argument_list|()
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
name|atomic_cmpset_32
value|atomic_cmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_32
value|atomic_cmpset_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_32
value|atomic_cmpset_rel_int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|atomic_cmpset_64
value|atomic_cmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_64
value|atomic_cmpset_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_64
value|atomic_cmpset_rel_long
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|u_int
name|atomic_fetchadd_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
name|u_int
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
name|atomic_cmpset_int
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

begin_function
specifier|static
name|__inline
name|u_long
name|atomic_fetchadd_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|v
parameter_list|)
block|{
name|u_long
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
name|atomic_cmpset_long
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

begin_function
specifier|static
name|__inline
name|u_int
name|atomic_swap_32
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
name|u_int
name|prev
decl_stmt|;
asm|__asm __volatile(
literal|"1:	lwarx	%0,0,%2\n"
literal|"	stwcx.	%3,0,%2\n"
literal|"	bne-	1b\n"
operator|:
literal|"=&r"
operator|(
name|prev
operator|)
operator|,
literal|"+m"
operator|(
operator|*
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
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
name|v
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|prev
operator|)
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_function
unit|static
name|__inline
name|u_long
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|v
parameter_list|)
block|{
name|u_long
name|prev
decl_stmt|;
asm|__asm __volatile(
literal|"1:	ldarx	%0,0,%2\n"
literal|"	stdcx.	%3,0,%2\n"
literal|"	bne-	1b\n"
operator|:
literal|"=&r"
operator|(
name|prev
operator|)
operator|,
literal|"+m"
operator|(
operator|*
operator|(
specifier|volatile
name|u_long
operator|*
operator|)
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
name|v
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|prev
operator|)
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
name|atomic_fetchadd_32
value|atomic_fetchadd_int
end_define

begin_define
define|#
directive|define
name|atomic_swap_int
value|atomic_swap_32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|atomic_fetchadd_64
value|atomic_fetchadd_long
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
name|atomic_swap_ptr
value|atomic_swap_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__ATOMIC_REL
end_undef

begin_undef
undef|#
directive|undef
name|__ATOMIC_ACQ
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

