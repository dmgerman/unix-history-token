begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// UNSUPPORTED: armv6m-target-arch
end_comment

begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- bswapdi2_test.c - Test __bswapdi2 ---------------------------------===//
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
comment|// This file tests __bswapdi2 for the compiler_rt library.
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
name|uint64_t
name|__bswapdi2
parameter_list|(
name|uint64_t
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
name|test__bswapdi2
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|expected
parameter_list|)
block|{
name|uint64_t
name|actual
init|=
name|__bswapdi2
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
literal|"error in test__bswapsi2(0x%0llX) = 0x%0llX, expected 0x%0llX\n"
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
name|test__bswapdi2
argument_list|(
literal|0x123456789ABCDEF0LL
argument_list|,
literal|0xF0DEBC9A78563412LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__bswapdi2
argument_list|(
literal|0x0000000100000002LL
argument_list|,
literal|0x0200000001000000LL
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

