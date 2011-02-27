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
comment|//
end_comment

begin_comment
comment|//  This file defines the Diagnostic-related interfaces.
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
file|"clang/Basic/SourceLocation.h"
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
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticClient
decl_stmt|;
name|class
name|DiagnosticBuilder
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
comment|/// \brief The actual code to insert at the insertion location, as a
comment|/// string.
name|std
operator|::
name|string
name|CodeToInsert
expr_stmt|;
comment|/// \brief Empty code modification hint, indicating that no code
comment|/// modification is known.
name|FixItHint
argument_list|()
operator|:
name|RemoveRange
argument_list|()
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
argument_list|(
name|SourceLocation
name|InsertionLoc
argument_list|,
name|llvm
operator|::
name|StringRef
name|Code
argument_list|)
block|{
name|FixItHint
name|Hint
decl_stmt|;
name|Hint
operator|.
name|RemoveRange
operator|=
name|CharSourceRange
argument_list|(
name|SourceRange
argument_list|(
name|InsertionLoc
argument_list|,
name|InsertionLoc
argument_list|)
argument_list|,
name|false
argument_list|)
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
argument_list|(
name|CharSourceRange
name|RemoveRange
argument_list|,
name|llvm
operator|::
name|StringRef
name|Code
argument_list|)
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
argument_list|(
name|SourceRange
name|RemoveRange
argument_list|,
name|llvm
operator|::
name|StringRef
name|Code
argument_list|)
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
comment|/// Diagnostic - This concrete class is used by the front-end to report
comment|/// problems and issues.  It massages the diagnostics (e.g. handling things like
comment|/// "report warnings as errors" and passes them off to the DiagnosticClient for
comment|/// reporting to the user. Diagnostic is tied to one translation unit and
comment|/// one SourceManager.
name|class
name|Diagnostic
range|:
name|public
name|llvm
operator|::
name|RefCountedBase
operator|<
name|Diagnostic
operator|>
block|{
name|public
operator|:
comment|/// Level - The level of the diagnostic, after it has been through mapping.
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
comment|/// ExtensionHandling - How do we handle otherwise-unmapped extension?  This
comment|/// is controlled by -pedantic and -pedantic-errors.
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
comment|// std::string
name|ak_c_string
block|,
comment|// const char *
name|ak_sint
block|,
comment|// int
name|ak_uint
block|,
comment|// unsigned
name|ak_identifierinfo
block|,
comment|// IdentifierInfo
name|ak_qualtype
block|,
comment|// QualType
name|ak_declarationname
block|,
comment|// DeclarationName
name|ak_nameddecl
block|,
comment|// NamedDecl *
name|ak_nestednamespec
block|,
comment|// NestedNameSpecifier *
name|ak_declcontext
comment|// DeclContext *
block|}
block|;
comment|/// Specifies which overload candidates to display when overload resolution
comment|/// fails.
block|enum
name|OverloadsShown
block|{
name|Ovl_All
block|,
comment|///< Show all overloads.
name|Ovl_Best
comment|///< Show just the "best" overload candidates.
block|}
block|;
comment|/// ArgumentValue - This typedef represents on argument value, which is a
comment|/// union discriminated by ArgumentKind, with a value.
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
comment|// Treat warnings like errors:
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
name|ExtensionHandling
name|ExtBehavior
decl_stmt|;
comment|// Map extensions onto warnings or errors?
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticIDs
operator|>
name|Diags
expr_stmt|;
name|DiagnosticClient
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
comment|/// \brief Mapping information for diagnostics.  Mapping info is
comment|/// packed into four bits per diagnostic.  The low three bits are the mapping
comment|/// (an instance of diag::Mapping), or zero if unset.  The high bit is set
comment|/// when the mapping was established as a user mapping.  If the high bit is
comment|/// clear, then the low bits are set to the default value, and should be
comment|/// mapped with -pedantic, -Werror, etc.
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
name|unsigned
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
name|unsigned
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|void
name|setMapping
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|,
name|unsigned
name|Map
argument_list|)
block|{
name|DiagMap
index|[
name|Diag
index|]
operator|=
name|Map
expr_stmt|;
block|}
name|diag
operator|::
name|Mapping
name|getMapping
argument_list|(
argument|diag::kind Diag
argument_list|)
specifier|const
block|{
name|iterator
name|I
operator|=
name|DiagMap
operator|.
name|find
argument_list|(
name|Diag
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|DiagMap
operator|.
name|end
argument_list|()
condition|)
return|return
operator|(
name|diag
operator|::
name|Mapping
operator|)
name|I
operator|->
name|second
return|;
return|return
name|diag
operator|::
name|Mapping
argument_list|()
return|;
block|}
name|iterator
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
name|iterator
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Keeps and automatically disposes all DiagStates that we create.
end_comment

