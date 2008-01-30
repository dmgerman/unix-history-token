begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2006 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/amd/amfs_auto.c  *  */
end_comment

begin_comment
comment|/*  * Automount file system  */
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
comment|/****************************************************************************  *** MACROS                                                               ***  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *** STRUCTURES                                                           ***  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *** FORWARD DEFINITIONS                                                  ***  ****************************************************************************/
end_comment

begin_function_decl
specifier|static
name|int
name|amfs_auto_mount
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
comment|/****************************************************************************  *** OPS STRUCTURES                                                       ***  ****************************************************************************/
end_comment

begin_decl_stmt
name|am_ops
name|amfs_auto_ops
init|=
block|{
literal|"auto"
block|,
name|amfs_generic_match
block|,
literal|0
block|,
comment|/* amfs_auto_init */
name|amfs_auto_mount
block|,
name|amfs_generic_umount
block|,
name|amfs_generic_lookup_child
block|,
name|amfs_generic_mount_child
block|,
name|amfs_generic_readdir
block|,
literal|0
block|,
comment|/* amfs_auto_readlink */
name|amfs_generic_mounted
block|,
literal|0
block|,
comment|/* amfs_auto_umounted */
name|amfs_generic_find_srvr
block|,
literal|0
block|,
comment|/* amfs_auto_get_wchan */
name|FS_AMQINFO
operator||
name|FS_DIRECTORY
block|,
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
name|AUTOFS_AUTO_FS_FLAGS
block|,
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****************************************************************************  *** FUNCTIONS                                                             ***  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Mount a sub-mount  */
end_comment

begin_function
specifier|static
name|int
name|amfs_auto_mount
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
comment|/*    * Pseudo-directories are used to provide some structure    * to the automounted directories instead    * of putting them all in the top-level automount directory.    *    * Here, just increment the parent's link count.    */
name|mp
operator|->
name|am_parent
operator|->
name|am_fattr
operator|.
name|na_nlink
operator|++
expr_stmt|;
comment|/*    * Info field of . means use parent's info field.    * Historical - not documented.    */
if|if
condition|(
name|mf
operator|->
name|mf_info
index|[
literal|0
index|]
operator|==
literal|'.'
operator|&&
name|mf
operator|->
name|mf_info
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
name|mf
operator|->
name|mf_info
operator|=
name|strealloc
argument_list|(
name|mf
operator|->
name|mf_info
argument_list|,
name|mp
operator|->
name|am_parent
operator|->
name|am_mnt
operator|->
name|mf_info
argument_list|)
expr_stmt|;
comment|/*    * Compute prefix:    *    * If there is an option prefix then use that else    * If the parent had a prefix then use that with name    *      of this node appended else    * Use the name of this node.    *    * That means if you want no prefix you must say so    * in the map.    */
if|if
condition|(
name|mf
operator|->
name|mf_fo
operator|->
name|opt_pref
condition|)
block|{
comment|/* allow pref:=null to set a real null prefix */
if|if
condition|(
name|STREQ
argument_list|(
name|mf
operator|->
name|mf_fo
operator|->
name|opt_pref
argument_list|,
literal|"null"
argument_list|)
condition|)
block|{
name|mp
operator|->
name|am_pref
operator|=
name|strdup
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/*        * the prefix specified as an option        */
name|mp
operator|->
name|am_pref
operator|=
name|strdup
argument_list|(
name|mf
operator|->
name|mf_fo
operator|->
name|opt_pref
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/*      * else the parent's prefix      * followed by the name      * followed by /      */
name|char
modifier|*
name|ppref
init|=
name|mp
operator|->
name|am_parent
operator|->
name|am_pref
decl_stmt|;
if|if
condition|(
name|ppref
operator|==
literal|0
condition|)
name|ppref
operator|=
literal|""
expr_stmt|;
name|mp
operator|->
name|am_pref
operator|=
name|str3cat
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|ppref
argument_list|,
name|mp
operator|->
name|am_name
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
if|if
condition|(
name|mf
operator|->
name|mf_flags
operator|&
name|MFF_IS_AUTOFS
condition|)
block|{
name|char
name|opts
index|[
name|SIZEOF_OPTS
index|]
decl_stmt|;
name|int
name|error
decl_stmt|;
name|autofs_get_opts
argument_list|(
name|opts
argument_list|,
sizeof|sizeof
argument_list|(
name|opts
argument_list|)
argument_list|,
name|mp
operator|->
name|am_autofs_fh
argument_list|)
expr_stmt|;
comment|/* now do the mount */
name|error
operator|=
name|amfs_mount
argument_list|(
name|mp
argument_list|,
name|mf
argument_list|,
name|opts
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|errno
operator|=
name|error
expr_stmt|;
name|plog
argument_list|(
name|XLOG_FATAL
argument_list|,
literal|"amfs_auto_mount: amfs_mount failed: %m"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
block|}
endif|#
directive|endif
comment|/* HAVE_FS_AUTOFS */
comment|/*    * Attach a map cache    */
name|amfs_mkcacheref
argument_list|(
name|mf
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

