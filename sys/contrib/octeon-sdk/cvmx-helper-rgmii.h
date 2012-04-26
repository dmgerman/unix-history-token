begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Functions for RGMII/GMII/MII initialization, configuration,  * and monitoring.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_RGMII_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_RGMII_H__
end_define

begin_comment
comment|/**  * @INTERNAL  * Probe RGMII ports and determine the number present  *  * @param interface Interface to probe  *  * @return Number of RGMII/GMII/MII ports (0-4).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_rgmii_probe
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|__cvmx_helper_rgmii_enumerate
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
return|return
name|__cvmx_helper_rgmii_probe
argument_list|(
name|interface
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Put an RGMII interface in loopback mode. Internal packets sent  * out will be received back again on the same port. Externally  * received packets will echo back out.  *  * @param port   IPD port number to loop.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cvmx_helper_rgmii_internal_loopback
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Configure all of the ASX, GMX, and PKO regsiters required  * to get RGMII to function on the supplied interface.  *  * @param interface PKO Interface to configure (0 or 1)  *  * @return Zero on success  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_rgmii_enable
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
name|__cvmx_helper_rgmii_link_get
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
name|__cvmx_helper_rgmii_link_set
parameter_list|(
name|int
name|ipd_port
parameter_list|,
name|cvmx_helper_link_info_t
name|link_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Configure a port for internal and/or external loopback. Internal loopback  * causes packets sent by the port to be received by Octeon. External loopback  * causes packets received from the wire to sent out again.  *  * @param ipd_port IPD/PKO port to loopback.  * @param enable_internal  *                 Non zero if you want internal loopback  * @param enable_external  *                 Non zero if you want external loopback  *  * @return Zero on success, negative on failure.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_rgmii_configure_loopback
parameter_list|(
name|int
name|ipd_port
parameter_list|,
name|int
name|enable_internal
parameter_list|,
name|int
name|enable_external
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

