begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1995,1997            *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_item_nam                                                        * * Get menus item name and description                                      * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_item_nam.c,v 1.9 1999/05/16 17:25:43 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  char *item_name(const ITEM *item) |    |   Description   :  Return name of menu item | |   Return Values :  See above; returns NULL if item is invalid +--------------------------------------------------------------------------*/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|item_name
parameter_list|(
specifier|const
name|ITEM
modifier|*
name|item
parameter_list|)
block|{
return|return
operator|(
operator|(
name|item
operator|)
condition|?
name|item
operator|->
name|name
operator|.
name|str
else|:
operator|(
name|char
operator|*
operator|)
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  char *item_description(const ITEM *item) |    |   Description   :  Returns description of item | |   Return Values :  See above; Returns NULL if item is invalid +--------------------------------------------------------------------------*/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|item_description
parameter_list|(
specifier|const
name|ITEM
modifier|*
name|item
parameter_list|)
block|{
return|return
operator|(
operator|(
name|item
operator|)
condition|?
name|item
operator|->
name|description
operator|.
name|str
else|:
operator|(
name|char
operator|*
operator|)
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* m_item_nam.c ends here */
end_comment

end_unit

