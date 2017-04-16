begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContextLinux_arm.h ---------------------*- C++ -*-===//
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
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_NativeRegisterContextLinux_arm_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_NativeRegisterContextLinux_arm_h
end_define

begin_include
include|#
directive|include
file|"Plugins/Process/Linux/NativeRegisterContextLinux.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/lldb-arm-register-enums.h"
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
name|NativeRegisterContextLinux_arm
range|:
name|public
name|NativeRegisterContextLinux
block|{
name|public
operator|:
name|NativeRegisterContextLinux_arm
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
comment|//------------------------------------------------------------------
comment|// Hardware breakpoints/watchpoint mangement functions
comment|//------------------------------------------------------------------
name|uint32_t
name|NumSupportedHardwareBreakpoints
argument_list|()
name|override
block|;
name|uint32_t
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
name|override
block|;
name|bool
name|ClearHardwareBreakpoint
argument_list|(
argument|uint32_t hw_idx
argument_list|)
name|override
block|;
name|Error
name|ClearAllHardwareBreakpoints
argument_list|()
name|override
block|;
name|Error
name|GetHardwareBreakHitIndex
argument_list|(
argument|uint32_t&bp_index
argument_list|,
argument|lldb::addr_t trap_addr
argument_list|)
name|override
block|;
name|uint32_t
name|NumSupportedHardwareWatchpoints
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
name|bool
name|ClearHardwareWatchpoint
argument_list|(
argument|uint32_t hw_index
argument_list|)
name|override
block|;
name|Error
name|ClearAllHardwareWatchpoints
argument_list|()
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
name|lldb
operator|::
name|addr_t
name|GetWatchpointHitAddress
argument_list|(
argument|uint32_t wp_index
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
name|GetWatchpointSize
argument_list|(
argument|uint32_t wp_index
argument_list|)
block|;
name|bool
name|WatchpointIsEnabled
argument_list|(
argument|uint32_t wp_index
argument_list|)
block|;
comment|// Debug register type select
block|enum
name|DREGType
block|{
name|eDREGTypeWATCH
operator|=
literal|0
block|,
name|eDREGTypeBREAK
block|}
block|;
name|protected
operator|:
name|Error
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
name|Error
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
name|Error
name|DoReadGPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|Error
name|DoWriteGPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|Error
name|DoReadFPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|Error
name|DoWriteFPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
name|override
block|;
name|void
operator|*
name|GetGPRBuffer
argument_list|()
name|override
block|{
return|return
operator|&
name|m_gpr_arm
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
name|m_fpr
return|;
block|}
name|size_t
name|GetFPRSize
argument_list|()
name|override
block|{
return|return
sizeof|sizeof
argument_list|(
name|m_fpr
argument_list|)
return|;
block|}
name|private
operator|:
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
block|;
name|uint32_t
name|first_fpr_v
block|;
name|uint32_t
name|last_fpr_v
block|;
name|uint32_t
name|gpr_flags
block|;   }
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
block|;
name|uint32_t
name|m_gpr_arm
index|[
name|k_num_gpr_registers_arm
index|]
block|;
name|RegInfo
name|m_reg_info
block|;
name|FPU
name|m_fpr
block|;
comment|// Debug register info for hardware breakpoints and watchpoints management.
block|struct
name|DREG
block|{
name|lldb
operator|::
name|addr_t
name|address
block|;
comment|// Breakpoint/watchpoint address value.
name|lldb
operator|::
name|addr_t
name|hit_addr
block|;
comment|// Address at which last watchpoint trigger exception
comment|// occurred.
name|lldb
operator|::
name|addr_t
name|real_addr
block|;
comment|// Address value that should cause target to stop.
name|uint32_t
name|control
block|;
comment|// Breakpoint/watchpoint control value.
name|uint32_t
name|refcount
block|;
comment|// Serves as enable/disable and refernce counter.
block|}
block|;    struct
name|DREG
name|m_hbr_regs
index|[
literal|16
index|]
block|;
comment|// Arm native linux hardware breakpoints
block|struct
name|DREG
name|m_hwp_regs
index|[
literal|16
index|]
block|;
comment|// Arm native linux hardware watchpoints
name|uint32_t
name|m_max_hwp_supported
block|;
name|uint32_t
name|m_max_hbp_supported
block|;
name|bool
name|m_refresh_hwdebug_info
block|;
name|bool
name|IsGPR
argument_list|(
argument|unsigned reg
argument_list|)
specifier|const
block|;
name|bool
name|IsFPR
argument_list|(
argument|unsigned reg
argument_list|)
specifier|const
block|;
name|Error
name|ReadHardwareDebugInfo
argument_list|()
block|;
name|Error
name|WriteHardwareDebugRegs
argument_list|(
argument|int hwbType
argument_list|,
argument|int hwb_index
argument_list|)
block|;
name|uint32_t
name|CalculateFprOffset
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|)
specifier|const
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
comment|// #ifndef lldb_NativeRegisterContextLinux_arm_h
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__arm__) || defined(__arm64__) || defined(__aarch64__)
end_comment

end_unit

