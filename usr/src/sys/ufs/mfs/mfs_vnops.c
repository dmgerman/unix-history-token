begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mfs_vnops.c	7.18 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"vmmac.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"../ufs/mfsnode.h"
end_include

begin_include
include|#
directive|include
file|"../ufs/mfsiom.h"
end_include

begin_include
include|#
directive|include
file|"machine/vmparam.h"
end_include

begin_include
include|#
directive|include
file|"machine/pte.h"
end_include

begin_include
include|#
directive|include
file|"machine/mtpr.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|hp300
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|int
name|mfsmap_want
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => need kernel I/O resources */
end_comment

begin_decl_stmt
name|struct
name|map
name|mfsmap
index|[
name|MFS_MAPSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|mfsiobuf
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * mfs vnode operations.  */
end_comment

begin_decl_stmt
name|int
name|mfs_open
argument_list|()
decl_stmt|,
name|mfs_strategy
argument_list|()
decl_stmt|,
name|mfs_bmap
argument_list|()
decl_stmt|,
name|mfs_ioctl
argument_list|()
decl_stmt|,
name|mfs_close
argument_list|()
decl_stmt|,
name|mfs_inactive
argument_list|()
decl_stmt|,
name|mfs_print
argument_list|()
decl_stmt|,
name|mfs_badop
argument_list|()
decl_stmt|,
name|mfs_nullop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeops
name|mfs_vnodeops
init|=
block|{
name|mfs_badop
block|,
comment|/* lookup */
name|mfs_badop
block|,
comment|/* create */
name|mfs_badop
block|,
comment|/* mknod */
name|mfs_open
block|,
comment|/* open */
name|mfs_close
block|,
comment|/* close */
name|mfs_badop
block|,
comment|/* access */
name|mfs_badop
block|,
comment|/* getattr */
name|mfs_badop
block|,
comment|/* setattr */
name|mfs_badop
block|,
comment|/* read */
name|mfs_badop
block|,
comment|/* write */
name|mfs_ioctl
block|,
comment|/* ioctl */
name|mfs_badop
block|,
comment|/* select */
name|mfs_badop
block|,
comment|/* mmap */
name|mfs_badop
block|,
comment|/* fsync */
name|mfs_badop
block|,
comment|/* seek */
name|mfs_badop
block|,
comment|/* remove */
name|mfs_badop
block|,
comment|/* link */
name|mfs_badop
block|,
comment|/* rename */
name|mfs_badop
block|,
comment|/* mkdir */
name|mfs_badop
block|,
comment|/* rmdir */
name|mfs_badop
block|,
comment|/* symlink */
name|mfs_badop
block|,
comment|/* readdir */
name|mfs_badop
block|,
comment|/* readlink */
name|mfs_badop
block|,
comment|/* abortop */
name|mfs_inactive
block|,
comment|/* inactive */
name|mfs_nullop
block|,
comment|/* reclaim */
name|mfs_nullop
block|,
comment|/* lock */
name|mfs_nullop
block|,
comment|/* unlock */
name|mfs_bmap
block|,
comment|/* bmap */
name|mfs_strategy
block|,
comment|/* strategy */
name|mfs_print
block|,
comment|/* print */
name|mfs_nullop
block|,
comment|/* islocked */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Vnode Operations.  *  * Open called to allow memory filesystem to initialize and  * validate before actual IO. Record our process identifier  * so we can tell when we are doing I/O to ourself.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_expr_stmt
name|mfs_open
argument_list|(
name|vp
argument_list|,
name|mode
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
name|int
name|mode
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
if|if
condition|(
name|vp
operator|->
name|v_type
operator|!=
name|VBLK
condition|)
block|{
name|panic
argument_list|(
literal|"mfs_ioctl not VBLK"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Ioctl operation.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|mfs_ioctl
argument_list|(
argument|vp
argument_list|,
argument|com
argument_list|,
argument|data
argument_list|,
argument|fflag
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
name|int
name|com
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fflag
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
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Pass I/O requests to the memory filesystem process.  */
end_comment

begin_expr_stmt
name|mfs_strategy
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|struct
name|mfsnode
modifier|*
name|mfsp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
if|if
condition|(
name|vfinddev
argument_list|(
name|bp
operator|->
name|b_dev
argument_list|,
name|VBLK
argument_list|,
operator|&
name|vp
argument_list|)
operator|||
name|vp
operator|->
name|v_usecount
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"mfs_strategy: bad dev"
argument_list|)
expr_stmt|;
name|mfsp
operator|=
name|VTOMFS
argument_list|(
name|vp
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfsp
operator|->
name|mfs_pid
operator|==
name|u
operator|.
name|u_procp
operator|->
name|p_pid
condition|)
block|{
name|mfs_doio
argument_list|(
name|bp
argument_list|,
name|mfsp
operator|->
name|mfs_baseoff
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|bp
operator|->
name|av_forw
operator|=
name|mfsp
operator|->
name|mfs_buflist
expr_stmt|;
name|mfsp
operator|->
name|mfs_buflist
operator|=
name|bp
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|vp
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_comment
comment|/*  * Memory file system I/O.  *  * Essentially play ubasetup() and disk interrupt service routine by  * doing the copies to or from the memfs process. If doing physio  * (i.e. pagein), we must map the I/O through the kernel virtual  * address space.  */
end_comment

begin_expr_stmt
name|mfs_doio
argument_list|(
name|bp
argument_list|,
name|base
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|pte
modifier|*
name|pte
decl_stmt|,
modifier|*
name|ppte
decl_stmt|;
specifier|register
name|caddr_t
name|vaddr
decl_stmt|;
name|int
name|off
decl_stmt|,
name|npf
decl_stmt|,
name|npf2
decl_stmt|,
name|reg
decl_stmt|;
name|caddr_t
name|kernaddr
decl_stmt|,
name|offset
decl_stmt|;
comment|/* 	 * For phys I/O, map the b_addr into kernel virtual space using 	 * the Mfsiomap pte's. 	 */
if|if
condition|(
operator|(
name|bp
operator|->
name|b_flags
operator|&
name|B_PHYS
operator|)
operator|==
literal|0
condition|)
block|{
name|kernaddr
operator|=
name|bp
operator|->
name|b_un
operator|.
name|b_addr
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|bp
operator|->
name|b_flags
operator|&
operator|(
name|B_PAGET
operator||
name|B_UAREA
operator||
name|B_DIRTY
operator|)
condition|)
name|panic
argument_list|(
literal|"swap on memfs?"
argument_list|)
expr_stmt|;
name|off
operator|=
operator|(
name|int
operator|)
name|bp
operator|->
name|b_un
operator|.
name|b_addr
operator|&
name|PGOFSET
expr_stmt|;
name|npf
operator|=
name|btoc
argument_list|(
name|bp
operator|->
name|b_bcount
operator|+
name|off
argument_list|)
expr_stmt|;
comment|/* 		 * Get some mapping page table entries 		 */
while|while
condition|(
operator|(
name|reg
operator|=
name|rmalloc
argument_list|(
name|mfsmap
argument_list|,
operator|(
name|long
operator|)
name|npf
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|mfsmap_want
operator|++
expr_stmt|;
name|sleep
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|mfsmap_want
argument_list|,
name|PZERO
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|reg
operator|--
expr_stmt|;
name|pte
operator|=
name|vtopte
argument_list|(
name|bp
operator|->
name|b_proc
argument_list|,
name|btop
argument_list|(
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 		 * Do vmaccess() but with the Mfsiomap page table. 		 */
name|ppte
operator|=
operator|&
name|Mfsiomap
index|[
name|reg
index|]
expr_stmt|;
name|vaddr
operator|=
operator|&
name|mfsiobuf
index|[
name|reg
operator|*
name|NBPG
index|]
expr_stmt|;
name|kernaddr
operator|=
name|vaddr
operator|+
name|off
expr_stmt|;
for|for
control|(
name|npf2
operator|=
name|npf
init|;
name|npf2
condition|;
name|npf2
operator|--
control|)
block|{
name|mapin
argument_list|(
name|ppte
argument_list|,
operator|(
name|u_int
operator|)
name|vaddr
argument_list|,
name|pte
operator|->
name|pg_pfnum
argument_list|,
call|(
name|int
call|)
argument_list|(
name|PG_V
operator||
name|PG_KW
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|tahoe
argument_list|)
if|if
condition|(
operator|(
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
operator|)
operator|==
literal|0
condition|)
name|mtpr
argument_list|(
name|P1DC
argument_list|,
name|vaddr
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ppte
operator|++
expr_stmt|;
name|pte
operator|++
expr_stmt|;
name|vaddr
operator|+=
name|NBPG
expr_stmt|;
block|}
block|}
name|offset
operator|=
name|base
operator|+
operator|(
name|bp
operator|->
name|b_blkno
operator|<<
name|DEV_BSHIFT
operator|)
expr_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|)
name|bp
operator|->
name|b_error
operator|=
name|copyin
argument_list|(
name|offset
argument_list|,
name|kernaddr
argument_list|,
name|bp
operator|->
name|b_bcount
argument_list|)
expr_stmt|;
else|else
name|bp
operator|->
name|b_error
operator|=
name|copyout
argument_list|(
name|kernaddr
argument_list|,
name|offset
argument_list|,
name|bp
operator|->
name|b_bcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_error
condition|)
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
comment|/* 	 * Release pte's used by physical I/O. 	 */
if|if
condition|(
name|bp
operator|->
name|b_flags
operator|&
name|B_PHYS
condition|)
block|{
name|rmfree
argument_list|(
name|mfsmap
argument_list|,
operator|(
name|long
operator|)
name|npf
argument_list|,
operator|(
name|long
operator|)
operator|++
name|reg
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfsmap_want
condition|)
block|{
name|mfsmap_want
operator|=
literal|0
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|mfsmap_want
argument_list|)
expr_stmt|;
block|}
block|}
name|biodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax || tahoe */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hp300
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_comment
comment|/*  * Memory file system I/O.  *  * Trivial on the HP since buffer has already been mapping into KVA space.  */
end_comment

begin_expr_stmt
name|mfs_doio
argument_list|(
name|bp
argument_list|,
name|base
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|base
operator|+=
operator|(
name|bp
operator|->
name|b_blkno
operator|<<
name|DEV_BSHIFT
operator|)
expr_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|)
name|bp
operator|->
name|b_error
operator|=
name|copyin
argument_list|(
name|base
argument_list|,
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|bp
operator|->
name|b_bcount
argument_list|)
expr_stmt|;
else|else
name|bp
operator|->
name|b_error
operator|=
name|copyout
argument_list|(
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|base
argument_list|,
name|bp
operator|->
name|b_bcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_error
condition|)
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|biodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is a noop, simply returning what one has been given.  */
end_comment

begin_macro
name|mfs_bmap
argument_list|(
argument|vp
argument_list|,
argument|bn
argument_list|,
argument|vpp
argument_list|,
argument|bnp
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
name|daddr_t
name|bn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
modifier|*
name|bnp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|vpp
operator|!=
name|NULL
condition|)
operator|*
name|vpp
operator|=
name|vp
expr_stmt|;
if|if
condition|(
name|bnp
operator|!=
name|NULL
condition|)
operator|*
name|bnp
operator|=
name|bn
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Memory filesystem close routine  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_expr_stmt
name|mfs_close
argument_list|(
name|vp
argument_list|,
name|flag
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
name|int
name|flag
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
name|mfsnode
modifier|*
name|mfsp
init|=
name|VTOMFS
argument_list|(
name|vp
argument_list|)
decl_stmt|;
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* 	 * Finish any pending I/O requests. 	 */
while|while
condition|(
name|bp
operator|=
name|mfsp
operator|->
name|mfs_buflist
condition|)
block|{
name|mfsp
operator|->
name|mfs_buflist
operator|=
name|bp
operator|->
name|av_forw
expr_stmt|;
name|mfs_doio
argument_list|(
name|bp
argument_list|,
name|mfsp
operator|->
name|mfs_baseoff
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|bp
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * On last close of a memory filesystem 	 * we must invalidate any in core blocks, so that 	 * we can, free up its vnode. 	 */
name|vflushbuf
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|vinvalbuf
argument_list|(
name|vp
argument_list|,
literal|1
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * There should be no way to have any more uses of this 	 * vnode, so if we find any other uses, it is a panic. 	 */
if|if
condition|(
name|vp
operator|->
name|v_usecount
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"mfs_close: ref count %d> 1\n"
argument_list|,
name|vp
operator|->
name|v_usecount
argument_list|)
expr_stmt|;
if|if
condition|(
name|vp
operator|->
name|v_usecount
operator|>
literal|1
operator|||
name|mfsp
operator|->
name|mfs_buflist
condition|)
name|panic
argument_list|(
literal|"mfs_close"
argument_list|)
expr_stmt|;
comment|/* 	 * Send a request to the filesystem server to exit. 	 */
name|mfsp
operator|->
name|mfs_buflist
operator|=
operator|(
expr|struct
name|buf
operator|*
operator|)
operator|(
operator|-
literal|1
operator|)
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|vp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Memory filesystem inactive routine  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|mfs_inactive
argument_list|(
argument|vp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|VTOMFS
argument_list|(
name|vp
argument_list|)
operator|->
name|mfs_buflist
operator|!=
operator|(
expr|struct
name|buf
operator|*
operator|)
operator|(
operator|-
literal|1
operator|)
condition|)
name|panic
argument_list|(
literal|"mfs_inactive: not inactive"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Print out the contents of an mfsnode.  */
end_comment

begin_macro
name|mfs_print
argument_list|(
argument|vp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|mfsnode
modifier|*
name|mfsp
init|=
name|VTOMFS
argument_list|(
name|vp
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"tag VT_MFS, pid %d, base %d, size %d\n"
argument_list|,
name|mfsp
operator|->
name|mfs_pid
argument_list|,
name|mfsp
operator|->
name|mfs_baseoff
argument_list|,
name|mfsp
operator|->
name|mfs_size
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Block device bad operation  */
end_comment

begin_macro
name|mfs_badop
argument_list|()
end_macro

begin_block
block|{
name|panic
argument_list|(
literal|"mfs_badop called\n"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_block

begin_comment
comment|/*  * Block device null operation  */
end_comment

begin_macro
name|mfs_nullop
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
comment|/*  * Memory based filesystem initialization.  */
end_comment

begin_macro
name|mfs_init
argument_list|()
end_macro

begin_block
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|hp300
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|i386
argument_list|)
name|rminit
argument_list|(
name|mfsmap
argument_list|,
operator|(
name|long
operator|)
name|MFS_MAPREG
argument_list|,
operator|(
name|long
operator|)
literal|1
argument_list|,
literal|"mfs mapreg"
argument_list|,
name|MFS_MAPSIZE
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

