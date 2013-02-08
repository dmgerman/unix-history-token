begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2004 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5210REG_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5210REG_H
end_define

begin_comment
comment|/*  * Register defintions for the Atheros AR5210/5110 MAC/Basedband  * Processor for IEEE 802.11a 5-GHz Wireless LANs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ATHEROS
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ATHEROS
value|0x168c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_PRODUCT_ATHEROS_AR5210
value|0x0007
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_ATHEROS_AR5210_OLD
value|0x0004
end_define

begin_comment
comment|/* DMA Registers */
end_comment

begin_define
define|#
directive|define
name|AR_TXDP0
value|0x0000
end_define

begin_comment
comment|/* TX queue pointer 0 register */
end_comment

begin_define
define|#
directive|define
name|AR_TXDP1
value|0x0004
end_define

begin_comment
comment|/* TX queue pointer 1 register */
end_comment

begin_define
define|#
directive|define
name|AR_CR
value|0x0008
end_define

begin_comment
comment|/* Command register */
end_comment

begin_define
define|#
directive|define
name|AR_RXDP
value|0x000c
end_define

begin_comment
comment|/* RX queue descriptor ptr register */
end_comment

begin_define
define|#
directive|define
name|AR_CFG
value|0x0014
end_define

begin_comment
comment|/* Configuration and status register */
end_comment

begin_define
define|#
directive|define
name|AR_ISR
value|0x001c
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|AR_IMR
value|0x0020
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|AR_IER
value|0x0024
end_define

begin_comment
comment|/* Interrupt global enable register */
end_comment

begin_define
define|#
directive|define
name|AR_BCR
value|0x0028
end_define

begin_comment
comment|/* Beacon control register */
end_comment

begin_define
define|#
directive|define
name|AR_BSR
value|0x002c
end_define

begin_comment
comment|/* Beacon status register */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG
value|0x0030
end_define

begin_comment
comment|/* TX configuration register */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG
value|0x0034
end_define

begin_comment
comment|/* RX configuration register */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC
value|0x0040
end_define

begin_comment
comment|/* MIB control register */
end_comment

begin_define
define|#
directive|define
name|AR_TOPS
value|0x0044
end_define

begin_comment
comment|/* Timeout prescale register */
end_comment

begin_define
define|#
directive|define
name|AR_RXNOFRM
value|0x0048
end_define

begin_comment
comment|/* RX no frame timeout register */
end_comment

begin_define
define|#
directive|define
name|AR_TXNOFRM
value|0x004c
end_define

begin_comment
comment|/* TX no frame timeout register */
end_comment

begin_define
define|#
directive|define
name|AR_RPGTO
value|0x0050
end_define

begin_comment
comment|/* RX frame gap timeout register */
end_comment

begin_define
define|#
directive|define
name|AR_RFCNT
value|0x0054
end_define

begin_comment
comment|/* RX frame count limit register */
end_comment

begin_define
define|#
directive|define
name|AR_MISC
value|0x0058
end_define

begin_comment
comment|/* Misc control and status register */
end_comment

begin_define
define|#
directive|define
name|AR_RC
value|0x4000
end_define

begin_comment
comment|/* Reset control */
end_comment

begin_define
define|#
directive|define
name|AR_SCR
value|0x4004
end_define

begin_comment
comment|/* Sleep control */
end_comment

begin_define
define|#
directive|define
name|AR_INTPEND
value|0x4008
end_define

begin_comment
comment|/* Interrupt pending */
end_comment

begin_define
define|#
directive|define
name|AR_SFR
value|0x400c
end_define

begin_comment
comment|/* Force sleep */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG
value|0x4010
end_define

begin_comment
comment|/* PCI configuration */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR
value|0x4014
end_define

begin_comment
comment|/* GPIO configuration */
end_comment

begin_define
define|#
directive|define
name|AR_GPIODO
value|0x4018
end_define

begin_comment
comment|/* GPIO data output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIODI
value|0x401c
end_define

begin_comment
comment|/* GPIO data input */
end_comment

begin_define
define|#
directive|define
name|AR_SREV
value|0x4020
end_define

begin_comment
comment|/* Silicon revision */
end_comment

begin_comment
comment|/* EEPROM Access Registers */
end_comment

begin_define
define|#
directive|define
name|AR_EP_AIR_BASE
value|0x6000
end_define

begin_comment
comment|/* EEPROM access initiation regs base */
end_comment

begin_define
define|#
directive|define
name|AR_EP_AIR
parameter_list|(
name|n
parameter_list|)
value|(AR_EP_AIR_BASE + (n)*4)
end_define

begin_define
define|#
directive|define
name|AR_EP_RDATA
value|0x6800
end_define

