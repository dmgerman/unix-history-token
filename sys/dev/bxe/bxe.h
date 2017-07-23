begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2014 QLogic Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BXE_H__
end_ifndef

begin_define
define|#
directive|define
name|__BXE_H__
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/bitstring.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/zlib.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_vlan_var.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_include
include|#
directive|include
file|"device_if.h"
end_include

begin_include
include|#
directive|include
file|"bus_if.h"
end_include

begin_include
include|#
directive|include
file|"pci_if.h"
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|BIG_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|__BIG_ENDIAN
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BIG_ENDIAN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|__BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LITTLE_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|__LITTLE_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ecore_mfw_req.h"
end_include

begin_include
include|#
directive|include
file|"ecore_fw_defs.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi.h"
end_include

begin_include
include|#
directive|include
file|"ecore_reg.h"
end_include

begin_include
include|#
directive|include
file|"bxe_dcb.h"
end_include

begin_include
include|#
directive|include
file|"bxe_stats.h"
end_include

begin_include
include|#
directive|include
file|"bxe_elink.h"
end_include

begin_define
define|#
directive|define
name|VF_MAC_CREDIT_CNT
value|0
end_define

begin_define
define|#
directive|define
name|VF_VLAN_CREDIT_CNT
value|(0)
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|800054
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__asm volatile("mfence;" : : : "memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__asm volatile("sfence;" : : : "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__asm volatile("lfence;" : : : "memory")
end_define

begin_function
specifier|static
name|__inline
name|void
name|prefetch
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
asm|__asm volatile("prefetcht0 %0" :: "m" (*(unsigned long *)x));
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|prefetch
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1000000
end_if

begin_define
define|#
directive|define
name|PCIR_EXPRESS_DEVICE_STA
value|PCIER_DEVICE_STA
end_define

begin_define
define|#
directive|define
name|PCIM_EXP_STA_TRANSACTION_PND
value|PCIEM_STA_TRANSACTION_PND
end_define

begin_define
define|#
directive|define
name|PCIR_EXPRESS_LINK_STA
value|PCIER_LINK_STA
end_define

begin_define
define|#
directive|define
name|PCIM_LINK_STA_WIDTH
value|PCIEM_LINK_STA_WIDTH
end_define

begin_define
define|#
directive|define
name|PCIM_LINK_STA_SPEED
value|PCIEM_LINK_STA_SPEED
end_define

begin_define
define|#
directive|define
name|PCIR_EXPRESS_DEVICE_CTL
value|PCIER_DEVICE_CTL
end_define

begin_define
define|#
directive|define
name|PCIM_EXP_CTL_MAX_PAYLOAD
value|PCIEM_CTL_MAX_PAYLOAD
end_define

begin_define
define|#
directive|define
name|PCIM_EXP_CTL_MAX_READ_REQUEST
value|PCIEM_CTL_MAX_READ_REQUEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARRAY_SIZE
end_ifndef

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof((arr)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARRSIZE
end_ifndef

begin_define
define|#
directive|define
name|ARRSIZE
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof((arr)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DIV_ROUND_UP
end_ifndef

begin_define
define|#
directive|define
name|DIV_ROUND_UP
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
value|(((n) + (d) - 1) / (d))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|roundup
end_ifndef

begin_define
define|#
directive|define
name|roundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x) + ((y) - 1)) / (y)) * (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ilog2
end_ifndef

begin_function
specifier|static
specifier|inline
name|int
name|bxe_ilog2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|log
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|x
operator|>>=
literal|1
condition|)
name|log
operator|++
expr_stmt|;
return|return
operator|(
name|log
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ilog2
parameter_list|(
name|x
parameter_list|)
value|bxe_ilog2(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ecore_sp.h"
end_include

begin_define
define|#
directive|define
name|BRCM_VENDORID
value|0x14e4
end_define

begin_define
define|#
directive|define
name|QLOGIC_VENDORID
value|0x1077
end_define

begin_define
define|#
directive|define
name|PCI_ANY_ID
value|(uint16_t)(~0U)
end_define

begin_struct
struct|struct
name|bxe_device_type
block|{
name|uint16_t
name|bxe_vid
decl_stmt|;
name|uint16_t
name|bxe_did
decl_stmt|;
name|uint16_t
name|bxe_svid
decl_stmt|;
name|uint16_t
name|bxe_sdid
decl_stmt|;
name|char
modifier|*
name|bxe_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BCM_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BCM_PAGE_SIZE
value|(1<< BCM_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|BCM_PAGE_MASK
value|(~(BCM_PAGE_SIZE - 1))
end_define

begin_define
define|#
directive|define
name|BCM_PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|((addr + BCM_PAGE_SIZE - 1)& BCM_PAGE_MASK)
end_define

begin_if
if|#
directive|if
name|BCM_PAGE_SIZE
operator|!=
literal|4096
end_if

begin_error
error|#
directive|error
error|Page sizes other than 4KB are unsupported!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|BUS_SPACE_MAXADDR
operator|>
literal|0xFFFFFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|U64_LO
parameter_list|(
name|addr
parameter_list|)
value|((uint32_t)(((uint64_t)(addr))& 0xFFFFFFFF))
end_define

begin_define
define|#
directive|define
name|U64_HI
parameter_list|(
name|addr
parameter_list|)
value|((uint32_t)(((uint64_t)(addr))>> 32))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|U64_LO
parameter_list|(
name|addr
parameter_list|)
value|((uint32_t)(addr))
end_define

begin_define
define|#
directive|define
name|U64_HI
parameter_list|(
name|addr
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HILO_U64
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
value|((((uint64_t)(hi))<< 32) + (lo))
end_define

begin_define
define|#
directive|define
name|SET_FLAG
parameter_list|(
name|value
parameter_list|,
name|mask
parameter_list|,
name|flag
parameter_list|)
define|\
value|do {                                       \         (value)&= ~(mask);                    \         (value) |= ((flag)<< (mask##_SHIFT)); \     } while (0)
end_define

begin_define
define|#
directive|define
name|GET_FLAG
parameter_list|(
name|value
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((value)& (mask))>> (mask##_SHIFT))
end_define

begin_define
define|#
directive|define
name|GET_FIELD
parameter_list|(
name|value
parameter_list|,
name|fname
parameter_list|)
define|\
value|(((value)& (fname##_MASK))>> (fname##_SHIFT))
end_define

begin_define
define|#
directive|define
name|BXE_MAX_SEGMENTS
value|12
end_define

begin_comment
comment|/* 13-1 for parsing buffer */
end_comment

begin_define
define|#
directive|define
name|BXE_TSO_MAX_SEGMENTS
value|32
end_define

begin_define
define|#
directive|define
name|BXE_TSO_MAX_SIZE
value|(65535 + sizeof(struct ether_vlan_header))
end_define

begin_define
define|#
directive|define
name|BXE_TSO_MAX_SEG_SIZE
value|4096
end_define

begin_comment
comment|/* dropless fc FW/HW related params */
end_comment

begin_define
define|#
directive|define
name|BRB_SIZE
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E3(sc) ? 1024 : 512)
end_define

begin_define
define|#
directive|define
name|MAX_AGG_QS
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E1(sc) ?                       \                                   ETH_MAX_AGGREGATION_QUEUES_E1 :    \                                   ETH_MAX_AGGREGATION_QUEUES_E1H_E2)
end_define

begin_define
define|#
directive|define
name|FW_DROP_LEVEL
parameter_list|(
name|sc
parameter_list|)
value|(3 + MAX_SPQ_PENDING + MAX_AGG_QS(sc))
end_define

begin_define
define|#
directive|define
name|FW_PREFETCH_CNT
value|16
end_define

begin_define
define|#
directive|define
name|DROPLESS_FC_HEADROOM
value|100
end_define

begin_comment
comment|/******************/
end_comment

begin_comment
comment|/* RX SGE defines */
end_comment

begin_comment
comment|/******************/
end_comment

begin_define
define|#
directive|define
name|RX_SGE_NUM_PAGES
value|2
end_define

begin_comment
comment|/* must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|RX_SGE_TOTAL_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(struct eth_rx_sge))
end_define

begin_define
define|#
directive|define
name|RX_SGE_NEXT_PAGE_DESC_CNT
value|2
end_define

begin_define
define|#
directive|define
name|RX_SGE_USABLE_PER_PAGE
value|(RX_SGE_TOTAL_PER_PAGE - RX_SGE_NEXT_PAGE_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|RX_SGE_PER_PAGE_MASK
value|(RX_SGE_TOTAL_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|RX_SGE_TOTAL
value|(RX_SGE_TOTAL_PER_PAGE * RX_SGE_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|RX_SGE_USABLE
value|(RX_SGE_USABLE_PER_PAGE * RX_SGE_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|RX_SGE_MAX
value|(RX_SGE_TOTAL - 1)
end_define

begin_define
define|#
directive|define
name|RX_SGE
parameter_list|(
name|x
parameter_list|)
value|((x)& RX_SGE_MAX)
end_define

begin_define
define|#
directive|define
name|RX_SGE_NEXT
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& RX_SGE_PER_PAGE_MASK) == (RX_SGE_USABLE_PER_PAGE - 1)) \      ? (x) + 1 + RX_SGE_NEXT_PAGE_DESC_CNT : (x) + 1)
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_SZ
value|64
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_MASK
value|((uint64_t)RX_SGE_MASK_ELEM_SZ - 1)
end_define

begin_comment
comment|/*  * Creates a bitmask of all ones in less significant bits.  * idx - index of the most significant bit in the created mask.  */
end_comment

begin_define
define|#
directive|define
name|RX_SGE_ONES_MASK
parameter_list|(
name|idx
parameter_list|)
define|\
value|(((uint64_t)0x1<< (((idx)& RX_SGE_MASK_ELEM_MASK) + 1)) - 1)
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_ELEM_ONE_MASK
value|((uint64_t)(~0))
end_define

begin_comment
comment|/* Number of uint64_t elements in SGE mask array. */
end_comment

begin_define
define|#
directive|define
name|RX_SGE_MASK_LEN
define|\
value|((RX_SGE_NUM_PAGES * RX_SGE_TOTAL_PER_PAGE) / RX_SGE_MASK_ELEM_SZ)
end_define

begin_define
define|#
directive|define
name|RX_SGE_MASK_LEN_MASK
value|(RX_SGE_MASK_LEN - 1)
end_define

begin_define
define|#
directive|define
name|RX_SGE_NEXT_MASK_ELEM
parameter_list|(
name|el
parameter_list|)
value|(((el) + 1)& RX_SGE_MASK_LEN_MASK)
end_define

begin_comment
comment|/*  * dropless fc calculations for SGEs  * Number of required SGEs is the sum of two:  * 1. Number of possible opened aggregations (next packet for  *    these aggregations will probably consume SGE immidiatelly)  * 2. Rest of BRB blocks divided by 2 (block will consume new SGE only  *    after placement on BD for new TPA aggregation)  * Takes into account RX_SGE_NEXT_PAGE_DESC_CNT "next" elements on each page  */
end_comment

begin_define
define|#
directive|define
name|NUM_SGE_REQ
parameter_list|(
name|sc
parameter_list|)
define|\
value|(MAX_AGG_QS(sc) + (BRB_SIZE(sc) - MAX_AGG_QS(sc)) / 2)
end_define

begin_define
define|#
directive|define
name|NUM_SGE_PG_REQ
parameter_list|(
name|sc
parameter_list|)
define|\
value|((NUM_SGE_REQ(sc) + RX_SGE_USABLE_PER_PAGE - 1) / RX_SGE_USABLE_PER_PAGE)
end_define

begin_define
define|#
directive|define
name|SGE_TH_LO
parameter_list|(
name|sc
parameter_list|)
define|\
value|(NUM_SGE_REQ(sc) + NUM_SGE_PG_REQ(sc) * RX_SGE_NEXT_PAGE_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|SGE_TH_HI
parameter_list|(
name|sc
parameter_list|)
define|\
value|(SGE_TH_LO(sc) + DROPLESS_FC_HEADROOM)
end_define

begin_define
define|#
directive|define
name|PAGES_PER_SGE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAGES_PER_SGE
value|(1<< PAGES_PER_SGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|SGE_PAGE_SIZE
value|BCM_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|SGE_PAGE_SHIFT
value|BCM_PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|SGE_PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|BCM_PAGE_ALIGN(addr)
end_define

begin_define
define|#
directive|define
name|SGE_PAGES
value|(SGE_PAGE_SIZE * PAGES_PER_SGE)
end_define

begin_define
define|#
directive|define
name|TPA_AGG_SIZE
value|min((8 * SGE_PAGES), 0xffff)
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* TX BD defines */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|TX_BD_NUM_PAGES
value|16
end_define

begin_comment
comment|/* must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|TX_BD_TOTAL_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(union eth_tx_bd_types))
end_define

begin_define
define|#
directive|define
name|TX_BD_USABLE_PER_PAGE
value|(TX_BD_TOTAL_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|TX_BD_TOTAL
value|(TX_BD_TOTAL_PER_PAGE * TX_BD_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|TX_BD_USABLE
value|(TX_BD_USABLE_PER_PAGE * TX_BD_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|TX_BD_MAX
value|(TX_BD_TOTAL - 1)
end_define

begin_define
define|#
directive|define
name|TX_BD_NEXT
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& TX_BD_USABLE_PER_PAGE) == (TX_BD_USABLE_PER_PAGE - 1)) ? \      ((x) + 2) : ((x) + 1))
end_define

begin_define
define|#
directive|define
name|TX_BD
parameter_list|(
name|x
parameter_list|)
value|((x)& TX_BD_MAX)
end_define

begin_define
define|#
directive|define
name|TX_BD_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~TX_BD_USABLE_PER_PAGE)>> 8)
end_define

begin_define
define|#
directive|define
name|TX_BD_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& TX_BD_USABLE_PER_PAGE)
end_define

begin_comment
comment|/*  * Trigger pending transmits when the number of available BDs is greater  * than 1/8 of the total number of usable BDs.  */
end_comment

begin_define
define|#
directive|define
name|BXE_TX_CLEANUP_THRESHOLD
value|(TX_BD_USABLE / 8)
end_define

begin_define
define|#
directive|define
name|BXE_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* RX BD defines */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|RX_BD_NUM_PAGES
value|8
end_define

begin_comment
comment|/* power of 2 */
end_comment

begin_define
define|#
directive|define
name|RX_BD_TOTAL_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(struct eth_rx_bd))
end_define

begin_define
define|#
directive|define
name|RX_BD_NEXT_PAGE_DESC_CNT
value|2
end_define

begin_define
define|#
directive|define
name|RX_BD_USABLE_PER_PAGE
value|(RX_BD_TOTAL_PER_PAGE - RX_BD_NEXT_PAGE_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|RX_BD_PER_PAGE_MASK
value|(RX_BD_TOTAL_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|RX_BD_TOTAL
value|(RX_BD_TOTAL_PER_PAGE * RX_BD_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|RX_BD_USABLE
value|(RX_BD_USABLE_PER_PAGE * RX_BD_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|RX_BD_MAX
value|(RX_BD_TOTAL - 1)
end_define

begin_define
define|#
directive|define
name|RX_BD_NEXT
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& RX_BD_PER_PAGE_MASK) == (RX_BD_USABLE_PER_PAGE - 1)) ? \      ((x) + 3) : ((x) + 1))
end_define

begin_define
define|#
directive|define
name|RX_BD
parameter_list|(
name|x
parameter_list|)
value|((x)& RX_BD_MAX)
end_define

begin_define
define|#
directive|define
name|RX_BD_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~RX_BD_PER_PAGE_MASK)>> 9)
end_define

begin_define
define|#
directive|define
name|RX_BD_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& RX_BD_PER_PAGE_MASK)
end_define

begin_comment
comment|/*  * dropless fc calculations for BDs  * Number of BDs should be as number of buffers in BRB:  * Low threshold takes into account RX_BD_NEXT_PAGE_DESC_CNT  * "next" elements on each page  */
end_comment

begin_define
define|#
directive|define
name|NUM_BD_REQ
parameter_list|(
name|sc
parameter_list|)
define|\
value|BRB_SIZE(sc)
end_define

begin_define
define|#
directive|define
name|NUM_BD_PG_REQ
parameter_list|(
name|sc
parameter_list|)
define|\
value|((NUM_BD_REQ(sc) + RX_BD_USABLE_PER_PAGE - 1) / RX_BD_USABLE_PER_PAGE)
end_define

begin_define
define|#
directive|define
name|BD_TH_LO
parameter_list|(
name|sc
parameter_list|)
define|\
value|(NUM_BD_REQ(sc) +                               \      NUM_BD_PG_REQ(sc) * RX_BD_NEXT_PAGE_DESC_CNT + \      FW_DROP_LEVEL(sc))
end_define

begin_define
define|#
directive|define
name|BD_TH_HI
parameter_list|(
name|sc
parameter_list|)
define|\
value|(BD_TH_LO(sc) + DROPLESS_FC_HEADROOM)
end_define

begin_define
define|#
directive|define
name|MIN_RX_AVAIL
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->dropless_fc ? BD_TH_HI(sc) + 128 : 128)
end_define

begin_define
define|#
directive|define
name|MIN_RX_SIZE_TPA_HW
parameter_list|(
name|sc
parameter_list|)
define|\
value|(CHIP_IS_E1(sc) ? ETH_MIN_RX_CQES_WITH_TPA_E1 :    \                       ETH_MIN_RX_CQES_WITH_TPA_E1H_E2)
end_define

begin_define
define|#
directive|define
name|MIN_RX_SIZE_NONTPA_HW
value|ETH_MIN_RX_CQES_WITHOUT_TPA
end_define

begin_define
define|#
directive|define
name|MIN_RX_SIZE_TPA
parameter_list|(
name|sc
parameter_list|)
define|\
value|(max(MIN_RX_SIZE_TPA_HW(sc), MIN_RX_AVAIL(sc)))
end_define

begin_define
define|#
directive|define
name|MIN_RX_SIZE_NONTPA
parameter_list|(
name|sc
parameter_list|)
define|\
value|(max(MIN_RX_SIZE_NONTPA_HW, MIN_RX_AVAIL(sc)))
end_define

begin_comment
comment|/***************/
end_comment

begin_comment
comment|/* RCQ defines */
end_comment

begin_comment
comment|/***************/
end_comment

begin_comment
comment|/*  * As long as CQE is X times bigger than BD entry we have to allocate X times  * more pages for CQ ring in order to keep it balanced with BD ring  */
end_comment

begin_define
define|#
directive|define
name|CQE_BD_REL
value|(sizeof(union eth_rx_cqe) / \                              sizeof(struct eth_rx_bd))
end_define

begin_define
define|#
directive|define
name|RCQ_NUM_PAGES
value|(RX_BD_NUM_PAGES * CQE_BD_REL)
end_define

begin_comment
comment|/* power of 2 */
end_comment

begin_define
define|#
directive|define
name|RCQ_TOTAL_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(union eth_rx_cqe))
end_define

begin_define
define|#
directive|define
name|RCQ_NEXT_PAGE_DESC_CNT
value|1
end_define

begin_define
define|#
directive|define
name|RCQ_USABLE_PER_PAGE
value|(RCQ_TOTAL_PER_PAGE - RCQ_NEXT_PAGE_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|RCQ_TOTAL
value|(RCQ_TOTAL_PER_PAGE * RCQ_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|RCQ_USABLE
value|(RCQ_USABLE_PER_PAGE * RCQ_NUM_PAGES)
end_define

begin_define
define|#
directive|define
name|RCQ_MAX
value|(RCQ_TOTAL - 1)
end_define

begin_define
define|#
directive|define
name|RCQ_NEXT
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& RCQ_USABLE_PER_PAGE) == (RCQ_USABLE_PER_PAGE - 1)) ? \      ((x) + 1 + RCQ_NEXT_PAGE_DESC_CNT) : ((x) + 1))
end_define

begin_define
define|#
directive|define
name|RCQ
parameter_list|(
name|x
parameter_list|)
value|((x)& RCQ_MAX)
end_define

begin_define
define|#
directive|define
name|RCQ_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~RCQ_USABLE_PER_PAGE)>> 7)
end_define

begin_define
define|#
directive|define
name|RCQ_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& RCQ_USABLE_PER_PAGE)
end_define

begin_comment
comment|/*  * dropless fc calculations for RCQs  * Number of RCQs should be as number of buffers in BRB:  * Low threshold takes into account RCQ_NEXT_PAGE_DESC_CNT  * "next" elements on each page  */
end_comment

begin_define
define|#
directive|define
name|NUM_RCQ_REQ
parameter_list|(
name|sc
parameter_list|)
define|\
value|BRB_SIZE(sc)
end_define

begin_define
define|#
directive|define
name|NUM_RCQ_PG_REQ
parameter_list|(
name|sc
parameter_list|)
define|\
value|((NUM_RCQ_REQ(sc) + RCQ_USABLE_PER_PAGE - 1) / RCQ_USABLE_PER_PAGE)
end_define

begin_define
define|#
directive|define
name|RCQ_TH_LO
parameter_list|(
name|sc
parameter_list|)
define|\
value|(NUM_RCQ_REQ(sc) +                             \      NUM_RCQ_PG_REQ(sc) * RCQ_NEXT_PAGE_DESC_CNT + \      FW_DROP_LEVEL(sc))
end_define

begin_define
define|#
directive|define
name|RCQ_TH_HI
parameter_list|(
name|sc
parameter_list|)
define|\
value|(RCQ_TH_LO(sc) + DROPLESS_FC_HEADROOM)
end_define

begin_comment
comment|/* This is needed for determening of last_max */
end_comment

begin_define
define|#
directive|define
name|SUB_S16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(int16_t)((int16_t)(a) - (int16_t)(b))
end_define

begin_define
define|#
directive|define
name|__SGE_MASK_SET_BIT
parameter_list|(
name|el
parameter_list|,
name|bit
parameter_list|)
define|\
value|do {                                          \         (el) = ((el) | ((uint64_t)0x1<< (bit))); \     } while (0)
end_define

begin_define
define|#
directive|define
name|__SGE_MASK_CLEAR_BIT
parameter_list|(
name|el
parameter_list|,
name|bit
parameter_list|)
define|\
value|do {                                             \         (el) = ((el)& (~((uint64_t)0x1<< (bit)))); \     } while (0)
end_define

begin_define
define|#
directive|define
name|SGE_MASK_SET_BIT
parameter_list|(
name|fp
parameter_list|,
name|idx
parameter_list|)
define|\
value|__SGE_MASK_SET_BIT((fp)->sge_mask[(idx)>> RX_SGE_MASK_ELEM_SHIFT], \                        ((idx)& RX_SGE_MASK_ELEM_MASK))
end_define

begin_define
define|#
directive|define
name|SGE_MASK_CLEAR_BIT
parameter_list|(
name|fp
parameter_list|,
name|idx
parameter_list|)
define|\
value|__SGE_MASK_CLEAR_BIT((fp)->sge_mask[(idx)>> RX_SGE_MASK_ELEM_SHIFT], \                          ((idx)& RX_SGE_MASK_ELEM_MASK))
end_define

begin_comment
comment|/* Load / Unload modes */
end_comment

begin_define
define|#
directive|define
name|LOAD_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|LOAD_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|LOAD_DIAG
value|2
end_define

begin_define
define|#
directive|define
name|LOAD_LOOPBACK_EXT
value|3
end_define

begin_define
define|#
directive|define
name|UNLOAD_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|UNLOAD_CLOSE
value|1
end_define

begin_define
define|#
directive|define
name|UNLOAD_RECOVERY
value|2
end_define

begin_comment
comment|/* Some constants... */
end_comment

begin_comment
comment|//#define MAX_PATH_NUM       2
end_comment

begin_comment
comment|//#define E2_MAX_NUM_OF_VFS  64
end_comment

begin_comment
comment|//#define E1H_FUNC_MAX       8
end_comment

begin_comment
comment|//#define E2_FUNC_MAX        4   /* per path */
end_comment

begin_define
define|#
directive|define
name|MAX_VNIC_NUM
value|4
end_define

begin_define
define|#
directive|define
name|MAX_FUNC_NUM
value|8
end_define

begin_comment
comment|/* common to all chips */
end_comment

begin_comment
comment|//#define MAX_NDSB           HC_SB_MAX_SB_E2 /* max non-default status block */
end_comment

begin_define
define|#
directive|define
name|MAX_RSS_CHAINS
value|16
end_define

begin_comment
comment|/* a constant for HW limit */
end_comment

begin_define
define|#
directive|define
name|MAX_MSI_VECTOR
value|8
end_define

begin_comment
comment|/* a constant for HW limit */
end_comment

begin_define
define|#
directive|define
name|ILT_NUM_PAGE_ENTRIES
value|3072
end_define

begin_comment
comment|/*  * 57710/11 we use whole table since we have 8 functions.  * 57712 we have only 4 functions, but use same size per func, so only half  * of the table is used.  */
end_comment

begin_define
define|#
directive|define
name|ILT_PER_FUNC
value|(ILT_NUM_PAGE_ENTRIES / 8)
end_define

begin_define
define|#
directive|define
name|FUNC_ILT_BASE
parameter_list|(
name|func
parameter_list|)
value|(func * ILT_PER_FUNC)
end_define

begin_comment
comment|/*  * the phys address is shifted right 12 bits and has an added  * 1=valid bit added to the 53rd bit  * then since this is a wide register(TM)  * we split it into two 32 bit writes  */
end_comment

begin_define
define|#
directive|define
name|ONCHIP_ADDR1
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(((uint64_t)x>> 12)& 0xFFFFFFFF))
end_define

begin_define
define|#
directive|define
name|ONCHIP_ADDR2
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)((1<< 20) | ((uint64_t)x>> 44)))
end_define

begin_comment
comment|/* L2 header size + 2*VLANs (8 bytes) + LLC SNAP (8 bytes) */
end_comment

begin_define
define|#
directive|define
name|ETH_HLEN
value|14
end_define

begin_define
define|#
directive|define
name|ETH_OVERHEAD
value|(ETH_HLEN + 8 + 8)
end_define

begin_define
define|#
directive|define
name|ETH_MIN_PACKET_SIZE
value|60
end_define

begin_define
define|#
directive|define
name|ETH_MAX_PACKET_SIZE
value|ETHERMTU
end_define

begin_comment
comment|/* 1500 */
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_JUMBO_PACKET_SIZE
value|9600
end_define

begin_comment
comment|/* TCP with Timestamp Option (32) + IPv6 (40) */
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_TPA_HEADER_SIZE
value|72
end_define

begin_comment
comment|/* max supported alignment is 256 (8 shift) */
end_comment

begin_comment
comment|//#define BXE_RX_ALIGN_SHIFT ((CACHE_LINE_SHIFT< 8) ? CACHE_LINE_SHIFT : 8)
end_comment

begin_define
define|#
directive|define
name|BXE_RX_ALIGN_SHIFT
value|8
end_define

begin_comment
comment|/* FW uses 2 cache lines alignment for start packet and size  */
end_comment

begin_define
define|#
directive|define
name|BXE_FW_RX_ALIGN_START
value|(1<< BXE_RX_ALIGN_SHIFT)
end_define

begin_define
define|#
directive|define
name|BXE_FW_RX_ALIGN_END
value|(1<< BXE_RX_ALIGN_SHIFT)
end_define

begin_define
define|#
directive|define
name|BXE_PXP_DRAM_ALIGN
value|(BXE_RX_ALIGN_SHIFT - 5)
end_define

begin_comment
comment|/* XXX ??? */
end_comment

begin_struct
struct|struct
name|bxe_bar
block|{
name|struct
name|resource
modifier|*
name|resource
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|handle
decl_stmt|;
name|vm_offset_t
name|kva
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bxe_intr
block|{
name|struct
name|resource
modifier|*
name|resource
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Used to manage DMA allocations. */
end_comment

begin_struct
struct|struct
name|bxe_dma
block|{
name|struct
name|bxe_softc
modifier|*
name|sc
decl_stmt|;
name|bus_addr_t
name|paddr
decl_stmt|;
name|void
modifier|*
name|vaddr
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_dma_segment_t
name|seg
decl_stmt|;
name|bus_size_t
name|size
decl_stmt|;
name|int
name|nseg
decl_stmt|;
name|char
name|msg
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* attn group wiring */
end_comment

begin_define
define|#
directive|define
name|MAX_DYNAMIC_ATTN_GRPS
value|8
end_define

begin_struct
struct|struct
name|attn_route
block|{
name|uint32_t
name|sig
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iro
block|{
name|uint32_t
name|base
decl_stmt|;
name|uint16_t
name|m1
decl_stmt|;
name|uint16_t
name|m2
decl_stmt|;
name|uint16_t
name|m3
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|bxe_host_hc_status_block
block|{
comment|/* pointer to fp status block e2 */
name|struct
name|host_hc_status_block_e2
modifier|*
name|e2_sb
decl_stmt|;
comment|/* pointer to fp status block e1x */
name|struct
name|host_hc_status_block_e1x
modifier|*
name|e1x_sb
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|bxe_db_prod
block|{
name|struct
name|doorbell_set_prod
name|data
decl_stmt|;
name|uint32_t
name|raw
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|bxe_sw_tx_bd
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|bus_dmamap_t
name|m_map
decl_stmt|;
name|uint16_t
name|first_bd
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
comment|/* set on the first BD descriptor when there is a split BD */
define|#
directive|define
name|BXE_TSO_SPLIT_BD
value|(1<< 0)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bxe_sw_rx_bd
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|bus_dmamap_t
name|m_map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bxe_sw_tpa_info
block|{
name|struct
name|bxe_sw_rx_bd
name|bd
decl_stmt|;
name|bus_dma_segment_t
name|seg
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
define|#
directive|define
name|BXE_TPA_STATE_START
value|1
define|#
directive|define
name|BXE_TPA_STATE_STOP
value|2
name|uint8_t
name|placement_offset
decl_stmt|;
name|uint16_t
name|parsing_flags
decl_stmt|;
name|uint16_t
name|vlan_tag
decl_stmt|;
name|uint16_t
name|len_on_bd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the HSI fastpath data structure. There can be up to MAX_RSS_CHAIN  * instances of the fastpath structure when using multiple queues.  */
end_comment

begin_struct
struct|struct
name|bxe_fastpath
block|{
comment|/* pointer back to parent structure */
name|struct
name|bxe_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|mtx
name|tx_mtx
decl_stmt|;
name|char
name|tx_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|rx_mtx
decl_stmt|;
name|char
name|rx_mtx_name
index|[
literal|32
index|]
decl_stmt|;
define|#
directive|define
name|BXE_FP_TX_LOCK
parameter_list|(
name|fp
parameter_list|)
value|mtx_lock(&fp->tx_mtx)
define|#
directive|define
name|BXE_FP_TX_UNLOCK
parameter_list|(
name|fp
parameter_list|)
value|mtx_unlock(&fp->tx_mtx)
define|#
directive|define
name|BXE_FP_TX_LOCK_ASSERT
parameter_list|(
name|fp
parameter_list|)
value|mtx_assert(&fp->tx_mtx, MA_OWNED)
define|#
directive|define
name|BXE_FP_TX_TRYLOCK
parameter_list|(
name|fp
parameter_list|)
value|mtx_trylock(&fp->tx_mtx)
define|#
directive|define
name|BXE_FP_RX_LOCK
parameter_list|(
name|fp
parameter_list|)
value|mtx_lock(&fp->rx_mtx)
define|#
directive|define
name|BXE_FP_RX_UNLOCK
parameter_list|(
name|fp
parameter_list|)
value|mtx_unlock(&fp->rx_mtx)
define|#
directive|define
name|BXE_FP_RX_LOCK_ASSERT
parameter_list|(
name|fp
parameter_list|)
value|mtx_assert(&fp->rx_mtx, MA_OWNED)
comment|/* status block */
name|struct
name|bxe_dma
name|sb_dma
decl_stmt|;
name|union
name|bxe_host_hc_status_block
name|status_block
decl_stmt|;
comment|/* transmit chain (tx bds) */
name|struct
name|bxe_dma
name|tx_dma
decl_stmt|;
name|union
name|eth_tx_bd_types
modifier|*
name|tx_chain
decl_stmt|;
comment|/* receive chain (rx bds) */
name|struct
name|bxe_dma
name|rx_dma
decl_stmt|;
name|struct
name|eth_rx_bd
modifier|*
name|rx_chain
decl_stmt|;
comment|/* receive completion queue chain (rcq bds) */
name|struct
name|bxe_dma
name|rcq_dma
decl_stmt|;
name|union
name|eth_rx_cqe
modifier|*
name|rcq_chain
decl_stmt|;
comment|/* receive scatter/gather entry chain (for TPA) */
name|struct
name|bxe_dma
name|rx_sge_dma
decl_stmt|;
name|struct
name|eth_rx_sge
modifier|*
name|rx_sge_chain
decl_stmt|;
comment|/* tx mbufs */
name|bus_dma_tag_t
name|tx_mbuf_tag
decl_stmt|;
name|struct
name|bxe_sw_tx_bd
name|tx_mbuf_chain
index|[
name|TX_BD_TOTAL
index|]
decl_stmt|;
comment|/* rx mbufs */
name|bus_dma_tag_t
name|rx_mbuf_tag
decl_stmt|;
name|struct
name|bxe_sw_rx_bd
name|rx_mbuf_chain
index|[
name|RX_BD_TOTAL
index|]
decl_stmt|;
name|bus_dmamap_t
name|rx_mbuf_spare_map
decl_stmt|;
comment|/* rx sge mbufs */
name|bus_dma_tag_t
name|rx_sge_mbuf_tag
decl_stmt|;
name|struct
name|bxe_sw_rx_bd
name|rx_sge_mbuf_chain
index|[
name|RX_SGE_TOTAL
index|]
decl_stmt|;
name|bus_dmamap_t
name|rx_sge_mbuf_spare_map
decl_stmt|;
comment|/* rx tpa mbufs (use the larger size for TPA queue length) */
name|int
name|tpa_enable
decl_stmt|;
comment|/* disabled per fastpath upon error */
name|struct
name|bxe_sw_tpa_info
name|rx_tpa_info
index|[
name|ETH_MAX_AGGREGATION_QUEUES_E1H_E2
index|]
decl_stmt|;
name|bus_dmamap_t
name|rx_tpa_info_mbuf_spare_map
decl_stmt|;
name|uint64_t
name|rx_tpa_queue_used
decl_stmt|;
name|uint16_t
modifier|*
name|sb_index_values
decl_stmt|;
name|uint16_t
modifier|*
name|sb_running_index
decl_stmt|;
name|uint32_t
name|ustorm_rx_prods_offset
decl_stmt|;
name|uint8_t
name|igu_sb_id
decl_stmt|;
comment|/* status block number in HW */
name|uint8_t
name|fw_sb_id
decl_stmt|;
comment|/* status block number in FW */
name|uint32_t
name|rx_buf_size
decl_stmt|;
name|int
name|mbuf_alloc_size
decl_stmt|;
name|int
name|state
decl_stmt|;
define|#
directive|define
name|BXE_FP_STATE_CLOSED
value|0x01
define|#
directive|define
name|BXE_FP_STATE_IRQ
value|0x02
define|#
directive|define
name|BXE_FP_STATE_OPENING
value|0x04
define|#
directive|define
name|BXE_FP_STATE_OPEN
value|0x08
define|#
directive|define
name|BXE_FP_STATE_HALTING
value|0x10
define|#
directive|define
name|BXE_FP_STATE_HALTED
value|0x20
comment|/* reference back to this fastpath queue number */
name|uint8_t
name|index
decl_stmt|;
comment|/* this is also the 'cid' */
define|#
directive|define
name|FP_IDX
parameter_list|(
name|fp
parameter_list|)
value|(fp->index)
comment|/* interrupt taskqueue (fast) */
name|struct
name|task
name|tq_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
name|char
name|tq_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|task
name|tx_task
decl_stmt|;
name|struct
name|timeout_task
name|tx_timeout_task
decl_stmt|;
comment|/* ethernet client ID (each fastpath set of RX/TX/CQE is a client) */
name|uint8_t
name|cl_id
decl_stmt|;
define|#
directive|define
name|FP_CL_ID
parameter_list|(
name|fp
parameter_list|)
value|(fp->cl_id)
name|uint8_t
name|cl_qzone_id
decl_stmt|;
name|uint16_t
name|fp_hc_idx
decl_stmt|;
comment|/* driver copy of the receive buffer descriptor prod/cons indices */
name|uint16_t
name|rx_bd_prod
decl_stmt|;
name|uint16_t
name|rx_bd_cons
decl_stmt|;
comment|/* driver copy of the receive completion queue prod/cons indices */
name|uint16_t
name|rx_cq_prod
decl_stmt|;
name|uint16_t
name|rx_cq_cons
decl_stmt|;
name|union
name|bxe_db_prod
name|tx_db
decl_stmt|;
comment|/* Transmit packet producer index (used in eth_tx_bd). */
name|uint16_t
name|tx_pkt_prod
decl_stmt|;
name|uint16_t
name|tx_pkt_cons
decl_stmt|;
comment|/* Transmit buffer descriptor producer index. */
name|uint16_t
name|tx_bd_prod
decl_stmt|;
name|uint16_t
name|tx_bd_cons
decl_stmt|;
name|uint64_t
name|sge_mask
index|[
name|RX_SGE_MASK_LEN
index|]
decl_stmt|;
name|uint16_t
name|rx_sge_prod
decl_stmt|;
name|struct
name|tstorm_per_queue_stats
name|old_tclient
decl_stmt|;
name|struct
name|ustorm_per_queue_stats
name|old_uclient
decl_stmt|;
name|struct
name|xstorm_per_queue_stats
name|old_xclient
decl_stmt|;
name|struct
name|bxe_eth_q_stats
name|eth_q_stats
decl_stmt|;
name|struct
name|bxe_eth_q_stats_old
name|eth_q_stats_old
decl_stmt|;
comment|/* Pointer to the receive consumer in the status block */
name|uint16_t
modifier|*
name|rx_cq_cons_sb
decl_stmt|;
comment|/* Pointer to the transmit consumer in the status block */
name|uint16_t
modifier|*
name|tx_cons_sb
decl_stmt|;
comment|/* transmit timeout until chip reset */
name|int
name|watchdog_timer
decl_stmt|;
comment|/* Free/used buffer descriptor counters. */
comment|//uint16_t used_tx_bd;
comment|/* Last maximal completed SGE */
name|uint16_t
name|last_max_sge
decl_stmt|;
comment|//uint16_t rx_sge_free_idx;
comment|//uint8_t segs;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|800000
define|#
directive|define
name|BXE_BR_SIZE
value|4096
name|struct
name|buf_ring
modifier|*
name|tx_br
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* struct bxe_fastpath */
end_comment

begin_comment
comment|/* sriov XXX */
end_comment

begin_define
define|#
directive|define
name|BXE_MAX_NUM_OF_VFS
value|64
end_define

begin_define
define|#
directive|define
name|BXE_VF_CID_WND
value|0
end_define

begin_define
define|#
directive|define
name|BXE_CIDS_PER_VF
value|(1<< BXE_VF_CID_WND)
end_define

begin_define
define|#
directive|define
name|BXE_CLIENTS_PER_VF
value|1
end_define

begin_define
define|#
directive|define
name|BXE_FIRST_VF_CID
value|256
end_define

begin_define
define|#
directive|define
name|BXE_VF_CIDS
value|(BXE_MAX_NUM_OF_VFS * BXE_CIDS_PER_VF)
end_define

begin_define
define|#
directive|define
name|BXE_VF_ID_INVALID
value|0xFF
end_define

begin_define
define|#
directive|define
name|IS_SRIOV
parameter_list|(
name|sc
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|GET_NUM_VFS_PER_PATH
parameter_list|(
name|sc
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|GET_NUM_VFS_PER_PF
parameter_list|(
name|sc
parameter_list|)
value|0
end_define

begin_comment
comment|/* maximum number of fast-path interrupt contexts */
end_comment

begin_define
define|#
directive|define
name|FP_SB_MAX_E1x
value|16
end_define

begin_define
define|#
directive|define
name|FP_SB_MAX_E2
value|HC_SB_MAX_SB_E2
end_define

begin_union
union|union
name|cdu_context
block|{
name|struct
name|eth_context
name|eth
decl_stmt|;
name|char
name|pad
index|[
literal|1024
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* CDU host DB constants */
end_comment

begin_define
define|#
directive|define
name|CDU_ILT_PAGE_SZ_HW
value|2
end_define

begin_define
define|#
directive|define
name|CDU_ILT_PAGE_SZ
value|(8192<< CDU_ILT_PAGE_SZ_HW)
end_define

begin_comment
comment|/* 32K */
end_comment

begin_define
define|#
directive|define
name|ILT_PAGE_CIDS
value|(CDU_ILT_PAGE_SZ / sizeof(union cdu_context))
end_define

begin_define
define|#
directive|define
name|CNIC_ISCSI_CID_MAX
value|256
end_define

begin_define
define|#
directive|define
name|CNIC_FCOE_CID_MAX
value|2048
end_define

begin_define
define|#
directive|define
name|CNIC_CID_MAX
value|(CNIC_ISCSI_CID_MAX + CNIC_FCOE_CID_MAX)
end_define

begin_define
define|#
directive|define
name|CNIC_ILT_LINES
value|DIV_ROUND_UP(CNIC_CID_MAX, ILT_PAGE_CIDS)
end_define

begin_define
define|#
directive|define
name|QM_ILT_PAGE_SZ_HW
value|0
end_define

begin_define
define|#
directive|define
name|QM_ILT_PAGE_SZ
value|(4096<< QM_ILT_PAGE_SZ_HW)
end_define

begin_comment
comment|/* 4K */
end_comment

begin_define
define|#
directive|define
name|QM_CID_ROUND
value|1024
end_define

begin_comment
comment|/* TM (timers) host DB constants */
end_comment

begin_define
define|#
directive|define
name|TM_ILT_PAGE_SZ_HW
value|0
end_define

begin_define
define|#
directive|define
name|TM_ILT_PAGE_SZ
value|(4096<< TM_ILT_PAGE_SZ_HW)
end_define

begin_comment
comment|/* 4K */
end_comment

begin_comment
comment|/*#define TM_CONN_NUM        (CNIC_STARTING_CID+CNIC_ISCSI_CXT_MAX) */
end_comment

begin_define
define|#
directive|define
name|TM_CONN_NUM
value|1024
end_define

begin_define
define|#
directive|define
name|TM_ILT_SZ
value|(8 * TM_CONN_NUM)
end_define

begin_define
define|#
directive|define
name|TM_ILT_LINES
value|DIV_ROUND_UP(TM_ILT_SZ, TM_ILT_PAGE_SZ)
end_define

begin_comment
comment|/* SRC (Searcher) host DB constants */
end_comment

begin_define
define|#
directive|define
name|SRC_ILT_PAGE_SZ_HW
value|0
end_define

begin_define
define|#
directive|define
name|SRC_ILT_PAGE_SZ
value|(4096<< SRC_ILT_PAGE_SZ_HW)
end_define

begin_comment
comment|/* 4K */
end_comment

begin_define
define|#
directive|define
name|SRC_HASH_BITS
value|10
end_define

begin_define
define|#
directive|define
name|SRC_CONN_NUM
value|(1<< SRC_HASH_BITS)
end_define

begin_comment
comment|/* 1024 */
end_comment

begin_define
define|#
directive|define
name|SRC_ILT_SZ
value|(sizeof(struct src_ent) * SRC_CONN_NUM)
end_define

begin_define
define|#
directive|define
name|SRC_T2_SZ
value|SRC_ILT_SZ
end_define

begin_define
define|#
directive|define
name|SRC_ILT_LINES
value|DIV_ROUND_UP(SRC_ILT_SZ, SRC_ILT_PAGE_SZ)
end_define

begin_struct
struct|struct
name|hw_context
block|{
name|struct
name|bxe_dma
name|vcxt_dma
decl_stmt|;
name|union
name|cdu_context
modifier|*
name|vcxt
decl_stmt|;
comment|//bus_addr_t        cxt_mapping;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SM_RX_ID
value|0
end_define

begin_define
define|#
directive|define
name|SM_TX_ID
value|1
end_define

begin_comment
comment|/* defines for multiple tx priority indices */
end_comment

begin_define
define|#
directive|define
name|FIRST_TX_ONLY_COS_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|FIRST_TX_COS_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|CID_TO_FP
parameter_list|(
name|cid
parameter_list|,
name|sc
parameter_list|)
value|((cid) % BXE_NUM_NON_CNIC_QUEUES(sc))
end_define

begin_define
define|#
directive|define
name|HC_INDEX_ETH_RX_CQ_CONS
value|1
end_define

begin_define
define|#
directive|define
name|HC_INDEX_OOO_TX_CQ_CONS
value|4
end_define

begin_define
define|#
directive|define
name|HC_INDEX_ETH_TX_CQ_CONS_COS0
value|5
end_define

begin_define
define|#
directive|define
name|HC_INDEX_ETH_TX_CQ_CONS_COS1
value|6
end_define

begin_define
define|#
directive|define
name|HC_INDEX_ETH_TX_CQ_CONS_COS2
value|7
end_define

begin_define
define|#
directive|define
name|HC_INDEX_ETH_FIRST_TX_CQ_CONS
value|HC_INDEX_ETH_TX_CQ_CONS_COS0
end_define

begin_comment
comment|/* congestion management fairness mode */
end_comment

begin_define
define|#
directive|define
name|CMNG_FNS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CMNG_FNS_MINMAX
value|1
end_define

begin_comment
comment|/* CMNG constants, as derived from system spec calculations */
end_comment

begin_comment
comment|/* default MIN rate in case VNIC min rate is configured to zero - 100Mbps */
end_comment

begin_define
define|#
directive|define
name|DEF_MIN_RATE
value|100
end_define

begin_comment
comment|/* resolution of the rate shaping timer - 400 usec */
end_comment

begin_define
define|#
directive|define
name|RS_PERIODIC_TIMEOUT_USEC
value|400
end_define

begin_comment
comment|/* number of bytes in single QM arbitration cycle -  * coefficient for calculating the fairness timer */
end_comment

begin_define
define|#
directive|define
name|QM_ARB_BYTES
value|160000
end_define

begin_comment
comment|/* resolution of Min algorithm 1:100 */
end_comment

begin_define
define|#
directive|define
name|MIN_RES
value|100
end_define

begin_comment
comment|/* how many bytes above threshold for the minimal credit of Min algorithm*/
end_comment

begin_define
define|#
directive|define
name|MIN_ABOVE_THRESH
value|32768
end_define

begin_comment
comment|/* fairness algorithm integration time coefficient -  * for calculating the actual Tfair */
end_comment

begin_define
define|#
directive|define
name|T_FAIR_COEF
value|((MIN_ABOVE_THRESH + QM_ARB_BYTES) * 8 * MIN_RES)
end_define

begin_comment
comment|/* memory of fairness algorithm - 2 cycles */
end_comment

begin_define
define|#
directive|define
name|FAIR_MEM
value|2
end_define

begin_define
define|#
directive|define
name|HC_SEG_ACCESS_DEF
value|0
end_define

begin_comment
comment|/* Driver decision 0-3 */
end_comment

begin_define
define|#
directive|define
name|HC_SEG_ACCESS_ATTN
value|4
end_define

begin_define
define|#
directive|define
name|HC_SEG_ACCESS_NORM
value|0
end_define

begin_comment
comment|/* Driver decision 0-1 */
end_comment

begin_comment
comment|/*  * The total number of L2 queues, MSIX vectors and HW contexts (CIDs) is  * control by the number of fast-path status blocks supported by the  * device (HW/FW). Each fast-path status block (FP-SB) aka non-default  * status block represents an independent interrupts context that can  * serve a regular L2 networking queue. However special L2 queues such  * as the FCoE queue do not require a FP-SB and other components like  * the CNIC may consume FP-SB reducing the number of possible L2 queues  *  * If the maximum number of FP-SB available is X then:  * a. If CNIC is supported it consumes 1 FP-SB thus the max number of  *    regular L2 queues is Y=X-1  * b. in MF mode the actual number of L2 queues is Y= (X-1/MF_factor)  * c. If the FCoE L2 queue is supported the actual number of L2 queues  *    is Y+1  * d. The number of irqs (MSIX vectors) is either Y+1 (one extra for  *    slow-path interrupts) or Y+2 if CNIC is supported (one additional  *    FP interrupt context for the CNIC).  * e. The number of HW context (CID count) is always X or X+1 if FCoE  *    L2 queue is supported. the cid for the FCoE L2 queue is always X.  *  * So this is quite simple for now as no ULPs are supported yet. :-)  */
end_comment

begin_define
define|#
directive|define
name|BXE_NUM_QUEUES
parameter_list|(
name|sc
parameter_list|)
value|((sc)->num_queues)
end_define

begin_define
define|#
directive|define
name|BXE_NUM_ETH_QUEUES
parameter_list|(
name|sc
parameter_list|)
value|BXE_NUM_QUEUES(sc)
end_define

begin_define
define|#
directive|define
name|BXE_NUM_NON_CNIC_QUEUES
parameter_list|(
name|sc
parameter_list|)
value|BXE_NUM_QUEUES(sc)
end_define

begin_define
define|#
directive|define
name|BXE_NUM_RX_QUEUES
parameter_list|(
name|sc
parameter_list|)
value|BXE_NUM_QUEUES(sc)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) = 0; (var)< BXE_NUM_QUEUES(sc); (var)++)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_NONDEFAULT_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) = 1; (var)< BXE_NUM_QUEUES(sc); (var)++)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_ETH_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) = 0; (var)< BXE_NUM_ETH_QUEUES(sc); (var)++)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_NONDEFAULT_ETH_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) = 1; (var)< BXE_NUM_ETH_QUEUES(sc); (var)++)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_COS_IN_TX_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) = 0; (var)< (sc)->max_cos; (var)++)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_CNIC_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) = BXE_NUM_ETH_QUEUES(sc); \          (var)< BXE_NUM_QUEUES(sc);     \          (var)++)
end_define

begin_enum
enum|enum
block|{
name|OOO_IDX_OFFSET
block|,
name|FCOE_IDX_OFFSET
block|,
name|FWD_IDX_OFFSET
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|FCOE_IDX
parameter_list|(
name|sc
parameter_list|)
value|(BXE_NUM_NON_CNIC_QUEUES(sc) + FCOE_IDX_OFFSET)
end_define

begin_define
define|#
directive|define
name|bxe_fcoe_fp
parameter_list|(
name|sc
parameter_list|)
value|(&sc->fp[FCOE_IDX(sc)])
end_define

begin_define
define|#
directive|define
name|bxe_fcoe
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(bxe_fcoe_fp(sc)->var)
end_define

begin_define
define|#
directive|define
name|bxe_fcoe_inner_sp_obj
parameter_list|(
name|sc
parameter_list|)
value|(&sc->sp_objs[FCOE_IDX(sc)])
end_define

begin_define
define|#
directive|define
name|bxe_fcoe_sp_obj
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(bxe_fcoe_inner_sp_obj(sc)->var)
end_define

begin_define
define|#
directive|define
name|bxe_fcoe_tx
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(bxe_fcoe_fp(sc)->txdata_ptr[FIRST_TX_COS_INDEX]->var)
end_define

begin_define
define|#
directive|define
name|OOO_IDX
parameter_list|(
name|sc
parameter_list|)
value|(BXE_NUM_NON_CNIC_QUEUES(sc) + OOO_IDX_OFFSET)
end_define

begin_define
define|#
directive|define
name|bxe_ooo_fp
parameter_list|(
name|sc
parameter_list|)
value|(&sc->fp[OOO_IDX(sc)])
end_define

begin_define
define|#
directive|define
name|bxe_ooo
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(bxe_ooo_fp(sc)->var)
end_define

begin_define
define|#
directive|define
name|bxe_ooo_inner_sp_obj
parameter_list|(
name|sc
parameter_list|)
value|(&sc->sp_objs[OOO_IDX(sc)])
end_define

begin_define
define|#
directive|define
name|bxe_ooo_sp_obj
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(bxe_ooo_inner_sp_obj(sc)->var)
end_define

begin_define
define|#
directive|define
name|FWD_IDX
parameter_list|(
name|sc
parameter_list|)
value|(BXE_NUM_NON_CNIC_QUEUES(sc) + FWD_IDX_OFFSET)
end_define

begin_define
define|#
directive|define
name|bxe_fwd_fp
parameter_list|(
name|sc
parameter_list|)
value|(&sc->fp[FWD_IDX(sc)])
end_define

begin_define
define|#
directive|define
name|bxe_fwd
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(bxe_fwd_fp(sc)->var)
end_define

begin_define
define|#
directive|define
name|bxe_fwd_inner_sp_obj
parameter_list|(
name|sc
parameter_list|)
value|(&sc->sp_objs[FWD_IDX(sc)])
end_define

begin_define
define|#
directive|define
name|bxe_fwd_sp_obj
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(bxe_fwd_inner_sp_obj(sc)->var)
end_define

begin_define
define|#
directive|define
name|bxe_fwd_txdata
parameter_list|(
name|fp
parameter_list|)
value|(fp->txdata_ptr[FIRST_TX_COS_INDEX])
end_define

begin_define
define|#
directive|define
name|IS_ETH_FP
parameter_list|(
name|fp
parameter_list|)
value|((fp)->index< BXE_NUM_ETH_QUEUES((fp)->sc))
end_define

begin_define
define|#
directive|define
name|IS_FCOE_FP
parameter_list|(
name|fp
parameter_list|)
value|((fp)->index == FCOE_IDX((fp)->sc))
end_define

begin_define
define|#
directive|define
name|IS_FCOE_IDX
parameter_list|(
name|idx
parameter_list|)
value|((idx) == FCOE_IDX(sc))
end_define

begin_define
define|#
directive|define
name|IS_FWD_FP
parameter_list|(
name|fp
parameter_list|)
value|((fp)->index == FWD_IDX((fp)->sc))
end_define

begin_define
define|#
directive|define
name|IS_FWD_IDX
parameter_list|(
name|idx
parameter_list|)
value|((idx) == FWD_IDX(sc))
end_define

begin_define
define|#
directive|define
name|IS_OOO_FP
parameter_list|(
name|fp
parameter_list|)
value|((fp)->index == OOO_IDX((fp)->sc))
end_define

begin_define
define|#
directive|define
name|IS_OOO_IDX
parameter_list|(
name|idx
parameter_list|)
value|((idx) == OOO_IDX(sc))
end_define

begin_enum
enum|enum
block|{
name|BXE_PORT_QUERY_IDX
block|,
name|BXE_PF_QUERY_IDX
block|,
name|BXE_FCOE_QUERY_IDX
block|,
name|BXE_FIRST_QUEUE_QUERY_IDX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|bxe_fw_stats_req
block|{
name|struct
name|stats_query_header
name|hdr
decl_stmt|;
name|struct
name|stats_query_entry
name|query
index|[
name|FP_SB_MAX_E1x
operator|+
name|BXE_FIRST_QUEUE_QUERY_IDX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bxe_fw_stats_data
block|{
name|struct
name|stats_counter
name|storm_counters
decl_stmt|;
name|struct
name|per_port_stats
name|port
decl_stmt|;
name|struct
name|per_pf_stats
name|pf
decl_stmt|;
comment|//struct fcoe_statistics_params fcoe;
name|struct
name|per_queue_stats
name|queue_stats
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* IGU MSIX STATISTICS on 57712: 64 for VFs; 4 for PFs; 4 for Attentions */
end_comment

begin_define
define|#
directive|define
name|BXE_IGU_STAS_MSG_VF_CNT
value|64
end_define

begin_define
define|#
directive|define
name|BXE_IGU_STAS_MSG_PF_CNT
value|4
end_define

begin_define
define|#
directive|define
name|MAX_DMAE_C
value|8
end_define

begin_comment
comment|/*  * For the main interface up/down code paths, a not-so-fine-grained CORE  * mutex lock is used. Inside this code are various calls to kernel routines  * that can cause a sleep to occur. Namely memory allocations and taskqueue  * handling. If using an MTX lock we are *not* allowed to sleep but we can  * with an SX lock. This define forces the CORE lock to use and SX lock.  * Undefine this and an MTX lock will be used instead. Note that the IOCTL  * path can cause problems since it's called by a non-sleepable thread. To  * alleviate a potential sleep, any IOCTL processing that results in the  * chip/interface being started/stopped/reinitialized, the actual work is  * offloaded to a taskqueue.  */
end_comment

begin_define
define|#
directive|define
name|BXE_CORE_LOCK_SX
end_define

begin_comment
comment|/*  * This is the slowpath data structure. It is mapped into non-paged memory  * so that the hardware can access it's contents directly and must be page  * aligned.  */
end_comment

begin_struct
struct|struct
name|bxe_slowpath
block|{
comment|/* used by the DMAE command executer */
name|struct
name|dmae_cmd
name|dmae
index|[
name|MAX_DMAE_C
index|]
decl_stmt|;
comment|/* statistics completion */
name|uint32_t
name|stats_comp
decl_stmt|;
comment|/* firmware defined statistics blocks */
name|union
name|mac_stats
name|mac_stats
decl_stmt|;
name|struct
name|nig_stats
name|nig_stats
decl_stmt|;
name|struct
name|host_port_stats
name|port_stats
decl_stmt|;
name|struct
name|host_func_stats
name|func_stats
decl_stmt|;
comment|//struct host_func_stats func_stats_base;
comment|/* DMAE completion value and data source/sink */
name|uint32_t
name|wb_comp
decl_stmt|;
name|uint32_t
name|wb_data
index|[
literal|4
index|]
decl_stmt|;
union|union
block|{
name|struct
name|mac_configuration_cmd
name|e1x
decl_stmt|;
name|struct
name|eth_classify_rules_ramrod_data
name|e2
decl_stmt|;
block|}
name|mac_rdata
union|;
union|union
block|{
name|struct
name|tstorm_eth_mac_filter_config
name|e1x
decl_stmt|;
name|struct
name|eth_filter_rules_ramrod_data
name|e2
decl_stmt|;
block|}
name|rx_mode_rdata
union|;
name|struct
name|eth_rss_update_ramrod_data
name|rss_rdata
decl_stmt|;
union|union
block|{
name|struct
name|mac_configuration_cmd
name|e1
decl_stmt|;
name|struct
name|eth_multicast_rules_ramrod_data
name|e2
decl_stmt|;
block|}
name|mcast_rdata
union|;
union|union
block|{
name|struct
name|function_start_data
name|func_start
decl_stmt|;
name|struct
name|flow_control_configuration
name|pfc_config
decl_stmt|;
comment|/* for DCBX ramrod */
block|}
name|func_rdata
union|;
comment|/* Queue State related ramrods */
union|union
block|{
name|struct
name|client_init_ramrod_data
name|init_data
decl_stmt|;
name|struct
name|client_update_ramrod_data
name|update_data
decl_stmt|;
block|}
name|q_rdata
union|;
comment|/*      * AFEX ramrod can not be a part of func_rdata union because these      * events might arrive in parallel to other events from func_rdata.      * If they were defined in the same union the data can get corrupted.      */
name|struct
name|afex_vif_list_ramrod_data
name|func_afex_rdata
decl_stmt|;
name|union
name|drv_info_to_mcp
name|drv_info_to_mcp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* struct bxe_slowpath */
end_comment

begin_comment
comment|/*  * Port specifc data structure.  */
end_comment

begin_struct
struct|struct
name|bxe_port
block|{
comment|/*      * Port Management Function (for 57711E only).      * When this field is set the driver instance is      * responsible for managing port specifc      * configurations such as handling link attentions.      */
name|uint32_t
name|pmf
decl_stmt|;
comment|/* Ethernet maximum transmission unit. */
name|uint16_t
name|ether_mtu
decl_stmt|;
name|uint32_t
name|link_config
index|[
name|ELINK_LINK_CONFIG_SIZE
index|]
decl_stmt|;
name|uint32_t
name|ext_phy_config
decl_stmt|;
comment|/* Port feature config.*/
name|uint32_t
name|config
decl_stmt|;
comment|/* Defines the features supported by the PHY. */
name|uint32_t
name|supported
index|[
name|ELINK_LINK_CONFIG_SIZE
index|]
decl_stmt|;
comment|/* Defines the features advertised by the PHY. */
name|uint32_t
name|advertising
index|[
name|ELINK_LINK_CONFIG_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|ADVERTISED_10baseT_Half
value|(1<< 1)
define|#
directive|define
name|ADVERTISED_10baseT_Full
value|(1<< 2)
define|#
directive|define
name|ADVERTISED_100baseT_Half
value|(1<< 3)
define|#
directive|define
name|ADVERTISED_100baseT_Full
value|(1<< 4)
define|#
directive|define
name|ADVERTISED_1000baseT_Half
value|(1<< 5)
define|#
directive|define
name|ADVERTISED_1000baseT_Full
value|(1<< 6)
define|#
directive|define
name|ADVERTISED_TP
value|(1<< 7)
define|#
directive|define
name|ADVERTISED_FIBRE
value|(1<< 8)
define|#
directive|define
name|ADVERTISED_Autoneg
value|(1<< 9)
define|#
directive|define
name|ADVERTISED_Asym_Pause
value|(1<< 10)
define|#
directive|define
name|ADVERTISED_Pause
value|(1<< 11)
define|#
directive|define
name|ADVERTISED_2500baseX_Full
value|(1<< 15)
define|#
directive|define
name|ADVERTISED_10000baseT_Full
value|(1<< 16)
name|uint32_t
name|phy_addr
decl_stmt|;
comment|/* Used to synchronize phy accesses. */
name|struct
name|mtx
name|phy_mtx
decl_stmt|;
name|char
name|phy_mtx_name
index|[
literal|32
index|]
decl_stmt|;
define|#
directive|define
name|BXE_PHY_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&sc->port.phy_mtx)
define|#
directive|define
name|BXE_PHY_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&sc->port.phy_mtx)
define|#
directive|define
name|BXE_PHY_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->port.phy_mtx, MA_OWNED)
comment|/*      * MCP scratchpad address for port specific statistics.      * The device is responsible for writing statistcss      * back to the MCP for use with management firmware such      * as UMP/NC-SI.      */
name|uint32_t
name|port_stx
decl_stmt|;
name|struct
name|nig_stats
name|old_nig_stats
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* struct bxe_port */
end_comment

begin_struct
struct|struct
name|bxe_mf_info
block|{
name|uint32_t
name|mf_config
index|[
name|E1HVN_MAX
index|]
decl_stmt|;
name|uint32_t
name|vnics_per_port
decl_stmt|;
comment|/* 1, 2 or 4 */
name|uint32_t
name|multi_vnics_mode
decl_stmt|;
comment|/* can be set even if vnics_per_port = 1 */
name|uint32_t
name|path_has_ovlan
decl_stmt|;
comment|/* MF mode in the path (can be different than the MF mode of the function */
define|#
directive|define
name|IS_MULTI_VNIC
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.multi_vnics_mode)
define|#
directive|define
name|VNICS_PER_PORT
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.vnics_per_port)
define|#
directive|define
name|VNICS_PER_PATH
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->devinfo.mf_info.vnics_per_port *                 \      ((CHIP_PORT_MODE(sc) == CHIP_4_PORT_MODE) ? 2 : 1 ))
name|uint8_t
name|min_bw
index|[
name|MAX_VNIC_NUM
index|]
decl_stmt|;
name|uint8_t
name|max_bw
index|[
name|MAX_VNIC_NUM
index|]
decl_stmt|;
name|uint16_t
name|ext_id
decl_stmt|;
comment|/* vnic outer vlan or VIF ID */
define|#
directive|define
name|VALID_OVLAN
parameter_list|(
name|ovlan
parameter_list|)
value|((ovlan)<= 4096)
define|#
directive|define
name|INVALID_VIF_ID
value|0xFFFF
define|#
directive|define
name|OVLAN
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.ext_id)
define|#
directive|define
name|VIF_ID
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.ext_id)
name|uint16_t
name|default_vlan
decl_stmt|;
define|#
directive|define
name|NIV_DEFAULT_VLAN
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.default_vlan)
name|uint8_t
name|niv_allowed_priorities
decl_stmt|;
define|#
directive|define
name|NIV_ALLOWED_PRIORITIES
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.niv_allowed_priorities)
name|uint8_t
name|niv_default_cos
decl_stmt|;
define|#
directive|define
name|NIV_DEFAULT_COS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.niv_default_cos)
name|uint8_t
name|niv_mba_enabled
decl_stmt|;
name|enum
name|mf_cfg_afex_vlan_mode
name|afex_vlan_mode
decl_stmt|;
define|#
directive|define
name|AFEX_VLAN_MODE
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.mf_info.afex_vlan_mode)
name|int
name|afex_def_vlan_tag
decl_stmt|;
name|uint32_t
name|pending_max
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|MF_INFO_VALID_MAC
value|0x0001
name|uint8_t
name|mf_mode
decl_stmt|;
comment|/* Switch-Dependent or Switch-Independent */
define|#
directive|define
name|IS_MF
parameter_list|(
name|sc
parameter_list|)
define|\
value|(IS_MULTI_VNIC(sc)&&                \      ((sc)->devinfo.mf_info.mf_mode != 0))
define|#
directive|define
name|IS_MF_SD
parameter_list|(
name|sc
parameter_list|)
define|\
value|(IS_MULTI_VNIC(sc)&&                                \      ((sc)->devinfo.mf_info.mf_mode == MULTI_FUNCTION_SD))
define|#
directive|define
name|IS_MF_SI
parameter_list|(
name|sc
parameter_list|)
define|\
value|(IS_MULTI_VNIC(sc)&&                                \      ((sc)->devinfo.mf_info.mf_mode == MULTI_FUNCTION_SI))
define|#
directive|define
name|IS_MF_AFEX
parameter_list|(
name|sc
parameter_list|)
define|\
value|(IS_MULTI_VNIC(sc)&&                           \      ((sc)->devinfo.mf_info.mf_mode == MULTI_FUNCTION_AFEX))
define|#
directive|define
name|IS_MF_SD_MODE
parameter_list|(
name|sc
parameter_list|)
value|IS_MF_SD(sc)
define|#
directive|define
name|IS_MF_SI_MODE
parameter_list|(
name|sc
parameter_list|)
value|IS_MF_SI(sc)
define|#
directive|define
name|IS_MF_AFEX_MODE
parameter_list|(
name|sc
parameter_list|)
value|IS_MF_AFEX(sc)
name|uint32_t
name|mf_protos_supported
decl_stmt|;
define|#
directive|define
name|MF_PROTO_SUPPORT_ETHERNET
value|0x1
define|#
directive|define
name|MF_PROTO_SUPPORT_ISCSI
value|0x2
define|#
directive|define
name|MF_PROTO_SUPPORT_FCOE
value|0x4
block|}
struct|;
end_struct

