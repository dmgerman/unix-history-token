begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_H_
end_ifndef

begin_define
define|#
directive|define
name|VCHI_H_
end_define

begin_include
include|#
directive|include
file|"interface/vchi/vchi_cfg.h"
end_include

begin_include
include|#
directive|include
file|"interface/vchi/vchi_common.h"
end_include

begin_include
include|#
directive|include
file|"interface/vchi/connections/connection.h"
end_include

begin_include
include|#
directive|include
file|"vchi_mh.h"
end_include

begin_comment
comment|/******************************************************************************  Global defs  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|VCHI_BULK_ROUND_UP
parameter_list|(
name|x
parameter_list|)
value|((((unsigned long)(x))+VCHI_BULK_ALIGN-1)& ~(VCHI_BULK_ALIGN-1))
end_define

begin_define
define|#
directive|define
name|VCHI_BULK_ROUND_DOWN
parameter_list|(
name|x
parameter_list|)
value|(((unsigned long)(x))& ~(VCHI_BULK_ALIGN-1))
end_define

begin_define
define|#
directive|define
name|VCHI_BULK_ALIGN_NBYTES
parameter_list|(
name|x
parameter_list|)
value|(VCHI_BULK_ALIGNED(x) ? 0 : (VCHI_BULK_ALIGN - ((unsigned long)(x)& (VCHI_BULK_ALIGN-1))))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_VCHIQ_ARM
end_ifdef

begin_define
define|#
directive|define
name|VCHI_BULK_ALIGNED
parameter_list|(
name|x
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VCHI_BULK_ALIGNED
parameter_list|(
name|x
parameter_list|)
value|(((unsigned long)(x)& (VCHI_BULK_ALIGN-1)) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vchi_version
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|version_min
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VCHI_VERSION
parameter_list|(
name|v_
parameter_list|)
value|{ v_, v_ }
end_define

begin_define
define|#
directive|define
name|VCHI_VERSION_EX
parameter_list|(
name|v_
parameter_list|,
name|m_
parameter_list|)
value|{ v_, m_ }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|VCHI_VEC_POINTER
block|,
name|VCHI_VEC_HANDLE
block|,
name|VCHI_VEC_LIST
block|}
name|VCHI_MSG_VECTOR_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchi_msg_vector_ex
block|{
name|VCHI_MSG_VECTOR_TYPE_T
name|type
decl_stmt|;
union|union
block|{
comment|// a memory handle
struct|struct
block|{
name|VCHI_MEM_HANDLE_T
name|handle
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|int32_t
name|vec_len
decl_stmt|;
block|}
name|handle
struct|;
comment|// an ordinary data pointer
struct|struct
block|{
specifier|const
name|void
modifier|*
name|vec_base
decl_stmt|;
name|int32_t
name|vec_len
decl_stmt|;
block|}
name|ptr
struct|;
comment|// a nested vector list
struct|struct
block|{
name|struct
name|vchi_msg_vector_ex
modifier|*
name|vec
decl_stmt|;
name|uint32_t
name|vec_len
decl_stmt|;
block|}
name|list
struct|;
block|}
name|u
union|;
block|}
name|VCHI_MSG_VECTOR_EX_T
typedef|;
end_typedef

begin_comment
comment|// Construct an entry in a msg vector for a pointer (p) of length (l)
end_comment

begin_define
define|#
directive|define
name|VCHI_VEC_POINTER
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|VCHI_VEC_POINTER, { { (VCHI_MEM_HANDLE_T)(p), (l) } }
end_define

begin_comment
comment|// Construct an entry in a msg vector for a message handle (h), starting at offset (o) of length (l)
end_comment

begin_define
define|#
directive|define
name|VCHI_VEC_HANDLE
parameter_list|(
name|h
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|)
value|VCHI_VEC_HANDLE,  { { (h), (o), (l) } }
end_define

begin_comment
comment|// Macros to manipulate 'FOURCC' values
end_comment

begin_define
define|#
directive|define
name|MAKE_FOURCC
parameter_list|(
name|x
parameter_list|)
value|((int32_t)( (x[0]<< 24) | (x[1]<< 16) | (x[2]<< 8) | x[3] ))
end_define

begin_define
define|#
directive|define
name|FOURCC_TO_CHAR
parameter_list|(
name|x
parameter_list|)
value|(x>> 24)& 0xFF,(x>> 16)& 0xFF,(x>> 8)& 0xFF, x& 0xFF
end_define

begin_comment
comment|// Opaque service information
end_comment

begin_struct_decl
struct_decl|struct
name|opaque_vchi_service_t
struct_decl|;
end_struct_decl

begin_comment
comment|// Descriptor for a held message. Allocated by client, initialised by vchi_msg_hold,
end_comment

begin_comment
comment|// vchi_msg_iter_hold or vchi_msg_iter_hold_next. Fields are for internal VCHI use only.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|opaque_vchi_service_t
modifier|*
name|service
decl_stmt|;
name|void
modifier|*
name|message
decl_stmt|;
block|}
name|VCHI_HELD_MSG_T
typedef|;
end_typedef

begin_comment
comment|// structure used to provide the information needed to open a server or a client
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|vchi_version
name|version
decl_stmt|;
name|int32_t
name|service_id
decl_stmt|;
name|VCHI_CONNECTION_T
modifier|*
name|connection
decl_stmt|;
name|uint32_t
name|rx_fifo_size
decl_stmt|;
name|uint32_t
name|tx_fifo_size
decl_stmt|;
name|VCHI_CALLBACK_T
name|callback
decl_stmt|;
name|void
modifier|*
name|callback_param
decl_stmt|;
comment|/* client intends to receive bulk transfers of 		odd lengths or into unaligned buffers */
name|int32_t
name|want_unaligned_bulk_rx
decl_stmt|;
comment|/* client intends to transmit bulk transfers of 		odd lengths or out of unaligned buffers */
name|int32_t
name|want_unaligned_bulk_tx
decl_stmt|;
comment|/* client wants to check CRCs on (bulk) xfers. 		Only needs to be set at 1 end - will do both directions. */
name|int32_t
name|want_crc
decl_stmt|;
block|}
name|SERVICE_CREATION_T
typedef|;
end_typedef

