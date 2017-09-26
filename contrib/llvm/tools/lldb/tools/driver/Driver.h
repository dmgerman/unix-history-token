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
file|"lldb/Host/PseudoTerminal.h"
end_include

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_include
include|#
directive|include
file|<set>
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
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBError.h"
end_include

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
typedef|typedef
enum|enum
name|CommandPlacement
block|{
name|eCommandPlacementBeforeFile
block|,
name|eCommandPlacementAfterFile
block|,
name|eCommandPlacementAfterCrash
block|,
block|}
name|CommandPlacement
expr_stmt|;
name|Driver
argument_list|()
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
operator|~
name|Driver
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|MainLoop
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|GetFilename
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|GetCrashLogFilename
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|GetArchName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ScriptLanguage
name|GetScriptLanguage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|WriteCommandsForSourcing
argument_list|(
name|CommandPlacement
name|placement
argument_list|,
name|lldb
operator|::
name|SBStream
operator|&
name|strm
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|bool
name|GetDebugMode
parameter_list|()
function|const;
end_function

begin_decl_stmt
name|class
name|OptionData
block|{
name|public
label|:
name|OptionData
argument_list|()
expr_stmt|;
operator|~
name|OptionData
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|AddInitialCommand
argument_list|(
specifier|const
name|char
operator|*
name|command
argument_list|,
name|CommandPlacement
name|placement
argument_list|,
name|bool
name|is_file
argument_list|,
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
decl_stmt|;
comment|// static OptionDefinition m_cmd_option_table[];
struct|struct
name|InitialCmdEntry
block|{
name|InitialCmdEntry
argument_list|(
argument|const char *in_contents
argument_list|,
argument|bool in_is_file
argument_list|,
argument|bool is_cwd_lldbinit_file_read
argument_list|,
argument|bool in_quiet = false
argument_list|)
block|:
name|contents
argument_list|(
name|in_contents
argument_list|)
operator|,
name|is_file
argument_list|(
name|in_is_file
argument_list|)
operator|,
name|is_cwd_lldbinit_file_read
argument_list|(
name|is_cwd_lldbinit_file_read
argument_list|)
operator|,
name|source_quietly
argument_list|(
argument|in_quiet
argument_list|)
block|{}
name|std
operator|::
name|string
name|contents
expr_stmt|;
name|bool
name|is_file
decl_stmt|;
name|bool
name|is_cwd_lldbinit_file_read
decl_stmt|;
comment|// if this is reading ./.lldbinit - so we
comment|// may skip if not permitted
name|bool
name|source_quietly
decl_stmt|;
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|m_args
expr_stmt|;
name|lldb
operator|::
name|ScriptLanguage
name|m_script_lang
expr_stmt|;
name|std
operator|::
name|string
name|m_core_file
expr_stmt|;
name|std
operator|::
name|string
name|m_crash_log
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|InitialCmdEntry
operator|>
name|m_initial_commands
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|InitialCmdEntry
operator|>
name|m_after_file_commands
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|InitialCmdEntry
operator|>
name|m_after_crash_commands
expr_stmt|;
name|bool
name|m_debug_mode
decl_stmt|;
name|bool
name|m_source_quietly
decl_stmt|;
name|bool
name|m_print_version
decl_stmt|;
name|bool
name|m_print_python_path
decl_stmt|;
name|bool
name|m_print_help
decl_stmt|;
name|bool
name|m_wait_for
decl_stmt|;
name|bool
name|m_repl
decl_stmt|;
name|lldb
operator|::
name|LanguageType
name|m_repl_lang
expr_stmt|;
name|std
operator|::
name|string
name|m_repl_options
expr_stmt|;
name|std
operator|::
name|string
name|m_process_name
expr_stmt|;
name|lldb
operator|::
name|pid_t
name|m_process_pid
expr_stmt|;
name|bool
name|m_use_external_editor
decl_stmt|;
comment|// FIXME: When we have set/show variables we can
comment|// remove this from here.
name|bool
name|m_batch
decl_stmt|;
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
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

