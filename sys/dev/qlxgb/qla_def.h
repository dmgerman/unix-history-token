begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011-2013 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: qla_def.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLA_DEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLA_DEF_H_
end_define

begin_define
define|#
directive|define
name|BIT_0
value|(0x1<< 0)
end_define

begin_define
define|#
directive|define
name|BIT_1
value|(0x1<< 1)
end_define

begin_define
define|#
directive|define
name|BIT_2
value|(0x1<< 2)
end_define

begin_define
define|#
directive|define
name|BIT_3
value|(0x1<< 3)
end_define

begin_define
define|#
directive|define
name|BIT_4
value|(0x1<< 4)
end_define

begin_define
define|#
directive|define
name|BIT_5
value|(0x1<< 5)
end_define

begin_define
define|#
directive|define
name|BIT_6
value|(0x1<< 6)
end_define

begin_define
define|#
directive|define
name|BIT_7
value|(0x1<< 7)
end_define

begin_define
define|#
directive|define
name|BIT_8
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|BIT_9
value|(0x1<< 9)
end_define

begin_define
define|#
directive|define
name|BIT_10
value|(0x1<< 10)
end_define

begin_define
define|#
directive|define
name|BIT_11
value|(0x1<< 11)
end_define

begin_define
define|#
directive|define
name|BIT_12
value|(0x1<< 12)
end_define

begin_define
define|#
directive|define
name|BIT_13
value|(0x1<< 13)
end_define

begin_define
define|#
directive|define
name|BIT_14
value|(0x1<< 14)
end_define

begin_define
define|#
directive|define
name|BIT_15
value|(0x1<< 15)
end_define

begin_define
define|#
directive|define
name|BIT_16
value|(0x1<< 16)
end_define

begin_define
define|#
directive|define
name|BIT_17
value|(0x1<< 17)
end_define

begin_define
define|#
directive|define
name|BIT_18
value|(0x1<< 18)
end_define

begin_define
define|#
directive|define
name|BIT_19
value|(0x1<< 19)
end_define

begin_define
define|#
directive|define
name|BIT_20
value|(0x1<< 20)
end_define

begin_define
define|#
directive|define
name|BIT_21
value|(0x1<< 21)
end_define

begin_define
define|#
directive|define
name|BIT_22
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|BIT_23
value|(0x1<< 23)
end_define

begin_define
define|#
directive|define
name|BIT_24
value|(0x1<< 24)
end_define

begin_define
define|#
directive|define
name|BIT_25
value|(0x1<< 25)
end_define

begin_define
define|#
directive|define
name|BIT_26
value|(0x1<< 26)
end_define

begin_define
define|#
directive|define
name|BIT_27
value|(0x1<< 27)
end_define

begin_define
define|#
directive|define
name|BIT_28
value|(0x1<< 28)
end_define

begin_define
define|#
directive|define
name|BIT_29
value|(0x1<< 29)
end_define

begin_define
define|#
directive|define
name|BIT_30
value|(0x1<< 30)
end_define

begin_define
define|#
directive|define
name|BIT_31
value|(0x1<< 31)
end_define

begin_struct
struct|struct
name|qla_rx_buf
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_addr_t
name|paddr
decl_stmt|;
name|uint32_t
name|handle
decl_stmt|;
name|void
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_rx_buf
name|qla_rx_buf_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_tx_buf
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_tx_buf
name|qla_tx_buf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QLA_MAX_SEGMENTS
value|63
end_define

begin_comment
comment|/* maximum # of segs in a sg list */
end_comment

begin_define
define|#
directive|define
name|QLA_MAX_FRAME_SIZE
value|MJUM9BYTES
end_define

begin_define
define|#
directive|define
name|QLA_STD_FRAME_SIZE
value|1514
end_define

begin_define
define|#
directive|define
name|QLA_MAX_TSO_FRAME_SIZE
value|((64 * 1024 - 1) + 22)
end_define

begin_comment
comment|/* Number of MSIX/MSI Vectors required */
end_comment

begin_define
define|#
directive|define
name|Q8_MSI_COUNT
value|4
end_define

