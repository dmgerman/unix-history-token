begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/floatsidf.c - integer -> double-precision conversion --*- C -*-===//
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
comment|// This file implements integer to double-precision conversion for the
end_comment

begin_comment
comment|// compiler-rt library in the IEEE-754 default round-to-nearest, ties-to-even
end_comment

begin_comment
comment|// mode.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|DOUBLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_function
name|fp_t
name|__floatsidf
parameter_list|(
name|int
name|a
parameter_list|)
block|{
specifier|const
name|int
name|aWidth
init|=
sizeof|sizeof
name|a
operator|*
name|CHAR_BIT
decl_stmt|;
comment|// Handle zero as a special case to protect clz
if|if
condition|(
name|a
operator|==
literal|0
condition|)
return|return
name|fromRep
argument_list|(
literal|0
argument_list|)
return|;
comment|// All other cases begin by extracting the sign and absolute value of a
name|rep_t
name|sign
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|sign
operator|=
name|signBit
expr_stmt|;
name|a
operator|=
operator|-
name|a
expr_stmt|;
block|}
comment|// Exponent of (fp_t)a is the width of abs(a).
specifier|const
name|int
name|exponent
init|=
operator|(
name|aWidth
operator|-
literal|1
operator|)
operator|-
name|__builtin_clz
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|rep_t
name|result
decl_stmt|;
comment|// Shift a into the significand field and clear the implicit bit.  Extra
comment|// cast to unsigned int is necessary to get the correct behavior for
comment|// the input INT_MIN.
specifier|const
name|int
name|shift
init|=
name|significandBits
operator|-
name|exponent
decl_stmt|;
name|result
operator|=
operator|(
name|rep_t
operator|)
operator|(
name|unsigned
name|int
operator|)
name|a
operator|<<
name|shift
operator|^
name|implicitBit
expr_stmt|;
comment|// Insert the exponent
name|result
operator|+=
call|(
name|rep_t
call|)
argument_list|(
name|exponent
operator|+
name|exponentBias
argument_list|)
operator|<<
name|significandBits
expr_stmt|;
comment|// Insert the sign bit and return
return|return
name|fromRep
argument_list|(
name|result
operator||
name|sign
argument_list|)
return|;
block|}
end_function

end_unit

