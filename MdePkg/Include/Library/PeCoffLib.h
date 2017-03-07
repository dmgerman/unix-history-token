begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to load and relocate a PE/COFF image.    The PE/COFF Loader Library abstracts the implementation of a PE/COFF loader for   IA-32, x86, IPF, and EBC processor types. The library functions are memory-based    and can be ported easily to any environment.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BASE_PE_COFF_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__BASE_PE_COFF_LIB_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/PeImage.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Return status codes from the PE/COFF Loader services
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_ERROR_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_IMAGE_READ
value|1
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_INVALID_PE_HEADER_SIGNATURE
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_INVALID_MACHINE_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_INVALID_SUBSYSTEM
value|4
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_INVALID_IMAGE_ADDRESS
value|5
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_INVALID_IMAGE_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_INVALID_SECTION_ALIGNMENT
value|7
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_SECTION_NOT_LOADED
value|8
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_FAILED_RELOCATION
value|9
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_FAILED_ICACHE_FLUSH
value|10
end_define

begin_define
define|#
directive|define
name|IMAGE_ERROR_UNSUPPORTED
value|11
end_define

begin_comment
comment|/**   Reads contents of a PE/COFF image.    A function of this type reads contents of the PE/COFF image specified by FileHandle. The read    operation copies ReadSize bytes from the PE/COFF image starting at byte offset FileOffset into    the buffer specified by Buffer. The size of the buffer actually read is returned in ReadSize.     If FileOffset specifies an offset past the end of the PE/COFF image, a ReadSize of 0 is returned.   A function of this type must be registered in the ImageRead field of a PE_COFF_LOADER_IMAGE_CONTEXT    structure for the PE/COFF Loader Library service to function correctly.  This function abstracts access    to a PE/COFF image so it can be implemented in an environment specific manner.  For example, SEC and PEI    environments may access memory directly to read the contents of a PE/COFF image, and DXE or UEFI    environments may require protocol services to read the contents of PE/COFF image    stored on FLASH, disk, or network devices.      If FileHandle is not a valid handle, then ASSERT().   If ReadSize is NULL, then ASSERT().   If Buffer is NULL, then ASSERT().    @param  FileHandle      Pointer to the file handle to read the PE/COFF image.   @param  FileOffset      Offset into the PE/COFF image to begin the read operation.   @param  ReadSize        On input, the size in bytes of the requested read operation.                             On output, the number of bytes actually read.   @param  Buffer          Output buffer that contains the data read from the PE/COFF image.      @retval RETURN_SUCCESS            The specified portion of the PE/COFF image was                                      read and the size return in ReadSize.   @retval RETURN_DEVICE_ERROR       The specified portion of the PE/COFF image                                      could not be read due to a device error.  **/
end_comment

