begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OperatingSystemGo.h -------------------------------------*- C++ -*-===//
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
name|_liblldb_OperatingSystemGo_h_
end_ifndef

begin_define
define|#
directive|define
name|_liblldb_OperatingSystemGo_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/OperatingSystem.h"
end_include

begin_decl_stmt
name|class
name|DynamicRegisterInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|OperatingSystemGo
range|:
name|public
name|lldb_private
operator|::
name|OperatingSystem
block|{
name|public
operator|:
name|OperatingSystemGo
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
operator|~
name|OperatingSystemGo
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|lldb_private
operator|::
name|OperatingSystem
operator|*
name|CreateInstance
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|bool force
argument_list|)
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|DebuggerInitialize
argument_list|(
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|)
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// lldb_private::PluginInterface Methods
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// lldb_private::OperatingSystem Methods
comment|//------------------------------------------------------------------
name|bool
name|UpdateThreadList
argument_list|(
argument|lldb_private::ThreadList&old_thread_list
argument_list|,
argument|lldb_private::ThreadList&real_thread_list
argument_list|,
argument|lldb_private::ThreadList&new_thread_list
argument_list|)
name|override
block|;
name|void
name|ThreadWasSelected
argument_list|(
argument|lldb_private::Thread *thread
argument_list|)
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForThread
argument_list|(
argument|lldb_private::Thread *thread
argument_list|,
argument|lldb::addr_t reg_data_addr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|StopInfoSP
name|CreateThreadStopReason
argument_list|(
argument|lldb_private::Thread *thread
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Method for lazy creation of threads on demand
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ThreadSP
name|CreateThread
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|lldb::addr_t context
argument_list|)
name|override
block|;
name|private
operator|:
expr|struct
name|Goroutine
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|FindGlobal
argument_list|(
argument|lldb::TargetSP target
argument_list|,
argument|const char *name
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|TypeSP
name|FindType
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|const char *name
argument_list|)
block|;
name|bool
name|Init
argument_list|(
name|lldb_private
operator|::
name|ThreadList
operator|&
name|threads
argument_list|)
block|;
name|Goroutine
name|CreateGoroutineAtIndex
argument_list|(
argument|uint64_t idx
argument_list|,
argument|lldb_private::Status&err
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|DynamicRegisterInfo
operator|>
name|m_reginfo
block|;
name|lldb
operator|::
name|ValueObjectSP
name|m_allg_sp
block|;
name|lldb
operator|::
name|ValueObjectSP
name|m_allglen_sp
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OperatingSystemGo_h_
end_comment

end_unit

