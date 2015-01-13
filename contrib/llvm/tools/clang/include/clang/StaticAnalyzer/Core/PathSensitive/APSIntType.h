begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== APSIntType.h - Simple record of the type of APSInts --------*- C++ -*--==//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SA_CORE_APSINTTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SA_CORE_APSINTTYPE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// \brief A record of the "type" of an APSInt, used for conversions.
name|class
name|APSIntType
block|{
name|uint32_t
name|BitWidth
decl_stmt|;
name|bool
name|IsUnsigned
decl_stmt|;
name|public
label|:
name|APSIntType
argument_list|(
argument|uint32_t Width
argument_list|,
argument|bool Unsigned
argument_list|)
block|:
name|BitWidth
argument_list|(
name|Width
argument_list|)
operator|,
name|IsUnsigned
argument_list|(
argument|Unsigned
argument_list|)
block|{}
comment|/* implicit */
name|APSIntType
argument_list|(
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|Value
argument_list|)
operator|:
name|BitWidth
argument_list|(
name|Value
operator|.
name|getBitWidth
argument_list|()
argument_list|)
operator|,
name|IsUnsigned
argument_list|(
argument|Value.isUnsigned()
argument_list|)
block|{}
name|uint32_t
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
return|;
block|}
name|bool
name|isUnsigned
argument_list|()
specifier|const
block|{
return|return
name|IsUnsigned
return|;
block|}
comment|/// \brief Convert a given APSInt, in place, to match this type.
comment|///
comment|/// This behaves like a C cast: converting 255u8 (0xFF) to s16 gives
comment|/// 255 (0x00FF), and converting -1s8 (0xFF) to u16 gives 65535 (0xFFFF).
name|void
name|apply
argument_list|(
name|llvm
operator|::
name|APSInt
operator|&
name|Value
argument_list|)
decl|const
block|{
comment|// Note the order here. We extend first to preserve the sign, if this value
comment|// is signed, /then/ match the signedness of the result type.
name|Value
operator|=
name|Value
operator|.
name|extOrTrunc
argument_list|(
name|BitWidth
argument_list|)
expr_stmt|;
name|Value
operator|.
name|setIsUnsigned
argument_list|(
name|IsUnsigned
argument_list|)
expr_stmt|;
block|}
comment|/// Convert and return a new APSInt with the given value, but this
comment|/// type's bit width and signedness.
comment|///
comment|/// \see apply
name|llvm
operator|::
name|APSInt
name|convert
argument_list|(
argument|const llvm::APSInt&Value
argument_list|)
specifier|const
name|LLVM_READONLY
block|{
name|llvm
operator|::
name|APSInt
name|Result
argument_list|(
name|Value
argument_list|,
name|Value
operator|.
name|isUnsigned
argument_list|()
argument_list|)
block|;
name|apply
argument_list|(
name|Result
argument_list|)
block|;
return|return
name|Result
return|;
block|}
comment|/// Returns an all-zero value for this type.
name|llvm
operator|::
name|APSInt
name|getZeroValue
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|llvm
operator|::
name|APSInt
argument_list|(
name|BitWidth
argument_list|,
name|IsUnsigned
argument_list|)
return|;
block|}
comment|/// Returns the minimum value for this type.
name|llvm
operator|::
name|APSInt
name|getMinValue
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|llvm
operator|::
name|APSInt
operator|::
name|getMinValue
argument_list|(
name|BitWidth
argument_list|,
name|IsUnsigned
argument_list|)
return|;
block|}
comment|/// Returns the maximum value for this type.
name|llvm
operator|::
name|APSInt
name|getMaxValue
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|llvm
operator|::
name|APSInt
operator|::
name|getMaxValue
argument_list|(
name|BitWidth
argument_list|,
name|IsUnsigned
argument_list|)
return|;
block|}
name|llvm
operator|::
name|APSInt
name|getValue
argument_list|(
argument|uint64_t RawValue
argument_list|)
specifier|const
name|LLVM_READONLY
block|{
return|return
operator|(
name|llvm
operator|::
name|APSInt
argument_list|(
name|BitWidth
argument_list|,
name|IsUnsigned
argument_list|)
operator|=
name|RawValue
operator|)
return|;
block|}
comment|/// Used to classify whether a value is representable using this type.
comment|///
comment|/// \see testInRange
enum|enum
name|RangeTestResultKind
block|{
name|RTR_Below
init|=
operator|-
literal|1
block|,
comment|///< Value is less than the minimum representable value.
name|RTR_Within
init|=
literal|0
block|,
comment|///< Value is representable using this type.
name|RTR_Above
init|=
literal|1
comment|///< Value is greater than the maximum representable value.
block|}
enum|;
comment|/// Tests whether a given value is losslessly representable using this type.
comment|///
comment|/// \param Val The value to test.
comment|/// \param AllowMixedSign Whether or not to allow signedness conversions.
comment|///                       This determines whether -1s8 is considered in range
comment|///                       for 'unsigned char' (u8).
name|RangeTestResultKind
name|testInRange
argument_list|(
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|Val
argument_list|,
name|bool
name|AllowMixedSign
argument_list|)
decl|const
name|LLVM_READONLY
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|APSIntType
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|BitWidth
operator|==
name|Other
operator|.
name|BitWidth
operator|&&
name|IsUnsigned
operator|==
name|Other
operator|.
name|IsUnsigned
return|;
block|}
comment|/// \brief Provide an ordering for finding a common conversion type.
comment|///
comment|/// Unsigned integers are considered to be better conversion types than
comment|/// signed integers of the same width.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|APSIntType
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|BitWidth
argument_list|,
name|IsUnsigned
argument_list|)
operator|<
name|std
operator|::
name|tie
argument_list|(
name|Other
operator|.
name|BitWidth
argument_list|,
name|Other
operator|.
name|IsUnsigned
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// end ento namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

