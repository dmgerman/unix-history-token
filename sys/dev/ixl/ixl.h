begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXL_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXL_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf_ring.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
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
file|<net/if_arp.h>
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
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_vlan_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
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
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_lro.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp.h>
end_include

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|"i40e_type.h"
end_include

begin_include
include|#
directive|include
file|"i40e_prototype.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IXL_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_define
define|#
directive|define
name|MAC_FORMAT
value|"%02x:%02x:%02x:%02x:%02x:%02x"
end_define

begin_define
define|#
directive|define
name|MAC_FORMAT_ARGS
parameter_list|(
name|mac_addr
parameter_list|)
define|\
value|(mac_addr)[0], (mac_addr)[1], (mac_addr)[2], (mac_addr)[3], \ 	(mac_addr)[4], (mac_addr)[5]
end_define

begin_define
define|#
directive|define
name|ON_OFF_STR
parameter_list|(
name|is_set
parameter_list|)
value|((is_set) ? "On" : "Off")
end_define

begin_define
define|#
directive|define
name|_DBG_PRINTF
parameter_list|(
name|S
parameter_list|,
modifier|...
parameter_list|)
value|printf("%s: " S "\n", __func__, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|_DEV_DBG_PRINTF
parameter_list|(
name|dev
parameter_list|,
name|S
parameter_list|,
modifier|...
parameter_list|)
value|device_printf(dev, "%s: " S "\n", __func__, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|_IF_DBG_PRINTF
parameter_list|(
name|ifp
parameter_list|,
name|S
parameter_list|,
modifier|...
parameter_list|)
value|if_printf(ifp, "%s: " S "\n", __func__, ##__VA_ARGS__)
end_define

begin_comment
comment|/* Defines for printing generic debug information */
end_comment

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|_DBG_PRINTF(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DDPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|_DEV_DBG_PRINTF(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IDPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|_IF_DBG_PRINTF(__VA_ARGS__)
end_define

begin_comment
comment|/* Defines for printing specific debug information */
end_comment

begin_define
define|#
directive|define
name|DEBUG_INIT
value|1
end_define

begin_define
define|#
directive|define
name|DEBUG_IOCTL
value|1
end_define

begin_define
define|#
directive|define
name|DEBUG_HW
value|1
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT
parameter_list|(
modifier|...
parameter_list|)
value|if (DEBUG_INIT) _DBG_PRINTF(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|INIT_DBG_DEV
parameter_list|(
modifier|...
parameter_list|)
value|if (DEBUG_INIT) _DEV_DBG_PRINTF(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|INIT_DBG_IF
parameter_list|(
modifier|...
parameter_list|)
value|if (DEBUG_INIT) _IF_DBG_PRINTF(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT
parameter_list|(
modifier|...
parameter_list|)
value|if (DEBUG_IOCTL) _DBG_PRINTF(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IOCTL_DBG_IF2
parameter_list|(
name|ifp
parameter_list|,
name|S
parameter_list|,
modifier|...
parameter_list|)
value|if (DEBUG_IOCTL) \ 					    if_printf(ifp, S "\n", ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|IOCTL_DBG_IF
parameter_list|(
modifier|...
parameter_list|)
value|if (DEBUG_IOCTL) _IF_DBG_PRINTF(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT
parameter_list|(
modifier|...
parameter_list|)
value|if (DEBUG_HW) _DBG_PRINTF(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG_INIT
value|0
end_define

begin_define
define|#
directive|define
name|DEBUG_IOCTL
value|0
end_define

begin_define
define|#
directive|define
name|DEBUG_HW
value|0
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DDPRINTF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IDPRINTF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INIT_DBG_DEV
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INIT_DBG_IF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IOCTL_DBG_IF2
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IOCTL_DBG_IF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tunables */
end_comment

begin_comment
comment|/*  * Ring Descriptors Valid Range: 32-4096 Default Value: 1024 This value is the  * number of tx/rx descriptors allocated by the driver. Increasing this  * value allows the driver to queue more operations. Each descriptor is 16  * or 32 bytes (configurable in FVL)  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RING
value|1024
end_define

begin_define
define|#
directive|define
name|PERFORM_RING
value|2048
end_define

begin_define
define|#
directive|define
name|MAX_RING
value|4096
end_define

begin_define
define|#
directive|define
name|MIN_RING
value|32
end_define

begin_comment
comment|/* ** Default number of entries in Tx queue buf_ring. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TXBRSZ
value|(4096 * 4096)
end_define

begin_comment
comment|/* Alignment for rings */
end_comment

begin_define
define|#
directive|define
name|DBA_ALIGN
value|128
end_define

begin_comment
comment|/*  * This parameter controls the maximum no of times the driver will loop in  * the isr. Minimum Value = 1  */
end_comment

begin_define
define|#
directive|define
name|MAX_LOOP
value|10
end_define

begin_comment
comment|/*  * This is the max watchdog interval, ie. the time that can  * pass between any two TX clean operations, such only happening  * when the TX hardware is functioning.  */
end_comment

begin_define
define|#
directive|define
name|IXL_WATCHDOG
value|(10 * hz)
end_define

begin_comment
comment|/*  * This parameters control when the driver calls the routine to reclaim  * transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|IXL_TX_CLEANUP_THRESHOLD
value|(que->num_desc / 8)
end_define

begin_define
define|#
directive|define
name|IXL_TX_OP_THRESHOLD
value|(que->num_desc / 32)
end_define

begin_comment
comment|/* Flow control constants */
end_comment

begin_define
define|#
directive|define
name|IXL_FC_PAUSE
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXL_FC_HI
value|0x20000
end_define

begin_define
define|#
directive|define
name|IXL_FC_LO
value|0x10000
end_define

begin_define
define|#
directive|define
name|MAX_MULTICAST_ADDR
value|128
end_define

begin_define
define|#
directive|define
name|IXL_BAR
value|3
end_define

begin_define
define|#
directive|define
name|IXL_ADM_LIMIT
value|2
end_define

begin_define
define|#
directive|define
name|IXL_TSO_SIZE
value|65535
end_define

begin_define
define|#
directive|define
name|IXL_TX_BUF_SZ
value|((u32) 1514)
end_define

begin_define
define|#
directive|define
name|IXL_AQ_BUF_SZ
value|((u32) 4096)
end_define

begin_define
define|#
directive|define
name|IXL_RX_HDR
value|128
end_define

begin_define
define|#
directive|define
name|IXL_AQ_LEN
value|256
end_define

begin_define
define|#
directive|define
name|IXL_AQ_BUFSZ
value|4096
end_define

begin_define
define|#
directive|define
name|IXL_RX_LIMIT
value|512
end_define

begin_define
define|#
directive|define
name|IXL_RX_ITR
value|0
end_define

begin_define
define|#
directive|define
name|IXL_TX_ITR
value|1
end_define

begin_define
define|#
directive|define
name|IXL_ITR_NONE
value|3
end_define

begin_define
define|#
directive|define
name|IXL_QUEUE_EOL
value|0x7FF
end_define

begin_define
define|#
directive|define
name|IXL_MAX_FRAME
value|0x2600
end_define

begin_define
define|#
directive|define
name|IXL_MAX_TX_SEGS
value|8
end_define

begin_define
define|#
directive|define
name|IXL_MAX_TSO_SEGS
value|66
end_define

begin_define
define|#
directive|define
name|IXL_SPARSE_CHAIN
value|6
end_define

begin_define
define|#
directive|define
name|IXL_QUEUE_HUNG
value|0x80000000
end_define

begin_comment
comment|/* ERJ: hardware can support ~1.5k filters between all functions */
end_comment

begin_define
define|#
directive|define
name|IXL_MAX_FILTERS
value|256
end_define

begin_define
define|#
directive|define
name|IXL_MAX_TX_BUSY
value|10
end_define

begin_define
define|#
directive|define
name|IXL_NVM_VERSION_LO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXL_NVM_VERSION_LO_MASK
value|(0xff<< IXL_NVM_VERSION_LO_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXL_NVM_VERSION_HI_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IXL_NVM_VERSION_HI_MASK
value|(0xf<< IXL_NVM_VERSION_HI_SHIFT)
end_define

begin_comment
comment|/*  * Interrupt Moderation parameters   */
end_comment

begin_define
define|#
directive|define
name|IXL_MAX_ITR
value|0x07FF
end_define

begin_define
define|#
directive|define
name|IXL_ITR_100K
value|0x0005
end_define

begin_define
define|#
directive|define
name|IXL_ITR_20K
value|0x0019
end_define

begin_define
define|#
directive|define
name|IXL_ITR_8K
value|0x003E
end_define

begin_define
define|#
directive|define
name|IXL_ITR_4K
value|0x007A
end_define

begin_define
define|#
directive|define
name|IXL_ITR_DYNAMIC
value|0x8000
end_define

begin_define
define|#
directive|define
name|IXL_LOW_LATENCY
value|0
end_define

begin_define
define|#
directive|define
name|IXL_AVE_LATENCY
value|1
end_define

begin_define
define|#
directive|define
name|IXL_BULK_LATENCY
value|2
end_define

begin_comment
comment|/* MacVlan Flags */
end_comment

begin_define
define|#
directive|define
name|IXL_FILTER_USED
value|(u16)(1<< 0)
end_define

begin_define
define|#
directive|define
name|IXL_FILTER_VLAN
value|(u16)(1<< 1)
end_define

begin_define
define|#
directive|define
name|IXL_FILTER_ADD
value|(u16)(1<< 2)
end_define

begin_define
define|#
directive|define
name|IXL_FILTER_DEL
value|(u16)(1<< 3)
end_define

begin_define
define|#
directive|define
name|IXL_FILTER_MC
value|(u16)(1<< 4)
end_define

begin_comment
comment|/* used in the vlan field of the filter when not a vlan */
end_comment

begin_define
define|#
directive|define
name|IXL_VLAN_ANY
value|-1
end_define

begin_define
define|#
directive|define
name|CSUM_OFFLOAD_IPV4
value|(CSUM_IP|CSUM_TCP|CSUM_UDP|CSUM_SCTP)
end_define

begin_define
define|#
directive|define
name|CSUM_OFFLOAD_IPV6
value|(CSUM_TCP_IPV6|CSUM_UDP_IPV6|CSUM_SCTP_IPV6)
end_define

begin_define
define|#
directive|define
name|CSUM_OFFLOAD
value|(CSUM_OFFLOAD_IPV4|CSUM_OFFLOAD_IPV6|CSUM_TSO)
end_define

begin_comment
comment|/* Misc flags for ixl_vsi.flags */
end_comment

begin_define
define|#
directive|define
name|IXL_FLAGS_KEEP_TSO4
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IXL_FLAGS_KEEP_TSO6
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IXL_TX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXL_TX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXL_TX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXL_TX_TRYLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_trylock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXL_TX_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IXL_RX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXL_RX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXL_RX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->mtx)
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100000
end_if

begin_define
define|#
directive|define
name|IXL_SET_IPACKETS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ipackets = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_IERRORS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ierrors = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OPACKETS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->opackets = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OERRORS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->oerrors = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_COLLISIONS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
end_define

begin_comment
comment|/* Do nothing; collisions is always 0. */
end_comment

begin_define
define|#
directive|define
name|IXL_SET_IBYTES
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ibytes = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OBYTES
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->obytes = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_IMCASTS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->imcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OMCASTS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->omcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_IQDROPS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->iqdrops = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OQDROPS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->iqdrops = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_NOPROTO
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->noproto = (count)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IXL_SET_IPACKETS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_ipackets = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_IERRORS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_ierrors = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OPACKETS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_opackets = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OERRORS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_oerrors = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_COLLISIONS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_collisions = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_IBYTES
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_ibytes = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OBYTES
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_obytes = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_IMCASTS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_imcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OMCASTS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_omcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_IQDROPS
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->ifp->if_iqdrops = (count)
end_define

begin_define
define|#
directive|define
name|IXL_SET_OQDROPS
parameter_list|(
name|vsi
parameter_list|,
name|odrops
parameter_list|)
value|(vsi)->ifp->if_snd.ifq_drops = (odrops)
end_define

begin_define
define|#
directive|define
name|IXL_SET_NOPROTO
parameter_list|(
name|vsi
parameter_list|,
name|count
parameter_list|)
value|(vsi)->noproto = (count)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *****************************************************************************  * vendor_info_array  *   * This array contains the list of Subvendor/Subdevice IDs on which the driver  * should load.  *   *****************************************************************************  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ixl_vendor_info_t
block|{
name|unsigned
name|int
name|vendor_id
decl_stmt|;
name|unsigned
name|int
name|device_id
decl_stmt|;
name|unsigned
name|int
name|subvendor_id
decl_stmt|;
name|unsigned
name|int
name|subdevice_id
decl_stmt|;
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|ixl_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ixl_tx_buf
block|{
name|u32
name|eop_index
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixl_rx_buf
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_pack
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|fmp
decl_stmt|;
name|bus_dmamap_t
name|hmap
decl_stmt|;
name|bus_dmamap_t
name|pmap
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** This struct has multiple uses, multicast ** addresses, vlans, and mac filters all use it. */
end_comment

begin_struct
struct|struct
name|ixl_mac_filter
block|{
name|SLIST_ENTRY
argument_list|(
argument|ixl_mac_filter
argument_list|)
name|next
expr_stmt|;
name|u8
name|macaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|s16
name|vlan
decl_stmt|;
name|u16
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The Transmit ring control struct  */
end_comment

begin_struct
struct|struct
name|tx_ring
block|{
name|struct
name|ixl_queue
modifier|*
name|que
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|u32
name|tail
decl_stmt|;
name|struct
name|i40e_tx_desc
modifier|*
name|base
decl_stmt|;
name|struct
name|i40e_dma_mem
name|dma
decl_stmt|;
name|u16
name|next_avail
decl_stmt|;
name|u16
name|next_to_clean
decl_stmt|;
name|u16
name|atr_rate
decl_stmt|;
name|u16
name|atr_count
decl_stmt|;
name|u16
name|itr
decl_stmt|;
name|u16
name|latency
decl_stmt|;
name|struct
name|ixl_tx_buf
modifier|*
name|buffers
decl_stmt|;
specifier|volatile
name|u16
name|avail
decl_stmt|;
name|u32
name|cmd
decl_stmt|;
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
name|bus_dma_tag_t
name|tso_tag
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* Used for Dynamic ITR calculation */
name|u32
name|packets
decl_stmt|;
name|u32
name|bytes
decl_stmt|;
comment|/* Soft Stats */
name|u64
name|tx_bytes
decl_stmt|;
name|u64
name|no_desc
decl_stmt|;
name|u64
name|total_packets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The Receive ring control struct  */
end_comment

begin_struct
struct|struct
name|rx_ring
block|{
name|struct
name|ixl_queue
modifier|*
name|que
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|union
name|i40e_rx_desc
modifier|*
name|base
decl_stmt|;
name|struct
name|i40e_dma_mem
name|dma
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|bool
name|lro_enabled
decl_stmt|;
name|bool
name|hdr_split
decl_stmt|;
name|bool
name|discard
decl_stmt|;
name|u16
name|next_refresh
decl_stmt|;
name|u16
name|next_check
decl_stmt|;
name|u16
name|itr
decl_stmt|;
name|u16
name|latency
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|ixl_rx_buf
modifier|*
name|buffers
decl_stmt|;
name|u32
name|mbuf_sz
decl_stmt|;
name|u32
name|tail
decl_stmt|;
name|bus_dma_tag_t
name|htag
decl_stmt|;
name|bus_dma_tag_t
name|ptag
decl_stmt|;
comment|/* Used for Dynamic ITR calculation */
name|u32
name|packets
decl_stmt|;
name|u32
name|bytes
decl_stmt|;
comment|/* Soft stats */
name|u64
name|split
decl_stmt|;
name|u64
name|rx_packets
decl_stmt|;
name|u64
name|rx_bytes
decl_stmt|;
name|u64
name|discarded
decl_stmt|;
name|u64
name|not_done
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Driver queue struct: this is the interrupt container **  for the associated tx and rx ring pair. */
end_comment

begin_struct
struct|struct
name|ixl_queue
block|{
name|struct
name|ixl_vsi
modifier|*
name|vsi
decl_stmt|;
name|u32
name|me
decl_stmt|;
name|u32
name|msix
decl_stmt|;
comment|/* This queue's MSIX vector */
name|u32
name|eims
decl_stmt|;
comment|/* This queue's EIMS bit */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
name|int
name|num_desc
decl_stmt|;
comment|/* both tx and rx */
name|int
name|busy
decl_stmt|;
name|struct
name|tx_ring
name|txr
decl_stmt|;
name|struct
name|rx_ring
name|rxr
decl_stmt|;
name|struct
name|task
name|task
decl_stmt|;
name|struct
name|task
name|tx_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* Queue stats */
name|u64
name|irqs
decl_stmt|;
name|u64
name|tso
decl_stmt|;
name|u64
name|mbuf_defrag_failed
decl_stmt|;
name|u64
name|mbuf_hdr_failed
decl_stmt|;
name|u64
name|mbuf_pkt_failed
decl_stmt|;
name|u64
name|tx_map_avail
decl_stmt|;
name|u64
name|tx_dma_setup
decl_stmt|;
name|u64
name|dropped_pkts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Virtual Station interface:  **	there would be one of these per traffic class/type **	for now just one, and its embedded in the pf */
end_comment

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|ixl_ftl_head
argument_list|,
name|ixl_mac_filter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ixl_vsi
block|{
name|void
modifier|*
name|back
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
name|struct
name|i40e_hw
modifier|*
name|hw
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|u64
name|que_mask
decl_stmt|;
name|int
name|id
decl_stmt|;
name|u16
name|msix_base
decl_stmt|;
comment|/* station base MSIX vector */
name|u16
name|num_queues
decl_stmt|;
name|u16
name|rx_itr_setting
decl_stmt|;
name|u16
name|tx_itr_setting
decl_stmt|;
name|struct
name|ixl_queue
modifier|*
name|queues
decl_stmt|;
comment|/* head of queues */
name|bool
name|link_active
decl_stmt|;
name|u16
name|seid
decl_stmt|;
name|u16
name|max_frame_size
decl_stmt|;
name|u32
name|link_speed
decl_stmt|;
name|bool
name|link_up
decl_stmt|;
name|u32
name|fc
decl_stmt|;
comment|/* local flow ctrl setting */
comment|/* MAC/VLAN Filter list */
name|struct
name|ixl_ftl_head
name|ftl
decl_stmt|;
name|struct
name|i40e_aqc_vsi_properties_data
name|info
decl_stmt|;
name|eventhandler_tag
name|vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vlan_detach
decl_stmt|;
name|u16
name|num_vlans
decl_stmt|;
comment|/* Per-VSI stats from hardware */
name|struct
name|i40e_eth_stats
name|eth_stats
decl_stmt|;
name|struct
name|i40e_eth_stats
name|eth_stats_offsets
decl_stmt|;
name|bool
name|stat_offsets_loaded
decl_stmt|;
name|u64
name|ipackets
decl_stmt|;
name|u64
name|ierrors
decl_stmt|;
name|u64
name|opackets
decl_stmt|;
name|u64
name|oerrors
decl_stmt|;
name|u64
name|ibytes
decl_stmt|;
name|u64
name|obytes
decl_stmt|;
name|u64
name|imcasts
decl_stmt|;
name|u64
name|omcasts
decl_stmt|;
name|u64
name|iqdrops
decl_stmt|;
name|u64
name|oqdrops
decl_stmt|;
name|u64
name|noproto
decl_stmt|;
comment|/* Driver statistics */
name|u64
name|hw_filters_del
decl_stmt|;
name|u64
name|hw_filters_add
decl_stmt|;
comment|/* Misc. */
name|u64
name|active_queues
decl_stmt|;
name|u64
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Find the number of unrefreshed RX descriptors */
end_comment

begin_function
specifier|static
specifier|inline
name|u16
name|ixl_rx_unrefreshed
parameter_list|(
name|struct
name|ixl_queue
modifier|*
name|que
parameter_list|)
block|{
name|struct
name|rx_ring
modifier|*
name|rxr
init|=
operator|&
name|que
operator|->
name|rxr
decl_stmt|;
if|if
condition|(
name|rxr
operator|->
name|next_check
operator|>
name|rxr
operator|->
name|next_refresh
condition|)
return|return
operator|(
name|rxr
operator|->
name|next_check
operator|-
name|rxr
operator|->
name|next_refresh
operator|-
literal|1
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|que
operator|->
name|num_desc
operator|+
name|rxr
operator|->
name|next_check
operator|)
operator|-
name|rxr
operator|->
name|next_refresh
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ** Find the next available unused filter */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|ixl_mac_filter
modifier|*
name|ixl_get_filter
parameter_list|(
name|struct
name|ixl_vsi
modifier|*
name|vsi
parameter_list|)
block|{
name|struct
name|ixl_mac_filter
modifier|*
name|f
decl_stmt|;
comment|/* create a new empty filter */
name|f
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ixl_mac_filter
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
name|SLIST_INSERT_HEAD
argument_list|(
operator|&
name|vsi
operator|->
name|ftl
argument_list|,
name|f
argument_list|,
name|next
argument_list|)
expr_stmt|;
return|return
operator|(
name|f
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ** Compare two ethernet addresses */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|cmp_etheraddr
parameter_list|(
name|u8
modifier|*
name|ea1
parameter_list|,
name|u8
modifier|*
name|ea2
parameter_list|)
block|{
name|bool
name|cmp
init|=
name|FALSE
decl_stmt|;
if|if
condition|(
operator|(
name|ea1
index|[
literal|0
index|]
operator|==
name|ea2
index|[
literal|0
index|]
operator|)
operator|&&
operator|(
name|ea1
index|[
literal|1
index|]
operator|==
name|ea2
index|[
literal|1
index|]
operator|)
operator|&&
operator|(
name|ea1
index|[
literal|2
index|]
operator|==
name|ea2
index|[
literal|2
index|]
operator|)
operator|&&
operator|(
name|ea1
index|[
literal|3
index|]
operator|==
name|ea2
index|[
literal|3
index|]
operator|)
operator|&&
operator|(
name|ea1
index|[
literal|4
index|]
operator|==
name|ea2
index|[
literal|4
index|]
operator|)
operator|&&
operator|(
name|ea1
index|[
literal|5
index|]
operator|==
name|ea2
index|[
literal|5
index|]
operator|)
condition|)
name|cmp
operator|=
name|TRUE
expr_stmt|;
return|return
operator|(
name|cmp
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Info for stats sysctls  */
end_comment

begin_struct
struct|struct
name|ixl_sysctl_info
block|{
name|u64
modifier|*
name|stat
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|description
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|ixl_atr_rate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ** ixl_fw_version_str - format the FW and NVM version strings */
end_comment

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|ixl_fw_version_str
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|32
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"f%d.%d a%d.%d n%02x.%02x e%08x"
argument_list|,
name|hw
operator|->
name|aq
operator|.
name|fw_maj_ver
argument_list|,
name|hw
operator|->
name|aq
operator|.
name|fw_min_ver
argument_list|,
name|hw
operator|->
name|aq
operator|.
name|api_maj_ver
argument_list|,
name|hw
operator|->
name|aq
operator|.
name|api_min_ver
argument_list|,
operator|(
name|hw
operator|->
name|nvm
operator|.
name|version
operator|&
name|IXL_NVM_VERSION_HI_MASK
operator|)
operator|>>
name|IXL_NVM_VERSION_HI_SHIFT
argument_list|,
operator|(
name|hw
operator|->
name|nvm
operator|.
name|version
operator|&
name|IXL_NVM_VERSION_LO_MASK
operator|)
operator|>>
name|IXL_NVM_VERSION_LO_SHIFT
argument_list|,
name|hw
operator|->
name|nvm
operator|.
name|eetrack
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/*********************************************************************  *  TXRX Function prototypes  *********************************************************************/
end_comment

begin_function_decl
name|int
name|ixl_allocate_tx_data
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_allocate_rx_data
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_init_tx_ring
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_init_rx_ring
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixl_rxeof
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixl_txeof
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_mq_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_mq_start_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_deferred_mq_start
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_qflush
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_free_vsi
parameter_list|(
name|struct
name|ixl_vsi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_free_que_tx
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_free_que_rx
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IXL_FDIR
end_ifdef

begin_function_decl
name|void
name|ixl_atr
parameter_list|(
name|struct
name|ixl_queue
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100000
end_if

begin_function_decl
name|uint64_t
name|ixl_get_counter
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|ift_counter
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXL_H_ */
end_comment

end_unit

