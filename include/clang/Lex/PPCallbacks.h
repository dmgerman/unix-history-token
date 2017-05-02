begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PPCallbacks.h - Callbacks for Preprocessor actions -----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the PPCallbacks interface.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LEX_PPCALLBACKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PPCALLBACKS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/DiagnosticIDs.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/ModuleLoader.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/Pragma.h"
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
name|Token
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|MacroDefinition
decl_stmt|;
name|class
name|MacroDirective
decl_stmt|;
name|class
name|MacroArgs
decl_stmt|;
comment|/// \brief This interface provides a way to observe the actions of the
comment|/// preprocessor as it does its thing.
comment|///
comment|/// Clients can define their hooks here to implement preprocessor level tools.
name|class
name|PPCallbacks
block|{
name|public
label|:
name|virtual
operator|~
name|PPCallbacks
argument_list|()
expr_stmt|;
enum|enum
name|FileChangeReason
block|{
name|EnterFile
block|,
name|ExitFile
block|,
name|SystemHeaderPragma
block|,
name|RenameFile
block|}
enum|;
comment|/// \brief Callback invoked whenever a source file is entered or exited.
comment|///
comment|/// \param Loc Indicates the new location.
comment|/// \param PrevFID the file that was exited if \p Reason is ExitFile.
name|virtual
name|void
name|FileChanged
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|FileChangeReason
name|Reason
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileType
argument_list|,
name|FileID
name|PrevFID
operator|=
name|FileID
argument_list|()
argument_list|)
block|{   }
comment|/// \brief Callback invoked whenever a source file is skipped as the result
comment|/// of header guard optimization.
comment|///
comment|/// \param SkippedFile The file that is skipped instead of entering \#include
comment|///
comment|/// \param FilenameTok The file name token in \#include "FileName" directive
comment|/// or macro expanded file name token from \#include MACRO(PARAMS) directive.
comment|/// Note that FilenameTok contains corresponding quotes/angles symbols.
name|virtual
name|void
name|FileSkipped
argument_list|(
specifier|const
name|FileEntry
operator|&
name|SkippedFile
argument_list|,
specifier|const
name|Token
operator|&
name|FilenameTok
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileType
argument_list|)
block|{   }
comment|/// \brief Callback invoked whenever an inclusion directive results in a
comment|/// file-not-found error.
comment|///
comment|/// \param FileName The name of the file being included, as written in the
comment|/// source code.
comment|///
comment|/// \param RecoveryPath If this client indicates that it can recover from
comment|/// this missing file, the client should set this as an additional header
comment|/// search patch.
comment|///
comment|/// \returns true to indicate that the preprocessor should attempt to recover
comment|/// by adding \p RecoveryPath as a header search path.
name|virtual
name|bool
name|FileNotFound
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|RecoveryPath
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Callback invoked whenever an inclusion directive of
comment|/// any kind (\c \#include, \c \#import, etc.) has been processed, regardless
comment|/// of whether the inclusion will actually result in an inclusion.
comment|///
comment|/// \param HashLoc The location of the '#' that starts the inclusion
comment|/// directive.
comment|///
comment|/// \param IncludeTok The token that indicates the kind of inclusion
comment|/// directive, e.g., 'include' or 'import'.
comment|///
comment|/// \param FileName The name of the file being included, as written in the
comment|/// source code.
comment|///
comment|/// \param IsAngled Whether the file name was enclosed in angle brackets;
comment|/// otherwise, it was enclosed in quotes.
comment|///
comment|/// \param FilenameRange The character range of the quotes or angle brackets
comment|/// for the written file name.
comment|///
comment|/// \param File The actual file that may be included by this inclusion
comment|/// directive.
comment|///
comment|/// \param SearchPath Contains the search path which was used to find the file
comment|/// in the file system. If the file was found via an absolute include path,
comment|/// SearchPath will be empty. For framework includes, the SearchPath and
comment|/// RelativePath will be split up. For example, if an include of "Some/Some.h"
comment|/// is found via the framework path
comment|/// "path/to/Frameworks/Some.framework/Headers/Some.h", SearchPath will be
comment|/// "path/to/Frameworks/Some.framework/Headers" and RelativePath will be
comment|/// "Some.h".
comment|///
comment|/// \param RelativePath The path relative to SearchPath, at which the include
comment|/// file was found. This is equal to FileName except for framework includes.
comment|///
comment|/// \param Imported The module, whenever an inclusion directive was
comment|/// automatically turned into a module import or null otherwise.
comment|///
name|virtual
name|void
name|InclusionDirective
parameter_list|(
name|SourceLocation
name|HashLoc
parameter_list|,
specifier|const
name|Token
modifier|&
name|IncludeTok
parameter_list|,
name|StringRef
name|FileName
parameter_list|,
name|bool
name|IsAngled
parameter_list|,
name|CharSourceRange
name|FilenameRange
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|StringRef
name|SearchPath
parameter_list|,
name|StringRef
name|RelativePath
parameter_list|,
specifier|const
name|Module
modifier|*
name|Imported
parameter_list|)
block|{   }
comment|/// \brief Callback invoked whenever there was an explicit module-import
comment|/// syntax.
comment|///
comment|/// \param ImportLoc The location of import directive token.
comment|///
comment|/// \param Path The identifiers (and their locations) of the module
comment|/// "path", e.g., "std.vector" would be split into "std" and "vector".
comment|///
comment|/// \param Imported The imported module; can be null if importing failed.
comment|///
name|virtual
name|void
name|moduleImport
parameter_list|(
name|SourceLocation
name|ImportLoc
parameter_list|,
name|ModuleIdPath
name|Path
parameter_list|,
specifier|const
name|Module
modifier|*
name|Imported
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when the end of the main file is reached.
comment|///
comment|/// No subsequent callbacks will be made.
name|virtual
name|void
name|EndOfMainFile
parameter_list|()
block|{   }
comment|/// \brief Callback invoked when a \#ident or \#sccs directive is read.
comment|/// \param Loc The location of the directive.
comment|/// \param str The text of the directive.
comment|///
name|virtual
name|void
name|Ident
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|str
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when start reading any pragma directive.
name|virtual
name|void
name|PragmaDirective
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|PragmaIntroducerKind
name|Introducer
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma comment directive is read.
name|virtual
name|void
name|PragmaComment
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Kind
parameter_list|,
name|StringRef
name|Str
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma detect_mismatch directive is
comment|/// read.
name|virtual
name|void
name|PragmaDetectMismatch
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|Value
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma clang __debug directive is read.
comment|/// \param Loc The location of the debug directive.
comment|/// \param DebugType The identifier following __debug.
name|virtual
name|void
name|PragmaDebug
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|DebugType
parameter_list|)
block|{   }
comment|/// \brief Determines the kind of \#pragma invoking a call to PragmaMessage.
enum|enum
name|PragmaMessageKind
block|{
comment|/// \brief \#pragma message has been invoked.
name|PMK_Message
block|,
comment|/// \brief \#pragma GCC warning has been invoked.
name|PMK_Warning
block|,
comment|/// \brief \#pragma GCC error has been invoked.
name|PMK_Error
block|}
enum|;
comment|/// \brief Callback invoked when a \#pragma message directive is read.
comment|/// \param Loc The location of the message directive.
comment|/// \param Namespace The namespace of the message directive.
comment|/// \param Kind The type of the message directive.
comment|/// \param Str The text of the message directive.
name|virtual
name|void
name|PragmaMessage
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|Namespace
parameter_list|,
name|PragmaMessageKind
name|Kind
parameter_list|,
name|StringRef
name|Str
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma gcc diagnostic push directive
comment|/// is read.
name|virtual
name|void
name|PragmaDiagnosticPush
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|Namespace
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma gcc diagnostic pop directive
comment|/// is read.
name|virtual
name|void
name|PragmaDiagnosticPop
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|Namespace
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma gcc diagnostic directive is read.
name|virtual
name|void
name|PragmaDiagnostic
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|StringRef
name|Namespace
argument_list|,
name|diag
operator|::
name|Severity
name|mapping
argument_list|,
name|StringRef
name|Str
argument_list|)
block|{}
comment|/// \brief Called when an OpenCL extension is either disabled or
comment|/// enabled with a pragma.
name|virtual
name|void
name|PragmaOpenCLExtension
parameter_list|(
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|StateLoc
parameter_list|,
name|unsigned
name|State
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma warning directive is read.
name|virtual
name|void
name|PragmaWarning
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|StringRef
name|WarningSpec
argument_list|,
name|ArrayRef
operator|<
name|int
operator|>
name|Ids
argument_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma warning(push) directive is read.
name|virtual
name|void
name|PragmaWarningPush
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|int
name|Level
parameter_list|)
block|{   }
comment|/// \brief Callback invoked when a \#pragma warning(pop) directive is read.
name|virtual
name|void
name|PragmaWarningPop
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{   }
comment|/// \brief Called by Preprocessor::HandleMacroExpandedIdentifier when a
comment|/// macro invocation is found.
name|virtual
name|void
name|MacroExpands
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDefinition
modifier|&
name|MD
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
specifier|const
name|MacroArgs
modifier|*
name|Args
parameter_list|)
block|{}
comment|/// \brief Hook called whenever a macro definition is seen.
name|virtual
name|void
name|MacroDefined
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|)
block|{   }
comment|/// \brief Hook called whenever a macro \#undef is seen.
comment|/// \param MacroNameTok The active Token
comment|/// \param MD A MacroDefinition for the named macro.
comment|/// \param Undef New MacroDirective if the macro was defined, null otherwise.
comment|///
comment|/// MD is released immediately following this callback.
name|virtual
name|void
name|MacroUndefined
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDefinition
modifier|&
name|MD
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|Undef
parameter_list|)
block|{   }
comment|/// \brief Hook called whenever the 'defined' operator is seen.
comment|/// \param MD The MacroDirective if the name was a macro, null otherwise.
name|virtual
name|void
name|Defined
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDefinition
modifier|&
name|MD
parameter_list|,
name|SourceRange
name|Range
parameter_list|)
block|{   }
comment|/// \brief Hook called when a source range is skipped.
comment|/// \param Range The SourceRange that was skipped. The range begins at the
comment|/// \#if/\#else directive and ends after the \#endif/\#else directive.
name|virtual
name|void
name|SourceRangeSkipped
parameter_list|(
name|SourceRange
name|Range
parameter_list|)
block|{   }
enum|enum
name|ConditionValueKind
block|{
name|CVK_NotEvaluated
block|,
name|CVK_False
block|,
name|CVK_True
block|}
enum|;
comment|/// \brief Hook called whenever an \#if is seen.
comment|/// \param Loc the source location of the directive.
comment|/// \param ConditionRange The SourceRange of the expression being tested.
comment|/// \param ConditionValue The evaluated value of the condition.
comment|///
comment|// FIXME: better to pass in a list (or tree!) of Tokens.
name|virtual
name|void
name|If
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|ConditionRange
parameter_list|,
name|ConditionValueKind
name|ConditionValue
parameter_list|)
block|{   }
comment|/// \brief Hook called whenever an \#elif is seen.
comment|/// \param Loc the source location of the directive.
comment|/// \param ConditionRange The SourceRange of the expression being tested.
comment|/// \param ConditionValue The evaluated value of the condition.
comment|/// \param IfLoc the source location of the \#if/\#ifdef/\#ifndef directive.
comment|// FIXME: better to pass in a list (or tree!) of Tokens.
name|virtual
name|void
name|Elif
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|ConditionRange
parameter_list|,
name|ConditionValueKind
name|ConditionValue
parameter_list|,
name|SourceLocation
name|IfLoc
parameter_list|)
block|{   }
comment|/// \brief Hook called whenever an \#ifdef is seen.
comment|/// \param Loc the source location of the directive.
comment|/// \param MacroNameTok Information on the token being tested.
comment|/// \param MD The MacroDefinition if the name was a macro, null otherwise.
name|virtual
name|void
name|Ifdef
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDefinition
modifier|&
name|MD
parameter_list|)
block|{   }
comment|/// \brief Hook called whenever an \#ifndef is seen.
comment|/// \param Loc the source location of the directive.
comment|/// \param MacroNameTok Information on the token being tested.
comment|/// \param MD The MacroDefiniton if the name was a macro, null otherwise.
name|virtual
name|void
name|Ifndef
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDefinition
modifier|&
name|MD
parameter_list|)
block|{   }
comment|/// \brief Hook called whenever an \#else is seen.
comment|/// \param Loc the source location of the directive.
comment|/// \param IfLoc the source location of the \#if/\#ifdef/\#ifndef directive.
name|virtual
name|void
name|Else
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|SourceLocation
name|IfLoc
parameter_list|)
block|{   }
comment|/// \brief Hook called whenever an \#endif is seen.
comment|/// \param Loc the source location of the directive.
comment|/// \param IfLoc the source location of the \#if/\#ifdef/\#ifndef directive.
name|virtual
name|void
name|Endif
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|SourceLocation
name|IfLoc
parameter_list|)
block|{   }
block|}
empty_stmt|;
comment|/// \brief Simple wrapper class for chaining callbacks.
name|class
name|PPChainedCallbacks
range|:
name|public
name|PPCallbacks
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|PPCallbacks
operator|>
name|First
block|,
name|Second
block|;
name|public
operator|:
name|PPChainedCallbacks
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|PPCallbacks
operator|>
name|_First
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|PPCallbacks
operator|>
name|_Second
argument_list|)
operator|:
name|First
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|_First
argument_list|)
argument_list|)
block|,
name|Second
argument_list|(
argument|std::move(_Second)
argument_list|)
block|{}
name|void
name|FileChanged
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|FileChangeReason Reason
argument_list|,
argument|SrcMgr::CharacteristicKind FileType
argument_list|,
argument|FileID PrevFID
argument_list|)
name|override
block|{
name|First
operator|->
name|FileChanged
argument_list|(
name|Loc
argument_list|,
name|Reason
argument_list|,
name|FileType
argument_list|,
name|PrevFID
argument_list|)
block|;
name|Second
operator|->
name|FileChanged
argument_list|(
name|Loc
argument_list|,
name|Reason
argument_list|,
name|FileType
argument_list|,
name|PrevFID
argument_list|)
block|;   }
name|void
name|FileSkipped
argument_list|(
argument|const FileEntry&SkippedFile
argument_list|,
argument|const Token&FilenameTok
argument_list|,
argument|SrcMgr::CharacteristicKind FileType
argument_list|)
name|override
block|{
name|First
operator|->
name|FileSkipped
argument_list|(
name|SkippedFile
argument_list|,
name|FilenameTok
argument_list|,
name|FileType
argument_list|)
block|;
name|Second
operator|->
name|FileSkipped
argument_list|(
name|SkippedFile
argument_list|,
name|FilenameTok
argument_list|,
name|FileType
argument_list|)
block|;   }
name|bool
name|FileNotFound
argument_list|(
argument|StringRef FileName
argument_list|,
argument|SmallVectorImpl<char>&RecoveryPath
argument_list|)
name|override
block|{
return|return
name|First
operator|->
name|FileNotFound
argument_list|(
name|FileName
argument_list|,
name|RecoveryPath
argument_list|)
operator|||
name|Second
operator|->
name|FileNotFound
argument_list|(
name|FileName
argument_list|,
name|RecoveryPath
argument_list|)
return|;
block|}
name|void
name|InclusionDirective
argument_list|(
argument|SourceLocation HashLoc
argument_list|,
argument|const Token&IncludeTok
argument_list|,
argument|StringRef FileName
argument_list|,
argument|bool IsAngled
argument_list|,
argument|CharSourceRange FilenameRange
argument_list|,
argument|const FileEntry *File
argument_list|,
argument|StringRef SearchPath
argument_list|,
argument|StringRef RelativePath
argument_list|,
argument|const Module *Imported
argument_list|)
name|override
block|{
name|First
operator|->
name|InclusionDirective
argument_list|(
name|HashLoc
argument_list|,
name|IncludeTok
argument_list|,
name|FileName
argument_list|,
name|IsAngled
argument_list|,
name|FilenameRange
argument_list|,
name|File
argument_list|,
name|SearchPath
argument_list|,
name|RelativePath
argument_list|,
name|Imported
argument_list|)
block|;
name|Second
operator|->
name|InclusionDirective
argument_list|(
name|HashLoc
argument_list|,
name|IncludeTok
argument_list|,
name|FileName
argument_list|,
name|IsAngled
argument_list|,
name|FilenameRange
argument_list|,
name|File
argument_list|,
name|SearchPath
argument_list|,
name|RelativePath
argument_list|,
name|Imported
argument_list|)
block|;   }
name|void
name|moduleImport
argument_list|(
argument|SourceLocation ImportLoc
argument_list|,
argument|ModuleIdPath Path
argument_list|,
argument|const Module *Imported
argument_list|)
name|override
block|{
name|First
operator|->
name|moduleImport
argument_list|(
name|ImportLoc
argument_list|,
name|Path
argument_list|,
name|Imported
argument_list|)
block|;
name|Second
operator|->
name|moduleImport
argument_list|(
name|ImportLoc
argument_list|,
name|Path
argument_list|,
name|Imported
argument_list|)
block|;   }
name|void
name|EndOfMainFile
argument_list|()
name|override
block|{
name|First
operator|->
name|EndOfMainFile
argument_list|()
block|;
name|Second
operator|->
name|EndOfMainFile
argument_list|()
block|;   }
name|void
name|Ident
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|StringRef str
argument_list|)
name|override
block|{
name|First
operator|->
name|Ident
argument_list|(
name|Loc
argument_list|,
name|str
argument_list|)
block|;
name|Second
operator|->
name|Ident
argument_list|(
name|Loc
argument_list|,
name|str
argument_list|)
block|;   }
name|void
name|PragmaComment
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const IdentifierInfo *Kind
argument_list|,
argument|StringRef Str
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaComment
argument_list|(
name|Loc
argument_list|,
name|Kind
argument_list|,
name|Str
argument_list|)
block|;
name|Second
operator|->
name|PragmaComment
argument_list|(
name|Loc
argument_list|,
name|Kind
argument_list|,
name|Str
argument_list|)
block|;   }
name|void
name|PragmaDetectMismatch
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|StringRef Name
argument_list|,
argument|StringRef Value
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaDetectMismatch
argument_list|(
name|Loc
argument_list|,
name|Name
argument_list|,
name|Value
argument_list|)
block|;
name|Second
operator|->
name|PragmaDetectMismatch
argument_list|(
name|Loc
argument_list|,
name|Name
argument_list|,
name|Value
argument_list|)
block|;   }
name|void
name|PragmaMessage
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|StringRef Namespace
argument_list|,
argument|PragmaMessageKind Kind
argument_list|,
argument|StringRef Str
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaMessage
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|,
name|Kind
argument_list|,
name|Str
argument_list|)
block|;
name|Second
operator|->
name|PragmaMessage
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|,
name|Kind
argument_list|,
name|Str
argument_list|)
block|;   }
name|void
name|PragmaDiagnosticPush
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|StringRef Namespace
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaDiagnosticPush
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|)
block|;
name|Second
operator|->
name|PragmaDiagnosticPush
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|)
block|;   }
name|void
name|PragmaDiagnosticPop
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|StringRef Namespace
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaDiagnosticPop
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|)
block|;
name|Second
operator|->
name|PragmaDiagnosticPop
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|)
block|;   }
name|void
name|PragmaDiagnostic
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|StringRef Namespace
argument_list|,
argument|diag::Severity mapping
argument_list|,
argument|StringRef Str
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaDiagnostic
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|,
name|mapping
argument_list|,
name|Str
argument_list|)
block|;
name|Second
operator|->
name|PragmaDiagnostic
argument_list|(
name|Loc
argument_list|,
name|Namespace
argument_list|,
name|mapping
argument_list|,
name|Str
argument_list|)
block|;   }
name|void
name|PragmaOpenCLExtension
argument_list|(
argument|SourceLocation NameLoc
argument_list|,
argument|const IdentifierInfo *Name
argument_list|,
argument|SourceLocation StateLoc
argument_list|,
argument|unsigned State
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaOpenCLExtension
argument_list|(
name|NameLoc
argument_list|,
name|Name
argument_list|,
name|StateLoc
argument_list|,
name|State
argument_list|)
block|;
name|Second
operator|->
name|PragmaOpenCLExtension
argument_list|(
name|NameLoc
argument_list|,
name|Name
argument_list|,
name|StateLoc
argument_list|,
name|State
argument_list|)
block|;   }
name|void
name|PragmaWarning
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|StringRef WarningSpec
argument_list|,
argument|ArrayRef<int> Ids
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaWarning
argument_list|(
name|Loc
argument_list|,
name|WarningSpec
argument_list|,
name|Ids
argument_list|)
block|;
name|Second
operator|->
name|PragmaWarning
argument_list|(
name|Loc
argument_list|,
name|WarningSpec
argument_list|,
name|Ids
argument_list|)
block|;   }
name|void
name|PragmaWarningPush
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|int Level
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaWarningPush
argument_list|(
name|Loc
argument_list|,
name|Level
argument_list|)
block|;
name|Second
operator|->
name|PragmaWarningPush
argument_list|(
name|Loc
argument_list|,
name|Level
argument_list|)
block|;   }
name|void
name|PragmaWarningPop
argument_list|(
argument|SourceLocation Loc
argument_list|)
name|override
block|{
name|First
operator|->
name|PragmaWarningPop
argument_list|(
name|Loc
argument_list|)
block|;
name|Second
operator|->
name|PragmaWarningPop
argument_list|(
name|Loc
argument_list|)
block|;   }
name|void
name|MacroExpands
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDefinition&MD
argument_list|,
argument|SourceRange Range
argument_list|,
argument|const MacroArgs *Args
argument_list|)
name|override
block|{
name|First
operator|->
name|MacroExpands
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|,
name|Range
argument_list|,
name|Args
argument_list|)
block|;
name|Second
operator|->
name|MacroExpands
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|,
name|Range
argument_list|,
name|Args
argument_list|)
block|;   }
name|void
name|MacroDefined
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDirective *MD
argument_list|)
name|override
block|{
name|First
operator|->
name|MacroDefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|)
block|;
name|Second
operator|->
name|MacroDefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|)
block|;   }
name|void
name|MacroUndefined
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDefinition&MD
argument_list|,
argument|const MacroDirective *Undef
argument_list|)
name|override
block|{
name|First
operator|->
name|MacroUndefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|,
name|Undef
argument_list|)
block|;
name|Second
operator|->
name|MacroUndefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|,
name|Undef
argument_list|)
block|;   }
name|void
name|Defined
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDefinition&MD
argument_list|,
argument|SourceRange Range
argument_list|)
name|override
block|{
name|First
operator|->
name|Defined
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|,
name|Range
argument_list|)
block|;
name|Second
operator|->
name|Defined
argument_list|(
name|MacroNameTok
argument_list|,
name|MD
argument_list|,
name|Range
argument_list|)
block|;   }
name|void
name|SourceRangeSkipped
argument_list|(
argument|SourceRange Range
argument_list|)
name|override
block|{
name|First
operator|->
name|SourceRangeSkipped
argument_list|(
name|Range
argument_list|)
block|;
name|Second
operator|->
name|SourceRangeSkipped
argument_list|(
name|Range
argument_list|)
block|;   }
comment|/// \brief Hook called whenever an \#if is seen.
name|void
name|If
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceRange ConditionRange
argument_list|,
argument|ConditionValueKind ConditionValue
argument_list|)
name|override
block|{
name|First
operator|->
name|If
argument_list|(
name|Loc
argument_list|,
name|ConditionRange
argument_list|,
name|ConditionValue
argument_list|)
block|;
name|Second
operator|->
name|If
argument_list|(
name|Loc
argument_list|,
name|ConditionRange
argument_list|,
name|ConditionValue
argument_list|)
block|;   }
comment|/// \brief Hook called whenever an \#elif is seen.
name|void
name|Elif
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceRange ConditionRange
argument_list|,
argument|ConditionValueKind ConditionValue
argument_list|,
argument|SourceLocation IfLoc
argument_list|)
name|override
block|{
name|First
operator|->
name|Elif
argument_list|(
name|Loc
argument_list|,
name|ConditionRange
argument_list|,
name|ConditionValue
argument_list|,
name|IfLoc
argument_list|)
block|;
name|Second
operator|->
name|Elif
argument_list|(
name|Loc
argument_list|,
name|ConditionRange
argument_list|,
name|ConditionValue
argument_list|,
name|IfLoc
argument_list|)
block|;   }
comment|/// \brief Hook called whenever an \#ifdef is seen.
name|void
name|Ifdef
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDefinition&MD
argument_list|)
name|override
block|{
name|First
operator|->
name|Ifdef
argument_list|(
name|Loc
argument_list|,
name|MacroNameTok
argument_list|,
name|MD
argument_list|)
block|;
name|Second
operator|->
name|Ifdef
argument_list|(
name|Loc
argument_list|,
name|MacroNameTok
argument_list|,
name|MD
argument_list|)
block|;   }
comment|/// \brief Hook called whenever an \#ifndef is seen.
name|void
name|Ifndef
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDefinition&MD
argument_list|)
name|override
block|{
name|First
operator|->
name|Ifndef
argument_list|(
name|Loc
argument_list|,
name|MacroNameTok
argument_list|,
name|MD
argument_list|)
block|;
name|Second
operator|->
name|Ifndef
argument_list|(
name|Loc
argument_list|,
name|MacroNameTok
argument_list|,
name|MD
argument_list|)
block|;   }
comment|/// \brief Hook called whenever an \#else is seen.
name|void
name|Else
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation IfLoc
argument_list|)
name|override
block|{
name|First
operator|->
name|Else
argument_list|(
name|Loc
argument_list|,
name|IfLoc
argument_list|)
block|;
name|Second
operator|->
name|Else
argument_list|(
name|Loc
argument_list|,
name|IfLoc
argument_list|)
block|;   }
comment|/// \brief Hook called whenever an \#endif is seen.
name|void
name|Endif
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation IfLoc
argument_list|)
name|override
block|{
name|First
operator|->
name|Endif
argument_list|(
name|Loc
argument_list|,
name|IfLoc
argument_list|)
block|;
name|Second
operator|->
name|Endif
argument_list|(
name|Loc
argument_list|,
name|IfLoc
argument_list|)
block|;   }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

