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
comment|// This file declares routines for folding instructions into simpler forms that
end_comment

begin_comment
comment|// do not require creating new instructions.  For example, this does constant
end_comment

begin_comment
comment|// folding, and can handle identities like (X&0)->0.
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
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
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

