begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for the VIA VT6122 gigabit ethernet controller.  * Definitions for the built-in copper PHY can be found in vgphy.h.  *  * The VT612x controllers have 256 bytes of register space. The  * manual seems to imply that the registers should all be accessed  * using 32-bit I/O cycles, but some of them are less than 32 bits  * wide. Go figure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_VGEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_VGEREG_H_
end_define

begin_define
define|#
directive|define
name|VIA_VENDORID
value|0x1106
end_define

begin_define
define|#
directive|define
name|VIA_DEVICEID_61XX
value|0x3119
end_define

begin_define
define|#
directive|define
name|VGE_PAR0
value|0x00
end_define

begin_comment
comment|/* physical address register */
end_comment

begin_define
define|#
directive|define
name|VGE_PAR1
value|0x02
end_define

begin_define
define|#
directive|define
name|VGE_PAR2
value|0x04
end_define

begin_define
define|#
directive|define
name|VGE_RXCTL
value|0x06
end_define

begin_comment
comment|/* RX control register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCTL
value|0x07
end_define

begin_comment
comment|/* TX control register */
end_comment

begin_define
define|#
directive|define
name|VGE_CRS0
value|0x08
end_define

begin_comment
comment|/* Global cmd register 0 (w to set) */
end_comment

begin_define
define|#
directive|define
name|VGE_CRS1
value|0x09
end_define

begin_comment
comment|/* Global cmd register 1 (w to set) */
end_comment

begin_define
define|#
directive|define
name|VGE_CRS2
value|0x0A
end_define

begin_comment
comment|/* Global cmd register 2 (w to set) */
end_comment

begin_define
define|#
directive|define
name|VGE_CRS3
value|0x0B
end_define

begin_comment
comment|/* Global cmd register 3 (w to set) */
end_comment

begin_define
define|#
directive|define
name|VGE_CRC0
value|0x0C
end_define

begin_comment
comment|/* Global cmd register 0 (w to clr) */
end_comment

begin_define
define|#
directive|define
name|VGE_CRC1
value|0x0D
end_define

begin_comment
comment|/* Global cmd register 1 (w to clr) */
end_comment

begin_define
define|#
directive|define
name|VGE_CRC2
value|0x0E
end_define

begin_comment
comment|/* Global cmd register 2 (w to clr) */
end_comment

begin_define
define|#
directive|define
name|VGE_CRC3
value|0x0F
end_define

begin_comment
comment|/* Global cmd register 3 (w to clr) */
end_comment

begin_define
define|#
directive|define
name|VGE_MAR0
value|0x10
end_define

begin_comment
comment|/* Mcast hash/CAM register 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_MAR1
value|0x14
end_define

begin_comment
comment|/* Mcast hash/CAM register 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_CAM0
value|0x10
end_define

begin_define
define|#
directive|define
name|VGE_CAM1
value|0x11
end_define

begin_define
define|#
directive|define
name|VGE_CAM2
value|0x12
end_define

begin_define
define|#
directive|define
name|VGE_CAM3
value|0x13
end_define

begin_define
define|#
directive|define
name|VGE_CAM4
value|0x14
end_define

begin_define
define|#
directive|define
name|VGE_CAM5
value|0x15
end_define

begin_define
define|#
directive|define
name|VGE_CAM6
value|0x16
end_define

begin_define
define|#
directive|define
name|VGE_CAM7
value|0x17
end_define

begin_define
define|#
directive|define
name|VGE_TXDESC_HIADDR
value|0x18
end_define

begin_comment
comment|/* Hi part of 64bit txdesc base addr */
end_comment

begin_define
define|#
directive|define
name|VGE_DATABUF_HIADDR
value|0x1D
end_define

begin_comment
comment|/* Hi part of 64bit data buffer addr */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL0
value|0x20
end_define

begin_comment
comment|/* interrupt control register */
end_comment

begin_define
define|#
directive|define
name|VGE_RXSUPPTHR
value|0x20
end_define

begin_define
define|#
directive|define
name|VGE_TXSUPPTHR
value|0x20
end_define

begin_define
define|#
directive|define
name|VGE_INTHOLDOFF
value|0x20
end_define

begin_define
define|#
directive|define
name|VGE_INTCTL1
value|0x21
end_define

begin_comment
comment|/* interrupt control register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXHOSTERR
value|0x22
end_define

begin_comment
comment|/* TX host error status */
end_comment

begin_define
define|#
directive|define
name|VGE_RXHOSTERR
value|0x23
end_define

begin_comment
comment|/* RX host error status */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR
value|0x24
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR
value|0x28
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXSTS_PORT
value|0x2C
end_define

begin_comment
comment|/* Transmit status port (???) */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSRS
value|0x30
end_define

begin_comment
comment|/* TX queue ctl/status set */
end_comment

begin_define
define|#
directive|define
name|VGE_RXQCSRS
value|0x32
end_define

begin_comment
comment|/* RX queue ctl/status set */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSRC
value|0x34
end_define

begin_comment
comment|/* TX queue ctl/status clear */
end_comment

begin_define
define|#
directive|define
name|VGE_RXQCSRC
value|0x36
end_define

begin_comment
comment|/* RX queue ctl/status clear */
end_comment

begin_define
define|#
directive|define
name|VGE_RXDESC_ADDR_LO
value|0x38
end_define

begin_comment
comment|/* RX desc base addr (lo 32 bits) */
end_comment

begin_define
define|#
directive|define
name|VGE_RXDESC_CONSIDX
value|0x3C
end_define

begin_comment
comment|/* Current RX descriptor index */
end_comment

begin_define
define|#
directive|define
name|VGE_RXQTIMER
value|0x3E
end_define

begin_comment
comment|/* RX queue timer pend register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQTIMER
value|0x3F
end_define

begin_comment
comment|/* TX queue timer pend register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_ADDR_LO0
value|0x40
end_define

begin_comment
comment|/* TX desc0 base addr (lo 32 bits) */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_ADDR_LO1
value|0x44
end_define

begin_comment
comment|/* TX desc1 base addr (lo 32 bits) */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_ADDR_LO2
value|0x48
end_define

begin_comment
comment|/* TX desc2 base addr (lo 32 bits) */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_ADDR_LO3
value|0x4C
end_define

begin_comment
comment|/* TX desc3 base addr (lo 32 bits) */
end_comment

begin_define
define|#
directive|define
name|VGE_RXDESCNUM
value|0x50
end_define

begin_comment
comment|/* Size of RX desc ring */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESCNUM
value|0x52
end_define

begin_comment
comment|/* Size of TX desc ring */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_CONSIDX0
value|0x54
end_define

begin_comment
comment|/* Current TX descriptor index */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_CONSIDX1
value|0x56
end_define

begin_comment
comment|/* Current TX descriptor index */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_CONSIDX2
value|0x58
end_define

begin_comment
comment|/* Current TX descriptor index */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_CONSIDX3
value|0x5A
end_define

begin_comment
comment|/* Current TX descriptor index */
end_comment

begin_define
define|#
directive|define
name|VGE_TX_PAUSE_TIMER
value|0x5C
end_define

