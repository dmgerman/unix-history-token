begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI 1.0b definitions from the ACPI Specification, revision 1.0b  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPI_1_0_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPI_1_0_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/AcpiAml.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common table header, this prefaces all ACPI tables, including FACS, but
end_comment

begin_comment
comment|/// excluding the RSD PTR structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_COMMON_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// The common ACPI description table header.  This structure prefaces most ACPI tables.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|UINT8
name|OemId
index|[
literal|6
index|]
decl_stmt|;
name|UINT64
name|OemTableId
decl_stmt|;
name|UINT32
name|OemRevision
decl_stmt|;
name|UINT32
name|CreatorId
decl_stmt|;
name|UINT32
name|CreatorRevision
decl_stmt|;
block|}
name|EFI_ACPI_DESCRIPTION_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Define for Desriptor
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ACPI_SMALL_ITEM_FLAG
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_ITEM_FLAG
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Small Item Descriptor Name
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ACPI_SMALL_IRQ_DESCRIPTOR_NAME
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_DMA_DESCRIPTOR_NAME
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_START_DEPENDENT_DESCRIPTOR_NAME
value|0x06
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_END_DEPENDENT_DESCRIPTOR_NAME
value|0x07
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_IO_PORT_DESCRIPTOR_NAME
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_FIXED_IO_PORT_DESCRIPTOR_NAME
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_VENDOR_DEFINED_DESCRIPTOR_NAME
value|0x0E
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_END_TAG_DESCRIPTOR_NAME
value|0x0F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Large Item Descriptor Name
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ACPI_LARGE_24_BIT_MEMORY_RANGE_DESCRIPTOR_NAME
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_VENDOR_DEFINED_DESCRIPTOR_NAME
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_32_BIT_MEMORY_RANGE_DESCRIPTOR_NAME
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_32_BIT_FIXED_MEMORY_RANGE_DESCRIPTOR_NAME
value|0x06
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_DWORD_ADDRESS_SPACE_DESCRIPTOR_NAME
value|0x07
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_WORD_ADDRESS_SPACE_DESCRIPTOR_NAME
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_EXTENDED_IRQ_DESCRIPTOR_NAME
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_QWORD_ADDRESS_SPACE_DESCRIPTOR_NAME
value|0x0A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Small Item Descriptor Value
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ACPI_IRQ_NOFLAG_DESCRIPTOR
value|0x22
end_define

begin_define
define|#
directive|define
name|ACPI_IRQ_DESCRIPTOR
value|0x23
end_define

begin_define
define|#
directive|define
name|ACPI_DMA_DESCRIPTOR
value|0x2A
end_define

begin_define
define|#
directive|define
name|ACPI_START_DEPENDENT_DESCRIPTOR
value|0x30
end_define

begin_define
define|#
directive|define
name|ACPI_START_DEPENDENT_EX_DESCRIPTOR
value|0x31
end_define

begin_define
define|#
directive|define
name|ACPI_END_DEPENDENT_DESCRIPTOR
value|0x38
end_define

begin_define
define|#
directive|define
name|ACPI_IO_PORT_DESCRIPTOR
value|0x47
end_define

begin_define
define|#
directive|define
name|ACPI_FIXED_LOCATION_IO_PORT_DESCRIPTOR
value|0x4B
end_define

begin_define
define|#
directive|define
name|ACPI_END_TAG_DESCRIPTOR
value|0x79
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Large Item Descriptor Value
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ACPI_24_BIT_MEMORY_RANGE_DESCRIPTOR
value|0x81
end_define

begin_define
define|#
directive|define
name|ACPI_32_BIT_MEMORY_RANGE_DESCRIPTOR
value|0x85
end_define

begin_define
define|#
directive|define
name|ACPI_32_BIT_FIXED_MEMORY_RANGE_DESCRIPTOR
value|0x86
end_define

begin_define
define|#
directive|define
name|ACPI_DWORD_ADDRESS_SPACE_DESCRIPTOR
value|0x87
end_define

