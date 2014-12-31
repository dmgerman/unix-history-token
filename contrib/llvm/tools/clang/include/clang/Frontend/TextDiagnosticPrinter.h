begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TextDiagnosticPrinter.h - Text Diagnostic Client -------*- C++ -*-===//
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
comment|// This is a concrete diagnostic client, which prints the diagnostics to
end_comment

begin_comment
comment|// standard error.
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
name|LLVM_CLANG_FRONTEND_TEXT_DIAGNOSTIC_PRINTER_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_TEXT_DIAGNOSTIC_PRINTER_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|TextDiagnostic
decl_stmt|;
name|class
name|TextDiagnosticPrinter
range|:
name|public
name|DiagnosticConsumer
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticOptions
operator|>
name|DiagOpts
block|;
comment|/// \brief Handle to the currently active text diagnostic emitter.
name|std
operator|::
name|unique_ptr
operator|<
name|TextDiagnostic
operator|>
name|TextDiag
block|;
comment|/// A string to prefix to error messages.
name|std
operator|::
name|string
name|Prefix
block|;
name|unsigned
name|OwnsOutputStream
operator|:
literal|1
block|;
name|public
operator|:
name|TextDiagnosticPrinter
argument_list|(
argument|raw_ostream&os
argument_list|,
argument|DiagnosticOptions *diags
argument_list|,
argument|bool OwnsOutputStream = false
argument_list|)
block|;
name|virtual
operator|~
name|TextDiagnosticPrinter
argument_list|()
block|;
comment|/// setPrefix - Set the diagnostic printer prefix string, which will be
comment|/// printed at the start of any diagnostics. If empty, no prefix string is
comment|/// used.
name|void
name|setPrefix
argument_list|(
argument|std::string Value
argument_list|)
block|{
name|Prefix
operator|=
name|Value
block|; }
name|void
name|BeginSourceFile
argument_list|(
argument|const LangOptions&LO
argument_list|,
argument|const Preprocessor *PP
argument_list|)
name|override
block|;
name|void
name|EndSourceFile
argument_list|()
name|override
block|;
name|void
name|HandleDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|const Diagnostic&Info
argument_list|)
name|override
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

