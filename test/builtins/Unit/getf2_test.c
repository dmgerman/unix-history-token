begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===------------ getf2_test.c - Test __getf2------------------------------===//
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
comment|// This file tests __getf2 for the compiler_rt library.
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

begin_if
if|#
directive|if
name|__LP64__
operator|&&
name|__LDBL_MANT_DIG__
operator|==
literal|113
end_if

begin_include
include|#
directive|include
file|"fp_test.h"
end_include

begin_function_decl
name|int
name|__getf2
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__getf2
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|,
name|enum
name|EXPECTED_RESULT
name|expected
parameter_list|)
block|{
name|int
name|x
init|=
name|__getf2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
name|int
name|ret
init|=
name|compareResultCMP
argument_list|(
name|x
argument_list|,
name|expected
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
name|printf
argument_list|(
literal|"error in test__getf2(%.20Lf, %.20Lf) = %d, "
literal|"expected %s\n"
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|x
argument_list|,
name|expectedStr
argument_list|(
name|expected
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function

begin_expr_stmt
name|char
name|assumption_1
index|[
expr|sizeof
operator|(
name|long
name|double
operator|)
operator|*
name|CHAR_BIT
operator|==
literal|128
expr|]
operator|=
block|{
literal|0
block|}
expr_stmt|;
end_expr_stmt

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
name|__LP64__
operator|&&
name|__LDBL_MANT_DIG__
operator|==
literal|113
comment|// NaN
if|if
condition|(
name|test__getf2
argument_list|(
name|makeQNaN128
argument_list|()
argument_list|,
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
name|LESS_0
argument_list|)
condition|)
return|return
literal|1
return|;
comment|//<
comment|// exp
if|if
condition|(
name|test__getf2
argument_list|(
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|-
literal|3L
argument_list|,
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
name|LESS_0
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// mantissa
if|if
condition|(
name|test__getf2
argument_list|(
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
literal|0x1
literal|.334567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
name|LESS_0
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// sign
if|if
condition|(
name|test__getf2
argument_list|(
operator|-
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
name|LESS_0
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// ==
if|if
condition|(
name|test__getf2
argument_list|(
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
name|GREATER_EQUAL_0
argument_list|)
condition|)
return|return
literal|1
return|;
comment|//>
comment|// exp
if|if
condition|(
name|test__getf2
argument_list|(
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|-
literal|3L
argument_list|,
name|GREATER_EQUAL_0
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// mantissa
if|if
condition|(
name|test__getf2
argument_list|(
literal|0x1
literal|.334567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
name|GREATER_EQUAL_0
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// sign
if|if
condition|(
name|test__getf2
argument_list|(
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
operator|-
literal|0x1
literal|.234567890abcdef1234567890abcp
operator|+
literal|3L
argument_list|,
name|GREATER_EQUAL_0
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