begin_comment
comment|/* TX pause frame timer */
end_comment

begin_define
define|#
directive|define
name|VGE_RXDESC_RESIDUECNT
value|0x5E
end_define

begin_comment
comment|/* RX descriptor residue count */
end_comment

begin_define
define|#
directive|define
name|VGE_FIFOTEST0
value|0x60
end_define

begin_comment
comment|/* FIFO test register */
end_comment

begin_define
define|#
directive|define
name|VGE_FIFOTEST1
value|0x64
end_define

begin_comment
comment|/* FIFO test register */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMADDR
value|0x68
end_define

begin_comment
comment|/* CAM address register */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMCTL
value|0x69
end_define

begin_comment
comment|/* CAM control register */
end_comment

begin_define
define|#
directive|define
name|VGE_GFTEST
value|0x6A
end_define

begin_define
define|#
directive|define
name|VGE_FTSCMD
value|0x6B
end_define

begin_define
define|#
directive|define
name|VGE_MIICFG
value|0x6C
end_define

begin_comment
comment|/* MII port config register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIISTS
value|0x6D
end_define

begin_comment
comment|/* MII port status register */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS0
value|0x6E
end_define

begin_comment
comment|/* PHY status register */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS1
value|0x6F
end_define

begin_comment
comment|/* PHY status register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD
value|0x70
end_define

begin_comment
comment|/* MII command register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIIADDR
value|0x71
end_define

begin_comment
comment|/* MII address register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIIDATA
value|0x72
end_define

begin_comment
comment|/* MII data register */
end_comment

begin_define
define|#
directive|define
name|VGE_SSTIMER
value|0x74
end_define

begin_comment
comment|/* single-shot timer */
end_comment

begin_define
define|#
directive|define
name|VGE_PTIMER
value|0x76
end_define

begin_comment
comment|/* periodic timer */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG0
value|0x78
end_define

begin_comment
comment|/* chip config A */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG1
value|0x79
end_define

begin_comment
comment|/* chip config B */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG2
value|0x7A
end_define

begin_comment
comment|/* chip config C */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG3
value|0x7B
end_define

begin_comment
comment|/* chip config D */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG0
value|0x7C
end_define

begin_comment
comment|/* DMA config 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG1
value|0x7D
end_define

begin_comment
comment|/* DMA config 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCFG
value|0x7E
end_define

begin_comment
comment|/* MAC RX config */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCFG
value|0x7F
end_define

begin_comment
comment|/* MAC TX config */
end_comment

begin_define
define|#
directive|define
name|VGE_PWRMGMT
value|0x82
end_define

begin_comment
comment|/* power management shadow register */
end_comment

begin_define
define|#
directive|define
name|VGE_PWRSTAT
value|0x83
end_define

begin_comment
comment|/* power state shadow register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIBCSR
value|0x84
end_define

begin_comment
comment|/* MIB control/status register */
end_comment

begin_define
define|#
directive|define
name|VGE_SWEEDATA
value|0x85
end_define

begin_comment
comment|/* EEPROM software loaded data */
end_comment

begin_define
define|#
directive|define
name|VGE_MIBDATA
value|0x88
end_define

begin_comment
comment|/* MIB data register */
end_comment

begin_define
define|#
directive|define
name|VGE_EEWRDAT
value|0x8C
end_define

begin_comment
comment|/* EEPROM embedded write */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSUM
value|0x92
end_define

begin_comment
comment|/* EEPROM checksum */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR
value|0x93
end_define

begin_comment
comment|/* EEPROM control/status */
end_comment

begin_define
define|#
directive|define
name|VGE_EERDDAT
value|0x94
end_define

begin_comment
comment|/* EEPROM embedded read */
end_comment

begin_define
define|#
directive|define
name|VGE_EEADDR
value|0x96
end_define

begin_comment
comment|/* EEPROM address */
end_comment

begin_define
define|#
directive|define
name|VGE_EECMD
value|0x97
end_define

begin_comment
comment|/* EEPROM embedded command */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPSTRAP
value|0x99
end_define

begin_comment
comment|/* Chip jumper strapping status */
end_comment

begin_define
define|#
directive|define
name|VGE_MEDIASTRAP
value|0x9B
end_define

begin_comment
comment|/* Media jumper strapping */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGSTS
value|0x9C
end_define

begin_comment
comment|/* Chip diagnostic status */
end_comment

begin_define
define|#
directive|define
name|VGE_DBGCTL
value|0x9E
end_define

begin_comment
comment|/* Chip debug control */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL
value|0x9F
end_define

begin_comment
comment|/* Chip diagnostic control */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLCR0S
value|0xA0
end_define

begin_comment
comment|/* WOL0 event set */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLCR1S
value|0xA1
end_define

begin_comment
comment|/* WOL1 event set */
end_comment

begin_define
define|#
directive|define
name|VGE_PWRCFGS
value|0xA2
end_define

begin_comment
comment|/* Power management config set */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLCFGS
value|0xA3
end_define

begin_comment
comment|/* WOL config set */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLCR0C
value|0xA4
end_define

begin_comment
comment|/* WOL0 event clear */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLCR1C
value|0xA5
end_define

begin_comment
comment|/* WOL1 event clear */
end_comment

begin_define
define|#
directive|define
name|VGE_PWRCFGC
value|0xA6
end_define

begin_comment
comment|/* Power management config clear */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLCFGC
value|0xA7
end_define

begin_comment
comment|/* WOL config clear */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLSR0S
value|0xA8
end_define

begin_comment
comment|/* WOL status set */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLSR1S
value|0xA9
end_define

begin_comment
comment|/* WOL status set */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLSR0C
value|0xAC
end_define

begin_comment
comment|/* WOL status clear */
end_comment

begin_define
define|#
directive|define
name|VGE_WOLSR1C
value|0xAD
end_define

begin_comment
comment|/* WOL status clear */
end_comment

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC0
value|0xB0
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC1
value|0xB2
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC2
value|0xB4
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC3
value|0xB6
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC4
value|0xB8
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC5
value|0xBA
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC6
value|0xBC
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_CRC7
value|0xBE
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK0_0
value|0xC0
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK0_1
value|0xC4
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK0_2
value|0xC8
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK0_3
value|0xCC
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK1_0
value|0xD0
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK1_1
value|0xD4
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK1_2
value|0xD8
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK1_3
value|0xDC
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK2_0
value|0xE0
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK2_1
value|0xE4
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK2_2
value|0xE8
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK2_3
value|0xEC
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK3_0
value|0xF0
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK3_1
value|0xF4
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK3_2
value|0xF8
end_define

begin_define
define|#
directive|define
name|VGE_WAKEPAT_MSK3_3
value|0xFC
end_define

begin_comment
comment|/* Receive control register */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_BADFRAMES
value|0x01
end_define

begin_comment
comment|/* accept CRC error frames */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_RUNT
value|0x02
end_define

begin_comment
comment|/* accept runts */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_MCAST
value|0x04
end_define

begin_comment
comment|/* accept multicasts */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_BCAST
value|0x08
end_define

