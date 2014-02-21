begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_STATUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_STATUS_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the return status codes utilized across  *        the various sub-components in SCI.  */
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
comment|/**  * @enum  _SCI_STATUS  * @brief This is the general return status enumeration for non-IO, non-task  *        management related SCI interface methods.  */
typedef|typedef
enum|enum
name|_SCI_STATUS
block|{
comment|/**     * This member indicates successful completion.     */
name|SCI_SUCCESS
init|=
literal|0
block|,
comment|/**     * This value indicates that the calling method completed successfully,     * but that the IO may have completed before having it's start method     * invoked.  This occurs during SAT translation for requests that do     * not require an IO to the target or for any other requests that may     * be completed without having to submit IO.     */
name|SCI_SUCCESS_IO_COMPLETE_BEFORE_START
block|,
comment|/**     *  This Value indicates that the SCU hardware returned an early response     *  because the io request specified more data than is returned by the     *  target device (mode pages, inquiry data, etc.). The completion routine     *  will handle this case to get the actual number of bytes transferred.     */
name|SCI_SUCCESS_IO_DONE_EARLY
block|,
comment|/**     * This member indicates that the object for which a state change is     * being requested is already in said state.     */
name|SCI_WARNING_ALREADY_IN_STATE
block|,
comment|/**     * This member indicates interrupt coalescence timer may cause SAS     * specification compliance issues (i.e. SMP target mode response     * frames must be returned within 1.9 milliseconds).     */
name|SCI_WARNING_TIMER_CONFLICT
block|,
comment|/**     * This field indicates a sequence of action is not completed yet. Mostly,     * this status is used when multiple ATA commands are needed in a SATI translation.     */
name|SCI_WARNING_SEQUENCE_INCOMPLETE
block|,
comment|/**     * This member indicates that there was a general failure.     */
name|SCI_FAILURE
block|,
comment|/**     * This member indicates that the SCI implementation is unable to complete     * an operation due to a critical flaw the prevents any further operation     * (i.e. an invalid pointer).     */
name|SCI_FATAL_ERROR
block|,
comment|/**     * This member indicates the calling function failed, because the state     * of the controller is in a state that prevents successful completion.     */
name|SCI_FAILURE_INVALID_STATE
block|,
comment|/**     * This member indicates the calling function failed, because there is     * insufficient resources/memory to complete the request.     */
name|SCI_FAILURE_INSUFFICIENT_RESOURCES
block|,
comment|/**     * This member indicates the calling function failed, because the     * controller object required for the operation can't be located.     */
name|SCI_FAILURE_CONTROLLER_NOT_FOUND
block|,
comment|/**     * This member indicates the calling function failed, because the     * discovered controller type is not supported by the library.     */
name|SCI_FAILURE_UNSUPPORTED_CONTROLLER_TYPE
block|,
comment|/**     * This member indicates the calling function failed, because the     * requested initialization data version isn't supported.     */
name|SCI_FAILURE_UNSUPPORTED_INIT_DATA_VERSION
block|,
comment|/**     * This member indicates the calling function failed, because the     * requested configuration of SAS Phys into SAS Ports is not supported.     */
name|SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION
block|,
comment|/**     * This member indicates the calling function failed, because the     * requested protocol is not supported by the remote device, port,     * or controller.     */
name|SCI_FAILURE_UNSUPPORTED_PROTOCOL
block|,
comment|/**     * This member indicates the calling function failed, because the     * requested information type is not supported by the SCI implementation.     */
name|SCI_FAILURE_UNSUPPORTED_INFORMATION_TYPE
block|,
comment|/**     * This member indicates the calling function failed, because the     * device already exists.     */
name|SCI_FAILURE_DEVICE_EXISTS
block|,
comment|/**     * This member indicates the calling function failed, because adding     * a phy to the object is not possible.     */
name|SCI_FAILURE_ADDING_PHY_UNSUPPORTED
block|,
comment|/**     * This member indicates the calling function failed, because the     * requested information type is not supported by the SCI implementation.     */
name|SCI_FAILURE_UNSUPPORTED_INFORMATION_FIELD
block|,
comment|/**     * This member indicates the calling function failed, because the SCI     * implementation does not support the supplied time limit.     */
name|SCI_FAILURE_UNSUPPORTED_TIME_LIMIT
block|,
comment|/**     * This member indicates the calling method failed, because the SCI     * implementation does not contain the specified Phy.     */
name|SCI_FAILURE_INVALID_PHY
block|,
comment|/**     * This member indicates the calling method failed, because the SCI     * implementation does not contain the specified Port.     */
name|SCI_FAILURE_INVALID_PORT
block|,
comment|/**      * This member indicates the calling method was partly successful      * The port was reset but not all phys in port are operational      */
name|SCI_FAILURE_RESET_PORT_PARTIAL_SUCCESS
block|,
comment|/**      * This member indicates that calling method failed      * The port reset did not complete because none of the phys are operational      */
name|SCI_FAILURE_RESET_PORT_FAILURE
block|,
comment|/**     * This member indicates the calling method failed, because the SCI     * implementation does not contain the specified remote device.     */
name|SCI_FAILURE_INVALID_REMOTE_DEVICE
block|,
comment|/**     * This member indicates the calling method failed, because the remote     * device is in a bad state and requires a reset.     */
name|SCI_FAILURE_REMOTE_DEVICE_RESET_REQUIRED
block|,
comment|/**     * This member indicates the calling method failed, because the SCI     * implementation does not contain or support the specified IO tag.     */
name|SCI_FAILURE_INVALID_IO_TAG
block|,
comment|/**     * This member indicates that the operation failed and the user should     * check the response data associated with the IO.     */
name|SCI_FAILURE_IO_RESPONSE_VALID
block|,
comment|/**     * This member indicates that the operation failed, the failure is     * controller implementation specific, and the response data associated     * with the request is not valid.  You can query for the controller     * specific error information via scic_request_get_controller_status()     */
name|SCI_FAILURE_CONTROLLER_SPECIFIC_IO_ERR
block|,
comment|/**     * This member indicated that the operation failed because the     * user requested this IO to be terminated.     */
name|SCI_FAILURE_IO_TERMINATED
block|,
comment|/**     * This member indicates that the operation failed and the associated     * request requires a SCSI abort task to be sent to the target.     */
name|SCI_FAILURE_IO_REQUIRES_SCSI_ABORT
block|,
comment|/**     * This member indicates that the operation failed because the supplied     * device could not be located.     */
name|SCI_FAILURE_DEVICE_NOT_FOUND
block|,
comment|/**     * This member indicates that the operation failed because the     * objects association is required and is not correctly set.     */
name|SCI_FAILURE_INVALID_ASSOCIATION
block|,
comment|/**     * This member indicates that the operation failed, because a timeout     * occurred.     */
name|SCI_FAILURE_TIMEOUT
block|,
comment|/**     * This member indicates that the operation failed, because the user     * specified a value that is either invalid or not supported.     */
name|SCI_FAILURE_INVALID_PARAMETER_VALUE
block|,
comment|/**     * This value indicates that the operation failed, because the number     * of messages (MSI-X) is not supported.     */
name|SCI_FAILURE_UNSUPPORTED_MESSAGE_COUNT
block|,
comment|/**     * This value indicates that the method failed due to a lack of     * available NCQ tags.     */
name|SCI_FAILURE_NO_NCQ_TAG_AVAILABLE
block|,
comment|/**     * This value indicates that a protocol violation has occurred on the     * link.     */
name|SCI_FAILURE_PROTOCOL_VIOLATION
block|,
comment|/**     * This value indicates a failure condition that retry may help to clear.     */
name|SCI_FAILURE_RETRY_REQUIRED
block|,
comment|/**     * This field indicates the retry limit was reached when a retry is attempted     */
name|SCI_FAILURE_RETRY_LIMIT_REACHED
block|,
comment|/**     * This member indicates the calling method was partly successful.     * Mostly, this status is used when a LUN_RESET issued to an expander attached     * STP device in READY NCQ substate needs to have RNC suspended/resumed     * before posting TC.     */
name|SCI_FAILURE_RESET_DEVICE_PARTIAL_SUCCESS
block|,
comment|/**     * This field indicates an illegal phy connection based on the routing attribute     * of both expander phy attached to each other.     */
name|SCI_FAILURE_ILLEGAL_ROUTING_ATTRIBUTE_CONFIGURATION
block|,
comment|/**     * This field indicates a CONFIG ROUTE INFO command has a response with function result     * INDEX DOES NOT EXIST, usually means exceeding max route index.     */
name|SCI_FAILURE_EXCEED_MAX_ROUTE_INDEX
block|,
comment|/**     * This value indicates that an unsupported PCI device ID has been     * specified.  This indicates that attempts to invoke     * scic_library_allocate_controller() will fail.     */
name|SCI_FAILURE_UNSUPPORTED_PCI_DEVICE_ID
block|}
name|SCI_STATUS
typedef|;
comment|/**  * @enum  _SCI_IO_STATUS  * @brief This enumeration depicts all of the possible IO completion  *        status values.  Each value in this enumeration maps directly to  *        a value in the SCI_STATUS enumeration.  Please refer to that  *        enumeration for detailed comments concerning what the status  *        represents.  * @todo Add the API to retrieve the SCU status from the core.  * @todo Check to see that the following status are properly handled:  *       - SCI_IO_FAILURE_UNSUPPORTED_PROTOCOL  *       - SCI_IO_FAILURE_INVALID_IO_TAG  */
typedef|typedef
enum|enum
name|_SCI_IO_STATUS
block|{
name|SCI_IO_SUCCESS
init|=
name|SCI_SUCCESS
block|,
name|SCI_IO_FAILURE
init|=
name|SCI_FAILURE
block|,
name|SCI_IO_SUCCESS_COMPLETE_BEFORE_START
init|=
name|SCI_SUCCESS_IO_COMPLETE_BEFORE_START
block|,
name|SCI_IO_SUCCESS_IO_DONE_EARLY
init|=
name|SCI_SUCCESS_IO_DONE_EARLY
block|,
name|SCI_IO_FAILURE_INVALID_STATE
init|=
name|SCI_FAILURE_INVALID_STATE
block|,
name|SCI_IO_FAILURE_INSUFFICIENT_RESOURCES
init|=
name|SCI_FAILURE_INSUFFICIENT_RESOURCES
block|,
name|SCI_IO_FAILURE_UNSUPPORTED_PROTOCOL
init|=
name|SCI_FAILURE_UNSUPPORTED_PROTOCOL
block|,
name|SCI_IO_FAILURE_RESPONSE_VALID
init|=
name|SCI_FAILURE_IO_RESPONSE_VALID
block|,
name|SCI_IO_FAILURE_CONTROLLER_SPECIFIC_ERR
init|=
name|SCI_FAILURE_CONTROLLER_SPECIFIC_IO_ERR
block|,
name|SCI_IO_FAILURE_TERMINATED
init|=
name|SCI_FAILURE_IO_TERMINATED
block|,
name|SCI_IO_FAILURE_REQUIRES_SCSI_ABORT
init|=
name|SCI_FAILURE_IO_REQUIRES_SCSI_ABORT
block|,
name|SCI_IO_FAILURE_INVALID_PARAMETER_VALUE
init|=
name|SCI_FAILURE_INVALID_PARAMETER_VALUE
block|,
name|SCI_IO_FAILURE_NO_NCQ_TAG_AVAILABLE
init|=
name|SCI_FAILURE_NO_NCQ_TAG_AVAILABLE
block|,
name|SCI_IO_FAILURE_PROTOCOL_VIOLATION
init|=
name|SCI_FAILURE_PROTOCOL_VIOLATION
block|,
name|SCI_IO_FAILURE_REMOTE_DEVICE_RESET_REQUIRED
init|=
name|SCI_FAILURE_REMOTE_DEVICE_RESET_REQUIRED
block|,
name|SCI_IO_FAILURE_RETRY_REQUIRED
init|=
name|SCI_FAILURE_RETRY_REQUIRED
block|,
name|SCI_IO_FAILURE_RETRY_LIMIT_REACHED
init|=
name|SCI_FAILURE_RETRY_LIMIT_REACHED
block|,
name|SCI_IO_FAILURE_INVALID_REMOTE_DEVICE
init|=
name|SCI_FAILURE_INVALID_REMOTE_DEVICE
block|}
name|SCI_IO_STATUS
typedef|;
comment|/**  * @enum  _SCI_TASK_STATUS  * @brief This enumeration depicts all of the possible task completion  *        status values.  Each value in this enumeration maps directly to  *        a value in the SCI_STATUS enumeration.  Please refer to that  *        enumeration for detailed comments concerning what the status  *        represents.  * @todo Check to see that the following status are properly handled:  */
typedef|typedef
enum|enum
name|_SCI_TASK_STATUS
block|{
name|SCI_TASK_SUCCESS
init|=
name|SCI_SUCCESS
block|,
name|SCI_TASK_FAILURE
init|=
name|SCI_FAILURE
block|,
name|SCI_TASK_FAILURE_INVALID_STATE
init|=
name|SCI_FAILURE_INVALID_STATE
block|,
name|SCI_TASK_FAILURE_INSUFFICIENT_RESOURCES
init|=
name|SCI_FAILURE_INSUFFICIENT_RESOURCES
block|,
name|SCI_TASK_FAILURE_UNSUPPORTED_PROTOCOL
init|=
name|SCI_FAILURE_UNSUPPORTED_PROTOCOL
block|,
name|SCI_TASK_FAILURE_INVALID_TAG
init|=
name|SCI_FAILURE_INVALID_IO_TAG
block|,
name|SCI_TASK_FAILURE_RESPONSE_VALID
init|=
name|SCI_FAILURE_IO_RESPONSE_VALID
block|,
name|SCI_TASK_FAILURE_CONTROLLER_SPECIFIC_ERR
init|=
name|SCI_FAILURE_CONTROLLER_SPECIFIC_IO_ERR
block|,
name|SCI_TASK_FAILURE_TERMINATED
init|=
name|SCI_FAILURE_IO_TERMINATED
block|,
name|SCI_TASK_FAILURE_INVALID_PARAMETER_VALUE
init|=
name|SCI_FAILURE_INVALID_PARAMETER_VALUE
block|,
name|SCI_TASK_FAILURE_REMOTE_DEVICE_RESET_REQUIRED
init|=
name|SCI_FAILURE_REMOTE_DEVICE_RESET_REQUIRED
block|,
name|SCI_TASK_FAILURE_RESET_DEVICE_PARTIAL_SUCCESS
init|=
name|SCI_FAILURE_RESET_DEVICE_PARTIAL_SUCCESS
block|}
name|SCI_TASK_STATUS
typedef|;
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
comment|// _SCI_STATUS_H_
end_comment

end_unit

