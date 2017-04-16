begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- fixsfsivfp_test.c - Test __fixsfsivfp -----------------------------===//
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
comment|// This file tests __fixsfsivfp for the compiler_rt library.
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

begin_function_decl
specifier|extern
name|int
name|__fixsfsivfp
parameter_list|(
name|float
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__arm__
operator|&&
name|__VFP_FP__
end_if

begin_function
name|int
name|test__fixsfsivfp
parameter_list|(
name|float
name|a
parameter_list|)
block|{
name|int
name|actual
init|=
name|__fixsfsivfp
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|int
name|expected
init|=
name|a
decl_stmt|;
if|if
condition|(
name|actual
operator|!=
name|expected
condition|)
name|printf
argument_list|(
literal|"error in test__fixsfsivfp(%f) = %u, expected %u\n"
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
operator|&&
name|__VFP_FP__
if|if
condition|(
name|test__fixsfsivfp
argument_list|(
literal|0.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__fixsfsivfp
argument_list|(
literal|1.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__fixsfsivfp
argument_list|(
operator|-
literal|1.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__fixsfsivfp
argument_list|(
literal|2147483647.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__fixsfsivfp
argument_list|(
operator|-
literal|2147483648.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__fixsfsivfp
argument_list|(
literal|65536.0
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

