begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- divsf3vfp_test.c - Test __divsf3vfp -------------------------------===//
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
comment|// This file tests __divsf3vfp for the compiler_rt library.
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
name|float
name|__divsf3vfp
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
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
name|test__divsf3vfp
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
name|float
name|actual
init|=
name|__divsf3vfp
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
name|float
name|expected
init|=
name|a
operator|/
name|b
decl_stmt|;
if|if
condition|(
name|actual
operator|!=
name|expected
condition|)
name|printf
argument_list|(
literal|"error in test__divsf3vfp(%f, %f) = %f, expected %f\n"
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
name|test__divsf3vfp
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__divsf3vfp
argument_list|(
literal|12345.678
argument_list|,
literal|1.23
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__divsf3vfp
argument_list|(
literal|0.0
argument_list|,
name|HUGE_VALF
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__divsf3vfp
argument_list|(
literal|10.0
argument_list|,
operator|-
literal|2.0
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

