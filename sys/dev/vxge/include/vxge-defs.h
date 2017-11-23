begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_DEFS_H
end_define

begin_define
define|#
directive|define
name|VXGE_PCI_VENDOR_ID
value|0x17D5
end_define

begin_define
define|#
directive|define
name|VXGE_PCI_DEVICE_ID_TITAN_1
value|0x5833
end_define

begin_define
define|#
directive|define
name|VXGE_PCI_REVISION_TITAN_1
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_PCI_DEVICE_ID_TITAN_1A
value|0x5833
end_define

begin_define
define|#
directive|define
name|VXGE_PCI_REVISION_TITAN_1A
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_PCI_DEVICE_ID_TITAN_2
value|0x5834
end_define

begin_define
define|#
directive|define
name|VXGE_PCI_REVISION_TITAN_2
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_MIN_FW_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_MIN_FW_MINOR_VERSION
value|8
end_define

begin_define
define|#
directive|define
name|VXGE_MIN_FW_BUILD_NUMBER
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_DRIVER_VENDOR
value|"Exar Corp."
end_define

begin_define
define|#
directive|define
name|VXGE_CHIP_FAMILY
value|"X3100"
end_define

begin_define
define|#
directive|define
name|VXGE_SUPPORTED_MEDIA_0
value|"Fiber"
end_define

begin_define
define|#
directive|define
name|VXGE_DRIVER_NAME
define|\
value|"Neterion X3100 10GbE PCIe Server Adapter Driver"
end_define

begin_comment
comment|/*  * mBIT(loc) - set bit at offset  */
end_comment

begin_define
define|#
directive|define
name|mBIT
parameter_list|(
name|loc
parameter_list|)
value|(0x8000000000000000ULL>> (loc))
end_define

begin_comment
comment|/*  * vBIT(val, loc, sz) - set bits at offset  */
end_comment

begin_define
define|#
directive|define
name|vBIT
parameter_list|(
name|val
parameter_list|,
name|loc
parameter_list|,
name|sz
parameter_list|)
value|(((u64)(val))<< (64-(loc)-(sz)))
end_define

begin_define
define|#
directive|define
name|vBIT32
parameter_list|(
name|val
parameter_list|,
name|loc
parameter_list|,
name|sz
parameter_list|)
value|(((u32)(val))<< (32-(loc)-(sz)))
end_define

begin_comment
comment|/*  * bVALx(bits, loc) - Get the value of x bits at location  */
end_comment

begin_define
define|#
directive|define
name|bVAL1
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+1)))& 0x1)
end_define

begin_define
define|#
directive|define
name|bVAL2
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+2)))& 0x3)
end_define

begin_define
define|#
directive|define
name|bVAL3
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+3)))& 0x7)
end_define

begin_define
define|#
directive|define
name|bVAL4
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+4)))& 0xF)
end_define

begin_define
define|#
directive|define
name|bVAL5
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+5)))& 0x1F)
end_define

begin_define
define|#
directive|define
name|bVAL6
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+6)))& 0x3F)
end_define

begin_define
define|#
directive|define
name|bVAL7
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+7)))& 0x7F)
end_define

begin_define
define|#
directive|define
name|bVAL8
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+8)))& 0xFF)
end_define

begin_define
define|#
directive|define
name|bVAL9
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+9)))& 0x1FF)
end_define

begin_define
define|#
directive|define
name|bVAL11
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+11)))& 0x7FF)
end_define

begin_define
define|#
directive|define
name|bVAL12
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+12)))& 0xFFF)
end_define

begin_define
define|#
directive|define
name|bVAL14
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+14)))& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|bVAL15
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+15)))& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|bVAL16
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+16)))& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|bVAL17
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+17)))& 0x1FFFF)
end_define

begin_define
define|#
directive|define
name|bVAL18
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+18)))& 0x3FFFF)
end_define

begin_define
define|#
directive|define
name|bVAL20
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+20)))& 0xFFFFF)
end_define

begin_define
define|#
directive|define
name|bVAL22
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+22)))& 0x3FFFFF)
end_define

begin_define
define|#
directive|define
name|bVAL24
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+24)))& 0xFFFFFF)
end_define

begin_define
define|#
directive|define
name|bVAL28
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+28)))& 0xFFFFFFF)
end_define

