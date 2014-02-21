begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR9300REG_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR9300REG_H
end_define

begin_include
include|#
directive|include
file|"osprey_reg_map.h"
end_include

begin_include
include|#
directive|include
file|"wasp_reg_map.h"
end_include

begin_comment
comment|/******************************************************************************  * MAC Register Map ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AR_MAC_DMA_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct mac_dma_reg, _x)
end_define

begin_comment
comment|/*  * MAC DMA Registers  */
end_comment

begin_comment
comment|/* MAC Control Register - only write values of 1 have effect */
end_comment

begin_define
define|#
directive|define
name|AR_CR
value|AR_MAC_DMA_OFFSET(MAC_DMA_CR)
end_define

begin_define
define|#
directive|define
name|AR_CR_LP_RXE
value|0x00000004
end_define

begin_comment
comment|// Receive LPQ enable
end_comment

begin_define
define|#
directive|define
name|AR_CR_HP_RXE
value|0x00000008
end_define

begin_comment
comment|// Receive HPQ enable
end_comment

begin_define
define|#
directive|define
name|AR_CR_RXD
value|0x00000020
end_define

begin_comment
comment|// Receive disable
end_comment

begin_define
define|#
directive|define
name|AR_CR_SWI
value|0x00000040
end_define

begin_comment
comment|// One-shot software interrupt
end_comment

begin_define
define|#
directive|define
name|AR_CR_RXE
value|(AR_CR_LP_RXE|AR_CR_HP_RXE)
end_define

begin_comment
comment|/* MAC configuration and status register */
end_comment

begin_define
define|#
directive|define
name|AR_CFG
value|AR_MAC_DMA_OFFSET(MAC_DMA_CFG)
end_define

begin_define
define|#
directive|define
name|AR_CFG_SWTD
value|0x00000001
end_define

begin_comment
comment|// byteswap tx descriptor words
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWTB
value|0x00000002
end_define

begin_comment
comment|// byteswap tx data buffer words
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRD
value|0x00000004
end_define

begin_comment
comment|// byteswap rx descriptor words
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRB
value|0x00000008
end_define

begin_comment
comment|// byteswap rx data buffer words
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRG
value|0x00000010
end_define

begin_comment
comment|// byteswap register access data words
end_comment

begin_define
define|#
directive|define
name|AR_CFG_AP_ADHOC_INDICATION
value|0x00000020
end_define

begin_comment
comment|// AP/adhoc indication (0-AP 1-Adhoc)
end_comment

begin_define
define|#
directive|define
name|AR_CFG_PHOK
value|0x00000100
end_define

begin_comment
comment|// PHY OK status
end_comment

begin_define
define|#
directive|define
name|AR_CFG_CLK_GATE_DIS
value|0x00000400
end_define

begin_comment
comment|// Clock gating disable
end_comment

begin_define
define|#
directive|define
name|AR_CFG_EEBS
value|0x00000200
end_define

begin_comment
comment|// EEPROM busy
end_comment

begin_define
define|#
directive|define
name|AR_CFG_PCI_MASTER_REQ_Q_THRESH
value|0x00060000
end_define

begin_comment
comment|// Mask of PCI core master request queue full threshold
end_comment

begin_define
define|#
directive|define
name|AR_CFG_PCI_MASTER_REQ_Q_THRESH_S
value|17
end_define

begin_comment
comment|// Shift for PCI core master request queue full threshold
end_comment

begin_define
define|#
directive|define
name|AR_CFG_MISSING_TX_INTR_FIX_ENABLE
value|0x00080000
end_define

begin_comment
comment|// See EV 61133 for details.
end_comment

begin_comment
comment|/* Rx DMA Data Buffer Pointer Threshold - High and Low Priority register */
end_comment

begin_define
define|#
directive|define
name|AR_RXBP_THRESH
value|AR_MAC_DMA_OFFSET(MAC_DMA_RXBUFPTR_THRESH)
end_define

begin_define
define|#
directive|define
name|AR_RXBP_THRESH_HP
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|AR_RXBP_THRESH_HP_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RXBP_THRESH_LP
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|AR_RXBP_THRESH_LP_S
value|8
end_define

begin_comment
comment|/* Tx DMA Descriptor Pointer Threshold register */
end_comment

begin_define
define|#
directive|define
name|AR_TXDP_THRESH
value|AR_MAC_DMA_OFFSET(MAC_DMA_TXDPPTR_THRESH)
end_define

begin_comment
comment|/* Mac Interrupt rate threshold register */
end_comment

begin_define
define|#
directive|define
name|AR_MIRT
value|AR_MAC_DMA_OFFSET(MAC_DMA_MIRT)
end_define

begin_define
define|#
directive|define
name|AR_MIRT_VAL
value|0x0000ffff
end_define

begin_comment
comment|// in uS
end_comment

begin_define
define|#
directive|define
name|AR_MIRT_VAL_S
value|16
end_define

begin_comment
comment|/* MAC Global Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|AR_IER
value|AR_MAC_DMA_OFFSET(MAC_DMA_GLOBAL_IER)
end_define

begin_define
define|#
directive|define
name|AR_IER_ENABLE
value|0x00000001
end_define

begin_comment
comment|// Global interrupt enable
end_comment

begin_define
define|#
directive|define
name|AR_IER_DISABLE
value|0x00000000
end_define

begin_comment
comment|// Global interrupt disable
end_comment

begin_comment
comment|/* Mac Tx Interrupt mitigation threshold */
end_comment

begin_define
define|#
directive|define
name|AR_TIMT
value|AR_MAC_DMA_OFFSET(MAC_DMA_TIMT)
end_define

begin_define
define|#
directive|define
name|AR_TIMT_LAST
value|0x0000ffff
end_define

begin_comment
comment|// Last packet threshold
end_comment

begin_define
define|#
directive|define
name|AR_TIMT_LAST_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TIMT_FIRST
value|0xffff0000
end_define

begin_comment
comment|// First packet threshold
end_comment

begin_define
define|#
directive|define
name|AR_TIMT_FIRST_S
value|16
end_define

begin_comment
comment|/* Mac Rx Interrupt mitigation threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RIMT
value|AR_MAC_DMA_OFFSET(MAC_DMA_RIMT)
end_define

begin_define
define|#
directive|define
name|AR_RIMT_LAST
value|0x0000ffff
end_define

begin_comment
comment|// Last packet threshold
end_comment

begin_define
define|#
directive|define
name|AR_RIMT_LAST_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RIMT_FIRST
value|0xffff0000
end_define

begin_comment
comment|// First packet threshold
end_comment

begin_define
define|#
directive|define
name|AR_RIMT_FIRST_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_DMASIZE_4B
value|0x00000000
end_define

begin_comment
comment|// DMA size 4 bytes (TXCFG + RXCFG)
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_8B
value|0x00000001
end_define

begin_comment
comment|// DMA size 8 bytes
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_16B
value|0x00000002
end_define

begin_comment
comment|// DMA size 16 bytes
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_32B
value|0x00000003
end_define

begin_comment
comment|// DMA size 32 bytes
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_64B
value|0x00000004
end_define

begin_comment
comment|// DMA size 64 bytes
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_128B
value|0x00000005
end_define

begin_comment
comment|// DMA size 128 bytes
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_256B
value|0x00000006
end_define

begin_comment
comment|// DMA size 256 bytes
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_512B
value|0x00000007
end_define

begin_comment
comment|// DMA size 512 bytes
end_comment

begin_comment
comment|/* MAC Tx DMA size config register */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG
value|AR_MAC_DMA_OFFSET(MAC_DMA_TXCFG)
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_4B
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_8B
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_16B
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_32B
value|3
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_64B
value|4
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_128B
value|5
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_256B
value|6
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_512B
value|7
end_define

begin_define
define|#
directive|define
name|AR_FTRIG
value|0x000003F0
end_define

begin_comment
comment|// Mask for Frame trigger level
end_comment

begin_define
define|#
directive|define
name|AR_FTRIG_S
value|4
end_define

begin_comment
comment|// Shift for Frame trigger level
end_comment

begin_define
define|#
directive|define
name|AR_FTRIG_IMMED
value|0x00000000
end_define

begin_comment
comment|// bytes in PCU TX FIFO before air
end_comment

begin_define
define|#
directive|define
name|AR_FTRIG_64B
value|0x00000010
end_define

begin_comment
comment|// default
end_comment

begin_define
define|#
directive|define
name|AR_FTRIG_128B
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_FTRIG_192B
value|0x00000030
end_define

begin_define
define|#
directive|define
name|AR_FTRIG_256B
value|0x00000040
end_define

begin_comment
comment|// 5 bits total
end_comment

begin_define
define|#
directive|define
name|AR_FTRIG_512B
value|0x00000080
end_define

begin_comment
comment|// 5 bits total
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_ADHOC_BEACON_ATIM_TX_POLICY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_S
value|19
end_define

begin_comment
comment|/* MAC Rx DMA size config register */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG
value|AR_MAC_DMA_OFFSET(MAC_DMA_RXCFG)
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_CHIRP
value|0x00000008
end_define

begin_comment
comment|// Only double chirps
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG_ZLFDMA
value|0x00000010
end_define

begin_comment
comment|// Enable DMA of zero-length frame
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_4B
value|0
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_8B
value|1
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_16B
value|2
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_32B
value|3
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_64B
value|4
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_128B
value|5
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_256B
value|6
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_512B
value|7
end_define

begin_comment
comment|/* MAC Rx jumbo descriptor last address register */
end_comment

begin_define
define|#
directive|define
name|AR_RXJLA
value|AR_MAC_DMA_OFFSET(MAC_DMA_RXJLA)
end_define

begin_comment
comment|/* MAC MIB control register */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC
value|AR_MAC_DMA_OFFSET(MAC_DMA_MIBC)
end_define

begin_define
define|#
directive|define
name|AR_MIBC_COW
value|0x00000001
end_define

begin_comment
comment|// counter overflow warning
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_FMC
value|0x00000002
end_define

begin_comment
comment|// freeze MIB counters
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_CMC
value|0x00000004
end_define

begin_comment
comment|// clear MIB counters
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_MCS
value|0x00000008
end_define

begin_comment
comment|// MIB counter strobe increment all
end_comment

begin_comment
comment|/* MAC timeout prescale count */
end_comment

begin_define
define|#
directive|define
name|AR_TOPS
value|AR_MAC_DMA_OFFSET(MAC_DMA_TOPS)
end_define

begin_define
define|#
directive|define
name|AR_TOPS_MASK
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for timeout prescale
end_comment

begin_comment
comment|/* MAC no frame received timeout */
end_comment

begin_define
define|#
directive|define
name|AR_RXNPTO
value|AR_MAC_DMA_OFFSET(MAC_DMA_RXNPTO)
end_define

begin_define
define|#
directive|define
name|AR_RXNPTO_MASK
value|0x000003FF
end_define

begin_comment
comment|// Mask for no frame received timeout
end_comment

begin_comment
comment|/* MAC no frame trasmitted timeout */
end_comment

begin_define
define|#
directive|define
name|AR_TXNPTO
value|AR_MAC_DMA_OFFSET(MAC_DMA_TXNPTO)
end_define

begin_define
define|#
directive|define
name|AR_TXNPTO_MASK
value|0x000003FF
end_define

begin_comment
comment|// Mask for no frame transmitted timeout
end_comment

begin_define
define|#
directive|define
name|AR_TXNPTO_QCU_MASK
value|0x000FFC00
end_define

begin_comment
comment|// Mask indicating the set of QCUs
end_comment

begin_comment
comment|// for which frame completions will cause
end_comment

begin_comment
comment|// a reset of the no frame transmitted timeout
end_comment

begin_comment
comment|/* MAC receive frame gap timeout */
end_comment

begin_define
define|#
directive|define
name|AR_RPGTO
value|AR_MAC_DMA_OFFSET(MAC_DMA_RPGTO)
end_define

begin_define
define|#
directive|define
name|AR_RPGTO_MASK
value|0x000003FF
end_define

begin_comment
comment|// Mask for receive frame gap timeout
end_comment

begin_comment
comment|/* MAC miscellaneous control/status register */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC
value|AR_MAC_DMA_OFFSET(MAC_DMA_MACMISC)
end_define

begin_define
define|#
directive|define
name|AR_MACMISC_PCI_EXT_FORCE
value|0x00000010
end_define

begin_comment
comment|//force msb to 10 to ahb
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS
value|0x000001E0
end_define

begin_comment
comment|// Mask for DMA observation bus mux select
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_S
value|5
end_define

begin_comment
comment|// Shift for DMA observation bus mux select
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_0
value|0
end_define

begin_comment
comment|// Observation DMA line 0
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_1
value|1
end_define

begin_comment
comment|// Observation DMA line 1
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_2
value|2
end_define

begin_comment
comment|// Observation DMA line 2
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_3
value|3
end_define

begin_comment
comment|// Observation DMA line 3
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_4
value|4
end_define

begin_comment
comment|// Observation DMA line 4
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_5
value|5
end_define

begin_comment
comment|// Observation DMA line 5
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_6
value|6
end_define

begin_comment
comment|// Observation DMA line 6
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_7
value|7
end_define

begin_comment
comment|// Observation DMA line 7
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_LINE_8
value|8
end_define

begin_comment
comment|// Observation DMA line 8
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS
value|0x00000E00
end_define

begin_comment
comment|// Mask for MISC observation bus mux select
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_S
value|9
end_define

begin_comment
comment|// Shift for MISC observation bus mux select
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_BUS_LSB
value|0x00007000
end_define

begin_comment
comment|// Mask for MAC observation bus mux select (lsb)
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_BUS_LSB_S
value|12
end_define

begin_comment
comment|// Shift for MAC observation bus mux select (lsb)
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_BUS_MSB
value|0x00038000
end_define

begin_comment
comment|// Mask for MAC observation bus mux select (msb)
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_BUS_MSB_S
value|15
end_define

begin_comment
comment|// Shift for MAC observation bus mux select (msb)
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_BUS_1
value|1
end_define

begin_comment
comment|// MAC observation bus mux select
end_comment

begin_comment
comment|/* MAC Interrupt Config register */
end_comment

begin_define
define|#
directive|define
name|AR_INTCFG
value|AR_MAC_DMA_OFFSET(MAC_DMA_INTER)
end_define

begin_define
define|#
directive|define
name|AR_INTCFG_REQ
value|0x00000001
end_define

begin_comment
comment|// Interrupt request flag
end_comment

begin_comment
comment|// Indicates whether the DMA engine should generate
end_comment

begin_comment
comment|// an interrupt upon completion of the frame
end_comment

begin_define
define|#
directive|define
name|AR_INTCFG_MSI_RXOK
value|0x00000000
end_define

begin_comment
comment|// Rx interrupt for MSI logic is RXOK
end_comment

begin_define
define|#
directive|define
name|AR_INTCFG_MSI_RXINTM
value|0x00000004
end_define

begin_comment
comment|// Rx interrupt for MSI logic is RXINTM
end_comment

begin_define
define|#
directive|define
name|AR_INTCFG_MSI_RXMINTR
value|0x00000006
end_define

begin_comment
comment|// Rx interrupt for MSI logic is RXMINTR
end_comment

begin_define
define|#
directive|define
name|AR_INTCFG_MSI_TXOK
value|0x00000000
end_define

begin_comment
comment|// Rx interrupt for MSI logic is TXOK
end_comment

begin_define
define|#
directive|define
name|AR_INTCFG_MSI_TXINTM
value|0x00000010
end_define

begin_comment
comment|// Rx interrupt for MSI logic is TXINTM
end_comment

begin_define
define|#
directive|define
name|AR_INTCFG_MSI_TXMINTR
value|0x00000018
end_define

begin_comment
comment|// Rx interrupt for MSI logic is TXMINTR
end_comment

begin_comment
comment|/* MAC DMA Data Buffer length, in bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DATABUF
value|AR_MAC_DMA_OFFSET(MAC_DMA_DATABUF)
end_define

begin_define
define|#
directive|define
name|AR_DATABUF_MASK
value|0x00000FFF
end_define

begin_comment
comment|/* MAC global transmit timeout */
end_comment

begin_define
define|#
directive|define
name|AR_GTXTO
value|AR_MAC_DMA_OFFSET(MAC_DMA_GTT)
end_define

begin_define
define|#
directive|define
name|AR_GTXTO_TIMEOUT_COUNTER
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for timeout counter (in TUs)
end_comment

begin_define
define|#
directive|define
name|AR_GTXTO_TIMEOUT_LIMIT
value|0xFFFF0000
end_define

begin_comment
comment|// Mask for timeout limit (in TUs)
end_comment

begin_define
define|#
directive|define
name|AR_GTXTO_TIMEOUT_LIMIT_S
value|16
end_define

begin_comment
comment|// Shift for timeout limit
end_comment

begin_comment
comment|/* MAC global transmit timeout mode */
end_comment

begin_define
define|#
directive|define
name|AR_GTTM
value|AR_MAC_DMA_OFFSET(MAC_DMA_GTTM)
end_define

begin_define
define|#
directive|define
name|AR_GTTM_USEC
value|0x00000001
end_define

begin_comment
comment|// usec strobe
end_comment

begin_define
define|#
directive|define
name|AR_GTTM_IGNORE_IDLE
value|0x00000002
end_define

begin_comment
comment|// ignore channel idle
end_comment

begin_define
define|#
directive|define
name|AR_GTTM_RESET_IDLE
value|0x00000004
end_define

begin_comment
comment|// reset counter on channel idle low
end_comment

begin_define
define|#
directive|define
name|AR_GTTM_CST_USEC
value|0x00000008
end_define

begin_comment
comment|// CST usec strobe
end_comment

begin_comment
comment|/* MAC carrier sense timeout */
end_comment

begin_define
define|#
directive|define
name|AR_CST
value|AR_MAC_DMA_OFFSET(MAC_DMA_CST)
end_define

begin_define
define|#
directive|define
name|AR_CST_TIMEOUT_COUNTER
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for timeout counter (in TUs)
end_comment

begin_define
define|#
directive|define
name|AR_CST_TIMEOUT_LIMIT
value|0xFFFF0000
end_define

begin_comment
comment|// Mask for timeout limit (in  TUs)
end_comment

begin_define
define|#
directive|define
name|AR_CST_TIMEOUT_LIMIT_S
value|16
end_define

begin_comment
comment|// Shift for timeout limit
end_comment

begin_comment
comment|/* MAC Indicates the size of High and Low priority rx_dp FIFOs */
end_comment

begin_define
define|#
directive|define
name|AR_RXDP_SIZE
value|AR_MAC_DMA_OFFSET(MAC_DMA_RXDP_SIZE)
end_define

begin_define
define|#
directive|define
name|AR_RXDP_LP_SZ_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|AR_RXDP_LP_SZ_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RXDP_HP_SZ_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|AR_RXDP_HP_SZ_S
value|8
end_define

begin_comment
comment|/* MAC Rx High Priority Queue RXDP Pointer (lower 32 bits) */
end_comment

begin_define
define|#
directive|define
name|AR_HP_RXDP
value|AR_MAC_DMA_OFFSET(MAC_DMA_RX_QUEUE_HP_RXDP)
end_define

begin_comment
comment|/* MAC Rx Low Priority Queue RXDP Pointer (lower 32 bits) */
end_comment

begin_define
define|#
directive|define
name|AR_LP_RXDP
value|AR_MAC_DMA_OFFSET(MAC_DMA_RX_QUEUE_LP_RXDP)
end_define

begin_comment
comment|/* Primary Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|AR_ISR
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_P)
end_define

begin_define
define|#
directive|define
name|AR_ISR_HP_RXOK
value|0x00000001
end_define

begin_comment
comment|// At least one frame rx on high-priority queue sans errors
end_comment

begin_define
define|#
directive|define
name|AR_ISR_LP_RXOK
value|0x00000002
end_define

begin_comment
comment|// At least one frame rx on low-priority queue sans errors
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXERR
value|0x00000004
end_define

begin_comment
comment|// Receive error interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXNOPKT
value|0x00000008
end_define

begin_comment
comment|// No frame received within timeout clock
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXEOL
value|0x00000010
end_define

begin_comment
comment|// Received descriptor empty interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXORN
value|0x00000020
end_define

begin_comment
comment|// Receive FIFO overrun interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXOK
value|0x00000040
end_define

begin_comment
comment|// Transmit okay interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXERR
value|0x00000100
end_define

begin_comment
comment|// Transmit error interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXNOPKT
value|0x00000200
end_define

begin_comment
comment|// No frame transmitted interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXEOL
value|0x00000400
end_define

begin_comment
comment|// Transmit descriptor empty interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXURN
value|0x00000800
end_define

begin_comment
comment|// Transmit FIFO underrun interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_MIB
value|0x00001000
end_define

begin_comment
comment|// MIB interrupt - see MIBC
end_comment

begin_define
define|#
directive|define
name|AR_ISR_SWI
value|0x00002000
end_define

begin_comment
comment|// Software interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXPHY
value|0x00004000
end_define

begin_comment
comment|// PHY receive error interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXKCM
value|0x00008000
end_define

begin_comment
comment|// Key-cache miss interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_SWBA
value|0x00010000
end_define

begin_comment
comment|// Software beacon alert interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BRSSI
value|0x00020000
end_define

begin_comment
comment|// Beacon threshold interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BMISS
value|0x00040000
end_define

begin_comment
comment|// Beacon missed interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXMINTR
value|0x00080000
end_define

begin_comment
comment|// Maximum interrupt transmit rate
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BNR
value|0x00100000
end_define

begin_comment
comment|// Beacon not ready interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXCHIRP
value|0x00200000
end_define

begin_comment
comment|// Phy received a 'chirp'
end_comment

begin_define
define|#
directive|define
name|AR_ISR_HCFPOLL
value|0x00400000
end_define

begin_comment
comment|// Received directed HCF poll
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BCNMISC
value|0x00800000
end_define

begin_comment
comment|// CST, GTT, TIM, CABEND, DTIMSYNC, BCNTO, CABTO,
end_comment

begin_comment
comment|// TSFOOR, DTIM, and TBTT_TIME bits bits from ISR_S2
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TIM
value|0x00800000
end_define

begin_comment
comment|// TIM interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXMINTR
value|0x01000000
end_define

begin_comment
comment|// Maximum interrupt receive rate
end_comment

begin_define
define|#
directive|define
name|AR_ISR_QCBROVF
value|0x02000000
end_define

begin_comment
comment|// QCU CBR overflow interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_QCBRURN
value|0x04000000
end_define

begin_comment
comment|// QCU CBR underrun interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_QTRIG
value|0x08000000
end_define

begin_comment
comment|// QCU scheduling trigger interrupt
end_comment

begin_define
define|#
directive|define
name|AR_ISR_GENTMR
value|0x10000000
end_define

begin_comment
comment|// OR of generic timer bits in ISR 5
end_comment

begin_define
define|#
directive|define
name|AR_ISR_HCFTO
value|0x20000000
end_define

begin_comment
comment|// HCF poll timeout
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXINTM
value|0x40000000
end_define

begin_comment
comment|// Tx interrupt after mitigation
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXINTM
value|0x80000000
end_define

begin_comment
comment|// Rx interrupt after mitigation
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 0 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S0)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S0_QCU_TXOK
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXOK (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0_QCU_TXOK_S
value|0
end_define

begin_comment
comment|// Shift for TXOK (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 1 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S1)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXERR
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXERR (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXERR_S
value|0
end_define

begin_comment
comment|// Shift for TXERR (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXEOL
value|0x03FF0000
end_define

begin_comment
comment|// Mask for TXEOL (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXEOL_S
value|16
end_define

begin_comment
comment|// Shift for TXEOL (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 2 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S2)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S2_QCU_TXURN
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXURN (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_BBPANIC
value|0x00010000
end_define

begin_comment
comment|// Panic watchdog IRQ from BB
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_CST
value|0x00400000
end_define

begin_comment
comment|// Carrier sense timeout
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_GTT
value|0x00800000
end_define

begin_comment
comment|// Global transmit timeout
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_TIM
value|0x01000000
end_define

begin_comment
comment|// TIM
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_CABEND
value|0x02000000
end_define

begin_comment
comment|// CABEND
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_DTIMSYNC
value|0x04000000
end_define

begin_comment
comment|// DTIMSYNC
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_BCNTO
value|0x08000000
end_define

begin_comment
comment|// BCNTO
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_CABTO
value|0x10000000
end_define

begin_comment
comment|// CABTO
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_DTIM
value|0x20000000
end_define

begin_comment
comment|// DTIM
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_TSFOOR
value|0x40000000
end_define

begin_comment
comment|// Rx TSF out of range
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_TBTT_TIME
value|0x80000000
end_define

begin_comment
comment|// TBTT-referenced timer
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 3 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S3
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S3)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S3_QCU_QCBROVF
value|0x000003FF
end_define

begin_comment
comment|// Mask for QCBROVF (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S3_QCU_QCBRURN
value|0x03FF0000
end_define

begin_comment
comment|// Mask for QCBRURN (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 4 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S4
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S4)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S4_QCU_QTRIG
value|0x000003FF
end_define

begin_comment
comment|// Mask for QTRIG (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S4_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 5 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S5)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S5_TIMER_TRIG
value|0x000000FF
end_define

begin_comment
comment|// Mask for timer trigger (0-7)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5_TIMER_THRESH
value|0x0007FE00
end_define

begin_comment
comment|// Mask for timer threshold(0-7)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5_TIM_TIMER
value|0x00000010
end_define

begin_comment
comment|// TIM Timer ISR
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5_DTIM_TIMER
value|0x00000020
end_define

begin_comment
comment|// DTIM Timer ISR
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5_GENTIMER_TRIG
value|0x0000FF80
end_define

begin_comment
comment|// ISR for generic timer trigger 7
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5_GENTIMER_TRIG_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_ISR_S5_GENTIMER_THRESH
value|0xFF800000
end_define

begin_comment
comment|// ISR for generic timer threshold 7
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5_GENTIMER_THRESH_S
value|16
end_define

begin_comment
comment|/* Primary Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|AR_IMR
value|AR_MAC_DMA_OFFSET(MAC_DMA_IMR_P)
end_define

begin_define
define|#
directive|define
name|AR_IMR_RXOK_HP
value|0x00000001
end_define

begin_comment
comment|// Receive high-priority interrupt enable mask
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXOK_LP
value|0x00000002
end_define

begin_comment
comment|// Receive low-priority interrupt enable mask
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXERR
value|0x00000004
end_define

begin_comment
comment|// Receive error interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXNOPKT
value|0x00000008
end_define

begin_comment
comment|// No frame received within timeout clock
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXEOL
value|0x00000010
end_define

begin_comment
comment|// Received descriptor empty interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXORN
value|0x00000020
end_define

begin_comment
comment|// Receive FIFO overrun interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXOK
value|0x00000040
end_define

begin_comment
comment|// Transmit okay interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXERR
value|0x00000100
end_define

begin_comment
comment|// Transmit error interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXNOPKT
value|0x00000200
end_define

begin_comment
comment|// No frame transmitted interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXEOL
value|0x00000400
end_define

begin_comment
comment|// Transmit descriptor empty interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXURN
value|0x00000800
end_define

begin_comment
comment|// Transmit FIFO underrun interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_MIB
value|0x00001000
end_define

begin_comment
comment|// MIB interrupt - see MIBC
end_comment

begin_define
define|#
directive|define
name|AR_IMR_SWI
value|0x00002000
end_define

begin_comment
comment|// Software interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXPHY
value|0x00004000
end_define

begin_comment
comment|// PHY receive error interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXKCM
value|0x00008000
end_define

begin_comment
comment|// Key-cache miss interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_SWBA
value|0x00010000
end_define

begin_comment
comment|// Software beacon alert interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BRSSI
value|0x00020000
end_define

begin_comment
comment|// Beacon threshold interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BMISS
value|0x00040000
end_define

begin_comment
comment|// Beacon missed interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXMINTR
value|0x00080000
end_define

begin_comment
comment|// Maximum interrupt transmit rate
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BNR
value|0x00100000
end_define

begin_comment
comment|// BNR interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXCHIRP
value|0x00200000
end_define

begin_comment
comment|// RXCHIRP interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BCNMISC
value|0x00800000
end_define

begin_comment
comment|// Venice: BCNMISC
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TIM
value|0x00800000
end_define

begin_comment
comment|// TIM interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXMINTR
value|0x01000000
end_define

begin_comment
comment|// Maximum interrupt receive rate
end_comment

begin_define
define|#
directive|define
name|AR_IMR_QCBROVF
value|0x02000000
end_define

begin_comment
comment|// QCU CBR overflow interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_QCBRURN
value|0x04000000
end_define

begin_comment
comment|// QCU CBR underrun interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_QTRIG
value|0x08000000
end_define

begin_comment
comment|// QCU scheduling trigger interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_GENTMR
value|0x10000000
end_define

begin_comment
comment|// Generic timer interrupt
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXINTM
value|0x40000000
end_define

begin_comment
comment|// Tx interrupt after mitigation
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXINTM
value|0x80000000
end_define

begin_comment
comment|// Rx interrupt after mitigation
end_comment

begin_comment
comment|/* MAC Secondary interrupt mask register 0 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S0
value|AR_MAC_DMA_OFFSET(MAC_DMA_IMR_S0)
end_define

begin_define
define|#
directive|define
name|AR_IMR_S0_QCU_TXOK
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXOK (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S0_QCU_TXOK_S
value|0
end_define

begin_comment
comment|// Shift for TXOK (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt mask register 1 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1
value|AR_MAC_DMA_OFFSET(MAC_DMA_IMR_S1)
end_define

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXERR
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXERR (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXERR_S
value|0
end_define

begin_comment
comment|// Shift for TXERR (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXEOL
value|0x03FF0000
end_define

begin_comment
comment|// Mask for TXEOL (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXEOL_S
value|16
end_define

begin_comment
comment|// Shift for TXEOL (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt mask register 2 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2
value|AR_MAC_DMA_OFFSET(MAC_DMA_IMR_S2)
end_define

begin_define
define|#
directive|define
name|AR_IMR_S2_QCU_TXURN
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXURN (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_QCU_TXURN_S
value|0
end_define

begin_comment
comment|// Shift for TXURN (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_BBPANIC
value|0x00010000
end_define

begin_comment
comment|// Panic watchdog IRQ from BB
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_CST
value|0x00400000
end_define

begin_comment
comment|// Carrier sense timeout
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_GTT
value|0x00800000
end_define

begin_comment
comment|// Global transmit timeout
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_TIM
value|0x01000000
end_define

begin_comment
comment|// TIM
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_CABEND
value|0x02000000
end_define

begin_comment
comment|// CABEND
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_DTIMSYNC
value|0x04000000
end_define

begin_comment
comment|// DTIMSYNC
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_BCNTO
value|0x08000000
end_define

begin_comment
comment|// BCNTO
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_CABTO
value|0x10000000
end_define

begin_comment
comment|// CABTO
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_DTIM
value|0x20000000
end_define

begin_comment
comment|// DTIM
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_TSFOOR
value|0x40000000
end_define

begin_comment
comment|// TSF out of range
end_comment

begin_comment
comment|/* MAC Secondary interrupt mask register 3 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S3
value|AR_MAC_DMA_OFFSET(MAC_DMA_IMR_S3)
end_define

begin_define
define|#
directive|define
name|AR_IMR_S3_QCU_QCBROVF
value|0x000003FF
end_define

begin_comment
comment|// Mask for QCBROVF (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S3_QCU_QCBRURN
value|0x03FF0000
end_define

begin_comment
comment|// Mask for QCBRURN (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S3_QCU_QCBRURN_S
value|16
end_define

begin_comment
comment|// Shift for QCBRURN (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt mask register 4 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S4
value|AR_MAC_DMA_OFFSET(MAC_DMA_IMR_S4)
end_define

begin_define
define|#
directive|define
name|AR_IMR_S4_QCU_QTRIG
value|0x000003FF
end_define

begin_comment
comment|// Mask for QTRIG (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S4_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC Secondary interrupt mask register 5 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5
value|AR_MAC_DMA_OFFSET(MAC_DMA_IMR_S5)
end_define

begin_define
define|#
directive|define
name|AR_IMR_S5_TIMER_TRIG
value|0x000000FF
end_define

begin_comment
comment|// Mask for timer trigger (0-7)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5_TIMER_THRESH
value|0x0000FF00
end_define

begin_comment
comment|// Mask for timer threshold(0-7)
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5_TIM_TIMER
value|0x00000010
end_define

begin_comment
comment|// TIM Timer Mask
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5_DTIM_TIMER
value|0x00000020
end_define

begin_comment
comment|// DTIM Timer Mask
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5_GENTIMER7
value|0x00000080
end_define

begin_comment
comment|// Mask for timer 7 trigger
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5_GENTIMER_TRIG
value|0x0000FF80
end_define

begin_comment
comment|// Mask for generic timer trigger 7-15
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5_GENTIMER_TRIG_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_IMR_S5_GENTIMER_THRESH
value|0xFF800000
end_define

begin_comment
comment|// Mask for generic timer threshold 7-15
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S5_GENTIMER_THRESH_S
value|16
end_define

begin_comment
comment|/* Interrupt status registers (read-and-clear access secondary shadow copies) */
end_comment

