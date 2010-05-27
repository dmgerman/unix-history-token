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
name|LLVM_CLANG_FRONTEND_FRONTENDACTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_FRONTENDACTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
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
name|FixItRewriter
decl_stmt|;
name|class
name|FixItPathRewriter
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Custom Consumer Actions
comment|//===----------------------------------------------------------------------===//
name|class
name|InitOnlyAction
range|:
name|public
name|FrontendAction
block|{
name|virtual
name|void
name|ExecuteAction
argument_list|()
block|;
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|;
name|public
operator|:
comment|// Don't claim to only use the preprocessor, we want to follow the AST path,
comment|// but do nothing.
name|virtual
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|// AST Consumer Actions
comment|//===----------------------------------------------------------------------===//
name|class
name|AnalysisAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|ASTPrintAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|ASTPrintXMLAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|ASTDumpAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|ASTViewAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|DeclContextPrintAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|FixItAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|llvm
operator|::
name|OwningPtr
operator|<
name|FixItRewriter
operator|>
name|Rewriter
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|FixItPathRewriter
operator|>
name|PathRewriter
block|;
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|;
name|virtual
name|bool
name|BeginSourceFileAction
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef Filename
argument_list|)
block|;
name|virtual
name|void
name|EndSourceFileAction
argument_list|()
block|;
name|virtual
name|bool
name|hasASTSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|public
operator|:
name|FixItAction
argument_list|()
block|;
operator|~
name|FixItAction
argument_list|()
block|; }
block|;
name|class
name|GeneratePCHAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|;
name|virtual
name|bool
name|usesCompleteTranslationUnit
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|hasASTSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
expr|}
block|;
name|class
name|HTMLPrintAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|InheritanceViewAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|RewriteObjCAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|SyntaxOnlyAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|;
name|public
operator|:
name|virtual
name|bool
name|hasCodeCompletionSupport
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|BoostConAction
operator|:
name|public
name|SyntaxOnlyAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|; }
block|;
comment|/**  * \brief Frontend action adaptor that merges ASTs together.  *  * This action takes an existing AST file and "merges" it into the AST  * context, producing a merged context. This action is an action  * adaptor, which forwards most of its calls to another action that  * will consume the merged context.  */
name|class
name|ASTMergeAction
operator|:
name|public
name|FrontendAction
block|{
comment|/// \brief The action that the merge action adapts.
name|FrontendAction
operator|*
name|AdaptedAction
block|;
comment|/// \brief The set of AST files to merge.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ASTFiles
block|;
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|;
name|virtual
name|bool
name|BeginSourceFileAction
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef Filename
argument_list|)
block|;
name|virtual
name|void
name|ExecuteAction
argument_list|()
block|;
name|virtual
name|void
name|EndSourceFileAction
argument_list|()
block|;
name|public
operator|:
name|ASTMergeAction
argument_list|(
argument|FrontendAction *AdaptedAction
argument_list|,
argument|std::string *ASTFiles
argument_list|,
argument|unsigned NumASTFiles
argument_list|)
block|;
name|virtual
operator|~
name|ASTMergeAction
argument_list|()
block|;
name|virtual
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|usesCompleteTranslationUnit
argument_list|()
block|;
name|virtual
name|bool
name|hasPCHSupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|hasASTSupport
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|hasCodeCompletionSupport
argument_list|()
specifier|const
block|; }
block|;
comment|//===----------------------------------------------------------------------===//
comment|// Preprocessor Actions
comment|//===----------------------------------------------------------------------===//
name|class
name|DumpRawTokensAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;
name|class
name|DumpTokensAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;
name|class
name|GeneratePTHAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;
name|class
name|ParseOnlyAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;
name|class
name|PreprocessOnlyAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;
name|class
name|PrintParseAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;
name|class
name|PrintPreprocessedAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|;
name|virtual
name|bool
name|hasPCHSupport
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|RewriteMacrosAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;
name|class
name|RewriteTestAction
operator|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

