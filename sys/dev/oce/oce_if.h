begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2013 Emulex  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Emulex Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * Contact Information:  * freebsd-drivers@emulex.com  *  * Emulex  * 3333 Susan Street  * Costa Mesa, CA 92626  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
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
file|<sys/sockopt.h>
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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/firmware.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
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
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
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
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
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
file|<netinet6/in6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_mroute.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_lro.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|"oce_hw.h"
end_include

begin_comment
comment|/* OCE device driver module component revision informaiton */
end_comment

begin_define
define|#
directive|define
name|COMPONENT_REVISION
value|"10.0.664.0"
end_define

begin_comment
comment|/* OCE devices supported by this driver */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_EMULEX
value|0x10df
end_define

begin_comment
comment|/* Emulex */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_SERVERENGINES
value|0x19a2
end_define

begin_comment
comment|/* ServerEngines (BE) */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BE2
value|0x0700
end_define

begin_comment
comment|/* BE2 network adapter */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BE3
value|0x0710
end_define

begin_comment
comment|/* BE3 network adapter */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_XE201
value|0xe220
end_define

begin_comment
comment|/* XE201 network adapter */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_XE201_VF
value|0xe228
end_define

begin_comment
comment|/* XE201 with VF in Lancer */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_SH
value|0x0720
end_define

begin_comment
comment|/* Skyhawk network adapter */
end_comment

begin_define
define|#
directive|define
name|IS_BE
parameter_list|(
name|sc
parameter_list|)
value|(((sc->flags& OCE_FLAGS_BE3) | \ 			 (sc->flags& OCE_FLAGS_BE2))? 1:0)
end_define

begin_define
define|#
directive|define
name|IS_BE3
parameter_list|(
name|sc
parameter_list|)
value|(sc->flags& OCE_FLAGS_BE3)
end_define

begin_define
define|#
directive|define
name|IS_BE2
parameter_list|(
name|sc
parameter_list|)
value|(sc->flags& OCE_FLAGS_BE2)
end_define

begin_define
define|#
directive|define
name|IS_XE201
parameter_list|(
name|sc
parameter_list|)
value|((sc->flags& OCE_FLAGS_XE201) ? 1:0)
end_define

begin_define
define|#
directive|define
name|HAS_A0_CHIP
parameter_list|(
name|sc
parameter_list|)
value|((sc->flags& OCE_FLAGS_HAS_A0_CHIP) ? 1:0)
end_define

begin_define
define|#
directive|define
name|IS_SH
parameter_list|(
name|sc
parameter_list|)
value|((sc->flags& OCE_FLAGS_SH) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|is_be_mode_mc
parameter_list|(
name|sc
parameter_list|)
value|((sc->function_mode& FNM_FLEX10_MODE) ||	\ 				(sc->function_mode& FNM_UMC_MODE)    ||	\ 				(sc->function_mode& FNM_VNIC_MODE))
end_define

begin_define
define|#
directive|define
name|OCE_FUNCTION_CAPS_SUPER_NIC
value|0x40
end_define

begin_define
define|#
directive|define
name|IS_PROFILE_SUPER_NIC
parameter_list|(
name|sc
parameter_list|)
value|(sc->function_caps& OCE_FUNCTION_CAPS_SUPER_NIC)
end_define

begin_comment
comment|/* proportion Service Level Interface queues */
end_comment

begin_define
define|#
directive|define
name|OCE_MAX_UNITS
value|2
end_define

begin_define
define|#
directive|define
name|OCE_MAX_PPORT
value|OCE_MAX_UNITS
end_define

begin_define
define|#
directive|define
name|OCE_MAX_VPORT
value|OCE_MAX_UNITS
end_define

begin_decl_stmt
specifier|extern
name|int
name|mp_ncpus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system's total active cpu cores */
end_comment

begin_define
define|#
directive|define
name|OCE_NCPUS
value|mp_ncpus
end_define

begin_comment
comment|/* This should be powers of 2. Like 2,4,8& 16 */
end_comment

begin_define
define|#
directive|define
name|OCE_MAX_RSS
value|8
end_define

begin_define
define|#
directive|define
name|OCE_LEGACY_MODE_RSS
value|4
end_define

begin_comment
comment|/* For BE3 Legacy mode*/
end_comment

begin_define
define|#
directive|define
name|is_rss_enabled
parameter_list|(
name|sc
parameter_list|)
value|((sc->function_caps& FNC_RSS)&& !is_be_mode_mc(sc))
end_define

begin_define
define|#
directive|define
name|OCE_MIN_RQ
value|1
end_define

begin_define
define|#
directive|define
name|OCE_MIN_WQ
value|1
end_define

begin_define
define|#
directive|define
name|OCE_MAX_RQ
value|OCE_MAX_RSS + 1
end_define

begin_comment
comment|/* one default queue */
end_comment

begin_define
define|#
directive|define
name|OCE_MAX_WQ
value|8
end_define

begin_define
define|#
directive|define
name|OCE_MAX_EQ
value|32
end_define

begin_define
define|#
directive|define
name|OCE_MAX_CQ
value|OCE_MAX_RQ + OCE_MAX_WQ + 1
end_define

begin_comment
comment|/* one MCC queue */
end_comment

begin_define
define|#
directive|define
name|OCE_MAX_CQ_EQ
value|8
end_define

begin_comment
comment|/* Max CQ that can attached to an EQ */
end_comment

begin_define
define|#
directive|define
name|OCE_DEFAULT_WQ_EQD
value|16
end_define

begin_define
define|#
directive|define
name|OCE_MAX_PACKET_Q
value|16
end_define

begin_define
define|#
directive|define
name|OCE_RQ_BUF_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|OCE_LSO_MAX_SIZE
value|(64 * 1024)
end_define

begin_define
define|#
directive|define
name|LONG_TIMEOUT
value|30
end_define

begin_define
define|#
directive|define
name|OCE_MAX_JUMBO_FRAME_SIZE
value|9018
end_define

begin_define
define|#
directive|define
name|OCE_MAX_MTU
value|(OCE_MAX_JUMBO_FRAME_SIZE - \ 						ETHER_VLAN_ENCAP_LEN - \ 						ETHER_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|OCE_MAX_TX_ELEMENTS
value|29
end_define

begin_define
define|#
directive|define
name|OCE_MAX_TX_DESC
value|1024
end_define

begin_define
define|#
directive|define
name|OCE_MAX_TX_SIZE
value|65535
end_define

begin_define
define|#
directive|define
name|OCE_MAX_RX_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|OCE_MAX_RQ_POSTS
value|255
end_define

begin_define
define|#
directive|define
name|OCE_DEFAULT_PROMISCUOUS
value|0
end_define

begin_define
define|#
directive|define
name|RSS_ENABLE_IPV4
value|0x1
end_define

begin_define
define|#
directive|define
name|RSS_ENABLE_TCP_IPV4
value|0x2
end_define

begin_define
define|#
directive|define
name|RSS_ENABLE_IPV6
value|0x4
end_define

begin_define
define|#
directive|define
name|RSS_ENABLE_TCP_IPV6
value|0x8
end_define

begin_define
define|#
directive|define
name|INDIRECTION_TABLE_ENTRIES
value|128
end_define

begin_comment
comment|/* flow control definitions */
end_comment

begin_define
define|#
directive|define
name|OCE_FC_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|OCE_FC_TX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OCE_FC_RX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OCE_DEFAULT_FLOW_CONTROL
value|(OCE_FC_TX | OCE_FC_RX)
end_define

begin_comment
comment|/* Interface capabilities to give device when creating interface */
end_comment

begin_define
define|#
directive|define
name|OCE_CAPAB_FLAGS
value|(MBX_RX_IFACE_FLAGS_BROADCAST    | \ 					MBX_RX_IFACE_FLAGS_UNTAGGED      | \ 					MBX_RX_IFACE_FLAGS_PROMISCUOUS      | \ 					MBX_RX_IFACE_FLAGS_VLAN_PROMISCUOUS |	\ 					MBX_RX_IFACE_FLAGS_MCAST_PROMISCUOUS   | \ 					MBX_RX_IFACE_FLAGS_RSS | \ 					MBX_RX_IFACE_FLAGS_PASS_L3L4_ERR)
end_define

begin_comment
comment|/* Interface capabilities to enable by default (others set dynamically) */
end_comment

begin_define
define|#
directive|define
name|OCE_CAPAB_ENABLE
value|(MBX_RX_IFACE_FLAGS_BROADCAST | \ 					MBX_RX_IFACE_FLAGS_UNTAGGED   | \ 					MBX_RX_IFACE_FLAGS_PASS_L3L4_ERR)
end_define

begin_define
define|#
directive|define
name|OCE_IF_HWASSIST
value|(CSUM_IP | CSUM_TCP | CSUM_UDP)
end_define

begin_define
define|#
directive|define
name|OCE_IF_CAPABILITIES
value|(IFCAP_VLAN_MTU | IFCAP_VLAN_HWTAGGING | \ 					IFCAP_HWCSUM | IFCAP_VLAN_HWCSUM | \ 					IFCAP_JUMBO_MTU | IFCAP_VLAN_MTU)
end_define

begin_define
define|#
directive|define
name|OCE_IF_HWASSIST_NONE
value|0
end_define

begin_define
define|#
directive|define
name|OCE_IF_CAPABILITIES_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ETH_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MAX_VLANFILTER_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|MAX_VLANS
value|4096
end_define

begin_define
define|#
directive|define
name|upper_32_bits
parameter_list|(
name|n
parameter_list|)
value|((uint32_t)(((n)>> 16)>> 16))
end_define

begin_define
define|#
directive|define
name|BSWAP_8
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|BSWAP_16
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_8(x)<< 8) | BSWAP_8((x)>> 8))
end_define

