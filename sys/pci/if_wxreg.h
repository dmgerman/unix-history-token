begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Principal Author: Matthew Jacob  * Copyright (c) 1999, 2001 by Traakan Software  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Additional Copyright (c) 2001 by Parag Patel  * under same licence for MII PHY code.  */
end_comment

begin_define
define|#
directive|define
name|WX_VENDOR_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|WX_PRODUCT_82452
value|0x1000
end_define

begin_define
define|#
directive|define
name|WX_PRODUCT_LIVENGOOD
value|0x1001
end_define

begin_define
define|#
directive|define
name|WX_PRODUCT_82452_SC
value|0x1003
end_define

begin_define
define|#
directive|define
name|WX_PRODUCT_82543
value|0x1004
end_define

begin_define
define|#
directive|define
name|WX_MMBA
value|0x10
end_define

begin_define
define|#
directive|define
name|MWI
value|0x10
end_define

begin_comment
comment|/* Memory Write Invalidate */
end_comment

begin_define
define|#
directive|define
name|WX_CACHELINE_SIZE
value|0x20
end_define

begin_comment
comment|/* Join PCI ID and revision into one value */
end_comment

begin_define
define|#
directive|define
name|WX_WISEMAN_0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|WX_WISEMAN_2_0
value|0x10000002
end_define

begin_define
define|#
directive|define
name|WX_WISEMAN_2_1
value|0x10000003
end_define

begin_define
define|#
directive|define
name|WX_LIVENGOOD
value|0x10010000
end_define

begin_define
define|#
directive|define
name|WX_LIVENGOOD_CU
value|0x10040002
end_define

begin_define
define|#
directive|define
name|IS_WISEMAN
parameter_list|(
name|sc
parameter_list|)
value|((sc)->wx_idnrev< WX_LIVENGOOD)
end_define

begin_define
define|#
directive|define
name|IS_LIVENGOOD
parameter_list|(
name|sc
parameter_list|)
value|((sc)->wx_idnrev>= WX_LIVENGOOD)
end_define

begin_define
define|#
directive|define
name|IS_LIVENGOOD_CU
parameter_list|(
name|sc
parameter_list|)
value|((sc)->wx_idnrev == WX_LIVENGOOD_CU)
end_define

begin_comment
comment|/*  * Information about this chipset gathered from a released Intel Linux driver,  * which was clearly a port of an NT driver.   */
end_comment

begin_comment
comment|/*  * Various Descriptor Structures.  * These are all in little endian format (for now).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|lowpart
decl_stmt|;
name|u_int32_t
name|highpart
decl_stmt|;
block|}
name|wxpa_t
operator|,
name|wxrp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Receive Descriptor.  * The base address of a receive descriptor ring must be on a 4KB boundary,  * and they must be allocated in multiples of 8.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|wxpa_t
name|address
decl_stmt|;
comment|/* physical address of buffer */
name|u_int16_t
name|length
decl_stmt|;
name|u_int16_t
name|csum
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|errors
decl_stmt|;
name|u_int16_t
name|special
decl_stmt|;
block|}
name|wxrd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RDSTAT_DD
value|0x1
end_define

begin_comment
comment|/* descriptor done */
end_comment

begin_define
define|#
directive|define
name|RDSTAT_EOP
value|0x2
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|RDSTAT_RSVD
value|0x74
end_define

begin_comment
comment|/* reserved bits */
end_comment

begin_define
define|#
directive|define
name|RDERR_CRC
value|0x1
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|RDERR_SE
value|0x2
end_define

begin_comment
comment|/* Symbol Error */
end_comment

begin_define
define|#
directive|define
name|RDERR_SEQ
value|0x4
end_define

begin_comment
comment|/* Sequence Error */
end_comment

