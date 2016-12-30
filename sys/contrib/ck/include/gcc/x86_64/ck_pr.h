begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_X86_64_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_X86_64_H
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
file|<ck_stdint.h>
end_include

begin_comment
comment|/*  * The following represent supported atomic operations.  * These operations may be emulated.  */
end_comment

begin_include
include|#
directive|include
file|"ck_f_pr.h"
end_include

begin_comment
comment|/*  * Support for TSX extensions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_MD_RTM_ENABLE
end_ifdef

begin_include
include|#
directive|include
file|"ck_pr_rtm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Minimum requirements for the CK_PR interface are met. */
end_comment

begin_define
define|#
directive|define
name|CK_F_PR
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CK_MD_UMP
end_ifdef

begin_define
define|#
directive|define
name|CK_PR_LOCK_PREFIX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CK_PR_LOCK_PREFIX
value|"lock "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Prevent speculative execution in busy-wait loops (P4<=)  * or "predefined delay".  */
end_comment

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
asm|("pause" ::: "memory");
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
value|CK_CC_INLINE static void			\ 	ck_pr_fence_strict_##T(void)			\ 	{						\ 		__asm__ __volatile__(I ::: "memory");	\ 	}
end_define

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic
argument_list|,
literal|"sfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_store
argument_list|,
literal|"sfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_load
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_atomic
argument_list|,
literal|"sfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_atomic
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load
argument_list|,
literal|"lfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_store
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store
argument_list|,
literal|"sfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_load
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|memory
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|release
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acquire
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acqrel
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|lock
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|unlock
argument_list|,
literal|"mfence"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FENCE
end_undef

begin_comment
comment|/*  * Read for ownership. Older compilers will generate the 32-bit  * 3DNow! variant which is binary compatible with x86-64 variant  * of prefetchw.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_RFO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_RFO
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_rfo
parameter_list|(
specifier|const
name|void
modifier|*
name|m
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("prefetchw (%0)" 	    : 	    : "r" (m) 	    : "memory");
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_RFO */
end_comment

