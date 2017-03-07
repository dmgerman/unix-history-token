begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Graphics PPI.   This PPI is the main interface exposed by the Graphics PEIM to be used by the   other firmware modules.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is introduced in PI Version 1.4.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_GRAPHICS_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_GRAPHICS_PPI_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/GraphicsOutput.h>
end_include

begin_define
define|#
directive|define
name|EFI_PEI_GRAPHICS_PPI_GUID
define|\
value|{ \     0x6ecd1463, 0x4a4a, 0x461b, { 0xaf, 0x5f, 0x5a, 0x33, 0xe3, 0xb2, 0x16, 0x2b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_GRAPHICS_PPI
name|EFI_PEI_GRAPHICS_PPI
typedef|;
end_typedef

begin_comment
comment|/**   The GraphicsPpiInit initializes the graphics subsystem in phases.    @param[in] GraphicsPolicyPtr    GraphicsPolicyPtr points to a configuration data                                   block of policy settings required by Graphics PEIM.    @retval EFI_SUCCESS             The invocation was successful.   @retval EFI_INVALID_PARAMETER   The phase parameter is not valid.   @retval EFI_NOT_ABORTED         The stages was not called in the proper order.   @retval EFI_NOT_FOUND           The PeiGraphicsPlatformPolicyPpi is not located.   @retval EFI_DEVICE_ERROR        The initialization failed due to device error.   @retval EFI_NOT_READY           The previous init stage is still in progress and not                                   ready for the current initialization phase yet. The                                   platform code should call this again sometime later. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GRAPHICS_INIT
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|GraphicsPolicyPtr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The GraphicsPpiGetMode returns the mode information supported by the Graphics PEI   Module.    @param[in, out] Mode            Pointer to EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE data.    @retval EFI_SUCCESS             Valid mode information was returned.   @retval EFI_INVALID_PARAMETER   The Mode parameter is not valid.   @retval EFI_DEVICE_ERROR        A hardware error occurred trying to retrieve the video                                   mode.   @retval EFI_NOT_READY           The Graphics Initialization is not competed and Mode                                   information is not yet available.The platform code                                   should call this again after the Graphics                                   initialization is done. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GRAPHICS_GET_MODE
function_decl|)
parameter_list|(
name|IN
name|OUT
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
modifier|*
name|Mode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI is the main interface exposed by the Graphics PEIM to be used by the other
end_comment

begin_comment
comment|/// firmware modules.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_GRAPHICS_PPI
block|{
name|EFI_PEI_GRAPHICS_INIT
name|GraphicsPpiInit
decl_stmt|;
name|EFI_PEI_GRAPHICS_GET_MODE
name|GraphicsPpiGetMode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiGraphicsPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

