begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Support functions for managing the MII management port  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_MGMT_PORT_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_MGMT_PORT_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-helper.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-helper-board.h"
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
define|#
directive|define
name|CVMX_MGMT_PORT_NUM_PORTS
value|2
comment|/* Right now we only have one mgmt port */
define|#
directive|define
name|CVMX_MGMT_PORT_NUM_TX_BUFFERS
value|16
comment|/* Number of TX ring buffer entries and buffers */
define|#
directive|define
name|CVMX_MGMT_PORT_NUM_RX_BUFFERS
value|128
comment|/* Number of RX ring buffer entries and buffers */
define|#
directive|define
name|CVMX_MGMT_PORT_TX_BUFFER_SIZE
value|12288
comment|/* Size of each TX/RX buffer */
define|#
directive|define
name|CVMX_MGMT_PORT_RX_BUFFER_SIZE
value|1536
comment|/* Size of each TX/RX buffer */
typedef|typedef
enum|enum
block|{
name|CVMX_MGMT_PORT_SUCCESS
init|=
literal|0
block|,
name|CVMX_MGMT_PORT_NO_MEMORY
init|=
operator|-
literal|1
block|,
name|CVMX_MGMT_PORT_INVALID_PARAM
init|=
operator|-
literal|2
block|,
name|CVMX_MGMT_PORT_INIT_ERROR
init|=
operator|-
literal|3
block|, }
name|cvmx_mgmt_port_result_t
typedef|;
comment|/* Enumeration of Net Device interface flags. */
typedef|typedef
enum|enum
block|{
name|CVMX_IFF_PROMISC
init|=
literal|0x100
block|,
comment|/* receive all packets           */
name|CVMX_IFF_ALLMULTI
init|=
literal|0x200
block|,
comment|/* receive all multicast packets */
block|}
name|cvmx_mgmt_port_netdevice_flags_t
typedef|;
comment|/**  * Called to initialize a management port for use. Multiple calls  * to this function accross applications is safe.  *  * @param port   Port to initialize  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_initialize
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
comment|/**  * Shutdown a management port. This currently disables packet IO  * but leaves all hardware and buffers. Another application can then  * call initialize() without redoing the hardware setup.  *  * @param port   Management port  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_shutdown
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
comment|/**  * Enable packet IO on a management port  *  * @param port   Management port  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_enable
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
comment|/**  * Disable packet IO on a management port  *  * @param port   Management port  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_disable
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
comment|/**  * Send a packet out the management port. The packet is copied so  * the input buffer isn't used after this call.  *  * @param port       Management port  * @param packet_len Length of the packet to send. It does not include the final CRC  * @param buffer     Packet data  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_send
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|packet_len
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
comment|/**  * Send a packet out the management port. The packet is copied so  * the input mbuf isn't used after this call.  *  * @param port       Management port  * @param m          Packet mbuf (with pkthdr)  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_sendm
parameter_list|(
name|int
name|port
parameter_list|,
specifier|const
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/**  * Receive a packet from the management port.  *  * @param port       Management port  * @param buffer_len Size of the buffer to receive the packet into  * @param buffer     Buffer to receive the packet into  *  * @return The size of the packet, or a negative erorr code on failure. Zero  *         means that no packets were available.  */
specifier|extern
name|int
name|cvmx_mgmt_port_receive
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|buffer_len
parameter_list|,
name|uint8_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
comment|/**  * Set the MAC address for a management port  *  * @param port   Management port  * @param mac    New MAC address. The lower 6 bytes are used.  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_set_mac
parameter_list|(
name|int
name|port
parameter_list|,
name|uint64_t
name|mac
parameter_list|)
function_decl|;
comment|/**  * Get the MAC address for a management port  *  * @param port   Management port  *  * @return MAC address  */
specifier|extern
name|uint64_t
name|cvmx_mgmt_port_get_mac
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
define|#
directive|define
name|CVMX_MGMT_PORT_GET_MAC_ERROR
value|((unsigned long long)-2LL)
comment|/**  * Set the multicast list.  *  * @param port   Management port  * @param flags  Interface flags  *  * @return  */
specifier|extern
name|void
name|cvmx_mgmt_port_set_multicast_list
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
comment|/**  * Set the maximum packet allowed in. Size is specified  * including L2 but without FCS. A normal MTU would corespond  * to 1514 assuming the standard 14 byte L2 header.  *  * @param port   Management port  * @param size_without_fcs  *               Size in bytes without FCS  */
specifier|extern
name|void
name|cvmx_mgmt_port_set_max_packet_size
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|size_without_fcs
parameter_list|)
function_decl|;
comment|/**  * Return the link state of an RGMII/MII port as returned by  * auto negotiation. The result of this function may not match  * Octeon's link config if auto negotiation has changed since  * the last call to __cvmx_mgmt_port_link_set().  *  * @param port     The RGMII/MII interface port to query  *  * @return Link state  */
specifier|extern
name|cvmx_helper_link_info_t
name|cvmx_mgmt_port_link_get
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
comment|/**  * Configure RGMII/MII port for the specified link state. This  * function does not influence auto negotiation at the PHY level.  *  * @param port      RGMII/MII interface port  * @param link_info The new link state  *  * @return Zero on success, negative on failure  */
specifier|extern
name|int
name|cvmx_mgmt_port_link_set
parameter_list|(
name|int
name|port
parameter_list|,
name|cvmx_helper_link_info_t
name|link_info
parameter_list|)
function_decl|;
comment|/**  * Return the number of management ports supported on this board.  *  * @return Number of ports  */
specifier|extern
name|int
name|cvmx_mgmt_port_num_ports
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
comment|/* __CVMX_MGMT_PORT_H__ */
end_comment

end_unit

