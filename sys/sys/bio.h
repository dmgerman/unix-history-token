begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)buf.h	8.9 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|iodone_chain
block|{
name|long
name|ic_prev_flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|ic_prev_iodone
function_decl|)
parameter_list|(
name|struct
name|bio
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ic_prev_iodone_chain
decl_stmt|;
struct|struct
block|{
name|long
name|ia_long
decl_stmt|;
name|void
modifier|*
name|ia_ptr
decl_stmt|;
block|}
name|ic_args
index|[
literal|5
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The bio structure describes an I/O operation in the kernel.  */
end_comment

begin_struct
struct|struct
name|bio
block|{
name|u_int
name|bio_cmd
decl_stmt|;
comment|/* I/O operation. */
name|dev_t
name|bio_dev
decl_stmt|;
comment|/* Device to do I/O on. */
name|daddr_t
name|bio_blkno
decl_stmt|;
comment|/* Underlying physical block number. */
name|off_t
name|bio_offset
decl_stmt|;
comment|/* Offset into file. */
name|long
name|bio_bcount
decl_stmt|;
comment|/* Valid bytes in buffer. */
name|caddr_t
name|bio_data
decl_stmt|;
comment|/* Memory, superblocks, indirect etc. */
name|u_int
name|bio_flags
decl_stmt|;
comment|/* BIO_ flags. */
name|int
name|bio_error
decl_stmt|;
comment|/* Errno for BIO_ERROR. */
name|long
name|bio_resid
decl_stmt|;
comment|/* Remaining I/0 in bytes. */
name|void
function_decl|(
modifier|*
name|bio_done
function_decl|)
parameter_list|(
name|struct
name|bio
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|bio_driver1
decl_stmt|;
comment|/* Private use by the callee. */
name|void
modifier|*
name|bio_driver2
decl_stmt|;
comment|/* Private use by the callee. */
name|void
modifier|*
name|bio_caller1
decl_stmt|;
comment|/* Private use by the caller. */
name|void
modifier|*
name|bio_caller2
decl_stmt|;
comment|/* Private use by the caller. */
name|TAILQ_ENTRY
argument_list|(
argument|bio
argument_list|)
name|bio_queue
expr_stmt|;
comment|/* Disksort queue. */
specifier|const
name|char
modifier|*
name|bio_attribute
decl_stmt|;
comment|/* Attribute for BIO_[GS]ETATTR */
name|struct
name|g_consumer
modifier|*
name|bio_from
decl_stmt|;
comment|/* GEOM linkage */
name|struct
name|g_provider
modifier|*
name|bio_to
decl_stmt|;
comment|/* GEOM linkage */
name|off_t
name|bio_length
decl_stmt|;
comment|/* Like bio_bcount */
name|off_t
name|bio_completed
decl_stmt|;
comment|/* Inverse of bio_resid */
name|u_int
name|bio_children
decl_stmt|;
comment|/* Number of spawned bios */
comment|/* XXX: these go away when bio chaining is introduced */
name|daddr_t
name|bio_pblkno
decl_stmt|;
comment|/* physical block number */
name|struct
name|iodone_chain
modifier|*
name|bio_done_chain
decl_stmt|;
name|struct
name|bio
modifier|*
name|bio_linkage
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bio_cmd */
end_comment

begin_define
define|#
directive|define
name|BIO_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BIO_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BIO_DELETE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BIO_GETATTR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BIO_SETATTR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BIO_CMD1
value|0x40000000
end_define

begin_comment
comment|/* Available for local hacks */
end_comment

begin_define
define|#
directive|define
name|BIO_CMD2
value|0x80000000
end_define

begin_comment
comment|/* Available for local hacks */
end_comment

begin_comment
comment|/* bio_flags */
end_comment

begin_define
define|#
directive|define
name|BIO_ERROR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BIO_DONE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BIO_FLAG2
value|0x40000000
end_define

begin_comment
comment|/* Available for local hacks */
end_comment

begin_define
define|#
directive|define
name|BIO_FLAG1
value|0x80000000
end_define

begin_comment
comment|/* Available for local hacks */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|devstat
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bio_queue_head
block|{
name|TAILQ_HEAD
argument_list|(
argument|bio_queue
argument_list|,
argument|bio
argument_list|)
name|queue
expr_stmt|;
name|daddr_t
name|last_pblkno
decl_stmt|;
name|struct
name|bio
modifier|*
name|insert_point
decl_stmt|;
name|struct
name|bio
modifier|*
name|switch_point
decl_stmt|;
name|int
name|busy
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|static
name|__inline
name|void
name|bioq_insert_tail
parameter_list|(
name|struct
name|bio_queue_head
modifier|*
name|head
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|bio
operator|*
name|bioq_first
argument_list|(
expr|struct
name|bio_queue_head
operator|*
name|head
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|__inline
name|void
name|bioq_insert_tail
parameter_list|(
name|struct
name|bio_queue_head
modifier|*
name|head
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
block|{
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|,
name|bp
argument_list|,
name|bio_queue
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|bio
operator|*
name|bioq_first
argument_list|(
argument|struct bio_queue_head *head
argument_list|)
block|{
return|return
operator|(
name|TAILQ_FIRST
argument_list|(
operator|&
name|head
operator|->
name|queue
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|biodone
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|biofinish
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|struct
name|devstat
modifier|*
name|stat
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|biowait
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
specifier|const
name|char
modifier|*
name|wchan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bioq_disksort
parameter_list|(
name|struct
name|bio_queue_head
modifier|*
name|ap
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bioqdisksort
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|bioq_disksort(foo, bar)
end_define

begin_function_decl
name|void
name|bioq_init
parameter_list|(
name|struct
name|bio_queue_head
modifier|*
name|head
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bioq_remove
parameter_list|(
name|struct
name|bio_queue_head
modifier|*
name|head
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|physio
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|physread
value|physio
end_define

begin_define
define|#
directive|define
name|physwrite
value|physio
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

begin_comment
comment|/* !_SYS_BIO_H_ */
end_comment

end_unit

