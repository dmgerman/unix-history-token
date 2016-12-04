begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2016 Samy Al Bahra.  * Copyright 2016 Olivier Houchard.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_ARM_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_H
end_ifndef

begin_error
error|#
directive|error
error|Do not include this file directly, use ck_pr.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_include
include|#
directive|include
file|<ck_md.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_comment
comment|/*  * armv4/v5 CPUs lack any instruction that would let us implement an atomic CAS  * so we have to give atomicity by disabling interrupts. This only works in  * the kernel, obviously.  */
end_comment

begin_define
define|#
directive|define
name|__with_interrupts_disabled
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {						\ 		u_int cpsr_save, tmp;			\ 							\ 		__asm __volatile(			\ 			"mrs  %0, cpsr;"		\ 			"orr  %1, %0, %2;"		\ 			"msr  cpsr_fsxc, %1;"		\ 			: "=r" (cpsr_save), "=r" (tmp)	\ 			: "I" (PSR_I | PSR_F)		\ 		        : "cc" );		\ 		(expr);				\ 		 __asm __volatile(		\ 			"msr  cpsr_fsxc, %0"	\ 			:
comment|/* no output */
value|\ 			: "r" (cpsr_save)	\ 			: "cc" );		\ 	} while(0)
end_define

begin_comment
comment|/*  * The following represent supported atomic operations.  * These operations may be emulated.  */
end_comment

begin_include
include|#
directive|include
file|"ck_f_pr.h"
end_include

begin_comment
comment|/*  * Minimum interface requirement met.  */
end_comment

