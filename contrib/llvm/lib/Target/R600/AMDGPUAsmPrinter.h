begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUAsmPrinter.h - Print AMDGPU assembly code ---------*- C++ -*-===//
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
comment|/// \brief AMDGPU Assembly printer class.
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
name|LLVM_LIB_TARGET_R600_AMDGPUASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_AMDGPUASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
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
name|AMDGPUAsmPrinter
range|:
name|public
name|AsmPrinter
block|{
name|private
operator|:
expr|struct
name|SIProgramInfo
block|{
name|SIProgramInfo
argument_list|()
operator|:
name|VGPRBlocks
argument_list|(
literal|0
argument_list|)
block|,
name|SGPRBlocks
argument_list|(
literal|0
argument_list|)
block|,
name|Priority
argument_list|(
literal|0
argument_list|)
block|,
name|FloatMode
argument_list|(
literal|0
argument_list|)
block|,
name|Priv
argument_list|(
literal|0
argument_list|)
block|,
name|DX10Clamp
argument_list|(
literal|0
argument_list|)
block|,
name|DebugMode
argument_list|(
literal|0
argument_list|)
block|,
name|IEEEMode
argument_list|(
literal|0
argument_list|)
block|,
name|ScratchSize
argument_list|(
literal|0
argument_list|)
block|,
name|ComputePGMRSrc1
argument_list|(
literal|0
argument_list|)
block|,
name|LDSBlocks
argument_list|(
literal|0
argument_list|)
block|,
name|ScratchBlocks
argument_list|(
literal|0
argument_list|)
block|,
name|ComputePGMRSrc2
argument_list|(
literal|0
argument_list|)
block|,
name|NumVGPR
argument_list|(
literal|0
argument_list|)
block|,
name|NumSGPR
argument_list|(
literal|0
argument_list|)
block|,
name|FlatUsed
argument_list|(
name|false
argument_list|)
block|,
name|VCCUsed
argument_list|(
name|false
argument_list|)
block|,
name|CodeLen
argument_list|(
literal|0
argument_list|)
block|{}
comment|// Fields set in PGM_RSRC1 pm4 packet.
name|uint32_t
name|VGPRBlocks
block|;
name|uint32_t
name|SGPRBlocks
block|;
name|uint32_t
name|Priority
block|;
name|uint32_t
name|FloatMode
block|;
name|uint32_t
name|Priv
block|;
name|uint32_t
name|DX10Clamp
block|;
name|uint32_t
name|DebugMode
block|;
name|uint32_t
name|IEEEMode
block|;
name|uint32_t
name|ScratchSize
block|;
name|uint64_t
name|ComputePGMRSrc1
block|;
comment|// Fields set in PGM_RSRC2 pm4 packet.
name|uint32_t
name|LDSBlocks
block|;
name|uint32_t
name|ScratchBlocks
block|;
name|uint64_t
name|ComputePGMRSrc2
block|;
name|uint32_t
name|NumVGPR
block|;
name|uint32_t
name|NumSGPR
block|;
name|uint32_t
name|LDSSize
block|;
name|bool
name|FlatUsed
block|;
comment|// Bonus information for debugging.
name|bool
name|VCCUsed
block|;
name|uint64_t
name|CodeLen
block|;   }
block|;
name|void
name|getSIProgramInfo
argument_list|(
argument|SIProgramInfo&Out
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|findNumUsedRegistersSI
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned&NumSGPR
argument_list|,
argument|unsigned&NumVGPR
argument_list|)
specifier|const
block|;
comment|/// \brief Emit register usage information so that the GPU driver
comment|/// can correctly setup the GPU state.
name|void
name|EmitProgramInfoR600
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|void
name|EmitProgramInfoSI
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
specifier|const
name|SIProgramInfo
operator|&
name|KernelInfo
argument_list|)
block|;
name|void
name|EmitAmdKernelCodeT
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|const SIProgramInfo&KernelInfo
argument_list|)
specifier|const
block|;
name|public
operator|:
name|explicit
name|AMDGPUAsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"AMDGPU Assembly Printer"
return|;
block|}
comment|/// Implemented in AMDGPUMCInstLower.cpp
name|void
name|EmitInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|;
name|void
name|EmitEndOfAsmFile
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|protected
operator|:
name|bool
name|DisasmEnabled
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|DisasmLines
block|,
name|HexLines
block|;
name|size_t
name|DisasmLineMaxLen
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End anonymous llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

