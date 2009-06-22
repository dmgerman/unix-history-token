begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Local.h - Functions to perform local transformations ----*- C++ -*-===//
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
comment|// This family of functions perform various local transformations to the
end_comment

begin_comment
comment|// program.
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
name|LLVM_TRANSFORMS_UTILS_LOCAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_LOCAL_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|User
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|PHINode
decl_stmt|;
name|class
name|AllocaInst
decl_stmt|;
name|class
name|ConstantExpr
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
struct_decl|struct
name|DbgInfoIntrinsic
struct_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//  Local analysis.
comment|//
comment|/// isSafeToLoadUnconditionally - Return true if we know that executing a load
comment|/// from this value cannot trap.  If it is not obviously safe to load from the
comment|/// specified pointer, we do a quick local scan of the basic block containing
comment|/// ScanFrom, to determine if the address is already accessed.
name|bool
name|isSafeToLoadUnconditionally
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|Instruction
modifier|*
name|ScanFrom
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  Local constant propagation.
comment|//
comment|/// ConstantFoldTerminator - If a terminator instruction is predicated on a
comment|/// constant value, convert it into an unconditional branch to the constant
comment|/// destination.  This is a nontrivial operation because the successors of this
comment|/// basic block must have their PHI nodes updated.
comment|///
name|bool
name|ConstantFoldTerminator
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  Local dead code elimination.
comment|//
comment|/// isInstructionTriviallyDead - Return true if the result produced by the
comment|/// instruction is not used, and the instruction has no side effects.
comment|///
name|bool
name|isInstructionTriviallyDead
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// RecursivelyDeleteTriviallyDeadInstructions - If the specified value is a
comment|/// trivially dead instruction, delete it.  If that makes any of its operands
comment|/// trivially dead, delete them too, recursively.
name|void
name|RecursivelyDeleteTriviallyDeadInstructions
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// RecursivelyDeleteDeadPHINode - If the specified value is an effectively
comment|/// dead PHI node, due to being a def-use chain of single-use nodes that
comment|/// either forms a cycle or is terminated by a trivially dead instruction,
comment|/// delete it.  If that makes any of its operands trivially dead, delete them
comment|/// too, recursively.
name|void
name|RecursivelyDeleteDeadPHINode
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  Control Flow Graph Restructuring.
comment|//
comment|/// MergeBasicBlockIntoOnlyPred - BB is a block with one predecessor and its
comment|/// predecessor is known to have one successor (BB!).  Eliminate the edge
comment|/// between them, moving the instructions in the predecessor into BB.  This
comment|/// deletes the predecessor block.
comment|///
name|void
name|MergeBasicBlockIntoOnlyPred
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// SimplifyCFG - This function is used to do simplification of a CFG.  For
comment|/// example, it adjusts branches to branches to eliminate the extra hop, it
comment|/// eliminates unreachable basic blocks, and does other "peephole" optimization
comment|/// of the CFG.  It returns true if a modification was made, possibly deleting
comment|/// the basic block that was pointed to.
comment|///
comment|/// WARNING:  The entry node of a method may not be simplified.
comment|///
name|bool
name|SimplifyCFG
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// DemoteRegToStack - This function takes a virtual register computed by an
comment|/// Instruction and replaces it with a slot in the stack frame, allocated via
comment|/// alloca.  This allows the CFG to be changed around without fear of
comment|/// invalidating the SSA information for the value.  It returns the pointer to
comment|/// the alloca inserted to create a stack slot for X.
comment|///
name|AllocaInst
modifier|*
name|DemoteRegToStack
parameter_list|(
name|Instruction
modifier|&
name|X
parameter_list|,
name|bool
name|VolatileLoads
init|=
name|false
parameter_list|,
name|Instruction
modifier|*
name|AllocaPoint
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// DemotePHIToStack - This function takes a virtual register computed by a phi
comment|/// node and replaces it with a slot in the stack frame, allocated via alloca.
comment|/// The phi node is deleted and it returns the pointer to the alloca inserted.
name|AllocaInst
modifier|*
name|DemotePHIToStack
parameter_list|(
name|PHINode
modifier|*
name|P
parameter_list|,
name|Instruction
modifier|*
name|AllocaPoint
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// OnlyUsedByDbgIntrinsics - Return true if the instruction I is only used
comment|/// by DbgIntrinsics. If DbgInUses is specified then the vector is filled
comment|/// with DbgInfoIntrinsic that use the instruction I.
name|bool
name|OnlyUsedByDbgInfoIntrinsics
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|DbgInfoIntrinsic
operator|*
operator|>
operator|*
name|DbgInUses
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// UserIsDebugInfo - Return true if U is a constant expr used by
comment|/// llvm.dbg.variable or llvm.dbg.global_variable
name|bool
name|UserIsDebugInfo
parameter_list|(
name|User
modifier|*
name|U
parameter_list|)
function_decl|;
comment|/// RemoveDbgInfoUser - Remove an User which is representing debug info.
name|void
name|RemoveDbgInfoUser
parameter_list|(
name|User
modifier|*
name|U
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

