begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Sundance PCI device/vendor ID for the  * ST201 chip.  */
end_comment

begin_define
define|#
directive|define
name|ST_VENDORID
value|0x13F0
end_define

begin_define
define|#
directive|define
name|ST_DEVICEID_ST201_1
value|0x0200
end_define

begin_define
define|#
directive|define
name|ST_DEVICEID_ST201_2
value|0x0201
end_define

begin_comment
comment|/*  * D-Link PCI device/vendor ID for the DL10050[AB] chip  */
end_comment

begin_define
define|#
directive|define
name|DL_VENDORID
value|0x1186
end_define

begin_define
define|#
directive|define
name|DL_DEVICEID_DL10050
value|0x1002
end_define

begin_comment
comment|/*  * Register definitions for the Sundance Technologies ST201 PCI  * fast ethernet controller. The register space is 128 bytes long and  * can be accessed using either PCI I/O space or PCI memory mapping.  * There are 32-bit, 16-bit and 8-bit registers.  */
end_comment

begin_define
define|#
directive|define
name|STE_DMACTL
value|0x00
end_define

begin_define
define|#
directive|define
name|STE_TX_DMALIST_PTR
value|0x04
end_define

begin_define
define|#
directive|define
name|STE_TX_DMABURST_THRESH
value|0x08
end_define

begin_define
define|#
directive|define
name|STE_TX_DMAURG_THRESH
value|0x09
end_define

begin_define
define|#
directive|define
name|STE_TX_DMAPOLL_PERIOD
value|0x0A
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS
value|0x0C
end_define

begin_define
define|#
directive|define
name|STE_RX_DMALIST_PTR
value|0x10
end_define

begin_define
define|#
directive|define
name|STE_RX_DMABURST_THRESH
value|0x14
end_define

begin_define
define|#
directive|define
name|STE_RX_DMAURG_THRESH
value|0x15
end_define

begin_define
define|#
directive|define
name|STE_RX_DMAPOLL_PERIOD
value|0x16
end_define

begin_define
define|#
directive|define
name|STE_DEBUGCTL
value|0x1A
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL
value|0x30
end_define

begin_define
define|#
directive|define
name|STE_EEPROM_DATA
value|0x34
end_define

begin_define
define|#
directive|define
name|STE_EEPROM_CTL
value|0x36
end_define

begin_define
define|#
directive|define
name|STE_FIFOCTL
value|0x3A
end_define

begin_define
define|#
directive|define
name|STE_TX_STARTTHRESH
value|0x3C
end_define

begin_define
define|#
directive|define
name|STE_RX_EARLYTHRESH
value|0x3E
end_define

begin_define
define|#
directive|define
name|STE_EXT_ROMADDR
value|0x40
end_define

begin_define
define|#
directive|define
name|STE_EXT_ROMDATA
value|0x44
end_define

begin_define
define|#
directive|define
name|STE_WAKE_EVENT
value|0x45
end_define

begin_define
define|#
directive|define
name|STE_TX_STATUS
value|0x46
end_define

begin_define
define|#
directive|define
name|STE_TX_FRAMEID
value|0x47
end_define

begin_define
define|#
directive|define
name|STE_COUNTDOWN
value|0x48
end_define

begin_define
define|#
directive|define
name|STE_ISR_ACK
value|0x4A
end_define

begin_define
define|#
directive|define
name|STE_IMR
value|0x4C
end_define

begin_define
define|#
directive|define
name|STE_ISR
value|0x4E
end_define

begin_define
define|#
directive|define
name|STE_MACCTL0
value|0x50
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1
value|0x52
end_define

begin_define
define|#
directive|define
name|STE_PAR0
value|0x54
end_define

begin_define
define|#
directive|define
name|STE_PAR1
value|0x56
end_define

begin_define
define|#
directive|define
name|STE_PAR2
value|0x58
end_define

begin_define
define|#
directive|define
name|STE_MAX_FRAMELEN
value|0x5A
end_define

begin_define
define|#
directive|define
name|STE_RX_MODE
value|0x5C
end_define

begin_define
define|#
directive|define
name|STE_TX_RECLAIM_THRESH
value|0x5D
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL
value|0x5E
end_define

begin_define
define|#
directive|define
name|STE_MAR0
value|0x60
end_define

