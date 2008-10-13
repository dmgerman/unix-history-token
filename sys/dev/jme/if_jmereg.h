begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_JMEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_JMEREG_H
end_define

begin_comment
comment|/*  * JMicron Inc. PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_JMICRON
value|0x197B
end_define

begin_comment
comment|/*  * JMC250 PCI device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_JMC250
value|0x0250
end_define

begin_define
define|#
directive|define
name|DEVICEREVID_JMC250_A0
value|0x00
end_define

begin_define
define|#
directive|define
name|DEVICEREVID_JMC250_A2
value|0x11
end_define

begin_comment
comment|/*  * JMC260 PCI device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_JMC260
value|0x0260
end_define

begin_define
define|#
directive|define
name|DEVICEREVID_JMC260_A0
value|0x00
end_define

begin_define
define|#
directive|define
name|DEVICEID_JMC2XX_MASK
value|0x0FF0
end_define

begin_comment
comment|/* JMC250 PCI configuration register. */
end_comment

begin_define
define|#
directive|define
name|JME_PCI_BAR0
value|0x10
end_define

begin_comment
comment|/* 16KB memory window. */
end_comment

begin_define
define|#
directive|define
name|JME_PCI_BAR1
value|0x18
end_define

begin_comment
comment|/* 128bytes I/O window. */
end_comment

begin_define
define|#
directive|define
name|JME_PCI_BAR2
value|0x1C
end_define

begin_comment
comment|/* 256bytes I/O window. */
end_comment

begin_define
define|#
directive|define
name|JME_PCI_BAR3
value|0x20
end_define

begin_comment
comment|/* 64KB memory window. */
end_comment

begin_define
define|#
directive|define
name|JME_PCI_EROM
value|0x30
end_define

begin_define
define|#
directive|define
name|JME_PCI_DBG
value|0x9C
end_define

begin_define
define|#
directive|define
name|JME_PCI_SPI
value|0xB0
end_define

begin_define
define|#
directive|define
name|SPI_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SPI_SO_STATUS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SPI_SI_CTRL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SPI_SCK_CTRL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SPI_CS_N_CTRL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|JME_PCI_PHYCFG0
value|0xC0
end_define

begin_define
define|#
directive|define
name|JME_PCI_PHYCFG1
value|0xC4
end_define

begin_define
define|#
directive|define
name|JME_PCI_PHYCFG2
value|0xC8
end_define

begin_define
define|#
directive|define
name|JME_PCI_PHYCFG3
value|0xCC
end_define

begin_define
define|#
directive|define
name|JME_PCI_PIPECTL1
value|0xD0
end_define

begin_define
define|#
directive|define
name|JME_PCI_PIPECTL2
value|0xD4
end_define

begin_comment
comment|/* PCIe link error/status. */
end_comment

begin_define
define|#
directive|define
name|JME_PCI_LES
value|0xD8
end_define

begin_comment
comment|/* propeietary register 0. */
end_comment

begin_define
define|#
directive|define
name|JME_PCI_PE0
value|0xE0
end_define

begin_define
define|#
directive|define
name|PE0_SPI_EXIST
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PE0_PME_D0
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PE0_PME_D3H
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PE0_PME_SPI_PAD
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PE0_MASK_ASPM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PE0_EEPROM_RW_DIS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PE0_PCI_INTA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PE0_PCI_INTB
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PE0_PCI_INTC
value|0x00003000
end_define

begin_define
define|#
directive|define
name|PE0_PCI_INTD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PE0_PCI_SVSSID_WR_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_8
value|0x00000700
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_7
value|0x00000600
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_6
value|0x00000500
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_5
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_4
value|0x00000300
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_3
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_SIZE_DEF
value|0x00000700
end_define

begin_define
define|#
directive|define
name|PE0_MSIX_CAP_DIS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PE0_MSI_PVMC_ENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PE0_LCAP_EXIT_LAT_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|PE0_LCAP_EXIT_LAT_DEF
value|0x00000038
end_define

begin_define
define|#
directive|define
name|PE0_PM_AUXC_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|PE0_PM_AUXC_DEF
value|0x00000007
end_define

begin_define
define|#
directive|define
name|JME_PCI_PE1
value|0xE4
end_define

begin_define
define|#
directive|define
name|JME_PCI_PHYTEST
value|0xF8
end_define

begin_define
define|#
directive|define
name|JME_PCI_GPR
value|0xFC
end_define

begin_comment
comment|/*  * JMC Register Map.  * -----------------------------------------------------------------------  *   Register               Size           IO space         Memory space  * -----------------------------------------------------------------------  * Tx/Rx MAC registers    128 bytes     BAR1 + 0x00 ~       BAR0 + 0x00 ~  *                                       BAR1 + 0x7F         BAR0 + 0x7F  * -----------------------------------------------------------------------  * PHY registers          128 bytes     BAR2 + 0x00 ~       BAR0 + 0x400 ~  *                                       BAR2 + 0x7F         BAR0 + 0x47F  * -----------------------------------------------------------------------  * Misc registers         128 bytes     BAR2 + 0x80 ~       BAR0 + 0x800 ~  *                                       BAR2 + 0x7F         BAR0 + 0x87F  * -----------------------------------------------------------------------  * To simplify register access fuctions and to get better performance  * this driver doesn't support IO space access. It could be implemented  * as a function which selects appropriate BARs to access requested  * register.  */
end_comment

begin_comment
comment|/* Tx control and status. */
end_comment

begin_define
define|#
directive|define
name|JME_TXCSR
value|0x0000
end_define

begin_define
define|#
directive|define
name|TXCSR_QWEIGHT_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|TXCSR_QWEIGHT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_SEL_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_START
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_START_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TXCSR_FIFO_THRESH_4QW
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TXCSR_FIFO_THRESH_8QW
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TXCSR_FIFO_THRESH_12QW
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TXCSR_FIFO_THRESH_16QW
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|TXCSR_DMA_SIZE_64
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TXCSR_DMA_SIZE_128
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TXCSR_DMA_SIZE_256
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TXCSR_DMA_SIZE_512
value|0x00000030
end_define

