begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Include file matches things in PI.  Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   PI Version 1.4  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_DXECIS_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_DXECIS_H__
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
comment|/// Global Coherencey Domain types - Memory type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// A memory region that is visible to the boot processor. However, there are no system
comment|/// components that are currently decoding this memory region.
comment|///
name|EfiGcdMemoryTypeNonExistent
block|,
comment|///
comment|/// A memory region that is visible to the boot processor. This memory region is being
comment|/// decoded by a system component, but the memory region is not considered to be either
comment|/// system memory or memory-mapped I/O.
comment|///
name|EfiGcdMemoryTypeReserved
block|,
comment|///
comment|/// A memory region that is visible to the boot processor. A memory controller is
comment|/// currently decoding this memory region and the memory controller is producing a
comment|/// tested system memory region that is available to the memory services.
comment|///
name|EfiGcdMemoryTypeSystemMemory
block|,
comment|///
comment|/// A memory region that is visible to the boot processor. This memory region is
comment|/// currently being decoded by a component as memory-mapped I/O that can be used to
comment|/// access I/O devices in the platform.
comment|///
name|EfiGcdMemoryTypeMemoryMappedIo
block|,
comment|///
comment|/// A memory region that is visible to the boot processor.
comment|/// This memory supports byte-addressable non-volatility.
comment|///
name|EfiGcdMemoryTypePersistentMemory
block|,
comment|///
comment|/// A memory region that provides higher reliability relative to other memory in the
comment|/// system. If all memory has the same reliability, then this bit is not used.
comment|///
name|EfiGcdMemoryTypeMoreReliable
block|,
name|EfiGcdMemoryTypeMaximum
block|}
name|EFI_GCD_MEMORY_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global Coherencey Domain types - IO type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// An I/O region that is visible to the boot processor. However, there are no system
comment|/// components that are currently decoding this I/O region.
comment|///
name|EfiGcdIoTypeNonExistent
block|,
comment|///
comment|/// An I/O region that is visible to the boot processor. This I/O region is currently being
comment|/// decoded by a system component, but the I/O region cannot be used to access I/O devices.
comment|///
name|EfiGcdIoTypeReserved
block|,
comment|///
comment|/// An I/O region that is visible to the boot processor. This I/O region is currently being
comment|/// decoded by a system component that is producing I/O ports that can be used to access I/O devices.
comment|///
name|EfiGcdIoTypeIo
block|,
name|EfiGcdIoTypeMaximum
block|}
name|EFI_GCD_IO_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of allocation to perform.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The GCD memory space map is searched from the lowest address up to the highest address
comment|/// looking for unallocated memory ranges.
comment|///
name|EfiGcdAllocateAnySearchBottomUp
block|,
comment|///
comment|/// The GCD memory space map is searched from the lowest address up
comment|/// to the specified MaxAddress looking for unallocated memory ranges.
comment|///
name|EfiGcdAllocateMaxAddressSearchBottomUp
block|,
comment|///
comment|/// The GCD memory space map is checked to see if the memory range starting
comment|/// at the specified Address is available.
comment|///
name|EfiGcdAllocateAddress
block|,
comment|///
comment|/// The GCD memory space map is searched from the highest address down to the lowest address
comment|/// looking for unallocated memory ranges.
comment|///
name|EfiGcdAllocateAnySearchTopDown
block|,
comment|///
comment|/// The GCD memory space map is searched from the specified MaxAddress
comment|/// down to the lowest address looking for unallocated memory ranges.
comment|///
name|EfiGcdAllocateMaxAddressSearchTopDown
block|,
name|EfiGcdMaxAllocateType
block|}
name|EFI_GCD_ALLOCATE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_GCD_MEMORY_SPACE_DESCRIPTOR.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The physical address of the first byte in the memory region. Type
comment|/// EFI_PHYSICAL_ADDRESS is defined in the AllocatePages() function
comment|/// description in the UEFI 2.0 specification.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
decl_stmt|;
comment|///
comment|/// The number of bytes in the memory region.
comment|///
name|UINT64
name|Length
decl_stmt|;
comment|///
comment|/// The bit mask of attributes that the memory region is capable of supporting. The bit
comment|/// mask of available attributes is defined in the GetMemoryMap() function description
comment|/// in the UEFI 2.0 specification.
comment|///
name|UINT64
name|Capabilities
decl_stmt|;
comment|///
comment|/// The bit mask of attributes that the memory region is currently using. The bit mask of
comment|/// available attributes is defined in GetMemoryMap().
comment|///
name|UINT64
name|Attributes
decl_stmt|;
comment|///
comment|/// Type of the memory region. Type EFI_GCD_MEMORY_TYPE is defined in the
comment|/// AddMemorySpace() function description.
comment|///
name|EFI_GCD_MEMORY_TYPE
name|GcdMemoryType
decl_stmt|;
comment|///
comment|/// The image handle of the agent that allocated the memory resource described by
comment|/// PhysicalStart and NumberOfBytes. If this field is NULL, then the memory
comment|/// resource is not currently allocated. Type EFI_HANDLE is defined in
comment|/// InstallProtocolInterface() in the UEFI 2.0 specification.
comment|///
name|EFI_HANDLE
name|ImageHandle
decl_stmt|;
comment|///
comment|/// The device handle for which the memory resource has been allocated. If
comment|/// ImageHandle is NULL, then the memory resource is not currently allocated. If this
comment|/// field is NULL, then the memory resource is not associated with a device that is
comment|/// described by a device handle. Type EFI_HANDLE is defined in
comment|/// InstallProtocolInterface() in the UEFI 2.0 specification.
comment|///
name|EFI_HANDLE
name|DeviceHandle
decl_stmt|;
block|}
name|EFI_GCD_MEMORY_SPACE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_GCD_IO_SPACE_DESCRIPTOR.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Physical address of the first byte in the I/O region. Type
comment|/// EFI_PHYSICAL_ADDRESS is defined in the AllocatePages() function
comment|/// description in the UEFI 2.0 specification.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
decl_stmt|;
comment|///
comment|/// Number of bytes in the I/O region.
comment|///
name|UINT64
name|Length
decl_stmt|;
comment|///
comment|/// Type of the I/O region. Type EFI_GCD_IO_TYPE is defined in the
comment|/// AddIoSpace() function description.
comment|///
name|EFI_GCD_IO_TYPE
name|GcdIoType
decl_stmt|;
comment|///
comment|/// The image handle of the agent that allocated the I/O resource described by
comment|/// PhysicalStart and NumberOfBytes. If this field is NULL, then the I/O
comment|/// resource is not currently allocated. Type EFI_HANDLE is defined in
comment|/// InstallProtocolInterface() in the UEFI 2.0 specification.
comment|///
name|EFI_HANDLE
name|ImageHandle
decl_stmt|;
comment|///
comment|/// The device handle for which the I/O resource has been allocated. If ImageHandle
comment|/// is NULL, then the I/O resource is not currently allocated. If this field is NULL, then
comment|/// the I/O resource is not associated with a device that is described by a device handle.
comment|/// Type EFI_HANDLE is defined in InstallProtocolInterface() in the UEFI
comment|/// 2.0 specification.
comment|///
name|EFI_HANDLE
name|DeviceHandle
decl_stmt|;
block|}
name|EFI_GCD_IO_SPACE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|/**   Adds reserved memory, system memory, or memory-mapped I/O resources to the   global coherency domain of the processor.    @param  GcdMemoryType    The type of memory resource being added.   @param  BaseAddress      The physical address that is the start address                            of the memory resource being added.   @param  Length           The size, in bytes, of the memory resource that                            is being added.   @param  Capabilities     The bit mask of attributes that the memory                             resource region supports.    @retval EFI_SUCCESS            The memory resource was added to the global                                  coherency domain of the processor.   @retval EFI_INVALID_PARAMETER  GcdMemoryType is invalid.   @retval EFI_INVALID_PARAMETER  Length is zero.   @retval EFI_OUT_OF_RESOURCES   There are not enough system resources to add                                  the memory resource to the global coherency                                   domain of the processor.   @retval EFI_UNSUPPORTED        The processor does not support one or more bytes                                  of the memory resource range specified by                                   BaseAddress and Length.   @retval EFI_ACCESS_DENIED      One or more bytes of the memory resource range                                  specified by BaseAddress and Length conflicts                                   with a memory resource range that was previously                                  added to the global coherency domain of the processor.   @retval EFI_ACCESS_DENIED      One or more bytes of the memory resource range                                  specified by BaseAddress and Length was allocated                                  in a prior call to AllocateMemorySpace().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ADD_MEMORY_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_GCD_MEMORY_TYPE
name|GcdMemoryType
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|,
name|IN
name|UINT64
name|Capabilities
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Allocates nonexistent memory, reserved memory, system memory, or memorymapped   I/O resources from the global coherency domain of the processor.    @param  GcdAllocateType  The type of allocation to perform.   @param  GcdMemoryType    The type of memory resource being allocated.   @param  Alignment        The log base 2 of the boundary that BaseAddress must                            be aligned on output. Align with 2^Alignment.   @param  Length           The size in bytes of the memory resource range that                            is being allocated.   @param  BaseAddress      A pointer to a physical address to allocate.   @param  Imagehandle      The image handle of the agent that is allocating                             the memory resource.   @param  DeviceHandle     The device handle for which the memory resource                            is being allocated.    @retval EFI_INVALID_PARAMETER GcdAllocateType is invalid.   @retval EFI_INVALID_PARAMETER GcdMemoryType is invalid.   @retval EFI_INVALID_PARAMETER Length is zero.   @retval EFI_INVALID_PARAMETER BaseAddress is NULL.   @retval EFI_INVALID_PARAMETER ImageHandle is NULL.   @retval EFI_NOT_FOUND         The memory resource request could not be satisfied.                                 No descriptor contains the desired space.   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to allocate the memory                                 resource from the global coherency domain of the processor.   @retval EFI_SUCCESS           The memory resource was allocated from the global coherency                                 domain of the processor.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ALLOCATE_MEMORY_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_GCD_ALLOCATE_TYPE
name|GcdAllocateType
parameter_list|,
name|IN
name|EFI_GCD_MEMORY_TYPE
name|GcdMemoryType
parameter_list|,
name|IN
name|UINTN
name|Alignment
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|,
name|IN
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|BaseAddress
parameter_list|,
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|DeviceHandle
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Frees nonexistent memory, reserved memory, system memory, or memory-mapped   I/O resources from the global coherency domain of the processor.    @param  BaseAddress      The physical address that is the start address of the memory resource being freed.   @param  Length           The size in bytes of the memory resource range that is being freed.    @retval EFI_SUCCESS           The memory resource was freed from the global coherency domain of                                 the processor.   @retval EFI_INVALID_PARAMETER Length is zero.      @retval EFI_UNSUPPORTED       The processor does not support one or more bytes of the memory                                 resource range specified by BaseAddress and Length.   @retval EFI_NOT_FOUND         The memory resource range specified by BaseAddress and                                 Length was not allocated with previous calls to AllocateMemorySpace().   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to free the memory resource                                 from the global coherency domain of the processor.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FREE_MEMORY_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Removes reserved memory, system memory, or memory-mapped I/O resources from   the global coherency domain of the processor.    @param  BaseAddress      The physical address that is the start address of the memory resource being removed.   @param  Length           The size in bytes of the memory resource that is being removed.    @retval EFI_SUCCESS           The memory resource was removed from the global coherency                                 domain of the processor.   @retval EFI_INVALID_PARAMETER Length is zero.    @retval EFI_UNSUPPORTED       The processor does not support one or more bytes of the memory                                 resource range specified by BaseAddress and Length.   @retval EFI_NOT_FOUND         One or more bytes of the memory resource range specified by                                 BaseAddress and Length was not added with previous calls to                                 AddMemorySpace().   @retval EFI_ACCESS_DEFINED    One or more bytes of the memory resource range specified by                                 BaseAddress and Length has been allocated with AllocateMemorySpace().   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to remove the memory                                 resource from the global coherency domain of the processor.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REMOVE_MEMORY_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the descriptor for a memory region containing a specified address.    @param  BaseAddress      The physical address that is the start address of a memory region.   @param  Descriptor       A pointer to a caller allocated descriptor.    @retval EFI_SUCCESS           The descriptor for the memory resource region containing                                 BaseAddress was returned in Descriptor.   @retval EFI_INVALID_PARAMETER Descriptor is NULL.   @retval EFI_NOT_FOUND         A memory resource range containing BaseAddress was not found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_MEMORY_SPACE_DESCRIPTOR
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|OUT
name|EFI_GCD_MEMORY_SPACE_DESCRIPTOR
modifier|*
name|Descriptor
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Modifies the attributes for a memory region in the global coherency domain of the   processor.    @param  BaseAddress      The physical address that is the start address of a memory region.   @param  Length           The size in bytes of the memory region.   @param  Attributes       The bit mask of attributes to set for the memory region.    @retval EFI_SUCCESS           The attributes were set for the memory region.   @retval EFI_INVALID_PARAMETER Length is zero.    @retval EFI_UNSUPPORTED       The processor does not support one or more bytes of the memory                                 resource range specified by BaseAddress and Length.   @retval EFI_UNSUPPORTED       The bit mask of attributes is not support for the memory resource                                 range specified by BaseAddress and Length.   @retval EFI_ACCESS_DENIED     The attributes for the memory resource range specified by                                 BaseAddress and Length cannot be modified.   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to modify the attributes of                                 the memory resource range.   @retval EFI_NOT_AVAILABLE_YET The attributes cannot be set because CPU architectural protocol is                                 not available yet. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_MEMORY_SPACE_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Modifies the capabilities for a memory region in the global coherency domain of the   processor.    @param  BaseAddress      The physical address that is the start address of a memory region.   @param  Length           The size in bytes of the memory region.   @param  Capabilities     The bit mask of capabilities that the memory region supports.    @retval EFI_SUCCESS           The capabilities were set for the memory region.   @retval EFI_INVALID_PARAMETER Length is zero.   @retval EFI_UNSUPPORTED       The capabilities specified by Capabilities do not include the                                 memory region attributes currently in use.   @retval EFI_ACCESS_DENIED     The capabilities for the memory resource range specified by                                 BaseAddress and Length cannot be modified.   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to modify the capabilities                                 of the memory resource range. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_MEMORY_SPACE_CAPABILITIES
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|,
name|IN
name|UINT64
name|Capabilities
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns a map of the memory resources in the global coherency domain of the   processor.    @param  NumberOfDescriptors A pointer to number of descriptors returned in the MemorySpaceMap buffer.   @param  MemorySpaceMap      A pointer to the array of EFI_GCD_MEMORY_SPACE_DESCRIPTORs.    @retval EFI_SUCCESS           The memory space map was returned in the MemorySpaceMap                                 buffer, and the number of descriptors in MemorySpaceMap was                                 returned in NumberOfDescriptors.   @retval EFI_INVALID_PARAMETER NumberOfDescriptors is NULL.   @retval EFI_INVALID_PARAMETER MemorySpaceMap is NULL.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to allocate MemorySpaceMap.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_MEMORY_SPACE_MAP
function_decl|)
parameter_list|(
name|OUT
name|UINTN
modifier|*
name|NumberOfDescriptors
parameter_list|,
name|OUT
name|EFI_GCD_MEMORY_SPACE_DESCRIPTOR
modifier|*
modifier|*
name|MemorySpaceMap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Adds reserved I/O or I/O resources to the global coherency domain of the processor.    @param  GcdIoType        The type of I/O resource being added.   @param  BaseAddress      The physical address that is the start address of the I/O resource being added.   @param  Length           The size in bytes of the I/O resource that is being added.    @retval EFI_SUCCESS           The I/O resource was added to the global coherency domain of                                 the processor.   @retval EFI_INVALID_PARAMETER GcdIoType is invalid.   @retval EFI_INVALID_PARAMETER Length is zero.   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to add the I/O resource to                                 the global coherency domain of the processor.   @retval EFI_UNSUPPORTED       The processor does not support one or more bytes of the I/O                                 resource range specified by BaseAddress and Length.   @retval EFI_ACCESS_DENIED     One or more bytes of the I/O resource range specified by                                 BaseAddress and Length conflicts with an I/O resource                                 range that was previously added to the global coherency domain                                 of the processor.   @retval EFI_ACCESS_DENIED     One or more bytes of the I/O resource range specified by                                 BaseAddress and Length was allocated in a prior call to                                 AllocateIoSpace().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ADD_IO_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_GCD_IO_TYPE
name|GcdIoType
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Allocates nonexistent I/O, reserved I/O, or I/O resources from the global coherency   domain of the processor.    @param  GcdAllocateType  The type of allocation to perform.   @param  GcdIoType        The type of I/O resource being allocated.   @param  Alignment        The log base 2 of the boundary that BaseAddress must be aligned on output.   @param  Length           The size in bytes of the I/O resource range that is being allocated.   @param  BaseAddress      A pointer to a physical address.   @param  Imagehandle      The image handle of the agent that is allocating the I/O resource.   @param  DeviceHandle     The device handle for which the I/O resource is being allocated.    @retval EFI_SUCCESS           The I/O resource was allocated from the global coherency domain                                 of the processor.   @retval EFI_INVALID_PARAMETER GcdAllocateType is invalid.   @retval EFI_INVALID_PARAMETER GcdIoType is invalid.   @retval EFI_INVALID_PARAMETER Length is zero.   @retval EFI_INVALID_PARAMETER BaseAddress is NULL.   @retval EFI_INVALID_PARAMETER ImageHandle is NULL.   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to allocate the I/O                                 resource from the global coherency domain of the processor.   @retval EFI_NOT_FOUND         The I/O resource request could not be satisfied.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ALLOCATE_IO_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_GCD_ALLOCATE_TYPE
name|GcdAllocateType
parameter_list|,
name|IN
name|EFI_GCD_IO_TYPE
name|GcdIoType
parameter_list|,
name|IN
name|UINTN
name|Alignment
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|,
name|IN
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|BaseAddress
parameter_list|,
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|DeviceHandle
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Frees nonexistent I/O, reserved I/O, or I/O resources from the global coherency   domain of the processor.    @param  BaseAddress      The physical address that is the start address of the I/O resource being freed.   @param  Length           The size in bytes of the I/O resource range that is being freed.    @retval EFI_SUCCESS           The I/O resource was freed from the global coherency domain of the                                 processor.   @retval EFI_INVALID_PARAMETER Length is zero.   @retval EFI_UNSUPPORTED       The processor does not support one or more bytes of the I/O resource                                 range specified by BaseAddress and Length.   @retval EFI_NOT_FOUND         The I/O resource range specified by BaseAddress and Length                                 was not allocated with previous calls to AllocateIoSpace().   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to free the I/O resource from                                 the global coherency domain of the processor.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FREE_IO_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Removes reserved I/O or I/O resources from the global coherency domain of the   processor.    @param  BaseAddress      A pointer to a physical address that is the start address of the I/O resource being                            removed.   @param Length            The size in bytes of the I/O resource that is being removed.    @retval EFI_SUCCESS           The I/O resource was removed from the global coherency domain                                 of the processor.   @retval EFI_INVALID_PARAMETER Length is zero.   @retval EFI_UNSUPPORTED       The processor does not support one or more bytes of the I/O                                 resource range specified by BaseAddress and Length.   @retval EFI_NOT_FOUND         One or more bytes of the I/O resource range specified by                                 BaseAddress and Length was not added with previous                                 calls to AddIoSpace().   @retval EFI_ACCESS_DENIED     One or more bytes of the I/O resource range specified by                                 BaseAddress and Length has been allocated with                                 AllocateIoSpace().   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to remove the I/O                                 resource from the global coherency domain of the processor.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REMOVE_IO_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the descriptor for an I/O region containing a specified address.    @param  BaseAddress      The physical address that is the start address of an I/O region.   @param  Descriptor       A pointer to a caller allocated descriptor.    @retval EFI_SUCCESS           The descriptor for the I/O resource region containing                                 BaseAddress was returned in Descriptor.   @retval EFI_INVALID_PARAMETER Descriptor is NULL.   @retval EFI_NOT_FOUND         An I/O resource range containing BaseAddress was not found.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_IO_SPACE_DESCRIPTOR
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|OUT
name|EFI_GCD_IO_SPACE_DESCRIPTOR
modifier|*
name|Descriptor
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns a map of the I/O resources in the global coherency domain of the processor.    @param  NumberOfDescriptors A pointer to number of descriptors returned in the IoSpaceMap buffer.   @param  MemorySpaceMap      A pointer to the array of EFI_GCD_IO_SPACE_DESCRIPTORs.    @retval EFI_SUCCESS           The I/O space map was returned in the IoSpaceMap buffer, and                                 the number of descriptors in IoSpaceMap was returned in                                 NumberOfDescriptors.   @retval EFI_INVALID_PARAMETER NumberOfDescriptors is NULL.   @retval EFI_INVALID_PARAMETER IoSpaceMap is NULL.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to allocate IoSpaceMap.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_IO_SPACE_MAP
function_decl|)
parameter_list|(
name|OUT
name|UINTN
modifier|*
name|NumberOfDescriptors
parameter_list|,
name|OUT
name|EFI_GCD_IO_SPACE_DESCRIPTOR
modifier|*
modifier|*
name|IoSpaceMap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Loads and executed DXE drivers from firmware volumes.    The Dispatch() function searches for DXE drivers in firmware volumes that have been    installed since the last time the Dispatch() service was called. It then evaluates    the dependency expressions of all the DXE drivers and loads and executes those DXE   drivers whose dependency expression evaluate to TRUE. This service must interact with   the Security Architectural Protocol to authenticate DXE drivers before they are executed.   This process is continued until no more DXE drivers can be executed.    @retval EFI_SUCCESS         One or more DXE driver were dispatched.   @retval EFI_NOT_FOUND       No DXE drivers were dispatched.   @retval EFI_ALREADY_STARTED An attempt is being made to start the DXE Dispatcher recursively.                               Thus, no action was taken.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISPATCH
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Clears the Schedule on Request (SOR) flag for a component that is stored in a firmware volume.    @param  FirmwareVolumeHandle The handle of the firmware volume that contains the file specified by FileName.   @param  FileName             A pointer to the name of the file in a firmware volume.    @retval EFI_SUCCESS         The DXE driver was found and its SOR bit was cleared.   @retval EFI_NOT_FOUND       The DXE driver does not exist, or the DXE driver exists and its SOR                               bit is not set.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCHEDULE
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|FirmwareVolumeHandle
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|FileName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Promotes a file stored in a firmware volume from the untrusted to the trusted state.    @param  FirmwareVolumeHandle The handle of the firmware volume that contains the file specified by FileName.   @param  DriverName           A pointer to the name of the file in a firmware volume.    @return Status of promoting FFS from untrusted to trusted           state.   @retval EFI_NOT_FOUND       The file was not found in the untrusted state.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TRUST
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|FirmwareVolumeHandle
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|FileName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates a firmware volume handle for a firmware volume that is present in system memory.    @param  FirmwareVolumeHeader A pointer to the header of the firmware volume.   @param  Size                 The size, in bytes, of the firmware volume.   @param  FirmwareVolumeHandle On output, a pointer to the created handle.    @retval EFI_SUCCESS          The EFI_FIRMWARE_VOLUME_PROTOCOL and                                EFI_DEVICE_PATH_PROTOCOL were installed onto                                FirmwareVolumeHandle for the firmware volume described                                by FirmwareVolumeHeader and Size.   @retval EFI_VOLUME_CORRUPTED The firmware volume described by FirmwareVolumeHeader                                and Size is corrupted.   @retval EFI_OUT_OF_RESOURCES There are not enough system resources available to produce the                                EFI_FIRMWARE_VOLUME_PROTOCOL and EFI_DEVICE_PATH_PROTOCOL                                 for the firmware volume described by FirmwareVolumeHeader and Size.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PROCESS_FIRMWARE_VOLUME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|FirmwareVolumeHeader
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|FirmwareVolumeHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// DXE Services Table
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|DXE_SERVICES_SIGNATURE
value|0x565245535f455844ULL
end_define

begin_define
define|#
directive|define
name|DXE_SPECIFICATION_MAJOR_REVISION
value|1
end_define

begin_define
define|#
directive|define
name|DXE_SPECIFICATION_MINOR_REVISION
value|40
end_define

begin_define
define|#
directive|define
name|DXE_SERVICES_REVISION
value|((DXE_SPECIFICATION_MAJOR_REVISION<<16) | (DXE_SPECIFICATION_MINOR_REVISION))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The table header for the DXE Services Table.
comment|/// This header contains the DXE_SERVICES_SIGNATURE and DXE_SERVICES_REVISION values.
comment|///
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|//
comment|// Global Coherency Domain Services
comment|//
name|EFI_ADD_MEMORY_SPACE
name|AddMemorySpace
decl_stmt|;
name|EFI_ALLOCATE_MEMORY_SPACE
name|AllocateMemorySpace
decl_stmt|;
name|EFI_FREE_MEMORY_SPACE
name|FreeMemorySpace
decl_stmt|;
name|EFI_REMOVE_MEMORY_SPACE
name|RemoveMemorySpace
decl_stmt|;
name|EFI_GET_MEMORY_SPACE_DESCRIPTOR
name|GetMemorySpaceDescriptor
decl_stmt|;
name|EFI_SET_MEMORY_SPACE_ATTRIBUTES
name|SetMemorySpaceAttributes
decl_stmt|;
name|EFI_GET_MEMORY_SPACE_MAP
name|GetMemorySpaceMap
decl_stmt|;
name|EFI_ADD_IO_SPACE
name|AddIoSpace
decl_stmt|;
name|EFI_ALLOCATE_IO_SPACE
name|AllocateIoSpace
decl_stmt|;
name|EFI_FREE_IO_SPACE
name|FreeIoSpace
decl_stmt|;
name|EFI_REMOVE_IO_SPACE
name|RemoveIoSpace
decl_stmt|;
name|EFI_GET_IO_SPACE_DESCRIPTOR
name|GetIoSpaceDescriptor
decl_stmt|;
name|EFI_GET_IO_SPACE_MAP
name|GetIoSpaceMap
decl_stmt|;
comment|//
comment|// Dispatcher Services
comment|//
name|EFI_DISPATCH
name|Dispatch
decl_stmt|;
name|EFI_SCHEDULE
name|Schedule
decl_stmt|;
name|EFI_TRUST
name|Trust
decl_stmt|;
comment|//
comment|// Service to process a single firmware volume found in a capsule
comment|//
name|EFI_PROCESS_FIRMWARE_VOLUME
name|ProcessFirmwareVolume
decl_stmt|;
comment|//
comment|// Extensions to Global Coherency Domain Services
comment|//
name|EFI_SET_MEMORY_SPACE_CAPABILITIES
name|SetMemorySpaceCapabilities
decl_stmt|;
block|}
name|DXE_SERVICES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DXE_SERVICES
name|EFI_DXE_SERVICES
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