begin_comment
comment|/* struct bxe_mf_info */
end_comment

begin_comment
comment|/* Device information data structure. */
end_comment

begin_struct
struct|struct
name|bxe_devinfo
block|{
comment|/* PCIe info */
name|uint16_t
name|vendor_id
decl_stmt|;
name|uint16_t
name|device_id
decl_stmt|;
name|uint16_t
name|subvendor_id
decl_stmt|;
name|uint16_t
name|subdevice_id
decl_stmt|;
comment|/*      * chip_id = 0b'CCCCCCCCCCCCCCCCRRRRMMMMMMMMBBBB'      *   C = Chip Number   (bits 16-31)      *   R = Chip Revision (bits 12-15)      *   M = Chip Metal    (bits 4-11)      *   B = Chip Bond ID  (bits 0-3)      */
name|uint32_t
name|chip_id
decl_stmt|;
define|#
directive|define
name|CHIP_ID
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.chip_id& 0xffff0000)
define|#
directive|define
name|CHIP_NUM
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.chip_id>> 16)
comment|/* device ids */
define|#
directive|define
name|CHIP_NUM_57710
value|0x164e
define|#
directive|define
name|CHIP_NUM_57711
value|0x164f
define|#
directive|define
name|CHIP_NUM_57711E
value|0x1650
define|#
directive|define
name|CHIP_NUM_57712
value|0x1662
define|#
directive|define
name|CHIP_NUM_57712_MF
value|0x1663
define|#
directive|define
name|CHIP_NUM_57712_VF
value|0x166f
define|#
directive|define
name|CHIP_NUM_57800
value|0x168a
define|#
directive|define
name|CHIP_NUM_57800_MF
value|0x16a5
define|#
directive|define
name|CHIP_NUM_57800_VF
value|0x16a9
define|#
directive|define
name|CHIP_NUM_57810
value|0x168e
define|#
directive|define
name|CHIP_NUM_57810_MF
value|0x16ae
define|#
directive|define
name|CHIP_NUM_57810_VF
value|0x16af
define|#
directive|define
name|CHIP_NUM_57811
value|0x163d
define|#
directive|define
name|CHIP_NUM_57811_MF
value|0x163e
define|#
directive|define
name|CHIP_NUM_57811_VF
value|0x163f
define|#
directive|define
name|CHIP_NUM_57840_OBS
value|0x168d
define|#
directive|define
name|CHIP_NUM_57840_OBS_MF
value|0x16ab
define|#
directive|define
name|CHIP_NUM_57840_4_10
value|0x16a1
define|#
directive|define
name|CHIP_NUM_57840_2_20
value|0x16a2
define|#
directive|define
name|CHIP_NUM_57840_MF
value|0x16a4
define|#
directive|define
name|CHIP_NUM_57840_VF
value|0x16ad
define|#
directive|define
name|CHIP_REV_SHIFT
value|12
define|#
directive|define
name|CHIP_REV_MASK
value|(0xF<< CHIP_REV_SHIFT)
define|#
directive|define
name|CHIP_REV
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.chip_id& CHIP_REV_MASK)
define|#
directive|define
name|CHIP_REV_Ax
value|(0x0<< CHIP_REV_SHIFT)
define|#
directive|define
name|CHIP_REV_Bx
value|(0x1<< CHIP_REV_SHIFT)
define|#
directive|define
name|CHIP_REV_Cx
value|(0x2<< CHIP_REV_SHIFT)
define|#
directive|define
name|CHIP_REV_IS_SLOW
parameter_list|(
name|sc
parameter_list|)
define|\
value|(CHIP_REV(sc)> 0x00005000)
define|#
directive|define
name|CHIP_REV_IS_FPGA
parameter_list|(
name|sc
parameter_list|)
define|\
value|(CHIP_REV_IS_SLOW(sc)&& (CHIP_REV(sc)& 0x00001000))
define|#
directive|define
name|CHIP_REV_IS_EMUL
parameter_list|(
name|sc
parameter_list|)
define|\
value|(CHIP_REV_IS_SLOW(sc)&& !(CHIP_REV(sc)& 0x00001000))
define|#
directive|define
name|CHIP_REV_IS_ASIC
parameter_list|(
name|sc
parameter_list|)
define|\
value|(!CHIP_REV_IS_SLOW(sc))
define|#
directive|define
name|CHIP_METAL
parameter_list|(
name|sc
parameter_list|)
value|((sc->devinfo.chip_id)& 0x00000ff0)
define|#
directive|define
name|CHIP_BOND_ID
parameter_list|(
name|sc
parameter_list|)
value|((sc->devinfo.chip_id)& 0x0000000f)
define|#
directive|define
name|CHIP_IS_E1
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57710)
define|#
directive|define
name|CHIP_IS_57710
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57710)
define|#
directive|define
name|CHIP_IS_57711
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57711)
define|#
directive|define
name|CHIP_IS_57711E
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57711E)
define|#
directive|define
name|CHIP_IS_E1H
parameter_list|(
name|sc
parameter_list|)
value|((CHIP_IS_57711(sc)) || \                              (CHIP_IS_57711E(sc)))
define|#
directive|define
name|CHIP_IS_E1x
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E1((sc)) || \                              CHIP_IS_E1H((sc)))
define|#
directive|define
name|CHIP_IS_57712
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57712)
define|#
directive|define
name|CHIP_IS_57712_MF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57712_MF)
define|#
directive|define
name|CHIP_IS_57712_VF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57712_VF)
define|#
directive|define
name|CHIP_IS_E2
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_57712(sc) ||  \                               CHIP_IS_57712_MF(sc))
define|#
directive|define
name|CHIP_IS_57800
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57800)
define|#
directive|define
name|CHIP_IS_57800_MF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57800_MF)
define|#
directive|define
name|CHIP_IS_57800_VF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57800_VF)
define|#
directive|define
name|CHIP_IS_57810
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57810)
define|#
directive|define
name|CHIP_IS_57810_MF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57810_MF)
define|#
directive|define
name|CHIP_IS_57810_VF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57810_VF)
define|#
directive|define
name|CHIP_IS_57811
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57811)
define|#
directive|define
name|CHIP_IS_57811_MF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57811_MF)
define|#
directive|define
name|CHIP_IS_57811_VF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57811_VF)
define|#
directive|define
name|CHIP_IS_57840
parameter_list|(
name|sc
parameter_list|)
value|((CHIP_NUM(sc) == CHIP_NUM_57840_OBS)  || \                               (CHIP_NUM(sc) == CHIP_NUM_57840_4_10) || \                               (CHIP_NUM(sc) == CHIP_NUM_57840_2_20))
define|#
directive|define
name|CHIP_IS_57840_MF
parameter_list|(
name|sc
parameter_list|)
value|((CHIP_NUM(sc) == CHIP_NUM_57840_OBS_MF) || \                               (CHIP_NUM(sc) == CHIP_NUM_57840_MF))
define|#
directive|define
name|CHIP_IS_57840_VF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_NUM(sc) == CHIP_NUM_57840_VF)
define|#
directive|define
name|CHIP_IS_E3
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_57800(sc)    || \                              CHIP_IS_57800_MF(sc) || \                              CHIP_IS_57800_VF(sc) || \                              CHIP_IS_57810(sc)    || \                              CHIP_IS_57810_MF(sc) || \                              CHIP_IS_57810_VF(sc) || \                              CHIP_IS_57811(sc)    || \                              CHIP_IS_57811_MF(sc) || \                              CHIP_IS_57811_VF(sc) || \                              CHIP_IS_57840(sc)    || \                              CHIP_IS_57840_MF(sc) || \                              CHIP_IS_57840_VF(sc))
define|#
directive|define
name|CHIP_IS_E3A0
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E3(sc)&&              \                              (CHIP_REV(sc) == CHIP_REV_Ax))
define|#
directive|define
name|CHIP_IS_E3B0
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E3(sc)&&              \                              (CHIP_REV(sc) == CHIP_REV_Bx))
define|#
directive|define
name|USES_WARPCORE
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E3(sc))
define|#
directive|define
name|CHIP_IS_E2E3
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E2(sc) || \                              CHIP_IS_E3(sc))
define|#
directive|define
name|CHIP_IS_MF_CAP
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_57711E(sc)  ||  \                              CHIP_IS_57712_MF(sc) || \                              CHIP_IS_E3(sc))
define|#
directive|define
name|IS_VF
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_57712_VF(sc) || \                              CHIP_IS_57800_VF(sc) || \                              CHIP_IS_57810_VF(sc) || \                              CHIP_IS_57840_VF(sc))
define|#
directive|define
name|IS_PF
parameter_list|(
name|sc
parameter_list|)
value|(!IS_VF(sc))
comment|/*  * This define is used in two main places:  * 1. In the early stages of nic_load, to know if to configure Parser/Searcher  * to nic-only mode or to offload mode. Offload mode is configured if either  * the chip is E1x (where NIC_MODE register is not applicable), or if cnic  * already registered for this port (which means that the user wants storage  * services).  * 2. During cnic-related load, to know if offload mode is already configured  * in the HW or needs to be configrued. Since the transition from nic-mode to  * offload-mode in HW causes traffic coruption, nic-mode is configured only  * in ports on which storage services where never requested.  */
define|#
directive|define
name|CONFIGURE_NIC_MODE
parameter_list|(
name|sc
parameter_list|)
value|(!CHIP_IS_E1x(sc)&& !CNIC_ENABLED(sc))
name|uint8_t
name|chip_port_mode
decl_stmt|;
define|#
directive|define
name|CHIP_4_PORT_MODE
value|0x0
define|#
directive|define
name|CHIP_2_PORT_MODE
value|0x1
define|#
directive|define
name|CHIP_PORT_MODE_NONE
value|0x2
define|#
directive|define
name|CHIP_PORT_MODE
parameter_list|(
name|sc
parameter_list|)
value|((sc)->devinfo.chip_port_mode)
define|#
directive|define
name|CHIP_IS_MODE_4_PORT
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_PORT_MODE(sc) == CHIP_4_PORT_MODE)
name|uint8_t
name|int_block
decl_stmt|;
define|#
directive|define
name|INT_BLOCK_HC
value|0
define|#
directive|define
name|INT_BLOCK_IGU
value|1
define|#
directive|define
name|INT_BLOCK_MODE_NORMAL
value|0
define|#
directive|define
name|INT_BLOCK_MODE_BW_COMP
value|2
define|#
directive|define
name|CHIP_INT_MODE_IS_NBC
parameter_list|(
name|sc
parameter_list|)
define|\
value|(!CHIP_IS_E1x(sc)&&                                  \      !((sc)->devinfo.int_block& INT_BLOCK_MODE_BW_COMP))
define|#
directive|define
name|CHIP_INT_MODE_IS_BC
parameter_list|(
name|sc
parameter_list|)
value|(!CHIP_INT_MODE_IS_NBC(sc))
name|uint32_t
name|shmem_base
decl_stmt|;
name|uint32_t
name|shmem2_base
decl_stmt|;
name|uint32_t
name|bc_ver
decl_stmt|;
name|char
name|bc_ver_str
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|mf_cfg_base
decl_stmt|;
comment|/* bootcode shmem address in BAR memory */
name|struct
name|bxe_mf_info
name|mf_info
decl_stmt|;
name|int
name|flash_size
decl_stmt|;
define|#
directive|define
name|NVRAM_1MB_SIZE
value|0x20000
define|#
directive|define
name|NVRAM_TIMEOUT_COUNT
value|30000
define|#
directive|define
name|NVRAM_PAGE_SIZE
value|256
comment|/* PCIe capability information */
name|uint32_t
name|pcie_cap_flags
decl_stmt|;
define|#
directive|define
name|BXE_PM_CAPABLE_FLAG
value|0x00000001
define|#
directive|define
name|BXE_PCIE_CAPABLE_FLAG
value|0x00000002
define|#
directive|define
name|BXE_MSI_CAPABLE_FLAG
value|0x00000004
define|#
directive|define
name|BXE_MSIX_CAPABLE_FLAG
value|0x00000008
name|uint16_t
name|pcie_pm_cap_reg
decl_stmt|;
name|uint16_t
name|pcie_pcie_cap_reg
decl_stmt|;
comment|//uint16_t pcie_devctl;
name|uint16_t
name|pcie_link_width
decl_stmt|;
name|uint16_t
name|pcie_link_speed
decl_stmt|;
name|uint16_t
name|pcie_msi_cap_reg
decl_stmt|;
name|uint16_t
name|pcie_msix_cap_reg
decl_stmt|;
comment|/* device configuration read from bootcode shared memory */
name|uint32_t
name|hw_config
decl_stmt|;
name|uint32_t
name|hw_config2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* struct bxe_devinfo */
end_comment

