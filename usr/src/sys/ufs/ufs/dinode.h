begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)dinode.h	8.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The root inode is the root of the file system.  Inode 0 can't be used for  * normal purposes and historically bad blocks were linked to inode 1, thus  * the root inode is 2.  (Inode 1 is no longer used for this purpose, however  * numerous dump tapes make this assumption, so we are stuck with it).  */
end_comment

begin_define
define|#
directive|define
name|ROOTINO
value|((ino_t)2)
end_define

begin_comment
comment|/*  * A dinode contains all the meta-data associated with a UFS file.  * This structure defines the on-disk format of a dinode.  */
end_comment

begin_define
define|#
directive|define
name|NDADDR
value|12
end_define

begin_comment
comment|/* Direct addresses in inode. */
end_comment

begin_define
define|#
directive|define
name|NIADDR
value|3
end_define

begin_comment
comment|/* Indirect addresses in inode. */
end_comment

begin_struct
struct|struct
name|dinode
block|{
name|u_int16_t
name|di_mode
decl_stmt|;
comment|/*   0: IFMT, permissions; see below. */
name|int16_t
name|di_nlink
decl_stmt|;
comment|/*   2: File link count. */
union|union
block|{
name|u_int16_t
name|oldids
index|[
literal|2
index|]
decl_stmt|;
comment|/*   4: Ffs: old user and group ids. */
name|ino_t
name|inumber
decl_stmt|;
comment|/*   4: Lfs: inode number. */
block|}
name|di_u
union|;
name|u_quad_t
name|di_size
decl_stmt|;
comment|/*   8: File byte count. */
name|struct
name|timespec
name|di_atime
decl_stmt|;
comment|/*  16: Last access time. */
name|struct
name|timespec
name|di_mtime
decl_stmt|;
comment|/*  24: Last modified time. */
name|struct
name|timespec
name|di_ctime
decl_stmt|;
comment|/*  32: Last inode change time. */
name|daddr_t
name|di_db
index|[
name|NDADDR
index|]
decl_stmt|;
comment|/*  40: Direct disk blocks. */
name|daddr_t
name|di_ib
index|[
name|NIADDR
index|]
decl_stmt|;
comment|/*  88: Indirect disk blocks. */
name|u_int32_t
name|di_flags
decl_stmt|;
comment|/* 100: Status flags (chflags). */
name|int32_t
name|di_blocks
decl_stmt|;
comment|/* 104: Blocks actually held. */
name|int32_t
name|di_gen
decl_stmt|;
comment|/* 108: Generation number. */
name|u_int32_t
name|di_uid
decl_stmt|;
comment|/* 112: File owner. */
name|u_int32_t
name|di_gid
decl_stmt|;
comment|/* 116: File group. */
name|int32_t
name|di_spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* 120: Reserved; currently unused */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The di_db fields may be overlaid with other information for  * file types that do not have associated disk storage. Block  * and character devices overlay the first data block with their  * dev_t value. Short symbolic links place their path in the  * di_db area.  */
end_comment

begin_define
define|#
directive|define
name|di_inumber
value|di_u.inumber
end_define

begin_define
define|#
directive|define
name|di_ogid
value|di_u.oldids[1]
end_define

begin_define
define|#
directive|define
name|di_ouid
value|di_u.oldids[0]
end_define

begin_define
define|#
directive|define
name|di_rdev
value|di_db[0]
end_define

begin_define
define|#
directive|define
name|di_shortlink
value|di_db
end_define

begin_define
define|#
directive|define
name|MAXSYMLINKLEN
value|((NDADDR + NIADDR) * sizeof(daddr_t))
end_define

begin_comment
comment|/* File permissions. */
end_comment

begin_define
define|#
directive|define
name|IEXEC
value|0000100
end_define

begin_comment
comment|/* Executable. */
end_comment

begin_define
define|#
directive|define
name|IWRITE
value|0000200
end_define

begin_comment
comment|/* Writeable. */
end_comment

begin_define
define|#
directive|define
name|IREAD
value|0000400
end_define

begin_comment
comment|/* Readable. */
end_comment

begin_define
define|#
directive|define
name|ISVTX
value|0001000
end_define

begin_comment
comment|/* Sticky bit. */
end_comment

begin_define
define|#
directive|define
name|ISGID
value|0002000
end_define

begin_comment
comment|/* Set-gid. */
end_comment

begin_define
define|#
directive|define
name|ISUID
value|0004000
end_define

begin_comment
comment|/* Set-uid. */
end_comment

begin_comment
comment|/* File types. */
end_comment

begin_define
define|#
directive|define
name|IFMT
value|0170000
end_define

begin_comment
comment|/* Mask of file type. */
end_comment

begin_define
define|#
directive|define
name|IFIFO
value|0010000
end_define

begin_comment
comment|/* Named pipe (fifo). */
end_comment

begin_define
define|#
directive|define
name|IFCHR
value|0020000
end_define

begin_comment
comment|/* Character device. */
end_comment

begin_define
define|#
directive|define
name|IFDIR
value|0040000
end_define

begin_comment
comment|/* Directory file. */
end_comment

begin_define
define|#
directive|define
name|IFBLK
value|0060000
end_define

begin_comment
comment|/* Block device. */
end_comment

begin_define
define|#
directive|define
name|IFREG
value|0100000
end_define

begin_comment
comment|/* Regular file. */
end_comment

begin_define
define|#
directive|define
name|IFLNK
value|0120000
end_define

begin_comment
comment|/* Symbolic link. */
end_comment

begin_define
define|#
directive|define
name|IFSOCK
value|0140000
end_define

begin_comment
comment|/* UNIX domain socket. */
end_comment

end_unit

