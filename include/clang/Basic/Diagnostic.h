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
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
block|}
end_decl_stmt

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
name|DiagnosticClient
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|PartialDiagnostic
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|SourceRange
decl_stmt|;
comment|// Import the diagnostic enums themselves.
name|namespace
name|diag
block|{
comment|// Start position for diagnostics.
enum|enum
block|{
name|DIAG_START_DRIVER
init|=
literal|300
block|,
name|DIAG_START_FRONTEND
init|=
name|DIAG_START_DRIVER
operator|+
literal|100
block|,
name|DIAG_START_LEX
init|=
name|DIAG_START_FRONTEND
operator|+
literal|100
block|,
name|DIAG_START_PARSE
init|=
name|DIAG_START_LEX
operator|+
literal|300
block|,
name|DIAG_START_AST
init|=
name|DIAG_START_PARSE
operator|+
literal|300
block|,
name|DIAG_START_SEMA
init|=
name|DIAG_START_AST
operator|+
literal|100
block|,
name|DIAG_START_ANALYSIS
init|=
name|DIAG_START_SEMA
operator|+
literal|1100
block|,
name|DIAG_UPPER_LIMIT
init|=
name|DIAG_START_ANALYSIS
operator|+
literal|100
block|}
enum|;
name|class
name|CustomDiagInfo
decl_stmt|;
comment|/// diag::kind - All of the diagnostics that can be emitted by the frontend.
typedef|typedef
name|unsigned
name|kind
typedef|;
comment|// Get typedefs for common diagnostics.
enum|enum
block|{
define|#
directive|define
name|DIAG
parameter_list|(
name|ENUM
parameter_list|,
name|FLAGS
parameter_list|,
name|DEFAULT_MAPPING
parameter_list|,
name|DESC
parameter_list|,
name|GROUP
parameter_list|,
name|SFINAE
parameter_list|)
value|ENUM,
include|#
directive|include
file|"clang/Basic/DiagnosticCommonKinds.inc"
name|NUM_BUILTIN_COMMON_DIAGNOSTICS
undef|#
directive|undef
name|DIAG
block|}
enum|;
comment|/// Enum values that allow the client to map NOTEs, WARNINGs, and EXTENSIONs
comment|/// to either MAP_IGNORE (nothing), MAP_WARNING (emit a warning), MAP_ERROR
comment|/// (emit as an error).  It allows clients to map errors to
comment|/// MAP_ERROR/MAP_DEFAULT or MAP_FATAL (stop emitting diagnostics after this
comment|/// one).
enum|enum
name|Mapping
block|{
comment|// NOTE: 0 means "uncomputed".
name|MAP_IGNORE
init|=
literal|1
block|,
comment|//< Map this diagnostic to nothing, ignore it.
name|MAP_WARNING
init|=
literal|2
block|,
comment|//< Map this diagnostic to a warning.
name|MAP_ERROR
init|=
literal|3
block|,
comment|//< Map this diagnostic to an error.
name|MAP_FATAL
init|=
literal|4
block|,
comment|//< Map this diagnostic to a fatal error.
comment|/// Map this diagnostic to "warning", but make it immune to -Werror.  This
comment|/// happens when you specify -Wno-error=foo.
name|MAP_WARNING_NO_WERROR
init|=
literal|5
block|}
enum|;
block|}
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
name|CodeModificationHint
block|{
name|public
label|:
comment|/// \brief Tokens that should be removed to correct the error.
name|SourceRange
name|RemoveRange
decl_stmt|;
comment|/// \brief The location at which we should insert code to correct
comment|/// the error.
name|SourceLocation
name|InsertionLoc
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
name|CodeModificationHint
argument_list|()
operator|:
name|RemoveRange
argument_list|()
operator|,
name|InsertionLoc
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
operator|&&
operator|!
name|InsertionLoc
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Create a code modification hint that inserts the given
comment|/// code string at a specific location.
specifier|static
name|CodeModificationHint
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
name|CodeModificationHint
name|Hint
decl_stmt|;
name|Hint
operator|.
name|InsertionLoc
operator|=
name|InsertionLoc
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
name|CodeModificationHint
name|CreateRemoval
parameter_list|(
name|SourceRange
name|RemoveRange
parameter_list|)
block|{
name|CodeModificationHint
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
comment|/// \brief Create a code modification hint that replaces the given
comment|/// source range with the given code string.
specifier|static
name|CodeModificationHint
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
name|CodeModificationHint
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
name|InsertionLoc
operator|=
name|RemoveRange
operator|.
name|getBegin
argument_list|()
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
block|}
empty_stmt|;
comment|/// Diagnostic - This concrete class is used by the front-end to report
comment|/// problems and issues.  It massages the diagnostics (e.g. handling things like
comment|/// "report warnings as errors" and passes them off to the DiagnosticClient for
comment|/// reporting to the user.
name|class
name|Diagnostic
block|{
name|public
label|:
comment|/// Level - The level of the diagnostic, after it has been through mapping.
enum|enum
name|Level
block|{
name|Ignored
block|,
name|Note
block|,
name|Warning
block|,
name|Error
block|,
name|Fatal
block|}
enum|;
comment|/// ExtensionHandling - How do we handle otherwise-unmapped extension?  This
comment|/// is controlled by -pedantic and -pedantic-errors.
enum|enum
name|ExtensionHandling
block|{
name|Ext_Ignore
block|,
name|Ext_Warn
block|,
name|Ext_Error
block|}
enum|;
enum|enum
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
enum|;
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
label|:
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
name|SuppressSystemWarnings
decl_stmt|;
comment|// Suppress warnings in system headers.
name|bool
name|SuppressAllDiagnostics
decl_stmt|;
comment|// Suppress all diagnostics.
name|ExtensionHandling
name|ExtBehavior
decl_stmt|;
comment|// Map extensions onto warnings or errors?
name|DiagnosticClient
modifier|*
name|Client
decl_stmt|;
comment|/// DiagMappings - Mapping information for diagnostics.  Mapping info is
comment|/// packed into four bits per diagnostic.  The low three bits are the mapping
comment|/// (an instance of diag::Mapping), or zero if unset.  The high bit is set
comment|/// when the mapping was established as a user mapping.  If the high bit is
comment|/// clear, then the low bits are set to the default value, and should be
comment|/// mapped with -pedantic, -Werror, etc.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|DiagMappings
expr_stmt|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|DiagMappings
operator|>
name|DiagMappingsStack
expr_stmt|;
comment|/// ErrorOccurred / FatalErrorOccurred - This is set to true when an error or
comment|/// fatal error is emitted, and is sticky.
name|bool
name|ErrorOccurred
decl_stmt|;
name|bool
name|FatalErrorOccurred
decl_stmt|;
comment|/// LastDiagLevel - This is the level of the last diagnostic emitted.  This is
comment|/// used to emit continuation diagnostics with the same level as the
comment|/// diagnostic that they follow.
name|Diagnostic
operator|::
name|Level
name|LastDiagLevel
expr_stmt|;
name|unsigned
name|NumDiagnostics
decl_stmt|;
comment|// Number of diagnostics reported
name|unsigned
name|NumErrors
decl_stmt|;
comment|// Number of diagnostics that are errors
comment|/// CustomDiagInfo - Information for uniquing and looking up custom diags.
name|diag
operator|::
name|CustomDiagInfo
operator|*
name|CustomDiagInfo
expr_stmt|;
comment|/// ArgToStringFn - A function pointer that converts an opaque diagnostic
comment|/// argument to a strings.  This takes the modifiers and argument that was
comment|/// present in the diagnostic.
comment|///
comment|/// The PrevArgs array (whose length is NumPrevArgs) indicates the previous
comment|/// arguments formatted for this diagnostic.  Implementations of this function
comment|/// can use this information to avoid redundancy across arguments.
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
name|void
modifier|*
name|ArgToStringCookie
decl_stmt|;
name|ArgToStringFnTy
name|ArgToStringFn
decl_stmt|;
name|public
label|:
name|explicit
name|Diagnostic
parameter_list|(
name|DiagnosticClient
modifier|*
name|client
init|=
literal|0
parameter_list|)
function_decl|;
operator|~
name|Diagnostic
argument_list|()
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//  Diagnostic characterization methods, used by a client to customize how
comment|//
name|DiagnosticClient
modifier|*
name|getClient
parameter_list|()
block|{
return|return
name|Client
return|;
block|}
empty_stmt|;
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
empty_stmt|;
comment|/// pushMappings - Copies the current DiagMappings and pushes the new copy
comment|/// onto the top of the stack.
name|void
name|pushMappings
parameter_list|()
function_decl|;
comment|/// popMappings - Pops the current DiagMappings off the top of the stack
comment|/// causing the new top of the stack to be the active mappings. Returns
comment|/// true if the pop happens, false if there is only one DiagMapping on the
comment|/// stack.
name|bool
name|popMappings
parameter_list|()
function_decl|;
name|void
name|setClient
parameter_list|(
name|DiagnosticClient
modifier|*
name|client
parameter_list|)
block|{
name|Client
operator|=
name|client
expr_stmt|;
block|}
comment|/// setIgnoreAllWarnings - When set to true, any unmapped warnings are
comment|/// ignored.  If this and WarningsAsErrors are both set, then this one wins.
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
name|bool
name|getIgnoreAllWarnings
argument_list|()
specifier|const
block|{
return|return
name|IgnoreAllWarnings
return|;
block|}
comment|/// setWarningsAsErrors - When set to true, any warnings reported are issued
comment|/// as errors.
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
name|bool
name|getWarningsAsErrors
argument_list|()
specifier|const
block|{
return|return
name|WarningsAsErrors
return|;
block|}
comment|/// setSuppressSystemWarnings - When set to true mask warnings that
comment|/// come from system headers.
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
name|bool
name|getSuppressSystemWarnings
argument_list|()
specifier|const
block|{
return|return
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
comment|/// \brief Pretend that the last diagnostic issued was ignored. This can
comment|/// be used by clients who suppress diagnostics themselves.
name|void
name|setLastDiagnosticIgnored
parameter_list|()
block|{
name|LastDiagLevel
operator|=
name|Ignored
expr_stmt|;
block|}
comment|/// setExtensionHandlingBehavior - This controls whether otherwise-unmapped
comment|/// extension diagnostics are mapped onto ignore/warning/error.  This
comment|/// corresponds to the GCC -pedantic and -pedantic-errors option.
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
comment|/// AllExtensionsSilenced - This is a counter bumped when an __extension__
comment|/// block is encountered.  When non-zero, all extension diagnostics are
comment|/// entirely silenced, no matter how they are mapped.
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
comment|/// setDiagnosticMapping - This allows the client to specify that certain
comment|/// warnings are ignored.  Notes can never be mapped, errors can only be
comment|/// mapped to fatal, and WARNINGs and EXTENSIONs can be mapped arbitrarily.
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
argument_list|)
block|{
name|assert
argument_list|(
name|Diag
operator|<
name|diag
operator|::
name|DIAG_UPPER_LIMIT
operator|&&
literal|"Can only map builtin diagnostics"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|isBuiltinWarningOrExtension
argument_list|(
name|Diag
argument_list|)
operator|||
name|Map
operator|==
name|diag
operator|::
name|MAP_FATAL
operator|)
operator|&&
literal|"Cannot map errors!"
argument_list|)
expr_stmt|;
name|setDiagnosticMappingInternal
argument_list|(
name|Diag
argument_list|,
name|Map
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
comment|/// setDiagnosticGroupMapping - Change an entire diagnostic group (e.g.
comment|/// "unknown-pragmas" to have the specified mapping.  This returns true and
comment|/// ignores the request if "Group" was unknown, false otherwise.
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
name|bool
name|hasFatalErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|FatalErrorOccurred
return|;
block|}
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
name|getNumDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|NumDiagnostics
return|;
block|}
comment|/// getCustomDiagID - Return an ID for a diagnostic with the specified message
comment|/// and level.  If this is the first request for this diagnosic, it is
comment|/// registered and created, otherwise the existing ID is returned.
name|unsigned
name|getCustomDiagID
parameter_list|(
name|Level
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|Message
parameter_list|)
function_decl|;
comment|/// ConvertArgToString - This method converts a diagnostic argument (as an
comment|/// intptr_t) into the string that represents it.
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
comment|//===--------------------------------------------------------------------===//
comment|// Diagnostic classification and reporting interfaces.
comment|//
comment|/// getDescription - Given a diagnostic ID, return a description of the
comment|/// issue.
specifier|const
name|char
modifier|*
name|getDescription
argument_list|(
name|unsigned
name|DiagID
argument_list|)
decl|const
decl_stmt|;
comment|/// isNoteWarningOrExtension - Return true if the unmapped diagnostic
comment|/// level of the specified diagnostic ID is a Warning or Extension.
comment|/// This only works on builtin diagnostics, not custom ones, and is not legal to
comment|/// call on NOTEs.
specifier|static
name|bool
name|isBuiltinWarningOrExtension
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// \brief Determine whether the given built-in diagnostic ID is a
comment|/// Note.
specifier|static
name|bool
name|isBuiltinNote
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// isBuiltinExtensionDiag - Determine whether the given built-in diagnostic
comment|/// ID is for an extension of some sort.
comment|///
specifier|static
name|bool
name|isBuiltinExtensionDiag
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// getWarningOptionForDiag - Return the lowest-level warning option that
comment|/// enables the specified diagnostic.  If there is no -Wfoo flag that controls
comment|/// the diagnostic, this returns null.
specifier|static
specifier|const
name|char
modifier|*
name|getWarningOptionForDiag
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// \brief Determines whether the given built-in diagnostic ID is
comment|/// for an error that is suppressed if it occurs during C++ template
comment|/// argument deduction.
comment|///
comment|/// When an error is suppressed due to SFINAE, the template argument
comment|/// deduction fails but no diagnostic is emitted. Certain classes of
comment|/// errors, such as those errors that involve C++ access control,
comment|/// are not SFINAE errors.
specifier|static
name|bool
name|isBuiltinSFINAEDiag
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// getDiagnosticLevel - Based on the way the client configured the Diagnostic
comment|/// object, classify the specified diagnostic ID into a Level, consumable by
comment|/// the DiagnosticClient.
name|Level
name|getDiagnosticLevel
argument_list|(
name|unsigned
name|DiagID
argument_list|)
decl|const
decl_stmt|;
comment|/// Report - Issue the message to the client.  @c DiagID is a member of the
comment|/// @c diag::kind enum.  This actually returns aninstance of DiagnosticBuilder
comment|/// which emits the diagnostics (through @c ProcessDiag) when it is destroyed.
comment|/// @c Pos represents the source location associated with the diagnostic,
comment|/// which can be an invalid location if no position information is available.
specifier|inline
name|DiagnosticBuilder
name|Report
parameter_list|(
name|FullSourceLoc
name|Pos
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
name|private
label|:
comment|/// getDiagnosticMappingInfo - Return the mapping info currently set for the
comment|/// specified builtin diagnostic.  This returns the high bit encoding, or zero
comment|/// if the field is completely uninitialized.
name|unsigned
name|getDiagnosticMappingInfo
argument_list|(
name|diag
operator|::
name|kind
name|Diag
argument_list|)
decl|const
block|{
specifier|const
name|DiagMappings
modifier|&
name|currentMappings
init|=
name|DiagMappingsStack
operator|.
name|back
argument_list|()
decl_stmt|;
return|return
operator|(
name|diag
operator|::
name|Mapping
operator|)
operator|(
operator|(
name|currentMappings
index|[
name|Diag
operator|/
literal|2
index|]
operator|>>
operator|(
name|Diag
operator|&
literal|1
operator|)
operator|*
literal|4
operator|)
operator|&
literal|15
operator|)
return|;
block|}
name|void
name|setDiagnosticMappingInternal
argument_list|(
name|unsigned
name|DiagId
argument_list|,
name|unsigned
name|Map
argument_list|,
name|bool
name|isUser
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
name|unsigned
name|char
modifier|&
name|Slot
init|=
name|DiagMappingsStack
operator|.
name|back
argument_list|()
index|[
name|DiagId
operator|/
literal|2
index|]
decl_stmt|;
name|unsigned
name|Shift
init|=
operator|(
name|DiagId
operator|&
literal|1
operator|)
operator|*
literal|4
decl_stmt|;
name|Slot
operator|&=
operator|~
operator|(
literal|15
operator|<<
name|Shift
operator|)
expr_stmt|;
name|Slot
operator||=
name|Map
operator|<<
name|Shift
expr_stmt|;
block|}
comment|/// getDiagnosticLevel - This is an internal implementation helper used when
comment|/// DiagClass is already known.
name|Level
name|getDiagnosticLevel
argument_list|(
name|unsigned
name|DiagID
argument_list|,
name|unsigned
name|DiagClass
argument_list|)
decl|const
decl_stmt|;
comment|// This is private state used by DiagnosticBuilder.  We put it here instead of
comment|// in DiagnosticBuilder in order to keep DiagnosticBuilder a small lightweight
comment|// object.  This implementation choice means that we can only have one
comment|// diagnostic "in flight" at a time, but this seems to be a reasonable
comment|// tradeoff to keep these objects small.  Assertions verify that only one
comment|// diagnostic is in flight at a time.
name|friend
name|class
name|DiagnosticBuilder
decl_stmt|;
name|friend
name|class
name|DiagnosticInfo
decl_stmt|;
comment|/// CurDiagLoc - This is the location of the current diagnostic that is in
comment|/// flight.
name|FullSourceLoc
name|CurDiagLoc
decl_stmt|;
comment|/// CurDiagID - This is the ID of the current diagnostic that is in flight.
comment|/// This is set to ~0U when there is no diagnostic in flight.
name|unsigned
name|CurDiagID
decl_stmt|;
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
comment|/// NumDiagArgs - This contains the number of entries in Arguments.
name|signed
name|char
name|NumDiagArgs
decl_stmt|;
comment|/// NumRanges - This is the number of ranges in the DiagRanges array.
name|unsigned
name|char
name|NumDiagRanges
decl_stmt|;
comment|/// \brief The number of code modifications hints in the
comment|/// CodeModificationHints array.
name|unsigned
name|char
name|NumCodeModificationHints
decl_stmt|;
comment|/// DiagArgumentsKind - This is an array of ArgumentKind::ArgumentKind enum
comment|/// values, with one for each argument.  This specifies whether the argument
comment|/// is in DiagArgumentsStr or in DiagArguments.
name|unsigned
name|char
name|DiagArgumentsKind
index|[
name|MaxArguments
index|]
decl_stmt|;
comment|/// DiagArgumentsStr - This holds the values of each string argument for the
comment|/// current diagnostic.  This value is only used when the corresponding
comment|/// ArgumentKind is ak_std_string.
name|std
operator|::
name|string
name|DiagArgumentsStr
index|[
name|MaxArguments
index|]
expr_stmt|;
comment|/// DiagArgumentsVal - The values for the various substitution positions. This
comment|/// is used when the argument is not an std::string.  The specific value is
comment|/// mangled into an intptr_t and the intepretation depends on exactly what
comment|/// sort of argument kind it is.
name|intptr_t
name|DiagArgumentsVal
index|[
name|MaxArguments
index|]
decl_stmt|;
comment|/// DiagRanges - The list of ranges added to this diagnostic.  It currently
comment|/// only support 10 ranges, could easily be extended if needed.
specifier|const
name|SourceRange
modifier|*
name|DiagRanges
index|[
literal|10
index|]
decl_stmt|;
enum|enum
block|{
name|MaxCodeModificationHints
init|=
literal|3
block|}
enum|;
comment|/// CodeModificationHints - If valid, provides a hint with some code
comment|/// to insert, remove, or modify at a particular position.
name|CodeModificationHint
name|CodeModificationHints
index|[
name|MaxCodeModificationHints
index|]
decl_stmt|;
comment|/// ProcessDiag - This is the method used to report a diagnostic that is
comment|/// finally fully formed.
comment|///
comment|/// \returns true if the diagnostic was emitted, false if it was
comment|/// suppressed.
name|bool
name|ProcessDiag
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// DiagnosticBuilder
comment|//===----------------------------------------------------------------------===//
comment|/// DiagnosticBuilder - This is a little helper class used to produce
comment|/// diagnostics.  This is constructed by the Diagnostic::Report method, and
comment|/// allows insertion of extra information (arguments and source ranges) into the
comment|/// currently "in flight" diagnostic.  When the temporary for the builder is
comment|/// destroyed, the diagnostic is issued.
comment|///
comment|/// Note that many of these will be created as temporary objects (many call
comment|/// sites), so we want them to be small and we never want their address taken.
comment|/// This ensures that compilers with somewhat reasonable optimizers will promote
comment|/// the common fields to registers, eliminating increments of the NumArgs field,
comment|/// for example.
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
name|NumCodeModificationHints
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
name|NumCodeModificationHints
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
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
block|;
name|D
operator|.
name|DiagObj
operator|=
literal|0
block|;
name|NumArgs
operator|=
name|D
operator|.
name|NumArgs
block|;
name|NumRanges
operator|=
name|D
operator|.
name|NumRanges
block|;
name|NumCodeModificationHints
operator|=
name|D
operator|.
name|NumCodeModificationHints
block|;   }
comment|/// \brief Simple enumeration value used to give a name to the
comment|/// suppress-diagnostic constructor.
expr|enum
name|SuppressKind
block|{
name|Suppress
block|}
expr_stmt|;
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
name|NumCodeModificationHints
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
block|{
comment|// If DiagObj is null, then its soul was stolen by the copy ctor
comment|// or the user called Emit().
if|if
condition|(
name|DiagObj
operator|==
literal|0
condition|)
return|return
name|false
return|;
comment|// When emitting diagnostics, we set the final argument count into
comment|// the Diagnostic object.
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
name|NumCodeModificationHints
operator|=
name|NumCodeModificationHints
expr_stmt|;
comment|// Process the diagnostic, sending the accumulated information to the
comment|// DiagnosticClient.
name|bool
name|Emitted
init|=
name|DiagObj
operator|->
name|ProcessDiag
argument_list|()
decl_stmt|;
comment|// Clear out the current diagnostic object.
name|DiagObj
operator|->
name|Clear
argument_list|()
expr_stmt|;
comment|// This diagnostic is dead.
name|DiagObj
operator|=
literal|0
expr_stmt|;
return|return
name|Emitted
return|;
block|}
comment|/// Destructor - The dtor emits the diagnostic if it hasn't already
comment|/// been emitted.
operator|~
name|DiagnosticBuilder
argument_list|()
block|{
name|Emit
argument_list|()
block|; }
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
name|SourceRange
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
operator|&
name|R
expr_stmt|;
block|}
name|void
name|AddCodeModificationHint
argument_list|(
specifier|const
name|CodeModificationHint
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
name|NumCodeModificationHints
operator|<
name|Diagnostic
operator|::
name|MaxCodeModificationHints
operator|&&
literal|"Too many code modification hints!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|DiagObj
condition|)
name|DiagObj
operator|->
name|CodeModificationHints
index|[
name|NumCodeModificationHints
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
name|CodeModificationHint
operator|&
name|Hint
operator|)
block|{
name|DB
operator|.
name|AddCodeModificationHint
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
argument|FullSourceLoc Loc
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
name|FullSourceLoc
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
name|FullSourceLoc
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
name|SourceRange
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
operator|*
name|DiagObj
operator|->
name|DiagRanges
index|[
name|Idx
index|]
return|;
block|}
name|unsigned
name|getNumCodeModificationHints
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|NumCodeModificationHints
return|;
block|}
specifier|const
name|CodeModificationHint
modifier|&
name|getCodeModificationHint
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
return|return
name|DiagObj
operator|->
name|CodeModificationHints
index|[
name|Idx
index|]
return|;
block|}
specifier|const
name|CodeModificationHint
operator|*
name|getCodeModificationHints
argument_list|()
specifier|const
block|{
return|return
name|DiagObj
operator|->
name|NumCodeModificationHints
operator|?
operator|&
name|DiagObj
operator|->
name|CodeModificationHints
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
name|public
label|:
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
init|=
literal|0
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