begin_define
define|#
directive|define
name|STE_MAR1
value|0x62
end_define

begin_define
define|#
directive|define
name|STE_MAR2
value|0x64
end_define

begin_define
define|#
directive|define
name|STE_MAR3
value|0x66
end_define

begin_define
define|#
directive|define
name|STE_STATS
value|0x68
end_define

begin_define
define|#
directive|define
name|STE_LATE_COLLS
value|0x75
end_define

begin_define
define|#
directive|define
name|STE_MULTI_COLLS
value|0x76
end_define

begin_define
define|#
directive|define
name|STE_SINGLE_COLLS
value|0x77
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_RXDMA_STOPPED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_TXDMA_CMPREQ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_TXDMA_STOPPED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_RXDMA_COMPLETE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_TXDMA_COMPLETE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_RXDMA_STALL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_RXDMA_UNSTALL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_TXDMA_STALL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_TXDMA_UNSTALL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_TXDMA_INPROG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_DMA_HALTINPROG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_RXEARLY_ENABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_COUNTDOWN_SPEED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_COUNTDOWN_MODE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_MWI_DISABLE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_RX_DISCARD_OFLOWS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_COUNTDOWN_ENABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_TARGET_ABORT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|STE_DMACTL_MASTER_ABORT
value|0x80000000
end_define

begin_comment
comment|/*  * TX DMA burst thresh is the number of 32-byte blocks that  * must be loaded into the TX Fifo before a TXDMA burst request  * will be issued.  */
end_comment

begin_define
define|#
directive|define
name|STE_TXDMABURST_THRESH
value|0x1F
end_define

begin_comment
comment|/*  * The number of 32-byte blocks in the TX FIFO falls below the  * TX DMA urgent threshold, a TX DMA urgent request will be  * generated.  */
end_comment

begin_define
define|#
directive|define
name|STE_TXDMAURG_THRESH
value|0x3F
end_define

begin_comment
comment|/*  * Number of 320ns intervals between polls of the TXDMA next  * descriptor pointer (if we're using polling mode).  */
end_comment

begin_define
define|#
directive|define
name|STE_TXDMA_POLL_PERIOD
value|0x7F
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_FRAMELEN
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_RXERR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_DMADONE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_FIFO_OFLOW
value|0x00010000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_RUNT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_ALIGNERR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_CRCERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_GIANT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_DRIBBLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|STE_RX_DMASTATUS_DMA_OFLOW
value|0x01000000
end_define

begin_comment
comment|/*  * RX DMA burst thresh is the number of 32-byte blocks that  * must be present in the RX FIFO before a RXDMA bus master  * request will be issued.  */
end_comment

begin_define
define|#
directive|define
name|STE_RXDMABURST_THRESH
value|0xFF
end_define

begin_comment
comment|/*  * The number of 32-byte blocks in the RX FIFO falls below the  * RX DMA urgent threshold, a RX DMA urgent request will be  * generated.  */
end_comment

begin_define
define|#
directive|define
name|STE_RXDMAURG_THRESH
value|0x1F
end_define

begin_comment
comment|/*  * Number of 320ns intervals between polls of the RXDMA complete  * bit in the status field on the current RX descriptor (if we're  * using polling mode).  */
end_comment

begin_define
define|#
directive|define
name|STE_RXDMA_POLL_PERIOD
value|0x7F
end_define

begin_define
define|#
directive|define
name|STE_DEBUGCTL_GPIO0_CTL
value|0x0001
end_define

begin_define
define|#
directive|define
name|STE_DEBUGCTL_GPIO1_CTL
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_DEBUGCTL_GPIO0_DATA
value|0x0004
end_define

