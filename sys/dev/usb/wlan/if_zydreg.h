begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_zydreg.h,v 1.19 2006/11/30 19:28:07 damien Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: if_zydreg.h,v 1.2 2007/06/16 11:18:45 kiyohara Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006 by Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2006 by Florian Stoehr<ich@florian-stoehr.de>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * ZyDAS ZD1211/ZD1211B USB WLAN driver.  */
end_comment

begin_define
define|#
directive|define
name|ZYD_CR_GPI_EN
value|0x9418
end_define

begin_define
define|#
directive|define
name|ZYD_CR_RADIO_PD
value|0x942c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_RF2948_PD
value|0x942c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_EN_PS_MANUAL_AGC
value|0x943c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_CONFIG_PHILIPS
value|0x9440
end_define

begin_define
define|#
directive|define
name|ZYD_CR_I2C_WRITE
value|0x9444
end_define

begin_define
define|#
directive|define
name|ZYD_CR_SA2400_SER_RP
value|0x9448
end_define

begin_define
define|#
directive|define
name|ZYD_CR_RADIO_PE
value|0x9458
end_define

begin_define
define|#
directive|define
name|ZYD_CR_RST_BUS_MASTER
value|0x945c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_RFCFG
value|0x9464
end_define

begin_define
define|#
directive|define
name|ZYD_CR_HSTSCHG
value|0x946c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_PHY_ON
value|0x9474
end_define

begin_define
define|#
directive|define
name|ZYD_CR_RX_DELAY
value|0x9478
end_define

begin_define
define|#
directive|define
name|ZYD_CR_RX_PE_DELAY
value|0x947c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_GPIO_1
value|0x9490
end_define

begin_define
define|#
directive|define
name|ZYD_CR_GPIO_2
value|0x9494
end_define

begin_define
define|#
directive|define
name|ZYD_CR_EnZYD_CRyBufMux
value|0x94a8
end_define

begin_define
define|#
directive|define
name|ZYD_CR_PS_CTRL
value|0x9500
end_define

begin_define
define|#
directive|define
name|ZYD_CR_ADDA_PWR_DWN
value|0x9504
end_define

begin_define
define|#
directive|define
name|ZYD_CR_ADDA_MBIAS_WT
value|0x9508
end_define

begin_define
define|#
directive|define
name|ZYD_CR_INTERRUPT
value|0x9510
end_define

begin_define
define|#
directive|define
name|ZYD_CR_MAC_PS_STATE
value|0x950c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_ATIM_WND_PERIOD
value|0x951c
end_define

begin_define
define|#
directive|define
name|ZYD_CR_BCN_INTERVAL
value|0x9520
end_define

begin_define
define|#
directive|define
name|ZYD_CR_PRE_TBTT
value|0x9524
end_define

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_MACADRL
value|0x9610
end_define

begin_comment
comment|/* MAC address (low) */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_MACADRH
value|0x9614
end_define

begin_comment
comment|/* MAC address (high) */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BSSADRL
value|0x9618
end_define

begin_comment
comment|/* BSS address (low) */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BSSADRH
value|0x961c
end_define

begin_comment
comment|/* BSS address (high) */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BCNCFG
value|0x9620
end_define

begin_comment
comment|/* BCN configuration */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_GHTBL
value|0x9624
end_define

begin_comment
comment|/* Group hash table (low) */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_GHTBH
value|0x9628
end_define

begin_comment
comment|/* Group hash table (high) */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_TIMEOUT
value|0x962c
end_define

begin_comment
comment|/* Rx timeout value */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BAS_RATE
value|0x9630
end_define

begin_comment
comment|/* Basic rate setting */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_MAN_RATE
value|0x9634
end_define

begin_comment
comment|/* Mandatory rate setting */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RTSCTSRATE
value|0x9638
end_define

begin_comment
comment|/* RTS CTS rate */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BACKOFF_PROTECT
value|0x963c
end_define

begin_comment
comment|/* Backoff protection */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_THRESHOLD
value|0x9640
end_define

begin_comment
comment|/* Rx threshold */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_TX_PE_CONTROL
value|0x9644
end_define

begin_comment
comment|/* Tx_PE control */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_AFTER_PNP
value|0x9648
end_define

begin_comment
comment|/* After PnP */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_PE_DELAY
value|0x964c
end_define

begin_comment
comment|/* Rx_pe delay */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_ADDR2_L
value|0x9650
end_define

begin_comment
comment|/* RX address2 (low)    */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_ADDR2_H
value|0x9654
end_define

begin_comment
comment|/* RX address2 (high) */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_SIFS_ACK_TIME
value|0x9658
end_define

begin_comment
comment|/* Dynamic SIFS ack time */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_PHY_DELAY
value|0x9660
end_define

begin_comment
comment|/* PHY delay */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_PHY_DELAY2
value|0x966c
end_define

begin_comment
comment|/* PHY delay */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BCNFIFO
value|0x9670
end_define

begin_comment
comment|/* Beacon FIFO I/O port */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_SNIFFER
value|0x9674
end_define

begin_comment
comment|/* Sniffer on/off */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_ENCRYPTION_TYPE
value|0x9678
end_define

begin_comment
comment|/* Encryption type */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RETRY
value|0x967c
end_define

begin_comment
comment|/* Retry time */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_MISC
value|0x9680
end_define

begin_comment
comment|/* Misc */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_STMACHINESTAT
value|0x9684
end_define

begin_comment
comment|/* State machine status */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_TX_UNDERRUN_CNT
value|0x9688
end_define

begin_comment
comment|/* TX underrun counter */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RXFILTER
value|0x968c
end_define

begin_comment
comment|/* Send to host settings */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_ACK_EXT
value|0x9690
end_define

begin_comment
comment|/* Acknowledge extension */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BCNFIFOST
value|0x9694
end_define

begin_comment
comment|/* BCN FIFO set and status */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_DIFS_EIFS_SIFS
value|0x9698
end_define

begin_comment
comment|/* DIFS, EIFS& SIFS settings */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_TIMEOUT_CNT
value|0x969c
end_define

begin_comment
comment|/* RX timeout count */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_TOTAL_FRAME
value|0x96a0
end_define

begin_comment
comment|/* RX total frame count */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_CRC32_CNT
value|0x96a4
end_define

begin_comment
comment|/* RX CRC32 frame count */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_CRC16_CNT
value|0x96a8
end_define

begin_comment
comment|/* RX CRC16 frame count */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_UDEC
value|0x96ac
end_define

begin_comment
comment|/* RX unicast decr. error count */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_OVERRUN_CNT
value|0x96b0
end_define

begin_comment
comment|/* RX FIFO overrun count */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_MDEC
value|0x96bc
end_define

begin_comment
comment|/* RX multicast decr. err. cnt. */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_NAV_TCR
value|0x96c4
end_define

begin_comment
comment|/* NAV timer count read */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_BACKOFF_ST_RD
value|0x96c8
end_define

begin_comment
comment|/* Backoff status read */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_DM_RETRY_CNT_RD
value|0x96cc
end_define

begin_comment
comment|/* DM retry count read */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RX_ACR
value|0x96d0
end_define

begin_comment
comment|/* RX arbitration count read    */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_TX_CCR
value|0x96d4
end_define

begin_comment
comment|/* Tx complete count read */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_TCB_ADDR
value|0x96e8
end_define

begin_comment
comment|/* Current PCI process TCP addr */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_RCB_ADDR
value|0x96ec
end_define

begin_comment
comment|/* Next RCB address */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_CONT_WIN_LIMIT
value|0x96f0
end_define

begin_comment
comment|/* Contention window limit */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_TX_PKT
value|0x96f4
end_define

begin_comment
comment|/* Tx total packet count read */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_DL_CTRL
value|0x96f8
end_define

begin_comment
comment|/* Download control */
end_comment

begin_define
define|#
directive|define
name|ZYD_MAC_CAM_MODE
value|0x9700
end_define

begin_comment
comment|/* CAM: Continuous Access Mode */
end_comment

begin_define
define|#
directive|define
name|ZYD_MACB_TXPWR_CTL1
value|0x9b00
end_define

begin_define
define|#
directive|define
name|ZYD_MACB_TXPWR_CTL2
value|0x9b04
end_define

begin_define
define|#
directive|define
name|ZYD_MACB_TXPWR_CTL3
value|0x9b08
end_define

begin_define
define|#
directive|define
name|ZYD_MACB_TXPWR_CTL4
value|0x9b0c
end_define

begin_define
define|#
directive|define
name|ZYD_MACB_AIFS_CTL1
value|0x9b10
end_define

begin_define
define|#
directive|define
name|ZYD_MACB_AIFS_CTL2
value|0x9b14
end_define

begin_define
define|#
directive|define
name|ZYD_MACB_TXOP
value|0x9b20
end_define

begin_define
define|#
directive|define
name|ZYD_MACB_MAX_RETRY
value|0x9b28
end_define

begin_comment
comment|/*  * Miscellaneous registers.  */
end_comment

begin_define
define|#
directive|define
name|ZYD_FIRMWARE_START_ADDR
value|0xee00
end_define

begin_define
define|#
directive|define
name|ZYD_FIRMWARE_BASE_ADDR
value|0xee1d
end_define

begin_comment
comment|/* Firmware base address */
end_comment

begin_comment
comment|/*  * EEPROM registers.  */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_START_HEAD
value|0xf800
end_define

begin_comment
comment|/* EEPROM start */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_SUBID
value|0xf817
end_define

begin_define
define|#
directive|define
name|ZYD_EEPROM_POD
value|0xf819
end_define

begin_define
define|#
directive|define
name|ZYD_EEPROM_MAC_ADDR_P1
value|0xf81b
end_define

begin_comment
comment|/* Part 1 of the MAC address */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_MAC_ADDR_P2
value|0xf81d
end_define

begin_comment
comment|/* Part 2 of the MAC address */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_PWR_CAL
value|0xf81f
end_define

begin_comment
comment|/* Calibration */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_PWR_INT
value|0xf827
end_define

begin_comment
comment|/* Calibration */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_ALLOWEDCHAN
value|0xf82f
end_define

begin_comment
comment|/* Allowed CH mask, 1 bit each */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_DEVICE_VER
value|0xf837
end_define

begin_comment
comment|/* Device version */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_PHY_REG
value|0xf83c
end_define

begin_comment
comment|/* PHY registers */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_36M_CAL
value|0xf83f
end_define

begin_comment
comment|/* Calibration */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_11A_INT
value|0xf847
end_define

begin_comment
comment|/* Interpolation */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_48M_CAL
value|0xf84f
end_define

begin_comment
comment|/* Calibration */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_48M_INT
value|0xf857
end_define

begin_comment
comment|/* Interpolation */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_54M_CAL
value|0xf85f
end_define

begin_comment
comment|/* Calibration */
end_comment

begin_define
define|#
directive|define
name|ZYD_EEPROM_54M_INT
value|0xf867
end_define

begin_comment
comment|/* Interpolation */
end_comment

begin_comment
comment|/*  * Firmware registers offsets (relative to fwbase).  */
end_comment

begin_define
define|#
directive|define
name|ZYD_FW_FIRMWARE_REV
value|0x0000
end_define

begin_comment
comment|/* Firmware version */
end_comment

begin_define
define|#
directive|define
name|ZYD_FW_USB_SPEED
value|0x0001
end_define

begin_comment
comment|/* USB speed (!=0 if highspeed) */
end_comment

begin_define
define|#
directive|define
name|ZYD_FW_FIX_TX_RATE
value|0x0002
end_define

begin_comment
comment|/* Fixed TX rate */
end_comment

begin_define
define|#
directive|define
name|ZYD_FW_LINK_STATUS
value|0x0003
end_define

begin_define
define|#
directive|define
name|ZYD_FW_SOFT_RESET
value|0x0004
end_define

begin_define
define|#
directive|define
name|ZYD_FW_FLASH_CHK
value|0x0005
end_define

begin_comment
comment|/* possible flags for register ZYD_FW_LINK_STATUS */
end_comment

begin_define
define|#
directive|define
name|ZYD_LED1
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ZYD_LED2
value|(1<< 9)
end_define

begin_comment
comment|/*  * RF IDs.  */
end_comment

begin_define
define|#
directive|define
name|ZYD_RF_UW2451
value|0x2
end_define

begin_comment
comment|/* not supported yet */
end_comment

begin_define
define|#
directive|define
name|ZYD_RF_UCHIP
value|0x3
end_define

begin_comment
comment|/* not supported yet */
end_comment

begin_define
define|#
directive|define
name|ZYD_RF_AL2230
value|0x4
end_define

begin_define
define|#
directive|define
name|ZYD_RF_AL7230B
value|0x5
end_define

