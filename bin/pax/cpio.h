begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cpio.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Defines common to all versions of cpio  */
end_comment

begin_define
define|#
directive|define
name|TRAILER
value|"TRAILER!!!"
end_define

begin_comment
comment|/* name in last archive record */
end_comment

begin_comment
comment|/*  * Header encoding of the different file types  */
end_comment

begin_define
define|#
directive|define
name|C_ISDIR
value|040000
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|C_ISFIFO
value|010000
end_define

begin_comment
comment|/* FIFO */
end_comment

begin_define
define|#
directive|define
name|C_ISREG
value|0100000
end_define

begin_comment
comment|/* Regular file */
end_comment

begin_define
define|#
directive|define
name|C_ISBLK
value|060000
end_define

begin_comment
comment|/* Block special file */
end_comment

begin_define
define|#
directive|define
name|C_ISCHR
value|020000
end_define

begin_comment
comment|/* Character special file */
end_comment

begin_define
define|#
directive|define
name|C_ISCTG
value|0110000
end_define

begin_comment
comment|/* Reserved for contiguous files */
end_comment

begin_define
define|#
directive|define
name|C_ISLNK
value|0120000
end_define

begin_comment
comment|/* Reserved for symbolic links */
end_comment

begin_define
define|#
directive|define
name|C_ISOCK
value|0140000
end_define

begin_comment
comment|/* Reserved for sockets */
end_comment

begin_define
define|#
directive|define
name|C_IFMT
value|0170000
end_define

begin_comment
comment|/* type of file */
end_comment

begin_comment
comment|/*  * Data Interchange Format - Extended cpio header format - POSIX 1003.1-1990  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c_magic
index|[
literal|6
index|]
decl_stmt|;
comment|/* magic cookie */
name|char
name|c_dev
index|[
literal|6
index|]
decl_stmt|;
comment|/* device number */
name|char
name|c_ino
index|[
literal|6
index|]
decl_stmt|;
comment|/* inode number */
name|char
name|c_mode
index|[
literal|6
index|]
decl_stmt|;
comment|/* file type/access */
name|char
name|c_uid
index|[
literal|6
index|]
decl_stmt|;
comment|/* owners uid */
name|char
name|c_gid
index|[
literal|6
index|]
decl_stmt|;
comment|/* owners gid */
name|char
name|c_nlink
index|[
literal|6
index|]
decl_stmt|;
comment|/* # of links at archive creation */
name|char
name|c_rdev
index|[
literal|6
index|]
decl_stmt|;
comment|/* block/char major/minor # */
name|char
name|c_mtime
index|[
literal|11
index|]
decl_stmt|;
comment|/* modification time */
name|char
name|c_namesize
index|[
literal|6
index|]
decl_stmt|;
comment|/* length of pathname */
name|char
name|c_filesize
index|[
literal|11
index|]
decl_stmt|;
comment|/* length of file in bytes */
block|}
name|HD_CPIO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAGIC
value|070707
end_define

begin_comment
comment|/* transportable archive id */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PAX_
end_ifdef

begin_define
define|#
directive|define
name|AMAGIC
value|"070707"
end_define

begin_comment
comment|/* ascii equivalent string of MAGIC */
end_comment

begin_define
define|#
directive|define
name|CPIO_MASK
value|0x3ffff
end_define

begin_comment
comment|/* bits valid in the dev/ino fields */
end_comment

begin_comment
comment|/* used for dev/inode remaps */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAX_ */
end_comment

begin_comment
comment|/*  * Binary cpio header structure  *  * CAUTION! CAUTION! CAUTION!  * Each field really represents a 16 bit short (NOT ASCII). Described as  * an array of chars in an attempt to improve portability!!  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|h_magic
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_dev
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_ino
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_mode
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_uid
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_gid
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_nlink
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_rdev
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_mtime_1
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_mtime_2
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_namesize
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_filesize_1
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|h_filesize_2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|HD_BCPIO
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_PAX_
end_ifdef

begin_comment
comment|/*  * extraction and creation macros for binary cpio  */
end_comment

begin_define
define|#
directive|define
name|SHRT_EXT
parameter_list|(
name|ch
parameter_list|)
value|((((unsigned)(ch)[0])<<8) | (((unsigned)(ch)[1])&0xff))
end_define

