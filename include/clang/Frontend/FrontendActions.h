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
name|Module
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
argument|StringRef InFile
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
argument|StringRef InFile
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
argument|StringRef InFile
argument_list|)
block|; }
block|;
name|class
name|ASTDeclListAction
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
argument|StringRef InFile
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
argument|StringRef InFile
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
argument|StringRef InFile
argument_list|)
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
argument|StringRef InFile
argument_list|)
block|;
name|virtual
name|TranslationUnitKind
name|getTranslationUnitKind
argument_list|()
block|{
return|return
name|TU_Prefix
return|;
block|}
name|virtual
name|bool
name|hasASTFileSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|public
operator|:
comment|/// \brief Compute the AST consumer arguments that will be used to
comment|/// create the PCHGenerator instance returned by CreateASTConsumer.
comment|///
comment|/// \returns true if an error occurred, false otherwise.
specifier|static
name|bool
name|ComputeASTConsumerArguments
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|,
argument|std::string&Sysroot
argument_list|,
argument|std::string&OutputFile
argument_list|,
argument|raw_ostream *&OS
argument_list|)
block|; }
block|;
name|class
name|GenerateModuleAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|clang
operator|::
name|Module
operator|*
name|Module
block|;
name|bool
name|IsSystem
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
argument|StringRef InFile
argument_list|)
block|;
name|virtual
name|TranslationUnitKind
name|getTranslationUnitKind
argument_list|()
block|{
return|return
name|TU_Module
return|;
block|}
name|virtual
name|bool
name|hasASTFileSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|public
operator|:
name|explicit
name|GenerateModuleAction
argument_list|(
argument|bool IsSystem = false
argument_list|)
operator|:
name|ASTFrontendAction
argument_list|()
block|,
name|IsSystem
argument_list|(
argument|IsSystem
argument_list|)
block|{ }
name|virtual
name|bool
name|BeginSourceFileAction
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef Filename
argument_list|)
block|;
comment|/// \brief Compute the AST consumer arguments that will be used to
comment|/// create the PCHGenerator instance returned by CreateASTConsumer.
comment|///
comment|/// \returns true if an error occurred, false otherwise.
specifier|static
name|bool
name|ComputeASTConsumerArguments
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|,
argument|std::string&Sysroot
argument_list|,
argument|std::string&OutputFile
argument_list|,
argument|raw_ostream *&OS
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
argument|StringRef InFile
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
comment|/// \brief Dump information about the given module file, to be used for
comment|/// basic debugging and discovery.
name|class
name|DumpModuleInfoAction
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
argument|StringRef InFile
argument_list|)
block|;
name|virtual
name|void
name|ExecuteAction
argument_list|()
block|;
name|public
operator|:
name|virtual
name|bool
name|hasPCHSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|hasASTFileSupport
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|hasIRSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|hasCodeCompletionSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
expr|}
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
argument|StringRef InFile
argument_list|)
block|;
name|virtual
name|bool
name|BeginSourceFileAction
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef Filename
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
name|FrontendAction
operator|*
name|AdaptedAction
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|ASTFiles
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
name|TranslationUnitKind
name|getTranslationUnitKind
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
name|hasASTFileSupport
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
name|class
name|PrintPreambleAction
operator|:
name|public
name|FrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|;
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&
argument_list|,
argument|StringRef
argument_list|)
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|bool
name|usesPreprocessorOnly
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
block|;    }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

