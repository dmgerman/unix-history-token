begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Defines data types and constants introduced in UEFI.  Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR> Portions copyright (c) 2011 - 2016, ARM Ltd. All rights reserved.<BR>  This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_BASETYPE_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_BASETYPE_H__
end_define

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Basic data type definitions introduced in UEFI.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 128-bit buffer containing a unique identifier value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|GUID
name|EFI_GUID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Function return status for EFI API.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|RETURN_STATUS
name|EFI_STATUS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A collection of related interfaces.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Handle to an event structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_EVENT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Task priority level.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINTN
name|EFI_TPL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Logical block address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|EFI_LBA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 64-bit physical memory address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|EFI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 64-bit virtual memory address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|EFI_VIRTUAL_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Time Abstraction:
end_comment

begin_comment
comment|///  Year:       1900 - 9999
end_comment

begin_comment
comment|///  Month:      1 - 12
end_comment

begin_comment
comment|///  Day:        1 - 31
end_comment

begin_comment
comment|///  Hour:       0 - 23
end_comment

begin_comment
comment|///  Minute:     0 - 59
end_comment

begin_comment
comment|///  Second:     0 - 59
end_comment

begin_comment
comment|///  Nanosecond: 0 - 999,999,999
end_comment

begin_comment
comment|///  TimeZone:   -1440 to 1440 or 2047
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Year
decl_stmt|;
name|UINT8
name|Month
decl_stmt|;
name|UINT8
name|Day
decl_stmt|;
name|UINT8
name|Hour
decl_stmt|;
name|UINT8
name|Minute
decl_stmt|;
name|UINT8
name|Second
decl_stmt|;
name|UINT8
name|Pad1
decl_stmt|;
name|UINT32
name|Nanosecond
decl_stmt|;
name|INT16
name|TimeZone
decl_stmt|;
name|UINT8
name|Daylight
decl_stmt|;
name|UINT8
name|Pad2
decl_stmt|;
block|}
name|EFI_TIME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 4-byte buffer. An IPv4 internet protocol address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|IPv4_ADDRESS
name|EFI_IPv4_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 16-byte buffer. An IPv6 internet protocol address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|IPv6_ADDRESS
name|EFI_IPv6_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 32-byte buffer containing a network Media Access Control address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Addr
index|[
literal|32
index|]
decl_stmt|;
block|}
name|EFI_MAC_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 16-byte buffer aligned on a 4-byte boundary.
end_comment

begin_comment
comment|/// An IPv4 or IPv6 internet protocol address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|UINT32
name|Addr
index|[
literal|4
index|]
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|v4
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|v6
decl_stmt|;
block|}
name|EFI_IP_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of EFI_STATUS.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SUCCESS
value|RETURN_SUCCESS
end_define

begin_define
define|#
directive|define
name|EFI_LOAD_ERROR
value|RETURN_LOAD_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_INVALID_PARAMETER
value|RETURN_INVALID_PARAMETER
end_define

begin_define
define|#
directive|define
name|EFI_UNSUPPORTED
value|RETURN_UNSUPPORTED
end_define

begin_define
define|#
directive|define
name|EFI_BAD_BUFFER_SIZE
value|RETURN_BAD_BUFFER_SIZE
end_define

begin_define
define|#
directive|define
name|EFI_BUFFER_TOO_SMALL
value|RETURN_BUFFER_TOO_SMALL
end_define

begin_define
define|#
directive|define
name|EFI_NOT_READY
value|RETURN_NOT_READY
end_define

begin_define
define|#
directive|define
name|EFI_DEVICE_ERROR
value|RETURN_DEVICE_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_WRITE_PROTECTED
value|RETURN_WRITE_PROTECTED
end_define

begin_define
define|#
directive|define
name|EFI_OUT_OF_RESOURCES
value|RETURN_OUT_OF_RESOURCES
end_define

begin_define
define|#
directive|define
name|EFI_VOLUME_CORRUPTED
value|RETURN_VOLUME_CORRUPTED
end_define

begin_define
define|#
directive|define
name|EFI_VOLUME_FULL
value|RETURN_VOLUME_FULL
end_define

begin_define
define|#
directive|define
name|EFI_NO_MEDIA
value|RETURN_NO_MEDIA
end_define

