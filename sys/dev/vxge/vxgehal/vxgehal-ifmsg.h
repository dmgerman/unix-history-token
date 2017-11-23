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
name|VXGE_HAL_IFMSG_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_IFMSG_H
end_define

begin_function
name|__EXTERN_BEGIN_DECLS
define|#
directive|define
name|VXGE_HAL_IFMSG_PRIV_DRIVER_UP_MSG
define|\
value|VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE(VXGE_HAL_IFMSG_MSV_OPCODE_UP)
define|#
directive|define
name|VXGE_HAL_IFMSG_PRIV_DRIVER_DOWN_MSG
define|\
value|VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE(VXGE_HAL_IFMSG_MSV_OPCODE_DOWN)
define|#
directive|define
name|VXGE_HAL_IFMSG_DEVICE_RESET_BEGIN_MSG
define|\
value|VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE(			\ 	VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE_DEVICE_RESET_BEGIN)
define|#
directive|define
name|VXGE_HAL_IFMSG_DEVICE_RESET_END_MSG
define|\
value|VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE(			\ 	VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE_DEVICE_RESET_END)
specifier|static
specifier|inline
name|u32
comment|/* LINTED */
name|__hal_ifmsg_is_manager_up
parameter_list|(
name|u64
name|wmsg
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|u32
operator|)
name|VXGE_HAL_RTS_ACCESS_STEER_DATA0_GET_MSG_TYPE
argument_list|(
name|wmsg
argument_list|)
operator|==
name|VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE_PRIV_DRIVER_UP
operator|)
operator|||
operator|(
operator|(
name|u32
operator|)
name|VXGE_HAL_RTS_ACCESS_STEER_DATA0_GET_MSG_TYPE
argument_list|(
name|wmsg
argument_list|)
operator|==
name|VXGE_HAL_RTS_ACCESS_STEER_DATA0_MSG_TYPE_DEVICE_RESET_END
operator|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|vxge_hal_status_e
name|__hal_ifmsg_device_reset_end_poll
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|vp_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ifmsg_wmsg_process
parameter_list|(
name|__hal_virtualpath_t
modifier|*
name|vpath
parameter_list|,
name|u64
name|wmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_ifmsg_wmsg_post
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|src_vp_id
parameter_list|,
name|u32
name|dest_vp_id
parameter_list|,
name|u32
name|msg_type
parameter_list|,
name|u32
name|msg_data
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
comment|/* VXGE_HAL_IFMSG_H */
end_comment

end_unit

