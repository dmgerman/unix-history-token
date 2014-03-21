begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ELFTypes.h - Endian specific types for ELF ---------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_OBJECT_ELF_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_ELF_TYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|using
name|support
operator|::
name|endianness
expr_stmt|;
name|template
operator|<
name|endianness
name|target_endianness
operator|,
name|std
operator|::
name|size_t
name|max_alignment
operator|,
name|bool
name|is64Bits
operator|>
expr|struct
name|ELFType
block|{
specifier|static
specifier|const
name|endianness
name|TargetEndianness
operator|=
name|target_endianness
block|;
specifier|static
specifier|const
name|std
operator|::
name|size_t
name|MaxAlignment
operator|=
name|max_alignment
block|;
specifier|static
specifier|const
name|bool
name|Is64Bits
operator|=
name|is64Bits
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|int
name|max_align
operator|>
expr|struct
name|MaximumAlignment
block|{   enum
block|{
name|value
operator|=
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
operator|>
name|max_align
operator|?
name|max_align
operator|:
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
block|}
block|; }
expr_stmt|;
comment|// Templates to choose Elf_Addr and Elf_Off depending on is64Bits.
name|template
operator|<
name|endianness
name|target_endianness
operator|,
name|std
operator|::
name|size_t
name|max_alignment
operator|>
expr|struct
name|ELFDataTypeTypedefHelperCommon
block|{
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|uint16_t
operator|,
name|target_endianness
operator|,
name|MaximumAlignment
operator|<
name|uint16_t
operator|,
name|max_alignment
operator|>
operator|::
name|value
operator|>
name|Elf_Half
expr_stmt|;
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|uint32_t
operator|,
name|target_endianness
operator|,
name|MaximumAlignment
operator|<
name|uint32_t
operator|,
name|max_alignment
operator|>
operator|::
name|value
operator|>
name|Elf_Word
expr_stmt|;
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|int32_t
operator|,
name|target_endianness
operator|,
name|MaximumAlignment
operator|<
name|int32_t
operator|,
name|max_alignment
operator|>
operator|::
name|value
operator|>
name|Elf_Sword
expr_stmt|;
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|uint64_t
operator|,
name|target_endianness
operator|,
name|MaximumAlignment
operator|<
name|uint64_t
operator|,
name|max_alignment
operator|>
operator|::
name|value
operator|>
name|Elf_Xword
expr_stmt|;
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|int64_t
operator|,
name|target_endianness
operator|,
name|MaximumAlignment
operator|<
name|int64_t
operator|,
name|max_alignment
operator|>
operator|::
name|value
operator|>
name|Elf_Sxword
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|ELFDataTypeTypedefHelper
expr_stmt|;
comment|/// ELF 32bit types.
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|ELFDataTypeTypedefHelper
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
expr|>
operator|:
name|ELFDataTypeTypedefHelperCommon
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|>
block|{
typedef|typedef
name|uint32_t
name|value_type
typedef|;
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|value_type
operator|,
name|TargetEndianness
operator|,
name|MaximumAlignment
operator|<
name|value_type
operator|,
name|MaxAlign
operator|>
operator|::
name|value
operator|>
name|Elf_Addr
expr_stmt|;
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|value_type
operator|,
name|TargetEndianness
operator|,
name|MaximumAlignment
operator|<
name|value_type
operator|,
name|MaxAlign
operator|>
operator|::
name|value
operator|>
name|Elf_Off
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ELF 64bit types.
end_comment

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|ELFDataTypeTypedefHelper
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
expr|>
operator|:
name|ELFDataTypeTypedefHelperCommon
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|>
block|{
typedef|typedef
name|uint64_t
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|value_type
operator|,
name|TargetEndianness
operator|,
name|MaximumAlignment
operator|<
name|value_type
operator|,
name|MaxAlign
operator|>
operator|::
name|value
operator|>
name|Elf_Addr
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|support
operator|::
name|detail
operator|::
name|packed_endian_specific_integral
operator|<
name|value_type
operator|,
name|TargetEndianness
operator|,
name|MaximumAlignment
operator|<
name|value_type
operator|,
name|MaxAlign
operator|>
operator|::
name|value
operator|>
name|Elf_Off
expr_stmt|;
end_typedef

begin_comment
unit|};
comment|// I really don't like doing this, but the alternative is copypasta.
end_comment

begin_define
define|#
directive|define
name|LLVM_ELF_IMPORT_TYPES
parameter_list|(
name|E
parameter_list|,
name|M
parameter_list|,
name|W
parameter_list|)
define|\
value|typedef typename ELFDataTypeTypedefHelper<ELFType<E, M, W>>::Elf_Addr         \     Elf_Addr;                                                                  \ typedef typename ELFDataTypeTypedefHelper<ELFType<E, M, W>>::Elf_Off          \     Elf_Off;                                                                   \ typedef typename ELFDataTypeTypedefHelper<ELFType<E, M, W>>::Elf_Half         \     Elf_Half;                                                                  \ typedef typename ELFDataTypeTypedefHelper<ELFType<E, M, W>>::Elf_Word         \     Elf_Word;                                                                  \ typedef typename ELFDataTypeTypedefHelper<ELFType<E, M, W>>::Elf_Sword        \     Elf_Sword;                                                                 \ typedef typename ELFDataTypeTypedefHelper<ELFType<E, M, W>>::Elf_Xword        \     Elf_Xword;                                                                 \ typedef typename ELFDataTypeTypedefHelper<ELFType<E, M, W>>::Elf_Sxword       \     Elf_Sxword;
end_define

begin_define
define|#
directive|define
name|LLVM_ELF_IMPORT_TYPES_ELFT
parameter_list|(
name|ELFT
parameter_list|)
define|\
value|LLVM_ELF_IMPORT_TYPES(ELFT::TargetEndianness, ELFT::MaxAlignment,            \                         ELFT::Is64Bits)
end_define

begin_comment
comment|// Section header.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Shdr_Base
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Shdr_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|false
argument_list|)
name|Elf_Word
name|sh_name
block|;
comment|// Section name (index into string table)
name|Elf_Word
name|sh_type
block|;
comment|// Section type (SHT_*)
name|Elf_Word
name|sh_flags
block|;
comment|// Section flags (SHF_*)
name|Elf_Addr
name|sh_addr
block|;
comment|// Address where section is to be loaded
name|Elf_Off
name|sh_offset
block|;
comment|// File offset of section data, in bytes
name|Elf_Word
name|sh_size
block|;
comment|// Size of section, in bytes
name|Elf_Word
name|sh_link
block|;
comment|// Section type-specific header table index link
name|Elf_Word
name|sh_info
block|;
comment|// Section type-specific extra information
name|Elf_Word
name|sh_addralign
block|;
comment|// Section address alignment
name|Elf_Word
name|sh_entsize
block|;
comment|// Size of records contained within the section
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Shdr_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|true
argument_list|)
name|Elf_Word
name|sh_name
block|;
comment|// Section name (index into string table)
name|Elf_Word
name|sh_type
block|;
comment|// Section type (SHT_*)
name|Elf_Xword
name|sh_flags
block|;
comment|// Section flags (SHF_*)
name|Elf_Addr
name|sh_addr
block|;
comment|// Address where section is to be loaded
name|Elf_Off
name|sh_offset
block|;
comment|// File offset of section data, in bytes
name|Elf_Xword
name|sh_size
block|;
comment|// Size of section, in bytes
name|Elf_Word
name|sh_link
block|;
comment|// Section type-specific header table index link
name|Elf_Word
name|sh_info
block|;
comment|// Section type-specific extra information
name|Elf_Xword
name|sh_addralign
block|;
comment|// Section address alignment
name|Elf_Xword
name|sh_entsize
block|;
comment|// Size of records contained within the section
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Shdr_Impl
operator|:
name|Elf_Shdr_Base
operator|<
name|ELFT
operator|>
block|{
name|using
name|Elf_Shdr_Base
operator|<
name|ELFT
operator|>
operator|::
name|sh_entsize
block|;
name|using
name|Elf_Shdr_Base
operator|<
name|ELFT
operator|>
operator|::
name|sh_size
block|;
comment|/// @brief Get the number of entities this section contains if it has any.
name|unsigned
name|getEntityCount
argument_list|()
specifier|const
block|{
if|if
condition|(
name|sh_entsize
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|sh_size
operator|/
name|sh_entsize
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Sym_Base
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Sym_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|false
argument_list|)
name|Elf_Word
name|st_name
block|;
comment|// Symbol name (index into string table)
name|Elf_Addr
name|st_value
block|;
comment|// Value or address associated with the symbol
name|Elf_Word
name|st_size
block|;
comment|// Size of the symbol
name|unsigned
name|char
name|st_info
block|;
comment|// Symbol's type and binding attributes
name|unsigned
name|char
name|st_other
block|;
comment|// Must be zero; reserved
name|Elf_Half
name|st_shndx
block|;
comment|// Which section (header table index) it's defined in
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Sym_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|true
argument_list|)
name|Elf_Word
name|st_name
block|;
comment|// Symbol name (index into string table)
name|unsigned
name|char
name|st_info
block|;
comment|// Symbol's type and binding attributes
name|unsigned
name|char
name|st_other
block|;
comment|// Must be zero; reserved
name|Elf_Half
name|st_shndx
block|;
comment|// Which section (header table index) it's defined in
name|Elf_Addr
name|st_value
block|;
comment|// Value or address associated with the symbol
name|Elf_Xword
name|st_size
block|;
comment|// Size of the symbol
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Sym_Impl
operator|:
name|Elf_Sym_Base
operator|<
name|ELFT
operator|>
block|{
name|using
name|Elf_Sym_Base
operator|<
name|ELFT
operator|>
operator|::
name|st_info
block|;
comment|// These accessors and mutators correspond to the ELF32_ST_BIND,
comment|// ELF32_ST_TYPE, and ELF32_ST_INFO macros defined in the ELF specification:
name|unsigned
name|char
name|getBinding
argument_list|()
specifier|const
block|{
return|return
name|st_info
operator|>>
literal|4
return|;
block|}
name|unsigned
name|char
name|getType
argument_list|()
specifier|const
block|{
return|return
name|st_info
operator|&
literal|0x0f
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setBinding
parameter_list|(
name|unsigned
name|char
name|b
parameter_list|)
block|{
name|setBindingAndType
argument_list|(
name|b
argument_list|,
name|getType
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setType
parameter_list|(
name|unsigned
name|char
name|t
parameter_list|)
block|{
name|setBindingAndType
argument_list|(
name|getBinding
argument_list|()
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setBindingAndType
parameter_list|(
name|unsigned
name|char
name|b
parameter_list|,
name|unsigned
name|char
name|t
parameter_list|)
block|{
name|st_info
operator|=
operator|(
name|b
operator|<<
literal|4
operator|)
operator|+
operator|(
name|t
operator|&
literal|0x0f
operator|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|/// Elf_Versym: This is the structure of entries in the SHT_GNU_versym section
end_comment

begin_comment
comment|/// (.gnu.version). This structure is identical for ELF32 and ELF64.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Versym_Impl
block|{
name|LLVM_ELF_IMPORT_TYPES_ELFT
argument_list|(
argument|ELFT
argument_list|)
name|Elf_Half
name|vs_index
block|;
comment|// Version index with flags (e.g. VERSYM_HIDDEN)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Verdaux_Impl
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Elf_Verdef: This is the structure of entries in the SHT_GNU_verdef section
end_comment

begin_comment
comment|/// (.gnu.version_d). This structure is identical for ELF32 and ELF64.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Verdef_Impl
block|{
name|LLVM_ELF_IMPORT_TYPES_ELFT
argument_list|(
argument|ELFT
argument_list|)
typedef|typedef
name|Elf_Verdaux_Impl
operator|<
name|ELFT
operator|>
name|Elf_Verdaux
expr_stmt|;
name|Elf_Half
name|vd_version
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Version of this structure (e.g. VER_DEF_CURRENT)
end_comment

begin_decl_stmt
name|Elf_Half
name|vd_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Bitwise flags (VER_DEF_*)
end_comment

begin_decl_stmt
name|Elf_Half
name|vd_ndx
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Version index, used in .gnu.version entries
end_comment

begin_decl_stmt
name|Elf_Half
name|vd_cnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Number of Verdaux entries
end_comment

begin_decl_stmt
name|Elf_Word
name|vd_hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Hash of name
end_comment

begin_decl_stmt
name|Elf_Word
name|vd_aux
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Offset to the first Verdaux entry (in bytes)
end_comment

begin_decl_stmt
name|Elf_Word
name|vd_next
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Offset to the next Verdef entry (in bytes)
end_comment

begin_comment
comment|/// Get the first Verdaux entry for this Verdef.
end_comment

begin_expr_stmt
specifier|const
name|Elf_Verdaux
operator|*
name|getAux
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|Elf_Verdaux
operator|*
operator|>
operator|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|this
operator|+
name|vd_aux
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Elf_Verdaux: This is the structure of auxiliary data in the SHT_GNU_verdef
end_comment

begin_comment
comment|/// section (.gnu.version_d). This structure is identical for ELF32 and ELF64.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Verdaux_Impl
block|{
name|LLVM_ELF_IMPORT_TYPES_ELFT
argument_list|(
argument|ELFT
argument_list|)
name|Elf_Word
name|vda_name
block|;
comment|// Version name (offset in string table)
name|Elf_Word
name|vda_next
block|;
comment|// Offset to next Verdaux entry (in bytes)
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Elf_Verneed: This is the structure of entries in the SHT_GNU_verneed
end_comment

begin_comment
comment|/// section (.gnu.version_r). This structure is identical for ELF32 and ELF64.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Verneed_Impl
block|{
name|LLVM_ELF_IMPORT_TYPES_ELFT
argument_list|(
argument|ELFT
argument_list|)
name|Elf_Half
name|vn_version
block|;
comment|// Version of this structure (e.g. VER_NEED_CURRENT)
name|Elf_Half
name|vn_cnt
block|;
comment|// Number of associated Vernaux entries
name|Elf_Word
name|vn_file
block|;
comment|// Library name (string table offset)
name|Elf_Word
name|vn_aux
block|;
comment|// Offset to first Vernaux entry (in bytes)
name|Elf_Word
name|vn_next
block|;
comment|// Offset to next Verneed entry (in bytes)
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Elf_Vernaux: This is the structure of auxiliary data in SHT_GNU_verneed
end_comment

begin_comment
comment|/// section (.gnu.version_r). This structure is identical for ELF32 and ELF64.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Vernaux_Impl
block|{
name|LLVM_ELF_IMPORT_TYPES_ELFT
argument_list|(
argument|ELFT
argument_list|)
name|Elf_Word
name|vna_hash
block|;
comment|// Hash of dependency name
name|Elf_Half
name|vna_flags
block|;
comment|// Bitwise Flags (VER_FLAG_*)
name|Elf_Half
name|vna_other
block|;
comment|// Version index, used in .gnu.version entries
name|Elf_Word
name|vna_name
block|;
comment|// Dependency name
name|Elf_Word
name|vna_next
block|;
comment|// Offset to next Vernaux entry (in bytes)
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Elf_Dyn_Base: This structure matches the form of entries in the dynamic
end_comment

begin_comment
comment|///               table section (.dynamic) look like.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Dyn_Base
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Dyn_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|false
argument_list|)
name|Elf_Sword
name|d_tag
block|;
expr|union
block|{
name|Elf_Word
name|d_val
block|;
name|Elf_Addr
name|d_ptr
block|;   }
name|d_un
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Dyn_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|true
argument_list|)
name|Elf_Sxword
name|d_tag
block|;
expr|union
block|{
name|Elf_Xword
name|d_val
block|;
name|Elf_Addr
name|d_ptr
block|;   }
name|d_un
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Elf_Dyn_Impl: This inherits from Elf_Dyn_Base, adding getters and setters.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Dyn_Impl
operator|:
name|Elf_Dyn_Base
operator|<
name|ELFT
operator|>
block|{
name|using
name|Elf_Dyn_Base
operator|<
name|ELFT
operator|>
operator|::
name|d_tag
block|;
name|using
name|Elf_Dyn_Base
operator|<
name|ELFT
operator|>
operator|::
name|d_un
block|;
name|int64_t
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|d_tag
return|;
block|}
name|uint64_t
name|getVal
argument_list|()
specifier|const
block|{
return|return
name|d_un
operator|.
name|d_val
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uint64_t
name|getPtr
argument_list|()
specifier|const
block|{
return|return
name|d_un
operator|.
name|ptr
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Elf_Rel: Elf Relocation
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|,
name|bool
name|isRela
operator|>
expr|struct
name|Elf_Rel_Base
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Rel_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
operator|,
name|false
operator|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|false
argument_list|)
name|Elf_Addr
name|r_offset
block|;
comment|// Location (file byte offset, or program virtual addr)
name|Elf_Word
name|r_info
block|;
comment|// Symbol table index and type of relocation to apply
name|uint32_t
name|getRInfo
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isMips64EL
argument_list|)
block|;
return|return
name|r_info
return|;
block|}
name|void
name|setRInfo
argument_list|(
argument|uint32_t R
argument_list|)
block|{
name|r_info
operator|=
name|R
block|; }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Rel_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
operator|,
name|false
operator|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|true
argument_list|)
name|Elf_Addr
name|r_offset
block|;
comment|// Location (file byte offset, or program virtual addr)
name|Elf_Xword
name|r_info
block|;
comment|// Symbol table index and type of relocation to apply
name|uint64_t
name|getRInfo
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
name|uint64_t
name|t
operator|=
name|r_info
block|;
if|if
condition|(
operator|!
name|isMips64EL
condition|)
return|return
name|t
return|;
comment|// Mips64 little endian has a "special" encoding of r_info. Instead of one
comment|// 64 bit little endian number, it is a little endian 32 bit number followed
comment|// by a 32 bit big endian number.
return|return
operator|(
name|t
operator|<<
literal|32
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|8
operator|)
operator|&
literal|0xff000000
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|24
operator|)
operator|&
literal|0x00ff0000
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|40
operator|)
operator|&
literal|0x0000ff00
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|56
operator|)
operator|&
literal|0x000000ff
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setRInfo
parameter_list|(
name|uint64_t
name|R
parameter_list|)
block|{
comment|// FIXME: Add mips64el support.
name|r_info
operator|=
name|R
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Rel_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
operator|,
name|true
operator|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|false
argument_list|)
name|Elf_Addr
name|r_offset
block|;
comment|// Location (file byte offset, or program virtual addr)
name|Elf_Word
name|r_info
block|;
comment|// Symbol table index and type of relocation to apply
name|Elf_Sword
name|r_addend
block|;
comment|// Compute value for relocatable field by adding this
name|uint32_t
name|getRInfo
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isMips64EL
argument_list|)
block|;
return|return
name|r_info
return|;
block|}
name|void
name|setRInfo
argument_list|(
argument|uint32_t R
argument_list|)
block|{
name|r_info
operator|=
name|R
block|; }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Rel_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
operator|,
name|true
operator|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|true
argument_list|)
name|Elf_Addr
name|r_offset
block|;
comment|// Location (file byte offset, or program virtual addr)
name|Elf_Xword
name|r_info
block|;
comment|// Symbol table index and type of relocation to apply
name|Elf_Sxword
name|r_addend
block|;
comment|// Compute value for relocatable field by adding this.
name|uint64_t
name|getRInfo
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
comment|// Mips64 little endian has a "special" encoding of r_info. Instead of one
comment|// 64 bit little endian number, it is a little endian 32 bit number followed
comment|// by a 32 bit big endian number.
name|uint64_t
name|t
operator|=
name|r_info
block|;
if|if
condition|(
operator|!
name|isMips64EL
condition|)
return|return
name|t
return|;
return|return
operator|(
name|t
operator|<<
literal|32
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|8
operator|)
operator|&
literal|0xff000000
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|24
operator|)
operator|&
literal|0x00ff0000
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|40
operator|)
operator|&
literal|0x0000ff00
operator|)
operator||
operator|(
operator|(
name|t
operator|>>
literal|56
operator|)
operator|&
literal|0x000000ff
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setRInfo
parameter_list|(
name|uint64_t
name|R
parameter_list|)
block|{
comment|// FIXME: Add mips64el support.
name|r_info
operator|=
name|R
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|,
name|bool
name|isRela
operator|>
expr|struct
name|Elf_Rel_Impl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|,
name|bool
name|isRela
operator|>
expr|struct
name|Elf_Rel_Impl
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
operator|,
name|isRela
operator|>
operator|:
name|Elf_Rel_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
operator|,
name|isRela
operator|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|true
argument_list|)
comment|// These accessors and mutators correspond to the ELF64_R_SYM, ELF64_R_TYPE,
comment|// and ELF64_R_INFO macros defined in the ELF specification:
name|uint32_t
name|getSymbol
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
return|return
call|(
name|uint32_t
call|)
argument_list|(
name|this
operator|->
name|getRInfo
argument_list|(
name|isMips64EL
argument_list|)
operator|>>
literal|32
argument_list|)
return|;
block|}
name|uint32_t
name|getType
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
return|return
call|(
name|uint32_t
call|)
argument_list|(
name|this
operator|->
name|getRInfo
argument_list|(
name|isMips64EL
argument_list|)
operator|&
literal|0xffffffffL
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSymbol
parameter_list|(
name|uint32_t
name|s
parameter_list|)
block|{
name|setSymbolAndType
argument_list|(
name|s
argument_list|,
name|getType
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setType
parameter_list|(
name|uint32_t
name|t
parameter_list|)
block|{
name|setSymbolAndType
argument_list|(
name|getSymbol
argument_list|()
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setSymbolAndType
parameter_list|(
name|uint32_t
name|s
parameter_list|,
name|uint32_t
name|t
parameter_list|)
block|{
name|this
operator|->
name|setRInfo
argument_list|(
operator|(
operator|(
name|uint64_t
operator|)
name|s
operator|<<
literal|32
operator|)
operator|+
operator|(
name|t
operator|&
literal|0xffffffffL
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|,
name|bool
name|isRela
operator|>
expr|struct
name|Elf_Rel_Impl
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
operator|,
name|isRela
operator|>
operator|:
name|Elf_Rel_Base
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
operator|,
name|isRela
operator|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|false
argument_list|)
comment|// These accessors and mutators correspond to the ELF32_R_SYM, ELF32_R_TYPE,
comment|// and ELF32_R_INFO macros defined in the ELF specification:
name|uint32_t
name|getSymbol
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|getRInfo
argument_list|(
name|isMips64EL
argument_list|)
operator|>>
literal|8
return|;
block|}
name|unsigned
name|char
name|getType
argument_list|(
argument|bool isMips64EL
argument_list|)
specifier|const
block|{
return|return
call|(
name|unsigned
name|char
call|)
argument_list|(
name|this
operator|->
name|getRInfo
argument_list|(
name|isMips64EL
argument_list|)
operator|&
literal|0x0ff
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSymbol
parameter_list|(
name|uint32_t
name|s
parameter_list|)
block|{
name|setSymbolAndType
argument_list|(
name|s
argument_list|,
name|getType
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setType
parameter_list|(
name|unsigned
name|char
name|t
parameter_list|)
block|{
name|setSymbolAndType
argument_list|(
name|getSymbol
argument_list|()
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setSymbolAndType
parameter_list|(
name|uint32_t
name|s
parameter_list|,
name|unsigned
name|char
name|t
parameter_list|)
block|{
name|this
operator|->
name|setRInfo
argument_list|(
operator|(
name|s
operator|<<
literal|8
operator|)
operator|+
name|t
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Ehdr_Impl
block|{
name|LLVM_ELF_IMPORT_TYPES_ELFT
argument_list|(
argument|ELFT
argument_list|)
name|unsigned
name|char
name|e_ident
index|[
name|ELF
operator|::
name|EI_NIDENT
index|]
block|;
comment|// ELF Identification bytes
name|Elf_Half
name|e_type
block|;
comment|// Type of file (see ET_*)
name|Elf_Half
name|e_machine
block|;
comment|// Required architecture for this file (see EM_*)
name|Elf_Word
name|e_version
block|;
comment|// Must be equal to 1
name|Elf_Addr
name|e_entry
block|;
comment|// Address to jump to in order to start program
name|Elf_Off
name|e_phoff
block|;
comment|// Program header table's file offset, in bytes
name|Elf_Off
name|e_shoff
block|;
comment|// Section header table's file offset, in bytes
name|Elf_Word
name|e_flags
block|;
comment|// Processor-specific flags
name|Elf_Half
name|e_ehsize
block|;
comment|// Size of ELF header, in bytes
name|Elf_Half
name|e_phentsize
block|;
comment|// Size of an entry in the program header table
name|Elf_Half
name|e_phnum
block|;
comment|// Number of entries in the program header table
name|Elf_Half
name|e_shentsize
block|;
comment|// Size of an entry in the section header table
name|Elf_Half
name|e_shnum
block|;
comment|// Number of entries in the section header table
name|Elf_Half
name|e_shstrndx
block|;
comment|// Section header table index of section name
comment|// string table
name|bool
name|checkMagic
argument_list|()
specifier|const
block|{
return|return
operator|(
name|memcmp
argument_list|(
name|e_ident
argument_list|,
name|ELF
operator|::
name|ElfMagic
argument_list|,
name|strlen
argument_list|(
name|ELF
operator|::
name|ElfMagic
argument_list|)
argument_list|)
operator|)
operator|==
literal|0
return|;
block|}
name|unsigned
name|char
name|getFileClass
argument_list|()
specifier|const
block|{
return|return
name|e_ident
index|[
name|ELF
operator|::
name|EI_CLASS
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|char
name|getDataEncoding
argument_list|()
specifier|const
block|{
return|return
name|e_ident
index|[
name|ELF
operator|::
name|EI_DATA
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|Elf_Phdr_Impl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Phdr_Impl
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|false
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|false
argument_list|)
name|Elf_Word
name|p_type
block|;
comment|// Type of segment
name|Elf_Off
name|p_offset
block|;
comment|// FileOffset where segment is located, in bytes
name|Elf_Addr
name|p_vaddr
block|;
comment|// Virtual Address of beginning of segment
name|Elf_Addr
name|p_paddr
block|;
comment|// Physical address of beginning of segment (OS-specific)
name|Elf_Word
name|p_filesz
block|;
comment|// Num. of bytes in file image of segment (may be zero)
name|Elf_Word
name|p_memsz
block|;
comment|// Num. of bytes in mem image of segment (may be zero)
name|Elf_Word
name|p_flags
block|;
comment|// Segment flags
name|Elf_Word
name|p_align
block|;
comment|// Segment alignment constraint
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|endianness
name|TargetEndianness
operator|,
name|std
operator|::
name|size_t
name|MaxAlign
operator|>
expr|struct
name|Elf_Phdr_Impl
operator|<
name|ELFType
operator|<
name|TargetEndianness
operator|,
name|MaxAlign
operator|,
name|true
operator|>
expr|>
block|{
name|LLVM_ELF_IMPORT_TYPES
argument_list|(
argument|TargetEndianness
argument_list|,
argument|MaxAlign
argument_list|,
argument|true
argument_list|)
name|Elf_Word
name|p_type
block|;
comment|// Type of segment
name|Elf_Word
name|p_flags
block|;
comment|// Segment flags
name|Elf_Off
name|p_offset
block|;
comment|// FileOffset where segment is located, in bytes
name|Elf_Addr
name|p_vaddr
block|;
comment|// Virtual Address of beginning of segment
name|Elf_Addr
name|p_paddr
block|;
comment|// Physical address of beginning of segment (OS-specific)
name|Elf_Xword
name|p_filesz
block|;
comment|// Num. of bytes in file image of segment (may be zero)
name|Elf_Xword
name|p_memsz
block|;
comment|// Num. of bytes in mem image of segment (may be zero)
name|Elf_Xword
name|p_align
block|;
comment|// Segment alignment constraint
block|}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace object.
end_comment

begin_comment
unit|}
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