begin_define
define|#
directive|define
name|STE_DEBUGCTL_GPIO1_DATA
value|0x0008
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_ROMSIZE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_TX_LARGEPKTS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_RX_LARGEPKTS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_EXTROM_DISABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_PHYSPEED_10
value|0x00000020
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_PHYSPEED_100
value|0x00000040
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_PHYMEDIA
value|0x00000080
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_FORCEDCONFIG
value|0x00000700
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_D3RESET_DISABLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_SPEEDUPMODE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_LEDMODE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_RSTOUT_POLARITY
value|0x00008000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_GLOBAL_RESET
value|0x00010000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_RX_RESET
value|0x00020000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_TX_RESET
value|0x00040000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_DMA_RESET
value|0x00080000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_FIFO_RESET
value|0x00100000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_NETWORK_RESET
value|0x00200000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_HOST_RESET
value|0x00400000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_AUTOINIT_RESET
value|0x00800000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_EXTRESET_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_SOFTINTR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL_RESET_BUSY
value|0x04000000
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_GLOBAL_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_RX_RESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_TX_RESET
value|0x0004
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_DMA_RESET
value|0x0008
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_FIFO_RESET
value|0x0010
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_NETWORK_RESET
value|0x0020
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_HOST_RESET
value|0x0040
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_AUTOINIT_RESET
value|0x0080
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_EXTRESET_RESET
value|0x0100
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_SOFTINTR
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_ASICCTL1_RESET_BUSY
value|0x0400
end_define

begin_define
define|#
directive|define
name|STE_EECTL_ADDR
value|0x00FF
end_define

begin_define
define|#
directive|define
name|STE_EECTL_OPCODE
value|0x0300
end_define

begin_define
define|#
directive|define
name|STE_EECTL_BUSY
value|0x1000
end_define

begin_define
define|#
directive|define
name|STE_EEOPCODE_WRITE
value|0x0100
end_define

begin_define
define|#
directive|define
name|STE_EEOPCODE_READ
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_EEOPCODE_ERASE
value|0x0300
end_define

begin_define
define|#
directive|define
name|STE_FIFOCTL_RAMTESTMODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|STE_FIFOCTL_OVERRUNMODE
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_FIFOCTL_RXFIFOFULL
value|0x0800
end_define

begin_define
define|#
directive|define
name|STE_FIFOCTL_TX_BUSY
value|0x4000
end_define

begin_define
define|#
directive|define
name|STE_FIFOCTL_RX_BUSY
value|0x8000
end_define

begin_comment
comment|/*  * The number of bytes that must in present in the TX FIFO before  * transmission begins. Value should be in increments of 4 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STE_TXSTART_THRESH
value|0x1FFC
end_define

begin_comment
comment|/*  * Number of bytes that must be present in the RX FIFO before  * an RX EARLY interrupt is generated.  */
end_comment

begin_define
define|#
directive|define
name|STE_RXEARLY_THRESH
value|0x1FFC
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_WAKEPKT_ENB
value|0x01
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_MAGICPKT_ENB
value|0x02
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_LINKEVT_ENB
value|0x04
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_WAKEPOLARITY
value|0x08
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_WAKEPKTEVENT
value|0x10
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_MAGICPKTEVENT
value|0x20
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_LINKEVENT
value|0x40
end_define

begin_define
define|#
directive|define
name|STE_WAKEEVENT_WAKEONLAN_ENB
value|0x80
end_define

begin_define
define|#
directive|define
name|STE_TXSTATUS_RECLAIMERR
value|0x02
end_define

begin_define
define|#
directive|define
name|STE_TXSTATUS_STATSOFLOW
value|0x04
end_define

begin_define
define|#
directive|define
name|STE_TXSTATUS_EXCESSCOLLS
value|0x08
end_define

begin_define
define|#
directive|define
name|STE_TXSTATUS_UNDERRUN
value|0x10
end_define

begin_define
define|#
directive|define
name|STE_TXSTATUS_TXINTR_REQ
value|0x40
end_define

begin_define
define|#
directive|define
name|STE_TXSTATUS_TXDONE
value|0x80
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_INTLATCH
value|0x0001
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_HOSTERR
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_TX_DONE
value|0x0004
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_MACCTL_FRAME
value|0x0008
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_RX_DONE
value|0x0010
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_RX_EARLY
value|0x0020
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_SOFTINTR
value|0x0040
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_STATS_OFLOW
value|0x0080
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_LINKEVENT
value|0x0100
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_TX_DMADONE
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_ISRACK_RX_DMADONE
value|0x0400
end_define

begin_define
define|#
directive|define
name|STE_IMR_HOSTERR
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_IMR_TX_DONE
value|0x0004
end_define

begin_define
define|#
directive|define
name|STE_IMR_MACCTL_FRAME
value|0x0008
end_define

begin_define
define|#
directive|define
name|STE_IMR_RX_DONE
value|0x0010
end_define

