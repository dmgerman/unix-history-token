begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/amd/amfs_error.c  *  */
end_comment

begin_comment
comment|/*  * Error file system.  * This is used as a last resort catchall if  * nothing else worked.  EFS just returns lots  * of error codes, except for unmount which  * always works of course.  */
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

begin_function_decl
specifier|static
name|char
modifier|*
name|amfs_error_match
parameter_list|(
name|am_opts
modifier|*
name|fo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|amfs_error_mount
parameter_list|(
name|am_node
modifier|*
name|am
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
name|amfs_error_umount
parameter_list|(
name|am_node
modifier|*
name|am
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Ops structure  */
end_comment

begin_decl_stmt
name|am_ops
name|amfs_error_ops
init|=
block|{
literal|"error"
block|,
name|amfs_error_match
block|,
literal|0
block|,
comment|/* amfs_error_init */
name|amfs_error_mount
block|,
name|amfs_error_umount
block|,
name|amfs_error_lookup_child
block|,
name|amfs_error_mount_child
block|,
name|amfs_error_readdir
block|,
literal|0
block|,
comment|/* amfs_error_readlink */
literal|0
block|,
comment|/* amfs_error_mounted */
literal|0
block|,
comment|/* amfs_error_umounted */
name|amfs_generic_find_srvr
block|,
literal|0
block|,
comment|/* amfs_error_get_wchan */
name|FS_DISCARD
block|,
comment|/* nfs_fs_flags */
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
name|AUTOFS_ERROR_FS_FLAGS
block|,
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * EFS file system always matches  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|amfs_error_match
parameter_list|(
name|am_opts
modifier|*
name|fo
parameter_list|)
block|{
return|return
name|strdup
argument_list|(
literal|"(error-hook)"
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|amfs_error_mount
parameter_list|(
name|am_node
modifier|*
name|am
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
return|return
name|ENOENT
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|amfs_error_umount
parameter_list|(
name|am_node
modifier|*
name|am
parameter_list|,
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
comment|/*    * Always succeed    */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * EFS interface to RPC lookup() routine.  * Should never get here in the automounter.  * If we do then just give an error.  */
end_comment

begin_function
name|am_node
modifier|*
name|amfs_error_lookup_child
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|,
name|int
name|op
parameter_list|)
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
comment|/*  * EFS interface to RPC lookup() routine.  * Should never get here in the automounter.  * If we do then just give an error.  */
end_comment

begin_function
name|am_node
modifier|*
name|amfs_error_mount_child
parameter_list|(
name|am_node
modifier|*
name|ap
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|)
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

begin_function
name|int
name|amfs_error_readdir
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|nfscookie
name|cookie
parameter_list|,
name|nfsdirlist
modifier|*
name|dp
parameter_list|,
name|nfsentry
modifier|*
name|ep
parameter_list|,
name|u_int
name|count
parameter_list|)
block|{
return|return
name|ESTALE
return|;
block|}
end_function

end_unit