begin_comment
comment|/* accept broadcasts */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_PROMISC
value|0x10
end_define

begin_comment
comment|/* promisc mode */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_GIANT
value|0x20
end_define

begin_comment
comment|/* accept VLAN tagged frames */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_UCAST
value|0x40
end_define

begin_comment
comment|/* use perfect filtering */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCTL_RX_SYMERR
value|0x80
end_define

begin_comment
comment|/* accept symbol err packet */
end_comment

begin_comment
comment|/* Transmit control register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCTL_LOOPCTL
value|0x03
end_define

begin_comment
comment|/* loopback control */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCTL_COLLCTL
value|0x0C
end_define

begin_comment
comment|/* collision retry control */
end_comment

begin_define
define|#
directive|define
name|VGE_TXLOOPCTL_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_TXLOOPCTL_MAC_INTERNAL
value|0x01
end_define

begin_define
define|#
directive|define
name|VGE_TXLOOPCTL_EXTERNAL
value|0x02
end_define

begin_define
define|#
directive|define
name|VGE_TXCOLLS_NORMAL
value|0x00
end_define

begin_comment
comment|/* one set of 16 retries */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCOLLS_32
value|0x04
end_define

begin_comment
comment|/* two sets of 16 retries */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCOLLS_48
value|0x08
end_define

begin_comment
comment|/* three sets of 16 retries */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCOLLS_INFINITE
value|0x0C
end_define

begin_comment
comment|/* retry forever */
end_comment

begin_comment
comment|/* Global command register 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_CR0_START
value|0x01
end_define

begin_comment
comment|/* start NIC */
end_comment

begin_define
define|#
directive|define
name|VGE_CR0_STOP
value|0x02
end_define

begin_comment
comment|/* stop NIC */
end_comment

begin_define
define|#
directive|define
name|VGE_CR0_RX_ENABLE
value|0x04
end_define

begin_comment
comment|/* turn on RX engine */
end_comment

begin_define
define|#
directive|define
name|VGE_CR0_TX_ENABLE
value|0x08
end_define

begin_comment
comment|/* turn on TX engine */
end_comment

begin_comment
comment|/* Global command register 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_CR1_NOUCAST
value|0x01
end_define

begin_comment
comment|/* disable unicast reception */
end_comment

begin_define
define|#
directive|define
name|VGE_CR1_NOPOLL
value|0x08
end_define

begin_comment
comment|/* disable RX/TX desc polling */
end_comment

begin_define
define|#
directive|define
name|VGE_CR1_TIMER0_ENABLE
value|0x20
end_define

begin_comment
comment|/* enable single shot timer */
end_comment

begin_define
define|#
directive|define
name|VGE_CR1_TIMER1_ENABLE
value|0x40
end_define

begin_comment
comment|/* enable periodic timer */
end_comment

begin_define
define|#
directive|define
name|VGE_CR1_SOFTRESET
value|0x80
end_define

begin_comment
comment|/* software reset */
end_comment

begin_comment
comment|/* Global command register 2 */
end_comment

begin_define
define|#
directive|define
name|VGE_CR2_TXPAUSE_THRESH_LO
value|0x03
end_define

begin_comment
comment|/* TX pause frame lo threshold */
end_comment

begin_define
define|#
directive|define
name|VGE_CR2_TXPAUSE_THRESH_HI
value|0x0C
end_define

begin_comment
comment|/* TX pause frame hi threshold */
end_comment

begin_define
define|#
directive|define
name|VGE_CR2_HDX_FLOWCTL_ENABLE
value|0x10
end_define

begin_comment
comment|/* half duplex flow control */
end_comment

begin_define
define|#
directive|define
name|VGE_CR2_FDX_RXFLOWCTL_ENABLE
value|0x20
end_define

begin_comment
comment|/* full duplex RX flow control */
end_comment

begin_define
define|#
directive|define
name|VGE_CR2_FDX_TXFLOWCTL_ENABLE
value|0x40
end_define

begin_comment
comment|/* full duplex TX flow control */
end_comment

begin_define
define|#
directive|define
name|VGE_CR2_XON_ENABLE
value|0x80
end_define

begin_comment
comment|/* 802.3x XON/XOFF flow control */
end_comment

begin_comment
comment|/* Global command register 3 */
end_comment

begin_define
define|#
directive|define
name|VGE_CR3_INT_SWPEND
value|0x01
end_define

begin_comment
comment|/* disable multi-level int bits */
end_comment

begin_define
define|#
directive|define
name|VGE_CR3_INT_GMSK
value|0x02
end_define

begin_comment
comment|/* mask off all interrupts */
end_comment

begin_define
define|#
directive|define
name|VGE_CR3_INT_HOLDOFF
value|0x04
end_define

begin_comment
comment|/* enable int hold off timer */
end_comment

begin_define
define|#
directive|define
name|VGE_CR3_DIAG
value|0x10
end_define

begin_comment
comment|/* diagnostic enabled */
end_comment

begin_define
define|#
directive|define
name|VGE_CR3_PHYRST
value|0x20
end_define

begin_comment
comment|/* assert PHYRSTZ */
end_comment

begin_define
define|#
directive|define
name|VGE_CR3_STOP_FORCE
value|0x40
end_define

begin_comment
comment|/* force NIC to stopped state */
end_comment

begin_comment
comment|/* Interrupt control register */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL_SC_RELOAD
value|0x01
end_define

begin_comment
comment|/* reload hold timer */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL_HC_RELOAD
value|0x02
end_define

begin_comment
comment|/* enable hold timer reload */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL_STATUS
value|0x04
end_define

begin_comment
comment|/* interrupt pending status */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL_MASK
value|0x18
end_define

begin_comment
comment|/* multilayer int mask */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL_RXINTSUP_DISABLE
value|0x20
end_define

begin_comment
comment|/* disable RX int supression */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL_TXINTSUP_DISABLE
value|0x40
end_define

begin_comment
comment|/* disable TX int supression */
end_comment

begin_define
define|#
directive|define
name|VGE_INTCTL_SOFTINT
value|0x80
end_define

begin_comment
comment|/* request soft interrupt */
end_comment

begin_define
define|#
directive|define
name|VGE_INTMASK_LAYER0
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_INTMASK_LAYER1
value|0x08
end_define

begin_define
define|#
directive|define
name|VGE_INTMASK_ALL
value|0x10
end_define

begin_define
define|#
directive|define
name|VGE_INTMASK_ALL2
value|0x18
end_define

begin_comment
comment|/* Transmit host error status register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXHOSTERR_TDSTRUCT
value|0x01
end_define

begin_comment
comment|/* bad TX desc structure */
end_comment

begin_define
define|#
directive|define
name|VGE_TXHOSTERR_TDFETCH_BUSERR
value|0x02
end_define

begin_comment
comment|/* bus error on desc fetch */
end_comment

begin_define
define|#
directive|define
name|VGE_TXHOSTERR_TDWBACK_BUSERR
value|0x04
end_define

begin_comment
comment|/* bus error on desc writeback */
end_comment

begin_define
define|#
directive|define
name|VGE_TXHOSTERR_FIFOERR
value|0x08
end_define

