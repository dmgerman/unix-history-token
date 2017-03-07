begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI image format for PE32, PE32+ and TE. Please note some data structures are    different for PE32 and PE32+. EFI_IMAGE_NT_HEADERS32 is for PE32 and    EFI_IMAGE_NT_HEADERS64 is for PE32+.     This file is coded to the Visual Studio, Microsoft Portable Executable and    Common Object File Format Specification, Revision 8.3 - February 6, 2013.   This file also includes some definitions in PI Specification, Revision 1.0.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR> This program and the accompanying materials                           are licensed and made available under the terms and conditions of the BSD License          which accompanies this distribution.  The full text of the license may be found at         http://opensource.org/licenses/bsd-license.php.                                             THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PE_IMAGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PE_IMAGE_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// PE32+ Subsystem type for EFI images
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION
value|10
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER
value|11
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER
value|12
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_SAL_RUNTIME_DRIVER
value|13
end_define

begin_comment
comment|///< defined PI Specification, 1.0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PE32+ Machine type for EFI images
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_I386
value|0x014c
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_IA64
value|0x0200
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_EBC
value|0x0EBC
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_X64
value|0x8664
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ARMTHUMB_MIXED
value|0x01c2
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ARM64
value|0xAA64
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EXE file formats
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_DOS_SIGNATURE
value|SIGNATURE_16('M', 'Z')
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_OS2_SIGNATURE
value|SIGNATURE_16('N', 'E')
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_OS2_SIGNATURE_LE
value|SIGNATURE_16('L', 'E')
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_NT_SIGNATURE
value|SIGNATURE_32('P', 'E', '\0', '\0')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PE images can start with an optional DOS header, so if an image is run
end_comment

begin_comment
comment|/// under DOS it can print an error message.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|e_magic
decl_stmt|;
comment|///< Magic number.
name|UINT16
name|e_cblp
decl_stmt|;
comment|///< Bytes on last page of file.
name|UINT16
name|e_cp
decl_stmt|;
comment|///< Pages in file.
name|UINT16
name|e_crlc
decl_stmt|;
comment|///< Relocations.
name|UINT16
name|e_cparhdr
decl_stmt|;
comment|///< Size of header in paragraphs.
name|UINT16
name|e_minalloc
decl_stmt|;
comment|///< Minimum extra paragraphs needed.
name|UINT16
name|e_maxalloc
decl_stmt|;
comment|///< Maximum extra paragraphs needed.
name|UINT16
name|e_ss
decl_stmt|;
comment|///< Initial (relative) SS value.
name|UINT16
name|e_sp
decl_stmt|;
comment|///< Initial SP value.
name|UINT16
name|e_csum
decl_stmt|;
comment|///< Checksum.
name|UINT16
name|e_ip
decl_stmt|;
comment|///< Initial IP value.
name|UINT16
name|e_cs
decl_stmt|;
comment|///< Initial (relative) CS value.
name|UINT16
name|e_lfarlc
decl_stmt|;
comment|///< File address of relocation table.
name|UINT16
name|e_ovno
decl_stmt|;
comment|///< Overlay number.
name|UINT16
name|e_res
index|[
literal|4
index|]
decl_stmt|;
comment|///< Reserved words.
name|UINT16
name|e_oemid
decl_stmt|;
comment|///< OEM identifier (for e_oeminfo).
name|UINT16
name|e_oeminfo
decl_stmt|;
comment|///< OEM information; e_oemid specific.
name|UINT16
name|e_res2
index|[
literal|10
index|]
decl_stmt|;
comment|///< Reserved words.
name|UINT32
name|e_lfanew
decl_stmt|;
comment|///< File address of new exe header.
block|}
name|EFI_IMAGE_DOS_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// COFF File Header (Object and Image).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Machine
decl_stmt|;
name|UINT16
name|NumberOfSections
decl_stmt|;
name|UINT32
name|TimeDateStamp
decl_stmt|;
name|UINT32
name|PointerToSymbolTable
decl_stmt|;
name|UINT32
name|NumberOfSymbols
decl_stmt|;
name|UINT16
name|SizeOfOptionalHeader
decl_stmt|;
name|UINT16
name|Characteristics
decl_stmt|;
block|}
name|EFI_IMAGE_FILE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size of EFI_IMAGE_FILE_HEADER.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_FILE_HEADER
value|20
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Characteristics
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_RELOCS_STRIPPED
value|BIT0
end_define

