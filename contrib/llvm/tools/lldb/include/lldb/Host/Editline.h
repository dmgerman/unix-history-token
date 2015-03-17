begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Editline.h ----------------------------------------------*- C++ -*-===//
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
comment|//TODO: wire up window size changes
end_comment

begin_comment
comment|// If we ever get a private copy of libedit, there are a number of defects that would be nice to fix;
end_comment

begin_comment
comment|// a) Sometimes text just disappears while editing.  In an 80-column editor paste the following text, without
end_comment

begin_comment
comment|//    the quotes:
end_comment

begin_comment
comment|//    "This is a test of the input system missing Hello, World!  Do you disappear when it gets to a particular length?"
end_comment

begin_comment
comment|//    Now press ^A to move to the start and type 3 characters, and you'll see a good amount of the text will
end_comment

begin_comment
comment|//    disappear.  It's still in the buffer, just invisible.
end_comment

begin_comment
comment|// b) The prompt printing logic for dealing with ANSI formatting characters is broken, which is why we're
end_comment

begin_comment
comment|//    working around it here.
end_comment

begin_comment
comment|// c) When resizing the terminal window, if the cursor moves between rows libedit will get confused.
end_comment

begin_comment
comment|// d) The incremental search uses escape to cancel input, so it's confused by ANSI sequences starting with escape.
end_comment

begin_comment
comment|// e) Emoji support is fairly terrible, presumably it doesn't understand composed characters?
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_Editline_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Editline_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// components needed to handle wide characters (<codecvt>, codecvt_utf8, libedit built with '--enable-widec' )
end_comment

begin_comment
comment|// are not consistenly available on non-OSX platforms.  The wchar_t versions of libedit functions will only be
end_comment

begin_comment
comment|// used in cases where this is true.  This is a compile time dependecy, for now selected per target Platform
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLDB_EDITLINE_USE_WCHAR
value|1
end_define

