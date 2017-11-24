begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009-2010 Chelsio, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_T4FW_RI_API_H_
end_ifndef

begin_define
define|#
directive|define
name|_T4FW_RI_API_H_
end_define

begin_include
include|#
directive|include
file|"t4fw_api.h"
end_include

begin_enum
enum|enum
name|fw_ri_wr_opcode
block|{
name|FW_RI_RDMA_WRITE
init|=
literal|0x0
block|,
comment|/* IETF RDMAP v1.0 ... */
name|FW_RI_READ_REQ
init|=
literal|0x1
block|,
name|FW_RI_READ_RESP
init|=
literal|0x2
block|,
name|FW_RI_SEND
init|=
literal|0x3
block|,
name|FW_RI_SEND_WITH_INV
init|=
literal|0x4
block|,
name|FW_RI_SEND_WITH_SE
init|=
literal|0x5
block|,
name|FW_RI_SEND_WITH_SE_INV
init|=
literal|0x6
block|,
name|FW_RI_TERMINATE
init|=
literal|0x7
block|,
name|FW_RI_RDMA_INIT
init|=
literal|0x8
block|,
comment|/* CHELSIO RI specific ... */
name|FW_RI_BIND_MW
init|=
literal|0x9
block|,
name|FW_RI_FAST_REGISTER
init|=
literal|0xa
block|,
name|FW_RI_LOCAL_INV
init|=
literal|0xb
block|,
name|FW_RI_QP_MODIFY
init|=
literal|0xc
block|,
name|FW_RI_BYPASS
init|=
literal|0xd
block|,
name|FW_RI_RECEIVE
init|=
literal|0xe
block|,
name|FW_RI_SGE_EC_CR_RETURN
init|=
literal|0xf
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_wr_flags
block|{
name|FW_RI_COMPLETION_FLAG
init|=
literal|0x01
block|,
name|FW_RI_NOTIFICATION_FLAG
init|=
literal|0x02
block|,
name|FW_RI_SOLICITED_EVENT_FLAG
init|=
literal|0x04
block|,
name|FW_RI_READ_FENCE_FLAG
init|=
literal|0x08
block|,
name|FW_RI_LOCAL_FENCE_FLAG
init|=
literal|0x10
block|,
name|FW_RI_RDMA_READ_INVALIDATE
init|=
literal|0x20
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_mpa_attrs
block|{
name|FW_RI_MPA_RX_MARKER_ENABLE
init|=
literal|0x01
block|,
name|FW_RI_MPA_TX_MARKER_ENABLE
init|=
literal|0x02
block|,
name|FW_RI_MPA_CRC_ENABLE
init|=
literal|0x04
block|,
name|FW_RI_MPA_IETF_ENABLE
init|=
literal|0x08
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_qp_caps
block|{
name|FW_RI_QP_RDMA_READ_ENABLE
init|=
literal|0x01
block|,
name|FW_RI_QP_RDMA_WRITE_ENABLE
init|=
literal|0x02
block|,
name|FW_RI_QP_BIND_ENABLE
init|=
literal|0x04
block|,
name|FW_RI_QP_FAST_REGISTER_ENABLE
init|=
literal|0x08
block|,
name|FW_RI_QP_STAG0_ENABLE
init|=
literal|0x10
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_addr_type
block|{
name|FW_RI_ZERO_BASED_TO
init|=
literal|0x00
block|,
name|FW_RI_VA_BASED_TO
init|=
literal|0x01
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_mem_perms
block|{
name|FW_RI_MEM_ACCESS_REM_WRITE
init|=
literal|0x01
block|,
name|FW_RI_MEM_ACCESS_REM_READ
init|=
literal|0x02
block|,
name|FW_RI_MEM_ACCESS_REM
init|=
literal|0x03
block|,
name|FW_RI_MEM_ACCESS_LOCAL_WRITE
init|=
literal|0x04
block|,
name|FW_RI_MEM_ACCESS_LOCAL_READ
init|=
literal|0x08
block|,
name|FW_RI_MEM_ACCESS_LOCAL
init|=
literal|0x0C
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_stag_type
block|{
name|FW_RI_STAG_NSMR
init|=
literal|0x00
block|,
name|FW_RI_STAG_SMR
init|=
literal|0x01
block|,
name|FW_RI_STAG_MW
init|=
literal|0x02
block|,
name|FW_RI_STAG_MW_RELAXED
init|=
literal|0x03
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_data_op
block|{
name|FW_RI_DATA_IMMD
init|=
literal|0x81
block|,
name|FW_RI_DATA_DSGL
init|=
literal|0x82
block|,
name|FW_RI_DATA_ISGL
init|=
literal|0x83
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_sgl_depth
block|{
name|FW_RI_SGL_DEPTH_MAX_SQ
init|=
literal|16
block|,
name|FW_RI_SGL_DEPTH_MAX_RQ
init|=
literal|4
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_dsge_pair
block|{
name|__be32
name|len
index|[
literal|2
index|]
decl_stmt|;
name|__be64
name|addr
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_dsgl
block|{
name|__u8
name|op
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__be16
name|nsge
decl_stmt|;
name|__be32
name|len0
decl_stmt|;
name|__be64
name|addr0
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_ri_dsge_pair
name|sge
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_sge
block|{
name|__be32
name|stag
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be64
name|to
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_isgl
block|{
name|__u8
name|op
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__be16
name|nsge
decl_stmt|;
name|__be32
name|r2
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_ri_sge
name|sge
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_immd
block|{
name|__u8
name|op
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__be16
name|r2
decl_stmt|;
name|__be32
name|immdlen
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|__u8
name|data
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_tpte
block|{
name|__be32
name|valid_to_pdid
decl_stmt|;
name|__be32
name|locread_to_qpid
decl_stmt|;
name|__be32
name|nosnoop_pbladdr
decl_stmt|;
name|__be32
name|len_lo
decl_stmt|;
name|__be32
name|va_hi
decl_stmt|;
name|__be32
name|va_lo_fbo
decl_stmt|;
name|__be32
name|dca_mwbcnt_pstag
decl_stmt|;
name|__be32
name|len_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RI_TPTE_VALID_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_VALID_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_VALID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_VALID_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_VALID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_VALID_S)& FW_RI_TPTE_VALID_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_VALID_F
value|FW_RI_TPTE_VALID_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGKEY_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGKEY_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGKEY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_STAGKEY_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGKEY_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_STAGKEY_S)& FW_RI_TPTE_STAGKEY_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGSTATE_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGSTATE_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGSTATE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_STAGSTATE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGSTATE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_STAGSTATE_S)& FW_RI_TPTE_STAGSTATE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGSTATE_F
value|FW_RI_TPTE_STAGSTATE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGTYPE_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGTYPE_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_STAGTYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_STAGTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_STAGTYPE_S)& FW_RI_TPTE_STAGTYPE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PDID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PDID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PDID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_PDID_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PDID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_PDID_S)& FW_RI_TPTE_PDID_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PERM_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PERM_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PERM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_PERM_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PERM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_PERM_S)& FW_RI_TPTE_PERM_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_REMINVDIS_S
value|27
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_REMINVDIS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_REMINVDIS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_REMINVDIS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_REMINVDIS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_REMINVDIS_S)& FW_RI_TPTE_REMINVDIS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_REMINVDIS_F
value|FW_RI_TPTE_REMINVDIS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_ADDRTYPE_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_ADDRTYPE_M
value|1
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_ADDRTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_ADDRTYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_ADDRTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_ADDRTYPE_S)& FW_RI_TPTE_ADDRTYPE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_ADDRTYPE_F
value|FW_RI_TPTE_ADDRTYPE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBINDEN_S
value|25
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBINDEN_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBINDEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_MWBINDEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBINDEN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_MWBINDEN_S)& FW_RI_TPTE_MWBINDEN_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBINDEN_F
value|FW_RI_TPTE_MWBINDEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PS_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PS_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_PS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_PS_S)& FW_RI_TPTE_PS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_QPID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_QPID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_QPID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_QPID_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_QPID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_QPID_S)& FW_RI_TPTE_QPID_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_NOSNOOP_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_NOSNOOP_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_NOSNOOP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_NOSNOOP_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_NOSNOOP_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_NOSNOOP_S)& FW_RI_TPTE_NOSNOOP_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_NOSNOOP_F
value|FW_RI_TPTE_NOSNOOP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PBLADDR_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PBLADDR_M
value|0x1fffffff
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PBLADDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_PBLADDR_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_PBLADDR_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_PBLADDR_S)& FW_RI_TPTE_PBLADDR_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_DCA_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_DCA_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_DCA_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_TPTE_DCA_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_DCA_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_DCA_S)& FW_RI_TPTE_DCA_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBCNT_PSTAG_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBCNT_PSTAG_M
value|0xffffff
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBCNT_PSTAT_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RI_TPTE_MWBCNT_PSTAG_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_TPTE_MWBCNT_PSTAG_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_TPTE_MWBCNT_PSTAG_S)& FW_RI_TPTE_MWBCNT_PSTAG_M)
end_define

