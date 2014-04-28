begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, 2009, 2010 Nikolay Denev<ndenev@gmail.com>  * Copyright (c) 2007, 2008 Alexander Pohoyda<alexander.pohoyda@gmx.net>  * Copyright (c) 1997, 1998, 1999  *      Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL AUTHORS OR  * THE VOICES IN THEIR HEADS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SGEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_SGEREG_H
end_define

begin_comment
comment|/*  * SiS PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|SIS_VENDORID
value|0x1039
end_define

begin_comment
comment|/*  * SiS PCI device IDs  */
end_comment

begin_define
define|#
directive|define
name|SIS_DEVICEID_190
value|0x0190
end_define

begin_define
define|#
directive|define
name|SIS_DEVICEID_191
value|0x0191
end_define

begin_define
define|#
directive|define
name|TX_CTL
value|0x00
end_define

begin_define
define|#
directive|define
name|TX_DESC
value|0x04
end_define

begin_define
define|#
directive|define
name|Reserved0
value|0x08
end_define

begin_define
define|#
directive|define
name|TX_NEXT
value|0x0c
end_define

begin_define
define|#
directive|define
name|RX_CTL
value|0x10
end_define

begin_define
define|#
directive|define
name|RX_DESC
value|0x14
end_define

begin_define
define|#
directive|define
name|Reserved1
value|0x18
end_define

begin_define
define|#
directive|define
name|RX_NEXT
value|0x1c
end_define

begin_define
define|#
directive|define
name|IntrStatus
value|0x20
end_define

begin_define
define|#
directive|define
name|IntrMask
value|0x24
end_define

begin_define
define|#
directive|define
name|IntrControl
value|0x28
end_define

begin_define
define|#
directive|define
name|IntrTimer
value|0x2c
end_define

begin_define
define|#
directive|define
name|PMControl
value|0x30
end_define

begin_define
define|#
directive|define
name|Reserved2
value|0x34
end_define

begin_define
define|#
directive|define
name|ROMControl
value|0x38
end_define

begin_define
define|#
directive|define
name|ROMInterface
value|0x3c
end_define

begin_define
define|#
directive|define
name|StationControl
value|0x40
end_define

begin_define
define|#
directive|define
name|GMIIControl
value|0x44
end_define

begin_define
define|#
directive|define
name|GMacIOCR
value|0x48
end_define

begin_define
define|#
directive|define
name|GMacIOCTL
value|0x4c
end_define

begin_define
define|#
directive|define
name|TxMacControl
value|0x50
end_define

begin_define
define|#
directive|define
name|TxMacTimeLimit
value|0x54
end_define

begin_define
define|#
directive|define
name|RGMIIDelay
value|0x58
end_define

begin_define
define|#
directive|define
name|Reserved3
value|0x5c
end_define

begin_define
define|#
directive|define
name|RxMacControl
value|0x60
end_define

begin_comment
comment|/* 1  WORD */
end_comment

begin_define
define|#
directive|define
name|RxMacAddr
value|0x62
end_define

begin_comment
comment|/* 6x BYTE */
end_comment

begin_define
define|#
directive|define
name|RxHashTable
value|0x68
end_define

begin_comment
comment|/* 1 LONG */
end_comment

begin_define
define|#
directive|define
name|RxHashTable2
value|0x6c
end_define

begin_comment
comment|/* 1 LONG */
end_comment

begin_define
define|#
directive|define
name|RxWakeOnLan
value|0x70
end_define

begin_define
define|#
directive|define
name|RxWakeOnLanData
value|0x74
end_define

begin_define
define|#
directive|define
name|RxMPSControl
value|0x78
end_define

begin_define
define|#
directive|define
name|Reserved4
value|0x7c
end_define

begin_comment
comment|/*  * IntrStatus Register Content  */
end_comment

begin_define
define|#
directive|define
name|INTR_SOFT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|INTR_TIMER
value|0x20000000
end_define

