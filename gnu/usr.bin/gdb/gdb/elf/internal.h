begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF support for BFD.    Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support, from information published    in "UNIX System V Release 4, Programmers Guide: ANSI C and    Programming Support Tools".  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This file is part of ELF support for BFD, and contains the portions    that describe how ELF is represented internally in the BFD library.    I.E. it describes the in-memory representation of ELF.  It requires    the elf-common.h file which contains the portions that are common to    both the internal and external representations. */
end_comment

begin_comment
comment|/* NOTE that these structures are not kept in the same order as they appear    in the object file.  In some cases they've been reordered for more optimal    packing under various circumstances.  */
end_comment

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
name|PTR
name|rawdata
decl_stmt|;
comment|/* null if unused... */
name|PTR
name|contents
decl_stmt|;
comment|/* null if unused... */
name|bfd_vma
name|size
decl_stmt|;
comment|/* size of contents (0 if unused) */
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

end_unit

