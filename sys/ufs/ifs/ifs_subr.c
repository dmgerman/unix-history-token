begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000  *	Adrian Chadd<adrian@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ffs_vnops.c	8.15 (Berkeley) 5/14/95  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dir.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/quota.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/inode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/ufs_extern.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/ffs_extern.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ifs/ifs_extern.h>
end_include

begin_comment
comment|/*  * Check whether the given inode number is free.  *  * This routine is a chunk of ffs_nodealloccg - we aren't  * allocating here. We also check whether there will be  * any other inodes in the cylinder group, and if not,  * we return -1.  */
end_comment

begin_function
name|int
name|ifs_isinodealloc
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|ufs_daddr_t
name|ino
parameter_list|)
block|{
name|struct
name|fs
modifier|*
name|fs
decl_stmt|;
name|struct
name|cg
modifier|*
name|cgp
decl_stmt|;
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
name|int
name|error
decl_stmt|;
name|int
name|cg
decl_stmt|;
name|int
name|retval
init|=
literal|0
decl_stmt|;
comment|/* Grab the filesystem info and cylinder group */
name|fs
operator|=
name|ip
operator|->
name|i_fs
expr_stmt|;
name|cg
operator|=
name|ino_to_cg
argument_list|(
name|fs
argument_list|,
name|ino
argument_list|)
expr_stmt|;
comment|/* Read in the cylinder group inode allocation bitmap .. */
name|error
operator|=
name|bread
argument_list|(
name|ip
operator|->
name|i_devvp
argument_list|,
name|fsbtodb
argument_list|(
name|fs
argument_list|,
name|cgtod
argument_list|(
name|fs
argument_list|,
name|cg
argument_list|)
argument_list|)
argument_list|,
operator|(
name|int
operator|)
name|fs
operator|->
name|fs_cgsize
argument_list|,
name|NOCRED
argument_list|,
operator|&
name|bp
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|retval
operator|=
name|IFS_INODE_NOALLOC
expr_stmt|;
goto|goto
name|end
goto|;
block|}
name|cgp
operator|=
operator|(
expr|struct
name|cg
operator|*
operator|)
name|bp
operator|->
name|b_data
expr_stmt|;
if|if
condition|(
operator|!
name|cg_chkmagic
argument_list|(
name|cgp
argument_list|)
condition|)
block|{
name|retval
operator|=
name|IFS_INODE_NOALLOC
expr_stmt|;
goto|goto
name|end
goto|;
block|}
name|ino
operator|%=
name|fs
operator|->
name|fs_ipg
expr_stmt|;
comment|/* 	 * Check whether we have any inodes in this cg, or whether the 	 * inode is allocated 	 */
if|if
condition|(
operator|!
name|isclr
argument_list|(
name|cg_inosused
argument_list|(
name|cgp
argument_list|)
argument_list|,
name|ino
argument_list|)
condition|)
name|retval
operator|=
name|IFS_INODE_ISALLOC
expr_stmt|;
comment|/* it is allocated */
elseif|else
if|if
condition|(
name|cgp
operator|->
name|cg_niblk
operator|==
name|cgp
operator|->
name|cg_cs
operator|.
name|cs_nifree
condition|)
name|retval
operator|=
name|IFS_INODE_EMPTYCG
expr_stmt|;
comment|/* empty cg */
else|else
name|retval
operator|=
name|IFS_INODE_NOALLOC
expr_stmt|;
comment|/* its not allocated */
name|end
label|:
comment|/* Close the buffer and return */
name|brelse
argument_list|(
name|bp
argument_list|)
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

end_unit

