begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_USER_PARAMETERS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_USER_PARAMETERS_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structure definitions and interface  *        methods that can be called by a SCIC user on the SCU Driver  *        Standard (SCIC_SDS_USER_PARAMETERS_T) user parameter block.  */
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
include|#
directive|include
file|<dev/isci/scil/sci_controller_constants.h>
include|#
directive|include
file|<dev/isci/scil/scu_bios_definitions.h>
comment|/**  * @name SCIC_SDS_PARM_PHY_SPEED  *  * These constants define the speeds utilized for a phy/port.  */
comment|/*@{*/
define|#
directive|define
name|SCIC_SDS_PARM_NO_SPEED
value|0
comment|/**  * This value of 1 indicates generation 1 (i.e. 1.5 Gb/s).  */
define|#
directive|define
name|SCIC_SDS_PARM_GEN1_SPEED
value|1
comment|/**  * This value of 2 indicates generation 2 (i.e. 3.0 Gb/s).  */
define|#
directive|define
name|SCIC_SDS_PARM_GEN2_SPEED
value|2
comment|/**  * This value of 3 indicates generation 3 (i.e. 6.0 Gb/s).  */
define|#
directive|define
name|SCIC_SDS_PARM_GEN3_SPEED
value|3
comment|/**  * For range checks, the max speed generation  */
define|#
directive|define
name|SCIC_SDS_PARM_MAX_SPEED
value|SCIC_SDS_PARM_GEN3_SPEED
comment|/*@}*/
comment|/**  * @struct SCIC_SDS_USER_PARAMETERS  *  * @brief This structure delineates the various user parameters that can be  *        changed by the core user.  */
typedef|typedef
struct|struct
name|SCIC_SDS_USER_PARAMETERS
block|{
struct|struct
block|{
comment|/**        * This field specifies the NOTIFY (ENABLE SPIN UP) primitive        * insertion frequency for this phy index.        */
name|U32
name|notify_enable_spin_up_insertion_frequency
decl_stmt|;
comment|/**        * This method specifies the number of transmitted DWORDs within which        * to transmit a single ALIGN primitive.  This value applies regardless        * of what type of device is attached or connection state.  A value of        * 0 indicates that no ALIGN primitives will be inserted.        */
name|U16
name|align_insertion_frequency
decl_stmt|;
comment|/**        * This method specifies the number of transmitted DWORDs within which        * to transmit 2 ALIGN primitives.  This applies for SAS connections        * only.  A minimum value of 3 is required for this field.        */
name|U16
name|in_connection_align_insertion_frequency
decl_stmt|;
comment|/**        * This field indicates the maximum speed generation to be utilized        * by phys in the supplied port.        * - A value of 1 indicates generation 1 (i.e. 1.5 Gb/s).        * - A value of 2 indicates generation 2 (i.e. 3.0 Gb/s).        * - A value of 3 indicates generation 3 (i.e. 6.0 Gb/s).        */
name|U8
name|max_speed_generation
decl_stmt|;
block|}
name|phys
index|[
name|SCI_MAX_PHYS
index|]
struct|;
comment|/**     * This field specifies the number of seconds to allow a phy to consume     * power before yielding to another phy.     *     */
name|U8
name|phy_spin_up_delay_interval
decl_stmt|;
comment|/**    * These timer values specifies how long a link will remain open with no    * activity in increments of a microsecond, it can be in increments of    * 100 microseconds if the upper most bit is set.    *    */
name|U16
name|stp_inactivity_timeout
decl_stmt|;
name|U16
name|ssp_inactivity_timeout
decl_stmt|;
comment|/**    * These timer values specifies how long a link will remain open in increments    * of 100 microseconds.    *    */
name|U16
name|stp_max_occupancy_timeout
decl_stmt|;
name|U16
name|ssp_max_occupancy_timeout
decl_stmt|;
comment|/**    * This timer value specifies how long a link will remain open with no    * outbound traffic in increments of a microsecond.    *    */
name|U8
name|no_outbound_task_timeout
decl_stmt|;
block|}
name|SCIC_SDS_USER_PARAMETERS_T
typedef|;
comment|/**  * @union SCIC_USER_PARAMETERS  * @brief This structure/union specifies the various different user  *        parameter sets available.  Each type is specific to a hardware  *        controller version.  */
typedef|typedef
union|union
name|SCIC_USER_PARAMETERS
block|{
comment|/**     * This field specifies the user parameters specific to the     * Storage Controller Unit (SCU) Driver Standard (SDS) version     * 1.     */
name|SCIC_SDS_USER_PARAMETERS_T
name|sds1
decl_stmt|;
block|}
name|SCIC_USER_PARAMETERS_T
typedef|;
comment|/**  * @name SCIC_SDS_OEM_PHY_MASK  *  * These constants define the valid values for phy_mask  */
comment|/*@{*/
comment|/**  * This is the min value assignable to a port's phy mask  */
define|#
directive|define
name|SCIC_SDS_PARM_PHY_MASK_MIN
value|0x0
comment|/**  * This is the max value assignable to a port's phy mask  */
define|#
directive|define
name|SCIC_SDS_PARM_PHY_MASK_MAX
value|0xF
comment|/*@}*/
define|#
directive|define
name|MAX_CONCURRENT_DEVICE_SPIN_UP_COUNT
value|4
typedef|typedef
name|SCI_BIOS_OEM_PARAM_ELEMENT_v_1_3_T
name|SCIC_SDS_OEM_PARAMETERS_T
typedef|;
comment|/**  * @union SCIC_OEM_PARAMETERS  *  * @brief This structure/union specifies the various different OEM  *        parameter sets available.  Each type is specific to a hardware  *        controller version.  */
typedef|typedef
union|union
name|SCIC_OEM_PARAMETERS
block|{
comment|/**     * This field specifies the OEM parameters specific to the     * Storage Controller Unit (SCU) Driver Standard (SDS) version     * 1.     */
name|SCIC_SDS_OEM_PARAMETERS_T
name|sds1
decl_stmt|;
block|}
name|SCIC_OEM_PARAMETERS_T
typedef|;
comment|/**  * @union OEM_SSC_DATA  *  * @brief This typedef provides a means to convert from the original  *        1.0 version of the OEM PARAMETER do_enable_ssc to the more  *        comprehensive 1.1 version of enabling SSC parameters.  *        For the definition of the field members see scu_bios_definitions.h  *        header file or refer to the SCU BIOS Writers Guide.  */
typedef|typedef
union|union
name|OEM_SSC_PARAMETERS
block|{
struct|struct
block|{
name|U8
name|ssc_sata_tx_spread_level
range|:
literal|4
decl_stmt|;
name|U8
name|ssc_sas_tx_spread_level
range|:
literal|3
decl_stmt|;
name|U8
name|ssc_sas_tx_type
range|:
literal|1
decl_stmt|;
block|}
name|bf
struct|;
name|U8
name|do_enable_ssc
decl_stmt|;
block|}
name|OEM_SSC_PARAMETERS_T
typedef|;
comment|/**  * @brief This method allows the user to attempt to change the user  *        parameters utilized by the controller.  *  * @param[in] controller This parameter specifies the controller on which  *            to set the user parameters.  * @param[in] user_parameters This parameter specifies the USER_PARAMETERS  *            object containing the potential new values.  *  * @return Indicate if the update of the user parameters was successful.  * @retval SCI_SUCCESS This value is returned if the operation succeeded.  * @retval SCI_FAILURE_INVALID_STATE This value is returned if the attempt  *         to change the user parameter failed, because changing one of  *         the parameters is not currently allowed.  * @retval SCI_FAILURE_INVALID_PARAMETER_VALUE This value is returned if the  *         user supplied an invalid interrupt coalescence time, spin up  *         delay interval, etc.  */
name|SCI_STATUS
name|scic_user_parameters_set
parameter_list|(
name|SCI_CONTROLLER_HANDLE_T
name|controller
parameter_list|,
name|SCIC_USER_PARAMETERS_T
modifier|*
name|user_parameters
parameter_list|)
function_decl|;
comment|/**  * @brief This method allows the user to retrieve the user parameters  *        utilized by the controller.  *  * @param[in] controller This parameter specifies the controller on which  *            to set the user parameters.  * @param[in] user_parameters This parameter specifies the USER_PARAMETERS  *            object into which the framework shall save it's parameters.  *  * @return none  */
name|void
name|scic_user_parameters_get
parameter_list|(
name|SCI_CONTROLLER_HANDLE_T
name|controller
parameter_list|,
name|SCIC_USER_PARAMETERS_T
modifier|*
name|user_parameters
parameter_list|)
function_decl|;
comment|/**  * @brief This method allows the user to attempt to change the OEM  *        parameters utilized by the controller.  *  * @param[in] controller This parameter specifies the controller on which  *            to set the user parameters.  * @param[in] oem_parameters This parameter specifies the OEM parameters  *            object containing the potential new values.  * @param[in] oem_parameters_version This parameter is the OEM block version  *            value indicating the format of the data associated with  *            oem_parameters.  *  * @return Indicate if the update of the user parameters was successful.  * @retval SCI_SUCCESS This value is returned if the operation succeeded.  * @retval SCI_FAILURE_INVALID_STATE This value is returned if the attempt  *         to change the user parameter failed, because changing one of  *         the parameters is not currently allowed.  * @retval SCI_FAILURE_INVALID_PARAMETER_VALUE This value is returned if the  *         user supplied an unsupported value for one of the OEM parameters.  */
name|SCI_STATUS
name|scic_oem_parameters_set
parameter_list|(
name|SCI_CONTROLLER_HANDLE_T
name|controller
parameter_list|,
name|SCIC_OEM_PARAMETERS_T
modifier|*
name|oem_parameters
parameter_list|,
name|U8
name|oem_parameters_version
parameter_list|)
function_decl|;
comment|/**  * @brief This method allows the user to retreive the OEM  *        parameters utilized by the controller.  *  * @param[in]  controller This parameter specifies the controller on which  *             to set the user parameters.  * @param[out] oem_parameters This parameter specifies the OEM parameters  *             object in which to write the core's OEM parameters.  *  * @return none  */
name|void
name|scic_oem_parameters_get
parameter_list|(
name|SCI_CONTROLLER_HANDLE_T
name|controller
parameter_list|,
name|SCIC_OEM_PARAMETERS_T
modifier|*
name|oem_parameters
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
comment|// _SCIC_SDS_USER_PARAMETERS_H_
end_comment

end_unit

