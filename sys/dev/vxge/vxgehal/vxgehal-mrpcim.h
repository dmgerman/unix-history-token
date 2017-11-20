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
name|VXGE_HAL_MRPCIM_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_MRPCIM_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/*  * __hal_mrpcim_t  *  * HAL mrpcim object. Represents privileged mode device.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__hal_mrpcim_t
block|{
name|u32
name|mdio_phy_prtad0
decl_stmt|;
name|u32
name|mdio_phy_prtad1
decl_stmt|;
name|u32
name|mdio_dte_prtad0
decl_stmt|;
name|u32
name|mdio_dte_prtad1
decl_stmt|;
name|vxge_hal_vpd_data_t
name|vpd_data
decl_stmt|;
name|__hal_blockpool_entry_t
modifier|*
name|mrpcim_stats_block
decl_stmt|;
name|vxge_hal_mrpcim_stats_hw_info_t
modifier|*
name|mrpcim_stats
decl_stmt|;
name|vxge_hal_mrpcim_stats_hw_info_t
name|mrpcim_stats_sav
decl_stmt|;
name|vxge_hal_mrpcim_xpak_stats_t
name|xpak_stats
index|[
name|VXGE_HAL_MAC_MAX_WIRE_PORTS
index|]
decl_stmt|;
block|}
name|__hal_mrpcim_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VXGE_HAL_MRPCIM_STATS_PIO_READ
parameter_list|(
name|loc
parameter_list|,
name|offset
parameter_list|)
value|{			\ 	status = vxge_hal_mrpcim_stats_access(devh,			\ 				VXGE_HAL_STATS_OP_READ,			\ 				loc,					\ 				offset,					\&val64);				\ 									\ 	if (status != VXGE_HAL_OK) {					\ 		vxge_hal_trace_log_stats("<== %s:%s:%d Result = %d",	\ 				__FILE__, __func__, __LINE__, status);	\ 		return (status);					\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MRPCIM_ERROR_REG_CLEAR
parameter_list|(
name|reg
parameter_list|)
define|\
value|vxge_os_pio_mem_write64(					\ 		hldev->header.pdev,					\ 		hldev->header.regh0,					\ 		VXGE_HAL_INTR_MASK_ALL,					\ 		(reg));
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MRPCIM_ERROR_REG_MASK
parameter_list|(
name|reg
parameter_list|)
define|\
value|vxge_os_pio_mem_write64(					\ 		hldev->header.pdev,					\ 		hldev->header.regh0,					\ 		VXGE_HAL_INTR_MASK_ALL,					\ 		(reg));
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_MRPCIM_ERROR_REG_UNMASK
parameter_list|(
name|mask
parameter_list|,
name|reg
parameter_list|)
define|\
value|vxge_os_pio_mem_write64(					\ 		hldev->header.pdev,					\ 		hldev->header.regh0,					\ 		~mask,							\ 		(reg));
end_define

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_mdio_access
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|port
parameter_list|,
name|u32
name|operation
parameter_list|,
name|u32
name|device
parameter_list|,
name|u16
name|addr
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_rts_table_access
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|action
parameter_list|,
name|u32
name|rts_table
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
modifier|*
name|data1
parameter_list|,
name|u64
modifier|*
name|data2
parameter_list|,
name|u64
modifier|*
name|vpath_vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_initialize
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_terminate
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_mrpcim_get_vpd_data
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_mrpcim_xpak_counter_check
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|port
parameter_list|,
name|u32
name|type
parameter_list|,
name|u32
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_stats_get
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|,
name|vxge_hal_mrpcim_stats_hw_info_t
modifier|*
name|mrpcim_stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_mac_configure
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_mrpcim_lag_configure
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
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
comment|/* VXGE_HAL_MRPCIM_H */
end_comment

end_unit

