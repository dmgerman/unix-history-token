begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TextDiagnostic.h - Text Diagnostic Pretty-Printing -----*- C++ -*-===//
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
comment|// This is a utility class that provides support for textual pretty-printing of
end_comment

begin_comment
comment|// diagnostics. It is used to implement the different code paths which require
end_comment

begin_comment
comment|// such functionality in a consistent way.
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
name|LLVM_CLANG_FRONTEND_TEXTDIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_TEXTDIAGNOSTIC_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/DiagnosticRenderer.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Class to encapsulate the logic for formatting and printing a textual
comment|/// diagnostic message.
comment|///
comment|/// This class provides an interface for building and emitting a textual
comment|/// diagnostic, including all of the macro backtraces, caret diagnostics, FixIt
comment|/// Hints, and code snippets. In the presence of macros this involves
comment|/// a recursive process, synthesizing notes for each macro expansion.
comment|///
comment|/// The purpose of this class is to isolate the implementation of printing
comment|/// beautiful text diagnostics from any particular interfaces. The Clang
comment|/// DiagnosticClient is implemented through this class as is diagnostic
comment|/// printing coming out of libclang.
name|class
name|TextDiagnostic
range|:
name|public
name|DiagnosticRenderer
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|TextDiagnostic
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|DiagnosticOptions
operator|*
name|DiagOpts
argument_list|)
block|;
operator|~
name|TextDiagnostic
argument_list|()
name|override
block|;
comment|/// \brief Print the diagonstic level to a raw_ostream.
comment|///
comment|/// This is a static helper that handles colorizing the level and formatting
comment|/// it into an arbitrary output stream. This is used internally by the
comment|/// TextDiagnostic emission code, but it can also be used directly by
comment|/// consumers that don't have a source manager or other state that the full
comment|/// TextDiagnostic logic requires.
specifier|static
name|void
name|printDiagnosticLevel
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|bool ShowColors
argument_list|,
argument|bool CLFallbackMode = false
argument_list|)
block|;
comment|/// \brief Pretty-print a diagnostic message to a raw_ostream.
comment|///
comment|/// This is a static helper to handle the line wrapping, colorizing, and
comment|/// rendering of a diagnostic message to a particular ostream. It is
comment|/// publicly visible so that clients which do not have sufficient state to
comment|/// build a complete TextDiagnostic object can still get consistent
comment|/// formatting of their diagnostic messages.
comment|///
comment|/// \param OS Where the message is printed
comment|/// \param IsSupplemental true if this is a continuation note diagnostic
comment|/// \param Message The text actually printed
comment|/// \param CurrentColumn The starting column of the first line, accounting
comment|///                      for any prefix.
comment|/// \param Columns The number of columns to use in line-wrapping, 0 disables
comment|///                all line-wrapping.
comment|/// \param ShowColors Enable colorizing of the message.
specifier|static
name|void
name|printDiagnosticMessage
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool IsSupplemental
argument_list|,
argument|StringRef Message
argument_list|,
argument|unsigned CurrentColumn
argument_list|,
argument|unsigned Columns
argument_list|,
argument|bool ShowColors
argument_list|)
block|;
name|protected
operator|:
name|void
name|emitDiagnosticMessage
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|PresumedLoc PLoc
argument_list|,
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|StringRef Message
argument_list|,
argument|ArrayRef<CharSourceRange> Ranges
argument_list|,
argument|DiagOrStoredDiag D
argument_list|)
name|override
block|;
name|void
name|emitDiagnosticLoc
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|PresumedLoc PLoc
argument_list|,
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|ArrayRef<CharSourceRange> Ranges
argument_list|)
name|override
block|;
name|void
name|emitCodeContext
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|SmallVectorImpl<CharSourceRange>&Ranges
argument_list|,
argument|ArrayRef<FixItHint> Hints
argument_list|)
name|override
block|{
name|emitSnippetAndCaret
argument_list|(
name|Loc
argument_list|,
name|Level
argument_list|,
name|Ranges
argument_list|,
name|Hints
argument_list|)
block|;   }
name|void
name|emitIncludeLocation
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|PresumedLoc PLoc
argument_list|)
name|override
block|;
name|void
name|emitImportLocation
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|PresumedLoc PLoc
argument_list|,
argument|StringRef ModuleName
argument_list|)
name|override
block|;
name|void
name|emitBuildingModuleLocation
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|PresumedLoc PLoc
argument_list|,
argument|StringRef ModuleName
argument_list|)
name|override
block|;
name|private
operator|:
name|void
name|emitFilename
argument_list|(
argument|StringRef Filename
argument_list|,
argument|const SourceManager&SM
argument_list|)
block|;
name|void
name|emitSnippetAndCaret
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|SmallVectorImpl<CharSourceRange>&Ranges
argument_list|,
argument|ArrayRef<FixItHint> Hints
argument_list|)
block|;
name|void
name|emitSnippet
argument_list|(
argument|StringRef SourceLine
argument_list|)
block|;
name|void
name|emitParseableFixits
argument_list|(
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|Hints
argument_list|,
specifier|const
name|SourceManager
operator|&
name|SM
argument_list|)
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

