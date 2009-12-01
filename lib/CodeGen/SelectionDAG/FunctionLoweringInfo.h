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
name|FUNCTIONLOWERINGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|FUNCTIONLOWERINGINFO_H
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

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
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
name|public
label|:
name|TargetLowering
modifier|&
name|TLI
decl_stmt|;
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
name|explicit
name|FunctionLoweringInfo
parameter_list|(
name|TargetLowering
modifier|&
name|TLI
parameter_list|)
function_decl|;
comment|/// set - Initialize this FunctionLoweringInfo with the given Function
comment|/// and its associated MachineFunction.
comment|///
name|void
name|set
parameter_list|(
name|Function
modifier|&
name|Fn
parameter_list|,
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|bool
name|EnableFastISel
parameter_list|)
function_decl|;
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
ifndef|#
directive|ifndef
name|NDEBUG
name|SmallSet
operator|<
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|CatchInfoLost
expr_stmt|;
name|SmallSet
operator|<
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|CatchInfoFound
expr_stmt|;
endif|#
directive|endif
name|unsigned
name|MakeReg
parameter_list|(
name|EVT
name|VT
parameter_list|)
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
name|CreateRegForValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
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
name|CreateRegForValue
argument_list|(
name|V
argument_list|)
return|;
block|}
struct|struct
name|LiveOutInfo
block|{
name|unsigned
name|NumSignBits
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
comment|/// LiveOutRegInfo - Information about live out vregs, indexed by their
comment|/// register number offset by 'FirstVirtualRegister'.
name|std
operator|::
name|vector
operator|<
name|LiveOutInfo
operator|>
name|LiveOutRegInfo
expr_stmt|;
comment|/// clear - Clear out all the function-specific state. This returns this
comment|/// FunctionLoweringInfo to an empty state, ready to be used for a
comment|/// different function.
name|void
name|clear
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// ComputeLinearIndex - Given an LLVM IR aggregate type and a sequence
comment|/// of insertvalue or extractvalue indices that identify a member, return
comment|/// the linearized index of the start of the member.
comment|///
name|unsigned
name|ComputeLinearIndex
parameter_list|(
specifier|const
name|TargetLowering
modifier|&
name|TLI
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|Indices
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|IndicesEnd
parameter_list|,
name|unsigned
name|CurIndex
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// ComputeValueVTs - Given an LLVM IR type, compute a sequence of
comment|/// EVTs that represent all the individual underlying
comment|/// non-aggregate types that comprise it.
comment|///
comment|/// If Offsets is non-null, it points to a vector to be filled in
comment|/// with the in-memory offsets of each of the individual values.
comment|///
name|void
name|ComputeValueVTs
argument_list|(
specifier|const
name|TargetLowering
operator|&
name|TLI
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|SmallVectorImpl
operator|<
name|EVT
operator|>
operator|&
name|ValueVTs
argument_list|,
name|SmallVectorImpl
operator|<
name|uint64_t
operator|>
operator|*
name|Offsets
operator|=
literal|0
argument_list|,
name|uint64_t
name|StartingOffset
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// ExtractTypeInfo - Returns the type info, possibly bitcast, encoded in V.
name|GlobalVariable
modifier|*
name|ExtractTypeInfo
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// AddCatchInfo - Extract the personality and type infos from an eh.selector
comment|/// call, and add them to the specified machine basic block.
name|void
name|AddCatchInfo
parameter_list|(
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
comment|/// CopyCatchInfo - Copy catch information from DestBB to SrcBB.
name|void
name|CopyCatchInfo
parameter_list|(
name|BasicBlock
modifier|*
name|SrcBB
parameter_list|,
name|BasicBlock
modifier|*
name|DestBB
parameter_list|,
name|MachineModuleInfo
modifier|*
name|MMI
parameter_list|,
name|FunctionLoweringInfo
modifier|&
name|FLI
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

