begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2002 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey 2002                                           *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<term.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_vid_attr.c,v 1.1 2002/05/11 20:55:26 tom Exp $"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|set_color
parameter_list|(
name|mode
parameter_list|,
name|pair
parameter_list|)
value|mode&= ~A_COLOR; mode |= COLOR_PAIR(pair)
end_define

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|vid_puts
argument_list|(
argument|attr_t newmode
argument_list|,
argument|short pair
argument_list|,
argument|void *opts GCC_UNUSED
argument_list|,
argument|int (*outc) (int)
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"vid_puts(%s,%d)"
argument_list|)
operator|,
name|_traceattr
argument_list|(
name|newmode
argument_list|)
operator|,
name|pair
operator|)
argument_list|)
expr_stmt|;
name|set_color
argument_list|(
name|newmode
argument_list|,
name|pair
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|vidputs
argument_list|(
name|newmode
argument_list|,
name|outc
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|vid_attr
end_undef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|vid_attr
argument_list|(
argument|attr_t newmode
argument_list|,
argument|short pair
argument_list|,
argument|void *opts GCC_UNUSED
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"vid_attr(%s,%d)"
argument_list|)
operator|,
name|_traceattr
argument_list|(
name|newmode
argument_list|)
operator|,
name|pair
operator|)
argument_list|)
expr_stmt|;
name|set_color
argument_list|(
name|newmode
argument_list|,
name|pair
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|vidputs
argument_list|(
name|newmode
argument_list|,
name|_nc_outch
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|attr_t
argument_list|)
end_macro

begin_macro
name|term_attrs
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|attr_t
name|attrs
init|=
name|WA_NORMAL
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"term_attrs()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|enter_alt_charset_mode
condition|)
name|attrs
operator||=
name|WA_ALTCHARSET
expr_stmt|;
if|if
condition|(
name|enter_blink_mode
condition|)
name|attrs
operator||=
name|WA_BLINK
expr_stmt|;
if|if
condition|(
name|enter_bold_mode
condition|)
name|attrs
operator||=
name|WA_BOLD
expr_stmt|;
if|if
condition|(
name|enter_dim_mode
condition|)
name|attrs
operator||=
name|WA_DIM
expr_stmt|;
if|if
condition|(
name|enter_reverse_mode
condition|)
name|attrs
operator||=
name|WA_REVERSE
expr_stmt|;
if|if
condition|(
name|enter_standout_mode
condition|)
name|attrs
operator||=
name|WA_STANDOUT
expr_stmt|;
if|if
condition|(
name|enter_protected_mode
condition|)
name|attrs
operator||=
name|WA_PROTECT
expr_stmt|;
if|if
condition|(
name|enter_secure_mode
condition|)
name|attrs
operator||=
name|WA_INVIS
expr_stmt|;
if|if
condition|(
name|enter_underline_mode
condition|)
name|attrs
operator||=
name|WA_UNDERLINE
expr_stmt|;
if|if
condition|(
name|SP
operator|->
name|_coloron
condition|)
name|attrs
operator||=
name|A_COLOR
expr_stmt|;
name|returnAttr
argument_list|(
name|attrs
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

