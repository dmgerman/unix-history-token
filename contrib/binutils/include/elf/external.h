begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF support for BFD.    Copyright (C) 1991, 92, 93, 95, 1997 Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support, from information published    in "UNIX System V Release 4, Programmers Guide: ANSI C and    Programming Support Tools".  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is part of ELF support for BFD, and contains the portions    that describe how ELF is represented externally by the BFD library.    I.E. it describes the in-file representation of ELF.  It requires    the elf-common.h file which contains the portions that are common to    both the internal and external representations. */
end_comment

begin_comment
comment|/* The 64-bit stuff is kind of random.  Perhaps someone will publish a    spec someday.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_EXTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_EXTERNAL_H
end_define

begin_comment
comment|/* ELF Header (32-bit implementations) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|e_ident
index|[
literal|16
index|]
decl_stmt|;
comment|/* ELF "magic number" */
name|unsigned
name|char
name|e_type
index|[
literal|2
index|]
decl_stmt|;
comment|/* Identifies object file type */
name|unsigned
name|char
name|e_machine
index|[
literal|2
index|]
decl_stmt|;
comment|/* Specifies required architecture */
name|unsigned
name|char
name|e_version
index|[
literal|4
index|]
decl_stmt|;
comment|/* Identifies object file version */
name|unsigned
name|char
name|e_entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* Entry point virtual address */
name|unsigned
name|char
name|e_phoff
index|[
literal|4
index|]
decl_stmt|;
comment|/* Program header table file offset */
name|unsigned
name|char
name|e_shoff
index|[
literal|4
index|]
decl_stmt|;
comment|/* Section header table file offset */
name|unsigned
name|char
name|e_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* Processor-specific flags */
name|unsigned
name|char
name|e_ehsize
index|[
literal|2
index|]
decl_stmt|;
comment|/* ELF header size in bytes */
name|unsigned
name|char
name|e_phentsize
index|[
literal|2
index|]
decl_stmt|;
comment|/* Program header table entry size */
name|unsigned
name|char
name|e_phnum
index|[
literal|2
index|]
decl_stmt|;
comment|/* Program header table entry count */
name|unsigned
name|char
name|e_shentsize
index|[
literal|2
index|]
decl_stmt|;
comment|/* Section header table entry size */
name|unsigned
name|char
name|e_shnum
index|[
literal|2
index|]
decl_stmt|;
comment|/* Section header table entry count */
name|unsigned
name|char
name|e_shstrndx
index|[
literal|2
index|]
decl_stmt|;
comment|/* Section header string table index */
block|}
name|Elf32_External_Ehdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|e_ident
index|[
literal|16
index|]
decl_stmt|;
comment|/* ELF "magic number" */
name|unsigned
name|char
name|e_type
index|[
literal|2
index|]
decl_stmt|;
comment|/* Identifies object file type */
name|unsigned
name|char
name|e_machine
index|[
literal|2
index|]
decl_stmt|;
comment|/* Specifies required architecture */
name|unsigned
name|char
name|e_version
index|[
literal|4
index|]
decl_stmt|;
comment|/* Identifies object file version */
name|unsigned
name|char
name|e_entry
index|[
literal|8
index|]
decl_stmt|;
comment|/* Entry point virtual address */
name|unsigned
name|char
name|e_phoff
index|[
literal|8
index|]
decl_stmt|;
comment|/* Program header table file offset */
name|unsigned
name|char
name|e_shoff
index|[
literal|8
index|]
decl_stmt|;
comment|/* Section header table file offset */
name|unsigned
name|char
name|e_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* Processor-specific flags */
name|unsigned
name|char
name|e_ehsize
index|[
literal|2
index|]
decl_stmt|;
comment|/* ELF header size in bytes */
name|unsigned
name|char
name|e_phentsize
index|[
literal|2
index|]
decl_stmt|;
comment|/* Program header table entry size */
name|unsigned
name|char
name|e_phnum
index|[
literal|2
index|]
decl_stmt|;
comment|/* Program header table entry count */
name|unsigned
name|char
name|e_shentsize
index|[
literal|2
index|]
decl_stmt|;
comment|/* Section header table entry size */
name|unsigned
name|char
name|e_shnum
index|[
literal|2
index|]
decl_stmt|;
comment|/* Section header table entry count */
name|unsigned
name|char
name|e_shstrndx
index|[
literal|2
index|]
decl_stmt|;
comment|/* Section header string table index */
block|}
name|Elf64_External_Ehdr
typedef|;
end_typedef

