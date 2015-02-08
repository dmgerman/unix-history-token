begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_CFG_H_
end_ifndef

begin_define
define|#
directive|define
name|VCHI_CFG_H_
end_define

begin_comment
comment|/****************************************************************************************  * Defines in this first section are part of the VCHI API and may be examined by VCHI  * services.  ***************************************************************************************/
end_comment

begin_comment
comment|/* Required alignment of base addresses for bulk transfer, if unaligned transfers are not enabled */
end_comment

begin_comment
comment|/* Really determined by the message driver, and should be available from a run-time call. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_BULK_ALIGN
end_ifndef

begin_if
if|#
directive|if
name|__VCCOREVER__
operator|>=
literal|0x04000000
end_if

begin_define
define|#
directive|define
name|VCHI_BULK_ALIGN
value|32
end_define

begin_comment
comment|// Allows for the need to do cache cleans
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VCHI_BULK_ALIGN
value|16
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
comment|/* Required length multiple for bulk transfers, if unaligned transfers are not enabled */
end_comment

begin_comment
comment|/* May be less than or greater than VCHI_BULK_ALIGN */
end_comment

begin_comment
comment|/* Really determined by the message driver, and should be available from a run-time call. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_BULK_GRANULARITY
end_ifndef

begin_if
if|#
directive|if
name|__VCCOREVER__
operator|>=
literal|0x04000000
end_if

begin_define
define|#
directive|define
name|VCHI_BULK_GRANULARITY
value|32
end_define

begin_comment
comment|// Allows for the need to do cache cleans
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VCHI_BULK_GRANULARITY
value|16
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
comment|/* The largest possible message to be queued with vchi_msg_queue. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_MSG_SIZE
end_ifndef

begin_if
if|#
directive|if
name|defined
name|VCHI_LOCAL_HOST_PORT
end_if

begin_define
define|#
directive|define
name|VCHI_MAX_MSG_SIZE
value|16384
end_define

begin_comment
comment|// makes file transfers fast, but should they be using bulk?
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VCHI_MAX_MSG_SIZE
value|4096
end_define

begin_comment
comment|// NOTE: THIS MUST BE LARGER THAN OR EQUAL TO THE SIZE OF THE KHRONOS MERGE BUFFER!!
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************************************************************************  * Defines below are system configuration options, and should not be used by VCHI services.  *****************************************************************************************/
end_comment

begin_comment
comment|/* How many connections can we support? A localhost implementation uses 2 connections,  * 1 for host-app, 1 for VMCS, and these are hooked together by a loopback MPHI VCFW  * driver. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_NUM_CONNECTIONS
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MAX_NUM_CONNECTIONS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How many services can we open per connection? Extending this doesn't cost processing time, just a small  * amount of static memory. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_SERVICES_PER_CONNECTION
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MAX_SERVICES_PER_CONNECTION
value|36
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Adjust if using a message driver that supports more logical TX channels */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_BULK_TX_CHANNELS_PER_CONNECTION
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MAX_BULK_TX_CHANNELS_PER_CONNECTION
value|9
end_define

begin_comment
comment|// 1 MPHI + 8 CCP2 logical channels
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Adjust if using a message driver that supports more logical RX channels */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_BULK_RX_CHANNELS_PER_CONNECTION
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MAX_BULK_RX_CHANNELS_PER_CONNECTION
value|1
end_define

begin_comment
comment|// 1 MPHI
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How many receive slots do we use. This times VCHI_MAX_MSG_SIZE gives the effective  * receive queue space, less message headers. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_NUM_READ_SLOTS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VCHI_LOCAL_HOST_PORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|VCHI_NUM_READ_SLOTS
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VCHI_NUM_READ_SLOTS
value|48
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
comment|/* Do we utilise overrun facility for receive message slots? Can aid peer transmit  * performance. Only define on VideoCore end, talking to host.  */
end_comment

begin_comment
comment|//#define VCHI_MSG_RX_OVERRUN
end_comment

