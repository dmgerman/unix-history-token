begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)cribbage.h	5.3 (Berkeley) 6/18/88  */
end_comment

begin_decl_stmt
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
name|CARD
name|turnover
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the starter */
end_comment

begin_decl_stmt
specifier|extern
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
specifier|extern
name|int
name|knownum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of cards we know */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player's score */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* comp's score */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|glimit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to win game */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pgames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player's games won */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cgames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* comp's games won */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gamecount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # games played */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Lastscore
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous score for each */
end_comment

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|iwon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if comp won last */
end_comment

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|explain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player mistakes explained */
end_comment

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if all cuts random */
end_comment

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|quiet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if suppress random mess */
end_comment

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|playing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* currently playing game */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|expl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string for explanation */
end_comment

end_unit