begin_comment
comment|/* TX FIFO DMA bus error */
end_comment

begin_comment
comment|/* Receive host error status register */
end_comment

begin_define
define|#
directive|define
name|VGE_RXHOSTERR_RDSTRUCT
value|0x01
end_define

begin_comment
comment|/* bad RX desc structure */
end_comment

begin_define
define|#
directive|define
name|VGE_RXHOSTERR_RDFETCH_BUSERR
value|0x02
end_define

begin_comment
comment|/* bus error on desc fetch */
end_comment

begin_define
define|#
directive|define
name|VGE_RXHOSTERR_RDWBACK_BUSERR
value|0x04
end_define

begin_comment
comment|/* bus error on desc writeback */
end_comment

begin_define
define|#
directive|define
name|VGE_RXHOSTERR_FIFOERR
value|0x08
end_define

begin_comment
comment|/* RX FIFO DMA bus error */
end_comment

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXOK_HIPRIO
value|0x00000001
end_define

begin_comment
comment|/* hi prio RX int */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TXOK_HIPRIO
value|0x00000002
end_define

begin_comment
comment|/* hi prio TX int */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXOK
value|0x00000004
end_define

begin_comment
comment|/* normal RX done */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TXOK
value|0x00000008
end_define

begin_comment
comment|/* combo results for next 4 bits */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TXOK0
value|0x00000010
end_define

begin_comment
comment|/* TX complete on queue 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TXOK1
value|0x00000020
end_define

begin_comment
comment|/* TX complete on queue 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TXOK2
value|0x00000040
end_define

begin_comment
comment|/* TX complete on queue 2 */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TXOK3
value|0x00000080
end_define

begin_comment
comment|/* TX complete on queue 3 */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXCNTOFLOW
value|0x00000400
end_define

begin_comment
comment|/* RX packet count overflow */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXPAUSE
value|0x00000800
end_define

begin_comment
comment|/* pause frame RX'ed */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXOFLOW
value|0x00001000
end_define

begin_comment
comment|/* RX FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXNODESC
value|0x00002000
end_define

begin_comment
comment|/* ran out of RX descriptors */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXNODESC_WARN
value|0x00004000
end_define

begin_comment
comment|/* running out of RX descs */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_LINKSTS
value|0x00008000
end_define

begin_comment
comment|/* link status change */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TIMER0
value|0x00010000
end_define

begin_comment
comment|/* one shot timer expired */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TIMER1
value|0x00020000
end_define

begin_comment
comment|/* periodic timer expired */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_PWR
value|0x00040000
end_define

begin_comment
comment|/* wake up power event */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_PHYINT
value|0x00080000
end_define

begin_comment
comment|/* PHY interrupt */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_STOPPED
value|0x00100000
end_define

begin_comment
comment|/* software shutdown complete */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_MIBOFLOW
value|0x00200000
end_define

begin_comment
comment|/* MIB counter overflow warning */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_SOFTINT
value|0x00400000
end_define

begin_comment
comment|/* software interrupt */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_HOLDOFF_RELOAD
value|0x00800000
end_define

begin_comment
comment|/* reload hold timer */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_RXDMA_STALL
value|0x01000000
end_define

begin_comment
comment|/* RX DMA stall */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_TXDMA_STALL
value|0x02000000
end_define

begin_comment
comment|/* TX DMA STALL */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_ISRC0
value|0x10000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_ISRC1
value|0x20000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_ISRC2
value|0x40000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_define
define|#
directive|define
name|VGE_ISR_ISRC3
value|0x80000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_define
define|#
directive|define
name|VGE_INTRS
value|(VGE_ISR_TXOK0|VGE_ISR_RXOK|VGE_ISR_STOPPED|	\ 			 VGE_ISR_RXOFLOW|VGE_ISR_PHYINT|		\ 			 VGE_ISR_LINKSTS|VGE_ISR_RXNODESC|		\ 			 VGE_ISR_RXDMA_STALL|VGE_ISR_TXDMA_STALL|	\ 			 VGE_ISR_TIMER0)
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXOK_HIPRIO
value|0x00000001
end_define

begin_comment
comment|/* hi prio RX int */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TXOK_HIPRIO
value|0x00000002
end_define

begin_comment
comment|/* hi prio TX int */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXOK
value|0x00000004
end_define

begin_comment
comment|/* normal RX done */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TXOK
value|0x00000008
end_define

begin_comment
comment|/* combo results for next 4 bits */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TXOK0
value|0x00000010
end_define

begin_comment
comment|/* TX complete on queue 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TXOK1
value|0x00000020
end_define

begin_comment
comment|/* TX complete on queue 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TXOK2
value|0x00000040
end_define

begin_comment
comment|/* TX complete on queue 2 */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TXOK3
value|0x00000080
end_define

begin_comment
comment|/* TX complete on queue 3 */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXCNTOFLOW
value|0x00000400
end_define

begin_comment
comment|/* RX packet count overflow */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXPAUSE
value|0x00000800
end_define

begin_comment
comment|/* pause frame RX'ed */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXOFLOW
value|0x00001000
end_define

begin_comment
comment|/* RX FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXNODESC
value|0x00002000
end_define

begin_comment
comment|/* ran out of RX descriptors */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXNODESC_WARN
value|0x00004000
end_define

begin_comment
comment|/* running out of RX descs */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_LINKSTS
value|0x00008000
end_define

begin_comment
comment|/* link status change */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TIMER0
value|0x00010000
end_define

begin_comment
comment|/* one shot timer expired */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TIMER1
value|0x00020000
end_define

begin_comment
comment|/* periodic timer expired */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_PWR
value|0x00040000
end_define

begin_comment
comment|/* wake up power event */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_PHYINT
value|0x00080000
end_define

begin_comment
comment|/* PHY interrupt */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_STOPPED
value|0x00100000
end_define

begin_comment
comment|/* software shutdown complete */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_MIBOFLOW
value|0x00200000
end_define

begin_comment
comment|/* MIB counter overflow warning */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_SOFTINT
value|0x00400000
end_define

begin_comment
comment|/* software interrupt */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_HOLDOFF_RELOAD
value|0x00800000
end_define

begin_comment
comment|/* reload hold timer */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_RXDMA_STALL
value|0x01000000
end_define

begin_comment
comment|/* RX DMA stall */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_TXDMA_STALL
value|0x02000000
end_define

begin_comment
comment|/* TX DMA STALL */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_ISRC0
value|0x10000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_ISRC1
value|0x20000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_ISRC2
value|0x40000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_define
define|#
directive|define
name|VGE_IMR_ISRC3
value|0x80000000
end_define

begin_comment
comment|/* interrupt source indication */
end_comment

