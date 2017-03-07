begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI SMM Control2 Protocol as defined in the PI 1.2 specification.    This protocol is used initiate synchronous SMI activations. This protocol could be published by a   processor driver to abstract the SMI IPI or a driver which abstracts the ASIC that is supporting the   APM port. Because of the possibility of performing SMI IPI transactions, the ability to generate this    event from a platform chipset agent is an optional capability for both IA-32 and x64-based systems.    The EFI_SMM_CONTROL2_PROTOCOL is produced by a runtime driver. It provides  an    abstraction of the platform hardware that generates an SMI.  There are often I/O ports that, when    accessed, will generate the SMI.  Also, the hardware optionally supports the periodic generation of    these signals.    Copyright (c) 2009 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_CONTROL2_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_CONTROL2_H_
end_define

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_CONTROL2_PROTOCOL_GUID
define|\
value|{ \     0x843dc720, 0xab1e, 0x42cb, {0x93, 0x57, 0x8a, 0x0, 0x78, 0xf3, 0x56, 0x1b}  \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_CONTROL2_PROTOCOL
name|EFI_SMM_CONTROL2_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINTN
name|EFI_SMM_PERIOD
typedef|;
end_typedef

begin_comment
comment|/**   Invokes SMI activation from either the preboot or runtime environment.    This function generates an SMI.    @param[in]     This                The EFI_SMM_CONTROL2_PROTOCOL instance.   @param[in,out] CommandPort         The value written to the command port.   @param[in,out] DataPort            The value written to the data port.   @param[in]     Periodic            Optional mechanism to engender a periodic stream.   @param[in]     ActivationInterval  Optional parameter to repeat at this period one                                      time or, if the Periodic Boolean is set, periodically.    @retval EFI_SUCCESS            The SMI/PMI has been engendered.   @retval EFI_DEVICE_ERROR       The timing is unsupported.   @retval EFI_INVALID_PARAMETER  The activation period is unsupported.   @retval EFI_INVALID_PARAMETER  The last periodic activation has not been cleared.    @retval EFI_NOT_STARTED        The SMM base service has not been initialized. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_ACTIVATE2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_CONTROL2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|CommandPort
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|DataPort
name|OPTIONAL
parameter_list|,
name|IN
name|BOOLEAN
name|Periodic
name|OPTIONAL
parameter_list|,
name|IN
name|UINTN
name|ActivationInterval
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Clears any system state that was created in response to the Trigger() call.    This function acknowledges and causes the deassertion of the SMI activation source.    @param[in] This                The EFI_SMM_CONTROL2_PROTOCOL instance.   @param[in] Periodic            Optional parameter to repeat at this period one time    @retval EFI_SUCCESS            The SMI/PMI has been engendered.   @retval EFI_DEVICE_ERROR       The source could not be cleared.   @retval EFI_INVALID_PARAMETER  The service did not support the Periodic input argument. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_DEACTIVATE2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_CONTROL2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|Periodic
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SMM_CONTROL2_PROTOCOL is produced by a runtime driver. It provides  an
end_comment

begin_comment
comment|/// abstraction of the platform hardware that generates an SMI.  There are often I/O ports that, when
end_comment

begin_comment
comment|/// accessed, will generate the SMI.  Also, the hardware optionally supports the periodic generation of
end_comment

begin_comment
comment|/// these signals.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_CONTROL2_PROTOCOL
block|{
name|EFI_SMM_ACTIVATE2
name|Trigger
decl_stmt|;
name|EFI_SMM_DEACTIVATE2
name|Clear
decl_stmt|;
comment|///
comment|/// Minimum interval at which the platform can set the period.  A maximum is not
comment|/// specified in that the SMM infrastructure code can emulate a maximum interval that is
comment|/// greater than the hardware capabilities by using software emulation in the SMM
comment|/// infrastructure code.
comment|///
name|EFI_SMM_PERIOD
name|MinimumTriggerPeriod
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmControl2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