begin_comment
comment|/* EEPROM read data register */
end_comment

begin_define
define|#
directive|define
name|AR_EP_STA
value|0x6c00
end_define

begin_comment
comment|/* EEPROM access status register */
end_comment

begin_comment
comment|/* PCU Registers */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID0
value|0x8000
end_define

begin_comment
comment|/* Lower 32bits of MAC address */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1
value|0x8004
end_define

begin_comment
comment|/* Upper 16bits of MAC address */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID0
value|0x8008
end_define

begin_comment
comment|/* Lower 32bits of BSSID */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1
value|0x800c
end_define

begin_comment
comment|/* Upper 16bits of BSSID */
end_comment

begin_define
define|#
directive|define
name|AR_SLOT_TIME
value|0x8010
end_define

begin_comment
comment|/* Length of a back-off */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT
value|0x8014
end_define

begin_comment
comment|/* Timeout to wait for ACK and CTS */
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR
value|0x8018
end_define

begin_comment
comment|/* Beacon RSSI warning threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_LMT
value|0x801c
end_define

begin_comment
comment|/* Short and long frame retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_USEC
value|0x8020
end_define

begin_comment
comment|/* Transmit latency */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON
value|0x8024
end_define

begin_comment
comment|/* Beacon control */
end_comment

begin_define
define|#
directive|define
name|AR_CFP_PERIOD
value|0x8028
end_define

begin_comment
comment|/* CFP period */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER0
value|0x802c
end_define

begin_comment
comment|/* Next beacon time */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER1
value|0x8030
end_define

begin_comment
comment|/* Next DMA beacon alert time */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER2
value|0x8034
end_define

begin_comment
comment|/* Next software beacon alert time */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER3
value|0x8038
end_define

begin_comment
comment|/* Next ATIM window time */
end_comment

begin_define
define|#
directive|define
name|AR_IFS0
value|0x8040
end_define

begin_comment
comment|/* Protocol timers */
end_comment

begin_define
define|#
directive|define
name|AR_IFS1
value|0x8044
end_define

begin_comment
comment|/* Protocol time and control */
end_comment

begin_define
define|#
directive|define
name|AR_CFP_DUR
value|0x8048
end_define

begin_comment
comment|/* Maximum CFP duration */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER
value|0x804c
end_define

begin_comment
comment|/* Receive filter */
end_comment

begin_define
define|#
directive|define
name|AR_MCAST_FIL0
value|0x8050
end_define

begin_comment
comment|/* Lower 32bits of mcast filter mask */
end_comment

begin_define
define|#
directive|define
name|AR_MCAST_FIL1
value|0x8054
end_define

begin_comment
comment|/* Upper 16bits of mcast filter mask */
end_comment

begin_define
define|#
directive|define
name|AR_TX_MASK0
value|0x8058
end_define

begin_comment
comment|/* Lower 32bits of TX mask */
end_comment

begin_define
define|#
directive|define
name|AR_TX_MASK1
value|0x805c
end_define

begin_comment
comment|/* Upper 16bits of TX mask */
end_comment

begin_define
define|#
directive|define
name|AR_CLR_TMASK
value|0x8060
end_define

begin_comment
comment|/* Clear TX mask */
end_comment

begin_define
define|#
directive|define
name|AR_TRIG_LEV
value|0x8064
end_define

begin_comment
comment|/* Minimum FIFO fill level before TX */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW
value|0x8068
end_define

begin_comment
comment|/* PCU control */
end_comment

begin_define
define|#
directive|define
name|AR_TSF_L32
value|0x806c
end_define

begin_comment
comment|/* Lower 32bits of local clock */
end_comment

begin_define
define|#
directive|define
name|AR_TSF_U32
value|0x8070
end_define

begin_comment
comment|/* Upper 32bits of local clock */
end_comment

begin_define
define|#
directive|define
name|AR_LAST_TSTP
value|0x8080
end_define

begin_comment
comment|/* Lower 32bits of last beacon tstamp */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_CNT
value|0x8084
end_define

begin_comment
comment|/* Current short or long retry cnt */
end_comment

begin_define
define|#
directive|define
name|AR_BACKOFF
value|0x8088
end_define

begin_comment
comment|/* Back-off status */
end_comment

begin_define
define|#
directive|define
name|AR_NAV
value|0x808c
end_define

begin_comment
comment|/* Current NAV value */
end_comment

begin_define
define|#
directive|define
name|AR_RTS_OK
value|0x8090
end_define

begin_comment
comment|/* RTS success counter */
end_comment

