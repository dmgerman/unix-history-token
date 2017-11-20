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
name|VXGE_HAL_TOC_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_TOC_REGS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_toc_reg_t
block|{
name|u8
name|unused00050
index|[
literal|0x00050
index|]
decl_stmt|;
comment|/* 0x00050 */
name|u64
name|toc_common_pointer
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_COMMON_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00058 */
name|u64
name|toc_memrepair_pointer
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_MEMREPAIR_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00060 */
name|u64
name|toc_pcicfgmgmt_pointer
index|[
literal|17
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_PCICFGMGMT_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
name|u8
name|unused001e0
index|[
literal|0x001e0
operator|-
literal|0x000e8
index|]
decl_stmt|;
comment|/* 0x001e0 */
name|u64
name|toc_mrpcim_pointer
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_MRPCIM_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x001e8 */
name|u64
name|toc_srpcim_pointer
index|[
literal|17
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_SRPCIM_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
name|u8
name|unused00278
index|[
literal|0x00278
operator|-
literal|0x00270
index|]
decl_stmt|;
comment|/* 0x00278 */
name|u64
name|toc_vpmgmt_pointer
index|[
literal|17
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_VPMGMT_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
name|u8
name|unused00390
index|[
literal|0x00390
operator|-
literal|0x00300
index|]
decl_stmt|;
comment|/* 0x00390 */
name|u64
name|toc_vpath_pointer
index|[
literal|17
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_VPATH_POINTER_INITIAL_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
name|u8
name|unused004a0
index|[
literal|0x004a0
operator|-
literal|0x00418
index|]
decl_stmt|;
comment|/* 0x004a0 */
name|u64
name|toc_kdfc
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_KDFC_INITIAL_OFFSET
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 61)
define|#
directive|define
name|VXGE_HAL_TOC_KDFC_INITIAL_BIR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 61, 3)
comment|/* 0x004a8 */
name|u64
name|toc_usdc
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_USDC_INITIAL_OFFSET
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 61)
define|#
directive|define
name|VXGE_HAL_TOC_USDC_INITIAL_BIR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 61, 3)
comment|/* 0x004b0 */
name|u64
name|toc_kdfc_vpath_stride
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_KDFC_VPATH_STRIDE_INITIAL_TOC_KDFC_VPATH_STRIDE
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 64)
comment|/* 0x004b8 */
name|u64
name|toc_kdfc_fifo_stride
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TOC_KDFC_FIFO_STRIDE_INITIAL_TOC_KDFC_FIFO_STRIDE
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 64)
block|}
name|vxge_hal_toc_reg_t
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
comment|/* VXGE_HAL_TOC_REGS_H */
end_comment

end_unit

