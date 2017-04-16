begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContext.h ---------------------------------*- C++ -*-===//
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
name|liblldb_NativeRegisterContext_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeRegisterContext_h_
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
file|"lldb/Host/common/NativeWatchpointList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|NativeThreadProtocol
decl_stmt|;
name|class
name|NativeRegisterContext
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|NativeRegisterContext
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|NativeRegisterContext
argument_list|(
argument|NativeThreadProtocol&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|virtual
operator|~
name|NativeRegisterContext
argument_list|()
block|;
comment|// void
comment|// InvalidateIfNeeded (bool force);
comment|//------------------------------------------------------------------
comment|// Subclasses must override these functions
comment|//------------------------------------------------------------------
comment|// virtual void
comment|// InvalidateAllRegisters () = 0;
name|virtual
name|uint32_t
name|GetRegisterCount
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|uint32_t
name|GetUserRegisterCount
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|uint32_t reg
argument_list|)
specifier|const
operator|=
literal|0
block|;
specifier|const
name|char
operator|*
name|GetRegisterSetNameForRegisterAtIndex
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
block|;
name|virtual
name|uint32_t
name|GetRegisterSetCount
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|uint32_t set_index
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|Error
name|ReadRegister
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|RegisterValue
operator|&
name|reg_value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Error
name|WriteRegister
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
specifier|const
name|RegisterValue
operator|&
name|reg_value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Error
name|ReadAllRegisterValues
argument_list|(
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Error
name|WriteAllRegisterValues
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
operator|=
literal|0
block|;
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|uint32_t kind
argument_list|,
argument|uint32_t num
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|// Subclasses can override these functions if desired
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|NumSupportedHardwareBreakpoints
argument_list|()
block|;
name|virtual
name|uint32_t
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|virtual
name|bool
name|ClearHardwareBreakpoint
argument_list|(
argument|uint32_t hw_idx
argument_list|)
block|;
name|virtual
name|Error
name|ClearAllHardwareBreakpoints
argument_list|()
block|;
name|virtual
name|Error
name|GetHardwareBreakHitIndex
argument_list|(
argument|uint32_t&bp_index
argument_list|,
argument|lldb::addr_t trap_addr
argument_list|)
block|;
name|virtual
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
block|;
name|virtual
name|uint32_t
name|SetHardwareWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|)
block|;
name|virtual
name|bool
name|ClearHardwareWatchpoint
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|;
name|virtual
name|Error
name|ClearAllHardwareWatchpoints
argument_list|()
block|;
name|virtual
name|Error
name|IsWatchpointHit
argument_list|(
argument|uint32_t wp_index
argument_list|,
argument|bool&is_hit
argument_list|)
block|;
name|virtual
name|Error
name|GetWatchpointHitIndex
argument_list|(
argument|uint32_t&wp_index
argument_list|,
argument|lldb::addr_t trap_addr
argument_list|)
block|;
name|virtual
name|Error
name|IsWatchpointVacant
argument_list|(
argument|uint32_t wp_index
argument_list|,
argument|bool&is_vacant
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetWatchpointAddress
argument_list|(
argument|uint32_t wp_index
argument_list|)
block|;
comment|// MIPS Linux kernel returns a masked address (last 3bits are masked)
comment|// when a HW watchpoint is hit. However user may not have set a watchpoint
comment|// on this address. This function emulates the instruction at PC and
comment|// finds the base address used in the load/store instruction. This gives the
comment|// exact address used to read/write the variable being watched.
comment|// For example:
comment|// 'n' is at 0x120010d00 and 'm' is 0x120010d04. When a watchpoint is set at
comment|// 'm',
comment|// then watch exception is generated even when 'n' is read/written. This
comment|// function
comment|// returns address of 'n' so that client can check whether a watchpoint is set
comment|// on this address or not.
name|virtual
name|lldb
operator|::
name|addr_t
name|GetWatchpointHitAddress
argument_list|(
argument|uint32_t wp_index
argument_list|)
block|;
name|virtual
name|bool
name|HardwareSingleStep
argument_list|(
argument|bool enable
argument_list|)
block|;
name|virtual
name|Error
name|ReadRegisterValueFromMemory
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|lldb::addr_t src_addr
argument_list|,
argument|size_t src_len
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
block|;
name|virtual
name|Error
name|WriteRegisterValueToMemory
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|lldb::addr_t dst_addr
argument_list|,
argument|size_t dst_len
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Subclasses should not override these
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|tid_t
name|GetThreadID
argument_list|()
specifier|const
block|;
name|virtual
name|NativeThreadProtocol
operator|&
name|GetThread
argument_list|()
block|{
return|return
name|m_thread
return|;
block|}
specifier|const
name|RegisterInfo
operator|*
name|GetRegisterInfoByName
argument_list|(
argument|llvm::StringRef reg_name
argument_list|,
argument|uint32_t start_idx =
literal|0
argument_list|)
block|;
specifier|const
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|(
argument|uint32_t reg_kind
argument_list|,
argument|uint32_t reg_num
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetPC
argument_list|(
argument|lldb::addr_t fail_value = LLDB_INVALID_ADDRESS
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetPCfromBreakpointLocation
argument_list|(
argument|lldb::addr_t fail_value = LLDB_INVALID_ADDRESS
argument_list|)
block|;
name|Error
name|SetPC
argument_list|(
argument|lldb::addr_t pc
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetSP
argument_list|(
argument|lldb::addr_t fail_value = LLDB_INVALID_ADDRESS
argument_list|)
block|;
name|Error
name|SetSP
argument_list|(
argument|lldb::addr_t sp
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetFP
argument_list|(
argument|lldb::addr_t fail_value = LLDB_INVALID_ADDRESS
argument_list|)
block|;
name|Error
name|SetFP
argument_list|(
argument|lldb::addr_t fp
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetRegisterName
argument_list|(
argument|uint32_t reg
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetReturnAddress
argument_list|(
argument|lldb::addr_t fail_value = LLDB_INVALID_ADDRESS
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetFlags
argument_list|(
argument|lldb::addr_t fail_value =
literal|0
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|ReadRegisterAsUnsigned
argument_list|(
argument|uint32_t reg
argument_list|,
argument|lldb::addr_t fail_value
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|ReadRegisterAsUnsigned
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|lldb::addr_t fail_value
argument_list|)
block|;
name|Error
name|WriteRegisterFromUnsigned
argument_list|(
argument|uint32_t reg
argument_list|,
argument|uint64_t uval
argument_list|)
block|;
name|Error
name|WriteRegisterFromUnsigned
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|uint64_t uval
argument_list|)
block|;
comment|// uint32_t
comment|// GetStopID () const
comment|// {
comment|//     return m_stop_id;
comment|// }
comment|// void
comment|// SetStopID (uint32_t stop_id)
comment|// {
comment|//     m_stop_id = stop_id;
comment|// }
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from RegisterContext can see and modify these
comment|//------------------------------------------------------------------
name|NativeThreadProtocol
operator|&
name|m_thread
block|;
comment|// The thread that this register context belongs to.
name|uint32_t
name|m_concrete_frame_idx
block|;
comment|// The concrete frame index for this register
comment|// context
comment|// uint32_t m_stop_id;             // The stop ID that any data in this
comment|// context is valid for
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For RegisterContext only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|NativeRegisterContext
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_NativeRegisterContext_h_
end_comment

end_unit

