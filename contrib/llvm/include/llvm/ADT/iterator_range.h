begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- iterator_range.h - A range adaptor for iterators ---------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This provides a very simple, boring adaptor for a begin and end iterator
end_comment

begin_comment
comment|/// into a range type. This should be used to build range views that work well
end_comment

begin_comment
comment|/// with range based for loops and range based constructors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that code here follows more standards-based coding conventions as it
end_comment

begin_comment
comment|/// is mirroring proposed interfaces for standardization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_ITERATOR_RANGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_ITERATOR_RANGE_H
end_define

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief A range adaptor for a pair of iterators.
comment|///
comment|/// This just wraps two iterators into a range-compatible interface. Nothing
comment|/// fancy at all.
name|template
operator|<
name|typename
name|IteratorT
operator|>
name|class
name|iterator_range
block|{
name|IteratorT
name|begin_iterator
block|,
name|end_iterator
block|;
name|public
operator|:
name|iterator_range
argument_list|()
block|{}
name|iterator_range
argument_list|(
argument|IteratorT begin_iterator
argument_list|,
argument|IteratorT end_iterator
argument_list|)
operator|:
name|begin_iterator
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|begin_iterator
argument_list|)
argument_list|)
block|,
name|end_iterator
argument_list|(
argument|std::move(end_iterator)
argument_list|)
block|{}
name|IteratorT
name|begin
argument_list|()
specifier|const
block|{
return|return
name|begin_iterator
return|;
block|}
name|IteratorT
name|end
argument_list|()
specifier|const
block|{
return|return
name|end_iterator
return|;
block|}
expr|}
block|;
comment|/// \brief Convenience function for iterating over sub-ranges.
comment|///
comment|/// This provides a bit of syntactic sugar to make using sub-ranges
comment|/// in for loops a bit easier. Analogous to std::make_pair().
name|template
operator|<
name|class
name|T
operator|>
name|iterator_range
operator|<
name|T
operator|>
name|make_range
argument_list|(
argument|T x
argument_list|,
argument|T y
argument_list|)
block|{
return|return
name|iterator_range
operator|<
name|T
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|x
argument_list|)
operator|,
name|std
operator|::
name|move
argument_list|(
name|y
argument_list|)
operator|)
return|;
block|}
expr|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

