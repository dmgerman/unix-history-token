begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)pwd.h	4.2 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|passwd
block|{
name|char
modifier|*
name|pw_name
decl_stmt|;
name|char
modifier|*
name|pw_passwd
decl_stmt|;
name|int
name|pw_uid
decl_stmt|;
name|int
name|pw_gid
decl_stmt|;
name|int
name|pw_quota
decl_stmt|;
comment|/* not used */
name|char
modifier|*
name|pw_comment
decl_stmt|;
comment|/* not used */
name|char
modifier|*
name|pw_gecos
decl_stmt|;
name|char
modifier|*
name|pw_dir
decl_stmt|;
name|char
modifier|*
name|pw_shell
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|()
function_decl|;
end_function_decl

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

end_unit

