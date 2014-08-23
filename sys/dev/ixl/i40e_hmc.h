begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_HMC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_HMC_H_
end_define

begin_define
define|#
directive|define
name|I40E_HMC_MAX_BP_COUNT
value|512
end_define

begin_comment
comment|/* forward-declare the HW struct for the compiler */
end_comment

begin_struct_decl
struct_decl|struct
name|i40e_hw
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|I40E_HMC_INFO_SIGNATURE
value|0x484D5347
end_define

begin_comment
comment|/* HMSG */
end_comment

begin_define
define|#
directive|define
name|I40E_HMC_PD_CNT_IN_SD
value|512
end_define

begin_define
define|#
directive|define
name|I40E_HMC_DIRECT_BP_SIZE
value|0x200000
end_define

begin_comment
comment|/* 2M */
end_comment

begin_define
define|#
directive|define
name|I40E_HMC_PAGED_BP_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|I40E_HMC_PD_BP_BUF_ALIGNMENT
value|4096
end_define

begin_define
define|#
directive|define
name|I40E_FIRST_VF_FPM_ID
value|16
end_define

begin_struct
struct|struct
name|i40e_hmc_obj_info
block|{
name|u64
name|base
decl_stmt|;
comment|/* base addr in FPM */
name|u32
name|max_cnt
decl_stmt|;
comment|/* max count available for this hmc func */
name|u32
name|cnt
decl_stmt|;
comment|/* count of objects driver actually wants to create */
name|u64
name|size
decl_stmt|;
comment|/* size in bytes of one object */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|i40e_sd_entry_type
block|{
name|I40E_SD_TYPE_INVALID
init|=
literal|0
block|,
name|I40E_SD_TYPE_PAGED
init|=
literal|1
block|,
name|I40E_SD_TYPE_DIRECT
init|=
literal|2
block|}
enum|;
end_enum

begin_struct
struct|struct
name|i40e_hmc_bp
block|{
name|enum
name|i40e_sd_entry_type
name|entry_type
decl_stmt|;
name|struct
name|i40e_dma_mem
name|addr
decl_stmt|;
comment|/* populate to be used by hw */
name|u32
name|sd_pd_index
decl_stmt|;
name|u32
name|ref_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_hmc_pd_entry
block|{
name|struct
name|i40e_hmc_bp
name|bp
decl_stmt|;
name|u32
name|sd_index
decl_stmt|;
name|bool
name|valid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_hmc_pd_table
block|{
name|struct
name|i40e_dma_mem
name|pd_page_addr
decl_stmt|;
comment|/* populate to be used by hw */
name|struct
name|i40e_hmc_pd_entry
modifier|*
name|pd_entry
decl_stmt|;
comment|/* [512] for sw book keeping */
name|struct
name|i40e_virt_mem
name|pd_entry_virt_mem
decl_stmt|;
comment|/* virt mem for pd_entry */
name|u32
name|ref_cnt
decl_stmt|;
name|u32
name|sd_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_hmc_sd_entry
block|{
name|enum
name|i40e_sd_entry_type
name|entry_type
decl_stmt|;
name|bool
name|valid
decl_stmt|;
union|union
block|{
name|struct
name|i40e_hmc_pd_table
name|pd_table
decl_stmt|;
name|struct
name|i40e_hmc_bp
name|bp
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_hmc_sd_table
block|{
name|struct
name|i40e_virt_mem
name|addr
decl_stmt|;
comment|/* used to track sd_entry allocations */
name|u32
name|sd_cnt
decl_stmt|;
name|u32
name|ref_cnt
decl_stmt|;
name|struct
name|i40e_hmc_sd_entry
modifier|*
name|sd_entry
decl_stmt|;
comment|/* (sd_cnt*512) entries max */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_hmc_info
block|{
name|u32
name|signature
decl_stmt|;
comment|/* equals to pci func num for PF and dynamically allocated for VFs */
name|u8
name|hmc_fn_id
decl_stmt|;
name|u16
name|first_sd_index
decl_stmt|;
comment|/* index of the first available SD */
comment|/* hmc objects */
name|struct
name|i40e_hmc_obj_info
modifier|*
name|hmc_obj
decl_stmt|;
name|struct
name|i40e_virt_mem
name|hmc_obj_virt_mem
decl_stmt|;
name|struct
name|i40e_hmc_sd_table
name|sd_table
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_INC_SD_REFCNT
parameter_list|(
name|sd_table
parameter_list|)
value|((sd_table)->ref_cnt++)
end_define

begin_define
define|#
directive|define
name|I40E_INC_PD_REFCNT
parameter_list|(
name|pd_table
parameter_list|)
value|((pd_table)->ref_cnt++)
end_define

begin_define
define|#
directive|define
name|I40E_INC_BP_REFCNT
parameter_list|(
name|bp
parameter_list|)
value|((bp)->ref_cnt++)
end_define

begin_define
define|#
directive|define
name|I40E_DEC_SD_REFCNT
parameter_list|(
name|sd_table
parameter_list|)
value|((sd_table)->ref_cnt--)
end_define

begin_define
define|#
directive|define
name|I40E_DEC_PD_REFCNT
parameter_list|(
name|pd_table
parameter_list|)
value|((pd_table)->ref_cnt--)
end_define

begin_define
define|#
directive|define
name|I40E_DEC_BP_REFCNT
parameter_list|(
name|bp
parameter_list|)
value|((bp)->ref_cnt--)
end_define

begin_comment
comment|/**  * I40E_SET_PF_SD_ENTRY - marks the sd entry as valid in the hardware  * @hw: pointer to our hw struct  * @pa: pointer to physical address  * @sd_index: segment descriptor index  * @type: if sd entry is direct or paged  **/
end_comment

begin_define
define|#
directive|define
name|I40E_SET_PF_SD_ENTRY
parameter_list|(
name|hw
parameter_list|,
name|pa
parameter_list|,
name|sd_index
parameter_list|,
name|type
parameter_list|)
define|\
value|{									\ 	u32 val1, val2, val3;						\ 	val1 = (u32)(I40E_HI_DWORD(pa));				\ 	val2 = (u32)(pa) | (I40E_HMC_MAX_BP_COUNT<<			\ 		 I40E_PFHMC_SDDATALOW_PMSDBPCOUNT_SHIFT) |		\ 		((((type) == I40E_SD_TYPE_PAGED) ? 0 : 1)<<		\ 		I40E_PFHMC_SDDATALOW_PMSDTYPE_SHIFT) |			\ 		(1<< I40E_PFHMC_SDDATALOW_PMSDVALID_SHIFT);		\ 	val3 = (sd_index) | (1u<< I40E_PFHMC_SDCMD_PMSDWR_SHIFT);	\ 	wr32((hw), I40E_PFHMC_SDDATAHIGH, val1);			\ 	wr32((hw), I40E_PFHMC_SDDATALOW, val2);				\ 	wr32((hw), I40E_PFHMC_SDCMD, val3);				\ }
end_define

begin_comment
comment|/**  * I40E_CLEAR_PF_SD_ENTRY - marks the sd entry as invalid in the hardware  * @hw: pointer to our hw struct  * @sd_index: segment descriptor index  * @type: if sd entry is direct or paged  **/
end_comment

begin_define
define|#
directive|define
name|I40E_CLEAR_PF_SD_ENTRY
parameter_list|(
name|hw
parameter_list|,
name|sd_index
parameter_list|,
name|type
parameter_list|)
define|\
value|{									\ 	u32 val2, val3;							\ 	val2 = (I40E_HMC_MAX_BP_COUNT<<				\ 		I40E_PFHMC_SDDATALOW_PMSDBPCOUNT_SHIFT) |		\ 		((((type) == I40E_SD_TYPE_PAGED) ? 0 : 1)<<		\ 		I40E_PFHMC_SDDATALOW_PMSDTYPE_SHIFT);			\ 	val3 = (sd_index) | (1u<< I40E_PFHMC_SDCMD_PMSDWR_SHIFT);	\ 	wr32((hw), I40E_PFHMC_SDDATAHIGH, 0);				\ 	wr32((hw), I40E_PFHMC_SDDATALOW, val2);				\ 	wr32((hw), I40E_PFHMC_SDCMD, val3);				\ }
end_define

begin_comment
comment|/**  * I40E_INVALIDATE_PF_HMC_PD - Invalidates the pd cache in the hardware  * @hw: pointer to our hw struct  * @sd_idx: segment descriptor index  * @pd_idx: page descriptor index  **/
end_comment

begin_define
define|#
directive|define
name|I40E_INVALIDATE_PF_HMC_PD
parameter_list|(
name|hw
parameter_list|,
name|sd_idx
parameter_list|,
name|pd_idx
parameter_list|)
define|\
value|wr32((hw), I40E_PFHMC_PDINV,					\ 	    (((sd_idx)<< I40E_PFHMC_PDINV_PMSDIDX_SHIFT) |		\ 	     ((pd_idx)<< I40E_PFHMC_PDINV_PMPDIDX_SHIFT)))
end_define

begin_comment
comment|/**  * I40E_FIND_SD_INDEX_LIMIT - finds segment descriptor index limit  * @hmc_info: pointer to the HMC configuration information structure  * @type: type of HMC resources we're searching  * @index: starting index for the object  * @cnt: number of objects we're trying to create  * @sd_idx: pointer to return index of the segment descriptor in question  * @sd_limit: pointer to return the maximum number of segment descriptors  *  * This function calculates the segment descriptor index and index limit  * for the resource defined by i40e_hmc_rsrc_type.  **/
end_comment

begin_define
define|#
directive|define
name|I40E_FIND_SD_INDEX_LIMIT
parameter_list|(
name|hmc_info
parameter_list|,
name|type
parameter_list|,
name|index
parameter_list|,
name|cnt
parameter_list|,
name|sd_idx
parameter_list|,
name|sd_limit
parameter_list|)
define|\
value|{									\ 	u64 fpm_addr, fpm_limit;					\ 	fpm_addr = (hmc_info)->hmc_obj[(type)].base +			\ 		   (hmc_info)->hmc_obj[(type)].size * (index);		\ 	fpm_limit = fpm_addr + (hmc_info)->hmc_obj[(type)].size * (cnt);\ 	*(sd_idx) = (u32)(fpm_addr / I40E_HMC_DIRECT_BP_SIZE);		\ 	*(sd_limit) = (u32)((fpm_limit - 1) / I40E_HMC_DIRECT_BP_SIZE);	\
comment|/* add one more to the limit to correct our range */
value|\ 	*(sd_limit) += 1;						\ }
end_define

begin_comment
comment|/**  * I40E_FIND_PD_INDEX_LIMIT - finds page descriptor index limit  * @hmc_info: pointer to the HMC configuration information struct  * @type: HMC resource type we're examining  * @idx: starting index for the object  * @cnt: number of objects we're trying to create  * @pd_index: pointer to return page descriptor index  * @pd_limit: pointer to return page descriptor index limit  *  * Calculates the page descriptor index and index limit for the resource  * defined by i40e_hmc_rsrc_type.  **/
end_comment

begin_define
define|#
directive|define
name|I40E_FIND_PD_INDEX_LIMIT
parameter_list|(
name|hmc_info
parameter_list|,
name|type
parameter_list|,
name|idx
parameter_list|,
name|cnt
parameter_list|,
name|pd_index
parameter_list|,
name|pd_limit
parameter_list|)
define|\
value|{									\ 	u64 fpm_adr, fpm_limit;						\ 	fpm_adr = (hmc_info)->hmc_obj[(type)].base +			\ 		  (hmc_info)->hmc_obj[(type)].size * (idx);		\ 	fpm_limit = fpm_adr + (hmc_info)->hmc_obj[(type)].size * (cnt);	\ 	*(pd_index) = (u32)(fpm_adr / I40E_HMC_PAGED_BP_SIZE);		\ 	*(pd_limit) = (u32)((fpm_limit - 1) / I40E_HMC_PAGED_BP_SIZE);	\
comment|/* add one more to the limit to correct our range */
value|\ 	*(pd_limit) += 1;						\ }
end_define

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_add_sd_table_entry
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_hmc_info
modifier|*
name|hmc_info
parameter_list|,
name|u32
name|sd_index
parameter_list|,
name|enum
name|i40e_sd_entry_type
name|type
parameter_list|,
name|u64
name|direct_mode_sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_add_pd_table_entry
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_hmc_info
modifier|*
name|hmc_info
parameter_list|,
name|u32
name|pd_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_remove_pd_bp
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_hmc_info
modifier|*
name|hmc_info
parameter_list|,
name|u32
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_prep_remove_sd_bp
parameter_list|(
name|struct
name|i40e_hmc_info
modifier|*
name|hmc_info
parameter_list|,
name|u32
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_remove_sd_bp_new
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_hmc_info
modifier|*
name|hmc_info
parameter_list|,
name|u32
name|idx
parameter_list|,
name|bool
name|is_pf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_prep_remove_pd_page
parameter_list|(
name|struct
name|i40e_hmc_info
modifier|*
name|hmc_info
parameter_list|,
name|u32
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_remove_pd_page_new
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_hmc_info
modifier|*
name|hmc_info
parameter_list|,
name|u32
name|idx
parameter_list|,
name|bool
name|is_pf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_HMC_H_ */
end_comment

end_unit

