begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2007   *	Oleksandr Tymoshenko<gonzo@freebsd.org>. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_AREREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_AREREG_H__
end_define

begin_struct
struct|struct
name|are_desc
block|{
name|uint32_t
name|are_stat
decl_stmt|;
name|uint32_t
name|are_devcs
decl_stmt|;
name|uint32_t
name|are_addr
decl_stmt|;
name|uint32_t
name|are_link
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARE_DMASIZE
parameter_list|(
name|len
parameter_list|)
value|((len)& ((1<< 11)-1))
end_define

begin_define
define|#
directive|define
name|ARE_PKTSIZE
parameter_list|(
name|len
parameter_list|)
value|((len& 0xffff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|ARE_RX_RING_CNT
value|128
end_define

begin_define
define|#
directive|define
name|ARE_TX_RING_CNT
value|128
end_define

begin_define
define|#
directive|define
name|ARE_TX_RING_SIZE
value|sizeof(struct are_desc) * ARE_TX_RING_CNT
end_define

begin_define
define|#
directive|define
name|ARE_RX_RING_SIZE
value|sizeof(struct are_desc) * ARE_RX_RING_CNT
end_define

begin_define
define|#
directive|define
name|ARE_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|ARE_RING_ALIGN
value|sizeof(struct are_desc)
end_define

begin_define
define|#
directive|define
name|ARE_RX_ALIGN
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|ARE_MAXFRAGS
value|8
end_define

begin_define
define|#
directive|define
name|ARE_TX_INTR_THRESH
value|8
end_define

begin_define
define|#
directive|define
name|ARE_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->are_rdata.are_tx_ring_paddr + sizeof(struct are_desc) * (i))
end_define

begin_define
define|#
directive|define
name|ARE_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->are_rdata.are_rx_ring_paddr + sizeof(struct are_desc) * (i))
end_define

begin_define
define|#
directive|define
name|ARE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (((x) + 1) % y)
end_define

begin_struct
struct|struct
name|are_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|are_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
name|struct
name|are_desc
modifier|*
name|desc
decl_stmt|;
comment|/* Use this values on error instead of allocating new mbuf */
name|uint32_t
name|saved_ctl
decl_stmt|,
name|saved_ca
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|are_chain_data
block|{
name|bus_dma_tag_t
name|are_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|are_tx_tag
decl_stmt|;
name|struct
name|are_txdesc
name|are_txdesc
index|[
name|ARE_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|are_rx_tag
decl_stmt|;
name|struct
name|are_rxdesc
name|are_rxdesc
index|[
name|ARE_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|are_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|are_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|are_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|are_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|are_rx_sparemap
decl_stmt|;
name|int
name|are_tx_pkts
decl_stmt|;
name|int
name|are_tx_prod
decl_stmt|;
name|int
name|are_tx_cons
decl_stmt|;
name|int
name|are_tx_cnt
decl_stmt|;
name|int
name|are_rx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|are_ring_data
block|{
name|struct
name|are_desc
modifier|*
name|are_rx_ring
decl_stmt|;
name|struct
name|are_desc
modifier|*
name|are_tx_ring
decl_stmt|;
name|bus_addr_t
name|are_rx_ring_paddr
decl_stmt|;
name|bus_addr_t
name|are_tx_ring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|are_softc
block|{
name|struct
name|ifnet
modifier|*
name|are_ifp
decl_stmt|;
comment|/* interface info */
name|bus_space_handle_t
name|are_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|are_btag
decl_stmt|;
comment|/* bus space tag */
name|device_t
name|are_dev
decl_stmt|;
name|uint8_t
name|are_eaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|are_res
decl_stmt|;
name|int
name|are_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|are_irq
decl_stmt|;
name|void
modifier|*
name|are_intrhand
decl_stmt|;
name|u_int32_t
name|sc_inten
decl_stmt|;
comment|/* copy of CSR_INTEN */
name|u_int32_t
name|sc_rxint_mask
decl_stmt|;
comment|/* mask of Rx interrupts we want */
name|u_int32_t
name|sc_txint_mask
decl_stmt|;
comment|/* mask of Tx interrupts we want */
ifdef|#
directive|ifdef
name|ARE_MII
name|device_t
name|are_miibus
decl_stmt|;
else|#
directive|else
name|struct
name|ifmedia
name|are_ifmedia
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ARE_MDIO
name|device_t
name|are_miiproxy
decl_stmt|;
endif|#
directive|endif
name|bus_dma_tag_t
name|are_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|are_tag
decl_stmt|;
name|struct
name|mtx
name|are_mtx
decl_stmt|;
name|struct
name|callout
name|are_stat_callout
decl_stmt|;
name|struct
name|task
name|are_link_task
decl_stmt|;
name|struct
name|are_chain_data
name|are_cdata
decl_stmt|;
name|struct
name|are_ring_data
name|are_rdata
decl_stmt|;
name|int
name|are_link_status
decl_stmt|;
name|int
name|are_detach
decl_stmt|;
name|int
name|are_if_flags
decl_stmt|;
comment|/* last if flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->are_mtx)
end_define

begin_define
define|#
directive|define
name|ARE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->are_mtx)
end_define

begin_define
define|#
directive|define
name|ARE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->are_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->are_btag, sc->are_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->are_btag, sc->are_bhandle, reg)
end_define

begin_comment
comment|/*	$NetBSD: aereg.h,v 1.2 2008/04/28 20:23:28 martin Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999, 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Descriptor Status bits common to transmit and receive.  */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_OWN
value|0x80000000
end_define

begin_comment
comment|/* Tulip owns descriptor */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_ES
value|0x00008000
end_define

begin_comment
comment|/* Error Summary */
end_comment

begin_comment
comment|/*  * Descriptor Status bits for Receive Descriptor.  */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_FF
value|0x40000000
end_define

begin_comment
comment|/* Filtering Fail */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_FL
value|0x3fff0000
end_define

begin_comment
comment|/* Frame Length including CRC */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_DE
value|0x00004000
end_define

begin_comment
comment|/* Descriptor Error */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_LE
value|0x00001000
end_define

begin_comment
comment|/* Length Error */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_RF
value|0x00000800
end_define

begin_comment
comment|/* Runt Frame */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_MF
value|0x00000400
end_define

begin_comment
comment|/* Multicast Frame */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_FS
value|0x00000200
end_define

begin_comment
comment|/* First Descriptor */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_LS
value|0x00000100
end_define

begin_comment
comment|/* Last Descriptor */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_TL
value|0x00000080
end_define

begin_comment
comment|/* Frame Too Long */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_CS
value|0x00000040
end_define

begin_comment
comment|/* Collision Seen */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_RT
value|0x00000020
end_define

begin_comment
comment|/* Frame Type */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_RW
value|0x00000010
end_define

begin_comment
comment|/* Receive Watchdog */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_RE
value|0x00000008
end_define

begin_comment
comment|/* Report on MII Error */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_DB
value|0x00000004
end_define

begin_comment
comment|/* Dribbling Bit */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_CE
value|0x00000002
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_ZER
value|0x00000001
end_define

begin_comment
comment|/* Zero (always 0) */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Rx_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& ADSTAT_Rx_FL)>> 16)
end_define

begin_comment
comment|/*  * Descriptor Status bits for Transmit Descriptor.  */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_ES
value|0x00008000
end_define

begin_comment
comment|/* Error Summary */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_TO
value|0x00004000
end_define

begin_comment
comment|/* Transmit Jabber Timeout */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_LO
value|0x00000800
end_define

begin_comment
comment|/* Loss of Carrier */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_NC
value|0x00000400
end_define

begin_comment
comment|/* No Carrier */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_LC
value|0x00000200
end_define

begin_comment
comment|/* Late Collision */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_EC
value|0x00000100
end_define

begin_comment
comment|/* Excessive Collisions */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_HF
value|0x00000080
end_define

begin_comment
comment|/* Heartbeat Fail */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_CC
value|0x00000078
end_define

begin_comment
comment|/* Collision Count */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_ED
value|0x00000004
end_define

begin_comment
comment|/* Excessive Deferral */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_UF
value|0x00000002
end_define

begin_comment
comment|/* Underflow Error */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_DE
value|0x00000001
end_define

begin_comment
comment|/* Deferred */
end_comment

begin_define
define|#
directive|define
name|ADSTAT_Tx_COLLISIONS
parameter_list|(
name|x
parameter_list|)
value|(((x)& ADSTAT_Tx_CC)>> 3)
end_define

begin_comment
comment|/*  * Descriptor Control bits common to transmit and receive.  */
end_comment

begin_define
define|#
directive|define
name|ADCTL_SIZE1
value|0x000007ff
end_define

begin_comment
comment|/* Size of buffer 1 */
end_comment

begin_define
define|#
directive|define
name|ADCTL_SIZE1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ADCTL_SIZE2
value|0x003ff800
end_define

begin_comment
comment|/* Size of buffer 2 */
end_comment

begin_define
define|#
directive|define
name|ADCTL_SIZE2_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|ADCTL_ER
value|0x02000000
end_define

begin_comment
comment|/* End of Ring */
end_comment

begin_define
define|#
directive|define
name|ADCTL_CH
value|0x01000000
end_define

begin_comment
comment|/* Second Address Chained */
end_comment

begin_comment
comment|/*  * Descriptor Control bits for Transmit Descriptor.  */
end_comment

begin_define
define|#
directive|define
name|ADCTL_Tx_IC
value|0x80000000
end_define

begin_comment
comment|/* Interrupt on Completion */
end_comment

begin_define
define|#
directive|define
name|ADCTL_Tx_LS
value|0x40000000
end_define

begin_comment
comment|/* Last Segment */
end_comment

begin_define
define|#
directive|define
name|ADCTL_Tx_FS
value|0x20000000
end_define

begin_comment
comment|/* First Segment */
end_comment

begin_define
define|#
directive|define
name|ADCTL_Tx_AC
value|0x04000000
end_define

begin_comment
comment|/* Add CRC Disable */
end_comment

begin_define
define|#
directive|define
name|ADCTL_Tx_DPD
value|0x00800000
end_define

begin_comment
comment|/* Disabled Padding */
end_comment

begin_comment
comment|/*  * Control registers.  */
end_comment

begin_comment
comment|/* tese are registers only found on this part */
end_comment

begin_define
define|#
directive|define
name|CSR_MACCTL
value|0x0000
end_define

begin_comment
comment|/* mac control */
end_comment

begin_define
define|#
directive|define
name|CSR_MACHI
value|0x0004
end_define

begin_define
define|#
directive|define
name|CSR_MACLO
value|0x0008
end_define

begin_define
define|#
directive|define
name|CSR_HTHI
value|0x000C
end_define

begin_comment
comment|/* multicast table high */
end_comment

begin_define
define|#
directive|define
name|CSR_HTLO
value|0x0010
end_define

begin_comment
comment|/* multicast table low */
end_comment

begin_define
define|#
directive|define
name|CSR_MIIADDR
value|0x0014
end_define

begin_comment
comment|/* mii address */
end_comment

begin_define
define|#
directive|define
name|CSR_MIIDATA
value|0x0018
end_define

begin_comment
comment|/* mii data */
end_comment

begin_define
define|#
directive|define
name|CSR_FLOWC
value|0x001C
end_define

begin_comment
comment|/* flow control */
end_comment

begin_define
define|#
directive|define
name|CSR_VL1
value|0x0020
end_define

begin_comment
comment|/* vlan 1 tag */
end_comment

begin_comment
comment|/* these are more or less normal Tulip registers */
end_comment

begin_define
define|#
directive|define
name|CSR_BUSMODE
value|0x1000
end_define

begin_comment
comment|/* bus mode */
end_comment

begin_define
define|#
directive|define
name|CSR_TXPOLL
value|0x1004
end_define

begin_comment
comment|/* tx poll demand */
end_comment

begin_define
define|#
directive|define
name|CSR_RXPOLL
value|0x1008
end_define

begin_comment
comment|/* rx poll demand */
end_comment

begin_define
define|#
directive|define
name|CSR_RXLIST
value|0x100C
end_define

begin_comment
comment|/* rx base descriptor address */
end_comment

begin_define
define|#
directive|define
name|CSR_TXLIST
value|0x1010
end_define

begin_comment
comment|/* tx base descriptor address */
end_comment

begin_define
define|#
directive|define
name|CSR_STATUS
value|0x1014
end_define

begin_comment
comment|/* (interrupt) status */
end_comment

begin_define
define|#
directive|define
name|CSR_OPMODE
value|0x1018
end_define

begin_comment
comment|/* operation mode */
end_comment

begin_define
define|#
directive|define
name|CSR_INTEN
value|0x101C
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CSR_MISSED
value|0x1020
end_define

begin_comment
comment|/* missed frame counter */
end_comment

begin_define
define|#
directive|define
name|CSR_HTBA
value|0x1050
end_define

begin_comment
comment|/* host tx buffer address (ro) */
end_comment

begin_define
define|#
directive|define
name|CSR_HRBA
value|0x1054
end_define

begin_comment
comment|/* host rx buffer address (ro) */
end_comment

begin_comment
comment|/* CSR_MACCTL - Mac Control */
end_comment

begin_define
define|#
directive|define
name|MACCTL_RE
value|0x00000004
end_define

begin_comment
comment|/* rx enable */
end_comment

begin_define
define|#
directive|define
name|MACCTL_TE
value|0x00000008
end_define

begin_comment
comment|/* tx enable */
end_comment

begin_define
define|#
directive|define
name|MACCTL_DC
value|0x00000020
end_define

begin_comment
comment|/* deferral check */
end_comment

begin_define
define|#
directive|define
name|MACCTL_PSTR
value|0x00000100
end_define

begin_comment
comment|/* automatic pad strip */
end_comment

begin_define
define|#
directive|define
name|MACCTL_DTRY
value|0x00000400
end_define

begin_comment
comment|/* disable retry */
end_comment

begin_define
define|#
directive|define
name|MACCTL_DBF
value|0x00000800
end_define

begin_comment
comment|/* disable broadcast frames */
end_comment

begin_define
define|#
directive|define
name|MACCTL_LCC
value|0x00001000
end_define

begin_comment
comment|/* late collision control */
end_comment

begin_define
define|#
directive|define
name|MACCTL_HASH
value|0x00002000
end_define

begin_comment
comment|/* hash filtering enable */
end_comment

begin_define
define|#
directive|define
name|MACCTL_HO
value|0x00008000
end_define

begin_comment
comment|/* disable perfect filtering */
end_comment

begin_define
define|#
directive|define
name|MACCTL_PB
value|0x00010000
end_define

begin_comment
comment|/* pass bad frames */
end_comment

begin_define
define|#
directive|define
name|MACCTL_IF
value|0x00020000
end_define

begin_comment
comment|/* inverse filtering */
end_comment

begin_define
define|#
directive|define
name|MACCTL_PR
value|0x00040000
end_define

begin_comment
comment|/* promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|MACCTL_PM
value|0x00080000
end_define

begin_comment
comment|/* pass all multicast */
end_comment

begin_define
define|#
directive|define
name|MACCTL_FDX
value|0x00100000
end_define

begin_comment
comment|/* full duplex mode */
end_comment

begin_define
define|#
directive|define
name|MACCTL_LOOP
value|0x00600000
end_define

begin_comment
comment|/* loopback mask */
end_comment

begin_define
define|#
directive|define
name|MACCTL_LOOP_INT
value|0x00200000
end_define

begin_comment
comment|/* internal loopback */
end_comment

begin_define
define|#
directive|define
name|MACCTL_LOOP_EXT
value|0x00400000
end_define

begin_comment
comment|/* external loopback */
end_comment

begin_define
define|#
directive|define
name|MACCTL_LOOP_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MACCTL_DRO
value|0x00800000
end_define

begin_comment
comment|/* disable receive own */
end_comment

begin_define
define|#
directive|define
name|MACCTL_PS
value|0x08000000
end_define

begin_comment
comment|/* port select, 0 = mii */
end_comment

begin_define
define|#
directive|define
name|MACCTL_HBD
value|0x10000000
end_define

begin_comment
comment|/* heartbeat disable */
end_comment

begin_define
define|#
directive|define
name|MACCTL_BLE
value|0x40000000
end_define

begin_comment
comment|/* mac big endian */
end_comment

begin_define
define|#
directive|define
name|MACCTL_RA
value|0x80000000
end_define

begin_comment
comment|/* receive all packets */
end_comment

begin_comment
comment|/* CSR_MIIADDR - MII Addess */
end_comment

begin_define
define|#
directive|define
name|MIIADDR_BUSY
value|0x00000001
end_define

begin_comment
comment|/* mii busy */
end_comment

begin_define
define|#
directive|define
name|MIIADDR_WRITE
value|0x00000002
end_define

begin_comment
comment|/* mii write */
end_comment

begin_define
define|#
directive|define
name|MIIADDR_REG_MASK
value|0x000007C0
end_define

begin_comment
comment|/* mii register */
end_comment

begin_define
define|#
directive|define
name|MIIADDR_REG_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MIIADDR_PHY_MASK
value|0x0000F800
end_define

begin_comment
comment|/* mii phy */
end_comment

begin_define
define|#
directive|define
name|MIIADDR_PHY_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|MIIADDR_GETREG
parameter_list|(
name|x
parameter_list|)
value|(((x)& MIIADDR_REG)>> 6)
end_define

begin_define
define|#
directive|define
name|MIIADDR_PUTREG
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 6)& MIIADR_REG)
end_define

begin_define
define|#
directive|define
name|MIIADDR_GETPHY
parameter_list|(
name|x
parameter_list|)
value|(((x)& MIIADDR_PHY)>> 11)
end_define

begin_define
define|#
directive|define
name|MIIADDR_PUTPHY
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 6)& MIIADR_PHY)
end_define

