begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_PHY_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the interface methods that can be called  *        by an SCIC user on a phy (SAS or SATA) object.  */
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
file|<dev/isci/scil/intel_sata.h>
include|#
directive|include
file|<dev/isci/scil/intel_sas.h>
comment|/**  * @struct SCIC_PHY_PROPERTIES  * @brief This structure defines the properties common to all phys  *        that can be retrieved.  */
typedef|typedef
struct|struct
name|SCIC_PHY_PROPERTIES
block|{
comment|/**     * This field specifies the port that currently contains the     * supplied phy.  This field may be set to SCI_INVALID_HANDLE     * if the phy is not currently contained in a port.     */
name|SCI_PORT_HANDLE_T
name|owning_port
decl_stmt|;
comment|/**     * This field specifies the maximum link rate for which this phy     * will negotiate.     */
name|SCI_SAS_LINK_RATE
name|max_link_rate
decl_stmt|;
comment|/**     * This field specifies the link rate at which the phy is     * currently operating.     */
name|SCI_SAS_LINK_RATE
name|negotiated_link_rate
decl_stmt|;
comment|/**     * This field indicates the identify address frame that will be     * transmitted to the connected phy.     */
name|SCI_SAS_IDENTIFY_ADDRESS_FRAME_T
name|transmit_iaf
decl_stmt|;
comment|/**     * This field specifies the index of the phy in relation to other     * phys within the controller.  This index is zero relative.     */
name|U8
name|index
decl_stmt|;
block|}
name|SCIC_PHY_PROPERTIES_T
typedef|;
comment|/**  * @struct SCIC_SAS_PHY_PROPERTIES  * @brief This structure defines the properties, specific to a  *        SAS phy, that can be retrieved.  */
typedef|typedef
struct|struct
name|SCIC_SAS_PHY_PROPERTIES
block|{
comment|/**     * This field delineates the Identify Address Frame received     * from the remote end point.     */
name|SCI_SAS_IDENTIFY_ADDRESS_FRAME_T
name|received_iaf
decl_stmt|;
comment|/**     * This field delineates the Phy capabilities structure received     * from the remote end point.     */
name|SAS_CAPABILITIES_T
name|received_capabilities
decl_stmt|;
block|}
name|SCIC_SAS_PHY_PROPERTIES_T
typedef|;
comment|/**  * @struct SCIC_SATA_PHY_PROPERTIES  * @brief This structure defines the properties, specific to a  *        SATA phy, that can be retrieved.  */
typedef|typedef
struct|struct
name|SCIC_SATA_PHY_PROPERTIES
block|{
comment|/**     * This field delineates the signature FIS received from the     * attached target.     */
name|SATA_FIS_REG_D2H_T
name|signature_fis
decl_stmt|;
comment|/**     * This field specifies to the user if a port selector is connected     * on the specified phy.     */
name|BOOL
name|is_port_selector_present
decl_stmt|;
block|}
name|SCIC_SATA_PHY_PROPERTIES_T
typedef|;
comment|/**  * @enum  SCIC_PHY_COUNTER_ID  * @brief This enumeration depicts the various pieces of optional  *        information that can be retrieved for a specific phy.  */
typedef|typedef
enum|enum
name|SCIC_PHY_COUNTER_ID
block|{
comment|/**     * This PHY information field tracks the number of frames received.     */
name|SCIC_PHY_COUNTER_RECEIVED_FRAME
block|,
comment|/**     * This PHY information field tracks the number of frames transmitted.     */
name|SCIC_PHY_COUNTER_TRANSMITTED_FRAME
block|,
comment|/**     * This PHY information field tracks the number of DWORDs received.     */
name|SCIC_PHY_COUNTER_RECEIVED_FRAME_DWORD
block|,
comment|/**     * This PHY information field tracks the number of DWORDs transmitted.     */
name|SCIC_PHY_COUNTER_TRANSMITTED_FRAME_DWORD
block|,
comment|/**     * This PHY information field tracks the number of times DWORD     * synchronization was lost.     */
name|SCIC_PHY_COUNTER_LOSS_OF_SYNC_ERROR
block|,
comment|/**     * This PHY information field tracks the number of received DWORDs with     * running disparity errors.     */
name|SCIC_PHY_COUNTER_RECEIVED_DISPARITY_ERROR
block|,
comment|/**     * This PHY information field tracks the number of received frames with a     * CRC error (not including short or truncated frames).     */
name|SCIC_PHY_COUNTER_RECEIVED_FRAME_CRC_ERROR
block|,
comment|/**     * This PHY information field tracks the number of DONE (ACK/NAK TIMEOUT)     * primitives received.     */
name|SCIC_PHY_COUNTER_RECEIVED_DONE_ACK_NAK_TIMEOUT
block|,
comment|/**     * This PHY information field tracks the number of DONE (ACK/NAK TIMEOUT)     * primitives transmitted.     */
name|SCIC_PHY_COUNTER_TRANSMITTED_DONE_ACK_NAK_TIMEOUT
block|,
comment|/**     * This PHY information field tracks the number of times the inactivity     * timer for connections on the phy has been utilized.     */
name|SCIC_PHY_COUNTER_INACTIVITY_TIMER_EXPIRED
block|,
comment|/**     * This PHY information field tracks the number of DONE (CREDIT TIMEOUT)     * primitives received.     */
name|SCIC_PHY_COUNTER_RECEIVED_DONE_CREDIT_TIMEOUT
block|,
comment|/**     * This PHY information field tracks the number of DONE (CREDIT TIMEOUT)     * primitives transmitted.     */
name|SCIC_PHY_COUNTER_TRANSMITTED_DONE_CREDIT_TIMEOUT
block|,
comment|/**     * This PHY information field tracks the number of CREDIT BLOCKED     * primitives received.     * @note Depending on remote device implementation, credit blocks     *       may occur regularly.     */
name|SCIC_PHY_COUNTER_RECEIVED_CREDIT_BLOCKED
block|,
comment|/**     * This PHY information field contains the number of short frames     * received.  A short frame is simply a frame smaller then what is     * allowed by either the SAS or SATA specification.     */
name|SCIC_PHY_COUNTER_RECEIVED_SHORT_FRAME
block|,
comment|/**     * This PHY information field contains the number of frames received after     * credit has been exhausted.     */
name|SCIC_PHY_COUNTER_RECEIVED_FRAME_WITHOUT_CREDIT
block|,
comment|/**     * This PHY information field contains the number of frames received after     * a DONE has been received.     */
name|SCIC_PHY_COUNTER_RECEIVED_FRAME_AFTER_DONE
block|,
comment|/**     * This PHY information field contains the number of times the phy     * failed to achieve DWORD synchronization during speed negotiation.     */
name|SCIC_PHY_COUNTER_SN_DWORD_SYNC_ERROR
block|}
name|SCIC_PHY_COUNTER_ID_T
typedef|;
comment|/**  * @brief This method will enable the user to retrieve information  *        common to all phys, such as: the negotiated link rate,  *        the phy id, etc.  *  * @param[in]  phy This parameter specifies the phy for which to retrieve  *             the properties.  * @param[out] properties This parameter specifies the properties  *             structure into which to copy the requested information.  *  * @return Indicate if the user specified a valid phy.  * @retval SCI_SUCCESS This value is returned if the specified phy was valid.  * @retval SCI_FAILURE_INVALID_PHY This value is returned if the specified phy  *         is not valid.  When this value is returned, no data is copied to the  *         properties output parameter.  */
name|SCI_STATUS
name|scic_phy_get_properties
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|,
name|SCIC_PHY_PROPERTIES_T
modifier|*
name|properties
parameter_list|)
function_decl|;
comment|/**  * @brief This method will enable the user to retrieve information  *        specific to a SAS phy, such as: the received identify  *        address frame, received phy capabilities, etc.  *  * @param[in]  phy this parameter specifies the phy for which to  *             retrieve properties.  * @param[out] properties This parameter specifies the properties  *             structure into which to copy the requested information.  *  * @return This method returns an indication as to whether the SAS  *         phy properties were successfully retrieved.  * @retval SCI_SUCCESS This value is returned if the SAS properties  *         are successfully retrieved.  * @retval SCI_FAILURE This value is returned if the SAS properties  *         are not successfully retrieved (e.g. It's not a SAS Phy).  */
name|SCI_STATUS
name|scic_sas_phy_get_properties
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|,
name|SCIC_SAS_PHY_PROPERTIES_T
modifier|*
name|properties
parameter_list|)
function_decl|;
comment|/**  * @brief This method will enable the user to retrieve information  *        specific to a SATA phy, such as: the recieved signature  *        FIS, if a port selector is present, etc.  *  * @param[in]  phy this parameter specifies the phy for which to  *             retrieve properties.  * @param[out] properties This parameter specifies the properties  *             structure into which to copy the requested information.  *  * @return This method returns an indication as to whether the SATA  *         phy properties were successfully retrieved.  * @retval SCI_SUCCESS This value is returned if the SATA properties  *         are successfully retrieved.  * @retval SCI_FAILURE This value is returned if the SATA properties  *         are not successfully retrieved (e.g. It's not a SATA Phy).  */
name|SCI_STATUS
name|scic_sata_phy_get_properties
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|,
name|SCIC_SATA_PHY_PROPERTIES_T
modifier|*
name|properties
parameter_list|)
function_decl|;
comment|/**  * @brief This method allows the SCIC user to instruct the SCIC  *        implementation to send the SATA port selection signal.  *  * @param[in]  phy this parameter specifies the phy for which to send  *             the port selection signal.  *  * @return An indication of whether the port selection signal was  *         successfully executed.  * @retval SCI_SUCCESS This value is returned if the port selection signal  *         was successfully transmitted.  */
name|SCI_STATUS
name|scic_sata_phy_send_port_selection_signal
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|)
function_decl|;
comment|/**  * @brief This method requests the SCI implementation to begin tracking  *        information specified by the supplied parameters.  *  * @param[in]  phy this parameter specifies the phy for which to enable  *             the information type.  * @param[in]  counter_id this parameter specifies the information  *             type to be enabled.  *  * @return Indicate if enablement of the information type was successful.  * @retval SCI_SUCCESS This value is returned if the information type was  *         successfully enabled.  * @retval SCI_FAILURE_UNSUPPORTED_INFORMATION_FIELD This value is returned  *         if the supplied information type is not supported.  */
name|SCI_STATUS
name|scic_phy_enable_counter
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|,
name|SCIC_PHY_COUNTER_ID_T
name|counter_id
parameter_list|)
function_decl|;
comment|/**  * @brief This method requests the SCI implementation to stop tracking  *        information specified by the supplied parameters.  *  * @param[in]  phy this parameter specifies the phy for which to disable  *             the information type.  * @param[in]  counter_id this parameter specifies the information  *             type to be disabled.  *  * @return Indicate if disablement of the information type was successful.  * @retval SCI_SUCCESS This value is returned if the information type was  *         successfully disabled.  * @retval SCI_FAILURE_UNSUPPORTED_INFORMATION_FIELD This value is returned  *         if the supplied information type is not supported.  */
name|SCI_STATUS
name|scic_phy_disable_counter
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|,
name|SCIC_PHY_COUNTER_ID_T
name|counter_id
parameter_list|)
function_decl|;
comment|/**  * @brief This method requests the SCI implementation to retrieve  *        tracking information specified by the supplied parameters.  *  * @param[in]  phy this parameter specifies the phy for which to retrieve  *             the information type.  * @param[in]  counter_id this parameter specifies the information  *             type to be retrieved.  * @param[out] data this parameter is a 32-bit pointer to a location  *             where the data being retrieved is to be placed.  *  * @return Indicate if retrieval of the information type was successful.  * @retval SCI_SUCCESS This value is returned if the information type was  *         successfully retrieved.  * @retval SCI_FAILURE_UNSUPPORTED_INFORMATION_FIELD This value is returned  *         if the supplied information type is not supported.  */
name|SCI_STATUS
name|scic_phy_get_counter
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|,
name|SCIC_PHY_COUNTER_ID_T
name|counter_id
parameter_list|,
name|U32
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * @brief This method requests the SCI implementation to clear (reset)  *        tracking information specified by the supplied parameters.  *  * @param[in]  phy this parameter specifies the phy for which to clear  *             the information type.  * @param[in]  counter_id this parameter specifies the information  *             type to be cleared.  *  * @return Indicate if clearing of the information type was successful.  * @retval SCI_SUCCESS This value is returned if the information type was  *         successfully cleared.  * @retval SCI_FAILURE_UNSUPPORTED_INFORMATION_FIELD This value is returned  *         if the supplied information type is not supported.  */
name|SCI_STATUS
name|scic_phy_clear_counter
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|,
name|SCIC_PHY_COUNTER_ID_T
name|counter_id
parameter_list|)
function_decl|;
comment|/**  * @brief This method will attempt to stop the phy object.  *  * @param[in] this_phy  *  * @return SCI_STATUS  * @retval SCI_SUCCESS if the phy is going to stop  *         SCI_INVALID_STATE if the phy is not in a valid state  *         to stop  */
name|SCI_STATUS
name|scic_phy_stop
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
parameter_list|)
function_decl|;
comment|/**  * @brief This method will attempt to start the phy object. This  *        request is only valid when the phy is in the stopped  *        state  *  * @param[in] this_phy  *  * @return SCI_STATUS  */
name|SCI_STATUS
name|scic_phy_start
parameter_list|(
name|SCI_PHY_HANDLE_T
name|phy
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
comment|// _SCIC_PHY_H_
end_comment

end_unit

