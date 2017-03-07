begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides library functions for all PEI Services.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_SERVICES_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_SERVICES_LIB_H__
end_define

begin_comment
comment|/**   This service enables a given PEIM to register an interface into the PEI Foundation.    @param  PpiList               A pointer to the list of interfaces that the caller shall install.    @retval EFI_SUCCESS           The interface was successfully installed.   @retval EFI_INVALID_PARAMETER The PpiList pointer is NULL.   @retval EFI_INVALID_PARAMETER Any of the PEI PPI descriptors in the list do not have the                                 EFI_PEI_PPI_DESCRIPTOR_PPI bit set in the Flags field.   @retval EFI_OUT_OF_RESOURCES  There is no additional space in the PPI database.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesInstallPpi
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_PPI_DESCRIPTOR
modifier|*
name|PpiList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to replace an entry in the PPI database with an alternate entry.    @param  OldPpi                Pointer to the old PEI PPI Descriptors.   @param  NewPpi                Pointer to the new PEI PPI Descriptors.    @retval EFI_SUCCESS           The interface was successfully installed.   @retval EFI_INVALID_PARAMETER The OldPpi or NewPpi is NULL.   @retval EFI_INVALID_PARAMETER Any of the PEI PPI descriptors in the list do not have the                                 EFI_PEI_PPI_DESCRIPTOR_PPI bit set in the Flags field.   @retval EFI_OUT_OF_RESOURCES  There is no additional space in the PPI database.   @retval EFI_NOT_FOUND         The PPI for which the reinstallation was requested has not been                                 installed.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesReInstallPpi
parameter_list|(
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
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to discover a given instance of an interface.    @param  Guid                  A pointer to the GUID whose corresponding interface needs to be                                 found.   @param  Instance              The N-th instance of the interface that is required.   @param  PpiDescriptor         A pointer to instance of the EFI_PEI_PPI_DESCRIPTOR.   @param  Ppi                   A pointer to the instance of the interface.    @retval EFI_SUCCESS           The interface was successfully returned.   @retval EFI_NOT_FOUND         The PPI descriptor is not found in the database.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesLocatePpi
parameter_list|(
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
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|Ppi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to register a given service to be invoked when another service is   installed or reinstalled.    @param  NotifyList            A pointer to the list of notification interfaces that the caller                                 shall install.    @retval EFI_SUCCESS           The interface was successfully installed.   @retval EFI_INVALID_PARAMETER The NotifyList pointer is NULL.   @retval EFI_INVALID_PARAMETER Any of the PEI notify descriptors in the list do not have the                                 EFI_PEI_PPI_DESCRIPTOR_NOTIFY_TYPES bit set in the Flags field.   @retval EFI_OUT_OF_RESOURCES  There is no additional space in the PPI database.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesNotifyPpi
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_NOTIFY_DESCRIPTOR
modifier|*
name|NotifyList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to ascertain the present value of the boot mode.    @param  BootMode              A pointer to contain the value of the boot mode.    @retval EFI_SUCCESS           The boot mode was returned successfully.   @retval EFI_INVALID_PARAMETER BootMode is NULL.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesGetBootMode
parameter_list|(
name|OUT
name|EFI_BOOT_MODE
modifier|*
name|BootMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to update the boot mode variable.    @param  BootMode              The value of the boot mode to set.    @retval EFI_SUCCESS           The value was successfully updated  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesSetBootMode
parameter_list|(
name|IN
name|EFI_BOOT_MODE
name|BootMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables a PEIM to ascertain the address of the list of HOBs in memory.    @param  HobList               A pointer to the list of HOBs that the PEI Foundation will initialize.    @retval EFI_SUCCESS           The list was successfully returned.   @retval EFI_NOT_AVAILABLE_YET The HOB list is not yet published.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesGetHobList
parameter_list|(
name|OUT
name|VOID
modifier|*
modifier|*
name|HobList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to create various types of HOBs.    @param  Type                  The type of HOB to be installed.   @param  Length                The length of the HOB to be added.   @param  Hob                   The address of a pointer that will contain the HOB header.    @retval EFI_SUCCESS           The HOB was successfully created.   @retval EFI_OUT_OF_RESOURCES  There is no additional space for HOB creation.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesCreateHob
parameter_list|(
name|IN
name|UINT16
name|Type
parameter_list|,
name|IN
name|UINT16
name|Length
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Hob
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to discover additional firmware volumes.    @param  Instance              This instance of the firmware volume to find.  The value 0 is the                                 Boot Firmware Volume (BFV).   @param  VolumeHandle          Handle of the firmware volume header of the volume to return.    @retval EFI_SUCCESS           The volume was found.   @retval EFI_NOT_FOUND         The volume was not found.   @retval EFI_INVALID_PARAMETER FwVolHeader is NULL.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsFindNextVolume
parameter_list|(
name|IN
name|UINTN
name|Instance
parameter_list|,
name|IN
name|OUT
name|EFI_PEI_FV_HANDLE
modifier|*
name|VolumeHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to discover additional firmware files.    @param  SearchType            A filter to find files only of this type.   @param  VolumeHandle          Pointer to the firmware volume header of the volume to search.                                 This parameter must point to a valid FFS volume.   @param  FileHandle            Handle of the current file from which to begin searching.    @retval EFI_SUCCESS           The file was found.   @retval EFI_NOT_FOUND         The file was not found.   @retval EFI_NOT_FOUND         The header checksum was not zero.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsFindNextFile
parameter_list|(
name|IN
name|EFI_FV_FILETYPE
name|SearchType
parameter_list|,
name|IN
name|EFI_PEI_FV_HANDLE
name|VolumeHandle
parameter_list|,
name|IN
name|OUT
name|EFI_PEI_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to discover sections of a given type within a valid FFS file.    @param  SectionType           The value of the section type to find.   @param  FileHandle            A pointer to the file header that contains the set of sections to                                 be searched.   @param  SectionData           A pointer to the discovered section, if successful.    @retval EFI_SUCCESS           The section was found.   @retval EFI_NOT_FOUND         The section was not found.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsFindSectionData
parameter_list|(
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
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to discover sections of a given instance and type within a valid FFS file.    @param  SectionType           The value of the section type to find.   @param  SectionInstance       Section instance to find.   @param  FileHandle            A pointer to the file header that contains the set                                  of sections to be searched.   @param  SectionData           A pointer to the discovered section, if successful.   @param  AuthenticationStatus  A pointer to the authentication status for this section.    @retval EFI_SUCCESS           The section was found.   @retval EFI_NOT_FOUND         The section was not found.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsFindSectionData3
parameter_list|(
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
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to register the permanent memory configuration   that has been initialized with the PEI Foundation.    @param  MemoryBegin           The value of a region of installed memory.   @param  MemoryLength          The corresponding length of a region of installed memory.    @retval EFI_SUCCESS           The region was successfully installed in a HOB.   @retval EFI_INVALID_PARAMETER MemoryBegin and MemoryLength are illegal for this system.   @retval EFI_OUT_OF_RESOURCES  There is no additional space for HOB creation.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesInstallPeiMemory
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|MemoryBegin
parameter_list|,
name|IN
name|UINT64
name|MemoryLength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service enables PEIMs to allocate memory after the permanent memory has been installed by a   PEIM.    @param  MemoryType            Type of memory to allocate.   @param  Pages                 Number of pages to allocate.   @param  Memory                Pointer of memory allocated.    @retval EFI_SUCCESS           The memory range was successfully allocated.   @retval EFI_INVALID_PARAMETER Type is not equal to AllocateAnyPages.   @retval EFI_NOT_AVAILABLE_YET Called with permanent memory not available.   @retval EFI_OUT_OF_RESOURCES  The pages could not be allocated.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesAllocatePages
parameter_list|(
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
end_function_decl

begin_comment
comment|/**   This service allocates memory from the Hand-Off Block (HOB) heap.    @param  Size                  The number of bytes to allocate from the pool.   @param  Buffer                If the call succeeds, a pointer to a pointer to the allocate                                 buffer; undefined otherwise.    @retval EFI_SUCCESS           The allocation was successful   @retval EFI_OUT_OF_RESOURCES  There is not enough heap to allocate the requested size.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesAllocatePool
parameter_list|(
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
end_function_decl

begin_comment
comment|/**   Resets the entire platform.    @retval EFI_SUCCESS           The function completed successfully.   @retval EFI_NOT_AVAILABLE_YET The service has not been installed yet.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesResetSystem
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service is a wrapper for the PEI Service FfsFindByName(), except the pointer to the PEI Services    Table has been removed.  See the Platform Initialization Pre-EFI Initialization Core Interface    Specification for details.     @param FileName       A pointer to the name of the file to                         find within the firmware volume.    @param VolumeHandle   The firmware volume to search FileHandle                         Upon exit, points to the found file's                         handle or NULL if it could not be found.   @param FileHandle     Pointer to found file handle     @retval EFI_SUCCESS             File was found.    @retval EFI_NOT_FOUND           File was not found.    @retval EFI_INVALID_PARAMETER   VolumeHandle or FileHandle or                                   FileName was NULL.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsFindFileByName
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|FileName
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_FV_HANDLE
name|VolumeHandle
parameter_list|,
name|OUT
name|EFI_PEI_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service is a wrapper for the PEI Service FfsGetFileInfo(), except the pointer to the PEI Services    Table has been removed.  See the Platform Initialization Pre-EFI Initialization Core Interface    Specification for details.     @param FileHandle   Handle of the file.    @param FileInfo     Upon exit, points to the file's                       information.    @retval EFI_SUCCESS             File information returned.      @retval EFI_INVALID_PARAMETER   If FileHandle does not                                   represent a valid file.      @retval EFI_INVALID_PARAMETER   If FileInfo is NULL.    **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsGetFileInfo
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|EFI_FV_FILE_INFO
modifier|*
name|FileInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service is a wrapper for the PEI Service FfsGetFileInfo2(), except the pointer to the PEI Services   Table has been removed. See the Platform Initialization Pre-EFI Initialization Core Interface   Specification for details.    @param FileHandle   Handle of the file.    @param FileInfo     Upon exit, points to the file's                       information.    @retval EFI_SUCCESS             File information returned.      @retval EFI_INVALID_PARAMETER   If FileHandle does not                                   represent a valid file.      @retval EFI_INVALID_PARAMETER   If FileInfo is NULL.    **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsGetFileInfo2
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|EFI_FV_FILE_INFO2
modifier|*
name|FileInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This service is a wrapper for the PEI Service FfsGetVolumeInfo(), except the pointer to the PEI Services    Table has been removed.  See the Platform Initialization Pre-EFI Initialization Core Interface    Specification for details.     @param VolumeHandle   Handle of the volume.    @param VolumeInfo     Upon exit, points to the volume's                         information.    @retval EFI_SUCCESS             File information returned.      @retval EFI_INVALID_PARAMETER   If FileHandle does not                                   represent a valid file.      @retval EFI_INVALID_PARAMETER   If FileInfo is NULL.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesFfsGetVolumeInfo
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
end_function_decl

begin_comment
comment|/**   This service is a wrapper for the PEI Service RegisterForShadow(), except the pointer to the PEI Services    Table has been removed.  See the Platform Initialization Pre-EFI Initialization Core Interface    Specification for details.     @param FileHandle   PEIM's file handle. Must be the currently                       executing PEIM.      @retval EFI_SUCCESS   The PEIM was successfully registered for                         shadowing.    @retval EFI_ALREADY_STARTED   The PEIM was previously                                 registered for shadowing.    @retval EFI_NOT_FOUND   The FileHandle does not refer to a                           valid file handle. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|PeiServicesRegisterForShadow
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Install a EFI_PEI_FIRMWARE_VOLUME_INFO_PPI instance so the PEI Core will be notified about a new firmware volume.      This function allocates, initializes, and installs a new EFI_PEI_FIRMWARE_VOLUME_INFO_PPI using    the parameters passed in to initialize the fields of the EFI_PEI_FIRMWARE_VOLUME_INFO_PPI instance.   If the resources can not be allocated for EFI_PEI_FIRMWARE_VOLUME_INFO_PPI, then ASSERT().   If the EFI_PEI_FIRMWARE_VOLUME_INFO_PPI can not be installed, then ASSERT().       @param  FvFormat             Unique identifier of the format of the memory-mapped firmware volume.                                This parameter is optional and may be NULL.                                  If NULL is specified, the EFI_FIRMWARE_FILE_SYSTEM2_GUID format is assumed.   @param  FvInfo               Points to a buffer which allows the EFI_PEI_FIRMWARE_VOLUME_PPI to process the volume.                                 The format of this buffer is specific to the FvFormat. For memory-mapped firmware volumes,                                 this typically points to the first byte of the firmware volume.   @param  FvInfoSize           The size, in bytes, of FvInfo. For memory-mapped firmware volumes,                                 this is typically the size of the firmware volume.   @param  ParentFvName         If the new firmware volume originated from a file in a different firmware volume,                                 then this parameter specifies the GUID name of the originating firmware volume.                                Otherwise, this parameter must be NULL.   @param  ParentFileName       If the new firmware volume originated from a file in a different firmware volume,                                 then this parameter specifies the GUID file name of the originating firmware file.                                Otherwise, this parameter must be NULL. **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|PeiServicesInstallFvInfoPpi
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|FvFormat
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|VOID
modifier|*
name|FvInfo
parameter_list|,
name|IN
name|UINT32
name|FvInfoSize
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|ParentFvName
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|ParentFileName
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Install a EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI instance so the PEI Core will be notified about a new firmware volume.    This function allocates, initializes, and installs a new EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI using   the parameters passed in to initialize the fields of the EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI instance.   If the resources can not be allocated for EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI, then ASSERT().   If the EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI can not be installed, then ASSERT().    @param  FvFormat             Unique identifier of the format of the memory-mapped                                firmware volume.  This parameter is optional and                                may be NULL.  If NULL is specified, the                                EFI_FIRMWARE_FILE_SYSTEM2_GUID format is assumed.   @param  FvInfo               Points to a buffer which allows the                                EFI_PEI_FIRMWARE_VOLUME_PPI to process the volume.                                The format of this buffer is specific to the FvFormat.                                For memory-mapped firmware volumes, this typically                                points to the first byte of the firmware volume.   @param  FvInfoSize           The size, in bytes, of FvInfo. For memory-mapped                                firmware volumes, this is typically the size of                                the firmware volume.   @param  ParentFvName         If the new firmware volume originated from a file                                in a different firmware volume, then this parameter                                specifies the GUID name of the originating firmware                                volume. Otherwise, this parameter must be NULL.   @param  ParentFileName       If the new firmware volume originated from a file                                in a different firmware volume, then this parameter                                specifies the GUID file name of the originating                                firmware file. Otherwise, this parameter must be NULL.   @param  AuthenticationStatus Authentication Status **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|PeiServicesInstallFvInfo2Ppi
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|FvFormat
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|VOID
modifier|*
name|FvInfo
parameter_list|,
name|IN
name|UINT32
name|FvInfoSize
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|ParentFvName
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|ParentFileName
parameter_list|,
name|OPTIONAL
name|IN
name|UINT32
name|AuthenticationStatus
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

