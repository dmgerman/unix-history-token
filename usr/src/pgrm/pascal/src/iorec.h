begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)iorec.h	5.1 (Berkeley) 6/5/85  */
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

