begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)context.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
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

