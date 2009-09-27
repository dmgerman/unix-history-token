begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2009 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEKEN_H_
end_ifndef

begin_define
define|#
directive|define
name|_TEKEN_H_
end_define

begin_comment
comment|/*  * libteken: terminal emulation library.  *  * This library converts an UTF-8 stream of bytes to terminal drawing  * commands.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|teken_char_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|teken_unit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|teken_format_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TF_BOLD
value|0x01
end_define

begin_define
define|#
directive|define
name|TF_UNDERLINE
value|0x02
end_define

begin_define
define|#
directive|define
name|TF_BLINK
value|0x04
end_define

begin_define
define|#
directive|define
name|TF_REVERSE
value|0x08
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|teken_color_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TC_BLACK
value|0
end_define

begin_define
define|#
directive|define
name|TC_RED
value|1
end_define

begin_define
define|#
directive|define
name|TC_GREEN
value|2
end_define

begin_define
define|#
directive|define
name|TC_BROWN
value|3
end_define

begin_define
define|#
directive|define
name|TC_BLUE
value|4
end_define

begin_define
define|#
directive|define
name|TC_MAGENTA
value|5
end_define

begin_define
define|#
directive|define
name|TC_CYAN
value|6
end_define

begin_define
define|#
directive|define
name|TC_WHITE
value|7
end_define

begin_define
define|#
directive|define
name|TC_NCOLORS
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|teken_unit_t
name|tp_row
decl_stmt|;
name|teken_unit_t
name|tp_col
decl_stmt|;
block|}
name|teken_pos_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|teken_pos_t
name|tr_begin
decl_stmt|;
name|teken_pos_t
name|tr_end
decl_stmt|;
block|}
name|teken_rect_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|teken_format_t
name|ta_format
decl_stmt|;
name|teken_color_t
name|ta_fgcolor
decl_stmt|;
name|teken_color_t
name|ta_bgcolor
decl_stmt|;
block|}
name|teken_attr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|teken_unit_t
name|ts_begin
decl_stmt|;
name|teken_unit_t
name|ts_end
decl_stmt|;
block|}
name|teken_span_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|__teken
name|teken_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|teken_state_t
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
name|teken_char_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Drawing routines supplied by the user.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|tf_bell_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tf_cursor_t
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|teken_pos_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tf_putchar_t
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|teken_pos_t
modifier|*
parameter_list|,
name|teken_char_t
parameter_list|,
specifier|const
name|teken_attr_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tf_fill_t
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|teken_rect_t
modifier|*
parameter_list|,
name|teken_char_t
parameter_list|,
specifier|const
name|teken_attr_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tf_copy_t
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|teken_rect_t
modifier|*
parameter_list|,
specifier|const
name|teken_pos_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tf_param_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|TP_SHOWCURSOR
value|0
end_define

begin_define
define|#
directive|define
name|TP_CURSORKEYS
value|1
end_define

begin_define
define|#
directive|define
name|TP_KEYPADAPP
value|2
end_define

begin_define
define|#
directive|define
name|TP_AUTOREPEAT
value|3
end_define

begin_define
define|#
directive|define
name|TP_SWITCHVT
value|4
end_define

begin_define
define|#
directive|define
name|TP_132COLS
value|5
end_define

begin_define
define|#
directive|define
name|TP_SETBELLPD
value|6
end_define

begin_define
define|#
directive|define
name|TP_SETBELLPD_PITCH
parameter_list|(
name|pd
parameter_list|)
value|((pd)>> 16)
end_define

begin_define
define|#
directive|define
name|TP_SETBELLPD_DURATION
parameter_list|(
name|pd
parameter_list|)
value|((pd)& 0xffff)
end_define

begin_define
define|#
directive|define
name|TP_MOUSE
value|7
end_define

begin_typedef
typedef|typedef
name|void
name|tf_respond_t
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|tf_bell_t
modifier|*
name|tf_bell
decl_stmt|;
name|tf_cursor_t
modifier|*
name|tf_cursor
decl_stmt|;
name|tf_putchar_t
modifier|*
name|tf_putchar
decl_stmt|;
name|tf_fill_t
modifier|*
name|tf_fill
decl_stmt|;
name|tf_copy_t
modifier|*
name|tf_copy
decl_stmt|;
name|tf_param_t
modifier|*
name|tf_param
decl_stmt|;
name|tf_respond_t
modifier|*
name|tf_respond
decl_stmt|;
block|}
name|teken_funcs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|teken_char_t
name|teken_scs_t
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
name|teken_char_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Terminal state.  */
end_comment

