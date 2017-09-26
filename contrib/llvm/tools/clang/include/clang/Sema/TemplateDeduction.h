begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TemplateDeduction.h - C++ template argument deduction ----*- C++ -*-===/
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
comment|//===----------------------------------------------------------------------===/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file provides types used with Sema's template argument deduction
end_comment

begin_comment
comment|// routines.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SEMA_TEMPLATEDEDUCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_TEMPLATEDEDUCTION_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/PartialDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
struct_decl|struct
name|DeducedPack
struct_decl|;
name|class
name|TemplateArgumentList
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|namespace
name|sema
block|{
comment|/// \brief Provides information about an attempted template argument
comment|/// deduction, whose success or failure was described by a
comment|/// TemplateDeductionResult value.
name|class
name|TemplateDeductionInfo
block|{
comment|/// \brief The deduced template argument list.
comment|///
name|TemplateArgumentList
modifier|*
name|Deduced
decl_stmt|;
comment|/// \brief The source location at which template argument
comment|/// deduction is occurring.
name|SourceLocation
name|Loc
decl_stmt|;
comment|/// \brief Have we suppressed an error during deduction?
name|bool
name|HasSFINAEDiagnostic
decl_stmt|;
comment|/// \brief The template parameter depth for which we're performing deduction.
name|unsigned
name|DeducedDepth
decl_stmt|;
comment|/// \brief Warnings (and follow-on notes) that were suppressed due to
comment|/// SFINAE while performing template argument deduction.
name|SmallVector
operator|<
name|PartialDiagnosticAt
operator|,
literal|4
operator|>
name|SuppressedDiagnostics
expr_stmt|;
name|TemplateDeductionInfo
argument_list|(
specifier|const
name|TemplateDeductionInfo
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TemplateDeductionInfo
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|TemplateDeductionInfo
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|unsigned DeducedDepth =
literal|0
argument_list|)
block|:
name|Deduced
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Loc
argument_list|(
name|Loc
argument_list|)
operator|,
name|HasSFINAEDiagnostic
argument_list|(
name|false
argument_list|)
operator|,
name|DeducedDepth
argument_list|(
name|DeducedDepth
argument_list|)
operator|,
name|CallArgIndex
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Returns the location at which template argument is
comment|/// occurring.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief The depth of template parameters for which deduction is being
comment|/// performed.
name|unsigned
name|getDeducedDepth
argument_list|()
specifier|const
block|{
return|return
name|DeducedDepth
return|;
block|}
comment|/// \brief Take ownership of the deduced template argument list.
name|TemplateArgumentList
modifier|*
name|take
parameter_list|()
block|{
name|TemplateArgumentList
modifier|*
name|Result
init|=
name|Deduced
decl_stmt|;
name|Deduced
operator|=
name|nullptr
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// \brief Take ownership of the SFINAE diagnostic.
name|void
name|takeSFINAEDiagnostic
parameter_list|(
name|PartialDiagnosticAt
modifier|&
name|PD
parameter_list|)
block|{
name|assert
argument_list|(
name|HasSFINAEDiagnostic
argument_list|)
expr_stmt|;
name|PD
operator|.
name|first
operator|=
name|SuppressedDiagnostics
operator|.
name|front
argument_list|()
operator|.
name|first
expr_stmt|;
name|PD
operator|.
name|second
operator|.
name|swap
argument_list|(
name|SuppressedDiagnostics
operator|.
name|front
argument_list|()
operator|.
name|second
argument_list|)
expr_stmt|;
name|clearSFINAEDiagnostic
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Discard any SFINAE diagnostics.
name|void
name|clearSFINAEDiagnostic
parameter_list|()
block|{
name|SuppressedDiagnostics
operator|.
name|clear
argument_list|()
expr_stmt|;
name|HasSFINAEDiagnostic
operator|=
name|false
expr_stmt|;
block|}
comment|/// Peek at the SFINAE diagnostic.
specifier|const
name|PartialDiagnosticAt
operator|&
name|peekSFINAEDiagnostic
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|HasSFINAEDiagnostic
argument_list|)
block|;
return|return
name|SuppressedDiagnostics
operator|.
name|front
argument_list|()
return|;
block|}
comment|/// \brief Provide a new template argument list that contains the
comment|/// results of template argument deduction.
name|void
name|reset
parameter_list|(
name|TemplateArgumentList
modifier|*
name|NewDeduced
parameter_list|)
block|{
name|Deduced
operator|=
name|NewDeduced
expr_stmt|;
block|}
comment|/// \brief Is a SFINAE diagnostic available?
name|bool
name|hasSFINAEDiagnostic
argument_list|()
specifier|const
block|{
return|return
name|HasSFINAEDiagnostic
return|;
block|}
comment|/// \brief Set the diagnostic which caused the SFINAE failure.
name|void
name|addSFINAEDiagnostic
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|PartialDiagnostic
name|PD
parameter_list|)
block|{
comment|// Only collect the first diagnostic.
if|if
condition|(
name|HasSFINAEDiagnostic
condition|)
return|return;
name|SuppressedDiagnostics
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SuppressedDiagnostics
operator|.
name|emplace_back
argument_list|(
name|Loc
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PD
argument_list|)
argument_list|)
expr_stmt|;
name|HasSFINAEDiagnostic
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Add a new diagnostic to the set of diagnostics
name|void
name|addSuppressedDiagnostic
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|PartialDiagnostic
name|PD
parameter_list|)
block|{
if|if
condition|(
name|HasSFINAEDiagnostic
condition|)
return|return;
name|SuppressedDiagnostics
operator|.
name|emplace_back
argument_list|(
name|Loc
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PD
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Iterator over the set of suppressed diagnostics.
typedef|typedef
name|SmallVectorImpl
operator|<
name|PartialDiagnosticAt
operator|>
operator|::
name|const_iterator
name|diag_iterator
expr_stmt|;
comment|/// \brief Returns an iterator at the beginning of the sequence of suppressed
comment|/// diagnostics.
name|diag_iterator
name|diag_begin
argument_list|()
specifier|const
block|{
return|return
name|SuppressedDiagnostics
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// \brief Returns an iterator at the end of the sequence of suppressed
comment|/// diagnostics.
name|diag_iterator
name|diag_end
argument_list|()
specifier|const
block|{
return|return
name|SuppressedDiagnostics
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief The template parameter to which a template argument
comment|/// deduction failure refers.
comment|///
comment|/// Depending on the result of template argument deduction, this
comment|/// template parameter may have different meanings:
comment|///
comment|///   TDK_Incomplete: this is the first template parameter whose
comment|///   corresponding template argument was not deduced.
comment|///
comment|///   TDK_Inconsistent: this is the template parameter for which
comment|///   two different template argument values were deduced.
name|TemplateParameter
name|Param
decl_stmt|;
comment|/// \brief The first template argument to which the template
comment|/// argument deduction failure refers.
comment|///
comment|/// Depending on the result of the template argument deduction,
comment|/// this template argument may have different meanings:
comment|///
comment|///   TDK_Inconsistent: this argument is the first value deduced
comment|///   for the corresponding template parameter.
comment|///
comment|///   TDK_SubstitutionFailure: this argument is the template
comment|///   argument we were instantiating when we encountered an error.
comment|///
comment|///   TDK_DeducedMismatch: this is the parameter type, after substituting
comment|///   deduced arguments.
comment|///
comment|///   TDK_NonDeducedMismatch: this is the component of the 'parameter'
comment|///   of the deduction, directly provided in the source code.
name|TemplateArgument
name|FirstArg
decl_stmt|;
comment|/// \brief The second template argument to which the template
comment|/// argument deduction failure refers.
comment|///
comment|///   TDK_Inconsistent: this argument is the second value deduced
comment|///   for the corresponding template parameter.
comment|///
comment|///   TDK_DeducedMismatch: this is the (adjusted) call argument type.
comment|///
comment|///   TDK_NonDeducedMismatch: this is the mismatching component of the
comment|///   'argument' of the deduction, from which we are deducing arguments.
comment|///
comment|/// FIXME: Finish documenting this.
name|TemplateArgument
name|SecondArg
decl_stmt|;
comment|/// \brief The index of the function argument that caused a deduction
comment|/// failure.
comment|///
comment|///   TDK_DeducedMismatch: this is the index of the argument that had a
comment|///   different argument type from its substituted parameter type.
name|unsigned
name|CallArgIndex
decl_stmt|;
comment|/// \brief Information on packs that we're currently expanding.
comment|///
comment|/// FIXME: This should be kept internal to SemaTemplateDeduction.
name|SmallVector
operator|<
name|DeducedPack
operator|*
operator|,
literal|8
operator|>
name|PendingDeducedPacks
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace sema
comment|/// A structure used to record information about a failed
comment|/// template argument deduction, for diagnosis.
struct|struct
name|DeductionFailureInfo
block|{
comment|/// A Sema::TemplateDeductionResult.
name|unsigned
name|Result
range|:
literal|8
decl_stmt|;
comment|/// \brief Indicates whether a diagnostic is stored in Diagnostic.
name|unsigned
name|HasDiagnostic
range|:
literal|1
decl_stmt|;
comment|/// \brief Opaque pointer containing additional data about
comment|/// this deduction failure.
name|void
modifier|*
name|Data
decl_stmt|;
comment|/// \brief A diagnostic indicating why deduction failed.
name|alignas
argument_list|(
argument|PartialDiagnosticAt
argument_list|)
name|char
name|Diagnostic
index|[
sizeof|sizeof
argument_list|(
name|PartialDiagnosticAt
argument_list|)
index|]
decl_stmt|;
comment|/// \brief Retrieve the diagnostic which caused this deduction failure,
comment|/// if any.
name|PartialDiagnosticAt
modifier|*
name|getSFINAEDiagnostic
parameter_list|()
function_decl|;
comment|/// \brief Retrieve the template parameter this deduction failure
comment|/// refers to, if any.
name|TemplateParameter
name|getTemplateParameter
parameter_list|()
function_decl|;
comment|/// \brief Retrieve the template argument list associated with this
comment|/// deduction failure, if any.
name|TemplateArgumentList
modifier|*
name|getTemplateArgumentList
parameter_list|()
function_decl|;
comment|/// \brief Return the first template argument this deduction failure
comment|/// refers to, if any.
specifier|const
name|TemplateArgument
modifier|*
name|getFirstArg
parameter_list|()
function_decl|;
comment|/// \brief Return the second template argument this deduction failure
comment|/// refers to, if any.
specifier|const
name|TemplateArgument
modifier|*
name|getSecondArg
parameter_list|()
function_decl|;
comment|/// \brief Return the index of the call argument that this deduction
comment|/// failure refers to, if any.
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|getCallArgIndex
argument_list|()
expr_stmt|;
comment|/// \brief Free any memory associated with this deduction failure.
name|void
name|Destroy
parameter_list|()
function_decl|;
block|}
struct|;
comment|/// TemplateSpecCandidate - This is a generalization of OverloadCandidate
comment|/// which keeps track of template argument deduction failure info, when
comment|/// handling explicit specializations (and instantiations) of templates
comment|/// beyond function overloading.
comment|/// For now, assume that the candidates are non-matching specializations.
comment|/// TODO: In the future, we may need to unify/generalize this with
comment|/// OverloadCandidate.
struct|struct
name|TemplateSpecCandidate
block|{
comment|/// \brief The declaration that was looked up, together with its access.
comment|/// Might be a UsingShadowDecl, but usually a FunctionTemplateDecl.
name|DeclAccessPair
name|FoundDecl
decl_stmt|;
comment|/// Specialization - The actual specialization that this candidate
comment|/// represents. When NULL, this may be a built-in candidate.
name|Decl
modifier|*
name|Specialization
decl_stmt|;
comment|/// Template argument deduction info
name|DeductionFailureInfo
name|DeductionFailure
decl_stmt|;
name|void
name|set
parameter_list|(
name|DeclAccessPair
name|Found
parameter_list|,
name|Decl
modifier|*
name|Spec
parameter_list|,
name|DeductionFailureInfo
name|Info
parameter_list|)
block|{
name|FoundDecl
operator|=
name|Found
expr_stmt|;
name|Specialization
operator|=
name|Spec
expr_stmt|;
name|DeductionFailure
operator|=
name|Info
expr_stmt|;
block|}
comment|/// Diagnose a template argument deduction failure.
name|void
name|NoteDeductionFailure
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|bool
name|ForTakingAddress
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// TemplateSpecCandidateSet - A set of generalized overload candidates,
comment|/// used in template specializations.
comment|/// TODO: In the future, we may need to unify/generalize this with
comment|/// OverloadCandidateSet.
name|class
name|TemplateSpecCandidateSet
block|{
name|SmallVector
operator|<
name|TemplateSpecCandidate
operator|,
literal|16
operator|>
name|Candidates
expr_stmt|;
name|SourceLocation
name|Loc
decl_stmt|;
comment|// Stores whether we're taking the address of these candidates. This helps us
comment|// produce better error messages when dealing with the pass_object_size
comment|// attribute on parameters.
name|bool
name|ForTakingAddress
decl_stmt|;
name|TemplateSpecCandidateSet
argument_list|(
specifier|const
name|TemplateSpecCandidateSet
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TemplateSpecCandidateSet
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|void
name|destroyCandidates
parameter_list|()
function_decl|;
name|public
label|:
name|TemplateSpecCandidateSet
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|bool ForTakingAddress = false
argument_list|)
block|:
name|Loc
argument_list|(
name|Loc
argument_list|)
operator|,
name|ForTakingAddress
argument_list|(
argument|ForTakingAddress
argument_list|)
block|{}
operator|~
name|TemplateSpecCandidateSet
argument_list|()
block|{
name|destroyCandidates
argument_list|()
block|; }
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Clear out all of the candidates.
comment|/// TODO: This may be unnecessary.
name|void
name|clear
parameter_list|()
function_decl|;
typedef|typedef
name|SmallVector
operator|<
name|TemplateSpecCandidate
operator|,
literal|16
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Candidates
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Candidates
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Candidates
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Candidates
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Add a new candidate with NumConversions conversion sequence slots
comment|/// to the overload set.
name|TemplateSpecCandidate
modifier|&
name|addCandidate
parameter_list|()
block|{
name|Candidates
operator|.
name|emplace_back
argument_list|()
expr_stmt|;
return|return
name|Candidates
operator|.
name|back
argument_list|()
return|;
block|}
name|void
name|NoteCandidates
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
name|void
name|NoteCandidates
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
name|const_cast
operator|<
name|TemplateSpecCandidateSet
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|NoteCandidates
argument_list|(
name|S
argument_list|,
name|Loc
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
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