begin_define
define|#
directive|define
name|AR_RTS_FAIL
value|0x8094
end_define

begin_comment
comment|/* RTS failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_ACK_FAIL
value|0x8098
end_define

begin_comment
comment|/* ACK failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_FCS_FAIL
value|0x809c
end_define

begin_comment
comment|/* FCS failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_CNT
value|0x80a0
end_define

begin_comment
comment|/* Valid beacon counter */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_0
value|0x9000
end_define

begin_comment
comment|/* Encryption key table */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE_0 + ((n)*32))
end_define

begin_define
define|#
directive|define
name|AR_CR_TXE0
value|0x00000001
end_define

begin_comment
comment|/* TX queue 0 enable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_TXE1
value|0x00000002
end_define

begin_comment
comment|/* TX queue 1 enable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_RXE
value|0x00000004
end_define

begin_comment
comment|/* RX enable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_TXD0
value|0x00000008
end_define

begin_comment
comment|/* TX queue 0 disable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_TXD1
value|0x00000010
end_define

begin_comment
comment|/* TX queue 1 disable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_RXD
value|0x00000020
end_define

begin_comment
comment|/* RX disable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_SWI
value|0x00000040
end_define

begin_comment
comment|/* software interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_CR_BITS
define|\
value|"\20\1TXE0\2TXE1\3RXE\4TXD0\5TXD1\6RXD\7SWI"
end_define

begin_define
define|#
directive|define
name|AR_CFG_SWTD
value|0x00000001
end_define

begin_comment
comment|/* BE for TX desc */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWTB
value|0x00000002
end_define

begin_comment
comment|/* BE for TX data */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRD
value|0x00000004
end_define

begin_comment
comment|/* BE for RX desc */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRB
value|0x00000008
end_define

begin_comment
comment|/* BE for RX data */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRG
value|0x00000010
end_define

begin_comment
comment|/* BE for registers */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_EEBS
value|0x00000200
end_define

begin_comment
comment|/* EEPROM busy */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_TXCNT
value|0x00007800
end_define

begin_comment
comment|/* number of TX desc in Q */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_TXCNT_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_CFG_TXFSTAT
value|0x00008000
end_define

begin_comment
comment|/* TX DMA status */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_TXFSTRT
value|0x00010000
end_define

begin_comment
comment|/* re-enable TX DMA */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_BITS
define|\
value|"\20\1SWTD\2SWTB\3SWRD\4SWRB\5SWRG\14EEBS\17TXFSTAT\20TXFSTRT"
end_define

begin_define
define|#
directive|define
name|AR_ISR_RXOK_INT
value|0x00000001
end_define

begin_comment
comment|/* RX frame OK */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXDESC_INT
value|0x00000002
end_define

begin_comment
comment|/* RX intr request */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXERR_INT
value|0x00000004
end_define

begin_comment
comment|/* RX error */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXNOFRM_INT
value|0x00000008
end_define

begin_comment
comment|/* no frame received */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXEOL_INT
value|0x00000010
end_define

begin_comment
comment|/* RX desc empty */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXORN_INT
value|0x00000020
end_define

begin_comment
comment|/* RX fifo overrun */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXOK_INT
value|0x00000040
end_define

begin_comment
comment|/* TX frame OK */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXDESC_INT
value|0x00000080
end_define

begin_comment
comment|/* TX intr request */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXERR_INT
value|0x00000100
end_define

begin_comment
comment|/* TX error */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXNOFRM_INT
value|0x00000200
end_define

begin_comment
comment|/* no frame transmitted */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXEOL_INT
value|0x00000400
end_define

begin_comment
comment|/* TX desc empty */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXURN_INT
value|0x00000800
end_define

begin_comment
comment|/* TX fifo underrun */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_MIB_INT
value|0x00001000
end_define

begin_comment
comment|/* MIB interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_SWI_INT
value|0x00002000
end_define

begin_comment
comment|/* software interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXPHY_INT
value|0x00004000
end_define

begin_comment
comment|/* PHY RX error */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXKCM_INT
value|0x00008000
end_define

begin_comment
comment|/* Key cache miss */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_SWBA_INT
value|0x00010000
end_define

begin_comment
comment|/* software beacon alert */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BRSSI_INT
value|0x00020000
end_define

begin_comment
comment|/* beacon threshold */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BMISS_INT
value|0x00040000
end_define

begin_comment
comment|/* beacon missed */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_MCABT_INT
value|0x00100000
end_define

begin_comment
comment|/* master cycle abort */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_SSERR_INT
value|0x00200000
end_define

begin_comment
comment|/* SERR on PCI */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_DPERR_INT
value|0x00400000
end_define