begin_define
define|#
directive|define
name|BSWAP_32
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_16(x)<< 16) | \ 					 BSWAP_16((x)>> 16))
end_define

begin_define
define|#
directive|define
name|BSWAP_64
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_32(x)<< 32) | \ 					BSWAP_32((x)>> 32))
end_define

begin_define
define|#
directive|define
name|for_all_wq_queues
parameter_list|(
name|sc
parameter_list|,
name|wq
parameter_list|,
name|i
parameter_list|)
define|\
value|for (i = 0, wq = sc->wq[0]; i< sc->nwqs; i++, wq = sc->wq[i])
end_define

begin_define
define|#
directive|define
name|for_all_rq_queues
parameter_list|(
name|sc
parameter_list|,
name|rq
parameter_list|,
name|i
parameter_list|)
define|\
value|for (i = 0, rq = sc->rq[0]; i< sc->nrqs; i++, rq = sc->rq[i])
end_define

begin_define
define|#
directive|define
name|for_all_rss_queues
parameter_list|(
name|sc
parameter_list|,
name|rq
parameter_list|,
name|i
parameter_list|)
define|\
value|for (i = 0, rq = sc->rq[i + 1]; i< (sc->nrqs - 1); \ 		     i++, rq = sc->rq[i + 1])
end_define

begin_define
define|#
directive|define
name|for_all_evnt_queues
parameter_list|(
name|sc
parameter_list|,
name|eq
parameter_list|,
name|i
parameter_list|)
define|\
value|for (i = 0, eq = sc->eq[0]; i< sc->neqs; i++, eq = sc->eq[i])
end_define

begin_define
define|#
directive|define
name|for_all_cq_queues
parameter_list|(
name|sc
parameter_list|,
name|cq
parameter_list|,
name|i
parameter_list|)
define|\
value|for (i = 0, cq = sc->cq[0]; i< sc->ncqs; i++, cq = sc->cq[i])
end_define

begin_comment
comment|/* Flash specific */
end_comment

begin_define
define|#
directive|define
name|IOCTL_COOKIE
value|"SERVERENGINES CORP"
end_define

begin_define
define|#
directive|define
name|MAX_FLASH_COMP
value|32
end_define

begin_define
define|#
directive|define
name|IMG_ISCSI
value|160
end_define

begin_define
define|#
directive|define
name|IMG_REDBOOT
value|224
end_define

begin_define
define|#
directive|define
name|IMG_BIOS
value|34
end_define

begin_define
define|#
directive|define
name|IMG_PXEBIOS
value|32
end_define

begin_define
define|#
directive|define
name|IMG_FCOEBIOS
value|33
end_define

begin_define
define|#
directive|define
name|IMG_ISCSI_BAK
value|176
end_define

begin_define
define|#
directive|define
name|IMG_FCOE
value|162
end_define

begin_define
define|#
directive|define
name|IMG_FCOE_BAK
value|178
end_define

begin_define
define|#
directive|define
name|IMG_NCSI
value|16
end_define

begin_define
define|#
directive|define
name|IMG_PHY
value|192
end_define

begin_define
define|#
directive|define
name|FLASHROM_OPER_FLASH
value|1
end_define

begin_define
define|#
directive|define
name|FLASHROM_OPER_SAVE
value|2
end_define

begin_define
define|#
directive|define
name|FLASHROM_OPER_REPORT
value|4
end_define

begin_define
define|#
directive|define
name|FLASHROM_OPER_FLASH_PHY
value|9
end_define

begin_define
define|#
directive|define
name|FLASHROM_OPER_SAVE_PHY
value|10
end_define

begin_define
define|#
directive|define
name|TN_8022
value|13
end_define

