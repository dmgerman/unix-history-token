begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- USRFindingAction.h - Clang refactoring library -------------------===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Provides an action to find all relevant USRs at a point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_FINDING_ACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_FINDING_ACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|CompilerInstance
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|namespace
name|tooling
block|{
struct|struct
name|USRFindingAction
block|{
name|USRFindingAction
argument_list|(
argument|ArrayRef<unsigned> SymbolOffsets
argument_list|,
argument|ArrayRef<std::string> QualifiedNames
argument_list|,
argument|bool Force
argument_list|)
block|:
name|SymbolOffsets
argument_list|(
name|SymbolOffsets
argument_list|)
operator|,
name|QualifiedNames
argument_list|(
name|QualifiedNames
argument_list|)
operator|,
name|ErrorOccurred
argument_list|(
name|false
argument_list|)
operator|,
name|Force
argument_list|(
argument|Force
argument_list|)
block|{}
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|newASTConsumer
argument_list|()
expr_stmt|;
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|getUSRSpellings
argument_list|()
block|{
return|return
name|SpellingNames
return|;
block|}
name|ArrayRef
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>>
name|getUSRList
argument_list|()
block|{
return|return
name|USRList
return|;
block|}
name|bool
name|errorOccurred
parameter_list|()
block|{
return|return
name|ErrorOccurred
return|;
block|}
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|SymbolOffsets
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|QualifiedNames
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|SpellingNames
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>>
name|USRList
expr_stmt|;
name|bool
name|ErrorOccurred
decl_stmt|;
name|bool
name|Force
decl_stmt|;
block|}
struct|;
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_FINDING_ACTION_H
end_comment

end_unit

