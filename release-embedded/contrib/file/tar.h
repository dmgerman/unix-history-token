begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Ian F. Darwin 1986-1995.  * Software written by Ian F. Darwin and others;  * maintained 1995-present by Christos Zoulas and others.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Header file for public domain tar (tape archive) program.  *  * @(#)tar.h 1.20 86/10/29	Public Domain.  *  * Created 25 August 1985 by John Gilmore, ihnp4!hoptoad!gnu.  *  * $File: tar.h,v 1.13 2010/11/30 14:58:53 rrt Exp $ # checkin only  */
end_comment

begin_comment
comment|/*  * Header block on tape.  *  * I'm going to use traditional DP naming conventions here.  * A "block" is a big chunk of stuff that we do I/O on.  * A "record" is a piece of info that we care about.  * Typically many "record"s fit into a "block".  */
end_comment

begin_define
define|#
directive|define
name|RECORDSIZE
value|512
end_define

begin_define
define|#
directive|define
name|NAMSIZ
value|100
end_define

begin_define
define|#
directive|define
name|TUNMLEN
value|32
end_define

begin_define
define|#
directive|define
name|TGNMLEN
value|32
end_define

begin_union
union|union
name|record
block|{
name|unsigned
name|char
name|charptr
index|[
name|RECORDSIZE
index|]
decl_stmt|;
struct|struct
name|header
block|{
name|char
name|name
index|[
name|NAMSIZ
index|]
decl_stmt|;
name|char
name|mode
index|[
literal|8
index|]
decl_stmt|;
name|char
name|uid
index|[
literal|8
index|]
decl_stmt|;
name|char
name|gid
index|[
literal|8
index|]
decl_stmt|;
name|char
name|size
index|[
literal|12
index|]
decl_stmt|;
name|char
name|mtime
index|[
literal|12
index|]
decl_stmt|;
name|char
name|chksum
index|[
literal|8
index|]
decl_stmt|;
name|char
name|linkflag
decl_stmt|;
name|char
name|linkname
index|[
name|NAMSIZ
index|]
decl_stmt|;
name|char
name|magic
index|[
literal|8
index|]
decl_stmt|;
name|char
name|uname
index|[
name|TUNMLEN
index|]
decl_stmt|;
name|char
name|gname
index|[
name|TGNMLEN
index|]
decl_stmt|;
name|char
name|devmajor
index|[
literal|8
index|]
decl_stmt|;
name|char
name|devminor
index|[
literal|8
index|]
decl_stmt|;
block|}
name|header
struct|;
block|}
union|;
end_union

begin_comment
comment|/* The magic field is filled with this if uname and gname are valid. */
end_comment

begin_define
define|#
directive|define
name|TMAGIC
value|"ustar"
end_define

begin_comment
comment|/* 5 chars and a null */
end_comment

begin_define
define|#
directive|define
name|GNUTMAGIC
value|"ustar  "
end_define

begin_comment
comment|/* 7 chars and a null */
end_comment

end_unit

