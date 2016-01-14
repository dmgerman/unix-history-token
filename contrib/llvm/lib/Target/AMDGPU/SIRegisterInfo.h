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
name|LLVM_LIB_TARGET_R600_SIREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_SIREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPURegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|struct
name|SIRegisterInfo
range|:
name|public
name|AMDGPURegisterInfo
block|{
name|private
operator|:
name|unsigned
name|SGPR32SetID
block|;
name|unsigned
name|VGPR32SetID
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
name|public
operator|:
name|SIRegisterInfo
argument_list|()
block|;
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
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRegPressureSetLimit
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned Idx
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
name|unsigned
name|getHWRegIndex
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
name|override
block|;
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
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
name|isSGPRClass
argument_list|(
name|MRI
operator|.
name|getRegClass
argument_list|(
name|Reg
argument_list|)
argument_list|)
return|;
return|return
name|getPhysRegClass
argument_list|(
name|Reg
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
comment|/// returns true if this is a pseudoregister class combination of VGPRs and
comment|/// SGPRs for operand modeling. FIXME: We should set isAllocatable = 0 on
comment|/// them.
specifier|static
name|bool
name|isPseudoRegClass
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
block|{
return|return
name|RC
operator|==
operator|&
name|AMDGPU
operator|::
name|VS_32RegClass
operator|||
name|RC
operator|==
operator|&
name|AMDGPU
operator|::
name|VS_64RegClass
return|;
block|}
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
comment|/// \p Channel This is the register channel (e.g. a value from 0-16), not the
comment|///            SubReg index.
comment|/// \returns The sub-register of Reg that is in Channel.
name|unsigned
name|getPhysRegSubReg
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|SubRC
argument_list|,
name|unsigned
name|Channel
argument_list|)
decl|const
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
decl_stmt|;
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
decl_stmt|;
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
comment|// VGPRS:
name|FIRST_VGPR_VALUE
init|=
literal|15
block|,
name|WORKITEM_ID_X
init|=
name|FIRST_VGPR_VALUE
block|,
name|WORKITEM_ID_Y
init|=
literal|16
block|,
name|WORKITEM_ID_Z
init|=
literal|17
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
comment|/// \brief Give the maximum number of VGPRs that can be used by \p WaveCount
comment|///        concurrent waves.
name|unsigned
name|getNumVGPRsAllowed
argument_list|(
name|unsigned
name|WaveCount
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Give the maximum number of SGPRs that can be used by \p WaveCount
comment|///        concurrent waves.
name|unsigned
name|getNumSGPRsAllowed
argument_list|(
name|AMDGPUSubtarget
operator|::
name|Generation
name|gen
argument_list|,
name|unsigned
name|WaveCount
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
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getSGPR32PressureSet
argument_list|()
specifier|const
block|{
return|return
name|SGPR32SetID
return|;
block|}
empty_stmt|;
name|unsigned
name|getVGPR32PressureSet
argument_list|()
specifier|const
block|{
return|return
name|VGPR32SetID
return|;
block|}
empty_stmt|;
name|private
label|:
name|void
name|buildScratchLoadStore
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|unsigned
name|LoadStoreOp
argument_list|,
name|unsigned
name|Value
argument_list|,
name|unsigned
name|ScratchRsrcReg
argument_list|,
name|unsigned
name|ScratchOffset
argument_list|,
name|int64_t
name|Offset
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

