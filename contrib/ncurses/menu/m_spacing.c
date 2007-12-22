begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_spacing                                                         * * Routines to handle spacing between entries                               * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_spacing.c,v 1.17 2004/12/11 23:29:34 tom Exp $"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|MAX_SPC_DESC
value|((TABSIZE) ? (TABSIZE) : 8)
end_define

begin_define
define|#
directive|define
name|MAX_SPC_COLS
value|((TABSIZE) ? (TABSIZE) : 8)
end_define

begin_define
define|#
directive|define
name|MAX_SPC_ROWS
value|(3)
end_define

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu |   Function      :  int set_menu_spacing(MENU *menu,int desc, int r, int c); | |   Description   :  Set the spacing between entries | |   Return Values :  E_OK                 - on success +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_menu_spacing
argument_list|(
argument|MENU * menu
argument_list|,
argument|int s_desc
argument_list|,
argument|int s_row
argument_list|,
argument|int s_col
argument_list|)
end_macro

begin_block
block|{
name|MENU
modifier|*
name|m
decl_stmt|;
comment|/* split for ATAC workaround */
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_menu_spacing(%p,%d,%d,%d)"
argument_list|)
operator|,
name|menu
operator|,
name|s_desc
operator|,
name|s_row
operator|,
name|s_col
operator|)
argument_list|)
expr_stmt|;
name|m
operator|=
name|Normalize_Menu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|status
operator|&
name|_POSTED
condition|)
name|RETURN
argument_list|(
name|E_POSTED
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|s_desc
operator|<
literal|0
operator|)
operator|||
operator|(
name|s_desc
operator|>
name|MAX_SPC_DESC
operator|)
operator|)
operator|||
operator|(
operator|(
name|s_row
operator|<
literal|0
operator|)
operator|||
operator|(
name|s_row
operator|>
name|MAX_SPC_ROWS
operator|)
operator|)
operator|||
operator|(
operator|(
name|s_col
operator|<
literal|0
operator|)
operator|||
operator|(
name|s_col
operator|>
name|MAX_SPC_COLS
operator|)
operator|)
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
name|m
operator|->
name|spc_desc
operator|=
name|s_desc
condition|?
name|s_desc
else|:
literal|1
expr_stmt|;
name|m
operator|->
name|spc_rows
operator|=
name|s_row
condition|?
name|s_row
else|:
literal|1
expr_stmt|;
name|m
operator|->
name|spc_cols
operator|=
name|s_col
condition|?
name|s_col
else|:
literal|1
expr_stmt|;
name|_nc_Calculate_Item_Length_and_Width
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu |   Function      :  int menu_spacing (const MENU *,int *,int *,int *); | |   Description   :  Retrieve info about spacing between the entries | |   Return Values :  E_OK             - on success +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|menu_spacing
argument_list|(
argument|const MENU * menu
argument_list|,
argument|int *s_desc
argument_list|,
argument|int *s_row
argument_list|,
argument|int *s_col
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|MENU
modifier|*
name|m
decl_stmt|;
comment|/* split for ATAC workaround */
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"menu_spacing(%p,%p,%p,%p)"
argument_list|)
operator|,
name|menu
operator|,
name|s_desc
operator|,
name|s_row
operator|,
name|s_col
operator|)
argument_list|)
expr_stmt|;
name|m
operator|=
name|Normalize_Menu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|s_desc
condition|)
operator|*
name|s_desc
operator|=
name|m
operator|->
name|spc_desc
expr_stmt|;
if|if
condition|(
name|s_row
condition|)
operator|*
name|s_row
operator|=
name|m
operator|->
name|spc_rows
expr_stmt|;
if|if
condition|(
name|s_col
condition|)
operator|*
name|s_col
operator|=
name|m
operator|->
name|spc_cols
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* m_spacing.c ends here */
end_comment

end_unit

