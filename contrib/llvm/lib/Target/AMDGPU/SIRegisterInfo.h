begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIRegisterInfo.h - SI Register Info Interface ----------*- C++ -*--===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Interface definition for SIRegisterInfo
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
name|LLVM_LIB_TARGET_AMDGPU_SIREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_SIREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPURegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/AMDGPUMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"SIDefines.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|SISubtarget
decl_stmt|;
name|class
name|SIMachineFunctionInfo
decl_stmt|;
name|class
name|SIRegisterInfo
name|final
range|:
name|public
name|AMDGPURegisterInfo
block|{
name|private
operator|:
name|unsigned
name|SGPRSetID
block|;
name|unsigned
name|VGPRSetID
block|;
name|BitVector
name|SGPRPressureSets
block|;
name|BitVector
name|VGPRPressureSets
block|;
name|bool
name|SpillSGPRToVGPR
block|;
name|bool
name|SpillSGPRToSMEM
block|;
name|void
name|reserveRegisterTuples
argument_list|(
argument|BitVector&
argument_list|,
argument|unsigned Reg
argument_list|)
specifier|const
block|;
name|void
name|classifyPressureSet
argument_list|(
argument|unsigned PSetID
argument_list|,
argument|unsigned Reg
argument_list|,
argument|BitVector&PressureSets
argument_list|)
specifier|const
block|;
name|public
operator|:
name|SIRegisterInfo
argument_list|(
specifier|const
name|SISubtarget
operator|&
name|ST
argument_list|)
block|;
name|bool
name|spillSGPRToVGPR
argument_list|()
specifier|const
block|{
return|return
name|SpillSGPRToVGPR
return|;
block|}
name|bool
name|spillSGPRToSMEM
argument_list|()
specifier|const
block|{
return|return
name|SpillSGPRToSMEM
return|;
block|}
comment|/// Return the end register initially reserved for the scratch buffer in case
comment|/// spilling is needed.
name|unsigned
name|reservedPrivateSegmentBufferReg
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// Return the end register initially reserved for the scratch wave offset in
comment|/// case spilling is needed.
name|unsigned
name|reservedPrivateSegmentWaveByteOffsetReg
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|reservedStackPtrOffsetReg
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCPhysReg
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|uint32_t
operator|*
name|getCallPreservedMask
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|CallingConv::ID
argument_list|)
specifier|const
name|override
block|;
comment|// Stack access is very expensive. CSRs are also the high registers, and we
comment|// want to minimize the number of used registers.
name|unsigned
name|getCSRFirstUseCost
argument_list|()
specifier|const
name|override
block|{
return|return
literal|100
return|;
block|}
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&Fn
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresFrameIndexScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresFrameIndexReplacementScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|bool
name|requiresVirtualBaseRegisters
argument_list|(
argument|const MachineFunction&Fn
argument_list|)
specifier|const
name|override
block|;
name|bool
name|trackLivenessAfterRegAlloc
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|int64_t
name|getMUBUFInstrOffset
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|int64_t
name|getFrameIndexInstrOffset
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int Idx
argument_list|)
specifier|const
name|override
block|;
name|bool
name|needsFrameBaseReg
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|void
name|materializeFrameBaseRegister
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int FrameIdx
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|void
name|resolveFrameIndex
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFrameOffsetLegal
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Kind =
literal|0
argument_list|)
specifier|const
name|override
block|;
comment|/// If \p OnlyToVGPR is true, this will only succeed if this
name|bool
name|spillSGPR
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int FI
argument_list|,
argument|RegScavenger *RS
argument_list|,
argument|bool OnlyToVGPR = false
argument_list|)
specifier|const
block|;
name|bool
name|restoreSGPR
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int FI
argument_list|,
argument|RegScavenger *RS
argument_list|,
argument|bool OnlyToVGPR = false
argument_list|)
specifier|const
block|;
name|void
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int SPAdj
argument_list|,
argument|unsigned FIOperandNum
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
name|override
block|;
name|bool
name|eliminateSGPRToVGPRSpillFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|int FI
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
block|;
name|StringRef
name|getRegAsmName
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getHWRegIndex
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|getEncodingValue
argument_list|(
name|Reg
argument_list|)
operator|&
literal|0xff
return|;
block|}
comment|/// \brief Return the 'base' register class for this register.
comment|/// e.g. SGPR0 => SReg_32, VGPR => VGPR_32 SGPR0_SGPR1 -> SReg_32, etc.
specifier|const
name|TargetRegisterClass
operator|*
name|getPhysRegClass
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|;
comment|/// \returns true if this class contains only SGPR registers
name|bool
name|isSGPRClass
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|{
return|return
operator|!
name|hasVGPRs
argument_list|(
name|RC
argument_list|)
return|;
block|}
comment|/// \returns true if this class ID contains only SGPR registers
name|bool
name|isSGPRClassID
argument_list|(
argument|unsigned RCID
argument_list|)
specifier|const
block|{
return|return
name|isSGPRClass
argument_list|(
name|getRegClass
argument_list|(
name|RCID
argument_list|)
argument_list|)
return|;
block|}
name|bool
name|isSGPRReg
argument_list|(
argument|const MachineRegisterInfo&MRI
argument_list|,
argument|unsigned Reg
argument_list|)
specifier|const
block|{
specifier|const
name|TargetRegisterClass
operator|*
name|RC
block|;
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|Reg
argument_list|)
condition|)
name|RC
operator|=
name|MRI
operator|.
name|getRegClass
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
else|else
name|RC
operator|=
name|getPhysRegClass
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
return|return
name|isSGPRClass
argument_list|(
name|RC
argument_list|)
return|;
block|}
comment|/// \returns true if this class contains VGPR registers.
name|bool
name|hasVGPRs
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns A VGPR reg class with the same width as \p SRC
specifier|const
name|TargetRegisterClass
modifier|*
name|getEquivalentVGPRClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|SRC
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns A SGPR reg class with the same width as \p SRC
specifier|const
name|TargetRegisterClass
modifier|*
name|getEquivalentSGPRClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|VRC
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The register class that is used for a sub-register of \p RC for
comment|/// the given \p SubIdx.  If \p SubIdx equals NoSubRegister, \p RC will
comment|/// be returned.
specifier|const
name|TargetRegisterClass
modifier|*
name|getSubRegClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|unsigned
name|SubIdx
argument_list|)
decl|const
decl_stmt|;
name|bool
name|shouldRewriteCopySrc
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|DefRC
argument_list|,
name|unsigned
name|DefSubReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|SrcRC
argument_list|,
name|unsigned
name|SrcSubReg
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// \returns True if operands defined with this operand type can accept
comment|/// a literal constant (i.e. any 32-bit immediate).
name|bool
name|opCanUseLiteralConstant
argument_list|(
name|unsigned
name|OpType
argument_list|)
decl|const
block|{
comment|// TODO: 64-bit operands have extending behavior from 32-bit literal.
return|return
name|OpType
operator|>=
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_FIRST
operator|&&
name|OpType
operator|<=
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_LAST
return|;
block|}
comment|/// \returns True if operands defined with this operand type can accept
comment|/// an inline constant. i.e. An integer value in the range (-16, 64) or
comment|/// -4.0f, -2.0f, -1.0f, -0.5f, 0.0f, 0.5f, 1.0f, 2.0f, 4.0f.
name|bool
name|opCanUseInlineConstant
argument_list|(
name|unsigned
name|OpType
argument_list|)
decl|const
block|{
return|return
name|OpType
operator|>=
name|AMDGPU
operator|::
name|OPERAND_SRC_FIRST
operator|&&
name|OpType
operator|<=
name|AMDGPU
operator|::
name|OPERAND_SRC_LAST
return|;
block|}
enum|enum
name|PreloadedValue
block|{
comment|// SGPRS:
name|PRIVATE_SEGMENT_BUFFER
init|=
literal|0
block|,
name|DISPATCH_PTR
init|=
literal|1
block|,
name|QUEUE_PTR
init|=
literal|2
block|,
name|KERNARG_SEGMENT_PTR
init|=
literal|3
block|,
name|DISPATCH_ID
init|=
literal|4
block|,
name|FLAT_SCRATCH_INIT
init|=
literal|5
block|,
name|WORKGROUP_ID_X
init|=
literal|10
block|,
name|WORKGROUP_ID_Y
init|=
literal|11
block|,
name|WORKGROUP_ID_Z
init|=
literal|12
block|,
name|PRIVATE_SEGMENT_WAVE_BYTE_OFFSET
init|=
literal|14
block|,
name|IMPLICIT_BUFFER_PTR
init|=
literal|15
block|,
comment|// VGPRS:
name|FIRST_VGPR_VALUE
init|=
literal|16
block|,
name|WORKITEM_ID_X
init|=
name|FIRST_VGPR_VALUE
block|,
name|WORKITEM_ID_Y
init|=
literal|17
block|,
name|WORKITEM_ID_Z
init|=
literal|18
block|}
enum|;
comment|/// \brief Returns the physical register that \p Value is stored in.
name|unsigned
name|getPreloadedValue
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
expr|enum
name|PreloadedValue
name|Value
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|findUnusedRegister
argument_list|(
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getSGPRPressureSet
argument_list|()
specifier|const
block|{
return|return
name|SGPRSetID
return|;
block|}
empty_stmt|;
name|unsigned
name|getVGPRPressureSet
argument_list|()
specifier|const
block|{
return|return
name|VGPRSetID
return|;
block|}
empty_stmt|;
specifier|const
name|TargetRegisterClass
modifier|*
name|getRegClassForReg
argument_list|(
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isVGPR
argument_list|(
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isSGPRPressureSet
argument_list|(
name|unsigned
name|SetID
argument_list|)
decl|const
block|{
return|return
name|SGPRPressureSets
operator|.
name|test
argument_list|(
name|SetID
argument_list|)
operator|&&
operator|!
name|VGPRPressureSets
operator|.
name|test
argument_list|(
name|SetID
argument_list|)
return|;
block|}
name|bool
name|isVGPRPressureSet
argument_list|(
name|unsigned
name|SetID
argument_list|)
decl|const
block|{
return|return
name|VGPRPressureSets
operator|.
name|test
argument_list|(
name|SetID
argument_list|)
operator|&&
operator|!
name|SGPRPressureSets
operator|.
name|test
argument_list|(
name|SetID
argument_list|)
return|;
block|}
name|ArrayRef
operator|<
name|int16_t
operator|>
name|getRegSplitParts
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned EltSize
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|shouldCoalesce
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|SrcRC
argument_list|,
name|unsigned
name|SubReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|DstRC
argument_list|,
name|unsigned
name|DstSubReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|NewRC
argument_list|)
decl|const
name|override
decl_stmt|;
name|unsigned
name|getRegPressureLimit
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
name|override
decl_stmt|;
name|unsigned
name|getRegPressureSetLimit
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|unsigned
name|Idx
argument_list|)
decl|const
name|override
decl_stmt|;
specifier|const
name|int
modifier|*
name|getRegUnitPressureSets
argument_list|(
name|unsigned
name|RegUnit
argument_list|)
decl|const
name|override
decl_stmt|;
name|unsigned
name|getReturnAddressReg
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
comment|// Not a callee saved register.
return|return
name|AMDGPU
operator|::
name|SGPR30_SGPR31
return|;
block|}
name|private
label|:
name|void
name|buildSpillLoadStore
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|unsigned
name|LoadStoreOp
argument_list|,
name|int
name|Index
argument_list|,
name|unsigned
name|ValueReg
argument_list|,
name|bool
name|ValueIsKill
argument_list|,
name|unsigned
name|ScratchRsrcReg
argument_list|,
name|unsigned
name|ScratchOffsetReg
argument_list|,
name|int64_t
name|InstrOffset
argument_list|,
name|MachineMemOperand
operator|*
name|MMO
argument_list|,
name|RegScavenger
operator|*
name|RS
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

