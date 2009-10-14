begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/CodeGen/ELF.h - ELF constants and data structures ---*- C++ -*-===//
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
comment|// This header contains common, non-processor-specific data structures and
end_comment

begin_comment
comment|// constants for the ELF file format.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The details of the ELF32 bits in this file are largely based on the Tool
end_comment

begin_comment
comment|// Interface Standard (TIS) Executable and Linking Format (ELF) Specification
end_comment

begin_comment
comment|// Version 1.2, May 1995. The ELF64 is based on HP/Intel definition of the
end_comment

begin_comment
comment|// ELF-64 object file format document, Version 1.5 Draft 2 May 27, 1998
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
name|CODEGEN_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/BinaryObject.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRelocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
comment|// Identification Indexes
enum|enum
block|{
name|EI_MAG0
init|=
literal|0
block|,
name|EI_MAG1
init|=
literal|1
block|,
name|EI_MAG2
init|=
literal|2
block|,
name|EI_MAG3
init|=
literal|3
block|}
enum|;
comment|// File types
enum|enum
block|{
name|ET_NONE
init|=
literal|0
block|,
comment|// No file type
name|ET_REL
init|=
literal|1
block|,
comment|// Relocatable file
name|ET_EXEC
init|=
literal|2
block|,
comment|// Executable file
name|ET_DYN
init|=
literal|3
block|,
comment|// Shared object file
name|ET_CORE
init|=
literal|4
block|,
comment|// Core file
name|ET_LOPROC
init|=
literal|0xff00
block|,
comment|// Beginning of processor-specific codes
name|ET_HIPROC
init|=
literal|0xffff
comment|// Processor-specific
block|}
enum|;
comment|// Versioning
enum|enum
block|{
name|EV_NONE
init|=
literal|0
block|,
name|EV_CURRENT
init|=
literal|1
block|}
enum|;
comment|/// ELFSym - This struct contains information about each symbol that is
comment|/// added to logical symbol table for the module.  This is eventually
comment|/// turned into a real symbol table in the file.
struct|struct
name|ELFSym
block|{
comment|// ELF symbols are related to llvm ones by being one of the two llvm
comment|// types, for the other ones (section, file, func) a null pointer is
comment|// assumed by default.
union|union
block|{
specifier|const
name|GlobalValue
modifier|*
name|GV
decl_stmt|;
comment|// If this is a pointer to a GV
specifier|const
name|char
modifier|*
name|Ext
decl_stmt|;
comment|// If this is a pointer to a named symbol
block|}
name|Source
union|;
comment|// Describes from which source type this ELF symbol comes from,
comment|// they can be GlobalValue, ExternalSymbol or neither.
enum|enum
block|{
name|isGV
block|,
comment|// The Source.GV field is valid.
name|isExtSym
block|,
comment|// The Source.ExtSym field is valid.
name|isOther
comment|// Not a GlobalValue or External Symbol
block|}
enum|;
name|unsigned
name|SourceType
decl_stmt|;
name|bool
name|isGlobalValue
argument_list|()
specifier|const
block|{
return|return
name|SourceType
operator|==
name|isGV
return|;
block|}
name|bool
name|isExternalSym
argument_list|()
specifier|const
block|{
return|return
name|SourceType
operator|==
name|isExtSym
return|;
block|}
comment|// getGlobalValue - If this is a global value which originated the
comment|// elf symbol, return a reference to it.
specifier|const
name|GlobalValue
operator|*
name|getGlobalValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SourceType
operator|==
name|isGV
operator|&&
literal|"This is not a global value"
argument_list|)
block|;
return|return
name|Source
operator|.
name|GV
return|;
block|}
empty_stmt|;
comment|// getExternalSym - If this is an external symbol which originated the
comment|// elf symbol, return a reference to it.
specifier|const
name|char
operator|*
name|getExternalSymbol
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SourceType
operator|==
name|isExtSym
operator|&&
literal|"This is not an external symbol"
argument_list|)
block|;
return|return
name|Source
operator|.
name|Ext
return|;
block|}
empty_stmt|;
comment|// getGV - From a global value return a elf symbol to represent it
specifier|static
name|ELFSym
modifier|*
name|getGV
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|unsigned
name|Bind
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Visibility
parameter_list|)
block|{
name|ELFSym
modifier|*
name|Sym
init|=
name|new
name|ELFSym
argument_list|()
decl_stmt|;
name|Sym
operator|->
name|Source
operator|.
name|GV
operator|=
name|GV
expr_stmt|;
name|Sym
operator|->
name|setBind
argument_list|(
name|Bind
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setType
argument_list|(
name|Type
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setVisibility
argument_list|(
name|Visibility
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|SourceType
operator|=
name|isGV
expr_stmt|;
return|return
name|Sym
return|;
block|}
comment|// getExtSym - Create and return an elf symbol to represent an
comment|// external symbol
specifier|static
name|ELFSym
modifier|*
name|getExtSym
parameter_list|(
specifier|const
name|char
modifier|*
name|Ext
parameter_list|)
block|{
name|ELFSym
modifier|*
name|Sym
init|=
name|new
name|ELFSym
argument_list|()
decl_stmt|;
name|Sym
operator|->
name|Source
operator|.
name|Ext
operator|=
name|Ext
expr_stmt|;
name|Sym
operator|->
name|setBind
argument_list|(
name|STB_GLOBAL
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setType
argument_list|(
name|STT_NOTYPE
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setVisibility
argument_list|(
name|STV_DEFAULT
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|SourceType
operator|=
name|isExtSym
expr_stmt|;
return|return
name|Sym
return|;
block|}
comment|// getSectionSym - Returns a elf symbol to represent an elf section
specifier|static
name|ELFSym
modifier|*
name|getSectionSym
parameter_list|()
block|{
name|ELFSym
modifier|*
name|Sym
init|=
name|new
name|ELFSym
argument_list|()
decl_stmt|;
name|Sym
operator|->
name|setBind
argument_list|(
name|STB_LOCAL
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setType
argument_list|(
name|STT_SECTION
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setVisibility
argument_list|(
name|STV_DEFAULT
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|SourceType
operator|=
name|isOther
expr_stmt|;
return|return
name|Sym
return|;
block|}
comment|// getFileSym - Returns a elf symbol to represent the module identifier
specifier|static
name|ELFSym
modifier|*
name|getFileSym
parameter_list|()
block|{
name|ELFSym
modifier|*
name|Sym
init|=
name|new
name|ELFSym
argument_list|()
decl_stmt|;
name|Sym
operator|->
name|setBind
argument_list|(
name|STB_LOCAL
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setType
argument_list|(
name|STT_FILE
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setVisibility
argument_list|(
name|STV_DEFAULT
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|SectionIdx
operator|=
literal|0xfff1
expr_stmt|;
comment|// ELFSection::SHN_ABS;
name|Sym
operator|->
name|SourceType
operator|=
name|isOther
expr_stmt|;
return|return
name|Sym
return|;
block|}
comment|// getUndefGV - Returns a STT_NOTYPE symbol
specifier|static
name|ELFSym
modifier|*
name|getUndefGV
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|unsigned
name|Bind
parameter_list|)
block|{
name|ELFSym
modifier|*
name|Sym
init|=
name|new
name|ELFSym
argument_list|()
decl_stmt|;
name|Sym
operator|->
name|Source
operator|.
name|GV
operator|=
name|GV
expr_stmt|;
name|Sym
operator|->
name|setBind
argument_list|(
name|Bind
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setType
argument_list|(
name|STT_NOTYPE
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|setVisibility
argument_list|(
name|STV_DEFAULT
argument_list|)
expr_stmt|;
name|Sym
operator|->
name|SectionIdx
operator|=
literal|0
expr_stmt|;
comment|//ELFSection::SHN_UNDEF;
name|Sym
operator|->
name|SourceType
operator|=
name|isGV
expr_stmt|;
return|return
name|Sym
return|;
block|}
comment|// ELF specific fields
name|unsigned
name|NameIdx
decl_stmt|;
comment|// Index in .strtab of name, once emitted.
name|uint64_t
name|Value
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|uint8_t
name|Info
decl_stmt|;
name|uint8_t
name|Other
decl_stmt|;
name|unsigned
name|short
name|SectionIdx
decl_stmt|;
comment|// Symbol index into the Symbol table
name|unsigned
name|SymTabIdx
decl_stmt|;
enum|enum
block|{
name|STB_LOCAL
init|=
literal|0
block|,
comment|// Local sym, not visible outside obj file containing def
name|STB_GLOBAL
init|=
literal|1
block|,
comment|// Global sym, visible to all object files being combined
name|STB_WEAK
init|=
literal|2
comment|// Weak symbol, like global but lower-precedence
block|}
enum|;
enum|enum
block|{
name|STT_NOTYPE
init|=
literal|0
block|,
comment|// Symbol's type is not specified
name|STT_OBJECT
init|=
literal|1
block|,
comment|// Symbol is a data object (variable, array, etc.)
name|STT_FUNC
init|=
literal|2
block|,
comment|// Symbol is executable code (function, etc.)
name|STT_SECTION
init|=
literal|3
block|,
comment|// Symbol refers to a section
name|STT_FILE
init|=
literal|4
comment|// Local, absolute symbol that refers to a file
block|}
enum|;
enum|enum
block|{
name|STV_DEFAULT
init|=
literal|0
block|,
comment|// Visibility is specified by binding type
name|STV_INTERNAL
init|=
literal|1
block|,
comment|// Defined by processor supplements
name|STV_HIDDEN
init|=
literal|2
block|,
comment|// Not visible to other components
name|STV_PROTECTED
init|=
literal|3
comment|// Visible in other components but not preemptable
block|}
enum|;
name|ELFSym
argument_list|()
operator|:
name|SourceType
argument_list|(
name|isOther
argument_list|)
operator|,
name|NameIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|Value
argument_list|(
literal|0
argument_list|)
operator|,
name|Size
argument_list|(
literal|0
argument_list|)
operator|,
name|Info
argument_list|(
literal|0
argument_list|)
operator|,
name|Other
argument_list|(
name|STV_DEFAULT
argument_list|)
operator|,
name|SectionIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|SymTabIdx
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getBind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Info
operator|>>
literal|4
operator|)
operator|&
literal|0xf
return|;
block|}
name|unsigned
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Info
operator|&
literal|0xf
return|;
block|}
name|bool
name|isLocalBind
argument_list|()
specifier|const
block|{
return|return
name|getBind
argument_list|()
operator|==
name|STB_LOCAL
return|;
block|}
name|bool
name|isFileType
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|==
name|STT_FILE
return|;
block|}
name|void
name|setBind
parameter_list|(
name|unsigned
name|X
parameter_list|)
block|{
name|assert
argument_list|(
name|X
operator|==
operator|(
name|X
operator|&
literal|0xF
operator|)
operator|&&
literal|"Bind value out of range!"
argument_list|)
expr_stmt|;
name|Info
operator|=
operator|(
name|Info
operator|&
literal|0x0F
operator|)
operator||
operator|(
name|X
operator|<<
literal|4
operator|)
expr_stmt|;
block|}
name|void
name|setType
parameter_list|(
name|unsigned
name|X
parameter_list|)
block|{
name|assert
argument_list|(
name|X
operator|==
operator|(
name|X
operator|&
literal|0xF
operator|)
operator|&&
literal|"Type value out of range!"
argument_list|)
expr_stmt|;
name|Info
operator|=
operator|(
name|Info
operator|&
literal|0xF0
operator|)
operator||
name|X
expr_stmt|;
block|}
name|void
name|setVisibility
parameter_list|(
name|unsigned
name|V
parameter_list|)
block|{
name|assert
argument_list|(
name|V
operator|==
operator|(
name|V
operator|&
literal|0x3
operator|)
operator|&&
literal|"Visibility value out of range!"
argument_list|)
expr_stmt|;
name|Other
operator|=
name|V
expr_stmt|;
block|}
block|}
struct|;
comment|/// ELFSection - This struct contains information about each section that is
comment|/// emitted to the file.  This is eventually turned into the section header
comment|/// table at the end of the file.
name|class
name|ELFSection
range|:
name|public
name|BinaryObject
block|{
name|public
operator|:
comment|// ELF specific fields
name|unsigned
name|NameIdx
block|;
comment|// sh_name - .shstrtab idx of name, once emitted.
name|unsigned
name|Type
block|;
comment|// sh_type - Section contents& semantics
name|unsigned
name|Flags
block|;
comment|// sh_flags - Section flags.
name|uint64_t
name|Addr
block|;
comment|// sh_addr - The mem addr this section is in.
name|unsigned
name|Offset
block|;
comment|// sh_offset - Offset from the file start
name|unsigned
name|Size
block|;
comment|// sh_size - The section size.
name|unsigned
name|Link
block|;
comment|// sh_link - Section header table index link.
name|unsigned
name|Info
block|;
comment|// sh_info - Auxillary information.
name|unsigned
name|Align
block|;
comment|// sh_addralign - Alignment of section.
name|unsigned
name|EntSize
block|;
comment|// sh_entsize - Size of entries in the section e
comment|// Section Header Flags
block|enum
block|{
name|SHF_WRITE
operator|=
literal|1
operator|<<
literal|0
block|,
comment|// Writable
name|SHF_ALLOC
operator|=
literal|1
operator|<<
literal|1
block|,
comment|// Mapped into the process addr space
name|SHF_EXECINSTR
operator|=
literal|1
operator|<<
literal|2
block|,
comment|// Executable
name|SHF_MERGE
operator|=
literal|1
operator|<<
literal|4
block|,
comment|// Might be merged if equal
name|SHF_STRINGS
operator|=
literal|1
operator|<<
literal|5
block|,
comment|// Contains null-terminated strings
name|SHF_INFO_LINK
operator|=
literal|1
operator|<<
literal|6
block|,
comment|// 'sh_info' contains SHT index
name|SHF_LINK_ORDER
operator|=
literal|1
operator|<<
literal|7
block|,
comment|// Preserve order after combining
name|SHF_OS_NONCONFORMING
operator|=
literal|1
operator|<<
literal|8
block|,
comment|// nonstandard OS support required
name|SHF_GROUP
operator|=
literal|1
operator|<<
literal|9
block|,
comment|// Section is a member of a group
name|SHF_TLS
operator|=
literal|1
operator|<<
literal|10
comment|// Section holds thread-local data
block|}
block|;
comment|// Section Types
block|enum
block|{
name|SHT_NULL
operator|=
literal|0
block|,
comment|// No associated section (inactive entry).
name|SHT_PROGBITS
operator|=
literal|1
block|,
comment|// Program-defined contents.
name|SHT_SYMTAB
operator|=
literal|2
block|,
comment|// Symbol table.
name|SHT_STRTAB
operator|=
literal|3
block|,
comment|// String table.
name|SHT_RELA
operator|=
literal|4
block|,
comment|// Relocation entries; explicit addends.
name|SHT_HASH
operator|=
literal|5
block|,
comment|// Symbol hash table.
name|SHT_DYNAMIC
operator|=
literal|6
block|,
comment|// Information for dynamic linking.
name|SHT_NOTE
operator|=
literal|7
block|,
comment|// Information about the file.
name|SHT_NOBITS
operator|=
literal|8
block|,
comment|// Data occupies no space in the file.
name|SHT_REL
operator|=
literal|9
block|,
comment|// Relocation entries; no explicit addends.
name|SHT_SHLIB
operator|=
literal|10
block|,
comment|// Reserved.
name|SHT_DYNSYM
operator|=
literal|11
block|,
comment|// Symbol table.
name|SHT_LOPROC
operator|=
literal|0x70000000
block|,
comment|// Lowest processor arch-specific type.
name|SHT_HIPROC
operator|=
literal|0x7fffffff
block|,
comment|// Highest processor arch-specific type.
name|SHT_LOUSER
operator|=
literal|0x80000000
block|,
comment|// Lowest type reserved for applications.
name|SHT_HIUSER
operator|=
literal|0xffffffff
comment|// Highest type reserved for applications.
block|}
block|;
comment|// Special section indices.
block|enum
block|{
name|SHN_UNDEF
operator|=
literal|0
block|,
comment|// Undefined, missing, irrelevant
name|SHN_LORESERVE
operator|=
literal|0xff00
block|,
comment|// Lowest reserved index
name|SHN_LOPROC
operator|=
literal|0xff00
block|,
comment|// Lowest processor-specific index
name|SHN_HIPROC
operator|=
literal|0xff1f
block|,
comment|// Highest processor-specific index
name|SHN_ABS
operator|=
literal|0xfff1
block|,
comment|// Symbol has absolute value; no relocation
name|SHN_COMMON
operator|=
literal|0xfff2
block|,
comment|// FORTRAN COMMON or C external global variables
name|SHN_HIRESERVE
operator|=
literal|0xffff
comment|// Highest reserved index
block|}
block|;
comment|/// SectionIdx - The number of the section in the Section Table.
name|unsigned
name|short
name|SectionIdx
block|;
comment|/// Sym - The symbol to represent this section if it has one.
name|ELFSym
operator|*
name|Sym
block|;
comment|/// getSymIndex - Returns the symbol table index of the symbol
comment|/// representing this section.
name|unsigned
name|getSymbolTableIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Sym
operator|&&
literal|"section not present in the symbol table"
argument_list|)
block|;
return|return
name|Sym
operator|->
name|SymTabIdx
return|;
block|}
name|ELFSection
argument_list|(
argument|const std::string&name
argument_list|,
argument|bool isLittleEndian
argument_list|,
argument|bool is64Bit
argument_list|)
operator|:
name|BinaryObject
argument_list|(
name|name
argument_list|,
name|isLittleEndian
argument_list|,
name|is64Bit
argument_list|)
block|,
name|Type
argument_list|(
literal|0
argument_list|)
block|,
name|Flags
argument_list|(
literal|0
argument_list|)
block|,
name|Addr
argument_list|(
literal|0
argument_list|)
block|,
name|Offset
argument_list|(
literal|0
argument_list|)
block|,
name|Size
argument_list|(
literal|0
argument_list|)
block|,
name|Link
argument_list|(
literal|0
argument_list|)
block|,
name|Info
argument_list|(
literal|0
argument_list|)
block|,
name|Align
argument_list|(
literal|0
argument_list|)
block|,
name|EntSize
argument_list|(
literal|0
argument_list|)
block|,
name|Sym
argument_list|(
literal|0
argument_list|)
block|{}
block|}
decl_stmt|;
comment|/// ELFRelocation - This class contains all the information necessary to
comment|/// to generate any 32-bit or 64-bit ELF relocation entry.
name|class
name|ELFRelocation
block|{
name|uint64_t
name|r_offset
decl_stmt|;
comment|// offset in the section of the object this applies to
name|uint32_t
name|r_symidx
decl_stmt|;
comment|// symbol table index of the symbol to use
name|uint32_t
name|r_type
decl_stmt|;
comment|// machine specific relocation type
name|int64_t
name|r_add
decl_stmt|;
comment|// explicit relocation addend
name|bool
name|r_rela
decl_stmt|;
comment|// if true then the addend is part of the entry
comment|// otherwise the addend is at the location specified
comment|// by r_offset
name|public
label|:
name|uint64_t
name|getInfo
argument_list|(
name|bool
name|is64Bit
argument_list|)
decl|const
block|{
if|if
condition|(
name|is64Bit
condition|)
return|return
operator|(
operator|(
name|uint64_t
operator|)
name|r_symidx
operator|<<
literal|32
operator|)
operator|+
operator|(
operator|(
name|uint64_t
operator|)
name|r_type
operator|&
literal|0xFFFFFFFFL
operator|)
return|;
else|else
return|return
operator|(
name|r_symidx
operator|<<
literal|8
operator|)
operator|+
operator|(
name|r_type
operator|&
literal|0xFFL
operator|)
return|;
block|}
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|r_offset
return|;
block|}
name|int64_t
name|getAddend
argument_list|()
specifier|const
block|{
return|return
name|r_add
return|;
block|}
name|ELFRelocation
argument_list|(
argument|uint64_t off
argument_list|,
argument|uint32_t sym
argument_list|,
argument|uint32_t type
argument_list|,
argument|bool rela = true
argument_list|,
argument|int64_t addend =
literal|0
argument_list|)
block|:
name|r_offset
argument_list|(
name|off
argument_list|)
operator|,
name|r_symidx
argument_list|(
name|sym
argument_list|)
operator|,
name|r_type
argument_list|(
name|type
argument_list|)
operator|,
name|r_add
argument_list|(
name|addend
argument_list|)
operator|,
name|r_rela
argument_list|(
argument|rela
argument_list|)
block|{}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

