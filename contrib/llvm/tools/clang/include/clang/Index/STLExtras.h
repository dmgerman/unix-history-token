begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- STLExtras.h - Helper STL related templates -------------*- C++ -*-===//
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
comment|//  Helper templates for using with the STL.
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
name|LLVM_CLANG_INDEX_STLEXTRAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_STLEXTRAS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|idx
block|{
comment|/// \brief Wraps an iterator whose value_type is a pair, and provides
comment|/// pair's second object as the value.
name|template
operator|<
name|typename
name|iter_type
operator|>
name|class
name|pair_value_iterator
block|{
name|iter_type
name|I
block|;
name|public
operator|:
typedef|typedef
name|typename
name|iter_type
operator|::
name|value_type
operator|::
name|second_type
name|value_type
expr_stmt|;
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
typedef|typedef
name|typename
name|iter_type
operator|::
name|iterator_category
name|iterator_category
expr_stmt|;
typedef|typedef
name|typename
name|iter_type
operator|::
name|difference_type
name|difference_type
expr_stmt|;
name|pair_value_iterator
argument_list|()
block|{ }
name|pair_value_iterator
argument_list|(
argument|iter_type i
argument_list|)
block|:
name|I
argument_list|(
argument|i
argument_list|)
block|{ }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|I
operator|->
name|second
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|I
operator|->
name|second
return|;
block|}
name|pair_value_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|I
block|;
return|return
operator|*
name|this
return|;
block|}
name|pair_value_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|pair_value_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|pair_value_iterator
name|L
operator|,
name|pair_value_iterator
name|R
operator|)
block|{
return|return
name|L
operator|.
name|I
operator|==
name|R
operator|.
name|I
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|pair_value_iterator
name|L
operator|,
name|pair_value_iterator
name|R
operator|)
block|{
return|return
name|L
operator|.
name|I
operator|!=
name|R
operator|.
name|I
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end idx namespace
end_comment

begin_comment
unit|}
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

