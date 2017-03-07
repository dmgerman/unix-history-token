begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares the Device Recovery Module PPI.    The interface of this PPI does the following:     - Reports the number of recovery DXE capsules that exist on the associated device(s)     - Finds the requested firmware binary capsule     - Loads that capsule into memory    A device can be either a group of devices, such as a block device, or an individual device.   The module determines the internal search order, with capsule number 1 as the highest load   priority and number N as the lowest priority.    Copyright (c) 2007 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is defined in UEFI Platform Initialization Specification 1.2 Volume 1:    Pre-EFI Initalization Core Interface  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PEI_DEVICE_RECOVERY_MODULE_PPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_PEI_DEVICE_RECOVERY_MODULE_PPI_H_
end_define

begin_define
define|#
directive|define
name|EFI_PEI_DEVICE_RECOVERY_MODULE_PPI_GUID
define|\
value|{ \     0x0DE2CE25, 0x446A, 0x45a7, {0xBF, 0xC9, 0x37, 0xDA, 0x26, 0x34, 0x4B, 0x37 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_DEVICE_RECOVERY_MODULE_PPI
name|EFI_PEI_DEVICE_RECOVERY_MODULE_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Returns the number of DXE capsules residing on the device.    This function searches for DXE capsules from the associated device and returns   the number and maximum size in bytes of the capsules discovered. Entry 1 is    assumed to be the highest load priority and entry N is assumed to be the lowest    priority.    @param[in]  PeiServices              General-purpose services that are available                                         to every PEIM   @param[in]  This                     Indicates the EFI_PEI_DEVICE_RECOVERY_MODULE_PPI                                        instance.   @param[out] NumberRecoveryCapsules   Pointer to a caller-allocated UINTN. On                                         output, *NumberRecoveryCapsules contains                                         the number of recovery capsule images                                         available for retrieval from this PEIM                                         instance.    @retval EFI_SUCCESS        One or more capsules were discovered.   @retval EFI_DEVICE_ERROR   A device error occurred.   @retval EFI_NOT_FOUND      A recovery DXE capsule cannot be found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_DEVICE_GET_NUMBER_RECOVERY_CAPSULE
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_DEVICE_RECOVERY_MODULE_PPI
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|NumberRecoveryCapsules
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the size and type of the requested recovery capsule.    This function gets the size and type of the capsule specified by CapsuleInstance.    @param[in]  PeiServices       General-purpose services that are available to every PEIM   @param[in]  This              Indicates the EFI_PEI_DEVICE_RECOVERY_MODULE_PPI                                  instance.   @param[in]  CapsuleInstance   Specifies for which capsule instance to retrieve                                  the information.  This parameter must be between                                  one and the value returned by GetNumberRecoveryCapsules()                                  in NumberRecoveryCapsules.   @param[out] Size              A pointer to a caller-allocated UINTN in which                                  the size of the requested recovery module is                                  returned.   @param[out] CapsuleType       A pointer to a caller-allocated EFI_GUID in which                                  the type of the requested recovery capsule is                                  returned.  The semantic meaning of the value                                  returned is defined by the implementation.    @retval EFI_SUCCESS        One or more capsules were discovered.   @retval EFI_DEVICE_ERROR   A device error occurred.   @retval EFI_NOT_FOUND      A recovery DXE capsule cannot be found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_DEVICE_GET_RECOVERY_CAPSULE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_DEVICE_RECOVERY_MODULE_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|CapsuleInstance
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
parameter_list|,
name|OUT
name|EFI_GUID
modifier|*
name|CapsuleType
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Loads a DXE capsule from some media into memory.    This function, by whatever mechanism, retrieves a DXE capsule from some device   and loads it into memory. Note that the published interface is device neutral.    @param[in]     PeiServices       General-purpose services that are available                                     to every PEIM   @param[in]     This              Indicates the EFI_PEI_DEVICE_RECOVERY_MODULE_PPI                                    instance.   @param[in]     CapsuleInstance   Specifies which capsule instance to retrieve.   @param[out]    Buffer            Specifies a caller-allocated buffer in which                                     the requested recovery capsule will be returned.    @retval EFI_SUCCESS        The capsule was loaded correctly.   @retval EFI_DEVICE_ERROR   A device error occurred.   @retval EFI_NOT_FOUND      A requested recovery DXE capsule cannot be found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_DEVICE_LOAD_RECOVERY_CAPSULE
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_DEVICE_RECOVERY_MODULE_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|CapsuleInstance
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Presents a standard interface to EFI_PEI_DEVICE_RECOVERY_MODULE_PPI,
end_comment

begin_comment
comment|/// regardless of the underlying device(s).
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_DEVICE_RECOVERY_MODULE_PPI
block|{
name|EFI_PEI_DEVICE_GET_NUMBER_RECOVERY_CAPSULE
name|GetNumberRecoveryCapsules
decl_stmt|;
comment|///< Returns the number of DXE capsules residing on the device.
name|EFI_PEI_DEVICE_GET_RECOVERY_CAPSULE_INFO
name|GetRecoveryCapsuleInfo
decl_stmt|;
comment|///< Returns the size and type of the requested recovery capsule.
name|EFI_PEI_DEVICE_LOAD_RECOVERY_CAPSULE
name|LoadRecoveryCapsule
decl_stmt|;
comment|///< Loads a DXE capsule from some media into memory.
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiDeviceRecoveryModulePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PEI_DEVICE_RECOVERY_MODULE_PPI_H_ */
end_comment

end_unit

