begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 by David E. O'Brien<obrien@FreeBSD.org>.  * Copyright (c) 2003 by Quinton Dolan<q@onthenet.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS `AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * $Id: if_nvreg.h,v 1.6 2004/08/12 14:00:05 q Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_NVEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_NVEREG_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NVIDIA_VENDORID
end_ifndef

begin_define
define|#
directive|define
name|NVIDIA_VENDORID
value|0x10DE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFORCE_MCPNET1_DEVICEID
value|0x01C3
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET2_DEVICEID
value|0x0066
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET3_DEVICEID
value|0x00D6
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET4_DEVICEID
value|0x0086
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET5_DEVICEID
value|0x008C
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET6_DEVICEID
value|0x00E6
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET7_DEVICEID
value|0x00DF
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET8_DEVICEID
value|0x0056
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET9_DEVICEID
value|0x0057
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET10_DEVICEID
value|0x0037
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET11_DEVICEID
value|0x0038
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET12_DEVICEID
value|0x0268
end_define

begin_define
define|#
directive|define
name|NFORCE_MCPNET13_DEVICEID
value|0x0269
end_define

begin_define
define|#
directive|define
name|NV_RID
value|0x10
end_define

begin_define
define|#
directive|define
name|TX_RING_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|RX_RING_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|NV_MAX_FRAGS
value|32
end_define

begin_comment
comment|// match adapter.h:ADAPTER_WRITE_DATA.sElement[]
end_comment

begin_define
define|#
directive|define
name|FCS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG
value|0x0000
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_INIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_RUNNING
value|0x0002
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_DEINIT
value|0x0004
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_IOCTL
value|0x0008
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_INTERRUPT
value|0x0010
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_API
value|0x0020
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_LOCK
value|0x0040
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_BROKEN
value|0x0080
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_MII
value|0x0100
end_define

begin_define
define|#
directive|define
name|NVE_DEBUG_ALL
value|0xFFFF
end_define

begin_if
if|#
directive|if
name|NVE_DEBUG
end_if

begin_define
define|#
directive|define
name|DEBUGOUT
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|if (NVE_DEBUG& level) \     printf(fmt, ## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUGOUT
parameter_list|(
name|level
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

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulong
typedef|;
end_typedef

begin_struct
struct|struct
name|nve_map_buffer
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* mbuf receiving packet */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* DMA map */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nve_dma_info
block|{
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|struct
name|nve_map_buffer
name|buf
decl_stmt|;
name|u_int16_t
name|buflength
decl_stmt|;
name|caddr_t
name|vaddr
decl_stmt|;
comment|/* Virtual memory address */
name|bus_addr_t
name|paddr
decl_stmt|;
comment|/* DMA physical address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nve_rx_desc
block|{
name|struct
name|nve_rx_desc
modifier|*
name|next
decl_stmt|;
name|struct
name|nve_map_buffer
name|buf
decl_stmt|;
name|u_int16_t
name|buflength
decl_stmt|;
name|caddr_t
name|vaddr
decl_stmt|;
name|bus_addr_t
name|paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nve_tx_desc
block|{
comment|/* Don't add anything above this structure */
name|TX_INFO_ADAP
name|TxInfoAdap
decl_stmt|;
name|struct
name|nve_tx_desc
modifier|*
name|next
decl_stmt|;
name|struct
name|nve_map_buffer
name|buf
decl_stmt|;
name|u_int16_t
name|buflength
decl_stmt|;
name|u_int32_t
name|numfrags
decl_stmt|;
name|bus_dma_segment_t
name|frags
index|[
name|NV_MAX_FRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nve_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* interface info */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|ADAPTER_API
modifier|*
name|hwapi
decl_stmt|;
name|OS_API
name|osapi
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|callout
name|stat_callout
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
name|bus_dma_tag_t
name|mtag
decl_stmt|;
name|bus_dma_tag_t
name|rtag
decl_stmt|;
name|bus_dmamap_t
name|rmap
decl_stmt|;
name|bus_dma_tag_t
name|ttag
decl_stmt|;
name|bus_dmamap_t
name|tmap
decl_stmt|;
name|struct
name|nve_rx_desc
modifier|*
name|rx_desc
decl_stmt|;
name|struct
name|nve_tx_desc
modifier|*
name|tx_desc
decl_stmt|;
name|bus_addr_t
name|rx_addr
decl_stmt|;
name|bus_addr_t
name|tx_addr
decl_stmt|;
name|u_int16_t
name|rx_ring_full
decl_stmt|;
name|u_int16_t
name|tx_ring_full
decl_stmt|;
name|u_int32_t
name|cur_rx
decl_stmt|;
name|u_int32_t
name|cur_tx
decl_stmt|;
name|u_int32_t
name|pending_rxs
decl_stmt|;
name|u_int32_t
name|pending_txs
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* Stuff for dealing with the NVIDIA OS API */
name|struct
name|callout
name|ostimer
decl_stmt|;
name|PTIMER_FUNC
name|ostimer_func
decl_stmt|;
name|void
modifier|*
name|ostimer_params
decl_stmt|;
name|int
name|linkup
decl_stmt|;
name|ulong
name|tx_errors
decl_stmt|;
name|NV_UINT32
name|hwmode
decl_stmt|;
name|NV_UINT32
name|max_frame_size
decl_stmt|;
name|NV_UINT32
name|phyaddr
decl_stmt|;
name|NV_UINT32
name|media
decl_stmt|;
name|CMNDATA_OS_ADAPTER
name|adapterdata
decl_stmt|;
name|unsigned
name|char
name|original_mac_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nve_type
block|{
name|u_int16_t
name|vid_id
decl_stmt|;
name|u_int16_t
name|dev_id
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NVE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|NVE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|NVE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IF_Kbps
parameter_list|(
name|x
parameter_list|)
value|((x) * 1000)
end_define

begin_comment
comment|/* kilobits/sec. */
end_comment

begin_define
define|#
directive|define
name|IF_Mbps
parameter_list|(
name|x
parameter_list|)
value|(IF_Kbps((x) * 1000))
end_define

begin_comment
comment|/* megabits/sec. */
end_comment

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_function_decl
specifier|extern
name|int
name|ADAPTER_ReadPhy
parameter_list|(
name|PVOID
name|pContext
parameter_list|,
name|ULONG
name|ulPhyAddr
parameter_list|,
name|ULONG
name|ulReg
parameter_list|,
name|ULONG
modifier|*
name|pulVal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ADAPTER_WritePhy
parameter_list|(
name|PVOID
name|pContext
parameter_list|,
name|ULONG
name|ulPhyAddr
parameter_list|,
name|ULONG
name|ulReg
parameter_list|,
name|ULONG
name|ulVal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ADAPTER_Init
parameter_list|(
name|PVOID
name|pContext
parameter_list|,
name|USHORT
name|usForcedSpeed
parameter_list|,
name|UCHAR
name|ucForceDpx
parameter_list|,
name|UCHAR
name|ucForceMode
parameter_list|,
name|UINT
modifier|*
name|puiLinkState
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_NVEREG_H_ */
end_comment

end_unit

