begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF support for BFD.    Copyright (C) 1991, 92, 93, 94, 95, 1997 Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support, from information published    in "UNIX System V Release 4, Programmers Guide: ANSI C and    Programming Support Tools".  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is part of ELF support for BFD, and contains the portions    that describe how ELF is represented internally in the BFD library.    I.E. it describes the in-memory representation of ELF.  It requires    the elf-common.h file which contains the portions that are common to    both the internal and external representations. */
end_comment

begin_comment
comment|/* NOTE that these structures are not kept in the same order as they appear    in the object file.  In some cases they've been reordered for more optimal    packing under various circumstances.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_INTERNAL_H
end_define

begin_comment
comment|/* ELF Header */
end_comment

begin_define
define|#
directive|define
name|EI_NIDENT
value|16
end_define

begin_comment
comment|/* Size of e_ident[] */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_ehdr
block|{
name|unsigned
name|char
name|e_ident
index|[
name|EI_NIDENT
index|]
decl_stmt|;
comment|/* ELF "magic number" */
name|bfd_vma
name|e_entry
decl_stmt|;
comment|/* Entry point virtual address */
name|bfd_signed_vma
name|e_phoff
decl_stmt|;
comment|/* Program header table file offset */
name|bfd_signed_vma
name|e_shoff
decl_stmt|;
comment|/* Section header table file offset */
name|unsigned
name|long
name|e_version
decl_stmt|;
comment|/* Identifies object file version */
name|unsigned
name|long
name|e_flags
decl_stmt|;
comment|/* Processor-specific flags */
name|unsigned
name|short
name|e_type
decl_stmt|;
comment|/* Identifies object file type */
name|unsigned
name|short
name|e_machine
decl_stmt|;
comment|/* Specifies required architecture */
name|unsigned
name|short
name|e_ehsize
decl_stmt|;
comment|/* ELF header size in bytes */
name|unsigned
name|short
name|e_phentsize
decl_stmt|;
comment|/* Program header table entry size */
name|unsigned
name|short
name|e_phnum
decl_stmt|;
comment|/* Program header table entry count */
name|unsigned
name|short
name|e_shentsize
decl_stmt|;
comment|/* Section header table entry size */
name|unsigned
name|short
name|e_shnum
decl_stmt|;
comment|/* Section header table entry count */
name|unsigned
name|short
name|e_shstrndx
decl_stmt|;
comment|/* Section header string table index */
block|}
name|Elf_Internal_Ehdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_ehdr
value|elf_internal_ehdr
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Ehdr
value|Elf_Internal_Ehdr
end_define

begin_define
define|#
directive|define
name|elf64_internal_ehdr
value|elf_internal_ehdr
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Ehdr
value|Elf_Internal_Ehdr
end_define

begin_comment
comment|/* Program header */
end_comment

begin_struct
struct|struct
name|elf_internal_phdr
block|{
name|unsigned
name|long
name|p_type
decl_stmt|;
comment|/* Identifies program segment type */
name|unsigned
name|long
name|p_flags
decl_stmt|;
comment|/* Segment flags */
name|bfd_vma
name|p_offset
decl_stmt|;
comment|/* Segment file offset */
name|bfd_vma
name|p_vaddr
decl_stmt|;
comment|/* Segment virtual address */
name|bfd_vma
name|p_paddr
decl_stmt|;
comment|/* Segment physical address */
name|bfd_vma
name|p_filesz
decl_stmt|;
comment|/* Segment size in file */
name|bfd_vma
name|p_memsz
decl_stmt|;
comment|/* Segment size in memory */
name|bfd_vma
name|p_align
decl_stmt|;
comment|/* Segment alignment, file& memory */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|elf_internal_phdr
name|Elf_Internal_Phdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_phdr
value|elf_internal_phdr
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Phdr
value|Elf_Internal_Phdr
end_define

begin_define
define|#
directive|define
name|elf64_internal_phdr
value|elf_internal_phdr
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Phdr
value|Elf_Internal_Phdr
end_define

begin_comment
comment|/* Section header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_shdr
block|{
name|unsigned
name|int
name|sh_name
decl_stmt|;
comment|/* Section name, index in string tbl */
name|unsigned
name|int
name|sh_type
decl_stmt|;
comment|/* Type of section */
name|bfd_vma
name|sh_flags
decl_stmt|;
comment|/* Miscellaneous section attributes */
name|bfd_vma
name|sh_addr
decl_stmt|;
comment|/* Section virtual addr at execution */
name|bfd_size_type
name|sh_size
decl_stmt|;
comment|/* Size of section in bytes */
name|bfd_size_type
name|sh_entsize
decl_stmt|;
comment|/* Entry size if section holds table */
name|unsigned
name|long
name|sh_link
decl_stmt|;
comment|/* Index of another section */
name|unsigned
name|long
name|sh_info
decl_stmt|;
comment|/* Additional section information */
name|file_ptr
name|sh_offset
decl_stmt|;
comment|/* Section file offset */
name|unsigned
name|int
name|sh_addralign
decl_stmt|;
comment|/* Section alignment */
comment|/* The internal rep also has some cached info associated with it. */
name|asection
modifier|*
name|bfd_section
decl_stmt|;
comment|/* Associated BFD section.  */
name|PTR
name|contents
decl_stmt|;
comment|/* Section contents.  */
block|}
name|Elf_Internal_Shdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_shdr
value|elf_internal_shdr
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Shdr
value|Elf_Internal_Shdr
end_define

