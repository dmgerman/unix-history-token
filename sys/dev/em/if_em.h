begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** **************************************************************************  Copyright (c) 2001 Intel Corporation All rights reserved.  Redistribution and use in source and binary forms of the Software, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code of the Software may retain the above     copyright notice, this list of conditions and the following disclaimer.   2. Redistributions in binary form of the Software may reproduce the above     copyright notice, this list of conditions and the following disclaimer     in the documentation and/or other materials provided with the     distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors shall be used to endorse or promote products derived from     this Software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *************************************************************************** ***************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EM_H_DEFINED_
end_ifndef

begin_define
define|#
directive|define
name|_EM_H_DEFINED_
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
file|<net/if.h>
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
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
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
file|<netinet/ip.h>
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
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|"opt_bdg.h"
end_include

begin_include
include|#
directive|include
file|<dev/em/if_em_fxhw.h>
end_include

begin_include
include|#
directive|include
file|<dev/em/if_em_phy.h>
end_include

begin_comment
comment|/* Tunables */
end_comment

begin_define
define|#
directive|define
name|MAX_TXD
value|256
end_define

begin_define
define|#
directive|define
name|MAX_RXD
value|256
end_define

begin_define
define|#
directive|define
name|TX_CLEANUP_THRESHOLD
value|MAX_TXD / 8
end_define

begin_define
define|#
directive|define
name|TIDV
value|128
end_define

begin_define
define|#
directive|define
name|RIDV
value|28
end_define

begin_define
define|#
directive|define
name|DO_AUTO_NEG
value|1
end_define

begin_define
define|#
directive|define
name|WAIT_FOR_AUTO_NEG_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|AUTONEG_ADV_DEFAULT
value|(ADVERTISE_10_HALF | ADVERTISE_10_FULL | \                                          ADVERTISE_100_HALF | ADVERTISE_100_FULL | \                                          ADVERTISE_1000_FULL)
end_define

begin_define
define|#
directive|define
name|EM_ENABLE_RXCSUM_OFFLOAD
value|1
end_define

begin_define
define|#
directive|define
name|EM_REPORT_TX_EARLY
value|2
end_define

begin_define
define|#
directive|define
name|EM_CHECKSUM_FEATURES
value|(CSUM_TCP | CSUM_UDP)
end_define

begin_define
define|#
directive|define
name|EM_MAX_INTR
value|3
end_define

begin_define
define|#
directive|define
name|EM_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/* set to 5 seconds */
end_comment

begin_define
define|#
directive|define
name|EM_JUMBO_ENABLE_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|EM_VENDOR_ID
value|0x8086
end_define

begin_define
define|#
directive|define
name|EM_MMBA
value|0x0010
end_define

begin_comment
comment|/* Mem base address */
end_comment

begin_define
define|#
directive|define
name|EM_ROUNDUP
parameter_list|(
name|size
parameter_list|,
name|unit
parameter_list|)
value|(((size) + (unit) - 1)& ~((unit) - 1))
end_define

begin_define
define|#
directive|define
name|EM_JUMBO_PBA
value|0x00000028
end_define

begin_define
define|#
directive|define
name|EM_DEFAULT_PBA
value|0x00000030
end_define

begin_define
define|#
directive|define
name|IOCTL_CMD_TYPE
value|u_long
end_define

begin_define
define|#
directive|define
name|ETH_LENGTH_OF_ADDRESS
value|ETHER_ADDR_LEN
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_REGISTER
value|PCIR_COMMAND
end_define

begin_define
define|#
directive|define
name|MAX_NUM_MULTICAST_ADDRESSES
value|128
end_define

begin_define
define|#
directive|define
name|PCI_ANY_ID
value|(~0U)
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|CMD_MEM_WRT_INVALIDATE
value|0x0010
end_define

begin_comment
comment|/* Defines for printing debug information */
end_comment

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
name|DEBUG_TXRX
value|0
end_define

begin_define
define|#
directive|define
name|DEBUG_RXCSUM
value|0
end_define

begin_define
define|#
directive|define
name|DEBUG_TXCSUM
value|0
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_INIT)  printf(S "\n")
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_INIT)  printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_INIT)  printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_IOCTL) printf(S "\n")
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_IOCTL) printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_IOCTL) printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_HW) printf(S "\n")
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_HW) printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_HW) printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|TXRX_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_TXRX) printf(S "\n")
end_define

