begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dumprestore.h	8.2 (Berkeley) 1/21/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTOCOLS_DUMPRESTORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROTOCOLS_DUMPRESTORE_H_
end_define

begin_comment
comment|/*  * TP_BSIZE is the size of file blocks on the dump tapes.  * Note that TP_BSIZE must be a multiple of DEV_BSIZE.  *  * NTREC is the number of TP_BSIZE blocks that are written  * in each tape record. HIGHDENSITYTREC is the number of  * TP_BSIZE blocks that are written in each tape record on  * 6250 BPI or higher density tapes.  *  * TP_NINDIR is the number of indirect pointers in a TS_INODE  * or TS_ADDR record. Note that it must be a power of two.  */
end_comment

begin_define
define|#
directive|define
name|TP_BSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|NTREC
value|10
end_define

begin_define
define|#
directive|define
name|HIGHDENSITYTREC
value|32
end_define

begin_define
define|#
directive|define
name|TP_NINDIR
value|(TP_BSIZE/2)
end_define

begin_define
define|#
directive|define
name|LBLSIZE
value|16
end_define

begin_define
define|#
directive|define
name|NAMELEN
value|64
end_define

begin_define
define|#
directive|define
name|OFS_MAGIC
value|(int)60011
end_define

begin_define
define|#
directive|define
name|NFS_MAGIC
value|(int)60012
end_define

begin_define
define|#
directive|define
name|CHECKSUM
value|(int)84446
end_define

begin_union
union|union
name|u_spcl
block|{
name|char
name|dummy
index|[
name|TP_BSIZE
index|]
decl_stmt|;
struct|struct
name|s_spcl
block|{
name|int32_t
name|c_type
decl_stmt|;
comment|/* record type (see below) */
name|time_t
name|c_date
decl_stmt|;
comment|/* date of this dump */
name|time_t
name|c_ddate
decl_stmt|;
comment|/* date of previous dump */
name|int32_t
name|c_volume
decl_stmt|;
comment|/* dump volume number */
name|daddr_t
name|c_tapea
decl_stmt|;
comment|/* logical block of this record */
name|ino_t
name|c_inumber
decl_stmt|;
comment|/* number of inode */
name|int32_t
name|c_magic
decl_stmt|;
comment|/* magic number (see above) */
name|int32_t
name|c_checksum
decl_stmt|;
comment|/* record checksum */
name|struct
name|dinode
name|c_dinode
decl_stmt|;
comment|/* ownership and mode of inode */
name|int32_t
name|c_count
decl_stmt|;
comment|/* number of valid c_addr entries */
name|char
name|c_addr
index|[
name|TP_NINDIR
index|]
decl_stmt|;
comment|/* 1 => data; 0 => hole in inode */
name|char
name|c_label
index|[
name|LBLSIZE
index|]
decl_stmt|;
comment|/* dump label */
name|int32_t
name|c_level
decl_stmt|;
comment|/* level of this dump */
name|char
name|c_filesys
index|[
name|NAMELEN
index|]
decl_stmt|;
comment|/* name of dumpped file system */
name|char
name|c_dev
index|[
name|NAMELEN
index|]
decl_stmt|;
comment|/* name of dumpped device */
name|char
name|c_host
index|[
name|NAMELEN
index|]
decl_stmt|;
comment|/* name of dumpped host */
name|int32_t
name|c_flags
decl_stmt|;
comment|/* additional information */
name|int32_t
name|c_firstrec
decl_stmt|;
comment|/* first record on volume */
name|int32_t
name|c_spare
index|[
literal|32
index|]
decl_stmt|;
comment|/* reserved for future uses */
block|}
name|s_spcl
struct|;
block|}
name|u_spcl
union|;
end_union

begin_define
define|#
directive|define
name|spcl
value|u_spcl.s_spcl
end_define

begin_comment
comment|/*  * special record types  */
end_comment

begin_define
define|#
directive|define
name|TS_TAPE
value|1
end_define

begin_comment
comment|/* dump tape header */
end_comment

begin_define
define|#
directive|define
name|TS_INODE
value|2
end_define

begin_comment
comment|/* beginning of file record */
end_comment

begin_define
define|#
directive|define
name|TS_ADDR
value|4
end_define

begin_comment
comment|/* continuation of file record */
end_comment

begin_define
define|#
directive|define
name|TS_BITS
value|3
end_define

begin_comment
comment|/* map of inodes on tape */
end_comment

begin_define
define|#
directive|define
name|TS_CLRI
value|6
end_define

begin_comment
comment|/* map of inodes deleted since last dump */
end_comment

begin_define
define|#
directive|define
name|TS_END
value|5
end_define

begin_comment
comment|/* end of volume marker */
end_comment

begin_comment
comment|/*  * flag values  */
end_comment

begin_define
define|#
directive|define
name|DR_NEWHEADER
value|0x0001
end_define

begin_comment
comment|/* new format tape header */
end_comment

begin_define
define|#
directive|define
name|DR_NEWINODEFMT
value|0x0002
end_define

begin_comment
comment|/* new format inodes on tape */
end_comment

begin_define
define|#
directive|define
name|DUMPOUTFMT
value|"%-32s %c %s"
end_define

begin_comment
comment|/* for printf */
end_comment

begin_comment
comment|/* name, level, ctime(date) */
end_comment

begin_define
define|#
directive|define
name|DUMPINFMT
value|"%32s %c %[^\n]\n"
end_define

begin_comment
comment|/* inverse for scanf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DUMPRESTORE_H_ */
end_comment

end_unit

