begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pe.h  -  PE COFF header information      Copyright 2000, 2001 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* NT specific file attributes.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_RELOCS_STRIPPED
value|0x0001
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_EXECUTABLE_IMAGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_LINE_NUMS_STRIPPED
value|0x0004
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_LOCAL_SYMS_STRIPPED
value|0x0008
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_AGGRESSIVE_WS_TRIM
value|0x0010
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_LARGE_ADDRESS_AWARE
value|0x0020
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_16BIT_MACHINE
value|0x0040
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_BYTES_REVERSED_LO
value|0x0080
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_32BIT_MACHINE
value|0x0100
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_DEBUG_STRIPPED
value|0x0200
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP
value|0x0400
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_SYSTEM
value|0x1000
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_DLL
value|0x2000
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_UP_SYSTEM_ONLY
value|0x4000
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_BYTES_REVERSED_HI
value|0x8000
end_define

begin_comment
comment|/* Additional flags to be set for section headers to allow the NT loader to    read and write to the section data (to replace the addresses of data in    dlls for one thing); also to execute the section in .text's case.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_DISCARDABLE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_EXECUTE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_READ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_WRITE
value|0x80000000
end_define

begin_comment
comment|/* Section characteristics added for ppc-nt.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_TYPE_NO_PAD
value|0x00000008
end_define

begin_comment
comment|/* Reserved. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_CODE
value|0x00000020
end_define

begin_comment
comment|/* Section contains code. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_INITIALIZED_DATA
value|0x00000040
end_define

begin_comment
comment|/* Section contains initialized data. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_CNT_UNINITIALIZED_DATA
value|0x00000080
end_define

begin_comment
comment|/* Section contains uninitialized data. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_OTHER
value|0x00000100
end_define

begin_comment
comment|/* Reserved. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_INFO
value|0x00000200
end_define

begin_comment
comment|/* Section contains comments or some other type of information. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_REMOVE
value|0x00000800
end_define

begin_comment
comment|/* Section contents will not become part of image. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_COMDAT
value|0x00001000
end_define

begin_comment
comment|/* Section contents comdat. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_FARDATA
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_PURGEABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_16BIT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_LOCKED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_PRELOAD
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_1BYTES
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_2BYTES
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_4BYTES
value|0x00300000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_8BYTES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_16BYTES
value|0x00500000
end_define

begin_comment
comment|/* Default alignment if no others are specified. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_32BYTES
value|0x00600000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_ALIGN_64BYTES
value|0x00700000
end_define

begin_define
define|#
directive|define
name|IMAGE_SCN_LNK_NRELOC_OVFL
value|0x01000000
end_define

begin_comment
comment|/* Section contains extended relocations. */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_NOT_CACHED
value|0x04000000
end_define

begin_comment
comment|/* Section is not cachable.               */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_NOT_PAGED
value|0x08000000
end_define

begin_comment
comment|/* Section is not pageable.               */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SCN_MEM_SHARED
value|0x10000000
end_define

begin_comment
comment|/* Section is shareable.                  */
end_comment

begin_comment
comment|/* COMDAT selection codes.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_NODUPLICATES
value|(1)
end_define

begin_comment
comment|/* Warn if duplicates.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_ANY
value|(2)
end_define

begin_comment
comment|/* No warning.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_SAME_SIZE
value|(3)
end_define

begin_comment
comment|/* Warn if different size.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_EXACT_MATCH
value|(4)
end_define

begin_comment
comment|/* Warn if different.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_COMDAT_SELECT_ASSOCIATIVE
value|(5)
end_define

begin_comment
comment|/* Base on other section.  */
end_comment

begin_comment
comment|/* Machine numbers.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_UNKNOWN
value|0x0
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ALPHA
value|0x184
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ARM
value|0x1c0
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ALPHA64
value|0x284
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_I386
value|0x14c
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_IA64
value|0x200
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_M68K
value|0x268
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPS16
value|0x266
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPSFPU
value|0x366
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPSFPU16
value|0x466
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_POWERPC
value|0x1f0
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R3000
value|0x162
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R4000
value|0x166
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R10000
value|0x168
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH3
value|0x1a2
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH4
value|0x1a6
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_THUMB
value|0x1c2
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_NATIVE
value|1
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_GUI
value|2
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_CUI
value|3
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_POSIX_CUI
value|7
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_WINDOWS_CE_GUI
value|9
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_APPLICATION
value|10
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER
value|11
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER
value|12
end_define

begin_comment
comment|/* Magic values that are true for all dos/nt implementations.  */
end_comment

