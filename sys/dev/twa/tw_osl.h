begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_OSL_H
end_ifndef

begin_define
define|#
directive|define
name|TW_OSL_H
end_define

begin_comment
comment|/*  * OS Layer internal macros, structures and functions.  */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_DEVICE_NAME
value|"3ware 9000 series Storage Controller"
end_define

begin_define
define|#
directive|define
name|TW_OSLI_MALLOC_CLASS
value|M_TWA
end_define

begin_define
define|#
directive|define
name|TW_OSLI_MAX_NUM_IOS
value|TW_CL_MAX_SIMULTANEOUS_REQUESTS
end_define

begin_define
define|#
directive|define
name|TW_OSLI_MAX_NUM_AENS
value|0x100
end_define

begin_define
define|#
directive|define
name|TW_OSLI_DEFERRED_INTR_USED
end_define

begin_comment
comment|/* Possible values of req->state. */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_STATE_INIT
value|0x0
end_define

begin_comment
comment|/* being initialized */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_STATE_BUSY
value|0x1
end_define

begin_comment
comment|/* submitted to CL */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_STATE_PENDING
value|0x2
end_define

begin_comment
comment|/* in pending queue */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_STATE_COMPLETE
value|0x3
end_define

begin_comment
comment|/* completed by CL */
end_comment

begin_comment
comment|/* Possible values of req->flags. */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_FLAGS_DATA_IN
value|(1<<0)
end_define

begin_comment
comment|/* read request */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_FLAGS_DATA_OUT
value|(1<<1)
end_define

begin_comment
comment|/* write request */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_FLAGS_DATA_COPY_NEEDED
value|(1<<2)
end_define

begin_comment
comment|/* data in ccb is misaligned, 					have to copy to/from private buffer */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_FLAGS_MAPPED
value|(1<<3)
end_define

begin_comment
comment|/* request has been mapped */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_FLAGS_IN_PROGRESS
value|(1<<4)
end_define

begin_comment
comment|/* bus_dmamap_load returned 						EINPROGRESS */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_FLAGS_PASSTHRU
value|(1<<5)
end_define

begin_comment
comment|/* pass through request */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_REQ_FLAGS_SLEEPING
value|(1<<6)
end_define

begin_comment
comment|/* owner sleeping on this cmd */
end_comment

begin_comment
comment|/* Possible values of sc->state. */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_CTLR_STATE_OPEN
value|(1<<0)
end_define

begin_comment
comment|/* control device is open */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_CTLR_STATE_SIMQ_FROZEN
value|(1<<1)
end_define