begin_comment
comment|/* MAC Primary interrupt status register read-and-clear access */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RAC
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_P_RAC)
end_define

begin_comment
comment|/* MAC Secondary interrupt status register 0 - shadow copy */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0_S
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S0_S)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S0_QCU_TXOK
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXOK (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0_QCU_TXOK_S
value|0
end_define

begin_comment
comment|// Shift for TXOK (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 1 - shadow copy */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_S
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S1_S)
end_define

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXERR
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXERR (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXERR_S
value|0
end_define

begin_comment
comment|// Shift for TXERR (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXEOL
value|0x03FF0000
end_define

begin_comment
comment|// Mask for TXEOL (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXEOL_S
value|16
end_define

begin_comment
comment|// Shift for TXEOL (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Secondary interrupt status register 2 - shadow copy */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_S
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S2_S)
end_define

begin_comment
comment|/* MAC Secondary interrupt status register 3 - shadow copy */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S3_S
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S3_S)
end_define

begin_comment
comment|/* MAC Secondary interrupt status register 4 - shadow copy */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S4_S
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S4_S)
end_define

begin_comment
comment|/* MAC Secondary interrupt status register 5 - shadow copy */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S5_S
value|AR_MAC_DMA_OFFSET(MAC_DMA_ISR_S5_S)
end_define

begin_comment
comment|/* MAC DMA Debug Registers */
end_comment

begin_define
define|#
directive|define
name|AR_DMADBG_0
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_0)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_1
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_1)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_2
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_2)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_3
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_3)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_4
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_4)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_5
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_5)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_6
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_6)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_7
value|AR_MAC_DMA_OFFSET(MAC_DMA_DMADBG_7)
end_define

begin_define
define|#
directive|define
name|AR_DMATXDP_QCU_7_0
value|AR_MAC_DMA_OFFSET(MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0)
end_define

begin_define
define|#
directive|define
name|AR_DMATXDP_QCU_9_8
value|AR_MAC_DMA_OFFSET(MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8)
end_define

begin_define
define|#
directive|define
name|AR_DMADBG_RX_STATE
value|0x00000F00
end_define

begin_comment
comment|// Mask for Rx DMA State machine
end_comment

begin_comment
comment|/*  * MAC QCU Registers  */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_QCU_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct mac_qcu_reg, _x)
end_define

begin_define
define|#
directive|define
name|AR_NUM_QCU
value|10
end_define

begin_comment
comment|// Only use QCU 0-9 for forward QCU compatibility
end_comment

begin_define
define|#
directive|define
name|AR_QCU_0
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_QCU_1
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_QCU_2
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_QCU_3
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_QCU_4
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_QCU_5
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_QCU_6
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_QCU_7
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_QCU_8
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_QCU_9
value|0x0200
end_define

begin_comment
comment|/* MAC Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_TXDP
value|AR_MAC_QCU_OFFSET(MAC_QCU_TXDP)
end_define

begin_define
define|#
directive|define
name|AR_QTXDP
parameter_list|(
name|_i
parameter_list|)
value|(AR_Q0_TXDP + ((_i)<<2))
end_define

begin_comment
comment|/* MAC Transmit Status Ring Start Address */
end_comment

begin_define
define|#
directive|define
name|AR_Q_STATUS_RING_START
value|AR_MAC_QCU_OFFSET(MAC_QCU_STATUS_RING_START)
end_define

begin_comment
comment|/* MAC Transmit Status Ring End Address */
end_comment

begin_define
define|#
directive|define
name|AR_Q_STATUS_RING_END
value|AR_MAC_QCU_OFFSET(MAC_QCU_STATUS_RING_END)
end_define

begin_comment
comment|/* Current Address in the Transmit Status Ring pointed to by the MAC */
end_comment

begin_define
define|#
directive|define
name|AR_Q_STATUS_RING_CURRENT
value|AR_MAC_QCU_OFFSET(MAC_QCU_STATUS_RING_CURRENT)
end_define

begin_comment
comment|/* MAC Transmit Queue enable */
end_comment

begin_define
define|#
directive|define
name|AR_Q_TXE
value|AR_MAC_QCU_OFFSET(MAC_QCU_TXE)
end_define