begin_comment
comment|/* TX descriptor queue control/status register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_RUN0
value|0x0001
end_define

begin_comment
comment|/* Enable TX queue 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_ACT0
value|0x0002
end_define

begin_comment
comment|/* queue 0 active indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_WAK0
value|0x0004
end_define

begin_comment
comment|/* Wake up (poll) queue 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_DEAD0
value|0x0008
end_define

begin_comment
comment|/* queue 0 dead indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_RUN1
value|0x0010
end_define

begin_comment
comment|/* Enable TX queue 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_ACT1
value|0x0020
end_define

begin_comment
comment|/* queue 1 active indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_WAK1
value|0x0040
end_define

begin_comment
comment|/* Wake up (poll) queue 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_DEAD1
value|0x0080
end_define

begin_comment
comment|/* queue 1 dead indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_RUN2
value|0x0100
end_define

begin_comment
comment|/* Enable TX queue 2 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_ACT2
value|0x0200
end_define

begin_comment
comment|/* queue 2 active indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_WAK2
value|0x0400
end_define

begin_comment
comment|/* Wake up (poll) queue 2 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_DEAD2
value|0x0800
end_define

begin_comment
comment|/* queue 2 dead indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_RUN3
value|0x1000
end_define

begin_comment
comment|/* Enable TX queue 3 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_ACT3
value|0x2000
end_define

begin_comment
comment|/* queue 3 active indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_WAK3
value|0x4000
end_define

begin_comment
comment|/* Wake up (poll) queue 3 */
end_comment

begin_define
define|#
directive|define
name|VGE_TXQCSR_DEAD3
value|0x8000
end_define

begin_comment
comment|/* queue 3 dead indicator */
end_comment

begin_comment
comment|/* RX descriptor queue control/status register */
end_comment

begin_define
define|#
directive|define
name|VGE_RXQCSR_RUN
value|0x0001
end_define

begin_comment
comment|/* Enable RX queue */
end_comment

begin_define
define|#
directive|define
name|VGE_RXQCSR_ACT
value|0x0002
end_define

begin_comment
comment|/* queue active indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_RXQCSR_WAK
value|0x0004
end_define

begin_comment
comment|/* Wake up (poll) queue */
end_comment

begin_define
define|#
directive|define
name|VGE_RXQCSR_DEAD
value|0x0008
end_define

begin_comment
comment|/* queue dead indicator */
end_comment

begin_comment
comment|/* RX/TX queue empty interrupt delay timer register */
end_comment

begin_define
define|#
directive|define
name|VGE_QTIMER_PENDCNT
value|0x3F
end_define

begin_define
define|#
directive|define
name|VGE_QTIMER_RESOLUTION
value|0xC0
end_define

begin_define
define|#
directive|define
name|VGE_QTIMER_RES_1US
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_QTIMER_RES_4US
value|0x40
end_define

begin_define
define|#
directive|define
name|VGE_QTIMER_RES_16US
value|0x80
end_define

begin_define
define|#
directive|define
name|VGE_QTIMER_RES_64US
value|0xC0
end_define

begin_comment
comment|/* CAM address register */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMADDR_ADDR
value|0x3F
end_define

begin_comment
comment|/* CAM address to program */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMADDR_AVSEL
value|0x40
end_define

begin_comment
comment|/* 0 = address cam, 1 = VLAN cam */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMADDR_ENABLE
value|0x80
end_define

begin_comment
comment|/* enable CAM read/write */
end_comment

begin_define
define|#
directive|define
name|VGE_CAM_MAXADDRS
value|64
end_define

begin_comment
comment|/*  * CAM command register  * Note that the page select bits in this register affect three  * different things:  * - The behavior of the MAR0/MAR1 registers at offset 0x10 (the  *   page select bits control whether the MAR0/MAR1 registers affect  *   the multicast hash filter or the CAM table)  * - The behavior of the interrupt holdoff timer register at offset  *   0x20 (the page select bits allow you to set the interrupt  *   holdoff timer, the TX interrupt supression count or the  *   RX interrupt supression count)  * - The behavior the WOL pattern programming registers at offset  *   0xC0 (controls which pattern is set)  */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMCTL_WRITE
value|0x04
end_define

begin_comment
comment|/* CAM write command */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMCTL_READ
value|0x08
end_define

begin_comment
comment|/* CAM read command */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMCTL_INTPKT_SIZ
value|0x10
end_define

begin_comment
comment|/* select interesting pkt CAM size */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMCTL_INTPKT_ENB
value|0x20
end_define

begin_comment
comment|/* enable interesting packet mode */
end_comment

begin_define
define|#
directive|define
name|VGE_CAMCTL_PAGESEL
value|0xC0
end_define

begin_comment
comment|/* page select */
end_comment

begin_define
define|#
directive|define
name|VGE_PAGESEL_MAR
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_PAGESEL_CAMMASK
value|0x40
end_define

begin_define
define|#
directive|define
name|VGE_PAGESEL_CAMDATA
value|0x80
end_define

begin_define
define|#
directive|define
name|VGE_PAGESEL_INTHLDOFF
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_PAGESEL_TXSUPPTHR
value|0x40
end_define

begin_define
define|#
directive|define
name|VGE_PAGESEL_RXSUPPTHR
value|0x80
end_define

begin_define
define|#
directive|define
name|VGE_PAGESEL_WOLPAT0
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_PAGESEL_WOLPAT1
value|0x40
end_define

begin_comment
comment|/* MII port config register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICFG_PHYADDR
value|0x1F
end_define

begin_comment
comment|/* PHY address (internal PHY is 1) */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICFG_MDCSPEED
value|0x20
end_define

begin_comment
comment|/* MDC accelerate x 4 */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICFG_POLLINT
value|0xC0
end_define

begin_comment
comment|/* polling interval */
end_comment

begin_define
define|#
directive|define
name|VGE_MIIPOLLINT_1024
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_MIIPOLLINT_512
value|0x40
end_define

begin_define
define|#
directive|define
name|VGE_MIIPOLLINT_128
value|0x80
end_define

begin_define
define|#
directive|define
name|VGE_MIIPOLLINT_64
value|0xC0
end_define

begin_comment
comment|/* MII port status register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIISTS_IIDL
value|0x80
end_define

begin_comment
comment|/* not at sofrware/timer poll cycle */
end_comment

begin_comment
comment|/* PHY status register */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS_TXFLOWCAP
value|0x01
end_define

begin_comment
comment|/* resolved TX flow control cap */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS_RXFLOWCAP
value|0x02
end_define

begin_comment
comment|/* resolved RX flow control cap */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS_SPEED10
value|0x04
end_define

begin_comment
comment|/* PHY in 10Mbps mode */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS_SPEED1000
value|0x08
end_define

begin_comment
comment|/* PHY in giga mode */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS_FDX
value|0x10
end_define

begin_comment
comment|/* PHY in full duplex mode */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS_LINK
value|0x40
end_define

begin_comment
comment|/* link status */
end_comment

begin_define
define|#
directive|define
name|VGE_PHYSTS_RESETSTS
value|0x80
end_define

begin_comment
comment|/* reset status */
end_comment

begin_comment
comment|/* MII management command register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_MDC
value|0x01
end_define

begin_comment
comment|/* clock pin */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_MDI
value|0x02
end_define

begin_comment
comment|/* data in pin */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_MDO
value|0x04
end_define

begin_comment
comment|/* data out pin */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_MOUT
value|0x08
end_define

