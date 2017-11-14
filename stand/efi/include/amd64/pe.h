begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*      PE32+ header file  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PE_H
end_ifndef

begin_define
define|#
directive|define
name|_PE_H
end_define

begin_define
define|#
directive|define
name|IMAGE_DOS_SIGNATURE
value|0x5A4D
end_define

begin_comment
comment|// MZ
end_comment

begin_define
define|#
directive|define
name|IMAGE_OS2_SIGNATURE
value|0x454E
end_define

begin_comment
comment|// NE
end_comment

begin_define
define|#
directive|define
name|IMAGE_OS2_SIGNATURE_LE
value|0x454C
end_define

begin_comment
comment|// LE
end_comment

begin_define
define|#
directive|define
name|IMAGE_NT_SIGNATURE
value|0x00004550
end_define

begin_comment
comment|// PE00
end_comment

begin_define
define|#
directive|define
name|IMAGE_EDOS_SIGNATURE
value|0x44454550
end_define

begin_comment
comment|// PEED
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_DOS_HEADER
block|{
comment|// DOS .EXE header
name|UINT16
name|e_magic
decl_stmt|;
comment|// Magic number
name|UINT16
name|e_cblp
decl_stmt|;
comment|// Bytes on last page of file
name|UINT16
name|e_cp
decl_stmt|;
comment|// Pages in file
name|UINT16
name|e_crlc
decl_stmt|;
comment|// Relocations
name|UINT16
name|e_cparhdr
decl_stmt|;
comment|// Size of header in paragraphs
name|UINT16
name|e_minalloc
decl_stmt|;
comment|// Minimum extra paragraphs needed
name|UINT16
name|e_maxalloc
decl_stmt|;
comment|// Maximum extra paragraphs needed
name|UINT16
name|e_ss
decl_stmt|;
comment|// Initial (relative) SS value
name|UINT16
name|e_sp
decl_stmt|;
comment|// Initial SP value
name|UINT16
name|e_csum
decl_stmt|;
comment|// Checksum
name|UINT16
name|e_ip
decl_stmt|;
comment|// Initial IP value
name|UINT16
name|e_cs
decl_stmt|;
comment|// Initial (relative) CS value
name|UINT16
name|e_lfarlc
decl_stmt|;
comment|// File address of relocation table
name|UINT16
name|e_ovno
decl_stmt|;
comment|// Overlay number
name|UINT16
name|e_res
index|[
literal|4
index|]
decl_stmt|;
comment|// Reserved words
name|UINT16
name|e_oemid
decl_stmt|;
comment|// OEM identifier (for e_oeminfo)
name|UINT16
name|e_oeminfo
decl_stmt|;
comment|// OEM information; e_oemid specific
name|UINT16
name|e_res2
index|[
literal|10
index|]
decl_stmt|;
comment|// Reserved words
name|UINT32
name|e_lfanew
decl_stmt|;
comment|// File address of new exe header
block|}
name|IMAGE_DOS_HEADER
operator|,
typedef|*
name|PIMAGE_DOS_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_OS2_HEADER
block|{
comment|// OS/2 .EXE header
name|UINT16
name|ne_magic
decl_stmt|;
comment|// Magic number
name|UINT8
name|ne_ver
decl_stmt|;
comment|// Version number
name|UINT8
name|ne_rev
decl_stmt|;
comment|// Revision number
name|UINT16
name|ne_enttab
decl_stmt|;
comment|// Offset of Entry Table
name|UINT16
name|ne_cbenttab
decl_stmt|;
comment|// Number of bytes in Entry Table
name|UINT32
name|ne_crc
decl_stmt|;
comment|// Checksum of whole file
name|UINT16
name|ne_flags
decl_stmt|;
comment|// Flag UINT16
name|UINT16
name|ne_autodata
decl_stmt|;
comment|// Automatic data segment number
name|UINT16
name|ne_heap
decl_stmt|;
comment|// Initial heap allocation
name|UINT16
name|ne_stack
decl_stmt|;
comment|// Initial stack allocation
name|UINT32
name|ne_csip
decl_stmt|;
comment|// Initial CS:IP setting
name|UINT32
name|ne_sssp
decl_stmt|;
comment|// Initial SS:SP setting
name|UINT16
name|ne_cseg
decl_stmt|;
comment|// Count of file segments
name|UINT16
name|ne_cmod
decl_stmt|;
comment|// Entries in Module Reference Table
name|UINT16
name|ne_cbnrestab
decl_stmt|;
comment|// Size of non-resident name table
name|UINT16
name|ne_segtab
decl_stmt|;
comment|// Offset of Segment Table
name|UINT16
name|ne_rsrctab
decl_stmt|;
comment|// Offset of Resource Table
name|UINT16
name|ne_restab
decl_stmt|;
comment|// Offset of resident name table
name|UINT16
name|ne_modtab
decl_stmt|;
comment|// Offset of Module Reference Table
name|UINT16
name|ne_imptab
decl_stmt|;
comment|// Offset of Imported Names Table
name|UINT32
name|ne_nrestab
decl_stmt|;
comment|// Offset of Non-resident Names Table
name|UINT16
name|ne_cmovent
decl_stmt|;
comment|// Count of movable entries
name|UINT16
name|ne_align
decl_stmt|;
comment|// Segment alignment shift count
name|UINT16
name|ne_cres
decl_stmt|;
comment|// Count of resource segments
name|UINT8
name|ne_exetyp
decl_stmt|;
comment|// Target Operating system
name|UINT8
name|ne_flagsothers
decl_stmt|;
comment|// Other .EXE flags
name|UINT16
name|ne_pretthunks
decl_stmt|;
comment|// offset to return thunks
name|UINT16
name|ne_psegrefbytes
decl_stmt|;
comment|// offset to segment ref. bytes
name|UINT16
name|ne_swaparea
decl_stmt|;
comment|// Minimum code swap area size
name|UINT16
name|ne_expver
decl_stmt|;
comment|// Expected Windows version number
block|}
name|IMAGE_OS2_HEADER
operator|,
typedef|*
name|PIMAGE_OS2_HEADER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// File header format.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_FILE_HEADER
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
name|IMAGE_FILE_HEADER
operator|,
typedef|*
name|PIMAGE_FILE_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_FILE_HEADER
value|20
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_RELOCS_STRIPPED
value|0x0001
end_define

