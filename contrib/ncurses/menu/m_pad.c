begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1995,1997            *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_pad                                                             * * Control menus padding character                                          * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_pad.c,v 1.4 1999/05/16 17:27:17 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/* Macro to redraw menu if it is posted and changed */
end_comment

begin_define
define|#
directive|define
name|Refresh_Menu
parameter_list|(
name|menu
parameter_list|)
define|\
value|if ( (menu)&& ((menu)->status& _POSTED) )\    {\       _nc_Draw_Menu( menu );\       _nc_Show_Menu( menu );\    }
end_define

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_menu_pad(MENU *menu, int pad) |    |   Description   :  Set the character to be used to separate the item name |                    from its description. This must be a printable  |                    character. | |   Return Values :  E_OK              - success |                    E_BAD_ARGUMENT    - an invalid value has been passed +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|set_menu_pad
parameter_list|(
name|MENU
modifier|*
name|menu
parameter_list|,
name|int
name|pad
parameter_list|)
block|{
name|bool
name|do_refresh
init|=
operator|(
name|menu
operator|!=
operator|(
name|MENU
operator|*
operator|)
literal|0
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|isprint
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|pad
argument_list|)
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
name|Normalize_Menu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|menu
operator|->
name|pad
operator|=
name|pad
expr_stmt|;
if|if
condition|(
name|do_refresh
condition|)
name|Refresh_Menu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int menu_pad(const MENU *menu) |    |   Description   :  Return the value of the padding character | |   Return Values :  The pad character +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|menu_pad
parameter_list|(
specifier|const
name|MENU
modifier|*
name|menu
parameter_list|)
block|{
return|return
operator|(
name|Normalize_Menu
argument_list|(
name|menu
argument_list|)
operator|->
name|pad
operator|)
return|;
block|}
end_function

begin_comment
comment|/* m_pad.c ends here */
end_comment

end_unit

