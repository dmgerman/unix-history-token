begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Window definitions for GNU Emacs.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* Windows are allocated as if they were vectors, but then the Lisp data type is changed to Lisp_Window.  They are garbage collected along with the vectors.  All windows in use are arranged into a tree, with pointers up and down.  Windows that are leaves of the tree are actually displayed and show the contents of buffers.  Windows that are not leaves are used for representing the way groups of leaf windows are arranged on the screen.  Leaf windows never become non-leaves. They are deleted only by calling delete-window on them (but this can be done implicitly).  Combination windows can be created and deleted at any time.  A leaf window has a non-nil buffer field, and also  has markers in its start and pointm fields.  Non-leaf windows  have nil in these fields.  Non-leaf windows are either vertical or horizontal combinations.  A vertical combination window has children that are arranged one above the next.  Its vchild field points to the uppermost child. The parent field of each of the children points to the vertical combination window.  The next field of each child points to the child below it, or is nil for the lowest child.  The prev field or each child points to the child above it, or is nil for the highest child.  A horizontal combination window has children that are side by side. Its hchild field points to the leftmost child.  In each child the next field points to the child to the right and the prev field points to the child to the left.  The children of a vertical combination window may be leaf windows or horizontal combination windows.  The children of a horizontal combination window may be leaf windows or vertical combination windows.  At the top of the tree are two windows which have nil as parent. The second of these is minibuf_window.  The first one manages all the screen area that is not minibuffer, and is called the root window. Different windows can be the root at different times; initially the root window is a leaf window, but if more windows are created then that leaf window ceases to be root and a newly made combination window becomes root instead.  In any case, prev of the minibuf window is the root window and next of the root window is the minibuf window.  To find the root window at any time, do XWINDOW (minibuf_window)->prev.  */
end_comment

begin_struct
struct|struct
name|window
block|{
comment|/* The first two fields are really the header of a vector */
comment|/* The window code does not refer to them.  */
name|int
name|size
decl_stmt|;
name|struct
name|Lisp_Vector
modifier|*
name|vec_next
decl_stmt|;
comment|/* Following child (to right or down) at same level of tree */
name|Lisp_Object
name|next
decl_stmt|;
comment|/* Preceding child (to left or up) at same level of tree */
name|Lisp_Object
name|prev
decl_stmt|;
comment|/* First child of this window. */
comment|/* vchild is used if this is a vertical combination,        hchild if this is a horizontal combination. */
name|Lisp_Object
name|hchild
decl_stmt|,
name|vchild
decl_stmt|;
comment|/* The window this one is a child of. */
name|Lisp_Object
name|parent
decl_stmt|;
comment|/* The upper left corner coordinates of this window,        as integers relative to upper left corner of screen = 0, 0 */
name|Lisp_Object
name|left
decl_stmt|;
name|Lisp_Object
name|top
decl_stmt|;
comment|/* The size of the window */
name|Lisp_Object
name|height
decl_stmt|;
name|Lisp_Object
name|width
decl_stmt|;
comment|/* The buffer displayed in this window */
comment|/* Of the fields vchild, hchild and buffer, only one is non-nil.  */
name|Lisp_Object
name|buffer
decl_stmt|;
comment|/* A marker pointing to where in the text to start displaying */
name|Lisp_Object
name|start
decl_stmt|;
comment|/* A marker pointing to where in the text point is in this window,        used only when the window is not selected.        This exists so that when multiple windows show one buffer        each one can have its own value of point.  */
name|Lisp_Object
name|pointm
decl_stmt|;
comment|/* Non-nil means next redisplay must use the value of start        set up for it in advance.  Set by scrolling commands.  */
name|Lisp_Object
name|force_start
decl_stmt|;
comment|/* Number of columns display within the window is scrolled to the left.        Currently always zero since this is not implemented.  */
name|Lisp_Object
name|hscroll
decl_stmt|;
comment|/* Number saying how recently window was selected */
name|Lisp_Object
name|use_time
decl_stmt|;
comment|/* Unique number of window assigned when it was created */
name|Lisp_Object
name|sequence_number
decl_stmt|;
comment|/* No permanent meaning; used by save-window-excursion's bookkeeping */
name|Lisp_Object
name|temslot
decl_stmt|;
comment|/* text.modified of displayed buffer as of last time display completed */
name|Lisp_Object
name|last_modified
decl_stmt|;
comment|/* Value of point at that time */
name|Lisp_Object
name|last_point
decl_stmt|;
comment|/* The rest are currently not used or only half used */
comment|/* Screen coords of point at that time */
name|Lisp_Object
name|last_point_x
decl_stmt|;
name|Lisp_Object
name|last_point_y
decl_stmt|;
comment|/* Screen coords of mark as of last time display completed */
comment|/* May be nil if mark does not exist or was not on screen */
name|Lisp_Object
name|last_mark_x
decl_stmt|;
name|Lisp_Object
name|last_mark_y
decl_stmt|;
comment|/* Number of characters in buffer past bottom of window,        as of last redisplay that finished. */
name|Lisp_Object
name|window_end_pos
decl_stmt|;
comment|/* Vertical position (relative to window top) of that buffer position        of the first of those characters */
name|Lisp_Object
name|window_end_vpos
decl_stmt|;
comment|/* Non-nil means must regenerate mode line of this window */
name|Lisp_Object
name|redo_mode_line
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the window which displays the minibuffer. It is always the same window.  */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|minibuf_window
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the window in which the terminal's cursor should  be left when nothing is being done with it.  This must  always be a leaf window, and its buffer is selected by  the top level editing loop at the end of each command.  */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|selected_window
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|new_windows
value|1
end_define

begin_function_decl
name|Lisp_Object
name|Fnext_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Lisp_Object
name|Fselect_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Lisp_Object
name|Fdisplay_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Lisp_Object
name|Fshow_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|minibuf_prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prompt to display in front of the minibuffer contents */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|minibuf_message
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Message to display instead of minibuffer contents */
end_comment

begin_comment
comment|/* This is what the functions error and message make, */
end_comment

begin_comment
comment|/* and command echoing uses it as well. */
end_comment

begin_comment
comment|/* It overrides the minibuf_prompt as well as the buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|RecurseDepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Depth in recursive edits */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MinibufDepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Depth in minibuffer invocations */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|RedoModes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true iff we should redraw the mode lines 				   on the next redisplay */
end_comment

begin_comment
comment|/* Minimum value of bf_s1 since last redisplay that finished.  Valid for current buffer unless Cant1WinOpt is nonzero. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|beg_unchanged
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minimum value of bf_s2 since last redisplay that finished.  Valid for current buffer unless Cant1WinOpt is nonzero. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|end_unchanged
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bf_modified as of last redisplay that finished;  if it matches bf_modified, beg_unchanged and end_unchanged  contain no useful information */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unchanged_modified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if head_clip or tail_clip of current buffer has changed  since last redisplay that finished */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|clip_changed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if window sizes or contents have changed  since last redisplay that finished */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|windows_or_buffers_changed
decl_stmt|;
end_decl_stmt

end_unit

