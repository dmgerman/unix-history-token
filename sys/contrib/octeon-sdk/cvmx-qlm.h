begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2011  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Helper utilities for qlm.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_QLM_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_QLM_H__
end_define

begin_include
include|#
directive|include
file|"cvmx.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|stop_bit
decl_stmt|;
name|int
name|start_bit
decl_stmt|;
block|}
name|__cvmx_qlm_jtag_field_t
typedef|;
end_typedef

begin_comment
comment|/**  * Return the number of QLMs supported by the chip  *   * @return  Number of QLMs  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_qlm_get_num
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the qlm number based on the interface  *  * @param interface  Interface to look up  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_qlm_interface
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return number of lanes for a given qlm  *   * @return  Number of lanes  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_qlm_get_lanes
parameter_list|(
name|int
name|qlm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the QLM JTAG fields based on Octeon model on the supported chips.   *  * @return  qlm_jtag_field_t structure  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|__cvmx_qlm_jtag_field_t
modifier|*
name|cvmx_qlm_jtag_get_field
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the QLM JTAG length by going through qlm_jtag_field for each  * Octeon model that is supported  *  * @return return the length.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_qlm_jtag_get_length
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize the QLM layer  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cvmx_qlm_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get a field in a QLM JTAG chain  *  * @param qlm    QLM to get  * @param lane   Lane in QLM to get  * @param name   String name of field  *  * @return JTAG field value  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|cvmx_qlm_jtag_get
parameter_list|(
name|int
name|qlm
parameter_list|,
name|int
name|lane
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set a field in a QLM JTAG chain  *  * @param qlm    QLM to set  * @param lane   Lane in QLM to set, or -1 for all lanes  * @param name   String name of field  * @param value  Value of the field  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cvmx_qlm_jtag_set
parameter_list|(
name|int
name|qlm
parameter_list|,
name|int
name|lane
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Errata G-16094: QLM Gen2 Equalizer Default Setting Change.  * CN68XX pass 1.x and CN66XX pass 1.x QLM tweak. This function tweaks the  * JTAG setting for a QLMs to run better at 5 and 6.25Ghz.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__cvmx_qlm_speed_tweak
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Errata G-16174: QLM Gen2 PCIe IDLE DAC change.  * CN68XX pass 1.x, CN66XX pass 1.x and CN63XX pass 1.0-2.2 QLM tweak.  * This function tweaks the JTAG setting for a QLMs for PCIe to run better.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__cvmx_qlm_pcie_idle_dac_tweak
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_LINUX_HOST
end_ifndef

begin_comment
comment|/**  * Get the speed (Gbaud) of the QLM in Mhz.  *  * @param qlm    QLM to examine  *  * @return Speed in Mhz  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_qlm_get_gbaud_mhz
parameter_list|(
name|int
name|qlm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Read QLM and return status based on CN66XX.  * @return  Return 1 if QLM is SGMII  *                 2 if QLM is XAUI  *                 3 if QLM is PCIe gen2 / gen1  *                 4 if QLM is SRIO 1x4 short / long  *                 5 if QLM is SRIO 2x2 short / long  *                 6 is reserved  *                 7 if QLM is PCIe 1x2 gen2 / gen1  *                 8 if QLM is PCIe 2x1 gen2 / gen1  *                 9 if QLM is ILK  *                 10 if QLM is RXAUI  *                 -1 otherwise  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_qlm_get_status
parameter_list|(
name|int
name|qlm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_QLM_H__ */
end_comment

end_unit

