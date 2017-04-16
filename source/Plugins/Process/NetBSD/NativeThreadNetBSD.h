begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeThreadNetBSD.h ---------------------------------- -*- C++ -*-===//
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
name|liblldb_NativeThreadNetBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeThreadNetBSD_H_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeThreadProtocol.h"
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
name|NativeThreadNetBSD
range|:
name|public
name|NativeThreadProtocol
block|{
name|friend
name|class
name|NativeProcessNetBSD
block|;
name|public
operator|:
name|NativeThreadNetBSD
argument_list|(
argument|NativeProcessNetBSD *process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
comment|// ---------------------------------------------------------------------
comment|// NativeThreadProtocol Interface
comment|// ---------------------------------------------------------------------
name|std
operator|::
name|string
name|GetName
argument_list|()
name|override
block|;
name|lldb
operator|::
name|StateType
name|GetState
argument_list|()
name|override
block|;
name|bool
name|GetStopReason
argument_list|(
argument|ThreadStopInfo&stop_info
argument_list|,
argument|std::string&description
argument_list|)
name|override
block|;
name|NativeRegisterContextSP
name|GetRegisterContext
argument_list|()
name|override
block|;
name|Error
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
name|override
block|;
name|Error
name|RemoveWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
name|override
block|;
name|Error
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
name|override
block|;
name|Error
name|RemoveHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
name|override
block|;
name|private
operator|:
comment|// ---------------------------------------------------------------------
comment|// Interface for friend classes
comment|// ---------------------------------------------------------------------
name|void
name|SetStoppedBySignal
argument_list|(
argument|uint32_t signo
argument_list|,
argument|const siginfo_t *info = nullptr
argument_list|)
block|;
name|void
name|SetStoppedByBreakpoint
argument_list|()
block|;
name|void
name|SetStoppedByTrace
argument_list|()
block|;
name|void
name|SetStoppedByExec
argument_list|()
block|;
name|void
name|SetStopped
argument_list|()
block|;
name|void
name|SetRunning
argument_list|()
block|;
name|void
name|SetStepping
argument_list|()
block|;
comment|// ---------------------------------------------------------------------
comment|// Member Variables
comment|// ---------------------------------------------------------------------
name|lldb
operator|::
name|StateType
name|m_state
block|;
name|ThreadStopInfo
name|m_stop_info
block|;
name|NativeRegisterContextSP
name|m_reg_context_sp
block|;
name|std
operator|::
name|string
name|m_stop_description
block|; }
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|NativeThreadNetBSD
operator|>
name|NativeThreadNetBSDSP
expr_stmt|;
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
comment|// #ifndef liblldb_NativeThreadNetBSD_H_
end_comment

end_unit

