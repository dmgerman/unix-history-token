begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Defives data structures per MultiProcessor Specification Ver 1.4.      The MultiProcessor Specification defines an enhancement to the standard    to which PC manufacturers design DOS-compatible systems.  Copyright (c) 2007 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials                           are licensed and made available under the terms and conditions of the BSD License          which accompanies this distribution.  The full text of the license may be found at         http://opensource.org/licenses/bsd-license.php                                                                                                                                        THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LEGACY_BIOS_MPTABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LEGACY_BIOS_MPTABLE_H_
end_define

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_REV_1_4
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define MP table structures. All are packed.
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

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_FLOATING_POINTER_SIGNATURE
value|SIGNATURE_32 ('_', 'M', 'P', '_')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Reserved1
range|:
literal|6
decl_stmt|;
name|UINT32
name|MutipleClk
range|:
literal|1
decl_stmt|;
name|UINT32
name|Imcr
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved2
range|:
literal|24
decl_stmt|;
block|}
name|FEATUREBYTE2_5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|PhysicalAddress
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|SpecRev
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|UINT8
name|FeatureByte1
decl_stmt|;
name|FEATUREBYTE2_5
name|FeatureByte2_5
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_FLOATING_POINTER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_HEADER_SIGNATURE
value|SIGNATURE_32 ('P', 'C', 'M', 'P')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT16
name|BaseTableLength
decl_stmt|;
name|UINT8
name|SpecRev
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|CHAR8
name|OemId
index|[
literal|8
index|]
decl_stmt|;
name|CHAR8
name|OemProductId
index|[
literal|12
index|]
decl_stmt|;
name|UINT32
name|OemTablePointer
decl_stmt|;
name|UINT16
name|OemTableSize
decl_stmt|;
name|UINT16
name|EntryCount
decl_stmt|;
name|UINT32
name|LocalApicAddress
decl_stmt|;
name|UINT16
name|ExtendedTableLength
decl_stmt|;
name|UINT8
name|ExtendedChecksum
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 0: Processor.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_TYPE_PROCESSOR
value|0x00
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Enabled
range|:
literal|1
decl_stmt|;
name|UINT8
name|Bsp
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|6
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_PROCESSOR_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Stepping
range|:
literal|4
decl_stmt|;
name|UINT32
name|Model
range|:
literal|4
decl_stmt|;
name|UINT32
name|Family
range|:
literal|4
decl_stmt|;
name|UINT32
name|Reserved
range|:
literal|20
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_PROCESSOR_SIGNATURE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Fpu
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved1
range|:
literal|6
decl_stmt|;
name|UINT32
name|Mce
range|:
literal|1
decl_stmt|;
name|UINT32
name|Cx8
range|:
literal|1
decl_stmt|;
name|UINT32
name|Apic
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved2
range|:
literal|22
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_PROCESSOR_FEATURES
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|Id
decl_stmt|;
name|UINT8
name|Ver
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_PROCESSOR_FLAGS
name|Flags
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_PROCESSOR_SIGNATURE
name|Signature
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_PROCESSOR_FEATURES
name|Features
decl_stmt|;
name|UINT32
name|Reserved1
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_PROCESSOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 1: Bus.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_TYPE_BUS
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|Id
decl_stmt|;
name|CHAR8
name|TypeString
index|[
literal|6
index|]
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_CBUS
value|"CBUS  "
end_define

begin_comment
comment|// Corollary CBus
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_CBUSII
value|"CBUSII"
end_define

begin_comment
comment|// Corollary CBUS II
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_EISA
value|"EISA  "
end_define

begin_comment
comment|// Extended ISA
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_FUTURE
value|"FUTURE"
end_define

begin_comment
comment|// IEEE FutureBus
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_INTERN
value|"INTERN"
end_define

begin_comment
comment|// Internal bus
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_ISA
value|"ISA   "
end_define

begin_comment
comment|// Industry Standard Architecture
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_MBI
value|"MBI   "
end_define