begin_enum
enum|enum
block|{
name|PHY_TYPE_CX4_10GB
init|=
literal|0
block|,
name|PHY_TYPE_XFP_10GB
block|,
name|PHY_TYPE_SFP_1GB
block|,
name|PHY_TYPE_SFP_PLUS_10GB
block|,
name|PHY_TYPE_KR_10GB
block|,
name|PHY_TYPE_KX4_10GB
block|,
name|PHY_TYPE_BASET_10GB
block|,
name|PHY_TYPE_BASET_1GB
block|,
name|PHY_TYPE_BASEX_1GB
block|,
name|PHY_TYPE_SGMII
block|,
name|PHY_TYPE_DISABLED
init|=
literal|255
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief Define and hold all necessary info for a single interrupt  */
end_comment

begin_define
define|#
directive|define
name|OCE_MAX_MSI
value|32
end_define

begin_comment
comment|/* Message Signaled Interrupts */
end_comment

begin_define
define|#
directive|define
name|OCE_MAX_MSIX
value|2048
end_define

begin_comment
comment|/* PCI Express MSI Interrrupts */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|oce_intr_info
block|{
name|void
modifier|*
name|tag
decl_stmt|;
comment|/* cookie returned by bus_setup_intr */
name|struct
name|resource
modifier|*
name|intr_res
decl_stmt|;
comment|/* PCI resource container */
name|int
name|irq_rr
decl_stmt|;
comment|/* resource id for the interrupt */
name|struct
name|oce_softc
modifier|*
name|sc
decl_stmt|;
comment|/* pointer to the parent soft c */
name|struct
name|oce_eq
modifier|*
name|eq
decl_stmt|;
comment|/* pointer to the connected EQ */
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* Associated task queue */
name|struct
name|task
name|task
decl_stmt|;
comment|/* task queue task */
name|char
name|task_name
index|[
literal|32
index|]
decl_stmt|;
comment|/* task name */
name|int
name|vector
decl_stmt|;
comment|/* interrupt vector number */
block|}
name|OCE_INTR_INFO
operator|,
typedef|*
name|POCE_INTR_INFO
typedef|;
end_typedef

begin_comment
comment|/* Ring related */
end_comment

begin_define
define|#
directive|define
name|GET_Q_NEXT
parameter_list|(
name|_START
parameter_list|,
name|_STEP
parameter_list|,
name|_END
parameter_list|)
define|\
value|(((_START) + (_STEP))< (_END) ? ((_START) + (_STEP)) \ 	: (((_START) + (_STEP)) - (_END)))
end_define

begin_define
define|#
directive|define
name|DBUF_PA
parameter_list|(
name|obj
parameter_list|)
value|((obj)->addr)
end_define

begin_define
define|#
directive|define
name|DBUF_VA
parameter_list|(
name|obj
parameter_list|)
value|((obj)->ptr)
end_define

begin_define
define|#
directive|define
name|DBUF_TAG
parameter_list|(
name|obj
parameter_list|)
value|((obj)->tag)
end_define

begin_define
define|#
directive|define
name|DBUF_MAP
parameter_list|(
name|obj
parameter_list|)
value|((obj)->map)
end_define

begin_define
define|#
directive|define
name|DBUF_SYNC
parameter_list|(
name|obj
parameter_list|,
name|flags
parameter_list|)
define|\
value|(void) bus_dmamap_sync(DBUF_TAG(obj), DBUF_MAP(obj), (flags))
end_define

begin_define
define|#
directive|define
name|RING_NUM_PENDING
parameter_list|(
name|ring
parameter_list|)
value|ring->num_used
end_define

begin_define
define|#
directive|define
name|RING_FULL
parameter_list|(
name|ring
parameter_list|)
value|(ring->num_used == ring->num_items)
end_define

begin_define
define|#
directive|define
name|RING_EMPTY
parameter_list|(
name|ring
parameter_list|)
value|(ring->num_used == 0)
end_define

begin_define
define|#
directive|define
name|RING_NUM_FREE
parameter_list|(
name|ring
parameter_list|)
define|\
value|(uint32_t)(ring->num_items - ring->num_used)
end_define

begin_define
define|#
directive|define
name|RING_GET
parameter_list|(
name|ring
parameter_list|,
name|n
parameter_list|)
define|\
value|ring->cidx = GET_Q_NEXT(ring->cidx, n, ring->num_items)
end_define

begin_define
define|#
directive|define
name|RING_PUT
parameter_list|(
name|ring
parameter_list|,
name|n
parameter_list|)
define|\
value|ring->pidx = GET_Q_NEXT(ring->pidx, n, ring->num_items)
end_define

begin_define
define|#
directive|define
name|RING_GET_CONSUMER_ITEM_VA
parameter_list|(
name|ring
parameter_list|,
name|type
parameter_list|)
define|\
value|(void*)((type *)DBUF_VA(&ring->dma) + ring->cidx)
end_define

begin_define
define|#
directive|define
name|RING_GET_CONSUMER_ITEM_PA
parameter_list|(
name|ring
parameter_list|,
name|type
parameter_list|)
define|\
value|(uint64_t)(((type *)DBUF_PA(ring->dbuf)) + ring->cidx)
end_define

begin_define
define|#
directive|define
name|RING_GET_PRODUCER_ITEM_VA
parameter_list|(
name|ring
parameter_list|,
name|type
parameter_list|)
define|\
value|(void *)(((type *)DBUF_VA(&ring->dma)) + ring->pidx)
end_define

begin_define
define|#
directive|define
name|RING_GET_PRODUCER_ITEM_PA
parameter_list|(
name|ring
parameter_list|,
name|type
parameter_list|)
define|\
value|(uint64_t)(((type *)DBUF_PA(ring->dbuf)) + ring->pidx)
end_define

begin_define
define|#
directive|define
name|OCE_DMAPTR
parameter_list|(
name|o
parameter_list|,
name|c
parameter_list|)
value|((c *)(o)->ptr)
end_define

begin_struct
struct|struct
name|oce_packet_desc
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|int
name|nsegs
decl_stmt|;
name|uint32_t
name|wqe_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|oce_dma_mem
block|{
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
name|bus_addr_t
name|paddr
decl_stmt|;
block|}
name|OCE_DMA_MEM
operator|,
typedef|*
name|POCE_DMA_MEM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|oce_ring_buffer_s
block|{
name|uint16_t
name|cidx
decl_stmt|;
comment|/* Get ptr */
name|uint16_t
name|pidx
decl_stmt|;
comment|/* Put Ptr */
name|size_t
name|item_size
decl_stmt|;
name|size_t
name|num_items
decl_stmt|;
name|uint32_t
name|num_used
decl_stmt|;
name|OCE_DMA_MEM
name|dma
decl_stmt|;
block|}
name|oce_ring_buffer_t
typedef|;
end_typedef

begin_comment
comment|/* Stats */
end_comment

begin_define
define|#
directive|define
name|OCE_UNICAST_PACKET
value|0
end_define

begin_define
define|#
directive|define
name|OCE_MULTICAST_PACKET
value|1
end_define

begin_define
define|#
directive|define
name|OCE_BROADCAST_PACKET
value|2
end_define

begin_define
define|#
directive|define
name|OCE_RSVD_PACKET
value|3
end_define

begin_struct
struct|struct
name|oce_rx_stats
block|{
comment|/* Total Receive Stats*/
name|uint64_t
name|t_rx_pkts
decl_stmt|;
name|uint64_t
name|t_rx_bytes
decl_stmt|;
name|uint32_t
name|t_rx_frags
decl_stmt|;
name|uint32_t
name|t_rx_mcast_pkts
decl_stmt|;
name|uint32_t
name|t_rx_ucast_pkts
decl_stmt|;
name|uint32_t
name|t_rxcp_errs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_tx_stats
block|{
comment|/*Total Transmit Stats */
name|uint64_t
name|t_tx_pkts
decl_stmt|;
name|uint64_t
name|t_tx_bytes
decl_stmt|;
name|uint32_t
name|t_tx_reqs
decl_stmt|;
name|uint32_t
name|t_tx_stops
decl_stmt|;
name|uint32_t
name|t_tx_wrbs
decl_stmt|;
name|uint32_t
name|t_tx_compl
decl_stmt|;
name|uint32_t
name|t_ipv6_ext_hdr_tx_drop
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_be_stats
block|{
name|uint8_t
name|be_on_die_temperature
decl_stmt|;
name|uint32_t
name|be_tx_events
decl_stmt|;
name|uint32_t
name|eth_red_drops
decl_stmt|;
name|uint32_t
name|rx_drops_no_pbuf
decl_stmt|;
name|uint32_t
name|rx_drops_no_txpb
decl_stmt|;
name|uint32_t
name|rx_drops_no_erx_descr
decl_stmt|;
name|uint32_t
name|rx_drops_no_tpre_descr
decl_stmt|;
name|uint32_t
name|rx_drops_too_many_frags
decl_stmt|;
name|uint32_t
name|rx_drops_invalid_ring
decl_stmt|;
name|uint32_t
name|forwarded_packets
decl_stmt|;
name|uint32_t
name|rx_drops_mtu
decl_stmt|;
name|uint32_t
name|rx_crc_errors
decl_stmt|;
name|uint32_t
name|rx_alignment_symbol_errors
decl_stmt|;
name|uint32_t
name|rx_pause_frames
decl_stmt|;
name|uint32_t
name|rx_priority_pause_frames
decl_stmt|;
name|uint32_t
name|rx_control_frames
decl_stmt|;
name|uint32_t
name|rx_in_range_errors
decl_stmt|;
name|uint32_t
name|rx_out_range_errors
decl_stmt|;
name|uint32_t
name|rx_frame_too_long
decl_stmt|;
name|uint32_t
name|rx_address_match_errors
decl_stmt|;
name|uint32_t
name|rx_dropped_too_small
decl_stmt|;
name|uint32_t
name|rx_dropped_too_short
decl_stmt|;
name|uint32_t
name|rx_dropped_header_too_small
decl_stmt|;
name|uint32_t
name|rx_dropped_tcp_length
decl_stmt|;
name|uint32_t
name|rx_dropped_runt
decl_stmt|;
name|uint32_t
name|rx_ip_checksum_errs
decl_stmt|;
name|uint32_t
name|rx_tcp_checksum_errs
decl_stmt|;
name|uint32_t
name|rx_udp_checksum_errs
decl_stmt|;
name|uint32_t
name|rx_switched_unicast_packets
decl_stmt|;
name|uint32_t
name|rx_switched_multicast_packets
decl_stmt|;
name|uint32_t
name|rx_switched_broadcast_packets
decl_stmt|;
name|uint32_t
name|tx_pauseframes
decl_stmt|;
name|uint32_t
name|tx_priority_pauseframes
decl_stmt|;
name|uint32_t
name|tx_controlframes
decl_stmt|;
name|uint32_t
name|rxpp_fifo_overflow_drop
decl_stmt|;
name|uint32_t
name|rx_input_fifo_overflow_drop
decl_stmt|;
name|uint32_t
name|pmem_fifo_overflow_drop
decl_stmt|;
name|uint32_t
name|jabber_events
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_xe201_stats
block|{
name|uint64_t
name|tx_pkts
decl_stmt|;
name|uint64_t
name|tx_unicast_pkts
decl_stmt|;
name|uint64_t
name|tx_multicast_pkts
decl_stmt|;
name|uint64_t
name|tx_broadcast_pkts
decl_stmt|;
name|uint64_t
name|tx_bytes
decl_stmt|;
name|uint64_t
name|tx_unicast_bytes
decl_stmt|;
name|uint64_t
name|tx_multicast_bytes
decl_stmt|;
name|uint64_t
name|tx_broadcast_bytes
decl_stmt|;
name|uint64_t
name|tx_discards
decl_stmt|;
name|uint64_t
name|tx_errors
decl_stmt|;
name|uint64_t
name|tx_pause_frames
decl_stmt|;
name|uint64_t
name|tx_pause_on_frames
decl_stmt|;
name|uint64_t
name|tx_pause_off_frames
decl_stmt|;
name|uint64_t
name|tx_internal_mac_errors
decl_stmt|;
name|uint64_t
name|tx_control_frames
decl_stmt|;
name|uint64_t
name|tx_pkts_64_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_65_to_127_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_128_to_255_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_256_to_511_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_512_to_1023_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_1024_to_1518_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_1519_to_2047_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_2048_to_4095_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_4096_to_8191_bytes
decl_stmt|;
name|uint64_t
name|tx_pkts_8192_to_9216_bytes
decl_stmt|;
name|uint64_t
name|tx_lso_pkts
decl_stmt|;
name|uint64_t
name|rx_pkts
decl_stmt|;
name|uint64_t
name|rx_unicast_pkts
decl_stmt|;
name|uint64_t
name|rx_multicast_pkts
decl_stmt|;
name|uint64_t
name|rx_broadcast_pkts
decl_stmt|;
name|uint64_t
name|rx_bytes
decl_stmt|;
name|uint64_t
name|rx_unicast_bytes
decl_stmt|;
name|uint64_t
name|rx_multicast_bytes
decl_stmt|;
name|uint64_t
name|rx_broadcast_bytes
decl_stmt|;
name|uint32_t
name|rx_unknown_protos
decl_stmt|;
name|uint64_t
name|rx_discards
decl_stmt|;
name|uint64_t
name|rx_errors
decl_stmt|;
name|uint64_t
name|rx_crc_errors
decl_stmt|;
name|uint64_t
name|rx_alignment_errors
decl_stmt|;
name|uint64_t
name|rx_symbol_errors
decl_stmt|;
name|uint64_t
name|rx_pause_frames
decl_stmt|;
name|uint64_t
name|rx_pause_on_frames
decl_stmt|;
name|uint64_t
name|rx_pause_off_frames
decl_stmt|;
name|uint64_t
name|rx_frames_too_long
decl_stmt|;
name|uint64_t
name|rx_internal_mac_errors
decl_stmt|;
name|uint32_t
name|rx_undersize_pkts
decl_stmt|;
name|uint32_t
name|rx_oversize_pkts
decl_stmt|;
name|uint32_t
name|rx_fragment_pkts
decl_stmt|;
name|uint32_t
name|rx_jabbers
decl_stmt|;
name|uint64_t
name|rx_control_frames
decl_stmt|;
name|uint64_t
name|rx_control_frames_unknown_opcode
decl_stmt|;
name|uint32_t
name|rx_in_range_errors
decl_stmt|;
name|uint32_t
name|rx_out_of_range_errors
decl_stmt|;
name|uint32_t
name|rx_address_match_errors
decl_stmt|;
name|uint32_t
name|rx_vlan_mismatch_errors
decl_stmt|;
name|uint32_t
name|rx_dropped_too_small
decl_stmt|;
name|uint32_t
name|rx_dropped_too_short
decl_stmt|;
name|uint32_t
name|rx_dropped_header_too_small
decl_stmt|;
name|uint32_t
name|rx_dropped_invalid_tcp_length
decl_stmt|;
name|uint32_t
name|rx_dropped_runt
decl_stmt|;
name|uint32_t
name|rx_ip_checksum_errors
decl_stmt|;
name|uint32_t
name|rx_tcp_checksum_errors
decl_stmt|;
name|uint32_t
name|rx_udp_checksum_errors
decl_stmt|;
name|uint32_t
name|rx_non_rss_pkts
decl_stmt|;
name|uint64_t
name|rx_ipv4_pkts
decl_stmt|;
name|uint64_t
name|rx_ipv6_pkts
decl_stmt|;
name|uint64_t
name|rx_ipv4_bytes
decl_stmt|;
name|uint64_t
name|rx_ipv6_bytes
decl_stmt|;
name|uint64_t
name|rx_nic_pkts
decl_stmt|;
name|uint64_t
name|rx_tcp_pkts
decl_stmt|;
name|uint64_t
name|rx_iscsi_pkts
decl_stmt|;
name|uint64_t
name|rx_management_pkts
decl_stmt|;
name|uint64_t
name|rx_switched_unicast_pkts
decl_stmt|;
name|uint64_t
name|rx_switched_multicast_pkts
decl_stmt|;
name|uint64_t
name|rx_switched_broadcast_pkts
decl_stmt|;
name|uint64_t
name|num_forwards
decl_stmt|;
name|uint32_t
name|rx_fifo_overflow
decl_stmt|;
name|uint32_t
name|rx_input_fifo_overflow
decl_stmt|;
name|uint64_t
name|rx_drops_too_many_frags
decl_stmt|;
name|uint32_t
name|rx_drops_invalid_queue
decl_stmt|;
name|uint64_t
name|rx_drops_mtu
decl_stmt|;
name|uint64_t
name|rx_pkts_64_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_65_to_127_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_128_to_255_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_256_to_511_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_512_to_1023_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_1024_to_1518_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_1519_to_2047_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_2048_to_4095_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_4096_to_8191_bytes
decl_stmt|;
name|uint64_t
name|rx_pkts_8192_to_9216_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_drv_stats
block|{
name|struct
name|oce_rx_stats
name|rx
decl_stmt|;
name|struct
name|oce_tx_stats
name|tx
decl_stmt|;
union|union
block|{
name|struct
name|oce_be_stats
name|be
decl_stmt|;
name|struct
name|oce_xe201_stats
name|xe201
decl_stmt|;
block|}
name|u0
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INTR_RATE_HWM
value|15000
end_define

begin_define
define|#
directive|define
name|INTR_RATE_LWM
value|10000
end_define

begin_define
define|#
directive|define
name|OCE_MAX_EQD
value|128u
end_define

begin_define
define|#
directive|define
name|OCE_MIN_EQD
value|50u
end_define

begin_struct
struct|struct
name|oce_set_eqd
block|{
name|uint32_t
name|eq_id
decl_stmt|;
name|uint32_t
name|phase
decl_stmt|;
name|uint32_t
name|delay_multiplier
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_aic_obj
block|{
comment|/* Adaptive interrupt coalescing (AIC) info */
name|boolean_t
name|enable
decl_stmt|;
name|uint32_t
name|min_eqd
decl_stmt|;
comment|/* in usecs */
name|uint32_t
name|max_eqd
decl_stmt|;
comment|/* in usecs */
name|uint32_t
name|cur_eqd
decl_stmt|;
comment|/* in usecs */
name|uint32_t
name|et_eqd
decl_stmt|;
comment|/* configured value when aic is off */
name|uint64_t
name|ticks
decl_stmt|;
name|uint64_t
name|intr_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_LOCK_DESC_LEN
value|32
end_define

begin_struct
struct|struct
name|oce_lock
block|{
name|struct
name|mtx
name|mutex
decl_stmt|;
name|char
name|name
index|[
name|MAX_LOCK_DESC_LEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OCE_LOCK
value|struct oce_lock
end_define

begin_define
define|#
directive|define
name|LOCK_CREATE
parameter_list|(
name|lock
parameter_list|,
name|desc
parameter_list|)
value|{ \ 	strncpy((lock)->name, (desc), MAX_LOCK_DESC_LEN); \ 	(lock)->name[MAX_LOCK_DESC_LEN] = '\0'; \ 	mtx_init(&(lock)->mutex, (lock)->name, NULL, MTX_DEF); \ }
end_define

begin_define
define|#
directive|define
name|LOCK_DESTROY
parameter_list|(
name|lock
parameter_list|)
define|\
value|if (mtx_initialized(&(lock)->mutex))\ 			mtx_destroy(&(lock)->mutex)
end_define

begin_define
define|#
directive|define
name|TRY_LOCK
parameter_list|(
name|lock
parameter_list|)
value|mtx_trylock(&(lock)->mutex)
end_define

begin_define
define|#
directive|define
name|LOCK
parameter_list|(
name|lock
parameter_list|)
value|mtx_lock(&(lock)->mutex)
end_define

begin_define
define|#
directive|define
name|LOCKED
parameter_list|(
name|lock
parameter_list|)
value|mtx_owned(&(lock)->mutex)
end_define

begin_define
define|#
directive|define
name|UNLOCK
parameter_list|(
name|lock
parameter_list|)
value|mtx_unlock(&(lock)->mutex)
end_define

begin_define
define|#
directive|define
name|DEFAULT_MQ_MBOX_TIMEOUT
value|(5 * 1000 * 1000)
end_define

begin_define
define|#
directive|define
name|MBX_READY_TIMEOUT
value|(1 * 1000 * 1000)
end_define

begin_define
define|#
directive|define
name|DEFAULT_DRAIN_TIME
value|200
end_define

begin_define
define|#
directive|define
name|MBX_TIMEOUT_SEC
value|5
end_define

begin_define
define|#
directive|define
name|STAT_TIMEOUT
value|2000000
end_define

begin_comment
comment|/* size of the packet descriptor array in a transmit queue */
end_comment

begin_define
define|#
directive|define
name|OCE_TX_RING_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|OCE_RX_RING_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|OCE_WQ_PACKET_ARRAY_SIZE
value|(OCE_TX_RING_SIZE/2)
end_define

begin_define
define|#
directive|define
name|OCE_RQ_PACKET_ARRAY_SIZE
value|(OCE_RX_RING_SIZE)
end_define

begin_struct_decl
struct_decl|struct
name|oce_dev
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|eq_len
block|{
name|EQ_LEN_256
init|=
literal|256
block|,
name|EQ_LEN_512
init|=
literal|512
block|,
name|EQ_LEN_1024
init|=
literal|1024
block|,
name|EQ_LEN_2048
init|=
literal|2048
block|,
name|EQ_LEN_4096
init|=
literal|4096
block|}
enum|;
end_enum

begin_enum
enum|enum
name|eqe_size
block|{
name|EQE_SIZE_4
init|=
literal|4
block|,
name|EQE_SIZE_16
init|=
literal|16
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qtype
block|{
name|QTYPE_EQ
block|,
name|QTYPE_MQ
block|,
name|QTYPE_WQ
block|,
name|QTYPE_RQ
block|,
name|QTYPE_CQ
block|,
name|QTYPE_RSS
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
enum|enum
name|qstate_e
block|{
name|QDELETED
init|=
literal|0x0
block|,
name|QCREATED
init|=
literal|0x1
block|}
name|qstate_t
typedef|;
end_typedef

begin_struct
struct|struct
name|eq_config
block|{
name|enum
name|eq_len
name|q_len
decl_stmt|;
name|enum
name|eqe_size
name|item_size
decl_stmt|;
name|uint32_t
name|q_vector_num
decl_stmt|;
name|uint8_t
name|min_eqd
decl_stmt|;
name|uint8_t
name|max_eqd
decl_stmt|;
name|uint8_t
name|cur_eqd
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_eq
block|{
name|uint32_t
name|eq_id
decl_stmt|;
name|void
modifier|*
name|parent
decl_stmt|;
name|void
modifier|*
name|cb_context
decl_stmt|;
name|oce_ring_buffer_t
modifier|*
name|ring
decl_stmt|;
name|uint32_t
name|ref_count
decl_stmt|;
name|qstate_t
name|qstate
decl_stmt|;
name|struct
name|oce_cq
modifier|*
name|cq
index|[
name|OCE_MAX_CQ_EQ
index|]
decl_stmt|;
name|int
name|cq_valid
decl_stmt|;
name|struct
name|eq_config
name|eq_cfg
decl_stmt|;
name|int
name|vector
decl_stmt|;
name|uint64_t
name|intr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|cq_len
block|{
name|CQ_LEN_256
init|=
literal|256
block|,
name|CQ_LEN_512
init|=
literal|512
block|,
name|CQ_LEN_1024
init|=
literal|1024
block|}
enum|;
end_enum

begin_struct
struct|struct
name|cq_config
block|{
name|enum
name|cq_len
name|q_len
decl_stmt|;
name|uint32_t
name|item_size
decl_stmt|;
name|boolean_t
name|is_eventable
decl_stmt|;
name|boolean_t
name|sol_eventable
decl_stmt|;
name|boolean_t
name|nodelay
decl_stmt|;
name|uint16_t
name|dma_coalescing
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|uint16_t
function_decl|(
modifier|*
name|cq_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg1
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|oce_cq
block|{
name|uint32_t
name|cq_id
decl_stmt|;
name|void
modifier|*
name|parent
decl_stmt|;
name|struct
name|oce_eq
modifier|*
name|eq
decl_stmt|;
name|cq_handler_t
name|cq_handler
decl_stmt|;
name|void
modifier|*
name|cb_arg
decl_stmt|;
name|oce_ring_buffer_t
modifier|*
name|ring
decl_stmt|;
name|qstate_t
name|qstate
decl_stmt|;
name|struct
name|cq_config
name|cq_cfg
decl_stmt|;
name|uint32_t
name|ref_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mq_config
block|{
name|uint32_t
name|eqd
decl_stmt|;
name|uint8_t
name|q_len
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_mq
block|{
name|void
modifier|*
name|parent
decl_stmt|;
name|oce_ring_buffer_t
modifier|*
name|ring
decl_stmt|;
name|uint32_t
name|mq_id
decl_stmt|;
name|struct
name|oce_cq
modifier|*
name|cq
decl_stmt|;
name|struct
name|oce_cq
modifier|*
name|async_cq
decl_stmt|;
name|uint32_t
name|mq_free
decl_stmt|;
name|qstate_t
name|qstate
decl_stmt|;
name|struct
name|mq_config
name|cfg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_mbx_ctx
block|{
name|struct
name|oce_mbx
modifier|*
name|mbx
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wq_config
block|{
name|uint8_t
name|wq_type
decl_stmt|;
name|uint16_t
name|buf_size
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|1
index|]
decl_stmt|;
name|uint32_t
name|q_len
decl_stmt|;
name|uint16_t
name|pd_id
decl_stmt|;
name|uint16_t
name|pci_fn_num
decl_stmt|;
name|uint32_t
name|eqd
decl_stmt|;
comment|/* interrupt delay */
name|uint32_t
name|nbufs
decl_stmt|;
name|uint32_t
name|nhdl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_tx_queue_stats
block|{
name|uint64_t
name|tx_pkts
decl_stmt|;
name|uint64_t
name|tx_bytes
decl_stmt|;
name|uint32_t
name|tx_reqs
decl_stmt|;
name|uint32_t
name|tx_stops
decl_stmt|;
comment|/* number of times TX Q was stopped */
name|uint32_t
name|tx_wrbs
decl_stmt|;
name|uint32_t
name|tx_compl
decl_stmt|;
name|uint32_t
name|tx_rate
decl_stmt|;
name|uint32_t
name|ipv6_ext_hdr_tx_drop
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_wq
block|{
name|OCE_LOCK
name|tx_lock
decl_stmt|;
name|void
modifier|*
name|parent
decl_stmt|;
name|oce_ring_buffer_t
modifier|*
name|ring
decl_stmt|;
name|struct
name|oce_cq
modifier|*
name|cq
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|struct
name|oce_packet_desc
name|pckts
index|[
name|OCE_WQ_PACKET_ARRAY_SIZE
index|]
decl_stmt|;
name|uint32_t
name|pkt_desc_tail
decl_stmt|;
name|uint32_t
name|pkt_desc_head
decl_stmt|;
name|uint32_t
name|wqm_used
decl_stmt|;
name|boolean_t
name|resched
decl_stmt|;
name|uint32_t
name|wq_free
decl_stmt|;
name|uint32_t
name|tx_deferd
decl_stmt|;
name|uint32_t
name|pkt_drops
decl_stmt|;
name|qstate_t
name|qstate
decl_stmt|;
name|uint16_t
name|wq_id
decl_stmt|;
name|struct
name|wq_config
name|cfg
decl_stmt|;
name|int
name|queue_index
decl_stmt|;
name|struct
name|oce_tx_queue_stats
name|tx_stats
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
name|struct
name|task
name|txtask
decl_stmt|;
name|uint32_t
name|db_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rq_config
block|{
name|uint32_t
name|q_len
decl_stmt|;
name|uint32_t
name|frag_size
decl_stmt|;
name|uint32_t
name|mtu
decl_stmt|;
name|uint32_t
name|if_id
decl_stmt|;
name|uint32_t
name|is_rss_queue
decl_stmt|;
name|uint32_t
name|eqd
decl_stmt|;
name|uint32_t
name|nbufs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_rx_queue_stats
block|{
name|uint32_t
name|rx_post_fail
decl_stmt|;
name|uint32_t
name|rx_ucast_pkts
decl_stmt|;
name|uint32_t
name|rx_compl
decl_stmt|;
name|uint64_t
name|rx_bytes
decl_stmt|;
name|uint64_t
name|rx_bytes_prev
decl_stmt|;
name|uint64_t
name|rx_pkts
decl_stmt|;
name|uint32_t
name|rx_rate
decl_stmt|;
name|uint32_t
name|rx_mcast_pkts
decl_stmt|;
name|uint32_t
name|rxcp_err
decl_stmt|;
name|uint32_t
name|rx_frags
decl_stmt|;
name|uint32_t
name|prev_rx_frags
decl_stmt|;
name|uint32_t
name|rx_fps
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oce_rq
block|{
name|struct
name|rq_config
name|cfg
decl_stmt|;
name|uint32_t
name|rq_id
decl_stmt|;
name|int
name|queue_index
decl_stmt|;
name|uint32_t
name|rss_cpuid
decl_stmt|;
name|void
modifier|*
name|parent
decl_stmt|;
name|oce_ring_buffer_t
modifier|*
name|ring
decl_stmt|;
name|struct
name|oce_cq
modifier|*
name|cq
decl_stmt|;
name|void
modifier|*
name|pad1
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|struct
name|oce_packet_desc
name|pckts
index|[
name|OCE_RQ_PACKET_ARRAY_SIZE
index|]
decl_stmt|;
name|uint32_t
name|packets_in
decl_stmt|;
name|uint32_t
name|packets_out
decl_stmt|;
name|uint32_t
name|pending
decl_stmt|;
ifdef|#
directive|ifdef
name|notdef
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tail
decl_stmt|;
name|int
name|fragsleft
decl_stmt|;
endif|#
directive|endif
name|qstate_t
name|qstate
decl_stmt|;
name|OCE_LOCK
name|rx_lock
decl_stmt|;
name|struct
name|oce_rx_queue_stats
name|rx_stats
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|int
name|lro_pkts_queued
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|link_status
block|{
name|uint8_t
name|phys_port_speed
decl_stmt|;
name|uint8_t
name|logical_link_status
decl_stmt|;
name|uint16_t
name|qos_link_speed
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OCE_FLAGS_PCIX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_PCIE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_MSI_CAPABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_MSIX_CAPABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_USING_MSI
value|0x00000010
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_USING_MSIX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_FUNCRESET_RQD
value|0x00000040
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_VIRTUAL_PORT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_MBOX_ENDIAN_RQD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_BE3
value|0x00000200
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_XE201
value|0x00000400
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_BE2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|OCE_FLAGS_SH
value|0x00001000
end_define

begin_define
define|#
directive|define
name|OCE_DEV_BE2_CFG_BAR
value|1
end_define

begin_define
define|#
directive|define
name|OCE_DEV_CFG_BAR
value|0
end_define

begin_define
define|#
directive|define
name|OCE_PCI_CSR_BAR
value|2
end_define

begin_define
define|#
directive|define
name|OCE_PCI_DB_BAR
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|oce_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|OCE_LOCK
name|dev_lock
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|pcie_link_speed
decl_stmt|;
name|uint32_t
name|pcie_link_width
decl_stmt|;
name|uint8_t
name|fn
decl_stmt|;
comment|/* PCI function number */
name|struct
name|resource
modifier|*
name|devcfg_res
decl_stmt|;
name|bus_space_tag_t
name|devcfg_btag
decl_stmt|;
name|bus_space_handle_t
name|devcfg_bhandle
decl_stmt|;
name|void
modifier|*
name|devcfg_vhandle
decl_stmt|;
name|struct
name|resource
modifier|*
name|csr_res
decl_stmt|;
name|bus_space_tag_t
name|csr_btag
decl_stmt|;
name|bus_space_handle_t
name|csr_bhandle
decl_stmt|;
name|void
modifier|*
name|csr_vhandle
decl_stmt|;
name|struct
name|resource
modifier|*
name|db_res
decl_stmt|;
name|bus_space_tag_t
name|db_btag
decl_stmt|;
name|bus_space_handle_t
name|db_bhandle
decl_stmt|;
name|void
modifier|*
name|db_vhandle
decl_stmt|;
name|OCE_INTR_INFO
name|intrs
index|[
name|OCE_MAX_EQ
index|]
decl_stmt|;
name|int
name|intr_count
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|uint8_t
name|link_status
decl_stmt|;
name|uint8_t
name|link_speed
decl_stmt|;
name|uint8_t
name|duplex
decl_stmt|;
name|uint32_t
name|qos_link_speed
decl_stmt|;
name|uint32_t
name|speed
decl_stmt|;
name|char
name|fw_version
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mac_address_format
name|macaddr
decl_stmt|;
name|OCE_DMA_MEM
name|bsmbx
decl_stmt|;
name|OCE_LOCK
name|bmbx_lock
decl_stmt|;
name|uint32_t
name|config_number
decl_stmt|;
name|uint32_t
name|asic_revision
decl_stmt|;
name|uint32_t
name|port_id
decl_stmt|;
name|uint32_t
name|function_mode
decl_stmt|;
name|uint32_t
name|function_caps
decl_stmt|;
name|uint32_t
name|max_tx_rings
decl_stmt|;
name|uint32_t
name|max_rx_rings
decl_stmt|;
name|struct
name|oce_wq
modifier|*
name|wq
index|[
name|OCE_MAX_WQ
index|]
decl_stmt|;
comment|/* TX work queues */
name|struct
name|oce_rq
modifier|*
name|rq
index|[
name|OCE_MAX_RQ
index|]
decl_stmt|;
comment|/* RX work queues */
name|struct
name|oce_cq
modifier|*
name|cq
index|[
name|OCE_MAX_CQ
index|]
decl_stmt|;
comment|/* Completion queues */
name|struct
name|oce_eq
modifier|*
name|eq
index|[
name|OCE_MAX_EQ
index|]
decl_stmt|;
comment|/* Event queues */
name|struct
name|oce_mq
modifier|*
name|mq
decl_stmt|;
comment|/* Mailbox queue */
name|uint32_t
name|neqs
decl_stmt|;
name|uint32_t
name|ncqs
decl_stmt|;
name|uint32_t
name|nrqs
decl_stmt|;
name|uint32_t
name|nwqs
decl_stmt|;
name|uint32_t
name|nrssqs
decl_stmt|;
name|uint32_t
name|tx_ring_size
decl_stmt|;
name|uint32_t
name|rx_ring_size
decl_stmt|;
name|uint32_t
name|rq_frag_size
decl_stmt|;
name|uint32_t
name|if_id
decl_stmt|;
comment|/* interface ID */
name|uint32_t
name|nifs
decl_stmt|;
comment|/* number of adapter interfaces, 0 or 1 */
name|uint32_t
name|pmac_id
decl_stmt|;
comment|/* PMAC id */
name|uint32_t
name|if_cap_flags
decl_stmt|;
name|uint32_t
name|flow_control
decl_stmt|;
name|uint8_t
name|promisc
decl_stmt|;
name|struct
name|oce_aic_obj
name|aic_obj
index|[
name|OCE_MAX_EQ
index|]
decl_stmt|;
comment|/*Vlan Filtering related */
name|eventhandler_tag
name|vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vlan_detach
decl_stmt|;
name|uint16_t
name|vlans_added
decl_stmt|;
name|uint8_t
name|vlan_tag
index|[
name|MAX_VLANS
index|]
decl_stmt|;
comment|/*stats */
name|OCE_DMA_MEM
name|stats_mem
decl_stmt|;
name|struct
name|oce_drv_stats
name|oce_stats_info
decl_stmt|;
name|struct
name|callout
name|timer
decl_stmt|;
name|int8_t
name|be3_native
decl_stmt|;
name|uint8_t
name|hw_error
decl_stmt|;
name|uint16_t
name|qnq_debug_event
decl_stmt|;
name|uint16_t
name|qnqid
decl_stmt|;
name|uint32_t
name|pvid
decl_stmt|;
name|uint32_t
name|max_vlans
decl_stmt|;
block|}
name|OCE_SOFTC
operator|,
typedef|*
name|POCE_SOFTC
typedef|;
end_typedef

begin_comment
comment|/**************************************************  * BUS memory read/write macros  * BE3: accesses three BAR spaces (CFG, CSR, DB)  * Lancer: accesses one BAR space (CFG)  **************************************************/
end_comment

begin_define
define|#
directive|define
name|OCE_READ_CSR_MPU
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|)
define|\
value|((IS_BE(sc)) ? (bus_space_read_4((sc)->space##_btag, \ 					(sc)->space##_bhandle,o)) \ 				: (bus_space_read_4((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o)))
end_define

begin_define
define|#
directive|define
name|OCE_READ_REG32
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|)
define|\
value|((IS_BE(sc) || IS_SH(sc)) ? (bus_space_read_4((sc)->space##_btag, \ 					(sc)->space##_bhandle,o)) \ 				: (bus_space_read_4((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o)))
end_define

begin_define
define|#
directive|define
name|OCE_READ_REG16
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|)
define|\
value|((IS_BE(sc) || IS_SH(sc)) ? (bus_space_read_2((sc)->space##_btag, \ 					(sc)->space##_bhandle,o)) \ 				: (bus_space_read_2((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o)))
end_define

begin_define
define|#
directive|define
name|OCE_READ_REG8
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|)
define|\
value|((IS_BE(sc) || IS_SH(sc)) ? (bus_space_read_1((sc)->space##_btag, \ 					(sc)->space##_bhandle,o)) \ 				: (bus_space_read_1((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o)))
end_define

begin_define
define|#
directive|define
name|OCE_WRITE_CSR_MPU
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((IS_BE(sc)) ? (bus_space_write_4((sc)->space##_btag, \ 				       (sc)->space##_bhandle,o,v)) \ 				: (bus_space_write_4((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o,v)))
end_define

begin_define
define|#
directive|define
name|OCE_WRITE_REG32
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((IS_BE(sc) || IS_SH(sc)) ? (bus_space_write_4((sc)->space##_btag, \ 				       (sc)->space##_bhandle,o,v)) \ 				: (bus_space_write_4((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o,v)))
end_define

begin_define
define|#
directive|define
name|OCE_WRITE_REG16
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((IS_BE(sc) || IS_SH(sc)) ? (bus_space_write_2((sc)->space##_btag, \ 				       (sc)->space##_bhandle,o,v)) \ 				: (bus_space_write_2((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o,v)))
end_define

begin_define
define|#
directive|define
name|OCE_WRITE_REG8
parameter_list|(
name|sc
parameter_list|,
name|space
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((IS_BE(sc) || IS_SH(sc)) ? (bus_space_write_1((sc)->space##_btag, \ 				       (sc)->space##_bhandle,o,v)) \ 				: (bus_space_write_1((sc)->devcfg_btag, \ 					(sc)->devcfg_bhandle,o,v)))
end_define

begin_comment
comment|/***********************************************************  * DMA memory functions  ***********************************************************/
end_comment

begin_define
define|#
directive|define
name|oce_dma_sync
parameter_list|(
name|d
parameter_list|,
name|f
parameter_list|)
value|bus_dmamap_sync((d)->tag, (d)->map, f)
end_define

begin_function_decl
name|int
name|oce_dma_alloc
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|POCE_DMA_MEM
name|dma
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_dma_free
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|dma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_dma_map_addr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nseg
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_destroy_ring_buffer
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|oce_ring_buffer_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|oce_ring_buffer_t
modifier|*
name|oce_create_ring_buffer
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|q_len
parameter_list|,
name|uint32_t
name|num_entries
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************************************************  * oce_hw_xxx functions  ************************************************************/
end_comment

begin_function_decl
name|int
name|oce_clear_rx_buf
parameter_list|(
name|struct
name|oce_rq
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_hw_pci_alloc
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_hw_init
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_hw_start
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_create_nw_interface
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_pci_soft_reset
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_hw_update_multicast
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_delete_nw_interface
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_hw_shutdown
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_hw_intr_enable
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_hw_intr_disable
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_hw_pci_free
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***********************************************************  * oce_queue_xxx functions  ***********************************************************/
end_comment

begin_function_decl
name|int
name|oce_queue_init_all
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_start_rq
parameter_list|(
name|struct
name|oce_rq
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_start_wq
parameter_list|(
name|struct
name|oce_wq
modifier|*
name|wq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_start_mq
parameter_list|(
name|struct
name|oce_mq
modifier|*
name|mq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_start_rx
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_arm_eq
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|int16_t
name|qid
parameter_list|,
name|int
name|npopped
parameter_list|,
name|uint32_t
name|rearm
parameter_list|,
name|uint32_t
name|clearint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_queue_release_all
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_arm_cq
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|int16_t
name|qid
parameter_list|,
name|int
name|npopped
parameter_list|,
name|uint32_t
name|rearm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_drain_eq
parameter_list|(
name|struct
name|oce_eq
modifier|*
name|eq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_drain_mq_cq
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_drain_rq_cq
parameter_list|(
name|struct
name|oce_rq
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_drain_wq_cq
parameter_list|(
name|struct
name|oce_wq
modifier|*
name|wq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|oce_page_list
parameter_list|(
name|oce_ring_buffer_t
modifier|*
name|ring
parameter_list|,
name|struct
name|phys_addr
modifier|*
name|pa_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***********************************************************  * cleanup  functions  ***********************************************************/
end_comment

begin_function_decl
name|void
name|oce_stop_rx
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_intr_free
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_free_posted_rxbuf
parameter_list|(
name|struct
name|oce_rq
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INET6
argument_list|)
operator|||
name|defined
argument_list|(
name|INET
argument_list|)
end_if

begin_function_decl
name|void
name|oce_free_lro
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************  * Mailbox functions  ************************************************************/
end_comment

begin_function_decl
name|int
name|oce_fw_clean
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_reset_fun
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_init
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_dispatch
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|tmo_sec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_get_fw_version
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_first_mcc_cmd
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_read_mac_addr
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|if_id
parameter_list|,
name|uint8_t
name|perm
parameter_list|,
name|uint8_t
name|type
parameter_list|,
name|struct
name|mac_address_format
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_get_fw_config
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_if_create
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|cap_flags
parameter_list|,
name|uint32_t
name|en_flags
parameter_list|,
name|uint16_t
name|vlan_tag
parameter_list|,
name|uint8_t
modifier|*
name|mac_addr
parameter_list|,
name|uint32_t
modifier|*
name|if_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_if_del
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|if_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_config_vlan
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|if_id
parameter_list|,
name|struct
name|normal_vlan
modifier|*
name|vtag_arr
parameter_list|,
name|uint8_t
name|vtag_cnt
parameter_list|,
name|uint32_t
name|untagged
parameter_list|,
name|uint32_t
name|enable_promisc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_set_flow_control
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|flow_control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_config_nic_rss
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|if_id
parameter_list|,
name|uint16_t
name|enable_rss
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_rxf_set_promiscuous
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint8_t
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_set_common_iface_rx_filter
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|sgl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_get_link_status
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|struct
name|link_status
modifier|*
name|link
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_get_nic_stats_v0
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|pstats_dma_mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_get_nic_stats
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|pstats_dma_mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_get_pport_stats
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|pstats_dma_mem
parameter_list|,
name|uint32_t
name|reset_stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_get_vport_stats
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|pstats_dma_mem
parameter_list|,
name|uint32_t
name|req_size
parameter_list|,
name|uint32_t
name|reset_stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_update_multicast
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|pdma_mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_pass_through_mbox
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|POCE_DMA_MEM
name|dma_mem
parameter_list|,
name|uint32_t
name|req_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_macaddr_del
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|if_id
parameter_list|,
name|uint32_t
name|pmac_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_macaddr_add
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|mac_addr
parameter_list|,
name|uint32_t
name|if_id
parameter_list|,
name|uint32_t
modifier|*
name|pmac_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_cmd_test_loopback
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|port_num
parameter_list|,
name|uint32_t
name|loopback_type
parameter_list|,
name|uint32_t
name|pkt_size
parameter_list|,
name|uint32_t
name|num_pkts
parameter_list|,
name|uint64_t
name|pattern
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_cmd_set_loopback
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint8_t
name|port_num
parameter_list|,
name|uint8_t
name|loopback_type
parameter_list|,
name|uint8_t
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_check_native_mode
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_post
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|struct
name|oce_mbx
modifier|*
name|mbx
parameter_list|,
name|struct
name|oce_mbx_ctx
modifier|*
name|mbxctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_write_flashrom
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|optype
parameter_list|,
name|uint32_t
name|opcode
parameter_list|,
name|POCE_DMA_MEM
name|pdma_mem
parameter_list|,
name|uint32_t
name|num_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_lancer_write_flashrom
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|data_size
parameter_list|,
name|uint32_t
name|data_offset
parameter_list|,
name|POCE_DMA_MEM
name|pdma_mem
parameter_list|,
name|uint32_t
modifier|*
name|written_data
parameter_list|,
name|uint32_t
modifier|*
name|additional_status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_get_flashrom_crc
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|flash_crc
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|optype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_get_phy_info
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|struct
name|oce_phy_info
modifier|*
name|phy_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_create_rq
parameter_list|(
name|struct
name|oce_rq
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_create_wq
parameter_list|(
name|struct
name|oce_wq
modifier|*
name|wq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_create_eq
parameter_list|(
name|struct
name|oce_eq
modifier|*
name|eq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_cq_create
parameter_list|(
name|struct
name|oce_cq
modifier|*
name|cq
parameter_list|,
name|uint32_t
name|ncoalesce
parameter_list|,
name|uint32_t
name|is_eventable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_mbox_read_transrecv_data
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|page_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_mbox_eqd_modify_periodic
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|struct
name|oce_set_eqd
modifier|*
name|set_eqd
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_get_profile_config
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|,
name|uint32_t
name|max_rss
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_get_func_config
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbx_common_req_hdr_init
parameter_list|(
name|struct
name|mbx_hdr
modifier|*
name|hdr
parameter_list|,
name|uint8_t
name|dom
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|uint8_t
name|subsys
parameter_list|,
name|uint8_t
name|opcode
parameter_list|,
name|uint32_t
name|timeout
parameter_list|,
name|uint32_t
name|pyld_len
parameter_list|,
name|uint8_t
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|oce_mq_handler
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************************************************  * Transmit functions  ************************************************************/
end_comment

begin_function_decl
name|uint16_t
name|oce_wq_handler
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_start
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_tx_task
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|npending
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************************************************  * Receive functions  ************************************************************/
end_comment

begin_function_decl
name|int
name|oce_alloc_rx_bufs
parameter_list|(
name|struct
name|oce_rq
modifier|*
name|rq
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|oce_rq_handler
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sysctl functions */
end_comment

begin_function_decl
name|void
name|oce_add_sysctls
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_refresh_queue_stats
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_refresh_nic_stats
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oce_stats_init
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oce_stats_free
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Capabilities */
end_comment

begin_define
define|#
directive|define
name|OCE_MODCAP_RSS
value|1
end_define

begin_define
define|#
directive|define
name|OCE_MAX_RSP_HANDLED
value|64
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|oce_max_rsp_handled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max responses */
end_comment

begin_define
define|#
directive|define
name|OCE_MAC_LOOPBACK
value|0x0
end_define

begin_define
define|#
directive|define
name|OCE_PHY_LOOPBACK
value|0x1
end_define

begin_define
define|#
directive|define
name|OCE_ONE_PORT_EXT_LOOPBACK
value|0x2
end_define

begin_define
define|#
directive|define
name|OCE_NO_LOOPBACK
value|0xff
end_define

begin_undef
undef|#
directive|undef
name|IFM_40G_SR4
end_undef

begin_define
define|#
directive|define
name|IFM_40G_SR4
value|28
end_define

begin_define
define|#
directive|define
name|atomic_inc_32
parameter_list|(
name|x
parameter_list|)
value|atomic_add_32(x, 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec_32
parameter_list|(
name|x
parameter_list|)
value|atomic_subtract_32(x, 1)
end_define

begin_define
define|#
directive|define
name|LE_64
parameter_list|(
name|x
parameter_list|)
value|htole64(x)
end_define

begin_define
define|#
directive|define
name|LE_32
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_define
define|#
directive|define
name|LE_16
parameter_list|(
name|x
parameter_list|)
value|htole16(x)
end_define

begin_define
define|#
directive|define
name|HOST_64
parameter_list|(
name|x
parameter_list|)
value|le64toh(x)
end_define

begin_define
define|#
directive|define
name|HOST_32
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|HOST_16
parameter_list|(
name|x
parameter_list|)
value|le16toh(x)
end_define

begin_define
define|#
directive|define
name|DW_SWAP
parameter_list|(
name|x
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IS_ALIGNED
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|((x % a) == 0)
end_define

begin_define
define|#
directive|define
name|ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)((uint64_t)(x)>> 32))
end_define

begin_define
define|#
directive|define
name|ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)((uint64_t)(x)& 0xffffffff));
end_define

begin_define
define|#
directive|define
name|IF_LRO_ENABLED
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->ifp->if_capenable& IFCAP_LRO) ? 1:0)
end_define

begin_define
define|#
directive|define
name|IF_LSO_ENABLED
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->ifp->if_capenable& IFCAP_TSO4) ? 1:0)
end_define

begin_define
define|#
directive|define
name|IF_CSUM_ENABLED
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->ifp->if_capenable& IFCAP_HWCSUM) ? 1:0)
end_define

begin_define
define|#
directive|define
name|OCE_LOG2
parameter_list|(
name|x
parameter_list|)
value|(oce_highbit(x))
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|oce_highbit
parameter_list|(
name|uint32_t
name|x
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|int
name|c
decl_stmt|;
name|int
name|b
decl_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
name|b
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
literal|1
operator|<<
name|i
operator|)
operator|&
name|x
condition|)
block|{
name|c
operator|++
expr_stmt|;
name|b
operator|=
name|i
expr_stmt|;
block|}
block|}
if|if
condition|(
name|c
operator|==
literal|1
condition|)
return|return
name|b
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|MPU_EP_SEMAPHORE
parameter_list|(
name|POCE_SOFTC
name|sc
parameter_list|)
block|{
if|if
condition|(
name|IS_BE
argument_list|(
name|sc
argument_list|)
condition|)
return|return
name|MPU_EP_SEMAPHORE_BE3
return|;
elseif|else
if|if
condition|(
name|IS_SH
argument_list|(
name|sc
argument_list|)
condition|)
return|return
name|MPU_EP_SEMAPHORE_SH
return|;
else|else
return|return
name|MPU_EP_SEMAPHORE_XE201
return|;
block|}
end_function

begin_define
define|#
directive|define
name|TRANSCEIVER_DATA_NUM_ELE
value|64
end_define

begin_define
define|#
directive|define
name|TRANSCEIVER_DATA_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|TRANSCEIVER_A0_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|TRANSCEIVER_A2_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|PAGE_NUM_A0
value|0xa0
end_define

begin_define
define|#
directive|define
name|PAGE_NUM_A2
value|0xa2
end_define

begin_define
define|#
directive|define
name|IS_QNQ_OR_UMC
parameter_list|(
name|sc
parameter_list|)
value|((sc->pvid&& (sc->function_mode& FNM_UMC_MODE ))\ 		     || (sc->qnqid&& (sc->function_mode& FNM_FLEX10_MODE)))
end_define

end_unit

