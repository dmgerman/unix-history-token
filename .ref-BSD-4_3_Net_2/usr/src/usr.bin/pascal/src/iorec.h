begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)iorec.h	5.2 (Berkeley) 4/16/91  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|NAMSIZ
value|76
end_define

begin_struct
struct|struct
name|iorec
block|{
name|char
modifier|*
name|fileptr
decl_stmt|;
comment|/* ptr to file window */
name|long
name|lcount
decl_stmt|;
comment|/* number of lines printed */
name|long
name|llimit
decl_stmt|;
comment|/* maximum number of text lines */
name|FILE
modifier|*
name|fbuf
decl_stmt|;
comment|/* FILE ptr */
name|struct
name|iorec
modifier|*
name|fchain
decl_stmt|;
comment|/* chain to next file */
name|long
modifier|*
name|flev
decl_stmt|;
comment|/* ptr to associated file variable */
name|char
modifier|*
name|pfname
decl_stmt|;
comment|/* ptr to name of file */
name|long
name|funit
decl_stmt|;
comment|/* file status flags */
name|long
name|size
decl_stmt|;
comment|/* size of elements in the file */
name|char
name|fname
index|[
name|NAMSIZ
index|]
decl_stmt|;
comment|/* name of associated UNIX file */
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* I/O buffer */
name|char
name|window
index|[
literal|1
index|]
decl_stmt|;
comment|/* file window element */
block|}
struct|;
end_struct

end_unit

