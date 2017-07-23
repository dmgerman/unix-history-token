begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AMDGPUInstructionSelector --------------------------------*- C++ -*-==//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file declares the targeting of the InstructionSelector class for
end_comment

begin_comment
comment|/// AMDGPU.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUINSTRUCTIONSELECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUINSTRUCTIONSELECTOR_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/InstructionSelector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUInstrInfo
decl_stmt|;
name|class
name|AMDGPURegisterBankInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|SIInstrInfo
decl_stmt|;
name|class
name|SIRegisterInfo
decl_stmt|;
name|class
name|SISubtarget
decl_stmt|;
name|class
name|AMDGPUInstructionSelector
range|:
name|public
name|InstructionSelector
block|{
name|public
operator|:
name|AMDGPUInstructionSelector
argument_list|(
specifier|const
name|SISubtarget
operator|&
name|STI
argument_list|,
specifier|const
name|AMDGPURegisterBankInfo
operator|&
name|RBI
argument_list|)
block|;
name|bool
name|select
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
expr|struct
name|GEPInfo
block|{
specifier|const
name|MachineInstr
operator|&
name|GEP
block|;
name|SmallVector
operator|<
name|unsigned
block|,
literal|2
operator|>
name|SgprParts
block|;
name|SmallVector
operator|<
name|unsigned
block|,
literal|2
operator|>
name|VgprParts
block|;
name|int64_t
name|Imm
block|;
name|GEPInfo
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|GEP
argument_list|)
operator|:
name|GEP
argument_list|(
name|GEP
argument_list|)
block|,
name|Imm
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
block|;
name|MachineOperand
name|getSubOperand64
argument_list|(
argument|MachineOperand&MO
argument_list|,
argument|unsigned SubIdx
argument_list|)
specifier|const
block|;
name|bool
name|selectG_CONSTANT
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
block|;
name|bool
name|selectG_ADD
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
block|;
name|bool
name|selectG_GEP
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
block|;
name|bool
name|hasVgprParts
argument_list|(
argument|ArrayRef<GEPInfo> AddrInfo
argument_list|)
specifier|const
block|;
name|void
name|getAddrModeInfo
argument_list|(
argument|const MachineInstr&Load
argument_list|,
argument|const MachineRegisterInfo&MRI
argument_list|,
argument|SmallVectorImpl<GEPInfo>&AddrInfo
argument_list|)
specifier|const
block|;
name|bool
name|selectSMRD
argument_list|(
argument|MachineInstr&I
argument_list|,
argument|ArrayRef<GEPInfo> AddrInfo
argument_list|)
specifier|const
block|;
name|bool
name|selectG_LOAD
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
block|;
name|bool
name|selectG_STORE
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
block|;
specifier|const
name|SIInstrInfo
operator|&
name|TII
block|;
specifier|const
name|SIRegisterInfo
operator|&
name|TRI
block|;
specifier|const
name|AMDGPURegisterBankInfo
operator|&
name|RBI
block|;
name|protected
operator|:
name|AMDGPUAS
name|AMDGPUASI
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

