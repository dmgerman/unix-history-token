begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Marshall  * Kirk McKusick and Network Associates Laboratories, the Security  * Research Division of Network Associates, Inc. under DARPA/SPAWAR  * contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA CHATS  * research program  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1982, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dinode.h	8.3 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_DINODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_DINODE_H_
end_define

begin_comment
comment|/*  * The root inode is the root of the filesystem.  Inode 0 can't be used for  * normal purposes and historically bad blocks were linked to inode 1, thus  * the root inode is 2.  (Inode 1 is no longer used for this purpose, however  * numerous dump tapes make this assumption, so we are stuck with it).  */
end_comment

begin_define
define|#
directive|define
name|ROOTINO
value|((ino_t)2)
end_define

begin_comment
comment|/*  * The Whiteout inode# is a dummy non-zero inode number which will  * never be allocated to a real file.  It is used as a place holder  * in the directory entry which has been tagged as a DT_WHT entry.  * See the comments about ROOTINO above.  */
end_comment

begin_define
define|#
directive|define
name|WINO
value|((ino_t)1)
end_define

begin_comment
comment|/*  * The size of physical and logical block numbers and time fields in UFS.  */
end_comment

begin_typedef
typedef|typedef
name|int32_t
name|ufs1_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|ufs2_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|ufs_lbn_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|ufs_time_t
typedef|;
end_typedef

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

begin_define
define|#
directive|define
name|IFWHT
value|0160000
end_define

begin_comment
comment|/* Whiteout. */
end_comment

begin_comment
comment|/*  * A dinode contains all the meta-data associated with a UFS2 file.  * This structure defines the on-disk format of a dinode. Since  * this structure describes an on-disk structure, all its fields  * are defined by types with precise widths.  */
end_comment

begin_define
define|#
directive|define
name|NXADDR
value|2
end_define

begin_comment
comment|/* External addresses in inode. */
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
name|ufs2_dinode
block|{
name|u_int16_t
name|di_mode
decl_stmt|;
comment|/*   0: IFMT, permissions; see below. */
name|int16_t
name|di_nlink
decl_stmt|;
comment|/*   2: File link count. */
name|u_int32_t
name|di_uid
decl_stmt|;
comment|/*   4: File owner. */
name|u_int32_t
name|di_gid
decl_stmt|;
comment|/*   8: File group. */
name|u_int32_t
name|di_blksize
decl_stmt|;
comment|/*  12: Inode blocksize. */
name|u_int64_t
name|di_size
decl_stmt|;
comment|/*  16: File byte count. */
name|u_int64_t
name|di_blocks
decl_stmt|;
comment|/*  24: Blocks actually held. */
name|ufs_time_t
name|di_atime
decl_stmt|;
comment|/*  32: Last access time. */
name|ufs_time_t
name|di_mtime
decl_stmt|;
comment|/*  40: Last modified time. */
name|ufs_time_t
name|di_ctime
decl_stmt|;
comment|/*  48: Last inode change time. */
name|ufs_time_t
name|di_birthtime
decl_stmt|;
comment|/*  56: Inode creation time. */
name|int32_t
name|di_mtimensec
decl_stmt|;
comment|/*  64: Last modified time. */
name|int32_t
name|di_atimensec
decl_stmt|;
comment|/*  68: Last access time. */
name|int32_t
name|di_ctimensec
decl_stmt|;
comment|/*  72: Last inode change time. */
name|int32_t
name|di_birthnsec
decl_stmt|;
comment|/*  76: Inode creation time. */
name|u_int32_t
name|di_gen
decl_stmt|;
comment|/*  80: Generation number. */
name|u_int32_t
name|di_kernflags
decl_stmt|;
comment|/*  84: Kernel flags. */
name|u_int32_t
name|di_flags
decl_stmt|;
comment|/*  88: Status flags (chflags). */
name|u_int32_t
name|di_extsize
decl_stmt|;
comment|/*  92: External attributes size. */
name|ufs2_daddr_t
name|di_extb
index|[
name|NXADDR
index|]
decl_stmt|;
comment|/*  96: External attributes block. */
name|ufs2_daddr_t
name|di_db
index|[
name|NDADDR
index|]
decl_stmt|;
comment|/* 112: Direct disk blocks. */
name|ufs2_daddr_t
name|di_ib
index|[
name|NIADDR
index|]
decl_stmt|;
comment|/* 208: Indirect disk blocks. */
name|u_int64_t
name|di_modrev
decl_stmt|;
comment|/* 232: i_modrev for NFSv4 */
name|uint32_t
name|di_freelink
decl_stmt|;
comment|/* 240: SUJ: Next unlinked inode. */
name|uint32_t
name|di_spare
index|[
literal|3
index|]
decl_stmt|;
comment|/* 244: Reserved; currently unused */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The di_db fields may be overlaid with other information for  * file types that do not have associated disk storage. Block  * and character devices overlay the first data block with their  * dev_t value. Short symbolic links place their path in the  * di_db area.  */
end_comment

begin_define
define|#
directive|define
name|di_rdev
value|di_db[0]
end_define

begin_comment
comment|/*  * A UFS1 dinode contains all the meta-data associated with a UFS1 file.  * This structure defines the on-disk format of a UFS1 dinode. Since  * this structure describes an on-disk structure, all its fields  * are defined by types with precise widths.  */
end_comment

begin_struct
struct|struct
name|ufs1_dinode
block|{
name|u_int16_t
name|di_mode
decl_stmt|;
comment|/*   0: IFMT, permissions; see below. */
name|int16_t
name|di_nlink
decl_stmt|;
comment|/*   2: File link count. */
name|uint32_t
name|di_freelink
decl_stmt|;
comment|/*   4: SUJ: Next unlinked inode. */
name|u_int64_t
name|di_size
decl_stmt|;
comment|/*   8: File byte count. */
name|int32_t
name|di_atime
decl_stmt|;
comment|/*  16: Last access time. */
name|int32_t
name|di_atimensec
decl_stmt|;
comment|/*  20: Last access time. */
name|int32_t
name|di_mtime
decl_stmt|;
comment|/*  24: Last modified time. */
name|int32_t
name|di_mtimensec
decl_stmt|;
comment|/*  28: Last modified time. */
name|int32_t
name|di_ctime
decl_stmt|;
comment|/*  32: Last inode change time. */
name|int32_t
name|di_ctimensec
decl_stmt|;
comment|/*  36: Last inode change time. */
name|ufs1_daddr_t
name|di_db
index|[
name|NDADDR
index|]
decl_stmt|;
comment|/*  40: Direct disk blocks. */
name|ufs1_daddr_t
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
name|u_int32_t
name|di_blocks
decl_stmt|;
comment|/* 104: Blocks actually held. */
name|u_int32_t
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
name|u_int64_t
name|di_modrev
decl_stmt|;
comment|/* 120: i_modrev for NFSv4 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UFS_UFS_DINODE_H_ */
end_comment

end_unit

