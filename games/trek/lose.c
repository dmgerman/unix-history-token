begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)lose.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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

begin_include
include|#
directive|include
file|<setjmp.h>
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
specifier|extern
name|jmp_buf
name|env
decl_stmt|;
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
name|longjmp
argument_list|(
name|env
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

