begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *  *     * Redistributions in binary form must reproduce the above  *       copyright notice, this list of conditions and the following  *       disclaimer in the documentation and/or other materials provided  *       with the distribution.  *  *     * Neither the name of Cavium Networks nor the names of  *       its contributors may be used to endorse or promote products  *       derived from this software without specific prior written  *       permission.  *  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  * OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  * RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  * REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  * DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  * OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  * PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  * POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  * OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  * For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CVMX_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_CVMX_CONFIG_H
end_define

begin_include
include|#
directive|include
file|"opt_cvmx.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_define
define|#
directive|define
name|asm
value|__asm
end_define

begin_define
define|#
directive|define
name|CVMX_DONT_INCLUDE_CONFIG
end_define

begin_comment
comment|/* Define to enable the use of simple executive packet output functions. ** For packet I/O setup enable the helper functions below.  */
end_comment

begin_define
define|#
directive|define
name|CVMX_ENABLE_PKO_FUNCTIONS
end_define

begin_comment
comment|/* Define to enable the use of simple executive helper functions. These ** include many hardware setup functions.  See cvmx-helper.[ch] for ** details. */
end_comment

begin_define
define|#
directive|define
name|CVMX_ENABLE_HELPER_FUNCTIONS
end_define

begin_comment
comment|/* CVMX_HELPER_FIRST_MBUFF_SKIP is the number of bytes to reserve before ** the beginning of the packet. If necessary, override the default   ** here.  See the IPD section of the hardware manual for MBUFF SKIP  ** details.*/
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_FIRST_MBUFF_SKIP
value|184
end_define

begin_comment
comment|/* CVMX_HELPER_NOT_FIRST_MBUFF_SKIP is the number of bytes to reserve in each ** chained packet element. If necessary, override the default here */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_NOT_FIRST_MBUFF_SKIP
value|0
end_define

begin_comment
comment|/* CVMX_HELPER_ENABLE_BACK_PRESSURE controls whether back pressure is enabled ** for all input ports. This controls if IPD sends backpressure to all ports if ** Octeon's FPA pools don't have enough packet or work queue entries. Even when ** this is off, it is still possible to get backpressure from individual ** hardware ports. When configuring backpressure, also check ** CVMX_HELPER_DISABLE_*_BACKPRESSURE below. If necessary, override the default ** here */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_ENABLE_BACK_PRESSURE
value|1
end_define

begin_comment
comment|/* CVMX_HELPER_ENABLE_IPD controls if the IPD is enabled in the helper **  function. Once it is enabled the hardware starts accepting packets. You **  might want to skip the IPD enable if configuration changes are need **  from the default helper setup. If necessary, override the default here */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_ENABLE_IPD
value|1
end_define

begin_comment
comment|/* CVMX_HELPER_INPUT_TAG_TYPE selects the type of tag that the IPD assigns ** to incoming packets. */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_TYPE
value|CVMX_POW_TAG_TYPE_ORDERED
end_define

begin_comment
comment|/* The following select which fields are used by the PIP to generate ** the tag on INPUT ** 0: don't include ** 1: include */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV6_SRC_IP
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV6_DST_IP
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV6_SRC_PORT
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV6_DST_PORT
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV6_NEXT_HEADER
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV4_SRC_IP
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV4_DST_IP
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV4_SRC_PORT
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV4_DST_PORT
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_IPV4_PROTOCOL
value|0
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_INPUT_PORT
value|1
end_define

begin_comment
comment|/* Select skip mode for input ports */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_PORT_SKIP_MODE
value|CVMX_PIP_PORT_CFG_MODE_SKIPL2
end_define

begin_comment
comment|/* Define the number of queues per output port */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_PKO_QUEUES_PER_PORT_INTERFACE0
value|1
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_PKO_QUEUES_PER_PORT_INTERFACE1
value|1
end_define

begin_comment
comment|/* Configure PKO to use per-core queues (PKO lockless operation).  ** Please see the related SDK documentation for PKO that illustrates  ** how to enable and configure this option. */
end_comment

begin_comment
comment|//#define CVMX_ENABLE_PKO_LOCKLESS_OPERATION 1
end_comment

begin_comment
comment|//#define CVMX_HELPER_PKO_MAX_PORTS_INTERFACE0 8
end_comment

begin_comment
comment|//#define CVMX_HELPER_PKO_MAX_PORTS_INTERFACE1 8
end_comment

begin_comment
comment|/* Force backpressure to be disabled.  This overrides all other ** backpressure configuration */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_DISABLE_RGMII_BACKPRESSURE
value|1
end_define

begin_comment
comment|/* Disable the SPI4000's processing of backpressure packets and backpressure ** generation. When this is 1, the SPI4000 will not stop sending packets when ** receiving backpressure. It will also not generate backpressure packets when ** its internal FIFOs are full. */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_DISABLE_SPI4000_BACKPRESSURE
value|1
end_define