begin_define
define|#
directive|define
name|TXCSR_DMA_BURST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TXCSR_TX_SUSPEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TXCSR_TX_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ0
value|0
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ1
value|1
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ2
value|2
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ3
value|3
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ4
value|4
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ5
value|5
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ6
value|6
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ7
value|7
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_WEIGHT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< TXCSR_QWEIGHT_SHIFT)& TXCSR_QWEIGHT_MASK)
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_WEIGHT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_WEIGHT_MAX
value|15
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_N_SEL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< TXCSR_TXQ_SEL_SHIFT)& TXCSR_TXQ_SEL_MASK)
end_define

begin_define
define|#
directive|define
name|TXCSR_TXQ_N_START
parameter_list|(
name|x
parameter_list|)
define|\
value|(TXCSR_TXQ_START<< (TXCSR_TXQ_START_SHIFT + (x)))
end_define

begin_comment
comment|/* Tx queue descriptor base address. 16bytes alignment required. */
end_comment

begin_define
define|#
directive|define
name|JME_TXDBA_LO
value|0x0004
end_define

begin_define
define|#
directive|define
name|JME_TXDBA_HI
value|0x0008
end_define

begin_comment
comment|/* Tx queue descriptor count. multiple of 16(max = 1024). */
end_comment

begin_define
define|#
directive|define
name|JME_TXQDC
value|0x000C
end_define

begin_define
define|#
directive|define
name|TXQDC_MASK
value|0x0000007F0
end_define

begin_comment
comment|/* Tx queue next descriptor address. */
end_comment

begin_define
define|#
directive|define
name|JME_TXNDA
value|0x0010
end_define

begin_define
define|#
directive|define
name|TXNDA_ADDR_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|TXNDA_DESC_EMPTY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TXNDA_DESC_VALID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TXNDA_DESC_WAIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TXNDA_DESC_FETCH
value|0x00000001
end_define

begin_comment
comment|/* Tx MAC control ans status. */
end_comment

begin_define
define|#
directive|define
name|JME_TXMAC
value|0x0014
end_define

begin_define
define|#
directive|define
name|TXMAC_IFG2_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|TXMAC_IFG2_DEFAULT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TXMAC_IFG1_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|TXMAC_IFG1_DEFAULT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TXMAC_THRESH_1_PKT
value|0x00000300
end_define

begin_define
define|#
directive|define
name|TXMAC_THRESH_1_2_PKT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TXMAC_THRESH_1_4_PKT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TXMAC_THRESH_1_8_PKT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TXMAC_FRAME_BURST
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TXMAC_CARRIER_EXT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TXMAC_IFG_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TXMAC_BACKOFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TXMAC_CARRIER_SENSE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TXMAC_COLL_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TXMAC_CRC_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TXMAC_PAD_ENB
value|0x00000001
end_define

begin_comment
comment|/* Tx pause frame control. */
end_comment

begin_define
define|#
directive|define
name|JME_TXPFC
value|0x0018
end_define

begin_define
define|#
directive|define
name|TXPFC_VLAN_TAG_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|TXPFC_VLAN_TAG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TXPFC_VLAN_ENB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TXPFC_PAUSE_ENB
value|0x00000001
end_define

begin_comment
comment|/* Tx timer/retry at half duplex. */
end_comment

begin_define
define|#
directive|define
name|JME_TXTRHD
value|0x001C
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_PERIOD_ENB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_PERIOD_MASK
value|0x7FFFFF00
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_PERIOD_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_LIMIT_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_LIMIT_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_LIMIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_PERIOD_DEFAULT
value|8192
end_define

begin_define
define|#
directive|define
name|TXTRHD_RT_LIMIT_DEFAULT
value|8
end_define

begin_comment
comment|/* Rx control& status. */
end_comment

begin_define
define|#
directive|define
name|JME_RXCSR
value|0x0020
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_FTHRESH_16T
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_FTHRESH_32T
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_FTHRESH_64T
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_FTHRESH_128T
value|0x30000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_FTHRESH_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_THRESH_16QW
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_THRESH_32QW
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_THRESH_64QW
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_THRESH_128QW
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|RXCSR_FIFO_THRESH_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|RXCSR_DMA_SIZE_16
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXCSR_DMA_SIZE_32
value|0x01000000
end_define

begin_define
define|#
directive|define
name|RXCSR_DMA_SIZE_64
value|0x02000000
end_define

begin_define
define|#
directive|define
name|RXCSR_DMA_SIZE_128
value|0x03000000
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ_SEL_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_256
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_512
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_1024
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_2048
value|0x00003000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_4096
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_8192
value|0x00005000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_16384
value|0x00006000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_GAP_32768
value|0x00007000
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_CNT_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RXCSR_PASS_WAKEUP_PKT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RXCSR_PASS_MAGIC_PKT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RXCSR_PASS_RUNT_PKT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RXCSR_PASS_BAD_PKT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ_START
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RXCSR_RX_SUSPEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RXCSR_RX_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ_N_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< RXCSR_RXQ_SEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ0
value|0
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ1
value|1
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ2
value|2
end_define

begin_define
define|#
directive|define
name|RXCSR_RXQ3
value|3
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_CNT
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x) / 4)<< RXCSR_DESC_RT_CNT_SHIFT)& RXCSR_DESC_RT_CNT_MASK)
end_define

begin_define
define|#
directive|define
name|RXCSR_DESC_RT_CNT_DEFAULT
value|32
end_define

begin_comment
comment|/* Rx queue descriptor base address. 16bytes alignment needed. */
end_comment

begin_define
define|#
directive|define
name|JME_RXDBA_LO
value|0x0024
end_define

begin_define
define|#
directive|define
name|JME_RXDBA_HI
value|0x0028
end_define

begin_comment
comment|/* Rx queue descriptor count. multiple of 16(max = 1024). */
end_comment

begin_define
define|#
directive|define
name|JME_RXQDC
value|0x002C
end_define

begin_define
define|#
directive|define
name|RXQDC_MASK
value|0x0000007F0
end_define

begin_comment
comment|/* Rx queue next descriptor address. */
end_comment

begin_define
define|#
directive|define
name|JME_RXNDA
value|0x0030
end_define

begin_define
define|#
directive|define
name|RXNDA_ADDR_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|RXNDA_DESC_EMPTY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RXNDA_DESC_VALID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RXNDA_DESC_WAIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RXNDA_DESC_FETCH
value|0x00000001
end_define

begin_comment
comment|/* Rx MAC control and status. */
end_comment

