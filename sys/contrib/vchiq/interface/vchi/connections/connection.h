begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONNECTION_H_
end_ifndef

begin_define
define|#
directive|define
name|CONNECTION_H_
end_define

begin_include
include|#
directive|include
file|"interface/vchi/vchi_cfg_internal.h"
end_include

begin_include
include|#
directive|include
file|"interface/vchi/vchi_common.h"
end_include

begin_include
include|#
directive|include
file|"interface/vchi/message_drivers/message.h"
end_include

begin_comment
comment|/******************************************************************************  Global defs  *****************************************************************************/
end_comment

begin_comment
comment|// Opaque handle for a connection / service pair
end_comment

begin_typedef
typedef|typedef
name|struct
name|opaque_vchi_connection_connected_service_handle_t
modifier|*
name|VCHI_CONNECTION_SERVICE_HANDLE_T
typedef|;
end_typedef

begin_comment
comment|// opaque handle to the connection state information
end_comment

begin_typedef
typedef|typedef
name|struct
name|opaque_vchi_connection_info_t
name|VCHI_CONNECTION_STATE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vchi_connection_t
name|VCHI_CONNECTION_T
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  API  *****************************************************************************/
end_comment

begin_comment
comment|// Routine to init a connection with a particular low level driver
end_comment

