begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Aleksandr Rybalko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR8X16_SWITCHREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR8X16_SWITCHREG_H__
end_define

begin_comment
comment|/* XXX doesn't belong here; stolen shamelessly from ath_hal/ah_internal.h */
end_comment

begin_comment
comment|/*  * Register manipulation macros that expect bit field defines  * to follow the convention that an _S suffix is appended for  * a shift count, while the field mask has no suffix.  */
end_comment

begin_define
define|#
directive|define
name|SM
parameter_list|(
name|_v
parameter_list|,
name|_f
parameter_list|)
value|(((_v)<< _f##_S)& (_f))
end_define

begin_define
define|#
directive|define
name|MS
parameter_list|(
name|_v
parameter_list|,
name|_f
parameter_list|)
value|(((_v)& (_f))>> _f##_S)
end_define

begin_comment
comment|/* Atheros specific MII registers */
end_comment

begin_define
define|#
directive|define
name|MII_ATH_DBG_ADDR
value|0x1d
end_define

begin_define
define|#
directive|define
name|MII_ATH_DBG_DATA
value|0x1e
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_MASK_CTRL
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR8X16_MASK_CTRL_REV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR8X16_MASK_CTRL_VER_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR8X16_MASK_CTRL_VER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AR8X16_MASK_CTRL_SOFT_RESET
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_MODE
value|0x0008
end_define

begin_comment
comment|/* DIR-615 E4 U-Boot */
end_comment

begin_define
define|#
directive|define
name|AR8X16_MODE_DIR_615_UBOOT
value|0x8d1003e0
end_define

begin_comment
comment|/* From Ubiquiti RSPRO */
end_comment

begin_define
define|#
directive|define
name|AR8X16_MODE_RGMII_PORT4_ISO
value|0x81461bea
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_RGMII_PORT4_SWITCH
value|0x01261be2
end_define

begin_comment
comment|/* AVM Fritz!Box 7390 */
end_comment

begin_define
define|#
directive|define
name|AR8X16_MODE_GMII
value|0x010e5b71
end_define

begin_comment
comment|/* from avm_cpmac/linux_ar_reg.h */
end_comment

begin_define
define|#
directive|define
name|AR8X16_MODE_RESERVED
value|0x000e1b20
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_MAC0_GMII_EN
value|(1u<<  0)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_MAC0_RGMII_EN
value|(1u<<  1)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_PHY4_GMII_EN
value|(1u<<  2)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_PHY4_RGMII_EN
value|(1u<<  3)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_MAC0_MAC_MODE
value|(1u<<  4)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_RGMII_RXCLK_DELAY_EN
value|(1u<<  6)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_RGMII_TXCLK_DELAY_EN
value|(1u<<  7)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_MAC5_MAC_MODE
value|(1u<< 14)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_MAC5_PHY_MODE
value|(1u<< 15)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_TXDELAY_S0
value|(1u<< 21)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_TXDELAY_S1
value|(1u<< 22)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_RXDELAY_S0
value|(1u<< 23)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_LED_OPEN_EN
value|(1u<< 24)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_SPI_EN
value|(1u<< 25)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_RXDELAY_S1
value|(1u<< 26)
end_define

begin_define
define|#
directive|define
name|AR8X16_MODE_POWER_ON_SEL
value|(1u<< 31)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_ISR
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_IMR
value|0x0014
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_SW_MAC_ADDR0
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_SW_MAC_ADDR1
value|0x0024
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_FLOOD_MASK
value|0x002c
end_define

begin_define
define|#
directive|define
name|AR8X16_FLOOD_MASK_BCAST_TO_CPU
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_GLOBAL_CTRL
value|0x0030
end_define

begin_define
define|#
directive|define
name|AR8216_GLOBAL_CTRL_MTU_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR8216_GLOBAL_CTRL_MTU_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR8316_GLOBAL_CTRL_MTU_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR8316_GLOBAL_CTRL_MTU_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR8236_GLOBAL_CTRL_MTU_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR8236_GLOBAL_CTRL_MTU_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR7240_GLOBAL_CTRL_MTU_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|AR7240_GLOBAL_CTRL_MTU_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_VLAN_CTRL
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP_NOOP
value|0x0
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP_FLUSH
value|0x1
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP_LOAD
value|0x2
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP_PURGE
value|0x3
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP_REMOVE_PORT
value|0x4
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP_GET_NEXT
value|0x5
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_OP_GET
value|0x6
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_ACTIVE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_FULL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_PORT
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_PORT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_VID
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_VID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_PRIO
value|0x70000000
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_PRIO_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_PRIO_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_VLAN_DATA
value|0x0044
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_MEMBER
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|AR8X16_VLAN_VALID
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_ARL_CTRL0
value|0x0050
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_ARL_CTRL1
value|0x0054
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_ARL_CTRL2
value|0x0058
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_AT_CTRL
value|0x005c
end_define

begin_define
define|#
directive|define
name|AR8X16_AT_CTRL_ARP_EN
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_IP_PRIORITY_1
value|0x0060
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_IP_PRIORITY_2
value|0x0064
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_IP_PRIORITY_3
value|0x0068
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_IP_PRIORITY_4
value|0x006C
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_TAG_PRIO
value|0x0070
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_SERVICE_TAG
value|0x0074
end_define

begin_define
define|#
directive|define
name|AR8X16_SERVICE_TAG_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_CPU_PORT
value|0x0078
end_define

begin_define
define|#
directive|define
name|AR8X16_MIRROR_PORT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|AR8X16_MIRROR_PORT_MASK
value|(0xf<< AR8X16_MIRROR_PORT_SHIFT)
end_define

begin_define
define|#
directive|define
name|AR8X16_CPU_MIRROR_PORT
parameter_list|(
name|_p
parameter_list|)
value|((_p)<< AR8X16_MIRROR_PORT_SHIFT)
end_define

begin_define
define|#
directive|define
name|AR8X16_CPU_MIRROR_DIS
value|AR8X16_CPU_MIRROR_PORT(0xf)
end_define

begin_define
define|#
directive|define
name|AR8X16_CPU_PORT_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_MIB_FUNC0
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_TIMER_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_AT_HALF_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_BUSY
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_FUNC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_FUNC_NO_OP
value|0x0
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_FUNC_FLUSH
value|0x1
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_FUNC_CAPTURE
value|0x3
end_define

begin_define
define|#
directive|define
name|AR8X16_MIB_FUNC_XXX
value|(1<< 30)
end_define

begin_comment
comment|/* 0x40000000 */
end_comment

begin_define
define|#
directive|define
name|AR8X16_REG_MDIO_HIGH_ADDR
value|0x0094
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_MDIO_CTRL
value|0x0098
end_define

begin_define
define|#
directive|define
name|AR8X16_MDIO_CTRL_DATA_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR8X16_MDIO_CTRL_REG_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AR8X16_MDIO_CTRL_PHY_ADDR_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|AR8X16_MDIO_CTRL_CMD_WRITE
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_MDIO_CTRL_CMD_READ
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AR8X16_MDIO_CTRL_MASTER_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AR8X16_MDIO_CTRL_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_PORT_BASE
parameter_list|(
name|_p
parameter_list|)
value|(0x0100 + (_p) * 0x0100)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_PORT_STS
parameter_list|(
name|_p
parameter_list|)
value|(AR8X16_REG_PORT_BASE((_p)) + 0x0000)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_SPEED_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_SPEED_10
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_SPEED_100
value|1
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_SPEED_1000
value|2
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_TXMAC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_RXMAC
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_TXFLOW
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_RXFLOW
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_DUPLEX
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_LINK_UP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_LINK_AUTO
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_STS_LINK_PAUSE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_PORT_CTRL
parameter_list|(
name|_p
parameter_list|)
value|(AR8X16_REG_PORT_BASE((_p)) + 0x0004)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_STATE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_STATE_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_STATE_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_STATE_LISTEN
value|2
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_STATE_LEARN
value|3
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_STATE_FORWARD
value|4
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_LEARN_LOCK
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_EGRESS_VLAN_MODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_EGRESS_VLAN_MODE_KEEP
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_EGRESS_VLAN_MODE_STRIP
value|1
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_EGRESS_VLAN_MODE_ADD
value|2
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_EGRESS_VLAN_MODE_DOUBLE_TAG
value|3
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_IGMP_SNOOP
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_HEADER
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_MAC_LOOP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_SINGLE_VLAN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_LEARN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_DOUBLE_TAG
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_MIRROR_TX
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CTRL_MIRROR_RX
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_PORT_VLAN
parameter_list|(
name|_p
parameter_list|)
value|(AR8X16_REG_PORT_BASE((_p)) + 0x0008)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_DEFAULT_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_DEST_PORTS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_MODE_MASK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_MODE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_MODE_PORT_ONLY
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_MODE_PORT_FALLBACK
value|1
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_MODE_VLAN_ONLY
value|2
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_VLAN_MODE_SECURE
value|3
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_PORT_RATE_LIM
parameter_list|(
name|_p
parameter_list|)
value|(AR8X16_REG_PORT_BASE((_p)) + 0x000c)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_128KB
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_256KB
value|1
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_512KB
value|2
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_1MB
value|3
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_2MB
value|4
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_4MB
value|5
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_8MB
value|6
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_16MB
value|7
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_32MB
value|8
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_64MB
value|9
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_IN_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_OUT_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_IN_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_IN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_OUT_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_RATE_LIM_OUT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_PORT_PRIORITY
parameter_list|(
name|_p
parameter_list|)
value|(AR8X16_REG_PORT_BASE((_p)) + 0x0010)
end_define

begin_define
define|#
directive|define
name|AR8X16_REG_STATS_BASE
parameter_list|(
name|_p
parameter_list|)
value|(0x20000 + (_p) * 0x100)
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXBROAD
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXPAUSE
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXMULTI
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXFCSERR
value|0x000c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXALIGNERR
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXRUNT
value|0x0014
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXFRAGMENT
value|0x0018
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RX64BYTE
value|0x001c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RX128BYTE
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RX256BYTE
value|0x0024
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RX512BYTE
value|0x0028
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RX1024BYTE
value|0x002c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RX1518BYTE
value|0x0030
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXMAXBYTE
value|0x0034
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXTOOLONG
value|0x0038
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXGOODBYTE
value|0x003c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXBADBYTE
value|0x0044
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_RXOVERFLOW
value|0x004c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_FILTERED
value|0x0050
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXBROAD
value|0x0054
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXPAUSE
value|0x0058
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXMULTI
value|0x005c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXUNDERRUN
value|0x0060
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TX64BYTE
value|0x0064
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TX128BYTE
value|0x0068
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TX256BYTE
value|0x006c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TX512BYTE
value|0x0070
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TX1024BYTE
value|0x0074
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TX1518BYTE
value|0x0078
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXMAXBYTE
value|0x007c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXOVERSIZE
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXBYTE
value|0x0084
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXCOLLISION
value|0x008c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXABORTCOL
value|0x0090
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXMULTICOL
value|0x0094
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXSINGLECOL
value|0x0098
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXEXCDEFER
value|0x009c
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXDEFER
value|0x00a0
end_define

begin_define
define|#
directive|define
name|AR8X16_STATS_TXLATECOL
value|0x00a4
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_CPU
value|0
end_define

begin_define
define|#
directive|define
name|AR8X16_NUM_PORTS
value|6
end_define

begin_define
define|#
directive|define
name|AR8X16_NUM_PHYS
value|5
end_define

begin_define
define|#
directive|define
name|AR8X16_MAGIC
value|0xc000050e
end_define

begin_define
define|#
directive|define
name|AR8X16_PHY_ID1
value|0x004d
end_define

begin_define
define|#
directive|define
name|AR8X16_PHY_ID2
value|0xd041
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_MASK
parameter_list|(
name|_port
parameter_list|)
value|(1<< (_port))
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_MASK_ALL
value|((1<<AR8X16_NUM_PORTS)-1)
end_define

begin_define
define|#
directive|define
name|AR8X16_PORT_MASK_BUT
parameter_list|(
name|_port
parameter_list|)
value|(AR8X16_PORT_MASK_ALL& ~(1<< (_port)))
end_define

begin_define
define|#
directive|define
name|AR8X16_MAX_VLANS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR8X16_SWITCHREG_H__ */
end_comment

end_unit

