begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mfsnode.h	8.2 (Berkeley) 8/11/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_MFS_MFSNODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_MFS_MFSNODE_H_
end_define

begin_comment
comment|/*  * This structure defines the control data for the memory based file system.  */
end_comment

begin_struct
struct|struct
name|mfsnode
block|{
name|struct
name|vnode
modifier|*
name|mfs_vnode
decl_stmt|;
comment|/* vnode associated with this mfsnode */
name|caddr_t
name|mfs_baseoff
decl_stmt|;
comment|/* base of file system in memory */
name|long
name|mfs_size
decl_stmt|;
comment|/* size of memory file system */
name|pid_t
name|mfs_pid
decl_stmt|;
comment|/* supporting process pid */
name|struct
name|buf
modifier|*
name|mfs_buflist
decl_stmt|;
comment|/* list of I/O requests */
name|long
name|mfs_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Convert between mfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTOMFS
parameter_list|(
name|vp
parameter_list|)
value|((struct mfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|MFSTOV
parameter_list|(
name|mfsp
parameter_list|)
value|((mfsp)->mfs_vnode)
end_define

begin_comment
comment|/* Prototypes for MFS operations on vnodes. */
end_comment

begin_define
define|#
directive|define
name|mfs_lookup
value|((int (*) __P((struct  vop_lookup_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_create
value|((int (*) __P((struct  vop_create_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_mknod
value|((int (*) __P((struct  vop_mknod_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_access
value|((int (*) __P((struct  vop_access_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_getattr
value|((int (*) __P((struct  vop_getattr_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_setattr
value|((int (*) __P((struct  vop_setattr_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_read
value|((int (*) __P((struct  vop_read_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_write
value|((int (*) __P((struct  vop_write_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_select
value|((int (*) __P((struct  vop_select_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_mmap
value|((int (*) __P((struct  vop_mmap_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_seek
value|((int (*) __P((struct  vop_seek_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_remove
value|((int (*) __P((struct  vop_remove_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_link
value|((int (*) __P((struct  vop_link_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_rename
value|((int (*) __P((struct  vop_rename_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_mkdir
value|((int (*) __P((struct  vop_mkdir_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_rmdir
value|((int (*) __P((struct  vop_rmdir_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_symlink
value|((int (*) __P((struct  vop_symlink_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_readdir
value|((int (*) __P((struct  vop_readdir_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_readlink
value|((int (*) __P((struct  vop_readlink_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_abortop
value|((int (*) __P((struct  vop_abortop_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_lock
value|((int (*) __P((struct  vop_lock_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|mfs_unlock
value|((int (*) __P((struct  vop_unlock_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|mfs_islocked
value|((int (*) __P((struct  vop_islocked_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|mfs_pathconf
value|((int (*) __P((struct  vop_pathconf_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_advlock
value|((int (*) __P((struct  vop_advlock_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_blkatoff
value|((int (*) __P((struct  vop_blkatoff_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_valloc
value|((int (*) __P((struct  vop_valloc_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_vfree
value|((int (*) __P((struct  vop_vfree_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_truncate
value|((int (*) __P((struct  vop_truncate_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_update
value|((int (*) __P((struct  vop_update_args *)))mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_bwrite
value|((int (*) __P((struct  vop_bwrite_args *)))vn_bwrite)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

