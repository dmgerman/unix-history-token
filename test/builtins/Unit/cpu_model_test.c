begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: XFAIL the test because it is expected to return non-zero value.
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// REQUIRES: x86-target-arch
end_comment

begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- cpu_model_test.c - Test __builtin_cpu_supports --------------------===//
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
comment|// This file tests __builtin_cpu_supports for the compiler_rt library.
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

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
if|if
condition|(
name|__builtin_cpu_supports
argument_list|(
literal|"avx2"
argument_list|)
condition|)
return|return
literal|4
return|;
else|else
return|return
literal|3
return|;
else|#
directive|else
name|printf
argument_list|(
literal|"skipped\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function

end_unit

