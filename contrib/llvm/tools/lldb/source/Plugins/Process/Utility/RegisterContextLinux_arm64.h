begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextLinux_arm64.h ----------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextLinux_arm64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextLinux_arm64_H_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"RegisterContextPOSIX.h"
end_include

begin_include
include|#
directive|include
file|"RegisterInfoInterface.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextLinux_arm64
range|:
name|public
name|lldb_private
operator|::
name|RegisterInfoInterface
block|{
name|public
operator|:
comment|// based on RegisterContextDarwin_arm64.h
expr|struct
name|GPR
block|{
name|uint64_t
name|x
index|[
literal|29
index|]
block|;
comment|// x0-x28
name|uint64_t
name|fp
block|;
comment|// x29
name|uint64_t
name|lr
block|;
comment|// x30
name|uint64_t
name|sp
block|;
comment|// x31
name|uint64_t
name|pc
block|;
comment|// pc
name|uint32_t
name|cpsr
block|;
comment|// cpsr
block|}
block|;
comment|// based on RegisterContextDarwin_arm64.h
block|struct
name|VReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;     }
block|;
comment|// based on RegisterContextDarwin_arm64.h
block|struct
name|FPU
block|{
name|VReg
name|v
index|[
literal|32
index|]
block|;
name|uint32_t
name|fpsr
block|;
name|uint32_t
name|fpcr
block|;     }
block|;
comment|// based on RegisterContextDarwin_arm64.h
block|struct
name|EXC
block|{
name|uint64_t
name|far
block|;
comment|// Virtual Fault Address
name|uint32_t
name|esr
block|;
comment|// Exception syndrome
name|uint32_t
name|exception
block|;
comment|// number of arm exception token
block|}
block|;
comment|// based on RegisterContextDarwin_arm64.h
block|struct
name|DBG
block|{
name|uint64_t
name|bvr
index|[
literal|16
index|]
block|;
name|uint64_t
name|bcr
index|[
literal|16
index|]
block|;
name|uint64_t
name|wvr
index|[
literal|16
index|]
block|;
name|uint64_t
name|wcr
index|[
literal|16
index|]
block|;
name|uint64_t
name|mdscr_el1
block|;     }
block|;
name|RegisterContextLinux_arm64
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|target_arch
argument_list|)
block|;
name|size_t
name|GetGPRSize
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|GetRegisterCount
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|m_register_info_p
block|;
name|uint32_t
name|m_register_info_count
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

