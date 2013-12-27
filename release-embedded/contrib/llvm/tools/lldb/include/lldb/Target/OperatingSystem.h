begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OperatingSystem.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_OperatingSystem_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OperatingSystem_h_
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

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class OperatingSystem OperatingSystem.h "lldb/Target/OperatingSystem.h"
comment|/// @brief A plug-in interface definition class for halted OS helpers.
comment|///
comment|/// Halted OS plug-ins can be used by any process to locate and create
comment|/// OS objects, like threads, during the lifetime of a debug session.
comment|/// This is commonly used when attaching to an operating system that is
comment|/// halted, such as when debugging over JTAG or connecting to low level
comment|/// kernel debug services.
comment|//----------------------------------------------------------------------
name|class
name|OperatingSystem
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Find a halted OS plugin for a given process.
comment|///
comment|/// Scans the installed OperatingSystem plug-ins and tries to find
comment|/// an instance that matches the current target triple and
comment|/// executable.
comment|///
comment|/// @param[in] process
comment|///     The process for which to try and locate a halted OS
comment|///     plug-in instance.
comment|///
comment|/// @param[in] plugin_name
comment|///     An optional name of a specific halted OS plug-in that
comment|///     should be used. If NULL, pick the best plug-in.
comment|//------------------------------------------------------------------
specifier|static
name|OperatingSystem
operator|*
name|FindPlugin
argument_list|(
name|Process
operator|*
name|process
argument_list|,
specifier|const
name|char
operator|*
name|plugin_name
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Class Methods
comment|//------------------------------------------------------------------
name|OperatingSystem
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
name|virtual
operator|~
name|OperatingSystem
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Plug-in Methods
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|UpdateThreadList
argument_list|(
name|ThreadList
operator|&
name|old_thread_list
argument_list|,
name|ThreadList
operator|&
name|real_thread_list
argument_list|,
name|ThreadList
operator|&
name|new_thread_list
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|ThreadWasSelected
argument_list|(
name|Thread
operator|*
name|thread
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForThread
argument_list|(
argument|Thread *thread
argument_list|,
argument|lldb::addr_t reg_data_addr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|StopInfoSP
name|CreateThreadStopReason
argument_list|(
name|Thread
operator|*
name|thread
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|ThreadSP
name|CreateThread
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|lldb::addr_t context
argument_list|)
block|{
return|return
name|lldb
operator|::
name|ThreadSP
argument_list|()
return|;
block|}
name|virtual
name|bool
name|IsOperatingSystemPluginThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|Process
operator|*
name|m_process
block|;
comment|///< The process that this dynamic loader plug-in is tracking.
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|OperatingSystem
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
comment|// #ifndef liblldb_OperatingSystem_h_
end_comment

end_unit