begin_define
define|#
directive|define
name|elf64_internal_shdr
value|elf_internal_shdr
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Shdr
value|Elf_Internal_Shdr
end_define

begin_comment
comment|/* Symbol table entry */
end_comment

begin_struct
struct|struct
name|elf_internal_sym
block|{
name|bfd_vma
name|st_value
decl_stmt|;
comment|/* Value of the symbol */
name|bfd_vma
name|st_size
decl_stmt|;
comment|/* Associated symbol size */
name|unsigned
name|long
name|st_name
decl_stmt|;
comment|/* Symbol name, index in string tbl */
name|unsigned
name|char
name|st_info
decl_stmt|;
comment|/* Type and binding attributes */
name|unsigned
name|char
name|st_other
decl_stmt|;
comment|/* No defined meaning, 0 */
name|unsigned
name|short
name|st_shndx
decl_stmt|;
comment|/* Associated section index */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|elf_internal_sym
name|Elf_Internal_Sym
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_sym
value|elf_internal_sym
end_define

begin_define
define|#
directive|define
name|elf64_internal_sym
value|elf_internal_sym
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Sym
value|Elf_Internal_Sym
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Sym
value|Elf_Internal_Sym
end_define

begin_comment
comment|/* Note segments */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_note
block|{
name|unsigned
name|long
name|namesz
decl_stmt|;
comment|/* Size of entry's owner string */
name|unsigned
name|long
name|descsz
decl_stmt|;
comment|/* Size of the note descriptor */
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* Interpretation of the descriptor */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* Start of the name+desc data */
block|}
name|Elf_Internal_Note
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Elf32_Internal_Note
value|Elf_Internal_Note
end_define

begin_define
define|#
directive|define
name|elf32_internal_note
value|elf_internal_note
end_define

begin_comment
comment|/* Relocation Entries */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_rel
block|{
name|bfd_vma
name|r_offset
decl_stmt|;
comment|/* Location at which to apply the action */
comment|/* This needs to support 64-bit values in elf64.  */
name|bfd_vma
name|r_info
decl_stmt|;
comment|/* index and type of relocation */
block|}
name|Elf_Internal_Rel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_rel
value|elf_internal_rel
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Rel
value|Elf_Internal_Rel
end_define

begin_define
define|#
directive|define
name|elf64_internal_rel
value|elf_internal_rel
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Rel
value|Elf_Internal_Rel
end_define

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_rela
block|{
name|bfd_vma
name|r_offset
decl_stmt|;
comment|/* Location at which to apply the action */
name|bfd_vma
name|r_info
decl_stmt|;
comment|/* Index and Type of relocation */
name|bfd_signed_vma
name|r_addend
decl_stmt|;
comment|/* Constant addend used to compute value */
block|}
name|Elf_Internal_Rela
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_rela
value|elf_internal_rela
end_define

begin_define
define|#
directive|define
name|elf64_internal_rela
value|elf_internal_rela
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Rela
value|Elf_Internal_Rela
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Rela
value|Elf_Internal_Rela
end_define

begin_comment
comment|/* dynamic section structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_dyn
block|{
comment|/* This needs to support 64-bit values in elf64.  */
name|bfd_vma
name|d_tag
decl_stmt|;
comment|/* entry tag value */
union|union
block|{
comment|/* This needs to support 64-bit values in elf64.  */
name|bfd_vma
name|d_val
decl_stmt|;
name|bfd_vma
name|d_ptr
decl_stmt|;
block|}
name|d_un
union|;
block|}
name|Elf_Internal_Dyn
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_dyn
value|elf_internal_dyn
end_define

