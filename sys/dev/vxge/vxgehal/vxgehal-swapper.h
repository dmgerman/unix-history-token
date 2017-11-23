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
name|VXGE_HAL_SWAPPER_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_SWAPPER_H
end_define

begin_function_decl
name|__EXTERN_BEGIN_DECLS
define|#
directive|define
name|VXGE_HAL_SWAPPER_INITIAL_VALUE
value|0x0123456789abcdefULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_BYTE_SWAPPED
value|0xefcdab8967452301ULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_BIT_FLIPPED
value|0x80c4a2e691d5b3f7ULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_BYTE_SWAPPED_BIT_FLIPPED
value|0xf7b3d591e6a2c480ULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_READ_BYTE_SWAP_ENABLE
value|0xFFFFFFFFFFFFFFFFULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_READ_BYTE_SWAP_DISABLE
value|0x0000000000000000ULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_READ_BIT_FLAP_ENABLE
value|0xFFFFFFFFFFFFFFFFULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_READ_BIT_FLAP_DISABLE
value|0x0000000000000000ULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_WRITE_BYTE_SWAP_ENABLE
value|0xFFFFFFFFFFFFFFFFULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_WRITE_BYTE_SWAP_DISABLE
value|0x0000000000000000ULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_WRITE_BIT_FLAP_ENABLE
value|0xFFFFFFFFFFFFFFFFULL
define|#
directive|define
name|VXGE_HAL_SWAPPER_WRITE_BIT_FLAP_DISABLE
value|0x0000000000000000ULL
name|vxge_hal_status_e
name|__hal_legacy_swapper_set
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|vxge_hal_legacy_reg_t
modifier|*
name|legacy_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_vpath_swapper_set
parameter_list|(
name|vxge_hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|vp_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_kdfc_swapper_set
parameter_list|(
name|vxge_hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|vp_id
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
comment|/* VXGE_HAL_SWAPPER_H */
end_comment

end_unit

