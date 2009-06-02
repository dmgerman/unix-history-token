begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- DarwinTargetAsmInfo.h - Darwin asm properties ---------*- C++ -*-===//
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
comment|// should take in general on Darwin-based targets
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
name|LLVM_DARWIN_TARGET_ASM_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DARWIN_TARGET_ASM_INFO_H
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
name|class
name|Mangler
decl_stmt|;
name|struct
name|DarwinTargetAsmInfo
range|:
name|public
name|TargetAsmInfo
block|{
specifier|const
name|Section
operator|*
name|TextCoalSection
block|;
specifier|const
name|Section
operator|*
name|ConstTextCoalSection
block|;
specifier|const
name|Section
operator|*
name|ConstDataCoalSection
block|;
specifier|const
name|Section
operator|*
name|ConstDataSection
block|;
specifier|const
name|Section
operator|*
name|DataCoalSection
block|;
specifier|const
name|Section
operator|*
name|FourByteConstantSection
block|;
specifier|const
name|Section
operator|*
name|EightByteConstantSection
block|;
specifier|const
name|Section
operator|*
name|SixteenByteConstantSection
block|;
name|explicit
name|DarwinTargetAsmInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
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
name|UniqueSectionForGlobal
argument_list|(
argument|const GlobalValue* GV
argument_list|,
argument|SectionKind::Kind kind
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|emitUsedDirectiveFor
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
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
specifier|const
name|Section
operator|*
name|SelectSectionForMachineConst
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DARWIN_TARGET_ASM_INFO_H
end_comment

end_unit

