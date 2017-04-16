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
name|MOVEONLY_H
end_ifndef

begin_define
define|#
directive|define
name|MOVEONLY_H
end_define

begin_include
include|#
directive|include
file|"test_macros.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_HAS_NO_RVALUE_REFERENCES
end_ifndef

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|class
name|MoveOnly
block|{
name|friend
name|class
name|MoveOnly2
decl_stmt|;
name|MoveOnly
argument_list|(
specifier|const
name|MoveOnly
operator|&
argument_list|)
expr_stmt|;
name|MoveOnly
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MoveOnly
operator|&
operator|)
decl_stmt|;
name|int
name|data_
decl_stmt|;
name|public
label|:
name|MoveOnly
argument_list|(
argument|int data =
literal|1
argument_list|)
block|:
name|data_
argument_list|(
argument|data
argument_list|)
block|{}
name|MoveOnly
argument_list|(
name|MoveOnly
operator|&&
name|x
argument_list|)
operator|:
name|data_
argument_list|(
argument|x.data_
argument_list|)
block|{
name|x
operator|.
name|data_
operator|=
literal|0
block|;}
name|MoveOnly
operator|&
name|operator
operator|=
operator|(
name|MoveOnly
operator|&&
name|x
operator|)
block|{
name|data_
operator|=
name|x
operator|.
name|data_
block|;
name|x
operator|.
name|data_
operator|=
literal|0
block|;
return|return
operator|*
name|this
return|;
block|}
name|int
name|get
argument_list|()
specifier|const
block|{
return|return
name|data_
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MoveOnly
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|data_
operator|==
name|x
operator|.
name|data_
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|MoveOnly
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|data_
operator|<
name|x
operator|.
name|data_
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|MoveOnly
operator|>
block|{
typedef|typedef
name|MoveOnly
name|argument_type
typedef|;
typedef|typedef
name|size_t
name|result_type
typedef|;
name|std
operator|::
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|MoveOnly
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|x
operator|.
name|get
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_HAS_NO_RVALUE_REFERENCES
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MOVEONLY_H
end_comment

end_unit

