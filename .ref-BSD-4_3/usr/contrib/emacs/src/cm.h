begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Cursor motion calculation definitions for GNU Emacs    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* This structure holds everything needed to do cursor motion except the pad    character (PC) and the output speed of the terminal (ospeed), which    termcap wants in global variables. */
end_comment

begin_struct
specifier|extern
struct|struct
name|cm
block|{
comment|/* Cursor position */
name|int
name|cm_curY
decl_stmt|,
comment|/* current row */
name|cm_curX
decl_stmt|;
comment|/* current column */
comment|/* -1 in either one means position unknown */
comment|/* Capabilities from termcap(5) (including extensions) */
name|char
modifier|*
name|cm_up
decl_stmt|,
comment|/* up (up) */
modifier|*
name|cm_down
decl_stmt|,
comment|/* down (do) */
modifier|*
name|cm_left
decl_stmt|,
comment|/* left (bs) */
modifier|*
name|cm_right
decl_stmt|,
comment|/* right (nd) */
modifier|*
name|cm_home
decl_stmt|,
comment|/* home (ho) */
modifier|*
name|cm_cr
decl_stmt|,
comment|/* carriage return (cr) */
modifier|*
name|cm_ll
decl_stmt|,
comment|/* last line (ll) */
modifier|*
name|cm_abs
decl_stmt|,
comment|/* absolute (cm) */
modifier|*
name|cm_habs
decl_stmt|,
comment|/* horizontal absolute (ch) */
modifier|*
name|cm_vabs
decl_stmt|,
comment|/* vertical absolute (cv) */
modifier|*
name|cm_ds
decl_stmt|,
comment|/* "don't send" string (ds) */
modifier|*
name|cm_tab
decl_stmt|;
comment|/* tab (ta) */
name|int
name|cm_tabwidth
decl_stmt|,
comment|/* tab width (tw) */
name|cm_cols
decl_stmt|,
comment|/* Number of cols on screen (co) */
name|cm_rows
decl_stmt|,
comment|/* Number of rows on screen (li) */
name|cm_autowrap
range|:
literal|1
decl_stmt|,
comment|/* autowrap flag (am) */
name|cm_magicwrap
range|:
literal|1
decl_stmt|,
comment|/* vt100s: cursor stays in last col but 				   will wrap if next char is printing (xn) */
name|cm_usetabs
range|:
literal|1
decl_stmt|,
comment|/* if set, use tabs */
name|cm_autolf
range|:
literal|1
decl_stmt|,
comment|/* \r performs a \r\n (rn) */
name|cm_losewrap
range|:
literal|1
decl_stmt|;
comment|/* if reach right margin, forget cursor location */
comment|/* Costs */
name|int
name|cc_up
decl_stmt|,
comment|/* cost for up */
name|cc_down
decl_stmt|,
comment|/* etc */
name|cc_left
decl_stmt|,
name|cc_right
decl_stmt|,
name|cc_home
decl_stmt|,
name|cc_cr
decl_stmt|,
name|cc_ll
decl_stmt|,
name|cc_abs
decl_stmt|,
comment|/* abs costs are actually min costs */
name|cc_habs
decl_stmt|,
name|cc_vabs
decl_stmt|,
name|cc_tab
decl_stmt|;
block|}
name|Wcm
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pad character */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output speed (from sg_ospeed) */
end_comment

begin_comment
comment|/* Shorthand */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NoCMShortHand
end_ifndef

begin_define
define|#
directive|define
name|curY
value|Wcm.cm_curY
end_define

begin_define
define|#
directive|define
name|curX
value|Wcm.cm_curX
end_define

begin_define
define|#
directive|define
name|Up
value|Wcm.cm_up
end_define

begin_define
define|#
directive|define
name|Down
value|Wcm.cm_down
end_define

begin_define
define|#
directive|define
name|Left
value|Wcm.cm_left
end_define

begin_define
define|#
directive|define
name|Right
value|Wcm.cm_right
end_define

begin_define
define|#
directive|define
name|Home
value|Wcm.cm_home
end_define

begin_define
define|#
directive|define
name|CR
value|Wcm.cm_cr
end_define

begin_define
define|#
directive|define
name|LastLine
value|Wcm.cm_ll
end_define

begin_define
define|#
directive|define
name|Tab
value|Wcm.cm_tab
end_define

begin_define
define|#
directive|define
name|TabWidth
value|Wcm.cm_tabwidth
end_define

begin_define
define|#
directive|define
name|DontSend
value|Wcm.cm_ds
end_define

begin_define
define|#
directive|define
name|AbsPosition
value|Wcm.cm_abs
end_define

begin_define
define|#
directive|define
name|ColPosition
value|Wcm.cm_habs
end_define

begin_define
define|#
directive|define
name|RowPosition
value|Wcm.cm_vabs
end_define

begin_define
define|#
directive|define
name|AutoWrap
value|Wcm.cm_autowrap
end_define

begin_define
define|#
directive|define
name|MagicWrap
value|Wcm.cm_magicwrap
end_define

begin_define
define|#
directive|define
name|UseTabs
value|Wcm.cm_usetabs
end_define

begin_define
define|#
directive|define
name|AutoLF
value|Wcm.cm_autolf
end_define

begin_define
define|#
directive|define
name|ScreenRows
value|Wcm.cm_rows
end_define

begin_define
define|#
directive|define
name|ScreenCols
value|Wcm.cm_cols
end_define

begin_define
define|#
directive|define
name|cmat
parameter_list|(
name|row
parameter_list|,
name|col
parameter_list|)
value|(curY = (row), curX = (col))
end_define

begin_define
define|#
directive|define
name|cmplus
parameter_list|(
name|n
parameter_list|)
value|{if ((curX += (n))>= ScreenCols&& !MagicWrap)\ 			   {if (Wcm.cm_losewrap) curY = -1; \ 			      else if (AutoWrap) curX = 0, curY++; else curX--;}}
end_define

begin_function_decl
specifier|extern
name|void
name|cmputc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

