begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_nfereg.h,v 1.16 2006/02/22 19:23:44 damien Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005 Jonathan Gray<jsg@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NFE_PCI_BA
value|0x10
end_define

begin_define
define|#
directive|define
name|NFE_RX_RING_COUNT
value|128
end_define

begin_define
define|#
directive|define
name|NFE_TX_RING_COUNT
value|256
end_define

begin_comment
comment|/* RX/TX MAC addr + type + VLAN + align + slack */
end_comment

begin_define
define|#
directive|define
name|NFE_RX_HEADERS
value|64
end_define

begin_comment
comment|/* Maximum MTU size. */
end_comment

begin_define
define|#
directive|define
name|NV_PKTLIMIT_1
value|ETH_DATA_LEN
end_define

begin_comment
comment|/* Hard limit not known. */
end_comment

begin_define
define|#
directive|define
name|NV_PKTLIMIT_2
value|9100
end_define

begin_comment
comment|/* Actual limit according to NVidia:9202 */
end_comment

begin_define
define|#
directive|define
name|NFE_JBYTES
value|(ETHER_MAX_LEN_JUMBO + ETHER_ALIGN)
end_define

begin_define
define|#
directive|define
name|NFE_JPOOL_COUNT
value|(NFE_RX_RING_COUNT + NFE_RX_HEADERS)
end_define

begin_define
define|#
directive|define
name|NFE_MAX_SCATTER
value|(NFE_TX_RING_COUNT - 2)
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_STATUS
value|0x000
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_MASK
value|0x004
end_define

begin_define
define|#
directive|define
name|NFE_SETUP_R6
value|0x008
end_define

begin_define
define|#
directive|define
name|NFE_IMTIMER
value|0x00c
end_define

begin_define
define|#
directive|define
name|NFE_MISC1
value|0x080
end_define

begin_define
define|#
directive|define
name|NFE_TX_CTL
value|0x084
end_define

begin_define
define|#
directive|define
name|NFE_TX_STATUS
value|0x088
end_define

begin_define
define|#
directive|define
name|NFE_RXFILTER
value|0x08c
end_define

begin_define
define|#
directive|define
name|NFE_RXBUFSZ
value|0x090
end_define

begin_define
define|#
directive|define
name|NFE_RX_CTL
value|0x094
end_define

begin_define
define|#
directive|define
name|NFE_RX_STATUS
value|0x098
end_define

begin_define
define|#
directive|define
name|NFE_RNDSEED
value|0x09c
end_define

begin_define
define|#
directive|define
name|NFE_SETUP_R1
value|0x0a0
end_define

begin_define
define|#
directive|define
name|NFE_SETUP_R2
value|0x0a4
end_define

begin_define
define|#
directive|define
name|NFE_MACADDR_HI
value|0x0a8
end_define

begin_define
define|#
directive|define
name|NFE_MACADDR_LO
value|0x0ac
end_define

begin_define
define|#
directive|define
name|NFE_MULTIADDR_HI
value|0x0b0
end_define

begin_define
define|#
directive|define
name|NFE_MULTIADDR_LO
value|0x0b4
end_define

begin_define
define|#
directive|define
name|NFE_MULTIMASK_HI
value|0x0b8
end_define

begin_define
define|#
directive|define
name|NFE_MULTIMASK_LO
value|0x0bc
end_define

begin_define
define|#
directive|define
name|NFE_PHY_IFACE
value|0x0c0
end_define

begin_define
define|#
directive|define
name|NFE_TX_RING_ADDR_LO
value|0x100
end_define

begin_define
define|#
directive|define
name|NFE_RX_RING_ADDR_LO
value|0x104
end_define

begin_define
define|#
directive|define
name|NFE_RING_SIZE
value|0x108
end_define

begin_define
define|#
directive|define
name|NFE_TX_UNK
value|0x10c
end_define

begin_define
define|#
directive|define
name|NFE_LINKSPEED
value|0x110
end_define

begin_define
define|#
directive|define
name|NFE_SETUP_R5
value|0x130
end_define

begin_define
define|#
directive|define
name|NFE_SETUP_R3
value|0x13C
end_define

begin_define
define|#
directive|define
name|NFE_SETUP_R7
value|0x140
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_CTL
value|0x144
end_define

begin_define
define|#
directive|define
name|NFE_TX_RING_ADDR_HI
value|0x148
end_define

begin_define
define|#
directive|define
name|NFE_RX_RING_ADDR_HI
value|0x14c
end_define

begin_define
define|#
directive|define
name|NFE_PHY_STATUS
value|0x180
end_define

begin_define
define|#
directive|define
name|NFE_SETUP_R4
value|0x184
end_define

begin_define
define|#
directive|define
name|NFE_STATUS
value|0x188
end_define

begin_define
define|#
directive|define
name|NFE_PHY_SPEED
value|0x18c
end_define

begin_define
define|#
directive|define
name|NFE_PHY_CTL
value|0x190
end_define

begin_define
define|#
directive|define
name|NFE_PHY_DATA
value|0x194
end_define