begin_comment
comment|/* Program header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|p_type
index|[
literal|4
index|]
decl_stmt|;
comment|/* Identifies program segment type */
name|unsigned
name|char
name|p_offset
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment file offset */
name|unsigned
name|char
name|p_vaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment virtual address */
name|unsigned
name|char
name|p_paddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment physical address */
name|unsigned
name|char
name|p_filesz
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment size in file */
name|unsigned
name|char
name|p_memsz
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment size in memory */
name|unsigned
name|char
name|p_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment flags */
name|unsigned
name|char
name|p_align
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment alignment, file& memory */
block|}
name|Elf32_External_Phdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|p_type
index|[
literal|4
index|]
decl_stmt|;
comment|/* Identifies program segment type */
name|unsigned
name|char
name|p_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* Segment flags */
name|unsigned
name|char
name|p_offset
index|[
literal|8
index|]
decl_stmt|;
comment|/* Segment file offset */
name|unsigned
name|char
name|p_vaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Segment virtual address */
name|unsigned
name|char
name|p_paddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Segment physical address */
name|unsigned
name|char
name|p_filesz
index|[
literal|8
index|]
decl_stmt|;
comment|/* Segment size in file */
name|unsigned
name|char
name|p_memsz
index|[
literal|8
index|]
decl_stmt|;
comment|/* Segment size in memory */
name|unsigned
name|char
name|p_align
index|[
literal|8
index|]
decl_stmt|;
comment|/* Segment alignment, file& memory */
block|}
name|Elf64_External_Phdr
typedef|;
end_typedef

begin_comment
comment|/* Section header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|sh_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* Section name, index in string tbl */
name|unsigned
name|char
name|sh_type
index|[
literal|4
index|]
decl_stmt|;
comment|/* Type of section */
name|unsigned
name|char
name|sh_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* Miscellaneous section attributes */
name|unsigned
name|char
name|sh_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* Section virtual addr at execution */
name|unsigned
name|char
name|sh_offset
index|[
literal|4
index|]
decl_stmt|;
comment|/* Section file offset */
name|unsigned
name|char
name|sh_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* Size of section in bytes */
name|unsigned
name|char
name|sh_link
index|[
literal|4
index|]
decl_stmt|;
comment|/* Index of another section */
name|unsigned
name|char
name|sh_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* Additional section information */
name|unsigned
name|char
name|sh_addralign
index|[
literal|4
index|]
decl_stmt|;
comment|/* Section alignment */
name|unsigned
name|char
name|sh_entsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* Entry size if section holds table */
block|}
name|Elf32_External_Shdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|sh_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* Section name, index in string tbl */
name|unsigned
name|char
name|sh_type
index|[
literal|4
index|]
decl_stmt|;
comment|/* Type of section */
name|unsigned
name|char
name|sh_flags
index|[
literal|8
index|]
decl_stmt|;
comment|/* Miscellaneous section attributes */
name|unsigned
name|char
name|sh_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Section virtual addr at execution */
name|unsigned
name|char
name|sh_offset
index|[
literal|8
index|]
decl_stmt|;
comment|/* Section file offset */
name|unsigned
name|char
name|sh_size
index|[
literal|8
index|]
decl_stmt|;
comment|/* Size of section in bytes */
name|unsigned
name|char
name|sh_link
index|[
literal|4
index|]
decl_stmt|;
comment|/* Index of another section */
name|unsigned
name|char
name|sh_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* Additional section information */
name|unsigned
name|char
name|sh_addralign
index|[
literal|8
index|]
decl_stmt|;
comment|/* Section alignment */
name|unsigned
name|char
name|sh_entsize
index|[
literal|8
index|]
decl_stmt|;
comment|/* Entry size if section holds table */
block|}
name|Elf64_External_Shdr
typedef|;
end_typedef

