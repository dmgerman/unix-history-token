begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// GRSimpleVals.h - Transfer functions for tracking simple values -*- C++ -*--//
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
comment|//  This file defines GRSimpleVals, a sub-class of GRTransferFuncs that
end_comment

begin_comment
comment|//  provides transfer functions for performing simple value tracking with
end_comment

begin_comment
comment|//  limited support for symbolics.
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
name|LLVM_CLANG_ANALYSIS_GRSIMPLEVALS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GRSIMPLEVALS
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRTransferFuncs.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRExprEngine.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|PathDiagnostic
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|GRSimpleVals
range|:
name|public
name|GRTransferFuncs
block|{
name|protected
operator|:
name|virtual
name|SVal
name|DetermEvalBinOpNN
argument_list|(
argument|GRExprEngine& Eng
argument_list|,
argument|BinaryOperator::Opcode Op
argument_list|,
argument|NonLoc L
argument_list|,
argument|NonLoc R
argument_list|,
argument|QualType T
argument_list|)
block|;
name|public
operator|:
name|GRSimpleVals
argument_list|()
block|{}
name|virtual
operator|~
name|GRSimpleVals
argument_list|()
block|{}
comment|// Casts.
name|virtual
name|SVal
name|EvalCast
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|NonLoc V
argument_list|,
argument|QualType CastT
argument_list|)
block|;
name|virtual
name|SVal
name|EvalCast
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|Loc V
argument_list|,
argument|QualType CastT
argument_list|)
block|;
comment|// Unary Operators.
name|virtual
name|SVal
name|EvalMinus
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|UnaryOperator* U
argument_list|,
argument|NonLoc X
argument_list|)
block|;
name|virtual
name|SVal
name|EvalComplement
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|NonLoc X
argument_list|)
block|;
comment|// Binary Operators.
name|virtual
name|SVal
name|EvalBinOp
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|BinaryOperator::Opcode Op
argument_list|,
argument|Loc L
argument_list|,
argument|Loc R
argument_list|)
block|;
comment|// Pointer arithmetic.
name|virtual
name|SVal
name|EvalBinOp
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|const GRState *state
argument_list|,
argument|BinaryOperator::Opcode Op
argument_list|,
argument|Loc L
argument_list|,
argument|NonLoc R
argument_list|)
block|;
comment|// Calls.
name|virtual
name|void
name|EvalCall
argument_list|(
argument|ExplodedNodeSet<GRState>& Dst
argument_list|,
argument|GRExprEngine& Engine
argument_list|,
argument|GRStmtNodeBuilder<GRState>& Builder
argument_list|,
argument|CallExpr* CE
argument_list|,
argument|SVal L
argument_list|,
argument|ExplodedNode<GRState>* Pred
argument_list|)
block|;
name|virtual
name|void
name|EvalObjCMessageExpr
argument_list|(
name|ExplodedNodeSet
operator|<
name|GRState
operator|>
operator|&
name|Dst
argument_list|,
name|GRExprEngine
operator|&
name|Engine
argument_list|,
name|GRStmtNodeBuilder
operator|<
name|GRState
operator|>
operator|&
name|Builder
argument_list|,
name|ObjCMessageExpr
operator|*
name|ME
argument_list|,
name|ExplodedNode
operator|<
name|GRState
operator|>
operator|*
name|Pred
argument_list|)
block|;
specifier|static
name|void
name|GeneratePathDiagnostic
argument_list|(
name|PathDiagnostic
operator|&
name|PD
argument_list|,
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|ExplodedNode
operator|<
name|GRState
operator|>
operator|*
name|N
argument_list|)
block|;
name|protected
operator|:
comment|// Equality (==, !=) operators for Locs.
name|SVal
name|EvalEquality
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|Loc L
argument_list|,
argument|Loc R
argument_list|,
argument|bool isEqual
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

