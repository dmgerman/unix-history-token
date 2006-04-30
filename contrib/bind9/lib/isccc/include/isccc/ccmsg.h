begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ccmsg.h,v 1.3.206.1 2004/03/06 08:15:21 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_CCMSG_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_CCMSG_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/socket.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|isccc_ccmsg
block|{
comment|/* private (don't touch!) */
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_uint32_t
name|size
decl_stmt|;
name|isc_buffer_t
name|buffer
decl_stmt|;
name|unsigned
name|int
name|maxsize
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_socket_t
modifier|*
name|sock
decl_stmt|;
name|isc_task_t
modifier|*
name|task
decl_stmt|;
name|isc_taskaction_t
name|action
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|isc_event_t
name|event
decl_stmt|;
comment|/* public (read-only) */
name|isc_result_t
name|result
decl_stmt|;
name|isc_sockaddr_t
name|address
decl_stmt|;
block|}
name|isccc_ccmsg_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isccc_ccmsg_init
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isccc_ccmsg_t
modifier|*
name|ccmsg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Associate a cc message state with a given memory context and  * TCP socket.  *  * Requires:  *  *	"mctx" and "sock" be non-NULL and valid types.  *  *	"sock" be a read/write TCP socket.  *  *	"ccmsg" be non-NULL and an uninitialized or invalidated structure.  *  * Ensures:  *  *	"ccmsg" is a valid structure.  */
end_comment

begin_function_decl
name|void
name|isccc_ccmsg_setmaxsize
parameter_list|(
name|isccc_ccmsg_t
modifier|*
name|ccmsg
parameter_list|,
name|unsigned
name|int
name|maxsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the maximum packet size to "maxsize"  *  * Requires:  *  *	"ccmsg" be valid.  *  *	512<= "maxsize"<= 4294967296  */
end_comment

begin_function_decl
name|isc_result_t
name|isccc_ccmsg_readmessage
parameter_list|(
name|isccc_ccmsg_t
modifier|*
name|ccmsg
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Schedule an event to be delivered when a command channel message is  * readable, or when an error occurs on the socket.  *  * Requires:  *  *	"ccmsg" be valid.  *  *	"task", "taskaction", and "arg" be valid.  *  * Returns:  *  *	ISC_R_SUCCESS		-- no error  *	Anything that the isc_socket_recv() call can return.  XXXMLG  *  * Notes:  *  *	The event delivered is a fully generic event.  It will contain no  *	actual data.  The sender will be a pointer to the isccc_ccmsg_t.  *	The result code inside that structure should be checked to see  *	what the final result was.  */
end_comment

begin_function_decl
name|void
name|isccc_ccmsg_cancelread
parameter_list|(
name|isccc_ccmsg_t
modifier|*
name|ccmsg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel a readmessage() call.  The event will still be posted with a  * CANCELED result code.  *  * Requires:  *  *	"ccmsg" be valid.  */
end_comment

begin_function_decl
name|void
name|isccc_ccmsg_invalidate
parameter_list|(
name|isccc_ccmsg_t
modifier|*
name|ccmsg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Clean up all allocated state, and invalidate the structure.  *  * Requires:  *  *	"ccmsg" be valid.  *  * Ensures:  *  *	"ccmsg" is invalidated and disassociated with all memory contexts,  *	sockets, etc.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCC_CCMSG_H */
end_comment

end_unit

