begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|IMAGE_FILE_MACHINE_IA64
value|0x0200
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
name|uint32_t
name|ioh_databaseaddr
decl_stmt|;
comment|/* NT-specific fields */
name|uint32_t
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
name|uint32_t
name|ioh_stackreservesize
decl_stmt|;
name|uint32_t
name|ioh_stackcommitsize
decl_stmt|;
name|uint32_t
name|ioh_heapreservesize
decl_stmt|;
name|uint32_t
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
name|u_int8_t
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
name|IMAGE_REL_BASED_IA64_IMM64
value|9
end_define

begin_comment
comment|/* yes, 9 too */
end_comment

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
name|uint32_t
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