begin_define
define|#
directive|define
name|JME_RXMAC
value|0x0034
end_define

begin_define
define|#
directive|define
name|RXMAC_RSS_UNICAST
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXMAC_RSS_UNI_MULTICAST
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RXMAC_RSS_UNI_MULTI_BROADCAST
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RXMAC_RSS_ALLFRAME
value|0x00030000
end_define

begin_define
define|#
directive|define
name|RXMAC_PROMISC
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RXMAC_BROADCAST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RXMAC_MULTICAST
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RXMAC_UNICAST
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RXMAC_ALLMULTI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RXMAC_MULTICAST_FILTER
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RXMAC_COLL_DET_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RXMAC_FC_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RXMAC_VLAN_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RXMAC_PAD_10BYTES
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RXMAC_CSUM_ENB
value|0x00000001
end_define

begin_comment
comment|/* Rx unicast MAC address. */
end_comment

begin_define
define|#
directive|define
name|JME_PAR0
value|0x0038
end_define

begin_define
define|#
directive|define
name|JME_PAR1
value|0x003C
end_define

begin_comment
comment|/* Rx multicast address hash table. */
end_comment

begin_define
define|#
directive|define
name|JME_MAR0
value|0x0040
end_define

begin_define
define|#
directive|define
name|JME_MAR1
value|0x0044
end_define

begin_comment
comment|/* Wakeup frame output data port. */
end_comment

begin_define
define|#
directive|define
name|JME_WFODP
value|0x0048
end_define

begin_comment
comment|/* Wakeup frame output interface. */
end_comment

begin_define
define|#
directive|define
name|JME_WFOI
value|0x004C
end_define

begin_define
define|#
directive|define
name|WFOI_MASK_0_31
value|0x00000000
end_define

begin_define
define|#
directive|define
name|WFOI_MASK_31_63
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WFOI_MASK_64_95
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WFOI_MASK_96_127
value|0x00000030
end_define

begin_define
define|#
directive|define
name|WFOI_MASK_SEL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WFOI_CRC_SEL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|WFOI_WAKEUP_FRAME_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|WFOI_WAKEUP_FRAME_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)& WFOI_WAKEUP_FRAME_MASK)
end_define

begin_comment
comment|/* Station management interface. */
end_comment

begin_define
define|#
directive|define
name|JME_SMI
value|0x0050
end_define

begin_define
define|#
directive|define
name|SMI_DATA_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|SMI_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SMI_REG_ADDR_MASK
value|0x0000F800
end_define

begin_define
define|#
directive|define
name|SMI_REG_ADDR_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|SMI_PHY_ADDR_MASK
value|0x000007C0
end_define

begin_define
define|#
directive|define
name|SMI_PHY_ADDR_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SMI_OP_WRITE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SMI_OP_READ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SMI_OP_EXECUTE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SMI_MDIO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SMI_MDOE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SMI_MDC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SMI_MDEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SMI_REG_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< SMI_REG_ADDR_SHIFT)& SMI_REG_ADDR_MASK)
end_define

begin_define
define|#
directive|define
name|SMI_PHY_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< SMI_PHY_ADDR_SHIFT)& SMI_PHY_ADDR_MASK)
end_define

begin_comment
comment|/* Global host control. */
end_comment

begin_define
define|#
directive|define
name|JME_GHC
value|0x0054
end_define

begin_define
define|#
directive|define
name|GHC_LOOPBACK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|GHC_RESET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|GHC_FULL_DUPLEX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GHC_SPEED_UNKNOWN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GHC_SPEED_10
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GHC_SPEED_100
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GHC_SPEED_1000
value|0x00000030
end_define

begin_define
define|#
directive|define
name|GHC_SPEED_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|GHC_LINK_OFF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GHC_LINK_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GHC_LINK_STAT_POLLING
value|0x00000001
end_define

begin_comment
comment|/* Power management control and status. */
end_comment

begin_define
define|#
directive|define
name|JME_PMCS
value|0x0060
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_7
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_6
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_5
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_4
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_3
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_2
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_1
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_0
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PMCS_LINK_FAIL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PMCS_LINK_RISING
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PMCS_MAGIC_FRAME
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_7_ENB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_6_ENB
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_5_ENB
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_4_ENB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_3_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_2_ENB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_1_ENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PMCS_WAKEUP_FRAME_0_ENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PMCS_LINK_FAIL_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PMCS_LINK_RISING_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PMCS_MAGIC_FRAME_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PMCS_WOL_ENB_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Giga PHY& EEPROM registers. */
end_comment

begin_define
define|#
directive|define
name|JME_PHY_EEPROM_BASE_ADDR
value|0x0400
end_define

begin_define
define|#
directive|define
name|JME_GIGAR0LO
value|0x0400
end_define

begin_define
define|#
directive|define
name|JME_GIGAR0HI
value|0x0404
end_define

begin_define
define|#
directive|define
name|JME_GIGARALO
value|0x0408
end_define

begin_define
define|#
directive|define
name|JME_GIGARAHI
value|0x040C
end_define

begin_define
define|#
directive|define
name|JME_GIGARBLO
value|0x0410
end_define

begin_define
define|#
directive|define
name|JME_GIGARBHI
value|0x0414
end_define

begin_define
define|#
directive|define
name|JME_GIGARCLO
value|0x0418
end_define

begin_define
define|#
directive|define
name|JME_GIGARCHI
value|0x041C
end_define

begin_define
define|#
directive|define
name|JME_GIGARDLO
value|0x0420
end_define

begin_define
define|#
directive|define
name|JME_GIGARDHI
value|0x0424
end_define

begin_comment
comment|/* BIST status and control. */
end_comment

begin_define
define|#
directive|define
name|JME_GIGACSR
value|0x0428
end_define

begin_define
define|#
directive|define
name|GIGACSR_STATUS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|GIGACSR_CTRL_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|GIGACSR_CTRL_DEFAULT
value|0x30000000
end_define

begin_define
define|#
directive|define
name|GIGACSR_TX_CLK_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|GIGACSR_RX_CLK_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|GIGACSR_TX_CLK_INV
value|0x00080000
end_define

begin_define
define|#
directive|define
name|GIGACSR_RX_CLK_INV
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GIGACSR_PHY_RST
value|0x00010000
end_define

