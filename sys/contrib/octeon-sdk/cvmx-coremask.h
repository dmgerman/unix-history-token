begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Module to support operations on bitmap of cores. Coremask can be used to  * select a specific core, a group of cores, or all available cores, for  * initialization and differentiation of roles within a single shared binary  * executable image.  *  *<hr>$Revision: 41586 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_COREMASK_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_COREMASK_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-asm.h"
end_include

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
comment|/*  * coremask is simply unsigned int (32 bits).  *  * NOTE: supports up to 32 cores maximum.  *  * union of coremasks is simply bitwise-or.  * intersection of coremasks is simply bitwise-and.  *  */
define|#
directive|define
name|CVMX_COREMASK_MAX
value|0xFFFFFFFFu
comment|/* maximum supported mask */
comment|/**  * Compute coremask for a specific core.  *  * @param  core_id  The core ID  *  * @return  coremask for a specific core  *  */
specifier|static
specifier|inline
name|unsigned
name|int
name|cvmx_coremask_core
parameter_list|(
name|unsigned
name|int
name|core_id
parameter_list|)
block|{
return|return
operator|(
literal|1u
operator|<<
name|core_id
operator|)
return|;
block|}
comment|/**  * Compute coremask for num_cores cores starting with core 0.  *  * @param  num_cores  number of cores  *  * @return  coremask for num_cores cores  *  */
specifier|static
specifier|inline
name|unsigned
name|int
name|cvmx_coremask_numcores
parameter_list|(
name|unsigned
name|int
name|num_cores
parameter_list|)
block|{
return|return
operator|(
name|CVMX_COREMASK_MAX
operator|>>
operator|(
literal|32
operator|-
name|num_cores
operator|)
operator|)
return|;
block|}
comment|/**  * Compute coremask for a range of cores from core low to core high.  *  * @param  low   first core in the range  * @param  high  last core in the range  *  * @return  coremask for the range of cores  *  */
specifier|static
specifier|inline
name|unsigned
name|int
name|cvmx_coremask_range
parameter_list|(
name|unsigned
name|int
name|low
parameter_list|,
name|unsigned
name|int
name|high
parameter_list|)
block|{
return|return
operator|(
operator|(
name|CVMX_COREMASK_MAX
operator|>>
operator|(
literal|31
operator|-
name|high
operator|+
name|low
operator|)
operator|)
operator|<<
name|low
operator|)
return|;
block|}
comment|/**  * Test to see if current core is a member of coremask.  *  * @param  coremask  the coremask to test against  *  * @return  1 if current core is a member of coremask, 0 otherwise  *  */
specifier|static
specifier|inline
name|int
name|cvmx_coremask_is_member
parameter_list|(
name|unsigned
name|int
name|coremask
parameter_list|)
block|{
return|return
operator|(
operator|(
name|cvmx_coremask_core
argument_list|(
name|cvmx_get_core_num
argument_list|()
argument_list|)
operator|&
name|coremask
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
comment|/**  * Test to see if current core is first core in coremask.  *  * @param  coremask  the coremask to test against  *  * @return  1 if current core is first core in the coremask, 0 otherwise  *  */
specifier|static
specifier|inline
name|int
name|cvmx_coremask_first_core
parameter_list|(
name|unsigned
name|int
name|coremask
parameter_list|)
block|{
return|return
name|cvmx_coremask_is_member
argument_list|(
name|coremask
argument_list|)
operator|&&
operator|(
operator|(
name|cvmx_get_core_num
argument_list|()
operator|==
literal|0
operator|)
operator|||
operator|(
operator|(
name|cvmx_coremask_numcores
argument_list|(
name|cvmx_get_core_num
argument_list|()
argument_list|)
operator|&
name|coremask
operator|)
operator|==
literal|0
operator|)
operator|)
return|;
block|}
comment|/**  * Wait (stall) until all cores in the given coremask has reached this point  * in the program execution before proceeding.  *  * @param  coremask  the group of cores performing the barrier sync  *  */
specifier|extern
name|void
name|cvmx_coremask_barrier_sync
parameter_list|(
name|unsigned
name|int
name|coremask
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
comment|/* __CVMX_COREMASK_H__ */
end_comment

end_unit

