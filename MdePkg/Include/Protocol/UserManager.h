begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI User Manager Protocol definition.    This protocol manages user profiles.    Copyright (c) 2009 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USER_MANAGER_H__
end_ifndef

begin_define
define|#
directive|define
name|__USER_MANAGER_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the User Manager Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_MANAGER_PROTOCOL_GUID
define|\
value|{ \     0x6fd5b00c, 0xd426, 0x4283, { 0x98, 0x87, 0x6c, 0xf5, 0xcf, 0x1c, 0xb1, 0xfe } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_GROUP_USER_PROFILE_CHANGED
define|\
value|{ \     0xbaf1e6de, 0x209e, 0x4adb, { 0x8d, 0x96, 0xfd, 0x8b, 0x71, 0xf3, 0xf6, 0x83 } \   }
end_define

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_USER_PROFILE_HANDLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_USER_INFO_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attributes of the user profile information.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|EFI_USER_INFO_ATTRIBS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_USER_INFO_STORAGE
value|0x000F
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_STORAGE_VOLATILE
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_STORAGE_CREDENTIAL_NV
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_STORAGE_PLATFORM_NV
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS
value|0x0070
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_PUBLIC
value|0x0010
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_PRIVATE
value|0x0020
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_PROTECTED
value|0x0030
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_EXCLUSIVE
value|0x0080
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// User information structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The user credential identifier associated with this user information or else Nil if the
comment|/// information is not associated with any specific credential.
comment|///
name|EFI_GUID
name|Credential
decl_stmt|;
comment|///
comment|/// The type of user information.
comment|///
name|UINT8
name|InfoType
decl_stmt|;
comment|///
comment|/// Must be set to 0.
comment|///
name|UINT8
name|Reserved1
decl_stmt|;
comment|///
comment|/// The attributes of the user profile information.
comment|///
name|EFI_USER_INFO_ATTRIBS
name|InfoAttribs
decl_stmt|;
comment|///
comment|/// The size of the user information, in bytes, including this header.
comment|///
name|UINT32
name|InfoSize
decl_stmt|;
block|}
name|EFI_USER_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// User credential class GUIDs
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_CREDENTIAL_CLASS_UNKNOWN
define|\
value|{ 0x5cf32e68, 0x7660, 0x449b, { 0x80, 0xe6, 0x7e, 0xa3, 0x6e, 0x3, 0xf6, 0xa8 } }
end_define

begin_define
define|#
directive|define
name|EFI_USER_CREDENTIAL_CLASS_PASSWORD
define|\
value|{ 0xf8e5058c, 0xccb6, 0x4714, { 0xb2, 0x20, 0x3f, 0x7e, 0x3a, 0x64, 0xb, 0xd1 } }
end_define

begin_define
define|#
directive|define
name|EFI_USER_CREDENTIAL_CLASS_SMART_CARD
define|\
value|{ 0x5f03ba33, 0x8c6b, 0x4c24, { 0xaa, 0x2e, 0x14, 0xa2, 0x65, 0x7b, 0xd4, 0x54 } }
end_define

begin_define
define|#
directive|define
name|EFI_USER_CREDENTIAL_CLASS_FINGERPRINT
define|\
value|{ 0x32cba21f, 0xf308, 0x4cbc, { 0x9a, 0xb5, 0xf5, 0xa3, 0x69, 0x9f, 0x4, 0x4a } }
end_define

begin_define
define|#
directive|define
name|EFI_USER_CREDENTIAL_CLASS_HANDPRINT
define|\
value|{ 0x5917ef16, 0xf723, 0x4bb9, { 0xa6, 0x4b, 0xd8, 0xc5, 0x32, 0xf4, 0xd8, 0xb5 } }
end_define

begin_define
define|#
directive|define
name|EFI_USER_CREDENTIAL_CLASS_SECURE_CARD
define|\
value|{ 0x8a6b4a83, 0x42fe, 0x45d2, { 0xa2, 0xef, 0x46, 0xf0, 0x6c, 0x7d, 0x98, 0x52 } }
end_define

