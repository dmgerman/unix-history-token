begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/arm/aeabi_cfcmpeq_helper.c - Helper for cdcmpeq ---------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_macro
name|__attribute__
argument_list|(
argument|(pcs(
literal|"aapcs"
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(visibility(
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_function
name|int
name|__aeabi_cfcmpeq_check_nan
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
return|return
name|__builtin_isnan
argument_list|(
name|a
argument_list|)
operator|||
name|__builtin_isnan
argument_list|(
name|b
argument_list|)
return|;
block|}
end_function

end_unit