begin_comment
comment|/* Symbol table entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|st_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* Symbol name, index in string tbl */
name|unsigned
name|char
name|st_value
index|[
literal|4
index|]
decl_stmt|;
comment|/* Value of the symbol */
name|unsigned
name|char
name|st_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* Associated symbol size */
name|unsigned
name|char
name|st_info
index|[
literal|1
index|]
decl_stmt|;
comment|/* Type and binding attributes */
name|unsigned
name|char
name|st_other
index|[
literal|1
index|]
decl_stmt|;
comment|/* No defined meaning, 0 */
name|unsigned
name|char
name|st_shndx
index|[
literal|2
index|]
decl_stmt|;
comment|/* Associated section index */
block|}
name|Elf32_External_Sym
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|st_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* Symbol name, index in string tbl */
name|unsigned
name|char
name|st_info
index|[
literal|1
index|]
decl_stmt|;
comment|/* Type and binding attributes */
name|unsigned
name|char
name|st_other
index|[
literal|1
index|]
decl_stmt|;
comment|/* No defined meaning, 0 */
name|unsigned
name|char
name|st_shndx
index|[
literal|2
index|]
decl_stmt|;
comment|/* Associated section index */
name|unsigned
name|char
name|st_value
index|[
literal|8
index|]
decl_stmt|;
comment|/* Value of the symbol */
name|unsigned
name|char
name|st_size
index|[
literal|8
index|]
decl_stmt|;
comment|/* Associated symbol size */
block|}
name|Elf64_External_Sym
typedef|;
end_typedef

begin_comment
comment|/* Note segments */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|namesz
index|[
literal|4
index|]
decl_stmt|;
comment|/* Size of entry's owner string */
name|unsigned
name|char
name|descsz
index|[
literal|4
index|]
decl_stmt|;
comment|/* Size of the note descriptor */
name|unsigned
name|char
name|type
index|[
literal|4
index|]
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
name|Elf_External_Note
typedef|;
end_typedef

begin_comment
comment|/* Relocation Entries */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|r_offset
index|[
literal|4
index|]
decl_stmt|;
comment|/* Location at which to apply the action */
name|unsigned
name|char
name|r_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* index and type of relocation */
block|}
name|Elf32_External_Rel
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|r_offset
index|[
literal|4
index|]
decl_stmt|;
comment|/* Location at which to apply the action */
name|unsigned
name|char
name|r_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* index and type of relocation */
name|unsigned
name|char
name|r_addend
index|[
literal|4
index|]
decl_stmt|;
comment|/* Constant addend used to compute value */
block|}
name|Elf32_External_Rela
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|r_offset
index|[
literal|8
index|]
decl_stmt|;
comment|/* Location at which to apply the action */
name|unsigned
name|char
name|r_info
index|[
literal|8
index|]
decl_stmt|;
comment|/* index and type of relocation */
block|}
name|Elf64_External_Rel
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|r_offset
index|[
literal|8
index|]
decl_stmt|;
comment|/* Location at which to apply the action */
name|unsigned
name|char
name|r_info
index|[
literal|8
index|]
decl_stmt|;
comment|/* index and type of relocation */
name|unsigned
name|char
name|r_addend
index|[
literal|8
index|]
decl_stmt|;
comment|/* Constant addend used to compute value */
block|}
name|Elf64_External_Rela
typedef|;
end_typedef

begin_comment
comment|/* dynamic section structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|d_tag
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry tag value */
union|union
block|{
name|unsigned
name|char
name|d_val
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|d_ptr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|d_un
union|;
block|}
name|Elf32_External_Dyn
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|d_tag
index|[
literal|8
index|]
decl_stmt|;
comment|/* entry tag value */
union|union
block|{
name|unsigned
name|char
name|d_val
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|d_ptr
index|[
literal|8
index|]
decl_stmt|;
block|}
name|d_un
union|;
block|}
name|Elf64_External_Dyn
typedef|;
end_typedef

begin_comment
comment|/* The version structures are currently size independent.  They are    named without a 32 or 64.  If that ever changes, these structures    will need to be renamed.  */
end_comment

begin_comment
comment|/* This structure appears in a SHT_GNU_verdef section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|vd_version
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vd_flags
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vd_ndx
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vd_cnt
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vd_hash
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|vd_aux
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|vd_next
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf_External_Verdef
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_verdef section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|vda_name
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|vda_next
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf_External_Verdaux
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_verneed section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|vn_version
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vn_cnt
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vn_file
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|vn_aux
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|vn_next
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf_External_Verneed
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_verneed section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|vna_hash
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|vna_flags
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vna_other
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|vna_name
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|vna_next
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf_External_Vernaux
typedef|;
end_typedef

begin_comment
comment|/* This structure appears in a SHT_GNU_versym section.  This is not a    standard ELF structure; ELF just uses Elf32_Half.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|vs_vers
index|[
literal|2
index|]
decl_stmt|;
block|}
name|Elf_External_Versym
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_EXTERNAL_H */
end_comment

end_unit

