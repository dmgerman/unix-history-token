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
comment|/* XXX Linux define compatibility stuff */
end_comment

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|_m
parameter_list|)
value|(1UL<< (_m))
end_define

begin_define
define|#
directive|define
name|BITM
parameter_list|(
name|_count
parameter_list|)
value|((1UL<< (_count)) - 1)
end_define

begin_define
define|#
directive|define
name|BITS
parameter_list|(
name|_shift
parameter_list|,
name|_count
parameter_list|)
value|(BITM(_count)<< (_shift))
end_define

begin_comment
comment|/* Atheros specific MII registers */
end_comment

begin_define
define|#
directive|define
name|MII_ATH_MMD_ADDR
value|0x0d
end_define

begin_define
define|#
directive|define
name|MII_ATH_MMD_DATA
value|0x0e
end_define

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
value|(1U<< 31)
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
value|(1U<< 31)
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
name|AR8216_REG_ATU
value|0x0050
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP
value|BITS(0, 3)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP_NOOP
value|0x0
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP_FLUSH
value|0x1
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP_LOAD
value|0x2
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP_PURGE
value|0x3
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP_FLUSH_LOCKED
value|0x4
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP_FLUSH_UNICAST
value|0x5
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_OP_GET_NEXT
value|0x6
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_ACTIVE
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_PORT_NUM
value|BITS(8, 4)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_FULL_VIO
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_ADDR4
value|BITS(16, 8)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_ADDR5
value|BITS(24, 8)
end_define

begin_define
define|#
directive|define
name|AR8216_REG_ATU_DATA
value|0x0054
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_ADDR3
value|BITS(0, 8)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_ADDR2
value|BITS(8, 8)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_ADDR1
value|BITS(16, 8)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_ADDR0
value|BITS(24, 8)
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
name|AR8216_REG_ATU_CTRL
value|0x005C
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_CTRL_AGE_EN
value|BIT(17)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_CTRL_AGE_TIME
value|BITS(0, 16)
end_define

begin_define
define|#
directive|define
name|AR8216_ATU_CTRL_AGE_TIME_S
value|0
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
name|AR934X_MIB_ENABLE
value|(1<< 30)
end_define

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
value|(1U<< 31)
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

begin_comment
comment|/*  * AR9340 switch specific definitions.  */
end_comment

begin_define
define|#
directive|define
name|AR934X_REG_OPER_MODE0
value|0x04
end_define

begin_define
define|#
directive|define
name|AR934X_OPER_MODE0_MAC_GMII_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR934X_OPER_MODE0_PHY_MII_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR934X_REG_OPER_MODE1
value|0x08
end_define

begin_define
define|#
directive|define
name|AR934X_REG_OPER_MODE1_PHY4_MII_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AR934X_REG_FLOOD_MASK
value|0x2c
end_define

begin_define
define|#
directive|define
name|AR934X_FLOOD_MASK_MC_DP
parameter_list|(
name|_p
parameter_list|)
value|(1<< (16 + (_p)))
end_define

begin_define
define|#
directive|define
name|AR934X_FLOOD_MASK_BC_DP
parameter_list|(
name|_p
parameter_list|)
value|(1<< (25 + (_p)))
end_define

begin_define
define|#
directive|define
name|AR934X_REG_QM_CTRL
value|0x3c
end_define

begin_define
define|#
directive|define
name|AR934X_QM_CTRL_ARP_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AR934X_REG_AT_CTRL
value|0x5c
end_define

begin_define
define|#
directive|define
name|AR934X_AT_CTRL_AGE_TIME
value|BITS(0, 15)
end_define

begin_define
define|#
directive|define
name|AR934X_AT_CTRL_AGE_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR934X_AT_CTRL_LEARN_CHANGE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AR934X_REG_PORT_BASE
parameter_list|(
name|_port
parameter_list|)
value|(0x100 + (_port) * 0x100)
end_define

begin_define
define|#
directive|define
name|AR934X_REG_PORT_VLAN1
parameter_list|(
name|_port
parameter_list|)
value|(AR934X_REG_PORT_BASE((_port)) + 0x08)
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_DEFAULT_SVID_S
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_FORCE_DEFAULT_VID_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_PORT_TLS_MODE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_PORT_VLAN_PROP_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_PORT_CLONE_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_DEFAULT_CVID_S
value|16
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_FORCE_PORT_VLAN_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN1_ING_PORT_PRI_S
value|29
end_define

