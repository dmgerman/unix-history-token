begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gschar.h */
end_comment

begin_comment
comment|/* Character operations for Ghostscript library */
end_comment

begin_comment
comment|/* String display, like image display, uses an enumeration structure */
end_comment

begin_comment
comment|/* to keep track of what's going on (aka 'poor man's callback'). */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gs_show_enum_s
name|gs_show_enum
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|gs_show_enum_sizeof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The routines all come in two versions, */
end_comment

begin_comment
comment|/* one that uses the C convention of null-terminated strings, */
end_comment

begin_comment
comment|/* and one that supplies a length. */
end_comment

begin_decl_stmt
name|int
name|gs_show_init
argument_list|(
name|P3
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_show_n_init
argument_list|(
name|P4
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|gs_ashow_init
argument_list|(
name|P5
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_ashow_n_init
argument_list|(
name|P6
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|gs_widthshow_init
argument_list|(
name|P6
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_widthshow_n_init
argument_list|(
name|P7
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
argument_list|,
name|char
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|gs_awidthshow_init
argument_list|(
name|P8
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_awidthshow_n_init
argument_list|(
name|P9
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|char
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|gs_kshow_init
argument_list|(
name|P3
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_kshow_n_init
argument_list|(
name|P4
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|gs_stringwidth_init
argument_list|(
name|P3
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_stringwidth_n_init
argument_list|(
name|P4
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|,
name|gs_charpath_init
argument_list|(
name|P4
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|,
name|gs_charpath_n_init
argument_list|(
name|P5
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|uint
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After setting up the enumeration, all the string-related routines */
end_comment

begin_comment
comment|/* work the same way.  The client calls gs_show_next until it returns */
end_comment

begin_comment
comment|/* a zero (successful completion) or negative (error) value. */
end_comment

begin_comment
comment|/* Other values indicate the following situations: */
end_comment

begin_comment
comment|/* The client must render a character: obtain the code from */
end_comment

begin_comment
comment|/* gs_show_current_char, do whatever is necessary, and then */
end_comment

begin_comment
comment|/* call gs_show_next again. */
end_comment

begin_define
define|#
directive|define
name|gs_show_render
value|1
end_define

begin_comment
comment|/* The client has asked to intervene between characters (kshow). */
end_comment

begin_comment
comment|/* Obtain the previous and next codes from gs_kshow_previous_char */
end_comment

begin_comment
comment|/* and gs_kshow_next_char, do whatever is necessary, and then */
end_comment

begin_comment
comment|/* call gs_show_next again. */
end_comment

begin_define
define|#
directive|define
name|gs_show_kern
value|2
end_define

begin_comment
comment|/* Because of composite fonts, character codes must be 32 bits. */
end_comment

begin_typedef
typedef|typedef
name|ulong
name|char_code
typedef|;
end_typedef

begin_decl_stmt
name|int
name|gs_show_next
argument_list|(
name|P1
argument_list|(
name|gs_show_enum
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char_code
name|gs_show_current_char
argument_list|(
name|P1
argument_list|(
name|gs_show_enum
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_kshow_previous_char
argument_list|(
name|P1
argument_list|(
name|gs_show_enum
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_kshow_next_char
argument_list|(
name|P1
argument_list|(
name|gs_show_enum
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gs_show_width
argument_list|(
name|P2
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_point
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cumulative width */
end_comment

begin_decl_stmt
name|int
name|gs_show_in_charpath
argument_list|(
name|P1
argument_list|(
name|gs_show_enum
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return charpath flag */
end_comment

begin_comment
comment|/* Convert an image to an outline encoding. */
end_comment

begin_decl_stmt
name|int
name|gs_type1imagepath
argument_list|(
name|P10
argument_list|(
name|gs_state
operator|*
argument_list|,
specifier|const
name|byte
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Font cache and metrics operators */
end_comment

begin_decl_stmt
name|int
name|gs_setcachedevice
argument_list|(
name|P8
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setcharwidth
argument_list|(
name|P4
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setmetrics
argument_list|(
name|P4
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|gs_state
operator|*
argument_list|,
name|gs_point
operator|*
argument_list|,
name|gs_point
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