begin_comment
comment|/* Parity error on PCI */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_GPIO_INT
value|0x01000000
end_define

begin_comment
comment|/* GPIO interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BITS
define|\
value|"\20\1RXOK\2RXDESC\3RXERR\4RXNOFM\5RXEOL\6RXORN\7TXOK\10TXDESC"\ 	"\11TXERR\12TXNOFRM\13TXEOL\14TXURN\15MIB\16SWI\17RXPHY\20RXKCM"\ 	"\21SWBA\22BRSSI\23BMISS\24MCABT\25SSERR\26DPERR\27GPIO"
end_define

begin_define
define|#
directive|define
name|AR_IMR_RXOK_INT
value|0x00000001
end_define

begin_comment
comment|/* RX frame OK */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXDESC_INT
value|0x00000002
end_define

begin_comment
comment|/* RX intr request */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXERR_INT
value|0x00000004
end_define

begin_comment
comment|/* RX error */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXNOFRM_INT
value|0x00000008
end_define

begin_comment
comment|/* no frame received */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXEOL_INT
value|0x00000010
end_define

begin_comment
comment|/* RX desc empty */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXORN_INT
value|0x00000020
end_define

begin_comment
comment|/* RX fifo overrun */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXOK_INT
value|0x00000040
end_define

begin_comment
comment|/* TX frame OK */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXDESC_INT
value|0x00000080
end_define

begin_comment
comment|/* TX intr request */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXERR_INT
value|0x00000100
end_define

begin_comment
comment|/* TX error */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXNOFRM_INT
value|0x00000200
end_define

begin_comment
comment|/* no frame transmitted */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXEOL_INT
value|0x00000400
end_define

begin_comment
comment|/* TX desc empty */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXURN_INT
value|0x00000800
end_define

begin_comment
comment|/* TX fifo underrun */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_MIB_INT
value|0x00001000
end_define

begin_comment
comment|/* MIB interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_SWI_INT
value|0x00002000
end_define

begin_comment
comment|/* software interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXPHY_INT
value|0x00004000
end_define

begin_comment
comment|/* PHY RX error */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXKCM_INT
value|0x00008000
end_define

begin_comment
comment|/* Key cache miss */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_SWBA_INT
value|0x00010000
end_define

begin_comment
comment|/* software beacon alert */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BRSSI_INT
value|0x00020000
end_define

begin_comment
comment|/* beacon threshold */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BMISS_INT
value|0x00040000
end_define

begin_comment
comment|/* beacon missed */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_MCABT_INT
value|0x00100000
end_define

begin_comment
comment|/* master cycle abort */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_SSERR_INT
value|0x00200000
end_define

begin_comment
comment|/* SERR on PCI */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_DPERR_INT
value|0x00400000
end_define

begin_comment
comment|/* Parity error on PCI */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_GPIO_INT
value|0x01000000
end_define

begin_comment
comment|/* GPIO interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BITS
value|AR_ISR_BITS
end_define

begin_define
define|#
directive|define
name|AR_IER_DISABLE
value|0x00000000
end_define

begin_comment
comment|/* pseudo-flag */
end_comment

begin_define
define|#
directive|define
name|AR_IER_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* global interrupt enable */
end_comment

begin_define
define|#
directive|define
name|AR_IER_BITS
value|"\20\1ENABLE"
end_define

begin_define
define|#
directive|define
name|AR_BCR_BCMD
value|0x00000001
end_define

begin_comment
comment|/* ad hoc beacon mode */
end_comment

begin_define
define|#
directive|define
name|AR_BCR_BDMAE
value|0x00000002
end_define

begin_comment
comment|/* beacon DMA enable */
end_comment

begin_define
define|#
directive|define
name|AR_BCR_TQ1FV
value|0x00000004
end_define

begin_comment
comment|/* use TXQ1 for non-beacon */
end_comment

begin_define
define|#
directive|define
name|AR_BCR_TQ1V
value|0x00000008
end_define

begin_comment
comment|/* TXQ1 valid for beacon */
end_comment

begin_define
define|#
directive|define
name|AR_BCR_BCGET
value|0x00000010
end_define

begin_comment
comment|/* force a beacon fetch */
end_comment

begin_define
define|#
directive|define
name|AR_BCR_BITS
value|"\20\1BCMD\2BDMAE\3TQ1FV\4TQ1V\5BCGET"
end_define

begin_define
define|#
directive|define
name|AR_BSR_BDLYSW
value|0x00000001
end_define

begin_comment
comment|/* software beacon delay */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_BDLYDMA
value|0x00000002
end_define

begin_comment
comment|/* DMA beacon delay */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_TXQ1F
value|0x00000004
end_define

