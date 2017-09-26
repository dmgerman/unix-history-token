begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DiagnosticRenderer.h - Diagnostic Pretty-Printing ------*- C++ -*-===//
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
comment|// This is a utility class that provides support for pretty-printing of
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
name|LLVM_CLANG_FRONTEND_DIAGNOSTICRENDERER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_DIAGNOSTICRENDERER_H
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
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
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
name|SourceManager
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|PointerUnion
operator|<
specifier|const
name|Diagnostic
operator|*
operator|,
specifier|const
name|StoredDiagnostic
operator|*
operator|>
name|DiagOrStoredDiag
expr_stmt|;
comment|/// \brief Class to encapsulate the logic for formatting a diagnostic message.
comment|///
comment|/// Actual "printing" logic is implemented by subclasses.
comment|///
comment|/// This class provides an interface for building and emitting
comment|/// diagnostic, including all of the macro backtraces, caret diagnostics, FixIt
comment|/// Hints, and code snippets. In the presence of macros this involves
comment|/// a recursive process, synthesizing notes for each macro expansion.
comment|///
comment|/// A brief worklist:
comment|/// FIXME: Sink the recursive printing of template instantiations into this
comment|/// class.
name|class
name|DiagnosticRenderer
block|{
name|protected
label|:
specifier|const
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticOptions
operator|>
name|DiagOpts
expr_stmt|;
comment|/// \brief The location of the previous diagnostic if known.
comment|///
comment|/// This will be invalid in cases where there is no (known) previous
comment|/// diagnostic location, or that location itself is invalid or comes from
comment|/// a different source manager than SM.
name|SourceLocation
name|LastLoc
decl_stmt|;
comment|/// \brief The location of the last include whose stack was printed if known.
comment|///
comment|/// Same restriction as LastLoc essentially, but tracking include stack
comment|/// root locations rather than diagnostic locations.
name|SourceLocation
name|LastIncludeLoc
decl_stmt|;
comment|/// \brief The level of the last diagnostic emitted.
comment|///
comment|/// The level of the last diagnostic emitted. Used to detect level changes
comment|/// which change the amount of information displayed.
name|DiagnosticsEngine
operator|::
name|Level
name|LastLevel
expr_stmt|;
name|DiagnosticRenderer
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|DiagnosticOptions
operator|*
name|DiagOpts
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|DiagnosticRenderer
argument_list|()
expr_stmt|;
name|virtual
name|void
name|emitDiagnosticMessage
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|PresumedLoc
name|PLoc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|,
name|StringRef
name|Message
argument_list|,
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|,
name|DiagOrStoredDiag
name|Info
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|emitDiagnosticLoc
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|PresumedLoc
name|PLoc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|,
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|emitCodeContext
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|,
name|SmallVectorImpl
operator|<
name|CharSourceRange
operator|>
operator|&
name|Ranges
argument_list|,
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|Hints
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|emitIncludeLocation
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|,
name|PresumedLoc
name|PLoc
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|emitImportLocation
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|,
name|PresumedLoc
name|PLoc
parameter_list|,
name|StringRef
name|ModuleName
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|emitBuildingModuleLocation
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|,
name|PresumedLoc
name|PLoc
parameter_list|,
name|StringRef
name|ModuleName
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|beginDiagnostic
argument_list|(
name|DiagOrStoredDiag
name|D
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|)
block|{}
name|virtual
name|void
name|endDiagnostic
argument_list|(
name|DiagOrStoredDiag
name|D
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|)
block|{}
name|private
label|:
name|void
name|emitBasicNote
parameter_list|(
name|StringRef
name|Message
parameter_list|)
function_decl|;
name|void
name|emitIncludeStack
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|PresumedLoc
name|PLoc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|)
decl_stmt|;
name|void
name|emitIncludeStackRecursively
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|)
function_decl|;
name|void
name|emitImportStack
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|)
function_decl|;
name|void
name|emitImportStackRecursively
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|,
name|StringRef
name|ModuleName
parameter_list|)
function_decl|;
name|void
name|emitModuleBuildStack
parameter_list|(
specifier|const
name|SourceManager
modifier|&
name|SM
parameter_list|)
function_decl|;
name|void
name|emitCaret
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|,
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|,
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|Hints
argument_list|)
decl_stmt|;
name|void
name|emitSingleMacroExpansion
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|,
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|)
decl_stmt|;
name|void
name|emitMacroExpansions
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|,
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|,
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|Hints
argument_list|)
decl_stmt|;
name|public
label|:
comment|/// \brief Emit a diagnostic.
comment|///
comment|/// This is the primary entry point for emitting diagnostic messages.
comment|/// It handles formatting and rendering the message as well as any ancillary
comment|/// information needed based on macros whose expansions impact the
comment|/// diagnostic.
comment|///
comment|/// \param Loc The location for this caret.
comment|/// \param Level The level of the diagnostic to be emitted.
comment|/// \param Message The diagnostic message to emit.
comment|/// \param Ranges The underlined ranges for this code snippet.
comment|/// \param FixItHints The FixIt hints active for this diagnostic.
name|void
name|emitDiagnostic
argument_list|(
name|FullSourceLoc
name|Loc
argument_list|,
name|DiagnosticsEngine
operator|::
name|Level
name|Level
argument_list|,
name|StringRef
name|Message
argument_list|,
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|,
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|FixItHints
argument_list|,
name|DiagOrStoredDiag
name|D
operator|=
operator|(
name|Diagnostic
operator|*
operator|)
name|nullptr
argument_list|)
decl_stmt|;
name|void
name|emitStoredDiagnostic
parameter_list|(
name|StoredDiagnostic
modifier|&
name|Diag
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Subclass of DiagnosticRender that turns all subdiagostics into explicit
comment|/// notes.  It is up to subclasses to further define the behavior.
name|class
name|DiagnosticNoteRenderer
range|:
name|public
name|DiagnosticRenderer
block|{
name|public
operator|:
name|DiagnosticNoteRenderer
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|DiagnosticOptions
operator|*
name|DiagOpts
argument_list|)
operator|:
name|DiagnosticRenderer
argument_list|(
argument|LangOpts
argument_list|,
argument|DiagOpts
argument_list|)
block|{}
operator|~
name|DiagnosticNoteRenderer
argument_list|()
name|override
block|;
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
name|virtual
name|void
name|emitNote
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|StringRef Message
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

