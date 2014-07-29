begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/tube.h - pipe service  *  * Copyright (c) 2008, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains pipe service functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_TUBE_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_TUBE_H
end_define

begin_struct_decl
struct_decl|struct
name|comm_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_point
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_base
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tube
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tube_res_list
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WINSOCK
end_ifdef

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_include
include|#
directive|include
file|"util/winsock_event.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Callback from pipe listen function  * void mycallback(tube, msg, len, error, user_argument);  * if error is true (NETEVENT_*), msg is probably NULL.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|tube_callback_t
parameter_list|(
name|struct
name|tube
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * A pipe  */
end_comment

begin_struct
struct|struct
name|tube
block|{
ifndef|#
directive|ifndef
name|USE_WINSOCK
comment|/** pipe end to read from */
name|int
name|sr
decl_stmt|;
comment|/** pipe end to write on */
name|int
name|sw
decl_stmt|;
comment|/** listen commpoint */
name|struct
name|comm_point
modifier|*
name|listen_com
decl_stmt|;
comment|/** listen callback */
name|tube_callback_t
modifier|*
name|listen_cb
decl_stmt|;
comment|/** listen callback user arg */
name|void
modifier|*
name|listen_arg
decl_stmt|;
comment|/** are we currently reading a command, 0 if not, else bytecount */
name|size_t
name|cmd_read
decl_stmt|;
comment|/** size of current read command, may be partially read */
name|uint32_t
name|cmd_len
decl_stmt|;
comment|/** the current read command content, malloced, can be partially read*/
name|uint8_t
modifier|*
name|cmd_msg
decl_stmt|;
comment|/** background write queue, commpoint to write results back */
name|struct
name|comm_point
modifier|*
name|res_com
decl_stmt|;
comment|/** are we curently writing a result, 0 if not, else bytecount into 	 * the res_list first entry. */
name|size_t
name|res_write
decl_stmt|;
comment|/** list of outstanding results to be written back */
name|struct
name|tube_res_list
modifier|*
name|res_list
decl_stmt|;
comment|/** last in list */
name|struct
name|tube_res_list
modifier|*
name|res_last
decl_stmt|;
else|#
directive|else
comment|/* USE_WINSOCK */
comment|/** listen callback */
name|tube_callback_t
modifier|*
name|listen_cb
decl_stmt|;
comment|/** listen callback user arg */
name|void
modifier|*
name|listen_arg
decl_stmt|;
comment|/** the windows sockets event (signaled if items in pipe) */
name|WSAEVENT
name|event
decl_stmt|;
comment|/** winsock event storage when registered with event base */
name|struct
name|event
name|ev_listen
decl_stmt|;
comment|/** lock on the list of outstanding items */
name|lock_basic_t
name|res_lock
decl_stmt|;
comment|/** list of outstanding results on pipe */
name|struct
name|tube_res_list
modifier|*
name|res_list
decl_stmt|;
comment|/** last in list */
name|struct
name|tube_res_list
modifier|*
name|res_last
decl_stmt|;
endif|#
directive|endif
comment|/* USE_WINSOCK */
block|}
struct|;
end_struct

begin_comment
comment|/**  * List of results (arbitrary command serializations) to write back  */
end_comment

begin_struct
struct|struct
name|tube_res_list
block|{
comment|/** next in list */
name|struct
name|tube_res_list
modifier|*
name|next
decl_stmt|;
comment|/** serialized buffer to write */
name|uint8_t
modifier|*
name|buf
decl_stmt|;
comment|/** length to write */
name|uint32_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create a pipe  * @return: new tube struct or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|tube
modifier|*
name|tube_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete and destroy a pipe  * @param tube: to delete  */
end_comment

begin_function_decl
name|void
name|tube_delete
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Write length bytes followed by message.  * @param tube: the tube to write on.  *     If that tube is a pipe, its write fd is used as  *     the socket to write on. Is nonblocking.  *      Set to blocking by the function,  *      and back to non-blocking at exit of function.  * @param buf: the message.  * @param len: length of message.  * @param nonblock: if set to true, the first write is nonblocking.  *      If the first write fails the function returns -1.  *      If set false, the first write is blocking.  * @return: all remainder writes are nonblocking.  *      return 0 on error, in that case blocking/nonblocking of socket is  *              unknown.  *      return 1 if all OK.  */
end_comment

begin_function_decl
name|int
name|tube_write_msg
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|len
parameter_list|,
name|int
name|nonblock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read length bytes followed by message.  * @param tube: The tube to read on.  *     If that tube is a pipe, its read fd is used as  *     the socket to read on. Is nonblocking.  *      Set to blocking by the function,  *      and back to non-blocking at exit of function.  * @param buf: the message, malloced.  * @param len: length of message, returned.  * @param nonblock: if set to true, the first read is nonblocking.  *      If the first read fails the function returns -1.  *      If set false, the first read is blocking.  * @return: all remainder reads are nonblocking.  *      return 0 on error, in that case blocking/nonblocking of socket is   *              unknown. On EOF 0 is returned.  *      return 1 if all OK.  */
end_comment

begin_function_decl
name|int
name|tube_read_msg
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|buf
parameter_list|,
name|uint32_t
modifier|*
name|len
parameter_list|,
name|int
name|nonblock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Close read part of the pipe.  * The tube can no longer be read from.  * @param tube: tube to operate on.  */
end_comment

begin_function_decl
name|void
name|tube_close_read
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Close write part of the pipe.  * The tube can no longer be written to.  * @param tube: tube to operate on.  */
end_comment

begin_function_decl
name|void
name|tube_close_write
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if data is ready for reading on the tube without blocking.  * @param tube: tube to check for readable items  * @return true if readable items are present. False if not (or error).  *     true on pipe_closed.  */
end_comment

begin_function_decl
name|int
name|tube_poll
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Wait for data to be ready for reading on the tube. is blocking.  * No timeout.  * @param tube: the tube to wait on.  * @return: if there was something to read (false on error).  *     true on pipe_closed.  */
end_comment

begin_function_decl
name|int
name|tube_wait
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get FD that is readable when new information arrives.  * @param tube  * @return file descriptor.  */
end_comment

begin_function_decl
name|int
name|tube_read_fd
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Start listening for information over the pipe.  * Background registration of a read listener, callback when read completed.  * Do not mix with tube_read_msg style direct reads from the pipe.  * @param tube: tube to listen on  * @param base: what base to register event callback.  * @param cb: callback routine.  * @param arg: user argument for callback routine.  * @return true if successful, false on error.  */
end_comment

begin_function_decl
name|int
name|tube_setup_bg_listen
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|,
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|tube_callback_t
modifier|*
name|cb
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove bg listen setup from event base.  * @param tube: what tube to cleanup  */
end_comment

begin_function_decl
name|void
name|tube_remove_bg_listen
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Start background write handler for the pipe.  * Do not mix with tube_write_msg style direct writes to the pipe.  * @param tube: tube to write on  * @param base: what base to register event handler on.  * @return true if successful, false on error.  */
end_comment

begin_function_decl
name|int
name|tube_setup_bg_write
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|,
name|struct
name|comm_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove bg write setup from event base.  * @param tube: what tube to cleanup  */
end_comment

begin_function_decl
name|void
name|tube_remove_bg_write
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Append data item to background list of writes.  * Mallocs a list entry behind the scenes.  * Not locked behind the scenes, call from one thread or lock on outside.  * @param tube: what tube to queue on.  * @param msg: memory message to send. Is free()d after use.  * 	Put at the end of the to-send queue.  * @param len: length of item.  * @return 0 on failure (msg freed).  */
end_comment

begin_function_decl
name|int
name|tube_queue_item
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|,
name|uint8_t
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** for fptr wlist, callback function */
end_comment

begin_function_decl
name|int
name|tube_handle_listen
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|error
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|reply_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** for fptr wlist, callback function */
end_comment

begin_function_decl
name|int
name|tube_handle_write
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|error
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|reply_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** for fptr wlist, winsock signal event callback function */
end_comment

begin_function_decl
name|void
name|tube_handle_signal
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|events
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_TUBE_H */
end_comment

end_unit

