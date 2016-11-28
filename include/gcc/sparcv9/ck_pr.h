begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009, 2010 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_SPARCV9_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_SPARCV9_H
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

begin_comment
comment|/*  * Order loads at the least.  */
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
asm|("membar #LoadLoad" ::: "memory");
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
value|CK_CC_INLINE static void			\ 	ck_pr_fence_strict_##T(void)			\ 	{						\ 		__asm__ __volatile__(I ::: "memory");   \ 	}
end_define

begin_comment
comment|/*  * Atomic operations are treated as both load and store  * operations on SPARCv9.  */
end_comment

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic
argument_list|,
literal|"membar #StoreStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_store
argument_list|,
literal|"membar #StoreStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_load
argument_list|,
literal|"membar #StoreLoad"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_atomic
argument_list|,
literal|"membar #StoreStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_atomic
argument_list|,
literal|"membar #LoadStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store
argument_list|,
literal|"membar #StoreStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_load
argument_list|,
literal|"membar #StoreLoad"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load
argument_list|,
literal|"membar #LoadLoad"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_store
argument_list|,
literal|"membar #LoadStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|memory
argument_list|,
literal|"membar #LoadLoad | #LoadStore | #StoreStore | #StoreLoad"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acquire
argument_list|,
literal|"membar #LoadLoad | #LoadStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|release
argument_list|,
literal|"membar #LoadStore | #StoreStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acqrel
argument_list|,
literal|"membar #LoadLoad | #LoadStore | #StoreStore"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|lock
argument_list|,
literal|"membar #LoadLoad | #LoadStore | #StoreStore | #StoreLoad"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|unlock
argument_list|,
literal|"membar #LoadStore | #StoreStore"
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
value|CK_CC_INLINE static T					\ 	ck_pr_md_load_##S(const M *target)			\ 	{							\ 		T r;						\ 		__asm__ __volatile__(I " [%1], %0"		\ 					: "=&r" (r)		\ 					: "r"   (target)	\ 					: "memory");		\ 		return (r);					\ 	}
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
argument|uint64_t
argument_list|,
literal|"ldx"
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
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"ldx"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"lduw"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"lduw"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"ldx"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"ldsw"
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
value|CK_CC_INLINE static void				\ 	ck_pr_md_store_##S(M *target, T v)			\ 	{							\ 		__asm__ __volatile__(I " %0, [%1]"		\ 					:			\ 					: "r" (v),		\ 					  "r" (target)		\ 					: "memory");		\ 		return;						\ 	}
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
argument|uint64_t
argument_list|,
literal|"stx"
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
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"stub"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"stx"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"stuw"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"stuw"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"stx"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"stsw"
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

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_64_value
parameter_list|(
name|uint64_t
modifier|*
name|target
parameter_list|,
name|uint64_t
name|compare
parameter_list|,
name|uint64_t
name|set
parameter_list|,
name|uint64_t
modifier|*
name|value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("casx [%1], %2, %0" 				: "+&r" (set) 				: "r"   (target), 				  "r"   (compare) 				: "memory");
operator|*
name|value
operator|=
name|set
expr_stmt|;
return|return
operator|(
name|compare
operator|==
name|set
operator|)
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_64
parameter_list|(
name|uint64_t
modifier|*
name|target
parameter_list|,
name|uint64_t
name|compare
parameter_list|,
name|uint64_t
name|set
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("casx [%1], %2, %0" 				: "+&r" (set) 				: "r" (target), 				  "r" (compare) 				: "memory");
return|return
operator|(
name|compare
operator|==
name|set
operator|)
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_ptr
parameter_list|(
name|void
modifier|*
name|target
parameter_list|,
name|void
modifier|*
name|compare
parameter_list|,
name|void
modifier|*
name|set
parameter_list|)
block|{
return|return
name|ck_pr_cas_64
argument_list|(
name|target
argument_list|,
operator|(
name|uint64_t
operator|)
name|compare
argument_list|,
operator|(
name|uint64_t
operator|)
name|set
argument_list|)
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_ptr_value
parameter_list|(
name|void
modifier|*
name|target
parameter_list|,
name|void
modifier|*
name|compare
parameter_list|,
name|void
modifier|*
name|set
parameter_list|,
name|void
modifier|*
name|previous
parameter_list|)
block|{
return|return
name|ck_pr_cas_64_value
argument_list|(
name|target
argument_list|,
operator|(
name|uint64_t
operator|)
name|compare
argument_list|,
operator|(
name|uint64_t
operator|)
name|set
argument_list|,
name|previous
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_CAS
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ 	ck_pr_cas_##N##_value(T *target, T compare, T set, T *value)	\ 	{								\ 		__asm__ __volatile__("cas [%1], %2, %0"			\ 					: "+&r" (set)			\ 					: "r"   (target),		\ 					  "r"   (compare)		\ 					: "memory");			\ 		*value = set;						\ 		return (compare == set);				\ 	} 								\ 	CK_CC_INLINE static bool					\ 	ck_pr_cas_##N(T *target, T compare, T set)			\ 	{								\ 		__asm__ __volatile__("cas [%1], %2, %0"			\ 					: "+&r" (set)			\ 					: "r" (target),			\ 					  "r" (compare)			\ 					: "memory");			\ 		return (compare == set);				\ 	}
end_define

begin_macro
name|CK_PR_CAS
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

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
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static T 					\ 	ck_pr_fas_##N(T *target, T update)			\ 	{							\ 								\ 		__asm__ __volatile__("swap [%1], %0"		\ 					: "+&r" (update)	\ 					: "r"   (target)	\ 					: "memory");		\ 		return (update);				\ 	}
end_define

begin_macro
name|CK_PR_FAS
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FAS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_SPARCV9_H */
end_comment

end_unit

