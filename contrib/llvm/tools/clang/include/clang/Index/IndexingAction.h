begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- IndexingAction.h - Frontend index action -------------------------===//
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
name|LLVM_CLANG_INDEX_INDEXINGACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_INDEXINGACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTReader
decl_stmt|;
name|class
name|ASTUnit
decl_stmt|;
name|class
name|FrontendAction
decl_stmt|;
name|namespace
name|serialization
block|{
name|class
name|ModuleFile
decl_stmt|;
block|}
name|namespace
name|index
block|{
name|class
name|IndexDataConsumer
decl_stmt|;
struct|struct
name|IndexingOptions
block|{
name|enum
name|class
name|SystemSymbolFilterKind
block|{
name|None
operator|,
name|DeclarationsOnly
operator|,
name|All
operator|,
block|}
empty_stmt|;
name|SystemSymbolFilterKind
name|SystemSymbolFilter
init|=
name|SystemSymbolFilterKind
operator|::
name|DeclarationsOnly
decl_stmt|;
name|bool
name|IndexFunctionLocals
init|=
name|false
decl_stmt|;
block|}
struct|;
comment|/// \param WrappedAction another frontend action to wrap over or null.
name|std
operator|::
name|unique_ptr
operator|<
name|FrontendAction
operator|>
name|createIndexingAction
argument_list|(
argument|std::shared_ptr<IndexDataConsumer> DataConsumer
argument_list|,
argument|IndexingOptions Opts
argument_list|,
argument|std::unique_ptr<FrontendAction> WrappedAction
argument_list|)
expr_stmt|;
name|void
name|indexASTUnit
argument_list|(
name|ASTUnit
operator|&
name|Unit
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|IndexDataConsumer
operator|>
name|DataConsumer
argument_list|,
name|IndexingOptions
name|Opts
argument_list|)
decl_stmt|;
name|void
name|indexModuleFile
argument_list|(
name|serialization
operator|::
name|ModuleFile
operator|&
name|Mod
argument_list|,
name|ASTReader
operator|&
name|Reader
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|IndexDataConsumer
operator|>
name|DataConsumer
argument_list|,
name|IndexingOptions
name|Opts
argument_list|)
decl_stmt|;
block|}
comment|// namespace index
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

