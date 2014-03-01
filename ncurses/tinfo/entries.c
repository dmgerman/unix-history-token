begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2006-2011,2012 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                                                *  *     and: Juergen Pfeifer                                                 *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<tic.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: entries.c,v 1.21 2012/05/05 20:33:44 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/****************************************************************************  *  * Entry queue handling  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *  The entry list is a doubly linked list with NULLs terminating the lists:  *  *	  ---------   ---------   ---------  *	  |       |   |       |   |       |   offset  *        |-------|   |-------|   |-------|  *	  |   ----+-->|   ----+-->|  NULL |   next  *	  |-------|   |-------|   |-------|  *	  |  NULL |<--+----   |<--+----   |   last  *	  ---------   ---------   ---------  *	      ^                       ^  *	      |                       |  *	      |                       |  *	   _nc_head                _nc_tail  */
end_comment

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|ENTRY *
argument_list|)
end_macro

begin_expr_stmt
name|_nc_head
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|ENTRY *
argument_list|)
end_macro

begin_expr_stmt
name|_nc_tail
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_free_entry
argument_list|(
argument|ENTRY * headp
argument_list|,
argument|TERMTYPE *tterm
argument_list|)
end_macro

begin_comment
comment|/* free the allocated storage consumed by the given list entry */
end_comment

begin_block
block|{
name|ENTRY
modifier|*
name|ep
decl_stmt|;
if|if
condition|(
operator|(
name|ep
operator|=
name|_nc_delink_entry
argument_list|(
name|headp
argument_list|,
name|tterm
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|free
argument_list|(
name|ep
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_free_entries
argument_list|(
argument|ENTRY * headp
argument_list|)
end_macro

begin_comment
comment|/* free the allocated storage consumed by list entries */
end_comment

begin_block
block|{
operator|(
name|void
operator|)
name|headp
expr_stmt|;
comment|/* unused - _nc_head is altered here! */
while|while
condition|(
name|_nc_head
operator|!=
literal|0
condition|)
block|{
name|_nc_free_termtype
argument_list|(
operator|&
operator|(
name|_nc_head
operator|->
name|tterm
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|ENTRY *
argument_list|)
end_macro

begin_macro
name|_nc_delink_entry
argument_list|(
argument|ENTRY * headp
argument_list|,
argument|TERMTYPE *tterm
argument_list|)
end_macro

begin_comment
comment|/* delink the allocated storage for the given list entry */
end_comment

begin_block
block|{
name|ENTRY
modifier|*
name|ep
decl_stmt|,
modifier|*
name|last
decl_stmt|;
for|for
control|(
name|last
operator|=
literal|0
operator|,
name|ep
operator|=
name|headp
init|;
name|ep
operator|!=
literal|0
condition|;
name|last
operator|=
name|ep
operator|,
name|ep
operator|=
name|ep
operator|->
name|next
control|)
block|{
if|if
condition|(
operator|&
operator|(
name|ep
operator|->
name|tterm
operator|)
operator|==
name|tterm
condition|)
block|{
if|if
condition|(
name|last
operator|!=
literal|0
condition|)
block|{
name|last
operator|->
name|next
operator|=
name|ep
operator|->
name|next
expr_stmt|;
block|}
if|if
condition|(
name|ep
operator|->
name|next
operator|!=
literal|0
condition|)
block|{
name|ep
operator|->
name|next
operator|->
name|last
operator|=
name|last
expr_stmt|;
block|}
if|if
condition|(
name|ep
operator|==
name|_nc_head
condition|)
block|{
name|_nc_head
operator|=
name|ep
operator|->
name|next
expr_stmt|;
block|}
if|if
condition|(
name|ep
operator|==
name|_nc_tail
condition|)
block|{
name|_nc_tail
operator|=
name|last
expr_stmt|;
block|}
break|break;
block|}
block|}
return|return
name|ep
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_leaks_tinfo
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|NO_LEAKS
name|char
modifier|*
name|s
decl_stmt|;
endif|#
directive|endif
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"_nc_free_tinfo()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|NO_LEAKS
name|_nc_free_tparm
argument_list|()
expr_stmt|;
name|_nc_tgetent_leaks
argument_list|()
expr_stmt|;
if|if
condition|(
name|TerminalOf
argument_list|(
name|CURRENT_SCREEN
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|del_curterm
argument_list|(
name|TerminalOf
argument_list|(
name|CURRENT_SCREEN
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|_nc_comp_captab_leaks
argument_list|()
expr_stmt|;
name|_nc_free_entries
argument_list|(
name|_nc_head
argument_list|)
expr_stmt|;
name|_nc_get_type
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|_nc_first_name
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|_nc_db_iterator_leaks
argument_list|()
expr_stmt|;
name|_nc_keyname_leaks
argument_list|()
expr_stmt|;
if|#
directive|if
name|BROKEN_LINKER
operator|||
name|USE_REENTRANT
name|_nc_names_leaks
argument_list|()
expr_stmt|;
name|_nc_codes_leaks
argument_list|()
expr_stmt|;
name|FreeIfNeeded
argument_list|(
name|_nc_prescreen
operator|.
name|real_acs_map
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|_nc_comp_error_leaks
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|s
operator|=
name|_nc_home_terminfo
argument_list|()
operator|)
operator|!=
literal|0
condition|)
name|free
argument_list|(
name|s
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TRACE
name|trace
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|_nc_trace_buf
argument_list|(
operator|-
literal|1
argument_list|,
operator|(
name|size_t
operator|)
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* NO_LEAKS */
name|returnVoid
expr_stmt|;
block|}
end_block

begin_if
if|#
directive|if
name|NO_LEAKS
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_free_tinfo
argument_list|(
argument|int code
argument_list|)
end_macro

begin_block
block|{
name|_nc_leaks_tinfo
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