begin_struct
struct|struct
name|bxe_sp_objs
block|{
name|struct
name|ecore_vlan_mac_obj
name|mac_obj
decl_stmt|;
comment|/* MACs object */
name|struct
name|ecore_queue_sp_obj
name|q_obj
decl_stmt|;
comment|/* Queue State object */
block|}
struct|;
end_struct

begin_comment
comment|/* struct bxe_sp_objs */
end_comment

begin_comment
comment|/*  * Data that will be used to create a link report message. We will keep the  * data used for the last link report in order to prevent reporting the same  * link parameters twice.  */
end_comment

begin_struct
struct|struct
name|bxe_link_report_data
block|{
name|uint16_t
name|line_speed
decl_stmt|;
comment|/* Effective line speed */
name|unsigned
name|long
name|link_report_flags
decl_stmt|;
comment|/* BXE_LINK_REPORT_XXX flags */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|BXE_LINK_REPORT_FULL_DUPLEX
block|,
name|BXE_LINK_REPORT_LINK_DOWN
block|,
name|BXE_LINK_REPORT_RX_FC_ON
block|,
name|BXE_LINK_REPORT_TX_FC_ON
block|}
enum|;
end_enum

begin_comment
comment|/* Top level device private data structure. */
end_comment

begin_struct
struct|struct
name|bxe_softc
block|{
comment|/*      * First entry must be a pointer to the BSD ifnet struct which      * has a first element of 'void *if_softc' (which is us). XXX      */
name|if_t
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* network interface media structure */
name|int
name|media
decl_stmt|;
specifier|volatile
name|int
name|state
decl_stmt|;
comment|/* device state */
define|#
directive|define
name|BXE_STATE_CLOSED
value|0x0000
define|#
directive|define
name|BXE_STATE_OPENING_WAITING_LOAD
value|0x1000
define|#
directive|define
name|BXE_STATE_OPENING_WAITING_PORT
value|0x2000
define|#
directive|define
name|BXE_STATE_OPEN
value|0x3000
define|#
directive|define
name|BXE_STATE_CLOSING_WAITING_HALT
value|0x4000
define|#
directive|define
name|BXE_STATE_CLOSING_WAITING_DELETE
value|0x5000
define|#
directive|define
name|BXE_STATE_CLOSING_WAITING_UNLOAD
value|0x6000
define|#
directive|define
name|BXE_STATE_DISABLED
value|0xD000
define|#
directive|define
name|BXE_STATE_DIAG
value|0xE000
define|#
directive|define
name|BXE_STATE_ERROR
value|0xF000
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|BXE_ONE_PORT_FLAG
value|0x00000001
define|#
directive|define
name|BXE_NO_ISCSI
value|0x00000002
define|#
directive|define
name|BXE_NO_FCOE
value|0x00000004
define|#
directive|define
name|BXE_ONE_PORT
parameter_list|(
name|sc
parameter_list|)
value|(sc->flags& BXE_ONE_PORT_FLAG)
comment|//#define BXE_NO_WOL_FLAG      0x00000008
comment|//#define BXE_USING_DAC_FLAG   0x00000010
comment|//#define BXE_USING_MSIX_FLAG  0x00000020
comment|//#define BXE_USING_MSI_FLAG   0x00000040
comment|//#define BXE_DISABLE_MSI_FLAG 0x00000080
define|#
directive|define
name|BXE_NO_MCP_FLAG
value|0x00000200
define|#
directive|define
name|BXE_NOMCP
parameter_list|(
name|sc
parameter_list|)
value|(sc->flags& BXE_NO_MCP_FLAG)
comment|//#define BXE_SAFC_TX_FLAG     0x00000400
define|#
directive|define
name|BXE_MF_FUNC_DIS
value|0x00000800
define|#
directive|define
name|BXE_TX_SWITCHING
value|0x00001000
define|#
directive|define
name|BXE_NO_PULSE
value|0x00002000
name|unsigned
name|long
name|debug
decl_stmt|;
comment|/* per-instance debug logging config */
define|#
directive|define
name|MAX_BARS
value|5
name|struct
name|bxe_bar
name|bar
index|[
name|MAX_BARS
index|]
decl_stmt|;
comment|/* map BARs 0, 2, 4 */
name|uint16_t
name|doorbell_size
decl_stmt|;
comment|/* periodic timer callout */
define|#
directive|define
name|PERIODIC_STOP
value|0
define|#
directive|define
name|PERIODIC_GO
value|1
specifier|volatile
name|unsigned
name|long
name|periodic_flags
decl_stmt|;
name|struct
name|callout
name|periodic_callout
decl_stmt|;
comment|/* chip start/stop/reset taskqueue */
define|#
directive|define
name|CHIP_TQ_NONE
value|0
define|#
directive|define
name|CHIP_TQ_START
value|1
define|#
directive|define
name|CHIP_TQ_STOP
value|2
define|#
directive|define
name|CHIP_TQ_REINIT
value|3
specifier|volatile
name|unsigned
name|long
name|chip_tq_flags
decl_stmt|;
name|struct
name|task
name|chip_tq_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|chip_tq
decl_stmt|;
name|char
name|chip_tq_name
index|[
literal|32
index|]
decl_stmt|;
comment|/* slowpath interrupt taskqueue */
name|struct
name|task
name|sp_tq_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sp_tq
decl_stmt|;
name|char
name|sp_tq_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|bxe_fastpath
name|fp
index|[
name|MAX_RSS_CHAINS
index|]
decl_stmt|;
name|struct
name|bxe_sp_objs
name|sp_objs
index|[
name|MAX_RSS_CHAINS
index|]
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
comment|/* parent device handle */
name|uint8_t
name|unit
decl_stmt|;
comment|/* driver instance number */
name|int
name|pcie_bus
decl_stmt|;
comment|/* PCIe bus number */
name|int
name|pcie_device
decl_stmt|;
comment|/* PCIe device/slot number */
name|int
name|pcie_func
decl_stmt|;
comment|/* PCIe function number */
name|uint8_t
name|pfunc_rel
decl_stmt|;
comment|/* function relative */
name|uint8_t
name|pfunc_abs
decl_stmt|;
comment|/* function absolute */
name|uint8_t
name|path_id
decl_stmt|;
comment|/* function absolute */
define|#
directive|define
name|SC_PATH
parameter_list|(
name|sc
parameter_list|)
value|(sc->path_id)
define|#
directive|define
name|SC_PORT
parameter_list|(
name|sc
parameter_list|)
value|(sc->pfunc_rel& 1)
define|#
directive|define
name|SC_FUNC
parameter_list|(
name|sc
parameter_list|)
value|(sc->pfunc_rel)
define|#
directive|define
name|SC_ABS_FUNC
parameter_list|(
name|sc
parameter_list|)
value|(sc->pfunc_abs)
define|#
directive|define
name|SC_VN
parameter_list|(
name|sc
parameter_list|)
value|(sc->pfunc_rel>> 1)
define|#
directive|define
name|SC_L_ID
parameter_list|(
name|sc
parameter_list|)
value|(SC_VN(sc)<< 2)
define|#
directive|define
name|PORT_ID
parameter_list|(
name|sc
parameter_list|)
value|SC_PORT(sc)
define|#
directive|define
name|PATH_ID
parameter_list|(
name|sc
parameter_list|)
value|SC_PATH(sc)
define|#
directive|define
name|VNIC_ID
parameter_list|(
name|sc
parameter_list|)
value|SC_VN(sc)
define|#
directive|define
name|FUNC_ID
parameter_list|(
name|sc
parameter_list|)
value|SC_FUNC(sc)
define|#
directive|define
name|ABS_FUNC_ID
parameter_list|(
name|sc
parameter_list|)
value|SC_ABS_FUNC(sc)
define|#
directive|define
name|SC_FW_MB_IDX_VN
parameter_list|(
name|sc
parameter_list|,
name|vn
parameter_list|)
define|\
value|(SC_PORT(sc) + (vn) *                                      \      ((CHIP_IS_E1x(sc) || (CHIP_IS_MODE_4_PORT(sc))) ? 2 : 1))
define|#
directive|define
name|SC_FW_MB_IDX
parameter_list|(
name|sc
parameter_list|)
value|SC_FW_MB_IDX_VN(sc, SC_VN(sc))
name|int
name|if_capen
decl_stmt|;
comment|/* enabled interface capabilities */
name|struct
name|bxe_devinfo
name|devinfo
decl_stmt|;
name|char
name|fw_ver_str
index|[
literal|32
index|]
decl_stmt|;
name|char
name|mf_mode_str
index|[
literal|32
index|]
decl_stmt|;
name|char
name|pci_link_str
index|[
literal|32
index|]
decl_stmt|;
specifier|const
name|struct
name|iro
modifier|*
name|iro_array
decl_stmt|;
ifdef|#
directive|ifdef
name|BXE_CORE_LOCK_SX
name|struct
name|sx
name|core_sx
decl_stmt|;
name|char
name|core_sx_name
index|[
literal|32
index|]
decl_stmt|;
else|#
directive|else
name|struct
name|mtx
name|core_mtx
decl_stmt|;
name|char
name|core_mtx_name
index|[
literal|32
index|]
decl_stmt|;
endif|#
directive|endif
name|struct
name|mtx
name|sp_mtx
decl_stmt|;
name|char
name|sp_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|dmae_mtx
decl_stmt|;
name|char
name|dmae_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|fwmb_mtx
decl_stmt|;
name|char
name|fwmb_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|print_mtx
decl_stmt|;
name|char
name|print_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|stats_mtx
decl_stmt|;
name|char
name|stats_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|mcast_mtx
decl_stmt|;
name|char
name|mcast_mtx_name
index|[
literal|32
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|BXE_CORE_LOCK_SX
define|#
directive|define
name|BXE_CORE_TRYLOCK
parameter_list|(
name|sc
parameter_list|)
value|sx_try_xlock(&sc->core_sx)
define|#
directive|define
name|BXE_CORE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|sx_xlock(&sc->core_sx)
define|#
directive|define
name|BXE_CORE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|sx_xunlock(&sc->core_sx)
define|#
directive|define
name|BXE_CORE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|sx_assert(&sc->core_sx, SA_XLOCKED)
else|#
directive|else
define|#
directive|define
name|BXE_CORE_TRYLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_trylock(&sc->core_mtx)
define|#
directive|define
name|BXE_CORE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&sc->core_mtx)
define|#
directive|define
name|BXE_CORE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&sc->core_mtx)
define|#
directive|define
name|BXE_CORE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->core_mtx, MA_OWNED)
endif|#
directive|endif
define|#
directive|define
name|BXE_SP_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&sc->sp_mtx)
define|#
directive|define
name|BXE_SP_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&sc->sp_mtx)
define|#
directive|define
name|BXE_SP_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->sp_mtx, MA_OWNED)
define|#
directive|define
name|BXE_DMAE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&sc->dmae_mtx)
define|#
directive|define
name|BXE_DMAE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&sc->dmae_mtx)
define|#
directive|define
name|BXE_DMAE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->dmae_mtx, MA_OWNED)
define|#
directive|define
name|BXE_FWMB_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&sc->fwmb_mtx)
define|#
directive|define
name|BXE_FWMB_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&sc->fwmb_mtx)
define|#
directive|define
name|BXE_FWMB_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->fwmb_mtx, MA_OWNED)
define|#
directive|define
name|BXE_PRINT_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&sc->print_mtx)
define|#
directive|define
name|BXE_PRINT_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&sc->print_mtx)
define|#
directive|define
name|BXE_PRINT_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->print_mtx, MA_OWNED)
define|#
directive|define
name|BXE_STATS_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&sc->stats_mtx)
define|#
directive|define
name|BXE_STATS_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&sc->stats_mtx)
define|#
directive|define
name|BXE_STATS_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->stats_mtx, MA_OWNED)
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|800000
define|#
directive|define
name|BXE_MCAST_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {                          \         mtx_lock(&sc->mcast_mtx); \         IF_ADDR_LOCK(sc->ifp);  \     } while (0)
define|#
directive|define
name|BXE_MCAST_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {                            \         IF_ADDR_UNLOCK(sc->ifp);  \         mtx_unlock(&sc->mcast_mtx); \     } while (0)
else|#
directive|else
define|#
directive|define
name|BXE_MCAST_LOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {                           \         mtx_lock(&sc->mcast_mtx);  \         if_maddr_rlock(sc->ifp); \     } while (0)
define|#
directive|define
name|BXE_MCAST_UNLOCK
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {                             \         if_maddr_runlock(sc->ifp); \         mtx_unlock(&sc->mcast_mtx);  \     } while (0)
endif|#
directive|endif
define|#
directive|define
name|BXE_MCAST_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&sc->mcast_mtx, MA_OWNED)
name|int
name|dmae_ready
decl_stmt|;
define|#
directive|define
name|DMAE_READY
parameter_list|(
name|sc
parameter_list|)
value|(sc->dmae_ready)
name|struct
name|ecore_credit_pool_obj
name|vlans_pool
decl_stmt|;
name|struct
name|ecore_credit_pool_obj
name|macs_pool
decl_stmt|;
name|struct
name|ecore_rx_mode_obj
name|rx_mode_obj
decl_stmt|;
name|struct
name|ecore_mcast_obj
name|mcast_obj
decl_stmt|;
name|struct
name|ecore_rss_config_obj
name|rss_conf_obj
decl_stmt|;
name|struct
name|ecore_func_sp_obj
name|func_obj
decl_stmt|;
name|uint16_t
name|fw_seq
decl_stmt|;
name|uint16_t
name|fw_drv_pulse_wr_seq
decl_stmt|;
name|uint32_t
name|func_stx
decl_stmt|;
name|struct
name|elink_params
name|link_params
decl_stmt|;
name|struct
name|elink_vars
name|link_vars
decl_stmt|;
name|uint32_t
name|link_cnt
decl_stmt|;
name|struct
name|bxe_link_report_data
name|last_reported_link
decl_stmt|;
name|char
name|mac_addr_str
index|[
literal|32
index|]
decl_stmt|;
name|int
name|last_reported_link_state
decl_stmt|;
name|int
name|tx_ring_size
decl_stmt|;
name|int
name|rx_ring_size
decl_stmt|;
name|int
name|wol
decl_stmt|;
name|int
name|is_leader
decl_stmt|;
name|int
name|recovery_state
decl_stmt|;
define|#
directive|define
name|BXE_RECOVERY_DONE
value|1
define|#
directive|define
name|BXE_RECOVERY_INIT
value|2
define|#
directive|define
name|BXE_RECOVERY_WAIT
value|3
define|#
directive|define
name|BXE_RECOVERY_FAILED
value|4
define|#
directive|define
name|BXE_RECOVERY_NIC_LOADING
value|5
name|uint32_t
name|rx_mode
decl_stmt|;
define|#
directive|define
name|BXE_RX_MODE_NONE
value|0
define|#
directive|define
name|BXE_RX_MODE_NORMAL
value|1
define|#
directive|define
name|BXE_RX_MODE_ALLMULTI
value|2
define|#
directive|define
name|BXE_RX_MODE_PROMISC
value|3
define|#
directive|define
name|BXE_MAX_MULTICAST
value|64
name|struct
name|bxe_port
name|port
decl_stmt|;
name|struct
name|cmng_init
name|cmng
decl_stmt|;
comment|/* user configs */
name|int
name|num_queues
decl_stmt|;
name|int
name|max_rx_bufs
decl_stmt|;
name|int
name|hc_rx_ticks
decl_stmt|;
name|int
name|hc_tx_ticks
decl_stmt|;
name|int
name|rx_budget
decl_stmt|;
name|int
name|max_aggregation_size
decl_stmt|;
name|int
name|mrrs
decl_stmt|;
name|int
name|autogreeen
decl_stmt|;
define|#
directive|define
name|AUTO_GREEN_HW_DEFAULT
value|0
define|#
directive|define
name|AUTO_GREEN_FORCE_ON
value|1
define|#
directive|define
name|AUTO_GREEN_FORCE_OFF
value|2
name|int
name|interrupt_mode
decl_stmt|;
define|#
directive|define
name|INTR_MODE_INTX
value|0
define|#
directive|define
name|INTR_MODE_MSI
value|1
define|#
directive|define
name|INTR_MODE_MSIX
value|2
name|int
name|udp_rss
decl_stmt|;
comment|/* interrupt allocations */
name|struct
name|bxe_intr
name|intr
index|[
name|MAX_RSS_CHAINS
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|intr_count
decl_stmt|;
name|uint8_t
name|igu_dsb_id
decl_stmt|;
name|uint8_t
name|igu_base_sb
decl_stmt|;
name|uint8_t
name|igu_sb_cnt
decl_stmt|;
comment|//uint8_t         min_msix_vec_cnt;
name|uint32_t
name|igu_base_addr
decl_stmt|;
comment|//bus_addr_t      def_status_blk_mapping;
name|uint8_t
name|base_fw_ndsb
decl_stmt|;
define|#
directive|define
name|DEF_SB_IGU_ID
value|16
define|#
directive|define
name|DEF_SB_ID
value|HC_SP_SB_ID
comment|/* parent bus DMA tag  */
name|bus_dma_tag_t
name|parent_dma_tag
decl_stmt|;
comment|/* default status block */
name|struct
name|bxe_dma
name|def_sb_dma
decl_stmt|;
name|struct
name|host_sp_status_block
modifier|*
name|def_sb
decl_stmt|;
name|uint16_t
name|def_idx
decl_stmt|;
name|uint16_t
name|def_att_idx
decl_stmt|;
name|uint32_t
name|attn_state
decl_stmt|;
name|struct
name|attn_route
name|attn_group
index|[
name|MAX_DYNAMIC_ATTN_GRPS
index|]
decl_stmt|;
comment|/* general SP events - stats query, cfc delete, etc */
define|#
directive|define
name|HC_SP_INDEX_ETH_DEF_CONS
value|3
comment|/* EQ completions */
define|#
directive|define
name|HC_SP_INDEX_EQ_CONS
value|7
comment|/* FCoE L2 connection completions */
define|#
directive|define
name|HC_SP_INDEX_ETH_FCOE_TX_CQ_CONS
value|6
define|#
directive|define
name|HC_SP_INDEX_ETH_FCOE_RX_CQ_CONS
value|4
comment|/* iSCSI L2 */
define|#
directive|define
name|HC_SP_INDEX_ETH_ISCSI_CQ_CONS
value|5
define|#
directive|define
name|HC_SP_INDEX_ETH_ISCSI_RX_CQ_CONS
value|1
comment|/* event queue */
name|struct
name|bxe_dma
name|eq_dma
decl_stmt|;
name|union
name|event_ring_elem
modifier|*
name|eq
decl_stmt|;
name|uint16_t
name|eq_prod
decl_stmt|;
name|uint16_t
name|eq_cons
decl_stmt|;
name|uint16_t
modifier|*
name|eq_cons_sb
decl_stmt|;
define|#
directive|define
name|NUM_EQ_PAGES
value|1
comment|/* must be a power of 2 */
define|#
directive|define
name|EQ_DESC_CNT_PAGE
value|(BCM_PAGE_SIZE / sizeof(union event_ring_elem))
define|#
directive|define
name|EQ_DESC_MAX_PAGE
value|(EQ_DESC_CNT_PAGE - 1)
define|#
directive|define
name|NUM_EQ_DESC
value|(EQ_DESC_CNT_PAGE * NUM_EQ_PAGES)
define|#
directive|define
name|EQ_DESC_MASK
value|(NUM_EQ_DESC - 1)
define|#
directive|define
name|MAX_EQ_AVAIL
value|(EQ_DESC_MAX_PAGE * NUM_EQ_PAGES - 2)
comment|/* depends on EQ_DESC_CNT_PAGE being a power of 2 */
define|#
directive|define
name|NEXT_EQ_IDX
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& EQ_DESC_MAX_PAGE) == (EQ_DESC_MAX_PAGE - 1)) ? \          ((x) + 2) : ((x) + 1))
comment|/* depends on the above and on NUM_EQ_PAGES being a power of 2 */
define|#
directive|define
name|EQ_DESC
parameter_list|(
name|x
parameter_list|)
value|((x)& EQ_DESC_MASK)
comment|/* slow path */
name|struct
name|bxe_dma
name|sp_dma
decl_stmt|;
name|struct
name|bxe_slowpath
modifier|*
name|sp
decl_stmt|;
name|unsigned
name|long
name|sp_state
decl_stmt|;
comment|/* slow path queue */
name|struct
name|bxe_dma
name|spq_dma
decl_stmt|;
name|struct
name|eth_spe
modifier|*
name|spq
decl_stmt|;
define|#
directive|define
name|SP_DESC_CNT
value|(BCM_PAGE_SIZE / sizeof(struct eth_spe))
define|#
directive|define
name|MAX_SP_DESC_CNT
value|(SP_DESC_CNT - 1)
define|#
directive|define
name|MAX_SPQ_PENDING
value|8
name|uint16_t
name|spq_prod_idx
decl_stmt|;
name|struct
name|eth_spe
modifier|*
name|spq_prod_bd
decl_stmt|;
name|struct
name|eth_spe
modifier|*
name|spq_last_bd
decl_stmt|;
name|uint16_t
modifier|*
name|dsb_sp_prod
decl_stmt|;
comment|//uint16_t       *spq_hw_con;
comment|//uint16_t       spq_left;
specifier|volatile
name|unsigned
name|long
name|eq_spq_left
decl_stmt|;
comment|/* COMMON_xxx ramrod credit */
specifier|volatile
name|unsigned
name|long
name|cq_spq_left
decl_stmt|;
comment|/* ETH_xxx ramrod credit */
comment|/* fw decompression buffer */
name|struct
name|bxe_dma
name|gz_buf_dma
decl_stmt|;
name|void
modifier|*
name|gz_buf
decl_stmt|;
name|z_streamp
name|gz_strm
decl_stmt|;
name|uint32_t
name|gz_outlen
decl_stmt|;
define|#
directive|define
name|GUNZIP_BUF
parameter_list|(
name|sc
parameter_list|)
value|(sc->gz_buf)
define|#
directive|define
name|GUNZIP_OUTLEN
parameter_list|(
name|sc
parameter_list|)
value|(sc->gz_outlen)
define|#
directive|define
name|GUNZIP_PHYS
parameter_list|(
name|sc
parameter_list|)
value|(sc->gz_buf_dma.paddr)
define|#
directive|define
name|FW_BUF_SIZE
value|0x40000
specifier|const
name|struct
name|raw_op
modifier|*
name|init_ops
decl_stmt|;
specifier|const
name|uint16_t
modifier|*
name|init_ops_offsets
decl_stmt|;
comment|/* init block offsets inside init_ops */
specifier|const
name|uint32_t
modifier|*
name|init_data
decl_stmt|;
comment|/* data blob, 32 bit granularity */
name|uint32_t
name|init_mode_flags
decl_stmt|;
define|#
directive|define
name|INIT_MODE_FLAGS
parameter_list|(
name|sc
parameter_list|)
value|(sc->init_mode_flags)
comment|/* PRAM blobs - raw data */
specifier|const
name|uint8_t
modifier|*
name|tsem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|tsem_pram_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|usem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|usem_pram_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|xsem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|xsem_pram_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|csem_int_table_data
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|csem_pram_data
decl_stmt|;
define|#
directive|define
name|INIT_OPS
parameter_list|(
name|sc
parameter_list|)
value|(sc->init_ops)
define|#
directive|define
name|INIT_OPS_OFFSETS
parameter_list|(
name|sc
parameter_list|)
value|(sc->init_ops_offsets)
define|#
directive|define
name|INIT_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->init_data)
define|#
directive|define
name|INIT_TSEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->tsem_int_table_data)
define|#
directive|define
name|INIT_TSEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->tsem_pram_data)
define|#
directive|define
name|INIT_USEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->usem_int_table_data)
define|#
directive|define
name|INIT_USEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->usem_pram_data)
define|#
directive|define
name|INIT_XSEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->xsem_int_table_data)
define|#
directive|define
name|INIT_XSEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->xsem_pram_data)
define|#
directive|define
name|INIT_CSEM_INT_TABLE_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->csem_int_table_data)
define|#
directive|define
name|INIT_CSEM_PRAM_DATA
parameter_list|(
name|sc
parameter_list|)
value|(sc->csem_pram_data)
comment|/* ILT      * For max 196 cids (64*3 + non-eth), 32KB ILT page size and 1KB      * context size we need 8 ILT entries.      */
define|#
directive|define
name|ILT_MAX_L2_LINES
value|8
name|struct
name|hw_context
name|context
index|[
name|ILT_MAX_L2_LINES
index|]
decl_stmt|;
name|struct
name|ecore_ilt
modifier|*
name|ilt
decl_stmt|;
define|#
directive|define
name|ILT_MAX_LINES
value|256
comment|/* max supported number of RSS queues: IGU SBs minus one for CNIC */
define|#
directive|define
name|BXE_MAX_RSS_COUNT
parameter_list|(
name|sc
parameter_list|)
value|((sc)->igu_sb_cnt - CNIC_SUPPORT(sc))
comment|/* max CID count: Max RSS * Max_Tx_Multi_Cos + FCoE + iSCSI */
if|#
directive|if
literal|1
define|#
directive|define
name|BXE_L2_MAX_CID
parameter_list|(
name|sc
parameter_list|)
define|\
value|(BXE_MAX_RSS_COUNT(sc) * ECORE_MULTI_TX_COS + 2 * CNIC_SUPPORT(sc))
else|#
directive|else
define|#
directive|define
name|BXE_L2_MAX_CID
parameter_list|(
name|sc
parameter_list|)
comment|/* OOO + FWD */
define|\
value|(BXE_MAX_RSS_COUNT(sc) * ECORE_MULTI_TX_COS + 4 * CNIC_SUPPORT(sc))
endif|#
directive|endif
if|#
directive|if
literal|1
define|#
directive|define
name|BXE_L2_CID_COUNT
parameter_list|(
name|sc
parameter_list|)
define|\
value|(BXE_NUM_ETH_QUEUES(sc) * ECORE_MULTI_TX_COS + 2 * CNIC_SUPPORT(sc))
else|#
directive|else
define|#
directive|define
name|BXE_L2_CID_COUNT
parameter_list|(
name|sc
parameter_list|)
comment|/* OOO + FWD */
define|\
value|(BXE_NUM_ETH_QUEUES(sc) * ECORE_MULTI_TX_COS + 4 * CNIC_SUPPORT(sc))
endif|#
directive|endif
define|#
directive|define
name|L2_ILT_LINES
parameter_list|(
name|sc
parameter_list|)
define|\
value|(DIV_ROUND_UP(BXE_L2_CID_COUNT(sc), ILT_PAGE_CIDS))
name|int
name|qm_cid_count
decl_stmt|;
name|uint8_t
name|dropless_fc
decl_stmt|;
comment|/* total number of FW statistics requests */
name|uint8_t
name|fw_stats_num
decl_stmt|;
comment|/*      * This is a memory buffer that will contain both statistics ramrod      * request and data.      */
name|struct
name|bxe_dma
name|fw_stats_dma
decl_stmt|;
comment|/*      * FW statistics request shortcut (points at the beginning of fw_stats      * buffer).      */
name|int
name|fw_stats_req_size
decl_stmt|;
name|struct
name|bxe_fw_stats_req
modifier|*
name|fw_stats_req
decl_stmt|;
name|bus_addr_t
name|fw_stats_req_mapping
decl_stmt|;
comment|/*      * FW statistics data shortcut (points at the beginning of fw_stats      * buffer + fw_stats_req_size).      */
name|int
name|fw_stats_data_size
decl_stmt|;
name|struct
name|bxe_fw_stats_data
modifier|*
name|fw_stats_data
decl_stmt|;
name|bus_addr_t
name|fw_stats_data_mapping
decl_stmt|;
comment|/* tracking a pending STAT_QUERY ramrod */
name|uint16_t
name|stats_pending
decl_stmt|;
comment|/* number of completed statistics ramrods */
name|uint16_t
name|stats_comp
decl_stmt|;
name|uint16_t
name|stats_counter
decl_stmt|;
name|uint8_t
name|stats_init
decl_stmt|;
name|int
name|stats_state
decl_stmt|;
name|struct
name|bxe_eth_stats
name|eth_stats
decl_stmt|;
name|struct
name|host_func_stats
name|func_stats
decl_stmt|;
name|struct
name|bxe_eth_stats_old
name|eth_stats_old
decl_stmt|;
name|struct
name|bxe_net_stats_old
name|net_stats_old
decl_stmt|;
name|struct
name|bxe_fw_port_stats_old
name|fw_stats_old
decl_stmt|;
name|struct
name|dmae_cmd
name|stats_dmae
decl_stmt|;
comment|/* used by dmae command loader */
name|int
name|executer_idx
decl_stmt|;
name|int
name|mtu
decl_stmt|;
comment|/* LLDP params */
name|struct
name|bxe_config_lldp_params
name|lldp_config_params
decl_stmt|;
comment|/* DCB support on/off */
name|int
name|dcb_state
decl_stmt|;
define|#
directive|define
name|BXE_DCB_STATE_OFF
value|0
define|#
directive|define
name|BXE_DCB_STATE_ON
value|1
comment|/* DCBX engine mode */
name|int
name|dcbx_enabled
decl_stmt|;
define|#
directive|define
name|BXE_DCBX_ENABLED_OFF
value|0
define|#
directive|define
name|BXE_DCBX_ENABLED_ON_NEG_OFF
value|1
define|#
directive|define
name|BXE_DCBX_ENABLED_ON_NEG_ON
value|2
define|#
directive|define
name|BXE_DCBX_ENABLED_INVALID
value|-1
name|uint8_t
name|dcbx_mode_uset
decl_stmt|;
name|struct
name|bxe_config_dcbx_params
name|dcbx_config_params
decl_stmt|;
name|struct
name|bxe_dcbx_port_params
name|dcbx_port_params
decl_stmt|;
name|int
name|dcb_version
decl_stmt|;
name|uint8_t
name|cnic_support
decl_stmt|;
name|uint8_t
name|cnic_enabled
decl_stmt|;
name|uint8_t
name|cnic_loaded
decl_stmt|;
define|#
directive|define
name|CNIC_SUPPORT
parameter_list|(
name|sc
parameter_list|)
value|0
comment|/* ((sc)->cnic_support) */
define|#
directive|define
name|CNIC_ENABLED
parameter_list|(
name|sc
parameter_list|)
value|0
comment|/* ((sc)->cnic_enabled) */
define|#
directive|define
name|CNIC_LOADED
parameter_list|(
name|sc
parameter_list|)
value|0
comment|/* ((sc)->cnic_loaded) */
comment|/* multiple tx classes of service */
name|uint8_t
name|max_cos
decl_stmt|;
define|#
directive|define
name|BXE_MAX_PRIORITY
value|8
comment|/* priority to cos mapping */
name|uint8_t
name|prio_to_cos
index|[
name|BXE_MAX_PRIORITY
index|]
decl_stmt|;
name|int
name|panic
decl_stmt|;
name|struct
name|cdev
modifier|*
name|ioctl_dev
decl_stmt|;
name|void
modifier|*
name|grc_dump
decl_stmt|;
name|unsigned
name|int
name|trigger_grcdump
decl_stmt|;
name|unsigned
name|int
name|grcdump_done
decl_stmt|;
name|unsigned
name|int
name|grcdump_started
decl_stmt|;
name|int
name|bxe_pause_param
decl_stmt|;
name|void
modifier|*
name|eeprom
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* struct bxe_softc */
end_comment