begin_struct
struct|struct
name|__teken
block|{
specifier|const
name|teken_funcs_t
modifier|*
name|t_funcs
decl_stmt|;
name|void
modifier|*
name|t_softc
decl_stmt|;
name|teken_state_t
modifier|*
name|t_nextstate
decl_stmt|;
name|unsigned
name|int
name|t_stateflags
decl_stmt|;
define|#
directive|define
name|T_NUMSIZE
value|8
name|unsigned
name|int
name|t_nums
index|[
name|T_NUMSIZE
index|]
decl_stmt|;
name|unsigned
name|int
name|t_curnum
decl_stmt|;
name|teken_pos_t
name|t_cursor
decl_stmt|;
name|teken_attr_t
name|t_curattr
decl_stmt|;
name|teken_pos_t
name|t_saved_cursor
decl_stmt|;
name|teken_attr_t
name|t_saved_curattr
decl_stmt|;
name|teken_attr_t
name|t_defattr
decl_stmt|;
name|teken_pos_t
name|t_winsize
decl_stmt|;
comment|/* For DECSTBM. */
name|teken_span_t
name|t_scrollreg
decl_stmt|;
comment|/* For DECOM. */
name|teken_span_t
name|t_originreg
decl_stmt|;
define|#
directive|define
name|T_NUMCOL
value|160
name|unsigned
name|int
name|t_tabstops
index|[
name|T_NUMCOL
operator|/
operator|(
expr|sizeof
operator|(
name|unsigned
name|int
operator|)
operator|*
literal|8
block|)
struct|];
end_struct

begin_decl_stmt
name|unsigned
name|int
name|t_utf8_left
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|teken_char_t
name|t_utf8_partial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|t_curscs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|teken_scs_t
modifier|*
name|t_saved_curscs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|teken_scs_t
modifier|*
name|t_scs
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/* Initialize teken structure. */
end_comment

begin_function_decl
name|void
name|teken_init
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
specifier|const
name|teken_funcs_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deliver character input. */
end_comment

begin_function_decl
name|void
name|teken_input
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get/set teken attributes. */
end_comment

begin_function_decl
specifier|const
name|teken_pos_t
modifier|*
name|teken_get_cursor
parameter_list|(
name|teken_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|teken_attr_t
modifier|*
name|teken_get_curattr
parameter_list|(
name|teken_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|teken_attr_t
modifier|*
name|teken_get_defattr
parameter_list|(
name|teken_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|teken_get_defattr_cons25
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|teken_pos_t
modifier|*
name|teken_get_winsize
parameter_list|(
name|teken_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|teken_set_cursor
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
specifier|const
name|teken_pos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|teken_set_curattr
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
specifier|const
name|teken_attr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|teken_set_defattr
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
specifier|const
name|teken_attr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|teken_set_winsize
parameter_list|(
name|teken_t
modifier|*
parameter_list|,
specifier|const
name|teken_pos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Legacy features. */
end_comment

begin_function_decl
name|void
name|teken_set_8bit
parameter_list|(
name|teken_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|teken_set_cons25
parameter_list|(
name|teken_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Color conversion. */
end_comment

begin_function_decl
name|teken_color_t
name|teken_256to8
parameter_list|(
name|teken_color_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TEKEN_H_ */
end_comment

end_unit

