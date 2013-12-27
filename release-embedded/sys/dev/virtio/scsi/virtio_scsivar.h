begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, Bryan Venteicher<bryanv@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_SCSIVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_SCSIVAR_H
end_define

begin_struct_decl
struct_decl|struct
name|vtscsi_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vtscsi_request
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|vtscsi_request_cb_t
parameter_list|(
name|struct
name|vtscsi_softc
modifier|*
parameter_list|,
name|struct
name|vtscsi_request
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|vtscsi_statistics
block|{
name|unsigned
name|long
name|scsi_cmd_timeouts
decl_stmt|;
name|unsigned
name|long
name|dequeue_no_requests
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vtscsi_softc
block|{
name|device_t
name|vtscsi_dev
decl_stmt|;
name|struct
name|mtx
name|vtscsi_mtx
decl_stmt|;
name|uint64_t
name|vtscsi_features
decl_stmt|;
name|uint16_t
name|vtscsi_flags
decl_stmt|;
define|#
directive|define
name|VTSCSI_FLAG_INDIRECT
value|0x0001
define|#
directive|define
name|VTSCSI_FLAG_BIDIRECTIONAL
value|0x0002
define|#
directive|define
name|VTSCSI_FLAG_HOTPLUG
value|0x0004
define|#
directive|define
name|VTSCSI_FLAG_RESET
value|0x0008
define|#
directive|define
name|VTSCSI_FLAG_DETACH
value|0x0010
name|uint16_t
name|vtscsi_frozen
decl_stmt|;
define|#
directive|define
name|VTSCSI_FROZEN_NO_REQUESTS
value|0x01
define|#
directive|define
name|VTSCSI_FROZEN_REQUEST_VQ_FULL
value|0x02
name|struct
name|sglist
modifier|*
name|vtscsi_sglist
decl_stmt|;
name|struct
name|virtqueue
modifier|*
name|vtscsi_control_vq
decl_stmt|;
name|struct
name|virtqueue
modifier|*
name|vtscsi_event_vq
decl_stmt|;
name|struct
name|virtqueue
modifier|*
name|vtscsi_request_vq
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|vtscsi_sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|vtscsi_path
decl_stmt|;
name|int
name|vtscsi_debug
decl_stmt|;
name|int
name|vtscsi_nrequests
decl_stmt|;
name|int
name|vtscsi_max_nsegs
decl_stmt|;
name|int
name|vtscsi_event_buf_size
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vtscsi_request
argument_list|)
name|vtscsi_req_free
expr_stmt|;
name|uint16_t
name|vtscsi_max_channel
decl_stmt|;
name|uint16_t
name|vtscsi_max_target
decl_stmt|;
name|uint32_t
name|vtscsi_max_lun
decl_stmt|;
define|#
directive|define
name|VTSCSI_NUM_EVENT_BUFS
value|4
name|struct
name|virtio_scsi_event
name|vtscsi_event_bufs
index|[
name|VTSCSI_NUM_EVENT_BUFS
index|]
decl_stmt|;
name|struct
name|vtscsi_statistics
name|vtscsi_stats
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|vtscsi_request_state
block|{
name|VTSCSI_REQ_STATE_FREE
block|,
name|VTSCSI_REQ_STATE_INUSE
block|,
name|VTSCSI_REQ_STATE_ABORTED
block|,
name|VTSCSI_REQ_STATE_TIMEDOUT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|vtscsi_request
block|{
name|struct
name|vtscsi_softc
modifier|*
name|vsr_softc
decl_stmt|;
name|union
name|ccb
modifier|*
name|vsr_ccb
decl_stmt|;
name|vtscsi_request_cb_t
modifier|*
name|vsr_complete
decl_stmt|;
name|void
modifier|*
name|vsr_ptr0
decl_stmt|;
comment|/* Request when aborting a timedout command. */
define|#
directive|define
name|vsr_timedout_req
value|vsr_ptr0
name|enum
name|vtscsi_request_state
name|vsr_state
decl_stmt|;
name|uint16_t
name|vsr_flags
decl_stmt|;
define|#
directive|define
name|VTSCSI_REQ_FLAG_POLLED
value|0x01
define|#
directive|define
name|VTSCSI_REQ_FLAG_COMPLETE
value|0x02
define|#
directive|define
name|VTSCSI_REQ_FLAG_TIMEOUT_SET
value|0x04
union|union
block|{
name|struct
name|virtio_scsi_cmd_req
name|cmd
decl_stmt|;
name|struct
name|virtio_scsi_ctrl_tmf_req
name|tmf
decl_stmt|;
name|struct
name|virtio_scsi_ctrl_an_req
name|an
decl_stmt|;
block|}
name|vsr_ureq
union|;
define|#
directive|define
name|vsr_cmd_req
value|vsr_ureq.cmd
define|#
directive|define
name|vsr_tmf_req
value|vsr_ureq.tmf
define|#
directive|define
name|vsr_an_req
value|vsr_ureq.an
comment|/* Make request and response non-contiguous. */
name|uint32_t
name|vsr_pad
decl_stmt|;
union|union
block|{
name|struct
name|virtio_scsi_cmd_resp
name|cmd
decl_stmt|;
name|struct
name|virtio_scsi_ctrl_tmf_resp
name|tmf
decl_stmt|;
name|struct
name|virtio_scsi_ctrl_an_resp
name|an
decl_stmt|;
block|}
name|vsr_uresp
union|;
define|#
directive|define
name|vsr_cmd_resp
value|vsr_uresp.cmd
define|#
directive|define
name|vsr_tmf_resp
value|vsr_uresp.tmf
define|#
directive|define
name|vsr_an_resp
value|vsr_uresp.an
name|struct
name|callout
name|vsr_callout
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|vtscsi_request
argument_list|)
name|vsr_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Private field in the CCB header that points to our request. */
end_comment

begin_define
define|#
directive|define
name|ccbh_vtscsi_req
value|spriv_ptr0
end_define

begin_comment
comment|/* Features desired/implemented by this driver. */
end_comment

begin_define
define|#
directive|define
name|VTSCSI_FEATURES
define|\
value|(VIRTIO_SCSI_F_HOTPLUG		| \      VIRTIO_RING_F_INDIRECT_DESC)
end_define

begin_define
define|#
directive|define
name|VTSCSI_MTX
parameter_list|(
name|_sc
parameter_list|)
value|&(_sc)->vtscsi_mtx
end_define

begin_define
define|#
directive|define
name|VTSCSI_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
value|mtx_init(VTSCSI_MTX(_sc), _name, \ 					    "VTSCSI Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|VTSCSI_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(VTSCSI_MTX(_sc))
end_define

begin_define
define|#
directive|define
name|VTSCSI_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(VTSCSI_MTX(_sc))
end_define

begin_define
define|#
directive|define
name|VTSCSI_LOCK_OWNED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(VTSCSI_MTX(_sc), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|VTSCSI_LOCK_NOTOWNED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(VTSCSI_MTX(_sc), MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|VTSCSI_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(VTSCSI_MTX(_sc))
end_define

begin_comment
comment|/*  * Reasons for either freezing or thawing the SIMQ.  *  * VirtIO SCSI is a bit unique in the sense that SCSI and TMF  * commands go over different queues. Both queues are fed by  * the same SIMQ, but we only freeze the SIMQ when the request  * (SCSI) virtqueue is full, not caring if the control (TMF)  * virtqueue unlikely gets full. However, both queues share the  * same pool of requests, so the completion of a TMF command  * could cause the SIMQ to be unfrozen.  */
end_comment

begin_define
define|#
directive|define
name|VTSCSI_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|VTSCSI_REQUEST_VQ
value|0x02
end_define

begin_comment
comment|/* Debug trace levels. */
end_comment

begin_define
define|#
directive|define
name|VTSCSI_INFO
value|0x01
end_define

begin_define
define|#
directive|define
name|VTSCSI_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|VTSCSI_TRACE
value|0x04
end_define

begin_define
define|#
directive|define
name|vtscsi_dprintf
parameter_list|(
name|_sc
parameter_list|,
name|_level
parameter_list|,
name|_msg
parameter_list|,
name|_args
modifier|...
parameter_list|)
value|do { 		\ 	if ((_sc)->vtscsi_debug& (_level))				\ 		device_printf((_sc)->vtscsi_dev, "%s: "_msg,		\ 		    __FUNCTION__, ##_args);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|vtscsi_dprintf_req
parameter_list|(
name|_req
parameter_list|,
name|_level
parameter_list|,
name|_msg
parameter_list|,
name|_args
modifier|...
parameter_list|)
value|do {		\ 	struct vtscsi_softc *__sc = (_req)->vsr_softc;			\ 	if ((__sc)->vtscsi_debug& (_level))				\ 		vtscsi_printf_req(_req, __FUNCTION__, _msg, ##_args);	\ } while (0)
end_define

begin_comment
comment|/*  * Set the status field in a CCB, optionally clearing non CCB_STATUS_* flags.  */
end_comment

begin_define
define|#
directive|define
name|vtscsi_set_ccb_status
parameter_list|(
name|_ccbh
parameter_list|,
name|_status
parameter_list|,
name|_mask
parameter_list|)
value|do {		\ 	KASSERT(((_mask)& CAM_STATUS_MASK) == 0,			\ 	    ("%s:%d bad mask: 0x%x", __FUNCTION__, __LINE__, (_mask)));	\ 	(_ccbh)->status&= ~(CAM_STATUS_MASK | (_mask));		\ 	(_ccbh)->status |= (_status);					\ } while (0)
end_define

begin_comment
comment|/*  * One segment each for the request and the response.  */
end_comment

begin_define
define|#
directive|define
name|VTSCSI_MIN_SEGMENTS
value|2
end_define

begin_comment
comment|/*  * Allocate additional requests for internal use such  * as TM commands (e.g. aborting timedout commands).  */
end_comment

begin_define
define|#
directive|define
name|VTSCSI_RESERVED_REQUESTS
value|10
end_define

begin_comment
comment|/*  * Specification doesn't say, use traditional SCSI default.  */
end_comment

begin_define
define|#
directive|define
name|VTSCSI_INITIATOR_ID
value|7
end_define

begin_comment
comment|/*  * How to wait (or not) for request completion.  */
end_comment

begin_define
define|#
directive|define
name|VTSCSI_EXECUTE_ASYNC
value|0
end_define

begin_define
define|#
directive|define
name|VTSCSI_EXECUTE_POLL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_SCSIVAR_H */
end_comment

end_unit