begin_define
define|#
directive|define
name|CK_F_PR
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_stall
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("" ::: "memory");
return|return;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_FENCE
parameter_list|(
name|T
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static void			\ 	ck_pr_fence_strict_##T(void)			\ 	{						\ 		I;					\ 	}
end_define

begin_comment
comment|/*   * ARM CPUs prior to armv6 didn't reorder instructions, and we don't  * support any SMP system, so a compiler barrier should be enough for fences  */
end_comment

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_store
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_load
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_atomic
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_atomic
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_load
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_store
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|memory
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acquire
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|release
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acqrel
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|lock
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|unlock
argument_list|,
argument|ck_pr_stall()
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FENCE
end_undef

begin_define
define|#
directive|define
name|CK_PR_LOAD
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static T					\ 	ck_pr_md_load_##S(const M *target)			\ 	{							\ 		long r = 0;					\ 		__asm__ __volatile__(I " %0, [%1];"		\ 					: "=r" (r)		\ 					: "r"  (target)		\ 					: "memory");		\ 		return ((T)r);					\ 	}
end_define

begin_macro
name|CK_PR_LOAD
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|uint32_t
argument_list|,
literal|"ldr"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_LOAD_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_LOAD(S, T, T, T, I)
end_define

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"ldr"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"ldrh"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"ldrb"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"ldr"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"ldr"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"ldrh"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"ldrb"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_LOAD_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_LOAD
end_undef

begin_define
define|#
directive|define
name|CK_PR_STORE
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static void				\ 	ck_pr_md_store_##S(M *target, T v)			\ 	{							\ 		__asm__ __volatile__(I " %1, [%0]"		\ 					:			\ 					: "r" (target),		\ 					  "r" (v)		\ 					: "memory");		\ 		return;						\ 	}
end_define

begin_macro
name|CK_PR_STORE
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|const void *
argument_list|,
argument|uint32_t
argument_list|,
literal|"str"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_STORE_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_STORE(S, T, T, T, I)
end_define

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"str"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"strh"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"strb"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"str"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"str"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"strh"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"strb"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_STORE_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_STORE
end_undef

begin_define
define|#
directive|define
name|CK_PR_CAS
parameter_list|(
name|N
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ ck_pr_cas_##N##_value(M *target, T compare, T set, M *value)	\ {								\ 	bool ret;						\ 	__with_interrupts_disabled(				\ 	    {							\ 	        *(T *)value = *(T *)target;			\ 	        if (*(T *)target == compare) {			\ 	    		*(T *)target = set;			\ 	    		ret = true;				\ 		} else						\ 	    		ret = false;				\ 	    }							\ 	    );							\ 	return ret;						\ }								\ CK_CC_INLINE static bool					\ ck_pr_cas_##N(M *target, T compare, T set)			\ {								\ 	bool ret;						\ 	__with_interrupts_disabled(				\ 	    {							\ 	        if (*(T *)target == compare) {			\ 	    		*(T *)target = set;			\ 	    		ret = true;				\ 		} else						\ 	    		ret = false;				\ 	    }							\ 	    );							\ 	return ret;						\ }
end_define

begin_macro
name|CK_PR_CAS
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_CAS_S
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|)
value|CK_PR_CAS(N, T, T)
end_define

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_CAS_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_CAS
end_undef

begin_define
define|#
directive|define
name|CK_PR_FAS
parameter_list|(
name|N
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_CC_INLINE static T					\ 	ck_pr_fas_##N(M *target, T v)				\ 	{							\ 		T previous = 0;					\ 		__with_interrupts_disabled(			\ 		    {						\ 		    previous = *(T *)target;			\ 		    *(T *)target = v;				\ 		    }						\ 		    );						\ 		return (previous);				\ 	}
end_define

begin_macro
name|CK_PR_FAS
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|uint32_t
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|unsigned int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|uint16_t
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|uint8_t
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
argument|short
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FAS
end_undef

begin_define
define|#
directive|define
name|CK_PR_UNARY
parameter_list|(
name|O
parameter_list|,
name|N
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_CC_INLINE static void				\ 	ck_pr_##O##_##N(M *target)				\ 	{							\ 		__with_interrupts_disabled(			\ 		    {						\ 		    I;						\ 		    }						\ 		    );						\ 		return;						\ 	}
end_define

begin_macro
name|CK_PR_UNARY
argument_list|(
argument|inc
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|(*(int *)target)++
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY
argument_list|(
argument|dec
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|(*(int *)target)--
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY
argument_list|(
argument|not
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|*(int *)target = !(*(int*)target)
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY
argument_list|(
argument|neg
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|*(int *)target = -(*(int *)target)
argument_list|,
literal|""
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_UNARY_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_PR_UNARY(inc, S, T, T, *target++, W)		\ 	CK_PR_UNARY(dec, S, T, T, *target--, W)		\ 	CK_PR_UNARY(not, S, T, T, *target = !*target, W)		\ 	CK_PR_UNARY(neg, S, T, T, *target = -*target, W)		\  CK_PR_UNARY_S(32, uint32_t, "")
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY
end_undef

begin_define
define|#
directive|define
name|CK_PR_BINARY
parameter_list|(
name|O
parameter_list|,
name|N
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_CC_INLINE static void				\ 	ck_pr_##O##_##N(M *target, T delta)			\ 	{							\ 		__with_interrupts_disabled(			\ 		    {						\ 		    I;						\ 		    }						\ 		    );						\ 		return;						\ 	}
end_define

begin_macro
name|CK_PR_BINARY
argument_list|(
argument|and
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|*((uintptr_t *)target)&= delta
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY
argument_list|(
argument|add
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|*((uintptr_t *)target) += delta
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY
argument_list|(
argument|or
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|*((uintptr_t *)target) |= delta
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY
argument_list|(
argument|sub
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|*((uintptr_t *)target) -= delta
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY
argument_list|(
argument|xor
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|*((uintptr_t *)target) ^= delta
argument_list|,
literal|""
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_BINARY_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_PR_BINARY(and, S, T, T, *target&= delta, W)	\ 	CK_PR_BINARY(add, S, T, T, *target += delta, W)	\ 	CK_PR_BINARY(or, S, T, T, *target |= delta, W)	\ 	CK_PR_BINARY(sub, S, T, T, *target -= delta, W)	\ 	CK_PR_BINARY(xor, S, T, T, *target ^= delta, W)
end_define

begin_macro
name|CK_PR_BINARY_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_BINARY_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_BINARY
end_undef

begin_function
name|CK_CC_INLINE
specifier|static
name|void
modifier|*
name|ck_pr_faa_ptr
parameter_list|(
name|void
modifier|*
name|target
parameter_list|,
name|uintptr_t
name|delta
parameter_list|)
block|{
name|uintptr_t
name|previous
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
argument|{ 	previous = *(uintptr_t *)target; 	*(uintptr_t *)target += delta; 	}
argument_list|)
empty_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
operator|(
name|previous
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_FAA
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_CC_INLINE static T						\ 	ck_pr_faa_##S(T *target, T delta)				\ 	{								\ 		T previous = 0;						\ 		__with_interrupts_disabled(				\ 		    {							\ 		    previous = *target;					\ 		    *target += delta;					\ 		    }							\ 		    );							\ 		return (previous);					\ 	}
end_define

begin_macro
name|CK_PR_FAA
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FAA
end_undef

begin_undef
undef|#
directive|undef
name|__with_interrupts_disabled
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_ARM_H */
end_comment

end_unit

