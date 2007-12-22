begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)talkd.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTOCOLS_TALKD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROTOCOLS_TALKD_H_
end_define

begin_comment
comment|/*  * This describes the protocol used by the talk server and clients.  *  * The talk server acts a repository of invitations, responding to  * requests by clients wishing to rendezvous for the purpose of  * holding a conversation.  In normal operation, a client, the caller,  * initiates a rendezvous by sending a CTL_MSG to the server of  * type LOOK_UP.  This causes the server to search its invitation  * tables to check if an invitation currently exists for the caller  * (to speak to the callee specified in the message).  If the lookup  * fails, the caller then sends an ANNOUNCE message causing the server  * to broadcast an announcement on the callee's login ports requesting  * contact.  When the callee responds, the local server uses the  * recorded invitation to respond with the appropriate rendezvous  * address and the caller and callee client programs establish a  * stream connection through which the conversation takes place.  */
end_comment

begin_comment
comment|/*  * Client->server request message format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|vers
decl_stmt|;
comment|/* protocol version */
name|u_char
name|type
decl_stmt|;
comment|/* request type, see below */
name|u_char
name|answer
decl_stmt|;
comment|/* not used */
name|u_char
name|pad
decl_stmt|;
name|u_int32_t
name|id_num
decl_stmt|;
comment|/* message id */
name|struct
name|osockaddr
name|addr
decl_stmt|;
comment|/* old (4.3) style */
name|struct
name|osockaddr
name|ctl_addr
decl_stmt|;
comment|/* old (4.3) style */
name|int32_t
name|pid
decl_stmt|;
comment|/* caller's process id */
define|#
directive|define
name|NAME_SIZE
value|12
name|char
name|l_name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
comment|/* caller's name */
name|char
name|r_name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
comment|/* callee's name */
define|#
directive|define
name|TTY_SIZE
value|16
name|char
name|r_tty
index|[
name|TTY_SIZE
index|]
decl_stmt|;
comment|/* callee's tty name */
block|}
name|CTL_MSG
typedef|;
end_typedef

begin_comment
comment|/*  * Server->client response message format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|vers
decl_stmt|;
comment|/* protocol version */
name|u_char
name|type
decl_stmt|;
comment|/* type of request message, see below */
name|u_char
name|answer
decl_stmt|;
comment|/* respose to request message, see below */
name|u_char
name|pad
decl_stmt|;
name|u_int32_t
name|id_num
decl_stmt|;
comment|/* message id */
name|struct
name|osockaddr
name|addr
decl_stmt|;
comment|/* address for establishing conversation */
block|}
name|CTL_RESPONSE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TALK_VERSION
value|1
end_define

begin_comment
comment|/* protocol version */
end_comment

begin_comment
comment|/* message type values */
end_comment

begin_define
define|#
directive|define
name|LEAVE_INVITE
value|0
end_define

begin_comment
comment|/* leave invitation with server */
end_comment

begin_define
define|#
directive|define
name|LOOK_UP
value|1
end_define

begin_comment
comment|/* check for invitation by callee */
end_comment

begin_define
define|#
directive|define
name|DELETE
value|2
end_define

begin_comment
comment|/* delete invitation by caller */
end_comment

begin_define
define|#
directive|define
name|ANNOUNCE
value|3
end_define

begin_comment
comment|/* announce invitation by caller */
end_comment

begin_comment
comment|/* answer values */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_comment
comment|/* operation completed properly */
end_comment

begin_define
define|#
directive|define
name|NOT_HERE
value|1
end_define

begin_comment
comment|/* callee not logged in */
end_comment

begin_define
define|#
directive|define
name|FAILED
value|2
end_define

begin_comment
comment|/* operation failed for unexplained reason */
end_comment

begin_define
define|#
directive|define
name|MACHINE_UNKNOWN
value|3
end_define

begin_comment
comment|/* caller's machine name unknown */
end_comment

begin_define
define|#
directive|define
name|PERMISSION_DENIED
value|4
end_define

begin_comment
comment|/* callee's tty doesn't permit announce */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_REQUEST
value|5
end_define

begin_comment
comment|/* request has invalid type value */
end_comment

begin_define
define|#
directive|define
name|BADVERSION
value|6
end_define

begin_comment
comment|/* request has invalid protocol version */
end_comment

begin_define
define|#
directive|define
name|BADADDR
value|7
end_define

begin_comment
comment|/* request has invalid addr value */
end_comment

begin_define
define|#
directive|define
name|BADCTLADDR
value|8
end_define

begin_comment
comment|/* request has invalid ctl_addr value */
end_comment

begin_comment
comment|/*  * Operational parameters.  */
end_comment

begin_define
define|#
directive|define
name|MAX_LIFE
value|60
end_define

begin_comment
comment|/* max time daemon saves invitations */
end_comment

begin_comment
comment|/* RING_WAIT should be 10's of seconds less than MAX_LIFE */
end_comment

begin_define
define|#
directive|define
name|RING_WAIT
value|30
end_define

begin_comment
comment|/* time to wait before resending invitation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TALKD_H_ */
end_comment

end_unit

