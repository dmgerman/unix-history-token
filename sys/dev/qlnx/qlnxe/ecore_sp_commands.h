begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_SP_COMMANDS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_SP_COMMANDS_H__
end_define

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_include
include|#
directive|include
file|"ecore_spq.h"
end_include

begin_include
include|#
directive|include
file|"ecore_sp_api.h"
end_include

begin_define
define|#
directive|define
name|ECORE_SP_EQ_COMPLETION
value|0x01
end_define

begin_define
define|#
directive|define
name|ECORE_SP_CQE_COMPLETION
value|0x02
end_define

begin_struct
struct|struct
name|ecore_sp_init_data
block|{
comment|/* The CID and FID aren't necessarily derived from hwfn, 	 * e.g., in IOV scenarios. CID might defer between SPQ and 	 * other elements. 	 */
name|u32
name|cid
decl_stmt|;
name|u16
name|opaque_fid
decl_stmt|;
comment|/* Information regarding operation upon sending& completion */
name|enum
name|spq_mode
name|comp_mode
decl_stmt|;
name|struct
name|ecore_spq_comp_cb
modifier|*
name|p_comp_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief Acquire and initialize and SPQ entry for a given ramrod.  *  * @param p_hwfn  * @param pp_ent - will be filled with a pointer to an entry upon success  * @param cmd - dependent upon protocol  * @param protocol  * @param p_data - various configuration required for ramrod  *  * @return ECORE_SUCCESS upon success, otherwise failure.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_init_request
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_spq_entry
modifier|*
modifier|*
name|pp_ent
parameter_list|,
name|u8
name|cmd
parameter_list|,
name|u8
name|protocol
parameter_list|,
name|struct
name|ecore_sp_init_data
modifier|*
name|p_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_pf_start - PF Function Start Ramrod  *  * This ramrod is sent to initialize a physical function (PF). It will  * configure the function related parameters and write its completion to the  * event ring specified in the parameters.  *  * Ramrods complete on the common event ring for the PF. This ring is  * allocated by the driver on host memory and its parameters are written  * to the internal RAM of the UStorm by the Function Start Ramrod.  *  * @param p_hwfn  * @param p_ptt  * @param p_tunn - pf start tunneling configuration  * @param mode  * @param allow_npar_tx_switch - npar tx switching to be used  *	  for vports configured for tx-switching.  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_pf_start
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
name|ecore_tunnel_info
modifier|*
name|p_tunn
parameter_list|,
name|enum
name|ecore_mf_mode
name|mode
parameter_list|,
name|bool
name|allow_npar_tx_switch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_pf_update - PF Function Update Ramrod  *  * This ramrod updates function-related parameters. Every parameter can be  * updated independently, according to configuration flags.  *  * @note Final phase API.  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_pf_update_dcbx
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_pf_stop - PF Function Stop Ramrod  *  * This ramrod is sent to close a Physical Function (PF). It is the last ramrod  * sent and the last completion written to the PFs Event Ring. This ramrod also  * deletes the context for the Slowhwfn connection on this PF.  *  * @note Not required for first packet.  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_pf_stop
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_heartbeat_ramrod - Send empty Ramrod  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_heartbeat_ramrod
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ecore_rl_update_params
block|{
name|u8
name|qcn_update_param_flg
decl_stmt|;
name|u8
name|dcqcn_update_param_flg
decl_stmt|;
name|u8
name|rl_init_flg
decl_stmt|;
name|u8
name|rl_start_flg
decl_stmt|;
name|u8
name|rl_stop_flg
decl_stmt|;
name|u8
name|rl_id_first
decl_stmt|;
name|u8
name|rl_id_last
decl_stmt|;
name|u8
name|rl_dc_qcn_flg
decl_stmt|;
comment|/* If set, RL will used for DCQCN */
name|u32
name|rl_bc_rate
decl_stmt|;
comment|/* Byte Counter Limit */
name|u16
name|rl_max_rate
decl_stmt|;
comment|/* Maximum rate in 1.6 Mbps resolution */
name|u16
name|rl_r_ai
decl_stmt|;
comment|/* Active increase rate */
name|u16
name|rl_r_hai
decl_stmt|;
comment|/* Hyper active increase rate */
name|u16
name|dcqcn_g
decl_stmt|;
comment|/* DCQCN Alpha update gain in 1/64K resolution */
name|u32
name|dcqcn_k_us
decl_stmt|;
comment|/* DCQCN Alpha update interval */
name|u32
name|dcqcn_timeuot_us
decl_stmt|;
name|u32
name|qcn_timeuot_us
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief ecore_sp_rl_update - Update rate limiters  *  * @param p_hwfn  * @param params  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_rl_update
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_rl_update_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sp_pf_update_stag - PF STAG value update Ramrod  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sp_pf_update_stag
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__ECORE_SP_COMMANDS_H__*/
end_comment

end_unit

