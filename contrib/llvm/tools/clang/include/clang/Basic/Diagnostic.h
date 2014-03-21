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
name|LLVM_CLANG_DIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DIAGNOSTIC_H
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
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<list>
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
name|DiagnosticConsumer
decl_stmt|;
name|class
name|DiagnosticBuilder
decl_stmt|;
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|DiagnosticErrorTrap
decl_stmt|;
name|class
name|StoredDiagnostic
decl_stmt|;
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
block|;
comment|/// \brief How do we handle otherwise-unmapped extension?
comment|///
comment|/// This is controlled by -pedantic and -pedantic-errors.
block|enum
name|ExtensionHandling
block|{
name|Ext_Ignore
block|,
name|Ext_Warn
block|,
name|Ext_Error
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
comment|///< pair<QualType, QualType>
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
name|IgnoreAllWarnings
decl_stmt|;
comment|// Ignore all warnings: -w
name|bool
name|WarningsAsErrors
decl_stmt|;
comment|// Treat warnings like errors.
name|bool
name|EnableAllWarnings
decl_stmt|;
comment|// Enable all warnings.
name|bool
name|ErrorsAsFatal
decl_stmt|;
comment|// Treat errors like fatal errors.
name|bool
name|SuppressSystemWarnings
decl_stmt|;
comment|// Suppress warnings in system headers.
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
name|ExtensionHandling
name|ExtBehavior
decl_stmt|;
comment|// Map extensions onto warnings or errors?
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
name|bool
name|OwnsDiagClient
decl_stmt|;
name|SourceManager
modifier|*
name|SourceMgr
decl_stmt|;
comment|/// \brief Mapping information for diagnostics.
comment|///
comment|/// Mapping info is packed into four bits per diagnostic.  The low three
comment|/// bits are the mapping (an instance of diag::Mapping), or zero if unset.
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
name|DiagnosticMappingInfo
operator|>
name|DiagMap
expr_stmt|;
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|DiagnosticMappingInfo
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
name|DiagnosticMappingInfo
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|void
name|setMappingInfo
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|,
name|DiagnosticMappingInfo
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
name|DiagnosticMappingInfo
modifier|&
name|getOrAddMappingInfo
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
name|FullSourceLoc
name|Loc
decl_stmt|;
name|DiagStatePoint
argument_list|(
argument|DiagState *State
argument_list|,
argument|FullSourceLoc Loc
argument_list|)
block|:
name|State
argument_list|(
name|State
argument_list|)
operator|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{ }
name|bool
name|operator
operator|<
operator|(
specifier|const
name|DiagStatePoint
operator|&
name|RHS
operator|)
specifier|const
block|{
comment|// If Loc is invalid it means it came from<command-line>, in which case
comment|// we regard it as coming before any valid source location.
if|if
condition|(
name|RHS
operator|.
name|Loc
operator|.
name|isInvalid
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Loc
operator|.
name|isInvalid
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|Loc
operator|.
name|isBeforeInTranslationUnitThan
argument_list|(
name|RHS
operator|.
name|Loc
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A sorted vector of all DiagStatePoints representing changes in
end_comment

begin_comment
comment|/// diagnostic state due to diagnostic pragmas.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The vector is always sorted according to the SourceLocation of the
end_comment

begin_comment
comment|/// DiagStatePoint.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DiagStatePoint
operator|>
name|DiagStatePointsTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|mutable
name|DiagStatePointsTy
name|DiagStatePoints
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Keeps the DiagState that was active during each diagnostic 'push'
end_comment

begin_comment
comment|/// so we can get back at it when we 'pop'.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|DiagState
operator|*
operator|>
name|DiagStateOnPushStack
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DiagState
operator|*
name|GetCurDiagState
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|DiagStatePoints
operator|.
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|DiagStatePoints
operator|.
name|back
argument_list|()
operator|.
name|State
return|;
block|}
end_expr_stmt

begin_function
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
block|{
name|FullSourceLoc
name|Loc
argument_list|(
name|L
argument_list|,
name|getSourceManager
argument_list|()
argument_list|)
decl_stmt|;
comment|// Make sure that DiagStatePoints is always sorted according to Loc.
name|assert
argument_list|(
name|Loc
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Adding invalid loc point"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|DiagStatePoints
operator|.
name|empty
argument_list|()
operator|&&
operator|(
name|DiagStatePoints
operator|.
name|back
argument_list|()
operator|.
name|Loc
operator|.
name|isInvalid
argument_list|()
operator|||
name|DiagStatePoints
operator|.
name|back
argument_list|()
operator|.
name|Loc
operator|.
name|isBeforeInTranslationUnitThan
argument_list|(
name|Loc
argument_list|)
operator|)
operator|&&
literal|"Previous point loc comes after or is the same as new one"
argument_list|)
expr_stmt|;
name|DiagStatePoints
operator|.
name|push_back
argument_list|(
name|DiagStatePoint
argument_list|(
name|State
argument_list|,
name|Loc
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Finds the DiagStatePoint that contains the diagnostic state of
end_comment

begin_comment
comment|/// the given source location.
end_comment

begin_expr_stmt
name|DiagStatePointsTy
operator|::
name|iterator
name|GetDiagStatePointForLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Sticky flag set to \c true when an error is emitted.
end_comment

begin_decl_stmt
name|bool
name|ErrorOccurred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Sticky flag set to \c true when an "uncompilable error" occurs.
end_comment

begin_comment
comment|/// I.e. an error that was not upgraded from a warning by -Werror.
end_comment

begin_decl_stmt
name|bool
name|UncompilableErrorOccurred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Sticky flag set to \c true when a fatal error is emitted.
end_comment

begin_decl_stmt
name|bool
name|FatalErrorOccurred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Indicates that an unrecoverable error has occurred.
end_comment

begin_decl_stmt
name|bool
name|UnrecoverableErrorOccurred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Counts for DiagnosticErrorTrap to check whether an error occurred
end_comment

begin_comment
comment|/// during a parsing section, e.g. during parsing a function.
end_comment

begin_decl_stmt
name|unsigned
name|TrapNumErrorsOccurred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|TrapNumUnrecoverableErrorsOccurred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The level of the last diagnostic emitted.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to emit continuation diagnostics with the same level as the
end_comment

begin_comment
comment|/// diagnostic that they follow.
end_comment

begin_expr_stmt
name|DiagnosticIDs
operator|::
name|Level
name|LastDiagLevel
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|NumWarnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Number of warnings reported
end_comment

begin_decl_stmt
name|unsigned
name|NumErrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Number of errors reported
end_comment

begin_decl_stmt
name|unsigned
name|NumErrorsSuppressed
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Number of errors suppressed
end_comment

begin_comment
comment|/// \brief A function pointer that converts an opaque diagnostic
end_comment

begin_comment
comment|/// argument to a strings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This takes the modifiers and argument that was present in the diagnostic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The PrevArgs array (whose length is NumPrevArgs) indicates the previous
end_comment

begin_comment
comment|/// arguments formatted for this diagnostic.  Implementations of this function
end_comment

begin_comment
comment|/// can use this information to avoid redundancy across arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a hack to avoid a layering violation between libbasic and libsema.
end_comment

begin_typedef
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
specifier|const
name|char
operator|*
name|Modifier
operator|,
name|unsigned
name|ModifierLen
operator|,
specifier|const
name|char
operator|*
name|Argument
operator|,
name|unsigned
name|ArgumentLen
operator|,
specifier|const
name|ArgumentValue
operator|*
name|PrevArgs
operator|,
name|unsigned
name|NumPrevArgs
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
end_typedef

begin_decl_stmt
name|void
modifier|*
name|ArgToStringCookie
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ArgToStringFnTy
name|ArgToStringFn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief ID of the "delayed" diagnostic, which is a (typically
end_comment

begin_comment
comment|/// fatal) diagnostic that had to be delayed because it was found
end_comment

begin_comment
comment|/// while emitting another diagnostic.
end_comment

begin_decl_stmt
name|unsigned
name|DelayedDiagID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief First string argument for the delayed diagnostic.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|DelayedDiagArg1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Second string argument for the delayed diagnostic.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|DelayedDiagArg2
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|explicit
name|DiagnosticsEngine
argument_list|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticIDs
operator|>
operator|&
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
literal|0
argument_list|,
name|bool
name|ShouldOwnClient
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|~
name|DiagnosticsEngine
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the diagnostic options.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function
name|DiagnosticConsumer
modifier|*
name|getClient
parameter_list|()
block|{
return|return
name|Client
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this \c DiagnosticsEngine object own its client.
end_comment

begin_expr_stmt
name|bool
name|ownsClient
argument_list|()
specifier|const
block|{
return|return
name|OwnsDiagClient
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the current diagnostic client along with ownership of that
end_comment

begin_comment
comment|/// client.
end_comment

begin_function
name|DiagnosticConsumer
modifier|*
name|takeClient
parameter_list|()
block|{
name|OwnsDiagClient
operator|=
name|false
expr_stmt|;
return|return
name|Client
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|hasSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setSourceManager
parameter_list|(
name|SourceManager
modifier|*
name|SrcMgr
parameter_list|)
block|{
name|SourceMgr
operator|=
name|SrcMgr
expr_stmt|;
block|}
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//  DiagnosticsEngine characterization methods, used by a client to customize
end_comment

begin_comment
comment|//  how diagnostics are emitted.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \brief Copies the current DiagMappings and pushes the new copy
end_comment

begin_comment
comment|/// onto the top of the stack.
end_comment

begin_function_decl
name|void
name|pushMappings
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Pops the current DiagMappings off the top of the stack,
end_comment

begin_comment
comment|/// causing the new top of the stack to be the active mappings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns \c true if the pop happens, \c false if there is only one
end_comment

begin_comment
comment|/// DiagMapping on the stack.
end_comment

begin_function_decl
name|bool
name|popMappings
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Set the diagnostic client associated with this diagnostic object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ShouldOwnClient true if the diagnostic object should take
end_comment

begin_comment
comment|/// ownership of \c client.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Specify a limit for the number of errors we should
end_comment

begin_comment
comment|/// emit before giving up.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Zero disables the limit.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Specify the maximum number of template instantiation
end_comment

begin_comment
comment|/// notes to emit along with a given diagnostic.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Retrieve the maximum number of template instantiation
end_comment

begin_comment
comment|/// notes to emit along with a given diagnostic.
end_comment

begin_expr_stmt
name|unsigned
name|getTemplateBacktraceLimit
argument_list|()
specifier|const
block|{
return|return
name|TemplateBacktraceLimit
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Specify the maximum number of constexpr evaluation
end_comment

begin_comment
comment|/// notes to emit along with a given diagnostic.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Retrieve the maximum number of constexpr evaluation
end_comment

begin_comment
comment|/// notes to emit along with a given diagnostic.
end_comment

begin_expr_stmt
name|unsigned
name|getConstexprBacktraceLimit
argument_list|()
specifier|const
block|{
return|return
name|ConstexprBacktraceLimit
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief When set to true, any unmapped warnings are ignored.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this and WarningsAsErrors are both set, then this one wins.
end_comment

begin_function
name|void
name|setIgnoreAllWarnings
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|IgnoreAllWarnings
operator|=
name|Val
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getIgnoreAllWarnings
argument_list|()
specifier|const
block|{
return|return
name|IgnoreAllWarnings
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief When set to true, any unmapped ignored warnings are no longer
end_comment

begin_comment
comment|/// ignored.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this and IgnoreAllWarnings are both set, then that one wins.
end_comment

begin_function
name|void
name|setEnableAllWarnings
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|EnableAllWarnings
operator|=
name|Val
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getEnableAllWarnings
argument_list|()
specifier|const
block|{
return|return
name|EnableAllWarnings
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief When set to true, any warnings reported are issued as errors.
end_comment

begin_function
name|void
name|setWarningsAsErrors
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|WarningsAsErrors
operator|=
name|Val
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getWarningsAsErrors
argument_list|()
specifier|const
block|{
return|return
name|WarningsAsErrors
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief When set to true, any error reported is made a fatal error.
end_comment

begin_function
name|void
name|setErrorsAsFatal
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|ErrorsAsFatal
operator|=
name|Val
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getErrorsAsFatal
argument_list|()
specifier|const
block|{
return|return
name|ErrorsAsFatal
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief When set to true mask warnings that come from system headers.
end_comment

begin_function
name|void
name|setSuppressSystemWarnings
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|SuppressSystemWarnings
operator|=
name|Val
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getSuppressSystemWarnings
argument_list|()
specifier|const
block|{
return|return
name|SuppressSystemWarnings
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Suppress all diagnostics, to silence the front end when we
end_comment

begin_comment
comment|/// know that we don't want any more diagnostics to be passed along to the
end_comment

begin_comment
comment|/// client
end_comment

begin_function
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
end_function

begin_expr_stmt
name|bool
name|getSuppressAllDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|SuppressAllDiagnostics
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set type eliding, to skip outputting same types occurring in
end_comment

begin_comment
comment|/// template types.
end_comment

begin_function
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
end_function

begin_function
name|bool
name|getElideType
parameter_list|()
block|{
return|return
name|ElideType
return|;
block|}
end_function

begin_comment
comment|/// \brief Set tree printing, to outputting the template difference in a
end_comment

begin_comment
comment|/// tree format.
end_comment

begin_function
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
end_function

begin_function
name|bool
name|getPrintTemplateTree
parameter_list|()
block|{
return|return
name|PrintTemplateTree
return|;
block|}
end_function

begin_comment
comment|/// \brief Set color printing, so the type diffing will inject color markers
end_comment

begin_comment
comment|/// into the output.
end_comment

begin_function
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
end_function

begin_function
name|bool
name|getShowColors
parameter_list|()
block|{
return|return
name|ShowColors
return|;
block|}
end_function

begin_comment
comment|/// \brief Specify which overload candidates to show when overload resolution
end_comment

begin_comment
comment|/// fails.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// By default, we show all candidates.
end_comment

begin_function
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
end_function

begin_expr_stmt
name|OverloadsShown
name|getShowOverloads
argument_list|()
specifier|const
block|{
return|return
name|ShowOverloads
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Pretend that the last diagnostic issued was ignored, so any
end_comment

begin_comment
comment|/// subsequent notes will be suppressed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can be used by clients who suppress diagnostics themselves.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Determine whether the previous diagnostic was ignored. This can
end_comment

begin_comment
comment|/// be used by clients that want to determine whether notes attached to a
end_comment

begin_comment
comment|/// diagnostic will be suppressed.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Controls whether otherwise-unmapped extension diagnostics are
end_comment

begin_comment
comment|/// mapped onto ignore/warning/error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to the GCC -pedantic and -pedantic-errors option.
end_comment

begin_function
name|void
name|setExtensionHandlingBehavior
parameter_list|(
name|ExtensionHandling
name|H
parameter_list|)
block|{
name|ExtBehavior
operator|=
name|H
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ExtensionHandling
name|getExtensionHandlingBehavior
argument_list|()
specifier|const
block|{
return|return
name|ExtBehavior
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Counter bumped when an __extension__  block is/ encountered.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When non-zero, all extension diagnostics are entirely silenced, no
end_comment

begin_comment
comment|/// matter how they are mapped.
end_comment

begin_function
name|void
name|IncrementAllExtensionsSilenced
parameter_list|()
block|{
operator|++
name|AllExtensionsSilenced
expr_stmt|;
block|}
end_function

begin_function
name|void
name|DecrementAllExtensionsSilenced
parameter_list|()
block|{
operator|--
name|AllExtensionsSilenced
expr_stmt|;
block|}
end_function

begin_function
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
end_function

begin_comment
comment|/// \brief This allows the client to specify that certain warnings are
end_comment

begin_comment
comment|/// ignored.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Notes can never be mapped, errors can only be mapped to fatal, and
end_comment

begin_comment
comment|/// WARNINGs and EXTENSIONs can be mapped arbitrarily.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The source location that this change of diagnostic state should
end_comment

begin_comment
comment|/// take affect. It can be null if we are setting the latest state.
end_comment

begin_decl_stmt
name|void
name|setDiagnosticMapping
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|,
name|diag
operator|::
name|Mapping
name|Map
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Change an entire diagnostic group (e.g. "unknown-pragmas") to
end_comment

begin_comment
comment|/// have the specified mapping.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true (and ignores the request) if "Group" was unknown, false
end_comment

begin_comment
comment|/// otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The source location that this change of diagnostic state should
end_comment

begin_comment
comment|/// take affect. It can be null if we are setting the state from command-line.
end_comment

begin_decl_stmt
name|bool
name|setDiagnosticGroupMapping
argument_list|(
name|StringRef
name|Group
argument_list|,
name|diag
operator|::
name|Mapping
name|Map
argument_list|,
name|SourceLocation
name|Loc
operator|=
name|SourceLocation
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Set the warning-as-error flag for the given diagnostic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function always only operates on the current diagnostic state.
end_comment

begin_decl_stmt
name|void
name|setDiagnosticWarningAsError
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|,
name|bool
name|Enabled
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Set the warning-as-error flag for the given diagnostic group.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function always only operates on the current diagnostic state.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns True if the given group is unknown, false otherwise.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Set the error-as-fatal flag for the given diagnostic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function always only operates on the current diagnostic state.
end_comment

begin_decl_stmt
name|void
name|setDiagnosticErrorAsFatal
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|,
name|bool
name|Enabled
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Set the error-as-fatal flag for the given diagnostic group.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function always only operates on the current diagnostic state.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns True if the given group is unknown, false otherwise.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Add the specified mapping to all diagnostics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Mainly to be used by -Wno-everything to disable all warnings but allow
end_comment

begin_comment
comment|/// subsequent -W options to enable specific warnings.
end_comment

begin_decl_stmt
name|void
name|setMappingToAllDiagnostics
argument_list|(
name|diag
operator|::
name|Mapping
name|Map
argument_list|,
name|SourceLocation
name|Loc
operator|=
name|SourceLocation
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|hasErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|ErrorOccurred
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Errors that actually prevent compilation, not those that are
end_comment

begin_comment
comment|/// upgraded from a warning by -Werror.
end_comment

begin_expr_stmt
name|bool
name|hasUncompilableErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|UncompilableErrorOccurred
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasFatalErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|FatalErrorOccurred
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether any kind of unrecoverable error has occurred.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNumWarnings
argument_list|()
specifier|const
block|{
return|return
name|NumWarnings
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_comment
comment|/// \brief Return an ID for a diagnostic with the specified message and level.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this is the first request for this diagnostic, it is registered and
end_comment

begin_comment
comment|/// created, otherwise the existing ID is returned.
end_comment

begin_function
name|unsigned
name|getCustomDiagID
parameter_list|(
name|Level
name|L
parameter_list|,
name|StringRef
name|Message
parameter_list|)
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
name|Message
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a diagnostic argument (as an intptr_t) into the string
end_comment

begin_comment
comment|/// that represents it.
end_comment

begin_decl_stmt
name|void
name|ConvertArgToString
argument_list|(
name|ArgumentKind
name|Kind
argument_list|,
name|intptr_t
name|Val
argument_list|,
specifier|const
name|char
operator|*
name|Modifier
argument_list|,
name|unsigned
name|ModLen
argument_list|,
specifier|const
name|char
operator|*
name|Argument
argument_list|,
name|unsigned
name|ArgLen
argument_list|,
specifier|const
name|ArgumentValue
operator|*
name|PrevArgs
argument_list|,
name|unsigned
name|NumPrevArgs
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
name|ModLen
argument_list|,
name|Argument
argument_list|,
name|ArgLen
argument_list|,
name|PrevArgs
argument_list|,
name|NumPrevArgs
argument_list|,
name|Output
argument_list|,
name|ArgToStringCookie
argument_list|,
name|QualTypeVals
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
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
end_function

begin_comment
comment|/// \brief Note that the prior diagnostic was emitted by some other
end_comment

begin_comment
comment|/// \c DiagnosticsEngine, and we may be attaching a note to that diagnostic.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Reset the state of the diagnostic object to its initial
end_comment

begin_comment
comment|/// configuration.
end_comment

begin_function_decl
name|void
name|Reset
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// DiagnosticsEngine classification and reporting interfaces.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \brief Based on the way the client configured the DiagnosticsEngine
end_comment

begin_comment
comment|/// object, classify the specified diagnostic ID into a Level, consumable by
end_comment

begin_comment
comment|/// the DiagnosticConsumer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The source location we are interested in finding out the
end_comment

begin_comment
comment|/// diagnostic state. Can be null in order to query the latest state.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Issue the message to the client.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This actually returns an instance of DiagnosticBuilder which emits the
end_comment

begin_comment
comment|/// diagnostics (through @c ProcessDiag) when it is destroyed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DiagID A member of the @c diag::kind enum.
end_comment

begin_comment
comment|/// \param Loc Represents the source location associated with the diagnostic,
end_comment

begin_comment
comment|/// which can be an invalid location if no position information is available.
end_comment

begin_function_decl
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
end_function_decl

begin_function_decl
specifier|inline
name|DiagnosticBuilder
name|Report
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Report
parameter_list|(
specifier|const
name|StoredDiagnostic
modifier|&
name|storedDiag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whethere there is already a diagnostic in flight.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Set the "delayed" diagnostic that will be emitted once
end_comment

begin_comment
comment|/// the current diagnostic completes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  If a diagnostic is already in-flight but the front end must
end_comment

begin_comment
comment|///  report a problem (e.g., with an inconsistent file system
end_comment

begin_comment
comment|///  state), this routine sets a "delayed" diagnostic that will be
end_comment

begin_comment
comment|///  emitted after the current diagnostic completes. This should
end_comment

begin_comment
comment|///  only be used for fatal errors detected at inconvenient
end_comment

begin_comment
comment|///  times. If emitting a delayed diagnostic causes a second delayed
end_comment

begin_comment
comment|///  diagnostic to be introduced, that second delayed diagnostic
end_comment

begin_comment
comment|///  will be ignored.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DiagID The ID of the diagnostic being delayed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Arg1 A string argument that will be provided to the
end_comment

begin_comment
comment|/// diagnostic. A copy of this string will be stored in the
end_comment

begin_comment
comment|/// DiagnosticsEngine object itself.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Arg2 A string argument that will be provided to the
end_comment

begin_comment
comment|/// diagnostic. A copy of this string will be stored in the
end_comment

begin_comment
comment|/// DiagnosticsEngine object itself.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Clear out the current diagnostic.
end_comment

begin_function
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
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Report the delayed diagnostic.
end_comment

begin_function_decl
name|void
name|ReportDelayed
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// This is private state used by DiagnosticBuilder.  We put it here instead of
end_comment

begin_comment
comment|// in DiagnosticBuilder in order to keep DiagnosticBuilder a small lightweight
end_comment

begin_comment
comment|// object.  This implementation choice means that we can only have one
end_comment

begin_comment
comment|// diagnostic "in flight" at a time, but this seems to be a reasonable
end_comment

begin_comment
comment|// tradeoff to keep these objects small.  Assertions verify that only one
end_comment

begin_comment
comment|// diagnostic is in flight at a time.
end_comment

begin_decl_stmt
name|friend
name|class
name|DiagnosticIDs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|DiagnosticBuilder
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|Diagnostic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|PartialDiagnostic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|DiagnosticErrorTrap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The location of the current diagnostic that is in flight.
end_comment

begin_decl_stmt
name|SourceLocation
name|CurDiagLoc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The ID of the current diagnostic that is in flight.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is set to ~0U when there is no diagnostic in flight.
end_comment

begin_decl_stmt
name|unsigned
name|CurDiagID
decl_stmt|;
end_decl_stmt

begin_enum
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
block|,
comment|/// \brief The maximum number of ranges we can hold.
name|MaxRanges
init|=
literal|10
block|,
comment|/// \brief The maximum number of ranges we can hold.
name|MaxFixItHints
init|=
literal|10
block|}
enum|;
end_enum

begin_comment
comment|/// \brief The number of entries in Arguments.
end_comment

begin_decl_stmt
name|signed
name|char
name|NumDiagArgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of ranges in the DiagRanges array.
end_comment

begin_decl_stmt
name|unsigned
name|char
name|NumDiagRanges
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of hints in the DiagFixItHints array.
end_comment

begin_decl_stmt
name|unsigned
name|char
name|NumDiagFixItHints
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Specifies whether an argument is in DiagArgumentsStr or
end_comment

begin_comment
comment|/// in DiagArguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is an array of ArgumentKind::ArgumentKind enum values, one for each
end_comment

begin_comment
comment|/// argument.
end_comment

begin_decl_stmt
name|unsigned
name|char
name|DiagArgumentsKind
index|[
name|MaxArguments
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Holds the values of each string argument for the current
end_comment

begin_comment
comment|/// diagnostic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is only used when the corresponding ArgumentKind is ak_std_string.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|DiagArgumentsStr
index|[
name|MaxArguments
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The values for the various substitution positions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used when the argument is not an std::string.  The specific
end_comment

begin_comment
comment|/// value is mangled into an intptr_t and the interpretation depends on
end_comment

begin_comment
comment|/// exactly what sort of argument kind it is.
end_comment

begin_decl_stmt
name|intptr_t
name|DiagArgumentsVal
index|[
name|MaxArguments
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The list of ranges added to this diagnostic.
end_comment

begin_decl_stmt
name|CharSourceRange
name|DiagRanges
index|[
name|MaxRanges
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief If valid, provides a hint with some code to insert, remove,
end_comment

begin_comment
comment|/// or modify at a particular position.
end_comment

begin_decl_stmt
name|FixItHint
name|DiagFixItHints
index|[
name|MaxFixItHints
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DiagnosticMappingInfo
name|makeMappingInfo
argument_list|(
name|diag
operator|::
name|Mapping
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
name|DiagnosticMappingInfo
name|MappingInfo
init|=
name|DiagnosticMappingInfo
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
name|MappingInfo
operator|.
name|setNoWarningAsError
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|MappingInfo
operator|.
name|setNoErrorAsFatal
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
return|return
name|MappingInfo
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Used to report a diagnostic that is finally fully formed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if the diagnostic was emitted, false if it was suppressed.
end_comment

begin_function
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
end_function

begin_comment
comment|/// @name Diagnostic Emission
end_comment

begin_comment
comment|/// @{
end_comment

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Sema requires access to the following functions because the current design
end_comment

begin_comment
comment|// of SFINAE requires it to use its own SemaDiagnosticBuilder, which needs to
end_comment

begin_comment
comment|// access us directly to ensure we minimize the emitted code for the common
end_comment

begin_comment
comment|// Sema::Diag() patterns.
end_comment

begin_decl_stmt
name|friend
name|class
name|Sema
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit the current diagnostic and clear the diagnostic state.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Force Emit the diagnostic regardless of suppression settings.
end_comment

begin_function_decl
name|bool
name|EmitCurrentDiagnostic
parameter_list|(
name|bool
name|Force
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|unsigned
name|getCurrentDiagID
argument_list|()
specifier|const
block|{
return|return
name|CurDiagID
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getCurrentDiagLoc
argument_list|()
specifier|const
block|{
return|return
name|CurDiagLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
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
decl_stmt|;
name|mutable
name|unsigned
name|NumArgs
decl_stmt|,
name|NumRanges
decl_stmt|,
name|NumFixits
decl_stmt|;
comment|/// \brief Status variable indicating if this diagnostic is still active.
comment|///
comment|// NOTE: This field is redundant with DiagObj (IsActive iff (DiagObj == 0)),
comment|// but LLVM is not currently smart enough to eliminate the null check that
comment|// Emit() would end up with if we used that as our status variable.
name|mutable
name|bool
name|IsActive
decl_stmt|;
comment|/// \brief Flag indicating that this diagnostic is being emitted via a
comment|/// call to ForceEmit.
name|mutable
name|bool
name|IsForceEmit
decl_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|friend
name|class
name|DiagnosticsEngine
decl_stmt|;
name|DiagnosticBuilder
argument_list|()
operator|:
name|DiagObj
argument_list|(
literal|0
argument_list|)
operator|,
name|NumArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRanges
argument_list|(
literal|0
argument_list|)
operator|,
name|NumFixits
argument_list|(
literal|0
argument_list|)
operator|,
name|IsActive
argument_list|(
name|false
argument_list|)
operator|,
name|IsForceEmit
argument_list|(
argument|false
argument_list|)
block|{ }
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
name|NumArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRanges
argument_list|(
literal|0
argument_list|)
operator|,
name|NumFixits
argument_list|(
literal|0
argument_list|)
operator|,
name|IsActive
argument_list|(
name|true
argument_list|)
operator|,
name|IsForceEmit
argument_list|(
argument|false
argument_list|)
block|{
name|assert
argument_list|(
name|diagObj
operator|&&
literal|"DiagnosticBuilder requires a valid DiagnosticsEngine!"
argument_list|)
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
name|DiagObj
operator|->
name|NumDiagRanges
operator|=
name|NumRanges
expr_stmt|;
name|DiagObj
operator|->
name|NumDiagFixItHints
operator|=
name|NumFixits
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
literal|0
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
name|NumRanges
operator|=
name|D
operator|.
name|NumRanges
expr_stmt|;
name|NumFixits
operator|=
name|D
operator|.
name|NumFixits
expr_stmt|;
block|}
comment|/// \brief Retrieve an empty diagnostic builder.
specifier|static
name|DiagnosticBuilder
name|getEmpty
parameter_list|()
block|{
return|return
name|DiagnosticBuilder
argument_list|()
return|;
block|}
comment|/// \brief Emits the diagnostic.
operator|~
name|DiagnosticBuilder
argument_list|()
block|{
name|Emit
argument_list|()
block|;   }
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
name|assert
argument_list|(
name|NumRanges
operator|<
name|DiagnosticsEngine
operator|::
name|MaxRanges
operator|&&
literal|"Too many arguments to diagnostic!"
argument_list|)
expr_stmt|;
name|DiagObj
operator|->
name|DiagRanges
index|[
name|NumRanges
operator|++
index|]
operator|=
name|R
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
name|assert
argument_list|(
name|NumFixits
operator|<
name|DiagnosticsEngine
operator|::
name|MaxFixItHints
operator|&&
literal|"Too many arguments to diagnostic!"
argument_list|)
expr_stmt|;
name|DiagObj
operator|->
name|DiagFixItHints
index|[
name|NumFixits
operator|++
index|]
operator|=
name|Hint
expr_stmt|;
block|}
name|bool
name|hasMaxRanges
argument_list|()
specifier|const
block|{
return|return
name|NumRanges
operator|==
name|DiagnosticsEngine
operator|::
name|MaxRanges
return|;
block|}
name|bool
name|hasMaxFixItHints
argument_list|()
specifier|const
block|{
return|return
name|NumFixits
operator|==
name|DiagnosticsEngine
operator|::
name|MaxFixItHints
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|bool
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
name|llvm
operator|::
name|enable_if
operator|<
name|llvm
operator|::
name|is_same
operator|<
name|T
operator|,
name|DeclContext
operator|>
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
specifier|const
name|SourceRange
operator|&
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
if|if
condition|(
operator|!
name|Hint
operator|.
name|isNull
argument_list|()
condition|)
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

begin_expr_stmt
unit|}  inline
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
name|NumDiagRanges
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
name|DiagObj
operator|->
name|NumDiagRanges
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
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|DiagObj
operator|->
name|DiagRanges
argument_list|,
name|DiagObj
operator|->
name|NumDiagRanges
argument_list|)
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
name|NumDiagFixItHints
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
specifier|const
name|FixItHint
operator|*
name|getFixItHints
argument_list|()
specifier|const
block|{
return|return
name|getNumFixItHints
argument_list|()
operator|?
name|DiagObj
operator|->
name|DiagFixItHints
operator|:
literal|0
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
operator|~
name|StoredDiagnostic
argument_list|()
expr_stmt|;
comment|/// \brief Evaluates true when this object stores a diagnostic.
name|LLVM_EXPLICIT
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Message
operator|.
name|size
argument_list|()
operator|>
literal|0
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
decl_stmt|;
comment|///< Number of warnings reported
name|unsigned
name|NumErrors
decl_stmt|;
comment|///< Number of errors reported
name|public
label|:
name|DiagnosticConsumer
argument_list|()
operator|:
name|NumWarnings
argument_list|(
literal|0
argument_list|)
operator|,
name|NumErrors
argument_list|(
literal|0
argument_list|)
block|{ }
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
name|virtual
operator|~
name|DiagnosticConsumer
argument_list|()
expr_stmt|;
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
literal|0
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
name|virtual
operator|~
name|ForwardingDiagnosticConsumer
argument_list|()
block|;
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level DiagLevel
argument_list|,
argument|const Diagnostic&Info
argument_list|)
block|;
name|virtual
name|void
name|clear
argument_list|()
block|;
name|virtual
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
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
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

