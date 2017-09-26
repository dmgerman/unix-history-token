begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DiagnosticIDs.h - Diagnostic IDs Handling --------------*- C++ -*-===//
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
comment|/// \brief Defines the Diagnostic IDs-related interfaces.
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
name|LLVM_CLANG_BASIC_DIAGNOSTICIDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_DIAGNOSTICIDS_H
end_define

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
file|"llvm/ADT/StringRef.h"
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
name|DiagnosticsEngine
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
comment|// Import the diagnostic enums themselves.
name|namespace
name|diag
block|{
comment|// Start position for diagnostics.
enum|enum
block|{
name|DIAG_START_COMMON
init|=
literal|0
block|,
name|DIAG_START_DRIVER
init|=
name|DIAG_START_COMMON
operator|+
literal|300
block|,
name|DIAG_START_FRONTEND
init|=
name|DIAG_START_DRIVER
operator|+
literal|200
block|,
name|DIAG_START_SERIALIZATION
init|=
name|DIAG_START_FRONTEND
operator|+
literal|100
block|,
name|DIAG_START_LEX
init|=
name|DIAG_START_SERIALIZATION
operator|+
literal|120
block|,
name|DIAG_START_PARSE
init|=
name|DIAG_START_LEX
operator|+
literal|400
block|,
name|DIAG_START_AST
init|=
name|DIAG_START_PARSE
operator|+
literal|500
block|,
name|DIAG_START_COMMENT
init|=
name|DIAG_START_AST
operator|+
literal|110
block|,
name|DIAG_START_SEMA
init|=
name|DIAG_START_COMMENT
operator|+
literal|100
block|,
name|DIAG_START_ANALYSIS
init|=
name|DIAG_START_SEMA
operator|+
literal|3500
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
comment|/// \brief All of the diagnostics that can be emitted by the frontend.
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
parameter_list|,\
name|SFINAE
parameter_list|,
name|CATEGORY
parameter_list|,
name|NOWERROR
parameter_list|,
name|SHOWINSYSHEADER
parameter_list|)
value|ENUM,
define|#
directive|define
name|COMMONSTART
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
comment|/// to either Ignore (nothing), Remark (emit a remark), Warning
comment|/// (emit a warning) or Error (emit as an error).  It allows clients to
comment|/// map ERRORs to Error or Fatal (stop emitting diagnostics after this one).
name|enum
name|class
name|Severity
block|{
comment|// NOTE: 0 means "uncomputed".
name|Ignored
operator|=
literal|1
operator|,
comment|///< Do not present this diagnostic, ignore it.
name|Remark
operator|=
literal|2
operator|,
comment|///< Present this diagnostic as a remark.
name|Warning
operator|=
literal|3
operator|,
comment|///< Present this diagnostic as a warning.
name|Error
operator|=
literal|4
operator|,
comment|///< Present this diagnostic as an error.
name|Fatal
operator|=
literal|5
comment|///< Present this diagnostic as a fatal error.
block|}
empty_stmt|;
comment|/// Flavors of diagnostics we can emit. Used to filter for a particular
comment|/// kind of diagnostic (for instance, for -W/-R flags).
name|enum
name|class
name|Flavor
block|{
name|WarningOrError
operator|,
comment|///< A diagnostic that indicates a problem or potential
comment|///< problem. Can be made fatal by -Werror.
name|Remark
comment|///< A diagnostic that indicates normal progress through
comment|///< compilation.
block|}
empty_stmt|;
block|}
name|class
name|DiagnosticMapping
block|{
name|unsigned
name|Severity
range|:
literal|3
decl_stmt|;
name|unsigned
name|IsUser
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsPragma
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasNoWarningAsError
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasNoErrorAsFatal
range|:
literal|1
decl_stmt|;
name|unsigned
name|WasUpgradedFromWarning
range|:
literal|1
decl_stmt|;
name|public
label|:
specifier|static
name|DiagnosticMapping
name|Make
argument_list|(
name|diag
operator|::
name|Severity
name|Severity
argument_list|,
name|bool
name|IsUser
argument_list|,
name|bool
name|IsPragma
argument_list|)
block|{
name|DiagnosticMapping
name|Result
decl_stmt|;
name|Result
operator|.
name|Severity
operator|=
operator|(
name|unsigned
operator|)
name|Severity
expr_stmt|;
name|Result
operator|.
name|IsUser
operator|=
name|IsUser
expr_stmt|;
name|Result
operator|.
name|IsPragma
operator|=
name|IsPragma
expr_stmt|;
name|Result
operator|.
name|HasNoWarningAsError
operator|=
literal|0
expr_stmt|;
name|Result
operator|.
name|HasNoErrorAsFatal
operator|=
literal|0
expr_stmt|;
name|Result
operator|.
name|WasUpgradedFromWarning
operator|=
literal|0
expr_stmt|;
return|return
name|Result
return|;
block|}
name|diag
operator|::
name|Severity
name|getSeverity
argument_list|()
specifier|const
block|{
return|return
operator|(
name|diag
operator|::
name|Severity
operator|)
name|Severity
return|;
block|}
name|void
name|setSeverity
argument_list|(
name|diag
operator|::
name|Severity
name|Value
argument_list|)
block|{
name|Severity
operator|=
operator|(
name|unsigned
operator|)
name|Value
expr_stmt|;
block|}
name|bool
name|isUser
argument_list|()
specifier|const
block|{
return|return
name|IsUser
return|;
block|}
name|bool
name|isPragma
argument_list|()
specifier|const
block|{
return|return
name|IsPragma
return|;
block|}
name|bool
name|isErrorOrFatal
argument_list|()
specifier|const
block|{
return|return
name|getSeverity
argument_list|()
operator|==
name|diag
operator|::
name|Severity
operator|::
name|Error
operator|||
name|getSeverity
argument_list|()
operator|==
name|diag
operator|::
name|Severity
operator|::
name|Fatal
return|;
block|}
name|bool
name|hasNoWarningAsError
argument_list|()
specifier|const
block|{
return|return
name|HasNoWarningAsError
return|;
block|}
name|void
name|setNoWarningAsError
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|HasNoWarningAsError
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|hasNoErrorAsFatal
argument_list|()
specifier|const
block|{
return|return
name|HasNoErrorAsFatal
return|;
block|}
name|void
name|setNoErrorAsFatal
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|HasNoErrorAsFatal
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Whether this mapping attempted to map the diagnostic to a warning, but
comment|/// was overruled because the diagnostic was already mapped to an error or
comment|/// fatal error.
name|bool
name|wasUpgradedFromWarning
argument_list|()
specifier|const
block|{
return|return
name|WasUpgradedFromWarning
return|;
block|}
name|void
name|setUpgradedFromWarning
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|WasUpgradedFromWarning
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Serialize this mapping as a raw integer.
name|unsigned
name|serialize
argument_list|()
specifier|const
block|{
return|return
operator|(
name|IsUser
operator|<<
literal|7
operator|)
operator||
operator|(
name|IsPragma
operator|<<
literal|6
operator|)
operator||
operator|(
name|HasNoWarningAsError
operator|<<
literal|5
operator|)
operator||
operator|(
name|HasNoErrorAsFatal
operator|<<
literal|4
operator|)
operator||
operator|(
name|WasUpgradedFromWarning
operator|<<
literal|3
operator|)
operator||
name|Severity
return|;
block|}
comment|/// Deserialize a mapping.
specifier|static
name|DiagnosticMapping
name|deserialize
parameter_list|(
name|unsigned
name|Bits
parameter_list|)
block|{
name|DiagnosticMapping
name|Result
decl_stmt|;
name|Result
operator|.
name|IsUser
operator|=
operator|(
name|Bits
operator|>>
literal|7
operator|)
operator|&
literal|1
expr_stmt|;
name|Result
operator|.
name|IsPragma
operator|=
operator|(
name|Bits
operator|>>
literal|6
operator|)
operator|&
literal|1
expr_stmt|;
name|Result
operator|.
name|HasNoWarningAsError
operator|=
operator|(
name|Bits
operator|>>
literal|5
operator|)
operator|&
literal|1
expr_stmt|;
name|Result
operator|.
name|HasNoErrorAsFatal
operator|=
operator|(
name|Bits
operator|>>
literal|4
operator|)
operator|&
literal|1
expr_stmt|;
name|Result
operator|.
name|WasUpgradedFromWarning
operator|=
operator|(
name|Bits
operator|>>
literal|3
operator|)
operator|&
literal|1
expr_stmt|;
name|Result
operator|.
name|Severity
operator|=
name|Bits
operator|&
literal|0x7
expr_stmt|;
return|return
name|Result
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Used for handling and querying diagnostic IDs.
comment|///
comment|/// Can be used and shared by multiple Diagnostics for multiple translation units.
name|class
name|DiagnosticIDs
range|:
name|public
name|RefCountedBase
operator|<
name|DiagnosticIDs
operator|>
block|{
name|public
operator|:
comment|/// \brief The level of the diagnostic, after it has been through mapping.
expr|enum
name|Level
block|{
name|Ignored
block|,
name|Note
block|,
name|Remark
block|,
name|Warning
block|,
name|Error
block|,
name|Fatal
block|}
block|;
name|private
operator|:
comment|/// \brief Information for uniquing and looking up custom diags.
name|diag
operator|::
name|CustomDiagInfo
operator|*
name|CustomDiagInfo
block|;
name|public
operator|:
name|DiagnosticIDs
argument_list|()
block|;
operator|~
name|DiagnosticIDs
argument_list|()
block|;
comment|/// \brief Return an ID for a diagnostic with the specified format string and
comment|/// level.
comment|///
comment|/// If this is the first request for this diagnostic, it is registered and
comment|/// created, otherwise the existing ID is returned.
comment|// FIXME: Replace this function with a create-only facilty like
comment|// createCustomDiagIDFromFormatString() to enforce safe usage. At the time of
comment|// writing, nearly all callers of this function were invalid.
name|unsigned
name|getCustomDiagID
argument_list|(
argument|Level L
argument_list|,
argument|StringRef FormatString
argument_list|)
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Diagnostic classification and reporting interfaces.
comment|//
comment|/// \brief Given a diagnostic ID, return a description of the issue.
name|StringRef
name|getDescription
argument_list|(
argument|unsigned DiagID
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if the unmapped diagnostic levelof the specified
comment|/// diagnostic ID is a Warning or Extension.
comment|///
comment|/// This only works on builtin diagnostics, not custom ones, and is not
comment|/// legal to call on NOTEs.
specifier|static
name|bool
name|isBuiltinWarningOrExtension
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// \brief Return true if the specified diagnostic is mapped to errors by
comment|/// default.
specifier|static
name|bool
name|isDefaultMappingAsError
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// \brief Determine whether the given built-in diagnostic ID is a Note.
specifier|static
name|bool
name|isBuiltinNote
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// \brief Determine whether the given built-in diagnostic ID is for an
comment|/// extension of some sort.
specifier|static
name|bool
name|isBuiltinExtensionDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|{
name|bool
name|ignored
block|;
return|return
name|isBuiltinExtensionDiag
argument_list|(
name|DiagID
argument_list|,
name|ignored
argument_list|)
return|;
block|}
comment|/// \brief Determine whether the given built-in diagnostic ID is for an
comment|/// extension of some sort, and whether it is enabled by default.
comment|///
comment|/// This also returns EnabledByDefault, which is set to indicate whether the
comment|/// diagnostic is ignored by default (in which case -pedantic enables it) or
comment|/// treated as a warning/error by default.
comment|///
specifier|static
name|bool
name|isBuiltinExtensionDiag
argument_list|(
argument|unsigned DiagID
argument_list|,
argument|bool&EnabledByDefault
argument_list|)
block|;
comment|/// \brief Return the lowest-level warning option that enables the specified
comment|/// diagnostic.
comment|///
comment|/// If there is no -Wfoo flag that controls the diagnostic, this returns null.
specifier|static
name|StringRef
name|getWarningOptionForDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// \brief Return the category number that a specified \p DiagID belongs to,
comment|/// or 0 if no category.
specifier|static
name|unsigned
name|getCategoryNumberForDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// \brief Return the number of diagnostic categories.
specifier|static
name|unsigned
name|getNumberOfCategories
argument_list|()
block|;
comment|/// \brief Given a category ID, return the name of the category.
specifier|static
name|StringRef
name|getCategoryNameFromID
argument_list|(
argument|unsigned CategoryID
argument_list|)
block|;
comment|/// \brief Return true if a given diagnostic falls into an ARC diagnostic
comment|/// category.
specifier|static
name|bool
name|isARCDiagnostic
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// \brief Enumeration describing how the emission of a diagnostic should
comment|/// be treated when it occurs during C++ template argument deduction.
block|enum
name|SFINAEResponse
block|{
comment|/// \brief The diagnostic should not be reported, but it should cause
comment|/// template argument deduction to fail.
comment|///
comment|/// The vast majority of errors that occur during template argument
comment|/// deduction fall into this category.
name|SFINAE_SubstitutionFailure
block|,
comment|/// \brief The diagnostic should be suppressed entirely.
comment|///
comment|/// Warnings generally fall into this category.
name|SFINAE_Suppress
block|,
comment|/// \brief The diagnostic should be reported.
comment|///
comment|/// The diagnostic should be reported. Various fatal errors (e.g.,
comment|/// template instantiation depth exceeded) fall into this category.
name|SFINAE_Report
block|,
comment|/// \brief The diagnostic is an access-control diagnostic, which will be
comment|/// substitution failures in some contexts and reported in others.
name|SFINAE_AccessControl
block|}
block|;
comment|/// \brief Determines whether the given built-in diagnostic ID is
comment|/// for an error that is suppressed if it occurs during C++ template
comment|/// argument deduction.
comment|///
comment|/// When an error is suppressed due to SFINAE, the template argument
comment|/// deduction fails but no diagnostic is emitted. Certain classes of
comment|/// errors, such as those errors that involve C++ access control,
comment|/// are not SFINAE errors.
specifier|static
name|SFINAEResponse
name|getDiagnosticSFINAEResponse
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// \brief Get the string of all diagnostic flags.
comment|///
comment|/// \returns A list of all diagnostics flags as they would be written in a
comment|/// command line invocation including their `no-` variants. For example:
comment|/// `{"-Wempty-body", "-Wno-empty-body", ...}`
specifier|static
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|getDiagnosticFlags
argument_list|()
block|;
comment|/// \brief Get the set of all diagnostic IDs in the group with the given name.
comment|///
comment|/// \param[out] Diags - On return, the diagnostics in the group.
comment|/// \returns \c true if the given group is unknown, \c false otherwise.
name|bool
name|getDiagnosticsInGroup
argument_list|(
argument|diag::Flavor Flavor
argument_list|,
argument|StringRef Group
argument_list|,
argument|SmallVectorImpl<diag::kind>&Diags
argument_list|)
specifier|const
block|;
comment|/// \brief Get the set of all diagnostic IDs.
name|void
name|getAllDiagnostics
argument_list|(
argument|diag::Flavor Flavor
argument_list|,
argument|SmallVectorImpl<diag::kind>&Diags
argument_list|)
specifier|const
block|;
comment|/// \brief Get the diagnostic option with the closest edit distance to the
comment|/// given group name.
specifier|static
name|StringRef
name|getNearestOption
argument_list|(
argument|diag::Flavor Flavor
argument_list|,
argument|StringRef Group
argument_list|)
block|;
name|private
operator|:
comment|/// \brief Classify the specified diagnostic ID into a Level, consumable by
comment|/// the DiagnosticClient.
comment|///
comment|/// The classification is based on the way the client configured the
comment|/// DiagnosticsEngine object.
comment|///
comment|/// \param Loc The source location for which we are interested in finding out
comment|/// the diagnostic state. Can be null in order to query the latest state.
name|DiagnosticIDs
operator|::
name|Level
name|getDiagnosticLevel
argument_list|(
argument|unsigned DiagID
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|const DiagnosticsEngine&Diag
argument_list|)
specifier|const
name|LLVM_READONLY
block|;
name|diag
operator|::
name|Severity
name|getDiagnosticSeverity
argument_list|(
argument|unsigned DiagID
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|const DiagnosticsEngine&Diag
argument_list|)
specifier|const
name|LLVM_READONLY
block|;
comment|/// \brief Used to report a diagnostic that is finally fully formed.
comment|///
comment|/// \returns \c true if the diagnostic was emitted, \c false if it was
comment|/// suppressed.
name|bool
name|ProcessDiag
argument_list|(
argument|DiagnosticsEngine&Diag
argument_list|)
specifier|const
block|;
comment|/// \brief Used to emit a diagnostic that is finally fully formed,
comment|/// ignoring suppression.
name|void
name|EmitDiag
argument_list|(
argument|DiagnosticsEngine&Diag
argument_list|,
argument|Level DiagLevel
argument_list|)
specifier|const
block|;
comment|/// \brief Whether the diagnostic may leave the AST in a state where some
comment|/// invariants can break.
name|bool
name|isUnrecoverable
argument_list|(
argument|unsigned DiagID
argument_list|)
specifier|const
block|;
name|friend
name|class
name|DiagnosticsEngine
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

