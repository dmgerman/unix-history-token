begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Aleksandr Rybalko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_RTREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_RTREG_H_
end_define

begin_define
define|#
directive|define
name|RT_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->bst, (sc)->bsh, reg)
end_define

begin_define
define|#
directive|define
name|RT_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->bst, (sc)->bsh, reg, val)
end_define

begin_define
define|#
directive|define
name|GE_PORT_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_ACCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|MDIO_CMD_ONGO
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|MDIO_CMD_WR
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|MDIO_PHY_ADDR_MASK
value|0x1f000000
end_define

begin_define
define|#
directive|define
name|MDIO_PHY_ADDR_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|MDIO_PHYREG_ADDR_MASK
value|0x001f0000
end_define

begin_define
define|#
directive|define
name|MDIO_PHYREG_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MDIO_PHY_DATA_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|MDIO_PHY_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MDIO_CFG
value|0x04
end_define

begin_define
define|#
directive|define
name|MDIO_2880_100T_INIT
value|0x1001BC01
end_define

begin_define
define|#
directive|define
name|MDIO_2880_GIGA_INIT
value|0x1F01DC01
end_define

begin_define
define|#
directive|define
name|FE_GLO_CFG
value|0x08
end_define

begin_comment
comment|/*Frame Engine Global Configuration */
end_comment

begin_define
define|#
directive|define
name|EXT_VLAN_TYPE_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|EXT_VLAN_TYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EXT_VLAN_TYPE_DFLT
value|0x81000000
end_define

begin_define
define|#
directive|define
name|US_CYC_CNT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|US_CYC_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|US_CYC_CNT_DFLT
value|(132<<8)
end_define

begin_comment
comment|/* sys clocks per 1uS */
end_comment

begin_define
define|#
directive|define
name|L2_SPACE
value|(8<<4)
end_define

begin_comment
comment|/* L2 space. Unit is 8 bytes */
end_comment

begin_define
define|#
directive|define
name|FE_RST_GLO
value|0x0C
end_define

begin_comment
comment|/*Frame Engine Global Reset*/
end_comment

begin_define
define|#
directive|define
name|FC_DROP_CNT_MASK
value|0xffff0000
end_define

begin_comment
comment|/*Flow cntrl drop count */
end_comment

begin_define
define|#
directive|define
name|FC_DROP_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PSE_RESET
value|(1<<0)
end_define

begin_comment
comment|/* RT305x interrupt registers */
end_comment

begin_define
define|#
directive|define
name|FE_INT_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|CNT_PPE_AF
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|CNT_GDM_AF
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|PSE_P2_FC
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|GDM_CRC_DROP
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PSE_BUF_DROP
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GDM_OTHER_DROP
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|PSE_P1_FC
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|PSE_P0_FC
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|PSE_FQ_EMPTY
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|INT_TX_COHERENT
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|INT_RX_COHERENT
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|INT_TXQ3_DONE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|INT_TXQ2_DONE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|INT_TXQ1_DONE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|INT_TXQ0_DONE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|INT_RX_DONE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TX_DLY_INT
value|(1<<1)
end_define

begin_comment
comment|/* TXQ[0|1]_DONE with delay */
end_comment

begin_define
define|#
directive|define
name|RX_DLY_INT
value|(1<<0)
end_define

begin_comment
comment|/* RX_DONE with delay */
end_comment

begin_define
define|#
directive|define
name|FE_INT_ENABLE
value|0x14
end_define

begin_comment
comment|/* RT5350 interrupt registers */
end_comment

begin_define
define|#
directive|define
name|RT5350_FE_INT_STATUS
value|(RT5350_PDMA_BASE + 0x220)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_RX_COHERENT
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|RT5350_RX_DLY_INT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_TX_COHERENT
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|RT5350_TX_DLY_INT
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_RXQ1_DONE
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_RXQ0_DONE
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_TXQ3_DONE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_TXQ2_DONE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_TXQ1_DONE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|RT5350_INT_TXQ0_DONE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|RT5350_FE_INT_ENABLE
value|(RT5350_PDMA_BASE + 0x228)
end_define

begin_define
define|#
directive|define
name|MDIO_CFG2
value|0x18
end_define