begin_define
define|#
directive|define
name|ZYD_RF_THETA
value|0x6
end_define

begin_comment
comment|/* not supported yet */
end_comment

begin_define
define|#
directive|define
name|ZYD_RF_AL2210
value|0x7
end_define

begin_define
define|#
directive|define
name|ZYD_RF_MAXIM_NEW
value|0x8
end_define

begin_define
define|#
directive|define
name|ZYD_RF_GCT
value|0x9
end_define

begin_define
define|#
directive|define
name|ZYD_RF_AL2230S
value|0xa
end_define

begin_comment
comment|/* not supported yet */
end_comment

begin_define
define|#
directive|define
name|ZYD_RF_RALINK
value|0xb
end_define

begin_comment
comment|/* not supported yet */
end_comment

begin_define
define|#
directive|define
name|ZYD_RF_INTERSIL
value|0xc
end_define

begin_comment
comment|/* not supported yet */
end_comment

begin_define
define|#
directive|define
name|ZYD_RF_RFMD
value|0xd
end_define

begin_define
define|#
directive|define
name|ZYD_RF_MAXIM_NEW2
value|0xe
end_define

begin_define
define|#
directive|define
name|ZYD_RF_PHILIPS
value|0xf
end_define

begin_comment
comment|/* not supported yet */
end_comment

begin_comment
comment|/*  * PHY registers (8 bits, not documented).  */
end_comment

begin_define
define|#
directive|define
name|ZYD_CR0
value|0x9000
end_define

begin_define
define|#
directive|define
name|ZYD_CR1
value|0x9004
end_define

begin_define
define|#
directive|define
name|ZYD_CR2
value|0x9008
end_define

begin_define
define|#
directive|define
name|ZYD_CR3
value|0x900c
end_define

begin_define
define|#
directive|define
name|ZYD_CR5
value|0x9010
end_define

begin_define
define|#
directive|define
name|ZYD_CR6
value|0x9014
end_define

begin_define
define|#
directive|define
name|ZYD_CR7
value|0x9018
end_define

begin_define
define|#
directive|define
name|ZYD_CR8
value|0x901c
end_define

begin_define
define|#
directive|define
name|ZYD_CR4
value|0x9020
end_define

begin_define
define|#
directive|define
name|ZYD_CR9
value|0x9024
end_define

begin_define
define|#
directive|define
name|ZYD_CR10
value|0x9028
end_define

begin_define
define|#
directive|define
name|ZYD_CR11
value|0x902c
end_define

begin_define
define|#
directive|define
name|ZYD_CR12
value|0x9030
end_define

begin_define
define|#
directive|define
name|ZYD_CR13
value|0x9034
end_define

begin_define
define|#
directive|define
name|ZYD_CR14
value|0x9038
end_define

begin_define
define|#
directive|define
name|ZYD_CR15
value|0x903c
end_define

begin_define
define|#
directive|define
name|ZYD_CR16
value|0x9040
end_define

begin_define
define|#
directive|define
name|ZYD_CR17
value|0x9044
end_define

begin_define
define|#
directive|define
name|ZYD_CR18
value|0x9048
end_define

begin_define
define|#
directive|define
name|ZYD_CR19
value|0x904c
end_define

begin_define
define|#
directive|define
name|ZYD_CR20
value|0x9050
end_define

begin_define
define|#
directive|define
name|ZYD_CR21
value|0x9054
end_define

begin_define
define|#
directive|define
name|ZYD_CR22
value|0x9058
end_define

begin_define
define|#
directive|define
name|ZYD_CR23
value|0x905c
end_define

begin_define
define|#
directive|define
name|ZYD_CR24
value|0x9060
end_define

begin_define
define|#
directive|define
name|ZYD_CR25
value|0x9064
end_define

begin_define
define|#
directive|define
name|ZYD_CR26
value|0x9068
end_define

begin_define
define|#
directive|define
name|ZYD_CR27
value|0x906c
end_define

begin_define
define|#
directive|define
name|ZYD_CR28
value|0x9070
end_define

begin_define
define|#
directive|define
name|ZYD_CR29
value|0x9074
end_define

begin_define
define|#
directive|define
name|ZYD_CR30
value|0x9078
end_define

begin_define
define|#
directive|define
name|ZYD_CR31
value|0x907c
end_define

begin_define
define|#
directive|define
name|ZYD_CR32
value|0x9080
end_define

begin_define
define|#
directive|define
name|ZYD_CR33
value|0x9084
end_define

begin_define
define|#
directive|define
name|ZYD_CR34
value|0x9088
end_define

begin_define
define|#
directive|define
name|ZYD_CR35
value|0x908c
end_define

begin_define
define|#
directive|define
name|ZYD_CR36
value|0x9090
end_define

begin_define
define|#
directive|define
name|ZYD_CR37
value|0x9094
end_define

begin_define
define|#
directive|define
name|ZYD_CR38
value|0x9098
end_define

begin_define
define|#
directive|define
name|ZYD_CR39
value|0x909c
end_define

begin_define
define|#
directive|define
name|ZYD_CR40
value|0x90a0
end_define

begin_define
define|#
directive|define
name|ZYD_CR41
value|0x90a4
end_define

begin_define
define|#
directive|define
name|ZYD_CR42
value|0x90a8
end_define

begin_define
define|#
directive|define
name|ZYD_CR43
value|0x90ac
end_define

begin_define
define|#
directive|define
name|ZYD_CR44
value|0x90b0
end_define

begin_define
define|#
directive|define
name|ZYD_CR45
value|0x90b4
end_define

begin_define
define|#
directive|define
name|ZYD_CR46
value|0x90b8
end_define

begin_define
define|#
directive|define
name|ZYD_CR47
value|0x90bc
end_define

begin_define
define|#
directive|define
name|ZYD_CR48
value|0x90c0
end_define

begin_define
define|#
directive|define
name|ZYD_CR49
value|0x90c4
end_define

begin_define
define|#
directive|define
name|ZYD_CR50
value|0x90c8
end_define

begin_define
define|#
directive|define
name|ZYD_CR51
value|0x90cc
end_define

begin_define
define|#
directive|define
name|ZYD_CR52
value|0x90d0
end_define

begin_define
define|#
directive|define
name|ZYD_CR53
value|0x90d4
end_define

begin_define
define|#
directive|define
name|ZYD_CR54
value|0x90d8
end_define

begin_define
define|#
directive|define
name|ZYD_CR55
value|0x90dc
end_define

begin_define
define|#
directive|define
name|ZYD_CR56
value|0x90e0
end_define

begin_define
define|#
directive|define
name|ZYD_CR57
value|0x90e4
end_define

begin_define
define|#
directive|define
name|ZYD_CR58
value|0x90e8
end_define

begin_define
define|#
directive|define
name|ZYD_CR59
value|0x90ec
end_define

begin_define
define|#
directive|define
name|ZYD_CR60
value|0x90f0
end_define

begin_define
define|#
directive|define
name|ZYD_CR61
value|0x90f4
end_define

begin_define
define|#
directive|define
name|ZYD_CR62
value|0x90f8
end_define

begin_define
define|#
directive|define
name|ZYD_CR63
value|0x90fc
end_define

begin_define
define|#
directive|define
name|ZYD_CR64
value|0x9100
end_define

begin_define
define|#
directive|define
name|ZYD_CR65
value|0x9104
end_define

begin_define
define|#
directive|define
name|ZYD_CR66
value|0x9108
end_define

begin_define
define|#
directive|define
name|ZYD_CR67
value|0x910c
end_define

begin_define
define|#
directive|define
name|ZYD_CR68
value|0x9110
end_define

begin_define
define|#
directive|define
name|ZYD_CR69
value|0x9114
end_define

begin_define
define|#
directive|define
name|ZYD_CR70
value|0x9118
end_define

begin_define
define|#
directive|define
name|ZYD_CR71
value|0x911c
end_define

begin_define
define|#
directive|define
name|ZYD_CR72
value|0x9120
end_define

begin_define
define|#
directive|define
name|ZYD_CR73
value|0x9124
end_define

begin_define
define|#
directive|define
name|ZYD_CR74
value|0x9128
end_define

begin_define
define|#
directive|define
name|ZYD_CR75
value|0x912c
end_define

begin_define
define|#
directive|define
name|ZYD_CR76
value|0x9130
end_define

begin_define
define|#
directive|define
name|ZYD_CR77
value|0x9134
end_define

begin_define
define|#
directive|define
name|ZYD_CR78
value|0x9138
end_define

begin_define
define|#
directive|define
name|ZYD_CR79
value|0x913c
end_define

begin_define
define|#
directive|define
name|ZYD_CR80
value|0x9140
end_define

begin_define
define|#
directive|define
name|ZYD_CR81
value|0x9144
end_define

begin_define
define|#
directive|define
name|ZYD_CR82
value|0x9148
end_define

begin_define
define|#
directive|define
name|ZYD_CR83
value|0x914c
end_define

begin_define
define|#
directive|define
name|ZYD_CR84
value|0x9150
end_define

begin_define
define|#
directive|define
name|ZYD_CR85
value|0x9154
end_define

begin_define
define|#
directive|define
name|ZYD_CR86
value|0x9158
end_define

begin_define
define|#
directive|define
name|ZYD_CR87
value|0x915c
end_define

begin_define
define|#
directive|define
name|ZYD_CR88
value|0x9160
end_define

begin_define
define|#
directive|define
name|ZYD_CR89
value|0x9164
end_define

begin_define
define|#
directive|define
name|ZYD_CR90
value|0x9168
end_define

begin_define
define|#
directive|define
name|ZYD_CR91
value|0x916c
end_define

begin_define
define|#
directive|define
name|ZYD_CR92
value|0x9170
end_define

begin_define
define|#
directive|define
name|ZYD_CR93
value|0x9174
end_define

begin_define
define|#
directive|define
name|ZYD_CR94
value|0x9178
end_define

begin_define
define|#
directive|define
name|ZYD_CR95
value|0x917c
end_define

begin_define
define|#
directive|define
name|ZYD_CR96
value|0x9180
end_define

begin_define
define|#
directive|define
name|ZYD_CR97
value|0x9184
end_define

begin_define
define|#
directive|define
name|ZYD_CR98
value|0x9188
end_define

begin_define
define|#
directive|define
name|ZYD_CR99
value|0x918c
end_define

begin_define
define|#
directive|define
name|ZYD_CR100
value|0x9190
end_define

begin_define
define|#
directive|define
name|ZYD_CR101
value|0x9194
end_define

begin_define
define|#
directive|define
name|ZYD_CR102
value|0x9198
end_define

begin_define
define|#
directive|define
name|ZYD_CR103
value|0x919c
end_define

begin_define
define|#
directive|define
name|ZYD_CR104
value|0x91a0
end_define

begin_define
define|#
directive|define
name|ZYD_CR105
value|0x91a4
end_define

begin_define
define|#
directive|define
name|ZYD_CR106
value|0x91a8
end_define

begin_define
define|#
directive|define
name|ZYD_CR107
value|0x91ac
end_define

begin_define
define|#
directive|define
name|ZYD_CR108
value|0x91b0
end_define

begin_define
define|#
directive|define
name|ZYD_CR109
value|0x91b4
end_define

begin_define
define|#
directive|define
name|ZYD_CR110
value|0x91b8
end_define

begin_define
define|#
directive|define
name|ZYD_CR111
value|0x91bc
end_define

begin_define
define|#
directive|define
name|ZYD_CR112
value|0x91c0
end_define

begin_define
define|#
directive|define
name|ZYD_CR113
value|0x91c4
end_define

begin_define
define|#
directive|define
name|ZYD_CR114
value|0x91c8
end_define

begin_define
define|#
directive|define
name|ZYD_CR115
value|0x91cc
end_define

begin_define
define|#
directive|define
name|ZYD_CR116
value|0x91d0
end_define

begin_define
define|#
directive|define
name|ZYD_CR117
value|0x91d4
end_define

begin_define
define|#
directive|define
name|ZYD_CR118
value|0x91d8
end_define

begin_define
define|#
directive|define
name|ZYD_CR119
value|0x91dc
end_define

begin_define
define|#
directive|define
name|ZYD_CR120
value|0x91e0
end_define

begin_define
define|#
directive|define
name|ZYD_CR121
value|0x91e4
end_define

begin_define
define|#
directive|define
name|ZYD_CR122
value|0x91e8
end_define

begin_define
define|#
directive|define
name|ZYD_CR123
value|0x91ec
end_define

begin_define
define|#
directive|define
name|ZYD_CR124
value|0x91f0
end_define

begin_define
define|#
directive|define
name|ZYD_CR125
value|0x91f4
end_define

begin_define
define|#
directive|define
name|ZYD_CR126
value|0x91f8
end_define