begin_typedef
typedef|typedef
name|UINT64
name|EFI_CREDENTIAL_CAPABILITIES
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_CREDENTIAL_CAPABILITIES_ENROLL
value|0x0000000000000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Credential logon flags
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_CREDENTIAL_LOGON_FLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_CREDENTIAL_LOGON_FLAG_AUTO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_CREDENTIAL_LOGON_FLAG_DEFAULT
value|0x00000002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// User information record types
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No information.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_EMPTY_RECORD
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provide the user's name for the enrolled user.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_NAME_RECORD
value|0x01
end_define

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
name|EFI_USER_INFO_NAME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the date and time when the user profile was created.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_CREATE_DATE_RECORD
value|0x02
end_define

begin_typedef
typedef|typedef
name|EFI_TIME
name|EFI_USER_INFO_CREATE_DATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the date and time when the user profile was selected.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_USAGE_DATE_RECORD
value|0x03
end_define

begin_typedef
typedef|typedef
name|EFI_TIME
name|EFI_USER_INFO_USAGE_DATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the number of times that the user profile has been selected.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_USAGE_COUNT_RECORD
value|0x04
end_define

begin_typedef
typedef|typedef
name|UINT64
name|EFI_USER_INFO_USAGE_COUNT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides a unique non-volatile user identifier for each enrolled user.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTIFIER_RECORD
value|0x05
end_define

begin_typedef
typedef|typedef
name|UINT8
name|EFI_USER_INFO_IDENTIFIER
index|[
literal|16
index|]
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specifies the type of a particular credential associated with the user profile.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_CREDENTIAL_TYPE_RECORD
value|0x06
end_define

begin_typedef
typedef|typedef
name|EFI_GUID
name|EFI_USER_INFO_CREDENTIAL_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specifies the user-readable name of a particular credential type.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_CREDENTIAL_TYPE_NAME_RECORD
value|0x07
end_define

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
name|EFI_USER_INFO_CREDENTIAL_TYPE_NAME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specifies the credential provider.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_CREDENTIAL_PROVIDER_RECORD
value|0x08
end_define

begin_typedef
typedef|typedef
name|EFI_GUID
name|EFI_USER_INFO_CREDENTIAL_PROVIDER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specifies the user-readable name of a particular credential's provider.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_CREDENTIAL_PROVIDER_NAME_RECORD
value|0x09
end_define

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
name|EFI_USER_INFO_CREDENTIAL_PROVIDER_NAME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides PKCS#11 credential information from a smart card.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_PKCS11_RECORD
value|0x0A
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides standard biometric information in the format specified by the ISO 19785 (Common
end_comment

begin_comment
comment|/// Biometric Exchange Formats Framework) specification.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_CBEFF_RECORD
value|0x0B
end_define

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_USER_INFO_CBEFF
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates how close of a match the fingerprint must be in order to be considered a match.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_FAR_RECORD
value|0x0C
end_define

begin_typedef
typedef|typedef
name|UINT8
name|EFI_USER_INFO_FAR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates how many attempts the user has to with a particular credential before the system prevents
end_comment

begin_comment
comment|/// further attempts.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_RETRY_RECORD
value|0x0D
end_define

begin_typedef
typedef|typedef
name|UINT8
name|EFI_USER_INFO_RETRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the user's pre-OS access rights.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_POLICY_RECORD
value|0x0E
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Type
decl_stmt|;
comment|///< Specifies the type of user access control.
name|UINT32
name|Size
decl_stmt|;
comment|///< Specifies the size of the user access control record, in bytes, including this header.
block|}
name|EFI_USER_INFO_ACCESS_CONTROL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_USER_INFO_ACCESS_CONTROL
name|EFI_USER_INFO_ACCESS_POLICY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// User Information access types
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forbids the user from booting or loading executables from the specified device path or any child
end_comment

begin_comment
comment|/// device paths.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_FORBID_LOAD
value|0x00000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Permits the user from booting or loading executables from the specified device path or any child
end_comment