begin_comment
comment|/* data out pin enable */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_MDP
value|0x10
end_define

begin_comment
comment|/* enable direct programming mode */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_WCMD
value|0x20
end_define

begin_comment
comment|/* embedded mode write */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_RCMD
value|0x40
end_define

begin_comment
comment|/* embadded mode read */
end_comment

begin_define
define|#
directive|define
name|VGE_MIICMD_MAUTO
value|0x80
end_define

begin_comment
comment|/* enable autopolling */
end_comment

begin_comment
comment|/* MII address register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIIADDR_SWMPL
value|0x80
end_define

begin_comment
comment|/* initiate priority resolution */
end_comment

begin_comment
comment|/* Chip config register A */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG0_PACPI
value|0x01
end_define

begin_comment
comment|/* pre-ACPI wakeup function */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG0_ABSHDN
value|0x02
end_define

begin_comment
comment|/* abnormal shutdown function */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG0_GPIO1PD
value|0x04
end_define

begin_comment
comment|/* GPIO pin enable */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG0_SKIPTAG
value|0x08
end_define

begin_comment
comment|/* omit 802.1p tag from CRC calc */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG0_PHLED
value|0x30
end_define

begin_comment
comment|/* phy LED select */
end_comment

begin_comment
comment|/* Chip config register B */
end_comment

begin_comment
comment|/* Note: some of these bits are not documented in the manual! */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_BAKOPT
value|0x01
end_define

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_MBA
value|0x02
end_define

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_CAP
value|0x04
end_define

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_CRANDOM
value|0x08
end_define

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_OFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_SLOTTIME
value|0x20
end_define

begin_comment
comment|/* slot time 512/500 in giga mode */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_MIIOPT
value|0x40
end_define

begin_define
define|#
directive|define
name|VGE_CHIPCFG1_GTCKOPT
value|0x80
end_define

begin_comment
comment|/* Chip config register C */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG2_EELOAD
value|0x80
end_define

begin_comment
comment|/* enable EEPROM programming */
end_comment

begin_comment
comment|/* Chip config register D */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG3_64BIT_DAC
value|0x20
end_define

begin_comment
comment|/* enable 64bit via DAC */
end_comment

begin_define
define|#
directive|define
name|VGE_CHIPCFG3_IODISABLE
value|0x80
end_define

begin_comment
comment|/* disable I/O access mode */
end_comment

begin_comment
comment|/* DMA config register 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG0_BURSTLEN
value|0x07
end_define

begin_comment
comment|/* RX/TX DMA burst (in dwords) */
end_comment

begin_define
define|#
directive|define
name|VGE_DMABURST_8
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_DMABURST_16
value|0x01
end_define

begin_define
define|#
directive|define
name|VGE_DMABURST_32
value|0x02
end_define

begin_define
define|#
directive|define
name|VGE_DMABURST_64
value|0x03
end_define

begin_define
define|#
directive|define
name|VGE_DMABURST_128
value|0x04
end_define

begin_define
define|#
directive|define
name|VGE_DMABURST_256
value|0x05
end_define

begin_define
define|#
directive|define
name|VGE_DMABURST_STRFWD
value|0x07
end_define

begin_comment
comment|/* DMA config register 1 */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG1_LATENB
value|0x01
end_define

begin_comment
comment|/* Latency timer enable */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG1_MWWAIT
value|0x02
end_define

begin_comment
comment|/* insert wait on master write */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG1_MRWAIT
value|0x04
end_define

begin_comment
comment|/* insert wait on master read */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG1_MRM
value|0x08
end_define

begin_comment
comment|/* use memory read multiple */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG1_PERR_DIS
value|0x10
end_define

begin_comment
comment|/* disable parity error checking */
end_comment

begin_define
define|#
directive|define
name|VGE_DMACFG1_XMRL
value|0x20
end_define

begin_comment
comment|/* disable memory read line support */
end_comment

begin_comment
comment|/* RX MAC config register */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCFG_VLANFILT
value|0x01
end_define

begin_comment
comment|/* filter VLAN ID mismatches */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCFG_VTAGOPT
value|0x06
end_define

begin_comment
comment|/* VLAN tag handling */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCFG_FIFO_LOWAT
value|0x08
end_define

begin_comment
comment|/* RX FIFO low watermark (7QW/15QW) */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCFG_FIFO_THR
value|0x30
end_define

begin_comment
comment|/* RX FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|VGE_RXCFG_ARB_PRIO
value|0x80
end_define

begin_comment
comment|/* arbitration priority */
end_comment

begin_define
define|#
directive|define
name|VGE_VTAG_OPT0
value|0x00
end_define

begin_comment
comment|/* TX: no tag insertion 					   RX: rx all, no tag extraction */
end_comment

begin_define
define|#
directive|define
name|VGE_VTAG_OPT1
value|0x02
end_define

begin_comment
comment|/* TX: no tag insertion 					   RX: rx only tagged pkts, no 					       extraction */
end_comment

begin_define
define|#
directive|define
name|VGE_VTAG_OPT2
value|0x04
end_define

begin_comment
comment|/* TX: perform tag insertion, 					   RX: rx all, extract tags */
end_comment

begin_define
define|#
directive|define
name|VGE_VTAG_OPT3
value|0x06
end_define

begin_comment
comment|/* TX: perform tag insertion, 					   RX: rx only tagged pkts, 					       with extraction */
end_comment

begin_define
define|#
directive|define
name|VGE_RXFIFOTHR_128BYTES
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_RXFIFOTHR_512BYTES
value|0x10
end_define

begin_define
define|#
directive|define
name|VGE_RXFIFOTHR_1024BYTES
value|0x20
end_define

begin_define
define|#
directive|define
name|VGE_RXFIFOTHR_STRNFWD
value|0x30
end_define

begin_comment
comment|/* TX MAC config register */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCFG_SNAPOPT
value|0x01
end_define

begin_comment
comment|/* 1 == insert VLAN tag at 					   13th byte 					   0 == insert VLANM tag after 					   SNAP header (21st byte) */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCFG_NONBLK
value|0x02
end_define

begin_comment
comment|/* priority TX/non-blocking mode */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCFG_NONBLK_THR
value|0x0C
end_define

begin_comment
comment|/* non-blocking threshold */
end_comment

begin_define
define|#
directive|define
name|VGE_TXCFG_ARB_PRIO
value|0x80
end_define

begin_comment
comment|/* arbitration priority */
end_comment

begin_define
define|#
directive|define
name|VGE_TXBLOCK_64PKTS
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_TXBLOCK_32PKTS
value|0x04
end_define

begin_define
define|#
directive|define
name|VGE_TXBLOCK_128PKTS
value|0x08
end_define

begin_define
define|#
directive|define
name|VGE_TXBLOCK_8PKTS
value|0x0C
end_define

begin_comment
comment|/* MIB control/status register */
end_comment

begin_define
define|#
directive|define
name|VGE_MIBCSR_CLR
value|0x01
end_define

begin_define
define|#
directive|define
name|VGE_MIBCSR_RINI
value|0x02
end_define