begin_define
define|#
directive|define
name|RSHRT_EXT
parameter_list|(
name|ch
parameter_list|)
value|((((unsigned)(ch)[1])<<8) | (((unsigned)(ch)[0])&0xff))
end_define

begin_define
define|#
directive|define
name|CHR_WR_0
parameter_list|(
name|val
parameter_list|)
value|((char)(((val)>> 24)& 0xff))
end_define

begin_define
define|#
directive|define
name|CHR_WR_1
parameter_list|(
name|val
parameter_list|)
value|((char)(((val)>> 16)& 0xff))
end_define

begin_define
define|#
directive|define
name|CHR_WR_2
parameter_list|(
name|val
parameter_list|)
value|((char)(((val)>> 8)& 0xff))
end_define

begin_define
define|#
directive|define
name|CHR_WR_3
parameter_list|(
name|val
parameter_list|)
value|((char)((val)& 0xff))
end_define

begin_comment
comment|/*  * binary cpio masks and pads  */
end_comment

begin_define
define|#
directive|define
name|BCPIO_PAD
parameter_list|(
name|x
parameter_list|)
value|((2 - ((x)& 1))& 1)
end_define

begin_comment
comment|/* pad to next 2 byte word */
end_comment

begin_define
define|#
directive|define
name|BCPIO_MASK
value|0xffff
end_define

begin_comment
comment|/* mask for dev/ino fields */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAX_ */
end_comment

begin_comment
comment|/*  * System VR4 cpio header structure (with/without file data crc)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c_magic
index|[
literal|6
index|]
decl_stmt|;
comment|/* magic cookie */
name|char
name|c_ino
index|[
literal|8
index|]
decl_stmt|;
comment|/* inode number */
name|char
name|c_mode
index|[
literal|8
index|]
decl_stmt|;
comment|/* file type/access */
name|char
name|c_uid
index|[
literal|8
index|]
decl_stmt|;
comment|/* owners uid */
name|char
name|c_gid
index|[
literal|8
index|]
decl_stmt|;
comment|/* owners gid */
name|char
name|c_nlink
index|[
literal|8
index|]
decl_stmt|;
comment|/* # of links at archive creation */
name|char
name|c_mtime
index|[
literal|8
index|]
decl_stmt|;
comment|/* modification time */
name|char
name|c_filesize
index|[
literal|8
index|]
decl_stmt|;
comment|/* length of file in bytes */
name|char
name|c_maj
index|[
literal|8
index|]
decl_stmt|;
comment|/* block/char major # */
name|char
name|c_min
index|[
literal|8
index|]
decl_stmt|;
comment|/* block/char minor # */
name|char
name|c_rmaj
index|[
literal|8
index|]
decl_stmt|;
comment|/* special file major # */
name|char
name|c_rmin
index|[
literal|8
index|]
decl_stmt|;
comment|/* special file minor # */
name|char
name|c_namesize
index|[
literal|8
index|]
decl_stmt|;
comment|/* length of pathname */
name|char
name|c_chksum
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0 OR CRC of bytes of FILE data */
block|}
name|HD_VCPIO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VMAGIC
value|070701
end_define

begin_comment
comment|/* sVr4 new portable archive id */
end_comment

begin_define
define|#
directive|define
name|VCMAGIC
value|070702
end_define

begin_comment
comment|/* sVr4 new portable archive id CRC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PAX_
end_ifdef

begin_define
define|#
directive|define
name|AVMAGIC
value|"070701"
end_define

begin_comment
comment|/* ascii string of above */
end_comment

begin_define
define|#
directive|define
name|AVCMAGIC
value|"070702"
end_define

begin_comment
comment|/* ascii string of above */
end_comment

begin_define
define|#
directive|define
name|VCPIO_PAD
parameter_list|(
name|x
parameter_list|)
value|((4 - ((x)& 3))& 3)
end_define

begin_comment
comment|/* pad to next 4 byte word */
end_comment

begin_define
define|#
directive|define
name|VCPIO_MASK
value|0xffffffff
end_define

begin_comment
comment|/* mask for dev/ino fields */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAX_ */
end_comment

end_unit

