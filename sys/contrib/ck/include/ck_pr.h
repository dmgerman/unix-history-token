begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * Copyright 2011 David Joseph.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_H
end_define

begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_include
include|#
directive|include
file|<ck_limits.h>
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

begin_include
include|#
directive|include
file|<ck_stdbool.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CK_USE_CC_BUILTINS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"gcc/x86_64/ck_pr.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"gcc/x86/ck_pr.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparcv9__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"gcc/sparcv9/ck_pr.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc64__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"gcc/ppc64/ck_pr.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"gcc/ppc/ck_pr.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_include
include|#
directive|include
file|"gcc/arm/ck_pr.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"gcc/arm/ck_pr_armv4.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"gcc/aarch64/ck_pr.h"
end_include

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_error
error|#
directive|error
error|Your platform is unsupported
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CK_USE_CC_BUILTINS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"gcc/ck_pr.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CK_PR_FENCE_EMIT
parameter_list|(
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static void		\ 	ck_pr_fence_##T(void)			\ 	{					\ 		ck_pr_fence_strict_##T();	\ 		return;				\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_FENCE_NOOP
parameter_list|(
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static void		\ 	ck_pr_fence_##T(void)			\ 	{					\ 		ck_pr_barrier();		\ 		return;				\ 	}
end_define

begin_comment
comment|/*  * None of the currently supported platforms allow for data-dependent  * load ordering.  */
end_comment

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|load_depends
argument_list|)
end_macro

begin_define
define|#
directive|define
name|ck_pr_fence_strict_load_depends
value|ck_pr_fence_load_depends
end_define

begin_comment
comment|/*  * In memory models where atomic operations do not have serializing  * effects, atomic read-modify-write operations are modeled as stores.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_MD_RMO
argument_list|)
end_if

begin_comment
comment|/*  * Only stores to the same location have a global  * ordering.  */
end_comment

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|atomic_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|atomic_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|store_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|load_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|load_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|store_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|memory
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|acquire
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|release
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|acqrel
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|lock
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|unlock
argument_list|)
end_macro

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CK_MD_PSO
argument_list|)
end_elif

begin_comment
comment|/*  * Anything can be re-ordered with respect to stores.  * Otherwise, loads are executed in-order.  */
end_comment

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|atomic_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|atomic_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|store_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|load_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|load_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|store_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|memory
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|acquire
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|release
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|acqrel
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|lock
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|unlock
argument_list|)
end_macro

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CK_MD_TSO
argument_list|)
end_elif

begin_comment
comment|/*  * Only loads are re-ordered and only with respect to  * prior stores. Atomic operations are serializing.  */
end_comment

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|atomic_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|atomic_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|store_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|load_atomic
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|load_store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|store_load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|load
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|store
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_EMIT
argument_list|(
argument|memory
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|acquire
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|release
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|acqrel
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|lock
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE_NOOP
argument_list|(
argument|unlock
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"No memory model has been defined."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_MD_TSO */
end_comment

begin_undef
undef|#
directive|undef
name|CK_PR_FENCE_EMIT
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_FENCE_NOOP
end_undef

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
operator|(
name|void
operator|)
name|m
expr_stmt|;
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

begin_define
define|#
directive|define
name|CK_PR_STORE_SAFE
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|ck_pr_md_store_##TYPE(					\         ((void)sizeof(*(DST) = (VAL)), (DST)),			\         (VAL))
end_define

begin_define
define|#
directive|define
name|ck_pr_store_ptr
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), ptr)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_char
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), char)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_double
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), double)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_uint
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), uint)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_int
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), int)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_32
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), 32)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_16
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), 16)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_8
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), 8)
end_define

begin_define
define|#
directive|define
name|ck_pr_store_ptr_unsafe
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|ck_pr_md_store_ptr((DST), (VAL))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CK_F_PR_LOAD_64
end_ifdef

begin_define
define|#
directive|define
name|ck_pr_store_64
parameter_list|(
name|DST
parameter_list|,
name|VAL
parameter_list|)
value|CK_PR_STORE_SAFE((DST), (VAL), 64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_64 */
end_comment

begin_define
define|#
directive|define
name|CK_PR_LOAD_PTR_SAFE
parameter_list|(
name|SRC
parameter_list|)
value|(CK_CC_TYPEOF(*(SRC), (void *)))ck_pr_md_load_ptr((SRC))
end_define

begin_define
define|#
directive|define
name|ck_pr_load_ptr
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_PTR_SAFE((SRC))
end_define

begin_define
define|#
directive|define
name|CK_PR_LOAD_SAFE
parameter_list|(
name|SRC
parameter_list|,
name|TYPE
parameter_list|)
value|ck_pr_md_load_##TYPE((SRC))
end_define

begin_define
define|#
directive|define
name|ck_pr_load_char
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), char)
end_define

