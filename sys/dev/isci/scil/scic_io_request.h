begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_IO_REQUEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_IO_REQUEST_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures and interface methods that  *        can be referenced and used by the SCI user for the SCI IO request  *        object.  *  * @todo Determine the failure situations and return values.  */
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
comment|/**  * @struct SCIC_IO_SSP_PARAMETERS  * @brief  This structure contains additional optional parameters for SSP  *         IO requests.  These parameters are utilized with the  *         scic_io_request_construct_advanced_ssp() method.  *  * @todo Add Block-guard/DIF, TLR  */
typedef|typedef
struct|struct
name|SCIC_IO_SSP_PARAMETERS
block|{
comment|/**     * Data Integrity Format (DIF) is also known as protection information     * or block-guard.  This sub-structure contains DIF specific feature     * information for SSP IO requests.     */
struct|struct
block|{
name|void
modifier|*
name|placeholder
decl_stmt|;
block|}
name|dif
struct|;
comment|/**     * Transport Layer Retries (TLR) is an SSP protocol specific feature.     * This sub-structure contains Transport Layer Retries (TLR) specific     * feature information for SSP IO requests.     */
struct|struct
block|{
name|void
modifier|*
name|placeholder
decl_stmt|;
block|}
name|tlr
struct|;
block|}
name|SCIC_IO_SSP_PARAMETERS_T
typedef|;
comment|/**  * @struct SCIC_IO_PARAMETERS  * @brief  This structure contains additional optional parameters for  *         STP/SATA IO requests.  These parameters are utilized with the  *         scic_io_request_construct_advanced_sata() method.  */
typedef|typedef
struct|struct
name|SCIC_IO_SATA_PARAMETERS
block|{
comment|/**     * This field indicates whether or not to construct the Scatter-Gather     * List elements for the SATA request.  This is used in scenarios     * where Scatter-gather-list processing/translation is done by the     * user.     */
name|BOOL
name|do_translate_sgl
decl_stmt|;
block|}
name|SCIC_IO_SATA_PARAMETERS_T
typedef|;
comment|/**  * @struct SCIC_PASSTHRU_REQUEST_CALLBACKS  * @brief  This structure contains the pointer to the callback functions  *         for constructing the passthrough request common to SSP, SMP and STP.  *         This structure must be set by the win sci layer before the passthrough  *         build is called  *  */
typedef|typedef
struct|struct
name|SCIC_PASSTHRU_REQUEST_CALLBACKS
block|{
comment|/**    * Function pointer to get the phy identifier for passthrough request.    */
name|U32
function_decl|(
modifier|*
name|scic_cb_passthru_get_phy_identifier
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|U8
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the port identifier for passthrough request.    */
name|U32
function_decl|(
modifier|*
name|scic_cb_passthru_get_port_identifier
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|U8
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the connection rate for passthrough request.    */
name|U32
function_decl|(
modifier|*
name|scic_cb_passthru_get_connection_rate
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the destination sas address for passthrough request.    */
name|void
function_decl|(
modifier|*
name|scic_cb_passthru_get_destination_sas_address
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|U8
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the transfer length for passthrough request.    */
name|U32
function_decl|(
modifier|*
name|scic_cb_passthru_get_transfer_length
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the data direction for passthrough request.    */
name|U32
function_decl|(
modifier|*
name|scic_cb_passthru_get_data_direction
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|SCIC_PASSTHRU_REQUEST_CALLBACKS_T
typedef|;
comment|/**  * @struct SCIC_SSP_PASSTHRU_REQUEST_CALLBACKS  * @brief  This structure contains the pointer to the callback functions  *         for constructing the passthrough request specific to SSP.  *         This structure must be set by the win sci layer before the passthrough  *         build is called  *  */
typedef|typedef
struct|struct
name|SCIC_SSP_PASSTHRU_REQUEST_CALLBACKS
block|{
comment|/**    * Common callbacks for all Passthru requests    */
name|SCIC_PASSTHRU_REQUEST_CALLBACKS_T
name|common_callbacks
decl_stmt|;
comment|/**    * Function pointer to get the lun for passthrough request.    */
name|void
function_decl|(
modifier|*
name|scic_cb_ssp_passthru_get_lun
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|U8
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the cdb    */
name|void
function_decl|(
modifier|*
name|scic_cb_ssp_passthru_get_cdb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|U32
modifier|*
parameter_list|,
name|U8
modifier|*
modifier|*
parameter_list|,
name|U32
modifier|*
parameter_list|,
name|U8
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the task attribute for passthrough request.    */
name|U32
function_decl|(
modifier|*
name|scic_cb_ssp_passthru_get_task_attribute
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|SCIC_SSP_PASSTHRU_REQUEST_CALLBACKS_T
typedef|;
comment|/**  * @struct SCIC_STP_PASSTHRU_REQUEST_CALLBACKS  * @brief  This structure contains the pointer to the callback functions  *         for constructing the passthrough request specific to STP.  *         This structure must be set by the win sci layer before the passthrough  *         build is called  *  */
typedef|typedef
struct|struct
name|SCIC_STP_PASSTHRU_REQUEST_CALLBACKS
block|{
comment|/**    * Common callbacks for all Passthru requests    */
name|SCIC_PASSTHRU_REQUEST_CALLBACKS_T
name|common_callbacks
decl_stmt|;
comment|/**    * Function pointer to get the protocol for passthrough request.    */
name|U8
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_protocol
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the resgister fis    */
name|void
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_register_fis
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|U8
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the MULTIPLE_COUNT (bits 5,6,7 in Byte 1 in the SAT-specific SCSI extenstion in ATA Pass-through (0x85))    */
name|U8
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_multiplecount
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the EXTEND (bit 0 in Byte 1 the SAT-specific SCSI extenstion in ATA Pass-through (0x85))    */
name|U8
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_extend
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the CK_COND (bit 5 in Byte 2 the SAT-specific SCSI extenstion in ATA Pass-through (0x85))    */
name|U8
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_ckcond
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the T_DIR (bit 3 in Byte 2 the SAT-specific SCSI extenstion in ATA Pass-through (0x85))    */
name|U8
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_tdir
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the BYTE_BLOCK (bit 2 in Byte 2 the SAT-specific SCSI extenstion in ATA Pass-through (0x85))    */
name|U8
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_byteblock
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the T_LENGTH (bits 0,1 in Byte 2 the SAT-specific SCSI extenstion in ATA Pass-through (0x85))    */
name|U8
function_decl|(
modifier|*
name|scic_cb_stp_passthru_get_tlength
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|SCIC_STP_PASSTHRU_REQUEST_CALLBACKS_T
typedef|;
comment|/**  * @struct SCIC_SMP_PASSTHRU_REQUEST_CALLBACKS  * @brief  This structure contains the pointer to the callback functions  *         for constructing the passthrough request specific to SMP.  *         This structure must be set by the win sci layer before the passthrough  *         build is called  *  */
typedef|typedef
struct|struct
name|SCIC_SMP_PASSTHRU_REQUEST_CALLBACKS
block|{
comment|/**    * Common callbacks for all Passthru requests    */
name|SCIC_PASSTHRU_REQUEST_CALLBACKS_T
name|common_callbacks
decl_stmt|;
comment|/**    * Function pointer to get the length of the smp request and its length    */
name|U32
function_decl|(
modifier|*
name|scic_cb_smp_passthru_get_request
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|U8
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the frame type of the smp request    */
name|U8
function_decl|(
modifier|*
name|scic_cb_smp_passthru_get_frame_type
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the function in the smp request    */
name|U8
function_decl|(
modifier|*
name|scic_cb_smp_passthru_get_function
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**    * Function pointer to get the "allocated response length" in the smp request    */
name|U8
function_decl|(
modifier|*
name|scic_cb_smp_passthru_get_allocated_response_length
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|SCIC_SMP_PASSTHRU_REQUEST_CALLBACKS_T
typedef|;
comment|/**  * @brief This enumeration specifies the transport protocol utilized  *        for the request.  */
typedef|typedef
enum|enum
block|{
comment|/**     * This enumeration constant indicates that no protocol has yet been     * set.     */
name|SCIC_NO_PROTOCOL
block|,
comment|/**     * This enumeration constant indicates that the protocol utilized     * is the Serial Management Protocol.     */
name|SCIC_SMP_PROTOCOL
block|,
comment|/**     * This enumeration constant indicates that the protocol utilized     * is the Serial SCSI Protocol.     */
name|SCIC_SSP_PROTOCOL
block|,
comment|/**     * This enumeration constant indicates that the protocol utilized     * is the Serial-ATA Tunneling Protocol.     */
name|SCIC_STP_PROTOCOL
block|}
name|SCIC_TRANSPORT_PROTOCOL
typedef|;
comment|/**  * @brief This method simply returns the size required to build an SCI  *        based IO request object.  *  * @return Return the size of the SCI IO request object.  */
name|U32
name|scic_io_request_get_object_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI user to construct all SCI Core  *        IO requests.  Memory initialization and functionality common to  *        all IO request types is performed in this method.  *  * @note  The SCI core implementation will create an association between  *        the user IO request object and the core IO request object.  *  * @param[in]  scic_controller the handle to the core controller object  *             for which to build an IO request.  * @param[in]  scic_remote_device the handle to the core remote device  *             object for which to build an IO request.  * @param[in]  io_tag This parameter specifies the IO tag to be associated  *             with this request.  If SCI_CONTROLLER_INVALID_IO_TAG is  *             passed, then a copy of the request is built internally.  The  *             request will be copied into the actual controller request  *             memory when the IO tag is allocated internally during the  *             scic_controller_start_io() method.  * @param[in]  user_io_request_object This parameter specifies the user  *             IO request to be utilized during IO construction.  This IO  *             pointer will become the associated object for the core  *             IO request object.  * @param[in]  scic_io_request_memory This parameter specifies the memory  *             location to be utilized when building the core request.  * @param[out] new_scic_io_request_handle This parameter specifies a  *             pointer to the handle the core will expect in further  *             interactions with the core IO request object.  *  * @return Indicate if the controller successfully built the IO request.  * @retval SCI_SUCCESS This value is returned if the IO request was  *         successfully built.  */
name|SCI_STATUS
name|scic_io_request_construct
parameter_list|(
name|SCI_CONTROLLER_HANDLE_T
name|scic_controller
parameter_list|,
name|SCI_REMOTE_DEVICE_HANDLE_T
name|scic_remote_device
parameter_list|,
name|U16
name|io_tag
parameter_list|,
name|void
modifier|*
name|user_io_request_object
parameter_list|,
name|void
modifier|*
name|scic_io_request_memory
parameter_list|,
name|SCI_IO_REQUEST_HANDLE_T
modifier|*
name|new_scic_io_request_handle
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI user to build an SSP  *        IO request.  *  * @pre  *        - The user must have previously called scic_io_request_construct()  *          on the supplied IO request.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @return Indicate if the controller successfully built the IO request.  * @retval SCI_SUCCESS This value is returned if the IO request was  *         successfully built.  * @retval SCI_FAILURE_UNSUPPORTED_PROTOCOL This value is returned if the  *         remote_device does not support the SSP protocol.  * @retval SCI_FAILURE_INVALID_ASSOCIATION This value is returned if the  *         user did not properly set the association between the SCIC IO  *         request and the user's IO request.  Please refer to the  *         sci_object_set_association() routine for more  *         information.  */
name|SCI_STATUS
name|scic_io_request_construct_basic_ssp
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI user to build an SSP  *        IO request with additional parameters that provide additional  *        flexibility from the standard scic_io_request_construct_basic_ssp()  *        method.  *  * @pre  *        - The user must have previously called scic_io_request_construct()  *          on the supplied IO request.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  * @param[in]  io_parameters the additional parameter information to  *             be added to the outgoing IO request.  *  * @return Indicate if the controller successfully built the IO request.  * @retval SCI_SUCCESS This value is returned if the IO request was  *         successfully built.  * @retval SCI_FAILURE_UNSUPPORTED_PROTOCOL This value is returned if the  *         remote_device does not support the SSP protocol.  * @retval SCI_FAILURE_INVALID_ASSOCIATION This value is returned if the  *         user did not properly set the association between the SCIC IO  *         request and the user's IO request.  Please refer to the  *         sci_object_set_association() routine for more  *         information.  *  * @todo Determine the failure situations and return values.  */
name|SCI_STATUS
name|scic_io_request_construct_advanced_ssp
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|,
name|SCIC_IO_SSP_PARAMETERS_T
modifier|*
name|io_parameters
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_PASS_THROUGH
argument_list|)
comment|/**  * @brief This method will build an IO request based on the user information  *        supplied in the pass-through IO request object.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @param[in]  ssp_passthru_cb This parameter specifies the pointer to  *             the structure containing the callback to the function  *             pointers to get the needed fields from the pass-through  *             reqiest instead of SRB  *  * @return Indicate if the controller successfully built the IO request.  * @retval SCI_SUCCESS This value is returned if the IO request was  *         successfully built.  * @retval SCI_FAILURE_INVALID_ASSOCIATION This value is returned if the  *         user did not properly set the association between the SCIC IO  *         request and the user's IO request.  Please refer to the  *         sci_object_set_association() routine for more  *         information.  */
name|SCI_STATUS
name|scic_io_request_construct_ssp_pass_through
parameter_list|(
name|void
modifier|*
name|scic_io_request_memory
parameter_list|,
name|SCIC_SSP_PASSTHRU_REQUEST_CALLBACKS_T
modifier|*
name|ssp_passthru_cb
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_PASS_THROUGH)
define|#
directive|define
name|scic_io_request_construct_ssp_pass_through
parameter_list|(
name|memory
parameter_list|,
name|cb
parameter_list|)
value|SCI_FAILURE
endif|#
directive|endif
comment|// !defined(DISABLE_PASS_THROUGH)
comment|/**  * @brief This method is called by the SCI Core user to build an STP  *        IO request.  *  * @pre  *        - The user must have previously called scic_io_request_construct()  *          on the supplied IO request.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @return Indicate if the controller successfully built the IO request.  * @retval SCI_SUCCESS This value is returned if the IO request was  *         successfully built.  * @retval SCI_FAILURE_UNSUPPORTED_PROTOCOL This value is returned if the  *         remote_device does not support the STP protocol.  * @retval SCI_FAILURE_INVALID_ASSOCIATION This value is returned if the  *         user did not properly set the association between the SCIC IO  *         request and the user's IO request.  Please refer to the  *         sci_object_set_association() routine for more  *         information.  */
name|SCI_STATUS
name|scic_io_request_construct_basic_sata
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI Core user to build an STP  *        IO request.  *  * @pre  *        - The user must have previously called scic_io_request_construct()  *          on the supplied IO request.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @return Indicate if the controller successfully built the IO request.  * @retval SCI_SUCCESS This value is returned if the IO request was  *         successfully built.  * @retval SCI_FAILURE_UNSUPPORTED_PROTOCOL This value is returned if the  *         remote_device does not support the STP protocol.  * @retval SCI_FAILURE_INVALID_ASSOCIATION This value is returned if the  *         user did not properly set the association between the SCIC IO  *         request and the user's IO request.  Please refer to the  *         sci_object_set_association() routine for more  *         information.  */
name|SCI_STATUS
name|scic_io_request_construct_advanced_sata
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|,
name|SCIC_IO_SATA_PARAMETERS_T
modifier|*
name|io_parameters
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_PASS_THROUGH
argument_list|)
comment|/**  * @brief This method is called by the SCI user to build an STP pass-through  *        IO request.  *  * @pre  *        - The user must have previously called scic_io_request_construct()  *          on the supplied IO request.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @param[in]  passthru_cb This parameter specifies the pointer to the callback  *             structure that contains the function pointers  *  * @return Indicate if the controller successfully built the IO request.  */
name|SCI_STATUS
name|scic_io_request_construct_sata_pass_through
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|,
name|SCIC_STP_PASSTHRU_REQUEST_CALLBACKS_T
modifier|*
name|passthru_cb
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_PASS_THROUGH)
define|#
directive|define
name|scic_io_request_construct_sata_pass_through
parameter_list|(
name|io
parameter_list|,
name|cb
parameter_list|)
value|SCI_FAILURE
endif|#
directive|endif
comment|// !defined(DISABLE_PASS_THROUGH)
comment|/**  * @brief This method is called by the SCI user to build an SMP  *        IO request.  *  * @pre  *        - The user must have previously called scic_io_request_construct()  *          on the supplied IO request.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @return Indicate if the controller successfully built the IO request.  * @retval SCI_SUCCESS This value is returned if the IO request was  *         successfully built.  * @retval SCI_FAILURE_UNSUPPORTED_PROTOCOL This value is returned if the  *         remote_device does not support the SMP protocol.  * @retval SCI_FAILURE_INVALID_ASSOCIATION This value is returned if the  *         user did not properly set the association between the SCIC IO  *         request and the user's IO request.  Please refer to the  *         sci_object_set_association() routine for more  *         information.  */
name|SCI_STATUS
name|scic_io_request_construct_smp
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI user to build an SMP pass-through  *        IO request.  *  * @pre  *        - The user must have previously called scic_io_request_construct()  *          on the supplied IO request.  *  * @param[in]  scic_smp_request This parameter specifies the handle to the  *             io request object to be built.  *  * @param[in]  passthru_cb This parameter specifies the pointer to the callback  *             structure that contains the function pointers  *  * @return Indicate if the controller successfully built the IO request.  */
name|SCI_STATUS
name|scic_io_request_construct_smp_pass_through
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_smp_request
parameter_list|,
name|SCIC_SMP_PASSTHRU_REQUEST_CALLBACKS_T
modifier|*
name|passthru_cb
parameter_list|)
function_decl|;
comment|/**  * @brief This method returns the controller specific IO/Task request status.  *        These status values are unique to the specific controller being  *        managed by the SCIC.  *  * @param[in]  io_request the handle to the IO or task management request  *             object for which to retrieve the status.  *  * @return This method returns a value indicating the controller specific  *         request status.  */
name|U32
name|scic_request_get_controller_status
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method returns the user specific IO/Task request status.  *  * @param[in]  io_request the handle to the IO or task management request  *             object for which to retrieve the status.  *  * @return This method returns a value indicating the user specific  *         request status.  */
name|U32
name|scic_request_get_sci_status
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method will return the address to the command information  *        unit.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @return The address of the SSP/SMP command information unit.  */
name|void
modifier|*
name|scic_io_request_get_command_iu_address
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method will return the address to the response information  *        unit.  For an SSP request this buffer is only valid if the IO  *        request is completed with the status SCI_FAILURE_IO_RESPONSE_VALID.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to be built.  *  * @return The address of the SSP/SMP response information unit.  */
name|void
modifier|*
name|scic_io_request_get_response_iu_address
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method will return the IO tag utilized by the IO request.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object for which to return the IO tag.  *  * @return An unsigned integer representing the IO tag being utilized.  * @retval SCI_CONTROLLER_INVALID_IO_TAG This value is returned if the IO  *         does not currently have an IO tag allocated to it.  * @retval All return other values indicate a legitimate tag.  */
name|U16
name|scic_io_request_get_io_tag
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method will inform the user of the protocol with which  *        the supplied IO request was created.  *  * @param[in]  scic_io_request This parameter specifies the IO request  *             for which to retrieve the protocol.  *  * @return This method returns the transport protocol utilized for the  *         the supplied request.  Please refer to SCIC_TRANSPORT_PROTOCOL  *         for more information.  */
name|SCIC_TRANSPORT_PROTOCOL
name|scic_io_request_get_protocol
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method will assign an NCQ tag to the io request object.  The  *        caller of this function must make sure that only valid NCQ tags are  *        assigned to the io request object.  *  * @param[in]  scic_io_request This parameter specifies the handle to the  *             io request object to which to assign the ncq tag.  * @param[in]  ncq_tag This parameter specifies the NCQ tag to be utilized  *             for the supplied core IO request.  It is up to the user to make  *             sure that this is a valid NCQ tag.  *  * @return none  *  * @note This function is only valid for SATA NCQ requests.  */
name|void
name|scic_stp_io_request_set_ncq_tag
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|,
name|U16
name|ncq_tag
parameter_list|)
function_decl|;
comment|/**  * @brief This method will return the address of the host to device register  *        fis region for the io request object.  *  * @param[in] scic_io_request This parameter specifies the handle to the io  *       request object from which to get the host to device register fis  *       buffer.  *  * @return The address of the host to device register fis buffer in the io  *         request object.  *  * @note This function is only valid for SATA requests.  */
name|void
modifier|*
name|scic_stp_io_request_get_h2d_reg_address
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method will return the address of the device to host register  *        fis region for the io request object.  *  * @param[in] scic_io_request This parameter specifies the handle to the io  *       request object from which to get the device to host register fis  *       buffer.  *  * @return The address fo the device to host register fis ending the io  *         request.  *  * @note This function is only valid for SATA requests.  */
name|void
modifier|*
name|scic_stp_io_request_get_d2h_reg_address
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method will return the rx frame for the io request object that  *        contains the given offset.  *  * @param[in] scic_io_request This parameter specifies the handle to the io  *       request object which has received the frame data.  * @param[in] offset This parameter specifies which frame is being requested.  *  * @return The return is a pointer to the frame buffer data.  *  * @note Frame buffers are only 1024 bytes in size.  Reading past the end of a  *       frame will have unexpected results.  */
name|void
modifier|*
name|scic_io_request_get_rx_frame
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
parameter_list|,
name|U32
name|offset
parameter_list|)
function_decl|;
comment|/**  * @brief This method will return the number of bytes transferred from the SCU  *  * @param[in] scic_io_request This parameter specifies the handle to the io request  *            whose data length was not eqaul to the data length specified in the request.  *            When the driver gets an early io completion status from the hardware,  *            this routine should be called to get the actual number of bytes transferred  *  * @return The return is the number of bytes transferred when the data legth is not equal to  *         the specified length in the io request  *  */
name|U32
name|scic_io_request_get_number_of_bytes_transferred
parameter_list|(
name|SCI_IO_REQUEST_HANDLE_T
name|scic_io_request
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
comment|// _SCIC_IO_REQUEST_H_
end_comment

end_unit

