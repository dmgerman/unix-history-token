begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996-1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ELF64_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ELF64_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/elf_common.h>
end_include

begin_comment
comment|/*  * ELF definitions common to all 64-bit architectures.  */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|Elf64_Addr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|Elf64_Half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|Elf64_Off
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|Elf64_Sword
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|Elf64_Sxword
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|Elf64_Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|Elf64_Lword
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|Elf64_Xword
typedef|;
end_typedef

begin_comment
comment|/*  * Types of dynamic symbol hash table bucket and chain elements.  *  * This is inconsistent among 64 bit architectures, so a machine dependent  * typedef is required.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_typedef
typedef|typedef
name|Elf64_Off
name|Elf64_Hashelt
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|Elf64_Word
name|Elf64_Hashelt
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Non-standard class-dependent datatype used for abstraction. */
end_comment

begin_typedef
typedef|typedef
name|Elf64_Xword
name|Elf64_Size
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Elf64_Sxword
name|Elf64_Ssize
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
name|Elf64_Half
name|e_type
decl_stmt|;
comment|/* File type. */
name|Elf64_Half
name|e_machine
decl_stmt|;
comment|/* Machine architecture. */
name|Elf64_Word
name|e_version
decl_stmt|;
comment|/* ELF format version. */
name|Elf64_Addr
name|e_entry
decl_stmt|;
comment|/* Entry point. */
name|Elf64_Off
name|e_phoff
decl_stmt|;
comment|/* Program header file offset. */
name|Elf64_Off
name|e_shoff
decl_stmt|;
comment|/* Section header file offset. */
name|Elf64_Word
name|e_flags
decl_stmt|;
comment|/* Architecture-specific flags. */
name|Elf64_Half
name|e_ehsize
decl_stmt|;
comment|/* Size of ELF header in bytes. */
name|Elf64_Half
name|e_phentsize
decl_stmt|;
comment|/* Size of program header entry. */
name|Elf64_Half
name|e_phnum
decl_stmt|;
comment|/* Number of program header entries. */
name|Elf64_Half
name|e_shentsize
decl_stmt|;
comment|/* Size of section header entry. */
name|Elf64_Half
name|e_shnum
decl_stmt|;
comment|/* Number of section header entries. */
name|Elf64_Half
name|e_shstrndx
decl_stmt|;
comment|/* Section name strings section. */
block|}
name|Elf64_Ehdr
typedef|;
end_typedef

begin_comment
comment|/*  * Section header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|sh_name
decl_stmt|;
comment|/* Section name (index into the 					   section header string table). */
name|Elf64_Word
name|sh_type
decl_stmt|;
comment|/* Section type. */
name|Elf64_Xword
name|sh_flags
decl_stmt|;
comment|/* Section flags. */
name|Elf64_Addr
name|sh_addr
decl_stmt|;
comment|/* Address in memory image. */
name|Elf64_Off
name|sh_offset
decl_stmt|;
comment|/* Offset in file. */
name|Elf64_Xword
name|sh_size
decl_stmt|;
comment|/* Size in bytes. */
name|Elf64_Word
name|sh_link
decl_stmt|;
comment|/* Index of a related section. */
name|Elf64_Word
name|sh_info
decl_stmt|;
comment|/* Depends on section type. */
name|Elf64_Xword
name|sh_addralign
decl_stmt|;
comment|/* Alignment in bytes. */
name|Elf64_Xword
name|sh_entsize
decl_stmt|;
comment|/* Size of each entry in section. */
block|}
name|Elf64_Shdr
typedef|;
end_typedef

begin_comment
comment|/*  * Program header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|p_type
decl_stmt|;
comment|/* Entry type. */
name|Elf64_Word
name|p_flags
decl_stmt|;
comment|/* Access permission flags. */
name|Elf64_Off
name|p_offset
decl_stmt|;
comment|/* File offset of contents. */
name|Elf64_Addr
name|p_vaddr
decl_stmt|;
comment|/* Virtual address in memory image. */
name|Elf64_Addr
name|p_paddr
decl_stmt|;
comment|/* Physical address (not used). */
name|Elf64_Xword
name|p_filesz
decl_stmt|;
comment|/* Size of contents in file. */
name|Elf64_Xword
name|p_memsz
decl_stmt|;
comment|/* Size of contents in memory. */
name|Elf64_Xword
name|p_align
decl_stmt|;
comment|/* Alignment in memory and file. */
block|}
name|Elf64_Phdr
typedef|;
end_typedef

begin_comment
comment|/*  * Dynamic structure.  The ".dynamic" section contains an array of them.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Sxword
name|d_tag
decl_stmt|;
comment|/* Entry type. */
union|union
block|{
name|Elf64_Xword
name|d_val
decl_stmt|;
comment|/* Integer value. */
name|Elf64_Addr
name|d_ptr
decl_stmt|;
comment|/* Address value. */
block|}
name|d_un
union|;
block|}
name|Elf64_Dyn
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
name|Elf64_Addr
name|r_offset
decl_stmt|;
comment|/* Location to be relocated. */
name|Elf64_Xword
name|r_info
decl_stmt|;
comment|/* Relocation type and symbol index. */
block|}
name|Elf64_Rel
typedef|;
end_typedef

begin_comment
comment|/* Relocations that need an addend field. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Addr
name|r_offset
decl_stmt|;
comment|/* Location to be relocated. */
name|Elf64_Xword
name|r_info
decl_stmt|;
comment|/* Relocation type and symbol index. */
name|Elf64_Sxword
name|r_addend
decl_stmt|;
comment|/* Addend. */
block|}
name|Elf64_Rela
typedef|;
end_typedef

begin_comment
comment|/* Macros for accessing the fields of r_info. */
end_comment

