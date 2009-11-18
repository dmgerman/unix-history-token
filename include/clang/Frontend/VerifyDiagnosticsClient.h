begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- VerifyDiagnosticsClient.h - Verifying Diagnostic Client -*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_VERIFYDIAGNOSTICSCLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_VERIFYDIAGNOSTICSCLIENT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Diagnostic
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|TextDiagnosticBuffer
decl_stmt|;
comment|/// VerifyDiagnosticsClient - Create a diagnostic client which will use markers
comment|/// in the input source to check that all the emitted diagnostics match those
comment|/// expected.
comment|///
comment|/// USING THE DIAGNOSTIC CHECKER:
comment|///
comment|/// Indicating that a line expects an error or a warning is simple. Put a
comment|/// comment on the line that has the diagnostic, use "expected-{error,warning}"
comment|/// to tag if it's an expected error or warning, and place the expected text
comment|/// between {{ and }} markers. The full text doesn't have to be included, only
comment|/// enough to ensure that the correct diagnostic was emitted.
comment|///
comment|/// Here's an example:
comment|///
comment|///   int A = B; // expected-error {{use of undeclared identifier 'B'}}
comment|///
comment|/// You can place as many diagnostics on one line as you wish. To make the code
comment|/// more readable, you can use slash-newline to separate out the diagnostics.
comment|///
comment|/// The simple syntax above allows each specification to match exactly one
comment|/// error.  You can use the extended syntax to customize this. The extended
comment|/// syntax is "expected-<type><n> {{diag text}}", where<type> is one of
comment|/// "error", "warning" or "note", and<n> is a positive integer. This allows the
comment|/// diagnostic to appear as many times as specified. Example:
comment|///
comment|///   void f(); // expected-note 2 {{previous declaration is here}}
comment|///
name|class
name|VerifyDiagnosticsClient
range|:
name|public
name|DiagnosticClient
block|{
name|public
operator|:
name|Diagnostic
operator|&
name|Diags
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|DiagnosticClient
operator|>
name|PrimaryClient
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|TextDiagnosticBuffer
operator|>
name|Buffer
block|;
name|Preprocessor
operator|*
name|CurrentPreprocessor
block|;
name|unsigned
name|NumErrors
block|;
name|private
operator|:
name|void
name|CheckDiagnostics
argument_list|()
block|;
name|public
operator|:
comment|/// Create a new verifying diagnostic client, which will issue errors to \arg
comment|/// PrimaryClient when a diagnostic does not match what is expected (as
comment|/// indicated in the source file). The verifying diagnostic client takes
comment|/// ownership of \arg PrimaryClient.
name|VerifyDiagnosticsClient
argument_list|(
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|DiagnosticClient
operator|*
name|PrimaryClient
argument_list|)
block|;
operator|~
name|VerifyDiagnosticsClient
argument_list|()
block|;
name|virtual
name|void
name|BeginSourceFile
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
specifier|const
name|Preprocessor
operator|*
name|PP
argument_list|)
block|;
name|virtual
name|void
name|EndSourceFile
argument_list|()
block|;
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|Diagnostic::Level DiagLevel
argument_list|,
argument|const DiagnosticInfo&Info
argument_list|)
block|;
comment|/// HadErrors - Check if there were any mismatches in expected diagnostics.
name|bool
name|HadErrors
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namspace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