begin_define
define|#
directive|define
name|GIGACSR_IRQ_N_O
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GIGACSR_BIST_OK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|GIGACSR_BIST_DONE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|GIGACSR_BIST_LED_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GIGACSR_BIST_MASK
value|0x00000003
end_define

begin_comment
comment|/* PHY Link Status. */
end_comment

begin_define
define|#
directive|define
name|JME_LNKSTS
value|0x0430
end_define

begin_define
define|#
directive|define
name|LINKSTS_SPEED_10
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LINKSTS_SPEED_100
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LINKSTS_SPEED_1000
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LINKSTS_FULL_DUPLEX
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LINKSTS_PAGE_RCVD
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LINKSTS_SPDDPX_RESOLVED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LINKSTS_UP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LINKSTS_ANEG_COMP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LINKSTS_MDI_CROSSOVR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LINKSTS_LPAR_PAUSE_ASYM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINKSTS_LPAR_PAUSE
value|0x00000001
end_define

begin_comment
comment|/* SMB control and status. */
end_comment

begin_define
define|#
directive|define
name|JME_SMBCSR
value|0x0440
end_define

begin_define
define|#
directive|define
name|SMBCSR_SLAVE_ADDR_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|SMBCSR_WR_DATA_NACK
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SMBCSR_CMD_NACK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SMBCSR_RELOAD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SMBCSR_CMD_ADDR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|SMBCSR_SCL_STAT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SMBCSR_SDA_STAT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SMBCSR_EEPROM_PRESENT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SMBCSR_INIT_LD_DONE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SMBCSR_HW_BUSY_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|SMBCSR_HW_IDLE
value|0x00000000
end_define

begin_comment
comment|/* SMB interface. */
end_comment

begin_define
define|#
directive|define
name|JME_SMBINTF
value|0x0444
end_define

begin_define
define|#
directive|define
name|SMBINTF_RD_DATA_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|SMBINTF_RD_DATA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SMBINTF_WR_DATA_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SMBINTF_WR_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SMBINTF_ADDR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|SMBINTF_ADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SMBINTF_RD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SMBINTF_WR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SMBINTF_CMD_TRIGGER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SMBINTF_BUSY
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SMBINTF_FAST_MODE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SMBINTF_GPIO_SCL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SMBINTF_GPIO_SDA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SMBINTF_GPIO_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_SIG0
value|0x55
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_SIG1
value|0xAA
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_DESC_BYTES
value|3
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_DESC_END
value|0x80
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_FUNC_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_FUNC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_PAGE_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_PAGE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_FUNC0
value|0
end_define

begin_comment
comment|/* PCI configuration space. */
end_comment

begin_define
define|#
directive|define
name|JME_EEPROM_PAGE_BAR0
value|0
end_define

begin_comment
comment|/* 128 bytes I/O window. */
end_comment

begin_define
define|#
directive|define
name|JME_EEPROM_PAGE_BAR1
value|1
end_define

begin_comment
comment|/* 256 bytes I/O window. */
end_comment

begin_define
define|#
directive|define
name|JME_EEPROM_PAGE_BAR2
value|2
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_END
value|0xFF
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_MKDESC
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
define|\
value|((((f)& JME_EEPROM_FUNC_MASK)<< JME_EEPROM_FUNC_SHIFT) |	\ 	(((p)& JME_EEPROM_PAGE_MASK)<< JME_EEPROM_PAGE_SHIFT))
end_define

begin_comment
comment|/* 3-wire EEPROM interface. Obsolete interface, use SMBCSR. */
end_comment

begin_define
define|#
directive|define
name|JME_EEPINTF
value|0x0448
end_define

begin_define
define|#
directive|define
name|EEPINTF_DATA_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|EEPINTF_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EEPINTF_ADDR_MASK
value|0x0000FC00
end_define

begin_define
define|#
directive|define
name|EEPINTF_ADDR_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|EEPRINTF_OP_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|EEPINTF_OP_EXECUTE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EEPINTF_DATA_OUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EEPINTF_DATA_IN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EEPINTF_CLK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EEPINTF_SEL
value|0x00000001
end_define

begin_comment
comment|/* 3-wire EEPROM control and status. Obsolete interface, use SMBCSR. */
end_comment

begin_define
define|#
directive|define
name|JME_EEPCSR
value|0x044C
end_define

begin_define
define|#
directive|define
name|EEPCSR_EEPROM_RELOAD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EEPCSR_EEPROM_PRESENT
value|0x00000001
end_define

begin_comment
comment|/* Misc registers. */
end_comment

begin_define
define|#
directive|define
name|JME_MISC_BASE_ADDR
value|0x800
end_define

begin_comment
comment|/* Timer control and status. */
end_comment

begin_define
define|#
directive|define
name|JME_TMCSR
value|0x0800
end_define

begin_define
define|#
directive|define
name|TMCSR_SW_INTR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TMCSR_TIMER_INTR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TMCSR_TIMER_ENB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TMCSR_TIMER_COUNT_MASK
value|0x00FFFFFF
end_define

begin_comment
comment|/* GPIO control and status. */
end_comment

begin_define
define|#
directive|define
name|JME_GPIO
value|0x0804
end_define

begin_define
define|#
directive|define
name|GPIO_4_SPI_IN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|GPIO_3_SPI_IN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|GPIO_4_SPI_OUT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|GPIO_4_SPI_OUT_ENB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|GPIO_3_SPI_OUT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|GPIO_3_SPI_OUT_ENB
value|0x04000000
end_define

begin_define
define|#
directive|define
name|GPIO_3_4_LED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GPIO_3_4_GPIO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|GPIO_2_CLKREQN_IN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|GPIO_2_CLKREQN_OUT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GPIO_2_CLKREQN_OUT_ENB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GPIO_1_LED42_IN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GPIO_1_LED42_OUT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|GPIO_1_LED42_OUT_ENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|GPIO_1_LED42_ENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|GPIO_0_SDA_IN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GPIO_0_SDA_OUT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GPIO_0_SDA_OUT_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GPIO_0_SDA_ENB
value|0x00000001
end_define

begin_comment
comment|/* General purpose register 0. */
end_comment

