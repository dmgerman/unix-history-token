begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* XXX Conflicts with John's - not installed.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id:$  */
end_comment

begin_comment
comment|/* aio.h: P1003.1B-1993 Asynchronous I/O */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX4_AIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_POSIX4_AIO_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX4_INCLUDE_MAYBES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return values: */
end_comment

begin_define
define|#
directive|define
name|AIO_CANCELED
value|0x01
end_define

begin_comment
comment|/* All operations cancelled */
end_comment

begin_define
define|#
directive|define
name|AIO_NOTCANCELLED
value|0x02
end_define

begin_comment
comment|/* Some not cancelled */
end_comment

begin_define
define|#
directive|define
name|AIO_ALLDONE
value|0x04
end_define

begin_comment
comment|/* None were cancelled */
end_comment

begin_comment
comment|/* lio_listio synchronization options */
end_comment

begin_define
define|#
directive|define
name|LIO_WAIT
value|0x08
end_define

begin_comment
comment|/* Suspend until complete */
end_comment

begin_define
define|#
directive|define
name|LIO_NOWAIT
value|0x10
end_define

begin_comment
comment|/* Continue operation */
end_comment

begin_comment
comment|/* lio_listio element operations */
end_comment

begin_define
define|#
directive|define
name|LIO_READ
value|0x20
end_define

begin_define
define|#
directive|define
name|LIO_WRITE
value|0x40
end_define

begin_define
define|#
directive|define
name|LIO_NOP
value|0x80
end_define

begin_typedef
typedef|typedef
name|struct
name|aiocb
modifier|*
specifier|const
name|aio_listio_ctl
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|aiocb
modifier|*
specifier|const
name|caio_listio_ctl
typedef|;
end_typedef

begin_struct
struct|struct
name|aiocb
block|{
name|int
name|aio_fildes
decl_stmt|;
comment|/* File descriptor */
name|off_t
name|aio_offset
decl_stmt|;
comment|/* File offset */
specifier|volatile
name|void
modifier|*
name|aio_buf
decl_stmt|;
comment|/* Location of buffer */
name|size_t
name|aio_nbytes
decl_stmt|;
comment|/* Length of transfer */
name|int
name|aio_reqprio
decl_stmt|;
comment|/* Request priority offset */
name|struct
name|sigevent
name|aio_sigevent
decl_stmt|;
comment|/* Signal number and value */
name|int
name|aio_lio_opcode
decl_stmt|;
comment|/* Operation to be performed */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|int
name|aio_read
name|__P
argument_list|(
operator|(
expr|struct
name|aiocb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aio_write
name|__P
argument_list|(
operator|(
expr|struct
name|aiocb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lio_listio
name|__P
argument_list|(
operator|(
name|int
operator|,
name|aio_listio_ctl
index|[
name|_POSIX_AIO_LISTIO_MAX
index|]
operator|,
name|int
operator|,
expr|struct
name|sigevent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aio_error
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|aiocb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|aio_return
name|__P
argument_list|(
operator|(
expr|struct
name|aiocb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aio_cancel
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|aiocb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aio_suspend
name|__P
argument_list|(
operator|(
name|caio_listio_ctl
index|[
name|_POSIX_AIO_LISTIO_MAX
index|]
operator|,
name|int
operator|,
specifier|const
expr|struct
name|timespec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aio_fsync
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|aiocb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* _POSIX4_AIO_H_ */
end_comment

end_unit