begin_comment
comment|/// device paths.
end_comment

begin_comment
comment|/// Note: in-consistency between code and the UEFI 2.3 specification here.
end_comment

begin_comment
comment|/// The definition EFI_USER_INFO_ACCESS_PERMIT_BOOT in the specification should be typo and wait for
end_comment

begin_comment
comment|/// spec update.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_PERMIT_LOAD
value|0x00000002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Presence of this record indicates that a user can update enrollment information.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_ENROLL_SELF
value|0x00000003
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Presence of this record indicates that a user can enroll new users.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_ENROLL_OTHERS
value|0x00000004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Presence of this record indicates that a user can update the user information of any user.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_MANAGE
value|0x00000005
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes permissions usable when configuring the platform.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_SETUP
value|0x00000006
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard GUIDs for access to configure the platform.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_SETUP_ADMIN_GUID
define|\
value|{ 0x85b75607, 0xf7ce, 0x471e, { 0xb7, 0xe4, 0x2a, 0xea, 0x5f, 0x72, 0x32, 0xee } }
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_SETUP_NORMAL_GUID
define|\
value|{ 0x1db29ae0, 0x9dcb, 0x43bc, { 0x8d, 0x87, 0x5d, 0xa1, 0x49, 0x64, 0xdd, 0xe2 } }
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_SETUP_RESTRICTED_GUID
define|\
value|{ 0xbdb38125, 0x4d63, 0x49f4, { 0x82, 0x12, 0x61, 0xcf, 0x5a, 0x19, 0xa, 0xf8 } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forbids UEFI drivers from being started from the specified device path(s) or any child device paths.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_FORBID_CONNECT
value|0x00000007
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Permits UEFI drivers to be started on the specified device path(s) or any child device paths.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_PERMIT_CONNECT
value|0x00000008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Modifies the boot order.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_BOOT_ORDER
value|0x00000009
end_define

begin_typedef
typedef|typedef
name|UINT32
name|EFI_USER_INFO_ACCESS_BOOT_ORDER_HDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_BOOT_ORDER_MASK
value|0x0000000F
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Insert new boot options at the beginning of the boot order.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_BOOT_ORDER_INSERT
value|0x00000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Append new boot options to the end of the boot order.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_BOOT_ORDER_APPEND
value|0x00000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Replace the entire boot order.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_BOOT_ORDER_REPLACE
value|0x00000002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Boot Manager will not attempt find a default boot device
end_comment

begin_comment
comment|/// when the default boot order is does not lead to a bootable device.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_ACCESS_BOOT_ORDER_NODEFAULT
value|0x00000010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the expression which determines which credentials are required to assert user identity.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_POLICY_RECORD
value|0x0F
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Type
decl_stmt|;
comment|///< Specifies either an operator or a data item.
name|UINT32
name|Length
decl_stmt|;
comment|///< The length of this block, in bytes, including this header.
block|}
name|EFI_USER_INFO_IDENTITY_POLICY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// User identity policy expression operators.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_FALSE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_TRUE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_CREDENTIAL_TYPE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_CREDENTIAL_PROVIDER
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_NOT
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_AND
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_USER_INFO_IDENTITY_OR
value|0x12
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides placeholder for additional user profile information identified by a GUID.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_USER_INFO_GUID_RECORD
value|0xFF
end_define

begin_typedef
typedef|typedef
name|EFI_GUID
name|EFI_USER_INFO_GUID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// User information table
end_comment

