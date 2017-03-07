begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI SMM Base2 Protocol as defined in the PI 1.2 specification.    This protocol is utilized by all SMM drivers to locate the SMM infrastructure services and determine   whether the driver is being invoked inside SMRAM or outside of SMRAM.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_BASE2_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_BASE2_H_
end_define

begin_include
include|#
directive|include
file|<Pi/PiSmmCis.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_BASE2_PROTOCOL_GUID
define|\
value|{ \     0xf4ccbfb7, 0xf6e0, 0x47fd, {0x9d, 0xd4, 0x10, 0xa8, 0xf1, 0x50, 0xc1, 0x91 }  \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_BASE2_PROTOCOL
name|EFI_SMM_BASE2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Service to indicate whether the driver is currently executing in the SMM Initialization phase.      This service is used to indicate whether the driver is currently executing in the SMM Initialization    phase. For SMM drivers, this will return TRUE in InSmram while inside the driver's entry point and    otherwise FALSE. For combination SMM/DXE drivers, this will return FALSE in the DXE launch. For the   SMM launch, it behaves as an SMM driver.    @param[in]  This               The EFI_SMM_BASE2_PROTOCOL instance.    @param[out] InSmram            Pointer to a Boolean which, on return, indicates that the driver is                                  currently executing inside of SMRAM (TRUE) or outside of SMRAM (FALSE).    @retval EFI_SUCCESS            The call returned successfully.   @retval EFI_INVALID_PARAMETER  InSmram was NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_INSIDE_OUT2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_BASE2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|InSmram
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the location of the System Management Service Table (SMST).    This function returns the location of the System Management Service Table (SMST).  The use of the    API is such that a driver can discover the location of the SMST in its entry point and then cache it in    some driver global variable so that the SMST can be invoked in subsequent handlers.    @param[in]     This            The EFI_SMM_BASE2_PROTOCOL instance.   @param[in,out] Smst            On return, points to a pointer to the System Management Service Table (SMST).    @retval EFI_SUCCESS            The operation was successful.   @retval EFI_INVALID_PARAMETER  Smst was invalid.   @retval EFI_UNSUPPORTED        Not in SMM. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_GET_SMST_LOCATION2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_BASE2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_SMM_SYSTEM_TABLE2
modifier|*
modifier|*
name|Smst
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI SMM Base2 Protocol is utilized by all SMM drivers to locate the SMM infrastructure
end_comment

begin_comment
comment|/// services and determine whether the driver is being invoked inside SMRAM or outside of SMRAM.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_BASE2_PROTOCOL
block|{
name|EFI_SMM_INSIDE_OUT2
name|InSmm
decl_stmt|;
name|EFI_SMM_GET_SMST_LOCATION2
name|GetSmstLocation
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmBase2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