begin_define
define|#
directive|define
name|AR_Q_TXE_M
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXE (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Transmit Queue disable */
end_comment

begin_define
define|#
directive|define
name|AR_Q_TXD
value|AR_MAC_QCU_OFFSET(MAC_QCU_TXD)
end_define

begin_define
define|#
directive|define
name|AR_Q_TXD_M
value|0x000003FF
end_define

begin_comment
comment|// Mask for TXD (QCU 0-9)
end_comment

begin_comment
comment|/* MAC CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_CBRCFG
value|AR_MAC_QCU_OFFSET(MAC_QCU_CBR)
end_define

begin_define
define|#
directive|define
name|AR_QCBRCFG
parameter_list|(
name|_i
parameter_list|)
value|(AR_Q0_CBRCFG + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_INTERVAL
value|0x00FFFFFF
end_define

begin_comment
comment|// Mask for CBR interval (us)
end_comment

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_INTERVAL_S
value|0
end_define

begin_comment
comment|// Shift for CBR interval (us)
end_comment

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_OVF_THRESH
value|0xFF000000
end_define

begin_comment
comment|// Mask for CBR overflow threshold
end_comment

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_OVF_THRESH_S
value|24
end_define

begin_comment
comment|// Shift for CBR overflow threshold
end_comment

begin_comment
comment|/* MAC ready_time configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_RDYTIMECFG
value|AR_MAC_QCU_OFFSET(MAC_QCU_RDYTIME)
end_define

begin_define
define|#
directive|define
name|AR_QRDYTIMECFG
parameter_list|(
name|_i
parameter_list|)
value|(AR_Q0_RDYTIMECFG + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_DURATION
value|0x00FFFFFF
end_define

begin_comment
comment|// Mask for ready_time duration (us)
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_DURATION_S
value|0
end_define

begin_comment
comment|// Shift for ready_time duration (us)
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_EN
value|0x01000000
end_define

begin_comment
comment|// ready_time enable
end_comment

begin_comment
comment|/* MAC OneShotArm set control */
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_SC
value|AR_MAC_QCU_OFFSET(MAC_QCU_ONESHOT_ARM_SC)
end_define

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_SC_M
value|0x000003FF
end_define

begin_comment
comment|// Mask for #define AR_Q_ONESHOTARM_SC (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_SC_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC OneShotArm clear control */
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_CC
value|AR_MAC_QCU_OFFSET(MAC_QCU_ONESHOT_ARM_CC)
end_define

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_CC_M
value|0x000003FF
end_define

begin_comment
comment|// Mask for #define AR_Q_ONESHOTARM_CC (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_CC_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_MISC
value|AR_MAC_QCU_OFFSET(MAC_QCU_MISC)
end_define

begin_define
define|#
directive|define
name|AR_QMISC
parameter_list|(
name|_i
parameter_list|)
value|(AR_Q0_MISC + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP
value|0x0000000F
end_define

begin_comment
comment|// Mask for Frame Scheduling Policy
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_ASAP
value|0
end_define

begin_comment
comment|// ASAP
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_CBR
value|1
end_define

begin_comment
comment|// CBR
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_DBA_GATED
value|2
end_define

begin_comment
comment|// DMA Beacon Alert gated
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_TIM_GATED
value|3
end_define

begin_comment
comment|// TIM gated
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_BEACON_SENT_GATED
value|4
end_define

begin_comment
comment|// Beacon-sent-gated
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_BEACON_RCVD_GATED
value|5
end_define

begin_comment
comment|// Beacon-received-gated
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_ONE_SHOT_EN
value|0x00000010
end_define

begin_comment
comment|// OneShot enable
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_CBR_INCR_DIS1
value|0x00000020
end_define

begin_comment
comment|// Disable CBR expired counter incr (empty q)
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_CBR_INCR_DIS0
value|0x00000040
end_define

begin_comment
comment|// Disable CBR expired counter incr (empty beacon q)
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_BEACON_USE
value|0x00000080
end_define

begin_comment
comment|// Beacon use indication
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_CBR_EXP_CNTR_LIMIT_EN
value|0x00000100
end_define

begin_comment
comment|// CBR expired counter limit enable
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_RDYTIME_EXP_POLICY
value|0x00000200
end_define

begin_comment
comment|// Enable TXE cleared on ready_time expired or VEOL
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_RESET_CBR_EXP_CTR
value|0x00000400
end_define

begin_comment
comment|// Reset CBR expired counter
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_DCU_EARLY_TERM_REQ
value|0x00000800
end_define

begin_comment
comment|// DCU frame early termination request control
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_RESV0
value|0xFFFFF000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_STS
value|AR_MAC_QCU_OFFSET(MAC_QCU_CNT)
end_define

begin_define
define|#
directive|define
name|AR_QSTS
parameter_list|(
name|_i
parameter_list|)
value|(AR_Q0_STS + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q_STS_PEND_FR_CNT
value|0x00000003
end_define

begin_comment
comment|// Mask for Pending Frame Count
end_comment

begin_define
define|#
directive|define
name|AR_Q_STS_RESV0
value|0x000000FC
end_define

begin_comment
comment|// Reserved
end_comment

begin_define
define|#
directive|define
name|AR_Q_STS_CBR_EXP_CNT
value|0x0000FF00
end_define

begin_comment
comment|// Mask for CBR expired counter
end_comment

begin_define
define|#
directive|define
name|AR_Q_STS_RESV1
value|0xFFFF0000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC ReadyTimeShutdown status */
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMESHDN
value|AR_MAC_QCU_OFFSET(MAC_QCU_RDYTIME_SHDN)
end_define

begin_define
define|#
directive|define
name|AR_Q_RDYTIMESHDN_M
value|0x000003FF
end_define

begin_comment
comment|// Mask for ReadyTimeShutdown status (QCU 0-9)
end_comment

begin_comment
comment|/* MAC Descriptor CRC check */
end_comment

begin_define
define|#
directive|define
name|AR_Q_DESC_CRCCHK
value|AR_MAC_QCU_OFFSET(MAC_QCU_DESC_CRC_CHK)
end_define

begin_define
define|#
directive|define
name|AR_Q_DESC_CRCCHK_EN
value|1
end_define

begin_comment
comment|// Enable CRC check on the descriptor fetched from HOST
end_comment

begin_define
define|#
directive|define
name|AR_MAC_QCU_EOL
value|AR_MAC_QCU_OFFSET(MAC_QCU_EOL)
end_define

begin_define
define|#
directive|define
name|AR_MAC_QCU_EOL_DUR_CAL_EN
value|0x000003FF
end_define

begin_comment
comment|// Adjusts EOL for frame duration (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_MAC_QCU_EOL_DUR_CAL_EN_S
value|0
end_define

begin_comment
comment|/*  * MAC DCU Registers  */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_DCU_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct mac_dcu_reg, _x)
end_define

begin_define
define|#
directive|define
name|AR_NUM_DCU
value|10
end_define

begin_comment
comment|// Only use 10 DCU's for forward QCU/DCU compatibility
end_comment

begin_define
define|#
directive|define
name|AR_DCU_0
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_DCU_1
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_DCU_2
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_DCU_3
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_DCU_4
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_DCU_5
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_DCU_6
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_DCU_7
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_DCU_8
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_DCU_9
value|0x0200
end_define

begin_comment
comment|/* MAC QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D0_QCUMASK
value|AR_MAC_DCU_OFFSET(MAC_DCU_QCUMASK)
end_define

begin_define
define|#
directive|define
name|AR_DQCUMASK
parameter_list|(
name|_i
parameter_list|)
value|(AR_D0_QCUMASK + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D_QCUMASK
value|0x000003FF
end_define

begin_comment
comment|// Mask for QCU Mask (QCU 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_D_QCUMASK_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* DCU transmit filter cmd (w/only) */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXBLK_CMD
value|AR_MAC_DCU_OFFSET(MAC_DCU_TXFILTER_DCU0_31_0)
end_define

begin_define
define|#
directive|define
name|AR_D_TXBLK_DATA
parameter_list|(
name|i
parameter_list|)
value|(AR_D_TXBLK_CMD+(i))
end_define

begin_comment
comment|// DCU transmit filter data
end_comment

begin_comment
comment|/* MAC DCU-global IFS settings: SIFS duration */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SIFS
value|AR_MAC_DCU_OFFSET(MAC_DCU_GBL_IFS_SIFS)
end_define

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SIFS_M
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for SIFS duration (core clocks)
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SIFS_RESV0
value|0xFFFFFFFF
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC DCU-global IFS settings: slot duration */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SLOT
value|AR_MAC_DCU_OFFSET(MAC_DCU_GBL_IFS_SLOT)
end_define

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SLOT_M
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for Slot duration (core clocks)
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SLOT_RESV0
value|0xFFFF0000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D0_RETRY_LIMIT
value|AR_MAC_DCU_OFFSET(MAC_DCU_RETRY_LIMIT)
end_define

begin_define
define|#
directive|define
name|AR_DRETRY_LIMIT
parameter_list|(
name|_i
parameter_list|)
value|(AR_D0_RETRY_LIMIT + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_FR_SH
value|0x0000000F
end_define

begin_comment
comment|// Mask for frame short retry limit
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_FR_SH_S
value|0
end_define

begin_comment
comment|// Shift for frame short retry limit
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_SH
value|0x00003F00
end_define

begin_comment
comment|// Mask for station short retry limit
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_SH_S
value|8
end_define

begin_comment
comment|// Shift for station short retry limit
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_LG
value|0x000FC000
end_define

begin_comment
comment|// Mask for station short retry limit
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_LG_S
value|14
end_define

begin_comment
comment|// Shift for station short retry limit
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_RESV0
value|0xFFF00000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC DCU-global IFS settings: EIFS duration */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_EIFS
value|AR_MAC_DCU_OFFSET(MAC_DCU_GBL_IFS_EIFS)
end_define

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_EIFS_M
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for Slot duration (core clocks)
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_EIFS_RESV0
value|0xFFFF0000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D0_CHNTIME
value|AR_MAC_DCU_OFFSET(MAC_DCU_CHANNEL_TIME)
end_define

begin_define
define|#
directive|define
name|AR_DCHNTIME
parameter_list|(
name|_i
parameter_list|)
value|(AR_D0_CHNTIME + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D_CHNTIME_DUR
value|0x000FFFFF
end_define

begin_comment
comment|// Mask for ChannelTime duration (us)
end_comment

begin_define
define|#
directive|define
name|AR_D_CHNTIME_DUR_S
value|0
end_define

begin_comment
comment|// Shift for ChannelTime duration (us)
end_comment

begin_define
define|#
directive|define
name|AR_D_CHNTIME_EN
value|0x00100000
end_define

begin_comment
comment|// ChannelTime enable
end_comment

begin_define
define|#
directive|define
name|AR_D_CHNTIME_RESV0
value|0xFFE00000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC DCU-global IFS settings: Miscellaneous */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC
value|AR_MAC_DCU_OFFSET(MAC_DCU_GBL_IFS_MISC)
end_define

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_LFSR_SLICE_SEL
value|0x00000007
end_define

begin_comment
comment|// Mask forLFSR slice select
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_TURBO_MODE
value|0x00000008
end_define

begin_comment
comment|// Turbo mode indication
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_DCU_ARBITER_DLY
value|0x00300000
end_define

begin_comment
comment|// Mask for DCU arbiter delay
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_RANDOM_LFSR_SLICE_DIS
value|0x01000000
end_define

begin_comment
comment|// Random LSFR slice disable
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_SLOT_XMIT_WIND_LEN
value|0x06000000
end_define

begin_comment
comment|// Slot transmission window length mask
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_FORCE_XMIT_SLOT_BOUND
value|0x08000000
end_define

begin_comment
comment|// Force transmission on slot boundaries
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_IGNORE_BACKOFF
value|0x10000000
end_define

begin_comment
comment|// Ignore backoff
end_comment

begin_comment
comment|/* MAC Miscellaneous DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D0_MISC
value|AR_MAC_DCU_OFFSET(MAC_DCU_MISC)
end_define

begin_define
define|#
directive|define
name|AR_DMISC
parameter_list|(
name|_i
parameter_list|)
value|(AR_D0_MISC + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D_MISC_BKOFF_THRESH
value|0x0000003F
end_define

begin_comment
comment|// Mask for Backoff threshold setting
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_RETRY_CNT_RESET_EN
value|0x00000040
end_define

begin_comment
comment|// End of tx series station RTS/data failure count reset policy
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_CW_RESET_EN
value|0x00000080
end_define

begin_comment
comment|// End of tx series CW reset enable
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_FRAG_WAIT_EN
value|0x00000100
end_define

begin_comment
comment|// Fragment Starvation Policy
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_FRAG_BKOFF_EN
value|0x00000200
end_define

begin_comment
comment|// Backoff during a frag burst
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_CW_BKOFF_EN
value|0x00001000
end_define

begin_comment
comment|// Use binary exponential CW backoff
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING
value|0x0000C000
end_define

begin_comment
comment|// Mask for Virtual collision handling policy
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING_S
value|14
end_define

begin_comment
comment|// Shift for Virtual collision handling policy
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING_DEFAULT
value|0
end_define

begin_comment
comment|// Normal
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING_IGNORE
value|1
end_define

begin_comment
comment|// Ignore
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_BEACON_USE
value|0x00010000
end_define

begin_comment
comment|// Beacon use indication
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL
value|0x00060000
end_define

begin_comment
comment|// Mask for DCU arbiter lockout control
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_S
value|17
end_define

begin_comment
comment|// Shift for DCU arbiter lockout control
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_NONE
value|0
end_define

begin_comment
comment|// No lockout
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_INTRA_FR
value|1
end_define

begin_comment
comment|// Intra-frame
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_GLOBAL
value|2
end_define

begin_comment
comment|// Global
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_IGNORE
value|0x00080000
end_define

begin_comment
comment|// DCU arbiter lockout ignore control
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_SEQ_NUM_INCR_DIS
value|0x00100000
end_define

begin_comment
comment|// Sequence number increment disable
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_POST_FR_BKOFF_DIS
value|0x00200000
end_define

begin_comment
comment|// Post-frame backoff disable
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIT_COL_CW_BKOFF_EN
value|0x00400000
end_define

begin_comment
comment|// Virtual coll. handling policy
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_BLOWN_IFS_RETRY_EN
value|0x00800000
end_define

begin_comment
comment|// Initiate Retry procedure on Blown IFS
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_RESV0
value|0xFF000000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC Frame sequence number control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D_SEQNUM
value|AR_MAC_DCU_OFFSET(MAC_DCU_SEQ)
end_define

begin_comment
comment|/* MAC DCU transmit pause control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE
value|AR_MAC_DCU_OFFSET(MAC_DCU_PAUSE)
end_define

begin_define
define|#
directive|define
name|AR_D_TXPSE_CTRL
value|0x000003FF
end_define

begin_comment
comment|// Mask of DCUs to pause (DCUs 0-9)
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE_RESV0
value|0x0000FC00
end_define

begin_comment
comment|// Reserved
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE_STATUS
value|0x00010000
end_define

begin_comment
comment|// Transmit pause status
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE_RESV1
value|0xFFFE0000
end_define

begin_comment
comment|// Reserved
end_comment

begin_comment
comment|/* MAC DCU WOW Keep-Alive Config register */
end_comment

begin_define
define|#
directive|define
name|AR_D_WOW_KACFG
value|AR_MAC_DCU_OFFSET(MAC_DCU_WOW_KACFG)
end_define

begin_comment
comment|/* MAC DCU transmission slot mask */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXSLOTMASK
value|AR_MAC_DCU_OFFSET(MAC_DCU_TXSLOT)
end_define

begin_define
define|#
directive|define
name|AR_D_TXSLOTMASK_NUM
value|0x0000000F
end_define

begin_comment
comment|// slot numbers
end_comment

begin_comment
comment|/* MAC DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D0_LCL_IFS
value|AR_MAC_DCU_OFFSET(MAC_DCU_LCL_IFS)
end_define

begin_define
define|#
directive|define
name|AR_DLCL_IFS
parameter_list|(
name|_i
parameter_list|)
value|(AR_D0_LCL_IFS + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D9_LCL_IFS
value|AR_DLCL_IFS(9)
end_define

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMIN
value|0x000003FF
end_define

begin_comment
comment|// Mask for CW_MIN
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMIN_S
value|0
end_define

begin_comment
comment|// Shift for CW_MIN
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMAX
value|0x000FFC00
end_define

begin_comment
comment|// Mask for CW_MAX
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMAX_S
value|10
end_define

begin_comment
comment|// Shift for CW_MAX
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_AIFS
value|0x0FF00000
end_define

begin_comment
comment|// Mask for AIFS
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_AIFS_S
value|20
end_define

begin_comment
comment|// Shift for AIFS
end_comment

begin_comment
comment|/*      *  Note:  even though this field is 8 bits wide the      *  maximum supported AIFS value is 0xfc.  Setting the AIFS value      *  to 0xfd 0xfe or 0xff will not work correctly and will cause      *  the DCU to hang.      */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_RESV0
value|0xF0000000
end_define

begin_comment
comment|// Reserved
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED
value|0x1f04
end_define

begin_comment
comment|/* LED control */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SCLK_RATE_IND
value|0x00000003
end_define

begin_comment
comment|/* sleep clock indication */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SCLK_RATE_IND_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_CFG_SCLK_32MHZ
value|0x00000000
end_define

begin_comment
comment|/* Sleep clock rate */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SCLK_4MHZ
value|0x00000001
end_define

begin_comment
comment|/* Sleep clock rate */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SCLK_1MHZ
value|0x00000002
end_define

begin_comment
comment|/* Sleep clock rate */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SCLK_32KHZ
value|0x00000003
end_define

begin_comment
comment|/* Sleep clock rate */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_BLINK_SLOW
value|0x00000008
end_define

begin_comment
comment|/* LED slowest blink rate mode */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_BLINK_THRESH_SEL
value|0x00000070
end_define

begin_comment
comment|/* LED blink threshold select */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_SEL
value|0x00000380
end_define

begin_comment
comment|/* LED mode: bits 7..9 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_SEL_S
value|7
end_define

begin_comment
comment|/* LED mode: bits 7..9 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_POWER
value|0x00000280
end_define

begin_comment
comment|/* Power LED: bit 9=1, bit 7=<LED State> */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_POWER_S
value|7
end_define

begin_comment
comment|/* LED mode: bits 7..9 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_NETWORK
value|0x00000300
end_define

begin_comment
comment|/* Network LED: bit 9=1, bit 8=<LED State> */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_NETWORK_S
value|7
end_define

begin_comment
comment|/* LED mode: bits 7..9 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_PROP
value|0x0
end_define

begin_comment
comment|/* Blink prop to filtered tx/rx */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_RPROP
value|0x1
end_define

begin_comment
comment|/* Blink prop to unfiltered tx/rx */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_SPLIT
value|0x2
end_define

begin_comment
comment|/* Blink power for tx/net for rx */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_RAND
value|0x3
end_define

begin_comment
comment|/* Blink randomly */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_POWER_OFF
value|0x4
end_define

begin_comment
comment|/* Power LED OFF */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_POWER_ON
value|0x5
end_define

begin_comment
comment|/* Power LED ON   */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_NETWORK_OFF
value|0x4
end_define

begin_comment
comment|/* Network LED OFF */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_MODE_NETWORK_ON
value|0x6
end_define

begin_comment
comment|/* Network LED ON  */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_ASSOC_CTL
value|0x00000c00
end_define

begin_comment
comment|/* LED control: bits 10..11 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_ASSOC_CTL_S
value|10
end_define

begin_comment
comment|/* LED control: bits 10..11 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_ASSOC_NONE
value|0x0
end_define

begin_comment
comment|/* 0x00000000: STA is not associated or trying */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_ASSOC_ACTIVE
value|0x1
end_define

begin_comment
comment|/* 0x00000400: STA is associated */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_ASSOC_PENDING
value|0x2
end_define

begin_comment
comment|/* 0x00000800: STA is trying to associate */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_BLINK_SLOW
value|0x00000008
end_define

begin_comment
comment|/* LED slowest blink rate mode: bit 3 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_BLINK_SLOW_S
value|3
end_define

begin_comment
comment|/* LED slowest blink rate mode: bit 3 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_BLINK_THRESH_SEL
value|0x00000070
end_define

begin_comment
comment|/* LED blink threshold select: bits 4..6 */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_LED_BLINK_THRESH_SEL_S
value|4
end_define

begin_comment
comment|/* LED blink threshold select: bits 4..6 */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_SLEEP
value|0x1f00
end_define

begin_define
define|#
directive|define
name|AR_MAC_SLEEP_MAC_AWAKE
value|0x00000000
end_define

begin_comment
comment|// mac is now awake
end_comment

begin_define
define|#
directive|define
name|AR_MAC_SLEEP_MAC_ASLEEP
value|0x00000001
end_define

begin_comment
comment|// mac is now asleep
end_comment

begin_comment
comment|/******************************************************************************  * Host Interface Register Map ******************************************************************************/
end_comment

begin_comment
comment|// DMA& PCI Registers in PCI space (usable during sleep)
end_comment

begin_define
define|#
directive|define
name|AR_HOSTIF_REG
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|)
value|(AH9300(_ah)->ah_hostifregs._reg)
end_define

begin_define
define|#
directive|define
name|AR9300_HOSTIF_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct host_intf_reg, _x)
end_define

begin_define
define|#
directive|define
name|AR9340_HOSTIF_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct host_intf_reg_ar9340, _x)
end_define

begin_comment
comment|/* Interface Reset Control Register */
end_comment

begin_define
define|#
directive|define
name|AR_RC_AHB
value|0x00000001
end_define

begin_comment
comment|// ahb reset
end_comment

begin_define
define|#
directive|define
name|AR_RC_APB
value|0x00000002
end_define

begin_comment
comment|// apb reset
end_comment

begin_define
define|#
directive|define
name|AR_RC_HOSTIF
value|0x00000100
end_define

begin_comment
comment|// host interface reset
end_comment

begin_comment
comment|/* PCI express work-arounds */
end_comment

begin_define
define|#
directive|define
name|AR_WA_D3_TO_L1_DISABLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR_WA_UNTIE_RESET_EN
value|(1<< 15)
end_define

begin_comment
comment|/* Enable PCI Reset to POR (power-on-reset) */
end_comment

begin_define
define|#
directive|define
name|AR_WA_D3_TO_L1_DISABLE_REAL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR_WA_ASPM_TIMER_BASED_DISABLE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR_WA_RESET_EN
value|(1<< 18)
end_define

begin_comment
comment|/* Sw Control to enable PCI-Reset to POR (bit 15) */
end_comment

begin_define
define|#
directive|define
name|AR_WA_ANALOG_SHIFT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR_WA_POR_SHORT
value|(1<< 21)
end_define

begin_comment
comment|/* PCI-E Phy reset control */
end_comment

begin_define
define|#
directive|define
name|AR_WA_COLD_RESET_OVERRIDE
value|(1<< 13)
end_define

begin_comment
comment|/* PCI-E Cold reset override */
end_comment

begin_comment
comment|/* power management state */
end_comment

begin_define
define|#
directive|define
name|AR_PM_STATE_PME_D3COLD_VAUX
value|0x00100000
end_define

begin_comment
comment|//for wow
end_comment

begin_comment
comment|/* CXPL Debug signals which help debug Link Negotiation */
end_comment

begin_comment
comment|/* CXPL Debug signals which help debug Link Negotiation */
end_comment

begin_comment
comment|/* XXX check bit feilds */
end_comment

begin_comment
comment|/* Power Management Control Register */
end_comment

begin_define
define|#
directive|define
name|AR_PCIE_PM_CTRL_ENA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_PMCTRL_WOW_PME_CLR
value|0x00200000
end_define

begin_comment
comment|/* Clear WoW event */
end_comment

begin_define
define|#
directive|define
name|AR_PMCTRL_HOST_PME_EN
value|0x00400000
end_define

begin_comment
comment|/* Send OOB WAKE_L on WoW event */
end_comment

begin_define
define|#
directive|define
name|AR_PMCTRL_D3COLD_VAUX
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR_PMCTRL_PWR_STATE_MASK
value|0x0F000000
end_define

begin_comment
comment|/* Power State Mask */
end_comment

begin_define
define|#
directive|define
name|AR_PMCTRL_PWR_STATE_D1D3
value|0x0F000000
end_define

begin_comment
comment|/* Activate D1 and D3 */
end_comment

begin_define
define|#
directive|define
name|AR_PMCTRL_PWR_STATE_D0
value|0x08000000
end_define

begin_comment
comment|/* Activate D0 */
end_comment

begin_define
define|#
directive|define
name|AR_PMCTRL_PWR_PM_CTRL_ENA
value|0x00008000
end_define

begin_comment
comment|/* Enable power management */
end_comment

begin_define
define|#
directive|define
name|AR_PMCTRL_AUX_PWR_DET
value|0x10000000
end_define

begin_comment
comment|/* Puts Chip in L2 state */
end_comment

begin_comment
comment|/* APB and Local Bus Timeout Counters */
end_comment

begin_define
define|#
directive|define
name|AR_HOST_TIMEOUT_APB_CNTR
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|AR_HOST_TIMEOUT_APB_CNTR_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_HOST_TIMEOUT_LCL_CNTR
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|AR_HOST_TIMEOUT_LCL_CNTR_S
value|16
end_define

begin_comment
comment|/* EEPROM Control Register */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_ABSENT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CORRUPT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROT_MASK
value|0x03FFFC00
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_PROT_MASK_S
value|10
end_define

begin_comment
comment|// Protect Bits RP is read protect WP is write protect
end_comment

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_0_31
value|0x0001
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_0_31
value|0x0002
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_32_63
value|0x0004
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_32_63
value|0x0008
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_64_127
value|0x0010
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_64_127
value|0x0020
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_128_191
value|0x0040
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_128_191
value|0x0080
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_192_255
value|0x0100
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_192_255
value|0x0200
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_256_511
value|0x0400
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_256_511
value|0x0800
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_512_1023
value|0x1000
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_512_1023
value|0x2000
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_RP_1024_2047
value|0x4000
end_define

begin_define
define|#
directive|define
name|EEPROM_PROTECT_WP_1024_2047
value|0x8000
end_define

begin_comment
comment|/* RF silent */
end_comment

begin_define
define|#
directive|define
name|AR_RFSILENT_FORCE
value|0x01
end_define

begin_comment
comment|/* MAC silicon Rev ID */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_ID
value|0x000000FF
end_define

begin_comment
comment|/* Mask to read SREV info */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION
value|0x000000F0
end_define

begin_comment
comment|/* Mask for Chip version */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION_S
value|4
end_define

begin_comment
comment|/* Mask to shift Major Rev Info */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION
value|0x00000007
end_define

begin_comment
comment|/* Mask for Chip revision level */
end_comment

begin_comment
comment|/* Sowl extension to SREV. AR_SREV_ID must be 0xFF */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_ID2
value|0xFFFFFFFF
end_define

begin_comment
comment|/* Mask to read SREV info */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION2
value|0xFFFC0000
end_define

begin_comment
comment|/* Mask for Chip version */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION2_S
value|18
end_define

begin_comment
comment|/* Mask to shift Major Rev Info */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2
value|0x0003F000
end_define

begin_comment
comment|/* Mask for Chip type */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2_S
value|12
end_define

begin_comment
comment|/* Mask to shift Major Rev Info */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2_CHAIN
value|0x00001000
end_define

begin_comment
comment|/* chain mode (1 = 3 chains, 0 = 2 chains) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2_HOST_MODE
value|0x00002000
end_define

begin_comment
comment|/* host mode (1 = PCI, 0 = PCIe) */
end_comment

begin_comment
comment|/* Jupiter has a different TYPE2 definition. */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2_JUPITER_CHAIN
value|0x00001000
end_define

begin_comment
comment|/* chain (1 = 2 chains, 0 = 1 chain) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2_JUPITER_BAND
value|0x00002000
end_define

begin_comment
comment|/* band (1 =  dual band, 0 = single band) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2_JUPITER_BT
value|0x00004000
end_define

begin_comment
comment|/* BT (1 = shared BT, 0 = no BT) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_TYPE2_JUPITER_MODE
value|0x00008000
end_define

begin_comment
comment|/* mode (1 = premium, 0 = standard) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION2
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|AR_SREV_REVISION2_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RADIO_SREV_MAJOR
value|0xf0
end_define

begin_define
define|#
directive|define
name|AR_RAD5133_SREV_MAJOR
value|0xc0
end_define

begin_comment
comment|/* Fowl: 2+5G/3x3 */
end_comment

begin_define
define|#
directive|define
name|AR_RAD2133_SREV_MAJOR
value|0xd0
end_define

begin_comment
comment|/* Fowl: 2G/3x3   */
end_comment

begin_define
define|#
directive|define
name|AR_RAD5122_SREV_MAJOR
value|0xe0
end_define

begin_comment
comment|/* Fowl: 5G/2x2   */
end_comment

begin_define
define|#
directive|define
name|AR_RAD2122_SREV_MAJOR
value|0xf0
end_define

begin_comment
comment|/* Fowl: 2+5G/2x2 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|AR_AHB_MODE
value|0x4024
end_define

begin_comment
comment|// ahb mode for dma
end_comment

begin_define
define|#
directive|define
name|AR_AHB_EXACT_WR_EN
value|0x00000000
end_define

begin_comment
comment|// write exact bytes
end_comment

begin_define
define|#
directive|define
name|AR_AHB_BUF_WR_EN
value|0x00000001
end_define

begin_comment
comment|// buffer write upto cacheline
end_comment

begin_define
define|#
directive|define
name|AR_AHB_EXACT_RD_EN
value|0x00000000
end_define

begin_comment
comment|// read exact bytes
end_comment

begin_define
define|#
directive|define
name|AR_AHB_CACHELINE_RD_EN
value|0x00000002
end_define

begin_comment
comment|// read upto end of cacheline
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PREFETCH_RD_EN
value|0x00000004
end_define

begin_comment
comment|// prefetch upto page boundary
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PAGE_SIZE_1K
value|0x00000000
end_define

begin_comment
comment|// set page-size as 1k
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PAGE_SIZE_2K
value|0x00000008
end_define

begin_comment
comment|// set page-size as 2k
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PAGE_SIZE_4K
value|0x00000010
end_define

begin_comment
comment|// set page-size as 4k
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AR_INTR_RTC_IRQ
value|0x00000001
end_define

begin_comment
comment|// rtc in shutdown state
end_comment

begin_define
define|#
directive|define
name|AR_INTR_MAC_IRQ
value|0x00000002
end_define

begin_comment
comment|// pending mac interrupt
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*   * the following definitions might be differents for WASP so   * disable them to avoid improper use   */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_EEP_PROT_ACCESS
value|0x00000004
end_define

begin_comment
comment|// eeprom protected area access
end_comment

begin_define
define|#
directive|define
name|AR_INTR_MAC_AWAKE
value|0x00020000
end_define

begin_comment
comment|// mac is awake
end_comment

begin_define
define|#
directive|define
name|AR_INTR_MAC_ASLEEP
value|0x00040000
end_define

begin_comment
comment|// mac is asleep
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AR_INTR_SPURIOUS
value|0xFFFFFFFF
end_define

begin_comment
comment|/* TODO: fill in other values */
end_comment

begin_comment
comment|/* Synchronous Interrupt Cause Register */
end_comment

begin_comment
comment|/* Synchronous Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_ENABLE_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|// enable interrupts: bits 18..31
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_ENABLE_GPIO_S
value|18
end_define

begin_comment
comment|// enable interrupts: bits 18..31
end_comment

begin_comment
comment|/*  * synchronous interrupt signals  */
end_comment

begin_enum
enum|enum
block|{
name|AR9300_INTR_SYNC_RTC_IRQ
init|=
literal|0x00000001
block|,
name|AR9300_INTR_SYNC_MAC_IRQ
init|=
literal|0x00000002
block|,
name|AR9300_INTR_SYNC_EEPROM_ILLEGAL_ACCESS
init|=
literal|0x00000004
block|,
name|AR9300_INTR_SYNC_APB_TIMEOUT
init|=
literal|0x00000008
block|,
name|AR9300_INTR_SYNC_PCI_MODE_CONFLICT
init|=
literal|0x00000010
block|,
name|AR9300_INTR_SYNC_HOST1_FATAL
init|=
literal|0x00000020
block|,
name|AR9300_INTR_SYNC_HOST1_PERR
init|=
literal|0x00000040
block|,
name|AR9300_INTR_SYNC_TRCV_FIFO_PERR
init|=
literal|0x00000080
block|,
name|AR9300_INTR_SYNC_RADM_CPL_EP
init|=
literal|0x00000100
block|,
name|AR9300_INTR_SYNC_RADM_CPL_DLLP_ABORT
init|=
literal|0x00000200
block|,
name|AR9300_INTR_SYNC_RADM_CPL_TLP_ABORT
init|=
literal|0x00000400
block|,
name|AR9300_INTR_SYNC_RADM_CPL_ECRC_ERR
init|=
literal|0x00000800
block|,
name|AR9300_INTR_SYNC_RADM_CPL_TIMEOUT
init|=
literal|0x00001000
block|,
name|AR9300_INTR_SYNC_LOCAL_TIMEOUT
init|=
literal|0x00002000
block|,
name|AR9300_INTR_SYNC_PM_ACCESS
init|=
literal|0x00004000
block|,
name|AR9300_INTR_SYNC_MAC_AWAKE
init|=
literal|0x00008000
block|,
name|AR9300_INTR_SYNC_MAC_ASLEEP
init|=
literal|0x00010000
block|,
name|AR9300_INTR_SYNC_MAC_SLEEP_ACCESS
init|=
literal|0x00020000
block|,
name|AR9300_INTR_SYNC_ALL
init|=
literal|0x0003FFFF
block|,
comment|/*      * Do not enable and turn on mask for both sync and async interrupt, since      * chip can generate interrupt storm.      */
name|AR9300_INTR_SYNC_DEF_NO_HOST1_PERR
init|=
operator|(
name|AR9300_INTR_SYNC_HOST1_FATAL
operator||
name|AR9300_INTR_SYNC_RADM_CPL_EP
operator||
name|AR9300_INTR_SYNC_RADM_CPL_DLLP_ABORT
operator||
name|AR9300_INTR_SYNC_RADM_CPL_TLP_ABORT
operator||
name|AR9300_INTR_SYNC_RADM_CPL_ECRC_ERR
operator||
name|AR9300_INTR_SYNC_RADM_CPL_TIMEOUT
operator||
name|AR9300_INTR_SYNC_LOCAL_TIMEOUT
operator||
name|AR9300_INTR_SYNC_MAC_SLEEP_ACCESS
operator|)
block|,
name|AR9300_INTR_SYNC_DEFAULT
init|=
operator|(
name|AR9300_INTR_SYNC_DEF_NO_HOST1_PERR
operator||
name|AR9300_INTR_SYNC_HOST1_PERR
operator|)
block|,
name|AR9300_INTR_SYNC_SPURIOUS
init|=
literal|0xFFFFFFFF
block|,
comment|/* WASP */
name|AR9340_INTR_SYNC_RTC_IRQ
init|=
literal|0x00000001
block|,
name|AR9340_INTR_SYNC_MAC_IRQ
init|=
literal|0x00000002
block|,
name|AR9340_INTR_SYNC_HOST1_FATAL
init|=
literal|0x00000004
block|,
name|AR9340_INTR_SYNC_HOST1_PERR
init|=
literal|0x00000008
block|,
name|AR9340_INTR_SYNC_LOCAL_TIMEOUT
init|=
literal|0x00000010
block|,
name|AR9340_INTR_SYNC_MAC_ASLEEP
init|=
literal|0x00000020
block|,
name|AR9340_INTR_SYNC_MAC_SLEEP_ACCESS
init|=
literal|0x00000040
block|,
name|AR9340_INTR_SYNC_DEFAULT
init|=
operator|(
name|AR9340_INTR_SYNC_HOST1_FATAL
operator||
name|AR9340_INTR_SYNC_HOST1_PERR
operator||
name|AR9340_INTR_SYNC_LOCAL_TIMEOUT
operator||
name|AR9340_INTR_SYNC_MAC_SLEEP_ACCESS
operator|)
block|,
name|AR9340_INTR_SYNC_SPURIOUS
init|=
literal|0xFFFFFFFF
block|, }
enum|;
end_enum

begin_comment
comment|/* Asynchronous Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_MASK_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|// asynchronous interrupt mask: bits 18..31
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_MASK_GPIO_S
value|18
end_define

begin_comment
comment|// asynchronous interrupt mask: bits 18..31
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_MASK_MCI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_MASK_MCI_S
value|7
end_define

begin_comment
comment|/* Synchronous Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MASK_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|// synchronous interrupt mask: bits 18..31
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MASK_GPIO_S
value|18
end_define

begin_comment
comment|// synchronous interrupt mask: bits 18..31
end_comment

begin_comment
comment|/* Asynchronous Interrupt Cause Register */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_CAUSE_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|// GPIO interrupts: bits 18..31
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_CAUSE_MCI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_USED
value|(AR_INTR_MAC_IRQ | AR_INTR_ASYNC_CAUSE_GPIO | AR_INTR_ASYNC_CAUSE_MCI)
end_define

begin_comment
comment|/* Asynchronous Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_ENABLE_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|// enable interrupts: bits 18..31
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_ENABLE_GPIO_S
value|18
end_define

begin_comment
comment|// enable interrupts: bits 18..31
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_ENABLE_MCI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_ENABLE_MCI_S
value|7
end_define

begin_comment
comment|/* PCIE PHY Data Register */
end_comment

begin_comment
comment|/* PCIE PHY Load Register */
end_comment

begin_define
define|#
directive|define
name|AR_PCIE_PM_CTRL_ENA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR93XX_NUM_GPIO
value|16
end_define

begin_comment
comment|// 0 to 15
end_comment

begin_comment
comment|/* GPIO Output Register */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OUT_VAL
value|0x000FFFF
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUT_VAL_S
value|0
end_define

begin_comment
comment|/* GPIO Input Register */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_IN_VAL
value|0x000FFFF
end_define

begin_define
define|#
directive|define
name|AR_GPIO_IN_VAL_S
value|0
end_define

begin_comment
comment|/* Host GPIO output enable bits */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV
value|0x3
end_define

begin_comment
comment|// 2 bit field mask, shifted by 2*bitpos
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_NO
value|0x0
end_define

begin_comment
comment|// tristate
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_LOW
value|0x1
end_define

begin_comment
comment|// drive if low
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_HI
value|0x2
end_define

begin_comment
comment|// drive if high
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_ALL
value|0x3
end_define

begin_comment
comment|// drive always
end_comment

begin_comment
comment|/* Host GPIO output enable bits */
end_comment

begin_comment
comment|/* Host GPIO Interrupt Polarity */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INTR_POL_VAL
value|0x0001FFFF
end_define

begin_comment
comment|// bits 16:0 correspond to gpio 16:0
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INTR_POL_VAL_S
value|0
end_define

begin_comment
comment|// bits 16:0 correspond to gpio 16:0
end_comment

begin_comment
comment|/* Host GPIO Input Value */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_PRIORITY_DEF
value|0x00000004
end_define

begin_comment
comment|// default value for bt_priority_async
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_PRIORITY_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_FREQUENCY_DEF
value|0x00000008
end_define

begin_comment
comment|// default value for bt_frequency_async
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_FREQUENCY_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_ACTIVE_DEF
value|0x00000010
end_define

begin_comment
comment|// default value for bt_active_async
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_ACTIVE_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_RFSILENT_DEF
value|0x00000080
end_define

begin_comment
comment|// default value for rfsilent_bb_l
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_RFSILENT_DEF_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_PRIORITY_BB
value|0x00000400
end_define

begin_comment
comment|// 0 == set bt_priority_async to default, 1 == connect bt_prority_async to baseband
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_PRIORITY_BB_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_FREQUENCY_BB
value|0x00000800
end_define

begin_comment
comment|// 0 == set bt_frequency_async to default, 1 == connect bt_frequency_async to baseband
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_FREQUENCY_BB_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_ACTIVE_BB
value|0x00001000
end_define

begin_comment
comment|// 0 == set bt_active_async to default, 1 == connect bt_active_async to baseband
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_BT_ACTIVE_BB_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_RFSILENT_BB
value|0x00008000
end_define

begin_comment
comment|// 0 == set rfsilent_bb_l to default, 1 == connect rfsilent_bb_l to baseband
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL_RFSILENT_BB_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_GPIO_RTC_RESET_OVERRIDE_ENABLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_GPIO_JTAG_DISABLE
value|0x00020000
end_define

begin_comment
comment|// 1 == disable JTAG
end_comment

begin_comment
comment|/* GPIO Input Mux1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX1_BT_PRIORITY
value|0x00000f00
end_define

begin_comment
comment|/* bits 8..11: input mux for BT priority input */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX1_BT_PRIORITY_S
value|8
end_define

begin_comment
comment|/* bits 8..11: input mux for BT priority input */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX1_BT_FREQUENCY
value|0x0000f000
end_define

begin_comment
comment|/* bits 12..15: input mux for BT frequency input */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX1_BT_FREQUENCY_S
value|12
end_define

begin_comment
comment|/* bits 12..15: input mux for BT frequency input */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX1_BT_ACTIVE
value|0x000f0000
end_define

begin_comment
comment|/* bits 16..19: input mux for BT active input */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX1_BT_ACTIVE_S
value|16
end_define

begin_comment
comment|/* bits 16..19: input mux for BT active input */
end_comment

begin_comment
comment|/* GPIO Input Mux2 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX2_CLK25
value|0x0000000f
end_define

begin_comment
comment|// bits 0..3: input mux for clk25 input
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX2_CLK25_S
value|0
end_define

begin_comment
comment|// bits 0..3: input mux for clk25 input
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX2_RFSILENT
value|0x000000f0
end_define

begin_comment
comment|// bits 4..7: input mux for rfsilent_bb_l input
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX2_RFSILENT_S
value|4
end_define

begin_comment
comment|// bits 4..7: input mux for rfsilent_bb_l input
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX2_RTC_RESET
value|0x00000f00
end_define

begin_comment
comment|// bits 8..11: input mux for RTC Reset input
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX2_RTC_RESET_S
value|8
end_define

begin_comment
comment|// bits 8..11: input mux for RTC Reset input
end_comment

begin_comment
comment|/* GPIO Output Mux1 */
end_comment

begin_comment
comment|/* GPIO Output Mux2 */
end_comment

begin_comment
comment|/* GPIO Output Mux3 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_OUTPUT
value|0
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_PCIE_ATTENTION_LED
value|1
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_PCIE_POWER_LED
value|2
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_TX_FRAME
value|3
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_RX_CLEAR_EXTERNAL
value|4
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_MAC_NETWORK_LED
value|5
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_MAC_POWER_LED
value|6
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_MCI_WLAN_DATA
value|0x16
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_MCI_WLAN_CLK
value|0x17
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_MCI_BT_DATA
value|0x18
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_MCI_BT_CLK
value|0x19
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_WL_IN_TX
value|0x14
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_WL_IN_RX
value|0x13
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_BT_IN_TX
value|9
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_BT_IN_RX
value|8
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_RUCKUS_STROBE
value|0x1d
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_RUCKUS_DATA
value|0x1e
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_SMARTANT_CTRL0
value|0x1d
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_SMARTANT_CTRL1
value|0x1e
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_SMARTANT_CTRL2
value|0x1b
end_define

begin_comment
comment|/* The above three seems to be functional values for peacock chip. For some  * reason these are continued for different boards as simple place holders.  * Now continuing to use these and adding the extra definitions for Scropion  */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX_AS_SWCOM3
value|0x26
end_define

begin_define
define|#
directive|define
name|AR_ENABLE_SMARTANTENNA
value|0x00000001
end_define

begin_comment
comment|/* Host GPIO Input State */
end_comment

begin_comment
comment|/* Host Spare */
end_comment

begin_comment
comment|/* Host PCIE Core Reset Enable */
end_comment

begin_comment
comment|/* Host CLKRUN */
end_comment

begin_comment
comment|/* Host EEPROM Status */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_VAL
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_VAL_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_BUSY
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_BUSY_ACCESS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_PROT_ACCESS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_ABSENT_ACCESS
value|0x00080000
end_define

begin_comment
comment|/* Host Observation Control */
end_comment

begin_comment
comment|/* Host RF Silent */
end_comment

begin_comment
comment|/* Host GPIO PDPU */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_PDPU_OPTION
value|0x03
end_define

begin_define
define|#
directive|define
name|AR_GPIO_PULL_DOWN
value|0x02
end_define

begin_comment
comment|/* Host GPIO Drive Strength */
end_comment

begin_comment
comment|/* Host Miscellaneous */
end_comment

begin_comment
comment|/* Host PCIE MSI Control Register */
end_comment

begin_define
define|#
directive|define
name|AR_PCIE_MSI_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PCIE_MSI_HW_DBI_WR_EN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_PCIE_MSI_HW_INT_PENDING_ADDR
value|0xFFA0C1FF
end_define

begin_comment
comment|// bits 8..11: value must be 0x5060
end_comment

begin_define
define|#
directive|define
name|AR_PCIE_MSI_HW_INT_PENDING_ADDR_MSI_64
value|0xFFA0C9FF
end_define

begin_comment
comment|// bits 8..11: value must be 0x5064
end_comment

begin_define
define|#
directive|define
name|AR_INTR_PRIO_TX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_INTR_PRIO_RXLP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_INTR_PRIO_RXHP
value|0x00000004
end_define

begin_comment
comment|/* OTP Interface Register */
end_comment

begin_define
define|#
directive|define
name|AR_ENT_OTP
value|AR9300_HOSTIF_OFFSET(HOST_INTF_OTP)
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_DUAL_BAND_DISABLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_CHAIN2_DISABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_5MHZ_DISABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_10MHZ_DISABLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_49GHZ_DISABLE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_LOOPBACK_DISABLE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_TPC_PERF_DISABLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_MIN_PKT_SIZE_DISABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR_ENT_OTP_SPECTRAL_PRECISION
value|0x03000000
end_define

begin_comment
comment|/* OTP EFUSE registers */
end_comment

begin_define
define|#
directive|define
name|AR_OTP_EFUSE_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct efuse_reg_WLAN, _x)
end_define

