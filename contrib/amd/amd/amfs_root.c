begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amfs_root.c,v 1.2 1999/01/10 21:53:43 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * Root file system  */
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
comment|/****************************************************************************  *** FORWARD DEFINITIONS                                                  ***  ****************************************************************************/
end_comment

begin_function_decl
specifier|static
name|int
name|amfs_root_mount
parameter_list|(
name|am_node
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************************  *** OPS STRUCTURES                                                       ***  ****************************************************************************/
end_comment

begin_decl_stmt
name|am_ops
name|amfs_root_ops
init|=
block|{
literal|"root"
block|,
literal|0
block|,
comment|/* amfs_root_match */
literal|0
block|,
comment|/* amfs_root_init */
name|amfs_root_mount
block|,
literal|0
block|,
name|amfs_auto_umount
block|,
literal|0
block|,
name|amfs_auto_lookuppn
block|,
name|amfs_auto_readdir
block|,
literal|0
block|,
comment|/* amfs_root_readlink */
literal|0
block|,
comment|/* amfs_root_mounted */
literal|0
block|,
comment|/* amfs_root_umounted */
name|find_amfs_auto_srvr
block|,
name|FS_NOTIMEOUT
operator||
name|FS_AMQINFO
operator||
name|FS_DIRECTORY
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****************************************************************************  *** FUNCTIONS                                                             ***  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Mount the root...  */
end_comment

begin_function
specifier|static
name|int
name|amfs_root_mount
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
name|mf
operator|->
name|mf_mount
operator|=
name|strealloc
argument_list|(
name|mf
operator|->
name|mf_mount
argument_list|,
name|pid_fsname
argument_list|)
expr_stmt|;
name|mf
operator|->
name|mf_private
operator|=
operator|(
name|voidp
operator|)
name|mapc_find
argument_list|(
name|mf
operator|->
name|mf_info
argument_list|,
literal|""
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|mf
operator|->
name|mf_prfree
operator|=
name|mapc_free
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

