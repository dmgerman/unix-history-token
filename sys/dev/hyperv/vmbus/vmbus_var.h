begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv_busdma.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcib_private.h>
end_include

begin_comment
comment|/*  * NOTE: DO NOT CHANGE THIS.  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_SINT_MESSAGE
value|2
end_define

begin_comment
comment|/*  * NOTE:  * - DO NOT set it to the same value as VMBUS_SINT_MESSAGE.  * - DO NOT set it to 0.  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_SINT_TIMER
value|4
end_define

begin_comment
comment|/*  * NOTE: DO NOT CHANGE THESE  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CONNID_MESSAGE
value|1
end_define

begin_define
define|#
directive|define
name|VMBUS_CONNID_EVENT
value|2
end_define

begin_struct_decl
struct_decl|struct
name|vmbus_message
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vmbus_chanmsg_proc_t
function_decl|)
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
end_typedef

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_PROC
parameter_list|(
name|name
parameter_list|,
name|func
parameter_list|)
define|\
value|[VMBUS_CHANMSG_TYPE_##name] = func
end_define

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_PROC_WAKEUP
parameter_list|(
name|name
parameter_list|)
define|\
value|VMBUS_CHANMSG_PROC(name, vmbus_msghc_wakeup)
end_define

begin_struct
struct|struct
name|vmbus_pcpu_data
block|{
name|u_long
modifier|*
name|intr_cnt
decl_stmt|;
comment|/* Hyper-V interrupt counter */
name|struct
name|vmbus_message
modifier|*
name|message
decl_stmt|;
comment|/* shared messages */
name|uint32_t
name|vcpuid
decl_stmt|;
comment|/* virtual cpuid */
name|int
name|event_flags_cnt
decl_stmt|;
comment|/* # of event flags */
name|struct
name|vmbus_evtflags
modifier|*
name|event_flags
decl_stmt|;
comment|/* event flags from host */
comment|/* Rarely used fields */
name|struct
name|hyperv_dma
name|message_dma
decl_stmt|;
comment|/* busdma glue */
name|struct
name|hyperv_dma
name|event_flags_dma
decl_stmt|;
comment|/* busdma glue */
name|struct
name|taskqueue
modifier|*
name|event_tq
decl_stmt|;
comment|/* event taskq */
name|struct
name|taskqueue
modifier|*
name|message_tq
decl_stmt|;
comment|/* message taskq */
name|struct
name|task
name|message_task
decl_stmt|;
comment|/* message task */
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|1100000
end_if

begin_typedef
typedef|typedef
name|u_long
name|rman_res_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vmbus_softc
block|{
name|void
function_decl|(
modifier|*
name|vmbus_event_proc
function_decl|)
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|u_long
modifier|*
name|vmbus_tx_evtflags
decl_stmt|;
comment|/* event flags to host */
name|struct
name|vmbus_mnf
modifier|*
name|vmbus_mnf2
decl_stmt|;
comment|/* monitored by host */
name|u_long
modifier|*
name|vmbus_rx_evtflags
decl_stmt|;
comment|/* compat evtflgs from host */
name|struct
name|vmbus_channel
modifier|*
modifier|*
name|vmbus_chmap
decl_stmt|;
name|struct
name|vmbus_xact_ctx
modifier|*
name|vmbus_xc
decl_stmt|;
name|struct
name|vmbus_pcpu_data
name|vmbus_pcpu
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* 	 * Rarely used fields 	 */
name|device_t
name|vmbus_dev
decl_stmt|;
name|int
name|vmbus_idtvec
decl_stmt|;
name|uint32_t
name|vmbus_flags
decl_stmt|;
comment|/* see VMBUS_FLAG_ */
name|uint32_t
name|vmbus_version
decl_stmt|;
name|uint32_t
name|vmbus_gpadl
decl_stmt|;
comment|/* Shared memory for vmbus_{rx,tx}_evtflags */
name|void
modifier|*
name|vmbus_evtflags
decl_stmt|;
name|struct
name|hyperv_dma
name|vmbus_evtflags_dma
decl_stmt|;
name|void
modifier|*
name|vmbus_mnf1
decl_stmt|;
comment|/* monitored by VM, unused */
name|struct
name|hyperv_dma
name|vmbus_mnf1_dma
decl_stmt|;
name|struct
name|hyperv_dma
name|vmbus_mnf2_dma
decl_stmt|;
name|bool
name|vmbus_scandone
decl_stmt|;
name|struct
name|task
name|vmbus_scandone_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|vmbus_devtq
decl_stmt|;
comment|/* for dev attach/detach */
name|struct
name|taskqueue
modifier|*
name|vmbus_subchtq
decl_stmt|;
comment|/* for sub-chan attach/detach */
comment|/* Primary channels */
name|struct
name|mtx
name|vmbus_prichan_lock
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vmbus_channel
argument_list|)
name|vmbus_prichans
expr_stmt|;
comment|/* Complete channel list */
name|struct
name|mtx
name|vmbus_chan_lock
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|vmbus_channel
argument_list|)
name|vmbus_chans
expr_stmt|;
ifdef|#
directive|ifdef
name|NEW_PCIB
comment|/* The list of usable MMIO ranges for PCIe pass-through */
name|struct
name|pcib_host_resources
name|vmbus_mmio_res
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_FLAG_ATTACHED
value|0x0001
end_define

begin_comment
comment|/* vmbus was attached */
end_comment

begin_define
define|#
directive|define
name|VMBUS_FLAG_SYNIC
value|0x0002
end_define

begin_comment
comment|/* SynIC was setup */
end_comment

begin_define
define|#
directive|define
name|VMBUS_PCPU_GET
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|cpu
parameter_list|)
value|(sc)->vmbus_pcpu[(cpu)].field
end_define

begin_define
define|#
directive|define
name|VMBUS_PCPU_PTR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|cpu
parameter_list|)
value|&(sc)->vmbus_pcpu[(cpu)].field
end_define

begin_struct_decl
struct_decl|struct
name|vmbus_channel
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_message
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_msghc
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|vmbus_handle_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_add_child
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_delete_child
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_et_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|vmbus_gpadl_alloc
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vmbus_msghc
modifier|*
name|vmbus_msghc_get
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_msghc_put
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|struct
name|vmbus_msghc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vmbus_msghc_dataptr
parameter_list|(
name|struct
name|vmbus_msghc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_msghc_exec_noresult
parameter_list|(
name|struct
name|vmbus_msghc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_msghc_exec
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|struct
name|vmbus_msghc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_msghc_exec_cancel
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|struct
name|vmbus_msghc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|vmbus_message
modifier|*
name|vmbus_msghc_wait_result
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|struct
name|vmbus_msghc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|vmbus_message
modifier|*
name|vmbus_msghc_poll_result
parameter_list|(
name|struct
name|vmbus_softc
modifier|*
parameter_list|,
name|struct
name|vmbus_msghc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_msghc_wakeup
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
name|vmbus_msghc_reset
parameter_list|(
name|struct
name|vmbus_msghc
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_VAR_H_ */
end_comment

end_unit

