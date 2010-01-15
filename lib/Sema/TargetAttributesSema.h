begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TargetAttributesSema.h - Semantic Analysis For Target Attributes -===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_SEMA_TARGETSEMA_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_SEMA_TARGETSEMA_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Scope
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Attr
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|TargetAttributesSema
block|{
name|public
label|:
name|virtual
operator|~
name|TargetAttributesSema
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|ProcessDeclAttribute
argument_list|(
name|Scope
operator|*
name|scope
argument_list|,
name|Decl
operator|*
name|D
argument_list|,
specifier|const
name|AttributeList
operator|&
name|Attr
argument_list|,
name|Sema
operator|&
name|S
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

