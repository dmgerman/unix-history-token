begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares UEFI PI Multi-processor PPI.   This PPI is installed by some platform or chipset-specific PEIM that abstracts   handling multiprocessor support.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is introduced in PI Version 1.4.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_MP_SERVICES_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_MP_SERVICES_PPI_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/MpService.h>
end_include

begin_define
define|#
directive|define
name|EFI_PEI_MP_SERVICES_PPI_GUID
define|\
value|{ \     0xee16160a, 0xe8be, 0x47a6, { 0x82, 0xa, 0xc6, 0x90, 0xd, 0xb0, 0x25, 0xa } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_MP_SERVICES_PPI
name|EFI_PEI_MP_SERVICES_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Get the number of CPU's.    @param[in]  PeiServices         An indirect pointer to the PEI Services Table                                   published by the PEI Foundation.   @param[in]  This                Pointer to this instance of the PPI.   @param[out] NumberOfProcessors  Pointer to the total number of logical processors in                                   the system, including the BSP and disabled APs.   @param[out] NumberOfEnabledProcessors                                   Number of processors in the system that are enabled.    @retval EFI_SUCCESS             The number of logical processors and enabled                                   logical processors was retrieved.   @retval EFI_DEVICE_ERROR        The calling processor is an AP.   @retval EFI_INVALID_PARAMETER   NumberOfProcessors is NULL.                                   NumberOfEnabledProcessors is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_MP_SERVICES_GET_NUMBER_OF_PROCESSORS
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
name|EFI_PEI_MP_SERVICES_PPI
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|NumberOfProcessors
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|NumberOfEnabledProcessors
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get information on a specific CPU.    @param[in]  PeiServices         An indirect pointer to the PEI Services Table                                   published by the PEI Foundation.   @param[in]  This                Pointer to this instance of the PPI.   @param[in]  ProcessorNumber     Pointer to the total number of logical processors in                                   the system, including the BSP and disabled APs.   @param[out] ProcessorInfoBuffer Number of processors in the system that are enabled.    @retval EFI_SUCCESS             Processor information was returned.   @retval EFI_DEVICE_ERROR        The calling processor is an AP.   @retval EFI_INVALID_PARAMETER   ProcessorInfoBuffer is NULL.   @retval EFI_NOT_FOUND           The processor with the handle specified by                                   ProcessorNumber does not exist in the platform. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_MP_SERVICES_GET_PROCESSOR_INFO
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
name|EFI_PEI_MP_SERVICES_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ProcessorNumber
parameter_list|,
name|OUT
name|EFI_PROCESSOR_INFORMATION
modifier|*
name|ProcessorInfoBuffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Activate all of the application proessors.    @param[in] PeiServices          An indirect pointer to the PEI Services Table                                   published by the PEI Foundation.   @param[in] This                 A pointer to the EFI_PEI_MP_SERVICES_PPI instance.   @param[in] Procedure            A pointer to the function to be run on enabled APs of                                   the system.   @param[in] SingleThread         If TRUE, then all the enabled APs execute the function                                   specified by Procedure one by one, in ascending order                                   of processor handle number. If FALSE, then all the                                   enabled APs execute the function specified by Procedure                                   simultaneously.   @param[in] TimeoutInMicroSeconds                                   Indicates the time limit in microseconds for APs to                                   return from Procedure, for blocking mode only. Zero                                   means infinity. If the timeout expires before all APs                                   return from Procedure, then Procedure on the failed APs                                   is terminated. All enabled APs are available for next                                   function assigned by EFI_PEI_MP_SERVICES_PPI.StartupAllAPs()                                   or EFI_PEI_MP_SERVICES_PPI.StartupThisAP(). If the                                   timeout expires in blocking mode, BSP returns                                   EFI_TIMEOUT.   @param[in] ProcedureArgument    The parameter passed into Procedure for all APs.    @retval EFI_SUCCESS             In blocking mode, all APs have finished before the                                   timeout expired.   @retval EFI_DEVICE_ERROR        Caller processor is AP.   @retval EFI_NOT_STARTED         No enabled APs exist in the system.   @retval EFI_NOT_READY           Any enabled APs are busy.   @retval EFI_TIMEOUT             In blocking mode, the timeout expired before all                                   enabled APs have finished.   @retval EFI_INVALID_PARAMETER   Procedure is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_MP_SERVICES_STARTUP_ALL_APS
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
name|EFI_PEI_MP_SERVICES_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_AP_PROCEDURE
name|Procedure
parameter_list|,
name|IN
name|BOOLEAN
name|SingleThread
parameter_list|,
name|IN
name|UINTN
name|TimeoutInMicroSeconds
parameter_list|,
name|IN
name|VOID
modifier|*
name|ProcedureArgument
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Activate a specific application processor.    @param[in] PeiServices          An indirect pointer to the PEI Services Table                                   published by the PEI Foundation.   @param[in] This                 A pointer to the EFI_PEI_MP_SERVICES_PPI instance.   @param[in] Procedure            A pointer to the function to be run on enabled APs of                                   the system.   @param[in] ProcessorNumber      The handle number of the AP. The range is from 0 to the                                   total number of logical processors minus 1. The total                                   number of logical processors can be retrieved by                                   EFI_PEI_MP_SERVICES_PPI.GetNumberOfProcessors().   @param[in] TimeoutInMicroSeconds                                   Indicates the time limit in microseconds for APs to                                   return from Procedure, for blocking mode only. Zero                                   means infinity. If the timeout expires before all APs                                   return from Procedure, then Procedure on the failed APs                                   is terminated. All enabled APs are available for next                                   function assigned by EFI_PEI_MP_SERVICES_PPI.StartupAllAPs()                                   or EFI_PEI_MP_SERVICES_PPI.StartupThisAP(). If the                                   timeout expires in blocking mode, BSP returns                                   EFI_TIMEOUT.   @param[in] ProcedureArgument    The parameter passed into Procedure for all APs.    @retval EFI_SUCCESS             In blocking mode, specified AP finished before the                                   timeout expires.   @retval EFI_DEVICE_ERROR        The calling processor is an AP.   @retval EFI_TIMEOUT             In blocking mode, the timeout expired before the                                   specified AP has finished.   @retval EFI_NOT_FOUND           The processor with the handle specified by                                   ProcessorNumber does not exist.   @retval EFI_INVALID_PARAMETER   ProcessorNumber specifies the BSP or disabled AP.   @retval EFI_INVALID_PARAMETER   Procedure is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_MP_SERVICES_STARTUP_THIS_AP
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
name|EFI_PEI_MP_SERVICES_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_AP_PROCEDURE
name|Procedure
parameter_list|,
name|IN
name|UINTN
name|ProcessorNumber
parameter_list|,
name|IN
name|UINTN
name|TimeoutInMicroseconds
parameter_list|,
name|IN
name|VOID
modifier|*
name|ProcedureArgument
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Switch the boot strap processor.    @param[in] PeiServices          An indirect pointer to the PEI Services Table                                   published by the PEI Foundation.   @param[in] This                 A pointer to the EFI_PEI_MP_SERVICES_PPI instance.   @param[in] ProcessorNumber      The handle number of the AP. The range is from 0 to the                                   total number of logical processors minus 1. The total                                   number of logical processors can be retrieved by                                   EFI_PEI_MP_SERVICES_PPI.GetNumberOfProcessors().   @param[in] EnableOldBSP         If TRUE, then the old BSP will be listed as an enabled                                   AP. Otherwise, it will be disabled.    @retval EFI_SUCCESS             BSP successfully switched.   @retval EFI_UNSUPPORTED         Switching the BSP cannot be completed prior to this                                   service returning.   @retval EFI_UNSUPPORTED         Switching the BSP is not supported.   @retval EFI_SUCCESS             The calling processor is an AP.   @retval EFI_NOT_FOUND           The processor with the handle specified by                                   ProcessorNumber does not exist.   @retval EFI_INVALID_PARAMETER   ProcessorNumber specifies the current BSP or a disabled                                   AP.   @retval EFI_NOT_READY           The specified AP is busy. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_MP_SERVICES_SWITCH_BSP
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
name|EFI_PEI_MP_SERVICES_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ProcessorNumber
parameter_list|,
name|IN
name|BOOLEAN
name|EnableOldBSP
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Enable or disable an application processor.    @param[in] PeiServices          An indirect pointer to the PEI Services Table                                   published by the PEI Foundation.   @param[in] This                 A pointer to the EFI_PEI_MP_SERVICES_PPI instance.   @param[in] ProcessorNumber      The handle number of the AP. The range is from 0 to the                                   total number of logical processors minus 1. The total                                   number of logical processors can be retrieved by                                   EFI_PEI_MP_SERVICES_PPI.GetNumberOfProcessors().   @param[in] EnableAP             Specifies the new state for the processor for enabled,                                   FALSE for disabled.   @param[in] HealthFlag           If not NULL, a pointer to a value that specifies the                                   new health status of the AP. This flag corresponds to                                   StatusFlag defined in EFI_PEI_MP_SERVICES_PPI.GetProcessorInfo().                                   Only the PROCESSOR_HEALTH_STATUS_BIT is used. All other                                   bits are ignored. If it is NULL, this parameter is                                   ignored.    @retval EFI_SUCCESS             The specified AP was enabled or disabled successfully.   @retval EFI_UNSUPPORTED         Enabling or disabling an AP cannot be completed prior                                   to this service returning.   @retval EFI_UNSUPPORTED         Enabling or disabling an AP is not supported.   @retval EFI_DEVICE_ERROR        The calling processor is an AP.   @retval EFI_NOT_FOUND           Processor with the handle specified by ProcessorNumber                                   does not exist.   @retval EFI_INVALID_PARAMETER   ProcessorNumber specifies the BSP. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_MP_SERVICES_ENABLEDISABLEAP
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
name|EFI_PEI_MP_SERVICES_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ProcessorNumber
parameter_list|,
name|IN
name|BOOLEAN
name|EnableAP
parameter_list|,
name|IN
name|UINT32
modifier|*
name|HealthFlag
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Identify the currently executing processor.    @param[in]  PeiServices         An indirect pointer to the PEI Services Table                                   published by the PEI Foundation.   @param[in]  This                A pointer to the EFI_PEI_MP_SERVICES_PPI instance.   @param[out] ProcessorNumber     The handle number of the AP. The range is from 0 to the                                   total number of logical processors minus 1. The total                                   number of logical processors can be retrieved by                                   EFI_PEI_MP_SERVICES_PPI.GetNumberOfProcessors().    @retval EFI_SUCCESS             The current processor handle number was returned in                                   ProcessorNumber.   @retval EFI_INVALID_PARAMETER   ProcessorNumber is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_MP_SERVICES_WHOAMI
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
name|EFI_PEI_MP_SERVICES_PPI
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|ProcessorNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI is installed by some platform or chipset-specific PEIM that abstracts
end_comment

begin_comment
comment|/// handling multiprocessor support.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_MP_SERVICES_PPI
block|{
name|EFI_PEI_MP_SERVICES_GET_NUMBER_OF_PROCESSORS
name|GetNumberOfProcessors
decl_stmt|;
name|EFI_PEI_MP_SERVICES_GET_PROCESSOR_INFO
name|GetProcessorInfo
decl_stmt|;
name|EFI_PEI_MP_SERVICES_STARTUP_ALL_APS
name|StartupAllAPs
decl_stmt|;
name|EFI_PEI_MP_SERVICES_STARTUP_THIS_AP
name|StartupThisAP
decl_stmt|;
name|EFI_PEI_MP_SERVICES_SWITCH_BSP
name|SwitchBSP
decl_stmt|;
name|EFI_PEI_MP_SERVICES_ENABLEDISABLEAP
name|EnableDisableAP
decl_stmt|;
name|EFI_PEI_MP_SERVICES_WHOAMI
name|WhoAmI
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiMpServicesPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

