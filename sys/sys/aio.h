begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_AIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_AIO_H_
end_define

begin_comment
comment|/*  * Copyright (c) 1997 John S. Dyson.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. John S. Dyson's name may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * DISCLAIMER:  This code isn't warranted to do anything useful.  Anything  * bad that happens because of using this software isn't the responsibility  * of the author.  This software is distributed AS-IS.  *  * $Id: aio.h,v 1.4 1998/03/08 17:25:30 dufault Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/* Additions to signal.h -- hack alert.                                   */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * sigval structure:  */
end_comment

begin_union
union|union
name|sigval
block|{
name|int
name|sival_int
decl_stmt|;
name|void
modifier|*
name|sival_ptr
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * this is the sigevent structure:  */
end_comment

begin_struct
struct|struct
name|sigevent
block|{
name|int
name|sigev_notify
decl_stmt|;
comment|/* Notification */
name|int
name|sigev_signo
decl_stmt|;
comment|/* Signal number */
name|union
name|sigval
name|sigev_value
decl_stmt|;
comment|/* Not used yet in FreeBSD */
block|}
struct|;
end_struct

begin_comment
comment|/*  * values for sigev_notify:  */
end_comment

begin_expr_stmt
name|define
name|SIGEV_NONE
literal|0
comment|/* Don't post a signal */
define|#
directive|define
name|SIGEV_SIGNAL
value|1
comment|/* Post specified signal */
comment|/*  * Returned by aio_cancel:  *  (Note that FreeBSD's aio is not cancellable -- yet.)  */
define|#
directive|define
name|AIO_CANCELED
value|0x1
define|#
directive|define
name|AIO_NOTCANCELED
value|0x2
define|#
directive|define
name|AIO_ALLDONE
value|0x3
comment|/*  * LIO opcodes  */
define|#
directive|define
name|LIO_NOP
value|0x0
define|#
directive|define
name|LIO_WRITE
value|0x1
define|#
directive|define
name|LIO_READ
value|0x2
comment|/*  * LIO modes  */
define|#
directive|define
name|LIO_NOWAIT
value|0x0
define|#
directive|define
name|LIO_WAIT
value|0x1
comment|/*  * Maximum number of allowed LIO operations  */
define|#
directive|define
name|AIO_LISTIO_MAX
value|16
comment|/*  * Private mode bit for aio.  * (This bit is set by the library routine  *  to allow the kernel to support sync  *  or async operations in the future.)  */
define|#
directive|define
name|AIO_PMODE_SYNC
value|0x1
define|#
directive|define
name|AIO_PMODE_DONE
value|0x2
define|#
directive|define
name|AIO_PMODE_SUSPEND
value|0x4
define|#
directive|define
name|AIO_PMODE_ACTIVE
value|0x2357c0de
comment|/*  * Private members for aiocb -- don't access  * directly.  */
expr|struct
name|__aiocb_private
block|{
name|int
name|status
block|;
name|int
name|error
block|;
name|int
name|privatemodes
block|;
name|int
name|active
block|;
name|int
name|tid
block|;
name|int
name|threadinfo
block|;
name|void
operator|*
name|userinfo
block|;
name|void
operator|*
name|kernelinfo
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * I/O control block  */
end_comment

begin_typedef
typedef|typedef
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
comment|/* File offset for I/O */
specifier|volatile
name|void
modifier|*
name|aio_buf
decl_stmt|;
comment|/* I/O buffer in process space */
name|size_t
name|aio_nbytes
decl_stmt|;
comment|/* Number of bytes for I/O */
name|struct
name|sigevent
name|aio_sigevent
decl_stmt|;
comment|/* Signal to deliver */
name|int
name|aio_lio_opcode
decl_stmt|;
comment|/* LIO opcode */
name|int
name|aio_reqprio
decl_stmt|;
comment|/* Request priority -- ignored */
name|struct
name|__aiocb_private
name|_aiocb_private
decl_stmt|;
block|}
name|aiocb_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_comment
comment|/*  * Asynchronously read from a file  */
end_comment

begin_function_decl
name|int
name|aio_read
parameter_list|(
name|struct
name|aiocb
modifier|*
name|iocb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Asynchronously write to file  */
end_comment

begin_function_decl
name|int
name|aio_write
parameter_list|(
name|struct
name|aiocb
modifier|*
name|iocb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * List I/O Asynchronously/synchronously read/write to/from file  *	"lio_mode" specifies whether or not the I/O is synchronous.  *	"acb_list" is an array of "nacb_listent" I/O control blocks.  *	when all I/Os are complete, the optional signal "sig" is sent.  */
end_comment

begin_function_decl
name|int
name|lio_listio
parameter_list|(
name|int
name|lio_mode
parameter_list|,
name|struct
name|aiocb
modifier|*
specifier|const
name|acb_list
index|[]
parameter_list|,
name|int
name|nacb_listent
parameter_list|,
name|struct
name|sigevent
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get completion status  *	returns EINPROGRESS until I/O is complete.  *	this routine does not block.  */
end_comment

begin_function_decl
name|int
name|aio_error
parameter_list|(
specifier|const
name|struct
name|aiocb
modifier|*
name|iocb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finish up I/O, releasing I/O resources and returns the value  *	that would have been associated with a synchronous I/O request.  *	This routine must be called once and only once for each  *	I/O control block who has had I/O associated with it.  */
end_comment

begin_function_decl
name|ssize_t
name|aio_return
parameter_list|(
name|struct
name|aiocb
modifier|*
name|iocb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel I/O -- implemented only to return AIO_NOTCANCELLED or  *	AIO_ALLDONE.  No cancellation operation will occur.  */
end_comment

begin_function_decl
name|int
name|aio_cancel
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|aiocb
modifier|*
name|iocb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Suspend until all specified I/O or timeout is complete.  */
end_comment

begin_function_decl
name|int
name|aio_suspend
parameter_list|(
specifier|const
name|struct
name|aiocb
modifier|*
specifier|const
name|acb_list
index|[]
parameter_list|,
name|int
name|nacb_listent
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|aio_proc_rundown
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