begin_define
define|#
directive|define
name|ACPI_WORD_ADDRESS_SPACE_DESCRIPTOR
value|0x88
end_define

begin_define
define|#
directive|define
name|ACPI_EXTENDED_INTERRUPT_DESCRIPTOR
value|0x89
end_define

begin_define
define|#
directive|define
name|ACPI_QWORD_ADDRESS_SPACE_DESCRIPTOR
value|0x8A
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_SPACE_DESCRIPTOR
value|0x8A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Resource Type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ACPI_ADDRESS_SPACE_TYPE_MEM
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_SPACE_TYPE_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_SPACE_TYPE_BUS
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Power Management Timer frequency is fixed at 3.579545MHz.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ACPI_TIMER_FREQUENCY
value|3579545
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure proper structure formats
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// The commond definition of QWORD, DWORD, and WORD
end_comment

begin_comment
comment|/// Address Space Descriptors.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|UINT8
name|Desc
decl_stmt|;
name|UINT16
name|Len
decl_stmt|;
name|UINT8
name|ResType
decl_stmt|;
name|UINT8
name|GenFlag
decl_stmt|;
name|UINT8
name|SpecificFlag
decl_stmt|;
name|UINT64
name|AddrSpaceGranularity
decl_stmt|;
name|UINT64
name|AddrRangeMin
decl_stmt|;
name|UINT64
name|AddrRangeMax
decl_stmt|;
name|UINT64
name|AddrTranslationOffset
decl_stmt|;
name|UINT64
name|AddrLen
decl_stmt|;
block|}
name|EFI_ACPI_ADDRESS_SPACE_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PACKED
union|union
block|{
name|UINT8
name|Byte
decl_stmt|;
name|PACKED
struct|struct
block|{
name|UINT8
name|Length
range|:
literal|3
decl_stmt|;
name|UINT8
name|Name
range|:
literal|4
decl_stmt|;
name|UINT8
name|Type
range|:
literal|1
decl_stmt|;
block|}
name|Bits
struct|;
block|}
name|ACPI_SMALL_RESOURCE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|PACKED
union|union
block|{
name|UINT8
name|Byte
decl_stmt|;
name|PACKED
struct|struct
block|{
name|UINT8
name|Name
range|:
literal|7
decl_stmt|;
name|UINT8
name|Type
range|:
literal|1
decl_stmt|;
block|}
name|Bits
struct|;
block|}
name|Header
union|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|ACPI_LARGE_RESOURCE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IRQ Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_SMALL_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Mask
decl_stmt|;
block|}
name|EFI_ACPI_IRQ_NOFLAG_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IRQ Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_SMALL_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Mask
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
block|}
name|EFI_ACPI_IRQ_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DMA Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_SMALL_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ChannelMask
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
block|}
name|EFI_ACPI_DMA_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// I/O Port Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_SMALL_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT16
name|BaseAddressMin
decl_stmt|;
name|UINT16
name|BaseAddressMax
decl_stmt|;
name|UINT8
name|Alignment
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_IO_PORT_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fixed Location I/O Port Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_SMALL_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|BaseAddress
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_FIXED_LOCATION_IO_PORT_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 24-Bit Memory Range Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT16
name|BaseAddressMin
decl_stmt|;
name|UINT16
name|BaseAddressMax
decl_stmt|;
name|UINT16
name|Alignment
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_24_BIT_MEMORY_RANGE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 32-Bit Memory Range Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT32
name|BaseAddressMin
decl_stmt|;
name|UINT32
name|BaseAddressMax
decl_stmt|;
name|UINT32
name|Alignment
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_32_BIT_MEMORY_RANGE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fixed 32-Bit Fixed Memory Range Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT32
name|BaseAddress
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_32_BIT_FIXED_MEMORY_RANGE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// QWORD Address Space Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ResType
decl_stmt|;
name|UINT8
name|GenFlag
decl_stmt|;
name|UINT8
name|SpecificFlag
decl_stmt|;
name|UINT64
name|AddrSpaceGranularity
decl_stmt|;
name|UINT64
name|AddrRangeMin
decl_stmt|;
name|UINT64
name|AddrRangeMax
decl_stmt|;
name|UINT64
name|AddrTranslationOffset
decl_stmt|;
name|UINT64
name|AddrLen
decl_stmt|;
block|}
name|EFI_ACPI_QWORD_ADDRESS_SPACE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DWORD Address Space Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ResType
decl_stmt|;
name|UINT8
name|GenFlag
decl_stmt|;
name|UINT8
name|SpecificFlag
decl_stmt|;
name|UINT32
name|AddrSpaceGranularity
decl_stmt|;
name|UINT32
name|AddrRangeMin
decl_stmt|;
name|UINT32
name|AddrRangeMax
decl_stmt|;
name|UINT32
name|AddrTranslationOffset
decl_stmt|;
name|UINT32
name|AddrLen
decl_stmt|;
block|}
name|EFI_ACPI_DWORD_ADDRESS_SPACE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// WORD Address Space Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ResType
decl_stmt|;
name|UINT8
name|GenFlag
decl_stmt|;
name|UINT8
name|SpecificFlag
decl_stmt|;
name|UINT16
name|AddrSpaceGranularity
decl_stmt|;
name|UINT16
name|AddrRangeMin
decl_stmt|;
name|UINT16
name|AddrRangeMax
decl_stmt|;
name|UINT16
name|AddrTranslationOffset
decl_stmt|;
name|UINT16
name|AddrLen
decl_stmt|;
block|}
name|EFI_ACPI_WORD_ADDRESS_SPACE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended Interrupt Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|InterruptVectorFlags
decl_stmt|;
name|UINT8
name|InterruptTableLength
decl_stmt|;
name|UINT32
name|InterruptNumber
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_ACPI_EXTENDED_INTERRUPT_DESCRIPTOR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// The End tag identifies an end of resource data.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Desc
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
block|}
name|EFI_ACPI_END_TAG_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// General use definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_RESERVED_BYTE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_RESERVED_WORD
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_RESERVED_DWORD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_RESERVED_QWORD
value|0x0000000000000000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Resource Type Specific Flags
end_comment

