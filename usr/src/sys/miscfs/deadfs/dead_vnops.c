begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dead_vnops.c	7.19 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"namei.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_comment
comment|/*  * Prototypes for dead operations on vnodes.  */
end_comment

begin_decl_stmt
name|int
name|dead_badop
argument_list|()
decl_stmt|,
name|dead_ebadf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lookup_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_create
value|((int (*) __P((struct  vop_create_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_mknod
value|((int (*) __P((struct  vop_mknod_args *)))dead_badop)
end_define

begin_decl_stmt
name|int
name|dead_open
name|__P
argument_list|(
operator|(
expr|struct
name|vop_open_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_close
value|((int (*) __P((struct  vop_close_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_access
value|((int (*) __P((struct  vop_access_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_getattr
value|((int (*) __P((struct  vop_getattr_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_setattr
value|((int (*) __P((struct  vop_setattr_args *)))dead_ebadf)
end_define

begin_decl_stmt
name|int
name|dead_read
name|__P
argument_list|(
operator|(
expr|struct
name|vop_read_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vop_ioctl_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead_select
name|__P
argument_list|(
operator|(
expr|struct
name|vop_select_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_mmap
value|((int (*) __P((struct  vop_mmap_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_fsync
value|((int (*) __P((struct  vop_fsync_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_seek
value|((int (*) __P((struct  vop_seek_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_remove
value|((int (*) __P((struct  vop_remove_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_link
value|((int (*) __P((struct  vop_link_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_rename
value|((int (*) __P((struct  vop_rename_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_mkdir
value|((int (*) __P((struct  vop_mkdir_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_rmdir
value|((int (*) __P((struct  vop_rmdir_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_symlink
value|((int (*) __P((struct  vop_symlink_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_readdir
value|((int (*) __P((struct  vop_readdir_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_readlink
value|((int (*) __P((struct  vop_readlink_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_abortop
value|((int (*) __P((struct  vop_abortop_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_inactive
value|((int (*) __P((struct  vop_inactive_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_reclaim
value|((int (*) __P((struct  vop_reclaim_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|dead_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_unlock
value|((int (*) __P((struct  vop_unlock_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|dead_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|vop_strategy_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead_print
name|__P
argument_list|(
operator|(
expr|struct
name|vop_print_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_islocked
value|((int (*) __P((struct  vop_islocked_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_advlock
value|((int (*) __P((struct  vop_advlock_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_blkatoff
value|((int (*) __P((struct  vop_blkatoff_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_vget
value|((int (*) __P((struct  vop_vget_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_valloc
value|((int (*) __P((struct  vop_valloc_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_vfree
value|((int (*) __P((struct  vop_vfree_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_truncate
value|((int (*) __P((struct  vop_truncate_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_update
value|((int (*) __P((struct  vop_update_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_bwrite
value|((int (*) __P((struct  vop_bwrite_args *)))nullop)
end_define

begin_function_decl
name|int
function_decl|(
modifier|*
modifier|*
name|dead_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|vnodeopv_entry_desc
name|dead_vnodeop_entries
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
name|dead_lookup
block|}
block|,
comment|/* lookup */
block|{
operator|&
name|vop_create_desc
block|,
name|dead_create
block|}
block|,
comment|/* create */
block|{
operator|&
name|vop_mknod_desc
block|,
name|dead_mknod
block|}
block|,
comment|/* mknod */
block|{
operator|&
name|vop_open_desc
block|,
name|dead_open
block|}
block|,
comment|/* open */
block|{
operator|&
name|vop_close_desc
block|,
name|dead_close
block|}
block|,
comment|/* close */
block|{
operator|&
name|vop_access_desc
block|,
name|dead_access
block|}
block|,
comment|/* access */
block|{
operator|&
name|vop_getattr_desc
block|,
name|dead_getattr
block|}
block|,
comment|/* getattr */
block|{
operator|&
name|vop_setattr_desc
block|,
name|dead_setattr
block|}
block|,
comment|/* setattr */
block|{
operator|&
name|vop_read_desc
block|,
name|dead_read
block|}
block|,
comment|/* read */
block|{
operator|&
name|vop_write_desc
block|,
name|dead_write
block|}
block|,
comment|/* write */
block|{
operator|&
name|vop_ioctl_desc
block|,
name|dead_ioctl
block|}
block|,
comment|/* ioctl */
block|{
operator|&
name|vop_select_desc
block|,
name|dead_select
block|}
block|,
comment|/* select */
block|{
operator|&
name|vop_mmap_desc
block|,
name|dead_mmap
block|}
block|,
comment|/* mmap */
block|{
operator|&
name|vop_fsync_desc
block|,
name|dead_fsync
block|}
block|,
comment|/* fsync */
block|{
operator|&
name|vop_seek_desc
block|,
name|dead_seek
block|}
block|,
comment|/* seek */
block|{
operator|&
name|vop_remove_desc
block|,
name|dead_remove
block|}
block|,
comment|/* remove */
block|{
operator|&
name|vop_link_desc
block|,
name|dead_link
block|}
block|,
comment|/* link */
block|{
operator|&
name|vop_rename_desc
block|,
name|dead_rename
block|}
block|,
comment|/* rename */
block|{
operator|&
name|vop_mkdir_desc
block|,
name|dead_mkdir
block|}
block|,
comment|/* mkdir */
block|{
operator|&
name|vop_rmdir_desc
block|,
name|dead_rmdir
block|}
block|,
comment|/* rmdir */
block|{
operator|&
name|vop_symlink_desc
block|,
name|dead_symlink
block|}
block|,
comment|/* symlink */
block|{
operator|&
name|vop_readdir_desc
block|,
name|dead_readdir
block|}
block|,
comment|/* readdir */
block|{
operator|&
name|vop_readlink_desc
block|,
name|dead_readlink
block|}
block|,
comment|/* readlink */
block|{
operator|&
name|vop_abortop_desc
block|,
name|dead_abortop
block|}
block|,
comment|/* abortop */
block|{
operator|&
name|vop_inactive_desc
block|,
name|dead_inactive
block|}
block|,
comment|/* inactive */
block|{
operator|&
name|vop_reclaim_desc
block|,
name|dead_reclaim
block|}
block|,
comment|/* reclaim */
block|{
operator|&
name|vop_lock_desc
block|,
name|dead_lock
block|}
block|,
comment|/* lock */
block|{
operator|&
name|vop_unlock_desc
block|,
name|dead_unlock
block|}
block|,
comment|/* unlock */
block|{
operator|&
name|vop_bmap_desc
block|,
name|dead_bmap
block|}
block|,
comment|/* bmap */
block|{
operator|&
name|vop_strategy_desc
block|,
name|dead_strategy
block|}
block|,
comment|/* strategy */
block|{
operator|&
name|vop_print_desc
block|,
name|dead_print
block|}
block|,
comment|/* print */
block|{
operator|&
name|vop_islocked_desc
block|,
name|dead_islocked
block|}
block|,
comment|/* islocked */
block|{
operator|&
name|vop_advlock_desc
block|,
name|dead_advlock
block|}
block|,
comment|/* advlock */
block|{
operator|&
name|vop_blkatoff_desc
block|,
name|dead_blkatoff
block|}
block|,
comment|/* blkatoff */
block|{
operator|&
name|vop_vget_desc
block|,
name|dead_vget
block|}
block|,
comment|/* vget */
block|{
operator|&
name|vop_valloc_desc
block|,
name|dead_valloc
block|}
block|,
comment|/* valloc */
block|{
operator|&
name|vop_vfree_desc
block|,
name|dead_vfree
block|}
block|,
comment|/* vfree */
block|{
operator|&
name|vop_truncate_desc
block|,
name|dead_truncate
block|}
block|,
comment|/* truncate */
block|{
operator|&
name|vop_update_desc
block|,
name|dead_update
block|}
block|,
comment|/* update */
block|{
operator|&
name|vop_bwrite_desc
block|,
name|dead_bwrite
block|}
block|,
comment|/* bwrite */
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
name|dead_vnodeop_opv_desc
init|=
block|{
operator|&
name|dead_vnodeop_p
block|,
name|dead_vnodeop_entries
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Trivial lookup routine that always fails.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|dead_lookup
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_lookup_args
modifier|*
name|ap
decl_stmt|;
block|{
operator|*
name|ap
operator|->
name|a_vpp
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|ENOTDIR
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Open always fails as if device did not exist.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_open
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_open_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Vnode op for read  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_read
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_read_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
condition|)
name|panic
argument_list|(
literal|"dead_read: lock"
argument_list|)
expr_stmt|;
comment|/* 	 * Return EOF for character devices, EIO for others 	 */
if|if
condition|(
name|ap
operator|->
name|a_vp
operator|->
name|v_type
operator|!=
name|VCHR
condition|)
return|return
operator|(
name|EIO
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Vnode op for write  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_write
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_write_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
condition|)
name|panic
argument_list|(
literal|"dead_write: lock"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Device ioctl operation.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_ioctl
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_ioctl_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|USES_VOP_IOCTL
expr_stmt|;
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
condition|)
return|return
operator|(
name|EBADF
operator|)
return|;
return|return
operator|(
name|VOP_IOCTL
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|,
name|ap
operator|->
name|a_command
argument_list|,
name|ap
operator|->
name|a_data
argument_list|,
name|ap
operator|->
name|a_fflag
argument_list|,
name|ap
operator|->
name|a_cred
argument_list|,
name|ap
operator|->
name|a_p
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_select
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_select_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Let the user find out that the descriptor is gone. 	 */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Just call the device strategy routine  */
end_comment

begin_macro
name|dead_strategy
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_strategy_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|USES_VOP_STRATEGY
expr_stmt|;
if|if
condition|(
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
operator|==
name|NULL
operator|||
operator|!
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
argument_list|)
condition|)
block|{
name|ap
operator|->
name|a_bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|biodone
argument_list|(
name|ap
operator|->
name|a_bp
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
return|return
operator|(
name|VOP_STRATEGY
argument_list|(
name|ap
operator|->
name|a_bp
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Wait until the vnode has finished changing state.  */
end_comment

begin_macro
name|dead_lock
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_lock_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|USES_VOP_LOCK
expr_stmt|;
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|VOP_LOCK
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Wait until the vnode has finished changing state.  */
end_comment

begin_macro
name|dead_bmap
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_bmap_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|USES_VOP_BMAP
expr_stmt|;
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
condition|)
return|return
operator|(
name|EIO
operator|)
return|;
return|return
operator|(
name|VOP_BMAP
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|,
name|ap
operator|->
name|a_bn
argument_list|,
name|ap
operator|->
name|a_vpp
argument_list|,
name|ap
operator|->
name|a_bnp
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Print out the contents of a dead vnode.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_print
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_print_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"tag VT_NON, dead vnode\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Empty vnode failed operation  */
end_comment

begin_macro
name|dead_ebadf
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|EBADF
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Empty vnode bad operation  */
end_comment

begin_macro
name|dead_badop
argument_list|()
end_macro

begin_block
block|{
name|panic
argument_list|(
literal|"dead_badop called"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_block

begin_comment
comment|/*  * Empty vnode null operation  */
end_comment

begin_macro
name|dead_nullop
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * We have to wait during times when the vnode is  * in a state of change.  */
end_comment

begin_expr_stmt
name|chkvnlock
argument_list|(
name|vp
argument_list|)
specifier|register
expr|struct
name|vnode
operator|*
name|vp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|locked
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|vp
operator|->
name|v_flag
operator|&
name|VXLOCK
condition|)
block|{
name|vp
operator|->
name|v_flag
operator||=
name|VXWANT
expr_stmt|;
name|sleep
argument_list|(
operator|(
name|caddr_t
operator|)
name|vp
argument_list|,
name|PINOD
argument_list|)
expr_stmt|;
name|locked
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|locked
operator|)
return|;
block|}
end_block

end_unit

