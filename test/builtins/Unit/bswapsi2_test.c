begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// UNSUPPORTED: armv6m-target-arch
end_comment

begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- bswapsi2_test.c - Test __bswapsi2 ---------------------------------===//
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
comment|// This file tests __bswapsi2 for the compiler_rt library.
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function_decl
specifier|extern
name|uint32_t
name|__bswapsi2
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__arm__
end_if

begin_function
name|int
name|test__bswapsi2
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|expected
parameter_list|)
block|{
name|uint32_t
name|actual
init|=
name|__bswapsi2
argument_list|(
name|a
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
literal|"error in test__bswapsi2(0x%0X) = 0x%0X, expected 0x%0X\n"
argument_list|,
name|a
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
name|test__bswapsi2
argument_list|(
literal|0x12345678
argument_list|,
literal|0x78563412
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__bswapsi2
argument_list|(
literal|0x00000001
argument_list|,
literal|0x01000000
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

