begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tar.h	8.2 (Berkeley) 4/18/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * defines and data structures common to all tar formats  */
end_comment

begin_define
define|#
directive|define
name|CHK_LEN
value|8
end_define

begin_comment
comment|/* length of checksum field */
end_comment

begin_define
define|#
directive|define
name|TNMSZ
value|100
end_define

begin_comment
comment|/* size of name field */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PAX_
end_ifdef

begin_define
define|#
directive|define
name|NULLCNT
value|2
end_define

begin_comment
comment|/* number of null blocks in trailer */
end_comment

begin_define
define|#
directive|define
name|CHK_OFFSET
value|148
end_define

begin_comment
comment|/* start of checksum field */
end_comment

begin_define
define|#
directive|define
name|BLNKSUM
value|256L
end_define

begin_comment
comment|/* sum of checksum field using ' ' */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAX_ */
end_comment

begin_comment
comment|/*  * Values used in typeflag field in all tar formats  * (only REGTYPE, LNKTYPE and SYMTYPE are used in old BSD tar headers)  */
end_comment

begin_define
define|#
directive|define
name|REGTYPE
value|'0'
end_define

begin_comment
comment|/* Regular File */
end_comment

begin_define
define|#
directive|define
name|AREGTYPE
value|'\0'
end_define

begin_comment
comment|/* Regular File */
end_comment

begin_define
define|#
directive|define
name|LNKTYPE
value|'1'
end_define

begin_comment
comment|/* Link */
end_comment

begin_define
define|#
directive|define
name|SYMTYPE
value|'2'
end_define

begin_comment
comment|/* Symlink */
end_comment

begin_define
define|#
directive|define
name|CHRTYPE
value|'3'
end_define

begin_comment
comment|/* Character Special File */
end_comment

begin_define
define|#
directive|define
name|BLKTYPE
value|'4'
end_define

begin_comment
comment|/* Block Special File */
end_comment

begin_define
define|#
directive|define
name|DIRTYPE
value|'5'
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|FIFOTYPE
value|'6'
end_define

begin_comment
comment|/* FIFO */
end_comment

begin_define
define|#
directive|define
name|CONTTYPE
value|'7'
end_define

begin_comment
comment|/* high perf file */
end_comment

begin_comment
comment|/*  * Mode field encoding of the different file types - values in octal  */
end_comment

begin_define
define|#
directive|define
name|TSUID
value|04000
end_define

begin_comment
comment|/* Set UID on execution */
end_comment

begin_define
define|#
directive|define
name|TSGID
value|02000
end_define

begin_comment
comment|/* Set GID on execution */
end_comment

begin_define
define|#
directive|define
name|TSVTX
value|01000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|TUREAD
value|00400
end_define

begin_comment
comment|/* Read by owner */
end_comment

begin_define
define|#
directive|define
name|TUWRITE
value|00200
end_define

begin_comment
comment|/* Write by owner */
end_comment

begin_define
define|#
directive|define
name|TUEXEC
value|00100
end_define

begin_comment
comment|/* Execute/Search by owner */
end_comment

begin_define
define|#
directive|define
name|TGREAD
value|00040
end_define

begin_comment
comment|/* Read by group */
end_comment

begin_define
define|#
directive|define
name|TGWRITE
value|00020
end_define

begin_comment
comment|/* Write by group */
end_comment

begin_define
define|#
directive|define
name|TGEXEC
value|00010
end_define

begin_comment
comment|/* Execute/Search by group */
end_comment

begin_define
define|#
directive|define
name|TOREAD
value|00004
end_define

begin_comment
comment|/* Read by other */
end_comment

begin_define
define|#
directive|define
name|TOWRITE
value|00002
end_define

begin_comment
comment|/* Write by other */
end_comment

begin_define
define|#
directive|define
name|TOEXEC
value|00001
end_define

begin_comment
comment|/* Execute/Search by other */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PAX_
end_ifdef

begin_comment
comment|/*  * Pad with a bit mask, much faster than doing a mod but only works on powers  * of 2. Macro below is for block of 512 bytes.  */
end_comment

begin_define
define|#
directive|define
name|TAR_PAD
parameter_list|(
name|x
parameter_list|)
value|((512 - ((x)& 511))& 511)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAX_ */
end_comment

