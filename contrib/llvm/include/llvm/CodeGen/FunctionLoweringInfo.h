begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FunctionLoweringInfo.h - Lower functions from LLVM IR to CodeGen --===//
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
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
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
name|AllocaInst
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|BranchProbabilityInfo
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// FunctionLoweringInfo - This contains information that is global to a
comment|/// function that is used when lowering a region of the function.
comment|///
name|class
name|FunctionLoweringInfo
block|{
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
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
ifndef|#
directive|ifndef
name|NDEBUG
name|SmallPtrSet
operator|<
specifier|const
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|CatchInfoLost
expr_stmt|;
name|SmallPtrSet
operator|<
specifier|const
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|CatchInfoFound
expr_stmt|;
endif|#
directive|endif
struct|struct
name|LiveOutInfo
block|{
name|unsigned
name|NumSignBits
range|:
literal|31
decl_stmt|;
name|bool
name|IsValid
range|:
literal|1
decl_stmt|;
name|APInt
name|KnownOne
decl_stmt|,
name|KnownZero
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
name|true
argument_list|)
operator|,
name|KnownOne
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|,
name|KnownZero
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
block|{}
block|}
struct|;
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
comment|/// If the current MBB is a landing pad, the exception pointer and exception
comment|/// selector registers are copied into these virtual registers by
comment|/// SelectionDAGISel::PrepareEHLandingPad().
name|unsigned
name|ExceptionPointerVirtReg
decl_stmt|,
name|ExceptionSelectorVirtReg
decl_stmt|;
name|explicit
name|FunctionLoweringInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
operator|:
name|TM
argument_list|(
argument|TM
argument_list|)
block|{}
comment|/// set - Initialize this FunctionLoweringInfo with the given Function
comment|/// and its associated MachineFunction.
comment|///
name|void
name|set
argument_list|(
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
expr_stmt|;
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
name|NULL
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
name|NULL
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
name|APInt
modifier|&
name|KnownZero
parameter_list|,
specifier|const
name|APInt
modifier|&
name|KnownOne
parameter_list|)
block|{
comment|// Only install this information if it tells us something.
if|if
condition|(
name|NumSignBits
operator|==
literal|1
operator|&&
name|KnownZero
operator|==
literal|0
operator|&&
name|KnownOne
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
name|KnownOne
operator|=
name|KnownOne
expr_stmt|;
name|LOI
operator|.
name|KnownZero
operator|=
name|KnownZero
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
name|private
label|:
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
empty_stmt|;
comment|/// ComputeUsesVAFloatArgument - Determine if any floating-point values are
comment|/// being passed to this variadic function, and set the MachineModuleInfo's
comment|/// usesVAFloatArgument flag if so. This flag is used to emit an undefined
comment|/// reference to _fltused on Windows, which will link in MSVCRT's
comment|/// floating-point support.
name|void
name|ComputeUsesVAFloatArgument
parameter_list|(
specifier|const
name|CallInst
modifier|&
name|I
parameter_list|,
name|MachineModuleInfo
modifier|*
name|MMI
parameter_list|)
function_decl|;
comment|/// AddCatchInfo - Extract the personality and type infos from an eh.selector
comment|/// call, and add them to the specified machine basic block.
name|void
name|AddCatchInfo
parameter_list|(
specifier|const
name|CallInst
modifier|&
name|I
parameter_list|,
name|MachineModuleInfo
modifier|*
name|MMI
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
comment|/// AddLandingPadInfo - Extract the exception handling information from the
comment|/// landingpad instruction and add them to the specified machine module info.
name|void
name|AddLandingPadInfo
parameter_list|(
specifier|const
name|LandingPadInst
modifier|&
name|I
parameter_list|,
name|MachineModuleInfo
modifier|&
name|MMI
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
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