begin_comment
comment|/* How many transmit slots do we use. Generally don't need many, as the hardware driver  * underneath VCHI will usually have its own buffering. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_NUM_WRITE_SLOTS
end_ifndef

begin_define
define|#
directive|define
name|VCHI_NUM_WRITE_SLOTS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If a service has held or queued received messages in VCHI_XOFF_THRESHOLD or more slots,  * then it's taking up too much buffer space, and the peer service will be told to stop  * transmitting with an XOFF message. For this to be effective, the VCHI_NUM_READ_SLOTS  * needs to be considerably bigger than VCHI_NUM_WRITE_SLOTS, or the transmit latency  * is too high. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_XOFF_THRESHOLD
end_ifndef

begin_define
define|#
directive|define
name|VCHI_XOFF_THRESHOLD
value|(VCHI_NUM_READ_SLOTS / 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* After we've sent an XOFF, the peer will be told to resume transmission once the local  * service has dequeued/released enough messages that it's now occupying  * VCHI_XON_THRESHOLD slots or fewer. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_XON_THRESHOLD
end_ifndef

begin_define
define|#
directive|define
name|VCHI_XON_THRESHOLD
value|(VCHI_NUM_READ_SLOTS / 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A size below which a bulk transfer omits the handshake completely and always goes  * via the message channel, if bulk auxiliary is being sent on that service. (The user  * can guarantee this by enabling unaligned transmits).  * Not API. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MIN_BULK_SIZE
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MIN_BULK_SIZE
value|( VCHI_MAX_MSG_SIZE / 2< 4096 ? VCHI_MAX_MSG_SIZE / 2 : 4096 )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum size of bulk transmission chunks, for each interface type. A trade-off between  * speed and latency; the smaller the chunk size the better change of messages and other  * bulk transmissions getting in when big bulk transfers are happening. Set to 0 to not  * break transmissions into chunks.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_BULK_CHUNK_SIZE_MPHI
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MAX_BULK_CHUNK_SIZE_MPHI
value|(16 * 1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NB Chunked CCP2 transmissions violate the letter of the CCP2 spec by using "JPEG8" mode  * with multiple-line frames. Only use if the receiver can cope. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_BULK_CHUNK_SIZE_CCP2
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MAX_BULK_CHUNK_SIZE_CCP2
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How many TX messages can we have pending in our transmit slots. Once exhausted,  * vchi_msg_queue will be blocked. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_TX_MSG_QUEUE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|VCHI_TX_MSG_QUEUE_SIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How many RX messages can we have parsed in the receive slots. Once exhausted, parsing  * will be suspended until older messages are dequeued/released. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_RX_MSG_QUEUE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|VCHI_RX_MSG_QUEUE_SIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Really should be able to cope if we run out of received message descriptors, by  * suspending parsing as the comment above says, but we don't. This sweeps the issue  * under the carpet. */
end_comment

begin_if
if|#
directive|if
name|VCHI_RX_MSG_QUEUE_SIZE
operator|<
operator|(
name|VCHI_MAX_MSG_SIZE
operator|/
literal|16
operator|+
literal|1
operator|)
operator|*
name|VCHI_NUM_READ_SLOTS
end_if

begin_undef
undef|#
directive|undef
name|VCHI_RX_MSG_QUEUE_SIZE
end_undef

begin_define
define|#
directive|define
name|VCHI_RX_MSG_QUEUE_SIZE
value|(VCHI_MAX_MSG_SIZE/16 + 1) * VCHI_NUM_READ_SLOTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How many bulk transmits can we have pending. Once exhausted, vchi_bulk_queue_transmit  * will be blocked. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_TX_BULK_QUEUE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|VCHI_TX_BULK_QUEUE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How many bulk receives can we have pending. Once exhausted, vchi_bulk_queue_receive  * will be blocked. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_RX_BULK_QUEUE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|VCHI_RX_BULK_QUEUE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A limit on how many outstanding bulk requests we expect the peer to give us. If  * the peer asks for more than this, VCHI will fail and assert. The number is determined  * by the peer's hardware - it's the number of outstanding requests that can be queued  * on all bulk channels. VC3's MPHI peripheral allows 16. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_MAX_PEER_BULK_REQUESTS
end_ifndef

begin_define
define|#
directive|define
name|VCHI_MAX_PEER_BULK_REQUESTS
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define VCHI_CCP2TX_MANUAL_POWER if the host tells us when to turn the CCP2  * transmitter on and off.  */
end_comment

begin_comment
comment|/*#define VCHI_CCP2TX_MANUAL_POWER*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_CCP2TX_MANUAL_POWER
end_ifndef

begin_comment
comment|/* Timeout (in milliseconds) for putting the CCP2TX interface into IDLE state. Set  * negative for no IDLE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_CCP2TX_IDLE_TIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|VCHI_CCP2TX_IDLE_TIMEOUT
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Timeout (in milliseconds) for putting the CCP2TX interface into OFF state. Set  * negative for no OFF.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_CCP2TX_OFF_TIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|VCHI_CCP2TX_OFF_TIMEOUT
value|1000
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
comment|/* VCHI_CCP2TX_MANUAL_POWER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VCHI_CFG_H_ */
end_comment

begin_comment
comment|/****************************** End of file **********************************/
end_comment

end_unit