begin_comment
comment|/*  * Transmit Descriptor  * The base address of a transmit descriptor ring must be on a 4KB boundary,  * and they must be allocated in multiples of 8.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|wxpa_t
name|address
decl_stmt|;
name|u_int16_t
name|length
decl_stmt|;
name|u_int8_t
name|cso
decl_stmt|;
comment|/* checksum offset */
name|u_int8_t
name|cmd
decl_stmt|;
comment|/* cmd */
name|u_int8_t
name|status
decl_stmt|;
comment|/* status */
name|u_int8_t
name|css
decl_stmt|;
comment|/* checksum start */
name|u_int16_t
name|special
decl_stmt|;
block|}
name|wxtd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TXCMD_EOP
value|0x1
end_define

begin_comment
comment|/* last packet */
end_comment

begin_define
define|#
directive|define
name|TXCMD_IFCS
value|0x2
end_define

begin_comment
comment|/* insert FCS */
end_comment

begin_define
define|#
directive|define
name|TXCMD_IC
value|0x4
end_define

begin_comment
comment|/* insert checksum */
end_comment

begin_define
define|#
directive|define
name|TXCMD_RS
value|0x8
end_define

begin_comment
comment|/* report status */
end_comment

begin_define
define|#
directive|define
name|TXCMD_RPS
value|0x10
end_define

begin_comment
comment|/* report packet sent */
end_comment

begin_define
define|#
directive|define
name|TXCMD_SM
value|0x20
end_define

begin_comment
comment|/* symbol mode */
end_comment

begin_define
define|#
directive|define
name|TXCMD_IDE
value|0x80
end_define

begin_comment
comment|/* interrupt delay enable */
end_comment

begin_define
define|#
directive|define
name|TXSTS_DD
value|0x1
end_define

begin_comment
comment|/* descriptor done */
end_comment

begin_define
define|#
directive|define
name|TXSTS_EC
value|0x2
end_define

begin_comment
comment|/* excess collisions */
end_comment

begin_define
define|#
directive|define
name|TXSTS_LC
value|0x4
end_define

begin_comment
comment|/* late collision */
end_comment

begin_comment
comment|/*  * This device can only be accessed via memory space.  */
end_comment

begin_comment
comment|/*  * Register access via offsets.  *  * Our brilliant friends at Intel decided to move registers offsets  * around from chip version to chip version. It's amazing that some  * deity doesn't zap these suckers. Really.  */
end_comment

begin_define
define|#
directive|define
name|WXREG_DCR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|WXREG_DSR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WXREG_EECDR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WXREG_EXCT
value|0x00000018
end_define

begin_define
define|#
directive|define
name|WXREG_MDIC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WXREG_FCAL
value|0x00000028
end_define

begin_define
define|#
directive|define
name|WXREG_FCAH
value|0x0000002C
end_define

begin_define
define|#
directive|define
name|WXREG_FCT
value|0x00000030
end_define

begin_define
define|#
directive|define
name|WXREG_VET
value|0x00000038
end_define

begin_define
define|#
directive|define
name|WXREG_RAL_BASE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WXREG_RAL_LO
parameter_list|(
name|x
parameter_list|)
value|(WXREG_RAL_BASE + ((x)<< 3))
end_define

begin_define
define|#
directive|define
name|WXREG_RAL_HI
parameter_list|(
name|x
parameter_list|)
value|(WXREG_RAL_LO(x) + 4)
end_define

begin_define
define|#
directive|define
name|WXREG_ICR
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|WXREG_ICS
value|0x000000c8
end_define

begin_define
define|#
directive|define
name|WXREG_IMASK
value|0x000000d0
end_define

begin_define
define|#
directive|define
name|WXREG_IMCLR
value|0x000000d8
end_define

begin_define
define|#
directive|define
name|WXREG_RCTL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WXREG_RDTR0
value|0x00000108
end_define

begin_define
define|#
directive|define
name|WXREG_RDTR0_LIVENGOOD
value|0x00002820
end_define

begin_define
define|#
directive|define
name|WXREG_RDBA0_LO
value|0x00000110
end_define

begin_define
define|#
directive|define
name|WXREG_RDBA0_LO_LIVENGOOD
value|0x00002800
end_define

begin_define
define|#
directive|define
name|WXREG_RDBA0_HI
value|0x00000114
end_define

