begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 2000  *	Poul-Henning Kamp.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kernfs.h	8.6 (Berkeley) 3/29/95  * From: FreeBSD: src/sys/miscfs/kernfs/kernfs.h 1.14  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_DEVFS_DEVFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_DEVFS_DEVFS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* No userland stuff in here... */
end_comment

begin_comment
comment|/*  * These are default sizes for the DEVFS inode table and the overflow  * table.  If the default table overflows we allocate the overflow   * table, the size of which can also be set with a sysctl.  If the  * overflow table fills you're toast.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDEVFSINO
end_ifndef

begin_define
define|#
directive|define
name|NDEVFSINO
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NDEVFSOVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|NDEVFSOVERFLOW
value|32768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the first "per mount" inode, these are used for directories  * and symlinks and the like.  Must be larger than the number of "true"  * device nodes and symlinks.  It is.  */
end_comment

begin_define
define|#
directive|define
name|DEVFSINOMOUNT
value|0x2000000
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_DEVFS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|devfs_dirent
block|{
name|int
name|de_inode
decl_stmt|;
name|int
name|de_flags
decl_stmt|;
define|#
directive|define
name|DE_WHITEOUT
value|0x1
define|#
directive|define
name|DE_DOT
value|0x2
define|#
directive|define
name|DE_DOTDOT
value|0x4
name|struct
name|dirent
modifier|*
name|de_dirent
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|devfs_dirent
argument_list|)
name|de_list
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|devfs_dirent
argument_list|)
name|de_dlist
expr_stmt|;
name|struct
name|devfs_dirent
modifier|*
name|de_dir
decl_stmt|;
name|int
name|de_links
decl_stmt|;
name|mode_t
name|de_mode
decl_stmt|;
name|uid_t
name|de_uid
decl_stmt|;
name|gid_t
name|de_gid
decl_stmt|;
name|struct
name|timespec
name|de_atime
decl_stmt|;
name|struct
name|timespec
name|de_mtime
decl_stmt|;
name|struct
name|timespec
name|de_ctime
decl_stmt|;
name|struct
name|vnode
modifier|*
name|de_vnode
decl_stmt|;
name|char
modifier|*
name|de_symlink
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devfs_mount
block|{
name|struct
name|vnode
modifier|*
name|dm_root
decl_stmt|;
comment|/* Root node */
name|struct
name|devfs_dirent
modifier|*
name|dm_rootdir
decl_stmt|;
name|struct
name|devfs_dirent
modifier|*
name|dm_basedir
decl_stmt|;
name|unsigned
name|dm_generation
decl_stmt|;
name|struct
name|devfs_dirent
modifier|*
name|dm_dirent
index|[
name|NDEVFSINO
index|]
decl_stmt|;
name|struct
name|devfs_dirent
modifier|*
modifier|*
name|dm_overflow
decl_stmt|;
name|int
name|dm_inode
decl_stmt|;
name|struct
name|lock
name|dm_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is what we fill in dm_dirent[N] for a deleted entry.  */
end_comment

begin_define
define|#
directive|define
name|DE_DELETED
value|((struct devfs_dirent *)sizeof(struct devfs_dirent))
end_define

begin_define
define|#
directive|define
name|VFSTODEVFS
parameter_list|(
name|mp
parameter_list|)
value|((struct devfs_mount *)((mp)->mnt_data))
end_define

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|devfs_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|devfs_specop_p
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|devfs_allocv
parameter_list|(
name|struct
name|devfs_dirent
modifier|*
name|de
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
modifier|*
name|devfs_itod
parameter_list|(
name|int
name|inode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|devfs_dirent
modifier|*
modifier|*
name|devfs_itode
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|,
name|int
name|inode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devfs_populate
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|devfs_dirent
modifier|*
name|devfs_newdirent
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_purge
parameter_list|(
name|struct
name|devfs_dirent
modifier|*
name|dd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|devfs_dirent
modifier|*
name|devfs_vmkdir
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|,
name|struct
name|devfs_dirent
modifier|*
name|dotdot
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FS_DEVFS_DEVFS_H_ */
end_comment

end_unit

