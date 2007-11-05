begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for the SiS 900 and SiS 7016 chipsets. The  * 7016 is actually an older chip and some of its registers differ  * from the 900, however the core operational registers are the same:  * the differences lie in the OnNow/Wake on LAN stuff which we don't  * use anyway. The 7016 needs an external MII compliant PHY while the  * SiS 900 has one built in. All registers are 32-bits wide.  */
end_comment

begin_comment
comment|/* Registers common to SiS 900 and SiS 7016 */
end_comment

begin_define
define|#
directive|define
name|SIS_CSR
value|0x00
end_define

begin_define
define|#
directive|define
name|SIS_CFG
value|0x04
end_define

begin_define
define|#
directive|define
name|SIS_EECTL
value|0x08
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL
value|0x0C
end_define

begin_define
define|#
directive|define
name|SIS_ISR
value|0x10
end_define

begin_define
define|#
directive|define
name|SIS_IMR
value|0x14
end_define

begin_define
define|#
directive|define
name|SIS_IER
value|0x18
end_define

begin_define
define|#
directive|define
name|SIS_PHYCTL
value|0x1C
end_define

begin_define
define|#
directive|define
name|SIS_TX_LISTPTR
value|0x20
end_define

begin_define
define|#
directive|define
name|SIS_TX_CFG
value|0x24
end_define

begin_define
define|#
directive|define
name|SIS_RX_LISTPTR
value|0x30
end_define

begin_define
define|#
directive|define
name|SIS_RX_CFG
value|0x34
end_define

begin_define
define|#
directive|define
name|SIS_FLOWCTL
value|0x38
end_define

begin_define
define|#
directive|define
name|SIS_RXFILT_CTL
value|0x48
end_define

begin_define
define|#
directive|define
name|SIS_RXFILT_DATA
value|0x4C
end_define

begin_define
define|#
directive|define
name|SIS_PWRMAN_CTL
value|0xB0
end_define

begin_define
define|#
directive|define
name|SIS_PWERMAN_WKUP_EVENT
value|0xB4
end_define

begin_define
define|#
directive|define
name|SIS_WKUP_FRAME_CRC
value|0xBC
end_define

begin_define
define|#
directive|define
name|SIS_WKUP_FRAME_MASK0
value|0xC0
end_define

begin_define
define|#
directive|define
name|SIS_WKUP_FRAME_MASKXX
value|0xEC
end_define

begin_comment
comment|/* SiS 7016 specific registers */
end_comment

begin_define
define|#
directive|define
name|SIS_SILICON_REV
value|0x5C
end_define

begin_define
define|#
directive|define
name|SIS_MIB_CTL0
value|0x60
end_define

begin_define
define|#
directive|define
name|SIS_MIB_CTL1
value|0x64
end_define

begin_define
define|#
directive|define
name|SIS_MIB_CTL2
value|0x68
end_define

begin_define
define|#
directive|define
name|SIS_MIB_CTL3
value|0x6C
end_define

begin_define
define|#
directive|define
name|SIS_MIB
value|0x80
end_define

begin_define
define|#
directive|define
name|SIS_LINKSTS
value|0xA0
end_define

begin_define
define|#
directive|define
name|SIS_TIMEUNIT
value|0xA4
end_define

begin_define
define|#
directive|define
name|SIS_GPIO
value|0xB8
end_define

begin_comment
comment|/* NS DP83815/6 registers */
end_comment

begin_define
define|#
directive|define
name|NS_IHR
value|0x1C
end_define

begin_define
define|#
directive|define
name|NS_CLKRUN
value|0x3C
end_define

begin_define
define|#
directive|define
name|NS_SRR
value|0x58
end_define

begin_define
define|#
directive|define
name|NS_BMCR
value|0x80
end_define

begin_define
define|#
directive|define
name|NS_BMSR
value|0x84
end_define

begin_define
define|#
directive|define
name|NS_PHYIDR1
value|0x88
end_define

begin_define
define|#
directive|define
name|NS_PHYIDR2
value|0x8C
end_define

begin_define
define|#
directive|define
name|NS_ANAR
value|0x90
end_define

begin_define
define|#
directive|define
name|NS_ANLPAR
value|0x94
end_define