begin_comment
comment|///< 0x0001  Relocation info stripped from file.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_EXECUTABLE_IMAGE
value|BIT1
end_define

begin_comment
comment|///< 0x0002  File is executable  (i.e. no unresolved externel references).
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_LINE_NUMS_STRIPPED
value|BIT2
end_define

begin_comment
comment|///< 0x0004  Line nunbers stripped from file.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_LOCAL_SYMS_STRIPPED
value|BIT3
end_define

begin_comment
comment|///< 0x0008  Local symbols stripped from file.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_BYTES_REVERSED_LO
value|BIT7
end_define

begin_comment
comment|///< 0x0080  Bytes of machine word are reversed.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_32BIT_MACHINE
value|BIT8
end_define

begin_comment
comment|///< 0x0100  32 bit word machine.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_DEBUG_STRIPPED
value|BIT9
end_define

begin_comment
comment|///< 0x0200  Debugging info stripped from file in .DBG file.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_SYSTEM
value|BIT12
end_define

begin_comment
comment|///< 0x1000  System File.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_DLL
value|BIT13
end_define

begin_comment
comment|///< 0x2000  File is a DLL.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_FILE_BYTES_REVERSED_HI
value|BIT15
end_define

begin_comment
comment|///< 0x8000  Bytes of machine word are reversed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Header Data Directories.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|VirtualAddress
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
block|}
name|EFI_IMAGE_DATA_DIRECTORY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Directory Entries
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_EXPORT
value|0
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_IMPORT
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_RESOURCE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_EXCEPTION
value|3
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_SECURITY
value|4
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_BASERELOC
value|5
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_DEBUG
value|6
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_COPYRIGHT
value|7
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_GLOBALPTR
value|8
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_TLS
value|9
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG
value|10
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES
value|16
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// @attention
end_comment

begin_comment
comment|/// EFI_IMAGE_NT_OPTIONAL_HDR32_MAGIC means PE32 and
end_comment

begin_comment
comment|/// EFI_IMAGE_OPTIONAL_HEADER32 must be used. The data structures only vary
end_comment

begin_comment
comment|/// after NT additional fields.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_NT_OPTIONAL_HDR32_MAGIC
value|0x10b
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Optional Header Standard Fields for PE32.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Standard fields.
comment|///
name|UINT16
name|Magic
decl_stmt|;
name|UINT8
name|MajorLinkerVersion
decl_stmt|;
name|UINT8
name|MinorLinkerVersion
decl_stmt|;
name|UINT32
name|SizeOfCode
decl_stmt|;
name|UINT32
name|SizeOfInitializedData
decl_stmt|;
name|UINT32
name|SizeOfUninitializedData
decl_stmt|;
name|UINT32
name|AddressOfEntryPoint
decl_stmt|;
name|UINT32
name|BaseOfCode
decl_stmt|;
name|UINT32
name|BaseOfData
decl_stmt|;
comment|///< PE32 contains this additional field, which is absent in PE32+.
comment|///
comment|/// Optional Header Windows-Specific Fields.
comment|///
name|UINT32
name|ImageBase
decl_stmt|;
name|UINT32
name|SectionAlignment
decl_stmt|;
name|UINT32
name|FileAlignment
decl_stmt|;
name|UINT16
name|MajorOperatingSystemVersion
decl_stmt|;
name|UINT16
name|MinorOperatingSystemVersion
decl_stmt|;
name|UINT16
name|MajorImageVersion
decl_stmt|;
name|UINT16
name|MinorImageVersion
decl_stmt|;
name|UINT16
name|MajorSubsystemVersion
decl_stmt|;
name|UINT16
name|MinorSubsystemVersion
decl_stmt|;
name|UINT32
name|Win32VersionValue
decl_stmt|;
name|UINT32
name|SizeOfImage
decl_stmt|;
name|UINT32
name|SizeOfHeaders
decl_stmt|;
name|UINT32
name|CheckSum
decl_stmt|;
name|UINT16
name|Subsystem
decl_stmt|;
name|UINT16
name|DllCharacteristics
decl_stmt|;
name|UINT32
name|SizeOfStackReserve
decl_stmt|;
name|UINT32
name|SizeOfStackCommit
decl_stmt|;
name|UINT32
name|SizeOfHeapReserve
decl_stmt|;
name|UINT32
name|SizeOfHeapCommit
decl_stmt|;
name|UINT32
name|LoaderFlags
decl_stmt|;
name|UINT32
name|NumberOfRvaAndSizes
decl_stmt|;
name|EFI_IMAGE_DATA_DIRECTORY
name|DataDirectory
index|[
name|EFI_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES
index|]
decl_stmt|;
block|}
name|EFI_IMAGE_OPTIONAL_HEADER32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// @attention
end_comment

