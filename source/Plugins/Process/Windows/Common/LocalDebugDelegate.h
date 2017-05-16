begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LocalDebugDelegate.h ------------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_LocalDebugDelegate_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_LocalDebugDelegate_H_
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|"IDebugDelegate.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessWindows
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|ProcessWindows
operator|>
name|ProcessWindowsSP
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// LocalDebugDelegate
comment|//
comment|// LocalDebugDelegate creates a connection between a ProcessWindows and the
comment|// debug driver.  This serves to decouple ProcessWindows from the debug
comment|// driver.  It would be possible to get a similar decoupling by just having
comment|// ProcessWindows implement this interface directly.  There are two reasons
comment|// why we don't do this:
comment|//
comment|// 1) In the future when we add support for local debugging through LLGS, and we
comment|//    go through the Native*Protocol interface, it is likely we will need the
comment|//    additional flexibility provided by this sort of adapter pattern.
comment|// 2) LLDB holds a shared_ptr to the ProcessWindows, and our driver thread
comment|//    needs access to it as well.  To avoid a race condition, we want to make
comment|//    sure that we're also holding onto a shared_ptr.
comment|//    lldb_private::Process supports enable_shared_from_this, but that gives us
comment|//    a ProcessSP (which is exactly what we are trying to decouple from the
comment|//    driver), so this adapter serves as a way to transparently hold the
comment|//    ProcessSP while still keeping it decoupled from the driver.
comment|//----------------------------------------------------------------------
name|class
name|LocalDebugDelegate
range|:
name|public
name|IDebugDelegate
block|{
name|public
operator|:
name|explicit
name|LocalDebugDelegate
argument_list|(
argument|lldb::ProcessWP process
argument_list|)
block|;
name|void
name|OnExitProcess
argument_list|(
argument|uint32_t exit_code
argument_list|)
name|override
block|;
name|void
name|OnDebuggerConnected
argument_list|(
argument|lldb::addr_t image_base
argument_list|)
name|override
block|;
name|ExceptionResult
name|OnDebugException
argument_list|(
argument|bool first_chance
argument_list|,
argument|const ExceptionRecord&record
argument_list|)
name|override
block|;
name|void
name|OnCreateThread
argument_list|(
argument|const HostThread&thread
argument_list|)
name|override
block|;
name|void
name|OnExitThread
argument_list|(
argument|lldb::tid_t thread_id
argument_list|,
argument|uint32_t exit_code
argument_list|)
name|override
block|;
name|void
name|OnLoadDll
argument_list|(
argument|const lldb_private::ModuleSpec&module_spec
argument_list|,
argument|lldb::addr_t module_addr
argument_list|)
name|override
block|;
name|void
name|OnUnloadDll
argument_list|(
argument|lldb::addr_t module_addr
argument_list|)
name|override
block|;
name|void
name|OnDebugString
argument_list|(
argument|const std::string&message
argument_list|)
name|override
block|;
name|void
name|OnDebuggerError
argument_list|(
argument|const Status&error
argument_list|,
argument|uint32_t type
argument_list|)
name|override
block|;
name|private
operator|:
name|ProcessWindowsSP
name|GetProcessPointer
argument_list|()
block|;
name|lldb
operator|::
name|ProcessWP
name|m_process
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