begin_define
define|#
directive|define
name|NS_ANER
value|0x98
end_define

begin_define
define|#
directive|define
name|NS_ANNPTR
value|0x9C
end_define

begin_define
define|#
directive|define
name|NS_PHY_CR
value|0xE4
end_define

begin_define
define|#
directive|define
name|NS_PHY_10BTSCR
value|0xE8
end_define

begin_define
define|#
directive|define
name|NS_PHY_PAGE
value|0xCC
end_define

begin_define
define|#
directive|define
name|NS_PHY_EXTCFG
value|0xF0
end_define

begin_define
define|#
directive|define
name|NS_PHY_DSPCFG
value|0xF4
end_define

begin_define
define|#
directive|define
name|NS_PHY_SDCFG
value|0xF8
end_define

begin_define
define|#
directive|define
name|NS_PHY_TDATA
value|0xFC
end_define

begin_define
define|#
directive|define
name|NS_CLKRUN_PMESTS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NS_CLKRUN_PMEENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NS_CLNRUN_CLKRUN_ENB
value|0x00000001
end_define

begin_comment
comment|/* NS silicon revisions */
end_comment

begin_define
define|#
directive|define
name|NS_SRR_15C
value|0x302
end_define

begin_define
define|#
directive|define
name|NS_SRR_15D
value|0x403
end_define

begin_define
define|#
directive|define
name|NS_SRR_16A
value|0x505
end_define

begin_define
define|#
directive|define
name|SIS_CSR_TX_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIS_CSR_TX_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SIS_CSR_RX_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIS_CSR_RX_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIS_CSR_TX_RESET
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIS_CSR_RX_RESET
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_CSR_SOFTINTR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SIS_CSR_RESET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SIS_CSR_ACCESS_MODE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIS_CSR_RELOAD
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIS_CFG_BIGENDIAN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIS_CFG_PERR_DETECT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIS_CFG_DEFER_DISABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIS_CFG_OUTOFWIN_TIMER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_CFG_SINGLE_BACKOFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIS_CFG_PCIREQ_ALG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SIS_CFG_FAIR_BACKOFF
value|0x00000200
end_define

begin_comment
comment|/* 635& 900B Specific */
end_comment

begin_define
define|#
directive|define
name|SIS_CFG_RND_CNT
value|0x00000400
end_define

begin_comment
comment|/* 635& 900B Specific */
end_comment

begin_define
define|#
directive|define
name|SIS_CFG_EDB_MASTER_EN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SIS_EECTL_DIN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIS_EECTL_DOUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SIS_EECTL_CLK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIS_EECTL_CSEL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIS_MII_CLK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIS_MII_DIR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_MII_DATA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIS_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|SIS_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|SIS_EECMD_ERASE
value|0x1c0
end_define

begin_comment
comment|/*  * EEPROM Commands for SiS96x  * chipsets.  */
end_comment

begin_define
define|#
directive|define
name|SIS_EECMD_REQ
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIS_EECMD_DONE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIS_EECMD_GNT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SIS_EE_NODEADDR
value|0x8
end_define

begin_define
define|#
directive|define
name|NS_EE_NODEADDR
value|0x6
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_SRAMADDR
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_RAMTSTENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_TXTSTENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_RXTSTENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_BMTSTENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_RAMADDR
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_ROMTIME
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|SIS_PCICTL_DISCTEST
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_DESC_OK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_EARLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_IDLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_OFLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_DESC_OK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_ERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_IDLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_UFLOW
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIS_ISR_SOFTINTR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SIS_ISR_HIBITS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_FIFO_OFLOW
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TGT_ABRT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_BM_ABRT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_SYSERR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_PARITY_ERR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_RX_RESET_DONE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_RESET_DONE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_PAUSE_START
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_TX_PAUSE_DONE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SIS_ISR_WAKE_EVENT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_DESC_OK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_EARLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_IDLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_OFLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_DESC_OK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_ERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_IDLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_UFLOW
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIS_IMR_SOFTINTR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SIS_IMR_HIBITS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_FIFO_OFLOW
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TGT_ABRT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_BM_ABRT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_SYSERR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_PARITY_ERR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_RX_RESET_DONE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_RESET_DONE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_PAUSE_START
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_TX_PAUSE_DONE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SIS_IMR_WAKE_EVENT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIS_INTRS
define|\
value|(SIS_IMR_RX_OFLOW|SIS_IMR_TX_UFLOW|SIS_IMR_TX_OK|\ 	 SIS_IMR_TX_IDLE|SIS_IMR_RX_OK|SIS_IMR_RX_ERR|\ 	 SIS_IMR_RX_IDLE|\ 	 SIS_IMR_SYSERR)
end_define