begin_define
define|#
directive|define
name|TXRX_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_TXRX) printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|TXRX_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_TXRX) printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|RXCSUM_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_RXCSUM) printf(S "\n")
end_define

begin_define
define|#
directive|define
name|RXCSUM_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_RXCSUM) printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|RXCSUM_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_RXCSUM) printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|TXCSUM_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_TXCSUM) printf(S "\n")
end_define

begin_define
define|#
directive|define
name|TXCSUM_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_TXCSUM) printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|TXCSUM_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_TXCSUM) printf(S "\n", A, B)
end_define

begin_comment
comment|/* Device ID defines */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_82542
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_82543GC_FIBER
value|0x1001
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_82543GC_COPPER
value|0x1004
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_82544EI_FIBER
value|0x1009
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_82544EI_COPPER
value|0x1008
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_82544GC_STRG
value|0x100C
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_82544GC_COPPER
value|0x100D
end_define

begin_comment
comment|/* Supported RX Buffer Sizes */
end_comment

begin_define
define|#
directive|define
name|EM_RXBUFFER_2048
value|2048
end_define

begin_define
define|#
directive|define
name|EM_RXBUFFER_4096
value|4096
end_define

begin_define
define|#
directive|define
name|EM_RXBUFFER_8192
value|8192
end_define

begin_define
define|#
directive|define
name|EM_RXBUFFER_16384
value|16384
end_define

begin_comment
comment|/* Jumbo Frame */
end_comment

begin_define
define|#
directive|define
name|EM_JSLOTS
value|384
end_define

begin_define
define|#
directive|define
name|EM_JUMBO_FRAMELEN
value|9018
end_define

