begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)fortune.c	5.5 (Berkeley) 6/10/91";
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

begin_comment
comment|/* fortune.c		 Larn is copyrighted 1986 by Noah Morgan. */
end_comment

begin_comment
comment|/*  * function to return a random fortune from the fortune file  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|flines
index|[]
init|=
block|{
literal|"gem value = gem * 2 ^ perfection"
block|,
literal|"sitting down can have unexpected results"
block|,
literal|"don't pry into the affairs of others"
block|,
literal|"drinking can be hazardous to your health"
block|,
literal|"beware of the gusher!"
block|,
literal|"some monsters are greedy"
block|,
literal|"nymphs have light fingers"
block|,
literal|"try kissing a disenchantress!"
block|,
literal|"hammers and brains don't mix"
block|,
literal|"what does a potion of cure dianthroritis taste like?"
block|,
literal|"hit point gain/loss when raising a level depends on constitution"
block|,
literal|"healing a mighty wizard can be exhilarating"
block|,
literal|"be sure to pay your taxes"
block|,
literal|"are Vampires afraid of something?"
block|,
literal|"some dragons can fly"
block|,
literal|"dos thou strive for perfection?"
block|,
literal|"patience is a virtue, unless your daughter dies"
block|,
literal|"what does the Eye of Larn see in its guardian?"
block|,
literal|"a level 25 player casts like crazy!"
block|,
literal|"energy rings affect spell regeneration"
block|,
literal|"difficulty affects regeneration"
block|,
literal|"control of the pesty spirits is most helpful"
block|,
literal|"don't fall into a bottomless pit"
block|,
literal|"dexterity allows you to carry more"
block|,
literal|"you can get 2 points of WC for the price of one"
block|,
literal|"never enter the dungeon naked!  the monsters will laugh at you!"
block|,
literal|"did someone put itching powder in your armor?"
block|,
literal|"you klutz!"
block|,
literal|"avoid opening doors.  you never know whats on the other side."
block|,
literal|"infinite regeneration ---> temptation"
block|,
literal|"the greatest weapon in the game has not the highest Weapon Class"
block|,
literal|"you can't buy the most powerful scroll"
block|,
literal|"identify things before you use them"
block|,
literal|"there's more than one way through a wall"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFORTUNES
value|34
end_define

begin_function
name|char
modifier|*
name|fortune
parameter_list|()
block|{
return|return
operator|(
name|flines
index|[
name|random
argument_list|()
operator|%
name|NFORTUNES
index|]
operator|)
return|;
block|}
end_function

end_unit