begin_define
define|#
directive|define
name|FOE_TS_T
value|0x1c
end_define

begin_define
define|#
directive|define
name|PSE_FQ_PCNT_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|PSE_FQ_PCNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FOE_TS_TIMESTAMP_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|FOE_TS_TIMESTAMP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GDMA1_BASE
value|0x0020
end_define

begin_define
define|#
directive|define
name|GDMA2_BASE
value|0x0060
end_define

begin_define
define|#
directive|define
name|CDMA_BASE
value|0x0080
end_define

begin_define
define|#
directive|define
name|MT7620_GDMA1_BASE
value|0x600
end_define

begin_define
define|#
directive|define
name|GDMA_FWD_CFG
value|0x00
end_define

begin_comment
comment|/* Only GDMA */
end_comment

begin_define
define|#
directive|define
name|GDM_DROP_256B
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|GDM_ICS_EN
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GDM_TCS_EN
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|GDM_UCS_EN
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GDM_DISPAD
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GDM_DISCRC
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GDM_STRPCRC
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|GDM_UFRC_P_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|GDM_BFRC_P_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GDM_MFRC_P_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|GDM_OFRC_P_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GDM_XFRC_P_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|GDM_DST_PORT_CPU
value|0
end_define

begin_define
define|#
directive|define
name|GDM_DST_PORT_GDMA1
value|1
end_define

begin_define
define|#
directive|define
name|GDM_DST_PORT_GDMA2
value|2
end_define

begin_define
define|#
directive|define
name|GDM_DST_PORT_PPE
value|6
end_define

begin_define
define|#
directive|define
name|GDM_DST_PORT_DISCARD
value|7
end_define

begin_define
define|#
directive|define
name|CDMA_CSG_CFG
value|0x00
end_define

begin_comment
comment|/* Only CDMA */
end_comment

begin_define
define|#
directive|define
name|INS_VLAN_TAG
value|(0x8100<<16)
end_define

begin_define
define|#
directive|define
name|ICS_GEN_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TCS_GEN_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|UCS_GEN_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GDMA_SCH_CFG
value|0x04
end_define

begin_define
define|#
directive|define
name|GDM1_SCH_MOD_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|GDM1_SCH_MOD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|GDM1_SCH_MOD_WRR
value|0
end_define

begin_define
define|#
directive|define
name|GDM1_SCH_MOD_STRICT
value|1
end_define

begin_define
define|#
directive|define
name|GDM1_SCH_MOD_MIXED
value|2
end_define

begin_define
define|#
directive|define
name|GDM1_WT_1
value|0
end_define

begin_define
define|#
directive|define
name|GDM1_WT_2
value|1
end_define

begin_define
define|#
directive|define
name|GDM1_WT_4
value|2
end_define

begin_define
define|#
directive|define
name|GDM1_WT_8
value|3
end_define

begin_define
define|#
directive|define
name|GDM1_WT_16
value|4
end_define

begin_define
define|#
directive|define
name|GDM1_WT_Q3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|GDM1_WT_Q2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GDM1_WT_Q1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|GDM1_WT_Q0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GDMA_SHPR_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|GDM1_SHPR_EN
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GDM1_BK_SIZE_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* Bucket size 1kB units */
end_comment

begin_define
define|#
directive|define
name|GDM1_BK_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GDM1_TK_RATE_MASK
value|0x00003fff
end_define

begin_comment
comment|/* Shaper token rate 8B/ms units */
end_comment

begin_define
define|#
directive|define
name|GDM1_TK_RATE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GDMA_MAC_ADRL
value|0x0C
end_define

begin_define
define|#
directive|define
name|GDMA_MAC_ADRH
value|0x10
end_define

begin_define
define|#
directive|define
name|PPPOE_SID_0001
value|0x08
end_define

begin_comment
comment|/* 0..15 SID0, 15..31 SID1 */
end_comment

begin_define
define|#
directive|define
name|PPPOE_SID_0203
value|0x0c
end_define

begin_define
define|#
directive|define
name|PPPOE_SID_0405
value|0x10
end_define

begin_define
define|#
directive|define
name|PPPOE_SID_0607
value|0x14
end_define