begin_define
define|#
directive|define
name|JME_GPREG0
value|0x0808
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW7_DIS
value|0x80000000
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW6_DIS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW5_DIS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW4_DIS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW3_DIS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW2_DIS
value|0x04000000
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW1_DIS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|GPREG0_SH_POST_DW0_DIS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|GPREG0_DMA_RD_REQ_8
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GPREG0_DMA_RD_REQ_6
value|0x00100000
end_define

begin_define
define|#
directive|define
name|GPREG0_DMA_RD_REQ_5
value|0x00200000
end_define

begin_define
define|#
directive|define
name|GPREG0_DMA_RD_REQ_4
value|0x00300000
end_define

begin_define
define|#
directive|define
name|GPREG0_POST_DW0_ENB
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GPREG0_PCC_CLR_DIS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GPREG0_FORCE_SCL_OUT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|GPREG0_DL_RSTB_DIS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|GPREG0_STICKY_RESET
value|0x00004000
end_define

begin_define
define|#
directive|define
name|GPREG0_DL_RSTB_CFG_DIS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|GPREG0_LINK_CHG_POLL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GPREG0_LINK_CHG_DIRECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GPREG0_MSI_GEN_SEL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|GPREG0_SMB_PAD_PU_DIS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|GPREG0_PCC_UNIT_16US
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GPREG0_PCC_UNIT_256US
value|0x00000100
end_define

begin_define
define|#
directive|define
name|GPREG0_PCC_UNIT_US
value|0x00000200
end_define

begin_define
define|#
directive|define
name|GPREG0_PCC_UNIT_MS
value|0x00000300
end_define

begin_define
define|#
directive|define
name|GPREG0_PCC_UNIT_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|GPREG0_INTR_EVENT_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|GPREG0_PME_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GPREG0_PHY_ADDR_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|GPREG0_PHY_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GPREG0_PHY_ADDR
value|1
end_define

begin_comment
comment|/* General purpose register 1. */
end_comment

begin_define
define|#
directive|define
name|JME_GPREG1
value|0x080C
end_define

begin_define
define|#
directive|define
name|GPREG1_RSS_IPV6_10_100
value|0x00000040
end_define

begin_comment
comment|/* JMC250 A2 */
end_comment

begin_define
define|#
directive|define
name|GPREG1_HDPX_FIX
value|0x00000020
end_define

begin_comment
comment|/* JMC250 A2 */
end_comment

begin_define
define|#
directive|define
name|GPREG1_INTDLY_UNIT_16US
value|0x00000018
end_define

begin_comment
comment|/* JMC250 A1, A2 */
end_comment

begin_define
define|#
directive|define
name|GPREG1_INTDLY_UNIT_1US
value|0x00000010
end_define

begin_comment
comment|/* JMC250 A1, A2 */
end_comment

begin_define
define|#
directive|define
name|GPREG1_INTDLY_UNIT_256NS
value|0x00000008
end_define

begin_comment
comment|/* JMC250 A1, A2 */
end_comment

begin_define
define|#
directive|define
name|GPREG1_INTDLY_UNIT_16NS
value|0x00000000
end_define

begin_comment
comment|/* JMC250 A1, A2 */
end_comment

begin_define
define|#
directive|define
name|GPREG1_INTDLY_MASK
value|0x00000007
end_define

begin_comment
comment|/* MSIX entry number of interrupt source. */
end_comment

begin_define
define|#
directive|define
name|JME_MSINUM_BASE
value|0x0810
end_define

begin_define
define|#
directive|define
name|JME_MSINUM_END
value|0x081F
end_define

begin_define
define|#
directive|define
name|MSINUM_MASK
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|MSINUM_ENTRY_MASK
value|7
end_define

begin_define
define|#
directive|define
name|MSINUM_REG_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x) / 8)
end_define

begin_define
define|#
directive|define
name|MSINUM_INTR_SOURCE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(((x)& MSINUM_ENTRY_MASK)<< (((y)& 7) * 4))
end_define

begin_define
define|#
directive|define
name|MSINUM_NUM_INTR_SOURCE
value|32
end_define

begin_comment
comment|/* Interrupt event status. */
end_comment

begin_define
define|#
directive|define
name|JME_INTR_STATUS
value|0x0820
end_define

begin_define
define|#
directive|define
name|INTR_SW
value|0x80000000
end_define

begin_define
define|#
directive|define
name|INTR_TIMER
value|0x40000000
end_define

begin_define
define|#
directive|define
name|INTR_LINKCHG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|INTR_PAUSE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|INTR_MAGIC_PKT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|INTR_WAKEUP_PKT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ0_COAL_TO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ1_COAL_TO
value|0x01000000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ2_COAL_TO
value|0x00800000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ3_COAL_TO
value|0x00400000
end_define

begin_define
define|#
directive|define
name|INTR_TXQ_COAL_TO
value|0x00200000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ0_COAL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ1_COAL
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ2_COAL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ3_COAL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INTR_TXQ_COAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ3_DESC_EMPTY
value|0x00008000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ2_DESC_EMPTY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ1_DESC_EMPTY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ0_DESC_EMPTY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|INTR_RXQ3_COMP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|INTR_RXQ2_COMP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|INTR_RXQ1_COMP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|INTR_RXQ0_COMP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|INTR_TXQ7_COMP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_TXQ6_COMP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_TXQ5_COMP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTR_TXQ4_COMP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|INTR_TXQ3_COMP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INTR_TXQ2_COMP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|INTR_TXQ1_COMP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INTR_TXQ0_COMP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INTR_RXQ_COAL_TO
define|\
value|(INTR_RXQ0_COAL_TO | INTR_RXQ1_COAL_TO |		\ 	 INTR_RXQ2_COAL_TO | INTR_RXQ3_COAL_TO)
end_define

begin_define
define|#
directive|define
name|INTR_RXQ_COAL
define|\
value|(INTR_RXQ0_COAL | INTR_RXQ1_COAL | INTR_RXQ2_COAL |	\ 	 INTR_RXQ3_COAL)
end_define

begin_define
define|#
directive|define
name|INTR_RXQ_COMP
define|\
value|(INTR_RXQ0_COMP | INTR_RXQ1_COMP | INTR_RXQ2_COMP |	\ 	 INTR_RXQ3_COMP)
end_define

