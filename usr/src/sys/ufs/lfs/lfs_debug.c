begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lfs_debug.c	7.6 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
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
file|<ufs/lfs/lfs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/lfs/lfs_extern.h>
end_include

begin_function
name|void
name|lfs_dump_super
parameter_list|(
name|lfsp
parameter_list|)
name|struct
name|lfs
modifier|*
name|lfsp
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%lx\t%s%lx\t%s%d\t%s%d\n"
argument_list|,
literal|"magic    "
argument_list|,
name|lfsp
operator|->
name|lfs_magic
argument_list|,
literal|"version  "
argument_list|,
name|lfsp
operator|->
name|lfs_version
argument_list|,
literal|"size     "
argument_list|,
name|lfsp
operator|->
name|lfs_size
argument_list|,
literal|"ssize    "
argument_list|,
name|lfsp
operator|->
name|lfs_ssize
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%d\t%s%d\t%s%d\t%s%d\n"
argument_list|,
literal|"dsize    "
argument_list|,
name|lfsp
operator|->
name|lfs_dsize
argument_list|,
literal|"bsize    "
argument_list|,
name|lfsp
operator|->
name|lfs_bsize
argument_list|,
literal|"fsize    "
argument_list|,
name|lfsp
operator|->
name|lfs_fsize
argument_list|,
literal|"frag     "
argument_list|,
name|lfsp
operator|->
name|lfs_frag
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%d\t%s%d\t%s%d\t%s%d\n"
argument_list|,
literal|"minfree  "
argument_list|,
name|lfsp
operator|->
name|lfs_minfree
argument_list|,
literal|"inopb    "
argument_list|,
name|lfsp
operator|->
name|lfs_inopb
argument_list|,
literal|"ifpb     "
argument_list|,
name|lfsp
operator|->
name|lfs_ifpb
argument_list|,
literal|"nindir   "
argument_list|,
name|lfsp
operator|->
name|lfs_nindir
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%d\t%s%d\t%s%d\n"
argument_list|,
literal|"nseg     "
argument_list|,
name|lfsp
operator|->
name|lfs_nseg
argument_list|,
literal|"nspf     "
argument_list|,
name|lfsp
operator|->
name|lfs_nspf
argument_list|,
literal|"segtabsz "
argument_list|,
name|lfsp
operator|->
name|lfs_segtabsz
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%lx\t%s%d\t%s%lx\t%s%d\n"
argument_list|,
literal|"segmask  "
argument_list|,
name|lfsp
operator|->
name|lfs_segmask
argument_list|,
literal|"segshift "
argument_list|,
name|lfsp
operator|->
name|lfs_segshift
argument_list|,
literal|"bmask    "
argument_list|,
name|lfsp
operator|->
name|lfs_bmask
argument_list|,
literal|"bshift   "
argument_list|,
name|lfsp
operator|->
name|lfs_bshift
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%lx\t%s%d\t%s%lx\t%s%d\n"
argument_list|,
literal|"ffmask   "
argument_list|,
name|lfsp
operator|->
name|lfs_ffmask
argument_list|,
literal|"ffshift  "
argument_list|,
name|lfsp
operator|->
name|lfs_ffshift
argument_list|,
literal|"fbmask   "
argument_list|,
name|lfsp
operator|->
name|lfs_fbmask
argument_list|,
literal|"fbshift  "
argument_list|,
name|lfsp
operator|->
name|lfs_fbshift
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%d\t%s%lx\n"
argument_list|,
literal|"fsbtodb  "
argument_list|,
name|lfsp
operator|->
name|lfs_fsbtodb
argument_list|,
literal|"cksum    "
argument_list|,
name|lfsp
operator|->
name|lfs_cksum
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"Superblock disk addresses:"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|LFS_MAXNUMSB
condition|;
name|i
operator|++
control|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|" %lx"
argument_list|,
name|lfsp
operator|->
name|lfs_sboffs
index|[
name|i
index|]
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"Checkpoint Info\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%d\t%s%lx\t%s%d\n"
argument_list|,
literal|"free     "
argument_list|,
name|lfsp
operator|->
name|lfs_free
argument_list|,
literal|"idaddr   "
argument_list|,
name|lfsp
operator|->
name|lfs_idaddr
argument_list|,
literal|"ifile    "
argument_list|,
name|lfsp
operator|->
name|lfs_ifile
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%lx\t%s%d\t%s%lx\t%s%lx\n"
argument_list|,
literal|"bfree    "
argument_list|,
name|lfsp
operator|->
name|lfs_bfree
argument_list|,
literal|"nfiles   "
argument_list|,
name|lfsp
operator|->
name|lfs_nfiles
argument_list|,
literal|"lastseg  "
argument_list|,
name|lfsp
operator|->
name|lfs_lastseg
argument_list|,
literal|"nextseg  "
argument_list|,
name|lfsp
operator|->
name|lfs_nextseg
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"tstamp   %lx\n"
argument_list|,
name|lfsp
operator|->
name|lfs_tstamp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|lfs_dump_dinode
parameter_list|(
name|dip
parameter_list|)
name|struct
name|dinode
modifier|*
name|dip
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%u\t%s%d\t%s%u\t%s%u\t%s%lu\n"
argument_list|,
literal|"mode  "
argument_list|,
name|dip
operator|->
name|di_mode
argument_list|,
literal|"nlink "
argument_list|,
name|dip
operator|->
name|di_nlink
argument_list|,
literal|"uid   "
argument_list|,
name|dip
operator|->
name|di_uid
argument_list|,
literal|"gid   "
argument_list|,
name|dip
operator|->
name|di_gid
argument_list|,
literal|"size  "
argument_list|,
name|dip
operator|->
name|di_size
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"inum  %ld\n"
argument_list|,
name|dip
operator|->
name|di_inum
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"Direct Addresses\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NDADDR
condition|;
name|i
operator|++
control|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\t%lx"
argument_list|,
name|dip
operator|->
name|di_db
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|%
literal|6
operator|)
operator|==
literal|5
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NIADDR
condition|;
name|i
operator|++
control|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\t%lx"
argument_list|,
name|dip
operator|->
name|di_ib
index|[
name|i
index|]
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

end_unit

