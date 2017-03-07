begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This includes some definitions introduced in UEFI that will be used in both PEI and DXE phases.  Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_MULTIPHASE_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_MULTIPHASE_H__
end_define

begin_include
include|#
directive|include
file|<Guid/WinCertificate.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of memory types introduced in UEFI.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Not used.
comment|///
name|EfiReservedMemoryType
block|,
comment|///
comment|/// The code portions of a loaded application.
comment|/// (Note that UEFI OS loaders are UEFI applications.)
comment|///
name|EfiLoaderCode
block|,
comment|///
comment|/// The data portions of a loaded application and the default data allocation
comment|/// type used by an application to allocate pool memory.
comment|///
name|EfiLoaderData
block|,
comment|///
comment|/// The code portions of a loaded Boot Services Driver.
comment|///
name|EfiBootServicesCode
block|,
comment|///
comment|/// The data portions of a loaded Boot Serves Driver, and the default data
comment|/// allocation type used by a Boot Services Driver to allocate pool memory.
comment|///
name|EfiBootServicesData
block|,
comment|///
comment|/// The code portions of a loaded Runtime Services Driver.
comment|///
name|EfiRuntimeServicesCode
block|,
comment|///
comment|/// The data portions of a loaded Runtime Services Driver and the default
comment|/// data allocation type used by a Runtime Services Driver to allocate pool memory.
comment|///
name|EfiRuntimeServicesData
block|,
comment|///
comment|/// Free (unallocated) memory.
comment|///
name|EfiConventionalMemory
block|,
comment|///
comment|/// Memory in which errors have been detected.
comment|///
name|EfiUnusableMemory
block|,
comment|///
comment|/// Memory that holds the ACPI tables.
comment|///
name|EfiACPIReclaimMemory
block|,
comment|///
comment|/// Address space reserved for use by the firmware.
comment|///
name|EfiACPIMemoryNVS
block|,
comment|///
comment|/// Used by system firmware to request that a memory-mapped IO region
comment|/// be mapped by the OS to a virtual address so it can be accessed by EFI runtime services.
comment|///
name|EfiMemoryMappedIO
block|,
comment|///
comment|/// System memory-mapped IO region that is used to translate memory
comment|/// cycles to IO cycles by the processor.
comment|///
name|EfiMemoryMappedIOPortSpace
block|,
comment|///
comment|/// Address space reserved by the firmware for code that is part of the processor.
comment|///
name|EfiPalCode
block|,
comment|///
comment|/// A memory region that operates as EfiConventionalMemory,
comment|/// however it happens to also support byte-addressable non-volatility.
comment|///
name|EfiPersistentMemory
block|,
name|EfiMaxMemoryType
block|}
name|EFI_MEMORY_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of reset types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Used to induce a system-wide reset. This sets all circuitry within the
comment|/// system to its initial state.  This type of reset is asynchronous to system
comment|/// operation and operates withgout regard to cycle boundaries.  EfiColdReset
comment|/// is tantamount to a system power cycle.
comment|///
name|EfiResetCold
block|,
comment|///
comment|/// Used to induce a system-wide initialization. The processors are set to their
comment|/// initial state, and pending cycles are not corrupted.  If the system does
comment|/// not support this reset type, then an EfiResetCold must be performed.
comment|///
name|EfiResetWarm
block|,
comment|///
comment|/// Used to induce an entry into a power state equivalent to the ACPI G2/S5 or G3
comment|/// state.  If the system does not support this reset type, then when the system
comment|/// is rebooted, it should exhibit the EfiResetCold attributes.
comment|///
name|EfiResetShutdown
block|,
comment|///
comment|/// Used to induce a system-wide reset. The exact type of the reset is defined by
comment|/// the EFI_GUID that follows the Null-terminated Unicode string passed into
comment|/// ResetData. If the platform does not recognize the EFI_GUID in ResetData the
comment|/// platform must pick a supported reset type to perform. The platform may
comment|/// optionally log the parameters from any non-normal reset that occurs.
comment|///
name|EfiResetPlatformSpecific
block|}
name|EFI_RESET_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Data structure that precedes all of the standard EFI table types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A 64-bit signature that identifies the type of table that follows.
comment|/// Unique signatures have been generated for the EFI System Table,
comment|/// the EFI Boot Services Table, and the EFI Runtime Services Table.
comment|///
name|UINT64
name|Signature
decl_stmt|;
comment|///
comment|/// The revision of the EFI Specification to which this table
comment|/// conforms. The upper 16 bits of this field contain the major
comment|/// revision value, and the lower 16 bits contain the minor revision
comment|/// value. The minor revision values are limited to the range of 00..99.
comment|///
name|UINT32
name|Revision
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the entire table including the EFI_TABLE_HEADER.
comment|///
name|UINT32
name|HeaderSize
decl_stmt|;
comment|///
comment|/// The 32-bit CRC for the entire table. This value is computed by
comment|/// setting this field to 0, and computing the 32-bit CRC for HeaderSize bytes.
comment|///
name|UINT32
name|CRC32
decl_stmt|;
comment|///
comment|/// Reserved field that must be set to 0.
comment|///
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|EFI_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Attributes of variable.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_VARIABLE_NON_VOLATILE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_BOOTSERVICE_ACCESS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_RUNTIME_ACCESS
value|0x00000004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This attribute is identified by the mnemonic 'HR'
end_comment

