begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   HOB related definitions in PI.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   PI Version 1.4a  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_HOB_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_HOB_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HobType of EFI_HOB_GENERIC_HEADER.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_HANDOFF
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_MEMORY_ALLOCATION
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_RESOURCE_DESCRIPTOR
value|0x0003
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_GUID_EXTENSION
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_FV
value|0x0005
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_CPU
value|0x0006
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_MEMORY_POOL
value|0x0007
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_FV2
value|0x0009
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_LOAD_PEIM_UNUSED
value|0x000A
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_UEFI_CAPSULE
value|0x000B
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_UNUSED
value|0xFFFE
end_define

begin_define
define|#
directive|define
name|EFI_HOB_TYPE_END_OF_HOB_LIST
value|0xFFFF
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes the format and size of the data inside the HOB.
end_comment

begin_comment
comment|/// All HOBs must contain this generic HOB header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Identifies the HOB data structure type.
comment|///
name|UINT16
name|HobType
decl_stmt|;
comment|///
comment|/// The length in bytes of the HOB.
comment|///
name|UINT16
name|HobLength
decl_stmt|;
comment|///
comment|/// This field must always be set to zero.
comment|///
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|EFI_HOB_GENERIC_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Value of version  in EFI_HOB_HANDOFF_INFO_TABLE.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_HOB_HANDOFF_TABLE_VERSION
value|0x0009
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Contains general state information used by the HOB producer phase.
end_comment

begin_comment
comment|/// This HOB must be the first one in the HOB list.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_HANDOFF.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// The version number pertaining to the PHIT HOB definition.
comment|/// This value is four bytes in length to provide an 8-byte aligned entry
comment|/// when it is combined with the 4-byte BootMode.
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// The system boot mode as determined during the HOB producer phase.
comment|///
name|EFI_BOOT_MODE
name|BootMode
decl_stmt|;
comment|///
comment|/// The highest address location of memory that is allocated for use by the HOB producer
comment|/// phase. This address must be 4-KB aligned to meet page restrictions of UEFI.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|EfiMemoryTop
decl_stmt|;
comment|///
comment|/// The lowest address location of memory that is allocated for use by the HOB producer phase.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|EfiMemoryBottom
decl_stmt|;
comment|///
comment|/// The highest address location of free memory that is currently available
comment|/// for use by the HOB producer phase.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|EfiFreeMemoryTop
decl_stmt|;
comment|///
comment|/// The lowest address location of free memory that is available for use by the HOB producer phase.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|EfiFreeMemoryBottom
decl_stmt|;
comment|///
comment|/// The end of the HOB list.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|EfiEndOfHobList
decl_stmt|;
block|}
name|EFI_HOB_HANDOFF_INFO_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HOB_MEMORY_ALLOCATION_HEADER describes the
end_comment

begin_comment
comment|/// various attributes of the logical memory allocation. The type field will be used for
end_comment

begin_comment
comment|/// subsequent inclusion in the UEFI memory map.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A GUID that defines the memory allocation region's type and purpose, as well as
comment|/// other fields within the memory allocation HOB. This GUID is used to define the
comment|/// additional data within the HOB that may be present for the memory allocation HOB.
comment|/// Type EFI_GUID is defined in InstallProtocolInterface() in the UEFI 2.0
comment|/// specification.
comment|///
name|EFI_GUID
name|Name
decl_stmt|;
comment|///
comment|/// The base address of memory allocated by this HOB. Type
comment|/// EFI_PHYSICAL_ADDRESS is defined in AllocatePages() in the UEFI 2.0
comment|/// specification.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|MemoryBaseAddress
decl_stmt|;
comment|///
comment|/// The length in bytes of memory allocated by this HOB.
comment|///
name|UINT64
name|MemoryLength
decl_stmt|;
comment|///
comment|/// Defines the type of memory allocated by this HOB. The memory type definition
comment|/// follows the EFI_MEMORY_TYPE definition. Type EFI_MEMORY_TYPE is defined
comment|/// in AllocatePages() in the UEFI 2.0 specification.
comment|///
name|EFI_MEMORY_TYPE
name|MemoryType
decl_stmt|;
comment|///
comment|/// Padding for Itanium processor family
comment|///
name|UINT8
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|EFI_HOB_MEMORY_ALLOCATION_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes all memory ranges used during the HOB producer
end_comment

