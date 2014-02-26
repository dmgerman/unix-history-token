begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IOHandler.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_IOHandler_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_IOHandler_h_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stack>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StringList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ValueObjectList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|curses
block|{
name|class
name|Application
decl_stmt|;
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|Application
operator|>
name|ApplicationAP
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|IOHandler
block|{
name|public
label|:
name|IOHandler
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
expr_stmt|;
name|IOHandler
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|const lldb::StreamFileSP&input_sp
argument_list|,
argument|const lldb::StreamFileSP&output_sp
argument_list|,
argument|const lldb::StreamFileSP&error_sp
argument_list|,
argument|uint32_t flags
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|IOHandler
argument_list|()
expr_stmt|;
comment|// Each IOHandler gets to run until it is done. It should read data
comment|// from the "in" and place output into "out" and "err and return
comment|// when done.
name|virtual
name|void
name|Run
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Hide any characters that have been displayed so far so async
comment|// output can be displayed. Refresh() will be called after the
comment|// output has been displayed.
name|virtual
name|void
name|Hide
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Called when the async output has been received in order to update
comment|// the input reader (refresh the prompt and redisplay any current
comment|// line(s) that are being edited
name|virtual
name|void
name|Refresh
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Called when an input reader should relinquish its control so another
comment|// can be pushed onto the IO handler stack, or so the current IO
comment|// handler can pop itself off the stack
name|virtual
name|void
name|Cancel
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Called when CTRL+C is pressed which usually causes
comment|// Debugger::DispatchInputInterrupt to be called.
name|virtual
name|void
name|Interrupt
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|GotEOF
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|IsActive
parameter_list|()
block|{
return|return
name|m_active
operator|&&
operator|!
name|m_done
return|;
block|}
name|virtual
name|void
name|SetIsDone
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_done
operator|=
name|b
expr_stmt|;
block|}
name|virtual
name|bool
name|GetIsDone
parameter_list|()
block|{
return|return
name|m_done
return|;
block|}
name|virtual
name|void
name|Activate
parameter_list|()
block|{
name|m_active
operator|=
name|true
expr_stmt|;
block|}
name|virtual
name|void
name|Deactivate
parameter_list|()
block|{
name|m_active
operator|=
name|false
expr_stmt|;
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetPrompt
parameter_list|()
block|{
comment|// Prompt support isn't mandatory
return|return
name|NULL
return|;
block|}
name|virtual
name|bool
name|SetPrompt
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
parameter_list|)
block|{
comment|// Prompt support isn't mandatory
return|return
name|false
return|;
block|}
name|virtual
name|ConstString
name|GetControlSequence
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|ConstString
argument_list|()
return|;
block|}
name|int
name|GetInputFD
parameter_list|()
function_decl|;
name|int
name|GetOutputFD
parameter_list|()
function_decl|;
name|int
name|GetErrorFD
parameter_list|()
function_decl|;
name|FILE
modifier|*
name|GetInputFILE
parameter_list|()
function_decl|;
name|FILE
modifier|*
name|GetOutputFILE
parameter_list|()
function_decl|;
name|FILE
modifier|*
name|GetErrorFILE
parameter_list|()
function_decl|;
name|lldb
operator|::
name|StreamFileSP
operator|&
name|GetInputStreamFile
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|StreamFileSP
operator|&
name|GetOutputStreamFile
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|StreamFileSP
operator|&
name|GetErrorStreamFile
argument_list|()
expr_stmt|;
name|Debugger
modifier|&
name|GetDebugger
parameter_list|()
block|{
return|return
name|m_debugger
return|;
block|}
name|void
modifier|*
name|GetUserData
parameter_list|()
block|{
return|return
name|m_user_data
return|;
block|}
name|void
name|SetUserData
parameter_list|(
name|void
modifier|*
name|user_data
parameter_list|)
block|{
name|m_user_data
operator|=
name|user_data
expr_stmt|;
block|}
name|Flags
modifier|&
name|GetFlags
parameter_list|()
block|{
return|return
name|m_flags
return|;
block|}
specifier|const
name|Flags
operator|&
name|GetFlags
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Check if the input is being supplied interactively by a user
comment|///
comment|/// This will return true if the input stream is a terminal (tty or
comment|/// pty) and can cause IO handlers to do different things (like
comment|/// for a comfirmation when deleting all breakpoints).
comment|//------------------------------------------------------------------
name|bool
name|GetIsInteractive
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check if the input is coming from a real terminal.
comment|///
comment|/// A real terminal has a valid size with a certain number of rows
comment|/// and colums. If this function returns true, then terminal escape
comment|/// sequences are expected to work (cursor movement escape sequences,
comment|/// clearning lines, etc).
comment|//------------------------------------------------------------------
name|bool
name|GetIsRealTerminal
parameter_list|()
function_decl|;
name|protected
label|:
name|Debugger
modifier|&
name|m_debugger
decl_stmt|;
name|lldb
operator|::
name|StreamFileSP
name|m_input_sp
expr_stmt|;
name|lldb
operator|::
name|StreamFileSP
name|m_output_sp
expr_stmt|;
name|lldb
operator|::
name|StreamFileSP
name|m_error_sp
expr_stmt|;
name|Flags
name|m_flags
decl_stmt|;
name|void
modifier|*
name|m_user_data
decl_stmt|;
name|bool
name|m_done
decl_stmt|;
name|bool
name|m_active
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|IOHandler
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// A delegate class for use with IOHandler subclasses.
comment|///
comment|/// The IOHandler delegate is designed to be mixed into classes so
comment|/// they can use an IOHandler subclass to fetch input and notify the
comment|/// object that inherits from this delegate class when a token is
comment|/// received.
comment|//------------------------------------------------------------------
name|class
name|IOHandlerDelegate
block|{
name|public
label|:
name|enum
name|class
name|Completion
block|{
name|None
operator|,
name|LLDBCommand
operator|,
name|Expression
block|}
empty_stmt|;
name|IOHandlerDelegate
argument_list|(
argument|Completion completion = Completion::None
argument_list|)
block|:
name|m_completion
argument_list|(
name|completion
argument_list|)
operator|,
name|m_io_handler_done
argument_list|(
argument|false
argument_list|)
block|{         }
name|virtual
operator|~
name|IOHandlerDelegate
argument_list|()
block|{         }
name|virtual
name|void
name|IOHandlerActivated
argument_list|(
argument|IOHandler&io_handler
argument_list|)
block|{         }
name|virtual
name|int
name|IOHandlerComplete
argument_list|(
argument|IOHandler&io_handler
argument_list|,
argument|const char *current_line
argument_list|,
argument|const char *cursor
argument_list|,
argument|const char *last_char
argument_list|,
argument|int skip_first_n_matches
argument_list|,
argument|int max_matches
argument_list|,
argument|StringList&matches
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Called when a line or lines have been retrieved.
comment|///
comment|/// This funtion can handle the current line and possibly call
comment|/// IOHandler::SetIsDone(true) when the IO handler is done like when
comment|/// "quit" is entered as a command, of when an empty line is
comment|/// received. It is up to the delegate to determine when a line
comment|/// should cause a IOHandler to exit.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|IOHandlerInputComplete
argument_list|(
name|IOHandler
operator|&
name|io_handler
argument_list|,
name|std
operator|::
name|string
operator|&
name|data
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Called when a line in \a lines has been updated when doing
comment|/// multi-line input.
comment|///
comment|/// @return
comment|///     Return an enumeration to indicate the status of the current
comment|///     line:
comment|///         Success - The line is good and should be added to the
comment|///                   multiple lines
comment|///         Error - There is an error with the current line and it
comment|///                 need to be re-edited before it is acceptable
comment|///         Done - The lines collection is complete and ready to be
comment|///                returned.
comment|//------------------------------------------------------------------
name|virtual
name|LineStatus
name|IOHandlerLinesUpdated
parameter_list|(
name|IOHandler
modifier|&
name|io_handler
parameter_list|,
name|StringList
modifier|&
name|lines
parameter_list|,
name|uint32_t
name|line_idx
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
block|{
return|return
name|LineStatus
operator|::
name|Done
return|;
comment|// Stop getting lines on the first line that is updated
comment|// subclasses should do something more intelligent here.
comment|// This function will not be called on IOHandler objects
comment|// that are getting single lines.
block|}
name|virtual
name|ConstString
name|GetControlSequence
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
return|return
name|ConstString
argument_list|()
return|;
block|}
name|protected
label|:
name|Completion
name|m_completion
decl_stmt|;
comment|// Support for common builtin completions
name|bool
name|m_io_handler_done
decl_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// IOHandlerDelegateMultiline
comment|//
comment|// A IOHandlerDelegate that handles terminating multi-line input when
comment|// the last line is equal to "end_line" which is specified in the
comment|// constructor.
comment|//----------------------------------------------------------------------
name|class
name|IOHandlerDelegateMultiline
range|:
name|public
name|IOHandlerDelegate
block|{
name|public
operator|:
name|IOHandlerDelegateMultiline
argument_list|(
argument|const char *end_line
argument_list|,
argument|Completion completion = Completion::None
argument_list|)
operator|:
name|IOHandlerDelegate
argument_list|(
name|completion
argument_list|)
block|,
name|m_end_line
argument_list|(
argument|(end_line&& end_line[
literal|0
argument|]) ? end_line :
literal|""
argument_list|)
block|{         }
name|virtual
operator|~
name|IOHandlerDelegateMultiline
argument_list|()
block|{         }
name|virtual
name|ConstString
name|GetControlSequence
argument_list|(
argument|char ch
argument_list|)
block|{
if|if
condition|(
name|ch
operator|==
literal|'d'
condition|)
return|return
name|ConstString
argument_list|(
name|m_end_line
operator|+
literal|"\n"
argument_list|)
return|;
return|return
name|ConstString
argument_list|()
return|;
block|}
name|virtual
name|LineStatus
name|IOHandlerLinesUpdated
parameter_list|(
name|IOHandler
modifier|&
name|io_handler
parameter_list|,
name|StringList
modifier|&
name|lines
parameter_list|,
name|uint32_t
name|line_idx
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
block|{
if|if
condition|(
name|line_idx
operator|==
name|UINT32_MAX
condition|)
block|{
comment|// Remove the last empty line from "lines" so it doesn't appear
comment|// in our final expression and return true to indicate we are done
comment|// getting lines
name|lines
operator|.
name|PopBack
argument_list|()
expr_stmt|;
return|return
name|LineStatus
operator|::
name|Done
return|;
block|}
elseif|else
if|if
condition|(
name|line_idx
operator|+
literal|1
operator|==
name|lines
operator|.
name|GetSize
argument_list|()
condition|)
block|{
comment|// The last line was edited, if this line is empty, then we are done
comment|// getting our multiple lines.
if|if
condition|(
name|lines
index|[
name|line_idx
index|]
operator|==
name|m_end_line
condition|)
return|return
name|LineStatus
operator|::
name|Done
return|;
block|}
return|return
name|LineStatus
operator|::
name|Success
return|;
block|}
name|protected
label|:
specifier|const
name|std
operator|::
name|string
name|m_end_line
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|IOHandlerEditline
range|:
name|public
name|IOHandler
block|{
name|public
operator|:
name|IOHandlerEditline
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|const char *editline_name
argument_list|,
comment|// Used for saving history files
argument|const char *prompt
argument_list|,
argument|bool multi_line
argument_list|,
argument|IOHandlerDelegate&delegate
argument_list|)
block|;
name|IOHandlerEditline
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|const lldb::StreamFileSP&input_sp
argument_list|,
argument|const lldb::StreamFileSP&output_sp
argument_list|,
argument|const lldb::StreamFileSP&error_sp
argument_list|,
argument|uint32_t flags
argument_list|,
argument|const char *editline_name
argument_list|,
comment|// Used for saving history files
argument|const char *prompt
argument_list|,
argument|bool multi_line
argument_list|,
argument|IOHandlerDelegate&delegate
argument_list|)
block|;
name|virtual
operator|~
name|IOHandlerEditline
argument_list|()
block|;
name|virtual
name|void
name|Run
argument_list|()
block|;
name|virtual
name|void
name|Hide
argument_list|()
block|;
name|virtual
name|void
name|Refresh
argument_list|()
block|;
name|virtual
name|void
name|Cancel
argument_list|()
block|;
name|virtual
name|void
name|Interrupt
argument_list|()
block|;
name|virtual
name|void
name|GotEOF
argument_list|()
block|;
name|virtual
name|void
name|Activate
argument_list|()
block|{
name|IOHandler
operator|::
name|Activate
argument_list|()
block|;
name|m_delegate
operator|.
name|IOHandlerActivated
argument_list|(
operator|*
name|this
argument_list|)
block|;         }
name|virtual
name|ConstString
name|GetControlSequence
argument_list|(
argument|char ch
argument_list|)
block|{
return|return
name|m_delegate
operator|.
name|GetControlSequence
argument_list|(
name|ch
argument_list|)
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|GetPrompt
argument_list|()
block|;
name|virtual
name|bool
name|SetPrompt
argument_list|(
specifier|const
name|char
operator|*
name|prompt
argument_list|)
block|;
name|bool
name|GetLine
argument_list|(
name|std
operator|::
name|string
operator|&
name|line
argument_list|)
block|;
name|bool
name|GetLines
argument_list|(
name|StringList
operator|&
name|lines
argument_list|)
block|;
name|private
operator|:
specifier|static
name|LineStatus
name|LineCompletedCallback
argument_list|(
argument|Editline *editline
argument_list|,
argument|StringList&lines
argument_list|,
argument|uint32_t line_idx
argument_list|,
argument|Error&error
argument_list|,
argument|void *baton
argument_list|)
block|;
specifier|static
name|int
name|AutoCompleteCallback
argument_list|(
argument|const char *current_line
argument_list|,
argument|const char *cursor
argument_list|,
argument|const char *last_char
argument_list|,
argument|int skip_first_n_matches
argument_list|,
argument|int max_matches
argument_list|,
argument|StringList&matches
argument_list|,
argument|void *baton
argument_list|)
block|;
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|Editline
operator|>
name|m_editline_ap
block|;
name|IOHandlerDelegate
operator|&
name|m_delegate
block|;
name|std
operator|::
name|string
name|m_prompt
block|;
name|bool
name|m_multi_line
block|;             }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|IOHandlerConfirm
range|:
name|public
name|IOHandlerEditline
decl_stmt|,
name|public
name|IOHandlerDelegate
block|{
name|public
label|:
name|IOHandlerConfirm
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|const char *prompt
argument_list|,
argument|bool default_response
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|IOHandlerConfirm
argument_list|()
expr_stmt|;
name|bool
name|GetResponse
argument_list|()
specifier|const
block|{
return|return
name|m_user_response
return|;
block|}
name|virtual
name|int
name|IOHandlerComplete
parameter_list|(
name|IOHandler
modifier|&
name|io_handler
parameter_list|,
specifier|const
name|char
modifier|*
name|current_line
parameter_list|,
specifier|const
name|char
modifier|*
name|cursor
parameter_list|,
specifier|const
name|char
modifier|*
name|last_char
parameter_list|,
name|int
name|skip_first_n_matches
parameter_list|,
name|int
name|max_matches
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
name|virtual
name|void
name|IOHandlerInputComplete
argument_list|(
name|IOHandler
operator|&
name|io_handler
argument_list|,
name|std
operator|::
name|string
operator|&
name|data
argument_list|)
decl_stmt|;
name|protected
label|:
specifier|const
name|bool
name|m_default_response
decl_stmt|;
name|bool
name|m_user_response
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|IOHandlerCursesGUI
range|:
name|public
name|IOHandler
block|{
name|public
operator|:
name|IOHandlerCursesGUI
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
block|;
name|virtual
operator|~
name|IOHandlerCursesGUI
argument_list|()
block|;
name|virtual
name|void
name|Run
argument_list|()
block|;
name|virtual
name|void
name|Hide
argument_list|()
block|;
name|virtual
name|void
name|Refresh
argument_list|()
block|;
name|virtual
name|void
name|Cancel
argument_list|()
block|;
name|virtual
name|void
name|Interrupt
argument_list|()
block|;
name|virtual
name|void
name|GotEOF
argument_list|()
block|;
name|virtual
name|void
name|Activate
argument_list|()
block|;
name|virtual
name|void
name|Deactivate
argument_list|()
block|;
name|protected
operator|:
name|curses
operator|::
name|ApplicationAP
name|m_app_ap
block|;     }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|IOHandlerCursesValueObjectList
range|:
name|public
name|IOHandler
block|{
name|public
operator|:
name|IOHandlerCursesValueObjectList
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|,
name|ValueObjectList
operator|&
name|valobj_list
argument_list|)
block|;
name|virtual
operator|~
name|IOHandlerCursesValueObjectList
argument_list|()
block|;
name|virtual
name|void
name|Run
argument_list|()
block|;
name|virtual
name|void
name|Hide
argument_list|()
block|;
name|virtual
name|void
name|Refresh
argument_list|()
block|;
name|virtual
name|void
name|Interrupt
argument_list|()
block|;
name|virtual
name|void
name|GotEOF
argument_list|()
block|;
name|protected
operator|:
name|ValueObjectList
name|m_valobj_list
block|;     }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|IOHandlerStack
block|{
name|public
label|:
name|IOHandlerStack
argument_list|()
operator|:
name|m_stack
argument_list|()
operator|,
name|m_mutex
argument_list|(
name|Mutex
operator|::
name|eMutexTypeRecursive
argument_list|)
operator|,
name|m_top
argument_list|(
argument|NULL
argument_list|)
block|{         }
operator|~
name|IOHandlerStack
argument_list|()
block|{         }
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
return|return
name|m_stack
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|Push
argument_list|(
specifier|const
name|lldb
operator|::
name|IOHandlerSP
operator|&
name|sp
argument_list|)
block|{
if|if
condition|(
name|sp
condition|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
name|m_stack
operator|.
name|push
argument_list|(
name|sp
argument_list|)
expr_stmt|;
comment|// Set m_top the non-locking IsTop() call
name|m_top
operator|=
name|sp
operator|.
name|get
argument_list|()
expr_stmt|;
block|}
block|}
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
return|return
name|m_stack
operator|.
name|empty
argument_list|()
return|;
block|}
name|lldb
operator|::
name|IOHandlerSP
name|Top
argument_list|()
block|{
name|lldb
operator|::
name|IOHandlerSP
name|sp
block|;
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
if|if
condition|(
operator|!
name|m_stack
operator|.
name|empty
argument_list|()
condition|)
name|sp
operator|=
name|m_stack
operator|.
name|top
argument_list|()
expr_stmt|;
block|}
return|return
name|sp
return|;
block|}
name|void
name|Pop
parameter_list|()
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_stack
operator|.
name|empty
argument_list|()
condition|)
name|m_stack
operator|.
name|pop
argument_list|()
expr_stmt|;
comment|// Set m_top the non-locking IsTop() call
if|if
condition|(
name|m_stack
operator|.
name|empty
argument_list|()
condition|)
name|m_top
operator|=
name|NULL
expr_stmt|;
else|else
name|m_top
operator|=
name|m_stack
operator|.
name|top
argument_list|()
operator|.
name|get
argument_list|()
expr_stmt|;
block|}
name|Mutex
modifier|&
name|GetMutex
parameter_list|()
block|{
return|return
name|m_mutex
return|;
block|}
name|bool
name|IsTop
argument_list|(
specifier|const
name|lldb
operator|::
name|IOHandlerSP
operator|&
name|io_handler_sp
argument_list|)
decl|const
block|{
return|return
name|m_top
operator|==
name|io_handler_sp
operator|.
name|get
argument_list|()
return|;
block|}
name|ConstString
name|GetTopIOHandlerControlSequence
parameter_list|(
name|char
name|ch
parameter_list|)
block|{
if|if
condition|(
name|m_top
condition|)
return|return
name|m_top
operator|->
name|GetControlSequence
argument_list|(
name|ch
argument_list|)
return|;
return|return
name|ConstString
argument_list|()
return|;
block|}
name|protected
label|:
name|std
operator|::
name|stack
operator|<
name|lldb
operator|::
name|IOHandlerSP
operator|>
name|m_stack
expr_stmt|;
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
name|IOHandler
modifier|*
name|m_top
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|IOHandlerStack
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_IOHandler_h_
end_comment

end_unit