begin_comment
comment|/// elsewhere in this specification.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_VARIABLE_HARDWARE_ERROR_RECORD
value|0x00000008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Attributes of Authenticated Variable
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_APPEND_WRITE
value|0x00000040
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// AuthInfo is a WIN_CERTIFICATE using the wCertificateType
end_comment

begin_comment
comment|/// WIN_CERTIFICATE_UEFI_GUID and the CertType
end_comment

begin_comment
comment|/// EFI_CERT_TYPE_RSA2048_SHA256_GUID. If the attribute specifies
end_comment

begin_comment
comment|/// authenticated access, then the Data buffer should begin with an
end_comment

begin_comment
comment|/// authentication descriptor prior to the data payload and DataSize
end_comment

begin_comment
comment|/// should reflect the the data.and descriptor size. The caller
end_comment

begin_comment
comment|/// shall digest the Monotonic Count value and the associated data
end_comment

begin_comment
comment|/// for the variable update using the SHA-256 1-way hash algorithm.
end_comment

begin_comment
comment|/// The ensuing the 32-byte digest will be signed using the private
end_comment

begin_comment
comment|/// key associated w/ the public/private 2048-bit RSA key-pair. The
end_comment

begin_comment
comment|/// WIN_CERTIFICATE shall be used to describe the signature of the
end_comment

begin_comment
comment|/// Variable data *Data. In addition, the signature will also
end_comment

begin_comment
comment|/// include the MonotonicCount value to guard against replay attacks.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Included in the signature of
comment|/// AuthInfo.Used to ensure freshness/no
comment|/// replay. Incremented during each
comment|/// "Write" access.
comment|///
name|UINT64
name|MonotonicCount
decl_stmt|;
comment|///
comment|/// Provides the authorization for the variable
comment|/// access. It is a signature across the
comment|/// variable data and the  Monotonic Count
comment|/// value. Caller uses Private key that is
comment|/// associated with a public key that has been
comment|/// provisioned via the key exchange.
comment|///
name|WIN_CERTIFICATE_UEFI_GUID
name|AuthInfo
decl_stmt|;
block|}
name|EFI_VARIABLE_AUTHENTICATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// When the attribute EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS is
end_comment

begin_comment
comment|/// set, then the Data buffer shall begin with an instance of a complete (and serialized)
end_comment

begin_comment
comment|/// EFI_VARIABLE_AUTHENTICATION_2 descriptor. The descriptor shall be followed by the new
end_comment

begin_comment
comment|/// variable value and DataSize shall reflect the combined size of the descriptor and the new
end_comment

begin_comment
comment|/// variable value. The authentication descriptor is not part of the variable data and is not
end_comment

begin_comment
comment|/// returned by subsequent calls to GetVariable().
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For the TimeStamp value, components Pad1, Nanosecond, TimeZone, Daylight and
comment|/// Pad2 shall be set to 0. This means that the time shall always be expressed in GMT.
comment|///
name|EFI_TIME
name|TimeStamp
decl_stmt|;
comment|///
comment|/// Only a CertType of  EFI_CERT_TYPE_PKCS7_GUID is accepted.
comment|///
name|WIN_CERTIFICATE_UEFI_GUID
name|AuthInfo
decl_stmt|;
block|}
name|EFI_VARIABLE_AUTHENTICATION_2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

