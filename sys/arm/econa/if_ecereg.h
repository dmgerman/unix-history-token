begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Yohanes Nugroho<yohanes@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ECEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_ECEREG_H
end_define

begin_define
define|#
directive|define
name|ETH_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|ETH_CFG_RMII
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PHY_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|PHY_RW_OK
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|PHY_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1)
end_define

begin_define
define|#
directive|define
name|PHY_REGISTER
parameter_list|(
name|r
parameter_list|)
value|(((r)& 0x1F)<< 8)
end_define

begin_define
define|#
directive|define
name|PHY_WRITE_COMMAND
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|PHY_READ_COMMAND
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|PHY_GET_DATA
parameter_list|(
name|d
parameter_list|)
value|(((d)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|PHY_DATA
parameter_list|(
name|d
parameter_list|)
value|(((d)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|PORT_0_CONFIG
value|0x08
end_define

begin_define
define|#
directive|define
name|ARL_TABLE_ACCESS_CONTROL_0
value|0x050
end_define

begin_define
define|#
directive|define
name|ARL_TABLE_ACCESS_CONTROL_1
value|0x054
end_define

begin_define
define|#
directive|define
name|ARL_TABLE_ACCESS_CONTROL_2
value|0x058
end_define

begin_define
define|#
directive|define
name|ARL_WRITE_COMMAND
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ARL_LOOKUP_COMMAND
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ARL_COMMAND_COMPLETE
value|(1)
end_define

begin_define
define|#
directive|define
name|PORT0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PORT1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CPU_PORT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VLAN0_GROUP_ID
value|(0)
end_define

begin_define
define|#
directive|define
name|VLAN1_GROUP_ID
value|(1)
end_define

begin_define
define|#
directive|define
name|VLAN2_GROUP_ID
value|(2)
end_define

begin_define
define|#
directive|define
name|VLAN3_GROUP_ID
value|(3)
end_define

begin_define
define|#
directive|define
name|VLAN4_GROUP_ID
value|(4)
end_define

begin_define
define|#
directive|define
name|VLAN5_GROUP_ID
value|(5)
end_define

begin_define
define|#
directive|define
name|VLAN6_GROUP_ID
value|(6)
end_define

begin_define
define|#
directive|define
name|VLAN7_GROUP_ID
value|(7)
end_define

begin_define
define|#
directive|define
name|PORT0_PVID
value|(VLAN1_GROUP_ID)
end_define

begin_define
define|#
directive|define
name|PORT1_PVID
value|(VLAN2_GROUP_ID)
end_define

begin_define
define|#
directive|define
name|CPU_PORT_PVID
value|(VLAN0_GROUP_ID)
end_define

begin_define
define|#
directive|define
name|VLAN0_VID
value|(0x111)
end_define

begin_define
define|#
directive|define
name|VLAN1_VID
value|(0x222)
end_define

begin_define
define|#
directive|define
name|VLAN2_VID
value|(0x333)
end_define

begin_define
define|#
directive|define
name|VLAN3_VID
value|(0x444)
end_define

begin_define
define|#
directive|define
name|VLAN4_VID
value|(0x555)
end_define

begin_define
define|#
directive|define
name|VLAN5_VID
value|(0x666)
end_define

begin_define
define|#
directive|define
name|VLAN6_VID
value|(0x777)
end_define

begin_define
define|#
directive|define
name|VLAN7_VID
value|(0x888)
end_define

begin_define
define|#
directive|define
name|VLAN0_GROUP
value|(PORT0 | PORT1 | CPU_PORT)
end_define

begin_define
define|#
directive|define
name|VLAN1_GROUP
value|(PORT0 | CPU_PORT)
end_define

begin_define
define|#
directive|define
name|VLAN2_GROUP
value|(PORT1 | CPU_PORT)
end_define

begin_define
define|#
directive|define
name|VLAN3_GROUP
value|(0)
end_define

begin_define
define|#
directive|define
name|VLAN4_GROUP
value|(0)
end_define

begin_define
define|#
directive|define
name|VLAN5_GROUP
value|(0)
end_define

begin_define
define|#
directive|define
name|VLAN6_GROUP
value|(0)
end_define

begin_define
define|#
directive|define
name|VLAN7_GROUP
value|(0)
end_define

begin_define
define|#
directive|define
name|SWITCH_CONFIG
value|0x004
end_define

begin_define
define|#
directive|define
name|MAC_PORT_0_CONFIG
value|0x008
end_define

begin_define
define|#
directive|define
name|MAC_PORT_1_CONFIG
value|0x00C
end_define

begin_define
define|#
directive|define
name|CPU_PORT_CONFIG
value|0x010
end_define

begin_define
define|#
directive|define
name|BIST_RESULT_TEST_0
value|0x094
end_define

begin_define
define|#
directive|define
name|FS_DMA_CONTROL
value|0x104
end_define

begin_define
define|#
directive|define
name|TS_DMA_CONTROL
value|0x100
end_define

begin_define
define|#
directive|define
name|INTERRUPT_MASK
value|0x08C
end_define

begin_define
define|#
directive|define
name|INTERRUPT_STATUS
value|0x088
end_define

begin_define
define|#
directive|define
name|TS_DESCRIPTOR_POINTER
value|0x108
end_define

begin_define
define|#
directive|define
name|TS_DESCRIPTOR_BASE_ADDR
value|0x110
end_define

begin_define
define|#
directive|define
name|FS_DESCRIPTOR_POINTER
value|0x10C
end_define

begin_define
define|#
directive|define
name|FS_DESCRIPTOR_BASE_ADDR
value|0x114
end_define

begin_define
define|#
directive|define
name|VLAN_VID_0_1
value|0x060
end_define

begin_define
define|#
directive|define
name|VLAN_VID_2_3
value|0x064
end_define

begin_define
define|#
directive|define
name|VLAN_VID_4_5
value|0x068
end_define

begin_define
define|#
directive|define
name|VLAN_VID_6_7
value|0x06C
end_define

begin_define
define|#
directive|define
name|VLAN_PORT_PVID
value|0x05C
end_define

begin_define
define|#
directive|define
name|VLAN_MEMBER_PORT_MAP
value|0x070
end_define

begin_define
define|#
directive|define
name|VLAN_TAG_PORT_MAP
value|0x074
end_define

begin_define
define|#
directive|define
name|ASIX_GIGA_PHY
value|1
end_define

begin_define
define|#
directive|define
name|TWO_SINGLE_PHY
value|2
end_define

begin_define
define|#
directive|define
name|AGERE_GIGA_PHY
value|3
end_define

begin_define
define|#
directive|define
name|VSC8601_GIGA_PHY
value|4
end_define

begin_define
define|#
directive|define
name|IC_PLUS_PHY
value|5
end_define

begin_define
define|#
directive|define
name|NOT_FOUND_PHY
value|(-1)
end_define

begin_define
define|#
directive|define
name|MAX_PACKET_LEN
value|(1536)
end_define

begin_define
define|#
directive|define
name|INVALID_ENTRY
value|0
end_define

begin_define
define|#
directive|define
name|NEW_ENTRY
value|0x1
end_define

begin_define
define|#
directive|define
name|STATIC_ENTRY
value|0x7
end_define

begin_comment
comment|/*mask status except for link change*/
end_comment

begin_define
define|#
directive|define
name|ERROR_MASK
value|0xFFFFFF7F
end_define

begin_comment
comment|/*hardware interface flags*/
end_comment

begin_define
define|#
directive|define
name|FAST_AGING
value|(0xf)
end_define

begin_define
define|#
directive|define
name|IVL_LEARNING
value|(0x1<< 22)
end_define

begin_comment
comment|/*hardware NAT accelerator*/
end_comment

begin_define
define|#
directive|define
name|HARDWARE_NAT
value|(0x1<< 23)
end_define

begin_comment
comment|/*aging		time		setting*/
end_comment

begin_comment
comment|/*skip lookup*/
end_comment

begin_define
define|#
directive|define
name|SKIP_L2_LOOKUP_PORT_1
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SKIP_L2_LOOKUP_PORT_0
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|NIC_MODE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PORT_DISABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SA_LEARNING_DISABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DISABLE_BROADCAST_PACKET
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|DISABLE_MULTICAST_PACKET
value|( 1<< 26)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

