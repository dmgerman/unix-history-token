begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Mellanox Technologies Ltd.  All rights reserved.  * Copyright (c) 2004 Infinicon Corporation.  All rights reserved.  * Copyright (c) 2004 Intel Corporation.  All rights reserved.  * Copyright (c) 2004 Topspin Corporation.  All rights reserved.  * Copyright (c) 2004-2006 Voltaire Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IB_MAD_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|IB_MAD_H
end_define

begin_include
include|#
directive|include
file|<linux/list.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_verbs.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_user_mad.h>
end_include

begin_comment
comment|/* Management base versions */
end_comment

begin_define
define|#
directive|define
name|IB_MGMT_BASE_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|OPA_MGMT_BASE_VERSION
value|0x80
end_define

begin_define
define|#
directive|define
name|OPA_SMP_CLASS_VERSION
value|0x80
end_define

begin_comment
comment|/* Management classes */
end_comment

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_SUBN_LID_ROUTED
value|0x01
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE
value|0x81
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_SUBN_ADM
value|0x03
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_PERF_MGMT
value|0x04
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_BM
value|0x05
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_DEVICE_MGMT
value|0x06
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_CM
value|0x07
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_SNMP
value|0x08
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_DEVICE_ADM
value|0x10
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_BOOT_MGMT
value|0x11
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_BIS
value|0x12
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_CONG_MGMT
value|0x21
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_VENDOR_RANGE2_START
value|0x30
end_define

begin_define
define|#
directive|define
name|IB_MGMT_CLASS_VENDOR_RANGE2_END
value|0x4F
end_define

begin_define
define|#
directive|define
name|IB_OPENIB_OUI
value|(0x001405)
end_define

begin_comment
comment|/* Management methods */
end_comment

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_GET
value|0x01
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_SET
value|0x02
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_GET_RESP
value|0x81
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_SEND
value|0x03
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_TRAP
value|0x05
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_REPORT
value|0x06
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_REPORT_RESP
value|0x86
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_TRAP_REPRESS
value|0x07
end_define

begin_define
define|#
directive|define
name|IB_MGMT_METHOD_RESP
value|0x80
end_define

begin_define
define|#
directive|define
name|IB_BM_ATTR_MOD_RESP
value|cpu_to_be32(1)
end_define

begin_define
define|#
directive|define
name|IB_MGMT_MAX_METHODS
value|128
end_define

begin_comment
comment|/* MAD Status field bit masks */
end_comment

begin_define
define|#
directive|define
name|IB_MGMT_MAD_STATUS_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|IB_MGMT_MAD_STATUS_BUSY
value|0x0001
end_define

begin_define
define|#
directive|define
name|IB_MGMT_MAD_STATUS_REDIRECT_REQD
value|0x0002
end_define

begin_define
define|#
directive|define
name|IB_MGMT_MAD_STATUS_BAD_VERSION
value|0x0004
end_define

begin_define
define|#
directive|define
name|IB_MGMT_MAD_STATUS_UNSUPPORTED_METHOD
value|0x0008
end_define

begin_define
define|#
directive|define
name|IB_MGMT_MAD_STATUS_UNSUPPORTED_METHOD_ATTRIB
value|0x000c
end_define

begin_define
define|#
directive|define
name|IB_MGMT_MAD_STATUS_INVALID_ATTRIB_VALUE
value|0x001c
end_define

begin_comment
comment|/* RMPP information */
end_comment

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_TYPE_DATA
value|1
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_TYPE_ACK
value|2
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_TYPE_STOP
value|3
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_TYPE_ABORT
value|4
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_FLAG_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_FLAG_FIRST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_FLAG_LAST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_NO_RESPTIME
value|0x1F
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_RESX
value|1
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_ABORT_MIN
value|118
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_T2L
value|118
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_BAD_LEN
value|119
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_BAD_SEG
value|120
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_BADT
value|121
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_W2S
value|122
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_S2B
value|123
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_BAD_STATUS
value|124
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_UNV
value|125
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_TMR
value|126
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_UNSPEC
value|127
end_define

begin_define
define|#
directive|define
name|IB_MGMT_RMPP_STATUS_ABORT_MAX
value|127
end_define

begin_define
define|#
directive|define
name|IB_QP0
value|0
end_define

begin_define
define|#
directive|define
name|IB_QP1
value|cpu_to_be32(1)
end_define

begin_define
define|#
directive|define
name|IB_QP1_QKEY
value|0x80010000
end_define

begin_define
define|#
directive|define
name|IB_QP_SET_QKEY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IB_DEFAULT_PKEY_PARTIAL
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|IB_DEFAULT_PKEY_FULL
value|0xFFFF
end_define

begin_comment
comment|/*  * Generic trap/notice types  */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_FATAL
value|0x80
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_URGENT
value|0x81
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_SECURITY
value|0x82
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_SM
value|0x83
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_TYPE_INFO
value|0x84
end_define

