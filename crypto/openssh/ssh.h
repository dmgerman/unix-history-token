begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: ssh.h,v 1.64 2002/03/04 17:27:39 stevesk Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_H
end_ifndef

begin_define
define|#
directive|define
name|SSH_H
end_define

begin_comment
comment|/* Cipher used for encrypting authentication files. */
end_comment

begin_define
define|#
directive|define
name|SSH_AUTHFILE_CIPHER
value|SSH_CIPHER_3DES
end_define

begin_comment
comment|/* Default port number. */
end_comment

begin_define
define|#
directive|define
name|SSH_DEFAULT_PORT
value|22
end_define

begin_comment
comment|/* Maximum number of TCP/IP ports forwarded per direction. */
end_comment

begin_define
define|#
directive|define
name|SSH_MAX_FORWARDS_PER_DIRECTION
value|100
end_define

begin_comment
comment|/*  * Maximum number of RSA authentication identity files that can be specified  * in configuration files or on the command line.  */
end_comment

begin_define
define|#
directive|define
name|SSH_MAX_IDENTITY_FILES
value|100
end_define

begin_comment
comment|/*  * Major protocol version.  Different version indicates major incompatiblity  * that prevents communication.  *  * Minor protocol version.  Different version indicates minor incompatibility  * that does not prevent interoperation.  */
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_MAJOR_1
value|1
end_define

begin_define
define|#
directive|define
name|PROTOCOL_MINOR_1
value|5
end_define

begin_comment
comment|/* We support both SSH1 and SSH2 */
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_MAJOR_2
value|2
end_define

begin_define
define|#
directive|define
name|PROTOCOL_MINOR_2
value|0
end_define

begin_comment
comment|/*  * Name for the service.  The port named by this service overrides the  * default port if present.  */
end_comment

begin_define
define|#
directive|define
name|SSH_SERVICE_NAME
value|"ssh"
end_define

begin_comment
comment|/*  * Name of the environment variable containing the pathname of the  * authentication socket.  */
end_comment

begin_define
define|#
directive|define
name|SSH_AGENTPID_ENV_NAME
value|"SSH_AGENT_PID"
end_define

begin_comment
comment|/*  * Name of the environment variable containing the pathname of the  * authentication socket.  */
end_comment

begin_define
define|#
directive|define
name|SSH_AUTHSOCKET_ENV_NAME
value|"SSH_AUTH_SOCK"
end_define

begin_comment
comment|/*  * Environment variable for overwriting the default location of askpass  */
end_comment

begin_define
define|#
directive|define
name|SSH_ASKPASS_ENV
value|"SSH_ASKPASS"
end_define

begin_comment
comment|/*  * Force host key length and server key length to differ by at least this  * many bits.  This is to make double encryption with rsaref work.  */
end_comment

begin_define
define|#
directive|define
name|SSH_KEY_BITS_RESERVED
value|128
end_define

begin_comment
comment|/*  * Length of the session key in bytes.  (Specified as 256 bits in the  * protocol.)  */
end_comment

begin_define
define|#
directive|define
name|SSH_SESSION_KEY_LENGTH
value|32
end_define

begin_comment
comment|/* Name of Kerberos service for SSH to use. */
end_comment

begin_define
define|#
directive|define
name|KRB4_SERVICE_NAME
value|"rcmd"
end_define

begin_comment
comment|/* Used to identify ``EscapeChar none'' */
end_comment

begin_define
define|#
directive|define
name|SSH_ESCAPECHAR_NONE
value|-2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PAM
end_ifdef

begin_include
include|#
directive|include
file|"auth-pam.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_PAM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SSH_H */
end_comment

end_unit