begin_define
define|#
directive|define
name|STE_IMR_RX_EARLY
value|0x0020
end_define

begin_define
define|#
directive|define
name|STE_IMR_SOFTINTR
value|0x0040
end_define

begin_define
define|#
directive|define
name|STE_IMR_STATS_OFLOW
value|0x0080
end_define

begin_define
define|#
directive|define
name|STE_IMR_LINKEVENT
value|0x0100
end_define

begin_define
define|#
directive|define
name|STE_IMR_TX_DMADONE
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_IMR_RX_DMADONE
value|0x0400
end_define

begin_define
define|#
directive|define
name|STE_INTRS
define|\
value|(STE_IMR_RX_DMADONE|STE_IMR_TX_DMADONE|	\ 	STE_IMR_TX_DONE|STE_IMR_HOSTERR| \         STE_IMR_LINKEVENT)
end_define

begin_define
define|#
directive|define
name|STE_ISR_INTLATCH
value|0x0001
end_define

begin_define
define|#
directive|define
name|STE_ISR_HOSTERR
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_ISR_TX_DONE
value|0x0004
end_define

begin_define
define|#
directive|define
name|STE_ISR_MACCTL_FRAME
value|0x0008
end_define

begin_define
define|#
directive|define
name|STE_ISR_RX_DONE
value|0x0010
end_define

begin_define
define|#
directive|define
name|STE_ISR_RX_EARLY
value|0x0020
end_define

begin_define
define|#
directive|define
name|STE_ISR_SOFTINTR
value|0x0040
end_define

begin_define
define|#
directive|define
name|STE_ISR_STATS_OFLOW
value|0x0080
end_define

begin_define
define|#
directive|define
name|STE_ISR_LINKEVENT
value|0x0100
end_define

begin_define
define|#
directive|define
name|STE_ISR_TX_DMADONE
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_ISR_RX_DMADONE
value|0x0400
end_define

begin_comment
comment|/*  * Note: the Sundance manual gives the impression that the's  * only one 32-bit MACCTL register. In fact, there are two  * 16-bit registers side by side, and you have to access them  * separately.  */
end_comment

begin_define
define|#
directive|define
name|STE_MACCTL0_IPG
value|0x0003
end_define

begin_define
define|#
directive|define
name|STE_MACCTL0_FULLDUPLEX
value|0x0020
end_define

begin_define
define|#
directive|define
name|STE_MACCTL0_RX_GIANTS
value|0x0040
end_define

begin_define
define|#
directive|define
name|STE_MACCTL0_FLOWCTL_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|STE_MACCTL0_RX_FCS
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_MACCTL0_FIFOLOOPBK
value|0x0400
end_define

begin_define
define|#
directive|define
name|STE_MACCTL0_MACLOOPBK
value|0x0800
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_COLLDETECT
value|0x0001
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_CARRSENSE
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_TX_BUSY
value|0x0004
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_TX_ERROR
value|0x0008
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_STATS_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_STATS_DISABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_STATS_ENABLED
value|0x0080
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_TX_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_TX_DISABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_TX_ENABLED
value|0x0400
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_RX_ENABLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_RX_DISABLE
value|0x1000
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_RX_ENABLED
value|0x2000
end_define

begin_define
define|#
directive|define
name|STE_MACCTL1_PAUSED
value|0x4000
end_define

begin_define
define|#
directive|define
name|STE_IPG_96BT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|STE_IPG_128BT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|STE_IPG_224BT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|STE_IPG_544BT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|STE_RXMODE_UNICAST
value|0x01
end_define

begin_define
define|#
directive|define
name|STE_RXMODE_ALLMULTI
value|0x02
end_define

begin_define
define|#
directive|define
name|STE_RXMODE_BROADCAST
value|0x04
end_define

begin_define
define|#
directive|define
name|STE_RXMODE_PROMISC
value|0x08
end_define

begin_define
define|#
directive|define
name|STE_RXMODE_MULTIHASH
value|0x10
end_define

begin_define
define|#
directive|define
name|STE_RXMODE_ALLIPMULTI
value|0x20
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_MCLK
value|0x01
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_MDATA
value|0x02
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_MDIR
value|0x04
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_CLK25_DISABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_DUPLEXPOLARITY
value|0x10
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_DUPLEXSTAT
value|0x20
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_SPEEDSTAT
value|0x40
end_define

