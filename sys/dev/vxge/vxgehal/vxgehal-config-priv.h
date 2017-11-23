begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGEHAL_CONFIG_PRIV_H
end_ifndef

begin_define
define|#
directive|define
name|XGEHAL_CONFIG_PRIV_H
end_define

begin_function_decl
name|__EXTERN_BEGIN_DECLS
name|vxge_hal_status_e
name|vxge_hal_driver_config_check
parameter_list|(
name|vxge_hal_driver_config_t
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_mac_config_check
parameter_list|(
name|vxge_hal_mac_config_t
modifier|*
name|mac_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_vpath_qos_config_check
parameter_list|(
name|vxge_hal_vpath_qos_config_t
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_config_check
parameter_list|(
name|vxge_hal_mrpcim_config_t
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_ring_config_check
parameter_list|(
name|vxge_hal_ring_config_t
modifier|*
name|ring_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_fifo_config_check
parameter_list|(
name|vxge_hal_fifo_config_t
modifier|*
name|fifo_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_lag_config_check
parameter_list|(
name|vxge_hal_lag_config_t
modifier|*
name|lag_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_lag_port_config_check
parameter_list|(
name|vxge_hal_lag_port_config_t
modifier|*
name|port_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_lag_aggr_config_check
parameter_list|(
name|vxge_hal_lag_aggr_config_t
modifier|*
name|aggr_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_lag_la_config_check
parameter_list|(
name|vxge_hal_lag_la_config_t
modifier|*
name|la_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_lag_ap_config_check
parameter_list|(
name|vxge_hal_lag_ap_config_t
modifier|*
name|ap_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_lag_sl_config_check
parameter_list|(
name|vxge_hal_lag_sl_config_t
modifier|*
name|sl_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_lag_lacp_config_check
parameter_list|(
name|vxge_hal_lag_lacp_config_t
modifier|*
name|lacp_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_wire_port_config_check
parameter_list|(
name|vxge_hal_wire_port_config_t
modifier|*
name|port_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_switch_port_config_check
parameter_list|(
name|vxge_hal_switch_port_config_t
modifier|*
name|port_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_tim_intr_config_check
parameter_list|(
name|vxge_hal_tim_intr_config_t
modifier|*
name|tim_intr_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_vpath_config_check
parameter_list|(
name|vxge_hal_vp_config_t
modifier|*
name|vp_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_device_config_check
parameter_list|(
name|vxge_hal_device_config_t
modifier|*
name|new_config
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGEHAL_CONFIG_PRIV_H */
end_comment

end_unit

