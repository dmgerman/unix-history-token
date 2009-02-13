begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_CL_H
end_ifndef

begin_define
define|#
directive|define
name|TW_CL_H
end_define

begin_comment
comment|/*  * Common Layer internal macros, structures and functions.  */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_SECTOR_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|TW_CLI_REQUEST_TIMEOUT_PERIOD
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_RESET_TIMEOUT_PERIOD
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_MAX_RESET_ATTEMPTS
value|2
end_define

begin_comment
comment|/* Possible values of ctlr->state. */
end_comment

begin_comment
comment|/* Initialization done, and controller is active. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_CTLR_STATE_ACTIVE
value|(1<<0)
end_define

begin_comment
comment|/* Interrupts on controller enabled. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_CTLR_STATE_INTR_ENABLED
value|(1<<1)
end_define

begin_comment
comment|/* Data buffer for internal requests in use. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_CTLR_STATE_INTERNAL_REQ_BUSY
value|(1<<2)
end_define

begin_comment
comment|/* More AEN's need to be retrieved. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_CTLR_STATE_GET_MORE_AENS
value|(1<<3)
end_define

begin_comment
comment|/* Controller is being reset. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_CTLR_STATE_RESET_IN_PROGRESS
value|(1<<4)
end_define

begin_comment
comment|/* G133 controller is in 'phase 1' of being reset. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_CTLR_STATE_RESET_PHASE1_IN_PROGRESS
value|(1<<5)
end_define

begin_comment
comment|/* G66 register write access bug needs to be worked around. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_CTLR_STATE_G66_WORKAROUND_NEEDED
value|(1<<6)
end_define

begin_comment
comment|/* Possible values of ctlr->ioctl_lock.lock. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_LOCK_FREE
value|0x0
end_define

begin_comment
comment|/* lock is free */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_LOCK_HELD
value|0x1
end_define

begin_comment
comment|/* lock is held */
end_comment

begin_comment
comment|/* Possible values of req->state. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_STATE_INIT
value|0x0
end_define

begin_comment
comment|/* being initialized */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_STATE_BUSY
value|0x1
end_define

begin_comment
comment|/* submitted to controller */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_STATE_PENDING
value|0x2
end_define

begin_comment
comment|/* in pending queue */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_STATE_COMPLETE
value|0x3
end_define

begin_comment
comment|/* completed by controller */
end_comment

begin_comment
comment|/* Possible values of req->flags. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_FLAGS_7K
value|(1<<0)
end_define

begin_comment
comment|/* 7000 cmd pkt */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_FLAGS_9K
value|(1<<1)
end_define

begin_comment
comment|/* 9000 cmd pkt */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_FLAGS_INTERNAL
value|(1<<2)
end_define

begin_comment
comment|/* internal request */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_FLAGS_PASSTHRU
value|(1<<3)
end_define

begin_comment
comment|/* passthru request */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_REQ_FLAGS_EXTERNAL
value|(1<<4)
end_define

begin_comment
comment|/* external request */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_PCI_CONFIG_ACCESSIBLE
end_ifdef

begin_comment
comment|/* Register offsets in PCI config space. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_PCI_CONFIG_COMMAND_OFFSET
value|0x4
end_define

begin_comment
comment|/* cmd register offset */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_PCI_CONFIG_STATUS_OFFSET
value|0x6
end_define

