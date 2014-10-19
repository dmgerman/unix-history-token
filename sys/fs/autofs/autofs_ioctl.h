begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Edward Tomasz Napierala under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOFS_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|AUTOFS_IOCTL_H
end_define

begin_define
define|#
directive|define
name|AUTOFS_PATH
value|"/dev/autofs"
end_define

begin_struct
struct|struct
name|autofs_daemon_request
block|{
comment|/* 	 * Request identifier. 	 */
name|int
name|adr_id
decl_stmt|;
comment|/* 	 * The "from" field, containing map name.  For example, 	 * when accessing '/net/192.168.1.3/tank/vm/', that would 	 * be '-hosts'. 	 */
name|char
name|adr_from
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* 	 * Full path to the node being looked up; for requests that result 	 * in actual mount it is the full mount path. 	 */
name|char
name|adr_path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* 	 * Prefix, which is basically the mountpoint from auto_master(5). 	 * In example above that would be "/net"; for direct maps it is "/". 	 */
name|char
name|adr_prefix
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* 	 * Map key, also used as command argument for dynamic maps; in example 	 * above that would be '192.168.1.3'. 	 */
name|char
name|adr_key
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* 	 * Mount options from auto_master(5). 	 */
name|char
name|adr_options
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|autofs_daemon_done
block|{
comment|/* 	 * Identifier, copied from adr_id. 	 */
name|int
name|add_id
decl_stmt|;
comment|/* 	 * Set to 1 if the map may contain wildcard entries; 	 * otherwise autofs will do negative caching. 	 */
name|int
name|add_wildcards
decl_stmt|;
comment|/* 	 * Error number, possibly returned to userland. 	 */
name|int
name|add_error
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AUTOFSREQUEST
value|_IOR('I', 0x01, struct autofs_daemon_request)
end_define

begin_define
define|#
directive|define
name|AUTOFSDONE
value|_IOW('I', 0x02, struct autofs_daemon_done)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !AUTOFS_IOCTL_H */
end_comment

end_unit

