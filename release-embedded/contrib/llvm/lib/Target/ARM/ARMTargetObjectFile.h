begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/ARMTargetObjectFile.h - ARM Object Info -----*- C++ -*-===//
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
name|LLVM_TARGET_ARM_TARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_ARM_TARGETOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetLoweringObjectFileImpl.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|ARMElfTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
name|protected
operator|:
specifier|const
name|MCSection
operator|*
name|AttributesSection
block|;
name|public
operator|:
name|ARMElfTargetObjectFile
argument_list|()
operator|:
name|TargetLoweringObjectFileELF
argument_list|()
block|,
name|AttributesSection
argument_list|(
argument|NULL
argument_list|)
block|{}
name|virtual
name|void
name|Initialize
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
specifier|const
name|MCExpr
operator|*
name|getTTypeGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|getAttributesSection
argument_list|()
specifier|const
block|{
return|return
name|AttributesSection
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