begin_define
define|#
directive|define
name|AR_OTP_EFUSE_INTF0
value|AR_OTP_EFUSE_OFFSET(OTP_INTF0)
end_define

begin_define
define|#
directive|define
name|AR_OTP_EFUSE_INTF5
value|AR_OTP_EFUSE_OFFSET(OTP_INTF5)
end_define

begin_define
define|#
directive|define
name|AR_OTP_EFUSE_PGENB_SETUP_HOLD_TIME
value|AR_OTP_EFUSE_OFFSET(OTP_PGENB_SETUP_HOLD_TIME)
end_define

begin_define
define|#
directive|define
name|AR_OTP_EFUSE_MEM
value|AR_OTP_EFUSE_OFFSET(OTP_MEM)
end_define

begin_comment
comment|/******************************************************************************  * RTC Register Map ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AR_RTC_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct rtc_reg, _x)
end_define

begin_comment
comment|/* Reset Control */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_RC
value|AR_RTC_OFFSET(RESET_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_RTC_RC_M
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_RTC_RC_MAC_WARM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_RTC_RC_MAC_COLD
value|0x00000002
end_define

begin_comment
comment|/* Crystal Control */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_XTAL_CONTROL
value|AR_RTC_OFFSET(XTAL_CONTROL)
end_define

begin_comment
comment|/* Reg Control 0 */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_REG_CONTROL0
value|AR_RTC_OFFSET(REG_CONTROL0)
end_define

begin_comment
comment|/* Reg Control 1 */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_REG_CONTROL1
value|AR_RTC_OFFSET(REG_CONTROL1)
end_define

begin_define
define|#
directive|define
name|AR_RTC_REG_CONTROL1_SWREG_PROGRAM
value|0x00000001
end_define

begin_comment
comment|/* TCXO Detect */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_TCXO_DETECT
value|AR_RTC_OFFSET(TCXO_DETECT)
end_define

begin_comment
comment|/* Crystal Test */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_XTAL_TEST
value|AR_RTC_OFFSET(XTAL_TEST)
end_define

begin_comment
comment|/* Sets the ADC/DAC clock quadrature */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_QUADRATURE
value|AR_RTC_OFFSET(QUADRATURE)
end_define

begin_comment
comment|/* PLL Control */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_PLL_CONTROL
value|AR_RTC_OFFSET(PLL_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_DIV
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_DIV_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_REFDIV
value|0x00003C00
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_REFDIV_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_CLKSEL
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_CLKSEL_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_BYPASS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_BYPASS_S
value|16
end_define

begin_comment
comment|/* PLL Control 2: for Hornet */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_PLL_CONTROL2
value|AR_RTC_OFFSET(PLL_CONTROL2)
end_define

begin_comment
comment|/* PLL Settle */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_PLL_SETTLE
value|AR_RTC_OFFSET(PLL_SETTLE)
end_define

begin_comment
comment|/* Crystal Settle */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_XTAL_SETTLE
value|AR_RTC_OFFSET(XTAL_SETTLE)
end_define

begin_comment
comment|/* Controls CLK_OUT pin clock speed */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_CLOCK_OUT
value|AR_RTC_OFFSET(CLOCK_OUT)
end_define

begin_comment
comment|/* Forces bias block on at all times */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_BIAS_OVERRIDE
value|AR_RTC_OFFSET(BIAS_OVERRIDE)
end_define

begin_comment
comment|/* System Sleep status bits */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_SYSTEM_SLEEP
value|AR_RTC_OFFSET(SYSTEM_SLEEP)
end_define

begin_comment
comment|/* Controls sleep options for MAC */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_MAC_SLEEP_CONTROL
value|AR_RTC_OFFSET(MAC_SLEEP_CONTROL)
end_define

begin_comment
comment|/* Keep Awake Timer */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_KEEP_AWAKE
value|AR_RTC_OFFSET(KEEP_AWAKE)
end_define

begin_comment
comment|/* Create a 32kHz clock derived from HF */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_DERIVED_RTC_CLK
value|AR_RTC_OFFSET(DERIVED_RTC_CLK)
end_define

begin_comment
comment|/******************************************************************************  * RTC SYNC Register Map ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AR_RTC_SYNC_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct rtc_sync_reg, _x)
end_define

begin_comment
comment|/* reset RTC */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_RESET
value|AR_RTC_SYNC_OFFSET(RTC_SYNC_RESET)
end_define

begin_define
define|#
directive|define
name|AR_RTC_RESET_EN
value|0x00000001
end_define

begin_comment
comment|/* Reset RTC bit */
end_comment

begin_comment
comment|/* system sleep status */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_STATUS
value|AR_RTC_SYNC_OFFSET(RTC_SYNC_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_M
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_SHUTDOWN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_SLEEP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_WAKEUP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_SLEEP_ACCESS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_PLL_CHANGING
value|0x00000020
end_define

begin_comment
comment|/* RTC Derived Register */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_SLEEP_CLK
value|AR_RTC_SYNC_OFFSET(RTC_SYNC_DERIVED)
end_define

begin_define
define|#
directive|define
name|AR_RTC_FORCE_DERIVED_CLK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_RTC_FORCE_SWREG_PRD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_RTC_PCIE_RST_PWDN_EN
value|0x00000008
end_define

begin_comment
comment|/* RTC Force Wake Register */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_FORCE_WAKE
value|AR_RTC_SYNC_OFFSET(RTC_SYNC_FORCE_WAKE)
end_define

begin_define
define|#
directive|define
name|AR_RTC_FORCE_WAKE_EN
value|0x00000001
end_define

begin_comment
comment|/* enable force wake */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_FORCE_WAKE_ON_INT
value|0x00000002
end_define

begin_comment
comment|/* auto-wake on MAC interrupt */
end_comment

begin_comment
comment|/* RTC interrupt cause/clear */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_INTR_CAUSE
value|AR_RTC_SYNC_OFFSET(RTC_SYNC_INTR_CAUSE)
end_define

begin_comment
comment|/* RTC interrupt enable */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_INTR_ENABLE
value|AR_RTC_SYNC_OFFSET(RTC_SYNC_INTR_ENABLE)
end_define

begin_comment
comment|/* RTC interrupt mask */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_INTR_MASK
value|AR_RTC_SYNC_OFFSET(RTC_SYNC_INTR_MASK)
end_define

begin_comment
comment|/******************************************************************************  * Analog Interface Register Map ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AR_AN_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct analog_intf_reg_csr, _x)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|// AR9280: rf long shift registers
end_comment

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0
value|0x7810
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_OB
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_OB_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_DB
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_DB_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0
value|0x7818
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_OB5
value|0x00070000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_OB5_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_DB5
value|0x00380000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_DB5_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1
value|0x7834
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_OB
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_OB_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_DB
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_DB_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1
value|0x783C
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_OB5
value|0x00070000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_OB5_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_DB5
value|0x00380000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_DB5_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2
value|0x7894
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_XPABIAS_LVL
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_XPABIAS_LVL_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_LOCALBIAS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_LOCALBIAS_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_PWDCLKIND
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_PWDCLKIND_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_AN_SYNTH9
value|0x7868
end_define

begin_define
define|#
directive|define
name|AR_AN_SYNTH9_REFDIVA
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|AR_AN_SYNTH9_REFDIVA_S
value|27
end_define

begin_comment
comment|// AR9285 Analog registers
end_comment

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1
value|0x7820
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2
value|0x7824
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3
value|0x7828
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0_S
value|21
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1
value|0x001C0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1_S
value|18
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2
value|0x00038000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2_S
value|15
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3
value|0x00007000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4
value|0x00000E00
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4_S
value|9
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0
value|0x000001C0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0_S
value|6
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1
value|0x00000038
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1_S
value|3
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4
value|0x782C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3_S
value|29
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4_S
value|26
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2_S
value|17
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3
value|0x0001C000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4
value|0x00003800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6
value|0x7834
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7
value|0x7838
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G9
value|0x7840
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1
value|0x7854
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP2
value|0x7868
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3
value|0x786c
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_XPABIAS_LVL
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_XPABIAS_LVL_S
value|2
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP4
value|0x7870
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP4_DEFAULT
value|0x10142c00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************************************************************  * MAC PCU Register Map ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AR_MAC_PCU_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct mac_pcu_reg, _x)
end_define

begin_comment
comment|/* MAC station ID0 - low 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID0
value|AR_MAC_PCU_OFFSET(MAC_PCU_STA_ADDR_L32)
end_define

begin_comment
comment|/* MAC station ID1 - upper 16 bits */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1
value|AR_MAC_PCU_OFFSET(MAC_PCU_STA_ADDR_U16)
end_define

begin_define
define|#
directive|define
name|AR_STA_ID1_SADH_MASK
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for 16 msb of MAC addr
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_STA_AP
value|0x00010000
end_define

begin_comment
comment|// Device is AP
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_ADHOC
value|0x00020000
end_define

begin_comment
comment|// Device is ad-hoc
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PWR_SAV
value|0x00040000
end_define

begin_comment
comment|// Power save in generated frames
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_KSRCHDIS
value|0x00080000
end_define

begin_comment
comment|// Key search disable
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PCF
value|0x00100000
end_define

begin_comment
comment|// Observe PCF
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_USE_DEFANT
value|0x00200000
end_define

begin_comment
comment|// Use default antenna
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_DEFANT_UPDATE
value|0x00400000
end_define

begin_comment
comment|// Update default ant w/TX antenna
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_RTS_USE_DEF
value|0x00800000
end_define

begin_comment
comment|// Use default antenna to send RTS
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_ACKCTS_6MB
value|0x01000000
end_define

begin_comment
comment|// Use 6Mb/s rate for ACK& CTS
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_BASE_RATE_11B
value|0x02000000
end_define

begin_comment
comment|// Use 11b base rate for ACK& CTS
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_SECTOR_SELF_GEN
value|0x04000000
end_define

begin_comment
comment|// default ant for generated frames
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_CRPT_MIC_ENABLE
value|0x08000000
end_define

begin_comment
comment|// Enable Michael
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_KSRCH_MODE
value|0x10000000
end_define

begin_comment
comment|// Look-up unique key when !keyID
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PRESERVE_SEQNUM
value|0x20000000
end_define

begin_comment
comment|// Don't replace seq num
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_CBCIV_ENDIAN
value|0x40000000
end_define

begin_comment
comment|// IV endian-ness in CBC nonce
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_MCAST_KSRCH
value|0x80000000
end_define

begin_comment
comment|// Adhoc key search enable
end_comment

begin_comment
comment|/* MAC BSSID low 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID0
value|AR_MAC_PCU_OFFSET(MAC_PCU_BSSID_L32)
end_define

begin_comment
comment|/* MAC BSSID upper 16 bits / AID */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1
value|AR_MAC_PCU_OFFSET(MAC_PCU_BSSID_U16)
end_define

begin_define
define|#
directive|define
name|AR_BSS_ID1_U16
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for upper 16 bits of BSSID
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1_AID
value|0x07FF0000
end_define

begin_comment
comment|// Mask for association ID
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1_AID_S
value|16
end_define

begin_comment
comment|// Shift for association ID
end_comment

begin_comment
comment|/*  * Added to support dual BSSID/TSF which are needed in the application  * of Mesh networking. See bug 35189. Note that the only function added  * with this BSSID2 is to receive multi/broadcast from BSSID2 as well  */
end_comment

begin_comment
comment|/* MAC BSSID low 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_BSS2_ID0
value|AR_MAC_PCU_OFFSET(MAC_PCU_BSSID2_L32)
end_define

begin_comment
comment|/* MAC BSSID upper 16 bits / AID */
end_comment

begin_define
define|#
directive|define
name|AR_BSS2_ID1
value|AR_MAC_PCU_OFFSET(MAC_PCU_BSSID2_U16)
end_define

begin_comment
comment|/* MAC Beacon average RSSI  *  * This register holds the average RSSI with 1/16 dB resolution.  * The RSSI is averaged over multiple beacons which matched our BSSID.  * Note that AVE_VALUE is 12 bits with 4 bits below the normal 8 bits.  * These lowest 4 bits provide for a resolution of 1/16 dB.  *  */
end_comment

begin_define
define|#
directive|define
name|AR_BCN_RSSI_AVE
value|AR_MAC_PCU_OFFSET(MAC_PCU_BCN_RSSI_AVE)
end_define

begin_define
define|#
directive|define
name|AR_BCN_RSSI_AVE_VAL
value|0x00000FFF
end_define

begin_comment
comment|// Beacon RSSI value
end_comment

begin_define
define|#
directive|define
name|AR_BCN_RSSI_AVE_VAL_S
value|0
end_define

begin_comment
comment|/* MAC ACK& CTS time-out */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT
value|AR_MAC_PCU_OFFSET(MAC_PCU_ACK_CTS_TIMEOUT)
end_define

begin_define
define|#
directive|define
name|AR_TIME_OUT_ACK
value|0x00003FFF
end_define

begin_comment
comment|// Mask for ACK time-out
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT_ACK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TIME_OUT_CTS
value|0x3FFF0000
end_define

begin_comment
comment|// Mask for CTS time-out
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT_CTS_S
value|16
end_define

begin_comment
comment|/* beacon RSSI warning / bmiss threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR
value|AR_MAC_PCU_OFFSET(MAC_PCU_BCN_RSSI_CTL)
end_define

begin_define
define|#
directive|define
name|AR_RSSI_THR_VAL
value|0x000000FF
end_define

begin_comment
comment|// Beacon RSSI warning threshold
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR_VAL_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RSSI_THR_BM_THR
value|0x0000FF00
end_define

begin_comment
comment|// Mask for Missed beacon threshold
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR_BM_THR_S
value|8
end_define

begin_comment
comment|// Shift for Missed beacon threshold
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_BCN_WEIGHT
value|0x1F000000
end_define

begin_comment
comment|// RSSI average weight
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_BCN_WEIGHT_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_RSSI_BCN_RSSI_RST
value|0x20000000
end_define

begin_comment
comment|// Reset RSSI value
end_comment

begin_comment
comment|/* MAC transmit latency register */
end_comment

begin_define
define|#
directive|define
name|AR_USEC
value|AR_MAC_PCU_OFFSET(MAC_PCU_USEC_LATENCY)
end_define

begin_define
define|#
directive|define
name|AR_USEC_USEC
value|0x000000FF
end_define

begin_comment
comment|// Mask for clock cycles in 1 usec
end_comment

begin_define
define|#
directive|define
name|AR_USEC_USEC_S
value|0
end_define

begin_comment
comment|// Shift for clock cycles in 1 usec
end_comment

begin_define
define|#
directive|define
name|AR_USEC_TX_LAT
value|0x007FC000
end_define

begin_comment
comment|// tx latency to start of SIGNAL (usec)
end_comment

begin_define
define|#
directive|define
name|AR_USEC_TX_LAT_S
value|14
end_define

begin_comment
comment|// tx latency to start of SIGNAL (usec)
end_comment

begin_define
define|#
directive|define
name|AR_USEC_RX_LAT
value|0x1F800000
end_define

begin_comment
comment|// rx latency to start of SIGNAL (usec)
end_comment

begin_define
define|#
directive|define
name|AR_USEC_RX_LAT_S
value|23
end_define

begin_comment
comment|// rx latency to start of SIGNAL (usec)
end_comment

begin_define
define|#
directive|define
name|AR_SLOT_HALF
value|13
end_define

begin_define
define|#
directive|define
name|AR_SLOT_QUARTER
value|21
end_define

begin_define
define|#
directive|define
name|AR_USEC_RX_LATENCY
value|0x1f800000
end_define

begin_define
define|#
directive|define
name|AR_USEC_RX_LATENCY_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_RX_LATENCY_FULL
value|37
end_define

begin_define
define|#
directive|define
name|AR_RX_LATENCY_HALF
value|74
end_define

begin_define
define|#
directive|define
name|AR_RX_LATENCY_QUARTER
value|148
end_define

begin_define
define|#
directive|define
name|AR_RX_LATENCY_FULL_FAST_CLOCK
value|41
end_define

begin_define
define|#
directive|define
name|AR_RX_LATENCY_HALF_FAST_CLOCK
value|82
end_define

begin_define
define|#
directive|define
name|AR_RX_LATENCY_QUARTER_FAST_CLOCK
value|163
end_define

begin_define
define|#
directive|define
name|AR_USEC_TX_LATENCY
value|0x007fc000
end_define

begin_define
define|#
directive|define
name|AR_USEC_TX_LATENCY_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_TX_LATENCY_FULL
value|54
end_define

begin_define
define|#
directive|define
name|AR_TX_LATENCY_HALF
value|108
end_define

begin_define
define|#
directive|define
name|AR_TX_LATENCY_QUARTER
value|216
end_define

begin_define
define|#
directive|define
name|AR_TX_LATENCY_FULL_FAST_CLOCK
value|54
end_define

begin_define
define|#
directive|define
name|AR_TX_LATENCY_HALF_FAST_CLOCK
value|119
end_define

begin_define
define|#
directive|define
name|AR_TX_LATENCY_QUARTER_FAST_CLOCK
value|238
end_define

begin_define
define|#
directive|define
name|AR_USEC_HALF
value|19
end_define

begin_define
define|#
directive|define
name|AR_USEC_QUARTER
value|9
end_define

begin_define
define|#
directive|define
name|AR_USEC_HALF_FAST_CLOCK
value|21
end_define

begin_define
define|#
directive|define
name|AR_USEC_QUARTER_FAST_CLOCK
value|10
end_define

begin_define
define|#
directive|define
name|AR_EIFS_HALF
value|175
end_define

begin_define
define|#
directive|define
name|AR_EIFS_QUARTER
value|340
end_define

begin_define
define|#
directive|define
name|AR_RESET_TSF
value|AR_MAC_PCU_OFFSET(MAC_PCU_RESET_TSF)
end_define

begin_define
define|#
directive|define
name|AR_RESET_TSF_ONCE
value|0x01000000
end_define

begin_comment
comment|// reset tsf once ; self-clears bit
end_comment

begin_define
define|#
directive|define
name|AR_RESET_TSF2_ONCE
value|0x02000000
end_define

begin_comment
comment|// reset tsf2 once ; self-clears bit
end_comment

begin_comment
comment|/* MAC CFP Interval (TU/msec) */
end_comment

begin_define
define|#
directive|define
name|AR_CFP_PERIOD
value|0x8024
end_define

begin_comment
comment|/* MAC CFP Interval (TU/msec) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER0
value|0x8028
end_define

begin_comment
comment|/* MAC Next beacon time (TU/msec) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER1
value|0x802c
end_define

begin_comment
comment|/* MAC DMA beacon alert time (1/8 TU) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER2
value|0x8030
end_define

begin_comment
comment|/* MAC Software beacon alert (1/8 TU) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER3
value|0x8034
end_define

begin_comment
comment|/* MAC ATIM window time */
end_comment

begin_comment
comment|/* MAC maximum CFP duration */
end_comment

begin_define
define|#
directive|define
name|AR_MAX_CFP_DUR
value|AR_MAC_PCU_OFFSET(MAC_PCU_MAX_CFP_DUR)
end_define

begin_define
define|#
directive|define
name|AR_CFP_VAL
value|0x0000FFFF
end_define

begin_comment
comment|// CFP value in uS
end_comment

begin_comment
comment|/* MAC receive filter register */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER
value|AR_MAC_PCU_OFFSET(MAC_PCU_RX_FILTER)
end_define

begin_define
define|#
directive|define
name|AR_RX_FILTER_ALL
value|0x00000000
end_define

begin_comment
comment|// Disallow all frames
end_comment

begin_define
define|#
directive|define
name|AR_RX_UCAST
value|0x00000001
end_define

begin_comment
comment|// Allow unicast frames
end_comment

begin_define
define|#
directive|define
name|AR_RX_MCAST
value|0x00000002
end_define

begin_comment
comment|// Allow multicast frames
end_comment

begin_define
define|#
directive|define
name|AR_RX_BCAST
value|0x00000004
end_define

begin_comment
comment|// Allow broadcast frames
end_comment

begin_define
define|#
directive|define
name|AR_RX_CONTROL
value|0x00000008
end_define

begin_comment
comment|// Allow control frames
end_comment

begin_define
define|#
directive|define
name|AR_RX_BEACON
value|0x00000010
end_define

begin_comment
comment|// Allow beacon frames
end_comment

begin_define
define|#
directive|define
name|AR_RX_PROM
value|0x00000020
end_define

begin_comment
comment|// Promiscuous mode all packets
end_comment

begin_define
define|#
directive|define
name|AR_RX_PROBE_REQ
value|0x00000080
end_define

begin_comment
comment|// Any probe request frameA
end_comment

begin_define
define|#
directive|define
name|AR_RX_MY_BEACON
value|0x00000200
end_define

begin_comment
comment|// Any beacon frame with matching BSSID
end_comment

begin_define
define|#
directive|define
name|AR_RX_COMPR_BAR
value|0x00000400
end_define

begin_comment
comment|// Compressed directed block ack request
end_comment

begin_define
define|#
directive|define
name|AR_RX_COMPR_BA
value|0x00000800
end_define

begin_comment
comment|// Compressed directed block ack
end_comment

begin_define
define|#
directive|define
name|AR_RX_UNCOM_BA_BAR
value|0x00001000
end_define

begin_comment
comment|// Uncompressed directed BA or BAR
end_comment

begin_define
define|#
directive|define
name|AR_RX_HWBCNPROC_EN
value|0x00020000
end_define

begin_comment
comment|// Enable hw beacon processing (see AR_HWBCNPROC1)
end_comment

begin_define
define|#
directive|define
name|AR_RX_CONTROL_WRAPPER
value|0x00080000
end_define

begin_comment
comment|// Control wrapper. Jupiter only.
end_comment

begin_define
define|#
directive|define
name|AR_RX_4ADDRESS
value|0x00100000
end_define

begin_comment
comment|// 4-Address frames
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERROR_MASK_CONT)
end_define

begin_comment
comment|/* MAC multicast filter lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_MCAST_FIL0
value|AR_MAC_PCU_OFFSET(MAC_PCU_MCAST_FILTER_L32)
end_define

begin_comment
comment|/* MAC multicast filter upper 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_MCAST_FIL1
value|AR_MAC_PCU_OFFSET(MAC_PCU_MCAST_FILTER_U32)
end_define

begin_comment
comment|/* MAC PCU diagnostic switches */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW
value|AR_MAC_PCU_OFFSET(MAC_PCU_DIAG_SW)
end_define

begin_define
define|#
directive|define
name|AR_DIAG_CACHE_ACK
value|0x00000001
end_define

begin_comment
comment|// disable ACK when no valid key
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_ACK_DIS
value|0x00000002
end_define

begin_comment
comment|// disable ACK generation
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_CTS_DIS
value|0x00000004
end_define

begin_comment
comment|// disable CTS generation
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_ENCRYPT_DIS
value|0x00000008
end_define

begin_comment
comment|// disable encryption
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_DECRYPT_DIS
value|0x00000010
end_define

begin_comment
comment|// disable decryption
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_RX_DIS
value|0x00000020
end_define

begin_comment
comment|// disable receive
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_LOOP_BACK
value|0x00000040
end_define

begin_comment
comment|// enable loopback
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_CORR_FCS
value|0x00000080
end_define

begin_comment
comment|// corrupt FCS
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_CHAN_INFO
value|0x00000100
end_define

begin_comment
comment|// dump channel info
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_FRAME_NV0
value|0x00020000
end_define

begin_comment
comment|// accept w/protocol version !0
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_OBS_PT_SEL1
value|0x000C0000
end_define

begin_comment
comment|// observation point select
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_OBS_PT_SEL1_S
value|18
end_define

begin_comment
comment|// Shift for observation point select
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_FORCE_RX_CLEAR
value|0x00100000
end_define

begin_comment
comment|// force rx_clear high
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_IGNORE_VIRT_CS
value|0x00200000
end_define

begin_comment
comment|// ignore virtual carrier sense
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_FORCE_CH_IDLE_HIGH
value|0x00400000
end_define

begin_comment
comment|// force channel idle high
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_EIFS_CTRL_ENA
value|0x00800000
end_define

begin_comment
comment|// use framed and ~wait_wep if 0
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_DUAL_CHAIN_INFO
value|0x01000000
end_define

begin_comment
comment|// dual chain channel info
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_RX_ABORT
value|0x02000000
end_define

begin_comment
comment|//  abort rx
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SATURATE_CYCLE_CNT
value|0x04000000
end_define

begin_comment
comment|// saturate cycle cnts (no shift)
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_OBS_PT_SEL2
value|0x08000000
end_define

begin_comment
comment|// Mask for observation point sel
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_OBS_PT_SEL2_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_DIAG_RX_CLEAR_CTL_LOW
value|0x10000000
end_define

begin_comment
comment|// force rx_clear (ctl) low (i.e. busy)
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_RX_CLEAR_EXT_LOW
value|0x20000000
end_define

begin_comment
comment|// force rx_clear (ext) low (i.e. busy)
end_comment

begin_comment
comment|/* MAC local clock lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TSF_L32
value|AR_MAC_PCU_OFFSET(MAC_PCU_TSF_L32)
end_define

begin_comment
comment|/* MAC local clock upper 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TSF_U32
value|AR_MAC_PCU_OFFSET(MAC_PCU_TSF_U32)
end_define

begin_comment
comment|/*  * Secondary TSF support added for dual BSSID/TSF  * which is needed in the application of DirectConnect or  * Mesh networking  */
end_comment

begin_comment
comment|/* MAC local clock lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TSF2_L32
value|AR_MAC_PCU_OFFSET(MAC_PCU_TSF2_L32)
end_define

begin_comment
comment|/* MAC local clock upper 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TSF2_U32
value|AR_MAC_PCU_OFFSET(MAC_PCU_TSF2_U32)
end_define

begin_comment
comment|/* ADDAC test register */
end_comment

begin_define
define|#
directive|define
name|AR_TST_ADDAC
value|AR_MAC_PCU_OFFSET(MAC_PCU_TST_ADDAC)
end_define

begin_define
define|#
directive|define
name|AR_TST_ADDAC_TST_MODE
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_TST_ADDAC_TST_MODE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TST_ADDAC_TST_LOOP_ENA
value|0x2
end_define

begin_define
define|#
directive|define
name|AR_TST_ADDAC_TST_LOOP_ENA_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_TST_ADDAC_BEGIN_CAPTURE
value|0x80000
end_define

begin_define
define|#
directive|define
name|AR_TST_ADDAC_BEGIN_CAPTURE_S
value|19
end_define

begin_comment
comment|/* default antenna register */
end_comment

begin_define
define|#
directive|define
name|AR_DEF_ANTENNA
value|AR_MAC_PCU_OFFSET(MAC_PCU_DEF_ANTENNA)
end_define

begin_comment
comment|/* MAC AES mute mask */
end_comment

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK0
value|AR_MAC_PCU_OFFSET(MAC_PCU_AES_MUTE_MASK_0)
end_define

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK0_FC
value|0x0000FFFF
end_define

begin_comment
comment|// frame ctrl mask bits
end_comment

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK0_QOS
value|0xFFFF0000
end_define

begin_comment
comment|// qos ctrl mask bits
end_comment

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK0_QOS_S
value|16
end_define

begin_comment
comment|/* MAC AES mute mask 1 */
end_comment

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK1
value|AR_MAC_PCU_OFFSET(MAC_PCU_AES_MUTE_MASK_1)
end_define

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK1_SEQ
value|0x0000FFFF
end_define

begin_comment
comment|// seq + frag mask bits
end_comment

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK1_FC_MGMT
value|0xFFFF0000
end_define

begin_comment
comment|// frame ctrl mask for mgmt frames (Sowl)
end_comment

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK1_FC_MGMT_S
value|16
end_define

begin_comment
comment|/* control clock domain */
end_comment

begin_define
define|#
directive|define
name|AR_GATED_CLKS
value|AR_MAC_PCU_OFFSET(MAC_PCU_GATED_CLKS)
end_define

begin_define
define|#
directive|define
name|AR_GATED_CLKS_TX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_GATED_CLKS_RX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_GATED_CLKS_REG
value|0x00000008
end_define

begin_comment
comment|/* MAC PCU observation bus 2 */
end_comment

begin_define
define|#
directive|define
name|AR_OBS_BUS_CTRL
value|AR_MAC_PCU_OFFSET(MAC_PCU_OBS_BUS_2)
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_SEL_1
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_SEL_2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_SEL_3
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_SEL_4
value|0x08040000
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_SEL_5
value|0x08080000
end_define

begin_comment
comment|/* MAC PCU observation bus 1 */
end_comment

begin_define
define|#
directive|define
name|AR_OBS_BUS_1
value|AR_MAC_PCU_OFFSET(MAC_PCU_OBS_BUS_1)
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_PCU
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_END
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_WEP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_BEACON
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_FILTER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_TX_HCF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_QUIET_TIME
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_CHAN_IDLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_TX_HOLD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_TX_FRAME
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_FRAME
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_CLEAR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_WEP_STATE
value|0x0003F000
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_WEP_STATE_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_STATE
value|0x01F00000
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_RX_STATE_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_TX_STATE
value|0x7E000000
end_define

begin_define
define|#
directive|define
name|AR_OBS_BUS_1_TX_STATE_S
value|25
end_define

begin_comment
comment|/* MAC PCU dynamic MIMO power save */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_SMPS
value|AR_MAC_PCU_OFFSET(MAC_PCU_DYM_MIMO_PWR_SAVE)
end_define

begin_define
define|#
directive|define
name|AR_PCU_SMPS_MAC_CHAINMASK
value|0x00000001
end_define

begin_comment
comment|// Use the Rx Chainmask of MAC's setting
end_comment

begin_define
define|#
directive|define
name|AR_PCU_SMPS_HW_CTRL_EN
value|0x00000002
end_define

begin_comment
comment|// Enable hardware control of dynamic MIMO PS
end_comment

begin_define
define|#
directive|define
name|AR_PCU_SMPS_SW_CTRL_HPWR
value|0x00000004
end_define

begin_comment
comment|// Software controlled High power chainmask setting
end_comment

begin_define
define|#
directive|define
name|AR_PCU_SMPS_LPWR_CHNMSK
value|0x00000070
end_define

begin_comment
comment|// Low power setting of Rx Chainmask
end_comment

begin_define
define|#
directive|define
name|AR_PCU_SMPS_LPWR_CHNMSK_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PCU_SMPS_HPWR_CHNMSK
value|0x00000700
end_define

begin_comment
comment|// High power setting of Rx Chainmask
end_comment

begin_define
define|#
directive|define
name|AR_PCU_SMPS_HPWR_CHNMSK_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PCU_SMPS_LPWR_CHNMSK_VAL
value|0x1
end_define

begin_comment
comment|/* MAC PCU frame start time trigger for the AP's Downlink Traffic in TDMA mode */
end_comment

begin_define
define|#
directive|define
name|AR_TDMA_TXSTARTTRIG_LSB
value|AR_MAC_PCU_OFFSET(MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB)
end_define

begin_define
define|#
directive|define
name|AR_TDMA_TXSTARTTRIG_MSB
value|AR_MAC_PCU_OFFSET(MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB)
end_define

begin_comment
comment|/* MAC Time stamp of the last beacon received */
end_comment

begin_define
define|#
directive|define
name|AR_LAST_TSTP
value|AR_MAC_PCU_OFFSET(MAC_PCU_LAST_BEACON_TSF)
end_define

begin_comment
comment|/* MAC current NAV value */
end_comment

begin_define
define|#
directive|define
name|AR_NAV
value|AR_MAC_PCU_OFFSET(MAC_PCU_NAV)
end_define

begin_comment
comment|/* MAC RTS exchange success counter */
end_comment

begin_define
define|#
directive|define
name|AR_RTS_OK
value|AR_MAC_PCU_OFFSET(MAC_PCU_RTS_SUCCESS_CNT)
end_define

begin_comment
comment|/* MAC RTS exchange failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_RTS_FAIL
value|AR_MAC_PCU_OFFSET(MAC_PCU_RTS_FAIL_CNT)
end_define

begin_comment
comment|/* MAC ACK failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_ACK_FAIL
value|AR_MAC_PCU_OFFSET(MAC_PCU_ACK_FAIL_CNT)
end_define

begin_comment
comment|/* MAC FCS check failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_FCS_FAIL
value|AR_MAC_PCU_OFFSET(MAC_PCU_FCS_FAIL_CNT)
end_define

begin_comment
comment|/* MAC Valid beacon value */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_CNT
value|AR_MAC_PCU_OFFSET(MAC_PCU_BEACON_CNT)
end_define

begin_comment
comment|/* MAC PCU tdma slot alert control */
end_comment

begin_define
define|#
directive|define
name|AR_TDMA_SLOT_ALERT_CNTL
value|AR_MAC_PCU_OFFSET(MAC_PCU_TDMA_SLOT_ALERT_CNTL)
end_define

begin_comment
comment|/* MAC PCU Basic MCS set for MCS 0 to 31 */
end_comment

begin_define
define|#
directive|define
name|AR_BASIC_SET
value|AR_MAC_PCU_OFFSET(MAC_PCU_BASIC_SET)
end_define

begin_define
define|#
directive|define
name|ALL_RATE
value|0xff
end_define

begin_comment
comment|/* MAC_PCU_ _SEQ */
end_comment

begin_define
define|#
directive|define
name|AR_MGMT_SEQ
value|AR_MAC_PCU_OFFSET(MAC_PCU_MGMT_SEQ)
end_define

begin_define
define|#
directive|define
name|AR_MGMT_SEQ_MIN
value|0xFFF
end_define

begin_comment
comment|/* sequence minimum value*/
end_comment

begin_define
define|#
directive|define
name|AR_MGMT_SEQ_MIN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MIN_HW_SEQ
value|0
end_define

begin_define
define|#
directive|define
name|AR_MGMT_SEQ_MAX
value|0xFFF0000
end_define

begin_comment
comment|/* sequence maximum value*/
end_comment

begin_define
define|#
directive|define
name|AR_MGMT_SEQ_MAX_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_MAX_HW_SEQ
value|0xFF
end_define

begin_comment
comment|/*MAC PCU Key Cache Antenna 1 */
end_comment

begin_define
define|#
directive|define
name|AR_TX_ANT_1
value|AR_MAC_PCU_OFFSET(MAC_PCU_TX_ANT_1)
end_define

begin_comment
comment|/*MAC PCU Key Cache Antenna 2 */
end_comment

begin_define
define|#
directive|define
name|AR_TX_ANT_2
value|AR_MAC_PCU_OFFSET(MAC_PCU_TX_ANT_2)
end_define

begin_comment
comment|/*MAC PCU Key Cache Antenna 3 */
end_comment

begin_define
define|#
directive|define
name|AR_TX_ANT_3
value|AR_MAC_PCU_OFFSET(MAC_PCU_TX_ANT_3)
end_define

begin_comment
comment|/*MAC PCU Key Cache Antenna 4 */
end_comment

begin_define
define|#
directive|define
name|AR_TX_ANT_4
value|AR_MAC_PCU_OFFSET(MAC_PCU_TX_ANT_4)
end_define

begin_comment
comment|/* Extended range mode */
end_comment

begin_define
define|#
directive|define
name|AR_XRMODE
value|AR_MAC_PCU_OFFSET(MAC_PCU_XRMODE)
end_define

begin_comment
comment|/* Extended range mode delay */
end_comment

begin_define
define|#
directive|define
name|AR_XRDEL
value|AR_MAC_PCU_OFFSET(MAC_PCU_XRDEL)
end_define

begin_comment
comment|/* Extended range mode timeout */
end_comment

begin_define
define|#
directive|define
name|AR_XRTO
value|AR_MAC_PCU_OFFSET(MAC_PCU_XRTO)
end_define

begin_comment
comment|/* Extended range mode chirp */
end_comment

begin_define
define|#
directive|define
name|AR_XRCRP
value|AR_MAC_PCU_OFFSET(MAC_PCU_XRCRP)
end_define

begin_comment
comment|/* Extended range stomp */
end_comment

begin_define
define|#
directive|define
name|AR_XRSTMP
value|AR_MAC_PCU_OFFSET(MAC_PCU_XRSTMP)
end_define

begin_comment
comment|/* Enhanced sleep control 1 */
end_comment

begin_define
define|#
directive|define
name|AR_SLEEP1
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP1)
end_define

begin_define
define|#
directive|define
name|AR_SLEEP1_ASSUME_DTIM
value|0x00080000
end_define

begin_comment
comment|// Assume DTIM on missed beacon
end_comment

begin_define
define|#
directive|define
name|AR_SLEEP1_CAB_TIMEOUT
value|0xFFE00000
end_define

begin_comment
comment|// Cab timeout(TU) mask
end_comment

begin_define
define|#
directive|define
name|AR_SLEEP1_CAB_TIMEOUT_S
value|21
end_define

begin_comment
comment|// Cab timeout(TU) shift
end_comment

begin_comment
comment|/* Enhanced sleep control 2 */
end_comment

begin_define
define|#
directive|define
name|AR_SLEEP2
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP2)
end_define