begin_comment
comment|/// EFI_IMAGE_NT_OPTIONAL_HDR64_MAGIC means PE32+ and
end_comment

begin_comment
comment|/// EFI_IMAGE_OPTIONAL_HEADER64 must be used. The data structures only vary
end_comment

begin_comment
comment|/// after NT additional fields.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_NT_OPTIONAL_HDR64_MAGIC
value|0x20b
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Optional Header Standard Fields for PE32+.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Standard fields.
comment|///
name|UINT16
name|Magic
decl_stmt|;
name|UINT8
name|MajorLinkerVersion
decl_stmt|;
name|UINT8
name|MinorLinkerVersion
decl_stmt|;
name|UINT32
name|SizeOfCode
decl_stmt|;
name|UINT32
name|SizeOfInitializedData
decl_stmt|;
name|UINT32
name|SizeOfUninitializedData
decl_stmt|;
name|UINT32
name|AddressOfEntryPoint
decl_stmt|;
name|UINT32
name|BaseOfCode
decl_stmt|;
comment|///
comment|/// Optional Header Windows-Specific Fields.
comment|///
name|UINT64
name|ImageBase
decl_stmt|;
name|UINT32
name|SectionAlignment
decl_stmt|;
name|UINT32
name|FileAlignment
decl_stmt|;
name|UINT16
name|MajorOperatingSystemVersion
decl_stmt|;
name|UINT16
name|MinorOperatingSystemVersion
decl_stmt|;
name|UINT16
name|MajorImageVersion
decl_stmt|;
name|UINT16
name|MinorImageVersion
decl_stmt|;
name|UINT16
name|MajorSubsystemVersion
decl_stmt|;
name|UINT16
name|MinorSubsystemVersion
decl_stmt|;
name|UINT32
name|Win32VersionValue
decl_stmt|;
name|UINT32
name|SizeOfImage
decl_stmt|;
name|UINT32
name|SizeOfHeaders
decl_stmt|;
name|UINT32
name|CheckSum
decl_stmt|;
name|UINT16
name|Subsystem
decl_stmt|;
name|UINT16
name|DllCharacteristics
decl_stmt|;
name|UINT64
name|SizeOfStackReserve
decl_stmt|;
name|UINT64
name|SizeOfStackCommit
decl_stmt|;
name|UINT64
name|SizeOfHeapReserve
decl_stmt|;
name|UINT64
name|SizeOfHeapCommit
decl_stmt|;
name|UINT32
name|LoaderFlags
decl_stmt|;
name|UINT32
name|NumberOfRvaAndSizes
decl_stmt|;
name|EFI_IMAGE_DATA_DIRECTORY
name|DataDirectory
index|[
name|EFI_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES
index|]
decl_stmt|;
block|}
name|EFI_IMAGE_OPTIONAL_HEADER64
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// @attention
end_comment

begin_comment
comment|/// EFI_IMAGE_NT_HEADERS32 is for use ONLY by tools.
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
name|EFI_IMAGE_FILE_HEADER
name|FileHeader
decl_stmt|;
name|EFI_IMAGE_OPTIONAL_HEADER32
name|OptionalHeader
decl_stmt|;
block|}
name|EFI_IMAGE_NT_HEADERS32
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
value|sizeof (EFI_IMAGE_NT_HEADERS32)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// @attention
end_comment

