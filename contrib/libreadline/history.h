begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* History.h -- the names of functions that you can call in history. */
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1992 Free Software Foundation, Inc.     This file contains the GNU History Library (the Library), a set of    routines for managing the text of previously typed lines.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HISTORY_H_
end_ifndef

begin_define
define|#
directive|define
name|_HISTORY_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_FUNCTION_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|_FUNCTION_DEF
end_define

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CPFunction
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
modifier|*
name|CPPFunction
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The structure used to store a history entry. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hist_entry
block|{
name|char
modifier|*
name|line
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|HIST_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* A structure used to pass the current state of the history stuff around. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hist_state
block|{
name|HIST_ENTRY
modifier|*
modifier|*
name|entries
decl_stmt|;
comment|/* Pointer to the entries themselves. */
name|int
name|offset
decl_stmt|;
comment|/* The location pointer within this array. */
name|int
name|length
decl_stmt|;
comment|/* Number of elements within this array. */
name|int
name|size
decl_stmt|;
comment|/* Number of slots allocated to this array. */
name|int
name|flags
decl_stmt|;
block|}
name|HISTORY_STATE
typedef|;
end_typedef

begin_comment
comment|/* Flag values for the `flags' member of HISTORY_STATE. */
end_comment

begin_define
define|#
directive|define
name|HS_STIFLED
value|0x01
end_define

begin_comment
comment|/* Initialization and state management. */
end_comment

begin_comment
comment|/* Begin a session in which the history functions might be used.  This    just initializes the interactive variables. */
end_comment

begin_function_decl
specifier|extern
name|void
name|using_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the current HISTORY_STATE of the history. */
end_comment

begin_function_decl
specifier|extern
name|HISTORY_STATE
modifier|*
name|history_get_history_state
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Set the state of the current history array to STATE. */
end_comment

begin_function_decl
specifier|extern
name|void
name|history_set_history_state
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Manage the history list. */
end_comment

begin_comment
comment|/* Place STRING at the end of the history list.    The associated data field (if any) is set to NULL. */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A reasonably useless function, only here for completeness.  WHICH    is the magic number that tells us which element to delete.  The    elements are numbered from 0. */
end_comment

begin_function_decl
specifier|extern
name|HIST_ENTRY
modifier|*
name|remove_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make the history entry at WHICH have LINE and DATA.  This returns    the old entry so you can dispose of the data.  In the case of an    invalid WHICH, a NULL pointer is returned. */
end_comment

begin_function_decl
specifier|extern
name|HIST_ENTRY
modifier|*
name|replace_history_entry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Clear the history list and start over. */
end_comment

begin_function_decl
specifier|extern
name|void
name|clear_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Stifle the history list, remembering only MAX number of entries. */
end_comment

begin_function_decl
specifier|extern
name|void
name|stifle_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Stop stifling the history.  This returns the previous amount the    history was stifled by.  The value is positive if the history was    stifled, negative if it wasn't. */
end_comment

begin_function_decl
specifier|extern
name|int
name|unstifle_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return 1 if the history is stifled, 0 if it is not. */
end_comment

begin_function_decl
specifier|extern
name|int
name|history_is_stifled
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Information about the history list. */
end_comment

begin_comment
comment|/* Return a NULL terminated array of HIST_ENTRY which is the current input    history.  Element 0 of this list is the beginning of time.  If there    is no history, return NULL. */
end_comment

begin_function_decl
specifier|extern
name|HIST_ENTRY
modifier|*
modifier|*
name|history_list
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the number which says what history element we are now    looking at.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|where_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the history entry at the current position, as determined by    history_offset.  If there is no entry there, return a NULL pointer. */
end_comment

begin_function_decl
name|HIST_ENTRY
modifier|*
name|current_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the history entry which is logically at OFFSET in the history    array.  OFFSET is relative to history_base. */
end_comment

begin_function_decl
specifier|extern
name|HIST_ENTRY
modifier|*
name|history_get
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of bytes that the primary history entries are using.    This just adds up the lengths of the_history->lines. */
end_comment

begin_function_decl
specifier|extern
name|int
name|history_total_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Moving around the history list. */
end_comment

begin_comment
comment|/* Set the position in the history list to POS. */
end_comment

begin_function_decl
name|int
name|history_set_pos
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Back up history_offset to the previous history entry, and return    a pointer to that entry.  If there is no previous entry, return    a NULL pointer. */
end_comment

begin_function_decl
specifier|extern
name|HIST_ENTRY
modifier|*
name|previous_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Move history_offset forward to the next item in the input_history,    and return the a pointer to that entry.  If there is no next entry,    return a NULL pointer. */
end_comment

begin_function_decl
specifier|extern
name|HIST_ENTRY
modifier|*
name|next_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Searching the history list. */
end_comment

begin_comment
comment|/* Search the history for STRING, starting at history_offset.    If DIRECTION< 0, then the search is through previous entries,    else through subsequent.  If the string is found, then    current_history () is the history entry, and the value of this function    is the offset in the line of that history entry that the string was    found in.  Otherwise, nothing is changed, and a -1 is returned. */
end_comment

begin_function_decl
specifier|extern
name|int
name|history_search
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Search the history for STRING, starting at history_offset.    The search is anchored: matching lines must begin with string. */
end_comment

begin_function_decl
specifier|extern
name|int
name|history_search_prefix
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Search for STRING in the history list, starting at POS, an    absolute index into the list.  DIR, if negative, says to search    backwards from POS, else forwards.    Returns the absolute index of the history element where STRING    was found, or -1 otherwise. */
end_comment

begin_function_decl
specifier|extern
name|int
name|history_search_pos
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Managing the history file. */
end_comment

begin_comment
comment|/* Add the contents of FILENAME to the history list, a line at a time.    If FILENAME is NULL, then read from ~/.history.  Returns 0 if    successful, or errno if not. */
end_comment

begin_function_decl
specifier|extern
name|int
name|read_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Read a range of lines from FILENAME, adding them to the history list.    Start reading at the FROM'th line and end at the TO'th.  If FROM    is zero, start at the beginning.  If TO is less than FROM, read    until the end of the file.  If FILENAME is NULL, then read from    ~/.history.  Returns 0 if successful, or errno if not. */
end_comment

begin_function_decl
specifier|extern
name|int
name|read_history_range
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Write the current history to FILENAME.  If FILENAME is NULL,    then write the history list to ~/.history.  Values returned    are as in read_history ().  */
end_comment

begin_function_decl
specifier|extern
name|int
name|write_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Append NELEMENT entries to FILENAME.  The entries appended are from    the end of the list minus NELEMENTs up to the end of the list. */
end_comment

begin_function_decl
name|int
name|append_history
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Truncate the history file, leaving only the last NLINES lines. */
end_comment

begin_function_decl
specifier|extern
name|int
name|history_truncate_file
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* History expansion. */
end_comment

begin_comment
comment|/* Expand the string STRING, placing the result into OUTPUT, a pointer    to a string.  Returns:     0) If no expansions took place (or, if the only change in       the text was the de-slashifying of the history expansion       character)    1) If expansions did take place   -1) If there was an error in expansion.    2) If the returned line should just be printed.    If an error ocurred in expansion, then OUTPUT contains a descriptive   error message. */
end_comment

begin_function_decl
specifier|extern
name|int
name|history_expand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Extract a string segment consisting of the FIRST through LAST    arguments present in STRING.  Arguments are broken up as in    the shell. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|history_arg_extract
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the text of the history event beginning at the current    offset into STRING. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_history_event
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return an array of tokens, much as the shell might.  The tokens are    parsed out of STRING. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|history_tokenize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Exported history variables. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|history_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|history_length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_input_history
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|history_expansion_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|history_subst_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|history_comment_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|history_no_expand_chars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|history_search_delimiter_chars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|history_quotes_inhibit_expansion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If set, this function is called to decide whether or not a particular    history expansion should be treated as a special case for the calling    application and not expanded. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|history_inhibit_expansion_function
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HISTORY_H_ */
end_comment

end_unit

