begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Utils.h - Misc utilities for the front-end------------------------===//
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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|raw_fd_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|MinimalAction
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|IdentifierTable
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|PreprocessorFactory
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
comment|/// ProcessWarningOptions - Initialize the diagnostic client and process the
comment|/// warning options specified on the command line.
name|bool
name|ProcessWarningOptions
argument_list|(
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Warnings
argument_list|,
name|bool
name|Pedantic
argument_list|,
name|bool
name|PedanticErrors
argument_list|,
name|bool
name|NoWarnings
argument_list|)
decl_stmt|;
comment|/// DoPrintPreprocessedInput - Implement -E -dM mode.
name|void
name|DoPrintMacros
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
name|bool
name|EnableCommentOutput
argument_list|,
name|bool
name|EnableMacroCommentOutput
argument_list|,
name|bool
name|DisableLineMarkers
argument_list|,
name|bool
name|DumpDefines
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
argument_list|(
name|Preprocessor
operator|*
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Targets
argument_list|,
name|bool
name|IncludeSystemHeaders
argument_list|,
name|bool
name|PhonyTarget
argument_list|)
decl_stmt|;
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

