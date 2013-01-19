begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- int_lib.h - configuration header for compiler-rt  -----------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file is a configuration header for compiler-rt.  * This file is not part of the interface of this library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_LIB_H
end_ifndef

begin_define
define|#
directive|define
name|INT_LIB_H
end_define

begin_comment
comment|/* Assumption: Signed integral is 2's complement. */
end_comment

begin_comment
comment|/* Assumption: Right shift of signed negative is arithmetic shift. */
end_comment

begin_comment
comment|/* Assumption: Endianness is little or big (not mixed). */
end_comment

begin_comment
comment|/* ABI macro definitions */
end_comment

begin_if
if|#
directive|if
name|__ARM_EABI__
end_if

begin_define
define|#
directive|define
name|ARM_EABI_FNALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
define|\
value|void __aeabi_##aeabi_name() __attribute__((alias("__" #name)));
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
expr|\
operator|(
name|__GNUC__
operator|<
literal|4
operator|||
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
end_if

begin_comment
comment|/* The pcs attribute was introduced in GCC 4.5.0 */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
value|__attribute__((pcs("aapcs")))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_EABI_FNALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include the standard compiler builtin headers we use functionality from. */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_comment
comment|/* Include the commonly used internal type definitions. */
end_comment

begin_include
include|#
directive|include
file|"int_types.h"
end_include

begin_comment
comment|/* Include internal utility function declarations. */
end_comment

begin_include
include|#
directive|include
file|"int_util.h"
end_include

begin_comment
comment|/*  * Workaround for LLVM bug 11663.  Prevent endless recursion in  * __c?zdi2(), where calls to __builtin_c?z() are expanded to  * __c?zdi2() instead of __c?zsi2().  *  * Instead of placing this workaround in c?zdi2.c, put it in this  * global header to prevent other C files from making the detour  * through __c?zdi2() as well.  *  * This problem has only been observed on FreeBSD for sparc64 and  * mips64 with GCC 4.2.1.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__sparc64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o64
argument_list|)
operator|)
end_if

begin_function_decl
name|si_int
name|__clzsi2
parameter_list|(
name|si_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|si_int
name|__ctzsi2
parameter_list|(
name|si_int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|__builtin_clz
value|__clzsi2
end_define

begin_define
define|#
directive|define
name|__builtin_ctz
value|__ctzsi2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_LIB_H */
end_comment

end_unit