begin_define
define|#
directive|define
name|VGE_MIBCSR_FLUSH
value|0x04
end_define

begin_define
define|#
directive|define
name|VGE_MIBCSR_FREEZE
value|0x08
end_define

begin_define
define|#
directive|define
name|VGE_MIBCSR_HI_80
value|0x00
end_define

begin_define
define|#
directive|define
name|VGE_MIBCSR_HI_C0
value|0x10
end_define

begin_define
define|#
directive|define
name|VGE_MIBCSR_BISTGO
value|0x40
end_define

begin_define
define|#
directive|define
name|VGE_MIBCSR_BISTOK
value|0x80
end_define

begin_comment
comment|/* MIB data index. */
end_comment

begin_define
define|#
directive|define
name|VGE_MIB_RX_FRAMES
value|0
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_GOOD_FRAMES
value|1
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_GOOD_FRAMES
value|2
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_FIFO_OVERRUNS
value|3
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_RUNTS
value|4
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_RUNTS_ERRS
value|5
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_64
value|6
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_PKTS_64
value|7
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_65_127
value|8
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_PKTS_65_127
value|9
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_128_255
value|10
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_PKTS_128_255
value|11
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_256_511
value|12
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_PKTS_256_511
value|13
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_512_1023
value|14
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_PKTS_512_1023
value|15
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_1024_1518
value|16
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_PKTS_1024_1518
value|17
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_COLLS
value|18
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_CRCERRS
value|19
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_JUMBOS
value|20
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_JUMBOS
value|21
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PAUSE
value|22
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_PAUSE
value|23
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_ALIGNERRS
value|24
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_1519_MAX
value|25
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_PKTS_1519_MAX_ERRS
value|26
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_SQEERRS
value|27
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_NOBUFS
value|28
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_SYMERRS
value|29
end_define

begin_define
define|#
directive|define
name|VGE_MIB_RX_LENERRS
value|30
end_define

begin_define
define|#
directive|define
name|VGE_MIB_TX_LATECOLLS
value|31
end_define

begin_define
define|#
directive|define
name|VGE_MIB_CNT
value|(VGE_MIB_TX_LATECOLLS - VGE_MIB_RX_FRAMES + 1)
end_define

begin_define
define|#
directive|define
name|VGE_MIB_DATA_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|VGE_MIB_DATA_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)>> 24)
end_define

begin_comment
comment|/* EEPROM control/status register */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR_EDO
value|0x01
end_define

begin_comment
comment|/* data out pin */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR_EDI
value|0x02
end_define

begin_comment
comment|/* data in pin */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR_ECK
value|0x04
end_define

begin_comment
comment|/* clock pin */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR_ECS
value|0x08
end_define

begin_comment
comment|/* chip select pin */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR_DPM
value|0x10
end_define

begin_comment
comment|/* direct program mode enable */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR_RELOAD
value|0x20
end_define

begin_comment
comment|/* trigger reload from EEPROM */
end_comment

begin_define
define|#
directive|define
name|VGE_EECSR_EMBP
value|0x40
end_define

begin_comment
comment|/* embedded program mode enable */
end_comment

begin_comment
comment|/* EEPROM embedded command register */
end_comment

begin_define
define|#
directive|define
name|VGE_EECMD_ERD
value|0x01
end_define

begin_comment
comment|/* EEPROM read command */
end_comment

begin_define
define|#
directive|define
name|VGE_EECMD_EWR
value|0x02
end_define

begin_comment
comment|/* EEPROM write command */
end_comment

begin_define
define|#
directive|define
name|VGE_EECMD_EWEN
value|0x04
end_define

begin_comment
comment|/* EEPROM write enable */
end_comment

begin_define
define|#
directive|define
name|VGE_EECMD_EWDIS
value|0x08
end_define

begin_comment
comment|/* EEPROM write disable */
end_comment

begin_define
define|#
directive|define
name|VGE_EECMD_EDONE
value|0x80
end_define

begin_comment
comment|/* read/write done */
end_comment

begin_comment
comment|/* Chip operation and diagnostic control register */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_PHYINT_ENB
value|0x01
end_define

begin_comment
comment|/* Enable PHY interrupts */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_TIMER0_RES
value|0x02
end_define

begin_comment
comment|/* timer0 uSec resolution */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_TIMER1_RES
value|0x04
end_define

begin_comment
comment|/* timer1 uSec resolution */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_LPSEL_DIS
value|0x08
end_define

begin_comment
comment|/* disable LPSEL field */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_MACFORCE
value|0x10
end_define

begin_comment
comment|/* MAC side force mode */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_FCRSVD
value|0x20
end_define

begin_comment
comment|/* reserved for future fiber use */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_FDXFORCE
value|0x40
end_define

begin_comment
comment|/* force full duplex mode */
end_comment

begin_define
define|#
directive|define
name|VGE_DIAGCTL_GMII
value|0x80
end_define

begin_comment
comment|/* force GMII mode, otherwise MII */
end_comment

begin_comment
comment|/* Location of station address in EEPROM */
end_comment

begin_define
define|#
directive|define
name|VGE_EE_EADDR
value|0
end_define

begin_comment
comment|/* DMA descriptor structures */
end_comment

begin_comment
comment|/*  * Each TX DMA descriptor has a control and status word, and 7  * fragment address/length words. If a transmitted packet spans  * more than 7 fragments, it has to be coalesced.  */
end_comment

begin_define
define|#
directive|define
name|VGE_TX_FRAGS
value|7
end_define

