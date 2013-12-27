begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Helper Functions for the Configuration Framework  *  * OCTEON_CN68XX introduces a flexible hw interface configuration  * scheme. To cope with this change and the requirements of  * configurability for other system resources, e.g., IPD/PIP pknd and  * PKO ports and queues, a configuration framework for the SDK is  * designed. It has two goals: first to recognize and establish the  * default configuration and, second, to allow the user to define key  * parameters in a high-level language.  *  * The helper functions query the QLM setup to help achieving the  * first goal.  *  * The second goal is accomplished by generating  * cvmx_helper_cfg_init() from a high-level lanaguage.  *  *<hr>$Revision: 0 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_CFG_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_CFG_H__
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_CFG_MAX_IFACE
value|9
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_CFG_MAX_PKO_PORT
value|128
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_CFG_MAX_PIP_BPID
value|64
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_CFG_MAX_PIP_PKND
value|64
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_CFG_MAX_PKO_QUEUES
value|256
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_CFG_MAX_PORT_PER_IFACE
value|256
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_CFG_INVALID_VALUE
value|-1
end_define

begin_comment
comment|/* The default return  						   	 * value upon failure 							 */
end_comment

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
define|#
directive|define
name|cvmx_helper_cfg_assert
parameter_list|(
name|cond
parameter_list|)
define|\
value|do {								\ 	    if (!(cond))						\ 	    {								\ 	        cvmx_dprintf("cvmx_helper_cfg_assert (%s) at %s:%d\n",	\ 		    #cond, __FILE__, __LINE__);				\ 	    }								\ 	} while (0)
comment|/*  * Config Options  *  * These options have to be set via cvmx_helper_cfg_opt_set() before calling the  * routines that set up the hw. These routines process the options and set them  * correctly to take effect at runtime.   */
enum|enum
name|cvmx_helper_cfg_option
block|{
name|CVMX_HELPER_CFG_OPT_USE_DWB
block|,
comment|/* 				      * Global option to control if 				      * the SDK configures units (DMA, 				      * SSO, and PKO) to send don't 				      * write back (DWB) requests for 				      * freed buffers. Set to 1/0 to 				      * enable/disable DWB. 				      * 				      * For programs that fit inside 				      * L2, sending DWB just causes 				      * more L2 operations without 				      * benefit. 	                              */
name|CVMX_HELPER_CFG_OPT_MAX
block|}
enum|;
typedef|typedef
name|enum
name|cvmx_helper_cfg_option
name|cvmx_helper_cfg_option_t
typedef|;
comment|/*  * @INTERNAL  * Return configured pknd for the port  *  * @param interface the interface number  * @param index the port's index number  * @return the pknd  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pknd
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the configured bpid for the port  *  * @param interface the interface number  * @param index the port's index number  * @return the bpid  */
specifier|extern
name|int
name|__cvmx_helper_cfg_bpid
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the configured pko_port base for the port  *  * @param interface the interface number  * @param index the port's index number  * @return the pko_port base  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_port_base
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the configured number of pko_ports for the port  *  * @param interface the interface number  * @param index the port's index number  * @return the number of pko_ports  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_port_num
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the configured pko_queue base for the pko_port  *  * @param pko_port  * @return the pko_queue base  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_queue_base
parameter_list|(
name|int
name|pko_port
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the configured number of pko_queues for the pko_port  *  * @param pko_port  * @return the number of pko_queues  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_queue_num
parameter_list|(
name|int
name|pko_port
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the interface the pko_port is configured for  *  * @param pko_port  * @return the interface for the pko_port  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_port_interface
parameter_list|(
name|int
name|pko_port
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the index of the port the pko_port is configured for  *  * @param pko_port  * @return the index of the port  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_port_index
parameter_list|(
name|int
name|pko_port
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the pko_eid of the pko_port  *  * @param pko_port  * @return the pko_eid  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_port_eid
parameter_list|(
name|int
name|pko_port
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the max# of pko queues allocated.  *  * @return the max# of pko queues  *  * Note: there might be holes in the queue space depending on user  * configuration. The function returns the highest queue's index in  * use.  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_max_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * Return the max# of PKO DMA engines allocated.  *  * @return the max# of DMA engines  *  * NOTE: the DMA engines are allocated contiguously and starting from  * 0.  */
specifier|extern
name|int
name|__cvmx_helper_cfg_pko_max_engine
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/*  * Get the value set for the config option ``opt''.  *  * @param opt is the config option.  * @return the value set for the option  */
specifier|extern
name|uint64_t
name|cvmx_helper_cfg_opt_get
parameter_list|(
name|cvmx_helper_cfg_option_t
name|opt
parameter_list|)
function_decl|;
comment|/*  * Set the value for a config option.  *  * @param opt is the config option.  * @param val is the value to set for the opt.  * @return 0 for success and -1 on error  *  * Note an option here is a config-time parameter and this means that  * it has to be set before calling the corresponding setup functions  * that actually sets the option in hw.  */
specifier|extern
name|int
name|cvmx_helper_cfg_opt_set
parameter_list|(
name|cvmx_helper_cfg_option_t
name|opt
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
comment|/*  * Retrieve the pko_port base given ipd_port.  *  * @param ipd_port is the IPD eport  * @return the corresponding PKO port base for the physical port  * represented by the IPD eport or CVMX_HELPER_CFG_INVALID_VALUE.  */
specifier|extern
name|int
name|cvmx_helper_cfg_ipd2pko_port_base
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/*  * Retrieve the number of pko_ports given ipd_port.  *  * @param ipd_port is the IPD eport  * @return the corresponding number of PKO ports for the physical port   *  represented by IPD eport or CVMX_HELPER_CFG_INVALID_VALUE.  */
specifier|extern
name|int
name|cvmx_helper_cfg_ipd2pko_port_num
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/*  * @INTERNAL  * The init function  *  * @param none  * @return 0 for success.  *  * Note: this function is meant to be called to set the ``configured  * parameters,'' e.g., pknd, bpid, etc. and therefore should be before  * any of the corresponding cvmx_helper_cfg_xxxx() functions are  * called.  */
specifier|extern
name|int
name|__cvmx_helper_cfg_init
parameter_list|(
name|void
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
comment|/* __CVMX_HELPER_CFG_H__ */
end_comment

end_unit