begin_comment
comment|// Relocation info stripped from file.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_EXECUTABLE_IMAGE
value|0x0002
end_define

begin_comment
comment|// File is executable  (i.e. no unresolved externel references).
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_LINE_NUMS_STRIPPED
value|0x0004
end_define

begin_comment
comment|// Line nunbers stripped from file.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_LOCAL_SYMS_STRIPPED
value|0x0008
end_define

begin_comment
comment|// Local symbols stripped from file.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_BYTES_REVERSED_LO
value|0x0080
end_define

begin_comment
comment|// Bytes of machine word are reversed.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_32BIT_MACHINE
value|0x0100
end_define

begin_comment
comment|// 32 bit word machine.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_DEBUG_STRIPPED
value|0x0200
end_define

begin_comment
comment|// Debugging info stripped from file in .DBG file
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_SYSTEM
value|0x1000
end_define

begin_comment
comment|// System File.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_DLL
value|0x2000
end_define

begin_comment
comment|// File is a DLL.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_BYTES_REVERSED_HI
value|0x8000
end_define

begin_comment
comment|// Bytes of machine word are reversed.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_I386
value|0x14c
end_define

begin_comment
comment|// Intel 386.
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R3000
value|0x162
end_define

begin_comment
comment|// MIPS little-endian, 0540 big-endian
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R4000
value|0x166
end_define

begin_comment
comment|// MIPS little-endian
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ALPHA
value|0x184
end_define

begin_comment
comment|// Alpha_AXP
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_POWERPC
value|0x1F0
end_define

