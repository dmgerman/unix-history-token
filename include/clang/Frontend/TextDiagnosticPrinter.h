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
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SourceManager
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|TextDiagnosticPrinter
range|:
name|public
name|DiagnosticClient
block|{
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
block|;
specifier|const
name|LangOptions
operator|*
name|LangOpts
block|;
name|SourceLocation
name|LastWarningLoc
block|;
name|FullSourceLoc
name|LastLoc
block|;
name|bool
name|LastCaretDiagnosticWasNote
block|;
name|bool
name|ShowColumn
block|;
name|bool
name|CaretDiagnostics
block|;
name|bool
name|ShowLocation
block|;
name|bool
name|PrintRangeInfo
block|;
name|bool
name|PrintDiagnosticOption
block|;
name|bool
name|PrintFixItInfo
block|;
name|unsigned
name|MessageLength
block|;
name|public
operator|:
name|TextDiagnosticPrinter
argument_list|(
argument|llvm::raw_ostream&os
argument_list|,
argument|bool showColumn = true
argument_list|,
argument|bool caretDiagnistics = true
argument_list|,
argument|bool showLocation = true
argument_list|,
argument|bool printRangeInfo = true
argument_list|,
argument|bool printDiagnosticOption = true
argument_list|,
argument|bool printFixItInfo = true
argument_list|,
argument|unsigned messageLength =
literal|0
argument_list|)
operator|:
name|OS
argument_list|(
name|os
argument_list|)
block|,
name|LangOpts
argument_list|(
literal|0
argument_list|)
block|,
name|LastCaretDiagnosticWasNote
argument_list|(
name|false
argument_list|)
block|,
name|ShowColumn
argument_list|(
name|showColumn
argument_list|)
block|,
name|CaretDiagnostics
argument_list|(
name|caretDiagnistics
argument_list|)
block|,
name|ShowLocation
argument_list|(
name|showLocation
argument_list|)
block|,
name|PrintRangeInfo
argument_list|(
name|printRangeInfo
argument_list|)
block|,
name|PrintDiagnosticOption
argument_list|(
name|printDiagnosticOption
argument_list|)
block|,
name|PrintFixItInfo
argument_list|(
name|printFixItInfo
argument_list|)
block|,
name|MessageLength
argument_list|(
argument|messageLength
argument_list|)
block|{}
name|void
name|setLangOptions
argument_list|(
argument|const LangOptions *LO
argument_list|)
block|{
name|LangOpts
operator|=
name|LO
block|;   }
name|void
name|PrintIncludeStack
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const SourceManager&SM
argument_list|)
block|;
name|void
name|HighlightRange
argument_list|(
argument|const SourceRange&R
argument_list|,
argument|const SourceManager&SrcMgr
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|FileID FID
argument_list|,
argument|std::string&CaretLine
argument_list|,
argument|const std::string&SourceLine
argument_list|)
block|;
name|void
name|EmitCaretDiagnostic
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceRange *Ranges
argument_list|,
argument|unsigned NumRanges
argument_list|,
argument|SourceManager&SM
argument_list|,
argument|const CodeModificationHint *Hints
argument_list|,
argument|unsigned NumHints
argument_list|,
argument|unsigned Columns
argument_list|)
block|;
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|Diagnostic::Level DiagLevel
argument_list|,
argument|const DiagnosticInfo&Info
argument_list|)
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

