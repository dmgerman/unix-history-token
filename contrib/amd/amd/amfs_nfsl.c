begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amfs_nfsl.c,v 1.3 1999/01/10 21:53:42 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * NFSL: Network file system with local existence check.  If the local  * path denoted by $rfs exists, it behaves as type:=link.  *  * Example:  *	pkg	type:=nfsl;rhost:=jonny;rfs:=/n/johnny/src/pkg;fs:=${rfs}  */
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
name|amfs_nfsl_match
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
name|amfs_nfsl_init
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
name|amfs_nfsl_fmount
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
name|amfs_nfsl_fumount
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
name|amfs_nfsl_umounted
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|fserver
modifier|*
name|amfs_nfsl_ffserver
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NFS-Link operations  */
end_comment

begin_decl_stmt
name|am_ops
name|amfs_nfsl_ops
init|=
block|{
literal|"nfsl"
block|,
comment|/* name of file system */
name|amfs_nfsl_match
block|,
comment|/* match */
name|amfs_nfsl_init
block|,
comment|/* initialize */
name|amfs_auto_fmount
block|,
comment|/* mount vnode */
name|amfs_nfsl_fmount
block|,
comment|/* mount vfs */
name|amfs_auto_fumount
block|,
comment|/* unmount vnode */
name|amfs_nfsl_fumount
block|,
comment|/* unmount VFS */
name|amfs_error_lookuppn
block|,
comment|/* lookup path-name */
name|amfs_error_readdir
block|,
comment|/* read directory */
literal|0
block|,
comment|/* read link */
literal|0
block|,
comment|/* after-mount extra actions */
name|amfs_nfsl_umounted
block|,
comment|/* after-umount extra actions */
name|amfs_nfsl_ffserver
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
name|amfs_nfsl_match
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
name|fo
operator|->
name|opt_fs
decl_stmt|;
name|char
modifier|*
name|ho
init|=
name|fo
operator|->
name|opt_rhost
decl_stmt|;
name|struct
name|stat
name|stb
decl_stmt|;
if|if
condition|(
operator|!
name|cp
operator|||
operator|!
name|ho
condition|)
block|{
name|plog
argument_list|(
name|XLOG_USER
argument_list|,
literal|"amfs_nfsl: host $fs and $rhost must be specified"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/*    * If this host is not the same as $rhost, or if link does not exist,    * perform nfs_match(), same as for type:=nfs.    * If link value exists (or same host), then perform amfs_link_match(),    * same as for linkx.    */
if|if
condition|(
operator|!
name|STRCEQ
argument_list|(
name|ho
argument_list|,
name|am_get_hostname
argument_list|()
argument_list|)
condition|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"amfs_nfsl: \"%s\" is not local host, using type:=nfs"
argument_list|,
name|ho
argument_list|)
expr_stmt|;
return|return
name|nfs_match
argument_list|(
name|fo
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|lstat
argument_list|(
name|cp
argument_list|,
operator|&
name|stb
argument_list|)
operator|<
literal|0
condition|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"amfs_nfsl: \"%s\" does not exist, using type:=nfs"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
return|return
name|nfs_match
argument_list|(
name|fo
argument_list|)
return|;
block|}
else|else
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"amfs_nfsl: \"%s\" exists, using type:=link"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
return|return
name|amfs_link_match
argument_list|(
name|fo
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Initialize.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|amfs_nfsl_init
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
comment|/*    * If a link, do nothing (same as type:=link).    * If non-link, do nfs_init (same as type:=nfs).    */
if|if
condition|(
name|mf
operator|->
name|mf_flags
operator|&
name|MFF_NFSLINK
condition|)
block|{
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
name|nfs_init
argument_list|(
name|mf
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Mount vfs.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|amfs_nfsl_fmount
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
comment|/*    * If a link, do run amfs_link_fmount() (same as type:=link)    * If non-link, do nfs_fmount (same as type:=nfs).    */
if|if
condition|(
name|mf
operator|->
name|mf_flags
operator|&
name|MFF_NFSLINK
condition|)
block|{
return|return
name|amfs_link_fmount
argument_list|(
name|mf
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|nfs_fmount
argument_list|(
name|mf
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Unmount VFS.  * Returns: 0 if OK, non-zero (errno) if failed.  */
end_comment

begin_function
specifier|static
name|int
name|amfs_nfsl_fumount
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
comment|/*    * If a link, do run amfs_link_fumount() (same as type:=link)    * If non-link, do nfs_fumount (same as type:=nfs).    */
if|if
condition|(
name|mf
operator|->
name|mf_flags
operator|&
name|MFF_NFSLINK
condition|)
block|{
return|return
name|amfs_link_fumount
argument_list|(
name|mf
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|nfs_fumount
argument_list|(
name|mf
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Async unmount callback function.  * After the base umount() succeeds, we may want to take extra actions,  * such as informing remote mount daemons that we've unmounted them.  * See amfs_auto_umounted(), host_umounted(), nfs_umounted().  */
end_comment

begin_function
specifier|static
name|void
name|amfs_nfsl_umounted
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
block|{
name|mntfs
modifier|*
name|mf
init|=
name|mp
operator|->
name|am_mnt
decl_stmt|;
comment|/*    * If a link, do nothing (same as type:=link)    * If non-link, do nfs_fumount (same as type:=nfs).    */
if|if
condition|(
name|mf
operator|->
name|mf_flags
operator|&
name|MFF_NFSLINK
condition|)
block|{
return|return;
block|}
else|else
block|{
name|nfs_umounted
argument_list|(
name|mp
argument_list|)
expr_stmt|;
comment|/*      * MUST remove mount point directories, because if they remain      * behind, the next nfsl access will think they are a link      * type file system, and not NFS! (when it performs link target      * existence test)      */
if|if
condition|(
name|mf
operator|->
name|mf_flags
operator|&
name|MFF_MKMNT
condition|)
name|rmdirs
argument_list|(
name|mf
operator|->
name|mf_mount
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_function

begin_comment
comment|/*  * Find a file server.  * Returns: fserver of found server, or NULL if not found.  */
end_comment

begin_function
specifier|static
name|fserver
modifier|*
name|amfs_nfsl_ffserver
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|char
modifier|*
name|cp
init|=
name|mf
operator|->
name|mf_fo
operator|->
name|opt_fs
decl_stmt|;
name|char
modifier|*
name|ho
init|=
name|mf
operator|->
name|mf_fo
operator|->
name|opt_rhost
decl_stmt|;
name|struct
name|stat
name|stb
decl_stmt|;
comment|/*    * If this host is not the same as $rhost, or if link does not exist,    * perform find_nfs_srvr(), same as for type:=nfs.    * If link value exists (or same host), then perform    * find_amfs_auto_srvr(), same as for linkx.    */
if|if
condition|(
operator|!
name|STRCEQ
argument_list|(
name|ho
argument_list|,
name|am_get_hostname
argument_list|()
argument_list|)
operator|||
name|lstat
argument_list|(
name|cp
argument_list|,
operator|&
name|stb
argument_list|)
operator|<
literal|0
condition|)
block|{
return|return
name|find_nfs_srvr
argument_list|(
name|mf
argument_list|)
return|;
block|}
else|else
block|{
name|mf
operator|->
name|mf_flags
operator||=
name|MFF_NFSLINK
expr_stmt|;
return|return
name|find_amfs_auto_srvr
argument_list|(
name|mf
argument_list|)
return|;
block|}
block|}
end_function

end_unit

