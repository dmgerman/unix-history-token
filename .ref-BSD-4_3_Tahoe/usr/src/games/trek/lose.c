begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)lose.c	5.4 (Berkeley) 6/18/88"
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
file|"trek.h"
end_include

begin_comment
comment|/* **  PRINT OUT LOSER MESSAGES ** **	The messages are printed out, the score is computed and **	printed, and the game is restarted.  Oh yeh, any special **	actions which need be taken are taken. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Losemsg
index|[]
init|=
block|{
literal|"You ran out of time"
block|,
literal|"You ran out of energy"
block|,
literal|"You have been destroyed"
block|,
literal|"You ran into the negative energy barrier"
block|,
literal|"You destroyed yourself by nova'ing that star"
block|,
literal|"You have been caught in a supernova"
block|,
literal|"You just suffocated in outer space"
block|,
literal|"You could not be rematerialized"
block|,
literal|"\n\032\014 ***\07 Ship's hull has imploded\07 ***"
block|,
literal|"You have burned up in a star"
block|,
literal|"Well, you destroyed yourself, but it didn't do any good"
block|,
literal|"You have been captured by Klingons and mercilessly tortured"
block|,
literal|"Your last crew member died"
block|, }
decl_stmt|;
end_decl_stmt

begin_macro
name|lose
argument_list|(
argument|why
argument_list|)
end_macro

begin_decl_stmt
name|int
name|why
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|Game
operator|.
name|killed
operator|=
literal|1
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n%s\n"
argument_list|,
name|Losemsg
index|[
name|why
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|why
condition|)
block|{
case|case
name|L_NOTIME
case|:
name|Game
operator|.
name|killed
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|Move
operator|.
name|endgame
operator|=
operator|-
literal|1
expr_stmt|;
name|score
argument_list|()
expr_stmt|;
name|skiptonl
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

