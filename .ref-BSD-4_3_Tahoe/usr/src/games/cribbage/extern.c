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
literal|"@(#)extern.c	5.3 (Berkeley) 6/18/88"
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