begin_comment
comment|/* TXQ1 fetch */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_ATIMDLY
value|0x00000008
end_define

begin_comment
comment|/* ATIM delay */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_SNPBCMD
value|0x00000100
end_define

begin_comment
comment|/* snapshot of BCMD */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_SNPBDMAE
value|0x00000200
end_define

begin_comment
comment|/* snapshot of BDMAE */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_SNPTQ1FV
value|0x00000400
end_define

begin_comment
comment|/* snapshot of TQ1FV */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_SNPTQ1V
value|0x00000800
end_define

begin_comment
comment|/* snapshot of TQ1V */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_SNAPPEDBCRVALID
value|0x00001000
end_define

begin_comment
comment|/* snapshot of BCR are valid */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_SWBA_CNT
value|0x00ff0000
end_define

begin_comment
comment|/* software beacon alert cnt */
end_comment

begin_define
define|#
directive|define
name|AR_BSR_BITS
define|\
value|"\20\1BDLYSW\2BDLYDMA\3TXQ1F\4ATIMDLY\11SNPBCMD\12SNPBDMAE"\ 	"\13SNPTQ1FV\14SNPTQ1V\15SNAPPEDBCRVALID"
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_SDMAMR
value|0x00000007
end_define

begin_comment
comment|/* DMA burst size 2^(2+x) */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_TXFSTP
value|0x00000008
end_define

begin_comment
comment|/* Stop TX DMA on filtered */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_TXFULL
value|0x00000070
end_define

begin_comment
comment|/* TX DMA desc Q full thresh */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_TXCONT_EN
value|0x00000080
end_define

begin_comment
comment|/* Enable continuous TX mode */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_BITS
value|"\20\3TXFSTP\7TXCONT_EN"
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_SDMAMW
value|0x00000007
end_define

begin_comment
comment|/* DMA burst size 2^(2+x) */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG_ZLFDMA
value|0x00000010
end_define

begin_comment
comment|/* enable zero length DMA */
end_comment

begin_comment
comment|/* DMA sizes used for both AR_TXCFG_SDMAMR and AR_RXCFG_SDMAMW */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_4B
value|0
end_define

begin_comment
comment|/* DMA size 4 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_8B
value|1
end_define

begin_comment
comment|/* DMA size 8 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_16B
value|2
end_define

begin_comment
comment|/* DMA size 16 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_32B
value|3
end_define

begin_comment
comment|/* DMA size 32 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_64B
value|4
end_define

begin_comment
comment|/* DMA size 64 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_128B
value|5
end_define

begin_comment
comment|/* DMA size 128 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_256B
value|6
end_define

begin_comment
comment|/* DMA size 256 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_512B
value|7
end_define

begin_comment
comment|/* DMA size 512 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_COW
value|0x00000001
end_define

begin_comment
comment|/* counter overflow warning */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_FMC
value|0x00000002
end_define

begin_comment
comment|/* freeze MIB counters */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_CMC
value|0x00000004
end_define

begin_comment
comment|/* clear MIB counters */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_MCS
value|0x00000008
end_define

begin_comment
comment|/* MIB counter strobe */
end_comment

begin_define
define|#
directive|define
name|AR_RFCNT_RFCL
value|0x0000000f
end_define

begin_comment
comment|/* RX frame count limit */
end_comment

begin_define
define|#
directive|define
name|AR_MISC_LED_DECAY
value|0x001c0000
end_define

begin_comment
comment|/* LED decay rate */
end_comment

begin_define
define|#
directive|define
name|AR_MISC_LED_BLINK
value|0x00e00000
end_define

begin_comment
comment|/* LED blink rate */
end_comment

begin_define
define|#
directive|define
name|AR_RC_RPCU
value|0x00000001
end_define

begin_comment
comment|/* PCU Warm Reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_RDMA
value|0x00000002
end_define

begin_comment
comment|/* DMA Warm Reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_RMAC
value|0x00000004
end_define

begin_comment
comment|/* MAC Warm Reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_RPHY
value|0x00000008
end_define

begin_comment
comment|/* PHY Warm Reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_RPCI
value|0x00000010
end_define

begin_comment
comment|/* PCI Core Warm Reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_BITS
value|"\20\1RPCU\2RDMA\3RMAC\4RPHY\5RPCI"
end_define

begin_define
define|#
directive|define
name|AR_SCR_SLDUR
value|0x0000ffff
end_define

begin_comment
comment|/* sleep duration */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE
value|0x00030000
end_define

begin_comment
comment|/* sleep enable */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_S
value|16
end_define

