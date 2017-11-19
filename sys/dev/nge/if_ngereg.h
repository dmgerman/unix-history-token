begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 2001 Wind River Systems  * Copyright (c) 1997, 1998, 1999, 2000, 2001  *	Bill Paul<wpaul@bsdi.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NGE_CSR
value|0x00
end_define

begin_define
define|#
directive|define
name|NGE_CFG
value|0x04
end_define

begin_define
define|#
directive|define
name|NGE_MEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|NGE_PCITST
value|0x0C
end_define

begin_define
define|#
directive|define
name|NGE_ISR
value|0x10
end_define

begin_define
define|#
directive|define
name|NGE_IMR
value|0x14
end_define

begin_define
define|#
directive|define
name|NGE_IER
value|0x18
end_define

begin_define
define|#
directive|define
name|NGE_IHR
value|0x1C
end_define

begin_define
define|#
directive|define
name|NGE_TX_LISTPTR_LO
value|0x20
end_define

begin_define
define|#
directive|define
name|NGE_TX_LISTPTR_HI
value|0x24
end_define

begin_define
define|#
directive|define
name|NGE_TX_LISTPTR
value|NGE_TX_LISTPTR_LO
end_define

begin_define
define|#
directive|define
name|NGE_TX_CFG
value|0x28
end_define

begin_define
define|#
directive|define
name|NGE_GPIO
value|0x2C
end_define

begin_define
define|#
directive|define
name|NGE_RX_LISTPTR_LO
value|0x30
end_define

begin_define
define|#
directive|define
name|NGE_RX_LISTPTR_HI
value|0x34
end_define

begin_define
define|#
directive|define
name|NGE_RX_LISTPTR
value|NGE_RX_LISTPTR_LO
end_define

begin_define
define|#
directive|define
name|NGE_RX_CFG
value|0x38
end_define

begin_define
define|#
directive|define
name|NGE_PRIOQCTL
value|0x3C
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR
value|0x40
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR
value|0x44
end_define

begin_define
define|#
directive|define
name|NGE_RXFILT_CTL
value|0x48
end_define

begin_define
define|#
directive|define
name|NGE_RXFILT_DATA
value|0x4C
end_define

begin_define
define|#
directive|define
name|NGE_BOOTROM_ADDR
value|0x50
end_define

begin_define
define|#
directive|define
name|NGE_BOOTROM_DATA
value|0x54
end_define

begin_define
define|#
directive|define
name|NGE_SILICONREV
value|0x58
end_define

begin_define
define|#
directive|define
name|NGE_MIBCTL
value|0x5C
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXERRPKT
value|0x60
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXERRFCS
value|0x64
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXERRMISSEDPKT
value|0x68
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXERRALIGN
value|0x6C
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXERRSYM
value|0x70
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXERRGIANT
value|0x74
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXERRRANGLEN
value|0x78
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXBADOPCODE
value|0x7C
end_define

begin_define
define|#
directive|define
name|NGE_MIB_RXPAUSEPKTS
value|0x80
end_define

begin_define
define|#
directive|define
name|NGE_MIB_TXPAUSEPKTS
value|0x84
end_define

begin_define
define|#
directive|define
name|NGE_MIB_TXERRSQE
value|0x88
end_define

begin_define
define|#
directive|define
name|NGE_TXPRIOQ_PTR1
value|0xA0
end_define

begin_define
define|#
directive|define
name|NGE_TXPRIOQ_PTR2
value|0xA4
end_define

begin_define
define|#
directive|define
name|NGE_TXPRIOQ_PTR3
value|0xA8
end_define

begin_define
define|#
directive|define
name|NGE_RXPRIOQ_PTR1
value|0xB0
end_define

begin_define
define|#
directive|define
name|NGE_RXPRIOQ_PTR2
value|0xB4
end_define

begin_define
define|#
directive|define
name|NGE_RXPRIOQ_PTR3
value|0xB8
end_define

