begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ntfs_ihash.c,v 1.5 1999/09/30 16:56:40 jdolecek Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1991, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ufs_ihash.c	8.7 (Berkeley) 5/17/95  * $FreeBSD$  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<ntfs/ntfs.h>
end_include

begin_include
include|#
directive|include
file|<ntfs/ntfs_inode.h>
end_include

begin_include
include|#
directive|include
file|<ntfs/ntfs_ihash.h>
end_include

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_NTFSNTHASH
argument_list|,
literal|"NTFS nthash"
argument_list|,
literal|"NTFS ntnode hash tables"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Structures associated with inode cacheing.  */
end_comment

begin_expr_stmt
specifier|static
name|LIST_HEAD
argument_list|(
name|nthashhead
argument_list|,
name|ntnode
argument_list|)
operator|*
name|ntfs_nthashtbl
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|u_long
name|ntfs_nthash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of hash table - 1 */
end_comment

begin_define
define|#
directive|define
name|NTNOHASH
parameter_list|(
name|device
parameter_list|,
name|inum
parameter_list|)
value|(&ntfs_nthashtbl[(minor(device) + (inum))& ntfs_nthash])
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_SIMPLELOCKS
end_ifndef

begin_decl_stmt
specifier|static
name|struct
name|simplelock
name|ntfs_nthash_slock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|lock
name|ntfs_hashlock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialize inode hash table.  */
end_comment

begin_function
name|void
name|ntfs_nthashinit
parameter_list|()
block|{
name|lockinit
argument_list|(
operator|&
name|ntfs_hashlock
argument_list|,
name|PINOD
argument_list|,
literal|"ntfs_nthashlock"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ntfs_nthashtbl
operator|=
name|HASHINIT
argument_list|(
name|desiredvnodes
argument_list|,
name|M_NTFSNTHASH
argument_list|,
name|M_WAITOK
argument_list|,
operator|&
name|ntfs_nthash
argument_list|)
expr_stmt|;
name|simple_lock_init
argument_list|(
operator|&
name|ntfs_nthash_slock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Use the device/inum pair to find the incore inode, and return a pointer  * to it. If it is in core, return it, even if it is locked.  */
end_comment

begin_function
name|struct
name|ntnode
modifier|*
name|ntfs_nthashlookup
parameter_list|(
name|dev
parameter_list|,
name|inum
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|ino_t
name|inum
decl_stmt|;
block|{
name|struct
name|ntnode
modifier|*
name|ip
decl_stmt|;
name|simple_lock
argument_list|(
operator|&
name|ntfs_nthash_slock
argument_list|)
expr_stmt|;
for|for
control|(
name|ip
operator|=
name|NTNOHASH
argument_list|(
name|dev
argument_list|,
name|inum
argument_list|)
operator|->
name|lh_first
init|;
name|ip
condition|;
name|ip
operator|=
name|ip
operator|->
name|i_hash
operator|.
name|le_next
control|)
if|if
condition|(
name|inum
operator|==
name|ip
operator|->
name|i_number
operator|&&
name|dev
operator|==
name|ip
operator|->
name|i_dev
condition|)
break|break;
name|simple_unlock
argument_list|(
operator|&
name|ntfs_nthash_slock
argument_list|)
expr_stmt|;
return|return
operator|(
name|ip
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Insert the ntnode into the hash table.  */
end_comment

begin_function
name|void
name|ntfs_nthashins
parameter_list|(
name|ip
parameter_list|)
name|struct
name|ntnode
modifier|*
name|ip
decl_stmt|;
block|{
name|struct
name|nthashhead
modifier|*
name|ipp
decl_stmt|;
name|simple_lock
argument_list|(
operator|&
name|ntfs_nthash_slock
argument_list|)
expr_stmt|;
name|ipp
operator|=
name|NTNOHASH
argument_list|(
name|ip
operator|->
name|i_dev
argument_list|,
name|ip
operator|->
name|i_number
argument_list|)
expr_stmt|;
name|LIST_INSERT_HEAD
argument_list|(
name|ipp
argument_list|,
name|ip
argument_list|,
name|i_hash
argument_list|)
expr_stmt|;
name|ip
operator|->
name|i_flag
operator||=
name|IN_HASHED
expr_stmt|;
name|simple_unlock
argument_list|(
operator|&
name|ntfs_nthash_slock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Remove the inode from the hash table.  */
end_comment

begin_function
name|void
name|ntfs_nthashrem
parameter_list|(
name|ip
parameter_list|)
name|struct
name|ntnode
modifier|*
name|ip
decl_stmt|;
block|{
name|simple_lock
argument_list|(
operator|&
name|ntfs_nthash_slock
argument_list|)
expr_stmt|;
if|if
condition|(
name|ip
operator|->
name|i_flag
operator|&
name|IN_HASHED
condition|)
block|{
name|ip
operator|->
name|i_flag
operator|&=
operator|~
name|IN_HASHED
expr_stmt|;
name|LIST_REMOVE
argument_list|(
name|ip
argument_list|,
name|i_hash
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|ip
operator|->
name|i_hash
operator|.
name|le_next
operator|=
name|NULL
expr_stmt|;
name|ip
operator|->
name|i_hash
operator|.
name|le_prev
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
block|}
name|simple_unlock
argument_list|(
operator|&
name|ntfs_nthash_slock
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

