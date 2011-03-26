begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_VTEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_VTEREG_H
end_define

begin_comment
comment|/*  * RDC Semiconductor PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_RDC
value|0x17F3
end_define

begin_comment
comment|/*  * Vortex86 RDC R6040 FastEthernet device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_RDC_R6040
value|0x6040
end_define

begin_comment
comment|/* PMX-1000 */
end_comment

begin_comment
comment|/* MAC control register 0 */
end_comment

begin_define
define|#
directive|define
name|VTE_MCR0
value|0x00
end_define

begin_define
define|#
directive|define
name|MCR0_ACCPT_ERR
value|0x0001
end_define

begin_define
define|#
directive|define
name|MCR0_RX_ENB
value|0x0002
end_define

begin_define
define|#
directive|define
name|MCR0_ACCPT_RUNT
value|0x0004
end_define

begin_define
define|#
directive|define
name|MCR0_ACCPT_LONG_PKT
value|0x0008
end_define

begin_define
define|#
directive|define
name|MCR0_ACCPT_DRIBBLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|MCR0_PROMISC
value|0x0020
end_define

begin_define
define|#
directive|define
name|MCR0_BROADCAST_DIS
value|0x0040
end_define

begin_define
define|#
directive|define
name|MCR0_RX_EARLY_INTR
value|0x0080
end_define

begin_define
define|#
directive|define
name|MCR0_MULTICAST
value|0x0100
end_define

begin_define
define|#
directive|define
name|MCR0_FC_ENB
value|0x0200
end_define

begin_define
define|#
directive|define
name|MCR0_TX_ENB
value|0x1000
end_define

begin_define
define|#
directive|define
name|MCR0_TX_EARLY_INTR
value|0x4000
end_define

begin_define
define|#
directive|define
name|MCR0_FULL_DUPLEX
value|0x8000
end_define

begin_comment
comment|/* MAC control register 1 */
end_comment

begin_define
define|#
directive|define
name|VTE_MCR1
value|0x04
end_define

begin_define
define|#
directive|define
name|MCR1_MAC_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|MCR1_MAC_LOOPBACK
value|0x0002
end_define

begin_define
define|#
directive|define
name|MCR1_EXCESS_COL_RETRANS_DIS
value|0x0004
end_define

begin_define
define|#
directive|define
name|MCR1_AUTO_CHG_DUPLEX
value|0x0008
end_define

begin_define
define|#
directive|define
name|MCR1_PKT_LENGTH_1518
value|0x0010
end_define

begin_define
define|#
directive|define
name|MCR1_PKT_LENGTH_1522
value|0x0020
end_define

begin_define
define|#
directive|define
name|MCR1_PKT_LENGTH_1534
value|0x0030
end_define

begin_define
define|#
directive|define
name|MCR1_PKT_LENGTH_1537
value|0x0000
end_define

begin_define
define|#
directive|define
name|MCR1_EARLY_INTR_THRESH_1129
value|0x0000
end_define

begin_define
define|#
directive|define
name|MCR1_EARLY_INTR_THRESH_1257
value|0x0040
end_define

begin_define
define|#
directive|define
name|MCR1_EARLY_INTR_THRESH_1385
value|0x0080
end_define

begin_define
define|#
directive|define
name|MCR1_EARLY_INTR_THRESH_1513
value|0x00C0
end_define

begin_define
define|#
directive|define
name|MCR1_EXCESS_COL_RETRY_16
value|0x0000
end_define

begin_define
define|#
directive|define
name|MCR1_EXCESS_COL_RETRY_32
value|0x0100
end_define

begin_define
define|#
directive|define
name|MCR1_FC_ACTIVE
value|0x0200
end_define

begin_define
define|#
directive|define
name|MCR1_RX_DESC_HASH_IDX
value|0x4000
end_define

begin_define
define|#
directive|define
name|MCR1_RX_UNICAST_HASH
value|0x8000
end_define

