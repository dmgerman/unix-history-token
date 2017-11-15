begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_DEF_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_DEF_H
end_define

begin_comment
comment|/*++  Copyright (c)  1999 - 2002 Intel Corporation. All rights reserved This software and associated documentation (if any) is furnished under a license and may only be used or copied in accordance with the terms of the license. Except as permitted by such license, no part of this software or documentation may be reproduced, stored in a retrieval system, or transmitted in any form or by any means without the express written consent of Intel Corporation.  Module Name:      efidef.h  Abstract:      EFI definitions     Revision History  --*/
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|CHAR16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|CHAR8
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_THREAD_ID
end_ifndef

begin_comment
comment|/* ACPI's definitions are fine */
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|BOOLEAN
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|((BOOLEAN) 1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|((BOOLEAN) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|((VOID *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|UINTN
name|EFI_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|EFI_LBA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINTN
name|EFI_TPL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_HANDLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_EVENT
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Prototype argument decoration for EFI parameters to indicate
end_comment

begin_comment
comment|// their direction
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IN - argument is passed into the function
end_comment

begin_comment
comment|// OUT - argument (pointer) is returned from the function
end_comment

begin_comment
comment|// OPTIONAL - argument is optional
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN
end_ifndef

begin_define
define|#
directive|define
name|IN
end_define

begin_define
define|#
directive|define
name|OUT
end_define

begin_define
define|#
directive|define
name|OPTIONAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// A GUID
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Data1
decl_stmt|;
name|UINT16
name|Data2
decl_stmt|;
name|UINT16
name|Data3
decl_stmt|;
name|UINT8
name|Data4
index|[
literal|8
index|]
decl_stmt|;
block|}
name|EFI_GUID
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Time
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Year
decl_stmt|;
comment|// 1998 - 20XX
name|UINT8
name|Month
decl_stmt|;
comment|// 1 - 12
name|UINT8
name|Day
decl_stmt|;
comment|// 1 - 31
name|UINT8
name|Hour
decl_stmt|;
comment|// 0 - 23
name|UINT8
name|Minute
decl_stmt|;
comment|// 0 - 59
name|UINT8
name|Second
decl_stmt|;
comment|// 0 - 59
name|UINT8
name|Pad1
decl_stmt|;
name|UINT32
name|Nanosecond
decl_stmt|;
comment|// 0 - 999,999,999
name|INT16
name|TimeZone
decl_stmt|;
comment|// -1440 to 1440 or 2047
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
comment|// Bit definitions for EFI_TIME.Daylight
end_comment

begin_define
define|#
directive|define
name|EFI_TIME_ADJUST_DAYLIGHT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_TIME_IN_DAYLIGHT
value|0x02
end_define

begin_comment
comment|// Value definition for EFI_TIME.TimeZone
end_comment

begin_define
define|#
directive|define
name|EFI_UNSPECIFIED_TIMEZONE
value|0x07FF
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Networking
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|EFI_IPv4_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Addr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|EFI_IPv6_ADDRESS
typedef|;
end_typedef

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
comment|//
end_comment

begin_comment
comment|// Memory
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|EFI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|EFI_VIRTUAL_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AllocateAnyPages
block|,
name|AllocateMaxAddress
block|,
name|AllocateAddress
block|,
name|MaxAllocateType
block|}
name|EFI_ALLOCATE_TYPE
typedef|;
end_typedef

begin_comment
comment|//Preseve the attr on any range supplied.
end_comment

begin_comment
comment|//ConventialMemory must have WB,SR,SW when supplied.
end_comment

begin_comment
comment|//When allocating from ConventialMemory always make it WB,SR,SW
end_comment

begin_comment
comment|//When returning to ConventialMemory always make it WB,SR,SW
end_comment

begin_comment
comment|//When getting the memory map, or on RT for runtime types
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiReservedMemoryType
block|,
name|EfiLoaderCode
block|,
name|EfiLoaderData
block|,
name|EfiBootServicesCode
block|,
name|EfiBootServicesData
block|,
name|EfiRuntimeServicesCode
block|,
name|EfiRuntimeServicesData
block|,
name|EfiConventionalMemory
block|,
name|EfiUnusableMemory
block|,
name|EfiACPIReclaimMemory
block|,
name|EfiACPIMemoryNVS
block|,
name|EfiMemoryMappedIO
block|,
name|EfiMemoryMappedIOPortSpace
block|,
name|EfiPalCode
block|,
name|EfiMaxMemoryType
block|}
name|EFI_MEMORY_TYPE
typedef|;
end_typedef

begin_comment
comment|// possible caching types for the memory range
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_UC
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WC
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WT
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WB
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_UCE
value|0x0000000000000010
end_define

begin_comment
comment|// physical memory protection on range
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_WP
value|0x0000000000001000
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_RP
value|0x0000000000002000
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_XP
value|0x0000000000004000
end_define

begin_comment
comment|// range requires a runtime mapping
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_RUNTIME
value|0x8000000000000000
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_DESCRIPTOR_VERSION
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Type
decl_stmt|;
comment|// Field size is 32 bits followed by 32 bit pad
name|UINT32
name|Pad
decl_stmt|;
name|EFI_PHYSICAL_ADDRESS
name|PhysicalStart
decl_stmt|;
comment|// Field size is 64 bits
name|EFI_VIRTUAL_ADDRESS
name|VirtualStart
decl_stmt|;
comment|// Field size is 64 bits
name|UINT64
name|NumberOfPages
decl_stmt|;
comment|// Field size is 64 bits
name|UINT64
name|Attribute
decl_stmt|;
comment|// Field size is 64 bits
block|}
name|EFI_MEMORY_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// International Language
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|ISO_639_2
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISO_639_2_ENTRY_SIZE
value|3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PAGE_SIZE
value|4096
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

begin_define
define|#
directive|define
name|EFI_SIZE_TO_PAGES
parameter_list|(
name|a
parameter_list|)
define|\
value|( ((a)>> EFI_PAGE_SHIFT) + (((a)& EFI_PAGE_MASK) ? 1 : 0) )
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