begin_comment
comment|/*  * The previous values for the following three defines were:  *  *	AR_SCR_SLE_WAKE		0x00000000  *	AR_SCR_SLE_SLP		0x00010000  *	AR_SCR_SLE_ALLOW	0x00020000  *  * However, these have been pre-shifted with AR_SCR_SLE_S.  The  * OS_REG_READ() macro would attempt to shift them again, effectively  * shifting out any of the set bits completely.  */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_WAKE
value|0
end_define

begin_comment
comment|/* force wake */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_SLP
value|1
end_define

begin_comment
comment|/* force sleep */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_ALLOW
value|2
end_define

begin_comment
comment|/* allow to control sleep */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_BITS
value|"\20\20SLE_SLP\21SLE_ALLOW"
end_define

begin_define
define|#
directive|define
name|AR_INTPEND_IP
value|0x00000001
end_define

begin_comment
comment|/* interrupt pending */
end_comment

begin_define
define|#
directive|define
name|AR_INTPEND_BITS
value|"\20\1IP"
end_define

begin_define
define|#
directive|define
name|AR_SFR_SF
value|0x00000001
end_define

begin_comment
comment|/* force sleep immediately */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROMSEL
value|0x00000001
end_define

begin_comment
comment|/* EEPROM access enable */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_CLKRUNEN
value|0x00000004
end_define

begin_comment
comment|/* CLKRUN enable */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LED_PEND
value|0x00000020
end_define

begin_comment
comment|/* LED for assoc pending */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LED_ACT
value|0x00000040
end_define

begin_comment
comment|/* LED for assoc active */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_SL_INTEN
value|0x00000800
end_define

begin_comment
comment|/* Enable sleep intr */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LED_BCTL
value|0x00001000
end_define

begin_comment
comment|/* LED blink for local act */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_SL_INPEN
value|0x00002800
end_define

begin_comment
comment|/* sleep even intr pending */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_SPWR_DN
value|0x00010000
end_define

begin_comment
comment|/* sleep indication */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_BITS
define|\
value|"\20\1EEPROMSEL\3CLKRUNEN\5LED_PEND\6LED_ACT\13SL_INTEN"\ 	"\14LED_BCTL\20SPWR_DN"
end_define

begin_define
define|#
directive|define
name|AR_GPIOCR_IN
parameter_list|(
name|n
parameter_list|)
value|(0<<((n)*2))
end_define

begin_comment
comment|/* input-only */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_OUT0
parameter_list|(
name|n
parameter_list|)
value|(1<<((n)*2))
end_define

begin_comment
comment|/* output-only if GPIODO = 0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_OUT1
parameter_list|(
name|n
parameter_list|)
value|(2<<((n)*2))
end_define

begin_comment
comment|/* output-only if GPIODO = 1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_OUT
parameter_list|(
name|n
parameter_list|)
value|(3<<((n)*2))
end_define

begin_comment
comment|/* always output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_ALL
parameter_list|(
name|n
parameter_list|)
value|(3<<((n)*2))
end_define

begin_comment
comment|/* all bits for pin */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SEL
parameter_list|(
name|n
parameter_list|)
value|((n)<<12)
end_define

begin_comment
comment|/* GPIO interrupt pin select */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_ENA
value|0x00008000
end_define

begin_comment
comment|/* Enable GPIO interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SELL
value|0x00000000
end_define

begin_comment
comment|/* Interrupt if pin is low */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SELH
value|0x00010000
end_define

begin_comment
comment|/* Interrupt if pin is high */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_CRETE
value|4
end_define

begin_comment
comment|/* Crete 1st version */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_CRETE_MS
value|5
end_define

begin_comment
comment|/* Crete FCS version */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_CRETE_23
value|8
end_define

begin_comment
comment|/* Crete version 2.3 */
end_comment

begin_define
define|#
directive|define
name|AR_EP_STA_RDERR
value|0x00000001
end_define

begin_comment
comment|/* read error */
end_comment

begin_define
define|#
directive|define
name|AR_EP_STA_RDCMPLT
value|0x00000002
end_define

begin_comment
comment|/* read complete */
end_comment

begin_define
define|#
directive|define
name|AR_EP_STA_WRERR
value|0x00000004
end_define

begin_comment
comment|/* write error */
end_comment

begin_define
define|#
directive|define
name|AR_EP_STA_WRCMPLT
value|0x00000008
end_define

begin_comment
comment|/* write complete */
end_comment

begin_define
define|#
directive|define
name|AR_EP_STA_BITS
define|\
value|"\20\1RDERR\2RDCMPLT\3WRERR\4WRCMPLT"
end_define

begin_define
define|#
directive|define
name|AR_STA_ID1_AP
value|0x00010000
end_define