begin_comment
comment|/* status register offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_PCI_CONFIG_ACCESSIBLE */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_struct
struct|struct
name|tw_cli_q_stats
block|{
name|TW_UINT32
name|cur_len
decl_stmt|;
comment|/* current # of entries in q */
name|TW_UINT32
name|max_len
decl_stmt|;
comment|/* max # of entries in q, ever reached */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_comment
comment|/* Queues of CL internal request context packets. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_FREE_Q
value|0
end_define

begin_comment
comment|/* free q */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_BUSY_Q
value|1
end_define

begin_comment
comment|/* q of reqs submitted to fw */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_PENDING_Q
value|2
end_define

begin_comment
comment|/* q of reqs deferred due to 'q full' */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_COMPLETE_Q
value|3
end_define

begin_comment
comment|/* q of reqs completed by fw */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_Q_COUNT
value|4
end_define

begin_comment
comment|/* total number of queues */
end_comment

begin_comment
comment|/* CL's internal request context. */
end_comment

begin_struct
struct|struct
name|tw_cli_req_context
block|{
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
decl_stmt|;
comment|/* handle to track requests between 						OSL& CL */
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
decl_stmt|;
comment|/* ptr to CL's controller context */
name|struct
name|tw_cl_command_packet
modifier|*
name|cmd_pkt
decl_stmt|;
comment|/* ptr to ctlr cmd pkt */
name|TW_UINT64
name|cmd_pkt_phys
decl_stmt|;
comment|/* cmd pkt physical address */
name|TW_VOID
modifier|*
name|data
decl_stmt|;
comment|/* ptr to data being passed to fw */
name|TW_UINT32
name|length
decl_stmt|;
comment|/* length of data being passed to fw */
name|TW_UINT64
name|data_phys
decl_stmt|;
comment|/* physical address of data */
name|TW_UINT32
name|state
decl_stmt|;
comment|/* request state */
name|TW_UINT32
name|flags
decl_stmt|;
comment|/* request flags */
name|TW_UINT32
name|error_code
decl_stmt|;
comment|/* error encountered before submission 					of request to fw, if any */
name|TW_VOID
modifier|*
name|orig_req
decl_stmt|;
comment|/* ptr to original request for use 					during callback */
name|TW_VOID
function_decl|(
modifier|*
name|tw_cli_callback
function_decl|)
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
comment|/* CL internal callback */
name|TW_UINT32
name|request_id
decl_stmt|;
comment|/* request id for tracking with fw */
name|struct
name|tw_cl_link
name|link
decl_stmt|;
comment|/* to link this request in a list */
block|}
struct|;
end_struct

begin_comment
comment|/* CL's internal controller context. */
end_comment

begin_struct
struct|struct
name|tw_cli_ctlr_context
block|{
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
decl_stmt|;
comment|/* handle to track ctlr between 							OSL& CL. */
name|struct
name|tw_cli_req_context
modifier|*
name|req_ctxt_buf
decl_stmt|;
comment|/* pointer to the array of CL's 						internal request context pkts */
name|struct
name|tw_cl_command_packet
modifier|*
name|cmd_pkt_buf
decl_stmt|;
comment|/* ptr to array of cmd pkts */
name|TW_UINT64
name|cmd_pkt_phys
decl_stmt|;
comment|/* phys addr of cmd_pkt_buf */
name|TW_UINT32
name|device_id
decl_stmt|;
comment|/* controller device id */
name|TW_UINT32
name|arch_id
decl_stmt|;
comment|/* controller architecture id */
name|TW_UINT32
name|state
decl_stmt|;
comment|/* controller state */
name|TW_UINT32
name|flags
decl_stmt|;
comment|/* controller settings */
name|TW_UINT32
name|sg_size_factor
decl_stmt|;
comment|/* SG element size should be a 							multiple of this */
comment|/* Request queues and arrays. */
name|struct
name|tw_cl_link
name|req_q_head
index|[
name|TW_CLI_Q_COUNT
index|]
decl_stmt|;
name|TW_UINT8
modifier|*
name|internal_req_data
decl_stmt|;
comment|/* internal req data buf */
name|TW_UINT64
name|internal_req_data_phys
decl_stmt|;
comment|/* phys addr of internal 							req data buf */
name|TW_UINT32
name|max_simult_reqs
decl_stmt|;
comment|/* max simultaneous requests 							supported */
name|TW_UINT32
name|max_aens_supported
decl_stmt|;
comment|/* max AEN's supported */
comment|/* AEN handler fields. */
name|struct
name|tw_cl_event_packet
modifier|*
name|aen_queue
decl_stmt|;
comment|/* circular queue of AENs from 							firmware/CL/OSL */
name|TW_UINT32
name|aen_head
decl_stmt|;
comment|/* AEN queue head */
name|TW_UINT32
name|aen_tail
decl_stmt|;
comment|/* AEN queue tail */
name|TW_UINT32
name|aen_cur_seq_id
decl_stmt|;
comment|/* index of the last event+1 */
name|TW_UINT32
name|aen_q_overflow
decl_stmt|;
comment|/* indicates if unretrieved 						events were overwritten */
name|TW_UINT32
name|aen_q_wrapped
decl_stmt|;
comment|/* indicates if AEN queue ever 							wrapped */
name|TW_UINT16
name|working_srl
decl_stmt|;
comment|/* driver& firmware negotiated 							srl */
name|TW_UINT16
name|working_branch
decl_stmt|;
comment|/* branch # of the firmware 					that the driver is compatible with */
name|TW_UINT16
name|working_build
decl_stmt|;
comment|/* build # of the firmware 					that the driver is compatible with */
name|TW_UINT16
name|fw_on_ctlr_srl
decl_stmt|;
comment|/* srl of running firmware */
name|TW_UINT16
name|fw_on_ctlr_branch
decl_stmt|;
comment|/* branch # of running 							firmware */
name|TW_UINT16
name|fw_on_ctlr_build
decl_stmt|;
comment|/* build # of running 							firmware */
name|TW_UINT32
name|operating_mode
decl_stmt|;
comment|/* base mode/current mode */
name|TW_INT32
name|host_intr_pending
decl_stmt|;
comment|/* host intr processing 							needed */
name|TW_INT32
name|attn_intr_pending
decl_stmt|;
comment|/* attn intr processing 							needed */
name|TW_INT32
name|cmd_intr_pending
decl_stmt|;
comment|/* cmd intr processing 							needed */
name|TW_INT32
name|resp_intr_pending
decl_stmt|;
comment|/* resp intr processing 							needed */
name|TW_LOCK_HANDLE
name|gen_lock_handle
decl_stmt|;
comment|/* general purpose lock */
name|TW_LOCK_HANDLE
modifier|*
name|gen_lock
decl_stmt|;
comment|/* ptr to general purpose lock */
name|TW_LOCK_HANDLE
name|io_lock_handle
decl_stmt|;
comment|/* lock held during cmd 						submission */
name|TW_LOCK_HANDLE
modifier|*
name|io_lock
decl_stmt|;
comment|/* ptr to lock held during cmd 						submission */
name|TW_LOCK_HANDLE
name|intr_lock_handle
decl_stmt|;
comment|/* lock held during 						ISR/response intr processing */
name|TW_LOCK_HANDLE
modifier|*
name|intr_lock
decl_stmt|;
comment|/* ptr to lock held during ISR/ 						response intr processing */
ifdef|#
directive|ifdef
name|TW_OSL_CAN_SLEEP
name|TW_SLEEP_HANDLE
name|sleep_handle
decl_stmt|;
comment|/* handle to co-ordinate sleeps& wakeups */
endif|#
directive|endif
comment|/* TW_OSL_CAN_SLEEP */
struct|struct
block|{
name|TW_UINT32
name|lock
decl_stmt|;
comment|/* lock state */
name|TW_TIME
name|timeout
decl_stmt|;
comment|/* time at which the lock will 						become available, even if not 						explicitly released */
block|}
name|ioctl_lock
struct|;
comment|/* lock for use by user applications, for 				synchronization between ioctl calls */
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
name|struct
name|tw_cli_q_stats
name|q_stats
index|[
name|TW_CLI_Q_COUNT
index|]
decl_stmt|;
comment|/* queue statistics */
endif|#
directive|endif
comment|/* TW_OSL_DEBUG */
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * Queue primitives  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TW_CLI_Q_INIT
parameter_list|(
name|ctlr
parameter_list|,
name|q_type
parameter_list|)
value|do {				\ 	(ctlr)->q_stats[q_type].cur_len = 0;				\ 	(ctlr)->q_stats[q_type].max_len = 0;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|TW_CLI_Q_INSERT
parameter_list|(
name|ctlr
parameter_list|,
name|q_type
parameter_list|)
value|do {				\ 	struct tw_cli_q_stats *q_stats =&((ctlr)->q_stats[q_type]);	\ 									\ 	if (++(q_stats->cur_len)> q_stats->max_len)			\ 		q_stats->max_len = q_stats->cur_len;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|TW_CLI_Q_REMOVE
parameter_list|(
name|ctlr
parameter_list|,
name|q_type
parameter_list|)
define|\
value|(ctlr)->q_stats[q_type].cur_len--
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_Q_INIT
parameter_list|(
name|ctlr
parameter_list|,
name|q_index
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TW_CLI_Q_INSERT
parameter_list|(
name|ctlr
parameter_list|,
name|q_index
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TW_CLI_Q_REMOVE
parameter_list|(
name|ctlr
parameter_list|,
name|q_index
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_comment
comment|/* Initialize a queue of requests. */
end_comment

begin_function
specifier|static
name|__inline
name|TW_VOID
name|tw_cli_req_q_init
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|TW_CL_Q_INIT
argument_list|(
operator|&
operator|(
name|ctlr
operator|->
name|req_q_head
index|[
name|q_type
index|]
operator|)
argument_list|)
expr_stmt|;
name|TW_CLI_Q_INIT
argument_list|(
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Insert the given request at the head of the given queue (q_type). */
end_comment

begin_function
specifier|static
name|__inline
name|TW_VOID
name|tw_cli_req_q_insert_head
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
init|=
name|req
operator|->
name|ctlr
decl_stmt|;
name|tw_osl_get_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
expr_stmt|;
name|TW_CL_Q_INSERT_HEAD
argument_list|(
operator|&
operator|(
name|ctlr
operator|->
name|req_q_head
index|[
name|q_type
index|]
operator|)
argument_list|,
operator|&
operator|(
name|req
operator|->
name|link
operator|)
argument_list|)
expr_stmt|;
name|TW_CLI_Q_INSERT
argument_list|(
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
name|tw_osl_free_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Insert the given request at the tail of the given queue (q_type). */
end_comment

begin_function
specifier|static
name|__inline
name|TW_VOID
name|tw_cli_req_q_insert_tail
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
init|=
name|req
operator|->
name|ctlr
decl_stmt|;
name|tw_osl_get_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
expr_stmt|;
name|TW_CL_Q_INSERT_TAIL
argument_list|(
operator|&
operator|(
name|ctlr
operator|->
name|req_q_head
index|[
name|q_type
index|]
operator|)
argument_list|,
operator|&
operator|(
name|req
operator|->
name|link
operator|)
argument_list|)
expr_stmt|;
name|TW_CLI_Q_INSERT
argument_list|(
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
name|tw_osl_free_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Remove and return the request at the head of the given queue (q_type). */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|tw_cli_req_context
operator|*
name|tw_cli_req_q_remove_head
argument_list|(
argument|struct tw_cli_ctlr_context *ctlr
argument_list|,
argument|TW_UINT8 q_type
argument_list|)
block|{ 	struct
name|tw_cli_req_context
operator|*
name|req
operator|=
name|TW_CL_NULL
block|; 	struct
name|tw_cl_link
operator|*
name|link
block|;
name|tw_osl_get_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
block|;
if|if
condition|(
operator|(
name|link
operator|=
name|TW_CL_Q_FIRST_ITEM
argument_list|(
operator|&
operator|(
name|ctlr
operator|->
name|req_q_head
index|[
name|q_type
index|]
operator|)
argument_list|)
operator|)
operator|!=
name|TW_CL_NULL
condition|)
block|{
name|req
operator|=
name|TW_CL_STRUCT_HEAD
argument_list|(
name|link
argument_list|,
expr|struct
name|tw_cli_req_context
argument_list|,
name|link
argument_list|)
expr_stmt|;
name|TW_CL_Q_REMOVE_ITEM
argument_list|(
operator|&
operator|(
name|ctlr
operator|->
name|req_q_head
index|[
name|q_type
index|]
operator|)
argument_list|,
operator|&
operator|(
name|req
operator|->
name|link
operator|)
argument_list|)
expr_stmt|;
name|TW_CLI_Q_REMOVE
argument_list|(
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
block|}
name|tw_osl_free_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|req
operator|)
return|;
end_return

begin_comment
unit|}
comment|/* Remove the given request from the given queue (q_type). */
end_comment

begin_function
unit|static
name|__inline
name|TW_VOID
name|tw_cli_req_q_remove_item
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
init|=
name|req
operator|->
name|ctlr
decl_stmt|;
name|tw_osl_get_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
expr_stmt|;
name|TW_CL_Q_REMOVE_ITEM
argument_list|(
operator|&
operator|(
name|ctlr
operator|->
name|req_q_head
index|[
name|q_type
index|]
operator|)
argument_list|,
operator|&
operator|(
name|req
operator|->
name|link
operator|)
argument_list|)
expr_stmt|;
name|TW_CLI_Q_REMOVE
argument_list|(
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
name|tw_osl_free_lock
argument_list|(
name|ctlr
operator|->
name|ctlr_handle
argument_list|,
name|ctlr
operator|->
name|gen_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Create an event packet for an event/error posted by the controller. */
end_comment

begin_define
define|#
directive|define
name|tw_cli_create_ctlr_event
parameter_list|(
name|ctlr
parameter_list|,
name|event_src
parameter_list|,
name|cmd_hdr
parameter_list|)
value|do {	\ 	TW_UINT8 severity =						\ 		GET_SEVERITY((cmd_hdr)->status_block.res__severity);	\ 									\ 	tw_cl_create_event(ctlr->ctlr_handle, TW_CL_TRUE, event_src,	\ 		(cmd_hdr)->status_block.error,				\ 		severity,						\ 		tw_cli_severity_string_table[severity],			\ 		(cmd_hdr)->err_specific_desc +				\ 		tw_osl_strlen((cmd_hdr)->err_specific_desc) + 1,	\ 		(cmd_hdr)->err_specific_desc);				\
comment|/* Print 18 bytes of sense information. */
value|\ 	tw_cli_dbg_printf(2, ctlr->ctlr_handle,				\ 		tw_osl_cur_func(),					\ 		"sense info: %x %x %x %x %x %x %x %x %x "		\ 		"%x %x %x %x %x %x %x %x %x",				\ 		(cmd_hdr)->sense_data[0], (cmd_hdr)->sense_data[1],	\ 		(cmd_hdr)->sense_data[2], (cmd_hdr)->sense_data[3],	\ 		(cmd_hdr)->sense_data[4], (cmd_hdr)->sense_data[5],	\ 		(cmd_hdr)->sense_data[6], (cmd_hdr)->sense_data[7],	\ 		(cmd_hdr)->sense_data[8], (cmd_hdr)->sense_data[9],	\ 		(cmd_hdr)->sense_data[10], (cmd_hdr)->sense_data[11],	\ 		(cmd_hdr)->sense_data[12], (cmd_hdr)->sense_data[13],	\ 		(cmd_hdr)->sense_data[14], (cmd_hdr)->sense_data[15],	\ 		(cmd_hdr)->sense_data[16], (cmd_hdr)->sense_data[17]);	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_CL_H */
end_comment

end_unit