begin_define
define|#
directive|define
name|ELF64_R_SYM
parameter_list|(
name|info
parameter_list|)
value|((info)>> 32)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE
parameter_list|(
name|info
parameter_list|)
value|((info)& 0xffffffffL)
end_define

begin_comment
comment|/* Macro for constructing r_info from field values. */
end_comment

begin_define
define|#
directive|define
name|ELF64_R_INFO
parameter_list|(
name|sym
parameter_list|,
name|type
parameter_list|)
value|(((sym)<< 32) + ((type)& 0xffffffffL))
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE_DATA
parameter_list|(
name|info
parameter_list|)
value|(((Elf64_Xword)(info)<<32)>>40)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE_ID
parameter_list|(
name|info
parameter_list|)
value|(((Elf64_Xword)(info)<<56)>>56)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE_INFO
parameter_list|(
name|data
parameter_list|,
name|type
parameter_list|)
define|\
value|(((Elf64_Xword)(data)<<8)+(Elf64_Xword)(type))
end_define

begin_comment
comment|/*  *	Note entry header  */
end_comment

begin_typedef
typedef|typedef
name|Elf_Note
name|Elf64_Nhdr
typedef|;
end_typedef

begin_comment
comment|/*  *	Move entry  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Lword
name|m_value
decl_stmt|;
comment|/* symbol value */
name|Elf64_Xword
name|m_info
decl_stmt|;
comment|/* size + index */
name|Elf64_Xword
name|m_poffset
decl_stmt|;
comment|/* symbol offset */
name|Elf64_Half
name|m_repeat
decl_stmt|;
comment|/* repeat count */
name|Elf64_Half
name|m_stride
decl_stmt|;
comment|/* stride info */
block|}
name|Elf64_Move
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ELF64_M_SYM
parameter_list|(
name|info
parameter_list|)
value|((info)>>8)
end_define

begin_define
define|#
directive|define
name|ELF64_M_SIZE
parameter_list|(
name|info
parameter_list|)
value|((unsigned char)(info))
end_define

begin_define
define|#
directive|define
name|ELF64_M_INFO
parameter_list|(
name|sym
parameter_list|,
name|size
parameter_list|)
value|(((sym)<<8)+(unsigned char)(size))
end_define

begin_comment
comment|/*  *	Hardware/Software capabilities entry  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Xword
name|c_tag
decl_stmt|;
comment|/* how to interpret value */
union|union
block|{
name|Elf64_Xword
name|c_val
decl_stmt|;
name|Elf64_Addr
name|c_ptr
decl_stmt|;
block|}
name|c_un
union|;
block|}
name|Elf64_Cap
typedef|;
end_typedef

begin_comment
comment|/*  * Symbol table entries.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|st_name
decl_stmt|;
comment|/* String table index of name. */
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
name|Elf64_Half
name|st_shndx
decl_stmt|;
comment|/* Section index of symbol. */
name|Elf64_Addr
name|st_value
decl_stmt|;
comment|/* Symbol value. */
name|Elf64_Xword
name|st_size
decl_stmt|;
comment|/* Size of associated object. */
block|}
name|Elf64_Sym
typedef|;
end_typedef

begin_comment
comment|/* Macros for accessing the fields of st_info. */
end_comment

begin_define
define|#
directive|define
name|ELF64_ST_BIND
parameter_list|(
name|info
parameter_list|)
value|((info)>> 4)
end_define

begin_define
define|#
directive|define
name|ELF64_ST_TYPE
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
name|ELF64_ST_INFO
parameter_list|(
name|bind
parameter_list|,
name|type
parameter_list|)
value|(((bind)<< 4) + ((type)& 0xf))
end_define

begin_comment
comment|/* Macro for accessing the fields of st_other. */
end_comment

begin_define
define|#
directive|define
name|ELF64_ST_VISIBILITY
parameter_list|(
name|oth
parameter_list|)
value|((oth)& 0x3)
end_define

begin_comment
comment|/* Structures used by Sun& GNU-style symbol versioning. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Half
name|vd_version
decl_stmt|;
name|Elf64_Half
name|vd_flags
decl_stmt|;
name|Elf64_Half
name|vd_ndx
decl_stmt|;
name|Elf64_Half
name|vd_cnt
decl_stmt|;
name|Elf64_Word
name|vd_hash
decl_stmt|;
name|Elf64_Word
name|vd_aux
decl_stmt|;
name|Elf64_Word
name|vd_next
decl_stmt|;
block|}
name|Elf64_Verdef
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|vda_name
decl_stmt|;
name|Elf64_Word
name|vda_next
decl_stmt|;
block|}
name|Elf64_Verdaux
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Half
name|vn_version
decl_stmt|;
name|Elf64_Half
name|vn_cnt
decl_stmt|;
name|Elf64_Word
name|vn_file
decl_stmt|;
name|Elf64_Word
name|vn_aux
decl_stmt|;
name|Elf64_Word
name|vn_next
decl_stmt|;
block|}
name|Elf64_Verneed
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|vna_hash
decl_stmt|;
name|Elf64_Half
name|vna_flags
decl_stmt|;
name|Elf64_Half
name|vna_other
decl_stmt|;
name|Elf64_Word
name|vna_name
decl_stmt|;
name|Elf64_Word
name|vna_next
decl_stmt|;
block|}
name|Elf64_Vernaux
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Elf64_Half
name|Elf64_Versym
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Half
name|si_boundto
decl_stmt|;
comment|/* direct bindings - symbol bound to */
name|Elf64_Half
name|si_flags
decl_stmt|;
comment|/* per symbol flags */
block|}
name|Elf64_Syminfo
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ELF64_H_ */
end_comment

end_unit