begin_comment
comment|// Opaque handle for a VCHI instance
end_comment

begin_typedef
typedef|typedef
name|struct
name|opaque_vchi_instance_handle_t
modifier|*
name|VCHI_INSTANCE_T
typedef|;
end_typedef

begin_comment
comment|// Opaque handle for a server or client
end_comment

begin_typedef
typedef|typedef
name|struct
name|opaque_vchi_service_handle_t
modifier|*
name|VCHI_SERVICE_HANDLE_T
typedef|;
end_typedef

begin_comment
comment|// Service registration& startup
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_SERVICE_INIT
function_decl|)
parameter_list|(
name|VCHI_INSTANCE_T
name|initialise_instance
parameter_list|,
name|VCHI_CONNECTION_T
modifier|*
modifier|*
name|connections
parameter_list|,
name|uint32_t
name|num_connections
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|service_info_tag
block|{
specifier|const
name|char
modifier|*
specifier|const
name|vll_filename
decl_stmt|;
comment|/* VLL to load to start this service. This is an empty string if VLL is "static" */
name|VCHI_SERVICE_INIT
name|init
decl_stmt|;
comment|/* Service initialisation function */
name|void
modifier|*
name|vll_handle
decl_stmt|;
comment|/* VLL handle; NULL when unloaded or a "static VLL" in build */
block|}
name|SERVICE_INFO_T
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  Global funcs - implementation is specific to which side you are on (local / remote)  *****************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
comment|/*@observer@*/
name|VCHI_CONNECTION_T
modifier|*
name|vchi_create_connection
parameter_list|(
specifier|const
name|VCHI_CONNECTION_API_T
modifier|*
name|function_table
parameter_list|,
specifier|const
name|VCHI_MESSAGE_DRIVER_T
modifier|*
name|low_level
parameter_list|)
function_decl|;
comment|// Routine used to initialise the vchi on both local + remote connections
specifier|extern
name|int32_t
name|vchi_initialise
parameter_list|(
name|VCHI_INSTANCE_T
modifier|*
name|instance_handle
parameter_list|)
function_decl|;
specifier|extern
name|int32_t
name|vchi_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int32_t
name|vchi_connect
parameter_list|(
name|VCHI_CONNECTION_T
modifier|*
modifier|*
name|connections
parameter_list|,
specifier|const
name|uint32_t
name|num_connections
parameter_list|,
name|VCHI_INSTANCE_T
name|instance_handle
parameter_list|)
function_decl|;
comment|//When this is called, ensure that all services have no data pending.
comment|//Bulk transfers can remain 'queued'
specifier|extern
name|int32_t
name|vchi_disconnect
parameter_list|(
name|VCHI_INSTANCE_T
name|instance_handle
parameter_list|)
function_decl|;
comment|// Global control over bulk CRC checking
specifier|extern
name|int32_t
name|vchi_crc_control
parameter_list|(
name|VCHI_CONNECTION_T
modifier|*
name|connection
parameter_list|,
name|VCHI_CRC_CONTROL_T
name|control
parameter_list|)
function_decl|;
comment|// helper functions
specifier|extern
name|void
modifier|*
name|vchi_allocate_buffer
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|uint32_t
modifier|*
name|length
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vchi_free_buffer
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|void
modifier|*
name|address
parameter_list|)
function_decl|;
specifier|extern
name|uint32_t
name|vchi_current_time
parameter_list|(
name|VCHI_INSTANCE_T
name|instance_handle
parameter_list|)
function_decl|;
comment|/******************************************************************************  Global service API  *****************************************************************************/
comment|// Routine to create a named service
specifier|extern
name|int32_t
name|vchi_service_create
parameter_list|(
name|VCHI_INSTANCE_T
name|instance_handle
parameter_list|,
name|SERVICE_CREATION_T
modifier|*
name|setup
parameter_list|,
name|VCHI_SERVICE_HANDLE_T
modifier|*
name|handle
parameter_list|)
function_decl|;
comment|// Routine to destory a service
specifier|extern
name|int32_t
name|vchi_service_destroy
parameter_list|(
specifier|const
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|)
function_decl|;
comment|// Routine to open a named service
specifier|extern
name|int32_t
name|vchi_service_open
parameter_list|(
name|VCHI_INSTANCE_T
name|instance_handle
parameter_list|,
name|SERVICE_CREATION_T
modifier|*
name|setup
parameter_list|,
name|VCHI_SERVICE_HANDLE_T
modifier|*
name|handle
parameter_list|)
function_decl|;
specifier|extern
name|int32_t
name|vchi_get_peer_version
parameter_list|(
specifier|const
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|short
modifier|*
name|peer_version
parameter_list|)
function_decl|;
comment|// Routine to close a named service
specifier|extern
name|int32_t
name|vchi_service_close
parameter_list|(
specifier|const
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|)
function_decl|;
comment|// Routine to increment ref count on a named service
specifier|extern
name|int32_t
name|vchi_service_use
parameter_list|(
specifier|const
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|)
function_decl|;
comment|// Routine to decrement ref count on a named service
specifier|extern
name|int32_t
name|vchi_service_release
parameter_list|(
specifier|const
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|)
function_decl|;
comment|// Routine to send a message accross a service
specifier|extern
name|int32_t
name|vchi_msg_queue
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|uint32_t
name|data_size
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|void
modifier|*
name|msg_handle
parameter_list|)
function_decl|;
comment|// scatter-gather (vector) and send message
name|int32_t
name|vchi_msg_queuev_ex
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|VCHI_MSG_VECTOR_EX_T
modifier|*
name|vector
parameter_list|,
name|uint32_t
name|count
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|void
modifier|*
name|msg_handle
parameter_list|)
function_decl|;
comment|// legacy scatter-gather (vector) and send message, only handles pointers
name|int32_t
name|vchi_msg_queuev
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|VCHI_MSG_VECTOR_T
modifier|*
name|vector
parameter_list|,
name|uint32_t
name|count
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|void
modifier|*
name|msg_handle
parameter_list|)
function_decl|;
comment|// Routine to receive a msg from a service
comment|// Dequeue is equivalent to hold, copy into client buffer, release
specifier|extern
name|int32_t
name|vchi_msg_dequeue
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|uint32_t
name|max_data_size_to_read
parameter_list|,
name|uint32_t
modifier|*
name|actual_msg_size
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|)
function_decl|;
comment|// Routine to look at a message in place.
comment|// The message is not dequeued, so a subsequent call to peek or dequeue
comment|// will return the same message.
specifier|extern
name|int32_t
name|vchi_msg_peek
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|uint32_t
modifier|*
name|msg_size
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|)
function_decl|;
comment|// Routine to remove a message after it has been read in place with peek
comment|// The first message on the queue is dequeued.
specifier|extern
name|int32_t
name|vchi_msg_remove
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|)
function_decl|;
comment|// Routine to look at a message in place.
comment|// The message is dequeued, so the caller is left holding it; the descriptor is
comment|// filled in and must be released when the user has finished with the message.
specifier|extern
name|int32_t
name|vchi_msg_hold
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|,
comment|// } may be NULL, as info can be
name|uint32_t
modifier|*
name|msg_size
parameter_list|,
comment|// } obtained from HELD_MSG_T
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|VCHI_HELD_MSG_T
modifier|*
name|message_descriptor
parameter_list|)
function_decl|;
comment|// Initialise an iterator to look through messages in place
specifier|extern
name|int32_t
name|vchi_msg_look_ahead
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|)
function_decl|;
comment|/******************************************************************************  Global service support API - operations on held messages and message iterators  *****************************************************************************/
comment|// Routine to get the address of a held message
specifier|extern
name|void
modifier|*
name|vchi_held_msg_ptr
parameter_list|(
specifier|const
name|VCHI_HELD_MSG_T
modifier|*
name|message
parameter_list|)
function_decl|;
comment|// Routine to get the size of a held message
specifier|extern
name|int32_t
name|vchi_held_msg_size
parameter_list|(
specifier|const
name|VCHI_HELD_MSG_T
modifier|*
name|message
parameter_list|)
function_decl|;
comment|// Routine to get the transmit timestamp as written into the header by the peer
specifier|extern
name|uint32_t
name|vchi_held_msg_tx_timestamp
parameter_list|(
specifier|const
name|VCHI_HELD_MSG_T
modifier|*
name|message
parameter_list|)
function_decl|;
comment|// Routine to get the reception timestamp, written as we parsed the header
specifier|extern
name|uint32_t
name|vchi_held_msg_rx_timestamp
parameter_list|(
specifier|const
name|VCHI_HELD_MSG_T
modifier|*
name|message
parameter_list|)
function_decl|;
comment|// Routine to release a held message after it has been processed
specifier|extern
name|int32_t
name|vchi_held_msg_release
parameter_list|(
name|VCHI_HELD_MSG_T
modifier|*
name|message
parameter_list|)
function_decl|;
comment|// Indicates whether the iterator has a next message.
specifier|extern
name|int32_t
name|vchi_msg_iter_has_next
parameter_list|(
specifier|const
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|)
function_decl|;
comment|// Return the pointer and length for the next message and advance the iterator.
specifier|extern
name|int32_t
name|vchi_msg_iter_next
parameter_list|(
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|uint32_t
modifier|*
name|msg_size
parameter_list|)
function_decl|;
comment|// Remove the last message returned by vchi_msg_iter_next.
comment|// Can only be called once after each call to vchi_msg_iter_next.
specifier|extern
name|int32_t
name|vchi_msg_iter_remove
parameter_list|(
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|)
function_decl|;
comment|// Hold the last message returned by vchi_msg_iter_next.
comment|// Can only be called once after each call to vchi_msg_iter_next.
specifier|extern
name|int32_t
name|vchi_msg_iter_hold
parameter_list|(
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|,
name|VCHI_HELD_MSG_T
modifier|*
name|message
parameter_list|)
function_decl|;
comment|// Return information for the next message, and hold it, advancing the iterator.
specifier|extern
name|int32_t
name|vchi_msg_iter_hold_next
parameter_list|(
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|,
comment|// } may be NULL
name|uint32_t
modifier|*
name|msg_size
parameter_list|,
comment|// }
name|VCHI_HELD_MSG_T
modifier|*
name|message
parameter_list|)
function_decl|;
comment|/******************************************************************************  Global bulk API  *****************************************************************************/
comment|// Routine to prepare interface for a transfer from the other side
specifier|extern
name|int32_t
name|vchi_bulk_queue_receive
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|void
modifier|*
name|data_dst
parameter_list|,
name|uint32_t
name|data_size
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|void
modifier|*
name|transfer_handle
parameter_list|)
function_decl|;
comment|// Prepare interface for a transfer from the other side into relocatable memory.
name|int32_t
name|vchi_bulk_queue_receive_reloc
parameter_list|(
specifier|const
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|VCHI_MEM_HANDLE_T
name|h_dst
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|data_size
parameter_list|,
specifier|const
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|void
modifier|*
specifier|const
name|bulk_handle
parameter_list|)
function_decl|;
comment|// Routine to queue up data ready for transfer to the other (once they have signalled they are ready)
specifier|extern
name|int32_t
name|vchi_bulk_queue_transmit
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|void
modifier|*
name|data_src
parameter_list|,
name|uint32_t
name|data_size
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|void
modifier|*
name|transfer_handle
parameter_list|)
function_decl|;
comment|/******************************************************************************  Configuration plumbing  *****************************************************************************/
comment|// function prototypes for the different mid layers (the state info gives the different physical connections)
specifier|extern
specifier|const
name|VCHI_CONNECTION_API_T
modifier|*
name|single_get_func_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|//extern const VCHI_CONNECTION_API_T *local_server_get_func_table( void );
comment|//extern const VCHI_CONNECTION_API_T *local_client_get_func_table( void );
comment|// declare all message drivers here
specifier|const
name|VCHI_MESSAGE_DRIVER_T
modifier|*
name|vchi_mphi_message_driver_func_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int32_t
name|vchi_bulk_queue_transmit_reloc
parameter_list|(
name|VCHI_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|VCHI_MEM_HANDLE_T
name|h_src
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|data_size
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|,
name|void
modifier|*
name|transfer_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VCHI_H_ */
end_comment

begin_comment
comment|/****************************** End of file **********************************/
end_comment

end_unit

