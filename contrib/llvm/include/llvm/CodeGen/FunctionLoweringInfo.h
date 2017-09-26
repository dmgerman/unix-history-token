begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FunctionLoweringInfo.h - Lower functions from LLVM IR to CodeGen ---===//
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
comment|// This implements routines for translating functions from LLVM IR into
end_comment

begin_comment
comment|// Machine IR.
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
name|LLVM_CODEGEN_FUNCTIONLOWERINGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_FUNCTIONLOWERINGINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ISDOpcodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/KnownBits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Argument
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|BranchProbabilityInfo
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MVT
decl_stmt|;
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// FunctionLoweringInfo - This contains information that is global to a
comment|/// function that is used when lowering a region of the function.
comment|///
name|class
name|FunctionLoweringInfo
block|{
name|public
label|:
specifier|const
name|Function
modifier|*
name|Fn
decl_stmt|;
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
specifier|const
name|TargetLowering
modifier|*
name|TLI
decl_stmt|;
name|MachineRegisterInfo
modifier|*
name|RegInfo
decl_stmt|;
name|BranchProbabilityInfo
modifier|*
name|BPI
decl_stmt|;
comment|/// CanLowerReturn - true iff the function's return value can be lowered to
comment|/// registers.
name|bool
name|CanLowerReturn
decl_stmt|;
comment|/// True if part of the CSRs will be handled via explicit copies.
name|bool
name|SplitCSR
decl_stmt|;
comment|/// DemoteRegister - if CanLowerReturn is false, DemoteRegister is a vreg
comment|/// allocated to hold a pointer to the hidden sret parameter.
name|unsigned
name|DemoteRegister
decl_stmt|;
comment|/// MBBMap - A mapping from LLVM basic blocks to their machine code entry.
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
name|MachineBasicBlock
operator|*
operator|>
name|MBBMap
expr_stmt|;
comment|/// A map from swifterror value in a basic block to the virtual register it is
comment|/// currently represented by.
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|,
specifier|const
name|Value
operator|*
operator|>
operator|,
name|unsigned
operator|>
name|SwiftErrorVRegDefMap
expr_stmt|;
comment|/// A list of upward exposed vreg uses that need to be satisfied by either a
comment|/// copy def or a phi node at the beginning of the basic block representing
comment|/// the predecessor(s) swifterror value.
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|,
specifier|const
name|Value
operator|*
operator|>
operator|,
name|unsigned
operator|>
name|SwiftErrorVRegUpwardsUse
expr_stmt|;
comment|/// A map from instructions that define/use a swifterror value to the virtual
comment|/// register that represents that def/use.
name|llvm
operator|::
name|DenseMap
operator|<
name|PointerIntPair
operator|<
specifier|const
name|Instruction
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
operator|,
name|unsigned
operator|>
name|SwiftErrorVRegDefUses
expr_stmt|;
comment|/// The swifterror argument of the current function.
specifier|const
name|Value
modifier|*
name|SwiftErrorArg
decl_stmt|;
name|using
name|SwiftErrorValues
init|=
name|SmallVector
operator|<
specifier|const
name|Value
operator|*
decl_stmt|, 1>;
comment|/// A function can only have a single swifterror argument. And if it does
comment|/// have a swifterror argument, it must be the first entry in
comment|/// SwiftErrorVals.
name|SwiftErrorValues
name|SwiftErrorVals
decl_stmt|;
comment|/// Get or create the swifterror value virtual register in
comment|/// SwiftErrorVRegDefMap for this basic block.
name|unsigned
name|getOrCreateSwiftErrorVReg
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|,
specifier|const
name|Value
modifier|*
parameter_list|)
function_decl|;
comment|/// Set the swifterror virtual register in the SwiftErrorVRegDefMap for this
comment|/// basic block.
name|void
name|setCurrentSwiftErrorVReg
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
specifier|const
name|Value
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
comment|/// Get or create the swifterror value virtual register for a def of a
comment|/// swifterror by an instruction.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|bool
operator|>
name|getOrCreateSwiftErrorVRegDefAt
argument_list|(
specifier|const
name|Instruction
operator|*
argument_list|)
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|bool
operator|>
name|getOrCreateSwiftErrorVRegUseAt
argument_list|(
specifier|const
name|Instruction
operator|*
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
argument_list|,
specifier|const
name|Value
operator|*
argument_list|)
expr_stmt|;
comment|/// ValueMap - Since we emit code for the function a basic block at a time,
comment|/// we must remember which virtual registers hold the values for
comment|/// cross-basic-block values.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|unsigned
operator|>
name|ValueMap
expr_stmt|;
comment|/// Track virtual registers created for exception pointers.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|unsigned
operator|>
name|CatchPadExceptionPointers
expr_stmt|;
comment|/// Keep track of frame indices allocated for statepoints as they could be
comment|/// used across basic block boundaries.  This struct is more complex than a
comment|/// simple map because the stateopint lowering code de-duplicates gc pointers
comment|/// based on their SDValue (so %p and (bitcast %p to T) will get the same
comment|/// slot), and we track that here.
struct|struct
name|StatepointSpillMap
block|{
name|using
name|SlotMapTy
init|=
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
decl_stmt|,
name|Optional
decl|<
name|int
decl|>>
decl_stmt|;
comment|/// Maps uniqued llvm IR values to the slots they were spilled in.  If a
comment|/// value is mapped to None it means we visited the value but didn't spill
comment|/// it (because it was a constant, for instance).
name|SlotMapTy
name|SlotMap
decl_stmt|;
comment|/// Maps llvm IR values to the values they were de-duplicated to.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
specifier|const
name|Value
operator|*
operator|>
name|DuplicateMap
expr_stmt|;
name|SlotMapTy
operator|::
name|const_iterator
name|find
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|{
name|auto
name|DuplIt
operator|=
name|DuplicateMap
operator|.
name|find
argument_list|(
name|V
argument_list|)
block|;
if|if
condition|(
name|DuplIt
operator|!=
name|DuplicateMap
operator|.
name|end
argument_list|()
condition|)
name|V
operator|=
name|DuplIt
operator|->
name|second
expr_stmt|;
return|return
name|SlotMap
operator|.
name|find
argument_list|(
name|V
argument_list|)
return|;
block|}
name|SlotMapTy
decl|::
name|const_iterator
name|end
argument_list|()
decl|const
block|{
return|return
name|SlotMap
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// Maps gc.statepoint instructions to their corresponding StatepointSpillMap
comment|/// instances.
name|DenseMap
operator|<
specifier|const
name|Instruction
operator|*
operator|,
name|StatepointSpillMap
operator|>
name|StatepointSpillMaps
expr_stmt|;
comment|/// StaticAllocaMap - Keep track of frame indices for fixed sized allocas in
comment|/// the entry block.  This allows the allocas to be efficiently referenced
comment|/// anywhere in the function.
name|DenseMap
operator|<
specifier|const
name|AllocaInst
operator|*
operator|,
name|int
operator|>
name|StaticAllocaMap
expr_stmt|;
comment|/// ByValArgFrameIndexMap - Keep track of frame indices for byval arguments.
name|DenseMap
operator|<
specifier|const
name|Argument
operator|*
operator|,
name|int
operator|>
name|ByValArgFrameIndexMap
expr_stmt|;
comment|/// ArgDbgValues - A list of DBG_VALUE instructions created during isel for
comment|/// function arguments that are inserted after scheduling is completed.
name|SmallVector
operator|<
name|MachineInstr
operator|*
operator|,
literal|8
operator|>
name|ArgDbgValues
expr_stmt|;
comment|/// RegFixups - Registers which need to be replaced after isel is done.
name|DenseMap
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|RegFixups
expr_stmt|;
comment|/// StatepointStackSlots - A list of temporary stack slots (frame indices)
comment|/// used to spill values at a statepoint.  We store them here to enable
comment|/// reuse of the same stack slots across different statepoints in different
comment|/// basic blocks.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|50
operator|>
name|StatepointStackSlots
expr_stmt|;
comment|/// MBB - The current block.
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
comment|/// MBB - The current insert position inside the current block.
name|MachineBasicBlock
operator|::
name|iterator
name|InsertPt
expr_stmt|;
struct|struct
name|LiveOutInfo
block|{
name|unsigned
name|NumSignBits
range|:
literal|31
decl_stmt|;
name|unsigned
name|IsValid
range|:
literal|1
decl_stmt|;
name|KnownBits
name|Known
init|=
literal|1
decl_stmt|;
name|LiveOutInfo
argument_list|()
operator|:
name|NumSignBits
argument_list|(
literal|0
argument_list|)
operator|,
name|IsValid
argument_list|(
argument|true
argument_list|)
block|{}
block|}
struct|;
comment|/// Record the preferred extend type (ISD::SIGN_EXTEND or ISD::ZERO_EXTEND)
comment|/// for a value.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|ISD
operator|::
name|NodeType
operator|>
name|PreferredExtendType
expr_stmt|;
comment|/// VisitedBBs - The set of basic blocks visited thus far by instruction
comment|/// selection.
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
literal|4
operator|>
name|VisitedBBs
expr_stmt|;
comment|/// PHINodesToUpdate - A list of phi instructions whose operand list will
comment|/// be updated after processing the current basic block.
comment|/// TODO: This isn't per-function state, it's per-basic-block state. But
comment|/// there's no other convenient place for it to live right now.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
operator|,
name|unsigned
operator|>
expr|>
name|PHINodesToUpdate
expr_stmt|;
name|unsigned
name|OrigNumPHINodesToUpdate
decl_stmt|;
comment|/// If the current MBB is a landing pad, the exception pointer and exception
comment|/// selector registers are copied into these virtual registers by
comment|/// SelectionDAGISel::PrepareEHLandingPad().
name|unsigned
name|ExceptionPointerVirtReg
decl_stmt|,
name|ExceptionSelectorVirtReg
decl_stmt|;
comment|/// set - Initialize this FunctionLoweringInfo with the given Function
comment|/// and its associated MachineFunction.
comment|///
name|void
name|set
parameter_list|(
specifier|const
name|Function
modifier|&
name|Fn
parameter_list|,
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|SelectionDAG
modifier|*
name|DAG
parameter_list|)
function_decl|;
comment|/// clear - Clear out all the function-specific state. This returns this
comment|/// FunctionLoweringInfo to an empty state, ready to be used for a
comment|/// different function.
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// isExportedInst - Return true if the specified value is an instruction
comment|/// exported from its block.
name|bool
name|isExportedInst
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|ValueMap
operator|.
name|count
argument_list|(
name|V
argument_list|)
return|;
block|}
name|unsigned
name|CreateReg
parameter_list|(
name|MVT
name|VT
parameter_list|)
function_decl|;
name|unsigned
name|CreateRegs
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|unsigned
name|InitializeRegForValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
comment|// Tokens never live in vregs.
if|if
condition|(
name|V
operator|->
name|getType
argument_list|()
operator|->
name|isTokenTy
argument_list|()
condition|)
return|return
literal|0
return|;
name|unsigned
modifier|&
name|R
init|=
name|ValueMap
index|[
name|V
index|]
decl_stmt|;
name|assert
argument_list|(
name|R
operator|==
literal|0
operator|&&
literal|"Already initialized this value register!"
argument_list|)
expr_stmt|;
return|return
name|R
operator|=
name|CreateRegs
argument_list|(
name|V
operator|->
name|getType
argument_list|()
argument_list|)
return|;
block|}
comment|/// GetLiveOutRegInfo - Gets LiveOutInfo for a register, returning NULL if the
comment|/// register is a PHI destination and the PHI's LiveOutInfo is not valid.
specifier|const
name|LiveOutInfo
modifier|*
name|GetLiveOutRegInfo
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
if|if
condition|(
operator|!
name|LiveOutRegInfo
operator|.
name|inBounds
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|nullptr
return|;
specifier|const
name|LiveOutInfo
modifier|*
name|LOI
init|=
operator|&
name|LiveOutRegInfo
index|[
name|Reg
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|LOI
operator|->
name|IsValid
condition|)
return|return
name|nullptr
return|;
return|return
name|LOI
return|;
block|}
comment|/// GetLiveOutRegInfo - Gets LiveOutInfo for a register, returning NULL if the
comment|/// register is a PHI destination and the PHI's LiveOutInfo is not valid. If
comment|/// the register's LiveOutInfo is for a smaller bit width, it is extended to
comment|/// the larger bit width by zero extension. The bit width must be no smaller
comment|/// than the LiveOutInfo's existing bit width.
specifier|const
name|LiveOutInfo
modifier|*
name|GetLiveOutRegInfo
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|BitWidth
parameter_list|)
function_decl|;
comment|/// AddLiveOutRegInfo - Adds LiveOutInfo for a register.
name|void
name|AddLiveOutRegInfo
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|NumSignBits
parameter_list|,
specifier|const
name|KnownBits
modifier|&
name|Known
parameter_list|)
block|{
comment|// Only install this information if it tells us something.
if|if
condition|(
name|NumSignBits
operator|==
literal|1
operator|&&
name|Known
operator|.
name|isUnknown
argument_list|()
condition|)
return|return;
name|LiveOutRegInfo
operator|.
name|grow
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
name|LiveOutInfo
modifier|&
name|LOI
init|=
name|LiveOutRegInfo
index|[
name|Reg
index|]
decl_stmt|;
name|LOI
operator|.
name|NumSignBits
operator|=
name|NumSignBits
expr_stmt|;
name|LOI
operator|.
name|Known
operator|.
name|One
operator|=
name|Known
operator|.
name|One
expr_stmt|;
name|LOI
operator|.
name|Known
operator|.
name|Zero
operator|=
name|Known
operator|.
name|Zero
expr_stmt|;
block|}
comment|/// ComputePHILiveOutRegInfo - Compute LiveOutInfo for a PHI's destination
comment|/// register based on the LiveOutInfo of its operands.
name|void
name|ComputePHILiveOutRegInfo
parameter_list|(
specifier|const
name|PHINode
modifier|*
parameter_list|)
function_decl|;
comment|/// InvalidatePHILiveOutRegInfo - Invalidates a PHI's LiveOutInfo, to be
comment|/// called when a block is visited before all of its predecessors.
name|void
name|InvalidatePHILiveOutRegInfo
parameter_list|(
specifier|const
name|PHINode
modifier|*
name|PN
parameter_list|)
block|{
comment|// PHIs with no uses have no ValueMap entry.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|unsigned
operator|>
operator|::
name|const_iterator
name|It
operator|=
name|ValueMap
operator|.
name|find
argument_list|(
name|PN
argument_list|)
expr_stmt|;
if|if
condition|(
name|It
operator|==
name|ValueMap
operator|.
name|end
argument_list|()
condition|)
return|return;
name|unsigned
name|Reg
init|=
name|It
operator|->
name|second
decl_stmt|;
if|if
condition|(
name|Reg
operator|==
literal|0
condition|)
return|return;
name|LiveOutRegInfo
operator|.
name|grow
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
name|LiveOutRegInfo
index|[
name|Reg
index|]
operator|.
name|IsValid
operator|=
name|false
expr_stmt|;
block|}
comment|/// setArgumentFrameIndex - Record frame index for the byval
comment|/// argument.
name|void
name|setArgumentFrameIndex
parameter_list|(
specifier|const
name|Argument
modifier|*
name|A
parameter_list|,
name|int
name|FI
parameter_list|)
function_decl|;
comment|/// getArgumentFrameIndex - Get frame index for the byval argument.
name|int
name|getArgumentFrameIndex
parameter_list|(
specifier|const
name|Argument
modifier|*
name|A
parameter_list|)
function_decl|;
name|unsigned
name|getCatchPadExceptionPointerVReg
parameter_list|(
specifier|const
name|Value
modifier|*
name|CPI
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|addSEHHandlersForLPads
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|LandingPadInst
operator|*
operator|>
name|LPads
argument_list|)
decl_stmt|;
comment|/// LiveOutRegInfo - Information about live out vregs.
name|IndexedMap
operator|<
name|LiveOutInfo
operator|,
name|VirtReg2IndexFunctor
operator|>
name|LiveOutRegInfo
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_FUNCTIONLOWERINGINFO_H
end_comment

end_unit

