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
name|VXGE_HAL_LEGACY_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_LEGACY_REGS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_legacy_reg_t
block|{
name|u8
name|unused00010
index|[
literal|0x00010
index|]
decl_stmt|;
comment|/* 0x00010 */
name|u64
name|toc_swapper_fb
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_SWAPPER_FB_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00018 */
name|u64
name|pifm_rd_swap_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PIFM_RD_SWAP_EN_PIFM_RD_SWAP_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00020 */
name|u64
name|pifm_rd_flip_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PIFM_RD_FLIP_EN_PIFM_RD_FLIP_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00028 */
name|u64
name|pifm_wr_swap_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PIFM_WR_SWAP_EN_PIFM_WR_SWAP_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00030 */
name|u64
name|pifm_wr_flip_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PIFM_WR_FLIP_EN_PIFM_WR_FLIP_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00038 */
name|u64
name|toc_first_pointer
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_FIRST_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00040 */
name|u64
name|host_access_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_HOST_ACCESS_EN_HOST_ACCESS_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
block|}
name|vxge_hal_legacy_reg_t
typedef|;
end_typedef

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_LEGACY_REGS_H */
end_comment

end_unit

