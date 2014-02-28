begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2009,2010 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1995                    *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Juergen Pfeifer                         1997-1999,2008          *  ****************************************************************************/
end_comment

begin_comment
comment|/* p_update.c  * wnoutrefresh windows in an orderly fashion  */
end_comment

begin_include
include|#
directive|include
file|"panel.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: p_update.c,v 1.11 2010/01/23 21:22:16 tom Exp $"
argument_list|)
end_macro

begin_function
name|NCURSES_EXPORT
function|(
name|void
function|)
name|NCURSES_SP_NAME
argument_list|(
argument|update_panels
argument_list|)
parameter_list|(
name|NCURSES_SP_DCL0
parameter_list|)
block|{
name|PANEL
modifier|*
name|pan
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"update_panels(%p)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|SP_PARM
operator|)
argument_list|)
expr_stmt|;
name|dBug
argument_list|(
operator|(
literal|"--> update_panels"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SP_PARM
condition|)
block|{
name|GetScreenHook
argument_list|(
name|SP_PARM
argument_list|)
expr_stmt|;
name|pan
operator|=
name|_nc_bottom_panel
expr_stmt|;
while|while
condition|(
name|pan
operator|&&
name|pan
operator|->
name|above
condition|)
block|{
name|PANEL_UPDATE
argument_list|(
name|pan
argument_list|,
name|pan
operator|->
name|above
argument_list|)
expr_stmt|;
name|pan
operator|=
name|pan
operator|->
name|above
expr_stmt|;
block|}
name|pan
operator|=
name|_nc_bottom_panel
expr_stmt|;
while|while
condition|(
name|pan
condition|)
block|{
name|Wnoutrefresh
argument_list|(
name|pan
argument_list|)
expr_stmt|;
name|pan
operator|=
name|pan
operator|->
name|above
expr_stmt|;
block|}
block|}
name|returnVoid
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|update_panels
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|NCURSES_SP_NAME
function_decl|(
name|update_panels
function_decl|)
parameter_list|(
name|CURRENT_SCREEN
parameter_list|)
function_decl|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

