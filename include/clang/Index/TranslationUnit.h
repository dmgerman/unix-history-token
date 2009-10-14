begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TranslationUnit.h - Interface for a translation unit ---*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  Abstract interface for a translation unit.
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
name|LLVM_CLANG_INDEX_TRANSLATIONUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_TRANSLATIONUNIT_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|namespace
name|idx
block|{
name|class
name|DeclReferenceMap
decl_stmt|;
name|class
name|SelectorMap
decl_stmt|;
comment|/// \brief Abstract interface for a translation unit.
name|class
name|TranslationUnit
block|{
name|public
label|:
name|virtual
operator|~
name|TranslationUnit
argument_list|()
expr_stmt|;
name|virtual
name|ASTContext
modifier|&
name|getASTContext
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|DeclReferenceMap
modifier|&
name|getDeclReferenceMap
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|SelectorMap
modifier|&
name|getSelectorMap
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
comment|// namespace idx
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

