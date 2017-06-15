begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPA_PORT_INFO_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|OPA_PORT_INFO_H
end_define

begin_define
define|#
directive|define
name|OPA_PORT_LINK_MODE_NOP
value|0
end_define

begin_comment
comment|/* No change */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_LINK_MODE_OPA
value|4
end_define

begin_comment
comment|/* Port mode is OPA */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_PACKET_FORMAT_NOP
value|0
end_define

begin_comment
comment|/* No change */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_PACKET_FORMAT_8B
value|1
end_define

begin_comment
comment|/* Format 8B */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_PACKET_FORMAT_9B
value|2
end_define

begin_comment
comment|/* Format 9B */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_PACKET_FORMAT_10B
value|4
end_define

begin_comment
comment|/* Format 10B */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_PACKET_FORMAT_16B
value|8
end_define

begin_comment
comment|/* Format 16B */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_LTP_CRC_MODE_NONE
value|0
end_define

begin_comment
comment|/* No change */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_LTP_CRC_MODE_14
value|1
end_define

begin_comment
comment|/* 14-bit LTP CRC mode (optional) */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_LTP_CRC_MODE_16
value|2
end_define

begin_comment
comment|/* 16-bit LTP CRC mode */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_LTP_CRC_MODE_48
value|4
end_define

begin_comment
comment|/* 48-bit LTP CRC mode (optional) */
end_comment

begin_define
define|#
directive|define
name|OPA_PORT_LTP_CRC_MODE_PER_LANE
value|8
end_define

begin_comment
comment|/* 12/16-bit per lane LTP CRC mode */
end_comment

begin_comment
comment|/* Link Down / Neighbor Link Down Reason; indicated as follows: */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_NONE
value|0
end_define

begin_comment
comment|/* No specified reason */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_0
value|1
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_PKT_LEN
value|2
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_PKT_TOO_LONG
value|3
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_PKT_TOO_SHORT
value|4
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_SLID
value|5
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_DLID
value|6
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_L2
value|7
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_SC
value|8
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_8
value|9
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_MID_TAIL
value|10
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_10
value|11
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_PREEMPT_ERROR
value|12
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_PREEMPT_VL15
value|13
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_VL_MARKER
value|14
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_14
value|15
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_15
value|16
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_HEAD_DIST
value|17
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_TAIL_DIST
value|18
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_CTRL_DIST
value|19
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_CREDIT_ACK
value|20
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_UNSUPPORTED_VL_MARKER
value|21
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_PREEMPT
value|22
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_BAD_CONTROL_FLIT
value|23
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_EXCEED_MULTICAST_LIMIT
value|24
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_24
value|25
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_25
value|26
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_26
value|27
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_27
value|28
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_28
value|29
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_29
value|30
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_RCV_ERROR_30
value|31
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_EXCESSIVE_BUFFER_OVERRUN
value|32
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_UNKNOWN
value|33
end_define

begin_comment
comment|/* 34 -reserved */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_REBOOT
value|35
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_NEIGHBOR_UNKNOWN
value|36
end_define

begin_comment
comment|/* 37-38 reserved */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_FM_BOUNCE
value|39
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_SPEED_POLICY
value|40
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_WIDTH_POLICY
value|41
end_define

begin_comment
comment|/* 42-48 reserved */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_DISCONNECTED
value|49
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_LOCAL_MEDIA_NOT_INSTALLED
value|50
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_NOT_INSTALLED
value|51
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_CHASSIS_CONFIG
value|52
end_define

begin_comment
comment|/* 53 reserved */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_END_TO_END_NOT_INSTALLED
value|54
end_define

begin_comment
comment|/* 55 reserved */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_POWER_POLICY
value|56
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_LINKSPEED_POLICY
value|57
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_LINKWIDTH_POLICY
value|58
end_define

begin_comment
comment|/* 59 reserved */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_SWITCH_MGMT
value|60
end_define

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_SMA_DISABLED
value|61
end_define

begin_comment
comment|/* 62 reserved */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKDOWN_REASON_TRANSIENT
value|63
end_define

begin_comment
comment|/* 64-255 reserved */
end_comment

begin_comment
comment|/* OPA Link Init reason; indicated as follows: */
end_comment

begin_comment
comment|/* 3-7; 11-15 reserved; 8-15 cleared on Polling->LinkUp */
end_comment

