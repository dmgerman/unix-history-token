begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|INPUT_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|INPUT_ITERATOR_H
end_define

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|It
operator|>
name|class
name|input_iterator
block|{
name|It
name|it_
block|;
name|public
operator|:
typedef|typedef
name|typename
name|std
operator|::
name|input_iterator_tag
name|iterator_category
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|It
operator|>
operator|::
name|value_type
name|value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|It
operator|>
operator|::
name|difference_type
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|It
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|It
operator|>
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_expr_stmt
name|input_iterator
argument_list|()
operator|:
name|it_
argument_list|()
block|{}
name|explicit
name|input_iterator
argument_list|(
argument|It it
argument_list|)
operator|:
name|it_
argument_list|(
argument|it
argument_list|)
block|{}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|it_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|it_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|input_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|it_
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|input_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|input_iterator
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
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|input_iterator
operator|&
name|x
operator|,
specifier|const
name|input_iterator
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|it_
operator|==
name|y
operator|.
name|it_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|input_iterator
operator|&
name|x
operator|,
specifier|const
name|input_iterator
operator|&
name|y
operator|)
block|{
return|return
operator|!
operator|(
name|x
operator|==
name|y
operator|)
return|;
block|}
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// INPUT_ITERATOR_H
end_comment

end_unit

