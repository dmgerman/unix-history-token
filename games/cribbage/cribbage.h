begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cribbage.h	8.1 (Berkeley) 5/31/93  */
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

begin_decl_stmt
name|void
name|addmsg
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|adjust
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|CARD
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|anymove
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|anysumto
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bye
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cchose
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cdiscard
name|__P
argument_list|(
operator|(
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chkscr
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|comphand
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cremove
name|__P
argument_list|(
operator|(
name|CARD
operator|,
name|CARD
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cut
name|__P
argument_list|(
operator|(
name|BOOLEAN
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|deal
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|discard
name|__P
argument_list|(
operator|(
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|do_wait
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|endmsg
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eq
name|__P
argument_list|(
operator|(
name|CARD
operator|,
name|CARD
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifteens
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|game
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gamescore
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getline
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getuchar
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|incard
name|__P
argument_list|(
operator|(
name|CARD
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|infrom
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|instructions
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isone
name|__P
argument_list|(
operator|(
name|CARD
operator|,
name|CARD
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|makeboard
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|makedeck
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|makeknown
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|msg
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msgcard
name|__P
argument_list|(
operator|(
name|CARD
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msgcrd
name|__P
argument_list|(
operator|(
name|CARD
operator|,
name|BOOLEAN
operator|,
name|char
operator|*
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|number
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numofval
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pairuns
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|peg
name|__P
argument_list|(
operator|(
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pegscore
name|__P
argument_list|(
operator|(
name|CARD
operator|,
name|CARD
index|[]
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|playhand
name|__P
argument_list|(
operator|(
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|plyrhand
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prcard
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|CARD
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prcrib
name|__P
argument_list|(
operator|(
name|BOOLEAN
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prhand
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|,
name|WINDOW
operator|*
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|printcard
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|CARD
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prpeg
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prtable
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|readchar
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rint
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|score
name|__P
argument_list|(
operator|(
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scorehand
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|CARD
operator|,
name|int
operator|,
name|BOOLEAN
operator|,
name|BOOLEAN
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|shuffle
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sorthand
name|__P
argument_list|(
operator|(
name|CARD
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wait_for
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

