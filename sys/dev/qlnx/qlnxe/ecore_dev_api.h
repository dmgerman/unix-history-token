begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_DEV_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_DEV_API_H__
end_define

begin_include
include|#
directive|include
file|"ecore_status.h"
end_include

begin_include
include|#
directive|include
file|"ecore_chain.h"
end_include

begin_include
include|#
directive|include
file|"ecore_int_api.h"
end_include

begin_struct
struct|struct
name|ecore_wake_info
block|{
name|u32
name|wk_info
decl_stmt|;
name|u32
name|wk_details
decl_stmt|;
name|u32
name|wk_pkt_len
decl_stmt|;
name|u8
name|wk_buffer
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_init_dp - initialize the debug level  *  * @param p_dev  * @param dp_module  * @param dp_level  * @param dp_ctx  */
end_comment

begin_function_decl
name|void
name|ecore_init_dp
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|u32
name|dp_module
parameter_list|,
name|u8
name|dp_level
parameter_list|,
name|void
modifier|*
name|dp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_struct - initialize the device structure to  *        its defaults  *  * @param p_dev  */
end_comment

begin_function_decl
name|void
name|ecore_init_struct
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_resc_free -  *  * @param p_dev  */
end_comment

begin_function_decl
name|void
name|ecore_resc_free
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_resc_alloc -  *  * @param p_dev  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_resc_alloc
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_resc_setup -  *  * @param p_dev  */
end_comment

begin_function_decl
name|void
name|ecore_resc_setup
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ecore_override_force_load
block|{
name|ECORE_OVERRIDE_FORCE_LOAD_NONE
block|,
name|ECORE_OVERRIDE_FORCE_LOAD_ALWAYS
block|,
name|ECORE_OVERRIDE_FORCE_LOAD_NEVER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_drv_load_params
block|{
comment|/* Indicates whether the driver is running over a crash kernel. 	 * As part of the load request, this will be used for providing the 	 * driver role to the MFW. 	 * In case of a crash kernel over PDA - this should be set to false. 	 */
name|bool
name|is_crash_kernel
decl_stmt|;
comment|/* The timeout value that the MFW should use when locking the engine for 	 * the driver load process. 	 * A value of '0' means the default value, and '255' means no timeout. 	 */
name|u8
name|mfw_timeout_val
decl_stmt|;
define|#
directive|define
name|ECORE_LOAD_REQ_LOCK_TO_DEFAULT
value|0
define|#
directive|define
name|ECORE_LOAD_REQ_LOCK_TO_NONE
value|255
comment|/* Avoid engine reset when first PF loads on it */
name|bool
name|avoid_eng_reset
decl_stmt|;
comment|/* Allow overriding the default force load behavior */
name|enum
name|ecore_override_force_load
name|override_force_load
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_hw_init_params
block|{
comment|/* Tunneling parameters */
name|struct
name|ecore_tunnel_info
modifier|*
name|p_tunn
decl_stmt|;
name|bool
name|b_hw_start
decl_stmt|;
comment|/* Interrupt mode [msix, inta, etc.] to use */
name|enum
name|ecore_int_mode
name|int_mode
decl_stmt|;
comment|/* NPAR tx switching to be used for vports configured for tx-switching */
name|bool
name|allow_npar_tx_switch
decl_stmt|;
comment|/* Binary fw data pointer in binary fw file */
specifier|const
name|u8
modifier|*
name|bin_fw_data
decl_stmt|;
comment|/* Driver load parameters */
name|struct
name|ecore_drv_load_params
modifier|*
name|p_drv_load_params
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_hw_init -  *  * @param p_dev  * @param p_params  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_hw_init
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|struct
name|ecore_hw_init_params
modifier|*
name|p_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_hw_timers_stop_all -  *  * @param p_dev  *  * @return void  */
end_comment

begin_function_decl
name|void
name|ecore_hw_timers_stop_all
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_hw_stop -  *  * @param p_dev  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_hw_stop
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_hw_stop_fastpath -should be called incase  *        slowpath is still required for the device,  *        but fastpath is not.  *  * @param p_dev  *  */
end_comment

begin_function_decl
name|void
name|ecore_hw_stop_fastpath
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_hw_hibernate_prepare -should be called when  *        the system is going into the hibernate state  *  * @param p_dev  *  */
end_comment

begin_function_decl
name|void
name|ecore_hw_hibernate_prepare
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_hw_hibernate_resume -should be called when the system is 	  resuming from D3 power state and before calling ecore_hw_init.  *  * @param p_hwfn  *  */
end_comment

begin_function_decl
name|void
name|ecore_hw_hibernate_resume
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_hw_start_fastpath -restart fastpath traffic,  *        only if hw_stop_fastpath was called   * @param p_dev  *  */
end_comment

begin_function_decl
name|void
name|ecore_hw_start_fastpath
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ecore_hw_prepare_result
block|{
name|ECORE_HW_PREPARE_SUCCESS
block|,
comment|/* FAILED results indicate probe has failed& cleaned up */
name|ECORE_HW_PREPARE_FAILED_ENG2
block|,
name|ECORE_HW_PREPARE_FAILED_ME
block|,
name|ECORE_HW_PREPARE_FAILED_MEM
block|,
name|ECORE_HW_PREPARE_FAILED_DEV
block|,
name|ECORE_HW_PREPARE_FAILED_NVM
block|,
comment|/* BAD results indicate probe is passed even though some wrongness 	 * has occurred; Trying to actually use [I.e., hw_init()] might have 	 * dire reprecautions. 	 */
name|ECORE_HW_PREPARE_BAD_IOV
block|,
name|ECORE_HW_PREPARE_BAD_MCP
block|,
name|ECORE_HW_PREPARE_BAD_IGU
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_hw_prepare_params
block|{
comment|/* Personality to initialize */
name|int
name|personality
decl_stmt|;
comment|/* Force the driver's default resource allocation */
name|bool
name|drv_resc_alloc
decl_stmt|;
comment|/* Check the reg_fifo after any register access */
name|bool
name|chk_reg_fifo
decl_stmt|;
comment|/* Request the MFW to initiate PF FLR */
name|bool
name|initiate_pf_flr
decl_stmt|;
comment|/* The OS Epoch time in seconds */
name|u32
name|epoch
decl_stmt|;
comment|/* Allow the MFW to collect a crash dump */
name|bool
name|allow_mdump
decl_stmt|;
comment|/* Allow prepare to pass even if some initializations are failing. 	 * If set, the `p_prepare_res' field would be set with the return, 	 * and might allow probe to pass even if there are certain issues. 	 */
name|bool
name|b_relaxed_probe
decl_stmt|;
name|enum
name|ecore_hw_prepare_result
name|p_relaxed_res
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_hw_prepare -  *  * @param p_dev  * @param p_params  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_hw_prepare
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|struct
name|ecore_hw_prepare_params
modifier|*
name|p_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_hw_remove -  *  * @param p_dev  */
end_comment

begin_function_decl
name|void
name|ecore_hw_remove
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_set_nwuf_reg - * * @param p_dev * @param wol_flag - wol_capability * @param reg_idx - Index of the pattern register * @param pattern_size - size of pattern * @param crc - CRC value of patter& mask * * @return enum _ecore_status_t */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_set_nwuf_reg
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
specifier|const
name|bool
name|b_enable
parameter_list|,
name|u32
name|reg_idx
parameter_list|,
name|u32
name|pattern_size
parameter_list|,
name|u32
name|crc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_get_wake_info - get magic packet buffer * * @param p_dev * @param wake_info - pointer to ecore_wake_info buffer * * @return enum _ecore_status_t */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_get_wake_info
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|struct
name|ecore_wake_info
modifier|*
name|wake_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_wol_buffer_clear - Clear magic package buffer * * @param p_dev * * @return void */
end_comment

begin_function_decl
name|void
name|ecore_wol_buffer_clear
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_acquire - Allocate a PTT window  *  * Should be called at the entry point to the driver (at the beginning of an  * exported function)  *  * @param p_hwfn  *  * @return struct ecore_ptt  */
end_comment

begin_function_decl
name|struct
name|ecore_ptt
modifier|*
name|ecore_ptt_acquire
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_release - Release PTT Window  *  * Should be called at the end of a flow - at the end of the function that  * acquired the PTT.  *  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|void
name|ecore_ptt_release
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
name|ecore_eth_stats_common
block|{
name|u64
name|no_buff_discards
decl_stmt|;
name|u64
name|packet_too_big_discard
decl_stmt|;
name|u64
name|ttl0_discard
decl_stmt|;
name|u64
name|rx_ucast_bytes
decl_stmt|;
name|u64
name|rx_mcast_bytes
decl_stmt|;
name|u64
name|rx_bcast_bytes
decl_stmt|;
name|u64
name|rx_ucast_pkts
decl_stmt|;
name|u64
name|rx_mcast_pkts
decl_stmt|;
name|u64
name|rx_bcast_pkts
decl_stmt|;
name|u64
name|mftag_filter_discards
decl_stmt|;
name|u64
name|mac_filter_discards
decl_stmt|;
name|u64
name|tx_ucast_bytes
decl_stmt|;
name|u64
name|tx_mcast_bytes
decl_stmt|;
name|u64
name|tx_bcast_bytes
decl_stmt|;
name|u64
name|tx_ucast_pkts
decl_stmt|;
name|u64
name|tx_mcast_pkts
decl_stmt|;
name|u64
name|tx_bcast_pkts
decl_stmt|;
name|u64
name|tx_err_drop_pkts
decl_stmt|;
name|u64
name|tpa_coalesced_pkts
decl_stmt|;
name|u64
name|tpa_coalesced_events
decl_stmt|;
name|u64
name|tpa_aborts_num
decl_stmt|;
name|u64
name|tpa_not_coalesced_pkts
decl_stmt|;
name|u64
name|tpa_coalesced_bytes
decl_stmt|;
comment|/* port */
name|u64
name|rx_64_byte_packets
decl_stmt|;
name|u64
name|rx_65_to_127_byte_packets
decl_stmt|;
name|u64
name|rx_128_to_255_byte_packets
decl_stmt|;
name|u64
name|rx_256_to_511_byte_packets
decl_stmt|;
name|u64
name|rx_512_to_1023_byte_packets
decl_stmt|;
name|u64
name|rx_1024_to_1518_byte_packets
decl_stmt|;
name|u64
name|rx_crc_errors
decl_stmt|;
name|u64
name|rx_mac_crtl_frames
decl_stmt|;
name|u64
name|rx_pause_frames
decl_stmt|;
name|u64
name|rx_pfc_frames
decl_stmt|;
name|u64
name|rx_align_errors
decl_stmt|;
name|u64
name|rx_carrier_errors
decl_stmt|;
name|u64
name|rx_oversize_packets
decl_stmt|;
name|u64
name|rx_jabbers
decl_stmt|;
name|u64
name|rx_undersize_packets
decl_stmt|;
name|u64
name|rx_fragments
decl_stmt|;
name|u64
name|tx_64_byte_packets
decl_stmt|;
name|u64
name|tx_65_to_127_byte_packets
decl_stmt|;
name|u64
name|tx_128_to_255_byte_packets
decl_stmt|;
name|u64
name|tx_256_to_511_byte_packets
decl_stmt|;
name|u64
name|tx_512_to_1023_byte_packets
decl_stmt|;
name|u64
name|tx_1024_to_1518_byte_packets
decl_stmt|;
name|u64
name|tx_pause_frames
decl_stmt|;
name|u64
name|tx_pfc_frames
decl_stmt|;
name|u64
name|brb_truncates
decl_stmt|;
name|u64
name|brb_discards
decl_stmt|;
name|u64
name|rx_mac_bytes
decl_stmt|;
name|u64
name|rx_mac_uc_packets
decl_stmt|;
name|u64
name|rx_mac_mc_packets
decl_stmt|;
name|u64
name|rx_mac_bc_packets
decl_stmt|;
name|u64
name|rx_mac_frames_ok
decl_stmt|;
name|u64
name|tx_mac_bytes
decl_stmt|;
name|u64
name|tx_mac_uc_packets
decl_stmt|;
name|u64
name|tx_mac_mc_packets
decl_stmt|;
name|u64
name|tx_mac_bc_packets
decl_stmt|;
name|u64
name|tx_mac_ctrl_frames
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_eth_stats_bb
block|{
name|u64
name|rx_1519_to_1522_byte_packets
decl_stmt|;
name|u64
name|rx_1519_to_2047_byte_packets
decl_stmt|;
name|u64
name|rx_2048_to_4095_byte_packets
decl_stmt|;
name|u64
name|rx_4096_to_9216_byte_packets
decl_stmt|;
name|u64
name|rx_9217_to_16383_byte_packets
decl_stmt|;
name|u64
name|tx_1519_to_2047_byte_packets
decl_stmt|;
name|u64
name|tx_2048_to_4095_byte_packets
decl_stmt|;
name|u64
name|tx_4096_to_9216_byte_packets
decl_stmt|;
name|u64
name|tx_9217_to_16383_byte_packets
decl_stmt|;
name|u64
name|tx_lpi_entry_count
decl_stmt|;
name|u64
name|tx_total_collisions
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_eth_stats_ah
block|{
name|u64
name|rx_1519_to_max_byte_packets
decl_stmt|;
name|u64
name|tx_1519_to_max_byte_packets
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_eth_stats
block|{
name|struct
name|ecore_eth_stats_common
name|common
decl_stmt|;
union|union
block|{
name|struct
name|ecore_eth_stats_bb
name|bb
decl_stmt|;
name|struct
name|ecore_eth_stats_ah
name|ah
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ecore_dmae_address_type_t
block|{
name|ECORE_DMAE_ADDRESS_HOST_VIRT
block|,
name|ECORE_DMAE_ADDRESS_HOST_PHYS
block|,
name|ECORE_DMAE_ADDRESS_GRC
block|}
enum|;
end_enum

begin_comment
comment|/* value of flags If ECORE_DMAE_FLAG_RW_REPL_SRC flag is set and the  * source is a block of length DMAE_MAX_RW_SIZE and the  * destination is larger, the source block will be duplicated as  * many times as required to fill the destination block. This is  * used mostly to write a zeroed buffer to destination address  * using DMA  */
end_comment

begin_define
define|#
directive|define
name|ECORE_DMAE_FLAG_RW_REPL_SRC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ECORE_DMAE_FLAG_VF_SRC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ECORE_DMAE_FLAG_VF_DST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ECORE_DMAE_FLAG_COMPLETION_DST
value|0x00000008
end_define

begin_struct
struct|struct
name|ecore_dmae_params
block|{
name|u32
name|flags
decl_stmt|;
comment|/* consists of ECORE_DMAE_FLAG_* values */
name|u8
name|src_vfid
decl_stmt|;
name|u8
name|dst_vfid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_dmae_host2grc - copy data from source addr to  * dmae registers using the given ptt  *  * @param p_hwfn  * @param p_ptt  * @param source_addr  * @param grc_addr (dmae_data_offset)  * @param size_in_dwords  * @param flags (one of the flags defined above)  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_dmae_host2grc
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
name|u64
name|source_addr
parameter_list|,
name|u32
name|grc_addr
parameter_list|,
name|u32
name|size_in_dwords
parameter_list|,
name|u32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_dmae_grc2host - Read data from dmae data offset  * to source address using the given ptt  *  * @param p_ptt  * @param grc_addr (dmae_data_offset)  * @param dest_addr  * @param size_in_dwords  * @param flags - one of the flags defined above  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_dmae_grc2host
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
name|grc_addr
parameter_list|,
name|dma_addr_t
name|dest_addr
parameter_list|,
name|u32
name|size_in_dwords
parameter_list|,
name|u32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_dmae_host2host - copy data from to source address  * to a destination address (for SRIOV) using the given ptt  *  * @param p_hwfn  * @param p_ptt  * @param source_addr  * @param dest_addr  * @param size_in_dwords  * @param params  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_dmae_host2host
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
name|dma_addr_t
name|source_addr
parameter_list|,
name|dma_addr_t
name|dest_addr
parameter_list|,
name|u32
name|size_in_dwords
parameter_list|,
name|struct
name|ecore_dmae_params
modifier|*
name|p_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_chain_alloc - Allocate and initialize a chain  *  * @param p_hwfn  * @param intended_use  * @param mode  * @param num_elems  * @param elem_size  * @param p_chain  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_chain_alloc
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|enum
name|ecore_chain_use_mode
name|intended_use
parameter_list|,
name|enum
name|ecore_chain_mode
name|mode
parameter_list|,
name|enum
name|ecore_chain_cnt_type
name|cnt_type
parameter_list|,
name|u32
name|num_elems
parameter_list|,
name|osal_size_t
name|elem_size
parameter_list|,
name|struct
name|ecore_chain
modifier|*
name|p_chain
parameter_list|,
name|struct
name|ecore_chain_ext_pbl
modifier|*
name|ext_pbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_chain_free - Free chain DMA memory  *  * @param p_hwfn  * @param p_chain  */
end_comment

begin_function_decl
name|void
name|ecore_chain_free
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
name|struct
name|ecore_chain
modifier|*
name|p_chain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @@brief ecore_fw_l2_queue - Get absolute L2 queue ID  *  *  @param p_hwfn  *  @param src_id - relative to p_hwfn  *  @param dst_id - absolute per engine  *  *  @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_fw_l2_queue
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|src_id
parameter_list|,
name|u16
modifier|*
name|dst_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @@brief ecore_fw_vport - Get absolute vport ID  *  *  @param p_hwfn  *  @param src_id - relative to p_hwfn  *  @param dst_id - absolute per engine  *  *  @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_fw_vport
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|src_id
parameter_list|,
name|u8
modifier|*
name|dst_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @@brief ecore_fw_rss_eng - Get absolute RSS engine ID  *  *  @param p_hwfn  *  @param src_id - relative to p_hwfn  *  @param dst_id - absolute per engine  *  *  @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_fw_rss_eng
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|src_id
parameter_list|,
name|u8
modifier|*
name|dst_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_llh_add_mac_filter - configures a MAC filter in llh  *  * @param p_hwfn  * @param p_ptt  * @param p_filter - MAC to add  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_llh_add_mac_filter
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
modifier|*
name|p_filter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_llh_remove_mac_filter - removes a MAC filtre from llh  *  * @param p_hwfn  * @param p_ptt  * @param p_filter - MAC to remove  */
end_comment

begin_function_decl
name|void
name|ecore_llh_remove_mac_filter
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
modifier|*
name|p_filter
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ecore_llh_port_filter_type_t
block|{
name|ECORE_LLH_FILTER_ETHERTYPE
block|,
name|ECORE_LLH_FILTER_TCP_SRC_PORT
block|,
name|ECORE_LLH_FILTER_TCP_DEST_PORT
block|,
name|ECORE_LLH_FILTER_TCP_SRC_AND_DEST_PORT
block|,
name|ECORE_LLH_FILTER_UDP_SRC_PORT
block|,
name|ECORE_LLH_FILTER_UDP_DEST_PORT
block|,
name|ECORE_LLH_FILTER_UDP_SRC_AND_DEST_PORT
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief ecore_llh_add_protocol_filter - configures a protocol filter in llh  *  * @param p_hwfn  * @param p_ptt  * @param source_port_or_eth_type - source port or ethertype to add  * @param dest_port - destination port to add  * @param type - type of filters and comparing  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_llh_add_protocol_filter
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
name|u16
name|source_port_or_eth_type
parameter_list|,
name|u16
name|dest_port
parameter_list|,
name|enum
name|ecore_llh_port_filter_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_llh_remove_protocol_filter - remove a protocol filter in llh  *  * @param p_hwfn  * @param p_ptt  * @param source_port_or_eth_type - source port or ethertype to add  * @param dest_port - destination port to add  * @param type - type of filters and comparing  */
end_comment

begin_function_decl
name|void
name|ecore_llh_remove_protocol_filter
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
name|u16
name|source_port_or_eth_type
parameter_list|,
name|u16
name|dest_port
parameter_list|,
name|enum
name|ecore_llh_port_filter_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_llh_clear_all_filters - removes all MAC filters from llh  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|void
name|ecore_llh_clear_all_filters
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
comment|/**  * @brief ecore_llh_set_function_as_default - set function as defult per port  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_llh_set_function_as_default
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
comment|/**  *@brief Cleanup of previous driver remains prior to load  *  * @param p_hwfn  * @param p_ptt  * @param id - For PF, engine-relative. For VF, PF-relative.  * @param is_vf - true iff cleanup is made for a VF.  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_final_cleanup
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
name|u16
name|id
parameter_list|,
name|bool
name|is_vf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_queue_coalesce - Configure coalesce parameters for Rx and  *    Tx queue. The fact that we can configure coalescing to up to 511, but on  *    varying accuracy [the bigger the value the less accurate] up to a mistake  *    of 3usec for the highest values.  *    While the API allows setting coalescing per-qid, all queues sharing a SB  *    should be in same range [i.e., either 0-0x7f, 0x80-0xff or 0x100-0x1ff]  *    otherwise configuration would break.  *  * @param p_hwfn  * @param rx_coal - Rx Coalesce value in micro seconds.  * @param tx_coal - TX Coalesce value in micro seconds.  * @param p_handle  *  * @return enum _ecore_status_t  **/
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_set_queue_coalesce
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|rx_coal
parameter_list|,
name|u16
name|tx_coal
parameter_list|,
name|void
modifier|*
name|p_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Recalculate feature distributions based on HW resources and  * user inputs. Currently this affects RDMA_CNQ, PF_L2_QUE and VF_L2_QUE.  * As a result, this must not be called while RDMA is active or while VFs  * are enabled.  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_hw_set_feat
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_change_pci_hwfn - Enable or disable PCI BUS MASTER  *  * @param p_hwfn  * @param p_ptt  * @param enable - true/false  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_change_pci_hwfn
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
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