begin_define
define|#
directive|define
name|PPPOE_SID_0809
value|0x18
end_define

begin_define
define|#
directive|define
name|PPPOE_SID_1011
value|0x1c
end_define

begin_define
define|#
directive|define
name|PPPOE_SID_1213
value|0x20
end_define

begin_define
define|#
directive|define
name|PPPOE_SID_1415
value|0x24
end_define

begin_define
define|#
directive|define
name|VLAN_ID_0001
value|0x28
end_define

begin_comment
comment|/* 0..11 VID0, 15..26 VID1 */
end_comment

begin_define
define|#
directive|define
name|VLAN_ID_0203
value|0x2c
end_define

begin_define
define|#
directive|define
name|VLAN_ID_0405
value|0x30
end_define

begin_define
define|#
directive|define
name|VLAN_ID_0607
value|0x34
end_define

begin_define
define|#
directive|define
name|VLAN_ID_0809
value|0x38
end_define

begin_define
define|#
directive|define
name|VLAN_ID_1011
value|0x3c
end_define

begin_define
define|#
directive|define
name|VLAN_ID_1213
value|0x40
end_define

begin_define
define|#
directive|define
name|VLAN_ID_1415
value|0x44
end_define

begin_define
define|#
directive|define
name|PSE_BASE
value|0x0040
end_define

begin_define
define|#
directive|define
name|PSE_FQFC_CFG
value|0x00
end_define

begin_define
define|#
directive|define
name|FQ_MAX_PCNT_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|FQ_MAX_PCNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FQ_FC_RLS_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|FQ_FC_RLS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FQ_FC_ASRT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|FQ_FC_ASRT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FQ_FC_DROP_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|FQ_FC_DROP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CDMA_FC_CFG
value|0x04
end_define

begin_define
define|#
directive|define
name|GDMA1_FC_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|GDMA2_FC_CFG
value|0x0C
end_define

begin_define
define|#
directive|define
name|P_SHARING
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|P_HQ_DEF_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|P_HQ_DEF_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|P_HQ_RESV_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|P_HQ_RESV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|P_LQ_RESV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|P_LQ_RESV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|P_IQ_ASRT_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|P_IQ_ASRT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CDMA_OQ_STA
value|0x10
end_define

begin_define
define|#
directive|define
name|GDMA1_OQ_STA
value|0x14
end_define

begin_define
define|#
directive|define
name|GDMA2_OQ_STA
value|0x18
end_define

begin_define
define|#
directive|define
name|P_OQ3_PCNT_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|P_OQ3_PCNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|P_OQ2_PCNT_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|P_OQ2_PCNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|P_OQ1_PCNT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|P_OQ1_PCNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|P_OQ0_PCNT_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|P_OQ0_PCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PSE_IQ_STA
value|0x1C
end_define

begin_define
define|#
directive|define
name|P6_OQ0_PCNT_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|P6_OQ0_PCNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|P2_IQ_PCNT_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|P2_IQ_PCNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|P1_IQ_PCNT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|P1_IQ_PCNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|P0_IQ_PCNT_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|P0_IQ_PCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PDMA_BASE
value|0x0100
end_define

begin_define
define|#
directive|define
name|RT5350_PDMA_BASE
value|0x0800
end_define

begin_define
define|#
directive|define
name|PDMA_GLO_CFG
value|0x00
end_define

begin_define
define|#
directive|define
name|RT5350_PDMA_GLO_CFG
value|0x204
end_define

begin_define
define|#
directive|define
name|FE_TX_WB_DDONE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|FE_DMA_BT_SIZE4
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|FE_DMA_BT_SIZE8
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|FE_DMA_BT_SIZE16
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|FE_RX_DMA_BUSY
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|FE_RX_DMA_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FE_TX_DMA_BUSY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FE_TX_DMA_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PDMA_RST_IDX
value|0x04
end_define

begin_define
define|#
directive|define
name|RT5350_PDMA_RST_IDX
value|0x208
end_define

begin_define
define|#
directive|define
name|FE_RST_DRX_IDX0
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|FE_RST_DTX_IDX3
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|FE_RST_DTX_IDX2
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FE_RST_DTX_IDX1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FE_RST_DTX_IDX0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PDMA_SCH_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|RT5350_PDMA_SCH_CFG
value|0x280
end_define

