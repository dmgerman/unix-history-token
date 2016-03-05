begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUTargetStreamer.h - AMDGPU Target Streamer --------*- C++ -*--===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_R600_MCTARGETDESC_AMDGPUTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_MCTARGETDESC_AMDGPUTARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"AMDKernelCodeT.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
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
name|class
name|MCELFStreamer
decl_stmt|;
name|class
name|AMDGPUTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|AMDGPUTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
name|virtual
name|void
name|EmitDirectiveHSACodeObjectVersion
argument_list|(
argument|uint32_t Major
argument_list|,
argument|uint32_t Minor
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|EmitDirectiveHSACodeObjectISA
argument_list|(
argument|uint32_t Major
argument_list|,
argument|uint32_t Minor
argument_list|,
argument|uint32_t Stepping
argument_list|,
argument|StringRef VendorName
argument_list|,
argument|StringRef ArchName
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|EmitAMDKernelCodeT
argument_list|(
specifier|const
name|amd_kernel_code_t
operator|&
name|Header
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|EmitAMDGPUSymbolType
argument_list|(
argument|StringRef SymbolName
argument_list|,
argument|unsigned Type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|EmitAMDGPUHsaModuleScopeGlobal
argument_list|(
argument|StringRef GlobalName
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|EmitAMDGPUHsaProgramScopeGlobal
argument_list|(
argument|StringRef GlobalName
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
name|class
name|AMDGPUTargetAsmStreamer
range|:
name|public
name|AMDGPUTargetStreamer
block|{
name|formatted_raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|AMDGPUTargetAsmStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|,
name|formatted_raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|EmitDirectiveHSACodeObjectVersion
argument_list|(
argument|uint32_t Major
argument_list|,
argument|uint32_t Minor
argument_list|)
name|override
block|;
name|void
name|EmitDirectiveHSACodeObjectISA
argument_list|(
argument|uint32_t Major
argument_list|,
argument|uint32_t Minor
argument_list|,
argument|uint32_t Stepping
argument_list|,
argument|StringRef VendorName
argument_list|,
argument|StringRef ArchName
argument_list|)
name|override
block|;
name|void
name|EmitAMDKernelCodeT
argument_list|(
argument|const amd_kernel_code_t&Header
argument_list|)
name|override
block|;
name|void
name|EmitAMDGPUSymbolType
argument_list|(
argument|StringRef SymbolName
argument_list|,
argument|unsigned Type
argument_list|)
name|override
block|;
name|void
name|EmitAMDGPUHsaModuleScopeGlobal
argument_list|(
argument|StringRef GlobalName
argument_list|)
name|override
block|;
name|void
name|EmitAMDGPUHsaProgramScopeGlobal
argument_list|(
argument|StringRef GlobalName
argument_list|)
name|override
block|; }
decl_stmt|;
name|class
name|AMDGPUTargetELFStreamer
range|:
name|public
name|AMDGPUTargetStreamer
block|{    enum
name|NoteType
block|{
name|NT_AMDGPU_HSA_CODE_OBJECT_VERSION
operator|=
literal|1
block|,
name|NT_AMDGPU_HSA_HSAIL
operator|=
literal|2
block|,
name|NT_AMDGPU_HSA_ISA
operator|=
literal|3
block|,
name|NT_AMDGPU_HSA_PRODUCER
operator|=
literal|4
block|,
name|NT_AMDGPU_HSA_PRODUCER_OPTIONS
operator|=
literal|5
block|,
name|NT_AMDGPU_HSA_EXTENSION
operator|=
literal|6
block|,
name|NT_AMDGPU_HSA_HLDEBUG_DEBUG
operator|=
literal|101
block|,
name|NT_AMDGPU_HSA_HLDEBUG_TARGET
operator|=
literal|102
block|}
block|;
name|MCStreamer
operator|&
name|Streamer
block|;
name|public
operator|:
name|AMDGPUTargetELFStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
name|MCELFStreamer
operator|&
name|getStreamer
argument_list|()
block|;
name|void
name|EmitDirectiveHSACodeObjectVersion
argument_list|(
argument|uint32_t Major
argument_list|,
argument|uint32_t Minor
argument_list|)
name|override
block|;
name|void
name|EmitDirectiveHSACodeObjectISA
argument_list|(
argument|uint32_t Major
argument_list|,
argument|uint32_t Minor
argument_list|,
argument|uint32_t Stepping
argument_list|,
argument|StringRef VendorName
argument_list|,
argument|StringRef ArchName
argument_list|)
name|override
block|;
name|void
name|EmitAMDKernelCodeT
argument_list|(
argument|const amd_kernel_code_t&Header
argument_list|)
name|override
block|;
name|void
name|EmitAMDGPUSymbolType
argument_list|(
argument|StringRef SymbolName
argument_list|,
argument|unsigned Type
argument_list|)
name|override
block|;
name|void
name|EmitAMDGPUHsaModuleScopeGlobal
argument_list|(
argument|StringRef GlobalName
argument_list|)
name|override
block|;
name|void
name|EmitAMDGPUHsaProgramScopeGlobal
argument_list|(
argument|StringRef GlobalName
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

