begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InstructionSimplify.h - Fold instructions into simpler forms ------===//
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
comment|// This file declares routines for folding instructions into simpler forms
end_comment

begin_comment
comment|// that do not require creating new instructions.  This does constant folding
end_comment

begin_comment
comment|// ("add i32 1, 1" -> "2") but can also handle non-constant operands, either
end_comment

begin_comment
comment|// returning a constant ("and i32 %x, 0" -> "0") or an already existing value
end_comment

begin_comment
comment|// ("and i32 %x, %x" -> "%x").  If the simplification is also an instruction
end_comment

begin_comment
comment|// then it dominates the original instruction.
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
name|LLVM_ANALYSIS_INSTRUCTIONSIMPLIFY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_INSTRUCTIONSIMPLIFY_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
comment|/// SimplifyAddInst - Given operands for an Add, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyAddInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
name|bool
name|isNSW
parameter_list|,
name|bool
name|isNUW
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifySubInst - Given operands for a Sub, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifySubInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
name|bool
name|isNSW
parameter_list|,
name|bool
name|isNUW
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyMulInst - Given operands for a Mul, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyMulInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifySDivInst - Given operands for an SDiv, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifySDivInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyUDivInst - Given operands for a UDiv, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyUDivInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyFDivInst - Given operands for an FDiv, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyFDivInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifySRemInst - Given operands for an SRem, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifySRemInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyURemInst - Given operands for a URem, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyURemInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyFRemInst - Given operands for an FRem, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyFRemInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyShlInst - Given operands for a Shl, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyShlInst
parameter_list|(
name|Value
modifier|*
name|Op0
parameter_list|,
name|Value
modifier|*
name|Op1
parameter_list|,
name|bool
name|isNSW
parameter_list|,
name|bool
name|isNUW
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyLShrInst - Given operands for a LShr, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyLShrInst
parameter_list|(
name|Value
modifier|*
name|Op0
parameter_list|,
name|Value
modifier|*
name|Op1
parameter_list|,
name|bool
name|isExact
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyAShrInst - Given operands for a AShr, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyAShrInst
parameter_list|(
name|Value
modifier|*
name|Op0
parameter_list|,
name|Value
modifier|*
name|Op1
parameter_list|,
name|bool
name|isExact
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyAndInst - Given operands for an And, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyAndInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyOrInst - Given operands for an Or, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyOrInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyXorInst - Given operands for a Xor, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyXorInst
parameter_list|(
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyICmpInst - Given operands for an ICmpInst, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyICmpInst
parameter_list|(
name|unsigned
name|Predicate
parameter_list|,
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyFCmpInst - Given operands for an FCmpInst, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyFCmpInst
parameter_list|(
name|unsigned
name|Predicate
parameter_list|,
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifySelectInst - Given operands for a SelectInst, see if we can fold
comment|/// the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifySelectInst
parameter_list|(
name|Value
modifier|*
name|Cond
parameter_list|,
name|Value
modifier|*
name|TrueVal
parameter_list|,
name|Value
modifier|*
name|FalseVal
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyGEPInst - Given operands for an GetElementPtrInst, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyGEPInst
parameter_list|(
name|Value
modifier|*
specifier|const
modifier|*
name|Ops
parameter_list|,
name|unsigned
name|NumOps
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|//=== Helper functions for higher up the class hierarchy.
comment|/// SimplifyCmpInst - Given operands for a CmpInst, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyCmpInst
parameter_list|(
name|unsigned
name|Predicate
parameter_list|,
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyBinOp - Given operands for a BinaryOperator, see if we can
comment|/// fold the result.  If not, this returns null.
name|Value
modifier|*
name|SimplifyBinOp
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|Value
modifier|*
name|LHS
parameter_list|,
name|Value
modifier|*
name|RHS
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyInstruction - See if we can compute a simplified version of this
comment|/// instruction.  If not, this returns null.
name|Value
modifier|*
name|SimplifyInstruction
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// ReplaceAndSimplifyAllUses - Perform From->replaceAllUsesWith(To) and then
comment|/// delete the From instruction.  In addition to a basic RAUW, this does a
comment|/// recursive simplification of the updated instructions.  This catches
comment|/// things where one simplification exposes other opportunities.  This only
comment|/// simplifies and deletes scalar operations, it does not change the CFG.
comment|///
name|void
name|ReplaceAndSimplifyAllUses
parameter_list|(
name|Instruction
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
literal|0
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

