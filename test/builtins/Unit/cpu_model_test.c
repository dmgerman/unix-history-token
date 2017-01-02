begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- cpu_model_test.c - Test __builtin_cpu_supports -------------------------------===//
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

begin_comment
comment|// REQUIRES: x86-target-arch
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
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
block|}
end_function

end_unit

