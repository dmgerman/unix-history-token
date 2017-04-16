begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===--------------- addtf3_test.c - Test __addtf3 ------------------------===//
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
comment|// This file tests __addtf3 for the compiler_rt library.
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

begin_comment
comment|// Returns: a + b
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|long
name|double
name|__addtf3
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
name|test__addtf3
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|,
name|uint64_t
name|expectedHi
parameter_list|,
name|uint64_t
name|expectedLo
parameter_list|)
block|{
name|long
name|double
name|x
init|=
name|__addtf3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
name|int
name|ret
init|=
name|compareResultLD
argument_list|(
name|x
argument_list|,
name|expectedHi
argument_list|,
name|expectedLo
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
name|printf
argument_list|(
literal|"error in test__addtf3(%.20Lf, %.20Lf) = %.20Lf, "
literal|"expected %.20Lf\n"
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|x
argument_list|,
name|fromRep128
argument_list|(
name|expectedHi
argument_list|,
name|expectedLo
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
comment|// qNaN + any = qNaN
if|if
condition|(
name|test__addtf3
argument_list|(
name|makeQNaN128
argument_list|()
argument_list|,
literal|0x1
literal|.23456789abcdefp
operator|+
literal|5L
argument_list|,
name|UINT64_C
argument_list|(
literal|0x7fff800000000000
argument_list|)
argument_list|,
name|UINT64_C
argument_list|(
literal|0x0
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// NaN + any = NaN
if|if
condition|(
name|test__addtf3
argument_list|(
name|makeNaN128
argument_list|(
name|UINT64_C
argument_list|(
literal|0x800030000000
argument_list|)
argument_list|)
argument_list|,
literal|0x1
literal|.23456789abcdefp
operator|+
literal|5L
argument_list|,
name|UINT64_C
argument_list|(
literal|0x7fff800000000000
argument_list|)
argument_list|,
name|UINT64_C
argument_list|(
literal|0x0
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// inf + inf = inf
if|if
condition|(
name|test__addtf3
argument_list|(
name|makeInf128
argument_list|()
argument_list|,
name|makeInf128
argument_list|()
argument_list|,
name|UINT64_C
argument_list|(
literal|0x7fff000000000000
argument_list|)
argument_list|,
name|UINT64_C
argument_list|(
literal|0x0
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// inf + any = inf
if|if
condition|(
name|test__addtf3
argument_list|(
name|makeInf128
argument_list|()
argument_list|,
literal|0x1
literal|.2335653452436234723489432abcdefp
operator|+
literal|5L
argument_list|,
name|UINT64_C
argument_list|(
literal|0x7fff000000000000
argument_list|)
argument_list|,
name|UINT64_C
argument_list|(
literal|0x0
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// any + any
if|if
condition|(
name|test__addtf3
argument_list|(
literal|0x1
literal|.23456734245345543849abcdefp
operator|+
literal|5L
argument_list|,
literal|0x1
operator|.
name|edcba52449872455634654321fp
operator|-
literal|1L
argument_list|,
name|UINT64_C
argument_list|(
literal|0x40042afc95c8b579
argument_list|)
argument_list|,
name|UINT64_C
argument_list|(
literal|0x61e58dd6c51eb77c
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

