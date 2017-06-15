begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/****************************************************************************  *  * Name:        mcp_private.h  *  * Description: MCP private data. Located in HSI only to provide debug access  *              for diag.  *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MCP_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|MCP_PRIVATE_H
end_define

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
name|MFW_SIM
operator|)
operator|&&
operator|(
operator|!
name|defined
name|RECOVERY
operator|)
end_if

begin_include
include|#
directive|include
file|"eth.h"
end_include

begin_include
include|#
directive|include
file|"pmm.h"
end_include

begin_include
include|#
directive|include
file|"ah_eth.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mcp_public.h"
end_include

begin_typedef
typedef|typedef
enum|enum
name|active_mf_mode
block|{
name|MF_MODE_SF
init|=
literal|0
block|,
name|MF_MODE_MF_ALLOWED
block|,
name|MF_MODE_MF_SWITCH_INDEPENDENT
block|,
name|MF_MODE_NIV
block|}
name|active_mf_mode_t
typedef|;
end_typedef

begin_enum
enum|enum
name|ov_current_cfg
block|{
name|CURR_CFG_NONE
init|=
literal|0
block|,
name|CURR_CFG_OS
block|,
name|CURR_CFG_VENDOR_SPEC
block|,
name|CURR_CFG_OTHER
block|,
name|CURR_CFG_VC_CLP
block|,
name|CURR_CFG_CNU
block|,
name|CURR_CFG_DCI
block|,
name|CURR_CFG_HII
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|dci_info_global
block|{
name|enum
name|ov_current_cfg
name|current_cfg
decl_stmt|;
name|u8
name|pci_bus_num
decl_stmt|;
name|u8
name|boot_progress
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Resource allocation information of one resource */
end_comment

