begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_XAUI_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_XAUI_H__
end_define

begin_comment
comment|/** * @file_name xaui.h * @author Netlogic Microsystems * @brief Basic definitions of XLP XAUI ports */
end_comment

begin_define
define|#
directive|define
name|XAUI_CONFIG0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x00)
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x01)
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x02)
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG3
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x03)
end_define

begin_comment
comment|/* #define	XAUI_MAC_ADDR0_LO(block)		NAE_REG(block, 4, 0x04) #define	XAUI_MAC_ADDR0_HI(block)		NAE_REG(block, 4, 0x05) */
end_comment

begin_define
define|#
directive|define
name|XAUI_MAX_FRAME_LEN
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x08)
end_define

begin_define
define|#
directive|define
name|XAUI_REVISION_LVL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x0b)
end_define

begin_define
define|#
directive|define
name|XAUI_MII_MGMT_CMD
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x10)
end_define

begin_define
define|#
directive|define
name|XAUI_MII_MGMT_FIELD
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x11)
end_define

begin_define
define|#
directive|define
name|XAUI_MII_MGMT_CFG
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x12)
end_define

begin_define
define|#
directive|define
name|XAUI_MIIM_LINK_FALL_VEC
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x13)
end_define

begin_define
define|#
directive|define
name|XAUI_MII_MGMT_IND
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x14)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_MLR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x1f)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TR64
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x20)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TR127
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x21)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TR255
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x22)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TR511
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x23)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TR1K
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x24)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TRMAX
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x25)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TRMGV
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x26)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RBYT
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x27)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RPKT
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x28)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RFCS
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x29)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RMCA
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x2a)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RBCA
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x2b)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RXCF
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x2c)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RXPF
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x2d)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RXUO
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x2e)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RALN
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x2f)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RFLR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x30)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RCDE
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x31)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RCSE
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x32)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RUND
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x33)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_ROVR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x34)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RFRG
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x35)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_RJBR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x36)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TBYT
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x38)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TPKT
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x39)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TMCA
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x3a)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TBCA
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x3b)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TXPF
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x3c)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TDFR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x3d)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TEDF
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x3e)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TSCL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x3f)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TMCL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x40)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TLCL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x41)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TXCL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x42)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TNCL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x43)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TJBR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x46)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TFCS
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x47)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TXCF
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x48)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TOVR
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x49)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TUND
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x4a)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_TFRG
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x4b)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_CAR1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x4c)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_CAR2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x4d)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_CAM1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x4e)
end_define

begin_define
define|#
directive|define
name|XAUI_STATS_CAM2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x4f)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR0_LO
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x50)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR0_HI
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x51)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR1_LO
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x52)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR1_HI
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x53)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR2_LO
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x54)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR2_HI
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x55)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR3_LO
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x56)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR3_HI
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x57)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR_MASK0_LO
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x58)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR_MASK0_HI
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x59)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR_MASK1_LO
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x5a)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_ADDR_MASK1_HI
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x5b)
end_define

begin_define
define|#
directive|define
name|XAUI_MAC_FILTER_CFG
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x5c)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B31_0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x60)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B63_32
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x61)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B95_64
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x62)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B127_96
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x63)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B159_128
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x64)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B191_160
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x65)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B223_192
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x66)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B255_224
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x67)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B287_256
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x68)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B319_288
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x69)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B351_320
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x6a)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B383_352
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x6b)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B415_384
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x6c)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B447_416
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x6d)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B479_448
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x6e)
end_define

begin_define
define|#
directive|define
name|XAUI_HASHTBL_VEC_B511_480
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x6f)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_XGMAC_MISC0
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x76)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_RX_ABORT_DROP_COUNT
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x77)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_MACCTRL_PAUSE_QUANTA
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x78)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_MACCTRL_OPCODE
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x79)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_MAC_DA_H
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x7a)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_MAC_DA_L
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x7b)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_XGMAC_STAT
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x7c)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_XGMAC_CTRL3
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x7d)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_XGMAC_CTRL2
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x7e)
end_define

begin_define
define|#
directive|define
name|XAUI_NETIOR_XGMAC_CTRL1
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 4, 0x7f)
end_define

begin_define
define|#
directive|define
name|LANE_RX_CLK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LANE_TX_CLK
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|XAUI_LANE_FAULT
value|0x400
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_0
value|0
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_MACRST
value|0x80000000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_RSTRCTL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_RSTRFN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_RSTTCTL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_RSTTFN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_RSTMIIM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_1
value|1
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_TCTLEN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_TFEN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_RCTLEN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_RFEN
value|0x10000000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_DRPLT64
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_LENCHK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_GENFCS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_PAD_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_PAD_64
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_PAD_COND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XAUI_CONFIG_PAD_68
value|0x00000003
end_define

begin_define
define|#
directive|define
name|XAUI_PHY_CTRL_1
value|0x00
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_CTRL1
value|0x7F
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_CTRL3
value|0x7D
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_VLAN_DC_POS
value|28
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_PHYADDR_POS
value|23
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_DEVID_POS
value|18
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_STATS_EN_POS
value|17
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_TX_PFC_EN_POS
value|14
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_RX_PFC_EN_POS
value|13
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_SOFT_RST_POS
value|11
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_TX_PAUSE_POS
value|10
end_define

begin_define
define|#
directive|define
name|NETIOR_XGMAC_STATS_CLR_POS
value|16
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_function_decl
name|void
name|nlm_xaui_pcs_init
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_setup_rx_mode_xaui
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_setup_mac_addr_xaui
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_config_xaui_mtu
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_config_xaui
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(LOCORE)&& !(__ASSEMBLY__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