begin_typedef
typedef|typedef
name|RETURN_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|PE_COFF_LOADER_READ_FILE
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|FileHandle
parameter_list|,
name|IN
name|UINTN
name|FileOffset
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ReadSize
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
comment|/// The context structure used while PE/COFF image is being loaded and relocated.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to the ImageBase in the PE/COFF header.
comment|///
name|PHYSICAL_ADDRESS
name|ImageAddress
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to the SizeOfImage in the PE/COFF header.
comment|/// Image size includes the size of Debug Entry if it is present.
comment|///
name|UINT64
name|ImageSize
decl_stmt|;
comment|///
comment|/// Is set to zero by PeCoffLoaderGetImageInfo(). If DestinationAddress is non-zero,
comment|/// PeCoffLoaderRelocateImage() will relocate the image using this base address.
comment|/// If the DestinationAddress is zero, the ImageAddress will be used as the base
comment|/// address of relocation.
comment|///
name|PHYSICAL_ADDRESS
name|DestinationAddress
decl_stmt|;
comment|///
comment|/// PeCoffLoaderLoadImage() sets EntryPoint to to the entry point of the PE/COFF image.
comment|///
name|PHYSICAL_ADDRESS
name|EntryPoint
decl_stmt|;
comment|///
comment|/// Passed in by the caller to PeCoffLoaderGetImageInfo() and PeCoffLoaderLoadImage()
comment|/// to abstract accessing the image from the library.
comment|///
name|PE_COFF_LOADER_READ_FILE
name|ImageRead
decl_stmt|;
comment|///
comment|/// Used as the FileHandle passed into the ImageRead function when it's called.
comment|///
name|VOID
modifier|*
name|Handle
decl_stmt|;
comment|///
comment|/// Caller allocated buffer of size FixupDataSize that can be optionally allocated
comment|/// prior to calling PeCoffLoaderRelocateImage().
comment|/// This buffer is filled with the information used to fix up the image.
comment|/// The fixups have been applied to the image and this entry is just for information.
comment|///
name|VOID
modifier|*
name|FixupData
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to the Section Alignment in the PE/COFF header.
comment|/// If the image is a TE image, then this field is set to 0.
comment|///
name|UINT32
name|SectionAlignment
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to offset to the PE/COFF header.
comment|/// If the PE/COFF image does not start with a DOS header, this value is zero.
comment|/// Otherwise, it's the offset to the PE/COFF header.
comment|///
name|UINT32
name|PeCoffHeaderOffset
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to the Relative Virtual Address of the debug directory,
comment|/// if it exists in the image
comment|///
name|UINT32
name|DebugDirectoryEntryRva
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderLoadImage() to CodeView area of the PE/COFF Debug directory.
comment|///
name|VOID
modifier|*
name|CodeView
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderLoadImage() to point to the PDB entry contained in the CodeView area.
comment|/// The PdbPointer points to the filename of the PDB file used for source-level debug of
comment|/// the image by a debugger.
comment|///
name|CHAR8
modifier|*
name|PdbPointer
decl_stmt|;
comment|///
comment|/// Is set by PeCoffLoaderGetImageInfo() to the Section Alignment in the PE/COFF header.
comment|///
name|UINTN
name|SizeOfHeaders
decl_stmt|;
comment|///
comment|/// Not used by this library class. Other library classes that layer on  top of this library
comment|/// class fill in this value as part of their GetImageInfo call.
comment|/// This allows the caller of the library to know what type of memory needs to be allocated
comment|/// to load and relocate the image.
comment|///
name|UINT32
name|ImageCodeMemoryType
decl_stmt|;
comment|///
comment|/// Not used by this library class. Other library classes that layer on top of this library
comment|/// class fill in this value as part of their GetImageInfo call.
comment|/// This allows the caller of the library to know what type of memory needs to be allocated
comment|/// to load and relocate the image.
comment|///
name|UINT32
name|ImageDataMemoryType
decl_stmt|;
comment|///
comment|/// Set by any of the library functions if they encounter an error.
comment|///
name|UINT32
name|ImageError
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderLoadImage() to indicate the size of FixupData that the caller must
comment|/// allocate before calling PeCoffLoaderRelocateImage().
comment|///
name|UINTN
name|FixupDataSize
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to the machine type stored in the PE/COFF header.
comment|///
name|UINT16
name|Machine
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to the subsystem type stored in the PE/COFF header.
comment|///
name|UINT16
name|ImageType
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to TRUE if the PE/COFF image does not contain
comment|/// relocation information.
comment|///
name|BOOLEAN
name|RelocationsStripped
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderGetImageInfo() to TRUE if the image is a TE image.
comment|/// For a definition of the TE Image format, see the Platform Initialization Pre-EFI
comment|/// Initialization Core Interface Specification.
comment|///
name|BOOLEAN
name|IsTeImage
decl_stmt|;
comment|///
comment|/// Set by PeCoffLoaderLoadImage() to the HII resource offset
comment|/// if the image contains a custom PE/COFF resource with the type 'HII'.
comment|/// Otherwise, the entry remains to be 0.
comment|///
name|PHYSICAL_ADDRESS
name|HiiResourceData
decl_stmt|;
comment|///
comment|/// Private storage for implementation specific data.
comment|///
name|UINT64
name|Context
decl_stmt|;
block|}
name|PE_COFF_LOADER_IMAGE_CONTEXT
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves information about a PE/COFF image.    Computes the PeCoffHeaderOffset, IsTeImage, ImageType, ImageAddress, ImageSize,    DestinationAddress, RelocationsStripped, SectionAlignment, SizeOfHeaders, and    DebugDirectoryEntryRva fields of the ImageContext structure.     If ImageContext is NULL, then return RETURN_INVALID_PARAMETER.     If the PE/COFF image accessed through the ImageRead service in the ImageContext    structure is not a supported PE/COFF image type, then return RETURN_UNSUPPORTED.     If any errors occur while computing the fields of ImageContext,    then the error status is returned in the ImageError field of ImageContext.     If the image is a TE image, then SectionAlignment is set to 0.   The ImageRead and Handle fields of ImageContext structure must be valid prior    to invoking this service.    @param  ImageContext              The pointer to the image context structure that                                      describes the PE/COFF image that needs to be                                      examined by this function.    @retval RETURN_SUCCESS            The information on the PE/COFF image was collected.   @retval RETURN_INVALID_PARAMETER  ImageContext is NULL.   @retval RETURN_UNSUPPORTED        The PE/COFF image is not supported.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|PeCoffLoaderGetImageInfo
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Applies relocation fixups to a PE/COFF image that was loaded with PeCoffLoaderLoadImage().    If the DestinationAddress field of ImageContext is 0, then use the ImageAddress field of   ImageContext as the relocation base address.  Otherwise, use the DestinationAddress field   of ImageContext as the relocation base address.  The caller must allocate the relocation   fixup log buffer and fill in the FixupData field of ImageContext prior to calling this function.      The ImageRead, Handle, PeCoffHeaderOffset, IsTeImage, Machine, ImageType, ImageAddress,    ImageSize, DestinationAddress, RelocationsStripped, SectionAlignment, SizeOfHeaders,    DebugDirectoryEntryRva, EntryPoint, FixupDataSize, CodeView, PdbPointer, and FixupData of    the ImageContext structure must be valid prior to invoking this service.        If ImageContext is NULL, then ASSERT().    Note that if the platform does not maintain coherency between the instruction cache(s) and the data   cache(s) in hardware, then the caller is responsible for performing cache maintenance operations   prior to transferring control to a PE/COFF image that is loaded using this library.    @param  ImageContext        The pointer to the image context structure that describes the PE/COFF                               image that is being relocated.    @retval RETURN_SUCCESS      The PE/COFF image was relocated.                               Extended status information is in the ImageError field of ImageContext.   @retval RETURN_LOAD_ERROR   The image in not a valid PE/COFF image.                               Extended status information is in the ImageError field of ImageContext.   @retval RETURN_UNSUPPORTED  A relocation record type is not supported.                               Extended status information is in the ImageError field of ImageContext.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|PeCoffLoaderRelocateImage
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Loads a PE/COFF image into memory.    Loads the PE/COFF image accessed through the ImageRead service of ImageContext into the buffer   specified by the ImageAddress and ImageSize fields of ImageContext.  The caller must allocate   the load buffer and fill in the ImageAddress and ImageSize fields prior to calling this function.   The EntryPoint, FixupDataSize, CodeView, PdbPointer and HiiResourceData fields of ImageContext are computed.   The ImageRead, Handle, PeCoffHeaderOffset, IsTeImage, Machine, ImageType, ImageAddress, ImageSize,    DestinationAddress, RelocationsStripped, SectionAlignment, SizeOfHeaders, and DebugDirectoryEntryRva    fields of the ImageContext structure must be valid prior to invoking this service.      If ImageContext is NULL, then ASSERT().    Note that if the platform does not maintain coherency between the instruction cache(s) and the data   cache(s) in hardware, then the caller is responsible for performing cache maintenance operations   prior to transferring control to a PE/COFF image that is loaded using this library.    @param  ImageContext              The pointer to the image context structure that describes the PE/COFF                                     image that is being loaded.    @retval RETURN_SUCCESS            The PE/COFF image was loaded into the buffer specified by                                     the ImageAddress and ImageSize fields of ImageContext.                                     Extended status information is in the ImageError field of ImageContext.   @retval RETURN_BUFFER_TOO_SMALL   The caller did not provide a large enough buffer.                                     Extended status information is in the ImageError field of ImageContext.   @retval RETURN_LOAD_ERROR         The PE/COFF image is an EFI Runtime image with no relocations.                                     Extended status information is in the ImageError field of ImageContext.   @retval RETURN_INVALID_PARAMETER  The image address is invalid.                                     Extended status information is in the ImageError field of ImageContext.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|PeCoffLoaderLoadImage
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads contents of a PE/COFF image from a buffer in system memory.       This is the default implementation of a PE_COFF_LOADER_READ_FILE function    that assumes FileHandle pointer to the beginning of a PE/COFF image.      This function reads contents of the PE/COFF image that starts at the system memory    address specified by FileHandle. The read operation copies ReadSize bytes from the    PE/COFF image starting at byte offset FileOffset into the buffer specified by Buffer.     The size of the buffer actually read is returned in ReadSize.      If FileHandle is NULL, then ASSERT().   If ReadSize is NULL, then ASSERT().   If Buffer is NULL, then ASSERT().    @param  FileHandle        The pointer to base of the input stream   @param  FileOffset        Offset into the PE/COFF image to begin the read operation.   @param  ReadSize          On input, the size in bytes of the requested read operation.                               On output, the number of bytes actually read.   @param  Buffer            Output buffer that contains the data read from the PE/COFF image.    @retval RETURN_SUCCESS    The data is read from FileOffset from the Handle into                              the buffer. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|PeCoffLoaderImageReadFromMemory
parameter_list|(
name|IN
name|VOID
modifier|*
name|FileHandle
parameter_list|,
name|IN
name|UINTN
name|FileOffset
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ReadSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reapply fixups on a fixed up PE32/PE32+ image to allow virtual calling at EFI   runtime.       This function reapplies relocation fixups to the PE/COFF image specified by ImageBase    and ImageSize so the image will execute correctly when the PE/COFF image is mapped    to the address specified by VirtualImageBase. RelocationData must be identical    to the FiuxupData buffer from the PE_COFF_LOADER_IMAGE_CONTEXT structure    after this PE/COFF image was relocated with PeCoffLoaderRelocateImage().    Note that if the platform does not maintain coherency between the instruction cache(s) and the data   cache(s) in hardware, then the caller is responsible for performing cache maintenance operations   prior to transferring control to a PE/COFF image that is loaded using this library.    @param  ImageBase          The base address of a PE/COFF image that has been loaded                               and relocated into system memory.   @param  VirtImageBase      The request virtual address that the PE/COFF image is to                              be fixed up for.   @param  ImageSize          The size, in bytes, of the PE/COFF image.   @param  RelocationData     A pointer to the relocation data that was collected when the PE/COFF                               image was relocated using PeCoffLoaderRelocateImage().    **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|PeCoffLoaderRelocateImageForRuntime
parameter_list|(
name|IN
name|PHYSICAL_ADDRESS
name|ImageBase
parameter_list|,
name|IN
name|PHYSICAL_ADDRESS
name|VirtImageBase
parameter_list|,
name|IN
name|UINTN
name|ImageSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|RelocationData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Unloads a loaded PE/COFF image from memory and releases its taken resource.   Releases any environment specific resources that were allocated when the image    specified by ImageContext was loaded using PeCoffLoaderLoadImage().      For NT32 emulator, the PE/COFF image loaded by system needs to release.   For real platform, the PE/COFF image loaded by Core doesn't needs to be unloaded,    this function can simply return RETURN_SUCCESS.      If ImageContext is NULL, then ASSERT().      @param  ImageContext              Pointer to the image context structure that describes the PE/COFF                                     image to be unloaded.    @retval RETURN_SUCCESS            The PE/COFF image was unloaded successfully. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|PeCoffLoaderUnloadImage
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