begin_comment
comment|/// phase that exist outside the HOB list. This HOB type
end_comment

begin_comment
comment|/// describes how memory is used, not the physical attributes of memory.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_MEMORY_ALLOCATION.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// An instance of the EFI_HOB_MEMORY_ALLOCATION_HEADER that describes the
comment|/// various attributes of the logical memory allocation.
comment|///
name|EFI_HOB_MEMORY_ALLOCATION_HEADER
name|AllocDescriptor
decl_stmt|;
comment|//
comment|// Additional data pertaining to the "Name" Guid memory
comment|// may go here.
comment|//
block|}
name|EFI_HOB_MEMORY_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes the memory stack that is produced by the HOB producer
end_comment

begin_comment
comment|/// phase and upon which all post-memory-installed executable
end_comment

begin_comment
comment|/// content in the HOB producer phase is executing.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_MEMORY_ALLOCATION.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// An instance of the EFI_HOB_MEMORY_ALLOCATION_HEADER that describes the
comment|/// various attributes of the logical memory allocation.
comment|///
name|EFI_HOB_MEMORY_ALLOCATION_HEADER
name|AllocDescriptor
decl_stmt|;
block|}
name|EFI_HOB_MEMORY_ALLOCATION_STACK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Defines the location of the boot-strap
end_comment

begin_comment
comment|/// processor (BSP) BSPStore ("Backing Store Pointer Store").
end_comment

begin_comment
comment|/// This HOB is valid for the Itanium processor family only
end_comment

begin_comment
comment|/// register overflow store.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_MEMORY_ALLOCATION.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// An instance of the EFI_HOB_MEMORY_ALLOCATION_HEADER that describes the
comment|/// various attributes of the logical memory allocation.
comment|///
name|EFI_HOB_MEMORY_ALLOCATION_HEADER
name|AllocDescriptor
decl_stmt|;
block|}
name|EFI_HOB_MEMORY_ALLOCATION_BSP_STORE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Defines the location and entry point of the HOB consumer phase.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_MEMORY_ALLOCATION.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// An instance of the EFI_HOB_MEMORY_ALLOCATION_HEADER that describes the
comment|/// various attributes of the logical memory allocation.
comment|///
name|EFI_HOB_MEMORY_ALLOCATION_HEADER
name|MemoryAllocationHeader
decl_stmt|;
comment|///
comment|/// The GUID specifying the values of the firmware file system name
comment|/// that contains the HOB consumer phase component.
comment|///
name|EFI_GUID
name|ModuleName
decl_stmt|;
comment|///
comment|/// The address of the memory-mapped firmware volume
comment|/// that contains the HOB consumer phase firmware file.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|EntryPoint
decl_stmt|;
block|}
name|EFI_HOB_MEMORY_ALLOCATION_MODULE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resource type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_RESOURCE_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of ResourceType in EFI_HOB_RESOURCE_DESCRIPTOR.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_SYSTEM_MEMORY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_MEMORY_MAPPED_IO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_IO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_FIRMWARE_DEVICE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_MEMORY_MAPPED_IO_PORT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_MEMORY_RESERVED
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_IO_RESERVED
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_MAX_MEMORY_TYPE
value|0x00000007
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A type of recount attribute type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_RESOURCE_ATTRIBUTE_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// These types can be ORed together as needed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following attributes are used to describe settings
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_PRESENT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_INITIALIZED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_TESTED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_READ_PROTECTED
value|0x00000080
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// This is typically used as memory cacheability attribute today.
end_comment

begin_comment
comment|// NOTE: Since PI spec 1.4, please use EFI_RESOURCE_ATTRIBUTE_READ_ONLY_PROTECTED
end_comment

