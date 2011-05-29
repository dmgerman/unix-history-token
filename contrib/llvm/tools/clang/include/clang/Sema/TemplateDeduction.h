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
name|LLVM_CLANG_SEMA_TEMPLATE_DEDUCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_TEMPLATE_DEDUCTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/PartialDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
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
name|class
name|ASTContext
decl_stmt|;
name|class
name|TemplateArgumentList
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
comment|/// \brief The context in which the template arguments are stored.
name|ASTContext
modifier|&
name|Context
decl_stmt|;
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
comment|/// \brief Warnings (and follow-on notes) that were suppressed due to
comment|/// SFINAE while performing template argument deduction.
name|llvm
operator|::
name|SmallVector
operator|<
name|PartialDiagnosticAt
operator|,
literal|4
operator|>
name|SuppressedDiagnostics
expr_stmt|;
comment|// do not implement these
name|TemplateDeductionInfo
argument_list|(
specifier|const
name|TemplateDeductionInfo
operator|&
argument_list|)
expr_stmt|;
name|TemplateDeductionInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|TemplateDeductionInfo
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|TemplateDeductionInfo
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|SourceLocation Loc
argument_list|)
block|:
name|Context
argument_list|(
name|Context
argument_list|)
operator|,
name|Deduced
argument_list|(
literal|0
argument_list|)
operator|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{ }
operator|~
name|TemplateDeductionInfo
argument_list|()
block|{
comment|// FIXME: if (Deduced) Deduced->Destroy(Context);
block|}
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
literal|0
expr_stmt|;
return|return
name|Result
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
comment|// FIXME: if (Deduced) Deduced->Destroy(Context);
name|Deduced
operator|=
name|NewDeduced
expr_stmt|;
block|}
comment|/// \brief Add a new diagnostic to the set of diagnostics
name|void
name|addSuppressedDiagnostic
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PD
parameter_list|)
block|{
name|SuppressedDiagnostics
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Loc
argument_list|,
name|PD
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Iterator over the set of suppressed diagnostics.
typedef|typedef
name|llvm
operator|::
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
comment|///   TDK_NonDeducedMismatch: this is the template argument
comment|///   provided in the source code.
name|TemplateArgument
name|FirstArg
decl_stmt|;
comment|/// \brief The second template argument to which the template
comment|/// argument deduction failure refers.
comment|///
comment|/// FIXME: Finish documenting this.
name|TemplateArgument
name|SecondArg
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

