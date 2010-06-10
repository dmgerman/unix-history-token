begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- PPCMCAsmInfo.h - PPC asm properties -----------------*- C++ -*--====//
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
comment|// This file contains the declaration of the MCAsmInfoDarwin class.
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
name|PPCTARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PPCTARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoDarwin.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|struct
name|PPCMCAsmInfoDarwin
range|:
name|public
name|MCAsmInfoDarwin
block|{
name|explicit
name|PPCMCAsmInfoDarwin
argument_list|(
argument|bool is64Bit
argument_list|)
block|;   }
decl_stmt|;
name|struct
name|PPCLinuxMCAsmInfo
range|:
name|public
name|MCAsmInfo
block|{
name|explicit
name|PPCLinuxMCAsmInfo
argument_list|(
argument|bool is64Bit
argument_list|)
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

