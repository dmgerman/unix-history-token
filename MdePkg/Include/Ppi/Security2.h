begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Pei Security2 PPI.    This PPI is installed by some platform PEIM that abstracts the security    policy to the PEI Foundation, namely the case of a PEIM's authentication    state being returned during the PEI section extraction process.    Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SECURITY2_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__SECURITY2_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_SECURITY2_PPI_GUID
define|\
value|{ 0xdcd0be23, 0x9586, 0x40f4, { 0xb6, 0x43, 0x6, 0x52, 0x2c, 0xed, 0x4e, 0xde } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_SECURITY2_PPI
name|EFI_PEI_SECURITY2_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Allows the platform builder to implement a security policy    in response to varying file authentication states.    This service is published by some platform PEIM. The purpose of   this service is to expose a given platform's policy-based   response to the PEI Foundation. For example, if there is a PEIM   in a GUIDed encapsulation section and the extraction of the PEI   file section yields an authentication failure, there is no a   priori policy in the PEI Foundation. Specifically, this   situation leads to the question whether PEIMs that are either   not in GUIDed sections or are in sections whose authentication   fails should still be executed.    @param PeiServices             An indirect pointer to the PEI Services                                  Table published by the PEI Foundation.   @param This                    Interface pointer that implements the                                  particular EFI_PEI_SECURITY2_PPI instance.   @param AuthenticationStatus    Authentication status of the file.                                  xx00 Image was not signed.                                  xxx1 Platform security policy override.                                        Assumes same meaning as 0010 (the image was signed, the                                       signature was tested, and the signature passed authentication test).                                  0010 Image was signed, the signature was tested,                                        and the signature passed authentication test.                                  0110 Image was signed and the signature was not tested.                                  1010 Image was signed, the signature was tested,                                        and the signature failed the authentication test.   @param FvHandle                Handle of the volume in which the file                                  resides. This allows different policies                                  depending on different firmware volumes.   @param FileHandle              Handle of the file under review.   @param DeferExecution          Pointer to a variable that alerts the                                  PEI Foundation to defer execution of a                                  PEIM.    @retval EFI_SUCCESS            The service performed its action successfully.   @retval EFI_SECURITY_VIOLATION The object cannot be trusted.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SECURITY_AUTHENTICATION_STATE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_SECURITY2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|AuthenticationStatus
parameter_list|,
name|IN
name|EFI_PEI_FV_HANDLE
name|FvHandle
parameter_list|,
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|OUT
name|BOOLEAN
modifier|*
name|DeferExecution
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI is a means by which the platform builder can indicate
end_comment

begin_comment
comment|/// a response to a PEIM's authentication state. This can be in
end_comment

begin_comment
comment|/// the form of a requirement for the PEI Foundation to skip a
end_comment

begin_comment
comment|/// module using the DeferExecution Boolean output in the
end_comment

begin_comment
comment|/// AuthenticationState() member function. Alternately, the
end_comment

begin_comment
comment|/// Security PPI can invoke something like a cryptographic PPI
end_comment

begin_comment
comment|/// that hashes the PEIM contents to log attestations, for which
end_comment

begin_comment
comment|/// the FileHandle parameter in AuthenticationState() will be
end_comment

begin_comment
comment|/// useful. If this PPI does not exist, PEIMs will be considered
end_comment

begin_comment
comment|/// trusted.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_SECURITY2_PPI
block|{
name|EFI_PEI_SECURITY_AUTHENTICATION_STATE
name|AuthenticationState
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiSecurity2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

