begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES-ANY: arm-target-arch,armv6m-target-arch
end_comment

begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- aeabi_drsub.c - Test __aeabi_drsub --------------------------------===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file tests __aeabi_drsub for the compiler_rt library.
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_if
if|#
directive|if
name|__arm__
end_if

begin_extern
extern|extern __attribute__((pcs(
literal|"aapcs"
end_extern

begin_function_decl
unit|)))
name|double
name|__aeabi_drsub
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__aeabi_drsub
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|expected
parameter_list|)
block|{
name|double
name|actual
init|=
name|__aeabi_drsub
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
if|if
condition|(
name|actual
operator|!=
name|expected
condition|)
name|printf
argument_list|(
literal|"error in __aeabi_drsub(%f, %f) = %f, expected %f\n"
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|)
expr_stmt|;
return|return
name|actual
operator|!=
name|expected
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|()
block|{
if|#
directive|if
name|__arm__
if|if
condition|(
name|test__aeabi_drsub
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|0.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__aeabi_drsub
argument_list|(
literal|1234.567
argument_list|,
literal|765.4321
argument_list|,
operator|-
literal|469.134900
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__aeabi_drsub
argument_list|(
operator|-
literal|123.0
argument_list|,
operator|-
literal|678.0
argument_list|,
operator|-
literal|555.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__aeabi_drsub
argument_list|(
literal|0.0
argument_list|,
operator|-
literal|0.0
argument_list|,
literal|0.0
argument_list|)
condition|)
return|return
literal|1
return|;
else|#
directive|else
name|printf
argument_list|(
literal|"skipped\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

end_unit

