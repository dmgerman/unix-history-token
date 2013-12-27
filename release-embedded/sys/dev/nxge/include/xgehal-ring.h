begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_HAL_RING_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_HAL_RING_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal-channel.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal-config.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal-mm.h>
end_include

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/* HW ring configuration */
end_comment

begin_define
define|#
directive|define
name|XGE_HAL_RING_RXDBLOCK_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_OK
value|0x0
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_PARITY
value|0x1
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_ABORT
value|0x2
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_PARITY_ABORT
value|0x3
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_RDA_FAILURE
value|0x4
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_UNKNOWN_PROTO
value|0x5
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_BAD_FCS
value|0x6
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_BUFF_SIZE
value|0x7
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_BAD_ECC
value|0x8
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_UNUSED_C
value|0xC
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE_UNKNOWN
value|0xF
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RING_USE_MTU
value|-1
end_define

begin_comment
comment|/* control_1 and control_2 formatting - same for all buffer modes */
end_comment

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_L3_CKSUM
parameter_list|(
name|control_1
parameter_list|)
value|((u16)(control_1>>16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_L4_CKSUM
parameter_list|(
name|control_1
parameter_list|)
value|((u16)(control_1& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_MASK_VLAN_TAG
value|vBIT(0xFFFF,48,16)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_SET_VLAN_TAG
parameter_list|(
name|control_2
parameter_list|,
name|val
parameter_list|)
value|control_2 |= (u16)val
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_VLAN_TAG
parameter_list|(
name|control_2
parameter_list|)
value|((u16)(control_2& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_POSTED_4_XFRAME
value|BIT(7)
end_define

begin_comment
comment|/* control_1 */
end_comment

begin_define
define|#
directive|define
name|XGE_HAL_RXD_NOT_COMPLETED
value|BIT(0)
end_define

begin_comment
comment|/* control_2 */
end_comment

begin_define
define|#
directive|define
name|XGE_HAL_RXD_T_CODE
value|(BIT(12)|BIT(13)|BIT(14)|BIT(15))
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_T_CODE
parameter_list|(
name|control_1
parameter_list|)
define|\
value|((control_1& XGE_HAL_RXD_T_CODE)>>48)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_SET_T_CODE
parameter_list|(
name|control_1
parameter_list|,
name|val
parameter_list|)
define|\
value|(control_1 |= (((u64)val& 0xF)<< 48))
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_MASK_FRAME_TYPE
value|vBIT(0x3,25,2)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_MASK_FRAME_PROTO
value|vBIT(0xFFFF,24,8)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_FRAME_TYPE
parameter_list|(
name|control_1
parameter_list|)
define|\
value|(u8)(0x3& ((control_1& XGE_HAL_RXD_MASK_FRAME_TYPE)>> 37))
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_FRAME_PROTO
parameter_list|(
name|control_1
parameter_list|)
define|\
value|(u8)((control_1& XGE_HAL_RXD_MASK_FRAME_PROTO)>> 32)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_FRAME_PROTO_VLAN_TAGGED
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_FRAME_PROTO_IPV4
value|BIT(27)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_FRAME_PROTO_IPV6
value|BIT(28)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_FRAME_PROTO_IP_FRAGMENTED
value|BIT(29)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_FRAME_PROTO_TCP
value|BIT(30)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_FRAME_PROTO_UDP
value|BIT(31)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_FRAME_TCP_OR_UDP
value|(XGE_HAL_RXD_FRAME_PROTO_TCP | \ 	            XGE_HAL_RXD_FRAME_PROTO_UDP)
end_define

begin_comment
comment|/**  * enum xge_hal_frame_type_e - Ethernet frame format.  * @XGE_HAL_FRAME_TYPE_DIX: DIX (Ethernet II) format.  * @XGE_HAL_FRAME_TYPE_LLC: LLC format.  * @XGE_HAL_FRAME_TYPE_SNAP: SNAP format.  * @XGE_HAL_FRAME_TYPE_IPX: IPX format.  *  * Ethernet frame format.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|xge_hal_frame_type_e
block|{
name|XGE_HAL_FRAME_TYPE_DIX
init|=
literal|0x0
block|,
name|XGE_HAL_FRAME_TYPE_LLC
init|=
literal|0x1
block|,
name|XGE_HAL_FRAME_TYPE_SNAP
init|=
literal|0x2
block|,
name|XGE_HAL_FRAME_TYPE_IPX
init|=
literal|0x3
block|, }
name|xge_hal_frame_type_e
typedef|;
end_typedef

begin_comment
comment|/**  * enum xge_hal_frame_proto_e - Higher-layer ethernet protocols.  * @XGE_HAL_FRAME_PROTO_VLAN_TAGGED: VLAN.  * @XGE_HAL_FRAME_PROTO_IPV4: IPv4.  * @XGE_HAL_FRAME_PROTO_IPV6: IPv6.  * @XGE_HAL_FRAME_PROTO_IP_FRAGMENTED: IP fragmented.  * @XGE_HAL_FRAME_PROTO_TCP: TCP.  * @XGE_HAL_FRAME_PROTO_UDP: UDP.  * @XGE_HAL_FRAME_PROTO_TCP_OR_UDP: TCP or UDP.  *  * Higher layer ethernet protocols and options.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|xge_hal_frame_proto_e
block|{
name|XGE_HAL_FRAME_PROTO_VLAN_TAGGED
init|=
literal|0x80
block|,
name|XGE_HAL_FRAME_PROTO_IPV4
init|=
literal|0x10
block|,
name|XGE_HAL_FRAME_PROTO_IPV6
init|=
literal|0x08
block|,
name|XGE_HAL_FRAME_PROTO_IP_FRAGMENTED
init|=
literal|0x04
block|,
name|XGE_HAL_FRAME_PROTO_TCP
init|=
literal|0x02
block|,
name|XGE_HAL_FRAME_PROTO_UDP
init|=
literal|0x01
block|,
name|XGE_HAL_FRAME_PROTO_TCP_OR_UDP
init|=
operator|(
name|XGE_HAL_FRAME_PROTO_TCP
operator||
expr|\
name|XGE_HAL_FRAME_PROTO_UDP
operator|)
block|}
name|xge_hal_frame_proto_e
typedef|;
end_typedef

begin_comment
comment|/*  * xge_hal_ring_rxd_1_t  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u64
name|host_control
decl_stmt|;
name|u64
name|control_1
decl_stmt|;
name|u64
name|control_2
decl_stmt|;
define|#
directive|define
name|XGE_HAL_RXD_1_MASK_BUFFER0_SIZE
value|vBIT(0xFFFF,0,16)
define|#
directive|define
name|XGE_HAL_RXD_1_SET_BUFFER0_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,0,16)
define|#
directive|define
name|XGE_HAL_RXD_1_GET_BUFFER0_SIZE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(int)((Control_2& vBIT(0xFFFF,0,16))>>48)
define|#
directive|define
name|XGE_HAL_RXD_1_GET_RTH_VALUE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(u32)((Control_2& vBIT(0xFFFFFFFF,16,32))>>16)
name|u64
name|buffer0_ptr
decl_stmt|;
block|}
name|xge_hal_ring_rxd_1_t
typedef|;
end_typedef

begin_comment
comment|/*  * xge_hal_ring_rxd_3_t  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u64
name|host_control
decl_stmt|;
name|u64
name|control_1
decl_stmt|;
name|u64
name|control_2
decl_stmt|;
define|#
directive|define
name|XGE_HAL_RXD_3_MASK_BUFFER0_SIZE
value|vBIT(0xFF,8,8)
define|#
directive|define
name|XGE_HAL_RXD_3_SET_BUFFER0_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,8,8)
define|#
directive|define
name|XGE_HAL_RXD_3_MASK_BUFFER1_SIZE
value|vBIT(0xFFFF,16,16)
define|#
directive|define
name|XGE_HAL_RXD_3_SET_BUFFER1_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,16,16)
define|#
directive|define
name|XGE_HAL_RXD_3_MASK_BUFFER2_SIZE
value|vBIT(0xFFFF,32,16)
define|#
directive|define
name|XGE_HAL_RXD_3_SET_BUFFER2_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,32,16)
define|#
directive|define
name|XGE_HAL_RXD_3_GET_BUFFER0_SIZE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(int)((Control_2& vBIT(0xFF,8,8))>>48)
define|#
directive|define
name|XGE_HAL_RXD_3_GET_BUFFER1_SIZE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(int)((Control_2& vBIT(0xFFFF,16,16))>>32)
define|#
directive|define
name|XGE_HAL_RXD_3_GET_BUFFER2_SIZE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(int)((Control_2& vBIT(0xFFFF,32,16))>>16)
name|u64
name|buffer0_ptr
decl_stmt|;
name|u64
name|buffer1_ptr
decl_stmt|;
name|u64
name|buffer2_ptr
decl_stmt|;
block|}
name|xge_hal_ring_rxd_3_t
typedef|;
end_typedef

begin_comment
comment|/*  * xge_hal_ring_rxd_5_t  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
ifdef|#
directive|ifdef
name|XGE_OS_HOST_BIG_ENDIAN
name|u32
name|host_control
decl_stmt|;
name|u32
name|control_3
decl_stmt|;
else|#
directive|else
name|u32
name|control_3
decl_stmt|;
name|u32
name|host_control
decl_stmt|;
endif|#
directive|endif
define|#
directive|define
name|XGE_HAL_RXD_5_MASK_BUFFER3_SIZE
value|vBIT(0xFFFF,32,16)
define|#
directive|define
name|XGE_HAL_RXD_5_SET_BUFFER3_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,32,16)
define|#
directive|define
name|XGE_HAL_RXD_5_MASK_BUFFER4_SIZE
value|vBIT(0xFFFF,48,16)
define|#
directive|define
name|XGE_HAL_RXD_5_SET_BUFFER4_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,48,16)
define|#
directive|define
name|XGE_HAL_RXD_5_GET_BUFFER3_SIZE
parameter_list|(
name|Control_3
parameter_list|)
define|\
value|(int)((Control_3& vBIT(0xFFFF,32,16))>>16)
define|#
directive|define
name|XGE_HAL_RXD_5_GET_BUFFER4_SIZE
parameter_list|(
name|Control_3
parameter_list|)
define|\
value|(int)((Control_3& vBIT(0xFFFF,48,16)))
name|u64
name|control_1
decl_stmt|;
name|u64
name|control_2
decl_stmt|;
define|#
directive|define
name|XGE_HAL_RXD_5_MASK_BUFFER0_SIZE
value|vBIT(0xFFFF,0,16)
define|#
directive|define
name|XGE_HAL_RXD_5_SET_BUFFER0_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,0,16)
define|#
directive|define
name|XGE_HAL_RXD_5_MASK_BUFFER1_SIZE
value|vBIT(0xFFFF,16,16)
define|#
directive|define
name|XGE_HAL_RXD_5_SET_BUFFER1_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,16,16)
define|#
directive|define
name|XGE_HAL_RXD_5_MASK_BUFFER2_SIZE
value|vBIT(0xFFFF,32,16)
define|#
directive|define
name|XGE_HAL_RXD_5_SET_BUFFER2_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val,32,16)
define|#
directive|define
name|XGE_HAL_RXD_5_GET_BUFFER0_SIZE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(int)((Control_2& vBIT(0xFFFF,0,16))>>48)
define|#
directive|define
name|XGE_HAL_RXD_5_GET_BUFFER1_SIZE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(int)((Control_2& vBIT(0xFFFF,16,16))>>32)
define|#
directive|define
name|XGE_HAL_RXD_5_GET_BUFFER2_SIZE
parameter_list|(
name|Control_2
parameter_list|)
define|\
value|(int)((Control_2& vBIT(0xFFFF,32,16))>>16)
name|u64
name|buffer0_ptr
decl_stmt|;
name|u64
name|buffer1_ptr
decl_stmt|;
name|u64
name|buffer2_ptr
decl_stmt|;
name|u64
name|buffer3_ptr
decl_stmt|;
name|u64
name|buffer4_ptr
decl_stmt|;
block|}
name|xge_hal_ring_rxd_5_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_RTH_SPDM_HIT
parameter_list|(
name|Control_1
parameter_list|)
define|\
value|(u8)((Control_1& BIT(18))>>45)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_RTH_IT_HIT
parameter_list|(
name|Control_1
parameter_list|)
define|\
value|(u8)((Control_1& BIT(19))>>44)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_GET_RTH_HASH_TYPE
parameter_list|(
name|Control_1
parameter_list|)
define|\
value|(u8)((Control_1& vBIT(0xF,20,4))>>40)
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_TCP_IPV4
value|0x1
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_UDP_IPV4
value|0x2
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_IPV4
value|0x3
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_TCP_IPV6
value|0x4
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_UDP_IPV6
value|0x5
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_IPV6
value|0x6
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_TCP_IPV6_EX
value|0x7
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_UDP_IPV6_EX
value|0x8
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RXD_HASH_TYPE_IPV6_EX
value|0x9
end_define

begin_typedef
typedef|typedef
name|u8
name|xge_hal_ring_block_t
index|[
name|XGE_HAL_RING_RXDBLOCK_SIZE
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XGE_HAL_RING_NEXT_BLOCK_POINTER_OFFSET
value|0xFF8
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RING_MEMBLOCK_IDX_OFFSET
value|0xFF0
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RING_RXD_SIZEOF
parameter_list|(
name|n
parameter_list|)
define|\
value|(n==1 ? sizeof(xge_hal_ring_rxd_1_t) : \ 	    (n==3 ? sizeof(xge_hal_ring_rxd_3_t) : \ 	        sizeof(xge_hal_ring_rxd_5_t)))
end_define

begin_define
define|#
directive|define
name|XGE_HAL_RING_RXDS_PER_BLOCK
parameter_list|(
name|n
parameter_list|)
define|\
value|(n==1 ? 127 : (n==3 ? 85 : 63))
end_define

begin_comment
comment|/**  * struct xge_hal_ring_rxd_priv_t - Receive descriptor HAL-private data.  * @dma_addr: DMA (mapped) address of _this_ descriptor.  * @dma_handle: DMA handle used to map the descriptor onto device.  * @dma_offset: Descriptor's offset in the memory block. HAL allocates  *              descriptors in memory blocks of  *              %XGE_HAL_RING_RXDBLOCK_SIZE  *              bytes. Each memblock is contiguous DMA-able memory. Each  *              memblock contains 1 or more 4KB RxD blocks visible to the  *              Xframe hardware.  * @dma_object: DMA address and handle of the memory block that contains  *              the descriptor. This member is used only in the "checked"  *              version of the HAL (to enforce certain assertions);  *              otherwise it gets compiled out.  * @allocated: True if the descriptor is reserved, 0 otherwise. Internal usage.  *  * Per-receive decsriptor HAL-private data. HAL uses the space to keep DMA  * information associated with the descriptor. Note that ULD can ask HAL  * to allocate additional per-descriptor space for its own (ULD-specific)  * purposes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_hal_ring_rxd_priv_t
block|{
name|dma_addr_t
name|dma_addr
decl_stmt|;
name|pci_dma_h
name|dma_handle
decl_stmt|;
name|ptrdiff_t
name|dma_offset
decl_stmt|;
ifdef|#
directive|ifdef
name|XGE_DEBUG_ASSERT
name|xge_hal_mempool_dma_t
modifier|*
name|dma_object
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XGE_OS_MEMORY_CHECK
name|int
name|allocated
decl_stmt|;
endif|#
directive|endif
block|}
name|xge_hal_ring_rxd_priv_t
typedef|;
end_typedef

begin_comment
comment|/**  * struct xge_hal_ring_t - Ring channel.  * @channel: Channel "base" of this ring, the common part of all HAL  *           channels.  * @buffer_mode: 1, 3, or 5. The value specifies a receive buffer mode,  *          as per Xframe User Guide.  * @indicate_max_pkts: Maximum number of packets processed within a single  *          interrupt. Can be used to limit the time spent inside hw  *          interrupt.  * @config: Ring configuration, part of device configuration  *          (see xge_hal_device_config_t{}).  * @rxd_size: RxD sizes for 1-, 3- or 5- buffer modes. As per Xframe spec,  *            1-buffer mode descriptor is 32 byte long, etc.  * @rxd_priv_size: Per RxD size reserved (by HAL) for ULD to keep per-descriptor  *                 data (e.g., DMA handle for Solaris)  * @rxds_per_block: Number of descriptors per hardware-defined RxD  *                  block. Depends on the (1-,3-,5-) buffer mode.  * @mempool: Memory pool, the pool from which descriptors get allocated.  *           (See xge_hal_mm.h).  * @rxdblock_priv_size: Reserved at the end of each RxD block. HAL internal  *                      usage. Not to confuse with @rxd_priv_size.  * @reserved_rxds_arr: Array of RxD pointers. At any point in time each  *                     entry in this array is available for allocation  *                     (via xge_hal_ring_dtr_reserve()) and posting.  * @cmpl_cnt: Completion counter. Is reset to zero upon entering the ISR.  *            Used in conjunction with @indicate_max_pkts.   * Ring channel.  *  * Note: The structure is cache line aligned to better utilize  *       CPU cache performance.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_hal_ring_t
block|{
name|xge_hal_channel_t
name|channel
decl_stmt|;
name|int
name|buffer_mode
decl_stmt|;
name|int
name|indicate_max_pkts
decl_stmt|;
name|xge_hal_ring_config_t
modifier|*
name|config
decl_stmt|;
name|int
name|rxd_size
decl_stmt|;
name|int
name|rxd_priv_size
decl_stmt|;
name|int
name|rxds_per_block
decl_stmt|;
name|xge_hal_mempool_t
modifier|*
name|mempool
decl_stmt|;
name|int
name|rxdblock_priv_size
decl_stmt|;
name|void
modifier|*
modifier|*
name|reserved_rxds_arr
decl_stmt|;
name|int
name|cmpl_cnt
decl_stmt|;
block|}
name|__xge_os_attr_cacheline_aligned
name|xge_hal_ring_t
typedef|;
end_typedef

begin_comment
comment|/**  * struct xge_hal_dtr_info_t - Extended information associated with a  * completed ring descriptor.  * @l3_cksum: Result of IP checksum check (by Xframe hardware).  *            This field containing XGE_HAL_L3_CKSUM_OK would mean that  *            the checksum is correct, otherwise - the datagram is  *            corrupted.  * @l4_cksum: Result of TCP/UDP checksum check (by Xframe hardware).  *            This field containing XGE_HAL_L4_CKSUM_OK would mean that  *            the checksum is correct. Otherwise - the packet is  *            corrupted.  * @frame: See xge_hal_frame_type_e{}.  * @proto:    Reporting bits for various higher-layer protocols, including (but  *        note restricted to) TCP and UDP. See xge_hal_frame_proto_e{}.  * @vlan:     VLAN tag extracted from the received frame.  * @rth_value: Receive Traffic Hashing(RTH) hash value. Produced by Xframe II  *             hardware if RTH is enabled.  * @rth_it_hit: Set, If RTH hash value calculated by the Xframe II hardware  *             has a matching entry in the Indirection table.  * @rth_spdm_hit: Set, If RTH hash value calculated by the Xframe II hardware  *             has a matching entry in the Socket Pair Direct Match table.  * @rth_hash_type: RTH hash code of the function used to calculate the hash.  * @reserved_pad: Unused byte.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_hal_dtr_info_t
block|{
name|int
name|l3_cksum
decl_stmt|;
name|int
name|l4_cksum
decl_stmt|;
name|int
name|frame
decl_stmt|;
comment|/* zero or more of xge_hal_frame_type_e flags */
name|int
name|proto
decl_stmt|;
comment|/* zero or more of xge_hal_frame_proto_e flags */
name|int
name|vlan
decl_stmt|;
name|u32
name|rth_value
decl_stmt|;
name|u8
name|rth_it_hit
decl_stmt|;
name|u8
name|rth_spdm_hit
decl_stmt|;
name|u8
name|rth_hash_type
decl_stmt|;
name|u8
name|reserved_pad
decl_stmt|;
block|}
name|xge_hal_dtr_info_t
typedef|;
end_typedef

begin_comment
comment|/* ========================== RING PRIVATE API ============================ */
end_comment

begin_function_decl
name|xge_hal_status_e
name|__hal_ring_open
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_channel_attr_t
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ring_close
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ring_hw_initialize
parameter_list|(
name|xge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ring_mtu_set
parameter_list|(
name|xge_hal_device_h
name|devh
parameter_list|,
name|int
name|new_mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ring_prc_enable
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ring_prc_disable
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|__hal_ring_initial_replenish
parameter_list|(
name|xge_hal_channel_t
modifier|*
name|channel
parameter_list|,
name|xge_hal_channel_reopen_e
name|reopen
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XGE_DEBUG_FP
argument_list|)
operator|&&
operator|(
name|XGE_DEBUG_FP
operator|&
name|XGE_DEBUG_FP_RING
operator|)
end_if

begin_define
define|#
directive|define
name|__HAL_STATIC_RING
end_define

begin_define
define|#
directive|define
name|__HAL_INLINE_RING
end_define

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|int
name|__hal_ring_block_memblock_idx
parameter_list|(
name|xge_hal_ring_block_t
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|__hal_ring_block_memblock_idx_set
parameter_list|(
name|xge_hal_ring_block_t
modifier|*
name|block
parameter_list|,
name|int
name|memblock_idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|dma_addr_t
name|__hal_ring_block_next_pointer
parameter_list|(
name|xge_hal_ring_block_t
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|__hal_ring_block_next_pointer_set
parameter_list|(
name|xge_hal_ring_block_t
modifier|*
name|block
parameter_list|,
name|dma_addr_t
name|dma_next
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|xge_hal_ring_rxd_priv_t
modifier|*
name|__hal_ring_rxd_priv
parameter_list|(
name|xge_hal_ring_t
modifier|*
name|ring
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* =========================== RING PUBLIC API ============================ */
end_comment

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|xge_hal_status_e
name|xge_hal_ring_dtr_reserve
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
modifier|*
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
modifier|*
name|xge_hal_ring_dtr_private
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_1b_set
parameter_list|(
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|dma_addr_t
name|dma_pointer
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_info_get
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|xge_hal_dtr_info_t
modifier|*
name|ext_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_1b_get
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|dma_addr_t
modifier|*
name|dma_pointer
parameter_list|,
name|int
modifier|*
name|pkt_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_3b_set
parameter_list|(
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|dma_addr_t
name|dma_pointers
index|[]
parameter_list|,
name|int
name|sizes
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_3b_get
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|dma_addr_t
name|dma_pointers
index|[]
parameter_list|,
name|int
name|sizes
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_5b_set
parameter_list|(
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|dma_addr_t
name|dma_pointers
index|[]
parameter_list|,
name|int
name|sizes
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_5b_get
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|dma_addr_t
name|dma_pointer
index|[]
parameter_list|,
name|int
name|sizes
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_post
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_pre_post
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_post_post
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_post_post_wmb
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|xge_hal_status_e
name|xge_hal_ring_dtr_next_completed
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
modifier|*
name|dtrh
parameter_list|,
name|u8
modifier|*
name|t_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|void
name|xge_hal_ring_dtr_free
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtrh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__HAL_STATIC_RING
name|__HAL_INLINE_RING
name|xge_hal_status_e
name|xge_hal_ring_is_next_dtr_completed
parameter_list|(
name|xge_hal_channel_h
name|channelh
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XGE_FASTPATH_EXTERN */
end_comment

begin_define
define|#
directive|define
name|__HAL_STATIC_RING
value|static
end_define

begin_define
define|#
directive|define
name|__HAL_INLINE_RING
value|inline
end_define

begin_include
include|#
directive|include
file|<dev/nxge/xgehal/xgehal-ring-fp.c>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_FASTPATH_INLINE */
end_comment

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_HAL_RING_H */
end_comment

end_unit