begin_define
define|#
directive|define
name|ZYD_CR127
value|0x91fc
end_define

begin_define
define|#
directive|define
name|ZYD_CR128
value|0x9200
end_define

begin_define
define|#
directive|define
name|ZYD_CR129
value|0x9204
end_define

begin_define
define|#
directive|define
name|ZYD_CR130
value|0x9208
end_define

begin_define
define|#
directive|define
name|ZYD_CR131
value|0x920c
end_define

begin_define
define|#
directive|define
name|ZYD_CR132
value|0x9210
end_define

begin_define
define|#
directive|define
name|ZYD_CR133
value|0x9214
end_define

begin_define
define|#
directive|define
name|ZYD_CR134
value|0x9218
end_define

begin_define
define|#
directive|define
name|ZYD_CR135
value|0x921c
end_define

begin_define
define|#
directive|define
name|ZYD_CR136
value|0x9220
end_define

begin_define
define|#
directive|define
name|ZYD_CR137
value|0x9224
end_define

begin_define
define|#
directive|define
name|ZYD_CR138
value|0x9228
end_define

begin_define
define|#
directive|define
name|ZYD_CR139
value|0x922c
end_define

begin_define
define|#
directive|define
name|ZYD_CR140
value|0x9230
end_define

begin_define
define|#
directive|define
name|ZYD_CR141
value|0x9234
end_define

begin_define
define|#
directive|define
name|ZYD_CR142
value|0x9238
end_define

begin_define
define|#
directive|define
name|ZYD_CR143
value|0x923c
end_define

begin_define
define|#
directive|define
name|ZYD_CR144
value|0x9240
end_define

begin_define
define|#
directive|define
name|ZYD_CR145
value|0x9244
end_define

begin_define
define|#
directive|define
name|ZYD_CR146
value|0x9248
end_define

begin_define
define|#
directive|define
name|ZYD_CR147
value|0x924c
end_define

begin_define
define|#
directive|define
name|ZYD_CR148
value|0x9250
end_define

begin_define
define|#
directive|define
name|ZYD_CR149
value|0x9254
end_define

begin_define
define|#
directive|define
name|ZYD_CR150
value|0x9258
end_define

begin_define
define|#
directive|define
name|ZYD_CR151
value|0x925c
end_define

begin_define
define|#
directive|define
name|ZYD_CR152
value|0x9260
end_define

begin_define
define|#
directive|define
name|ZYD_CR153
value|0x9264
end_define

begin_define
define|#
directive|define
name|ZYD_CR154
value|0x9268
end_define

begin_define
define|#
directive|define
name|ZYD_CR155
value|0x926c
end_define

begin_define
define|#
directive|define
name|ZYD_CR156
value|0x9270
end_define

begin_define
define|#
directive|define
name|ZYD_CR157
value|0x9274
end_define

begin_define
define|#
directive|define
name|ZYD_CR158
value|0x9278
end_define

begin_define
define|#
directive|define
name|ZYD_CR159
value|0x927c
end_define

begin_define
define|#
directive|define
name|ZYD_CR160
value|0x9280
end_define

begin_define
define|#
directive|define
name|ZYD_CR161
value|0x9284
end_define

begin_define
define|#
directive|define
name|ZYD_CR162
value|0x9288
end_define

begin_define
define|#
directive|define
name|ZYD_CR163
value|0x928c
end_define

begin_define
define|#
directive|define
name|ZYD_CR164
value|0x9290
end_define

begin_define
define|#
directive|define
name|ZYD_CR165
value|0x9294
end_define

begin_define
define|#
directive|define
name|ZYD_CR166
value|0x9298
end_define

begin_define
define|#
directive|define
name|ZYD_CR167
value|0x929c
end_define

begin_define
define|#
directive|define
name|ZYD_CR168
value|0x92a0
end_define

begin_define
define|#
directive|define
name|ZYD_CR169
value|0x92a4
end_define

begin_define
define|#
directive|define
name|ZYD_CR170
value|0x92a8
end_define

begin_define
define|#
directive|define
name|ZYD_CR171
value|0x92ac
end_define

begin_define
define|#
directive|define
name|ZYD_CR172
value|0x92b0
end_define

begin_define
define|#
directive|define
name|ZYD_CR173
value|0x92b4
end_define

begin_define
define|#
directive|define
name|ZYD_CR174
value|0x92b8
end_define

begin_define
define|#
directive|define
name|ZYD_CR175
value|0x92bc
end_define

begin_define
define|#
directive|define
name|ZYD_CR176
value|0x92c0
end_define

begin_define
define|#
directive|define
name|ZYD_CR177
value|0x92c4
end_define

begin_define
define|#
directive|define
name|ZYD_CR178
value|0x92c8
end_define

begin_define
define|#
directive|define
name|ZYD_CR179
value|0x92cc
end_define

begin_define
define|#
directive|define
name|ZYD_CR180
value|0x92d0
end_define

begin_define
define|#
directive|define
name|ZYD_CR181
value|0x92d4
end_define

begin_define
define|#
directive|define
name|ZYD_CR182
value|0x92d8
end_define

begin_define
define|#
directive|define
name|ZYD_CR183
value|0x92dc
end_define

begin_define
define|#
directive|define
name|ZYD_CR184
value|0x92e0
end_define

begin_define
define|#
directive|define
name|ZYD_CR185
value|0x92e4
end_define

begin_define
define|#
directive|define
name|ZYD_CR186
value|0x92e8
end_define

begin_define
define|#
directive|define
name|ZYD_CR187
value|0x92ec
end_define

begin_define
define|#
directive|define
name|ZYD_CR188
value|0x92f0
end_define

begin_define
define|#
directive|define
name|ZYD_CR189
value|0x92f4
end_define

begin_define
define|#
directive|define
name|ZYD_CR190
value|0x92f8
end_define

begin_define
define|#
directive|define
name|ZYD_CR191
value|0x92fc
end_define

begin_define
define|#
directive|define
name|ZYD_CR192
value|0x9300
end_define

begin_define
define|#
directive|define
name|ZYD_CR193
value|0x9304
end_define

begin_define
define|#
directive|define
name|ZYD_CR194
value|0x9308
end_define

begin_define
define|#
directive|define
name|ZYD_CR195
value|0x930c
end_define

begin_define
define|#
directive|define
name|ZYD_CR196
value|0x9310
end_define

begin_define
define|#
directive|define
name|ZYD_CR197
value|0x9314
end_define

begin_define
define|#
directive|define
name|ZYD_CR198
value|0x9318
end_define

begin_define
define|#
directive|define
name|ZYD_CR199
value|0x931c
end_define

begin_define
define|#
directive|define
name|ZYD_CR200
value|0x9320
end_define

begin_define
define|#
directive|define
name|ZYD_CR201
value|0x9324
end_define

begin_define
define|#
directive|define
name|ZYD_CR202
value|0x9328
end_define

begin_define
define|#
directive|define
name|ZYD_CR203
value|0x932c
end_define

begin_define
define|#
directive|define
name|ZYD_CR204
value|0x9330
end_define

begin_define
define|#
directive|define
name|ZYD_CR205
value|0x9334
end_define

begin_define
define|#
directive|define
name|ZYD_CR206
value|0x9338
end_define

begin_define
define|#
directive|define
name|ZYD_CR207
value|0x933c
end_define

begin_define
define|#
directive|define
name|ZYD_CR208
value|0x9340
end_define

begin_define
define|#
directive|define
name|ZYD_CR209
value|0x9344
end_define

begin_define
define|#
directive|define
name|ZYD_CR210
value|0x9348
end_define

begin_define
define|#
directive|define
name|ZYD_CR211
value|0x934c
end_define

begin_define
define|#
directive|define
name|ZYD_CR212
value|0x9350
end_define

begin_define
define|#
directive|define
name|ZYD_CR213
value|0x9354
end_define

begin_define
define|#
directive|define
name|ZYD_CR214
value|0x9358
end_define

begin_define
define|#
directive|define
name|ZYD_CR215
value|0x935c
end_define

begin_define
define|#
directive|define
name|ZYD_CR216
value|0x9360
end_define

begin_define
define|#
directive|define
name|ZYD_CR217
value|0x9364
end_define

begin_define
define|#
directive|define
name|ZYD_CR218
value|0x9368
end_define

begin_define
define|#
directive|define
name|ZYD_CR219
value|0x936c
end_define

begin_define
define|#
directive|define
name|ZYD_CR220
value|0x9370
end_define

begin_define
define|#
directive|define
name|ZYD_CR221
value|0x9374
end_define

begin_define
define|#
directive|define
name|ZYD_CR222
value|0x9378
end_define

begin_define
define|#
directive|define
name|ZYD_CR223
value|0x937c
end_define

begin_define
define|#
directive|define
name|ZYD_CR224
value|0x9380
end_define

begin_define
define|#
directive|define
name|ZYD_CR225
value|0x9384
end_define

begin_define
define|#
directive|define
name|ZYD_CR226
value|0x9388
end_define

begin_define
define|#
directive|define
name|ZYD_CR227
value|0x938c
end_define

begin_define
define|#
directive|define
name|ZYD_CR228
value|0x9390
end_define

begin_define
define|#
directive|define
name|ZYD_CR229
value|0x9394
end_define

begin_define
define|#
directive|define
name|ZYD_CR230
value|0x9398
end_define

begin_define
define|#
directive|define
name|ZYD_CR231
value|0x939c
end_define

begin_define
define|#
directive|define
name|ZYD_CR232
value|0x93a0
end_define

begin_define
define|#
directive|define
name|ZYD_CR233
value|0x93a4
end_define

begin_define
define|#
directive|define
name|ZYD_CR234
value|0x93a8
end_define

begin_define
define|#
directive|define
name|ZYD_CR235
value|0x93ac
end_define

begin_define
define|#
directive|define
name|ZYD_CR236
value|0x93b0
end_define

begin_define
define|#
directive|define
name|ZYD_CR240
value|0x93c0
end_define

begin_define
define|#
directive|define
name|ZYD_CR241
value|0x93c4
end_define

begin_define
define|#
directive|define
name|ZYD_CR242
value|0x93c8
end_define

begin_define
define|#
directive|define
name|ZYD_CR243
value|0x93cc
end_define

begin_define
define|#
directive|define
name|ZYD_CR244
value|0x93d0
end_define

begin_define
define|#
directive|define
name|ZYD_CR245
value|0x93d4
end_define

begin_define
define|#
directive|define
name|ZYD_CR251
value|0x93ec
end_define

begin_define
define|#
directive|define
name|ZYD_CR252
value|0x93f0
end_define

begin_define
define|#
directive|define
name|ZYD_CR253
value|0x93f4
end_define

begin_define
define|#
directive|define
name|ZYD_CR254
value|0x93f8
end_define

begin_define
define|#
directive|define
name|ZYD_CR255
value|0x93fc
end_define

begin_comment
comment|/* copied nearly verbatim from the Linux driver rewrite */
end_comment