begin_comment
comment|/* CSR_FLOWC - Flow Control */
end_comment

begin_define
define|#
directive|define
name|FLOWC_FCB
value|0x00000001
end_define

begin_comment
comment|/* flow control busy */
end_comment

begin_define
define|#
directive|define
name|FLOWC_FCE
value|0x00000002
end_define

begin_comment
comment|/* flow control enable */
end_comment

begin_define
define|#
directive|define
name|FLOWC_PCF
value|0x00000004
end_define

begin_comment
comment|/* pass control frames */
end_comment

begin_define
define|#
directive|define
name|FLOWC_PT
value|0xffff0000
end_define

begin_comment
comment|/* pause time */
end_comment

begin_comment
comment|/* CSR_BUSMODE - Bus Mode */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_SWR
value|0x00000001
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_BAR
value|0x00000002
end_define

begin_comment
comment|/* bus arbitration */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_DSL
value|0x0000007c
end_define

begin_comment
comment|/* descriptor skip length */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_BLE
value|0x00000080
end_define

begin_comment
comment|/* data buf endian */
end_comment

begin_comment
comment|/* programmable burst length */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_PBL_DEFAULT
value|0x00000000
end_define

begin_comment
comment|/*     default value */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_PBL_1LW
value|0x00000100
end_define

