begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- AMDGPUSubtarget.h - Define Subtarget for the AMDIL ---*- C++ -*-====//
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
name|AMDGPUSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPUSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
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

begin_define
define|#
directive|define
name|MAX_CB_SIZE
value|(1<< 16)
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
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
block|}
block|;
name|private
operator|:
name|size_t
name|DefaultSize
index|[
literal|3
index|]
block|;
name|std
operator|::
name|string
name|DevName
block|;
name|bool
name|Is64bit
block|;
name|bool
name|Is32on64bit
block|;
name|bool
name|DumpCode
block|;
name|bool
name|R600ALUInst
block|;
name|bool
name|HasVertexCache
block|;
name|short
name|TexVTXClauseSize
block|;   enum
name|Generation
name|Gen
block|;
name|bool
name|FP64
block|;
name|bool
name|CaymanISA
block|;
name|bool
name|EnableIRStructurizer
block|;
name|bool
name|EnableIfCvt
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|public
operator|:
name|AMDGPUSubtarget
argument_list|(
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
specifier|const
name|InstrItineraryData
operator|&
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
name|InstrItins
return|;
block|}
name|virtual
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|bool
name|is64bit
argument_list|()
specifier|const
block|;
name|bool
name|hasVertexCache
argument_list|()
specifier|const
block|;
name|short
name|getTexVTXClauseSize
argument_list|()
specifier|const
block|;   enum
name|Generation
name|getGeneration
argument_list|()
specifier|const
block|;
name|bool
name|hasHWFP64
argument_list|()
specifier|const
block|;
name|bool
name|hasCaymanISA
argument_list|()
specifier|const
block|;
name|bool
name|IsIRStructurizerEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isIfCvtEnabled
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
block|{
return|return
name|getGeneration
argument_list|()
operator|<=
name|NORTHERN_ISLANDS
return|;
block|}
comment|// Helper functions to simplify if statements
name|bool
name|isTargetELF
argument_list|()
specifier|const
block|;
name|std
operator|::
name|string
name|getDataLayout
argument_list|()
specifier|const
block|;
name|std
operator|::
name|string
name|getDeviceName
argument_list|()
specifier|const
block|;
name|virtual
name|size_t
name|getDefaultSize
argument_list|(
argument|uint32_t dim
argument_list|)
specifier|const
block|;
name|bool
name|dumpCode
argument_list|()
specifier|const
block|{
return|return
name|DumpCode
return|;
block|}
name|bool
name|r600ALUEncoding
argument_list|()
specifier|const
block|{
return|return
name|R600ALUInst
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDGPUSUBTARGET_H
end_comment

end_unit