begin_struct
struct|struct
name|vge_tx_frag
block|{
name|uint32_t
name|vge_addrlo
decl_stmt|;
name|uint32_t
name|vge_addrhi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The high bit in the buflen field of fragment #0 has special meaning.  * Normally, the chip requires the driver to issue a TX poll command  * for every packet that gets put in the TX DMA queue. Sometimes though,  * the driver might want to queue up several packets at once and just  * issue one transmit command to have all of them processed. In order  * to obtain this behavior, the special 'queue' bit must be set.  */
end_comment

begin_define
define|#
directive|define
name|VGE_TXDESC_Q
value|0x80000000
end_define

begin_struct
struct|struct
name|vge_tx_desc
block|{
name|uint32_t
name|vge_sts
decl_stmt|;
name|uint32_t
name|vge_ctl
decl_stmt|;
name|struct
name|vge_tx_frag
name|vge_frag
index|[
name|VGE_TX_FRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGE_TDSTS_COLLCNT
value|0x0000000F
end_define

begin_comment
comment|/* TX collision count */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_COLL
value|0x00000010
end_define

begin_comment
comment|/* collision seen */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_OWINCOLL
value|0x00000020
end_define

begin_comment
comment|/* out of window collision */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_OWT
value|0x00000040
end_define

begin_comment
comment|/* jumbo frame tx abort */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_EXCESSCOLL
value|0x00000080
end_define

begin_comment
comment|/* TX aborted, excess colls */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_HBEATFAIL
value|0x00000100
end_define

begin_comment
comment|/* heartbeat detect failed */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_CARRLOSS
value|0x00000200
end_define

begin_comment
comment|/* carrier sense lost */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_SHUTDOWN
value|0x00000400
end_define

begin_comment
comment|/* shutdown during TX */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_LINKFAIL
value|0x00001000
end_define

begin_comment
comment|/* link fail during TX */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_GMII
value|0x00002000
end_define

begin_comment
comment|/* GMII transmission */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_FDX
value|0x00004000
end_define

begin_comment
comment|/* full duplex transmit */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_TXERR
value|0x00008000
end_define

begin_comment
comment|/* error occurred */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_SEGSIZE
value|0x3FFF0000
end_define

begin_comment
comment|/* TCP large send size */
end_comment

begin_define
define|#
directive|define
name|VGE_TDSTS_OWN
value|0x80000000
end_define

begin_comment
comment|/* own bit */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_VLANID
value|0x00000FFF
end_define

begin_comment
comment|/* VLAN ID */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_CFI
value|0x00001000
end_define

begin_comment
comment|/* VLAN CFI bit */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_PRIO
value|0x0000E000
end_define

begin_comment
comment|/* VLAN prio bits */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_NOCRC
value|0x00010000
end_define

begin_comment
comment|/* disable CRC generation */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_JUMBO
value|0x00020000
end_define

begin_comment
comment|/* jumbo frame */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_TCPCSUM
value|0x00040000
end_define

begin_comment
comment|/* do TCP hw checksum */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_UDPCSUM
value|0x00080000
end_define

begin_comment
comment|/* do UDP hw checksum */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_IPCSUM
value|0x00100000
end_define

begin_comment
comment|/* do IP hw checksum */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_VTAG
value|0x00200000
end_define

begin_comment
comment|/* insert VLAN tag */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_PRIO_INT
value|0x00400000
end_define

begin_comment
comment|/* priority int request */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_TIC
value|0x00800000
end_define

begin_comment
comment|/* transfer int request */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_TCPLSCTL
value|0x03000000
end_define

begin_comment
comment|/* TCP large send ctl */
end_comment

begin_define
define|#
directive|define
name|VGE_TDCTL_FRAGCNT
value|0xF0000000
end_define

begin_comment
comment|/* number of frags used */
end_comment

begin_define
define|#
directive|define
name|VGE_TD_LS_MOF
value|0x00000000
end_define

begin_comment
comment|/* middle of large send */
end_comment

begin_define
define|#
directive|define
name|VGE_TD_LS_SOF
value|0x01000000
end_define

begin_comment
comment|/* start of large send */
end_comment

begin_define
define|#
directive|define
name|VGE_TD_LS_EOF
value|0x02000000
end_define

begin_comment
comment|/* end of large send */
end_comment

begin_define
define|#
directive|define
name|VGE_TD_LS_NORM
value|0x03000000
end_define

begin_comment
comment|/* normal frame */
end_comment

begin_comment
comment|/* Receive DMA descriptors have a single fragment pointer. */
end_comment

begin_struct
struct|struct
name|vge_rx_desc
block|{
name|uint32_t
name|vge_sts
decl_stmt|;
name|uint32_t
name|vge_ctl
decl_stmt|;
name|uint32_t
name|vge_addrlo
decl_stmt|;
name|uint32_t
name|vge_addrhi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Like the TX descriptor, the high bit in the buflen field in the  * RX descriptor has special meaning. This bit controls whether or  * not interrupts are generated for this descriptor.  */
end_comment

begin_define
define|#
directive|define
name|VGE_RXDESC_I
value|0x80000000
end_define

begin_define
define|#
directive|define
name|VGE_RDSTS_VIDM
value|0x00000001
end_define

begin_comment
comment|/* VLAN tag filter miss */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_CRCERR
value|0x00000002
end_define

begin_comment
comment|/* bad CRC error */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_FAERR
value|0x00000004
end_define

begin_comment
comment|/* frame alignment error */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_CSUMERR
value|0x00000008
end_define

begin_comment
comment|/* bad TCP/IP checksum */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_RLERR
value|0x00000010
end_define

begin_comment
comment|/* RX length error */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_SYMERR
value|0x00000020
end_define

begin_comment
comment|/* PCS symbol error */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_SNTAG
value|0x00000040
end_define

begin_comment
comment|/* RX'ed tagged SNAP pkt */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_DETAG
value|0x00000080
end_define

begin_comment
comment|/* VLAN tag extracted */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_BOUNDARY
value|0x00000300
end_define

begin_comment
comment|/* frame boundary bits */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_VTAG
value|0x00000400
end_define

begin_comment
comment|/* VLAN tag indicator */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_UCAST
value|0x00000800
end_define

begin_comment
comment|/* unicast frame */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_BCAST
value|0x00001000
end_define

begin_comment
comment|/* broadcast frame */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_MCAST
value|0x00002000
end_define

begin_comment
comment|/* multicast frame */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_PFT
value|0x00004000
end_define

begin_comment
comment|/* perfect filter hit */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_RXOK
value|0x00008000
end_define

begin_comment
comment|/* frame is good. */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_BUFSIZ
value|0x3FFF0000
end_define

begin_comment
comment|/* received frame len */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_SHUTDOWN
value|0x40000000
end_define

begin_comment
comment|/* shutdown during RX */
end_comment

begin_define
define|#
directive|define
name|VGE_RDSTS_OWN
value|0x80000000
end_define

begin_comment
comment|/* own bit. */
end_comment

begin_define
define|#
directive|define
name|VGE_RXPKT_ONEFRAG
value|0x00000000
end_define

begin_comment
comment|/* only one fragment */
end_comment

begin_define
define|#
directive|define
name|VGE_RXPKT_EOF
value|0x00000100
end_define

begin_comment
comment|/* first frag in frame */
end_comment

begin_define
define|#
directive|define
name|VGE_RXPKT_SOF
value|0x00000200
end_define

begin_comment
comment|/* last frag in frame */
end_comment

begin_define
define|#
directive|define
name|VGE_RXPKT_MOF
value|0x00000300
end_define

begin_comment
comment|/* intermediate frag */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_VLANID
value|0x0000FFFF
end_define

begin_comment
comment|/* VLAN ID info */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_UDPPKT
value|0x00010000
end_define

begin_comment
comment|/* UDP packet received */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_TCPPKT
value|0x00020000
end_define

begin_comment
comment|/* TCP packet received */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_IPPKT
value|0x00040000
end_define

begin_comment
comment|/* IP packet received */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_UDPZERO
value|0x00080000
end_define

begin_comment
comment|/* pkt with UDP CSUM of 0 */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_FRAG
value|0x00100000
end_define

begin_comment
comment|/* received IP frag */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_PROTOCSUMOK
value|0x00200000
end_define

begin_comment
comment|/* TCP/UDP checksum ok */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_IPCSUMOK
value|0x00400000
end_define

begin_comment
comment|/* IP checksum ok */
end_comment

begin_define
define|#
directive|define
name|VGE_RDCTL_FILTIDX
value|0x3C000000
end_define

begin_comment
comment|/* interesting filter idx */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_VGEREG_H_ */
end_comment

end_unit