begin_comment
comment|/*     1 longword */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_PBL_2LW
value|0x00000200
end_define

begin_comment
comment|/*     2 longwords */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_PBL_4LW
value|0x00000400
end_define

begin_comment
comment|/*     4 longwords */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_PBL_8LW
value|0x00000800
end_define

begin_comment
comment|/*     8 longwords */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_PBL_16LW
value|0x00001000
end_define

begin_comment
comment|/*    16 longwords */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_PBL_32LW
value|0x00002000
end_define

begin_comment
comment|/*    32 longwords */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_DBO
value|0x00100000
end_define

begin_comment
comment|/* descriptor endian */
end_comment

begin_define
define|#
directive|define
name|BUSMODE_ALIGN_16B
value|0x01000000
end_define

begin_comment
comment|/* force oddhw rx buf align */
end_comment

begin_comment
comment|/* CSR_TXPOLL - Transmit Poll Demand */
end_comment

begin_define
define|#
directive|define
name|TXPOLL_TPD
value|0x00000001
end_define

begin_comment
comment|/* transmit poll demand */
end_comment

begin_comment
comment|/* CSR_RXPOLL - Receive Poll Demand */
end_comment

begin_define
define|#
directive|define
name|RXPOLL_RPD
value|0x00000001
end_define

begin_comment
comment|/* receive poll demand */
end_comment