begin_define
define|#
directive|define
name|NGE_VLAN_IP_RXCTL
value|0xBC
end_define

begin_define
define|#
directive|define
name|NGE_VLAN_IP_TXCTL
value|0xC0
end_define

begin_define
define|#
directive|define
name|NGE_VLAN_DATA
value|0xC4
end_define

begin_define
define|#
directive|define
name|NGE_CLKRUN
value|0xCC
end_define

begin_define
define|#
directive|define
name|NGE_TBI_BMCR
value|0xE0
end_define

begin_define
define|#
directive|define
name|NGE_TBI_BMSR
value|0xE4
end_define

begin_define
define|#
directive|define
name|NGE_TBI_ANAR
value|0xE8
end_define

begin_define
define|#
directive|define
name|NGE_TBI_ANLPAR
value|0xEC
end_define

begin_define
define|#
directive|define
name|NGE_TBI_ANER
value|0xF0
end_define

begin_define
define|#
directive|define
name|NGE_TBI_ESR
value|0xF4
end_define

begin_comment
comment|/* Control/status register */
end_comment

begin_define
define|#
directive|define
name|NGE_CSR_TX_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_CSR_TX_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RX_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RX_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_CSR_TX_RESET
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RX_RESET
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_CSR_SOFTINTR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RESET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_CSR_TX_PRIOQ_ENB0
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_CSR_TX_PRIOQ_ENB1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NGE_CSR_TX_PRIOQ_ENB2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NGE_CSR_TX_PRIOQ_ENB3
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RX_PRIOQ_ENB0
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RX_PRIOQ_ENB1
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RX_PRIOQ_ENB2
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NGE_CSR_RX_PRIOQ_ENB3
value|0x00010000
end_define

begin_comment
comment|/* Configuration register */
end_comment

begin_define
define|#
directive|define
name|NGE_CFG_BIGENDIAN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_CFG_EXT_125MHZ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_CFG_BOOTROM_DIS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_CFG_PERR_DETECT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_CFG_DEFER_DISABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_CFG_OUTOFWIN_TIMER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_CFG_SINGLE_BACKOFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_CFG_PCIREQ_ALG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_CFG_EXTSTS_ENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_CFG_PHY_DIS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_CFG_PHY_RST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NGE_CFG_64BIT_ADDR_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NGE_CFG_64BIT_DATA_ENB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_64BIT_PCI_DET
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_64BIT_TARG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_MWI_DIS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_MRM_DIS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_TMRTST
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_PHYINTR_SPD
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_PHYINTR_LNK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_PHYINTR_DUP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_MODE_1000
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_TBI_EN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_DUPLEX_STS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_SPEED_STS
value|0x60000000
end_define

begin_define
define|#
directive|define
name|NGE_CFG_LINK_STS
value|0x80000000
end_define

begin_comment
comment|/* MII/EEPROM control register */
end_comment

begin_define
define|#
directive|define
name|NGE_MEAR_EE_DIN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_MEAR_EE_DOUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_MEAR_EE_CLK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_MEAR_EE_CSEL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_MEAR_MII_DATA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_MEAR_MII_DIR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_MEAR_MII_CLK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|NGE_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|NGE_EECMD_ERASE
value|0x1c0
end_define

begin_define
define|#
directive|define
name|NGE_EE_NODEADDR
value|0xA
end_define

begin_comment
comment|/* PCI control register */
end_comment

begin_define
define|#
directive|define
name|NGE_PCICTL_SRAMADDR
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|NGE_PCICTL_RAMTSTENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_PCICTL_TXTSTENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_PCICTL_RXTSTENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_PCICTL_BMTSTENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_PCICTL_RAMADDR
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|NGE_PCICTL_ROMTIME
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|NGE_PCICTL_DISCTEST
value|0x40000000
end_define

begin_comment
comment|/* Interrupt/status register */
end_comment

