begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FrontendActions.h - Useful Frontend Actions -------------*- C++ -*-===//
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
name|LLVM_CLANG_STATICANALYZER_FRONTEND_FRONTENDACTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_FRONTEND_FRONTENDACTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Stmt
decl_stmt|;
name|namespace
name|ento
block|{
comment|//===----------------------------------------------------------------------===//
comment|// AST Consumer Actions
comment|//===----------------------------------------------------------------------===//
name|class
name|AnalysisAction
range|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// \brief Frontend action to parse model files.
comment|///
comment|/// This frontend action is responsible for parsing model files. Model files can
comment|/// not be parsed on their own, they rely on type information that is available
comment|/// in another translation unit. The parsing of model files is done by a
comment|/// separate compiler instance that reuses the ASTContext and othen information
comment|/// from the main translation unit that is being compiled. After a model file is
comment|/// parsed, the function definitions will be collected into a StringMap.
name|class
name|ParseModelFileAction
range|:
name|public
name|ASTFrontendAction
block|{
name|public
operator|:
name|ParseModelFileAction
argument_list|(
name|llvm
operator|::
name|StringMap
operator|<
name|Stmt
operator|*
operator|>
operator|&
name|Bodies
argument_list|)
block|;
name|bool
name|isModelParsingAction
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
name|override
block|;
name|private
operator|:
name|llvm
operator|::
name|StringMap
operator|<
name|Stmt
operator|*
operator|>
operator|&
name|Bodies
block|; }
decl_stmt|;
name|void
name|printCheckerHelp
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|plugins
argument_list|)
decl_stmt|;
block|}
comment|// end GR namespace
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