begin_define
define|#
directive|define
name|MCR1_PKT_LENGTH_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|MCR1_EARLY_INTR_THRESH_MASK
value|0x00C0
end_define

begin_comment
comment|/* MAC bus control register */
end_comment

begin_define
define|#
directive|define
name|VTE_MBCR
value|0x08
end_define

begin_define
define|#
directive|define
name|MBCR_FIFO_XFER_LENGTH_4
value|0x0000
end_define

begin_define
define|#
directive|define
name|MBCR_FIFO_XFER_LENGTH_8
value|0x0001
end_define

begin_define
define|#
directive|define
name|MBCR_FIFO_XFER_LENGTH_16
value|0x0002
end_define

begin_define
define|#
directive|define
name|MBCR_FIFO_XFER_LENGTH_32
value|0x0003
end_define

begin_define
define|#
directive|define
name|MBCR_TX_FIFO_THRESH_16
value|0x0000
end_define

begin_define
define|#
directive|define
name|MBCR_TX_FIFO_THRESH_32
value|0x0004
end_define

begin_define
define|#
directive|define
name|MBCR_TX_FIFO_THRESH_64
value|0x0008
end_define

begin_define
define|#
directive|define
name|MBCR_TX_FIFO_THRESH_96
value|0x000C
end_define

begin_define
define|#
directive|define
name|MBCR_RX_FIFO_THRESH_8
value|0x0000
end_define

begin_define
define|#
directive|define
name|MBCR_RX_FIFO_THRESH_16
value|0x0010
end_define

begin_define
define|#
directive|define
name|MBCR_RX_FIFO_THRESH_32
value|0x0020
end_define

begin_define
define|#
directive|define
name|MBCR_RX_FIFO_THRESH_64
value|0x0030
end_define

begin_define
define|#
directive|define
name|MBCR_SDRAM_BUS_REQ_TIMER_MASK
value|0x1F00
end_define

begin_define
define|#
directive|define
name|MBCR_SDRAM_BUS_REQ_TIMER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MBCR_SDRAM_BUS_REQ_TIMER_DEFAULT
value|0x1F00
end_define

begin_comment
comment|/* MAC TX interrupt control register */
end_comment

begin_define
define|#
directive|define
name|VTE_MTICR
value|0x0C
end_define

begin_define
define|#
directive|define
name|MTICR_TX_TIMER_MASK
value|0x001F
end_define

begin_define
define|#
directive|define
name|MTICR_TX_BUNDLE_MASK
value|0x0F00
end_define

begin_define
define|#
directive|define
name|VTE_IM_TX_TIMER_DEFAULT
value|0x7F
end_define

begin_define
define|#
directive|define
name|VTE_IM_TX_BUNDLE_DEFAULT
value|15
end_define

begin_define
define|#
directive|define
name|VTE_IM_TIMER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|VTE_IM_TIMER_MAX
value|82
end_define

begin_define
define|#
directive|define
name|VTE_IM_TIMER_MASK
value|0x001F
end_define

begin_define
define|#
directive|define
name|VTE_IM_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|VTE_IM_BUNDLE_MIN
value|1
end_define

begin_define
define|#
directive|define
name|VTE_IM_BUNDLE_MAX
value|15
end_define

begin_define
define|#
directive|define
name|VTE_IM_BUNDLE_SHIFT
value|8
end_define

begin_comment
comment|/* MAC RX interrupt control register */
end_comment

begin_define
define|#
directive|define
name|VTE_MRICR
value|0x10
end_define

begin_define
define|#
directive|define
name|MRICR_RX_TIMER_MASK
value|0x001F
end_define

begin_define
define|#
directive|define
name|MRICR_RX_BUNDLE_MASK
value|0x0F00
end_define

begin_define
define|#
directive|define
name|VTE_IM_RX_TIMER_DEFAULT
value|0x7F
end_define

