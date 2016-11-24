begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_CHANVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_CHANVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv_busdma.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/vmbus.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/vmbus/vmbus_brvar.h>
end_include

begin_struct
struct|struct
name|vmbus_channel
block|{
comment|/* 	 * NOTE: 	 * Fields before ch_txbr are only accessed on this channel's 	 * target CPU. 	 */
name|uint32_t
name|ch_flags
decl_stmt|;
comment|/* VMBUS_CHAN_FLAG_ */
comment|/* 	 * RX bufring; immediately following ch_txbr. 	 */
name|struct
name|vmbus_rxbr
name|ch_rxbr
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|ch_tq
decl_stmt|;
name|struct
name|task
name|ch_task
decl_stmt|;
name|vmbus_chan_callback_t
name|ch_cb
decl_stmt|;
name|void
modifier|*
name|ch_cbarg
decl_stmt|;
comment|/* 	 * TX bufring; at the beginning of ch_bufring. 	 * 	 * NOTE: 	 * Put TX bufring and the following MNF/evtflag to a new 	 * cacheline, since they will be accessed on all CPUs by 	 * locking ch_txbr first. 	 * 	 * XXX 	 * TX bufring and following MNF/evtflags do _not_ fit in 	 * one 64B cacheline. 	 */
name|struct
name|vmbus_txbr
name|ch_txbr
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
name|uint32_t
name|ch_txflags
decl_stmt|;
comment|/* VMBUS_CHAN_TXF_ */
comment|/* 	 * These are based on the vmbus_chanmsg_choffer.chm_montrig. 	 * Save it here for easy access. 	 */
name|uint32_t
name|ch_montrig_mask
decl_stmt|;
comment|/* MNF trig mask */
specifier|volatile
name|uint32_t
modifier|*
name|ch_montrig
decl_stmt|;
comment|/* MNF trigger loc. */
comment|/* 	 * These are based on the vmbus_chanmsg_choffer.chm_chanid. 	 * Save it here for easy access. 	 */
name|u_long
name|ch_evtflag_mask
decl_stmt|;
comment|/* event flag */
specifier|volatile
name|u_long
modifier|*
name|ch_evtflag
decl_stmt|;
comment|/* event flag loc. */
comment|/* 	 * Rarely used fields. 	 */
name|struct
name|hyperv_mon_param
modifier|*
name|ch_monprm
decl_stmt|;
name|struct
name|hyperv_dma
name|ch_monprm_dma
decl_stmt|;
name|uint32_t
name|ch_id
decl_stmt|;
comment|/* channel id */
name|device_t
name|ch_dev
decl_stmt|;
name|struct
name|vmbus_softc
modifier|*
name|ch_vmbus
decl_stmt|;
name|int
name|ch_cpuid
decl_stmt|;
comment|/* owner cpu */
comment|/* 	 * Virtual cpuid for ch_cpuid; it is used to communicate cpuid 	 * related information w/ Hyper-V.  If MSR_HV_VP_INDEX does not 	 * exist, ch_vcpuid will always be 0 for compatibility. 	 */
name|uint32_t
name|ch_vcpuid
decl_stmt|;
comment|/* 	 * If this is a primary channel, ch_subchan* fields 	 * contain sub-channels belonging to this primary 	 * channel. 	 */
name|struct
name|mtx
name|ch_subchan_lock
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vmbus_channel
argument_list|)
name|ch_subchans
expr_stmt|;
name|int
name|ch_subchan_cnt
decl_stmt|;
comment|/* If this is a sub-channel */
name|TAILQ_ENTRY
argument_list|(
argument|vmbus_channel
argument_list|)
name|ch_sublink
expr_stmt|;
comment|/* sub-channel link */
name|struct
name|vmbus_channel
modifier|*
name|ch_prichan
decl_stmt|;
comment|/* owner primary chan */
name|void
modifier|*
name|ch_bufring
decl_stmt|;
comment|/* TX+RX bufrings */
name|struct
name|hyperv_dma
name|ch_bufring_dma
decl_stmt|;
name|uint32_t
name|ch_bufring_gpadl
decl_stmt|;
name|struct
name|task
name|ch_attach_task
decl_stmt|;
comment|/* run in ch_mgmt_tq */
name|struct
name|task
name|ch_detach_task
decl_stmt|;
comment|/* run in ch_mgmt_tq */
name|struct
name|taskqueue
modifier|*
name|ch_mgmt_tq
decl_stmt|;
comment|/* If this is a primary channel */
name|TAILQ_ENTRY
argument_list|(
argument|vmbus_channel
argument_list|)
name|ch_prilink
expr_stmt|;
comment|/* primary chan link */
name|TAILQ_ENTRY
argument_list|(
argument|vmbus_channel
argument_list|)
name|ch_link
expr_stmt|;
comment|/* channel link */
name|uint32_t
name|ch_subidx
decl_stmt|;
comment|/* subchan index */
specifier|volatile
name|uint32_t
name|ch_stflags
decl_stmt|;
comment|/* atomic-op */
comment|/* VMBUS_CHAN_ST_ */
name|struct
name|hyperv_guid
name|ch_guid_type
decl_stmt|;
name|struct
name|hyperv_guid
name|ch_guid_inst
decl_stmt|;
name|struct
name|sx
name|ch_orphan_lock
decl_stmt|;
name|struct
name|vmbus_xact_ctx
modifier|*
name|ch_orphan_xact
decl_stmt|;
name|int
name|ch_refs
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|ch_sysctl_ctx
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_CHAN_ISPRIMARY
parameter_list|(
name|chan
parameter_list|)
value|((chan)->ch_subidx == 0)
end_define

begin_comment
comment|/*  * If this flag is set, this channel's interrupt will be masked in ISR,  * and the RX bufring will be drained before this channel's interrupt is  * unmasked.  *  * This flag is turned on by default.  Drivers can turn it off according  * to their own requirement.  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHAN_FLAG_BATCHREAD
value|0x0002
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_TXF_HASMNF
value|0x0001
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_OPENED_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_ONPRIL_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_ONSUBL_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_ONLIST_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_REVOKED_SHIFT
value|4
end_define

begin_comment
comment|/* sticky */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_OPENED
value|(1<< VMBUS_CHAN_ST_OPENED_SHIFT)
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_ONPRIL
value|(1<< VMBUS_CHAN_ST_ONPRIL_SHIFT)
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_ONSUBL
value|(1<< VMBUS_CHAN_ST_ONSUBL_SHIFT)
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_ONLIST
value|(1<< VMBUS_CHAN_ST_ONLIST_SHIFT)
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_REVOKED
value|(1<< VMBUS_CHAN_ST_REVOKED_SHIFT)
end_define

begin_struct_decl
struct_decl|struct
name|vmbus_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_message
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|vmbus_event_proc
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_event_proc_compat
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_msgproc
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
specifier|const
name|struct
name|vmbus_message
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_destroy_all
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_CHANVAR_H_ */
end_comment

end_unit

