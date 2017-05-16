begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContextLinux_s390x.h ----------------------*- C++ -*-===//
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__s390x__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_NativeRegisterContextLinux_s390x_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_NativeRegisterContextLinux_s390x_h
end_define

begin_include
include|#
directive|include
file|"Plugins/Process/Linux/NativeRegisterContextLinux.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/RegisterContext_s390x.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/lldb-s390x-register-enums.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_linux
block|{
name|class
name|NativeProcessLinux
decl_stmt|;
name|class
name|NativeRegisterContextLinux_s390x
range|:
name|public
name|NativeRegisterContextLinux
block|{
name|public
operator|:
name|NativeRegisterContextLinux_s390x
argument_list|(
argument|const ArchSpec&target_arch
argument_list|,
argument|NativeThreadProtocol&native_thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|uint32_t
name|GetRegisterSetCount
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|uint32_t set_index
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|GetUserRegisterCount
argument_list|()
specifier|const
name|override
block|;
name|Status
name|ReadRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
name|override
block|;
name|Status
name|WriteRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
name|override
block|;
name|Status
name|ReadAllRegisterValues
argument_list|(
argument|lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|Status
name|WriteAllRegisterValues
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|Status
name|IsWatchpointHit
argument_list|(
argument|uint32_t wp_index
argument_list|,
argument|bool&is_hit
argument_list|)
name|override
block|;
name|Status
name|GetWatchpointHitIndex
argument_list|(
argument|uint32_t&wp_index
argument_list|,
argument|lldb::addr_t trap_addr
argument_list|)
name|override
block|;
name|Status
name|IsWatchpointVacant
argument_list|(
argument|uint32_t wp_index
argument_list|,
argument|bool&is_vacant
argument_list|)
name|override
block|;
name|bool
name|ClearHardwareWatchpoint
argument_list|(
argument|uint32_t wp_index
argument_list|)
name|override
block|;
name|Status
name|ClearAllHardwareWatchpoints
argument_list|()
name|override
block|;
name|uint32_t
name|SetHardwareWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetWatchpointAddress
argument_list|(
argument|uint32_t wp_index
argument_list|)
name|override
block|;
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
name|override
block|;
name|protected
operator|:
name|Status
name|DoReadRegisterValue
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const char *reg_name
argument_list|,
argument|uint32_t size
argument_list|,
argument|RegisterValue&value
argument_list|)
name|override
block|;
name|Status
name|DoWriteRegisterValue
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const char *reg_name
argument_list|,
argument|const RegisterValue&value
argument_list|)
name|override
block|;
name|Status
name|DoReadGPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|Status
name|DoWriteGPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|Status
name|DoReadFPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|Status
name|DoWriteFPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|private
operator|:
comment|// Info about register ranges.
expr|struct
name|RegInfo
block|{
name|uint32_t
name|num_registers
block|;
name|uint32_t
name|num_gpr_registers
block|;
name|uint32_t
name|num_fpr_registers
block|;
name|uint32_t
name|last_gpr
block|;
name|uint32_t
name|first_fpr
block|;
name|uint32_t
name|last_fpr
block|;   }
block|;
comment|// Private member variables.
name|RegInfo
name|m_reg_info
block|;
name|lldb
operator|::
name|addr_t
name|m_watchpoint_addr
block|;
comment|// Private member methods.
name|bool
name|IsRegisterSetAvailable
argument_list|(
argument|uint32_t set_index
argument_list|)
specifier|const
block|;
name|bool
name|IsGPR
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
block|;
name|bool
name|IsFPR
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
block|;
name|Status
name|PeekUserArea
argument_list|(
argument|uint32_t offset
argument_list|,
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
block|;
name|Status
name|PokeUserArea
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
block|;
name|Status
name|DoReadRegisterSet
argument_list|(
argument|uint32_t regset
argument_list|,
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
block|;
name|Status
name|DoWriteRegisterSet
argument_list|(
argument|uint32_t regset
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// namespace process_linux
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef lldb_NativeRegisterContextLinux_s390x_h
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__s390x__)&& defined(__linux__)
end_comment

end_unit