begin_struct
struct|struct
name|resource_info_private
block|{
name|u16
name|size
decl_stmt|;
comment|/* number of allocated resources */
name|u16
name|offset
decl_stmt|;
comment|/* Offset of the 1st resource */
name|u8
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Cache for resource allocation of one PF */
end_comment

begin_struct
struct|struct
name|res_alloc_cache
block|{
name|u8
name|pf_num
decl_stmt|;
name|struct
name|resource_info_private
name|res
index|[
name|RESOURCE_MAX_NUM
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_sb_t
block|{
name|u8
name|sb_for_pf_size
decl_stmt|;
name|u8
name|sb_for_pf_offset
decl_stmt|;
name|u8
name|sb_for_vf_size
decl_stmt|;
name|u8
name|sb_for_vf_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**************************************/
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/*     P R I V A T E    G L O B A L   */
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/**************************************/
end_comment

begin_struct
struct|struct
name|private_global
block|{
name|active_mf_mode_t
name|mf_mode
decl_stmt|;
comment|/* TBD - require initialization */
name|u32
name|exp_rom_nvm_addr
decl_stmt|;
comment|/* The pmm_config structure holds all active phy/link configuration */
ifndef|#
directive|ifndef
name|RECOVERY
ifdef|#
directive|ifdef
name|b900
name|struct
name|pmm_config
name|eth_cfg
decl_stmt|;
else|#
directive|else
name|struct
name|ah_eth
name|eth_cfg
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|u32
name|lldp_counter
decl_stmt|;
name|u32
name|avs_init_timestamp
decl_stmt|;
name|u32
name|seconds_since_mcp_reset
decl_stmt|;
name|u32
name|last_malloc_dir_used_timestamp
decl_stmt|;
define|#
directive|define
name|MAX_USED_DIR_ALLOWED_TIME
value|(3)
comment|/* Seconds */
name|u32
name|drv_nvm_state
decl_stmt|;
comment|/* Per PF bitmask */
define|#
directive|define
name|DRV_NVM_STATE_IN_PROGRESS_MASK
value|(0x0000ffff)
define|#
directive|define
name|DRV_NVM_STATE_IN_PROGRESS_OFFSET
value|(0)
name|u32
name|storm_fw_ver
decl_stmt|;
comment|/* OneView data*/
name|struct
name|dci_info_global
name|dci_global
decl_stmt|;
comment|/* Resource allocation cached data */
name|struct
name|res_alloc_cache
name|res_alloc
decl_stmt|;
define|#
directive|define
name|G_RES_ALLOC_P
value|(&g_spad.private_data.global.res_alloc)
name|u32
name|resource_max_values
index|[
name|RESOURCE_MAX_NUM
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**************************************/
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/*     P R I V A T E    P A T H       */
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/**************************************/
end_comment

begin_struct
struct|struct
name|private_path
block|{
name|u32
name|recovery_countdown
decl_stmt|;
comment|/* Counting down 2 seconds, using TMR3 */
define|#
directive|define
name|RECOVERY_MAX_COUNTDOWN_SECONDS
value|2
name|u32
name|drv_load_vars
decl_stmt|;
comment|/* When the seconds_since_mcp_reset gets here */
define|#
directive|define
name|DRV_LOAD_TIMEOUT_MASK
value|0x0000ffff
define|#
directive|define
name|DRV_LOAD_TIMEOUT_OFFSET
value|0
define|#
directive|define
name|DRV_LOAD_NEED_FORCE_MASK
value|0xffff0000
define|#
directive|define
name|DRV_LOAD_NEED_FORCE_OFFSET
value|16
name|struct
name|load_rsp_stc
name|drv_load_params
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**************************************/
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/*     P R I V A T E    P O R T       */
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/**************************************/
end_comment

begin_struct
struct|struct
name|drv_port_info_t
block|{
name|u32_t
name|port_state
decl_stmt|;
define|#
directive|define
name|DRV_STATE_LINK_LOCK_FLAG
value|0x00000001
define|#
directive|define
name|DRV_WAIT_DBG_PRN
value|0x00000002
comment|/* There are maximum 8 PFs per port */
define|#
directive|define
name|DRV_STATE_LOADED_MASK
value|0x0000ff00
define|#
directive|define
name|DRV_STATE_LOADED_OFFSET
value|8
define|#
directive|define
name|DRV_STATE_PF_TRANSITION_MASK
value|0x00ff0000
define|#
directive|define
name|DRV_STATE_PF_TRANSITION_OFFSET
value|16
define|#
directive|define
name|DRV_STATE_PF_PHY_INIT_MASK
value|0xff000000
define|#
directive|define
name|DRV_STATE_PF_PHY_INIT_OFFSET
value|24
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
name|_lldp_subscriber_e
block|{
name|LLDP_SUBSCRIBER_MANDATORY
init|=
literal|0
block|,
name|LLDP_SUBSCRIBER_DCBX_IEEE
block|,
name|LLDP_SUBSCRIBER_DCBX_CEE
block|,
name|LLDP_SUBSCRIBER_EEE
block|,
name|LLDP_SUBSCRIBER_DCI
block|,
name|MAX_SUBSCRIBERS
block|}
name|lldp_subscriber_e
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u16
name|valid
decl_stmt|;
name|u16
name|type_len
decl_stmt|;
define|#
directive|define
name|LLDP_LEN_MASK
value|(0x01ff)
define|#
directive|define
name|LLDP_LEN_OFFSET
value|(0)
define|#
directive|define
name|LLDP_TYPE_MASK
value|(0xfe00)
define|#
directive|define
name|LLDP_TYPE_OFFSET
value|(9)
name|u8
modifier|*
name|value_p
decl_stmt|;
block|}
name|tlv_s
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u16
function_decl|(
modifier|*
name|lldp_prepare_tlv_func
function_decl|)
parameter_list|(
name|u8
name|port
parameter_list|,
name|lldp_agent_e
name|lldp_agent
parameter_list|,
name|u8
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u16
name|valid
decl_stmt|;
name|lldp_prepare_tlv_func
name|func
decl_stmt|;
block|}
name|subscriber_callback_send_s
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u8
function_decl|(
modifier|*
name|lldp_process_func
function_decl|)
parameter_list|(
name|u8
name|port
parameter_list|,
name|u8
name|num
parameter_list|,
name|u8
modifier|*
modifier|*
name|tlvs
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|MAX_NUM_SUBTYPES
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u8
name|valid
decl_stmt|;
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
name|u8
name|subtype_list
index|[
name|MAX_NUM_SUBTYPES
index|]
decl_stmt|;
name|u8
name|num_subtypes
decl_stmt|;
name|lldp_process_func
name|func
decl_stmt|;
block|}
name|subscriber_callback_receive_s
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_ETH_HEADER
value|14
end_define

begin_comment
comment|/* TODO: to be extended per requirements */
end_comment

begin_define
define|#
directive|define
name|MAX_PACKET_SIZE
value|(1516)
end_define

begin_comment
comment|/* So it can be devided by 4 */
end_comment

begin_define
define|#
directive|define
name|LLDP_CHASSIS_ID_TLV_LEN
value|7
end_define

begin_define
define|#
directive|define
name|LLDP_PORT_ID_TLV_LEN
value|7
end_define

begin_define
define|#
directive|define
name|MAX_TLV_BUFFER
value|128
end_define

begin_comment
comment|/* In dwords. 512 in bytes*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u16
name|len
decl_stmt|;
name|u8
name|header
index|[
name|MAX_ETH_HEADER
index|]
decl_stmt|;
block|}
name|lldp_eth_header_s
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|lldp_config_params_s
name|lldp_config_params
decl_stmt|;
name|u16
name|lldp_ttl
decl_stmt|;
name|u8
name|lldp_cur_credit
decl_stmt|;
name|subscriber_callback_send_s
name|subscriber_callback_send
index|[
name|MAX_SUBSCRIBERS
index|]
decl_stmt|;
name|lldp_eth_header_s
name|lldp_eth_header
decl_stmt|;
name|u32
name|lldp_time_to_send
decl_stmt|;
name|u32
name|lldp_ttl_expired
decl_stmt|;
name|u32
name|lldp_sent
decl_stmt|;
name|u8
name|first_lldp
decl_stmt|;
name|subscriber_callback_receive_s
name|subscriber_callback_receive
index|[
name|MAX_SUBSCRIBERS
index|]
decl_stmt|;
block|}
name|lldp_params_s
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_TLVS
value|20
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u8
name|current_received_tlv_index
decl_stmt|;
name|u8
modifier|*
name|received_tlvs
index|[
name|MAX_TLVS
index|]
decl_stmt|;
block|}
name|lldp_receive_data_s
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_REGISTERED_TLVS
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u32
name|config
decl_stmt|;
comment|/* Uses same defines as local config plus some more below*/
define|#
directive|define
name|DCBX_MODE_MASK
value|0x00000010
define|#
directive|define
name|DCBX_MODE_OFFSET
value|4
define|#
directive|define
name|DCBX_MODE_DRIVER
value|0
define|#
directive|define
name|DCBX_MODE_DEFAULT
value|1
define|#
directive|define
name|DCBX_CHANGED_MASK
value|0x00000f00
define|#
directive|define
name|DCBX_CHANGED_OFFSET
value|8
define|#
directive|define
name|DCBX_CONTROL_CHANGED_MASK
value|0x00000100
define|#
directive|define
name|DCBX_CONTROL_CHANGED_OFFSET
value|8
define|#
directive|define
name|DCBX_PFC_CHANGED_MASK
value|0x00000200
define|#
directive|define
name|DCBX_PFC_CHANGED_OFFSET
value|9
define|#
directive|define
name|DCBX_ETS_CHANGED_MASK
value|0x00000400
define|#
directive|define
name|DCBX_ETS_CHANGED_OFFSET
value|10
define|#
directive|define
name|DCBX_APP_CHANGED_MASK
value|0x00000800
define|#
directive|define
name|DCBX_APP_CHANGED_OFFSET
value|11
name|u32
name|seq_no
decl_stmt|;
name|u32
name|ack_no
decl_stmt|;
name|u32
name|received_seq_no
decl_stmt|;
name|u8
name|tc_map
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|num_used_tcs
decl_stmt|;
block|}
name|dcbx_state_s
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_HP_DCI_SUPPORT
end_ifdef

begin_struct
struct|struct
name|dci_info_port
block|{
name|u32
name|config
decl_stmt|;
define|#
directive|define
name|DCI_PORT_CFG_ENABLE_OFFSET
value|(0)
define|#
directive|define
name|DCI_PORT_CFG_ENABLE_MASK
value|(1<< DCI_PORT_CFG_ENABLE_OFFSET)
define|#
directive|define
name|DCI_PORT_CFG_ENABLE_DIAG_OFFSET
value|(1)
define|#
directive|define
name|DCI_PORT_CFG_ENABLE_DIAG_MASK
value|(1<< DCI_PORT_CFG_ENABLE_DIAG_OFFSET)
define|#
directive|define
name|DCI_PORT_CFG_DIAG_L_LOOP_OFFSET
value|(2)
define|#
directive|define
name|DCI_PORT_CFG_DIAG_L_LOOP_MASK
value|(1<< DCI_PORT_CFG_DIAG_L_LOOP_OFFSET)
define|#
directive|define
name|DCI_PORT_CFG_DIAG_R_LOOP_OFFSET
value|(3)
define|#
directive|define
name|DCI_PORT_CFG_DIAG_R_LOOP_MASK
value|(1<< DCI_PORT_CFG_DIAG_R_LOOP_OFFSET)
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|private_port
block|{
name|struct
name|drv_port_info_t
name|port_info
decl_stmt|;
name|active_mf_mode_t
name|mf_mode
decl_stmt|;
name|u32
name|prev_link_change_count
decl_stmt|;
comment|/* LLDP structures */
name|lldp_params_s
name|lldp_params
index|[
name|LLDP_MAX_LLDP_AGENTS
index|]
decl_stmt|;
name|lldp_receive_data_s
name|lldp_receive_data
index|[
name|MAX_SUBSCRIBERS
index|]
decl_stmt|;
comment|/* DCBX */
name|dcbx_state_s
name|dcbx_state
decl_stmt|;
name|u32
name|net_buffer
index|[
name|MAX_PACKET_SIZE
operator|/
literal|4
index|]
decl_stmt|;
comment|/* Buffer to send any packet to network */
comment|/* time stamp of the end of NIG drain time for the TX drain */
name|u32
name|nig_drain_end_ts
decl_stmt|;
comment|/* time stamp of the end of NIG drain time for the TC pause drain, this timer is used togther for all TC */
name|u32
name|nig_drain_tc_end_ts
decl_stmt|;
name|u32
name|tc_drain_en_bitmap
decl_stmt|;
name|u32
name|recv_lldp_tlvs
index|[
name|LLDP_MAX_LLDP_AGENTS
index|]
index|[
name|MAX_TLV_BUFFER
index|]
decl_stmt|;
name|tlv_s
name|lldp_core_tlv_desc
index|[
name|LLDP_MAX_LLDP_AGENTS
index|]
index|[
name|MAX_REGISTERED_TLVS
index|]
decl_stmt|;
name|u8
name|current_core_tlv_num
index|[
name|LLDP_MAX_LLDP_AGENTS
index|]
decl_stmt|;
name|struct
name|mcp_mac
name|lldp_mac
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_HP_DCI_SUPPORT
name|struct
name|dci_info_port
name|dci_port
decl_stmt|;
endif|#
directive|endif
name|u32
name|temperature
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**************************************/
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/*     P R I V A T E    F U N C       */
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/**************************************/
end_comment

begin_struct
struct|struct
name|drv_func_info_t
block|{
name|u32_t
name|func_state
decl_stmt|;
define|#
directive|define
name|DRV_STATE_UNKNOWN
value|0x00000000
define|#
directive|define
name|DRV_STATE_UNLOADED
value|0x00000001
define|#
directive|define
name|DRV_STATE_D3
value|0x00000004
define|#
directive|define
name|DRV_STATE_PRESENT_FLAG
value|0x00000100
define|#
directive|define
name|DRV_STATE_RUNNING
value|(0x00000002 | DRV_STATE_PRESENT_FLAG)
define|#
directive|define
name|DRV_STATE_NOT_RESPONDING
value|0x00000003
comment|/* Will result with non-zero value when compared with DRV_STATE_RUNNING or with DRV_STATE_UNLOADED */
define|#
directive|define
name|DRV_STATE_BACK_AFTER_TO
value|(DRV_STATE_NOT_RESPONDING | DRV_STATE_PRESENT_FLAG)
define|#
directive|define
name|DRV_STATE_DIAG
value|(0x00000010 | DRV_STATE_PRESENT_FLAG)
define|#
directive|define
name|DRV_STATE_TRANSITION_FLAG
value|0x00001000
define|#
directive|define
name|DRV_STATE_LOADING_TRANSITION
value|(DRV_STATE_TRANSITION_FLAG | DRV_STATE_PRESENT_FLAG)
define|#
directive|define
name|DRV_STATE_UNLOADING_TRANSITION
value|(DRV_STATE_TRANSITION_FLAG | DRV_STATE_PRESENT_FLAG | DRV_STATE_UNLOADED)
name|u32_t
name|driver_last_activity
decl_stmt|;
name|u32_t
name|wol_mac_addr
index|[
literal|2
index|]
decl_stmt|;
name|u32_t
name|drv_feature_support
decl_stmt|;
comment|/* See DRV_MB_PARAM_FEATURE_SUPPORT_FUNC_* */
name|u8_t
name|unload_wol_param
decl_stmt|;
comment|/* See drv_mb_param */
name|u8_t
name|eswitch_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dci_info_func
block|{
name|u8
name|config
decl_stmt|;
define|#
directive|define
name|DCI_FUNC_CFG_FNIC_ENABLE_OFFSET
value|(0)
define|#
directive|define
name|DCI_FUNC_CFG_FNIC_ENABLE_MASK
value|(1<< DCI_FUNC_CFG_FNIC_ENABLE_OFFSET)
define|#
directive|define
name|DCI_FUNC_CFG_OS_MTU_OVERRIDE_OFFSET
value|(1)
define|#
directive|define
name|DCI_FUNC_CFG_OS_MTU_OVERRIDE_MASK
value|(1<< DCI_FUNC_CFG_OS_MTU_OVERRIDE_OFFSET)
define|#
directive|define
name|DCI_FUNC_CFG_DIAG_WOL_ENABLE_OFFSET
value|(2)
define|#
directive|define
name|DCI_FUNC_CFG_DIAG_WOL_ENABLE_MASK
value|(1<< DCI_FUNC_CFG_DIAG_WOL_ENABLE_OFFSET)
name|u8
name|drv_state
decl_stmt|;
name|u16
name|fcoe_cvid
decl_stmt|;
name|u8
name|fcoe_fabric_name
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|private_func
block|{
name|struct
name|drv_func_info_t
name|func_info
decl_stmt|;
name|u32
name|init_hw_page
decl_stmt|;
name|u32
name|num_of_msix
decl_stmt|;
name|struct
name|pf_sb_t
name|sb
decl_stmt|;
name|struct
name|dci_info_func
name|dci_func
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**************************************/
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/*     P R I V A T E    D A T A       */
end_comment

begin_comment
comment|/*                                    */
end_comment

begin_comment
comment|/**************************************/
end_comment

begin_struct
struct|struct
name|mcp_private_data
block|{
comment|/* Basically no need for section offsets here, since this is private data. 	 * TBD - should consider adding section offsets if we want diag to parse this correctly !! 	 */
name|struct
name|private_global
name|global
decl_stmt|;
name|struct
name|private_path
name|path
index|[
name|MCP_GLOB_PATH_MAX
index|]
decl_stmt|;
name|struct
name|private_port
name|port
index|[
name|MCP_GLOB_PORT_MAX
index|]
decl_stmt|;
name|struct
name|private_func
name|func
index|[
name|MCP_GLOB_FUNC_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MCP_PRIVATE_H */
end_comment

end_unit