begin_define
define|#
directive|define
name|WXREG_RDBA0_HI_LIVENGOOD
value|0x00002804
end_define

begin_define
define|#
directive|define
name|WXREG_RDLEN0
value|0x00000118
end_define

begin_define
define|#
directive|define
name|WXREG_RDLEN0_LIVENGOOD
value|0x00002808
end_define

begin_define
define|#
directive|define
name|WXREG_RDH0
value|0x00000120
end_define

begin_define
define|#
directive|define
name|WXREG_RDH0_LIVENGOOD
value|0x00002810
end_define

begin_define
define|#
directive|define
name|WXREG_RDT0
value|0x00000128
end_define

begin_define
define|#
directive|define
name|WXREG_RDT0_LIVENGOOD
value|0x00002818
end_define

begin_define
define|#
directive|define
name|WXREG_RDTR1
value|0x00000130
end_define

begin_define
define|#
directive|define
name|WXREG_RDBA1_LO
value|0x00000138
end_define

begin_define
define|#
directive|define
name|WXREG_RDBA1_HI
value|0x0000013C
end_define

begin_define
define|#
directive|define
name|WXREG_RDLEN1
value|0x00000140
end_define

begin_define
define|#
directive|define
name|WXREG_RDH1
value|0x00000148
end_define

begin_define
define|#
directive|define
name|WXREG_RDT1
value|0x00000150
end_define

begin_define
define|#
directive|define
name|WXREG_FLOW_RCV_HI
value|0x00000160
end_define

begin_define
define|#
directive|define
name|WXREG_FLOW_RCV_HI_LIVENGOOD
value|0x00002168
end_define

begin_define
define|#
directive|define
name|WXREG_FLOW_RCV_LO
value|0x00000168
end_define

begin_define
define|#
directive|define
name|WXREG_FLOW_RCV_LO_LIVENGOOD
value|0x00002160
end_define

begin_define
define|#
directive|define
name|WXREG_FLOW_XTIMER
value|0x00000170
end_define

begin_define
define|#
directive|define
name|WXREG_XMIT_CFGW
value|0x00000178
end_define

begin_define
define|#
directive|define
name|WXREG_RECV_CFGW
value|0x00000180
end_define

begin_define
define|#
directive|define
name|WXREG_MTA
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WXREG_TCTL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WXREG_TQSA_LO
value|0x00000408
end_define

begin_define
define|#
directive|define
name|WXREG_TQSA_HI
value|0x0000040C
end_define

begin_define
define|#
directive|define
name|WXREG_TIPG
value|0x00000410
end_define

begin_define
define|#
directive|define
name|WXREG_TQC
value|0x00000418
end_define

begin_define
define|#
directive|define
name|WXREG_TDBA_LO
value|0x00000420
end_define

begin_define
define|#
directive|define
name|WXREG_TDBA_LO_LIVENGOOD
value|0x00003800
end_define

begin_define
define|#
directive|define
name|WXREG_TDBA_HI
value|0x00000424
end_define

begin_define
define|#
directive|define
name|WXREG_TDBA_HI_LIVENGOOD
value|0x00003804
end_define

begin_define
define|#
directive|define
name|WXREG_TDLEN
value|0x00000428
end_define

begin_define
define|#
directive|define
name|WXREG_TDLEN_LIVENGOOD
value|0x00003808
end_define

begin_define
define|#
directive|define
name|WXREG_TDH
value|0x00000430
end_define

begin_define
define|#
directive|define
name|WXREG_TDH_LIVENGOOD
value|0x00003810
end_define

begin_define
define|#
directive|define
name|WXREG_TDT
value|0x00000438
end_define

begin_define
define|#
directive|define
name|WXREG_TDT_LIVENGOOD
value|0x00003818
end_define

begin_define
define|#
directive|define
name|WXREG_TIDV
value|0x00000440
end_define

begin_define
define|#
directive|define
name|WXREG_TIDV_LIVENGOOD
value|0x00003820
end_define

begin_define
define|#
directive|define
name|WXREG_VFTA
value|0x00000600
end_define

