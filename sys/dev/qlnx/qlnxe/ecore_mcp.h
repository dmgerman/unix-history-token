begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_MCP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_MCP_H__
end_define

begin_include
include|#
directive|include
file|"bcm_osal.h"
end_include

begin_include
include|#
directive|include
file|"mcp_public.h"
end_include

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_include
include|#
directive|include
file|"ecore_mcp_api.h"
end_include

begin_include
include|#
directive|include
file|"ecore_dev_api.h"
end_include

begin_comment
comment|/* Using hwfn number (and not pf_num) is required since in CMT mode,  * same pf_num may be used by two different hwfn  * TODO - this shouldn't really be in .h file, but until all fields  * required during hw-init will be placed in their correct place in shmem  * we need it in ecore_dev.c [for readin the nvram reflection in shmem].  */
end_comment

begin_define
define|#
directive|define
name|MCP_PF_ID_BY_REL
parameter_list|(
name|p_hwfn
parameter_list|,
name|rel_pfid
parameter_list|)
value|(ECORE_IS_BB((p_hwfn)->p_dev) ? \ 					    ((rel_pfid) | \ 					     ((p_hwfn)->abs_pf_id& 1)<< 3) : \ 					     rel_pfid)
end_define

begin_define
define|#
directive|define
name|MCP_PF_ID
parameter_list|(
name|p_hwfn
parameter_list|)
value|MCP_PF_ID_BY_REL(p_hwfn, (p_hwfn)->rel_pf_id)
end_define

begin_define
define|#
directive|define
name|MFW_PORT
parameter_list|(
name|_p_hwfn
parameter_list|)
value|((_p_hwfn)->abs_pf_id % \ 				 ((_p_hwfn)->p_dev->num_ports_in_engine * \ 				  ecore_device_num_engines((_p_hwfn)->p_dev)))
end_define

