begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amfs_linkx.c,v 1.2 1999/01/10 21:53:42 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * Symbol-link file system, with test that the target of the link exists.  */
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
name|amfs_linkx_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * linkx operations  */
end_comment

begin_decl_stmt
name|struct
name|am_ops
name|amfs_linkx_ops
init|=
block|{
literal|"linkx"
block|,
name|amfs_link_match
block|,
literal|0
block|,
comment|/* amfs_linkx_init */
name|amfs_linkx_mount
block|,
literal|0
block|,
name|amfs_auto_fumount
block|,
name|amfs_link_fumount
block|,
name|amfs_error_lookuppn
block|,
name|amfs_error_readdir
block|,
literal|0
block|,
comment|/* amfs_linkx_readlink */
literal|0
block|,
comment|/* amfs_linkx_mounted */
literal|0
block|,
comment|/* amfs_linkx_umounted */
name|find_amfs_auto_srvr
block|,
name|FS_MBACKGROUND
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|amfs_linkx_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
block|{
comment|/*    * Check for existence of target.    */
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
comment|/*    * Use lstat, not stat, since we don't    * want to know if the ultimate target of    * a symlink chain exists, just the first.    */
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

end_unit

