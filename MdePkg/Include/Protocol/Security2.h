begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Security2 Architectural Protocol as defined in PI Specification1.2.1 VOLUME 2 DXE    Abstracts security-specific functions from the DXE Foundation of UEFI Image Verification,   Trusted Computing Group (TCG) measured boot, and User Identity policy for image loading and   consoles. This protocol must be produced by a boot service or runtime DXE driver.      This protocol is optional and must be published prior to the EFI_SECURITY_ARCH_PROTOCOL.   As a result, the same driver must publish both of these interfaces.      When both Security and Security2 Architectural Protocols are published, LoadImage must use   them in accordance with the following rules:     The Security2 protocol must be used on every image being loaded.     The Security protocol must be used after the Securiy2 protocol and only on images that      have been read using Firmware Volume protocol.    When only Security architectural protocol is published, LoadImage must use it on every image   being loaded.    Copyright (c) 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_SECURITY2_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_SECURITY2_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Security2 Code Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SECURITY2_ARCH_PROTOCOL_GUID
define|\
value|{ 0x94ab2f58, 0x1438, 0x4ef1, {0x91, 0x52, 0x18, 0x94, 0x1a, 0x3a, 0x0e, 0x68 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SECURITY2_ARCH_PROTOCOL
name|EFI_SECURITY2_ARCH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The DXE Foundation uses this service to measure and/or verify a UEFI image.    This service abstracts the invocation of Trusted Computing Group (TCG) measured boot, UEFI   Secure boot, and UEFI User Identity infrastructure. For the former two, the DXE Foundation   invokes the FileAuthentication() with a DevicePath and corresponding image in   FileBuffer memory. The TCG measurement code will record the FileBuffer contents into the   appropriate PCR. The image verification logic will confirm the integrity and provenance of the   image in FileBuffer of length FileSize . The origin of the image will be DevicePath in   these cases.   If the FileBuffer is NULL, the interface will determine if the DevicePath can be connected   in order to support the User Identification policy.      @param  This             The EFI_SECURITY2_ARCH_PROTOCOL instance.   @param  File             A pointer to the device path of the file that is                            being dispatched. This will optionally be used for logging.   @param  FileBuffer       A pointer to the buffer with the UEFI file image.   @param  FileSize         The size of the file.   @param  BootPolicy       A boot policy that was used to call LoadImage() UEFI service. If                            FileAuthentication() is invoked not from the LoadImage(),                            BootPolicy must be set to FALSE.      @retval EFI_SUCCESS             The file specified by DevicePath and non-NULL                                   FileBuffer did authenticate, and the platform policy dictates                                   that the DXE Foundation may use the file.   @retval EFI_SUCCESS             The device path specified by NULL device path DevicePath                                   and non-NULL FileBuffer did authenticate, and the platform                                   policy dictates that the DXE Foundation may execute the image in                                   FileBuffer.   @retval EFI_SUCCESS             FileBuffer is NULL and current user has permission to start                                   UEFI device drivers on the device path specified by DevicePath.   @retval EFI_SECURITY_VIOLATION  The file specified by DevicePath and FileBuffer did not                                   authenticate, and the platform policy dictates that the file should be                                   placed in the untrusted state. The image has been added to the file                                   execution table.   @retval EFI_ACCESS_DENIED       The file specified by File and FileBuffer did not                                   authenticate, and the platform policy dictates that the DXE                                   Foundation may not use File.   @retval EFI_SECURITY_VIOLATION  FileBuffer is NULL and the user has no                                   permission to start UEFI device drivers on the device path specified                                   by DevicePath.   @retval EFI_SECURITY_VIOLATION  FileBuffer is not NULL and the user has no permission to load                                   drivers from the device path specified by DevicePath. The                                   image has been added into the list of the deferred images. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SECURITY2_FILE_AUTHENTICATION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SECURITY2_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|IN
name|VOID
modifier|*
name|FileBuffer
parameter_list|,
name|IN
name|UINTN
name|FileSize
parameter_list|,
name|IN
name|BOOLEAN
name|BootPolicy
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SECURITY2_ARCH_PROTOCOL is used to abstract platform-specific policy from the
end_comment

begin_comment
comment|/// DXE Foundation. This includes measuring the PE/COFF image prior to invoking, comparing the
end_comment

begin_comment
comment|/// image against a policy (whether a white-list/black-list of public image verification keys
end_comment

begin_comment
comment|/// or registered hashes).
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SECURITY2_ARCH_PROTOCOL
block|{
name|EFI_SECURITY2_FILE_AUTHENTICATION
name|FileAuthentication
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSecurity2ArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