begin_typedef
typedef|typedef
name|VCHI_CONNECTION_STATE_T
modifier|*
function_decl|(
modifier|*
name|VCHI_CONNECTION_INIT_T
function_decl|)
parameter_list|(
name|struct
name|vchi_connection_t
modifier|*
name|connection
parameter_list|,
specifier|const
name|VCHI_MESSAGE_DRIVER_T
modifier|*
name|driver
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to control CRC enabling at a connection level
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_CRC_CONTROL_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state_handle
parameter_list|,
name|VCHI_CRC_CONTROL_T
name|control
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to create a service
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_CONNECT_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state_handle
parameter_list|,
name|int32_t
name|service_id
parameter_list|,
name|uint32_t
name|rx_fifo_size
parameter_list|,
name|uint32_t
name|tx_fifo_size
parameter_list|,
name|int
name|server
parameter_list|,
name|VCHI_CALLBACK_T
name|callback
parameter_list|,
name|void
modifier|*
name|callback_param
parameter_list|,
name|int32_t
name|want_crc
parameter_list|,
name|int32_t
name|want_unaligned_bulk_rx
parameter_list|,
name|int32_t
name|want_unaligned_bulk_tx
parameter_list|,
name|VCHI_CONNECTION_SERVICE_HANDLE_T
modifier|*
name|service_handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to close a service
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_DISCONNECT_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to queue a message
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_QUEUE_MESSAGE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
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
end_typedef

begin_comment
comment|// scatter-gather (vector) message queueing
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_QUEUE_MESSAGEV_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
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
end_typedef

begin_comment
comment|// Routine to dequeue a message
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_DEQUEUE_MESSAGE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
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
end_typedef

begin_comment
comment|// Routine to peek at a message
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_PEEK_MESSAGE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
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
end_typedef

begin_comment
comment|// Routine to hold a message
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_HOLD_MESSAGE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
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
parameter_list|,
name|void
modifier|*
modifier|*
name|message_handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to initialise a received message iterator
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVICE_LOOKAHEAD_MESSAGE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
parameter_list|,
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|,
name|VCHI_FLAGS_T
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to release a held message
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_HELD_MSG_RELEASE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
parameter_list|,
name|void
modifier|*
name|message_handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to get info on a held message
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_HELD_MSG_INFO_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
parameter_list|,
name|void
modifier|*
name|message_handle
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|int32_t
modifier|*
name|msg_size
parameter_list|,
name|uint32_t
modifier|*
name|tx_timestamp
parameter_list|,
name|uint32_t
modifier|*
name|rx_timestamp
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to check whether the iterator has a next message
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_MSG_ITER_HAS_NEXT_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service
parameter_list|,
specifier|const
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to advance the iterator
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_MSG_ITER_NEXT_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service
parameter_list|,
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
end_typedef

begin_comment
comment|// Routine to remove the last message returned by the iterator
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_MSG_ITER_REMOVE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service
parameter_list|,
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to hold the last message returned by the iterator
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_MSG_ITER_HOLD_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service
parameter_list|,
name|VCHI_MSG_ITER_T
modifier|*
name|iter
parameter_list|,
name|void
modifier|*
modifier|*
name|msg_handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to transmit bulk data
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_BULK_QUEUE_TRANSMIT_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
parameter_list|,
specifier|const
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
name|bulk_handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to receive data
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_BULK_QUEUE_RECEIVE_T
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
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
name|bulk_handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to report if a server is available
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVER_PRESENT
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|int32_t
name|service_id
parameter_list|,
name|int32_t
name|peer_flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to report the number of RX slots available
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|VCHI_CONNECTION_RX_SLOTS_AVAILABLE
function_decl|)
parameter_list|(
specifier|const
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Routine to report the RX slot size
end_comment

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|VCHI_CONNECTION_RX_SLOT_SIZE
function_decl|)
parameter_list|(
specifier|const
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback to indicate that the other side has added a buffer to the rx bulk DMA FIFO
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_RX_BULK_BUFFER_ADDED
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|int32_t
name|service
parameter_list|,
name|uint32_t
name|length
parameter_list|,
name|MESSAGE_TX_CHANNEL_T
name|channel
parameter_list|,
name|uint32_t
name|channel_params
parameter_list|,
name|uint32_t
name|data_length
parameter_list|,
name|uint32_t
name|data_offset
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback to inform a service that a Xon or Xoff message has been received
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_FLOW_CONTROL
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|int32_t
name|service_id
parameter_list|,
name|int32_t
name|xoff
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback to inform a service that a server available reply message has been received
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_SERVER_AVAILABLE_REPLY
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|int32_t
name|service_id
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback to indicate that bulk auxiliary messages have arrived
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_BULK_AUX_RECEIVED
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback to indicate that bulk auxiliary messages have arrived
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_BULK_AUX_TRANSMITTED
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback with all the connection info you require
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_INFO
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|uint32_t
name|protocol_version
parameter_list|,
name|uint32_t
name|slot_size
parameter_list|,
name|uint32_t
name|num_slots
parameter_list|,
name|uint32_t
name|min_bulk_size
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback to inform of a disconnect
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_DISCONNECT
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Callback to inform of a power control request
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CONNECTION_POWER_CONTROL
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
parameter_list|,
name|MESSAGE_TX_CHANNEL_T
name|channel
parameter_list|,
name|int32_t
name|enable
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// allocate memory suitably aligned for this connection
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|VCHI_BUFFER_ALLOCATE
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
parameter_list|,
name|uint32_t
modifier|*
name|length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// free memory allocated by buffer_allocate
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_BUFFER_FREE
function_decl|)
parameter_list|(
name|VCHI_CONNECTION_SERVICE_HANDLE_T
name|service_handle
parameter_list|,
name|void
modifier|*
name|address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/******************************************************************************  System driver struct  *****************************************************************************/
end_comment

begin_struct
struct|struct
name|opaque_vchi_connection_api_t
block|{
comment|// Routine to init the connection
name|VCHI_CONNECTION_INIT_T
name|init
decl_stmt|;
comment|// Connection-level CRC control
name|VCHI_CONNECTION_CRC_CONTROL_T
name|crc_control
decl_stmt|;
comment|// Routine to connect to or create service
name|VCHI_CONNECTION_SERVICE_CONNECT_T
name|service_connect
decl_stmt|;
comment|// Routine to disconnect from a service
name|VCHI_CONNECTION_SERVICE_DISCONNECT_T
name|service_disconnect
decl_stmt|;
comment|// Routine to queue a message
name|VCHI_CONNECTION_SERVICE_QUEUE_MESSAGE_T
name|service_queue_msg
decl_stmt|;
comment|// scatter-gather (vector) message queue
name|VCHI_CONNECTION_SERVICE_QUEUE_MESSAGEV_T
name|service_queue_msgv
decl_stmt|;
comment|// Routine to dequeue a message
name|VCHI_CONNECTION_SERVICE_DEQUEUE_MESSAGE_T
name|service_dequeue_msg
decl_stmt|;
comment|// Routine to peek at a message
name|VCHI_CONNECTION_SERVICE_PEEK_MESSAGE_T
name|service_peek_msg
decl_stmt|;
comment|// Routine to hold a message
name|VCHI_CONNECTION_SERVICE_HOLD_MESSAGE_T
name|service_hold_msg
decl_stmt|;
comment|// Routine to initialise a received message iterator
name|VCHI_CONNECTION_SERVICE_LOOKAHEAD_MESSAGE_T
name|service_look_ahead_msg
decl_stmt|;
comment|// Routine to release a message
name|VCHI_CONNECTION_HELD_MSG_RELEASE_T
name|held_msg_release
decl_stmt|;
comment|// Routine to get information on a held message
name|VCHI_CONNECTION_HELD_MSG_INFO_T
name|held_msg_info
decl_stmt|;
comment|// Routine to check for next message on iterator
name|VCHI_CONNECTION_MSG_ITER_HAS_NEXT_T
name|msg_iter_has_next
decl_stmt|;
comment|// Routine to get next message on iterator
name|VCHI_CONNECTION_MSG_ITER_NEXT_T
name|msg_iter_next
decl_stmt|;
comment|// Routine to remove the last message returned by iterator
name|VCHI_CONNECTION_MSG_ITER_REMOVE_T
name|msg_iter_remove
decl_stmt|;
comment|// Routine to hold the last message returned by iterator
name|VCHI_CONNECTION_MSG_ITER_HOLD_T
name|msg_iter_hold
decl_stmt|;
comment|// Routine to transmit bulk data
name|VCHI_CONNECTION_BULK_QUEUE_TRANSMIT_T
name|bulk_queue_transmit
decl_stmt|;
comment|// Routine to receive data
name|VCHI_CONNECTION_BULK_QUEUE_RECEIVE_T
name|bulk_queue_receive
decl_stmt|;
comment|// Routine to report the available servers
name|VCHI_CONNECTION_SERVER_PRESENT
name|server_present
decl_stmt|;
comment|// Routine to report the number of RX slots available
name|VCHI_CONNECTION_RX_SLOTS_AVAILABLE
name|connection_rx_slots_available
decl_stmt|;
comment|// Routine to report the RX slot size
name|VCHI_CONNECTION_RX_SLOT_SIZE
name|connection_rx_slot_size
decl_stmt|;
comment|// Callback to indicate that the other side has added a buffer to the rx bulk DMA FIFO
name|VCHI_CONNECTION_RX_BULK_BUFFER_ADDED
name|rx_bulk_buffer_added
decl_stmt|;
comment|// Callback to inform a service that a Xon or Xoff message has been received
name|VCHI_CONNECTION_FLOW_CONTROL
name|flow_control
decl_stmt|;
comment|// Callback to inform a service that a server available reply message has been received
name|VCHI_CONNECTION_SERVER_AVAILABLE_REPLY
name|server_available_reply
decl_stmt|;
comment|// Callback to indicate that bulk auxiliary messages have arrived
name|VCHI_CONNECTION_BULK_AUX_RECEIVED
name|bulk_aux_received
decl_stmt|;
comment|// Callback to indicate that a bulk auxiliary message has been transmitted
name|VCHI_CONNECTION_BULK_AUX_TRANSMITTED
name|bulk_aux_transmitted
decl_stmt|;
comment|// Callback to provide information about the connection
name|VCHI_CONNECTION_INFO
name|connection_info
decl_stmt|;
comment|// Callback to notify that peer has requested disconnect
name|VCHI_CONNECTION_DISCONNECT
name|disconnect
decl_stmt|;
comment|// Callback to notify that peer has requested power change
name|VCHI_CONNECTION_POWER_CONTROL
name|power_control
decl_stmt|;
comment|// allocate memory suitably aligned for this connection
name|VCHI_BUFFER_ALLOCATE
name|buffer_allocate
decl_stmt|;
comment|// free memory allocated by buffer_allocate
name|VCHI_BUFFER_FREE
name|buffer_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vchi_connection_t
block|{
specifier|const
name|VCHI_CONNECTION_API_T
modifier|*
name|api
decl_stmt|;
name|VCHI_CONNECTION_STATE_T
modifier|*
name|state
decl_stmt|;
ifdef|#
directive|ifdef
name|VCHI_COARSE_LOCKING
name|struct
name|semaphore
name|sem
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONNECTION_H_ */
end_comment

begin_comment
comment|/****************************** End of file **********************************/
end_comment

end_unit

