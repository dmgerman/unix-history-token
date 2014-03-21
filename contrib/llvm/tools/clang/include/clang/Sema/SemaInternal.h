begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SemaInternal.h - Internal Sema Interfaces --------------*- C++ -*-===//
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
comment|// This file provides common API and #includes for the internal
end_comment

begin_comment
comment|// implementation of Sema.
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
name|LLVM_CLANG_SEMA_SEMA_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SEMA_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Sema.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaDiagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
specifier|inline
name|PartialDiagnostic
name|Sema
operator|::
name|PDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|{
return|return
name|PartialDiagnostic
argument_list|(
name|DiagID
argument_list|,
name|Context
operator|.
name|getDiagAllocator
argument_list|()
argument_list|)
return|;
block|}
comment|// This requires the variable to be non-dependent and the initializer
comment|// to not be value dependent.
specifier|inline
name|bool
name|IsVariableAConstantExpression
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|ASTContext
modifier|&
name|Context
parameter_list|)
block|{
specifier|const
name|VarDecl
modifier|*
name|DefVD
init|=
literal|0
decl_stmt|;
return|return
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|Var
operator|)
operator|&&
name|Var
operator|->
name|isUsableInConstantExpressions
argument_list|(
name|Context
argument_list|)
operator|&&
name|Var
operator|->
name|getAnyInitializer
argument_list|(
name|DefVD
argument_list|)
operator|&&
name|DefVD
operator|->
name|checkInitIsICE
argument_list|()
return|;
block|}
comment|// Directly mark a variable odr-used. Given a choice, prefer to use
comment|// MarkVariableReferenced since it does additional checks and then
comment|// calls MarkVarDeclODRUsed.
comment|// If the variable must be captured:
comment|//  - if FunctionScopeIndexToStopAt is null, capture it in the CurContext
comment|//  - else capture it in the DeclContext that maps to the
comment|//    *FunctionScopeIndexToStopAt on the FunctionScopeInfo stack.
specifier|inline
name|void
name|MarkVarDeclODRUsed
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|Sema
modifier|&
name|SemaRef
parameter_list|,
specifier|const
name|unsigned
modifier|*
specifier|const
name|FunctionScopeIndexToStopAt
parameter_list|)
block|{
comment|// Keep track of used but undefined variables.
comment|// FIXME: We shouldn't suppress this warning for static data members.
if|if
condition|(
name|Var
operator|->
name|hasDefinition
argument_list|(
name|SemaRef
operator|.
name|Context
argument_list|)
operator|==
name|VarDecl
operator|::
name|DeclarationOnly
operator|&&
operator|!
name|Var
operator|->
name|isExternallyVisible
argument_list|()
operator|&&
operator|!
operator|(
name|Var
operator|->
name|isStaticDataMember
argument_list|()
operator|&&
name|Var
operator|->
name|hasInit
argument_list|()
operator|)
condition|)
block|{
name|SourceLocation
modifier|&
name|old
init|=
name|SemaRef
operator|.
name|UndefinedButUsed
index|[
name|Var
operator|->
name|getCanonicalDecl
argument_list|()
index|]
decl_stmt|;
if|if
condition|(
name|old
operator|.
name|isInvalid
argument_list|()
condition|)
name|old
operator|=
name|Loc
expr_stmt|;
block|}
name|QualType
name|CaptureType
decl_stmt|,
name|DeclRefType
decl_stmt|;
name|SemaRef
operator|.
name|tryCaptureVariable
argument_list|(
name|Var
argument_list|,
name|Loc
argument_list|,
name|Sema
operator|::
name|TryCapture_Implicit
argument_list|,
comment|/*EllipsisLoc*/
name|SourceLocation
argument_list|()
argument_list|,
comment|/*BuildAndDiagnose*/
name|true
argument_list|,
name|CaptureType
argument_list|,
name|DeclRefType
argument_list|,
name|FunctionScopeIndexToStopAt
argument_list|)
expr_stmt|;
name|Var
operator|->
name|markUsed
argument_list|(
name|SemaRef
operator|.
name|Context
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

