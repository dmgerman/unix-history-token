begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amfs_union.c,v 1.2 1999/01/10 21:53:43 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * Union automounter file system  */
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
name|void
name|amfs_union_mounted
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************************  *** OPS STRUCTURES                                                       ***  ****************************************************************************/
end_comment

begin_decl_stmt
name|am_ops
name|amfs_union_ops
init|=
block|{
literal|"union"
block|,
name|amfs_auto_match
block|,
literal|0
block|,
comment|/* amfs_auto_init */
name|amfs_toplvl_mount
block|,
literal|0
block|,
name|amfs_toplvl_umount
block|,
literal|0
block|,
name|amfs_auto_lookuppn
block|,
name|amfs_auto_readdir
block|,
literal|0
block|,
comment|/* amfs_toplvl_readlink */
name|amfs_union_mounted
block|,
literal|0
block|,
comment|/* amfs_toplvl_umounted */
name|find_amfs_auto_srvr
block|,
name|FS_MKMNT
operator||
name|FS_NOTIMEOUT
operator||
name|FS_BACKGROUND
operator||
name|FS_AMQINFO
operator||
name|FS_DIRECTORY
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Create a reference to a union'ed entry  * XXX: this function may not be used anywhere...  */
end_comment

begin_function
specifier|static
name|int
name|create_amfs_union_node
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|voidp
name|arg
parameter_list|)
block|{
if|if
condition|(
operator|!
name|STREQ
argument_list|(
name|dir
argument_list|,
literal|"/defaults"
argument_list|)
condition|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
operator|(
name|void
operator|)
name|amfs_toplvl_ops
operator|.
name|lookuppn
argument_list|(
name|arg
argument_list|,
name|dir
argument_list|,
operator|&
name|error
argument_list|,
name|VLOOK_CREATE
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|>
literal|0
condition|)
block|{
name|errno
operator|=
name|error
expr_stmt|;
comment|/* XXX */
name|plog
argument_list|(
name|XLOG_ERROR
argument_list|,
literal|"Could not mount %s: %m"
argument_list|,
name|dir
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|amfs_union_mounted
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|amfs_auto_mkcacheref
argument_list|(
name|mf
argument_list|)
expr_stmt|;
comment|/*    * Having made the union mount point,    * populate all the entries...    */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|last_used_map
condition|;
name|i
operator|++
control|)
block|{
name|am_node
modifier|*
name|mp
init|=
name|exported_ap
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|mp
operator|&&
name|mp
operator|->
name|am_mnt
operator|==
name|mf
condition|)
block|{
comment|/* return value from create_amfs_union_node is ignored by mapc_keyiter */
operator|(
name|void
operator|)
name|mapc_keyiter
argument_list|(
operator|(
name|mnt_map
operator|*
operator|)
name|mp
operator|->
name|am_mnt
operator|->
name|mf_private
argument_list|,
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|,
name|voidp
argument_list|)
operator|)
name|create_amfs_union_node
argument_list|,
name|mp
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

end_unit