begin_comment
comment|/// EFI_IMAGE_HEADERS64 is for use ONLY by tools.
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
name|EFI_IMAGE_FILE_HEADER
name|FileHeader
decl_stmt|;
name|EFI_IMAGE_OPTIONAL_HEADER64
name|OptionalHeader
decl_stmt|;
block|}
name|EFI_IMAGE_NT_HEADERS64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
value|sizeof (EFI_IMAGE_NT_HEADERS64)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Other Windows Subsystem Values
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_NATIVE
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_WINDOWS_GUI
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_WINDOWS_CUI
value|3
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_OS2_CUI
value|5
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SUBSYSTEM_POSIX_CUI
value|7
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Length of ShortName.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_SHORT_NAME
value|8
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Section Table. This table immediately follows the optional header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Name
index|[
name|EFI_IMAGE_SIZEOF_SHORT_NAME
index|]
decl_stmt|;
union|union
block|{
name|UINT32
name|PhysicalAddress
decl_stmt|;
name|UINT32
name|VirtualSize
decl_stmt|;
block|}
name|Misc
union|;
name|UINT32
name|VirtualAddress
decl_stmt|;
name|UINT32
name|SizeOfRawData
decl_stmt|;
name|UINT32
name|PointerToRawData
decl_stmt|;
name|UINT32
name|PointerToRelocations
decl_stmt|;
name|UINT32
name|PointerToLinenumbers
decl_stmt|;
name|UINT16
name|NumberOfRelocations
decl_stmt|;
name|UINT16
name|NumberOfLinenumbers
decl_stmt|;
name|UINT32
name|Characteristics
decl_stmt|;
block|}
name|EFI_IMAGE_SECTION_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size of EFI_IMAGE_SECTION_HEADER.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_SECTION_HEADER
value|40
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Section Flags Values
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_TYPE_NO_PAD
value|BIT3
end_define

begin_comment
comment|///< 0x00000008  ///< Reserved.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_CNT_CODE
value|BIT5
end_define

begin_comment
comment|///< 0x00000020
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_CNT_INITIALIZED_DATA
value|BIT6
end_define

begin_comment
comment|///< 0x00000040
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_CNT_UNINITIALIZED_DATA
value|BIT7
end_define

begin_comment
comment|///< 0x00000080
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_LNK_OTHER
value|BIT8
end_define

begin_comment
comment|///< 0x00000100  ///< Reserved.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_LNK_INFO
value|BIT9
end_define

begin_comment
comment|///< 0x00000200  ///< Section contains comments or some other type of information.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_LNK_REMOVE
value|BIT11
end_define

begin_comment
comment|///< 0x00000800  ///< Section contents will not become part of image.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_LNK_COMDAT
value|BIT12
end_define

begin_comment
comment|///< 0x00001000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_ALIGN_1BYTES
value|BIT20
end_define

begin_comment
comment|///< 0x00100000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_ALIGN_2BYTES
value|BIT21
end_define

begin_comment
comment|///< 0x00200000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_ALIGN_4BYTES
value|(BIT20|BIT21)
end_define

begin_comment
comment|///< 0x00300000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_ALIGN_8BYTES
value|BIT22
end_define

begin_comment
comment|///< 0x00400000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_ALIGN_16BYTES
value|(BIT20|BIT22)
end_define

begin_comment
comment|///< 0x00500000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_ALIGN_32BYTES
value|(BIT21|BIT22)
end_define

begin_comment
comment|///< 0x00600000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_ALIGN_64BYTES
value|(BIT20|BIT21|BIT22)
end_define

begin_comment
comment|///< 0x00700000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_MEM_DISCARDABLE
value|BIT25
end_define

begin_comment
comment|///< 0x02000000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_MEM_NOT_CACHED
value|BIT26
end_define

begin_comment
comment|///< 0x04000000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_MEM_NOT_PAGED
value|BIT27
end_define

begin_comment
comment|///< 0x08000000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_MEM_SHARED
value|BIT28
end_define

begin_comment
comment|///< 0x10000000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_MEM_EXECUTE
value|BIT29
end_define

begin_comment
comment|///< 0x20000000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_MEM_READ
value|BIT30
end_define