begin_define
define|#
directive|define
name|INTR_PAUSE_FRAME
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTR_MAGIC_FRAME
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INTR_WAKE_FRAME
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INTR_LINK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTR_RX_IDLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_RX_DONE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_TXQ1_IDLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTR_TXQ1_DONE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|INTR_TX_IDLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INTR_TX_DONE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|INTR_RX_HALT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INTR_TX_HALT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SGE_INTRS
define|\
value|(INTR_RX_IDLE | INTR_RX_DONE | INTR_TXQ1_IDLE |			\ 	 INTR_TXQ1_DONE |INTR_TX_IDLE | INTR_TX_DONE |			\ 	 INTR_TX_HALT | INTR_RX_HALT)
end_define

begin_comment
comment|/*  * RxStatusDesc Register Content  */
end_comment

begin_define
define|#
directive|define
name|RxRES
value|0x00200000
end_define

begin_define
define|#
directive|define
name|RxCRC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RxRUNT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|RxRWT
value|0x00400000
end_define

begin_comment
comment|/*  * RX_CTL Register Content  */
end_comment

begin_define
define|#
directive|define
name|RX_CTL_POLL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RX_CTL_ENB
value|0x00000001
end_define

begin_comment
comment|/*  * TX_CTL Register Content  */
end_comment

begin_define
define|#
directive|define
name|TX_CTL_POLL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TX_CTL_ENB
value|0x00000001
end_define

begin_comment
comment|/*  * RxMacControl Register Content  */
end_comment

begin_define
define|#
directive|define
name|AcceptBroadcast
value|0x0800
end_define

begin_define
define|#
directive|define
name|AcceptMulticast
value|0x0400
end_define

begin_define
define|#
directive|define
name|AcceptMyPhys
value|0x0200
end_define

begin_define
define|#
directive|define
name|AcceptAllPhys
value|0x0100
end_define

begin_define
define|#
directive|define
name|AcceptErr
value|0x0020
end_define

begin_define
define|#
directive|define
name|AcceptRunt
value|0x0010
end_define

begin_define
define|#
directive|define
name|RXMAC_STRIP_VLAN
value|0x0020
end_define

begin_define
define|#
directive|define
name|RXMAC_STRIP_FCS
value|0x0010
end_define

begin_define
define|#
directive|define
name|RXMAC_PAD_ENB
value|0x0004
end_define

begin_define
define|#
directive|define
name|RXMAC_CSUM_ENB
value|0x0002
end_define

begin_define
define|#
directive|define
name|SGE_RX_PAD_BYTES
value|10
end_define

begin_comment
comment|/* Station control register. */
end_comment

begin_define
define|#
directive|define
name|SC_LOOPBACK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SC_RGMII
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SC_FDX
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SC_SPEED_MASK
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|SC_SPEED_10
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SC_SPEED_100
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SC_SPEED_1000
value|0x00000c00
end_define

begin_comment
comment|/*  * Gigabit Media Independent Interface CTL register  */
end_comment

begin_define
define|#
directive|define
name|GMI_DATA
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|GMI_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GMI_REG
value|0x0000f800
end_define

begin_define
define|#
directive|define
name|GMI_REG_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|GMI_PHY
value|0x000007c0
end_define

begin_define
define|#
directive|define
name|GMI_PHY_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|GMI_OP_WR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GMI_OP_RD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GMI_REQ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GMI_MDIO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GMI_MDDIR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GMI_MDC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GMI_MDEN
value|0x00000001
end_define

begin_comment
comment|/* Tx descriptor command bits. */
end_comment

begin_define
define|#
directive|define
name|TDC_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TDC_INTR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TDC_THOL3
value|0x30000000
end_define

begin_define
define|#
directive|define
name|TDC_THOL2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TDC_THOL1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TDC_THOL0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TDC_LS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TDC_IP_CSUM
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TDC_TCP_CSUM
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TDC_UDP_CSUM
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TDC_BST
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TDC_EXT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TDC_DEF
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TDC_BKF
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TDC_CRS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TDC_COL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TDC_CRC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TDC_PAD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TDC_VLAN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|SGE_TX_INTR_FRAMES
value|32
end_define

begin_comment
comment|/*  * TX descriptor status bits.  */
end_comment

begin_define
define|#
directive|define
name|TDS_INS_VLAN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TDS_OWC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TDS_ABT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TDS_FIFO
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TDS_CRS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TDS_COLLS
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SGE_TX_ERROR
parameter_list|(
name|x
parameter_list|)
value|((x)& (TDS_OWC | TDS_ABT | TDS_FIFO | TDS_CRS))
end_define