begin_comment
comment|// Multibus I
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_MBII
value|"MBII  "
end_define

begin_comment
comment|// Multibus II
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_MCA
value|"MCA   "
end_define

begin_comment
comment|// Micro Channel Architecture
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_MPI
value|"MPI   "
end_define

begin_comment
comment|// MPI
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_MPSA
value|"MPSA  "
end_define

begin_comment
comment|// MPSA
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_NUBUS
value|"NUBUS "
end_define

begin_comment
comment|// Apple Macintosh NuBus
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_PCI
value|"PCI   "
end_define

begin_comment
comment|// Peripheral Component Interconnect
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_PCMCIA
value|"PCMCIA"
end_define

begin_comment
comment|// PC Memory Card International Assoc.
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_TC
value|"TC    "
end_define

begin_comment
comment|// DEC TurboChannel
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_VL
value|"VL    "
end_define

begin_comment
comment|// VESA Local Bus
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_VME
value|"VME   "
end_define

begin_comment
comment|// VMEbus
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_BUS_STRING_XPRESS
value|"XPRESS"
end_define

begin_comment
comment|// Express System Bus
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 2: I/O APIC.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_TYPE_IOAPIC
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Enabled
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_IOAPIC_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|Id
decl_stmt|;
name|UINT8
name|Ver
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_IOAPIC_FLAGS
name|Flags
decl_stmt|;
name|UINT32
name|Address
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_IOAPIC
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 3: I/O Interrupt Assignment.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_TYPE_IO_INT
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Polarity
range|:
literal|2
decl_stmt|;
name|UINT16
name|Trigger
range|:
literal|2
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|12
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|IntNo
range|:
literal|2
decl_stmt|;
name|UINT8
name|Dev
range|:
literal|5
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|1
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_FIELDS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_FIELDS
name|fields
decl_stmt|;
name|UINT8
name|byte
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_SOURCE_BUS_IRQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|IntType
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_FLAGS
name|Flags
decl_stmt|;
name|UINT8
name|SourceBusId
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_SOURCE_BUS_IRQ
name|SourceBusIrq
decl_stmt|;
name|UINT8
name|DestApicId
decl_stmt|;
name|UINT8
name|DestApicIntIn
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_IO_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLegacyMpTableEntryIoIntTypeInt
init|=
literal|0
block|,
name|EfiLegacyMpTableEntryIoIntTypeNmi
init|=
literal|1
block|,
name|EfiLegacyMpTableEntryIoIntTypeSmi
init|=
literal|2
block|,
name|EfiLegacyMpTableEntryIoIntTypeExtInt
init|=
literal|3
block|, }
name|EFI_LEGACY_MP_TABLE_ENTRY_IO_INT_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLegacyMpTableEntryIoIntFlagsPolaritySpec
init|=
literal|0x0
block|,
name|EfiLegacyMpTableEntryIoIntFlagsPolarityActiveHigh
init|=
literal|0x1
block|,
name|EfiLegacyMpTableEntryIoIntFlagsPolarityReserved
init|=
literal|0x2
block|,
name|EfiLegacyMpTableEntryIoIntFlagsPolarityActiveLow
init|=
literal|0x3
block|, }
name|EFI_LEGACY_MP_TABLE_ENTRY_IO_INT_FLAGS_POLARITY
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLegacyMpTableEntryIoIntFlagsTriggerSpec
init|=
literal|0x0
block|,
name|EfiLegacyMpTableEntryIoIntFlagsTriggerEdge
init|=
literal|0x1
block|,
name|EfiLegacyMpTableEntryIoIntFlagsTriggerReserved
init|=
literal|0x2
block|,
name|EfiLegacyMpTableEntryIoIntFlagsTriggerLevel
init|=
literal|0x3
block|, }
name|EFI_LEGACY_MP_TABLE_ENTRY_IO_INT_FLAGS_TRIGGER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 4: Local Interrupt Assignment.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_TYPE_LOCAL_INT
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|IntType
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_FLAGS
name|Flags
decl_stmt|;
name|UINT8
name|SourceBusId
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_INT_SOURCE_BUS_IRQ
name|SourceBusIrq
decl_stmt|;
name|UINT8
name|DestApicId
decl_stmt|;
name|UINT8
name|DestApicIntIn
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_LOCAL_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLegacyMpTableEntryLocalIntTypeInt
init|=
literal|0
block|,
name|EfiLegacyMpTableEntryLocalIntTypeNmi
init|=
literal|1
block|,
name|EfiLegacyMpTableEntryLocalIntTypeSmi
init|=
literal|2
block|,
name|EfiLegacyMpTableEntryLocalIntTypeExtInt
init|=
literal|3
block|, }
name|EFI_LEGACY_MP_TABLE_ENTRY_LOCAL_INT_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLegacyMpTableEntryLocalIntFlagsPolaritySpec
init|=
literal|0x0
block|,
name|EfiLegacyMpTableEntryLocalIntFlagsPolarityActiveHigh
init|=
literal|0x1
block|,
name|EfiLegacyMpTableEntryLocalIntFlagsPolarityReserved
init|=
literal|0x2
block|,
name|EfiLegacyMpTableEntryLocalIntFlagsPolarityActiveLow
init|=
literal|0x3
block|, }
name|EFI_LEGACY_MP_TABLE_ENTRY_LOCAL_INT_FLAGS_POLARITY
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLegacyMpTableEntryLocalIntFlagsTriggerSpec
init|=
literal|0x0
block|,
name|EfiLegacyMpTableEntryLocalIntFlagsTriggerEdge
init|=
literal|0x1
block|,
name|EfiLegacyMpTableEntryLocalIntFlagsTriggerReserved
init|=
literal|0x2
block|,
name|EfiLegacyMpTableEntryLocalIntFlagsTriggerLevel
init|=
literal|0x3
block|, }
name|EFI_LEGACY_MP_TABLE_ENTRY_LOCAL_INT_FLAGS_TRIGGER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 128: System Address Space Mapping.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_TYPE_SYS_ADDR_SPACE_MAPPING
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|BusId
decl_stmt|;
name|UINT8
name|AddressType
decl_stmt|;
name|UINT64
name|AddressBase
decl_stmt|;
name|UINT64
name|AddressLength
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_SYS_ADDR_SPACE_MAPPING
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLegacyMpTableEntryExtSysAddrSpaceMappingIo
init|=
literal|0
block|,
name|EfiLegacyMpTableEntryExtSysAddrSpaceMappingMemory
init|=
literal|1
block|,
name|EfiLegacyMpTableEntryExtSysAddrSpaceMappingPrefetch
init|=
literal|2
block|, }
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_SYS_ADDR_SPACE_MAPPING_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 129: Bus Hierarchy.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_TYPE_BUS_HIERARCHY
value|0x81
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|SubtractiveDecode
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_BUS_HIERARCHY_BUSINFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|BusId
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_BUS_HIERARCHY_BUSINFO
name|BusInfo
decl_stmt|;
name|UINT8
name|ParentBus
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
name|UINT8
name|Reserved3
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_BUS_HIERARCHY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Entry Type 130: Compatibility Bus Address Space Modifier.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_TYPE_COMPAT_BUS_ADDR_SPACE_MODIFIER
value|0x82
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|RangeMode
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_COMPAT_BUS_ADDR_SPACE_MODIFIER_ADDR_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|BusId
decl_stmt|;
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_COMPAT_BUS_ADDR_SPACE_MODIFIER_ADDR_MODE
name|AddrMode
decl_stmt|;
name|UINT32
name|PredefinedRangeList
decl_stmt|;
block|}
name|EFI_LEGACY_MP_TABLE_ENTRY_EXT_COMPAT_BUS_ADDR_SPACE_MODIFIER
typedef|;
end_typedef

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

