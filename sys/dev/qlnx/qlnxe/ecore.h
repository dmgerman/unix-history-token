begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_H
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_H
end_define

begin_include
include|#
directive|include
file|"ecore_hsi_common.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_debug_tools.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_init_func.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_init_tool.h"
end_include

begin_include
include|#
directive|include
file|"ecore_proto_if.h"
end_include

begin_include
include|#
directive|include
file|"mcp_public.h"
end_include

begin_define
define|#
directive|define
name|ECORE_MAJOR_VERSION
value|8
end_define

begin_define
define|#
directive|define
name|ECORE_MINOR_VERSION
value|18
end_define

begin_define
define|#
directive|define
name|ECORE_REVISION_VERSION
value|13
end_define

begin_define
define|#
directive|define
name|ECORE_ENGINEERING_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|ECORE_VERSION
define|\
value|((ECORE_MAJOR_VERSION<< 24) | (ECORE_MINOR_VERSION<< 16) |	\ 	 (ECORE_REVISION_VERSION<< 8) | ECORE_ENGINEERING_VERSION)
end_define

begin_define
define|#
directive|define
name|STORM_FW_VERSION
define|\
value|((FW_MAJOR_VERSION<< 24) | (FW_MINOR_VERSION<< 16) |	\ 	 (FW_REVISION_VERSION<< 8) | FW_ENGINEERING_VERSION)
end_define

begin_define
define|#
directive|define
name|MAX_HWFNS_PER_DEVICE
value|2
end_define

begin_define
define|#
directive|define
name|NAME_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ARRAY_DECL
value|static const
end_define

begin_define
define|#
directive|define
name|ECORE_WFQ_UNIT
value|100
end_define

begin_comment
comment|/* Constants */
end_comment

begin_define
define|#
directive|define
name|ECORE_WID_SIZE
value|(1024)
end_define

begin_comment
comment|/* Configurable */
end_comment

begin_define
define|#
directive|define
name|ECORE_PF_DEMS_SIZE
value|(4)
end_define

begin_comment
comment|/* cau states */
end_comment

