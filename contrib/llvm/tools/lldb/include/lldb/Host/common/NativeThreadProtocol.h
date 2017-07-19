begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeThreadProtocol.h ----------------------------------*- C++ -*-===//
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
name|liblldb_NativeThreadProtocol_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeThreadProtocol_h_
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Debug.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|// NativeThreadProtocol
comment|//------------------------------------------------------------------
name|class
name|NativeThreadProtocol
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|NativeThreadProtocol
operator|>
block|{
name|public
operator|:
name|NativeThreadProtocol
argument_list|(
argument|NativeProcessProtocol&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
name|virtual
operator|~
name|NativeThreadProtocol
argument_list|()
block|{}
name|virtual
name|std
operator|::
name|string
name|GetName
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|NativeRegisterContextSP
name|GetRegisterContext
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|Status
name|ReadRegister
argument_list|(
argument|uint32_t reg
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
block|;
name|virtual
name|Status
name|WriteRegister
argument_list|(
argument|uint32_t reg
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
block|;
name|virtual
name|Status
name|SaveAllRegisters
argument_list|(
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
block|;
name|virtual
name|Status
name|RestoreAllRegisters
argument_list|(
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
block|;
name|virtual
name|bool
name|GetStopReason
argument_list|(
name|ThreadStopInfo
operator|&
name|stop_info
argument_list|,
name|std
operator|::
name|string
operator|&
name|description
argument_list|)
operator|=
literal|0
block|;
name|lldb
operator|::
name|tid_t
name|GetID
argument_list|()
specifier|const
block|{
return|return
name|m_tid
return|;
block|}
name|NativeProcessProtocol
operator|&
name|GetProcess
argument_list|()
block|{
return|return
name|m_process
return|;
block|}
comment|// ---------------------------------------------------------------------
comment|// Thread-specific watchpoints
comment|// ---------------------------------------------------------------------
name|virtual
name|Status
name|SetWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|,
argument|bool hardware
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Status
name|RemoveWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
operator|=
literal|0
block|;
comment|// ---------------------------------------------------------------------
comment|// Thread-specific Hardware Breakpoint routines
comment|// ---------------------------------------------------------------------
name|virtual
name|Status
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Status
name|RemoveHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|NativeProcessProtocol
operator|&
name|m_process
block|;
name|lldb
operator|::
name|tid_t
name|m_tid
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_NativeThreadProtocol_h_
end_comment

end_unit