begin_define
define|#
directive|define
name|DELAY_INT_CFG
value|0x0C
end_define

begin_define
define|#
directive|define
name|RT5350_DELAY_INT_CFG
value|0x20C
end_define

begin_define
define|#
directive|define
name|TXDLY_INT_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|TXMAX_PINT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TXMAX_PTIME_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RXDLY_INT_EN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|RXMAX_PINT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RXMAX_PTIME_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TX_BASE_PTR0
value|0x10
end_define

begin_define
define|#
directive|define
name|TX_MAX_CNT0
value|0x14
end_define

begin_define
define|#
directive|define
name|TX_CTX_IDX0
value|0x18
end_define

begin_define
define|#
directive|define
name|TX_DTX_IDX0
value|0x1C
end_define

begin_define
define|#
directive|define
name|TX_BASE_PTR1
value|0x20
end_define

begin_define
define|#
directive|define
name|TX_MAX_CNT1
value|0x24
end_define

begin_define
define|#
directive|define
name|TX_CTX_IDX1
value|0x28
end_define

begin_define
define|#
directive|define
name|TX_DTX_IDX1
value|0x2C
end_define

begin_define
define|#
directive|define
name|RX_BASE_PTR0
value|0x30
end_define

begin_define
define|#
directive|define
name|RX_MAX_CNT0
value|0x34
end_define

begin_define
define|#
directive|define
name|RX_CALC_IDX0
value|0x38
end_define

begin_define
define|#
directive|define
name|RX_DRX_IDX0
value|0x3C
end_define

begin_define
define|#
directive|define
name|TX_BASE_PTR2
value|0x40
end_define

begin_define
define|#
directive|define
name|TX_MAX_CNT2
value|0x44
end_define

begin_define
define|#
directive|define
name|TX_CTX_IDX2
value|0x48
end_define

begin_define
define|#
directive|define
name|TX_DTX_IDX2
value|0x4C
end_define

begin_define
define|#
directive|define
name|TX_BASE_PTR3
value|0x50
end_define

begin_define
define|#
directive|define
name|TX_MAX_CNT3
value|0x54
end_define

begin_define
define|#
directive|define
name|TX_CTX_IDX3
value|0x58
end_define

begin_define
define|#
directive|define
name|TX_DTX_IDX3
value|0x5C
end_define

