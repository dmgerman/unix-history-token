begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* window.h -- Structure and flags used in manipulating Info windows.    $Id: window.h,v 1.4 1997/07/15 18:45:47 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 97 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_WINDOW_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_WINDOW_H
end_define

begin_include
include|#
directive|include
file|"nodes.h"
end_include

begin_include
include|#
directive|include
file|"infomap.h"
end_include

begin_comment
comment|/* Smallest number of visible lines in a window.  The actual height is    always one more than this number because each window has a modeline. */
end_comment

begin_define
define|#
directive|define
name|WINDOW_MIN_HEIGHT
value|2
end_define

begin_comment
comment|/* Smallest number of screen lines that can be used to fully present a    window.  This number includes the modeline of the window. */
end_comment

begin_define
define|#
directive|define
name|WINDOW_MIN_SIZE
value|(WINDOW_MIN_HEIGHT + 1)
end_define

begin_comment
comment|/* The exact same elements are used within the WINDOW_STATE structure and a    subsection of the WINDOW structure.  We could define a structure which    contains this elements, and include that structure in each of WINDOW_STATE    and WINDOW.  But that would lead references in the code such as    window->state->node which we would like to avoid.  Instead, we #define the    elements here, and simply include the define in both data structures. Thus,    if you need to change window state information, here is where you would    do it.  NB> The last element does NOT end with a semi-colon. */
end_comment

begin_define
define|#
directive|define
name|WINDOW_STATE_DECL
define|\
value|NODE *node;
comment|/* The node displayed in this window. */
value|\    int pagetop;
comment|/* LINE_STARTS[PAGETOP] is first line in WINDOW. */
value|\    long point
end_define

begin_comment
comment|/* Offset within NODE of the cursor position. */
end_comment

begin_comment
comment|/* Structure which defines a window.  Windows are doubly linked, next    and prev. The list of windows is kept on WINDOWS.  The structure member    window->height is the total height of the window.  The position location    (0, window->height + window->first_row) is the first character of this    windows modeline.  The number of lines that can be displayed in a window    is equal to window->height - 1. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|window_struct
block|{
name|struct
name|window_struct
modifier|*
name|next
decl_stmt|;
comment|/* Next window in this chain. */
name|struct
name|window_struct
modifier|*
name|prev
decl_stmt|;
comment|/* Previous window in this chain. */
name|int
name|width
decl_stmt|;
comment|/* Width of this window. */
name|int
name|height
decl_stmt|;
comment|/* Height of this window. */
name|int
name|first_row
decl_stmt|;
comment|/* Offset of the first line in the_screen. */
name|int
name|goal_column
decl_stmt|;
comment|/* The column we would like the cursor to appear in. */
name|Keymap
name|keymap
decl_stmt|;
comment|/* Keymap used to read commands in this window. */
name|WINDOW_STATE_DECL
expr_stmt|;
comment|/* Node, pagetop and point. */
name|char
modifier|*
name|modeline
decl_stmt|;
comment|/* Calculated text of the modeline for this window. */
name|char
modifier|*
modifier|*
name|line_starts
decl_stmt|;
comment|/* Array of printed line starts for this node. */
name|int
name|line_count
decl_stmt|;
comment|/* Number of lines appearing in LINE_STARTS. */
name|int
name|flags
decl_stmt|;
comment|/* See below for details. */
block|}
name|WINDOW
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|WINDOW_STATE_DECL
expr_stmt|;
comment|/* What gets saved. */
block|}
name|WINDOW_STATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|W_UpdateWindow
value|0x01
end_define

begin_comment
comment|/* WINDOW needs updating. */
end_comment

begin_define
define|#
directive|define
name|W_WindowIsPerm
value|0x02
end_define

begin_comment
comment|/* This WINDOW is a permanent object. */
end_comment

begin_define
define|#
directive|define
name|W_WindowVisible
value|0x04
end_define

begin_comment
comment|/* This WINDOW is currently visible. */
end_comment

begin_define
define|#
directive|define
name|W_InhibitMode
value|0x08
end_define

begin_comment
comment|/* This WINDOW has no modeline. */
end_comment

begin_define
define|#
directive|define
name|W_NoWrap
value|0x10
end_define

begin_comment
comment|/* Lines do not wrap in this window. */
end_comment

begin_define
define|#
directive|define
name|W_InputWindow
value|0x20
end_define

begin_comment
comment|/* Window accepts input. */
end_comment

begin_define
define|#
directive|define
name|W_TempWindow
value|0x40
end_define

begin_comment
comment|/* Window is less important. */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|windows
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of visible Info windows. */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|active_window
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The currently active window. */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|the_screen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The Info screen is just another window. */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|the_echo_area
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* THE_ECHO_AREA is a window in THE_SCREEN. */
end_comment

begin_comment
comment|/* Global variable control redisplay of scrolled windows.  If non-zero, it    is the desired number of lines to scroll the window in order to make    point visible.  A user might set this to 1 for smooth scrolling.  If    set to zero, the line containing point is centered within the window. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|window_scroll_step
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make the modeline member for WINDOW. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_make_modeline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Initalize the window system by creating THE_SCREEN and THE_ECHO_AREA.    Create the first window ever, and make it permanent.    You pass WIDTH and HEIGHT; the dimensions of the total screen size. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_initialize_windows
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make a new window showing NODE, and return that window structure.    The new window is made to be the active window.  If NODE is passed    as NULL, then show the node showing in the active window.  If the    window could not be made return a NULL pointer.  The active window    is not changed.*/
end_comment