begin_define
define|#
directive|define
name|STE_PHYCTL_LINKSTAT
value|0x80
end_define

begin_comment
comment|/*  * EEPROM offsets.  */
end_comment

begin_define
define|#
directive|define
name|STE_EEADDR_CONFIGPARM
value|0x00
end_define

begin_define
define|#
directive|define
name|STE_EEADDR_ASICCTL
value|0x02
end_define

begin_define
define|#
directive|define
name|STE_EEADDR_SUBSYS_ID
value|0x04
end_define

begin_define
define|#
directive|define
name|STE_EEADDR_SUBVEN_ID
value|0x08
end_define

begin_define
define|#
directive|define
name|STE_EEADDR_NODE0
value|0x10
end_define

begin_define
define|#
directive|define
name|STE_EEADDR_NODE1
value|0x12
end_define

begin_define
define|#
directive|define
name|STE_EEADDR_NODE2
value|0x14
end_define

begin_comment
comment|/* PCI registers */
end_comment

begin_define
define|#
directive|define
name|STE_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|STE_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|STE_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|STE_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|STE_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|STE_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|STE_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|STE_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|STE_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|STE_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|STE_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|STE_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|STE_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|STE_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|STE_PCI_CAPID
value|0x50
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|STE_PCI_NEXTPTR
value|0x51
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|STE_PCI_PWRMGMTCAP
value|0x52
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|STE_PCI_PWRMGMTCTRL
value|0x54
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|STE_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|STE_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|STE_PSTATE_D1
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|STE_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|STE_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|STE_PME_STATUS
value|0x8000
end_define