begin_define
define|#
directive|define
name|VTE_IM_RX_BUNDLE_DEFAULT
value|15
end_define

begin_comment
comment|/* MAC TX poll command register */
end_comment

begin_define
define|#
directive|define
name|VTE_TX_POLL
value|0x14
end_define

begin_define
define|#
directive|define
name|TX_POLL_START
value|0x0001
end_define

begin_comment
comment|/* MAC RX buffer size register */
end_comment

begin_define
define|#
directive|define
name|VTE_MRBSR
value|0x18
end_define

begin_define
define|#
directive|define
name|VTE_MRBSR_SIZE_MASK
value|0x03FF
end_define

begin_comment
comment|/* MAC RX descriptor control register */
end_comment

begin_define
define|#
directive|define
name|VTE_MRDCR
value|0x1A
end_define

begin_define
define|#
directive|define
name|VTE_MRDCR_RESIDUE_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|VTE_MRDCR_RX_PAUSE_THRESH_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|VTE_MRDCR_RX_PAUSE_THRESH_SHIFT
value|8
end_define

begin_comment
comment|/* MAC Last status register */
end_comment

begin_define
define|#
directive|define
name|VTE_MLSR
value|0x1C
end_define

begin_define
define|#
directive|define
name|MLSR_MULTICAST
value|0x0001
end_define

begin_define
define|#
directive|define
name|MLSR_BROADCAST
value|0x0002
end_define

begin_define
define|#
directive|define
name|MLSR_CRC_ERR
value|0x0004
end_define

begin_define
define|#
directive|define
name|MLSR_RUNT
value|0x0008
end_define

begin_define
define|#
directive|define
name|MLSR_LONG_PKT
value|0x0010
end_define

begin_define
define|#
directive|define
name|MLSR_TRUNC
value|0x0020
end_define

begin_define
define|#
directive|define
name|MLSR_DRIBBLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|MLSR_PHY_ERR
value|0x0080
end_define

begin_define
define|#
directive|define
name|MLSR_TX_FIFO_UNDERRUN
value|0x0200
end_define

begin_define
define|#
directive|define
name|MLSR_RX_DESC_UNAVAIL
value|0x0400
end_define

begin_define
define|#
directive|define
name|MLSR_TX_EXCESS_COL
value|0x2000
end_define

begin_define
define|#
directive|define
name|MLSR_TX_LATE_COL
value|0x4000
end_define

begin_define
define|#
directive|define
name|MLSR_RX_FIFO_OVERRUN
value|0x8000
end_define

begin_comment
comment|/* MAC MDIO control register */
end_comment

begin_define
define|#
directive|define
name|VTE_MMDIO
value|0x20
end_define

begin_define
define|#
directive|define
name|MMDIO_REG_ADDR_MASK
value|0x001F
end_define

begin_define
define|#
directive|define
name|MMDIO_PHY_ADDR_MASK
value|0x1F00
end_define

begin_define
define|#
directive|define
name|MMDIO_READ
value|0x2000
end_define

begin_define
define|#
directive|define
name|MMDIO_WRITE
value|0x4000
end_define

begin_define
define|#
directive|define
name|MMDIO_REG_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MMDIO_PHY_ADDR_SHIFT
value|8
end_define

begin_comment
comment|/* MAC MDIO read data register */
end_comment

begin_define
define|#
directive|define
name|VTE_MMRD
value|0x24
end_define

begin_define
define|#
directive|define
name|MMRD_DATA_MASK
value|0xFFFF
end_define

begin_comment
comment|/* MAC MDIO write data register */
end_comment

begin_define
define|#
directive|define
name|VTE_MMWD
value|0x28
end_define

begin_define
define|#
directive|define
name|MMWD_DATA_MASK
value|0xFFFF
end_define

begin_comment
comment|/* MAC TX descriptor start address 0 */
end_comment

begin_define
define|#
directive|define
name|VTE_MTDSA0
value|0x2C
end_define

