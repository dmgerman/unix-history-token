begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: authfd.h,v 1.23 2002/03/04 17:27:39 stevesk Exp $	*/
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

begin_include
include|#
directive|include
file|"buffer.h"
end_include

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fd
decl_stmt|;
name|Buffer
name|identities
decl_stmt|;
name|int
name|howmany
decl_stmt|;
block|}
name|AuthenticationConnection
typedef|;
end_typedef

begin_function_decl
name|int
name|ssh_get_authentication_socket
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_close_authentication_socket
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AuthenticationConnection
modifier|*
name|ssh_get_authentication_connection
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_close_authentication_connection
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_get_num_identities
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|ssh_get_first_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|ssh_get_next_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_add_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_remove_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_remove_all_identities
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_update_card
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_decrypt_challenge
parameter_list|(
name|AuthenticationConnection
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|u_char
index|[
literal|16
index|]
parameter_list|,
name|u_int
parameter_list|,
name|u_char
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
name|AuthenticationConnection
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTHFD_H */
end_comment

end_unit

