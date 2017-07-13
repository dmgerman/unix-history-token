begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- UnicodeCharRanges.h - Types and functions for character ranges ---===//
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
name|LLVM_SUPPORT_UNICODECHARRANGES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_UNICODECHARRANGES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MutexGuard.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_define
define|#
directive|define
name|DEBUG_TYPE
value|"unicode"
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// \brief Represents a closed range of Unicode code points [Lower, Upper].
struct|struct
name|UnicodeCharRange
block|{
name|uint32_t
name|Lower
decl_stmt|;
name|uint32_t
name|Upper
decl_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|uint32_t
name|Value
operator|,
name|UnicodeCharRange
name|Range
operator|)
block|{
return|return
name|Value
operator|<
name|Range
operator|.
name|Lower
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|UnicodeCharRange
name|Range
operator|,
name|uint32_t
name|Value
operator|)
block|{
return|return
name|Range
operator|.
name|Upper
operator|<
name|Value
return|;
block|}
comment|/// \brief Holds a reference to an ordered array of UnicodeCharRange and allows
comment|/// to quickly check if a code point is contained in the set represented by this
comment|/// array.
name|class
name|UnicodeCharSet
block|{
name|public
label|:
typedef|typedef
name|ArrayRef
operator|<
name|UnicodeCharRange
operator|>
name|CharRanges
expr_stmt|;
comment|/// \brief Constructs a UnicodeCharSet instance from an array of
comment|/// UnicodeCharRanges.
comment|///
comment|/// Array pointed by \p Ranges should have the lifetime at least as long as
comment|/// the UnicodeCharSet instance, and should not change. Array is validated by
comment|/// the constructor, so it makes sense to create as few UnicodeCharSet
comment|/// instances per each array of ranges, as possible.
ifdef|#
directive|ifdef
name|NDEBUG
comment|// FIXME: This could use constexpr + static_assert. This way we
comment|// may get rid of NDEBUG in this header. Unfortunately there are some
comment|// problems to get this working with MSVC 2013. Change this when
comment|// the support for MSVC 2013 is dropped.
name|constexpr
name|UnicodeCharSet
argument_list|(
argument|CharRanges Ranges
argument_list|)
block|:
name|Ranges
argument_list|(
argument|Ranges
argument_list|)
block|{}
else|#
directive|else
name|UnicodeCharSet
argument_list|(
argument|CharRanges Ranges
argument_list|)
block|:
name|Ranges
argument_list|(
argument|Ranges
argument_list|)
block|{
name|assert
argument_list|(
name|rangesAreValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/// \brief Returns true if the character set contains the Unicode code point
comment|/// \p C.
name|bool
name|contains
argument_list|(
name|uint32_t
name|C
argument_list|)
decl|const
block|{
return|return
name|std
operator|::
name|binary_search
argument_list|(
name|Ranges
operator|.
name|begin
argument_list|()
argument_list|,
name|Ranges
operator|.
name|end
argument_list|()
argument_list|,
name|C
argument_list|)
return|;
block|}
name|private
label|:
comment|/// \brief Returns true if each of the ranges is a proper closed range
comment|/// [min, max], and if the ranges themselves are ordered and non-overlapping.
name|bool
name|rangesAreValid
argument_list|()
specifier|const
block|{
name|uint32_t
name|Prev
operator|=
literal|0
block|;
for|for
control|(
name|CharRanges
operator|::
name|const_iterator
name|I
operator|=
name|Ranges
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Ranges
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
if|if
condition|(
name|I
operator|!=
name|Ranges
operator|.
name|begin
argument_list|()
operator|&&
name|Prev
operator|>=
name|I
operator|->
name|Lower
condition|)
block|{
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"Upper bound 0x"
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|.
name|write_hex
argument_list|(
name|Prev
argument_list|)
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|" should be less than succeeding lower bound 0x"
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|.
name|write_hex
argument_list|(
name|I
operator|->
name|Lower
argument_list|)
operator|<<
literal|"\n"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|I
operator|->
name|Upper
operator|<
name|I
operator|->
name|Lower
condition|)
block|{
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"Upper bound 0x"
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|.
name|write_hex
argument_list|(
name|I
operator|->
name|Lower
argument_list|)
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|" should not be less than lower bound 0x"
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|.
name|write_hex
argument_list|(
name|I
operator|->
name|Upper
argument_list|)
operator|<<
literal|"\n"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|Prev
operator|=
name|I
operator|->
name|Upper
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
specifier|const
name|CharRanges
name|Ranges
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace sys
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG_TYPE
end_undef

begin_comment
comment|// "unicode"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_UNICODECHARRANGES_H
end_comment

end_unit