begin_define
define|#
directive|define
name|DOSMAGIC
value|0x5a4d
end_define

begin_define
define|#
directive|define
name|NT_SIGNATURE
value|0x00004550
end_define

begin_comment
comment|/* NT allows long filenames, we want to accommodate this.    This may break some of the bfd functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|FILNMLEN
end_undef

begin_define
define|#
directive|define
name|FILNMLEN
value|18
end_define

begin_comment
comment|/* # characters in a file name.  */
end_comment

begin_struct
struct|struct
name|external_PEI_DOS_hdr
block|{
comment|/* DOS header fields - always at offset zero in the EXE file.  */
name|char
name|e_magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* Magic number, 0x5a4d.  */
name|char
name|e_cblp
index|[
literal|2
index|]
decl_stmt|;
comment|/* Bytes on last page of file, 0x90.  */
name|char
name|e_cp
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pages in file, 0x3.  */
name|char
name|e_crlc
index|[
literal|2
index|]
decl_stmt|;
comment|/* Relocations, 0x0.  */
name|char
name|e_cparhdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* Size of header in paragraphs, 0x4.  */
name|char
name|e_minalloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* Minimum extra paragraphs needed, 0x0.  */
name|char
name|e_maxalloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* Maximum extra paragraphs needed, 0xFFFF.  */
name|char
name|e_ss
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial (relative) SS value, 0x0.  */
name|char
name|e_sp
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial SP value, 0xb8.  */
name|char
name|e_csum
index|[
literal|2
index|]
decl_stmt|;
comment|/* Checksum, 0x0.  */
name|char
name|e_ip
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial IP value, 0x0.  */
name|char
name|e_cs
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial (relative) CS value, 0x0.  */
name|char
name|e_lfarlc
index|[
literal|2
index|]
decl_stmt|;
comment|/* File address of relocation table, 0x40.  */
name|char
name|e_ovno
index|[
literal|2
index|]
decl_stmt|;
comment|/* Overlay number, 0x0.  */
name|char
name|e_res
index|[
literal|4
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved words, all 0x0.  */
name|char
name|e_oemid
index|[
literal|2
index|]
decl_stmt|;
comment|/* OEM identifier (for e_oeminfo), 0x0.  */
name|char
name|e_oeminfo
index|[
literal|2
index|]
decl_stmt|;
comment|/* OEM information; e_oemid specific, 0x0.  */
name|char
name|e_res2
index|[
literal|10
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved words, all 0x0.  */
name|char
name|e_lfanew
index|[
literal|4
index|]
decl_stmt|;
comment|/* File address of new exe header, usually 0x80.  */
name|char
name|dos_message
index|[
literal|16
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* Other stuff, always follow DOS header.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|external_PEI_IMAGE_hdr
block|{
name|char
name|nt_signature
index|[
literal|4
index|]
decl_stmt|;
comment|/* required NT signature, 0x4550.  */
comment|/* From standard header.  */
name|char
name|f_magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* Magic number.		*/
name|char
name|f_nscns
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of sections.		*/
name|char
name|f_timdat
index|[
literal|4
index|]
decl_stmt|;
comment|/* Time& date stamp.		*/
name|char
name|f_symptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* File pointer to symtab.	*/
name|char
name|f_nsyms
index|[
literal|4
index|]
decl_stmt|;
comment|/* Number of symtab entries.	*/
name|char
name|f_opthdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* Sizeof(optional hdr).	*/
name|char
name|f_flags
index|[
literal|2
index|]
decl_stmt|;
comment|/* Flags.			*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|external_PEI_filehdr
block|{
comment|/* DOS header fields - always at offset zero in the EXE file.  */
name|char
name|e_magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* Magic number, 0x5a4d.  */
name|char
name|e_cblp
index|[
literal|2
index|]
decl_stmt|;
comment|/* Bytes on last page of file, 0x90.  */
name|char
name|e_cp
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pages in file, 0x3.  */
name|char
name|e_crlc
index|[
literal|2
index|]
decl_stmt|;
comment|/* Relocations, 0x0.  */
name|char
name|e_cparhdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* Size of header in paragraphs, 0x4.  */
name|char
name|e_minalloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* Minimum extra paragraphs needed, 0x0.  */
name|char
name|e_maxalloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* Maximum extra paragraphs needed, 0xFFFF.  */
name|char
name|e_ss
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial (relative) SS value, 0x0.  */
name|char
name|e_sp
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial SP value, 0xb8.  */
name|char
name|e_csum
index|[
literal|2
index|]
decl_stmt|;
comment|/* Checksum, 0x0.  */
name|char
name|e_ip
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial IP value, 0x0.  */
name|char
name|e_cs
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initial (relative) CS value, 0x0.  */
name|char
name|e_lfarlc
index|[
literal|2
index|]
decl_stmt|;
comment|/* File address of relocation table, 0x40.  */
name|char
name|e_ovno
index|[
literal|2
index|]
decl_stmt|;
comment|/* Overlay number, 0x0.  */
name|char
name|e_res
index|[
literal|4
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved words, all 0x0.  */
name|char
name|e_oemid
index|[
literal|2
index|]
decl_stmt|;
comment|/* OEM identifier (for e_oeminfo), 0x0.  */
name|char
name|e_oeminfo
index|[
literal|2
index|]
decl_stmt|;
comment|/* OEM information; e_oemid specific, 0x0.  */
name|char
name|e_res2
index|[
literal|10
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved words, all 0x0.  */
name|char
name|e_lfanew
index|[
literal|4
index|]
decl_stmt|;
comment|/* File address of new exe header, usually 0x80.  */
name|char
name|dos_message
index|[
literal|16
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* Other stuff, always follow DOS header.  */
comment|/* Note: additional bytes may be inserted before the signature.  Use    the e_lfanew field to find the actual location of the NT signature.  */
name|char
name|nt_signature
index|[
literal|4
index|]
decl_stmt|;
comment|/* required NT signature, 0x4550.  */
comment|/* From standard header.  */
name|char
name|f_magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* Magic number.		*/
name|char
name|f_nscns
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of sections.		*/
name|char
name|f_timdat
index|[
literal|4
index|]
decl_stmt|;
comment|/* Time& date stamp.		*/
name|char
name|f_symptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* File pointer to symtab.	*/
name|char
name|f_nsyms
index|[
literal|4
index|]
decl_stmt|;
comment|/* Number of symtab entries.	*/
name|char
name|f_opthdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* Sizeof(optional hdr).	*/
name|char
name|f_flags
index|[
literal|2
index|]
decl_stmt|;
comment|/* Flags.			*/
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_IMAGE_WITH_PE
end_ifdef

begin_comment
comment|/* The filehdr is only weird in images.  */
end_comment

begin_undef
undef|#
directive|undef
name|FILHDR
end_undef

begin_define
define|#
directive|define
name|FILHDR
value|struct external_PEI_filehdr
end_define

begin_undef
undef|#
directive|undef
name|FILHSZ
end_undef

begin_define
define|#
directive|define
name|FILHSZ
value|152
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF_IMAGE_WITH_PE */
end_comment

begin_comment
comment|/* 32-bit PE a.out header: */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|AOUTHDR
name|standard
decl_stmt|;
comment|/* NT extra fields; see internal.h for descriptions.  */
name|char
name|ImageBase
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SectionAlignment
index|[
literal|4
index|]
decl_stmt|;
name|char
name|FileAlignment
index|[
literal|4
index|]
decl_stmt|;
name|char
name|MajorOperatingSystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MinorOperatingSystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MajorImageVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MinorImageVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MajorSubsystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MinorSubsystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|Reserved1
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SizeOfImage
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SizeOfHeaders
index|[
literal|4
index|]
decl_stmt|;
name|char
name|CheckSum
index|[
literal|4
index|]
decl_stmt|;
name|char
name|Subsystem
index|[
literal|2
index|]
decl_stmt|;
name|char
name|DllCharacteristics
index|[
literal|2
index|]
decl_stmt|;
name|char
name|SizeOfStackReserve
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SizeOfStackCommit
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SizeOfHeapReserve
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SizeOfHeapCommit
index|[
literal|4
index|]
decl_stmt|;
name|char
name|LoaderFlags
index|[
literal|4
index|]
decl_stmt|;
name|char
name|NumberOfRvaAndSizes
index|[
literal|4
index|]
decl_stmt|;
comment|/* IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];  */
name|char
name|DataDirectory
index|[
literal|16
index|]
index|[
literal|2
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* 16 entries, 2 elements/entry, 4 chars.  */
block|}
name|PEAOUTHDR
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|AOUTSZ
end_undef

begin_define
define|#
directive|define
name|AOUTSZ
value|(AOUTHDRSZ + 196)
end_define

begin_comment
comment|/* Like PEAOUTHDR, except that the "standard" member has no BaseOfData    (aka data_start) member and that some of the members are 8 instead    of just 4 bytes long.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|AOUTHDR
name|standard
decl_stmt|;
comment|/* NT extra fields; see internal.h for descriptions.  */
name|char
name|ImageBase
index|[
literal|8
index|]
decl_stmt|;
name|char
name|SectionAlignment
index|[
literal|4
index|]
decl_stmt|;
name|char
name|FileAlignment
index|[
literal|4
index|]
decl_stmt|;
name|char
name|MajorOperatingSystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MinorOperatingSystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MajorImageVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MinorImageVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MajorSubsystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|MinorSubsystemVersion
index|[
literal|2
index|]
decl_stmt|;
name|char
name|Reserved1
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SizeOfImage
index|[
literal|4
index|]
decl_stmt|;
name|char
name|SizeOfHeaders
index|[
literal|4
index|]
decl_stmt|;
name|char
name|CheckSum
index|[
literal|4
index|]
decl_stmt|;
name|char
name|Subsystem
index|[
literal|2
index|]
decl_stmt|;
name|char
name|DllCharacteristics
index|[
literal|2
index|]
decl_stmt|;
name|char
name|SizeOfStackReserve
index|[
literal|8
index|]
decl_stmt|;
name|char
name|SizeOfStackCommit
index|[
literal|8
index|]
decl_stmt|;
name|char
name|SizeOfHeapReserve
index|[
literal|8
index|]
decl_stmt|;
name|char
name|SizeOfHeapCommit
index|[
literal|8
index|]
decl_stmt|;
name|char
name|LoaderFlags
index|[
literal|4
index|]
decl_stmt|;
name|char
name|NumberOfRvaAndSizes
index|[
literal|4
index|]
decl_stmt|;
comment|/* IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];  */
name|char
name|DataDirectory
index|[
literal|16
index|]
index|[
literal|2
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* 16 entries, 2 elements/entry, 4 chars.  */
block|}
name|PEPAOUTHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PEPAOUTSZ
value|240
end_define

begin_undef
undef|#
directive|undef
name|E_FILNMLEN
end_undef

begin_define
define|#
directive|define
name|E_FILNMLEN
value|18
end_define

begin_comment
comment|/* # characters in a file name.  */
end_comment

begin_comment
comment|/* Import Tyoes fot ILF format object files..  */
end_comment

begin_define
define|#
directive|define
name|IMPORT_CODE
value|0
end_define

begin_define
define|#
directive|define
name|IMPORT_DATA
value|1
end_define

begin_define
define|#
directive|define
name|IMPORT_CONST
value|2
end_define

begin_comment
comment|/* Import Name Tyoes for ILF format object files.  */
end_comment

begin_define
define|#
directive|define
name|IMPORT_ORDINAL
value|0
end_define

begin_define
define|#
directive|define
name|IMPORT_NAME
value|1
end_define

begin_define
define|#
directive|define
name|IMPORT_NAME_NOPREFIX
value|2
end_define

begin_define
define|#
directive|define
name|IMPORT_NAME_UNDECORATE
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PE_H */
end_comment

end_unit

