begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2004,2005 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Thomas E. Dickey                                              *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_trace.c,v 1.3 2005/01/16 01:06:11 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|ITEM *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_item
argument_list|(
argument|ITEM * code
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
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|ITEM **
argument_list|)
end_macro

begin_macro
name|_nc_retrace_item_ptr
argument_list|(
argument|ITEM ** code
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
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|Item_Options
argument_list|)
end_macro

begin_macro
name|_nc_retrace_item_opts
argument_list|(
argument|Item_Options code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%d"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|MENU *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_menu
argument_list|(
argument|MENU * code
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
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|Menu_Hook
argument_list|)
end_macro

begin_macro
name|_nc_retrace_menu_hook
argument_list|(
argument|Menu_Hook code
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
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|Menu_Options
argument_list|)
end_macro

begin_macro
name|_nc_retrace_menu_opts
argument_list|(
argument|Menu_Options code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%d"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

end_unit

