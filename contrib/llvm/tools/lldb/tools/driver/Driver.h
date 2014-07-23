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
file|"Platform.h"
end_include

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
name|void
name|ExecuteInitialCommands
argument_list|(
argument|bool before_file
argument_list|)
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
name|void
name|AddInitialCommand
argument_list|(
argument|const char *command
argument_list|,
argument|bool before_file
argument_list|,
argument|bool is_file
argument_list|,
argument|lldb::SBError&error
argument_list|)
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
name|pair
operator|<
name|bool
block|,
name|std
operator|::
name|string
operator|>
expr|>
name|m_initial_commands
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|bool
block|,
name|std
operator|::
name|string
operator|>
expr|>
name|m_after_file_commands
block|;
name|bool
name|m_debug_mode
block|;
name|bool
name|m_source_quietly
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

begin_decl_stmt
name|OptionData
name|m_option_data
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ResetOptionValues
parameter_list|()
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

