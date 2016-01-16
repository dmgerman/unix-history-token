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
name|A_H
end_ifndef

begin_define
define|#
directive|define
name|A_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|class
name|A
block|{
name|int
name|id_
decl_stmt|;
name|public
label|:
name|explicit
name|A
argument_list|(
argument|int id
argument_list|)
block|:
name|id_
argument_list|(
argument|id
argument_list|)
block|{
operator|++
name|count
expr_stmt|;
block|}
name|A
argument_list|(
specifier|const
name|A
operator|&
name|a
argument_list|)
operator|:
name|id_
argument_list|(
argument|a.id_
argument_list|)
block|{
operator|++
name|count
block|;}
operator|~
name|A
argument_list|()
block|{
name|assert
argument_list|(
name|id_
operator|>=
literal|0
argument_list|)
block|;
name|id_
operator|=
operator|-
literal|1
block|;
operator|--
name|count
block|;}
name|int
name|id
argument_list|()
specifier|const
block|{
return|return
name|id_
return|;
block|}
specifier|static
name|int
name|count
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|int
name|A
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
comment|// A_H
end_comment

end_unit

