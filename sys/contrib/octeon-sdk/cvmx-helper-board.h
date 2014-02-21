begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Helper functions to abstract board specific data about  * network ports from the rest of the cvmx-helper files.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_BOARD_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_BOARD_H__
end_define

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
name|USB_CLOCK_TYPE_REF_12
block|,
name|USB_CLOCK_TYPE_REF_24
block|,
name|USB_CLOCK_TYPE_REF_48
block|,
name|USB_CLOCK_TYPE_CRYSTAL_12
block|, }
name|cvmx_helper_board_usb_clock_types_t
typedef|;
typedef|typedef
enum|enum
block|{
name|BROADCOM_GENERIC_PHY
block|,
name|MARVELL_GENERIC_PHY
block|, }
name|cvmx_phy_type_t
typedef|;
typedef|typedef
enum|enum
block|{
name|set_phy_link_flags_autoneg
init|=
literal|0x1
block|,
name|set_phy_link_flags_flow_control_dont_touch
init|=
literal|0x0
operator|<<
literal|1
block|,
name|set_phy_link_flags_flow_control_enable
init|=
literal|0x1
operator|<<
literal|1
block|,
name|set_phy_link_flags_flow_control_disable
init|=
literal|0x2
operator|<<
literal|1
block|,
name|set_phy_link_flags_flow_control_mask
init|=
literal|0x3
operator|<<
literal|1
block|,
comment|/* Mask for 2 bit wide flow control field */
block|}
name|cvmx_helper_board_set_phy_link_flags_types_t
typedef|;
comment|/* Fake IPD port, the RGMII/MII interface may use different PHY, use this    macro to return appropriate MIX address to read the PHY. */
define|#
directive|define
name|CVMX_HELPER_BOARD_MGMT_IPD_PORT
value|-10
comment|/**  * cvmx_override_board_link_get(int ipd_port) is a function  * pointer. It is meant to allow customization of the process of  * talking to a PHY to determine link speed. It is called every  * time a PHY must be polled for link status. Users should set  * this pointer to a function before calling any cvmx-helper  * operations.  */
specifier|extern
name|cvmx_helper_link_info_t
function_decl|(
modifier|*
name|cvmx_override_board_link_get
function_decl|)
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/**  * Return the MII PHY address associated with the given IPD  * port. A result of -1 means there isn't a MII capable PHY  * connected to this port. On chips supporting multiple MII  * busses the bus number is encoded in bits<15:8>.  *  * This function must be modified for every new Octeon board.  * Internally it uses switch statements based on the cvmx_sysinfo  * data to determine board types and revisions. It relies on the  * fact that every Octeon board receives a unique board type  * enumeration from the bootloader.  *  * @param ipd_port Octeon IPD port to get the MII address for.  *  * @return MII PHY address and bus number or -1.  */
specifier|extern
name|int
name|cvmx_helper_board_get_mii_address
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/**  * This function as a board specific method of changing the PHY  * speed, duplex, and autonegotiation. This programs the PHY and  * not Octeon. This can be used to force Octeon's links to  * specific settings.  *  * @param phy_addr  The address of the PHY to program  * @param link_flags  *                  Flags to control autonegotiation.  Bit 0 is autonegotiation  *                  enable/disable to maintain backward compatibility.  * @param link_info Link speed to program. If the speed is zero and autonegotiation  *                  is enabled, all possible negotiation speeds are advertised.  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_helper_board_link_set_phy
parameter_list|(
name|int
name|phy_addr
parameter_list|,
name|cvmx_helper_board_set_phy_link_flags_types_t
name|link_flags
parameter_list|,
name|cvmx_helper_link_info_t
name|link_info
parameter_list|)
function_decl|;
comment|/**  * @INTERNAL  * This function is the board specific method of determining an  * ethernet ports link speed. Most Octeon boards have Marvell PHYs  * and are handled by the fall through case. This function must be  * updated for boards that don't have the normal Marvell PHYs.  *  * This function must be modified for every new Octeon board.  * Internally it uses switch statements based on the cvmx_sysinfo  * data to determine board types and revisions. It relies on the  * fact that every Octeon board receives a unique board type  * enumeration from the bootloader.  *  * @param ipd_port IPD input port associated with the port we want to get link  *                 status for.  *  * @return The ports link status. If the link isn't fully resolved, this must  *         return zero.  */
specifier|extern
name|cvmx_helper_link_info_t
name|__cvmx_helper_board_link_get
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
comment|/**  * @INTERNAL  * This function is called by cvmx_helper_interface_probe() after it  * determines the number of ports Octeon can support on a specific  * interface. This function is the per board location to override  * this value. It is called with the number of ports Octeon might  * support and should return the number of actual ports on the  * board.  *  * This function must be modified for every new Octeon board.  * Internally it uses switch statements based on the cvmx_sysinfo  * data to determine board types and revisions. It relies on the  * fact that every Octeon board receives a unique board type  * enumeration from the bootloader.  *  * @param interface Interface to probe  * @param supported_ports  *                  Number of ports Octeon supports.  *  * @return Number of ports the actual board supports. Many times this will  *         simple be "support_ports".  */
specifier|extern
name|int
name|__cvmx_helper_board_interface_probe
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|supported_ports
parameter_list|)
function_decl|;
comment|/**  * @INTERNAL  * Enable packet input/output from the hardware. This function is  * called after by cvmx_helper_packet_hardware_enable() to  * perform board specific initialization. For most boards  * nothing is needed.  *  * @param interface Interface to enable  *  * @return Zero on success, negative on failure  */
specifier|extern
name|int
name|__cvmx_helper_board_hardware_enable
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
comment|/**  * @INTERNAL  * Gets the clock type used for the USB block based on board type.  * Used by the USB code for auto configuration of clock type.  *  * @return USB clock type enumeration  */
name|cvmx_helper_board_usb_clock_types_t
name|__cvmx_helper_board_usb_get_clock_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * @INTERNAL  * Adjusts the number of available USB ports on Octeon based on board  * specifics.  *  * @param supported_ports expected number of ports based on chip type;  *  *  * @return number of available usb ports, based on board specifics.  *         Return value is supported_ports if function does not  *         override.  */
name|int
name|__cvmx_helper_board_usb_get_num_ports
parameter_list|(
name|int
name|supported_ports
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
comment|/* __CVMX_HELPER_BOARD_H__ */
end_comment

end_unit

