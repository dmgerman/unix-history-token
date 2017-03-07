begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI 2.2 User Credential Protocol definition.It has been removed from UEFI 2.3.1 and replaced   by EFI_USER_CREDENTIAL2_PROTOCOL.    Attached to a device handle, this protocol identifies a single means of identifying the user.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USER_CREDENTIAL_H__
end_ifndef

begin_define
define|#
directive|define
name|__USER_CREDENTIAL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/UserManager.h>
end_include

begin_define
define|#
directive|define
name|EFI_USER_CREDENTIAL_PROTOCOL_GUID
define|\
value|{ \     0x71ee5e94, 0x65b9, 0x45d5, { 0x82, 0x1a, 0x3a, 0x4d, 0x86, 0xcf, 0xe6, 0xbe } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_USER_CREDENTIAL_PROTOCOL
name|EFI_USER_CREDENTIAL_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Enroll a user on a credential provider.    This function enrolls and deletes a user profile using this credential provider. If a user profile   is successfully enrolled, it calls the User Manager Protocol function Notify() to notify the user    manager driver that credential information has changed. If an enrolled user does exist, delete the    user on the credential provider.    @param[in] This                Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[in] User                The user profile to enroll.     @retval EFI_SUCCESS            User profile was successfully enrolled.   @retval EFI_ACCESS_DENIED      Current user profile does not permit enrollment on the user profile                                   handle. Either the user profile cannot enroll on any user profile or                                   cannot enroll on a user profile other than the current user profile.   @retval EFI_UNSUPPORTED        This credential provider does not support enrollment in the pre-OS.   @retval EFI_DEVICE_ERROR       The new credential could not be created because of a device error.   @retval EFI_INVALID_PARAMETER  User does not refer to a valid user profile handle. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_ENROLL
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
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
comment|/**   Returns the user interface information used during user identification.    This function returns information about the form used when interacting with the user during user    identification. The form is the first enabled form in the form-set class    EFI_HII_USER_CREDENTIAL_FORMSET_GUID installed on the HII handle HiiHandle. If    the user credential provider does not require a form to identify the user, then this function should    return EFI_NOT_FOUND.    @param[in]  This               Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[out] Hii                On return, holds the HII database handle.   @param[out] FormSetId          On return, holds the identifier of the form set which contains                                  the form used during user identification.   @param[out] FormId             On return, holds the identifier of the form used during user                                   identification.     @retval EFI_SUCCESS            Form returned successfully.   @retval EFI_NOT_FOUND          Form not returned.   @retval EFI_INVALID_PARAMETER  Hii is NULL or FormSetId is NULL or FormId is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_FORM
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_HII_HANDLE
modifier|*
name|Hii
parameter_list|,
name|OUT
name|EFI_GUID
modifier|*
name|FormSetId
parameter_list|,
name|OUT
name|EFI_FORM_ID
modifier|*
name|FormId
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns bitmap used to describe the credential provider type.    This optional function returns a bitmap which is less than or equal to the number of pixels specified    by Width and Height. If no such bitmap exists, then EFI_NOT_FOUND is returned.     @param[in]      This           Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[in, out] Width          On entry, points to the desired bitmap width. If NULL then no bitmap                                  information will be returned. On exit, points to the width of the                                    bitmap returned.   @param[in, out] Height         On entry, points to the desired bitmap height. If NULL then no bitmap                                   information will be returned. On exit, points to the height of the                                    bitmap returned   @param[out]     Hii            On return, holds the HII database handle.    @param[out]     Image          On return, holds the HII image identifier.      @retval EFI_SUCCESS            Image identifier returned successfully.   @retval EFI_NOT_FOUND          Image identifier not returned.   @retval EFI_INVALID_PARAMETER  Hii is NULL or Image is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_TILE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|Width
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|Height
parameter_list|,
name|OUT
name|EFI_HII_HANDLE
modifier|*
name|Hii
parameter_list|,
name|OUT
name|EFI_IMAGE_ID
modifier|*
name|Image
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns string used to describe the credential provider type.    This function returns a string which describes the credential provider. If no such string exists, then    EFI_NOT_FOUND is returned.     @param[in]  This               Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[out] Hii                On return, holds the HII database handle.   @param[out] String             On return, holds the HII string identifier.     @retval EFI_SUCCESS            String identifier returned successfully.   @retval EFI_NOT_FOUND          String identifier not returned.   @retval EFI_INVALID_PARAMETER  Hii is NULL or String is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_TITLE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_HII_HANDLE
modifier|*
name|Hii
parameter_list|,
name|OUT
name|EFI_STRING_ID
modifier|*
name|String
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return the user identifier associated with the currently authenticated user.    This function returns the user identifier of the user authenticated by this credential provider. This    function is called after the credential-related information has been submitted on a form OR after a    call to Default() has returned that this credential is ready to log on.    @param[in]  This               Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[in]  User               The user profile handle of the user profile currently being considered                                   by the user identity manager. If NULL, then no user profile is currently                                   under consideration.   @param[out] Identifier         On return, points to the user identifier.      @retval EFI_SUCCESS            User identifier returned successfully.   @retval EFI_NOT_READY          No user identifier can be returned.   @retval EFI_ACCESS_DENIED      The user has been locked out of this user credential.   @retval EFI_NOT_FOUND          User is not NULL, and the specified user handle can't be found in user                                   profile database    @retval EFI_INVALID_PARAMETER  Identifier is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_USER
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USER_PROFILE_HANDLE
name|User
parameter_list|,
name|OUT
name|EFI_USER_INFO_IDENTIFIER
modifier|*
name|Identifier
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Indicate that user interface interaction has begun for the specified credential.    This function is called when a credential provider is selected by the user. If AutoLogon returns    FALSE, then the user interface will be constructed by the User Identity Manager.     @param[in]  This               Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[out] AutoLogon          On return, points to the credential provider's capabilities after                                   the credential provider has been selected by the user.      @retval EFI_SUCCESS            Credential provider successfully selected.   @retval EFI_INVALID_PARAMETER  AutoLogon is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_SELECT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_CREDENTIAL_LOGON_FLAGS
modifier|*
name|AutoLogon
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Indicate that user interface interaction has ended for the specified credential.    This function is called when a credential provider is deselected by the user.    @param[in] This        Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.     @retval EFI_SUCCESS    Credential provider successfully deselected. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_DESELECT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return the default logon behavior for this user credential.    This function reports the default login behavior regarding this credential provider.      @param[in]  This               Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[out] AutoLogon          On return, holds whether the credential provider should be                                   used by default to automatically log on the user.       @retval EFI_SUCCESS            Default information successfully returned.   @retval EFI_INVALID_PARAMETER  AutoLogon is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_DEFAULT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_CREDENTIAL_LOGON_FLAGS
modifier|*
name|AutoLogon
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return information attached to the credential provider.    This function returns user information.     @param[in]     This           Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[in]     UserInfo       Handle of the user information data record.    @param[out]    Info           On entry, points to a buffer of at least *InfoSize bytes. On exit, holds the user                                  information. If the buffer is too small to hold the information, then                                  EFI_BUFFER_TOO_SMALL is returned and InfoSize is updated to contain the                                  number of bytes actually required.   @param[in,out] InfoSize       On entry, points to the size of Info. On return, points to the size of the user                                  information.      @retval EFI_SUCCESS           Information returned successfully.   @retval EFI_BUFFER_TOO_SMALL  The size specified by InfoSize is too small to hold all of the user                                  information. The size required is returned in *InfoSize.   @retval EFI_NOT_FOUND         The specified UserInfo does not refer to a valid user info handle.   @retval EFI_INVALID_PARAMETER Info is NULL or InfoSize is NULL.                                 **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
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
comment|/**   Enumerate all of the user information records on the credential provider.    This function returns the next user information record. To retrieve the first user information record    handle, point UserInfo at a NULL. Each subsequent call will retrieve another user information    record handle until there are no more, at which point UserInfo will point to NULL.     @param[in]     This            Points to this instance of the EFI_USER_CREDENTIAL_PROTOCOL.   @param[in,out] UserInfo        On entry, points to the previous user information handle or NULL to                                    start enumeration. On exit, points to the next user information handle                                   or NULL if there is no more user information.     @retval EFI_SUCCESS            User information returned.   @retval EFI_NOT_FOUND          No more user information found.   @retval EFI_INVALID_PARAMETER  UserInfo is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREDENTIAL_GET_NEXT_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_USER_CREDENTIAL_PROTOCOL
modifier|*
name|This
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
comment|/// This protocol provides support for a single class of credentials
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_USER_CREDENTIAL_PROTOCOL
block|{
name|EFI_GUID
name|Identifier
decl_stmt|;
comment|///< Uniquely identifies this credential provider.
name|EFI_GUID
name|Type
decl_stmt|;
comment|///< Identifies this class of User Credential Provider.
name|EFI_CREDENTIAL_ENROLL
name|Enroll
decl_stmt|;
name|EFI_CREDENTIAL_FORM
name|Form
decl_stmt|;
name|EFI_CREDENTIAL_TILE
name|Tile
decl_stmt|;
name|EFI_CREDENTIAL_TITLE
name|Title
decl_stmt|;
name|EFI_CREDENTIAL_USER
name|User
decl_stmt|;
name|EFI_CREDENTIAL_SELECT
name|Select
decl_stmt|;
name|EFI_CREDENTIAL_DESELECT
name|Deselect
decl_stmt|;
name|EFI_CREDENTIAL_DEFAULT
name|Default
decl_stmt|;
name|EFI_CREDENTIAL_GET_INFO
name|GetInfo
decl_stmt|;
name|EFI_CREDENTIAL_GET_NEXT_INFO
name|GetNextInfo
decl_stmt|;
name|EFI_CREDENTIAL_CAPABILITIES
name|Capabilities
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUserCredentialProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

