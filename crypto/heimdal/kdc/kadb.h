begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: kadb.h,v 1.3 2000/03/03 12:36:26 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__kadb_h__
end_ifndef

begin_define
define|#
directive|define
name|__kadb_h__
end_define

begin_define
define|#
directive|define
name|HASHSIZE
value|8191
end_define

begin_struct
struct|struct
name|ka_header
block|{
name|int32_t
name|version1
decl_stmt|;
comment|/* file format version, should 					   match version2 */
name|int32_t
name|size
decl_stmt|;
name|int32_t
name|free_ptr
decl_stmt|;
name|int32_t
name|eof_ptr
decl_stmt|;
name|int32_t
name|kvno_ptr
decl_stmt|;
name|int32_t
name|stats
index|[
literal|8
index|]
decl_stmt|;
name|int32_t
name|admin_accounts
decl_stmt|;
name|int32_t
name|special_keys_version
decl_stmt|;
name|int32_t
name|hashsize
decl_stmt|;
comment|/* allocated size of hash */
name|int32_t
name|hash
index|[
name|HASHSIZE
index|]
decl_stmt|;
name|int32_t
name|version2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ka_entry
block|{
name|int32_t
name|flags
decl_stmt|;
comment|/* see below */
name|int32_t
name|next
decl_stmt|;
comment|/* next in hash list */
name|int32_t
name|valid_end
decl_stmt|;
comment|/* expiration date */
name|int32_t
name|mod_time
decl_stmt|;
comment|/* time last modified */
name|int32_t
name|mod_ptr
decl_stmt|;
comment|/* pointer to modifier */
name|int32_t
name|pw_change
decl_stmt|;
comment|/* last pw change */
name|int32_t
name|max_life
decl_stmt|;
comment|/* max ticket life */
name|int32_t
name|kvno
decl_stmt|;
name|int32_t
name|foo2
index|[
literal|2
index|]
decl_stmt|;
comment|/* huh? */
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
name|char
name|instance
index|[
literal|64
index|]
decl_stmt|;
name|char
name|key
index|[
literal|8
index|]
decl_stmt|;
name|u_char
name|pw_expire
decl_stmt|;
comment|/* # days before password expires  */
name|u_char
name|spare
decl_stmt|;
name|u_char
name|attempts
decl_stmt|;
name|u_char
name|locktime
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KAFNORMAL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|KAFADMIN
value|(1<<2)
end_define

begin_comment
comment|/* an administrator */
end_comment

begin_define
define|#
directive|define
name|KAFNOTGS
value|(1<<3)
end_define

begin_comment
comment|/* ! allow principal to get or use TGT */
end_comment

begin_define
define|#
directive|define
name|KAFNOSEAL
value|(1<<5)
end_define

begin_comment
comment|/* ! allow principal as server in GetTicket */
end_comment

begin_define
define|#
directive|define
name|KAFNOCPW
value|(1<<6)
end_define

begin_comment
comment|/* ! allow principal to change its own key */
end_comment

begin_define
define|#
directive|define
name|KAFSPECIAL
value|(1<<8)
end_define

begin_comment
comment|/* set if special AuthServer principal */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_DATABASE
value|"/usr/afs/db/kaserver.DB0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __kadb_h__ */
end_comment

end_unit

