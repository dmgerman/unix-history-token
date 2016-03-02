begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QMAN_H
end_ifndef

begin_define
define|#
directive|define
name|_QMAN_H
end_define

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<contrib/ncsw/inc/Peripherals/qm_ext.h>
end_include

begin_comment
comment|/**  * @group QMan private defines/declarations  * @{  */
end_comment

begin_comment
comment|/**  * Maximum number of frame queues in all QMans.  */
end_comment

begin_define
define|#
directive|define
name|QMAN_MAX_FQIDS
value|16
end_define

begin_comment
comment|/**  * Pool channel common to all software portals.  * @note Value of 0 reflects the e_QM_FQ_CHANNEL_POOL1 from e_QmFQChannel  *       type used in qman_fqr_create().  */
end_comment

begin_define
define|#
directive|define
name|QMAN_COMMON_POOL_CHANNEL
value|0
end_define

begin_define
define|#
directive|define
name|QMAN_FQID_BASE
value|1
end_define

begin_define
define|#
directive|define
name|QMAN_CCSR_SIZE
value|0x1000
end_define

begin_comment
comment|/*  * Portal defines  */
end_comment

begin_define
define|#
directive|define
name|QMAN_CE_PA
parameter_list|(
name|base
parameter_list|)
value|(base)
end_define

begin_define
define|#
directive|define
name|QMAN_CI_PA
parameter_list|(
name|base
parameter_list|)
value|((base) + 0x100000)
end_define

begin_define
define|#
directive|define
name|QMAN_PORTAL_CE_PA
parameter_list|(
name|base
parameter_list|,
name|n
parameter_list|)
define|\
value|(QMAN_CE_PA(base) + ((n) * QMAN_PORTAL_CE_SIZE))
end_define

begin_define
define|#
directive|define
name|QMAN_PORTAL_CI_PA
parameter_list|(
name|base
parameter_list|,
name|n
parameter_list|)
define|\
value|(QMAN_CI_PA(base) + ((n) * QMAN_PORTAL_CI_SIZE))
end_define

