begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_comment
comment|/* **  PRINT OUT LOSER MESSAGES ** **	The messages are printed out, the score is computed and **	printed, and the game is restarted.  Oh yeh, any special **	actions which need be taken are taken. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Losemsg
index|[]
block|{
literal|"You ran out of time"
operator|,
literal|"You ran out of energy"
operator|,
literal|"You have been destroyed"
operator|,
literal|"You ran into the negative energy barrier"
operator|,
literal|"You destroyed yourself by nova'ing that star"
operator|,
literal|"You have been caught in a supernova"
operator|,
literal|"You just suffocated in outer space"
operator|,
literal|"You could not be rematerialized"
operator|,
literal|"\n\032\014 ***
literal|Ship's hull has imploded
literal|***"
operator|,
literal|"You have burned up in a star"
operator|,
literal|"Well, you destroyed yourself, but it didn't do any good"
operator|,
literal|"You have been captured by Klingons and mercilessly tortured"
operator|,
literal|"Your last crew member died"
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|reset
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

