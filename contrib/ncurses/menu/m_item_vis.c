begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1995,1997            *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_item_vis                                                        * * Tell if menu item is visible                                             * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_item_vis.c,v 1.10 1999/05/16 17:26:34 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  bool item_visible(const ITEM *item) |    |   Description   :  A item is visible if it currently appears in the |                    subwindow of a posted menu. | |   Return Values :  TRUE  if visible |                    FALSE if invisible +--------------------------------------------------------------------------*/
end_comment

begin_function
name|bool
name|item_visible
parameter_list|(
specifier|const
name|ITEM
modifier|*
name|item
parameter_list|)
block|{
name|MENU
modifier|*
name|menu
decl_stmt|;
if|if
condition|(
name|item
operator|&&
operator|(
name|menu
operator|=
name|item
operator|->
name|imenu
operator|)
operator|&&
operator|(
name|menu
operator|->
name|status
operator|&
name|_POSTED
operator|)
operator|&&
operator|(
operator|(
name|menu
operator|->
name|toprow
operator|+
name|menu
operator|->
name|arows
operator|)
operator|>
operator|(
name|item
operator|->
name|y
operator|)
operator|)
operator|&&
operator|(
name|item
operator|->
name|y
operator|>=
name|menu
operator|->
name|toprow
operator|)
condition|)
return|return
name|TRUE
return|;
else|else
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/* m_item_vis.c ends here */
end_comment

end_unit

