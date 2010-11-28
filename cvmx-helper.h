begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Networks nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Helper functions for common, but complicated tasks.  *  *<hr>$Revision: 49448 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_H__
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"cvmx-fpa.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-wqe.h"
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
typedef|typedef
enum|enum
block|{
name|CVMX_HELPER_INTERFACE_MODE_DISABLED
block|,
name|CVMX_HELPER_INTERFACE_MODE_RGMII
block|,
name|CVMX_HELPER_INTERFACE_MODE_GMII
block|,
name|CVMX_HELPER_INTERFACE_MODE_SPI
block|,
name|CVMX_HELPER_INTERFACE_MODE_PCIE
block|,
name|CVMX_HELPER_INTERFACE_MODE_XAUI
block|,
name|CVMX_HELPER_INTERFACE_MODE_SGMII
block|,
name|CVMX_HELPER_INTERFACE_MODE_PICMG
block|,
name|CVMX_HELPER_INTERFACE_MODE_NPI
block|,
name|CVMX_HELPER_INTERFACE_MODE_LOOP
block|,
name|CVMX_HELPER_INTERFACE_MODE_SRIO
block|, }
name|cvmx_helper_interface_mode_t
typedef|;
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved_20_63
range|:
literal|44
decl_stmt|;
name|uint64_t
name|link_up
range|:
literal|1
decl_stmt|;
comment|/**< Is the physical link up? */
name|uint64_t
name|full_duplex
range|:
literal|1
decl_stmt|;
comment|/**< 1 if the link is full duplex */
name|uint64_t
name|speed
range|:
literal|18
decl_stmt|;
comment|/**< Speed of the link in Mbps */
block|}
name|s
struct|;
block|}
name|cvmx_helper_link_info_t
typedef|;
include|#
directive|include
file|"cvmx-helper-fpa.h"
ifdef|#
directive|ifdef
name|CVMX_ENABLE_PKO_FUNCTIONS
include|#
directive|include
file|"cvmx-helper-errata.h"
include|#
directive|include
file|"cvmx-helper-loop.h"
include|#
directive|include
file|"cvmx-helper-npi.h"
include|#
directive|include
file|"cvmx-helper-rgmii.h"
include|#
directive|include
file|"cvmx-helper-sgmii.h"
include|#
directive|include
file|"cvmx-helper-spi.h"
include|#
directive|include
file|"cvmx-helper-srio.h"
include|#
directive|include
file|"cvmx-helper-util.h"
include|#
directive|include
file|"cvmx-helper-xaui.h"
comment|/**  * cvmx_override_pko_queue_priority(int ipd_port, uint64_t  * priorities[16]) is a function pointer. It is meant to allow  * customization of the PKO queue priorities based on the port  * number. Users should set this pointer to a function before  * calling any cvmx-helper operations.  */
specifier|extern
name|void
function_decl|(
modifier|*
name|cvmx_override_pko_queue_priority
function_decl|)
parameter_list|(
name|int
name|pko_port
parameter_list|,
name|uint64_t
name|priorities
index|[
literal|16
index|]
parameter_list|)
function_decl|;
comment|/**  * cvmx_override_ipd_port_setup(int ipd_port) is a function  * pointer. It is meant to allow customization of the IPD port  * setup before packet input/output comes online. It is called  * after cvmx-helper does the default IPD configuration, but  * before IPD is enabled. Users should set this pointer to a  * function before calling any cvmx-helper operations.  */
specifier|extern
name|void
function_decl|(
modifier|*
name|cvmx_override_ipd_port_setup
function_decl|)
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/**  * This function enables the IPD and also enables the packet interfaces.  * The packet interfaces (RGMII and SPI) must be enabled after the  * IPD.  This should be called by the user program after any additional  * IPD configuration changes are made if CVMX_HELPER_ENABLE_IPD  * is not set in the executive-config.h file.  *  * @return 0 on success  *         -1 on failure  */
specifier|extern
name|int
name|cvmx_helper_ipd_and_packet_input_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Initialize the PIP, IPD, and PKO hardware to support  * simple priority based queues for the ethernet ports. Each  * port is configured with a number of priority queues based  * on CVMX_PKO_QUEUES_PER_PORT_* where each queue is lower  * priority than the previous.  *  * @return Zero on success, non-zero on failure  */
specifier|extern
name|int
name|cvmx_helper_initialize_packet_io_global
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Does core local initialization for packet io  *  * @return Zero on success, non-zero on failure  */
specifier|extern
name|int
name|cvmx_helper_initialize_packet_io_local
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Undo the initialization performed in  * cvmx_helper_initialize_packet_io_global(). After calling this routine and the  * local version on each core, packet IO for Octeon will be disabled and placed  * in the initial reset state. It will then be safe to call the initialize  * later on. Note that this routine does not empty the FPA pools. It frees all  * buffers used by the packet IO hardware to the FPA so a function emptying the  * FPA after shutdown should find all packet buffers in the FPA.  *  * @return Zero on success, negative on failure.  */
specifier|extern
name|int
name|cvmx_helper_shutdown_packet_io_global
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Does core local shutdown of packet io  *  * @return Zero on success, non-zero on failure  */
specifier|extern
name|int
name|cvmx_helper_shutdown_packet_io_local
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Returns the number of ports on the given interface.  * The interface must be initialized before the port count  * can be returned.  *  * @param interface Which interface to return port count for.  *  * @return Port count for interface  *         -1 for uninitialized interface  */
specifier|extern
name|int
name|cvmx_helper_ports_on_interface
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
comment|/**  * Return the number of interfaces the chip has. Each interface  * may have multiple ports. Most chips support two interfaces,  * but the CNX0XX and CNX1XX are exceptions. These only support  * one interface.  *  * @return Number of interfaces on chip  */
specifier|extern
name|int
name|cvmx_helper_get_number_of_interfaces
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Get the operating mode of an interface. Depending on the Octeon  * chip and configuration, this function returns an enumeration  * of the type of packet I/O supported by an interface.  *  * @param interface Interface to probe  *  * @return Mode of the interface. Unknown or unsupported interfaces return  *         DISABLED.  */
specifier|extern
name|cvmx_helper_interface_mode_t
name|cvmx_helper_interface_get_mode
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
comment|/**  * Auto configure an IPD/PKO port link state and speed. This  * function basically does the equivalent of:  * cvmx_helper_link_set(ipd_port, cvmx_helper_link_get(ipd_port));  *  * @param ipd_port IPD/PKO port to auto configure  *  * @return Link state after configure  */
specifier|extern
name|cvmx_helper_link_info_t
name|cvmx_helper_link_autoconf
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/**  * Return the link state of an IPD/PKO port as returned by  * auto negotiation. The result of this function may not match  * Octeon's link config if auto negotiation has changed since  * the last call to cvmx_helper_link_set().  *  * @param ipd_port IPD/PKO port to query  *  * @return Link state  */
specifier|extern
name|cvmx_helper_link_info_t
name|cvmx_helper_link_get
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/**  * Configure an IPD/PKO port for the specified link state. This  * function does not influence auto negotiation at the PHY level.  * The passed link state must always match the link state returned  * by cvmx_helper_link_get(). It is normally best to use  * cvmx_helper_link_autoconf() instead.  *  * @param ipd_port  IPD/PKO port to configure  * @param link_info The new link state  *  * @return Zero on success, negative on failure  */
specifier|extern
name|int
name|cvmx_helper_link_set
parameter_list|(
name|int
name|ipd_port
parameter_list|,
name|cvmx_helper_link_info_t
name|link_info
parameter_list|)
function_decl|;
comment|/**  * This function probes an interface to determine the actual  * number of hardware ports connected to it. It doesn't setup the  * ports or enable them. The main goal here is to set the global  * interface_port_count[interface] correctly. Hardware setup of the  * ports will be performed later.  *  * @param interface Interface to probe  *  * @return Zero on success, negative on failure  */
specifier|extern
name|int
name|cvmx_helper_interface_probe
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
comment|/**  * Configure a port for internal and/or external loopback. Internal loopback  * causes packets sent by the port to be received by Octeon. External loopback  * causes packets received from the wire to sent out again.  *  * @param ipd_port IPD/PKO port to loopback.  * @param enable_internal  *                 Non zero if you want internal loopback  * @param enable_external  *                 Non zero if you want external loopback  *  * @return Zero on success, negative on failure.  */
specifier|extern
name|int
name|cvmx_helper_configure_loopback
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
endif|#
directive|endif
comment|/* CVMX_ENABLE_PKO_FUNCTIONS */
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
comment|/* __CVMX_HELPER_H__ */
end_comment

end_unit

