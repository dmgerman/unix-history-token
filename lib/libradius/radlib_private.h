begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RADLIB_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|RADLIB_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|"radlib.h"
end_include

begin_comment
comment|/* Handle types */
end_comment

begin_define
define|#
directive|define
name|RADIUS_AUTH
value|0
end_define

begin_comment
comment|/* RADIUS authentication, default */
end_comment

begin_define
define|#
directive|define
name|RADIUS_ACCT
value|1
end_define

begin_comment
comment|/* RADIUS accounting */
end_comment

begin_comment
comment|/* Defaults */
end_comment

begin_define
define|#
directive|define
name|MAXTRIES
value|3
end_define

begin_define
define|#
directive|define
name|PATH_RADIUS_CONF
value|"/etc/radius.conf"
end_define

begin_define
define|#
directive|define
name|RADIUS_PORT
value|1812
end_define

begin_define
define|#
directive|define
name|RADACCT_PORT
value|1813
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|3
end_define

begin_comment
comment|/* In seconds */
end_comment

begin_comment
comment|/* Limits */
end_comment

begin_define
define|#
directive|define
name|ERRSIZE
value|128
end_define

begin_comment
comment|/* Maximum error message length */
end_comment

begin_define
define|#
directive|define
name|MAXCONFLINE
value|1024
end_define

begin_comment
comment|/* Maximum config file line length */
end_comment

begin_define
define|#
directive|define
name|MAXSERVERS
value|10
end_define

begin_comment
comment|/* Maximum number of servers to try */
end_comment

begin_define
define|#
directive|define
name|MSGSIZE
value|4096
end_define

begin_comment
comment|/* Maximum RADIUS message */
end_comment

begin_define
define|#
directive|define
name|PASSSIZE
value|128
end_define

begin_comment
comment|/* Maximum significant password chars */
end_comment

begin_comment
comment|/* Positions of fields in RADIUS messages */
end_comment

begin_define
define|#
directive|define
name|POS_CODE
value|0
end_define

begin_comment
comment|/* Message code */
end_comment

begin_define
define|#
directive|define
name|POS_IDENT
value|1
end_define

begin_comment
comment|/* Identifier */
end_comment

begin_define
define|#
directive|define
name|POS_LENGTH
value|2
end_define

begin_comment
comment|/* Message length */
end_comment

begin_define
define|#
directive|define
name|POS_AUTH
value|4
end_define

begin_comment
comment|/* Authenticator */
end_comment

begin_define
define|#
directive|define
name|LEN_AUTH
value|16
end_define

begin_comment
comment|/* Length of authenticator */
end_comment

begin_define
define|#
directive|define
name|POS_ATTRS
value|20
end_define

begin_comment
comment|/* Start of attributes */
end_comment

begin_struct
struct|struct
name|rad_server
block|{
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
comment|/* Address of server */
name|char
modifier|*
name|secret
decl_stmt|;
comment|/* Shared secret */
name|int
name|timeout
decl_stmt|;
comment|/* Timeout in seconds */
name|int
name|max_tries
decl_stmt|;
comment|/* Number of tries before giving up */
name|int
name|num_tries
decl_stmt|;
comment|/* Number of tries so far */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rad_handle
block|{
name|int
name|fd
decl_stmt|;
comment|/* Socket file descriptor */
name|struct
name|rad_server
name|servers
index|[
name|MAXSERVERS
index|]
decl_stmt|;
comment|/* Servers to contact */
name|int
name|num_servers
decl_stmt|;
comment|/* Number of valid server entries */
name|int
name|ident
decl_stmt|;
comment|/* Current identifier value */
name|char
name|errmsg
index|[
name|ERRSIZE
index|]
decl_stmt|;
comment|/* Most recent error message */
name|unsigned
name|char
name|request
index|[
name|MSGSIZE
index|]
decl_stmt|;
comment|/* Request to send */
name|int
name|req_len
decl_stmt|;
comment|/* Length of request */
name|char
name|pass
index|[
name|PASSSIZE
index|]
decl_stmt|;
comment|/* Cleartext password */
name|int
name|pass_len
decl_stmt|;
comment|/* Length of cleartext password */
name|int
name|pass_pos
decl_stmt|;
comment|/* Position of scrambled password */
name|char
name|chap_pass
decl_stmt|;
comment|/* Have we got a CHAP_PASSWORD ? */
name|unsigned
name|char
name|response
index|[
name|MSGSIZE
index|]
decl_stmt|;
comment|/* Response received */
name|int
name|resp_len
decl_stmt|;
comment|/* Length of response */
name|int
name|resp_pos
decl_stmt|;
comment|/* Current position scanning attrs */
name|int
name|total_tries
decl_stmt|;
comment|/* How many requests we'll send */
name|int
name|try
decl_stmt|;
comment|/* How many requests we've sent */
name|int
name|srv
decl_stmt|;
comment|/* Server number we did last */
name|int
name|type
decl_stmt|;
comment|/* Handle type */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