begin_comment
comment|/*  * structure of an old tar header as it appeared in BSD releases  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
name|TNMSZ
index|]
decl_stmt|;
comment|/* name of entry */
name|char
name|mode
index|[
literal|8
index|]
decl_stmt|;
comment|/* mode */
name|char
name|uid
index|[
literal|8
index|]
decl_stmt|;
comment|/* uid */
name|char
name|gid
index|[
literal|8
index|]
decl_stmt|;
comment|/* gid */
name|char
name|size
index|[
literal|12
index|]
decl_stmt|;
comment|/* size */
name|char
name|mtime
index|[
literal|12
index|]
decl_stmt|;
comment|/* modification time */
name|char
name|chksum
index|[
name|CHK_LEN
index|]
decl_stmt|;
comment|/* checksum */
name|char
name|linkflag
decl_stmt|;
comment|/* norm, hard, or sym. */
name|char
name|linkname
index|[
name|TNMSZ
index|]
decl_stmt|;
comment|/* linked to name */
block|}
name|HD_TAR
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_PAX_
end_ifdef

begin_comment
comment|/*  * -o options for BSD tar to not write directories to the archive  */
end_comment

begin_define
define|#
directive|define
name|TAR_NODIR
value|"nodir"
end_define

begin_define
define|#
directive|define
name|TAR_OPTION
value|"write_opt"
end_define

begin_comment
comment|/*  * default device names  */
end_comment

begin_define
define|#
directive|define
name|DEV_0
value|"/dev/rmt0"
end_define

begin_define
define|#
directive|define
name|DEV_1
value|"/dev/rmt1"
end_define

begin_define
define|#
directive|define
name|DEV_4
value|"/dev/rmt4"
end_define

begin_define
define|#
directive|define
name|DEV_5
value|"/dev/rmt5"
end_define

begin_define
define|#
directive|define
name|DEV_7
value|"/dev/rmt7"
end_define

begin_define
define|#
directive|define
name|DEV_8
value|"/dev/rmt8"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAX_ */
end_comment

begin_comment
comment|/*  * Data Interchange Format - Extended tar header format - POSIX 1003.1-1990  */
end_comment

begin_define
define|#
directive|define
name|TPFSZ
value|155
end_define

begin_define
define|#
directive|define
name|TMAGIC
value|"ustar"
end_define

begin_comment
comment|/* ustar and a null */
end_comment

begin_define
define|#
directive|define
name|TMAGLEN
value|6
end_define

begin_define
define|#
directive|define
name|TVERSION
value|"00"
end_define

begin_comment
comment|/* 00 and no null */
end_comment

begin_define
define|#
directive|define
name|TVERSLEN
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
name|TNMSZ
index|]
decl_stmt|;
comment|/* name of entry */
name|char
name|mode
index|[
literal|8
index|]
decl_stmt|;
comment|/* mode */
name|char
name|uid
index|[
literal|8
index|]
decl_stmt|;
comment|/* uid */
name|char
name|gid
index|[
literal|8
index|]
decl_stmt|;
comment|/* gid */
name|char
name|size
index|[
literal|12
index|]
decl_stmt|;
comment|/* size */
name|char
name|mtime
index|[
literal|12
index|]
decl_stmt|;
comment|/* modification time */
name|char
name|chksum
index|[
name|CHK_LEN
index|]
decl_stmt|;
comment|/* checksum */
name|char
name|typeflag
decl_stmt|;
comment|/* type of file. */
name|char
name|linkname
index|[
name|TNMSZ
index|]
decl_stmt|;
comment|/* linked to name */
name|char
name|magic
index|[
name|TMAGLEN
index|]
decl_stmt|;
comment|/* magic cookie */
name|char
name|version
index|[
name|TVERSLEN
index|]
decl_stmt|;
comment|/* version */
name|char
name|uname
index|[
literal|32
index|]
decl_stmt|;
comment|/* ascii owner name */
name|char
name|gname
index|[
literal|32
index|]
decl_stmt|;
comment|/* ascii group name */
name|char
name|devmajor
index|[
literal|8
index|]
decl_stmt|;
comment|/* major device number */
name|char
name|devminor
index|[
literal|8
index|]
decl_stmt|;
comment|/* minor device number */
name|char
name|prefix
index|[
name|TPFSZ
index|]
decl_stmt|;
comment|/* linked to name */
block|}
name|HD_USTAR
typedef|;
end_typedef

end_unit

