begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)pwd.h	8.2 (Berkeley) %G%  */
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
name|_PATH_PASSWD
value|"/etc/passwd"
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
name|_PATH_MP_DB
value|"/etc/pwd.db"
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
name|int
name|pw_uid
decl_stmt|;
comment|/* user uid */
name|int
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
block|}
struct|;
end_struct

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
name|int
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

