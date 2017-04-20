begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContextNetBSD_x86_64.h --------------------*- C++ -*-===//
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
name|__x86_64__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_NativeRegisterContextNetBSD_x86_64_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_NativeRegisterContextNetBSD_x86_64_h
end_define

begin_comment
comment|// clang-format off
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_comment
comment|// clang-format on
end_comment

begin_include
include|#
directive|include
file|"Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/RegisterContext_x86.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/lldb-x86-register-enums.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_netbsd
block|{
name|class
name|NativeProcessNetBSD
decl_stmt|;
name|class
name|NativeRegisterContextNetBSD_x86_64
range|:
name|public
name|NativeRegisterContextNetBSD
block|{
name|public
operator|:
name|NativeRegisterContextNetBSD_x86_64
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
name|Error
name|ReadRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
name|override
block|;
name|Error
name|WriteRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
name|override
block|;
name|Error
name|ReadAllRegisterValues
argument_list|(
argument|lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|Error
name|WriteAllRegisterValues
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|Error
name|IsWatchpointHit
argument_list|(
argument|uint32_t wp_index
argument_list|,
argument|bool&is_hit
argument_list|)
name|override
block|;
name|Error
name|GetWatchpointHitIndex
argument_list|(
argument|uint32_t&wp_index
argument_list|,
argument|lldb::addr_t trap_addr
argument_list|)
name|override
block|;
name|Error
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
name|Error
name|ClearAllHardwareWatchpoints
argument_list|()
name|override
block|;
name|Error
name|SetHardwareWatchpointWithIndex
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|,
argument|uint32_t wp_index
argument_list|)
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
name|void
operator|*
name|GetGPRBuffer
argument_list|()
name|override
block|{
return|return
operator|&
name|m_gpr_x86_64
return|;
block|}
name|void
operator|*
name|GetFPRBuffer
argument_list|()
name|override
block|{
return|return
operator|&
name|m_fpr_x86_64
return|;
block|}
name|void
operator|*
name|GetDBRBuffer
argument_list|()
name|override
block|{
return|return
operator|&
name|m_dbr_x86_64
return|;
block|}
name|private
operator|:
comment|// Private member types.
expr|enum
block|{
name|GPRegSet
block|,
name|FPRegSet
block|,
name|DBRegSet
block|}
block|;
comment|// Private member variables.
block|struct
name|reg
name|m_gpr_x86_64
block|;   struct
name|fpreg
name|m_fpr_x86_64
block|;   struct
name|dbreg
name|m_dbr_x86_64
block|;
name|int
name|GetSetForNativeRegNum
argument_list|(
argument|int reg_num
argument_list|)
specifier|const
block|;
name|int
name|ReadRegisterSet
argument_list|(
argument|uint32_t set
argument_list|)
block|;
name|int
name|WriteRegisterSet
argument_list|(
argument|uint32_t set
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// namespace process_netbsd
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
comment|// #ifndef lldb_NativeRegisterContextNetBSD_x86_64_h
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__x86_64__)
end_comment

end_unit