begin_struct
struct|struct
name|ste_stats
block|{
name|u_int32_t
name|ste_rx_bytes
decl_stmt|;
name|u_int32_t
name|ste_tx_bytes
decl_stmt|;
name|u_int16_t
name|ste_tx_frames
decl_stmt|;
name|u_int16_t
name|ste_rx_frames
decl_stmt|;
name|u_int8_t
name|ste_carrsense_errs
decl_stmt|;
name|u_int8_t
name|ste_late_colls
decl_stmt|;
name|u_int8_t
name|ste_multi_colls
decl_stmt|;
name|u_int8_t
name|ste_single_colls
decl_stmt|;
name|u_int8_t
name|ste_tx_frames_defered
decl_stmt|;
name|u_int8_t
name|ste_rx_lost_frames
decl_stmt|;
name|u_int8_t
name|ste_tx_excess_defers
decl_stmt|;
name|u_int8_t
name|ste_tx_abort_excess_colls
decl_stmt|;
name|u_int8_t
name|ste_tx_bcast_frames
decl_stmt|;
name|u_int8_t
name|ste_rx_bcast_frames
decl_stmt|;
name|u_int8_t
name|ste_tx_mcast_frames
decl_stmt|;
name|u_int8_t
name|ste_rx_mcast_frames
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste_frag
block|{
name|u_int32_t
name|ste_addr
decl_stmt|;
name|u_int32_t
name|ste_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STE_FRAG_LAST
value|0x80000000
end_define

begin_define
define|#
directive|define
name|STE_FRAG_LEN
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|STE_MAXFRAGS
value|8
end_define

begin_struct
struct|struct
name|ste_desc
block|{
name|u_int32_t
name|ste_next
decl_stmt|;
name|u_int32_t
name|ste_ctl
decl_stmt|;
name|struct
name|ste_frag
name|ste_frags
index|[
name|STE_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste_desc_onefrag
block|{
name|u_int32_t
name|ste_next
decl_stmt|;
name|u_int32_t
name|ste_status
decl_stmt|;
name|struct
name|ste_frag
name|ste_frag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STE_TXCTL_WORDALIGN
value|0x00000003
end_define

begin_define
define|#
directive|define
name|STE_TXCTL_FRAMEID
value|0x000003FC
end_define

begin_define
define|#
directive|define
name|STE_TXCTL_NOCRC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|STE_TXCTL_TXINTR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|STE_TXCTL_DMADONE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|STE_TXCTL_DMAINTR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_FRAMELEN
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_FRAME_ERR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_DMADONE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_FIFO_OFLOW
value|0x00010000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_RUNT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_ALIGNERR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_CRCERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_GIANT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_DRIBBLEBITS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|STE_RXSTAT_DMA_OFLOW
value|0x01000000
end_define

begin_define
define|#
directive|define
name|STE_RXATAT_ONEBUF
value|0x10000000
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
value|bus_space_write_4(sc->ste_btag, sc->ste_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->ste_btag, sc->ste_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->ste_btag, sc->ste_bhandle, reg, val)
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
value|bus_space_read_4(sc->ste_btag, sc->ste_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(sc->ste_btag, sc->ste_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(sc->ste_btag, sc->ste_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|STE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|STE_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|STE_PACKET_SIZE
value|1536
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
name|STE_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|STE_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|STE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_define
define|#
directive|define
name|STE_NEXT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x + 1) % y
end_define

begin_struct
struct|struct
name|ste_type
block|{
name|u_int16_t
name|ste_vid
decl_stmt|;
name|u_int16_t
name|ste_did
decl_stmt|;
name|char
modifier|*
name|ste_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste_list_data
block|{
name|struct
name|ste_desc_onefrag
name|ste_rx_list
index|[
name|STE_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|ste_desc
name|ste_tx_list
index|[
name|STE_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste_chain
block|{
name|struct
name|ste_desc
modifier|*
name|ste_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ste_mbuf
decl_stmt|;
name|struct
name|ste_chain
modifier|*
name|ste_next
decl_stmt|;
name|u_int32_t
name|ste_phys
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste_chain_onefrag
block|{
name|struct
name|ste_desc_onefrag
modifier|*
name|ste_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ste_mbuf
decl_stmt|;
name|struct
name|ste_chain_onefrag
modifier|*
name|ste_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste_chain_data
block|{
name|struct
name|ste_chain_onefrag
name|ste_rx_chain
index|[
name|STE_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|ste_chain
name|ste_tx_chain
index|[
name|STE_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|ste_chain_onefrag
modifier|*
name|ste_rx_head
decl_stmt|;
name|int
name|ste_tx_prod
decl_stmt|;
name|int
name|ste_tx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ste_softc
block|{
name|struct
name|ifnet
modifier|*
name|ste_ifp
decl_stmt|;
name|bus_space_tag_t
name|ste_btag
decl_stmt|;
name|bus_space_handle_t
name|ste_bhandle
decl_stmt|;
name|struct
name|resource
modifier|*
name|ste_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|ste_irq
decl_stmt|;
name|void
modifier|*
name|ste_intrhand
decl_stmt|;
name|struct
name|ste_type
modifier|*
name|ste_info
decl_stmt|;
name|device_t
name|ste_miibus
decl_stmt|;
name|device_t
name|ste_dev
decl_stmt|;
name|int
name|ste_tx_thresh
decl_stmt|;
name|u_int8_t
name|ste_link
decl_stmt|;
name|int
name|ste_if_flags
decl_stmt|;
name|struct
name|ste_chain
modifier|*
name|ste_tx_prev
decl_stmt|;
name|struct
name|ste_list_data
modifier|*
name|ste_ldata
decl_stmt|;
name|struct
name|ste_chain_data
name|ste_cdata
decl_stmt|;
name|struct
name|callout
name|ste_stat_callout
decl_stmt|;
name|struct
name|mtx
name|ste_mtx
decl_stmt|;
name|u_int8_t
name|ste_one_phy
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->ste_mtx)
end_define

begin_define
define|#
directive|define
name|STE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->ste_mtx)
end_define

begin_define
define|#
directive|define
name|STE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->ste_mtx, MA_OWNED)
end_define

begin_struct
struct|struct
name|ste_mii_frame
block|{
name|u_int8_t
name|mii_stdelim
decl_stmt|;
name|u_int8_t
name|mii_opcode
decl_stmt|;
name|u_int8_t
name|mii_phyaddr
decl_stmt|;
name|u_int8_t
name|mii_regaddr
decl_stmt|;
name|u_int8_t
name|mii_turnaround
decl_stmt|;
name|u_int16_t
name|mii_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MII constants  */
end_comment

begin_define
define|#
directive|define
name|STE_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|STE_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|STE_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|STE_MII_TURNAROUND
value|0x02
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_undef
undef|#
directive|undef
name|vtophys
end_undef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|alpha_XXX_dmamap((vm_offset_t)va)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

