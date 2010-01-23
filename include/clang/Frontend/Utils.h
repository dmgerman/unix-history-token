begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Utils.h - Misc utilities for the front-end -------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|//  This header contains miscellaneous utilities for various front-end actions.
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
name|LLVM_CLANG_FRONTEND_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_UTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Triple
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DependencyOutputOptions
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|IdentifierTable
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|MinimalAction
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|PreprocessorOutputOptions
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|FrontendOptions
decl_stmt|;
comment|/// Normalize \arg File for use in a user defined #include directive (in the
comment|/// predefines buffer).
name|std
operator|::
name|string
name|NormalizeDashIncludePath
argument_list|(
argument|llvm::StringRef File
argument_list|)
expr_stmt|;
comment|/// Apply the header search options to get given HeaderSearch object.
name|void
name|ApplyHeaderSearchOptions
argument_list|(
name|HeaderSearch
operator|&
name|HS
argument_list|,
specifier|const
name|HeaderSearchOptions
operator|&
name|HSOpts
argument_list|,
specifier|const
name|LangOptions
operator|&
name|Lang
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|/// InitializePreprocessor - Initialize the preprocessor getting it and the
comment|/// environment ready to process a single file.
name|void
name|InitializePreprocessor
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|PreprocessorOptions
modifier|&
name|PPOpts
parameter_list|,
specifier|const
name|HeaderSearchOptions
modifier|&
name|HSOpts
parameter_list|,
specifier|const
name|FrontendOptions
modifier|&
name|FEOpts
parameter_list|)
function_decl|;
comment|/// ProcessWarningOptions - Initialize the diagnostic client and process the
comment|/// warning options specified on the command line.
name|bool
name|ProcessWarningOptions
parameter_list|(
name|Diagnostic
modifier|&
name|Diags
parameter_list|,
specifier|const
name|DiagnosticOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
comment|/// DoPrintPreprocessedInput - Implement -E mode.
name|void
name|DoPrintPreprocessedInput
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|,
specifier|const
name|PreprocessorOutputOptions
operator|&
name|Opts
argument_list|)
decl_stmt|;
comment|/// RewriteMacrosInInput - Implement -rewrite-macros mode.
name|void
name|RewriteMacrosInInput
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|/// RewriteMacrosInInput - A simple test for the TokenRewriter class.
name|void
name|DoRewriteTest
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|/// CreatePrintParserActionsAction - Return the actions implementation that
comment|/// implements the -parse-print-callbacks option.
name|MinimalAction
modifier|*
name|CreatePrintParserActionsAction
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|/// CheckDiagnostics - Gather the expected diagnostics and check them.
name|bool
name|CheckDiagnostics
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|)
function_decl|;
comment|/// AttachDependencyFileGen - Create a dependency file generator, and attach
comment|/// it to the given preprocessor.  This takes ownership of the output stream.
name|void
name|AttachDependencyFileGen
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|DependencyOutputOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
comment|/// CacheTokens - Cache tokens for use with PCH. Note that this requires
comment|/// a seekable stream.
name|void
name|CacheTokens
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_fd_ostream
operator|*
name|OS
argument_list|)
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

