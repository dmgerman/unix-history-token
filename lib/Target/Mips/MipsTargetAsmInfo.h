begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- MipsTargetAsmInfo.h - Mips asm properties -----------*- C++ -*--====//
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
comment|// This file contains the declaration of the MipsTargetAsmInfo class.
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
name|MIPSTARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSTARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/ELFTargetAsmInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declaration.
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MipsTargetMachine
decl_stmt|;
name|struct
name|MipsTargetAsmInfo
range|:
name|public
name|ELFTargetAsmInfo
block|{
name|explicit
name|MipsTargetAsmInfo
argument_list|(
specifier|const
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// SectionKindForGlobal - This hook allows the target to select proper
comment|/// section kind used for global emission.
name|virtual
name|SectionKind
operator|::
name|Kind
name|SectionKindForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
comment|/// SectionFlagsForGlobal - This hook allows the target to select proper
comment|/// section flags either for given global or for section.
name|virtual
name|unsigned
name|SectionFlagsForGlobal
argument_list|(
argument|const GlobalValue *GV = NULL
argument_list|,
argument|const char* name = NULL
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
name|private
operator|:
specifier|const
name|MipsSubtarget
operator|*
name|Subtarget
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

