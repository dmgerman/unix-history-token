begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Bill Jolitz.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)main.h	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<connect.h>
end_include

begin_struct
struct|struct
name|conversation
block|{
name|struct
name|connectdomain
name|co_cd
decl_stmt|;
comment|/* where we are connecting to */
name|char
name|co_methods
index|[
literal|100
index|]
decl_stmt|;
comment|/* how we go about making connection */
name|char
name|co_optionsbuf
index|[
literal|1024
index|]
decl_stmt|;
comment|/* options requestor wants */
name|int
name|co_constatus
decl_stmt|;
comment|/* current connection status */
name|int
name|co_errfd
decl_stmt|;
comment|/* requestor's stderr if set */
name|int
name|co_sock
decl_stmt|;
comment|/* requestor's socket if set */
name|int
name|co_rqst
decl_stmt|;
comment|/* requestor's request if set */
name|int
name|co_pid
decl_stmt|;
comment|/* connector pid if active */
block|}
struct|;
end_struct

end_unit