begin_define
define|#
directive|define
name|TX_ERR_BITS
value|"\20"				\ 				"\21CRS\22FIFO\23ABT\24OWC"
end_define

begin_comment
comment|/* Rx descriptor command bits. */
end_comment

begin_define
define|#
directive|define
name|RDC_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RDC_INTR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RDC_IP_CSUM
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RDC_TCP_CSUM
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RDC_UDP_CSUM
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RDC_IP_CSUM_OK
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RDC_TCP_CSUM_OK
value|0x02000000
end_define

begin_define
define|#
directive|define
name|RDC_UDP_CSUM_OK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|RDC_WAKEUP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|RDC_MAGIC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|RDC_PAUSE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|RDC_BCAST
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|RDC_MCAST
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RDC_UCAST
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RDC_CRCOFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RDC_PREADD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RDC_VLAN_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/*  * RX descriptor status bits  */
end_comment

begin_define
define|#
directive|define
name|RDS_VLAN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RDS_DESCS
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|RDS_ABORT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|RDS_SHORT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|RDS_LIMIT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|RDS_MIIER
value|0x00100000
end_define

begin_define
define|#
directive|define
name|RDS_OVRUN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RDS_NIBON
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RDS_COLON
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RDS_CRCOK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SGE_RX_ERROR
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& (RDS_COLON | RDS_NIBON | RDS_OVRUN | RDS_MIIER |		\ 	RDS_LIMIT | RDS_SHORT | RDS_ABORT))
end_define

begin_define
define|#
directive|define
name|SGE_RX_NSEGS
parameter_list|(
name|x
parameter_list|)
value|(((x)& RDS_DESCS)>> 24)
end_define

begin_define
define|#
directive|define
name|RX_ERR_BITS
value|"\20"					\ 				"\21CRCOK\22COLON\23NIBON\24OVRUN"	\ 				"\25MIIER\26LIMIT\27SHORT\30ABORT"	\ 				"\40VLAN"
end_define

begin_define
define|#
directive|define
name|RING_END
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SGE_RX_BYTES
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|SGE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (((x) + 1) % y)
end_define

begin_comment
comment|/* Taken from Solaris driver */
end_comment

begin_define
define|#
directive|define
name|EI_DATA
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|EI_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EI_OFFSET
value|0x0000fc00
end_define

begin_define
define|#
directive|define
name|EI_OFFSET_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|EI_OP
value|0x00000300
end_define

begin_define
define|#
directive|define
name|EI_OP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|EI_OP_RD
value|(2<< EI_OP_SHIFT)
end_define

begin_define
define|#
directive|define
name|EI_OP_WR
value|(1<< EI_OP_SHIFT)
end_define

begin_define
define|#
directive|define
name|EI_REQ
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EI_DO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EI_DI
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EI_CLK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EI_CS
value|0x00000001
end_define

begin_comment
comment|/*  * EEPROM Addresses  */
end_comment

begin_define
define|#
directive|define
name|EEPROMSignature
value|0x00
end_define

begin_define
define|#
directive|define
name|EEPROMCLK
value|0x01
end_define

begin_define
define|#
directive|define
name|EEPROMInfo
value|0x02
end_define

begin_define
define|#
directive|define
name|EEPROMMACAddr
value|0x03
end_define

begin_struct
struct|struct
name|sge_desc
block|{
name|uint32_t
name|sge_sts_size
decl_stmt|;
name|uint32_t
name|sge_cmdsts
decl_stmt|;
name|uint32_t
name|sge_ptr
decl_stmt|;
name|uint32_t
name|sge_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SGE_RX_RING_CNT
value|256
end_define

begin_comment
comment|/* [8, 1024] */
end_comment

begin_define
define|#
directive|define
name|SGE_TX_RING_CNT
value|256
end_define

begin_comment
comment|/* [8, 8192] */
end_comment

begin_define
define|#
directive|define
name|SGE_DESC_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|SGE_MAXTXSEGS
value|35
end_define

begin_define
define|#
directive|define
name|SGE_TSO_MAXSIZE
value|(65535 + sizeof(struct ether_vlan_header))
end_define

begin_define
define|#
directive|define
name|SGE_TSO_MAXSEGSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|SGE_RX_BUF_ALIGN
value|sizeof(uint64_t)
end_define

begin_define
define|#
directive|define
name|SGE_RX_RING_SZ
value|(SGE_RX_RING_CNT * sizeof(struct sge_desc))
end_define

begin_define
define|#
directive|define
name|SGE_TX_RING_SZ
value|(SGE_TX_RING_CNT * sizeof(struct sge_desc))
end_define

begin_define
define|#
directive|define
name|SGE_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)& 0xFFFFFFFF)
end_define

