begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)deck.h	5.3 (Berkeley) 6/18/88  */
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

