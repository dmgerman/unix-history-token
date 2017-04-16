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
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GetElementPtrTypeIterator.h"
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
file|"llvm/ADT/SmallPtrSet.h"
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
name|CallInst
decl_stmt|;
name|class
name|DbgDeclareInst
decl_stmt|;
name|class
name|DbgValueInst
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
name|PHINode
decl_stmt|;
name|class
name|AllocaInst
decl_stmt|;
name|class
name|AssumptionCache
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
name|DominatorTree
decl_stmt|;
name|class
name|LazyValueInfo
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
comment|/// If a terminator instruction is predicated on a constant value, convert it
comment|/// into an unconditional branch to the constant destination.
comment|/// This is a nontrivial operation because the successors of this basic block
comment|/// must have their PHI nodes updated.
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
name|nullptr
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  Local dead code elimination.
comment|//
comment|/// Return true if the result produced by the instruction is not used, and the
comment|/// instruction has no side effects.
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// Return true if the result produced by the instruction would have no side
comment|/// effects if it was not used. This is equivalent to checking whether
comment|/// isInstructionTriviallyDead would be true if the use count was 0.
name|bool
name|wouldInstructionBeTriviallyDead
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// If the specified value is a trivially dead instruction, delete it.
comment|/// If that makes any of its operands trivially dead, delete them too,
comment|/// recursively. Return true if any instructions were deleted.
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// If the specified value is an effectively dead PHI node, due to being a
comment|/// def-use chain of single-use nodes that either forms a cycle or is terminated
comment|/// by a trivially dead instruction, delete it. If that makes any of its
comment|/// operands trivially dead, delete them too, recursively. Return true if a
comment|/// change was made.
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// Scan the specified basic block and try to simplify any instructions in it
comment|/// and recursively delete dead instructions.
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
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  Control Flow Graph Restructuring.
comment|//
comment|/// Like BasicBlock::removePredecessor, this method is called when we're about
comment|/// to delete Pred as a predecessor of BB. If BB contains any PHI nodes, this
comment|/// drops the entries in the PHI nodes for Pred.
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
parameter_list|)
function_decl|;
comment|/// BB is a block with one predecessor and its predecessor is known to have one
comment|/// successor (BB!). Eliminate the edge between them, moving the instructions in
comment|/// the predecessor into BB. This deletes the predecessor block.
name|void
name|MergeBasicBlockIntoOnlyPred
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// BB is known to contain an unconditional branch, and contains no instructions
comment|/// other than PHI nodes, potential debug intrinsics and the branch. If
comment|/// possible, eliminate BB by rewriting all the predecessors to branch to the
comment|/// successor block and return true. If we can't transform, return false.
name|bool
name|TryToSimplifyUncondBranchFromEmptyBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// Check for and eliminate duplicate PHI nodes in this block. This doesn't try
comment|/// to be clever about PHI nodes which differ only in the order of the incoming
comment|/// values, but instcombine orders them so it usually won't matter.
name|bool
name|EliminateDuplicatePHINodes
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// This function is used to do simplification of a CFG.  For
comment|/// example, it adjusts branches to branches to eliminate the extra hop, it
comment|/// eliminates unreachable basic blocks, and does other "peephole" optimization
comment|/// of the CFG.  It returns true if a modification was made, possibly deleting
comment|/// the basic block that was pointed to. LoopHeaders is an optional input
comment|/// parameter, providing the set of loop header that SimplifyCFG should not
comment|/// eliminate.
name|bool
name|SimplifyCFG
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
specifier|const
name|TargetTransformInfo
operator|&
name|TTI
argument_list|,
name|unsigned
name|BonusInstThreshold
argument_list|,
name|AssumptionCache
operator|*
name|AC
operator|=
name|nullptr
argument_list|,
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|*
name|LoopHeaders
operator|=
name|nullptr
argument_list|,
name|bool
name|LateSimplifyCFG
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// This function is used to flatten a CFG. For example, it uses parallel-and
comment|/// and parallel-or mode to collapse if-conditions and merge if-regions with
comment|/// identical statements.
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// If this basic block is ONLY a setcc and a branch, and if a predecessor
comment|/// branches to us and one of our successors, fold the setcc into the
comment|/// predecessor and use logical operations to pick the right destination.
name|bool
name|FoldBranchToCommonDest
parameter_list|(
name|BranchInst
modifier|*
name|BI
parameter_list|,
name|unsigned
name|BonusInstThreshold
init|=
literal|1
parameter_list|)
function_decl|;
comment|/// This function takes a virtual register computed by an Instruction and
comment|/// replaces it with a slot in the stack frame, allocated via alloca.
comment|/// This allows the CFG to be changed around without fear of invalidating the
comment|/// SSA information for the value. It returns the pointer to the alloca inserted
comment|/// to create a stack slot for X.
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// This function takes a virtual register computed by a phi node and replaces
comment|/// it with a slot in the stack frame, allocated via alloca. The phi node is
comment|/// deleted and it returns the pointer to the alloca inserted.
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// Try to ensure that the alignment of \p V is at least \p PrefAlign bytes. If
comment|/// the owning object can be modified and has an alignment less than \p
comment|/// PrefAlign, it will be increased and \p PrefAlign returned. If the alignment
comment|/// cannot be increased, the known alignment of the value is returned.
comment|///
comment|/// It is not always possible to modify the alignment of the underlying object,
comment|/// so if alignment is important, a more reliable approach is to simply align
comment|/// all global variables and allocation instructions to their preferred
comment|/// alignment from the beginning.
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
modifier|&
name|DL
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Try to infer an alignment for the specified pointer.
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
modifier|&
name|DL
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CxtI
init|=
name|nullptr
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|getOrEnforceKnownAlignment
argument_list|(
name|V
argument_list|,
literal|0
argument_list|,
name|DL
argument_list|,
name|CxtI
argument_list|,
name|AC
argument_list|,
name|DT
argument_list|)
return|;
block|}
comment|/// Given a getelementptr instruction/constantexpr, emit the code necessary to
comment|/// compute the offset from the base pointer (without adding in the base
comment|/// pointer). Return the result as a signed integer of intptr size.
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
argument|const DataLayout&DL
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
name|DL
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
name|DL
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
name|GTI
operator|.
name|getStructTypeOrNull
argument_list|()
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
name|DL
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
name|void
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
name|void
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
comment|/// Inserts a llvm.dbg.value intrinsic after a phi of an alloca'd value
comment|/// that has an associated llvm.dbg.decl intrinsic.
name|void
name|ConvertDebugDeclareToDebugValue
parameter_list|(
name|DbgDeclareInst
modifier|*
name|DDI
parameter_list|,
name|PHINode
modifier|*
name|LI
parameter_list|,
name|DIBuilder
modifier|&
name|Builder
parameter_list|)
function_decl|;
comment|/// Lowers llvm.dbg.declare intrinsics into appropriate set of
comment|/// llvm.dbg.value intrinsics.
name|bool
name|LowerDbgDeclare
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// Finds the llvm.dbg.declare intrinsic corresponding to an alloca, if any.
name|DbgDeclareInst
modifier|*
name|FindAllocaDbgDeclare
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Finds the llvm.dbg.value intrinsics describing a value.
name|void
name|findDbgValues
argument_list|(
name|SmallVectorImpl
operator|<
name|DbgValueInst
operator|*
operator|>
operator|&
name|DbgValues
argument_list|,
name|Value
operator|*
name|V
argument_list|)
decl_stmt|;
comment|/// Constants for \p replaceDbgDeclare and friends.
enum|enum
block|{
name|NoDeref
init|=
name|false
block|,
name|WithDeref
init|=
name|true
block|}
enum|;
comment|/// Replaces llvm.dbg.declare instruction when the address it describes
comment|/// is replaced with a new value. If Deref is true, an additional DW_OP_deref is
comment|/// prepended to the expression. If Offset is non-zero, a constant displacement
comment|/// is added to the expression (after the optional Deref). Offset can be
comment|/// negative.
name|bool
name|replaceDbgDeclare
parameter_list|(
name|Value
modifier|*
name|Address
parameter_list|,
name|Value
modifier|*
name|NewAddress
parameter_list|,
name|Instruction
modifier|*
name|InsertBefore
parameter_list|,
name|DIBuilder
modifier|&
name|Builder
parameter_list|,
name|bool
name|Deref
parameter_list|,
name|int
name|Offset
parameter_list|)
function_decl|;
comment|/// Replaces llvm.dbg.declare instruction when the alloca it describes
comment|/// is replaced with a new value. If Deref is true, an additional DW_OP_deref is
comment|/// prepended to the expression. If Offset is non-zero, a constant displacement
comment|/// is added to the expression (after the optional Deref). Offset can be
comment|/// negative. New llvm.dbg.declare is inserted immediately before AI.
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
parameter_list|,
name|bool
name|Deref
parameter_list|,
name|int
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Replaces multiple llvm.dbg.value instructions when the alloca it describes
comment|/// is replaced with a new value. If Offset is non-zero, a constant displacement
comment|/// is added to the expression (after the mandatory Deref). Offset can be
comment|/// negative. New llvm.dbg.value instructions are inserted at the locations of
comment|/// the instructions they replace.
name|void
name|replaceDbgValueForAlloca
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
parameter_list|,
name|int
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Assuming the instruction \p I is going to be deleted, attempt to salvage any
comment|/// dbg.value intrinsics referring to \p I by rewriting its effect into a
comment|/// DIExpression.
name|void
name|salvageDebugInfo
parameter_list|(
name|Instruction
modifier|&
name|I
parameter_list|)
function_decl|;
comment|/// Remove all instructions from a basic block other than it's terminator
comment|/// and any present EH pad instructions.
name|unsigned
name|removeAllNonTerminatorAndEHPadInstructions
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// Insert an unreachable instruction before the specified
comment|/// instruction, making it and the rest of the code in the block dead.
name|unsigned
name|changeToUnreachable
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|bool
name|UseLLVMTrap
parameter_list|,
name|bool
name|PreserveLCSSA
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Convert the CallInst to InvokeInst with the specified unwind edge basic
comment|/// block.  This also splits the basic block where CI is located, because
comment|/// InvokeInst is a terminator instruction.  Returns the newly split basic
comment|/// block.
name|BasicBlock
modifier|*
name|changeToInvokeAndSplitBasicBlock
parameter_list|(
name|CallInst
modifier|*
name|CI
parameter_list|,
name|BasicBlock
modifier|*
name|UnwindEdge
parameter_list|)
function_decl|;
comment|/// Replace 'BB's terminator with one that does not have an unwind successor
comment|/// block. Rewrites `invoke` to `call`, etc. Updates any PHIs in unwind
comment|/// successor.
comment|///
comment|/// \param BB  Block whose terminator will be replaced.  Its terminator must
comment|///            have an unwind successor.
name|void
name|removeUnwindEdge
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// Remove all blocks that can not be reached from the function's entry.
comment|///
comment|/// Returns true if any basic block was removed.
name|bool
name|removeUnreachableBlocks
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
name|LazyValueInfo
modifier|*
name|LVI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Combine the metadata of two instructions so that K can replace J
comment|///
comment|/// Metadata not listed as known via KnownIDs is removed
name|void
name|combineMetadata
argument_list|(
name|Instruction
operator|*
name|K
argument_list|,
specifier|const
name|Instruction
operator|*
name|J
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|KnownIDs
argument_list|)
decl_stmt|;
comment|/// Combine the metadata of two instructions so that K can replace J. This
comment|/// specifically handles the case of CSE-like transformations.
comment|///
comment|/// Unknown metadata is removed.
name|void
name|combineMetadataForCSE
parameter_list|(
name|Instruction
modifier|*
name|K
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|J
parameter_list|)
function_decl|;
comment|/// Replace each use of 'From' with 'To' if that use is dominated by
comment|/// the given edge.  Returns the number of replacements made.
name|unsigned
name|replaceDominatedUsesWith
parameter_list|(
name|Value
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|,
name|DominatorTree
modifier|&
name|DT
parameter_list|,
specifier|const
name|BasicBlockEdge
modifier|&
name|Edge
parameter_list|)
function_decl|;
comment|/// Replace each use of 'From' with 'To' if that use is dominated by
comment|/// the end of the given BasicBlock. Returns the number of replacements made.
name|unsigned
name|replaceDominatedUsesWith
parameter_list|(
name|Value
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|,
name|DominatorTree
modifier|&
name|DT
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// Return true if the CallSite CS calls a gc leaf function.
comment|///
comment|/// A leaf function is a function that does not safepoint the thread during its
comment|/// execution.  During a call or invoke to such a function, the callers stack
comment|/// does not have to be made parseable.
comment|///
comment|/// Most passes can and should ignore this information, and it is only used
comment|/// during lowering by the GC infrastructure.
name|bool
name|callsGCLeafFunction
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//  Intrinsic pattern matching
comment|//
comment|/// Try and match a bswap or bitreverse idiom.
comment|///
comment|/// If an idiom is matched, an intrinsic call is inserted before \c I. Any added
comment|/// instructions are returned in \c InsertedInsts. They will all have been added
comment|/// to a basic block.
comment|///
comment|/// A bitreverse idiom normally requires around 2*BW nodes to be searched (where
comment|/// BW is the bitwidth of the integer type). A bswap idiom requires anywhere up
comment|/// to BW / 4 nodes to be searched, so is significantly faster.
comment|///
comment|/// This function returns true on a successful match or false otherwise.
name|bool
name|recognizeBSwapOrBitReverseIdiom
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|bool
name|MatchBSwaps
argument_list|,
name|bool
name|MatchBitReversals
argument_list|,
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|InsertedInsts
argument_list|)
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//  Sanitizer utilities
comment|//
comment|/// Given a CallInst, check if it calls a string function known to CodeGen,
comment|/// and mark it with NoBuiltin if so.  To be used by sanitizers that intend
comment|/// to intercept string functions and want to avoid converting them to target
comment|/// specific instructions.
name|void
name|maybeMarkSanitizerLibraryCallNoBuiltin
parameter_list|(
name|CallInst
modifier|*
name|CI
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
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

