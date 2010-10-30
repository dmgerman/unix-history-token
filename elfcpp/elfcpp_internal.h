begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// elfcpp_internal.h -- internals for elfcpp   -*- C++ -*-
end_comment

begin_comment
comment|// This is included by elfcpp.h, the external interface, but holds
end_comment

begin_comment
comment|// information which we want to keep private.
end_comment

begin_include
include|#
directive|include
file|"elfcpp_config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ELFCPP_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|ELFCPP_INTERNAL_H
end_define

begin_decl_stmt
name|namespace
name|elfcpp
block|{
name|namespace
name|internal
block|{
comment|// The ELF file header.
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|Ehdr_data
block|{
name|unsigned
name|char
name|e_ident
index|[
name|EI_NIDENT
index|]
block|;
name|Elf_Half
name|e_type
block|;
name|Elf_Half
name|e_machine
block|;
name|Elf_Word
name|e_version
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Addr
name|e_entry
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Off
name|e_phoff
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Off
name|e_shoff
block|;
name|Elf_Word
name|e_flags
block|;
name|Elf_Half
name|e_ehsize
block|;
name|Elf_Half
name|e_phentsize
block|;
name|Elf_Half
name|e_phnum
block|;
name|Elf_Half
name|e_shentsize
block|;
name|Elf_Half
name|e_shnum
block|;
name|Elf_Half
name|e_shstrndx
block|; }
expr_stmt|;
comment|// An ELF section header.
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|Shdr_data
block|{
name|Elf_Word
name|sh_name
block|;
name|Elf_Word
name|sh_type
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|sh_flags
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Addr
name|sh_addr
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Off
name|sh_offset
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|sh_size
block|;
name|Elf_Word
name|sh_link
block|;
name|Elf_Word
name|sh_info
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|sh_addralign
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|sh_entsize
block|; }
expr_stmt|;
comment|// An ELF segment header.  We use template specialization for the
comment|// 32-bit and 64-bit versions because the fields are in a different
comment|// order.
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|Phdr_data
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|Phdr_data
operator|<
literal|32
operator|>
block|{
name|Elf_Word
name|p_type
block|;
name|Elf_types
operator|<
literal|32
operator|>
operator|::
name|Elf_Off
name|p_offset
block|;
name|Elf_types
operator|<
literal|32
operator|>
operator|::
name|Elf_Addr
name|p_vaddr
block|;
name|Elf_types
operator|<
literal|32
operator|>
operator|::
name|Elf_Addr
name|p_paddr
block|;
name|Elf_Word
name|p_filesz
block|;
name|Elf_Word
name|p_memsz
block|;
name|Elf_Word
name|p_flags
block|;
name|Elf_Word
name|p_align
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|Phdr_data
operator|<
literal|64
operator|>
block|{
name|Elf_Word
name|p_type
block|;
name|Elf_Word
name|p_flags
block|;
name|Elf_types
operator|<
literal|64
operator|>
operator|::
name|Elf_Off
name|p_offset
block|;
name|Elf_types
operator|<
literal|64
operator|>
operator|::
name|Elf_Addr
name|p_vaddr
block|;
name|Elf_types
operator|<
literal|64
operator|>
operator|::
name|Elf_Addr
name|p_paddr
block|;
name|Elf_Xword
name|p_filesz
block|;
name|Elf_Xword
name|p_memsz
block|;
name|Elf_Xword
name|p_align
block|; }
expr_stmt|;
comment|// An ELF symbol table entry.  We use template specialization for the
comment|// 32-bit and 64-bit versions because the fields are in a different
comment|// order.
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|Sym_data
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|Sym_data
operator|<
literal|32
operator|>
block|{
name|Elf_Word
name|st_name
block|;
name|Elf_types
operator|<
literal|32
operator|>
operator|::
name|Elf_Addr
name|st_value
block|;
name|Elf_Word
name|st_size
block|;
name|unsigned
name|char
name|st_info
block|;
name|unsigned
name|char
name|st_other
block|;
name|Elf_Half
name|st_shndx
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|Sym_data
operator|<
literal|64
operator|>
block|{
name|Elf_Word
name|st_name
block|;
name|unsigned
name|char
name|st_info
block|;
name|unsigned
name|char
name|st_other
block|;
name|Elf_Half
name|st_shndx
block|;
name|Elf_types
operator|<
literal|64
operator|>
operator|::
name|Elf_Addr
name|st_value
block|;
name|Elf_Xword
name|st_size
block|; }
expr_stmt|;
comment|// ELF relocation table entries.
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|Rel_data
block|{
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Addr
name|r_offset
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|r_info
block|; }
expr_stmt|;
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|Rela_data
block|{
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Addr
name|r_offset
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|r_info
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Swxword
name|r_addend
block|; }
expr_stmt|;
comment|// An entry in the ELF SHT_DYNAMIC section aka PT_DYNAMIC segment.
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|Dyn_data
block|{
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_Swxword
name|d_tag
block|;
name|typename
name|Elf_types
operator|<
name|size
operator|>
operator|::
name|Elf_WXword
name|d_val
block|; }
expr_stmt|;
comment|// An entry in a SHT_GNU_verdef section.  This structure is the same
comment|// in 32-bit and 64-bit ELF files.
struct|struct
name|Verdef_data
block|{
comment|// Version number of structure (VER_DEF_*).
name|Elf_Half
name|vd_version
decl_stmt|;
comment|// Bit flags (VER_FLG_*).
name|Elf_Half
name|vd_flags
decl_stmt|;
comment|// Version index.
name|Elf_Half
name|vd_ndx
decl_stmt|;
comment|// Number of auxiliary Verdaux entries.
name|Elf_Half
name|vd_cnt
decl_stmt|;
comment|// Hash of name.
name|Elf_Word
name|vd_hash
decl_stmt|;
comment|// Byte offset to first Verdaux entry.
name|Elf_Word
name|vd_aux
decl_stmt|;
comment|// Byte offset to next Verdef entry.
name|Elf_Word
name|vd_next
decl_stmt|;
block|}
struct|;
comment|// An auxiliary entry in a SHT_GNU_verdef section.  This structure is
comment|// the same in 32-bit and 64-bit ELF files.
struct|struct
name|Verdaux_data
block|{
comment|// Offset in string table of version name.
name|Elf_Word
name|vda_name
decl_stmt|;
comment|// Byte offset to next Verdaux entry.
name|Elf_Word
name|vda_next
decl_stmt|;
block|}
struct|;
comment|// An entry in a SHT_GNU_verneed section.  This structure is the same
comment|// in 32-bit and 64-bit ELF files.
struct|struct
name|Verneed_data
block|{
comment|// Version number of structure (VER_NEED_*).
name|Elf_Half
name|vn_version
decl_stmt|;
comment|// Number of auxiliary Vernaux entries.
name|Elf_Half
name|vn_cnt
decl_stmt|;
comment|// Offset in string table of library name.
name|Elf_Word
name|vn_file
decl_stmt|;
comment|// Byte offset to first Vernaux entry.
name|Elf_Word
name|vn_aux
decl_stmt|;
comment|// Byt eoffset to next Verneed entry.
name|Elf_Word
name|vn_next
decl_stmt|;
block|}
struct|;
comment|// An auxiliary entry in a SHT_GNU_verneed section.  This structure is
comment|// the same in 32-bit and 64-bit ELF files.
struct|struct
name|Vernaux_data
block|{
comment|// Hash of dependency name.
name|Elf_Word
name|vna_hash
decl_stmt|;
comment|// Bit flags (VER_FLG_*).
name|Elf_Half
name|vna_flags
decl_stmt|;
comment|// Version index used in SHT_GNU_versym entries.
name|Elf_Half
name|vna_other
decl_stmt|;
comment|// Offset in string table of version name.
name|Elf_Word
name|vna_name
decl_stmt|;
comment|// Byte offset to next Vernaux entry.
name|Elf_Word
name|vna_next
decl_stmt|;
block|}
struct|;
block|}
comment|// End namespace internal.
block|}
end_decl_stmt

begin_comment
comment|// End namespace elfcpp.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(ELFCPP_INTERNAL_H)
end_comment

end_unit