begin_define
define|#
directive|define
name|EFI_MEDIA_CHANGED
value|RETURN_MEDIA_CHANGED
end_define

begin_define
define|#
directive|define
name|EFI_NOT_FOUND
value|RETURN_NOT_FOUND
end_define

begin_define
define|#
directive|define
name|EFI_ACCESS_DENIED
value|RETURN_ACCESS_DENIED
end_define

begin_define
define|#
directive|define
name|EFI_NO_RESPONSE
value|RETURN_NO_RESPONSE
end_define

begin_define
define|#
directive|define
name|EFI_NO_MAPPING
value|RETURN_NO_MAPPING
end_define

begin_define
define|#
directive|define
name|EFI_TIMEOUT
value|RETURN_TIMEOUT
end_define

begin_define
define|#
directive|define
name|EFI_NOT_STARTED
value|RETURN_NOT_STARTED
end_define

begin_define
define|#
directive|define
name|EFI_ALREADY_STARTED
value|RETURN_ALREADY_STARTED
end_define

begin_define
define|#
directive|define
name|EFI_ABORTED
value|RETURN_ABORTED
end_define

begin_define
define|#
directive|define
name|EFI_ICMP_ERROR
value|RETURN_ICMP_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_TFTP_ERROR
value|RETURN_TFTP_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_PROTOCOL_ERROR
value|RETURN_PROTOCOL_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_INCOMPATIBLE_VERSION
value|RETURN_INCOMPATIBLE_VERSION
end_define

begin_define
define|#
directive|define
name|EFI_SECURITY_VIOLATION
value|RETURN_SECURITY_VIOLATION
end_define

begin_define
define|#
directive|define
name|EFI_CRC_ERROR
value|RETURN_CRC_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_END_OF_MEDIA
value|RETURN_END_OF_MEDIA
end_define

begin_define
define|#
directive|define
name|EFI_END_OF_FILE
value|RETURN_END_OF_FILE
end_define

begin_define
define|#
directive|define
name|EFI_INVALID_LANGUAGE
value|RETURN_INVALID_LANGUAGE
end_define

begin_define
define|#
directive|define
name|EFI_COMPROMISED_DATA
value|RETURN_COMPROMISED_DATA
end_define

begin_define
define|#
directive|define
name|EFI_HTTP_ERROR
value|RETURN_HTTP_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_WARN_UNKNOWN_GLYPH
value|RETURN_WARN_UNKNOWN_GLYPH
end_define

begin_define
define|#
directive|define
name|EFI_WARN_DELETE_FAILURE
value|RETURN_WARN_DELETE_FAILURE
end_define

begin_define
define|#
directive|define
name|EFI_WARN_WRITE_FAILURE
value|RETURN_WARN_WRITE_FAILURE
end_define

begin_define
define|#
directive|define
name|EFI_WARN_BUFFER_TOO_SMALL
value|RETURN_WARN_BUFFER_TOO_SMALL
end_define

begin_define
define|#
directive|define
name|EFI_WARN_STALE_DATA
value|RETURN_WARN_STALE_DATA
end_define

begin_define
define|#
directive|define
name|EFI_WARN_FILE_SYSTEM
value|RETURN_WARN_FILE_SYSTEM
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Define macro to encode the status code.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFIERR
parameter_list|(
name|_a
parameter_list|)
value|ENCODE_ERROR(_a)
end_define

begin_define
define|#
directive|define
name|EFI_ERROR
parameter_list|(
name|A
parameter_list|)
value|RETURN_ERROR(A)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ICMP error definitions
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_NETWORK_UNREACHABLE
value|EFIERR(100)
end_define

begin_define
define|#
directive|define
name|EFI_HOST_UNREACHABLE
value|EFIERR(101)
end_define

begin_define
define|#
directive|define
name|EFI_PROTOCOL_UNREACHABLE
value|EFIERR(102)
end_define

begin_define
define|#
directive|define
name|EFI_PORT_UNREACHABLE
value|EFIERR(103)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Tcp connection status definitions
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CONNECTION_FIN
value|EFIERR(104)
end_define

