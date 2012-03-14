begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This file provides bootbus flash operations  *  *<hr>$Revision: 70030 $<hr>  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_FLASH_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_FLASH_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
struct|struct
block|{
name|int
name|start_offset
decl_stmt|;
name|int
name|block_size
decl_stmt|;
name|int
name|num_blocks
decl_stmt|;
block|}
name|cvmx_flash_region_t
typedef|;
comment|/**  * Initialize the flash access library  */
name|void
name|cvmx_flash_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Return a pointer to the flash chip  *  * @param chip_id Chip ID to return  * @return NULL if the chip doesn't exist  */
name|void
modifier|*
name|cvmx_flash_get_base
parameter_list|(
name|int
name|chip_id
parameter_list|)
function_decl|;
comment|/**  * Return the number of erasable regions on the chip  *  * @param chip_id Chip to return info for  * @return Number of regions  */
name|int
name|cvmx_flash_get_num_regions
parameter_list|(
name|int
name|chip_id
parameter_list|)
function_decl|;
comment|/**  * Return information about a flash chips region  *  * @param chip_id Chip to get info for  * @param region  Region to get info for  * @return Region information  */
specifier|const
name|cvmx_flash_region_t
modifier|*
name|cvmx_flash_get_region_info
parameter_list|(
name|int
name|chip_id
parameter_list|,
name|int
name|region
parameter_list|)
function_decl|;
comment|/**  * Erase a block on the flash chip  *  * @param chip_id Chip to erase a block on  * @param region  Region to erase a block in  * @param block   Block number to erase  * @return Zero on success. Negative on failure  */
name|int
name|cvmx_flash_erase_block
parameter_list|(
name|int
name|chip_id
parameter_list|,
name|int
name|region
parameter_list|,
name|int
name|block
parameter_list|)
function_decl|;
comment|/**  * Write a block on the flash chip  *  * @param chip_id Chip to write a block on  * @param region  Region to write a block in  * @param block   Block number to write  * @param data    Data to write  * @return Zero on success. Negative on failure  */
name|int
name|cvmx_flash_write_block
parameter_list|(
name|int
name|chip_id
parameter_list|,
name|int
name|region
parameter_list|,
name|int
name|block
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Erase and write data to a flash  *  * @param address Memory address to write to  * @param data    Data to write  * @param len     Length of the data  * @return Zero on success. Negative on failure  */
name|int
name|cvmx_flash_write
parameter_list|(
name|void
modifier|*
name|address
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_FLASH_H__ */
end_comment

end_unit