begin_define
define|#
directive|define
name|AR_SLEEP2_BEACON_TIMEOUT
value|0xFFE00000
end_define

begin_comment
comment|// Beacon timeout(TU) mask
end_comment

begin_define
define|#
directive|define
name|AR_SLEEP2_BEACON_TIMEOUT_S
value|21
end_define

begin_comment
comment|// Beacon timeout(TU) shift
end_comment

begin_comment
comment|/*MAC_PCU_SELF_GEN_DEFAULT*/
end_comment

begin_define
define|#
directive|define
name|AR_SELFGEN
value|AR_MAC_PCU_OFFSET(MAC_PCU_SELF_GEN_DEFAULT)
end_define

begin_define
define|#
directive|define
name|AR_MMSS
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR_MMSS_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_NO
value|RESTRICTION  0
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_ONEOVER4_us
value|1
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_ONEOVER2_us
value|2
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_ONE_us
value|3
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_TWO_us
value|4
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_FOUR_us
value|5
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_EIGHT_us
value|6
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_MMSS_SIXTEEN_us
value|7
end_define

begin_define
define|#
directive|define
name|AR_CEC
value|0x00000018
end_define

begin_define
define|#
directive|define
name|AR_CEC_S
value|3
end_define

begin_comment
comment|/* Although in original standard 0 is for 1 stream and 1 is for 2 stream */
end_comment

begin_comment
comment|/*  due to H/W resaon, Here should set 1 for 1 stream and 2 for 2 stream */
end_comment

begin_define
define|#
directive|define
name|AR_SELFGEN_CEC_ONE_SPACETIMESTREAM
value|1
end_define

begin_define
define|#
directive|define
name|AR_SELFGEN_CEC_TWO_SPACETIMESTREAM
value|2
end_define

begin_comment
comment|/* BSSID mask lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_BSSMSKL
value|AR_MAC_PCU_OFFSET(MAC_PCU_ADDR1_MASK_L32)
end_define

begin_comment
comment|/* BSSID mask upper 16 bits */
end_comment

begin_define
define|#
directive|define
name|AR_BSSMSKU
value|AR_MAC_PCU_OFFSET(MAC_PCU_ADDR1_MASK_U16)
end_define

begin_comment
comment|/* Transmit power control for gen frames */
end_comment

begin_define
define|#
directive|define
name|AR_TPC
value|AR_MAC_PCU_OFFSET(MAC_PCU_TPC)
end_define

begin_define
define|#
directive|define
name|AR_TPC_ACK
value|0x0000003f
end_define

begin_comment
comment|// ack frames mask
end_comment

begin_define
define|#
directive|define
name|AR_TPC_ACK_S
value|0x00
end_define

begin_comment
comment|// ack frames shift
end_comment

begin_define
define|#
directive|define
name|AR_TPC_CTS
value|0x00003f00
end_define

begin_comment
comment|// cts frames mask
end_comment

begin_define
define|#
directive|define
name|AR_TPC_CTS_S
value|0x08
end_define

begin_comment
comment|// cts frames shift
end_comment

begin_define
define|#
directive|define
name|AR_TPC_CHIRP
value|0x003f0000
end_define

begin_comment
comment|// chirp frames mask
end_comment

begin_define
define|#
directive|define
name|AR_TPC_CHIRP_S
value|16
end_define

begin_comment
comment|// chirp frames shift
end_comment

begin_define
define|#
directive|define
name|AR_TPC_RPT
value|0x3f000000
end_define

begin_comment
comment|// rpt frames mask
end_comment

begin_define
define|#
directive|define
name|AR_TPC_RPT_S
value|24
end_define

begin_comment
comment|// rpt frames shift
end_comment

begin_comment
comment|/* Profile count transmit frames */
end_comment

begin_define
define|#
directive|define
name|AR_TFCNT
value|AR_MAC_PCU_OFFSET(MAC_PCU_TX_FRAME_CNT)
end_define

begin_comment
comment|/* Profile count receive frames */
end_comment

begin_define
define|#
directive|define
name|AR_RFCNT
value|AR_MAC_PCU_OFFSET(MAC_PCU_RX_FRAME_CNT)
end_define

begin_comment
comment|/* Profile count receive clear */
end_comment

begin_define
define|#
directive|define
name|AR_RCCNT
value|AR_MAC_PCU_OFFSET(MAC_PCU_RX_CLEAR_CNT)
end_define

begin_comment
comment|/* Profile count cycle counter */
end_comment

begin_define
define|#
directive|define
name|AR_CCCNT
value|AR_MAC_PCU_OFFSET(MAC_PCU_CYCLE_CNT)
end_define

begin_comment
comment|/* Quiet time programming for TGh */
end_comment

begin_define
define|#
directive|define
name|AR_QUIET1
value|AR_MAC_PCU_OFFSET(MAC_PCU_QUIET_TIME_1)
end_define

begin_define
define|#
directive|define
name|AR_QUIET1_NEXT_QUIET_S
value|0
end_define

begin_comment
comment|// TSF of next quiet period (TU)
end_comment

begin_define
define|#
directive|define
name|AR_QUIET1_NEXT_QUIET_M
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR_QUIET1_QUIET_ENABLE
value|0x00010000
end_define

begin_comment
comment|// Enable Quiet time operation
end_comment

begin_define
define|#
directive|define
name|AR_QUIET1_QUIET_ACK_CTS_ENABLE
value|0x00020000
end_define

begin_comment
comment|// ack/cts in quiet period
end_comment

begin_define
define|#
directive|define
name|AR_QUIET1_QUIET_ACK_CTS_ENABLE_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_QUIET2
value|AR_MAC_PCU_OFFSET(MAC_PCU_QUIET_TIME_2)
end_define

begin_define
define|#
directive|define
name|AR_QUIET2_QUIET_PERIOD_S
value|0
end_define

begin_comment
comment|// Periodicity of quiet period (TU)
end_comment

begin_define
define|#
directive|define
name|AR_QUIET2_QUIET_PERIOD_M
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR_QUIET2_QUIET_DUR_S
value|16
end_define

begin_comment
comment|// quiet period (TU)
end_comment

begin_define
define|#
directive|define
name|AR_QUIET2_QUIET_DUR
value|0xffff0000
end_define

begin_comment
comment|/* locate no_ack in qos */
end_comment

begin_define
define|#
directive|define
name|AR_QOS_NO_ACK
value|AR_MAC_PCU_OFFSET(MAC_PCU_QOS_NO_ACK)
end_define

begin_define
define|#
directive|define
name|AR_QOS_NO_ACK_TWO_BIT
value|0x0000000f
end_define

begin_comment
comment|// 2 bit sentinel for no-ack
end_comment

begin_define
define|#
directive|define
name|AR_QOS_NO_ACK_TWO_BIT_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_QOS_NO_ACK_BIT_OFF
value|0x00000070
end_define

begin_comment
comment|// offset for no-ack
end_comment

begin_define
define|#
directive|define
name|AR_QOS_NO_ACK_BIT_OFF_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_QOS_NO_ACK_BYTE_OFF
value|0x00000180
end_define

begin_comment
comment|// from end of header
end_comment

begin_define
define|#
directive|define
name|AR_QOS_NO_ACK_BYTE_OFF_S
value|7
end_define

begin_comment
comment|/* Phy errors to be filtered */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERROR_MASK)
end_define

begin_comment
comment|/* XXX validate! XXX */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_DCHIRP
value|0x00000008
end_define

begin_comment
comment|// Bit  3 enables double chirp
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_RADAR
value|0x00000020
end_define

begin_comment
comment|// Bit  5 is Radar signal
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_OFDM_TIMING
value|0x00020000
end_define

begin_comment
comment|// Bit 17 is AH_FALSE detect for OFDM
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_CCK_TIMING
value|0x02000000
end_define

begin_comment
comment|// Bit 25 is AH_FALSE detect for CCK
end_comment

begin_comment
comment|/* MAC PCU extended range latency */
end_comment

begin_define
define|#
directive|define
name|AR_XRLAT
value|AR_MAC_PCU_OFFSET(MAC_PCU_XRLAT)
end_define

begin_comment
comment|/* MAC PCU Receive Buffer settings */
end_comment

begin_define
define|#
directive|define
name|AR_RXFIFO_CFG
value|AR_MAC_PCU_OFFSET(MAC_PCU_RXBUF)
end_define

begin_define
define|#
directive|define
name|AR_RXFIFO_CFG_REG_RD_ENA_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_RXFIFO_CFG_REG_RD_ENA
value|(0x1<< AR_RXFIFO_CFG_REG_RD_ENA_S)
end_define

begin_comment
comment|/* MAC PCU QoS control */
end_comment

begin_define
define|#
directive|define
name|AR_MIC_QOS_CONTROL
value|AR_MAC_PCU_OFFSET(MAC_PCU_MIC_QOS_CONTROL)
end_define

begin_comment
comment|/* MAC PCU Michael QoS select */
end_comment

begin_define
define|#
directive|define
name|AR_MIC_QOS_SELECT
value|AR_MAC_PCU_OFFSET(MAC_PCU_MIC_QOS_SELECT)
end_define

begin_comment
comment|/* PCU Miscellaneous Mode */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC
value|AR_MAC_PCU_OFFSET(MAC_PCU_MISC_MODE)
end_define

begin_define
define|#
directive|define
name|AR_PCU_FORCE_BSSID_MATCH
value|0x00000001
end_define

begin_comment
comment|// force bssid to match
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MIC_NEW_LOC_ENA
value|0x00000004
end_define

begin_comment
comment|// tx/rx mic key are together
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TX_ADD_TSF
value|0x00000008
end_define

begin_comment
comment|// add tx_tsf + int_tsf
end_comment

begin_define
define|#
directive|define
name|AR_PCU_CCK_SIFS_MODE
value|0x00000010
end_define

begin_comment
comment|// assume 11b sifs programmed
end_comment

begin_define
define|#
directive|define
name|AR_PCU_RX_ANT_UPDT
value|0x00000800
end_define

begin_comment
comment|// KC_RX_ANT_UPDATE
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TXOP_TBTT_LIMIT_ENA
value|0x00001000
end_define

begin_comment
comment|// enforce txop / tbtt
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISS_BCN_IN_SLEEP
value|0x00004000
end_define

begin_comment
comment|// count bmiss's when sleeping
end_comment

begin_define
define|#
directive|define
name|AR_PCU_BUG_12306_FIX_ENA
value|0x00020000
end_define

begin_comment
comment|// use rx_clear to count sifs
end_comment

begin_define
define|#
directive|define
name|AR_PCU_FORCE_QUIET_COLL
value|0x00040000
end_define

begin_comment
comment|// kill xmit for channel change
end_comment

begin_define
define|#
directive|define
name|AR_PCU_BT_ANT_PREVENT_RX
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_PCU_BT_ANT_PREVENT_RX_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PCU_TBTT_PROTECT
value|0x00200000
end_define

begin_comment
comment|// no xmit upto tbtt + 20 uS
end_comment

begin_define
define|#
directive|define
name|AR_PCU_CLEAR_VMF
value|0x01000000
end_define

begin_comment
comment|// clear vmf mode (fast cc)
end_comment

begin_define
define|#
directive|define
name|AR_PCU_CLEAR_BA_VALID
value|0x04000000
end_define

begin_comment
comment|// clear ba state
end_comment

begin_define
define|#
directive|define
name|AR_PCU_SEL_EVM
value|0x08000000
end_define

begin_comment
comment|// select EVM data or PLCP header
end_comment

begin_define
define|#
directive|define
name|AR_PCU_ALWAYS_PERFORM_KEYSEARCH
value|0x10000000
end_define

begin_comment
comment|/* always perform key search */
end_comment

begin_comment
comment|/* count of filtered ofdm */
end_comment

begin_define
define|#
directive|define
name|AR_FILT_OFDM
value|AR_MAC_PCU_OFFSET(MAC_PCU_FILTER_OFDM_CNT)
end_define

begin_define
define|#
directive|define
name|AR_FILT_OFDM_COUNT
value|0x00FFFFFF
end_define

begin_comment
comment|// count of filtered ofdm
end_comment

begin_comment
comment|/* count of filtered cck */
end_comment

begin_define
define|#
directive|define
name|AR_FILT_CCK
value|AR_MAC_PCU_OFFSET(MAC_PCU_FILTER_CCK_CNT)
end_define

begin_define
define|#
directive|define
name|AR_FILT_CCK_COUNT
value|0x00FFFFFF
end_define

begin_comment
comment|// count of filtered cck
end_comment

begin_comment
comment|/* MAC PCU PHY error counter 1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_1
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERR_CNT_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_1_COUNT
value|0x00FFFFFF
end_define

begin_comment
comment|// phy errs that pass mask_1
end_comment

begin_comment
comment|/* MAC PCU PHY error mask 1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_1
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERR_CNT_1_MASK)
end_define

begin_comment
comment|/* MAC PCU PHY error counter 2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_2
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERR_CNT_2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_2_COUNT
value|0x00FFFFFF
end_define

begin_comment
comment|// phy errs that pass mask_2
end_comment

begin_comment
comment|/* MAC PCU PHY error mask 2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_2
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERR_CNT_2_MASK)
end_define

begin_define
define|#
directive|define
name|AR_PHY_COUNTMAX
value|(3<< 22)
end_define

begin_comment
comment|// Max counted before intr
end_comment

begin_define
define|#
directive|define
name|AR_MIBCNT_INTRMASK
value|(3<< 22)
end_define

begin_comment
comment|// Mask top 2 bits of counters
end_comment

begin_comment
comment|/* interrupt if rx_tsf-int_tsf */
end_comment

begin_define
define|#
directive|define
name|AR_TSFOOR_THRESHOLD
value|AR_MAC_PCU_OFFSET(MAC_PCU_TSF_THRESHOLD)
end_define

begin_define
define|#
directive|define
name|AR_TSFOOR_THRESHOLD_VAL
value|0x0000FFFF
end_define

begin_comment
comment|// field width
end_comment

begin_comment
comment|/* MAC PCU PHY error counter 3 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_3
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERR_CNT_3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_3_COUNT
value|0x00FFFFFF
end_define

begin_comment
comment|// phy errs that pass mask_3
end_comment

begin_comment
comment|/* MAC PCU PHY error mask 3 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_3
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERR_CNT_3_MASK)
end_define

begin_comment
comment|/* Bluetooth coexistance mode */
end_comment

begin_define
define|#
directive|define
name|AR_BT_COEX_MODE
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_MODE)
end_define

begin_define
define|#
directive|define
name|AR_BT_TIME_EXTEND
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_BT_TIME_EXTEND_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_BT_TXSTATE_EXTEND
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_BT_TXSTATE_EXTEND_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_BT_TX_FRAME_EXTEND
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_BT_TX_FRAME_EXTEND_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_BT_MODE
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|AR_BT_MODE_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_BT_QUIET
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_BT_QUIET_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_BT_QCU_THRESH
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|AR_BT_QCU_THRESH_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_BT_RX_CLEAR_POLARITY
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_BT_RX_CLEAR_POLARITY_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_BT_PRIORITY_TIME
value|0x00fc0000
end_define

begin_define
define|#
directive|define
name|AR_BT_PRIORITY_TIME_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_BT_FIRST_SLOT_TIME
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_BT_FIRST_SLOT_TIME_S
value|24
end_define

begin_comment
comment|/* BlueTooth coexistance WLAN weights */
end_comment