begin_define
define|#
directive|define
name|WX_RAL_TAB_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|WX_RAL_AV
value|0x80000000
end_define

begin_define
define|#
directive|define
name|WX_MC_TAB_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|WX_VLAN_TAB_SIZE
value|128
end_define

begin_comment
comment|/*  * Device Control Register Defines  */
end_comment

begin_define
define|#
directive|define
name|WXDCR_FD
value|0x1
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|WXDCR_BEM
value|0x2
end_define

begin_comment
comment|/* big endian mode */
end_comment

begin_define
define|#
directive|define
name|WXDCR_FAIR
value|0x4
end_define

begin_comment
comment|/* 1->Fairness, 0->Receive Priority */
end_comment

begin_define
define|#
directive|define
name|WXDCR_LRST
value|0x8
end_define

begin_comment
comment|/* Link Reset */
end_comment

begin_define
define|#
directive|define
name|WXDCR_ASDE
value|0x20
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SLE
value|0x20
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SLU
value|0x40
end_define

begin_comment
comment|/* Set Link Up */
end_comment

begin_define
define|#
directive|define
name|WXDCR_ILOS
value|0x80
end_define

begin_comment
comment|/* Invert Loss-of-Signal */
end_comment

begin_define
define|#
directive|define
name|WXDCR_10BT
value|0x000
end_define

begin_comment
comment|/* set 10BaseT */
end_comment

begin_define
define|#
directive|define
name|WXDCR_100BT
value|0x100
end_define

begin_comment
comment|/* LIVENGOOD: Set 100BaseT */
end_comment

begin_define
define|#
directive|define
name|WXDCR_1000BT
value|0x200
end_define

begin_comment
comment|/* LIVENGOOD: Set 1000BaseT */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SPEED_MASK
value|0x300
end_define

begin_define
define|#
directive|define
name|WXDCR_BEM32
value|0x400
end_define

begin_comment
comment|/* LIVENGOOD: Set Big Endian 32 (?) */
end_comment

begin_define
define|#
directive|define
name|WXDCR_FRCSPD
value|0x800
end_define

begin_comment
comment|/* LIVENGOOD: Force Speed (?) */
end_comment

begin_define
define|#
directive|define
name|WXDCR_FRCDPX
value|0x1000
end_define

begin_comment
comment|/* LIVENGOOD: Force Full Duplex */
end_comment

begin_comment
comment|/*  * General purpose I/O pins  *  * Pin 0 is for the LED.  *  * Pin 1 is to detect loss of signal (LOS)- if it is set, we've lost signal.  */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPINS_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|WXDCR_SWDPINS_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|WXDCR_SWDPIN0
value|(1<< 18)
end_define

begin_comment
comment|/* 0x00040000 - PHY reset */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPIN1
value|(1<< 19)
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPIN2
value|(1<< 20)
end_define

begin_comment
comment|/* 0x00100000 - PHY data */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPIN3
value|(1<< 21)
end_define

begin_comment
comment|/* 0x00200000 - PHY clk */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPIO_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|WXDCR_SWDPIO_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|WXDCR_SWDPIO0
value|(1<< 22)
end_define

begin_comment
comment|/* 0x00400000 - PHY rst dir */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPIO1
value|(1<< 23)
end_define

begin_comment
comment|/* 0x00800000 */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPIO2
value|(1<< 24)
end_define

begin_comment
comment|/* 0x01000000 - PHY data dir */
end_comment

begin_define
define|#
directive|define
name|WXDCR_SWDPIO3
value|(1<< 25)
end_define

begin_comment
comment|/* 0x02000000 - PHY clk dir */
end_comment

begin_define
define|#
directive|define
name|WXDCR_RST
value|0x04000000
end_define

begin_comment
comment|/* Device Reset (self clearing) */
end_comment

begin_define
define|#
directive|define
name|WXDCR_RFCE
value|0x08000000
end_define

begin_comment
comment|/* Receive Flow Control Enable */
end_comment

begin_define
define|#
directive|define
name|WXDCR_TFCE
value|0x10000000
end_define

begin_comment
comment|/* Transmit Flow Control Enable */
end_comment