begin_define
define|#
directive|define
name|AR934X_REG_PORT_VLAN2
parameter_list|(
name|_port
parameter_list|)
value|(AR934X_REG_PORT_BASE((_port)) + 0x0c)
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN2_PORT_VID_MEM_S
value|16
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN2_8021Q_MODE_S
value|30
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN2_8021Q_MODE_PORT_ONLY
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN2_8021Q_MODE_PORT_FALLBACK
value|1
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN2_8021Q_MODE_VLAN_ONLY
value|2
end_define

begin_define
define|#
directive|define
name|AR934X_PORT_VLAN2_8021Q_MODE_SECURE
value|3
end_define

begin_comment
comment|/*  * AR8327 specific registers  */
end_comment

begin_define
define|#
directive|define
name|AR8327_NUM_PORTS
value|7
end_define

begin_define
define|#
directive|define
name|AR8327_NUM_PHYS
value|5
end_define

begin_define
define|#
directive|define
name|AR8327_PORTS_ALL
value|0x7f
end_define

begin_define
define|#
directive|define
name|AR8327_REG_MASK
value|0x000
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PAD0_MODE
value|0x004
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PAD5_MODE
value|0x008
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PAD6_MODE
value|0x00c
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_MAC_MII_RXCLK_SEL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_MAC_MII_TXCLK_SEL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_MAC_MII_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_MAC_GMII_RXCLK_SEL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_MAC_GMII_TXCLK_SEL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_MAC_GMII_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_SGMII_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHY_MII_RXCLK_SEL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHY_MII_TXCLK_SEL
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHY_MII_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHY_GMII_PIPE_RXCLK_SEL
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHY_GMII_RXCLK_SEL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHY_GMII_TXCLK_SEL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHY_GMII_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHYX_GMII_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHYX_RGMII_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_PHYX_MII_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_SGMII_DELAY_EN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_RGMII_RXCLK_DELAY_SEL
value|BITS(20, 2)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_RGMII_RXCLK_DELAY_SEL_S
value|20
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_RGMII_TXCLK_DELAY_SEL
value|BITS(22, 2)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_RGMII_TXCLK_DELAY_SEL_S
value|22
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_RGMII_RXCLK_DELAY_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_RGMII_TXCLK_DELAY_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AR8327_PAD_RGMII_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_POWER_ON_STRIP
value|0x010
end_define

begin_define
define|#
directive|define
name|AR8327_POWER_ON_STRIP_POWER_ON_SEL
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AR8327_POWER_ON_STRIP_LED_OPEN_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AR8327_POWER_ON_STRIP_SERDES_AEN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_INT_STATUS0
value|0x020
end_define

begin_define
define|#
directive|define
name|AR8327_INT0_VT_DONE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_INT_STATUS1
value|0x024
end_define

begin_define
define|#
directive|define
name|AR8327_REG_INT_MASK0
value|0x028
end_define

begin_define
define|#
directive|define
name|AR8327_REG_INT_MASK1
value|0x02c
end_define

begin_define
define|#
directive|define
name|AR8327_REG_MODULE_EN
value|0x030
end_define

begin_define
define|#
directive|define
name|AR8327_MODULE_EN_MIB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_MIB_FUNC
value|0x034
end_define

begin_define
define|#
directive|define
name|AR8327_MIB_CPU_KEEP
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_MDIO_CTRL
value|0x03c
end_define

begin_define
define|#
directive|define
name|AR8327_REG_SERVICE_TAG
value|0x048
end_define

begin_define
define|#
directive|define
name|AR8327_REG_LED_CTRL0
value|0x050
end_define

begin_define
define|#
directive|define
name|AR8327_REG_LED_CTRL1
value|0x054
end_define

begin_define
define|#
directive|define
name|AR8327_REG_LED_CTRL2
value|0x058
end_define

begin_define
define|#
directive|define
name|AR8327_REG_LED_CTRL3
value|0x05c
end_define

begin_define
define|#
directive|define
name|AR8327_REG_MAC_ADDR0
value|0x060
end_define

begin_define
define|#
directive|define
name|AR8327_REG_MAC_ADDR1
value|0x064
end_define

begin_define
define|#
directive|define
name|AR8327_REG_MAX_FRAME_SIZE
value|0x078
end_define

begin_define
define|#
directive|define
name|AR8327_MAX_FRAME_SIZE_MTU
value|BITS(0, 14)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_STATUS
parameter_list|(
name|_i
parameter_list|)
value|(0x07c + (_i) * 4)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_HEADER_CTRL
value|0x098
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_HEADER
parameter_list|(
name|_i
parameter_list|)
value|(0x09c + (_i) * 4)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_SGMII_CTRL
value|0x0e0
end_define

