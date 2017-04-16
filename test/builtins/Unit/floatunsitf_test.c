begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===--------------- floatunsitf_test.c - Test __floatunsitf --------------===//
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
comment|// This file tests __floatunsitf for the compiler_rt library.
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
name|long
name|double
name|__floatunsitf
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__floatunsitf
parameter_list|(
name|unsigned
name|int
name|a
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
name|__floatunsitf
argument_list|(
name|a
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
literal|"error in test__floatunsitf(%u) = %.20Lf, "
literal|"expected %.20Lf\n"
argument_list|,
name|a
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
if|if
condition|(
name|test__floatunsitf
argument_list|(
literal|0x7fffffff
argument_list|,
name|UINT64_C
argument_list|(
literal|0x401dfffffffc0000
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
if|if
condition|(
name|test__floatunsitf
argument_list|(
literal|0
argument_list|,
name|UINT64_C
argument_list|(
literal|0x0
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
if|if
condition|(
name|test__floatunsitf
argument_list|(
literal|0xffffffff
argument_list|,
name|UINT64_C
argument_list|(
literal|0x401efffffffe0000
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
if|if
condition|(
name|test__floatunsitf
argument_list|(
literal|0x12345678
argument_list|,
name|UINT64_C
argument_list|(
literal|0x401b234567800000
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

