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

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GetElementPtrTypeIterator.h"
end_include

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
name|Function
decl_stmt|;
name|class
name|BranchInst
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|DbgDeclareInst
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|LoadInst
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
name|DataLayout
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TargetTransformInfo
decl_stmt|;
name|class
name|DIBuilder
decl_stmt|;
name|class
name|AliasAnalysis
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//  Local constant propagation.
comment|//
comment|/// ConstantFoldTerminator - If a terminator instruction is predicated on a
comment|/// constant value, convert it into an unconditional branch to the constant
comment|/// destination.  This is a nontrivial operation because the successors of this
comment|/// basic block must have their PHI nodes updated.
comment|/// Also calls RecursivelyDeleteTriviallyDeadInstructions() on any branch/switch
comment|/// conditions and indirectbr addresses this might make dead if
comment|/// DeleteDeadConditions is true.
name|bool
name|ConstantFoldTerminator
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|bool
name|DeleteDeadConditions
init|=
name|false
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
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
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// RecursivelyDeleteTriviallyDeadInstructions - If the specified value is a
comment|/// trivially dead instruction, delete it.  If that makes any of its operands
comment|/// trivially dead, delete them too, recursively.  Return true if any
comment|/// instructions were deleted.
name|bool
name|RecursivelyDeleteTriviallyDeadInstructions
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// RecursivelyDeleteDeadPHINode - If the specified value is an effectively
comment|/// dead PHI node, due to being a def-use chain of single-use nodes that
comment|/// either forms a cycle or is terminated by a trivially dead instruction,
comment|/// delete it.  If that makes any of its operands trivially dead, delete them
comment|/// too, recursively.  Return true if a change was made.
name|bool
name|RecursivelyDeleteDeadPHINode
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// SimplifyInstructionsInBlock - Scan the specified basic block and try to
comment|/// simplify any instructions in it and recursively delete dead instructions.
comment|///
comment|/// This returns true if it changed the code, note that it can delete
comment|/// instructions in other blocks as well in this block.
name|bool
name|SimplifyInstructionsInBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  Control Flow Graph Restructuring.
comment|//
comment|/// RemovePredecessorAndSimplify - Like BasicBlock::removePredecessor, this
comment|/// method is called when we're about to delete Pred as a predecessor of BB.  If
comment|/// BB contains any PHI nodes, this drops the entries in the PHI nodes for Pred.
comment|///
comment|/// Unlike the removePredecessor method, this attempts to simplify uses of PHI
comment|/// nodes that collapse into identity values.  For example, if we have:
comment|///   x = phi(1, 0, 0, 0)
comment|///   y = and x, z
comment|///
comment|/// .. and delete the predecessor corresponding to the '1', this will attempt to
comment|/// recursively fold the 'and' to 0.
name|void
name|RemovePredecessorAndSimplify
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|BasicBlock
modifier|*
name|Pred
parameter_list|,
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|)
function_decl|;
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
parameter_list|,
name|Pass
modifier|*
name|P
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// TryToSimplifyUncondBranchFromEmptyBlock - BB is known to contain an
comment|/// unconditional branch, and contains no instructions other than PHI nodes,
comment|/// potential debug intrinsics and the branch.  If possible, eliminate BB by
comment|/// rewriting all the predecessors to branch to the successor block and return
comment|/// true.  If we can't transform, return false.
name|bool
name|TryToSimplifyUncondBranchFromEmptyBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// EliminateDuplicatePHINodes - Check for and eliminate duplicate PHI
comment|/// nodes in this block. This doesn't try to be clever about PHI nodes
comment|/// which differ only in the order of the incoming values, but instcombine
comment|/// orders them so it usually won't matter.
comment|///
name|bool
name|EliminateDuplicatePHINodes
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
name|bool
name|SimplifyCFG
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
specifier|const
name|TargetTransformInfo
modifier|&
name|TTI
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// FlatternCFG - This function is used to flatten a CFG.  For
comment|/// example, it uses parallel-and and parallel-or mode to collapse
comment|//  if-conditions and merge if-regions with identical statements.
comment|///
name|bool
name|FlattenCFG
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|AliasAnalysis
modifier|*
name|AA
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// FoldBranchToCommonDest - If this basic block is ONLY a setcc and a branch,
comment|/// and if a predecessor branches to us and one of our successors, fold the
comment|/// setcc into the predecessor and use logical operations to pick the right
comment|/// destination.
name|bool
name|FoldBranchToCommonDest
parameter_list|(
name|BranchInst
modifier|*
name|BI
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
comment|/// getOrEnforceKnownAlignment - If the specified pointer has an alignment that
comment|/// we can determine, return it, otherwise return 0.  If PrefAlign is specified,
comment|/// and it is more than the alignment of the ultimate object, see if we can
comment|/// increase the alignment of the ultimate object, making this check succeed.
name|unsigned
name|getOrEnforceKnownAlignment
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|PrefAlign
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getKnownAlignment - Try to infer an alignment for the specified pointer.
specifier|static
specifier|inline
name|unsigned
name|getKnownAlignment
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|)
block|{
return|return
name|getOrEnforceKnownAlignment
argument_list|(
name|V
argument_list|,
literal|0
argument_list|,
name|TD
argument_list|)
return|;
block|}
comment|/// EmitGEPOffset - Given a getelementptr instruction/constantexpr, emit the
comment|/// code necessary to compute the offset from the base pointer (without adding
comment|/// in the base pointer).  Return the result as a signed integer of intptr size.
comment|/// When NoAssumptions is true, no assumptions about index computation not
comment|/// overflowing is made.
name|template
operator|<
name|typename
name|IRBuilderTy
operator|>
name|Value
operator|*
name|EmitGEPOffset
argument_list|(
argument|IRBuilderTy *Builder
argument_list|,
argument|const DataLayout&TD
argument_list|,
argument|User *GEP
argument_list|,
argument|bool NoAssumptions = false
argument_list|)
block|{
name|GEPOperator
operator|*
name|GEPOp
operator|=
name|cast
operator|<
name|GEPOperator
operator|>
operator|(
name|GEP
operator|)
block|;
name|Type
operator|*
name|IntPtrTy
operator|=
name|TD
operator|.
name|getIntPtrType
argument_list|(
name|GEP
operator|->
name|getType
argument_list|()
argument_list|)
block|;
name|Value
operator|*
name|Result
operator|=
name|Constant
operator|::
name|getNullValue
argument_list|(
name|IntPtrTy
argument_list|)
block|;
comment|// If the GEP is inbounds, we know that none of the addressing operations will
comment|// overflow in an unsigned sense.
name|bool
name|isInBounds
operator|=
name|GEPOp
operator|->
name|isInBounds
argument_list|()
operator|&&
operator|!
name|NoAssumptions
block|;
comment|// Build a mask for high order bits.
name|unsigned
name|IntPtrWidth
operator|=
name|IntPtrTy
operator|->
name|getScalarType
argument_list|()
operator|->
name|getIntegerBitWidth
argument_list|()
block|;
name|uint64_t
name|PtrSizeMask
operator|=
operator|~
literal|0ULL
operator|>>
operator|(
literal|64
operator|-
name|IntPtrWidth
operator|)
block|;
name|gep_type_iterator
name|GTI
operator|=
name|gep_type_begin
argument_list|(
name|GEP
argument_list|)
block|;
for|for
control|(
name|User
operator|::
name|op_iterator
name|i
operator|=
name|GEP
operator|->
name|op_begin
argument_list|()
operator|+
literal|1
operator|,
name|e
operator|=
name|GEP
operator|->
name|op_end
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
operator|,
operator|++
name|GTI
control|)
block|{
name|Value
modifier|*
name|Op
init|=
operator|*
name|i
decl_stmt|;
name|uint64_t
name|Size
init|=
name|TD
operator|.
name|getTypeAllocSize
argument_list|(
name|GTI
operator|.
name|getIndexedType
argument_list|()
argument_list|)
operator|&
name|PtrSizeMask
decl_stmt|;
if|if
condition|(
name|Constant
modifier|*
name|OpC
init|=
name|dyn_cast
operator|<
name|Constant
operator|>
operator|(
name|Op
operator|)
condition|)
block|{
if|if
condition|(
name|OpC
operator|->
name|isZeroValue
argument_list|()
condition|)
continue|continue;
comment|// Handle a struct index, which adds its field offset to the pointer.
if|if
condition|(
name|StructType
modifier|*
name|STy
init|=
name|dyn_cast
operator|<
name|StructType
operator|>
operator|(
operator|*
name|GTI
operator|)
condition|)
block|{
if|if
condition|(
name|OpC
operator|->
name|getType
argument_list|()
operator|->
name|isVectorTy
argument_list|()
condition|)
name|OpC
operator|=
name|OpC
operator|->
name|getSplatValue
argument_list|()
expr_stmt|;
name|uint64_t
name|OpValue
init|=
name|cast
operator|<
name|ConstantInt
operator|>
operator|(
name|OpC
operator|)
operator|->
name|getZExtValue
argument_list|()
decl_stmt|;
name|Size
operator|=
name|TD
operator|.
name|getStructLayout
argument_list|(
name|STy
argument_list|)
operator|->
name|getElementOffset
argument_list|(
name|OpValue
argument_list|)
expr_stmt|;
if|if
condition|(
name|Size
condition|)
name|Result
operator|=
name|Builder
operator|->
name|CreateAdd
argument_list|(
name|Result
argument_list|,
name|ConstantInt
operator|::
name|get
argument_list|(
name|IntPtrTy
argument_list|,
name|Size
argument_list|)
argument_list|,
name|GEP
operator|->
name|getName
argument_list|()
operator|+
literal|".offs"
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|Constant
modifier|*
name|Scale
init|=
name|ConstantInt
operator|::
name|get
argument_list|(
name|IntPtrTy
argument_list|,
name|Size
argument_list|)
decl_stmt|;
name|Constant
modifier|*
name|OC
init|=
name|ConstantExpr
operator|::
name|getIntegerCast
argument_list|(
name|OpC
argument_list|,
name|IntPtrTy
argument_list|,
name|true
comment|/*SExt*/
argument_list|)
decl_stmt|;
name|Scale
operator|=
name|ConstantExpr
operator|::
name|getMul
argument_list|(
name|OC
argument_list|,
name|Scale
argument_list|,
name|isInBounds
comment|/*NUW*/
argument_list|)
expr_stmt|;
comment|// Emit an add instruction.
name|Result
operator|=
name|Builder
operator|->
name|CreateAdd
argument_list|(
name|Result
argument_list|,
name|Scale
argument_list|,
name|GEP
operator|->
name|getName
argument_list|()
operator|+
literal|".offs"
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|// Convert to correct type.
if|if
condition|(
name|Op
operator|->
name|getType
argument_list|()
operator|!=
name|IntPtrTy
condition|)
name|Op
operator|=
name|Builder
operator|->
name|CreateIntCast
argument_list|(
name|Op
argument_list|,
name|IntPtrTy
argument_list|,
name|true
argument_list|,
name|Op
operator|->
name|getName
argument_list|()
operator|+
literal|".c"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Size
operator|!=
literal|1
condition|)
block|{
comment|// We'll let instcombine(mul) convert this to a shl if possible.
name|Op
operator|=
name|Builder
operator|->
name|CreateMul
argument_list|(
name|Op
argument_list|,
name|ConstantInt
operator|::
name|get
argument_list|(
name|IntPtrTy
argument_list|,
name|Size
argument_list|)
argument_list|,
name|GEP
operator|->
name|getName
argument_list|()
operator|+
literal|".idx"
argument_list|,
name|isInBounds
comment|/*NUW*/
argument_list|)
expr_stmt|;
block|}
comment|// Emit an add instruction.
name|Result
operator|=
name|Builder
operator|->
name|CreateAdd
argument_list|(
name|Op
argument_list|,
name|Result
argument_list|,
name|GEP
operator|->
name|getName
argument_list|()
operator|+
literal|".offs"
argument_list|)
expr_stmt|;
block|}
return|return
name|Result
return|;
block|}
comment|///===---------------------------------------------------------------------===//
comment|///  Dbg Intrinsic utilities
comment|///
comment|/// Inserts a llvm.dbg.value intrinsic before a store to an alloca'd value
comment|/// that has an associated llvm.dbg.decl intrinsic.
name|bool
name|ConvertDebugDeclareToDebugValue
parameter_list|(
name|DbgDeclareInst
modifier|*
name|DDI
parameter_list|,
name|StoreInst
modifier|*
name|SI
parameter_list|,
name|DIBuilder
modifier|&
name|Builder
parameter_list|)
function_decl|;
comment|/// Inserts a llvm.dbg.value intrinsic before a load of an alloca'd value
comment|/// that has an associated llvm.dbg.decl intrinsic.
name|bool
name|ConvertDebugDeclareToDebugValue
parameter_list|(
name|DbgDeclareInst
modifier|*
name|DDI
parameter_list|,
name|LoadInst
modifier|*
name|LI
parameter_list|,
name|DIBuilder
modifier|&
name|Builder
parameter_list|)
function_decl|;
comment|/// LowerDbgDeclare - Lowers llvm.dbg.declare intrinsics into appropriate set
comment|/// of llvm.dbg.value intrinsics.
name|bool
name|LowerDbgDeclare
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// FindAllocaDbgDeclare - Finds the llvm.dbg.declare intrinsic corresponding to
comment|/// an alloca, if any.
name|DbgDeclareInst
modifier|*
name|FindAllocaDbgDeclare
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// replaceDbgDeclareForAlloca - Replaces llvm.dbg.declare instruction when
comment|/// alloca is replaced with a new value.
name|bool
name|replaceDbgDeclareForAlloca
parameter_list|(
name|AllocaInst
modifier|*
name|AI
parameter_list|,
name|Value
modifier|*
name|NewAllocaAddress
parameter_list|,
name|DIBuilder
modifier|&
name|Builder
parameter_list|)
function_decl|;
comment|/// \brief Remove all blocks that can not be reached from the function's entry.
comment|///
comment|/// Returns true if any basic block was removed.
name|bool
name|removeUnreachableBlocks
parameter_list|(
name|Function
modifier|&
name|F
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

