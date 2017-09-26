begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterInfoPOSIX_arm.h ---------------------------------*- C++ -*-===//
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
name|liblldb_RegisterInfoPOSIX_arm_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterInfoPOSIX_arm_h_
end_define

begin_include
include|#
directive|include
file|"RegisterInfoInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|class
name|RegisterInfoPOSIX_arm
range|:
name|public
name|lldb_private
operator|::
name|RegisterInfoInterface
block|{
name|public
operator|:
expr|struct
name|GPR
block|{
name|uint32_t
name|r
index|[
literal|16
index|]
block|;
comment|// R0-R15
name|uint32_t
name|cpsr
block|;
comment|// CPSR
block|}
block|;    struct
name|QReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;   }
block|;    struct
name|FPU
block|{
expr|union
block|{
name|uint32_t
name|s
index|[
literal|32
index|]
block|;
name|uint64_t
name|d
index|[
literal|32
index|]
block|;
name|QReg
name|q
index|[
literal|16
index|]
block|;
comment|// the 128-bit NEON registers
block|}
name|floats
block|;
name|uint32_t
name|fpscr
block|;   }
block|;   struct
name|EXC
block|{
name|uint32_t
name|exception
block|;
name|uint32_t
name|fsr
block|;
comment|/* Fault status */
name|uint32_t
name|far
block|;
comment|/* Virtual Fault Address */
block|}
block|;    struct
name|DBG
block|{
name|uint32_t
name|bvr
index|[
literal|16
index|]
block|;
name|uint32_t
name|bcr
index|[
literal|16
index|]
block|;
name|uint32_t
name|wvr
index|[
literal|16
index|]
block|;
name|uint32_t
name|wcr
index|[
literal|16
index|]
block|;   }
block|;
name|RegisterInfoPOSIX_arm
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

begin_comment
comment|// liblldb_RegisterInfoPOSIX_arm_h_
end_comment

end_unit

