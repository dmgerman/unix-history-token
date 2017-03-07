begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI VLAN Config protocol is to provide manageability interface for VLAN configuration.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_VLANCONFIG_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_VLANCONFIG_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_VLAN_CONFIG_PROTOCOL_GUID
define|\
value|{ \     0x9e23d768, 0xd2f3, 0x4366, {0x9f, 0xc3, 0x3a, 0x7a, 0xba, 0x86, 0x43, 0x74 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_VLAN_CONFIG_PROTOCOL
name|EFI_VLAN_CONFIG_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_VLAN_FIND_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|VlanId
decl_stmt|;
comment|///< Vlan Identifier.
name|UINT8
name|Priority
decl_stmt|;
comment|///< Priority of this VLAN.
block|}
name|EFI_VLAN_FIND_DATA
typedef|;
end_typedef

begin_comment
comment|/**   Create a VLAN device or modify the configuration parameter of an    already-configured VLAN.    The Set() function is used to create a new VLAN device or change the VLAN   configuration parameters. If the VlanId hasn't been configured in the    physical Ethernet device, a new VLAN device will be created. If a VLAN with   this VlanId is already configured, then related configuration will be updated   as the input parameters.      If VlanId is zero, the VLAN device will send and receive untagged frames.   Otherwise, the VLAN device will send and receive VLAN-tagged frames containing the VlanId.   If VlanId is out of scope of (0-4094), EFI_INVALID_PARAMETER is returned.   If Priority is out of the scope of (0-7), then EFI_INVALID_PARAMETER is returned.    If there is not enough system memory to perform the registration, then    EFI_OUT_OF_RESOURCES is returned.    @param[in] This                Points to the EFI_VLAN_CONFIG_PROTOCOL.   @param[in] VlanId              A unique identifier (1-4094) of the VLAN which is being created                                   or modified, or zero (0).   @param[in] Priority            3 bit priority in VLAN header. Priority 0 is default value. If                                   VlanId is zero (0), Priority is ignored.                                     @retval EFI_SUCCESS            The VLAN is successfully configured.   @retval EFI_INVALID_PARAMETER  One or more of following conditions is TRUE:                                  - This is NULL.                                  - VlanId is an invalid VLAN Identifier.                                  - Priority is invalid.   @retval EFI_OUT_OF_RESOURCES   There is not enough system memory to perform the registration.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_VLAN_CONFIG_SET
function_decl|)
parameter_list|(
name|IN
name|EFI_VLAN_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|VlanId
parameter_list|,
name|IN
name|UINT8
name|Priority
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Find configuration information for specified VLAN or all configured VLANs.    The Find() function is used to find the configuration information for matching   VLAN and allocate a buffer into which those entries are copied.     @param[in]  This               Points to the EFI_VLAN_CONFIG_PROTOCOL.   @param[in]  VlanId             Pointer to VLAN identifier. Set to NULL to find all                                  configured VLANs.   @param[out] NumberOfVlan       The number of VLANs which is found by the specified criteria.   @param[out] Entries            The buffer which receive the VLAN configuration.                                     @retval EFI_SUCCESS            The VLAN is successfully found.   @retval EFI_INVALID_PARAMETER  One or more of following conditions is TRUE:                                  - This is NULL.                                  - Specified VlanId is invalid.   @retval EFI_NOT_FOUND          No matching VLAN is found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_VLAN_CONFIG_FIND
function_decl|)
parameter_list|(
name|IN
name|EFI_VLAN_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
modifier|*
name|VlanId
name|OPTIONAL
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|NumberOfVlan
parameter_list|,
name|OUT
name|EFI_VLAN_FIND_DATA
modifier|*
modifier|*
name|Entries
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Remove the configured VLAN device.    The Remove() function is used to remove the specified VLAN device.    If the VlanId is out of the scope of (0-4094), EFI_INVALID_PARAMETER is returned.   If specified VLAN hasn't been previously configured, EFI_NOT_FOUND is returned.       @param[in] This                Points to the EFI_VLAN_CONFIG_PROTOCOL.   @param[in] VlanId              Identifier (0-4094) of the VLAN to be removed.                                     @retval EFI_SUCCESS            The VLAN is successfully removed.   @retval EFI_INVALID_PARAMETER  One or more of following conditions is TRUE:                                  - This is NULL.                                  - VlanId  is an invalid parameter.   @retval EFI_NOT_FOUND          The to-be-removed VLAN does not exist.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_VLAN_CONFIG_REMOVE
function_decl|)
parameter_list|(
name|IN
name|EFI_VLAN_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|VlanId
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_VLAN_CONFIG_PROTOCOL
end_comment

begin_comment
comment|/// provide manageability interface for VLAN setting. The intended
end_comment

begin_comment
comment|/// VLAN tagging implementation is IEEE802.1Q.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_VLAN_CONFIG_PROTOCOL
block|{
name|EFI_VLAN_CONFIG_SET
name|Set
decl_stmt|;
name|EFI_VLAN_CONFIG_FIND
name|Find
decl_stmt|;
name|EFI_VLAN_CONFIG_REMOVE
name|Remove
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVlanConfigProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

