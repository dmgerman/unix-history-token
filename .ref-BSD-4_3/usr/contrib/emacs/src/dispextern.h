begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface definitions for display code.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
comment|/* Desired terminal cursor position (to show position of dot),  origin one */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cursX
decl_stmt|,
name|cursY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means last display completed and cursor is really at cursX, cursY.  Zero means it was preempted. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|display_completed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display line structure. This structure records the contents of a line either as already on the display or as we desire to have it on the display.  PhysScreen is a vector of pointers to lines  describing the actual contents of the screen. DesiredScreen is a vector of pointers to lines  describing what we want to put on the screen.  These were made from the buffers being displayed  by the file window.c  The code in this file compares those two vectors of display lines  and performs the updating.  As display lines are used only to go in those vectors,  the most display lines that ever ought to exist is  twice the maximum screen size.  That many are created  initially and put in a pool.  If the pool is ever empty  and a line is needed, that indicates a bug. */
end_comment

begin_struct
struct|struct
name|display_line
block|{
name|struct
name|display_line
modifier|*
name|next
decl_stmt|;
comment|/* Chain for free lines. */
name|short
name|length
decl_stmt|;
comment|/* the number of valid characters in body */
name|char
name|highlighted
decl_stmt|;
comment|/* 1 means write this line in standout mode */
name|char
name|physical
decl_stmt|;
comment|/* Mark bit for gc'ing, in update_screen */
name|char
name|body
index|[
name|MScreenWidth
operator|+
literal|4
index|]
decl_stmt|;
comment|/* the actual text of the line */
block|}
struct|;
end_struct

begin_comment
comment|/* Allocate a line structure for screen line `vpos' (origin 0)  to start output in it at `hpos' (origin 0, may be negative) */
end_comment

begin_decl_stmt
name|struct
name|display_line
modifier|*
name|get_display_line
argument_list|()
decl_stmt|,
modifier|*
name|new_display_line
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

