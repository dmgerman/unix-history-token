begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2016 Samy Al Bahra.  * Copyright 2013-2016 Olivier Houchard.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_AARCH64_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_AARCH64_H
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
name|CK_DMB_SY
value|__asm __volatile("dmb ish" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|CK_DMB_LD
value|__asm __volatile("dmb ishld" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|CK_DMB_ST
value|__asm __volatile("dmb ishst" : : "r" (0) : "memory")
end_define

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

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic
argument_list|,
argument|CK_DMB_ST
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_store
argument_list|,
argument|CK_DMB_ST
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_load
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_atomic
argument_list|,
argument|CK_DMB_ST
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_atomic
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store
argument_list|,
argument|CK_DMB_ST
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_load
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load
argument_list|,
argument|CK_DMB_LD
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_store
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|memory
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acquire
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|release
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acqrel
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|lock
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|unlock
argument_list|,
argument|CK_DMB_SY
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FENCE
end_undef

begin_undef
undef|#
directive|undef
name|CK_DMB_SI
end_undef

begin_undef
undef|#
directive|undef
name|CK_DMB_LD
end_undef

begin_undef
undef|#
directive|undef
name|CK_DMB_ST
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
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static T					\ 	ck_pr_md_load_##S(const M *target)			\ 	{							\ 		long r = 0;					\ 		__asm__ __volatile__(I " %w0, [%1];"		\ 					: "=r" (r)		\ 					: "r"  (target)		\ 					: "memory");		\ 		return ((T)r);					\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_LOAD_64
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static T					\ 	ck_pr_md_load_##S(const M *target)			\ 	{							\ 		long r = 0;					\ 		__asm__ __volatile__(I " %0, [%1];"		\ 					: "=r" (r)		\ 					: "r"  (target)		\ 					: "memory");		\ 		return ((T)r);					\ 	}
end_define

begin_macro
name|CK_PR_LOAD_64
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
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
value|CK_PR_LOAD(S, T, T, I)
end_define

begin_define
define|#
directive|define
name|CK_PR_LOAD_S_64
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_LOAD_64(S, T, T, I)
end_define

begin_macro
name|CK_PR_LOAD_S_64
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"ldr"
argument_list|)
end_macro

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

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_LOAD_S_64
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"ldr"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CK_PR_LOAD_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_LOAD_S_64
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_LOAD
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_LAOD_64
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
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static void				\ 	ck_pr_md_store_##S(M *target, T v)			\ 	{							\ 		__asm__ __volatile__(I " %w1, [%0]"		\ 					:			\ 					: "r" (target),		\ 					  "r" (v)		\ 					: "memory");		\ 		return;						\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_STORE_64
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
define|\
value|CK_CC_INLINE static void				\ 	ck_pr_md_store_##S(M *target, T v)			\ 	{							\ 		__asm__ __volatile__(I " %1, [%0]"		\ 					:			\ 					: "r" (target),		\ 					  "r" (v)		\ 					: "memory");		\ 		return;						\ 	}
end_define

begin_macro
name|CK_PR_STORE_64
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|const void *
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
value|CK_PR_STORE(S, T, T, I)
end_define

begin_define
define|#
directive|define
name|CK_PR_STORE_S_64
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|I
parameter_list|)
value|CK_PR_STORE_64(S, T, T, I)
end_define

begin_macro
name|CK_PR_STORE_S_64
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"str"
argument_list|)
end_macro

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

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_STORE_S_64
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"str"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CK_PR_STORE_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_STORE_S_64
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_STORE
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_STORE_64
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|CK_MD_LSE_ENABLE
end_ifdef

begin_include
include|#
directive|include
file|"ck_pr_lse.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ck_pr_llsc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ck_pr_neg_*() functions can only be implemented via LL/SC, as there are no  * LSE alternatives.  */
end_comment

begin_define
define|#
directive|define
name|CK_PR_NEG
parameter_list|(
name|N
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|W
parameter_list|,
name|R
parameter_list|)
define|\
value|CK_CC_INLINE static void				\         ck_pr_neg_##N(M *target)				\         {							\                 T previous = 0;					\                 T tmp = 0;					\                 __asm__ __volatile__("1:"			\                                      "ldxr" W " %" R "0, [%2];"	\                                      "neg %" R "0, %" R "0;"	\                                      "stxr" W " %w1, %" R "0, [%2];"	\                                      "cbnz %w1, 1b;"		\                                         : "=&r" (previous),	\                                           "=&r" (tmp)		\                                         : "r"   (target)	\                                         : "memory", "cc");	\                 return;						\         }
end_define

begin_macro
name|CK_PR_NEG
argument_list|(
argument|ptr
argument_list|,
argument|void
argument_list|,
argument|void *
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_NEG
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|uint64_t
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|)
end_macro

begin_define
define|#
directive|define
name|CK_PR_NEG_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_PR_NEG(S, T, T, W, "w")				\  CK_PR_NEG_S(32, uint32_t, "")
end_define

begin_macro
name|CK_PR_NEG_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_NEG_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_NEG_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_NEG_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_macro
name|CK_PR_NEG_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_NEG_S
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
name|CK_PR_NEG_S
end_undef

begin_undef
undef|#
directive|undef
name|CK_PR_NEG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_AARCH64_H */
end_comment

end_unit

