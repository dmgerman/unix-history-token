begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1995                    *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
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
literal|"$Id: p_below.c,v 1.3 1999/09/18 11:03:33 juergen Exp $"
argument_list|)
end_macro

begin_function
name|PANEL
modifier|*
name|panel_below
parameter_list|(
specifier|const
name|PANEL
modifier|*
name|pan
parameter_list|)
block|{
if|if
condition|(
operator|!
name|pan
condition|)
block|{
comment|/* if top and bottom are equal, we have no or only the pseudo panel */
return|return
operator|(
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
operator|)
return|;
block|}
else|else
block|{
comment|/* we must not return the pseudo panel */
return|return
operator|(
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
operator|)
return|;
block|}
block|}
end_function

end_unit

