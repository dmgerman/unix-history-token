begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_PPC64_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PR_PPC64_H
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
comment|/*  * This bounces the hardware thread from low to medium  * priority. I am unsure of the benefits of this approach  * but it is used by the Linux kernel.  */
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
asm|("or 1, 1, 1;" 			     "or 2, 2, 2;" ::: "memory");
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
comment|/*  * These are derived from:  *     http://www.ibm.com/developerworks/systems/articles/powerpc.html  */
end_comment

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_store
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|atomic_load
argument_list|,
literal|"sync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_atomic
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_atomic
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|store_load
argument_list|,
literal|"sync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_store
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|memory
argument_list|,
literal|"sync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acquire
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|release
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acqrel
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|lock
argument_list|,
literal|"lwsync"
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|unlock
argument_list|,
literal|"lwsync"
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
value|CK_CC_INLINE static T						\ 	ck_pr_md_load_##S(const M *target)				\ 	{								\ 		T r;							\ 		__asm__ __volatile__(I "%U1%X1 %0, %1"			\ 					: "=r" (r)			\ 					: "m"  (*(const C *)target)	\ 					: "memory");			\ 		return (r);						\ 	}
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
literal|"ld"
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
literal|"ld"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"lwz"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"lhz"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"lbz"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"lwz"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"lwz"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"lhz"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"lbz"
argument_list|)
end_macro

begin_macro
name|CK_PR_LOAD_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"ld"
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
value|CK_CC_INLINE static void				\ 	ck_pr_md_store_##S(M *target, T v)			\ 	{							\ 		__asm__ __volatile__(I "%U0%X0 %1, %0"		\ 					: "=m" (*(C *)target)	\ 					: "r" (v)		\ 					: "memory");		\ 		return;						\ 	}
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
literal|"std"
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
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"std"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"stw"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"sth"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"stb"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"stw"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"stw"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"sth"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|char
argument_list|,
argument|char
argument_list|,
literal|"stb"
argument_list|)
end_macro