begin_define
define|#
directive|define
name|AR_BT_COEX_WL_WEIGHTS0
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_WL_WEIGHTS0)
end_define

begin_define
define|#
directive|define
name|AR_BT_BT_WGHT
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR_BT_BT_WGHT_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_BT_WL_WGHT
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|AR_BT_WL_WGHT_S
value|16
end_define

begin_comment
comment|/* HCF timeout: Slotted behavior */
end_comment

begin_define
define|#
directive|define
name|AR_HCFTO
value|AR_MAC_PCU_OFFSET(MAC_PCU_HCF_TIMEOUT)
end_define

begin_comment
comment|/* BlueTooth mode 2: Slotted behavior */
end_comment

begin_define
define|#
directive|define
name|AR_BT_COEX_MODE2
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_MODE2)
end_define

begin_define
define|#
directive|define
name|AR_BT_BCN_MISS_THRESH
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_BT_BCN_MISS_THRESH_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_BT_BCN_MISS_CNT
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_BT_BCN_MISS_CNT_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_BT_HOLD_RX_CLEAR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_BT_HOLD_RX_CLEAR_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_BT_SLEEP_ALLOW_BT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_BT_SLEEP_ALLOW_BT_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_BT_PROTECT_AFTER_WAKE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_BT_PROTECT_AFTER_WAKE_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_BT_DISABLE_BT_ANT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_BT_DISABLE_BT_ANT_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_BT_QUIET_2_WIRE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AR_BT_QUIET_2_WIRE_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_BT_WL_ACTIVE_MODE
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|AR_BT_WL_ACTIVE_MODE_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_BT_WL_TXRX_SEPARATE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_BT_WL_TXRX_SEPARATE_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_BT_RS_DISCARD_EXTEND
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_BT_RS_DISCARD_EXTEND_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_BT_TSF_BT_ACTIVE_CTRL
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|AR_BT_TSF_BT_ACTIVE_CTRL_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_BT_TSF_BT_PRIORITY_CTRL
value|0x30000000
end_define

begin_define
define|#
directive|define
name|AR_BT_TSF_BT_PRIORITY_CTRL_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_BT_INTERRUPT_ENABLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_BT_INTERRUPT_ENABLE_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_BT_PHY_ERR_BT_COLL_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_BT_PHY_ERR_BT_COLL_ENABLE_S
value|31
end_define

begin_comment
comment|/* Generic Timers 2 */
end_comment

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_0
value|AR_MAC_PCU_OFFSET(MAC_PCU_GENERIC_TIMERS2)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_NEXT
parameter_list|(
name|_i
parameter_list|)
value|(AR_GEN_TIMERS2_0 + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_PERIOD
parameter_list|(
name|_i
parameter_list|)
value|(AR_GEN_TIMERS2_NEXT(8) + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_0_NEXT
value|AR_GEN_TIMERS2_NEXT(0)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_1_NEXT
value|AR_GEN_TIMERS2_NEXT(1)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_2_NEXT
value|AR_GEN_TIMERS2_NEXT(2)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_3_NEXT
value|AR_GEN_TIMERS2_NEXT(3)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_4_NEXT
value|AR_GEN_TIMERS2_NEXT(4)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_5_NEXT
value|AR_GEN_TIMERS2_NEXT(5)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_6_NEXT
value|AR_GEN_TIMERS2_NEXT(6)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_7_NEXT
value|AR_GEN_TIMERS2_NEXT(7)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_0_PERIOD
value|AR_GEN_TIMERS2_PERIOD(0)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_1_PERIOD
value|AR_GEN_TIMERS2_PERIOD(1)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_2_PERIOD
value|AR_GEN_TIMERS2_PERIOD(2)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_3_PERIOD
value|AR_GEN_TIMERS2_PERIOD(3)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_4_PERIOD
value|AR_GEN_TIMERS2_PERIOD(4)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_5_PERIOD
value|AR_GEN_TIMERS2_PERIOD(5)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_6_PERIOD
value|AR_GEN_TIMERS2_PERIOD(6)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_7_PERIOD
value|AR_GEN_TIMERS2_PERIOD(7)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMER_BANK_1_LEN
value|8
end_define

begin_define
define|#
directive|define
name|AR_FIRST_NDP_TIMER
value|7
end_define

begin_define
define|#
directive|define
name|AR_NUM_GEN_TIMERS
value|16
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMER_RESERVED
value|8
end_define

begin_comment
comment|/* Generic Timers 2 Mode */
end_comment

begin_define
define|#
directive|define
name|AR_GEN_TIMERS2_MODE
value|AR_MAC_PCU_OFFSET(MAC_PCU_GENERIC_TIMERS2_MODE)
end_define

begin_comment
comment|/* BlueTooth coexistance WLAN weights 1 */
end_comment

begin_define
define|#
directive|define
name|AR_BT_COEX_WL_WEIGHTS1
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_WL_WEIGHTS1)
end_define

begin_comment
comment|/* BlueTooth Coexistence TSF Snapshot for BT_ACTIVE */
end_comment

begin_define
define|#
directive|define
name|AR_BT_TSF_ACTIVE
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE)
end_define

begin_comment
comment|/* BlueTooth Coexistence TSF Snapshot for BT_PRIORITY */
end_comment

begin_define
define|#
directive|define
name|AR_BT_TSF_PRIORITY
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY)
end_define

begin_comment
comment|/* SIFS, TX latency and ACK shift */
end_comment

begin_define
define|#
directive|define
name|AR_TXSIFS
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXSIFS)
end_define

begin_define
define|#
directive|define
name|AR_TXSIFS_TIME
value|0x000000FF
end_define

begin_comment
comment|// uS in SIFS
end_comment

begin_define
define|#
directive|define
name|AR_TXSIFS_TX_LATENCY
value|0x00000F00
end_define

begin_comment
comment|// uS for transmission thru bb
end_comment

begin_define
define|#
directive|define
name|AR_TXSIFS_TX_LATENCY_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_TXSIFS_ACK_SHIFT
value|0x00007000
end_define

begin_comment
comment|// chan width for ack
end_comment

begin_define
define|#
directive|define
name|AR_TXSIFS_ACK_SHIFT_S
value|12
end_define

begin_comment
comment|/* BlueTooth mode 3 */
end_comment

begin_define
define|#
directive|define
name|AR_BT_COEX_MODE3
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_MODE3)
end_define

begin_comment
comment|/* TXOP for legacy non-qos */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_X
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXOP_X)
end_define

begin_define
define|#
directive|define
name|AR_TXOP_X_VAL
value|0x000000FF
end_define

begin_comment
comment|/* TXOP for TID 0 to 3 */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_0_3
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXOP_0_3)
end_define

begin_comment
comment|/* TXOP for TID 4 to 7 */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_4_7
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXOP_4_7)
end_define

begin_comment
comment|/* TXOP for TID 8 to 11 */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_8_11
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXOP_8_11)
end_define

begin_comment
comment|/* TXOP for TID 12 to 15 */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_12_15
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXOP_12_15)
end_define

begin_comment
comment|/* Generic Timers */
end_comment

begin_define
define|#
directive|define
name|AR_GEN_TIMERS_0
value|AR_MAC_PCU_OFFSET(MAC_PCU_GENERIC_TIMERS)
end_define

begin_define
define|#
directive|define
name|AR_GEN_TIMERS
parameter_list|(
name|_i
parameter_list|)
value|(AR_GEN_TIMERS_0 + ((_i)<<2))
end_define

begin_comment
comment|/* generic timers based on tsf - all uS */
end_comment

begin_define
define|#
directive|define
name|AR_NEXT_TBTT_TIMER
value|AR_GEN_TIMERS(0)
end_define

begin_define
define|#
directive|define
name|AR_NEXT_DMA_BEACON_ALERT
value|AR_GEN_TIMERS(1)
end_define

begin_define
define|#
directive|define
name|AR_NEXT_SWBA
value|AR_GEN_TIMERS(2)
end_define

begin_define
define|#
directive|define
name|AR_NEXT_HCF
value|AR_GEN_TIMERS(3)
end_define

begin_define
define|#
directive|define
name|AR_NEXT_TIM
value|AR_GEN_TIMERS(4)
end_define

begin_define
define|#
directive|define
name|AR_NEXT_DTIM
value|AR_GEN_TIMERS(5)
end_define

begin_define
define|#
directive|define
name|AR_NEXT_QUIET_TIMER
value|AR_GEN_TIMERS(6)
end_define

begin_define
define|#
directive|define
name|AR_NEXT_NDP_TIMER
value|AR_GEN_TIMERS(7)
end_define

begin_define
define|#
directive|define
name|AR_BEACON_PERIOD
value|AR_GEN_TIMERS(8)
end_define

begin_define
define|#
directive|define
name|AR_DMA_BEACON_PERIOD
value|AR_GEN_TIMERS(9)
end_define

begin_define
define|#
directive|define
name|AR_SWBA_PERIOD
value|AR_GEN_TIMERS(10)
end_define

begin_define
define|#
directive|define
name|AR_HCF_PERIOD
value|AR_GEN_TIMERS(11)
end_define

begin_define
define|#
directive|define
name|AR_TIM_PERIOD
value|AR_GEN_TIMERS(12)
end_define

begin_define
define|#
directive|define
name|AR_DTIM_PERIOD
value|AR_GEN_TIMERS(13)
end_define

begin_define
define|#
directive|define
name|AR_QUIET_PERIOD
value|AR_GEN_TIMERS(14)
end_define

begin_define
define|#
directive|define
name|AR_NDP_PERIOD
value|AR_GEN_TIMERS(15)
end_define

begin_comment
comment|/* Generic Timers Mode */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER_MODE
value|AR_MAC_PCU_OFFSET(MAC_PCU_GENERIC_TIMERS_MODE)
end_define

begin_define
define|#
directive|define
name|AR_TBTT_TIMER_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_DBA_TIMER_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_SWBA_TIMER_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_HCF_TIMER_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_TIM_TIMER_EN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_DTIM_TIMER_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_QUIET_TIMER_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_NDP_TIMER_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_TIMER_OVERFLOW_INDEX
value|0x00000700
end_define

begin_define
define|#
directive|define
name|AR_TIMER_OVERFLOW_INDEX_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_TIMER_THRESH
value|0xFFFFF000
end_define

begin_define
define|#
directive|define
name|AR_TIMER_THRESH_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_SLP32_MODE
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP32_MODE)
end_define

begin_define
define|#
directive|define
name|AR_SLP32_HALF_CLK_LATENCY
value|0x000FFFFF
end_define

begin_comment
comment|// rising<-> falling edge
end_comment

begin_define
define|#
directive|define
name|AR_SLP32_ENA
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_SLP32_TSF_WRITE_STATUS
value|0x00200000
end_define

begin_comment
comment|// tsf update in progress
end_comment

begin_define
define|#
directive|define
name|AR_SLP32_WAKE
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP32_WAKE)
end_define

begin_define
define|#
directive|define
name|AR_SLP32_WAKE_XTL_TIME
value|0x0000FFFF
end_define

begin_comment
comment|// time to wake crystal
end_comment

begin_define
define|#
directive|define
name|AR_SLP32_INC
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP32_INC)
end_define

begin_define
define|#
directive|define
name|AR_SLP32_TST_INC
value|0x000FFFFF
end_define

begin_comment
comment|/* Sleep MIB cycle count 32kHz cycles for which mac is asleep */
end_comment

begin_define
define|#
directive|define
name|AR_SLP_CNT
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP_MIB1)
end_define

begin_define
define|#
directive|define
name|AR_SLP_CYCLE_CNT
value|0x8254
end_define

begin_comment
comment|// absolute number of 32kHz cycles
end_comment

begin_comment
comment|/* Sleep MIB cycle count 2 */
end_comment

begin_define
define|#
directive|define
name|AR_SLP_MIB2
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP_MIB2)
end_define

begin_comment
comment|/* Sleep MIB control status */
end_comment

begin_define
define|#
directive|define
name|AR_SLP_MIB_CTRL
value|AR_MAC_PCU_OFFSET(MAC_PCU_SLP_MIB3)
end_define

begin_define
define|#
directive|define
name|AR_SLP_MIB_CLEAR
value|0x00000001
end_define

begin_comment
comment|// clear pending
end_comment

begin_define
define|#
directive|define
name|AR_SLP_MIB_PENDING
value|0x00000002
end_define

begin_comment
comment|// clear counters
end_comment

begin_comment
comment|//#ifdef AR9300_EMULATION
end_comment

begin_comment
comment|// MAC trace buffer registers (emulation only)
end_comment

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER
value|AR_MAC_PCU_OFFSET(MAC_PCU_LOGIC_ANALYZER)
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_CTL
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_HOLD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_CLEAR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_STATE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_QCU_SEL
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_QCU_SEL_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_INT_ADDR
value|0x0003FF00
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_INT_ADDR_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_DIAG_MODE
value|0xFFFC0000
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_DIAG_MODE_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_DISBUG20614
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_DISBUG20768
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_DISBUG20803
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_PSTABUG75996
value|0x9d500010
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_VC_MODE
value|0x9d400010
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_32L
value|AR_MAC_PCU_OFFSET(MAC_PCU_LOGIC_ANALYZER_32L)
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_LOGIC_ANALYZER_16U
value|AR_MAC_PCU_OFFSET(MAC_PCU_LOGIC_ANALYZER_16U)
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_TRACE_REG_START
value|0xE000
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_TRACE_REG_END
value|0xFFFC
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_TRACE_BUFFER_LENGTH
value|(AR_MAC_PCU_TRACE_REG_END - AR_MAC_PCU_TRACE_REG_START + sizeof(uint32_t))
end_define

begin_comment
comment|//#endif  // AR9300_EMULATION
end_comment

begin_comment
comment|/* MAC PCU global mode register */
end_comment

begin_define
define|#
directive|define
name|AR_2040_MODE
value|AR_MAC_PCU_OFFSET(MAC_PCU_20_40_MODE)
end_define

begin_define
define|#
directive|define
name|AR_2040_JOINED_RX_CLEAR
value|0x00000001
end_define

begin_comment
comment|// use ctl + ext rx_clear for cca
end_comment

begin_comment
comment|/* MAC PCU H transfer timeout register */
end_comment

begin_define
define|#
directive|define
name|AR_H_XFER_TIMEOUT
value|AR_MAC_PCU_OFFSET(MAC_PCU_H_XFER_TIMEOUT)
end_define

begin_define
define|#
directive|define
name|AR_EXBF_IMMDIATE_RESP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_EXBF_NOACK_NO_RPT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_H_XFER_TIMEOUT_COUNT
value|0xf
end_define

begin_define
define|#
directive|define
name|AR_H_XFER_TIMEOUT_COUNT_S
value|0
end_define

begin_comment
comment|/*  * Additional cycle counter. See also AR_CCCNT  * extension channel rx clear count  * counts number of cycles rx_clear (ext) is low (i.e. busy)  * when the MAC is not actively transmitting/receiving  */
end_comment

begin_define
define|#
directive|define
name|AR_EXTRCCNT
value|AR_MAC_PCU_OFFSET(MAC_PCU_RX_CLEAR_DIFF_CNT)
end_define

begin_comment
comment|/* antenna mask for self generated files */
end_comment

begin_define
define|#
directive|define
name|AR_SELFGEN_MASK
value|AR_MAC_PCU_OFFSET(MAC_PCU_SELF_GEN_ANTENNA_MASK)
end_define

begin_comment
comment|/* control registers for block BA control fields */
end_comment

begin_define
define|#
directive|define
name|AR_BA_BAR_CONTROL
value|AR_MAC_PCU_OFFSET(MAC_PCU_BA_BAR_CONTROL)
end_define

begin_comment
comment|/* legacy PLCP spoof */
end_comment

begin_define
define|#
directive|define
name|AR_LEG_PLCP_SPOOF
value|AR_MAC_PCU_OFFSET(MAC_PCU_LEGACY_PLCP_SPOOF)
end_define

begin_comment
comment|/* PHY error mask and EIFS mask continued */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_CONT
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERROR_MASK_CONT)
end_define

begin_comment
comment|/* MAC PCU transmit timer */
end_comment

begin_define
define|#
directive|define
name|AR_TX_TIMER
value|AR_MAC_PCU_OFFSET(MAC_PCU_TX_TIMER)
end_define

begin_comment
comment|/* MAC PCU transmit buffer control */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TXBUF_CTRL
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXBUF_CTRL)
end_define

begin_define
define|#
directive|define
name|AR_PCU_TXBUF_CTRL_SIZE_MASK
value|0x7FF
end_define

begin_define
define|#
directive|define
name|AR_PCU_TXBUF_CTRL_USABLE_SIZE
value|0x700
end_define

begin_comment
comment|/*  * MAC PCU miscellaneous mode 2  * WAR flags for various bugs, see mac_pcu_reg documentation.  */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2
value|AR_MAC_PCU_OFFSET(MAC_PCU_MISC_MODE2)
end_define

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_BUG_21532_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_MGMT_CRYPTO_ENABLE
value|0x00000002
end_define

begin_comment
comment|/* Decrypt MGT frames using MFP method */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_NO_CRYPTO_FOR_NON_DATA_PKT
value|0x00000004
end_define

begin_comment
comment|/* Don't decrypt MGT frames at all */
end_comment

begin_define
define|#
directive|define
name|AR_BUG_58603_FIX_ENABLE
value|0x00000008
end_define

begin_comment
comment|/* Enable fix for bug 58603. This allows                                                                      * the use of AR_AGG_WEP_ENABLE.                                                                      */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_PROM_VC_MODE
value|0xa148103b
end_define

begin_comment
comment|/* Enable promiscous in azimuth mode */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_RESERVED
value|0x00000038
end_define

begin_define
define|#
directive|define
name|AR_ADHOC_MCAST_KEYID_ENABLE
value|0x00000040
end_define

begin_comment
comment|/* This bit enables the Multicast search                                                                      * based on both MAC Address and Key ID.                                                                      * If bit is 0, then Multicast search is                                                                      * based on MAC address only.                                                                      * For Merlin and above only.                                                                      */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_CFP_IGNORE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_MGMT_QOS
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_MGMT_QOS_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_ENABLE_LOAD_NAV_BEACON_DURATION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_AGG_WEP_ENABLE
value|0x00020000
end_define

begin_comment
comment|/* This field enables AGG_WEP feature,                                                                      * when it is enable, AGG_WEP would takes                                                                      * charge of the encryption interface of                                                                      * pcu_txsm.                                                                      */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_HWWAR1
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_PROXY_STA
value|0x01000000
end_define

begin_comment
comment|/* see EV 75996 */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_HWWAR2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_DECOUPLE_DECRYPTION
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AR_PCU_MISC_MODE2_RESERVED2
value|0xFFFE0000
end_define

begin_comment
comment|/* MAC PCU Alternate AES QoS mute mask */
end_comment

begin_define
define|#
directive|define
name|AR_ALT_AES_MUTE_MASK
value|AR_MAC_PCU_OFFSET(MAC_PCU_ALT_AES_MUTE_MASK)
end_define

begin_comment
comment|/* Async Fifo registers - debug only */
end_comment

begin_define
define|#
directive|define
name|AR_ASYNC_FIFO_1
value|AR_MAC_PCU_OFFSET(ASYNC_FIFO_REG1)
end_define

begin_define
define|#
directive|define
name|AR_ASYNC_FIFO_2
value|AR_MAC_PCU_OFFSET(ASYNC_FIFO_REG2)
end_define

begin_define
define|#
directive|define
name|AR_ASYNC_FIFO_3
value|AR_MAC_PCU_OFFSET(ASYNC_FIFO_REG3)
end_define

begin_comment
comment|/* Maps the 16 user priority TID values to Access categories */
end_comment

begin_define
define|#
directive|define
name|AR_TID_TO_AC_MAP
value|AR_MAC_PCU_OFFSET(MAC_PCU_TID_TO_AC)
end_define

begin_comment
comment|/* High Priority Queue Control */
end_comment

begin_define
define|#
directive|define
name|AR_HP_Q_CONTROL
value|AR_MAC_PCU_OFFSET(MAC_PCU_HP_QUEUE)
end_define

begin_comment
comment|/* Rx High Priority Queue Control */
end_comment

begin_define
define|#
directive|define
name|AR_HPQ_CONTROL
value|AR_MAC_PCU_OFFSET(MAC_PCU_HP_QUEUE)
end_define

begin_define
define|#
directive|define
name|AR_HPQ_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_HPQ_MASK_BE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_HPQ_MASK_BK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_HPQ_MASK_VI
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_HPQ_MASK_VO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_HPQ_UAPSD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_HPQ_FRAME_FILTER_0
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_HPQ_FRAME_BSSID_MATCH_0
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_HPQ_UAPSD_TRIGGER_EN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_BT_COEX_BT_WEIGHTS0
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_BT_WEIGHTS0)
end_define

begin_define
define|#
directive|define
name|AR_BT_COEX_BT_WEIGHTS1
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_BT_WEIGHTS1)
end_define

begin_define
define|#
directive|define
name|AR_BT_COEX_BT_WEIGHTS2
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_BT_WEIGHTS2)
end_define

begin_define
define|#
directive|define
name|AR_BT_COEX_BT_WEIGHTS3
value|AR_MAC_PCU_OFFSET(MAC_PCU_BLUETOOTH_BT_WEIGHTS3)
end_define

begin_define
define|#
directive|define
name|AR_AGC_SATURATION_CNT0
value|AR_MAC_PCU_OFFSET(MAC_PCU_AGC_SATURATION_CNT0)
end_define

begin_define
define|#
directive|define
name|AR_AGC_SATURATION_CNT1
value|AR_MAC_PCU_OFFSET(MAC_PCU_AGC_SATURATION_CNT1)
end_define

begin_define
define|#
directive|define
name|AR_AGC_SATURATION_CNT2
value|AR_MAC_PCU_OFFSET(MAC_PCU_AGC_SATURATION_CNT2)
end_define

begin_comment
comment|/* Hardware beacon processing */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1
value|AR_MAC_PCU_OFFSET(MAC_PCU_HW_BCN_PROC1)
end_define

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_CRC_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable hw beacon processing */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_RESET_CRC
value|0x00000002
end_define

begin_comment
comment|/* Reset the last beacon CRC calculated */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_EXCLUDE_BCN_INTVL
value|0x00000004
end_define

begin_comment
comment|/* Exclude Beacon interval in CRC calculation */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_EXCLUDE_CAP_INFO
value|0x00000008
end_define

begin_comment
comment|/* Exclude Beacon capability information in CRC calculation */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_EXCLUDE_TIM_ELM
value|0x00000010
end_define

begin_comment
comment|/* Exclude Beacon TIM element in CRC calculation */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_EXCLUDE_ELM0
value|0x00000020
end_define

begin_comment
comment|/* Exclude element ID ELM0 in CRC calculation */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_EXCLUDE_ELM1
value|0x00000040
end_define

begin_comment
comment|/* Exclude element ID ELM1 in CRC calculation */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_EXCLUDE_ELM2
value|0x00000080
end_define

begin_comment
comment|/* Exclude element ID ELM2 in CRC calculation */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_ELM0_ID
value|0x0000FF00
end_define

begin_comment
comment|/* Element ID 0 */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_ELM0_ID_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_ELM1_ID
value|0x00FF0000
end_define

begin_comment
comment|/* Element ID 1 */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_ELM1_ID_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_ELM2_ID
value|0xFF000000
end_define

begin_comment
comment|/* Element ID 2 */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC1_ELM2_ID_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_HWBCNPROC2
value|AR_MAC_PCU_OFFSET(MAC_PCU_HW_BCN_PROC2)
end_define

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_FILTER_INTERVAL_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable filtering beacons based on filter interval */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_RESET_INTERVAL
value|0x00000002
end_define

begin_comment
comment|/* Reset internal interval counter interval */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_EXCLUDE_ELM3
value|0x00000004
end_define

begin_comment
comment|/* Exclude element ID ELM3 in CRC calculation */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_RSVD
value|0x000000F8
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_FILTER_INTERVAL
value|0x0000FF00
end_define

begin_comment
comment|/* Filter interval for beacons */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_FILTER_INTERVAL_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_ELM3_ID
value|0x00FF0000
end_define

begin_comment
comment|/* Element ID 3 */
end_comment

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_ELM3_ID_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_HWBCNPROC2_RSVD2
value|0xFF000000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_PCU_MISC_MODE3
value|AR_MAC_PCU_OFFSET(MAC_PCU_MISC_MODE3)
end_define

begin_define
define|#
directive|define
name|AR_BUG_61936_FIX_ENABLE
value|0x00000040
end_define

begin_comment
comment|/* EV61936 - rx descriptor corruption */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_BASED_DISCARD_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_TIME_BASED_DISCARD_EN_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_GEN_TIMER_TSF_SEL
value|AR_MAC_PCU_OFFSET(MAC_PCU_GENERIC_TIMERS_TSF_SEL)
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_TBD_FILTER
value|AR_MAC_PCU_OFFSET(MAC_PCU_TBD_FILTER)
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_USE_WBTIMER_TX_TS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_USE_WBTIMER_TX_TS_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_USE_WBTIMER_RX_TS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_MAC_PCU_USE_WBTIMER_RX_TS_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXBUF_BA
value|AR_MAC_PCU_OFFSET(MAC_PCU_TXBUF_BA)
end_define

begin_comment
comment|/* MAC Key Cache */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_0
value|AR_MAC_PCU_OFFSET(MAC_PCU_KEY_CACHE)
end_define

begin_define
define|#
directive|define
name|AR_KEYTABLE
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE_0 + ((_n)*32))
end_define

begin_define
define|#
directive|define
name|AR_KEY_CACHE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|AR_RSVD_KEYTABLE_ENTRIES
value|4
end_define

begin_define
define|#
directive|define
name|AR_KEY_TYPE
value|0x00000007
end_define

begin_comment
comment|// MAC Key Type Mask
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_40
value|0x00000000
end_define

begin_comment
comment|/* WEP 40 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_104
value|0x00000001
end_define

begin_comment
comment|/* WEP 104 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_128
value|0x00000003
end_define

begin_comment
comment|/* WEP 128 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_TKIP
value|0x00000004
end_define

begin_comment
comment|/* TKIP and Michael */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_AES
value|0x00000005
end_define

begin_comment
comment|/* AES/OCB 128 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_CCM
value|0x00000006
end_define

begin_comment
comment|/* AES/CCM 128 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_CLR
value|0x00000007
end_define

begin_comment
comment|/* no encryption */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_ANT
value|0x00000008
end_define

begin_comment
comment|/* previous transmit antenna */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_UAPSD
value|0x000001E0
end_define

begin_comment
comment|/* UAPSD AC mask */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_UAPSD_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_KEYTABLE_PWRMGT
value|0x00000200
end_define

begin_comment
comment|/* hw managed PowerMgt bit */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MMSS
value|0x00001c00
end_define

begin_comment
comment|/* remote's MMSS*/
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MMSS_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_KEYTABLE_CEC
value|0x00006000
end_define

begin_comment
comment|/* remote's CEC*/
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_CEC_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_KEYTABLE_STAGGED
value|0x00010000
end_define

begin_comment
comment|/* remote's stagged sounding*/
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_STAGGED_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_KEYTABLE_VALID
value|0x00008000
end_define

