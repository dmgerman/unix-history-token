begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)terminal.c	5.2 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  */
end_comment

begin_include
include|#
directive|include
file|"hunt.h"
end_include

begin_define
define|#
directive|define
name|TERM_WIDTH
value|80
end_define

begin_comment
comment|/* Assume terminals are 80-char wide */
end_comment

begin_comment
comment|/*  * cgoto:  *	Move the cursor to the given position on the given player's  *	terminal.  */
end_comment

begin_expr_stmt
name|cgoto
argument_list|(
name|pp
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
specifier|register
name|PLAYER
operator|*
name|pp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|x
operator|==
name|pp
operator|->
name|p_curx
operator|&&
name|y
operator|==
name|pp
operator|->
name|p_cury
condition|)
return|return;
name|sendcom
argument_list|(
name|pp
argument_list|,
name|MOVE
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|pp
operator|->
name|p_cury
operator|=
name|y
expr_stmt|;
name|pp
operator|->
name|p_curx
operator|=
name|x
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * outch:  *	Put out a single character.  */
end_comment

begin_expr_stmt
name|outch
argument_list|(
name|pp
argument_list|,
name|ch
argument_list|)
specifier|register
name|PLAYER
operator|*
name|pp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|ch
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|++
name|pp
operator|->
name|p_curx
operator|>=
name|TERM_WIDTH
condition|)
block|{
name|pp
operator|->
name|p_curx
operator|=
literal|0
expr_stmt|;
name|pp
operator|->
name|p_cury
operator|++
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|putc
argument_list|(
name|ch
argument_list|,
name|pp
operator|->
name|p_output
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * outstr:  *	Put out a string of the given length.  */
end_comment

begin_expr_stmt
name|outstr
argument_list|(
name|pp
argument_list|,
name|str
argument_list|,
name|len
argument_list|)
specifier|register
name|PLAYER
operator|*
name|pp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|pp
operator|->
name|p_curx
operator|+=
name|len
expr_stmt|;
name|pp
operator|->
name|p_cury
operator|+=
operator|(
name|pp
operator|->
name|p_curx
operator|/
name|TERM_WIDTH
operator|)
expr_stmt|;
name|pp
operator|->
name|p_curx
operator|%=
name|TERM_WIDTH
expr_stmt|;
while|while
condition|(
name|len
operator|--
condition|)
operator|(
name|void
operator|)
name|putc
argument_list|(
operator|*
name|str
operator|++
argument_list|,
name|pp
operator|->
name|p_output
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * clrscr:  *	Clear the screen, and reset the current position on the screen.  */
end_comment

begin_expr_stmt
name|clrscr
argument_list|(
name|pp
argument_list|)
specifier|register
name|PLAYER
operator|*
name|pp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|sendcom
argument_list|(
name|pp
argument_list|,
name|CLEAR
argument_list|)
expr_stmt|;
name|pp
operator|->
name|p_cury
operator|=
literal|0
expr_stmt|;
name|pp
operator|->
name|p_curx
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * ce:  *	Clear to the end of the line  */
end_comment

begin_macro
name|ce
argument_list|(
argument|pp
argument_list|)
end_macro

begin_decl_stmt
name|PLAYER
modifier|*
name|pp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sendcom
argument_list|(
name|pp
argument_list|,
name|CLRTOEOL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * ref;  *	Refresh the screen  */
end_comment

begin_expr_stmt
name|ref
argument_list|(
name|pp
argument_list|)
specifier|register
name|PLAYER
operator|*
name|pp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|sendcom
argument_list|(
name|pp
argument_list|,
name|REFRESH
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * sendcom:  *	Send a command to the given user  */
end_comment

begin_comment
comment|/* VARARGS2 */
end_comment

begin_expr_stmt
name|sendcom
argument_list|(
name|pp
argument_list|,
name|command
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|)
specifier|register
name|PLAYER
operator|*
name|pp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arg1
decl_stmt|,
name|arg2
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|(
name|void
operator|)
name|putc
argument_list|(
name|command
argument_list|,
name|pp
operator|->
name|p_output
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|command
operator|&
literal|0377
condition|)
block|{
case|case
name|MOVE
case|:
operator|(
name|void
operator|)
name|putc
argument_list|(
name|arg1
argument_list|,
name|pp
operator|->
name|p_output
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
name|arg2
argument_list|,
name|pp
operator|->
name|p_output
argument_list|)
expr_stmt|;
break|break;
case|case
name|ADDCH
case|:
case|case
name|READY
case|:
operator|(
name|void
operator|)
name|putc
argument_list|(
name|arg1
argument_list|,
name|pp
operator|->
name|p_output
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_block

end_unit

