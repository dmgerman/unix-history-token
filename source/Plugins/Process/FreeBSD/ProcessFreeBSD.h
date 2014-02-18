begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessFreeBSD.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_ProcessFreeBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessFreeBSD_H_
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
file|<queue>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadList.h"
end_include

begin_include
include|#
directive|include
file|"ProcessMessage.h"
end_include

begin_include
include|#
directive|include
file|"ProcessPOSIX.h"
end_include

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessFreeBSD
range|:
name|public
name|ProcessPOSIX
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Static functions.
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ProcessSP
name|CreateInstance
argument_list|(
name|lldb_private
operator|::
name|Target
operator|&
name|target
argument_list|,
name|lldb_private
operator|::
name|Listener
operator|&
name|listener
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|*
name|crash_file_path
argument_list|)
block|;
specifier|static
name|void
name|Initialize
argument_list|()
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
comment|// Constructors and destructors
comment|//------------------------------------------------------------------
name|ProcessFreeBSD
argument_list|(
name|lldb_private
operator|::
name|Target
operator|&
name|target
argument_list|,
name|lldb_private
operator|::
name|Listener
operator|&
name|listener
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoDetach
argument_list|(
argument|bool keep_stopped
argument_list|)
block|;
name|virtual
name|bool
name|UpdateThreadList
argument_list|(
name|lldb_private
operator|::
name|ThreadList
operator|&
name|old_thread_list
argument_list|,
name|lldb_private
operator|::
name|ThreadList
operator|&
name|new_thread_list
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|DoResume
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|WillResume
argument_list|()
block|;
name|virtual
name|void
name|SendMessage
argument_list|(
specifier|const
name|ProcessMessage
operator|&
name|message
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
name|virtual
name|void
name|GetPluginCommandHelp
argument_list|(
specifier|const
name|char
operator|*
name|command
argument_list|,
name|lldb_private
operator|::
name|Stream
operator|*
name|strm
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|ExecutePluginCommand
argument_list|(
name|lldb_private
operator|::
name|Args
operator|&
name|command
argument_list|,
name|lldb_private
operator|::
name|Stream
operator|*
name|strm
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Log
operator|*
name|EnablePluginLogging
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|strm
argument_list|,
name|lldb_private
operator|::
name|Args
operator|&
name|command
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|FreeBSDThread
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|tid_t
operator|>
name|tid_collection
expr_stmt|;
name|tid_collection
name|m_suspend_tids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tid_collection
name|m_run_tids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tid_collection
name|m_step_tids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|m_resume_signo
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessFreeBSD_H_
end_comment

end_unit

