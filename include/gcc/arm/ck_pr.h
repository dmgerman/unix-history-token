begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * Copyright 2013-2015 Olivier Houchard.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CK_ISB
value|__asm __volatile("isb" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|CK_DMB
value|__asm __volatile("dmb" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|CK_DSB
value|__asm __volatile("dsb" : : "r" (0) : "memory")
end_define

begin_comment
comment|/* FreeBSD's toolchain doesn't accept dmb st, so use the opcode instead */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|CK_DMB_ST
value|__asm __volatile(".word 0xf57ff05e" : : "r" (0) : "memory")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CK_DMB_ST
value|__asm __volatile("dmb st" : : "r" (0) : "memory")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* armv6 doesn't have dsb/dmb/isb, and no way to wait only for stores */
end_comment

begin_define
define|#
directive|define
name|CK_ISB
define|\
value|__asm __volatile("mcr p15, 0, %0, c7, c5, 4" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|CK_DSB
define|\
value|__asm __volatile("mcr p15, 0, %0, c7, c10, 4" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|CK_DMB
define|\
value|__asm __volatile("mcr p15, 0, %0, c7, c10, 5" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|CK_DMB_ST
value|CK_DMB
end_define

begin_endif
endif|#
directive|endif
end_endif

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
argument|CK_DMB_ST
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
argument|CK_DMB
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
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load
argument_list|,
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|load_store
argument_list|,
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|memory
argument_list|,
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acquire
argument_list|,
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|release
argument_list|,
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|acqrel
argument_list|,
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|lock
argument_list|,
argument|CK_DMB
argument_list|)
end_macro

begin_macro
name|CK_PR_FENCE
argument_list|(
argument|unlock
argument_list|,
argument|CK_DMB
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
name|CK_ISB
end_undef

begin_undef
undef|#
directive|undef
name|CK_DSB
end_undef

begin_undef
undef|#
directive|undef
name|CK_DMB
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CK_PR_DOUBLE_LOAD
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
define|\
value|CK_CC_INLINE static T				\ ck_pr_md_load_##N(const T *target)		\ {						\ 	register T ret;				\ 						\ 	__asm __volatile("ldrexd %0, [%1]" 	\ 	    : "=&r" (ret)			\ 	    : "r" (target)			\ 	    : "memory", "cc");			\ 	return (ret);				\ }
end_define

begin_macro
name|CK_PR_DOUBLE_LOAD
argument_list|(
argument|uint64_t
argument_list|,
literal|64
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_DOUBLE_LOAD
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

begin_undef
undef|#
directive|undef
name|CK_PR_DOUBLE_LOAD
end_undef

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_if

begin_define
define|#
directive|define
name|CK_PR_DOUBLE_STORE
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
define|\
value|CK_CC_INLINE static void					\ ck_pr_md_store_##N(const T *target, T value)			\ {								\ 	T tmp;							\ 	uint32_t flag;						\ 	__asm __volatile("1: 		\n"			\ 	    		 "ldrexd	%0, [%2]\n"		\ 			 "strexd	%1, %3, [%2]\n"		\ 			 "teq		%1, #0\n"		\ 			 "it ne		\n"			\ 			 "bne		1b\n"			\ 				: "=&r" (tmp), "=&r" (flag)	\ 				: "r" (target), "r" (value)	\ 				: "memory", "cc");		\ }
end_define

begin_macro
name|CK_PR_DOUBLE_STORE
argument_list|(
argument|uint64_t
argument_list|,
literal|64
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_DOUBLE_STORE
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

begin_undef
undef|#
directive|undef
name|CK_PR_DOUBLE_STORE
end_undef

begin_define
define|#
directive|define
name|CK_PR_DOUBLE_CAS_VALUE
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ ck_pr_cas_##N##_value(T *target, T compare, T set, T *value)	\ {								\         T previous;						\         int tmp;						\ 								\ 	__asm__ __volatile__("1:"				\ 			     "ldrexd %0, [%4];"			\ 			     "cmp    %Q0, %Q2;"			\ 			     "ittt eq;"				\ 			     "cmpeq  %R0, %R2;"			\ 			     "strexdeq %1, %3, [%4];"		\ 			     "cmpeq  %1, #1;"			\ 			     "beq 1b;"				\ 				:"=&r" (previous), "=&r" (tmp)	\ 				: "r" (compare), "r" (set) ,	\ 				  "r"(target)			\ 				: "memory", "cc");		\         *value = previous;					\ 	return (*value == compare);				\ }
end_define

begin_macro
name|CK_PR_DOUBLE_CAS_VALUE
argument_list|(
argument|uint64_t
argument_list|,
literal|64
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_DOUBLE_CAS_VALUE
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

begin_undef
undef|#
directive|undef
name|CK_PR_DOUBLE_CAS_VALUE
end_undef

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_ptr_2_value
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
name|uint32_t
modifier|*
name|_compare
init|=
name|CK_CPP_CAST
argument_list|(
name|uint32_t
operator|*
argument_list|,
name|compare
argument_list|)
decl_stmt|;
name|uint32_t
modifier|*
name|_set
init|=
name|CK_CPP_CAST
argument_list|(
name|uint32_t
operator|*
argument_list|,
name|set
argument_list|)
decl_stmt|;
name|uint64_t
name|__compare
init|=
operator|(
operator|(
name|uint64_t
operator|)
name|_compare
index|[
literal|0
index|]
operator|)
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|_compare
index|[
literal|1
index|]
operator|<<
literal|32
operator|)
decl_stmt|;
name|uint64_t
name|__set
init|=
operator|(
operator|(
name|uint64_t
operator|)
name|_set
index|[
literal|0
index|]
operator|)
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|_set
index|[
literal|1
index|]
operator|<<
literal|32
operator|)
decl_stmt|;
return|return
operator|(
name|ck_pr_cas_64_value
argument_list|(
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|target
argument_list|)
argument_list|,
name|__compare
argument_list|,
name|__set
argument_list|,
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|value
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CK_PR_DOUBLE_CAS
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
define|\
value|CK_CC_INLINE static bool			\ ck_pr_cas_##N(T *target, T compare, T set)	\ {						\ 	int ret;				\         T tmp;					\ 						\ 	__asm__ __volatile__("1:"		\ 			     "mov %0, #0;"	\ 			     "ldrexd %1, [%4];"	\ 			     "cmp    %Q1, %Q2;"	\ 			     "itttt eq;"	\ 			     "cmpeq  %R1, %R2;"	\ 			     "strexdeq %1, %3, [%4];" \ 			     "moveq %0, #1;"	\ 			     "cmpeq  %1, #1;"	\ 			     "beq 1b;"		\ 			     : "=&r" (ret), "=&r" (tmp) \ 			     : "r" (compare), "r" (set) , \ 			       "r"(target)	\ 			     : "memory", "cc");	\ 						\ 	return (ret);				\ }
end_define

begin_macro
name|CK_PR_DOUBLE_CAS
argument_list|(
argument|uint64_t
argument_list|,
literal|64
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PR_DISABLE_DOUBLE
end_ifndef

begin_macro
name|CK_PR_DOUBLE_CAS
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

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_pr_cas_ptr_2
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
name|uint32_t
modifier|*
name|_compare
init|=
name|CK_CPP_CAST
argument_list|(
name|uint32_t
operator|*
argument_list|,
name|compare
argument_list|)
decl_stmt|;
name|uint32_t
modifier|*
name|_set
init|=
name|CK_CPP_CAST
argument_list|(
name|uint32_t
operator|*
argument_list|,
name|set
argument_list|)
decl_stmt|;
name|uint64_t
name|__compare
init|=
operator|(
operator|(
name|uint64_t
operator|)
name|_compare
index|[
literal|0
index|]
operator|)
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|_compare
index|[
literal|1
index|]
operator|<<
literal|32
operator|)
decl_stmt|;
name|uint64_t
name|__set
init|=
operator|(
operator|(
name|uint64_t
operator|)
name|_set
index|[
literal|0
index|]
operator|)
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|_set
index|[
literal|1
index|]
operator|<<
literal|32
operator|)
decl_stmt|;
return|return
operator|(
name|ck_pr_cas_64
argument_list|(
name|CK_CPP_CAST
argument_list|(
name|uint64_t
operator|*
argument_list|,
name|target
argument_list|)
argument_list|,
name|__compare
argument_list|,
name|__set
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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
decl_stmt|,
modifier|*
name|tmp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldrex %0, [%2];" 			     "cmp   %0, %4;" 			     "itt eq;" 			     "strexeq %1, %3, [%2];" 			     "cmpeq   %1, #1;" 			     "beq   1b;" 			  	: "=&r" (previous), 				  "=&r" (tmp) 		  		: "r"   (target), 				  "r"   (set), 				  "r"   (compare) 				: "memory", "cc");
operator|*
operator|(
name|void
operator|*
operator|*
operator|)
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
decl_stmt|,
modifier|*
name|tmp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldrex %0, [%2];" 			     "cmp   %0, %4;" 			     "itt eq;" 			     "strexeq %1, %3, [%2];" 			     "cmpeq   %1, #1;" 			     "beq   1b;" 			  	: "=&r" (previous), 				  "=&r" (tmp) 		  		: "r"   (target), 				  "r"   (set), 				  "r"   (compare) 				: "memory", "cc");
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
parameter_list|,
name|W
parameter_list|)
define|\
value|CK_CC_INLINE static bool					\ 	ck_pr_cas_##N##_value(T *target, T compare, T set, T *value)	\ 	{								\ 		T previous = 0, tmp = 0;				\ 		__asm__ __volatile__("1:"				\ 				     "ldrex" W " %0, [%2];"		\ 				     "cmp   %0, %4;"			\ 				     "itt eq;"				\ 				     "strex" W "eq %1, %3, [%2];"	\ 		    		     "cmpeq   %1, #1;"			\ 				     "beq   1b;"			\
comment|/* 						\ 			 * Using "+&" instead of "=&" to avoid bogus	\ 			 * clang warnings.				\ 			 */
value|\ 					: "+&r" (previous),		\ 		    			  "+&r" (tmp)			\ 					: "r"   (target),		\ 					  "r"   (set),			\ 					  "r"   (compare)		\ 					: "memory", "cc");		\ 		*value = previous; 					\ 		return (previous == compare);				\ 	}								\ 	CK_CC_INLINE static bool					\ 	ck_pr_cas_##N(T *target, T compare, T set)			\ 	{								\ 		T previous = 0, tmp = 0;				\ 		__asm__ __volatile__("1:"				\ 				     "ldrex" W " %0, [%2];"		\ 				     "cmp   %0, %4;"			\ 				     "itt eq;"				\ 				     "strex" W "eq %1, %3, [%2];"	\ 				     "cmpeq   %1, #1;"			\ 				     "beq   1b;"			\ 					: "+&r" (previous),		\ 		    			  "+&r" (tmp)			\ 					: "r"   (target),		\ 					  "r"   (set),			\ 					  "r"   (compare)		\ 					: "memory", "cc");		\ 		return (previous == compare);				\ 	}
end_define

begin_macro
name|CK_PR_CAS
argument_list|(
literal|32
argument_list|,
argument|uint32_t
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
argument_list|(
literal|16
argument_list|,
argument|uint16_t
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
argument_list|(
literal|8
argument_list|,
argument|uint8_t
argument_list|,
literal|"b"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
argument_list|(
argument|short
argument_list|,
argument|short
argument_list|,
literal|"h"
argument_list|)
end_macro

begin_macro
name|CK_PR_CAS
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
value|CK_CC_INLINE static T					\ 	ck_pr_fas_##N(M *target, T v)				\ 	{							\ 		T previous = 0;					\ 		T tmp = 0;					\ 		__asm__ __volatile__("1:"			\ 				     "ldrex" W " %0, [%2];"	\ 				     "strex" W " %1, %3, [%2];"	\ 		    		     "cmp %1, #0;"		\ 				     "bne 1b;"			\ 					: "+&r" (previous),	\ 		    			  "+&r" (tmp) 		\ 					: "r"   (target),	\ 					  "r"   (v)		\ 					: "memory", "cc");	\ 		return (previous);				\ 	}
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
value|CK_CC_INLINE static void				\ 	ck_pr_##O##_##N(M *target)				\ 	{							\ 		T previous = 0;					\ 		T tmp = 0;					\ 		__asm__ __volatile__("1:"			\ 				     "ldrex" W " %0, [%2];"	\ 				      I ";"			\ 				     "strex" W " %1, %0, [%2];"	\ 		    		     "cmp   %1, #0;"		\ 				     "bne   1b;"		\ 					: "+&r" (previous),	\ 		    			  "+&r" (tmp)		\ 					: "r"   (target)	\ 					: "memory", "cc");	\ 		return;						\ 	}
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
literal|"add %0, %0, #1"
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
literal|"sub %0, %0, #1"
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
literal|"mvn %0, %0"
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
literal|"neg %0, %0"
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
value|CK_PR_UNARY(inc, S, T, T, "add %0, %0, #1", W)		\ 	CK_PR_UNARY(dec, S, T, T, "sub %0, %0, #1", W)		\ 	CK_PR_UNARY(not, S, T, T, "mvn %0, %0", W)		\ 	CK_PR_UNARY(neg, S, T, T, "neg %0, %0", W)		\  CK_PR_UNARY_S(32, uint32_t, "")
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
value|CK_CC_INLINE static void				\ 	ck_pr_##O##_##N(M *target, T delta)			\ 	{							\ 		T previous = 0;					\ 		T tmp = 0;					\ 		__asm__ __volatile__("1:"			\ 				     "ldrex" W " %0, [%2];"	\ 				      I " %0, %0, %3;"		\ 				     "strex" W " %1, %0, [%2];"	\ 		    		     "cmp %1, #0;"		\ 				     "bne 1b;"			\ 					: "+&r" (previous),	\ 		    			  "+&r" (tmp)		\ 					: "r"   (target),	\ 					  "r"   (delta)		\ 					: "memory", "cc");	\ 		return;						\ 	}
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
literal|"add"
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
literal|"orr"
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
literal|"sub"
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
literal|"eor"
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
value|CK_PR_BINARY(and, S, T, T, "and", W)	\ 	CK_PR_BINARY(add, S, T, T, "add", W)	\ 	CK_PR_BINARY(or, S, T, T, "orr", W)	\ 	CK_PR_BINARY(sub, S, T, T, "sub", W)	\ 	CK_PR_BINARY(xor, S, T, T, "eor", W)
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
decl_stmt|,
name|r
decl_stmt|,
name|tmp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:" 			     "ldrex %0, [%3];" 			     "add %1, %4, %0;" 			     "strex %2, %1, [%3];" 			     "cmp %2, #0;" 			     "bne  1b;" 				: "=&r" (previous), 				  "=&r" (r), 				  "=&r" (tmp) 				: "r"   (target), 				  "r"   (delta) 				: "memory", "cc");
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
value|CK_CC_INLINE static T						\ 	ck_pr_faa_##S(T *target, T delta)				\ 	{								\ 		T previous = 0, r = 0, tmp = 0;				\ 		__asm__ __volatile__("1:"				\ 				     "ldrex" W " %0, [%3];"		\ 				     "add %1, %4, %0;"			\ 				     "strex" W " %2, %1, [%3];"		\ 		    		     "cmp %2, #0;"			\ 				     "bne  1b;"				\ 					: "+&r" (previous),		\ 					  "+&r" (r),			\ 		    			  "+&r" (tmp)			\ 					: "r"   (target),		\ 					  "r"   (delta)			\ 					: "memory", "cc");		\ 		return (previous);					\ 	}
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PR_ARM_H */
end_comment

end_unit

