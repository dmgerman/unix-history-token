begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: look_up.c 1.2 83/03/28 00:34:22 moore Exp $ */
end_comment

begin_include
include|#
directive|include
file|"talk_ctl.h"
end_include

begin_comment
comment|/* see if the local daemon has a invitation for us */
end_comment

begin_macro
name|check_local
argument_list|()
end_macro

begin_block
block|{
name|CTL_RESPONSE
name|response
decl_stmt|;
comment|/* the rest of msg was set up in get_names */
name|msg
operator|.
name|ctl_addr
operator|=
name|ctl_addr
expr_stmt|;
if|if
condition|(
operator|!
name|look_for_invite
argument_list|(
operator|&
name|response
argument_list|)
condition|)
block|{
comment|/* we must be initiating a talk */
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * there was an invitation waiting for us,  	 * so connect with the other (hopefully waiting) party  	 */
name|current_state
operator|=
literal|"Waiting to connect with caller"
expr_stmt|;
while|while
condition|(
name|connect
argument_list|(
name|sockt
argument_list|,
operator|&
name|response
operator|.
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|response
operator|.
name|addr
argument_list|)
argument_list|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|ECONNREFUSED
condition|)
block|{
comment|/* the caller gave up, but his invitation somehow 		 * was not cleared. Clear it and initiate an  		 * invitation. (We know there are no newer invitations, 		 * the talkd works LIFO.) 		 */
name|ctl_transact
argument_list|(
name|his_machine_addr
argument_list|,
name|msg
argument_list|,
name|DELETE
argument_list|,
operator|&
name|response
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|sockt
argument_list|)
expr_stmt|;
name|open_sockt
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
block|{
comment|/* we have returned from an interupt handler */
continue|continue;
block|}
else|else
block|{
name|p_error
argument_list|(
literal|"Unable to connect with initiator"
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/* look for an invitation on 'machine' */
end_comment

begin_macro
name|look_for_invite
argument_list|(
argument|response
argument_list|)
end_macro

begin_decl_stmt
name|CTL_RESPONSE
modifier|*
name|response
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|in_addr
name|machine_addr
decl_stmt|;
name|current_state
operator|=
literal|"Checking for invitation on caller's machine"
expr_stmt|;
name|ctl_transact
argument_list|(
name|his_machine_addr
argument_list|,
name|msg
argument_list|,
name|LOOK_UP
argument_list|,
name|response
argument_list|)
expr_stmt|;
comment|/* the switch is for later options, such as multiple  	   invitations */
switch|switch
condition|(
name|response
operator|->
name|answer
condition|)
block|{
case|case
name|SUCCESS
case|:
name|msg
operator|.
name|id_num
operator|=
name|response
operator|->
name|id_num
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
default|default :
comment|/* there wasn't an invitation waiting for us */
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_block

end_unit

