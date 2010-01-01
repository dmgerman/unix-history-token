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

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FixItRewriter
decl_stmt|;
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
decl_stmt|;
name|class
name|ASTPrintAction
range|:
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
decl_stmt|;
name|class
name|ASTPrintXMLAction
range|:
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
decl_stmt|;
name|class
name|ASTDumpAction
range|:
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
decl_stmt|;
name|class
name|ASTViewAction
range|:
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
decl_stmt|;
name|class
name|DeclContextPrintAction
range|:
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
decl_stmt|;
name|class
name|DumpRecordAction
range|:
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
decl_stmt|;
name|class
name|FixItAction
range|:
name|public
name|ASTFrontendAction
block|{
name|private
operator|:
name|llvm
operator|::
name|OwningPtr
operator|<
name|FixItRewriter
operator|>
name|Rewriter
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
decl_stmt|;
name|class
name|GeneratePCHAction
range|:
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
comment|//===----------------------------------------------------------------------===//
comment|// Code Gen AST Actions
comment|//===----------------------------------------------------------------------===//
name|class
name|CodeGenAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|private
operator|:
name|unsigned
name|Act
block|;
name|protected
operator|:
name|CodeGenAction
argument_list|(
argument|unsigned _Act
argument_list|)
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
block|; }
block|;
name|class
name|EmitAssemblyAction
operator|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitAssemblyAction
argument_list|()
block|; }
block|;
name|class
name|EmitBCAction
operator|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitBCAction
argument_list|()
block|; }
block|;
name|class
name|EmitLLVMAction
operator|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitLLVMAction
argument_list|()
block|; }
block|;
name|class
name|EmitLLVMOnlyAction
operator|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitLLVMOnlyAction
argument_list|()
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

