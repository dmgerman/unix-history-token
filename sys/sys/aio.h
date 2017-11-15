begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 John S. Dyson.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. John S. Dyson's name may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * DISCLAIMER:  This code isn't warranted to do anything useful.  Anything  * bad that happens because of using this software isn't the responsibility  * of the author.  This software is distributed AS-IS.  *  * $FreeBSD$  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|LIO_SYNC
value|0x3
end_define

begin_define
define|#
directive|define
name|LIO_MLOCK
value|0x4
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Default values of tunables for the AIO worker pool. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_AIO_PROCS
end_ifndef

begin_define
define|#
directive|define
name|MAX_AIO_PROCS
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_AIO_PROCS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_AIO_PROCS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AIOD_LIFETIME_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|AIOD_LIFETIME_DEFAULT
value|(30 * hz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|__spare__
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|__spare2__
decl_stmt|;
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
name|struct
name|sigevent
name|aio_sigevent
decl_stmt|;
comment|/* Signal to deliver */
block|}
name|aiocb_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|void
name|aio_cancel_fn_t
parameter_list|(
name|struct
name|kaiocb
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|aio_handle_fn_t
parameter_list|(
name|struct
name|kaiocb
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Kernel version of an I/O control block.  *  * Locking key:  * * - need not protected  * a - locked by kaioinfo lock  * b - locked by backend lock  * c - locked by aio_job_mtx  */
end_comment

begin_struct
struct|struct
name|kaiocb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|kaiocb
argument_list|)
name|list
expr_stmt|;
comment|/* (b) backend-specific list of jobs */
name|TAILQ_ENTRY
argument_list|(
argument|kaiocb
argument_list|)
name|plist
expr_stmt|;
comment|/* (a) lists of pending / done jobs */
name|TAILQ_ENTRY
argument_list|(
argument|kaiocb
argument_list|)
name|allist
expr_stmt|;
comment|/* (a) list of all jobs in proc */
name|int
name|jobflags
decl_stmt|;
comment|/* (a) job flags */
name|int
name|inblock
decl_stmt|;
comment|/* (*) input blocks */
name|int
name|outblock
decl_stmt|;
comment|/* (*) output blocks */
name|int
name|msgsnd
decl_stmt|;
comment|/* (*) messages sent */
name|int
name|msgrcv
decl_stmt|;
comment|/* (*) messages received */
name|struct
name|proc
modifier|*
name|userproc
decl_stmt|;
comment|/* (*) user process */
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
comment|/* (*) active credential when created */
name|struct
name|file
modifier|*
name|fd_file
decl_stmt|;
comment|/* (*) pointer to file structure */
name|struct
name|aioliojob
modifier|*
name|lio
decl_stmt|;
comment|/* (*) optional lio job */
name|struct
name|aiocb
modifier|*
name|ujob
decl_stmt|;
comment|/* (*) pointer in userspace of aiocb */
name|struct
name|knlist
name|klist
decl_stmt|;
comment|/* (a) list of knotes */
name|struct
name|aiocb
name|uaiocb
decl_stmt|;
comment|/* (*) copy of user I/O control block */
name|ksiginfo_t
name|ksi
decl_stmt|;
comment|/* (a) realtime signal info */
name|uint64_t
name|seqno
decl_stmt|;
comment|/* (*) job number */
name|aio_cancel_fn_t
modifier|*
name|cancel_fn
decl_stmt|;
comment|/* (a) backend cancel function */
name|aio_handle_fn_t
modifier|*
name|handle_fn
decl_stmt|;
comment|/* (c) backend handle function */
union|union
block|{
comment|/* Backend-specific data fields */
struct|struct
block|{
comment|/* BIO backend */
name|struct
name|bio
modifier|*
name|bp
decl_stmt|;
comment|/* (*) BIO pointer */
name|struct
name|buf
modifier|*
name|pbuf
decl_stmt|;
comment|/* (*) buffer pointer */
name|struct
name|vm_page
modifier|*
name|pages
index|[
name|btoc
argument_list|(
name|MAXPHYS
argument_list|)
operator|+
literal|1
index|]
decl_stmt|;
comment|/* (*) */
name|int
name|npages
decl_stmt|;
comment|/* (*) number of pages */
block|}
struct|;
struct|struct
block|{
comment|/* fsync() requests */
name|int
name|pending
decl_stmt|;
comment|/* (a) number of pending I/O */
block|}
struct|;
struct|struct
block|{
name|void
modifier|*
name|backend1
decl_stmt|;
name|void
modifier|*
name|backend2
decl_stmt|;
name|long
name|backend3
decl_stmt|;
name|int
name|backend4
decl_stmt|;
block|}
struct|;
block|}
union|;
block|}
struct|;
end_struct

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

begin_comment
comment|/*  * AIO backends should permit cancellation of queued requests waiting to  * be serviced by installing a cancel routine while the request is  * queued.  The cancellation routine should dequeue the request if  * necessary and cancel it.  Care must be used to handle races between  * queueing and dequeueing requests and cancellation.  *  * When queueing a request somewhere such that it can be cancelled, the  * caller should:  *  *  1) Acquire lock that protects the associated queue.  *  2) Call aio_set_cancel_function() to install the cancel routine.  *  3) If that fails, the request has a pending cancel and should be  *     cancelled via aio_cancel().  *  4) Queue the request.  *  * When dequeueing a request to service it or hand it off to somewhere else,  * the caller should:  *  *  1) Acquire the lock that protects the associated queue.  *  2) Dequeue the request.  *  3) Call aio_clear_cancel_function() to clear the cancel routine.  *  4) If that fails, the cancel routine is about to be called.  The  *     caller should ignore the request.  *  * The cancel routine should:  *  *  1) Acquire the lock that protects the associated queue.  *  2) Call aio_cancel_cleared() to determine if the request is already  *     dequeued due to a race with dequeueing thread.  *  3) If that fails, dequeue the request.  *  4) Cancel the request via aio_cancel().  */
end_comment

begin_function_decl
name|bool
name|aio_cancel_cleared
parameter_list|(
name|struct
name|kaiocb
modifier|*
name|job
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aio_cancel
parameter_list|(
name|struct
name|kaiocb
modifier|*
name|job
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|aio_clear_cancel_function
parameter_list|(
name|struct
name|kaiocb
modifier|*
name|job
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aio_complete
parameter_list|(
name|struct
name|kaiocb
modifier|*
name|job
parameter_list|,
name|long
name|status
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aio_schedule
parameter_list|(
name|struct
name|kaiocb
modifier|*
name|job
parameter_list|,
name|aio_handle_fn_t
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|aio_set_cancel_function
parameter_list|(
name|struct
name|kaiocb
modifier|*
name|job
parameter_list|,
name|aio_cancel_fn_t
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aio_switch_vmspace
parameter_list|(
name|struct
name|kaiocb
modifier|*
name|job
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

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

begin_function_decl
name|int
name|lio_listio
parameter_list|(
name|int
parameter_list|,
name|struct
name|aiocb
modifier|*
name|__restrict
specifier|const
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|struct
name|sigevent
modifier|*
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
comment|/*  * Cancel I/O  */
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

begin_comment
comment|/*  * Asynchronous mlock  */
end_comment

begin_function_decl
name|int
name|aio_mlock
parameter_list|(
name|struct
name|aiocb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|ssize_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|aio_fsync
parameter_list|(
name|int
name|op
parameter_list|,
name|struct
name|aiocb
modifier|*
name|aiocbp
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_AIO_H_ */
end_comment

end_unit