begin_comment
comment|/* Access Point Operation */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_ADHOC
value|0x00020000
end_define

begin_comment
comment|/* ad hoc Operation */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PWR_SV
value|0x00040000
end_define

begin_comment
comment|/* power save report enable */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_NO_KEYSRCH
value|0x00080000
end_define

begin_comment
comment|/* key table search disable */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_NO_PSPOLL
value|0x00100000
end_define

begin_comment
comment|/* auto PS-POLL disable */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PCF
value|0x00200000
end_define

begin_comment
comment|/* PCF observation enable */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_DESC_ANTENNA
value|0x00400000
end_define

begin_comment
comment|/* use antenna in TX desc */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_DEFAULT_ANTENNA
value|0x00800000
end_define

begin_comment
comment|/* toggle default antenna */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_ACKCTS_6MB
value|0x01000000
end_define

begin_comment
comment|/* use 6Mbps for ACK/CTS */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_BITS
define|\
value|"\20\20AP\21ADHOC\22PWR_SV\23NO_KEYSRCH\24NO_PSPOLL\25PCF"\ 	"\26DESC_ANTENNA\27DEFAULT_ANTENNA\30ACKCTS_6MB"
end_define

begin_define
define|#
directive|define
name|AR_BSS_ID1_AID
value|0xffff0000
end_define

begin_comment
comment|/* association ID */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1_AID_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_TIME_OUT_ACK
value|0x00001fff
end_define

begin_comment
comment|/* ACK timeout */
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
value|0x1fff0000
end_define

begin_comment
comment|/* CTS timeout */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT_CTS_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RSSI_THR_BM_THR
value|0x00000700
end_define

begin_comment
comment|/* missed beacon threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR_BM_THR_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RETRY_LMT_SH_RETRY
value|0x0000000f
end_define

begin_comment
comment|/* short frame retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_LMT_SH_RETRY_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RETRY_LMT_LG_RETRY
value|0x000000f0
end_define

begin_comment
comment|/* long frame retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_LMT_LG_RETRY_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_RETRY_LMT_SSH_RETRY
value|0x00003f00
end_define

begin_comment
comment|/* short station retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_LMT_SSH_RETRY_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RETRY_LMT_SLG_RETRY
value|0x000fc000
end_define

begin_comment
comment|/* long station retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_LMT_SLG_RETRY_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_RETRY_LMT_CW_MIN
value|0x3ff00000
end_define

begin_comment
comment|/* minimum contention window */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_LMT_CW_MIN_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_USEC_1
value|0x0000007f
end_define

begin_comment
comment|/* number of clk in 1us */
end_comment

begin_define
define|#
directive|define
name|AR_USEC_1_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_USEC_32
value|0x00003f80
end_define

begin_comment
comment|/* number of 32MHz clk in 1us */
end_comment

begin_define
define|#
directive|define
name|AR_USEC_32_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_USEC_TX_LATENCY
value|0x000fc000
end_define

begin_comment
comment|/* transmit latency in us */
end_comment

begin_define
define|#
directive|define
name|AR_USEC_TX_LATENCY_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_USEC_RX_LATENCY
value|0x03f00000
end_define

begin_comment
comment|/* receive latency in us */
end_comment

begin_define
define|#
directive|define
name|AR_USEC_RX_LATENCY_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_BEACON_PERIOD
value|0x0000ffff
end_define

begin_comment
comment|/* beacon period in TU/ms */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_PERIOD_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_BEACON_TIM
value|0x007f0000
end_define

begin_comment
comment|/* byte offset */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_TIM_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_BEACON_EN
value|0x00800000
end_define

begin_comment
comment|/* beacon transmission enable */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_RESET_TSF
value|0x01000000
end_define

begin_comment
comment|/* TSF reset oneshot */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_BITS
value|"\20\27ENABLE\30RESET_TSF"
end_define

begin_define
define|#
directive|define
name|AR_IFS0_SIFS
value|0x000007ff
end_define

begin_comment
comment|/* SIFS in core clock cycles */
end_comment

begin_define
define|#
directive|define
name|AR_IFS0_SIFS_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_IFS0_DIFS
value|0x007ff800
end_define

begin_comment
comment|/* DIFS in core clock cycles */
end_comment

begin_define
define|#
directive|define
name|AR_IFS0_DIFS_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_IFS1_PIFS
value|0x00000fff
end_define

begin_comment
comment|/* Programmable IFS */
end_comment

begin_define
define|#
directive|define
name|AR_IFS1_PIFS_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_IFS1_EIFS
value|0x03fff000
end_define

begin_comment
comment|/* EIFS in core clock cycles */
end_comment

