begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_PORT_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the interface methods that can be called  *        by an SCI Core user on a SAS or SATA port.  */
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
comment|// __cplusplus
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
include|#
directive|include
file|<dev/isci/scil/sci_status.h>
include|#
directive|include
file|<dev/isci/scil/intel_sas.h>
enum|enum
name|SCIC_PORT_NOT_READY_REASON_CODE
block|{
name|SCIC_PORT_NOT_READY_NO_ACTIVE_PHYS
block|,
name|SCIC_PORT_NOT_READY_HARD_RESET_REQUESTED
block|,
name|SCIC_PORT_NOT_READY_INVALID_PORT_CONFIGURATION
block|,
name|SCIC_PORT_NOT_READY_RECONFIGURING
block|,
name|SCIC_PORT_NOT_READY_REASON_CODE_MAX
block|}
enum|;
comment|/**  * @struct SCIC_PORT_END_POINT_PROPERTIES  * @brief  This structure defines the properties that can be retrieved  *         for each end-point local or remote (attached) port in the  *         controller.  */
typedef|typedef
struct|struct
name|SCIC_PORT_END_POINT_PROPERTIES
block|{
comment|/**     * This field indicates the SAS address for the associated end     * point in the port.     */
name|SCI_SAS_ADDRESS_T
name|sas_address
decl_stmt|;
comment|/**     * This field indicates the protocols supported by the associated     * end-point in the port.     */
name|SCI_SAS_IDENTIFY_ADDRESS_FRAME_PROTOCOLS_T
name|protocols
decl_stmt|;
block|}
name|SCIC_PORT_END_POINT_PROPERTIES_T
typedef|;
comment|/**  * @struct SCIC_PORT_PROPERTIES  * @brief  This structure defines the properties that can be retrieved  *         for each port in the controller.  */
typedef|typedef
struct|struct
name|SCIC_PORT_PROPERTIES
block|{
comment|/**     * This field specifies the logical index of the port (0 relative).     */
name|U32
name|index
decl_stmt|;
comment|/**     * This field indicates the local end-point properties for port.     */
name|SCIC_PORT_END_POINT_PROPERTIES_T
name|local
decl_stmt|;
comment|/**     * This field indicates the remote (attached) end-point properties     * for the port.     */
name|SCIC_PORT_END_POINT_PROPERTIES_T
name|remote
decl_stmt|;
comment|/**     * This field specifies the phys contained inside the port.     */
name|U32
name|phy_mask
decl_stmt|;
block|}
name|SCIC_PORT_PROPERTIES_T
typedef|;
comment|/**  * @brief This method simply returns the properties regarding the  *        port, such as: physical index, protocols, sas address, etc.  *  * @param[in]  port this parameter specifies the port for which to retrieve  *             the physical index.  * @param[out] properties This parameter specifies the properties  *             structure into which to copy the requested information.  *  * @return Indicate if the user specified a valid port.  * @retval SCI_SUCCESS This value is returned if the specified port was valid.  * @retval SCI_FAILURE_INVALID_PORT This value is returned if the specified port  *         is not valid.  When this value is returned, no data is copied to the  *         properties output parameter.  */
name|SCI_STATUS
name|scic_port_get_properties
parameter_list|(
name|SCI_PORT_HANDLE_T
name|port
parameter_list|,
name|SCIC_PORT_PROPERTIES_T
modifier|*
name|properties
parameter_list|)
function_decl|;
comment|/**  * @brief This method will add a phy to an existing port.  *  * @param[in]  port This parameter specifies the port in which to add a new  *             phy.  * @param[in]  phy This parameter specifies the phy to be added to the port.  *  * @return Indicate if the phy was successfully added to the port.  * @retval SCI_SUCCESS This value is returned if the phy was successfully  *         added to the port.  * @retval SCI_FAILURE_INVALID_PORT This value is returned if the supplied  *         port is not valid.  * @retval SCI_FAILURE_INVALID_PHY This value is returned if the supplied  *         phy is either invalid or already contained in another port.  */
name|SCI_STATUS
name|scic_port_add_phy
parameter_list|(
name|SCI_PORT_HANDLE_T
name|port
parameter_list|,
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|)
function_decl|;
comment|/**  * @brief This method will remove a phy from an existing port.  *  * @param[in]  port This parameter specifies the port in which to remove a  *             phy.  * @param[in]  phy This parameter specifies the phy to be removed from the  *             port.  *  * @return Indicate if the phy was successfully removed from the port.  * @retval SCI_SUCCESS This value is returned if the phy was successfully  *         removed from the port.  * @retval SCI_FAILURE_INVALID_PORT This value is returned if the supplied  *         port is not valid.  * @retval SCI_FAILURE_INVALID_PHY This value is returned if the supplied  *         phy is either invalid or  *         not contained in the port.  */
name|SCI_STATUS
name|scic_port_remove_phy
parameter_list|(
name|SCI_PORT_HANDLE_T
name|port
parameter_list|,
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|)
function_decl|;
comment|/**  * @brief This method will request the SCI implementation to perform a  *        HARD RESET on the SAS Port.  If/When the HARD RESET completes  *        the SCI user will be notified via an SCI OS callback indicating  *        a direct attached device was found.  *  * @note The SCI User callback in SCIC_USER_CALLBACKS_T will only be called  *       once for each phy in the SAS Port at completion of the hard reset  *       sequence.  *  * @param[in]  port a handle corresponding to the SAS port to be  *             hard reset.  * @param[in]  reset_timeout This parameter specifies the number of  *             milliseconds in which the port reset operation should complete.  *  * @return Return a status indicating whether the hard reset started  *         successfully.  * @retval SCI_SUCCESS This value is returned if the hard reset operation  *         started successfully.  */
name|SCI_STATUS
name|scic_port_hard_reset
parameter_list|(
name|SCI_PORT_HANDLE_T
name|port
parameter_list|,
name|U32
name|reset_timeout
parameter_list|)
function_decl|;
comment|/**  * @brief This API method enables the broadcast change notification from  *        underneath hardware.  *  * @param[in] port The port upon which broadcast change notifications  *            (BCN) are to be enabled.  *  * @return none  */
name|void
name|scic_port_enable_broadcast_change_notification
parameter_list|(
name|SCI_PORT_HANDLE_T
name|port
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

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCIC_PORT_H_
end_comment

end_unit