begin_define
define|#
directive|define
name|TX_BASE_PTR
parameter_list|(
name|qid
parameter_list|)
value|(((qid>1)?(0x20):(0x10)) + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|TX_MAX_CNT
parameter_list|(
name|qid
parameter_list|)
value|(((qid>1)?(0x24):(0x14)) + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|TX_CTX_IDX
parameter_list|(
name|qid
parameter_list|)
value|(((qid>1)?(0x28):(0x18)) + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|TX_DTX_IDX
parameter_list|(
name|qid
parameter_list|)
value|(((qid>1)?(0x2c):(0x1c)) + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|RT5350_TX_BASE_PTR0
value|0x000
end_define

begin_define
define|#
directive|define
name|RT5350_TX_MAX_CNT0
value|0x004
end_define

begin_define
define|#
directive|define
name|RT5350_TX_CTX_IDX0
value|0x008
end_define

begin_define
define|#
directive|define
name|RT5350_TX_DTX_IDX0
value|0x00C
end_define

begin_define
define|#
directive|define
name|RT5350_TX_BASE_PTR1
value|0x010
end_define

begin_define
define|#
directive|define
name|RT5350_TX_MAX_CNT1
value|0x014
end_define

begin_define
define|#
directive|define
name|RT5350_TX_CTX_IDX1
value|0x018
end_define

begin_define
define|#
directive|define
name|RT5350_TX_DTX_IDX1
value|0x01C
end_define

begin_define
define|#
directive|define
name|RT5350_TX_BASE_PTR2
value|0x020
end_define

begin_define
define|#
directive|define
name|RT5350_TX_MAX_CNT2
value|0x024
end_define

begin_define
define|#
directive|define
name|RT5350_TX_CTX_IDX2
value|0x028
end_define

begin_define
define|#
directive|define
name|RT5350_TX_DTX_IDX2
value|0x02C
end_define

begin_define
define|#
directive|define
name|RT5350_TX_BASE_PTR3
value|0x030
end_define

begin_define
define|#
directive|define
name|RT5350_TX_MAX_CNT3
value|0x034
end_define

begin_define
define|#
directive|define
name|RT5350_TX_CTX_IDX3
value|0x038
end_define

begin_define
define|#
directive|define
name|RT5350_TX_DTX_IDX3
value|0x03C
end_define

begin_define
define|#
directive|define
name|RT5350_RX_BASE_PTR0
value|0x100
end_define

begin_define
define|#
directive|define
name|RT5350_RX_MAX_CNT0
value|0x104
end_define

begin_define
define|#
directive|define
name|RT5350_RX_CALC_IDX0
value|0x108
end_define

begin_define
define|#
directive|define
name|RT5350_RX_DRX_IDX0
value|0x10C
end_define

begin_define
define|#
directive|define
name|RT5350_RX_BASE_PTR1
value|0x110
end_define

begin_define
define|#
directive|define
name|RT5350_RX_MAX_CNT1
value|0x114
end_define

begin_define
define|#
directive|define
name|RT5350_RX_CALC_IDX1
value|0x118
end_define

begin_define
define|#
directive|define
name|RT5350_RX_DRX_IDX1
value|0x11C
end_define

begin_define
define|#
directive|define
name|RT5350_TX_BASE_PTR
parameter_list|(
name|qid
parameter_list|)
value|((qid) * 0x10 + 0x000)
end_define

begin_define
define|#
directive|define
name|RT5350_TX_MAX_CNT
parameter_list|(
name|qid
parameter_list|)
value|((qid) * 0x10 + 0x004)
end_define

begin_define
define|#
directive|define
name|RT5350_TX_CTX_IDX
parameter_list|(
name|qid
parameter_list|)
value|((qid) * 0x10 + 0x008)
end_define

begin_define
define|#
directive|define
name|RT5350_TX_DTX_IDX
parameter_list|(
name|qid
parameter_list|)
value|((qid) * 0x10 + 0x00C)
end_define

begin_define
define|#
directive|define
name|PPE_BASE
value|0x0200
end_define

begin_define
define|#
directive|define
name|CNTR_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PPE_AC_BCNT0
value|0x000
end_define

begin_define
define|#
directive|define
name|PPE_AC_PCNT0
value|0x004
end_define

begin_define
define|#
directive|define
name|PPE_AC_BCNT63
value|0x1F8
end_define

begin_define
define|#
directive|define
name|PPE_AC_PCNT63
value|0x1FC
end_define

begin_define
define|#
directive|define
name|PPE_MTR_CNT0
value|0x200
end_define

begin_define
define|#
directive|define
name|PPE_MTR_CNT63
value|0x2FC
end_define

begin_define
define|#
directive|define
name|GDMA_TX_GBCNT0
value|0x300
end_define

begin_define
define|#
directive|define
name|GDMA_TX_GPCNT0
value|0x304
end_define

begin_define
define|#
directive|define
name|GDMA_TX_SKIPCNT0
value|0x308
end_define

begin_define
define|#
directive|define
name|GDMA_TX_COLCNT0
value|0x30C
end_define

begin_define
define|#
directive|define
name|GDMA_RX_GBCNT0
value|0x320
end_define

begin_define
define|#
directive|define
name|GDMA_RX_GPCNT0
value|0x324
end_define

begin_define
define|#
directive|define
name|GDMA_RX_OERCNT0
value|0x328
end_define

begin_define
define|#
directive|define
name|GDMA_RX_FERCNT0
value|0x32C
end_define

begin_define
define|#
directive|define
name|GDMA_RX_SHORT_ERCNT0
value|0x330
end_define

begin_define
define|#
directive|define
name|GDMA_RX_LONG_ERCNT0
value|0x334
end_define

begin_define
define|#
directive|define
name|GDMA_RX_CSUM_ERCNT0
value|0x338
end_define

begin_define
define|#
directive|define
name|POLICYTABLE_BASE
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_RTREG_H_ */
end_comment

end_unit

