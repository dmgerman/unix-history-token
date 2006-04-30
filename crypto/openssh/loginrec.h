begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_HAVE_LOGINREC_H_
end_ifndef

begin_define
define|#
directive|define
name|_HAVE_LOGINREC_H_
end_define

begin_comment
comment|/*  * Copyright (c) 2000 Andre Lucas.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  ** loginrec.h:  platform-independent login recording and lastlog retrieval  **/
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

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
file|<sys/socket.h>
end_include

begin_comment
comment|/* RCSID("$Id: loginrec.h,v 1.10 2005/06/19 00:19:44 djm Exp $"); */
end_comment

begin_comment
comment|/**  ** you should use the login_* calls to work around platform dependencies  **/
end_comment

begin_comment
comment|/*  * login_netinfo structure  */
end_comment

begin_union
union|union
name|login_netinfo
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|sa_in
decl_stmt|;
name|struct
name|sockaddr_storage
name|sa_storage
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  *   * logininfo structure  *  */
end_comment

begin_comment
comment|/* types - different to utmp.h 'type' macros */
end_comment

begin_comment
comment|/* (though set to the same value as linux, openbsd and others...) */
end_comment

begin_define
define|#
directive|define
name|LTYPE_LOGIN
value|7
end_define

begin_define
define|#
directive|define
name|LTYPE_LOGOUT
value|8
end_define

begin_comment
comment|/* string lengths - set very long */
end_comment

begin_define
define|#
directive|define
name|LINFO_PROGSIZE
value|64
end_define

begin_define
define|#
directive|define
name|LINFO_LINESIZE
value|64
end_define

begin_define
define|#
directive|define
name|LINFO_NAMESIZE
value|128
end_define

begin_define
define|#
directive|define
name|LINFO_HOSTSIZE
value|256
end_define

begin_struct
struct|struct
name|logininfo
block|{
name|char
name|progname
index|[
name|LINFO_PROGSIZE
index|]
decl_stmt|;
comment|/* name of program (for PAM) */
name|int
name|progname_null
decl_stmt|;
name|short
name|int
name|type
decl_stmt|;
comment|/* type of login (LTYPE_*) */
name|int
name|pid
decl_stmt|;
comment|/* PID of login process */
name|int
name|uid
decl_stmt|;
comment|/* UID of this user */
name|char
name|line
index|[
name|LINFO_LINESIZE
index|]
decl_stmt|;
comment|/* tty/pty name */
name|char
name|username
index|[
name|LINFO_NAMESIZE
index|]
decl_stmt|;
comment|/* login username */
name|char
name|hostname
index|[
name|LINFO_HOSTSIZE
index|]
decl_stmt|;
comment|/* remote hostname */
comment|/* 'exit_status' structure components */
name|int
name|exit
decl_stmt|;
comment|/* process exit status */
name|int
name|termination
decl_stmt|;
comment|/* process termination status */
comment|/* struct timeval (sys/time.h) isn't always available, if it isn't we'll 	 * use time_t's value as tv_sec and set tv_usec to 0 	 */
name|unsigned
name|int
name|tv_sec
decl_stmt|;
name|unsigned
name|int
name|tv_usec
decl_stmt|;
name|union
name|login_netinfo
name|hostaddr
decl_stmt|;
comment|/* caller's host address(es) */
block|}
struct|;
end_struct

begin_comment
comment|/* struct logininfo */
end_comment

begin_comment
comment|/*  * login recording functions  */
end_comment

begin_comment
comment|/** 'public' functions */
end_comment

begin_comment
comment|/* construct a new login entry */
end_comment

begin_function_decl
name|struct
name|logininfo
modifier|*
name|login_alloc_entry
parameter_list|(
name|int
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|username
parameter_list|,
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
specifier|const
name|char
modifier|*
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free a structure */
end_comment

begin_function_decl
name|void
name|login_free_entry
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fill out a pre-allocated structure with useful information */
end_comment

begin_function_decl
name|int
name|login_init_entry
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|,
name|int
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|username
parameter_list|,
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
specifier|const
name|char
modifier|*
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* place the current time in a logininfo struct */
end_comment

begin_function_decl
name|void
name|login_set_current_time
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* record the entry */
end_comment

begin_function_decl
name|int
name|login_login
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_logout
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|LOGIN_NEEDS_UTMPX
end_ifdef

begin_function_decl
name|int
name|login_utmp_only
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** End of public functions */
end_comment

begin_comment
comment|/* record the entry */
end_comment

begin_function_decl
name|int
name|login_write
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_log_entry
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set the network address based on network address type */
end_comment

begin_function_decl
name|void
name|login_set_addr
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
specifier|const
name|unsigned
name|int
name|sa_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * lastlog retrieval functions  */
end_comment

begin_comment
comment|/* lastlog *entry* functions fill out a logininfo */
end_comment

begin_function_decl
name|struct
name|logininfo
modifier|*
name|login_get_lastlog
parameter_list|(
name|struct
name|logininfo
modifier|*
name|li
parameter_list|,
specifier|const
name|int
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lastlog *time* functions return time_t equivalent (uint) */
end_comment

begin_function_decl
name|unsigned
name|int
name|login_get_lastlog_time
parameter_list|(
specifier|const
name|int
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* produce various forms of the line filename */
end_comment

begin_function_decl
name|char
modifier|*
name|line_fullname
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|u_int
name|dstsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|line_stripname
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|dstsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|line_abbrevname
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|dstsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|record_failed_login
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HAVE_LOGINREC_H_ */
end_comment

end_unit

