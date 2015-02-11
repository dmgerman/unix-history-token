begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|VCHI_COMMON_H_
end_define

begin_comment
comment|//flags used when sending messages (must be bitmapped)
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VCHI_FLAGS_NONE
init|=
literal|0x0
block|,
name|VCHI_FLAGS_BLOCK_UNTIL_OP_COMPLETE
init|=
literal|0x1
block|,
comment|// waits for message to be received, or sent (NB. not the same as being seen on other side)
name|VCHI_FLAGS_CALLBACK_WHEN_OP_COMPLETE
init|=
literal|0x2
block|,
comment|// run a callback when message sent
name|VCHI_FLAGS_BLOCK_UNTIL_QUEUED
init|=
literal|0x4
block|,
comment|// return once the transfer is in a queue ready to go
name|VCHI_FLAGS_ALLOW_PARTIAL
init|=
literal|0x8
block|,
name|VCHI_FLAGS_BLOCK_UNTIL_DATA_READ
init|=
literal|0x10
block|,
name|VCHI_FLAGS_CALLBACK_WHEN_DATA_READ
init|=
literal|0x20
block|,
name|VCHI_FLAGS_ALIGN_SLOT
init|=
literal|0x000080
block|,
comment|// internal use only
name|VCHI_FLAGS_BULK_AUX_QUEUED
init|=
literal|0x010000
block|,
comment|// internal use only
name|VCHI_FLAGS_BULK_AUX_COMPLETE
init|=
literal|0x020000
block|,
comment|// internal use only
name|VCHI_FLAGS_BULK_DATA_QUEUED
init|=
literal|0x040000
block|,
comment|// internal use only
name|VCHI_FLAGS_BULK_DATA_COMPLETE
init|=
literal|0x080000
block|,
comment|// internal use only
name|VCHI_FLAGS_INTERNAL
init|=
literal|0xFF0000
block|}
name|VCHI_FLAGS_T
typedef|;
end_typedef

begin_comment
comment|// constants for vchi_crc_control()
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VCHI_CRC_NOTHING
init|=
operator|-
literal|1
block|,
name|VCHI_CRC_PER_SERVICE
init|=
literal|0
block|,
name|VCHI_CRC_EVERYTHING
init|=
literal|1
block|, }
name|VCHI_CRC_CONTROL_T
typedef|;
end_typedef

begin_comment
comment|//callback reasons when an event occurs on a service
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VCHI_CALLBACK_REASON_MIN
block|,
comment|//This indicates that there is data available
comment|//handle is the msg id that was transmitted with the data
comment|//    When a message is received and there was no FULL message available previously, send callback
comment|//    Tasks get kicked by the callback, reset their event and try and read from the fifo until it fails
name|VCHI_CALLBACK_MSG_AVAILABLE
block|,
name|VCHI_CALLBACK_MSG_SENT
block|,
name|VCHI_CALLBACK_MSG_SPACE_AVAILABLE
block|,
comment|// XXX not yet implemented
comment|// This indicates that a transfer from the other side has completed
name|VCHI_CALLBACK_BULK_RECEIVED
block|,
comment|//This indicates that data queued up to be sent has now gone
comment|//handle is the msg id that was used when sending the data
name|VCHI_CALLBACK_BULK_SENT
block|,
name|VCHI_CALLBACK_BULK_RX_SPACE_AVAILABLE
block|,
comment|// XXX not yet implemented
name|VCHI_CALLBACK_BULK_TX_SPACE_AVAILABLE
block|,
comment|// XXX not yet implemented
name|VCHI_CALLBACK_SERVICE_CLOSED
block|,
comment|// this side has sent XOFF to peer due to lack of data consumption by service
comment|// (suggests the service may need to take some recovery action if it has
comment|// been deliberately holding off consuming data)
name|VCHI_CALLBACK_SENT_XOFF
block|,
name|VCHI_CALLBACK_SENT_XON
block|,
comment|// indicates that a bulk transfer has finished reading the source buffer
name|VCHI_CALLBACK_BULK_DATA_READ
block|,
comment|// power notification events (currently host side only)
name|VCHI_CALLBACK_PEER_OFF
block|,
name|VCHI_CALLBACK_PEER_SUSPENDED
block|,
name|VCHI_CALLBACK_PEER_ON
block|,
name|VCHI_CALLBACK_PEER_RESUMED
block|,
name|VCHI_CALLBACK_FORCED_POWER_OFF
block|,
ifdef|#
directive|ifdef
name|USE_VCHIQ_ARM
comment|// some extra notifications provided by vchiq_arm
name|VCHI_CALLBACK_SERVICE_OPENED
block|,
name|VCHI_CALLBACK_BULK_RECEIVE_ABORTED
block|,
name|VCHI_CALLBACK_BULK_TRANSMIT_ABORTED
block|,
endif|#
directive|endif
name|VCHI_CALLBACK_REASON_MAX
block|}
name|VCHI_CALLBACK_REASON_T
typedef|;
end_typedef

begin_comment
comment|//Calback used by all services / bulk transfers
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHI_CALLBACK_T
function_decl|)
parameter_list|(
name|void
modifier|*
name|callback_param
parameter_list|,
comment|//my service local param
name|VCHI_CALLBACK_REASON_T
name|reason
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//for transmitting msg's only
end_comment

begin_comment
comment|/*  * Define vector struct for scatter-gather (vector) operations  * Vectors can be nested - if a vector element has negative length, then  * the data pointer is treated as pointing to another vector array, with  * '-vec_len' elements. Thus to append a header onto an existing vector,  * you can do this:  *  * void foo(const VCHI_MSG_VECTOR_T *v, int n)  * {  *    VCHI_MSG_VECTOR_T nv[2];  *    nv[0].vec_base = my_header;  *    nv[0].vec_len = sizeof my_header;  *    nv[1].vec_base = v;  *    nv[1].vec_len = -n;  *    ...  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vchi_msg_vector
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
name|VCHI_MSG_VECTOR_T
typedef|;
end_typedef

begin_comment
comment|// Opaque type for a connection API
end_comment

begin_typedef
typedef|typedef
name|struct
name|opaque_vchi_connection_api_t
name|VCHI_CONNECTION_API_T
typedef|;
end_typedef

begin_comment
comment|// Opaque type for a message driver
end_comment

begin_typedef
typedef|typedef
name|struct
name|opaque_vchi_message_driver_t
name|VCHI_MESSAGE_DRIVER_T
typedef|;
end_typedef

begin_comment
comment|// Iterator structure for reading ahead through received message queue. Allocated by client,
end_comment

begin_comment
comment|// initialised by vchi_msg_look_ahead. Fields are for internal VCHI use only.
end_comment

begin_comment
comment|// Iterates over messages in queue at the instant of the call to vchi_msg_lookahead -
end_comment

begin_comment
comment|// will not proceed to messages received since. Behaviour is undefined if an iterator
end_comment

begin_comment
comment|// is used again after messages for that service are removed/dequeued by any
end_comment

begin_comment
comment|// means other than vchi_msg_iter_... calls on the iterator itself.
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
name|last
decl_stmt|;
name|void
modifier|*
name|next
decl_stmt|;
name|void
modifier|*
name|remove
decl_stmt|;
block|}
name|VCHI_MSG_ITER_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// VCHI_COMMON_H_
end_comment

end_unit