begin_expr_stmt
name|std
operator|::
name|list
operator|<
name|DiagState
operator|>
name|DiagStates
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Represents a point in source where the diagnostic state was
end_comment

begin_comment
comment|/// modified because of a pragma. 'Loc' can be null if the point represents
end_comment

begin_comment
comment|/// the diagnostic state modifications done through the command-line.
end_comment

begin_struct
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
end_struct

begin_comment
unit|};
comment|/// \brief A vector of all DiagStatePoints representing changes in diagnostic
end_comment

begin_comment
comment|/// state due to diagnostic pragmas. The vector is always sorted according to
end_comment

begin_comment
comment|/// the SourceLocation of the DiagStatePoint.
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
operator|*
name|SourceMgr
argument_list|)
decl_stmt|;
comment|// Make sure that DiagStatePoints is always sorted according to Loc.
name|assert
argument_list|(
operator|(
name|Loc
operator|.
name|isValid
argument_list|()
operator|||
name|DiagStatePoints
operator|.
name|empty
argument_list|()
operator|)
operator|&&
literal|"Adding invalid loc point after another point"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|Loc
operator|.
name|isInvalid
argument_list|()
operator|||
name|DiagStatePoints
operator|.
name|empty
argument_list|()
operator|||
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
name|FullSourceLoc
argument_list|(
name|Loc
argument_list|,
operator|*
name|SourceMgr
argument_list|)
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
comment|/// ErrorOccurred / FatalErrorOccurred - This is set to true when an error or
end_comment

begin_comment
comment|/// fatal error is emitted, and is sticky.
end_comment

begin_decl_stmt
name|bool
name|ErrorOccurred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|FatalErrorOccurred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// LastDiagLevel - This is the level of the last diagnostic emitted.  This is
end_comment

begin_comment
comment|/// used to emit continuation diagnostics with the same level as the
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
comment|// Number of warnings reported
end_comment

begin_decl_stmt
name|unsigned
name|NumErrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Number of errors reported
end_comment

begin_decl_stmt
name|unsigned
name|NumErrorsSuppressed
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Number of errors suppressed
end_comment

begin_comment
comment|/// ArgToStringFn - A function pointer that converts an opaque diagnostic
end_comment

begin_comment
comment|/// argument to a strings.  This takes the modifiers and argument that was
end_comment

begin_comment
comment|/// present in the diagnostic.
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
name|llvm
operator|::
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
name|Diagnostic
argument_list|(
specifier|const
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticIDs
operator|>
operator|&
name|Diags
argument_list|,
name|DiagnosticClient
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
name|Diagnostic
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
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

begin_function
name|DiagnosticClient
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
name|DiagnosticClient
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
comment|/// \brief Return the current diagnostic client along with ownership of that
end_comment

begin_comment
comment|/// client.
end_comment

begin_function
name|DiagnosticClient
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
comment|//  Diagnostic characterization methods, used by a client to customize how
end_comment

begin_comment
comment|//  diagnostics are emitted.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// pushMappings - Copies the current DiagMappings and pushes the new copy
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
comment|/// popMappings - Pops the current DiagMappings off the top of the stack
end_comment

begin_comment
comment|/// causing the new top of the stack to be the active mappings. Returns
end_comment

begin_comment
comment|/// true if the pop happens, false if there is only one DiagMapping on the
end_comment

begin_comment
comment|/// stack.
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
name|DiagnosticClient
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
comment|/// setErrorLimit - Specify a limit for the number of errors we should
end_comment

begin_comment
comment|/// emit before giving up.  Zero disables the limit.
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
comment|/// nodes to emit along with a given diagnostic.
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
comment|/// setIgnoreAllWarnings - When set to true, any unmapped warnings are
end_comment

begin_comment
comment|/// ignored.  If this and WarningsAsErrors are both set, then this one wins.
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
comment|/// setWarningsAsErrors - When set to true, any warnings reported are issued
end_comment

begin_comment
comment|/// as errors.
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
comment|/// setErrorsAsFatal - When set to true, any error reported is made a
end_comment

begin_comment
comment|/// fatal error.
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
comment|/// setSuppressSystemWarnings - When set to true mask warnings that
end_comment

begin_comment
comment|/// come from system headers.
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
comment|/// \brief Specify which overload candidates to show when overload resolution
end_comment

begin_comment
comment|/// fails.  By default, we show all candidates.
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
comment|/// \brief Pretend that the last diagnostic issued was ignored. This can
end_comment

begin_comment
comment|/// be used by clients who suppress diagnostics themselves.
end_comment

begin_function
name|void
name|setLastDiagnosticIgnored
parameter_list|()
block|{
name|LastDiagLevel
operator|=
name|DiagnosticIDs
operator|::
name|Ignored
expr_stmt|;
block|}
end_function

begin_comment
comment|/// setExtensionHandlingBehavior - This controls whether otherwise-unmapped
end_comment

begin_comment
comment|/// extension diagnostics are mapped onto ignore/warning/error.  This
end_comment

begin_comment
comment|/// corresponds to the GCC -pedantic and -pedantic-errors option.
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

begin_comment
comment|/// AllExtensionsSilenced - This is a counter bumped when an __extension__
end_comment

begin_comment
comment|/// block is encountered.  When non-zero, all extension diagnostics are
end_comment

begin_comment
comment|/// entirely silenced, no matter how they are mapped.
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
comment|/// \brief This allows the client to specify that certain
end_comment

begin_comment
comment|/// warnings are ignored.  Notes can never be mapped, errors can only be
end_comment

begin_comment
comment|/// mapped to fatal, and WARNINGs and EXTENSIONs can be mapped arbitrarily.
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
comment|/// setDiagnosticGroupMapping - Change an entire diagnostic group (e.g.
end_comment

begin_comment
comment|/// "unknown-pragmas" to have the specified mapping.  This returns true and
end_comment

begin_comment
comment|/// ignores the request if "Group" was unknown, false otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 'Loc' is the source location that this change of diagnostic state should
end_comment

begin_comment
comment|/// take affect. It can be null if we are setting the state from command-line.
end_comment

begin_decl_stmt
name|bool
name|setDiagnosticGroupMapping
argument_list|(
specifier|const
name|char
operator|*
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
block|{
return|return
name|Diags
operator|->
name|setDiagnosticGroupMapping
argument_list|(
name|Group
argument_list|,
name|Map
argument_list|,
name|Loc
argument_list|,
operator|*
name|this
argument_list|)
return|;
block|}
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
comment|/// getCustomDiagID - Return an ID for a diagnostic with the specified message
end_comment

begin_comment
comment|/// and level.  If this is the first request for this diagnosic, it is
end_comment

begin_comment
comment|/// registered and created, otherwise the existing ID is returned.
end_comment

begin_decl_stmt
name|unsigned
name|getCustomDiagID
argument_list|(
name|Level
name|L
argument_list|,
name|llvm
operator|::
name|StringRef
name|Message
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
name|Message
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// ConvertArgToString - This method converts a diagnostic argument (as an
end_comment

begin_comment
comment|/// intptr_t) into the string that represents it.
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
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Output
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
comment|// Diagnostic classification and reporting interfaces.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \brief Based on the way the client configured the Diagnostic
end_comment

begin_comment
comment|/// object, classify the specified diagnostic ID into a Level, consumable by
end_comment

begin_comment
comment|/// the DiagnosticClient.
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
argument_list|,
name|diag
operator|::
name|Mapping
operator|*
name|mapping
operator|=
literal|0
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
argument_list|,
name|mapping
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Report - Issue the message to the client.  @c DiagID is a member of the
end_comment

begin_comment
comment|/// @c diag::kind enum.  This actually returns aninstance of DiagnosticBuilder
end_comment

begin_comment
comment|/// which emits the diagnostics (through @c ProcessDiag) when it is destroyed.
end_comment

begin_comment
comment|/// @c Pos represents the source location associated with the diagnostic,
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
name|Pos
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
comment|/// Diagnostic object itself.
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
comment|/// Diagnostic object itself.
end_comment

begin_decl_stmt
name|void
name|SetDelayedDiagnostic
argument_list|(
name|unsigned
name|DiagID
argument_list|,
name|llvm
operator|::
name|StringRef
name|Arg1
operator|=
literal|""
argument_list|,
name|llvm
operator|::
name|StringRef
name|Arg2
operator|=
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// getDiagnosticMappingInfo - Return the mapping info currently set for the
end_comment

begin_comment
comment|/// specified builtin diagnostic.  This returns the high bit encoding, or zero
end_comment

begin_comment
comment|/// if the field is completely uninitialized.
end_comment

begin_expr_stmt
name|diag
operator|::
name|Mapping
name|getDiagnosticMappingInfo
argument_list|(
argument|diag::kind Diag
argument_list|,
argument|DiagState *State
argument_list|)
specifier|const
block|{
return|return
name|State
operator|->
name|getMapping
argument_list|(
name|Diag
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setDiagnosticMappingInternal
argument_list|(
name|unsigned
name|DiagId
argument_list|,
name|unsigned
name|Map
argument_list|,
name|DiagState
operator|*
name|State
argument_list|,
name|bool
name|isUser
argument_list|,
name|bool
name|isPragma
argument_list|)
decl|const
block|{
if|if
condition|(
name|isUser
condition|)
name|Map
operator||=
literal|8
expr_stmt|;
comment|// Set the high bit for user mappings.
if|if
condition|(
name|isPragma
condition|)
name|Map
operator||=
literal|0x10
expr_stmt|;
comment|// Set the bit for diagnostic pragma mappings.
name|State
operator|->
name|setMapping
argument_list|(
operator|(
name|diag
operator|::
name|kind
operator|)
name|DiagId
argument_list|,
name|Map
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

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
name|DiagnosticInfo
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
comment|/// CurDiagLoc - This is the location of the current diagnostic that is in
end_comment

begin_comment
comment|/// flight.
end_comment

begin_decl_stmt
name|SourceLocation
name|CurDiagLoc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CurDiagID - This is the ID of the current diagnostic that is in flight.
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
comment|/// MaxArguments - The maximum number of arguments we can hold. We currently
comment|/// only support up to 10 arguments (%0-%9).  A single diagnostic with more
comment|/// than that almost certainly has to be simplified anyway.
name|MaxArguments
init|=
literal|10
block|}
enum|;
end_enum

begin_comment
comment|/// NumDiagArgs - This contains the number of entries in Arguments.
end_comment

begin_decl_stmt
name|signed
name|char
name|NumDiagArgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// NumRanges - This is the number of ranges in the DiagRanges array.
end_comment

begin_decl_stmt
name|unsigned
name|char
name|NumDiagRanges
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of code modifications hints in the
end_comment

begin_comment
comment|/// FixItHints array.
end_comment

begin_decl_stmt
name|unsigned
name|char
name|NumFixItHints
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DiagArgumentsKind - This is an array of ArgumentKind::ArgumentKind enum
end_comment

begin_comment
comment|/// values, with one for each argument.  This specifies whether the argument
end_comment

begin_comment
comment|/// is in DiagArgumentsStr or in DiagArguments.
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
comment|/// DiagArgumentsStr - This holds the values of each string argument for the
end_comment

begin_comment
comment|/// current diagnostic.  This value is only used when the corresponding
end_comment

begin_comment
comment|/// ArgumentKind is ak_std_string.
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
comment|/// DiagArgumentsVal - The values for the various substitution positions. This
end_comment

begin_comment
comment|/// is used when the argument is not an std::string.  The specific value is
end_comment

begin_comment
comment|/// mangled into an intptr_t and the intepretation depends on exactly what
end_comment

begin_comment
comment|/// sort of argument kind it is.
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
comment|/// DiagRanges - The list of ranges added to this diagnostic.  It currently
end_comment

begin_comment
comment|/// only support 10 ranges, could easily be extended if needed.
end_comment

begin_decl_stmt
name|CharSourceRange
name|DiagRanges
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
block|{
name|MaxFixItHints
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/// FixItHints - If valid, provides a hint with some code
end_comment

begin_comment
comment|/// to insert, remove, or modify at a particular position.
end_comment

begin_decl_stmt
name|FixItHint
name|FixItHints
index|[
name|MaxFixItHints
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ProcessDiag - This is the method used to report a diagnostic that is
end_comment

begin_comment
comment|/// finally fully formed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if the diagnostic was emitted, false if it was
end_comment

begin_comment
comment|/// suppressed.
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
name|Diagnostic
modifier|&
name|Diag
decl_stmt|;
name|unsigned
name|PrevErrors
decl_stmt|;
name|public
label|:
name|explicit
name|DiagnosticErrorTrap
argument_list|(
name|Diagnostic
operator|&
name|Diag
argument_list|)
operator|:
name|Diag
argument_list|(
name|Diag
argument_list|)
operator|,
name|PrevErrors
argument_list|(
argument|Diag.NumErrors
argument_list|)
block|{}
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
name|NumErrors
operator|>
name|PrevErrors
return|;
block|}
comment|// Set to initial state of "no errors occurred".
name|void
name|reset
parameter_list|()
block|{
name|PrevErrors
operator|=
name|Diag
operator|.
name|NumErrors
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
comment|/// DiagnosticBuilder - This is a little helper class used to produce
end_comment

begin_comment
comment|/// diagnostics.  This is constructed by the Diagnostic::Report method, and
end_comment

begin_comment
comment|/// allows insertion of extra information (arguments and source ranges) into the
end_comment

begin_comment
comment|/// currently "in flight" diagnostic.  When the temporary for the builder is
end_comment

begin_comment
comment|/// destroyed, the diagnostic is issued.
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
name|Diagnostic
modifier|*
name|DiagObj
decl_stmt|;
name|mutable
name|unsigned
name|NumArgs
decl_stmt|,
name|NumRanges
decl_stmt|,
name|NumFixItHints
decl_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|friend
name|class
name|Diagnostic
decl_stmt|;
name|explicit
name|DiagnosticBuilder
argument_list|(
name|Diagnostic
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
name|NumFixItHints
argument_list|(
literal|0
argument_list|)
block|{}
name|friend
name|class
name|PartialDiagnostic
expr_stmt|;
name|protected
label|:
name|void
name|FlushCounts
parameter_list|()
function_decl|;
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
name|D
operator|.
name|DiagObj
operator|=
literal|0
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
name|NumFixItHints
operator|=
name|D
operator|.
name|NumFixItHints
expr_stmt|;
block|}
comment|/// \brief Simple enumeration value used to give a name to the
comment|/// suppress-diagnostic constructor.
enum|enum
name|SuppressKind
block|{
name|Suppress
block|}
enum|;
comment|/// \brief Create an empty DiagnosticBuilder object that represents
comment|/// no actual diagnostic.
name|explicit
name|DiagnosticBuilder
argument_list|(
name|SuppressKind
argument_list|)
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
name|NumFixItHints
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Force the diagnostic builder to emit the diagnostic now.
comment|///
comment|/// Once this function has been called, the DiagnosticBuilder object
comment|/// should not be used again before it is destroyed.
comment|///
comment|/// \returns true if a diagnostic was emitted, false if the
comment|/// diagnostic was suppressed.
name|bool
name|Emit
argument_list|()
expr_stmt|;
comment|/// Destructor - The dtor emits the diagnostic if it hasn't already
comment|/// been emitted.
operator|~
name|DiagnosticBuilder
argument_list|()
block|{
name|Emit
argument_list|()
block|; }
comment|/// isActive - Determine whether this diagnostic is still active.
name|bool
name|isActive
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|!=
literal|0
return|;
block|}
comment|/// \brief Retrieve the active diagnostic ID.
comment|///
comment|/// \pre \c isActive()
name|unsigned
name|getDiagID
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isActive
argument_list|()
operator|&&
literal|"Diagnostic is inactive"
argument_list|)
block|;
return|return
name|DiagObj
operator|->
name|CurDiagID
return|;
block|}
comment|/// \brief Clear out the current diagnostic.
name|void
name|Clear
parameter_list|()
block|{
name|DiagObj
operator|=
literal|0
expr_stmt|;
block|}
comment|/// Operator bool: conversion of DiagnosticBuilder to bool always returns
comment|/// true.  This allows is to be used in boolean error contexts like:
comment|/// return Diag(...);
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
name|llvm
operator|::
name|StringRef
name|S
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|NumArgs
operator|<
name|Diagnostic
operator|::
name|MaxArguments
operator|&&
literal|"Too many arguments to diagnostic!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|DiagObj
condition|)
block|{
name|DiagObj
operator|->
name|DiagArgumentsKind
index|[
name|NumArgs
index|]
operator|=
name|Diagnostic
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
block|}
name|void
name|AddTaggedVal
argument_list|(
name|intptr_t
name|V
argument_list|,
name|Diagnostic
operator|::
name|ArgumentKind
name|Kind
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|NumArgs
operator|<
name|Diagnostic
operator|::
name|MaxArguments
operator|&&
literal|"Too many arguments to diagnostic!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|DiagObj
condition|)
block|{
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
name|NumRanges
operator|<
sizeof|sizeof
argument_list|(
name|DiagObj
operator|->
name|DiagRanges
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|DiagObj
operator|->
name|DiagRanges
index|[
literal|0
index|]
argument_list|)
operator|&&
literal|"Too many arguments to diagnostic!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|DiagObj
condition|)
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
if|if
condition|(
name|Hint
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|assert
argument_list|(
name|NumFixItHints
operator|<
name|Diagnostic
operator|::
name|MaxFixItHints
operator|&&
literal|"Too many fix-it hints!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|DiagObj
condition|)
name|DiagObj
operator|->
name|FixItHints
index|[
name|NumFixItHints
operator|++
index|]
operator|=
name|Hint
expr_stmt|;
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
name|llvm
operator|::
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
name|Diagnostic
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
name|Diagnostic
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
name|Diagnostic
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
name|Diagnostic
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
name|Diagnostic
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
name|Diagnostic
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

begin_comment
comment|/// Report - Issue the message to the client.  DiagID is a member of the
end_comment

begin_comment
comment|/// diag::kind enum.  This actually returns a new instance of DiagnosticBuilder
end_comment

begin_comment
comment|/// which emits the diagnostics (through ProcessDiag) when it is destroyed.
end_comment

begin_expr_stmt
specifier|inline
name|DiagnosticBuilder
name|Diagnostic
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
name|Diagnostic
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
comment|// DiagnosticInfo
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// DiagnosticInfo - This is a little helper class (which is basically a smart
end_comment

begin_comment
comment|/// pointer that forward info from Diagnostic) that allows clients to enquire
end_comment

begin_comment
comment|/// about the currently in-flight diagnostic.
end_comment

begin_decl_stmt
name|class
name|DiagnosticInfo
block|{
specifier|const
name|Diagnostic
modifier|*
name|DiagObj
decl_stmt|;
name|public
label|:
name|explicit
name|DiagnosticInfo
argument_list|(
specifier|const
name|Diagnostic
operator|*
name|DO
argument_list|)
operator|:
name|DiagObj
argument_list|(
argument|DO
argument_list|)
block|{}
specifier|const
name|Diagnostic
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
comment|/// getArgKind - Return the kind of the specified index.  Based on the kind
comment|/// of argument, the accessors below can be used to get the value.
name|Diagnostic
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
name|Diagnostic
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
comment|/// getArgStdStr - Return the provided argument string specified by Idx.
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
name|Diagnostic
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
comment|/// getArgCStr - Return the specified C string argument.
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
name|Diagnostic
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
comment|/// getArgSInt - Return the specified signed integer argument.
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
name|Diagnostic
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
comment|/// getArgUInt - Return the specified unsigned integer argument.
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
name|Diagnostic
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
comment|/// getArgIdentifier - Return the specified IdentifierInfo argument.
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
name|Diagnostic
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
comment|/// getRawArg - Return the specified non-string argument in an opaque form.
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
name|Diagnostic
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
comment|/// getNumRanges - Return the number of source ranges associated with this
comment|/// diagnostic.
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
name|unsigned
name|getNumFixItHints
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|NumFixItHints
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
return|return
name|DiagObj
operator|->
name|FixItHints
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
name|DiagObj
operator|->
name|NumFixItHints
operator|?
operator|&
name|DiagObj
operator|->
name|FixItHints
index|[
literal|0
index|]
operator|:
literal|0
return|;
block|}
comment|/// FormatDiagnostic - Format this diagnostic into a string, substituting the
comment|/// formal arguments into the %0 slots.  The result is appended onto the Str
comment|/// array.
name|void
name|FormatDiagnostic
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|OutStr
argument_list|)
decl|const
decl_stmt|;
comment|/// FormatDiagnostic - Format the given format-string into the
comment|/// output buffer using the arguments stored in this diagnostic.
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
name|llvm
operator|::
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
name|Diagnostic
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
argument|Diagnostic::Level Level
argument_list|,
argument|const DiagnosticInfo&Info
argument_list|)
empty_stmt|;
name|StoredDiagnostic
argument_list|(
argument|Diagnostic::Level Level
argument_list|,
argument|unsigned ID
argument_list|,
argument|llvm::StringRef Message
argument_list|)
empty_stmt|;
operator|~
name|StoredDiagnostic
argument_list|()
expr_stmt|;
comment|/// \brief Evaluates true when this object stores a diagnostic.
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
name|Diagnostic
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
name|llvm
operator|::
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// DiagnosticClient - This is an abstract interface implemented by clients of
end_comment

begin_comment
comment|/// the front-end, which formats and prints fully processed diagnostics.
end_comment

begin_decl_stmt
name|class
name|DiagnosticClient
block|{
name|protected
label|:
name|unsigned
name|NumWarnings
decl_stmt|;
comment|// Number of warnings reported
name|unsigned
name|NumErrors
decl_stmt|;
comment|// Number of errors reported
name|public
label|:
name|DiagnosticClient
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
operator|~
name|DiagnosticClient
argument_list|()
expr_stmt|;
comment|/// BeginSourceFile - Callback to inform the diagnostic client that processing
comment|/// of a source file is beginning.
comment|///
comment|/// Note that diagnostics may be emitted outside the processing of a source
comment|/// file, for example during the parsing of command line options. However,
comment|/// diagnostics with source range information are required to only be emitted
comment|/// in between BeginSourceFile() and EndSourceFile().
comment|///
comment|/// \arg LO - The language options for the source file being processed.
comment|/// \arg PP - The preprocessor object being used for the source; this optional
comment|/// and may not be present, for example when processing AST source files.
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
comment|/// EndSourceFile - Callback to inform the diagnostic client that processing
comment|/// of a source file has ended. The diagnostic client should assume that any
comment|/// objects made available via \see BeginSourceFile() are inaccessible.
name|virtual
name|void
name|EndSourceFile
parameter_list|()
block|{}
comment|/// IncludeInDiagnosticCounts - This method (whose default implementation
comment|/// returns true) indicates whether the diagnostics handled by this
comment|/// DiagnosticClient should be included in the number of diagnostics reported
comment|/// by Diagnostic.
name|virtual
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
expr_stmt|;
comment|/// HandleDiagnostic - Handle this diagnostic, reporting it to the user or
comment|/// capturing it to a log as needed.
comment|///
comment|/// Default implementation just keeps track of the total number of warnings
comment|/// and errors.
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
name|Diagnostic
operator|::
name|Level
name|DiagLevel
argument_list|,
specifier|const
name|DiagnosticInfo
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
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

