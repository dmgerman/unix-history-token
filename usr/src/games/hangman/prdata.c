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
literal|"@(#)prdata.c	5.2 (Berkeley) 6/18/88"
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
comment|/*  * prdata:  *	Print out the current guesses  */
end_comment

begin_macro
name|prdata
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|bool
modifier|*
name|bp
decl_stmt|;
name|move
argument_list|(
name|GUESSY
argument_list|,
name|GUESSX
operator|+
sizeof|sizeof
expr|"Guessed: "
argument_list|)
expr_stmt|;
name|bp
operator|=
name|Guessed
expr_stmt|;
while|while
condition|(
name|bp
operator|<
operator|&
name|Guessed
index|[
literal|26
index|]
condition|)
if|if
condition|(
operator|*
name|bp
operator|++
condition|)
name|addch
argument_list|(
operator|(
name|bp
operator|-
name|Guessed
operator|)
operator|+
literal|'a'
operator|-
literal|1
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|mvprintw
argument_list|(
name|NUMBERY
argument_list|,
name|NUMBERX
operator|+
sizeof|sizeof
expr|"Word #:          "
argument_list|,
literal|"%d"
argument_list|,
name|Wordnum
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|AVGY
argument_list|,
name|AVGX
operator|+
sizeof|sizeof
expr|"Current Average: "
argument_list|,
literal|"%.3f"
argument_list|,
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
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|AVGY
operator|+
literal|1
argument_list|,
name|AVGX
operator|+
sizeof|sizeof
expr|"Overall Average: "
argument_list|,
literal|"%.3f"
argument_list|,
name|Average
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

