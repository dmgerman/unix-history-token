begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)context.h	3.9 (Berkeley) 6/29/88  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_struct
struct|struct
name|context
block|{
name|struct
name|context
modifier|*
name|x_link
decl_stmt|;
comment|/* nested contexts */
name|char
name|x_type
decl_stmt|;
comment|/* tag for union */
union|union
block|{
struct|struct
block|{
comment|/* input is a file */
name|char
modifier|*
name|X_filename
decl_stmt|;
comment|/* input file name */
name|FILE
modifier|*
name|X_fp
decl_stmt|;
comment|/* input stream */
name|short
name|X_lineno
decl_stmt|;
comment|/* current line number */
name|char
name|X_bol
decl_stmt|;
comment|/* at beginning of line */
name|char
name|X_noerr
decl_stmt|;
comment|/* don't report errors */
name|struct
name|ww
modifier|*
name|X_errwin
decl_stmt|;
comment|/* error window */
block|}
name|x_f
struct|;
struct|struct
block|{
comment|/* input is a buffer */
name|char
modifier|*
name|X_buf
decl_stmt|;
comment|/* input buffer */
name|char
modifier|*
name|X_bufp
decl_stmt|;
comment|/* current position in buf */
name|struct
name|value
modifier|*
name|X_arg
decl_stmt|;
comment|/* argument for alias */
name|int
name|X_narg
decl_stmt|;
comment|/* number of arguments */
block|}
name|x_b
struct|;
block|}
name|x_un
union|;
comment|/* holding place for current token */
name|int
name|x_token
decl_stmt|;
comment|/* the token */
name|struct
name|value
name|x_val
decl_stmt|;
comment|/* values associated with token */
comment|/* parser error flags */
name|unsigned
name|x_erred
range|:
literal|1
decl_stmt|;
comment|/* had an error */
name|unsigned
name|x_synerred
range|:
literal|1
decl_stmt|;
comment|/* had syntax error */
name|unsigned
name|x_abort
range|:
literal|1
decl_stmt|;
comment|/* fatal error */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|x_buf
value|x_un.x_b.X_buf
end_define

begin_define
define|#
directive|define
name|x_bufp
value|x_un.x_b.X_bufp
end_define

begin_define
define|#
directive|define
name|x_arg
value|x_un.x_b.X_arg
end_define

begin_define
define|#
directive|define
name|x_narg
value|x_un.x_b.X_narg
end_define

begin_define
define|#
directive|define
name|x_filename
value|x_un.x_f.X_filename
end_define

begin_define
define|#
directive|define
name|x_fp
value|x_un.x_f.X_fp
end_define

begin_define
define|#
directive|define
name|x_lineno
value|x_un.x_f.X_lineno
end_define

begin_define
define|#
directive|define
name|x_bol
value|x_un.x_f.X_bol
end_define

begin_define
define|#
directive|define
name|x_errwin
value|x_un.x_f.X_errwin
end_define

begin_define
define|#
directive|define
name|x_noerr
value|x_un.x_f.X_noerr
end_define

begin_comment
comment|/* x_type values, 0 is reserved */
end_comment

begin_define
define|#
directive|define
name|X_FILE
value|1
end_define

begin_comment
comment|/* input is a file */
end_comment

begin_define
define|#
directive|define
name|X_BUF
value|2
end_define

begin_comment
comment|/* input is a buffer */
end_comment

begin_decl_stmt
name|struct
name|context
name|cx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current context */
end_comment

end_unit

