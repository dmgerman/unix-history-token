begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)look_up.c	8.1 (Berkeley) 6/6/93";
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<protocols/talkd.h>
end_include

begin_include
include|#
directive|include
file|"talk_ctl.h"
end_include

begin_include
include|#
directive|include
file|"talk.h"
end_include

begin_comment
comment|/*  * See if the local daemon has an invitation for us.  */
end_comment

begin_function
name|int
name|check_local
parameter_list|()
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
ifdef|#
directive|ifdef
name|MSG_EOR
comment|/* copy new style sockaddr to old, swap family (short in old) */
name|msg
operator|.
name|ctl_addr
operator|=
operator|*
operator|(
expr|struct
name|osockaddr
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
name|ctl_addr
operator|.
name|sin_family
argument_list|)
expr_stmt|;
else|#
directive|else
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
endif|#
directive|endif
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
comment|/* 	 * There was an invitation waiting for us, 	 * so connect with the other (hopefully waiting) party 	 */
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
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
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
comment|/* 		 * The caller gave up, but his invitation somehow 		 * was not cleared. Clear it and initiate an 		 * invitation. (We know there are no newer invitations, 		 * the talkd works LIFO.) 		 */
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
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Look for an invitation on 'machine'  */
end_comment

begin_function
name|int
name|look_for_invite
parameter_list|(
name|rp
parameter_list|)
name|CTL_RESPONSE
modifier|*
name|rp
decl_stmt|;
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
end_function

end_unit