begin_enum
enum|enum
name|fw_ri_res_type
block|{
name|FW_RI_RES_TYPE_SQ
block|,
name|FW_RI_RES_TYPE_RQ
block|,
name|FW_RI_RES_TYPE_CQ
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_res_op
block|{
name|FW_RI_RES_OP_WRITE
block|,
name|FW_RI_RES_OP_RESET
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_res
block|{
union|union
name|fw_ri_restype
block|{
struct|struct
name|fw_ri_res_sqrq
block|{
name|__u8
name|restype
decl_stmt|;
name|__u8
name|op
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be32
name|eqid
decl_stmt|;
name|__be32
name|r4
index|[
literal|2
index|]
decl_stmt|;
name|__be32
name|fetchszm_to_iqid
decl_stmt|;
name|__be32
name|dcaen_to_eqsize
decl_stmt|;
name|__be64
name|eqaddr
decl_stmt|;
block|}
name|sqrq
struct|;
struct|struct
name|fw_ri_res_cq
block|{
name|__u8
name|restype
decl_stmt|;
name|__u8
name|op
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be32
name|iqid
decl_stmt|;
name|__be32
name|r4
index|[
literal|2
index|]
decl_stmt|;
name|__be32
name|iqandst_to_iqandstindex
decl_stmt|;
name|__be16
name|iqdroprss_to_iqesize
decl_stmt|;
name|__be16
name|iqsize
decl_stmt|;
name|__be64
name|iqaddr
decl_stmt|;
name|__be32
name|iqns_iqro
decl_stmt|;
name|__be32
name|r6_lo
decl_stmt|;
name|__be64
name|r7
decl_stmt|;
block|}
name|cq
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_res_wr
block|{
name|__be32
name|op_nres
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_ri_res
name|res
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RI_RES_WR_NRES_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_NRES_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_NRES_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_NRES_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_NRES_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_NRES_S)& FW_RI_RES_WR_NRES_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHSZM_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHSZM_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHSZM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_FETCHSZM_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHSZM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_FETCHSZM_S)& FW_RI_RES_WR_FETCHSZM_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHSZM_F
value|FW_RI_RES_WR_FETCHSZM_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGNS_S
value|25
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGNS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_STATUSPGNS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGNS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_STATUSPGNS_S)& FW_RI_RES_WR_STATUSPGNS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGNS_F
value|FW_RI_RES_WR_STATUSPGNS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGRO_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGRO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_STATUSPGRO_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGRO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_STATUSPGRO_S)& FW_RI_RES_WR_STATUSPGRO_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_STATUSPGRO_F
value|FW_RI_RES_WR_STATUSPGRO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHNS_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHNS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_FETCHNS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHNS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_FETCHNS_S)& FW_RI_RES_WR_FETCHNS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHNS_F
value|FW_RI_RES_WR_FETCHNS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHRO_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHRO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_FETCHRO_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHRO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_FETCHRO_S)& FW_RI_RES_WR_FETCHRO_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FETCHRO_F
value|FW_RI_RES_WR_FETCHRO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_HOSTFCMODE_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_HOSTFCMODE_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_HOSTFCMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_HOSTFCMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_HOSTFCMODE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_HOSTFCMODE_S)& FW_RI_RES_WR_HOSTFCMODE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CPRIO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CPRIO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_CPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CPRIO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_CPRIO_S)& FW_RI_RES_WR_CPRIO_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CPRIO_F
value|FW_RI_RES_WR_CPRIO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_ONCHIP_S
value|18
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_ONCHIP_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_ONCHIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_ONCHIP_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_ONCHIP_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_ONCHIP_S)& FW_RI_RES_WR_ONCHIP_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_ONCHIP_F
value|FW_RI_RES_WR_ONCHIP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_PCIECHN_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_PCIECHN_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_PCIECHN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_PCIECHN_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_PCIECHN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_PCIECHN_S)& FW_RI_RES_WR_PCIECHN_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQID_M
value|0xffff
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQID_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQID_S)& FW_RI_RES_WR_IQID_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCAEN_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCAEN_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_DCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCAEN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_DCAEN_S)& FW_RI_RES_WR_DCAEN_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCAEN_F
value|FW_RI_RES_WR_DCAEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCACPU_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCACPU_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_DCACPU_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_DCACPU_S)& FW_RI_RES_WR_DCACPU_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMIN_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMIN_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMIN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_FBMIN_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMIN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_FBMIN_S)& FW_RI_RES_WR_FBMIN_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMAX_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMAX_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_FBMAX_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_FBMAX_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_FBMAX_S)& FW_RI_RES_WR_FBMAX_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESHO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESHO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESHO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_CIDXFTHRESHO_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESHO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_CIDXFTHRESHO_S)& FW_RI_RES_WR_CIDXFTHRESHO_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESHO_F
value|FW_RI_RES_WR_CIDXFTHRESHO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESH_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESH_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_CIDXFTHRESH_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_CIDXFTHRESH_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_CIDXFTHRESH_S)& FW_RI_RES_WR_CIDXFTHRESH_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_EQSIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_EQSIZE_M
value|0xffff
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_EQSIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_EQSIZE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_EQSIZE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_EQSIZE_S)& FW_RI_RES_WR_EQSIZE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDST_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDST_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDST_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQANDST_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDST_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQANDST_S)& FW_RI_RES_WR_IQANDST_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDST_F
value|FW_RI_RES_WR_IQANDST_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUS_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQANUS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQANUS_S)& FW_RI_RES_WR_IQANUS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUS_F
value|FW_RI_RES_WR_IQANUS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUD_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUD_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQANUD_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANUD_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQANUD_S)& FW_RI_RES_WR_IQANUD_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDSTINDEX_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDSTINDEX_M
value|0xfff
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDSTINDEX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQANDSTINDEX_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQANDSTINDEX_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQANDSTINDEX_S)& FW_RI_RES_WR_IQANDSTINDEX_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDROPRSS_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDROPRSS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDROPRSS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQDROPRSS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDROPRSS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQDROPRSS_S)& FW_RI_RES_WR_IQDROPRSS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDROPRSS_F
value|FW_RI_RES_WR_IQDROPRSS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQGTSMODE_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQGTSMODE_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQGTSMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQGTSMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQGTSMODE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQGTSMODE_S)& FW_RI_RES_WR_IQGTSMODE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQGTSMODE_F
value|FW_RI_RES_WR_IQGTSMODE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQPCIECH_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQPCIECH_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQPCIECH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQPCIECH_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQPCIECH_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQPCIECH_S)& FW_RI_RES_WR_IQPCIECH_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCAEN_S
value|11
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCAEN_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQDCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCAEN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQDCAEN_S)& FW_RI_RES_WR_IQDCAEN_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCAEN_F
value|FW_RI_RES_WR_IQDCAEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCACPU_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCACPU_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQDCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQDCACPU_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQDCACPU_S)& FW_RI_RES_WR_IQDCACPU_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQINTCNTTHRESH_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQINTCNTTHRESH_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQINTCNTTHRESH_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RI_RES_WR_IQINTCNTTHRESH_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQINTCNTTHRESH_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQINTCNTTHRESH_S)& FW_RI_RES_WR_IQINTCNTTHRESH_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQO_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQO_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQO_S)& FW_RI_RES_WR_IQO_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQO_F
value|FW_RI_RES_WR_IQO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQCPRIO_S
value|2
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQCPRIO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQCPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQCPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQCPRIO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQCPRIO_S)& FW_RI_RES_WR_IQCPRIO_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQCPRIO_F
value|FW_RI_RES_WR_IQCPRIO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQESIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQESIZE_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQESIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQESIZE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQESIZE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQESIZE_S)& FW_RI_RES_WR_IQESIZE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQNS_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQNS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQNS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQNS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQNS_S)& FW_RI_RES_WR_IQNS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQNS_F
value|FW_RI_RES_WR_IQNS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQRO_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQRO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_RES_WR_IQRO_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQRO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_RES_WR_IQRO_S)& FW_RI_RES_WR_IQRO_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_RES_WR_IQRO_F
value|FW_RI_RES_WR_IQRO_V(1U)
end_define

