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
name|DEFAULTONLY_H
end_ifndef

begin_define
define|#
directive|define
name|DEFAULTONLY_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|class
name|DefaultOnly
block|{
name|int
name|data_
decl_stmt|;
name|DefaultOnly
argument_list|(
specifier|const
name|DefaultOnly
operator|&
argument_list|)
expr_stmt|;
name|DefaultOnly
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DefaultOnly
operator|&
operator|)
decl_stmt|;
name|public
label|:
specifier|static
name|int
name|count
decl_stmt|;
name|DefaultOnly
argument_list|()
operator|:
name|data_
argument_list|(
argument|-
literal|1
argument_list|)
block|{
operator|++
name|count
block|;}
operator|~
name|DefaultOnly
argument_list|()
block|{
name|data_
operator|=
literal|0
block|;
operator|--
name|count
block|;}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DefaultOnly
operator|&
name|x
operator|,
specifier|const
name|DefaultOnly
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|data_
operator|==
name|y
operator|.
name|data_
return|;
block|}
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|DefaultOnly
operator|&
name|x
operator|,
specifier|const
name|DefaultOnly
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|data_
operator|<
name|y
operator|.
name|data_
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|int
name|DefaultOnly
operator|::
name|count
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// DEFAULTONLY_H
end_comment

end_unit

