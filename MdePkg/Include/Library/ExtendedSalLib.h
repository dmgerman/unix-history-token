begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Library class definition of Extended SAL Library.  Copyright (c) 2007 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXTENDED_SAL_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|_EXTENDED_SAL_LIB_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Sal.h>
end_include

begin_comment
comment|/**   Register ESAL Class and its associated global.      This function Registers one or more Extended SAL services in a given   class along with the associated global context.   This function is only available prior to ExitBootServices().    @param  ClassGuidLo          GUID of function class, lower 64-bits   @param  ClassGuidHi          GUID of function class, upper 64-bits   @param  ModuleGlobal         Module global for Function.   @param  ...                  List of Function/FunctionId pairs, ended by NULL    @retval EFI_SUCCESS          The Extended SAL services were registered.   @retval EFI_UNSUPPORTED      This function was called after ExitBootServices().   @retval EFI_OUT_OF_RESOURCES There are not enough resources available to register one or more of the specified services.   @retval Other                ClassGuid could not be installed onto a new handle.    **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|RegisterEsalClass
parameter_list|(
name|IN
name|CONST
name|UINT64
name|ClassGuidLo
parameter_list|,
name|IN
name|CONST
name|UINT64
name|ClassGuidHi
parameter_list|,
name|IN
name|VOID
modifier|*
name|ModuleGlobal
parameter_list|,
name|OPTIONAL
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Calls an Extended SAL Class service that was previously registered with RegisterEsalClass().      This function calls an Extended SAL Class service that was previously registered with RegisterEsalClass().    @param  ClassGuidLo    GUID of function, lower 64-bits   @param  ClassGuidHi    GUID of function, upper 64-bits   @param  FunctionId     Function in ClassGuid to call   @param  Arg2           Argument 2 ClassGuid/FunctionId defined   @param  Arg3           Argument 3 ClassGuid/FunctionId defined   @param  Arg4           Argument 4 ClassGuid/FunctionId defined   @param  Arg5           Argument 5 ClassGuid/FunctionId defined   @param  Arg6           Argument 6 ClassGuid/FunctionId defined   @param  Arg7           Argument 7 ClassGuid/FunctionId defined   @param  Arg8           Argument 8 ClassGuid/FunctionId defined      @retval EFI_SAL_ERROR  The address of ExtendedSalProc() can not be determined                          for the current CPU execution mode.   @retval Other          See the return status from ExtendedSalProc() in the                          EXTENDED_SAL_BOOT_SERVICE_PROTOCOL.    **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalCall
parameter_list|(
name|IN
name|UINT64
name|ClassGuidLo
parameter_list|,
name|IN
name|UINT64
name|ClassGuidHi
parameter_list|,
name|IN
name|UINT64
name|FunctionId
parameter_list|,
name|IN
name|UINT64
name|Arg2
parameter_list|,
name|IN
name|UINT64
name|Arg3
parameter_list|,
name|IN
name|UINT64
name|Arg4
parameter_list|,
name|IN
name|UINT64
name|Arg5
parameter_list|,
name|IN
name|UINT64
name|Arg6
parameter_list|,
name|IN
name|UINT64
name|Arg7
parameter_list|,
name|IN
name|UINT64
name|Arg8
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalStallFunctionId service of Extended SAL Stall Services Class.      This function is a wrapper for the EsalStallFunctionId service of Extended SAL   Stall Services Class. See EsalStallFunctionId of Extended SAL Specification.    @param  Microseconds                  The number of microseconds to delay.    @retval EFI_SAL_SUCCESS               Call completed without error.   @retval EFI_SAL_INVALID_ARGUMENT      Invalid argument.   @retval EFI_SAL_VIRTUAL_ADDRESS_ERROR Virtual address not registered  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalStall
parameter_list|(
name|IN
name|UINTN
name|Microseconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalSetNewPalEntryFunctionId service of Extended SAL PAL Services Services Class.      This function is a wrapper for the EsalSetNewPalEntryFunctionId service of Extended SAL   PAL Services Services Class. See EsalSetNewPalEntryFunctionId of Extended SAL Specification.    @param  PhysicalAddress                If TRUE, then PalEntryPoint is a physical address.                                          If FALSE, then PalEntryPoint is a virtual address.   @param  PalEntryPoint                  The PAL Entry Point being set.    @retval EFI_SAL_SUCCESS                The PAL Entry Point was set.   @retval EFI_SAL_VIRTUAL_ADDRESS_ERROR  This function was called in virtual mode before                                          virtual mappings for the specified Extended SAL                                          Procedure are available.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalSetNewPalEntry
parameter_list|(
name|IN
name|BOOLEAN
name|PhysicalAddress
parameter_list|,
name|IN
name|UINT64
name|PalEntryPoint
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalGetNewPalEntryFunctionId service of Extended SAL PAL Services Services Class.      This function is a wrapper for the EsalGetNewPalEntryFunctionId service of Extended SAL   PAL Services Services Class. See EsalGetNewPalEntryFunctionId of Extended SAL Specification.    @param  PhysicalAddress                If TRUE, then PalEntryPoint is a physical address.                                          If FALSE, then PalEntryPoint is a virtual address.    @retval EFI_SAL_SUCCESS                The PAL Entry Point was retrieved and returned in                                          SAL_RETURN_REGS.r9.   @retval EFI_SAL_VIRTUAL_ADDRESS_ERROR  This function was called in virtual mode before                                          virtual mappings for the specified Extended SAL                                          Procedure are available.   @return r9                             PAL entry point retrieved.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalGetNewPalEntry
parameter_list|(
name|IN
name|BOOLEAN
name|PhysicalAddress
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalGetStateBufferFunctionId service of Extended SAL MCA Log Services Class.      This function is a wrapper for the EsalGetStateBufferFunctionId service of Extended SAL   MCA Log Services Class. See EsalGetStateBufferFunctionId of Extended SAL Specification.    @param  McaType               See type parameter of SAL Procedure SAL_GET_STATE_INFO.   @param  McaBuffer             A pointer to the base address of the returned buffer.                                 Copied from SAL_RETURN_REGS.r9.   @param  BufferSize            A pointer to the size, in bytes, of the returned buffer.                                 Copied from SAL_RETURN_REGS.r10.    @retval EFI_SAL_SUCCESS       The memory buffer to store error records was returned in r9 and r10.   @retval EFI_OUT_OF_RESOURCES  A memory buffer for string error records in not available   @return r9                    Base address of the returned buffer   @return r10                   Size of the returned buffer in bytes  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalGetStateBuffer
parameter_list|(
name|IN
name|UINT64
name|McaType
parameter_list|,
name|OUT
name|UINT8
modifier|*
modifier|*
name|McaBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalSaveStateBufferFunctionId service of Extended SAL MCA Log Services Class.      This function is a wrapper for the EsalSaveStateBufferFunctionId service of Extended SAL   MCA Log Services Class. See EsalSaveStateBufferFunctionId of Extended SAL Specification.    @param  McaType      See type parameter of SAL Procedure SAL_GET_STATE_INFO.    @retval EFI_SUCCESS  The memory buffer containing the error record was written to nonvolatile storage.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalSaveStateBuffer
parameter_list|(
name|IN
name|UINT64
name|McaType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalGetVectorsFunctionId service of Extended SAL Base Services Class.      This function is a wrapper for the EsalGetVectorsFunctionId service of Extended SAL   Base Services Class. See EsalGetVectorsFunctionId of Extended SAL Specification.    @param  VectorType               The vector type to retrieve.                                    0 - MCA, 1 - BSP INIT, 2 - BOOT_RENDEZ, 3 - AP INIT.    @retval EFI_SAL_SUCCESS          Call completed without error.   @retval EFI_SAL_INVALID_ARGUMENT Invalid argument.   @retval EFI_SAL_NO_INFORMATION   The requested vector has not been registered                                    with the SAL Procedure SAL_SET_VECTORS.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalGetVectors
parameter_list|(
name|IN
name|UINT64
name|VectorType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalMcGetParamsFunctionId service of Extended SAL Base Services Class.      This function is a wrapper for the EsalMcGetParamsFunctionId service of Extended SAL   Base Services Class. See EsalMcGetParamsFunctionId of Extended SAL Specification.    @param  ParamInfoType            The parameter type to retrieve.                                    1 - rendezvous interrupt                                    2 - wake up                                    3 - Corrected Platform Error Vector.    @retval EFI_SAL_SUCCESS          Call completed without error.   @retval EFI_SAL_INVALID_ARGUMENT Invalid argument.   @retval EFI_SAL_NO_INFORMATION   The requested vector has not been registered                                    with the SAL Procedure SAL_MC_SET_PARAMS.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalMcGetParams
parameter_list|(
name|IN
name|UINT64
name|ParamInfoType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalMcGetParamsFunctionId service of Extended SAL Base Services Class.      This function is a wrapper for the EsalMcGetParamsFunctionId service of Extended SAL   Base Services Class. See EsalMcGetParamsFunctionId of Extended SAL Specification.    @retval EFI_SAL_SUCCESS          Call completed without error.   @retval EFI_SAL_NO_INFORMATION   The requested vector has not been registered                                    with the SAL Procedure SAL_MC_SET_PARAMS.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalMcGetMcParams
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalGetMcCheckinFlagsFunctionId service of Extended SAL Base Services Class.      This function is a wrapper for the EsalGetMcCheckinFlagsFunctionId service of Extended SAL   Base Services Class. See EsalGetMcCheckinFlagsFunctionId of Extended SAL Specification.    @param  CpuIndex         The index of the CPU of set of enabled CPUs to check.    @retval EFI_SAL_SUCCESS  The checkin status of the requested CPU was returned.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalGetMcCheckinFlags
parameter_list|(
name|IN
name|UINT64
name|CpuIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalAddCpuDataFunctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalAddCpuDataFunctionId service of Extended SAL   MP Services Class. See EsalAddCpuDataFunctionId of Extended SAL Specification.    @param  CpuGlobalId                 The Global ID for the CPU being added.   @param  Enabled                     The enable flag for the CPU being added.                                       TRUE means the CPU is enabled.                                       FALSE means the CPU is disabled.   @param  PalCompatibility            The PAL Compatibility value for the CPU being added.    @retval EFI_SAL_SUCCESS             The CPU was added to the database.   @retval EFI_SAL_NOT_ENOUGH_SCRATCH  There are not enough resource available to add the CPU.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalAddCpuData
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|,
name|IN
name|BOOLEAN
name|Enabled
parameter_list|,
name|IN
name|UINT64
name|PalCompatibility
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalRemoveCpuDataFunctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalRemoveCpuDataFunctionId service of Extended SAL   MP Services Class. See EsalRemoveCpuDataFunctionId of Extended SAL Specification.    @param  CpuGlobalId             The Global ID for the CPU being removed.    @retval EFI_SAL_SUCCESS         The CPU was removed from the database.   @retval EFI_SAL_NO_INFORMATION  The specified CPU is not in the database.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalRemoveCpuData
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalModifyCpuDataFunctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalModifyCpuDataFunctionId service of Extended SAL   MP Services Class. See EsalModifyCpuDataFunctionId of Extended SAL Specification.    @param  CpuGlobalId             The Global ID for the CPU being modified.   @param  Enabled                 The enable flag for the CPU being modified.                                   TRUE means the CPU is enabled.                                   FALSE means the CPU is disabled.   @param  PalCompatibility        The PAL Compatibility value for the CPU being modified.    @retval EFI_SAL_SUCCESS         The CPU database was updated.   @retval EFI_SAL_NO_INFORMATION  The specified CPU is not in the database.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalModifyCpuData
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|,
name|IN
name|BOOLEAN
name|Enabled
parameter_list|,
name|IN
name|UINT64
name|PalCompatibility
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalGetCpuDataByIdFunctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalGetCpuDataByIdFunctionId service of Extended SAL   MP Services Class. See EsalGetCpuDataByIdFunctionId of Extended SAL Specification.    @param  CpuGlobalId             The Global ID for the CPU being looked up.   @param  IndexByEnabledCpu       If TRUE, then the index of set of enabled CPUs of database is returned.                                   If FALSE, then the index of set of all CPUs of database is returned.    @retval EFI_SAL_SUCCESS         The information on the specified CPU was returned.   @retval EFI_SAL_NO_INFORMATION  The specified CPU is not in the database.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalGetCpuDataById
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|,
name|IN
name|BOOLEAN
name|IndexByEnabledCpu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalGetCpuDataByIndexFunctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalGetCpuDataByIndexFunctionId service of Extended SAL   MP Services Class. See EsalGetCpuDataByIndexFunctionId of Extended SAL Specification.    @param  Index                   The Global ID for the CPU being modified.   @param  IndexByEnabledCpu       If TRUE, then the index of set of enabled CPUs of database is returned.                                   If FALSE, then the index of set of all CPUs of database is returned.    @retval EFI_SAL_SUCCESS         The information on the specified CPU was returned.   @retval EFI_SAL_NO_INFORMATION  The specified CPU is not in the database.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalGetCpuDataByIndex
parameter_list|(
name|IN
name|UINT64
name|Index
parameter_list|,
name|IN
name|BOOLEAN
name|IndexByEnabledCpu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalWhoAmIFunctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalWhoAmIFunctionId service of Extended SAL   MP Services Class. See EsalWhoAmIFunctionId of Extended SAL Specification.    @param  IndexByEnabledCpu       If TRUE, then the index of set of enabled CPUs of database is returned.                                   If FALSE, then the index of set of all CPUs of database is returned.    @retval EFI_SAL_SUCCESS         The Global ID for the calling CPU was returned.   @retval EFI_SAL_NO_INFORMATION  The calling CPU is not in the database.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalWhoAmI
parameter_list|(
name|IN
name|BOOLEAN
name|IndexByEnabledCpu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalNumProcessors service of Extended SAL MP Services Class.      This function is a wrapper for the EsalNumProcessors service of Extended SAL   MP Services Class. See EsalNumProcessors of Extended SAL Specification.    @retval EFI_SAL_SUCCESS    The information on the number of CPUs in the platform                              was returned.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalNumProcessors
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalSetMinStateFnctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalSetMinStateFnctionId service of Extended SAL   MP Services Class. See EsalSetMinStateFnctionId of Extended SAL Specification.    @param  CpuGlobalId              The Global ID for the CPU whose MINSTATE pointer is being set.   @param  MinStatePointer          The physical address of the MINSTATE buffer for the CPU                                    specified by CpuGlobalId.    @retval EFI_SAL_SUCCESS          The MINSTATE pointer was set for the specified CPU.   @retval EFI_SAL_NO_INFORMATION   The specified CPU is not in the database.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalSetMinState
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|MinStatePointer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalGetMinStateFunctionId service of Extended SAL MP Services Class.      This function is a wrapper for the EsalGetMinStateFunctionId service of Extended SAL   MP Services Class. See EsalGetMinStateFunctionId of Extended SAL Specification.    @param  CpuGlobalId            The Global ID for the CPU whose MINSTATE pointer is being retrieved.    @retval EFI_SAL_SUCCESS        The MINSTATE pointer for the specified CPU was retrieved.   @retval EFI_SAL_NO_INFORMATION The specified CPU is not in the database.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalGetMinState
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalMcsGetStateInfoFunctionId service of Extended SAL MCA Services Class.      This function is a wrapper for the EsalMcsGetStateInfoFunctionId service of Extended SAL   MCA Services Class. See EsalMcsGetStateInfoFunctionId of Extended SAL Specification.    @param  CpuGlobalId               The Global ID for the CPU whose MCA state buffer is being retrieved.   @param  StateBufferPointer        A pointer to the returned MCA state buffer.   @param  RequiredStateBufferSize   A pointer to the size, in bytes, of the returned MCA state buffer.    @retval EFI_SUCCESS               MINSTATE successfully got and size calculated.   @retval EFI_SAL_NO_INFORMATION    Fail to get MINSTATE.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalMcaGetStateInfo
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|StateBufferPointer
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|RequiredStateBufferSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Wrapper for the EsalMcaRegisterCpuFunctionId service of Extended SAL MCA Services Class.      This function is a wrapper for the EsalMcaRegisterCpuFunctionId service of Extended SAL   MCA Services Class. See EsalMcaRegisterCpuFunctionId of Extended SAL Specification.    @param  CpuGlobalId              The Global ID for the CPU whose MCA state buffer is being set.   @param  StateBufferPointer       A pointer to the MCA state buffer.    @retval EFI_SAL_NO_INFORMATION   Cannot get the processor info with the CpuId   @retval EFI_SUCCESS              Save the processor's state info successfully  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|EsalMcaRegisterCpu
parameter_list|(
name|IN
name|UINT64
name|CpuGlobalId
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|StateBufferPointer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

