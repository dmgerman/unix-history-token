begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mfsnode.h	8.3 (Berkeley) 5/19/95  * $Id: mfsnode.h,v 1.9 1997/09/14 02:58:08 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_MFS_MFSNODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_MFS_MFSNODE_H_
end_define

begin_comment
comment|/*  * This structure defines the control data for the memory based file system.  */
end_comment

begin_struct
struct|struct
name|mfsnode
block|{
name|struct
name|vnode
modifier|*
name|mfs_vnode
decl_stmt|;
comment|/* vnode associated with this mfsnode */
name|caddr_t
name|mfs_baseoff
decl_stmt|;
comment|/* base of file system in memory */
name|long
name|mfs_size
decl_stmt|;
comment|/* size of memory file system */
name|pid_t
name|mfs_pid
decl_stmt|;
comment|/* supporting process pid */
name|struct
name|buf_queue_head
name|buf_queue
decl_stmt|;
comment|/* list of I/O requests */
name|int
name|mfs_active
decl_stmt|;
name|long
name|mfs_spare
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Convert between mfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTOMFS
parameter_list|(
name|vp
parameter_list|)
value|((struct mfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|MFSTOV
parameter_list|(
name|mfsp
parameter_list|)
value|((mfsp)->mfs_vnode)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

