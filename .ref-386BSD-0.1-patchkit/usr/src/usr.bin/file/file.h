begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file.h - definitions for file(1) program  # @(#)$Header: file.h,v 1.4 87/09/18 10:56:09 ian Exp $  *  * Copyright (c) Ian F. Darwin, 1987.  * Written by Ian F. Darwin.  *  * This software is not subject to any license of the American Telephone  * and Telegraph Company or of the Regents of the University of California.  *  * Permission is granted to anyone to use this software for any purpose on  * any computer system, and to alter it and redistribute it freely, subject  * to the following restrictions:  *  * 1. The author is not responsible for the consequences of use of this  *    software, no matter how awful, even if they arise from flaws in it.  *  * 2. The origin of this software must not be misrepresented, either by  *    explicit claim or by omission.  Since few users ever read sources,  *    credits must appear in the documentation.  *  * 3. Altered versions must be plainly marked as such, and must not be  *    misrepresented as being the original software.  Since few users  *    ever read sources, credits must appear in the documentation.  *  * 4. This notice may not be removed or altered.  */
end_comment

begin_define
define|#
directive|define
name|HOWMANY
value|1024
end_define

begin_comment
comment|/* how much of the file to look at */
end_comment

begin_define
define|#
directive|define
name|MAXMAGIS
value|250
end_define

begin_comment
comment|/* max entries in /etc/magic */
end_comment

begin_define
define|#
directive|define
name|MAXDESC
value|50
end_define

begin_comment
comment|/* max leng of text description */
end_comment

begin_define
define|#
directive|define
name|MAXstring
value|32
end_define

begin_comment
comment|/* max leng of "string" types */
end_comment

begin_define
define|#
directive|define
name|ckfputs
parameter_list|(
name|str
parameter_list|,
name|fil
parameter_list|)
value|{if (fputs(str,fil)==EOF) error(ckfmsg,"");}
end_define

begin_struct
struct|struct
name|magic
block|{
name|short
name|contflag
decl_stmt|;
comment|/* 1 if '>0' appears */
name|long
name|offset
decl_stmt|;
comment|/* offset to magic number */
name|char
name|reln
decl_stmt|;
comment|/* relation (0=eq, '>'=gt, etc) */
name|char
name|type
decl_stmt|;
comment|/* int, short, long or string. */
name|char
name|vallen
decl_stmt|;
comment|/* length of string value, if any */
define|#
directive|define
name|BYTE
value|1
define|#
directive|define
name|SHORT
value|2
define|#
directive|define
name|LONG
value|4
define|#
directive|define
name|STRING
value|5
union|union
name|VALUETYPE
block|{
name|char
name|b
decl_stmt|;
name|short
name|h
decl_stmt|;
name|long
name|l
decl_stmt|;
name|char
name|s
index|[
name|MAXstring
index|]
decl_stmt|;
block|}
name|value
union|;
comment|/* either number or string */
name|char
name|desc
index|[
name|MAXDESC
index|]
decl_stmt|;
comment|/* description */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|error
argument_list|()
decl_stmt|,
name|exit
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