begin_comment
comment|// as Physical write protected attribute, and EFI_RESOURCE_ATTRIBUTE_WRITE_PROTECTED
end_comment

begin_comment
comment|// means Memory cacheability attribute: The memory supports being programmed with
end_comment

begin_comment
comment|// a writeprotected cacheable attribute.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_WRITE_PROTECTED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTED
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_PERSISTENT
value|0x00800000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// The rest of the attributes are used to describe capabilities
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_SINGLE_BIT_ECC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_MULTIPLE_BIT_ECC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_ECC_RESERVED_1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_ECC_RESERVED_2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_16_BIT_IO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_32_BIT_IO
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_64_BIT_IO
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_UNCACHED_EXPORTED
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_READ_PROTECTABLE
value|0x00100000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// This is typically used as memory cacheability attribute today.
end_comment

begin_comment
comment|// NOTE: Since PI spec 1.4, please use EFI_RESOURCE_ATTRIBUTE_READ_ONLY_PROTECTABLE
end_comment

begin_comment
comment|// as Memory capability attribute: The memory supports being protected from processor
end_comment

begin_comment
comment|// writes, and EFI_RESOURCE_ATTRIBUTE_WRITE_PROTEC TABLE means Memory cacheability attribute:
end_comment

begin_comment
comment|// The memory supports being programmed with a writeprotected cacheable attribute.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_WRITE_PROTECTABLE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_PERSISTABLE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_READ_ONLY_PROTECTED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_READ_ONLY_PROTECTABLE
value|0x00080000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Physical memory relative reliability attribute. This
end_comment

begin_comment
comment|// memory provides higher reliability relative to other
end_comment

begin_comment
comment|// memory in the system. If all memory has the same
end_comment

begin_comment
comment|// reliability, then this bit is not used.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_ATTRIBUTE_MORE_RELIABLE
value|0x02000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes the resource properties of all fixed,
end_comment

begin_comment
comment|/// nonrelocatable resource ranges found on the processor
end_comment

begin_comment
comment|/// host bus during the HOB producer phase.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_RESOURCE_DESCRIPTOR.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// A GUID representing the owner of the resource. This GUID is used by HOB
comment|/// consumer phase components to correlate device ownership of a resource.
comment|///
name|EFI_GUID
name|Owner
decl_stmt|;
comment|///
comment|/// The resource type enumeration as defined by EFI_RESOURCE_TYPE.
comment|///
name|EFI_RESOURCE_TYPE
name|ResourceType
decl_stmt|;
comment|///
comment|/// Resource attributes as defined by EFI_RESOURCE_ATTRIBUTE_TYPE.
comment|///
name|EFI_RESOURCE_ATTRIBUTE_TYPE
name|ResourceAttribute
decl_stmt|;
comment|///
comment|/// The physical start address of the resource region.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|PhysicalStart
decl_stmt|;
comment|///
comment|/// The number of bytes of the resource region.
comment|///
name|UINT64
name|ResourceLength
decl_stmt|;
block|}
name|EFI_HOB_RESOURCE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Allows writers of executable content in the HOB producer phase to
end_comment

begin_comment
comment|/// maintain and manage HOBs with specific GUID.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_GUID_EXTENSION.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// A GUID that defines the contents of this HOB.
comment|///
name|EFI_GUID
name|Name
decl_stmt|;
comment|//
comment|// Guid specific data goes here
comment|//
block|}
name|EFI_HOB_GUID_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Details the location of firmware volumes that contain firmware files.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_FV.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// The physical memory-mapped base address of the firmware volume.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
decl_stmt|;
comment|///
comment|/// The length in bytes of the firmware volume.
comment|///
name|UINT64
name|Length
decl_stmt|;
block|}
name|EFI_HOB_FIRMWARE_VOLUME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Details the location of a firmware volume that was extracted
end_comment

