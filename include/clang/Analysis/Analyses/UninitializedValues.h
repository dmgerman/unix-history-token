begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- UninitializedValues.h - unintialized values analysis ----*- C++ --*-===//
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
comment|// This file provides the interface for the Unintialized Values analysis,
end_comment

begin_comment
comment|// a flow-sensitive analysis that detects when variable values are unintialized.
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
name|LLVM_CLANG_UNITVALS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_UNITVALS_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/Support/BlkExprDeclBitVector.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/FlowSensitive/DataflowValues.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|BlockVarDecl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|DeclRefExpr
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
comment|/// UninitializedValues_ValueTypes - Utility class to wrap type declarations
comment|///   for dataflow values and dataflow analysis state for the
comment|///   Unitialized Values analysis.
name|class
name|UninitializedValues_ValueTypes
block|{
name|public
label|:
struct_decl|struct
name|ObserverTy
struct_decl|;
name|struct
name|AnalysisDataTy
range|:
name|public
name|StmtDeclBitVector_Types
operator|::
name|AnalysisDataTy
block|{
name|AnalysisDataTy
argument_list|()
operator|:
name|Observer
argument_list|(
name|NULL
argument_list|)
block|,
name|FullUninitTaint
argument_list|(
argument|true
argument_list|)
block|{}
name|virtual
operator|~
name|AnalysisDataTy
argument_list|()
block|{}
name|ObserverTy
operator|*
name|Observer
block|;
name|bool
name|FullUninitTaint
block|;   }
decl_stmt|;
typedef|typedef
name|StmtDeclBitVector_Types
operator|::
name|ValTy
name|ValTy
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// ObserverTy - Observer for querying DeclRefExprs that use an uninitalized
comment|//   value.
comment|//===--------------------------------------------------------------------===//
struct|struct
name|ObserverTy
block|{
name|virtual
operator|~
name|ObserverTy
argument_list|()
expr_stmt|;
name|virtual
name|void
name|ObserveDeclRefExpr
parameter_list|(
name|ValTy
modifier|&
name|Val
parameter_list|,
name|AnalysisDataTy
modifier|&
name|AD
parameter_list|,
name|DeclRefExpr
modifier|*
name|DR
parameter_list|,
name|VarDecl
modifier|*
name|VD
parameter_list|)
init|=
literal|0
function_decl|;
block|}
struct|;
block|}
empty_stmt|;
comment|/// UninitializedValues - Objects of this class encapsulate dataflow analysis
comment|///  information regarding what variable declarations in a function are
comment|///  potentially unintialized.
name|class
name|UninitializedValues
range|:
name|public
name|DataflowValues
operator|<
name|UninitializedValues_ValueTypes
operator|>
block|{
name|public
operator|:
typedef|typedef
name|UninitializedValues_ValueTypes
operator|::
name|ObserverTy
name|ObserverTy
expr_stmt|;
name|UninitializedValues
argument_list|(
argument|CFG&cfg
argument_list|)
block|{
name|getAnalysisData
argument_list|()
operator|.
name|setCFG
argument_list|(
name|cfg
argument_list|)
block|; }
comment|/// IntializeValues - Create initial dataflow values and meta data for
comment|///  a given CFG.  This is intended to be called by the dataflow solver.
name|void
name|InitializeValues
argument_list|(
specifier|const
name|CFG
operator|&
name|cfg
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

