begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUIDs and definitions used for Common Platform Error Record.    Copyright (c) 2011 - 2016, Intel Corporation. All rights reserved.<BR>   (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   GUIDs defined in UEFI 2.6 Specification.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CPER_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__CPER_GUID_H__
end_define

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
name|EFI_ERROR_RECORD_SIGNATURE_START
value|SIGNATURE_32('C', 'P', 'E', 'R')
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_RECORD_SIGNATURE_END
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_RECORD_REVISION
value|0x0101
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error Severity in Error Record Header and Error Section Descriptor
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_RECOVERABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_FATAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_CORRECTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_INFO
value|0x00000003
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates the validity of the following fields
end_comment

begin_comment
comment|/// in Error Record Header.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_ERROR_RECORD_HEADER_PLATFORM_ID_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_RECORD_HEADER_TIME_STAMP_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_RECORD_HEADER_PARTITION_ID_VALID
value|BIT2
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Timestamp is precise if this bit is set and correlates to the time of the
end_comment

begin_comment
comment|/// error event.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ERROR_TIME_STAMP_PRECISE
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The timestamp correlates to the time when the error information was collected
end_comment

begin_comment
comment|/// by the system software and may not necessarily represent the time of the error
end_comment

begin_comment
comment|/// event. The timestamp contains the local time in BCD format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Seconds
decl_stmt|;
name|UINT8
name|Minutes
decl_stmt|;
name|UINT8
name|Hours
decl_stmt|;
name|UINT8
name|Flag
decl_stmt|;
name|UINT8
name|Day
decl_stmt|;
name|UINT8
name|Month
decl_stmt|;
name|UINT8
name|Year
decl_stmt|;
name|UINT8
name|Century
decl_stmt|;
block|}
name|EFI_ERROR_TIME_STAMP
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID value indicating the record association with an error event notification type.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_CMC_GUID
define|\
value|{ \     0x2DCE8BB1, 0xBDD7, 0x450e, { 0xB9, 0xAD, 0x9C, 0xF4, 0xEB, 0xD4, 0xF8, 0x90 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_CPE_GUID
define|\
value|{ \     0x4E292F96, 0xD843, 0x4a55, { 0xA8, 0xC2, 0xD4, 0x81, 0xF2, 0x7E, 0xBE, 0xEE } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_MCE_GUID
define|\
value|{ \     0xE8F56FFE, 0x919C, 0x4cc5, { 0xBA, 0x88, 0x65, 0xAB, 0xE1, 0x49, 0x13, 0xBB } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_PCIE_GUID
define|\
value|{ \     0xCF93C01F, 0x1A16, 0x4dfc, { 0xB8, 0xBC, 0x9C, 0x4D, 0xAF, 0x67, 0xC1, 0x04 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_INIT_GUID
define|\
value|{ \     0xCC5263E8, 0x9308, 0x454a, { 0x89, 0xD0, 0x34, 0x0B, 0xD3, 0x9B, 0xC9, 0x8E } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_NMI_GUID
define|\
value|{ \     0x5BAD89FF, 0xB7E6, 0x42c9, { 0x81, 0x4A, 0xCF, 0x24, 0x85, 0xD6, 0xE9, 0x8A } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_BOOT_GUID
define|\
value|{ \     0x3D61A466, 0xAB40, 0x409a, { 0xA6, 0x98, 0xF3, 0x62, 0xD4, 0x64, 0xB3, 0x8F } \   }
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_NOTIFICATION_TYEP_DMAR_GUID
define|\
value|{ \     0x667DD791, 0xC6B3, 0x4c27, { 0x8A, 0x6B, 0x0F, 0x8E, 0x72, 0x2D, 0xEB, 0x41 } \   }
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error Record Header Flags
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_HW_ERROR_FLAGS_RECOVERED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_HW_ERROR_FLAGS_PREVERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_HW_ERROR_FLAGS_SIMULATED
value|0x00000004
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common error record header
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|SignatureStart
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT32
name|SignatureEnd
decl_stmt|;
name|UINT16
name|SectionCount
decl_stmt|;
name|UINT32
name|ErrorSeverity
decl_stmt|;
name|UINT32
name|ValidationBits
decl_stmt|;
name|UINT32
name|RecordLength
decl_stmt|;
name|EFI_ERROR_TIME_STAMP
name|TimeStamp
decl_stmt|;
name|EFI_GUID
name|PlatformID
decl_stmt|;
name|EFI_GUID
name|PartitionID
decl_stmt|;
name|EFI_GUID
name|CreatorID
decl_stmt|;
name|EFI_GUID
name|NotificationType
decl_stmt|;
name|UINT64
name|RecordID
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT64
name|PersistenceInfo
decl_stmt|;
name|UINT8
name|Resv1
index|[
literal|12
index|]
decl_stmt|;
comment|///
comment|/// An array of SectionCount descriptors for the associated
comment|/// sections. The number of valid sections is equivalent to the
comment|/// SectionCount. The buffer size of the record may include
comment|/// more space to dynamically add additional Section
comment|/// Descriptors to the error record.
comment|///
block|}
name|EFI_COMMON_ERROR_RECORD_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_REVISION
value|0x0100
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Validity Fields in Error Section Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FRU_ID_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FRU_STRING_VALID
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Flag field contains information that describes the error section
end_comment

begin_comment
comment|/// in Error Section Descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FLAGS_PRIMARY
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FLAGS_CONTAINMENT_WARNING
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FLAGS_RESET
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FLAGS_ERROR_THRESHOLD_EXCEEDED
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FLAGS_RESOURCE_NOT_ACCESSIBLE
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FLAGS_LATENT_ERROR
value|BIT5
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error Sectition Type GUIDs in Error Section Descriptor
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PROCESSOR_GENERIC_GUID
define|\
value|{ \     0x9876ccad, 0x47b4, 0x4bdb, { 0xb6, 0x5e, 0x16, 0xf1, 0x93, 0xc4, 0xf3, 0xdb } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PROCESSOR_SPECIFIC_GUID
define|\
value|{ \     0xdc3ea0b0, 0xa144, 0x4797, { 0xb9, 0x5b, 0x53, 0xfa, 0x24, 0x2b, 0x6e, 0x1d } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PROCESSOR_SPECIFIC_IA32X64_GUID
define|\
value|{ \     0xdc3ea0b0, 0xa144, 0x4797, { 0xb9, 0x5b, 0x53, 0xfa, 0x24, 0x2b, 0x6e, 0x1d } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PROCESSOR_SPECIFIC_ARM_GUID
define|\
value|{ \     0xe19e3d16, 0xbc11, 0x11e4, { 0x9c, 0xaa, 0xc2, 0x05, 0x1d, 0x5d, 0x46, 0xb0 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PLATFORM_MEMORY_GUID
define|\
value|{ \     0xa5bc1114, 0x6f64, 0x4ede, { 0xb8, 0x63, 0x3e, 0x83, 0xed, 0x7c, 0x83, 0xb1 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PLATFORM_MEMORY2_GUID
define|\
value|{ \     0x61EC04FC, 0x48E6, 0xD813, { 0x25, 0xC9, 0x8D, 0xAA, 0x44, 0x75, 0x0B, 0x12 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PCIE_GUID
define|\
value|{ \     0xd995e954, 0xbbc1, 0x430f, { 0xad, 0x91, 0xb4, 0x4d, 0xcb, 0x3c, 0x6f, 0x35 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_FW_ERROR_RECORD_GUID
define|\
value|{ \     0x81212a96, 0x09ed, 0x4996, { 0x94, 0x71, 0x8d, 0x72, 0x9c, 0x8e, 0x69, 0xed } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PCI_PCIX_BUS_GUID
define|\
value|{ \     0xc5753963, 0x3b84, 0x4095, { 0xbf, 0x78, 0xed, 0xda, 0xd3, 0xf9, 0xc9, 0xdd } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_PCI_DEVICE_GUID
define|\
value|{ \     0xeb5e4685, 0xca66, 0x4769, { 0xb6, 0xa2, 0x26, 0x06, 0x8b, 0x00, 0x13, 0x26 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_DMAR_GENERIC_GUID
define|\
value|{ \     0x5b51fef7, 0xc79d, 0x4434, { 0x8f, 0x1b, 0xaa, 0x62, 0xde, 0x3e, 0x2c, 0x64 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_DIRECTED_IO_DMAR_GUID
define|\
value|{ \     0x71761d37, 0x32b2, 0x45cd, { 0xa7, 0xd0, 0xb0, 0xfe, 0xdd, 0x93, 0xe8, 0xcf } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_SECTION_IOMMU_DMAR_GUID
define|\
value|{ \     0x036f84e1, 0x7f37, 0x428c, { 0xa7, 0x9e, 0x57, 0x5f, 0xdf, 0xaa, 0x84, 0xec } \   }
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error Section Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|SectionOffset
decl_stmt|;
name|UINT32
name|SectionLength
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT8
name|SecValidMask
decl_stmt|;
name|UINT8
name|Resv1
decl_stmt|;
name|UINT32
name|SectionFlags
decl_stmt|;
name|EFI_GUID
name|SectionType
decl_stmt|;
name|EFI_GUID
name|FruId
decl_stmt|;
name|UINT32
name|Severity
decl_stmt|;
name|CHAR8
name|FruString
index|[
literal|20
index|]
decl_stmt|;
block|}
name|EFI_ERROR_SECTION_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates whether or not each of the following fields are
end_comment

begin_comment
comment|/// valid in Proessor Generic Error section.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_TYPE_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ISA_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ERROR_TYPE_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_OPERATION_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_FLAGS_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_LEVEL_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_VERSION_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_BRAND_VALID
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ID_VALID
value|BIT8
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_TARGET_ADDR_VALID
value|BIT9
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_REQUESTER_ID_VALID
value|BIT10
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_RESPONDER_ID_VALID
value|BIT11
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_INST_IP_VALID
value|BIT12
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of the processor architecture in Proessor Generic Error section.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_TYPE_IA32_X64
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_TYPE_IA64
value|0x01
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of the instruction set executing when the error occurred in Proessor
end_comment

begin_comment
comment|/// Generic Error section.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ISA_IA32
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ISA_IA64
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ISA_X64
value|0x02
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of error that occurred in Proessor Generic Error section.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ERROR_TYPE_UNKNOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ERROR_TYPE_CACHE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ERROR_TYPE_TLB
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ERROR_TYPE_BUS
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_ERROR_TYPE_MICRO_ARCH
value|0x08
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of operation in Proessor Generic Error section.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_OPERATION_GENERIC
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_OPERATION_DATA_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_OPERATION_DATA_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_OPERATION_INSTRUCTION_EXEC
value|0x03
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Flags bit mask indicates additional information about the error in Proessor Generic
end_comment

begin_comment
comment|/// Error section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_FLAGS_RESTARTABLE
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_FLAGS_PRECISE_IP
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_FLAGS_OVERFLOW
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_GENERIC_ERROR_PROC_FLAGS_CORRECTED
value|BIT3
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Generic Error Section
end_comment

begin_comment
comment|/// describes processor reported hardware errors for logical processors in the system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Isa
decl_stmt|;
name|UINT8
name|ErrorType
decl_stmt|;
name|UINT8
name|Operation
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Level
decl_stmt|;
name|UINT16
name|Resv1
decl_stmt|;
name|UINT64
name|VersionInfo
decl_stmt|;
name|CHAR8
name|BrandString
index|[
literal|128
index|]
decl_stmt|;
name|UINT64
name|ApicId
decl_stmt|;
name|UINT64
name|TargetAddr
decl_stmt|;
name|UINT64
name|RequestorId
decl_stmt|;
name|UINT64
name|ResponderId
decl_stmt|;
name|UINT64
name|InstructionIP
decl_stmt|;
block|}
name|EFI_PROCESSOR_GENERIC_ERROR_DATA
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
operator|||
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32 and x64 Specific definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID value indicating the type of Processor Error Information structure
end_comment

begin_comment
comment|/// in IA32/X64 Processor Error Information Structure.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_TYPE_CACHE_CHECK_GUID
define|\
value|{ \     0xA55701F5, 0xE3EF, 0x43de, {0xAC, 0x72, 0x24, 0x9B, 0x57, 0x3F, 0xAD, 0x2C } \   }
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_TYPE_TLB_CHECK_GUID
define|\
value|{ \     0xFC06B535, 0x5E1F, 0x4562, {0x9F, 0x25, 0x0A, 0x3B, 0x9A, 0xDB, 0x63, 0xC3 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_TYPE_BUS_CHECK_GUID
define|\
value|{ \     0x1CF3F8B3, 0xC5B1, 0x49a2, {0xAA, 0x59, 0x5E, 0xEF, 0x92, 0xFF, 0xA6, 0x3C } \   }
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_TYPE_MS_CHECK_GUID
define|\
value|{ \     0x48AB7F57, 0xDC34, 0x4f6c, {0xA7, 0xD3, 0xB0, 0xB5, 0xB0, 0xA7, 0x43, 0x14 } \   }
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates which fields in the IA32/X64 Processor
end_comment

begin_comment
comment|/// Error Record structure are valid.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IA32_X64_PROCESSOR_ERROR_APIC_ID_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_PROCESSOR_ERROR_CPU_ID_INFO_VALID
value|BIT1
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 Processor Error Record
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
decl_stmt|;
name|UINT64
name|ApicId
decl_stmt|;
name|UINT8
name|CpuIdInfo
index|[
literal|48
index|]
decl_stmt|;
block|}
name|EFI_IA32_X64_PROCESSOR_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates which fields in the Cache Check structure
end_comment

begin_comment
comment|/// are valid.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_TRANSACTION_TYPE_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_LEVEL_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_CONTEXT_CORRUPT_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_UNCORRECTED_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_PRECISE_IP_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_RESTARTABLE_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OVERFLOW_VALID
value|BIT7
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of cache error in the Cache Check structure
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_ERROR_TYPE_INSTRUCTION
value|0
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_ERROR_TYPE_DATA_ACCESS
value|1
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_ERROR_TYPE_GENERIC
value|2
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of cache operation that caused the error in the Cache
end_comment

begin_comment
comment|/// Check structure
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_GENERIC_READ
value|1
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_GENERIC_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_DATA_READ
value|3
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_DATA_WRITE
value|4
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_INSTRUCTION_FETCH
value|5
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_PREFETCH
value|6
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_EVICTION
value|7
end_define

begin_define
define|#
directive|define
name|EFI_CACHE_CHECK_OPERATION_TYPE_SNOOP
value|8
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 Cache Check Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
range|:
literal|16
decl_stmt|;
name|UINT64
name|TransactionType
range|:
literal|2
decl_stmt|;
name|UINT64
name|Operation
range|:
literal|4
decl_stmt|;
name|UINT64
name|Level
range|:
literal|3
decl_stmt|;
name|UINT64
name|ContextCorrupt
range|:
literal|1
decl_stmt|;
name|UINT64
name|ErrorUncorrected
range|:
literal|1
decl_stmt|;
name|UINT64
name|PreciseIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|RestartableIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|Overflow
range|:
literal|1
decl_stmt|;
name|UINT64
name|Resv1
range|:
literal|34
decl_stmt|;
block|}
name|EFI_IA32_X64_CACHE_CHECK_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates which fields in the TLB Check structure
end_comment

begin_comment
comment|/// are valid.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_TRANSACTION_TYPE_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_LEVEL_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_CONTEXT_CORRUPT_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_UNCORRECTED_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_PRECISE_IP_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_RESTARTABLE_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OVERFLOW_VALID
value|BIT7
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of cache error in the TLB Check structure
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_ERROR_TYPE_INSTRUCTION
value|0
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_ERROR_TYPE_DATA_ACCESS
value|1
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_ERROR_TYPE_GENERIC
value|2
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of cache operation that caused the error in the TLB
end_comment

begin_comment
comment|/// Check structure
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_TYPE_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_TYPE_GENERIC_READ
value|1
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_TYPE_GENERIC_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_TYPE_DATA_READ
value|3
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_TYPE_DATA_WRITE
value|4
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_TYPE_INST_FETCH
value|5
end_define

begin_define
define|#
directive|define
name|EFI_TLB_CHECK_OPERATION_TYPE_PREFETCH
value|6
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 TLB Check Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
range|:
literal|16
decl_stmt|;
name|UINT64
name|TransactionType
range|:
literal|2
decl_stmt|;
name|UINT64
name|Operation
range|:
literal|4
decl_stmt|;
name|UINT64
name|Level
range|:
literal|3
decl_stmt|;
name|UINT64
name|ContextCorrupt
range|:
literal|1
decl_stmt|;
name|UINT64
name|ErrorUncorrected
range|:
literal|1
decl_stmt|;
name|UINT64
name|PreciseIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|RestartableIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|Overflow
range|:
literal|1
decl_stmt|;
name|UINT64
name|Resv1
range|:
literal|34
decl_stmt|;
block|}
name|EFI_IA32_X64_TLB_CHECK_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates which fields in the MS Check structure
end_comment

begin_comment
comment|/// are valid.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_TRANSACTION_TYPE_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_LEVEL_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_CONTEXT_CORRUPT_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_UNCORRECTED_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_PRECISE_IP_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_RESTARTABLE_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OVERFLOW_VALID
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_PARTICIPATION_TYPE_VALID
value|BIT8
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_TIME_OUT_VALID
value|BIT9
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ADDRESS_SPACE_VALID
value|BIT10
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of cache error in the Bus Check structure
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ERROR_TYPE_INSTRUCTION
value|0
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ERROR_TYPE_DATA_ACCESS
value|1
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ERROR_TYPE_GENERIC
value|2
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of cache operation that caused the error in the Bus
end_comment

begin_comment
comment|/// Check structure
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_TYPE_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_TYPE_GENERIC_READ
value|1
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_TYPE_GENERIC_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_TYPE_DATA_READ
value|3
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_TYPE_DATA_WRITE
value|4
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_TYPE_INST_FETCH
value|5
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_OPERATION_TYPE_PREFETCH
value|6
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of Participation
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_PARTICIPATION_TYPE_REQUEST
value|0
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_PARTICIPATION_TYPE_RESPONDED
value|1
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_PARTICIPATION_TYPE_OBSERVED
value|2
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_PARTICIPATION_TYPE_GENERIC
value|3
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type of Address Space
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ADDRESS_SPACE_TYPE_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ADDRESS_SPACE_TYPE_RESERVED
value|1
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ADDRESS_SPACE_TYPE_IO
value|2
end_define

begin_define
define|#
directive|define
name|EFI_BUS_CHECK_ADDRESS_SPACE_TYPE_OTHER
value|3
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 Bus Check Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
range|:
literal|16
decl_stmt|;
name|UINT64
name|TransactionType
range|:
literal|2
decl_stmt|;
name|UINT64
name|Operation
range|:
literal|4
decl_stmt|;
name|UINT64
name|Level
range|:
literal|3
decl_stmt|;
name|UINT64
name|ContextCorrupt
range|:
literal|1
decl_stmt|;
name|UINT64
name|ErrorUncorrected
range|:
literal|1
decl_stmt|;
name|UINT64
name|PreciseIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|RestartableIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|Overflow
range|:
literal|1
decl_stmt|;
name|UINT64
name|ParticipationType
range|:
literal|2
decl_stmt|;
name|UINT64
name|TimeOut
range|:
literal|1
decl_stmt|;
name|UINT64
name|AddressSpace
range|:
literal|2
decl_stmt|;
name|UINT64
name|Resv1
range|:
literal|29
decl_stmt|;
block|}
name|EFI_IA32_X64_BUS_CHECK_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates which fields in the MS Check structure
end_comment

begin_comment
comment|/// are valid.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_MS_CHECK_ERROR_TYPE_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_CONTEXT_CORRUPT_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_UNCORRECTED_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_PRECISE_IP_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_RESTARTABLE_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_OVERFLOW_VALID
value|BIT5
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error type identifies the operation that caused the error.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_MS_CHECK_ERROR_TYPE_NO
value|0
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_ERROR_TYPE_UNCLASSIFIED
value|1
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_ERROR_TYPE_MICROCODE_PARITY
value|2
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_ERROR_TYPE_EXTERNAL
value|3
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_ERROR_TYPE_FRC
value|4
end_define

begin_define
define|#
directive|define
name|EFI_MS_CHECK_ERROR_TYPE_INTERNAL_UNCLASSIFIED
value|5
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 MS Check Field Description
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
range|:
literal|16
decl_stmt|;
name|UINT64
name|ErrorType
range|:
literal|3
decl_stmt|;
name|UINT64
name|ContextCorrupt
range|:
literal|1
decl_stmt|;
name|UINT64
name|ErrorUncorrected
range|:
literal|1
decl_stmt|;
name|UINT64
name|PreciseIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|RestartableIp
range|:
literal|1
decl_stmt|;
name|UINT64
name|Overflow
range|:
literal|1
decl_stmt|;
name|UINT64
name|Resv1
range|:
literal|40
decl_stmt|;
block|}
name|EFI_IA32_X64_MS_CHECK_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 Check Information Item
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_IA32_X64_CACHE_CHECK_INFO
name|CacheCheck
decl_stmt|;
name|EFI_IA32_X64_TLB_CHECK_INFO
name|TlbCheck
decl_stmt|;
name|EFI_IA32_X64_BUS_CHECK_INFO
name|BusCheck
decl_stmt|;
name|EFI_IA32_X64_MS_CHECK_INFO
name|MsCheck
decl_stmt|;
name|UINT64
name|Data64
decl_stmt|;
block|}
name|EFI_IA32_X64_CHECK_INFO_ITEM
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates which fields in the IA32/X64 Processor Error
end_comment

begin_comment
comment|/// Information Structure are valid.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_PROC_CHECK_INFO_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_PROC_TARGET_ADDR_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_PROC_REQUESTER_ID_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_PROC_RESPONDER_ID_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_IA32_X64_ERROR_PROC_INST_IP_VALID
value|BIT4
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 Processor Error Information Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_GUID
name|ErrorType
decl_stmt|;
name|UINT64
name|ValidFields
decl_stmt|;
name|EFI_IA32_X64_CHECK_INFO_ITEM
name|CheckInfo
decl_stmt|;
name|UINT64
name|TargetId
decl_stmt|;
name|UINT64
name|RequestorId
decl_stmt|;
name|UINT64
name|ResponderId
decl_stmt|;
name|UINT64
name|InstructionIP
decl_stmt|;
block|}
name|EFI_IA32_X64_PROCESS_ERROR_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32/X64 Processor Context Information Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|RegisterType
decl_stmt|;
name|UINT16
name|ArraySize
decl_stmt|;
name|UINT32
name|MsrAddress
decl_stmt|;
name|UINT64
name|MmRegisterAddress
decl_stmt|;
comment|//
comment|// This field will provide the contents of the actual registers or raw data.
comment|// The number of Registers or size of the raw data reported is determined
comment|// by (Array Size / 8) or otherwise specified by the context structure type
comment|// definition.
comment|//
block|}
name|EFI_IA32_X64_PROCESSOR_CONTEXT_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Register Context Type
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_UNCLASSIFIED
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_MSR
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_IA32
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_X64
value|0x0003
end_define

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_FXSAVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_DR_IA32
value|0x0005
end_define

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_DR_X64
value|0x0006
end_define

begin_define
define|#
directive|define
name|EFI_REG_CONTEXT_TYPE_MEM_MAP
value|0x0007
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32 Register State
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Eax
decl_stmt|;
name|UINT32
name|Ebx
decl_stmt|;
name|UINT32
name|Ecx
decl_stmt|;
name|UINT32
name|Edx
decl_stmt|;
name|UINT32
name|Esi
decl_stmt|;
name|UINT32
name|Edi
decl_stmt|;
name|UINT32
name|Ebp
decl_stmt|;
name|UINT32
name|Esp
decl_stmt|;
name|UINT16
name|Cs
decl_stmt|;
name|UINT16
name|Ds
decl_stmt|;
name|UINT16
name|Ss
decl_stmt|;
name|UINT16
name|Es
decl_stmt|;
name|UINT16
name|Fs
decl_stmt|;
name|UINT16
name|Gs
decl_stmt|;
name|UINT32
name|Eflags
decl_stmt|;
name|UINT32
name|Eip
decl_stmt|;
name|UINT32
name|Cr0
decl_stmt|;
name|UINT32
name|Cr1
decl_stmt|;
name|UINT32
name|Cr2
decl_stmt|;
name|UINT32
name|Cr3
decl_stmt|;
name|UINT32
name|Cr4
decl_stmt|;
name|UINT32
name|Gdtr
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|Idtr
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|Ldtr
decl_stmt|;
name|UINT16
name|Tr
decl_stmt|;
block|}
name|EFI_CONTEXT_IA32_REGISTER_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// X64 Register State
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Rax
decl_stmt|;
name|UINT64
name|Rbx
decl_stmt|;
name|UINT64
name|Rcx
decl_stmt|;
name|UINT64
name|Rdx
decl_stmt|;
name|UINT64
name|Rsi
decl_stmt|;
name|UINT64
name|Rdi
decl_stmt|;
name|UINT64
name|Rbp
decl_stmt|;
name|UINT64
name|Rsp
decl_stmt|;
name|UINT64
name|R8
decl_stmt|;
name|UINT64
name|R9
decl_stmt|;
name|UINT64
name|R10
decl_stmt|;
name|UINT64
name|R11
decl_stmt|;
name|UINT64
name|R12
decl_stmt|;
name|UINT64
name|R13
decl_stmt|;
name|UINT64
name|R14
decl_stmt|;
name|UINT64
name|R15
decl_stmt|;
name|UINT16
name|Cs
decl_stmt|;
name|UINT16
name|Ds
decl_stmt|;
name|UINT16
name|Ss
decl_stmt|;
name|UINT16
name|Es
decl_stmt|;
name|UINT16
name|Fs
decl_stmt|;
name|UINT16
name|Gs
decl_stmt|;
name|UINT32
name|Resv1
decl_stmt|;
name|UINT64
name|Rflags
decl_stmt|;
name|UINT64
name|Rip
decl_stmt|;
name|UINT64
name|Cr0
decl_stmt|;
name|UINT64
name|Cr1
decl_stmt|;
name|UINT64
name|Cr2
decl_stmt|;
name|UINT64
name|Cr3
decl_stmt|;
name|UINT64
name|Cr4
decl_stmt|;
name|UINT64
name|Gdtr
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|Idtr
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|Ldtr
decl_stmt|;
name|UINT16
name|Tr
decl_stmt|;
block|}
name|EFI_CONTEXT_X64_REGISTER_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The validation bit mask indicates each of the following field is in IA32/X64
end_comment

begin_comment
comment|/// Processor Error Section.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ApicIdValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|CpuIdInforValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|ErrorInfoNum
range|:
literal|6
decl_stmt|;
name|UINT64
name|ContextNum
range|:
literal|6
decl_stmt|;
name|UINT64
name|Resv1
range|:
literal|50
decl_stmt|;
block|}
name|EFI_IA32_X64_VALID_BITS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error Status Fields
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Resv1
range|:
literal|8
decl_stmt|;
name|UINT64
name|Type
range|:
literal|8
decl_stmt|;
name|UINT64
name|AddressSignal
range|:
literal|1
decl_stmt|;
comment|///< Error in Address signals or in Address portion of transaction
name|UINT64
name|ControlSignal
range|:
literal|1
decl_stmt|;
comment|///< Error in Control signals or in Control portion of transaction
name|UINT64
name|DataSignal
range|:
literal|1
decl_stmt|;
comment|///< Error in Data signals or in Data portion of transaction
name|UINT64
name|DetectedByResponder
range|:
literal|1
decl_stmt|;
comment|///< Error detected by responder
name|UINT64
name|DetectedByRequester
range|:
literal|1
decl_stmt|;
comment|///< Error detected by requestor
name|UINT64
name|FirstError
range|:
literal|1
decl_stmt|;
comment|///< First Error in the sequence - option field
name|UINT64
name|OverflowNotLogged
range|:
literal|1
decl_stmt|;
comment|///< Additional errors were not logged due to lack of resources
name|UINT64
name|Resv2
range|:
literal|41
decl_stmt|;
block|}
name|EFI_GENERIC_ERROR_STATUS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error Type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// General Internal errors
comment|///
name|ErrorInternal
init|=
literal|1
block|,
name|ErrorBus
init|=
literal|16
block|,
comment|///
comment|/// Component Internal errors
comment|///
name|ErrorMemStorage
init|=
literal|4
block|,
comment|// Error in memory device
name|ErrorTlbStorage
init|=
literal|5
block|,
comment|// TLB error in cache
name|ErrorCacheStorage
init|=
literal|6
block|,
name|ErrorFunctionalUnit
init|=
literal|7
block|,
name|ErrorSelftest
init|=
literal|8
block|,
name|ErrorOverflow
init|=
literal|9
block|,
comment|///
comment|/// Bus internal errors
comment|///
name|ErrorVirtualMap
init|=
literal|17
block|,
name|ErrorAccessInvalid
init|=
literal|18
block|,
comment|// Improper access
name|ErrorUnimplAccess
init|=
literal|19
block|,
comment|// Unimplemented memory access
name|ErrorLossOfLockstep
init|=
literal|20
block|,
name|ErrorResponseInvalid
init|=
literal|21
block|,
comment|// Response not associated with request
name|ErrorParity
init|=
literal|22
block|,
name|ErrorProtocol
init|=
literal|23
block|,
name|ErrorPath
init|=
literal|24
block|,
comment|// Detected path error
name|ErrorTimeout
init|=
literal|25
block|,
comment|// Bus timeout
name|ErrorPoisoned
init|=
literal|26
comment|// Read data poisoned
block|}
name|EFI_GENERIC_ERROR_STATUS_ERROR_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Validation bit mask indicates which fields in the memory error record are valid
end_comment

begin_comment
comment|/// in Memory Error section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_STATUS_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_PHY_ADDRESS_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_PHY_ADDRESS_MASK_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_NODE_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_CARD_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_MODULE_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_BANK_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_DEVICE_VALID
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ROW_VALID
value|BIT8
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_COLUMN_VALID
value|BIT9
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_BIT_POS_VALID
value|BIT10
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_REQUESTOR_ID_VALID
value|BIT11
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_RESPONDER_ID_VALID
value|BIT12
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_TARGET_ID_VALID
value|BIT13
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_TYPE_VALID
value|BIT14
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_RANK_NUM_VALID
value|BIT15
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_CARD_HANDLE_VALID
value|BIT16
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_MODULE_HANDLE_VALID
value|BIT17
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_EXTENDED_ROW_BIT_16_17_VALID
value|BIT18
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_BANK_GROUP_VALID
value|BIT19
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_BANK_ADDRESS_VALID
value|BIT20
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_CHIP_IDENTIFICATION_VALID
value|BIT21
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Type identifies the type of error that occurred in Memory
end_comment

begin_comment
comment|/// Error section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_UNKNOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_NONE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_SINGLEBIT_ECC
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_MLTIBIT_ECC
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_SINGLESYMBOLS_CHIPKILL
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_MULTISYMBOL_CHIPKILL
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_MATER_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_TARGET_ABORT
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_PARITY
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_WDT
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_INVALID_ADDRESS
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_MIRROR_FAILED
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_SPARING
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_SCRUB_CORRECTED
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_SCRUB_UNCORRECTED
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY_ERROR_MEMORY_MAP_EVENT
value|0x0F
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Section
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
decl_stmt|;
name|EFI_GENERIC_ERROR_STATUS
name|ErrorStatus
decl_stmt|;
name|UINT64
name|PhysicalAddress
decl_stmt|;
comment|// Error physical address
name|UINT64
name|PhysicalAddressMask
decl_stmt|;
comment|// Grnaularity
name|UINT16
name|Node
decl_stmt|;
comment|// Node #
name|UINT16
name|Card
decl_stmt|;
name|UINT16
name|ModuleRank
decl_stmt|;
comment|// Module or Rank#
name|UINT16
name|Bank
decl_stmt|;
name|UINT16
name|Device
decl_stmt|;
name|UINT16
name|Row
decl_stmt|;
name|UINT16
name|Column
decl_stmt|;
name|UINT16
name|BitPosition
decl_stmt|;
name|UINT64
name|RequestorId
decl_stmt|;
name|UINT64
name|ResponderId
decl_stmt|;
name|UINT64
name|TargetId
decl_stmt|;
name|UINT8
name|ErrorType
decl_stmt|;
name|UINT8
name|Extended
decl_stmt|;
name|UINT16
name|RankNum
decl_stmt|;
name|UINT16
name|CardHandle
decl_stmt|;
name|UINT16
name|ModuleHandle
decl_stmt|;
block|}
name|EFI_PLATFORM_MEMORY_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Validation bit mask indicates which fields in the memory error record 2 are valid
end_comment

begin_comment
comment|/// in Memory Error section 2
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_STATUS_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_PHY_ADDRESS_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_PHY_ADDRESS_MASK_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_NODE_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_CARD_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_MODULE_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_BANK_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_DEVICE_VALID
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ROW_VALID
value|BIT8
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_COLUMN_VALID
value|BIT9
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_RANK_VALID
value|BIT10
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_BIT_POS_VALID
value|BIT11
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_CHIP_ID_VALID
value|BIT12
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_MEMORY_ERROR_TYPE_VALID
value|BIT13
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_STATUS_VALID
value|BIT14
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_REQUESTOR_ID_VALID
value|BIT15
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_RESPONDER_ID_VALID
value|BIT16
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_TARGET_ID_VALID
value|BIT17
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_CARD_HANDLE_VALID
value|BIT18
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_MODULE_HANDLE_VALID
value|BIT19
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_BANK_GROUP_VALID
value|BIT20
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_BANK_ADDRESS_VALID
value|BIT21
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Type identifies the type of error that occurred in Memory
end_comment

begin_comment
comment|/// Error section 2
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_UNKNOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_NONE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_SINGLEBIT_ECC
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_MLTIBIT_ECC
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_SINGLESYMBOL_CHIPKILL
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_MULTISYMBOL_CHIPKILL
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_MASTER_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_TARGET_ABORT
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_PARITY
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_WDT
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_INVALID_ADDRESS
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_MIRROR_BROKEN
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_MEMORY_SPARING
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_SCRUB_CORRECTED
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_SCRUB_UNCORRECTED
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_MEMORY2_ERROR_MEMORY_MAP_EVENT
value|0x0F
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Section 2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
decl_stmt|;
name|EFI_GENERIC_ERROR_STATUS
name|ErrorStatus
decl_stmt|;
name|UINT64
name|PhysicalAddress
decl_stmt|;
comment|// Error physical address
name|UINT64
name|PhysicalAddressMask
decl_stmt|;
comment|// Grnaularity
name|UINT16
name|Node
decl_stmt|;
comment|// Node #
name|UINT16
name|Card
decl_stmt|;
name|UINT16
name|Module
decl_stmt|;
comment|// Module or Rank#
name|UINT16
name|Bank
decl_stmt|;
name|UINT32
name|Device
decl_stmt|;
name|UINT32
name|Row
decl_stmt|;
name|UINT32
name|Column
decl_stmt|;
name|UINT32
name|Rank
decl_stmt|;
name|UINT32
name|BitPosition
decl_stmt|;
name|UINT8
name|ChipId
decl_stmt|;
name|UINT8
name|MemErrorType
decl_stmt|;
name|UINT8
name|Status
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|RequestorId
decl_stmt|;
name|UINT64
name|ResponderId
decl_stmt|;
name|UINT64
name|TargetId
decl_stmt|;
name|UINT32
name|CardHandle
decl_stmt|;
name|UINT32
name|ModuleHandle
decl_stmt|;
block|}
name|EFI_PLATFORM_MEMORY2_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Validation bits mask indicates which of the following fields is valid
end_comment

begin_comment
comment|/// in PCI Express Error Record.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_TYPE_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_VERSION_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_COMMAND_STATUS_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_DEVICE_ID_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_SERIAL_NO_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_BRIDGE_CRL_STS_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_CAPABILITY_INFO_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_AER_INFO_VALID
value|BIT7
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCIe Device/Port Type as defined in the PCI Express capabilities register
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_PCIE_ENDPOINT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_PCI_ENDPOINT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_ROOT_PORT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_UPSWITCH_PORT
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_DOWNSWITCH_PORT
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_PCIE_TO_PCI_BRIDGE
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_PCI_TO_PCIE_BRIDGE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_ROOT_INT_ENDPOINT
value|0x00000009
end_define

begin_define
define|#
directive|define
name|EFI_PCIE_ERROR_PORT_ROOT_EVENT_COLLECTOR
value|0x0000000A
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Slot number
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Resv1
range|:
literal|3
decl_stmt|;
name|UINT16
name|Number
range|:
literal|13
decl_stmt|;
block|}
name|EFI_GENERIC_ERROR_PCI_SLOT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCIe Root Port PCI/bridge PCI compatible device number and
end_comment

begin_comment
comment|/// bus number information to uniquely identify the root port or
end_comment

begin_comment
comment|/// bridge. Default values for both the bus numbers is zero.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT8
name|ClassCode
index|[
literal|3
index|]
decl_stmt|;
name|UINT8
name|Function
decl_stmt|;
name|UINT8
name|Device
decl_stmt|;
name|UINT16
name|Segment
decl_stmt|;
name|UINT8
name|PrimaryOrDeviceBus
decl_stmt|;
name|UINT8
name|SecondaryBus
decl_stmt|;
name|EFI_GENERIC_ERROR_PCI_SLOT
name|Slot
decl_stmt|;
name|UINT8
name|Resv1
decl_stmt|;
block|}
name|EFI_GENERIC_ERROR_PCIE_DEV_BRIDGE_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCIe Capability Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|PcieCap
index|[
literal|60
index|]
decl_stmt|;
block|}
name|EFI_PCIE_ERROR_DATA_CAPABILITY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCIe Advanced Error Reporting Extended Capability Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|PcieAer
index|[
literal|96
index|]
decl_stmt|;
block|}
name|EFI_PCIE_ERROR_DATA_AER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Express Error Record
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
decl_stmt|;
name|UINT32
name|PortType
decl_stmt|;
name|UINT32
name|Version
decl_stmt|;
name|UINT32
name|CommandStatus
decl_stmt|;
name|UINT32
name|Resv2
decl_stmt|;
name|EFI_GENERIC_ERROR_PCIE_DEV_BRIDGE_ID
name|DevBridge
decl_stmt|;
name|UINT64
name|SerialNo
decl_stmt|;
name|UINT32
name|BridgeControlStatus
decl_stmt|;
name|EFI_PCIE_ERROR_DATA_CAPABILITY
name|Capability
decl_stmt|;
name|EFI_PCIE_ERROR_DATA_AER
name|AerInfo
decl_stmt|;
block|}
name|EFI_PCIE_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Validation bits Indicates which of the following fields is valid
end_comment

begin_comment
comment|/// in PCI/PCI-X Bus Error Section.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_STATUS_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_TYPE_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_BUS_ID_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_BUS_ADDRESS_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_BUS_DATA_VALID
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_COMMAND_VALID
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_REQUESTOR_ID_VALID
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_COMPLETER_ID_VALID
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_TARGET_ID_VALID
value|BIT8
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Bus Error Type in PCI/PCI-X Bus Error Section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_UNKNOWN
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_DATA_PARITY
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_SYSTEM
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_MASTER_ABORT
value|0x0003
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_BUS_TIMEOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_MASTER_DATA_PARITY
value|0x0005
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_ADDRESS_PARITY
value|0x0006
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_BUS_ERROR_COMMAND_PARITY
value|0x0007
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI/PCI-X Bus Error Section
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFields
decl_stmt|;
name|EFI_GENERIC_ERROR_STATUS
name|ErrorStatus
decl_stmt|;
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|BusId
decl_stmt|;
name|UINT32
name|Resv2
decl_stmt|;
name|UINT64
name|BusAddress
decl_stmt|;
name|UINT64
name|BusData
decl_stmt|;
name|UINT64
name|BusCommand
decl_stmt|;
name|UINT64
name|RequestorId
decl_stmt|;
name|UINT64
name|ResponderId
decl_stmt|;
name|UINT64
name|TargetId
decl_stmt|;
block|}
name|EFI_PCI_PCIX_BUS_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Validation bits Indicates which of the following fields is valid
end_comment

begin_comment
comment|/// in PCI/PCI-X Component Error Section.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_DEVICE_ERROR_STATUS_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_DEVICE_ERROR_ID_INFO_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_DEVICE_ERROR_MEM_NUM_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_DEVICE_ERROR_IO_NUM_VALID
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_PCI_PCIX_DEVICE_ERROR_REG_DATA_PAIR_VALID
value|BIT4
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI/PCI-X Device Identification Information
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT8
name|ClassCode
index|[
literal|3
index|]
decl_stmt|;
name|UINT8
name|Function
decl_stmt|;
name|UINT8
name|Device
decl_stmt|;
name|UINT8
name|Bus
decl_stmt|;
name|UINT8
name|Segment
decl_stmt|;
name|UINT8
name|Resv1
decl_stmt|;
name|UINT32
name|Resv2
decl_stmt|;
block|}
name|EFI_GENERIC_ERROR_PCI_DEVICE_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Identifies the type of firmware error record
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FIRMWARE_ERROR_TYPE_IPF_SAL
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware Error Record Section
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ErrorType
decl_stmt|;
name|UINT8
name|Resv1
index|[
literal|7
index|]
decl_stmt|;
name|UINT64
name|RecordId
decl_stmt|;
block|}
name|EFI_FIRMWARE_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fault Reason in DMAr Generic Error Section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_TABLE_ENTRY_NOT_PRESENT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_TABLE_ENTRY_INVALID
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_ACCESS_MAPPING_TABLE_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_RESV_BIT_ERROR_IN_MAPPING_TABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_ACCESS_ADDR_OUT_OF_SPACE
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_INVALID_ACCESS
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_INVALID_REQUEST
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_ACCESS_TRANSLATE_TABLE_ERROR
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_RESV_BIT_ERROR_IN_TRANSLATE_TABLE
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_INVALID_COMMAOND
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_DMA_FAULT_REASON_ACCESS_COMMAND_BUFFER_ERROR
value|0x0B
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DMA access type in DMAr Generic Error Section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_DMA_ACCESS_TYPE_READ
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_DMA_ACCESS_TYPE_WRITE
value|0x01
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DMA address type in DMAr Generic Error Section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_DMA_ADDRESS_UNTRANSLATED
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_DMA_ADDRESS_TRANSLATION
value|0x01
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Architecture type in DMAr Generic Error Section
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_DMA_ARCH_TYPE_VT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_DMA_ARCH_TYPE_IOMMU
value|0x02
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DMAr Generic Error Section
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|RequesterId
decl_stmt|;
name|UINT16
name|SegmentNumber
decl_stmt|;
name|UINT8
name|FaultReason
decl_stmt|;
name|UINT8
name|AccessType
decl_stmt|;
name|UINT8
name|AddressType
decl_stmt|;
name|UINT8
name|ArchType
decl_stmt|;
name|UINT64
name|DeviceAddr
decl_stmt|;
name|UINT8
name|Resv1
index|[
literal|16
index|]
decl_stmt|;
block|}
name|EFI_DMAR_GENERIC_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Intel VT for Directed I/O specific DMAr Errors
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Version
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|OemId
index|[
literal|6
index|]
decl_stmt|;
name|UINT64
name|Capability
decl_stmt|;
name|UINT64
name|CapabilityEx
decl_stmt|;
name|UINT32
name|GlobalCommand
decl_stmt|;
name|UINT32
name|GlobalStatus
decl_stmt|;
name|UINT32
name|FaultStatus
decl_stmt|;
name|UINT8
name|Resv1
index|[
literal|12
index|]
decl_stmt|;
name|UINT64
name|FaultRecord
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|RootEntry
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|ContextEntry
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|PteL6
decl_stmt|;
name|UINT64
name|PteL5
decl_stmt|;
name|UINT64
name|PteL4
decl_stmt|;
name|UINT64
name|PteL3
decl_stmt|;
name|UINT64
name|PteL2
decl_stmt|;
name|UINT64
name|PteL1
decl_stmt|;
block|}
name|EFI_DIRECTED_IO_DMAR_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IOMMU specific DMAr Errors
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|Resv1
index|[
literal|7
index|]
decl_stmt|;
name|UINT64
name|Control
decl_stmt|;
name|UINT64
name|Status
decl_stmt|;
name|UINT8
name|Resv2
index|[
literal|8
index|]
decl_stmt|;
name|UINT64
name|EventLogEntry
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|Resv3
index|[
literal|16
index|]
decl_stmt|;
name|UINT64
name|DeviceTableEntry
index|[
literal|4
index|]
decl_stmt|;
name|UINT64
name|PteL6
decl_stmt|;
name|UINT64
name|PteL5
decl_stmt|;
name|UINT64
name|PteL4
decl_stmt|;
name|UINT64
name|PteL3
decl_stmt|;
name|UINT64
name|PteL2
decl_stmt|;
name|UINT64
name|PteL1
decl_stmt|;
block|}
name|EFI_IOMMU_DMAR_ERROR_DATA
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypeCmcGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypeCpeGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypeMceGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypePcieGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypeInitGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypeNmiGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypeBootGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventNotificationTypeDmarGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiProcessorGenericErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiProcessorSpecificErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIa32X64ProcessorErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiArmProcessorErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPlatformMemoryErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPlatformMemory2ErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPcieErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFirmwareErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciBusErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciDevErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDMArGenericErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDirectedIoDMArErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIommuDMArErrorSectionGuid
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
operator|||
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA32 and x64 Specific definitions.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIa32X64ErrorTypeCacheCheckGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIa32X64ErrorTypeTlbCheckGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIa32X64ErrorTypeBusCheckGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIa32X64ErrorTypeMsCheckGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

