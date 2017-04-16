begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- parityti2_test.c - Test __parityti2 -------------------------------===//
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
comment|// This file tests __parityti2 for the compiler_rt library.
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

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
end_ifdef

begin_comment
comment|// Returns: 1 if number of bits is odd else returns 0
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__parityti2
parameter_list|(
name|ti_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|naive_parity
parameter_list|(
name|ti_int
name|a
parameter_list|)
block|{
name|int
name|r
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|a
condition|;
name|a
operator|=
name|a
operator|&
operator|(
name|a
operator|-
literal|1
operator|)
control|)
name|r
operator|=
operator|~
name|r
expr_stmt|;
return|return
name|r
operator|&
literal|1
return|;
block|}
end_function

begin_function
name|int
name|test__parityti2
parameter_list|(
name|ti_int
name|a
parameter_list|)
block|{
name|si_int
name|x
init|=
name|__parityti2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|si_int
name|expected
init|=
name|naive_parity
argument_list|(
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|x
operator|!=
name|expected
condition|)
block|{
name|twords
name|at
decl_stmt|;
name|at
operator|.
name|all
operator|=
name|a
expr_stmt|;
name|printf
argument_list|(
literal|"error in __parityti2(0x%.16llX%.16llX) = %d, expected %d\n"
argument_list|,
name|at
operator|.
name|s
operator|.
name|high
argument_list|,
name|at
operator|.
name|s
operator|.
name|low
argument_list|,
name|x
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
return|return
name|x
operator|!=
name|expected
return|;
block|}
end_function

begin_decl_stmt
name|char
name|assumption_1
index|[
sizeof|sizeof
argument_list|(
name|ti_int
argument_list|)
operator|==
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|di_int
argument_list|)
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|assumption_2
index|[
sizeof|sizeof
argument_list|(
name|di_int
argument_list|)
operator|*
name|CHAR_BIT
operator|==
literal|64
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|test__parityti2
argument_list|(
operator|(
operator|(
name|ti_int
operator|)
name|rand
argument_list|()
operator|<<
literal|96
operator|)
operator|+
operator|(
operator|(
name|ti_int
operator|)
name|rand
argument_list|()
operator|<<
literal|64
operator|)
operator|+
operator|(
operator|(
name|ti_int
operator|)
name|rand
argument_list|()
operator|<<
literal|32
operator|)
operator|+
name|rand
argument_list|()
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