begin_comment
comment|// IBM PowerPC Little-Endian
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_TAHOE
value|0x7cc
end_define

begin_comment
comment|// Intel EM machine
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Directory format.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_DATA_DIRECTORY
block|{
name|UINT32
name|VirtualAddress
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
block|}
name|IMAGE_DATA_DIRECTORY
operator|,
typedef|*
name|PIMAGE_DATA_DIRECTORY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_NUMBEROF_DIRECTORY_ENTRIES
value|16
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Optional header format.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_OPTIONAL_HEADER
block|{
comment|//
comment|// Standard fields.
comment|//
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
comment|//
comment|// NT additional fields.
comment|//
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
name|Reserved1
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
name|IMAGE_DATA_DIRECTORY
name|DataDirectory
index|[
name|IMAGE_NUMBEROF_DIRECTORY_ENTRIES
index|]
decl_stmt|;
block|}
name|IMAGE_OPTIONAL_HEADER
operator|,
typedef|*
name|PIMAGE_OPTIONAL_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_ROM_OPTIONAL_HEADER
block|{
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
name|UINT32
name|BaseOfBss
decl_stmt|;
name|UINT32
name|GprMask
decl_stmt|;
name|UINT32
name|CprMask
index|[
literal|4
index|]
decl_stmt|;
name|UINT32
name|GpValue
decl_stmt|;
block|}
name|IMAGE_ROM_OPTIONAL_HEADER
operator|,
typedef|*
name|PIMAGE_ROM_OPTIONAL_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_ROM_OPTIONAL_HEADER
value|56
end_define

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_STD_OPTIONAL_HEADER
value|28
end_define

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_NT_OPTIONAL_HEADER
value|224
end_define

begin_define
define|#
directive|define
name|IMAGE_NT_OPTIONAL_HDR_MAGIC
value|0x10b
end_define

begin_define
define|#
directive|define
name|IMAGE_ROM_OPTIONAL_HDR_MAGIC
value|0x107
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_NT_HEADERS
block|{
name|UINT32
name|Signature
decl_stmt|;
name|IMAGE_FILE_HEADER
name|FileHeader
decl_stmt|;
name|IMAGE_OPTIONAL_HEADER
name|OptionalHeader
decl_stmt|;
block|}
name|IMAGE_NT_HEADERS
operator|,
typedef|*
name|PIMAGE_NT_HEADERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_ROM_HEADERS
block|{
name|IMAGE_FILE_HEADER
name|FileHeader
decl_stmt|;
name|IMAGE_ROM_OPTIONAL_HEADER
name|OptionalHeader
decl_stmt|;
block|}
name|IMAGE_ROM_HEADERS
operator|,
typedef|*
name|PIMAGE_ROM_HEADERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_FIRST_SECTION
parameter_list|(
name|ntheader
parameter_list|)
value|((PIMAGE_SECTION_HEADER)        \     ((UINT32)ntheader +                                                  \      FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \      ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader   \     ))
end_define

begin_comment
comment|// Subsystem Values
end_comment

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_UNKNOWN
value|0
end_define

begin_comment
comment|// Unknown subsystem.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_NATIVE
value|1
end_define

begin_comment
comment|// Image doesn't require a subsystem.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_GUI
value|2
end_define

begin_comment
comment|// Image runs in the Windows GUI subsystem.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_CUI
value|3
end_define

begin_comment
comment|// Image runs in the Windows character subsystem.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_OS2_CUI
value|5
end_define

begin_comment
comment|// image runs in the OS/2 character subsystem.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_POSIX_CUI
value|7
end_define

begin_comment
comment|// image run  in the Posix character subsystem.
end_comment

begin_comment
comment|// Directory Entries
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_EXPORT
value|0
end_define

begin_comment
comment|// Export Directory
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_IMPORT
value|1
end_define

begin_comment
comment|// Import Directory
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_RESOURCE
value|2
end_define

begin_comment
comment|// Resource Directory
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_EXCEPTION
value|3
end_define