begin_define
define|#
directive|define
name|SIS_IER_INTRENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIS_PHYCTL_ACCESS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIS_PHYCTL_OP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_PHYCTL_REGADDR
value|0x000007C0
end_define

begin_define
define|#
directive|define
name|SIS_PHYCTL_PHYADDR
value|0x0000F800
end_define

begin_define
define|#
directive|define
name|SIS_PHYCTL_PHYDATA
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|SIS_PHYOP_READ
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIS_PHYOP_WRITE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_DRAIN_THRESH
value|0x0000003F
end_define

begin_comment
comment|/* 32-byte units */
end_comment

begin_define
define|#
directive|define
name|SIS_TXCFG_FILL_THRESH
value|0x00003F00
end_define

begin_comment
comment|/* 32-byte units */
end_comment

begin_define
define|#
directive|define
name|SIS_TXCFG_DMABURST
value|0x00700000
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_AUTOPAD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_LOOPBK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_IGN_HBEAT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_IGN_CARR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_DRAIN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& SIS_TXCFG_DRAIN_THRESH)
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_FILL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 5)<< 8)& SIS_TXCFG_FILL_THRESH)
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_512BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_4BYTES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_8BYTES
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_16BYTES
value|0x00300000
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_32BYTES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_64BYTES
value|0x00500000
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_128BYTES
value|0x00600000
end_define

begin_define
define|#
directive|define
name|SIS_TXDMA_256BYTES
value|0x00700000
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_100
define|\
value|(SIS_TXDMA_64BYTES|SIS_TXCFG_AUTOPAD|\ 	 SIS_TXCFG_FILL(64)|SIS_TXCFG_DRAIN(1536))
end_define

begin_define
define|#
directive|define
name|SIS_TXCFG_10
define|\
value|(SIS_TXDMA_32BYTES|SIS_TXCFG_AUTOPAD|\ 	 SIS_TXCFG_FILL(64)|SIS_TXCFG_DRAIN(1536))
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG_DRAIN_THRESH
value|0x0000003E
end_define

begin_comment
comment|/* 8-byte units */
end_comment

begin_define
define|#
directive|define
name|SIS_TXCFG_MPII03D
value|0x00040000
end_define

begin_comment
comment|/* "Must be 1" */
end_comment

begin_define
define|#
directive|define
name|SIS_RXCFG_DMABURST
value|0x00700000
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG_RX_JABBER
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG_RX_TXPKTS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG_RX_RUNTS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG_RX_GIANTS
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG_DRAIN
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 3)<< 1)& SIS_RXCFG_DRAIN_THRESH)
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_512BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_4BYTES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_8BYTES
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_16BYTES
value|0x00300000
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_32BYTES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_64BYTES
value|0x00500000
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_128BYTES
value|0x00600000
end_define

begin_define
define|#
directive|define
name|SIS_RXDMA_256BYTES
value|0x00700000
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG256
define|\
value|(SIS_RXCFG_DRAIN(64)|SIS_RXDMA_256BYTES)
end_define

begin_define
define|#
directive|define
name|SIS_RXCFG64
define|\
value|(SIS_RXCFG_DRAIN(64)|SIS_RXDMA_64BYTES)
end_define

begin_define
define|#
directive|define
name|SIS_RXFILTCTL_ADDR
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|NS_RXFILTCTL_MCHASH
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NS_RXFILTCTL_ARP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NS_RXFILTCTL_PERFECT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SIS_RXFILTCTL_ALLPHYS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIS_RXFILTCTL_ALLMULTI
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SIS_RXFILTCTL_BROAD
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIS_RXFILTCTL_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_PAR0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_PAR1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_PAR2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR0
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR1
value|0x00050000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR2
value|0x00060000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR3
value|0x00070000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR4
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR5
value|0x00090000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR6
value|0x000A0000
end_define

