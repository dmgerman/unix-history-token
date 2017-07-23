begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== SelectorExtras.h - Helpers for checkers using selectors -----*- C++ -*-=//
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
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_SELECTOREXTRAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_SELECTOREXTRAS_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|template
operator|<
name|typename
operator|...
name|IdentifierInfos
operator|>
specifier|static
specifier|inline
name|Selector
name|getKeywordSelector
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|IdentifierInfos *... IIs
argument_list|)
block|{
name|static_assert
argument_list|(
sizeof|sizeof...
argument_list|(
name|IdentifierInfos
argument_list|)
argument_list|,
literal|"keyword selectors must have at least one argument"
argument_list|)
block|;
name|SmallVector
operator|<
name|IdentifierInfo
operator|*
block|,
literal|10
operator|>
name|II
argument_list|(
block|{
operator|&
name|Ctx
operator|.
name|Idents
operator|.
name|get
argument_list|(
name|IIs
argument_list|)
operator|...
block|}
argument_list|)
block|;
return|return
name|Ctx
operator|.
name|Selectors
operator|.
name|getSelector
argument_list|(
name|II
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|II
index|[
literal|0
index|]
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
operator|...
name|IdentifierInfos
operator|>
specifier|static
specifier|inline
name|void
name|lazyInitKeywordSelector
argument_list|(
argument|Selector&Sel
argument_list|,
argument|ASTContext&Ctx
argument_list|,
argument|IdentifierInfos *... IIs
argument_list|)
block|{
if|if
condition|(
operator|!
name|Sel
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|Sel
operator|=
name|getKeywordSelector
argument_list|(
name|Ctx
argument_list|,
name|IIs
operator|...
argument_list|)
expr_stmt|;
block|}
specifier|static
specifier|inline
name|void
name|lazyInitNullarySelector
parameter_list|(
name|Selector
modifier|&
name|Sel
parameter_list|,
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Sel
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|Sel
operator|=
name|GetNullarySelector
argument_list|(
name|Name
argument_list|,
name|Ctx
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace ento
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

