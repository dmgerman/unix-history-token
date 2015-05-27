begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMMCAsmInfo.h - ARM asm properties --------------------*- C++ -*--===//
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
comment|// This file contains the declaration of the ARMMCAsmInfo class.
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
name|LLVM_LIB_TARGET_ARM_MCTARGETDESC_ARMMCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_MCTARGETDESC_ARMMCASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoCOFF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoDarwin.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoELF.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMMCAsmInfoDarwin
range|:
name|public
name|MCAsmInfoDarwin
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|explicit
name|ARMMCAsmInfoDarwin
argument_list|(
argument|StringRef TT
argument_list|)
block|;   }
decl_stmt|;
name|class
name|ARMELFMCAsmInfo
range|:
name|public
name|MCAsmInfoELF
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|explicit
name|ARMELFMCAsmInfo
argument_list|(
argument|StringRef TT
argument_list|)
block|;
name|void
name|setUseIntegratedAssembler
argument_list|(
argument|bool Value
argument_list|)
name|override
block|;   }
decl_stmt|;
name|class
name|ARMCOFFMCAsmInfoMicrosoft
range|:
name|public
name|MCAsmInfoMicrosoft
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|explicit
name|ARMCOFFMCAsmInfoMicrosoft
argument_list|()
block|;   }
decl_stmt|;
name|class
name|ARMCOFFMCAsmInfoGNU
range|:
name|public
name|MCAsmInfoGNUCOFF
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|explicit
name|ARMCOFFMCAsmInfoGNU
argument_list|()
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