begin_comment
comment|/// A collection of EFI_USER_INFO records, prefixed with this header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Size
decl_stmt|;
comment|///< Total size of the user information table, in bytes.
block|}
name|EFI_USER_INFO_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_USER_MANAGER_PROTOCOL
name|EFI_USER_MANAGER_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Create a new user profile.    This function creates a new user profile with only a new user identifier attached and returns its    handle. The user profile is non-volatile, but the handle User can change across reboots.    @param[in]  This               Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[out] User               On return, points to the new user profile handle.                                   The user profile handle is unique only during this boot.     @retval EFI_SUCCESS            User profile was successfully created.   @retval EFI_ACCESS_DENIED      Current user does not have sufficient permissions to create a user profile.   @retval EFI_UNSUPPORTED        Creation of new user profiles is not supported.   @retval EFI_INVALID_PARAMETER  The User parameter is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_CREATE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_USER_PROFILE_HANDLE
modifier|*
name|User
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Delete an existing user profile.    @param[in] This                Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in] User                User profile handle.     @retval EFI_SUCCESS            User profile was successfully deleted.   @retval EFI_ACCESS_DENIED      Current user does not have sufficient permissions to delete a user                                  profile or there is only one user profile.   @retval EFI_UNSUPPORTED        Deletion of new user profiles is not supported.   @retval EFI_INVALID_PARAMETER  User does not refer to a valid user profile. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_DELETE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USER_PROFILE_HANDLE
name|User
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Enumerate all of the enrolled users on the platform.    This function returns the next enrolled user profile. To retrieve the first user profile handle, point    User at a NULL. Each subsequent call will retrieve another user profile handle until there are no    more, at which point User will point to NULL.     @param[in]     This            Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in,out] User            On entry, points to the previous user profile handle or NULL to                                   start enumeration. On exit, points to the next user profile handle                                  or NULL if there are no more user profiles.    @retval EFI_SUCCESS            Next enrolled user profile successfully returned.    @retval EFI_ACCESS_DENIED      Next enrolled user profile was not successfully returned.   @retval EFI_INVALID_PARAMETER  The User parameter is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_GET_NEXT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_USER_PROFILE_HANDLE
modifier|*
name|User
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return the current user profile handle.    @param[in]  This               Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[out] CurrentUser        On return, points to the current user profile handle.    @retval EFI_SUCCESS            Current user profile handle returned successfully.    @retval EFI_INVALID_PARAMETER  The CurrentUser parameter is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_CURRENT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_USER_PROFILE_HANDLE
modifier|*
name|CurrentUser
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Identify a user.    Identify the user and, if authenticated, returns the user handle and changes the current user profile.   All user information marked as private in a previously selected profile is no longer available for    inspection.    Whenever the current user profile is changed then the an event with the GUID    EFI_EVENT_GROUP_USER_PROFILE_CHANGED is signaled.    @param[in]  This               Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[out] User               On return, points to the user profile handle for the current user profile.    @retval EFI_SUCCESS            User was successfully identified.   @retval EFI_ACCESS_DENIED      User was not successfully identified.   @retval EFI_INVALID_PARAMETER  The User parameter is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_IDENTIFY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_USER_PROFILE_HANDLE
modifier|*
name|User
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Find a user using a user information record.    This function searches all user profiles for the specified user information record. The search starts    with the user information record handle following UserInfo and continues until either the    information is found or there are no more user profiles.   A match occurs when the Info.InfoType field matches the user information record type and the    user information record data matches the portion of Info.    @param[in]     This      Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in,out] User      On entry, points to the previously returned user profile handle or NULL to start                             searching with the first user profile. On return, points to the user profile handle or                             NULL if not found.   @param[in,out] UserInfo  On entry, points to the previously returned user information handle or NULL to start                             searching with the first. On return, points to the user information handle of the user                             information record or NULL if not found. Can be NULL, in which case only one user                             information record per user can be returned.    @param[in]     Info      Points to the buffer containing the user information to be compared to the user                             information record. If the user information record data is empty, then only the user                             information record type is compared.                             If InfoSize is 0, then the user information record must be empty.    @param[in]     InfoSize  The size of Info, in bytes.     @retval EFI_SUCCESS           User information was found. User points to the user profile handle and UserInfo                                 points to the user information handle.   @retval EFI_NOT_FOUND         User information was not found. User points to NULL and UserInfo points to NULL.   @retval EFI_INVALID_PARAMETER User is NULL. Or Info is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_FIND
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_USER_PROFILE_HANDLE
modifier|*
name|User
parameter_list|,
name|IN
name|OUT
name|EFI_USER_INFO_HANDLE
modifier|*
name|UserInfo
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|EFI_USER_INFO
modifier|*
name|Info
parameter_list|,
name|IN
name|UINTN
name|InfoSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Called by credential provider to notify of information change.    This function allows the credential provider to notify the User Identity Manager when user status     has changed.   If the User Identity Manager doesn't support asynchronous changes in credentials, then this function    should return EFI_UNSUPPORTED.    If current user does not exist, and the credential provider can identify a user, then make the user    to be current user and signal the EFI_EVENT_GROUP_USER_PROFILE_CHANGED event.   If current user already exists, and the credential provider can identify another user, then switch    current user to the newly identified user, and signal the EFI_EVENT_GROUP_USER_PROFILE_CHANGED event.   If current user was identified by this credential provider and now the credential provider cannot identify    current user, then logout current user and signal the EFI_EVENT_GROUP_USER_PROFILE_CHANGED event.    @param[in] This          Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in] Changed       Handle on which is installed an instance of the                            EFI_USER_CREDENTIAL_PROTOCOL where the user has changed.    @retval EFI_SUCCESS      The User Identity Manager has handled the notification.   @retval EFI_NOT_READY    The function was called while the specified credential provider was not selected.   @retval EFI_UNSUPPORTED  The User Identity Manager doesn't support asynchronous notifications. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|Changed
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return information attached to the user.    This function returns user information. The format of the information is described in User    Information. The function may return EFI_ACCESS_DENIED if the information is marked private    and the handle specified by User is not the current user profile. The function may return    EFI_ACCESS_DENIED if the information is marked protected and the information is associated    with a credential provider for which the user has not been authenticated.    @param[in]     This           Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in]     User           Handle of the user whose profile will be retrieved.    @param[in]     UserInfo       Handle of the user information data record.      @param[out]    Info           On entry, points to a buffer of at least *InfoSize bytes. On exit, holds the user                                  information. If the buffer is too small to hold the information, then                                  EFI_BUFFER_TOO_SMALL is returned and InfoSize is updated to contain the                                  number of bytes actually required.    @param[in,out] InfoSize       On entry, points to the size of Info. On return, points to the size of the user                                  information.     @retval EFI_SUCCESS           Information returned successfully.   @retval EFI_ACCESS_DENIED     The information about the specified user cannot be accessed by the current user.   @retval EFI_BUFFER_TOO_SMALL  The number of bytes specified by *InfoSize is too small to hold                                  the returned data. The actual size required is returned in *InfoSize.   @retval EFI_NOT_FOUND         User does not refer to a valid user profile or UserInfo does not refer to a valid                                 user info handle.   @retval EFI_INVALID_PARAMETER Info is NULL or InfoSize is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USER_PROFILE_HANDLE
name|User
parameter_list|,
name|IN
name|EFI_USER_INFO_HANDLE
name|UserInfo
parameter_list|,
name|OUT
name|EFI_USER_INFO
modifier|*
name|Info
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|InfoSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Add or update user information.    This function changes user information.  If NULL is pointed to by UserInfo, then a new user    information record is created and its handle is returned in UserInfo. Otherwise, the existing one is    replaced.   If EFI_USER_INFO_IDENTITY_POLICY_RECORD is changed, it is the caller's responsibility to keep it to    be synced with the information on credential providers.   If EFI_USER_INFO_EXCLUSIVE is specified in Info and a user information record of the same    type already exists in the user profile, then EFI_ACCESS_DENIED will be returned and    UserInfo will point to the handle of the existing record.    @param[in]     This             Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in]     User             Handle of the user whose profile will be retrieved.    @param[in,out] UserInfo         Handle of the user information data record.      @param[in]     Info             On entry, points to a buffer of at least *InfoSize bytes. On exit, holds the user                                    information. If the buffer is too small to hold the information, then                                    EFI_BUFFER_TOO_SMALL is returned and InfoSize is updated to contain the                                    number of bytes actually required.    @param[in]     InfoSize         On entry, points to the size of Info. On return, points to the size of the user                                    information.     @retval EFI_SUCCESS             Information returned successfully.   @retval EFI_ACCESS_DENIED       The record is exclusive.   @retval EFI_SECURITY_VIOLATION  The current user does not have permission to change the specified                                    user profile or user information record.   @retval EFI_NOT_FOUND           User does not refer to a valid user profile or UserInfo does not refer to a valid                                   user info handle.   @retval EFI_INVALID_PARAMETER   UserInfo is NULL or Info is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_SET_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USER_PROFILE_HANDLE
name|User
parameter_list|,
name|IN
name|OUT
name|EFI_USER_INFO_HANDLE
modifier|*
name|UserInfo
parameter_list|,
name|IN
name|CONST
name|EFI_USER_INFO
modifier|*
name|Info
parameter_list|,
name|IN
name|UINTN
name|InfoSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Delete user information.    Delete the user information attached to the user profile specified by the UserInfo.    @param[in] This            Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in] User            Handle of the user whose information will be deleted.   @param[in] UserInfo        Handle of the user information to remove.    @retval EFI_SUCCESS        User information deleted successfully.   @retval EFI_NOT_FOUND      User information record UserInfo does not exist in the user profile.   @retval EFI_ACCESS_DENIED  The current user does not have permission to delete this user information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_DELETE_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USER_PROFILE_HANDLE
name|User
parameter_list|,
name|IN
name|EFI_USER_INFO_HANDLE
name|UserInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Enumerate user information of all the enrolled users on the platform.    This function returns the next user information record. To retrieve the first user information record    handle, point UserInfo at a NULL. Each subsequent call will retrieve another user information    record handle until there are no more, at which point UserInfo will point to NULL.     @param[in]     This           Points to this instance of the EFI_USER_MANAGER_PROTOCOL.   @param[in]     User           Handle of the user whose information will be deleted.   @param[in,out] UserInfo       Handle of the user information to remove.    @retval EFI_SUCCESS           User information returned.   @retval EFI_NOT_FOUND         No more user information found.   @retval EFI_INVALID_PARAMETER UserInfo is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USER_PROFILE_GET_NEXT_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_MANAGER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USER_PROFILE_HANDLE
name|User
parameter_list|,
name|IN
name|OUT
name|EFI_USER_INFO_HANDLE
modifier|*
name|UserInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the services used to manage user profiles.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_USER_MANAGER_PROTOCOL
block|{
name|EFI_USER_PROFILE_CREATE
name|Create
decl_stmt|;
name|EFI_USER_PROFILE_DELETE
name|Delete
decl_stmt|;
name|EFI_USER_PROFILE_GET_NEXT
name|GetNext
decl_stmt|;
name|EFI_USER_PROFILE_CURRENT
name|Current
decl_stmt|;
name|EFI_USER_PROFILE_IDENTIFY
name|Identify
decl_stmt|;
name|EFI_USER_PROFILE_FIND
name|Find
decl_stmt|;
name|EFI_USER_PROFILE_NOTIFY
name|Notify
decl_stmt|;
name|EFI_USER_PROFILE_GET_INFO
name|GetInfo
decl_stmt|;
name|EFI_USER_PROFILE_SET_INFO
name|SetInfo
decl_stmt|;
name|EFI_USER_PROFILE_DELETE_INFO
name|DeleteInfo
decl_stmt|;
name|EFI_USER_PROFILE_GET_NEXT_INFO
name|GetNextInfo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserManagerProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventUserProfileChangedGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserCredentialClassUnknownGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserCredentialClassPasswordGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserCredentialClassSmartCardGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserCredentialClassFingerprintGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserCredentialClassHandprintGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserCredentialClassSecureCardGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserInfoAccessSetupAdminGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserInfoAccessSetupNormalGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserInfoAccessSetupRestrictedGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