begin_comment
comment|/// from a file within another firmware volume.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_FV2.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// The physical memory-mapped base address of the firmware volume.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
decl_stmt|;
comment|///
comment|/// The length in bytes of the firmware volume.
comment|///
name|UINT64
name|Length
decl_stmt|;
comment|///
comment|/// The name of the firmware volume.
comment|///
name|EFI_GUID
name|FvName
decl_stmt|;
comment|///
comment|/// The name of the firmware file that contained this firmware volume.
comment|///
name|EFI_GUID
name|FileName
decl_stmt|;
block|}
name|EFI_HOB_FIRMWARE_VOLUME2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes processor information, such as address space and I/O space capabilities.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_CPU.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Identifies the maximum physical memory addressability of the processor.
comment|///
name|UINT8
name|SizeOfMemorySpace
decl_stmt|;
comment|///
comment|/// Identifies the maximum physical I/O addressability of the processor.
comment|///
name|UINT8
name|SizeOfIoSpace
decl_stmt|;
comment|///
comment|/// This field will always be set to zero.
comment|///
name|UINT8
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
name|EFI_HOB_CPU
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes pool memory allocations.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header. Header.HobType = EFI_HOB_TYPE_MEMORY_POOL.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_HOB_MEMORY_POOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each UEFI capsule HOB details the location of a UEFI capsule. It includes a base address and length
end_comment

begin_comment
comment|/// which is based upon memory blocks with a EFI_CAPSULE_HEADER and the associated
end_comment

begin_comment
comment|/// CapsuleImageSize-based payloads. These HOB's shall be created by the PEI PI firmware
end_comment

begin_comment
comment|/// sometime after the UEFI UpdateCapsule service invocation with the
end_comment

begin_comment
comment|/// CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE flag set in the EFI_CAPSULE_HEADER.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HOB generic header where Header.HobType = EFI_HOB_TYPE_UEFI_CAPSULE.
comment|///
name|EFI_HOB_GENERIC_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// The physical memory-mapped base address of an UEFI capsule. This value is set to
comment|/// point to the base of the contiguous memory of the UEFI capsule.
comment|/// The length of the contiguous memory in bytes.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
decl_stmt|;
name|UINT64
name|Length
decl_stmt|;
block|}
name|EFI_HOB_UEFI_CAPSULE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Union of all the possible HOB Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_HOB_GENERIC_HEADER
modifier|*
name|Header
decl_stmt|;
name|EFI_HOB_HANDOFF_INFO_TABLE
modifier|*
name|HandoffInformationTable
decl_stmt|;
name|EFI_HOB_MEMORY_ALLOCATION
modifier|*
name|MemoryAllocation
decl_stmt|;
name|EFI_HOB_MEMORY_ALLOCATION_BSP_STORE
modifier|*
name|MemoryAllocationBspStore
decl_stmt|;
name|EFI_HOB_MEMORY_ALLOCATION_STACK
modifier|*
name|MemoryAllocationStack
decl_stmt|;
name|EFI_HOB_MEMORY_ALLOCATION_MODULE
modifier|*
name|MemoryAllocationModule
decl_stmt|;
name|EFI_HOB_RESOURCE_DESCRIPTOR
modifier|*
name|ResourceDescriptor
decl_stmt|;
name|EFI_HOB_GUID_TYPE
modifier|*
name|Guid
decl_stmt|;
name|EFI_HOB_FIRMWARE_VOLUME
modifier|*
name|FirmwareVolume
decl_stmt|;
name|EFI_HOB_FIRMWARE_VOLUME2
modifier|*
name|FirmwareVolume2
decl_stmt|;
name|EFI_HOB_CPU
modifier|*
name|Cpu
decl_stmt|;
name|EFI_HOB_MEMORY_POOL
modifier|*
name|Pool
decl_stmt|;
name|EFI_HOB_UEFI_CAPSULE
modifier|*
name|Capsule
decl_stmt|;
name|UINT8
modifier|*
name|Raw
decl_stmt|;
block|}
name|EFI_PEI_HOB_POINTERS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

