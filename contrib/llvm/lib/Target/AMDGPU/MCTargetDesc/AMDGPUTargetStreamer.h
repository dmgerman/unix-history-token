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
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUTARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUCodeObjectMetadataStreamer.h"
end_include

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

begin_decl_stmt
name|namespace
name|llvm
block|{
include|#
directive|include
file|"AMDGPUPTNote.h"
name|class
name|DataLayout
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|MCELFStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|AMDGPUTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|protected
operator|:
name|AMDGPU
operator|::
name|CodeObject
operator|::
name|MetadataStreamer
name|CodeObjectMetadataStreamer
block|;
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Streamer
operator|.
name|getContext
argument_list|()
return|;
block|}
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
name|EmitStartOfCodeObjectMetadata
argument_list|(
specifier|const
name|Module
operator|&
name|Mod
argument_list|)
block|;
name|virtual
name|void
name|EmitKernelCodeObjectMetadata
argument_list|(
specifier|const
name|Function
operator|&
name|Func
argument_list|,
specifier|const
name|amd_kernel_code_t
operator|&
name|KernelCode
argument_list|)
block|;
name|virtual
name|void
name|EmitEndOfCodeObjectMetadata
argument_list|()
block|;
comment|/// \returns True on success, false on failure.
name|virtual
name|bool
name|EmitCodeObjectMetadata
argument_list|(
argument|StringRef YamlString
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
name|class
name|AMDGPUTargetAsmStreamer
name|final
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
comment|/// \returns True on success, false on failure.
name|bool
name|EmitCodeObjectMetadata
argument_list|(
argument|StringRef YamlString
argument_list|)
name|override
block|; }
decl_stmt|;
name|class
name|AMDGPUTargetELFStreamer
name|final
range|:
name|public
name|AMDGPUTargetStreamer
block|{
name|MCStreamer
operator|&
name|Streamer
block|;
name|void
name|EmitAMDGPUNote
argument_list|(
argument|const MCExpr *DescSize
argument_list|,
argument|AMDGPU::ElfNote::NoteType Type
argument_list|,
argument|function_ref<void(MCELFStreamer&)> EmitDesc
argument_list|)
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
comment|/// \returns True on success, false on failure.
name|bool
name|EmitCodeObjectMetadata
argument_list|(
argument|StringRef YamlString
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