begin_define
define|#
directive|define
name|INTR_RXQ_DESC_EMPTY
define|\
value|(INTR_RXQ0_DESC_EMPTY | INTR_RXQ1_DESC_EMPTY |		\ 	INTR_RXQ2_DESC_EMPTY | INTR_RXQ3_DESC_EMPTY)
end_define

begin_define
define|#
directive|define
name|INTR_RXQ_COMP
define|\
value|(INTR_RXQ0_COMP | INTR_RXQ1_COMP | INTR_RXQ2_COMP |	\ 	INTR_RXQ3_COMP)
end_define

begin_define
define|#
directive|define
name|INTR_TXQ_COMP
define|\
value|(INTR_TXQ0_COMP | INTR_TXQ1_COMP | INTR_TXQ2_COMP |	\ 	INTR_TXQ3_COMP | INTR_TXQ4_COMP | INTR_TXQ5_COMP | 	\ 	INTR_TXQ6_COMP | INTR_TXQ7_COMP)
end_define

begin_define
define|#
directive|define
name|JME_INTRS
define|\
value|(INTR_RXQ_COAL_TO | INTR_TXQ_COAL_TO | INTR_RXQ_COAL |	\ 	 INTR_TXQ_COAL | INTR_RXQ_DESC_EMPTY)
end_define

begin_define
define|#
directive|define
name|N_INTR_SW
value|31
end_define

begin_define
define|#
directive|define
name|N_INTR_TIMER
value|30
end_define

begin_define
define|#
directive|define
name|N_INTR_LINKCHG
value|29
end_define

begin_define
define|#
directive|define
name|N_INTR_PAUSE
value|28
end_define

begin_define
define|#
directive|define
name|N_INTR_MAGIC_PKT
value|27
end_define

begin_define
define|#
directive|define
name|N_INTR_WAKEUP_PKT
value|26
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ0_COAL_TO
value|25
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ1_COAL_TO
value|24
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ2_COAL_TO
value|23
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ3_COAL_TO
value|22
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ_COAL_TO
value|21
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ0_COAL
value|20
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ1_COAL
value|19
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ2_COAL
value|18
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ3_COAL
value|17
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ_COAL
value|16
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ3_DESC_EMPTY
value|15
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ2_DESC_EMPTY
value|14
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ1_DESC_EMPTY
value|13
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ0_DESC_EMPTY
value|12
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ3_COMP
value|11
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ2_COMP
value|10
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ1_COMP
value|9
end_define

begin_define
define|#
directive|define
name|N_INTR_RXQ0_COMP
value|8
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ7_COMP
value|7
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ6_COMP
value|6
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ5_COMP
value|5
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ4_COMP
value|4
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ3_COMP
value|3
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ2_COMP
value|2
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ1_COMP
value|1
end_define

begin_define
define|#
directive|define
name|N_INTR_TXQ0_COMP
value|0
end_define

begin_comment
comment|/* Interrupt request status. */
end_comment

begin_define
define|#
directive|define
name|JME_INTR_REQ_STATUS
value|0x0824
end_define

begin_comment
comment|/* Interrupt enable - setting port. */
end_comment

begin_define
define|#
directive|define
name|JME_INTR_MASK_SET
value|0x0828
end_define

begin_comment
comment|/* Interrupt enable - clearing port. */
end_comment

begin_define
define|#
directive|define
name|JME_INTR_MASK_CLR
value|0x082C
end_define

begin_comment
comment|/* Packet completion coalescing control of Rx queue 0, 1, 2 and 3. */
end_comment

begin_define
define|#
directive|define
name|JME_PCCRX0
value|0x0830
end_define

begin_define
define|#
directive|define
name|JME_PCCRX1
value|0x0834
end_define

begin_define
define|#
directive|define
name|JME_PCCRX2
value|0x0838
end_define

begin_define
define|#
directive|define
name|JME_PCCRX3
value|0x083C
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_TO_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_TO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_PKT_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_PKT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_TO_MIN
value|1
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_TO_DEFAULT
value|100
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_TO_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_PKT_MIN
value|1
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_PKT_DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|PCCRX_COAL_PKT_MAX
value|255
end_define

begin_comment
comment|/* Packet completion coalescing control of Tx queue. */
end_comment

begin_define
define|#
directive|define
name|JME_PCCTX
value|0x0840
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TO_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_PKT_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_PKT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TXQ0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TO_MIN
value|1
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TO_DEFAULT
value|100
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_TO_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_PKT_MIN
value|1
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_PKT_DEFAULT
value|8
end_define

begin_define
define|#
directive|define
name|PCCTX_COAL_PKT_MAX
value|255
end_define

begin_comment
comment|/* Chip mode and FPGA version. */
end_comment

begin_define
define|#
directive|define
name|JME_CHIPMODE
value|0x0844
end_define

begin_define
define|#
directive|define
name|CHIPMODE_FPGA_REV_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|CHIPMODE_FPGA_REV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPMODE_NOT_FPGA
value|0
end_define

begin_define
define|#
directive|define
name|CHIPMODE_REV_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|CHIPMODE_REV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPMODE_MODE_48P
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|CHIPMODE_MODE_64P
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CHIPMODE_MODE_128P_MAC
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CHIPMODE_MODE_128P_DBG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHIPMODE_MODE_128P_PHY
value|0x00000000
end_define

begin_comment
comment|/* Shadow status base address high/low. */
end_comment

begin_define
define|#
directive|define
name|JME_SHBASE_ADDR_HI
value|0x0848
end_define

begin_define
define|#
directive|define
name|JME_SHBASE_ADDR_LO
value|0x084C
end_define

begin_define
define|#
directive|define
name|SHBASE_ADDR_LO_MASK
value|0xFFFFFFE0
end_define

begin_define
define|#
directive|define
name|SHBASE_POST_FORCE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SHBASE_POST_ENB
value|0x00000001
end_define

begin_comment
comment|/* Timer 1 and 2. */
end_comment

begin_define
define|#
directive|define
name|JME_TIMER1
value|0x0870
end_define

begin_define
define|#
directive|define
name|JME_TIMER2
value|0x0874
end_define

begin_define
define|#
directive|define
name|TIMER_ENB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TIMER_CNT_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|TIMER_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_UNIT
value|1024
end_define

begin_comment
comment|/* 1024us */
end_comment

begin_comment
comment|/* Aggresive power mode control. */
end_comment

begin_define
define|#
directive|define
name|JME_APMC
value|0x087C
end_define