begin_struct
struct|struct
name|fw_ri_rdma_write_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be64
name|r2
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|stag_sink
decl_stmt|;
name|__be64
name|to_sink
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
union|union
block|{
name|struct
name|fw_ri_immd
name|immd_src
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|fw_ri_isgl
name|isgl_src
index|[
literal|0
index|]
decl_stmt|;
block|}
name|u
union|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_send_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be32
name|sendop_pkd
decl_stmt|;
name|__be32
name|stag_inv
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
union|union
block|{
name|struct
name|fw_ri_immd
name|immd_src
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|fw_ri_isgl
name|isgl_src
index|[
literal|0
index|]
decl_stmt|;
block|}
name|u
union|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RI_SEND_WR_SENDOP_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_SEND_WR_SENDOP_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_RI_SEND_WR_SENDOP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_SEND_WR_SENDOP_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_SEND_WR_SENDOP_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_SEND_WR_SENDOP_S)& FW_RI_SEND_WR_SENDOP_M)
end_define

begin_struct
struct|struct
name|fw_ri_rdma_read_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be64
name|r2
decl_stmt|;
name|__be32
name|stag_sink
decl_stmt|;
name|__be32
name|to_sink_hi
decl_stmt|;
name|__be32
name|to_sink_lo
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|stag_src
decl_stmt|;
name|__be32
name|to_src_hi
decl_stmt|;
name|__be32
name|to_src_lo
decl_stmt|;
name|__be32
name|r5
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_recv_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r2
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|struct
name|fw_ri_isgl
name|isgl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_bind_mw_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__u8
name|qpbinde_to_dcacpu
decl_stmt|;
name|__u8
name|pgsz_shift
decl_stmt|;
name|__u8
name|addr_type
decl_stmt|;
name|__u8
name|mem_perms
decl_stmt|;
name|__be32
name|stag_mr
decl_stmt|;
name|__be32
name|stag_mw
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be64
name|len_mw
decl_stmt|;
name|__be64
name|va_fbo
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_QPBINDE_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_QPBINDE_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_QPBINDE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_BIND_MW_WR_QPBINDE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_QPBINDE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_BIND_MW_WR_QPBINDE_S)& FW_RI_BIND_MW_WR_QPBINDE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_QPBINDE_F
value|FW_RI_BIND_MW_WR_QPBINDE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_NS_S
value|5
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_NS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_NS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_BIND_MW_WR_NS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_NS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_BIND_MW_WR_NS_S)& FW_RI_BIND_MW_WR_NS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_NS_F
value|FW_RI_BIND_MW_WR_NS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_DCACPU_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_DCACPU_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_BIND_MW_WR_DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_BIND_MW_WR_DCACPU_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_BIND_MW_WR_DCACPU_S)& FW_RI_BIND_MW_WR_DCACPU_M)
end_define