begin_comment
comment|///< 0x40000000
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SCN_MEM_WRITE
value|BIT31
end_define

begin_comment
comment|///< 0x80000000
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size of a Symbol Table Record.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_SYMBOL
value|18
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Symbols have a section number of the section in which they are
end_comment

begin_comment
comment|// defined. Otherwise, section numbers have the following meanings:
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_UNDEFINED
value|(UINT16) 0
end_define

begin_comment
comment|///< Symbol is undefined or is common.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_ABSOLUTE
value|(UINT16) -1
end_define

begin_comment
comment|///< Symbol is an absolute value.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_DEBUG
value|(UINT16) -2
end_define

begin_comment
comment|///< Symbol is a special debug item.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Symbol Type (fundamental) values.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_NULL
value|0
end_define

begin_comment
comment|///< no type.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_VOID
value|1
end_define

begin_comment
comment|///< no valid type.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_CHAR
value|2
end_define

begin_comment
comment|///< type character.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_SHORT
value|3
end_define

begin_comment
comment|///< type short integer.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_INT
value|4
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_LONG
value|5
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_FLOAT
value|6
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_DOUBLE
value|7
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_STRUCT
value|8
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_UNION
value|9
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_ENUM
value|10
end_define

begin_comment
comment|///< enumeration.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_MOE
value|11
end_define

begin_comment
comment|///< member of enumeration.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_BYTE
value|12
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_WORD
value|13
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_UINT
value|14
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_TYPE_DWORD
value|15
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Symbol Type (derived) values.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_DTYPE_NULL
value|0
end_define

begin_comment
comment|///< no derived type.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_DTYPE_POINTER
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_DTYPE_FUNCTION
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_DTYPE_ARRAY
value|3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Storage classes.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_END_OF_FUNCTION
value|((UINT8) -1)
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_NULL
value|0
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_AUTOMATIC
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_EXTERNAL
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_STATIC
value|3
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_REGISTER
value|4
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_EXTERNAL_DEF
value|5
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_LABEL
value|6
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_UNDEFINED_LABEL
value|7
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_MEMBER_OF_STRUCT
value|8
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_ARGUMENT
value|9
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_STRUCT_TAG
value|10
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_MEMBER_OF_UNION
value|11
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_UNION_TAG
value|12
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_TYPE_DEFINITION
value|13
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_UNDEFINED_STATIC
value|14
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_ENUM_TAG
value|15
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_MEMBER_OF_ENUM
value|16
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_REGISTER_PARAM
value|17
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_BIT_FIELD
value|18
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_BLOCK
value|100
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_FUNCTION
value|101
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_END_OF_STRUCT
value|102
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_FILE
value|103
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_SECTION
value|104
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_SYM_CLASS_WEAK_EXTERNAL
value|105
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// type packing constants
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_N_BTMASK
value|017
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_N_TMASK
value|060
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_N_TMASK1
value|0300
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_N_TMASK2
value|0360
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_N_BTSHFT
value|4
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_N_TSHIFT
value|2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Communal selection types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_COMDAT_SELECT_NODUPLICATES
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_COMDAT_SELECT_ANY
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_COMDAT_SELECT_SAME_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_COMDAT_SELECT_EXACT_MATCH
value|4
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_COMDAT_SELECT_ASSOCIATIVE
value|5
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// the following values only be referred in PeCoff, not defined in PECOFF.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_WEAK_EXTERN_SEARCH_LIBRARY
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_WEAK_EXTERN_SEARCH_ALIAS
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Relocation format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|VirtualAddress
decl_stmt|;
name|UINT32
name|SymbolTableIndex
decl_stmt|;
name|UINT16
name|Type
decl_stmt|;
block|}
name|EFI_IMAGE_RELOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size of EFI_IMAGE_RELOCATION
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_RELOCATION
value|10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// I386 relocation types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_ABSOLUTE
value|0x0000
end_define

begin_comment
comment|///< Reference is absolute, no relocation is necessary.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_DIR16
value|0x0001
end_define

begin_comment
comment|///< Direct 16-bit reference to the symbols virtual address.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_REL16
value|0x0002
end_define

begin_comment
comment|///< PC-relative 16-bit reference to the symbols virtual address.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_DIR32
value|0x0006
end_define