begin_define
define|#
directive|define
name|NGE_ISR_RX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_DESC_OK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_EARLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_IDLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_OFLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_DESC_OK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_ERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_IDLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_UFLOW
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NGE_ISR_MIB_SERVICE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NGE_ISR_SOFTINTR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_PME_EVENT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_PHY_INTR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_HIBITS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_FIFO_OFLOW
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TGT_ABRT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_BM_ABRT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_SYSERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_PARITY_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_RESET_DONE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_RESET_DONE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_PRIOQ_DESC0
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_PRIOQ_DESC1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_PRIOQ_DESC2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_RX_PRIOQ_DESC3
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_PRIOQ_DESC0
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_PRIOQ_DESC1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_PRIOQ_DESC2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NGE_ISR_TX_PRIOQ_DESC3
value|0x40000000
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|NGE_IMR_RX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_DESC_OK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_EARLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_IDLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_OFLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_DESC_OK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_ERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_IDLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_UFLOW
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NGE_IMR_MIB_SERVICE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NGE_IMR_SOFTINTR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_PME_EVENT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_PHY_INTR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_HIBITS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_FIFO_OFLOW
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TGT_ABRT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_BM_ABRT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_SYSERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_PARITY_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_RESET_DONE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_RESET_DONE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_PRIOQ_DESC0
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_PRIOQ_DESC1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_PRIOQ_DESC2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_RX_PRIOQ_DESC3
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_PRIOQ_DESC0
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_PRIOQ_DESC1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_PRIOQ_DESC2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NGE_IMR_TX_PRIOQ_DESC3
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NGE_INTRS
define|\
value|(NGE_IMR_RX_OFLOW|NGE_IMR_TX_UFLOW|NGE_IMR_TX_OK|\ 	 NGE_IMR_TX_IDLE|NGE_IMR_RX_OK|NGE_IMR_RX_ERR|\ 	 NGE_IMR_SYSERR|NGE_IMR_PHY_INTR|\ 	 NGE_IMR_RX_IDLE|NGE_IMR_RX_FIFO_OFLOW)
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|NGE_IER_INTRENB
value|0x00000001
end_define

begin_comment
comment|/* Interrupt moderation timer register */
end_comment

begin_define
define|#
directive|define
name|NGE_IHR_HOLDOFF
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|NGE_IHR_HOLDCTL
value|0x00000100
end_define

begin_comment
comment|/* Transmit configuration register */
end_comment

begin_define
define|#
directive|define
name|NGE_TXCFG_DRAIN_THRESH
value|0x000000FF
end_define

begin_comment
comment|/* 32-byte units */
end_comment

begin_define
define|#
directive|define
name|NGE_TXCFG_FILL_THRESH
value|0x0000FF00
end_define

begin_comment
comment|/* 32-byte units */
end_comment

begin_define
define|#
directive|define
name|NGE_1000MB_BURST_DIS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_DMABURST
value|0x00700000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_ECRETRY
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_AUTOPAD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_LOOPBK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_IGN_HBEAT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_IGN_CARR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_DRAIN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& NGE_TXCFG_DRAIN_THRESH)
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG_FILL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 5)<< 8)& NGE_TXCFG_FILL_THRESH)
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_1024BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_8BYTES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_16BYTES
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_32BYTES
value|0x00300000
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_64BYTES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_128BYTES
value|0x00500000
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_256BYTES
value|0x00600000
end_define

begin_define
define|#
directive|define
name|NGE_TXDMA_512BYTES
value|0x00700000
end_define

begin_define
define|#
directive|define
name|NGE_TXCFG
define|\
value|(NGE_TXDMA_512BYTES|NGE_TXCFG_AUTOPAD|\ 	 NGE_TXCFG_FILL(64)|NGE_TXCFG_DRAIN(6400))
end_define

begin_comment
comment|/* GPIO register */
end_comment

begin_define
define|#
directive|define
name|NGE_GPIO_GP1_OUT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP2_OUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP3_OUT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP4_OUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP5_OUT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP1_OUTENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP2_OUTENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP3_OUTENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP4_OUTENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP5_OUTENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP1_IN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP2_IN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP3_IN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP4_IN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NGE_GPIO_GP5_IN
value|0x00004000
end_define