begin_define
define|#
directive|define
name|ZYD_DEF_PHY
define|\
value|{									\ 	{ ZYD_CR0,   0x0a }, { ZYD_CR1,   0x06 }, { ZYD_CR2,   0x26 },	\ 	{ ZYD_CR3,   0x38 }, { ZYD_CR4,   0x80 }, { ZYD_CR9,   0xa0 },	\ 	{ ZYD_CR10,  0x81 }, { ZYD_CR11,  0x00 }, { ZYD_CR12,  0x7f },	\ 	{ ZYD_CR13,  0x8c }, { ZYD_CR14,  0x80 }, { ZYD_CR15,  0x3d },	\ 	{ ZYD_CR16,  0x20 }, { ZYD_CR17,  0x1e }, { ZYD_CR18,  0x0a },	\ 	{ ZYD_CR19,  0x48 }, { ZYD_CR20,  0x0c }, { ZYD_CR21,  0x0c },	\ 	{ ZYD_CR22,  0x23 }, { ZYD_CR23,  0x90 }, { ZYD_CR24,  0x14 },	\ 	{ ZYD_CR25,  0x40 }, { ZYD_CR26,  0x10 }, { ZYD_CR27,  0x19 },	\ 	{ ZYD_CR28,  0x7f }, { ZYD_CR29,  0x80 }, { ZYD_CR30,  0x4b },	\ 	{ ZYD_CR31,  0x60 }, { ZYD_CR32,  0x43 }, { ZYD_CR33,  0x08 },	\ 	{ ZYD_CR34,  0x06 }, { ZYD_CR35,  0x0a }, { ZYD_CR36,  0x00 },	\ 	{ ZYD_CR37,  0x00 }, { ZYD_CR38,  0x38 }, { ZYD_CR39,  0x0c },	\ 	{ ZYD_CR40,  0x84 }, { ZYD_CR41,  0x2a }, { ZYD_CR42,  0x80 },	\ 	{ ZYD_CR43,  0x10 }, { ZYD_CR44,  0x12 }, { ZYD_CR46,  0xff },	\ 	{ ZYD_CR47,  0x1e }, { ZYD_CR48,  0x26 }, { ZYD_CR49,  0x5b },	\ 	{ ZYD_CR64,  0xd0 }, { ZYD_CR65,  0x04 }, { ZYD_CR66,  0x58 },	\ 	{ ZYD_CR67,  0xc9 }, { ZYD_CR68,  0x88 }, { ZYD_CR69,  0x41 },	\ 	{ ZYD_CR70,  0x23 }, { ZYD_CR71,  0x10 }, { ZYD_CR72,  0xff },	\ 	{ ZYD_CR73,  0x32 }, { ZYD_CR74,  0x30 }, { ZYD_CR75,  0x65 },	\ 	{ ZYD_CR76,  0x41 }, { ZYD_CR77,  0x1b }, { ZYD_CR78,  0x30 },	\ 	{ ZYD_CR79,  0x68 }, { ZYD_CR80,  0x64 }, { ZYD_CR81,  0x64 },	\ 	{ ZYD_CR82,  0x00 }, { ZYD_CR83,  0x00 }, { ZYD_CR84,  0x00 },	\ 	{ ZYD_CR85,  0x02 }, { ZYD_CR86,  0x00 }, { ZYD_CR87,  0x00 },	\ 	{ ZYD_CR88,  0xff }, { ZYD_CR89,  0xfc }, { ZYD_CR90,  0x00 },	\ 	{ ZYD_CR91,  0x00 }, { ZYD_CR92,  0x00 }, { ZYD_CR93,  0x08 },	\ 	{ ZYD_CR94,  0x00 }, { ZYD_CR95,  0x00 }, { ZYD_CR96,  0xff },	\ 	{ ZYD_CR97,  0xe7 }, { ZYD_CR98,  0x00 }, { ZYD_CR99,  0x00 },	\ 	{ ZYD_CR100, 0x00 }, { ZYD_CR101, 0xae }, { ZYD_CR102, 0x02 },	\ 	{ ZYD_CR103, 0x00 }, { ZYD_CR104, 0x03 }, { ZYD_CR105, 0x65 },	\ 	{ ZYD_CR106, 0x04 }, { ZYD_CR107, 0x00 }, { ZYD_CR108, 0x0a },	\ 	{ ZYD_CR109, 0xaa }, { ZYD_CR110, 0xaa }, { ZYD_CR111, 0x25 },	\ 	{ ZYD_CR112, 0x25 }, { ZYD_CR113, 0x00 }, { ZYD_CR119, 0x1e },	\ 	{ ZYD_CR125, 0x90 }, { ZYD_CR126, 0x00 }, { ZYD_CR127, 0x00 },	\ 	{ ZYD_CR5,   0x00 }, { ZYD_CR6,   0x00 }, { ZYD_CR7,   0x00 },	\ 	{ ZYD_CR8,   0x00 }, { ZYD_CR9,   0x20 }, { ZYD_CR12,  0xf0 },	\ 	{ ZYD_CR20,  0x0e }, { ZYD_CR21,  0x0e }, { ZYD_CR27,  0x10 },	\ 	{ ZYD_CR44,  0x33 }, { ZYD_CR47,  0x1E }, { ZYD_CR83,  0x24 },	\ 	{ ZYD_CR84,  0x04 }, { ZYD_CR85,  0x00 }, { ZYD_CR86,  0x0C },	\ 	{ ZYD_CR87,  0x12 }, { ZYD_CR88,  0x0C }, { ZYD_CR89,  0x00 },	\ 	{ ZYD_CR90,  0x10 }, { ZYD_CR91,  0x08 }, { ZYD_CR93,  0x00 },	\ 	{ ZYD_CR94,  0x01 }, { ZYD_CR95,  0x00 }, { ZYD_CR96,  0x50 },	\ 	{ ZYD_CR97,  0x37 }, { ZYD_CR98,  0x35 }, { ZYD_CR101, 0x13 },	\ 	{ ZYD_CR102, 0x27 }, { ZYD_CR103, 0x27 }, { ZYD_CR104, 0x18 },	\ 	{ ZYD_CR105, 0x12 }, { ZYD_CR109, 0x27 }, { ZYD_CR110, 0x27 },	\ 	{ ZYD_CR111, 0x27 }, { ZYD_CR112, 0x27 }, { ZYD_CR113, 0x27 },	\ 	{ ZYD_CR114, 0x27 }, { ZYD_CR115, 0x26 }, { ZYD_CR116, 0x24 },	\ 	{ ZYD_CR117, 0xfc }, { ZYD_CR118, 0xfa }, { ZYD_CR120, 0x4f },	\ 	{ ZYD_CR125, 0xaa }, { ZYD_CR127, 0x03 }, { ZYD_CR128, 0x14 },	\ 	{ ZYD_CR129, 0x12 }, { ZYD_CR130, 0x10 }, { ZYD_CR131, 0x0C },	\ 	{ ZYD_CR136, 0xdf }, { ZYD_CR137, 0x40 }, { ZYD_CR138, 0xa0 },	\ 	{ ZYD_CR139, 0xb0 }, { ZYD_CR140, 0x99 }, { ZYD_CR141, 0x82 },	\ 	{ ZYD_CR142, 0x54 }, { ZYD_CR143, 0x1c }, { ZYD_CR144, 0x6c },	\ 	{ ZYD_CR147, 0x07 }, { ZYD_CR148, 0x4c }, { ZYD_CR149, 0x50 },	\ 	{ ZYD_CR150, 0x0e }, { ZYD_CR151, 0x18 }, { ZYD_CR160, 0xfe },	\ 	{ ZYD_CR161, 0xee }, { ZYD_CR162, 0xaa }, { ZYD_CR163, 0xfa },	\ 	{ ZYD_CR164, 0xfa }, { ZYD_CR165, 0xea }, { ZYD_CR166, 0xbe },	\ 	{ ZYD_CR167, 0xbe }, { ZYD_CR168, 0x6a }, { ZYD_CR169, 0xba },	\ 	{ ZYD_CR170, 0xba }, { ZYD_CR171, 0xba }, { ZYD_CR204, 0x7d },	\ 	{ ZYD_CR203, 0x30 }, { 0, 0}					\ }
end_define

begin_define
define|#
directive|define
name|ZYD_DEF_PHYB
define|\
value|{									\ 	{ ZYD_CR0,   0x14 }, { ZYD_CR1,   0x06 }, { ZYD_CR2,   0x26 },	\ 	{ ZYD_CR3,   0x38 }, { ZYD_CR4,   0x80 }, { ZYD_CR9,   0xe0 },	\ 	{ ZYD_CR10,  0x81 }, { ZYD_CR11,  0x00 }, { ZYD_CR12,  0xf0 },	\ 	{ ZYD_CR13,  0x8c }, { ZYD_CR14,  0x80 }, { ZYD_CR15,  0x3d },	\ 	{ ZYD_CR16,  0x20 }, { ZYD_CR17,  0x1e }, { ZYD_CR18,  0x0a },	\ 	{ ZYD_CR19,  0x48 }, { ZYD_CR20,  0x10 }, { ZYD_CR21,  0x0e },	\ 	{ ZYD_CR22,  0x23 }, { ZYD_CR23,  0x90 }, { ZYD_CR24,  0x14 },	\ 	{ ZYD_CR25,  0x40 }, { ZYD_CR26,  0x10 }, { ZYD_CR27,  0x10 },	\ 	{ ZYD_CR28,  0x7f }, { ZYD_CR29,  0x80 }, { ZYD_CR30,  0x4b },	\ 	{ ZYD_CR31,  0x60 }, { ZYD_CR32,  0x43 }, { ZYD_CR33,  0x08 },	\ 	{ ZYD_CR34,  0x06 }, { ZYD_CR35,  0x0a }, { ZYD_CR36,  0x00 },	\ 	{ ZYD_CR37,  0x00 }, { ZYD_CR38,  0x38 }, { ZYD_CR39,  0x0c },	\ 	{ ZYD_CR40,  0x84 }, { ZYD_CR41,  0x2a }, { ZYD_CR42,  0x80 },	\ 	{ ZYD_CR43,  0x10 }, { ZYD_CR44,  0x33 }, { ZYD_CR46,  0xff },	\ 	{ ZYD_CR47,  0x1E }, { ZYD_CR48,  0x26 }, { ZYD_CR49,  0x5b },	\ 	{ ZYD_CR64,  0xd0 }, { ZYD_CR65,  0x04 }, { ZYD_CR66,  0x58 },	\ 	{ ZYD_CR67,  0xc9 }, { ZYD_CR68,  0x88 }, { ZYD_CR69,  0x41 },	\ 	{ ZYD_CR70,  0x23 }, { ZYD_CR71,  0x10 }, { ZYD_CR72,  0xff },	\ 	{ ZYD_CR73,  0x32 }, { ZYD_CR74,  0x30 }, { ZYD_CR75,  0x65 },	\ 	{ ZYD_CR76,  0x41 }, { ZYD_CR77,  0x1b }, { ZYD_CR78,  0x30 },	\ 	{ ZYD_CR79,  0xf0 }, { ZYD_CR80,  0x64 }, { ZYD_CR81,  0x64 },	\ 	{ ZYD_CR82,  0x00 }, { ZYD_CR83,  0x24 }, { ZYD_CR84,  0x04 },	\ 	{ ZYD_CR85,  0x00 }, { ZYD_CR86,  0x0c }, { ZYD_CR87,  0x12 },	\ 	{ ZYD_CR88,  0x0c }, { ZYD_CR89,  0x00 }, { ZYD_CR90,  0x58 },	\ 	{ ZYD_CR91,  0x04 }, { ZYD_CR92,  0x00 }, { ZYD_CR93,  0x00 },	\ 	{ ZYD_CR94,  0x01 }, { ZYD_CR95,  0x20 }, { ZYD_CR96,  0x50 },	\ 	{ ZYD_CR97,  0x37 }, { ZYD_CR98,  0x35 }, { ZYD_CR99,  0x00 },	\ 	{ ZYD_CR100, 0x01 }, { ZYD_CR101, 0x13 }, { ZYD_CR102, 0x27 },	\ 	{ ZYD_CR103, 0x27 }, { ZYD_CR104, 0x18 }, { ZYD_CR105, 0x12 },	\ 	{ ZYD_CR106, 0x04 }, { ZYD_CR107, 0x00 }, { ZYD_CR108, 0x0a },	\ 	{ ZYD_CR109, 0x27 }, { ZYD_CR110, 0x27 }, { ZYD_CR111, 0x27 },	\ 	{ ZYD_CR112, 0x27 }, { ZYD_CR113, 0x27 }, { ZYD_CR114, 0x27 },	\ 	{ ZYD_CR115, 0x26 }, { ZYD_CR116, 0x24 }, { ZYD_CR117, 0xfc },	\ 	{ ZYD_CR118, 0xfa }, { ZYD_CR119, 0x1e }, { ZYD_CR125, 0x90 },	\ 	{ ZYD_CR126, 0x00 }, { ZYD_CR127, 0x00 }, { ZYD_CR128, 0x14 },	\ 	{ ZYD_CR129, 0x12 }, { ZYD_CR130, 0x10 }, { ZYD_CR131, 0x0c },	\ 	{ ZYD_CR136, 0xdf }, { ZYD_CR137, 0xa0 }, { ZYD_CR138, 0xa8 },	\ 	{ ZYD_CR139, 0xb4 }, { ZYD_CR140, 0x98 }, { ZYD_CR141, 0x82 },	\ 	{ ZYD_CR142, 0x53 }, { ZYD_CR143, 0x1c }, { ZYD_CR144, 0x6c },	\ 	{ ZYD_CR147, 0x07 }, { ZYD_CR148, 0x40 }, { ZYD_CR149, 0x40 },	\ 	{ ZYD_CR150, 0x14 }, { ZYD_CR151, 0x18 }, { ZYD_CR159, 0x70 },	\ 	{ ZYD_CR160, 0xfe }, { ZYD_CR161, 0xee }, { ZYD_CR162, 0xaa },	\ 	{ ZYD_CR163, 0xfa }, { ZYD_CR164, 0xfa }, { ZYD_CR165, 0xea },	\ 	{ ZYD_CR166, 0xbe }, { ZYD_CR167, 0xbe }, { ZYD_CR168, 0x6a },	\ 	{ ZYD_CR169, 0xba }, { ZYD_CR170, 0xba }, { ZYD_CR171, 0xba },	\ 	{ ZYD_CR204, 0x7d }, { ZYD_CR203, 0x30 },			\ 	{ 0, 0 }							\ }
end_define