begin_comment
comment|/*  * Generic trap/notice producers  */
end_comment

begin_define
define|#
directive|define
name|IB_NOTICE_PROD_CA
value|cpu_to_be16(1)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_PROD_SWITCH
value|cpu_to_be16(2)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_PROD_ROUTER
value|cpu_to_be16(3)
end_define

begin_define
define|#
directive|define
name|IB_NOTICE_PROD_CLASS_MGR
value|cpu_to_be16(4)
end_define

begin_enum
enum|enum
block|{
name|IB_MGMT_MAD_HDR
init|=
literal|24
block|,
name|IB_MGMT_MAD_DATA
init|=
literal|232
block|,
name|IB_MGMT_RMPP_HDR
init|=
literal|36
block|,
name|IB_MGMT_RMPP_DATA
init|=
literal|220
block|,
name|IB_MGMT_VENDOR_HDR
init|=
literal|40
block|,
name|IB_MGMT_VENDOR_DATA
init|=
literal|216
block|,
name|IB_MGMT_SA_HDR
init|=
literal|56
block|,
name|IB_MGMT_SA_DATA
init|=
literal|200
block|,
name|IB_MGMT_DEVICE_HDR
init|=
literal|64
block|,
name|IB_MGMT_DEVICE_DATA
init|=
literal|192
block|,
name|IB_MGMT_MAD_SIZE
init|=
name|IB_MGMT_MAD_HDR
operator|+
name|IB_MGMT_MAD_DATA
block|,
name|OPA_MGMT_MAD_DATA
init|=
literal|2024
block|,
name|OPA_MGMT_RMPP_DATA
init|=
literal|2012
block|,
name|OPA_MGMT_MAD_SIZE
init|=
name|IB_MGMT_MAD_HDR
operator|+
name|OPA_MGMT_MAD_DATA
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ib_mad_hdr
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
name|__be16
name|class_specific
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_rmpp_hdr
block|{
name|u8
name|rmpp_version
decl_stmt|;
name|u8
name|rmpp_type
decl_stmt|;
name|u8
name|rmpp_rtime_flags
decl_stmt|;
name|u8
name|rmpp_status
decl_stmt|;
name|__be32
name|seg_num
decl_stmt|;
name|__be32
name|paylen_newwin
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|u64
name|__bitwise
name|ib_sa_comp_mask
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_SA_COMP_MASK
parameter_list|(
name|n
parameter_list|)
value|((__force ib_sa_comp_mask) cpu_to_be64(1ull<< (n)))
end_define

begin_comment
comment|/*  * ib_sa_hdr and ib_sa_mad structures must be packed because they have  * 64-bit fields that are only 32-bit aligned. 64-bit architectures will  * lay them out wrong otherwise.  (And unfortunately they are sent on  * the wire so we can't change the layout)  */
end_comment

begin_struct
struct|struct
name|ib_sa_hdr
block|{
name|__be64
name|sm_key
decl_stmt|;
name|__be16
name|attr_offset
decl_stmt|;
name|__be16
name|reserved
decl_stmt|;
name|ib_sa_comp_mask
name|comp_mask
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

begin_struct
struct|struct
name|ib_mad
block|{
name|struct
name|ib_mad_hdr
name|mad_hdr
decl_stmt|;
name|u8
name|data
index|[
name|IB_MGMT_MAD_DATA
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|opa_mad
block|{
name|struct
name|ib_mad_hdr
name|mad_hdr
decl_stmt|;
name|u8
name|data
index|[
name|OPA_MGMT_MAD_DATA
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_rmpp_mad
block|{
name|struct
name|ib_mad_hdr
name|mad_hdr
decl_stmt|;
name|struct
name|ib_rmpp_hdr
name|rmpp_hdr
decl_stmt|;
name|u8
name|data
index|[
name|IB_MGMT_RMPP_DATA
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|opa_rmpp_mad
block|{
name|struct
name|ib_mad_hdr
name|mad_hdr
decl_stmt|;
name|struct
name|ib_rmpp_hdr
name|rmpp_hdr
decl_stmt|;
name|u8
name|data
index|[
name|OPA_MGMT_RMPP_DATA
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_sa_mad
block|{
name|struct
name|ib_mad_hdr
name|mad_hdr
decl_stmt|;
name|struct
name|ib_rmpp_hdr
name|rmpp_hdr
decl_stmt|;
name|struct
name|ib_sa_hdr
name|sa_hdr
decl_stmt|;
name|u8
name|data
index|[
name|IB_MGMT_SA_DATA
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

begin_struct
struct|struct
name|ib_vendor_mad
block|{
name|struct
name|ib_mad_hdr
name|mad_hdr
decl_stmt|;
name|struct
name|ib_rmpp_hdr
name|rmpp_hdr
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
name|u8
name|data
index|[
name|IB_MGMT_VENDOR_DATA
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IB_MGMT_CLASSPORTINFO_ATTR_ID
value|cpu_to_be16(0x0001)
end_define

begin_define
define|#
directive|define
name|IB_CLASS_PORT_INFO_RESP_TIME_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|IB_CLASS_PORT_INFO_RESP_TIME_FIELD_SIZE
value|5
end_define

begin_struct
struct|struct
name|ib_class_port_info
block|{
name|u8
name|base_version
decl_stmt|;
name|u8
name|class_version
decl_stmt|;
name|__be16
name|capability_mask
decl_stmt|;
comment|/* 27 bits for cap_mask2, 5 bits for resp_time */
name|__be32
name|cap_mask2_resp_time
decl_stmt|;
name|u8
name|redirect_gid
index|[
literal|16
index|]
decl_stmt|;
name|__be32
name|redirect_tcslfl
decl_stmt|;
name|__be16
name|redirect_lid
decl_stmt|;
name|__be16
name|redirect_pkey
decl_stmt|;
name|__be32
name|redirect_qp
decl_stmt|;
name|__be32
name|redirect_qkey
decl_stmt|;
name|u8
name|trap_gid
index|[
literal|16
index|]
decl_stmt|;
name|__be32
name|trap_tcslfl
decl_stmt|;
name|__be16
name|trap_lid
decl_stmt|;
name|__be16
name|trap_pkey
decl_stmt|;
name|__be32
name|trap_hlqp
decl_stmt|;
name|__be32
name|trap_qkey
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_get_cpi_resp_time - Returns the resp_time value from  * cap_mask2_resp_time in ib_class_port_info.  * @cpi: A struct ib_class_port_info mad.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u8
name|ib_get_cpi_resp_time
parameter_list|(
name|struct
name|ib_class_port_info
modifier|*
name|cpi
parameter_list|)
block|{
return|return
call|(
name|u8
call|)
argument_list|(
name|be32_to_cpu
argument_list|(
name|cpi
operator|->
name|cap_mask2_resp_time
argument_list|)
operator|&
name|IB_CLASS_PORT_INFO_RESP_TIME_MASK
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * ib_set_cpi_resptime - Sets the response time in an  * ib_class_port_info mad.  * @cpi: A struct ib_class_port_info.  * @rtime: The response time to set.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ib_set_cpi_resp_time
parameter_list|(
name|struct
name|ib_class_port_info
modifier|*
name|cpi
parameter_list|,
name|u8
name|rtime
parameter_list|)
block|{
name|cpi
operator|->
name|cap_mask2_resp_time
operator|=
operator|(
name|cpi
operator|->
name|cap_mask2_resp_time
operator|&
name|cpu_to_be32
argument_list|(
operator|~
name|IB_CLASS_PORT_INFO_RESP_TIME_MASK
argument_list|)
operator|)
operator||
name|cpu_to_be32
argument_list|(
name|rtime
operator|&
name|IB_CLASS_PORT_INFO_RESP_TIME_MASK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * ib_get_cpi_capmask2 - Returns the capmask2 value from  * cap_mask2_resp_time in ib_class_port_info.  * @cpi: A struct ib_class_port_info mad.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u32
name|ib_get_cpi_capmask2
parameter_list|(
name|struct
name|ib_class_port_info
modifier|*
name|cpi
parameter_list|)
block|{
return|return
operator|(
name|be32_to_cpu
argument_list|(
name|cpi
operator|->
name|cap_mask2_resp_time
argument_list|)
operator|>>
name|IB_CLASS_PORT_INFO_RESP_TIME_FIELD_SIZE
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * ib_set_cpi_capmask2 - Sets the capmask2 in an  * ib_class_port_info mad.  * @cpi: A struct ib_class_port_info.  * @capmask2: The capmask2 to set.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ib_set_cpi_capmask2
parameter_list|(
name|struct
name|ib_class_port_info
modifier|*
name|cpi
parameter_list|,
name|u32
name|capmask2
parameter_list|)
block|{
name|cpi
operator|->
name|cap_mask2_resp_time
operator|=
operator|(
name|cpi
operator|->
name|cap_mask2_resp_time
operator|&
name|cpu_to_be32
argument_list|(
name|IB_CLASS_PORT_INFO_RESP_TIME_MASK
argument_list|)
operator|)
operator||
name|cpu_to_be32
argument_list|(
name|capmask2
operator|<<
name|IB_CLASS_PORT_INFO_RESP_TIME_FIELD_SIZE
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|ib_mad_notice_attr
block|{
name|u8
name|generic_type
decl_stmt|;
name|u8
name|prod_type_msb
decl_stmt|;
name|__be16
name|prod_type_lsb
decl_stmt|;
name|__be16
name|trap_num
decl_stmt|;
name|__be16
name|issuer_lid
decl_stmt|;
name|__be16
name|toggle_count
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u8
name|details
index|[
literal|54
index|]
decl_stmt|;
block|}
name|raw_data
struct|;
struct|struct
block|{
name|__be16
name|reserved
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
comment|/* where violation happened */
name|u8
name|port_num
decl_stmt|;
comment|/* where violation happened */
block|}
name|__packed
name|ntc_129_131
struct|;
struct|struct
block|{
name|__be16
name|reserved
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
comment|/* LID where change occurred */
name|u8
name|reserved2
decl_stmt|;
name|u8
name|local_changes
decl_stmt|;
comment|/* low bit - local changes */
name|__be32
name|new_cap_mask
decl_stmt|;
comment|/* new capability mask */
name|u8
name|reserved3
decl_stmt|;
name|u8
name|change_flags
decl_stmt|;
comment|/* low 3 bits only */
block|}
name|__packed
name|ntc_144
struct|;
struct|struct
block|{
name|__be16
name|reserved
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
comment|/* lid where sys guid changed */
name|__be16
name|reserved2
decl_stmt|;
name|__be64
name|new_sys_guid
decl_stmt|;
block|}
name|__packed
name|ntc_145
struct|;
struct|struct
block|{
name|__be16
name|reserved
decl_stmt|;
name|__be16
name|lid
decl_stmt|;
name|__be16
name|dr_slid
decl_stmt|;
name|u8
name|method
decl_stmt|;
name|u8
name|reserved2
decl_stmt|;
name|__be16
name|attr_id
decl_stmt|;
name|__be32
name|attr_mod
decl_stmt|;
name|__be64
name|mkey
decl_stmt|;
name|u8
name|reserved3
decl_stmt|;
name|u8
name|dr_trunc_hop
decl_stmt|;
name|u8
name|dr_rtn_path
index|[
literal|30
index|]
decl_stmt|;
block|}
name|__packed
name|ntc_256
struct|;
struct|struct
block|{
name|__be16
name|reserved
decl_stmt|;
name|__be16
name|lid1
decl_stmt|;
name|__be16
name|lid2
decl_stmt|;
name|__be32
name|key
decl_stmt|;
name|__be32
name|sl_qp1
decl_stmt|;
comment|/* SL: high 4 bits */
name|__be32
name|qp2
decl_stmt|;
comment|/* high 8 bits reserved */
name|union
name|ib_gid
name|gid1
decl_stmt|;
name|union
name|ib_gid
name|gid2
decl_stmt|;
block|}
name|__packed
name|ntc_257_258
struct|;
block|}
name|details
union|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_mad_send_buf - MAD data buffer and work request for sends.  * @next: A pointer used to chain together MADs for posting.  * @mad: References an allocated MAD data buffer for MADs that do not have  *   RMPP active.  For MADs using RMPP, references the common and management  *   class specific headers.  * @mad_agent: MAD agent that allocated the buffer.  * @ah: The address handle to use when sending the MAD.  * @context: User-controlled context fields.  * @hdr_len: Indicates the size of the data header of the MAD.  This length  *   includes the common MAD, RMPP, and class specific headers.  * @data_len: Indicates the total size of user-transferred data.  * @seg_count: The number of RMPP segments allocated for this send.  * @seg_size: Size of the data in each RMPP segment.  This does not include  *   class specific headers.  * @seg_rmpp_size: Size of each RMPP segment including the class specific  *   headers.  * @timeout_ms: Time to wait for a response.  * @retries: Number of times to retry a request for a response.  For MADs  *   using RMPP, this applies per window.  On completion, returns the number  *   of retries needed to complete the transfer.  *  * Users are responsible for initializing the MAD buffer itself, with the  * exception of any RMPP header.  Additional segment buffer space allocated  * beyond data_len is padding.  */
end_comment

begin_struct
struct|struct
name|ib_mad_send_buf
block|{
name|struct
name|ib_mad_send_buf
modifier|*
name|next
decl_stmt|;
name|void
modifier|*
name|mad
decl_stmt|;
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
decl_stmt|;
name|struct
name|ib_ah
modifier|*
name|ah
decl_stmt|;
name|void
modifier|*
name|context
index|[
literal|2
index|]
decl_stmt|;
name|int
name|hdr_len
decl_stmt|;
name|int
name|data_len
decl_stmt|;
name|int
name|seg_count
decl_stmt|;
name|int
name|seg_size
decl_stmt|;
name|int
name|seg_rmpp_size
decl_stmt|;
name|int
name|timeout_ms
decl_stmt|;
name|int
name|retries
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_response_mad - Returns if the specified MAD has been generated in  *   response to a sent request or trap.  */
end_comment

begin_function_decl
name|int
name|ib_response_mad
parameter_list|(
specifier|const
name|struct
name|ib_mad_hdr
modifier|*
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_get_rmpp_resptime - Returns the RMPP response time.  * @rmpp_hdr: An RMPP header.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u8
name|ib_get_rmpp_resptime
parameter_list|(
name|struct
name|ib_rmpp_hdr
modifier|*
name|rmpp_hdr
parameter_list|)
block|{
return|return
name|rmpp_hdr
operator|->
name|rmpp_rtime_flags
operator|>>
literal|3
return|;
block|}
end_function

begin_comment
comment|/**  * ib_get_rmpp_flags - Returns the RMPP flags.  * @rmpp_hdr: An RMPP header.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u8
name|ib_get_rmpp_flags
parameter_list|(
specifier|const
name|struct
name|ib_rmpp_hdr
modifier|*
name|rmpp_hdr
parameter_list|)
block|{
return|return
name|rmpp_hdr
operator|->
name|rmpp_rtime_flags
operator|&
literal|0x7
return|;
block|}
end_function

begin_comment
comment|/**  * ib_set_rmpp_resptime - Sets the response time in an RMPP header.  * @rmpp_hdr: An RMPP header.  * @rtime: The response time to set.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ib_set_rmpp_resptime
parameter_list|(
name|struct
name|ib_rmpp_hdr
modifier|*
name|rmpp_hdr
parameter_list|,
name|u8
name|rtime
parameter_list|)
block|{
name|rmpp_hdr
operator|->
name|rmpp_rtime_flags
operator|=
name|ib_get_rmpp_flags
argument_list|(
name|rmpp_hdr
argument_list|)
operator||
operator|(
name|rtime
operator|<<
literal|3
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * ib_set_rmpp_flags - Sets the flags in an RMPP header.  * @rmpp_hdr: An RMPP header.  * @flags: The flags to set.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ib_set_rmpp_flags
parameter_list|(
name|struct
name|ib_rmpp_hdr
modifier|*
name|rmpp_hdr
parameter_list|,
name|u8
name|flags
parameter_list|)
block|{
name|rmpp_hdr
operator|->
name|rmpp_rtime_flags
operator|=
operator|(
name|rmpp_hdr
operator|->
name|rmpp_rtime_flags
operator|&
literal|0xF8
operator|)
operator||
operator|(
name|flags
operator|&
literal|0x7
operator|)
expr_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|ib_mad_agent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ib_mad_send_wc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ib_mad_recv_wc
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * ib_mad_send_handler - callback handler for a sent MAD.  * @mad_agent: MAD agent that sent the MAD.  * @mad_send_wc: Send work completion information on the sent MAD.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ib_mad_send_handler
function_decl|)
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|,
name|struct
name|ib_mad_send_wc
modifier|*
name|mad_send_wc
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * ib_mad_snoop_handler - Callback handler for snooping sent MADs.  * @mad_agent: MAD agent that snooped the MAD.  * @send_buf: send MAD data buffer.  * @mad_send_wc: Work completion information on the sent MAD.  Valid  *   only for snooping that occurs on a send completion.  *  * Clients snooping MADs should not modify data referenced by the @send_buf  * or @mad_send_wc.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ib_mad_snoop_handler
function_decl|)
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|,
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
parameter_list|,
name|struct
name|ib_mad_send_wc
modifier|*
name|mad_send_wc
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * ib_mad_recv_handler - callback handler for a received MAD.  * @mad_agent: MAD agent requesting the received MAD.  * @send_buf: Send buffer if found, else NULL  * @mad_recv_wc: Received work completion information on the received MAD.  *  * MADs received in response to a send request operation will be handed to  * the user before the send operation completes.  All data buffers given  * to registered agents through this routine are owned by the receiving  * client, except for snooping agents.  Clients snooping MADs should not  * modify the data referenced by @mad_recv_wc.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ib_mad_recv_handler
function_decl|)
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|,
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
parameter_list|,
name|struct
name|ib_mad_recv_wc
modifier|*
name|mad_recv_wc
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * ib_mad_agent - Used to track MAD registration with the access layer.  * @device: Reference to device registration is on.  * @qp: Reference to QP used for sending and receiving MADs.  * @mr: Memory region for system memory usable for DMA.  * @recv_handler: Callback handler for a received MAD.  * @send_handler: Callback handler for a sent MAD.  * @snoop_handler: Callback handler for snooped sent MADs.  * @context: User-specified context associated with this registration.  * @hi_tid: Access layer assigned transaction ID for this client.  *   Unsolicited MADs sent by this client will have the upper 32-bits  *   of their TID set to this value.  * @flags: registration flags  * @port_num: Port number on which QP is registered  * @rmpp_version: If set, indicates the RMPP version used by this agent.  */
end_comment

begin_enum
enum|enum
block|{
name|IB_MAD_USER_RMPP
init|=
name|IB_USER_MAD_USER_RMPP
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ib_mad_agent
block|{
name|struct
name|ib_device
modifier|*
name|device
decl_stmt|;
name|struct
name|ib_qp
modifier|*
name|qp
decl_stmt|;
name|ib_mad_recv_handler
name|recv_handler
decl_stmt|;
name|ib_mad_send_handler
name|send_handler
decl_stmt|;
name|ib_mad_snoop_handler
name|snoop_handler
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
name|u32
name|hi_tid
decl_stmt|;
name|u32
name|flags
decl_stmt|;
name|u8
name|port_num
decl_stmt|;
name|u8
name|rmpp_version
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_mad_send_wc - MAD send completion information.  * @send_buf: Send MAD data buffer associated with the send MAD request.  * @status: Completion status.  * @vendor_err: Optional vendor error information returned with a failed  *   request.  */
end_comment

begin_struct
struct|struct
name|ib_mad_send_wc
block|{
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
decl_stmt|;
name|enum
name|ib_wc_status
name|status
decl_stmt|;
name|u32
name|vendor_err
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_mad_recv_buf - received MAD buffer information.  * @list: Reference to next data buffer for a received RMPP MAD.  * @grh: References a data buffer containing the global route header.  *   The data refereced by this buffer is only valid if the GRH is  *   valid.  * @mad: References the start of the received MAD.  */
end_comment

begin_struct
struct|struct
name|ib_mad_recv_buf
block|{
name|struct
name|list_head
name|list
decl_stmt|;
name|struct
name|ib_grh
modifier|*
name|grh
decl_stmt|;
union|union
block|{
name|struct
name|ib_mad
modifier|*
name|mad
decl_stmt|;
name|struct
name|opa_mad
modifier|*
name|opa_mad
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_mad_recv_wc - received MAD information.  * @wc: Completion information for the received data.  * @recv_buf: Specifies the location of the received data buffer(s).  * @rmpp_list: Specifies a list of RMPP reassembled received MAD buffers.  * @mad_len: The length of the received MAD, without duplicated headers.  * @mad_seg_size: The size of individual MAD segments  *  * For received response, the wr_id contains a pointer to the ib_mad_send_buf  *   for the corresponding send request.  */
end_comment

begin_struct
struct|struct
name|ib_mad_recv_wc
block|{
name|struct
name|ib_wc
modifier|*
name|wc
decl_stmt|;
name|struct
name|ib_mad_recv_buf
name|recv_buf
decl_stmt|;
name|struct
name|list_head
name|rmpp_list
decl_stmt|;
name|int
name|mad_len
decl_stmt|;
name|size_t
name|mad_seg_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_mad_reg_req - MAD registration request  * @mgmt_class: Indicates which management class of MADs should be receive  *   by the caller.  This field is only required if the user wishes to  *   receive unsolicited MADs, otherwise it should be 0.  * @mgmt_class_version: Indicates which version of MADs for the given  *   management class to receive.  * @oui: Indicates IEEE OUI when mgmt_class is a vendor class  *   in the range from 0x30 to 0x4f. Otherwise not used.  * @method_mask: The caller will receive unsolicited MADs for any method  *   where @method_mask = 1.  *  */
end_comment

begin_struct
struct|struct
name|ib_mad_reg_req
block|{
name|u8
name|mgmt_class
decl_stmt|;
name|u8
name|mgmt_class_version
decl_stmt|;
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
name|DECLARE_BITMAP
argument_list|(
name|method_mask
argument_list|,
name|IB_MGMT_MAX_METHODS
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ib_register_mad_agent - Register to send/receive MADs.  * @device: The device to register with.  * @port_num: The port on the specified device to use.  * @qp_type: Specifies which QP to access.  Must be either  *   IB_QPT_SMI or IB_QPT_GSI.  * @mad_reg_req: Specifies which unsolicited MADs should be received  *   by the caller.  This parameter may be NULL if the caller only  *   wishes to receive solicited responses.  * @rmpp_version: If set, indicates that the client will send  *   and receive MADs that contain the RMPP header for the given version.  *   If set to 0, indicates that RMPP is not used by this client.  * @send_handler: The completion callback routine invoked after a send  *   request has completed.  * @recv_handler: The completion callback routine invoked for a received  *   MAD.  * @context: User specified context associated with the registration.  * @registration_flags: Registration flags to set for this agent  */
end_comment

begin_function_decl
name|struct
name|ib_mad_agent
modifier|*
name|ib_register_mad_agent
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|enum
name|ib_qp_type
name|qp_type
parameter_list|,
name|struct
name|ib_mad_reg_req
modifier|*
name|mad_reg_req
parameter_list|,
name|u8
name|rmpp_version
parameter_list|,
name|ib_mad_send_handler
name|send_handler
parameter_list|,
name|ib_mad_recv_handler
name|recv_handler
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u32
name|registration_flags
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ib_mad_snoop_flags
block|{
comment|/*IB_MAD_SNOOP_POSTED_SENDS	   = 1,*/
comment|/*IB_MAD_SNOOP_RMPP_SENDS	   = (1<<1),*/
name|IB_MAD_SNOOP_SEND_COMPLETIONS
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/*IB_MAD_SNOOP_RMPP_SEND_COMPLETIONS = (1<<3),*/
name|IB_MAD_SNOOP_RECVS
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
comment|/*IB_MAD_SNOOP_RMPP_RECVS	   = (1<<5),*/
comment|/*IB_MAD_SNOOP_REDIRECTED_QPS	   = (1<<6)*/
block|}
enum|;
end_enum

begin_comment
comment|/**  * ib_register_mad_snoop - Register to snoop sent and received MADs.  * @device: The device to register with.  * @port_num: The port on the specified device to use.  * @qp_type: Specifies which QP traffic to snoop.  Must be either  *   IB_QPT_SMI or IB_QPT_GSI.  * @mad_snoop_flags: Specifies information where snooping occurs.  * @send_handler: The callback routine invoked for a snooped send.  * @recv_handler: The callback routine invoked for a snooped receive.  * @context: User specified context associated with the registration.  */
end_comment

begin_function_decl
name|struct
name|ib_mad_agent
modifier|*
name|ib_register_mad_snoop
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|u8
name|port_num
parameter_list|,
name|enum
name|ib_qp_type
name|qp_type
parameter_list|,
name|int
name|mad_snoop_flags
parameter_list|,
name|ib_mad_snoop_handler
name|snoop_handler
parameter_list|,
name|ib_mad_recv_handler
name|recv_handler
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_unregister_mad_agent - Unregisters a client from using MAD services.  * @mad_agent: Corresponding MAD registration request to deregister.  *  * After invoking this routine, MAD services are no longer usable by the  * client on the associated QP.  */
end_comment

begin_function_decl
name|int
name|ib_unregister_mad_agent
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_post_send_mad - Posts MAD(s) to the send queue of the QP associated  *   with the registered client.  * @send_buf: Specifies the information needed to send the MAD(s).  * @bad_send_buf: Specifies the MAD on which an error was encountered.  This  *   parameter is optional if only a single MAD is posted.  *  * Sent MADs are not guaranteed to complete in the order that they were posted.  *  * If the MAD requires RMPP, the data buffer should contain a single copy  * of the common MAD, RMPP, and class specific headers, followed by the class  * defined data.  If the class defined data would not divide evenly into  * RMPP segments, then space must be allocated at the end of the referenced  * buffer for any required padding.  To indicate the amount of class defined  * data being transferred, the paylen_newwin field in the RMPP header should  * be set to the size of the class specific header plus the amount of class  * defined data being transferred.  The paylen_newwin field should be  * specified in network-byte order.  */
end_comment

begin_function_decl
name|int
name|ib_post_send_mad
parameter_list|(
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
parameter_list|,
name|struct
name|ib_mad_send_buf
modifier|*
modifier|*
name|bad_send_buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_free_recv_mad - Returns data buffers used to receive a MAD.  * @mad_recv_wc: Work completion information for a received MAD.  *  * Clients receiving MADs through their ib_mad_recv_handler must call this  * routine to return the work completion buffers to the access layer.  */
end_comment

begin_function_decl
name|void
name|ib_free_recv_mad
parameter_list|(
name|struct
name|ib_mad_recv_wc
modifier|*
name|mad_recv_wc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_cancel_mad - Cancels an outstanding send MAD operation.  * @mad_agent: Specifies the registration associated with sent MAD.  * @send_buf: Indicates the MAD to cancel.  *  * MADs will be returned to the user through the corresponding  * ib_mad_send_handler.  */
end_comment

begin_function_decl
name|void
name|ib_cancel_mad
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|,
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_modify_mad - Modifies an outstanding send MAD operation.  * @mad_agent: Specifies the registration associated with sent MAD.  * @send_buf: Indicates the MAD to modify.  * @timeout_ms: New timeout value for sent MAD.  *  * This call will reset the timeout value for a sent MAD to the specified  * value.  */
end_comment

begin_function_decl
name|int
name|ib_modify_mad
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|,
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
parameter_list|,
name|u32
name|timeout_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_redirect_mad_qp - Registers a QP for MAD services.  * @qp: Reference to a QP that requires MAD services.  * @rmpp_version: If set, indicates that the client will send  *   and receive MADs that contain the RMPP header for the given version.  *   If set to 0, indicates that RMPP is not used by this client.  * @send_handler: The completion callback routine invoked after a send  *   request has completed.  * @recv_handler: The completion callback routine invoked for a received  *   MAD.  * @context: User specified context associated with the registration.  *  * Use of this call allows clients to use MAD services, such as RMPP,  * on user-owned QPs.  After calling this routine, users may send  * MADs on the specified QP by calling ib_mad_post_send.  */
end_comment

begin_function_decl
name|struct
name|ib_mad_agent
modifier|*
name|ib_redirect_mad_qp
parameter_list|(
name|struct
name|ib_qp
modifier|*
name|qp
parameter_list|,
name|u8
name|rmpp_version
parameter_list|,
name|ib_mad_send_handler
name|send_handler
parameter_list|,
name|ib_mad_recv_handler
name|recv_handler
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_process_mad_wc - Processes a work completion associated with a  *   MAD sent or received on a redirected QP.  * @mad_agent: Specifies the registered MAD service using the redirected QP.  * @wc: References a work completion associated with a sent or received  *   MAD segment.  *  * This routine is used to complete or continue processing on a MAD request.  * If the work completion is associated with a send operation, calling  * this routine is required to continue an RMPP transfer or to wait for a  * corresponding response, if it is a request.  If the work completion is  * associated with a receive operation, calling this routine is required to  * process an inbound or outbound RMPP transfer, or to match a response MAD  * with its corresponding request.  */
end_comment

begin_function_decl
name|int
name|ib_process_mad_wc
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|,
name|struct
name|ib_wc
modifier|*
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_create_send_mad - Allocate and initialize a data buffer and work request  *   for sending a MAD.  * @mad_agent: Specifies the registered MAD service to associate with the MAD.  * @remote_qpn: Specifies the QPN of the receiving node.  * @pkey_index: Specifies which PKey the MAD will be sent using.  This field  *   is valid only if the remote_qpn is QP 1.  * @rmpp_active: Indicates if the send will enable RMPP.  * @hdr_len: Indicates the size of the data header of the MAD.  This length  *   should include the common MAD header, RMPP header, plus any class  *   specific header.  * @data_len: Indicates the size of any user-transferred data.  The call will  *   automatically adjust the allocated buffer size to account for any  *   additional padding that may be necessary.  * @gfp_mask: GFP mask used for the memory allocation.  * @base_version: Base Version of this MAD  *  * This routine allocates a MAD for sending.  The returned MAD send buffer  * will reference a data buffer usable for sending a MAD, along  * with an initialized work request structure.  Users may modify the returned  * MAD data buffer before posting the send.  *  * The returned MAD header, class specific headers, and any padding will be  * cleared.  Users are responsible for initializing the common MAD header,  * any class specific header, and MAD data area.  * If @rmpp_active is set, the RMPP header will be initialized for sending.  */
end_comment

begin_function_decl
name|struct
name|ib_mad_send_buf
modifier|*
name|ib_create_send_mad
parameter_list|(
name|struct
name|ib_mad_agent
modifier|*
name|mad_agent
parameter_list|,
name|u32
name|remote_qpn
parameter_list|,
name|u16
name|pkey_index
parameter_list|,
name|int
name|rmpp_active
parameter_list|,
name|int
name|hdr_len
parameter_list|,
name|int
name|data_len
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|,
name|u8
name|base_version
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_is_mad_class_rmpp - returns whether given management class  * supports RMPP.  * @mgmt_class: management class  *  * This routine returns whether the management class supports RMPP.  */
end_comment

begin_function_decl
name|int
name|ib_is_mad_class_rmpp
parameter_list|(
name|u8
name|mgmt_class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_get_mad_data_offset - returns the data offset for a given  * management class.  * @mgmt_class: management class  *  * This routine returns the data offset in the MAD for the management  * class requested.  */
end_comment

begin_function_decl
name|int
name|ib_get_mad_data_offset
parameter_list|(
name|u8
name|mgmt_class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_get_rmpp_segment - returns the data buffer for a given RMPP segment.  * @send_buf: Previously allocated send data buffer.  * @seg_num: number of segment to return  *  * This routine returns a pointer to the data buffer of an RMPP MAD.  * Users must provide synchronization to @send_buf around this call.  */
end_comment

begin_function_decl
name|void
modifier|*
name|ib_get_rmpp_segment
parameter_list|(
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
parameter_list|,
name|int
name|seg_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_free_send_mad - Returns data buffers used to send a MAD.  * @send_buf: Previously allocated send data buffer.  */
end_comment

begin_function_decl
name|void
name|ib_free_send_mad
parameter_list|(
name|struct
name|ib_mad_send_buf
modifier|*
name|send_buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ib_mad_kernel_rmpp_agent - Returns if the agent is performing RMPP.  * @agent: the agent in question  * @return: true if agent is performing rmpp, false otherwise.  */
end_comment

begin_function_decl
name|int
name|ib_mad_kernel_rmpp_agent
parameter_list|(
specifier|const
name|struct
name|ib_mad_agent
modifier|*
name|agent
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_MAD_H */
end_comment

end_unit

