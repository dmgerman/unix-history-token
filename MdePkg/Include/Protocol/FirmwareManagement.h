begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Firmware Management Protocol definition   Firmware Management Protocol provides an abstraction for device to provide firmware   management support. The base requirements for managing device firmware images include   identifying firmware image revision level and programming the image into the device.    GetImageInfo() is the only required function. GetImage(), SetImage(),   CheckImage(), GetPackageInfo(), and SetPackageInfo() shall return   EFI_UNSUPPORTED if not supported by the driver.    Copyright (c) 2009 - 2015, Intel Corporation. All rights reserved.<BR>   Copyright (c) 2013 - 2014, Hewlett-Packard Development Company, L.P.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.3  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_FIRMWARE_MANAGEMENT_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_FIRMWARE_MANAGEMENT_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GUID
define|\
value|{ \     0x86c77a67, 0xb97, 0x4633, {0xa1, 0x87, 0x49, 0x10, 0x4d, 0x6, 0x85, 0xc7 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_FIRMWARE_MANAGEMENT_PROTOCOL
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_FIRMWARE_IMAGE_DESCRIPTOR
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A unique number identifying the firmware image within the device. The number is
comment|/// between 1 and DescriptorCount.
comment|///
name|UINT8
name|ImageIndex
decl_stmt|;
comment|///
comment|/// A unique GUID identifying the firmware image type.
comment|///
name|EFI_GUID
name|ImageTypeId
decl_stmt|;
comment|///
comment|/// A unique number identifying the firmware image.
comment|///
name|UINT64
name|ImageId
decl_stmt|;
comment|///
comment|/// A pointer to a null-terminated string representing the firmware image name.
comment|///
name|CHAR16
modifier|*
name|ImageIdName
decl_stmt|;
comment|///
comment|/// Identifies the version of the device firmware. The format is vendor specific and new
comment|/// version must have a greater value than an old version.
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// A pointer to a null-terminated string representing the firmware image version name.
comment|///
name|CHAR16
modifier|*
name|VersionName
decl_stmt|;
comment|///
comment|/// Size of the image in bytes. If size=0, then only ImageIndex and ImageTypeId are valid.
comment|///
name|UINTN
name|Size
decl_stmt|;
comment|///
comment|/// Image attributes that are supported by this device. See 'Image Attribute Definitions'
comment|/// for possible returned values of this parameter. A value of 1 indicates the attribute is
comment|/// supported and the current setting value is indicated in AttributesSetting. A
comment|/// value of 0 indicates the attribute is not supported and the current setting value in
comment|/// AttributesSetting is meaningless.
comment|///
name|UINT64
name|AttributesSupported
decl_stmt|;
comment|///
comment|/// Image attributes. See 'Image Attribute Definitions' for possible returned values of
comment|/// this parameter.
comment|///
name|UINT64
name|AttributesSetting
decl_stmt|;
comment|///
comment|/// Image compatibilities. See 'Image Compatibility Definitions' for possible returned
comment|/// values of this parameter.
comment|///
name|UINT64
name|Compatibilities
decl_stmt|;
comment|///
comment|/// Describes the lowest ImageDescriptor version that the device will accept. Only
comment|/// present in version 2 or higher.
comment|///
name|UINT32
name|LowestSupportedImageVersion
decl_stmt|;
comment|///
comment|/// Describes the version that was last attempted to update. If no update attempted the
comment|/// value will be 0. If the update attempted was improperly formatted and no version
comment|/// number was available then the value will be zero. Only present in version 3 or higher.
name|UINT32
name|LastAttemptVersion
decl_stmt|;
comment|///
comment|/// Describes the status that was last attempted to update. If no update has been attempted
comment|/// the value will be LAST_ATTEMPT_STATUS_SUCCESS. Only present in version 3 or higher.
comment|///
name|UINT32
name|LastAttemptStatus
decl_stmt|;
comment|///
comment|/// An optional number to identify the unique hardware instance within the system for
comment|/// devices that may have multiple instances (Example: a plug in pci network card). This
comment|/// number must be unique within the namespace of the ImageTypeId GUID and
comment|/// ImageIndex. For FMP instances that have multiple descriptors for a single
comment|/// hardware instance, all descriptors must have the same HardwareInstance value.
comment|/// This number must be consistent between boots and should be based on some sort of
comment|/// hardware identified unique id (serial number, etc) whenever possible. If a hardware
comment|/// based number is not available the FMP provider may use some other characteristic
comment|/// such as device path, bus/dev/function, slot num, etc for generating the
comment|/// HardwareInstance. For implementations that will never have more than one
comment|/// instance a zero can be used. A zero means the FMP provider is not able to determine a
comment|/// unique hardware instance number or a hardware instance number is not needed. Only
comment|/// present in version 3 or higher.
comment|///
name|UINT64
name|HardwareInstance
decl_stmt|;
block|}
name|EFI_FIRMWARE_IMAGE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Image Attribute Definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute IMAGE_ATTRIBUTE_IMAGE_UPDATABLE indicates this device supports firmware
end_comment

begin_comment
comment|/// image update.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_ATTRIBUTE_IMAGE_UPDATABLE
value|0x0000000000000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute IMAGE_ATTRIBUTE_RESET_REQUIRED indicates a reset of the device is required
end_comment

begin_comment
comment|/// for the new firmware image to take effect after a firmware update. The device is the device hosting
end_comment

begin_comment
comment|/// the firmware image.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_ATTRIBUTE_RESET_REQUIRED
value|0x0000000000000002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED indicates authentication is
end_comment

begin_comment
comment|/// required to perform the following image operations: GetImage(), SetImage(), and
end_comment

begin_comment
comment|/// CheckImage(). See 'Image Attribute - Authentication'.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED
value|0x0000000000000004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute IMAGE_ATTRIBUTE_IN_USE indicates the current state of the firmware image.
end_comment

begin_comment
comment|/// This distinguishes firmware images in a device that supports redundant images.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_ATTRIBUTE_IN_USE
value|0x0000000000000008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute IMAGE_ATTRIBUTE_UEFI_IMAGE indicates that this image is an EFI compatible image.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_ATTRIBUTE_UEFI_IMAGE
value|0x0000000000000010
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Image Compatibility Definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// Values from 0x0000000000000002 thru 0x000000000000FFFF are reserved for future assignments.
end_comment

begin_comment
comment|/// Values from 0x0000000000010000 thru 0xFFFFFFFFFFFFFFFF are used by firmware vendor for
end_comment

begin_comment
comment|/// compatibility check.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_COMPATIBILITY_CHECK_SUPPORTED
value|0x0000000000000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Descriptor Version exposed by GetImageInfo() function
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FIRMWARE_IMAGE_DESCRIPTOR_VERSION
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Image Attribute -Authentication Required
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// It is included in the signature of AuthInfo. It is used to ensure freshness/no replay.
comment|/// It is incremented during each firmware image operation.
comment|///
name|UINT64
name|MonotonicCount
decl_stmt|;
comment|///
comment|/// Provides the authorization for the firmware image operations. It is a signature across
comment|/// the image data and the Monotonic Count value. Caller uses the private key that is
comment|/// associated with a public key that has been provisioned via the key exchange.
comment|/// Because this is defined as a signature, WIN_CERTIFICATE_UEFI_GUID.CertType must
comment|/// be EFI_CERT_TYPE_PKCS7_GUID.
comment|///
name|WIN_CERTIFICATE_UEFI_GUID
name|AuthInfo
decl_stmt|;
block|}
name|EFI_FIRMWARE_IMAGE_AUTHENTICATION
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// ImageUpdatable Definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMAGE_UPDATABLE_VALID indicates SetImage() will accept the new image and update the
end_comment

