begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: ops_TEMPLATE.c,v 1.2 1999/01/10 21:53:48 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * An empty template for an amd pseudo filesystem "foofs".  */
end_comment

begin_comment
comment|/*  * NOTE: if this is an Amd file system, prepend "amfs_" to all foofs symbols  * and renamed the file name to amfs_foofs.c.  If it is a native file system  * (such as pcfs, isofs, or ffs), then you can keep the names as is, and  * just rename the file to ops_foofs.c.  */
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
name|char
modifier|*
name|foofs_match
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
name|foofs_init
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|foofs_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|foofs_fmount
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|foofs_umount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|foofs_fumount
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|am_node
modifier|*
name|foofs_lookuppn
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
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|foofs_readdir
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
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|am_node
modifier|*
name|foofs_readlink
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|foofs_mounted
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|foofs_umounted
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|fserver
modifier|*
name|foofs_ffserver
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Foofs operations.  * Define only those you need, others set to 0 (NULL)  */
end_comment

begin_decl_stmt
name|am_ops
name|foofs_ops
init|=
block|{
literal|"foofs"
block|,
comment|/* name of file system */
name|foofs_match
block|,
comment|/* match */
name|foofs_init
block|,
comment|/* initialize */
name|foofs_mount
block|,
comment|/* mount vnode */
name|foofs_fmount
block|,
comment|/* mount vfs */
name|foofs_umount
block|,
comment|/* unmount vnode */
name|foofs_fumount
block|,
comment|/* unmount VFS */
name|foofs_lookuppn
block|,
comment|/* lookup path-name */
name|foofs_readdir
block|,
comment|/* read directory */
name|foofs_readlink
block|,
comment|/* read link */
name|foofs_mounted
block|,
comment|/* after-mount extra actions */
name|foofs_umounted
block|,
comment|/* after-umount extra actions */
name|foofs_ffserver
block|,
comment|/* find a file server */
name|FS_MKMNT
operator||
name|FS_BACKGROUND
operator||
name|FS_AMQINFO
comment|/* flags */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Check that f/s has all needed fields.  * Returns: matched string if found, NULL otherwise.  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|foofs_match
parameter_list|(
name|am_opts
modifier|*
name|fo
parameter_list|)
block|{
name|char
modifier|*
name|cp
init|=
literal|"fill this with a way to find the match"
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_match..."
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
condition|)
return|return
name|cp
return|;
comment|/* OK */
return|return
name|NULL
return|;
comment|/* not OK */
block|}
end_function

begin_comment
comment|/*  * Initialize.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|foofs_init
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_init..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/*  * Mount vnode.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|foofs_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_mount..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/*  * Mount vfs.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|foofs_fmount
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_fmount..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/*  * Unmount vnode.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|foofs_umount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_umount..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/*  * Unmount VFS.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|foofs_fumount
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_fumount..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/*  * Lookup path-name.  * Returns: the am_node that was found, or NULL if failed.  * If failed, also fills in errno in error_return.  */
end_comment

begin_function
specifier|static
name|am_node
modifier|*
name|foofs_lookuppn
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
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_lookuppn..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
operator|*
name|error_return
operator|=
name|error
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/*  * Read directory.  * Returns: 0 if OK, non-zero (errno) if failed.  * If OK, fills in ep with chain of directory entries.  */
end_comment

begin_function
specifier|static
name|int
name|foofs_readdir
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
name|int
name|count
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_readdir..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
return|return
name|error
return|;
block|}
end_function

begin_comment
comment|/*  * Read link.  * Returns: am_node found, or NULL if not found.  * If failed, fills in errno in error_return.  */
end_comment

begin_function
specifier|static
name|am_node
modifier|*
name|foofs_readlink
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|,
name|int
modifier|*
name|error_return
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_readlink..."
argument_list|)
expr_stmt|;
name|error
operator|=
name|EPERM
expr_stmt|;
comment|/* XXX: fixme */
operator|*
name|error_return
operator|=
name|error
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/*  * Async mount callback function.  * After the base mount went OK, sometimes  * there are additional actions that are needed.  See union_mounted() and  * toplvl_mounted().  */
end_comment

begin_function
specifier|static
name|void
name|foofs_mounted
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_mounted..."
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Async unmount callback function.  * After the base umount() succeeds, we may want to take extra actions,  * such as informing remote mount daemons that we've unmounted them.  * See amfs_auto_umounted(), host_umounted(), nfs_umounted().  */
end_comment

begin_function
specifier|static
name|void
name|foofs_umounted
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_umounted..."
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Find a file server.  * Returns: fserver of found server, or NULL if not found.  */
end_comment

begin_function
name|fserver
modifier|*
name|foofs_ffserver
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"entering foofs_ffserver..."
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

end_unit

