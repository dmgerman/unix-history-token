begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sfs_ops.c	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|"am.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_SFS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAS_SFSX
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEED_SFS_MATCH
end_define

begin_define
define|#
directive|define
name|NEED_SFS_UMOUNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Symbol-link file system  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SFSX
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SFS_MATCH
end_ifdef

begin_comment
comment|/*  * SFS needs a link.  */
end_comment

begin_function
specifier|static
name|char
modifier|*
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
name|fo
operator|->
name|opt_fs
operator|=
name|str3cat
argument_list|(
name|fo
operator|->
name|opt_fs
argument_list|,
literal|"."
argument_list|,
name|fullpath
argument_list|,
literal|""
argument_list|)
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SFSX
end_ifdef

begin_comment
comment|/*ARGUSED*/
end_comment

begin_decl_stmt
specifier|static
name|int
name|sfsx_mount
name|P
argument_list|(
operator|(
name|am_node
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|sfsx_mount
parameter_list|(
name|mp
parameter_list|)
name|am_node
modifier|*
name|mp
decl_stmt|;
block|{
comment|/* 	 * Check for existence of target. 	 */
name|struct
name|stat
name|stb
decl_stmt|;
name|char
modifier|*
name|ln
decl_stmt|;
if|if
condition|(
name|mp
operator|->
name|am_link
condition|)
name|ln
operator|=
name|mp
operator|->
name|am_link
expr_stmt|;
else|else
comment|/* should never occur */
name|ln
operator|=
name|mp
operator|->
name|am_mnt
operator|->
name|mf_mount
expr_stmt|;
comment|/* 	 * Use lstat, not stat, since we don't 	 * want to know if the ultimate target of 	 * a symlink chain exists, just the first. 	 */
if|if
condition|(
name|lstat
argument_list|(
name|ln
argument_list|,
operator|&
name|stb
argument_list|)
operator|<
literal|0
condition|)
return|return
name|errno
return|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SFS
end_ifdef

begin_comment
comment|/*ARGUSED*/
end_comment

begin_function
specifier|static
name|int
name|sfs_fmount
parameter_list|(
name|mf
parameter_list|)
name|mntfs
modifier|*
name|mf
decl_stmt|;
block|{
comment|/* 	 * Wow - this is hard to implement! 	 */
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SFS_UMOUNT
end_ifdef

begin_comment
comment|/*ARGUSED*/
end_comment

begin_function
specifier|static
name|int
name|sfs_fumount
parameter_list|(
name|mf
parameter_list|)
name|mntfs
modifier|*
name|mf
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ops structures  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SFS
end_ifdef

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
name|auto_fmount
block|,
name|sfs_fmount
block|,
name|auto_fumount
block|,
name|sfs_fumount
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SFSX
end_ifdef

begin_decl_stmt
name|struct
name|am_ops
name|sfsx_ops
init|=
block|{
literal|"linkx"
block|,
name|sfs_match
block|,
literal|0
block|,
comment|/* sfsx_init */
name|sfsx_mount
block|,
literal|0
block|,
name|auto_fumount
block|,
name|sfs_fumount
block|,
name|efs_lookuppn
block|,
name|efs_readdir
block|,
literal|0
block|,
comment|/* sfsx_readlink */
literal|0
block|,
comment|/* sfsx_mounted */
literal|0
block|,
comment|/* sfsx_umounted */
name|find_afs_srvr
block|,
ifdef|#
directive|ifdef
name|FLUSH_KERNEL_NAME_CACHE
name|FS_BACKGROUND
else|#
directive|else
comment|/* FLUSH_KERNEL_NAME_CACHE */
name|FS_MBACKGROUND
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
comment|/* HAS_SFSX */
end_comment

end_unit

