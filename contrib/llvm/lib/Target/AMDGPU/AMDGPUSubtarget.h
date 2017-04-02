begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- AMDGPUSubtarget.h - Define Subtarget for AMDGPU ------*- C++ -*-====//
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
comment|//==-----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief AMDGPU specific subclass of TargetSubtarget.
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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"R600InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"R600ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"R600FrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"SIInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SIISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SIFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"Utils/AMDGPUBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/GISelAccessor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGTargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|AMDGPUSubtarget
range|:
name|public
name|AMDGPUGenSubtargetInfo
block|{
name|public
operator|:
expr|enum
name|Generation
block|{
name|R600
operator|=
literal|0
block|,
name|R700
block|,
name|EVERGREEN
block|,
name|NORTHERN_ISLANDS
block|,
name|SOUTHERN_ISLANDS
block|,
name|SEA_ISLANDS
block|,
name|VOLCANIC_ISLANDS
block|,   }
block|;    enum
block|{
name|ISAVersion0_0_0
block|,
name|ISAVersion7_0_0
block|,
name|ISAVersion7_0_1
block|,
name|ISAVersion7_0_2
block|,
name|ISAVersion8_0_0
block|,
name|ISAVersion8_0_1
block|,
name|ISAVersion8_0_2
block|,
name|ISAVersion8_0_3
block|,
name|ISAVersion8_0_4
block|,
name|ISAVersion8_1_0
block|,   }
block|;
name|protected
operator|:
comment|// Basic subtarget description.
name|Triple
name|TargetTriple
block|;
name|Generation
name|Gen
block|;
name|unsigned
name|IsaVersion
block|;
name|unsigned
name|WavefrontSize
block|;
name|int
name|LocalMemorySize
block|;
name|int
name|LDSBankCount
block|;
name|unsigned
name|MaxPrivateElementSize
block|;
comment|// Possibly statically set by tablegen, but may want to be overridden.
name|bool
name|FastFMAF32
block|;
name|bool
name|HalfRate64Ops
block|;
comment|// Dynamially set bits that enable features.
name|bool
name|FP16Denormals
block|;
name|bool
name|FP32Denormals
block|;
name|bool
name|FP64Denormals
block|;
name|bool
name|FPExceptions
block|;
name|bool
name|FlatForGlobal
block|;
name|bool
name|UnalignedScratchAccess
block|;
name|bool
name|UnalignedBufferAccess
block|;
name|bool
name|EnableXNACK
block|;
name|bool
name|DebuggerInsertNops
block|;
name|bool
name|DebuggerReserveRegs
block|;
name|bool
name|DebuggerEmitPrologue
block|;
comment|// Used as options.
name|bool
name|EnableVGPRSpilling
block|;
name|bool
name|EnablePromoteAlloca
block|;
name|bool
name|EnableLoadStoreOpt
block|;
name|bool
name|EnableUnsafeDSOffsetFolding
block|;
name|bool
name|EnableSIScheduler
block|;
name|bool
name|DumpCode
block|;
comment|// Subtarget statically properties set by tablegen
name|bool
name|FP64
block|;
name|bool
name|IsGCN
block|;
name|bool
name|GCN1Encoding
block|;
name|bool
name|GCN3Encoding
block|;
name|bool
name|CIInsts
block|;
name|bool
name|SGPRInitBug
block|;
name|bool
name|HasSMemRealTime
block|;
name|bool
name|Has16BitInsts
block|;
name|bool
name|HasMovrel
block|;
name|bool
name|HasVGPRIndexMode
block|;
name|bool
name|HasScalarStores
block|;
name|bool
name|HasInv2PiInlineImm
block|;
name|bool
name|FlatAddressSpace
block|;
name|bool
name|R600ALUInst
block|;
name|bool
name|CaymanISA
block|;
name|bool
name|CFALUBug
block|;
name|bool
name|HasVertexCache
block|;
name|short
name|TexVTXClauseSize
block|;
name|bool
name|ScalarizeGlobal
block|;
comment|// Dummy feature to use for assembler in tablegen.
name|bool
name|FeatureDisable
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|SelectionDAGTargetInfo
name|TSInfo
block|;
name|public
operator|:
name|AMDGPUSubtarget
argument_list|(
argument|const Triple&TT
argument_list|,
argument|StringRef GPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetMachine&TM
argument_list|)
block|;
operator|~
name|AMDGPUSubtarget
argument_list|()
name|override
block|;
name|AMDGPUSubtarget
operator|&
name|initializeSubtargetDependencies
argument_list|(
argument|const Triple&TT
argument_list|,
argument|StringRef GPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
specifier|const
name|AMDGPUInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
operator|=
literal|0
block|;
specifier|const
name|AMDGPUFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
operator|=
literal|0
block|;
specifier|const
name|AMDGPUTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
operator|=
literal|0
block|;
specifier|const
name|AMDGPURegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
operator|=
literal|0
block|;
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrItins
return|;
block|}
comment|// Nothing implemented, just prevent crashes on use.
specifier|const
name|SelectionDAGTargetInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|bool
name|isAmdHsaOS
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|AMDHSA
return|;
block|}
name|bool
name|isMesa3DOS
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Mesa3D
return|;
block|}
name|bool
name|isOpenCLEnv
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|OpenCL
return|;
block|}
name|Generation
name|getGeneration
argument_list|()
specifier|const
block|{
return|return
name|Gen
return|;
block|}
name|unsigned
name|getWavefrontSize
argument_list|()
specifier|const
block|{
return|return
name|WavefrontSize
return|;
block|}
name|int
name|getLocalMemorySize
argument_list|()
specifier|const
block|{
return|return
name|LocalMemorySize
return|;
block|}
name|int
name|getLDSBankCount
argument_list|()
specifier|const
block|{
return|return
name|LDSBankCount
return|;
block|}
name|unsigned
name|getMaxPrivateElementSize
argument_list|()
specifier|const
block|{
return|return
name|MaxPrivateElementSize
return|;
block|}
name|bool
name|has16BitInsts
argument_list|()
specifier|const
block|{
return|return
name|Has16BitInsts
return|;
block|}
name|bool
name|hasHWFP64
argument_list|()
specifier|const
block|{
return|return
name|FP64
return|;
block|}
name|bool
name|hasFastFMAF32
argument_list|()
specifier|const
block|{
return|return
name|FastFMAF32
return|;
block|}
name|bool
name|hasHalfRate64Ops
argument_list|()
specifier|const
block|{
return|return
name|HalfRate64Ops
return|;
block|}
name|bool
name|hasAddr64
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|<
name|VOLCANIC_ISLANDS
operator|)
return|;
block|}
name|bool
name|hasBFE
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
block|}
name|bool
name|hasBFI
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
block|}
name|bool
name|hasBFM
argument_list|()
specifier|const
block|{
return|return
name|hasBFE
argument_list|()
return|;
block|}
name|bool
name|hasBCNT
argument_list|(
argument|unsigned Size
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Size
operator|==
literal|32
condition|)
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
if|if
condition|(
name|Size
operator|==
literal|64
condition|)
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|SOUTHERN_ISLANDS
operator|)
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|hasMulU24
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasMulI24
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|SOUTHERN_ISLANDS
operator|||
name|hasCaymanISA
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasFFBL
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasFFBH
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasCARRY
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasBORROW
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getGeneration
argument_list|()
operator|>=
name|EVERGREEN
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasCaymanISA
argument_list|()
specifier|const
block|{
return|return
name|CaymanISA
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isPromoteAllocaEnabled
argument_list|()
specifier|const
block|{
return|return
name|EnablePromoteAlloca
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|unsafeDSOffsetFoldingEnabled
argument_list|()
specifier|const
block|{
return|return
name|EnableUnsafeDSOffsetFolding
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|dumpCode
argument_list|()
specifier|const
block|{
return|return
name|DumpCode
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|enableIEEEBit
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|AMDGPU
operator|::
name|isCompute
argument_list|(
name|MF
operator|.
name|getFunction
argument_list|()
operator|->
name|getCallingConv
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the amount of LDS that can be used that will not restrict the
end_comment

begin_comment
comment|/// occupancy lower than WaveCount.
end_comment

begin_decl_stmt
name|unsigned
name|getMaxLocalMemSizeWithWaveCount
argument_list|(
name|unsigned
name|WaveCount
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Inverse of getMaxLocalMemWithWaveCount. Return the maximum wavecount if
end_comment

begin_comment
comment|/// the given LDS memory size is the only constraint.
end_comment

begin_decl_stmt
name|unsigned
name|getOccupancyWithLocalMemSize
argument_list|(
name|uint32_t
name|Bytes
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|hasFP16Denormals
argument_list|()
specifier|const
block|{
return|return
name|FP16Denormals
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasFP32Denormals
argument_list|()
specifier|const
block|{
return|return
name|FP32Denormals
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasFP64Denormals
argument_list|()
specifier|const
block|{
return|return
name|FP64Denormals
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasFPExceptions
argument_list|()
specifier|const
block|{
return|return
name|FPExceptions
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|useFlatForGlobal
argument_list|()
specifier|const
block|{
return|return
name|FlatForGlobal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasUnalignedBufferAccess
argument_list|()
specifier|const
block|{
return|return
name|UnalignedBufferAccess
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasUnalignedScratchAccess
argument_list|()
specifier|const
block|{
return|return
name|UnalignedScratchAccess
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isXNACKEnabled
argument_list|()
specifier|const
block|{
return|return
name|EnableXNACK
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|isMesaKernel
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|isMesa3DOS
argument_list|()
operator|&&
operator|!
name|AMDGPU
operator|::
name|isShader
argument_list|(
name|MF
operator|.
name|getFunction
argument_list|()
operator|->
name|getCallingConv
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Covers VS/PS/CS graphics shaders
end_comment

begin_decl_stmt
name|bool
name|isMesaGfxShader
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|isMesa3DOS
argument_list|()
operator|&&
name|AMDGPU
operator|::
name|isShader
argument_list|(
name|MF
operator|.
name|getFunction
argument_list|()
operator|->
name|getCallingConv
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|isAmdCodeObjectV2
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|isAmdHsaOS
argument_list|()
operator|||
name|isMesaKernel
argument_list|(
name|MF
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns the offset in bytes from the start of the input buffer
end_comment

begin_comment
comment|///        of the first explicit kernel argument.
end_comment

begin_decl_stmt
name|unsigned
name|getExplicitKernelArgOffset
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
return|return
name|isAmdCodeObjectV2
argument_list|(
name|MF
argument_list|)
condition|?
literal|0
else|:
literal|36
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getAlignmentForImplicitArgPtr
argument_list|()
specifier|const
block|{
return|return
name|isAmdHsaOS
argument_list|()
operator|?
literal|8
operator|:
literal|4
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|unsigned
name|getImplicitArgNumBytes
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
block|{
if|if
condition|(
name|isMesaKernel
argument_list|(
name|MF
argument_list|)
condition|)
return|return
literal|16
return|;
if|if
condition|(
name|isAmdHsaOS
argument_list|()
operator|&&
name|isOpenCLEnv
argument_list|()
condition|)
return|return
literal|32
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
block|{
comment|// Scratch is allocated in 256 dword per wave blocks.
return|return
literal|4
operator|*
literal|256
operator|/
name|getWavefrontSize
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|enableSubRegLiveness
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Number of execution units per compute unit supported by the
end_comment

begin_comment
comment|/// subtarget.
end_comment

begin_expr_stmt
name|unsigned
name|getEUsPerCU
argument_list|()
specifier|const
block|{
return|return
literal|4
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Maximum number of work groups per compute unit supported by the
end_comment

begin_comment
comment|/// subtarget and limited by given flat work group size.
end_comment

begin_decl_stmt
name|unsigned
name|getMaxWorkGroupsPerCU
argument_list|(
name|unsigned
name|FlatWorkGroupSize
argument_list|)
decl|const
block|{
if|if
condition|(
name|getGeneration
argument_list|()
operator|<
name|AMDGPUSubtarget
operator|::
name|SOUTHERN_ISLANDS
condition|)
return|return
literal|8
return|;
return|return
name|getWavesPerWorkGroup
argument_list|(
name|FlatWorkGroupSize
argument_list|)
operator|==
literal|1
condition|?
literal|40
else|:
literal|16
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \returns Maximum number of waves per compute unit supported by the
end_comment

begin_comment
comment|/// subtarget without any kind of limitation.
end_comment

begin_expr_stmt
name|unsigned
name|getMaxWavesPerCU
argument_list|()
specifier|const
block|{
return|return
name|getMaxWavesPerEU
argument_list|()
operator|*
name|getEUsPerCU
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Maximum number of waves per compute unit supported by the
end_comment

begin_comment
comment|/// subtarget and limited by given flat work group size.
end_comment

begin_decl_stmt
name|unsigned
name|getMaxWavesPerCU
argument_list|(
name|unsigned
name|FlatWorkGroupSize
argument_list|)
decl|const
block|{
return|return
name|getWavesPerWorkGroup
argument_list|(
name|FlatWorkGroupSize
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \returns Minimum number of waves per execution unit supported by the
end_comment

begin_comment
comment|/// subtarget.
end_comment

begin_expr_stmt
name|unsigned
name|getMinWavesPerEU
argument_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Maximum number of waves per execution unit supported by the
end_comment

begin_comment
comment|/// subtarget without any kind of limitation.
end_comment

begin_expr_stmt
name|unsigned
name|getMaxWavesPerEU
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getGeneration
argument_list|()
operator|<
name|AMDGPUSubtarget
operator|::
name|SOUTHERN_ISLANDS
condition|)
return|return
literal|8
return|;
end_expr_stmt

begin_comment
comment|// FIXME: Need to take scratch memory into account.
end_comment

begin_return
return|return
literal|10
return|;
end_return

begin_comment
unit|}
comment|/// \returns Maximum number of waves per execution unit supported by the
end_comment

begin_comment
comment|/// subtarget and limited by given flat work group size.
end_comment

begin_macro
unit|unsigned
name|getMaxWavesPerEU
argument_list|(
argument|unsigned FlatWorkGroupSize
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|alignTo
argument_list|(
name|getMaxWavesPerCU
argument_list|(
name|FlatWorkGroupSize
argument_list|)
argument_list|,
name|getEUsPerCU
argument_list|()
argument_list|)
operator|/
name|getEUsPerCU
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Minimum flat work group size supported by the subtarget.
end_comment

begin_expr_stmt
name|unsigned
name|getMinFlatWorkGroupSize
argument_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Maximum flat work group size supported by the subtarget.
end_comment

begin_expr_stmt
name|unsigned
name|getMaxFlatWorkGroupSize
argument_list|()
specifier|const
block|{
return|return
literal|2048
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Number of waves per work group given the flat work group size.
end_comment

begin_decl_stmt
name|unsigned
name|getWavesPerWorkGroup
argument_list|(
name|unsigned
name|FlatWorkGroupSize
argument_list|)
decl|const
block|{
return|return
name|alignTo
argument_list|(
name|FlatWorkGroupSize
argument_list|,
name|getWavefrontSize
argument_list|()
argument_list|)
operator|/
name|getWavefrontSize
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setScalarizeGlobalBehavior
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|ScalarizeGlobal
operator|=
name|b
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getScalarizeGlobalBehavior
argument_list|()
specifier|const
block|{
return|return
name|ScalarizeGlobal
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \returns Subtarget's default pair of minimum/maximum flat work group sizes
end_comment

begin_comment
comment|/// for function \p F, or minimum/maximum flat work group sizes explicitly
end_comment

begin_comment
comment|/// requested using "amdgpu-flat-work-group-size" attribute attached to
end_comment

begin_comment
comment|/// function \p F.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns Subtarget's default values if explicitly requested values cannot
end_comment

begin_comment
comment|/// be converted to integer, or violate subtarget's specifications.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|getFlatWorkGroupSizes
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \returns Subtarget's default pair of minimum/maximum number of waves per
end_comment

begin_comment
comment|/// execution unit for function \p F, or minimum/maximum number of waves per
end_comment

begin_comment
comment|/// execution unit explicitly requested using "amdgpu-waves-per-eu" attribute
end_comment

begin_comment
comment|/// attached to function \p F.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns Subtarget's default values if explicitly requested values cannot
end_comment

begin_comment
comment|/// be converted to integer, violate subtarget's specifications, or are not
end_comment

begin_comment
comment|/// compatible with minimum/maximum number of waves limited by flat work group
end_comment

begin_comment
comment|/// size, register usage, and/or lds usage.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|getWavesPerEU
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|R600Subtarget
name|final
range|:
name|public
name|AMDGPUSubtarget
block|{
name|private
operator|:
name|R600InstrInfo
name|InstrInfo
block|;
name|R600FrameLowering
name|FrameLowering
block|;
name|R600TargetLowering
name|TLInfo
block|;
name|public
operator|:
name|R600Subtarget
argument_list|(
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetMachine&TM
argument_list|)
block|;
specifier|const
name|R600InstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
specifier|const
name|R600FrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
specifier|const
name|R600TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
specifier|const
name|R600RegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
operator|.
name|getRegisterInfo
argument_list|()
return|;
block|}
name|bool
name|hasCFAluBug
argument_list|()
specifier|const
block|{
return|return
name|CFALUBug
return|;
block|}
name|bool
name|hasVertexCache
argument_list|()
specifier|const
block|{
return|return
name|HasVertexCache
return|;
block|}
name|short
name|getTexVTXClauseSize
argument_list|()
specifier|const
block|{
return|return
name|TexVTXClauseSize
return|;
block|}
expr|}
block|;
name|class
name|SISubtarget
name|final
operator|:
name|public
name|AMDGPUSubtarget
block|{
name|public
operator|:
expr|enum
block|{
comment|// The closed Vulkan driver sets 96, which limits the wave count to 8 but
comment|// doesn't spill SGPRs as much as when 80 is set.
name|FIXED_SGPR_COUNT_FOR_INIT_BUG
operator|=
literal|96
block|}
block|;
name|private
operator|:
name|SIInstrInfo
name|InstrInfo
block|;
name|SIFrameLowering
name|FrameLowering
block|;
name|SITargetLowering
name|TLInfo
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|GISelAccessor
operator|>
name|GISel
block|;
name|public
operator|:
name|SISubtarget
argument_list|(
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetMachine&TM
argument_list|)
block|;
specifier|const
name|SIInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
specifier|const
name|SIFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
specifier|const
name|SITargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
specifier|const
name|CallLowering
operator|*
name|getCallLowering
argument_list|()
specifier|const
name|override
block|{
name|assert
argument_list|(
name|GISel
operator|&&
literal|"Access to GlobalISel APIs not set"
argument_list|)
block|;
return|return
name|GISel
operator|->
name|getCallLowering
argument_list|()
return|;
block|}
specifier|const
name|SIRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
operator|.
name|getRegisterInfo
argument_list|()
return|;
block|}
name|void
name|setGISelAccessor
argument_list|(
argument|GISelAccessor&GISel
argument_list|)
block|{
name|this
operator|->
name|GISel
operator|.
name|reset
argument_list|(
operator|&
name|GISel
argument_list|)
block|;   }
name|void
name|overrideSchedPolicy
argument_list|(
argument|MachineSchedPolicy&Policy
argument_list|,
argument|unsigned NumRegionInstrs
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isVGPRSpillingEnabled
argument_list|(
argument|const Function& F
argument_list|)
specifier|const
block|;
name|unsigned
name|getMaxNumUserSGPRs
argument_list|()
specifier|const
block|{
return|return
literal|16
return|;
block|}
name|bool
name|hasFlatAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|FlatAddressSpace
return|;
block|}
name|bool
name|hasSMemRealTime
argument_list|()
specifier|const
block|{
return|return
name|HasSMemRealTime
return|;
block|}
name|bool
name|hasMovrel
argument_list|()
specifier|const
block|{
return|return
name|HasMovrel
return|;
block|}
name|bool
name|hasVGPRIndexMode
argument_list|()
specifier|const
block|{
return|return
name|HasVGPRIndexMode
return|;
block|}
name|bool
name|hasScalarCompareEq64
argument_list|()
specifier|const
block|{
return|return
name|getGeneration
argument_list|()
operator|>=
name|VOLCANIC_ISLANDS
return|;
block|}
name|bool
name|hasScalarStores
argument_list|()
specifier|const
block|{
return|return
name|HasScalarStores
return|;
block|}
name|bool
name|hasInv2PiInlineImm
argument_list|()
specifier|const
block|{
return|return
name|HasInv2PiInlineImm
return|;
block|}
name|bool
name|enableSIScheduler
argument_list|()
specifier|const
block|{
return|return
name|EnableSIScheduler
return|;
block|}
name|bool
name|debuggerSupported
argument_list|()
specifier|const
block|{
return|return
name|debuggerInsertNops
argument_list|()
operator|&&
name|debuggerReserveRegs
argument_list|()
operator|&&
name|debuggerEmitPrologue
argument_list|()
return|;
block|}
name|bool
name|debuggerInsertNops
argument_list|()
specifier|const
block|{
return|return
name|DebuggerInsertNops
return|;
block|}
name|bool
name|debuggerReserveRegs
argument_list|()
specifier|const
block|{
return|return
name|DebuggerReserveRegs
return|;
block|}
name|bool
name|debuggerEmitPrologue
argument_list|()
specifier|const
block|{
return|return
name|DebuggerEmitPrologue
return|;
block|}
name|bool
name|loadStoreOptEnabled
argument_list|()
specifier|const
block|{
return|return
name|EnableLoadStoreOpt
return|;
block|}
name|bool
name|hasSGPRInitBug
argument_list|()
specifier|const
block|{
return|return
name|SGPRInitBug
return|;
block|}
name|bool
name|has12DWordStoreHazard
argument_list|()
specifier|const
block|{
return|return
name|getGeneration
argument_list|()
operator|!=
name|AMDGPUSubtarget
operator|::
name|SOUTHERN_ISLANDS
return|;
block|}
name|unsigned
name|getKernArgSegmentSize
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|unsigned ExplictArgBytes
argument_list|)
specifier|const
block|;
comment|/// Return the maximum number of waves per SIMD for kernels using \p SGPRs SGPRs
name|unsigned
name|getOccupancyWithNumSGPRs
argument_list|(
argument|unsigned SGPRs
argument_list|)
specifier|const
block|;
comment|/// Return the maximum number of waves per SIMD for kernels using \p VGPRs VGPRs
name|unsigned
name|getOccupancyWithNumVGPRs
argument_list|(
argument|unsigned VGPRs
argument_list|)
specifier|const
block|;
comment|/// \returns True if waitcnt instruction is needed before barrier instruction,
comment|/// false otherwise.
name|bool
name|needWaitcntBeforeBarrier
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|unsigned
name|getMaxNumSGPRs
argument_list|()
specifier|const
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_AMDGPUSUBTARGET_H
end_comment

end_unit

