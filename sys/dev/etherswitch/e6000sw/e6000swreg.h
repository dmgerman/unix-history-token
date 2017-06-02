begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Semihalf  * Copyright (c) 2015 Stormshield  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E6000SWREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_E6000SWREG_H_
end_define

begin_struct
struct|struct
name|atu_opt
block|{
name|uint16_t
name|mac_01
decl_stmt|;
name|uint16_t
name|mac_23
decl_stmt|;
name|uint16_t
name|mac_45
decl_stmt|;
name|uint16_t
name|fid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for the Marvell 88E6000 series Ethernet Switch.  */
end_comment

begin_comment
comment|/*  * Switch Registers  */
end_comment

begin_define
define|#
directive|define
name|REG_GLOBAL
value|0x1b
end_define

begin_define
define|#
directive|define
name|REG_GLOBAL2
value|0x1c
end_define

begin_define
define|#
directive|define
name|REG_PORT
parameter_list|(
name|p
parameter_list|)
value|(0x10 + (p))
end_define

begin_define
define|#
directive|define
name|REG_NUM_MAX
value|31
end_define

begin_comment
comment|/*  * Per-Port Switch Registers  */
end_comment

begin_define
define|#
directive|define
name|PORT_STATUS
value|0x0
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_SPEED_MASK
value|0x300
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_SPEED_10
value|0
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_SPEED_100
value|1
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_SPEED_1000
value|2
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_DUPLEX_MASK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_LINK_MASK
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_PHY_DETECT_MASK
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PSC_CONTROL
value|0x1
end_define

begin_define
define|#
directive|define
name|SWITCH_ID
value|0x3
end_define

begin_define
define|#
directive|define
name|PORT_CONTROL
value|0x4
end_define

begin_define
define|#
directive|define
name|PORT_CONTROL_1
value|0x5
end_define

begin_define
define|#
directive|define
name|PORT_VLAN_MAP
value|0x6
end_define

begin_define
define|#
directive|define
name|PORT_VID
value|0x7
end_define

begin_define
define|#
directive|define
name|PORT_ASSOCIATION_VECTOR
value|0xb
end_define

begin_define
define|#
directive|define
name|PORT_ATU_CTRL
value|0xc
end_define

begin_define
define|#
directive|define
name|RX_COUNTER
value|0x12
end_define

begin_define
define|#
directive|define
name|TX_COUNTER
value|0x13
end_define

begin_define
define|#
directive|define
name|PORT_VID_DEF_VID
value|0
end_define

begin_define
define|#
directive|define
name|PORT_VID_DEF_VID_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|PORT_VID_PRIORITY_MASK
value|0xc00
end_define

begin_define
define|#
directive|define
name|PORT_CONTROL_ENABLE
value|0x3
end_define

begin_comment
comment|/* PORT_VLAN fields */
end_comment

begin_define
define|#
directive|define
name|PORT_VLAN_MAP_TABLE_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|PORT_VLAN_MAP_FID
value|12
end_define

begin_define
define|#
directive|define
name|PORT_VLAN_MAP_FID_MASK
value|0xf000
end_define

begin_comment
comment|/*  * Switch Global Register 1 accessed via REG_GLOBAL_ADDR  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_GLOBAL_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|SWITCH_GLOBAL_CONTROL
value|4
end_define

begin_define
define|#
directive|define
name|SWITCH_GLOBAL_CONTROL2
value|28
end_define

begin_define
define|#
directive|define
name|MONITOR_CONTROL
value|26
end_define

begin_comment
comment|/* ATU operation */
end_comment

begin_define
define|#
directive|define
name|ATU_FID
value|1
end_define

begin_define
define|#
directive|define
name|ATU_CONTROL
value|10
end_define

begin_define
define|#
directive|define
name|ATU_OPERATION
value|11
end_define

begin_define
define|#
directive|define
name|ATU_DATA
value|12
end_define

begin_define
define|#
directive|define
name|ATU_MAC_ADDR01
value|13
end_define

begin_define
define|#
directive|define
name|ATU_MAC_ADDR23
value|14
end_define

begin_define
define|#
directive|define
name|ATU_MAC_ADDR45
value|15
end_define

begin_define
define|#
directive|define
name|ATU_UNIT_BUSY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|ENTRY_STATE
value|0xf
end_define

begin_comment
comment|/* ATU_CONTROL fields */
end_comment

begin_define
define|#
directive|define
name|ATU_CONTROL_AGETIME
value|4
end_define

begin_define
define|#
directive|define
name|ATU_CONTROL_AGETIME_MASK
value|0xff0
end_define

begin_define
define|#
directive|define
name|ATU_CONTROL_LEARN2ALL
value|3
end_define

begin_comment
comment|/* ATU opcode */
end_comment

begin_define
define|#
directive|define
name|NO_OPERATION
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_ALL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_NON_STATIC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LOAD_FROM_FIB
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|PURGE_FROM_FIB
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|GET_NEXT_IN_FIB
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FLUSH_ALL_IN_FIB
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_NON_STATIC_IN_FIB
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|GET_VIOLATION_DATA
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|CLEAR_VIOLATION_DATA
value|(7<< 0)
end_define

begin_comment
comment|/* ATU Stats */
end_comment

begin_define
define|#
directive|define
name|COUNT_ALL
value|(0<< 0)
end_define

begin_comment
comment|/*  * Switch Global Register 2 accessed via REG_GLOBAL2_ADDR  */
end_comment

begin_define
define|#
directive|define
name|MGMT_EN_2x
value|2
end_define

begin_define
define|#
directive|define
name|MGMT_EN_0x
value|3
end_define

begin_define
define|#
directive|define
name|SWITCH_MGMT
value|5
end_define

begin_define
define|#
directive|define
name|ATU_STATS
value|14
end_define

begin_define
define|#
directive|define
name|MGMT_EN_ALL
value|0xffff
end_define

begin_comment
comment|/* SWITCH_MGMT fields */
end_comment

begin_define
define|#
directive|define
name|SWITCH_MGMT_PRI
value|0
end_define

begin_define
define|#
directive|define
name|SWITCH_MGMT_PRI_MASK
value|7
end_define

begin_define
define|#
directive|define
name|SWITCH_MGMT_RSVD2CPU
value|3
end_define

begin_define
define|#
directive|define
name|SWITCH_MGMT_FC_PRI
value|4
end_define

begin_define
define|#
directive|define
name|SWITCH_MGMT_FC_PRI_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|SWITCH_MGMT_FORCEFLOW
value|7
end_define

begin_comment
comment|/* ATU_STATS fields */
end_comment

begin_define
define|#
directive|define
name|ATU_STATS_BIN
value|14
end_define

begin_define
define|#
directive|define
name|ATU_STATS_FLAG
value|12
end_define

begin_comment
comment|/*  * PHY registers accessed via 'Switch Global Registers' (REG_GLOBAL2).  */
end_comment

begin_define
define|#
directive|define
name|SMI_PHY_CMD_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|SMI_PHY_DATA_REG
value|0x19
end_define

begin_define
define|#
directive|define
name|PHY_DATA_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|PHY_CMD_SMI_BUSY
value|15
end_define

begin_define
define|#
directive|define
name|PHY_CMD_MODE
value|12
end_define

begin_define
define|#
directive|define
name|PHY_CMD_MODE_MDIO
value|1
end_define

begin_define
define|#
directive|define
name|PHY_CMD_MODE_XMDIO
value|0
end_define

begin_define
define|#
directive|define
name|PHY_CMD_OPCODE
value|10
end_define

begin_define
define|#
directive|define
name|PHY_CMD_OPCODE_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|PHY_CMD_OPCODE_READ
value|2
end_define

begin_define
define|#
directive|define
name|PHY_CMD_DEV_ADDR
value|5
end_define

begin_define
define|#
directive|define
name|PHY_CMD_DEV_ADDR_MASK
value|0x3e0
end_define

begin_define
define|#
directive|define
name|PHY_CMD_REG_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|PHY_CMD_REG_ADDR_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|PHY_PAGE_REG
value|22
end_define

begin_comment
comment|/*  * Scratch and Misc register accessed via  * 'Switch Global Registers' (REG_GLOBAL2)  */
end_comment

begin_define
define|#
directive|define
name|SCR_AND_MISC_REG
value|0x1a
end_define

begin_define
define|#
directive|define
name|SCR_AND_MISC_PTR_CFG
value|0x7000
end_define

begin_define
define|#
directive|define
name|SCR_AND_MISC_DATA_CFG_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|E6000SW_NUM_PHY_REGS
value|29
end_define

begin_define
define|#
directive|define
name|E6000SW_NUM_VGROUPS
value|8
end_define

begin_define
define|#
directive|define
name|E6000SW_MAX_PORTS
value|10
end_define

begin_define
define|#
directive|define
name|E6000SW_PORT_NO_VGROUP
value|-1
end_define

begin_define
define|#
directive|define
name|E6000SW_DEFAULT_AGETIME
value|20
end_define

begin_define
define|#
directive|define
name|E6000SW_RETRIES
value|100
end_define

begin_define
define|#
directive|define
name|E6000SW_SMI_TIMEOUT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _E6000SWREG_H_ */
end_comment

end_unit