begin_comment
comment|/* CSR_STATUS - Status */
end_comment

begin_define
define|#
directive|define
name|STATUS_TI
value|0x00000001
end_define

begin_comment
comment|/* transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|STATUS_TPS
value|0x00000002
end_define

begin_comment
comment|/* transmit process stopped */
end_comment

begin_define
define|#
directive|define
name|STATUS_TU
value|0x00000004
end_define

begin_comment
comment|/* transmit buffer unavail */
end_comment

begin_define
define|#
directive|define
name|STATUS_TJT
value|0x00000008
end_define

begin_comment
comment|/* transmit jabber timeout */
end_comment

begin_define
define|#
directive|define
name|STATUS_UNF
value|0x00000020
end_define

begin_comment
comment|/* transmit underflow */
end_comment

begin_define
define|#
directive|define
name|STATUS_RI
value|0x00000040
end_define

begin_comment
comment|/* receive interrupt */
end_comment

begin_define
define|#
directive|define
name|STATUS_RU
value|0x00000080
end_define

begin_comment
comment|/* receive buffer unavail */
end_comment

begin_define
define|#
directive|define
name|STATUS_RPS
value|0x00000100
end_define

begin_comment
comment|/* receive process stopped */
end_comment

begin_define
define|#
directive|define
name|STATUS_ETI
value|0x00000400
end_define

