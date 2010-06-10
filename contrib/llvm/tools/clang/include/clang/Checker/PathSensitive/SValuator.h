begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// SValuator.h - Construction of SVals from evaluating expressions -*- C++ -*---
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
comment|//  This file defines SValuator, a class that defines the interface for
end_comment

begin_comment
comment|//  "symbolical evaluators" which construct an SVal from an expression.
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
name|LLVM_CLANG_ANALYSIS_SVALUATOR
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_SVALUATOR
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/Checker/PathSensitive/SVals.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GRState
decl_stmt|;
name|class
name|ValueManager
decl_stmt|;
name|class
name|SValuator
block|{
name|friend
name|class
name|ValueManager
decl_stmt|;
name|protected
label|:
name|ValueManager
modifier|&
name|ValMgr
decl_stmt|;
name|public
label|:
comment|// FIXME: Make these protected again one RegionStoreManager correctly
comment|// handles loads from differening bound value types.
name|virtual
name|SVal
name|EvalCastNL
parameter_list|(
name|NonLoc
name|val
parameter_list|,
name|QualType
name|castTy
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|SVal
name|EvalCastL
parameter_list|(
name|Loc
name|val
parameter_list|,
name|QualType
name|castTy
parameter_list|)
init|=
literal|0
function_decl|;
name|public
label|:
name|SValuator
argument_list|(
name|ValueManager
operator|&
name|valMgr
argument_list|)
operator|:
name|ValMgr
argument_list|(
argument|valMgr
argument_list|)
block|{}
name|virtual
operator|~
name|SValuator
argument_list|()
block|{}
name|SVal
name|EvalCast
argument_list|(
argument|SVal V
argument_list|,
argument|QualType castTy
argument_list|,
argument|QualType originalType
argument_list|)
expr_stmt|;
name|virtual
name|SVal
name|EvalMinus
parameter_list|(
name|NonLoc
name|val
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|SVal
name|EvalComplement
parameter_list|(
name|NonLoc
name|val
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|SVal
name|EvalBinOpNN
argument_list|(
specifier|const
name|GRState
operator|*
name|state
argument_list|,
name|BinaryOperator
operator|::
name|Opcode
name|Op
argument_list|,
name|NonLoc
name|lhs
argument_list|,
name|NonLoc
name|rhs
argument_list|,
name|QualType
name|resultTy
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|SVal
name|EvalBinOpLL
argument_list|(
name|BinaryOperator
operator|::
name|Opcode
name|Op
argument_list|,
name|Loc
name|lhs
argument_list|,
name|Loc
name|rhs
argument_list|,
name|QualType
name|resultTy
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|SVal
name|EvalBinOpLN
argument_list|(
specifier|const
name|GRState
operator|*
name|state
argument_list|,
name|BinaryOperator
operator|::
name|Opcode
name|Op
argument_list|,
name|Loc
name|lhs
argument_list|,
name|NonLoc
name|rhs
argument_list|,
name|QualType
name|resultTy
argument_list|)
init|=
literal|0
decl_stmt|;
name|SVal
name|EvalBinOp
argument_list|(
specifier|const
name|GRState
operator|*
name|ST
argument_list|,
name|BinaryOperator
operator|::
name|Opcode
name|Op
argument_list|,
name|SVal
name|L
argument_list|,
name|SVal
name|R
argument_list|,
name|QualType
name|T
argument_list|)
decl_stmt|;
name|DefinedOrUnknownSVal
name|EvalEQ
parameter_list|(
specifier|const
name|GRState
modifier|*
name|ST
parameter_list|,
name|DefinedOrUnknownSVal
name|L
parameter_list|,
name|DefinedOrUnknownSVal
name|R
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|SValuator
modifier|*
name|CreateSimpleSValuator
parameter_list|(
name|ValueManager
modifier|&
name|valMgr
parameter_list|)
function_decl|;
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

