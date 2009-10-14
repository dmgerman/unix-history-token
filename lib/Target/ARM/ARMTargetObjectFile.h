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
file|"llvm/Target/TargetLoweringObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSectionELF.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMElfTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
name|public
operator|:
name|ARMElfTargetObjectFile
argument_list|()
operator|:
name|TargetLoweringObjectFileELF
argument_list|()
block|{}
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
block|{
name|TargetLoweringObjectFileELF
operator|::
name|Initialize
argument_list|(
name|Ctx
argument_list|,
name|TM
argument_list|)
block|;
if|if
condition|(
name|TM
operator|.
name|getSubtarget
operator|<
name|ARMSubtarget
operator|>
operator|(
operator|)
operator|.
name|isAAPCS_ABI
argument_list|()
condition|)
block|{
name|StaticCtorSection
operator|=
name|getELFSection
argument_list|(
literal|".init_array"
argument_list|,
name|MCSectionELF
operator|::
name|SHT_INIT_ARRAY
argument_list|,
name|MCSectionELF
operator|::
name|SHF_WRITE
operator||
name|MCSectionELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getDataRel
argument_list|()
argument_list|)
expr_stmt|;
name|StaticDtorSection
operator|=
name|getELFSection
argument_list|(
literal|".fini_array"
argument_list|,
name|MCSectionELF
operator|::
name|SHT_FINI_ARRAY
argument_list|,
name|MCSectionELF
operator|::
name|SHF_WRITE
operator||
name|MCSectionELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getDataRel
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
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

end_unit

