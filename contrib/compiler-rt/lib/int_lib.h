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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_LIB_H */
end_comment

end_unit