begin_comment
comment|/* early transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|STATUS_SE
value|0x00002000
end_define

begin_comment
comment|/* system error */
end_comment

begin_define
define|#
directive|define
name|STATUS_ER
value|0x00004000
end_define

begin_comment
comment|/* early receive (21041) */
end_comment

begin_define
define|#
directive|define
name|STATUS_AIS
value|0x00008000
end_define

begin_comment
comment|/* abnormal intr summary */
end_comment

begin_define
define|#
directive|define
name|STATUS_NIS
value|0x00010000
end_define

begin_comment
comment|/* normal interrupt summary */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS
value|0x000e0000
end_define

begin_comment
comment|/* receive process state */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* Stopped */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_FETCH
value|0x00020000
end_define

begin_comment
comment|/* Running - fetch receive 						   descriptor */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_CHECK
value|0x00040000
end_define

begin_comment
comment|/* Running - check for end 						   of receive */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_WAIT
value|0x00060000
end_define

begin_comment
comment|/* Running - wait for packet */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_SUSPENDED
value|0x00080000
end_define

begin_comment
comment|/* Suspended */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_CLOSE
value|0x000a0000
end_define

begin_comment
comment|/* Running - close receive 						   descriptor */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_FLUSH
value|0x000c0000
end_define

begin_comment
comment|/* Running - flush current 						   frame from FIFO */
end_comment