begin_comment
comment|/* Receive configuration register */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_DRAIN_THRESH
value|0x0000003E
end_define

begin_comment
comment|/* 8-byte units */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_DMABURST
value|0x00700000
end_define

begin_define
define|#
directive|define
name|NGE_RXCFG_RX_RANGEERR
value|0x04000000
end_define

begin_comment
comment|/* accept in-range err frames */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_RX_GIANTS
value|0x08000000
end_define

begin_comment
comment|/* accept packets> 1518 bytes */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_RX_FDX
value|0x10000000
end_define

begin_comment
comment|/* full duplex receive */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_RX_NOCRC
value|0x20000000
end_define

begin_comment
comment|/* strip CRC */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_RX_RUNT
value|0x40000000
end_define

begin_comment
comment|/* accept short frames */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_RX_BADPKTS
value|0x80000000
end_define

begin_comment
comment|/* accept error frames */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG_DRAIN
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 3)<< 1)& NGE_RXCFG_DRAIN_THRESH)
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_1024BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_8BYTES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_16BYTES
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_32YTES
value|0x00300000
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_64BYTES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_128BYTES
value|0x00500000
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_256BYTES
value|0x00600000
end_define

begin_define
define|#
directive|define
name|NGE_RXDMA_512BYTES
value|0x00700000
end_define

begin_comment
comment|/*  * DP83820/DP83821 with H/W VLAN stripping does not accept short VLAN  * tagged packets such as ARP, short icmp echo request, etc. It seems  * that MAC checks frame length for VLAN tagged packets after stripping  * the VLAN tag. For short VLAN tagged packets it would would be 56  * (64 - CRC - VLAN info) bytes in length after stripping VLAN tag.  * If the VLAN tag stripped frames are less than 60 bytes in length  * the hardware think it received runt packets!  * Therefore we should accept runt frames to get VLAN tagged ARP  * packets. In addition, it is known that some revisions of  * DP83820/DP83821 have another bug that prevent fragmented IP packets  * from accepting. So we also should accept errored frames.  */
end_comment

begin_define
define|#
directive|define
name|NGE_RXCFG
define|\
value|(NGE_RXCFG_DRAIN(64) | NGE_RXDMA_256BYTES| \ 	 NGE_RXCFG_RX_RANGEERR | NGE_RXCFG_RX_BADPKTS | NGE_RXCFG_RX_RUNT | \ 	 NGE_RXCFG_RX_GIANTS | NGE_RXCFG_RX_NOCRC)
end_define

begin_comment
comment|/* Priority queue control */
end_comment

begin_define
define|#
directive|define
name|NGE_PRIOQCTL_TXPRIO_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_PRIOQCTL_TXFAIR_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_PRIOQCTL_RXPRIO
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|NGE_RXPRIOQ_DISABLED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NGE_RXPRIOQ_TWOQS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_RXPRIOQ_THREEQS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_RXPRIOQ_FOURQS
value|0x0000000C
end_define

begin_comment
comment|/* Wake On LAN command/status register */
end_comment

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_PHYINTR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_UNICAST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_MULTICAST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_BROADCAST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_ARP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_PAT0_MATCH
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_PAT1_MATCH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_PAT2_MATCH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_PAT3_MATCH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_WAKE_ON_MAGICPKT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_SECUREON_ENB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_SECUREON_HACK
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_PHYINTR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_UNICAST
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_MULTICAST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_BROADCAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_ARP_RCVD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_PAT0_MATCH
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_PAT1_MATCH
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_PAT2_MATCH
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_PAT3_MATCH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NGE_WOLCSR_MAGICPKT
value|0x80000000
end_define

begin_comment
comment|/* Pause control/status register */
end_comment

