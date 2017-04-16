begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- addvti3_test.c - Test __addvti3 -----------------------------------===//
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
comment|// This file tests __addvti3 for the compiler_rt library.
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

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
end_ifdef

begin_comment
comment|// Returns: a + b
end_comment

begin_comment
comment|// Effects: aborts if a + b overflows
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|ti_int
name|__addvti3
parameter_list|(
name|ti_int
name|a
parameter_list|,
name|ti_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__addvti3
parameter_list|(
name|ti_int
name|a
parameter_list|,
name|ti_int
name|b
parameter_list|)
block|{
name|ti_int
name|x
init|=
name|__addvti3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
name|ti_int
name|expected
init|=
name|a
operator|+
name|b
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
name|twords
name|bt
decl_stmt|;
name|bt
operator|.
name|all
operator|=
name|b
expr_stmt|;
name|twords
name|xt
decl_stmt|;
name|xt
operator|.
name|all
operator|=
name|x
expr_stmt|;
name|twords
name|expectedt
decl_stmt|;
name|expectedt
operator|.
name|all
operator|=
name|expected
expr_stmt|;
name|printf
argument_list|(
literal|"error in test__addvti3(0x%llX%.16llX, 0x%llX%.16llX) = "
literal|"0x%llX%.16llX, expected 0x%llX%.16llX\n"
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
name|bt
operator|.
name|s
operator|.
name|high
argument_list|,
name|bt
operator|.
name|s
operator|.
name|low
argument_list|,
name|xt
operator|.
name|s
operator|.
name|high
argument_list|,
name|xt
operator|.
name|s
operator|.
name|low
argument_list|,
name|expectedt
operator|.
name|s
operator|.
name|high
argument_list|,
name|expectedt
operator|.
name|s
operator|.
name|low
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
comment|// should abort
comment|//     test__addvti3(make_ti(0x8000000000000000LL, 0x0000000000000000LL),
comment|//                   make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFFFFFFFFFFLL));
comment|// should abort
comment|//     test__addvti3(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFFFFFFFFFFLL),
comment|//                   make_ti(0x8000000000000000LL, 0x0000000000000000LL));
comment|// should abort
comment|//     test__addvti3(make_ti(0x0000000000000000LL, 0x0000000000000001LL),
comment|//                   make_ti(0x7FFFFFFFFFFFFFFFLL, 0xFFFFFFFFFFFFFFFFLL));
comment|// should abort
comment|//     test__addvti3(make_ti(0x7FFFFFFFFFFFFFFFLL, 0xFFFFFFFFFFFFFFFFLL),
comment|//                   make_ti(0x0000000000000000LL, 0x0000000000000001LL));
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0x8000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0x0000000000000000LL
argument_list|,
literal|0x0000000000000001LL
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0x0000000000000000LL
argument_list|,
literal|0x0000000000000001LL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0x8000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0x8000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0x0000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0x0000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0x8000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0x7FFFFFFFFFFFFFFFLL
argument_list|,
literal|0xFFFFFFFFFFFFFFFFLL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0xFFFFFFFFFFFFFFFFLL
argument_list|,
literal|0xFFFFFFFFFFFFFFFFLL
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0xFFFFFFFFFFFFFFFFLL
argument_list|,
literal|0xFFFFFFFFFFFFFFFFLL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0x7FFFFFFFFFFFFFFFLL
argument_list|,
literal|0xFFFFFFFFFFFFFFFFLL
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0x7FFFFFFFFFFFFFFFLL
argument_list|,
literal|0xFFFFFFFFFFFFFFFFLL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0x0000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__addvti3
argument_list|(
name|make_ti
argument_list|(
literal|0x0000000000000000LL
argument_list|,
literal|0x0000000000000000LL
argument_list|)
argument_list|,
name|make_ti
argument_list|(
literal|0x7FFFFFFFFFFFFFFFLL
argument_list|,
literal|0xFFFFFFFFFFFFFFFFLL
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

