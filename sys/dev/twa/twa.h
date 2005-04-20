begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-04 3ware, Inc.  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  */
end_comment

begin_define
define|#
directive|define
name|TWA_DRIVER_VERSION_STRING
value|"2.50.02.012"
end_define

begin_define
define|#
directive|define
name|TWA_CDEV_MAJOR
value|MAJOR_AUTO
end_define

begin_define
define|#
directive|define
name|TWA_REQUEST_TIMEOUT_PERIOD
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|TWA_MESSAGE_SOURCE_CONTROLLER_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|TWA_MESSAGE_SOURCE_CONTROLLER_EVENT
value|4
end_define

begin_define
define|#
directive|define
name|TWA_MESSAGE_SOURCE_FREEBSD_DRIVER
value|6
end_define

begin_define
define|#
directive|define
name|TWA_MESSAGE_SOURCE_FREEBSD_OS
value|9
end_define

begin_define
define|#
directive|define
name|TWA_MALLOC_CLASS
value|M_TWA
end_define

begin_comment
comment|/* Macros for bus-space calls. */
end_comment

begin_define
define|#
directive|define
name|TWA_READ_REGISTER
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|(u_int32_t)bus_space_read_4(sc->twa_bus_tag, sc->twa_bus_handle, offset)
end_define

begin_define
define|#
directive|define
name|TWA_WRITE_REGISTER
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->twa_bus_tag, sc->twa_bus_handle, offset, (u_int32_t)val)
end_define

begin_comment
comment|/* Possible values of tr->tr_status. */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_SETUP
value|0x0
end_define

begin_comment
comment|/* being assembled */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_BUSY
value|0x1
end_define

begin_comment
comment|/* submitted to controller */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_PENDING
value|0x2
end_define

begin_comment
comment|/* in pending queue */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_COMPLETE
value|0x3
end_define

begin_comment
comment|/* completed by controller (maybe with error) */
end_comment

begin_comment
comment|/* Possible values of tr->tr_flags. */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_DATA_IN
value|(1<<0)
end_define

begin_comment
comment|/* read request */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_DATA_OUT
value|(1<<1)
end_define

begin_comment
comment|/* write request */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_DATA_COPY_NEEDED
value|(1<<2)
end_define

begin_comment
comment|/* data in ccb is misaligned, have to copy to/from private buffer */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_SLEEP_ON_REQUEST
value|(1<<3)
end_define

begin_comment
comment|/* owner is sleeping on this command */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_MAPPED
value|(1<<4)
end_define

begin_comment
comment|/* request has been mapped */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_IN_PROGRESS
value|(1<<5)
end_define

begin_comment
comment|/* bus_dmamap_load returned EINPROGRESS */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_TIMER_SET
value|(1<<6)
end_define

begin_comment
comment|/* request is being timed */
end_comment

begin_comment
comment|/* Possible values of tr->tr_cmd_pkt_type. */
end_comment

begin_define
define|#
directive|define
name|TWA_CMD_PKT_TYPE_7K
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TWA_CMD_PKT_TYPE_9K
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TWA_CMD_PKT_TYPE_INTERNAL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TWA_CMD_PKT_TYPE_IOCTL
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TWA_CMD_PKT_TYPE_EXTERNAL
value|(1<<4)
end_define

begin_comment
comment|/* Possible values of sc->twa_state. */
end_comment

begin_define
define|#
directive|define
name|TWA_STATE_INTR_ENABLED
value|(1<<0)
end_define

begin_comment
comment|/* interrupts have been enabled */
end_comment

begin_define
define|#
directive|define
name|TWA_STATE_SHUTDOWN
value|(1<<1)
end_define

begin_comment
comment|/* controller is shut down */
end_comment

begin_define
define|#
directive|define
name|TWA_STATE_OPEN
value|(1<<2)
end_define

begin_comment
comment|/* control device is open */
end_comment

begin_define
define|#
directive|define
name|TWA_STATE_SUSPEND
value|(1<<3)
end_define

begin_comment
comment|/* controller is suspended */
end_comment

begin_define
define|#
directive|define
name|TWA_STATE_SIMQ_FROZEN
value|(1<<4)
end_define

begin_comment
comment|/* simq frozen */
end_comment

begin_comment
comment|/* Possible values of sc->twa_ioctl_lock.lock. */
end_comment