begin_define
define|#
directive|define
name|bVAL32
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+32)))& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|bVAL36
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+36)))& 0xFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|bVAL40
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+40)))& 0xFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|bVAL44
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+44)))& 0xFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|bVAL48
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+48)))& 0xFFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|bVAL52
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+52)))& 0xFFFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|bVAL56
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
value|((((u64)bits)>> (64-(loc+56)))& 0xFFFFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|bVAL60
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
define|\
value|((((u64)bits)>> (64-(loc+60)))& 0xFFFFFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|bVAL61
parameter_list|(
name|bits
parameter_list|,
name|loc
parameter_list|)
define|\
value|((((u64)bits)>> (64-(loc+61)))& 0x1FFFFFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_VPATH_BMAP_START
value|47
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_VPATH_BMAP_END
value|63
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_ALL_FOXES
value|0xFFFFFFFFFFFFFFFFULL
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_INTR_MASK_ALL
value|0xFFFFFFFFFFFFFFFFULL
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAX_VIRTUAL_PATHS
value|17
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAX_FUNCTIONS
value|8
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAX_ITABLE_ENTRIES
value|256
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAX_RSS_KEY_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAC_MAX_WIRE_PORTS
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAC_SWITCH_PORT
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAC_MAX_AGGR_PORTS
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAC_MAX_PORTS
value|3
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_INTR_ALARM
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_INTR_TX
value|(1<<(3-VXGE_HAL_VPATH_INTR_TX))
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_INTR_RX
value|(1<<(3-VXGE_HAL_VPATH_INTR_RX))
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_INTR_EINTA
value|(1<<(3-VXGE_HAL_VPATH_INTR_EINTA))
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_INTR_BMAP
value|(1<<(3-VXGE_HAL_VPATH_INTR_BMAP))
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_SPACE_SIZE
value|VXGE_OS_PCI_CONFIG_SIZE
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_DEFAULT_32
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_DEFAULT_64
value|0xffffffffffffffff
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_DUMP_BUF_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_VPD_BUFFER_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_VPD_LENGTH
value|80
end_define

begin_comment
comment|/* Check whether an address is multicast. */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_IS_NULL
parameter_list|(
name|Address
parameter_list|)
value|(Address == 0x0000000000000000ULL)
end_define

begin_comment
comment|/* Check whether an address is multicast. */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_IS_MULTICAST
parameter_list|(
name|Address
parameter_list|)
value|(Address& 0x0000010000000000ULL)
end_define

begin_comment
comment|/* Check whether an address is broadcast. */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_IS_BROADCAST
parameter_list|(
name|Address
parameter_list|)
define|\
value|((Address& 0x0000FFFF00000000ULL) == 0x0000FFFF00000000ULL)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_IS_UNICAST
parameter_list|(
name|Address
parameter_list|)
define|\
value|(!(VXGE_HAL_IS_NULL(Address) ||		\ 	VXGE_HAL_IS_MULTICAST(Address) ||	\ 	VXGE_HAL_IS_BROADCAST(Address)))
end_define

begin_comment
comment|/* frames sizes */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_ETHERNET_II_802_3_SIZE
value|14
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_802_2_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_SNAP_SIZE
value|5
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_VLAN_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAC_HEADER_MAX_SIZE
define|\
value|(VXGE_HAL_HEADER_ETHERNET_II_802_3_SIZE + \ 			VXGE_HAL_HEADER_802_2_SIZE + \ 			VXGE_HAL_HEADER_SNAP_SIZE)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_TCPIP_HEADER_MAX_SIZE
value|(64 + 64)
end_define

begin_comment
comment|/* 32bit alignments */
end_comment

begin_comment
comment|/* A receive data corruption can occur resulting in either a single-bit or double-bit ECC error being flagged in the ASIC if starting offset of a buffer in single buffer mode is 0x2 to 0xa. Single bit ECC error will not lock up the card but can hide the data corruption while the double-bit ECC error will lock up the card. Limiting the starting offset of the buffers to 0x0, 0x1 or to a value greater than 0xF will workaround this issue. VXGE_HAL_HEADER_ETHERNET_II_802_3_ALIGN of 2 causes the starting offset of buffer to be 0x2, 0x12 and so on, to have the start of the ip header dword aligned. The start of buffer of 0x2 will cause this problem to occur. To avoid this problem in all cases, add 0x10 to 0x2, to ensure that the start of buffer is outside of the problem causing offsets. */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_ETHERNET_II_802_3_ALIGN
value|0x12
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_802_2_SNAP_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_802_2_ALIGN
value|3
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_HEADER_SNAP_ALIGN
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MIN_MTU
value|46
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MAX_MTU
value|9600
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_DEFAULT_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_SEGEMENT_OFFLOAD_MAX_SIZE
value|81920
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__EXTERN_BEGIN_DECLS
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|__EXTERN_BEGIN_DECLS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__EXTERN_END_DECLS
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|__EXTERN_END_DECLS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__EXTERN_BEGIN_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|__EXTERN_END_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__EXTERN_BEGIN_DECLS
end_define

begin_define
define|#
directive|define
name|__EXTERN_END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__EXTERN_BEGIN_DECLS
comment|/* --------------------------- common stuffs ------------------------------ */
comment|/*  * VXGE_OS_DMA_REQUIRES_SYNC  - should be defined or  * NOT defined in the Makefile  */
define|#
directive|define
name|VXGE_OS_DMA_CACHELINE_ALIGNED
value|0x1
comment|/*  * Either STREAMING or CONSISTENT should be used.  * The combination of both or none is invalid  */
define|#
directive|define
name|VXGE_OS_DMA_STREAMING
value|0x2
define|#
directive|define
name|VXGE_OS_DMA_CONSISTENT
value|0x4
define|#
directive|define
name|VXGE_OS_SPRINTF_STRLEN
value|64
comment|/* --------------------------- common stuffs ------------------------------ */
ifndef|#
directive|ifndef
name|VXGE_OS_LLXFMT
define|#
directive|define
name|VXGE_OS_LLXFMT
value|"%llx"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|VXGE_OS_LLDFMT
define|#
directive|define
name|VXGE_OS_LLDFMT
value|"%lld"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|VXGE_OS_STXFMT
define|#
directive|define
name|VXGE_OS_STXFMT
value|"%zx"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|VXGE_OS_STDFMT
define|#
directive|define
name|VXGE_OS_STDFMT
value|"%zd"
endif|#
directive|endif
name|__EXTERN_END_DECLS
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_DEFS_H */
end_comment

end_unit