begin_define
define|#
directive|define
name|NGE_PAUSECSR_CNT
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_PFRAME_SENT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_RX_DATAFIFO_THR_LO
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_RX_DATAFIFO_THR_HI
value|0x00300000
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_RX_STATFIFO_THR_LO
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_RX_STATFIFO_THR_HI
value|0x03000000
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_PFRAME_RCVD
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_PAUSE_ACTIVE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_PAUSECSR_PAUSE_ON_DA
value|0x20000000
end_define

begin_comment
comment|/* pause on direct addr */
end_comment

begin_define
define|#
directive|define
name|NGE_PAUSECSR_PAUSE_ON_MCAST
value|0x40000000
end_define

begin_comment
comment|/* pause on mcast */
end_comment

begin_define
define|#
directive|define
name|NGE_PAUSECSR_PAUSE_ENB
value|0x80000000
end_define

begin_comment
comment|/* Receive filter/match control message */
end_comment

begin_define
define|#
directive|define
name|MGE_RXFILTCTL_ADDR
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_ULMASK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_UCHASH
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_MCHASH
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_ARP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_PMATCH0
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_PMATCH1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_PMATCH2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_PMATCH3
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_PERFECT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_ALLPHYS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_ALLMULTI
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_BROAD
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NGE_RXFILTCTL_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_PAR0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_PAR1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_PAR2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_PMATCH0
value|0x00000006
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_PMATCH1
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_SOPASS0
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_SOPASS1
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_SOPASS2
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_FMEM_LO
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_FMEM_HI
value|0x000003FE
end_define

begin_define
define|#
directive|define
name|NGE_FILTADDR_MCAST_LO
value|0x00000100
end_define

begin_comment
comment|/* start of multicast filter */
end_comment

begin_define
define|#
directive|define
name|NGE_FILTADDR_MCAST_HI
value|0x000001FE
end_define

begin_comment
comment|/* end of multicast filter */
end_comment

begin_define
define|#
directive|define
name|NGE_MCAST_FILTER_LEN
value|256
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|NGE_FILTADDR_PBUF0
value|0x00000200
end_define

begin_comment
comment|/* pattern buffer 0 */
end_comment

begin_define
define|#
directive|define
name|NGE_FILTADDR_PBUF1
value|0x00000280
end_define

begin_comment
comment|/* pattern buffer 1 */
end_comment

begin_define
define|#
directive|define
name|NGE_FILTADDR_PBUF2
value|0x00000300
end_define

begin_comment
comment|/* pattern buffer 2 */
end_comment

begin_define
define|#
directive|define
name|NGE_FILTADDR_PBUF3
value|0x00000380
end_define

begin_comment
comment|/* pattern buffer 3 */
end_comment

begin_comment
comment|/* MIB control register */
end_comment

begin_define
define|#
directive|define
name|NGE_MIBCTL_WARNTEST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_MIBCTL_FREEZE_CNT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_MIBCTL_CLEAR_CNT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_MIBCTL_STROBE_CNT
value|0x00000008
end_define

begin_comment
comment|/* VLAN/IP RX control register */
end_comment

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_TAG_DETECT_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_TAG_STRIP_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_DROP_TAGGEDPKTS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_DROP_UNTAGGEDPKTS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_IPCSUM_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_REJECT_BADIPCSUM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_REJECT_BADTCPCSUM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_VIPRXCTL_REJECT_BADUDPCSUM
value|0x00000080
end_define

begin_comment
comment|/* VLAN/IP TX control register */
end_comment

begin_define
define|#
directive|define
name|NGE_VIPTXCTL_TAG_ALL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NGE_VIPTXCTL_TAG_PER_PKT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_VIPTXCTL_CSUM_ALL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_VIPTXCTL_CSUM_PER_PKT
value|0x00000008
end_define

begin_comment
comment|/* VLAN data register */
end_comment

begin_define
define|#
directive|define
name|NGE_VLANDATA_VTYPE
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|NGE_VLANDATA_VTCI
value|0xFFFF0000
end_define