begin_comment
comment|/* IOCTL sub-commands for edebug and firmware upgrade */
end_comment

begin_define
define|#
directive|define
name|BXE_IOC_RD_NVRAM
value|1
end_define

begin_define
define|#
directive|define
name|BXE_IOC_WR_NVRAM
value|2
end_define

begin_define
define|#
directive|define
name|BXE_IOC_STATS_SHOW_NUM
value|3
end_define

begin_define
define|#
directive|define
name|BXE_IOC_STATS_SHOW_STR
value|4
end_define

begin_define
define|#
directive|define
name|BXE_IOC_STATS_SHOW_CNT
value|5
end_define

begin_struct
struct|struct
name|bxe_nvram_data
block|{
name|uint32_t
name|op
decl_stmt|;
comment|/* ioctl sub-command */
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|value
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable */
block|}
struct|;
end_struct

begin_union
union|union
name|bxe_stats_show_data
block|{
name|uint32_t
name|op
decl_stmt|;
comment|/* ioctl sub-command */
struct|struct
block|{
name|uint32_t
name|num
decl_stmt|;
comment|/* return number of stats */
name|uint32_t
name|len
decl_stmt|;
comment|/* length of each string item */
block|}
name|desc
struct|;
comment|/* variable length... */
name|char
name|str
index|[
literal|1
index|]
decl_stmt|;
comment|/* holds names of desc.num stats, each desc.len in length */
comment|/* variable length... */
name|uint64_t
name|stats
index|[
literal|1
index|]
decl_stmt|;
comment|/* holds all stats */
block|}
union|;
end_union