begin_comment
comment|/* key and MAC address valid */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY0
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 0)
end_define

begin_comment
comment|/* key bit 0-31 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY1
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 4)
end_define

begin_comment
comment|/* key bit 32-47 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY2
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 8)
end_define

begin_comment
comment|/* key bit 48-79 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY3
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 12)
end_define

begin_comment
comment|/* key bit 80-95 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY4
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 16)
end_define

begin_comment
comment|/* key bit 96-127 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 20)
end_define

begin_comment
comment|/* key type */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MAC0
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 24)
end_define

begin_comment
comment|/* MAC address 1-32 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MAC1
parameter_list|(
name|_n
parameter_list|)
value|(AR_KEYTABLE(_n) + 28)
end_define

begin_comment
comment|/* MAC address 33-47 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_DIR_ACK_BIT
value|0x00000010
end_define

begin_comment
comment|/* Directed ACK bit */
end_comment

begin_comment
comment|/*  * MAC WoW Registers.  */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW1)
end_define

begin_define
define|#
directive|define
name|AR_WOW_PAT_BACKOFF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_WOW_BACK_OFF_SHIFT
parameter_list|(
name|x
parameter_list|)
value|((x& 0xf)<< 27)
end_define

begin_comment
comment|/* in usecs */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_MAC_INTR_EN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_WOW_MAGIC_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_EN
parameter_list|(
name|x
parameter_list|)
value|((x& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_FOUND_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_FOUND
parameter_list|(
name|x
parameter_list|)
value|(x& (0xff<< AR_WOW_PATTERN_FOUND_SHIFT))
end_define

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_FOUND_MASK
value|((0xff)<< AR_WOW_PATTERN_FOUND_SHIFT)
end_define

begin_define
define|#
directive|define
name|AR_WOW_MAGIC_PAT_FOUND
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_WOW_MAC_INTR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_FAIL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_WOW_BEACON_FAIL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AR_WOW_COUNT_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW2)
end_define

begin_define
define|#
directive|define
name|AR_WOW_AIFS_CNT
parameter_list|(
name|x
parameter_list|)
value|((x& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|AR_WOW_SLOT_CNT
parameter_list|(
name|x
parameter_list|)
value|((x& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_CNT
parameter_list|(
name|x
parameter_list|)
value|((x& 0xff)<< 16)
end_define

begin_comment
comment|/*  * Default values for Wow Configuration for backoff, aifs, slot, keep-alive, etc.  * to be programmed into various registers.  */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_CNT_AIFS_CNT
value|0x00000022
end_define

begin_comment
comment|// AR_WOW_COUNT_REG
end_comment

begin_define
define|#
directive|define
name|AR_WOW_CNT_SLOT_CNT
value|0x00000009
end_define

begin_comment
comment|// AR_WOW_COUNT_REG
end_comment

begin_comment
comment|/*  * Keepalive count applicable for Merlin 2.0 and above.  */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_CNT_KA_CNT
value|0x00000008
end_define

begin_comment
comment|// AR_WOW_COUNT_REG
end_comment

begin_define
define|#
directive|define
name|AR_WOW_BCN_EN_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW3_BEACON_FAIL)
end_define

begin_define
define|#
directive|define
name|AR_WOW_BEACON_FAIL_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_WOW_BCN_TIMO_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW3_BEACON)
end_define

begin_define
define|#
directive|define
name|AR_WOW_BEACON_TIMO
value|0x40000000
end_define

begin_comment
comment|/* Valid if BCN_EN is set */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_BEACON_TIMO_MAX
value|0xFFFFFFFF
end_define

begin_comment
comment|/* Max. value for Beacon Timeout */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_TIMO_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW3_KEEP_ALIVE)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_TIMO
value|0x00007A12
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_NEVER
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW_KA)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_AUTO_DIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_FAIL_DIS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_WOW_US_SCALAR_REG
value|AR_MAC_PCU_OFFSET(PCU_1US)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_DELAY_REG
value|AR_MAC_PCU_OFFSET(PCU_KA)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KEEP_ALIVE_DELAY
value|0x000003E8
end_define

begin_comment
comment|// 1 msec
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_MATCH_REG
value|AR_MAC_PCU_OFFSET(WOW_EXACT)
end_define

begin_define
define|#
directive|define
name|AR_WOW_PAT_END_OF_PKT
parameter_list|(
name|x
parameter_list|)
value|((x& 0xf)<< 0)
end_define

begin_define
define|#
directive|define
name|AR_WOW_PAT_OFF_MATCH
parameter_list|(
name|x
parameter_list|)
value|((x& 0xf)<< 8)
end_define

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_MATCH_REG_2
value|AR_MAC_PCU_OFFSET(WOW2_EXACT)
end_define

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_OFF1_REG
value|AR_MAC_PCU_OFFSET(PCU_WOW4)
end_define

begin_comment
comment|/* Pattern bytes 0 -> 3 */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_OFF2_REG
value|AR_MAC_PCU_OFFSET(PCU_WOW5)
end_define

begin_comment
comment|/* Pattern bytes 4 -> 7 */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_OFF3_REG
value|AR_MAC_PCU_OFFSET(PCU_WOW6)
end_define

begin_comment
comment|/* Pattern bytes 8 -> 11 */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_OFF4_REG
value|AR_MAC_PCU_OFFSET(PCU_WOW7)
end_define

begin_comment
comment|/* Pattern bytes 12 -> 15 */
end_comment

begin_comment
comment|/* start address of the frame in RxBUF */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_RXBUF_START_ADDR
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW6)
end_define

begin_comment
comment|/* Pattern detect and enable bits */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_DETECT_ENABLE
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW4)
end_define

begin_comment
comment|/* Rx Abort Enable */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_RX_ABORT_ENABLE
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW5)
end_define

begin_comment
comment|/* PHY error counter 1, 2, and 3 mask continued */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_CNT_MASK_CONT
value|AR_MAC_PCU_OFFSET(MAC_PCU_PHY_ERR_CNT_MASK_CONT)
end_define

begin_comment
comment|/* AZIMUTH mode reg can be used for proxySTA */
end_comment

begin_define
define|#
directive|define
name|AR_AZIMUTH_MODE
value|AR_MAC_PCU_OFFSET(MAC_PCU_AZIMUTH_MODE)
end_define

begin_define
define|#
directive|define
name|AR_AZIMUTH_KEY_SEARCH_AD1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_AZIMUTH_CTS_MATCH_TX_AD2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_AZIMUTH_BA_USES_AD1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_AZIMUTH_FILTER_PASS_HOLD
value|0x00000200
end_define

begin_comment
comment|/* Length of Pattern Match for Pattern */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_LENGTH1_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW_LENGTH1)
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH2_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW_LENGTH2)
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH3_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW_LENGTH3)
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH4_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_WOW_LENGTH4)
end_define

begin_define
define|#
directive|define
name|AR_LOC_CTL_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_LOCATION_MODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_LOC_TIMER_REG
value|AR_MAC_PCU_OFFSET(MAC_PCU_LOCATION_MODE_TIMER)
end_define

begin_define
define|#
directive|define
name|AR_LOC_CTL_REG_FS
value|0x1
end_define

begin_comment
comment|/* Register to enable pattern match for less than 256 bytes packets */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_MATCH_LT_256B_REG
value|AR_MAC_PCU_OFFSET(WOW_PATTERN_MATCH_LESS_THAN_256_BYTES)
end_define

begin_define
define|#
directive|define
name|AR_WOW_STATUS
parameter_list|(
name|x
parameter_list|)
value|(x& (AR_WOW_PATTERN_FOUND_MASK | AR_WOW_MAGIC_PAT_FOUND | \                                AR_WOW_KEEP_ALIVE_FAIL | AR_WOW_BEACON_FAIL))
end_define

begin_define
define|#
directive|define
name|AR_WOW_CLEAR_EVENTS
parameter_list|(
name|x
parameter_list|)
value|(x& ~(AR_WOW_PATTERN_EN(0xff) | \        AR_WOW_MAGIC_EN | AR_WOW_MAC_INTR_EN | AR_WOW_BEACON_FAIL | \        AR_WOW_KEEP_ALIVE_FAIL))
end_define

begin_comment
comment|/*  * Keep it long for Beacon workaround - ensures no AH_FALSE alarm  */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_BMISSTHRESHOLD
value|0x20
end_define

