begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)look_up.c	5.4 (Berkeley) 6/29/88"
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
file|"talk_ctl.h"
end_include

begin_comment
comment|/*  * See if the local daemon has an invitation for us.  */
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
specifier|register
name|CTL_RESPONSE
modifier|*
name|rp
init|=
operator|&
name|response
decl_stmt|;
comment|/* the rest of msg was set up in get_names */
name|msg
operator|.
name|ctl_addr
operator|=
operator|*
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|ctl_addr
expr_stmt|;
name|msg
operator|.
name|ctl_addr
operator|.
name|sa_family
operator|=
name|htons
argument_list|(
name|msg
operator|.
name|ctl_addr
operator|.
name|sa_family
argument_list|)
expr_stmt|;
comment|/* must be initiating a talk */
if|if
condition|(
operator|!
name|look_for_invite
argument_list|(
name|rp
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * There was an invitation waiting for us,  	 * so connect with the other (hopefully waiting) party  	 */
name|current_state
operator|=
literal|"Waiting to connect with caller"
expr_stmt|;
do|do
block|{
if|if
condition|(
name|rp
operator|->
name|addr
operator|.
name|sa_family
operator|!=
name|AF_INET
condition|)
name|p_error
argument_list|(
literal|"Response uses invalid network address"
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|connect
argument_list|(
name|sockt
argument_list|,
operator|&
name|rp
operator|->
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|rp
operator|->
name|addr
argument_list|)
argument_list|)
operator|!=
operator|-
literal|1
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
do|while
condition|(
name|errno
operator|==
name|EINTR
condition|)
do|;
if|if
condition|(
name|errno
operator|==
name|ECONNREFUSED
condition|)
block|{
comment|/* 		 * The caller gave up, but his invitation somehow 		 * was not cleared. Clear it and initiate an  		 * invitation. (We know there are no newer invitations, 		 * the talkd works LIFO.) 		 */
name|ctl_transact
argument_list|(
name|his_machine_addr
argument_list|,
name|msg
argument_list|,
name|DELETE
argument_list|,
name|rp
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
name|p_error
argument_list|(
literal|"Unable to connect with initiator"
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_block

begin_comment
comment|/*  * Look for an invitation on 'machine'  */
end_comment

begin_macro
name|look_for_invite
argument_list|(
argument|rp
argument_list|)
end_macro

begin_decl_stmt
name|CTL_RESPONSE
modifier|*
name|rp
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
name|rp
argument_list|)
expr_stmt|;
comment|/* the switch is for later options, such as multiple invitations */
switch|switch
condition|(
name|rp
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
name|htonl
argument_list|(
name|rp
operator|->
name|id_num
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
default|default:
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

