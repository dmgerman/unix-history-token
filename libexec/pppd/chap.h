begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * chap.h - Cryptographic Handshake Authentication Protocol definitions.  *          based on November 1991 draft of PPP Authentication RFC  *  * Copyright (c) 1991 Gregory M. Christy  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the author.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
value|(sizeof (u_char) + sizeof (u_char) + sizeof (u_short))
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
name|CHAP_NOCALLBACK
value|0
end_define

begin_comment
comment|/* don't call back after successful auth */
end_comment

begin_define
define|#
directive|define
name|CHAP_CALLBACK
value|1
end_define

begin_comment
comment|/* do call back */
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
comment|/*  *  Challenge lengths  */
end_comment

begin_define
define|#
directive|define
name|MIN_CHALLENGE_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|MAX_CHALLENGE_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|MAX_SECRET_LEN
value|128
end_define

begin_comment
comment|/*  * Each interface is described by chap structure.  */
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
name|u_char
name|chal_str
index|[
name|MAX_CHALLENGE_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* challenge string */
name|u_char
name|chal_len
decl_stmt|;
comment|/* challenge length */
name|int
name|clientstate
decl_stmt|;
comment|/* Client state */
name|int
name|serverstate
decl_stmt|;
comment|/* Server state */
name|int
name|flags
decl_stmt|;
comment|/* Flags */
name|unsigned
name|char
name|id
decl_stmt|;
comment|/* Current id */
name|int
name|timeouttime
decl_stmt|;
comment|/* Timeout time in milliseconds */
name|int
name|retransmits
decl_stmt|;
comment|/* Number of retransmissions */
block|}
name|chap_state
typedef|;
end_typedef

begin_comment
comment|/*  * Client states.  */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_CLOSED
value|1
end_define

begin_comment
comment|/* Connection down */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_CHALLENGE_SENT
value|2
end_define

begin_comment
comment|/* We've sent a challenge */
end_comment

begin_define
define|#
directive|define
name|CHAPCS_OPEN
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
name|CHAPSS_CLOSED
value|1
end_define

begin_comment
comment|/* Connection down */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_LISTEN
value|2
end_define

begin_comment
comment|/* Listening for a challenge */
end_comment

begin_define
define|#
directive|define
name|CHAPSS_OPEN
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
name|CHAPF_LOWERUP
value|0x01
end_define

begin_comment
comment|/* The lower level is UP */
end_comment

begin_define
define|#
directive|define
name|CHAPF_AWPPENDING
value|0x02
end_define

begin_comment
comment|/* Auth with peer pending */
end_comment

begin_define
define|#
directive|define
name|CHAPF_APPENDING
value|0x04
end_define

begin_comment
comment|/* Auth peer pending */
end_comment

begin_define
define|#
directive|define
name|CHAPF_UPVALID
value|0x08
end_define

begin_comment
comment|/* values valid */
end_comment

begin_define
define|#
directive|define
name|CHAPF_UPPENDING
value|0x10
end_define

begin_comment
comment|/* values pending */
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

begin_decl_stmt
specifier|extern
name|chap_state
name|chap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ChapInit
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
name|ChapAuthWithPeer
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
name|ChapAuthPeer
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
name|ChapLowerUp
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
name|ChapLowerDown
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
name|ChapInput
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
name|ChapProtocolReject
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
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

