begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ALQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ALQ_H_
end_define

begin_comment
comment|/*  * Opaque type for the Async. Logging Queue  */
end_comment

begin_struct_decl
struct_decl|struct
name|alq
struct_decl|;
end_struct_decl

begin_comment
comment|/* The thread for the logging daemon */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thread
modifier|*
name|ald_thread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Async. Logging Entry  */
end_comment

begin_struct
struct|struct
name|ale
block|{
name|struct
name|ale
modifier|*
name|ae_next
decl_stmt|;
comment|/* Next Entry */
name|char
modifier|*
name|ae_data
decl_stmt|;
comment|/* Entry buffer */
name|int
name|ae_flags
decl_stmt|;
comment|/* Entry flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AE_VALID
value|0x0001
end_define

begin_comment
comment|/* Entry has valid data */
end_comment

begin_comment
comment|/* waitok options */
end_comment

begin_define
define|#
directive|define
name|ALQ_NOWAIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALQ_WAITOK
value|0x0002
end_define

begin_comment
comment|/*  * alq_open:  Creates a new queue  *  * Arguments:  *	alq	Storage for a pointer to the newly created queue.  *	file	The filename to open for logging.  *	size	The size of each entry in the queue.  *	count	The number of items in the buffer, this should be large enough  *		to store items over the period of a disk write.  * Returns:  *	error from open or 0 on success  */
end_comment

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|alq_open
parameter_list|(
name|struct
name|alq
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * alq_write:  Write data into the queue  *  * Arguments:  *	alq	The queue we're writing to  *	data	The entry to be recorded  *	waitok	Are we permitted to wait?  *  * Returns:  *	EWOULDBLOCK if:  *		Waitok is ALQ_NOWAIT and the queue is full.  *		The system is shutting down.  *	0 on success.  */
end_comment

begin_function_decl
name|int
name|alq_write
parameter_list|(
name|struct
name|alq
modifier|*
name|alq
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|waitok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * alq_flush:  Flush the queue out to disk  */
end_comment

begin_function_decl
name|void
name|alq_flush
parameter_list|(
name|struct
name|alq
modifier|*
name|alq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * alq_close:  Flush the queue and free all resources.  */
end_comment

begin_function_decl
name|void
name|alq_close
parameter_list|(
name|struct
name|alq
modifier|*
name|alq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * alq_get:  Return an entry for direct access  *  * Arguments:  *	alq	The queue to retrieve an entry from  *	waitok	Are we permitted to wait?  *  * Returns:  *	The next available ale on success.  *	NULL if:  *		Waitok is ALQ_NOWAIT and the queue is full.  *		The system is shutting down.  *  * This leaves the queue locked until a subsequent alq_post.  */
end_comment

begin_function_decl
name|struct
name|ale
modifier|*
name|alq_get
parameter_list|(
name|struct
name|alq
modifier|*
name|alq
parameter_list|,
name|int
name|waitok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * alq_post:  Schedule the ale retrieved by alq_get for writing.  *	alq	The queue to post the entry to.  *	ale	An asynch logging entry returned by alq_get.  */
end_comment

begin_function_decl
name|void
name|alq_post
parameter_list|(
name|struct
name|alq
modifier|*
parameter_list|,
name|struct
name|ale
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ALQ_H_ */
end_comment

end_unit