begin_comment
comment|// Ref ACPI specification 6.4.3.5.5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit [0]    : Write Status, _RW
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_READ_WRITE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_READ_ONLY
value|(0<< 0)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit [2:1]  : Memory Attributes, _MEM
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_NON_CACHEABLE
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_CACHEABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_CACHEABLE_WRITE_COMBINING
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_CACHEABLE_PREFETCHABLE
value|(3<< 1)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit [4:3]  : Memory Attributes, _MTP
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_ADDRESS_RANGE_MEMORY
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_ADDRESS_RANGE_RESERVED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_ADDRESS_RANGE_ACPI
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|EFI_APCI_MEMORY_RESOURCE_SPECIFIC_FLAG_ADDRESS_RANGE_NVS
value|(3<< 3)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit [5]    : Memory to I/O Translation, _TTP
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_TYPE_TRANSLATION
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_RESOURCE_SPECIFIC_FLAG_TYPE_STATIC
value|(0<< 5)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// IRQ Information
end_comment

begin_comment
comment|// Ref ACPI specification 6.4.2.1
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_SHARABLE_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_SHARABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_POLARITY_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_HIGH_TRUE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_LOW_FALSE
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_LEVEL_TRIGGERED
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IRQ_EDGE_TRIGGERED
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// DMA Information
end_comment

begin_comment
comment|// Ref ACPI specification 6.4.2.2
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_SPEED_TYPE_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_SPEED_TYPE_COMPATIBILITY
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_SPEED_TYPE_A
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_SPEED_TYPE_B
value|0x40
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_SPEED_TYPE_F
value|0x60
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_BUS_MASTER_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_BUS_MASTER
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_TRANSFER_TYPE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_TRANSFER_TYPE_8_BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_TRANSFER_TYPE_8_BIT_AND_16_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMA_TRANSFER_TYPE_16_BIT
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Information
end_comment