begin_macro
name|CK_PR_STORE_S
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
literal|"std"
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
name|uint64_t
name|previous
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldarx %0, 0, %1;" 			     "cmpd  0, %0, %3;" 			     "bne-  2f;" 			     "stdcx. %2, 0, %1;" 			     "bne-  1b;" 			     "2:"                                 : "=&r" (previous)                                 : "r"   (target), 				  "r"   (set),                                   "r"   (compare)                                 : "memory", "cc");
operator|*
name|value
operator|=
name|previous
expr_stmt|;
return|return
operator|(
name|previous
operator|==
name|compare
operator|)
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
name|value
parameter_list|)
block|{
name|void
modifier|*
name|previous
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldarx %0, 0, %1;" 			     "cmpd  0, %0, %3;" 			     "bne-  2f;" 			     "stdcx. %2, 0, %1;" 			     "bne-  1b;" 			     "2:"                                 : "=&r" (previous)                                 : "r"   (target), 				  "r"   (set),                                   "r"   (compare)                                 : "memory", "cc");
name|ck_pr_md_store_ptr
argument_list|(
name|value
argument_list|,
name|previous
argument_list|)
expr_stmt|;
return|return
operator|(
name|previous
operator|==
name|compare
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
name|uint64_t
name|previous
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldarx %0, 0, %1;" 			     "cmpd  0, %0, %3;" 			     "bne-  2f;" 			     "stdcx. %2, 0, %1;" 			     "bne-  1b;" 			     "2:"                                 : "=&r" (previous)                                 : "r"   (target), 				  "r"   (set),                                   "r"   (compare)                                 : "memory", "cc");
return|return
operator|(
name|previous
operator|==
name|compare
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
name|void
modifier|*
name|previous
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldarx %0, 0, %1;" 			     "cmpd  0, %0, %3;" 			     "bne-  2f;" 			     "stdcx. %2, 0, %1;" 			     "bne-  1b;" 			     "2:"                                 : "=&r" (previous)                                 : "r"   (target), 				  "r"   (set),                                   "r"   (compare)                                 : "memory", "cc");
return|return
operator|(
name|previous
operator|==
name|compare
operator|)
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
value|CK_CC_INLINE static bool					\ 	ck_pr_cas_##N##_value(T *target, T compare, T set, T *value)	\ 	{								\ 		T previous;						\ 		__asm__ __volatile__("1:"				\ 				     "lwarx %0, 0, %1;"			\ 				     "cmpw  0, %0, %3;"			\ 				     "bne-  2f;"			\ 				     "stwcx. %2, 0, %1;"		\ 				     "bne-  1b;"			\ 				     "2:"				\ 					: "=&r" (previous)		\ 					: "r"   (target),		\ 					  "r"   (set),			\ 					  "r"   (compare)		\ 					: "memory", "cc");		\ 		*value = previous; 					\ 		return (previous == compare);				\ 	}								\ 	CK_CC_INLINE static bool					\ 	ck_pr_cas_##N(T *target, T compare, T set)			\ 	{								\ 		T previous;						\ 		__asm__ __volatile__("1:"				\ 				     "lwarx %0, 0, %1;"			\ 				     "cmpw  0, %0, %3;"			\ 				     "bne-  2f;"			\ 				     "stwcx. %2, 0, %1;"		\ 				     "bne-  1b;"			\ 				     "2:"				\ 					: "=&r" (previous)		\ 					: "r"   (target),		\ 					  "r"   (set),			\ 					  "r"   (compare)		\ 					: "memory", "cc");		\ 		return (previous == compare);				\ 	}
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
name|M
parameter_list|,
name|T
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_CC_INLINE static T					\ 	ck_pr_fas_##N(M *target, T v)				\ 	{							\ 		T previous;					\ 		__asm__ __volatile__("1:"			\ 				     "l" W "arx %0, 0, %1;"	\ 				     "st" W "cx. %2, 0, %1;"	\ 				     "bne- 1b;"			\ 					: "=&r" (previous)	\ 					: "r"   (target),	\ 					  "r"   (v)		\ 					: "memory", "cc");	\ 		return (previous);				\ 	}
end_define

begin_macro
name|CK_PR_FAS
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
argument|uint64_t
argument_list|,
literal|"d"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
argument|uint32_t
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAS
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|,
argument|double
argument_list|,
literal|"d"
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
literal|"d"
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
literal|"w"
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
literal|"w"
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
value|CK_CC_INLINE static void				\ 	ck_pr_##O##_##N(M *target)				\ 	{							\ 		T previous;					\ 		__asm__ __volatile__("1:"			\ 				     "l" W "arx %0, 0, %1;"	\ 				      I ";"			\ 				     "st" W "cx. %0, 0, %1;"	\ 				     "bne-  1b;"		\ 					: "=&r" (previous)	\ 					: "r"   (target)	\ 					: "memory", "cc");	\ 		return;						\ 	}
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
literal|"addic %0, %0, 1"
argument_list|,
literal|"d"
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
literal|"addic %0, %0, -1"
argument_list|,
literal|"d"
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
literal|"not %0, %0"
argument_list|,
literal|"d"
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
literal|"neg %0, %0"
argument_list|,
literal|"d"
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
value|CK_PR_UNARY(inc, S, T, T, "addic %0, %0, 1", W)		\ 	CK_PR_UNARY(dec, S, T, T, "addic %0, %0, -1", W)	\ 	CK_PR_UNARY(not, S, T, T, "not %0, %0", W)		\ 	CK_PR_UNARY(neg, S, T, T, "neg %0, %0", W)
end_define

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"d"
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_macro
name|CK_PR_UNARY_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"w"
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
value|CK_CC_INLINE static void				\ 	ck_pr_##O##_##N(M *target, T delta)			\ 	{							\ 		T previous;					\ 		__asm__ __volatile__("1:"			\ 				     "l" W "arx %0, 0, %1;"	\ 				      I " %0, %2, %0;"		\ 				     "st" W "cx. %0, 0, %1;"	\ 				     "bne-  1b;"		\ 					: "=&r" (previous)	\ 					: "r"   (target),	\ 					  "r"   (delta)		\ 					: "memory", "cc");	\ 		return;						\ 	}
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
literal|"and"
argument_list|,
literal|"d"
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
literal|"add"
argument_list|,
literal|"d"
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
literal|"or"
argument_list|,
literal|"d"
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
literal|"sub"
argument_list|,
literal|"d"
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
literal|"xor"
argument_list|,
literal|"d"
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
value|CK_PR_BINARY(and, S, T, T, "and", W)	\ 	CK_PR_BINARY(add, S, T, T, "add", W)	\ 	CK_PR_BINARY(or, S, T, T, "or", W)	\ 	CK_PR_BINARY(sub, S, T, T, "subf", W)	\ 	CK_PR_BINARY(xor, S, T, T, "xor", W)
end_define

begin_macro
name|CK_PR_BINARY_S
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"d"
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_macro
name|CK_PR_BINARY_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"w"
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
decl_stmt|,
name|r
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldarx %0, 0, %2;" 			     "add %1, %3, %0;" 			     "stdcx. %1, 0, %2;" 			     "bne-  1b;" 				: "=&r" (previous), 				  "=&r" (r) 				: "r"   (target), 				  "r"   (delta) 				: "memory", "cc");
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
value|CK_CC_INLINE static T						\ 	ck_pr_faa_##S(T *target, T delta)				\ 	{								\ 		T previous, r;						\ 		__asm__ __volatile__("1:"				\ 				     "l" W "arx %0, 0, %2;"		\ 				     "add %1, %3, %0;"			\ 				     "st" W "cx. %1, 0, %2;"		\ 				     "bne-  1b;"			\ 					: "=&r" (previous),		\ 					  "=&r" (r)			\ 					: "r"   (target),		\ 					  "r"   (delta)			\ 					: "memory", "cc");		\ 		return (previous);					\ 	}
end_define

begin_macro
name|CK_PR_FAA
argument_list|(
literal|64
argument_list|,
argument|uint64_t
argument_list|,
literal|"d"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_macro
name|CK_PR_FAA
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|"w"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|CK_PR_FAA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_PPC64_H */
end_comment

end_unit

