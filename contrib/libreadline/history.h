begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* history.h -- the names of functions that you can call in history. */
end_comment

begin_comment
comment|/* Copyright (C) 1989-2003 Free Software Foundation, Inc.     This file contains the GNU History Library (the Library), a set of    routines for managing the text of previously typed lines.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<time.h>
comment|/* XXX - for history timestamp code */
if|#
directive|if
name|defined
name|READLINE_LIBRARY
include|#
directive|include
file|"rlstdc.h"
include|#
directive|include
file|"rltypedefs.h"
else|#
directive|else
include|#
directive|include
file|<readline/rlstdc.h>
include|#
directive|include
file|<readline/rltypedefs.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__STDC__
typedef|typedef
name|void
modifier|*
name|histdata_t
typedef|;
else|#
directive|else
typedef|typedef
name|char
modifier|*
name|histdata_t
typedef|;
endif|#
directive|endif
comment|/* The structure used to store a history entry. */
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
name|timestamp
decl_stmt|;
comment|/* char * rather than time_t for read/write */
name|histdata_t
name|data
decl_stmt|;
block|}
name|HIST_ENTRY
typedef|;
comment|/* Size of the history-library-managed space in history entry HS. */
define|#
directive|define
name|HISTENT_BYTES
parameter_list|(
name|hs
parameter_list|)
value|(strlen ((hs)->line) + strlen ((hs)->timestamp))
comment|/* A structure used to pass the current state of the history stuff around. */
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
comment|/* Flag values for the `flags' member of HISTORY_STATE. */
define|#
directive|define
name|HS_STIFLED
value|0x01
comment|/* Initialization and state management. */
comment|/* Begin a session in which the history functions might be used.  This    just initializes the interactive variables. */
specifier|extern
name|void
name|using_history
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the current HISTORY_STATE of the history. */
specifier|extern
name|HISTORY_STATE
modifier|*
name|history_get_history_state
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Set the state of the current history array to STATE. */
specifier|extern
name|void
name|history_set_history_state
name|PARAMS
argument_list|(
operator|(
name|HISTORY_STATE
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Manage the history list. */
comment|/* Place STRING at the end of the history list.    The associated data field (if any) is set to NULL. */
specifier|extern
name|void
name|add_history
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Change the timestamp associated with the most recent history entry to    STRING. */
specifier|extern
name|void
name|add_history_time
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* A reasonably useless function, only here for completeness.  WHICH    is the magic number that tells us which element to delete.  The    elements are numbered from 0. */
specifier|extern
name|HIST_ENTRY
modifier|*
name|remove_history
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Free the history entry H and return any application-specific data    associated with it. */
specifier|extern
name|histdata_t
name|free_history_entry
name|PARAMS
argument_list|(
operator|(
name|HIST_ENTRY
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Make the history entry at WHICH have LINE and DATA.  This returns    the old entry so you can dispose of the data.  In the case of an    invalid WHICH, a NULL pointer is returned. */
specifier|extern
name|HIST_ENTRY
modifier|*
name|replace_history_entry
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|histdata_t
operator|)
argument_list|)
decl_stmt|;
comment|/* Clear the history list and start over. */
specifier|extern
name|void
name|clear_history
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Stifle the history list, remembering only MAX number of entries. */
specifier|extern
name|void
name|stifle_history
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Stop stifling the history.  This returns the previous amount the    history was stifled by.  The value is positive if the history was    stifled, negative if it wasn't. */
specifier|extern
name|int
name|unstifle_history
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Return 1 if the history is stifled, 0 if it is not. */
specifier|extern
name|int
name|history_is_stifled
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Information about the history list. */
comment|/* Return a NULL terminated array of HIST_ENTRY which is the current input    history.  Element 0 of this list is the beginning of time.  If there    is no history, return NULL. */
specifier|extern
name|HIST_ENTRY
modifier|*
modifier|*
name|history_list
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Returns the number which says what history element we are now    looking at.  */
specifier|extern
name|int
name|where_history
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the history entry at the current position, as determined by    history_offset.  If there is no entry there, return a NULL pointer. */
specifier|extern
name|HIST_ENTRY
modifier|*
name|current_history
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the history entry which is logically at OFFSET in the history    array.  OFFSET is relative to history_base. */
specifier|extern
name|HIST_ENTRY
modifier|*
name|history_get
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the timestamp associated with the HIST_ENTRY * passed as an    argument */
specifier|extern
name|time_t
name|history_get_time
name|PARAMS
argument_list|(
operator|(
name|HIST_ENTRY
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the number of bytes that the primary history entries are using.    This just adds up the lengths of the_history->lines. */
specifier|extern
name|int
name|history_total_bytes
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Moving around the history list. */
comment|/* Set the position in the history list to POS. */
specifier|extern
name|int
name|history_set_pos
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Back up history_offset to the previous history entry, and return    a pointer to that entry.  If there is no previous entry, return    a NULL pointer. */
specifier|extern
name|HIST_ENTRY
modifier|*
name|previous_history
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Move history_offset forward to the next item in the input_history,    and return the a pointer to that entry.  If there is no next entry,    return a NULL pointer. */
specifier|extern
name|HIST_ENTRY
modifier|*
name|next_history
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Searching the history list. */
comment|/* Search the history for STRING, starting at history_offset.    If DIRECTION< 0, then the search is through previous entries,    else through subsequent.  If the string is found, then    current_history () is the history entry, and the value of this function    is the offset in the line of that history entry that the string was    found in.  Otherwise, nothing is changed, and a -1 is returned. */
specifier|extern
name|int
name|history_search
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Search the history for STRING, starting at history_offset.    The search is anchored: matching lines must begin with string.    DIRECTION is as in history_search(). */
specifier|extern
name|int
name|history_search_prefix
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Search for STRING in the history list, starting at POS, an    absolute index into the list.  DIR, if negative, says to search    backwards from POS, else forwards.    Returns the absolute index of the history element where STRING    was found, or -1 otherwise. */
specifier|extern
name|int
name|history_search_pos
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Managing the history file. */
comment|/* Add the contents of FILENAME to the history list, a line at a time.    If FILENAME is NULL, then read from ~/.history.  Returns 0 if    successful, or errno if not. */
specifier|extern
name|int
name|read_history
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Read a range of lines from FILENAME, adding them to the history list.    Start reading at the FROM'th line and end at the TO'th.  If FROM    is zero, start at the beginning.  If TO is less than FROM, read    until the end of the file.  If FILENAME is NULL, then read from    ~/.history.  Returns 0 if successful, or errno if not. */
specifier|extern
name|int
name|read_history_range
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Write the current history to FILENAME.  If FILENAME is NULL,    then write the history list to ~/.history.  Values returned    are as in read_history ().  */
specifier|extern
name|int
name|write_history
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Append NELEMENT entries to FILENAME.  The entries appended are from    the end of the list minus NELEMENTs up to the end of the list. */
specifier|extern
name|int
name|append_history
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Truncate the history file, leaving only the last NLINES lines. */
specifier|extern
name|int
name|history_truncate_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* History expansion. */
comment|/* Expand the string STRING, placing the result into OUTPUT, a pointer    to a string.  Returns:     0) If no expansions took place (or, if the only change in       the text was the de-slashifying of the history expansion       character)    1) If expansions did take place   -1) If there was an error in expansion.    2) If the returned line should just be printed.    If an error ocurred in expansion, then OUTPUT contains a descriptive   error message. */
specifier|extern
name|int
name|history_expand
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Extract a string segment consisting of the FIRST through LAST    arguments present in STRING.  Arguments are broken up as in    the shell. */
specifier|extern
name|char
modifier|*
name|history_arg_extract
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Return the text of the history event beginning at the current    offset into STRING.  Pass STRING with *INDEX equal to the    history_expansion_char that begins this specification.    DELIMITING_QUOTE is a character that is allowed to end the string    specification for what to search for in addition to the normal    characters `:', ` ', `\t', `\n', and sometimes `?'. */
specifier|extern
name|char
modifier|*
name|get_history_event
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Return an array of tokens, much as the shell might.  The tokens are    parsed out of STRING. */
specifier|extern
name|char
modifier|*
modifier|*
name|history_tokenize
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Exported history variables. */
specifier|extern
name|int
name|history_base
decl_stmt|;
specifier|extern
name|int
name|history_length
decl_stmt|;
specifier|extern
name|int
name|history_max_entries
decl_stmt|;
specifier|extern
name|char
name|history_expansion_char
decl_stmt|;
specifier|extern
name|char
name|history_subst_char
decl_stmt|;
specifier|extern
name|char
modifier|*
name|history_word_delimiters
decl_stmt|;
specifier|extern
name|char
name|history_comment_char
decl_stmt|;
specifier|extern
name|char
modifier|*
name|history_no_expand_chars
decl_stmt|;
specifier|extern
name|char
modifier|*
name|history_search_delimiter_chars
decl_stmt|;
specifier|extern
name|int
name|history_quotes_inhibit_expansion
decl_stmt|;
specifier|extern
name|int
name|history_write_timestamps
decl_stmt|;
comment|/* Backwards compatibility */
specifier|extern
name|int
name|max_input_history
decl_stmt|;
comment|/* If set, this function is called to decide whether or not a particular    history expansion should be treated as a special case for the calling    application and not expanded. */
specifier|extern
name|rl_linebuf_func_t
modifier|*
name|history_inhibit_expansion_function
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HISTORY_H_ */
end_comment

end_unit

