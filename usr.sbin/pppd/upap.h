begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * upap.h - User/Password Authentication Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Packet header = Code, id, length.  */
end_comment

begin_define
define|#
directive|define
name|UPAP_HEADERLEN
value|(sizeof (u_char) + sizeof (u_char) + sizeof (u_short))
end_define

begin_comment
comment|/*  * UPAP codes.  */
end_comment

begin_define
define|#
directive|define
name|UPAP_AUTHREQ
value|1
end_define

begin_comment
comment|/* Authenticate-Request */
end_comment

begin_define
define|#
directive|define
name|UPAP_AUTHACK
value|2
end_define

begin_comment
comment|/* Authenticate-Ack */
end_comment

begin_define
define|#
directive|define
name|UPAP_AUTHNAK
value|3
end_define

begin_comment
comment|/* Authenticate-Nak */
end_comment

begin_comment
comment|/*  * Each interface is described by upap structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|upap_state
block|{
name|int
name|us_unit
decl_stmt|;
comment|/* Interface unit number */
name|char
modifier|*
name|us_user
decl_stmt|;
comment|/* User */
name|int
name|us_userlen
decl_stmt|;
comment|/* User length */
name|char
modifier|*
name|us_passwd
decl_stmt|;
comment|/* Password */
name|int
name|us_passwdlen
decl_stmt|;
comment|/* Password length */
name|int
name|us_clientstate
decl_stmt|;
comment|/* Client state */
name|int
name|us_serverstate
decl_stmt|;
comment|/* Server state */
name|u_char
name|us_id
decl_stmt|;
comment|/* Current id */
name|int
name|us_timeouttime
decl_stmt|;
comment|/* Timeout (seconds) for auth-req retrans. */
name|int
name|us_transmits
decl_stmt|;
comment|/* Number of auth-reqs sent */
name|int
name|us_maxtransmits
decl_stmt|;
comment|/* Maximum number of auth-reqs to send */
name|int
name|us_reqtimeout
decl_stmt|;
comment|/* Time to wait for auth-req from peer */
block|}
name|upap_state
typedef|;
end_typedef

begin_comment
comment|/*  * Client states.  */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_INITIAL
value|0
end_define

begin_comment
comment|/* Connection down */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_CLOSED
value|1
end_define

begin_comment
comment|/* Connection up, haven't requested auth */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_PENDING
value|2
end_define

begin_comment
comment|/* Connection down, have requested auth */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_AUTHREQ
value|3
end_define

begin_comment
comment|/* We've sent an Authenticate-Request */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_OPEN
value|4
end_define

begin_comment
comment|/* We've received an Ack */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_BADAUTH
value|5
end_define

begin_comment
comment|/* We've received a Nak */
end_comment

begin_comment
comment|/*  * Server states.  */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_INITIAL
value|0
end_define

begin_comment
comment|/* Connection down */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_CLOSED
value|1
end_define

begin_comment
comment|/* Connection up, haven't requested auth */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_PENDING
value|2
end_define

begin_comment
comment|/* Connection down, have requested auth */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_LISTEN
value|3
end_define

begin_comment
comment|/* Listening for an Authenticate */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_OPEN
value|4
end_define

begin_comment
comment|/* We've sent an Ack */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_BADAUTH
value|5
end_define

begin_comment
comment|/* We've sent a Nak */
end_comment

begin_comment
comment|/*  * Timeouts.  */
end_comment

begin_define
define|#
directive|define
name|UPAP_DEFTIMEOUT
value|3
end_define

begin_comment
comment|/* Timeout (seconds) for retransmitting req */
end_comment

begin_define
define|#
directive|define
name|UPAP_DEFREQTIME
value|30
end_define

begin_comment
comment|/* Time to wait for auth-req from peer */
end_comment

begin_decl_stmt
specifier|extern
name|upap_state
name|upap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_authwithpeer
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_authpeer
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protent
name|pap_protent
decl_stmt|;
end_decl_stmt

end_unit