begin_comment
comment|/// device with the new image. The version of the new image could be higher or lower than
end_comment

begin_comment
comment|/// the current image. SetImage VendorCode is optional but can be used for vendor
end_comment

begin_comment
comment|/// specific action.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_UPDATABLE_VALID
value|0x0000000000000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMAGE_UPDATABLE_INVALID indicates SetImage() will reject the new image. No additional
end_comment

begin_comment
comment|/// information is provided for the rejection.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_UPDATABLE_INVALID
value|0x0000000000000002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMAGE_UPDATABLE_INVALID_TYPE indicates SetImage() will reject the new image. The
end_comment

begin_comment
comment|/// rejection is due to the new image is not a firmware image recognized for this device.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_UPDATABLE_INVALID_TYPE
value|0x0000000000000004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMAGE_UPDATABLE_INVALID_OLD indicates SetImage() will reject the new image. The
end_comment

begin_comment
comment|/// rejection is due to the new image version is older than the current firmware image
end_comment

begin_comment
comment|/// version in the device. The device firmware update policy does not support firmware
end_comment

begin_comment
comment|/// version downgrade.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_UPDATABLE_INVALID_OLD
value|0x0000000000000008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMAGE_UPDATABLE_VALID_WITH_VENDOR_CODE indicates SetImage() will accept and update
end_comment

