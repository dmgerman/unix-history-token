begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_INT_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_INT_H__
end_define

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_include
include|#
directive|include
file|"ecore_int_api.h"
end_include

begin_define
define|#
directive|define
name|ECORE_CAU_DEF_RX_TIMER_RES
value|0
end_define

begin_define
define|#
directive|define
name|ECORE_CAU_DEF_TX_TIMER_RES
value|0
end_define

begin_define
define|#
directive|define
name|ECORE_SB_ATT_IDX
value|0x0001
end_define

begin_define
define|#
directive|define
name|ECORE_SB_EVENT_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|SB_ALIGNED_SIZE
parameter_list|(
name|p_hwfn
parameter_list|)
define|\
value|ALIGNED_TYPE_SIZE(struct status_block, p_hwfn)
end_define

begin_define
define|#
directive|define
name|ECORE_SB_INVALID_IDX
value|0xffff
end_define

begin_struct
struct|struct
name|ecore_igu_block
block|{
name|u8
name|status
decl_stmt|;
define|#
directive|define
name|ECORE_IGU_STATUS_FREE
value|0x01
define|#
directive|define
name|ECORE_IGU_STATUS_VALID
value|0x02
define|#
directive|define
name|ECORE_IGU_STATUS_PF
value|0x04
define|#
directive|define
name|ECORE_IGU_STATUS_DSB
value|0x08
name|u8
name|vector_number
decl_stmt|;
name|u8
name|function_id
decl_stmt|;
name|u8
name|is_pf
decl_stmt|;
comment|/* Index inside IGU [meant for back reference] */
name|u16
name|igu_sb_id
decl_stmt|;
name|struct
name|ecore_sb_info
modifier|*
name|sb_info
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_igu_info
block|{
name|struct
name|ecore_igu_block
name|entry
index|[
name|MAX_TOT_SB_PER_PATH
index|]
decl_stmt|;
name|u16
name|igu_dsb_id
decl_stmt|;
comment|/* The numbers can shift when using APIs to switch SBs between PF and 	 * VF. 	 */
name|struct
name|ecore_sb_cnt_info
name|usage
decl_stmt|;
comment|/* Determine whether we can shift SBs between VFs and PFs */
name|bool
name|b_allow_pf_vf_change
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief - Make sure the IGU CAM reflects the resources provided by MFW  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|int
name|ecore_int_igu_reset_cam
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
comment|/**  * @brief - Make sure IGU CAM reflects the default resources once again,  *          starting with a 'dirty' SW database.  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|int
name|ecore_int_igu_reset_cam_default
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
comment|/**  * @brief Translate the weakly-defined client sb-id into an IGU sb-id  *  * @param p_hwfn  * @param sb_id - user provided sb_id  *  * @return an index inside IGU CAM where the SB resides  */
end_comment

begin_function_decl
name|u16
name|ecore_get_igu_sb_id
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|sb_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief return a pointer to an unused valid SB  *  * @param p_hwfn  * @param b_is_pf - true iff we want a SB belonging to a PF  *  * @return point to an igu_block, OSAL_NULL if none is available  */
end_comment

begin_function_decl
name|struct
name|ecore_igu_block
modifier|*
name|ecore_get_igu_free_sb
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|bool
name|b_is_pf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TODO Names of function may change... */
end_comment

begin_function_decl
name|void
name|ecore_int_igu_init_pure_rt
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
name|bool
name|b_set
parameter_list|,
name|bool
name|b_slowpath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_int_igu_init_rt
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_int_igu_read_cam - Reads the IGU CAM.  *	This function needs to be called during hardware  *	prepare. It reads the info from igu cam to know which  *	status block is the default / base status block etc.  *  * @param p_hwfn  * @param p_ptt  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_int_igu_read_cam
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

begin_typedef
typedef|typedef
name|enum
name|_ecore_status_t
function_decl|(
modifier|*
name|ecore_int_comp_cb_t
function_decl|)
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * @brief ecore_int_register_cb - Register callback func for  *      slowhwfn statusblock.  *  *	Every protocol that uses the slowhwfn status block  *	should register a callback function that will be called  *	once there is an update of the sp status block.  *  * @param p_hwfn  * @param comp_cb - function to be called when there is an  *                  interrupt on the sp sb  *  * @param cookie  - passed to the callback function  * @param sb_idx  - OUT parameter which gives the chosen index  *                  for this protocol.  * @param p_fw_cons  - pointer to the actual address of the  *                     consumer for this protocol.  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_int_register_cb
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|ecore_int_comp_cb_t
name|comp_cb
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|u8
modifier|*
name|sb_idx
parameter_list|,
name|__le16
modifier|*
modifier|*
name|p_fw_cons
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_int_unregister_cb - Unregisters callback  *      function from sp sb.  *      Partner of ecore_int_register_cb -> should be called  *      when no longer required.  *  * @param p_hwfn  * @param pi  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_int_unregister_cb
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|pi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_int_get_sp_sb_id - Get the slowhwfn sb id.  *  * @param p_hwfn  *  * @return u16  */
end_comment

begin_function_decl
name|u16
name|ecore_int_get_sp_sb_id
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Status block cleanup. Should be called for each status  *        block that will be used -> both PF / VF  *  * @param p_hwfn  * @param p_ptt  * @param sb_id		- igu status block id  * @param opaque	- opaque fid of the sb owner.  * @param cleanup_set	- set(1) / clear(0)  */
end_comment

begin_function_decl
name|void
name|ecore_int_igu_init_pure_rt_single
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
name|sb_id
parameter_list|,
name|u16
name|opaque
parameter_list|,
name|bool
name|b_set
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_int_cau_conf - configure cau for a given status  *        block  *  * @param p_hwfn  * @param ptt  * @param sb_phys  * @param igu_sb_id  * @param vf_number  * @param vf_valid  */
end_comment

begin_function_decl
name|void
name|ecore_int_cau_conf_sb
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
name|sb_phys
parameter_list|,
name|u16
name|igu_sb_id
parameter_list|,
name|u16
name|vf_number
parameter_list|,
name|u8
name|vf_valid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_int_alloc * * @param p_hwfn  * @param p_ptt * * @return enum _ecore_status_t */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_int_alloc
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
comment|/** * @brief ecore_int_free * * @param p_hwfn */
end_comment

begin_function_decl
name|void
name|ecore_int_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_int_setup * * @param p_hwfn * @param p_ptt */
end_comment

begin_function_decl
name|void
name|ecore_int_setup
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
comment|/**  * @brief - Enable Interrupt& Attention for hw function  *  * @param p_hwfn  * @param p_ptt  * @param int_mode  * * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_int_igu_enable
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
name|ecore_int_mode
name|int_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief - Initialize CAU status block entry  *  * @param p_hwfn  * @param p_sb_entry  * @param pf_id  * @param vf_number  * @param vf_valid  */
end_comment

begin_function_decl
name|void
name|ecore_init_cau_sb_entry
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|cau_sb_entry
modifier|*
name|p_sb_entry
parameter_list|,
name|u8
name|pf_id
parameter_list|,
name|u16
name|vf_number
parameter_list|,
name|u8
name|vf_valid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_int_set_timer_res
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
name|timer_res
parameter_list|,
name|u16
name|sb_id
parameter_list|,
name|bool
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|ASIC_ONLY
end_ifndef

begin_define
define|#
directive|define
name|ECORE_MAPPING_MEMORY_SIZE
parameter_list|(
name|dev
parameter_list|)
define|\
value|((CHIP_REV_IS_SLOW(dev)&& (!(dev)->b_is_emul_full)) ? \ 	 136 : NUM_OF_SBS(dev))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ECORE_MAPPING_MEMORY_SIZE
parameter_list|(
name|dev
parameter_list|)
value|NUM_OF_SBS(dev)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_INT_H__ */
end_comment

end_unit

