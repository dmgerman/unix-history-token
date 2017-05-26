begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ufs_inode.h,v 1.3 2003/08/07 11:25:34 agc Exp $	*/
end_comment

begin_comment
comment|/* From:  NetBSD: inode.h,v 1.27 2001/12/18 10:57:23 fvdl Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)inode.h	8.9 (Berkeley) 5/14/95  * $FreeBSD$  */
end_comment

begin_union
union|union
name|dinode
block|{
name|struct
name|ufs1_dinode
name|ffs1_din
decl_stmt|;
name|struct
name|ufs2_dinode
name|ffs2_din
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|inode
block|{
name|ino_t
name|i_number
decl_stmt|;
comment|/* The identity of the inode. */
name|struct
name|vnode
modifier|*
name|i_devvp
decl_stmt|;
comment|/* vnode pointer (contains fsopts) */
name|struct
name|fs
modifier|*
name|i_fs
decl_stmt|;
comment|/* File system */
name|union
name|dinode
name|i_din
decl_stmt|;
name|uint64_t
name|i_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_ffs1_atime
value|i_din.ffs1_din.di_atime
end_define

begin_define
define|#
directive|define
name|i_ffs1_atimensec
value|i_din.ffs1_din.di_atimensec
end_define

begin_define
define|#
directive|define
name|i_ffs1_blocks
value|i_din.ffs1_din.di_blocks
end_define

begin_define
define|#
directive|define
name|i_ffs1_ctime
value|i_din.ffs1_din.di_ctime
end_define

begin_define
define|#
directive|define
name|i_ffs1_ctimensec
value|i_din.ffs1_din.di_ctimensec
end_define

begin_define
define|#
directive|define
name|i_ffs1_db
value|i_din.ffs1_din.di_db
end_define

begin_define
define|#
directive|define
name|i_ffs1_flags
value|i_din.ffs1_din.di_flags
end_define

begin_define
define|#
directive|define
name|i_ffs1_gen
value|i_din.ffs1_din.di_gen
end_define

begin_define
define|#
directive|define
name|i_ffs11_gid
value|i_din.ffs1_din.di_gid
end_define

begin_define
define|#
directive|define
name|i_ffs1_ib
value|i_din.ffs1_din.di_ib
end_define

begin_define
define|#
directive|define
name|i_ffs1_mode
value|i_din.ffs1_din.di_mode
end_define

begin_define
define|#
directive|define
name|i_ffs1_mtime
value|i_din.ffs1_din.di_mtime
end_define

begin_define
define|#
directive|define
name|i_ffs1_mtimensec
value|i_din.ffs1_din.di_mtimensec
end_define

begin_define
define|#
directive|define
name|i_ffs1_nlink
value|i_din.ffs1_din.di_nlink
end_define

begin_define
define|#
directive|define
name|i_ffs1_rdev
value|i_din.ffs1_din.di_rdev
end_define

begin_define
define|#
directive|define
name|i_ffs1_shortlink
value|i_din.ffs1_din.db
end_define

begin_define
define|#
directive|define
name|i_ffs1_size
value|i_din.ffs1_din.di_size
end_define

begin_define
define|#
directive|define
name|i_ffs1_uid
value|i_din.ffs1_din.di_uid
end_define

begin_define
define|#
directive|define
name|i_ffs2_atime
value|i_din.ffs2_din.di_atime
end_define

begin_define
define|#
directive|define
name|i_ffs2_atimensec
value|i_din.ffs2_din.di_atimensec
end_define

begin_define
define|#
directive|define
name|i_ffs2_blocks
value|i_din.ffs2_din.di_blocks
end_define

begin_define
define|#
directive|define
name|i_ffs2_ctime
value|i_din.ffs2_din.di_ctime
end_define

begin_define
define|#
directive|define
name|i_ffs2_ctimensec
value|i_din.ffs2_din.di_ctimensec
end_define

begin_define
define|#
directive|define
name|i_ffs2_birthtime
value|i_din.ffs2_din.di_birthtime
end_define

begin_define
define|#
directive|define
name|i_ffs2_birthnsec
value|i_din.ffs2_din.di_birthnsec
end_define

begin_define
define|#
directive|define
name|i_ffs2_db
value|i_din.ffs2_din.di_db
end_define

begin_define
define|#
directive|define
name|i_ffs2_flags
value|i_din.ffs2_din.di_flags
end_define

begin_define
define|#
directive|define
name|i_ffs2_gen
value|i_din.ffs2_din.di_gen
end_define

begin_define
define|#
directive|define
name|i_ffs21_gid
value|i_din.ffs2_din.di_gid
end_define

begin_define
define|#
directive|define
name|i_ffs2_ib
value|i_din.ffs2_din.di_ib
end_define

begin_define
define|#
directive|define
name|i_ffs2_mode
value|i_din.ffs2_din.di_mode
end_define

begin_define
define|#
directive|define
name|i_ffs2_mtime
value|i_din.ffs2_din.di_mtime
end_define

begin_define
define|#
directive|define
name|i_ffs2_mtimensec
value|i_din.ffs2_din.di_mtimensec
end_define

begin_define
define|#
directive|define
name|i_ffs2_nlink
value|i_din.ffs2_din.di_nlink
end_define

begin_define
define|#
directive|define
name|i_ffs2_rdev
value|i_din.ffs2_din.di_rdev
end_define

begin_define
define|#
directive|define
name|i_ffs2_shortlink
value|i_din.ffs2_din.db
end_define

begin_define
define|#
directive|define
name|i_ffs2_size
value|i_din.ffs2_din.di_size
end_define

begin_define
define|#
directive|define
name|i_ffs2_uid
value|i_din.ffs2_din.di_uid
end_define

begin_undef
undef|#
directive|undef
name|DIP
end_undef

begin_define
define|#
directive|define
name|DIP
parameter_list|(
name|ip
parameter_list|,
name|field
parameter_list|)
define|\
value|(((ip)->i_fs->fs_magic == FS_UFS1_MAGIC) ? \         (ip)->i_ffs1_##field : (ip)->i_ffs2_##field)
end_define

end_unit

