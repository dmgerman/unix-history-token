begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: sfs_ops.c,v 5.2 90/06/23 22:19:59 jsp Rel $  *  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)sfs_ops.c	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"am.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SFS
end_ifdef

begin_comment
comment|/*  * Symbol-link file system  */
end_comment

begin_comment
comment|/*  * SFS needs a link.  */
end_comment

begin_function
specifier|static
name|int
name|sfs_match
parameter_list|(
name|fo
parameter_list|)
name|am_opts
modifier|*
name|fo
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|fo
operator|->
name|opt_fs
condition|)
block|{
name|plog
argument_list|(
name|XLOG_USER
argument_list|,
literal|"link: no fs specified"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* 	 * Bug report (14/12/89) from Jay Plett<jay@princeton.edu> 	 * If an automount point has the same name as an existing 	 * link type mount Amd hits a race condition and either hangs 	 * or causes a symlink loop. 	 * 	 * If fs begins with a '/' change the opt_fs& opt_sublink 	 * fields so that the fs option doesn't end up pointing at 	 * an existing symlink. 	 * 	 * If sublink is nil then set sublink to fs 	 * else set sublink to fs / sublink 	 * 	 * Finally set fs to ".". 	 */
if|if
condition|(
operator|*
name|fo
operator|->
name|opt_fs
operator|==
literal|'/'
condition|)
block|{
name|char
modifier|*
name|fullpath
decl_stmt|;
name|char
modifier|*
name|link
init|=
name|fo
operator|->
name|opt_sublink
decl_stmt|;
if|if
condition|(
name|link
condition|)
block|{
if|if
condition|(
operator|*
name|link
operator|==
literal|'/'
condition|)
name|fullpath
operator|=
name|strdup
argument_list|(
name|link
argument_list|)
expr_stmt|;
else|else
name|fullpath
operator|=
name|str3cat
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|fo
operator|->
name|opt_fs
argument_list|,
literal|"/"
argument_list|,
name|link
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fullpath
operator|=
name|strdup
argument_list|(
name|fo
operator|->
name|opt_fs
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fo
operator|->
name|opt_sublink
condition|)
name|free
argument_list|(
name|fo
operator|->
name|opt_sublink
argument_list|)
expr_stmt|;
name|fo
operator|->
name|opt_sublink
operator|=
name|fullpath
expr_stmt|;
name|free
argument_list|(
name|fo
operator|->
name|opt_fs
argument_list|)
expr_stmt|;
name|fo
operator|->
name|opt_fs
operator|=
name|strdup
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
block|}
name|fo
operator|->
name|fs_mtab
operator|=
name|strealloc
argument_list|(
name|fo
operator|->
name|fs_mtab
argument_list|,
name|fo
operator|->
name|opt_fs
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*ARGUSED*/
end_comment

begin_function
specifier|static
name|int
name|sfs_mount
parameter_list|(
name|mp
parameter_list|)
name|am_node
modifier|*
name|mp
decl_stmt|;
block|{
comment|/* 	 * Wow - this is hard to implement! 	 */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*ARGUSED*/
end_comment

begin_function
specifier|static
name|int
name|sfs_umount
parameter_list|(
name|mp
parameter_list|)
name|am_node
modifier|*
name|mp
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Ops structure  */
end_comment

begin_decl_stmt
name|am_ops
name|sfs_ops
init|=
block|{
literal|"link"
block|,
name|sfs_match
block|,
literal|0
block|,
comment|/* sfs_init */
name|sfs_mount
block|,
name|sfs_umount
block|,
name|efs_lookuppn
block|,
name|efs_readdir
block|,
literal|0
block|,
comment|/* sfs_readlink */
literal|0
block|,
comment|/* sfs_mounted */
literal|0
block|,
comment|/* sfs_umounted */
name|find_afs_srvr
block|,
ifdef|#
directive|ifdef
name|FLUSH_KERNEL_NAME_CACHE
name|FS_UBACKGROUND
else|#
directive|else
comment|/* FLUSH_KERNEL_NAME_CACHE */
literal|0
endif|#
directive|endif
comment|/* FLUSH_KERNEL_NAME_CACHE */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_SFS */
end_comment

end_unit

