begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ELFHeader.h ------------------------------------------- -*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|/// @file
end_comment

begin_comment
comment|/// @brief Generic structures and typedefs for ELF files.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file provides definitions for the various entities comprising an ELF
end_comment

begin_comment
comment|/// file.  The structures are generic in the sense that they do not correspond
end_comment

begin_comment
comment|/// to the exact binary layout of an ELF, but can be used to hold the
end_comment

begin_comment
comment|/// information present in both 32 and 64 bit variants of the format.  Each
end_comment

begin_comment
comment|/// entity provides a \c Parse method which is capable of transparently reading
end_comment

begin_comment
comment|/// both 32 and 64 bit instances of the object.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ELFHeader_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ELFHeader_h_
end_define

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/ELF.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DataExtractor
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace lldb_private.
end_comment

begin_decl_stmt
name|namespace
name|elf
block|{
comment|//------------------------------------------------------------------------------
comment|/// @name ELF type definitions.
comment|///
comment|/// Types used to represent the various components of ELF structures.  All types
comment|/// are signed or unsigned integral types wide enough to hold values from both
comment|/// 32 and 64 bit ELF variants.
comment|//@{
typedef|typedef
name|uint64_t
name|elf_addr
typedef|;
typedef|typedef
name|uint64_t
name|elf_off
typedef|;
typedef|typedef
name|uint16_t
name|elf_half
typedef|;
typedef|typedef
name|uint32_t
name|elf_word
typedef|;
typedef|typedef
name|int32_t
name|elf_sword
typedef|;
typedef|typedef
name|uint64_t
name|elf_size
typedef|;
typedef|typedef
name|uint64_t
name|elf_xword
typedef|;
typedef|typedef
name|int64_t
name|elf_sxword
typedef|;
comment|//@}
comment|//------------------------------------------------------------------------------
comment|/// @class ELFHeader
comment|/// @brief Generic representation of an ELF file header.
comment|///
comment|/// This object is used to identify the general attributes on an ELF file and to
comment|/// locate additional sections within the file.
struct|struct
name|ELFHeader
block|{
name|unsigned
name|char
name|e_ident
index|[
name|llvm
operator|::
name|ELF
operator|::
name|EI_NIDENT
index|]
decl_stmt|;
comment|///< ELF file identification.
name|elf_addr
name|e_entry
decl_stmt|;
comment|///< Virtual address program entry point.
name|elf_off
name|e_phoff
decl_stmt|;
comment|///< File offset of program header table.
name|elf_off
name|e_shoff
decl_stmt|;
comment|///< File offset of section header table.
name|elf_word
name|e_flags
decl_stmt|;
comment|///< Processor specific flags.
name|elf_word
name|e_version
decl_stmt|;
comment|///< Version of object file (always 1).
name|elf_half
name|e_type
decl_stmt|;
comment|///< Object file type.
name|elf_half
name|e_machine
decl_stmt|;
comment|///< Target architecture.
name|elf_half
name|e_ehsize
decl_stmt|;
comment|///< Byte size of the ELF header.
name|elf_half
name|e_phentsize
decl_stmt|;
comment|///< Size of a program header table entry.
name|elf_half
name|e_phnum_hdr
decl_stmt|;
comment|///< Number of program header entries.
name|elf_half
name|e_shentsize
decl_stmt|;
comment|///< Size of a section header table entry.
name|elf_half
name|e_shnum_hdr
decl_stmt|;
comment|///< Number of section header entries.
name|elf_half
name|e_shstrndx_hdr
decl_stmt|;
comment|///< String table section index.
comment|// In some cases these numbers do not fit in 16 bits and they are
comment|// stored outside of the header in section #0. Here are the actual
comment|// values.
name|elf_word
name|e_phnum
decl_stmt|;
comment|///< Number of program header entries.
name|elf_word
name|e_shnum
decl_stmt|;
comment|///< Number of section header entries.
name|elf_word
name|e_shstrndx
decl_stmt|;
comment|///< String table section index.
name|ELFHeader
argument_list|()
expr_stmt|;
comment|//--------------------------------------------------------------------------
comment|/// Returns true if this is a 32 bit ELF file header.
comment|///
comment|/// @return
comment|///    True if this is a 32 bit ELF file header.
name|bool
name|Is32Bit
argument_list|()
specifier|const
block|{
return|return
name|e_ident
index|[
name|llvm
operator|::
name|ELF
operator|::
name|EI_CLASS
index|]
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|ELFCLASS32
return|;
block|}
comment|//--------------------------------------------------------------------------
comment|/// Returns true if this is a 64 bit ELF file header.
comment|///
comment|/// @return
comment|///   True if this is a 64 bit ELF file header.
name|bool
name|Is64Bit
argument_list|()
specifier|const
block|{
return|return
name|e_ident
index|[
name|llvm
operator|::
name|ELF
operator|::
name|EI_CLASS
index|]
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|ELFCLASS64
return|;
block|}
comment|//--------------------------------------------------------------------------
comment|/// The byte order of this ELF file header.
comment|///
comment|/// @return
comment|///    The byte order of this ELF file as described by the header.
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
expr_stmt|;
comment|//--------------------------------------------------------------------------
comment|/// The jump slot relocation type of this ELF.
name|unsigned
name|GetRelocationJumpSlotType
argument_list|()
specifier|const
expr_stmt|;
comment|//--------------------------------------------------------------------------
comment|/// Check if there should be header extension in section header #0
comment|///
comment|/// @return
comment|///    True if parsing the ELFHeader requires reading header extension
comment|///    and false otherwise.
name|bool
name|HasHeaderExtension
argument_list|()
specifier|const
expr_stmt|;
comment|//--------------------------------------------------------------------------
comment|/// Parse an ELFHeader entry starting at position \p offset and
comment|/// update the data extractor with the address size and byte order
comment|/// attributes as defined by the header.
comment|///
comment|/// @param[in,out] data
comment|///    The DataExtractor to read from.  Updated with the address size and
comment|///    byte order attributes appropriate to this header.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFHeader was successfully read and false
comment|///    otherwise.
name|bool
name|Parse
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
comment|//--------------------------------------------------------------------------
comment|/// Examines at most EI_NIDENT bytes starting from the given pointer and
comment|/// determines if the magic ELF identification exists.
comment|///
comment|/// @return
comment|///    True if the given sequence of bytes identifies an ELF file.
specifier|static
name|bool
name|MagicBytesMatch
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|magic
parameter_list|)
function_decl|;
comment|//--------------------------------------------------------------------------
comment|/// Examines at most EI_NIDENT bytes starting from the given address and
comment|/// determines the address size of the underlying ELF file.  This function
comment|/// should only be called on an pointer for which MagicBytesMatch returns
comment|/// true.
comment|///
comment|/// @return
comment|///    The number of bytes forming an address in the ELF file (either 4 or
comment|///    8), else zero if the address size could not be determined.
specifier|static
name|unsigned
name|AddressSizeInBytes
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|magic
parameter_list|)
function_decl|;
name|private
label|:
comment|//--------------------------------------------------------------------------
comment|/// Parse an ELFHeader header extension entry.  This method is called
comment|/// by Parse().
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.
name|void
name|ParseHeaderExtension
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|)
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------------------
comment|/// @class ELFSectionHeader
comment|/// @brief Generic representation of an ELF section header.
struct|struct
name|ELFSectionHeader
block|{
name|elf_word
name|sh_name
decl_stmt|;
comment|///< Section name string index.
name|elf_word
name|sh_type
decl_stmt|;
comment|///< Section type.
name|elf_xword
name|sh_flags
decl_stmt|;
comment|///< Section attributes.
name|elf_addr
name|sh_addr
decl_stmt|;
comment|///< Virtual address of the section in memory.
name|elf_off
name|sh_offset
decl_stmt|;
comment|///< Start of section from beginning of file.
name|elf_xword
name|sh_size
decl_stmt|;
comment|///< Number of bytes occupied in the file.
name|elf_word
name|sh_link
decl_stmt|;
comment|///< Index of associated section.
name|elf_word
name|sh_info
decl_stmt|;
comment|///< Extra section info (overloaded).
name|elf_xword
name|sh_addralign
decl_stmt|;
comment|///< Power of two alignment constraint.
name|elf_xword
name|sh_entsize
decl_stmt|;
comment|///< Byte size of each section entry.
name|ELFSectionHeader
argument_list|()
expr_stmt|;
comment|//--------------------------------------------------------------------------
comment|/// Parse an ELFSectionHeader entry from the given DataExtracter starting at
comment|/// position \p offset.
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.  The address size of the extractor
comment|///    determines if a 32 or 64 bit object should be read.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFSectionHeader was successfully read and false
comment|///    otherwise.
name|bool
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------------------
comment|/// @class ELFProgramHeader
comment|/// @brief Generic representation of an ELF program header.
struct|struct
name|ELFProgramHeader
block|{
name|elf_word
name|p_type
decl_stmt|;
comment|///< Type of program segment.
name|elf_word
name|p_flags
decl_stmt|;
comment|///< Segment attributes.
name|elf_off
name|p_offset
decl_stmt|;
comment|///< Start of segment from beginning of file.
name|elf_addr
name|p_vaddr
decl_stmt|;
comment|///< Virtual address of segment in memory.
name|elf_addr
name|p_paddr
decl_stmt|;
comment|///< Physical address (for non-VM systems).
name|elf_xword
name|p_filesz
decl_stmt|;
comment|///< Byte size of the segment in file.
name|elf_xword
name|p_memsz
decl_stmt|;
comment|///< Byte size of the segment in memory.
name|elf_xword
name|p_align
decl_stmt|;
comment|///< Segment alignment constraint.
name|ELFProgramHeader
argument_list|()
expr_stmt|;
comment|/// Parse an ELFProgramHeader entry from the given DataExtractor starting at
comment|/// position \p offset.  The address size of the DataExtractor determines if
comment|/// a 32 or 64 bit object is to be parsed.
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.  The address size of the extractor
comment|///    determines if a 32 or 64 bit object should be read.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFProgramHeader was successfully read and false
comment|///    otherwise.
name|bool
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------------------
comment|/// @class ELFSymbol
comment|/// @brief Represents a symbol within an ELF symbol table.
struct|struct
name|ELFSymbol
block|{
name|elf_addr
name|st_value
decl_stmt|;
comment|///< Absolute or relocatable address.
name|elf_xword
name|st_size
decl_stmt|;
comment|///< Size of the symbol or zero.
name|elf_word
name|st_name
decl_stmt|;
comment|///< Symbol name string index.
name|unsigned
name|char
name|st_info
decl_stmt|;
comment|///< Symbol type and binding attributes.
name|unsigned
name|char
name|st_other
decl_stmt|;
comment|///< Reserved for future use.
name|elf_half
name|st_shndx
decl_stmt|;
comment|///< Section to which this symbol applies.
name|ELFSymbol
argument_list|()
expr_stmt|;
comment|/// Returns the binding attribute of the st_info member.
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
comment|/// Returns the type attribute of the st_info member.
name|unsigned
name|char
name|getType
argument_list|()
specifier|const
block|{
return|return
name|st_info
operator|&
literal|0x0F
return|;
block|}
comment|/// Sets the binding and type of the st_info member.
name|void
name|setBindingAndType
parameter_list|(
name|unsigned
name|char
name|binding
parameter_list|,
name|unsigned
name|char
name|type
parameter_list|)
block|{
name|st_info
operator|=
operator|(
name|binding
operator|<<
literal|4
operator|)
operator|+
operator|(
name|type
operator|&
literal|0x0F
operator|)
expr_stmt|;
block|}
specifier|static
specifier|const
name|char
modifier|*
name|bindingToCString
parameter_list|(
name|unsigned
name|char
name|binding
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|typeToCString
parameter_list|(
name|unsigned
name|char
name|type
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|sectionIndexToCString
argument_list|(
name|elf_half
name|shndx
argument_list|,
specifier|const
name|lldb_private
operator|::
name|SectionList
operator|*
name|section_list
argument_list|)
decl_stmt|;
comment|/// Parse an ELFSymbol entry from the given DataExtractor starting at
comment|/// position \p offset.  The address size of the DataExtractor determines if
comment|/// a 32 or 64 bit object is to be parsed.
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.  The address size of the extractor
comment|///    determines if a 32 or 64 bit object should be read.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFSymbol was successfully read and false otherwise.
name|bool
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|,
name|uint32_t
name|idx
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|*
name|strtab_data
argument_list|,
specifier|const
name|lldb_private
operator|::
name|SectionList
operator|*
name|section_list
argument_list|)
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------------------
comment|/// @class ELFDynamic
comment|/// @brief Represents an entry in an ELF dynamic table.
struct|struct
name|ELFDynamic
block|{
name|elf_sxword
name|d_tag
decl_stmt|;
comment|///< Type of dynamic table entry.
union|union
block|{
name|elf_xword
name|d_val
decl_stmt|;
comment|///< Integer value of the table entry.
name|elf_addr
name|d_ptr
decl_stmt|;
comment|///< Pointer value of the table entry.
block|}
union|;
name|ELFDynamic
argument_list|()
expr_stmt|;
comment|/// Parse an ELFDynamic entry from the given DataExtractor starting at
comment|/// position \p offset.  The address size of the DataExtractor determines if
comment|/// a 32 or 64 bit object is to be parsed.
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.  The address size of the extractor
comment|///    determines if a 32 or 64 bit object should be read.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFDynamic entry was successfully read and false
comment|///    otherwise.
name|bool
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------------------
comment|/// @class ELFRel
comment|/// @brief Represents a relocation entry with an implicit addend.
struct|struct
name|ELFRel
block|{
name|elf_addr
name|r_offset
decl_stmt|;
comment|///< Address of reference.
name|elf_xword
name|r_info
decl_stmt|;
comment|///< symbol index and type of relocation.
name|ELFRel
argument_list|()
expr_stmt|;
comment|/// Parse an ELFRel entry from the given DataExtractor starting at position
comment|/// \p offset.  The address size of the DataExtractor determines if a 32 or
comment|/// 64 bit object is to be parsed.
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.  The address size of the extractor
comment|///    determines if a 32 or 64 bit object should be read.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFRel entry was successfully read and false otherwise.
name|bool
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
comment|/// Returns the type when the given entry represents a 32-bit relocation.
specifier|static
name|unsigned
name|RelocType32
parameter_list|(
specifier|const
name|ELFRel
modifier|&
name|rel
parameter_list|)
block|{
return|return
name|rel
operator|.
name|r_info
operator|&
literal|0x0ff
return|;
block|}
comment|/// Returns the type when the given entry represents a 64-bit relocation.
specifier|static
name|unsigned
name|RelocType64
parameter_list|(
specifier|const
name|ELFRel
modifier|&
name|rel
parameter_list|)
block|{
return|return
name|rel
operator|.
name|r_info
operator|&
literal|0xffffffff
return|;
block|}
comment|/// Returns the symbol index when the given entry represents a 32-bit
comment|/// relocation.
specifier|static
name|unsigned
name|RelocSymbol32
parameter_list|(
specifier|const
name|ELFRel
modifier|&
name|rel
parameter_list|)
block|{
return|return
name|rel
operator|.
name|r_info
operator|>>
literal|8
return|;
block|}
comment|/// Returns the symbol index when the given entry represents a 64-bit
comment|/// relocation.
specifier|static
name|unsigned
name|RelocSymbol64
parameter_list|(
specifier|const
name|ELFRel
modifier|&
name|rel
parameter_list|)
block|{
return|return
name|rel
operator|.
name|r_info
operator|>>
literal|32
return|;
block|}
block|}
struct|;
comment|//------------------------------------------------------------------------------
comment|/// @class ELFRela
comment|/// @brief Represents a relocation entry with an explicit addend.
struct|struct
name|ELFRela
block|{
name|elf_addr
name|r_offset
decl_stmt|;
comment|///< Address of reference.
name|elf_xword
name|r_info
decl_stmt|;
comment|///< Symbol index and type of relocation.
name|elf_sxword
name|r_addend
decl_stmt|;
comment|///< Constant part of expression.
name|ELFRela
argument_list|()
expr_stmt|;
comment|/// Parse an ELFRela entry from the given DataExtractor starting at position
comment|/// \p offset.  The address size of the DataExtractor determines if a 32 or
comment|/// 64 bit object is to be parsed.
comment|///
comment|/// @param[in] data
comment|///    The DataExtractor to read from.  The address size of the extractor
comment|///    determines if a 32 or 64 bit object should be read.
comment|///
comment|/// @param[in,out] offset
comment|///    Pointer to an offset in the data.  On return the offset will be
comment|///    advanced by the number of bytes read.
comment|///
comment|/// @return
comment|///    True if the ELFRela entry was successfully read and false otherwise.
name|bool
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
comment|/// Returns the type when the given entry represents a 32-bit relocation.
specifier|static
name|unsigned
name|RelocType32
parameter_list|(
specifier|const
name|ELFRela
modifier|&
name|rela
parameter_list|)
block|{
return|return
name|rela
operator|.
name|r_info
operator|&
literal|0x0ff
return|;
block|}
comment|/// Returns the type when the given entry represents a 64-bit relocation.
specifier|static
name|unsigned
name|RelocType64
parameter_list|(
specifier|const
name|ELFRela
modifier|&
name|rela
parameter_list|)
block|{
return|return
name|rela
operator|.
name|r_info
operator|&
literal|0xffffffff
return|;
block|}
comment|/// Returns the symbol index when the given entry represents a 32-bit
comment|/// relocation.
specifier|static
name|unsigned
name|RelocSymbol32
parameter_list|(
specifier|const
name|ELFRela
modifier|&
name|rela
parameter_list|)
block|{
return|return
name|rela
operator|.
name|r_info
operator|>>
literal|8
return|;
block|}
comment|/// Returns the symbol index when the given entry represents a 64-bit
comment|/// relocation.
specifier|static
name|unsigned
name|RelocSymbol64
parameter_list|(
specifier|const
name|ELFRela
modifier|&
name|rela
parameter_list|)
block|{
return|return
name|rela
operator|.
name|r_info
operator|>>
literal|32
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace elf.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_ELFHeader_h_
end_comment

end_unit

