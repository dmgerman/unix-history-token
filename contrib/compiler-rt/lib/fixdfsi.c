begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/fixdfsi.c - Double-precision -> integer conversion ----*- C -*-===//
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
comment|// This file implements double-precision to integer conversion for the
end_comment

begin_comment
comment|// compiler-rt library.  No range checking is performed; the behavior of this
end_comment

begin_comment
comment|// conversion is undefined for out of range values in the C standard.
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

begin_macro
name|ARM_EABI_FNALIAS
argument_list|(
argument|d2iz
argument_list|,
argument|fixdfsi
argument_list|)
end_macro

begin_function
name|int
name|__fixdfsi
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
comment|// Break a into sign, exponent, significand
specifier|const
name|rep_t
name|aRep
init|=
name|toRep
argument_list|(
name|a
argument_list|)
decl_stmt|;
specifier|const
name|rep_t
name|aAbs
init|=
name|aRep
operator|&
name|absMask
decl_stmt|;
specifier|const
name|int
name|sign
init|=
name|aRep
operator|&
name|signBit
condition|?
operator|-
literal|1
else|:
literal|1
decl_stmt|;
specifier|const
name|int
name|exponent
init|=
operator|(
name|aAbs
operator|>>
name|significandBits
operator|)
operator|-
name|exponentBias
decl_stmt|;
specifier|const
name|rep_t
name|significand
init|=
operator|(
name|aAbs
operator|&
name|significandMask
operator|)
operator||
name|implicitBit
decl_stmt|;
comment|// If 0< exponent< significandBits, right shift to get the result.
if|if
condition|(
operator|(
name|unsigned
name|int
operator|)
name|exponent
operator|<
name|significandBits
condition|)
block|{
return|return
name|sign
operator|*
operator|(
name|significand
operator|>>
operator|(
name|significandBits
operator|-
name|exponent
operator|)
operator|)
return|;
block|}
comment|// If exponent is negative, the result is zero.
elseif|else
if|if
condition|(
name|exponent
operator|<
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
comment|// If significandBits< exponent, left shift to get the result.  This shift
comment|// may end up being larger than the type width, which incurs undefined
comment|// behavior, but the conversion itself is undefined in that case, so
comment|// whatever the compiler decides to do is fine.
else|else
block|{
return|return
name|sign
operator|*
operator|(
name|significand
operator|<<
operator|(
name|exponent
operator|-
name|significandBits
operator|)
operator|)
return|;
block|}
block|}
end_function

end_unit