begin_define
define|#
directive|define
name|WXDCR_RTE
value|0x20000000
end_define

begin_comment
comment|/* Routing Tag Enable */
end_comment

begin_define
define|#
directive|define
name|WXDCR_VME
value|0x40000000
end_define

begin_comment
comment|/* VLAN Mode Enable */
end_comment

begin_comment
comment|/*  * Device Status Register Defines  */
end_comment

begin_define
define|#
directive|define
name|WXDSR_FD
value|0x1
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|WXDSR_LU
value|0x2
end_define

begin_comment
comment|/* link up */
end_comment

begin_define
define|#
directive|define
name|WXDSR_TXCLK
value|0x4
end_define

begin_comment
comment|/* transmit clock running */
end_comment

begin_define
define|#
directive|define
name|WXDSR_RBCLK
value|0x8
end_define

begin_comment
comment|/* receive clock running */
end_comment

begin_define
define|#
directive|define
name|WXDSR_TXOFF
value|0x10
end_define

begin_comment
comment|/* transmit paused */
end_comment

begin_define
define|#
directive|define
name|WXDSR_TBIMODE
value|0x20
end_define

begin_comment
comment|/* LIVENGOOD: Fibre Mode */
end_comment

begin_define
define|#
directive|define
name|WXDSR_100BT
value|0x40
end_define

begin_comment
comment|/* LIVENGOOD: 100BaseT */
end_comment

begin_define
define|#
directive|define
name|WXDSR_1000BT
value|0x80
end_define

begin_comment
comment|/* LIVENGOOD: 1000BaseT */
end_comment

begin_define
define|#
directive|define
name|WXDSR_ASDV
value|0x300
end_define

begin_comment
comment|/* LIVENGOOD: ?? */
end_comment

begin_define
define|#
directive|define
name|WXDSR_MTXCKOK
value|0x400
end_define

begin_comment
comment|/* LIVENGOOD: ?? */
end_comment

begin_define
define|#
directive|define
name|WXDSR_PCI66
value|0x800
end_define

begin_comment
comment|/* LIVENGOOD: 66 MHz bus */
end_comment

begin_define
define|#
directive|define
name|WXDSR_BUS64
value|0x1000
end_define

begin_comment
comment|/* LIVENGOOD: In 64 bit slot */
end_comment

begin_comment
comment|/*  * EEPROM Register Defines  */
end_comment

begin_define
define|#
directive|define
name|WXEECD_SK
value|0x1
end_define

begin_comment
comment|/* enable clock */
end_comment

begin_define
define|#
directive|define
name|WXEECD_CS
value|0x2
end_define

begin_comment
comment|/* chip select */
end_comment

begin_define
define|#
directive|define
name|WXEECD_DI
value|0x4
end_define

begin_comment
comment|/* data input */
end_comment

begin_define
define|#
directive|define
name|WXEECD_DO
value|0x8
end_define

begin_comment
comment|/* data output */
end_comment

begin_define
define|#
directive|define
name|EEPROM_READ_OPCODE
value|0x6
end_define

begin_comment
comment|/*  * Constant Flow Control Frame MAC Address and Type values.  */
end_comment

begin_define
define|#
directive|define
name|FC_FRM_CONST_LO
value|0x00C28001
end_define

begin_define
define|#
directive|define
name|FC_FRM_CONST_HI
value|0x0100
end_define

begin_define
define|#
directive|define
name|FC_TYP_CONST
value|0x8808
end_define

begin_comment
comment|/*  * Bits pertinent for the Receive Address register pairs. The low address  * is the low 32 bits of a 48 bit MAC address. The high address contains  * bits 32-47 of the 48 bit MAC address. The top bit in the high address  * is a 'valid' bit.  */
end_comment

begin_define
define|#
directive|define
name|WXRAH_RDR1
value|0x40000000
end_define

begin_comment
comment|/* second receive descriptor ring */
end_comment

begin_define
define|#
directive|define
name|WXRAH_VALID
value|0x80000000
end_define

begin_comment
comment|/*  * Interrupt Cause Bits  */
end_comment

