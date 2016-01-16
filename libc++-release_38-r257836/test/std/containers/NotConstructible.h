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
name|NOTCONSTRUCTIBLE_H
end_ifndef

begin_define
define|#
directive|define
name|NOTCONSTRUCTIBLE_H
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|class
name|NotConstructible
block|{
name|NotConstructible
argument_list|(
specifier|const
name|NotConstructible
operator|&
argument_list|)
expr_stmt|;
name|NotConstructible
modifier|&
name|operator
init|=
operator|(
specifier|const
name|NotConstructible
operator|&
operator|)
decl_stmt|;
name|public
label|:
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|NotConstructible
operator|&
operator|,
specifier|const
name|NotConstructible
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

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
name|NotConstructible
operator|>
operator|:
name|public
name|std
operator|::
name|unary_function
operator|<
name|NotConstructible
operator|,
name|std
operator|::
name|size_t
operator|>
block|{
name|std
operator|::
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|NotConstructible
operator|&
operator|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// NOTCONSTRUCTIBLE_H
end_comment

end_unit