begin_comment
comment|/// the new image only if a correct VendorCode is provided or else image would be
end_comment

begin_comment
comment|/// rejected and SetImage will return appropriate error.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_UPDATABLE_VALID_WITH_VENDOR_CODE
value|0x0000000000000010
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Package Attribute Definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute PACKAGE_ATTRIBUTE_VERSION_UPDATABLE indicates this device supports the
end_comment

begin_comment
comment|/// update of the firmware package version.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PACKAGE_ATTRIBUTE_VERSION_UPDATABLE
value|0x0000000000000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute PACKAGE_ATTRIBUTE_RESET_REQUIRED indicates a reset of the device is
end_comment

begin_comment
comment|/// required for the new package info to take effect after an update.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PACKAGE_ATTRIBUTE_RESET_REQUIRED
value|0x0000000000000002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The attribute PACKAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED indicates authentication
end_comment

begin_comment
comment|/// is required to update the package info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PACKAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED
value|0x0000000000000004
end_define

begin_comment
comment|/**   Callback function to report the process of the firmware updating.    @param[in]  Completion    A value between 1 and 100 indicating the current completion                             progress of the firmware update. Completion progress is                             reported as from 1 to 100 percent. A value of 0 is used by                             the driver to indicate that progress reporting is not supported.    @retval EFI_SUCCESS       SetImage() continues to do the callback if supported.   @retval other             SetImage() discontinues the callback and completes                             the update and returns.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|Completion
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns information about the current firmware image(s) of the device.    This function allows a copy of the current firmware image to be created and saved.   The saved copy could later been used, for example, in firmware image recovery or rollback.    @param[in]      This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.   @param[in, out] ImageInfoSize      A pointer to the size, in bytes, of the ImageInfo buffer.                                      On input, this is the size of the buffer allocated by the caller.                                      On output, it is the size of the buffer returned by the firmware                                      if the buffer was large enough, or the size of the buffer needed                                      to contain the image(s) information if the buffer was too small.   @param[in, out] ImageInfo          A pointer to the buffer in which firmware places the current image(s)                                      information. The information is an array of EFI_FIRMWARE_IMAGE_DESCRIPTORs.   @param[out]     DescriptorVersion  A pointer to the location in which firmware returns the version number                                      associated with the EFI_FIRMWARE_IMAGE_DESCRIPTOR.   @param[out]     DescriptorCount    A pointer to the location in which firmware returns the number of                                      descriptors or firmware images within this device.   @param[out]     DescriptorSize     A pointer to the location in which firmware returns the size, in bytes,                                      of an individual EFI_FIRMWARE_IMAGE_DESCRIPTOR.   @param[out]     PackageVersion     A version number that represents all the firmware images in the device.                                      The format is vendor specific and new version must have a greater value                                      than the old version. If PackageVersion is not supported, the value is                                      0xFFFFFFFF. A value of 0xFFFFFFFE indicates that package version comparison                                      is to be performed using PackageVersionName. A value of 0xFFFFFFFD indicates                                      that package version update is in progress.   @param[out]     PackageVersionName A pointer to a pointer to a null-terminated string representing the                                      package version name. The buffer is allocated by this function with                                      AllocatePool(), and it is the caller's responsibility to free it with a call                                      to FreePool().    @retval EFI_SUCCESS                The device was successfully updated with the new image.   @retval EFI_BUFFER_TOO_SMALL       The ImageInfo buffer was too small. The current buffer size                                      needed to hold the image(s) information is returned in ImageInfoSize.   @retval EFI_INVALID_PARAMETER      ImageInfoSize is NULL.   @retval EFI_DEVICE_ERROR           Valid information could not be returned. Possible corrupted image.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ImageInfoSize
parameter_list|,
name|IN
name|OUT
name|EFI_FIRMWARE_IMAGE_DESCRIPTOR
modifier|*
name|ImageInfo
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|DescriptorVersion
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|DescriptorCount
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DescriptorSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|PackageVersion
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|PackageVersionName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a copy of the current firmware image of the device.    This function allows a copy of the current firmware image to be created and saved.   The saved copy could later been used, for example, in firmware image recovery or rollback.    @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.   @param[in]  ImageIndex         A unique number identifying the firmware image(s) within the device.                                  The number is between 1 and DescriptorCount.   @param[out] Image              Points to the buffer where the current image is copied to.   @param[out] ImageSize          On entry, points to the size of the buffer pointed to by Image, in bytes.                                  On return, points to the length of the image, in bytes.    @retval EFI_SUCCESS            The device was successfully updated with the new image.   @retval EFI_BUFFER_TOO_SMALL   The buffer specified by ImageSize is too small to hold the                                  image. The current buffer size needed to hold the image is returned                                  in ImageSize.   @retval EFI_INVALID_PARAMETER  The Image was NULL.   @retval EFI_NOT_FOUND          The current image is not copied to the buffer.   @retval EFI_UNSUPPORTED        The operation is not supported.   @retval EFI_SECURITY_VIOLATIO  The operation could not be performed due to an authentication failure.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE
function_decl|)
parameter_list|(
name|IN
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|ImageIndex
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Image
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ImageSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Updates the firmware image of the device.    This function updates the hardware with the new firmware image.   This function returns EFI_UNSUPPORTED if the firmware image is not updatable.   If the firmware image is updatable, the function should perform the following minimal validations   before proceeding to do the firmware image update.   - Validate the image authentication if image has attribute     IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED. The function returns     EFI_SECURITY_VIOLATION if the validation fails.   - Validate the image is a supported image for this device. The function returns EFI_ABORTED if     the image is unsupported. The function can optionally provide more detailed information on     why the image is not a supported image.   - Validate the data from VendorCode if not null. Image validation must be performed before     VendorCode data validation. VendorCode data is ignored or considered invalid if image     validation failed. The function returns EFI_ABORTED if the data is invalid.    VendorCode enables vendor to implement vendor-specific firmware image update policy. Null if   the caller did not specify the policy or use the default policy. As an example, vendor can implement   a policy to allow an option to force a firmware image update when the abort reason is due to the new   firmware image version is older than the current firmware image version or bad image checksum.   Sensitive operations such as those wiping the entire firmware image and render the device to be   non-functional should be encoded in the image itself rather than passed with the VendorCode.   AbortReason enables vendor to have the option to provide a more detailed description of the abort   reason to the caller.    @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.   @param[in]  ImageIndex         A unique number identifying the firmware image(s) within the device.                                  The number is between 1 and DescriptorCount.   @param[in]  Image              Points to the new image.   @param[in]  ImageSize          Size of the new image in bytes.   @param[in]  VendorCode         This enables vendor to implement vendor-specific firmware image update policy.                                  Null indicates the caller did not specify the policy or use the default policy.   @param[in]  Progress           A function used by the driver to report the progress of the firmware update.   @param[out] AbortReason        A pointer to a pointer to a null-terminated string providing more                                  details for the aborted operation. The buffer is allocated by this function                                  with AllocatePool(), and it is the caller's responsibility to free it with a                                  call to FreePool().    @retval EFI_SUCCESS            The device was successfully updated with the new image.   @retval EFI_ABORTED            The operation is aborted.   @retval EFI_INVALID_PARAMETER  The Image was NULL.   @retval EFI_UNSUPPORTED        The operation is not supported.   @retval EFI_SECURITY_VIOLATIO  The operation could not be performed due to an authentication failure.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_IMAGE
function_decl|)
parameter_list|(
name|IN
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|ImageIndex
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Image
parameter_list|,
name|IN
name|UINTN
name|ImageSize
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|VendorCode
parameter_list|,
name|IN
name|EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS
name|Progress
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|AbortReason
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Checks if the firmware image is valid for the device.    This function allows firmware update application to validate the firmware image without   invoking the SetImage() first.    @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.   @param[in]  ImageIndex         A unique number identifying the firmware image(s) within the device.                                  The number is between 1 and DescriptorCount.   @param[in]  Image              Points to the new image.   @param[in]  ImageSize          Size of the new image in bytes.   @param[out] ImageUpdatable     Indicates if the new image is valid for update. It also provides,                                  if available, additional information if the image is invalid.    @retval EFI_SUCCESS            The image was successfully checked.   @retval EFI_INVALID_PARAMETER  The Image was NULL.   @retval EFI_UNSUPPORTED        The operation is not supported.   @retval EFI_SECURITY_VIOLATIO  The operation could not be performed due to an authentication failure.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_CHECK_IMAGE
function_decl|)
parameter_list|(
name|IN
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|ImageIndex
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Image
parameter_list|,
name|IN
name|UINTN
name|ImageSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|ImageUpdatable
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns information about the firmware package.    This function returns package information.    @param[in]  This                     A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.   @param[out] PackageVersion           A version number that represents all the firmware images in the device.                                        The format is vendor specific and new version must have a greater value                                        than the old version. If PackageVersion is not supported, the value is                                        0xFFFFFFFF. A value of 0xFFFFFFFE indicates that package version                                        comparison is to be performed using PackageVersionName. A value of                                        0xFFFFFFFD indicates that package version update is in progress.   @param[out] PackageVersionName       A pointer to a pointer to a null-terminated string representing                                        the package version name. The buffer is allocated by this function with                                        AllocatePool(), and it is the caller's responsibility to free it with a                                        call to FreePool().   @param[out] PackageVersionNameMaxLen The maximum length of package version name if device supports update of                                        package version name. A value of 0 indicates the device does not support                                        update of package version name. Length is the number of Unicode characters,                                        including the terminating null character.   @param[out] AttributesSupported      Package attributes that are supported by this device. See 'Package Attribute                                        Definitions' for possible returned values of this parameter. A value of 1                                        indicates the attribute is supported and the current setting value is                                        indicated in AttributesSetting. A value of 0 indicates the attribute is not                                        supported and the current setting value in AttributesSetting is meaningless.   @param[out] AttributesSetting        Package attributes. See 'Package Attribute Definitions' for possible returned                                        values of this parameter    @retval EFI_SUCCESS                  The package information was successfully returned.   @retval EFI_UNSUPPORTED              The operation is not supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_PACKAGE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|PackageVersion
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|PackageVersionName
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|PackageVersionNameMaxLen
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|AttributesSupported
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|AttributesSetting
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Updates information about the firmware package.    This function updates package information.   This function returns EFI_UNSUPPORTED if the package information is not updatable.   VendorCode enables vendor to implement vendor-specific package information update policy.   Null if the caller did not specify this policy or use the default policy.    @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.   @param[in]  Image              Points to the authentication image.                                  Null if authentication is not required.   @param[in]  ImageSize          Size of the authentication image in bytes.                                  0 if authentication is not required.   @param[in]  VendorCode         This enables vendor to implement vendor-specific firmware                                  image update policy.                                  Null indicates the caller did not specify this policy or use                                  the default policy.   @param[in]  PackageVersion     The new package version.   @param[in]  PackageVersionName A pointer to the new null-terminated Unicode string representing                                  the package version name.                                  The string length is equal to or less than the value returned in                                  PackageVersionNameMaxLen.    @retval EFI_SUCCESS            The device was successfully updated with the new package                                  information.   @retval EFI_INVALID_PARAMETER  The PackageVersionName length is longer than the value                                  returned in PackageVersionNameMaxLen.   @retval EFI_UNSUPPORTED        The operation is not supported.   @retval EFI_SECURITY_VIOLATIO  The operation could not be performed due to an authentication failure.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_PACKAGE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Image
parameter_list|,
name|IN
name|UINTN
name|ImageSize
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|VendorCode
parameter_list|,
name|IN
name|UINT32
name|PackageVersion
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|PackageVersionName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_FIRMWARE_MANAGEMENT_PROTOCOL
end_comment

begin_comment
comment|/// The protocol for managing firmware provides the following services.
end_comment

begin_comment
comment|/// - Get the attributes of the current firmware image. Attributes include revision level.
end_comment

begin_comment
comment|/// - Get a copy of the current firmware image. As an example, this service could be used by a
end_comment

begin_comment
comment|///   management application to facilitate a firmware roll-back.
end_comment

begin_comment
comment|/// - Program the device with a firmware image supplied by the user.
end_comment

begin_comment
comment|/// - Label all the firmware images within a device with a single version.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_FIRMWARE_MANAGEMENT_PROTOCOL
block|{
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE_INFO
name|GetImageInfo
decl_stmt|;
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE
name|GetImage
decl_stmt|;
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_IMAGE
name|SetImage
decl_stmt|;
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_CHECK_IMAGE
name|CheckImage
decl_stmt|;
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_PACKAGE_INFO
name|GetPackageInfo
decl_stmt|;
name|EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_PACKAGE_INFO
name|SetPackageInfo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFirmwareManagementProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

