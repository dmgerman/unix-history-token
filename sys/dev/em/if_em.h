begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2001 Intel Corporation All rights reserved.  Redistribution and use in source and binary forms of the Software, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code of the Software may retain the above     copyright notice, this list of conditions and the following disclaimer.   2. Redistributions in binary form of the Software may reproduce the above     copyright notice, this list of conditions and the following disclaimer     in the documentation and/or other materials provided with the     distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors shall be used to endorse or promote products derived from     this Software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
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
name|struct
name|em_shared_adapter
name|shared
decl_stmt|;
comment|/* FreeBSD operating-system-specific structures */
name|struct
name|em_osdep
name|osdep
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
comment|/* Info about the board itself */
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
name|MulticastAddressList
index|[
name|MAX_NUM_MULTICAST_ADDRESSES
index|]
index|[
name|ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u_int8_t
name|LinkStatusChanged
decl_stmt|;
name|u_int8_t
name|LinkIsActive
decl_stmt|;
name|u_int16_t
name|LineSpeed
decl_stmt|;
name|u_int16_t
name|FullDuplex
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
comment|/* Transmit definitions */
name|struct
name|em_tx_desc
modifier|*
name|FirstTxDescriptor
decl_stmt|;
name|struct
name|em_tx_desc
modifier|*
name|LastTxDescriptor
decl_stmt|;
name|struct
name|em_tx_desc
modifier|*
name|NextAvailTxDescriptor
decl_stmt|;
name|struct
name|em_tx_desc
modifier|*
name|OldestUsedTxDescriptor
decl_stmt|;
name|struct
name|em_tx_desc
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
name|em_rx_desc
modifier|*
name|FirstRxDescriptor
decl_stmt|;
name|struct
name|em_rx_desc
modifier|*
name|LastRxDescriptor
decl_stmt|;
name|struct
name|em_rx_desc
modifier|*
name|NextRxDescriptorToCheck
decl_stmt|;
name|struct
name|em_rx_desc
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
name|struct
name|mbuf
modifier|*
name|fmp
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|lmp
decl_stmt|;
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
name|struct
name|em_shared_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EM_H_DEFINED_ */
end_comment

end_unit

