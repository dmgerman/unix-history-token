begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * upap.h - User/Password Authentication Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
name|UPAP_AUTH
value|1
end_define

begin_comment
comment|/* Authenticate */
end_comment

begin_define
define|#
directive|define
name|UPAP_AUTHACK
value|2
end_define

begin_comment
comment|/* Authenticate Ack */
end_comment

begin_define
define|#
directive|define
name|UPAP_AUTHNAK
value|3
end_define

begin_comment
comment|/* Authenticate Nak */
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
name|int
name|us_flags
decl_stmt|;
comment|/* Flags */
name|u_char
name|us_id
decl_stmt|;
comment|/* Current id */
name|int
name|us_timeouttime
decl_stmt|;
comment|/* Timeout time in milliseconds */
name|int
name|us_retransmits
decl_stmt|;
comment|/* Number of retransmissions */
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
name|UPAPCS_CLOSED
value|1
end_define

begin_comment
comment|/* Connection down */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_AUTHSENT
value|2
end_define

begin_comment
comment|/* We've sent an Authenticate */
end_comment

begin_define
define|#
directive|define
name|UPAPCS_OPEN
value|3
end_define

begin_comment
comment|/* We've received an Ack */
end_comment

begin_comment
comment|/*  * Server states.  */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_CLOSED
value|1
end_define

begin_comment
comment|/* Connection down */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_LISTEN
value|2
end_define

begin_comment
comment|/* Listening for an Authenticate */
end_comment

begin_define
define|#
directive|define
name|UPAPSS_OPEN
value|3
end_define

begin_comment
comment|/* We've sent an Ack */
end_comment

begin_comment
comment|/*  * Flags.  */
end_comment

begin_define
define|#
directive|define
name|UPAPF_LOWERUP
value|1
end_define

begin_comment
comment|/* The lower level is UP */
end_comment

begin_define
define|#
directive|define
name|UPAPF_AWPPENDING
value|2
end_define

begin_comment
comment|/* Auth with peer pending */
end_comment

begin_define
define|#
directive|define
name|UPAPF_APPENDING
value|4
end_define

begin_comment
comment|/* Auth peer pending */
end_comment

begin_define
define|#
directive|define
name|UPAPF_UPVALID
value|8
end_define

begin_comment
comment|/* User/passwd values valid */
end_comment

begin_define
define|#
directive|define
name|UPAPF_UPPENDING
value|0x10
end_define

begin_comment
comment|/* User/passwd values pending */
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
comment|/* Timeout time in seconds */
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
name|upap_init
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_authwithpeer
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_authpeer
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_lowerup
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_lowerdown
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_input
name|__ARGS
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upap_protrej
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

