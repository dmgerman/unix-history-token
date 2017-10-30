begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_SP_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_SP_H
end_define

begin_include
include|#
directive|include
file|"common/general.h"
end_include

begin_include
include|#
directive|include
file|"fsl_fman.h"
end_include

begin_struct
struct|struct
name|fm_pcd_storage_profile_regs
block|{
name|uint32_t
name|fm_sp_ebmpi
index|[
literal|8
index|]
decl_stmt|;
comment|/*offset 0 - 0xc*/
comment|/**< Buffer Manager pool Information */
name|uint32_t
name|fm_sp_acnt
decl_stmt|;
comment|/*offset 0x20*/
name|uint32_t
name|fm_sp_ebm
decl_stmt|;
comment|/*offset 0x24*/
name|uint32_t
name|fm_sp_da
decl_stmt|;
comment|/*offset 0x28*/
name|uint32_t
name|fm_sp_icp
decl_stmt|;
comment|/*offset 0x2c*/
name|uint32_t
name|fm_sp_mpd
decl_stmt|;
comment|/*offset 0x30*/
name|uint32_t
name|res1
index|[
literal|2
index|]
decl_stmt|;
comment|/*offset 0x34 - 0x38*/
name|uint32_t
name|fm_sp_spliodn
decl_stmt|;
comment|/*offset 0x3c*/
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining internal context copying */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_struct
struct|struct
name|fman_sp_int_context_data_copy
block|{
name|uint16_t
name|ext_buf_offset
decl_stmt|;
comment|/**< Offset in External buffer to which 					internal context is copied to (Rx) 					or taken from (Tx, Op). */
name|uint8_t
name|int_context_offset
decl_stmt|;
comment|/**< Offset within internal context to copy 					from (Rx) or to copy to (Tx, Op).*/
name|uint16_t
name|size
decl_stmt|;
comment|/**< Internal offset size to be copied */
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining external buffer margins */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_struct
struct|struct
name|fman_sp_buf_margins
block|{
name|uint16_t
name|start_margins
decl_stmt|;
comment|/**< Number of bytes to be left at the 				beginning of the external buffer (must be 				divisible by 16) */
name|uint16_t
name|end_margins
decl_stmt|;
comment|/**< number of bytes to be left at the end of 				 the external buffer(must be divisible by 16)*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fm_storage_profile_params
block|{
name|struct
name|fman_ext_pools
name|fm_ext_pools
decl_stmt|;
name|struct
name|fman_backup_bm_pools
name|backup_pools
decl_stmt|;
name|struct
name|fman_sp_int_context_data_copy
modifier|*
name|int_context
decl_stmt|;
name|struct
name|fman_sp_buf_margins
modifier|*
name|buf_margins
decl_stmt|;
name|enum
name|fman_dma_swap_option
name|dma_swap_data
decl_stmt|;
name|enum
name|fman_dma_cache_option
name|int_context_cache_attr
decl_stmt|;
name|enum
name|fman_dma_cache_option
name|header_cache_attr
decl_stmt|;
name|enum
name|fman_dma_cache_option
name|scatter_gather_cache_attr
decl_stmt|;
name|bool
name|dma_write_optimize
decl_stmt|;
name|uint16_t
name|liodn_offset
decl_stmt|;
name|bool
name|no_scather_gather
decl_stmt|;
name|struct
name|fman_buf_pool_depletion
name|buf_pool_depletion
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Registers bit fields */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FMAN_SP_EXT_BUF_POOL_EN_COUNTER
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FMAN_SP_EXT_BUF_POOL_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FMAN_SP_EXT_BUF_POOL_BACKUP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FMAN_SP_DMA_ATTR_WRITE_OPTIMIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|FMAN_SP_SG_DISABLE
value|0x80000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|FMAN_SP_EXT_BUF_POOL_ID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_SP_POOL_DEP_NUM_OF_POOLS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_SP_EXT_BUF_MARG_START_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_SP_EXT_BUF_MARG_END_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FMAN_SP_DMA_ATTR_SWP_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|FMAN_SP_DMA_ATTR_IC_CACHE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|FMAN_SP_DMA_ATTR_HDR_CACHE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|FMAN_SP_DMA_ATTR_SG_CACHE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FMAN_SP_IC_TO_EXT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_SP_IC_FROM_INT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FMAN_SP_IC_SIZE_SHIFT
value|0
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       defaults */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FMAN_SP_DMA_SWAP_DATA
value|FMAN_DMA_NO_SWP
end_define

begin_define
define|#
directive|define
name|DEFAULT_FMAN_SP_DMA_INT_CONTEXT_CACHE_ATTR
value|FMAN_DMA_NO_STASH
end_define

begin_define
define|#
directive|define
name|DEFAULT_FMAN_SP_DMA_HEADER_CACHE_ATTR
value|FMAN_DMA_NO_STASH
end_define

begin_define
define|#
directive|define
name|DEFAULT_FMAN_SP_DMA_SCATTER_GATHER_CACHE_ATTR
value|FMAN_DMA_NO_STASH
end_define

begin_define
define|#
directive|define
name|DEFAULT_FMAN_SP_DMA_WRITE_OPTIMIZE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_FMAN_SP_NO_SCATTER_GATHER
value|FALSE
end_define

begin_function_decl
name|void
name|fman_vsp_defconfig
parameter_list|(
name|struct
name|fm_storage_profile_params
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_vsp_init
parameter_list|(
name|struct
name|fm_pcd_storage_profile_regs
modifier|*
name|regs
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|struct
name|fm_storage_profile_params
modifier|*
name|fm_vsp_params
parameter_list|,
name|int
name|port_max_num_of_ext_pools
parameter_list|,
name|int
name|bm_max_num_of_pools
parameter_list|,
name|int
name|max_num_of_pfc_priorities
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_vsp_get_statistics
parameter_list|(
name|struct
name|fm_pcd_storage_profile_regs
modifier|*
name|regs
parameter_list|,
name|uint16_t
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_vsp_set_statistics
parameter_list|(
name|struct
name|fm_pcd_storage_profile_regs
modifier|*
name|regs
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_FMAN_SP_H */
end_comment

end_unit