begin_define
define|#
directive|define
name|elf64_internal_dyn
value|elf_internal_dyn
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Dyn
value|Elf_Internal_Dyn
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Dyn
value|Elf_Internal_Dyn
end_define

begin_comment
comment|/* This structure appears in a SHT_GNU_verdef section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_verdef
block|{
name|unsigned
name|short
name|vd_version
decl_stmt|;
comment|/* Version number of structure.  */
name|unsigned
name|short
name|vd_flags
decl_stmt|;
comment|/* Flags (VER_FLG_*).  */
name|unsigned
name|short
name|vd_ndx
decl_stmt|;
comment|/* Version index.  */
name|unsigned
name|short
name|vd_cnt
decl_stmt|;
comment|/* Number of verdaux entries.  */
name|unsigned
name|long
name|vd_hash
decl_stmt|;
comment|/* Hash of name.  */
name|unsigned
name|long
name|vd_aux
decl_stmt|;
comment|/* Offset to verdaux entries.  */
name|unsigned
name|long
name|vd_next
decl_stmt|;
comment|/* Offset to next verdef.  */
comment|/* These fields are set up when BFD reads in the structure.  FIXME:      It would be cleaner to store these in a different structure.  */
name|bfd
modifier|*
name|vd_bfd
decl_stmt|;
comment|/* BFD.  */
specifier|const
name|char
modifier|*
name|vd_nodename
decl_stmt|;
comment|/* Version name.  */
name|struct
name|elf_internal_verdef
modifier|*
name|vd_nextdef
decl_stmt|;
comment|/* vd_next as pointer.  */
name|struct
name|elf_internal_verdaux
modifier|*
name|vd_auxptr
decl_stmt|;
comment|/* vd_aux as pointer.  */
name|unsigned
name|int
name|vd_exp_refno
decl_stmt|;
comment|/* Used by the linker.  */
block|}
name|Elf_Internal_Verdef
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_verdef section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_verdaux
block|{
name|unsigned
name|long
name|vda_name
decl_stmt|;
comment|/* String table offset of name.  */
name|unsigned
name|long
name|vda_next
decl_stmt|;
comment|/* Offset to next verdaux.  */
comment|/* These fields are set up when BFD reads in the structure.  FIXME:      It would be cleaner to store these in a different structure.  */
specifier|const
name|char
modifier|*
name|vda_nodename
decl_stmt|;
comment|/* vda_name as pointer.  */
name|struct
name|elf_internal_verdaux
modifier|*
name|vda_nextptr
decl_stmt|;
comment|/* vda_next as pointer.  */
block|}
name|Elf_Internal_Verdaux
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_verneed section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_verneed
block|{
name|unsigned
name|short
name|vn_version
decl_stmt|;
comment|/* Version number of structure.  */
name|unsigned
name|short
name|vn_cnt
decl_stmt|;
comment|/* Number of vernaux entries.  */
name|unsigned
name|long
name|vn_file
decl_stmt|;
comment|/* String table offset of library name.  */
name|unsigned
name|long
name|vn_aux
decl_stmt|;
comment|/* Offset to vernaux entries.  */
name|unsigned
name|long
name|vn_next
decl_stmt|;
comment|/* Offset to next verneed.  */
comment|/* These fields are set up when BFD reads in the structure.  FIXME:      It would be cleaner to store these in a different structure.  */
name|bfd
modifier|*
name|vn_bfd
decl_stmt|;
comment|/* BFD.  */
specifier|const
name|char
modifier|*
name|vn_filename
decl_stmt|;
comment|/* vn_file as pointer.  */
name|struct
name|elf_internal_vernaux
modifier|*
name|vn_auxptr
decl_stmt|;
comment|/* vn_aux as pointer.  */
name|struct
name|elf_internal_verneed
modifier|*
name|vn_nextref
decl_stmt|;
comment|/* vn_nextref as pointer.  */
block|}
name|Elf_Internal_Verneed
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_verneed section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_vernaux
block|{
name|unsigned
name|long
name|vna_hash
decl_stmt|;
comment|/* Hash of dependency name.  */
name|unsigned
name|short
name|vna_flags
decl_stmt|;
comment|/* Flags (VER_FLG_*).  */
name|unsigned
name|short
name|vna_other
decl_stmt|;
comment|/* Unused.  */
name|unsigned
name|long
name|vna_name
decl_stmt|;
comment|/* String table offset to version name.  */
name|unsigned
name|long
name|vna_next
decl_stmt|;
comment|/* Offset to next vernaux.  */
comment|/* These fields are set up when BFD reads in the structure.  FIXME:      It would be cleaner to store these in a different structure.  */
specifier|const
name|char
modifier|*
name|vna_nodename
decl_stmt|;
comment|/* vna_name as pointer.  */
name|struct
name|elf_internal_vernaux
modifier|*
name|vna_nextptr
decl_stmt|;
comment|/* vna_next as pointer.  */
block|}
name|Elf_Internal_Vernaux
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_versym section.  This is not a    standard ELF structure; ELF just uses Elf32_Half.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_versym
block|{
name|unsigned
name|short
name|vs_vers
decl_stmt|;
block|}
name|Elf_Internal_Versym
typedef|;
end_typedef