begin_comment
comment|///< Direct 32-bit reference to the symbols virtual address.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_DIR32NB
value|0x0007
end_define

begin_comment
comment|///< Direct 32-bit reference to the symbols virtual address, base not included.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_SEG12
value|0x0009
end_define

begin_comment
comment|///< Direct 16-bit reference to the segment-selector bits of a 32-bit virtual address.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_SECTION
value|0x000A
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_SECREL
value|0x000B
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_I386_REL32
value|0x0014
end_define

begin_comment
comment|///< PC-relative 32-bit reference to the symbols virtual address.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// x64 processor relocation types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_ABSOLUTE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_ADDR64
value|0x0001
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_ADDR32
value|0x0002
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_ADDR32NB
value|0x0003
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_REL32
value|0x0004
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_REL32_1
value|0x0005
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_REL32_2
value|0x0006
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_REL32_3
value|0x0007
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_REL32_4
value|0x0008
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_REL32_5
value|0x0009
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_SECTION
value|0x000A
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_SECREL
value|0x000B
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_SECREL7
value|0x000C
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_TOKEN
value|0x000D
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_SREL32
value|0x000E
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_PAIR
value|0x000F
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_AMD64_SSPAN32
value|0x0010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Based relocation format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|VirtualAddress
decl_stmt|;
name|UINT32
name|SizeOfBlock
decl_stmt|;
block|}
name|EFI_IMAGE_BASE_RELOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size of EFI_IMAGE_BASE_RELOCATION.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_BASE_RELOCATION
value|8
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Based relocation types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_ABSOLUTE
value|0
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_LOW
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_HIGHLOW
value|3
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_HIGHADJ
value|4
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_MIPS_JMPADDR
value|5
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_ARM_MOV32A
value|5
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_ARM_MOV32T
value|7
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_IA64_IMM64
value|9
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_MIPS_JMPADDR16
value|9
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_REL_BASED_DIR64
value|10
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Line number format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|UINT32
name|SymbolTableIndex
decl_stmt|;
comment|///< Symbol table index of function name if Linenumber is 0.
name|UINT32
name|VirtualAddress
decl_stmt|;
comment|///< Virtual address of line number.
block|}
name|Type
union|;
name|UINT16
name|Linenumber
decl_stmt|;
comment|///< Line number.
block|}
name|EFI_IMAGE_LINENUMBER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size of EFI_IMAGE_LINENUMBER.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_LINENUMBER
value|6
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Archive format.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_ARCHIVE_START_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_ARCHIVE_START
value|"!<arch>\n"
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_ARCHIVE_END
value|"`\n"
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_ARCHIVE_PAD
value|"\n"
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_ARCHIVE_LINKER_MEMBER
value|"/               "
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_ARCHIVE_LONGNAMES_MEMBER
value|"//              "
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Archive Member Headers
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Name
index|[
literal|16
index|]
decl_stmt|;
comment|///< File member name - `/' terminated.
name|UINT8
name|Date
index|[
literal|12
index|]
decl_stmt|;
comment|///< File member date - decimal.
name|UINT8
name|UserID
index|[
literal|6
index|]
decl_stmt|;
comment|///< File member user id - decimal.
name|UINT8
name|GroupID
index|[
literal|6
index|]
decl_stmt|;
comment|///< File member group id - decimal.
name|UINT8
name|Mode
index|[
literal|8
index|]
decl_stmt|;
comment|///< File member mode - octal.
name|UINT8
name|Size
index|[
literal|10
index|]
decl_stmt|;
comment|///< File member size - decimal.
name|UINT8
name|EndHeader
index|[
literal|2
index|]
decl_stmt|;
comment|///< String to end header. (0x60 0x0A).
block|}
name|EFI_IMAGE_ARCHIVE_MEMBER_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Size of EFI_IMAGE_ARCHIVE_MEMBER_HEADER.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR
value|60
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// DLL Support
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Export Directory Table.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Characteristics
decl_stmt|;
name|UINT32
name|TimeDateStamp
decl_stmt|;
name|UINT16
name|MajorVersion
decl_stmt|;
name|UINT16
name|MinorVersion
decl_stmt|;
name|UINT32
name|Name
decl_stmt|;
name|UINT32
name|Base
decl_stmt|;
name|UINT32
name|NumberOfFunctions
decl_stmt|;
name|UINT32
name|NumberOfNames
decl_stmt|;
name|UINT32
name|AddressOfFunctions
decl_stmt|;
name|UINT32
name|AddressOfNames
decl_stmt|;
name|UINT32
name|AddressOfNameOrdinals
decl_stmt|;
block|}
name|EFI_IMAGE_EXPORT_DIRECTORY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hint/Name Table.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Hint
decl_stmt|;
name|UINT8
name|Name
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IMAGE_IMPORT_BY_NAME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Import Address Table RVA (Thunk Table).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|UINT32
name|Function
decl_stmt|;
name|UINT32
name|Ordinal
decl_stmt|;
name|EFI_IMAGE_IMPORT_BY_NAME
modifier|*
name|AddressOfData
decl_stmt|;
block|}
name|u1
union|;
block|}
name|EFI_IMAGE_THUNK_DATA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IMAGE_ORDINAL_FLAG
value|BIT31
end_define