begin_comment
comment|/* Clockrun register */
end_comment

begin_define
define|#
directive|define
name|NGE_CLKRUN_PMESTS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NGE_CLKRUN_PMEENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_CLNRUN_CLKRUN_ENB
value|0x00000001
end_define

begin_comment
comment|/* TBI BMCR */
end_comment

begin_define
define|#
directive|define
name|NGE_TBIBMCR_RESTART_ANEG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NGE_TBIBMCR_ENABLE_ANEG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NGE_TBIBMCR_LOOPBACK
value|0x00004000
end_define

begin_comment
comment|/* TBI BMSR */
end_comment

begin_define
define|#
directive|define
name|NGE_TBIBMSR_ANEG_DONE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NGE_TBIBMSR_LINKSTAT
value|0x00000020
end_define

begin_comment
comment|/* TBI ANAR */
end_comment

begin_define
define|#
directive|define
name|NGE_TBIANAR_HDX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_FDX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_PS1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_PS2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_PCAP
value|0x00000180
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_REMFAULT
value|0x00003000
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_NEXTPAGE
value|0x00008000
end_define

begin_comment
comment|/* TBI ANLPAR */
end_comment

begin_define
define|#
directive|define
name|NGE_TBIANLPAR_HDX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NGE_TBIANLPAR_FDX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_PS1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NGE_TBIANAR_PS2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NGE_TBIANLPAR_PCAP
value|0x00000180
end_define

begin_define
define|#
directive|define
name|NGE_TBIANLPAR_REMFAULT
value|0x00003000
end_define

begin_define
define|#
directive|define
name|NGE_TBIANLPAR_NEXTPAGE
value|0x00008000
end_define

begin_comment
comment|/* TBI ANER */
end_comment

begin_define
define|#
directive|define
name|NGE_TBIANER_PAGERCVD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NGE_TBIANER_NEXTPGABLE
value|0x00000004
end_define

begin_comment
comment|/* TBI EXTSTS */
end_comment

begin_define
define|#
directive|define
name|NGE_TBIEXTSTS_HXD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NGE_TBIEXTSTS_FXD
value|0x00008000
end_define

begin_comment
comment|/*  * DMA descriptor structures. The RX and TX descriptor formats are  * deliberately designed to be similar to facilitate passing them between  * RX and TX queues on multiple controllers, in the case where you have  * multiple MACs in a switching configuration. With the 83820, the pointer  * values can be either 64 bits or 32 bits depending on how the chip is  * configured. For the 83821, the fields are always 32-bits. There is  * also an optional extended status field for VLAN and TCP/IP checksum  * functions. We use the checksum feature so we enable the use of this  * field. Descriptors must be 64-bit aligned.  */
end_comment