begin_comment
comment|/* WoW - Transmit buffer for keep alive frames */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_TRANSMIT_BUFFER
value|AR_MAC_PCU_OFFSET(MAC_PCU_BUF)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TXBUF
parameter_list|(
name|_i
parameter_list|)
value|(AR_WOW_TRANSMIT_BUFFER + ((_i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD2
value|AR_WOW_TXBUF(0)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD3
value|AR_WOW_TXBUF(1)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD4
value|AR_WOW_TXBUF(2)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD5
value|AR_WOW_TXBUF(3)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD6
value|AR_WOW_TXBUF(4)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD7
value|AR_WOW_TXBUF(5)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD8
value|AR_WOW_TXBUF(6)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD9
value|AR_WOW_TXBUF(7)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD10
value|AR_WOW_TXBUF(8)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD11
value|AR_WOW_TXBUF(9)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD12
value|AR_WOW_TXBUF(10)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DESC_WORD13
value|AR_WOW_TXBUF(11)
end_define

begin_comment
comment|/* KA_DATA_WORD = 6 words. Depending on the number of  * descriptor words, it can start at AR_WOW_TXBUF(12)  * or AR_WOW_TXBUF(13) */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_GTK_DATA_START
value|AR_WOW_TXBUF(19)
end_define

begin_define
define|#
directive|define
name|AR_WOW_KA_DATA_WORD_END_JUPITER
value|AR_WOW_TXBUF(60)
end_define

begin_define
define|#
directive|define
name|AR_WOW_SW_NULL_PARAMETER
value|AR_WOW_TXBUF(61)
end_define

begin_define
define|#
directive|define
name|AR_WOW_SW_NULL_LONG_PERIOD_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|AR_WOW_SW_NULL_LONG_PERIOD_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_WOW_SW_NULL_SHORT_PERIOD_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|AR_WOW_SW_NULL_SHORT_PERIOD_MASK_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_COMMAND_JUPITER
value|AR_WOW_TXBUF(62)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_GTK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_ACER_MAGIC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_STD_MAGIC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_SWKA
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_ARP_OFFLOAD
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_NS_OFFLOAD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_4WAY_WAKE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_GTK_ERROR_WAKE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_AP_LOSS_WAKE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_BT_SLEEP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_SW_NULL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_HWKA_FAIL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ENA_DEVID_SWAR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_STATUS_JUPITER
value|AR_WOW_TXBUF(63)
end_define

begin_comment
comment|/* WoW Transmit Buffer for patterns */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN0
value|AR_WOW_TXBUF(64)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN1
value|AR_WOW_TXBUF(128)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN2
value|AR_WOW_TXBUF(192)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN3
value|AR_WOW_TXBUF(256)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN4
value|AR_WOW_TXBUF(320)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN5
value|AR_WOW_TXBUF(384)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN6
value|AR_WOW_TXBUF(448)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_PATTERN7
value|AR_WOW_TXBUF(512)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK0
value|AR_WOW_TXBUF(768)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK1
value|AR_WOW_TXBUF(776)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK2
value|AR_WOW_TXBUF(784)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK3
value|AR_WOW_TXBUF(792)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK4
value|AR_WOW_TXBUF(800)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK5
value|AR_WOW_TXBUF(808)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK6
value|AR_WOW_TXBUF(816)
end_define

begin_define
define|#
directive|define
name|AR_WOW_TB_MASK7
value|AR_WOW_TXBUF(824)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_GTK_TXDESC_PARAM_START
value|AR_WOW_TXBUF(825)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_GTK_TXDESC_PARAM_START_JUPITER
value|AR_WOW_TXBUF(832)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_GTK_TXDESC_PARAM_WORDS
value|4
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_GTK_DATA_START_JUPITER
value|AR_WOW_TXBUF(836)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_GTK_DATA_WORDS_JUPITER
value|20
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_MAGIC_START
value|AR_WOW_TXBUF(856)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_MAGIC_WORDS
value|2
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA0_START
value|AR_WOW_TXBUF(858)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA0_PERIOD_MS
value|AR_WOW_TXBUF(858)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA0_SIZE
value|AR_WOW_TXBUF(859)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA0_DATA
value|AR_WOW_TXBUF(860)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA0_DATA_WORDS
value|20
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA0_WORDS
value|22
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA1_START
value|AR_WOW_TXBUF(880)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA1_PERIOD_MS
value|AR_WOW_TXBUF(880)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA1_SIZE
value|AR_WOW_TXBUF(881)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA1_DATA
value|AR_WOW_TXBUF(882)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA1_DATA_WORDS
value|20
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ACER_KA1_WORDS
value|22
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP0_START
value|AR_WOW_TXBUF(902)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP0_VALID
value|AR_WOW_TXBUF(902)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP0_RMT_IP
value|AR_WOW_TXBUF(903)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP0_HOST_IP
value|AR_WOW_TXBUF(904)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP0_MAC_L
value|AR_WOW_TXBUF(905)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP0_MAC_H
value|AR_WOW_TXBUF(906)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP0_WORDS
value|5
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP1_START
value|AR_WOW_TXBUF(907)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP1_VALID
value|AR_WOW_TXBUF(907)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP1_RMT_IP
value|AR_WOW_TXBUF(908)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP1_HOST_IP
value|AR_WOW_TXBUF(909)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP1_MAC_L
value|AR_WOW_TXBUF(910)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP1_MAC_H
value|AR_WOW_TXBUF(911)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_ARP1_WORDS
value|5
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_START
value|AR_WOW_TXBUF(912)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_VALID
value|AR_WOW_TXBUF(912)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_RMT_IPV6
value|AR_WOW_TXBUF(913)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_SOLICIT_IPV6
value|AR_WOW_TXBUF(917)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_MAC_L
value|AR_WOW_TXBUF(921)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_MAC_H
value|AR_WOW_TXBUF(922)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_TGT0_IPV6
value|AR_WOW_TXBUF(923)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_TGT1_IPV6
value|AR_WOW_TXBUF(927)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS0_WORDS
value|19
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_START
value|AR_WOW_TXBUF(931)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_VALID
value|AR_WOW_TXBUF(931)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_RMT_IPV6
value|AR_WOW_TXBUF(932)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_SOLICIT_IPV6
value|AR_WOW_TXBUF(936)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_MAC_L
value|AR_WOW_TXBUF(940)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_MAC_H
value|AR_WOW_TXBUF(941)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_TGT0_IPV6
value|AR_WOW_TXBUF(942)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_TGT1_IPV6
value|AR_WOW_TXBUF(946)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_NS1_WORDS
value|19
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_WLAN_REGSET_START
value|AR_WOW_TXBUF(950)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_WLAN_REGSET_NUM
value|AR_WOW_TXBUF(950)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_WLAN_REGSET_REGVAL
value|AR_WOW_TXBUF(951)
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_WLAN_REGSET_MAX_PAIR
value|32
end_define

begin_define
define|#
directive|define
name|AR_WOW_OFFLOAD_WLAN_REGSET_WORDS
value|65
end_define

begin_comment
comment|//(1 + AR_WOW_OFFLOAD_WLAN_REGSET_MAX_PAIR * 2)
end_comment

begin_comment
comment|/* Currently Pattern 0-7 are supported - so bit 0-7 are set */
end_comment

begin_define
define|#
directive|define
name|AR_WOW_PATTERN_SUPPORTED
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH_MAX
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH1_SHIFT
parameter_list|(
name|_i
parameter_list|)
value|((0x3 - ((_i)& 0x3))<< 0x3)
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH1_MASK
parameter_list|(
name|_i
parameter_list|)
value|(AR_WOW_LENGTH_MAX<< AR_WOW_LENGTH1_SHIFT(_i))
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH2_SHIFT
parameter_list|(
name|_i
parameter_list|)
value|((0x7 - ((_i)& 0x7))<< 0x3)
end_define

begin_define
define|#
directive|define
name|AR_WOW_LENGTH2_MASK
parameter_list|(
name|_i
parameter_list|)
value|(AR_WOW_LENGTH_MAX<< AR_WOW_LENGTH2_SHIFT(_i))
end_define

begin_comment
comment|/*  * MAC Direct Connect registers  *  * Added to support dual BSSID/TSF which are needed in the application  * of Mesh networking or Direct Connect.  */
end_comment

begin_comment
comment|/*  * Note that the only function added with this BSSID2 is to receive  * multi/broadcast from BSSID2 as well  */
end_comment

begin_comment
comment|/* MAC BSSID low 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_BSS2_ID0
value|AR_MAC_PCU_OFFSET(MAC_PCU_BSSID2_L32)
end_define

begin_comment
comment|/* MAC BSSID upper 16 bits / AID */
end_comment

begin_define
define|#
directive|define
name|AR_BSS2_ID1
value|AR_MAC_PCU_OFFSET(MAC_PCU_BSSID2_U16)
end_define

begin_comment
comment|/*  * Secondary TSF support added for dual BSSID/TSF  */
end_comment

begin_comment
comment|/* MAC local clock lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TSF2_L32
value|AR_MAC_PCU_OFFSET(MAC_PCU_TSF2_L32)
end_define

begin_comment
comment|/* MAC local clock upper 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TSF2_U32
value|AR_MAC_PCU_OFFSET(MAC_PCU_TSF2_U32)
end_define

begin_comment
comment|/* MAC Direct Connect Control */
end_comment

begin_define
define|#
directive|define
name|AR_DIRECT_CONNECT
value|AR_MAC_PCU_OFFSET(MAC_PCU_DIRECT_CONNECT)
end_define

begin_define
define|#
directive|define
name|AR_DC_AP_STA_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_DC_AP_STA_EN_S
value|0
end_define

begin_comment
comment|/*  * tx_bf Register  */
end_comment

begin_define
define|#
directive|define
name|AR_SVD_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct svd_reg, _x)
end_define

begin_define
define|#
directive|define
name|AR_TXBF_DBG
value|AR_SVD_OFFSET(TXBF_DBG)
end_define

begin_define
define|#
directive|define
name|AR_TXBF
value|AR_SVD_OFFSET(TXBF)
end_define

begin_define
define|#
directive|define
name|AR_TXBF_CB_TX
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_TXBF_CB_TX_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_PSI_1_PHI_3
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_PSI_2_PHI_4
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXBF_PSI_3_PHI_5
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXBF_PSI_4_PHI_6
value|3
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NB_TX
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NB_TX_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NUMBEROFBIT_4
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NUMBEROFBIT_2
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NUMBEROFBIT_6
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NUMBEROFBIT_8
value|3
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NG_RPT_TX
value|0x00000030
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NG_RPT_TX_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_TXBF_No_GROUP
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TWO_GROUP
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXBF_FOUR_GROUP
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NG_CVCACHE
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NG_CVCACHE_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_TXBF_FOUR_CLIENTS
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_EIGHT_CLIENTS
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXBF_SIXTEEN_CLIENTS
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TXCV_BFWEIGHT_METHOD
value|0x00000600
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TXCV_BFWEIGHT_METHOD_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_TXBF_NO_WEIGHTING
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_MAX_POWER
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXBF_KEEP_RATIO
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXBF_RLR_EN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_TXBF_RC_20_U_DONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_TXBF_RC_20_L_DONE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AR_TXBF_RC_40_DONE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AR_TXBF_FORCE_UPDATE_V2BB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TIMER
value|AR_SVD_OFFSET(TXBF_TIMER)
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TIMER_TIMEOUT
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TIMER_TIMEOUT_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TIMER_ATIMEOU
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_TXBF_TIMER_ATIMEOUT_S
value|8
end_define

begin_comment
comment|/* for SVD cache update */
end_comment

begin_define
define|#
directive|define
name|AR_TXBF_SW
value|AR_SVD_OFFSET(TXBF_SW)
end_define

begin_define
define|#
directive|define
name|AR_LRU_ACK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_LRU_ADDR
value|0x000003FE
end_define

begin_define
define|#
directive|define
name|AR_LRU_ADDR_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_LRU_EN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_LRU_EN_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_DEST_IDX
value|0x0007f000
end_define

begin_define
define|#
directive|define
name|AR_DEST_IDX_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_LRU_WR_ACK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_LRU_WR_ACK_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_LRU_RD_ACK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_LRU_RD_ACK_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_RC0_0
value|AR_SVD_OFFSET(RC0)
end_define

begin_define
define|#
directive|define
name|AR_RC0
parameter_list|(
name|_idx
parameter_list|)
value|(AR_RC0_0+(_idx))
end_define

begin_define
define|#
directive|define
name|AR_RC1_0
value|AR_SVD_OFFSET(RC1)
end_define

begin_define
define|#
directive|define
name|AR_RC1
parameter_list|(
name|_idx
parameter_list|)
value|(AR_RC1_0+(_idx))
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_0
value|AR_SVD_OFFSET(CVCACHE)
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE
parameter_list|(
name|_idx
parameter_list|)
value|(AR_CVCACHE_0+(_idx))
end_define

begin_comment
comment|/* for CV CACHE Header */
end_comment

begin_define
define|#
directive|define
name|AR_CVCACHE_Ng_IDX
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_Ng_IDX_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_BW40
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_BW40_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_IMPLICIT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_IMPLICIT_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_DEST_IDX
value|0x01FC0000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_DEST_IDX_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_Nc_IDX
value|0x06000000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_Nc_IDX_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_Nr_IDX
value|0x18000000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_Nr_IDX_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_EXPIRED
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_EXPIRED_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_WRITE
value|0x80000000
end_define

begin_comment
comment|/* for CV cache data*/
end_comment

begin_define
define|#
directive|define
name|AR_CVCACHE_RD_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_CVCACHE_DATA
value|0x3fffffff
end_define

begin_comment
comment|/*  * ANT DIV setting  */
end_comment

begin_define
define|#
directive|define
name|ANT_DIV_CONTROL_ALL
value|(0x7e000000)
end_define

begin_define
define|#
directive|define
name|ANT_DIV_CONTROL_ALL_S
value|(25)
end_define

begin_define
define|#
directive|define
name|ANT_DIV_ENABLE
value|(0x1000000)
end_define

begin_define
define|#
directive|define
name|ANT_DIV_ENABLE_S
value|(24)
end_define

begin_define
define|#
directive|define
name|FAST_DIV_ENABLE
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|FAST_DIV_ENABLE_S
value|(13)
end_define

begin_comment
comment|/* Global register */
end_comment

begin_define
define|#
directive|define
name|AR_GLB_REG_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct wlan_bt_glb_reg_pcie, _x)
end_define

begin_define
define|#
directive|define
name|AR_MBOX_CTRL_STATUS
value|AR_GLB_REG_OFFSET(GLB_MBOX_CONTROL_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_MBOX_INT_EMB_CPU
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_MBOX_INT_WLAN
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_MBOX_RESET
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_MBOX_RAM_REQ_MASK
value|0x0018
end_define

begin_define
define|#
directive|define
name|AR_MBOX_RAM_REQ_NO_RAM
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR_MBOX_RAM_REQ_USB
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_MBOX_RAM_REQ_WLAN_BUF
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_MBOX_RAM_REQ_PATCH_REAPPY
value|0x0018
end_define

begin_define
define|#
directive|define
name|AR_MBOX_RAM_CONF
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WLAN_BUF
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WOW_REQ
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WOW_CONF
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WOW_ERROR_MASK
value|0x1e00
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WOW_ERROR_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WOW_ERROR_INVALID_MSG
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WOW_ERROR_MALFORMED_MSG
value|0x0400
end_define

begin_define
define|#
directive|define
name|AR_MBOX_WOW_ERROR_INVALID_RAM_IMAGE
value|0x0600
end_define

begin_define
define|#
directive|define
name|AR_WLAN_WOW_STATUS
value|AR_GLB_REG_OFFSET(GLB_WLAN_WOW_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_WLAN_WOW_ENABLE
value|AR_GLB_REG_OFFSET(GLB_WLAN_WOW_ENABLE)
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_STATUS
value|AR_GLB_REG_OFFSET(GLB_EMB_CPU_WOW_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_STATUS_KEEP_ALIVE_FAIL
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_STATUS_BEACON_MISS
value|0x2
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_STATUS_PATTERN_MATCH
value|0x4
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_STATUS_MAGIC_PATTERN
value|0x8
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_ENABLE
value|AR_GLB_REG_OFFSET(GLB_EMB_CPU_WOW_ENABLE)
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_ENABLE_KEEP_ALIVE_FAIL
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_ENABLE_BEACON_MISS
value|0x2
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_ENABLE_PATTERN_MATCH
value|0x4
end_define

begin_define
define|#
directive|define
name|AR_EMB_CPU_WOW_ENABLE_MAGIC_PATTERN
value|0x8
end_define

begin_define
define|#
directive|define
name|AR_SW_WOW_CONTROL
value|AR_GLB_REG_OFFSET(GLB_SW_WOW_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_SW_WOW_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_SWITCH_TO_REFCLK
value|0x2
end_define

begin_define
define|#
directive|define
name|AR_RESET_CONTROL
value|0x4
end_define

begin_define
define|#
directive|define
name|AR_RESET_VALUE_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|AR_HW_WOW_DISABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|AR_CLR_MAC_INTERRUPT
value|0x20
end_define

begin_define
define|#
directive|define
name|AR_CLR_KA_INTERRUPT
value|0x40
end_define

begin_comment
comment|/*  * WLAN coex registers  */
end_comment

begin_define
define|#
directive|define
name|AR_WLAN_COEX_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct wlan_coex_reg, _x)
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND0
value|AR_WLAN_COEX_OFFSET(MCI_COMMAND0)
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND0_HEADER
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND0_HEADER_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND0_LEN
value|0x1f00
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND0_LEN_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND0_DISABLE_TIMESTAMP
value|0x2000
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND0_DISABLE_TIMESTAMP_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND1
value|AR_WLAN_COEX_OFFSET(MCI_COMMAND1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2
value|AR_WLAN_COEX_OFFSET(MCI_COMMAND2)
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_TX
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_TX_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_RX
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_RX_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_RX_NUM_CYCLES
value|0x3FC
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_RX_NUM_CYCLES_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_REQ_WAKEUP
value|0x400
end_define

begin_define
define|#
directive|define
name|AR_MCI_COMMAND2_RESET_REQ_WAKEUP_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_CTRL
value|AR_WLAN_COEX_OFFSET(MCI_RX_CTRL)
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL
value|AR_WLAN_COEX_OFFSET(MCI_TX_CTRL)
end_define

begin_comment
comment|/* 0 = no division, 1 = divide by 2, 2 = divide by 4, 3 = divide by 8 */
end_comment

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_CLK_DIV
value|0x03
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_CLK_DIV_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_DISABLE_LNA_UPDATE
value|0x04
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_DISABLE_LNA_UPDATE_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_GAIN_UPDATE_FREQ
value|0xFFFFF8
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_GAIN_UPDATE_FREQ_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_GAIN_UPDATE_NUM
value|0xF000000
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_CTRL_GAIN_UPDATE_NUM_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_MCI_MSG_ATTRIBUTES_TABLE
value|AR_WLAN_COEX_OFFSET(MCI_MSG_ATTRIBUTES_TABLE)
end_define

begin_define
define|#
directive|define
name|AR_MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|AR_MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|AR_MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_MCI_SCHD_TABLE_0
value|AR_WLAN_COEX_OFFSET(MCI_SCHD_TABLE_0)
end_define

begin_define
define|#
directive|define
name|AR_MCI_SCHD_TABLE_1
value|AR_WLAN_COEX_OFFSET(MCI_SCHD_TABLE_1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_GPM_0
value|AR_WLAN_COEX_OFFSET(MCI_GPM_0)
end_define

begin_define
define|#
directive|define
name|AR_MCI_GPM_1
value|AR_WLAN_COEX_OFFSET(MCI_GPM_1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_GPM_WRITE_PTR
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|AR_MCI_GPM_WRITE_PTR_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_MCI_GPM_BUF_LEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|AR_MCI_GPM_BUF_LEN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RAW
value|AR_WLAN_COEX_OFFSET(MCI_INTERRUPT_RAW)
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_EN
value|AR_WLAN_COEX_OFFSET(MCI_INTERRUPT_EN)
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_SW_MSG_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_SW_MSG_DONE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_CPU_INT_MSG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_CPU_INT_MSG_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_CKSUM_FAIL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_CKSUM_FAIL_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_INVALID_HDR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_INVALID_HDR_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_HW_MSG_FAIL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_HW_MSG_FAIL_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_SW_MSG_FAIL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_SW_MSG_FAIL_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_TX_HW_MSG_FAIL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_TX_HW_MSG_FAIL_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_TX_SW_MSG_FAIL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_TX_SW_MSG_FAIL_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_REMOTE_SLEEP_UPDATE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_REMOTE_SLEEP_UPDATE_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_PRI
value|0x07fff800
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_PRI_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_PRI_THRESH
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_PRI_THRESH_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_FREQ
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_FREQ_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_STOMP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BT_STOMP_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BB_AIC_IRQ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_BB_AIC_IRQ_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_CONT_INFO_TIMEOUT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_CONT_INFO_TIMEOUT_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_MSG_FAIL_MASK
value|( AR_MCI_INTERRUPT_RX_HW_MSG_FAIL | \                                          AR_MCI_INTERRUPT_RX_SW_MSG_FAIL | \                                          AR_MCI_INTERRUPT_TX_HW_MSG_FAIL | \                                          AR_MCI_INTERRUPT_TX_SW_MSG_FAIL )
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_DEFAULT
value|( AR_MCI_INTERRUPT_SW_MSG_DONE |          \                                                 AR_MCI_INTERRUPT_RX_INVALID_HDR |       \                                                 AR_MCI_INTERRUPT_RX_HW_MSG_FAIL |       \                                                 AR_MCI_INTERRUPT_RX_SW_MSG_FAIL |       \                                                 AR_MCI_INTERRUPT_TX_HW_MSG_FAIL |       \                                                 AR_MCI_INTERRUPT_TX_SW_MSG_FAIL |       \                                                 AR_MCI_INTERRUPT_RX_MSG |               \                                                 AR_MCI_INTERRUPT_REMOTE_SLEEP_UPDATE |  \                                                 AR_MCI_INTERRUPT_CONT_INFO_TIMEOUT )
end_define

begin_define
define|#
directive|define
name|AR_MCI_REMOTE_CPU_INT
value|AR_WLAN_COEX_OFFSET(MCI_REMOTE_CPU_INT)
end_define

begin_define
define|#
directive|define
name|AR_MCI_REMOTE_CPU_INT_EN
value|AR_WLAN_COEX_OFFSET(MCI_REMOTE_CPU_INT_EN)
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_RAW
value|AR_WLAN_COEX_OFFSET(MCI_INTERRUPT_RX_MSG_RAW)
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_EN
value|AR_WLAN_COEX_OFFSET(MCI_INTERRUPT_RX_MSG_EN)
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_REMOTE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_REMOTE_RESET_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_LNA_CONTROL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_LNA_CONTROL_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CONT_NACK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CONT_NACK_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CONT_INFO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CONT_INFO_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CONT_RST
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CONT_RST_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_SCHD_INFO
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_SCHD_INFO_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CPU_INT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_CPU_INT_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_GPM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_GPM_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_LNA_INFO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_LNA_INFO_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_REQ_WAKE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_REQ_WAKE_S
value|12
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AH_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_DEFAULT
value|( AR_MCI_INTERRUPT_RX_MSG_GPM           | \                                                 AR_MCI_INTERRUPT_RX_MSG_REMOTE_RESET  | \                                                 AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING    | \                                                 AR_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING  | \                                                 AR_MCI_INTERRUPT_RX_MSG_SCHD_INFO     | \                                                 AR_MCI_INTERRUPT_RX_MSG_LNA_CONTROL   | \                                                 AR_MCI_INTERRUPT_RX_MSG_LNA_INFO      | \                                                 AR_MCI_INTERRUPT_RX_MSG_CONT_NACK     | \                                                 AR_MCI_INTERRUPT_RX_MSG_CONT_INFO     | \                                                 AR_MCI_INTERRUPT_RX_MSG_CONT_RST      | \                                                 AR_MCI_INTERRUPT_RX_MSG_REQ_WAKE )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_MSG_DEFAULT
value|( AR_MCI_INTERRUPT_RX_MSG_GPM           | \                                                 AR_MCI_INTERRUPT_RX_MSG_REMOTE_RESET  | \                                                 AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING    | \                                                 AR_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING  | \                                                 AR_MCI_INTERRUPT_RX_MSG_REQ_WAKE )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AR_MCI_INTERRUPT_RX_HW_MSG_MASK
value|( AR_MCI_INTERRUPT_RX_MSG_SCHD_INFO     | \                                                 AR_MCI_INTERRUPT_RX_MSG_LNA_CONTROL   | \                                                 AR_MCI_INTERRUPT_RX_MSG_LNA_INFO      | \                                                 AR_MCI_INTERRUPT_RX_MSG_CONT_NACK     | \                                                 AR_MCI_INTERRUPT_RX_MSG_CONT_INFO     | \                                                 AR_MCI_INTERRUPT_RX_MSG_CONT_RST )
end_define

begin_define
define|#
directive|define
name|AR_MCI_CPU_INT
value|AR_WLAN_COEX_OFFSET(MCI_CPU_INT)
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_STATUS
value|AR_WLAN_COEX_OFFSET(MCI_RX_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_LAST_SCHD_MSG_INDEX
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_LAST_SCHD_MSG_INDEX_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_REMOTE_SLEEP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_REMOTE_SLEEP_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_MCI_CLK_REQ
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AR_MCI_RX_MCI_CLK_REQ_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_MCI_CONT_STATUS
value|AR_WLAN_COEX_OFFSET(MCI_CONT_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_MCI_CONT_RSSI_POWER
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_MCI_CONT_RSSI_POWER_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_CONT_RRIORITY
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_MCI_CONT_RRIORITY_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_MCI_CONT_TXRX
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_MCI_CONT_TXRX_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_MCI_BT_PRI0
value|AR_WLAN_COEX_OFFSET(MCI_BT_PRI0)
end_define

begin_define
define|#
directive|define
name|AR_MCI_BT_PRI1
value|AR_WLAN_COEX_OFFSET(MCI_BT_PRI1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_BT_PRI2
value|AR_WLAN_COEX_OFFSET(MCI_BT_PRI2)
end_define

begin_define
define|#
directive|define
name|AR_MCI_BT_PRI3
value|AR_WLAN_COEX_OFFSET(MCI_BT_PRI3)
end_define

begin_define
define|#
directive|define
name|AR_MCI_BT_PRI
value|AR_WLAN_COEX_OFFSET(MCI_BT_PRI)
end_define

begin_define
define|#
directive|define
name|AR_MCI_WL_FREQ0
value|AR_WLAN_COEX_OFFSET(MCI_WL_FREQ0)
end_define

begin_define
define|#
directive|define
name|AR_MCI_WL_FREQ1
value|AR_WLAN_COEX_OFFSET(MCI_WL_FREQ1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_WL_FREQ2
value|AR_WLAN_COEX_OFFSET(MCI_WL_FREQ2)
end_define

begin_define
define|#
directive|define
name|AR_MCI_GAIN
value|AR_WLAN_COEX_OFFSET(MCI_GAIN)
end_define

begin_define
define|#
directive|define
name|AR_MCI_WBTIMER1
value|AR_WLAN_COEX_OFFSET(MCI_WBTIMER1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_WBTIMER2
value|AR_WLAN_COEX_OFFSET(MCI_WBTIMER2)
end_define

begin_define
define|#
directive|define
name|AR_MCI_WBTIMER3
value|AR_WLAN_COEX_OFFSET(MCI_WBTIMER3)
end_define

begin_define
define|#
directive|define
name|AR_MCI_WBTIMER4
value|AR_WLAN_COEX_OFFSET(MCI_WBTIMER4)
end_define

begin_define
define|#
directive|define
name|AR_MCI_MAXGAIN
value|AR_WLAN_COEX_OFFSET(MCI_MAXGAIN)
end_define

begin_define
define|#
directive|define
name|AR_MCI_HW_SCHD_TBL_CTL
value|AR_WLAN_COEX_OFFSET(MCI_HW_SCHD_TBL_CTL)
end_define

begin_define
define|#
directive|define
name|AR_MCI_HW_SCHD_TBL_D0
value|AR_WLAN_COEX_OFFSET(MCI_HW_SCHD_TBL_D0)
end_define

begin_define
define|#
directive|define
name|AR_MCI_HW_SCHD_TBL_D1
value|AR_WLAN_COEX_OFFSET(MCI_HW_SCHD_TBL_D1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_HW_SCHD_TBL_D2
value|AR_WLAN_COEX_OFFSET(MCI_HW_SCHD_TBL_D2)
end_define

begin_define
define|#
directive|define
name|AR_MCI_HW_SCHD_TBL_D3
value|AR_WLAN_COEX_OFFSET(MCI_HW_SCHD_TBL_D3)
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_PAYLOAD0
value|AR_WLAN_COEX_OFFSET(MCI_TX_PAYLOAD0)
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_PAYLOAD1
value|AR_WLAN_COEX_OFFSET(MCI_TX_PAYLOAD1)
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_PAYLOAD2
value|AR_WLAN_COEX_OFFSET(MCI_TX_PAYLOAD2)
end_define

begin_define
define|#
directive|define
name|AR_MCI_TX_PAYLOAD3
value|AR_WLAN_COEX_OFFSET(MCI_TX_PAYLOAD3)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_WBTIMER
value|AR_WLAN_COEX_OFFSET(BTCOEX_WBTIMER)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL
value|AR_WLAN_COEX_OFFSET(BTCOEX_CTRL)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_JUPITER_MODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_JUPITER_MODE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_WBTIMER_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_WBTIMER_EN_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_MCI_MODE_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_MCI_MODE_EN_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_LNA_SHARED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_LNA_SHARED_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_PA_SHARED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_PA_SHARED_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_EN_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_EN_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_NUM_ANTENNAS
value|0x00000180
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_NUM_ANTENNAS_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_RX_CHAIN_MASK
value|0x00000E00
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_RX_CHAIN_MASK_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_AGGR_THRESH
value|0x00007000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_AGGR_THRESH_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_1_CHAIN_BCN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_1_CHAIN_BCN_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_1_CHAIN_ACK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_1_CHAIN_ACK_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_WAIT_BA_MARGIN
value|0x1FE00000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_WAIT_BA_MARGIN_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_REDUCE_TXPWR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_REDUCE_TXPWR_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_SPDT_ENABLE_10
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_SPDT_ENABLE_10_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_SPDT_POLARITY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_SPDT_POLARITY_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_WL_WEIGHTS0
value|AR_WLAN_COEX_OFFSET(BTCOEX_WL_WEIGHTS0)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_WL_WEIGHTS1
value|AR_WLAN_COEX_OFFSET(BTCOEX_WL_WEIGHTS1)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_WL_WEIGHTS2
value|AR_WLAN_COEX_OFFSET(BTCOEX_WL_WEIGHTS2)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_WL_WEIGHTS3
value|AR_WLAN_COEX_OFFSET(BTCOEX_WL_WEIGHTS3)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_MAX_TXPWR
parameter_list|(
name|_x
parameter_list|)
value|(AR_WLAN_COEX_OFFSET(BTCOEX_MAX_TXPWR) + ((_x)<< 2))
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_WL_LNA
value|AR_WLAN_COEX_OFFSET(BTCOEX_WL_LNA)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_RFGAIN_CTRL
value|AR_WLAN_COEX_OFFSET(BTCOEX_RFGAIN_CTRL)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2
value|AR_WLAN_COEX_OFFSET(BTCOEX_CTRL2)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_TXPWR_THRESH
value|0x0007F800
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_TXPWR_THRESH_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_TX_CHAIN_MASK
value|0x00380000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_TX_CHAIN_MASK_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_RX_DEWEIGHT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_RX_DEWEIGHT_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_GPIO_OBS_SEL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_GPIO_OBS_SEL_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_MAC_BB_OBS_SEL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_MAC_BB_OBS_SEL_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_DESC_BASED_TXPWR_ENABLE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL2_DESC_BASED_TXPWR_ENABLE_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_RC
value|AR_WLAN_COEX_OFFSET(BTCOEX_RC)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_MAX_RFGAIN
parameter_list|(
name|_x
parameter_list|)
value|AR_WLAN_COEX_OFFSET(BTCOEX_MAX_RFGAIN[_x])
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_DBG
value|AR_WLAN_COEX_OFFSET(BTCOEX_DBG)
end_define

begin_define
define|#
directive|define
name|AR_MCI_LAST_HW_MSG_HDR
value|AR_WLAN_COEX_OFFSET(MCI_LAST_HW_MSG_HDR)
end_define

begin_define
define|#
directive|define
name|AR_MCI_LAST_HW_MSG_BDY
value|AR_WLAN_COEX_OFFSET(MCI_LAST_HW_MSG_BDY)
end_define

begin_define
define|#
directive|define
name|AR_MCI_SCHD_TABLE_2
value|AR_WLAN_COEX_OFFSET(MCI_SCHD_TABLE_2)
end_define

begin_define
define|#
directive|define
name|AR_MCI_SCHD_TABLE_2_MEM_BASED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_MCI_SCHD_TABLE_2_MEM_BASED_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_MCI_SCHD_TABLE_2_HW_BASED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_MCI_SCHD_TABLE_2_HW_BASED_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL3
value|AR_WLAN_COEX_OFFSET(BTCOEX_CTRL3)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL3_CONT_INFO_TIMEOUT
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL3_CONT_INFO_TIMEOUT_S
value|0
end_define

begin_comment
comment|/******************************************************************************  * WLAN BT Global Register Map ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AR_WLAN_BT_GLB_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|offsetof(struct wlan_bt_glb_reg_pcie, _x)
end_define

begin_comment
comment|/*  * WLAN BT Global Registers  */
end_comment

begin_define
define|#
directive|define
name|AR_GLB_GPIO_CONTROL
value|AR_WLAN_BT_GLB_OFFSET(GLB_GPIO_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_GLB_WLAN_WOW_STATUS
value|AR_WLAN_BT_GLB_OFFSET(GLB_WLAN_WOW_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_GLB_WLAN_WOW_ENABLE
value|AR_WLAN_BT_GLB_OFFSET(GLB_WLAN_WOW_ENABLE)
end_define

begin_define
define|#
directive|define
name|AR_GLB_EMB_CPU_WOW_STATUS
value|AR_WLAN_BT_GLB_OFFSET(GLB_EMB_CPU_WOW_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_GLB_EMB_CPU_WOW_ENABLE
value|AR_WLAN_BT_GLB_OFFSET(GLB_EMB_CPU_WOW_ENABLE)
end_define

begin_define
define|#
directive|define
name|AR_GLB_MBOX_CONTROL_STATUS
value|AR_WLAN_BT_GLB_OFFSET(GLB_MBOX_CONTROL_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_GLB_SW_WOW_CLK_CONTROL
value|AR_WLAN_BT_GLB_OFFSET(GLB_SW_WOW_CLK_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_GLB_APB_TIMEOUT
value|AR_WLAN_BT_GLB_OFFSET(GLB_APB_TIMEOUT)
end_define

begin_define
define|#
directive|define
name|AR_GLB_OTP_LDO_CONTROL
value|AR_WLAN_BT_GLB_OFFSET(GLB_OTP_LDO_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_GLB_OTP_LDO_POWER_GOOD
value|AR_WLAN_BT_GLB_OFFSET(GLB_OTP_LDO_POWER_GOOD)
end_define

begin_define
define|#
directive|define
name|AR_GLB_OTP_LDO_STATUS
value|AR_WLAN_BT_GLB_OFFSET(GLB_OTP_LDO_STATUS)
end_define

begin_define
define|#
directive|define
name|AR_GLB_SWREG_DISCONT_MODE
value|AR_WLAN_BT_GLB_OFFSET(GLB_SWREG_DISCONT_MODE)
end_define

begin_define
define|#
directive|define
name|AR_GLB_BT_GPIO_REMAP_OUT_CONTROL0
value|AR_WLAN_BT_GLB_OFFSET(GLB_BT_GPIO_REMAP_OUT_CONTROL0)
end_define

begin_define
define|#
directive|define
name|AR_GLB_BT_GPIO_REMAP_OUT_CONTROL1
value|AR_WLAN_BT_GLB_OFFSET(GLB_BT_GPIO_REMAP_OUT_CONTROL1)
end_define

begin_define
define|#
directive|define
name|AR_GLB_BT_GPIO_REMAP_IN_CONTROL0
value|AR_WLAN_BT_GLB_OFFSET(GLB_BT_GPIO_REMAP_IN_CONTROL0)
end_define

begin_define
define|#
directive|define
name|AR_GLB_BT_GPIO_REMAP_IN_CONTROL1
value|AR_WLAN_BT_GLB_OFFSET(GLB_BT_GPIO_REMAP_IN_CONTROL1)
end_define

begin_define
define|#
directive|define
name|AR_GLB_BT_GPIO_REMAP_IN_CONTROL2
value|AR_WLAN_BT_GLB_OFFSET(GLB_BT_GPIO_REMAP_IN_CONTROL2)
end_define

begin_define
define|#
directive|define
name|AR_GLB_SCRATCH
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_APHRODITE(_ah)?          \         AR_WLAN_BT_GLB_OFFSET(overlay_0x20044.Aphrodite_10.GLB_SCRATCH) : \         (AR_SREV_JUPITER_20(_ah) ?          \             AR_WLAN_BT_GLB_OFFSET(overlay_0x20044.Jupiter_20.GLB_SCRATCH) : \             AR_WLAN_BT_GLB_OFFSET(overlay_0x20044.Jupiter_10.GLB_SCRATCH)))
end_define

begin_define
define|#
directive|define
name|AR_GLB_CONTROL
value|AR_WLAN_BT_GLB_OFFSET(overlay_0x20044.Jupiter_20.GLB_CONTROL)
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_SPDT_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_SPDT_ENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_BT_OWN_SPDT_CTRL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_BT_OWN_SPDT_CTRL_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_USE_LATCHED_BT_ANT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_BTCOEX_CTRL_USE_LATCHED_BT_ANT_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_GLB_WLAN_UART_INTF_EN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_GLB_WLAN_UART_INTF_EN_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_GLB_DS_JTAG_DISABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_GLB_DS_JTAG_DISABLE_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_GLB_STATUS
value|AR_WLAN_BT_GLB_OFFSET(overlay_0x20044.Jupiter_20.GLB_STATUS)
end_define

begin_comment
comment|/*  * MAC Version and Revision  */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION_OSPREY
value|0x1C0
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_AR9580
value|0x1C0
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_JUPITER
value|0x280
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_HORNET
value|0x200
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_WASP
value|0x300
end_define

begin_comment
comment|/* XXX: Check Wasp version number */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION_SCORPION
value|0x400
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_POSEIDON
value|0x240
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_APHRODITE
value|0x2C0
end_define

begin_define
define|#
directive|define
name|AR_SREV_REVISION_OSPREY_10
value|0
end_define

begin_comment
comment|/* Osprey 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_OSPREY_20
value|2
end_define

begin_comment
comment|/* Osprey 2.0/2.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_OSPREY_22
value|3
end_define

begin_comment
comment|/* Osprey 2.2 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9580_10
value|4
end_define

begin_comment
comment|/* AR9580/Peacock 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_HORNET_10
value|0
end_define

begin_comment
comment|/* Hornet 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_HORNET_11
value|1
end_define

begin_comment
comment|/* Hornet 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_HORNET_12
value|2
end_define

begin_comment
comment|/* Hornet 1.2 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_HORNET_11_MASK
value|0xf
end_define

begin_comment
comment|/* Hornet 1.1 revision mask */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_POSEIDON_10
value|0
end_define

begin_comment
comment|/* Poseidon 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_POSEIDON_11
value|1
end_define

begin_comment
comment|/* Poseidon 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_WASP_10
value|0
end_define

begin_comment
comment|/* Wasp 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_WASP_11
value|1
end_define

begin_comment
comment|/* Wasp 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_WASP_12
value|2
end_define

begin_comment
comment|/* Wasp 1.2 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_WASP_13
value|3
end_define

begin_comment
comment|/* Wasp 1.3 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_WASP_MASK
value|0xf
end_define

begin_comment
comment|/* Wasp revision mask */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_WASP_MINOR_MINOR_MASK
value|0x10000
end_define

begin_comment
comment|/* Wasp minor minor revision mask */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_WASP_MINOR_MINOR_SHIFT
value|16
end_define

begin_comment
comment|/* Wasp minor minor revision shift */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_JUPITER_10
value|0
end_define

begin_comment
comment|/* Jupiter 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_JUPITER_20
value|2
end_define

begin_comment
comment|/* Jupiter 2.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_APHRODITE_10
value|0
end_define

begin_comment
comment|/* Aphrodite 1.0 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AH_SUPPORT_OSPREY
argument_list|)
end_if

begin_define
define|#
directive|define
name|AR_SREV_OSPREY
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_OSPREY))
end_define

begin_define
define|#
directive|define
name|AR_SREV_OSPREY_22
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_OSPREY)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_OSPREY_22))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AR_SREV_OSPREY
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_OSPREY_10
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_OSPREY_20
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_OSPREY_22
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_OSPREY_20_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_OSPREY_22_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if defined(AH_SUPPORT_OSPREY) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_AR9580
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_AR9580)&& \      (AH_PRIVATE((_ah))->ah_macRev>= AR_SREV_REVISION_AR9580_10))
end_define

begin_define
define|#
directive|define
name|AR_SREV_AR9580_10
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_AR9580)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_AR9580_10))
end_define

begin_comment
comment|/* NOTE: When adding chips newer than Peacock, add chip check here.  */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_AR9580_10_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_AR9580(_ah))
end_define

begin_define
define|#
directive|define
name|AR_SREV_JUPITER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_JUPITER))
end_define

begin_define
define|#
directive|define
name|AR_SREV_JUPITER_10
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_JUPITER)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_JUPITER_10))
end_define

begin_define
define|#
directive|define
name|AR_SREV_JUPITER_20
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_JUPITER)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_JUPITER_20))
end_define

begin_define
define|#
directive|define
name|AR_SREV_JUPITER_20_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_JUPITER)&& \      (AH_PRIVATE((_ah))->ah_macRev>= AR_SREV_REVISION_JUPITER_20))
end_define

begin_define
define|#
directive|define
name|AR_SREV_APHRODITE
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_APHRODITE))
end_define

begin_define
define|#
directive|define
name|AR_SREV_APHRODITE_10
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_APHRODITE)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_APHRODITE_10))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AH_SUPPORT_HORNET
argument_list|)
end_if

begin_define
define|#
directive|define
name|AR_SREV_HORNET_10
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_HORNET)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_HORNET_10))
end_define

begin_define
define|#
directive|define
name|AR_SREV_HORNET_11
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_HORNET)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_HORNET_11))
end_define

begin_define
define|#
directive|define
name|AR_SREV_HORNET_12
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_HORNET)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_HORNET_12))
end_define

begin_define
define|#
directive|define
name|AR_SREV_HORNET
parameter_list|(
name|_ah
parameter_list|)
define|\
value|( AR_SREV_HORNET_10(_ah) || AR_SREV_HORNET_11(_ah) || AR_SREV_HORNET_12(_ah) )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AR_SREV_HORNET_10
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_HORNET_11
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_HORNET_12
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_HORNET
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if defined(AH_SUPPORT_HORNET) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AH_SUPPORT_WASP
argument_list|)
end_if

begin_define
define|#
directive|define
name|AR_SREV_WASP
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_WASP))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AR_SREV_WASP
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if defined(AH_SUPPORT_WASP) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_WASP_10
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_WASP)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_WASP_10))
end_define

begin_define
define|#
directive|define
name|AR_SREV_WASP_11
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_WASP)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_WASP_11))
end_define

begin_define
define|#
directive|define
name|AR_SREV_WASP_12
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_WASP)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_WASP_12))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AH_SUPPORT_SCORPION
argument_list|)
end_if

begin_define
define|#
directive|define
name|AR_SREV_SCORPION
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_SCORPION))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AR_SREV_SCORPION
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if defined(AH_SUPPORT_SCORPION) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AH_SUPPORT_POSEIDON
argument_list|)
end_if

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_POSEIDON))
end_define

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON_10
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_POSEIDON)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_POSEIDON_10))
end_define

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON_11
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_POSEIDON)&& \      (AH_PRIVATE((_ah))->ah_macRev == AR_SREV_REVISION_POSEIDON_11))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON_10
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON_11
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if defined(AH_SUPPORT_POSEIDON) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON_11_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((AH_PRIVATE((_ah))->ah_macVersion == AR_SREV_VERSION_POSEIDON)&& \      (AH_PRIVATE((_ah))->ah_macRev>= AR_SREV_REVISION_POSEIDON_11))
end_define

begin_define
define|#
directive|define
name|AR_SREV_POSEIDON_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_SREV_VERSION_POSEIDON)
end_define

begin_define
define|#
directive|define
name|AR_SREV_SOC
parameter_list|(
name|_ah
parameter_list|)
value|(AR_SREV_HORNET(_ah) || AR_SREV_POSEIDON(_ah) || AR_SREV_WASP(_ah))
end_define

begin_comment
comment|/* * Mask used to construct AAD for CCMP-AES * Cisco spec defined bits 0-3 as mask  * IEEE802.11w defined as bit 4. */
end_comment

begin_define
define|#
directive|define
name|AR_MFP_QOS_MASK_IEEE
value|0x10
end_define

begin_define
define|#
directive|define
name|AR_MFP_QOS_MASK_CISCO
value|0xf
end_define

begin_comment
comment|/* * frame control field mask: * 0 0 0 0 0 0 0 0 * | | | | | | | | _ Order            bit * | | | | | | | _ _ Protected Frame  bit * | | | | | | _ _ _ More data        bit * | | | | | _ _ _ _ Power management bit * | | | | _ _ _ _ _ Retry            bit * | | | _ _ _ _ _ _ More fragments   bit * | | _ _ _ _ _ _ _ FromDS           bit * | _ _ _ _ _ _ _ _ ToDS             bit */
end_comment

begin_define
define|#
directive|define
name|AR_AES_MUTE_MASK1_FC_MGMT_MFP
value|0xC7FF
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

