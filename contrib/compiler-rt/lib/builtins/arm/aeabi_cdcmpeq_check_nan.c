begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/arm/aeabi_cdcmpeq_helper.c - Helper for cdcmpeq ---------------===//
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

begin_include
include|#
directive|include
file|"../int_lib.h"
end_include

begin_decl_stmt
name|AEABI_RTABI
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
name|int
name|__aeabi_cdcmpeq_check_nan
argument_list|(
name|double
name|a
argument_list|,
name|double
name|b
argument_list|)
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
end_decl_stmt

end_unit

