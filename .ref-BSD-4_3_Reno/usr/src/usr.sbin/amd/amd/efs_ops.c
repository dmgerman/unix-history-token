begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: efs_ops.c,v 5.2 90/06/23 22:19:23 jsp Rel $  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)efs_ops.c	5.1 (Berkeley) 6/29/90  */
end_comment

begin_include
include|#
directive|include
file|"am.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_EFS
end_ifdef

begin_comment
comment|/*  * Error file system.  * This is used as a last resort catchall if  * nothing else worked.  EFS just returns lots  * of error codes, except for unmount which  * always works of course.  */
end_comment

begin_comment
comment|/*  * EFS file system always matches  */
end_comment

begin_function
specifier|static
name|int
name|efs_match
parameter_list|(
name|fo
parameter_list|)
name|am_opts
modifier|*
name|fo
decl_stmt|;
block|{
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
literal|"(error-hook)"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|int
name|efs_mount
parameter_list|(
name|mp
parameter_list|)
name|am_node
modifier|*
name|mp
decl_stmt|;
block|{
return|return
name|ENOENT
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|int
name|efs_umount
parameter_list|(
name|mp
parameter_list|)
name|am_node
modifier|*
name|mp
decl_stmt|;
block|{
comment|/* 	 * Always succeed 	 */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * EFS interface to RPC lookup() routine.  * Should never get here in the automounter.  * If we do then just give an error.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|am_node
modifier|*
name|efs_lookuppn
parameter_list|(
name|mp
parameter_list|,
name|fname
parameter_list|,
name|error_return
parameter_list|,
name|op
parameter_list|)
name|am_node
modifier|*
name|mp
decl_stmt|;
name|char
modifier|*
name|fname
decl_stmt|;
name|int
modifier|*
name|error_return
decl_stmt|;
name|int
name|op
decl_stmt|;
block|{
operator|*
name|error_return
operator|=
name|ESTALE
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * EFS interface to RPC readdir() routine.  * Should never get here in the automounter.  * If we do then just give an error.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|efs_readdir
parameter_list|(
name|mp
parameter_list|,
name|cookie
parameter_list|,
name|dp
parameter_list|,
name|ep
parameter_list|)
name|am_node
modifier|*
name|mp
decl_stmt|;
name|nfscookie
name|cookie
decl_stmt|;
name|dirlist
modifier|*
name|dp
decl_stmt|;
name|entry
modifier|*
name|ep
decl_stmt|;
block|{
return|return
name|ESTALE
return|;
block|}
end_function

begin_comment
comment|/*  * Ops structure  */
end_comment

begin_decl_stmt
name|am_ops
name|efs_ops
init|=
block|{
literal|"error"
block|,
name|efs_match
block|,
literal|0
block|,
comment|/* efs_init */
name|efs_mount
block|,
name|efs_umount
block|,
name|efs_lookuppn
block|,
name|efs_readdir
block|,
literal|0
block|,
comment|/* efs_readlink */
literal|0
block|,
comment|/* efs_mounted */
literal|0
block|,
comment|/* efs_umounted */
name|find_afs_srvr
block|,
name|FS_DISCARD
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_EFS */
end_comment

end_unit