begin_define
define|#
directive|define
name|SIS_FILTADDR_MAR7
value|0x000B0000
end_define

begin_define
define|#
directive|define
name|NS_FILTADDR_PAR0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NS_FILTADDR_PAR1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NS_FILTADDR_PAR2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NS_FILTADDR_FMEM_LO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NS_FILTADDR_FMEM_HI
value|0x000003FE
end_define

begin_comment
comment|/*  * DMA descriptor structures. The first part of the descriptor  * is the hardware descriptor format, which is just three longwords.  * After this, we include some additional structure members for  * use by the driver. Note that for this structure will be a different  * size on the alpha, but that's okay as long as it's a multiple of 4  * bytes in size.  */
end_comment

begin_struct
struct|struct
name|sis_desc
block|{
comment|/* SiS hardware descriptor section */
name|u_int32_t
name|sis_next
decl_stmt|;
name|u_int32_t
name|sis_cmdsts
decl_stmt|;
define|#
directive|define
name|sis_rxstat
value|sis_cmdsts
define|#
directive|define
name|sis_txstat
value|sis_cmdsts
define|#
directive|define
name|sis_ctl
value|sis_cmdsts
name|u_int32_t
name|sis_ptr
decl_stmt|;
comment|/* Driver software section */
name|struct
name|mbuf
modifier|*
name|sis_mbuf
decl_stmt|;
name|struct
name|sis_desc
modifier|*
name|sis_nextdesc
decl_stmt|;
name|bus_dmamap_t
name|sis_map
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIS_CMDSTS_BUFLEN
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|SIS_CMDSTS_PKT_OK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SIS_CMDSTS_CRC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIS_CMDSTS_INTR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SIS_CMDSTS_MORE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIS_CMDSTS_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIS_LASTDESC
parameter_list|(
name|x
parameter_list|)
value|(!((x)->sis_ctl& SIS_CMDSTS_MORE))
end_define

begin_define
define|#
directive|define
name|SIS_OWNDESC
parameter_list|(
name|x
parameter_list|)
value|((x)->sis_ctl& SIS_CMDSTS_OWN)
end_define

begin_define
define|#
directive|define
name|SIS_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = ((x) == ((y)-1)) ? 0 : (x)+1
end_define

begin_define
define|#
directive|define
name|SIS_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|(((x)->sis_ctl& SIS_CMDSTS_BUFLEN) - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_COLL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_LOOPBK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_ALIGNERR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_CRCERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_SYMBOLERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_RUNT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_GIANT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_DSTCLASS
value|0x01800000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_OVERRUN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIS_RXSTAT_RX_ABORT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SIS_DSTCLASS_REJECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SIS_DSTCLASS_UNICAST
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SIS_DSTCLASS_MULTICAST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SIS_DSTCLASS_BROADCAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_COLLCNT
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_EXCESSCOLLS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_OUTOFWINCOLL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_EXCESS_DEFER
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_DEFERED
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_CARR_LOST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_UNDERRUN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIS_TXSTAT_TX_ABORT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SIS_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|SIS_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|SIS_RX_LIST_SZ
value|SIS_RX_LIST_CNT * sizeof(struct sis_desc)
end_define

begin_define
define|#
directive|define
name|SIS_TX_LIST_SZ
value|SIS_TX_LIST_CNT * sizeof(struct sis_desc)
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
name|SIS_DEVICEID_900
value|0x0900
end_define

begin_define
define|#
directive|define
name|SIS_DEVICEID_7016
value|0x7016
end_define

begin_comment
comment|/*  * SiS 900 PCI revision codes.  */
end_comment

begin_define
define|#
directive|define
name|SIS_REV_900B
value|0x0003
end_define

begin_define
define|#
directive|define
name|SIS_REV_630A
value|0x0080
end_define

begin_define
define|#
directive|define
name|SIS_REV_630E
value|0x0081
end_define

begin_define
define|#
directive|define
name|SIS_REV_630S
value|0x0082
end_define

begin_define
define|#
directive|define
name|SIS_REV_630EA1
value|0x0083
end_define

begin_define
define|#
directive|define
name|SIS_REV_630ET
value|0x0084
end_define

begin_define
define|#
directive|define
name|SIS_REV_635
value|0x0090
end_define

begin_define
define|#
directive|define
name|SIS_REV_96x
value|0x0091
end_define

begin_comment
comment|/*  * NatSemi vendor ID  */
end_comment

begin_define
define|#
directive|define
name|NS_VENDORID
value|0x100B
end_define

begin_comment
comment|/*  * DP83815 device ID  */
end_comment

begin_define
define|#
directive|define
name|NS_DEVICEID_DP83815
value|0x0020
end_define

begin_struct
struct|struct
name|sis_type
block|{
name|u_int16_t
name|sis_vid
decl_stmt|;
name|u_int16_t
name|sis_did
decl_stmt|;
name|char
modifier|*
name|sis_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sis_mii_frame
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
name|SIS_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|SIS_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|SIS_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|SIS_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|SIS_TYPE_900
value|1
end_define

begin_define
define|#
directive|define
name|SIS_TYPE_7016
value|2
end_define

begin_define
define|#
directive|define
name|SIS_TYPE_83815
value|3
end_define

begin_define
define|#
directive|define
name|SIS_TYPE_83816
value|4
end_define

begin_struct
struct|struct
name|sis_softc
block|{
name|struct
name|ifnet
modifier|*
name|sis_ifp
decl_stmt|;
comment|/* interface info */
name|struct
name|resource
modifier|*
name|sis_res
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|sis_intrhand
decl_stmt|;
name|device_t
name|sis_dev
decl_stmt|;
name|device_t
name|sis_miibus
decl_stmt|;
name|u_int8_t
name|sis_type
decl_stmt|;
name|u_int8_t
name|sis_rev
decl_stmt|;
name|u_int8_t
name|sis_link
decl_stmt|;
name|u_int
name|sis_srr
decl_stmt|;
name|struct
name|sis_desc
modifier|*
name|sis_rx_list
decl_stmt|;
name|struct
name|sis_desc
modifier|*
name|sis_tx_list
decl_stmt|;
name|bus_dma_tag_t
name|sis_rx_tag
decl_stmt|;
name|bus_dmamap_t
name|sis_rx_dmamap
decl_stmt|;
name|bus_dma_tag_t
name|sis_tx_tag
decl_stmt|;
name|bus_dmamap_t
name|sis_tx_dmamap
decl_stmt|;
name|bus_dma_tag_t
name|sis_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|sis_tag
decl_stmt|;
name|struct
name|sis_desc
modifier|*
name|sis_rx_pdsc
decl_stmt|;
name|int
name|sis_tx_prod
decl_stmt|;
name|int
name|sis_tx_cons
decl_stmt|;
name|int
name|sis_tx_cnt
decl_stmt|;
name|u_int32_t
name|sis_rx_paddr
decl_stmt|;
name|u_int32_t
name|sis_tx_paddr
decl_stmt|;
name|struct
name|callout
name|sis_stat_ch
decl_stmt|;
name|int
name|sis_watchdog_timer
decl_stmt|;
name|int
name|sis_stopped
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
name|in_tick
decl_stmt|;
name|struct
name|mtx
name|sis_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIS_TIMEOUT
value|1000
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
name|SIS_RXLEN
value|1536
end_define

begin_define
define|#
directive|define
name|SIS_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|SIS_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|SIS_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|SIS_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|SIS_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|SIS_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|SIS_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|SIS_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|SIS_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|SIS_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|SIS_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|SIS_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|SIS_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|SIS_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|SIS_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|SIS_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|SIS_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|SIS_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|SIS_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|SIS_PCI_CAPID
value|0x50
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|SIS_PCI_NEXTPTR
value|0x51
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|SIS_PCI_PWRMGMTCAP
value|0x52
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|SIS_PCI_PWRMGMTCTRL
value|0x54
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|SIS_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|SIS_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|SIS_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|SIS_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|SIS_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|SIS_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|SIS_PME_STATUS
value|0x8000
end_define

end_unit

