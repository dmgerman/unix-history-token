begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1995 Artisoft, Inc.  All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vfs_conf.c	8.8 (Berkeley) 3/31/94  * $Id: vfs_conf.c,v 1.26 1998/09/14 19:56:40 sos Exp $  */
end_comment

begin_comment
comment|/*  * PURPOSE:	This file abstracts the root mounting interface from  *		the per file system semantics for handling mounts,  *		the overall intent of which is to move the BSD  *		internals dependence out of the FS code, both to  *		make the FS code more portable and to free up some  *		of the BSD internals so that they may more easily  *		be changed.  *  * NOTE1:	Code is single entry/single exit to aid debugging  *		and conversion for kernel multithreading.  *  * NOTE2:	Code notes lock state in headers on entry and exit  *		as an aid to conversion for kernel multithreading  *		on SMP reentrancy  */
end_comment

begin_include
include|#
directive|include
file|"opt_bootp.h"
end_include

begin_include
include|#
directive|include
file|"opt_mfs.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* dev_t (types.h)*/
end_comment

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/* rootvp*/
end_comment

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_comment
comment|/* curproc*/
end_comment

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_comment
comment|/* NULLVP*/
end_comment

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_comment
comment|/* struct mount*/
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_comment
comment|/* M_MOUNT*/
end_comment

begin_comment
comment|/*  * GLOBALS  */
end_comment

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_MOUNT
argument_list|,
literal|"mount"
argument_list|,
literal|"vfs mount struct"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *  These define the root filesystem, device, and root filesystem type.  */
end_comment

begin_decl_stmt
name|dev_t
name|rootdevs
index|[]
init|=
block|{
name|NODEV
block|,
name|NODEV
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rootdevnames
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|rootvnode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mountrootfsname
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BOOTP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|bootpc_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * vfs_init() will set maxvfsconf  * to the highest defined type number.  */
end_comment

begin_decl_stmt
name|int
name|maxvfsconf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vfsconf
modifier|*
name|vfsconf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Common root mount code shared by all filesystems  */
end_comment

begin_define
define|#
directive|define
name|ROOTNAME
value|"root_device"
end_define

begin_comment
comment|/*  * vfs_mountrootfs  *  * Common entry point for root mounts  *  * PARAMETERS:  * 		NONE  *  * RETURNS:	0	Success  *		!0	error number (errno.h)  *  * LOCK STATE:  *		ENTRY  *<no locks held>  *		EXIT  *<no locks held>  *  * NOTES:  *		This code is currently supported only for use for  *		the FFS file system type.  This is a matter of  *		fixing the other file systems, not this code!  */
end_comment

begin_function
specifier|static
name|void
name|vfs_mountrootfs
parameter_list|(
name|void
modifier|*
name|unused
parameter_list|)
block|{
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
name|int
name|err
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
init|=
name|curproc
decl_stmt|;
comment|/* XXX */
ifndef|#
directive|ifndef
name|MFS_ROOT
name|int
name|i
decl_stmt|;
name|dev_t
name|orootdev
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BOOTP
name|bootpc_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* 	 *  New root mount structure 	 */
if|if
condition|(
operator|(
name|err
operator|=
name|vfs_rootmountalloc
argument_list|(
name|mountrootfsname
argument_list|,
name|ROOTNAME
argument_list|,
operator|&
name|mp
argument_list|)
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"error %d: "
argument_list|,
name|err
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"cannot mount root\n"
argument_list|)
expr_stmt|;
return|return ;
block|}
name|mp
operator|->
name|mnt_flag
operator||=
name|MNT_ROOTFS
expr_stmt|;
comment|/* 	 * Attempt the mount 	 */
ifdef|#
directive|ifdef
name|MFS_ROOT
name|err
operator|=
name|VFS_MOUNT
argument_list|(
name|mp
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|p
argument_list|)
expr_stmt|;
else|#
directive|else
name|err
operator|=
name|ENXIO
expr_stmt|;
name|orootdev
operator|=
name|rootdev
expr_stmt|;
if|if
condition|(
name|rootdevs
index|[
literal|0
index|]
operator|==
name|NODEV
condition|)
name|rootdevs
index|[
literal|0
index|]
operator|=
name|rootdev
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|rootdevs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rootdevs
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|rootdevs
index|[
name|i
index|]
operator|==
name|NODEV
condition|)
break|break;
name|rootdev
operator|=
name|rootdevs
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|rootdev
operator|!=
name|orootdev
condition|)
block|{
name|printf
argument_list|(
literal|"changing root device to %s\n"
argument_list|,
name|rootdevnames
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|orootdev
operator|=
name|rootdev
expr_stmt|;
block|}
name|strncpy
argument_list|(
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntfromname
argument_list|,
name|rootdevnames
index|[
name|i
index|]
condition|?
name|rootdevnames
index|[
name|i
index|]
else|:
name|ROOTNAME
argument_list|,
name|MNAMELEN
operator|-
literal|1
argument_list|)
expr_stmt|;
name|err
operator|=
name|VFS_MOUNT
argument_list|(
name|mp
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
name|ENXIO
condition|)
break|break;
block|}
endif|#
directive|endif
if|if
condition|(
name|err
condition|)
block|{
comment|/* 		 * XXX should ask the user for the name in some cases. 		 * Why do we call vfs_unbusy() here and not after ENXIO 		 * is returned above? 		 */
name|vfs_unbusy
argument_list|(
name|mp
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* 		 * free mount struct before failing 		 * (hardly worthwhile with the PANIC eh?) 		 */
name|free
argument_list|(
name|mp
argument_list|,
name|M_MOUNT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"error %d: "
argument_list|,
name|err
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"cannot mount root (2)\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|simple_lock
argument_list|(
operator|&
name|mountlist_slock
argument_list|)
expr_stmt|;
comment|/* 	 * Add fs to list of mounted file systems 	 */
name|CIRCLEQ_INSERT_HEAD
argument_list|(
operator|&
name|mountlist
argument_list|,
name|mp
argument_list|,
name|mnt_list
argument_list|)
expr_stmt|;
name|simple_unlock
argument_list|(
operator|&
name|mountlist_slock
argument_list|)
expr_stmt|;
name|vfs_unbusy
argument_list|(
name|mp
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* root mount, update system time from FS specific data*/
name|inittodr
argument_list|(
name|mp
operator|->
name|mnt_time
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_macro
name|SYSINIT
argument_list|(
argument|mountroot
argument_list|,
argument|SI_SUB_MOUNT_ROOT
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|vfs_mountrootfs
argument_list|,
argument|NULL
argument_list|)
end_macro

end_unit