begin_comment
comment|/*  * Atomic fetch-and-store operations.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_FAS
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
value|CK_CC_INLINE static T					\ 	ck_pr_fas_##S(M *target, T v)				\ 	{							\ 		__asm__ __volatile__(I " %0, %1"		\ 					: "+m" (*(C *)target),	\ 					  "+q" (v)		\ 					:			\ 					: "memory");		\ 		return v;					\ 	}
end_define

begin_macro
name|CK_PR_FAS
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|char
argument_list|,
literal|"xchgq"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_FAS_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_FAS(S, T, T, T, I)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_FAS_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"xchgq"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|CK_PR_FAS_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"xchgb"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"xchgl"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"xchgl"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"xchgq"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"xchgl"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"xchgw"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"xchgb"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FAS_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_FAS
end_undef

begin_comment
comment|/*  * Atomic load-from-memory operations.  */
end_comment

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
value|CK_CC_INLINE static T					\ 	ck_pr_md_load_##S(const M *target)			\ 	{							\ 		T r;						\ 		__asm__ __volatile__(I " %1, %0"		\ 		    : "=q" (r)					\ 		    : "m"  (*(const C *)target)			\ 		    : "memory");				\ 		return (r);					\ 	}
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
argument|char
argument_list|,
literal|"movq"
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
argument|char
argument_list|,
argument|char
argument_list|,
literal|"movb"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"movl"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"movl"
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"movq"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"movq"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"movl"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"movw"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"movb"
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

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_load_64_2
parameter_list|(
specifier|const
name|uint64_t
name|target
index|[
literal|2
index|]
parameter_list|,
name|uint64_t
name|v
index|[
literal|2
index|]
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("movq %%rdx, %%rcx;" 			     "movq %%rax, %%rbx;" 			     CK_PR_LOCK_PREFIX "cmpxchg16b %2;" 				: "=a" (v[0]), 				  "=d" (v[1]) 				: "m" (*(const uint64_t *)target) 				: "rbx", "rcx", "memory", "cc");
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_load_ptr_2
parameter_list|(
specifier|const
name|void
modifier|*
name|t
parameter_list|,
name|void
modifier|*
name|v
parameter_list|)
block|{
name|ck_pr_load_64_2
argument_list|(
name|CK_CPP_CAST
argument_list|(
specifier|const
name|uint64_t
operator|*
argument_list|,
name|t
argument_list|)
argument_list|,
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|v
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_LOAD_2
parameter_list|(
name|S
parameter_list|,
name|W
parameter_list|,
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static void						\ 	ck_pr_md_load_##S##_##W(const T t[2], T v[2])				\ 	{									\ 		ck_pr_load_64_2((const uint64_t *)(const void *)t,		\ 				(uint64_t *)(void *)v);				\ 		return;								\ 	}
end_define

begin_macro
name|CK_PR_LOAD_2
argument_list|(
argument|char
argument_list|,
literal|16
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_2
argument_list|(
argument|int
argument_list|,
literal|4
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_2
argument_list|(
argument|uint
argument_list|,
literal|4
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_2
argument_list|(
literal|32
argument_list|,
literal|4
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_2
argument_list|(
literal|16
argument_list|,
literal|8
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_2
argument_list|(
literal|8
argument_list|,
literal|16
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_LOAD_2
end_undef

begin_comment
comment|/*  * Atomic store-to-memory operations.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_STORE_IMM
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
parameter_list|,
name|K
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_md_store_##S(M *target, T v)				\ 	{								\ 		__asm__ __volatile__(I " %1, %0"			\ 					: "=m" (*(C *)target)		\ 					: K "q" (v)			\ 					: "memory");			\ 		return;							\ 	}
end_define

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
value|CK_CC_INLINE static void				\ 	ck_pr_md_store_##S(M *target, T v)			\ 	{							\ 		__asm__ __volatile__(I " %1, %0"		\ 					: "=m" (*(C *)target)	\ 					: "q" (v)		\ 					: "memory");		\ 		return;						\ 	}
end_define

begin_macro
name|CK_PR_STORE_IMM
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|const void *
argument_list|,
argument|char
argument_list|,
literal|"movq"
argument_list|,
argument|CK_CC_IMM_U32
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_STORE
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|,
literal|"movq"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

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
parameter_list|,
name|K
parameter_list|)
value|CK_PR_STORE_IMM(S, T, T, T, I, K)
end_define

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"movb"
argument_list|,
argument|CK_CC_IMM_S32
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"movl"
argument_list|,
argument|CK_CC_IMM_S32
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"movl"
argument_list|,
argument|CK_CC_IMM_U32
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"movq"
argument_list|,
argument|CK_CC_IMM_U32
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"movl"
argument_list|,
argument|CK_CC_IMM_U32
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"movw"
argument_list|,
argument|CK_CC_IMM_U32
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"movb"
argument_list|,
argument|CK_CC_IMM_U32
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
name|CK_PR_STORE_IMM
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_STORE
end_undef

begin_comment
comment|/*  * Atomic fetch-and-add operations.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_FAA
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
value|CK_CC_INLINE static T						\ 	ck_pr_faa_##S(M *target, T d)					\ 	{								\ 		__asm__ __volatile__(CK_PR_LOCK_PREFIX I " %1, %0"	\ 					: "+m" (*(C *)target),		\ 					  "+q" (d)			\ 					:				\ 					: "memory", "cc");		\ 		return (d);						\ 	}
end_define

begin_macro
name|CK_PR_FAA
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|char
argument_list|,
literal|"xaddq"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_FAA_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_FAA(S, T, T, T, I)
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"xaddb"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"xaddl"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"xaddl"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"xaddq"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"xaddl"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"xaddw"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"xaddb"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FAA_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_FAA
end_undef

begin_comment
comment|/*  * Atomic store-only unary operations.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_UNARY
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_PR_UNARY_R(K, S, T, C, I)				\ 	CK_PR_UNARY_V(K, S, T, C, I)
end_define

begin_define
define|#
directive|define
name|CK_PR_UNARY_R
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static void				\ 	ck_pr_##K##_##S(T *target)				\ 	{							\ 		__asm__ __volatile__(CK_PR_LOCK_PREFIX I " %0"	\ 					: "+m" (*(C *)target)	\ 					:			\ 					: "memory", "cc");	\ 		return;						\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_UNARY_V
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_##K##_##S##_zero(T *target, bool *r)			\ 	{								\ 		__asm__ __volatile__(CK_PR_LOCK_PREFIX I " %0; setz %1"	\ 					: "+m" (*(C *)target),		\ 					  "=m" (*r)			\ 					:				\ 					: "memory", "cc");		\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_UNARY_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_UNARY(K, S, T, T, I)
end_define

begin_define
define|#
directive|define
name|CK_PR_GENERATE
parameter_list|(
name|K
parameter_list|)
define|\
value|CK_PR_UNARY(K, ptr, void, char, #K "q") 	\ 	CK_PR_UNARY_S(K, char, char, #K "b")		\ 	CK_PR_UNARY_S(K, int, int, #K "l")		\ 	CK_PR_UNARY_S(K, uint, unsigned int, #K "l")	\ 	CK_PR_UNARY_S(K, 64, uint64_t, #K "q")		\ 	CK_PR_UNARY_S(K, 32, uint32_t, #K "l")		\ 	CK_PR_UNARY_S(K, 16, uint16_t, #K "w")		\ 	CK_PR_UNARY_S(K, 8, uint8_t, #K "b")
end_define

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|inc
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|dec
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|neg
argument_list|)
end_macro

begin_comment
comment|/* not does not affect condition flags. */
end_comment

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_V
end_undef

begin_define
define|#
directive|define
name|CK_PR_UNARY_V
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
end_define

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|not
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_GENERATE
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_V
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_R
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY
end_undef

begin_comment
comment|/*  * Atomic store-only binary operations.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_BINARY
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|,
name|O
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_##K##_##S(M *target, T d)					\ 	{								\ 		__asm__ __volatile__(CK_PR_LOCK_PREFIX I " %1, %0"	\ 					: "+m" (*(C *)target)		\ 					: O "q" (d)			\ 					: "memory", "cc");		\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_BINARY_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|,
name|O
parameter_list|)
value|CK_PR_BINARY(K, S, T, T, T, I, O)
end_define

begin_define
define|#
directive|define
name|CK_PR_GENERATE
parameter_list|(
name|K
parameter_list|)
define|\
value|CK_PR_BINARY(K, ptr, void, uintptr_t, char, #K "q", CK_CC_IMM_U32)	\ 	CK_PR_BINARY_S(K, char, char, #K "b", CK_CC_IMM_S32)			\ 	CK_PR_BINARY_S(K, int, int, #K "l", CK_CC_IMM_S32)			\ 	CK_PR_BINARY_S(K, uint, unsigned int, #K "l", CK_CC_IMM_U32)		\ 	CK_PR_BINARY_S(K, 64, uint64_t, #K "q", CK_CC_IMM_U32)			\ 	CK_PR_BINARY_S(K, 32, uint32_t, #K "l", CK_CC_IMM_U32)			\ 	CK_PR_BINARY_S(K, 16, uint16_t, #K "w", CK_CC_IMM_U32)			\ 	CK_PR_BINARY_S(K, 8, uint8_t, #K "b", CK_CC_IMM_U32)
end_define

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|add
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|sub
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|and
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|or
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|xor
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_GENERATE
end_undef

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

begin_comment
comment|/*  * Atomic compare and swap.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_CAS
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
value|CK_CC_INLINE static bool						\ 	ck_pr_cas_##S(M *target, T compare, T set)				\ 	{									\ 		bool z;								\ 		__asm__ __volatile__(CK_PR_LOCK_PREFIX I " %2, %0; setz %1"	\ 					: "+m"  (*(C *)target),			\ 					  "=a"  (z)				\ 					: "q"   (set),				\ 					  "a"   (compare)			\ 					: "memory", "cc");			\ 		return z;							\ 	}
end_define

begin_macro
name|CK_PR_CAS
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|char
argument_list|,
literal|"cmpxchgq"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_CAS_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_CAS(S, T, T, T, I)
end_define

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"cmpxchgb"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"cmpxchgl"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"cmpxchgl"
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"cmpxchgq"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"cmpxchgq"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"cmpxchgl"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"cmpxchgw"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"cmpxchgb"
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

begin_comment
comment|/*  * Compare and swap, set *v to old value of target.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_CAS_O
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
parameter_list|,
name|R
parameter_list|)
define|\
value|CK_CC_INLINE static bool						\ 	ck_pr_cas_##S##_value(M *target, T compare, T set, M *v)		\ 	{									\ 		bool z;								\ 		__asm__ __volatile__(CK_PR_LOCK_PREFIX "cmpxchg" I " %3, %0;"	\ 				     "mov %% " R ", %2;"			\ 				     "setz %1;"					\ 					: "+m"  (*(C *)target),			\ 					  "=a"  (z),				\ 					  "=m"  (*(C *)v)			\ 					: "q"   (set),				\ 					  "a"   (compare)			\ 					: "memory", "cc");			\ 		return z;							\ 	}
end_define

begin_macro
name|CK_PR_CAS_O
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
argument|char
argument_list|,
literal|"q"
argument_list|,
literal|"rax"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_CAS_O_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|,
name|R
parameter_list|)
define|\
value|CK_PR_CAS_O(S, T, T, T, I, R)
end_define

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"b"
argument_list|,
literal|"al"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"l"
argument_list|,
literal|"eax"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"l"
argument_list|,
literal|"eax"
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"q"
argument_list|,
literal|"rax"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"q"
argument_list|,
literal|"rax"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"l"
argument_list|,
literal|"eax"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"w"
argument_list|,
literal|"ax"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"b"
argument_list|,
literal|"al"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_CAS_O_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_CAS_O
end_undef

begin_comment
comment|/*  * Contrary to C-interface, alignment requirements are that of uint64_t[2].  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_64_2
parameter_list|(
name|uint64_t
name|target
index|[
literal|2
index|]
parameter_list|,
name|uint64_t
name|compare
index|[
literal|2
index|]
parameter_list|,
name|uint64_t
name|set
index|[
literal|2
index|]
parameter_list|)
block|{
name|bool
name|z
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("movq 0(%4), %%rax;" 			     "movq 8(%4), %%rdx;" 			     CK_PR_LOCK_PREFIX "cmpxchg16b %0; setz %1" 				: "+m" (*target), 				  "=q" (z) 				: "b"  (set[0]), 				  "c"  (set[1]), 				  "q"  (compare) 				: "memory", "cc", "%rax", "%rdx");
return|return
name|z
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_ptr_2
parameter_list|(
name|void
modifier|*
name|t
parameter_list|,
name|void
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|s
parameter_list|)
block|{
return|return
name|ck_pr_cas_64_2
argument_list|(
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|t
argument_list|)
argument_list|,
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|c
argument_list|)
argument_list|,
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|s
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_64_2_value
parameter_list|(
name|uint64_t
name|target
index|[
literal|2
index|]
parameter_list|,
name|uint64_t
name|compare
index|[
literal|2
index|]
parameter_list|,
name|uint64_t
name|set
index|[
literal|2
index|]
parameter_list|,
name|uint64_t
name|v
index|[
literal|2
index|]
parameter_list|)
block|{
name|bool
name|z
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(CK_PR_LOCK_PREFIX "cmpxchg16b %0;" 			     "setz %3" 				: "+m" (*target), 				  "=a" (v[0]), 				  "=d" (v[1]), 				  "=q" (z) 				: "a" (compare[0]), 				  "d" (compare[1]), 				  "b" (set[0]), 				  "c" (set[1]) 				: "memory", "cc");
return|return
name|z
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_ptr_2_value
parameter_list|(
name|void
modifier|*
name|t
parameter_list|,
name|void
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|v
parameter_list|)
block|{
return|return
name|ck_pr_cas_64_2_value
argument_list|(
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|t
argument_list|)
argument_list|,
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|c
argument_list|)
argument_list|,
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|s
argument_list|)
argument_list|,
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|v
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_CAS_V
parameter_list|(
name|S
parameter_list|,
name|W
parameter_list|,
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ ck_pr_cas_##S##_##W(T t[W], T c[W], T s[W])			\ {								\ 	return ck_pr_cas_64_2((uint64_t *)(void *)t,		\ 			      (uint64_t *)(void *)c,		\ 			      (uint64_t *)(void *)s);		\ }								\ CK_CC_INLINE static bool					\ ck_pr_cas_##S##_##W##_value(T *t, T c[W], T s[W], T *v)		\ {								\ 	return ck_pr_cas_64_2_value((uint64_t *)(void *)t,	\ 				    (uint64_t *)(void *)c,	\ 				    (uint64_t *)(void *)s,	\ 				    (uint64_t *)(void *)v);	\ }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_CAS_V
argument_list|(
argument|double
argument_list|,
literal|2
argument_list|,
argument|double
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|CK_PR_CAS_V
argument_list|(
argument|char
argument_list|,
literal|16
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_V
argument_list|(
argument|int
argument_list|,
literal|4
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_V
argument_list|(
argument|uint
argument_list|,
literal|4
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_V
argument_list|(
literal|32
argument_list|,
literal|4
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_V
argument_list|(
literal|16
argument_list|,
literal|8
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_V
argument_list|(
literal|8
argument_list|,
literal|16
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_CAS_V
end_undef

begin_comment
comment|/*  * Atomic bit test operations.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_BT
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ 	ck_pr_##K##_##S(T *target, unsigned int b)			\ 	{								\ 		bool c;							\ 		__asm__ __volatile__(CK_PR_LOCK_PREFIX I "; setc %1"	\ 					: "+m" (*(C *)target),		\ 					  "=q" (c)			\ 					: "q"  ((P)b)			\ 					: "memory", "cc");		\ 		return c;						\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_BT_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_BT(K, S, T, T, T, I)
end_define

begin_define
define|#
directive|define
name|CK_PR_GENERATE
parameter_list|(
name|K
parameter_list|)
define|\
value|CK_PR_BT(K, ptr, void, uint64_t, char, #K "q %2, %0")	\ 	CK_PR_BT_S(K, uint, unsigned int, #K "l %2, %0")	\ 	CK_PR_BT_S(K, int, int, #K "l %2, %0")			\ 	CK_PR_BT_S(K, 64, uint64_t, #K "q %2, %0")		\ 	CK_PR_BT_S(K, 32, uint32_t, #K "l %2, %0")		\ 	CK_PR_BT_S(K, 16, uint16_t, #K "w %w2, %0")
end_define

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|btc
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|bts
argument_list|)
end_macro

begin_macro
name|CK_PR_GENERATE
argument_list|(
argument|btr
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_GENERATE
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_BT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_X86_64_H */
end_comment

end_unit

