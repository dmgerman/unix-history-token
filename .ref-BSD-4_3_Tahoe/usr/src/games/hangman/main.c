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
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)main.c	5.2 (Berkeley) 6/18/88"
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
comment|/*  * This game written by Ken Arnold.  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|initscr
argument_list|()
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|die
argument_list|)
expr_stmt|;
name|setup
argument_list|()
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|Wordnum
operator|++
expr_stmt|;
name|playgame
argument_list|()
expr_stmt|;
name|Average
operator|=
operator|(
name|Average
operator|*
operator|(
name|Wordnum
operator|-
literal|1
operator|)
operator|+
name|Errors
operator|)
operator|/
name|Wordnum
expr_stmt|;
block|}
comment|/* NOTREACHED */
block|}
end_function

begin_comment
comment|/*  * die:  *	Die properly.  */
end_comment

begin_macro
name|die
argument_list|()
end_macro

begin_block
block|{
name|mvcur
argument_list|(
literal|0
argument_list|,
name|COLS
operator|-
literal|1
argument_list|,
name|LINES
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|endwin
argument_list|()
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