begin_struct
struct|struct
name|sge_list_data
block|{
name|struct
name|sge_desc
modifier|*
name|sge_rx_ring
decl_stmt|;
name|struct
name|sge_desc
modifier|*
name|sge_tx_ring
decl_stmt|;
comment|/* physical bus addresses of sge_rx_ring/sge_tx_ring */
name|bus_addr_t
name|sge_rx_paddr
decl_stmt|;
name|bus_addr_t
name|sge_tx_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sge_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
name|int
name|tx_ndesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sge_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sge_chain_data
block|{
name|bus_dma_tag_t
name|sge_tag
decl_stmt|;
name|bus_dma_tag_t
name|sge_rx_tag
decl_stmt|;
name|bus_dma_tag_t
name|sge_tx_tag
decl_stmt|;
name|bus_dmamap_t
name|sge_rx_dmamap
decl_stmt|;
name|bus_dmamap_t
name|sge_tx_dmamap
decl_stmt|;
name|bus_dma_tag_t
name|sge_txmbuf_tag
decl_stmt|;
name|bus_dma_tag_t
name|sge_rxmbuf_tag
decl_stmt|;
name|struct
name|sge_txdesc
name|sge_txdesc
index|[
name|SGE_TX_RING_CNT
index|]
decl_stmt|;
name|struct
name|sge_rxdesc
name|sge_rxdesc
index|[
name|SGE_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dmamap_t
name|sge_rx_spare_map
decl_stmt|;
name|int
name|sge_rx_cons
decl_stmt|;
name|int
name|sge_tx_prod
decl_stmt|;
name|int
name|sge_tx_cons
decl_stmt|;
name|int
name|sge_tx_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sge_type
block|{
name|uint16_t
name|sge_vid
decl_stmt|;
name|uint16_t
name|sge_did
decl_stmt|;
name|char
modifier|*
name|sge_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sge_softc
block|{
name|struct
name|ifnet
modifier|*
name|sge_ifp
decl_stmt|;
comment|/* interface info */
name|struct
name|resource
modifier|*
name|sge_res
decl_stmt|;
name|int
name|sge_res_id
decl_stmt|;
name|int
name|sge_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|sge_irq
decl_stmt|;
name|void
modifier|*
name|sge_intrhand
decl_stmt|;
name|device_t
name|sge_dev
decl_stmt|;
name|device_t
name|sge_miibus
decl_stmt|;
name|uint8_t
name|sge_rev
decl_stmt|;
name|struct
name|sge_list_data
name|sge_ldata
decl_stmt|;
name|struct
name|sge_chain_data
name|sge_cdata
decl_stmt|;
name|struct
name|callout
name|sge_stat_ch
decl_stmt|;
name|int
name|sge_timer
decl_stmt|;
name|int
name|sge_flags
decl_stmt|;
define|#
directive|define
name|SGE_FLAG_FASTETHER
value|0x0001
define|#
directive|define
name|SGE_FLAG_SIS190
value|0x0002
define|#
directive|define
name|SGE_FLAG_RGMII
value|0x0010
define|#
directive|define
name|SGE_FLAG_SPEED_1000
value|0x2000
define|#
directive|define
name|SGE_FLAG_FDX
value|0x4000
define|#
directive|define
name|SGE_FLAG_LINK
value|0x8000
name|int
name|sge_if_flags
decl_stmt|;
name|int
name|sge_intrcontrol
decl_stmt|;
name|int
name|sge_intrtimer
decl_stmt|;
name|struct
name|mtx
name|sge_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sge_mtx)
end_define

begin_define
define|#
directive|define
name|SGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sge_mtx)
end_define

begin_define
define|#
directive|define
name|SGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sge_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SGE_TIMEOUT
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_SGEREG_H */
end_comment

end_unit

