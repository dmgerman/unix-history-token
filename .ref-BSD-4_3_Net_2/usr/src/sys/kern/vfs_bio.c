begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vfs_bio.c	7.40 (Berkeley) 5/8/91  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"specdev.h"
end_include

begin_include
include|#
directive|include
file|"mount.h"
end_include

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_include
include|#
directive|include
file|"resourcevar.h"
end_include

begin_comment
comment|/*  * Initialize buffers and hash links for buffers.  */
end_comment

begin_macro
name|bufinit
argument_list|()
end_macro

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

begin_comment
comment|/*  * Find the block in the buffer pool.  * If the buffer is not present, allocate a new buffer and load  * its contents according to the filesystem fill routine.  */
end_comment

begin_macro
name|bread
argument_list|(
argument|vp
argument_list|,
argument|blkno
argument_list|,
argument|size
argument_list|,
argument|cred
argument_list|,
argument|bpp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|blkno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
modifier|*
name|bpp
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Operates like bread, but also starts I/O on the specified  * read-ahead block.  */
end_comment

begin_macro
name|breada
argument_list|(
argument|vp
argument_list|,
argument|blkno
argument_list|,
argument|size
argument_list|,
argument|rablkno
argument_list|,
argument|rabsize
argument_list|,
argument|cred
argument_list|,
argument|bpp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|blkno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|rablkno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rabsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
modifier|*
modifier|*
name|bpp
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Synchronous write.  * Release buffer on completion.  */
end_comment

begin_expr_stmt
name|bwrite
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Delayed write.  *  * The buffer is marked dirty, but is not queued for I/O.  * This routine should be used when the buffer is expected  * to be modified again soon, typically a small write that  * partially fills a buffer.  *  * NB: magnetic tapes cannot be delayed; they must be  * written in the order that the writes are requested.  */
end_comment

begin_expr_stmt
name|bdwrite
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

begin_comment
comment|/*  * Asynchronous write.  * Start I/O on a buffer, but do not wait for it to complete.  * The buffer is released when the I/O completes.  */
end_comment

begin_expr_stmt
name|bawrite
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

begin_comment
comment|/*  * Release a buffer.  * Even if the buffer is dirty, no I/O is started.  */
end_comment

begin_expr_stmt
name|brelse
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

begin_comment
comment|/*  * Check to see if a block is currently memory resident.  */
end_comment

begin_macro
name|incore
argument_list|(
argument|vp
argument_list|,
argument|blkno
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|blkno
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Check to see if a block is currently memory resident.  * If it is resident, return it. If it is not resident,  * allocate a new buffer and assign it to the block.  */
end_comment

begin_function
name|struct
name|buf
modifier|*
name|getblk
parameter_list|(
name|vp
parameter_list|,
name|blkno
parameter_list|,
name|size
parameter_list|)
specifier|register
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|daddr_t
name|blkno
decl_stmt|;
name|int
name|size
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Allocate a buffer.  * The caller will assign it to a block.  */
end_comment

begin_function
name|struct
name|buf
modifier|*
name|geteblk
parameter_list|(
name|size
parameter_list|)
name|int
name|size
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Expand or contract the actual memory allocated to a buffer.  * If no memory is available, release buffer and take error exit.  */
end_comment

begin_expr_stmt
name|allocbuf
argument_list|(
name|tp
argument_list|,
name|size
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|tp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Find a buffer which is available for use.  * Select something from a free list.  * Preference is to AGE list, then LRU list.  */
end_comment

begin_function
name|struct
name|buf
modifier|*
name|getnewbuf
parameter_list|()
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Wait for I/O to complete.  *  * Extract and return any errors associated with the I/O.  * If the error flag is set, but no specific error is  * given, return EIO.  */
end_comment

begin_expr_stmt
name|biowait
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Mark I/O complete on a buffer.  *  * If a callback has been requested, e.g. the pageout  * daemon, do so. Otherwise, awaken waiting processes.  */
end_comment

begin_expr_stmt
name|biodone
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

end_unit