begin_define
define|#
directive|define
name|TWA_LOCK_FREE
value|0x0
end_define

begin_comment
comment|/* lock is free */
end_comment

begin_define
define|#
directive|define
name|TWA_LOCK_HELD
value|0x1
end_define

begin_comment
comment|/* lock is held */
end_comment

begin_comment
comment|/* Error/AEN message structure. */
end_comment

begin_struct
struct|struct
name|twa_message
block|{
name|u_int32_t
name|code
decl_stmt|;
name|char
modifier|*
name|message
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|TWA_DEBUG
end_ifdef

begin_struct
struct|struct
name|twa_q_statistics
block|{
name|u_int32_t
name|q_length
decl_stmt|;
name|u_int32_t
name|q_max
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TWAQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|TWAQ_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|TWAQ_PENDING
value|2
end_define

begin_define
define|#
directive|define
name|TWAQ_COMPLETE
value|3
end_define

begin_define
define|#
directive|define
name|TWAQ_COUNT
value|4
end_define

begin_comment
comment|/* total number of queues */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TWA_DEBUG */
end_comment

begin_comment
comment|/* Driver's request packet. */
end_comment

begin_struct
struct|struct
name|twa_request
block|{
name|struct
name|twa_command_packet
modifier|*
name|tr_command
decl_stmt|;
comment|/* ptr to cmd pkt submitted to controller */
name|u_int32_t
name|tr_request_id
decl_stmt|;
comment|/* request id for tracking with firmware */
name|void
modifier|*
name|tr_data
decl_stmt|;
comment|/* ptr to data being passed to firmware */
name|u_int32_t
name|tr_length
decl_stmt|;
comment|/* length of buffer being passed to firmware */
name|void
modifier|*
name|tr_real_data
decl_stmt|;
comment|/* ptr to, and length of data passed */
name|u_int32_t
name|tr_real_length
decl_stmt|;
comment|/* to us from above, in case a buffer copy 							was done due to non-compliance to  							alignment requirements */
name|TAILQ_ENTRY
argument_list|(
argument|twa_request
argument_list|)
name|tr_link
expr_stmt|;
comment|/* to link this request in a list */
name|struct
name|twa_softc
modifier|*
name|tr_sc
decl_stmt|;
comment|/* controller that owns us */
name|u_int32_t
name|tr_status
decl_stmt|;
comment|/* command status */
name|u_int32_t
name|tr_flags
decl_stmt|;
comment|/* request flags */
name|u_int32_t
name|tr_error
decl_stmt|;
comment|/* error encountered before request submission */
name|u_int32_t
name|tr_cmd_pkt_type
decl_stmt|;
comment|/* type of request */
name|void
modifier|*
name|tr_private
decl_stmt|;
comment|/* request specific data to use during callback */
name|void
function_decl|(
modifier|*
name|tr_callback
function_decl|)
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
comment|/* callback handler */
name|bus_addr_t
name|tr_cmd_phys
decl_stmt|;
comment|/* physical address of command in controller space */
name|bus_dmamap_t
name|tr_buf_map
decl_stmt|;
comment|/* DMA map for data */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Per-controller structure. */
end_comment

begin_struct
struct|struct
name|twa_softc
block|{
comment|/* Request queues and arrays. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twa_request
argument_list|)
name|twa_free
expr_stmt|;
comment|/* free request packets */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twa_request
argument_list|)
name|twa_busy
expr_stmt|;
comment|/* requests busy in the controller */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twa_request
argument_list|)
name|twa_pending
expr_stmt|;
comment|/* internal requests pending */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twa_request
argument_list|)
name|twa_complete
expr_stmt|;
comment|/* requests completed by firmware (not by us) */
name|struct
name|twa_request
modifier|*
name|twa_lookup
index|[
name|TWA_Q_LENGTH
index|]
decl_stmt|;
comment|/* requests indexed by request_id */
name|struct
name|twa_request
modifier|*
name|twa_req_buf
decl_stmt|;
name|struct
name|twa_command_packet
modifier|*
name|twa_cmd_pkt_buf
decl_stmt|;
comment|/* AEN handler fields. */
name|struct
name|twa_event_packet
modifier|*
name|twa_aen_queue
index|[
name|TWA_Q_LENGTH
index|]
decl_stmt|;
comment|/* circular queue of AENs from firmware */
name|uint16_t
name|working_srl
decl_stmt|;
comment|/* driver& firmware negotiated srl */
name|uint16_t
name|working_branch
decl_stmt|;
comment|/* branch # of the firmware that the driver is compatible with */
name|uint16_t
name|working_build
decl_stmt|;
comment|/* build # of the firmware that the driver is compatible with */
name|u_int32_t
name|twa_operating_mode
decl_stmt|;
comment|/* base mode/current mode */
name|u_int32_t
name|twa_aen_head
decl_stmt|;
comment|/* AEN queue head */
name|u_int32_t
name|twa_aen_tail
decl_stmt|;
comment|/* AEN queue tail */
name|u_int32_t
name|twa_current_sequence_id
decl_stmt|;
comment|/* index of the last event + 1 */
name|u_int32_t
name|twa_aen_queue_overflow
decl_stmt|;
comment|/* indicates if unretrieved events were overwritten */
name|u_int32_t
name|twa_aen_queue_wrapped
decl_stmt|;
comment|/* indicates if AEN queue ever wrapped */
name|u_int32_t
name|twa_wait_timeout
decl_stmt|;
comment|/* identifier for calling tsleep */
comment|/* Controller state. */
name|u_int32_t
name|twa_state
decl_stmt|;
ifdef|#
directive|ifdef
name|TWA_DEBUG
name|struct
name|twa_q_statistics
name|twa_qstats
index|[
name|TWAQ_COUNT
index|]
decl_stmt|;
comment|/* queue statistics */
endif|#
directive|endif
comment|/* TWA_DEBUG */
struct|struct
block|{
name|u_int32_t
name|lock
decl_stmt|;
comment|/* lock state */
name|u_int32_t
name|timeout
decl_stmt|;
comment|/* time at which the lock will become available, 						even if not released */
block|}
name|twa_ioctl_lock
struct|;
comment|/* lock for use by user applications, for synchronization 					between ioctl calls */
name|device_t
name|twa_bus_dev
decl_stmt|;
comment|/* bus device */
name|struct
name|cdev
modifier|*
name|twa_ctrl_dev
decl_stmt|;
comment|/* control device */
name|struct
name|resource
modifier|*
name|twa_io_res
decl_stmt|;
comment|/* register interface window */
name|bus_space_handle_t
name|twa_bus_handle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|twa_bus_tag
decl_stmt|;
comment|/* bus space tag */
name|bus_dma_tag_t
name|twa_parent_tag
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|twa_cmd_tag
decl_stmt|;
comment|/* cmd DMA tag */
name|bus_dma_tag_t
name|twa_buf_tag
decl_stmt|;
comment|/* data buffer DMA tag */
name|bus_dmamap_t
name|twa_cmd_map
decl_stmt|;
comment|/* DMA map for the array of cmd pkts */
name|bus_addr_t
name|twa_cmd_pkt_phys
decl_stmt|;
comment|/* phys addr of first of array of cmd pkts */
name|struct
name|resource
modifier|*
name|twa_irq_res
decl_stmt|;
comment|/* interrupt resource*/
name|void
modifier|*
name|twa_intr_handle
decl_stmt|;
comment|/* interrupt handle */
name|struct
name|intr_config_hook
name|twa_ich
decl_stmt|;
comment|/* delayed-startup hook */
name|struct
name|sysctl_ctx_list
name|twa_sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|twa_sysctl_tree
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|twa_sim
decl_stmt|;
comment|/* sim for this controller */
name|struct
name|cam_path
modifier|*
name|twa_path
decl_stmt|;
comment|/* peripheral, path, tgt, lun 						associated with this controller */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Queue primitives  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TWA_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TWAQ_INIT
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {						\ 		sc->twa_qstats[qname].q_length = 0;	\ 		sc->twa_qstats[qname].q_max = 0;	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|TWAQ_ADD
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {							\ 	struct twa_q_statistics *qs =&(sc)->twa_qstats[qname];	\ 								\ 		qs->q_length++;					\ 		if (qs->q_length> qs->q_max)			\ 			qs->q_max = qs->q_length;		\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|TWAQ_REMOVE
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
value|(sc)->twa_qstats[qname].q_length--
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TWA_DEBUG */
end_comment

begin_define
define|#
directive|define
name|TWAQ_INIT
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TWAQ_ADD
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TWAQ_REMOVE
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TWA_DEBUG */
end_comment

begin_define
define|#
directive|define
name|TWAQ_REQUEST_QUEUE
parameter_list|(
name|name
parameter_list|,
name|index
parameter_list|)
define|\
value|static __inline void twa_initq_ ## name(struct twa_softc *sc)		\ {									\ 	TAILQ_INIT(&sc->twa_ ## name);					\ 	TWAQ_INIT(sc, index);						\ }									\ static __inline void twa_enqueue_ ## name(struct twa_request *tr)	\ {									\ 	int	s;							\ 									\ 	s = splcam();							\ 	TAILQ_INSERT_TAIL(&tr->tr_sc->twa_ ## name, tr, tr_link);	\ 	TWAQ_ADD(tr->tr_sc, index);					\ 	splx(s);							\ }									\ static __inline void twa_requeue_ ## name(struct twa_request *tr)	\ {									\ 	int	s;							\ 									\ 	s = splcam();							\ 	TAILQ_INSERT_HEAD(&tr->tr_sc->twa_ ## name, tr, tr_link);	\ 	TWAQ_ADD(tr->tr_sc, index);					\ 	splx(s);							\ }									\ static __inline struct twa_request *twa_dequeue_ ## name(struct twa_softc *sc)\ {									\ 	struct twa_request	*tr;					\ 	int			s;					\ 									\ 	s = splcam();							\ 	if ((tr = TAILQ_FIRST(&sc->twa_ ## name)) != NULL) {		\ 		TAILQ_REMOVE(&sc->twa_ ## name, tr, tr_link);		\ 		TWAQ_REMOVE(sc, index);					\ 	}								\ 	splx(s);							\ 	return(tr);							\ }									\ static __inline void twa_remove_ ## name(struct twa_request *tr)	\ {									\ 	int	s;							\ 									\ 	s = splcam();							\ 	TAILQ_REMOVE(&tr->tr_sc->twa_ ## name, tr, tr_link);		\ 	TWAQ_REMOVE(tr->tr_sc, index);					\ 	splx(s);							\ }
end_define

begin_macro
name|TWAQ_REQUEST_QUEUE
argument_list|(
argument|free
argument_list|,
argument|TWAQ_FREE
argument_list|)
end_macro

begin_macro
name|TWAQ_REQUEST_QUEUE
argument_list|(
argument|busy
argument_list|,
argument|TWAQ_BUSY
argument_list|)
end_macro

begin_macro
name|TWAQ_REQUEST_QUEUE
argument_list|(
argument|pending
argument_list|,
argument|TWAQ_PENDING
argument_list|)
end_macro

begin_macro
name|TWAQ_REQUEST_QUEUE
argument_list|(
argument|complete
argument_list|,
argument|TWAQ_COMPLETE
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|TWA_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int8_t
name|twa_dbg_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int8_t
name|twa_call_dbg_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Printf with the bus device in question. */
end_comment

begin_define
define|#
directive|define
name|twa_dbg_dprint
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
value|do {							\ 		if (dbg_level<= twa_dbg_level)			\ 			device_printf(sc->twa_bus_dev,		\ 				"%s: " fmt "\n", __func__ , ##args);\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|twa_dbg_dprint_enter
parameter_list|(
name|dbg_level
parameter_list|,
name|sc
parameter_list|)
define|\
value|do {							\ 		if (dbg_level<= twa_call_dbg_level)		\ 			device_printf(sc->twa_bus_dev,		\ 				"%s: entered.\n", __func__);	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|twa_dbg_dprint_exit
parameter_list|(
name|dbg_level
parameter_list|,
name|sc
parameter_list|)
define|\
value|do {							\ 		if (dbg_level<= twa_call_dbg_level)		\ 			device_printf(sc->twa_bus_dev,		\ 				"%s: exiting.\n", __func__);	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|twa_dbg_print
parameter_list|(
name|dbg_level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {							\ 		if (dbg_level<= twa_dbg_level)			\ 			printf("%s: " fmt "\n", __func__ , ##args);\ 	} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|twa_dbg_dprint
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
name|twa_dbg_dprint_enter
parameter_list|(
name|dbg_level
parameter_list|,
name|sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|twa_dbg_dprint_exit
parameter_list|(
name|dbg_level
parameter_list|,
name|sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|twa_dbg_print
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
value|device_printf(sc->twa_bus_dev, fmt, ##args)
end_define

end_unit

