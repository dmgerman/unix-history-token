begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)file.h	8.3 (Berkeley) 1/9/95  * $Id: file.h,v 1.14 1997/09/14 02:25:40 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FILE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Kernel descriptor table.  * One entry for each open kernel vnode and socket.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|LIST_ENTRY
argument_list|(
argument|file
argument_list|)
name|f_list
expr_stmt|;
comment|/* list of active files */
name|short
name|f_flag
decl_stmt|;
comment|/* see fcntl.h */
define|#
directive|define
name|DTYPE_VNODE
value|1
comment|/* file */
define|#
directive|define
name|DTYPE_SOCKET
value|2
comment|/* communications endpoint */
define|#
directive|define
name|DTYPE_PIPE
value|3
comment|/* pipe */
define|#
directive|define
name|DTYPE_FIFO
value|4
comment|/* fifo (named pipe) */
name|short
name|f_type
decl_stmt|;
comment|/* descriptor type */
name|short
name|f_count
decl_stmt|;
comment|/* reference count */
name|short
name|f_msgcount
decl_stmt|;
comment|/* references from message queue */
name|struct
name|ucred
modifier|*
name|f_cred
decl_stmt|;
comment|/* credentials associated with descriptor */
struct|struct
name|fileops
block|{
name|int
argument_list|(
argument|*fo_read
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_write
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_ioctl
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|com
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_poll
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|events
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*fo_close
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
block|}
modifier|*
name|f_ops
struct|;
name|int
name|f_seqcount
decl_stmt|;
comment|/* 				 * count of sequential accesses -- cleared 				 * by most seek operations. 				 */
name|off_t
name|f_nextread
decl_stmt|;
comment|/* 				 * offset of next expected read 				 */
name|off_t
name|f_offset
decl_stmt|;
name|caddr_t
name|f_data
decl_stmt|;
comment|/* vnode or socket */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_FILE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|filelist
argument_list|,
name|file
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|filelist
name|filehead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list of open files */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fileops
name|vnops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel limit on number of open files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxfilesperproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per process limit on number of open files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual number of open files */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SYS_FILE_H */
end_comment

end_unit