begin_define
define|#
directive|define
name|WXISR_TXDW
value|0x1
end_define

begin_comment
comment|/* transmit descriptor written back */
end_comment

begin_define
define|#
directive|define
name|WXISR_TXQE
value|0x2
end_define

begin_comment
comment|/* transmit queue empty */
end_comment

begin_define
define|#
directive|define
name|WXISR_LSC
value|0x4
end_define

begin_comment
comment|/* link status change */
end_comment

begin_define
define|#
directive|define
name|WXISR_RXSEQ
value|0x8
end_define

begin_comment
comment|/* receive sequence error */
end_comment

begin_define
define|#
directive|define
name|WXISR_RXDMT0
value|0x10
end_define

begin_comment
comment|/* receiver ring 0 getting empty */
end_comment

begin_define
define|#
directive|define
name|WXISR_RXDMT1
value|0x20
end_define

begin_comment
comment|/* receiver ring 1 getting empty */
end_comment

begin_define
define|#
directive|define
name|WXISR_RXO
value|0x40
end_define

begin_comment
comment|/* receiver overrun */
end_comment

begin_define
define|#
directive|define
name|WXISR_RXT0
value|0x80
end_define

begin_comment
comment|/* ring 0 receiver timer interrupt */
end_comment

begin_define
define|#
directive|define
name|WXISR_RXT1
value|0x100
end_define

begin_comment
comment|/* ring 1 receiver timer interrupt */
end_comment

begin_define
define|#
directive|define
name|WXISR_PCIE
value|0x200
end_define

begin_comment
comment|/* ?? Probably PCI interface error... */
end_comment

begin_define
define|#
directive|define
name|WXISR_MDIAC
value|0x200
end_define

begin_define
define|#
directive|define
name|WXISR_RXCFG
value|0x400
end_define

begin_define
define|#
directive|define
name|WXISR_GPI_EN0
value|0x800
end_define

begin_define
define|#
directive|define
name|WXISR_GPI_EN1
value|0x1000
end_define

begin_comment
comment|/* appears to be PHY intr line */
end_comment

begin_define
define|#
directive|define
name|WXISR_GPI_EN2
value|0x2000
end_define

begin_define
define|#
directive|define
name|WXISR_GPI_EN3
value|0x4000
end_define

begin_define
define|#
directive|define
name|WXIENABLE_DEFAULT
define|\
value|(WXISR_RXO | WXISR_RXT0 | WXISR_RXDMT0 | WXISR_RXSEQ |	WXISR_TXDW |\ 		    WXISR_LSC | WXISR_PCIE | WXISR_GPI_EN1)
end_define

begin_define
define|#
directive|define
name|WXDISABLE
value|0xffffffff
end_define

begin_comment
comment|/*  * Receive Control Register bits.  */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_RST
value|0x1
end_define

begin_comment
comment|/* receiver reset */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_EN
value|0x2
end_define

begin_comment
comment|/* receiver enable */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_SBP
value|0x4
end_define

begin_comment
comment|/* store bad packets */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_UPE
value|0x8
end_define

begin_comment
comment|/* unicast promiscuos mode */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_MPE
value|0x10
end_define

begin_comment
comment|/* multicast promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_LPE
value|0x20
end_define

begin_comment
comment|/* large packet enable */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_BAM
value|0x8000
end_define

begin_comment
comment|/* broadcast accept mode */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_BSEX
value|0x2000000
end_define

begin_comment
comment|/* LIVENGOOD: Buffer Size Extension */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_2KRBUF
value|(0<< 16)
end_define

begin_comment
comment|/* 2KB Receive Buffers */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_1KRBUF
value|(1<< 16)
end_define

begin_comment
comment|/* 1KB Receive Buffers */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_512BRBUF
value|(2<< 16)
end_define

begin_comment
comment|/* 512 Byte Receive Buffers */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_256BRBUF
value|(3<< 16)
end_define

begin_comment
comment|/* 256 Byte Receive Buffers */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_4KRBUF
value|(3<< 16)
end_define

