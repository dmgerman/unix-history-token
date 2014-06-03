begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2010,2012 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1995                    *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Juergen Pfeifer                         1997-1999,2008          *  ****************************************************************************/
end_comment

begin_comment
comment|/* p_below.c  */
end_comment

begin_include
include|#
directive|include
file|"panel.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: p_below.c,v 1.9 2012/03/10 23:43:41 tom Exp $"
argument_list|)
end_macro

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|PANEL *
argument_list|)
end_macro

begin_macro
name|ceiling_panel
argument_list|(
argument|SCREEN * sp
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"ceiling_panel(%p)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|sp
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
condition|)
block|{
name|struct
name|panelhook
modifier|*
name|ph
init|=
name|NCURSES_SP_NAME
argument_list|(
name|_nc_panelhook
argument_list|)
argument_list|(
name|sp
argument_list|)
decl_stmt|;
comment|/* if top and bottom are equal, we have no or only the pseudo panel */
name|returnPanel
argument_list|(
name|EMPTY_STACK
argument_list|()
condition|?
operator|(
name|PANEL
operator|*
operator|)
literal|0
else|:
name|_nc_top_panel
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
literal|0
operator|==
name|CURRENT_SCREEN
condition|)
name|returnPanel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
name|returnPanel
argument_list|(
name|ceiling_panel
argument_list|(
name|CURRENT_SCREEN
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|PANEL *
argument_list|)
end_macro

begin_macro
name|panel_below
argument_list|(
argument|const PANEL * pan
argument_list|)
end_macro

begin_block
block|{
name|PANEL
modifier|*
name|result
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"panel_below(%p)"
argument_list|)
operator|,
operator|(
specifier|const
name|void
operator|*
operator|)
name|pan
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pan
condition|)
block|{
name|GetHook
argument_list|(
name|pan
argument_list|)
expr_stmt|;
comment|/* we must not return the pseudo panel */
name|result
operator|=
name|Is_Pseudo
argument_list|(
name|pan
operator|->
name|below
argument_list|)
condition|?
operator|(
name|PANEL
operator|*
operator|)
literal|0
else|:
name|pan
operator|->
name|below
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
name|NCURSES_SP_FUNCS
name|result
operator|=
name|ceiling_panel
argument_list|(
name|CURRENT_SCREEN
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* if top and bottom are equal, we have no or only the pseudo panel */
name|result
operator|=
name|EMPTY_STACK
argument_list|()
condition|?
operator|(
name|PANEL
operator|*
operator|)
literal|0
else|:
name|_nc_top_panel
expr_stmt|;
endif|#
directive|endif
block|}
name|returnPanel
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