begin_struct
struct|struct
name|ecore_mcp_info
block|{
comment|/* List for mailbox commands which were sent and wait for a response */
name|osal_list_t
name|cmd_list
decl_stmt|;
comment|/* Spinlock used for protecting the access to the mailbox commands list 	 * and the sending of the commands. 	 */
name|osal_spinlock_t
name|cmd_lock
decl_stmt|;
comment|/* Flag to indicate whether sending a MFW mailbox command is blocked */
name|bool
name|b_block_cmd
decl_stmt|;
comment|/* Spinlock used for syncing SW link-changes and link-changes 	 * originating from attention context. 	 */
name|osal_spinlock_t
name|link_lock
decl_stmt|;
comment|/* Address of the MCP public area */
name|u32
name|public_base
decl_stmt|;
comment|/* Address of the driver mailbox */
name|u32
name|drv_mb_addr
decl_stmt|;
comment|/* Address of the MFW mailbox */
name|u32
name|mfw_mb_addr
decl_stmt|;
comment|/* Address of the port configuration (link) */
name|u32
name|port_addr
decl_stmt|;
comment|/* Current driver mailbox sequence */
name|u16
name|drv_mb_seq
decl_stmt|;
comment|/* Current driver pulse sequence */
name|u16
name|drv_pulse_seq
decl_stmt|;
name|struct
name|ecore_mcp_link_params
name|link_input
decl_stmt|;
name|struct
name|ecore_mcp_link_state
name|link_output
decl_stmt|;
name|struct
name|ecore_mcp_link_capabilities
name|link_capabilities
decl_stmt|;
name|struct
name|ecore_mcp_function_info
name|func_info
decl_stmt|;
name|u8
modifier|*
name|mfw_mb_cur
decl_stmt|;
name|u8
modifier|*
name|mfw_mb_shadow
decl_stmt|;
name|u16
name|mfw_mb_length
decl_stmt|;
name|u32
name|mcp_hist
decl_stmt|;
comment|/* Capabilties negotiated with the MFW */
name|u32
name|capabilities
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_mcp_mb_params
block|{
name|u32
name|cmd
decl_stmt|;
name|u32
name|param
decl_stmt|;
name|void
modifier|*
name|p_data_src
decl_stmt|;
name|u8
name|data_src_size
decl_stmt|;
name|void
modifier|*
name|p_data_dst
decl_stmt|;
name|u8
name|data_dst_size
decl_stmt|;
name|u32
name|mcp_resp
decl_stmt|;
name|u32
name|mcp_param
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ecore_ov_eswitch
block|{
name|ECORE_OV_ESWITCH_NONE
block|,
name|ECORE_OV_ESWITCH_VEB
block|,
name|ECORE_OV_ESWITCH_VEPA
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ecore_drv_tlv_hdr
block|{
name|u8
name|tlv_type
decl_stmt|;
comment|/* According to the enum below */
name|u8
name|tlv_length
decl_stmt|;
comment|/* In dwords - not including this header */
name|u8
name|tlv_reserved
decl_stmt|;
define|#
directive|define
name|ECORE_DRV_TLV_FLAGS_CHANGED
value|0x01
name|u8
name|tlv_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief Initialize the interface with the MCP  *  * @param p_hwfn - HW func  * @param p_ptt - PTT required for register access  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_cmd_init
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

begin_comment
comment|/**  * @brief Intialize the port interface with the MCP  *  * @param p_hwfn  * @param p_ptt  * Can only be called after `num_ports_in_engine' is set  */
end_comment

begin_function_decl
name|void
name|ecore_mcp_cmd_port_init
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

begin_comment
comment|/**  * @brief Releases resources allocated during the init process.  *  * @param p_hwfn - HW func  * @param p_ptt - PTT required for register access  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief This function is called from the DPC context. After  * pointing PTT to the mfw mb, check for events sent by the MCP  * to the driver and ack them. In case a critical event  * detected, it will be handled here, otherwise the work will be  * queued to a sleepable work-queue.  *  * @param p_hwfn - HW function  * @param p_ptt - PTT required for register access  * @return enum _ecore_status_t - ECORE_SUCCESS - operation  * was successul.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_handle_events
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

begin_comment
comment|/**  * @brief When MFW doesn't get driver pulse for couple of seconds, at some  * threshold before timeout expires, it will generate interrupt  * through a dedicated status block (DPSB - Driver Pulse Status  * Block), which the driver should respond immediately, by  * providing keepalive indication after setting the PTT to the  * driver-MFW mailbox. This function is called directly from the  * DPC upon receiving the DPSB attention.  *  * @param p_hwfn - hw function  * @param p_ptt - PTT required for register access  * @return enum _ecore_status_t - ECORE_SUCCESS - operation  * was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_issue_pulse
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

begin_enum
enum|enum
name|ecore_drv_role
block|{
name|ECORE_DRV_ROLE_OS
block|,
name|ECORE_DRV_ROLE_KDUMP
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_load_req_params
block|{
comment|/* Input params */
name|enum
name|ecore_drv_role
name|drv_role
decl_stmt|;
name|u8
name|timeout_val
decl_stmt|;
comment|/* 1..254, '0' - default value, '255' - no timeout */
name|bool
name|avoid_eng_reset
decl_stmt|;
name|enum
name|ecore_override_force_load
name|override_force_load
decl_stmt|;
comment|/* Output params */
name|u32
name|load_code
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief Sends a LOAD_REQ to the MFW, and in case the operation succeeds,  *        returns whether this PF is the first on the engine/port or function.  *  * @param p_hwfn  * @param p_ptt  * @param p_params  *  * @return enum _ecore_status_t - ECORE_SUCCESS - Operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_load_req
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
parameter_list|,
name|struct
name|ecore_load_req_params
modifier|*
name|p_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Sends a UNLOAD_REQ message to the MFW  *  * @param p_hwfn  * @param p_ptt  *  * @return enum _ecore_status_t - ECORE_SUCCESS - Operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_unload_req
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

begin_comment
comment|/**  * @brief Sends a UNLOAD_DONE message to the MFW  *  * @param p_hwfn  * @param p_ptt  *  * @return enum _ecore_status_t - ECORE_SUCCESS - Operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_unload_done
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

begin_comment
comment|/**  * @brief Read the MFW mailbox into Current buffer.  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|void
name|ecore_mcp_read_mb
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

begin_comment
comment|/**  * @brief Ack to mfw that driver finished FLR process for VFs  *  * @param p_hwfn  * @param p_ptt  * @param vfs_to_ack - bit mask of all engine VFs for which the PF acks.  *  * @param return enum _ecore_status_t - ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_ack_vf_flr
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
parameter_list|,
name|u32
modifier|*
name|vfs_to_ack
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - calls during init to read shmem of all function-related info.  *  * @param p_hwfn  *  * @param return ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_fill_shmem_func_info
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

begin_comment
comment|/**  * @brief - Reset the MCP using mailbox command.  *  * @param p_hwfn  * @param p_ptt  *  * @param return ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_reset
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

begin_comment
comment|/**  * @brief indicates whether the MFW objects [under mcp_info] are accessible  *  * @param p_hwfn  *  * @return true iff MFW is running and mcp_info is initialized  */
end_comment

begin_function_decl
name|bool
name|ecore_mcp_is_init
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief request MFW to configure MSI-X for a VF  *  * @param p_hwfn  * @param p_ptt  * @param vf_id - absolute inside engine  * @param num_sbs - number of entries to request  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_config_vf_msix
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
parameter_list|,
name|u8
name|vf_id
parameter_list|,
name|u8
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Halt the MCP.  *  * @param p_hwfn  * @param p_ptt  *  * @param return ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_halt
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

begin_comment
comment|/**  * @brief - Wake up the MCP.  *  * @param p_hwfn  * @param p_ptt  *  * @param return ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_resume
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
name|__ecore_configure_pf_max_bandwidth
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
parameter_list|,
name|struct
name|ecore_mcp_link_state
modifier|*
name|p_link
parameter_list|,
name|u8
name|max_bw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__ecore_configure_pf_min_bandwidth
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
parameter_list|,
name|struct
name|ecore_mcp_link_state
modifier|*
name|p_link
parameter_list|,
name|u8
name|min_bw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_mask_parities
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
parameter_list|,
name|u32
name|mask_parities
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|enum _ecore_status_t ecore_hw_init_first_eth(struct ecore_hwfn *p_hwfn, 					     struct ecore_ptt *p_ptt, 					     u8 *p_pf);
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * @brief - Sends crash mdump related info to the MFW.  *  * @param p_hwfn  * @param p_ptt  * @param epoch  *  * @param return ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_mdump_set_values
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
parameter_list|,
name|u32
name|epoch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Triggers a MFW crash dump procedure.  *  * @param p_hwfn  * @param p_ptt  *  * @param return ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_mdump_trigger
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

begin_struct
struct|struct
name|ecore_mdump_retain_data
block|{
name|u32
name|valid
decl_stmt|;
name|u32
name|epoch
decl_stmt|;
name|u32
name|pf
decl_stmt|;
name|u32
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief - Gets the mdump retained data from the MFW.  *  * @param p_hwfn  * @param p_ptt  * @param p_mdump_retain  *  * @param return ECORE_SUCCESS upon success.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_mdump_get_retain
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
parameter_list|,
name|struct
name|ecore_mdump_retain_data
modifier|*
name|p_mdump_retain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Sets the MFW's max value for the given resource  *  *  @param p_hwfn  *  @param p_ptt  *  @param res_id  *  @param resc_max_val  *  @param p_mcp_resp  *  * @return enum _ecore_status_t - ECORE_SUCCESS - operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_set_resc_max_val
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
parameter_list|,
name|enum
name|ecore_resources
name|res_id
parameter_list|,
name|u32
name|resc_max_val
parameter_list|,
name|u32
modifier|*
name|p_mcp_resp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Gets the MFW allocation info for the given resource  *  *  @param p_hwfn  *  @param p_ptt  *  @param res_id  *  @param p_mcp_resp  *  @param p_resc_num  *  @param p_resc_start  *  * @return enum _ecore_status_t - ECORE_SUCCESS - operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_get_resc_info
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
parameter_list|,
name|enum
name|ecore_resources
name|res_id
parameter_list|,
name|u32
modifier|*
name|p_mcp_resp
parameter_list|,
name|u32
modifier|*
name|p_resc_num
parameter_list|,
name|u32
modifier|*
name|p_resc_start
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Initiates PF FLR  *  *  @param p_hwfn  *  @param p_ptt  *  * @return enum _ecore_status_t - ECORE_SUCCESS - operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_initiate_pf_flr
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

begin_comment
comment|/**  * @brief Send eswitch mode to MFW  *  *  @param p_hwfn  *  @param p_ptt  *  @param eswitch - eswitch mode  *  * @return enum _ecore_status_t - ECORE_SUCCESS - operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_ov_update_eswitch
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
parameter_list|,
name|enum
name|ecore_ov_eswitch
name|eswitch
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ECORE_MCP_RESC_LOCK_MIN_VAL
value|RESOURCE_DUMP
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|ECORE_MCP_RESC_LOCK_MAX_VAL
value|31
end_define

begin_enum
enum|enum
name|ecore_resc_lock
block|{
name|ECORE_RESC_LOCK_DBG_DUMP
init|=
name|ECORE_MCP_RESC_LOCK_MIN_VAL
block|,
comment|/* Locks that the MFW is aware of should be added here downwards */
comment|/* Ecore only locks should be added here upwards */
name|ECORE_RESC_LOCK_PTP_PORT0
block|,
name|ECORE_RESC_LOCK_PTP_PORT1
block|,
name|ECORE_RESC_LOCK_PTP_PORT2
block|,
name|ECORE_RESC_LOCK_PTP_PORT3
block|,
name|ECORE_RESC_LOCK_RESC_ALLOC
init|=
name|ECORE_MCP_RESC_LOCK_MAX_VAL
block|,
comment|/* A dummy value to be used for auxillary functions in need of 	 * returning an 'error' value. 	 */
name|ECORE_RESC_LOCK_RESC_INVALID
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_resc_lock_params
block|{
comment|/* Resource number [valid values are 0..31] */
name|u8
name|resource
decl_stmt|;
comment|/* Lock timeout value in seconds [default, none or 1..254] */
name|u8
name|timeout
decl_stmt|;
define|#
directive|define
name|ECORE_MCP_RESC_LOCK_TO_DEFAULT
value|0
define|#
directive|define
name|ECORE_MCP_RESC_LOCK_TO_NONE
value|255
comment|/* Number of times to retry locking */
name|u8
name|retry_num
decl_stmt|;
define|#
directive|define
name|ECORE_MCP_RESC_LOCK_RETRY_CNT_DFLT
value|10
comment|/* The interval in usec between retries */
name|u16
name|retry_interval
decl_stmt|;
define|#
directive|define
name|ECORE_MCP_RESC_LOCK_RETRY_VAL_DFLT
value|10000
comment|/* Use sleep or delay between retries */
name|bool
name|sleep_b4_retry
decl_stmt|;
comment|/* Will be set as true if the resource is free and granted */
name|bool
name|b_granted
decl_stmt|;
comment|/* Will be filled with the resource owner. 	 * [0..15 = PF0-15, 16 = MFW, 17 = diag over serial] 	 */
name|u8
name|owner
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief Acquires MFW generic resource lock  *  *  @param p_hwfn  *  @param p_ptt  *  @param p_params  *  * @return enum _ecore_status_t - ECORE_SUCCESS - operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_resc_lock
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
parameter_list|,
name|struct
name|ecore_resc_lock_params
modifier|*
name|p_params
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ecore_resc_unlock_params
block|{
comment|/* Resource number [valid values are 0..31] */
name|u8
name|resource
decl_stmt|;
comment|/* Allow to release a resource even if belongs to another PF */
name|bool
name|b_force
decl_stmt|;
comment|/* Will be set as true if the resource is released */
name|bool
name|b_released
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief Releases MFW generic resource lock  *  *  @param p_hwfn  *  @param p_ptt  *  @param p_params  *  * @return enum _ecore_status_t - ECORE_SUCCESS - operation was successful.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_resc_unlock
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
parameter_list|,
name|struct
name|ecore_resc_unlock_params
modifier|*
name|p_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - default initialization for lock/unlock resource structs  *  * @param p_lock - lock params struct to be initialized; Can be OSAL_NULL  * @param p_unlock - unlock params struct to be initialized; Can be OSAL_NULL  * @param resource - the requested resource  * @paral b_is_permanent - disable retries& aging when set  */
end_comment

begin_function_decl
name|void
name|ecore_mcp_resc_lock_default_init
parameter_list|(
name|struct
name|ecore_resc_lock_params
modifier|*
name|p_lock
parameter_list|,
name|struct
name|ecore_resc_unlock_params
modifier|*
name|p_unlock
parameter_list|,
name|enum
name|ecore_resc_lock
name|resource
parameter_list|,
name|bool
name|b_is_permanent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_mcp_wol_wr
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
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u32
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Learn of supported MFW features; To be done during early init  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_get_capabilities
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

begin_comment
comment|/**  * @brief Inform MFW of set of features supported by driver. Should be done  * inside the contet of the LOAD_REQ.  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_mcp_set_capabilities
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

begin_comment
comment|/**  * @brief Initialize MFW mailbox and sequence values for driver interaction.  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_load_mcp_offsets
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_MCP_H__ */
end_comment

end_unit

