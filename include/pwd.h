begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pwd.h	8.2 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PWD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PWD_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PWD
value|"/etc"
end_define

begin_define
define|#
directive|define
name|_PATH_PASSWD
value|"/etc/passwd"
end_define

begin_define
define|#
directive|define
name|_PASSWD
value|"passwd"
end_define

begin_define
define|#
directive|define
name|_PATH_MASTERPASSWD
value|"/etc/master.passwd"
end_define

begin_define
define|#
directive|define
name|_MASTERPASSWD
value|"master.passwd"
end_define

begin_define
define|#
directive|define
name|_PATH_MP_DB
value|"/etc/pwd.db"
end_define

begin_define
define|#
directive|define
name|_MP_DB
value|"pwd.db"
end_define

begin_define
define|#
directive|define
name|_PATH_SMP_DB
value|"/etc/spwd.db"
end_define

begin_define
define|#
directive|define
name|_SMP_DB
value|"spwd.db"
end_define

begin_define
define|#
directive|define
name|_PATH_PWD_MKDB
value|"/usr/sbin/pwd_mkdb"
end_define

begin_define
define|#
directive|define
name|_PW_KEYBYNAME
value|'1'
end_define

begin_comment
comment|/* stored by name */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYBYNUM
value|'2'
end_define

begin_comment
comment|/* stored by entry in the "file" */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYBYUID
value|'3'
end_define

begin_comment
comment|/* stored by uid */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYYPENABLED
value|'4'
end_define

begin_comment
comment|/* YP is enabled */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYYPBYNUM
value|'5'
end_define

begin_comment
comment|/* special +@netgroup entries */
end_comment

begin_define
define|#
directive|define
name|_PASSWORD_EFMT1
value|'_'
end_define

begin_comment
comment|/* extended encryption format */
end_comment

begin_define
define|#
directive|define
name|_PASSWORD_LEN
value|128
end_define

begin_comment
comment|/* max length, not counting NULL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|passwd
block|{
name|char
modifier|*
name|pw_name
decl_stmt|;
comment|/* user name */
name|char
modifier|*
name|pw_passwd
decl_stmt|;
comment|/* encrypted password */
name|uid_t
name|pw_uid
decl_stmt|;
comment|/* user uid */
name|gid_t
name|pw_gid
decl_stmt|;
comment|/* user gid */
name|time_t
name|pw_change
decl_stmt|;
comment|/* password change time */
name|char
modifier|*
name|pw_class
decl_stmt|;
comment|/* user access class */
name|char
modifier|*
name|pw_gecos
decl_stmt|;
comment|/* Honeywell login info */
name|char
modifier|*
name|pw_dir
decl_stmt|;
comment|/* home directory */
name|char
modifier|*
name|pw_shell
decl_stmt|;
comment|/* default shell */
name|time_t
name|pw_expire
decl_stmt|;
comment|/* account expiration */
name|int
name|pw_fields
decl_stmt|;
comment|/* internal: fields filled in */
block|}
struct|;
end_struct

begin_comment
comment|/* Mapping from fields to bits for pw_fields. */
end_comment

begin_define
define|#
directive|define
name|_PWF
parameter_list|(
name|x
parameter_list|)
value|(1<< x)
end_define

begin_define
define|#
directive|define
name|_PWF_NAME
value|_PWF(0)
end_define

begin_define
define|#
directive|define
name|_PWF_PASSWD
value|_PWF(1)
end_define

begin_define
define|#
directive|define
name|_PWF_UID
value|_PWF(2)
end_define

begin_define
define|#
directive|define
name|_PWF_GID
value|_PWF(3)
end_define

begin_define
define|#
directive|define
name|_PWF_CHANGE
value|_PWF(4)
end_define

begin_define
define|#
directive|define
name|_PWF_CLASS
value|_PWF(5)
end_define

begin_define
define|#
directive|define
name|_PWF_GECOS
value|_PWF(6)
end_define

begin_define
define|#
directive|define
name|_PWF_DIR
value|_PWF(7)
end_define

begin_define
define|#
directive|define
name|_PWF_SHELL
value|_PWF(8)
end_define

begin_define
define|#
directive|define
name|_PWF_EXPIRE
value|_PWF(9)
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|passwd
modifier|*
name|getpwuid
name|__P
argument_list|(
operator|(
name|uid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwnam
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setpassent
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setpwent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|endpwent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|user_from_uid
name|__P
argument_list|(
operator|(
name|uid_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PWD_H_ */
end_comment

end_unit