begin_comment
comment|/* MAC TX descriptor start address 1 */
end_comment

begin_define
define|#
directive|define
name|VTE_MTDSA1
value|0x30
end_define

begin_comment
comment|/* MAC RX descriptor start address 0 */
end_comment

begin_define
define|#
directive|define
name|VTE_MRDSA0
value|0x34
end_define

begin_comment
comment|/* MAC RX descriptor start address 1 */
end_comment

begin_define
define|#
directive|define
name|VTE_MRDSA1
value|0x38
end_define

begin_comment
comment|/* MAC Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|VTE_MISR
value|0x3C
end_define

begin_define
define|#
directive|define
name|MISR_RX_DONE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MISR_RX_DESC_UNAVAIL
value|0x0002
end_define

begin_define
define|#
directive|define
name|MISR_RX_FIFO_FULL
value|0x0004
end_define

begin_define
define|#
directive|define
name|MISR_RX_EARLY_INTR
value|0x0008
end_define

begin_define
define|#
directive|define
name|MISR_TX_DONE
value|0x0010
end_define

begin_define
define|#
directive|define
name|MISR_TX_EARLY_INTR
value|0x0080
end_define

begin_define
define|#
directive|define
name|MISR_EVENT_CNT_OFLOW
value|0x0100
end_define

begin_define
define|#
directive|define
name|MISR_PHY_MEDIA_CHG
value|0x0200
end_define

begin_comment
comment|/* MAC Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|VTE_MIER
value|0x40
end_define

begin_define
define|#
directive|define
name|VTE_INTRS
define|\
value|(MISR_RX_DONE | MISR_RX_DESC_UNAVAIL | MISR_RX_FIFO_FULL |	\ 	MISR_TX_DONE | MISR_EVENT_CNT_OFLOW)
end_define

begin_comment
comment|/* MAC Event counter interrupt status register */
end_comment

begin_define
define|#
directive|define
name|VTE_MECISR
value|0x44
end_define

begin_define
define|#
directive|define
name|MECISR_EC_RX_DONE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MECISR_EC_MULTICAST
value|0x0002
end_define

begin_define
define|#
directive|define
name|MECISR_EC_BROADCAST
value|0x0004
end_define

begin_define
define|#
directive|define
name|MECISR_EC_CRC_ERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|MECISR_EC_RUNT
value|0x0010
end_define

begin_define
define|#
directive|define
name|MESCIR_EC_LONG_PKT
value|0x0020
end_define

begin_define
define|#
directive|define
name|MESCIR_EC_RX_DESC_UNAVAIL
value|0x0080
end_define

begin_define
define|#
directive|define
name|MESCIR_EC_RX_FIFO_FULL
value|0x0100
end_define

begin_define
define|#
directive|define
name|MESCIR_EC_TX_DONE
value|0x0200
end_define

begin_define
define|#
directive|define
name|MESCIR_EC_LATE_COL
value|0x0400
end_define

begin_define
define|#
directive|define
name|MESCIR_EC_TX_UNDERRUN
value|0x0800
end_define

begin_comment
comment|/* MAC Event counter interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|VTE_MECIER
value|0x48
end_define

begin_define
define|#
directive|define
name|VTE_MECIER_INTRS
define|\
value|(MECISR_EC_RX_DONE | MECISR_EC_MULTICAST | MECISR_EC_BROADCAST | \ 	MECISR_EC_CRC_ERR | MECISR_EC_RUNT | MESCIR_EC_LONG_PKT |	 \ 	MESCIR_EC_RX_DESC_UNAVAIL | MESCIR_EC_RX_FIFO_FULL |		 \ 	MESCIR_EC_TX_DONE | MESCIR_EC_LATE_COL | MESCIR_EC_TX_UNDERRUN)
end_define

begin_define
define|#
directive|define
name|VTE_CNT_RX_DONE
value|0x50
end_define

begin_define
define|#
directive|define
name|VTE_CNT_MECNT0
value|0x52
end_define

begin_define
define|#
directive|define
name|VTE_CNT_MECNT1
value|0x54
end_define

begin_define
define|#
directive|define
name|VTE_CNT_MECNT2
value|0x56
end_define

begin_define
define|#
directive|define
name|VTE_CNT_MECNT3
value|0x58
end_define

begin_define
define|#
directive|define
name|VTE_CNT_TX_DONE
value|0x5A
end_define

begin_define
define|#
directive|define
name|VTE_CNT_MECNT4
value|0x5C
end_define

begin_define
define|#
directive|define
name|VTE_CNT_PAUSE
value|0x5E
end_define

begin_comment
comment|/* MAC Hash table register */
end_comment

