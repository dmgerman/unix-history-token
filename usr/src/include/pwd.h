begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)pwd.h	5.0 (Berkeley) %G%  */
end_comment

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
name|u_long
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
name|u_long
name|pw_expire
decl_stmt|;
comment|/* account expiration */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwent
argument_list|()
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|,
modifier|*
name|getpwnam
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|endpwent
argument_list|()
decl_stmt|,
name|setpwfile
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setpassent
argument_list|()
decl_stmt|,
name|setpwent
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

