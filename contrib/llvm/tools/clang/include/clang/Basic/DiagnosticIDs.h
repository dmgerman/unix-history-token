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
comment|//
end_comment

begin_comment
comment|//  This file defines the Diagnostic IDs-related interfaces.
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
name|LLVM_CLANG_DIAGNOSTICIDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DIAGNOSTICIDS_H
end_define

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
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
operator|>
name|class
name|SmallVector
expr_stmt|;
block|}
end_decl_stmt

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
struct_decl|struct
name|WarningOption
struct_decl|;
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
literal|120
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
literal|3000
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
parameter_list|,\
name|SFINAE
parameter_list|,
name|ACCESS
parameter_list|,
name|CATEGORY
parameter_list|,
name|NOWERROR
parameter_list|,
name|SHOWINSYSHEADER
parameter_list|,
name|BRIEF
parameter_list|,
name|FULL
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
comment|//< Map this diagnostic to a fatal error.
block|}
enum|;
block|}
name|class
name|DiagnosticMappingInfo
block|{
name|unsigned
name|Mapping
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
name|HasShowInSystemHeader
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
name|public
label|:
specifier|static
name|DiagnosticMappingInfo
name|Make
argument_list|(
name|diag
operator|::
name|Mapping
name|Mapping
argument_list|,
name|bool
name|IsUser
argument_list|,
name|bool
name|IsPragma
argument_list|)
block|{
name|DiagnosticMappingInfo
name|Result
decl_stmt|;
name|Result
operator|.
name|Mapping
operator|=
name|Mapping
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
name|HasShowInSystemHeader
operator|=
literal|0
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
return|return
name|Result
return|;
block|}
name|diag
operator|::
name|Mapping
name|getMapping
argument_list|()
specifier|const
block|{
return|return
name|diag
operator|::
name|Mapping
argument_list|(
name|Mapping
argument_list|)
return|;
block|}
name|void
name|setMapping
argument_list|(
name|diag
operator|::
name|Mapping
name|Value
argument_list|)
block|{
name|Mapping
operator|=
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
name|hasShowInSystemHeader
argument_list|()
specifier|const
block|{
return|return
name|HasShowInSystemHeader
return|;
block|}
name|void
name|setShowInSystemHeader
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|HasShowInSystemHeader
operator|=
name|Value
expr_stmt|;
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
block|}
empty_stmt|;
comment|/// \brief Used for handling and querying diagnostic IDs. Can be used and shared
comment|/// by multiple Diagnostics for multiple translation units.
name|class
name|DiagnosticIDs
range|:
name|public
name|llvm
operator|::
name|RefCountedBase
operator|<
name|DiagnosticIDs
operator|>
block|{
name|public
operator|:
comment|/// Level - The level of the diagnostic, after it has been through mapping.
expr|enum
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
block|;
name|private
operator|:
comment|/// CustomDiagInfo - Information for uniquing and looking up custom diags.
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
comment|/// getCustomDiagID - Return an ID for a diagnostic with the specified message
comment|/// and level.  If this is the first request for this diagnosic, it is
comment|/// registered and created, otherwise the existing ID is returned.
name|unsigned
name|getCustomDiagID
argument_list|(
argument|Level L
argument_list|,
argument|StringRef Message
argument_list|)
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Diagnostic classification and reporting interfaces.
comment|//
comment|/// getDescription - Given a diagnostic ID, return a description of the
comment|/// issue.
name|StringRef
name|getDescription
argument_list|(
argument|unsigned DiagID
argument_list|)
specifier|const
block|;
comment|/// isBuiltinWarningOrExtension - Return true if the unmapped diagnostic level
comment|/// of the specified diagnostic ID is a Warning or Extension.  This only works
comment|/// on builtin diagnostics, not custom ones, and is not legal to call on
comment|/// NOTEs.
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
comment|/// \brief Determine whether the given built-in diagnostic ID is a
comment|/// Note.
specifier|static
name|bool
name|isBuiltinNote
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// isBuiltinExtensionDiag - Determine whether the given built-in diagnostic
comment|/// ID is for an extension of some sort.
comment|///
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
comment|/// isBuiltinExtensionDiag - Determine whether the given built-in diagnostic
comment|/// ID is for an extension of some sort.  This also returns EnabledByDefault,
comment|/// which is set to indicate whether the diagnostic is ignored by default (in
comment|/// which case -pedantic enables it) or treated as a warning/error by default.
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
comment|/// getWarningOptionForDiag - Return the lowest-level warning option that
comment|/// enables the specified diagnostic.  If there is no -Wfoo flag that controls
comment|/// the diagnostic, this returns null.
specifier|static
name|StringRef
name|getWarningOptionForDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// getCategoryNumberForDiag - Return the category number that a specified
comment|/// DiagID belongs to, or 0 if no category.
specifier|static
name|unsigned
name|getCategoryNumberForDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// getNumberOfCategories - Return the number of categories
specifier|static
name|unsigned
name|getNumberOfCategories
argument_list|()
block|;
comment|/// getCategoryNameFromID - Given a category ID, return the name of the
comment|/// category.
specifier|static
name|StringRef
name|getCategoryNameFromID
argument_list|(
argument|unsigned CategoryID
argument_list|)
block|;
comment|/// \brief Enumeration describing how the the emission of a diagnostic should
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
comment|/// getName - Given a diagnostic ID, return its name
specifier|static
name|StringRef
name|getName
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// getIdFromName - Given a diagnostic name, return its ID, or 0
specifier|static
name|unsigned
name|getIdFromName
argument_list|(
argument|StringRef Name
argument_list|)
block|;
comment|/// getBriefExplanation - Given a diagnostic ID, return a brief explanation
comment|/// of the issue
specifier|static
name|StringRef
name|getBriefExplanation
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// getFullExplanation - Given a diagnostic ID, return a full explanation
comment|/// of the issue
specifier|static
name|StringRef
name|getFullExplanation
argument_list|(
argument|unsigned DiagID
argument_list|)
block|;
comment|/// Iterator class used for traversing all statically declared
comment|/// diagnostics.
name|class
name|diag_iterator
block|{
specifier|const
name|void
operator|*
name|impl
block|;
name|friend
name|class
name|DiagnosticIDs
block|;
name|diag_iterator
argument_list|(
specifier|const
name|void
operator|*
name|im
argument_list|)
operator|:
name|impl
argument_list|(
argument|im
argument_list|)
block|{}
name|public
operator|:
name|diag_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|diag_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|impl
operator|==
name|x
operator|.
name|impl
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|diag_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|impl
operator|!=
name|x
operator|.
name|impl
return|;
block|}
name|llvm
operator|::
name|StringRef
name|getDiagName
argument_list|()
specifier|const
block|;
name|unsigned
name|getDiagID
argument_list|()
specifier|const
block|;       }
block|;
specifier|static
name|diag_iterator
name|diags_begin
argument_list|()
block|;
specifier|static
name|diag_iterator
name|diags_end
argument_list|()
block|;
comment|/// \brief Get the set of all diagnostic IDs in the group with the given name.
comment|///
comment|/// \param Diags [out] - On return, the diagnostics in the group.
comment|/// \returns True if the given group is unknown, false otherwise.
name|bool
name|getDiagnosticsInGroup
argument_list|(
argument|StringRef Group
argument_list|,
argument|llvm::SmallVectorImpl<diag::kind>&Diags
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|/// \brief Get the set of all diagnostic IDs in the given group.
comment|///
comment|/// \param Diags [out] - On return, the diagnostics in the group.
name|void
name|getDiagnosticsInGroup
argument_list|(
argument|const WarningOption *Group
argument_list|,
argument|llvm::SmallVectorImpl<diag::kind>&Diags
argument_list|)
specifier|const
block|;
comment|/// \brief Based on the way the client configured the DiagnosticsEngine
comment|/// object, classify the specified diagnostic ID into a Level, consumable by
comment|/// the DiagnosticClient.
comment|///
comment|/// \param Loc The source location we are interested in finding out the
comment|/// diagnostic state. Can be null in order to query the latest state.
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
block|;
comment|/// getDiagnosticLevel - This is an internal implementation helper used when
comment|/// DiagClass is already known.
name|DiagnosticIDs
operator|::
name|Level
name|getDiagnosticLevel
argument_list|(
argument|unsigned DiagID
argument_list|,
argument|unsigned DiagClass
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|const DiagnosticsEngine&Diag
argument_list|)
specifier|const
block|;
comment|/// ProcessDiag - This is the method used to report a diagnostic that is
comment|/// finally fully formed.
comment|///
comment|/// \returns true if the diagnostic was emitted, false if it was
comment|/// suppressed.
name|bool
name|ProcessDiag
argument_list|(
argument|DiagnosticsEngine&Diag
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