begin_struct
struct|struct
name|nge_desc_64
block|{
comment|/* Hardware descriptor section */
name|uint32_t
name|nge_next_lo
decl_stmt|;
name|uint32_t
name|nge_next_hi
decl_stmt|;
name|uint32_t
name|nge_ptr_lo
decl_stmt|;
name|uint32_t
name|nge_ptr_hi
decl_stmt|;
name|uint32_t
name|nge_cmdsts
decl_stmt|;
name|uint32_t
name|nge_extsts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nge_desc_32
block|{
comment|/* Hardware descriptor section */
name|uint32_t
name|nge_next
decl_stmt|;
name|uint32_t
name|nge_ptr
decl_stmt|;
name|uint32_t
name|nge_cmdsts
decl_stmt|;
name|uint32_t
name|nge_extsts
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nge_desc
value|nge_desc_32
end_define

begin_define
define|#
directive|define
name|NGE_CMDSTS_BUFLEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|NGE_CMDSTS_PKT_OK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NGE_CMDSTS_CRC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NGE_CMDSTS_INTR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NGE_CMDSTS_MORE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NGE_CMDSTS_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NGE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = ((x) + 1) % y
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_RANGELENERR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_LOOPBK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_ALIGNERR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_CRCERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_SYMBOLERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_RUNT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_GIANT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_DSTCLASS
value|0x01800000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_OVERRUN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NGE_RXSTAT_RX_ABORT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NGE_DSTCLASS_REJECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NGE_DSTCLASS_UNICAST
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NGE_DSTCLASS_MULTICAST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NGE_DSTCLASS_BROADCAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_COLLCNT
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_EXCESSCOLLS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_OUTOFWINCOLL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_EXCESS_DEFER
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_DEFERED
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_CARR_LOST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_UNDERRUN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NGE_TXSTAT_TX_ABORT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NGE_TXEXTSTS_VLAN_TCI
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|NGE_TXEXTSTS_VLANPKT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NGE_TXEXTSTS_IPCSUM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NGE_TXEXTSTS_TCPCSUM
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_TXEXTSTS_UDPCSUM
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_VTCI
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_VLANPKT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_IPPKT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_IPCSUMERR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_TCPPKT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_TCPCSUMERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_UDPPKT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NGE_RXEXTSTS_UDPCSUMERR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NGE_TX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|NGE_RX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|NGE_TX_RING_SIZE
value|sizeof(struct nge_desc) * NGE_TX_RING_CNT
end_define

begin_define
define|#
directive|define
name|NGE_RX_RING_SIZE
value|sizeof(struct nge_desc) * NGE_RX_RING_CNT
end_define

begin_define
define|#
directive|define
name|NGE_RING_ALIGN
value|sizeof(uint64_t)
end_define

begin_define
define|#
directive|define
name|NGE_RX_ALIGN
value|sizeof(uint64_t)
end_define

begin_define
define|#
directive|define
name|NGE_MAXTXSEGS
value|16
end_define

begin_define
define|#
directive|define
name|NGE_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|NGE_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x)>> 32)
end_define

begin_define
define|#
directive|define
name|NGE_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->nge_rdata.nge_tx_ring_paddr + sizeof(struct nge_desc) * (i))
end_define

begin_define
define|#
directive|define
name|NGE_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->nge_rdata.nge_rx_ring_paddr + sizeof(struct nge_desc) * (i))
end_define

