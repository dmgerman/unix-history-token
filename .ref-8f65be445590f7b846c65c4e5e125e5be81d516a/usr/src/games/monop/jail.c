begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)jail.c	5.3 (Berkeley) %G%"
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
file|"monop.ext"
end_include

begin_comment
comment|/*  *	This routine uses a get-out-of-jail-free card to get the  * player out of jail.  */
end_comment

begin_macro
name|card
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|cur_p
operator|->
name|loc
operator|!=
name|JAIL
condition|)
block|{
name|printf
argument_list|(
literal|"But you're not IN Jail\n"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|cur_p
operator|->
name|num_gojf
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"But you don't HAVE a get out of jail free card\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|ret_card
argument_list|(
name|cur_p
argument_list|)
expr_stmt|;
name|cur_p
operator|->
name|loc
operator|=
literal|10
expr_stmt|;
comment|/* just visiting	*/
name|cur_p
operator|->
name|in_jail
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	This routine returns the players get-out-of-jail-free card  * to a deck.  */
end_comment

begin_macro
name|ret_card
argument_list|(
argument|plr
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|PLAY
modifier|*
name|plr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|plr
operator|->
name|num_gojf
operator|--
expr_stmt|;
if|if
condition|(
name|CC_D
operator|.
name|gojf_used
condition|)
name|CC_D
operator|.
name|gojf_used
operator|=
name|FALSE
expr_stmt|;
else|else
name|CH_D
operator|.
name|gojf_used
operator|=
name|FALSE
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	This routine deals with paying your way out of jail.  */
end_comment

begin_macro
name|pay
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|cur_p
operator|->
name|loc
operator|!=
name|JAIL
condition|)
block|{
name|printf
argument_list|(
literal|"But you're not IN Jail\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|cur_p
operator|->
name|loc
operator|=
literal|10
expr_stmt|;
name|cur_p
operator|->
name|money
operator|-=
literal|50
expr_stmt|;
name|cur_p
operator|->
name|in_jail
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"That cost you $50\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	This routine deals with a move in jail  */
end_comment

begin_macro
name|move_jail
argument_list|(
argument|r1
argument_list|,
argument|r2
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|r1
decl_stmt|,
name|r2
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|r1
operator|!=
name|r2
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, that doesn't get you out\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
operator|(
name|cur_p
operator|->
name|in_jail
operator|)
operator|==
literal|3
condition|)
block|{
name|printf
argument_list|(
literal|"It's your third turn and you didn't roll doubles.  You have to pay $50\n"
argument_list|)
expr_stmt|;
name|cur_p
operator|->
name|money
operator|-=
literal|50
expr_stmt|;
name|moveit
label|:
name|cur_p
operator|->
name|loc
operator|=
literal|10
expr_stmt|;
name|cur_p
operator|->
name|in_jail
operator|=
literal|0
expr_stmt|;
name|move
argument_list|(
name|r1
operator|+
name|r2
argument_list|)
expr_stmt|;
name|r1
operator|=
name|r2
operator|-
literal|1
expr_stmt|;
comment|/* kludge: stop new roll w/doub	*/
return|return
name|TRUE
return|;
block|}
return|return
name|FALSE
return|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"Double roll gets you out.\n"
argument_list|)
expr_stmt|;
goto|goto
name|moveit
goto|;
block|}
block|}
end_block

begin_macro
name|printturn
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|cur_p
operator|->
name|loc
operator|!=
name|JAIL
condition|)
return|return;
name|printf
argument_list|(
literal|"(This is your "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cur_p
operator|->
name|in_jail
condition|)
block|{
case|case
literal|0
case|:
name|printf
argument_list|(
literal|"1st"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|printf
argument_list|(
literal|"2nd"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|printf
argument_list|(
literal|"3rd (and final)"
argument_list|)
expr_stmt|;
break|break;
block|}
name|printf
argument_list|(
literal|" turn in JAIL)\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

