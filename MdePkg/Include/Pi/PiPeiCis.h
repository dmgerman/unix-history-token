begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   PI PEI master include file. This file should match the PI spec.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                                                          THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   PI Version 1.4a.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_PEICIS_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_PEICIS_H__
end_define

begin_include
include|#
directive|include
file|<Uefi/UefiMultiPhase.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiMultiPhase.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// The handles of EFI FV.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_PEI_FV_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The handles of EFI FFS.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_PEI_FILE_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declare the forward reference data structure for EFI_PEI_SERVICE.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_SERVICES
name|EFI_PEI_SERVICES
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declare the forward reference data structure for EFI_PEI_NOTIFY_DESCRIPTOR.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_NOTIFY_DESCRIPTOR
name|EFI_PEI_NOTIFY_DESCRIPTOR
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<Ppi/CpuIo.h>
end_include

begin_include
include|#
directive|include
file|<Ppi/PciCfg2.h>
end_include

begin_comment
comment|/**   The PEI Dispatcher will invoke each PEIM one time.  During this pass, the PEI    Dispatcher will pass control to the PEIM at the AddressOfEntryPoint in the PE Header.     @param  FileHandle       Pointer to the FFS file header.   @param  PeiServices      Describes the list of possible PEI Services.    @retval EFI_SUCCESS      The PEI completed successfully.   @retval !EFI_SUCCESS     There is error in PEIM.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEIM_ENTRY_POINT2
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Entry point of the notification callback function itself within the PEIM.    @param  PeiServices      Indirect reference to the PEI Services Table.   @param  NotifyDescriptor Address of the notification descriptor data structure.   @param  Ppi              Address of the PPI that was installed.    @return Status of the notification.           The status code returned from this function is ignored. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEIM_NOTIFY_ENTRY_POINT
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_NOTIFY_DESCRIPTOR
modifier|*
name|NotifyDescriptor
parameter_list|,
name|IN
name|VOID
modifier|*
name|Ppi
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// PEI Ppi Services List Descriptors
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PEI_PPI_DESCRIPTOR_PIC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_PEI_PPI_DESCRIPTOR_PPI
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_PEI_PPI_DESCRIPTOR_NOTIFY_CALLBACK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_PEI_PPI_DESCRIPTOR_NOTIFY_DISPATCH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EFI_PEI_PPI_DESCRIPTOR_NOTIFY_TYPES
value|0x00000060
end_define

begin_define
define|#
directive|define
name|EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST
value|0x80000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The data structure through which a PEIM describes available services to the PEI Foundation.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This field is a set of flags describing the characteristics of this imported table entry.
comment|/// All flags are defined as EFI_PEI_PPI_DESCRIPTOR_***, which can also be combined into one.
comment|///
name|UINTN
name|Flags
decl_stmt|;
comment|///
comment|/// The address of the EFI_GUID that names the interface.
comment|///
name|EFI_GUID
modifier|*
name|Guid
decl_stmt|;
comment|///
comment|/// A pointer to the PPI. It contains the information necessary to install a service.
comment|///
name|VOID
modifier|*
name|Ppi
decl_stmt|;
block|}
name|EFI_PEI_PPI_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The data structure in a given PEIM that tells the PEI
end_comment

begin_comment
comment|/// Foundation where to invoke the notification service.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_NOTIFY_DESCRIPTOR
block|{
comment|///
comment|/// Details if the type of notification are callback or dispatch.
comment|///
name|UINTN
name|Flags
decl_stmt|;
comment|///
comment|/// The address of the EFI_GUID that names the interface.
comment|///
name|EFI_GUID
modifier|*
name|Guid
decl_stmt|;
comment|///
comment|/// Address of the notification callback function itself within the PEIM.
comment|///
name|EFI_PEIM_NOTIFY_ENTRY_POINT
name|Notify
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|/// This data structure is the means by which callable services are installed and
end_comment

begin_comment
comment|/// notifications are registered in the PEI phase.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
comment|///
comment|/// The typedef structure of the notification descriptor.
comment|///
name|EFI_PEI_NOTIFY_DESCRIPTOR
name|Notify
decl_stmt|;
comment|///
comment|/// The typedef structure of the PPI descriptor.
comment|///
name|EFI_PEI_PPI_DESCRIPTOR
name|Ppi
decl_stmt|;
block|}
name|EFI_PEI_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|/**   This service is the first one provided by the PEI Foundation.  This function    installs an interface in the PEI PPI database by GUID.  The purpose of the    service is to publish an interface that other parties can use to call    additional PEIMs.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table                            published by the PEI Foundation.   @param  PpiList          A pointer to the list of interfaces that the caller shall install.    @retval EFI_SUCCESS           The interface was successfully installed.   @retval EFI_INVALID_PARAMETER The PpiList pointer is NULL or Any of the PEI PPI                                  descriptors in the list do not have the                                  EFI_PEI_PPI_DESCRIPTOR_PPI bit set in the Flags field.   @retval EFI_OUT_OF_RESOURCES  There is no additional space in the PPI database.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_INSTALL_PPI
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
name|EFI_PEI_PPI_DESCRIPTOR
modifier|*
name|PpiList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function reinstalls an interface in the PEI PPI database by GUID.    The purpose of the service is to publish an interface that other parties    can use to replace a same-named interface in the protocol database    with a different interface.     @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table                            published by the PEI Foundation.   @param  OldPpi           A pointer to the former PPI in the database.   @param  NewPpi           A pointer to the new interfaces that the caller shall install.    @retval EFI_SUCCESS           The interface was successfully installed.   @retval EFI_INVALID_PARAMETER The PpiList pointer is NULL or Any of the PEI PPI descriptors in the                                  list do not have the EFI_PEI_PPI_DESCRIPTOR_PPI bit set in the Flags field.   @retval EFI_OUT_OF_RESOURCES  There is no additional space in the PPI database.   @retval EFI_NOT_FOUND         The PPI for which the reinstallation was requested has not been installed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_REINSTALL_PPI
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
name|EFI_PEI_PPI_DESCRIPTOR
modifier|*
name|OldPpi
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_PPI_DESCRIPTOR
modifier|*
name|NewPpi
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function locates an interface in the PEI PPI database by GUID.     @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES published by the PEI Foundation.   @param  Guid             A pointer to the GUID whose corresponding interface needs to be found.   @param  Instance         The N-th instance of the interface that is required.   @param  PpiDescriptor    A pointer to instance of the EFI_PEI_PPI_DESCRIPTOR.   @param  Ppi              A pointer to the instance of the interface.    @retval EFI_SUCCESS           The interface was successfully returned.   @retval EFI_NOT_FOUND         The PPI descriptor is not found in the database.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_LOCATE_PPI
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
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|Instance
parameter_list|,
name|IN
name|OUT
name|EFI_PEI_PPI_DESCRIPTOR
modifier|*
modifier|*
name|PpiDescriptor
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|Ppi
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function installs a notification service to be called back when a    given interface is installed or reinstalled.  The purpose of the service    is to publish an interface that other parties can use to call additional PPIs    that may materialize later.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation   @param  NotifyList       A pointer to the list of notification interfaces that the caller shall install.    @retval EFI_SUCCESS           The interface was successfully installed.   @retval EFI_INVALID_PARAMETER The PpiList pointer is NULL, or any of the PEI PPI descriptors in the                                  list do not have the EFI_PEI_PPI_DESCRIPTOR_PPI bit set in the Flags field.   @retval EFI_OUT_OF_RESOURCES  There is no additional space in the PPI database.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_NOTIFY_PPI
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
name|EFI_PEI_NOTIFY_DESCRIPTOR
modifier|*
name|NotifyList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function returns the present value of the boot mode.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  BootMode         A pointer to contain the value of the boot mode.    @retval EFI_SUCCESS           The boot mode returned successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GET_BOOT_MODE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|OUT
name|EFI_BOOT_MODE
modifier|*
name|BootMode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function sets the value of the boot mode.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation   @param  BootMode         The value of the boot mode to set.    @retval EFI_SUCCESS           The boot mode returned successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SET_BOOT_MODE
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
name|EFI_BOOT_MODE
name|BootMode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function returns the pointer to the list of Hand-Off Blocks (HOBs) in memory.     @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation   @param  HobList          A pointer to the list of HOBs that the PEI Foundation will initialize    @retval EFI_SUCCESS           The list was successfully returned.   @retval EFI_NOT_AVAILABLE_YET The HOB list is not yet published.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GET_HOB_LIST
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|HobList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service, published by the PEI Foundation, abstracts the creation of a Hand-Off Block's (HOB's) headers.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  Type             The type of HOB to be installed.   @param  Length           The length of the HOB to be added.   @param  Hob              The address of a pointer that will contain the HOB header.    @retval EFI_SUCCESS           The HOB was successfully created.   @retval EFI_OUT_OF_RESOURCES  There is no additional space for HOB creation.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CREATE_HOB
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
name|UINT16
name|Type
parameter_list|,
name|IN
name|UINT16
name|Length
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|Hob
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The purpose of the service is to abstract the capability of the PEI    Foundation to discover instances of firmware volumes in the system.     This service enables PEIMs to discover additional firmware volumes. The PEI Foundation uses this   service to abstract the locations and formats of various firmware volumes. These volumes include   the Boot Firmware Volume and any other volumes exposed by EFI_PEI_FV_PPI. The service   returns a volume handle of type EFI_PEI_FV_HANDLE, which must be unique within the system.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  Instance         This instance of the firmware volume to find.                            The value 0 is the Boot Firmware Volume (BFV).   @param  VolumeHandle     On exit, points to the next volumn handle or NULL if it does not exist.    @retval EFI_SUCCESS           The volume was found.   @retval EFI_NOT_FOUND         The volume was not found.   @retval EFI_INVALID_PARAMETER VolumeHandle is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_FIND_NEXT_VOLUME2
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
name|UINTN
name|Instance
parameter_list|,
name|OUT
name|EFI_PEI_FV_HANDLE
modifier|*
name|VolumeHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Searches for the next matching file in the firmware volume.    This service enables PEIMs to discover firmware files within a specified volume.   To find the first instance of a firmware file, pass a FileHandle value of NULL into the service.   The service returns a file handle of type EFI_PEI_FILE_HANDLE, which must be unique within   the system.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  SearchType       A filter to find files only of this type.   @param  FvHandle         Handle of firmware volume in which to search.   @param  FileHandle       On entry, points to the current handle from which to begin searching                            or NULL to start at the beginning of the firmware volume.                            On exit, points the file handle of the next file in the volume or NULL                            if there are no more files.    @retval EFI_SUCCESS      The file was found.   @retval EFI_NOT_FOUND    The file was not found.   @retval EFI_NOT_FOUND    The header checksum was not zero.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_FIND_NEXT_FILE2
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
name|EFI_FV_FILETYPE
name|SearchType
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_FV_HANDLE
name|FvHandle
parameter_list|,
name|IN
name|OUT
name|EFI_PEI_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Searches for the next matching section within the specified file.    This service enables PEI modules to discover the first section of a given type within a valid file.   This service will search within encapsulation sections (compression and GUIDed) as well. It will   search inside of a GUIDed section or a compressed section, but may not, for example, search a   GUIDed section inside a GUIDes section.   This service will not search within compression sections or GUIDed sections that require   extraction if memory is not present.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  SectionType      The value of the section type to find.   @param  FileHandle       Handle of the firmware file to search.   @param  SectionData      A pointer to the discovered section, if successful.    @retval EFI_SUCCESS      The section was found.   @retval EFI_NOT_FOUND    The section was not found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_FIND_SECTION_DATA2
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
name|EFI_SECTION_TYPE
name|SectionType
parameter_list|,
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|SectionData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Searches for the next matching section within the specified file.    This service enables PEI modules to discover the section of a given type within a valid file.   This service will search within encapsulation sections (compression and GUIDed) as well. It will   search inside of a GUIDed section or a compressed section, but may not, for example, search a   GUIDed section inside a GUIDes section.   This service will not search within compression sections or GUIDed sections that require   extraction if memory is not present.    @param  PeiServices           An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  SectionType           The value of the section type to find.   @param  SectionInstance       Section instance to find.   @param  FileHandle            Handle of the firmware file to search.   @param  SectionData           A pointer to the discovered section, if successful.   @param  AuthenticationStatus  A pointer to the authentication status for this section.    @retval EFI_SUCCESS      The section was found.   @retval EFI_NOT_FOUND    The section was not found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_FIND_SECTION_DATA3
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
name|EFI_SECTION_TYPE
name|SectionType
parameter_list|,
name|IN
name|UINTN
name|SectionInstance
parameter_list|,
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|SectionData
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|AuthenticationStatus
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function registers the found memory configuration with the PEI Foundation.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  MemoryBegin      The value of a region of installed memory.   @param  MemoryLength     The corresponding length of a region of installed memory.    @retval EFI_SUCCESS           The region was successfully installed in a HOB.   @retval EFI_INVALID_PARAMETER MemoryBegin and MemoryLength are illegal for this system.   @retval EFI_OUT_OF_RESOURCES  There is no additional space for HOB creation.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_INSTALL_PEI_MEMORY
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
name|EFI_PHYSICAL_ADDRESS
name|MemoryBegin
parameter_list|,
name|IN
name|UINT64
name|MemoryLength
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The purpose of the service is to publish an interface that allows    PEIMs to allocate memory ranges that are managed by the PEI Foundation.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  MemoryType       The type of memory to allocate.   @param  Pages            The number of contiguous 4 KB pages to allocate.   @param  Memory           A pointer to a physical address. On output, the address is set to the base                             of the page range that was allocated.    @retval EFI_SUCCESS           The memory range was successfully allocated.   @retval EFI_OUT_OF_RESOURCES  The pages could not be allocated.   @retval EFI_INVALID_PARAMETER The type is not equal to EfiLoaderCode, EfiLoaderData, EfiRuntimeServicesCode,                                  EfiRuntimeServicesData, EfiBootServicesCode, EfiBootServicesData,                                 EfiACPIReclaimMemory, EfiReservedMemoryType, or EfiACPIMemoryNVS.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_ALLOCATE_PAGES
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
name|EFI_MEMORY_TYPE
name|MemoryType
parameter_list|,
name|IN
name|UINTN
name|Pages
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|Memory
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The purpose of this service is to publish an interface that    allows PEIMs to allocate memory ranges that are managed by the PEI Foundation.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  Size             The number of bytes to allocate from the pool.   @param  Buffer           If the call succeeds, a pointer to a pointer to the allocated buffer; undefined otherwise.    @retval EFI_SUCCESS           The allocation was successful.   @retval EFI_OUT_OF_RESOURCES  There is not enough heap to allocate the requested size.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_ALLOCATE_POOL
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
name|UINTN
name|Size
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service copies the contents of one buffer to another buffer.    @param  Destination      The pointer to the destination buffer of the memory copy.   @param  Source           The pointer to the source buffer of the memory copy.   @param  Length           The number of bytes to copy from Source to Destination.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_COPY_MEM
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Destination
parameter_list|,
name|IN
name|VOID
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The service fills a buffer with a specified value.    @param  Buffer           The pointer to the buffer to fill.   @param  Size             The number of bytes in Buffer to fill.   @param  Value            The value to fill Buffer with.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SET_MEM
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service publishes an interface that allows PEIMs to report status codes.    ReportStatusCode() is called by PEIMs that wish to report status information on their   progress. The principal use model is for a PEIM to emit one of the standard 32-bit error codes. This   will allow a platform owner to ascertain the state of the system, especially under conditions where   the full consoles might not have been installed.    @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES table published by the PEI Foundation.   @param  Type             Indicates the type of status code being reported.   @param  Value            Describes the current status of a hardware or                            software entity. This includes information about the class and                            subclass that is used to classify the entity as well as an operation.                            For progress codes, the operation is the current activity.                            For error codes, it is the exception.For debug codes,it is not defined at this time.   @param  Instance         The enumeration of a hardware or software entity within                            the system. A system may contain multiple entities that match a class/subclass                            pairing. The instance differentiates between them. An instance of 0 indicates                            that instance information is unavailable, not meaningful, or not relevant.                            Valid instance numbers start with 1.   @param  CallerId         This optional parameter may be used to identify the caller.                            This parameter allows the status code driver to apply different rules to                            different callers.   @param  Data             This optional parameter may be used to pass additional data.    @retval EFI_SUCCESS           The function completed successfully.   @retval EFI_NOT_AVAILABLE_YET No progress code provider has installed an interface in the system.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_REPORT_STATUS_CODE
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
name|EFI_STATUS_CODE_TYPE
name|Type
parameter_list|,
name|IN
name|EFI_STATUS_CODE_VALUE
name|Value
parameter_list|,
name|IN
name|UINT32
name|Instance
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|CallerId
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|EFI_STATUS_CODE_DATA
modifier|*
name|Data
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets the entire platform.    This service resets the entire platform, including all processors   and devices, and reboots the system.   This service will never return EFI_SUCCESS.      @param  PeiServices      An indirect pointer to the EFI_PEI_SERVICES                            table published by the PEI Foundation.    @retval EFI_NOT_AVAILABLE_YET The service has not been installed yet.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_RESET_SYSTEM
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets the entire platform.    @param[in] ResetType      The type of reset to perform.   @param[in] ResetStatus    The status code for the reset.   @param[in] DataSize       The size, in bytes, of WatchdogData.   @param[in] ResetData      For a ResetType of EfiResetCold, EfiResetWarm, or EfiResetShutdown                             the data buffer starts with a Null-terminated string, optionally                             followed by additional binary data. The string is a description                             that the caller may use to further indicate the reason for the                             system reset. ResetData is only valid if ResetStatus is something                             other than EFI_SUCCESS unless the ResetType is EfiResetPlatformSpecific                             where a minimum amount of ResetData is always required.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_RESET2_SYSTEM
function_decl|)
parameter_list|(
name|IN
name|EFI_RESET_TYPE
name|ResetType
parameter_list|,
name|IN
name|EFI_STATUS
name|ResetStatus
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|ResetData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Find a file within a volume by its name.    This service searches for files with a specific name, within   either the specified firmware volume or all firmware volumes.   The service returns a file handle of type EFI_PEI_FILE_HANDLE,   which must be unique within the system.    @param FileName       A pointer to the name of the file to                         find within the firmware volume.   @param VolumeHandle   The firmware volume to search.   @param FileHandle     Upon exit, points to the found file's                         handle or NULL if it could not be found.    @retval EFI_SUCCESS             The file was found.   @retval EFI_NOT_FOUND           The file was not found.   @retval EFI_INVALID_PARAMETER   VolumeHandle or FileHandle or                                   FileName was NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_FIND_BY_NAME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|FileName
parameter_list|,
name|IN
name|EFI_PEI_FV_HANDLE
name|VolumeHandle
parameter_list|,
name|OUT
name|EFI_PEI_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information of the FV file.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Name of the file.
comment|///
name|EFI_GUID
name|FileName
decl_stmt|;
comment|///
comment|/// File type.
comment|///
name|EFI_FV_FILETYPE
name|FileType
decl_stmt|;
comment|///
comment|/// Attributes of the file.
comment|///
name|EFI_FV_FILE_ATTRIBUTES
name|FileAttributes
decl_stmt|;
comment|///
comment|/// Points to the file's data (not the header).
comment|/// Not valid if EFI_FV_FILE_ATTRIB_MEMORY_MAPPED
comment|/// is zero.
comment|///
name|VOID
modifier|*
name|Buffer
decl_stmt|;
comment|///
comment|/// Size of the file's data.
comment|///
name|UINT32
name|BufferSize
decl_stmt|;
block|}
name|EFI_FV_FILE_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information with authentication status of the FV file.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Name of the file.
comment|///
name|EFI_GUID
name|FileName
decl_stmt|;
comment|///
comment|/// File type.
comment|///
name|EFI_FV_FILETYPE
name|FileType
decl_stmt|;
comment|///
comment|/// Attributes of the file.
comment|///
name|EFI_FV_FILE_ATTRIBUTES
name|FileAttributes
decl_stmt|;
comment|///
comment|/// Points to the file's data (not the header).
comment|/// Not valid if EFI_FV_FILE_ATTRIB_MEMORY_MAPPED
comment|/// is zero.
comment|///
name|VOID
modifier|*
name|Buffer
decl_stmt|;
comment|///
comment|/// Size of the file's data.
comment|///
name|UINT32
name|BufferSize
decl_stmt|;
comment|///
comment|/// Authentication status for this file.
comment|///
name|UINT32
name|AuthenticationStatus
decl_stmt|;
block|}
name|EFI_FV_FILE_INFO2
typedef|;
end_typedef

begin_comment
comment|/**   Returns information about a specific file.    This function returns information about a specific file,   including its file name, type, attributes, starting address and   size. If the firmware volume is not memory mapped, then the   Buffer member will be NULL.    @param FileHandle   The handle of the file.   @param FileInfo     Upon exit, points to the file's                       information.    @retval EFI_SUCCESS             File information was returned.   @retval EFI_INVALID_PARAMETER   FileHandle does not                                   represent a valid file.   @retval EFI_INVALID_PARAMETER   FileInfo is NULL.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_GET_FILE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|EFI_FV_FILE_INFO
modifier|*
name|FileInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns information about a specific file.    This function returns information about a specific file,   including its file name, type, attributes, starting address, size and authentication status.   If the firmware volume is not memory mapped, then the Buffer member will be NULL.    @param FileHandle   The handle of the file.   @param FileInfo     Upon exit, points to the file's                       information.    @retval EFI_SUCCESS             File information was returned.   @retval EFI_INVALID_PARAMETER   FileHandle does not                                   represent a valid file.   @retval EFI_INVALID_PARAMETER   FileInfo is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_GET_FILE_INFO2
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|EFI_FV_FILE_INFO2
modifier|*
name|FileInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information of the FV volume.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Attributes of the firmware volume.
comment|///
name|EFI_FVB_ATTRIBUTES_2
name|FvAttributes
decl_stmt|;
comment|///
comment|/// Format of the firmware volume.
comment|///
name|EFI_GUID
name|FvFormat
decl_stmt|;
comment|///
comment|/// Name of the firmware volume.
comment|///
name|EFI_GUID
name|FvName
decl_stmt|;
comment|///
comment|/// Points to the first byte of the firmware
comment|/// volume, if bit EFI_FVB_MEMORY_MAPPED is
comment|/// set in FvAttributes.
comment|///
name|VOID
modifier|*
name|FvStart
decl_stmt|;
comment|///
comment|/// Size of the firmware volume.
comment|///
name|UINT64
name|FvSize
decl_stmt|;
block|}
name|EFI_FV_INFO
typedef|;
end_typedef

begin_comment
comment|/**   Returns information about the specified volume.    This function returns information about a specific firmware   volume, including its name, type, attributes, starting address   and size.    @param VolumeHandle   Handle of the volume.   @param VolumeInfo     Upon exit, points to the volume's information.    @retval EFI_SUCCESS             The volume information returned.   @retval EFI_INVALID_PARAMETER   If VolumeHandle does not represent a valid volume.   @retval EFI_INVALID_PARAMETER   If VolumeHandle is NULL.   @retval EFI_SUCCESS             Information was successfully returned.   @retval EFI_INVALID_PARAMETER   The volume designated by the VolumeHandle is not available.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FFS_GET_VOLUME_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_FV_HANDLE
name|VolumeHandle
parameter_list|,
name|OUT
name|EFI_FV_INFO
modifier|*
name|VolumeInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register a PEIM so that it will be shadowed and called again.    This service registers a file handle so that after memory is   available, the PEIM will be re-loaded into permanent memory and   re-initialized. The PEIM registered this way will always be   initialized twice. The first time, this function call will   return EFI_SUCCESS. The second time, this function call will   return EFI_ALREADY_STARTED. Depending on the order in which   PEIMs are dispatched, the PEIM making this call may be   initialized after permanent memory is installed, even the first   time.    @param  FileHandle            PEIM's file handle. Must be the currently                                 executing PEIM.      @retval EFI_SUCCESS           The PEIM was successfully registered for                                 shadowing.   @retval EFI_ALREADY_STARTED   The PEIM was previously                                 registered for shadowing.   @retval EFI_NOT_FOUND         The FileHandle does not refer to a                                 valid file handle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_REGISTER_FOR_SHADOW
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// PEI Specification Revision information
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PEI_SPECIFICATION_MAJOR_REVISION
value|1
end_define

begin_define
define|#
directive|define
name|PEI_SPECIFICATION_MINOR_REVISION
value|40
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specification inconsistency here:
end_comment

begin_comment
comment|/// In the PI1.0 spec, PEI_SERVICES_SIGNATURE is defined as 0x5652455320494550. But
end_comment

begin_comment
comment|/// to pass a multiple tool chain, it appends an ULL.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PEI Services Table
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PEI_SERVICES_SIGNATURE
value|0x5652455320494550ULL
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specification inconsistency here:
end_comment

begin_comment
comment|/// In the PI1.0 specification, there is a typo error in PEI_SERVICES_REVISION. In the specification the defintion is
end_comment

begin_comment
comment|/// #define ((PEI_SPECIFICATION_MAJOR_REVISION<<16) |(PEI_SPECIFICATION_MINOR_REVISION))
end_comment

begin_comment
comment|/// and it should be as follows:
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PEI_SERVICES_REVISION
value|((PEI_SPECIFICATION_MAJOR_REVISION<<16) | (PEI_SPECIFICATION_MINOR_REVISION))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PEI_SERVICES is a collection of functions whose implementation is provided by the PEI
end_comment

begin_comment
comment|/// Foundation. These services fall into various classes, including the following:
end_comment

begin_comment
comment|/// - Managing the boot mode
end_comment

begin_comment
comment|/// - Allocating both early and permanent memory
end_comment

begin_comment
comment|/// - Supporting the Firmware File System (FFS)
end_comment

begin_comment
comment|/// - Abstracting the PPI database abstraction
end_comment

begin_comment
comment|/// - Creating Hand-Off Blocks (HOBs).
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_SERVICES
block|{
comment|///
comment|/// The table header for the PEI Services Table.
comment|///
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|//
comment|// PPI Functions
comment|//
name|EFI_PEI_INSTALL_PPI
name|InstallPpi
decl_stmt|;
name|EFI_PEI_REINSTALL_PPI
name|ReInstallPpi
decl_stmt|;
name|EFI_PEI_LOCATE_PPI
name|LocatePpi
decl_stmt|;
name|EFI_PEI_NOTIFY_PPI
name|NotifyPpi
decl_stmt|;
comment|//
comment|// Boot Mode Functions
comment|//
name|EFI_PEI_GET_BOOT_MODE
name|GetBootMode
decl_stmt|;
name|EFI_PEI_SET_BOOT_MODE
name|SetBootMode
decl_stmt|;
comment|//
comment|// HOB Functions
comment|//
name|EFI_PEI_GET_HOB_LIST
name|GetHobList
decl_stmt|;
name|EFI_PEI_CREATE_HOB
name|CreateHob
decl_stmt|;
comment|//
comment|// Firmware Volume Functions
comment|//
name|EFI_PEI_FFS_FIND_NEXT_VOLUME2
name|FfsFindNextVolume
decl_stmt|;
name|EFI_PEI_FFS_FIND_NEXT_FILE2
name|FfsFindNextFile
decl_stmt|;
name|EFI_PEI_FFS_FIND_SECTION_DATA2
name|FfsFindSectionData
decl_stmt|;
comment|//
comment|// PEI Memory Functions
comment|//
name|EFI_PEI_INSTALL_PEI_MEMORY
name|InstallPeiMemory
decl_stmt|;
name|EFI_PEI_ALLOCATE_PAGES
name|AllocatePages
decl_stmt|;
name|EFI_PEI_ALLOCATE_POOL
name|AllocatePool
decl_stmt|;
name|EFI_PEI_COPY_MEM
name|CopyMem
decl_stmt|;
name|EFI_PEI_SET_MEM
name|SetMem
decl_stmt|;
comment|//
comment|// Status Code
comment|//
name|EFI_PEI_REPORT_STATUS_CODE
name|ReportStatusCode
decl_stmt|;
comment|//
comment|// Reset
comment|//
name|EFI_PEI_RESET_SYSTEM
name|ResetSystem
decl_stmt|;
comment|//
comment|// (the following interfaces are installed by publishing PEIM)
comment|// I/O Abstractions
comment|//
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|CpuIo
decl_stmt|;
name|EFI_PEI_PCI_CFG2_PPI
modifier|*
name|PciCfg
decl_stmt|;
comment|//
comment|// Future Installed Services
comment|//
name|EFI_PEI_FFS_FIND_BY_NAME
name|FfsFindFileByName
decl_stmt|;
name|EFI_PEI_FFS_GET_FILE_INFO
name|FfsGetFileInfo
decl_stmt|;
name|EFI_PEI_FFS_GET_VOLUME_INFO
name|FfsGetVolumeInfo
decl_stmt|;
name|EFI_PEI_REGISTER_FOR_SHADOW
name|RegisterForShadow
decl_stmt|;
name|EFI_PEI_FFS_FIND_SECTION_DATA3
name|FindSectionData3
decl_stmt|;
name|EFI_PEI_FFS_GET_FILE_INFO2
name|FfsGetFileInfo2
decl_stmt|;
name|EFI_PEI_RESET2_SYSTEM
name|ResetSystem2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SEC_PEI_HAND_OFF structure holds information about
end_comment

begin_comment
comment|/// PEI core's operating environment, such as the size of location of
end_comment

begin_comment
comment|/// temporary RAM, the stack location and BFV location.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SEC_PEI_HAND_OFF
block|{
comment|///
comment|/// Size of the data structure.
comment|///
name|UINT16
name|DataSize
decl_stmt|;
comment|///
comment|/// Points to the first byte of the boot firmware volume,
comment|/// which the PEI Dispatcher should search for
comment|/// PEI modules.
comment|///
name|VOID
modifier|*
name|BootFirmwareVolumeBase
decl_stmt|;
comment|///
comment|/// Size of the boot firmware volume, in bytes.
comment|///
name|UINTN
name|BootFirmwareVolumeSize
decl_stmt|;
comment|///
comment|/// Points to the first byte of the temporary RAM.
comment|///
name|VOID
modifier|*
name|TemporaryRamBase
decl_stmt|;
comment|///
comment|/// Size of the temporary RAM, in bytes.
comment|///
name|UINTN
name|TemporaryRamSize
decl_stmt|;
comment|///
comment|/// Points to the first byte of the temporary RAM
comment|/// available for use by the PEI Foundation. The area
comment|/// described by PeiTemporaryRamBase and PeiTemporaryRamSize
comment|/// must not extend outside beyond the area described by
comment|/// TemporaryRamBase& TemporaryRamSize. This area should not
comment|/// overlap with the area reported by StackBase and
comment|/// StackSize.
comment|///
name|VOID
modifier|*
name|PeiTemporaryRamBase
decl_stmt|;
comment|///
comment|/// The size of the available temporary RAM available for
comment|/// use by the PEI Foundation, in bytes.
comment|///
name|UINTN
name|PeiTemporaryRamSize
decl_stmt|;
comment|///
comment|/// Points to the first byte of the stack.
comment|/// This are may be part of the memory described by
comment|/// TemporaryRamBase and TemporaryRamSize
comment|/// or may be an entirely separate area.
comment|///
name|VOID
modifier|*
name|StackBase
decl_stmt|;
comment|///
comment|/// Size of the stack, in bytes.
comment|///
name|UINTN
name|StackSize
decl_stmt|;
block|}
name|EFI_SEC_PEI_HAND_OFF
typedef|;
end_typedef

begin_comment
comment|/**   The entry point of PEI Foundation.    This function is the entry point for the PEI Foundation, which   allows the SEC phase to pass information about the stack,   temporary RAM and the Boot Firmware Volume. In addition, it also   allows the SEC phase to pass services and data forward for use   during the PEI phase in the form of one or more PPIs. There is   no limit to the number of additional PPIs that can be passed   from SEC into the PEI Foundation. As part of its initialization   phase, the PEI Foundation will add these SEC-hosted PPIs to its   PPI database such that both the PEI Foundation and any modules   can leverage the associated service calls and/or code in these   early PPIs.    @param SecCoreData    Points to a data structure containing                         information about the PEI core's                         operating environment, such as the size                         and location of temporary RAM, the stack                         location and the BFV location.    @param PpiList        Points to a list of one or more PPI                         descriptors to be installed initially by                         the PEI core. An empty PPI list consists                         of a single descriptor with the end-tag                         EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST.                         As part of its initialization phase, the                         PEI Foundation will add these SEC-hosted                         PPIs to its PPI database such that both                         the PEI Foundation and any modules can                         leverage the associated service calls                         and/or code in these early PPIs.   **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CORE_ENTRY_POINT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SEC_PEI_HAND_OFF
modifier|*
name|SecCoreData
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_PPI_DESCRIPTOR
modifier|*
name|PpiList
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

