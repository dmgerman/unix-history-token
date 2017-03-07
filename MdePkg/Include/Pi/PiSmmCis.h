begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Common definitions in the Platform Initialization Specification version 1.4a   VOLUME 4 System Management Mode Core Interface version.    Copyright (c) 2009 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PI_SMMCIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PI_SMMCIS_H_
end_define

begin_include
include|#
directive|include
file|<Pi/PiMultiPhase.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SmmCpuIo2.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_SYSTEM_TABLE2
name|EFI_SMM_SYSTEM_TABLE2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The System Management System Table (SMST) signature
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SMM_SMST_SIGNATURE
value|SIGNATURE_32 ('S', 'M', 'S', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The System Management System Table (SMST) revision is 1.4
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SMM_SPECIFICATION_MAJOR_REVISION
value|1
end_define

begin_define
define|#
directive|define
name|SMM_SPECIFICATION_MINOR_REVISION
value|40
end_define

begin_define
define|#
directive|define
name|EFI_SMM_SYSTEM_TABLE2_REVISION
value|((SMM_SPECIFICATION_MAJOR_REVISION<<16) | (SMM_SPECIFICATION_MINOR_REVISION))
end_define

begin_comment
comment|/**   Adds, updates, or removes a configuration table entry from the System Management System Table.    The SmmInstallConfigurationTable() function is used to maintain the list   of configuration tables that are stored in the System Management System   Table.  The list is stored as an array of (GUID, Pointer) pairs.  The list   must be allocated from pool memory with PoolType set to EfiRuntimeServicesData.    @param[in] SystemTable         A pointer to the SMM System Table (SMST).   @param[in] Guid                A pointer to the GUID for the entry to add, update, or remove.   @param[in] Table               A pointer to the buffer of the table to add.   @param[in] TableSize           The size of the table to install.    @retval EFI_SUCCESS            The (Guid, Table) pair was added, updated, or removed.   @retval EFI_INVALID_PARAMETER  Guid is not valid.   @retval EFI_NOT_FOUND          An attempt was made to delete a non-existent entry.   @retval EFI_OUT_OF_RESOURCES   There is not enough memory available to complete the operation. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_INSTALL_CONFIGURATION_TABLE2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_SYSTEM_TABLE2
modifier|*
name|SystemTable
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|VOID
modifier|*
name|Table
parameter_list|,
name|IN
name|UINTN
name|TableSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service lets the caller to get one distinct application processor (AP) to execute   a caller-provided code stream while in SMM.    @param[in]     Procedure       A pointer to the code stream to be run on the designated                                  AP of the system.   @param[in]     CpuNumber       The zero-based index of the processor number of the AP                                  on which the code stream is supposed to run.   @param[in,out] ProcArguments   Allows the caller to pass a list of parameters to the code                                  that is run by the AP.    @retval EFI_SUCCESS            The call was successful and the return parameters are valid.   @retval EFI_INVALID_PARAMETER  The input arguments are out of range.   @retval EFI_INVALID_PARAMETER  The CPU requested is not available on this SMI invocation.   @retval EFI_INVALID_PARAMETER  The CPU cannot support an additional service invocation. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_STARTUP_THIS_AP
function_decl|)
parameter_list|(
name|IN
name|EFI_AP_PROCEDURE
name|Procedure
parameter_list|,
name|IN
name|UINTN
name|CpuNumber
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|ProcArguments
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Function prototype for protocol install notification.    @param[in] Protocol   Points to the protocol's unique identifier.   @param[in] Interface  Points to the interface instance.   @param[in] Handle     The handle on which the interface was installed.    @return Status Code **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_NOTIFY_FN
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|VOID
modifier|*
name|Interface
parameter_list|,
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register a callback function be called when a particular protocol interface is installed.    The SmmRegisterProtocolNotify() function creates a registration Function that is to be    called whenever a protocol interface is installed for Protocol by    SmmInstallProtocolInterface().   If Function == NULL and Registration is an existing registration, then the callback is unhooked.    @param[in]  Protocol          The unique ID of the protocol for which the event is to be registered.   @param[in]  Function          Points to the notification function.   @param[out] Registration      A pointer to a memory location to receive the registration value.    @retval EFI_SUCCESS           Successfully returned the registration record                                 that has been added or unhooked.   @retval EFI_INVALID_PARAMETER Protocol is NULL or Registration is NULL.   @retval EFI_OUT_OF_RESOURCES  Not enough memory resource to finish the request.   @retval EFI_NOT_FOUND         If the registration is not found when Function == NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_REGISTER_PROTOCOL_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|EFI_SMM_NOTIFY_FN
name|Function
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Registration
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Manage SMI of a particular type.    @param[in]     HandlerType     Points to the handler type or NULL for root SMI handlers.   @param[in]     Context         Points to an optional context buffer.   @param[in,out] CommBuffer      Points to the optional communication buffer.   @param[in,out] CommBufferSize  Points to the size of the optional communication buffer.    @retval EFI_WARN_INTERRUPT_SOURCE_PENDING  Interrupt source was processed successfully but not quiesced.   @retval EFI_INTERRUPT_PENDING              One or more SMI sources could not be quiesced.   @retval EFI_NOT_FOUND                      Interrupt source was not handled or quiesced.   @retval EFI_SUCCESS                        Interrupt source was handled and quiesced. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_INTERRUPT_MANAGE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|HandlerType
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Context
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|CommBuffer
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|CommBufferSize
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Main entry point for an SMM handler dispatch or communicate-based callback.    @param[in]     DispatchHandle  The unique handle assigned to this handler by SmiHandlerRegister().   @param[in]     Context         Points to an optional handler context which was specified when the                                  handler was registered.   @param[in,out] CommBuffer      A pointer to a collection of data in memory that will                                  be conveyed from a non-SMM environment into an SMM environment.   @param[in,out] CommBufferSize  The size of the CommBuffer.    @retval EFI_SUCCESS                         The interrupt was handled and quiesced. No other handlers                                                should still be called.   @retval EFI_WARN_INTERRUPT_SOURCE_QUIESCED  The interrupt has been quiesced but other handlers should                                                still be called.   @retval EFI_WARN_INTERRUPT_SOURCE_PENDING   The interrupt is still pending and other handlers should still                                                be called.   @retval EFI_INTERRUPT_PENDING               The interrupt could not be quiesced. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_HANDLER_ENTRY_POINT2
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|DispatchHandle
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Context
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|CommBuffer
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|CommBufferSize
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Registers a handler to execute within SMM.    @param[in]  Handler            Handler service function pointer.   @param[in]  HandlerType        Points to the handler type or NULL for root SMI handlers.   @param[out] DispatchHandle     On return, contains a unique handle which can be used to later                                  unregister the handler function.    @retval EFI_SUCCESS            SMI handler added successfully.   @retval EFI_INVALID_PARAMETER  Handler is NULL or DispatchHandle is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_INTERRUPT_REGISTER
function_decl|)
parameter_list|(
name|IN
name|EFI_SMM_HANDLER_ENTRY_POINT2
name|Handler
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|HandlerType
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|DispatchHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Unregister a handler in SMM.    @param[in] DispatchHandle      The handle that was specified when the handler was registered.    @retval EFI_SUCCESS            Handler function was successfully unregistered.   @retval EFI_INVALID_PARAMETER  DispatchHandle does not refer to a valid handle. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_INTERRUPT_UNREGISTER
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|DispatchHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor information and functionality needed by SMM Foundation.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SMM_ENTRY_CONTEXT
block|{
name|EFI_SMM_STARTUP_THIS_AP
name|SmmStartupThisAp
decl_stmt|;
comment|///
comment|/// A number between zero and the NumberOfCpus field. This field designates which
comment|/// processor is executing the SMM Foundation.
comment|///
name|UINTN
name|CurrentlyExecutingCpu
decl_stmt|;
comment|///
comment|/// The number of possible processors in the platform.  This is a 1 based
comment|/// counter.  This does not indicate the number of processors that entered SMM.
comment|///
name|UINTN
name|NumberOfCpus
decl_stmt|;
comment|///
comment|/// Points to an array, where each element describes the number of bytes in the
comment|/// corresponding save state specified by CpuSaveState. There are always
comment|/// NumberOfCpus entries in the array.
comment|///
name|UINTN
modifier|*
name|CpuSaveStateSize
decl_stmt|;
comment|///
comment|/// Points to an array, where each element is a pointer to a CPU save state. The
comment|/// corresponding element in CpuSaveStateSize specifies the number of bytes in the
comment|/// save state area. There are always NumberOfCpus entries in the array.
comment|///
name|VOID
modifier|*
modifier|*
name|CpuSaveState
decl_stmt|;
block|}
name|EFI_SMM_ENTRY_CONTEXT
typedef|;
end_typedef

begin_comment
comment|/**   This function is the main entry point to the SMM Foundation.    @param[in] SmmEntryContext  Processor information and functionality needed by SMM Foundation. **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_ENTRY_POINT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_ENTRY_CONTEXT
modifier|*
name|SmmEntryContext
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Management System Table (SMST)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The System Management System Table (SMST) is a table that contains a collection of common
end_comment

begin_comment
comment|/// services for managing SMRAM allocation and providing basic I/O services. These services are
end_comment

begin_comment
comment|/// intended for both preboot and runtime usage.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_SYSTEM_TABLE2
block|{
comment|///
comment|/// The table header for the SMST.
comment|///
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// A pointer to a NULL-terminated Unicode string containing the vendor name.
comment|/// It is permissible for this pointer to be NULL.
comment|///
name|CHAR16
modifier|*
name|SmmFirmwareVendor
decl_stmt|;
comment|///
comment|/// The particular revision of the firmware.
comment|///
name|UINT32
name|SmmFirmwareRevision
decl_stmt|;
name|EFI_SMM_INSTALL_CONFIGURATION_TABLE2
name|SmmInstallConfigurationTable
decl_stmt|;
comment|///
comment|/// I/O Service
comment|///
name|EFI_SMM_CPU_IO2_PROTOCOL
name|SmmIo
decl_stmt|;
comment|///
comment|/// Runtime memory services
comment|///
name|EFI_ALLOCATE_POOL
name|SmmAllocatePool
decl_stmt|;
name|EFI_FREE_POOL
name|SmmFreePool
decl_stmt|;
name|EFI_ALLOCATE_PAGES
name|SmmAllocatePages
decl_stmt|;
name|EFI_FREE_PAGES
name|SmmFreePages
decl_stmt|;
comment|///
comment|/// MP service
comment|///
name|EFI_SMM_STARTUP_THIS_AP
name|SmmStartupThisAp
decl_stmt|;
comment|///
comment|/// CPU information records
comment|///
comment|///
comment|/// A number between zero and and the NumberOfCpus field. This field designates
comment|/// which processor is executing the SMM infrastructure.
comment|///
name|UINTN
name|CurrentlyExecutingCpu
decl_stmt|;
comment|///
comment|/// The number of possible processors in the platform.  This is a 1 based counter.
comment|///
name|UINTN
name|NumberOfCpus
decl_stmt|;
comment|///
comment|/// Points to an array, where each element describes the number of bytes in the
comment|/// corresponding save state specified by CpuSaveState. There are always
comment|/// NumberOfCpus entries in the array.
comment|///
name|UINTN
modifier|*
name|CpuSaveStateSize
decl_stmt|;
comment|///
comment|/// Points to an array, where each element is a pointer to a CPU save state. The
comment|/// corresponding element in CpuSaveStateSize specifies the number of bytes in the
comment|/// save state area. There are always NumberOfCpus entries in the array.
comment|///
name|VOID
modifier|*
modifier|*
name|CpuSaveState
decl_stmt|;
comment|///
comment|/// Extensibility table
comment|///
comment|///
comment|/// The number of UEFI Configuration Tables in the buffer SmmConfigurationTable.
comment|///
name|UINTN
name|NumberOfTableEntries
decl_stmt|;
comment|///
comment|/// A pointer to the UEFI Configuration Tables. The number of entries in the table is
comment|/// NumberOfTableEntries.
comment|///
name|EFI_CONFIGURATION_TABLE
modifier|*
name|SmmConfigurationTable
decl_stmt|;
comment|///
comment|/// Protocol services
comment|///
name|EFI_INSTALL_PROTOCOL_INTERFACE
name|SmmInstallProtocolInterface
decl_stmt|;
name|EFI_UNINSTALL_PROTOCOL_INTERFACE
name|SmmUninstallProtocolInterface
decl_stmt|;
name|EFI_HANDLE_PROTOCOL
name|SmmHandleProtocol
decl_stmt|;
name|EFI_SMM_REGISTER_PROTOCOL_NOTIFY
name|SmmRegisterProtocolNotify
decl_stmt|;
name|EFI_LOCATE_HANDLE
name|SmmLocateHandle
decl_stmt|;
name|EFI_LOCATE_PROTOCOL
name|SmmLocateProtocol
decl_stmt|;
comment|///
comment|/// SMI Management functions
comment|///
name|EFI_SMM_INTERRUPT_MANAGE
name|SmiManage
decl_stmt|;
name|EFI_SMM_INTERRUPT_REGISTER
name|SmiHandlerRegister
decl_stmt|;
name|EFI_SMM_INTERRUPT_UNREGISTER
name|SmiHandlerUnRegister
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

