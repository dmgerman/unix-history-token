begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dumprestore.h	5.5 (Berkeley) %G%  */
end_comment

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
name|long
name|c_type
decl_stmt|;
comment|/* record type (see below) */
name|time_t
name|c_date
decl_stmt|;
comment|/* date of previous dump */
name|time_t
name|c_ddate
decl_stmt|;
comment|/* date of this dump */
name|long
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
name|long
name|c_magic
decl_stmt|;
comment|/* magic number (see above) */
name|long
name|c_checksum
decl_stmt|;
comment|/* record checksum */
name|struct
name|dinode
name|c_dinode
decl_stmt|;
comment|/* ownership and mode of inode */
name|long
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
name|long
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
name|long
name|c_flags
decl_stmt|;
comment|/* additional information */
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
value|1
end_define

begin_comment
comment|/* new format tape header */
end_comment

begin_define
define|#
directive|define
name|DUMPOUTFMT
value|"%-16s %c %s"
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
value|"%16s %c %[^\n]\n"
end_define

begin_comment
comment|/* inverse for scanf */
end_comment

end_unit