begin_define
define|#
directive|define
name|EM_JUMBO_MTU
value|(EM_JUMBO_FRAMELEN - ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|EM_JRAWLEN
value|(EM_JUMBO_FRAMELEN + ETHER_ALIGN + sizeof(u_int64_t))
end_define

begin_define
define|#
directive|define
name|EM_JLEN
value|(EM_JRAWLEN + (sizeof(u_int64_t) - \                               (EM_JRAWLEN % sizeof(u_int64_t))))
end_define

begin_define
define|#
directive|define
name|EM_JPAGESZ
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|EM_RESID
value|(EM_JPAGESZ - (EM_JLEN * EM_JSLOTS) % EM_JPAGESZ)
end_define

begin_define
define|#
directive|define
name|EM_JMEM
value|((EM_JLEN * EM_JSLOTS) + EM_RESID)
end_define

begin_struct
struct|struct
name|em_jslot
block|{
name|caddr_t
name|em_buf
decl_stmt|;
name|int
name|em_inuse
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|em_jpool_entry
block|{
name|int
name|slot
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|em_jpool_entry
argument_list|)
name|em_jpool_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ******************************************************************************  * vendor_info_array  *  * This array contains the list of Subvendor/Subdevice IDs on which the driver  * should load.  *  * ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_em_vendor_info_t
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
name|em_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|em_tx_buffer
block|{
name|STAILQ_ENTRY
argument_list|(
argument|em_tx_buffer
argument_list|)
name|em_tx_entry
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|Packet
decl_stmt|;
name|u_int32_t
name|NumTxDescriptorsUsed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ******************************************************************************  * This structure stores information about the 2k aligned receive buffer  * into which the E1000 DMA's frames.   * ******************************************************************************/
end_comment

begin_struct
struct|struct
name|em_rx_buffer
block|{
name|STAILQ_ENTRY
argument_list|(
argument|em_rx_buffer
argument_list|)
name|em_rx_entry
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|Packet
decl_stmt|;
name|u_int32_t
name|LowPhysicalAddress
decl_stmt|;
name|u_int32_t
name|HighPhysicalAddress
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
name|_XSUM_CONTEXT_T
block|{
name|OFFLOAD_NONE
block|,
name|OFFLOAD_TCP_IP
block|,
name|OFFLOAD_UDP_IP
block|}
name|XSUM_CONTEXT_T
typedef|;
end_typedef

begin_comment
comment|/* Our adapter structure */
end_comment

begin_struct
struct|struct
name|adapter
block|{
name|struct
name|arpcom
name|interface_data
decl_stmt|;
name|struct
name|adapter
modifier|*
name|next
decl_stmt|;
name|struct
name|adapter
modifier|*
name|prev
decl_stmt|;
comment|/* FreeBSD operating-system-specific structures */
name|bus_space_tag_t
name|bus_space_tag
decl_stmt|;
name|bus_space_handle_t
name|bus_space_handle
decl_stmt|;
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_memory
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_interrupt
decl_stmt|;
name|void
modifier|*
name|int_handler_tag
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|struct
name|callout_handle
name|timer_handle
decl_stmt|;
name|u_int8_t
name|unit
decl_stmt|;
comment|/* PCI Info */
name|u_int16_t
name|VendorId
decl_stmt|;
name|u_int16_t
name|DeviceId
decl_stmt|;
name|u_int8_t
name|RevId
decl_stmt|;
name|u_int16_t
name|SubVendorId
decl_stmt|;
name|u_int16_t
name|SubSystemId
decl_stmt|;
name|u_int16_t
name|PciCommandWord
decl_stmt|;
comment|/* PCI Bus Info */
name|E1000_BUS_TYPE_ENUM
name|BusType
decl_stmt|;
name|E1000_BUS_SPEED_ENUM
name|BusSpeed
decl_stmt|;
name|E1000_BUS_WIDTH_ENUM
name|BusWidth
decl_stmt|;
comment|/* Info about the board itself */
name|u_int8_t
name|MacType
decl_stmt|;
name|u_int8_t
name|MediaType
decl_stmt|;
name|u_int32_t
name|PhyId
decl_stmt|;
name|u_int32_t
name|PhyAddress
decl_stmt|;
name|uint8_t
name|CurrentNetAddress
index|[
name|ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|uint8_t
name|PermNetAddress
index|[
name|ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u_int32_t
name|PartNumber
decl_stmt|;
name|u_int8_t
name|AdapterStopped
decl_stmt|;
name|u_int8_t
name|DmaFairness
decl_stmt|;
name|u_int8_t
name|ReportTxEarly
decl_stmt|;
name|u_int32_t
name|MulticastFilterType
decl_stmt|;
name|u_int32_t
name|NumberOfMcAddresses
decl_stmt|;
name|u_int8_t
name|MulticastAddressList
index|[
name|MAX_NUM_MULTICAST_ADDRESSES
index|]
index|[
name|ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u_int8_t
name|GetLinkStatus
decl_stmt|;
name|u_int8_t
name|LinkStatusChanged
decl_stmt|;
name|u_int8_t
name|LinkIsActive
decl_stmt|;
name|u_int32_t
name|AutoNegFailed
decl_stmt|;
name|u_int8_t
name|AutoNeg
decl_stmt|;
name|u_int16_t
name|AutoNegAdvertised
decl_stmt|;
name|u_int8_t
name|WaitAutoNegComplete
decl_stmt|;
name|u_int8_t
name|ForcedSpeedDuplex
decl_stmt|;
name|u_int16_t
name|LineSpeed
decl_stmt|;
name|u_int16_t
name|FullDuplex
decl_stmt|;
name|u_int8_t
name|TbiCompatibilityEnable
decl_stmt|;
name|u_int8_t
name|TbiCompatibilityOn
decl_stmt|;
name|u_int32_t
name|TxcwRegValue
decl_stmt|;
name|u_int32_t
name|OriginalFlowControl
decl_stmt|;
name|u_int32_t
name|FlowControl
decl_stmt|;
name|u_int16_t
name|FlowControlHighWatermark
decl_stmt|;
name|u_int16_t
name|FlowControlLowWatermark
decl_stmt|;
name|u_int16_t
name|FlowControlPauseTime
decl_stmt|;
name|u_int8_t
name|FlowControlSendXon
decl_stmt|;
name|u_int32_t
name|MaxFrameSize
decl_stmt|;
name|u_int32_t
name|TxIntDelay
decl_stmt|;
name|u_int32_t
name|RxIntDelay
decl_stmt|;
name|u_int8_t
name|RxChecksum
decl_stmt|;
name|XSUM_CONTEXT_T
name|ActiveChecksumContext
decl_stmt|;
name|u_int8_t
name|MdiX
decl_stmt|;
name|u_int8_t
name|DisablePolarityCorrection
decl_stmt|;
comment|/* Transmit definitions */
name|struct
name|_E1000_TRANSMIT_DESCRIPTOR
modifier|*
name|FirstTxDescriptor
decl_stmt|;
name|struct
name|_E1000_TRANSMIT_DESCRIPTOR
modifier|*
name|LastTxDescriptor
decl_stmt|;
name|struct
name|_E1000_TRANSMIT_DESCRIPTOR
modifier|*
name|NextAvailTxDescriptor
decl_stmt|;
name|struct
name|_E1000_TRANSMIT_DESCRIPTOR
modifier|*
name|OldestUsedTxDescriptor
decl_stmt|;
name|struct
name|_E1000_TRANSMIT_DESCRIPTOR
modifier|*
name|TxDescBase
decl_stmt|;
specifier|volatile
name|u_int16_t
name|NumTxDescriptorsAvail
decl_stmt|;
name|u_int16_t
name|NumTxDescriptors
decl_stmt|;
name|u_int32_t
name|TxdCmd
decl_stmt|;
name|struct
name|em_tx_buffer
modifier|*
name|tx_buffer_area
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument|__em_tx_buffer_free
argument_list|,
argument|em_tx_buffer
argument_list|)
name|FreeSwTxPacketList
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument|__em_tx_buffer_used
argument_list|,
argument|em_tx_buffer
argument_list|)
name|UsedSwTxPacketList
expr_stmt|;
comment|/* Receive definitions */
name|struct
name|_E1000_RECEIVE_DESCRIPTOR
modifier|*
name|FirstRxDescriptor
decl_stmt|;
name|struct
name|_E1000_RECEIVE_DESCRIPTOR
modifier|*
name|LastRxDescriptor
decl_stmt|;
name|struct
name|_E1000_RECEIVE_DESCRIPTOR
modifier|*
name|NextRxDescriptorToCheck
decl_stmt|;
name|struct
name|_E1000_RECEIVE_DESCRIPTOR
modifier|*
name|RxDescBase
decl_stmt|;
name|u_int16_t
name|NumRxDescriptors
decl_stmt|;
name|u_int16_t
name|NumRxDescriptorsEmpty
decl_stmt|;
name|u_int16_t
name|NextRxDescriptorToFill
decl_stmt|;
name|u_int32_t
name|RxBufferLen
decl_stmt|;
name|struct
name|em_rx_buffer
modifier|*
name|rx_buffer_area
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument|__em_rx_buffer
argument_list|,
argument|em_rx_buffer
argument_list|)
name|RxSwPacketList
expr_stmt|;
comment|/* Jumbo frame */
name|u_int8_t
name|JumboEnable
decl_stmt|;
name|struct
name|em_jslot
name|em_jslots
index|[
name|EM_JSLOTS
index|]
decl_stmt|;
name|void
modifier|*
name|em_jumbo_buf
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__em_jfreehead
argument_list|,
argument|em_jpool_entry
argument_list|)
name|em_jfree_listhead
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__em_jinusehead
argument_list|,
argument|em_jpool_entry
argument_list|)
name|em_jinuse_listhead
expr_stmt|;
comment|/* Misc stats maintained by the driver */
name|unsigned
name|long
name|DroppedPackets
decl_stmt|;
name|unsigned
name|long
name|NoJumboBufAvail
decl_stmt|;
name|unsigned
name|long
name|JumboMbufFailed
decl_stmt|;
name|unsigned
name|long
name|JumboClusterFailed
decl_stmt|;
name|unsigned
name|long
name|StdMbufFailed
decl_stmt|;
name|unsigned
name|long
name|StdClusterFailed
decl_stmt|;
ifdef|#
directive|ifdef
name|DBG_STATS
name|unsigned
name|long
name|NoTxDescAvail
decl_stmt|;
name|unsigned
name|long
name|NoPacketsAvail
decl_stmt|;
name|unsigned
name|long
name|CleanTxInterrupts
decl_stmt|;
name|unsigned
name|long
name|NoTxBufferAvail1
decl_stmt|;
name|unsigned
name|long
name|NoTxBufferAvail2
decl_stmt|;
endif|#
directive|endif
comment|/* Statistics registers present in the 82542 */
name|unsigned
name|long
name|Crcerrs
decl_stmt|;
name|unsigned
name|long
name|Symerrs
decl_stmt|;
name|unsigned
name|long
name|Mpc
decl_stmt|;
name|unsigned
name|long
name|Scc
decl_stmt|;
name|unsigned
name|long
name|Ecol
decl_stmt|;
name|unsigned
name|long
name|Mcc
decl_stmt|;
name|unsigned
name|long
name|Latecol
decl_stmt|;
name|unsigned
name|long
name|Colc
decl_stmt|;
name|unsigned
name|long
name|Dc
decl_stmt|;
name|unsigned
name|long
name|Sec
decl_stmt|;
name|unsigned
name|long
name|Rlec
decl_stmt|;
name|unsigned
name|long
name|Xonrxc
decl_stmt|;
name|unsigned
name|long
name|Xontxc
decl_stmt|;
name|unsigned
name|long
name|Xoffrxc
decl_stmt|;
name|unsigned
name|long
name|Xofftxc
decl_stmt|;
name|unsigned
name|long
name|Fcruc
decl_stmt|;
name|unsigned
name|long
name|Prc64
decl_stmt|;
name|unsigned
name|long
name|Prc127
decl_stmt|;
name|unsigned
name|long
name|Prc255
decl_stmt|;
name|unsigned
name|long
name|Prc511
decl_stmt|;
name|unsigned
name|long
name|Prc1023
decl_stmt|;
name|unsigned
name|long
name|Prc1522
decl_stmt|;
name|unsigned
name|long
name|Gprc
decl_stmt|;
name|unsigned
name|long
name|Bprc
decl_stmt|;
name|unsigned
name|long
name|Mprc
decl_stmt|;
name|unsigned
name|long
name|Gptc
decl_stmt|;
name|unsigned
name|long
name|Gorcl
decl_stmt|;
name|unsigned
name|long
name|Gorch
decl_stmt|;
name|unsigned
name|long
name|Gotcl
decl_stmt|;
name|unsigned
name|long
name|Gotch
decl_stmt|;
name|unsigned
name|long
name|Rnbc
decl_stmt|;
name|unsigned
name|long
name|Ruc
decl_stmt|;
name|unsigned
name|long
name|Rfc
decl_stmt|;
name|unsigned
name|long
name|Roc
decl_stmt|;
name|unsigned
name|long
name|Rjc
decl_stmt|;
name|unsigned
name|long
name|Torcl
decl_stmt|;
name|unsigned
name|long
name|Torch
decl_stmt|;
name|unsigned
name|long
name|Totcl
decl_stmt|;
name|unsigned
name|long
name|Totch
decl_stmt|;
name|unsigned
name|long
name|Tpr
decl_stmt|;
name|unsigned
name|long
name|Tpt
decl_stmt|;
name|unsigned
name|long
name|Ptc64
decl_stmt|;
name|unsigned
name|long
name|Ptc127
decl_stmt|;
name|unsigned
name|long
name|Ptc255
decl_stmt|;
name|unsigned
name|long
name|Ptc511
decl_stmt|;
name|unsigned
name|long
name|Ptc1023
decl_stmt|;
name|unsigned
name|long
name|Ptc1522
decl_stmt|;
name|unsigned
name|long
name|Mptc
decl_stmt|;
name|unsigned
name|long
name|Bptc
decl_stmt|;
comment|/* Statistics registers added in the 82543 */
name|unsigned
name|long
name|Algnerrc
decl_stmt|;
name|unsigned
name|long
name|Rxerrc
decl_stmt|;
name|unsigned
name|long
name|Tuc
decl_stmt|;
name|unsigned
name|long
name|Tncrs
decl_stmt|;
name|unsigned
name|long
name|Cexterr
decl_stmt|;
name|unsigned
name|long
name|Rutec
decl_stmt|;
name|unsigned
name|long
name|Tsctc
decl_stmt|;
name|unsigned
name|long
name|Tsctfc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|em_adjust_tbi_accepted_stats
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|u32
name|FrameLength
parameter_list|,
name|u8
modifier|*
name|MacAddress
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EM_H_DEFINED_ */
end_comment

end_unit

