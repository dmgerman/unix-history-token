begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===--------------- trunctfsf2_test.c - Test __trunctfsf2 ----------------===//
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
comment|// This file tests __trunctfsf2 for the compiler_rt library.
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
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
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
name|COMPILER_RT_ABI
name|float
name|__trunctfsf2
parameter_list|(
name|long
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__trunctfsf2
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|uint32_t
name|expected
parameter_list|)
block|{
name|float
name|x
init|=
name|__trunctfsf2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|int
name|ret
init|=
name|compareResultF
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
literal|"error in test__trunctfsf2(%.20Lf) = %f, "
literal|"expected %f\n"
argument_list|,
name|a
argument_list|,
name|x
argument_list|,
name|fromRep32
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
name|__LDBL_MANT_DIG__
operator|==
literal|113
comment|// qNaN
if|if
condition|(
name|test__trunctfsf2
argument_list|(
name|makeQNaN128
argument_list|()
argument_list|,
name|UINT32_C
argument_list|(
literal|0x7fc00000
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// NaN
if|if
condition|(
name|test__trunctfsf2
argument_list|(
name|makeNaN128
argument_list|(
name|UINT64_C
argument_list|(
literal|0x810000000000
argument_list|)
argument_list|)
argument_list|,
name|UINT32_C
argument_list|(
literal|0x7fc08000
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// inf
if|if
condition|(
name|test__trunctfsf2
argument_list|(
name|makeInf128
argument_list|()
argument_list|,
name|UINT32_C
argument_list|(
literal|0x7f800000
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// zero
if|if
condition|(
name|test__trunctfsf2
argument_list|(
literal|0.0L
argument_list|,
name|UINT32_C
argument_list|(
literal|0x0
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__trunctfsf2
argument_list|(
literal|0x1
literal|.23a2abb4a2ddee355f36789abcdep
operator|+
literal|5L
argument_list|,
name|UINT32_C
argument_list|(
literal|0x4211d156
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__trunctfsf2
argument_list|(
literal|0x1
operator|.
name|e3d3c45bd3abfd98b76a54cc321fp
operator|-
literal|9L
argument_list|,
name|UINT32_C
argument_list|(
literal|0x3b71e9e2
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__trunctfsf2
argument_list|(
literal|0x1
literal|.234eebb5faa678f4488693abcdefp
operator|+
literal|4534L
argument_list|,
name|UINT32_C
argument_list|(
literal|0x7f800000
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__trunctfsf2
argument_list|(
literal|0x1
operator|.
name|edcba9bb8c76a5a43dd21f334634p
operator|-
literal|435L
argument_list|,
name|UINT32_C
argument_list|(
literal|0x0
argument_list|)
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