begin_define
define|#
directive|define
name|AR_IFS1_EIFS_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_IFS1_CS_EN
value|0x04000000
end_define

begin_comment
comment|/* carrier sense enable */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_UNICAST
value|0x00000001
end_define

begin_comment
comment|/* unicast frame enable */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_MULTICAST
value|0x00000002
end_define

begin_comment
comment|/* multicast frame enable */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_BROADCAST
value|0x00000004
end_define

begin_comment
comment|/* broadcast frame enable */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_CONTROL
value|0x00000008
end_define

begin_comment
comment|/* control frame enable */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_BEACON
value|0x00000010
end_define

begin_comment
comment|/* beacon frame enable */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_PROMISCUOUS
value|0x00000020
end_define

begin_comment
comment|/* promiscuous receive enable */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_BITS
define|\
value|"\20\1UCAST\2MCAST\3BCAST\4CONTROL\5BEACON\6PROMISC"
end_define

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_WEP_ACK
value|0x00000001
end_define

begin_comment
comment|/* disable ACK if no key found*/
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_ACK
value|0x00000002
end_define

begin_comment
comment|/* disable ACK generation */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_CTS
value|0x00000004
end_define

begin_comment
comment|/* disable CTS generation */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_ENC
value|0x00000008
end_define

begin_comment
comment|/* encryption disable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_DEC
value|0x00000010
end_define

begin_comment
comment|/* decryption disable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_TX
value|0x00000020
end_define

begin_comment
comment|/* TX disable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_RX
value|0x00000040
end_define

begin_comment
comment|/* RX disable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_LOOP_BACK
value|0x00000080
end_define

begin_comment
comment|/* TX data loopback enable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_CORR_FCS
value|0x00000100
end_define

begin_comment
comment|/* corrupt FCS enable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_CHAN_INFO
value|0x00000200
end_define

begin_comment
comment|/* channel information enable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_EN_SCRAM_SEED
value|0x00000400
end_define

begin_comment
comment|/* use fixed scrambler seed */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_SCVRAM_SEED
value|0x0003f800
end_define

begin_comment
comment|/* fixed scrambler seed */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_SEQ_INC
value|0x00040000
end_define

begin_comment
comment|/* seq increment disable */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_FRAME_NV0
value|0x00080000
end_define

begin_comment
comment|/* accept frame vers != 0 */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_CRYPTO
value|(AR_DIAG_SW_DIS_ENC | AR_DIAG_SW_DIS_DEC)
end_define

begin_define
define|#
directive|define
name|AR_DIAG_SW_BITS
define|\
value|"\20\1DIS_WEP_ACK\2DIS_ACK\3DIS_CTS\4DIS_ENC\5DIS_DEC\6DIS_TX"\ 	"\7DIS_RX\10LOOP_BACK\11CORR_FCS\12CHAN_INFO\13EN_SCRAM_SEED"\ 	"\22DIS_SEQ_INC\24FRAME_NV0"
end_define

begin_define
define|#
directive|define
name|AR_RETRY_CNT_SSH
value|0x0000003f
end_define

begin_comment
comment|/* current short retry count */
end_comment

begin_define
define|#
directive|define
name|AR_RETRY_CNT_SLG
value|0x00000fc0
end_define

begin_comment
comment|/* current long retry count */
end_comment

begin_define
define|#
directive|define
name|AR_BACKOFF_CW
value|0x000003ff
end_define

begin_comment
comment|/* current contention window */
end_comment

begin_define
define|#
directive|define
name|AR_BACKOFF_CNT
value|0x03ff0000
end_define

begin_comment
comment|/* backoff count */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY0
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 0)
end_define

begin_comment
comment|/* key bit 0-31 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY1
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 4)
end_define

begin_comment
comment|/* key bit 32-47 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY2
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 8)
end_define

begin_comment
comment|/* key bit 48-79 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY3
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 12)
end_define

begin_comment
comment|/* key bit 80-95 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY4
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 16)
end_define

begin_comment
comment|/* key bit 96-127 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 20)
end_define

begin_comment
comment|/* key type */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_40
value|0x00000000
end_define

begin_comment
comment|/* 40 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_104
value|0x00000001
end_define

begin_comment
comment|/* 104 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_128
value|0x00000003
end_define

begin_comment
comment|/* 128 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MAC0
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 24)
end_define

begin_comment
comment|/* MAC address 1-32 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MAC1
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 28)
end_define

begin_comment
comment|/* MAC address 33-47 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_VALID
value|0x00008000
end_define

begin_comment
comment|/* key and MAC address valid */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5210REG_H */
end_comment

end_unit

