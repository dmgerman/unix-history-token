begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)defs.h	3.18 (Berkeley) 6/29/88  */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|NWINDOW
value|9
end_define

begin_decl_stmt
name|struct
name|timeval
name|starttime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ww
modifier|*
name|window
index|[
name|NWINDOW
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the windows */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|selwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the selected window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|lastselwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last selected window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|cmdwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the command window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|framewin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the window for framing */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|boxwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the window for the box */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|fgwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last foreground window */
end_comment

begin_define
define|#
directive|define
name|isfg
parameter_list|(
name|w
parameter_list|)
value|((w)->ww_order<= fgwin->ww_order)
end_define

begin_decl_stmt
name|char
modifier|*
name|shell
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the shell argv */
end_comment

begin_decl_stmt
name|char
modifier|*
name|shellfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the shell program */
end_comment

begin_decl_stmt
name|int
name|nbufline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default buffer size for new windows */
end_comment

begin_decl_stmt
name|char
name|escapec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the escape character */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
name|char
name|quit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quit command issued */
end_comment

begin_decl_stmt
name|char
name|terse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terse mode */
end_comment

begin_decl_stmt
name|char
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug mode */
end_comment

begin_decl_stmt
name|char
name|incmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in command mode */
end_comment

begin_function_decl
name|struct
name|ww
modifier|*
name|getwin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|openwin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|vtowin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|openiwin
parameter_list|()
function_decl|;
end_function_decl

end_unit

