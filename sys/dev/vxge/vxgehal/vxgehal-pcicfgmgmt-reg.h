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
name|VXGE_HAL_PCICFGMGMT_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_PCICFGMGMT_REGS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pcicfgmgmt_reg_t
block|{
comment|/* 0x00000 */
name|u64
name|resource_no
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RESOURCE_NO_PFN_OR_VF
value|BIT(3)
comment|/* 0x00008 */
name|u64
name|bargrp_pf_or_vf_bar0_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_BARGRP_PF_OR_VF_BAR0_MASK_BARGRP_PF_OR_VF_BAR0_MASK
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 2, 6)
comment|/* 0x00010 */
name|u64
name|bargrp_pf_or_vf_bar1_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_BARGRP_PF_OR_VF_BAR1_MASK_BARGRP_PF_OR_VF_BAR1_MASK
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 2, 6)
comment|/* 0x00018 */
name|u64
name|bargrp_pf_or_vf_bar2_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_BARGRP_PF_OR_VF_BAR2_MASK_BARGRP_PF_OR_VF_BAR2_MASK
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 2, 6)
comment|/* 0x00020 */
name|u64
name|msixgrp_no
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSIXGRP_NO_TABLE_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 5, 11)
block|}
name|vxge_hal_pcicfgmgmt_reg_t
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
comment|/* VXGE_HAL_PCICFGMGMT_REGS_H */
end_comment

end_unit

