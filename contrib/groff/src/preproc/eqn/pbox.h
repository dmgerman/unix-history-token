begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fat_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|over_hang
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|accent_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|delimiter_factor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|delimiter_shortfall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|null_delimiter_space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|script_space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|thin_space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|medium_space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|thick_space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// we don't use num3, because we don't have \atop
end_comment

begin_decl_stmt
specifier|extern
name|int
name|denom1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|denom2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|axis_height
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sup1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sup2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sup3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|default_rule_thickness
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sub1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sub2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sup_drop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sub_drop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x_height
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|big_op_spacing1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|big_op_spacing2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|big_op_spacing3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|big_op_spacing4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|big_op_spacing5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|baseline_sep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|shift_down
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|column_sep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|matrix_side_sep
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ms.eqn relies on this!
end_comment

begin_define
define|#
directive|define
name|LINE_STRING
value|"10"
end_define

begin_define
define|#
directive|define
name|MARK_OR_LINEUP_FLAG_REG
value|"MK"
end_define

begin_define
define|#
directive|define
name|WIDTH_FORMAT
value|PREFIX "w%d"
end_define

begin_define
define|#
directive|define
name|HEIGHT_FORMAT
value|PREFIX "h%d"
end_define

begin_define
define|#
directive|define
name|DEPTH_FORMAT
value|PREFIX "d%d"
end_define

begin_define
define|#
directive|define
name|TOTAL_FORMAT
value|PREFIX "t%d"
end_define

begin_define
define|#
directive|define
name|SIZE_FORMAT
value|PREFIX "z%d"
end_define

begin_define
define|#
directive|define
name|SMALL_SIZE_FORMAT
value|PREFIX "Z%d"
end_define

begin_define
define|#
directive|define
name|SUP_RAISE_FORMAT
value|PREFIX "p%d"
end_define

begin_define
define|#
directive|define
name|SUB_LOWER_FORMAT
value|PREFIX "b%d"
end_define

begin_define
define|#
directive|define
name|SUB_KERN_FORMAT
value|PREFIX "k%d"
end_define

begin_define
define|#
directive|define
name|FONT_FORMAT
value|PREFIX "f%d"
end_define

begin_define
define|#
directive|define
name|SKEW_FORMAT
value|PREFIX "s%d"
end_define

begin_define
define|#
directive|define
name|LEFT_WIDTH_FORMAT
value|PREFIX "lw%d"
end_define

begin_define
define|#
directive|define
name|LEFT_DELIM_STRING_FORMAT
value|PREFIX "l%d"
end_define

begin_define
define|#
directive|define
name|RIGHT_DELIM_STRING_FORMAT
value|PREFIX "r%d"
end_define

begin_define
define|#
directive|define
name|SQRT_STRING_FORMAT
value|PREFIX "sqr%d"
end_define

begin_define
define|#
directive|define
name|SQRT_WIDTH_FORMAT
value|PREFIX "sq%d"
end_define

begin_define
define|#
directive|define
name|BASELINE_SEP_FORMAT
value|PREFIX "bs%d"
end_define

begin_comment
comment|// this needs two parameters, the uid and the column index
end_comment

begin_define
define|#
directive|define
name|COLUMN_WIDTH_FORMAT
value|PREFIX "cw%d,%d"
end_define

begin_define
define|#
directive|define
name|BAR_STRING
value|PREFIX "sqb"
end_define

begin_define
define|#
directive|define
name|TEMP_REG
value|PREFIX "temp"
end_define

begin_define
define|#
directive|define
name|MARK_REG
value|PREFIX "mark"
end_define

begin_define
define|#
directive|define
name|MARK_WIDTH_REG
value|PREFIX "mwidth"
end_define

begin_define
define|#
directive|define
name|SAVED_MARK_REG
value|PREFIX "smark"
end_define

begin_define
define|#
directive|define
name|MAX_SIZE_REG
value|PREFIX "mxsz"
end_define

begin_define
define|#
directive|define
name|REPEAT_APPEND_STRING_MACRO
value|PREFIX "ras"
end_define

begin_define
define|#
directive|define
name|TOP_HEIGHT_REG
value|PREFIX "th"
end_define

begin_define
define|#
directive|define
name|TOP_DEPTH_REG
value|PREFIX "td"
end_define

begin_define
define|#
directive|define
name|MID_HEIGHT_REG
value|PREFIX "mh"
end_define

begin_define
define|#
directive|define
name|MID_DEPTH_REG
value|PREFIX "md"
end_define

begin_define
define|#
directive|define
name|BOT_HEIGHT_REG
value|PREFIX "bh"
end_define

begin_define
define|#
directive|define
name|BOT_DEPTH_REG
value|PREFIX "bd"
end_define

begin_define
define|#
directive|define
name|EXT_HEIGHT_REG
value|PREFIX "eh"
end_define

begin_define
define|#
directive|define
name|EXT_DEPTH_REG
value|PREFIX "ed"
end_define

begin_define
define|#
directive|define
name|TOTAL_HEIGHT_REG
value|PREFIX "tot"
end_define

begin_define
define|#
directive|define
name|DELTA_REG
value|PREFIX "delta"
end_define

begin_define
define|#
directive|define
name|DELIM_STRING
value|PREFIX "delim"
end_define

begin_define
define|#
directive|define
name|DELIM_WIDTH_REG
value|PREFIX "dwidth"
end_define

begin_define
define|#
directive|define
name|SAVED_FONT_REG
value|PREFIX "sfont"
end_define

begin_define
define|#
directive|define
name|SAVED_PREV_FONT_REG
value|PREFIX "spfont"
end_define

begin_define
define|#
directive|define
name|SAVED_INLINE_FONT_REG
value|PREFIX "sifont"
end_define

begin_define
define|#
directive|define
name|SAVED_INLINE_PREV_FONT_REG
value|PREFIX "sipfont"
end_define

begin_define
define|#
directive|define
name|SAVED_SIZE_REG
value|PREFIX "ssize"
end_define

begin_define
define|#
directive|define
name|SAVED_INLINE_SIZE_REG
value|PREFIX "sisize"
end_define

begin_define
define|#
directive|define
name|SAVED_INLINE_PREV_SIZE_REG
value|PREFIX "sipsize"
end_define

begin_define
define|#
directive|define
name|SAVE_FONT_STRING
value|PREFIX "sfont"
end_define

begin_define
define|#
directive|define
name|RESTORE_FONT_STRING
value|PREFIX "rfont"
end_define

begin_define
define|#
directive|define
name|INDEX_REG
value|PREFIX "i"
end_define

begin_define
define|#
directive|define
name|TEMP_MACRO
value|PREFIX "tempmac"
end_define

begin_define
define|#
directive|define
name|DELIMITER_CHAR
value|"\\(EQ"
end_define

begin_decl_stmt
specifier|const
name|int
name|CRAMPED_SCRIPT_STYLE
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|SCRIPT_STYLE
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|CRAMPED_DISPLAY_STYLE
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|DISPLAY_STYLE
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|script_style
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cramped_style
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|int
name|ORDINARY_TYPE
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|OPERATOR_TYPE
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|BINARY_TYPE
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|RELATION_TYPE
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|OPENING_TYPE
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|CLOSING_TYPE
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|PUNCTUATION_TYPE
init|=
literal|6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|INNER_TYPE
init|=
literal|7
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|SUPPRESS_TYPE
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_script_size
parameter_list|()
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|HINT_PREV_IS_ITALIC
init|=
literal|01
block|,
name|HINT_NEXT_IS_ITALIC
init|=
literal|02
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|current_roman_font
decl_stmt|;
end_decl_stmt

end_unit

