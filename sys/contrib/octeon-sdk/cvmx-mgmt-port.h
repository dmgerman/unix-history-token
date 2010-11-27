begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Support functions for managing the MII management port  *  *<hr>$Revision: 42115 $<hr>  */
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

begin_define
define|#
directive|define
name|CVMX_MGMT_PORT_NUM_PORTS
value|2
end_define

begin_comment
comment|/* Right now we only have one mgmt port */
end_comment

begin_define
define|#
directive|define
name|CVMX_MGMT_PORT_NUM_TX_BUFFERS
value|16
end_define

begin_comment
comment|/* Number of TX ring buffer entries and buffers */
end_comment

begin_define
define|#
directive|define
name|CVMX_MGMT_PORT_NUM_RX_BUFFERS
value|128
end_define

begin_comment
comment|/* Number of RX ring buffer entries and buffers */
end_comment

begin_define
define|#
directive|define
name|CVMX_MGMT_PORT_TX_BUFFER_SIZE
value|12288
end_define

begin_comment
comment|/* Size of each TX/RX buffer */
end_comment

begin_define
define|#
directive|define
name|CVMX_MGMT_PORT_RX_BUFFER_SIZE
value|1536
end_define

begin_comment
comment|/* Size of each TX/RX buffer */
end_comment

begin_typedef
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
block|, }
name|cvmx_mgmt_port_result_t
typedef|;
end_typedef

begin_comment
comment|/* Enumeration of Net Device interface flags. */
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/**  * Called to initialize a management port for use. Multiple calls  * to this function accross applications is safe.  *  * @param port   Port to initialize  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
end_comment

begin_function_decl
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_initialize
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Shutdown a management port. This currently disables packet IO  * but leaves all hardware and buffers. Another application can then  * call initialize() without redoing the hardware setup.  *  * @param port   Management port  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
end_comment

begin_function_decl
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_shutdown
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Enable packet IO on a management port  *  * @param port   Management port  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
end_comment

begin_function_decl
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_enable
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Disable packet IO on a management port  *  * @param port   Management port  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
end_comment

begin_function_decl
specifier|extern
name|cvmx_mgmt_port_result_t
name|cvmx_mgmt_port_disable
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Send a packet out the management port. The packet is copied so  * the input buffer isn't used after this call.  *  * @param port       Management port  * @param packet_len Length of the packet to send. It does not include the final CRC  * @param buffer     Packet data  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/**  * Receive a packet from the management port.  *  * @param port       Management port  * @param buffer_len Size of the buffer to receive the packet into  * @param buffer     Buffer to receive the packet into  *  * @return The size of the packet, or a negative erorr code on failure. Zero  *         means that no packets were available.  */
end_comment

begin_function_decl
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
name|void
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the management port link status:  * 100 = 100Mbps, full duplex  * 10 = 10Mbps, full duplex  * 0 = Link down  * -10 = 10Mpbs, half duplex  * -100 = 100Mbps, half duplex  *  * @param port   Management port  *  * @return  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_mgmt_port_get_link
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the MAC address for a management port  *  * @param port   Management port  * @param mac    New MAC address. The lower 6 bytes are used.  *  * @return CVMX_MGMT_PORT_SUCCESS or an error code  */
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/**  * Get the MAC address for a management port  *  * @param port   Management port  *  * @return MAC address  */
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|cvmx_mgmt_port_get_mac
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the multicast list.  *  * @param port   Management port  * @param flags  Interface flags  *  * @return  */
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/**  * Set the maximum packet allowed in. Size is specified  * including L2 but without FCS. A normal MTU would corespond  * to 1514 assuming the standard 14 byte L2 header.  *  * @param port   Management port  * @param size_without_crc  *               Size in bytes without FCS  */
end_comment

begin_function_decl
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
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_MGMT_PORT_H__ */
end_comment

end_unit

