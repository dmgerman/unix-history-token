begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)talkd.h	5.3 (Berkeley) 7/9/88  */
end_comment

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
name|u_long
name|id_num
decl_stmt|;
comment|/* message id */
name|struct
name|sockaddr
name|addr
decl_stmt|;
name|struct
name|sockaddr
name|ctl_addr
decl_stmt|;
name|long
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
name|u_long
name|id_num
decl_stmt|;
comment|/* message id */
name|struct
name|sockaddr
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

end_unit

