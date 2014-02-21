begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_COMPACTFLASH_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_COMPACTFLASH_H__
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
comment|/**  * This function takes values from the compact flash device  * identify response, and returns the appropriate value to write  * into the boot bus DMA timing register.  *  * @param tim_mult   Eclock timing multiple to use  * @param ident_data Data returned by the 'identify' command.  This is used to  *                   determine the DMA modes supported by the card, if any.  * @param mwdma_mode_ptr  *                   Optional pointer to return MWDMA mode in  *  * @return 64 bit value to write to DMA timing register  */
specifier|extern
name|uint64_t
name|cvmx_compactflash_generate_dma_tim
parameter_list|(
name|int
name|tim_mult
parameter_list|,
name|uint16_t
modifier|*
name|ident_data
parameter_list|,
name|int
modifier|*
name|mwdma_mode_ptr
parameter_list|)
function_decl|;
comment|/**  * Setup timing and region config to support a specific IDE PIO  * mode over the bootbus.  *  * @param cs0      Bootbus region number connected to CS0 on the IDE device  * @param cs1      Bootbus region number connected to CS1 on the IDE device  * @param pio_mode PIO mode to set (0-6)  */
specifier|extern
name|void
name|cvmx_compactflash_set_piomode
parameter_list|(
name|int
name|cs0
parameter_list|,
name|int
name|cs1
parameter_list|,
name|int
name|pio_mode
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
comment|/* __CVMX_COMPACTFLASH_H__ */
end_comment

end_unit