begin_struct
struct|struct
name|qman_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device handle */
name|int
name|sc_rrid
decl_stmt|;
comment|/* register rid */
name|struct
name|resource
modifier|*
name|sc_rres
decl_stmt|;
comment|/* register resource */
name|int
name|sc_irid
decl_stmt|;
comment|/* interrupt rid */
name|struct
name|resource
modifier|*
name|sc_ires
decl_stmt|;
comment|/* interrupt resource */
name|bool
name|sc_regs_mapped
index|[
name|MAXCPU
index|]
decl_stmt|;
name|t_Handle
name|sc_qh
decl_stmt|;
comment|/* QMAN handle */
name|t_Handle
name|sc_qph
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* QMAN portal handles */
name|vm_paddr_t
name|sc_qp_pa
decl_stmt|;
comment|/* QMAN portal PA */
name|int
name|sc_fqr_cpu
index|[
name|QMAN_MAX_FQIDS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** @> */
end_comment

begin_comment
comment|/**  * @group QMan bus interface  * @{  */
end_comment

begin_function_decl
name|int
name|qman_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qman_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qman_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qman_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qman_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @> */
end_comment

begin_comment
comment|/**  * @group QMan API  * @{  */
end_comment

begin_comment
comment|/**  * Create Frame Queue Range.  *  * @param fqids_num			Number of frame queues in the range.  *  * @param channel			Dedicated channel serviced by this  * 					Frame Queue Range.  *  * @param wq				Work Queue Number within the channel.  *  * @param force_fqid			If TRUE, fore allocation of specific  * 					FQID. Notice that there can not be two  * 					frame queues with the same ID in the  * 					system.  *  * @param fqid_or_align			FQID if @force_fqid == TRUE, alignment  * 					of FQIDs entries otherwise.  *  * @param init_parked			If TRUE, FQ state is initialized to  * 					"parked" state on creation. Otherwise,  * 					to "scheduled" state.  *  * @param hold_active			If TRUE, the FQ may be held in the  * 					portal in "held active" state in  * 					anticipation of more frames being  * 					dequeued from it after the head frame  * 					is removed from the FQ and the dequeue  * 					response is returned. If FALSE the  * 					"held_active" state of the FQ is not  * 					allowed. This affects only on queues  * 					destined to software portals. Refer to  * 					the 6.3.4.6 of DPAA Reference Manual.  *  * @param prefer_in_cache		If TRUE, prefer this FQR to be in QMan  * 					internal cache memory for all states.  *  * @param congst_avoid_ena		If TRUE, enable congestion avoidance  * 					mechanism.  *  * @param congst_group			A handle to the congestion group. Only  * 					relevant when @congst_avoid_ena == TRUE.  *  * @param overhead_accounting_len	For each frame add this number for CG  * 					calculation (may be negative), if 0 -  * 					disable feature.  *  * @param tail_drop_threshold		If not 0 - enable tail drop on this  * 					FQR.  *  * @return				A handle to newly created FQR object.  */
end_comment

begin_function_decl
name|t_Handle
name|qman_fqr_create
parameter_list|(
name|uint32_t
name|fqids_num
parameter_list|,
name|e_QmFQChannel
name|channel
parameter_list|,
name|uint8_t
name|wq
parameter_list|,
name|bool
name|force_fqid
parameter_list|,
name|uint32_t
name|fqid_or_align
parameter_list|,
name|bool
name|init_parked
parameter_list|,
name|bool
name|hold_active
parameter_list|,
name|bool
name|prefer_in_cache
parameter_list|,
name|bool
name|congst_avoid_ena
parameter_list|,
name|t_Handle
name|congst_group
parameter_list|,
name|int8_t
name|overhead_accounting_len
parameter_list|,
name|uint32_t
name|tail_drop_threshold
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free Frame Queue Range.  *  * @param fqr	A handle to FQR to be freed.  * @return	E_OK on success; error code otherwise.  */
end_comment

begin_function_decl
name|t_Error
name|qman_fqr_free
parameter_list|(
name|t_Handle
name|fqr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Register the callback function.  * The callback function will be called when a frame comes from this FQR.  *  * @param fqr		A handle to FQR.  * @param callback	A pointer to the callback function.  * @param app		A pointer to the user's data.  * @return		E_OK on success; error code otherwise.  */
end_comment

begin_function_decl
name|t_Error
name|qman_fqr_register_cb
parameter_list|(
name|t_Handle
name|fqr
parameter_list|,
name|t_QmReceivedFrameCallback
modifier|*
name|callback
parameter_list|,
name|t_Handle
name|app
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Enqueue a frame on a given FQR.  *  * @param fqr		A handle to FQR.  * @param fqid_off	FQID offset wihin the FQR.  * @param frame		A frame to be enqueued to the transmission.  * @return		E_OK on success; error code otherwise.  */
end_comment

begin_function_decl
name|t_Error
name|qman_fqr_enqueue
parameter_list|(
name|t_Handle
name|fqr
parameter_list|,
name|uint32_t
name|fqid_off
parameter_list|,
name|t_DpaaFD
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get one of the FQR counter's value.  *  * @param fqr		A handle to FQR.  * @param fqid_off	FQID offset within the FQR.  * @param counter	The requested counter.  * @return		Counter's current value.  */
end_comment

begin_function_decl
name|uint32_t
name|qman_fqr_get_counter
parameter_list|(
name|t_Handle
name|fqr
parameter_list|,
name|uint32_t
name|fqid_off
parameter_list|,
name|e_QmFqrCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Pull frame from FQR.  *  * @param fqr		A handle to FQR.  * @param fqid_off	FQID offset within the FQR.  * @param frame		The received frame.  * @return		E_OK on success; error code otherwise.  */
end_comment

begin_function_decl
name|t_Error
name|qman_fqr_pull_frame
parameter_list|(
name|t_Handle
name|fqr
parameter_list|,
name|uint32_t
name|fqid_off
parameter_list|,
name|t_DpaaFD
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get base FQID of the FQR.  * @param fqr	A handle to FQR.  * @return	Base FQID of the FQR.  */
end_comment

begin_function_decl
name|uint32_t
name|qman_fqr_get_base_fqid
parameter_list|(
name|t_Handle
name|fqr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Poll frames from QMan.  * This polls frames from the current software portal.  *  * @param source	Type of frames to be polled.  * @return		E_OK on success; error otherwise.  */
end_comment

begin_function_decl
name|t_Error
name|qman_poll
parameter_list|(
name|e_QmPortalPollSource
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * General received frame callback.  * This is called, when user did not register his own callback for a given  * frame queue range (fqr).  */
end_comment

begin_function_decl
name|e_RxStoreResponse
name|qman_received_frame_callback
parameter_list|(
name|t_Handle
name|app
parameter_list|,
name|t_Handle
name|qm_fqr
parameter_list|,
name|t_Handle
name|qm_portal
parameter_list|,
name|uint32_t
name|fqid_offset
parameter_list|,
name|t_DpaaFD
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * General rejected frame callback.  * This is called, when user did not register his own callback for a given  * frame queue range (fqr).  */
end_comment

begin_function_decl
name|e_RxStoreResponse
name|qman_rejected_frame_callback
parameter_list|(
name|t_Handle
name|app
parameter_list|,
name|t_Handle
name|qm_fqr
parameter_list|,
name|t_Handle
name|qm_portal
parameter_list|,
name|uint32_t
name|fqid_offset
parameter_list|,
name|t_DpaaFD
modifier|*
name|frame
parameter_list|,
name|t_QmRejectedFrameInfo
modifier|*
name|qm_rejected_frame_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QMAN_H */
end_comment

end_unit

