begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file provides functions for accessing a memory-mapped firmware volume of a specific format.    Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is from PI Version 1.0 errata.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FIRMWARE_VOLUME_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__FIRMWARE_VOLUME_PPI_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The GUID for this PPI is the same as the firmware volume format GUID.
end_comment

begin_comment
comment|/// The FV format can be EFI_FIRMWARE_FILE_SYSTEM2_GUID or the GUID for a user-defined
end_comment

begin_comment
comment|/// format. The EFI_FIRMWARE_FILE_SYSTEM2_GUID is the PI Firmware Volume format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_FIRMWARE_VOLUME_PPI
name|EFI_PEI_FIRMWARE_VOLUME_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Process a firmware volume and create a volume handle.    Create a volume handle from the information in the buffer. For   memory-mapped firmware volumes, Buffer and BufferSize refer to   the start of the firmware volume and the firmware volume size.   For non memory-mapped firmware volumes, this points to a   buffer which contains the necessary information for creating   the firmware volume handle. Normally, these values are derived   from the EFI_FIRMWARE_VOLUME_INFO_PPI.         @param This                   Points to this instance of the                                 EFI_PEI_FIRMWARE_VOLUME_PPI.   @param Buffer                 Points to the start of the buffer.   @param BufferSize             Size of the buffer.   @param FvHandle               Points to the returned firmware volume                                 handle. The firmware volume handle must                                 be unique within the system.     @retval EFI_SUCCESS           Firmware volume handle created.   @retval EFI_VOLUME_CORRUPTED  Volume was corrupt.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_PROCESS_FV
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|OUT
name|EFI_PEI_FV_HANDLE
modifier|*
name|FvHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Finds the next file of the specified type.    This service enables PEI modules to discover additional firmware files.    The FileHandle must be unique within the system.    @param This           Points to this instance of the                         EFI_PEI_FIRMWARE_VOLUME_PPI.   @param SearchType     A filter to find only files of this type. Type                         EFI_FV_FILETYPE_ALL causes no filtering to be                         done.   @param FvHandle       Handle of firmware volume in which to                         search.   @param FileHandle     Points to the current handle from which to                         begin searching or NULL to start at the                         beginning of the firmware volume. Updated                         upon return to reflect the file found.    @retval EFI_SUCCESS   The file was found.   @retval EFI_NOT_FOUND The file was not found. FileHandle contains NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_FIND_FILE_TYPE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FV_FILETYPE
name|SearchType
parameter_list|,
name|IN
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
comment|/**   Find a file within a volume by its name.       This service searches for files with a specific name, within   either the specified firmware volume or all firmware volumes.    @param This                   Points to this instance of the                                 EFI_PEI_FIRMWARE_VOLUME_PPI.   @param FileName               A pointer to the name of the file to find                                 within the firmware volume.   @param FvHandle               Upon entry, the pointer to the firmware                                 volume to search or NULL if all firmware                                 volumes should be searched. Upon exit, the                                 actual firmware volume in which the file was                                 found.   @param FileHandle             Upon exit, points to the found file's                                 handle or NULL if it could not be found.    @retval EFI_SUCCESS           File was found.   @retval EFI_NOT_FOUND         File was not found.   @retval EFI_INVALID_PARAMETER FvHandle or FileHandle or                                 FileName was NULL.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_FIND_FILE_NAME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|FileName
parameter_list|,
name|IN
name|EFI_PEI_FV_HANDLE
modifier|*
name|FvHandle
parameter_list|,
name|OUT
name|EFI_PEI_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns information about a specific file.    This function returns information about a specific   file, including its file name, type, attributes, starting   address and size.        @param This                     Points to this instance of the                                   EFI_PEI_FIRMWARE_VOLUME_PPI.   @param FileHandle               Handle of the file.   @param FileInfo                 Upon exit, points to the file's                                   information.    @retval EFI_SUCCESS             File information returned.   @retval EFI_INVALID_PARAMETER   If FileHandle does not                                   represent a valid file.   @retval EFI_INVALID_PARAMETER   If FileInfo is NULL.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_GET_FILE_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
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
comment|/**   Returns information about a specific file.    This function returns information about a specific   file, including its file name, type, attributes, starting   address, size and authentication status.     @param This                     Points to this instance of the                                   EFI_PEI_FIRMWARE_VOLUME_PPI.   @param FileHandle               Handle of the file.   @param FileInfo                 Upon exit, points to the file's                                   information.    @retval EFI_SUCCESS             File information returned.   @retval EFI_INVALID_PARAMETER   If FileHandle does not                                   represent a valid file.   @retval EFI_INVALID_PARAMETER   If FileInfo is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_GET_FILE_INFO2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
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
comment|/**   This function returns information about the firmware volume.      @param This                     Points to this instance of the                                   EFI_PEI_FIRMWARE_VOLUME_PPI.   @param FvHandle                 Handle to the firmware handle.   @param VolumeInfo               Points to the returned firmware volume                                   information.    @retval EFI_SUCCESS             Information returned successfully.   @retval EFI_INVALID_PARAMETER   FvHandle does not indicate a valid                                   firmware volume or VolumeInfo is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PEI_FV_HANDLE
name|FvHandle
parameter_list|,
name|OUT
name|EFI_FV_INFO
modifier|*
name|VolumeInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Find the next matching section in the firmware file.      This service enables PEI modules to discover sections   of a given type within a valid file.      @param This             Points to this instance of the                           EFI_PEI_FIRMWARE_VOLUME_PPI.   @param SearchType       A filter to find only sections of this                           type.   @param FileHandle       Handle of firmware file in which to                           search.   @param SectionData      Updated upon  return to point to the                           section found.      @retval EFI_SUCCESS     Section was found.   @retval EFI_NOT_FOUND   Section of the specified type was not                           found. SectionData contains NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_FIND_SECTION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SECTION_TYPE
name|SearchType
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
comment|/**   Find the next matching section in the firmware file.    This service enables PEI modules to discover sections   of a given instance and type within a valid file.    @param This                   Points to this instance of the                                 EFI_PEI_FIRMWARE_VOLUME_PPI.   @param SearchType             A filter to find only sections of this                                 type.   @param SearchInstance         A filter to find the specific instance                                 of sections.   @param FileHandle             Handle of firmware file in which to                                 search.   @param SectionData            Updated upon return to point to the                                 section found.   @param AuthenticationStatus   Updated upon return to point to the                                 authentication status for this section.    @retval EFI_SUCCESS     Section was found.   @retval EFI_NOT_FOUND   Section of the specified type was not                           found. SectionData contains NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_FV_FIND_SECTION2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_FIRMWARE_VOLUME_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SECTION_TYPE
name|SearchType
parameter_list|,
name|IN
name|UINTN
name|SearchInstance
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

begin_define
define|#
directive|define
name|EFI_PEI_FIRMWARE_VOLUME_PPI_SIGNATURE
value|SIGNATURE_32 ('P', 'F', 'V', 'P')
end_define

begin_define
define|#
directive|define
name|EFI_PEI_FIRMWARE_VOLUME_PPI_REVISION
value|0x00010030
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI provides functions for accessing a memory-mapped firmware volume of a specific format.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_FIRMWARE_VOLUME_PPI
block|{
name|EFI_PEI_FV_PROCESS_FV
name|ProcessVolume
decl_stmt|;
name|EFI_PEI_FV_FIND_FILE_TYPE
name|FindFileByType
decl_stmt|;
name|EFI_PEI_FV_FIND_FILE_NAME
name|FindFileByName
decl_stmt|;
name|EFI_PEI_FV_GET_FILE_INFO
name|GetFileInfo
decl_stmt|;
name|EFI_PEI_FV_GET_INFO
name|GetVolumeInfo
decl_stmt|;
name|EFI_PEI_FV_FIND_SECTION
name|FindSectionByType
decl_stmt|;
name|EFI_PEI_FV_GET_FILE_INFO2
name|GetFileInfo2
decl_stmt|;
name|EFI_PEI_FV_FIND_SECTION2
name|FindSectionByType2
decl_stmt|;
comment|///
comment|/// Signature is used to keep backward-compatibility, set to {'P','F','V','P'}.
comment|///
name|UINT32
name|Signature
decl_stmt|;
comment|///
comment|/// Revision for further extension.
comment|///
name|UINT32
name|Revision
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiFirmwareVolumePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

