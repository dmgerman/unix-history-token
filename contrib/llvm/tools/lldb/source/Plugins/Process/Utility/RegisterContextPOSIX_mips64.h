begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextPOSIX_mips64.h ---------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextPOSIX_mips64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextPOSIX_mips64_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"RegisterContext_mips.h"
end_include

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
file|"lldb/Utility/Log.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|lldb_private
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegisterContextPOSIX_mips64
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
expr|enum
name|Register_count
block|{
name|gpr_registers_count
operator|=
literal|0
block|,
name|fpr_registers_count
block|,
name|msa_registers_count
block|,
name|register_set_count
block|}
block|;
name|RegisterContextPOSIX_mips64
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|lldb_private::RegisterInfoInterface *register_info
argument_list|)
block|;
operator|~
name|RegisterContextPOSIX_mips64
argument_list|()
name|override
block|;
name|void
name|Invalidate
argument_list|()
block|;
name|void
name|InvalidateAllRegisters
argument_list|()
name|override
block|;
name|size_t
name|GetRegisterCount
argument_list|()
name|override
block|;
name|virtual
name|size_t
name|GetGPRSize
argument_list|()
block|;
name|virtual
name|unsigned
name|GetRegisterSize
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|virtual
name|unsigned
name|GetRegisterOffset
argument_list|(
argument|unsigned reg
argument_list|)
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|size_t reg
argument_list|)
name|override
block|;
name|size_t
name|GetRegisterSetCount
argument_list|()
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t set
argument_list|)
name|override
block|;
specifier|const
name|char
operator|*
name|GetRegisterName
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|lldb::RegisterKind kind
argument_list|,
argument|uint32_t num
argument_list|)
name|override
block|;
name|protected
operator|:
name|uint32_t
name|m_num_registers
block|;
name|uint8_t
name|m_registers_count
index|[
name|register_set_count
index|]
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|RegisterInfoInterface
operator|>
name|m_register_info_ap
block|;
comment|// Register Info Interface (FreeBSD or Linux)
comment|// Determines if an extended register set is supported on the processor
comment|// running the inferior process.
name|virtual
name|bool
name|IsRegisterSetAvailable
argument_list|(
argument|size_t set_index
argument_list|)
block|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
block|;
name|bool
name|IsGPR
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|bool
name|IsFPR
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
block|;
name|virtual
name|bool
name|ReadGPR
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|ReadFPR
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|WriteGPR
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|WriteFPR
argument_list|()
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContextPOSIX_mips64_h_
end_comment

end_unit