begin_comment
comment|/* function init flags */
end_comment

begin_define
define|#
directive|define
name|FUNC_FLG_RSS
value|0x0001
end_define

begin_define
define|#
directive|define
name|FUNC_FLG_STATS
value|0x0002
end_define

begin_comment
comment|/* FUNC_FLG_UNMATCHED       0x0004 */
end_comment

begin_define
define|#
directive|define
name|FUNC_FLG_TPA
value|0x0008
end_define

begin_define
define|#
directive|define
name|FUNC_FLG_SPQ
value|0x0010
end_define

begin_define
define|#
directive|define
name|FUNC_FLG_LEADING
value|0x0020
end_define

begin_comment
comment|/* PF only */
end_comment

begin_struct
struct|struct
name|bxe_func_init_params
block|{
name|bus_addr_t
name|fw_stat_map
decl_stmt|;
comment|/* (dma) valid if FUNC_FLG_STATS */
name|bus_addr_t
name|spq_map
decl_stmt|;
comment|/* (dma) valid if FUNC_FLG_SPQ */
name|uint16_t
name|func_flgs
decl_stmt|;
name|uint16_t
name|func_id
decl_stmt|;
comment|/* abs function id */
name|uint16_t
name|pf_id
decl_stmt|;
name|uint16_t
name|spq_prod
decl_stmt|;
comment|/* valid if FUNC_FLG_SPQ */
block|}
struct|;
end_struct

