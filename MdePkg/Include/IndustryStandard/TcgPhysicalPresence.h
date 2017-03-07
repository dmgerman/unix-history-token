begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TCG Physical Presence definition.  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials  are licensed and made available under the terms and conditions of the BSD License  which accompanies this distribution.  The full text of the license may be found at  http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCG_PHYSICAL_PRESENCE_H_
end_ifndef

begin_define
define|#
directive|define
name|_TCG_PHYSICAL_PRESENCE_H_
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition for physical presence ACPI function
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_GET_PHYSICAL_PRESENCE_INTERFACE_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_SUBMIT_REQUEST_TO_BIOS
value|2
end_define

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_GET_PENDING_REQUEST_BY_OS
value|3
end_define

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_GET_PLATFORM_ACTION_TO_TRANSITION_TO_BIOS
value|4
end_define

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_RETURN_REQUEST_RESPONSE_TO_OS
value|5
end_define

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_SUBMIT_PREFERRED_USER_LANGUAGE
value|6
end_define

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_SUBMIT_REQUEST_TO_BIOS_2
value|7
end_define

begin_define
define|#
directive|define
name|TCG_ACPI_FUNCTION_GET_USER_CONFIRMATION_STATUS_FOR_REQUEST
value|8
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition for TPM Operation Response to OS Environment
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG_PP_OPERATION_RESPONSE_SUCCESS
value|0x0
end_define

begin_define
define|#
directive|define
name|TCG_PP_OPERATION_RESPONSE_USER_ABORT
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|TCG_PP_OPERATION_RESPONSE_BIOS_FAILURE
value|0xFFFFFFF1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition of return code for Return TPM Operation Response to OS Environment
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG_PP_RETURN_TPM_OPERATION_RESPONSE_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|TCG_PP_RETURN_TPM_OPERATION_RESPONSE_FAILURE
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition of return code for Submit TPM Request to Pre-OS Environment
end_comment

begin_comment
comment|// and Submit TPM Request to Pre-OS Environment 2
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG_PP_SUBMIT_REQUEST_TO_PREOS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|TCG_PP_SUBMIT_REQUEST_TO_PREOS_NOT_IMPLEMENTED
value|1
end_define

begin_define
define|#
directive|define
name|TCG_PP_SUBMIT_REQUEST_TO_PREOS_GENERAL_FAILURE
value|2
end_define

begin_define
define|#
directive|define
name|TCG_PP_SUBMIT_REQUEST_TO_PREOS_BLOCKED_BY_BIOS_SETTINGS
value|3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition of return code for Get User Confirmation Status for Operation
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG_PP_GET_USER_CONFIRMATION_NOT_IMPLEMENTED
value|0
end_define

begin_define
define|#
directive|define
name|TCG_PP_GET_USER_CONFIRMATION_BIOS_ONLY
value|1
end_define

begin_define
define|#
directive|define
name|TCG_PP_GET_USER_CONFIRMATION_BLOCKED_BY_BIOS_CONFIGURATION
value|2
end_define

begin_define
define|#
directive|define
name|TCG_PP_GET_USER_CONFIRMATION_ALLOWED_AND_PPUSER_REQUIRED
value|3
end_define

begin_define
define|#
directive|define
name|TCG_PP_GET_USER_CONFIRMATION_ALLOWED_AND_PPUSER_NOT_REQUIRED
value|4
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition of physical presence operation actions for TPM12
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_NO_ACTION
value|0
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_DISABLE
value|2
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_ACTIVATE
value|3
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_DEACTIVATE
value|4
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_CLEAR
value|5
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_ENABLE_ACTIVATE
value|6
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_DEACTIVATE_DISABLE
value|7
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_OWNER_INSTALL_TRUE
value|8
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_OWNER_INSTALL_FALSE
value|9
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_ENABLE_ACTIVATE_OWNER_TRUE
value|10
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_DEACTIVATE_DISABLE_OWNER_FALSE
value|11
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_DEFERRED_PP_UNOWNERED_FIELD_UPGRADE
value|12
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_OPERATOR_AUTH
value|13
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_CLEAR_ENABLE_ACTIVATE
value|14
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_NO_PPI_PROVISION_FALSE
value|15
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_NO_PPI_PROVISION_TRUE
value|16
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_NO_PPI_CLEAR_FALSE
value|17
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_NO_PPI_CLEAR_TRUE
value|18
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_NO_PPI_MAINTENANCE_FALSE
value|19
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_SET_NO_PPI_MAINTENANCE_TRUE
value|20
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_ENABLE_ACTIVATE_CLEAR
value|21
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_ENABLE_ACTIVATE_CLEAR_ENABLE_ACTIVATE
value|22
end_define

begin_define
define|#
directive|define
name|TCG_PHYSICAL_PRESENCE_VENDOR_SPECIFIC_OPERATION
value|128
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition of physical presence operation actions for TPM2
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_NO_ACTION
value|0
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_DISABLE
value|2
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_CLEAR
value|5
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_ENABLE_CLEAR
value|14
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_CLEAR_TRUE
value|17
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_CLEAR_FALSE
value|18
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_ENABLE_CLEAR_2
value|21
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_ENABLE_CLEAR_3
value|22
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PCR_BANKS
value|23
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_CHANGE_EPS
value|24
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_CHANGE_PCRS_FALSE
value|25
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_CHANGE_PCRS_TRUE
value|26
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_TURN_ON_FALSE
value|27
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_TURN_ON_TRUE
value|28
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_TURN_OFF_FALSE
value|29
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_TURN_OFF_TRUE
value|30
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_CHANGE_EPS_FALSE
value|31
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_CHANGE_EPS_TRUE
value|32
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_LOG_ALL_DIGESTS
value|33
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_DISABLE_ENDORSEMENT_ENABLE_STORAGE_HIERARCHY
value|34
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_NO_ACTION_MAX
value|34
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PP definition of physical presence operation actions for storage management
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_STORAGE_MANAGEMENT_BEGIN
value|96
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_ENABLE_BLOCK_SID
value|96
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_DISABLE_BLOCK_SID
value|97
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_ENABLE_BLOCK_SID_FUNC_TRUE
value|98
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_ENABLE_BLOCK_SID_FUNC_FALSE
value|99
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_DISABLE_BLOCK_SID_FUNC_TRUE
value|100
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_SET_PP_REQUIRED_FOR_DISABLE_BLOCK_SID_FUNC_FALSE
value|101
end_define

begin_define
define|#
directive|define
name|TCG2_PHYSICAL_PRESENCE_VENDOR_SPECIFIC_OPERATION
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