begin_define
define|#
directive|define
name|elf32_internal_verdef
value|elf_internal_verdef
end_define

begin_define
define|#
directive|define
name|elf64_internal_verdef
value|elf_internal_verdef
end_define

begin_define
define|#
directive|define
name|elf32_internal_verdaux
value|elf_internal_verdaux
end_define

begin_define
define|#
directive|define
name|elf64_internal_verdaux
value|elf_internal_verdaux
end_define

begin_define
define|#
directive|define
name|elf32_internal_verneed
value|elf_internal_verneed
end_define

begin_define
define|#
directive|define
name|elf64_internal_verneed
value|elf_internal_verneed
end_define

begin_define
define|#
directive|define
name|elf32_internal_vernaux
value|elf_internal_vernaux
end_define

begin_define
define|#
directive|define
name|elf64_internal_vernaux
value|elf_internal_vernaux
end_define

begin_define
define|#
directive|define
name|elf32_internal_versym
value|elf_internal_versym
end_define

begin_define
define|#
directive|define
name|elf64_internal_versym
value|elf_internal_versym
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Verdef
value|Elf_Internal_Verdef
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Verdef
value|Elf_Internal_Verdef
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Verdaux
value|Elf_Internal_Verdaux
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Verdaux
value|Elf_Internal_Verdaux
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Verneed
value|Elf_Internal_Verneed
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Verneed
value|Elf_Internal_Verneed
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Vernaux
value|Elf_Internal_Vernaux
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Vernaux
value|Elf_Internal_Vernaux
end_define

begin_define
define|#
directive|define
name|Elf32_Internal_Versym
value|Elf_Internal_Versym
end_define

begin_define
define|#
directive|define
name|Elf64_Internal_Versym
value|Elf_Internal_Versym
end_define

begin_comment
comment|/* This structure is used to describe how sections should be assigned    to program segments.  */
end_comment

begin_struct
struct|struct
name|elf_segment_map
block|{
comment|/* Next program segment.  */
name|struct
name|elf_segment_map
modifier|*
name|next
decl_stmt|;
comment|/* Program segment type.  */
name|unsigned
name|long
name|p_type
decl_stmt|;
comment|/* Program segment flags.  */
name|unsigned
name|long
name|p_flags
decl_stmt|;
comment|/* Program segment physical address.  */
name|bfd_vma
name|p_paddr
decl_stmt|;
comment|/* Whether the p_flags field is valid; if not, the flags are based      on the section flags.  */
name|unsigned
name|int
name|p_flags_valid
range|:
literal|1
decl_stmt|;
comment|/* Whether the p_paddr field is valid; if not, the physical address      is based on the section lma values.  */
name|unsigned
name|int
name|p_paddr_valid
range|:
literal|1
decl_stmt|;
comment|/* Whether this segment includes the file header.  */
name|unsigned
name|int
name|includes_filehdr
range|:
literal|1
decl_stmt|;
comment|/* Whether this segment includes the program headers.  */
name|unsigned
name|int
name|includes_phdrs
range|:
literal|1
decl_stmt|;
comment|/* Number of sections (may be 0).  */
name|unsigned
name|int
name|count
decl_stmt|;
comment|/* Sections.  Actual number of elements is in count field.  */
name|asection
modifier|*
name|sections
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_INTERNAL_H */
end_comment

end_unit