begin_comment
comment|///< Flag for PE32.
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SNAP_BY_ORDINAL
parameter_list|(
name|Ordinal
parameter_list|)
value|((Ordinal& EFI_IMAGE_ORDINAL_FLAG) != 0)
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_ORDINAL
parameter_list|(
name|Ordinal
parameter_list|)
value|(Ordinal& 0xffff)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Import Directory Table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Characteristics
decl_stmt|;
name|UINT32
name|TimeDateStamp
decl_stmt|;
name|UINT32
name|ForwarderChain
decl_stmt|;
name|UINT32
name|Name
decl_stmt|;
name|EFI_IMAGE_THUNK_DATA
modifier|*
name|FirstThunk
decl_stmt|;
block|}
name|EFI_IMAGE_IMPORT_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Debug Directory Format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Characteristics
decl_stmt|;
name|UINT32
name|TimeDateStamp
decl_stmt|;
name|UINT16
name|MajorVersion
decl_stmt|;
name|UINT16
name|MinorVersion
decl_stmt|;
name|UINT32
name|Type
decl_stmt|;
name|UINT32
name|SizeOfData
decl_stmt|;
name|UINT32
name|RVA
decl_stmt|;
comment|///< The address of the debug data when loaded, relative to the image base.
name|UINT32
name|FileOffset
decl_stmt|;
comment|///< The file pointer to the debug data.
block|}
name|EFI_IMAGE_DEBUG_DIRECTORY_ENTRY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IMAGE_DEBUG_TYPE_CODEVIEW
value|2
end_define

