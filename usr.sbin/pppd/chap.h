begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * chap.h - Challenge Handshake Authentication Protocol definitions.  *  * Copyright (c) 1993 The Australian National University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Australian National University.  The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Copyright (c) 1991 Gregory M. Christy  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the author.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CHAP_INCLUDE__
end_ifndef

begin_comment
comment|/* Code + ID + length */
end_comment

begin_define
define|#
directive|define
name|CHAP_HEADERLEN
value|4
end_define

begin_comment
comment|/*  * CHAP codes.  */
end_comment

begin_define
define|#
directive|define
name|CHAP_DIGEST_MD5
value|5
end_define

begin_comment
comment|/* use MD5 algorithm */
end_comment

begin_define
define|#
directive|define
name|MD5_SIGNATURE_SIZE
value|16
end_define

begin_comment
comment|/* 16 bytes in a MD5 message digest */
end_comment

begin_define
define|#
directive|define
name|CHAP_MICROSOFT
value|0x80
end_define

begin_comment
comment|/* use Microsoft-compatible alg. */
end_comment

begin_define
define|#
directive|define
name|MS_CHAP_RESPONSE_LEN
value|49
end_define

begin_comment
comment|/* Response length for MS-CHAP */
end_comment

begin_define
define|#
directive|define
name|CHAP_CHALLENGE
value|1
end_define

begin_define
define|#
directive|define
name|CHAP_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|CHAP_SUCCESS
value|3
end_define

begin_define
define|#
directive|define
name|CHAP_FAILURE
value|4
end_define

begin_comment
comment|/*  *  Challenge lengths (for challenges we send) and other limits.  */
end_comment

begin_define
define|#
directive|define
name|MIN_CHALLENGE_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|MAX_CHALLENGE_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|MAX_RESPONSE_LENGTH
value|64
end_define

begin_comment
comment|/* sufficient for MD5 or MS-CHAP */
end_comment

begin_comment
comment|/*  * Each interface is described by a chap structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|chap_state
block|{
name|int
name|unit
decl_stmt|;
comment|/* Interface unit number */
name|int
name|clientstate
decl_stmt|;
comment|/* Client state */
name|int
name|serverstate
decl_stmt|;
comment|/* Server state */
name|u_char
name|challenge
index|[
name|MAX_CHALLENGE_LENGTH
index|]
decl_stmt|;
comment|/* last challenge string sent */
name|u_char
name|chal_len
decl_stmt|;
comment|/* challenge length */
name|u_char
name|chal_id
decl_stmt|;
comment|/* ID of last challenge */
name|u_char
name|chal_type
decl_stmt|;
comment|/* hash algorithm for challenges */
name|u_char
name|id
decl_stmt|;
comment|/* Current id */
name|char
modifier|*
name|chal_name
decl_stmt|;
comment|/* Our name to use with challenge */
name|int
name|chal_interval
decl_stmt|;
comment|/* Time until we challenge peer again */
name|int
name|timeouttime
decl_stmt|;
comment|/* Timeout time in seconds */
name|int
name|max_transmits
decl_stmt|;
comment|/* Maximum # of challenge transmissions */
name|int
name|chal_transmits
decl_stmt|;
comment|/* Number of transmissions of challenge */
name|int
name|resp_transmits
decl_stmt|;
comment|/* Number of transmissions of response */
name|u_char
name|response
index|[
name|MAX_RESPONSE_LENGTH
index|]
decl_stmt|;
comment|/* Response to send */
name|u_char
name|resp_length
decl_stmt|;
comment|/* length of response */
name|u_char
name|resp_id
decl_stmt|;
comment|/* ID for response messages */
name|u_char
name|resp_type
decl_stmt|;
comment|/* hash algorithm for responses */
name|char
modifier|*
name|resp_name
decl_stmt|;
comment|/* Our name to send with response */
block|}
name|chap_state
typedef|;
end_typedef

begin_comment
comment|/*  * Client (peer) states.  */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_INITIAL
value|0
end_define

begin_comment
comment|/* Lower layer down, not opened */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_CLOSED
value|1
end_define

begin_comment
comment|/* Lower layer up, not opened */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_PENDING
value|2
end_define

begin_comment
comment|/* Auth us to peer when lower up */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_LISTEN
value|3
end_define

begin_comment
comment|/* Listening for a challenge */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_RESPONSE
value|4
end_define

begin_comment
comment|/* Sent response, waiting for status */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_OPEN
value|5
end_define

begin_comment
comment|/* We've received Success */
end_comment

begin_comment
comment|/*  * Server (authenticator) states.  */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_INITIAL
value|0
end_define

begin_comment
comment|/* Lower layer down, not opened */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_CLOSED
value|1
end_define

begin_comment
comment|/* Lower layer up, not opened */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_PENDING
value|2
end_define

begin_comment
comment|/* Auth peer when lower up */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_INITIAL_CHAL
value|3
end_define

begin_comment
comment|/* We've sent the first challenge */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_OPEN
value|4
end_define

begin_comment
comment|/* We've sent a Success msg */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_RECHALLENGE
value|5
end_define

begin_comment
comment|/* We've sent another challenge */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_BADAUTH
value|6
end_define

begin_comment
comment|/* We've sent a Failure msg */
end_comment

begin_comment
comment|/*  * Timeouts.  */
end_comment

begin_define
define|#
directive|define
name|CHAP_DEFTIMEOUT
value|3
end_define

begin_comment
comment|/* Timeout time in seconds */
end_comment

begin_define
define|#
directive|define
name|CHAP_DEFTRANSMITS
value|10
end_define

begin_comment
comment|/* max # times to send challenge */
end_comment

begin_decl_stmt
specifier|extern
name|chap_state
name|chap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ChapAuthWithPeer
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ChapAuthPeer
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protent
name|chap_protent
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__CHAP_INCLUDE__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CHAP_INCLUDE__ */
end_comment

end_unit

