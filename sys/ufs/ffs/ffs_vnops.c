begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ffs_vnops.c	8.7 (Berkeley) 2/3/94  * $Id: ffs_vnops.c,v 1.12 1995/09/06 05:41:17 dyson Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lockf.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<miscfs/specfs/specdev.h>
end_include

begin_include
include|#
directive|include
file|<miscfs/fifofs/fifo.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/quota.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/inode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dir.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/ufs_extern.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/ffs_extern.h>
end_include

begin_comment
comment|/* Global vfs data structures for ufs. */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
modifier|*
name|ffs_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|vnodeopv_entry_desc
name|ffs_vnodeop_entries
index|[]
init|=
block|{
block|{
operator|&
name|vop_default_desc
block|,
name|vn_default_error
block|}
block|,
block|{
operator|&
name|vop_lookup_desc
block|,
name|ufs_lookup
block|}
block|,
comment|/* lookup */
block|{
operator|&
name|vop_create_desc
block|,
name|ufs_create
block|}
block|,
comment|/* create */
block|{
operator|&
name|vop_mknod_desc
block|,
name|ufs_mknod
block|}
block|,
comment|/* mknod */
block|{
operator|&
name|vop_open_desc
block|,
name|ufs_open
block|}
block|,
comment|/* open */
block|{
operator|&
name|vop_close_desc
block|,
name|ufs_close
block|}
block|,
comment|/* close */
block|{
operator|&
name|vop_access_desc
block|,
name|ufs_access
block|}
block|,
comment|/* access */
block|{
operator|&
name|vop_getattr_desc
block|,
name|ufs_getattr
block|}
block|,
comment|/* getattr */
block|{
operator|&
name|vop_setattr_desc
block|,
name|ufs_setattr
block|}
block|,
comment|/* setattr */
block|{
operator|&
name|vop_read_desc
block|,
name|ffs_read
block|}
block|,
comment|/* read */
block|{
operator|&
name|vop_write_desc
block|,
name|ffs_write
block|}
block|,
comment|/* write */
block|{
operator|&
name|vop_ioctl_desc
block|,
name|ufs_ioctl
block|}
block|,
comment|/* ioctl */
block|{
operator|&
name|vop_select_desc
block|,
name|ufs_select
block|}
block|,
comment|/* select */
block|{
operator|&
name|vop_mmap_desc
block|,
name|ufs_mmap
block|}
block|,
comment|/* mmap */
block|{
operator|&
name|vop_fsync_desc
block|,
name|ffs_fsync
block|}
block|,
comment|/* fsync */
block|{
operator|&
name|vop_seek_desc
block|,
name|ufs_seek
block|}
block|,
comment|/* seek */
block|{
operator|&
name|vop_remove_desc
block|,
name|ufs_remove
block|}
block|,
comment|/* remove */
block|{
operator|&
name|vop_link_desc
block|,
name|ufs_link
block|}
block|,
comment|/* link */
block|{
operator|&
name|vop_rename_desc
block|,
name|ufs_rename
block|}
block|,
comment|/* rename */
block|{
operator|&
name|vop_mkdir_desc
block|,
name|ufs_mkdir
block|}
block|,
comment|/* mkdir */
block|{
operator|&
name|vop_rmdir_desc
block|,
name|ufs_rmdir
block|}
block|,
comment|/* rmdir */
block|{
operator|&
name|vop_symlink_desc
block|,
name|ufs_symlink
block|}
block|,
comment|/* symlink */
block|{
operator|&
name|vop_readdir_desc
block|,
name|ufs_readdir
block|}
block|,
comment|/* readdir */
block|{
operator|&
name|vop_readlink_desc
block|,
name|ufs_readlink
block|}
block|,
comment|/* readlink */
block|{
operator|&
name|vop_abortop_desc
block|,
name|ufs_abortop
block|}
block|,
comment|/* abortop */
block|{
operator|&
name|vop_inactive_desc
block|,
name|ufs_inactive
block|}
block|,
comment|/* inactive */
block|{
operator|&
name|vop_reclaim_desc
block|,
name|ufs_reclaim
block|}
block|,
comment|/* reclaim */
block|{
operator|&
name|vop_lock_desc
block|,
name|ufs_lock
block|}
block|,
comment|/* lock */
block|{
operator|&
name|vop_unlock_desc
block|,
name|ufs_unlock
block|}
block|,
comment|/* unlock */
block|{
operator|&
name|vop_bmap_desc
block|,
name|ufs_bmap
block|}
block|,
comment|/* bmap */
block|{
operator|&
name|vop_strategy_desc
block|,
name|ufs_strategy
block|}
block|,
comment|/* strategy */
block|{
operator|&
name|vop_print_desc
block|,
name|ufs_print
block|}
block|,
comment|/* print */
block|{
operator|&
name|vop_islocked_desc
block|,
name|ufs_islocked
block|}
block|,
comment|/* islocked */
block|{
operator|&
name|vop_pathconf_desc
block|,
name|ufs_pathconf
block|}
block|,
comment|/* pathconf */
block|{
operator|&
name|vop_advlock_desc
block|,
name|ufs_advlock
block|}
block|,
comment|/* advlock */
block|{
operator|&
name|vop_blkatoff_desc
block|,
name|ffs_blkatoff
block|}
block|,
comment|/* blkatoff */
block|{
operator|&
name|vop_valloc_desc
block|,
name|ffs_valloc
block|}
block|,
comment|/* valloc */
block|{
operator|&
name|vop_reallocblks_desc
block|,
name|ffs_reallocblks
block|}
block|,
comment|/* reallocblks */
block|{
operator|&
name|vop_vfree_desc
block|,
name|ffs_vfree
block|}
block|,
comment|/* vfree */
block|{
operator|&
name|vop_truncate_desc
block|,
name|ffs_truncate
block|}
block|,
comment|/* truncate */
block|{
operator|&
name|vop_update_desc
block|,
name|ffs_update
block|}
block|,
comment|/* update */
block|{
operator|&
name|vop_getpages_desc
block|,
name|ffs_getpages
block|}
block|,
block|{
operator|&
name|vop_bwrite_desc
block|,
name|vn_bwrite
block|}
block|,
block|{
operator|(
expr|struct
name|vnodeop_desc
operator|*
operator|)
name|NULL
block|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeopv_desc
name|ffs_vnodeop_opv_desc
init|=
block|{
operator|&
name|ffs_vnodeop_p
block|,
name|ffs_vnodeop_entries
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
modifier|*
name|ffs_specop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|vnodeopv_entry_desc
name|ffs_specop_entries
index|[]
init|=
block|{
block|{
operator|&
name|vop_default_desc
block|,
name|vn_default_error
block|}
block|,
block|{
operator|&
name|vop_lookup_desc
block|,
name|spec_lookup
block|}
block|,
comment|/* lookup */
block|{
operator|&
name|vop_create_desc
block|,
name|spec_create
block|}
block|,
comment|/* create */
block|{
operator|&
name|vop_mknod_desc
block|,
name|spec_mknod
block|}
block|,
comment|/* mknod */
block|{
operator|&
name|vop_open_desc
block|,
name|spec_open
block|}
block|,
comment|/* open */
block|{
operator|&
name|vop_close_desc
block|,
name|ufsspec_close
block|}
block|,
comment|/* close */
block|{
operator|&
name|vop_access_desc
block|,
name|ufs_access
block|}
block|,
comment|/* access */
block|{
operator|&
name|vop_getattr_desc
block|,
name|ufs_getattr
block|}
block|,
comment|/* getattr */
block|{
operator|&
name|vop_setattr_desc
block|,
name|ufs_setattr
block|}
block|,
comment|/* setattr */
block|{
operator|&
name|vop_read_desc
block|,
name|ufsspec_read
block|}
block|,
comment|/* read */
block|{
operator|&
name|vop_write_desc
block|,
name|ufsspec_write
block|}
block|,
comment|/* write */
block|{
operator|&
name|vop_ioctl_desc
block|,
name|spec_ioctl
block|}
block|,
comment|/* ioctl */
block|{
operator|&
name|vop_select_desc
block|,
name|spec_select
block|}
block|,
comment|/* select */
block|{
operator|&
name|vop_mmap_desc
block|,
name|spec_mmap
block|}
block|,
comment|/* mmap */
block|{
operator|&
name|vop_fsync_desc
block|,
name|ffs_fsync
block|}
block|,
comment|/* fsync */
block|{
operator|&
name|vop_seek_desc
block|,
name|spec_seek
block|}
block|,
comment|/* seek */
block|{
operator|&
name|vop_remove_desc
block|,
name|spec_remove
block|}
block|,
comment|/* remove */
block|{
operator|&
name|vop_link_desc
block|,
name|spec_link
block|}
block|,
comment|/* link */
block|{
operator|&
name|vop_rename_desc
block|,
name|spec_rename
block|}
block|,
comment|/* rename */
block|{
operator|&
name|vop_mkdir_desc
block|,
name|spec_mkdir
block|}
block|,
comment|/* mkdir */
block|{
operator|&
name|vop_rmdir_desc
block|,
name|spec_rmdir
block|}
block|,
comment|/* rmdir */
block|{
operator|&
name|vop_symlink_desc
block|,
name|spec_symlink
block|}
block|,
comment|/* symlink */
block|{
operator|&
name|vop_readdir_desc
block|,
name|spec_readdir
block|}
block|,
comment|/* readdir */
block|{
operator|&
name|vop_readlink_desc
block|,
name|spec_readlink
block|}
block|,
comment|/* readlink */
block|{
operator|&
name|vop_abortop_desc
block|,
name|spec_abortop
block|}
block|,
comment|/* abortop */
block|{
operator|&
name|vop_inactive_desc
block|,
name|ufs_inactive
block|}
block|,
comment|/* inactive */
block|{
operator|&
name|vop_reclaim_desc
block|,
name|ufs_reclaim
block|}
block|,
comment|/* reclaim */
block|{
operator|&
name|vop_lock_desc
block|,
name|ufs_lock
block|}
block|,
comment|/* lock */
block|{
operator|&
name|vop_unlock_desc
block|,
name|ufs_unlock
block|}
block|,
comment|/* unlock */
block|{
operator|&
name|vop_bmap_desc
block|,
name|spec_bmap
block|}
block|,
comment|/* bmap */
block|{
operator|&
name|vop_strategy_desc
block|,
name|spec_strategy
block|}
block|,
comment|/* strategy */
block|{
operator|&
name|vop_print_desc
block|,
name|ufs_print
block|}
block|,
comment|/* print */
block|{
operator|&
name|vop_islocked_desc
block|,
name|ufs_islocked
block|}
block|,
comment|/* islocked */
block|{
operator|&
name|vop_pathconf_desc
block|,
name|spec_pathconf
block|}
block|,
comment|/* pathconf */
block|{
operator|&
name|vop_advlock_desc
block|,
name|spec_advlock
block|}
block|,
comment|/* advlock */
block|{
operator|&
name|vop_blkatoff_desc
block|,
name|spec_blkatoff
block|}
block|,
comment|/* blkatoff */
block|{
operator|&
name|vop_valloc_desc
block|,
name|spec_valloc
block|}
block|,
comment|/* valloc */
block|{
operator|&
name|vop_reallocblks_desc
block|,
name|spec_reallocblks
block|}
block|,
comment|/* reallocblks */
block|{
operator|&
name|vop_vfree_desc
block|,
name|ffs_vfree
block|}
block|,
comment|/* vfree */
block|{
operator|&
name|vop_truncate_desc
block|,
name|spec_truncate
block|}
block|,
comment|/* truncate */
block|{
operator|&
name|vop_update_desc
block|,
name|ffs_update
block|}
block|,
comment|/* update */
block|{
operator|&
name|vop_bwrite_desc
block|,
name|vn_bwrite
block|}
block|,
block|{
operator|(
expr|struct
name|vnodeop_desc
operator|*
operator|)
name|NULL
block|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeopv_desc
name|ffs_specop_opv_desc
init|=
block|{
operator|&
name|ffs_specop_p
block|,
name|ffs_specop_entries
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
modifier|*
name|ffs_fifoop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|vnodeopv_entry_desc
name|ffs_fifoop_entries
index|[]
init|=
block|{
block|{
operator|&
name|vop_default_desc
block|,
name|vn_default_error
block|}
block|,
block|{
operator|&
name|vop_lookup_desc
block|,
name|fifo_lookup
block|}
block|,
comment|/* lookup */
block|{
operator|&
name|vop_create_desc
block|,
name|fifo_create
block|}
block|,
comment|/* create */
block|{
operator|&
name|vop_mknod_desc
block|,
name|fifo_mknod
block|}
block|,
comment|/* mknod */
block|{
operator|&
name|vop_open_desc
block|,
name|fifo_open
block|}
block|,
comment|/* open */
block|{
operator|&
name|vop_close_desc
block|,
name|ufsfifo_close
block|}
block|,
comment|/* close */
block|{
operator|&
name|vop_access_desc
block|,
name|ufs_access
block|}
block|,
comment|/* access */
block|{
operator|&
name|vop_getattr_desc
block|,
name|ufs_getattr
block|}
block|,
comment|/* getattr */
block|{
operator|&
name|vop_setattr_desc
block|,
name|ufs_setattr
block|}
block|,
comment|/* setattr */
block|{
operator|&
name|vop_read_desc
block|,
name|ufsfifo_read
block|}
block|,
comment|/* read */
block|{
operator|&
name|vop_write_desc
block|,
name|ufsfifo_write
block|}
block|,
comment|/* write */
block|{
operator|&
name|vop_ioctl_desc
block|,
name|fifo_ioctl
block|}
block|,
comment|/* ioctl */
block|{
operator|&
name|vop_select_desc
block|,
name|fifo_select
block|}
block|,
comment|/* select */
block|{
operator|&
name|vop_mmap_desc
block|,
name|fifo_mmap
block|}
block|,
comment|/* mmap */
block|{
operator|&
name|vop_fsync_desc
block|,
name|ffs_fsync
block|}
block|,
comment|/* fsync */
block|{
operator|&
name|vop_seek_desc
block|,
name|fifo_seek
block|}
block|,
comment|/* seek */
block|{
operator|&
name|vop_remove_desc
block|,
name|fifo_remove
block|}
block|,
comment|/* remove */
block|{
operator|&
name|vop_link_desc
block|,
name|fifo_link
block|}
block|,
comment|/* link */
block|{
operator|&
name|vop_rename_desc
block|,
name|fifo_rename
block|}
block|,
comment|/* rename */
block|{
operator|&
name|vop_mkdir_desc
block|,
name|fifo_mkdir
block|}
block|,
comment|/* mkdir */
block|{
operator|&
name|vop_rmdir_desc
block|,
name|fifo_rmdir
block|}
block|,
comment|/* rmdir */
block|{
operator|&
name|vop_symlink_desc
block|,
name|fifo_symlink
block|}
block|,
comment|/* symlink */
block|{
operator|&
name|vop_readdir_desc
block|,
name|fifo_readdir
block|}
block|,
comment|/* readdir */
block|{
operator|&
name|vop_readlink_desc
block|,
name|fifo_readlink
block|}
block|,
comment|/* readlink */
block|{
operator|&
name|vop_abortop_desc
block|,
name|fifo_abortop
block|}
block|,
comment|/* abortop */
block|{
operator|&
name|vop_inactive_desc
block|,
name|ufs_inactive
block|}
block|,
comment|/* inactive */
block|{
operator|&
name|vop_reclaim_desc
block|,
name|ufs_reclaim
block|}
block|,
comment|/* reclaim */
block|{
operator|&
name|vop_lock_desc
block|,
name|ufs_lock
block|}
block|,
comment|/* lock */
block|{
operator|&
name|vop_unlock_desc
block|,
name|ufs_unlock
block|}
block|,
comment|/* unlock */
block|{
operator|&
name|vop_bmap_desc
block|,
name|fifo_bmap
block|}
block|,
comment|/* bmap */
block|{
operator|&
name|vop_strategy_desc
block|,
name|fifo_strategy
block|}
block|,
comment|/* strategy */
block|{
operator|&
name|vop_print_desc
block|,
name|ufs_print
block|}
block|,
comment|/* print */
block|{
operator|&
name|vop_islocked_desc
block|,
name|ufs_islocked
block|}
block|,
comment|/* islocked */
block|{
operator|&
name|vop_pathconf_desc
block|,
name|fifo_pathconf
block|}
block|,
comment|/* pathconf */
block|{
operator|&
name|vop_advlock_desc
block|,
name|fifo_advlock
block|}
block|,
comment|/* advlock */
block|{
operator|&
name|vop_blkatoff_desc
block|,
name|fifo_blkatoff
block|}
block|,
comment|/* blkatoff */
block|{
operator|&
name|vop_valloc_desc
block|,
name|fifo_valloc
block|}
block|,
comment|/* valloc */
block|{
operator|&
name|vop_reallocblks_desc
block|,
name|fifo_reallocblks
block|}
block|,
comment|/* reallocblks */
block|{
operator|&
name|vop_vfree_desc
block|,
name|ffs_vfree
block|}
block|,
comment|/* vfree */
block|{
operator|&
name|vop_truncate_desc
block|,
name|fifo_truncate
block|}
block|,
comment|/* truncate */
block|{
operator|&
name|vop_update_desc
block|,
name|ffs_update
block|}
block|,
comment|/* update */
block|{
operator|&
name|vop_bwrite_desc
block|,
name|vn_bwrite
block|}
block|,
block|{
operator|(
expr|struct
name|vnodeop_desc
operator|*
operator|)
name|NULL
block|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeopv_desc
name|ffs_fifoop_opv_desc
init|=
block|{
operator|&
name|ffs_fifoop_p
block|,
name|ffs_fifoop_entries
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|VNODEOP_SET
argument_list|(
name|ffs_vnodeop_opv_desc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNODEOP_SET
argument_list|(
name|ffs_specop_opv_desc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNODEOP_SET
argument_list|(
name|ffs_fifoop_opv_desc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  * Enabling cluster read/write operations.  */
end_comment

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_decl_stmt
name|int
name|doclusterread
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ctldebug
name|debug11
init|=
block|{
literal|"doclusterread"
block|,
operator|&
name|doclusterread
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|doclusterwrite
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ctldebug
name|debug12
init|=
block|{
literal|"doclusterwrite"
block|,
operator|&
name|doclusterwrite
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX for ufs_readwrite */
end_comment

begin_define
define|#
directive|define
name|doclusterread
value|1
end_define

begin_define
define|#
directive|define
name|doclusterwrite
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ufs/ufs/ufs_readwrite.c>
end_include

begin_comment
comment|/*  * Synch an open file.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|ffs_fsync
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_fsync_args
comment|/* { 		struct vnode *a_vp; 		struct ucred *a_cred; 		int a_waitfor; 		struct proc *a_p; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
specifier|register
name|struct
name|vnode
modifier|*
name|vp
init|=
name|ap
operator|->
name|a_vp
decl_stmt|;
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
name|struct
name|timeval
name|tv
decl_stmt|;
name|struct
name|buf
modifier|*
name|nbp
decl_stmt|;
name|int
name|pass
decl_stmt|;
name|int
name|s
decl_stmt|;
name|pass
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Flush all dirty buffers associated with a vnode. 	 */
name|loop
label|:
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
for|for
control|(
name|bp
operator|=
name|vp
operator|->
name|v_dirtyblkhd
operator|.
name|lh_first
init|;
name|bp
condition|;
name|bp
operator|=
name|nbp
control|)
block|{
name|nbp
operator|=
name|bp
operator|->
name|b_vnbufs
operator|.
name|le_next
expr_stmt|;
if|if
condition|(
operator|(
name|bp
operator|->
name|b_flags
operator|&
name|B_BUSY
operator|)
operator|||
operator|(
name|pass
operator|==
literal|0
operator|&&
operator|(
name|bp
operator|->
name|b_blkno
operator|<
literal|0
operator|)
operator|)
condition|)
continue|continue;
if|if
condition|(
operator|(
name|bp
operator|->
name|b_flags
operator|&
name|B_DELWRI
operator|)
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"ffs_fsync: not dirty"
argument_list|)
expr_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_vp
operator|!=
name|vp
operator|||
name|ap
operator|->
name|a_waitfor
operator|!=
name|MNT_NOWAIT
condition|)
block|{
name|bremfree
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|bp
operator|->
name|b_flags
operator||=
name|B_BUSY
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* 			 * Wait for I/O associated with indirect blocks to complete, 			 * since there is no way to quickly wait for them below. 			 */
if|if
condition|(
name|bp
operator|->
name|b_vp
operator|==
name|vp
operator|||
name|ap
operator|->
name|a_waitfor
operator|==
name|MNT_NOWAIT
condition|)
operator|(
name|void
operator|)
name|bawrite
argument_list|(
name|bp
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|bwrite
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|vfs_bio_awrite
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
goto|goto
name|loop
goto|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|pass
operator|==
literal|0
condition|)
block|{
name|pass
operator|=
literal|1
expr_stmt|;
goto|goto
name|loop
goto|;
block|}
if|if
condition|(
name|ap
operator|->
name|a_waitfor
operator|==
name|MNT_WAIT
condition|)
block|{
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
while|while
condition|(
name|vp
operator|->
name|v_numoutput
condition|)
block|{
name|vp
operator|->
name|v_flag
operator||=
name|VBWAIT
expr_stmt|;
operator|(
name|void
operator|)
name|tsleep
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|vp
operator|->
name|v_numoutput
argument_list|,
name|PRIBIO
operator|+
literal|1
argument_list|,
literal|"ffsfsn"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
name|vp
operator|->
name|v_dirtyblkhd
operator|.
name|lh_first
condition|)
block|{
name|vprint
argument_list|(
literal|"ffs_fsync: dirty"
argument_list|,
name|vp
argument_list|)
expr_stmt|;
goto|goto
name|loop
goto|;
block|}
endif|#
directive|endif
block|}
name|tv
operator|=
name|time
expr_stmt|;
return|return
operator|(
name|VOP_UPDATE
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|,
operator|&
name|tv
argument_list|,
operator|&
name|tv
argument_list|,
name|ap
operator|->
name|a_waitfor
operator|==
name|MNT_WAIT
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