begin_comment
comment|/* LIVENGOOD: 4KB Receive Buffers */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_8KRBUF
value|(2<< 16)
end_define

begin_comment
comment|/* LIVENGOOD: 8KB Receive Buffers */
end_comment

begin_define
define|#
directive|define
name|WXRCTL_16KRBUF
value|(1<< 16)
end_define

begin_comment
comment|/* LIVENGOOD: 16KB Receive Buffers */
end_comment

begin_comment
comment|/*  * Receive Delay Timer Register bits.  */
end_comment

begin_define
define|#
directive|define
name|WXRDTR_FPD
value|0x80000000
end_define

begin_comment
comment|/* flush partial descriptor */
end_comment

begin_comment
comment|/*  * Transmit Configuration Word defines  */
end_comment

begin_define
define|#
directive|define
name|WXTXCW_FD
value|0x00000020
end_define

begin_comment
comment|/* Full Duplex */
end_comment

begin_define
define|#
directive|define
name|WXTXCW_PMASK
value|0x00000180
end_define

begin_comment
comment|/* pause mask */
end_comment

begin_define
define|#
directive|define
name|WXTXCW_ANE
value|0x80000000
end_define

begin_comment
comment|/* AutoNegotiate */
end_comment

begin_define
define|#
directive|define
name|WXTXCW_DEFAULT
value|0x800001A0
end_define

begin_comment
comment|/*  * Transmit Control Register defines.  */
end_comment

begin_define
define|#
directive|define
name|WXTCTL_RST
value|0x1
end_define

begin_comment
comment|/* transmitter reset */
end_comment

begin_define
define|#
directive|define
name|WXTCTL_EN
value|0x2
end_define

begin_comment
comment|/* transmitter enable */
end_comment

begin_define
define|#
directive|define
name|WXTCTL_PSP
value|0x8
end_define

begin_comment
comment|/* pad short packets */
end_comment

begin_define
define|#
directive|define
name|WXTCTL_CT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 4)
end_define

begin_comment
comment|/* 4:11 - Collision Threshold */
end_comment

begin_define
define|#
directive|define
name|WXTCTL_COLD
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3ff)<< 12)
end_define

begin_comment
comment|/* 12:21 - Collision Distance */
end_comment

begin_define
define|#
directive|define
name|WXTCTL_SWXOFF
value|(1<< 22)
end_define

begin_comment
comment|/* Software XOFF */
end_comment

begin_define
define|#
directive|define
name|WX_COLLISION_THRESHOLD
value|15
end_define

begin_define
define|#
directive|define
name|WX_FDX_COLLISION_DX
value|64
end_define

begin_define
define|#
directive|define
name|WX_HDX_COLLISION_DX
value|512
end_define

begin_comment
comment|/*  * MDI control register bits - (best-guess)  */
end_comment

begin_define
define|#
directive|define
name|WXMDIC_WRITE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|WXMDIC_READ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|WXMDIC_READY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|WXMDIC_INTR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|WXMDIC_ERR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|WXMDIC_REGADDR_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|WXMDIC_REGADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|WXMDIC_PHYADDR_MASK
value|0x03E00000
end_define

begin_define
define|#
directive|define
name|WXMDIC_PHYADDR_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|WXMDIC_DATA_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/*  * EXCT control register bits  */
end_comment

begin_define
define|#
directive|define
name|WXEXCT_GPI_EN0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WXEXCT_GPI_EN1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WXEXCT_GPI_EN2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WXEXCT_GPI_EN3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIN4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIN5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIN6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIN7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIO4
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIO5
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIO6
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WXEXCT_SWDPIO7
value|0x00000800
end_define

begin_define
define|#
directive|define
name|WXEXCT_ASDCHK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|WXEXCT_EE_RST
value|0x00002000
end_define

begin_define
define|#
directive|define
name|WXEXCT_IPS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|WXEXCT_SPD_BYPS
value|0x00008000
end_define

begin_comment
comment|/*  * PHY access using GPIO pins  */
end_comment