begin_comment
comment|/* memory resources reside at BARs 0, 2, 4 */
end_comment

begin_comment
comment|/* Run `pciconf -lb` to see mappings */
end_comment

begin_define
define|#
directive|define
name|BAR0
value|0
end_define

begin_define
define|#
directive|define
name|BAR1
value|2
end_define

begin_define
define|#
directive|define
name|BAR2
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BXE_REG_NO_INLINE
end_ifdef

begin_function_decl
name|uint8_t
name|bxe_reg_read8
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|bxe_reg_read16
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bxe_reg_read32
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_reg_write8
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_reg_write16
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_reg_write32
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REG_RD8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bxe_reg_read8(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bxe_reg_read16(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_RD32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bxe_reg_read32(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_WR8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
value|bxe_reg_write8(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
value|bxe_reg_write16(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
value|bxe_reg_write32(sc, offset, val)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not BXE_REG_NO_INLINE */
end_comment

begin_define
define|#
directive|define
name|REG_WR8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->bar[BAR0].tag,    \                       sc->bar[BAR0].handle, \                       offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->bar[BAR0].tag,    \                       sc->bar[BAR0].handle, \                       offset, val)
end_define

begin_define
define|#
directive|define
name|REG_WR32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->bar[BAR0].tag,    \                       sc->bar[BAR0].handle, \                       offset, val)
end_define

begin_define
define|#
directive|define
name|REG_RD8
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_1(sc->bar[BAR0].tag,    \                      sc->bar[BAR0].handle, \                      offset)
end_define

begin_define
define|#
directive|define
name|REG_RD16
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_2(sc->bar[BAR0].tag,    \                      sc->bar[BAR0].handle, \                      offset)
end_define

begin_define
define|#
directive|define
name|REG_RD32
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_4(sc->bar[BAR0].tag,    \                      sc->bar[BAR0].handle, \                      offset)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BXE_REG_NO_INLINE */
end_comment

begin_define
define|#
directive|define
name|REG_RD
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|REG_RD32(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_WR
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
value|REG_WR32(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|REG_RD_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bxe_reg_rd_ind(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_WR_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
value|bxe_reg_wr_ind(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|BXE_SP
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(&(sc)->sp->var)
end_define

begin_define
define|#
directive|define
name|BXE_SP_MAPPING
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
define|\
value|(sc->sp_dma.paddr + offsetof(struct bxe_slowpath, var))
end_define

begin_define
define|#
directive|define
name|BXE_FP
parameter_list|(
name|sc
parameter_list|,
name|nr
parameter_list|,
name|var
parameter_list|)
value|((sc)->fp[(nr)].var)
end_define

begin_define
define|#
directive|define
name|BXE_SP_OBJ
parameter_list|(
name|sc
parameter_list|,
name|fp
parameter_list|)
value|((sc)->sp_objs[(fp)->index])
end_define

begin_define
define|#
directive|define
name|REG_RD_DMAE
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|valp
parameter_list|,
name|len32
parameter_list|)
define|\
value|do {                                                   \         bxe_read_dmae(sc, offset, len32);                  \         memcpy(valp, BXE_SP(sc, wb_data[0]), (len32) * 4); \     } while (0)
end_define

begin_define
define|#
directive|define
name|REG_WR_DMAE
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|valp
parameter_list|,
name|len32
parameter_list|)
define|\
value|do {                                                                \         memcpy(BXE_SP(sc, wb_data[0]), valp, (len32) * 4);              \         bxe_write_dmae(sc, BXE_SP_MAPPING(sc, wb_data), offset, len32); \     } while (0)
end_define

begin_define
define|#
directive|define
name|REG_WR_DMAE_LEN
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|valp
parameter_list|,
name|len32
parameter_list|)
define|\
value|REG_WR_DMAE(sc, offset, valp, len32)
end_define

begin_define
define|#
directive|define
name|REG_RD_DMAE_LEN
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|valp
parameter_list|,
name|len32
parameter_list|)
define|\
value|REG_RD_DMAE(sc, offset, valp, len32)
end_define

begin_define
define|#
directive|define
name|VIRT_WR_DMAE_LEN
parameter_list|(
name|sc
parameter_list|,
name|data
parameter_list|,
name|addr
parameter_list|,
name|len32
parameter_list|,
name|le32_swap
parameter_list|)
define|\
value|do {                                                           \
comment|/* if (le32_swap) {                                     */
value|\
comment|/*    BLOGW(sc, "VIRT_WR_DMAE_LEN with le32_swap=1\n"); */
value|\
comment|/* }                                                    */
value|\         memcpy(GUNZIP_BUF(sc), data, len32 * 4);                   \         ecore_write_big_buf_wb(sc, addr, len32);                   \     } while (0)
end_define

begin_define
define|#
directive|define
name|BXE_DB_MIN_SHIFT
value|3
end_define

begin_comment
comment|/* 8 bytes */
end_comment

begin_define
define|#
directive|define
name|BXE_DB_SHIFT
value|7
end_define

begin_comment
comment|/* 128 bytes */
end_comment

begin_if
if|#
directive|if
operator|(
name|BXE_DB_SHIFT
operator|<
name|BXE_DB_MIN_SHIFT
operator|)
end_if

begin_error
error|#
directive|error
literal|"Minimum DB doorbell stride is 8"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DPM_TRIGGER_TYPE
value|0x40
end_define

begin_define
define|#
directive|define
name|DOORBELL
parameter_list|(
name|sc
parameter_list|,
name|cid
parameter_list|,
name|val
parameter_list|)
define|\
value|do {                                                                    \         bus_space_write_4(sc->bar[BAR1].tag, sc->bar[BAR1].handle,          \                           ((sc->doorbell_size * (cid)) + DPM_TRIGGER_TYPE), \                           (uint32_t)val);                                   \     } while(0)
end_define

begin_define
define|#
directive|define
name|SHMEM_ADDR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
define|\
value|(sc->devinfo.shmem_base + offsetof(struct shmem_region, field))
end_define

begin_define
define|#
directive|define
name|SHMEM_RD
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|REG_RD(sc, SHMEM_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|SHMEM_RD16
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|REG_RD16(sc, SHMEM_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|SHMEM_WR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
value|REG_WR(sc, SHMEM_ADDR(sc, field), val)
end_define

begin_define
define|#
directive|define
name|SHMEM2_ADDR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
define|\
value|(sc->devinfo.shmem2_base + offsetof(struct shmem2_region, field))
end_define

begin_define
define|#
directive|define
name|SHMEM2_HAS
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
define|\
value|(sc->devinfo.shmem2_base&& (REG_RD(sc, SHMEM2_ADDR(sc, size))>     \                                  offsetof(struct shmem2_region, field)))
end_define

begin_define
define|#
directive|define
name|SHMEM2_RD
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|REG_RD(sc, SHMEM2_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|SHMEM2_WR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
value|REG_WR(sc, SHMEM2_ADDR(sc, field), val)
end_define

begin_define
define|#
directive|define
name|MFCFG_ADDR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
define|\
value|(sc->devinfo.mf_cfg_base + offsetof(struct mf_cfg, field))
end_define

begin_define
define|#
directive|define
name|MFCFG_RD
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|REG_RD(sc, MFCFG_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|MFCFG_RD16
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|)
value|REG_RD16(sc, MFCFG_ADDR(sc, field))
end_define

begin_define
define|#
directive|define
name|MFCFG_WR
parameter_list|(
name|sc
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
value|REG_WR(sc, MFCFG_ADDR(sc, field), val)
end_define

begin_comment
comment|/* DMAE command defines */
end_comment

begin_define
define|#
directive|define
name|DMAE_TIMEOUT
value|-1
end_define

begin_define
define|#
directive|define
name|DMAE_PCI_ERROR
value|-2
end_define

begin_comment
comment|/* E2 and onward */
end_comment

begin_define
define|#
directive|define
name|DMAE_NOT_RDY
value|-3
end_define

begin_define
define|#
directive|define
name|DMAE_PCI_ERR_FLAG
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DMAE_SRC_PCI
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_SRC_GRC
value|1
end_define

begin_define
define|#
directive|define
name|DMAE_DST_NONE
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_DST_PCI
value|1
end_define

begin_define
define|#
directive|define
name|DMAE_DST_GRC
value|2
end_define

begin_define
define|#
directive|define
name|DMAE_COMP_PCI
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_COMP_GRC
value|1
end_define

begin_define
define|#
directive|define
name|DMAE_COMP_REGULAR
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_COM_SET_ERR
value|1
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_SRC_PCI
value|(DMAE_SRC_PCI<< DMAE_CMD_SRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_SRC_GRC
value|(DMAE_SRC_GRC<< DMAE_CMD_SRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_DST_PCI
value|(DMAE_DST_PCI<< DMAE_CMD_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_DST_GRC
value|(DMAE_DST_GRC<< DMAE_CMD_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_C_DST_PCI
value|(DMAE_COMP_PCI<< DMAE_CMD_C_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_C_DST_GRC
value|(DMAE_COMP_GRC<< DMAE_CMD_C_DST_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_NO_SWAP
value|(0<< DMAE_CMD_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_B_SWAP
value|(1<< DMAE_CMD_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_DW_SWAP
value|(2<< DMAE_CMD_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY_B_DW_SWAP
value|(3<< DMAE_CMD_ENDIANITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_PORT_0
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_PORT_1
value|DMAE_CMD_PORT
end_define

begin_define
define|#
directive|define
name|DMAE_SRC_PF
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_SRC_VF
value|1
end_define

begin_define
define|#
directive|define
name|DMAE_DST_PF
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_DST_VF
value|1
end_define

begin_define
define|#
directive|define
name|DMAE_C_SRC
value|0
end_define

begin_define
define|#
directive|define
name|DMAE_C_DST
value|1
end_define

begin_define
define|#
directive|define
name|DMAE_LEN32_RD_MAX
value|0x80
end_define

begin_define
define|#
directive|define
name|DMAE_LEN32_WR_MAX
parameter_list|(
name|sc
parameter_list|)
value|(CHIP_IS_E1(sc) ? 0x400 : 0x2000)
end_define

begin_define
define|#
directive|define
name|DMAE_COMP_VAL
value|0x60d0d0ae
end_define

begin_comment
comment|/* E2 and beyond, upper bit indicates error */
end_comment

begin_define
define|#
directive|define
name|MAX_DMAE_C_PER_PORT
value|8
end_define

begin_define
define|#
directive|define
name|INIT_DMAE_C
parameter_list|(
name|sc
parameter_list|)
value|((SC_PORT(sc) * MAX_DMAE_C_PER_PORT) + SC_VN(sc))
end_define

begin_define
define|#
directive|define
name|PMF_DMAE_C
parameter_list|(
name|sc
parameter_list|)
value|((SC_PORT(sc) * MAX_DMAE_C_PER_PORT) + E1HVN_MAX)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|dmae_reg_go_c
index|[]
init|=
block|{
name|DMAE_REG_GO_C0
block|,
name|DMAE_REG_GO_C1
block|,
name|DMAE_REG_GO_C2
block|,
name|DMAE_REG_GO_C3
block|,
name|DMAE_REG_GO_C4
block|,
name|DMAE_REG_GO_C5
block|,
name|DMAE_REG_GO_C6
block|,
name|DMAE_REG_GO_C7
block|,
name|DMAE_REG_GO_C8
block|,
name|DMAE_REG_GO_C9
block|,
name|DMAE_REG_GO_C10
block|,
name|DMAE_REG_GO_C11
block|,
name|DMAE_REG_GO_C12
block|,
name|DMAE_REG_GO_C13
block|,
name|DMAE_REG_GO_C14
block|,
name|DMAE_REG_GO_C15
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ATTN_NIG_FOR_FUNC
value|(1L<< 8)
end_define

begin_define
define|#
directive|define
name|ATTN_SW_TIMER_4_FUNC
value|(1L<< 9)
end_define

begin_define
define|#
directive|define
name|GPIO_2_FUNC
value|(1L<< 10)
end_define

begin_define
define|#
directive|define
name|GPIO_3_FUNC
value|(1L<< 11)
end_define

begin_define
define|#
directive|define
name|GPIO_4_FUNC
value|(1L<< 12)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_1
value|(1L<< 13)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_2
value|(1L<< 14)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_3
value|(1L<< 15)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_4
value|(1L<< 13)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_5
value|(1L<< 14)
end_define

begin_define
define|#
directive|define
name|ATTN_GENERAL_ATTN_6
value|(1L<< 15)
end_define

begin_define
define|#
directive|define
name|ATTN_HARD_WIRED_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|ATTENTION_ID
value|4
end_define

begin_define
define|#
directive|define
name|AEU_IN_ATTN_BITS_PXPPCICLOCKCLIENT_PARITY_ERROR
define|\
value|AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_PARITY_ERROR
end_define

begin_define
define|#
directive|define
name|MAX_IGU_ATTN_ACK_TO
value|100
end_define

begin_define
define|#
directive|define
name|STORM_ASSERT_ARRAY_SIZE
value|50
end_define

begin_define
define|#
directive|define
name|BXE_PMF_LINK_ASSERT
parameter_list|(
name|sc
parameter_list|)
define|\
value|GENERAL_ATTEN_OFFSET(LINK_SYNC_ATTENTION_BIT_FUNC_0 + SC_FUNC(sc))
end_define

begin_define
define|#
directive|define
name|BXE_MC_ASSERT_BITS
define|\
value|(GENERAL_ATTEN_OFFSET(TSTORM_FATAL_ASSERT_ATTENTION_BIT) | \      GENERAL_ATTEN_OFFSET(USTORM_FATAL_ASSERT_ATTENTION_BIT) | \      GENERAL_ATTEN_OFFSET(CSTORM_FATAL_ASSERT_ATTENTION_BIT) | \      GENERAL_ATTEN_OFFSET(XSTORM_FATAL_ASSERT_ATTENTION_BIT))
end_define

begin_define
define|#
directive|define
name|BXE_MCP_ASSERT
define|\
value|GENERAL_ATTEN_OFFSET(MCP_FATAL_ASSERT_ATTENTION_BIT)
end_define

begin_define
define|#
directive|define
name|BXE_GRC_TIMEOUT
value|GENERAL_ATTEN_OFFSET(LATCHED_ATTN_TIMEOUT_GRC)
end_define

begin_define
define|#
directive|define
name|BXE_GRC_RSV
value|(GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCR) | \                          GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCT) | \                          GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCN) | \                          GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCU) | \                          GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RBCP) | \                          GENERAL_ATTEN_OFFSET(LATCHED_ATTN_RSVD_GRC))
end_define

begin_define
define|#
directive|define
name|MULTI_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|PFS_PER_PORT
parameter_list|(
name|sc
parameter_list|)
define|\
value|((CHIP_PORT_MODE(sc) == CHIP_4_PORT_MODE) ? 2 : 4)
end_define

begin_define
define|#
directive|define
name|SC_MAX_VN_NUM
parameter_list|(
name|sc
parameter_list|)
value|PFS_PER_PORT(sc)
end_define

begin_define
define|#
directive|define
name|FIRST_ABS_FUNC_IN_PORT
parameter_list|(
name|sc
parameter_list|)
define|\
value|((CHIP_PORT_MODE(sc) == CHIP_PORT_MODE_NONE) ?    \      PORT_ID(sc) : (PATH_ID(sc) + (2 * PORT_ID(sc))))
end_define

begin_define
define|#
directive|define
name|FOREACH_ABS_FUNC_IN_PORT
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|for ((i) = FIRST_ABS_FUNC_IN_PORT(sc);         \          (i)< MAX_FUNC_NUM;                       \          (i) += (MAX_FUNC_NUM / PFS_PER_PORT(sc)))
end_define

begin_define
define|#
directive|define
name|BXE_SWCID_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|BXE_SWCID_MASK
value|((0x1<< BXE_SWCID_SHIFT) - 1)
end_define

begin_define
define|#
directive|define
name|SW_CID
parameter_list|(
name|x
parameter_list|)
value|(le32toh(x)& BXE_SWCID_MASK)
end_define

begin_define
define|#
directive|define
name|CQE_CMD
parameter_list|(
name|x
parameter_list|)
value|(le32toh(x)>> COMMON_RAMROD_ETH_RX_CQE_CMD_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|CQE_TYPE
parameter_list|(
name|cqe_fp_flags
parameter_list|)
value|((cqe_fp_flags)& ETH_FAST_PATH_RX_CQE_TYPE)
end_define

begin_define
define|#
directive|define
name|CQE_TYPE_START
parameter_list|(
name|cqe_type
parameter_list|)
value|((cqe_type) == RX_ETH_CQE_TYPE_ETH_START_AGG)
end_define

begin_define
define|#
directive|define
name|CQE_TYPE_STOP
parameter_list|(
name|cqe_type
parameter_list|)
value|((cqe_type) == RX_ETH_CQE_TYPE_ETH_STOP_AGG)
end_define

begin_define
define|#
directive|define
name|CQE_TYPE_SLOW
parameter_list|(
name|cqe_type
parameter_list|)
value|((cqe_type) == RX_ETH_CQE_TYPE_ETH_RAMROD)
end_define

begin_define
define|#
directive|define
name|CQE_TYPE_FAST
parameter_list|(
name|cqe_type
parameter_list|)
value|((cqe_type) == RX_ETH_CQE_TYPE_ETH_FASTPATH)
end_define

begin_comment
comment|/* must be used on a CID before placing it on a HW ring */
end_comment

begin_define
define|#
directive|define
name|HW_CID
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|((SC_PORT(sc)<< 23) | (SC_VN(sc)<< BXE_SWCID_SHIFT) | (x))
end_define

begin_define
define|#
directive|define
name|SPEED_10
value|10
end_define

begin_define
define|#
directive|define
name|SPEED_100
value|100
end_define

begin_define
define|#
directive|define
name|SPEED_1000
value|1000
end_define

begin_define
define|#
directive|define
name|SPEED_2500
value|2500
end_define

begin_define
define|#
directive|define
name|SPEED_10000
value|10000
end_define

begin_define
define|#
directive|define
name|PCI_PM_D0
value|1
end_define

begin_define
define|#
directive|define
name|PCI_PM_D3hot
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DUPLEX_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|DUPLEX_UNKNOWN
value|(0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SPEED_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|SPEED_UNKNOWN
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable or disable autonegotiation. */
end_comment

begin_define
define|#
directive|define
name|AUTONEG_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|AUTONEG_ENABLE
value|0x01
end_define

begin_comment
comment|/* Which connector port. */
end_comment

begin_define
define|#
directive|define
name|PORT_TP
value|0x00
end_define

begin_define
define|#
directive|define
name|PORT_AUI
value|0x01
end_define

begin_define
define|#
directive|define
name|PORT_MII
value|0x02
end_define

begin_define
define|#
directive|define
name|PORT_FIBRE
value|0x03
end_define

begin_define
define|#
directive|define
name|PORT_BNC
value|0x04
end_define

begin_define
define|#
directive|define
name|PORT_DA
value|0x05
end_define

begin_define
define|#
directive|define
name|PORT_NONE
value|0xef
end_define

begin_define
define|#
directive|define
name|PORT_OTHER
value|0xff
end_define

begin_function_decl
name|int
name|bxe_test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|unsigned
name|long
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_set_bit
parameter_list|(
name|unsigned
name|int
name|nr
parameter_list|,
specifier|volatile
name|unsigned
name|long
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|unsigned
name|long
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bxe_test_and_set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|unsigned
name|long
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bxe_test_and_clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|unsigned
name|long
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bxe_cmpxchg
parameter_list|(
specifier|volatile
name|int
modifier|*
name|addr
parameter_list|,
name|int
name|old
parameter_list|,
name|int
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_reg_wr_ind
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bxe_reg_rd_ind
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bxe_dma_alloc
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|struct
name|bxe_dma
modifier|*
name|dma
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_dma_free
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|bxe_dma
modifier|*
name|dma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bxe_dmae_opcode_add_comp
parameter_list|(
name|uint32_t
name|opcode
parameter_list|,
name|uint8_t
name|comp_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bxe_dmae_opcode_clr_src_reset
parameter_list|(
name|uint32_t
name|opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bxe_dmae_opcode
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|src_type
parameter_list|,
name|uint8_t
name|dst_type
parameter_list|,
name|uint8_t
name|with_comp
parameter_list|,
name|uint8_t
name|comp_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_post_dmae
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|dmae_cmd
modifier|*
name|dmae
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_read_dmae
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|src_addr
parameter_list|,
name|uint32_t
name|len32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_write_dmae
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_addr_t
name|dma_addr
parameter_list|,
name|uint32_t
name|dst_addr
parameter_list|,
name|uint32_t
name|len32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_write_dmae_phys_len
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bus_addr_t
name|phys_addr
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_set_ctx_validation
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|eth_context
modifier|*
name|cxt
parameter_list|,
name|uint32_t
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_update_coalesce_sb_index
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|fw_sb_id
parameter_list|,
name|uint8_t
name|sb_index
parameter_list|,
name|uint8_t
name|disable
parameter_list|,
name|uint16_t
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bxe_sp_post
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|int
name|command
parameter_list|,
name|int
name|cid
parameter_list|,
name|uint32_t
name|data_hi
parameter_list|,
name|uint32_t
name|data_lo
parameter_list|,
name|int
name|cmd_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_igu_ack_sb
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|igu_sb_id
parameter_list|,
name|uint8_t
name|segment
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|uint8_t
name|op
parameter_list|,
name|uint8_t
name|update
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_init_e1_firmware
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_init_e1h_firmware
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_init_e2_firmware
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_storm_memset_struct
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint32_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*********************/
end_comment

begin_comment
comment|/* LOGGING AND DEBUG */
end_comment

begin_comment
comment|/*********************/
end_comment

begin_comment
comment|/* debug logging codepaths */
end_comment

begin_define
define|#
directive|define
name|DBG_LOAD
value|0x00000001
end_define

begin_comment
comment|/* load and unload    */
end_comment

begin_define
define|#
directive|define
name|DBG_INTR
value|0x00000002
end_define

begin_comment
comment|/* interrupt handling */
end_comment

begin_define
define|#
directive|define
name|DBG_SP
value|0x00000004
end_define

begin_comment
comment|/* slowpath handling  */
end_comment

begin_define
define|#
directive|define
name|DBG_STATS
value|0x00000008
end_define

begin_comment
comment|/* stats updates      */
end_comment

begin_define
define|#
directive|define
name|DBG_TX
value|0x00000010
end_define

begin_comment
comment|/* packet transmit    */
end_comment

begin_define
define|#
directive|define
name|DBG_RX
value|0x00000020
end_define

begin_comment
comment|/* packet receive     */
end_comment

begin_define
define|#
directive|define
name|DBG_PHY
value|0x00000040
end_define

begin_comment
comment|/* phy/link handling  */
end_comment

begin_define
define|#
directive|define
name|DBG_IOCTL
value|0x00000080
end_define

begin_comment
comment|/* ioctl handling     */
end_comment

begin_define
define|#
directive|define
name|DBG_MBUF
value|0x00000100
end_define

begin_comment
comment|/* dumping mbuf info  */
end_comment

begin_define
define|#
directive|define
name|DBG_REGS
value|0x00000200
end_define

begin_comment
comment|/* register access    */
end_comment

begin_define
define|#
directive|define
name|DBG_LRO
value|0x00000400
end_define

begin_comment
comment|/* lro processing     */
end_comment

begin_define
define|#
directive|define
name|DBG_ASSERT
value|0x80000000
end_define

begin_comment
comment|/* debug assert       */
end_comment

begin_define
define|#
directive|define
name|DBG_ALL
value|0xFFFFFFFF
end_define

begin_comment
comment|/* flying monkeys     */
end_comment

begin_define
define|#
directive|define
name|DBASSERT
parameter_list|(
name|sc
parameter_list|,
name|exp
parameter_list|,
name|msg
parameter_list|)
define|\
value|do {                                               \         if (__predict_false(sc->debug& DBG_ASSERT)) { \             if (__predict_false(!(exp))) {             \                 panic msg;                             \             }                                          \         }                                              \     } while (0)
end_define

begin_comment
comment|/* log a debug message */
end_comment

begin_define
define|#
directive|define
name|BLOGD
parameter_list|(
name|sc
parameter_list|,
name|codepath
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {                                               \         if (__predict_false(sc->debug& (codepath))) { \             device_printf((sc)->dev,                   \                           "%s(%s:%d) " format,         \                           __FUNCTION__,                \                           __FILE__,                    \                           __LINE__,                    \                           ## args);                    \         }                                              \     } while(0)
end_define

begin_comment
comment|/* log a info message */
end_comment

begin_define
define|#
directive|define
name|BLOGI
parameter_list|(
name|sc
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {                                       \         if (__predict_false(sc->debug)) {      \             device_printf((sc)->dev,           \                           "%s(%s:%d) " format, \                           __FUNCTION__,        \                           __FILE__,            \                           __LINE__,            \                           ## args);            \         } else {                               \             device_printf((sc)->dev,           \                           format,              \                           ## args);            \         }                                      \     } while(0)
end_define

begin_comment
comment|/* log a warning message */
end_comment

begin_define
define|#
directive|define
name|BLOGW
parameter_list|(
name|sc
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {                                                \         if (__predict_false(sc->debug)) {               \             device_printf((sc)->dev,                    \                           "%s(%s:%d) WARNING: " format, \                           __FUNCTION__,                 \                           __FILE__,                     \                           __LINE__,                     \                           ## args);                     \         } else {                                        \             device_printf((sc)->dev,                    \                           "WARNING: " format,           \                           ## args);                     \         }                                               \     } while(0)
end_define

begin_comment
comment|/* log a error message */
end_comment

begin_define
define|#
directive|define
name|BLOGE
parameter_list|(
name|sc
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {                                              \         if (__predict_false(sc->debug)) {             \             device_printf((sc)->dev,                  \                           "%s(%s:%d) ERROR: " format, \                           __FUNCTION__,               \                           __FILE__,                   \                           __LINE__,                   \                           ## args);                   \         } else {                                      \             device_printf((sc)->dev,                  \                           "ERROR: " format,           \                           ## args);                   \         }                                             \     } while(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ECORE_STOP_ON_ERROR
end_ifdef

begin_define
define|#
directive|define
name|bxe_panic
parameter_list|(
name|sc
parameter_list|,
name|msg
parameter_list|)
define|\
value|do {                   \         panic msg;         \     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|bxe_panic
parameter_list|(
name|sc
parameter_list|,
name|msg
parameter_list|)
define|\
value|device_printf((sc)->dev, "%s (%s,%d)\n", __FUNCTION__, __FILE__, __LINE__);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CATC_TRIGGER
parameter_list|(
name|sc
parameter_list|,
name|data
parameter_list|)
value|REG_WR((sc), 0x2000, (data));
end_define

begin_define
define|#
directive|define
name|CATC_TRIGGER_START
parameter_list|(
name|sc
parameter_list|)
value|CATC_TRIGGER((sc), 0xcafecafe)
end_define

begin_function_decl
name|void
name|bxe_dump_mem
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|tag
parameter_list|,
name|uint8_t
modifier|*
name|mem
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_dump_mbuf_data
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|pTag
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint8_t
name|contents
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|800000
end_if

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|1001513
operator|&&
name|__FreeBSD_version
operator|<
literal|1100000
operator|)
operator|||
expr|\
name|__FreeBSD_version
operator|>=
literal|1100048
end_if

begin_define
define|#
directive|define
name|BXE_SET_FLOWID
parameter_list|(
name|m
parameter_list|)
value|M_HASHTYPE_SET(m, M_HASHTYPE_OPAQUE)
end_define

begin_define
define|#
directive|define
name|BXE_VALID_FLOWID
parameter_list|(
name|m
parameter_list|)
value|(M_HASHTYPE_GET(m) != M_HASHTYPE_NONE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BXE_VALID_FLOWID
parameter_list|(
name|m
parameter_list|)
value|((m->m_flags& M_FLOWID) != 0)
end_define

begin_define
define|#
directive|define
name|BXE_SET_FLOWID
parameter_list|(
name|m
parameter_list|)
value|m->m_flags |= M_FLOWID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if __FreeBSD_version>= 800000 */
end_comment

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/* INLINES */
end_comment

begin_comment
comment|/***********/
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|reg_poll
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|expected
parameter_list|,
name|int
name|ms
parameter_list|,
name|int
name|wait
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
do|do
block|{
name|val
operator|=
name|REG_RD
argument_list|(
name|sc
argument_list|,
name|reg
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
name|expected
condition|)
block|{
break|break;
block|}
name|ms
operator|-=
name|wait
expr_stmt|;
name|DELAY
argument_list|(
name|wait
operator|*
literal|1000
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|ms
operator|>
literal|0
condition|)
do|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|bxe_update_fp_sb_idx
parameter_list|(
name|struct
name|bxe_fastpath
modifier|*
name|fp
parameter_list|)
block|{
name|mb
argument_list|()
expr_stmt|;
comment|/* status block is written to by the chip */
name|fp
operator|->
name|fp_hc_idx
operator|=
name|fp
operator|->
name|sb_running_index
index|[
name|SM_RX_ID
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|bxe_igu_ack_sb_gen
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|igu_sb_id
parameter_list|,
name|uint8_t
name|segment
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|uint8_t
name|op
parameter_list|,
name|uint8_t
name|update
parameter_list|,
name|uint32_t
name|igu_addr
parameter_list|)
block|{
name|struct
name|igu_regular
name|cmd_data
init|=
block|{
literal|0
block|}
decl_stmt|;
name|cmd_data
operator|.
name|sb_id_and_flags
operator|=
operator|(
operator|(
name|index
operator|<<
name|IGU_REGULAR_SB_INDEX_SHIFT
operator|)
operator||
operator|(
name|segment
operator|<<
name|IGU_REGULAR_SEGMENT_ACCESS_SHIFT
operator|)
operator||
operator|(
name|update
operator|<<
name|IGU_REGULAR_BUPDATE_SHIFT
operator|)
operator||
operator|(
name|op
operator|<<
name|IGU_REGULAR_ENABLE_INT_SHIFT
operator|)
operator|)
expr_stmt|;
name|BLOGD
argument_list|(
name|sc
argument_list|,
name|DBG_INTR
argument_list|,
literal|"write 0x%08x to IGU addr 0x%x\n"
argument_list|,
name|cmd_data
operator|.
name|sb_id_and_flags
argument_list|,
name|igu_addr
argument_list|)
expr_stmt|;
name|REG_WR
argument_list|(
name|sc
argument_list|,
name|igu_addr
argument_list|,
name|cmd_data
operator|.
name|sb_id_and_flags
argument_list|)
expr_stmt|;
comment|/* Make sure that ACK is written */
name|bus_space_barrier
argument_list|(
name|sc
operator|->
name|bar
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|sc
operator|->
name|bar
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|BUS_SPACE_BARRIER_WRITE
argument_list|)
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|bxe_hc_ack_sb
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|sb_id
parameter_list|,
name|uint8_t
name|storm
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|uint8_t
name|op
parameter_list|,
name|uint8_t
name|update
parameter_list|)
block|{
name|uint32_t
name|hc_addr
init|=
operator|(
name|HC_REG_COMMAND_REG
operator|+
name|SC_PORT
argument_list|(
name|sc
argument_list|)
operator|*
literal|32
operator|+
name|COMMAND_REG_INT_ACK
operator|)
decl_stmt|;
name|struct
name|igu_ack_register
name|igu_ack
decl_stmt|;
name|igu_ack
operator|.
name|status_block_index
operator|=
name|index
expr_stmt|;
name|igu_ack
operator|.
name|sb_id_and_flags
operator|=
operator|(
operator|(
name|sb_id
operator|<<
name|IGU_ACK_REGISTER_STATUS_BLOCK_ID_SHIFT
operator|)
operator||
operator|(
name|storm
operator|<<
name|IGU_ACK_REGISTER_STORM_ID_SHIFT
operator|)
operator||
operator|(
name|update
operator|<<
name|IGU_ACK_REGISTER_UPDATE_INDEX_SHIFT
operator|)
operator||
operator|(
name|op
operator|<<
name|IGU_ACK_REGISTER_INTERRUPT_MODE_SHIFT
operator|)
operator|)
expr_stmt|;
name|REG_WR
argument_list|(
name|sc
argument_list|,
name|hc_addr
argument_list|,
operator|(
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|igu_ack
operator|)
argument_list|)
expr_stmt|;
comment|/* Make sure that ACK is written */
name|bus_space_barrier
argument_list|(
name|sc
operator|->
name|bar
index|[
literal|0
index|]
operator|.
name|tag
argument_list|,
name|sc
operator|->
name|bar
index|[
literal|0
index|]
operator|.
name|handle
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|BUS_SPACE_BARRIER_WRITE
argument_list|)
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|bxe_ack_sb
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|igu_sb_id
parameter_list|,
name|uint8_t
name|storm
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|uint8_t
name|op
parameter_list|,
name|uint8_t
name|update
parameter_list|)
block|{
if|if
condition|(
name|sc
operator|->
name|devinfo
operator|.
name|int_block
operator|==
name|INT_BLOCK_HC
condition|)
name|bxe_hc_ack_sb
argument_list|(
name|sc
argument_list|,
name|igu_sb_id
argument_list|,
name|storm
argument_list|,
name|index
argument_list|,
name|op
argument_list|,
name|update
argument_list|)
expr_stmt|;
else|else
block|{
name|uint8_t
name|segment
decl_stmt|;
if|if
condition|(
name|CHIP_INT_MODE_IS_BC
argument_list|(
name|sc
argument_list|)
condition|)
block|{
name|segment
operator|=
name|storm
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|igu_sb_id
operator|!=
name|sc
operator|->
name|igu_dsb_id
condition|)
block|{
name|segment
operator|=
name|IGU_SEG_ACCESS_DEF
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|storm
operator|==
name|ATTENTION_ID
condition|)
block|{
name|segment
operator|=
name|IGU_SEG_ACCESS_ATTN
expr_stmt|;
block|}
else|else
block|{
name|segment
operator|=
name|IGU_SEG_ACCESS_DEF
expr_stmt|;
block|}
name|bxe_igu_ack_sb
argument_list|(
name|sc
argument_list|,
name|igu_sb_id
argument_list|,
name|segment
argument_list|,
name|index
argument_list|,
name|op
argument_list|,
name|update
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|bxe_hc_ack_int
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
block|{
name|uint32_t
name|hc_addr
init|=
operator|(
name|HC_REG_COMMAND_REG
operator|+
name|SC_PORT
argument_list|(
name|sc
argument_list|)
operator|*
literal|32
operator|+
name|COMMAND_REG_SIMD_MASK
operator|)
decl_stmt|;
name|uint32_t
name|result
init|=
name|REG_RD
argument_list|(
name|sc
argument_list|,
name|hc_addr
argument_list|)
decl_stmt|;
name|mb
argument_list|()
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|bxe_igu_ack_int
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
block|{
name|uint32_t
name|igu_addr
init|=
operator|(
name|BAR_IGU_INTMEM
operator|+
name|IGU_REG_SISR_MDPC_WMASK_LSB_UPPER
operator|*
literal|8
operator|)
decl_stmt|;
name|uint32_t
name|result
init|=
name|REG_RD
argument_list|(
name|sc
argument_list|,
name|igu_addr
argument_list|)
decl_stmt|;
name|BLOGD
argument_list|(
name|sc
argument_list|,
name|DBG_INTR
argument_list|,
literal|"read 0x%08x from IGU addr 0x%x\n"
argument_list|,
name|result
argument_list|,
name|igu_addr
argument_list|)
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|bxe_ack_int
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
block|{
name|mb
argument_list|()
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|devinfo
operator|.
name|int_block
operator|==
name|INT_BLOCK_HC
condition|)
block|{
return|return
operator|(
name|bxe_hc_ack_int
argument_list|(
name|sc
argument_list|)
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
name|bxe_igu_ack_int
argument_list|(
name|sc
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|func_by_vn
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|int
name|vn
parameter_list|)
block|{
return|return
operator|(
literal|2
operator|*
name|vn
operator|+
name|SC_PORT
argument_list|(
name|sc
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Statistics ID are global per chip/path, while Client IDs for E1x  * are per port.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|bxe_stats_id
parameter_list|(
name|struct
name|bxe_fastpath
modifier|*
name|fp
parameter_list|)
block|{
name|struct
name|bxe_softc
modifier|*
name|sc
init|=
name|fp
operator|->
name|sc
decl_stmt|;
if|if
condition|(
operator|!
name|CHIP_IS_E1x
argument_list|(
name|sc
argument_list|)
condition|)
block|{
return|return
operator|(
name|fp
operator|->
name|cl_id
operator|)
return|;
block|}
return|return
operator|(
name|fp
operator|->
name|cl_id
operator|+
name|SC_PORT
argument_list|(
name|sc
argument_list|)
operator|*
name|FP_SB_MAX_E1x
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BXE_H__ */
end_comment

end_unit

