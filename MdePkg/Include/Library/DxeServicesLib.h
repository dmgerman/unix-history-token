begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   MDE DXE Services Library provides functions that simplify the development of DXE Drivers.     These functions help access data from sections of FFS files or from file path.  Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR> (C) Copyright 2015 Hewlett Packard Enterprise Development LP<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                             THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DXE_SERVICES_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__DXE_SERVICES_LIB_H__
end_define

begin_comment
comment|/**   Searches all the available firmware volumes and returns the first matching FFS section.     This function searches all the firmware volumes for FFS files with FV file type specified by FileType   The order that the firmware volumes is searched is not deterministic. For each available FV a search    is made for FFS file of type FileType. If the FV contains more than one FFS file with the same FileType,    the FileInstance instance will be the matched FFS file. For each FFS file found a search    is made for FFS sections of type SectionType. If the FFS file contains at least SectionInstance instances    of the FFS section specified by SectionType, then the SectionInstance instance is returned in Buffer.    Buffer is allocated using AllocatePool(), and the size of the allocated buffer is returned in Size.    It is the caller's responsibility to use FreePool() to free the allocated buffer.     See EFI_FIRMWARE_VOLUME2_PROTOCOL.ReadSection() for details on how sections    are retrieved from an FFS file based on SectionType and SectionInstance.    If SectionType is EFI_SECTION_TE, and the search with an FFS file fails,    the search will be retried with a section type of EFI_SECTION_PE32.   This function must be called with a TPL<= TPL_NOTIFY.    If Buffer is NULL, then ASSERT().   If Size is NULL, then ASSERT().    @param  FileType             Indicates the FV file type to search for within all available FVs.   @param  FileInstance         Indicates which file instance within all available FVs specified by FileType.                                FileInstance starts from zero.   @param  SectionType          Indicates the FFS section type to search for within the FFS file                                 specified by FileType with FileInstance.   @param  SectionInstance      Indicates which section instance within the FFS file                                 specified by FileType with FileInstance to retrieve. SectionInstance starts from zero.   @param  Buffer               On output, a pointer to a callee allocated buffer containing the FFS file section that was found.                                Is it the caller's responsibility to free this buffer using FreePool().   @param  Size                 On output, a pointer to the size, in bytes, of Buffer.    @retval  EFI_SUCCESS          The specified FFS section was returned.   @retval  EFI_NOT_FOUND        The specified FFS section could not be found.   @retval  EFI_OUT_OF_RESOURCES There are not enough resources available to retrieve the matching FFS section.   @retval  EFI_DEVICE_ERROR     The FFS section could not be retrieves due to a device error.   @retval  EFI_ACCESS_DENIED    The FFS section could not be retrieves because the firmware volume that                                  contains the matching FFS section does not allow reads. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|GetSectionFromAnyFvByFileType
parameter_list|(
name|IN
name|EFI_FV_FILETYPE
name|FileType
parameter_list|,
name|IN
name|UINTN
name|FileInstance
parameter_list|,
name|IN
name|EFI_SECTION_TYPE
name|SectionType
parameter_list|,
name|IN
name|UINTN
name|SectionInstance
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Searches all the available firmware volumes and returns the first matching FFS section.     This function searches all the firmware volumes for FFS files with an FFS filename specified by NameGuid.     The order in which the firmware volumes are searched is not deterministic. For each FFS file found, a search    is made for FFS sections of type SectionType. If the FFS file contains at least SectionInstance instances    of the FFS section specified by SectionType, then the SectionInstance instance is returned in Buffer.    Buffer is allocated using AllocatePool(), and the size of the allocated buffer is returned in Size.    It is the caller's responsibility to use FreePool() to free the allocated buffer.     See EFI_FIRMWARE_VOLUME2_PROTOCOL.ReadSection() for details on how sections    are retrieved from an FFS file based on SectionType and SectionInstance.    If SectionType is EFI_SECTION_TE, and the search with an FFS file fails,    the search will be retried with a section type of EFI_SECTION_PE32.   This function must be called with a TPL<= TPL_NOTIFY.    If NameGuid is NULL, then ASSERT().   If Buffer is NULL, then ASSERT().   If Size is NULL, then ASSERT().     @param  NameGuid             A pointer to to the FFS filename GUID to search for                                  within any of the firmware volumes in the platform.    @param  SectionType          Indicates the FFS section type to search for within                                 the FFS file specified by NameGuid.   @param  SectionInstance      Indicates which section instance within the FFS file                                 specified by NameGuid to retrieve.   @param  Buffer               On output, a pointer to a callee-allocated buffer                                 containing the FFS file section that was found.                                  It is the caller's responsibility to free this                                 buffer using FreePool().   @param  Size                 On output, a pointer to the size, in bytes, of Buffer.    @retval  EFI_SUCCESS          The specified FFS section was returned.   @retval  EFI_NOT_FOUND        The specified FFS section could not be found.   @retval  EFI_OUT_OF_RESOURCES There are not enough resources available to retrieve                                  the matching FFS section.   @retval  EFI_DEVICE_ERROR     The FFS section could not be retrieves due to a                                  device error.   @retval  EFI_ACCESS_DENIED    The FFS section could not be retrieves because the                                  firmware volume that contains the matching FFS                                  section does not allow reads. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|GetSectionFromAnyFv
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|NameGuid
parameter_list|,
name|IN
name|EFI_SECTION_TYPE
name|SectionType
parameter_list|,
name|IN
name|UINTN
name|SectionInstance
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Searches the firmware volume that the currently executing module was loaded from and returns the first matching FFS section.     This function searches the firmware volume that the currently executing module was loaded    from for an FFS file with an FFS filename specified by NameGuid. If the FFS file is found, a search    is made for FFS sections of type SectionType. If the FFS file contains at least SectionInstance    instances of the FFS section specified by SectionType, then the SectionInstance instance is returned in Buffer.   Buffer is allocated using AllocatePool(), and the size of the allocated buffer is returned in Size.    It is the caller's responsibility to use FreePool() to free the allocated buffer.    See EFI_FIRMWARE_VOLUME2_PROTOCOL.ReadSection() for details on how sections are retrieved from    an FFS file based on SectionType and SectionInstance.    If the currently executing module was not loaded from a firmware volume, then EFI_NOT_FOUND is returned.   If SectionType is EFI_SECTION_TE, and the search with an FFS file fails,    the search will be retried with a section type of EFI_SECTION_PE32.      This function must be called with a TPL<= TPL_NOTIFY.   If NameGuid is NULL, then ASSERT().   If Buffer is NULL, then ASSERT().   If Size is NULL, then ASSERT().    @param  NameGuid             A pointer to to the FFS filename GUID to search for                                  within the firmware volumes that the currently                                 executing module was loaded from.   @param  SectionType          Indicates the FFS section type to search for within                                 the FFS file specified by NameGuid.   @param  SectionInstance      Indicates which section instance within the FFS                                 file specified by NameGuid to retrieve.   @param  Buffer               On output, a pointer to a callee allocated buffer                                 containing the FFS file section that was found.                                  It is the caller's responsibility to free this buffer                                 using FreePool().   @param  Size                 On output, a pointer to the size, in bytes, of Buffer.     @retval  EFI_SUCCESS          The specified FFS section was returned.   @retval  EFI_NOT_FOUND        The specified FFS section could not be found.   @retval  EFI_OUT_OF_RESOURCES There are not enough resources available to retrieve                                  the matching FFS section.   @retval  EFI_DEVICE_ERROR     The FFS section could not be retrieves due to a                                  device error.   @retval  EFI_ACCESS_DENIED    The FFS section could not be retrieves because the                                  firmware volume that contains the matching FFS                                  section does not allow reads.   **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|GetSectionFromFv
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|NameGuid
parameter_list|,
name|IN
name|EFI_SECTION_TYPE
name|SectionType
parameter_list|,
name|IN
name|UINTN
name|SectionInstance
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Searches the FFS file the the currently executing module was loaded from and returns the first matching FFS section.    This function searches the FFS file that the currently executing module was loaded from for a FFS sections of type SectionType.   If the FFS file contains at least SectionInstance instances of the FFS section specified by SectionType,    then the SectionInstance instance is returned in Buffer. Buffer is allocated using AllocatePool(),    and the size of the allocated buffer is returned in Size. It is the caller's responsibility    to use FreePool() to free the allocated buffer. See EFI_FIRMWARE_VOLUME2_PROTOCOL.ReadSection() for    details on how sections are retrieved from an FFS file based on SectionType and SectionInstance.    If the currently executing module was not loaded from an FFS file, then EFI_NOT_FOUND is returned.   If SectionType is EFI_SECTION_TE, and the search with an FFS file fails,    the search will be retried with a section type of EFI_SECTION_PE32.   This function must be called with a TPL<= TPL_NOTIFY.      If Buffer is NULL, then ASSERT().   If Size is NULL, then ASSERT().     @param  SectionType          Indicates the FFS section type to search for within                                  the FFS file that the currently executing module                                 was loaded from.   @param  SectionInstance      Indicates which section instance to retrieve within                                 the FFS file that the currently executing module                                 was loaded from.   @param  Buffer               On output, a pointer to a callee allocated buffer                                 containing the FFS file section that was found.                                  It is the caller's responsibility to free this buffer                                 using FreePool().   @param  Size                 On output, a pointer to the size, in bytes, of Buffer.    @retval  EFI_SUCCESS          The specified FFS section was returned.   @retval  EFI_NOT_FOUND        The specified FFS section could not be found.   @retval  EFI_OUT_OF_RESOURCES There are not enough resources available to retrieve                                  the matching FFS section.   @retval  EFI_DEVICE_ERROR     The FFS section could not be retrieves due to a                                  device error.   @retval  EFI_ACCESS_DENIED    The FFS section could not be retrieves because the                                  firmware volume that contains the matching FFS                                  section does not allow reads.      **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|GetSectionFromFfs
parameter_list|(
name|IN
name|EFI_SECTION_TYPE
name|SectionType
parameter_list|,
name|IN
name|UINTN
name|SectionInstance
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the image file buffer data and buffer size by its device path.       Access the file either from a firmware volume, from a file system interface,    or from the load file interface.      Allocate memory to store the found image. The caller is responsible to free memory.    If FilePath is NULL, then NULL is returned.   If FileSize is NULL, then NULL is returned.   If AuthenticationStatus is NULL, then NULL is returned.    @param[in]       BootPolicy           The policy for Open Image File.If TRUE,                                          indicates that the request originates from                                          the boot manager, and that the boot manager is                                         attempting to load FilePath as a boot selection.                                          If FALSE, then FilePath must match an exact                                          file to be loaded.   @param[in]       FilePath             Pointer to the device path of the file that is abstracted to                                         the file buffer.   @param[out]      FileSize             Pointer to the size of the abstracted file buffer.   @param[out]      AuthenticationStatus Pointer to the authentication status.    @retval NULL   FilePath is NULL, or FileSize is NULL, or AuthenticationStatus is NULL, or the file can't be found.   @retval other  The abstracted file buffer. The caller is responsible to free memory. **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|GetFileBufferByFilePath
parameter_list|(
name|IN
name|BOOLEAN
name|BootPolicy
parameter_list|,
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|FilePath
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|FileSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|AuthenticationStatus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Searches all the available firmware volumes and returns the file device path of first matching   FFS section.    This function searches all the firmware volumes for FFS files with an FFS filename specified by NameGuid.   The order that the firmware volumes is searched is not deterministic. For each FFS file found a search   is made for FFS sections of type SectionType.    If SectionType is EFI_SECTION_TE, and the search with an FFS file fails,   the search will be retried with a section type of EFI_SECTION_PE32.   This function must be called with a TPL<= TPL_NOTIFY.    If NameGuid is NULL, then ASSERT().     @param  NameGuid             A pointer to to the FFS filename GUID to search for                                 within any of the firmware volumes in the platform.    @param  SectionType          Indicates the FFS section type to search for within                                 the FFS file specified by NameGuid.    @param  SectionInstance      Indicates which section instance within the FFS file                                 specified by NameGuid to retrieve.    @param  FvFileDevicePath     Device path for the target FFS                                 file.     @retval  EFI_SUCCESS           The specified file device path of FFS section was returned.    @retval  EFI_NOT_FOUND         The specified file device path of FFS section could not be found.    @retval  EFI_DEVICE_ERROR      The FFS section could not be retrieves due to a                                   device error.    @retval  EFI_ACCESS_DENIED     The FFS section could not be retrieves because the                                   firmware volume that contains the matching FFS section does not                                   allow reads.    @retval  EFI_INVALID_PARAMETER FvFileDevicePath is NULL.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|GetFileDevicePathFromAnyFv
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|NameGuid
parameter_list|,
name|IN
name|EFI_SECTION_TYPE
name|SectionType
parameter_list|,
name|IN
name|UINTN
name|SectionInstance
parameter_list|,
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|FvFileDevicePath
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

