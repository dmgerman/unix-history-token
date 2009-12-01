begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Options.h - clang-cc Option Handling --------------------*- C++ -*-===//
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
name|LLVM_CLANGCC_OPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANGCC_OPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendOptions.h"
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
name|AnalyzerOptions
decl_stmt|;
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|DependencyOutputOptions
decl_stmt|;
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|FrontendOptions
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|PreprocessorOutputOptions
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|void
name|InitializeAnalyzerOptions
parameter_list|(
name|AnalyzerOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|InitializeCodeGenOptions
parameter_list|(
name|CodeGenOptions
modifier|&
name|Opts
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|Lang
parameter_list|)
function_decl|;
name|void
name|InitializeDependencyOutputOptions
parameter_list|(
name|DependencyOutputOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|InitializeDiagnosticOptions
parameter_list|(
name|DiagnosticOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|InitializeFrontendOptions
parameter_list|(
name|FrontendOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|InitializeHeaderSearchOptions
argument_list|(
name|HeaderSearchOptions
operator|&
name|Opts
argument_list|,
name|llvm
operator|::
name|StringRef
name|BuiltinIncludePath
argument_list|)
decl_stmt|;
name|void
name|InitializeLangOptions
argument_list|(
name|LangOptions
operator|&
name|Options
argument_list|,
name|FrontendOptions
operator|::
name|InputKind
name|LK
argument_list|)
decl_stmt|;
name|void
name|InitializePreprocessorOptions
parameter_list|(
name|PreprocessorOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|InitializePreprocessorOutputOptions
parameter_list|(
name|PreprocessorOutputOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|InitializeTargetOptions
parameter_list|(
name|TargetOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
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

