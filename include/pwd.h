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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_GID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__gid_t
name|gid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_GID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__time_t
name|time_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_TIME_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uid_t
name|uid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Historically, the keys in _PATH_MP_DB/_PATH_SMP_DB had the format  * `1 octet tag | key', where the tag is one of the _PW_KEY* values  * listed below.  These values happen to be ASCII digits.  Starting  * with FreeBSD 5.1, the tag is now still a single octet, but the  * upper 4 bits are interpreted as a version.  Pre-FreeBSD 5.1 format  * entries are version `3' -- this conveniently results in the same  * key values as before.  The new, architecture-independent entries  * are version `4'.  * As it happens, some applications read the database directly.  * (Bad app, no cookie!)  Thus, we leave the _PW_KEY* symbols at their  * old pre-FreeBSD 5.1 values so these apps still work.  Consequently  * we have to muck around a bit more to get the correct, versioned  * tag, and that is what the _PW_VERSIONED macro is about.  */
end_comment

begin_define
define|#
directive|define
name|_PW_VERSION_MASK
value|'\xF0'
end_define

begin_define
define|#
directive|define
name|_PW_VERSIONED
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|((unsigned char)(((x)& 0xCF) | ((v)<<4)))
end_define

begin_define
define|#
directive|define
name|_PW_KEYBYNAME
value|'\x31'
end_define

begin_comment
comment|/* stored by name */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYBYNUM
value|'\x32'
end_define

begin_comment
comment|/* stored by entry in the "file" */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYBYUID
value|'\x33'
end_define

begin_comment
comment|/* stored by uid */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYYPENABLED
value|'\x34'
end_define

begin_comment
comment|/* YP is enabled */
end_comment

begin_define
define|#
directive|define
name|_PW_KEYYPBYNUM
value|'\x35'
end_define

begin_comment
comment|/* special +@netgroup entries */
end_comment

begin_comment
comment|/* The database also contains a key to indicate the format version of  * the entries therein.  There may be other, older versioned entries  * as well.  */
end_comment

begin_define
define|#
directive|define
name|_PWD_VERSION_KEY
value|"\xFF" "VERSION"
end_define

begin_define
define|#
directive|define
name|_PWD_CURRENT_VERSION
value|'\x04'
end_define

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

begin_comment
comment|/* XXX These flags are bogus.  With nsswitch, there are many  * possible sources and they cannot be represented in a small integer.  */
end_comment

begin_define
define|#
directive|define
name|_PWF_SOURCE
value|0x3000
end_define

begin_define
define|#
directive|define
name|_PWF_FILES
value|0x1000
end_define

begin_define
define|#
directive|define
name|_PWF_NIS
value|0x2000
end_define

begin_define
define|#
directive|define
name|_PWF_HESIOD
value|0x3000
end_define

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
operator|>=
literal|500
end_if

begin_function_decl
name|void
name|endpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpwnam_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|passwd
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|passwd
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpwuid_r
parameter_list|(
name|uid_t
parameter_list|,
name|struct
name|passwd
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|passwd
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|getpwent_r
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|passwd
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpassent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|user_from_uid
parameter_list|(
name|uid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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

