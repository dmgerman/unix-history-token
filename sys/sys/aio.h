begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 John S. Dyson.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. John S. Dyson's name may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * DISCLAIMER:  This code isn't warranted to do anything useful.  Anything  * bad that happens because of using this software isn't the responsibility  * of the author.  This software is distributed AS-IS.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_AIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_AIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_comment
comment|/*  * Returned by aio_cancel:  */
end_comment

begin_define
define|#
directive|define
name|AIO_CANCELED
value|0x1
end_define

begin_define
define|#
directive|define
name|AIO_NOTCANCELED
value|0x2
end_define

begin_define
define|#
directive|define
name|AIO_ALLDONE
value|0x3
end_define

begin_comment
comment|/*  * LIO opcodes  */
end_comment

begin_define
define|#
directive|define
name|LIO_NOP
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_WRITE
value|0x1
end_define

begin_define
define|#
directive|define
name|LIO_READ
value|0x2
end_define

begin_comment
comment|/*  * LIO modes  */
end_comment

begin_define
define|#
directive|define
name|LIO_NOWAIT
value|0x0
end_define

begin_define
define|#
directive|define
name|LIO_WAIT
value|0x1
end_define

begin_comment
comment|/*  * Maximum number of allowed LIO operations  */
end_comment

begin_define
define|#
directive|define
name|AIO_LISTIO_MAX
value|16
end_define

begin_comment
comment|/*  * Private members for aiocb -- don't access  * directly.  */
end_comment

begin_struct
struct|struct
name|__aiocb_private
block|{
name|long
name|status
decl_stmt|;
name|long
name|error
decl_stmt|;
name|void
modifier|*
name|kernelinfo
decl_stmt|;
block|}
struct|;
end_struct

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
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Asynchronously read from a file  */
name|int
name|aio_read
parameter_list|(
name|struct
name|aiocb
modifier|*
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * List I/O Asynchronously/synchronously read/write to/from file  *	"lio_mode" specifies whether or not the I/O is synchronous.  *	"acb_list" is an array of "nacb_listent" I/O control blocks.  *	when all I/Os are complete, the optional signal "sig" is sent.  */
end_comment

begin_decl_stmt
name|int
name|lio_listio
argument_list|(
name|int
argument_list|,
expr|struct
name|aiocb
operator|*
specifier|const
index|[]
argument_list|,
name|int
argument_list|,
expr|struct
name|sigevent
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|struct
name|aiocb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Suspend until all specified I/O or timeout is complete.  */
end_comment

begin_decl_stmt
name|int
name|aio_suspend
argument_list|(
specifier|const
expr|struct
name|aiocb
operator|*
specifier|const
index|[]
argument_list|,
name|int
argument_list|,
specifier|const
expr|struct
name|timespec
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|aio_waitcomplete
parameter_list|(
name|struct
name|aiocb
modifier|*
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Job queue item  */
end_comment

begin_define
define|#
directive|define
name|AIOCBLIST_CANCELLED
value|0x1
end_define

begin_define
define|#
directive|define
name|AIOCBLIST_RUNDOWN
value|0x4
end_define

begin_define
define|#
directive|define
name|AIOCBLIST_ASYNCFREE
value|0x8
end_define

begin_define
define|#
directive|define
name|AIOCBLIST_DONE
value|0x10
end_define

begin_struct
struct|struct
name|aiocblist
block|{
name|TAILQ_ENTRY
argument_list|(
argument|aiocblist
argument_list|)
name|list
expr_stmt|;
comment|/* List of jobs */
name|TAILQ_ENTRY
argument_list|(
argument|aiocblist
argument_list|)
name|plist
expr_stmt|;
comment|/* List of jobs for proc */
name|int
name|jobflags
decl_stmt|;
name|int
name|jobstate
decl_stmt|;
name|int
name|inputcharge
decl_stmt|,
name|outputcharge
decl_stmt|;
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* Buffer pointer */
name|struct
name|proc
modifier|*
name|userproc
decl_stmt|;
comment|/* User process */
name|struct
name|file
modifier|*
name|fd_file
decl_stmt|;
comment|/* Pointer to file structure */
name|struct
name|aioproclist
modifier|*
name|jobaioproc
decl_stmt|;
comment|/* AIO process descriptor */
name|struct
name|aio_liojob
modifier|*
name|lio
decl_stmt|;
comment|/* Optional lio job */
name|struct
name|aiocb
modifier|*
name|uuaiocb
decl_stmt|;
comment|/* Pointer in userspace of aiocb */
name|struct
name|klist
name|klist
decl_stmt|;
comment|/* list of knotes */
name|struct
name|aiocb
name|uaiocb
decl_stmt|;
comment|/* Kernel I/O control block */
block|}
struct|;
end_struct

begin_comment
comment|/* Forward declarations for prototypes below. */
end_comment

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockbuf
struct_decl|;
end_struct_decl

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

begin_function_decl
name|void
name|aio_swake
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockbuf
modifier|*
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

