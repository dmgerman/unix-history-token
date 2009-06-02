begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- ELFTargetAsmInfo.h - ELF asm properties ---------------*- C++ -*-===//
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
comment|// This file defines target asm properties related what form asm statements
end_comment

begin_comment
comment|// should take in general on ELF-based targets
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
name|LLVM_ELF_TARGET_ASM_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ELF_TARGET_ASM_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetAsmInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|struct
name|ELFTargetAsmInfo
range|:
name|public
name|TargetAsmInfo
block|{
name|explicit
name|ELFTargetAsmInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|SectionKind
operator|::
name|Kind
name|SectionKindForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|Section
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
name|virtual
name|std
operator|::
name|string
name|printSectionFlags
argument_list|(
argument|unsigned flags
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|MergeableConstSection
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|inline
specifier|const
name|Section
operator|*
name|MergeableConstSection
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|MergeableStringSection
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|Section
operator|*
name|SelectSectionForMachineConst
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|DataRelSection
block|;
specifier|const
name|Section
operator|*
name|DataRelLocalSection
block|;
specifier|const
name|Section
operator|*
name|DataRelROSection
block|;
specifier|const
name|Section
operator|*
name|DataRelROLocalSection
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ELF_TARGET_ASM_INFO_H
end_comment

end_unit

