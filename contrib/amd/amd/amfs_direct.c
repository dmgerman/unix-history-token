begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amfs_direct.c,v 1.2 1999/01/10 21:53:41 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * Direct file system  */
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
name|am_node
modifier|*
name|amfs_direct_readlink
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

begin_comment
comment|/****************************************************************************  *** OPS STRUCTURES                                                       ***  ****************************************************************************/
end_comment

begin_decl_stmt
name|am_ops
name|amfs_direct_ops
init|=
block|{
literal|"direct"
block|,
name|amfs_auto_match
block|,
literal|0
block|,
comment|/* amfs_direct_init */
name|amfs_toplvl_mount
block|,
literal|0
block|,
name|amfs_toplvl_umount
block|,
literal|0
block|,
name|amfs_error_lookuppn
block|,
name|amfs_error_readdir
block|,
name|amfs_direct_readlink
block|,
name|amfs_toplvl_mounted
block|,
literal|0
block|,
comment|/* amfs_auto_umounted */
name|find_amfs_auto_srvr
block|,
name|FS_MKMNT
operator||
name|FS_NOTIMEOUT
operator||
name|FS_BACKGROUND
operator||
name|FS_AMQINFO
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****************************************************************************  *** FUNCTIONS                                                             ***  ****************************************************************************/
end_comment

begin_function
specifier|static
name|am_node
modifier|*
name|amfs_direct_readlink
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
name|am_node
modifier|*
name|xp
decl_stmt|;
name|int
name|rc
init|=
literal|0
decl_stmt|;
name|xp
operator|=
name|next_nonerror_node
argument_list|(
name|mp
operator|->
name|am_child
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|xp
condition|)
block|{
if|if
condition|(
operator|!
name|mp
operator|->
name|am_mnt
operator|->
name|mf_private
condition|)
name|amfs_auto_mkcacheref
argument_list|(
name|mp
operator|->
name|am_mnt
argument_list|)
expr_stmt|;
comment|/* XXX */
name|xp
operator|=
name|amfs_auto_lookuppn
argument_list|(
name|mp
argument_list|,
name|mp
operator|->
name|am_path
operator|+
literal|1
argument_list|,
operator|&
name|rc
argument_list|,
name|VLOOK_CREATE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|xp
condition|)
block|{
name|new_ttl
argument_list|(
name|xp
argument_list|)
expr_stmt|;
comment|/* (7/12/89) from Rein Tollevik */
return|return
name|xp
return|;
block|}
if|if
condition|(
name|amd_state
operator|==
name|Finishing
condition|)
name|rc
operator|=
name|ENOENT
expr_stmt|;
operator|*
name|error_return
operator|=
name|rc
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

