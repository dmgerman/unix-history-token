begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface definitions for display code.    Copyright (C) 1985, 1990 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Nonzero means do not assume anything about current  contents of actual terminal screen */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|screen_garbaged
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Desired terminal cursor position (to show position of point),  origin zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cursor_hpos
decl_stmt|,
name|cursor_vpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means last display completed    and cursor is really at cursor_hpos, cursor_vpos.    Zero means it was preempted. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|display_completed
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|matrix
block|{
comment|/* Height of this matrix.  */
name|int
name|height
decl_stmt|;
comment|/* Width of this matrix.  */
name|int
name|width
decl_stmt|;
comment|/* Vector of used widths of lines, indexed by vertical position.  */
name|int
modifier|*
name|used
decl_stmt|;
comment|/* Vector of line contents.      m->contents[V][H] is the character at position V, H.      Note that ->contents[...][screen_width] is always 0      and so is ->contents[...][-1].  */
name|unsigned
name|char
modifier|*
modifier|*
name|contents
decl_stmt|;
comment|/* Long vector from which the line contents are taken.  */
name|unsigned
name|char
modifier|*
name|total_contents
decl_stmt|;
comment|/* Vector indicating, for each line, whether it is highlighted.  */
name|char
modifier|*
name|highlight
decl_stmt|;
comment|/* Vector indicating, for each line, whether its contents mean anything.  */
name|char
modifier|*
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Current screen contents.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|matrix
modifier|*
name|current_screen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Screen contents to be displayed.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|matrix
modifier|*
name|new_screen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporary buffer for screen contents.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|matrix
modifier|*
name|temp_screen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get ready to display on screen line VPOS at column HPOS    and return the string where the text of that line is stored.  */
end_comment

begin_function_decl
name|unsigned
name|char
modifier|*
name|get_display_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Buffer used by `message' for formatting a message, and by print.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|message_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All costs measured in characters.    So no cost can exceed the area of a screen, measured in characters.    This should not be more than million.    Meanwhile, we can add lots of millions together without overflow.  */
end_comment

begin_define
define|#
directive|define
name|INFINITY
value|1000000
end_define

end_unit

