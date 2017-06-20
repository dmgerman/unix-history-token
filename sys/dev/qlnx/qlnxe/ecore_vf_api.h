begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_VF_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_VF_API_H__
end_define

begin_include
include|#
directive|include
file|"ecore_sp_api.h"
end_include

begin_include
include|#
directive|include
file|"ecore_mcp_api.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ECORE_SRIOV
end_ifdef

begin_comment
comment|/**  * @brief Read the VF bulletin and act on it if needed  *  * @param p_hwfn  * @param p_change - ecore fills 1 iff bulletin board has changed, 0 otherwise.  *  * @return enum _ecore_status  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_vf_read_bulletin
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
modifier|*
name|p_change
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get link paramters for VF from ecore  *  * @param p_hwfn  * @param params - the link params structure to be filled for the VF  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_link_params
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_mcp_link_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get link state for VF from ecore  *  * @param p_hwfn  * @param link - the link state structure to be filled for the VF  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_link_state
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_mcp_link_state
modifier|*
name|link
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get link capabilities for VF from ecore  *  * @param p_hwfn  * @param p_link_caps - the link capabilities structure to be filled for the VF  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_link_caps
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_mcp_link_capabilities
modifier|*
name|p_link_caps
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get number of Rx queues allocated for VF by ecore  *  *  @param p_hwfn  *  @param num_rxqs - allocated RX queues  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_num_rxqs
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
modifier|*
name|num_rxqs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get number of Rx queues allocated for VF by ecore  *  *  @param p_hwfn  *  @param num_txqs - allocated RX queues  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_num_txqs
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
modifier|*
name|num_txqs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get port mac address for VF  *  * @param p_hwfn  * @param port_mac - destination location for port mac  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_port_mac
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
modifier|*
name|port_mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get number of VLAN filters allocated for VF by ecore  *  *  @param p_hwfn  *  @param num_rxqs - allocated VLAN filters  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_num_vlan_filters
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
modifier|*
name|num_vlan_filters
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get number of MAC filters allocated for VF by ecore  *  *  @param p_hwfn  *  @param num_rxqs - allocated MAC filters  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_num_mac_filters
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
modifier|*
name|num_mac_filters
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Check if VF can set a MAC address  *  * @param p_hwfn  * @param mac  *  * @return bool  */
end_comment

begin_function_decl
name|bool
name|ecore_vf_check_mac
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_REMOVE
end_ifndef

begin_comment
comment|/**  * @brief Copy forced MAC address from bulletin board  *  * @param hwfn  * @param dst_mac  * @param p_is_forced - out param which indicate in case mac  *      	        exist if it forced or not.  *    * @return bool       - return true if mac exist and false if  *                      not.  */
end_comment

begin_function_decl
name|bool
name|ecore_vf_bulletin_get_forced_mac
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|hwfn
parameter_list|,
name|u8
modifier|*
name|dst_mac
parameter_list|,
name|u8
modifier|*
name|p_is_forced
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Check if force vlan is set and copy the forced vlan  *        from bulletin board  *  * @param hwfn  * @param dst_pvid  * @return bool  */
end_comment

begin_function_decl
name|bool
name|ecore_vf_bulletin_get_forced_vlan
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|hwfn
parameter_list|,
name|u16
modifier|*
name|dst_pvid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Check if VF is based on PF whose driver is pre-fp-hsi version;  *        This affects the fastpath implementation of the driver.  *  * @param p_hwfn  *  * @return bool - true iff PF is pre-fp-hsi version.  */
end_comment

begin_function_decl
name|bool
name|ecore_vf_get_pre_fp_hsi
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
comment|/**  * @brief Set firmware version information in dev_info from VFs acquire response tlv  *  * @param p_hwfn  * @param fw_major  * @param fw_minor  * @param fw_rev  * @param fw_eng  */
end_comment

begin_function_decl
name|void
name|ecore_vf_get_fw_version
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
modifier|*
name|fw_major
parameter_list|,
name|u16
modifier|*
name|fw_minor
parameter_list|,
name|u16
modifier|*
name|fw_rev
parameter_list|,
name|u16
modifier|*
name|fw_eng
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_vf_bulletin_get_udp_ports
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
modifier|*
name|p_vxlan_port
parameter_list|,
name|u16
modifier|*
name|p_geneve_port
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|OSAL_INLINE
name|enum
name|_ecore_status_t
name|ecore_vf_read_bulletin
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|p_change
parameter_list|)
block|{
return|return
name|ECORE_INVAL
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_link_params
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_mcp_link_params
name|OSAL_UNUSED
modifier|*
name|params
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_link_state
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_mcp_link_state
name|OSAL_UNUSED
modifier|*
name|link
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_link_caps
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_mcp_link_capabilities
name|OSAL_UNUSED
modifier|*
name|p_link_caps
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_num_rxqs
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|num_rxqs
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_num_txqs
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|num_txqs
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_port_mac
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|port_mac
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_num_vlan_filters
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|num_vlan_filters
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_num_mac_filters
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|num_mac_filters
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|bool
name|ecore_vf_check_mac
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|mac
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_REMOVE
end_ifndef

begin_function
specifier|static
name|OSAL_INLINE
name|bool
name|ecore_vf_bulletin_get_forced_mac
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|dst_mac
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|p_is_forced
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|bool
name|ecore_vf_get_pre_fp_hsi
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_get_fw_version
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|OSAL_UNUSED
modifier|*
name|fw_major
parameter_list|,
name|u16
name|OSAL_UNUSED
modifier|*
name|fw_minor
parameter_list|,
name|u16
name|OSAL_UNUSED
modifier|*
name|fw_rev
parameter_list|,
name|u16
name|OSAL_UNUSED
modifier|*
name|fw_eng
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_vf_bulletin_get_udp_ports
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|OSAL_UNUSED
modifier|*
name|p_vxlan_port
parameter_list|,
name|u16
name|OSAL_UNUSED
modifier|*
name|p_geneve_port
parameter_list|)
block|{
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

