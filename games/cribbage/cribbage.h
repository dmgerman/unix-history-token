begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cribbage.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/defs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_function_decl
name|void
name|addmsg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adjust
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|CARD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|anymove
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|anysumto
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bye
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cchose
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cdiscard
parameter_list|(
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chkscr
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|comphand
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cremove
parameter_list|(
name|CARD
parameter_list|,
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cut
parameter_list|(
name|BOOLEAN
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|deal
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|discard
parameter_list|(
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endmsg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eq
parameter_list|(
name|CARD
parameter_list|,
name|CARD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fifteens
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|game
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gamescore
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getuchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|incard
parameter_list|(
name|CARD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|infrom
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|instructions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isone
parameter_list|(
name|CARD
parameter_list|,
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makeboard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makedeck
parameter_list|(
name|CARD
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makeknown
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgcard
parameter_list|(
name|CARD
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgcrd
parameter_list|(
name|CARD
parameter_list|,
name|BOOLEAN
parameter_list|,
name|char
modifier|*
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|number
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|numofval
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pairuns
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|peg
parameter_list|(
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pegscore
parameter_list|(
name|CARD
parameter_list|,
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|playhand
parameter_list|(
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|plyrhand
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prcard
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|CARD
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prcrib
parameter_list|(
name|BOOLEAN
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prhand
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|,
name|WINDOW
modifier|*
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printcard
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|CARD
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prpeg
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prtable
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|score
parameter_list|(
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scorehand
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|CARD
parameter_list|,
name|int
parameter_list|,
name|BOOLEAN
parameter_list|,
name|BOOLEAN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|shuffle
parameter_list|(
name|CARD
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sorthand
parameter_list|(
name|CARD
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wait_for
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

