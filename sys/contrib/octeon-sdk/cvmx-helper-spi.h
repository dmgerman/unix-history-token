begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Networks nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Functions for SPI initialization, configuration,  * and monitoring.  *  *<hr>$Revision: 49448 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_SPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_SPI_H__
end_define

begin_comment
comment|/**  * @INTERNAL  * Probe a SPI interface and determine the number of ports  * connected to it. The SPI interface should still be down after  * this call.  *  * @param interface Interface to probe  *  * @return Number of ports on the interface. Zero to disable.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_spi_probe
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Bringup and enable a SPI interface. After this call packet I/O  * should be fully functional. This is called with IPD enabled but  * PKO disabled.  *  * @param interface Interface to bring up  *  * @return Zero on success, negative on failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_spi_enable
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Return the link state of an IPD/PKO port as returned by  * auto negotiation. The result of this function may not match  * Octeon's link config if auto negotiation has changed since  * the last call to cvmx_helper_link_set().  *  * @param ipd_port IPD/PKO port to query  *  * @return Link state  */
end_comment

begin_function_decl
specifier|extern
name|cvmx_helper_link_info_t
name|__cvmx_helper_spi_link_get
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Configure an IPD/PKO port for the specified link state. This  * function does not influence auto negotiation at the PHY level.  * The passed link state must always match the link state returned  * by cvmx_helper_link_get(). It is normally best to use  * cvmx_helper_link_autoconf() instead.  *  * @param ipd_port  IPD/PKO port to configure  * @param link_info The new link state  *  * @return Zero on success, negative on failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_spi_link_set
parameter_list|(
name|int
name|ipd_port
parameter_list|,
name|cvmx_helper_link_info_t
name|link_info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

