begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)deck.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_comment
comment|/*  * define structure of a deck of cards and other related things  */
end_comment

begin_define
define|#
directive|define
name|CARDS
value|52
end_define

begin_comment
comment|/* number cards in deck */
end_comment

begin_define
define|#
directive|define
name|RANKS
value|13
end_define

begin_comment
comment|/* number ranks in deck */
end_comment

begin_define
define|#
directive|define
name|SUITS
value|4
end_define

begin_comment
comment|/* number suits in deck */
end_comment

begin_define
define|#
directive|define
name|CINHAND
value|4
end_define

begin_comment
comment|/* # cards in cribbage hand */
end_comment

begin_define
define|#
directive|define
name|FULLHAND
value|6
end_define

begin_comment
comment|/* # cards in dealt hand */
end_comment

begin_define
define|#
directive|define
name|LGAME
value|121
end_define

begin_comment
comment|/* number points in a game */
end_comment

begin_define
define|#
directive|define
name|SGAME
value|61
end_define

begin_comment
comment|/* # points in a short game */
end_comment

begin_define
define|#
directive|define
name|SPADES
value|0
end_define

begin_comment
comment|/* value of each suit */
end_comment

begin_define
define|#
directive|define
name|HEARTS
value|1
end_define

begin_define
define|#
directive|define
name|DIAMONDS
value|2
end_define

begin_define
define|#
directive|define
name|CLUBS
value|3
end_define

begin_define
define|#
directive|define
name|ACE
value|0
end_define

begin_comment
comment|/* value of each rank */
end_comment

begin_define
define|#
directive|define
name|TWO
value|1
end_define

begin_define
define|#
directive|define
name|THREE
value|2
end_define

begin_define
define|#
directive|define
name|FOUR
value|3
end_define

begin_define
define|#
directive|define
name|FIVE
value|4
end_define

begin_define
define|#
directive|define
name|SIX
value|5
end_define

begin_define
define|#
directive|define
name|SEVEN
value|6
end_define

begin_define
define|#
directive|define
name|EIGHT
value|7
end_define

begin_define
define|#
directive|define
name|NINE
value|8
end_define

begin_define
define|#
directive|define
name|TEN
value|9
end_define

begin_define
define|#
directive|define
name|JACK
value|10
end_define

begin_define
define|#
directive|define
name|QUEEN
value|11
end_define

begin_define
define|#
directive|define
name|KING
value|12
end_define

begin_define
define|#
directive|define
name|EMPTY
value|13
end_define

begin_define
define|#
directive|define
name|VAL
parameter_list|(
name|c
parameter_list|)
value|( (c)< 9 ? (c)+1 : 10 )
end_define

begin_comment
comment|/* val of rank */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rank
decl_stmt|;
name|int
name|suit
decl_stmt|;
block|}
name|CARD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|BOOLEAN
typedef|;
end_typedef

end_unit