begin_define
define|#
directive|define
name|APMC_PCIE_SDOWN_STAT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|APMC_PCIE_SDOWN_ENB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|APMC_PSEUDO_HOT_PLUG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|APMC_EXT_PLUGIN_ENB
value|0x04000000
end_define

begin_define
define|#
directive|define
name|APMC_EXT_PLUGIN_CTL_MSK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|APMC_DIS_SRAM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|APMC_DIS_CLKPM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|APMC_DIS_CLKTX
value|0x00000001
end_define

begin_comment
comment|/* Packet completion coalesing status of Rx queue 0, 1, 2 and 3. */
end_comment

begin_define
define|#
directive|define
name|JME_PCCSRX_BASE
value|0x0880
end_define

begin_define
define|#
directive|define
name|JME_PCCSRX_END
value|0x088F
end_define

begin_define
define|#
directive|define
name|PCCSRX_REG
parameter_list|(
name|x
parameter_list|)
value|(JME_PCCSRX_BASE + ((x) * 4))
end_define

begin_define
define|#
directive|define
name|PCCSRX_TO_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PCCSRX_TO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCCSRX_PKT_CNT_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PCCSRX_PKT_CNT_SHIFT
value|8
end_define

begin_comment
comment|/* Packet completion coalesing status of Tx queue. */
end_comment

begin_define
define|#
directive|define
name|JME_PCCSTX
value|0x0890
end_define

begin_define
define|#
directive|define
name|PCCSTX_TO_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PCCSTX_TO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCCSTX_PKT_CNT_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PCCSTX_PKT_CNT_SHIFT
value|8
end_define

begin_comment
comment|/* Tx queues empty indicator. */
end_comment

begin_define
define|#
directive|define
name|JME_TXQEMPTY
value|0x0894
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_TXQ0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TXQEMPTY_N_TXQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)& (0x01<< (y)))
end_define

begin_comment
comment|/* RSS control registers. */
end_comment

begin_define
define|#
directive|define
name|JME_RSS_BASE
value|0x0C00
end_define

begin_define
define|#
directive|define
name|JME_RSSC
value|0x0C00
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_LEN_MASK
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_64_ENTRY
value|0x0000A000
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_128_ENTRY
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_NONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_IPV6
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_IPV4
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_IPV6_TCP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RSSC_HASH_IPV4_TCP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RSSC_NCPU_MASK
value|0x000000F8
end_define

begin_define
define|#
directive|define
name|RSSC_NCPU_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|RSSC_DIS_RSS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RSSC_2RXQ_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RSSS_4RXQ_ENB
value|0x00000002
end_define

begin_comment
comment|/* CPU vector. */
end_comment

begin_define
define|#
directive|define
name|JME_RSSCPU
value|0x0C04
end_define

begin_define
define|#
directive|define
name|RSSCPU_N_SEL
parameter_list|(
name|x
parameter_list|)
value|((1<< (x))
end_define

begin_comment
comment|/* RSS Hash value. */
end_comment

begin_define
define|#
directive|define
name|JME_RSSHASH
value|0x0C10
end_define

begin_define
define|#
directive|define
name|JME_RSSHASH_STAT
value|0x0C14
end_define

begin_define
define|#
directive|define
name|JME_RSS_RDATA0
value|0x0C18
end_define

begin_define
define|#
directive|define
name|JME_RSS_RDATA1
value|0x0C1C
end_define

begin_comment
comment|/* RSS secret key. */
end_comment

begin_define
define|#
directive|define
name|JME_RSSKEY_BASE
value|0x0C40
end_define

begin_define
define|#
directive|define
name|JME_RSSKEY_LAST
value|0x0C64
end_define

begin_define
define|#
directive|define
name|JME_RSSKEY_END
value|0x0C67
end_define

begin_define
define|#
directive|define
name|HASHKEY_NBYTES
value|40
end_define

begin_define
define|#
directive|define
name|RSSKEY_REG
parameter_list|(
name|x
parameter_list|)
value|(JME_RSSKEY_LAST - (4 * ((x) / 4)))
end_define

begin_define
define|#
directive|define
name|RSSKEY_VALUE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<< (24 - 8 * ((y) % 4)))
end_define

begin_comment
comment|/* RSS indirection table entries. */
end_comment

begin_define
define|#
directive|define
name|JME_RSSTBL_BASE
value|0x0C80
end_define

begin_define
define|#
directive|define
name|JME_RSSTBL_END
value|0x0CFF
end_define

begin_define
define|#
directive|define
name|RSSTBL_NENTRY
value|128
end_define

begin_define
define|#
directive|define
name|RSSTBL_REG
parameter_list|(
name|x
parameter_list|)
value|(JME_RSSTBL_BASE + ((x) / 4))
end_define

begin_define
define|#
directive|define
name|RSSTBL_VALUE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<< (8 * ((y) % 4)))
end_define

begin_comment
comment|/* MSI-X table. */
end_comment

begin_define
define|#
directive|define
name|JME_MSIX_BASE_ADDR
value|0x2000
end_define

begin_define
define|#
directive|define
name|JME_MSIX_BASE
value|0x2000
end_define

begin_define
define|#
directive|define
name|JME_MSIX_END
value|0x207F
end_define

begin_define
define|#
directive|define
name|JME_MSIX_NENTRY
value|8
end_define

begin_define
define|#
directive|define
name|MSIX_REG
parameter_list|(
name|x
parameter_list|)
value|(JME_MSIX_BASE + ((x) * 0x10))
end_define

begin_define
define|#
directive|define
name|MSIX_ADDR_HI_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|MSIX_ADDR_LO_OFF
value|0x04
end_define

begin_define
define|#
directive|define
name|MSIX_ADDR_LO_MASK
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|MSIX_DATA_OFF
value|0x08
end_define

begin_define
define|#
directive|define
name|MSIX_VECTOR_OFF
value|0x0C
end_define

begin_define
define|#
directive|define
name|MSIX_VECTOR_RSVD
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MSIX_VECTOR_DIS
value|0x00000001
end_define

begin_comment
comment|/* MSI-X PBA. */
end_comment

begin_define
define|#
directive|define
name|JME_MSIX_PBA_BASE_ADDR
value|0x3000
end_define