begin_define
define|#
directive|define
name|OPA_LINKINIT_REASON_NOP
value|0
end_define

begin_define
define|#
directive|define
name|OPA_LINKINIT_REASON_LINKUP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|OPA_LINKINIT_REASON_FLAPPING
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|OPA_LINKINIT_REASON_CLEAR
value|(8<< 4)
end_define

begin_define
define|#
directive|define
name|OPA_LINKINIT_OUTSIDE_POLICY
value|(8<< 4)
end_define

begin_define
define|#
directive|define
name|OPA_LINKINIT_QUARANTINED
value|(9<< 4)
end_define

begin_define
define|#
directive|define
name|OPA_LINKINIT_INSUFIC_CAPABILITY
value|(10<< 4)
end_define

begin_define
define|#
directive|define
name|OPA_LINK_SPEED_NOP
value|0x0000
end_define

begin_comment
comment|/*  Reserved (1-5 Gbps) */
end_comment

begin_define
define|#
directive|define
name|OPA_LINK_SPEED_12_5G
value|0x0001
end_define

begin_comment
comment|/*  12.5 Gbps */
end_comment

begin_define
define|#
directive|define
name|OPA_LINK_SPEED_25G
value|0x0002
end_define

begin_comment
comment|/*  25.78125?  Gbps (EDR) */
end_comment

begin_define
define|#
directive|define
name|OPA_LINK_WIDTH_1X
value|0x0001
end_define

begin_define
define|#
directive|define
name|OPA_LINK_WIDTH_2X
value|0x0002
end_define

begin_define
define|#
directive|define
name|OPA_LINK_WIDTH_3X
value|0x0004
end_define

begin_define
define|#
directive|define
name|OPA_LINK_WIDTH_4X
value|0x0008
end_define

begin_define
define|#
directive|define
name|OPA_CAP_MASK3_IsSnoopSupported
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|OPA_CAP_MASK3_IsAsyncSC2VLSupported
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|OPA_CAP_MASK3_IsAddrRangeConfigSupported
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|OPA_CAP_MASK3_IsPassThroughSupported
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|OPA_CAP_MASK3_IsSharedSpaceSupported
value|(1<< 3)
end_define

begin_comment
comment|/* reserved (1<< 2) */
end_comment

begin_define
define|#
directive|define
name|OPA_CAP_MASK3_IsVLMarkerSupported
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|OPA_CAP_MASK3_IsVLrSupported
value|(1<< 0)
end_define

begin_comment
comment|/**  * new MTU values  */
end_comment

