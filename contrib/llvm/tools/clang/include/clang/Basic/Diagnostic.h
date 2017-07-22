begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Diagnostic.h - C Language Family Diagnostic Handling ---*- C++ -*-===//
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
comment|/// \brief Defines the Diagnostic-related interfaces.
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
name|LLVM_CLANG_BASIC_DIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_DIAGNOSTIC_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/DiagnosticIDs.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DeclContext
decl_stmt|;
name|class
name|DiagnosticBuilder
decl_stmt|;
name|class
name|DiagnosticConsumer
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|StoredDiagnostic
decl_stmt|;
name|namespace
name|tok
block|{
enum_decl|enum
name|TokenKind
enum_decl|:
name|unsigned
name|short
enum_decl|;
block|}
comment|// end namespace tok
comment|/// \brief Annotates a diagnostic with some code that should be
comment|/// inserted, removed, or replaced to fix the problem.
comment|///
comment|/// This kind of hint should be used when we are certain that the
comment|/// introduction, removal, or modification of a particular (small!)
comment|/// amount of code will correct a compilation error. The compiler
comment|/// should also provide full recovery from such errors, such that
comment|/// suppressing the diagnostic output can still result in successful
comment|/// compilation.
name|class
name|FixItHint
block|{
name|public
label|:
comment|/// \brief Code that should be replaced to correct the error. Empty for an
comment|/// insertion hint.
name|CharSourceRange
name|RemoveRange
decl_stmt|;
comment|/// \brief Code in the specific range that should be inserted in the insertion
comment|/// location.
name|CharSourceRange
name|InsertFromRange
decl_stmt|;
comment|/// \brief The actual code to insert at the insertion location, as a
comment|/// string.
name|std
operator|::
name|string
name|CodeToInsert
expr_stmt|;
name|bool
name|BeforePreviousInsertions
decl_stmt|;
comment|/// \brief Empty code modification hint, indicating that no code
comment|/// modification is known.
name|FixItHint
argument_list|()
operator|:
name|BeforePreviousInsertions
argument_list|(
argument|false
argument_list|)
block|{ }
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
operator|!
name|RemoveRange
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Create a code modification hint that inserts the given
comment|/// code string at a specific location.
specifier|static
name|FixItHint
name|CreateInsertion
parameter_list|(
name|SourceLocation
name|InsertionLoc
parameter_list|,
name|StringRef
name|Code
parameter_list|,
name|bool
name|BeforePreviousInsertions
init|=
name|false
parameter_list|)
block|{
name|FixItHint
name|Hint
decl_stmt|;
name|Hint
operator|.
name|RemoveRange
operator|=
name|CharSourceRange
operator|::
name|getCharRange
argument_list|(
name|InsertionLoc
argument_list|,
name|InsertionLoc
argument_list|)
expr_stmt|;
name|Hint
operator|.
name|CodeToInsert
operator|=
name|Code
expr_stmt|;
name|Hint
operator|.
name|BeforePreviousInsertions
operator|=
name|BeforePreviousInsertions
expr_stmt|;
return|return
name|Hint
return|;
block|}
comment|/// \brief Create a code modification hint that inserts the given
comment|/// code from \p FromRange at a specific location.
specifier|static
name|FixItHint
name|CreateInsertionFromRange
parameter_list|(
name|SourceLocation
name|InsertionLoc
parameter_list|,
name|CharSourceRange
name|FromRange
parameter_list|,
name|bool
name|BeforePreviousInsertions
init|=
name|false
parameter_list|)
block|{
name|FixItHint
name|Hint
decl_stmt|;
name|Hint
operator|.
name|RemoveRange
operator|=
name|CharSourceRange
operator|::
name|getCharRange
argument_list|(
name|InsertionLoc
argument_list|,
name|InsertionLoc
argument_list|)
expr_stmt|;
name|Hint
operator|.
name|InsertFromRange
operator|=
name|FromRange
expr_stmt|;
name|Hint
operator|.
name|BeforePreviousInsertions
operator|=
name|BeforePreviousInsertions
expr_stmt|;
return|return
name|Hint
return|;
block|}
comment|/// \brief Create a code modification hint that removes the given
comment|/// source range.
specifier|static
name|FixItHint
name|CreateRemoval
parameter_list|(
name|CharSourceRange
name|RemoveRange
parameter_list|)
block|{
name|FixItHint
name|Hint
decl_stmt|;
name|Hint
operator|.
name|RemoveRange
operator|=
name|RemoveRange
expr_stmt|;
return|return
name|Hint
return|;
block|}
specifier|static
name|FixItHint
name|CreateRemoval
parameter_list|(
name|SourceRange
name|RemoveRange
parameter_list|)
block|{
return|return
name|CreateRemoval
argument_list|(
name|CharSourceRange
operator|::
name|getTokenRange
argument_list|(
name|RemoveRange
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Create a code modification hint that replaces the given
comment|/// source range with the given code string.
specifier|static
name|FixItHint
name|CreateReplacement
parameter_list|(
name|CharSourceRange
name|RemoveRange
parameter_list|,
name|StringRef
name|Code
parameter_list|)
block|{
name|FixItHint
name|Hint
decl_stmt|;
name|Hint
operator|.
name|RemoveRange
operator|=
name|RemoveRange
expr_stmt|;
name|Hint
operator|.
name|CodeToInsert
operator|=
name|Code
expr_stmt|;
return|return
name|Hint
return|;
block|}
specifier|static
name|FixItHint
name|CreateReplacement
parameter_list|(
name|SourceRange
name|RemoveRange
parameter_list|,
name|StringRef
name|Code
parameter_list|)
block|{
return|return
name|CreateReplacement
argument_list|(
name|CharSourceRange
operator|::
name|getTokenRange
argument_list|(
name|RemoveRange
argument_list|)
argument_list|,
name|Code
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Concrete class used by the front-end to report problems and issues.
comment|///
comment|/// This massages the diagnostics (e.g. handling things like "report warnings
comment|/// as errors" and passes them off to the DiagnosticConsumer for reporting to
comment|/// the user. DiagnosticsEngine is tied to one translation unit and one
comment|/// SourceManager.
name|class
name|DiagnosticsEngine
range|:
name|public
name|RefCountedBase
operator|<
name|DiagnosticsEngine
operator|>
block|{
name|public
operator|:
comment|/// \brief The level of the diagnostic, after it has been through mapping.
expr|enum
name|Level
block|{
name|Ignored
operator|=
name|DiagnosticIDs
operator|::
name|Ignored
block|,
name|Note
operator|=
name|DiagnosticIDs
operator|::
name|Note
block|,
name|Remark
operator|=
name|DiagnosticIDs
operator|::
name|Remark
block|,
name|Warning
operator|=
name|DiagnosticIDs
operator|::
name|Warning
block|,
name|Error
operator|=
name|DiagnosticIDs
operator|::
name|Error
block|,
name|Fatal
operator|=
name|DiagnosticIDs
operator|::
name|Fatal
block|}
block|;    enum
name|ArgumentKind
block|{
name|ak_std_string
block|,
comment|///< std::string
name|ak_c_string
block|,
comment|///< const char *
name|ak_sint
block|,
comment|///< int
name|ak_uint
block|,
comment|///< unsigned
name|ak_tokenkind
block|,
comment|///< enum TokenKind : unsigned
name|ak_identifierinfo
block|,
comment|///< IdentifierInfo
name|ak_qualtype
block|,
comment|///< QualType
name|ak_declarationname
block|,
comment|///< DeclarationName
name|ak_nameddecl
block|,
comment|///< NamedDecl *
name|ak_nestednamespec
block|,
comment|///< NestedNameSpecifier *
name|ak_declcontext
block|,
comment|///< DeclContext *
name|ak_qualtype_pair
block|,
comment|///< pair<QualType, QualType>
name|ak_attr
comment|///< Attr *
block|}
block|;
comment|/// \brief Represents on argument value, which is a union discriminated
comment|/// by ArgumentKind, with a value.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ArgumentKind
operator|,
name|intptr_t
operator|>
name|ArgumentValue
expr_stmt|;
name|private
operator|:
name|unsigned
name|char
name|AllExtensionsSilenced
decl_stmt|;
comment|// Used by __extension__
name|bool
name|SuppressAfterFatalError
decl_stmt|;
comment|// Suppress diagnostics after a fatal error?
name|bool
name|SuppressAllDiagnostics
decl_stmt|;
comment|// Suppress all diagnostics.
name|bool
name|ElideType
decl_stmt|;
comment|// Elide common types of templates.
name|bool
name|PrintTemplateTree
decl_stmt|;
comment|// Print a tree when comparing templates.
name|bool
name|ShowColors
decl_stmt|;
comment|// Color printing is enabled.
name|OverloadsShown
name|ShowOverloads
decl_stmt|;
comment|// Which overload candidates to show.
name|unsigned
name|ErrorLimit
decl_stmt|;
comment|// Cap of # errors emitted, 0 -> no limit.
name|unsigned
name|TemplateBacktraceLimit
decl_stmt|;
comment|// Cap on depth of template backtrace stack,
comment|// 0 -> no limit.
name|unsigned
name|ConstexprBacktraceLimit
decl_stmt|;
comment|// Cap on depth of constexpr evaluation
comment|// backtrace stack, 0 -> no limit.
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticIDs
operator|>
name|Diags
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticOptions
operator|>
name|DiagOpts
expr_stmt|;
name|DiagnosticConsumer
modifier|*
name|Client
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DiagnosticConsumer
operator|>
name|Owner
expr_stmt|;
name|SourceManager
modifier|*
name|SourceMgr
decl_stmt|;
comment|/// \brief Mapping information for diagnostics.
comment|///
comment|/// Mapping info is packed into four bits per diagnostic.  The low three
comment|/// bits are the mapping (an instance of diag::Severity), or zero if unset.
comment|/// The high bit is set when the mapping was established as a user mapping.
comment|/// If the high bit is clear, then the low bits are set to the default
comment|/// value, and should be mapped with -pedantic, -Werror, etc.
comment|///
comment|/// A new DiagState is created and kept around when diagnostic pragmas modify
comment|/// the state so that we know what is the diagnostic state at any given
comment|/// source location.
name|class
name|DiagState
block|{
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|DiagnosticMapping
operator|>
name|DiagMap
expr_stmt|;
name|public
label|:
comment|// "Global" configuration state that can actually vary between modules.
name|unsigned
name|IgnoreAllWarnings
range|:
literal|1
decl_stmt|;
comment|// Ignore all warnings: -w
name|unsigned
name|EnableAllWarnings
range|:
literal|1
decl_stmt|;
comment|// Enable all warnings.
name|unsigned
name|WarningsAsErrors
range|:
literal|1
decl_stmt|;
comment|// Treat warnings like errors.
name|unsigned
name|ErrorsAsFatal
range|:
literal|1
decl_stmt|;
comment|// Treat errors like fatal errors.
name|unsigned
name|SuppressSystemWarnings
range|:
literal|1
decl_stmt|;
comment|// Suppress warnings in system headers.
name|diag
operator|::
name|Severity
name|ExtBehavior
expr_stmt|;
comment|// Map extensions to warnings or errors?
name|DiagState
argument_list|()
operator|:
name|IgnoreAllWarnings
argument_list|(
name|false
argument_list|)
operator|,
name|EnableAllWarnings
argument_list|(
name|false
argument_list|)
operator|,
name|WarningsAsErrors
argument_list|(
name|false
argument_list|)
operator|,
name|ErrorsAsFatal
argument_list|(
name|false
argument_list|)
operator|,
name|SuppressSystemWarnings
argument_list|(
name|false
argument_list|)
operator|,
name|ExtBehavior
argument_list|(
argument|diag::Severity::Ignored
argument_list|)
block|{}
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|DiagnosticMapping
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|DiagnosticMapping
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|void
name|setMapping
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|,
name|DiagnosticMapping
name|Info
argument_list|)
block|{
name|DiagMap
index|[
name|Diag
index|]
operator|=
name|Info
expr_stmt|;
block|}
name|DiagnosticMapping
name|lookupMapping
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|)
decl|const
block|{
return|return
name|DiagMap
operator|.
name|lookup
argument_list|(
name|Diag
argument_list|)
return|;
block|}
name|DiagnosticMapping
modifier|&
name|getOrAddMapping
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|)
decl_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|DiagMap
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|DiagMap
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Keeps and automatically disposes all DiagStates that we create.
name|std
operator|::
name|list
operator|<
name|DiagState
operator|>
name|DiagStates
expr_stmt|;
comment|/// A mapping from files to the diagnostic states for those files. Lazily
comment|/// built on demand for files in which the diagnostic state has not changed.
name|class
name|DiagStateMap
block|{
name|public
label|:
comment|/// Add an initial diagnostic state.
name|void
name|appendFirst
parameter_list|(
name|DiagState
modifier|*
name|State
parameter_list|)
function_decl|;
comment|/// Add a new latest state point.
name|void
name|append
parameter_list|(
name|SourceManager
modifier|&
name|SrcMgr
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DiagState
modifier|*
name|State
parameter_list|)
function_decl|;
comment|/// Look up the diagnostic state at a given source location.
name|DiagState
modifier|*
name|lookup
argument_list|(
name|SourceManager
operator|&
name|SrcMgr
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
comment|/// Determine whether this map is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Files
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Clear out this map.
name|void
name|clear
parameter_list|()
block|{
name|Files
operator|.
name|clear
argument_list|()
expr_stmt|;
name|FirstDiagState
operator|=
name|CurDiagState
operator|=
name|nullptr
expr_stmt|;
name|CurDiagStateLoc
operator|=
name|SourceLocation
argument_list|()
expr_stmt|;
block|}
comment|/// Grab the most-recently-added state point.
name|DiagState
operator|*
name|getCurDiagState
argument_list|()
specifier|const
block|{
return|return
name|CurDiagState
return|;
block|}
comment|/// Get the location at which a diagnostic state was last added.
name|SourceLocation
name|getCurDiagStateLoc
argument_list|()
specifier|const
block|{
return|return
name|CurDiagStateLoc
return|;
block|}
name|private
label|:
comment|/// \brief Represents a point in source where the diagnostic state was
comment|/// modified because of a pragma.
comment|///
comment|/// 'Loc' can be null if the point represents the diagnostic state
comment|/// modifications done through the command-line.
struct|struct
name|DiagStatePoint
block|{
name|DiagState
modifier|*
name|State
decl_stmt|;
name|unsigned
name|Offset
decl_stmt|;
name|DiagStatePoint
argument_list|(
argument|DiagState *State
argument_list|,
argument|unsigned Offset
argument_list|)
block|:
name|State
argument_list|(
name|State
argument_list|)
operator|,
name|Offset
argument_list|(
argument|Offset
argument_list|)
block|{ }
block|}
struct|;
comment|/// Description of the diagnostic states and state transitions for a
comment|/// particular FileID.
struct|struct
name|File
block|{
comment|/// The diagnostic state for the parent file. This is strictly redundant,
comment|/// as looking up the DecomposedIncludedLoc for the FileID in the Files
comment|/// map would give us this, but we cache it here for performance.
name|File
modifier|*
name|Parent
init|=
name|nullptr
decl_stmt|;
comment|/// The offset of this file within its parent.
name|unsigned
name|ParentOffset
init|=
literal|0
decl_stmt|;
comment|/// Whether this file has any local (not imported from an AST file)
comment|/// diagnostic state transitions.
name|bool
name|HasLocalTransitions
init|=
name|false
decl_stmt|;
comment|/// The points within the file where the state changes. There will always
comment|/// be at least one of these (the state on entry to the file).
name|llvm
operator|::
name|SmallVector
operator|<
name|DiagStatePoint
operator|,
literal|4
operator|>
name|StateTransitions
expr_stmt|;
name|DiagState
modifier|*
name|lookup
argument_list|(
name|unsigned
name|Offset
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
comment|/// The diagnostic states for each file.
name|mutable
name|std
operator|::
name|map
operator|<
name|FileID
operator|,
name|File
operator|>
name|Files
expr_stmt|;
comment|/// The initial diagnostic state.
name|DiagState
modifier|*
name|FirstDiagState
decl_stmt|;
comment|/// The current diagnostic state.
name|DiagState
modifier|*
name|CurDiagState
decl_stmt|;
comment|/// The location at which the current diagnostic state was established.
name|SourceLocation
name|CurDiagStateLoc
decl_stmt|;
comment|/// Get the diagnostic state information for a file.
name|File
modifier|*
name|getFile
argument_list|(
name|SourceManager
operator|&
name|SrcMgr
argument_list|,
name|FileID
name|ID
argument_list|)
decl|const
decl_stmt|;
name|friend
name|class
name|ASTReader
decl_stmt|;
name|friend
name|class
name|ASTWriter
decl_stmt|;
block|}
empty_stmt|;
name|DiagStateMap
name|DiagStatesByLoc
decl_stmt|;
comment|/// \brief Keeps the DiagState that was active during each diagnostic 'push'
comment|/// so we can get back at it when we 'pop'.
name|std
operator|::
name|vector
operator|<
name|DiagState
operator|*
operator|>
name|DiagStateOnPushStack
expr_stmt|;
name|DiagState
operator|*
name|GetCurDiagState
argument_list|()
specifier|const
block|{
return|return
name|DiagStatesByLoc
operator|.
name|getCurDiagState
argument_list|()
return|;
block|}
name|void
name|PushDiagStatePoint
parameter_list|(
name|DiagState
modifier|*
name|State
parameter_list|,
name|SourceLocation
name|L
parameter_list|)
function_decl|;
comment|/// \brief Finds the DiagStatePoint that contains the diagnostic state of
comment|/// the given source location.
name|DiagState
modifier|*
name|GetDiagStateForLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|SourceMgr
condition|?
name|DiagStatesByLoc
operator|.
name|lookup
argument_list|(
operator|*
name|SourceMgr
argument_list|,
name|Loc
argument_list|)
else|:
name|DiagStatesByLoc
operator|.
name|getCurDiagState
argument_list|()
return|;
block|}
comment|/// \brief Sticky flag set to \c true when an error is emitted.
name|bool
name|ErrorOccurred
decl_stmt|;
comment|/// \brief Sticky flag set to \c true when an "uncompilable error" occurs.
comment|/// I.e. an error that was not upgraded from a warning by -Werror.
name|bool
name|UncompilableErrorOccurred
decl_stmt|;
comment|/// \brief Sticky flag set to \c true when a fatal error is emitted.
name|bool
name|FatalErrorOccurred
decl_stmt|;
comment|/// \brief Indicates that an unrecoverable error has occurred.
name|bool
name|UnrecoverableErrorOccurred
decl_stmt|;
comment|/// \brief Counts for DiagnosticErrorTrap to check whether an error occurred
comment|/// during a parsing section, e.g. during parsing a function.
name|unsigned
name|TrapNumErrorsOccurred
decl_stmt|;
name|unsigned
name|TrapNumUnrecoverableErrorsOccurred
decl_stmt|;
comment|/// \brief The level of the last diagnostic emitted.
comment|///
comment|/// This is used to emit continuation diagnostics with the same level as the
comment|/// diagnostic that they follow.
name|DiagnosticIDs
operator|::
name|Level
name|LastDiagLevel
expr_stmt|;
name|unsigned
name|NumWarnings
decl_stmt|;
comment|///< Number of warnings reported
name|unsigned
name|NumErrors
decl_stmt|;
comment|///< Number of errors reported
comment|/// \brief A function pointer that converts an opaque diagnostic
comment|/// argument to a strings.
comment|///
comment|/// This takes the modifiers and argument that was present in the diagnostic.
comment|///
comment|/// The PrevArgs array indicates the previous arguments formatted for this
comment|/// diagnostic.  Implementations of this function can use this information to
comment|/// avoid redundancy across arguments.
comment|///
comment|/// This is a hack to avoid a layering violation between libbasic and libsema.
typedef|typedef
name|void
argument_list|(
argument|*ArgToStringFnTy
argument_list|)
operator|(
name|ArgumentKind
name|Kind
operator|,
name|intptr_t
name|Val
operator|,
name|StringRef
name|Modifier
operator|,
name|StringRef
name|Argument
operator|,
name|ArrayRef
operator|<
name|ArgumentValue
operator|>
name|PrevArgs
operator|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Output
operator|,
name|void
operator|*
name|Cookie
operator|,
name|ArrayRef
operator|<
name|intptr_t
operator|>
name|QualTypeVals
operator|)
expr_stmt|;
name|void
modifier|*
name|ArgToStringCookie
decl_stmt|;
name|ArgToStringFnTy
name|ArgToStringFn
decl_stmt|;
comment|/// \brief ID of the "delayed" diagnostic, which is a (typically
comment|/// fatal) diagnostic that had to be delayed because it was found
comment|/// while emitting another diagnostic.
name|unsigned
name|DelayedDiagID
decl_stmt|;
comment|/// \brief First string argument for the delayed diagnostic.
name|std
operator|::
name|string
name|DelayedDiagArg1
expr_stmt|;
comment|/// \brief Second string argument for the delayed diagnostic.
name|std
operator|::
name|string
name|DelayedDiagArg2
expr_stmt|;
comment|/// \brief Optional flag value.
comment|///
comment|/// Some flags accept values, for instance: -Wframe-larger-than=<value> and
comment|/// -Rpass=<value>. The content of this string is emitted after the flag name
comment|/// and '='.
name|std
operator|::
name|string
name|FlagValue
expr_stmt|;
name|public
label|:
name|explicit
name|DiagnosticsEngine
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticIDs
operator|>
name|Diags
argument_list|,
name|DiagnosticOptions
operator|*
name|DiagOpts
argument_list|,
name|DiagnosticConsumer
operator|*
name|client
operator|=
name|nullptr
argument_list|,
name|bool
name|ShouldOwnClient
operator|=
name|true
argument_list|)
decl_stmt|;
name|DiagnosticsEngine
argument_list|(
specifier|const
name|DiagnosticsEngine
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|DiagnosticsEngine
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DiagnosticsEngine
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|DiagnosticsEngine
argument_list|()
expr_stmt|;
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticIDs
operator|>
operator|&
name|getDiagnosticIDs
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
comment|/// \brief Retrieve the diagnostic options.
name|DiagnosticOptions
operator|&
name|getDiagnosticOptions
argument_list|()
specifier|const
block|{
return|return
operator|*
name|DiagOpts
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|DiagState
operator|::
name|const_iterator
operator|>
name|diag_mapping_range
expr_stmt|;
comment|/// \brief Get the current set of diagnostic mappings.
name|diag_mapping_range
name|getDiagnosticMappings
argument_list|()
specifier|const
block|{
specifier|const
name|DiagState
operator|&
name|DS
operator|=
operator|*
name|GetCurDiagState
argument_list|()
block|;
return|return
name|diag_mapping_range
argument_list|(
name|DS
operator|.
name|begin
argument_list|()
argument_list|,
name|DS
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|DiagnosticConsumer
modifier|*
name|getClient
parameter_list|()
block|{
return|return
name|Client
return|;
block|}
specifier|const
name|DiagnosticConsumer
operator|*
name|getClient
argument_list|()
specifier|const
block|{
return|return
name|Client
return|;
block|}
comment|/// \brief Determine whether this \c DiagnosticsEngine object own its client.
name|bool
name|ownsClient
argument_list|()
specifier|const
block|{
return|return
name|Owner
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Return the current diagnostic client along with ownership of that
comment|/// client.
name|std
operator|::
name|unique_ptr
operator|<
name|DiagnosticConsumer
operator|>
name|takeClient
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|Owner
argument_list|)
return|;
block|}
name|bool
name|hasSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
operator|!=
name|nullptr
return|;
block|}
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SourceMgr
operator|&&
literal|"SourceManager not set!"
argument_list|)
block|;
return|return
operator|*
name|SourceMgr
return|;
block|}
name|void
name|setSourceManager
parameter_list|(
name|SourceManager
modifier|*
name|SrcMgr
parameter_list|)
block|{
name|assert
argument_list|(
name|DiagStatesByLoc
operator|.
name|empty
argument_list|()
operator|&&
literal|"Leftover diag state from a different SourceManager."
argument_list|)
expr_stmt|;
name|SourceMgr
operator|=
name|SrcMgr
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|//  DiagnosticsEngine characterization methods, used by a client to customize
comment|//  how diagnostics are emitted.
comment|//
comment|/// \brief Copies the current DiagMappings and pushes the new copy
comment|/// onto the top of the stack.
name|void
name|pushMappings
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Pops the current DiagMappings off the top of the stack,
comment|/// causing the new top of the stack to be the active mappings.
comment|///
comment|/// \returns \c true if the pop happens, \c false if there is only one
comment|/// DiagMapping on the stack.
name|bool
name|popMappings
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief Set the diagnostic client associated with this diagnostic object.
comment|///
comment|/// \param ShouldOwnClient true if the diagnostic object should take
comment|/// ownership of \c client.
name|void
name|setClient
parameter_list|(
name|DiagnosticConsumer
modifier|*
name|client
parameter_list|,
name|bool
name|ShouldOwnClient
init|=
name|true
parameter_list|)
function_decl|;
comment|/// \brief Specify a limit for the number of errors we should
comment|/// emit before giving up.
comment|///
comment|/// Zero disables the limit.
name|void
name|setErrorLimit
parameter_list|(
name|unsigned
name|Limit
parameter_list|)
block|{
name|ErrorLimit
operator|=
name|Limit
expr_stmt|;
block|}
comment|/// \brief Specify the maximum number of template instantiation
comment|/// notes to emit along with a given diagnostic.
name|void
name|setTemplateBacktraceLimit
parameter_list|(
name|unsigned
name|Limit
parameter_list|)
block|{
name|TemplateBacktraceLimit
operator|=
name|Limit
expr_stmt|;
block|}
comment|/// \brief Retrieve the maximum number of template instantiation
comment|/// notes to emit along with a given diagnostic.
name|unsigned
name|getTemplateBacktraceLimit
argument_list|()
specifier|const
block|{
return|return
name|TemplateBacktraceLimit
return|;
block|}
comment|/// \brief Specify the maximum number of constexpr evaluation
comment|/// notes to emit along with a given diagnostic.
name|void
name|setConstexprBacktraceLimit
parameter_list|(
name|unsigned
name|Limit
parameter_list|)
block|{
name|ConstexprBacktraceLimit
operator|=
name|Limit
expr_stmt|;
block|}
comment|/// \brief Retrieve the maximum number of constexpr evaluation
comment|/// notes to emit along with a given diagnostic.
name|unsigned
name|getConstexprBacktraceLimit
argument_list|()
specifier|const
block|{
return|return
name|ConstexprBacktraceLimit
return|;
block|}
comment|/// \brief When set to true, any unmapped warnings are ignored.
comment|///
comment|/// If this and WarningsAsErrors are both set, then this one wins.
name|void
name|setIgnoreAllWarnings
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|GetCurDiagState
argument_list|()
operator|->
name|IgnoreAllWarnings
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getIgnoreAllWarnings
argument_list|()
specifier|const
block|{
return|return
name|GetCurDiagState
argument_list|()
operator|->
name|IgnoreAllWarnings
return|;
block|}
comment|/// \brief When set to true, any unmapped ignored warnings are no longer
comment|/// ignored.
comment|///
comment|/// If this and IgnoreAllWarnings are both set, then that one wins.
name|void
name|setEnableAllWarnings
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|GetCurDiagState
argument_list|()
operator|->
name|EnableAllWarnings
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getEnableAllWarnings
argument_list|()
specifier|const
block|{
return|return
name|GetCurDiagState
argument_list|()
operator|->
name|EnableAllWarnings
return|;
block|}
comment|/// \brief When set to true, any warnings reported are issued as errors.
name|void
name|setWarningsAsErrors
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|GetCurDiagState
argument_list|()
operator|->
name|WarningsAsErrors
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getWarningsAsErrors
argument_list|()
specifier|const
block|{
return|return
name|GetCurDiagState
argument_list|()
operator|->
name|WarningsAsErrors
return|;
block|}
comment|/// \brief When set to true, any error reported is made a fatal error.
name|void
name|setErrorsAsFatal
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|GetCurDiagState
argument_list|()
operator|->
name|ErrorsAsFatal
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getErrorsAsFatal
argument_list|()
specifier|const
block|{
return|return
name|GetCurDiagState
argument_list|()
operator|->
name|ErrorsAsFatal
return|;
block|}
comment|/// \brief When set to true (the default), suppress further diagnostics after
comment|/// a fatal error.
name|void
name|setSuppressAfterFatalError
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|SuppressAfterFatalError
operator|=
name|Val
expr_stmt|;
block|}
comment|/// \brief When set to true mask warnings that come from system headers.
name|void
name|setSuppressSystemWarnings
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|GetCurDiagState
argument_list|()
operator|->
name|SuppressSystemWarnings
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getSuppressSystemWarnings
argument_list|()
specifier|const
block|{
return|return
name|GetCurDiagState
argument_list|()
operator|->
name|SuppressSystemWarnings
return|;
block|}
comment|/// \brief Suppress all diagnostics, to silence the front end when we
comment|/// know that we don't want any more diagnostics to be passed along to the
comment|/// client
name|void
name|setSuppressAllDiagnostics
parameter_list|(
name|bool
name|Val
init|=
name|true
parameter_list|)
block|{
name|SuppressAllDiagnostics
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getSuppressAllDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|SuppressAllDiagnostics
return|;
block|}
comment|/// \brief Set type eliding, to skip outputting same types occurring in
comment|/// template types.
name|void
name|setElideType
parameter_list|(
name|bool
name|Val
init|=
name|true
parameter_list|)
block|{
name|ElideType
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getElideType
parameter_list|()
block|{
return|return
name|ElideType
return|;
block|}
comment|/// \brief Set tree printing, to outputting the template difference in a
comment|/// tree format.
name|void
name|setPrintTemplateTree
parameter_list|(
name|bool
name|Val
init|=
name|false
parameter_list|)
block|{
name|PrintTemplateTree
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getPrintTemplateTree
parameter_list|()
block|{
return|return
name|PrintTemplateTree
return|;
block|}
comment|/// \brief Set color printing, so the type diffing will inject color markers
comment|/// into the output.
name|void
name|setShowColors
parameter_list|(
name|bool
name|Val
init|=
name|false
parameter_list|)
block|{
name|ShowColors
operator|=
name|Val
expr_stmt|;
block|}
name|bool
name|getShowColors
parameter_list|()
block|{
return|return
name|ShowColors
return|;
block|}
comment|/// \brief Specify which overload candidates to show when overload resolution
comment|/// fails.
comment|///
comment|/// By default, we show all candidates.
name|void
name|setShowOverloads
parameter_list|(
name|OverloadsShown
name|Val
parameter_list|)
block|{
name|ShowOverloads
operator|=
name|Val
expr_stmt|;
block|}
name|OverloadsShown
name|getShowOverloads
argument_list|()
specifier|const
block|{
return|return
name|ShowOverloads
return|;
block|}
comment|/// \brief Pretend that the last diagnostic issued was ignored, so any
comment|/// subsequent notes will be suppressed.
comment|///
comment|/// This can be used by clients who suppress diagnostics themselves.
name|void
name|setLastDiagnosticIgnored
parameter_list|()
block|{
if|if
condition|(
name|LastDiagLevel
operator|==
name|DiagnosticIDs
operator|::
name|Fatal
condition|)
name|FatalErrorOccurred
operator|=
name|true
expr_stmt|;
name|LastDiagLevel
operator|=
name|DiagnosticIDs
operator|::
name|Ignored
expr_stmt|;
block|}
comment|/// \brief Determine whether the previous diagnostic was ignored. This can
comment|/// be used by clients that want to determine whether notes attached to a
comment|/// diagnostic will be suppressed.
name|bool
name|isLastDiagnosticIgnored
argument_list|()
specifier|const
block|{
return|return
name|LastDiagLevel
operator|==
name|DiagnosticIDs
operator|::
name|Ignored
return|;
block|}
comment|/// \brief Controls whether otherwise-unmapped extension diagnostics are
comment|/// mapped onto ignore/warning/error.
comment|///
comment|/// This corresponds to the GCC -pedantic and -pedantic-errors option.
name|void
name|setExtensionHandlingBehavior
argument_list|(
name|diag
operator|::
name|Severity
name|H
argument_list|)
block|{
name|GetCurDiagState
argument_list|()
operator|->
name|ExtBehavior
operator|=
name|H
expr_stmt|;
block|}
name|diag
operator|::
name|Severity
name|getExtensionHandlingBehavior
argument_list|()
specifier|const
block|{
return|return
name|GetCurDiagState
argument_list|()
operator|->
name|ExtBehavior
return|;
block|}
comment|/// \brief Counter bumped when an __extension__  block is/ encountered.
comment|///
comment|/// When non-zero, all extension diagnostics are entirely silenced, no
comment|/// matter how they are mapped.
name|void
name|IncrementAllExtensionsSilenced
parameter_list|()
block|{
operator|++
name|AllExtensionsSilenced
expr_stmt|;
block|}
name|void
name|DecrementAllExtensionsSilenced
parameter_list|()
block|{
operator|--
name|AllExtensionsSilenced
expr_stmt|;
block|}
name|bool
name|hasAllExtensionsSilenced
parameter_list|()
block|{
return|return
name|AllExtensionsSilenced
operator|!=
literal|0
return|;
block|}
comment|/// \brief This allows the client to specify that certain warnings are
comment|/// ignored.
comment|///
comment|/// Notes can never be mapped, errors can only be mapped to fatal, and
comment|/// WARNINGs and EXTENSIONs can be mapped arbitrarily.
comment|///
comment|/// \param Loc The source location that this change of diagnostic state should
comment|/// take affect. It can be null if we are setting the latest state.
name|void
name|setSeverity
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|,
name|diag
operator|::
name|Severity
name|Map
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
comment|/// \brief Change an entire diagnostic group (e.g. "unknown-pragmas") to
comment|/// have the specified mapping.
comment|///
comment|/// \returns true (and ignores the request) if "Group" was unknown, false
comment|/// otherwise.
comment|///
comment|/// \param Flavor The flavor of group to affect. -Rfoo does not affect the
comment|/// state of the -Wfoo group and vice versa.
comment|///
comment|/// \param Loc The source location that this change of diagnostic state should
comment|/// take affect. It can be null if we are setting the state from command-line.
name|bool
name|setSeverityForGroup
argument_list|(
name|diag
operator|::
name|Flavor
name|Flavor
argument_list|,
name|StringRef
name|Group
argument_list|,
name|diag
operator|::
name|Severity
name|Map
argument_list|,
name|SourceLocation
name|Loc
operator|=
name|SourceLocation
argument_list|()
argument_list|)
decl_stmt|;
comment|/// \brief Set the warning-as-error flag for the given diagnostic group.
comment|///
comment|/// This function always only operates on the current diagnostic state.
comment|///
comment|/// \returns True if the given group is unknown, false otherwise.
name|bool
name|setDiagnosticGroupWarningAsError
parameter_list|(
name|StringRef
name|Group
parameter_list|,
name|bool
name|Enabled
parameter_list|)
function_decl|;
comment|/// \brief Set the error-as-fatal flag for the given diagnostic group.
comment|///
comment|/// This function always only operates on the current diagnostic state.
comment|///
comment|/// \returns True if the given group is unknown, false otherwise.
name|bool
name|setDiagnosticGroupErrorAsFatal
parameter_list|(
name|StringRef
name|Group
parameter_list|,
name|bool
name|Enabled
parameter_list|)
function_decl|;
comment|/// \brief Add the specified mapping to all diagnostics of the specified
comment|/// flavor.
comment|///
comment|/// Mainly to be used by -Wno-everything to disable all warnings but allow
comment|/// subsequent -W options to enable specific warnings.
name|void
name|setSeverityForAll
argument_list|(
name|diag
operator|::
name|Flavor
name|Flavor
argument_list|,
name|diag
operator|::
name|Severity
name|Map
argument_list|,
name|SourceLocation
name|Loc
operator|=
name|SourceLocation
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|hasErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|ErrorOccurred
return|;
block|}
comment|/// \brief Errors that actually prevent compilation, not those that are
comment|/// upgraded from a warning by -Werror.
name|bool
name|hasUncompilableErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|UncompilableErrorOccurred
return|;
block|}
name|bool
name|hasFatalErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|FatalErrorOccurred
return|;
block|}
comment|/// \brief Determine whether any kind of unrecoverable error has occurred.
name|bool
name|hasUnrecoverableErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|FatalErrorOccurred
operator|||
name|UnrecoverableErrorOccurred
return|;
block|}
name|unsigned
name|getNumWarnings
argument_list|()
specifier|const
block|{
return|return
name|NumWarnings
return|;
block|}
name|void
name|setNumWarnings
parameter_list|(
name|unsigned
name|NumWarnings
parameter_list|)
block|{
name|this
operator|->
name|NumWarnings
operator|=
name|NumWarnings
expr_stmt|;
block|}
comment|/// \brief Return an ID for a diagnostic with the specified format string and
comment|/// level.
comment|///
comment|/// If this is the first request for this diagnostic, it is registered and
comment|/// created, otherwise the existing ID is returned.
comment|///
comment|/// \param FormatString A fixed diagnostic format string that will be hashed
comment|/// and mapped to a unique DiagID.
name|template
operator|<
name|unsigned
name|N
operator|>
name|unsigned
name|getCustomDiagID
argument_list|(
argument|Level L
argument_list|,
argument|const char (&FormatString)[N]
argument_list|)
block|{
return|return
name|Diags
operator|->
name|getCustomDiagID
argument_list|(
operator|(
name|DiagnosticIDs
operator|::
name|Level
operator|)
name|L
argument_list|,
name|StringRef
argument_list|(
name|FormatString
argument_list|,
name|N
operator|-
literal|1
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Converts a diagnostic argument (as an intptr_t) into the string
comment|/// that represents it.
name|void
name|ConvertArgToString
argument_list|(
name|ArgumentKind
name|Kind
argument_list|,
name|intptr_t
name|Val
argument_list|,
name|StringRef
name|Modifier
argument_list|,
name|StringRef
name|Argument
argument_list|,
name|ArrayRef
operator|<
name|ArgumentValue
operator|>
name|PrevArgs
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Output
argument_list|,
name|ArrayRef
operator|<
name|intptr_t
operator|>
name|QualTypeVals
argument_list|)
decl|const
block|{
name|ArgToStringFn
argument_list|(
name|Kind
argument_list|,
name|Val
argument_list|,
name|Modifier
argument_list|,
name|Argument
argument_list|,
name|PrevArgs
argument_list|,
name|Output
argument_list|,
name|ArgToStringCookie
argument_list|,
name|QualTypeVals
argument_list|)
expr_stmt|;
block|}
name|void
name|SetArgToStringFn
parameter_list|(
name|ArgToStringFnTy
name|Fn
parameter_list|,
name|void
modifier|*
name|Cookie
parameter_list|)
block|{
name|ArgToStringFn
operator|=
name|Fn
expr_stmt|;
name|ArgToStringCookie
operator|=
name|Cookie
expr_stmt|;
block|}
comment|/// \brief Note that the prior diagnostic was emitted by some other
comment|/// \c DiagnosticsEngine, and we may be attaching a note to that diagnostic.
name|void
name|notePriorDiagnosticFrom
parameter_list|(
specifier|const
name|DiagnosticsEngine
modifier|&
name|Other
parameter_list|)
block|{
name|LastDiagLevel
operator|=
name|Other
operator|.
name|LastDiagLevel
expr_stmt|;
block|}
comment|/// \brief Reset the state of the diagnostic object to its initial
comment|/// configuration.
name|void
name|Reset
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// DiagnosticsEngine classification and reporting interfaces.
comment|//
comment|/// \brief Determine whether the diagnostic is known to be ignored.
comment|///
comment|/// This can be used to opportunistically avoid expensive checks when it's
comment|/// known for certain that the diagnostic has been suppressed at the
comment|/// specified location \p Loc.
comment|///
comment|/// \param Loc The source location we are interested in finding out the
comment|/// diagnostic state. Can be null in order to query the latest state.
name|bool
name|isIgnored
argument_list|(
name|unsigned
name|DiagID
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|Diags
operator|->
name|getDiagnosticSeverity
argument_list|(
name|DiagID
argument_list|,
name|Loc
argument_list|,
operator|*
name|this
argument_list|)
operator|==
name|diag
operator|::
name|Severity
operator|::
name|Ignored
return|;
block|}
comment|/// \brief Based on the way the client configured the DiagnosticsEngine
comment|/// object, classify the specified diagnostic ID into a Level, consumable by
comment|/// the DiagnosticConsumer.
comment|///
comment|/// To preserve invariant assumptions, this function should not be used to
comment|/// influence parse or semantic analysis actions. Instead consider using
comment|/// \c isIgnored().
comment|///
comment|/// \param Loc The source location we are interested in finding out the
comment|/// diagnostic state. Can be null in order to query the latest state.
name|Level
name|getDiagnosticLevel
argument_list|(
name|unsigned
name|DiagID
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
operator|(
name|Level
operator|)
name|Diags
operator|->
name|getDiagnosticLevel
argument_list|(
name|DiagID
argument_list|,
name|Loc
argument_list|,
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// \brief Issue the message to the client.
comment|///
comment|/// This actually returns an instance of DiagnosticBuilder which emits the
comment|/// diagnostics (through @c ProcessDiag) when it is destroyed.
comment|///
comment|/// \param DiagID A member of the @c diag::kind enum.
comment|/// \param Loc Represents the source location associated with the diagnostic,
comment|/// which can be an invalid location if no position information is available.
specifier|inline
name|DiagnosticBuilder
name|Report
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
specifier|inline
name|DiagnosticBuilder
name|Report
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
name|void
name|Report
parameter_list|(
specifier|const
name|StoredDiagnostic
modifier|&
name|storedDiag
parameter_list|)
function_decl|;
comment|/// \brief Determine whethere there is already a diagnostic in flight.
name|bool
name|isDiagnosticInFlight
argument_list|()
specifier|const
block|{
return|return
name|CurDiagID
operator|!=
operator|~
literal|0U
return|;
block|}
comment|/// \brief Set the "delayed" diagnostic that will be emitted once
comment|/// the current diagnostic completes.
comment|///
comment|///  If a diagnostic is already in-flight but the front end must
comment|///  report a problem (e.g., with an inconsistent file system
comment|///  state), this routine sets a "delayed" diagnostic that will be
comment|///  emitted after the current diagnostic completes. This should
comment|///  only be used for fatal errors detected at inconvenient
comment|///  times. If emitting a delayed diagnostic causes a second delayed
comment|///  diagnostic to be introduced, that second delayed diagnostic
comment|///  will be ignored.
comment|///
comment|/// \param DiagID The ID of the diagnostic being delayed.
comment|///
comment|/// \param Arg1 A string argument that will be provided to the
comment|/// diagnostic. A copy of this string will be stored in the
comment|/// DiagnosticsEngine object itself.
comment|///
comment|/// \param Arg2 A string argument that will be provided to the
comment|/// diagnostic. A copy of this string will be stored in the
comment|/// DiagnosticsEngine object itself.
name|void
name|SetDelayedDiagnostic
parameter_list|(
name|unsigned
name|DiagID
parameter_list|,
name|StringRef
name|Arg1
init|=
literal|""
parameter_list|,
name|StringRef
name|Arg2
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// \brief Clear out the current diagnostic.
name|void
name|Clear
parameter_list|()
block|{
name|CurDiagID
operator|=
operator|~
literal|0U
expr_stmt|;
block|}
comment|/// \brief Return the value associated with this diagnostic flag.
name|StringRef
name|getFlagValue
argument_list|()
specifier|const
block|{
return|return
name|FlagValue
return|;
block|}
name|private
label|:
comment|/// \brief Report the delayed diagnostic.
name|void
name|ReportDelayed
parameter_list|()
function_decl|;
comment|// This is private state used by DiagnosticBuilder.  We put it here instead of
comment|// in DiagnosticBuilder in order to keep DiagnosticBuilder a small lightweight
comment|// object.  This implementation choice means that we can only have one
comment|// diagnostic "in flight" at a time, but this seems to be a reasonable
comment|// tradeoff to keep these objects small.  Assertions verify that only one
comment|// diagnostic is in flight at a time.
name|friend
name|class
name|DiagnosticIDs
decl_stmt|;
name|friend
name|class
name|DiagnosticBuilder
decl_stmt|;
name|friend
name|class
name|Diagnostic
decl_stmt|;
name|friend
name|class
name|PartialDiagnostic
decl_stmt|;
name|friend
name|class
name|DiagnosticErrorTrap
decl_stmt|;
comment|/// \brief The location of the current diagnostic that is in flight.
name|SourceLocation
name|CurDiagLoc
decl_stmt|;
comment|/// \brief The ID of the current diagnostic that is in flight.
comment|///
comment|/// This is set to ~0U when there is no diagnostic in flight.
name|unsigned
name|CurDiagID
decl_stmt|;
enum|enum
block|{
comment|/// \brief The maximum number of arguments we can hold.
comment|///
comment|/// We currently only support up to 10 arguments (%0-%9).  A single
comment|/// diagnostic with more than that almost certainly has to be simplified
comment|/// anyway.
name|MaxArguments
init|=
literal|10
block|,   }
enum|;
comment|/// \brief The number of entries in Arguments.
name|signed
name|char
name|NumDiagArgs
decl_stmt|;
comment|/// \brief Specifies whether an argument is in DiagArgumentsStr or
comment|/// in DiagArguments.
comment|///
comment|/// This is an array of ArgumentKind::ArgumentKind enum values, one for each
comment|/// argument.
name|unsigned
name|char
name|DiagArgumentsKind
index|[
name|MaxArguments
index|]
decl_stmt|;
comment|/// \brief Holds the values of each string argument for the current
comment|/// diagnostic.
comment|///
comment|/// This is only used when the corresponding ArgumentKind is ak_std_string.
name|std
operator|::
name|string
name|DiagArgumentsStr
index|[
name|MaxArguments
index|]
expr_stmt|;
comment|/// \brief The values for the various substitution positions.
comment|///
comment|/// This is used when the argument is not an std::string.  The specific
comment|/// value is mangled into an intptr_t and the interpretation depends on
comment|/// exactly what sort of argument kind it is.
name|intptr_t
name|DiagArgumentsVal
index|[
name|MaxArguments
index|]
decl_stmt|;
comment|/// \brief The list of ranges added to this diagnostic.
name|SmallVector
operator|<
name|CharSourceRange
operator|,
literal|8
operator|>
name|DiagRanges
expr_stmt|;
comment|/// \brief If valid, provides a hint with some code to insert, remove,
comment|/// or modify at a particular position.
name|SmallVector
operator|<
name|FixItHint
operator|,
literal|8
operator|>
name|DiagFixItHints
expr_stmt|;
name|DiagnosticMapping
name|makeUserMapping
argument_list|(
name|diag
operator|::
name|Severity
name|Map
argument_list|,
name|SourceLocation
name|L
argument_list|)
block|{
name|bool
name|isPragma
init|=
name|L
operator|.
name|isValid
argument_list|()
decl_stmt|;
name|DiagnosticMapping
name|Mapping
init|=
name|DiagnosticMapping
operator|::
name|Make
argument_list|(
name|Map
argument_list|,
comment|/*IsUser=*/
name|true
argument_list|,
name|isPragma
argument_list|)
decl_stmt|;
comment|// If this is a pragma mapping, then set the diagnostic mapping flags so
comment|// that we override command line options.
if|if
condition|(
name|isPragma
condition|)
block|{
name|Mapping
operator|.
name|setNoWarningAsError
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|Mapping
operator|.
name|setNoErrorAsFatal
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
return|return
name|Mapping
return|;
block|}
comment|/// \brief Used to report a diagnostic that is finally fully formed.
comment|///
comment|/// \returns true if the diagnostic was emitted, false if it was suppressed.
name|bool
name|ProcessDiag
parameter_list|()
block|{
return|return
name|Diags
operator|->
name|ProcessDiag
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// @name Diagnostic Emission
comment|/// @{
name|protected
label|:
comment|// Sema requires access to the following functions because the current design
comment|// of SFINAE requires it to use its own SemaDiagnosticBuilder, which needs to
comment|// access us directly to ensure we minimize the emitted code for the common
comment|// Sema::Diag() patterns.
name|friend
name|class
name|Sema
decl_stmt|;
comment|/// \brief Emit the current diagnostic and clear the diagnostic state.
comment|///
comment|/// \param Force Emit the diagnostic regardless of suppression settings.
name|bool
name|EmitCurrentDiagnostic
parameter_list|(
name|bool
name|Force
init|=
name|false
parameter_list|)
function_decl|;
name|unsigned
name|getCurrentDiagID
argument_list|()
specifier|const
block|{
return|return
name|CurDiagID
return|;
block|}
name|SourceLocation
name|getCurrentDiagLoc
argument_list|()
specifier|const
block|{
return|return
name|CurDiagLoc
return|;
block|}
comment|/// @}
name|friend
name|class
name|ASTReader
decl_stmt|;
name|friend
name|class
name|ASTWriter
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief RAII class that determines when any errors have occurred
end_comment

begin_comment
comment|/// between the time the instance was created and the time it was
end_comment

begin_comment
comment|/// queried.
end_comment

begin_decl_stmt
name|class
name|DiagnosticErrorTrap
block|{
name|DiagnosticsEngine
modifier|&
name|Diag
decl_stmt|;
name|unsigned
name|NumErrors
decl_stmt|;
name|unsigned
name|NumUnrecoverableErrors
decl_stmt|;
name|public
label|:
name|explicit
name|DiagnosticErrorTrap
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|)
operator|:
name|Diag
argument_list|(
argument|Diag
argument_list|)
block|{
name|reset
argument_list|()
block|; }
comment|/// \brief Determine whether any errors have occurred since this
comment|/// object instance was created.
name|bool
name|hasErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|Diag
operator|.
name|TrapNumErrorsOccurred
operator|>
name|NumErrors
return|;
block|}
comment|/// \brief Determine whether any unrecoverable errors have occurred since this
comment|/// object instance was created.
name|bool
name|hasUnrecoverableErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|Diag
operator|.
name|TrapNumUnrecoverableErrorsOccurred
operator|>
name|NumUnrecoverableErrors
return|;
block|}
comment|/// \brief Set to initial state of "no errors occurred".
name|void
name|reset
parameter_list|()
block|{
name|NumErrors
operator|=
name|Diag
operator|.
name|TrapNumErrorsOccurred
expr_stmt|;
name|NumUnrecoverableErrors
operator|=
name|Diag
operator|.
name|TrapNumUnrecoverableErrorsOccurred
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// DiagnosticBuilder
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief A little helper class used to produce diagnostics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is constructed by the DiagnosticsEngine::Report method, and
end_comment

begin_comment
comment|/// allows insertion of extra information (arguments and source ranges) into
end_comment

begin_comment
comment|/// the currently "in flight" diagnostic.  When the temporary for the builder
end_comment

begin_comment
comment|/// is destroyed, the diagnostic is issued.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that many of these will be created as temporary objects (many call
end_comment

begin_comment
comment|/// sites), so we want them to be small and we never want their address taken.
end_comment

begin_comment
comment|/// This ensures that compilers with somewhat reasonable optimizers will promote
end_comment

begin_comment
comment|/// the common fields to registers, eliminating increments of the NumArgs field,
end_comment

begin_comment
comment|/// for example.
end_comment

begin_decl_stmt
name|class
name|DiagnosticBuilder
block|{
name|mutable
name|DiagnosticsEngine
modifier|*
name|DiagObj
init|=
name|nullptr
decl_stmt|;
name|mutable
name|unsigned
name|NumArgs
init|=
literal|0
decl_stmt|;
comment|/// \brief Status variable indicating if this diagnostic is still active.
comment|///
comment|// NOTE: This field is redundant with DiagObj (IsActive iff (DiagObj == 0)),
comment|// but LLVM is not currently smart enough to eliminate the null check that
comment|// Emit() would end up with if we used that as our status variable.
name|mutable
name|bool
name|IsActive
init|=
name|false
decl_stmt|;
comment|/// \brief Flag indicating that this diagnostic is being emitted via a
comment|/// call to ForceEmit.
name|mutable
name|bool
name|IsForceEmit
init|=
name|false
decl_stmt|;
name|friend
name|class
name|DiagnosticsEngine
decl_stmt|;
name|DiagnosticBuilder
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|DiagnosticBuilder
argument_list|(
name|DiagnosticsEngine
operator|*
name|diagObj
argument_list|)
operator|:
name|DiagObj
argument_list|(
name|diagObj
argument_list|)
operator|,
name|IsActive
argument_list|(
argument|true
argument_list|)
block|{
name|assert
argument_list|(
name|diagObj
operator|&&
literal|"DiagnosticBuilder requires a valid DiagnosticsEngine!"
argument_list|)
block|;
name|diagObj
operator|->
name|DiagRanges
operator|.
name|clear
argument_list|()
block|;
name|diagObj
operator|->
name|DiagFixItHints
operator|.
name|clear
argument_list|()
block|;   }
name|friend
name|class
name|PartialDiagnostic
expr_stmt|;
name|protected
label|:
name|void
name|FlushCounts
parameter_list|()
block|{
name|DiagObj
operator|->
name|NumDiagArgs
operator|=
name|NumArgs
expr_stmt|;
block|}
comment|/// \brief Clear out the current diagnostic.
name|void
name|Clear
argument_list|()
specifier|const
block|{
name|DiagObj
operator|=
name|nullptr
block|;
name|IsActive
operator|=
name|false
block|;
name|IsForceEmit
operator|=
name|false
block|;   }
comment|/// \brief Determine whether this diagnostic is still active.
name|bool
name|isActive
argument_list|()
specifier|const
block|{
return|return
name|IsActive
return|;
block|}
comment|/// \brief Force the diagnostic builder to emit the diagnostic now.
comment|///
comment|/// Once this function has been called, the DiagnosticBuilder object
comment|/// should not be used again before it is destroyed.
comment|///
comment|/// \returns true if a diagnostic was emitted, false if the
comment|/// diagnostic was suppressed.
name|bool
name|Emit
parameter_list|()
block|{
comment|// If this diagnostic is inactive, then its soul was stolen by the copy ctor
comment|// (or by a subclass, as in SemaDiagnosticBuilder).
if|if
condition|(
operator|!
name|isActive
argument_list|()
condition|)
return|return
name|false
return|;
comment|// When emitting diagnostics, we set the final argument count into
comment|// the DiagnosticsEngine object.
name|FlushCounts
argument_list|()
expr_stmt|;
comment|// Process the diagnostic.
name|bool
name|Result
init|=
name|DiagObj
operator|->
name|EmitCurrentDiagnostic
argument_list|(
name|IsForceEmit
argument_list|)
decl_stmt|;
comment|// This diagnostic is dead.
name|Clear
argument_list|()
expr_stmt|;
return|return
name|Result
return|;
block|}
name|public
label|:
comment|/// Copy constructor.  When copied, this "takes" the diagnostic info from the
comment|/// input and neuters it.
name|DiagnosticBuilder
argument_list|(
argument|const DiagnosticBuilder&D
argument_list|)
block|{
name|DiagObj
operator|=
name|D
operator|.
name|DiagObj
expr_stmt|;
name|IsActive
operator|=
name|D
operator|.
name|IsActive
expr_stmt|;
name|IsForceEmit
operator|=
name|D
operator|.
name|IsForceEmit
expr_stmt|;
name|D
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|NumArgs
operator|=
name|D
operator|.
name|NumArgs
expr_stmt|;
block|}
name|DiagnosticBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// \brief Emits the diagnostic.
operator|~
name|DiagnosticBuilder
argument_list|()
block|{
name|Emit
argument_list|()
block|;   }
comment|/// \brief Retrieve an empty diagnostic builder.
specifier|static
name|DiagnosticBuilder
name|getEmpty
argument_list|()
block|{
return|return
name|DiagnosticBuilder
argument_list|()
return|;
block|}
comment|/// \brief Forces the diagnostic to be emitted.
specifier|const
name|DiagnosticBuilder
operator|&
name|setForceEmit
argument_list|()
specifier|const
block|{
name|IsForceEmit
operator|=
name|true
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Conversion of DiagnosticBuilder to bool always returns \c true.
comment|///
comment|/// This allows is to be used in boolean error contexts (where \c true is
comment|/// used to indicate that an error has occurred), like:
comment|/// \code
comment|/// return Diag(...);
comment|/// \endcode
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|void
name|AddString
argument_list|(
name|StringRef
name|S
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isActive
argument_list|()
operator|&&
literal|"Clients must not add to cleared diagnostic!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|NumArgs
operator|<
name|DiagnosticsEngine
operator|::
name|MaxArguments
operator|&&
literal|"Too many arguments to diagnostic!"
argument_list|)
expr_stmt|;
name|DiagObj
operator|->
name|DiagArgumentsKind
index|[
name|NumArgs
index|]
operator|=
name|DiagnosticsEngine
operator|::
name|ak_std_string
expr_stmt|;
name|DiagObj
operator|->
name|DiagArgumentsStr
index|[
name|NumArgs
operator|++
index|]
operator|=
name|S
expr_stmt|;
block|}
name|void
name|AddTaggedVal
argument_list|(
name|intptr_t
name|V
argument_list|,
name|DiagnosticsEngine
operator|::
name|ArgumentKind
name|Kind
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isActive
argument_list|()
operator|&&
literal|"Clients must not add to cleared diagnostic!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|NumArgs
operator|<
name|DiagnosticsEngine
operator|::
name|MaxArguments
operator|&&
literal|"Too many arguments to diagnostic!"
argument_list|)
expr_stmt|;
name|DiagObj
operator|->
name|DiagArgumentsKind
index|[
name|NumArgs
index|]
operator|=
name|Kind
expr_stmt|;
name|DiagObj
operator|->
name|DiagArgumentsVal
index|[
name|NumArgs
operator|++
index|]
operator|=
name|V
expr_stmt|;
block|}
name|void
name|AddSourceRange
argument_list|(
specifier|const
name|CharSourceRange
operator|&
name|R
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isActive
argument_list|()
operator|&&
literal|"Clients must not add to cleared diagnostic!"
argument_list|)
expr_stmt|;
name|DiagObj
operator|->
name|DiagRanges
operator|.
name|push_back
argument_list|(
name|R
argument_list|)
expr_stmt|;
block|}
name|void
name|AddFixItHint
argument_list|(
specifier|const
name|FixItHint
operator|&
name|Hint
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isActive
argument_list|()
operator|&&
literal|"Clients must not add to cleared diagnostic!"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Hint
operator|.
name|isNull
argument_list|()
condition|)
name|DiagObj
operator|->
name|DiagFixItHints
operator|.
name|push_back
argument_list|(
name|Hint
argument_list|)
expr_stmt|;
block|}
name|void
name|addFlagValue
argument_list|(
name|StringRef
name|V
argument_list|)
decl|const
block|{
name|DiagObj
operator|->
name|FlagValue
operator|=
name|V
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|AddFlagValue
block|{
name|explicit
name|AddFlagValue
argument_list|(
argument|StringRef V
argument_list|)
block|:
name|Val
argument_list|(
argument|V
argument_list|)
block|{}
name|StringRef
name|Val
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Register a value for the flag in the current diagnostic. This
end_comment

begin_comment
comment|/// value will be shown as the suffix "=value" after the flag name. It is
end_comment

begin_comment
comment|/// useful in cases where the diagnostic flag accepts values (e.g.,
end_comment

begin_comment
comment|/// -Rpass or -Wframe-larger-than).
end_comment

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
specifier|const
name|AddFlagValue
name|V
operator|)
block|{
name|DB
operator|.
name|addFlagValue
argument_list|(
name|V
operator|.
name|Val
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|StringRef
name|S
operator|)
block|{
name|DB
operator|.
name|AddString
argument_list|(
name|S
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
specifier|const
name|char
operator|*
name|Str
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|Str
operator|)
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_c_string
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|int
name|I
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|I
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_sint
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_comment
comment|// We use enable_if here to prevent that this overload is selected for
end_comment

begin_comment
comment|// pointers or other arguments that are implicitly convertible to bool.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_same
operator|<
name|T
operator|,
name|bool
operator|>
operator|::
name|value
operator|,
specifier|const
name|DiagnosticBuilder
operator|&
operator|>
operator|::
name|type
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|T
name|I
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|I
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_sint
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|unsigned
name|I
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|I
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_uint
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|tok
operator|::
name|TokenKind
name|I
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|I
operator|)
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_tokenkind
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
specifier|const
name|IdentifierInfo
operator|*
name|II
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|II
operator|)
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_identifierinfo
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_comment
comment|// Adds a DeclContext to the diagnostic. The enable_if template magic is here
end_comment

begin_comment
comment|// so that we only match those arguments that are (statically) DeclContexts;
end_comment

begin_comment
comment|// other arguments that derive from DeclContext (e.g., RecordDecls) will not
end_comment

begin_comment
comment|// match.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_same
operator|<
name|typename
name|std
operator|::
name|remove_const
operator|<
name|T
operator|>
operator|::
name|type
operator|,
name|DeclContext
operator|>
operator|::
name|value
operator|,
specifier|const
name|DiagnosticBuilder
operator|&
operator|>
operator|::
name|type
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|T
operator|*
name|DC
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|DC
operator|)
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_declcontext
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|SourceRange
name|R
operator|)
block|{
name|DB
operator|.
name|AddSourceRange
argument_list|(
name|CharSourceRange
operator|::
name|getTokenRange
argument_list|(
name|R
argument_list|)
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|ArrayRef
operator|<
name|SourceRange
operator|>
name|Ranges
operator|)
block|{
for|for
control|(
name|SourceRange
name|R
range|:
name|Ranges
control|)
name|DB
operator|.
name|AddSourceRange
argument_list|(
name|CharSourceRange
operator|::
name|getTokenRange
argument_list|(
name|R
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|DB
return|;
end_return

begin_expr_stmt
unit|}  inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
specifier|const
name|CharSourceRange
operator|&
name|R
operator|)
block|{
name|DB
operator|.
name|AddSourceRange
argument_list|(
name|R
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
specifier|const
name|FixItHint
operator|&
name|Hint
operator|)
block|{
name|DB
operator|.
name|AddFixItHint
argument_list|(
name|Hint
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|Hints
operator|)
block|{
for|for
control|(
specifier|const
name|FixItHint
modifier|&
name|Hint
range|:
name|Hints
control|)
name|DB
operator|.
name|AddFixItHint
argument_list|(
name|Hint
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|DB
return|;
end_return

begin_comment
unit|}
comment|/// A nullability kind paired with a bit indicating whether it used a
end_comment

begin_comment
comment|/// context-sensitive keyword.
end_comment

begin_expr_stmt
unit|typedef
name|std
operator|::
name|pair
operator|<
name|NullabilityKind
operator|,
name|bool
operator|>
name|DiagNullabilityKind
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|DiagNullabilityKind
name|nullability
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|inline
name|DiagnosticBuilder
name|DiagnosticsEngine
operator|::
name|Report
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|unsigned DiagID
argument_list|)
block|{
name|assert
argument_list|(
name|CurDiagID
operator|==
operator|~
literal|0U
operator|&&
literal|"Multiple diagnostics in flight at once!"
argument_list|)
block|;
name|CurDiagLoc
operator|=
name|Loc
block|;
name|CurDiagID
operator|=
name|DiagID
block|;
name|FlagValue
operator|.
name|clear
argument_list|()
block|;
return|return
name|DiagnosticBuilder
argument_list|(
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|DiagnosticBuilder
name|DiagnosticsEngine
operator|::
name|Report
argument_list|(
argument|unsigned DiagID
argument_list|)
block|{
return|return
name|Report
argument_list|(
name|SourceLocation
argument_list|()
argument_list|,
name|DiagID
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Diagnostic
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// A little helper class (which is basically a smart pointer that forwards
end_comment

begin_comment
comment|/// info from DiagnosticsEngine) that allows clients to enquire about the
end_comment

begin_comment
comment|/// currently in-flight diagnostic.
end_comment

begin_decl_stmt
name|class
name|Diagnostic
block|{
specifier|const
name|DiagnosticsEngine
modifier|*
name|DiagObj
decl_stmt|;
name|StringRef
name|StoredDiagMessage
decl_stmt|;
name|public
label|:
name|explicit
name|Diagnostic
argument_list|(
specifier|const
name|DiagnosticsEngine
operator|*
name|DO
argument_list|)
operator|:
name|DiagObj
argument_list|(
argument|DO
argument_list|)
block|{}
name|Diagnostic
argument_list|(
argument|const DiagnosticsEngine *DO
argument_list|,
argument|StringRef storedDiagMessage
argument_list|)
operator|:
name|DiagObj
argument_list|(
name|DO
argument_list|)
operator|,
name|StoredDiagMessage
argument_list|(
argument|storedDiagMessage
argument_list|)
block|{}
specifier|const
name|DiagnosticsEngine
operator|*
name|getDiags
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
return|;
block|}
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|CurDiagID
return|;
block|}
specifier|const
name|SourceLocation
operator|&
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|CurDiagLoc
return|;
block|}
name|bool
name|hasSourceManager
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|hasSourceManager
argument_list|()
return|;
block|}
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|getSourceManager
argument_list|()
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|NumDiagArgs
return|;
block|}
comment|/// \brief Return the kind of the specified index.
comment|///
comment|/// Based on the kind of argument, the accessors below can be used to get
comment|/// the value.
comment|///
comment|/// \pre Idx< getNumArgs()
name|DiagnosticsEngine
operator|::
name|ArgumentKind
name|getArgKind
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getNumArgs
argument_list|()
operator|&&
literal|"Argument index out of range!"
argument_list|)
block|;
return|return
operator|(
name|DiagnosticsEngine
operator|::
name|ArgumentKind
operator|)
name|DiagObj
operator|->
name|DiagArgumentsKind
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Return the provided argument string specified by \p Idx.
comment|/// \pre getArgKind(Idx) == DiagnosticsEngine::ak_std_string
specifier|const
name|std
operator|::
name|string
operator|&
name|getArgStdStr
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|getArgKind
argument_list|(
name|Idx
argument_list|)
operator|==
name|DiagnosticsEngine
operator|::
name|ak_std_string
operator|&&
literal|"invalid argument accessor!"
argument_list|)
block|;
return|return
name|DiagObj
operator|->
name|DiagArgumentsStr
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Return the specified C string argument.
comment|/// \pre getArgKind(Idx) == DiagnosticsEngine::ak_c_string
specifier|const
name|char
modifier|*
name|getArgCStr
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getArgKind
argument_list|(
name|Idx
argument_list|)
operator|==
name|DiagnosticsEngine
operator|::
name|ak_c_string
operator|&&
literal|"invalid argument accessor!"
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|DiagObj
operator|->
name|DiagArgumentsVal
index|[
name|Idx
index|]
operator|)
return|;
block|}
comment|/// \brief Return the specified signed integer argument.
comment|/// \pre getArgKind(Idx) == DiagnosticsEngine::ak_sint
name|int
name|getArgSInt
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getArgKind
argument_list|(
name|Idx
argument_list|)
operator|==
name|DiagnosticsEngine
operator|::
name|ak_sint
operator|&&
literal|"invalid argument accessor!"
argument_list|)
expr_stmt|;
return|return
operator|(
name|int
operator|)
name|DiagObj
operator|->
name|DiagArgumentsVal
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Return the specified unsigned integer argument.
comment|/// \pre getArgKind(Idx) == DiagnosticsEngine::ak_uint
name|unsigned
name|getArgUInt
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getArgKind
argument_list|(
name|Idx
argument_list|)
operator|==
name|DiagnosticsEngine
operator|::
name|ak_uint
operator|&&
literal|"invalid argument accessor!"
argument_list|)
expr_stmt|;
return|return
operator|(
name|unsigned
operator|)
name|DiagObj
operator|->
name|DiagArgumentsVal
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Return the specified IdentifierInfo argument.
comment|/// \pre getArgKind(Idx) == DiagnosticsEngine::ak_identifierinfo
specifier|const
name|IdentifierInfo
modifier|*
name|getArgIdentifier
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getArgKind
argument_list|(
name|Idx
argument_list|)
operator|==
name|DiagnosticsEngine
operator|::
name|ak_identifierinfo
operator|&&
literal|"invalid argument accessor!"
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
name|DiagObj
operator|->
name|DiagArgumentsVal
index|[
name|Idx
index|]
operator|)
return|;
block|}
comment|/// \brief Return the specified non-string argument in an opaque form.
comment|/// \pre getArgKind(Idx) != DiagnosticsEngine::ak_std_string
name|intptr_t
name|getRawArg
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getArgKind
argument_list|(
name|Idx
argument_list|)
operator|!=
name|DiagnosticsEngine
operator|::
name|ak_std_string
operator|&&
literal|"invalid argument accessor!"
argument_list|)
expr_stmt|;
return|return
name|DiagObj
operator|->
name|DiagArgumentsVal
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Return the number of source ranges associated with this diagnostic.
name|unsigned
name|getNumRanges
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|DiagRanges
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \pre Idx< getNumRanges()
specifier|const
name|CharSourceRange
modifier|&
name|getRange
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getNumRanges
argument_list|()
operator|&&
literal|"Invalid diagnostic range index!"
argument_list|)
expr_stmt|;
return|return
name|DiagObj
operator|->
name|DiagRanges
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Return an array reference for this diagnostic's ranges.
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|getRanges
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|DiagRanges
return|;
block|}
name|unsigned
name|getNumFixItHints
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|DiagFixItHints
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|FixItHint
modifier|&
name|getFixItHint
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getNumFixItHints
argument_list|()
operator|&&
literal|"Invalid index!"
argument_list|)
expr_stmt|;
return|return
name|DiagObj
operator|->
name|DiagFixItHints
index|[
name|Idx
index|]
return|;
block|}
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|getFixItHints
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|DiagFixItHints
return|;
block|}
comment|/// \brief Format this diagnostic into a string, substituting the
comment|/// formal arguments into the %0 slots.
comment|///
comment|/// The result is appended onto the \p OutStr array.
name|void
name|FormatDiagnostic
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|OutStr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Format the given format-string into the output buffer using the
comment|/// arguments stored in this diagnostic.
name|void
name|FormatDiagnostic
argument_list|(
specifier|const
name|char
operator|*
name|DiagStr
argument_list|,
specifier|const
name|char
operator|*
name|DiagEnd
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|OutStr
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * \brief Represents a diagnostic in a form that can be retained until its   * corresponding source manager is destroyed.   */
end_comment

begin_decl_stmt
name|class
name|StoredDiagnostic
block|{
name|unsigned
name|ID
decl_stmt|;
name|DiagnosticsEngine
operator|::
name|Level
name|Level
expr_stmt|;
name|FullSourceLoc
name|Loc
decl_stmt|;
name|std
operator|::
name|string
name|Message
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|CharSourceRange
operator|>
name|Ranges
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|FixItHint
operator|>
name|FixIts
expr_stmt|;
name|public
label|:
name|StoredDiagnostic
argument_list|()
operator|=
expr|default
expr_stmt|;
name|StoredDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|const Diagnostic&Info
argument_list|)
empty_stmt|;
name|StoredDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|unsigned ID
argument_list|,
argument|StringRef Message
argument_list|)
empty_stmt|;
name|StoredDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level Level
argument_list|,
argument|unsigned ID
argument_list|,
argument|StringRef Message
argument_list|,
argument|FullSourceLoc Loc
argument_list|,
argument|ArrayRef<CharSourceRange> Ranges
argument_list|,
argument|ArrayRef<FixItHint> Fixits
argument_list|)
empty_stmt|;
comment|/// \brief Evaluates true when this object stores a diagnostic.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Message
operator|.
name|empty
argument_list|()
return|;
block|}
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|DiagnosticsEngine
operator|::
name|Level
name|getLevel
argument_list|()
specifier|const
block|{
return|return
name|Level
return|;
block|}
specifier|const
name|FullSourceLoc
operator|&
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|StringRef
name|getMessage
argument_list|()
specifier|const
block|{
return|return
name|Message
return|;
block|}
name|void
name|setLocation
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|)
block|{
name|this
operator|->
name|Loc
operator|=
name|Loc
expr_stmt|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CharSourceRange
operator|>
operator|::
name|const_iterator
name|range_iterator
expr_stmt|;
name|range_iterator
name|range_begin
argument_list|()
specifier|const
block|{
return|return
name|Ranges
operator|.
name|begin
argument_list|()
return|;
block|}
name|range_iterator
name|range_end
argument_list|()
specifier|const
block|{
return|return
name|Ranges
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|range_size
argument_list|()
specifier|const
block|{
return|return
name|Ranges
operator|.
name|size
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|getRanges
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|Ranges
argument_list|)
return|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|FixItHint
operator|>
operator|::
name|const_iterator
name|fixit_iterator
expr_stmt|;
name|fixit_iterator
name|fixit_begin
argument_list|()
specifier|const
block|{
return|return
name|FixIts
operator|.
name|begin
argument_list|()
return|;
block|}
name|fixit_iterator
name|fixit_end
argument_list|()
specifier|const
block|{
return|return
name|FixIts
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|fixit_size
argument_list|()
specifier|const
block|{
return|return
name|FixIts
operator|.
name|size
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|FixItHint
operator|>
name|getFixIts
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|FixIts
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Abstract interface, implemented by clients of the front-end, which
end_comment

begin_comment
comment|/// formats and prints fully processed diagnostics.
end_comment

begin_decl_stmt
name|class
name|DiagnosticConsumer
block|{
name|protected
label|:
name|unsigned
name|NumWarnings
init|=
literal|0
decl_stmt|;
comment|///< Number of warnings reported
name|unsigned
name|NumErrors
init|=
literal|0
decl_stmt|;
comment|///< Number of errors reported
name|public
label|:
name|DiagnosticConsumer
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
operator|~
name|DiagnosticConsumer
argument_list|()
expr_stmt|;
name|unsigned
name|getNumErrors
argument_list|()
specifier|const
block|{
return|return
name|NumErrors
return|;
block|}
name|unsigned
name|getNumWarnings
argument_list|()
specifier|const
block|{
return|return
name|NumWarnings
return|;
block|}
name|virtual
name|void
name|clear
parameter_list|()
block|{
name|NumWarnings
operator|=
name|NumErrors
operator|=
literal|0
expr_stmt|;
block|}
comment|/// \brief Callback to inform the diagnostic client that processing
comment|/// of a source file is beginning.
comment|///
comment|/// Note that diagnostics may be emitted outside the processing of a source
comment|/// file, for example during the parsing of command line options. However,
comment|/// diagnostics with source range information are required to only be emitted
comment|/// in between BeginSourceFile() and EndSourceFile().
comment|///
comment|/// \param LangOpts The language options for the source file being processed.
comment|/// \param PP The preprocessor object being used for the source; this is
comment|/// optional, e.g., it may not be present when processing AST source files.
name|virtual
name|void
name|BeginSourceFile
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
specifier|const
name|Preprocessor
modifier|*
name|PP
init|=
name|nullptr
parameter_list|)
block|{}
comment|/// \brief Callback to inform the diagnostic client that processing
comment|/// of a source file has ended.
comment|///
comment|/// The diagnostic client should assume that any objects made available via
comment|/// BeginSourceFile() are inaccessible.
name|virtual
name|void
name|EndSourceFile
parameter_list|()
block|{}
comment|/// \brief Callback to inform the diagnostic client that processing of all
comment|/// source files has ended.
name|virtual
name|void
name|finish
parameter_list|()
block|{}
comment|/// \brief Indicates whether the diagnostics handled by this
comment|/// DiagnosticConsumer should be included in the number of diagnostics
comment|/// reported by DiagnosticsEngine.
comment|///
comment|/// The default implementation returns true.
name|virtual
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Handle this diagnostic, reporting it to the user or
comment|/// capturing it to a log as needed.
comment|///
comment|/// The default implementation just keeps track of the total number of
comment|/// warnings and errors.
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
name|DiagnosticsEngine
operator|::
name|Level
name|DiagLevel
argument_list|,
specifier|const
name|Diagnostic
operator|&
name|Info
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A diagnostic client that ignores all diagnostics.
end_comment

begin_decl_stmt
name|class
name|IgnoringDiagConsumer
range|:
name|public
name|DiagnosticConsumer
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|void
name|HandleDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level DiagLevel
argument_list|,
argument|const Diagnostic&Info
argument_list|)
name|override
block|{
comment|// Just ignore it.
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Diagnostic consumer that forwards diagnostics along to an
end_comment

begin_comment
comment|/// existing, already-initialized diagnostic consumer.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ForwardingDiagnosticConsumer
range|:
name|public
name|DiagnosticConsumer
block|{
name|DiagnosticConsumer
operator|&
name|Target
block|;
name|public
operator|:
name|ForwardingDiagnosticConsumer
argument_list|(
name|DiagnosticConsumer
operator|&
name|Target
argument_list|)
operator|:
name|Target
argument_list|(
argument|Target
argument_list|)
block|{}
operator|~
name|ForwardingDiagnosticConsumer
argument_list|()
name|override
block|;
name|void
name|HandleDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level DiagLevel
argument_list|,
argument|const Diagnostic&Info
argument_list|)
name|override
block|;
name|void
name|clear
argument_list|()
name|override
block|;
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Struct used for sending info about how a type should be printed.
end_comment

begin_struct
struct|struct
name|TemplateDiffTypes
block|{
name|intptr_t
name|FromType
decl_stmt|;
name|intptr_t
name|ToType
decl_stmt|;
name|unsigned
name|PrintTree
range|:
literal|1
decl_stmt|;
name|unsigned
name|PrintFromType
range|:
literal|1
decl_stmt|;
name|unsigned
name|ElideType
range|:
literal|1
decl_stmt|;
name|unsigned
name|ShowColors
range|:
literal|1
decl_stmt|;
comment|// The printer sets this variable to true if the template diff was used.
name|unsigned
name|TemplateDiffUsed
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Special character that the diagnostic printer will use to toggle the bold
end_comment

begin_comment
comment|/// attribute.  The character itself will be not be printed.
end_comment

begin_decl_stmt
specifier|const
name|char
name|ToggleHighlight
init|=
literal|127
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ProcessWarningOptions - Initialize the diagnostic client and process the
end_comment

begin_comment
comment|/// warning options specified on the command line.
end_comment

begin_function_decl
name|void
name|ProcessWarningOptions
parameter_list|(
name|DiagnosticsEngine
modifier|&
name|Diags
parameter_list|,
specifier|const
name|DiagnosticOptions
modifier|&
name|Opts
parameter_list|,
name|bool
name|ReportDiags
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_DIAGNOSTIC_H
end_comment

end_unit

