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
unit|static char sccsid[] = "@(#)invite.c	8.1 (Berkeley) 6/6/93";
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
literal|"$Id$"
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
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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
comment|/*  * There wasn't an invitation waiting, so send a request containing  * our sockt address to the remote talk daemon so it can invite  * him  */
end_comment

begin_comment
comment|/*  * The msg.id's for the invitations  * on the local and remote machines.  * These are used to delete the  * invitations.  */
end_comment

begin_decl_stmt
name|int
name|local_id
decl_stmt|,
name|remote_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|invitebuf
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|invite_remote
parameter_list|()
block|{
name|int
name|nfd
decl_stmt|,
name|read_mask
decl_stmt|,
name|template
decl_stmt|,
name|new_sockt
decl_stmt|;
name|struct
name|itimerval
name|itimer
decl_stmt|;
name|CTL_RESPONSE
name|response
decl_stmt|;
name|itimer
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|RING_WAIT
expr_stmt|;
name|itimer
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|itimer
operator|.
name|it_interval
operator|=
name|itimer
operator|.
name|it_value
expr_stmt|;
if|if
condition|(
name|listen
argument_list|(
name|sockt
argument_list|,
literal|5
argument_list|)
operator|!=
literal|0
condition|)
name|p_error
argument_list|(
literal|"Error on attempt to listen for caller"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MSG_EOR
comment|/* copy new style sockaddr to old, swap family (short in old) */
name|msg
operator|.
name|addr
operator|=
operator|*
operator|(
expr|struct
name|osockaddr
operator|*
operator|)
operator|&
name|my_addr
expr_stmt|;
comment|/* XXX new to old  style*/
name|msg
operator|.
name|addr
operator|.
name|sa_family
operator|=
name|htons
argument_list|(
name|my_addr
operator|.
name|sin_family
argument_list|)
expr_stmt|;
else|#
directive|else
name|msg
operator|.
name|addr
operator|=
operator|*
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|my_addr
expr_stmt|;
endif|#
directive|endif
name|msg
operator|.
name|id_num
operator|=
name|htonl
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* an impossible id_num */
name|invitation_waiting
operator|=
literal|1
expr_stmt|;
name|announce_invite
argument_list|()
expr_stmt|;
comment|/* 	 * Shut off the automatic messages for a while, 	 * so we can use the interupt timer to resend the invitation 	 */
name|end_msgs
argument_list|()
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|itimer
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|message
argument_list|(
literal|"Waiting for your party to respond"
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|re_invite
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|setjmp
argument_list|(
name|invitebuf
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|new_sockt
operator|=
name|accept
argument_list|(
name|sockt
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
continue|continue;
name|p_error
argument_list|(
literal|"Unable to connect with your party"
argument_list|)
expr_stmt|;
block|}
name|close
argument_list|(
name|sockt
argument_list|)
expr_stmt|;
name|sockt
operator|=
name|new_sockt
expr_stmt|;
comment|/* 	 * Have the daemons delete the invitations now that we 	 * have connected. 	 */
name|current_state
operator|=
literal|"Waiting for your party to respond"
expr_stmt|;
name|start_msgs
argument_list|()
expr_stmt|;
name|msg
operator|.
name|id_num
operator|=
name|htonl
argument_list|(
name|local_id
argument_list|)
expr_stmt|;
name|ctl_transact
argument_list|(
name|my_machine_addr
argument_list|,
name|msg
argument_list|,
name|DELETE
argument_list|,
operator|&
name|response
argument_list|)
expr_stmt|;
name|msg
operator|.
name|id_num
operator|=
name|htonl
argument_list|(
name|remote_id
argument_list|)
expr_stmt|;
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
name|invitation_waiting
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Routine called on interupt to re-invite the callee  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|re_invite
parameter_list|(
name|signo
parameter_list|)
name|int
name|signo
decl_stmt|;
block|{
name|message
argument_list|(
literal|"Ringing your party again"
argument_list|)
expr_stmt|;
name|waddch
argument_list|(
name|my_win
operator|.
name|x_win
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|current_line
operator|<
name|my_win
operator|.
name|x_nlines
operator|-
literal|1
condition|)
name|current_line
operator|++
expr_stmt|;
comment|/* force a re-announce */
name|msg
operator|.
name|id_num
operator|=
name|htonl
argument_list|(
name|remote_id
operator|+
literal|1
argument_list|)
expr_stmt|;
name|announce_invite
argument_list|()
expr_stmt|;
name|longjmp
argument_list|(
name|invitebuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|char
modifier|*
name|answers
index|[]
init|=
block|{
literal|"answer #0"
block|,
comment|/* SUCCESS */
literal|"Your party is not logged on"
block|,
comment|/* NOT_HERE */
literal|"Target machine is too confused to talk to us"
block|,
comment|/* FAILED */
literal|"Target machine does not recognize us"
block|,
comment|/* MACHINE_UNKNOWN */
literal|"Your party is refusing messages"
block|,
comment|/* PERMISSION_REFUSED */
literal|"Target machine can not handle remote talk"
block|,
comment|/* UNKNOWN_REQUEST */
literal|"Target machine indicates protocol mismatch"
block|,
comment|/* BADVERSION */
literal|"Target machine indicates protocol botch (addr)"
block|,
comment|/* BADADDR */
literal|"Target machine indicates protocol botch (ctl_addr)"
block|,
comment|/* BADCTLADDR */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NANSWERS
value|(sizeof (answers) / sizeof (answers[0]))
end_define

begin_comment
comment|/*  * Transmit the invitation and process the response  */
end_comment

begin_function
name|void
name|announce_invite
parameter_list|()
block|{
name|CTL_RESPONSE
name|response
decl_stmt|;
name|current_state
operator|=
literal|"Trying to connect to your party's talk daemon"
expr_stmt|;
name|ctl_transact
argument_list|(
name|his_machine_addr
argument_list|,
name|msg
argument_list|,
name|ANNOUNCE
argument_list|,
operator|&
name|response
argument_list|)
expr_stmt|;
name|remote_id
operator|=
name|response
operator|.
name|id_num
expr_stmt|;
if|if
condition|(
name|response
operator|.
name|answer
operator|!=
name|SUCCESS
condition|)
block|{
if|if
condition|(
name|response
operator|.
name|answer
operator|<
name|NANSWERS
condition|)
name|message
argument_list|(
name|answers
index|[
name|response
operator|.
name|answer
index|]
argument_list|)
expr_stmt|;
name|quit
argument_list|()
expr_stmt|;
block|}
comment|/* leave the actual invitation on my talk daemon */
name|ctl_transact
argument_list|(
name|my_machine_addr
argument_list|,
name|msg
argument_list|,
name|LEAVE_INVITE
argument_list|,
operator|&
name|response
argument_list|)
expr_stmt|;
name|local_id
operator|=
name|response
operator|.
name|id_num
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Tell the daemon to remove your invitation  */
end_comment

begin_function
name|void
name|send_delete
parameter_list|()
block|{
name|msg
operator|.
name|type
operator|=
name|DELETE
expr_stmt|;
comment|/* 	 * This is just a extra clean up, so just send it 	 * and don't wait for an answer 	 */
name|msg
operator|.
name|id_num
operator|=
name|htonl
argument_list|(
name|remote_id
argument_list|)
expr_stmt|;
name|daemon_addr
operator|.
name|sin_addr
operator|=
name|his_machine_addr
expr_stmt|;
if|if
condition|(
name|sendto
argument_list|(
name|ctl_sockt
argument_list|,
operator|&
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|daemon_addr
argument_list|,
sizeof|sizeof
argument_list|(
name|daemon_addr
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
condition|)
name|warn
argument_list|(
literal|"send_delete (remote)"
argument_list|)
expr_stmt|;
name|msg
operator|.
name|id_num
operator|=
name|htonl
argument_list|(
name|local_id
argument_list|)
expr_stmt|;
name|daemon_addr
operator|.
name|sin_addr
operator|=
name|my_machine_addr
expr_stmt|;
if|if
condition|(
name|sendto
argument_list|(
name|ctl_sockt
argument_list|,
operator|&
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|daemon_addr
argument_list|,
sizeof|sizeof
argument_list|(
name|daemon_addr
argument_list|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
condition|)
name|warn
argument_list|(
literal|"send_delete (local)"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