begin_define
define|#
directive|define
name|WXPHY_RESET_DIR
value|WXDCR_SWDPIO0
end_define

begin_define
define|#
directive|define
name|WXPHY_RESET
value|WXDCR_SWDPIN0
end_define

begin_define
define|#
directive|define
name|WXPHY_MDIO_DIR
value|WXDCR_SWDPIO2
end_define

begin_define
define|#
directive|define
name|WXPHY_MDIO
value|WXDCR_SWDPIN2
end_define

begin_define
define|#
directive|define
name|WXPHY_MDC_DIR
value|WXDCR_SWDPIO3
end_define

begin_define
define|#
directive|define
name|WXPHY_MDC
value|WXDCR_SWDPIN3
end_define

begin_define
define|#
directive|define
name|WXPHY_RESET_DIR4
value|WXEXCT_SWDPIO4
end_define

begin_define
define|#
directive|define
name|WXPHY_RESET4
value|WXEXCT_SWDPIN4
end_define

begin_comment
comment|/*  * PHY commands  */
end_comment

begin_define
define|#
directive|define
name|WXPHYC_PREAMBLE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|WXPHYC_PREAMBLE_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WXPHYC_SOF
value|0x01
end_define

begin_define
define|#
directive|define
name|WXPHYC_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|WXPHYC_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|WXPHYC_TURNAROUND
value|0x02
end_define

begin_comment
comment|/*  * Receive Configuration Word defines  */
end_comment

begin_define
define|#
directive|define
name|WXRXCW_CWMASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|WXRXCW_NC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|WXRXCW_IV
value|0x08000000
end_define

begin_define
define|#
directive|define
name|WXRXCW_CC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|WXRXCW_C
value|0x20000000
end_define

begin_define
define|#
directive|define
name|WXRXCW_SYNCH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|WXRXCW_ANC
value|0x80000000
end_define

begin_comment
comment|/*  * Miscellaneous  */
end_comment

begin_define
define|#
directive|define
name|WX_EEPROM_MAC_OFF
value|0
end_define

begin_comment
comment|/*  * Offset for Initialization Control Word #1  */
end_comment

begin_define
define|#
directive|define
name|WX_EEPROM_CTLR1_OFF
value|0xA
end_define

begin_define
define|#
directive|define
name|WX_EEPROM_CTLR1_FD
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|WX_EEPROM_CTLR1_SWDPIO_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|WX_EEPROM_CTLR1_ILOS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|WX_EEPROM_CTLR2_OFF
value|0xF
end_define

begin_define
define|#
directive|define
name|WX_EEPROM_CTLR2_SWDPIO
value|0xF0
end_define

begin_define
define|#
directive|define
name|WX_EEPROM_EXT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|WX_XTIMER_DFLT
value|0x100
end_define

begin_define
define|#
directive|define
name|WX_RCV_FLOW_HI_DFLT
value|0x8000
end_define

begin_define
define|#
directive|define
name|WX_RCV_FLOW_LO_DFLT
value|0x4000
end_define

begin_define
define|#
directive|define
name|WX_WISEMAN_TIPG_DFLT
value|(10 | (2<< 10) | (10<< 20))
end_define

begin_define
define|#
directive|define
name|WX_LIVENGOOD_TIPG_DFLT
value|(6 | (8<< 10) | (6<< 20))
end_define

begin_define
define|#
directive|define
name|WX_LIVENGOOD_CU_TIPG_DFLT
value|(8 | (8<< 10) | (6<< 20))
end_define

begin_define
define|#
directive|define
name|WX_CRC_LENGTH
value|4
end_define

begin_comment
comment|/*  * Hardware cannot transmit less than 16 bytes. It also cannot  * successfully receive less than 60 bytes.  */
end_comment

begin_define
define|#
directive|define
name|WX_MIN_XPKT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|WX_MIN_RPKT_SIZE
value|60
end_define

begin_define
define|#
directive|define
name|WX_MAX_PKT_SIZE
value|1514
end_define

begin_define
define|#
directive|define
name|WX_MAX_PKT_SIZE_JUMBO
value|9014
end_define

end_unit

