begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ufsmount.h	8.6 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2_MOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2_MOUNT_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_EXT2NODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_comment
comment|/* This structure describes the ext2fs specific mount structure data. */
end_comment

begin_struct
struct|struct
name|ext2mount
block|{
name|struct
name|mount
modifier|*
name|um_mountp
decl_stmt|;
comment|/* filesystem vfs structure */
name|struct
name|cdev
modifier|*
name|um_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|vnode
modifier|*
name|um_devvp
decl_stmt|;
comment|/* block device mounted vnode */
name|struct
name|m_ext2fs
modifier|*
name|um_e2fs
decl_stmt|;
comment|/* EXT2FS */
define|#
directive|define
name|em_e2fsb
value|um_e2fs->e2fs
name|u_long
name|um_nindir
decl_stmt|;
comment|/* indirect ptrs per block */
name|u_long
name|um_bptrtodb
decl_stmt|;
comment|/* indir ptr to disk block */
name|u_long
name|um_seqinc
decl_stmt|;
comment|/* inc between seq blocks */
name|struct
name|mtx
name|um_lock
decl_stmt|;
comment|/* Protects ext2mount& fs */
name|struct
name|g_consumer
modifier|*
name|um_cp
decl_stmt|;
name|struct
name|bufobj
modifier|*
name|um_bo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXT2_LOCK
parameter_list|(
name|aa
parameter_list|)
value|mtx_lock(&(aa)->um_lock)
end_define

begin_define
define|#
directive|define
name|EXT2_UNLOCK
parameter_list|(
name|aa
parameter_list|)
value|mtx_unlock(&(aa)->um_lock)
end_define

begin_define
define|#
directive|define
name|EXT2_MTX
parameter_list|(
name|aa
parameter_list|)
value|(&(aa)->um_lock)
end_define

begin_comment
comment|/* Convert mount ptr to ext2fsmount ptr. */
end_comment

begin_define
define|#
directive|define
name|VFSTOEXT2
parameter_list|(
name|mp
parameter_list|)
value|((struct ext2mount *)((mp)->mnt_data))
end_define

begin_comment
comment|/*  * Macros to access file system parameters in the ufsmount structure.  * Used by ufs_bmap.  */
end_comment

begin_define
define|#
directive|define
name|MNINDIR
parameter_list|(
name|ump
parameter_list|)
value|((ump)->um_nindir)
end_define

begin_define
define|#
directive|define
name|blkptrtodb
parameter_list|(
name|ump
parameter_list|,
name|b
parameter_list|)
value|((b)<< (ump)->um_bptrtodb)
end_define

begin_define
define|#
directive|define
name|is_sequential
parameter_list|(
name|ump
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((b) == (a) + ump->um_seqinc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