begin_comment
comment|/* CVMX_HELPER_SPI_TIMEOUT is used to determine how long the SPI initialization ** routines wait for SPI training. You can override the value using ** executive-config.h if necessary */
end_comment

begin_define
define|#
directive|define
name|CVMX_HELPER_SPI_TIMEOUT
value|10
end_define

begin_comment
comment|/* Select the number of low latency memory ports (interfaces) that ** will be configured.  Valid values are 1 and 2. */
end_comment

begin_define
define|#
directive|define
name|CVMX_LLM_CONFIG_NUM_PORTS
value|2
end_define

begin_comment
comment|/* Enable the fix for PKI-100 errata ("Size field is 8 too large in WQE and next ** pointers"). If CVMX_ENABLE_LEN_M8_FIX is set to 0, the fix for this errata will  ** not be enabled.  ** 0: Fix is not enabled ** 1: Fix is enabled, if supported by hardware */
end_comment

begin_define
define|#
directive|define
name|CVMX_ENABLE_LEN_M8_FIX
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CVMX_ENABLE_HELPER_FUNCTIONS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CVMX_ENABLE_PKO_FUNCTIONS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CVMX_ENABLE_PKO_FUNCTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable debug and informational printfs */
end_comment

begin_define
define|#
directive|define
name|CVMX_CONFIG_ENABLE_DEBUG_PRINTS
value|1
end_define

begin_comment
comment|/************************* Config Specific Defines ************************/
end_comment

begin_define
define|#
directive|define
name|CVMX_LLM_NUM_PORTS
value|1
end_define

begin_define
define|#
directive|define
name|CVMX_PKO_QUEUES_PER_PORT_INTERFACE0
value|1
end_define

begin_comment
comment|/**< PKO queues per port for interface 0 (ports 0-15) */
end_comment

begin_define
define|#
directive|define
name|CVMX_PKO_QUEUES_PER_PORT_INTERFACE1
value|1
end_define

begin_comment
comment|/**< PKO queues per port for interface 1 (ports 16-31) */
end_comment

begin_define
define|#
directive|define
name|CVMX_PKO_MAX_PORTS_INTERFACE0
value|CVMX_HELPER_PKO_MAX_PORTS_INTERFACE0
end_define

begin_comment
comment|/**< Limit on the number of PKO ports enabled for interface 0 */
end_comment

begin_define
define|#
directive|define
name|CVMX_PKO_MAX_PORTS_INTERFACE1
value|CVMX_HELPER_PKO_MAX_PORTS_INTERFACE1
end_define

begin_comment
comment|/**< Limit on the number of PKO ports enabled for interface 1 */
end_comment

begin_define
define|#
directive|define
name|CVMX_PKO_QUEUES_PER_PORT_PCI
value|1
end_define

begin_comment
comment|/**< PKO queues per port for PCI (ports 32-35) */
end_comment

begin_define
define|#
directive|define
name|CVMX_PKO_QUEUES_PER_PORT_LOOP
value|1
end_define

begin_comment
comment|/**< PKO queues per port for Loop devices (ports 36-39) */
end_comment

begin_comment
comment|/************************* FPA allocation *********************************/
end_comment

begin_comment
comment|/* Pool sizes in bytes, must be multiple of a cache line */
end_comment

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_0_SIZE
value|(15 * CVMX_CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_1_SIZE
value|(1 * CVMX_CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_2_SIZE
value|(8 * CVMX_CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_3_SIZE
value|(0 * CVMX_CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_4_SIZE
value|(0 * CVMX_CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_5_SIZE
value|(0 * CVMX_CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_6_SIZE
value|(0 * CVMX_CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_POOL_7_SIZE
value|(0 * CVMX_CACHE_LINE_SIZE)
end_define

begin_comment
comment|/* Pools in use */
end_comment

begin_define
define|#
directive|define
name|CVMX_FPA_PACKET_POOL
value|(0)
end_define

begin_comment
comment|/**< Packet buffers */
end_comment

begin_define
define|#
directive|define
name|CVMX_FPA_PACKET_POOL_SIZE
value|CVMX_FPA_POOL_0_SIZE
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_WQE_POOL
value|(1)
end_define

begin_comment
comment|/**< Work queue entrys */
end_comment

begin_define
define|#
directive|define
name|CVMX_FPA_WQE_POOL_SIZE
value|CVMX_FPA_POOL_1_SIZE
end_define

begin_define
define|#
directive|define
name|CVMX_FPA_OUTPUT_BUFFER_POOL
value|(2)
end_define

begin_comment
comment|/**< PKO queue command buffers */
end_comment

begin_define
define|#
directive|define
name|CVMX_FPA_OUTPUT_BUFFER_POOL_SIZE
value|CVMX_FPA_POOL_2_SIZE
end_define

begin_comment
comment|/*************************  FAU allocation ********************************/
end_comment

begin_define
define|#
directive|define
name|CVMX_FAU_REG_END
value|2048
end_define

begin_define
define|#
directive|define
name|CVMX_SCR_SCRATCH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CVMX_CONFIG_H */
end_comment

end_unit