begin_enum
enum|enum
block|{
name|OPA_MTU_8192
init|=
literal|6
block|,
name|OPA_MTU_10240
init|=
literal|7
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|OPA_PORT_PHYS_CONF_DISCONNECTED
init|=
literal|0
block|,
name|OPA_PORT_PHYS_CONF_STANDARD
init|=
literal|1
block|,
name|OPA_PORT_PHYS_CONF_FIXED
init|=
literal|2
block|,
name|OPA_PORT_PHYS_CONF_VARIABLE
init|=
literal|3
block|,
name|OPA_PORT_PHYS_CONF_SI_PHOTO
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|port_info_field_masks
block|{
comment|/* vl.cap */
name|OPA_PI_MASK_VL_CAP
init|=
literal|0x1F
block|,
comment|/* port_states.ledenable_offlinereason */
name|OPA_PI_MASK_OFFLINE_REASON
init|=
literal|0x0F
block|,
name|OPA_PI_MASK_LED_ENABLE
init|=
literal|0x40
block|,
comment|/* port_states.unsleepstate_downdefstate */
name|OPA_PI_MASK_UNSLEEP_STATE
init|=
literal|0xF0
block|,
name|OPA_PI_MASK_DOWNDEF_STATE
init|=
literal|0x0F
block|,
comment|/* port_states.portphysstate_portstate */
name|OPA_PI_MASK_PORT_PHYSICAL_STATE
init|=
literal|0xF0
block|,
name|OPA_PI_MASK_PORT_STATE
init|=
literal|0x0F
block|,
comment|/* port_phys_conf */
name|OPA_PI_MASK_PORT_PHYSICAL_CONF
init|=
literal|0x0F
block|,
comment|/* collectivemask_multicastmask */
name|OPA_PI_MASK_COLLECT_MASK
init|=
literal|0x38
block|,
name|OPA_PI_MASK_MULTICAST_MASK
init|=
literal|0x07
block|,
comment|/* mkeyprotect_lmc */
name|OPA_PI_MASK_MKEY_PROT_BIT
init|=
literal|0xC0
block|,
name|OPA_PI_MASK_LMC
init|=
literal|0x0F
block|,
comment|/* smsl */
name|OPA_PI_MASK_SMSL
init|=
literal|0x1F
block|,
comment|/* partenforce_filterraw */
comment|/* Filter Raw In/Out bits 1 and 2 were removed */
name|OPA_PI_MASK_LINKINIT_REASON
init|=
literal|0xF0
block|,
name|OPA_PI_MASK_PARTITION_ENFORCE_IN
init|=
literal|0x08
block|,
name|OPA_PI_MASK_PARTITION_ENFORCE_OUT
init|=
literal|0x04
block|,
comment|/* operational_vls */
name|OPA_PI_MASK_OPERATIONAL_VL
init|=
literal|0x1F
block|,
comment|/* sa_qp */
name|OPA_PI_MASK_SA_QP
init|=
literal|0x00FFFFFF
block|,
comment|/* sm_trap_qp */
name|OPA_PI_MASK_SM_TRAP_QP
init|=
literal|0x00FFFFFF
block|,
comment|/* localphy_overrun_errors */
name|OPA_PI_MASK_LOCAL_PHY_ERRORS
init|=
literal|0xF0
block|,
name|OPA_PI_MASK_OVERRUN_ERRORS
init|=
literal|0x0F
block|,
comment|/* clientrereg_subnettimeout */
name|OPA_PI_MASK_CLIENT_REREGISTER
init|=
literal|0x80
block|,
name|OPA_PI_MASK_SUBNET_TIMEOUT
init|=
literal|0x1F
block|,
comment|/* port_link_mode */
name|OPA_PI_MASK_PORT_LINK_SUPPORTED
init|=
operator|(
literal|0x001F
operator|<<
literal|10
operator|)
block|,
name|OPA_PI_MASK_PORT_LINK_ENABLED
init|=
operator|(
literal|0x001F
operator|<<
literal|5
operator|)
block|,
name|OPA_PI_MASK_PORT_LINK_ACTIVE
init|=
operator|(
literal|0x001F
operator|<<
literal|0
operator|)
block|,
comment|/* port_link_crc_mode */
name|OPA_PI_MASK_PORT_LINK_CRC_SUPPORTED
init|=
literal|0x0F00
block|,
name|OPA_PI_MASK_PORT_LINK_CRC_ENABLED
init|=
literal|0x00F0
block|,
name|OPA_PI_MASK_PORT_LINK_CRC_ACTIVE
init|=
literal|0x000F
block|,
comment|/* port_mode */
name|OPA_PI_MASK_PORT_MODE_SECURITY_CHECK
init|=
literal|0x0001
block|,
name|OPA_PI_MASK_PORT_MODE_16B_TRAP_QUERY
init|=
literal|0x0002
block|,
name|OPA_PI_MASK_PORT_MODE_PKEY_CONVERT
init|=
literal|0x0004
block|,
name|OPA_PI_MASK_PORT_MODE_SC2SC_MAPPING
init|=
literal|0x0008
block|,
name|OPA_PI_MASK_PORT_MODE_VL_MARKER
init|=
literal|0x0010
block|,
name|OPA_PI_MASK_PORT_PASS_THROUGH
init|=
literal|0x0020
block|,
name|OPA_PI_MASK_PORT_ACTIVE_OPTOMIZE
init|=
literal|0x0040
block|,
comment|/* flit_control.interleave */
name|OPA_PI_MASK_INTERLEAVE_DIST_SUP
init|=
operator|(
literal|0x0003
operator|<<
literal|12
operator|)
block|,
name|OPA_PI_MASK_INTERLEAVE_DIST_ENABLE
init|=
operator|(
literal|0x0003
operator|<<
literal|10
operator|)
block|,
name|OPA_PI_MASK_INTERLEAVE_MAX_NEST_TX
init|=
operator|(
literal|0x001F
operator|<<
literal|5
operator|)
block|,
name|OPA_PI_MASK_INTERLEAVE_MAX_NEST_RX
init|=
operator|(
literal|0x001F
operator|<<
literal|0
operator|)
block|,
comment|/* port_error_action */
name|OPA_PI_MASK_EX_BUFFER_OVERRUN
init|=
literal|0x80000000
block|,
comment|/* 7 bits reserved */
name|OPA_PI_MASK_FM_CFG_ERR_EXCEED_MULTICAST_LIMIT
init|=
literal|0x00800000
block|,
name|OPA_PI_MASK_FM_CFG_BAD_CONTROL_FLIT
init|=
literal|0x00400000
block|,
name|OPA_PI_MASK_FM_CFG_BAD_PREEMPT
init|=
literal|0x00200000
block|,
name|OPA_PI_MASK_FM_CFG_UNSUPPORTED_VL_MARKER
init|=
literal|0x00100000
block|,
name|OPA_PI_MASK_FM_CFG_BAD_CRDT_ACK
init|=
literal|0x00080000
block|,
name|OPA_PI_MASK_FM_CFG_BAD_CTRL_DIST
init|=
literal|0x00040000
block|,
name|OPA_PI_MASK_FM_CFG_BAD_TAIL_DIST
init|=
literal|0x00020000
block|,
name|OPA_PI_MASK_FM_CFG_BAD_HEAD_DIST
init|=
literal|0x00010000
block|,
comment|/* 2 bits reserved */
name|OPA_PI_MASK_PORT_RCV_BAD_VL_MARKER
init|=
literal|0x00002000
block|,
name|OPA_PI_MASK_PORT_RCV_PREEMPT_VL15
init|=
literal|0x00001000
block|,
name|OPA_PI_MASK_PORT_RCV_PREEMPT_ERROR
init|=
literal|0x00000800
block|,
comment|/* 1 bit reserved */
name|OPA_PI_MASK_PORT_RCV_BAD_MidTail
init|=
literal|0x00000200
block|,
comment|/* 1 bit reserved */
name|OPA_PI_MASK_PORT_RCV_BAD_SC
init|=
literal|0x00000080
block|,
name|OPA_PI_MASK_PORT_RCV_BAD_L2
init|=
literal|0x00000040
block|,
name|OPA_PI_MASK_PORT_RCV_BAD_DLID
init|=
literal|0x00000020
block|,
name|OPA_PI_MASK_PORT_RCV_BAD_SLID
init|=
literal|0x00000010
block|,
name|OPA_PI_MASK_PORT_RCV_PKTLEN_TOOSHORT
init|=
literal|0x00000008
block|,
name|OPA_PI_MASK_PORT_RCV_PKTLEN_TOOLONG
init|=
literal|0x00000004
block|,
name|OPA_PI_MASK_PORT_RCV_BAD_PKTLEN
init|=
literal|0x00000002
block|,
name|OPA_PI_MASK_PORT_RCV_BAD_LT
init|=
literal|0x00000001
block|,
comment|/* pass_through.res_drctl */
name|OPA_PI_MASK_PASS_THROUGH_DR_CONTROL
init|=
literal|0x01
block|,
comment|/* buffer_units */
name|OPA_PI_MASK_BUF_UNIT_VL15_INIT
init|=
operator|(
literal|0x00000FFF
operator|<<
literal|11
operator|)
block|,
name|OPA_PI_MASK_BUF_UNIT_VL15_CREDIT_RATE
init|=
operator|(
literal|0x0000001F
operator|<<
literal|6
operator|)
block|,
name|OPA_PI_MASK_BUF_UNIT_CREDIT_ACK
init|=
operator|(
literal|0x00000003
operator|<<
literal|3
operator|)
block|,
name|OPA_PI_MASK_BUF_UNIT_BUF_ALLOC
init|=
operator|(
literal|0x00000003
operator|<<
literal|0
operator|)
block|,
comment|/* neigh_mtu.pvlx_to_mtu */
name|OPA_PI_MASK_NEIGH_MTU_PVL0
init|=
literal|0xF0
block|,
name|OPA_PI_MASK_NEIGH_MTU_PVL1
init|=
literal|0x0F
block|,
comment|/* neigh_mtu.vlstall_hoq_life */
name|OPA_PI_MASK_VL_STALL
init|=
operator|(
literal|0x03
operator|<<
literal|5
operator|)
block|,
name|OPA_PI_MASK_HOQ_LIFE
init|=
operator|(
literal|0x1F
operator|<<
literal|0
operator|)
block|,
comment|/* port_neigh_mode */
name|OPA_PI_MASK_NEIGH_MGMT_ALLOWED
init|=
operator|(
literal|0x01
operator|<<
literal|3
operator|)
block|,
name|OPA_PI_MASK_NEIGH_FW_AUTH_BYPASS
init|=
operator|(
literal|0x01
operator|<<
literal|2
operator|)
block|,
name|OPA_PI_MASK_NEIGH_NODE_TYPE
init|=
operator|(
literal|0x03
operator|<<
literal|0
operator|)
block|,
comment|/* resptime_value */
name|OPA_PI_MASK_RESPONSE_TIME_VALUE
init|=
literal|0x1F
block|,
comment|/* mtucap */
name|OPA_PI_MASK_MTU_CAP
init|=
literal|0x0F
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|opa_port_states
block|{
name|u8
name|reserved
decl_stmt|;
name|u8
name|ledenable_offlinereason
decl_stmt|;
comment|/* 1 res, 1 bit, 6 bits */
name|u8
name|reserved2
decl_stmt|;
name|u8
name|portphysstate_portstate
decl_stmt|;
comment|/* 4 bits, 4 bits */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|opa_port_state_info
block|{
name|struct
name|opa_port_states
name|port_states
decl_stmt|;
name|__be16
name|link_width_downgrade_tx_active
decl_stmt|;
name|__be16
name|link_width_downgrade_rx_active
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|opa_port_info
block|{
name|__be32
name|lid
decl_stmt|;
name|__be32
name|flow_control_mask
decl_stmt|;
struct|struct
block|{
name|u8
name|res
decl_stmt|;
comment|/* was inittype */
name|u8
name|cap
decl_stmt|;
comment|/* 3 res, 5 bits */
name|__be16
name|high_limit
decl_stmt|;
name|__be16
name|preempt_limit
decl_stmt|;
name|u8
name|arb_high_cap
decl_stmt|;
name|u8
name|arb_low_cap
decl_stmt|;
block|}
name|vl
struct|;
name|struct
name|opa_port_states
name|port_states
decl_stmt|;
name|u8
name|port_phys_conf
decl_stmt|;
comment|/* 4 res, 4 bits */
name|u8
name|collectivemask_multicastmask
decl_stmt|;
comment|/* 2 res, 3, 3 */
name|u8
name|mkeyprotect_lmc
decl_stmt|;
comment|/* 2 bits, 2 res, 4 bits */
name|u8
name|smsl
decl_stmt|;
comment|/* 3 res, 5 bits */
name|u8
name|partenforce_filterraw
decl_stmt|;
comment|/* bit fields */
name|u8
name|operational_vls
decl_stmt|;
comment|/* 3 res, 5 bits */
name|__be16
name|pkey_8b
decl_stmt|;
name|__be16
name|pkey_10b
decl_stmt|;
name|__be16
name|mkey_violations
decl_stmt|;
name|__be16
name|pkey_violations
decl_stmt|;
name|__be16
name|qkey_violations
decl_stmt|;
name|__be32
name|sm_trap_qp
decl_stmt|;
comment|/* 8 bits, 24 bits */
name|__be32
name|sa_qp
decl_stmt|;
comment|/* 8 bits, 24 bits */
name|u8
name|neigh_port_num
decl_stmt|;
name|u8
name|link_down_reason
decl_stmt|;
name|u8
name|neigh_link_down_reason
decl_stmt|;
name|u8
name|clientrereg_subnettimeout
decl_stmt|;
comment|/* 1 bit, 2 bits, 5 */
struct|struct
block|{
name|__be16
name|supported
decl_stmt|;
name|__be16
name|enabled
decl_stmt|;
name|__be16
name|active
decl_stmt|;
block|}
name|link_speed
struct|;
struct|struct
block|{
name|__be16
name|supported
decl_stmt|;
name|__be16
name|enabled
decl_stmt|;
name|__be16
name|active
decl_stmt|;
block|}
name|link_width
struct|;
struct|struct
block|{
name|__be16
name|supported
decl_stmt|;
name|__be16
name|enabled
decl_stmt|;
name|__be16
name|tx_active
decl_stmt|;
name|__be16
name|rx_active
decl_stmt|;
block|}
name|link_width_downgrade
struct|;
name|__be16
name|port_link_mode
decl_stmt|;
comment|/* 1 res, 5 bits, 5 bits, 5 bits */
name|__be16
name|port_ltp_crc_mode
decl_stmt|;
comment|/* 4 res, 4 bits, 4 bits, 4 bits */
name|__be16
name|port_mode
decl_stmt|;
comment|/* 9 res, bit fields */
struct|struct
block|{
name|__be16
name|supported
decl_stmt|;
name|__be16
name|enabled
decl_stmt|;
block|}
name|port_packet_format
struct|;
struct|struct
block|{
name|__be16
name|interleave
decl_stmt|;
comment|/* 2 res, 2,2,5,5 */
struct|struct
block|{
name|__be16
name|min_initial
decl_stmt|;
name|__be16
name|min_tail
decl_stmt|;
name|u8
name|large_pkt_limit
decl_stmt|;
name|u8
name|small_pkt_limit
decl_stmt|;
name|u8
name|max_small_pkt_limit
decl_stmt|;
name|u8
name|preemption_limit
decl_stmt|;
block|}
name|preemption
struct|;
block|}
name|flit_control
struct|;
name|__be32
name|reserved4
decl_stmt|;
name|__be32
name|port_error_action
decl_stmt|;
comment|/* bit field */
struct|struct
block|{
name|u8
name|egress_port
decl_stmt|;
name|u8
name|res_drctl
decl_stmt|;
comment|/* 7 res, 1 */
block|}
name|pass_through
struct|;
name|__be16
name|mkey_lease_period
decl_stmt|;
name|__be32
name|buffer_units
decl_stmt|;
comment|/* 9 res, 12, 5, 3, 3 */
name|__be32
name|reserved5
decl_stmt|;
name|__be32
name|sm_lid
decl_stmt|;
name|__be64
name|mkey
decl_stmt|;
name|__be64
name|subnet_prefix
decl_stmt|;
struct|struct
block|{
name|u8
name|pvlx_to_mtu
index|[
name|OPA_MAX_VLS
operator|/
literal|2
index|]
decl_stmt|;
comment|/* 4 bits, 4 bits */
block|}
name|neigh_mtu
struct|;
struct|struct
block|{
name|u8
name|vlstall_hoqlife
decl_stmt|;
comment|/* 3 bits, 5 bits */
block|}
name|xmit_q
index|[
name|OPA_MAX_VLS
index|]
struct|;
struct|struct
block|{
name|u8
name|addr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|ipaddr_ipv6
struct|;
struct|struct
block|{
name|u8
name|addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ipaddr_ipv4
struct|;
name|u32
name|reserved6
decl_stmt|;
name|u32
name|reserved7
decl_stmt|;
name|u32
name|reserved8
decl_stmt|;
name|__be64
name|neigh_node_guid
decl_stmt|;
name|__be32
name|ib_cap_mask
decl_stmt|;
name|__be16
name|reserved9
decl_stmt|;
comment|/* was ib_cap_mask2 */
name|__be16
name|opa_cap_mask
decl_stmt|;
name|__be32
name|reserved10
decl_stmt|;
comment|/* was link_roundtrip_latency */
name|__be16
name|overall_buffer_space
decl_stmt|;
name|__be16
name|reserved11
decl_stmt|;
comment|/* was max_credit_hint */
name|__be16
name|diag_code
decl_stmt|;
struct|struct
block|{
name|u8
name|buffer
decl_stmt|;
name|u8
name|wire
decl_stmt|;
block|}
name|replay_depth
struct|;
name|u8
name|port_neigh_mode
decl_stmt|;
name|u8
name|mtucap
decl_stmt|;
comment|/* 4 res, 4 bits */
name|u8
name|resptimevalue
decl_stmt|;
comment|/* 3 res, 5 bits */
name|u8
name|local_port_num
decl_stmt|;
name|u8
name|reserved12
decl_stmt|;
name|u8
name|reserved13
decl_stmt|;
comment|/* was guid_cap */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPA_PORT_INFO_H */
end_comment

end_unit

