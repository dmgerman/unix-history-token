begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)prman.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"hangman.h"
end_include

begin_comment
comment|/*  * prman:  *	Print out the man appropriately for the give number  *	of incorrect guesses.  */
end_comment

begin_macro
name|prman
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|Errors
condition|;
name|i
operator|++
control|)
name|mvaddch
argument_list|(
name|Err_pos
index|[
name|i
index|]
operator|.
name|y
argument_list|,
name|Err_pos
index|[
name|i
index|]
operator|.
name|x
argument_list|,
name|Err_pos
index|[
name|i
index|]
operator|.
name|ch
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|MAXERRS
condition|)
block|{
name|mvaddch
argument_list|(
name|Err_pos
index|[
name|i
index|]
operator|.
name|y
argument_list|,
name|Err_pos
index|[
name|i
index|]
operator|.
name|x
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
block|}
end_block

end_unit

