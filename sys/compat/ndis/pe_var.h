begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PE_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_PE_VAR_H_
end_define

begin_comment
comment|/*  *  Image Format  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DOS_SIGNATURE
value|0x5A4D
end_define

begin_comment
comment|/* MZ */
end_comment

begin_define
define|#
directive|define
name|IMAGE_OS2_SIGNATURE
value|0x454E
end_define

begin_comment
comment|/* NE */
end_comment

begin_define
define|#
directive|define
name|IMAGE_OS2_SIGNATURE_LE
value|0x454C
end_define

begin_comment
comment|/* LE */
end_comment

begin_define
define|#
directive|define
name|IMAGE_VXD_SIGNATURE
value|0x454C
end_define

begin_comment
comment|/* LE */
end_comment

begin_define
define|#
directive|define
name|IMAGE_NT_SIGNATURE
value|0x00004550
end_define

begin_comment
comment|/* PE00 */
end_comment

begin_comment
comment|/*  * All PE files have one of these, just so if you attempt to  * run them, they'll print out a message telling you they can  * only be run in Windows.  */
end_comment

begin_struct
struct|struct
name|image_dos_header
block|{
name|uint16_t
name|idh_magic
decl_stmt|;
comment|/* Magic number */
name|uint16_t
name|idh_cblp
decl_stmt|;
comment|/* Bytes on last page of file */
name|uint16_t
name|idh_cp
decl_stmt|;
comment|/* Pages in file */
name|uint16_t
name|idh_crlc
decl_stmt|;
comment|/* Relocations */
name|uint16_t
name|idh_cparhdr
decl_stmt|;
comment|/* Size of header in paragraphs */
name|uint16_t
name|idh_minalloc
decl_stmt|;
comment|/* Minimum extra paragraphs needed */
name|uint16_t
name|idh_maxalloc
decl_stmt|;
comment|/* Maximum extra paragraphs needed */
name|uint16_t
name|idh_ss
decl_stmt|;
comment|/* Initial (relative) SS value */
name|uint16_t
name|idh_sp
decl_stmt|;
comment|/* Initial SP value */
name|uint16_t
name|idh_csum
decl_stmt|;
comment|/* Checksum */
name|uint16_t
name|idh_ip
decl_stmt|;
comment|/* Initial IP value */
name|uint16_t
name|idh_cs
decl_stmt|;
comment|/* Initial (relative) CS value */
name|uint16_t
name|idh_lfarlc
decl_stmt|;
comment|/* File address of relocation table */
name|uint16_t
name|idh_ovno
decl_stmt|;
comment|/* Overlay number */
name|uint16_t
name|idh_rsvd1
index|[
literal|4
index|]
decl_stmt|;
comment|/* Reserved words */
name|uint16_t
name|idh_oemid
decl_stmt|;
comment|/* OEM identifier (for idh_oeminfo) */
name|uint16_t
name|idh_oeminfo
decl_stmt|;
comment|/* OEM information; oemid specific */
name|uint16_t
name|idh_rsvd2
index|[
literal|10
index|]
decl_stmt|;
comment|/* Reserved words */
name|uint32_t
name|idh_lfanew
decl_stmt|;
comment|/* File address of new exe header */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_dos_header
name|image_dos_header
typedef|;
end_typedef

begin_comment
comment|/*  * File header format.  */
end_comment

begin_struct
struct|struct
name|image_file_header
block|{
name|uint16_t
name|ifh_machine
decl_stmt|;
comment|/* Machine type */
name|uint16_t
name|ifh_numsections
decl_stmt|;
comment|/* # of sections */
name|uint32_t
name|ifh_timestamp
decl_stmt|;
comment|/* Date/time stamp */
name|uint32_t
name|ifh_symtblptr
decl_stmt|;
comment|/* Offset to symbol table */
name|uint32_t
name|ifh_numsyms
decl_stmt|;
comment|/* # of symbols */
name|uint16_t
name|ifh_optionalhdrlen
decl_stmt|;
comment|/* Size of optional header */
name|uint16_t
name|ifh_characteristics
decl_stmt|;
comment|/* Characteristics */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_file_header
name|image_file_header
typedef|;
end_typedef

begin_comment
comment|/* Machine types */
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
name|IMAGE_FILE_MACHINE_I860
value|0x014d
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_I386
value|0x014c
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R3000
value|0x0162
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R4000
value|0x0166
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_R10000
value|0x0168
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_WCEMIPSV2
value|0x0169
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ALPHA
value|0x0184
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH3
value|0x01a2
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH3DSP
value|0x01a3
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH3E
value|0x01a4
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH4
value|0x01a6
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_SH5
value|0x01a8
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ARM
value|0x01c0
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_THUMB
value|0x01c2
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_AM33
value|0x01d3
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_POWERPC
value|0x01f0
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_POWERPCFP
value|0x01f1
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPS16
value|0x0266
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_ALPHA64
value|0x0284
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPSFPU
value|0x0366
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_MIPSFPU16
value|0x0466
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_AXP64
value|IMAGE_FILE_MACHINE_ALPHA64
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_TRICORE
value|0x0520
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_CEF
value|0x0cef
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_EBC
value|0x0ebc
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_AMD64
value|0x8664
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_M32R
value|0x9041
end_define

begin_define
define|#
directive|define
name|IMAGE_FILE_MACHINE_CEE
value|0xc0ee
end_define

begin_comment
comment|/* Characteristics */
end_comment

begin_define
define|#
directive|define
name|IMAGE_FILE_RELOCS_STRIPPED
value|0x0001
end_define

begin_comment
comment|/* No relocation info */
end_comment

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
name|IMAGE_FILE_AGGRESIVE_WS_TRIM
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
name|IMAGE_FILE_NET_RUN_FROM_SWAP
value|0x0800
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

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_FILE_HEADER
value|20
end_define

begin_comment
comment|/*  * Directory format.  */
end_comment

begin_struct
struct|struct
name|image_data_directory
block|{
name|uint32_t
name|idd_vaddr
decl_stmt|;
comment|/* virtual address */
name|uint32_t
name|idd_size
decl_stmt|;
comment|/* size */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_data_directory
name|image_data_directory
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRIES_MAX
value|16
end_define

begin_comment
comment|/*  * Optional header format.  */
end_comment

begin_struct
struct|struct
name|image_optional_header
block|{
comment|/* Standard fields */
name|uint16_t
name|ioh_magic
decl_stmt|;
name|uint8_t
name|ioh_linkerver_major
decl_stmt|;
name|uint8_t
name|ioh_linkerver_minor
decl_stmt|;
name|uint32_t
name|ioh_codesize
decl_stmt|;
name|uint32_t
name|ioh_datasize
decl_stmt|;
name|uint32_t
name|ioh_bsssize
decl_stmt|;
name|uint32_t
name|ioh_entryaddr
decl_stmt|;
name|uint32_t
name|ioh_codebaseaddr
decl_stmt|;
ifndef|#
directive|ifndef
name|__amd64__
name|uint32_t
name|ioh_databaseaddr
decl_stmt|;
endif|#
directive|endif
comment|/* NT-specific fields */
name|uintptr_t
name|ioh_imagebase
decl_stmt|;
name|uint32_t
name|ioh_sectalign
decl_stmt|;
name|uint32_t
name|ioh_filealign
decl_stmt|;
name|uint16_t
name|ioh_osver_major
decl_stmt|;
name|uint16_t
name|ioh_osver_minor
decl_stmt|;
name|uint16_t
name|ioh_imagever_major
decl_stmt|;
name|uint16_t
name|ioh_imagever_minor
decl_stmt|;
name|uint16_t
name|ioh_subsys_major
decl_stmt|;
name|uint16_t
name|ioh_subsys_minor
decl_stmt|;
name|uint32_t
name|ioh_win32ver
decl_stmt|;
name|uint32_t
name|ioh_imagesize
decl_stmt|;
name|uint32_t
name|ioh_headersize
decl_stmt|;
name|uint32_t
name|ioh_csum
decl_stmt|;
name|uint16_t
name|ioh_subsys
decl_stmt|;
name|uint16_t
name|ioh_dll_characteristics
decl_stmt|;
name|uintptr_t
name|ioh_stackreservesize
decl_stmt|;
name|uintptr_t
name|ioh_stackcommitsize
decl_stmt|;
name|uintptr_t
name|ioh_heapreservesize
decl_stmt|;
name|uintptr_t
name|ioh_heapcommitsize
decl_stmt|;
name|uint16_t
name|ioh_loaderflags
decl_stmt|;
name|uint32_t
name|ioh_rva_size_cnt
decl_stmt|;
name|image_data_directory
name|ioh_datadir
index|[
name|IMAGE_DIRECTORY_ENTRIES_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_optional_header
name|image_optional_header
typedef|;
end_typedef

begin_struct
struct|struct
name|image_nt_header
block|{
name|uint32_t
name|inh_signature
decl_stmt|;
name|image_file_header
name|inh_filehdr
decl_stmt|;
name|image_optional_header
name|inh_optionalhdr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_nt_header
name|image_nt_header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMAGE_SIZEOF_NT_HEADER
parameter_list|(
name|nthdr
parameter_list|)
define|\
value|(offsetof(image_nt_header, inh_optionalhdr) +			\ 	  ((image_nt_header *)(nthdr))->inh_filehdr.ifh_optionalhdrlen)
end_define

begin_comment
comment|/* Directory Entries */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_EXPORT
value|0
end_define

begin_comment
comment|/* Export Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_IMPORT
value|1
end_define

begin_comment
comment|/* Import Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_RESOURCE
value|2
end_define

begin_comment
comment|/* Resource Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_EXCEPTION
value|3
end_define

begin_comment
comment|/* Exception Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_SECURITY
value|4
end_define

begin_comment
comment|/* Security Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_BASERELOC
value|5
end_define

begin_comment
comment|/* Base Relocation Table */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_DEBUG
value|6
end_define

begin_comment
comment|/* Debug Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_COPYRIGHT
value|7
end_define

begin_comment
comment|/* Description String */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_GLOBALPTR
value|8
end_define

begin_comment
comment|/* Machine Value (MIPS GP) */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_TLS
value|9
end_define

begin_comment
comment|/* TLS Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG
value|10
end_define

begin_comment
comment|/* Load Configuration Directory */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT
value|11
end_define

begin_comment
comment|/* Bound Import Directory in headers */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_IAT
value|12
end_define

begin_comment
comment|/* Import Address Table */
end_comment

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT
value|13
end_define

begin_define
define|#
directive|define
name|IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR
value|14
end_define

begin_comment
comment|/* Resource types */
end_comment

begin_define
define|#
directive|define
name|RT_CURSOR
value|1
end_define

begin_define
define|#
directive|define
name|RT_BITMAP
value|2
end_define

begin_define
define|#
directive|define
name|RT_ICON
value|3
end_define

begin_define
define|#
directive|define
name|RT_MENU
value|4
end_define

begin_define
define|#
directive|define
name|RT_DIALOG
value|5
end_define

begin_define
define|#
directive|define
name|RT_STRING
value|6
end_define

begin_define
define|#
directive|define
name|RT_FONTDIR
value|7
end_define

begin_define
define|#
directive|define
name|RT_FONT
value|8
end_define

begin_define
define|#
directive|define
name|RT_ACCELERATOR
value|9
end_define

begin_define
define|#
directive|define
name|RT_RCDATA
value|10
end_define

begin_define
define|#
directive|define
name|RT_MESSAGETABLE
value|11
end_define

begin_define
define|#
directive|define
name|RT_GROUP_CURSOR
value|12
end_define

begin_define
define|#
directive|define
name|RT_GROUP_ICON
value|14
end_define

begin_define
define|#
directive|define
name|RT_VERSION
value|16
end_define

begin_define
define|#
directive|define
name|RT_DLGINCLUDE
value|17
end_define

begin_define
define|#
directive|define
name|RT_PLUGPLAY
value|19
end_define

begin_define
define|#
directive|define
name|RT_VXD
value|20
end_define

begin_define
define|#
directive|define
name|RT_ANICURSOR
value|21
end_define

begin_define
define|#
directive|define
name|RT_ANIICON
value|22
end_define

begin_define
define|#
directive|define
name|RT_HTML
value|23
end_define

begin_comment
comment|/*  * Section header format.  */
end_comment

begin_define
define|#
directive|define
name|IMAGE_SHORT_NAME_LEN
value|8
end_define

begin_struct
struct|struct
name|image_section_header
block|{
name|uint8_t
name|ish_name
index|[
name|IMAGE_SHORT_NAME_LEN
index|]
decl_stmt|;
union|union
block|{
name|uint32_t
name|ish_paddr
decl_stmt|;
name|uint32_t
name|ish_vsize
decl_stmt|;
block|}
name|ish_misc
union|;
name|uint32_t
name|ish_vaddr
decl_stmt|;
name|uint32_t
name|ish_rawdatasize
decl_stmt|;
name|uint32_t
name|ish_rawdataaddr
decl_stmt|;
name|uint32_t
name|ish_relocaddr
decl_stmt|;
name|uint32_t
name|ish_linenumaddr
decl_stmt|;
name|uint16_t
name|ish_numrelocs
decl_stmt|;
name|uint16_t
name|ish_numlinenums
decl_stmt|;
name|uint32_t
name|ish_characteristics
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_section_header
name|image_section_header
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
name|IMAGE_FIRST_SECTION
parameter_list|(
name|nthdr
parameter_list|)
define|\
value|((image_section_header *)((vm_offset_t)(nthdr) +		\ 	  offsetof(image_nt_header, inh_optionalhdr) +			\ 	  ((image_nt_header *)(nthdr))->inh_filehdr.ifh_optionalhdrlen))
end_define

begin_comment
comment|/*  * Import format  */
end_comment

begin_struct
struct|struct
name|image_import_by_name
block|{
name|uint16_t
name|iibn_hint
decl_stmt|;
name|uint8_t
name|iibn_name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IMAGE_ORDINAL_FLAG
value|0x80000000
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

begin_struct
struct|struct
name|image_import_descriptor
block|{
name|uint32_t
name|iid_import_name_table_addr
decl_stmt|;
name|uint32_t
name|iid_timestamp
decl_stmt|;
name|uint32_t
name|iid_forwardchain
decl_stmt|;
name|uint32_t
name|iid_nameaddr
decl_stmt|;
name|uint32_t
name|iid_import_address_table_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_import_descriptor
name|image_import_descriptor
typedef|;
end_typedef

begin_struct
struct|struct
name|image_base_reloc
block|{
name|uint32_t
name|ibr_vaddr
decl_stmt|;
name|uint32_t
name|ibr_blocksize
decl_stmt|;
name|uint16_t
name|ibr_rel
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_base_reloc
name|image_base_reloc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IMR_RELTYPE
parameter_list|(
name|x
parameter_list|)
value|((x>> 12)& 0xF)
end_define

begin_define
define|#
directive|define
name|IMR_RELOFFSET
parameter_list|(
name|x
parameter_list|)
value|(x& 0xFFF)
end_define

begin_comment
comment|/* generic relocation types */
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
name|IMAGE_REL_BASED_SECTION
value|6
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_REL
value|7
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_MIPS_JMPADDR16
value|9
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_DIR64
value|10
end_define

begin_define
define|#
directive|define
name|IMAGE_REL_BASED_HIGH3ADJ
value|11
end_define

begin_struct
struct|struct
name|image_resource_directory_entry
block|{
name|uint32_t
name|irde_name
decl_stmt|;
name|uint32_t
name|irde_dataoff
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_resource_directory_entry
name|image_resource_directory_entry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RESOURCE_NAME_STR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RESOURCE_DIR_FLAG
value|0x80000000
end_define

begin_struct
struct|struct
name|image_resource_directory
block|{
name|uint32_t
name|ird_characteristics
decl_stmt|;
name|uint32_t
name|ird_timestamp
decl_stmt|;
name|uint16_t
name|ird_majorver
decl_stmt|;
name|uint16_t
name|ird_minorver
decl_stmt|;
name|uint16_t
name|ird_named_entries
decl_stmt|;
name|uint16_t
name|ird_id_entries
decl_stmt|;
ifdef|#
directive|ifdef
name|notdef
name|image_resource_directory_entry
name|ird_entries
index|[
literal|1
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_resource_directory
name|image_resource_directory
typedef|;
end_typedef

begin_struct
struct|struct
name|image_resource_directory_string
block|{
name|uint16_t
name|irds_len
decl_stmt|;
name|char
name|irds_name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_resource_directory_string
name|image_resource_directory_string
typedef|;
end_typedef

begin_struct
struct|struct
name|image_resource_directory_string_u
block|{
name|uint16_t
name|irds_len
decl_stmt|;
name|char
name|irds_name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_resource_directory_string_u
name|image_resource_directory_string_u
typedef|;
end_typedef

begin_struct
struct|struct
name|image_resource_data_entry
block|{
name|uint32_t
name|irde_offset
decl_stmt|;
name|uint32_t
name|irde_size
decl_stmt|;
name|uint32_t
name|irde_codepage
decl_stmt|;
name|uint32_t
name|irde_rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_resource_data_entry
name|image_resource_data_entry
typedef|;
end_typedef

begin_struct
struct|struct
name|message_resource_data
block|{
name|uint32_t
name|mrd_numblocks
decl_stmt|;
ifdef|#
directive|ifdef
name|notdef
name|message_resource_block
name|mrd_blocks
index|[
literal|1
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|message_resource_data
name|message_resource_data
typedef|;
end_typedef

begin_struct
struct|struct
name|message_resource_block
block|{
name|uint32_t
name|mrb_lowid
decl_stmt|;
name|uint32_t
name|mrb_highid
decl_stmt|;
name|uint32_t
name|mrb_entryoff
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|message_resource_block
name|message_resource_block
typedef|;
end_typedef

begin_struct
struct|struct
name|message_resource_entry
block|{
name|uint16_t
name|mre_len
decl_stmt|;
name|uint16_t
name|mre_flags
decl_stmt|;
name|char
name|mre_text
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|message_resource_entry
name|message_resource_entry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MESSAGE_RESOURCE_UNICODE
value|0x0001
end_define

begin_struct
struct|struct
name|image_patch_table
block|{
name|char
modifier|*
name|ipt_name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|ipt_func
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ipt_wrap
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|ipt_argcnt
decl_stmt|;
name|int
name|ipt_ftype
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|image_patch_table
name|image_patch_table
typedef|;
end_typedef

begin_comment
comment|/*  * AMD64 support. Microsoft uses a different calling convention  * than everyone else on the amd64 platform. Sadly, gcc has no  * built-in support for it (yet).  *  * The three major differences we're concerned with are:  *  * - The first 4 register-sized arguments are passed in the  *   %rcx, %rdx, %r8 and %r9 registers, and the rest are pushed  *   onto the stack. (The ELF ABI uses 6 registers, not 4).  *  * - The caller must reserve space on the stack for the 4  *   register arguments in case the callee has to spill them.  *  * - The stack myst be 16-byte aligned by the time the callee  *   executes. A call instruction implicitly pushes an 8 byte  *   return address onto the stack. We have to make sure that  *   the amount of space we consume, plus the return address,  *   is a multiple of 16 bytes in size. This means that in  *   some cases, we may need to chew up an extra 8 bytes on  *   the stack that will be unused.  *  * On the bright side, Microsoft seems to be using just the one  * calling convention for all functions on amd64, unlike x86 where  * they use a mix of _stdcall, _fastcall and _cdecl.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_function_decl
specifier|extern
name|uint64_t
name|x86_64_call1
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|x86_64_call2
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|x86_64_call3
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|x86_64_call4
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|x86_64_call5
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|x86_64_call6
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MSCALL1
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|)
define|\
value|x86_64_call1((fn), (uint64_t)(a))
end_define

begin_define
define|#
directive|define
name|MSCALL2
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|x86_64_call2((fn), (uint64_t)(a), (uint64_t)(b))
end_define

begin_define
define|#
directive|define
name|MSCALL3
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|x86_64_call3((fn), (uint64_t)(a), (uint64_t)(b),		\ 	(uint64_t)(c))
end_define

begin_define
define|#
directive|define
name|MSCALL4
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|x86_64_call4((fn), (uint64_t)(a), (uint64_t)(b),		\ 	(uint64_t)(c), (uint64_t)(d))
end_define

begin_define
define|#
directive|define
name|MSCALL5
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
define|\
value|x86_64_call5((fn), (uint64_t)(a), (uint64_t)(b),		\ 	(uint64_t)(c), (uint64_t)(d), (uint64_t)(e))
end_define

begin_define
define|#
directive|define
name|MSCALL6
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
define|\
value|x86_64_call6((fn), (uint64_t)(a), (uint64_t)(b),		\ 	(uint64_t)(c), (uint64_t)(d), (uint64_t)(e), (uint64_t)(f))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __amd64__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_function_decl
specifier|extern
name|uint32_t
name|x86_stdcall_call
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MSCALL1
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|)
value|x86_stdcall_call(fn, 1, (a))
end_define

begin_define
define|#
directive|define
name|MSCALL2
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|x86_stdcall_call(fn, 2, (a), (b))
end_define

begin_define
define|#
directive|define
name|MSCALL3
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|x86_stdcall_call(fn, 3, (a), (b), (c))
end_define

begin_define
define|#
directive|define
name|MSCALL4
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|x86_stdcall_call(fn, 4, (a), (b), (c), (d))
end_define

begin_define
define|#
directive|define
name|MSCALL5
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
define|\
value|x86_stdcall_call(fn, 5, (a), (b), (c), (d), (e))
end_define

begin_define
define|#
directive|define
name|MSCALL6
parameter_list|(
name|fn
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
define|\
value|x86_stdcall_call(fn, 6, (a), (b), (c), (d), (e), (f))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

begin_define
define|#
directive|define
name|FUNC
value|void(*)(void)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|IMPORT_SFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_STDCALL }
end_define

begin_define
define|#
directive|define
name|IMPORT_SFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_STDCALL }
end_define

begin_define
define|#
directive|define
name|IMPORT_FFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_FASTCALL }
end_define

begin_define
define|#
directive|define
name|IMPORT_FFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_FASTCALL }
end_define

begin_define
define|#
directive|define
name|IMPORT_RFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_REGPARM }
end_define

begin_define
define|#
directive|define
name|IMPORT_RFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_REGPARM }
end_define

begin_define
define|#
directive|define
name|IMPORT_CFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_CDECL }
end_define

begin_define
define|#
directive|define
name|IMPORT_CFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_CDECL }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|IMPORT_SFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_AMD64 }
end_define

begin_define
define|#
directive|define
name|IMPORT_SFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_AMD64 }
end_define

begin_define
define|#
directive|define
name|IMPORT_FFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_AMD64 }
end_define

begin_define
define|#
directive|define
name|IMPORT_FFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_AMD64 }
end_define

begin_define
define|#
directive|define
name|IMPORT_RFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_AMD64 }
end_define

begin_define
define|#
directive|define
name|IMPORT_RFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_AMD64 }
end_define

begin_define
define|#
directive|define
name|IMPORT_CFUNC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ #x, (FUNC)x, NULL, y, WINDRV_WRAP_AMD64 }
end_define

begin_define
define|#
directive|define
name|IMPORT_CFUNC_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{ #x, (FUNC)y, NULL, z, WINDRV_WRAP_AMD64 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __amd64__ */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|pe_get_dos_header
parameter_list|(
name|vm_offset_t
parameter_list|,
name|image_dos_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_is_nt_image
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_get_optional_header
parameter_list|(
name|vm_offset_t
parameter_list|,
name|image_optional_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_get_file_header
parameter_list|(
name|vm_offset_t
parameter_list|,
name|image_file_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_get_section_header
parameter_list|(
name|vm_offset_t
parameter_list|,
name|image_section_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_numsections
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_offset_t
name|pe_imagebase
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_offset_t
name|pe_directory_offset
parameter_list|(
name|vm_offset_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vm_offset_t
name|pe_translate_addr
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_get_section
parameter_list|(
name|vm_offset_t
parameter_list|,
name|image_section_header
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_relocate
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_get_import_descriptor
parameter_list|(
name|vm_offset_t
parameter_list|,
name|image_import_descriptor
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_patch_imports
parameter_list|(
name|vm_offset_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|image_patch_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_get_messagetable
parameter_list|(
name|vm_offset_t
parameter_list|,
name|message_resource_data
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pe_get_message
parameter_list|(
name|vm_offset_t
parameter_list|,
name|uint32_t
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PE_VAR_H_ */
end_comment

end_unit