begin_define
define|#
directive|define
name|AR8327_SGMII_CTRL_EN_PLL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR8327_SGMII_CTRL_EN_RX
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR8327_SGMII_CTRL_EN_TX
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_VLAN0
parameter_list|(
name|_i
parameter_list|)
value|(0x420 + (_i) * 0x8)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN0_DEF_SVID
value|BITS(0, 12)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN0_DEF_SVID_S
value|0
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN0_DEF_CVID
value|BITS(16, 12)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN0_DEF_CVID_S
value|16
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_VLAN1
parameter_list|(
name|_i
parameter_list|)
value|(0x424 + (_i) * 0x8)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN1_PORT_VLAN_PROP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN1_OUT_MODE
value|BITS(12, 2)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN1_OUT_MODE_S
value|12
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN1_OUT_MODE_UNMOD
value|0
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN1_OUT_MODE_UNTAG
value|1
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN1_OUT_MODE_TAG
value|2
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_VLAN1_OUT_MODE_UNTOUCH
value|3
end_define

begin_define
define|#
directive|define
name|AR8327_REG_ATU_DATA0
value|0x600
end_define

begin_define
define|#
directive|define
name|AR8327_REG_ATU_DATA1
value|0x604
end_define

begin_define
define|#
directive|define
name|AR8327_REG_ATU_DATA2
value|0x608
end_define

begin_define
define|#
directive|define
name|AR8327_REG_ATU_FUNC
value|0x60c
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP
value|BITS(0, 4)
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_NOOP
value|0x0
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_FLUSH
value|0x1
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_LOAD
value|0x2
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_PURGE
value|0x3
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_FLUSH_LOCKED
value|0x4
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_FLUSH_UNICAST
value|0x5
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_GET_NEXT
value|0x6
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_SEARCH_MAC
value|0x7
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_OP_CHANGE_TRUNK
value|0x8
end_define

begin_define
define|#
directive|define
name|AR8327_ATU_FUNC_BUSY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_VTU_FUNC0
value|0x0610
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_EG_MODE
value|BITS(4, 14)
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_EG_MODE_S
parameter_list|(
name|_i
parameter_list|)
value|(4 + (_i) * 2)
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_EG_MODE_KEEP
value|0
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_EG_MODE_UNTAG
value|1
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_EG_MODE_TAG
value|2
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_EG_MODE_NOT
value|3
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_IVL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC0_VALID
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_VTU_FUNC1
value|0x0614
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP
value|BITS(0, 3)
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP_NOOP
value|0
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP_FLUSH
value|1
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP_LOAD
value|2
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP_PURGE
value|3
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP_REMOVE_PORT
value|4
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP_GET_NEXT
value|5
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_OP_GET_ONE
value|6
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_FULL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_PORT
value|(1<< 8, 4)
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_PORT_S
value|8
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_VID
value|(1<< 16, 12)
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_VID_S
value|16
end_define

begin_define
define|#
directive|define
name|AR8327_VTU_FUNC1_BUSY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_FWD_CTRL0
value|0x620
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL0_CPU_PORT_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL0_MIRROR_PORT
value|BITS(4, 4)
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL0_MIRROR_PORT_S
value|4
end_define

begin_define
define|#
directive|define
name|AR8327_REG_FWD_CTRL1
value|0x624
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_UC_FLOOD
value|BITS(0, 7)
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_UC_FLOOD_S
value|0
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_MC_FLOOD
value|BITS(8, 7)
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_MC_FLOOD_S
value|8
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_BC_FLOOD
value|BITS(16, 7)
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_BC_FLOOD_S
value|16
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_IGMP
value|BITS(24, 7)
end_define

begin_define
define|#
directive|define
name|AR8327_FWD_CTRL1_IGMP_S
value|24
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_LOOKUP
parameter_list|(
name|_i
parameter_list|)
value|(0x660 + (_i) * 0xc)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_LOOKUP_MEMBER
value|BITS(0, 7)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_LOOKUP_IN_MODE
value|BITS(8, 2)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_LOOKUP_IN_MODE_S
value|8
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_LOOKUP_STATE
value|BITS(16, 3)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_LOOKUP_STATE_S
value|16
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_LOOKUP_LEARN
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_LOOKUP_ING_MIRROR_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_PRIO
parameter_list|(
name|_i
parameter_list|)
value|(0x664 + (_i) * 0xc)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_HOL_CTRL1
parameter_list|(
name|_i
parameter_list|)
value|(0x974 + (_i) * 0x8)
end_define

begin_define
define|#
directive|define
name|AR8327_PORT_HOL_CTRL1_EG_MIRROR_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR8327_REG_PORT_STATS_BASE
parameter_list|(
name|_i
parameter_list|)
value|(0x1000 + (_i) * 0x100)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR8X16_SWITCHREG_H__ */
end_comment

end_unit

