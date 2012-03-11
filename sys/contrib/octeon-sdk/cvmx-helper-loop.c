begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Functions for LOOP initialization, configuration,  * and monitoring.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<asm/octeon/cvmx.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_ENABLE_PKO_FUNCTIONS
end_ifdef

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-helper.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-pip-defs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|"executive-config.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_ENABLE_PKO_FUNCTIONS
end_ifdef

begin_include
include|#
directive|include
file|"cvmx.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-helper.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-helper.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_ENABLE_PKO_FUNCTIONS
end_ifdef

begin_function
name|int
name|__cvmx_helper_loop_enumerate
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
return|return
operator|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN68XX
argument_list|)
condition|?
literal|8
else|:
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Probe a LOOP interface and determine the number of ports  * connected to it. The LOOP interface should still be down  * after this call.  *  * @param interface Interface to probe  *  * @return Number of ports on the interface. Zero to disable.  */
end_comment

begin_function
name|int
name|__cvmx_helper_loop_probe
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
return|return
name|__cvmx_helper_loop_enumerate
argument_list|(
name|interface
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Bringup and enable a LOOP interface. After this call packet  * I/O should be fully functional. This is called with IPD  * enabled but PKO disabled.  *  * @param interface Interface to bring up  *  * @return Zero on success, negative on failure  */
end_comment

begin_function
name|int
name|__cvmx_helper_loop_enable
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
name|cvmx_pip_prt_cfgx_t
name|port_cfg
decl_stmt|;
name|int
name|num_ports
decl_stmt|,
name|index
decl_stmt|;
name|unsigned
name|long
name|offset
decl_stmt|;
name|num_ports
operator|=
name|__cvmx_helper_get_num_ipd_ports
argument_list|(
name|interface
argument_list|)
expr_stmt|;
comment|/*       * We need to disable length checking so packet< 64 bytes and jumbo      * frames don't get errors      */
for|for
control|(
name|index
operator|=
literal|0
init|;
name|index
operator|<
name|num_ports
condition|;
name|index
operator|++
control|)
block|{
name|offset
operator|=
operator|(
operator|(
name|octeon_has_feature
argument_list|(
name|OCTEON_FEATURE_PKND
argument_list|)
operator|)
condition|?
name|cvmx_helper_get_pknd
argument_list|(
name|interface
argument_list|,
name|index
argument_list|)
else|:
name|cvmx_helper_get_ipd_port
argument_list|(
name|interface
argument_list|,
name|index
argument_list|)
operator|)
expr_stmt|;
name|port_cfg
operator|.
name|u64
operator|=
name|cvmx_read_csr
argument_list|(
name|CVMX_PIP_PRT_CFGX
argument_list|(
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|port_cfg
operator|.
name|s
operator|.
name|maxerr_en
operator|=
literal|0
expr_stmt|;
name|port_cfg
operator|.
name|s
operator|.
name|minerr_en
operator|=
literal|0
expr_stmt|;
name|cvmx_write_csr
argument_list|(
name|CVMX_PIP_PRT_CFGX
argument_list|(
name|offset
argument_list|)
argument_list|,
name|port_cfg
operator|.
name|u64
argument_list|)
expr_stmt|;
block|}
comment|/*      * Disable FCS stripping for loopback ports      */
if|if
condition|(
operator|!
name|octeon_has_feature
argument_list|(
name|OCTEON_FEATURE_PKND
argument_list|)
condition|)
block|{
name|cvmx_ipd_sub_port_fcs_t
name|ipd_sub_port_fcs
decl_stmt|;
name|ipd_sub_port_fcs
operator|.
name|u64
operator|=
name|cvmx_read_csr
argument_list|(
name|CVMX_IPD_SUB_PORT_FCS
argument_list|)
expr_stmt|;
name|ipd_sub_port_fcs
operator|.
name|s
operator|.
name|port_bit2
operator|=
literal|0
expr_stmt|;
name|cvmx_write_csr
argument_list|(
name|CVMX_IPD_SUB_PORT_FCS
argument_list|,
name|ipd_sub_port_fcs
operator|.
name|u64
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVMX_ENABLE_PKO_FUNCTIONS */
end_comment

end_unit

