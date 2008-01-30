begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/amd/amfs_union.c  *  */
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
name|int
name|create_amfs_union_node
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|opaque_t
name|arg
parameter_list|)
function_decl|;
end_function_decl

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
name|amfs_generic_match
block|,
literal|0
block|,
comment|/* amfs_union_init */
name|amfs_toplvl_mount
block|,
name|amfs_toplvl_umount
block|,
name|amfs_generic_lookup_child
block|,
name|amfs_generic_mount_child
block|,
name|amfs_generic_readdir
block|,
literal|0
block|,
comment|/* amfs_union_readlink */
name|amfs_union_mounted
block|,
literal|0
block|,
comment|/* amfs_union_umounted */
name|amfs_generic_find_srvr
block|,
literal|0
block|,
comment|/* amfs_union_get_wchan */
name|FS_MKMNT
operator||
name|FS_NOTIMEOUT
operator||
name|FS_BACKGROUND
operator||
name|FS_AMQINFO
operator||
name|FS_DIRECTORY
block|,
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
name|AUTOFS_UNION_FS_FLAGS
block|,
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
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
name|opaque_t
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
name|am_node
modifier|*
name|am
decl_stmt|;
name|am
operator|=
name|amfs_generic_lookup_child
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
name|am
operator|&&
name|error
operator|<
literal|0
condition|)
name|am
operator|=
name|amfs_generic_mount_child
argument_list|(
name|am
argument_list|,
operator|&
name|error
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
literal|"unionfs: could not mount %s: %m"
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
name|index
decl_stmt|;
name|am_node
modifier|*
name|mp
decl_stmt|;
name|amfs_mkcacheref
argument_list|(
name|mf
argument_list|)
expr_stmt|;
comment|/*    * Having made the union mount point,    * populate all the entries...    */
for|for
control|(
name|mp
operator|=
name|get_first_exported_ap
argument_list|(
operator|&
name|index
argument_list|)
init|;
name|mp
condition|;
name|mp
operator|=
name|get_next_exported_ap
argument_list|(
operator|&
name|index
argument_list|)
control|)
block|{
if|if
condition|(
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

