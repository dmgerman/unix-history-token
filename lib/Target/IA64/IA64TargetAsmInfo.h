begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- IA64TargetAsmInfo.h - IA64 asm properties -----------*- C++ -*--====//
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
comment|// This file contains the declaration of the IA64TargetAsmInfo class.
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
name|IA64TARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|IA64TARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetAsmInfo.h"
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
name|TargetMachine
decl_stmt|;
name|struct
name|IA64TargetAsmInfo
range|:
name|public
name|ELFTargetAsmInfo
block|{
name|explicit
name|IA64TargetAsmInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
name|unsigned
name|RelocBehaviour
argument_list|()
specifier|const
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

