begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   * authfd.h  *   * Author: Tatu Ylonen<ylo@cs.hut.fi>  *   * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *   * Created: Wed Mar 29 01:17:41 1995 ylo  *   * Functions to interface with the SSH_AUTHENTICATION_FD socket.  *   */
end_comment

begin_comment
comment|/* RCSID("$Id: authfd.h,v 1.6 1999/11/24 19:53:44 markus Exp $"); */
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fd
decl_stmt|;
name|Buffer
name|packet
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

begin_comment
comment|/* Returns the number of the authentication fd, or -1 if there is none. */
end_comment

begin_function_decl
name|int
name|ssh_get_authentication_socket
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * This should be called for any descriptor returned by  * ssh_get_authentication_socket().  Depending on the way the descriptor was  * obtained, this may close the descriptor.  */
end_comment

begin_function_decl
name|void
name|ssh_close_authentication_socket
parameter_list|(
name|int
name|authfd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Opens and connects a private socket for communication with the  * authentication agent.  Returns NULL if an error occurred and the  * connection could not be opened.  The connection should be closed by the  * caller by calling ssh_close_authentication_connection().  */
end_comment

begin_function_decl
name|AuthenticationConnection
modifier|*
name|ssh_get_authentication_connection
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Closes the connection to the authentication agent and frees any associated  * memory.  */
end_comment

begin_function_decl
name|void
name|ssh_close_authentication_connection
parameter_list|(
name|AuthenticationConnection
modifier|*
name|ac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the first authentication identity held by the agent. Returns true  * if an identity is available, 0 otherwise. The caller must initialize the  * integers before the call, and free the comment after a successful call  * (before calling ssh_get_next_identity).  */
end_comment

begin_function_decl
name|int
name|ssh_get_first_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
name|connection
parameter_list|,
name|BIGNUM
modifier|*
name|e
parameter_list|,
name|BIGNUM
modifier|*
name|n
parameter_list|,
name|char
modifier|*
modifier|*
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the next authentication identity for the agent.  Other functions  * can be called between this and ssh_get_first_identity or two calls of this  * function.  This returns 0 if there are no more identities.  The caller  * must free comment after a successful return.  */
end_comment

begin_function_decl
name|int
name|ssh_get_next_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
name|connection
parameter_list|,
name|BIGNUM
modifier|*
name|e
parameter_list|,
name|BIGNUM
modifier|*
name|n
parameter_list|,
name|char
modifier|*
modifier|*
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Requests the agent to decrypt the given challenge.  Returns true if    the agent claims it was able to decrypt it. */
end_comment

begin_function_decl
name|int
name|ssh_decrypt_challenge
parameter_list|(
name|AuthenticationConnection
modifier|*
name|auth
parameter_list|,
name|BIGNUM
modifier|*
name|e
parameter_list|,
name|BIGNUM
modifier|*
name|n
parameter_list|,
name|BIGNUM
modifier|*
name|challenge
parameter_list|,
name|unsigned
name|char
name|session_id
index|[
literal|16
index|]
parameter_list|,
name|unsigned
name|int
name|response_type
parameter_list|,
name|unsigned
name|char
name|response
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Adds an identity to the authentication server.  This call is not meant to  * be used by normal applications.  This returns true if the identity was  * successfully added.  */
end_comment

begin_function_decl
name|int
name|ssh_add_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
name|connection
parameter_list|,
name|RSA
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Removes the identity from the authentication server.  This call is not  * meant to be used by normal applications.  This returns true if the  * identity was successfully added.  */
end_comment

begin_function_decl
name|int
name|ssh_remove_identity
parameter_list|(
name|AuthenticationConnection
modifier|*
name|connection
parameter_list|,
name|RSA
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Removes all identities from the authentication agent.  This call is not  * meant to be used by normal applications.  This returns true if the  * operation was successful.  */
end_comment

begin_function_decl
name|int
name|ssh_remove_all_identities
parameter_list|(
name|AuthenticationConnection
modifier|*
name|connection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Closes the connection to the authentication agent. */
end_comment

begin_function_decl
name|void
name|ssh_close_authentication
parameter_list|(
name|AuthenticationConnection
modifier|*
name|connection
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