begin_define
define|#
directive|define
name|NFE_WOL_CTL
value|0x200
end_define

begin_define
define|#
directive|define
name|NFE_PATTERN_CRC
value|0x204
end_define

begin_define
define|#
directive|define
name|NFE_PATTERN_MASK
value|0x208
end_define

begin_define
define|#
directive|define
name|NFE_PWR_CAP
value|0x268
end_define

begin_define
define|#
directive|define
name|NFE_PWR_STATE
value|0x26c
end_define

begin_define
define|#
directive|define
name|NFE_VTAG_CTL
value|0x300
end_define

begin_define
define|#
directive|define
name|NFE_PHY_ERROR
value|0x00001
end_define

begin_define
define|#
directive|define
name|NFE_PHY_WRITE
value|0x00400
end_define

begin_define
define|#
directive|define
name|NFE_PHY_BUSY
value|0x08000
end_define

begin_define
define|#
directive|define
name|NFE_PHYADD_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|NFE_STATUS_MAGIC
value|0x140000
end_define

begin_define
define|#
directive|define
name|NFE_R1_MAGIC
value|0x16070f
end_define

begin_define
define|#
directive|define
name|NFE_R2_MAGIC
value|0x16
end_define

begin_define
define|#
directive|define
name|NFE_R4_MAGIC
value|0x08
end_define

begin_define
define|#
directive|define
name|NFE_R6_MAGIC
value|0x03
end_define

begin_define
define|#
directive|define
name|NFE_WOL_MAGIC
value|0x1111
end_define

begin_define
define|#
directive|define
name|NFE_RX_START
value|0x01
end_define

begin_define
define|#
directive|define
name|NFE_TX_START
value|0x01
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_RXERR
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_RX
value|0x0002
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_RX_NOBUF
value|0x0004
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_TXERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_TX_DONE
value|0x0010
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_TIMER
value|0x0020
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_LINK
value|0x0040
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_TXERR2
value|0x0080
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_TX1
value|0x0100
end_define

begin_define
define|#
directive|define
name|NFE_IRQ_WANTED
define|\
value|(NFE_IRQ_RXERR | NFE_IRQ_RX_NOBUF | NFE_IRQ_RX |		\ 	 NFE_IRQ_TXERR | NFE_IRQ_TXERR2 | NFE_IRQ_TX_DONE |		\ 	 NFE_IRQ_LINK)
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_KICKTX
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_BIT1
value|0x0002
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_BIT2
value|0x0004
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_RESET
value|0x0010
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_VTAG_STRIP
value|0x0040
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_VTAG_INSERT
value|0x0080
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_RXCSUM
value|0x0400
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_V2MAGIC
value|0x2100
end_define

begin_define
define|#
directive|define
name|NFE_RXTX_V3MAGIC
value|0x2200
end_define

begin_define
define|#
directive|define
name|NFE_RXFILTER_MAGIC
value|0x007f0008
end_define

begin_define
define|#
directive|define
name|NFE_U2M
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|NFE_PROMISC
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|NFE_CSUM_FEATURES
value|(CSUM_IP | CSUM_TCP | CSUM_UDP)
end_define

begin_comment
comment|/* default interrupt moderation timer of 128us */
end_comment

begin_define
define|#
directive|define
name|NFE_IM_DEFAULT
value|((128 * 100) / 1024)
end_define

begin_define
define|#
directive|define
name|NFE_VTAG_ENABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|NFE_PWR_VALID
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|NFE_PWR_WAKEUP
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|NFE_MEDIA_SET
value|0x10000
end_define

begin_define
define|#
directive|define
name|NFE_MEDIA_1000T
value|0x00032
end_define

begin_define
define|#
directive|define
name|NFE_MEDIA_100TX
value|0x00064
end_define

begin_define
define|#
directive|define
name|NFE_MEDIA_10T
value|0x003e8
end_define

begin_define
define|#
directive|define
name|NFE_PHY_100TX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|NFE_PHY_1000T
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|NFE_PHY_HDX
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|NFE_MISC1_MAGIC
value|0x003b0f3c
end_define

begin_define
define|#
directive|define
name|NFE_MISC1_HDX
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|NFE_SEED_MASK
value|0x0003ff00
end_define

begin_define
define|#
directive|define
name|NFE_SEED_10T
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|NFE_SEED_100TX
value|0x00002d00
end_define

begin_define
define|#
directive|define
name|NFE_SEED_1000T
value|0x00007400
end_define

begin_comment
comment|/* Rx/Tx descriptor */
end_comment

