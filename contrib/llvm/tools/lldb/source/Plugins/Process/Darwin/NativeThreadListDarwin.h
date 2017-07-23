begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeThreadListDarwin.h --------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
comment|//  Created by Greg Clayton on 6/19/07.
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
name|__NativeThreadListDarwin_h__
end_ifndef

begin_define
define|#
directive|define
name|__NativeThreadListDarwin_h__
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<vector>
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

begin_include
include|#
directive|include
file|"MachException.h"
end_include

begin_comment
comment|// #include "ThreadInfo.h"
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_darwin
block|{
name|class
name|NativeBreakpointDarwin
decl_stmt|;
name|class
name|NativeProcessDarwin
decl_stmt|;
name|class
name|NativeThreadDarwin
decl_stmt|;
name|using
name|NativeThreadDarwinSP
init|=
name|std
operator|::
name|shared_ptr
operator|<
name|NativeThreadDarwin
operator|>
decl_stmt|;
name|class
name|NativeThreadListDarwin
block|{
name|public
label|:
name|NativeThreadListDarwin
argument_list|()
expr_stmt|;
operator|~
name|NativeThreadListDarwin
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|stream
argument_list|)
decl|const
decl_stmt|;
comment|// These methods will be accessed directly from NativeThreadDarwin
if|#
directive|if
literal|0
block|bool            GetRegisterValue (nub_thread_t tid, uint32_t set, uint32_t reg, DNBRegisterValue *reg_value) const;     bool            SetRegisterValue (nub_thread_t tid, uint32_t set, uint32_t reg, const DNBRegisterValue *reg_value) const;     nub_size_t      GetRegisterContext (nub_thread_t tid, void *buf, size_t buf_len);     nub_size_t      SetRegisterContext (nub_thread_t tid, const void *buf, size_t buf_len);     uint32_t        SaveRegisterState (nub_thread_t tid);     bool            RestoreRegisterState (nub_thread_t tid, uint32_t save_id);
endif|#
directive|endif
specifier|const
name|char
modifier|*
name|GetThreadInfo
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
decl|const
decl_stmt|;
name|void
name|ProcessWillResume
parameter_list|(
name|NativeProcessDarwin
modifier|&
name|process
parameter_list|,
specifier|const
name|ResumeActionList
modifier|&
name|thread_actions
parameter_list|)
function_decl|;
name|uint32_t
name|ProcessDidStop
parameter_list|(
name|NativeProcessDarwin
modifier|&
name|process
parameter_list|)
function_decl|;
name|bool
name|NotifyException
argument_list|(
name|MachException
operator|::
name|Data
operator|&
name|exc
argument_list|)
decl_stmt|;
name|bool
name|ShouldStop
parameter_list|(
name|bool
modifier|&
name|step_more
parameter_list|)
function_decl|;
comment|// These methods will be accessed directly from NativeThreadDarwin
if|#
directive|if
literal|0
block|const char *    GetName (nub_thread_t tid);     nub_state_t     GetState (nub_thread_t tid);     nub_thread_t    SetCurrentThread (nub_thread_t tid);
endif|#
directive|endif
comment|// TODO: figure out if we need to add this to NativeThreadDarwin yet.
if|#
directive|if
literal|0
block|ThreadInfo::QoS GetRequestedQoS (nub_thread_t tid, nub_addr_t tsd, uint64_t dti_qos_class_index);     nub_addr_t      GetPThreadT (nub_thread_t tid);     nub_addr_t      GetDispatchQueueT (nub_thread_t tid);     nub_addr_t      GetTSDAddressForThread (nub_thread_t tid, uint64_t plo_pthread_tsd_base_address_offset, uint64_t plo_pthread_tsd_base_offset, uint64_t plo_pthread_tsd_entry_size);
endif|#
directive|endif
comment|// These methods will be accessed directly from NativeThreadDarwin
if|#
directive|if
literal|0
block|bool            GetThreadStoppedReason (nub_thread_t tid, struct DNBThreadStopInfo *stop_info) const;     void            DumpThreadStoppedReason (nub_thread_t tid) const;     bool            GetIdentifierInfo (nub_thread_t tid, thread_identifier_info_data_t *ident_info);
endif|#
directive|endif
name|size_t
name|GetNumberOfThreads
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|tid_t
name|ThreadIDAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|tid_t
name|GetCurrentThreadID
argument_list|()
expr_stmt|;
name|NativeThreadDarwinSP
name|GetCurrentThread
parameter_list|()
function_decl|;
name|void
name|NotifyBreakpointChanged
parameter_list|(
specifier|const
name|NativeBreakpointDarwin
modifier|*
name|bp
parameter_list|)
function_decl|;
name|uint32_t
name|EnableHardwareBreakpoint
argument_list|(
specifier|const
name|NativeBreakpointDarwin
operator|*
name|bp
argument_list|)
decl|const
decl_stmt|;
name|bool
name|DisableHardwareBreakpoint
argument_list|(
specifier|const
name|NativeBreakpointDarwin
operator|*
name|bp
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|EnableHardwareWatchpoint
argument_list|(
specifier|const
name|NativeBreakpointDarwin
operator|*
name|wp
argument_list|)
decl|const
decl_stmt|;
name|bool
name|DisableHardwareWatchpoint
argument_list|(
specifier|const
name|NativeBreakpointDarwin
operator|*
name|wp
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|GetNumberOfSupportedHardwareWatchpoints
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|GetThreadIndexForThreadStoppedWithSignal
argument_list|(
specifier|const
name|int
name|signo
argument_list|)
decl|const
decl_stmt|;
name|NativeThreadDarwinSP
name|GetThreadByID
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
decl|const
decl_stmt|;
name|NativeThreadDarwinSP
name|GetThreadByMachPortNumber
argument_list|(
operator|::
name|thread_t
name|mach_port_number
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|tid_t
name|GetThreadIDByMachPortNumber
argument_list|(
argument|::thread_t mach_port_number
argument_list|)
specifier|const
expr_stmt|;
name|thread_t
name|GetMachPortNumberByThreadID
argument_list|(
name|lldb
operator|::
name|tid_t
name|globally_unique_id
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|NativeThreadDarwinSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|// Consider having this return an lldb_private::Status.
name|uint32_t
name|UpdateThreadList
parameter_list|(
name|NativeProcessDarwin
modifier|&
name|process
parameter_list|,
name|bool
name|update
parameter_list|,
name|collection
modifier|*
name|num_threads
init|=
name|nullptr
parameter_list|)
function_decl|;
name|collection
name|m_threads
decl_stmt|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_threads_mutex
expr_stmt|;
name|NativeThreadDarwinSP
name|m_current_thread
decl_stmt|;
name|bool
name|m_is_64_bit
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace process_darwin
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
comment|// #ifndef __NativeThreadListDarwin_h__
end_comment

end_unit