begin_define
define|#
directive|define
name|STATUS_RS_QUEUE
value|0x000e0000
end_define

begin_comment
comment|/* Running - queue current 						   frame from FIFO into 						   buffer */
end_comment

begin_define
define|#
directive|define
name|STATUS_TS
value|0x00700000
end_define

begin_comment
comment|/* transmit process state */
end_comment

begin_define
define|#
directive|define
name|STATUS_TS_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* Stopped */
end_comment

begin_define
define|#
directive|define
name|STATUS_TS_FETCH
value|0x00100000
end_define

begin_comment
comment|/* Running - fetch transmit 						   descriptor */
end_comment

begin_define
define|#
directive|define
name|STATUS_TS_WAIT
value|0x00200000
end_define

begin_comment
comment|/* Running - wait for end 						   of transmission */
end_comment

begin_define
define|#
directive|define
name|STATUS_TS_READING
value|0x00300000
end_define

begin_comment
comment|/* Running - read buffer from 						   memory and queue into 						   FIFO */
end_comment

begin_define
define|#
directive|define
name|STATUS_TS_SUSPENDED
value|0x00600000
end_define

begin_comment
comment|/* Suspended */
end_comment

begin_define
define|#
directive|define
name|STATUS_TS_CLOSE
value|0x00700000
end_define

