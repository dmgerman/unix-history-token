begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI 2.2 Deferred Image Load Protocol definition.    This protocol returns information about images whose load was denied because of security    considerations. This information can be used by the Boot Manager or another agent to reevaluate the    images when the current security profile has been changed, such as when the current user profile    changes. There can be more than one instance of this protocol installed.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEFERRED_IMAGE_LOAD_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEFERRED_IMAGE_LOAD_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Deferred Image Load Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEFERRED_IMAGE_LOAD_PROTOCOL_GUID
define|\
value|{ \     0x15853d7c, 0x3ddf, 0x43e0, { 0xa1, 0xcb, 0xeb, 0xf8, 0x5b, 0x8f, 0x87, 0x2c } \   };
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DEFERRED_IMAGE_LOAD_PROTOCOL
name|EFI_DEFERRED_IMAGE_LOAD_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Returns information about a deferred image.    This function returns information about a single deferred image. The deferred images are numbered    consecutively, starting with 0.  If there is no image which corresponds to ImageIndex, then    EFI_NOT_FOUND is returned. All deferred images may be returned by iteratively calling this    function until EFI_NOT_FOUND is returned.   Image may be NULL and ImageSize set to 0 if the decision to defer execution was made because    of the location of the executable image rather than its actual contents.  record handle until   there are no more, at which point UserInfo will point to NULL.     @param[in]  This               Points to this instance of the EFI_DEFERRED_IMAGE_LOAD_PROTOCOL.   @param[in]  ImageIndex         Zero-based index of the deferred index.   @param[out] ImageDevicePath    On return, points to a pointer to the device path of the image.                                   The device path should not be freed by the caller.    @param[out] Image              On return, points to the first byte of the image or NULL if the                                    image is not available. The image should not be freed by the caller                                   unless LoadImage() has been called successfully.     @param[out] ImageSize          On return, the size of the image, or 0 if the image is not available.   @param[out] BootOption         On return, points to TRUE if the image was intended as a boot option                                   or FALSE if it was not intended as a boot option.      @retval EFI_SUCCESS            Image information returned successfully.   @retval EFI_NOT_FOUND          ImageIndex does not refer to a valid image.   @retval EFI_INVALID_PARAMETER  ImageDevicePath is NULL or Image is NULL or ImageSize is NULL or                                   BootOption is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEFERRED_IMAGE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_DEFERRED_IMAGE_LOAD_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ImageIndex
parameter_list|,
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|ImageDevicePath
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Image
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|ImageSize
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|BootOption
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol returns information about a deferred image.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DEFERRED_IMAGE_LOAD_PROTOCOL
block|{
name|EFI_DEFERRED_IMAGE_INFO
name|GetImageInfo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDeferredImageLoadProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

