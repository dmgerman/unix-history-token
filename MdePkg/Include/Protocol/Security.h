begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Security Architectural Protocol as defined in PI Specification VOLUME 2 DXE    Used to provide Security services.  Specifically, dependening upon the    authentication state of a discovered driver in a Firmware Volume, the    portable DXE Core Dispatcher will call into the Security Architectural    Protocol (SAP) with the authentication state of the driver.    This call-out allows for OEM-specific policy decisions to be made, such   as event logging for attested boots, locking flash in response to discovering   an unsigned driver or failed signature check, or other exception response.    The SAP can also change system behavior by having the DXE core put a driver   in the Schedule-On-Request (SOR) state.  This will allow for later disposition    of the driver by platform agent, such as Platform BDS.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_SECURITY_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_SECURITY_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Security Code Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SECURITY_ARCH_PROTOCOL_GUID
define|\
value|{ 0xA46423E3, 0x4617, 0x49f1, {0xB9, 0xFF, 0xD1, 0xBF, 0xA9, 0x11, 0x58, 0x39 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SECURITY_ARCH_PROTOCOL
name|EFI_SECURITY_ARCH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The EFI_SECURITY_ARCH_PROTOCOL (SAP) is used to abstract platform-specific    policy from the DXE core response to an attempt to use a file that returns a    given status for the authentication check from the section extraction protocol.      The possible responses in a given SAP implementation may include locking    flash upon failure to authenticate, attestation logging for all signed drivers,    and other exception operations.  The File parameter allows for possible logging    within the SAP of the driver.    If File is NULL, then EFI_INVALID_PARAMETER is returned.    If the file specified by File with an authentication status specified by    AuthenticationStatus is safe for the DXE Core to use, then EFI_SUCCESS is returned.    If the file specified by File with an authentication status specified by    AuthenticationStatus is not safe for the DXE Core to use under any circumstances,    then EFI_ACCESS_DENIED is returned.    If the file specified by File with an authentication status specified by    AuthenticationStatus is not safe for the DXE Core to use right now, but it    might be possible to use it at a future time, then EFI_SECURITY_VIOLATION is    returned.    @param  This             The EFI_SECURITY_ARCH_PROTOCOL instance.   @param  AuthenticationStatus                             This is the authentication type returned from the Section                            Extraction protocol. See the Section Extraction Protocol                            Specification for details on this type.   @param  File             This is a pointer to the device path of the file that is                            being dispatched. This will optionally be used for logging.    @retval EFI_SUCCESS           The file specified by File did authenticate, and the                                 platform policy dictates that the DXE Core may use File.   @retval EFI_INVALID_PARAMETER Driver is NULL.   @retval EFI_SECURITY_VIOLATION The file specified by File did not authenticate, and                                 the platform policy dictates that File should be placed                                 in the untrusted state. A file may be promoted from                                 the untrusted to the trusted state at a future time                                 with a call to the Trust() DXE Service.   @retval EFI_ACCESS_DENIED     The file specified by File did not authenticate, and                                 the platform policy dictates that File should not be                                 used for any purpose.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SECURITY_FILE_AUTHENTICATION_STATE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SECURITY_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|AuthenticationStatus
parameter_list|,
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|File
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SECURITY_ARCH_PROTOCOL is used to abstract platform-specific policy
end_comment

begin_comment
comment|/// from the DXE core.  This includes locking flash upon failure to authenticate,
end_comment

begin_comment
comment|/// attestation logging, and other exception operations.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SECURITY_ARCH_PROTOCOL
block|{
name|EFI_SECURITY_FILE_AUTHENTICATION_STATE
name|FileAuthenticationState
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSecurityArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

