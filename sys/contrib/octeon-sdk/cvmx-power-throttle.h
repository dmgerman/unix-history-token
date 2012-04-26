begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to power-throttle control, measurement, and debugging  * facilities.  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_POWER_THROTTLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_POWER_THROTTLE_H__
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
enum|enum
name|cvmx_power_throttle_field_index
block|{
name|CVMX_PTH_INDEX_MAXPOW
block|,
name|CVMX_PTH_INDEX_POWER
block|,
name|CVMX_PTH_INDEX_THROTT
block|,
name|CVMX_PTH_INDEX_RESERVED
block|,
name|CVMX_PTH_INDEX_DISTAG
block|,
name|CVMX_PTH_INDEX_PERIOD
block|,
name|CVMX_PTH_INDEX_POWLIM
block|,
name|CVMX_PTH_INDEX_MAXTHR
block|,
name|CVMX_PTH_INDEX_MINTHR
block|,
name|CVMX_PTH_INDEX_HRMPOWADJ
block|,
name|CVMX_PTH_INDEX_OVRRD
block|,
name|CVMX_PTH_INDEX_MAX
block|}
enum|;
typedef|typedef
name|enum
name|cvmx_power_throttle_field_index
name|cvmx_power_throttle_field_index_t
typedef|;
comment|/**  * Throttle power to percentage% of configured maximum (MAXPOW).  *  * @param percentage	0 to 100  * @return 0 for success and -1 for error.  */
specifier|extern
name|int
name|cvmx_power_throttle_self
parameter_list|(
name|uint8_t
name|percentage
parameter_list|)
function_decl|;
comment|/**  * Throttle power to percentage% of configured maximum (MAXPOW)  * for the cores identified in coremask.  *  * @param percentage 	0 to 100  * @param coremask	bit mask where each bit identifies a core.  * @return 0 for success and -1 for error.  */
specifier|extern
name|int
name|cvmx_power_throttle
parameter_list|(
name|uint8_t
name|percentage
parameter_list|,
name|uint64_t
name|coremask
parameter_list|)
function_decl|;
comment|/**  * The same functionality as cvmx_power_throttle() but it takes a  * bitmap-based coremask as a parameter.  */
specifier|extern
name|int
name|cvmx_power_throttle_bmp
parameter_list|(
name|uint8_t
name|percentage
parameter_list|,
name|struct
name|cvmx_coremask
modifier|*
name|pcm
parameter_list|)
function_decl|;
comment|/**  * Get the i'th field of the power throttle register  *  * @param r is the value of the power throttle register  * @param i is the index of the field  *  * @return (uint64_t)-1 on failure.  */
specifier|extern
name|uint64_t
name|cvmx_power_throttle_get_field
parameter_list|(
name|uint64_t
name|r
parameter_list|,
name|cvmx_power_throttle_field_index_t
name|i
parameter_list|)
function_decl|;
comment|/**  * Retrieve the content of the power throttle register of a core  *  * @param ppid is the core id  *  * @return (uint64_t)-1 on failure.  */
specifier|extern
name|uint64_t
name|cvmx_power_throttle_get_register
parameter_list|(
name|int
name|ppid
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
comment|/* __CVMX_POWER_THROTTLE_H__ */
end_comment

end_unit

