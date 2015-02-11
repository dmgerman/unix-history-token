begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHIQ_CORE_H
end_ifndef

begin_define
define|#
directive|define
name|VCHIQ_CORE_H
end_define

begin_include
include|#
directive|include
file|<interface/compat/vchi_bsd.h>
end_include

begin_include
include|#
directive|include
file|<interface/compat/list.h>
end_include

begin_include
include|#
directive|include
file|"vchiq_cfg.h"
end_include

begin_include
include|#
directive|include
file|"vchiq.h"
end_include

begin_comment
comment|/* Run time control of log level, based on KERN_XXX level. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHIQ_LOG_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|VCHIQ_LOG_DEFAULT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VCHIQ_LOG_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|VCHIQ_LOG_WARNING
value|4
end_define

begin_define
define|#
directive|define
name|VCHIQ_LOG_INFO
value|6
end_define

begin_define
define|#
directive|define
name|VCHIQ_LOG_TRACE
value|7
end_define

begin_define
define|#
directive|define
name|VCHIQ_LOG_PREFIX
value|"vchiq: "
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vchiq_log_error
end_ifndef

begin_define
define|#
directive|define
name|vchiq_log_error
parameter_list|(
name|cat
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { if (cat>= VCHIQ_LOG_ERROR) \ 		printf(VCHIQ_LOG_PREFIX fmt "\n", ##__VA_ARGS__); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|vchiq_log_warning
end_ifndef

begin_define
define|#
directive|define
name|vchiq_log_warning
parameter_list|(
name|cat
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { if (cat>= VCHIQ_LOG_WARNING) \ 		 printf(VCHIQ_LOG_PREFIX fmt "\n", ##__VA_ARGS__); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|vchiq_log_info
end_ifndef

begin_define
define|#
directive|define
name|vchiq_log_info
parameter_list|(
name|cat
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { if (cat>= VCHIQ_LOG_INFO) \ 		printf(VCHIQ_LOG_PREFIX fmt "\n", ##__VA_ARGS__); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|vchiq_log_trace
end_ifndef

begin_define
define|#
directive|define
name|vchiq_log_trace
parameter_list|(
name|cat
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { if (cat>= VCHIQ_LOG_TRACE) \ 		printf(VCHIQ_LOG_PREFIX fmt "\n", ##__VA_ARGS__); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vchiq_loud_error
parameter_list|(
modifier|...
parameter_list|)
define|\
value|vchiq_log_error(vchiq_core_log_level, "===== " __VA_ARGS__)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vchiq_static_assert
end_ifndef

begin_define
define|#
directive|define
name|vchiq_static_assert
parameter_list|(
name|cond
parameter_list|)
value|__attribute__((unused)) \ 	extern int vchiq_static_assert[(cond) ? 1 : -1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IS_POW2
parameter_list|(
name|x
parameter_list|)
value|(x&& ((x& (x - 1)) == 0))
end_define

begin_comment
comment|/* Ensure that the slot size and maximum number of slots are powers of 2 */
end_comment