begin_comment
comment|// Exception Directory
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_SECURITY
value|4
end_define

begin_comment
comment|// Security Directory
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_BASERELOC
value|5
end_define

begin_comment
comment|// Base Relocation Table
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_DEBUG
value|6
end_define

begin_comment
comment|// Debug Directory
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_COPYRIGHT
value|7
end_define

begin_comment
comment|// Description String
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_GLOBALPTR
value|8
end_define

begin_comment
comment|// Machine Value (MIPS GP)
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_TLS
value|9
end_define

begin_comment
comment|// TLS Directory
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG
value|10
end_define

begin_comment
comment|// Load Configuration Directory
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Section header format.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_SHORT_NAME
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_SECTION_HEADER
block|{
name|UINT8
name|Name
index|[
name|IMAGE_SIZEOF_SHORT_NAME
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
name|IMAGE_SECTION_HEADER
operator|,
typedef|*
name|PIMAGE_SECTION_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_SECTION_HEADER
value|40
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_TYPE_NO_PAD
value|0x00000008
end_define

begin_comment
comment|// Reserved.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_CODE
value|0x00000020
end_define

begin_comment
comment|// Section contains code.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_INITIALIZED_DATA
value|0x00000040
end_define

begin_comment
comment|// Section contains initialized data.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_UNINITIALIZED_DATA
value|0x00000080
end_define

begin_comment
comment|// Section contains uninitialized data.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_OTHER
value|0x00000100
end_define

begin_comment
comment|// Reserved.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_INFO
value|0x00000200
end_define

begin_comment
comment|// Section contains comments or some other type of information.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_REMOVE
value|0x00000800
end_define

begin_comment
comment|// Section contents will not become part of image.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_COMDAT
value|0x00001000
end_define

begin_comment
comment|// Section contents comdat.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_1BYTES
value|0x00100000
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_2BYTES
value|0x00200000
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_4BYTES
value|0x00300000
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_8BYTES
value|0x00400000
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_16BYTES
value|0x00500000
end_define

begin_comment
comment|// Default alignment if no others are specified.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_32BYTES
value|0x00600000
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_64BYTES
value|0x00700000
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_DISCARDABLE
value|0x02000000
end_define

begin_comment
comment|// Section can be discarded.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_NOT_CACHED
value|0x04000000
end_define

begin_comment
comment|// Section is not cachable.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_NOT_PAGED
value|0x08000000
end_define

begin_comment
comment|// Section is not pageable.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_SHARED
value|0x10000000
end_define

begin_comment
comment|// Section is shareable.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_EXECUTE
value|0x20000000
end_define

begin_comment
comment|// Section is executable.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_READ
value|0x40000000
end_define

begin_comment
comment|// Section is readable.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_WRITE
value|0x80000000
end_define

begin_comment
comment|// Section is writeable.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Symbol format.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_SYMBOL
value|18
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Section values.
end_comment

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
name|IMAGE_SYM_UNDEFINED
value|(UINT16)0
end_define

begin_comment
comment|// Symbol is undefined or is common.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_ABSOLUTE
value|(UINT16)-1
end_define

begin_comment
comment|// Symbol is an absolute value.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_DEBUG
value|(UINT16)-2
end_define

begin_comment
comment|// Symbol is a special debug item.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Type (fundamental) values.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_NULL
value|0
end_define

begin_comment
comment|// no type.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_VOID
value|1
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_CHAR
value|2
end_define

begin_comment
comment|// type character.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_SHORT
value|3
end_define

begin_comment
comment|// type short integer.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_INT
value|4
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_LONG
value|5
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_FLOAT
value|6
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_DOUBLE
value|7
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_STRUCT
value|8
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_UNION
value|9
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_ENUM
value|10
end_define

begin_comment
comment|// enumeration.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_MOE
value|11
end_define

begin_comment
comment|// member of enumeration.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_BYTE
value|12
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_WORD
value|13
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_UINT
value|14
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_TYPE_DWORD
value|15
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Type (derived) values.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_DTYPE_NULL
value|0
end_define

begin_comment
comment|// no derived type.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_DTYPE_POINTER
value|1
end_define

begin_comment
comment|// pointer.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_DTYPE_FUNCTION
value|2
end_define

begin_comment
comment|// function.
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_DTYPE_ARRAY
value|3
end_define

begin_comment
comment|// array.
end_comment

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
name|IMAGE_SYM_CLASS_END_OF_FUNCTION
value|(BYTE )-1
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_NULL
value|0
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_AUTOMATIC
value|1
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_EXTERNAL
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_STATIC
value|3
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_REGISTER
value|4
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_EXTERNAL_DEF
value|5
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_LABEL
value|6
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_UNDEFINED_LABEL
value|7
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_MEMBER_OF_STRUCT
value|8
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_ARGUMENT
value|9
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_STRUCT_TAG
value|10
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_MEMBER_OF_UNION
value|11
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_UNION_TAG
value|12
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_TYPE_DEFINITION
value|13
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_UNDEFINED_STATIC
value|14
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_ENUM_TAG
value|15
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_MEMBER_OF_ENUM
value|16
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_REGISTER_PARAM
value|17
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_BIT_FIELD
value|18
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_BLOCK
value|100
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_FUNCTION
value|101
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_END_OF_STRUCT
value|102
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_FILE
value|103
end_define

begin_comment
comment|// new
end_comment

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_SECTION
value|104
end_define

begin_define
define|#
directive|define
name|IMAGE_SYM_CLASS_WEAK_EXTERNAL
value|105
end_define

begin_comment
comment|// type packing constants
end_comment

begin_define
define|#
directive|define
name|N_BTMASK
value|017
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|060
end_define

begin_define
define|#
directive|define
name|N_TMASK1
value|0300
end_define

begin_define
define|#
directive|define
name|N_TMASK2
value|0360
end_define

begin_define
define|#
directive|define
name|N_BTSHFT
value|4
end_define

begin_define
define|#
directive|define
name|N_TSHIFT
value|2
end_define

begin_comment
comment|// MACROS
end_comment

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
name|IMAGE_COMDAT_SELECT_NODUPLICATES
value|1
end_define

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_ANY
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_SAME_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_EXACT_MATCH
value|4
end_define

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_ASSOCIATIVE
value|5
end_define

begin_define
define|#
directive|define
name|IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY
value|1
end_define

begin_define
define|#
directive|define
name|IMAGE_WEAK_EXTERN_SEARCH_LIBRARY
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_WEAK_EXTERN_SEARCH_ALIAS
value|3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Relocation format.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_RELOCATION
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
name|IMAGE_RELOCATION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_RELOCATION
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
name|IMAGE_REL_I386_ABSOLUTE
value|0
end_define

begin_comment
comment|// Reference is absolute, no relocation is necessary
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_I386_DIR16
value|01
end_define

begin_comment
comment|// Direct 16-bit reference to the symbols virtual address
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_I386_REL16
value|02
end_define

begin_comment
comment|// PC-relative 16-bit reference to the symbols virtual address
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_I386_DIR32
value|06
end_define

begin_comment
comment|// Direct 32-bit reference to the symbols virtual address
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_I386_DIR32NB
value|07
end_define

begin_comment
comment|// Direct 32-bit reference to the symbols virtual address, base not included
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_I386_SEG12
value|011
end_define

begin_comment
comment|// Direct 16-bit reference to the segment-selector bits of a 32-bit virtual address
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_I386_SECTION
value|012
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_I386_SECREL
value|013
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_I386_REL32
value|024
end_define

begin_comment
comment|// PC-relative 32-bit reference to the symbols virtual address
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS relocation types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_ABSOLUTE
value|0
end_define

begin_comment
comment|// Reference is absolute, no relocation is necessary
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_REFHALF
value|01
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_REFWORD
value|02
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_JMPADDR
value|03
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_REFHI
value|04
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_REFLO
value|05
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_GPREL
value|06
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_LITERAL
value|07
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_SECTION
value|012
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_SECREL
value|013
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_REFWORDNB
value|042
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_MIPS_PAIR
value|045
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Alpha Relocation types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_ABSOLUTE
value|0x0
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_REFLONG
value|0x1
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_REFQUAD
value|0x2
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_GPREL32
value|0x3
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_LITERAL
value|0x4
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_LITUSE
value|0x5
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_GPDISP
value|0x6
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_BRADDR
value|0x7
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_HINT
value|0x8
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_INLINE_REFLONG
value|0x9
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_REFHI
value|0xA
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_REFLO
value|0xB
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_PAIR
value|0xC
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_MATCH
value|0xD
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_SECTION
value|0xE
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_SECREL
value|0xF
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_ALPHA_REFLONGNB
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// IBM PowerPC relocation types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_ABSOLUTE
value|0x0000
end_define

begin_comment
comment|// NOP
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_ADDR64
value|0x0001
end_define

begin_comment
comment|// 64-bit address
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_ADDR32
value|0x0002
end_define

begin_comment
comment|// 32-bit address
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_ADDR24
value|0x0003
end_define

begin_comment
comment|// 26-bit address, shifted left 2 (branch absolute)
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_ADDR16
value|0x0004
end_define

begin_comment
comment|// 16-bit address
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_ADDR14
value|0x0005
end_define

begin_comment
comment|// 16-bit address, shifted left 2 (load doubleword)
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_REL24
value|0x0006
end_define

begin_comment
comment|// 26-bit PC-relative offset, shifted left 2 (branch relative)
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_REL14
value|0x0007
end_define

begin_comment
comment|// 16-bit PC-relative offset, shifted left 2 (br cond relative)
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_TOCREL16
value|0x0008
end_define

begin_comment
comment|// 16-bit offset from TOC base
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_TOCREL14
value|0x0009
end_define

begin_comment
comment|// 16-bit offset from TOC base, shifted left 2 (load doubleword)
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_ADDR32NB
value|0x000A
end_define

begin_comment
comment|// 32-bit addr w/o image base
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_SECREL
value|0x000B
end_define

begin_comment
comment|// va of containing section (as in an image sectionhdr)
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_SECTION
value|0x000C
end_define

begin_comment
comment|// sectionheader number
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_IFGLUE
value|0x000D
end_define

begin_comment
comment|// substitute TOC restore instruction iff symbol is glue code
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_IMGLUE
value|0x000E
end_define

begin_comment
comment|// symbol is glue code; virtual address is TOC restore instruction
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_TYPEMASK
value|0x00FF
end_define

begin_comment
comment|// mask to isolate above values in IMAGE_RELOCATION.Type
end_comment

begin_comment
comment|// Flag bits in IMAGE_RELOCATION.TYPE
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_NEG
value|0x0100
end_define

begin_comment
comment|// subtract reloc value rather than adding it
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_BRTAKEN
value|0x0200
end_define

begin_comment
comment|// fix branch prediction bit to predict branch taken
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_BRNTAKEN
value|0x0400
end_define

begin_comment
comment|// fix branch prediction bit to predict branch not taken
end_comment

begin_define
define|#
directive|define
name|IMAGE_REL_PPC_TOCDEFN
value|0x0800
end_define

begin_comment
comment|// toc slot defined in file (or, data in toc)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Based relocation format.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_BASE_RELOCATION
block|{
name|UINT32
name|VirtualAddress
decl_stmt|;
name|UINT32
name|SizeOfBlock
decl_stmt|;
comment|//  UINT16    TypeOffset[1];
block|}
name|IMAGE_BASE_RELOCATION
operator|,
typedef|*
name|PIMAGE_BASE_RELOCATION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_BASE_RELOCATION
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
name|IMAGE_REL_BASED_ABSOLUTE
value|0
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_LOW
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_HIGHLOW
value|3
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_HIGHADJ
value|4
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_MIPS_JMPADDR
value|5
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_DIR64
value|10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Line number format.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_LINENUMBER
block|{
union|union
block|{
name|UINT32
name|SymbolTableIndex
decl_stmt|;
comment|// Symbol table index of function name if Linenumber is 0.
name|UINT32
name|VirtualAddress
decl_stmt|;
comment|// Virtual address of line number.
block|}
name|Type
union|;
name|UINT16
name|Linenumber
decl_stmt|;
comment|// Line number.
block|}
name|IMAGE_LINENUMBER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_LINENUMBER
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
name|IMAGE_ARCHIVE_START_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|IMAGE_ARCHIVE_START
value|"!<arch>\n"
end_define

begin_define
define|#
directive|define
name|IMAGE_ARCHIVE_END
value|"`\n"
end_define

begin_define
define|#
directive|define
name|IMAGE_ARCHIVE_PAD
value|"\n"
end_define

begin_define
define|#
directive|define
name|IMAGE_ARCHIVE_LINKER_MEMBER
value|"/               "
end_define

begin_define
define|#
directive|define
name|IMAGE_ARCHIVE_LONGNAMES_MEMBER
value|"//              "
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_ARCHIVE_MEMBER_HEADER
block|{
name|UINT8
name|Name
index|[
literal|16
index|]
decl_stmt|;
comment|// File member name - `/' terminated.
name|UINT8
name|Date
index|[
literal|12
index|]
decl_stmt|;
comment|// File member date - decimal.
name|UINT8
name|UserID
index|[
literal|6
index|]
decl_stmt|;
comment|// File member user id - decimal.
name|UINT8
name|GroupID
index|[
literal|6
index|]
decl_stmt|;
comment|// File member group id - decimal.
name|UINT8
name|Mode
index|[
literal|8
index|]
decl_stmt|;
comment|// File member mode - octal.
name|UINT8
name|Size
index|[
literal|10
index|]
decl_stmt|;
comment|// File member size - decimal.
name|UINT8
name|EndHeader
index|[
literal|2
index|]
decl_stmt|;
comment|// String to end header.
block|}
name|IMAGE_ARCHIVE_MEMBER_HEADER
operator|,
typedef|*
name|PIMAGE_ARCHIVE_MEMBER_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR
value|60
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// DLL support.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Export Format
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_EXPORT_DIRECTORY
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
modifier|*
name|AddressOfFunctions
decl_stmt|;
name|UINT32
modifier|*
name|AddressOfNames
decl_stmt|;
name|UINT32
modifier|*
name|AddressOfNameOrdinals
decl_stmt|;
block|}
name|IMAGE_EXPORT_DIRECTORY
operator|,
typedef|*
name|PIMAGE_EXPORT_DIRECTORY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Import Format
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_IMPORT_BY_NAME
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
name|IMAGE_IMPORT_BY_NAME
operator|,
typedef|*
name|PIMAGE_IMPORT_BY_NAME
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_THUNK_DATA
block|{
union|union
block|{
name|UINT32
name|Function
decl_stmt|;
name|UINT32
name|Ordinal
decl_stmt|;
name|PIMAGE_IMPORT_BY_NAME
name|AddressOfData
decl_stmt|;
block|}
name|u1
union|;
block|}
name|IMAGE_THUNK_DATA
operator|,
typedef|*
name|PIMAGE_THUNK_DATA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_ORDINAL_FLAG
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SNAP_BY_ORDINAL
parameter_list|(
name|Ordinal
parameter_list|)
value|((Ordinal& IMAGE_ORDINAL_FLAG) != 0)
end_define

begin_define
define|#
directive|define
name|IMAGE_ORDINAL
parameter_list|(
name|Ordinal
parameter_list|)
value|(Ordinal& 0xffff)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IMAGE_IMPORT_DESCRIPTOR
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
name|PIMAGE_THUNK_DATA
name|FirstThunk
decl_stmt|;
block|}
name|IMAGE_IMPORT_DESCRIPTOR
operator|,
typedef|*
name|PIMAGE_IMPORT_DESCRIPTOR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

