begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Networks nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Functions for NPI initialization, configuration,  * and monitoring.  *  *<hr>$Revision: 49448 $<hr>  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_ENABLE_PKO_FUNCTIONS
end_ifdef

begin_comment
comment|/**  * @INTERNAL  * Probe a NPI interface and determine the number of ports  * connected to it. The NPI interface should still be down  * after this call.  *  * @param interface Interface to probe  *  * @return Number of ports on the interface. Zero to disable.  */
end_comment

begin_function
name|int
name|__cvmx_helper_npi_probe
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
if|#
directive|if
name|CVMX_PKO_QUEUES_PER_PORT_PCI
operator|>
literal|0
if|if
condition|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN38XX
argument_list|)
operator|||
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN58XX
argument_list|)
condition|)
return|return
literal|4
return|;
elseif|else
if|if
condition|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN56XX
argument_list|)
operator|&&
operator|!
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN56XX_PASS1_X
argument_list|)
condition|)
return|return
literal|4
return|;
comment|/* The packet engines didn't exist before pass 2 */
elseif|else
if|if
condition|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN52XX
argument_list|)
operator|&&
operator|!
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN52XX_PASS1_X
argument_list|)
condition|)
return|return
literal|4
return|;
comment|/* The packet engines didn't exist before pass 2 */
elseif|else
if|if
condition|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN6XXX
argument_list|)
condition|)
return|return
literal|4
return|;
if|#
directive|if
literal|0
comment|/* Technically CN30XX, CN31XX, and CN50XX contain packet engines, but         nobody ever uses them. Since this is the case, we disable them here */
block|else if (OCTEON_IS_MODEL(OCTEON_CN31XX) || OCTEON_IS_MODEL(OCTEON_CN50XX))         return 2;     else if (OCTEON_IS_MODEL(OCTEON_CN30XX))         return 1;
endif|#
directive|endif
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Bringup and enable a NPI interface. After this call packet  * I/O should be fully functional. This is called with IPD  * enabled but PKO disabled.  *  * @param interface Interface to bring up  *  * @return Zero on success, negative on failure  */
end_comment

begin_function
name|int
name|__cvmx_helper_npi_enable
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
comment|/* On CN50XX, CN52XX, and CN56XX we need to disable length checking         so packet< 64 bytes and jumbo frames don't get errors */
if|if
condition|(
operator|!
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN3XXX
argument_list|)
operator|&&
operator|!
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN58XX
argument_list|)
condition|)
block|{
name|int
name|num_ports
init|=
name|cvmx_helper_ports_on_interface
argument_list|(
name|interface
argument_list|)
decl_stmt|;
name|int
name|port
decl_stmt|;
for|for
control|(
name|port
operator|=
literal|0
init|;
name|port
operator|<
name|num_ports
condition|;
name|port
operator|++
control|)
block|{
name|cvmx_pip_prt_cfgx_t
name|port_cfg
decl_stmt|;
name|int
name|ipd_port
init|=
name|cvmx_helper_get_ipd_port
argument_list|(
name|interface
argument_list|,
name|port
argument_list|)
decl_stmt|;
name|port_cfg
operator|.
name|u64
operator|=
name|cvmx_read_csr
argument_list|(
name|CVMX_PIP_PRT_CFGX
argument_list|(
name|ipd_port
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
name|ipd_port
argument_list|)
argument_list|,
name|port_cfg
operator|.
name|u64
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Enables are controlled by the remote host, so nothing to do here */
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

