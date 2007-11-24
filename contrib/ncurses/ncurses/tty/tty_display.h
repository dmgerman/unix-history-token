begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ************************************************************************** */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TTY_DISPLAY_H
end_ifndef

begin_define
define|#
directive|define
name|TTY_DISPLAY_H
value|1
end_define

begin_comment
comment|/*  * $Id: tty_display.h,v 1.6 2005/01/01 23:41:12 tom Exp $  */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_beep
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_check_resize
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_cursor
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_flash
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_init_color
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_init_pair
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_slk_hide
argument_list|(
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_slk_update
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_start_color
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_display_resume
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_display_suspend
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_dispose
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* frees SP->_term */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_switch_to
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_tty_update
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|tty_display_data
block|{
name|int
name|_fifohold
decl_stmt|;
comment|/* set if breakout marked           */
name|unsigned
name|long
name|_current_attr
decl_stmt|;
comment|/* terminal attribute current set   */
name|int
name|_cursrow
decl_stmt|;
comment|/* physical cursor row (-1=unknown) */
name|int
name|_curscol
decl_stmt|;
comment|/* physical cursor column           */
comment|/* cursor movement costs; units are 10ths of milliseconds */
name|int
name|_char_padding
decl_stmt|;
comment|/* cost of character put            */
name|int
name|_cr_cost
decl_stmt|;
comment|/* cost of (carriage_return)        */
name|int
name|_cup_cost
decl_stmt|;
comment|/* cost of (cursor_address)         */
name|int
name|_home_cost
decl_stmt|;
comment|/* cost of (cursor_home)            */
name|int
name|_ll_cost
decl_stmt|;
comment|/* cost of (cursor_to_ll)           */
if|#
directive|if
name|USE_HARD_TABS
name|int
name|_ht_cost
decl_stmt|;
comment|/* cost of (tab)                    */
name|int
name|_cbt_cost
decl_stmt|;
comment|/* cost of (backtab)                */
endif|#
directive|endif
comment|/* USE_HARD_TABS */
name|int
name|_cub1_cost
decl_stmt|;
comment|/* cost of (cursor_left)            */
name|int
name|_cuf1_cost
decl_stmt|;
comment|/* cost of (cursor_right)           */
name|int
name|_cud1_cost
decl_stmt|;
comment|/* cost of (cursor_down)            */
name|int
name|_cuu1_cost
decl_stmt|;
comment|/* cost of (cursor_up)              */
name|int
name|_cub_cost
decl_stmt|;
comment|/* cost of (parm_cursor_left)       */
name|int
name|_cuf_cost
decl_stmt|;
comment|/* cost of (parm_cursor_right)      */
name|int
name|_cud_cost
decl_stmt|;
comment|/* cost of (parm_cursor_down)       */
name|int
name|_cuu_cost
decl_stmt|;
comment|/* cost of (parm_cursor_up)         */
name|int
name|_hpa_cost
decl_stmt|;
comment|/* cost of (column_address)         */
name|int
name|_vpa_cost
decl_stmt|;
comment|/* cost of (row_address)            */
comment|/* used in lib_doupdate.c, must be chars */
name|int
name|_ed_cost
decl_stmt|;
comment|/* cost of (clr_eos)                */
name|int
name|_el_cost
decl_stmt|;
comment|/* cost of (clr_eol)                */
name|int
name|_el1_cost
decl_stmt|;
comment|/* cost of (clr_bol)                */
name|int
name|_dch1_cost
decl_stmt|;
comment|/* cost of (delete_character)       */
name|int
name|_ich1_cost
decl_stmt|;
comment|/* cost of (insert_character)       */
name|int
name|_dch_cost
decl_stmt|;
comment|/* cost of (parm_dch)               */
name|int
name|_ich_cost
decl_stmt|;
comment|/* cost of (parm_ich)               */
name|int
name|_ech_cost
decl_stmt|;
comment|/* cost of (erase_chars)            */
name|int
name|_rep_cost
decl_stmt|;
comment|/* cost of (repeat_char)            */
name|int
name|_hpa_ch_cost
decl_stmt|;
comment|/* cost of (column_address)         */
name|int
name|_cup_ch_cost
decl_stmt|;
comment|/* cost of (cursor_address)         */
name|int
name|_smir_cost
decl_stmt|;
comment|/* cost of (enter_insert_mode)      */
name|int
name|_rmir_cost
decl_stmt|;
comment|/* cost of (exit_insert_mode)       */
name|int
name|_ip_cost
decl_stmt|;
comment|/* cost of (insert_padding)         */
comment|/* used in lib_mvcur.c */
name|char
modifier|*
name|_address_cursor
decl_stmt|;
name|int
name|_carriage_return_length
decl_stmt|;
name|int
name|_cursor_home_length
decl_stmt|;
name|int
name|_cursor_to_ll_length
decl_stmt|;
name|chtype
name|_xmc_suppress
decl_stmt|;
comment|/* attributes to suppress if xmc     */
name|chtype
name|_xmc_triggers
decl_stmt|;
comment|/* attributes to process if xmc      */
name|bool
name|_sig_winch
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DelCharCost
parameter_list|(
name|count
parameter_list|)
define|\
value|((parm_dch != 0) \ 		? D->_dch_cost \ 		: ((delete_character != 0) \ 			? (D->_dch1_cost * count) \ 			: INFINITY))
end_define

begin_define
define|#
directive|define
name|InsCharCost
parameter_list|(
name|count
parameter_list|)
define|\
value|((parm_ich != 0) \ 		? D->_ich_cost \ 		: ((enter_insert_mode&& exit_insert_mode) \ 		  ? D->_smir_cost + D->_rmir_cost + (D->_ip_cost * count) \ 		  : ((insert_character != 0) \ 		    ? ((D->_ich1_cost + D->_ip_cost) * count) \ 		    : INFINITY)))
end_define

begin_if
if|#
directive|if
name|USE_XMC_SUPPORT
end_if

begin_define
define|#
directive|define
name|UpdateAttrs
parameter_list|(
name|c
parameter_list|)
value|if (!SameAttrOf(D->_current_attr, AttrOf(c))) { \ 				attr_t chg = D->_current_attr; \ 				vidattr(AttrOf(c)); \ 				if (magic_cookie_glitch> 0 \&& XMC_CHANGES((chg ^ D->_current_attr))) { \ 					T(("%s @%d before glitch %d,%d", \ 						__FILE__, __LINE__, \ 						D->_cursrow, \ 						D->_curscol)); \ 					_nc_do_xmc_glitch(chg); \ 				} \ 			}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UpdateAttrs
parameter_list|(
name|c
parameter_list|)
value|if (!SameAttrOf(D->_current_attr, AttrOf(c))) \ 				vidattr(AttrOf(c));
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XMC_CHANGES
parameter_list|(
name|c
parameter_list|)
value|((c)& D->_xmc_suppress)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TTY_DISPLAY_H */
end_comment

end_unit

