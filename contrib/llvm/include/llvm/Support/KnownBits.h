begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/KnownBits.h - Stores known zeros/ones -------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
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
comment|// This file contains a class for representing known zeros and ones used by
end_comment

begin_comment
comment|// computeKnownBits.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_KNOWNBITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_KNOWNBITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Struct for tracking the known zeros and ones of a value.
struct|struct
name|KnownBits
block|{
name|APInt
name|Zero
decl_stmt|;
name|APInt
name|One
decl_stmt|;
name|private
label|:
comment|// Internal constructor for creating a ConstantRange from two APInts.
name|KnownBits
argument_list|(
argument|APInt Zero
argument_list|,
argument|APInt One
argument_list|)
block|:
name|Zero
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Zero
argument_list|)
argument_list|)
operator|,
name|One
argument_list|(
argument|std::move(One)
argument_list|)
block|{}
name|public
operator|:
comment|// Default construct Zero and One.
name|KnownBits
argument_list|()
block|{}
comment|/// Create a known bits object of BitWidth bits initialized to unknown.
name|KnownBits
argument_list|(
argument|unsigned BitWidth
argument_list|)
operator|:
name|Zero
argument_list|(
name|BitWidth
argument_list|,
literal|0
argument_list|)
operator|,
name|One
argument_list|(
argument|BitWidth
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// Get the bit width of this value.
name|unsigned
name|getBitWidth
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Zero
operator|.
name|getBitWidth
argument_list|()
operator|==
name|One
operator|.
name|getBitWidth
argument_list|()
operator|&&
literal|"Zero and One should have the same width!"
argument_list|)
block|;
return|return
name|Zero
operator|.
name|getBitWidth
argument_list|()
return|;
block|}
comment|/// Returns true if there is conflicting information.
name|bool
name|hasConflict
argument_list|()
specifier|const
block|{
return|return
name|Zero
operator|.
name|intersects
argument_list|(
name|One
argument_list|)
return|;
block|}
comment|/// Returns true if we know the value of all bits.
name|bool
name|isConstant
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|hasConflict
argument_list|()
operator|&&
literal|"KnownBits conflict!"
argument_list|)
block|;
return|return
name|Zero
operator|.
name|countPopulation
argument_list|()
operator|+
name|One
operator|.
name|countPopulation
argument_list|()
operator|==
name|getBitWidth
argument_list|()
return|;
block|}
comment|/// Returns the value when all bits have a known value. This just returns One
comment|/// with a protective assertion.
specifier|const
name|APInt
operator|&
name|getConstant
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isConstant
argument_list|()
operator|&&
literal|"Can only get value when all bits are known"
argument_list|)
block|;
return|return
name|One
return|;
block|}
comment|/// Returns true if we don't know any bits.
name|bool
name|isUnknown
argument_list|()
specifier|const
block|{
return|return
name|Zero
operator|.
name|isNullValue
argument_list|()
operator|&&
name|One
operator|.
name|isNullValue
argument_list|()
return|;
block|}
comment|/// Resets the known state of all bits.
name|void
name|resetAll
parameter_list|()
block|{
name|Zero
operator|.
name|clearAllBits
argument_list|()
expr_stmt|;
name|One
operator|.
name|clearAllBits
argument_list|()
expr_stmt|;
block|}
comment|/// Returns true if value is all zero.
name|bool
name|isZero
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|hasConflict
argument_list|()
operator|&&
literal|"KnownBits conflict!"
argument_list|)
block|;
return|return
name|Zero
operator|.
name|isAllOnesValue
argument_list|()
return|;
block|}
comment|/// Returns true if value is all one bits.
name|bool
name|isAllOnes
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|hasConflict
argument_list|()
operator|&&
literal|"KnownBits conflict!"
argument_list|)
block|;
return|return
name|One
operator|.
name|isAllOnesValue
argument_list|()
return|;
block|}
comment|/// Make all bits known to be zero and discard any previous information.
name|void
name|setAllZero
parameter_list|()
block|{
name|Zero
operator|.
name|setAllBits
argument_list|()
expr_stmt|;
name|One
operator|.
name|clearAllBits
argument_list|()
expr_stmt|;
block|}
comment|/// Make all bits known to be one and discard any previous information.
name|void
name|setAllOnes
parameter_list|()
block|{
name|Zero
operator|.
name|clearAllBits
argument_list|()
expr_stmt|;
name|One
operator|.
name|setAllBits
argument_list|()
expr_stmt|;
block|}
comment|/// Returns true if this value is known to be negative.
name|bool
name|isNegative
argument_list|()
specifier|const
block|{
return|return
name|One
operator|.
name|isSignBitSet
argument_list|()
return|;
block|}
comment|/// Returns true if this value is known to be non-negative.
name|bool
name|isNonNegative
argument_list|()
specifier|const
block|{
return|return
name|Zero
operator|.
name|isSignBitSet
argument_list|()
return|;
block|}
comment|/// Make this value negative.
name|void
name|makeNegative
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|isNonNegative
argument_list|()
operator|&&
literal|"Can't make a non-negative value negative"
argument_list|)
expr_stmt|;
name|One
operator|.
name|setSignBit
argument_list|()
expr_stmt|;
block|}
comment|/// Make this value negative.
name|void
name|makeNonNegative
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|isNegative
argument_list|()
operator|&&
literal|"Can't make a negative value non-negative"
argument_list|)
expr_stmt|;
name|Zero
operator|.
name|setSignBit
argument_list|()
expr_stmt|;
block|}
comment|/// Truncate the underlying known Zero and One bits. This is equivalent
comment|/// to truncating the value we're tracking.
name|KnownBits
name|trunc
parameter_list|(
name|unsigned
name|BitWidth
parameter_list|)
block|{
return|return
name|KnownBits
argument_list|(
name|Zero
operator|.
name|trunc
argument_list|(
name|BitWidth
argument_list|)
argument_list|,
name|One
operator|.
name|trunc
argument_list|(
name|BitWidth
argument_list|)
argument_list|)
return|;
block|}
comment|/// Zero extends the underlying known Zero and One bits. This is equivalent
comment|/// to zero extending the value we're tracking.
name|KnownBits
name|zext
parameter_list|(
name|unsigned
name|BitWidth
parameter_list|)
block|{
return|return
name|KnownBits
argument_list|(
name|Zero
operator|.
name|zext
argument_list|(
name|BitWidth
argument_list|)
argument_list|,
name|One
operator|.
name|zext
argument_list|(
name|BitWidth
argument_list|)
argument_list|)
return|;
block|}
comment|/// Sign extends the underlying known Zero and One bits. This is equivalent
comment|/// to sign extending the value we're tracking.
name|KnownBits
name|sext
parameter_list|(
name|unsigned
name|BitWidth
parameter_list|)
block|{
return|return
name|KnownBits
argument_list|(
name|Zero
operator|.
name|sext
argument_list|(
name|BitWidth
argument_list|)
argument_list|,
name|One
operator|.
name|sext
argument_list|(
name|BitWidth
argument_list|)
argument_list|)
return|;
block|}
comment|/// Zero extends or truncates the underlying known Zero and One bits. This is
comment|/// equivalent to zero extending or truncating the value we're tracking.
name|KnownBits
name|zextOrTrunc
parameter_list|(
name|unsigned
name|BitWidth
parameter_list|)
block|{
return|return
name|KnownBits
argument_list|(
name|Zero
operator|.
name|zextOrTrunc
argument_list|(
name|BitWidth
argument_list|)
argument_list|,
name|One
operator|.
name|zextOrTrunc
argument_list|(
name|BitWidth
argument_list|)
argument_list|)
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