begin_struct
struct|struct
name|nfe_desc32
block|{
name|uint32_t
name|physaddr
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|NFE_RX_FIXME_V1
value|0x6004
define|#
directive|define
name|NFE_RX_VALID_V1
value|(1<< 0)
define|#
directive|define
name|NFE_TX_ERROR_V1
value|0x7808
define|#
directive|define
name|NFE_TX_LASTFRAG_V1
value|(1<< 0)
define|#
directive|define
name|NFE_RX_ERROR1_V1
value|(1<<7)
define|#
directive|define
name|NFE_RX_ERROR2_V1
value|(1<<8)
define|#
directive|define
name|NFE_RX_ERROR3_V1
value|(1<<9)
define|#
directive|define
name|NFE_RX_ERROR4_V1
value|(1<<10)
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|NFE_V1_TXERR
value|"\020"	\ 	"\14TXERROR\13UNDERFLOW\12LATECOLLISION\11LOSTCARRIER\10DEFERRED" \ 	"\08FORCEDINT\03RETRY\00LASTPACKET"
end_define

begin_comment
comment|/* V2 Rx/Tx descriptor */
end_comment

begin_struct
struct|struct
name|nfe_desc64
block|{
name|uint32_t
name|physaddr
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|vtag
decl_stmt|;
define|#
directive|define
name|NFE_RX_VTAG
value|(1<< 16)
define|#
directive|define
name|NFE_TX_VTAG
value|(1<< 18)
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|NFE_RX_FIXME_V2
value|0x4300
define|#
directive|define
name|NFE_RX_VALID_V2
value|(1<< 13)
define|#
directive|define
name|NFE_TX_ERROR_V2
value|0x5c04
define|#
directive|define
name|NFE_TX_LASTFRAG_V2
value|(1<< 13)
define|#
directive|define
name|NFE_RX_IP_CSUMOK_V2
value|0x1000
define|#
directive|define
name|NFE_RX_UDP_CSUMOK_V2
value|0x1400
define|#
directive|define
name|NFE_RX_TCP_CSUMOK_V2
value|0x1800
define|#
directive|define
name|NFE_RX_ERROR1_V2
value|(1<<2)
define|#
directive|define
name|NFE_RX_ERROR2_V2
value|(1<<3)
define|#
directive|define
name|NFE_RX_ERROR3_V2
value|(1<<4)
define|#
directive|define
name|NFE_RX_ERROR4_V2
value|(1<<5)
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|NFE_V2_TXERR
value|"\020"	\ 	"\14FORCEDINT\13LASTPACKET\12UNDERFLOW\10LOSTCARRIER\09DEFERRED\02RETRY"
end_define

begin_comment
comment|/* flags common to V1/V2 descriptors */
end_comment

begin_define
define|#
directive|define
name|NFE_RX_CSUMOK
value|0x1c00
end_define

begin_define
define|#
directive|define
name|NFE_RX_ERROR
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|NFE_RX_READY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|NFE_TX_TCP_CSUM
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|NFE_TX_IP_CSUM
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|NFE_TX_VALID
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|NFE_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->nfe_memt, (sc)->nfe_memh, (reg))
end_define

begin_define
define|#
directive|define
name|NFE_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->nfe_memt, (sc)->nfe_memh, (reg), (val))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_NVIDIA
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_NVIDIA
value|0x10DE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE_LAN
value|0x01C3
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE2_LAN
value|0x0066
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE3_LAN1
value|0x00D6
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE2_400_LAN1
value|0x0086
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE2_400_LAN2
value|0x008C
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE3_250_LAN
value|0x00E6
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE3_LAN4
value|0x00DF
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE4_LAN1
value|0x0056
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE4_LAN2
value|0x0057
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP04_LAN1
value|0x0037
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP04_LAN2
value|0x0038
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE430_LAN1
value|0x0268
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE430_LAN2
value|0x0269
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP55_LAN1
value|0x0372
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP55_LAN2
value|0x0373
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP61_LAN1
value|0x03e5
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP61_LAN2
value|0x03e6
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP61_LAN3
value|0x03ee
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP61_LAN4
value|0x03ef
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP65_LAN1
value|0x0450
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP65_LAN2
value|0x0451
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP65_LAN3
value|0x0452
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP65_LAN4
value|0x0453
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE3_LAN2
value|PCI_PRODUCT_NVIDIA_NFORCE2_400_LAN1
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE3_LAN3
value|PCI_PRODUCT_NVIDIA_NFORCE2_400_LAN2
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_NFORCE3_LAN5
value|PCI_PRODUCT_NVIDIA_NFORCE3_250_LAN
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_CK804_LAN1
value|PCI_PRODUCT_NVIDIA_NFORCE4_LAN1
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_CK804_LAN2
value|PCI_PRODUCT_NVIDIA_NFORCE4_LAN2
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP51_LAN1
value|PCI_PRODUCT_NVIDIA_NFORCE430_LAN1
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_NVIDIA_MCP51_LAN2
value|PCI_PRODUCT_NVIDIA_NFORCE430_LAN2
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG
value|0x0000
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_INIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_RUNNING
value|0x0002
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_DEINIT
value|0x0004
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_IOCTL
value|0x0008
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_INTERRUPT
value|0x0010
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_API
value|0x0020
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_LOCK
value|0x0040
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_BROKEN
value|0x0080
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_MII
value|0x0100
end_define

begin_define
define|#
directive|define
name|NFE_DEBUG_ALL
value|0xFFFF
end_define

end_unit