begin_expr_stmt
name|vchiq_static_assert
argument_list|(
name|IS_POW2
argument_list|(
name|VCHIQ_SLOT_SIZE
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vchiq_static_assert
argument_list|(
name|IS_POW2
argument_list|(
name|VCHIQ_MAX_SLOTS
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vchiq_static_assert
argument_list|(
name|IS_POW2
argument_list|(
name|VCHIQ_MAX_SLOTS_PER_SIDE
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VCHIQ_SLOT_MASK
value|(VCHIQ_SLOT_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|VCHIQ_SLOT_QUEUE_MASK
value|(VCHIQ_MAX_SLOTS_PER_SIDE - 1)
end_define

begin_define
define|#
directive|define
name|VCHIQ_SLOT_ZERO_SLOTS
value|((sizeof(VCHIQ_SLOT_ZERO_T) + \ 	VCHIQ_SLOT_SIZE - 1) / VCHIQ_SLOT_SIZE)
end_define

begin_define
define|#
directive|define
name|VCHIQ_MSG_PADDING
value|0
end_define

begin_comment
comment|/* -                                 */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_CONNECT
value|1
end_define

begin_comment
comment|/* -                                 */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_OPEN
value|2
end_define

begin_comment
comment|/* + (srcport, -), fourcc, client_id */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_OPENACK
value|3
end_define

begin_comment
comment|/* + (srcport, dstport)              */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_CLOSE
value|4
end_define

begin_comment
comment|/* + (srcport, dstport)              */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_DATA
value|5
end_define

begin_comment
comment|/* + (srcport, dstport)              */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_BULK_RX
value|6
end_define

begin_comment
comment|/* + (srcport, dstport), data, size  */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_BULK_TX
value|7
end_define

begin_comment
comment|/* + (srcport, dstport), data, size  */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_BULK_RX_DONE
value|8
end_define

begin_comment
comment|/* + (srcport, dstport), actual      */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_BULK_TX_DONE
value|9
end_define

begin_comment
comment|/* + (srcport, dstport), actual      */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_PAUSE
value|10
end_define

begin_comment
comment|/* -                                 */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_RESUME
value|11
end_define

begin_comment
comment|/* -                                 */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_REMOTE_USE
value|12
end_define

begin_comment
comment|/* -                                 */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_REMOTE_RELEASE
value|13
end_define

begin_comment
comment|/* -                                 */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_MSG_REMOTE_USE_ACTIVE
value|14
end_define

begin_comment
comment|/* -                                 */
end_comment

begin_define
define|#
directive|define
name|VCHIQ_PORT_MAX
value|(VCHIQ_MAX_SERVICES - 1)
end_define

begin_define
define|#
directive|define
name|VCHIQ_PORT_FREE
value|0x1000
end_define

begin_define
define|#
directive|define
name|VCHIQ_PORT_IS_VALID
parameter_list|(
name|port
parameter_list|)
value|(port< VCHIQ_PORT_FREE)
end_define

begin_define
define|#
directive|define
name|VCHIQ_MAKE_MSG
parameter_list|(
name|type
parameter_list|,
name|srcport
parameter_list|,
name|dstport
parameter_list|)
define|\
value|((type<<24) | (srcport<<12) | (dstport<<0))
end_define

begin_define
define|#
directive|define
name|VCHIQ_MSG_TYPE
parameter_list|(
name|msgid
parameter_list|)
value|((unsigned int)msgid>> 24)
end_define

begin_define
define|#
directive|define
name|VCHIQ_MSG_SRCPORT
parameter_list|(
name|msgid
parameter_list|)
define|\
value|(unsigned short)(((unsigned int)msgid>> 12)& 0xfff)
end_define

begin_define
define|#
directive|define
name|VCHIQ_MSG_DSTPORT
parameter_list|(
name|msgid
parameter_list|)
define|\
value|((unsigned short)msgid& 0xfff)
end_define

begin_define
define|#
directive|define
name|VCHIQ_FOURCC_AS_4CHARS
parameter_list|(
name|fourcc
parameter_list|)
define|\
value|((fourcc)>> 24)& 0xff, \ 	((fourcc)>> 16)& 0xff, \ 	((fourcc)>>  8)& 0xff, \ 	(fourcc)& 0xff
end_define

begin_comment
comment|/* Ensure the fields are wide enough */
end_comment

begin_expr_stmt
name|vchiq_static_assert
argument_list|(
name|VCHIQ_MSG_SRCPORT
argument_list|(
name|VCHIQ_MAKE_MSG
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|VCHIQ_PORT_MAX
argument_list|)
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vchiq_static_assert
argument_list|(
name|VCHIQ_MSG_TYPE
argument_list|(
name|VCHIQ_MAKE_MSG
argument_list|(
literal|0
argument_list|,
name|VCHIQ_PORT_MAX
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vchiq_static_assert
argument_list|(
operator|(
name|unsigned
name|int
operator|)
name|VCHIQ_PORT_MAX
operator|<
operator|(
name|unsigned
name|int
operator|)
name|VCHIQ_PORT_FREE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VCHIQ_MSGID_PADDING
value|VCHIQ_MAKE_MSG(VCHIQ_MSG_PADDING, 0, 0)
end_define

begin_define
define|#
directive|define
name|VCHIQ_MSGID_CLAIMED
value|0x40000000
end_define

begin_define
define|#
directive|define
name|VCHIQ_FOURCC_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|VCHIQ_FOURCC_IS_LEGAL
parameter_list|(
name|fourcc
parameter_list|)
value|(fourcc != VCHIQ_FOURCC_INVALID)
end_define

begin_define
define|#
directive|define
name|VCHIQ_BULK_ACTUAL_ABORTED
value|-1
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|BITSET_T
typedef|;
end_typedef

begin_expr_stmt
name|vchiq_static_assert
argument_list|(
operator|(
sizeof|sizeof
argument_list|(
name|BITSET_T
argument_list|)
operator|*
literal|8
operator|)
operator|==
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|BITSET_SIZE
parameter_list|(
name|b
parameter_list|)
value|((b + 31)>> 5)
end_define

begin_define
define|#
directive|define
name|BITSET_WORD
parameter_list|(
name|b
parameter_list|)
value|(b>> 5)
end_define

begin_define
define|#
directive|define
name|BITSET_BIT
parameter_list|(
name|b
parameter_list|)
value|(1<< (b& 31))
end_define

begin_define
define|#
directive|define
name|BITSET_ZERO
parameter_list|(
name|bs
parameter_list|)
value|memset(bs, 0, sizeof(bs))
end_define

begin_define
define|#
directive|define
name|BITSET_IS_SET
parameter_list|(
name|bs
parameter_list|,
name|b
parameter_list|)
value|(bs[BITSET_WORD(b)]& BITSET_BIT(b))
end_define

begin_define
define|#
directive|define
name|BITSET_SET
parameter_list|(
name|bs
parameter_list|,
name|b
parameter_list|)
value|(bs[BITSET_WORD(b)] |= BITSET_BIT(b))
end_define

begin_define
define|#
directive|define
name|BITSET_CLR
parameter_list|(
name|bs
parameter_list|,
name|b
parameter_list|)
value|(bs[BITSET_WORD(b)]&= ~BITSET_BIT(b))
end_define

begin_if
if|#
directive|if
name|VCHIQ_ENABLE_STATS
end_if

begin_define
define|#
directive|define
name|VCHIQ_STATS_INC
parameter_list|(
name|state
parameter_list|,
name|stat
parameter_list|)
value|(state->stats. stat++)
end_define

begin_define
define|#
directive|define
name|VCHIQ_SERVICE_STATS_INC
parameter_list|(
name|service
parameter_list|,
name|stat
parameter_list|)
value|(service->stats. stat++)
end_define

begin_define
define|#
directive|define
name|VCHIQ_SERVICE_STATS_ADD
parameter_list|(
name|service
parameter_list|,
name|stat
parameter_list|,
name|addend
parameter_list|)
define|\
value|(service->stats. stat += addend)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VCHIQ_STATS_INC
parameter_list|(
name|state
parameter_list|,
name|stat
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|VCHIQ_SERVICE_STATS_INC
parameter_list|(
name|service
parameter_list|,
name|stat
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|VCHIQ_SERVICE_STATS_ADD
parameter_list|(
name|service
parameter_list|,
name|stat
parameter_list|,
name|addend
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
block|{
name|DEBUG_ENTRIES
block|,
if|#
directive|if
name|VCHIQ_ENABLE_DEBUG
name|DEBUG_SLOT_HANDLER_COUNT
block|,
name|DEBUG_SLOT_HANDLER_LINE
block|,
name|DEBUG_PARSE_LINE
block|,
name|DEBUG_PARSE_HEADER
block|,
name|DEBUG_PARSE_MSGID
block|,
name|DEBUG_AWAIT_COMPLETION_LINE
block|,
name|DEBUG_DEQUEUE_MESSAGE_LINE
block|,
name|DEBUG_SERVICE_CALLBACK_LINE
block|,
name|DEBUG_MSG_QUEUE_FULL_COUNT
block|,
name|DEBUG_COMPLETION_QUEUE_FULL_COUNT
block|,
endif|#
directive|endif
name|DEBUG_MAX
block|}
enum|;
end_enum

begin_if
if|#
directive|if
name|VCHIQ_ENABLE_DEBUG
end_if

begin_define
define|#
directive|define
name|DEBUG_INITIALISE
parameter_list|(
name|local
parameter_list|)
value|int *debug_ptr = (local)->debug;
end_define

begin_define
define|#
directive|define
name|DEBUG_TRACE
parameter_list|(
name|d
parameter_list|)
define|\
value|do { debug_ptr[DEBUG_ ## d] = __LINE__; dsb(); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_VALUE
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|)
define|\
value|do { debug_ptr[DEBUG_ ## d] = (v); dsb(); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_COUNT
parameter_list|(
name|d
parameter_list|)
define|\
value|do { debug_ptr[DEBUG_ ## d]++; dsb(); } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VCHIQ_ENABLE_DEBUG */
end_comment

begin_define
define|#
directive|define
name|DEBUG_INITIALISE
parameter_list|(
name|local
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_TRACE
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_VALUE
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_COUNT
parameter_list|(
name|d
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VCHIQ_ENABLE_DEBUG */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VCHIQ_CONNSTATE_DISCONNECTED
block|,
name|VCHIQ_CONNSTATE_CONNECTING
block|,
name|VCHIQ_CONNSTATE_CONNECTED
block|,
name|VCHIQ_CONNSTATE_PAUSING
block|,
name|VCHIQ_CONNSTATE_PAUSE_SENT
block|,
name|VCHIQ_CONNSTATE_PAUSED
block|,
name|VCHIQ_CONNSTATE_RESUMING
block|,
name|VCHIQ_CONNSTATE_PAUSE_TIMEOUT
block|,
name|VCHIQ_CONNSTATE_RESUME_TIMEOUT
block|}
name|VCHIQ_CONNSTATE_T
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|VCHIQ_SRVSTATE_FREE
block|,
name|VCHIQ_SRVSTATE_HIDDEN
block|,
name|VCHIQ_SRVSTATE_LISTENING
block|,
name|VCHIQ_SRVSTATE_OPENING
block|,
name|VCHIQ_SRVSTATE_OPEN
block|,
name|VCHIQ_SRVSTATE_OPENSYNC
block|,
name|VCHIQ_SRVSTATE_CLOSESENT
block|,
name|VCHIQ_SRVSTATE_CLOSERECVD
block|,
name|VCHIQ_SRVSTATE_CLOSEWAIT
block|,
name|VCHIQ_SRVSTATE_CLOSED
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|VCHIQ_POLL_TERMINATE
block|,
name|VCHIQ_POLL_REMOVE
block|,
name|VCHIQ_POLL_TXNOTIFY
block|,
name|VCHIQ_POLL_RXNOTIFY
block|,
name|VCHIQ_POLL_COUNT
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
enum|enum
block|{
name|VCHIQ_BULK_TRANSMIT
block|,
name|VCHIQ_BULK_RECEIVE
block|}
name|VCHIQ_BULK_DIR_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|VCHIQ_USERDATA_TERM_T
function_decl|)
parameter_list|(
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchiq_bulk_struct
block|{
name|short
name|mode
decl_stmt|;
name|short
name|dir
decl_stmt|;
name|void
modifier|*
name|userdata
decl_stmt|;
name|VCHI_MEM_HANDLE_T
name|handle
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|int
name|size
decl_stmt|;
name|void
modifier|*
name|remote_data
decl_stmt|;
name|int
name|remote_size
decl_stmt|;
name|int
name|actual
decl_stmt|;
block|}
name|VCHIQ_BULK_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchiq_bulk_queue_struct
block|{
name|int
name|local_insert
decl_stmt|;
comment|/* Where to insert the next local bulk */
name|int
name|remote_insert
decl_stmt|;
comment|/* Where to insert the next remote bulk (master) */
name|int
name|process
decl_stmt|;
comment|/* Bulk to transfer next */
name|int
name|remote_notify
decl_stmt|;
comment|/* Bulk to notify the remote client of next (mstr) */
name|int
name|remove
decl_stmt|;
comment|/* Bulk to notify the local client of, and remove, 			   ** next */
name|VCHIQ_BULK_T
name|bulks
index|[
name|VCHIQ_NUM_SERVICE_BULKS
index|]
decl_stmt|;
block|}
name|VCHIQ_BULK_QUEUE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|remote_event_struct
block|{
name|int
name|armed
decl_stmt|;
name|int
name|fired
decl_stmt|;
name|struct
name|semaphore
modifier|*
name|event
decl_stmt|;
block|}
name|REMOTE_EVENT_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|opaque_platform_state_t
modifier|*
name|VCHIQ_PLATFORM_STATE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vchiq_state_struct
name|VCHIQ_STATE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchiq_slot_struct
block|{
name|char
name|data
index|[
name|VCHIQ_SLOT_SIZE
index|]
decl_stmt|;
block|}
name|VCHIQ_SLOT_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchiq_slot_info_struct
block|{
comment|/* Use two counters rather than one to avoid the need for a mutex. */
name|short
name|use_count
decl_stmt|;
name|short
name|release_count
decl_stmt|;
block|}
name|VCHIQ_SLOT_INFO_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchiq_service_struct
block|{
name|VCHIQ_SERVICE_BASE_T
name|base
decl_stmt|;
name|VCHIQ_SERVICE_HANDLE_T
name|handle
decl_stmt|;
name|unsigned
name|int
name|ref_count
decl_stmt|;
name|int
name|srvstate
decl_stmt|;
name|VCHIQ_USERDATA_TERM_T
name|userdata_term
decl_stmt|;
name|unsigned
name|int
name|localport
decl_stmt|;
name|unsigned
name|int
name|remoteport
decl_stmt|;
name|int
name|public_fourcc
decl_stmt|;
name|int
name|client_id
decl_stmt|;
name|char
name|auto_close
decl_stmt|;
name|char
name|sync
decl_stmt|;
name|char
name|closing
decl_stmt|;
name|atomic_t
name|poll_flags
decl_stmt|;
name|short
name|version
decl_stmt|;
name|short
name|version_min
decl_stmt|;
name|short
name|peer_version
decl_stmt|;
name|VCHIQ_STATE_T
modifier|*
name|state
decl_stmt|;
name|VCHIQ_INSTANCE_T
name|instance
decl_stmt|;
name|int
name|service_use_count
decl_stmt|;
name|VCHIQ_BULK_QUEUE_T
name|bulk_tx
decl_stmt|;
name|VCHIQ_BULK_QUEUE_T
name|bulk_rx
decl_stmt|;
name|struct
name|semaphore
name|remove_event
decl_stmt|;
name|struct
name|semaphore
name|bulk_remove_event
decl_stmt|;
name|struct
name|mutex
name|bulk_mutex
decl_stmt|;
struct|struct
name|service_stats_struct
block|{
name|int
name|quota_stalls
decl_stmt|;
name|int
name|slot_stalls
decl_stmt|;
name|int
name|bulk_stalls
decl_stmt|;
name|int
name|error_count
decl_stmt|;
name|int
name|ctrl_tx_count
decl_stmt|;
name|int
name|ctrl_rx_count
decl_stmt|;
name|int
name|bulk_tx_count
decl_stmt|;
name|int
name|bulk_rx_count
decl_stmt|;
name|int
name|bulk_aborted_count
decl_stmt|;
name|uint64_t
name|ctrl_tx_bytes
decl_stmt|;
name|uint64_t
name|ctrl_rx_bytes
decl_stmt|;
name|uint64_t
name|bulk_tx_bytes
decl_stmt|;
name|uint64_t
name|bulk_rx_bytes
decl_stmt|;
block|}
name|stats
struct|;
block|}
name|VCHIQ_SERVICE_T
typedef|;
end_typedef

begin_comment
comment|/* The quota information is outside VCHIQ_SERVICE_T so that it can be 	statically allocated, since for accounting reasons a service's slot 	usage is carried over between users of the same port number.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vchiq_service_quota_struct
block|{
name|unsigned
name|short
name|slot_quota
decl_stmt|;
name|unsigned
name|short
name|slot_use_count
decl_stmt|;
name|unsigned
name|short
name|message_quota
decl_stmt|;
name|unsigned
name|short
name|message_use_count
decl_stmt|;
name|struct
name|semaphore
name|quota_event
decl_stmt|;
name|int
name|previous_tx_index
decl_stmt|;
block|}
name|VCHIQ_SERVICE_QUOTA_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchiq_shared_state_struct
block|{
comment|/* A non-zero value here indicates that the content is valid. */
name|int
name|initialised
decl_stmt|;
comment|/* The first and last (inclusive) slots allocated to the owner. */
name|int
name|slot_first
decl_stmt|;
name|int
name|slot_last
decl_stmt|;
comment|/* The slot allocated to synchronous messages from the owner. */
name|int
name|slot_sync
decl_stmt|;
comment|/* Signalling this event indicates that owner's slot handler thread 	** should run. */
name|REMOTE_EVENT_T
name|trigger
decl_stmt|;
comment|/* Indicates the byte position within the stream where the next message 	** will be written. The least significant bits are an index into the 	** slot. The next bits are the index of the slot in slot_queue. */
name|int
name|tx_pos
decl_stmt|;
comment|/* This event should be signalled when a slot is recycled. */
name|REMOTE_EVENT_T
name|recycle
decl_stmt|;
comment|/* The slot_queue index where the next recycled slot will be written. */
name|int
name|slot_queue_recycle
decl_stmt|;
comment|/* This event should be signalled when a synchronous message is sent. */
name|REMOTE_EVENT_T
name|sync_trigger
decl_stmt|;
comment|/* This event should be signalled when a synchronous message has been 	** released. */
name|REMOTE_EVENT_T
name|sync_release
decl_stmt|;
comment|/* A circular buffer of slot indexes. */
name|int
name|slot_queue
index|[
name|VCHIQ_MAX_SLOTS_PER_SIDE
index|]
decl_stmt|;
comment|/* Debugging state */
name|int
name|debug
index|[
name|DEBUG_MAX
index|]
decl_stmt|;
block|}
name|VCHIQ_SHARED_STATE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vchiq_slot_zero_struct
block|{
name|int
name|magic
decl_stmt|;
name|short
name|version
decl_stmt|;
name|short
name|version_min
decl_stmt|;
name|int
name|slot_zero_size
decl_stmt|;
name|int
name|slot_size
decl_stmt|;
name|int
name|max_slots
decl_stmt|;
name|int
name|max_slots_per_side
decl_stmt|;
name|int
name|platform_data
index|[
literal|2
index|]
decl_stmt|;
name|VCHIQ_SHARED_STATE_T
name|master
decl_stmt|;
name|VCHIQ_SHARED_STATE_T
name|slave
decl_stmt|;
name|VCHIQ_SLOT_INFO_T
name|slots
index|[
name|VCHIQ_MAX_SLOTS
index|]
decl_stmt|;
block|}
name|VCHIQ_SLOT_ZERO_T
typedef|;
end_typedef

begin_struct
struct|struct
name|vchiq_state_struct
block|{
name|int
name|id
decl_stmt|;
name|int
name|initialised
decl_stmt|;
name|VCHIQ_CONNSTATE_T
name|conn_state
decl_stmt|;
name|int
name|is_master
decl_stmt|;
name|VCHIQ_SHARED_STATE_T
modifier|*
name|local
decl_stmt|;
name|VCHIQ_SHARED_STATE_T
modifier|*
name|remote
decl_stmt|;
name|VCHIQ_SLOT_T
modifier|*
name|slot_data
decl_stmt|;
name|unsigned
name|short
name|default_slot_quota
decl_stmt|;
name|unsigned
name|short
name|default_message_quota
decl_stmt|;
comment|/* Event indicating connect message received */
name|struct
name|semaphore
name|connect
decl_stmt|;
comment|/* Mutex protecting services */
name|struct
name|mutex
name|mutex
decl_stmt|;
name|VCHIQ_INSTANCE_T
modifier|*
name|instance
decl_stmt|;
comment|/* Processes incoming messages */
name|VCHIQ_THREAD_T
name|slot_handler_thread
decl_stmt|;
comment|/* Processes recycled slots */
name|VCHIQ_THREAD_T
name|recycle_thread
decl_stmt|;
comment|/* Processes synchronous messages */
name|VCHIQ_THREAD_T
name|sync_thread
decl_stmt|;
comment|/* Local implementation of the trigger remote event */
name|struct
name|semaphore
name|trigger_event
decl_stmt|;
comment|/* Local implementation of the recycle remote event */
name|struct
name|semaphore
name|recycle_event
decl_stmt|;
comment|/* Local implementation of the sync trigger remote event */
name|struct
name|semaphore
name|sync_trigger_event
decl_stmt|;
comment|/* Local implementation of the sync release remote event */
name|struct
name|semaphore
name|sync_release_event
decl_stmt|;
name|char
modifier|*
name|tx_data
decl_stmt|;
name|char
modifier|*
name|rx_data
decl_stmt|;
name|VCHIQ_SLOT_INFO_T
modifier|*
name|rx_info
decl_stmt|;
name|struct
name|mutex
name|slot_mutex
decl_stmt|;
name|struct
name|mutex
name|recycle_mutex
decl_stmt|;
name|struct
name|mutex
name|sync_mutex
decl_stmt|;
name|struct
name|mutex
name|bulk_transfer_mutex
decl_stmt|;
comment|/* Indicates the byte position within the stream from where the next 	** message will be read. The least significant bits are an index into 	** the slot.The next bits are the index of the slot in 	** remote->slot_queue. */
name|int
name|rx_pos
decl_stmt|;
comment|/* A cached copy of local->tx_pos. Only write to local->tx_pos, and read 		from remote->tx_pos. */
name|int
name|local_tx_pos
decl_stmt|;
comment|/* The slot_queue index of the slot to become available next. */
name|int
name|slot_queue_available
decl_stmt|;
comment|/* A flag to indicate if any poll has been requested */
name|int
name|poll_needed
decl_stmt|;
comment|/* Ths index of the previous slot used for data messages. */
name|int
name|previous_data_index
decl_stmt|;
comment|/* The number of slots occupied by data messages. */
name|unsigned
name|short
name|data_use_count
decl_stmt|;
comment|/* The maximum number of slots to be occupied by data messages. */
name|unsigned
name|short
name|data_quota
decl_stmt|;
comment|/* An array of bit sets indicating which services must be polled. */
name|atomic_t
name|poll_services
index|[
name|BITSET_SIZE
argument_list|(
name|VCHIQ_MAX_SERVICES
argument_list|)
index|]
decl_stmt|;
comment|/* The number of the first unused service */
name|int
name|unused_service
decl_stmt|;
comment|/* Signalled when a free slot becomes available. */
name|struct
name|semaphore
name|slot_available_event
decl_stmt|;
name|struct
name|semaphore
name|slot_remove_event
decl_stmt|;
comment|/* Signalled when a free data slot becomes available. */
name|struct
name|semaphore
name|data_quota_event
decl_stmt|;
comment|/* Incremented when there are bulk transfers which cannot be processed 	 * whilst paused and must be processed on resume */
name|int
name|deferred_bulks
decl_stmt|;
struct|struct
name|state_stats_struct
block|{
name|int
name|slot_stalls
decl_stmt|;
name|int
name|data_stalls
decl_stmt|;
name|int
name|ctrl_tx_count
decl_stmt|;
name|int
name|ctrl_rx_count
decl_stmt|;
name|int
name|error_count
decl_stmt|;
block|}
name|stats
struct|;
name|VCHIQ_SERVICE_T
modifier|*
name|services
index|[
name|VCHIQ_MAX_SERVICES
index|]
decl_stmt|;
name|VCHIQ_SERVICE_QUOTA_T
name|service_quotas
index|[
name|VCHIQ_MAX_SERVICES
index|]
decl_stmt|;
name|VCHIQ_SLOT_INFO_T
name|slot_info
index|[
name|VCHIQ_MAX_SLOTS
index|]
decl_stmt|;
name|VCHIQ_PLATFORM_STATE_T
name|platform_state
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bulk_waiter
block|{
name|VCHIQ_BULK_T
modifier|*
name|bulk
decl_stmt|;
name|struct
name|semaphore
name|event
decl_stmt|;
name|int
name|actual
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|spinlock_t
name|bulk_waiter_spinlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vchiq_core_log_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vchiq_core_msg_log_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vchiq_sync_log_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VCHIQ_STATE_T
modifier|*
name|vchiq_states
index|[
name|VCHIQ_MAX_STATES
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|get_conn_state_name
parameter_list|(
name|VCHIQ_CONNSTATE_T
name|conn_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_SLOT_ZERO_T
modifier|*
name|vchiq_init_slots
parameter_list|(
name|void
modifier|*
name|mem_base
parameter_list|,
name|int
name|mem_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_init_state
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_SLOT_ZERO_T
modifier|*
name|slot_zero
parameter_list|,
name|int
name|is_master
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_connect_internal
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_INSTANCE_T
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_SERVICE_T
modifier|*
name|vchiq_add_service_internal
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
specifier|const
name|VCHIQ_SERVICE_PARAMS_T
modifier|*
name|params
parameter_list|,
name|int
name|srvstate
parameter_list|,
name|VCHIQ_INSTANCE_T
name|instance
parameter_list|,
name|VCHIQ_USERDATA_TERM_T
name|userdata_term
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_open_service_internal
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|,
name|int
name|client_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_close_service_internal
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|,
name|int
name|close_recvd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_terminate_service_internal
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_free_service_internal
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_shutdown_internal
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_INSTANCE_T
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_pause_internal
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_resume_internal
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remote_event_pollall
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_bulk_transfer
parameter_list|(
name|VCHIQ_SERVICE_HANDLE_T
name|handle
parameter_list|,
name|VCHI_MEM_HANDLE_T
name|memhandle
parameter_list|,
name|void
modifier|*
name|offset
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|userdata
parameter_list|,
name|VCHIQ_BULK_MODE_T
name|mode
parameter_list|,
name|VCHIQ_BULK_DIR_T
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump_state
parameter_list|(
name|void
modifier|*
name|dump_context
parameter_list|,
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump_service_state
parameter_list|(
name|void
modifier|*
name|dump_context
parameter_list|,
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_loud_error_header
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_loud_error_footer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|request_poll
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|,
name|int
name|poll_type
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|VCHIQ_SERVICE_T
modifier|*
name|handle_to_service
parameter_list|(
name|VCHIQ_SERVICE_HANDLE_T
name|handle
parameter_list|)
block|{
name|VCHIQ_STATE_T
modifier|*
name|state
init|=
name|vchiq_states
index|[
operator|(
name|handle
operator|/
name|VCHIQ_MAX_SERVICES
operator|)
operator|&
operator|(
name|VCHIQ_MAX_STATES
operator|-
literal|1
operator|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|state
condition|)
return|return
name|NULL
return|;
return|return
name|state
operator|->
name|services
index|[
name|handle
operator|&
operator|(
name|VCHIQ_MAX_SERVICES
operator|-
literal|1
operator|)
index|]
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|VCHIQ_SERVICE_T
modifier|*
name|find_service_by_handle
parameter_list|(
name|VCHIQ_SERVICE_HANDLE_T
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_SERVICE_T
modifier|*
name|find_service_by_port
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|int
name|localport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_SERVICE_T
modifier|*
name|find_service_for_instance
parameter_list|(
name|VCHIQ_INSTANCE_T
name|instance
parameter_list|,
name|VCHIQ_SERVICE_HANDLE_T
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_SERVICE_T
modifier|*
name|next_service_by_instance
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_INSTANCE_T
name|instance
parameter_list|,
name|int
modifier|*
name|pidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lock_service
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unlock_service
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following functions are called from vchiq_core, and external ** implementations must be provided. */
end_comment

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_prepare_bulk_data
parameter_list|(
name|VCHIQ_BULK_T
modifier|*
name|bulk
parameter_list|,
name|VCHI_MEM_HANDLE_T
name|memhandle
parameter_list|,
name|void
modifier|*
name|offset
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_transfer_bulk
parameter_list|(
name|VCHIQ_BULK_T
modifier|*
name|bulk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_complete_bulk
parameter_list|(
name|VCHIQ_BULK_T
modifier|*
name|bulk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_copy_from_user
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remote_event_signal
parameter_list|(
name|REMOTE_EVENT_T
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vchiq_platform_check_suspend
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_platform_paused
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_platform_resume
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_platform_resumed
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump
parameter_list|(
name|void
modifier|*
name|dump_context
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump_platform_state
parameter_list|(
name|void
modifier|*
name|dump_context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump_platform_instances
parameter_list|(
name|void
modifier|*
name|dump_context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_dump_platform_service_state
parameter_list|(
name|void
modifier|*
name|dump_context
parameter_list|,
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_use_service_internal
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_release_service_internal
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_on_remote_use
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_on_remote_release
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_platform_init_state
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_check_service
parameter_list|(
name|VCHIQ_SERVICE_T
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_on_remote_use_active
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_send_remote_use
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_send_remote_release
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VCHIQ_STATUS_T
name|vchiq_send_remote_use_active
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_platform_conn_state_changed
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_CONNSTATE_T
name|oldstate
parameter_list|,
name|VCHIQ_CONNSTATE_T
name|newstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_platform_handle_timeout
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_set_conn_state
parameter_list|(
name|VCHIQ_STATE_T
modifier|*
name|state
parameter_list|,
name|VCHIQ_CONNSTATE_T
name|newstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_log_dump_mem
parameter_list|(
specifier|const
name|char
modifier|*
name|label
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
specifier|const
name|void
modifier|*
name|voidMem
parameter_list|,
name|size_t
name|numBytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vchiq_core_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