begin_struct
struct|struct
name|fw_ri_fr_nsmr_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__u8
name|qpbinde_to_dcacpu
decl_stmt|;
name|__u8
name|pgsz_shift
decl_stmt|;
name|__u8
name|addr_type
decl_stmt|;
name|__u8
name|mem_perms
decl_stmt|;
name|__be32
name|stag
decl_stmt|;
name|__be32
name|len_hi
decl_stmt|;
name|__be32
name|len_lo
decl_stmt|;
name|__be32
name|va_hi
decl_stmt|;
name|__be32
name|va_lo_fbo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_QPBINDE_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_QPBINDE_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_QPBINDE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_FR_NSMR_WR_QPBINDE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_QPBINDE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_FR_NSMR_WR_QPBINDE_S)& FW_RI_FR_NSMR_WR_QPBINDE_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_QPBINDE_F
value|FW_RI_FR_NSMR_WR_QPBINDE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_NS_S
value|5
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_NS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_NS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_FR_NSMR_WR_NS_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_NS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_FR_NSMR_WR_NS_S)& FW_RI_FR_NSMR_WR_NS_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_NS_F
value|FW_RI_FR_NSMR_WR_NS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_DCACPU_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_DCACPU_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_FR_NSMR_WR_DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_FR_NSMR_WR_DCACPU_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_FR_NSMR_WR_DCACPU_S)& FW_RI_FR_NSMR_WR_DCACPU_M)
end_define

