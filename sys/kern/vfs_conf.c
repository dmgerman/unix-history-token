begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1995 Artisoft, Inc.  All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vfs_conf.c	8.8 (Berkeley) 3/31/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * PURPOSE:	This file abstracts the root mounting interface from  *		the per file system semantics for handling mounts,  *		the overall intent of which is to move the BSD  *		internals dependence out of the FS code, both to  *		make the FS code more portable and to free up some  *		of the BSD internals so that they may more easily  *		be changed.  *  * NOTE1:	Code is single entry/single exit to aid debugging  *		and conversion for kernel multithreading.  *  * NOTE2:	Code notes lock state in headers on entry and exit  *		as an aid to conversion for kernel multithreading  *		on SMP reentrancy  */
end_comment

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

begin_macro
name|int
argument_list|(
argument|*mountroot
argument_list|)
end_macro

begin_expr_stmt
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|rootvnode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vfsops
modifier|*
name|mountrootvfsops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Common root mount code shared by all filesystems  */
end_comment

begin_define
define|#
directive|define
name|ROOTDIR
value|"/"
end_define

begin_define
define|#
directive|define
name|ROOTNAME
value|"root_device"
end_define

begin_comment
comment|/*  * vfs_mountroot  *  * Common entry point for root mounts  *  * PARAMETERS:  *		data	pointer to the vfs_ops for the FS type mounting  *  * RETURNS:	0	Success  *		!0	error number (errno.h)  *  * LOCK STATE:  *		ENTRY  *<no locks held>  *		EXIT  *<no locks held>  *  * NOTES:  *		This code is currently supported only for use for  *		the FFS file system type.  This is a matter of  *		fixing the other file systems, not this code!  */
end_comment

begin_function
name|int
name|vfs_mountroot
parameter_list|(
name|data
parameter_list|)
name|void
modifier|*
name|data
decl_stmt|;
block|{
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
name|u_int
name|size
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
init|=
name|curproc
decl_stmt|;
comment|/* XXX */
name|struct
name|vfsops
modifier|*
name|mnt_op
init|=
operator|(
expr|struct
name|vfsops
operator|*
operator|)
name|data
decl_stmt|;
comment|/* 	 *  New root mount structure 	 */
name|mp
operator|=
name|malloc
argument_list|(
operator|(
name|u_long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|mount
argument_list|)
argument_list|,
name|M_MOUNT
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|mp
argument_list|,
operator|(
name|u_long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|mount
argument_list|)
argument_list|)
expr_stmt|;
name|mp
operator|->
name|mnt_op
operator|=
name|mnt_op
expr_stmt|;
name|mp
operator|->
name|mnt_flag
operator|=
name|MNT_ROOTFS
expr_stmt|;
name|mp
operator|->
name|mnt_vnodecovered
operator|=
name|NULLVP
expr_stmt|;
comment|/* 	 * Lock mount point 	 */
if|if
condition|(
operator|(
name|err
operator|=
name|vfs_lock
argument_list|(
name|mp
argument_list|)
operator|)
operator|!=
literal|0
condition|)
goto|goto
name|error_1
goto|;
comment|/* Save "last mounted on" info for mount point (NULL pad)*/
name|copystr
argument_list|(
name|ROOTDIR
argument_list|,
comment|/* mount point*/
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntonname
argument_list|,
comment|/* save area*/
name|MNAMELEN
operator|-
literal|1
argument_list|,
comment|/* max size*/
operator|&
name|size
argument_list|)
expr_stmt|;
comment|/* real size*/
name|bzero
argument_list|(
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntonname
operator|+
name|size
argument_list|,
name|MNAMELEN
operator|-
name|size
argument_list|)
expr_stmt|;
comment|/* Save "mounted from" info for mount point (NULL pad)*/
name|copystr
argument_list|(
name|ROOTNAME
argument_list|,
comment|/* device name*/
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntfromname
argument_list|,
comment|/* save area*/
name|MNAMELEN
operator|-
literal|1
argument_list|,
comment|/* max size*/
operator|&
name|size
argument_list|)
expr_stmt|;
comment|/* real size*/
name|bzero
argument_list|(
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntfromname
operator|+
name|size
argument_list|,
name|MNAMELEN
operator|-
name|size
argument_list|)
expr_stmt|;
comment|/* 	 * Attempt the mount. 	 * 	 * If the mount fails, and it was an attempt to mount something 	 * which looks like it might have been within a disk slice, try 	 * again mounting the compatability slice instead. 	 */
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
operator|(
name|err
operator|==
name|ENXIO
operator|)
operator|&&
operator|(
name|rootdev
operator|&
literal|0xff0000
operator|)
condition|)
block|{
name|rootdev
operator|&=
operator|~
literal|0xff0000
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
block|}
if|if
condition|(
name|err
condition|)
goto|goto
name|error_2
goto|;
comment|/* Add fs to list of mounted file systems*/
name|CIRCLEQ_INSERT_TAIL
argument_list|(
operator|&
name|mountlist
argument_list|,
name|mp
argument_list|,
name|mnt_list
argument_list|)
expr_stmt|;
comment|/* Unlock mount point*/
name|vfs_unlock
argument_list|(
name|mp
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
goto|goto
name|success
goto|;
name|error_2
label|:
comment|/* mount error*/
comment|/* unlock before failing*/
name|vfs_unlock
argument_list|(
name|mp
argument_list|)
expr_stmt|;
name|error_1
label|:
comment|/* lock error*/
comment|/* free mount struct before failing*/
name|free
argument_list|(
name|mp
argument_list|,
name|M_MOUNT
argument_list|)
expr_stmt|;
name|success
label|:
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

end_unit

