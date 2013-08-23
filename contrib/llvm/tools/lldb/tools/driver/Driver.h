begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Driver.h ------------------------------------------------*- C++ -*-===//
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
name|lldb_Driver_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Driver_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/PseudoTerminal.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBBroadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDebugger.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBError.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBInputReader.h"
end_include

begin_define
define|#
directive|define
name|ASYNC
value|true
end_define

begin_define
define|#
directive|define
name|NO_ASYNC
value|false
end_define

begin_decl_stmt
name|class
name|IOChannel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBInputReader
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|class
name|Driver
range|:
name|public
name|lldb
operator|::
name|SBBroadcaster
block|{
name|public
operator|:
expr|enum
block|{
name|eBroadcastBitReadyForInput
operator|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastBitThreadShouldExit
operator|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|}
block|;
name|Driver
argument_list|()
block|;
name|virtual
operator|~
name|Driver
argument_list|()
block|;
name|void
name|MainLoop
argument_list|()
block|;
name|void
name|PutSTDIN
argument_list|(
argument|const char *src
argument_list|,
argument|size_t src_len
argument_list|)
block|;
name|void
name|GetFromMaster
argument_list|(
argument|const char *src
argument_list|,
argument|size_t src_len
argument_list|)
block|;
name|bool
name|HandleIOEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
block|;
name|void
name|HandleProcessEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
block|;
name|void
name|HandleBreakpointEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
block|;
name|void
name|HandleThreadEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|event
argument_list|)
block|;
name|lldb
operator|::
name|SBError
name|ParseArgs
argument_list|(
argument|int argc
argument_list|,
argument|const char *argv[]
argument_list|,
argument|FILE *out_fh
argument_list|,
argument|bool&do_exit
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetFilename
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetCrashLogFilename
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetArchName
argument_list|()
specifier|const
block|;
name|lldb
operator|::
name|ScriptLanguage
name|GetScriptLanguage
argument_list|()
specifier|const
block|;
name|size_t
name|GetNumSourceCommandFiles
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetSourceCommandFileAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
block|;
name|bool
name|GetDebugMode
argument_list|()
specifier|const
block|;
name|class
name|OptionData
block|{
name|public
operator|:
name|OptionData
argument_list|()
block|;
operator|~
name|OptionData
argument_list|()
block|;
name|void
name|Clear
argument_list|()
block|;
comment|//static OptionDefinition m_cmd_option_table[];
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|m_args
block|;
name|lldb
operator|::
name|ScriptLanguage
name|m_script_lang
block|;
name|std
operator|::
name|string
name|m_core_file
block|;
name|std
operator|::
name|string
name|m_crash_log
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|m_source_command_files
block|;
name|bool
name|m_debug_mode
block|;
name|bool
name|m_print_version
block|;
name|bool
name|m_print_python_path
block|;
name|bool
name|m_print_help
block|;
name|bool
name|m_wait_for
block|;
name|std
operator|::
name|string
name|m_process_name
block|;
name|lldb
operator|::
name|pid_t
name|m_process_pid
block|;
name|bool
name|m_use_external_editor
block|;
comment|// FIXME: When we have set/show variables we can remove this from here.
typedef|typedef
name|std
operator|::
name|set
operator|<
name|char
operator|>
name|OptionSet
expr_stmt|;
name|OptionSet
name|m_seen_options
block|;     }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|SBError
name|SetOptionValue
argument_list|(
argument|int option_idx
argument_list|,
argument|const char *option_arg
argument_list|,
argument|Driver::OptionData&data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|SBDebugger
operator|&
name|GetDebugger
argument_list|()
block|{
return|return
name|m_debugger
return|;
block|}
end_expr_stmt

begin_function
name|bool
name|EditlineReaderIsTop
parameter_list|()
block|{
return|return
name|m_debugger
operator|.
name|InputReaderIsTopReader
argument_list|(
name|m_editline_reader
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|GetIsDone
argument_list|()
specifier|const
block|{
return|return
name|m_done
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetIsDone
parameter_list|()
block|{
name|m_done
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|ResizeWindow
parameter_list|(
name|unsigned
name|short
name|col
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|lldb
operator|::
name|SBDebugger
name|m_debugger
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_utility
operator|::
name|PseudoTerminal
name|m_editline_pty
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|FILE
modifier|*
name|m_editline_slave_fh
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|SBInputReader
name|m_editline_reader
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|IOChannel
operator|>
name|m_io_channel_ap
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|OptionData
name|m_option_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_executing_user_command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_waiting_for_command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_done
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ResetOptionValues
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|GetProcessSTDOUT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|GetProcessSTDERR
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UpdateSelectedThread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CloseIOChannelFile
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|size_t
name|EditLineInputReaderCallback
argument_list|(
name|void
operator|*
name|baton
argument_list|,
name|lldb
operator|::
name|SBInputReader
operator|*
name|reader
argument_list|,
name|lldb
operator|::
name|InputReaderAction
name|notification
argument_list|,
specifier|const
name|char
operator|*
name|bytes
argument_list|,
name|size_t
name|bytes_len
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|ReadThreadBytesReceived
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|src_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|MasterThreadBytesReceived
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|src_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReadyForCommand
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_Driver_h_
end_comment

end_unit

