begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Flags and parameters describing terminal's characteristics.    Copyright (C) 1985, 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|baud_rate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output speed in baud */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|screen_width
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of usable columns */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|screen_height
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|must_write_spaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means spaces in the text 				   must actually be output; can't just skip 				   over some columns to leave them blank.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|min_padding_speed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Speed below which no padding necessary */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fast_clear_end_of_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means terminal has command for this */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|line_ins_del_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal can insert and delete lines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|char_ins_del_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal can insert and delete chars */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|scroll_region_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal supports setting the scroll window */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|memory_below_screen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal remembers lines scrolled off bottom */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fast_clear_end_of_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal has a `ce' string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dont_calculate_costs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't bother computing */
end_comment

begin_comment
comment|/* various cost tables; we won't use them.  */
end_comment

begin_comment
comment|/* Nonzero means no need to redraw the entire screen on resuming    a suspended Emacs.  This is useful on terminals with multiple pages,    where one page is used for Emacs and another for all else. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|no_redraw_on_reenter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DCICcost[n] is cost of inserting N characters.    DCICcost[-n] is cost of deleting N characters. */
end_comment

begin_define
define|#
directive|define
name|DCICcost
value|(&DC_ICcost[screen_width])
end_define

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|DC_ICcost
decl_stmt|;
end_decl_stmt

end_unit

