begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Flags and parameters describing terminal's characteristics.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
comment|/* DCICcost[n] is cost of inserting N characters.    DCICcost[-n] is cost of deleting N characters. */
end_comment

begin_define
define|#
directive|define
name|DCICcost
value|(&DC_ICcost[MScreenWidth])
end_define

begin_decl_stmt
specifier|extern
name|int
name|DC_ICcost
index|[
literal|1
operator|+
literal|2
operator|*
name|MScreenWidth
index|]
decl_stmt|;
end_decl_stmt

end_unit