begin_define
define|#
directive|define
name|VTE_MAR0
value|0x60
end_define

begin_define
define|#
directive|define
name|VTE_MAR1
value|0x62
end_define

begin_define
define|#
directive|define
name|VTE_MAR2
value|0x64
end_define

begin_define
define|#
directive|define
name|VTE_MAR3
value|0x66
end_define

begin_comment
comment|/* MAC station address and multicast address register */
end_comment

begin_define
define|#
directive|define
name|VTE_MID0L
value|0x68
end_define

begin_define
define|#
directive|define
name|VTE_MID0M
value|0x6A
end_define

begin_define
define|#
directive|define
name|VTE_MID0H
value|0x6C
end_define

begin_define
define|#
directive|define
name|VTE_MID1L
value|0x70
end_define

begin_define
define|#
directive|define
name|VTE_MID1M
value|0x72
end_define

begin_define
define|#
directive|define
name|VTE_MID1H
value|0x74
end_define

begin_define
define|#
directive|define
name|VTE_MID2L
value|0x78
end_define

begin_define
define|#
directive|define
name|VTE_MID2M
value|0x7A
end_define

begin_define
define|#
directive|define
name|VTE_MID2H
value|0x7C
end_define

begin_define
define|#
directive|define
name|VTE_MID3L
value|0x80
end_define

begin_define
define|#
directive|define
name|VTE_MID3M
value|0x82
end_define

begin_define
define|#
directive|define
name|VTE_MID3H
value|0x84
end_define

begin_define
define|#
directive|define
name|VTE_RXFILTER_PEEFECT_BASE
value|VTE_MID1L
end_define

begin_define
define|#
directive|define
name|VTE_RXFILT_PERFECT_CNT
value|3
end_define

begin_comment
comment|/* MAC PHY status change configuration register */
end_comment

begin_define
define|#
directive|define
name|VTE_MPSCCR
value|0x88
end_define

begin_define
define|#
directive|define
name|MPSCCR_TIMER_DIVIDER_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|MPSCCR_PHY_ADDR_MASK
value|0x1F00
end_define

begin_define
define|#
directive|define
name|MPSCCR_PHY_STS_CHG_ENB
value|0x8000
end_define

begin_define
define|#
directive|define
name|MPSCCR_PHY_ADDR_SHIFT
value|8
end_define

begin_comment
comment|/* MAC PHY status register2 */
end_comment

begin_define
define|#
directive|define
name|VTE_MPSR
value|0x8A
end_define

begin_define
define|#
directive|define
name|MPSR_LINK_UP
value|0x0001
end_define

begin_define
define|#
directive|define
name|MPSR_SPEED_100
value|0x0002
end_define

begin_define
define|#
directive|define
name|MPSR_FULL_DUPLEX
value|0x0004
end_define

begin_comment
comment|/* MAC Status machine(undocumented). */
end_comment

begin_define
define|#
directive|define
name|VTE_MACSM
value|0xAC
end_define

begin_comment
comment|/* MDC Speed control register */
end_comment

begin_define
define|#
directive|define
name|VTE_MDCSC
value|0xB6
end_define

begin_define
define|#
directive|define
name|MDCSC_DEFAULT
value|0x0030
end_define