begin_define
define|#
directive|define
name|EFI_CONNECTION_RESET
value|EFIERR(105)
end_define

begin_define
define|#
directive|define
name|EFI_CONNECTION_REFUSED
value|EFIERR(106)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The EFI memory allocation functions work in units of EFI_PAGEs that are
end_comment

begin_comment
comment|// 4KB. This should in no way be confused with the page size of the processor.
end_comment

begin_comment
comment|// An EFI_PAGE is just the quanta of memory in EFI.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PAGE_SIZE
value|SIZE_4KB
end_define

begin_define
define|#
directive|define
name|EFI_PAGE_MASK
value|0xFFF
end_define

begin_define
define|#
directive|define
name|EFI_PAGE_SHIFT
value|12
end_define

begin_comment
comment|/**   Macro that converts a size, in bytes, to a number of EFI_PAGESs.    @param  Size      A size in bytes.  This parameter is assumed to be type UINTN.                       Passing in a parameter that is larger than UINTN may produce                      unexpected results.    @return  The number of EFI_PAGESs associated with the number of bytes specified            by Size.  **/
end_comment

begin_define
define|#
directive|define
name|EFI_SIZE_TO_PAGES
parameter_list|(
name|Size
parameter_list|)
value|(((Size)>> EFI_PAGE_SHIFT) + (((Size)& EFI_PAGE_MASK) ? 1 : 0))
end_define

begin_comment
comment|/**   Macro that converts a number of EFI_PAGEs to a size in bytes.    @param  Pages     The number of EFI_PAGES.  This parameter is assumed to be                      type UINTN.  Passing in a parameter that is larger than                      UINTN may produce unexpected results.    @return  The number of bytes associated with the number of EFI_PAGEs specified             by Pages.    **/
end_comment

begin_define
define|#
directive|define
name|EFI_PAGES_TO_SIZE
parameter_list|(
name|Pages
parameter_list|)
value|((Pages)<< EFI_PAGE_SHIFT)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PE32+ Machine type for IA32 UEFI images.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_IA32
value|0x014C
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PE32+ Machine type for IA64 UEFI images.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_IA64
value|0x0200
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PE32+ Machine type for EBC UEFI images.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_EBC
value|0x0EBC
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PE32+ Machine type for X64 UEFI images.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_X64
value|0x8664
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PE32+ Machine type for ARM mixed ARM and Thumb/Thumb2 images.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_ARMTHUMB_MIXED
value|0x01C2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PE32+ Machine type for AARCH64 A64 images.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_AARCH64
value|0xAA64
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
end_if

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
define|\
value|(((Machine) == EFI_IMAGE_MACHINE_IA32) || ((Machine) == EFI_IMAGE_MACHINE_EBC))
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_CROSS_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
value|((Machine) == EFI_IMAGE_MACHINE_X64)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_IPF
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
define|\
value|(((Machine) == EFI_IMAGE_MACHINE_IA64) || ((Machine) == EFI_IMAGE_MACHINE_EBC))
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_CROSS_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
value|(FALSE)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
define|\
value|(((Machine) == EFI_IMAGE_MACHINE_X64) || ((Machine) == EFI_IMAGE_MACHINE_EBC))
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_CROSS_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
value|((Machine) == EFI_IMAGE_MACHINE_IA32)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_ARM
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
define|\
value|(((Machine) == EFI_IMAGE_MACHINE_ARMTHUMB_MIXED) || ((Machine) == EFI_IMAGE_MACHINE_EBC))
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_CROSS_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
value|((Machine) == EFI_IMAGE_MACHINE_ARMTHUMB_MIXED)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_AARCH64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
define|\
value|(((Machine) == EFI_IMAGE_MACHINE_AARCH64) || ((Machine) == EFI_IMAGE_MACHINE_EBC))
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_CROSS_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
value|(FALSE)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_EBC
argument_list|)
end_elif

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is just to make sure you can cross compile with the EBC compiler.
end_comment

begin_comment
comment|/// It does not make sense to have a PE loader coded in EBC.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
value|((Machine) == EFI_IMAGE_MACHINE_EBC)
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_CROSS_TYPE_SUPPORTED
parameter_list|(
name|Machine
parameter_list|)
value|(FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unknown Processor Type
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