begin_struct
struct|struct
name|fw_ri_inv_lstag_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be32
name|r2
decl_stmt|;
name|__be32
name|stag_inv
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fw_ri_type
block|{
name|FW_RI_TYPE_INIT
block|,
name|FW_RI_TYPE_FINI
block|,
name|FW_RI_TYPE_TERMINATE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_init_p2ptype
block|{
name|FW_RI_INIT_P2PTYPE_RDMA_WRITE
init|=
name|FW_RI_RDMA_WRITE
block|,
name|FW_RI_INIT_P2PTYPE_READ_REQ
init|=
name|FW_RI_READ_REQ
block|,
name|FW_RI_INIT_P2PTYPE_SEND
init|=
name|FW_RI_SEND
block|,
name|FW_RI_INIT_P2PTYPE_SEND_WITH_INV
init|=
name|FW_RI_SEND_WITH_INV
block|,
name|FW_RI_INIT_P2PTYPE_SEND_WITH_SE
init|=
name|FW_RI_SEND_WITH_SE
block|,
name|FW_RI_INIT_P2PTYPE_SEND_WITH_SE_INV
init|=
name|FW_RI_SEND_WITH_SE_INV
block|,
name|FW_RI_INIT_P2PTYPE_DISABLED
init|=
literal|0xf
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
union|union
name|fw_ri
block|{
struct|struct
name|fw_ri_init
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|mpareqbit_p2ptype
decl_stmt|;
name|__u8
name|r4
index|[
literal|2
index|]
decl_stmt|;
name|__u8
name|mpa_attrs
decl_stmt|;
name|__u8
name|qp_caps
decl_stmt|;
name|__be16
name|nrqe
decl_stmt|;
name|__be32
name|pdid
decl_stmt|;
name|__be32
name|qpid
decl_stmt|;
name|__be32
name|sq_eqid
decl_stmt|;
name|__be32
name|rq_eqid
decl_stmt|;
name|__be32
name|scqid
decl_stmt|;
name|__be32
name|rcqid
decl_stmt|;
name|__be32
name|ord_max
decl_stmt|;
name|__be32
name|ird_max
decl_stmt|;
name|__be32
name|iss
decl_stmt|;
name|__be32
name|irs
decl_stmt|;
name|__be32
name|hwrqsize
decl_stmt|;
name|__be32
name|hwrqaddr
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
union|union
name|fw_ri_init_p2p
block|{
name|struct
name|fw_ri_rdma_write_wr
name|write
decl_stmt|;
name|struct
name|fw_ri_rdma_read_wr
name|read
decl_stmt|;
name|struct
name|fw_ri_send_wr
name|send
decl_stmt|;
block|}
name|u
union|;
block|}
name|init
struct|;
struct|struct
name|fw_ri_fini
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|r3
index|[
literal|7
index|]
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
block|}
name|fini
struct|;
struct|struct
name|fw_ri_terminate
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|r3
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|immdlen
decl_stmt|;
name|__u8
name|termmsg
index|[
literal|40
index|]
decl_stmt|;
block|}
name|terminate
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RI_WR_MPAREQBIT_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_MPAREQBIT_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_MPAREQBIT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_WR_MPAREQBIT_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_MPAREQBIT_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_WR_MPAREQBIT_S)& FW_RI_WR_MPAREQBIT_M)
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_MPAREQBIT_F
value|FW_RI_WR_MPAREQBIT_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_P2PTYPE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_P2PTYPE_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_P2PTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RI_WR_P2PTYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_RI_WR_P2PTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RI_WR_P2PTYPE_S)& FW_RI_WR_P2PTYPE_M)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T4FW_RI_API_H_ */
end_comment

end_unit

