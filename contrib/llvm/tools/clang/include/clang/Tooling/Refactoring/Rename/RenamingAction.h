begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RenamingAction.h - Clang refactoring library ---------------------===//
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
comment|/// \brief Provides an action to rename every symbol at a point.
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
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_RENAMING_ACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_RENAMING_ACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Tooling/Refactoring.h"
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
name|namespace
name|tooling
block|{
name|class
name|RenamingAction
block|{
name|public
label|:
name|RenamingAction
argument_list|(
argument|const std::vector<std::string>&NewNames
argument_list|,
argument|const std::vector<std::string>&PrevNames
argument_list|,
argument|const std::vector<std::vector<std::string>>&USRList
argument_list|,
argument|std::map<std::string
argument_list|,
argument|tooling::Replacements>&FileToReplaces
argument_list|,
argument|bool PrintLocations = false
argument_list|)
block|:
name|NewNames
argument_list|(
name|NewNames
argument_list|)
operator|,
name|PrevNames
argument_list|(
name|PrevNames
argument_list|)
operator|,
name|USRList
argument_list|(
name|USRList
argument_list|)
operator|,
name|FileToReplaces
argument_list|(
name|FileToReplaces
argument_list|)
operator|,
name|PrintLocations
argument_list|(
argument|PrintLocations
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
name|private
label|:
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|NewNames
operator|,
operator|&
name|PrevNames
expr_stmt|;
specifier|const
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
operator|&
name|USRList
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|tooling
operator|::
name|Replacements
operator|>
operator|&
name|FileToReplaces
expr_stmt|;
name|bool
name|PrintLocations
decl_stmt|;
block|}
empty_stmt|;
comment|/// Rename all symbols identified by the given USRs.
name|class
name|QualifiedRenamingAction
block|{
name|public
label|:
name|QualifiedRenamingAction
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|NewNames
argument_list|,
specifier|const
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
operator|&
name|USRList
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
name|tooling
operator|::
name|Replacements
operator|>
operator|&
name|FileToReplaces
argument_list|)
operator|:
name|NewNames
argument_list|(
name|NewNames
argument_list|)
operator|,
name|USRList
argument_list|(
name|USRList
argument_list|)
operator|,
name|FileToReplaces
argument_list|(
argument|FileToReplaces
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
name|private
label|:
comment|/// New symbol names.
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|NewNames
expr_stmt|;
comment|/// A list of USRs. Each element represents USRs of a symbol being renamed.
specifier|const
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
operator|&
name|USRList
expr_stmt|;
comment|/// A file path to replacements map.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|tooling
operator|::
name|Replacements
operator|>
operator|&
name|FileToReplaces
expr_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_CLANG_TOOLING_REFACTOR_RENAME_RENAMING_ACTION_H
end_comment

end_unit