begin_enum
enum|enum
name|ecore_coalescing_mode
block|{
name|ECORE_COAL_MODE_DISABLE
block|,
name|ECORE_COAL_MODE_ENABLE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ecore_nvm_cmd
block|{
name|ECORE_PUT_FILE_BEGIN
init|=
name|DRV_MSG_CODE_NVM_PUT_FILE_BEGIN
block|,
name|ECORE_PUT_FILE_DATA
init|=
name|DRV_MSG_CODE_NVM_PUT_FILE_DATA
block|,
name|ECORE_NVM_READ_NVRAM
init|=
name|DRV_MSG_CODE_NVM_READ_NVRAM
block|,
name|ECORE_NVM_WRITE_NVRAM
init|=
name|DRV_MSG_CODE_NVM_WRITE_NVRAM
block|,
name|ECORE_NVM_DEL_FILE
init|=
name|DRV_MSG_CODE_NVM_DEL_FILE
block|,
name|ECORE_EXT_PHY_FW_UPGRADE
init|=
name|DRV_MSG_CODE_EXT_PHY_FW_UPGRADE
block|,
name|ECORE_NVM_SET_SECURE_MODE
init|=
name|DRV_MSG_CODE_SET_SECURE_MODE
block|,
name|ECORE_PHY_RAW_READ
init|=
name|DRV_MSG_CODE_PHY_RAW_READ
block|,
name|ECORE_PHY_RAW_WRITE
init|=
name|DRV_MSG_CODE_PHY_RAW_WRITE
block|,
name|ECORE_PHY_CORE_READ
init|=
name|DRV_MSG_CODE_PHY_CORE_READ
block|,
name|ECORE_PHY_CORE_WRITE
init|=
name|DRV_MSG_CODE_PHY_CORE_WRITE
block|,
name|ECORE_GET_MCP_NVM_RESP
init|=
literal|0xFFFFFF00
block|}
enum|;
end_enum

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CONFIG_ECORE_L2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_ECORE_ROCE
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|CONFIG_ECORE_FCOE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_ECORE_ISCSI
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONFIG_ECORE_L2
end_define

begin_define
define|#
directive|define
name|CONFIG_ECORE_SRIOV
end_define

begin_define
define|#
directive|define
name|CONFIG_ECORE_ROCE
end_define

begin_define
define|#
directive|define
name|CONFIG_ECORE_IWARP
end_define

begin_define
define|#
directive|define
name|CONFIG_ECORE_FCOE
end_define

begin_define
define|#
directive|define
name|CONFIG_ECORE_ISCSI
end_define

begin_define
define|#
directive|define
name|CONFIG_ECORE_LL2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* helpers */
end_comment

begin_define
define|#
directive|define
name|MASK_FIELD
parameter_list|(
name|_name
parameter_list|,
name|_value
parameter_list|)
define|\
value|((_value)&= (_name##_MASK))
end_define

begin_define
define|#
directive|define
name|FIELD_VALUE
parameter_list|(
name|_name
parameter_list|,
name|_value
parameter_list|)
define|\
value|((_value& _name##_MASK)<< _name##_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_FIELD
parameter_list|(
name|value
parameter_list|,
name|name
parameter_list|,
name|flag
parameter_list|)
define|\
value|do {									\ 	(value)&= ~(name##_MASK<< name##_SHIFT);			\ 	(value) |= ((((u64)flag)& (u64)name##_MASK)<< (name##_SHIFT));\ } while (0)
end_define

begin_define
define|#
directive|define
name|GET_FIELD
parameter_list|(
name|value
parameter_list|,
name|name
parameter_list|)
define|\
value|(((value)>> (name##_SHIFT))& name##_MASK)
end_define

begin_define
define|#
directive|define
name|ECORE_MFW_GET_FIELD
parameter_list|(
name|name
parameter_list|,
name|field
parameter_list|)
define|\
value|(((name)& (field ## _MASK))>> (field ## _SHIFT))
end_define

begin_define
define|#
directive|define
name|ECORE_MFW_SET_FIELD
parameter_list|(
name|name
parameter_list|,
name|field
parameter_list|,
name|value
parameter_list|)
define|\
value|do {									\ 	(name)&= ~((field ## _MASK)<< (field ## _SHIFT));		\ 	(name) |= (((value)<< (field ## _SHIFT))& (field ## _MASK));	\ } while (0)
end_define

begin_function
specifier|static
name|OSAL_INLINE
name|u32
name|DB_ADDR
parameter_list|(
name|u32
name|cid
parameter_list|,
name|u32
name|DEMS
parameter_list|)
block|{
name|u32
name|db_addr
init|=
name|FIELD_VALUE
argument_list|(
name|DB_LEGACY_ADDR_DEMS
argument_list|,
name|DEMS
argument_list|)
operator||
operator|(
name|cid
operator|*
name|ECORE_PF_DEMS_SIZE
operator|)
decl_stmt|;
return|return
name|db_addr
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|u32
name|DB_ADDR_VF
parameter_list|(
name|u32
name|cid
parameter_list|,
name|u32
name|DEMS
parameter_list|)
block|{
name|u32
name|db_addr
init|=
name|FIELD_VALUE
argument_list|(
name|DB_LEGACY_ADDR_DEMS
argument_list|,
name|DEMS
argument_list|)
operator||
name|FIELD_VALUE
argument_list|(
name|DB_LEGACY_ADDR_ICID
argument_list|,
name|cid
argument_list|)
decl_stmt|;
return|return
name|db_addr
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ALIGNED_TYPE_SIZE
parameter_list|(
name|type_name
parameter_list|,
name|p_hwfn
parameter_list|)
define|\
value|((sizeof(type_name) + (u32)(1<<(p_hwfn->p_dev->cache_shift))-1)& \ 	 ~((1<<(p_hwfn->p_dev->cache_shift))-1))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|U64_HI
end_ifndef

begin_define
define|#
directive|define
name|U64_HI
parameter_list|(
name|val
parameter_list|)
value|((u32)(((u64)(val))>> 32))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|U64_LO
end_ifndef

begin_define
define|#
directive|define
name|U64_LO
parameter_list|(
name|val
parameter_list|)
value|((u32)(((u64)(val))& 0xffffffff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UEFI
end_ifndef

begin_comment
comment|/* Debug print definitions */
end_comment

begin_define
define|#
directive|define
name|DP_ERR
parameter_list|(
name|p_dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {							\ 	PRINT_ERR((p_dev)->dp_ctx, "[%s:%d(%s)]" fmt,	\ 		  __func__, __LINE__,			\ 		  (p_dev)->name ? (p_dev)->name : "",	\ 		  ##__VA_ARGS__);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DP_NOTICE
parameter_list|(
name|p_dev
parameter_list|,
name|is_assert
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {									\ 	if (OSAL_UNLIKELY((p_dev)->dp_level<= ECORE_LEVEL_NOTICE)) {	\ 		PRINT((p_dev)->dp_ctx, "[%s:%d(%s)]" fmt,		\ 		      __func__, __LINE__,				\ 		      (p_dev)->name ? (p_dev)->name : "",		\ 		      ##__VA_ARGS__);					\ 		OSAL_ASSERT(!is_assert);				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|DP_INFO
parameter_list|(
name|p_dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								      \ 	if (OSAL_UNLIKELY((p_dev)->dp_level<= ECORE_LEVEL_INFO)) {   \ 		PRINT((p_dev)->dp_ctx, "[%s:%d(%s)]" fmt,	      \ 		      __func__, __LINE__,			      \ 		      (p_dev)->name ? (p_dev)->name : "",	      \ 		      ##__VA_ARGS__);				      \ 	}							      \ } while (0)
end_define

begin_define
define|#
directive|define
name|DP_VERBOSE
parameter_list|(
name|p_dev
parameter_list|,
name|module
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {									\ 	if (OSAL_UNLIKELY(((p_dev)->dp_level<= ECORE_LEVEL_VERBOSE)&&	\ 	    ((p_dev)->dp_module& module))) {				\ 		PRINT((p_dev)->dp_ctx, "[%s:%d(%s)]" fmt,		\ 		      __func__, __LINE__,				\ 		      (p_dev)->name ? (p_dev)->name : "",		\ 		      ##__VA_ARGS__);					\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|DP_LEVEL
block|{
name|ECORE_LEVEL_VERBOSE
init|=
literal|0x0
block|,
name|ECORE_LEVEL_INFO
init|=
literal|0x1
block|,
name|ECORE_LEVEL_NOTICE
init|=
literal|0x2
block|,
name|ECORE_LEVEL_ERR
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|ECORE_LOG_LEVEL_SHIFT
value|(30)
end_define

begin_define
define|#
directive|define
name|ECORE_LOG_VERBOSE_MASK
value|(0x3fffffff)
end_define

begin_define
define|#
directive|define
name|ECORE_LOG_INFO_MASK
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|ECORE_LOG_NOTICE_MASK
value|(0x80000000)
end_define

begin_enum
enum|enum
name|DP_MODULE
block|{
name|ECORE_MSG_DRV
init|=
literal|0x0001
block|,
name|ECORE_MSG_PROBE
init|=
literal|0x0002
block|,
name|ECORE_MSG_LINK
init|=
literal|0x0004
block|,
name|ECORE_MSG_TIMER
init|=
literal|0x0008
block|,
name|ECORE_MSG_IFDOWN
init|=
literal|0x0010
block|,
name|ECORE_MSG_IFUP
init|=
literal|0x0020
block|,
name|ECORE_MSG_RX_ERR
init|=
literal|0x0040
block|,
name|ECORE_MSG_TX_ERR
init|=
literal|0x0080
block|,
name|ECORE_MSG_TX_QUEUED
init|=
literal|0x0100
block|,
name|ECORE_MSG_INTR
init|=
literal|0x0200
block|,
name|ECORE_MSG_TX_DONE
init|=
literal|0x0400
block|,
name|ECORE_MSG_RX_STATUS
init|=
literal|0x0800
block|,
name|ECORE_MSG_PKTDATA
init|=
literal|0x1000
block|,
name|ECORE_MSG_HW
init|=
literal|0x2000
block|,
name|ECORE_MSG_WOL
init|=
literal|0x4000
block|,
name|ECORE_MSG_SPQ
init|=
literal|0x10000
block|,
name|ECORE_MSG_STATS
init|=
literal|0x20000
block|,
name|ECORE_MSG_DCB
init|=
literal|0x40000
block|,
name|ECORE_MSG_IOV
init|=
literal|0x80000
block|,
name|ECORE_MSG_SP
init|=
literal|0x100000
block|,
name|ECORE_MSG_STORAGE
init|=
literal|0x200000
block|,
name|ECORE_MSG_OOO
init|=
literal|0x200000
block|,
name|ECORE_MSG_CXT
init|=
literal|0x800000
block|,
name|ECORE_MSG_LL2
init|=
literal|0x1000000
block|,
name|ECORE_MSG_ILT
init|=
literal|0x2000000
block|,
name|ECORE_MSG_RDMA
init|=
literal|0x4000000
block|,
name|ECORE_MSG_DEBUG
init|=
literal|0x8000000
block|,
comment|/* to be added...up to 0x8000000 */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|for_each_hwfn
parameter_list|(
name|p_dev
parameter_list|,
name|i
parameter_list|)
value|for (i = 0; i< p_dev->num_hwfns; i++)
end_define

begin_define
define|#
directive|define
name|D_TRINE
parameter_list|(
name|val
parameter_list|,
name|cond1
parameter_list|,
name|cond2
parameter_list|,
name|true1
parameter_list|,
name|true2
parameter_list|,
name|def
parameter_list|)
define|\
value|(val == (cond1) ? true1 : \ 	 (val == (cond2) ? true2 : def))
end_define

begin_comment
comment|/* forward */
end_comment

begin_struct_decl
struct_decl|struct
name|ecore_ptt_pool
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_spq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_sb_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_sb_attn_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_cxt_mngr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_dma_mem
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_sb_sp_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_ll2_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_l2_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_igu_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_mcp_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ecore_dcbx_info
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ecore_rt_data
block|{
name|u32
modifier|*
name|init_val
decl_stmt|;
name|bool
modifier|*
name|b_valid
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ecore_tunn_mode
block|{
name|ECORE_MODE_L2GENEVE_TUNN
block|,
name|ECORE_MODE_IPGENEVE_TUNN
block|,
name|ECORE_MODE_L2GRE_TUNN
block|,
name|ECORE_MODE_IPGRE_TUNN
block|,
name|ECORE_MODE_VXLAN_TUNN
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ecore_tunn_clss
block|{
name|ECORE_TUNN_CLSS_MAC_VLAN
block|,
name|ECORE_TUNN_CLSS_MAC_VNI
block|,
name|ECORE_TUNN_CLSS_INNER_MAC_VLAN
block|,
name|ECORE_TUNN_CLSS_INNER_MAC_VNI
block|,
name|ECORE_TUNN_CLSS_MAC_VLAN_DUAL_STAGE
block|,
name|MAX_ECORE_TUNN_CLSS
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_tunn_update_type
block|{
name|bool
name|b_update_mode
decl_stmt|;
name|bool
name|b_mode_enabled
decl_stmt|;
name|enum
name|ecore_tunn_clss
name|tun_cls
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_tunn_update_udp_port
block|{
name|bool
name|b_update_port
decl_stmt|;
name|u16
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_tunnel_info
block|{
name|struct
name|ecore_tunn_update_type
name|vxlan
decl_stmt|;
name|struct
name|ecore_tunn_update_type
name|l2_geneve
decl_stmt|;
name|struct
name|ecore_tunn_update_type
name|ip_geneve
decl_stmt|;
name|struct
name|ecore_tunn_update_type
name|l2_gre
decl_stmt|;
name|struct
name|ecore_tunn_update_type
name|ip_gre
decl_stmt|;
name|struct
name|ecore_tunn_update_udp_port
name|vxlan_port
decl_stmt|;
name|struct
name|ecore_tunn_update_udp_port
name|geneve_port
decl_stmt|;
name|bool
name|b_update_rx_cls
decl_stmt|;
name|bool
name|b_update_tx_cls
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The PCI personality is not quite synonymous to protocol ID:  * 1. All personalities need CORE connections  * 2. The Ethernet personality may support also the RoCE/iWARP protocol  */
end_comment

begin_enum
enum|enum
name|ecore_pci_personality
block|{
name|ECORE_PCI_ETH
block|,
name|ECORE_PCI_FCOE
block|,
name|ECORE_PCI_ISCSI
block|,
name|ECORE_PCI_ETH_ROCE
block|,
name|ECORE_PCI_ETH_IWARP
block|,
name|ECORE_PCI_ETH_RDMA
block|,
name|ECORE_PCI_DEFAULT
comment|/* default in shmem */
block|}
enum|;
end_enum

begin_comment
comment|/* All VFs are symetric, all counters are PF + all VFs */
end_comment

begin_struct
struct|struct
name|ecore_qm_iids
block|{
name|u32
name|cids
decl_stmt|;
name|u32
name|vf_cids
decl_stmt|;
name|u32
name|tids
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_PF_PER_PORT
value|8
end_define

begin_comment
comment|/* HW / FW resources, output of features supported below, most information  * is received from MFW.  */
end_comment

begin_enum
enum|enum
name|ecore_resources
block|{
name|ECORE_L2_QUEUE
block|,
name|ECORE_VPORT
block|,
name|ECORE_RSS_ENG
block|,
name|ECORE_PQ
block|,
name|ECORE_RL
block|,
name|ECORE_MAC
block|,
name|ECORE_VLAN
block|,
name|ECORE_RDMA_CNQ_RAM
block|,
name|ECORE_ILT
block|,
name|ECORE_LL2_QUEUE
block|,
name|ECORE_CMDQS_CQS
block|,
name|ECORE_RDMA_STATS_QUEUE
block|,
name|ECORE_BDQ
block|,
comment|/* This is needed only internally for matching against the IGU. 	 * In case of legacy MFW, would be set to `0'. 	 */
name|ECORE_SB
block|,
name|ECORE_MAX_RESC
block|, }
enum|;
end_enum

begin_comment
comment|/* Features that require resources, given as input to the resource management  * algorithm, the output are the resources above  */
end_comment

begin_enum
enum|enum
name|ecore_feature
block|{
name|ECORE_PF_L2_QUE
block|,
name|ECORE_PF_TC
block|,
name|ECORE_VF
block|,
name|ECORE_EXTRA_VF_QUE
block|,
name|ECORE_VMQ
block|,
name|ECORE_RDMA_CNQ
block|,
name|ECORE_ISCSI_CQ
block|,
name|ECORE_FCOE_CQ
block|,
name|ECORE_VF_L2_QUE
block|,
name|ECORE_MAX_FEATURES
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ecore_port_mode
block|{
name|ECORE_PORT_MODE_DE_2X40G
block|,
name|ECORE_PORT_MODE_DE_2X50G
block|,
name|ECORE_PORT_MODE_DE_1X100G
block|,
name|ECORE_PORT_MODE_DE_4X10G_F
block|,
name|ECORE_PORT_MODE_DE_4X10G_E
block|,
name|ECORE_PORT_MODE_DE_4X20G
block|,
name|ECORE_PORT_MODE_DE_1X40G
block|,
name|ECORE_PORT_MODE_DE_2X25G
block|,
name|ECORE_PORT_MODE_DE_1X25G
block|,
name|ECORE_PORT_MODE_DE_4X25G
block|,
name|ECORE_PORT_MODE_DE_2X10G
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ecore_dev_cap
block|{
name|ECORE_DEV_CAP_ETH
block|,
name|ECORE_DEV_CAP_FCOE
block|,
name|ECORE_DEV_CAP_ISCSI
block|,
name|ECORE_DEV_CAP_ROCE
block|,
name|ECORE_DEV_CAP_IWARP
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ecore_hw_err_type
block|{
name|ECORE_HW_ERR_FAN_FAIL
block|,
name|ECORE_HW_ERR_MFW_RESP_FAIL
block|,
name|ECORE_HW_ERR_HW_ATTN
block|,
name|ECORE_HW_ERR_DMAE_FAIL
block|,
name|ECORE_HW_ERR_RAMROD_FAIL
block|,
name|ECORE_HW_ERR_FW_ASSERT
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ecore_wol_support
block|{
name|ECORE_WOL_SUPPORT_NONE
block|,
name|ECORE_WOL_SUPPORT_PME
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_hw_info
block|{
comment|/* PCI personality */
name|enum
name|ecore_pci_personality
name|personality
decl_stmt|;
define|#
directive|define
name|ECORE_IS_RDMA_PERSONALITY
parameter_list|(
name|dev
parameter_list|)
define|\
value|((dev)->hw_info.personality == ECORE_PCI_ETH_ROCE || \ 	 (dev)->hw_info.personality == ECORE_PCI_ETH_IWARP || \ 	 (dev)->hw_info.personality == ECORE_PCI_ETH_RDMA)
define|#
directive|define
name|ECORE_IS_ROCE_PERSONALITY
parameter_list|(
name|dev
parameter_list|)
define|\
value|((dev)->hw_info.personality == ECORE_PCI_ETH_ROCE || \ 	 (dev)->hw_info.personality == ECORE_PCI_ETH_RDMA)
define|#
directive|define
name|ECORE_IS_IWARP_PERSONALITY
parameter_list|(
name|dev
parameter_list|)
define|\
value|((dev)->hw_info.personality == ECORE_PCI_ETH_IWARP || \ 	 (dev)->hw_info.personality == ECORE_PCI_ETH_RDMA)
define|#
directive|define
name|ECORE_IS_L2_PERSONALITY
parameter_list|(
name|dev
parameter_list|)
define|\
value|((dev)->hw_info.personality == ECORE_PCI_ETH || \ 	 ECORE_IS_RDMA_PERSONALITY(dev))
define|#
directive|define
name|ECORE_IS_FCOE_PERSONALITY
parameter_list|(
name|dev
parameter_list|)
define|\
value|((dev)->hw_info.personality == ECORE_PCI_FCOE)
define|#
directive|define
name|ECORE_IS_ISCSI_PERSONALITY
parameter_list|(
name|dev
parameter_list|)
define|\
value|((dev)->hw_info.personality == ECORE_PCI_ISCSI)
comment|/* Resource Allocation scheme results */
name|u32
name|resc_start
index|[
name|ECORE_MAX_RESC
index|]
decl_stmt|;
name|u32
name|resc_num
index|[
name|ECORE_MAX_RESC
index|]
decl_stmt|;
name|u32
name|feat_num
index|[
name|ECORE_MAX_FEATURES
index|]
decl_stmt|;
define|#
directive|define
name|RESC_START
parameter_list|(
name|_p_hwfn
parameter_list|,
name|resc
parameter_list|)
value|((_p_hwfn)->hw_info.resc_start[resc])
define|#
directive|define
name|RESC_NUM
parameter_list|(
name|_p_hwfn
parameter_list|,
name|resc
parameter_list|)
value|((_p_hwfn)->hw_info.resc_num[resc])
define|#
directive|define
name|RESC_END
parameter_list|(
name|_p_hwfn
parameter_list|,
name|resc
parameter_list|)
value|(RESC_START(_p_hwfn, resc) + \ 					 RESC_NUM(_p_hwfn, resc))
define|#
directive|define
name|FEAT_NUM
parameter_list|(
name|_p_hwfn
parameter_list|,
name|resc
parameter_list|)
value|((_p_hwfn)->hw_info.feat_num[resc])
comment|/* Amount of traffic classes HW supports */
name|u8
name|num_hw_tc
decl_stmt|;
comment|/* Amount of TCs which should be active according to DCBx or upper layer driver configuration */
name|u8
name|num_active_tc
decl_stmt|;
comment|/* The traffic class used by PF for it's offloaded protocol */
name|u8
name|offload_tc
decl_stmt|;
name|u32
name|concrete_fid
decl_stmt|;
name|u16
name|opaque_fid
decl_stmt|;
name|u16
name|ovlan
decl_stmt|;
name|u32
name|part_num
index|[
literal|4
index|]
decl_stmt|;
ifndef|#
directive|ifndef
name|ETH_ALEN
define|#
directive|define
name|ETH_ALEN
value|6
comment|/* @@@ TBD - define somewhere else for Windows */
endif|#
directive|endif
name|unsigned
name|char
name|hw_mac_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u64
name|node_wwn
decl_stmt|;
comment|/* For FCoE only */
name|u64
name|port_wwn
decl_stmt|;
comment|/* For FCoE only */
name|u16
name|num_iscsi_conns
decl_stmt|;
name|u16
name|num_fcoe_conns
decl_stmt|;
name|struct
name|ecore_igu_info
modifier|*
name|p_igu_info
decl_stmt|;
comment|/* Sriov */
name|u8
name|max_chains_per_vf
decl_stmt|;
name|u32
name|port_mode
decl_stmt|;
name|u32
name|hw_mode
decl_stmt|;
name|unsigned
name|long
name|device_capabilities
decl_stmt|;
comment|/* Default DCBX mode */
name|u8
name|dcbx_mode
decl_stmt|;
name|u16
name|mtu
decl_stmt|;
name|enum
name|ecore_wol_support
name|b_wol_support
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* maximun size of read/write commands (HW limit) */
end_comment

begin_define
define|#
directive|define
name|DMAE_MAX_RW_SIZE
value|0x2000
end_define

begin_struct
struct|struct
name|ecore_dmae_info
block|{
comment|/* Mutex for synchronizing access to functions */
name|osal_mutex_t
name|mutex
decl_stmt|;
name|u8
name|channel
decl_stmt|;
name|dma_addr_t
name|completion_word_phys_addr
decl_stmt|;
comment|/* The memory location where the DMAE writes the completion 	 * value when an operation is finished on this context. 	 */
name|u32
modifier|*
name|p_completion_word
decl_stmt|;
name|dma_addr_t
name|intermediate_buffer_phys_addr
decl_stmt|;
comment|/* An intermediate buffer for DMAE operations that use virtual 	 * addresses - data is DMA'd to/from this buffer and then 	 * memcpy'd to/from the virtual address 	 */
name|u32
modifier|*
name|p_intermediate_buffer
decl_stmt|;
name|dma_addr_t
name|dmae_cmd_phys_addr
decl_stmt|;
name|struct
name|dmae_cmd
modifier|*
name|p_dmae_cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_wfq_data
block|{
name|u32
name|default_min_speed
decl_stmt|;
comment|/* When wfq feature is not configured */
name|u32
name|min_speed
decl_stmt|;
comment|/* when feature is configured for any 1 vport */
name|bool
name|configured
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_qm_info
block|{
name|struct
name|init_qm_pq_params
modifier|*
name|qm_pq_params
decl_stmt|;
name|struct
name|init_qm_vport_params
modifier|*
name|qm_vport_params
decl_stmt|;
name|struct
name|init_qm_port_params
modifier|*
name|qm_port_params
decl_stmt|;
name|u16
name|start_pq
decl_stmt|;
name|u8
name|start_vport
decl_stmt|;
name|u16
name|pure_lb_pq
decl_stmt|;
name|u16
name|offload_pq
decl_stmt|;
name|u16
name|low_latency_pq
decl_stmt|;
name|u16
name|pure_ack_pq
decl_stmt|;
name|u16
name|ooo_pq
decl_stmt|;
name|u16
name|first_vf_pq
decl_stmt|;
name|u16
name|first_mcos_pq
decl_stmt|;
name|u16
name|first_rl_pq
decl_stmt|;
name|u16
name|num_pqs
decl_stmt|;
name|u16
name|num_vf_pqs
decl_stmt|;
name|u8
name|num_vports
decl_stmt|;
name|u8
name|max_phys_tcs_per_port
decl_stmt|;
name|u8
name|ooo_tc
decl_stmt|;
name|bool
name|pf_rl_en
decl_stmt|;
name|bool
name|pf_wfq_en
decl_stmt|;
name|bool
name|vport_rl_en
decl_stmt|;
name|bool
name|vport_wfq_en
decl_stmt|;
name|u8
name|pf_wfq
decl_stmt|;
name|u32
name|pf_rl
decl_stmt|;
name|struct
name|ecore_wfq_data
modifier|*
name|wfq_data
decl_stmt|;
name|u8
name|num_pf_rls
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|storm_stats
block|{
name|u32
name|address
decl_stmt|;
name|u32
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_fw_data
block|{
ifdef|#
directive|ifdef
name|CONFIG_ECORE_BINARY_FW
name|struct
name|fw_ver_info
modifier|*
name|fw_ver_info
decl_stmt|;
endif|#
directive|endif
specifier|const
name|u8
modifier|*
name|modes_tree_buf
decl_stmt|;
name|union
name|init_op
modifier|*
name|init_ops
decl_stmt|;
specifier|const
name|u32
modifier|*
name|arr_data
decl_stmt|;
name|u32
name|init_ops_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_hwfn
block|{
name|struct
name|ecore_dev
modifier|*
name|p_dev
decl_stmt|;
name|u8
name|my_id
decl_stmt|;
comment|/* ID inside the PF */
define|#
directive|define
name|IS_LEAD_HWFN
parameter_list|(
name|edev
parameter_list|)
value|(!((edev)->my_id))
name|u8
name|rel_pf_id
decl_stmt|;
comment|/* Relative to engine*/
name|u8
name|abs_pf_id
decl_stmt|;
define|#
directive|define
name|ECORE_PATH_ID
parameter_list|(
name|_p_hwfn
parameter_list|)
define|\
value|(ECORE_IS_K2((_p_hwfn)->p_dev) ? 0 : ((_p_hwfn)->abs_pf_id& 1))
name|u8
name|port_id
decl_stmt|;
name|bool
name|b_active
decl_stmt|;
name|u32
name|dp_module
decl_stmt|;
name|u8
name|dp_level
decl_stmt|;
name|char
name|name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
name|void
modifier|*
name|dp_ctx
decl_stmt|;
name|bool
name|first_on_engine
decl_stmt|;
name|bool
name|hw_init_done
decl_stmt|;
name|u8
name|num_funcs_on_engine
decl_stmt|;
name|u8
name|enabled_func_idx
decl_stmt|;
comment|/* BAR access */
name|void
name|OSAL_IOMEM
modifier|*
name|regview
decl_stmt|;
name|void
name|OSAL_IOMEM
modifier|*
name|doorbells
decl_stmt|;
name|u64
name|db_phys_addr
decl_stmt|;
name|unsigned
name|long
name|db_size
decl_stmt|;
comment|/* PTT pool */
name|struct
name|ecore_ptt_pool
modifier|*
name|p_ptt_pool
decl_stmt|;
comment|/* HW info */
name|struct
name|ecore_hw_info
name|hw_info
decl_stmt|;
comment|/* rt_array (for init-tool) */
name|struct
name|ecore_rt_data
name|rt_data
decl_stmt|;
comment|/* SPQ */
name|struct
name|ecore_spq
modifier|*
name|p_spq
decl_stmt|;
comment|/* EQ */
name|struct
name|ecore_eq
modifier|*
name|p_eq
decl_stmt|;
comment|/* Consolidate Q*/
name|struct
name|ecore_consq
modifier|*
name|p_consq
decl_stmt|;
comment|/* Slow-Path definitions */
name|osal_dpc_t
name|sp_dpc
decl_stmt|;
name|bool
name|b_sp_dpc_enabled
decl_stmt|;
name|struct
name|ecore_ptt
modifier|*
name|p_main_ptt
decl_stmt|;
name|struct
name|ecore_ptt
modifier|*
name|p_dpc_ptt
decl_stmt|;
name|struct
name|ecore_sb_sp_info
modifier|*
name|p_sp_sb
decl_stmt|;
name|struct
name|ecore_sb_attn_info
modifier|*
name|p_sb_attn
decl_stmt|;
comment|/* Protocol related */
name|bool
name|using_ll2
decl_stmt|;
name|struct
name|ecore_ll2_info
modifier|*
name|p_ll2_info
decl_stmt|;
name|struct
name|ecore_ooo_info
modifier|*
name|p_ooo_info
decl_stmt|;
name|struct
name|ecore_iscsi_info
modifier|*
name|p_iscsi_info
decl_stmt|;
name|struct
name|ecore_fcoe_info
modifier|*
name|p_fcoe_info
decl_stmt|;
name|struct
name|ecore_rdma_info
modifier|*
name|p_rdma_info
decl_stmt|;
name|struct
name|ecore_pf_params
name|pf_params
decl_stmt|;
name|bool
name|b_rdma_enabled_in_prs
decl_stmt|;
name|u32
name|rdma_prs_search_reg
decl_stmt|;
name|struct
name|ecore_cxt_mngr
modifier|*
name|p_cxt_mngr
decl_stmt|;
comment|/* Flag indicating whether interrupts are enabled or not*/
name|bool
name|b_int_enabled
decl_stmt|;
name|bool
name|b_int_requested
decl_stmt|;
comment|/* True if the driver requests for the link */
name|bool
name|b_drv_link_init
decl_stmt|;
name|struct
name|ecore_vf_iov
modifier|*
name|vf_iov_info
decl_stmt|;
name|struct
name|ecore_pf_iov
modifier|*
name|pf_iov_info
decl_stmt|;
name|struct
name|ecore_mcp_info
modifier|*
name|mcp_info
decl_stmt|;
name|struct
name|ecore_dcbx_info
modifier|*
name|p_dcbx_info
decl_stmt|;
name|struct
name|ecore_dmae_info
name|dmae_info
decl_stmt|;
comment|/* QM init */
name|struct
name|ecore_qm_info
name|qm_info
decl_stmt|;
comment|/* Buffer for unzipping firmware data */
ifdef|#
directive|ifdef
name|CONFIG_ECORE_ZIPPED_FW
name|void
modifier|*
name|unzip_buf
decl_stmt|;
endif|#
directive|endif
name|struct
name|dbg_tools_data
name|dbg_info
decl_stmt|;
comment|/* PWM region specific data */
name|u16
name|wid_count
decl_stmt|;
name|u32
name|dpi_size
decl_stmt|;
name|u32
name|dpi_count
decl_stmt|;
name|u32
name|dpi_start_offset
decl_stmt|;
comment|/* this is used to 							   * calculate th 							   * doorbell address 							   */
comment|/* If one of the following is set then EDPM shouldn't be used */
name|u8
name|dcbx_no_edpm
decl_stmt|;
name|u8
name|db_bar_no_edpm
decl_stmt|;
comment|/* L2-related */
name|struct
name|ecore_l2_info
modifier|*
name|p_l2_info
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ecore_mf_mode
block|{
name|ECORE_MF_DEFAULT
block|,
name|ECORE_MF_OVLAN
block|,
name|ECORE_MF_NPAR
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|ecore_dev_type
block|{
name|ECORE_DEV_TYPE_BB
block|,
name|ECORE_DEV_TYPE_AH
block|,
name|ECORE_DEV_TYPE_E5
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_dev
block|{
name|u32
name|dp_module
decl_stmt|;
name|u8
name|dp_level
decl_stmt|;
name|char
name|name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
name|void
modifier|*
name|dp_ctx
decl_stmt|;
name|enum
name|ecore_dev_type
name|type
decl_stmt|;
comment|/* Translate type/revision combo into the proper conditions */
define|#
directive|define
name|ECORE_IS_BB
parameter_list|(
name|dev
parameter_list|)
value|((dev)->type == ECORE_DEV_TYPE_BB)
define|#
directive|define
name|ECORE_IS_BB_A0
parameter_list|(
name|dev
parameter_list|)
value|(ECORE_IS_BB(dev)&& CHIP_REV_IS_A0(dev))
ifndef|#
directive|ifndef
name|ASIC_ONLY
define|#
directive|define
name|ECORE_IS_BB_B0
parameter_list|(
name|dev
parameter_list|)
value|((ECORE_IS_BB(dev)&& CHIP_REV_IS_B0(dev)) || \ 				 (CHIP_REV_IS_TEDIBEAR(dev)))
else|#
directive|else
define|#
directive|define
name|ECORE_IS_BB_B0
parameter_list|(
name|dev
parameter_list|)
value|(ECORE_IS_BB(dev)&& CHIP_REV_IS_B0(dev))
endif|#
directive|endif
define|#
directive|define
name|ECORE_IS_AH
parameter_list|(
name|dev
parameter_list|)
value|((dev)->type == ECORE_DEV_TYPE_AH)
define|#
directive|define
name|ECORE_IS_K2
parameter_list|(
name|dev
parameter_list|)
value|ECORE_IS_AH(dev)
define|#
directive|define
name|ECORE_IS_E5
parameter_list|(
name|dev
parameter_list|)
value|false
define|#
directive|define
name|ECORE_E5_MISSING_CODE
value|OSAL_BUILD_BUG_ON(false)
name|u16
name|vendor_id
decl_stmt|;
name|u16
name|device_id
decl_stmt|;
define|#
directive|define
name|ECORE_DEV_ID_MASK
value|0xff00
define|#
directive|define
name|ECORE_DEV_ID_MASK_BB
value|0x1600
define|#
directive|define
name|ECORE_DEV_ID_MASK_AH
value|0x8000
name|u16
name|chip_num
decl_stmt|;
define|#
directive|define
name|CHIP_NUM_MASK
value|0xffff
define|#
directive|define
name|CHIP_NUM_SHIFT
value|16
name|u16
name|chip_rev
decl_stmt|;
define|#
directive|define
name|CHIP_REV_MASK
value|0xf
define|#
directive|define
name|CHIP_REV_SHIFT
value|12
ifndef|#
directive|ifndef
name|ASIC_ONLY
define|#
directive|define
name|CHIP_REV_IS_TEDIBEAR
parameter_list|(
name|_p_dev
parameter_list|)
value|((_p_dev)->chip_rev == 0x5)
define|#
directive|define
name|CHIP_REV_IS_EMUL_A0
parameter_list|(
name|_p_dev
parameter_list|)
value|((_p_dev)->chip_rev == 0xe)
define|#
directive|define
name|CHIP_REV_IS_EMUL_B0
parameter_list|(
name|_p_dev
parameter_list|)
value|((_p_dev)->chip_rev == 0xc)
define|#
directive|define
name|CHIP_REV_IS_EMUL
parameter_list|(
name|_p_dev
parameter_list|)
value|(CHIP_REV_IS_EMUL_A0(_p_dev) || \ 					  CHIP_REV_IS_EMUL_B0(_p_dev))
define|#
directive|define
name|CHIP_REV_IS_FPGA_A0
parameter_list|(
name|_p_dev
parameter_list|)
value|((_p_dev)->chip_rev == 0xf)
define|#
directive|define
name|CHIP_REV_IS_FPGA_B0
parameter_list|(
name|_p_dev
parameter_list|)
value|((_p_dev)->chip_rev == 0xd)
define|#
directive|define
name|CHIP_REV_IS_FPGA
parameter_list|(
name|_p_dev
parameter_list|)
value|(CHIP_REV_IS_FPGA_A0(_p_dev) || \ 					  CHIP_REV_IS_FPGA_B0(_p_dev))
define|#
directive|define
name|CHIP_REV_IS_SLOW
parameter_list|(
name|_p_dev
parameter_list|)
define|\
value|(CHIP_REV_IS_EMUL(_p_dev) || CHIP_REV_IS_FPGA(_p_dev))
define|#
directive|define
name|CHIP_REV_IS_A0
parameter_list|(
name|_p_dev
parameter_list|)
define|\
value|(CHIP_REV_IS_EMUL_A0(_p_dev) || \ 		 CHIP_REV_IS_FPGA_A0(_p_dev) || \ 		 !(_p_dev)->chip_rev)
define|#
directive|define
name|CHIP_REV_IS_B0
parameter_list|(
name|_p_dev
parameter_list|)
define|\
value|(CHIP_REV_IS_EMUL_B0(_p_dev) || \ 		 CHIP_REV_IS_FPGA_B0(_p_dev) || \ 		 (_p_dev)->chip_rev == 1)
define|#
directive|define
name|CHIP_REV_IS_ASIC
parameter_list|(
name|_p_dev
parameter_list|)
value|!CHIP_REV_IS_SLOW(_p_dev)
else|#
directive|else
define|#
directive|define
name|CHIP_REV_IS_A0
parameter_list|(
name|_p_dev
parameter_list|)
value|(!(_p_dev)->chip_rev)
define|#
directive|define
name|CHIP_REV_IS_B0
parameter_list|(
name|_p_dev
parameter_list|)
value|((_p_dev)->chip_rev == 1)
endif|#
directive|endif
name|u16
name|chip_metal
decl_stmt|;
define|#
directive|define
name|CHIP_METAL_MASK
value|0xff
define|#
directive|define
name|CHIP_METAL_SHIFT
value|4
name|u16
name|chip_bond_id
decl_stmt|;
define|#
directive|define
name|CHIP_BOND_ID_MASK
value|0xf
define|#
directive|define
name|CHIP_BOND_ID_SHIFT
value|0
name|u8
name|num_engines
decl_stmt|;
name|u8
name|num_ports_in_engines
decl_stmt|;
name|u8
name|num_funcs_in_port
decl_stmt|;
name|u8
name|path_id
decl_stmt|;
name|enum
name|ecore_mf_mode
name|mf_mode
decl_stmt|;
define|#
directive|define
name|IS_MF_DEFAULT
parameter_list|(
name|_p_hwfn
parameter_list|)
value|(((_p_hwfn)->p_dev)->mf_mode == ECORE_MF_DEFAULT)
define|#
directive|define
name|IS_MF_SI
parameter_list|(
name|_p_hwfn
parameter_list|)
value|(((_p_hwfn)->p_dev)->mf_mode == ECORE_MF_NPAR)
define|#
directive|define
name|IS_MF_SD
parameter_list|(
name|_p_hwfn
parameter_list|)
value|(((_p_hwfn)->p_dev)->mf_mode == ECORE_MF_OVLAN)
name|int
name|pcie_width
decl_stmt|;
name|int
name|pcie_speed
decl_stmt|;
comment|/* Add MF related configuration */
name|u8
name|mcp_rev
decl_stmt|;
name|u8
name|boot_mode
decl_stmt|;
comment|/* WoL related configurations */
name|u8
name|wol_config
decl_stmt|;
name|u8
name|wol_mac
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u32
name|int_mode
decl_stmt|;
name|enum
name|ecore_coalescing_mode
name|int_coalescing_mode
decl_stmt|;
name|u16
name|rx_coalesce_usecs
decl_stmt|;
name|u16
name|tx_coalesce_usecs
decl_stmt|;
comment|/* Start Bar offset of first hwfn */
name|void
name|OSAL_IOMEM
modifier|*
name|regview
decl_stmt|;
name|void
name|OSAL_IOMEM
modifier|*
name|doorbells
decl_stmt|;
name|u64
name|db_phys_addr
decl_stmt|;
name|unsigned
name|long
name|db_size
decl_stmt|;
comment|/* PCI */
name|u8
name|cache_shift
decl_stmt|;
comment|/* Init */
specifier|const
name|struct
name|iro
modifier|*
name|iro_arr
decl_stmt|;
define|#
directive|define
name|IRO
value|(p_hwfn->p_dev->iro_arr)
comment|/* HW functions */
name|u8
name|num_hwfns
decl_stmt|;
name|struct
name|ecore_hwfn
name|hwfns
index|[
name|MAX_HWFNS_PER_DEVICE
index|]
decl_stmt|;
comment|/* SRIOV */
name|struct
name|ecore_hw_sriov_info
modifier|*
name|p_iov_info
decl_stmt|;
define|#
directive|define
name|IS_ECORE_SRIOV
parameter_list|(
name|p_dev
parameter_list|)
value|(!!(p_dev)->p_iov_info)
ifdef|#
directive|ifdef
name|CONFIG_ECORE_SW_CHANNEL
name|bool
name|b_hw_channel
decl_stmt|;
endif|#
directive|endif
name|struct
name|ecore_tunnel_info
name|tunnel
decl_stmt|;
name|bool
name|b_is_vf
decl_stmt|;
name|bool
name|b_dont_override_vf_msix
decl_stmt|;
name|u32
name|drv_type
decl_stmt|;
name|u32
name|rdma_max_sge
decl_stmt|;
name|u32
name|rdma_max_inline
decl_stmt|;
name|u32
name|rdma_max_srq_sge
decl_stmt|;
name|struct
name|ecore_eth_stats
modifier|*
name|reset_stats
decl_stmt|;
name|struct
name|ecore_fw_data
modifier|*
name|fw_data
decl_stmt|;
name|u32
name|mcp_nvm_resp
decl_stmt|;
comment|/* Recovery */
name|bool
name|recov_in_prog
decl_stmt|;
comment|/* Indicates whether should prevent attentions from being reasserted */
name|bool
name|attn_clr_en
decl_stmt|;
comment|/* Indicates whether allowing the MFW to collect a crash dump */
name|bool
name|allow_mdump
decl_stmt|;
comment|/* Indicates if the reg_fifo is checked after any register access */
name|bool
name|chk_reg_fifo
decl_stmt|;
ifndef|#
directive|ifndef
name|ASIC_ONLY
name|bool
name|b_is_emul_full
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NUM_OF_VFS
parameter_list|(
name|dev
parameter_list|)
value|(ECORE_IS_BB(dev) ? MAX_NUM_VFS_BB \ 						  : MAX_NUM_VFS_K2)
end_define

begin_define
define|#
directive|define
name|NUM_OF_L2_QUEUES
parameter_list|(
name|dev
parameter_list|)
value|(ECORE_IS_BB(dev) ? MAX_NUM_L2_QUEUES_BB \ 						  : MAX_NUM_L2_QUEUES_K2)
end_define

begin_define
define|#
directive|define
name|NUM_OF_PORTS
parameter_list|(
name|dev
parameter_list|)
value|(ECORE_IS_BB(dev) ? MAX_NUM_PORTS_BB \ 						  : MAX_NUM_PORTS_K2)
end_define

begin_define
define|#
directive|define
name|NUM_OF_SBS
parameter_list|(
name|dev
parameter_list|)
value|(ECORE_IS_BB(dev) ? MAX_SB_PER_PATH_BB \ 						  : MAX_SB_PER_PATH_K2)
end_define

begin_define
define|#
directive|define
name|NUM_OF_ENG_PFS
parameter_list|(
name|dev
parameter_list|)
value|(ECORE_IS_BB(dev) ? MAX_NUM_PFS_BB \ 						  : MAX_NUM_PFS_K2)
end_define

begin_comment
comment|/**  * @brief ecore_concrete_to_sw_fid - get the sw function id from  *        the concrete value.  *  * @param concrete_fid  *  * @return OSAL_INLINE u8  */
end_comment

begin_function
specifier|static
name|OSAL_INLINE
name|u8
name|ecore_concrete_to_sw_fid
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|u32
name|concrete_fid
parameter_list|)
block|{
name|u8
name|vfid
init|=
name|GET_FIELD
argument_list|(
name|concrete_fid
argument_list|,
name|PXP_CONCRETE_FID_VFID
argument_list|)
decl_stmt|;
name|u8
name|pfid
init|=
name|GET_FIELD
argument_list|(
name|concrete_fid
argument_list|,
name|PXP_CONCRETE_FID_PFID
argument_list|)
decl_stmt|;
name|u8
name|vf_valid
init|=
name|GET_FIELD
argument_list|(
name|concrete_fid
argument_list|,
name|PXP_CONCRETE_FID_VFVALID
argument_list|)
decl_stmt|;
name|u8
name|sw_fid
decl_stmt|;
if|if
condition|(
name|vf_valid
condition|)
name|sw_fid
operator|=
name|vfid
operator|+
name|MAX_NUM_PFS
expr_stmt|;
else|else
name|sw_fid
operator|=
name|pfid
expr_stmt|;
return|return
name|sw_fid
return|;
block|}
end_function

begin_define
define|#
directive|define
name|PURE_LB_TC
value|8
end_define

begin_define
define|#
directive|define
name|PKT_LB_TC
value|9
end_define

begin_function_decl
name|int
name|ecore_configure_vport_wfq
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|u16
name|vp_id
parameter_list|,
name|u32
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_configure_vp_wfq_on_link_change
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u32
name|min_pf_rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_configure_pf_max_bandwidth
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|u8
name|max_bw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_configure_pf_min_bandwidth
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|u8
name|min_bw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_clean_wfq_db
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_device_num_engines
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_device_num_ports
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_set_fw_mac_addr
parameter_list|(
name|__le16
modifier|*
name|fw_msb
parameter_list|,
name|__le16
modifier|*
name|fw_mid
parameter_list|,
name|__le16
modifier|*
name|fw_lsb
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flags for indication of required queues */
end_comment

begin_define
define|#
directive|define
name|PQ_FLAGS_RLS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PQ_FLAGS_MCOS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PQ_FLAGS_LB
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PQ_FLAGS_OOO
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PQ_FLAGS_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PQ_FLAGS_OFLD
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PQ_FLAGS_VFS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PQ_FLAGS_LLT
value|(1<< 7)
end_define

begin_comment
comment|/* physical queue index for cm context intialization */
end_comment

begin_function_decl
name|u16
name|ecore_get_cm_pq_idx
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|pq_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|ecore_get_cm_pq_idx_mcos
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|tc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|ecore_get_cm_pq_idx_vf
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|vf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|ecore_get_cm_pq_idx_rl
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|qpid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* amount of resources used in qm init */
end_comment

begin_function_decl
name|u8
name|ecore_init_qm_get_num_tcs
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|ecore_init_qm_get_num_vfs
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|ecore_init_qm_get_num_pf_rls
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|ecore_init_qm_get_num_vports
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u16
name|ecore_init_qm_get_num_pqs
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ECORE_LEADING_HWFN
parameter_list|(
name|dev
parameter_list|)
value|(&dev->hwfns[0])
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|ecore_hw_get_resc_name
parameter_list|(
name|enum
name|ecore_resources
name|res_id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_H */
end_comment

end_unit

