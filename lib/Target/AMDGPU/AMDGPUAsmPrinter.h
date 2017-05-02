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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"AMDKernelCodeT.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|AMDGPUTargetStreamer
decl_stmt|;
name|class
name|MCOperand
decl_stmt|;
name|class
name|SISubtarget
decl_stmt|;
name|class
name|AMDGPUAsmPrinter
name|final
range|:
name|public
name|AsmPrinter
block|{
name|private
operator|:
comment|// Track resource usage for callee functions.
expr|struct
name|SIFunctionResourceInfo
block|{
comment|// Track the number of explicitly used VGPRs. Special registers reserved at
comment|// the end are tracked separately.
name|int32_t
name|NumVGPR
operator|=
literal|0
block|;
name|int32_t
name|NumExplicitSGPR
operator|=
literal|0
block|;
name|uint32_t
name|PrivateSegmentSize
operator|=
literal|0
block|;
name|bool
name|UsesVCC
operator|=
name|false
block|;
name|bool
name|UsesFlatScratch
operator|=
name|false
block|;
name|bool
name|HasDynamicallySizedStack
operator|=
name|false
block|;
name|bool
name|HasRecursion
operator|=
name|false
block|;
name|int32_t
name|getTotalNumSGPRs
argument_list|(
argument|const SISubtarget&ST
argument_list|)
specifier|const
block|;   }
block|;
comment|// Track resource usage for kernels / entry functions.
block|struct
name|SIProgramInfo
block|{
comment|// Fields set in PGM_RSRC1 pm4 packet.
name|uint32_t
name|VGPRBlocks
operator|=
literal|0
block|;
name|uint32_t
name|SGPRBlocks
operator|=
literal|0
block|;
name|uint32_t
name|Priority
operator|=
literal|0
block|;
name|uint32_t
name|FloatMode
operator|=
literal|0
block|;
name|uint32_t
name|Priv
operator|=
literal|0
block|;
name|uint32_t
name|DX10Clamp
operator|=
literal|0
block|;
name|uint32_t
name|DebugMode
operator|=
literal|0
block|;
name|uint32_t
name|IEEEMode
operator|=
literal|0
block|;
name|uint32_t
name|ScratchSize
operator|=
literal|0
block|;
name|uint64_t
name|ComputePGMRSrc1
operator|=
literal|0
block|;
comment|// Fields set in PGM_RSRC2 pm4 packet.
name|uint32_t
name|LDSBlocks
operator|=
literal|0
block|;
name|uint32_t
name|ScratchBlocks
operator|=
literal|0
block|;
name|uint64_t
name|ComputePGMRSrc2
operator|=
literal|0
block|;
name|uint32_t
name|NumVGPR
operator|=
literal|0
block|;
name|uint32_t
name|NumSGPR
operator|=
literal|0
block|;
name|uint32_t
name|LDSSize
operator|=
literal|0
block|;
name|bool
name|FlatUsed
operator|=
name|false
block|;
comment|// Number of SGPRs that meets number of waves per execution unit request.
name|uint32_t
name|NumSGPRsForWavesPerEU
operator|=
literal|0
block|;
comment|// Number of VGPRs that meets number of waves per execution unit request.
name|uint32_t
name|NumVGPRsForWavesPerEU
operator|=
literal|0
block|;
comment|// If ReservedVGPRCount is 0 then must be 0. Otherwise, this is the first
comment|// fixed VGPR number reserved.
name|uint16_t
name|ReservedVGPRFirst
operator|=
literal|0
block|;
comment|// The number of consecutive VGPRs reserved.
name|uint16_t
name|ReservedVGPRCount
operator|=
literal|0
block|;
comment|// Fixed SGPR number used to hold wave scratch offset for entire kernel
comment|// execution, or std::numeric_limits<uint16_t>::max() if the register is not
comment|// used or not known.
name|uint16_t
name|DebuggerWavefrontPrivateSegmentOffsetSGPR
operator|=
name|std
operator|::
name|numeric_limits
operator|<
name|uint16_t
operator|>
operator|::
name|max
argument_list|()
block|;
comment|// Fixed SGPR number of the first 4 SGPRs used to hold scratch V# for entire
comment|// kernel execution, or std::numeric_limits<uint16_t>::max() if the register
comment|// is not used or not known.
name|uint16_t
name|DebuggerPrivateSegmentBufferSGPR
operator|=
name|std
operator|::
name|numeric_limits
operator|<
name|uint16_t
operator|>
operator|::
name|max
argument_list|()
block|;
comment|// Whether there is recursion, dynamic allocas, indirect calls or some other
comment|// reason there may be statically unknown stack usage.
name|bool
name|DynamicCallStack
operator|=
name|false
block|;
comment|// Bonus information for debugging.
name|bool
name|VCCUsed
operator|=
name|false
block|;
name|SIProgramInfo
argument_list|()
operator|=
expr|default
block|;   }
block|;
name|SIProgramInfo
name|CurrentProgramInfo
block|;
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
block|,
name|SIFunctionResourceInfo
operator|>
name|CallGraphResourceInfo
block|;
name|uint64_t
name|getFunctionCodeSize
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|SIFunctionResourceInfo
name|analyzeResourceUsage
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|getSIProgramInfo
argument_list|(
name|SIProgramInfo
operator|&
name|Out
argument_list|,
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|void
name|getAmdKernelCode
argument_list|(
argument|amd_kernel_code_t&Out
argument_list|,
argument|const SIProgramInfo&KernelInfo
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
name|emitCommonFunctionComments
argument_list|(
argument|uint32_t NumVGPR
argument_list|,
argument|uint32_t NumSGPR
argument_list|,
argument|uint32_t ScratchSize
argument_list|,
argument|uint64_t CodeSize
argument_list|)
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
name|std
operator|::
name|unique_ptr
operator|<
name|MCStreamer
operator|>
name|Streamer
argument_list|)
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|MCSubtargetInfo
operator|*
name|getSTI
argument_list|()
specifier|const
block|;
name|AMDGPUTargetStreamer
operator|&
name|getTargetStreamer
argument_list|()
specifier|const
block|;
name|bool
name|doFinalization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
comment|/// \brief Wrapper for MCInstLowering.lowerOperand() for the tblgen'erated
comment|/// pseudo lowering.
name|bool
name|lowerOperand
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|MCOperand&MCOp
argument_list|)
specifier|const
block|;
comment|/// \brief Lower the specified LLVM Constant to an MCExpr.
comment|/// The AsmPrinter::lowerConstantof does not know how to lower
comment|/// addrspacecast, therefore they should be lowered by this function.
specifier|const
name|MCExpr
operator|*
name|lowerConstant
argument_list|(
argument|const Constant *CV
argument_list|)
name|override
block|;
comment|/// \brief tblgen'erated driver function for lowering simple MI->MC pseudo
comment|/// instructions.
name|bool
name|emitPseudoExpansionLowering
argument_list|(
name|MCStreamer
operator|&
name|OutStreamer
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
comment|/// Implemented in AMDGPUMCInstLower.cpp
name|void
name|EmitInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|;
name|void
name|EmitFunctionBodyStart
argument_list|()
name|override
block|;
name|void
name|EmitFunctionEntryLabel
argument_list|()
name|override
block|;
name|void
name|EmitGlobalVariable
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
name|override
block|;
name|void
name|EmitStartOfAsmFile
argument_list|(
argument|Module&M
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
name|bool
name|isBlockOnlyReachableByFallthrough
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
name|override
block|;
name|bool
name|PrintAsmOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&O
argument_list|)
name|override
block|;
name|protected
operator|:
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
block|;
name|AMDGPUAS
name|AMDGPUASI
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_AMDGPUASMPRINTER_H
end_comment

end_unit