begin_struct
struct|struct
name|nge_txdesc
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
name|nge_rxdesc
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
name|nge_chain_data
block|{
name|bus_dma_tag_t
name|nge_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|nge_tx_tag
decl_stmt|;
name|struct
name|nge_txdesc
name|nge_txdesc
index|[
name|NGE_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|nge_rx_tag
decl_stmt|;
name|struct
name|nge_rxdesc
name|nge_rxdesc
index|[
name|NGE_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|nge_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|nge_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|nge_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|nge_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|nge_rx_sparemap
decl_stmt|;
name|int
name|nge_tx_prod
decl_stmt|;
name|int
name|nge_tx_cons
decl_stmt|;
name|int
name|nge_tx_cnt
decl_stmt|;
name|int
name|nge_rx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nge_ring_data
block|{
name|struct
name|nge_desc
modifier|*
name|nge_tx_ring
decl_stmt|;
name|bus_addr_t
name|nge_tx_ring_paddr
decl_stmt|;
name|struct
name|nge_desc
modifier|*
name|nge_rx_ring
decl_stmt|;
name|bus_addr_t
name|nge_rx_ring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NatSemi PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|NGE_VENDORID
value|0x100B
end_define

begin_comment
comment|/*  * 83820/83821 PCI device IDs  */
end_comment

begin_define
define|#
directive|define
name|NGE_DEVICEID
value|0x0022
end_define

begin_struct
struct|struct
name|nge_type
block|{
name|uint16_t
name|nge_vid
decl_stmt|;
name|uint16_t
name|nge_did
decl_stmt|;
specifier|const
name|char
modifier|*
name|nge_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGE_JUMBO_FRAMELEN
value|9022
end_define

begin_define
define|#
directive|define
name|NGE_JUMBO_MTU
define|\
value|(NGE_JUMBO_FRAMELEN - sizeof(struct ether_vlan_header) - ETHER_CRC_LEN)
end_define

begin_comment
comment|/* Statistics counters. */
end_comment

begin_struct
struct|struct
name|nge_stats
block|{
name|uint32_t
name|rx_pkts_errs
decl_stmt|;
name|uint32_t
name|rx_crc_errs
decl_stmt|;
name|uint32_t
name|rx_fifo_oflows
decl_stmt|;
name|uint32_t
name|rx_align_errs
decl_stmt|;
name|uint32_t
name|rx_sym_errs
decl_stmt|;
name|uint32_t
name|rx_pkts_jumbos
decl_stmt|;
name|uint32_t
name|rx_len_errs
decl_stmt|;
name|uint32_t
name|rx_unctl_frames
decl_stmt|;
name|uint32_t
name|rx_pause
decl_stmt|;
name|uint32_t
name|tx_pause
decl_stmt|;
name|uint32_t
name|tx_seq_errs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nge_softc
block|{
name|struct
name|ifnet
modifier|*
name|nge_ifp
decl_stmt|;
name|device_t
name|nge_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|nge_res
decl_stmt|;
name|int
name|nge_res_type
decl_stmt|;
name|int
name|nge_res_id
decl_stmt|;
name|struct
name|resource
modifier|*
name|nge_irq
decl_stmt|;
name|void
modifier|*
name|nge_intrhand
decl_stmt|;
name|device_t
name|nge_miibus
decl_stmt|;
name|int
name|nge_if_flags
decl_stmt|;
name|uint32_t
name|nge_flags
decl_stmt|;
define|#
directive|define
name|NGE_FLAG_TBI
value|0x0002
define|#
directive|define
name|NGE_FLAG_SUSPENDED
value|0x2000
define|#
directive|define
name|NGE_FLAG_DETACH
value|0x4000
define|#
directive|define
name|NGE_FLAG_LINK
value|0x8000
name|struct
name|nge_chain_data
name|nge_cdata
decl_stmt|;
name|struct
name|nge_ring_data
name|nge_rdata
decl_stmt|;
name|struct
name|callout
name|nge_stat_ch
decl_stmt|;
name|struct
name|nge_stats
name|nge_stats
decl_stmt|;
name|struct
name|mtx
name|nge_mtx
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
endif|#
directive|endif
name|int
name|nge_watchdog_timer
decl_stmt|;
name|int
name|nge_int_holdoff
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|nge_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|nge_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->nge_mtx, _name, MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|NGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->nge_mtx)
end_define

begin_define
define|#
directive|define
name|NGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->nge_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|NGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->nge_mtx)
end_define

begin_define
define|#
directive|define
name|NGE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->nge_mtx)
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
value|bus_write_4((sc)->nge_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_BARRIER_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|flags
parameter_list|)
define|\
value|bus_barrier((sc)->nge_res, reg, 4, flags)
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
value|bus_read_4((sc)->nge_res, reg)
end_define

begin_define
define|#
directive|define
name|NGE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|NGE_INT_HOLDOFF_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|NGE_INT_HOLDOFF_MIN
value|0
end_define

begin_define
define|#
directive|define
name|NGE_INT_HOLDOFF_MAX
value|255
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|NGE_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|NGE_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|NGE_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|NGE_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|NGE_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|NGE_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|NGE_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|NGE_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|NGE_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|NGE_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|NGE_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|NGE_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|NGE_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|NGE_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|NGE_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|NGE_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|NGE_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|NGE_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|NGE_PCI_CAPID
value|0x50
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|NGE_PCI_NEXTPTR
value|0x51
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|NGE_PCI_PWRMGMTCAP
value|0x52
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|NGE_PCI_PWRMGMTCTRL
value|0x54
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|NGE_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|NGE_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|NGE_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|NGE_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|NGE_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|NGE_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|NGE_PME_STATUS
value|0x8000
end_define

end_unit

