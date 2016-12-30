begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_GCC_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_GCC_H
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

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_barrier
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

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR
end_define

begin_include
include|#
directive|include
file|<ck_stdbool.h>
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

begin_define
define|#
directive|define
name|CK_PR_ACCESS
parameter_list|(
name|x
parameter_list|)
value|(*(volatile __typeof__(x) *)&(x))
end_define

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
parameter_list|)
define|\
value|CK_CC_INLINE static T					\ 	ck_pr_md_load_##S(const M *target)			\ 	{							\ 		T r;						\ 		ck_pr_barrier();				\ 		r = CK_PR_ACCESS(*(const T *)target);		\ 		ck_pr_barrier();				\ 		return (r);					\ 	}							\ 	CK_CC_INLINE static void				\ 	ck_pr_md_store_##S(M *target, T v)			\ 	{							\ 		ck_pr_barrier();				\ 		CK_PR_ACCESS(*(T *)target) = v;			\ 		ck_pr_barrier();				\ 		return;						\ 	}
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|void
modifier|*
name|ck_pr_md_load_ptr
parameter_list|(
specifier|const
name|void
modifier|*
name|target
parameter_list|)
block|{
name|void
modifier|*
name|r
decl_stmt|;
name|ck_pr_barrier
argument_list|()
expr_stmt|;
name|r
operator|=
name|CK_CC_DECONST_PTR
argument_list|(
name|CK_PR_ACCESS
argument_list|(
name|target
argument_list|)
argument_list|)
expr_stmt|;
name|ck_pr_barrier
argument_list|()
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pr_md_store_ptr
parameter_list|(
name|void
modifier|*
name|target
parameter_list|,
specifier|const
name|void
modifier|*
name|v
parameter_list|)
block|{
name|ck_pr_barrier
argument_list|()
expr_stmt|;
name|CK_PR_ACCESS
argument_list|(
name|target
argument_list|)
operator|=
name|CK_CC_DECONST_PTR
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|ck_pr_barrier
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_LOAD_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
value|CK_PR_LOAD(S, T, T)
end_define

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|int
argument_list|,
argument|int
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
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
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
name|ck_pr_stall
parameter_list|(
name|void
parameter_list|)
block|{
name|ck_pr_barrier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Load and store fences are equivalent to full fences in the GCC port.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_FENCE
parameter_list|(
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static void			\ 	ck_pr_fence_strict_##T(void)			\ 	{						\ 		__sync_synchronize();			\ 	}
end_define

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|memory
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acquire
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|release
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acqrel
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|lock
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|unlock
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FENCE
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
parameter_list|)
define|\
value|CK_CC_INLINE static bool						\ 	ck_pr_cas_##S(M *target, T compare, T set)				\ 	{									\ 		bool z;								\ 		z = __sync_bool_compare_and_swap((T *)target, compare, set);	\ 		return z;							\ 	}
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
name|S
parameter_list|,
name|T
parameter_list|)
value|CK_PR_CAS(S, T, T)
end_define

begin_macro
name|CK_PR_CAS_S
argument_list|(
argument|char
argument_list|,
argument|char
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
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

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
name|v
parameter_list|)
block|{
name|set
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|)
name|target
argument_list|,
name|compare
argument_list|,
name|set
argument_list|)
expr_stmt|;
operator|*
operator|(
name|void
operator|*
operator|*
operator|)
name|v
operator|=
name|set
expr_stmt|;
return|return
operator|(
name|set
operator|==
name|compare
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_CAS_O
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ 	ck_pr_cas_##S##_value(T *target, T compare, T set, T *v)	\ 	{								\ 		set = __sync_val_compare_and_swap(target, compare, set);\ 		*v = set;						\ 		return (set == compare);				\ 	}
end_define

begin_macro
name|CK_PR_CAS_O
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS_O
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_CAS_O
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
parameter_list|)
define|\
value|CK_CC_INLINE static T					\ 	ck_pr_faa_##S(M *target, T d)				\ 	{							\ 		d = __sync_fetch_and_add((T *)target, d);	\ 		return (d);					\ 	}
end_define

begin_macro
name|CK_PR_FAA
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
name|CK_PR_FAA_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
value|CK_PR_FAA(S, T, T)
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
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
parameter_list|)
define|\
value|CK_CC_INLINE static void				\ 	ck_pr_##K##_##S(M *target, T d)				\ 	{							\ 		d = __sync_fetch_and_##K((T *)target, d);	\ 		return;						\ 	}
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
parameter_list|)
value|CK_PR_BINARY(K, S, T, T)
end_define

begin_define
define|#
directive|define
name|CK_PR_GENERATE
parameter_list|(
name|K
parameter_list|)
define|\
value|CK_PR_BINARY(K, ptr, void, void *)	\ 	CK_PR_BINARY_S(K, char, char)		\ 	CK_PR_BINARY_S(K, int, int)		\ 	CK_PR_BINARY_S(K, uint, unsigned int)	\ 	CK_PR_BINARY_S(K, 64, uint64_t)		\ 	CK_PR_BINARY_S(K, 32, uint32_t)		\ 	CK_PR_BINARY_S(K, 16, uint16_t)		\ 	CK_PR_BINARY_S(K, 8, uint8_t)
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

begin_define
define|#
directive|define
name|CK_PR_UNARY
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static void		\ 	ck_pr_inc_##S(M *target)		\ 	{					\ 		ck_pr_add_##S(target, (T)1);	\ 		return;				\ 	}					\ 	CK_CC_INLINE static void		\ 	ck_pr_dec_##S(M *target)		\ 	{					\ 		ck_pr_sub_##S(target, (T)1);	\ 		return;				\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_UNARY_S
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|)
value|CK_PR_UNARY(S, M, M)
end_define

begin_macro
name|CK_PR_UNARY
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CK_F_PR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_GCC_H */
end_comment

end_unit