begin_comment
comment|/* MAC Identifier and revision register */
end_comment

begin_define
define|#
directive|define
name|VTE_MACID_REV
value|0xBC
end_define

begin_define
define|#
directive|define
name|VTE_MACID_REV_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|VTE_MACID_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|VTE_MACID_REV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|VTE_MACID_SHIFT
value|8
end_define

begin_comment
comment|/* MAC Identifier register */
end_comment

begin_define
define|#
directive|define
name|VTE_MACID
value|0xBE
end_define

begin_comment
comment|/*  * RX descriptor  * - Added one more uint16_t member to align it 4 on bytes boundary.  *   This does not affect operation of controller since it includes  *   next pointer address.  */
end_comment

begin_struct
struct|struct
name|vte_rx_desc
block|{
name|uint16_t
name|drst
decl_stmt|;
name|uint16_t
name|drlen
decl_stmt|;
name|uint32_t
name|drbp
decl_stmt|;
name|uint32_t
name|drnp
decl_stmt|;
name|uint16_t
name|hidx
decl_stmt|;
name|uint16_t
name|rsvd2
decl_stmt|;
name|uint16_t
name|rsvd3
decl_stmt|;
name|uint16_t
name|__pad
decl_stmt|;
comment|/* Not actual descriptor member. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTE_DRST_MID_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|VTE_DRST_MID_HIT
value|0x0004
end_define

begin_define
define|#
directive|define
name|VTE_DRST_MULTICAST_HIT
value|0x0008
end_define

begin_define
define|#
directive|define
name|VTE_DRST_MULTICAST
value|0x0010
end_define

begin_define
define|#
directive|define
name|VTE_DRST_BROADCAST
value|0x0020
end_define

begin_define
define|#
directive|define
name|VTE_DRST_CRC_ERR
value|0x0040
end_define

begin_define
define|#
directive|define
name|VTE_DRST_RUNT
value|0x0080
end_define

begin_define
define|#
directive|define
name|VTE_DRST_LONG
value|0x0100
end_define

begin_define
define|#
directive|define
name|VTE_DRST_TRUNC
value|0x0200
end_define

begin_define
define|#
directive|define
name|VTE_DRST_DRIBBLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|VTE_DRST_PHY_ERR
value|0x0800
end_define

begin_define
define|#
directive|define
name|VTE_DRST_RX_OK
value|0x4000
end_define

begin_define
define|#
directive|define
name|VTE_DRST_RX_OWN
value|0x8000
end_define

begin_define
define|#
directive|define
name|VTE_RX_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|VTE_RX_HIDX
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3F)
end_define

begin_comment
comment|/*  * TX descriptor  * - Added one more uint32_t member to align it on 16 bytes boundary.  */
end_comment

begin_struct
struct|struct
name|vte_tx_desc
block|{
name|uint16_t
name|dtst
decl_stmt|;
name|uint16_t
name|dtlen
decl_stmt|;
name|uint32_t
name|dtbp
decl_stmt|;
name|uint32_t
name|dtnp
decl_stmt|;
name|uint32_t
name|__pad
decl_stmt|;
comment|/* Not actual descriptor member. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTE_DTST_EXCESS_COL
value|0x0010
end_define

begin_define
define|#
directive|define
name|VTE_DTST_LATE_COL
value|0x0020
end_define

begin_define
define|#
directive|define
name|VTE_DTST_UNDERRUN
value|0x0040
end_define

begin_define
define|#
directive|define
name|VTE_DTST_NO_CRC
value|0x2000
end_define

begin_define
define|#
directive|define
name|VTE_DTST_TX_OK
value|0x4000
end_define

begin_define
define|#
directive|define
name|VTE_DTST_TX_OWN
value|0x8000
end_define

begin_define
define|#
directive|define
name|VTE_TX_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7FF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_VTEREG_H */
end_comment

end_unit