begin_include
include|#
directive|include
file|<codecvt>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLDB_EDITLINE_USE_WCHAR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/ConnectionFileDescriptor.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Host/windows/editlinewin.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ANDROID_NDK__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<histedit.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
file|"lldb/Host/Condition.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/ConnectionFileDescriptor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|line_editor
block|{
comment|// type alias's to help manage 8 bit and wide character versions of libedit
if|#
directive|if
name|LLDB_EDITLINE_USE_WCHAR
name|using
name|EditLineStringType
init|=
name|std
operator|::
name|wstring
decl_stmt|;
name|using
name|EditLineStringStreamType
init|=
name|std
operator|::
name|wstringstream
decl_stmt|;
name|using
name|EditLineCharType
init|=
name|wchar_t
decl_stmt|;
else|#
directive|else
name|using
name|EditLineStringType
init|=
name|std
operator|::
name|string
decl_stmt|;
name|using
name|EditLineStringStreamType
init|=
name|std
operator|::
name|stringstream
decl_stmt|;
name|using
name|EditLineCharType
init|=
name|char
decl_stmt|;
endif|#
directive|endif
typedef|typedef
name|int
argument_list|(
operator|*
name|EditlineGetCharCallbackType
argument_list|)
argument_list|(
operator|::
name|EditLine
operator|*
name|editline
argument_list|,
name|EditLineCharType
operator|*
name|c
argument_list|)
expr_stmt|;
typedef|typedef
name|unsigned
name|char
typedef|(
modifier|*
name|EditlineCommandCallbackType
typedef|)
parameter_list|(
typedef|::
name|EditLine
modifier|*
name|editline
typedef|,
name|int
name|ch
typedef|);
typedef|typedef
specifier|const
name|char
operator|*
call|(
modifier|*
name|EditlinePromptCallbackType
call|)
argument_list|(
operator|::
name|EditLine
operator|*
name|editline
argument_list|)
expr_stmt|;
name|class
name|EditlineHistory
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|EditlineHistory
operator|>
name|EditlineHistorySP
expr_stmt|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|IsInputCompleteCallbackType
function_decl|)
parameter_list|(
name|Editline
modifier|*
name|editline
parameter_list|,
name|StringList
modifier|&
name|lines
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|FixIndentationCallbackType
function_decl|)
parameter_list|(
name|Editline
modifier|*
name|editline
parameter_list|,
specifier|const
name|StringList
modifier|&
name|lines
parameter_list|,
name|int
name|cursor_position
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|CompleteCallbackType
function_decl|)
parameter_list|(
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
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/// Status used to decide when and how to start editing another line in multi-line sessions
name|enum
name|class
name|EditorStatus
block|{
comment|/// The default state proceeds to edit the current line
name|Editing
operator|,
comment|/// Editing complete, returns the complete set of edited lines
name|Complete
operator|,
comment|/// End of input reported
name|EndOfInput
operator|,
comment|/// Editing interrupted
name|Interrupted
block|}
empty_stmt|;
comment|/// Established locations that can be easily moved among with MoveCursor
name|enum
name|class
name|CursorLocation
block|{
comment|/// The start of the first line in a multi-line edit session
name|BlockStart
operator|,
comment|/// The start of the current line in a multi-line edit session
name|EditingPrompt
operator|,
comment|/// The location of the cursor on the current line in a multi-line edit session
name|EditingCursor
operator|,
comment|/// The location immediately after the last character in a multi-line edit session
name|BlockEnd
block|}
empty_stmt|;
block|}
name|using
name|namespace
name|line_editor
decl_stmt|;
comment|/// Instances of Editline provide an abstraction over libedit's EditLine facility.  Both
comment|/// single- and multi-line editing are supported.
name|class
name|Editline
block|{
name|public
label|:
name|Editline
argument_list|(
argument|const char * editor_name
argument_list|,
argument|FILE * input_file
argument_list|,
argument|FILE * output_file
argument_list|,
argument|FILE * error_file
argument_list|,
argument|bool color_prompts
argument_list|)
empty_stmt|;
operator|~
name|Editline
argument_list|()
expr_stmt|;
comment|/// Uses the user data storage of EditLine to retrieve an associated instance of Editline.
specifier|static
name|Editline
modifier|*
name|InstanceFor
argument_list|(
operator|::
name|EditLine
operator|*
name|editline
argument_list|)
decl_stmt|;
comment|/// Sets a string to be used as a prompt, or combined with a line number to form a prompt.
name|void
name|SetPrompt
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
comment|/// Sets an alternate string to be used as a prompt for the second line and beyond in multi-line
comment|/// editing scenarios.
name|void
name|SetContinuationPrompt
parameter_list|(
specifier|const
name|char
modifier|*
name|continuation_prompt
parameter_list|)
function_decl|;
comment|/// Required to update the width of the terminal registered for I/O.  It is critical that this
comment|/// be correct at all times.
name|void
name|TerminalSizeChanged
parameter_list|()
function_decl|;
comment|/// Returns the prompt established by SetPrompt()
specifier|const
name|char
modifier|*
name|GetPrompt
parameter_list|()
function_decl|;
comment|/// Returns the index of the line currently being edited
name|uint32_t
name|GetCurrentLine
parameter_list|()
function_decl|;
comment|/// Hides the current input session in preparation for output
name|void
name|Hide
parameter_list|()
function_decl|;
comment|/// Prepare to return to editing after a call to Hide()
name|void
name|Refresh
parameter_list|()
function_decl|;
comment|/// Interrupt the current edit as if ^C was pressed
name|bool
name|Interrupt
parameter_list|()
function_decl|;
comment|/// Register a callback for the tab key
name|void
name|SetAutoCompleteCallback
parameter_list|(
name|CompleteCallbackType
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/// Register a callback for testing whether multi-line input is complete
name|void
name|SetIsInputCompleteCallback
parameter_list|(
name|IsInputCompleteCallbackType
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/// Register a callback for determining the appropriate indentation for a line
comment|/// when creating a newline.  An optional set of insertable characters can also
comment|/// trigger the callback.
name|bool
name|SetFixIndentationCallback
parameter_list|(
name|FixIndentationCallbackType
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|indent_chars
parameter_list|)
function_decl|;
comment|/// Prompts for and reads a single line of user input.
name|bool
name|GetLine
argument_list|(
name|std
operator|::
name|string
operator|&
name|line
argument_list|,
name|bool
operator|&
name|interrupted
argument_list|)
decl_stmt|;
comment|/// Prompts for and reads a multi-line batch of user input.
name|bool
name|GetLines
parameter_list|(
name|int
name|first_line_number
parameter_list|,
name|StringList
modifier|&
name|lines
parameter_list|,
name|bool
modifier|&
name|interrupted
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Sets the lowest line number for multi-line editing sessions.  A value of zero suppresses
comment|/// line number printing in the prompt.
name|void
name|SetBaseLineNumber
parameter_list|(
name|int
name|line_number
parameter_list|)
function_decl|;
comment|/// Returns the complete prompt by combining the prompt or continuation prompt with line numbers
comment|/// as appropriate.  The line index is a zero-based index into the current multi-line session.
name|std
operator|::
name|string
name|PromptForIndex
argument_list|(
argument|int line_index
argument_list|)
expr_stmt|;
comment|/// Sets the current line index between line edits to allow free movement between lines.  Updates
comment|/// the prompt to match.
name|void
name|SetCurrentLine
parameter_list|(
name|int
name|line_index
parameter_list|)
function_decl|;
comment|/// Determines the width of the prompt in characters.  The width is guaranteed to be the same for
comment|/// all lines of the current multi-line session.
name|int
name|GetPromptWidth
parameter_list|()
function_decl|;
comment|/// Returns true if the underlying EditLine session's keybindings are Emacs-based, or false if
comment|/// they are VI-based.
name|bool
name|IsEmacs
parameter_list|()
function_decl|;
comment|/// Returns true if the current EditLine buffer contains nothing but spaces, or is empty.
name|bool
name|IsOnlySpaces
parameter_list|()
function_decl|;
comment|/// Helper method used by MoveCursor to determine relative line position.
name|int
name|GetLineIndexForLocation
parameter_list|(
name|CursorLocation
name|location
parameter_list|,
name|int
name|cursor_row
parameter_list|)
function_decl|;
comment|/// Move the cursor from one well-established location to another using relative line positioning
comment|/// and absolute column positioning.
name|void
name|MoveCursor
parameter_list|(
name|CursorLocation
name|from
parameter_list|,
name|CursorLocation
name|to
parameter_list|)
function_decl|;
comment|/// Clear from cursor position to bottom of screen and print input lines including prompts, optionally
comment|/// starting from a specific line.  Lines are drawn with an extra space at the end to reserve room for
comment|/// the rightmost cursor position.
name|void
name|DisplayInput
parameter_list|(
name|int
name|firstIndex
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Counts the number of rows a given line of content will end up occupying, taking into account both
comment|/// the preceding prompt and a single trailing space occupied by a cursor when at the end of the line.
name|int
name|CountRowsForLine
parameter_list|(
specifier|const
name|EditLineStringType
modifier|&
name|content
parameter_list|)
function_decl|;
comment|/// Save the line currently being edited
name|void
name|SaveEditedLine
parameter_list|()
function_decl|;
comment|/// Convert the current input lines into a UTF8 StringList
name|StringList
name|GetInputAsStringList
parameter_list|(
name|int
name|line_count
init|=
name|UINT32_MAX
parameter_list|)
function_decl|;
comment|/// Replaces the current multi-line session with the next entry from history.  When the parameter is
comment|/// true it will take the next earlier entry from history, when it is false it takes the next most
comment|/// recent.
name|unsigned
name|char
name|RecallHistory
parameter_list|(
name|bool
name|earlier
parameter_list|)
function_decl|;
comment|/// Character reading implementation for EditLine that supports our multi-line editing trickery.
name|int
name|GetCharacter
parameter_list|(
name|EditLineCharType
modifier|*
name|c
parameter_list|)
function_decl|;
comment|/// Prompt implementation for EditLine.
specifier|const
name|char
modifier|*
name|Prompt
parameter_list|()
function_decl|;
comment|/// Line break command used when return is pressed in multi-line mode.
name|unsigned
name|char
name|BreakLineCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Delete command used when delete is pressed in multi-line mode.
name|unsigned
name|char
name|DeleteNextCharCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Delete command used when backspace is pressed in multi-line mode.
name|unsigned
name|char
name|DeletePreviousCharCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Line navigation command used when ^P or up arrow are pressed in multi-line mode.
name|unsigned
name|char
name|PreviousLineCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Line navigation command used when ^N or down arrow are pressed in multi-line mode.
name|unsigned
name|char
name|NextLineCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Buffer start command used when Esc< is typed in multi-line emacs mode.
name|unsigned
name|char
name|BufferStartCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Buffer end command used when Esc> is typed in multi-line emacs mode.
name|unsigned
name|char
name|BufferEndCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Context-sensitive tab insertion or code completion command used when the tab key is typed.
name|unsigned
name|char
name|TabCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Respond to normal character insertion by fixing line indentation
name|unsigned
name|char
name|FixIndentationCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Revert line command used when moving between lines.
name|unsigned
name|char
name|RevertLineCommand
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|/// Ensures that the current EditLine instance is properly configured for single or multi-line editing.
name|void
name|ConfigureEditor
parameter_list|(
name|bool
name|multiline
parameter_list|)
function_decl|;
name|private
label|:
if|#
directive|if
name|LLDB_EDITLINE_USE_WCHAR
name|std
operator|::
name|wstring_convert
operator|<
name|std
operator|::
name|codecvt_utf8
operator|<
name|wchar_t
operator|>>
name|m_utf8conv
expr_stmt|;
endif|#
directive|endif
operator|::
name|EditLine
operator|*
name|m_editline
operator|=
name|nullptr
expr_stmt|;
name|EditlineHistorySP
name|m_history_sp
decl_stmt|;
name|bool
name|m_in_history
init|=
name|false
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|EditLineStringType
operator|>
name|m_live_history_lines
expr_stmt|;
name|bool
name|m_multiline_enabled
init|=
name|false
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|EditLineStringType
operator|>
name|m_input_lines
expr_stmt|;
name|EditorStatus
name|m_editor_status
decl_stmt|;
name|bool
name|m_editor_getting_char
init|=
name|false
decl_stmt|;
name|bool
name|m_color_prompts
init|=
name|true
decl_stmt|;
name|int
name|m_terminal_width
init|=
literal|0
decl_stmt|;
name|int
name|m_base_line_number
init|=
literal|0
decl_stmt|;
name|unsigned
name|m_current_line_index
init|=
literal|0
decl_stmt|;
name|int
name|m_current_line_rows
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|m_revert_cursor_index
init|=
literal|0
decl_stmt|;
name|int
name|m_line_number_digits
init|=
literal|3
decl_stmt|;
name|std
operator|::
name|string
name|m_set_prompt
expr_stmt|;
name|std
operator|::
name|string
name|m_set_continuation_prompt
expr_stmt|;
name|std
operator|::
name|string
name|m_current_prompt
expr_stmt|;
name|bool
name|m_needs_prompt_repaint
init|=
name|false
decl_stmt|;
name|std
operator|::
name|string
name|m_editor_name
expr_stmt|;
name|FILE
modifier|*
name|m_input_file
decl_stmt|;
name|FILE
modifier|*
name|m_output_file
decl_stmt|;
name|FILE
modifier|*
name|m_error_file
decl_stmt|;
name|ConnectionFileDescriptor
name|m_input_connection
decl_stmt|;
name|IsInputCompleteCallbackType
name|m_is_input_complete_callback
init|=
name|nullptr
decl_stmt|;
name|void
modifier|*
name|m_is_input_complete_callback_baton
init|=
name|nullptr
decl_stmt|;
name|FixIndentationCallbackType
name|m_fix_indentation_callback
init|=
name|nullptr
decl_stmt|;
name|void
modifier|*
name|m_fix_indentation_callback_baton
init|=
name|nullptr
decl_stmt|;
specifier|const
name|char
modifier|*
name|m_fix_indentation_callback_chars
init|=
name|nullptr
decl_stmt|;
name|CompleteCallbackType
name|m_completion_callback
init|=
name|nullptr
decl_stmt|;
name|void
modifier|*
name|m_completion_callback_baton
init|=
name|nullptr
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Editline_h_
end_comment

end_unit

