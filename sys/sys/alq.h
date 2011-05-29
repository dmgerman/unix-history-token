begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, Jeffrey Roberson<jeff@freebsd.org>  * Copyright (c) 2008-2009, Lawrence Stewart<lstewart@freebsd.org>  * Copyright (c) 2010, The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed at the Centre for Advanced  * Internet Architectures, Swinburne University of Technology, Melbourne,  * Australia by Lawrence Stewart under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
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
name|intptr_t
name|ae_bytesused
decl_stmt|;
comment|/* # bytes written to ALE. */
name|char
modifier|*
name|ae_data
decl_stmt|;
comment|/* Write ptr. */
name|int
name|ae_pad
decl_stmt|;
comment|/* Unused, compat. */
block|}
struct|;
end_struct

begin_comment
comment|/* Flag options. */
end_comment

begin_define
define|#
directive|define
name|ALQ_NOWAIT
value|0x0001
end_define

begin_comment
comment|/* ALQ may not sleep. */
end_comment

begin_define
define|#
directive|define
name|ALQ_WAITOK
value|0x0002
end_define

begin_comment
comment|/* ALQ may sleep. */
end_comment

begin_define
define|#
directive|define
name|ALQ_NOACTIVATE
value|0x0004
end_define

begin_comment
comment|/* Don't activate ALQ after write. */
end_comment

begin_define
define|#
directive|define
name|ALQ_ORDERED
value|0x0010
end_define

begin_comment
comment|/* Maintain write ordering between threads. */
end_comment

begin_comment
comment|/* Suggested mode for file creation. */
end_comment

begin_define
define|#
directive|define
name|ALQ_DEFAULT_CMODE
value|0600
end_define

begin_comment
comment|/*  * alq_open_flags:  Creates a new queue  *  * Arguments:  *	alq	Storage for a pointer to the newly created queue.  *	file	The filename to open for logging.  *	cred	Credential to authorize open and I/O with.  *	cmode	Creation mode for file, if new.  *	size	The size of the queue in bytes.  *	flags	ALQ_ORDERED  * Returns:  *	error from open or 0 on success  */
end_comment

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|alq_open_flags
parameter_list|(
name|struct
name|alq
modifier|*
modifier|*
name|alqp
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
name|cmode
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alq_open
parameter_list|(
name|struct
name|alq
modifier|*
modifier|*
name|alqp
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
name|cmode
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
comment|/*  * alq_writen:  Write data into the queue  *  * Arguments:  *	alq	The queue we're writing to  *	data	The entry to be recorded  *	len	The number of bytes to write from *data  *	flags	(ALQ_NOWAIT || ALQ_WAITOK), ALQ_NOACTIVATE  *  * Returns:  *	EWOULDBLOCK if:  *		Waitok is ALQ_NOWAIT and the queue is full.  *		The system is shutting down.  *	0 on success.  */
end_comment

begin_function_decl
name|int
name|alq_writen
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
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

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
name|flags
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
comment|/*  * alq_getn:  Return an entry for direct access  *  * Arguments:  *	alq	The queue to retrieve an entry from  *	len	Max number of bytes required  *	flags	(ALQ_NOWAIT || ALQ_WAITOK)  *  * Returns:  *	The next available ale on success.  *	NULL if:  *		flags is ALQ_NOWAIT and the queue is full.  *		The system is shutting down.  *  * This leaves the queue locked until a subsequent alq_post.  */
end_comment

begin_function_decl
name|struct
name|ale
modifier|*
name|alq_getn
parameter_list|(
name|struct
name|alq
modifier|*
name|alq
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

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
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * alq_post_flags:  Schedule the ale retrieved by alq_get/alq_getn for writing.  *	alq	The queue to post the entry to.  *	ale	An asynch logging entry returned by alq_get.  *	flags	ALQ_NOACTIVATE  */
end_comment

begin_function_decl
name|void
name|alq_post_flags
parameter_list|(
name|struct
name|alq
modifier|*
name|alq
parameter_list|,
name|struct
name|ale
modifier|*
name|ale
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|alq_post
parameter_list|(
name|struct
name|alq
modifier|*
name|alq
parameter_list|,
name|struct
name|ale
modifier|*
name|ale
parameter_list|)
block|{
name|alq_post_flags
argument_list|(
name|alq
argument_list|,
name|ale
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ALQ_H_ */
end_comment

end_unit

