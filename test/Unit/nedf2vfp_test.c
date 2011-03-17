begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- nedf2vfp_test.c - Test __nedf2vfp ---------------------------------===//
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
comment|// This file tests __nedf2vfp for the compiler_rt library.
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
name|int
name|__nedf2vfp
parameter_list|(
name|double
name|a
parameter_list|,
name|double
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
name|test__nedf2vfp
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
name|int
name|actual
init|=
name|__nedf2vfp
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
name|int
name|expected
init|=
operator|(
name|a
operator|!=
name|b
operator|)
condition|?
literal|1
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|actual
operator|!=
name|expected
condition|)
name|printf
argument_list|(
literal|"error in __nedf2vfp(%f, %f) = %d, expected %d\n"
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
name|test__nedf2vfp
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__nedf2vfp
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
name|test__nedf2vfp
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__nedf2vfp
argument_list|(
name|HUGE_VAL
argument_list|,
literal|1.0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__nedf2vfp
argument_list|(
literal|1.0
argument_list|,
name|HUGE_VAL
argument_list|)
condition|)
return|return
literal|1
return|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

end_unit

