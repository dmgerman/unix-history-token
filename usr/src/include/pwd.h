begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pwd.h	5.4 (Berkeley) %G%  */
end_comment

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
name|_PATH_MKPASSWD
value|"/usr/sbin/mkpasswd"
end_define

begin_define
define|#
directive|define
name|_PATH_PTMP
value|"/etc/ptmp"
end_define

begin_define
define|#
directive|define
name|_PW_KEYBYNAME
value|'0'
end_define

begin_define
define|#
directive|define
name|_PW_KEYBYUID
value|'1'
end_define

begin_define
define|#
directive|define
name|_PASSWORD_LEN
value|128
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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

begin_function_decl
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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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
name|int
name|setpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setpwfile
parameter_list|(
specifier|const
name|char
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

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpwent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endpwent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setpwfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpassent
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