begin_define
define|#
directive|define
name|ZYD_RFMD_PHY
define|\
value|{									\ 	{ ZYD_CR2,   0x1e }, { ZYD_CR9,   0x20 }, { ZYD_CR10,  0x89 },	\ 	{ ZYD_CR11,  0x00 }, { ZYD_CR15,  0xd0 }, { ZYD_CR17,  0x68 },	\ 	{ ZYD_CR19,  0x4a }, { ZYD_CR20,  0x0c }, { ZYD_CR21,  0x0e },	\ 	{ ZYD_CR23,  0x48 }, { ZYD_CR24,  0x14 }, { ZYD_CR26,  0x90 },	\ 	{ ZYD_CR27,  0x30 }, { ZYD_CR29,  0x20 }, { ZYD_CR31,  0xb2 },	\ 	{ ZYD_CR32,  0x43 }, { ZYD_CR33,  0x28 }, { ZYD_CR38,  0x30 },	\ 	{ ZYD_CR34,  0x0f }, { ZYD_CR35,  0xf0 }, { ZYD_CR41,  0x2a },	\ 	{ ZYD_CR46,  0x7f }, { ZYD_CR47,  0x1e }, { ZYD_CR51,  0xc5 },	\ 	{ ZYD_CR52,  0xc5 }, { ZYD_CR53,  0xc5 }, { ZYD_CR79,  0x58 },	\ 	{ ZYD_CR80,  0x30 }, { ZYD_CR81,  0x30 }, { ZYD_CR82,  0x00 },	\ 	{ ZYD_CR83,  0x24 }, { ZYD_CR84,  0x04 }, { ZYD_CR85,  0x00 },	\ 	{ ZYD_CR86,  0x10 }, { ZYD_CR87,  0x2a }, { ZYD_CR88,  0x10 },	\ 	{ ZYD_CR89,  0x24 }, { ZYD_CR90,  0x18 }, { ZYD_CR91,  0x00 },	\ 	{ ZYD_CR92,  0x0a }, { ZYD_CR93,  0x00 }, { ZYD_CR94,  0x01 },	\ 	{ ZYD_CR95,  0x00 }, { ZYD_CR96,  0x40 }, { ZYD_CR97,  0x37 },	\ 	{ ZYD_CR98,  0x05 }, { ZYD_CR99,  0x28 }, { ZYD_CR100, 0x00 },	\ 	{ ZYD_CR101, 0x13 }, { ZYD_CR102, 0x27 }, { ZYD_CR103, 0x27 },	\ 	{ ZYD_CR104, 0x18 }, { ZYD_CR105, 0x12 }, { ZYD_CR106, 0x1a },	\ 	{ ZYD_CR107, 0x24 }, { ZYD_CR108, 0x0a }, { ZYD_CR109, 0x13 },	\ 	{ ZYD_CR110, 0x2f }, { ZYD_CR111, 0x27 }, { ZYD_CR112, 0x27 },	\ 	{ ZYD_CR113, 0x27 }, { ZYD_CR114, 0x27 }, { ZYD_CR115, 0x40 },	\ 	{ ZYD_CR116, 0x40 }, { ZYD_CR117, 0xf0 }, { ZYD_CR118, 0xf0 },	\ 	{ ZYD_CR119, 0x16 }, { ZYD_CR122, 0x00 }, { ZYD_CR127, 0x03 },	\ 	{ ZYD_CR131, 0x08 }, { ZYD_CR138, 0x28 }, { ZYD_CR148, 0x44 },	\ 	{ ZYD_CR150, 0x10 }, { ZYD_CR169, 0xbb }, { ZYD_CR170, 0xbb }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_RFMD_RF
define|\
value|{									\ 	0x000007, 0x07dd43, 0x080959, 0x0e6666, 0x116a57, 0x17dd43,	\ 	0x1819f9, 0x1e6666, 0x214554, 0x25e7fa, 0x27fffa, 0x294128,	\ 	0x2c0000, 0x300000, 0x340000, 0x381e0f, 0x6c180f		\ }
end_define

begin_define
define|#
directive|define
name|ZYD_RFMD_CHANTABLE
define|\
value|{				\ 	{ 0x181979, 0x1e6666 },	\ 	{ 0x181989, 0x1e6666 },	\ 	{ 0x181999, 0x1e6666 },	\ 	{ 0x1819a9, 0x1e6666 },	\ 	{ 0x1819b9, 0x1e6666 },	\ 	{ 0x1819c9, 0x1e6666 },	\ 	{ 0x1819d9, 0x1e6666 },	\ 	{ 0x1819e9, 0x1e6666 },	\ 	{ 0x1819f9, 0x1e6666 },	\ 	{ 0x181a09, 0x1e6666 },	\ 	{ 0x181a19, 0x1e6666 },	\ 	{ 0x181a29, 0x1e6666 },	\ 	{ 0x181a39, 0x1e6666 },	\ 	{ 0x181a60, 0x1c0000 }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_PHY
define|\
value|{									\ 	{ ZYD_CR15,  0x20 }, { ZYD_CR23,  0x40 }, { ZYD_CR24,  0x20 },	\ 	{ ZYD_CR26,  0x11 }, { ZYD_CR28,  0x3e }, { ZYD_CR29,  0x00 },	\ 	{ ZYD_CR44,  0x33 }, { ZYD_CR106, 0x2a }, { ZYD_CR107, 0x1a },	\ 	{ ZYD_CR109, 0x09 }, { ZYD_CR110, 0x27 }, { ZYD_CR111, 0x2b },	\ 	{ ZYD_CR112, 0x2b }, { ZYD_CR119, 0x0a }, { ZYD_CR10,  0x89 },	\ 	{ ZYD_CR17,  0x28 }, { ZYD_CR26,  0x93 }, { ZYD_CR34,  0x30 },	\ 	{ ZYD_CR35,  0x3e }, { ZYD_CR41,  0x24 }, { ZYD_CR44,  0x32 },	\ 	{ ZYD_CR46,  0x96 }, { ZYD_CR47,  0x1e }, { ZYD_CR79,  0x58 },	\ 	{ ZYD_CR80,  0x30 }, { ZYD_CR81,  0x30 }, { ZYD_CR87,  0x0a },	\ 	{ ZYD_CR89,  0x04 }, { ZYD_CR92,  0x0a }, { ZYD_CR99,  0x28 },	\ 	{ ZYD_CR100, 0x00 }, { ZYD_CR101, 0x13 }, { ZYD_CR102, 0x27 },	\ 	{ ZYD_CR106, 0x24 }, { ZYD_CR107, 0x2a }, { ZYD_CR109, 0x09 },	\ 	{ ZYD_CR110, 0x13 }, { ZYD_CR111, 0x1f }, { ZYD_CR112, 0x1f },	\ 	{ ZYD_CR113, 0x27 }, { ZYD_CR114, 0x27 }, { ZYD_CR115, 0x24 },	\ 	{ ZYD_CR116, 0x24 }, { ZYD_CR117, 0xf4 }, { ZYD_CR118, 0xfc },	\ 	{ ZYD_CR119, 0x10 }, { ZYD_CR120, 0x4f }, { ZYD_CR121, 0x77 },	\ 	{ ZYD_CR122, 0xe0 }, { ZYD_CR137, 0x88 }, { ZYD_CR252, 0xff },	\ 	{ ZYD_CR253, 0xff }, { ZYD_CR251, 0x2f }, { ZYD_CR251, 0x3f },	\ 	{ ZYD_CR138, 0x28 }, { ZYD_CR203, 0x06 } 			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_PHY_B
define|\
value|{									\ 	{ ZYD_CR10,  0x89 }, { ZYD_CR15,  0x20 }, { ZYD_CR17,  0x2B },	\ 	{ ZYD_CR23,  0x40 }, { ZYD_CR24,  0x20 }, { ZYD_CR26,  0x93 },	\ 	{ ZYD_CR28,  0x3e }, { ZYD_CR29,  0x00 }, { ZYD_CR33,  0x28 },	\ 	{ ZYD_CR34,  0x30 }, { ZYD_CR35,  0x3e }, { ZYD_CR41,  0x24 },	\ 	{ ZYD_CR44,  0x32 }, { ZYD_CR46,  0x99 }, { ZYD_CR47,  0x1e },	\ 	{ ZYD_CR48,  0x06 }, { ZYD_CR49,  0xf9 }, { ZYD_CR51,  0x01 },	\ 	{ ZYD_CR52,  0x80 }, { ZYD_CR53,  0x7e }, { ZYD_CR65,  0x00 },	\ 	{ ZYD_CR66,  0x00 }, { ZYD_CR67,  0x00 }, { ZYD_CR68,  0x00 },	\ 	{ ZYD_CR69,  0x28 }, { ZYD_CR79,  0x58 }, { ZYD_CR80,  0x30 },	\ 	{ ZYD_CR81,  0x30 }, { ZYD_CR87,  0x0a }, { ZYD_CR89,  0x04 },	\ 	{ ZYD_CR91,  0x00 }, { ZYD_CR92,  0x0a }, { ZYD_CR98,  0x8d },	\ 	{ ZYD_CR99,  0x00 }, { ZYD_CR101, 0x13 }, { ZYD_CR102, 0x27 },	\ 	{ ZYD_CR106, 0x24 }, { ZYD_CR107, 0x2a }, { ZYD_CR109, 0x13 },	\ 	{ ZYD_CR110, 0x1f }, { ZYD_CR111, 0x1f }, { ZYD_CR112, 0x1f },	\ 	{ ZYD_CR113, 0x27 }, { ZYD_CR114, 0x27 }, { ZYD_CR115, 0x26 },	\ 	{ ZYD_CR116, 0x24 }, { ZYD_CR117, 0xfa }, { ZYD_CR118, 0xfa },	\ 	{ ZYD_CR119, 0x10 }, { ZYD_CR120, 0x4f }, { ZYD_CR121, 0x6c },	\ 	{ ZYD_CR122, 0xfc }, { ZYD_CR123, 0x57 }, { ZYD_CR125, 0xad },	\ 	{ ZYD_CR126, 0x6c }, { ZYD_CR127, 0x03 }, { ZYD_CR137, 0x50 },	\ 	{ ZYD_CR138, 0xa8 }, { ZYD_CR144, 0xac }, { ZYD_CR150, 0x0d },	\ 	{ ZYD_CR252, 0x34 }, { ZYD_CR253, 0x34 }			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_PHY_PART1
define|\
value|{									\ 	{ ZYD_CR240, 0x57 }, { ZYD_CR9,   0xe0 }			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_PHY_PART2
define|\
value|{									\ 	{ ZYD_CR251, 0x2f }, { ZYD_CR251, 0x7f },			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_PHY_PART3
define|\
value|{									\ 	{ ZYD_CR128, 0x14 }, { ZYD_CR129, 0x12 }, { ZYD_CR130, 0x10 },	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230S_PHY_INIT
define|\
value|{									\ 	{ ZYD_CR47,  0x1e }, { ZYD_CR106, 0x22 }, { ZYD_CR107, 0x2a },	\ 	{ ZYD_CR109, 0x13 }, { ZYD_CR118, 0xf8 }, { ZYD_CR119, 0x12 },	\ 	{ ZYD_CR122, 0xe0 }, { ZYD_CR128, 0x10 }, { ZYD_CR129, 0x0e },	\ 	{ ZYD_CR130, 0x10 }						\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_PHY_FINI_PART1
define|\
value|{									\ 	{ ZYD_CR80,  0x30 }, { ZYD_CR81,  0x30 }, { ZYD_CR79,  0x58 },	\ 	{ ZYD_CR12,  0xf0 }, { ZYD_CR77,  0x1b }, { ZYD_CR78,  0x58 },	\ 	{ ZYD_CR203, 0x06 }, { ZYD_CR240, 0x80 },			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_RF_PART1
define|\
value|{									\ 	0x03f790, 0x033331, 0x00000d, 0x0b3331, 0x03b812, 0x00fff3	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_RF_PART2
define|\
value|{									\ 	0x000da4, 0x0f4dc5, 0x0805b6, 0x011687, 0x000688, 0x0403b9,	\ 	0x00dbba, 0x00099b, 0x0bdffc, 0x00000d, 0x00500f		\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_RF_PART3
define|\
value|{									\ 	0x00d00f, 0x004c0f, 0x00540f, 0x00700f, 0x00500f		\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_RF_B
define|\
value|{									\ 	0x03f790, 0x033331, 0x00000d, 0x0b3331, 0x03b812, 0x00fff3,	\ 	0x0005a4, 0x0f4dc5, 0x0805b6, 0x0146c7, 0x000688, 0x0403b9,	\ 	0x00dbba, 0x00099b, 0x0bdffc, 0x00000d, 0x00580f		\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_RF_B_PART1
define|\
value|{									\ 	0x8cccd0, 0x481dc0, 0xcfff00, 0x25a000				\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_RF_B_PART2
define|\
value|{									\ 	0x25a000, 0xa3b2f0, 0x6da010, 0xe36280, 0x116000, 0x9dc020,	\ 	0x5ddb00, 0xd99000, 0x3ffbd0, 0xb00000, 0xf01a00		\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_RF_B_PART3
define|\
value|{									\ 	0xf01b00, 0xf01e00, 0xf01a00					\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_CHANTABLE
define|\
value|{						\ 	{ 0x03f790, 0x033331, 0x00000d },	\ 	{ 0x03f790, 0x0b3331, 0x00000d },	\ 	{ 0x03e790, 0x033331, 0x00000d },	\ 	{ 0x03e790, 0x0b3331, 0x00000d },	\ 	{ 0x03f7a0, 0x033331, 0x00000d },	\ 	{ 0x03f7a0, 0x0b3331, 0x00000d },	\ 	{ 0x03e7a0, 0x033331, 0x00000d },	\ 	{ 0x03e7a0, 0x0b3331, 0x00000d },	\ 	{ 0x03f7b0, 0x033331, 0x00000d },	\ 	{ 0x03f7b0, 0x0b3331, 0x00000d },	\ 	{ 0x03e7b0, 0x033331, 0x00000d },	\ 	{ 0x03e7b0, 0x0b3331, 0x00000d },	\ 	{ 0x03f7c0, 0x033331, 0x00000d },	\ 	{ 0x03e7c0, 0x066661, 0x00000d }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2230_CHANTABLE_B
define|\
value|{						\ 	{ 0x09efc0, 0x8cccc0, 0xb00000 },	\ 	{ 0x09efc0, 0x8cccd0, 0xb00000 },	\ 	{ 0x09e7c0, 0x8cccc0, 0xb00000 },	\ 	{ 0x09e7c0, 0x8cccd0, 0xb00000 },	\ 	{ 0x05efc0, 0x8cccc0, 0xb00000 },	\ 	{ 0x05efc0, 0x8cccd0, 0xb00000 },	\ 	{ 0x05e7c0, 0x8cccc0, 0xb00000 },	\ 	{ 0x05e7c0, 0x8cccd0, 0xb00000 },	\ 	{ 0x0defc0, 0x8cccc0, 0xb00000 },	\ 	{ 0x0defc0, 0x8cccd0, 0xb00000 },	\ 	{ 0x0de7c0, 0x8cccc0, 0xb00000 },	\ 	{ 0x0de7c0, 0x8cccd0, 0xb00000 },	\ 	{ 0x03efc0, 0x8cccc0, 0xb00000 },	\ 	{ 0x03e7c0, 0x866660, 0xb00000 }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL7230B_PHY_1
define|\
value|{									\ 	{ ZYD_CR240, 0x57 }, { ZYD_CR15,  0x20 }, { ZYD_CR23,  0x40 },	\ 	{ ZYD_CR24,  0x20 }, { ZYD_CR26,  0x11 }, { ZYD_CR28,  0x3e },	\ 	{ ZYD_CR29,  0x00 }, { ZYD_CR44,  0x33 }, { ZYD_CR106, 0x22 },	\ 	{ ZYD_CR107, 0x1a }, { ZYD_CR109, 0x09 }, { ZYD_CR110, 0x27 },	\ 	{ ZYD_CR111, 0x2b }, { ZYD_CR112, 0x2b }, { ZYD_CR119, 0x0a },	\ 	{ ZYD_CR122, 0xfc }, { ZYD_CR10,  0x89 }, { ZYD_CR17,  0x28 },	\ 	{ ZYD_CR26,  0x93 }, { ZYD_CR34,  0x30 }, { ZYD_CR35,  0x3e },	\ 	{ ZYD_CR41,  0x24 }, { ZYD_CR44,  0x32 }, { ZYD_CR46,  0x96 },	\ 	{ ZYD_CR47,  0x1e }, { ZYD_CR79,  0x58 }, { ZYD_CR80,  0x30 },	\ 	{ ZYD_CR81,  0x30 }, { ZYD_CR87,  0x0a }, { ZYD_CR89,  0x04 },	\ 	{ ZYD_CR92,  0x0a }, { ZYD_CR99,  0x28 }, { ZYD_CR100, 0x02 },	\ 	{ ZYD_CR101, 0x13 }, { ZYD_CR102, 0x27 }, { ZYD_CR106, 0x22 },	\ 	{ ZYD_CR107, 0x3f }, { ZYD_CR109, 0x09 }, { ZYD_CR110, 0x1f },	\ 	{ ZYD_CR111, 0x1f }, { ZYD_CR112, 0x1f }, { ZYD_CR113, 0x27 },	\ 	{ ZYD_CR114, 0x27 }, { ZYD_CR115, 0x24 }, { ZYD_CR116, 0x3f },	\ 	{ ZYD_CR117, 0xfa }, { ZYD_CR118, 0xfc }, { ZYD_CR119, 0x10 },	\ 	{ ZYD_CR120, 0x4f }, { ZYD_CR121, 0x77 }, { ZYD_CR137, 0x88 },	\ 	{ ZYD_CR138, 0xa8 }, { ZYD_CR252, 0x34 }, { ZYD_CR253, 0x34 },	\ 	{ ZYD_CR251, 0x2f }						\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL7230B_PHY_2
define|\
value|{									\ 	{ ZYD_CR251, 0x3f }, { ZYD_CR128, 0x14 }, { ZYD_CR129, 0x12 },	\ 	{ ZYD_CR130, 0x10 }, { ZYD_CR38,  0x38 }, { ZYD_CR136, 0xdf }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL7230B_PHY_3
define|\
value|{									\ 	{ ZYD_CR203, 0x06 }, { ZYD_CR240, 0x80 }			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL7230B_RF_1
define|\
value|{									\ 	0x09ec04, 0x8cccc8, 0x4ff821, 0xc5fbfc, 0x21ebfe, 0xafd401,	\ 	0x6cf56a, 0xe04073, 0x193d76, 0x9dd844, 0x500007, 0xd8c010,	\ 	0x3c9000, 0xbfffff, 0x700000, 0xf15d58				\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL7230B_RF_2
define|\
value|{									\ 	0xf15d59, 0xf15d5c, 0xf15d58					\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL7230B_RF_SETCHANNEL
define|\
value|{									\ 	0x4ff821, 0xc5fbfc, 0x21ebfe, 0xafd401, 0x6cf56a, 0xe04073,	\ 	0x193d76, 0x9dd844, 0x500007, 0xd8c010, 0x3c9000, 0xf15d58	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL7230B_CHANTABLE
define|\
value|{				\ 	{ 0x09ec00, 0x8cccc8 },	\ 	{ 0x09ec00, 0x8cccd8 },	\ 	{ 0x09ec00, 0x8cccc0 },	\ 	{ 0x09ec00, 0x8cccd0 },	\ 	{ 0x05ec00, 0x8cccc8 },	\ 	{ 0x05ec00, 0x8cccd8 },	\ 	{ 0x05ec00, 0x8cccc0 },	\ 	{ 0x05ec00, 0x8cccd0 },	\ 	{ 0x0dec00, 0x8cccc8 },	\ 	{ 0x0dec00, 0x8cccd8 },	\ 	{ 0x0dec00, 0x8cccc0 },	\ 	{ 0x0dec00, 0x8cccd0 },	\ 	{ 0x03ec00, 0x8cccc8 },	\ 	{ 0x03ec00, 0x866660 }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2210_PHY
define|\
value|{									\ 	{ ZYD_CR9,   0xe0 }, { ZYD_CR10, 0x91 }, { ZYD_CR12,  0x90 },	\ 	{ ZYD_CR15,  0xd0 }, { ZYD_CR16, 0x40 }, { ZYD_CR17,  0x58 },	\ 	{ ZYD_CR18,  0x04 }, { ZYD_CR23, 0x66 }, { ZYD_CR24,  0x14 },	\ 	{ ZYD_CR26,  0x90 }, { ZYD_CR31, 0x80 }, { ZYD_CR34,  0x06 },	\ 	{ ZYD_CR35,  0x3e }, { ZYD_CR38, 0x38 }, { ZYD_CR46,  0x90 },	\ 	{ ZYD_CR47,  0x1e }, { ZYD_CR64, 0x64 }, { ZYD_CR79,  0xb5 },	\ 	{ ZYD_CR80,  0x38 }, { ZYD_CR81, 0x30 }, { ZYD_CR113, 0xc0 },	\ 	{ ZYD_CR127, 0x03 }						\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2210_RF
define|\
value|{									\ 	0x2396c0, 0x00fcb1, 0x358132, 0x0108b3, 0xc77804, 0x456415,	\ 	0xff2226, 0x806667, 0x7860f8, 0xbb01c9, 0x00000a, 0x00000b	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_AL2210_CHANTABLE
define|\
value|{									\ 	0x0196c0, 0x019710, 0x019760, 0x0197b0,	0x019800, 0x019850,	\ 	0x0198a0, 0x0198f0, 0x019940, 0x019990, 0x0199e0, 0x019a30,	\ 	0x019a80, 0x019b40 						\ }
end_define

begin_define
define|#
directive|define
name|ZYD_GCT_PHY
define|\
value|{									\ 	{ ZYD_CR10,  0x89 }, { ZYD_CR15,  0x20 }, { ZYD_CR17,  0x28 },	\ 	{ ZYD_CR23,  0x38 }, { ZYD_CR24,  0x20 }, { ZYD_CR26,  0x93 },	\ 	{ ZYD_CR27,  0x15 }, { ZYD_CR28,  0x3e }, { ZYD_CR29,  0x00 },	\ 	{ ZYD_CR33,  0x28 }, { ZYD_CR34,  0x30 }, { ZYD_CR35,  0x43 },	\ 	{ ZYD_CR41,  0x24 }, { ZYD_CR44,  0x32 }, { ZYD_CR46,  0x92 },	\ 	{ ZYD_CR47,  0x1e }, { ZYD_CR48,  0x04 }, { ZYD_CR49,  0xfa },	\ 	{ ZYD_CR79,  0x58 }, { ZYD_CR80,  0x30 }, { ZYD_CR81,  0x30 },	\ 	{ ZYD_CR87,  0x0a }, { ZYD_CR89,  0x04 }, { ZYD_CR91,  0x00 },	\ 	{ ZYD_CR92,  0x0a }, { ZYD_CR98,  0x8d }, { ZYD_CR99,  0x28 },	\ 	{ ZYD_CR100, 0x02 }, { ZYD_CR101, 0x09 }, { ZYD_CR102, 0x27 },	\ 	{ ZYD_CR106, 0x1c }, { ZYD_CR107, 0x1c }, { ZYD_CR109, 0x13 },	\ 	{ ZYD_CR110, 0x1f }, { ZYD_CR111, 0x13 }, { ZYD_CR112, 0x1f },	\ 	{ ZYD_CR113, 0x27 }, { ZYD_CR114, 0x23 }, { ZYD_CR115, 0x24 },	\ 	{ ZYD_CR116, 0x24 }, { ZYD_CR117, 0xfa }, { ZYD_CR118, 0xf0 },	\ 	{ ZYD_CR119, 0x1a }, { ZYD_CR120, 0x4f }, { ZYD_CR121, 0x1f },	\ 	{ ZYD_CR122, 0xf0 }, { ZYD_CR123, 0x57 }, { ZYD_CR125, 0xad },	\ 	{ ZYD_CR126, 0x6c }, { ZYD_CR127, 0x03 }, { ZYD_CR128, 0x14 },	\ 	{ ZYD_CR129, 0x12 }, { ZYD_CR130, 0x10 }, { ZYD_CR137, 0x50 },	\ 	{ ZYD_CR138, 0xa8 }, { ZYD_CR144, 0xac }, { ZYD_CR146, 0x20 },	\ 	{ ZYD_CR252, 0xff }, { ZYD_CR253, 0xff }			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_GCT_RF
define|\
value|{									\ 	0x40002b, 0x519e4f, 0x6f81ad, 0x73fffe, 0x25f9c, 0x100047,	\ 	0x200999, 0x307602, 0x346063,					\ }
end_define

begin_define
define|#
directive|define
name|ZYD_GCT_VCO
define|\
value|{									\ 	{ 0x664d, 0x604d, 0x6675, 0x6475, 0x6655, 0x6455, 0x6665 },	\ 	{ 0x666d, 0x606d, 0x664d, 0x644d, 0x6675, 0x6475, 0x6655 },	\ 	{ 0x665d, 0x605d, 0x666d, 0x646d, 0x664d, 0x644d, 0x6675 },	\ 	{ 0x667d, 0x607d, 0x665d, 0x645d, 0x666d, 0x646d, 0x664d },	\ 	{ 0x6643, 0x6043, 0x667d, 0x647d, 0x665d, 0x645d, 0x666d },	\ 	{ 0x6663, 0x6063, 0x6643, 0x6443, 0x667d, 0x647d, 0x665d },	\ 	{ 0x6653, 0x6053, 0x6663, 0x6463, 0x6643, 0x6443, 0x667d },	\ 	{ 0x6673, 0x6073, 0x6653, 0x6453, 0x6663, 0x6463, 0x6643 },	\ 	{ 0x664b, 0x604b, 0x6673, 0x6473, 0x6653, 0x6453, 0x6663 },	\ 	{ 0x666b, 0x606b, 0x664b, 0x644b, 0x6673, 0x6473, 0x6653 },	\ 	{ 0x665b, 0x605b, 0x666b, 0x646b, 0x664b, 0x644b, 0x6673 }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_GCT_TXGAIN
define|\
value|{									\ 	0x0e313, 0x0fb13, 0x0e093, 0x0f893, 0x0ea93, 0x1f093, 0x1f493,	\ 	0x1f693, 0x1f393, 0x1f35b, 0x1e6db, 0x1ff3f, 0x1ffff, 0x361d7,	\ 	0x37fbf, 0x3ff8b, 0x3ff33, 0x3fb3f, 0x3ffff			\ }
end_define

begin_define
define|#
directive|define
name|ZYD_GCT_CHANNEL_ACAL
define|\
value|{									\ 	0x106847, 0x106847, 0x106867, 0x106867, 0x106867, 0x106867,	\ 	0x106857, 0x106857, 0x106857, 0x106857, 0x106877, 0x106877,	\ 	0x106877, 0x10684f						\ }
end_define

begin_define
define|#
directive|define
name|ZYD_GCT_CHANNEL_STD
define|\
value|{									\ 	0x100047, 0x100047, 0x100067, 0x100067, 0x100067, 0x100067,	\ 	0x100057, 0x100057, 0x100057, 0x100057, 0x100077, 0x100077,	\ 	0x100077, 0x10004f						\ }
end_define

begin_define
define|#
directive|define
name|ZYD_GCT_CHANNEL_DIV
define|\
value|{									\ 	0x200999, 0x20099b, 0x200998, 0x20099a, 0x200999, 0x20099b,	\ 	0x200998, 0x20099a, 0x200999, 0x20099b, 0x200998, 0x20099a,	\ 	0x200999, 0x200ccc						\ }
end_define

begin_define
define|#
directive|define
name|ZYD_MAXIM2_PHY
define|\
value|{									\ 	{ ZYD_CR23,  0x40 }, { ZYD_CR15,  0x20 }, { ZYD_CR28,  0x3e },	\ 	{ ZYD_CR29,  0x00 }, { ZYD_CR26,  0x11 }, { ZYD_CR44,  0x33 },	\ 	{ ZYD_CR106, 0x2a }, { ZYD_CR107, 0x1a }, { ZYD_CR109, 0x2b },	\ 	{ ZYD_CR110, 0x2b }, { ZYD_CR111, 0x2b }, { ZYD_CR112, 0x2b },	\ 	{ ZYD_CR10,  0x89 }, { ZYD_CR17,  0x20 }, { ZYD_CR26,  0x93 },	\ 	{ ZYD_CR34,  0x30 }, { ZYD_CR35,  0x40 }, { ZYD_CR41,  0x24 },	\ 	{ ZYD_CR44,  0x32 }, { ZYD_CR46,  0x90 }, { ZYD_CR89,  0x18 },	\ 	{ ZYD_CR92,  0x0a }, { ZYD_CR101, 0x13 }, { ZYD_CR102, 0x27 },	\ 	{ ZYD_CR106, 0x20 }, { ZYD_CR107, 0x24 }, { ZYD_CR109, 0x09 },	\ 	{ ZYD_CR110, 0x13 }, { ZYD_CR111, 0x13 }, { ZYD_CR112, 0x13 },	\ 	{ ZYD_CR113, 0x27 }, { ZYD_CR114, 0x27 }, { ZYD_CR115, 0x24 },	\ 	{ ZYD_CR116, 0x24 }, { ZYD_CR117, 0xf4 }, { ZYD_CR118, 0xfa },	\ 	{ ZYD_CR120, 0x4f }, { ZYD_CR121, 0x77 }, { ZYD_CR122, 0xfe },	\ 	{ ZYD_CR10,  0x89 }, { ZYD_CR17,  0x20 }, { ZYD_CR26,  0x93 },	\ 	{ ZYD_CR34,  0x30 }, { ZYD_CR35,  0x40 }, { ZYD_CR41,  0x24 },	\ 	{ ZYD_CR44,  0x32 }, { ZYD_CR46,  0x90 }, { ZYD_CR79,  0x58 },	\ 	{ ZYD_CR80,  0x30 }, { ZYD_CR81,  0x30 }, { ZYD_CR89,  0x18 },	\ 	{ ZYD_CR92,  0x0a }, { ZYD_CR101, 0x13 }, { ZYD_CR102, 0x27 },	\ 	{ ZYD_CR106, 0x20 }, { ZYD_CR107, 0x24 }, { ZYD_CR109, 0x09 },	\ 	{ ZYD_CR110, 0x13 }, { ZYD_CR111, 0x13 }, { ZYD_CR112, 0x13 },	\ 	{ ZYD_CR113, 0x27 }, { ZYD_CR114, 0x27 }, { ZYD_CR115, 0x24 },	\ 	{ ZYD_CR116, 0x24 }, { ZYD_CR117, 0xf4 }, { ZYD_CR118, 0x00 },	\ 	{ ZYD_CR120, 0x4f }, { ZYD_CR121, 0x06 }, { ZYD_CR122, 0xfe }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_MAXIM2_RF
define|\
value|{									\ 	0x33334, 0x10a03, 0x00400, 0x00ca1, 0x10072, 0x18645, 0x04006,	\ 	0x000a7, 0x08258, 0x03fc9, 0x0040a, 0x0000b, 0x0026c		\ }
end_define

begin_define
define|#
directive|define
name|ZYD_MAXIM2_CHANTABLE_F
define|\
value|{									\ 	0x33334, 0x08884, 0x1ddd4, 0x33334, 0x08884, 0x1ddd4, 0x33334,	\ 	0x08884, 0x1ddd4, 0x33334, 0x08884, 0x1ddd4, 0x33334, 0x26664	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_MAXIM2_CHANTABLE
define|\
value|{				\ 	{ 0x33334, 0x10a03 },	\ 	{ 0x08884, 0x20a13 },	\ 	{ 0x1ddd4, 0x30a13 },	\ 	{ 0x33334, 0x10a13 },	\ 	{ 0x08884, 0x20a23 },	\ 	{ 0x1ddd4, 0x30a23 },	\ 	{ 0x33334, 0x10a23 },	\ 	{ 0x08884, 0x20a33 },	\ 	{ 0x1ddd4, 0x30a33 },	\ 	{ 0x33334, 0x10a33 },	\ 	{ 0x08884, 0x20a43 },	\ 	{ 0x1ddd4, 0x30a43 },	\ 	{ 0x33334, 0x10a43 },	\ 	{ 0x26664, 0x20a53 }	\ }
end_define

begin_define
define|#
directive|define
name|ZYD_TX_RATEDIV
define|\
value|{									\ 	0x1, 0x2, 0xb, 0xb, 0x1, 0x1, 0x1, 0x1, 0x30, 0x18, 0xc, 0x6,	\ 	0x36, 0x24, 0x12, 0x9						\ }
end_define

begin_comment
comment|/*  * Control pipe requests.  */
end_comment

begin_define
define|#
directive|define
name|ZYD_DOWNLOADREQ
value|0x30
end_define

begin_define
define|#
directive|define
name|ZYD_DOWNLOADSTS
value|0x31
end_define

begin_define
define|#
directive|define
name|ZYD_READFWDATAREQ
value|0x32
end_define

begin_comment
comment|/* possible values for register ZYD_CR_INTERRUPT */
end_comment

begin_define
define|#
directive|define
name|ZYD_HWINT_MASK
value|0x004f0000
end_define

begin_comment
comment|/* possible values for register ZYD_MAC_MISC */
end_comment

begin_define
define|#
directive|define
name|ZYD_UNLOCK_PHY_REGS
value|0x80
end_define

begin_comment
comment|/* possible values for register ZYD_MAC_ENCRYPTION_TYPE */
end_comment

begin_define
define|#
directive|define
name|ZYD_ENC_SNIFFER
value|8
end_define

begin_comment
comment|/* flags for register ZYD_MAC_RXFILTER */
end_comment

begin_define
define|#
directive|define
name|ZYD_FILTER_ASS_REQ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_ASS_RSP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_REASS_REQ
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_REASS_RSP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_PRB_REQ
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_PRB_RSP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_BCN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_ATIM
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_DEASS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_AUTH
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_DEAUTH
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_PS_POLL
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_RTS
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_CTS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_ACK
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_CFE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_CFE_A
value|(1U<< 31)
end_define

begin_comment
comment|/* helpers for register ZYD_MAC_RXFILTER */
end_comment

begin_define
define|#
directive|define
name|ZYD_FILTER_MONITOR
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_BSS
define|\
value|(ZYD_FILTER_ASS_REQ | ZYD_FILTER_ASS_RSP |			\ 	 ZYD_FILTER_REASS_REQ | ZYD_FILTER_REASS_RSP |			\ 	 ZYD_FILTER_PRB_REQ | ZYD_FILTER_PRB_RSP |			\ 	 (0x3<< 6) |							\ 	 ZYD_FILTER_BCN | ZYD_FILTER_ATIM | ZYD_FILTER_DEASS |		\ 	 ZYD_FILTER_AUTH | ZYD_FILTER_DEAUTH |				\ 	 (0x7<< 13) |							\ 	 ZYD_FILTER_PS_POLL | ZYD_FILTER_ACK)
end_define

begin_define
define|#
directive|define
name|ZYD_FILTER_HOSTAP
define|\
value|(ZYD_FILTER_ASS_REQ | ZYD_FILTER_REASS_REQ |			\ 	 ZYD_FILTER_PRB_REQ | ZYD_FILTER_DEASS | ZYD_FILTER_AUTH |	\ 	 ZYD_FILTER_DEAUTH | ZYD_FILTER_PS_POLL)
end_define

begin_struct
struct|struct
name|zyd_tx_desc
block|{
name|uint8_t
name|phy
decl_stmt|;
define|#
directive|define
name|ZYD_TX_PHY_SIGNAL
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
define|#
directive|define
name|ZYD_TX_PHY_OFDM
value|(1<< 4)
define|#
directive|define
name|ZYD_TX_PHY_SHPREAMBLE
value|(1<< 5)
comment|/* CCK */
define|#
directive|define
name|ZYD_TX_PHY_5GHZ
value|(1<< 5)
comment|/* OFDM */
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ZYD_TX_FLAG_BACKOFF
value|(1<< 0)
define|#
directive|define
name|ZYD_TX_FLAG_MULTICAST
value|(1<< 1)
define|#
directive|define
name|ZYD_TX_FLAG_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
define|#
directive|define
name|ZYD_TX_TYPE_DATA
value|0
define|#
directive|define
name|ZYD_TX_TYPE_PS_POLL
value|1
define|#
directive|define
name|ZYD_TX_TYPE_MGMT
value|2
define|#
directive|define
name|ZYD_TX_TYPE_CTL
value|3
define|#
directive|define
name|ZYD_TX_FLAG_WAKEUP
value|(1<< 4)
define|#
directive|define
name|ZYD_TX_FLAG_RTS
value|(1<< 5)
define|#
directive|define
name|ZYD_TX_FLAG_ENCRYPT
value|(1<< 6)
define|#
directive|define
name|ZYD_TX_FLAG_CTS_TO_SELF
value|(1<< 7)
name|uint16_t
name|pktlen
decl_stmt|;
name|uint16_t
name|plcp_length
decl_stmt|;
name|uint8_t
name|plcp_service
decl_stmt|;
define|#
directive|define
name|ZYD_PLCP_LENGEXT
value|0x80
name|uint16_t
name|nextlen
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|zyd_plcphdr
block|{
name|uint8_t
name|signal
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|service
decl_stmt|;
comment|/* unaligned! */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|zyd_rx_stat
block|{
name|uint8_t
name|signal_cck
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
name|uint8_t
name|signal_ofdm
decl_stmt|;
name|uint8_t
name|cipher
decl_stmt|;
define|#
directive|define
name|ZYD_RX_CIPHER_WEP64
value|1
define|#
directive|define
name|ZYD_RX_CIPHER_TKIP
value|2
define|#
directive|define
name|ZYD_RX_CIPHER_AES
value|4
define|#
directive|define
name|ZYD_RX_CIPHER_WEP128
value|5
define|#
directive|define
name|ZYD_RX_CIPHER_WEP256
value|6
define|#
directive|define
name|ZYD_RX_CIPHER_WEP
define|\
value|(ZYD_RX_CIPHER_WEP64 | ZYD_RX_CIPHER_WEP128 | ZYD_RX_CIPHER_WEP256)
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ZYD_RX_OFDM
value|(1<< 0)
define|#
directive|define
name|ZYD_RX_TIMEOUT
value|(1<< 1)
define|#
directive|define
name|ZYD_RX_OVERRUN
value|(1<< 2)
define|#
directive|define
name|ZYD_RX_DECRYPTERR
value|(1<< 3)
define|#
directive|define
name|ZYD_RX_BADCRC32
value|(1<< 4)
define|#
directive|define
name|ZYD_RX_NOT2ME
value|(1<< 5)
define|#
directive|define
name|ZYD_RX_BADCRC16
value|(1<< 6)
define|#
directive|define
name|ZYD_RX_ERROR
value|(1<< 7)
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* this structure may be unaligned */
end_comment

begin_struct
struct|struct
name|zyd_rx_desc
block|{
define|#
directive|define
name|ZYD_MAX_RXFRAMECNT
value|3
name|uWord
name|len
index|[
name|ZYD_MAX_RXFRAMECNT
index|]
decl_stmt|;
name|uWord
name|tag
decl_stmt|;
define|#
directive|define
name|ZYD_TAG_MULTIFRAME
value|0x697e
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* I2C bus alike */
end_comment

begin_struct
struct|struct
name|zyd_rfwrite_cmd
block|{
name|uint16_t
name|code
decl_stmt|;
name|uint16_t
name|width
decl_stmt|;
name|uint16_t
name|bit
index|[
literal|32
index|]
decl_stmt|;
define|#
directive|define
name|ZYD_RF_IF_LE
value|(1<< 1)
define|#
directive|define
name|ZYD_RF_CLK
value|(1<< 2)
define|#
directive|define
name|ZYD_RF_DATA
value|(1<< 3)
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|zyd_cmd
block|{
name|uint16_t
name|code
decl_stmt|;
define|#
directive|define
name|ZYD_CMD_IOWR
value|0x0021
comment|/* write HMAC or PHY register */
define|#
directive|define
name|ZYD_CMD_IORD
value|0x0022
comment|/* read HMAC or PHY register */
define|#
directive|define
name|ZYD_CMD_RFCFG
value|0x0023
comment|/* write RF register */
define|#
directive|define
name|ZYD_NOTIF_IORD
value|0x9001
comment|/* response for ZYD_CMD_IORD */
define|#
directive|define
name|ZYD_NOTIF_MACINTR
value|0x9001
comment|/* interrupt notification */
define|#
directive|define
name|ZYD_NOTIF_RETRYSTATUS
value|0xa001
comment|/* Tx retry notification */
name|uint8_t
name|data
index|[
literal|64
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command ZYD_CMD_IOWR */
end_comment

begin_struct
struct|struct
name|zyd_pair
block|{
name|uint16_t
name|reg
decl_stmt|;
comment|/* helpers macros to read/write 32-bit registers */
define|#
directive|define
name|ZYD_REG32_LO
parameter_list|(
name|reg
parameter_list|)
value|(reg)
define|#
directive|define
name|ZYD_REG32_HI
parameter_list|(
name|reg
parameter_list|)
define|\
value|((reg) + ((((reg)& 0xf000) == 0x9000) ? 2 : 1))
name|uint16_t
name|val
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for notification ZYD_NOTIF_RETRYSTATUS */
end_comment

begin_struct
struct|struct
name|zyd_notif_retry
block|{
name|uint16_t
name|rate
decl_stmt|;
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|count
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ZYD_CONFIG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|ZYD_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|ZYD_INTR_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ZYD_TX_TIMEOUT
value|10000
end_define

begin_define
define|#
directive|define
name|ZYD_MAX_TXBUFSZ
define|\
value|(sizeof(struct zyd_tx_desc) + MCLBYTES)
end_define

begin_define
define|#
directive|define
name|ZYD_MIN_FRAGSZ
define|\
value|(sizeof(struct zyd_plcphdr) + IEEE80211_MIN_LEN + 		\ 	 sizeof(struct zyd_rx_stat))
end_define

begin_define
define|#
directive|define
name|ZYD_MIN_RXBUFSZ
value|ZYD_MIN_FRAGSZ
end_define

begin_define
define|#
directive|define
name|ZYX_MAX_RXBUFSZ
define|\
value|((sizeof (struct zyd_plcphdr) + IEEE80211_MAX_LEN +		\ 	  sizeof (struct zyd_rx_stat)) * ZYD_MAX_RXFRAMECNT + 		\ 	 sizeof (struct zyd_rx_desc))
end_define

begin_define
define|#
directive|define
name|ZYD_TX_DESC_SIZE
value|(sizeof (struct zyd_tx_desc))
end_define

begin_define
define|#
directive|define
name|ZYD_RX_LIST_CNT
value|1
end_define

begin_define
define|#
directive|define
name|ZYD_TX_LIST_CNT
value|5
end_define

begin_define
define|#
directive|define
name|ZYD_CMD_FLAG_READ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ZYD_CMD_FLAG_SENT
value|(1<< 1)
end_define

begin_comment
comment|/* quickly determine if a given rate is CCK or OFDM */
end_comment

begin_define
define|#
directive|define
name|ZYD_RATE_IS_OFDM
parameter_list|(
name|rate
parameter_list|)
value|((rate)>= 12&& (rate) != 22)
end_define

begin_struct
struct|struct
name|zyd_phy_pair
block|{
name|uint16_t
name|reg
decl_stmt|;
name|uint8_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|zyd_mac_pair
block|{
name|uint16_t
name|reg
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|zyd_tx_data
block|{
name|STAILQ_ENTRY
argument_list|(
argument|zyd_tx_data
argument_list|)
name|next
expr_stmt|;
name|struct
name|zyd_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|zyd_tx_desc
name|desc
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
name|ni
decl_stmt|;
name|int
name|rate
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|zyd_tx_data
argument_list|)
name|zyd_txdhead
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|zyd_rx_data
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|int
name|rssi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|zyd_rx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wr_ihdr
decl_stmt|;
name|uint8_t
name|wr_flags
decl_stmt|;
name|uint8_t
name|wr_rate
decl_stmt|;
name|uint16_t
name|wr_chan_freq
decl_stmt|;
name|uint16_t
name|wr_chan_flags
decl_stmt|;
name|int8_t
name|wr_antsignal
decl_stmt|;
name|int8_t
name|wr_antnoise
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|ZYD_RX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) |				\ 	 (1<< IEEE80211_RADIOTAP_RATE) |				\ 	 (1<< IEEE80211_RADIOTAP_DBM_ANTSIGNAL) |			\ 	 (1<< IEEE80211_RADIOTAP_DBM_ANTNOISE) |			\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL))
end_define

begin_struct
struct|struct
name|zyd_tx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wt_ihdr
decl_stmt|;
name|uint8_t
name|wt_flags
decl_stmt|;
name|uint8_t
name|wt_rate
decl_stmt|;
name|uint16_t
name|wt_chan_freq
decl_stmt|;
name|uint16_t
name|wt_chan_flags
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|ZYD_TX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) |				\ 	 (1<< IEEE80211_RADIOTAP_RATE) |				\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL))
end_define

begin_struct_decl
struct_decl|struct
name|zyd_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declaration */
end_comment

begin_struct
struct|struct
name|zyd_rf
block|{
comment|/* RF methods */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|zyd_rf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|switch_radio
function_decl|)
parameter_list|(
name|struct
name|zyd_rf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set_channel
function_decl|)
parameter_list|(
name|struct
name|zyd_rf
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|bandedge6
function_decl|)
parameter_list|(
name|struct
name|zyd_rf
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
comment|/* RF attributes */
name|struct
name|zyd_softc
modifier|*
name|rf_sc
decl_stmt|;
comment|/* back-pointer */
name|int
name|width
decl_stmt|;
name|int
name|idx
decl_stmt|;
comment|/* for GIT RF */
name|int
name|update_pwr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|zyd_rq
block|{
name|struct
name|zyd_cmd
modifier|*
name|cmd
decl_stmt|;
specifier|const
name|uint16_t
modifier|*
name|idata
decl_stmt|;
name|struct
name|zyd_pair
modifier|*
name|odata
decl_stmt|;
name|int
name|ilen
decl_stmt|;
name|int
name|olen
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|zyd_rq
argument_list|)
name|rq
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|zyd_vap
block|{
name|struct
name|ieee80211vap
name|vap
decl_stmt|;
name|int
function_decl|(
modifier|*
name|newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ZYD_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct zyd_vap *)(vap))
end_define

begin_enum
enum|enum
block|{
name|ZYD_BULK_WR
block|,
name|ZYD_BULK_RD
block|,
name|ZYD_INTR_WR
block|,
name|ZYD_INTR_RD
block|,
name|ZYD_N_TRANSFER
init|=
literal|4
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|zyd_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_udev
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|ZYD_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|ZYD_FLAG_FWLOADED
value|(1<< 0)
define|#
directive|define
name|ZYD_FLAG_INITONCE
value|(1<< 1)
define|#
directive|define
name|ZYD_FLAG_INITDONE
value|(1<< 2)
define|#
directive|define
name|ZYD_FLAG_DETACHED
value|(1<< 3)
name|struct
name|zyd_rf
name|sc_rf
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|zyd_rq
argument_list|)
name|sc_rtx
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|zyd_rq
argument_list|)
name|sc_rqh
expr_stmt|;
name|uint8_t
name|sc_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|sc_fwbase
decl_stmt|;
name|uint8_t
name|sc_regdomain
decl_stmt|;
name|uint8_t
name|sc_macrev
decl_stmt|;
name|uint16_t
name|sc_fwrev
decl_stmt|;
name|uint8_t
name|sc_rfrev
decl_stmt|;
name|uint8_t
name|sc_parev
decl_stmt|;
name|uint8_t
name|sc_al2230s
decl_stmt|;
name|uint8_t
name|sc_bandedge6
decl_stmt|;
name|uint8_t
name|sc_newphy
decl_stmt|;
name|uint8_t
name|sc_cckgain
decl_stmt|;
name|uint8_t
name|sc_fix_cr157
decl_stmt|;
name|uint8_t
name|sc_ledtype
decl_stmt|;
name|uint8_t
name|sc_txled
decl_stmt|;
name|uint32_t
name|sc_atim_wnd
decl_stmt|;
name|uint32_t
name|sc_pre_tbtt
decl_stmt|;
name|uint32_t
name|sc_bcn_int
decl_stmt|;
name|uint8_t
name|sc_pwrcal
index|[
literal|14
index|]
decl_stmt|;
name|uint8_t
name|sc_pwrint
index|[
literal|14
index|]
decl_stmt|;
name|uint8_t
name|sc_ofdm36_cal
index|[
literal|14
index|]
decl_stmt|;
name|uint8_t
name|sc_ofdm48_cal
index|[
literal|14
index|]
decl_stmt|;
name|uint8_t
name|sc_ofdm54_cal
index|[
literal|14
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|zyd_tx_data
name|tx_data
index|[
name|ZYD_TX_LIST_CNT
index|]
decl_stmt|;
name|zyd_txdhead
name|tx_q
decl_stmt|;
name|zyd_txdhead
name|tx_free
decl_stmt|;
name|int
name|tx_nfree
decl_stmt|;
name|struct
name|zyd_rx_desc
name|sc_rx_desc
decl_stmt|;
name|struct
name|zyd_rx_data
name|sc_rx_data
index|[
name|ZYD_MAX_RXFRAMECNT
index|]
decl_stmt|;
name|int
name|sc_rx_count
decl_stmt|;
name|struct
name|zyd_cmd
name|sc_ibuf
decl_stmt|;
name|struct
name|zyd_rx_radiotap_header
name|sc_rxtap
decl_stmt|;
name|int
name|sc_rxtap_len
decl_stmt|;
name|struct
name|zyd_tx_radiotap_header
name|sc_txtap
decl_stmt|;
name|int
name|sc_txtap_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ZYD_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ZYD_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ZYD_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, t)
end_define

end_unit