begin_comment
comment|///< The Visual C++ debug information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Debug Data Structure defined in Microsoft C++.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CODEVIEW_SIGNATURE_NB10
value|SIGNATURE_32('N', 'B', '1', '0')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
comment|///< "NB10"
name|UINT32
name|Unknown
decl_stmt|;
name|UINT32
name|Unknown2
decl_stmt|;
name|UINT32
name|Unknown3
decl_stmt|;
comment|//
comment|// Filename of .PDB goes here
comment|//
block|}
name|EFI_IMAGE_DEBUG_CODEVIEW_NB10_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Debug Data Structure defined in Microsoft C++.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CODEVIEW_SIGNATURE_RSDS
value|SIGNATURE_32('R', 'S', 'D', 'S')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
comment|///< "RSDS".
name|UINT32
name|Unknown
decl_stmt|;
name|UINT32
name|Unknown2
decl_stmt|;
name|UINT32
name|Unknown3
decl_stmt|;
name|UINT32
name|Unknown4
decl_stmt|;
name|UINT32
name|Unknown5
decl_stmt|;
comment|//
comment|// Filename of .PDB goes here
comment|//
block|}
name|EFI_IMAGE_DEBUG_CODEVIEW_RSDS_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Debug Data Structure defined by Apple Mach-O to Coff utility.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CODEVIEW_SIGNATURE_MTOC
value|SIGNATURE_32('M', 'T', 'O', 'C')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
comment|///< "MTOC".
name|GUID
name|MachOUuid
decl_stmt|;
comment|//
comment|//  Filename of .DLL (Mach-O with debug info) goes here
comment|//
block|}
name|EFI_IMAGE_DEBUG_CODEVIEW_MTOC_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Resource format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Characteristics
decl_stmt|;
name|UINT32
name|TimeDateStamp
decl_stmt|;
name|UINT16
name|MajorVersion
decl_stmt|;
name|UINT16
name|MinorVersion
decl_stmt|;
name|UINT16
name|NumberOfNamedEntries
decl_stmt|;
name|UINT16
name|NumberOfIdEntries
decl_stmt|;
comment|//
comment|// Array of EFI_IMAGE_RESOURCE_DIRECTORY_ENTRY entries goes here.
comment|//
block|}
name|EFI_IMAGE_RESOURCE_DIRECTORY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Resource directory entry format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
struct|struct
block|{
name|UINT32
name|NameOffset
range|:
literal|31
decl_stmt|;
name|UINT32
name|NameIsString
range|:
literal|1
decl_stmt|;
block|}
name|s
struct|;
name|UINT32
name|Id
decl_stmt|;
block|}
name|u1
union|;
union|union
block|{
name|UINT32
name|OffsetToData
decl_stmt|;
struct|struct
block|{
name|UINT32
name|OffsetToDirectory
range|:
literal|31
decl_stmt|;
name|UINT32
name|DataIsDirectory
range|:
literal|1
decl_stmt|;
block|}
name|s
struct|;
block|}
name|u2
union|;
block|}
name|EFI_IMAGE_RESOURCE_DIRECTORY_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Resource directory entry for string.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Length
decl_stmt|;
name|CHAR16
name|String
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IMAGE_RESOURCE_DIRECTORY_STRING
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Resource directory entry for data array.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|OffsetToData
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
name|UINT32
name|CodePage
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|EFI_IMAGE_RESOURCE_DATA_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Header format for TE images, defined in the PI Specification, 1.0.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Signature
decl_stmt|;
comment|///< The signature for TE format = "VZ".
name|UINT16
name|Machine
decl_stmt|;
comment|///< From the original file header.
name|UINT8
name|NumberOfSections
decl_stmt|;
comment|///< From the original file header.
name|UINT8
name|Subsystem
decl_stmt|;
comment|///< From original optional header.
name|UINT16
name|StrippedSize
decl_stmt|;
comment|///< Number of bytes we removed from the header.
name|UINT32
name|AddressOfEntryPoint
decl_stmt|;
comment|///< Offset to entry point -- from original optional header.
name|UINT32
name|BaseOfCode
decl_stmt|;
comment|///< From original image -- required for ITP debug.
name|UINT64
name|ImageBase
decl_stmt|;
comment|///< From original file header.
name|EFI_IMAGE_DATA_DIRECTORY
name|DataDirectory
index|[
literal|2
index|]
decl_stmt|;
comment|///< Only base relocation and debug directory.
block|}
name|EFI_TE_IMAGE_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_TE_IMAGE_HEADER_SIGNATURE
value|SIGNATURE_16('V', 'Z')
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Data directory indexes in our TE image header
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_TE_IMAGE_DIRECTORY_ENTRY_BASERELOC
value|0
end_define

begin_define
define|#
directive|define
name|EFI_TE_IMAGE_DIRECTORY_ENTRY_DEBUG
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Union of PE32, PE32+, and TE headers.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_IMAGE_NT_HEADERS32
name|Pe32
decl_stmt|;
name|EFI_IMAGE_NT_HEADERS64
name|Pe32Plus
decl_stmt|;
name|EFI_TE_IMAGE_HEADER
name|Te
decl_stmt|;
block|}
name|EFI_IMAGE_OPTIONAL_HEADER_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_IMAGE_NT_HEADERS32
modifier|*
name|Pe32
decl_stmt|;
name|EFI_IMAGE_NT_HEADERS64
modifier|*
name|Pe32Plus
decl_stmt|;
name|EFI_TE_IMAGE_HEADER
modifier|*
name|Te
decl_stmt|;
name|EFI_IMAGE_OPTIONAL_HEADER_UNION
modifier|*
name|Union
decl_stmt|;
block|}
name|EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

