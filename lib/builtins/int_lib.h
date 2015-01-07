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

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
value|__attribute__((pcs("aapcs")))
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
operator|)
end_if

begin_comment
comment|/*  * Kernel and boot environment can't use normal headers,  * so use the equivalent system headers.  */
end_comment

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__paritysi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__paritydi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|di_int
name|__divdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__divsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|su_int
name|__udivsi3
parameter_list|(
name|su_int
name|n
parameter_list|,
name|su_int
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|su_int
name|__udivmodsi4
parameter_list|(
name|su_int
name|a
parameter_list|,
name|su_int
name|b
parameter_list|,
name|su_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|du_int
name|__udivmoddi4
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|,
name|du_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
end_ifdef

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__clzti2
parameter_list|(
name|ti_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|tu_int
name|__udivmodti4
parameter_list|(
name|tu_int
name|a
parameter_list|,
name|tu_int
name|b
parameter_list|,
name|tu_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

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

