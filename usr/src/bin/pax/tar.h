begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * %sccs.include.redist.c%  *  *	@(#)tar.h	1.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * defines and data structures common to all tar formats  */
end_comment

begin_define
define|#
directive|define
name|NULLCNT
value|2
end_define

begin_comment
comment|/* number of null blks in trailer */
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

begin_define
define|#
directive|define
name|CHK_OFFSET
value|148
end_define

begin_comment
comment|/* start of chksum field */
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
name|BLNKSUM
value|256L
end_define

begin_comment
comment|/* sum of checksum field using ' ' */
end_comment

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

begin_comment
comment|/*  * -o options for telling tar to not write directories to the archive  */
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
comment|/*  * structure of an old tar header as appeared in BSD releases  */
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
literal|8
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

begin_comment
comment|/*  * Data Interchange Format - Extended tar Format - POSIX 1003.1-1990  */
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
literal|8
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

begin_comment
comment|/*  * Values used in typeflag field  * (only REGTYPE, LNKTYPE and SYMTYPE are used in old tar headers)  */
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

end_unit

