begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/MipsTargetObjectFile.h - Mips Object Info ---*- C++ -*-===//
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
name|LLVM_LIB_TARGET_MIPS_MIPSTARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSTARGETOBJECTFILE_H
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
name|MipsTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
specifier|const
name|MCSection
operator|*
name|SmallDataSection
block|;
specifier|const
name|MCSection
operator|*
name|SmallBSSSection
block|;
specifier|const
name|TargetMachine
operator|*
name|TM
block|;
name|public
operator|:
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
block|;
comment|/// Return true if this global address should be placed into small data/bss
comment|/// section.
name|bool
name|IsGlobalInSmallSection
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|SectionKind Kind
argument_list|)
specifier|const
block|;
name|bool
name|IsGlobalInSmallSection
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|bool
name|IsGlobalInSmallSectionImpl
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true if this constant should be placed into small data section.
name|bool
name|IsConstantInSmallSection
argument_list|(
argument|const Constant *CN
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|SectionKind Kind
argument_list|,
argument|const Constant *C
argument_list|)
specifier|const
name|override
block|;   }
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

