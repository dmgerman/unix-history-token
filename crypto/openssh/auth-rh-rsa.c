begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Rhosts or /etc/hosts.equiv authentication combined with RSA host  * authentication.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$OpenBSD: auth-rh-rsa.c,v 1.29 2002/03/04 12:43:06 markus Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"packet.h"
end_include

begin_include
include|#
directive|include
file|"uidswap.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"servconf.h"
end_include

begin_include
include|#
directive|include
file|"key.h"
end_include

begin_include
include|#
directive|include
file|"hostfile.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_include
include|#
directive|include
file|"auth.h"
end_include

begin_include
include|#
directive|include
file|"canohost.h"
end_include

begin_comment
comment|/*  * Tries to authenticate the user using the .rhosts file and the host using  * its host key.  Returns true if authentication succeeds.  */
end_comment

begin_function
name|int
name|auth_rhosts_rsa
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|client_user
parameter_list|,
name|Key
modifier|*
name|client_host_key
parameter_list|)
block|{
specifier|extern
name|ServerOptions
name|options
decl_stmt|;
specifier|const
name|char
modifier|*
name|canonical_hostname
decl_stmt|;
name|HostStatus
name|host_status
decl_stmt|;
name|debug
argument_list|(
literal|"Trying rhosts with RSA host authentication for client user %.100s"
argument_list|,
name|client_user
argument_list|)
expr_stmt|;
if|if
condition|(
name|pw
operator|==
name|NULL
operator|||
name|client_host_key
operator|==
name|NULL
operator|||
name|client_host_key
operator|->
name|rsa
operator|==
name|NULL
condition|)
return|return
literal|0
return|;
comment|/* Check if we would accept it using rhosts authentication. */
if|if
condition|(
operator|!
name|auth_rhosts
argument_list|(
name|pw
argument_list|,
name|client_user
argument_list|)
condition|)
return|return
literal|0
return|;
name|canonical_hostname
operator|=
name|get_canonical_hostname
argument_list|(
name|options
operator|.
name|verify_reverse_mapping
argument_list|)
expr_stmt|;
name|debug
argument_list|(
literal|"Rhosts RSA authentication: canonical host %.900s"
argument_list|,
name|canonical_hostname
argument_list|)
expr_stmt|;
name|host_status
operator|=
name|check_key_in_hostfiles
argument_list|(
name|pw
argument_list|,
name|client_host_key
argument_list|,
name|canonical_hostname
argument_list|,
name|_PATH_SSH_SYSTEM_HOSTFILE
argument_list|,
name|options
operator|.
name|ignore_user_known_hosts
condition|?
name|NULL
else|:
name|_PATH_SSH_USER_HOSTFILE
argument_list|)
expr_stmt|;
if|if
condition|(
name|host_status
operator|!=
name|HOST_OK
condition|)
block|{
name|debug
argument_list|(
literal|"Rhosts with RSA host authentication denied: unknown or invalid host key"
argument_list|)
expr_stmt|;
name|packet_send_debug
argument_list|(
literal|"Your host key cannot be verified: unknown or invalid host key."
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* A matching host key was found and is known. */
comment|/* Perform the challenge-response dialog with the client for the host key. */
if|if
condition|(
operator|!
name|auth_rsa_challenge_dialog
argument_list|(
name|client_host_key
operator|->
name|rsa
argument_list|)
condition|)
block|{
name|log
argument_list|(
literal|"Client on %.800s failed to respond correctly to host authentication."
argument_list|,
name|canonical_hostname
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* 	 * We have authenticated the user using .rhosts or /etc/hosts.equiv, 	 * and the host using RSA. We accept the authentication. 	 */
name|verbose
argument_list|(
literal|"Rhosts with RSA host authentication accepted for %.100s, %.100s on %.700s."
argument_list|,
name|pw
operator|->
name|pw_name
argument_list|,
name|client_user
argument_list|,
name|canonical_hostname
argument_list|)
expr_stmt|;
name|packet_send_debug
argument_list|(
literal|"Rhosts with RSA host authentication accepted."
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

