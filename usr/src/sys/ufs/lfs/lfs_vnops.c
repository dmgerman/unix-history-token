begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1989, 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lfs_vnops.c	7.74 (Berkeley) %G%  */
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
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
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
file|<sys/specdev.h>
end_include

begin_include
include|#
directive|include
file|<sys/fifo.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
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
file|<ufs/lfs/lfs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/lfs/lfs_extern.h>
end_include

begin_comment
comment|/* Global vfs data structures for lfs. */
end_comment

begin_decl_stmt
name|struct
name|vnodeops
name|lfs_vnodeops
init|=
block|{
name|ufs_lookup
block|,
comment|/* lookup */
name|ufs_create
block|,
comment|/* create */
name|ufs_mknod
block|,
comment|/* mknod */
name|ufs_open
block|,
comment|/* open */
name|ufs_close
block|,
comment|/* close */
name|ufs_access
block|,
comment|/* access */
name|ufs_getattr
block|,
comment|/* getattr */
name|ufs_setattr
block|,
comment|/* setattr */
name|lfs_read
block|,
comment|/* read */
name|lfs_write
block|,
comment|/* write */
name|ufs_ioctl
block|,
comment|/* ioctl */
name|ufs_select
block|,
comment|/* select */
name|ufs_mmap
block|,
comment|/* mmap */
name|lfs_fsync
block|,
comment|/* fsync */
name|ufs_seek
block|,
comment|/* seek */
name|ufs_remove
block|,
comment|/* remove */
name|ufs_link
block|,
comment|/* link */
name|ufs_rename
block|,
comment|/* rename */
name|ufs_mkdir
block|,
comment|/* mkdir */
name|ufs_rmdir
block|,
comment|/* rmdir */
name|ufs_symlink
block|,
comment|/* symlink */
name|ufs_readdir
block|,
comment|/* readdir */
name|ufs_readlink
block|,
comment|/* readlink */
name|ufs_abortop
block|,
comment|/* abortop */
name|lfs_inactive
block|,
comment|/* inactive */
name|ufs_reclaim
block|,
comment|/* reclaim */
name|ufs_lock
block|,
comment|/* lock */
name|ufs_unlock
block|,
comment|/* unlock */
name|lfs_bmap
block|,
comment|/* bmap */
name|ufs_strategy
block|,
comment|/* strategy */
name|ufs_print
block|,
comment|/* print */
name|ufs_islocked
block|,
comment|/* islocked */
name|ufs_advlock
block|,
comment|/* advlock */
name|lfs_blkatoff
block|,
comment|/* blkatoff */
name|lfs_vget
block|,
comment|/* vget */
name|lfs_valloc
block|,
comment|/* valloc */
name|lfs_vfree
block|,
comment|/* vfree */
name|lfs_truncate
block|,
comment|/* truncate */
name|lfs_update
block|,
comment|/* update */
name|lfs_bwrite
block|,
comment|/* bwrite */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeops
name|lfs_specops
init|=
block|{
name|spec_lookup
block|,
comment|/* lookup */
name|spec_create
block|,
comment|/* create */
name|spec_mknod
block|,
comment|/* mknod */
name|spec_open
block|,
comment|/* open */
name|ufsspec_close
block|,
comment|/* close */
name|ufs_access
block|,
comment|/* access */
name|ufs_getattr
block|,
comment|/* getattr */
name|ufs_setattr
block|,
comment|/* setattr */
name|ufsspec_read
block|,
comment|/* read */
name|ufsspec_write
block|,
comment|/* write */
name|spec_ioctl
block|,
comment|/* ioctl */
name|spec_select
block|,
comment|/* select */
name|spec_mmap
block|,
comment|/* mmap */
name|spec_fsync
block|,
comment|/* fsync */
name|spec_seek
block|,
comment|/* seek */
name|spec_remove
block|,
comment|/* remove */
name|spec_link
block|,
comment|/* link */
name|spec_rename
block|,
comment|/* rename */
name|spec_mkdir
block|,
comment|/* mkdir */
name|spec_rmdir
block|,
comment|/* rmdir */
name|spec_symlink
block|,
comment|/* symlink */
name|spec_readdir
block|,
comment|/* readdir */
name|spec_readlink
block|,
comment|/* readlink */
name|spec_abortop
block|,
comment|/* abortop */
name|lfs_inactive
block|,
comment|/* inactive */
name|ufs_reclaim
block|,
comment|/* reclaim */
name|ufs_lock
block|,
comment|/* lock */
name|ufs_unlock
block|,
comment|/* unlock */
name|spec_bmap
block|,
comment|/* bmap */
name|spec_strategy
block|,
comment|/* strategy */
name|ufs_print
block|,
comment|/* print */
name|ufs_islocked
block|,
comment|/* islocked */
name|spec_advlock
block|,
comment|/* advlock */
name|spec_blkatoff
block|,
comment|/* blkatoff */
name|spec_vget
block|,
comment|/* vget */
name|spec_valloc
block|,
comment|/* valloc */
name|spec_vfree
block|,
comment|/* vfree */
name|spec_truncate
block|,
comment|/* truncate */
name|lfs_update
block|,
comment|/* update */
name|lfs_bwrite
block|,
comment|/* bwrite */
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FIFO
end_ifdef

begin_decl_stmt
name|struct
name|vnodeops
name|lfs_fifoops
init|=
block|{
name|fifo_lookup
block|,
comment|/* lookup */
name|fifo_create
block|,
comment|/* create */
name|fifo_mknod
block|,
comment|/* mknod */
name|fifo_open
block|,
comment|/* open */
name|ufsfifo_close
block|,
comment|/* close */
name|ufs_access
block|,
comment|/* access */
name|ufs_getattr
block|,
comment|/* getattr */
name|ufs_setattr
block|,
comment|/* setattr */
name|ufsfifo_read
block|,
comment|/* read */
name|ufsfifo_write
block|,
comment|/* write */
name|fifo_ioctl
block|,
comment|/* ioctl */
name|fifo_select
block|,
comment|/* select */
name|fifo_mmap
block|,
comment|/* mmap */
name|fifo_fsync
block|,
comment|/* fsync */
name|fifo_seek
block|,
comment|/* seek */
name|fifo_remove
block|,
comment|/* remove */
name|fifo_link
block|,
comment|/* link */
name|fifo_rename
block|,
comment|/* rename */
name|fifo_mkdir
block|,
comment|/* mkdir */
name|fifo_rmdir
block|,
comment|/* rmdir */
name|fifo_symlink
block|,
comment|/* symlink */
name|fifo_readdir
block|,
comment|/* readdir */
name|fifo_readlink
block|,
comment|/* readlink */
name|fifo_abortop
block|,
comment|/* abortop */
name|lfs_inactive
block|,
comment|/* inactive */
name|ufs_reclaim
block|,
comment|/* reclaim */
name|ufs_lock
block|,
comment|/* lock */
name|ufs_unlock
block|,
comment|/* unlock */
name|fifo_bmap
block|,
comment|/* bmap */
name|fifo_strategy
block|,
comment|/* strategy */
name|ufs_print
block|,
comment|/* print */
name|ufs_islocked
block|,
comment|/* islocked */
name|fifo_advlock
block|,
comment|/* advlock */
name|fifo_blkatoff
block|,
comment|/* blkatoff */
name|fifo_vget
block|,
comment|/* vget */
name|fifo_valloc
block|,
comment|/* valloc */
name|fifo_vfree
block|,
comment|/* vfree */
name|fifo_truncate
block|,
comment|/* truncate */
name|lfs_update
block|,
comment|/* update */
name|lfs_bwrite
block|,
comment|/* bwrite */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIFO */
end_comment

begin_comment
comment|/*  * Vnode op for reading.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|lfs_read
argument_list|(
argument|vp
argument_list|,
argument|uio
argument_list|,
argument|ioflag
argument_list|,
argument|cred
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ioflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|inode
modifier|*
name|ip
init|=
name|VTOI
argument_list|(
name|vp
argument_list|)
decl_stmt|;
specifier|register
name|struct
name|lfs
modifier|*
name|fs
decl_stmt|;
comment|/* LFS */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
name|daddr_t
name|lbn
decl_stmt|,
name|bn
decl_stmt|,
name|rablock
decl_stmt|;
name|int
name|size
decl_stmt|,
name|diff
decl_stmt|,
name|error
init|=
literal|0
decl_stmt|;
name|long
name|n
decl_stmt|,
name|on
decl_stmt|,
name|type
decl_stmt|;
ifdef|#
directive|ifdef
name|VERBOSE
name|printf
argument_list|(
literal|"lfs_read: ino %d\n"
argument_list|,
name|ip
operator|->
name|i_number
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
name|uio
operator|->
name|uio_rw
operator|!=
name|UIO_READ
condition|)
name|panic
argument_list|(
literal|"ufs_read mode"
argument_list|)
expr_stmt|;
name|type
operator|=
name|ip
operator|->
name|i_mode
operator|&
name|IFMT
expr_stmt|;
if|if
condition|(
name|type
operator|!=
name|IFDIR
operator|&&
name|type
operator|!=
name|IFREG
operator|&&
name|type
operator|!=
name|IFLNK
condition|)
name|panic
argument_list|(
literal|"ufs_read type"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|uio
operator|->
name|uio_resid
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|uio
operator|->
name|uio_offset
operator|<
literal|0
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
name|ip
operator|->
name|i_flag
operator||=
name|IACC
expr_stmt|;
name|fs
operator|=
name|ip
operator|->
name|i_lfs
expr_stmt|;
comment|/* LFS */
do|do
block|{
name|lbn
operator|=
name|lblkno
argument_list|(
name|fs
argument_list|,
name|uio
operator|->
name|uio_offset
argument_list|)
expr_stmt|;
name|on
operator|=
name|blkoff
argument_list|(
name|fs
argument_list|,
name|uio
operator|->
name|uio_offset
argument_list|)
expr_stmt|;
name|n
operator|=
name|MIN
argument_list|(
call|(
name|unsigned
call|)
argument_list|(
name|fs
operator|->
name|lfs_bsize
operator|-
name|on
argument_list|)
argument_list|,
name|uio
operator|->
name|uio_resid
argument_list|)
expr_stmt|;
name|diff
operator|=
name|ip
operator|->
name|i_size
operator|-
name|uio
operator|->
name|uio_offset
expr_stmt|;
if|if
condition|(
name|diff
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|diff
operator|<
name|n
condition|)
name|n
operator|=
name|diff
expr_stmt|;
name|size
operator|=
name|blksize
argument_list|(
name|fs
argument_list|)
expr_stmt|;
comment|/* LFS */
name|rablock
operator|=
name|lbn
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|vp
operator|->
name|v_lastr
operator|+
literal|1
operator|==
name|lbn
operator|&&
name|lblktosize
argument_list|(
name|fs
argument_list|,
name|rablock
argument_list|)
operator|<
name|ip
operator|->
name|i_size
condition|)
name|error
operator|=
name|breada
argument_list|(
name|ITOV
argument_list|(
name|ip
argument_list|)
argument_list|,
name|lbn
argument_list|,
name|size
argument_list|,
name|rablock
argument_list|,
name|blksize
argument_list|(
name|fs
argument_list|)
argument_list|,
name|NOCRED
argument_list|,
operator|&
name|bp
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|bread
argument_list|(
name|ITOV
argument_list|(
name|ip
argument_list|)
argument_list|,
name|lbn
argument_list|,
name|size
argument_list|,
name|NOCRED
argument_list|,
operator|&
name|bp
argument_list|)
expr_stmt|;
name|vp
operator|->
name|v_lastr
operator|=
name|lbn
expr_stmt|;
name|n
operator|=
name|MIN
argument_list|(
name|n
argument_list|,
name|size
operator|-
name|bp
operator|->
name|b_resid
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|brelse
argument_list|(
name|bp
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
name|error
operator|=
name|uiomove
argument_list|(
name|bp
operator|->
name|b_un
operator|.
name|b_addr
operator|+
name|on
argument_list|,
operator|(
name|int
operator|)
name|n
argument_list|,
name|uio
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|+
name|on
operator|==
name|fs
operator|->
name|lfs_bsize
operator|||
name|uio
operator|->
name|uio_offset
operator|==
name|ip
operator|->
name|i_size
condition|)
name|bp
operator|->
name|b_flags
operator||=
name|B_AGE
expr_stmt|;
name|brelse
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|error
operator|==
literal|0
operator|&&
name|uio
operator|->
name|uio_resid
operator|>
literal|0
operator|&&
name|n
operator|!=
literal|0
condition|)
do|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Vnode op for writing.  */
end_comment

begin_expr_stmt
name|lfs_write
argument_list|(
name|vp
argument_list|,
name|uio
argument_list|,
name|ioflag
argument_list|,
name|cred
argument_list|)
specifier|register
expr|struct
name|vnode
operator|*
name|vp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ioflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|proc
modifier|*
name|p
init|=
name|uio
operator|->
name|uio_procp
decl_stmt|;
specifier|register
name|struct
name|inode
modifier|*
name|ip
init|=
name|VTOI
argument_list|(
name|vp
argument_list|)
decl_stmt|;
specifier|register
name|struct
name|lfs
modifier|*
name|fs
decl_stmt|;
comment|/* LFS */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
name|daddr_t
name|lbn
decl_stmt|,
name|bn
decl_stmt|;
name|u_long
name|osize
decl_stmt|;
name|int
name|n
decl_stmt|,
name|on
decl_stmt|,
name|flags
decl_stmt|;
name|int
name|size
decl_stmt|,
name|resid
decl_stmt|,
name|error
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|VERBOSE
name|printf
argument_list|(
literal|"lfs_write ino %d\n"
argument_list|,
name|ip
operator|->
name|i_number
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
name|uio
operator|->
name|uio_rw
operator|!=
name|UIO_WRITE
condition|)
name|panic
argument_list|(
literal|"ufs_write mode"
argument_list|)
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
name|vp
operator|->
name|v_type
condition|)
block|{
case|case
name|VREG
case|:
if|if
condition|(
name|ioflag
operator|&
name|IO_APPEND
condition|)
name|uio
operator|->
name|uio_offset
operator|=
name|ip
operator|->
name|i_size
expr_stmt|;
comment|/* fall through */
case|case
name|VLNK
case|:
break|break;
case|case
name|VDIR
case|:
if|if
condition|(
operator|(
name|ioflag
operator|&
name|IO_SYNC
operator|)
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"ufs_write nonsync dir write"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"ufs_write type"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|uio
operator|->
name|uio_offset
operator|<
literal|0
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
name|uio
operator|->
name|uio_resid
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * Maybe this should be above the vnode op call, but so long as 	 * file servers have no limits, i don't think it matters 	 */
if|if
condition|(
name|vp
operator|->
name|v_type
operator|==
name|VREG
operator|&&
name|p
operator|&&
name|uio
operator|->
name|uio_offset
operator|+
name|uio
operator|->
name|uio_resid
operator|>
name|p
operator|->
name|p_rlimit
index|[
name|RLIMIT_FSIZE
index|]
operator|.
name|rlim_cur
condition|)
block|{
name|psignal
argument_list|(
name|p
argument_list|,
name|SIGXFSZ
argument_list|)
expr_stmt|;
return|return
operator|(
name|EFBIG
operator|)
return|;
block|}
name|resid
operator|=
name|uio
operator|->
name|uio_resid
expr_stmt|;
name|osize
operator|=
name|ip
operator|->
name|i_size
expr_stmt|;
name|fs
operator|=
name|ip
operator|->
name|i_lfs
expr_stmt|;
comment|/* LFS */
name|flags
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|NOTLFS
if|if
condition|(
name|ioflag
operator|&
name|IO_SYNC
condition|)
name|flags
operator|=
name|B_SYNC
expr_stmt|;
endif|#
directive|endif
do|do
block|{
name|lbn
operator|=
name|lblkno
argument_list|(
name|fs
argument_list|,
name|uio
operator|->
name|uio_offset
argument_list|)
expr_stmt|;
name|on
operator|=
name|blkoff
argument_list|(
name|fs
argument_list|,
name|uio
operator|->
name|uio_offset
argument_list|)
expr_stmt|;
name|n
operator|=
name|MIN
argument_list|(
call|(
name|unsigned
call|)
argument_list|(
name|fs
operator|->
name|lfs_bsize
operator|-
name|on
argument_list|)
argument_list|,
name|uio
operator|->
name|uio_resid
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|<
name|fs
operator|->
name|lfs_bsize
condition|)
name|flags
operator||=
name|B_CLRBUF
expr_stmt|;
else|else
name|flags
operator|&=
operator|~
name|B_CLRBUF
expr_stmt|;
if|if
condition|(
name|error
operator|=
name|bread
argument_list|(
name|vp
argument_list|,
name|lbn
argument_list|,
name|fs
operator|->
name|lfs_bsize
argument_list|,
name|NOCRED
argument_list|,
operator|&
name|bp
argument_list|)
condition|)
break|break;
name|bn
operator|=
name|bp
operator|->
name|b_blkno
expr_stmt|;
if|if
condition|(
name|uio
operator|->
name|uio_offset
operator|+
name|n
operator|>
name|ip
operator|->
name|i_size
condition|)
block|{
name|ip
operator|->
name|i_size
operator|=
name|uio
operator|->
name|uio_offset
operator|+
name|n
expr_stmt|;
name|vnode_pager_setsize
argument_list|(
name|vp
argument_list|,
operator|(
name|u_long
operator|)
name|ip
operator|->
name|i_size
argument_list|)
expr_stmt|;
block|}
name|size
operator|=
name|blksize
argument_list|(
name|fs
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vnode_pager_uncache
argument_list|(
name|vp
argument_list|)
expr_stmt|;
name|n
operator|=
name|MIN
argument_list|(
name|n
argument_list|,
name|size
operator|-
name|bp
operator|->
name|b_resid
argument_list|)
expr_stmt|;
name|error
operator|=
name|uiomove
argument_list|(
name|bp
operator|->
name|b_un
operator|.
name|b_addr
operator|+
name|on
argument_list|,
name|n
argument_list|,
name|uio
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NOTLFS
comment|/* LFS */
if|if
condition|(
name|ioflag
operator|&
name|IO_SYNC
condition|)
operator|(
name|void
operator|)
name|bwrite
argument_list|(
name|bp
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|+
name|on
operator|==
name|fs
operator|->
name|fs_bsize
condition|)
block|{
name|bp
operator|->
name|b_flags
operator||=
name|B_AGE
expr_stmt|;
name|bawrite
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
else|else
name|bdwrite
argument_list|(
name|bp
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* 		 * XXX 		 * This doesn't handle ioflag& IO_SYNC. 		 */
name|lfs_bwrite
argument_list|(
name|bp
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ip
operator|->
name|i_flag
operator||=
name|IUPD
operator||
name|ICHG
expr_stmt|;
if|if
condition|(
name|cred
operator|->
name|cr_uid
operator|!=
literal|0
condition|)
name|ip
operator|->
name|i_mode
operator|&=
operator|~
operator|(
name|ISUID
operator||
name|ISGID
operator|)
expr_stmt|;
block|}
do|while
condition|(
name|error
operator|==
literal|0
operator|&&
name|uio
operator|->
name|uio_resid
operator|>
literal|0
operator|&&
name|n
operator|!=
literal|0
condition|)
do|;
if|if
condition|(
name|error
operator|&&
operator|(
name|ioflag
operator|&
name|IO_UNIT
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|lfs_truncate
argument_list|(
name|vp
argument_list|,
name|osize
argument_list|,
name|ioflag
operator|&
name|IO_SYNC
argument_list|)
expr_stmt|;
name|uio
operator|->
name|uio_offset
operator|-=
name|resid
operator|-
name|uio
operator|->
name|uio_resid
expr_stmt|;
name|uio
operator|->
name|uio_resid
operator|=
name|resid
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|error
operator|&&
operator|(
name|ioflag
operator|&
name|IO_SYNC
operator|)
condition|)
name|error
operator|=
name|lfs_update
argument_list|(
name|vp
argument_list|,
operator|&
name|time
argument_list|,
operator|&
name|time
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Synch an open file.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|lfs_fsync
argument_list|(
argument|vp
argument_list|,
argument|fflags
argument_list|,
argument|cred
argument_list|,
argument|waitfor
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fflags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|waitfor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|inode
modifier|*
name|ip
decl_stmt|;
ifdef|#
directive|ifdef
name|VERBOSE
name|printf
argument_list|(
literal|"lfs_fsync\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ip
operator|=
name|VTOI
argument_list|(
name|vp
argument_list|)
expr_stmt|;
if|if
condition|(
name|fflags
operator|&
name|FWRITE
condition|)
name|ip
operator|->
name|i_flag
operator||=
name|ICHG
expr_stmt|;
comment|/* 	 * XXX 	 * Sync the mounted file system associated with the file 	 * descriptor. 	 */
name|ITIMES
argument_list|(
name|ip
argument_list|,
operator|&
name|time
argument_list|,
operator|&
name|time
argument_list|)
expr_stmt|;
comment|/* LFS */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Last reference to an inode, write the inode out and if necessary,  * truncate and deallocate the file.  */
end_comment

begin_function
name|int
name|lfs_inactive
parameter_list|(
name|vp
parameter_list|,
name|p
parameter_list|)
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
specifier|extern
name|int
name|prtactive
decl_stmt|;
specifier|register
name|struct
name|inode
modifier|*
name|ip
decl_stmt|;
name|int
name|mode
decl_stmt|,
name|error
decl_stmt|;
ifdef|#
directive|ifdef
name|VERBOSE
name|printf
argument_list|(
literal|"lfs_inactive\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|prtactive
operator|&&
name|vp
operator|->
name|v_usecount
operator|!=
literal|0
condition|)
name|vprint
argument_list|(
literal|"lfs_inactive: pushing active"
argument_list|,
name|vp
argument_list|)
expr_stmt|;
comment|/* Get rid of inodes related to stale file handles. */
name|ip
operator|=
name|VTOI
argument_list|(
name|vp
argument_list|)
expr_stmt|;
if|if
condition|(
name|ip
operator|->
name|i_mode
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|vp
operator|->
name|v_flag
operator|&
name|VXLOCK
operator|)
operator|==
literal|0
condition|)
name|vgone
argument_list|(
name|vp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|error
operator|=
literal|0
expr_stmt|;
name|ILOCK
argument_list|(
name|ip
argument_list|)
expr_stmt|;
if|if
condition|(
name|ip
operator|->
name|i_nlink
operator|<=
literal|0
operator|&&
operator|(
name|vp
operator|->
name|v_mount
operator|->
name|mnt_flag
operator|&
name|MNT_RDONLY
operator|)
operator|==
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|QUOTA
if|if
condition|(
operator|!
name|getinoquota
argument_list|(
name|ip
argument_list|)
condition|)
operator|(
name|void
operator|)
name|chkiq
argument_list|(
name|ip
argument_list|,
operator|-
literal|1
argument_list|,
name|NOCRED
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|error
operator|=
name|lfs_truncate
argument_list|(
name|vp
argument_list|,
operator|(
name|u_long
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mode
operator|=
name|ip
operator|->
name|i_mode
expr_stmt|;
name|ip
operator|->
name|i_mode
operator|=
literal|0
expr_stmt|;
name|ip
operator|->
name|i_rdev
operator|=
literal|0
expr_stmt|;
name|ip
operator|->
name|i_flag
operator||=
name|IUPD
operator||
name|ICHG
expr_stmt|;
name|lfs_vfree
argument_list|(
name|vp
argument_list|,
name|ip
operator|->
name|i_number
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ip
operator|->
name|i_flag
operator|&
operator|(
name|IUPD
operator||
name|IACC
operator||
name|ICHG
operator||
name|IMOD
operator|)
condition|)
name|lfs_update
argument_list|(
name|vp
argument_list|,
operator|&
name|time
argument_list|,
operator|&
name|time
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|IUNLOCK
argument_list|(
name|ip
argument_list|)
expr_stmt|;
name|ip
operator|->
name|i_flag
operator|=
literal|0
expr_stmt|;
comment|/* 	 * If we are done with the inode, reclaim it 	 * so that it can be reused immediately. 	 */
if|if
condition|(
name|vp
operator|->
name|v_usecount
operator|==
literal|0
operator|&&
name|ip
operator|->
name|i_mode
operator|==
literal|0
condition|)
name|vgone
argument_list|(
name|vp
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

end_unit

