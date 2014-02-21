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
name|LLVM_CLANG_REWRITE_FRONTENDACTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITE_FRONTENDACTIONS_H
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
name|class
name|FixItOptions
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// AST Consumer Actions
comment|//===----------------------------------------------------------------------===//
name|class
name|HTMLPrintAction
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
argument|StringRef InFile
argument_list|)
block|; }
decl_stmt|;
name|class
name|FixItAction
range|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|OwningPtr
operator|<
name|FixItRewriter
operator|>
name|Rewriter
block|;
name|OwningPtr
operator|<
name|FixItOptions
operator|>
name|FixItOpts
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
name|EndSourceFileAction
argument_list|()
block|;
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
name|FixItAction
argument_list|()
block|;
operator|~
name|FixItAction
argument_list|()
block|; }
decl_stmt|;
comment|/// \brief Emits changes to temporary files and uses them for the original
comment|/// frontend action.
name|class
name|FixItRecompile
range|:
name|public
name|WrapperFrontendAction
block|{
name|public
operator|:
name|FixItRecompile
argument_list|(
name|FrontendAction
operator|*
name|WrappedAction
argument_list|)
operator|:
name|WrapperFrontendAction
argument_list|(
argument|WrappedAction
argument_list|)
block|{}
name|protected
operator|:
name|virtual
name|bool
name|BeginInvocation
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|; }
decl_stmt|;
name|class
name|RewriteObjCAction
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
argument|StringRef InFile
argument_list|)
block|; }
decl_stmt|;
name|class
name|RewriteMacrosAction
range|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
decl_stmt|;
name|class
name|RewriteTestAction
range|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
decl_stmt|;
name|class
name|RewriteIncludesAction
range|:
name|public
name|PreprocessorFrontendAction
block|{
name|protected
operator|:
name|void
name|ExecuteAction
argument_list|()
block|; }
decl_stmt|;
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

