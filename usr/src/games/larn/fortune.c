begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)fortune.c	5.5 (Berkeley) %G%"
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