begin_comment
comment|// Ref ACPI specification 6.4.2.5
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_IO_DECODE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IO_DECODE_16_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_IO_DECODE_10_BIT
value|0x00
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Memory Information
end_comment

begin_comment
comment|// Ref ACPI specification 6.4.3.4
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_WRITE_STATUS_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_WRITABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_NON_WRITABLE
value|0x00
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure proper structure formats
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// ACPI 1.0b table structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Root System Description Pointer Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Signature
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|UINT8
name|OemId
index|[
literal|6
index|]
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|RsdtAddress
decl_stmt|;
block|}
name|EFI_ACPI_1_0_ROOT_SYSTEM_DESCRIPTION_POINTER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Root System Description Table
end_comment

begin_comment
comment|// No definition needed as it is a common description table header, the same with
end_comment

begin_comment
comment|// EFI_ACPI_DESCRIPTION_HEADER, followed by a variable number of UINT32 table pointers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// RSDT Revision (as defined in ACPI 1.0b specification).
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_ROOT_SYSTEM_DESCRIPTION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fixed ACPI Description Table Structure (FADT).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|FirmwareCtrl
decl_stmt|;
name|UINT32
name|Dsdt
decl_stmt|;
name|UINT8
name|IntModel
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT16
name|SciInt
decl_stmt|;
name|UINT32
name|SmiCmd
decl_stmt|;
name|UINT8
name|AcpiEnable
decl_stmt|;
name|UINT8
name|AcpiDisable
decl_stmt|;
name|UINT8
name|S4BiosReq
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
name|UINT32
name|Pm1aEvtBlk
decl_stmt|;
name|UINT32
name|Pm1bEvtBlk
decl_stmt|;
name|UINT32
name|Pm1aCntBlk
decl_stmt|;
name|UINT32
name|Pm1bCntBlk
decl_stmt|;
name|UINT32
name|Pm2CntBlk
decl_stmt|;
name|UINT32
name|PmTmrBlk
decl_stmt|;
name|UINT32
name|Gpe0Blk
decl_stmt|;
name|UINT32
name|Gpe1Blk
decl_stmt|;
name|UINT8
name|Pm1EvtLen
decl_stmt|;
name|UINT8
name|Pm1CntLen
decl_stmt|;
name|UINT8
name|Pm2CntLen
decl_stmt|;
name|UINT8
name|PmTmLen
decl_stmt|;
name|UINT8
name|Gpe0BlkLen
decl_stmt|;
name|UINT8
name|Gpe1BlkLen
decl_stmt|;
name|UINT8
name|Gpe1Base
decl_stmt|;
name|UINT8
name|Reserved3
decl_stmt|;
name|UINT16
name|PLvl2Lat
decl_stmt|;
name|UINT16
name|PLvl3Lat
decl_stmt|;
name|UINT16
name|FlushSize
decl_stmt|;
name|UINT16
name|FlushStride
decl_stmt|;
name|UINT8
name|DutyOffset
decl_stmt|;
name|UINT8
name|DutyWidth
decl_stmt|;
name|UINT8
name|DayAlrm
decl_stmt|;
name|UINT8
name|MonAlrm
decl_stmt|;
name|UINT8
name|Century
decl_stmt|;
name|UINT8
name|Reserved4
decl_stmt|;
name|UINT8
name|Reserved5
decl_stmt|;
name|UINT8
name|Reserved6
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_1_0_FIXED_ACPI_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FADT Version (as defined in ACPI 1.0b specification).
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_FIXED_ACPI_DESCRIPTION_TABLE_REVISION
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_INT_MODE_DUAL_PIC
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_INT_MODE_MULTIPLE_APIC
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Fixed ACPI Description Table Fixed Feature Flags
end_comment

