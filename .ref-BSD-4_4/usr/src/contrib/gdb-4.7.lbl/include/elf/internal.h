begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF support for BFD.    Copyright (C) 1991, 1992 Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support, from information published    in "UNIX System V Release 4, Programmers Guide: ANSI C and    Programming Support Tools".  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This file is part of ELF support for BFD, and contains the portions    that describe how ELF is represented internally in the BFD library.    I.E. it describes the in-memory representation of ELF.  It requires    the elf-common.h file which contains the portions that are common to    both the internal and external representations. */
end_comment

begin_comment
comment|/* Types used by various structures, functions, etc. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Elf_Addr
typedef|;
end_typedef

begin_comment
comment|/* Unsigned program address */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Elf_Off
typedef|;
end_typedef

begin_comment
comment|/* Unsigned file offset */
end_comment

begin_typedef
typedef|typedef
name|long
name|Elf_Sword
typedef|;
end_typedef

begin_comment
comment|/* Signed large integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Elf_Word
typedef|;
end_typedef

begin_comment
comment|/* Unsigned large integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|Elf_Half
typedef|;
end_typedef

begin_comment
comment|/* Unsigned medium integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Elf_Char
typedef|;
end_typedef

begin_comment
comment|/* Unsigned tiny integer */
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
name|Elf_Half
name|e_type
decl_stmt|;
comment|/* Identifies object file type */
name|Elf_Half
name|e_machine
decl_stmt|;
comment|/* Specifies required architecture */
name|Elf_Word
name|e_version
decl_stmt|;
comment|/* Identifies object file version */
name|Elf_Addr
name|e_entry
decl_stmt|;
comment|/* Entry point virtual address */
name|Elf_Off
name|e_phoff
decl_stmt|;
comment|/* Program header table file offset */
name|Elf_Off
name|e_shoff
decl_stmt|;
comment|/* Section header table file offset */
name|Elf_Word
name|e_flags
decl_stmt|;
comment|/* Processor-specific flags */
name|Elf_Half
name|e_ehsize
decl_stmt|;
comment|/* ELF header size in bytes */
name|Elf_Half
name|e_phentsize
decl_stmt|;
comment|/* Program header table entry size */
name|Elf_Half
name|e_phnum
decl_stmt|;
comment|/* Program header table entry count */
name|Elf_Half
name|e_shentsize
decl_stmt|;
comment|/* Section header table entry size */
name|Elf_Half
name|e_shnum
decl_stmt|;
comment|/* Section header table entry count */
name|Elf_Half
name|e_shstrndx
decl_stmt|;
comment|/* Section header string table index */
block|}
name|Elf_Internal_Ehdr
typedef|;
end_typedef

begin_comment
comment|/* Program header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_phdr
block|{
name|Elf_Word
name|p_type
decl_stmt|;
comment|/* Identifies program segment type */
name|Elf_Off
name|p_offset
decl_stmt|;
comment|/* Segment file offset */
name|Elf_Addr
name|p_vaddr
decl_stmt|;
comment|/* Segment virtual address */
name|Elf_Addr
name|p_paddr
decl_stmt|;
comment|/* Segment physical address */
name|Elf_Word
name|p_filesz
decl_stmt|;
comment|/* Segment size in file */
name|Elf_Word
name|p_memsz
decl_stmt|;
comment|/* Segment size in memory */
name|Elf_Word
name|p_flags
decl_stmt|;
comment|/* Segment flags */
name|Elf_Word
name|p_align
decl_stmt|;
comment|/* Segment alignment, file& memory */
block|}
name|Elf_Internal_Phdr
typedef|;
end_typedef

begin_comment
comment|/* Section header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_shdr
block|{
name|Elf_Word
name|sh_name
decl_stmt|;
comment|/* Section name, index in string tbl */
name|Elf_Word
name|sh_type
decl_stmt|;
comment|/* Type of section */
name|Elf_Word
name|sh_flags
decl_stmt|;
comment|/* Miscellaneous section attributes */
name|Elf_Addr
name|sh_addr
decl_stmt|;
comment|/* Section virtual addr at execution */
name|Elf_Off
name|sh_offset
decl_stmt|;
comment|/* Section file offset */
name|Elf_Word
name|sh_size
decl_stmt|;
comment|/* Size of section in bytes */
name|Elf_Word
name|sh_link
decl_stmt|;
comment|/* Index of another section */
name|Elf_Word
name|sh_info
decl_stmt|;
comment|/* Additional section information */
name|Elf_Word
name|sh_addralign
decl_stmt|;
comment|/* Section alignment */
name|Elf_Word
name|sh_entsize
decl_stmt|;
comment|/* Entry size if section holds table */
comment|/* The internal rep also has some cached info associated with it. */
name|void
modifier|*
name|rawdata
decl_stmt|;
comment|/* null if unused... */
name|void
modifier|*
name|contents
decl_stmt|;
comment|/* null if unused... */
block|}
name|Elf_Internal_Shdr
typedef|;
end_typedef

begin_comment
comment|/* Symbol table entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_sym
block|{
name|Elf_Word
name|st_name
decl_stmt|;
comment|/* Symbol name, index in string tbl */
name|Elf_Addr
name|st_value
decl_stmt|;
comment|/* Value of the symbol */
name|Elf_Word
name|st_size
decl_stmt|;
comment|/* Associated symbol size */
name|Elf_Char
name|st_info
decl_stmt|;
comment|/* Type and binding attributes */
name|Elf_Char
name|st_other
decl_stmt|;
comment|/* No defined meaning, 0 */
name|Elf_Half
name|st_shndx
decl_stmt|;
comment|/* Associated section index */
block|}
name|Elf_Internal_Sym
typedef|;
end_typedef

begin_comment
comment|/* Note segments */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_note
block|{
name|Elf_Word
name|namesz
decl_stmt|;
comment|/* Size of entry's owner string */
name|Elf_Word
name|descsz
decl_stmt|;
comment|/* Size of the note descriptor */
name|Elf_Word
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

begin_comment
comment|/* Relocation Entries */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_rel
block|{
name|Elf_Addr
name|r_offset
decl_stmt|;
comment|/* Location at which to apply the action */
name|Elf_Word
name|r_info
decl_stmt|;
comment|/* index and type of relocation */
block|}
name|Elf_Internal_Rel
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|elf_internal_rela
block|{
name|Elf_Addr
name|r_offset
decl_stmt|;
comment|/* Location at which to apply the action */
name|Elf_Word
name|r_info
decl_stmt|;
comment|/* Index and Type of relocation */
name|Elf_Sword
name|r_addend
decl_stmt|;
comment|/* Constant addend used to compute value */
block|}
name|Elf_Internal_Rela
typedef|;
end_typedef

end_unit

