begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ttyent.h	5.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_PATH_TTYS
value|"/etc/ttys"
end_define

begin_define
define|#
directive|define
name|_TTYS_OFF
value|"off"
end_define

begin_define
define|#
directive|define
name|_TTYS_ON
value|"on"
end_define

begin_define
define|#
directive|define
name|_TTYS_SECURE
value|"secure"
end_define

begin_define
define|#
directive|define
name|_TTYS_WINDOW
value|"window"
end_define

begin_struct
struct|struct
name|ttyent
block|{
name|char
modifier|*
name|ty_name
decl_stmt|;
comment|/* terminal device name */
name|char
modifier|*
name|ty_getty
decl_stmt|;
comment|/* command to execute, usually getty */
name|char
modifier|*
name|ty_type
decl_stmt|;
comment|/* terminal type for termcap */
define|#
directive|define
name|TTY_ON
value|0x01
comment|/* enable logins (start ty_getty program) */
define|#
directive|define
name|TTY_SECURE
value|0x02
comment|/* allow uid of 0 to login */
name|int
name|ty_status
decl_stmt|;
comment|/* status flags */
name|char
modifier|*
name|ty_window
decl_stmt|;
comment|/* command to start up window manager */
name|char
modifier|*
name|ty_comment
decl_stmt|;
comment|/* comment field */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttyent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttynam
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setttyent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|endttyent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttyent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttynam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setttyent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|endttyent
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

