begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)extern.c	8.1 (Berkeley) 5/31/93";
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
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|"deck.h"
end_include

begin_include
include|#
directive|include
file|"cribbage.h"
end_include

begin_decl_stmt
name|bool
name|explain
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player mistakes explained */
end_comment

begin_decl_stmt
name|bool
name|iwon
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if comp won last game */
end_comment

begin_decl_stmt
name|bool
name|quiet
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if suppress random mess */
end_comment

begin_decl_stmt
name|bool
name|rflag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if all cuts random */
end_comment

begin_decl_stmt
name|char
name|expl
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* explanation */
end_comment

begin_decl_stmt
name|int
name|cgames
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number games comp won */
end_comment

begin_decl_stmt
name|int
name|cscore
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* comp score in this game */
end_comment

begin_decl_stmt
name|int
name|gamecount
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number games played */
end_comment

begin_decl_stmt
name|int
name|glimit
init|=
name|LGAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* game playe to glimit */
end_comment

begin_decl_stmt
name|int
name|knownum
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of cards we know */
end_comment

begin_decl_stmt
name|int
name|pgames
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number games player won */
end_comment

begin_decl_stmt
name|int
name|pscore
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player score in this game */
end_comment

begin_decl_stmt
name|CARD
name|chand
index|[
name|FULLHAND
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* computer's hand */
end_comment

begin_decl_stmt
name|CARD
name|crib
index|[
name|CINHAND
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the crib */
end_comment

begin_decl_stmt
name|CARD
name|deck
index|[
name|CARDS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a deck */
end_comment

begin_decl_stmt
name|CARD
name|known
index|[
name|CARDS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cards we have seen */
end_comment

begin_decl_stmt
name|CARD
name|phand
index|[
name|FULLHAND
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player's hand */
end_comment

begin_decl_stmt
name|CARD
name|turnover
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the starter */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|Compwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* computer's hand window */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|Msgwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* messages for the player */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|Playwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player's hand window */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|Tablewin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table window */
end_comment

end_unit

