begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996-1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ELF32_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ELF32_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/elf_common.h>
end_include

begin_comment
comment|/*  * ELF definitions common to all 32-bit architectures.  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Addr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|Elf32_Half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Off
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|Elf32_Sword
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Size
typedef|;
end_typedef

begin_comment
comment|/*  * ELF header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|e_ident
index|[
name|EI_NIDENT
index|]
decl_stmt|;
comment|/* File identification. */
name|Elf32_Half
name|e_type
decl_stmt|;
comment|/* File type. */
name|Elf32_Half
name|e_machine
decl_stmt|;
comment|/* Machine architecture. */
name|Elf32_Word
name|e_version
decl_stmt|;
comment|/* ELF format version. */
name|Elf32_Addr
name|e_entry
decl_stmt|;
comment|/* Entry point. */
name|Elf32_Off
name|e_phoff
decl_stmt|;
comment|/* Program header file offset. */
name|Elf32_Off
name|e_shoff
decl_stmt|;
comment|/* Section header file offset. */
name|Elf32_Word
name|e_flags
decl_stmt|;
comment|/* Architecture-specific flags. */
name|Elf32_Half
name|e_ehsize
decl_stmt|;
comment|/* Size of ELF header in bytes. */
name|Elf32_Half
name|e_phentsize
decl_stmt|;
comment|/* Size of program header entry. */
name|Elf32_Half
name|e_phnum
decl_stmt|;
comment|/* Number of program header entries. */
name|Elf32_Half
name|e_shentsize
decl_stmt|;
comment|/* Size of section header entry. */
name|Elf32_Half
name|e_shnum
decl_stmt|;
comment|/* Number of section header entries. */
name|Elf32_Half
name|e_shstrndx
decl_stmt|;
comment|/* Section name strings section. */
block|}
name|Elf32_Ehdr
typedef|;
end_typedef

begin_comment
comment|/*  * Section header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|sh_name
decl_stmt|;
comment|/* Section name (index into the 					   section header string table). */
name|Elf32_Word
name|sh_type
decl_stmt|;
comment|/* Section type. */
name|Elf32_Word
name|sh_flags
decl_stmt|;
comment|/* Section flags. */
name|Elf32_Addr
name|sh_addr
decl_stmt|;
comment|/* Address in memory image. */
name|Elf32_Off
name|sh_offset
decl_stmt|;
comment|/* Offset in file. */
name|Elf32_Size
name|sh_size
decl_stmt|;
comment|/* Size in bytes. */
name|Elf32_Word
name|sh_link
decl_stmt|;
comment|/* Index of a related section. */
name|Elf32_Word
name|sh_info
decl_stmt|;
comment|/* Depends on section type. */
name|Elf32_Size
name|sh_addralign
decl_stmt|;
comment|/* Alignment in bytes. */
name|Elf32_Size
name|sh_entsize
decl_stmt|;
comment|/* Size of each entry in section. */
block|}
name|Elf32_Shdr
typedef|;
end_typedef

begin_comment
comment|/*  * Program header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|p_type
decl_stmt|;
comment|/* Entry type. */
name|Elf32_Off
name|p_offset
decl_stmt|;
comment|/* File offset of contents. */
name|Elf32_Addr
name|p_vaddr
decl_stmt|;
comment|/* Virtual address in memory image. */
name|Elf32_Addr
name|p_paddr
decl_stmt|;
comment|/* Physical address (not used). */
name|Elf32_Size
name|p_filesz
decl_stmt|;
comment|/* Size of contents in file. */
name|Elf32_Size
name|p_memsz
decl_stmt|;
comment|/* Size of contents in memory. */
name|Elf32_Word
name|p_flags
decl_stmt|;
comment|/* Access permission flags. */
name|Elf32_Size
name|p_align
decl_stmt|;
comment|/* Alignment in memory and file. */
block|}
name|Elf32_Phdr
typedef|;
end_typedef

begin_comment
comment|/*  * Dynamic structure.  The ".dynamic" section contains an array of them.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Sword
name|d_tag
decl_stmt|;
comment|/* Entry type. */
union|union
block|{
name|Elf32_Size
name|d_val
decl_stmt|;
comment|/* Integer value. */
name|Elf32_Addr
name|d_ptr
decl_stmt|;
comment|/* Address value. */
block|}
name|d_un
union|;
block|}
name|Elf32_Dyn
typedef|;
end_typedef

begin_comment
comment|/*  * Relocation entries.  */
end_comment

begin_comment
comment|/* Relocations that don't need an addend field. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|/* Location to be relocated. */
name|Elf32_Word
name|r_info
decl_stmt|;
comment|/* Relocation type and symbol index. */
block|}
name|Elf32_Rel
typedef|;
end_typedef

begin_comment
comment|/* Relocations that need an addend field. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|/* Location to be relocated. */
name|Elf32_Word
name|r_info
decl_stmt|;
comment|/* Relocation type and symbol index. */
name|Elf32_Sword
name|r_addend
decl_stmt|;
comment|/* Addend. */
block|}
name|Elf32_Rela
typedef|;
end_typedef

begin_comment
comment|/* Macros for accessing the fields of r_info. */
end_comment

begin_define
define|#
directive|define
name|ELF32_R_SYM
parameter_list|(
name|info
parameter_list|)
value|((info)>> 8)
end_define

begin_define
define|#
directive|define
name|ELF32_R_TYPE
parameter_list|(
name|info
parameter_list|)
value|((unsigned char)(info))
end_define

begin_comment
comment|/* Macro for constructing r_info from field values. */
end_comment

begin_define
define|#
directive|define
name|ELF32_R_INFO
parameter_list|(
name|sym
parameter_list|,
name|type
parameter_list|)
value|(((sym)<< 8) + (unsigned char)(type))
end_define

begin_comment
comment|/*  * Symbol table entries.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|st_name
decl_stmt|;
comment|/* String table index of name. */
name|Elf32_Addr
name|st_value
decl_stmt|;
comment|/* Symbol value. */
name|Elf32_Size
name|st_size
decl_stmt|;
comment|/* Size of associated object. */
name|unsigned
name|char
name|st_info
decl_stmt|;
comment|/* Type and binding information. */
name|unsigned
name|char
name|st_other
decl_stmt|;
comment|/* Reserved (not used). */
name|Elf32_Half
name|st_shndx
decl_stmt|;
comment|/* Section index of symbol. */
block|}
name|Elf32_Sym
typedef|;
end_typedef

begin_comment
comment|/* Macros for accessing the fields of st_info. */
end_comment

begin_define
define|#
directive|define
name|ELF32_ST_BIND
parameter_list|(
name|info
parameter_list|)
value|((info)>> 4)
end_define

begin_define
define|#
directive|define
name|ELF32_ST_TYPE
parameter_list|(
name|info
parameter_list|)
value|((info)& 0xf)
end_define

begin_comment
comment|/* Macro for constructing st_info from field values. */
end_comment

begin_define
define|#
directive|define
name|ELF32_ST_INFO
parameter_list|(
name|bind
parameter_list|,
name|type
parameter_list|)
value|(((bind)<< 4) + ((type)& 0xf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ELF32_H_ */
end_comment

end_unit

