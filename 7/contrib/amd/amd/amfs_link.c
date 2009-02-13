begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/amd/amfs_link.c  *  */
end_comment

begin_comment
comment|/*  * Symbol-link file system  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amd.h>
end_include

begin_comment
comment|/* forward declarations */
end_comment

begin_function_decl
specifier|static
name|int
name|amfs_link_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|amfs_link_umount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Ops structures  */
end_comment

begin_decl_stmt
name|am_ops
name|amfs_link_ops
init|=
block|{
literal|"link"
block|,
name|amfs_link_match
block|,
literal|0
block|,
comment|/* amfs_link_init */
name|amfs_link_mount
block|,
name|amfs_link_umount
block|,
name|amfs_error_lookup_child
block|,
name|amfs_error_mount_child
block|,
name|amfs_error_readdir
block|,
literal|0
block|,
comment|/* amfs_link_readlink */
literal|0
block|,
comment|/* amfs_link_mounted */
literal|0
block|,
comment|/* amfs_link_umounted */
name|amfs_generic_find_srvr
block|,
literal|0
block|,
comment|/* nfs_fs_flags */
literal|0
block|,
comment|/* amfs_link_get_wchan */
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
name|AUTOFS_LINK_FS_FLAGS
block|,
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * SFS needs a link.  */
end_comment

begin_function
name|char
modifier|*
name|amfs_link_match
parameter_list|(
name|am_opts
modifier|*
name|fo
parameter_list|)
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
comment|/*    * If the link target points to another mount point, then we could    * end up with an unpleasant situation, where the link f/s simply    * "assumes" the mntfs of that mount point.    *    * For example, if the link points to /usr, and /usr is a real ufs    * filesystem, then the link f/s will use the inherited ufs mntfs,    * and the end result will be that it will become unmountable.    *    * To prevent this, we use a hack: we prepend a dot ('.') to opt_fs if    * its original value was an absolute path, so that it will never match    * any other mntfs.    *    * XXX: a less hacky solution should be used...    */
if|if
condition|(
name|fo
operator|->
name|opt_fs
index|[
literal|0
index|]
operator|==
literal|'/'
condition|)
block|{
name|char
modifier|*
name|link_hack
init|=
name|str3cat
argument_list|(
name|NULL
argument_list|,
literal|"."
argument_list|,
name|fo
operator|->
name|opt_fs
argument_list|,
literal|""
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fo
operator|->
name|opt_sublink
condition|)
name|fo
operator|->
name|opt_sublink
operator|=
name|strdup
argument_list|(
name|fo
operator|->
name|opt_fs
argument_list|)
expr_stmt|;
name|XFREE
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
name|link_hack
expr_stmt|;
block|}
return|return
name|strdup
argument_list|(
name|fo
operator|->
name|opt_fs
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|amfs_link_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|amfs_link_umount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