begin_define
define|#
directive|define
name|JME_MSIX_PBA
value|0x3000
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_RSVD_MASK
value|0xFFFFFF00
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_RSVD_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MSIX_PBA_PEND_ENTRY0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|JME_PHY_OUI
value|0x001B8C
end_define

begin_define
define|#
directive|define
name|JME_PHY_MODEL
value|0x21
end_define

begin_define
define|#
directive|define
name|JME_PHY_REV
value|0x01
end_define

begin_define
define|#
directive|define
name|JME_PHY_ADDR
value|1
end_define

begin_comment
comment|/* JMC250 shadow status block. */
end_comment

begin_struct
struct|struct
name|jme_ssb
block|{
name|uint32_t
name|dw0
decl_stmt|;
name|uint32_t
name|dw1
decl_stmt|;
name|uint32_t
name|dw2
decl_stmt|;
name|uint32_t
name|dw3
decl_stmt|;
name|uint32_t
name|dw4
decl_stmt|;
name|uint32_t
name|dw5
decl_stmt|;
name|uint32_t
name|dw6
decl_stmt|;
name|uint32_t
name|dw7
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* JMC250 descriptor structures. */
end_comment

begin_struct
struct|struct
name|jme_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|buflen
decl_stmt|;
name|uint32_t
name|addr_hi
decl_stmt|;
name|uint32_t
name|addr_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JME_TD_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|JME_TD_INTR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|JME_TD_64BIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|JME_TD_TCPCSUM
value|0x10000000
end_define

begin_define
define|#
directive|define
name|JME_TD_UDPCSUM
value|0x08000000
end_define

begin_define
define|#
directive|define
name|JME_TD_IPCSUM
value|0x04000000
end_define

begin_define
define|#
directive|define
name|JME_TD_TSO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|JME_TD_VLAN_TAG
value|0x01000000
end_define

begin_define
define|#
directive|define
name|JME_TD_VLAN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|JME_TD_MSS_MASK
value|0xFFFC0000
end_define

begin_define
define|#
directive|define
name|JME_TD_MSS_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|JME_TD_BUF_LEN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|JME_TD_BUF_LEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JME_TD_FRAME_LEN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|JME_TD_FRAME_LEN_SHIFT
value|0
end_define

begin_comment
comment|/*  * Only the first Tx descriptor of a packet is updated  * after packet transmission.  */
end_comment

begin_define
define|#
directive|define
name|JME_TD_TMOUT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|JME_TD_RETRY_EXP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|JME_TD_COLLISION
value|0x08000000
end_define

begin_define
define|#
directive|define
name|JME_TD_UNDERRUN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|JME_TD_EHDR_SIZE_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|JME_TD_EHDR_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JME_TD_SEG_CNT_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|JME_TD_SEG_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|JME_TD_RETRY_CNT_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|JME_TD_RETRY_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JME_RD_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|JME_RD_INTR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|JME_RD_64BIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|JME_RD_BUF_LEN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|JME_RD_BUF_LEN_SHIFT
value|0
end_define

begin_comment
comment|/*  * Only the first Rx descriptor of a packet is updated  * after packet reception.  */
end_comment

begin_define
define|#
directive|define
name|JME_RD_MORE_FRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|JME_RD_TCP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|JME_RD_UDP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|JME_RD_IPCSUM
value|0x04000000
end_define

begin_define
define|#
directive|define
name|JME_RD_TCPCSUM
value|0x02000000
end_define

begin_define
define|#
directive|define
name|JME_RD_UDPCSUM
value|0x01000000
end_define

begin_define
define|#
directive|define
name|JME_RD_VLAN_TAG
value|0x00800000
end_define

begin_define
define|#
directive|define
name|JME_RD_IPV4
value|0x00400000
end_define

begin_define
define|#
directive|define
name|JME_RD_IPV6
value|0x00200000
end_define

begin_define
define|#
directive|define
name|JME_RD_PAUSE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|JME_RD_MAGIC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|JME_RD_WAKEUP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|JME_RD_BCAST
value|0x00030000
end_define

begin_define
define|#
directive|define
name|JME_RD_MCAST
value|0x00020000
end_define

begin_define
define|#
directive|define
name|JME_RD_UCAST
value|0x00010000
end_define

begin_define
define|#
directive|define
name|JME_RD_VLAN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|JME_RD_VLAN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JME_RD_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|JME_RD_CNT_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|JME_RD_CNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|JME_RD_GIANT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|JME_RD_GMII_ERR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|JME_RD_NBL_RCVD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|JME_RD_COLL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|JME_RD_ABORT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|JME_RD_RUNT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|JME_RD_FIFO_OVRN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|JME_RD_CRC_ERR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|JME_RD_FRAME_LEN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|JME_RX_ERR_STAT
define|\
value|(JME_RD_GIANT | JME_RD_GMII_ERR | JME_RD_NBL_RCVD |	\ 	JME_RD_COLL | JME_RD_ABORT | JME_RD_RUNT |		\ 	JME_RD_FIFO_OVRN | JME_RD_CRC_ERR)
end_define

begin_define
define|#
directive|define
name|JME_RD_ERR_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|JME_RD_ERR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|JME_RX_ERR
parameter_list|(
name|x
parameter_list|)
value|(((x)& JME_RD_ERR_MASK)>> JME_RD_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|JME_RX_ERR_BITS
value|"\20"					\ 				"\1CRCERR\2FIFOOVRN\3RUNT\4ABORT"	\ 				"\5COLL\6NBLRCVD\7GMIIERR\10"
end_define

begin_define
define|#
directive|define
name|JME_RX_NSEGS
parameter_list|(
name|x
parameter_list|)
value|(((x)& JME_RD_CNT_MASK)>> JME_RD_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|JME_RX_BYTES
parameter_list|(
name|x
parameter_list|)
value|((x)& JME_RD_FRAME_LEN_MASK)
end_define

begin_define
define|#
directive|define
name|JME_RX_PAD_BYTES
value|10
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_VALUE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_IPV4
value|0x00000100
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_IPV4TCP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_IPV6
value|0x00000400
end_define

begin_define
define|#
directive|define
name|JME_RD_RSS_HASH_IPV6TCP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|JME_RD_HASH_FN_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JME_RD_HASH_FN_TOEPLITZ
value|0x00000001
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