begin_define
define|#
directive|define
name|ck_pr_load_double
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), double)
end_define

begin_define
define|#
directive|define
name|ck_pr_load_uint
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), uint)
end_define

begin_define
define|#
directive|define
name|ck_pr_load_int
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), int)
end_define

begin_define
define|#
directive|define
name|ck_pr_load_32
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), 32)
end_define

begin_define
define|#
directive|define
name|ck_pr_load_16
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), 16)
end_define

begin_define
define|#
directive|define
name|ck_pr_load_8
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), 8)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CK_F_PR_LOAD_64
end_ifdef

begin_define
define|#
directive|define
name|ck_pr_load_64
parameter_list|(
name|SRC
parameter_list|)
value|CK_PR_LOAD_SAFE((SRC), 64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_64 */
end_comment

begin_define
define|#
directive|define
name|CK_PR_BIN
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|C
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_##K##_##S(M *target, T value)				\ 	{								\ 		T previous;						\ 		C punt;							\ 		punt = ck_pr_md_load_##S(target);			\ 		previous = (T)punt;					\ 		while (ck_pr_cas_##S##_value(target,			\ 					     (C)previous,		\ 					     (C)(previous P value),	\&previous) == false)	\ 			ck_pr_stall();					\ 									\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_BIN_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|)
value|CK_PR_BIN(K, S, T, T, P, T)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_CHAR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_CHAR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_CHAR
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_CHAR
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_CHAR
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|and
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|&
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_CHAR
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|xor
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|^
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_CHAR
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|or
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument||
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_CHAR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_CHAR&& CK_F_PR_CAS_CHAR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_INT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_INT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_INT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_INT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|and
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|&
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_INT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|xor
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|^
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_INT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|or
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument||
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_INT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_INT&& CK_F_PR_CAS_INT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_DOUBLE
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_DOUBLE_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_DOUBLE
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_DOUBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_DOUBLE
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_DOUBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_DOUBLE&& CK_F_PR_CAS_DOUBLE_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_UINT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_UINT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_UINT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_UINT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_UINT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|and
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|&
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_UINT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|xor
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|^
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_UINT
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|or
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument||
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_UINT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_UINT&& CK_F_PR_CAS_UINT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_PTR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_PTR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_PTR
end_define

begin_macro
name|CK_PR_BIN
argument_list|(
argument|add
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|+
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_PTR
end_define

begin_macro
name|CK_PR_BIN
argument_list|(
argument|sub
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|-
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_PTR
end_define

begin_macro
name|CK_PR_BIN
argument_list|(
argument|and
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|&
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_PTR
end_define

begin_macro
name|CK_PR_BIN
argument_list|(
argument|xor
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|^
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_PTR
end_define

begin_macro
name|CK_PR_BIN
argument_list|(
argument|or
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument||
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_PTR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_PTR&& CK_F_PR_CAS_PTR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_64
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_64_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_64
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_64
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_64
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|and
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|&
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_64
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|xor
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|^
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_64
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|or
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument||
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_64&& CK_F_PR_CAS_64_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_32
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_32_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_32
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_32
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_32
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|and
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|&
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_32
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|xor
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|^
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_32
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|or
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument||
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_32&& CK_F_PR_CAS_32_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_16
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_16_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_16
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_16
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_16
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|and
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|&
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_16
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|xor
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|^
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_16
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|or
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument||
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_16 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_16&& CK_F_PR_CAS_16_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_8
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_8_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_ADD_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_ADD_8
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|add
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|+
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_ADD_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_SUB_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_SUB_8
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|sub
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_SUB_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_AND_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_AND_8
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|and
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|&
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_AND_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_XOR_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_XOR_8
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|xor
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|^
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_XOR_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_OR_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_OR_8
end_define

begin_macro
name|CK_PR_BIN_S
argument_list|(
argument|or
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument||
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_OR_8 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_8&& CK_F_PR_CAS_8_VALUE */
end_comment

begin_undef
undef|#
directive|undef
name|CK_PR_BIN_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_BIN
end_undef

begin_define
define|#
directive|define
name|CK_PR_BTX
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|C
parameter_list|,
name|R
parameter_list|)
define|\
value|CK_CC_INLINE static bool						   \ 	ck_pr_##K##_##S(M *target, unsigned int offset)				   \ 	{									   \ 		T previous;							   \ 		C punt;								   \ 		punt = ck_pr_md_load_##S(target);				   \ 		previous = (T)punt;						   \ 		while (ck_pr_cas_##S##_value(target, (C)previous,		   \ 			(C)(previous P (R ((T)1<< offset))),&previous) == false) \ 				ck_pr_stall();					   \ 		return ((previous>> offset)& 1);				   \ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_BTX_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|R
parameter_list|)
value|CK_PR_BTX(K, S, T, T, P, T, R)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_INT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTC_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTC_INT
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btc
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|^
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTC_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTR_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTR_INT
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btr
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|&
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTR_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTS_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTS_INT
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|bts
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument||
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTS_INT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_INT&& CK_F_PR_CAS_INT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_UINT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_UINT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTC_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTC_UINT
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btc
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|^
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTC_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTR_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTR_UINT
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btr
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|&
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTR_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTS_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTS_UINT
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|bts
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument||
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTS_UINT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_UINT&& CK_F_PR_CAS_UINT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_PTR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_PTR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTC_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTC_PTR
end_define

begin_macro
name|CK_PR_BTX
argument_list|(
argument|btc
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|^
argument_list|,
argument|void *
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTC_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTR_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTR_PTR
end_define

begin_macro
name|CK_PR_BTX
argument_list|(
argument|btr
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|&
argument_list|,
argument|void *
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTR_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTS_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTS_PTR
end_define

begin_macro
name|CK_PR_BTX
argument_list|(
argument|bts
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument||
argument_list|,
argument|void *
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTS_PTR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_PTR&& CK_F_PR_CAS_PTR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_64
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_64_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTC_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTC_64
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btc
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|^
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTC_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTR_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTR_64
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btr
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|&
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTR_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTS_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTS_64
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|bts
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument||
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTS_64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_64&& CK_F_PR_CAS_64_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_32
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_32_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTC_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTC_32
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btc
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|^
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTC_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTR_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTR_32
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btr
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|&
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTR_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTS_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTS_32
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|bts
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument||
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTS_32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_32&& CK_F_PR_CAS_32_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_16
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_16_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTC_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTC_16
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btc
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|^
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTC_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTR_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTR_16
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|btr
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|&
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTR_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_BTS_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_BTS_16
end_define

begin_macro
name|CK_PR_BTX_S
argument_list|(
argument|bts
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument||
argument_list|,)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_BTS_16 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_16&& CK_F_PR_CAS_16_VALUE */
end_comment

begin_undef
undef|#
directive|undef
name|CK_PR_BTX_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_BTX
end_undef

begin_define
define|#
directive|define
name|CK_PR_UNARY
parameter_list|(
name|K
parameter_list|,
name|X
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_##K##_##S(M *target)					\ 	{								\ 		ck_pr_##X##_##S(target, (T)1);				\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_UNARY_Z
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|C
parameter_list|,
name|Z
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_##K##_##S##_zero(M *target, bool *zero)			\ 	{								\ 		T previous;						\ 		C punt;							\ 		punt = (C)ck_pr_md_load_##S(target);			\ 		previous = (T)punt;					\ 		while (ck_pr_cas_##S##_value(target,			\ 					     (C)previous,		\ 					     (C)(previous P 1),		\&previous) == false)	\ 			ck_pr_stall();					\ 		*zero = previous == (T)Z;				\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_UNARY_S
parameter_list|(
name|K
parameter_list|,
name|X
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|)
value|CK_PR_UNARY(K, X, S, M, M)
end_define

begin_define
define|#
directive|define
name|CK_PR_UNARY_Z_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|P
parameter_list|,
name|Z
parameter_list|)
value|CK_PR_UNARY_Z(K, S, M, M, P, M, Z)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_CHAR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_CHAR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_CHAR
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_CHAR_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_CHAR_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|inc
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|+
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_CHAR_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_CHAR
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_CHAR_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_CHAR_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|dec
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_CHAR_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_CHAR&& CK_F_PR_CAS_CHAR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_INT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_INT
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_INT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_INT_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|inc
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|+
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_INT_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_INT
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_INT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_INT_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|dec
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_INT_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_INT&& CK_F_PR_CAS_INT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_DOUBLE
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_DOUBLE_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_DOUBLE
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_DOUBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_DOUBLE
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_DOUBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_DOUBLE&& CK_F_PR_CAS_DOUBLE_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_UINT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_UINT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_UINT
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_UINT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_UINT_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|inc
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|+
argument_list|,
argument|UINT_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_UINT_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_UINT
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_UINT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_UINT_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|dec
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_UINT_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_UINT&& CK_F_PR_CAS_UINT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_PTR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_PTR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_PTR
end_define

begin_macro
name|CK_PR_UNARY
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_PTR_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_PTR_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z
argument_list|(
argument|inc
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|+
argument_list|,
argument|void *
argument_list|,
argument|UINT_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_PTR_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_PTR
end_define

begin_macro
name|CK_PR_UNARY
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_PTR_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_PTR_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z
argument_list|(
argument|dec
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|-
argument_list|,
argument|void *
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_PTR_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_PTR&& CK_F_PR_CAS_PTR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_64
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_64_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_64
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_64_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_64_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|inc
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|+
argument_list|,
argument|UINT64_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_64_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_64
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_64_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_64_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|dec
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_64_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_64&& CK_F_PR_CAS_64_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_32
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_32_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_32
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_32_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_32_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|inc
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|+
argument_list|,
argument|UINT32_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_32_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_32
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_32_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_32_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|dec
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_32_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_32&& CK_F_PR_CAS_32_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_16
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_16_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_16
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_16_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_16_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|inc
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|+
argument_list|,
argument|UINT16_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_16_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_16
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_16_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_16_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|dec
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_16_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_16&& CK_F_PR_CAS_16_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_8
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_8_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_8
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|inc
argument_list|,
argument|add
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_INC_8_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_INC_8_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|inc
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|+
argument_list|,
argument|UINT8_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_INC_8_ZERO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_8
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|dec
argument_list|,
argument|sub
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_DEC_8_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_DEC_8_ZERO
end_define

begin_macro
name|CK_PR_UNARY_Z_S
argument_list|(
argument|dec
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_DEC_8_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_8&& CK_F_PR_CAS_8_VALUE */
end_comment

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_Z_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY_Z
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_UNARY
end_undef

begin_define
define|#
directive|define
name|CK_PR_N
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|C
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_##K##_##S(M *target)					\ 	{								\ 		T previous;						\ 		C punt;							\ 		punt = (C)ck_pr_md_load_##S(target);			\ 		previous = (T)punt;					\ 		while (ck_pr_cas_##S##_value(target,			\ 					     (C)previous,		\ 					     (C)(P previous),		\&previous) == false)	\ 			ck_pr_stall();					\ 									\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_N_Z
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|C
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ 	ck_pr_neg_##S##_zero(M *target, bool *zero)			\ 	{								\ 		T previous;						\ 		C punt;							\ 		punt = (C)ck_pr_md_load_##S(target);			\ 		previous = (T)punt;					\ 		while (ck_pr_cas_##S##_value(target,			\ 					     (C)previous,		\ 					     (C)(-previous),		\&previous) == false)	\ 			ck_pr_stall();					\ 									\ 		*zero = previous == 0;					\ 		return;							\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_N_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|P
parameter_list|)
value|CK_PR_N(K, S, M, M, P, M)
end_define

begin_define
define|#
directive|define
name|CK_PR_N_Z_S
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|)
value|CK_PR_N_Z(S, M, M, M)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_CHAR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_CHAR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_CHAR
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|not
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_CHAR
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
argument|char
argument_list|,
argument|char
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_CHAR_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_CHAR_ZERO
end_define

begin_macro
name|CK_PR_N_Z_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_CHAR_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_CHAR&& CK_F_PR_CAS_CHAR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_INT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_INT
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|not
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_INT
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_INT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_INT_ZERO
end_define

begin_macro
name|CK_PR_N_Z_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_INT_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_INT&& CK_F_PR_CAS_INT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_DOUBLE
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_DOUBLE_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_DOUBLE
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_DOUBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_DOUBLE&& CK_F_PR_CAS_DOUBLE_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_UINT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_UINT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_UINT
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|not
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_UINT
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_UINT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_UINT_ZERO
end_define

begin_macro
name|CK_PR_N_Z_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_UINT_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_UINT&& CK_F_PR_CAS_UINT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_PTR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_PTR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_PTR
end_define

begin_macro
name|CK_PR_N
argument_list|(
argument|not
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|~
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_PTR
end_define

begin_macro
name|CK_PR_N
argument_list|(
argument|neg
argument_list|,
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|-
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_PTR_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_PTR_ZERO
end_define

begin_macro
name|CK_PR_N_Z
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|uintptr_t
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_PTR_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_PTR&& CK_F_PR_CAS_PTR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_64
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_64_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_64
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|not
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_64
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_64_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_64_ZERO
end_define

begin_macro
name|CK_PR_N_Z_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_64_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_64&& CK_F_PR_CAS_64_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_32
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_32_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_32
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|not
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_32
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_32_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_32_ZERO
end_define

begin_macro
name|CK_PR_N_Z_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_32_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_32&& CK_F_PR_CAS_32_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_16
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_16_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_16
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|not
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_16
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
literal|16
argument_list|,
argument|uint16_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_16_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_16_ZERO
end_define

begin_macro
name|CK_PR_N_Z_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_16_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_16&& CK_F_PR_CAS_16_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_8
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_8_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NOT_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NOT_8
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|not
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|~
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NOT_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_8
end_define

begin_macro
name|CK_PR_N_S
argument_list|(
argument|neg
argument_list|,
literal|8
argument_list|,
argument|uint8_t
argument_list|,
argument|-
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_NEG_8_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_NEG_8_ZERO
end_define

begin_macro
name|CK_PR_N_Z_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_NEG_8_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_8&& CK_F_PR_CAS_8_VALUE */
end_comment

begin_undef
undef|#
directive|undef
name|CK_PR_N_Z_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_N_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_N_Z
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_N
end_undef

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
parameter_list|)
define|\
value|CK_CC_INLINE static C						\ 	ck_pr_faa_##S(M *target, T delta)				\ 	{								\ 		T previous;						\ 		C punt;							\ 		punt = (C)ck_pr_md_load_##S(target);			\ 		previous = (T)punt;					\ 		while (ck_pr_cas_##S##_value(target,			\ 					     (C)previous,		\ 					     (C)(previous + delta),	\&previous) == false)	\ 			ck_pr_stall();					\ 									\ 		return ((C)previous);					\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_FAS
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|C
parameter_list|)
define|\
value|CK_CC_INLINE static C						\ 	ck_pr_fas_##S(M *target, C update)				\ 	{								\ 		C previous;						\ 		previous = ck_pr_md_load_##S(target);			\ 		while (ck_pr_cas_##S##_value(target,			\ 					     previous,			\ 					     update,			\&previous) == false)	\ 			ck_pr_stall();					\ 									\ 		return (previous);					\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_FAA_S
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|)
value|CK_PR_FAA(S, M, M, M)
end_define

begin_define
define|#
directive|define
name|CK_PR_FAS_S
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|)
value|CK_PR_FAS(S, M, M)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_CHAR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_CHAR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_CHAR
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_CHAR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_CHAR
end_define

begin_macro
name|CK_PR_FAS_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_CHAR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_CHAR&& CK_F_PR_CAS_CHAR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_INT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_INT
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_INT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_INT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_INT
end_define

begin_macro
name|CK_PR_FAS_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_INT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_INT&& CK_F_PR_CAS_INT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_DOUBLE
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_DOUBLE_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_DOUBLE
end_define

begin_macro
name|CK_PR_FAA_S
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

begin_comment
comment|/* CK_F_PR_FAA_DOUBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_DOUBLE
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_DOUBLE
end_define

begin_macro
name|CK_PR_FAS_S
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

begin_comment
comment|/* CK_F_PR_FAS_DOUBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_DOUBLE&& CK_F_PR_CAS_DOUBLE_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_UINT
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_UINT_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_UINT
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_UINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_UINT
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_UINT
end_define

begin_macro
name|CK_PR_FAS_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_UINT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_UINT&& CK_F_PR_CAS_UINT_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_PTR
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_PTR_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_PTR
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
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_PTR
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_PTR
end_define

begin_macro
name|CK_PR_FAS
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_PTR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_PTR&& CK_F_PR_CAS_PTR_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_64
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_64_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_64
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_64
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_64
end_define

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_64&& CK_F_PR_CAS_64_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_32
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_32_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_32
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_32
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_32
end_define

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_32&& CK_F_PR_CAS_32_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_16
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_16_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_16
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_16
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_16
end_define

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_16 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_16&& CK_F_PR_CAS_16_VALUE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_F_PR_LOAD_8
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_F_PR_CAS_8_VALUE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAA_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAA_8
end_define

begin_macro
name|CK_PR_FAA_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAA_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_PR_FAS_8
end_ifndef

begin_define
define|#
directive|define
name|CK_F_PR_FAS_8
end_define

begin_macro
name|CK_PR_FAS_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_FAS_8 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_LOAD_8&& CK_F_PR_CAS_8_VALUE */
end_comment

begin_undef
undef|#
directive|undef
name|CK_PR_FAA_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_FAS_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_FAA
end_undef

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
comment|/* CK_PR_H */
end_comment

end_unit

