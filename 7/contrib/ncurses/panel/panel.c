begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2004,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1995                    *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* panel.c -- implementation of panels library, some core routines */
end_comment

begin_include
include|#
directive|include
file|"panel.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: panel.c,v 1.23 2005/02/19 18:04:31 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*+------------------------------------------------------------------------- 	_nc_retrace_panel (pan) --------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|PANEL *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_panel
argument_list|(
argument|PANEL * pan
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%p"
argument_list|)
operator|,
name|pan
operator|)
argument_list|)
expr_stmt|;
return|return
name|pan
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*+------------------------------------------------------------------------- 	_nc_my_visbuf(ptr) --------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TRACE_TXT
end_ifndef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|const char *
argument_list|)
end_macro

begin_macro
name|_nc_my_visbuf
argument_list|(
argument|const void *ptr
argument_list|)
end_macro

begin_block
block|{
name|char
name|temp
index|[
literal|32
index|]
decl_stmt|;
if|if
condition|(
name|ptr
operator|!=
literal|0
condition|)
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"ptr:%p"
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
else|else
name|strcpy
argument_list|(
name|temp
argument_list|,
literal|"<null>"
argument_list|)
expr_stmt|;
return|return
name|_nc_visbuf
argument_list|(
name|temp
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*+------------------------------------------------------------------------- 	dPanel(text,pan) --------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_dPanel
argument_list|(
argument|const char *text
argument_list|,
argument|const PANEL * pan
argument_list|)
end_macro

begin_block
block|{
name|_tracef
argument_list|(
literal|"%s id=%s b=%s a=%s y=%d x=%d"
argument_list|,
name|text
argument_list|,
name|USER_PTR
argument_list|(
name|pan
operator|->
name|user
argument_list|)
argument_list|,
operator|(
name|pan
operator|->
name|below
operator|)
condition|?
name|USER_PTR
argument_list|(
name|pan
operator|->
name|below
operator|->
name|user
argument_list|)
else|:
literal|"--"
argument_list|,
operator|(
name|pan
operator|->
name|above
operator|)
condition|?
name|USER_PTR
argument_list|(
name|pan
operator|->
name|above
operator|->
name|user
argument_list|)
else|:
literal|"--"
argument_list|,
name|PSTARTY
argument_list|(
name|pan
argument_list|)
argument_list|,
name|PSTARTX
argument_list|(
name|pan
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*+------------------------------------------------------------------------- 	dStack(fmt,num,pan) --------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_dStack
argument_list|(
argument|const char *fmt
argument_list|,
argument|int num
argument_list|,
argument|const PANEL * pan
argument_list|)
end_macro

begin_block
block|{
name|char
name|s80
index|[
literal|80
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|s80
argument_list|,
name|fmt
argument_list|,
name|num
argument_list|,
name|pan
argument_list|)
expr_stmt|;
name|_tracef
argument_list|(
literal|"%s b=%s t=%s"
argument_list|,
name|s80
argument_list|,
operator|(
name|_nc_bottom_panel
operator|)
condition|?
name|USER_PTR
argument_list|(
name|_nc_bottom_panel
operator|->
name|user
argument_list|)
else|:
literal|"--"
argument_list|,
operator|(
name|_nc_top_panel
operator|)
condition|?
name|USER_PTR
argument_list|(
name|_nc_top_panel
operator|->
name|user
argument_list|)
else|:
literal|"--"
argument_list|)
expr_stmt|;
if|if
condition|(
name|pan
condition|)
name|_tracef
argument_list|(
literal|"pan id=%s"
argument_list|,
name|USER_PTR
argument_list|(
name|pan
operator|->
name|user
argument_list|)
argument_list|)
expr_stmt|;
name|pan
operator|=
name|_nc_bottom_panel
expr_stmt|;
while|while
condition|(
name|pan
condition|)
block|{
name|dPanel
argument_list|(
literal|"stk"
argument_list|,
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
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*+------------------------------------------------------------------------- 	Wnoutrefresh(pan) - debugging hook for wnoutrefresh --------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_Wnoutrefresh
argument_list|(
argument|const PANEL * pan
argument_list|)
end_macro

begin_block
block|{
name|dPanel
argument_list|(
literal|"wnoutrefresh"
argument_list|,
name|pan
argument_list|)
expr_stmt|;
name|wnoutrefresh
argument_list|(
name|pan
operator|->
name|win
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*+------------------------------------------------------------------------- 	Touchpan(pan) --------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_Touchpan
argument_list|(
argument|const PANEL * pan
argument_list|)
end_macro

begin_block
block|{
name|dPanel
argument_list|(
literal|"Touchpan"
argument_list|,
name|pan
argument_list|)
expr_stmt|;
name|touchwin
argument_list|(
name|pan
operator|->
name|win
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*+------------------------------------------------------------------------- 	Touchline(pan,start,count) --------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_Touchline
argument_list|(
argument|const PANEL * pan
argument_list|,
argument|int start
argument_list|,
argument|int count
argument_list|)
end_macro

begin_block
block|{
name|char
name|s80
index|[
literal|80
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|s80
argument_list|,
literal|"Touchline s=%d c=%d"
argument_list|,
name|start
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|dPanel
argument_list|(
name|s80
argument_list|,
name|pan
argument_list|)
expr_stmt|;
name|touchline
argument_list|(
name|pan
operator|->
name|win
argument_list|,
name|start
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRACE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* Some C compilers need something defined in a source file */
end_comment

begin_function_decl
specifier|extern
name|void
name|_nc_dummy_panel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_nc_dummy_panel
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

