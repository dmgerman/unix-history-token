begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: authfd.h,v 1.39 2015/12/04 16:41:28 markus Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Functions to interface with the SSH_AUTHENTICATION_FD socket.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTHFD_H
end_ifndef

begin_define
define|#
directive|define
name|AUTHFD_H
end_define

begin_comment
comment|/* List of identities returned by ssh_fetch_identitylist() */
end_comment

begin_struct
struct|struct
name|ssh_identitylist
block|{
name|size_t
name|nkeys
decl_stmt|;
name|struct
name|sshkey
modifier|*
modifier|*
name|keys
decl_stmt|;
name|char
modifier|*
modifier|*
name|comments
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ssh_get_authentication_socket
parameter_list|(
name|int
modifier|*
name|fdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_close_authentication_socket
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_lock_agent
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
name|lock
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_fetch_identitylist
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
name|version
parameter_list|,
name|struct
name|ssh_identitylist
modifier|*
modifier|*
name|idlp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_free_identitylist
parameter_list|(
name|struct
name|ssh_identitylist
modifier|*
name|idl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_add_identity_constrained
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|sshkey
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|,
name|u_int
name|life
parameter_list|,
name|u_int
name|confirm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_remove_identity
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|sshkey
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_update_card
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
name|add
parameter_list|,
specifier|const
name|char
modifier|*
name|reader_id
parameter_list|,
specifier|const
name|char
modifier|*
name|pin
parameter_list|,
name|u_int
name|life
parameter_list|,
name|u_int
name|confirm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_remove_all_identities
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_decrypt_challenge
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|sshkey
modifier|*
name|key
parameter_list|,
name|BIGNUM
modifier|*
name|challenge
parameter_list|,
name|u_char
name|session_id
index|[
literal|16
index|]
parameter_list|,
name|u_char
name|response
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_agent_sign
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|sshkey
modifier|*
name|key
parameter_list|,
name|u_char
modifier|*
modifier|*
name|sigp
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|,
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|,
specifier|const
name|char
modifier|*
name|alg
parameter_list|,
name|u_int
name|compat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Messages for the authentication agent connection. */
end_comment

begin_define
define|#
directive|define
name|SSH_AGENTC_REQUEST_RSA_IDENTITIES
value|1
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_RSA_IDENTITIES_ANSWER
value|2
end_define

begin_define
define|#
directive|define
name|SSH_AGENTC_RSA_CHALLENGE
value|3
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_RSA_RESPONSE
value|4
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_FAILURE
value|5
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_SUCCESS
value|6
end_define

begin_define
define|#
directive|define
name|SSH_AGENTC_ADD_RSA_IDENTITY
value|7
end_define

begin_define
define|#
directive|define
name|SSH_AGENTC_REMOVE_RSA_IDENTITY
value|8
end_define

begin_define
define|#
directive|define
name|SSH_AGENTC_REMOVE_ALL_RSA_IDENTITIES
value|9
end_define

begin_comment
comment|/* private OpenSSH extensions for SSH2 */
end_comment

begin_define
define|#
directive|define
name|SSH2_AGENTC_REQUEST_IDENTITIES
value|11
end_define

begin_define
define|#
directive|define
name|SSH2_AGENT_IDENTITIES_ANSWER
value|12
end_define

begin_define
define|#
directive|define
name|SSH2_AGENTC_SIGN_REQUEST
value|13
end_define

begin_define
define|#
directive|define
name|SSH2_AGENT_SIGN_RESPONSE
value|14
end_define

begin_define
define|#
directive|define
name|SSH2_AGENTC_ADD_IDENTITY
value|17
end_define

begin_define
define|#
directive|define
name|SSH2_AGENTC_REMOVE_IDENTITY
value|18
end_define

begin_define
define|#
directive|define
name|SSH2_AGENTC_REMOVE_ALL_IDENTITIES
value|19
end_define

begin_comment
comment|/* smartcard */
end_comment

begin_define
define|#
directive|define
name|SSH_AGENTC_ADD_SMARTCARD_KEY
value|20
end_define

begin_define
define|#
directive|define
name|SSH_AGENTC_REMOVE_SMARTCARD_KEY
value|21
end_define

begin_comment
comment|/* lock/unlock the agent */
end_comment

begin_define
define|#
directive|define
name|SSH_AGENTC_LOCK
value|22
end_define

begin_define
define|#
directive|define
name|SSH_AGENTC_UNLOCK
value|23
end_define

begin_comment
comment|/* add key with constraints */
end_comment

begin_define
define|#
directive|define
name|SSH_AGENTC_ADD_RSA_ID_CONSTRAINED
value|24
end_define

begin_define
define|#
directive|define
name|SSH2_AGENTC_ADD_ID_CONSTRAINED
value|25
end_define

begin_define
define|#
directive|define
name|SSH_AGENTC_ADD_SMARTCARD_KEY_CONSTRAINED
value|26
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_CONSTRAIN_LIFETIME
value|1
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_CONSTRAIN_CONFIRM
value|2
end_define

begin_comment
comment|/* extended failure messages */
end_comment

begin_define
define|#
directive|define
name|SSH2_AGENT_FAILURE
value|30
end_define

begin_comment
comment|/* additional error code for ssh.com's ssh-agent2 */
end_comment

begin_define
define|#
directive|define
name|SSH_COM_AGENT2_FAILURE
value|102
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_OLD_SIGNATURE
value|0x01
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_RSA_SHA2_256
value|0x02
end_define

begin_define
define|#
directive|define
name|SSH_AGENT_RSA_SHA2_512
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTHFD_H */
end_comment

end_unit

