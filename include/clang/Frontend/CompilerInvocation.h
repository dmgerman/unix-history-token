begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompilerInvocation.h - Compiler Invocation Helper Data --*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_COMPILERINVOCATION_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_COMPILERINVOCATION_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/CodeGen/CodeGenOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/AnalysisConsumer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/DependencyOutputOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/DiagnosticOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/HeaderSearchOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/PreprocessorOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/PreprocessorOutputOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
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
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// CompilerInvocation - Helper class for holding the data necessary to invoke
comment|/// the compiler.
comment|///
comment|/// This class is designed to represent an abstract "invocation" of the
comment|/// compiler, including data such as the include paths, the code generation
comment|/// options, the warning flags, and so on.
name|class
name|CompilerInvocation
block|{
comment|/// Options controlling the static analyzer.
name|AnalyzerOptions
name|AnalyzerOpts
decl_stmt|;
comment|/// Options controlling IRgen and the backend.
name|CodeGenOptions
name|CodeGenOpts
decl_stmt|;
comment|/// Options controlling dependency output.
name|DependencyOutputOptions
name|DependencyOutputOpts
decl_stmt|;
comment|/// Options controlling the diagnostic engine.
name|DiagnosticOptions
name|DiagnosticOpts
decl_stmt|;
comment|/// Options controlling the frontend itself.
name|FrontendOptions
name|FrontendOpts
decl_stmt|;
comment|/// Options controlling the #include directive.
name|HeaderSearchOptions
name|HeaderSearchOpts
decl_stmt|;
comment|/// Options controlling the language variant.
name|LangOptions
name|LangOpts
decl_stmt|;
comment|/// Options controlling the preprocessor (aside from #include handling).
name|PreprocessorOptions
name|PreprocessorOpts
decl_stmt|;
comment|/// Options controlling preprocessed output.
name|PreprocessorOutputOptions
name|PreprocessorOutputOpts
decl_stmt|;
comment|/// Options controlling the target.
name|TargetOptions
name|TargetOpts
decl_stmt|;
name|public
label|:
name|CompilerInvocation
argument_list|()
block|{}
comment|/// @name Utility Methods
comment|/// @{
comment|/// CreateFromArgs - Create a compiler invocation from a list of input
comment|/// options.
comment|///
comment|/// FIXME: Documenting error behavior.
comment|///
comment|/// \param Res [out] - The resulting invocation.
comment|/// \param Args - The input argument strings.
specifier|static
name|void
name|CreateFromArgs
argument_list|(
name|CompilerInvocation
operator|&
name|Res
argument_list|,
specifier|const
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|StringRef
operator|>
operator|&
name|Args
argument_list|)
decl_stmt|;
comment|/// toArgs - Convert the CompilerInvocation to a list of strings suitable for
comment|/// passing to CreateFromArgs.
name|void
name|toArgs
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Res
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Option Subgroups
comment|/// @{
name|AnalyzerOptions
modifier|&
name|getAnalyzerOpts
parameter_list|()
block|{
return|return
name|AnalyzerOpts
return|;
block|}
specifier|const
name|AnalyzerOptions
operator|&
name|getAnalyzerOpts
argument_list|()
specifier|const
block|{
return|return
name|AnalyzerOpts
return|;
block|}
name|CodeGenOptions
modifier|&
name|getCodeGenOpts
parameter_list|()
block|{
return|return
name|CodeGenOpts
return|;
block|}
specifier|const
name|CodeGenOptions
operator|&
name|getCodeGenOpts
argument_list|()
specifier|const
block|{
return|return
name|CodeGenOpts
return|;
block|}
name|DependencyOutputOptions
modifier|&
name|getDependencyOutputOpts
parameter_list|()
block|{
return|return
name|DependencyOutputOpts
return|;
block|}
specifier|const
name|DependencyOutputOptions
operator|&
name|getDependencyOutputOpts
argument_list|()
specifier|const
block|{
return|return
name|DependencyOutputOpts
return|;
block|}
name|DiagnosticOptions
modifier|&
name|getDiagnosticOpts
parameter_list|()
block|{
return|return
name|DiagnosticOpts
return|;
block|}
specifier|const
name|DiagnosticOptions
operator|&
name|getDiagnosticOpts
argument_list|()
specifier|const
block|{
return|return
name|DiagnosticOpts
return|;
block|}
name|HeaderSearchOptions
modifier|&
name|getHeaderSearchOpts
parameter_list|()
block|{
return|return
name|HeaderSearchOpts
return|;
block|}
specifier|const
name|HeaderSearchOptions
operator|&
name|getHeaderSearchOpts
argument_list|()
specifier|const
block|{
return|return
name|HeaderSearchOpts
return|;
block|}
name|FrontendOptions
modifier|&
name|getFrontendOpts
parameter_list|()
block|{
return|return
name|FrontendOpts
return|;
block|}
specifier|const
name|FrontendOptions
operator|&
name|getFrontendOpts
argument_list|()
specifier|const
block|{
return|return
name|FrontendOpts
return|;
block|}
name|LangOptions
modifier|&
name|getLangOpts
parameter_list|()
block|{
return|return
name|LangOpts
return|;
block|}
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
name|PreprocessorOptions
modifier|&
name|getPreprocessorOpts
parameter_list|()
block|{
return|return
name|PreprocessorOpts
return|;
block|}
specifier|const
name|PreprocessorOptions
operator|&
name|getPreprocessorOpts
argument_list|()
specifier|const
block|{
return|return
name|PreprocessorOpts
return|;
block|}
name|PreprocessorOutputOptions
modifier|&
name|getPreprocessorOutputOpts
parameter_list|()
block|{
return|return
name|PreprocessorOutputOpts
return|;
block|}
specifier|const
name|PreprocessorOutputOptions
operator|&
name|getPreprocessorOutputOpts
argument_list|()
specifier|const
block|{
return|return
name|PreprocessorOutputOpts
return|;
block|}
name|TargetOptions
modifier|&
name|getTargetOpts
parameter_list|()
block|{
return|return
name|TargetOpts
return|;
block|}
specifier|const
name|TargetOptions
operator|&
name|getTargetOpts
argument_list|()
specifier|const
block|{
return|return
name|TargetOpts
return|;
block|}
comment|/// @}
block|}
empty_stmt|;
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

