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
name|TEST_COMPARE_H
end_ifndef

begin_define
define|#
directive|define
name|TEST_COMPARE_H
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|C
operator|>
name|class
name|test_compare
operator|:
name|private
name|C
block|{
name|int
name|data_
block|;
name|public
operator|:
name|explicit
name|test_compare
argument_list|(
argument|int data =
literal|0
argument_list|)
operator|:
name|data_
argument_list|(
argument|data
argument_list|)
block|{}
name|typename
name|C
operator|::
name|result_type
name|operator
argument_list|()
operator|(
name|typename
name|std
operator|::
name|add_lvalue_reference
operator|<
specifier|const
name|typename
name|C
operator|::
name|first_argument_type
operator|>
operator|::
name|type
name|x
operator|,
name|typename
name|std
operator|::
name|add_lvalue_reference
operator|<
specifier|const
name|typename
name|C
operator|::
name|second_argument_type
operator|>
operator|::
name|type
name|y
operator|)
specifier|const
block|{
return|return
name|C
operator|::
name|operator
argument_list|()
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|test_compare
operator|&
name|c
operator|)
specifier|const
block|{
return|return
name|data_
operator|==
name|c
operator|.
name|data_
return|;
block|}
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// TEST_COMPARE_H
end_comment

end_unit

