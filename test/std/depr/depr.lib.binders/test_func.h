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
name|TEST_FUNC_H
end_ifndef

begin_define
define|#
directive|define
name|TEST_FUNC_H
end_define

begin_decl_stmt
name|class
name|test_func
block|{
name|int
name|id_
decl_stmt|;
name|public
label|:
typedef|typedef
name|int
name|first_argument_type
typedef|;
typedef|typedef
name|double
name|second_argument_type
typedef|;
typedef|typedef
name|long
name|double
name|result_type
typedef|;
name|explicit
name|test_func
argument_list|(
argument|int id
argument_list|)
block|:
name|id_
argument_list|(
argument|id
argument_list|)
block|{}
name|int
name|id
argument_list|()
specifier|const
block|{
return|return
name|id_
return|;
block|}
name|result_type
name|operator
argument_list|()
operator|(
specifier|const
name|first_argument_type
operator|&
name|x
operator|,
name|second_argument_type
operator|&
name|y
operator|)
specifier|const
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
name|result_type
name|operator
argument_list|()
operator|(
specifier|const
name|first_argument_type
operator|&
name|x
operator|,
specifier|const
name|second_argument_type
operator|&
name|y
operator|)
specifier|const
block|{
return|return
name|x
operator|-
name|y
return|;
block|}
name|result_type
name|operator
argument_list|()
operator|(
name|first_argument_type
operator|&
name|x
operator|,
specifier|const
name|second_argument_type
operator|&
name|y
operator|)
specifier|const
block|{
return|return
name|x
operator|*
name|y
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TEST_FUNC_H
end_comment

end_unit

