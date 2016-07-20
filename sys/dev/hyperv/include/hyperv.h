begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * HyperV definitions for messages that are sent between instances of the  * Channel Management Library in separate partitions, or in some cases,  * back to itself.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HYPERV_H__
end_ifndef

begin_define
define|#
directive|define
name|__HYPERV_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<amd64/include/xen/synch_bitops.h>
end_include

begin_include
include|#
directive|include
file|<amd64/include/atomic.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv_busdma.h>
end_include

begin_comment
comment|/*  * VMBUS version is 32 bit, upper 16 bit for major_number and lower  * 16 bit for minor_number.  *  * 0.13  --  Windows Server 2008  * 1.1   --  Windows 7  * 2.4   --  Windows 8  * 3.0   --  Windows 8.1  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_VERSION_WS2008
value|((0<< 16) | (13))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_WIN7
value|((1<< 16) | (1))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_WIN8
value|((2<< 16) | (4))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_WIN8_1
value|((3<< 16) | (0))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_MAJOR
parameter_list|(
name|ver
parameter_list|)
value|(((uint32_t)(ver))>> 16)
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_MINOR
parameter_list|(
name|ver
parameter_list|)
value|(((uint32_t)(ver))& 0xffff)
end_define

begin_struct
struct|struct
name|hyperv_guid
block|{
name|uint8_t
name|hv_guid
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|HYPERV_GUID_STRLEN
value|40
end_define

begin_function_decl
name|int
name|hyperv_guid2str
parameter_list|(
specifier|const
name|struct
name|hyperv_guid
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 	 * offset in bytes from the start of ring data below 	 */
specifier|volatile
name|uint32_t
name|write_index
decl_stmt|;
comment|/* 	 * offset in bytes from the start of ring data below 	 */
specifier|volatile
name|uint32_t
name|read_index
decl_stmt|;
comment|/* 	 * NOTE: The interrupt_mask field is used only for channels, but 	 * vmbus connection also uses this data structure 	 */
specifier|volatile
name|uint32_t
name|interrupt_mask
decl_stmt|;
comment|/* pad it to PAGE_SIZE so that data starts on a page */
name|uint8_t
name|reserved
index|[
literal|4084
index|]
decl_stmt|;
comment|/* 	 * WARNING: Ring data starts here 	 *  !!! DO NOT place any fields below this !!! 	 */
name|uint8_t
name|buffer
index|[
literal|0
index|]
decl_stmt|;
comment|/* doubles as interrupt mask */
block|}
name|__packed
name|hv_vmbus_ring_buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_ring_buffer
modifier|*
name|ring_buffer
decl_stmt|;
name|struct
name|mtx
name|ring_lock
decl_stmt|;
name|uint32_t
name|ring_data_size
decl_stmt|;
comment|/* ring_size */
block|}
name|hv_vmbus_ring_buffer_info
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|hv_vmbus_channel
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vmbus_chan_callback_t
function_decl|)
parameter_list|(
name|struct
name|hv_vmbus_channel
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_channel
block|{
name|device_t
name|ch_dev
decl_stmt|;
name|struct
name|vmbus_softc
modifier|*
name|ch_vmbus
decl_stmt|;
name|uint32_t
name|ch_flags
decl_stmt|;
comment|/* VMBUS_CHAN_FLAG_ */
name|uint32_t
name|ch_id
decl_stmt|;
comment|/* channel id */
comment|/* 	 * These are based on the offer_msg.monitor_id. 	 * Save it here for easy access. 	 */
name|int
name|ch_montrig_idx
decl_stmt|;
comment|/* MNF trig index */
name|uint32_t
name|ch_montrig_mask
decl_stmt|;
comment|/* MNF trig mask */
comment|/* 	 * TX bufring; at the beginning of ch_bufring. 	 */
name|hv_vmbus_ring_buffer_info
name|ch_txbr
decl_stmt|;
comment|/* 	 * RX bufring; immediately following ch_txbr. 	 */
name|hv_vmbus_ring_buffer_info
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
name|struct
name|hyperv_mon_param
modifier|*
name|ch_monprm
decl_stmt|;
name|struct
name|hyperv_dma
name|ch_monprm_dma
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
argument|hv_vmbus_channel
argument_list|)
name|ch_subchans
expr_stmt|;
name|int
name|ch_subchan_cnt
decl_stmt|;
comment|/* If this is a sub-channel */
name|TAILQ_ENTRY
argument_list|(
argument|hv_vmbus_channel
argument_list|)
name|ch_sublink
expr_stmt|;
comment|/* sub-channel link */
name|struct
name|hv_vmbus_channel
modifier|*
name|ch_prichan
decl_stmt|;
comment|/* owner primary chan */
comment|/* 	 * Driver private data 	 */
name|void
modifier|*
name|ch_dev_priv1
decl_stmt|;
name|void
modifier|*
name|ch_dev_priv2
decl_stmt|;
name|void
modifier|*
name|ch_dev_priv3
decl_stmt|;
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
name|ch_detach_task
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|hv_vmbus_channel
argument_list|)
name|ch_prilink
expr_stmt|;
comment|/* primary chan link */
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
name|sysctl_ctx_list
name|ch_sysctl_ctx
decl_stmt|;
block|}
name|hv_vmbus_channel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VMBUS_CHAN_ISPRIMARY
parameter_list|(
name|chan
parameter_list|)
value|((chan)->ch_subidx == 0)
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_FLAG_HASMNF
value|0x0001
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
name|VMBUS_CHAN_ST_OPENED_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_ST_OPENED
value|(1<< VMBUS_CHAN_ST_OPENED_SHIFT)
end_define

begin_comment
comment|/**  * @brief Get physical address from virtual  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|hv_get_phys_addr
parameter_list|(
name|void
modifier|*
name|virt
parameter_list|)
block|{
name|unsigned
name|long
name|ret
decl_stmt|;
name|ret
operator|=
operator|(
name|vtophys
argument_list|(
name|virt
argument_list|)
operator||
operator|(
operator|(
name|vm_offset_t
operator|)
name|virt
operator|&
name|PAGE_MASK
operator|)
operator|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|hv_vmbus_channel
operator|*
name|vmbus_get_channel
argument_list|(
argument|device_t dev
argument_list|)
block|{
return|return
name|device_get_ivars
argument_list|(
name|dev
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HYPERV_H__ */
end_comment

end_unit