begin_comment
comment|/* simq frozen */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_struct
struct|struct
name|tw_osli_q_stats
block|{
name|TW_UINT32
name|cur_len
decl_stmt|;
comment|/* current # of items in q */
name|TW_UINT32
name|max_len
decl_stmt|;
comment|/* max value reached by q_length */
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
comment|/* Queues of OSL internal request context packets. */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_FREE_Q
value|0
end_define

begin_comment
comment|/* free q */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_BUSY_Q
value|1
end_define

begin_comment
comment|/* q of reqs submitted to CL */
end_comment

begin_define
define|#
directive|define
name|TW_OSLI_Q_COUNT
value|2
end_define

begin_comment
comment|/* total number of queues */
end_comment

begin_comment
comment|/* Driver's request packet. */
end_comment

begin_struct
struct|struct
name|tw_osli_req_context
block|{
name|struct
name|tw_cl_req_handle
name|req_handle
decl_stmt|;
comment|/* tag to track req b/w OSL& CL */
name|struct
name|twa_softc
modifier|*
name|ctlr
decl_stmt|;
comment|/* ptr to OSL's controller context */
name|TW_VOID
modifier|*
name|data
decl_stmt|;
comment|/* ptr to data being passed to CL */
name|TW_UINT32
name|length
decl_stmt|;
comment|/* length of buf being passed to CL */
comment|/* 	 * ptr to, and length of data passed to us from above, in case a buffer 	 * copy was done due to non-compliance to alignment requirements 	 */
name|TW_VOID
modifier|*
name|real_data
decl_stmt|;
name|TW_UINT32
name|real_length
decl_stmt|;
name|TW_UINT32
name|state
decl_stmt|;
comment|/* request state */
name|TW_UINT32
name|flags
decl_stmt|;
comment|/* request flags */
comment|/* error encountered before request submission to CL */
name|TW_UINT32
name|error_code
decl_stmt|;
comment|/* ptr to orig req for use during callback */
name|TW_VOID
modifier|*
name|orig_req
decl_stmt|;
name|struct
name|tw_cl_link
name|link
decl_stmt|;
comment|/* to link this request in a list */
name|bus_dmamap_t
name|dma_map
decl_stmt|;
comment|/* DMA map for data */
name|struct
name|tw_cl_req_packet
name|req_pkt
decl_stmt|;
comment|/* req pkt understood by CL */
block|}
struct|;
end_struct

begin_comment
comment|/* Per-controller structure. */
end_comment

begin_struct
struct|struct
name|twa_softc
block|{
name|struct
name|tw_cl_ctlr_handle
name|ctlr_handle
decl_stmt|;
name|struct
name|tw_osli_req_context
modifier|*
name|req_ctxt_buf
decl_stmt|;
comment|/* Controller state. */
name|TW_UINT32
name|state
decl_stmt|;
name|TW_UINT32
name|flags
decl_stmt|;
name|TW_INT32
name|device_id
decl_stmt|;
name|TW_UINT32
name|alignment
decl_stmt|;
name|TW_UINT32
name|sg_size_factor
decl_stmt|;
name|TW_VOID
modifier|*
name|non_dma_mem
decl_stmt|;
name|TW_VOID
modifier|*
name|dma_mem
decl_stmt|;
name|TW_UINT64
name|dma_mem_phys
decl_stmt|;
comment|/* Request queues and arrays. */
name|struct
name|tw_cl_link
name|req_q_head
index|[
name|TW_OSLI_Q_COUNT
index|]
decl_stmt|;
name|struct
name|task
name|deferred_intr_callback
decl_stmt|;
comment|/* taskqueue function */
name|struct
name|mtx
name|io_lock_handle
decl_stmt|;
comment|/* general purpose lock */
name|struct
name|mtx
modifier|*
name|io_lock
decl_stmt|;
comment|/* ptr to general purpose lock */
name|struct
name|mtx
name|q_lock_handle
decl_stmt|;
comment|/* queue manipulation lock */
name|struct
name|mtx
modifier|*
name|q_lock
decl_stmt|;
comment|/* ptr to queue manipulation lock */
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
name|struct
name|tw_osli_q_stats
name|q_stats
index|[
name|TW_OSLI_Q_COUNT
index|]
decl_stmt|;
comment|/* queue statistics */
endif|#
directive|endif
comment|/* TW_OSL_DEBUG */
name|device_t
name|bus_dev
decl_stmt|;
comment|/* bus device */
name|struct
name|cdev
modifier|*
name|ctrl_dev
decl_stmt|;
comment|/* control device */
name|struct
name|resource
modifier|*
name|reg_res
decl_stmt|;
comment|/* register interface window */
name|TW_INT32
name|reg_res_id
decl_stmt|;
comment|/* register resource id */
name|bus_space_handle_t
name|bus_handle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|bus_tag
decl_stmt|;
comment|/* bus space tag */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|cmd_tag
decl_stmt|;
comment|/* DMA tag for CL's DMA'able mem */
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
comment|/* data buffer DMA tag */
name|bus_dma_tag_t
name|ioctl_tag
decl_stmt|;
comment|/* ioctl data buffer DMA tag */
name|bus_dmamap_t
name|cmd_map
decl_stmt|;
comment|/* DMA map for CL's DMA'able mem */
name|bus_dmamap_t
name|ioctl_map
decl_stmt|;
comment|/* DMA map for ioctl data buffers */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* interrupt resource */
name|TW_INT32
name|irq_res_id
decl_stmt|;
comment|/* register resource id */
name|TW_VOID
modifier|*
name|intr_handle
decl_stmt|;
comment|/* interrupt handle */
name|struct
name|sysctl_ctx_list
name|sysctl_ctxt
decl_stmt|;
comment|/* sysctl context */
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
decl_stmt|;
comment|/* sysctl oid */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
comment|/* sim for this controller */
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
comment|/* peripheral, path, tgt, lun 					associated with this controller */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Queue primitives.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TW_OSLI_Q_INIT
parameter_list|(
name|sc
parameter_list|,
name|q_type
parameter_list|)
value|do {				\ 	(sc)->q_stats[q_type].cur_len = 0;				\ 	(sc)->q_stats[q_type].max_len = 0;				\ } while(0)
end_define

begin_define
define|#
directive|define
name|TW_OSLI_Q_INSERT
parameter_list|(
name|sc
parameter_list|,
name|q_type
parameter_list|)
value|do {				\ 	struct tw_osli_q_stats *q_stats =&((sc)->q_stats[q_type]);	\ 									\ 	if (++(q_stats->cur_len)> q_stats->max_len)			\ 		q_stats->max_len = q_stats->cur_len;			\ } while(0)
end_define

begin_define
define|#
directive|define
name|TW_OSLI_Q_REMOVE
parameter_list|(
name|sc
parameter_list|,
name|q_type
parameter_list|)
define|\
value|(sc)->q_stats[q_type].cur_len--
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
name|TW_OSLI_Q_INIT
parameter_list|(
name|sc
parameter_list|,
name|q_index
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TW_OSLI_Q_INSERT
parameter_list|(
name|sc
parameter_list|,
name|q_index
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TW_OSLI_Q_REMOVE
parameter_list|(
name|sc
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
name|tw_osli_req_q_init
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|TW_CL_Q_INIT
argument_list|(
operator|&
operator|(
name|sc
operator|->
name|req_q_head
index|[
name|q_type
index|]
operator|)
argument_list|)
expr_stmt|;
name|TW_OSLI_Q_INIT
argument_list|(
name|sc
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
name|tw_osli_req_q_insert_head
parameter_list|(
name|struct
name|tw_osli_req_context
modifier|*
name|req
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|mtx_lock_spin
argument_list|(
name|req
operator|->
name|ctlr
operator|->
name|q_lock
argument_list|)
expr_stmt|;
name|TW_CL_Q_INSERT_HEAD
argument_list|(
operator|&
operator|(
name|req
operator|->
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
name|TW_OSLI_Q_INSERT
argument_list|(
name|req
operator|->
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
name|req
operator|->
name|ctlr
operator|->
name|q_lock
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
name|tw_osli_req_q_insert_tail
parameter_list|(
name|struct
name|tw_osli_req_context
modifier|*
name|req
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|mtx_lock_spin
argument_list|(
name|req
operator|->
name|ctlr
operator|->
name|q_lock
argument_list|)
expr_stmt|;
name|TW_CL_Q_INSERT_TAIL
argument_list|(
operator|&
operator|(
name|req
operator|->
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
name|TW_OSLI_Q_INSERT
argument_list|(
name|req
operator|->
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
name|req
operator|->
name|ctlr
operator|->
name|q_lock
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
name|tw_osli_req_context
operator|*
name|tw_osli_req_q_remove_head
argument_list|(
argument|struct twa_softc *sc
argument_list|,
argument|TW_UINT8 q_type
argument_list|)
block|{ 	struct
name|tw_osli_req_context
operator|*
name|req
operator|=
name|NULL
block|; 	struct
name|tw_cl_link
operator|*
name|link
block|;
name|mtx_lock_spin
argument_list|(
name|sc
operator|->
name|q_lock
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
name|sc
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
name|tw_osli_req_context
argument_list|,
name|link
argument_list|)
expr_stmt|;
name|TW_CL_Q_REMOVE_ITEM
argument_list|(
operator|&
operator|(
name|sc
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
name|TW_OSLI_Q_REMOVE
argument_list|(
name|sc
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
block|}
name|mtx_unlock_spin
argument_list|(
name|sc
operator|->
name|q_lock
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
name|tw_osli_req_q_remove_item
parameter_list|(
name|struct
name|tw_osli_req_context
modifier|*
name|req
parameter_list|,
name|TW_UINT8
name|q_type
parameter_list|)
block|{
name|mtx_lock_spin
argument_list|(
name|req
operator|->
name|ctlr
operator|->
name|q_lock
argument_list|)
expr_stmt|;
name|TW_CL_Q_REMOVE_ITEM
argument_list|(
operator|&
operator|(
name|req
operator|->
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
name|TW_OSLI_Q_REMOVE
argument_list|(
name|req
operator|->
name|ctlr
argument_list|,
name|q_type
argument_list|)
expr_stmt|;
name|mtx_unlock_spin
argument_list|(
name|req
operator|->
name|ctlr
operator|->
name|q_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|TW_INT32
name|TW_DEBUG_LEVEL_FOR_OSL
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tw_osli_dbg_dprintf
parameter_list|(
name|dbg_level
parameter_list|,
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (dbg_level<= TW_DEBUG_LEVEL_FOR_OSL)			\ 		device_printf(sc->bus_dev, "%s: " fmt "\n",		\ 			__func__, ##args)
end_define

begin_define
define|#
directive|define
name|tw_osli_dbg_printf
parameter_list|(
name|dbg_level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (dbg_level<= TW_DEBUG_LEVEL_FOR_OSL)			\ 		printf("%s: " fmt "\n",	__func__, ##args)
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
name|tw_osli_dbg_dprintf
parameter_list|(
name|dbg_level
parameter_list|,
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|tw_osli_dbg_printf
parameter_list|(
name|dbg_level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
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
comment|/* For regular printing. */
end_comment

begin_define
define|#
directive|define
name|twa_printf
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|device_printf(((struct twa_softc *)(sc))->bus_dev, fmt, ##args)
end_define

begin_comment
comment|/* For printing in the "consistent error reporting" format. */
end_comment

begin_define
define|#
directive|define
name|tw_osli_printf
parameter_list|(
name|sc
parameter_list|,
name|err_specific_desc
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|device_printf((sc)->bus_dev,					\ 		"%s: (0x%02X: 0x%04X): %s: " err_specific_desc "\n", ##args)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_H */
end_comment

end_unit

