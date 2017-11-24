begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Mellanox Technologies Ltd.  All rights reserved.  * Copyright (c) 2004 Infinicon Corporation.  All rights reserved.  * Copyright (c) 2004 Intel Corporation.  All rights reserved.  * Copyright (c) 2004 Topspin Corporation.  All rights reserved.  * Copyright (c) 2004 Voltaire Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IB_SMI_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|IB_SMI_H
end_define

begin_include
include|#
directive|include
file|<rdma/ib_mad.h>
end_include

begin_define
define|#
directive|define
name|IB_SMP_DATA_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|IB_SMP_MAX_PATH_HOPS
value|64
end_define

begin_struct
struct|struct
name|ib_smp
block|{
name|u8
name|base_version
decl_stmt|;
name|u8
name|mgmt_class
decl_stmt|;
name|u8
name|class_version
decl_stmt|;
name|u8
name|method
decl_stmt|;
name|__be16
name|status
decl_stmt|;
name|u8
name|hop_ptr
decl_stmt|;
name|u8
name|hop_cnt
decl_stmt|;
name|__be64
name|tid
decl_stmt|;
name|__be16
name|attr_id
decl_stmt|;
name|__be16
name|resv
decl_stmt|;
name|__be32
name|attr_mod
decl_stmt|;
name|__be64
name|mkey
decl_stmt|;
name|__be16
name|dr_slid
decl_stmt|;
name|__be16
name|dr_dlid
decl_stmt|;
name|u8
name|reserved
index|[
literal|28
index|]
decl_stmt|;
name|u8
name|data
index|[
name|IB_SMP_DATA_SIZE
index|]
decl_stmt|;
name|u8
name|initial_path
index|[
name|IB_SMP_MAX_PATH_HOPS
index|]
decl_stmt|;
name|u8
name|return_path
index|[
name|IB_SMP_MAX_PATH_HOPS
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|IB_SMP_DIRECTION
value|cpu_to_be16(0x8000)
end_define

begin_comment
comment|/* Subnet management attributes */
end_comment

begin_define
define|#
directive|define
name|IB_SMP_ATTR_NOTICE
value|cpu_to_be16(0x0002)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_NODE_DESC
value|cpu_to_be16(0x0010)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_NODE_INFO
value|cpu_to_be16(0x0011)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_SWITCH_INFO
value|cpu_to_be16(0x0012)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_GUID_INFO
value|cpu_to_be16(0x0014)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_PORT_INFO
value|cpu_to_be16(0x0015)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_PKEY_TABLE
value|cpu_to_be16(0x0016)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_SL_TO_VL_TABLE
value|cpu_to_be16(0x0017)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_VL_ARB_TABLE
value|cpu_to_be16(0x0018)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_LINEAR_FORWARD_TABLE
value|cpu_to_be16(0x0019)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_RANDOM_FORWARD_TABLE
value|cpu_to_be16(0x001A)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_MCAST_FORWARD_TABLE
value|cpu_to_be16(0x001B)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_SM_INFO
value|cpu_to_be16(0x0020)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_VENDOR_DIAG
value|cpu_to_be16(0x0030)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_LED_INFO
value|cpu_to_be16(0x0031)
end_define

begin_define
define|#
directive|define
name|IB_SMP_ATTR_VENDOR_MASK
value|cpu_to_be16(0xFF00)
end_define

begin_struct
struct|struct
name|ib_port_info
block|{
name|__be64
name|mkey
decl_stmt|;
name|__be64
name|gid_prefix
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
name|__be16
name|sm_lid
decl_stmt|;
name|__be32
name|cap_mask
decl_stmt|;
name|__be16
name|diag_code
decl_stmt|;
name|__be16
name|mkey_lease_period
decl_stmt|;
name|u8
name|local_port_num
decl_stmt|;
name|u8
name|link_width_enabled
decl_stmt|;
name|u8
name|link_width_supported
decl_stmt|;
name|u8
name|link_width_active
decl_stmt|;
name|u8
name|linkspeed_portstate
decl_stmt|;
comment|/* 4 bits, 4 bits */
name|u8
name|portphysstate_linkdown
decl_stmt|;
comment|/* 4 bits, 4 bits */
name|u8
name|mkeyprot_resv_lmc
decl_stmt|;
comment|/* 2 bits, 3, 3 */
name|u8
name|linkspeedactive_enabled
decl_stmt|;
comment|/* 4 bits, 4 bits */
name|u8
name|neighbormtu_mastersmsl
decl_stmt|;
comment|/* 4 bits, 4 bits */
name|u8
name|vlcap_inittype
decl_stmt|;
comment|/* 4 bits, 4 bits */
name|u8
name|vl_high_limit
decl_stmt|;
name|u8
name|vl_arb_high_cap
decl_stmt|;
name|u8
name|vl_arb_low_cap
decl_stmt|;
name|u8
name|inittypereply_mtucap
decl_stmt|;
comment|/* 4 bits, 4 bits */
name|u8
name|vlstallcnt_hoqlife
decl_stmt|;
comment|/* 3 bits, 5 bits */
name|u8
name|operationalvl_pei_peo_fpi_fpo
decl_stmt|;
comment|/* 4 bits, 1, 1, 1, 1 */
name|__be16
name|mkey_violations
decl_stmt|;
name|__be16
name|pkey_violations
decl_stmt|;
name|__be16
name|qkey_violations
decl_stmt|;
name|u8
name|guid_cap
decl_stmt|;
name|u8
name|clientrereg_resv_subnetto
decl_stmt|;
comment|/* 1 bit, 2 bits, 5 */
name|u8
name|resv_resptimevalue
decl_stmt|;
comment|/* 3 bits, 5 bits */
name|u8
name|localphyerrors_overrunerrors
decl_stmt|;
comment|/* 4 bits, 4 bits */
name|__be16
name|max_credit_hint
decl_stmt|;
name|u8
name|resv
decl_stmt|;
name|u8
name|link_roundtrip_latency
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_node_info
block|{
name|u8
name|base_version
decl_stmt|;
name|u8
name|class_version
decl_stmt|;
name|u8
name|node_type
decl_stmt|;
name|u8
name|num_ports
decl_stmt|;
name|__be64
name|sys_guid
decl_stmt|;
name|__be64
name|node_guid
decl_stmt|;
name|__be64
name|port_guid
decl_stmt|;
name|__be16
name|partition_cap
decl_stmt|;
name|__be16
name|device_id
decl_stmt|;
name|__be32
name|revision
decl_stmt|;
name|u8
name|local_port_num
decl_stmt|;
name|u8
name|vendor_id
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ib_vl_weight_elem
block|{
name|u8
name|vl
decl_stmt|;
comment|/* IB: VL is low 4 bits, upper 4 bits reserved */
comment|/* OPA: VL is low 5 bits, upper 3 bits reserved */
name|u8
name|weight
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|u8
name|ib_get_smp_direction
parameter_list|(
specifier|const
name|struct
name|ib_smp
modifier|*
name|smp
parameter_list|)
block|{
return|return
operator|(
operator|(
name|smp
operator|->
name|status
operator|&
name|IB_SMP_DIRECTION
operator|)
operator|==
name|IB_SMP_DIRECTION
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * SM Trap/Notice numbers  */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_LLI_THRESH
value|cpu_to_be16(129)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_EBO_THRESH
value|cpu_to_be16(130)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_FLOW_UPDATE
value|cpu_to_be16(131)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_CAP_MASK_CHG
value|cpu_to_be16(144)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_SYS_GUID_CHG
value|cpu_to_be16(145)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_BAD_MKEY
value|cpu_to_be16(256)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_BAD_PKEY
value|cpu_to_be16(257)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_BAD_QKEY
value|cpu_to_be16(258)
end_define

begin_comment
comment|/*  * Other local changes flags (trap 144).  */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_LSE_CHG
value|0x04
end_define

begin_comment
comment|/* Link Speed Enable changed */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_LWE_CHG
value|0x02
end_define

begin_comment
comment|/* Link Width Enable changed */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_NODE_DESC_CHG
value|0x01
end_define

begin_comment
comment|/*  * M_Key volation flags in dr_trunc_hop (trap 256).  */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_DR_NOTICE
value|0x80
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TRAP_DR_TRUNC
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_SMI_H */
end_comment

end_unit

