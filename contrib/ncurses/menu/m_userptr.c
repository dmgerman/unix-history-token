begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1995,1997            *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_userptr                                                         * * Associate application data with menus                                    * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_userptr.c,v 1.10 1999/05/16 17:28:29 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_menu_userptr(MENU *menu, void *userptr) |    |   Description   :  Set the pointer that is reserved in any menu to store |                    application relevant informations. | |   Return Values :  E_OK         - success +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|set_menu_userptr
parameter_list|(
name|MENU
modifier|*
name|menu
parameter_list|,
name|void
modifier|*
name|userptr
parameter_list|)
block|{
name|Normalize_Menu
argument_list|(
name|menu
argument_list|)
operator|->
name|userptr
operator|=
name|userptr
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  void *menu_userptr(const MENU *menu) |    |   Description   :  Return the pointer that is reserved in any menu to |                    store application relevant informations. | |   Return Values :  Value of the pointer. If no such pointer has been set, |                    NULL is returned +--------------------------------------------------------------------------*/
end_comment

begin_function
name|void
modifier|*
name|menu_userptr
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
name|userptr
operator|)
return|;
block|}
end_function

begin_comment
comment|/* m_userptr.c ends here */
end_comment

end_unit