begin_comment
comment|/* Running - close transmit 						   descriptor */
end_comment

begin_define
define|#
directive|define
name|STATUS_TX_ABORT
value|0x00800000
end_define

begin_comment
comment|/* Transmit bus abort */
end_comment

begin_define
define|#
directive|define
name|STATUS_RX_ABORT
value|0x01000000
end_define

begin_comment
comment|/* Transmit bus abort */
end_comment

begin_comment
comment|/* CSR_OPMODE - Operation Mode */
end_comment

begin_define
define|#
directive|define
name|OPMODE_SR
value|0x00000002
end_define

begin_comment
comment|/* start receive */
end_comment

begin_define
define|#
directive|define
name|OPMODE_OSF
value|0x00000004
end_define

begin_comment
comment|/* operate on second frame */
end_comment

begin_define
define|#
directive|define
name|OPMODE_ST
value|0x00002000
end_define

begin_comment
comment|/* start transmitter */
end_comment

begin_define
define|#
directive|define
name|OPMODE_TR
value|0x0000c000
end_define

begin_comment
comment|/* threshold control */
end_comment

begin_define
define|#
directive|define
name|OPMODE_TR_32
value|0x00000000
end_define

begin_comment
comment|/*     32 words */
end_comment

begin_define
define|#
directive|define
name|OPMODE_TR_64
value|0x00004000
end_define

begin_comment
comment|/*     64 words */
end_comment

begin_define
define|#
directive|define
name|OPMODE_TR_128
value|0x00008000
end_define

begin_comment
comment|/*    128 words */
end_comment

begin_define
define|#
directive|define
name|OPMODE_TR_256
value|0x0000c000
end_define

begin_comment
comment|/*    256 words */
end_comment

begin_define
define|#
directive|define
name|OPMODE_SF
value|0x00200000
end_define

begin_comment
comment|/* store and forward mode */
end_comment

begin_comment
comment|/* CSR_INTEN - Interrupt Enable */
end_comment

begin_comment
comment|/* See bits for CSR_STATUS -- Status */
end_comment

begin_comment
comment|/* CSR_MISSED - Missed Frames */
end_comment

begin_define
define|#
directive|define
name|MISSED_MFC
value|0xffff0000
end_define

begin_comment
comment|/* missed packet count */
end_comment

begin_define
define|#
directive|define
name|MISSED_FOC
value|0x0000ffff
end_define

begin_comment
comment|/* fifo overflow counter */
end_comment

begin_define
define|#
directive|define
name|MISSED_GETMFC
parameter_list|(
name|x
parameter_list|)
value|((x)& MISSED_MFC)
end_define

begin_define
define|#
directive|define
name|MISSED_GETFOC
parameter_list|(
name|x
parameter_list|)
value|(((x)& MISSED_FOC)>> 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_AREREG_H__ */
end_comment

end_unit