begin_comment
comment|// All other bits are reserved and must be set to 0.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_WBINVD
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_WBINVD_FLUSH
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_PROC_C1
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_P_LVL2_UP
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_PWR_BUTTON
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_SLP_BUTTON
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_FIX_RTC
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_RTC_S4
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_TMR_VAL_EXT
value|BIT8
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_DCK_CAP
value|BIT9
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware ACPI Control Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|HardwareSignature
decl_stmt|;
name|UINT32
name|FirmwareWakingVector
decl_stmt|;
name|UINT32
name|GlobalLock
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|40
index|]
decl_stmt|;
block|}
name|EFI_ACPI_1_0_FIRMWARE_ACPI_CONTROL_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware Control Structure Feature Flags.
end_comment

begin_comment
comment|/// All other bits are reserved and must be set to 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_S4BIOS_F
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Multiple APIC Description Table header definition.  The rest of the table
end_comment

begin_comment
comment|/// must be defined in a platform-specific manner.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|LocalApicAddress
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_1_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MADT Revision (as defined in ACPI 1.0b specification).
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_MULTIPLE_APIC_DESCRIPTION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Multiple APIC Flags
end_comment

begin_comment
comment|/// All other bits are reserved and must be set to 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_PCAT_COMPAT
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Multiple APIC Description Table APIC structure types
end_comment

begin_comment
comment|// All other values between 0x05 an 0xFF are reserved and
end_comment

begin_comment
comment|// will be ignored by OSPM.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_PROCESSOR_LOCAL_APIC
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_IO_APIC
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_INTERRUPT_SOURCE_OVERRIDE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_NON_MASKABLE_INTERRUPT_SOURCE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_LOCAL_APIC_NMI
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// APIC Structure Definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Local APIC Structure Definition.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|AcpiProcessorId
decl_stmt|;
name|UINT8
name|ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_1_0_PROCESSOR_LOCAL_APIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local APIC Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_LOCAL_APIC_ENABLED
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO APIC Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|IoApicId
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|IoApicAddress
decl_stmt|;
name|UINT32
name|SystemVectorBase
decl_stmt|;
block|}
name|EFI_ACPI_1_0_IO_APIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Interrupt Source Override Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|Bus
decl_stmt|;
name|UINT8
name|Source
decl_stmt|;
name|UINT32
name|GlobalSystemInterruptVector
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_1_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Non-Maskable Interrupt Source Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT32
name|GlobalSystemInterruptVector
decl_stmt|;
block|}
name|EFI_ACPI_1_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local APIC NMI Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|AcpiProcessorId
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT8
name|LocalApicInti
decl_stmt|;
block|}
name|EFI_ACPI_1_0_LOCAL_APIC_NMI_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Smart Battery Description Table (SBST)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|WarningEnergyLevel
decl_stmt|;
name|UINT32
name|LowEnergyLevel
decl_stmt|;
name|UINT32
name|CriticalEnergyLevel
decl_stmt|;
block|}
name|EFI_ACPI_1_0_SMART_BATTERY_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Known table signatures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// "RSD PTR " Root System Description Pointer.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_ROOT_SYSTEM_DESCRIPTION_POINTER_SIGNATURE
value|SIGNATURE_64('R', 'S', 'D', ' ', 'P', 'T', 'R', ' ')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "APIC" Multiple APIC Description Table.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_APIC_SIGNATURE
value|SIGNATURE_32('A', 'P', 'I', 'C')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "DSDT" Differentiated System Description Table.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_DIFFERENTIATED_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('D', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "FACS" Firmware ACPI Control Structure.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_FIRMWARE_ACPI_CONTROL_STRUCTURE_SIGNATURE
value|SIGNATURE_32('F', 'A', 'C', 'S')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "FACP" Fixed ACPI Description Table.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_FIXED_ACPI_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('F', 'A', 'C', 'P')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "PSDT" Persistent System Description Table.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_PERSISTENT_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('P', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "RSDT" Root System Description Table.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_ROOT_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('R', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SBST" Smart Battery Specification Table.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_SMART_BATTERY_SPECIFICATION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'B', 'S', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SSDT" Secondary System Description Table.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_1_0_SECONDARY_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'S', 'D', 'T')
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

