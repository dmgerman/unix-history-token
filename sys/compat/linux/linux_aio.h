begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Li, Xiao<intron@intron.ac>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Linux Kernel Implementation of Asynchronous I/O  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_AIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_AIO_H_
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|linux_aio_context_t
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|LINUX_IOCB_CMD_PREAD
init|=
literal|0
block|,
name|LINUX_IOCB_CMD_PWRITE
init|=
literal|1
block|,
name|LINUX_IOCB_CMD_FSYNC
init|=
literal|2
block|,
name|LINUX_IOCB_CMD_FDSYNC
init|=
literal|3
block|,
if|#
directive|if
literal|0
block|LINUX_IOCB_CMD_PREADX = 4, 	LINUX_IOCB_CMD_POLL = 5,
endif|#
directive|endif
name|LINUX_IOCB_CMD_NOOP
init|=
literal|6
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|linux_io_event
block|{
name|uint64_t
name|data
decl_stmt|;
name|uint64_t
name|obj
decl_stmt|;
name|int64_t
name|res
decl_stmt|;
name|int64_t
name|res2
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|LINUX_AIO_PADDED
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x,y
end_define

begin_elif
elif|#
directive|elif
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|LINUX_AIO_PADDED
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|y,x
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unidentified byte order !!!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|linux_iocb
block|{
name|uint64_t
name|aio_data
decl_stmt|;
name|uint32_t
name|LINUX_AIO_PADDED
parameter_list|(
name|aio_key
parameter_list|,
name|aio_reserved1
parameter_list|)
function_decl|;
name|uint16_t
name|aio_lio_opcode
decl_stmt|;
name|int16_t
name|aio_reqprio
decl_stmt|;
name|uint32_t
name|aio_fildes
decl_stmt|;
name|uint64_t
name|aio_buf
decl_stmt|;
name|uint64_t
name|aio_nbytes
decl_stmt|;
name|int64_t
name|aio_offset
decl_stmt|;
name|uint64_t
name|aio_reserved2
decl_stmt|;
comment|/* TODO: use this for a (struct sigevent *) */
name|uint64_t
name|aio_reserved3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* User space context information structure */
end_comment

begin_struct
struct|struct
name|linux_aio_ring
block|{
name|l_uint
name|ring_id
decl_stmt|;
name|l_uint
name|ring_nr
decl_stmt|;
name|l_uint
name|ring_head
decl_stmt|;
name|l_uint
name|ring_tail
decl_stmt|;
define|#
directive|define
name|LINUX_AIO_RING_MAGIC
value|0xa10a10a1
name|l_uint
name|ring_magic
decl_stmt|;
define|#
directive|define
name|LINUX_AIO_RING_COMPAT_FEATURES
value|1
name|l_uint
name|ring_compat_features
decl_stmt|;
define|#
directive|define
name|LINUX_AIO_RING_INCOMPAT_FEATURES
value|0
name|l_uint
name|ring_incompat_features
decl_stmt|;
name|l_uint
name|ring_header_length
decl_stmt|;
comment|/* Size of this structure */
name|struct
name|linux_io_event
name|ring_io_events
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_AIO_H_ */
end_comment

end_unit

