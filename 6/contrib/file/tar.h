begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Ian F. Darwin 1986-1995.  * Software written by Ian F. Darwin and others;  * maintained 1995-present by Christos Zoulas and others.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Header file for public domain tar (tape archive) program.  *  * @(#)tar.h 1.20 86/10/29	Public Domain.  *  * Created 25 August 1985 by John Gilmore, ihnp4!hoptoad!gnu.  *  * $File: tar.h,v 1.11 2007/01/16 14:56:45 ljt Exp $ # checkin only  */
end_comment

begin_comment
comment|/*  * Kludge for handling systems that cannot cope with multiple  * external definitions of a variable.  In ONE routine (tar.c),  * we #define TAR_EXTERN to null; here, we set it to "extern" if  * it is not already set.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TAR_EXTERN
end_ifndef

begin_define
define|#
directive|define
name|TAR_EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* The checksum field is filled with this while the checksum is computed. */
end_comment

begin_define
define|#
directive|define
name|CHKBLANKS
value|"        "
end_define

begin_comment
comment|/* 8 blanks, no null */
end_comment

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

begin_comment
comment|/* The linkflag defines the type of file */
end_comment

begin_define
define|#
directive|define
name|LF_OLDNORMAL
value|'\0'
end_define

begin_comment
comment|/* Normal disk file, Unix compat */
end_comment

begin_define
define|#
directive|define
name|LF_NORMAL
value|'0'
end_define

begin_comment
comment|/* Normal disk file */
end_comment

begin_define
define|#
directive|define
name|LF_LINK
value|'1'
end_define

begin_comment
comment|/* Link to previously dumped file */
end_comment

begin_define
define|#
directive|define
name|LF_SYMLINK
value|'2'
end_define

begin_comment
comment|/* Symbolic link */
end_comment

begin_define
define|#
directive|define
name|LF_CHR
value|'3'
end_define

begin_comment
comment|/* Character special file */
end_comment

begin_define
define|#
directive|define
name|LF_BLK
value|'4'
end_define

begin_comment
comment|/* Block special file */
end_comment

begin_define
define|#
directive|define
name|LF_DIR
value|'5'
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|LF_FIFO
value|'6'
end_define

begin_comment
comment|/* FIFO special file */
end_comment

begin_define
define|#
directive|define
name|LF_CONTIG
value|'7'
end_define

begin_comment
comment|/* Contiguous file */
end_comment

begin_comment
comment|/* Further link types may be defined later. */
end_comment

begin_comment
comment|/*  * Exit codes from the "tar" program  */
end_comment

begin_define
define|#
directive|define
name|EX_SUCCESS
value|0
end_define

begin_comment
comment|/* success! */
end_comment

begin_define
define|#
directive|define
name|EX_ARGSBAD
value|1
end_define

begin_comment
comment|/* invalid args */
end_comment

begin_define
define|#
directive|define
name|EX_BADFILE
value|2
end_define

begin_comment
comment|/* invalid filename */
end_comment

begin_define
define|#
directive|define
name|EX_BADARCH
value|3
end_define

begin_comment
comment|/* bad archive */
end_comment

begin_define
define|#
directive|define
name|EX_SYSTEM
value|4
end_define

begin_comment
comment|/* system gave unexpected error */
end_comment

begin_comment
comment|/*  * Structure for keeping track of filenames and lists thereof.  */
end_comment

begin_struct
struct|struct
name|name
block|{
name|struct
name|name
modifier|*
name|next
decl_stmt|;
name|short
name|length
decl_stmt|;
name|char
name|found
decl_stmt|;
name|char
name|name
index|[
name|NAMSIZ
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  * Due to the next struct declaration, each routine that includes  * "tar.h" must also include<sys/types.h>.  I tried to make it automatic,  * but System V has no defines in<sys/types.h>, so there is no way of  * knowing when it has been included.  In addition, it cannot be included  * twice, but must be included exactly once.  Argghh!  *  * Thanks, typedef.  Thanks, USG.  */
end_comment

begin_struct
struct|struct
name|link
block|{
name|struct
name|link
modifier|*
name|next
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
name|ino_t
name|ino
decl_stmt|;
name|short
name|linkcount
decl_stmt|;
name|char
name|name
index|[
name|NAMSIZ
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

