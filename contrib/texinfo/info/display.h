begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* display.h -- How the display in Info is done.    $Id: display.h,v 1.2 1997/07/15 18:37:29 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 97 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_DISPLAY_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_DISPLAY_H
end_define

begin_include
include|#
directive|include
file|"info-utils.h"
end_include

begin_include
include|#
directive|include
file|"terminal.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|text
decl_stmt|;
comment|/* Text of the line as it appears. */
name|int
name|textlen
decl_stmt|;
comment|/* Printable Length of TEXT. */
name|int
name|inverse
decl_stmt|;
comment|/* Non-zero means this line is inverse. */
block|}
name|DISPLAY_LINE
typedef|;
end_typedef

begin_comment
comment|/* An array of display lines which tell us what is currently visible on    the display.  */
end_comment

begin_decl_stmt
specifier|extern
name|DISPLAY_LINE
modifier|*
modifier|*
name|the_display
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means do no output. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|display_inhibited
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if we didn't completely redisplay a window. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|display_was_interrupted_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize THE_DISPLAY to WIDTH and HEIGHT, with nothing in it. */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_initialize_display
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Clear all of the lines in DISPLAY making the screen blank. */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_clear_display
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Update the windows pointed to by WINDOWS in THE_DISPLAY.  This actually    writes the text on the screen. */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_update_display
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Display WIN on THE_DISPLAY.  Unlike display_update_display (), this    function only does one window. */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_update_one_window
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Move the screen cursor to directly over the current character in WINDOW. */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_cursor_at_point
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Scroll the region of the_display starting at START, ending at END, and    moving the lines AMOUNT lines.  If AMOUNT is less than zero, the lines    are moved up in the screen, otherwise down.  Actually, it is possible    for no scrolling to take place in the case that the terminal doesn't    support it.  This doesn't matter to us. */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_scroll_display
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Try to scroll lines in WINDOW.  OLD_PAGETOP is the pagetop of WINDOW before    having had its line starts recalculated.  OLD_STARTS is the list of line    starts that used to appear in this window.  OLD_COUNT is the number of lines    that appear in the OLD_STARTS array. */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_scroll_line_starts
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_DISPLAY_H */
end_comment

end_unit