begin_struct
struct|struct
name|qla_ivec
block|{
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|void
modifier|*
name|ha
decl_stmt|;
name|struct
name|task
name|rcv_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|rcv_tq
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_ivec
name|qla_ivec_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QLA_WATCHDOG_CALLOUT_TICKS
value|1
end_define

begin_comment
comment|/*  * Adapter structure contains the hardware independent information of the  * pci function.  */
end_comment

begin_struct
struct|struct
name|qla_host
block|{
specifier|volatile
struct|struct
block|{
specifier|volatile
name|uint32_t
name|qla_watchdog_active
range|:
literal|1
decl_stmt|,
name|qla_watchdog_exit
range|:
literal|1
decl_stmt|,
name|qla_watchdog_pause
range|:
literal|1
decl_stmt|,
name|lro_init
range|:
literal|1
decl_stmt|,
name|stop_rcv
range|:
literal|1
decl_stmt|,
name|link_up
range|:
literal|1
decl_stmt|,
name|parent_tag
range|:
literal|1
decl_stmt|,
name|lock_init
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|device_t
name|pci_dev
decl_stmt|;
name|uint8_t
name|pci_func
decl_stmt|;
name|uint16_t
name|watchdog_ticks
decl_stmt|;
name|uint8_t
name|resvd
decl_stmt|;
comment|/* ioctl related */
name|struct
name|cdev
modifier|*
name|ioctl_dev
decl_stmt|;
comment|/* register mapping */
name|struct
name|resource
modifier|*
name|pci_reg
decl_stmt|;
name|int
name|reg_rid
decl_stmt|;
comment|/* interrupts */
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|msix_count
decl_stmt|;
name|void
modifier|*
name|intr_handle
decl_stmt|;
name|qla_ivec_t
name|irq_vec
index|[
name|Q8_MSI_COUNT
index|]
decl_stmt|;
comment|/* parent dma tag */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
comment|/* interface to o.s */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|uint16_t
name|rsrvd0
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
comment|/* hardware access lock */
name|struct
name|mtx
name|hw_lock
decl_stmt|;
specifier|volatile
name|uint32_t
name|hw_lock_held
decl_stmt|;
comment|/* transmit and receive buffers */
name|qla_tx_buf_t
name|tx_buf
index|[
name|NUM_TX_DESCRIPTORS
index|]
decl_stmt|;
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
name|struct
name|mtx
name|tx_lock
decl_stmt|;
name|struct
name|task
name|tx_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tx_tq
decl_stmt|;
name|struct
name|callout
name|tx_callout
decl_stmt|;
name|qla_rx_buf_t
name|rx_buf
index|[
name|NUM_RX_DESCRIPTORS
index|]
decl_stmt|;
name|qla_rx_buf_t
name|rx_jbuf
index|[
name|NUM_RX_JUMBO_DESCRIPTORS
index|]
decl_stmt|;
name|bus_dma_tag_t
name|rx_tag
decl_stmt|;
name|struct
name|mtx
name|rx_lock
decl_stmt|;
name|struct
name|mtx
name|rxj_lock
decl_stmt|;
comment|/* stats */
name|uint32_t
name|err_m_getcl
decl_stmt|;
name|uint32_t
name|err_m_getjcl
decl_stmt|;
name|uint32_t
name|err_tx_dmamap_create
decl_stmt|;
name|uint32_t
name|err_tx_dmamap_load
decl_stmt|;
name|uint32_t
name|err_tx_defrag
decl_stmt|;
name|uint64_t
name|rx_frames
decl_stmt|;
name|uint64_t
name|rx_bytes
decl_stmt|;
name|uint64_t
name|tx_frames
decl_stmt|;
name|uint64_t
name|tx_bytes
decl_stmt|;
name|uint32_t
name|fw_ver_major
decl_stmt|;
name|uint32_t
name|fw_ver_minor
decl_stmt|;
name|uint32_t
name|fw_ver_sub
decl_stmt|;
name|uint32_t
name|fw_ver_build
decl_stmt|;
comment|/* hardware specific */
name|qla_hw_t
name|hw
decl_stmt|;
comment|/* debug stuff */
specifier|volatile
specifier|const
name|char
modifier|*
name|qla_lock
decl_stmt|;
specifier|volatile
specifier|const
name|char
modifier|*
name|qla_unlock
decl_stmt|;
name|uint8_t
name|fw_ver_str
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_host
name|qla_host_t
typedef|;
end_typedef

begin_comment
comment|/* note that align has to be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|QL_ALIGN
parameter_list|(
name|size
parameter_list|,
name|align
parameter_list|)
value|(((size) + ((align) - 1))& (~((align) - 1)))
end_define

begin_define
define|#
directive|define
name|QL_MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x< y) ? x : y)
end_define

begin_define
define|#
directive|define
name|QL_RUNNING
parameter_list|(
name|ifp
parameter_list|)
define|\
value|((ifp->if_drv_flags& (IFF_DRV_RUNNING | IFF_DRV_OACTIVE)) == \ 			IFF_DRV_RUNNING)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLA_DEF_H_ */
end_comment

end_unit

