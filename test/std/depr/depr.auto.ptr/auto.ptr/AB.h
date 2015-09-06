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
name|AB_H
end_ifndef

begin_define
define|#
directive|define
name|AB_H
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
name|virtual
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
specifier|static
name|int
name|count
expr_stmt|;
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

begin_decl_stmt
name|class
name|B
range|:
name|public
name|A
block|{
name|public
operator|:
name|explicit
name|B
argument_list|(
argument|int id
argument_list|)
operator|:
name|A
argument_list|(
argument|id
argument_list|)
block|{
operator|++
name|count
block|;}
name|B
argument_list|(
specifier|const
name|B
operator|&
name|a
argument_list|)
operator|:
name|A
argument_list|(
argument|a
argument_list|)
block|{
operator|++
name|count
block|;}
name|virtual
operator|~
name|B
argument_list|()
block|{
operator|--
name|count
block|;}
specifier|static
name|int
name|count
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
name|B
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
comment|// AB_H
end_comment

end_unit