begin_function_decl
specifier|extern
name|WINDOW
modifier|*
name|window_make_window
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Delete WINDOW from the list of known windows.  If this window was the    active window, make the next window in the chain be the active window,    or the previous window in the chain if there is no next window. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_delete_window
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A function to call when the screen changes size, and some windows have    to get deleted.  The function is called with the window to be deleted    as an argument, and it can't do anything about the window getting deleted;    it can only clean up dangling references to that window. */
end_comment

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|window_deletion_notifier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set WINDOW to display NODE. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_set_node_of_window
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Tell the window system that the size of the screen has changed.  This    causes lots of interesting things to happen.  The permanent windows    are resized, as well as every visible window.  You pass WIDTH and HEIGHT;    the dimensions of the total screen size. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_new_screen_size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Change the height of WINDOW by AMOUNT.  This also automagically adjusts    the previous and next windows in the chain.  If there is only one user    window, then no change takes place. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_change_window_height
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Adjust the pagetop of WINDOW such that the cursor point will be visible. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_adjust_pagetop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Tile all of the windows currently displayed in the global variable    WINDOWS.  If argument DO_INTERNALS is non-zero, tile windows displaying    internal nodes as well. */
end_comment

begin_define
define|#
directive|define
name|DONT_TILE_INTERNALS
value|0
end_define

begin_define
define|#
directive|define
name|TILE_INTERNALS
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|window_tile_windows
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Toggle the state of line wrapping in WINDOW.  This can do a bit of fancy    redisplay. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_toggle_wrap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* For every window in CHAIN, set the flags member to have FLAG set. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_mark_chain
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* For every window in CHAIN, clear the flags member of FLAG. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_unmark_chain
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make WINDOW start displaying at PERCENT percentage of its node. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_goto_percentage
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Build a new node which has FORMAT printed with ARG1 and ARG2 as the    contents. */
end_comment

begin_function_decl
specifier|extern
name|NODE
modifier|*
name|build_message_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Useful functions can be called from outside of window.c. */
end_comment

begin_function_decl
specifier|extern
name|void
name|initialize_message_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Print FORMAT with ARG1,2 to the end of the current message buffer. */
end_comment

begin_function_decl
specifier|extern
name|void
name|printf_to_message_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Convert the contents of the message buffer to a node. */
end_comment

begin_function_decl
specifier|extern
name|NODE
modifier|*
name|message_buffer_to_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the length of the most recently printed line in message buffer. */
end_comment

begin_function_decl
specifier|extern
name|int
name|message_buffer_length_this_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Pad STRING to COUNT characters by inserting blanks. */
end_comment

begin_function_decl
specifier|extern
name|int
name|pad_to
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make a message appear in the echo area, built from FORMAT, ARG1 and ARG2.    The arguments are treated similar to printf () arguments, but not all of    printf () hair is present.  The message appears immediately.  If there was    already a message appearing in the echo area, it is removed. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_message_in_echo_area
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Place a temporary message in the echo area built from FORMAT, ARG1    and ARG2.  The message appears immediately, but does not destroy    any existing message.  A future call to unmessage_in_echo_area ()    restores the old contents. */
end_comment

begin_function_decl
specifier|extern
name|void
name|message_in_echo_area
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unmessage_in_echo_area
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Clear the echo area, removing any message that is already present.    The echo area is cleared immediately. */
end_comment

begin_function_decl
specifier|extern
name|void
name|window_clear_echo_area
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Quickly guess the approximate number of lines to that NODE would    take to display.  This really only counts carriage returns. */
end_comment

begin_function_decl
specifier|extern
name|int
name|window_physical_lines
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Calculate a list of line starts for the node belonging to WINDOW.  The line    starts are pointers to the actual text within WINDOW->NODE. */
end_comment

begin_function_decl
specifier|extern
name|void
name|calculate_line_starts
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given WINDOW, recalculate the line starts for the node it displays. */
end_comment

begin_function_decl
specifier|extern
name|void
name|recalculate_line_starts
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of characters it takes to display CHARACTER on the    screen at HPOS. */
end_comment

begin_function_decl
specifier|extern
name|int
name|character_width
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of characters it takes to display STRING on the    screen at HPOS. */
end_comment

begin_function_decl
specifier|extern
name|int
name|string_width
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the index of the line containing point. */
end_comment

begin_function_decl
specifier|extern
name|int
name|window_line_of_point
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get and return the goal column for this window. */
end_comment

begin_function_decl
specifier|extern
name|int
name|window_get_goal_column
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get and return the printed column offset of the cursor in this window. */
end_comment

begin_function_decl
specifier|extern
name|int
name|window_get_cursor_column
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get and Set the node, pagetop, and point of WINDOW. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|window_get_state
argument_list|()
decl_stmt|,
name|window_set_state
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count the number of characters in LINE that precede the printed column    offset of GOAL. */
end_comment

begin_function_decl
specifier|extern
name|int
name|window_chars_to_goal
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_WINDOW_H */
end_comment

end_unit

