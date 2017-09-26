begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/floatunsidf.c - uint -> double-precision conversion ---*- C -*-===//
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
comment|// This file implements unsigned integer to double-precision conversion for the
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

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__floatunsidf
parameter_list|(
name|unsigned
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
comment|// Shift a into the significand field and clear the implicit bit.
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
return|return
name|fromRep
argument_list|(
name|result
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_function
name|AEABI_RTABI
name|fp_t
name|__aeabi_ui2d
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
return|return
name|__floatunsidf
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

