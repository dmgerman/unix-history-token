begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/ELF.h - ELF constants and data structures --*- C++ -*-===//
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
comment|// The details of the ELF32 bits in this file are largely based on
end_comment

begin_comment
comment|// the Tool Interface Standard (TIS) Executable and Linking Format
end_comment

begin_comment
comment|// (ELF) Specification Version 1.2, May 1995. The ELF64 stuff is not
end_comment

begin_comment
comment|// standardized, as far as I can tell. It was largely based on information
end_comment

begin_comment
comment|// I found in OpenBSD header files.
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
name|LLVM_SUPPORT_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ELF
block|{
typedef|typedef
name|uint32_t
name|Elf32_Addr
typedef|;
comment|// Program address
typedef|typedef
name|uint16_t
name|Elf32_Half
typedef|;
typedef|typedef
name|uint32_t
name|Elf32_Off
typedef|;
comment|// File offset
typedef|typedef
name|int32_t
name|Elf32_Sword
typedef|;
typedef|typedef
name|uint32_t
name|Elf32_Word
typedef|;
typedef|typedef
name|uint64_t
name|Elf64_Addr
typedef|;
typedef|typedef
name|uint64_t
name|Elf64_Off
typedef|;
typedef|typedef
name|int32_t
name|Elf64_Shalf
typedef|;
typedef|typedef
name|int32_t
name|Elf64_Sword
typedef|;
typedef|typedef
name|uint32_t
name|Elf64_Word
typedef|;
typedef|typedef
name|int64_t
name|Elf64_Sxword
typedef|;
typedef|typedef
name|uint64_t
name|Elf64_Xword
typedef|;
typedef|typedef
name|uint32_t
name|Elf64_Half
typedef|;
typedef|typedef
name|uint16_t
name|Elf64_Quarter
typedef|;
comment|// Object file magic string.
specifier|static
specifier|const
name|char
name|ElfMagic
index|[]
init|=
block|{
literal|0x7f
block|,
literal|'E'
block|,
literal|'L'
block|,
literal|'F'
block|,
literal|'\0'
block|}
decl_stmt|;
struct|struct
name|Elf32_Ehdr
block|{
name|unsigned
name|char
name|e_ident
index|[
literal|16
index|]
decl_stmt|;
comment|// ELF Identification bytes
name|Elf32_Half
name|e_type
decl_stmt|;
comment|// Type of file (see ET_* below)
name|Elf32_Half
name|e_machine
decl_stmt|;
comment|// Required architecture for this file (see EM_*)
name|Elf32_Word
name|e_version
decl_stmt|;
comment|// Must be equal to 1
name|Elf32_Addr
name|e_entry
decl_stmt|;
comment|// Address to jump to in order to start program
name|Elf32_Off
name|e_phoff
decl_stmt|;
comment|// Program header table's file offset, in bytes
name|Elf32_Off
name|e_shoff
decl_stmt|;
comment|// Section header table's file offset, in bytes
name|Elf32_Word
name|e_flags
decl_stmt|;
comment|// Processor-specific flags
name|Elf32_Half
name|e_ehsize
decl_stmt|;
comment|// Size of ELF header, in bytes
name|Elf32_Half
name|e_phentsize
decl_stmt|;
comment|// Size of an entry in the program header table
name|Elf32_Half
name|e_phnum
decl_stmt|;
comment|// Number of entries in the program header table
name|Elf32_Half
name|e_shentsize
decl_stmt|;
comment|// Size of an entry in the section header table
name|Elf32_Half
name|e_shnum
decl_stmt|;
comment|// Number of entries in the section header table
name|Elf32_Half
name|e_shstrndx
decl_stmt|;
comment|// Sect hdr table index of sect name string table
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
name|ElfMagic
argument_list|,
name|strlen
argument_list|(
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
literal|4
index|]
return|;
block|}
name|unsigned
name|char
name|getDataEncoding
parameter_list|()
block|{
return|return
name|e_ident
index|[
literal|5
index|]
return|;
block|}
block|}
struct|;
comment|// 64-bit ELF header. Fields are the same as for ELF32, but with different
comment|// types (see above).
struct|struct
name|Elf64_Ehdr
block|{
name|unsigned
name|char
name|e_ident
index|[
literal|16
index|]
decl_stmt|;
name|Elf64_Quarter
name|e_type
decl_stmt|;
name|Elf64_Quarter
name|e_machine
decl_stmt|;
name|Elf64_Half
name|e_version
decl_stmt|;
name|Elf64_Addr
name|e_entry
decl_stmt|;
name|Elf64_Off
name|e_phoff
decl_stmt|;
name|Elf64_Off
name|e_shoff
decl_stmt|;
name|Elf64_Half
name|e_flags
decl_stmt|;
name|Elf64_Quarter
name|e_ehsize
decl_stmt|;
name|Elf64_Quarter
name|e_phentsize
decl_stmt|;
name|Elf64_Quarter
name|e_phnum
decl_stmt|;
name|Elf64_Quarter
name|e_shentsize
decl_stmt|;
name|Elf64_Quarter
name|e_shnum
decl_stmt|;
name|Elf64_Quarter
name|e_shstrndx
decl_stmt|;
block|}
struct|;
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
comment|// Machine architectures
enum|enum
block|{
name|EM_NONE
init|=
literal|0
block|,
comment|// No machine
name|EM_M32
init|=
literal|1
block|,
comment|// AT&T WE 32100
name|EM_SPARC
init|=
literal|2
block|,
comment|// SPARC
name|EM_386
init|=
literal|3
block|,
comment|// Intel 386
name|EM_68K
init|=
literal|4
block|,
comment|// Motorola 68000
name|EM_88K
init|=
literal|5
block|,
comment|// Motorola 88000
name|EM_486
init|=
literal|6
block|,
comment|// Intel 486 (deprecated)
name|EM_860
init|=
literal|7
block|,
comment|// Intel 80860
name|EM_MIPS
init|=
literal|8
block|,
comment|// MIPS R3000
name|EM_PPC
init|=
literal|20
block|,
comment|// PowerPC
name|EM_ARM
init|=
literal|40
block|,
comment|// ARM
name|EM_ALPHA
init|=
literal|41
block|,
comment|// DEC Alpha
name|EM_SPARCV9
init|=
literal|43
block|,
comment|// SPARC V9
name|EM_X86_64
init|=
literal|62
comment|// AMD64
block|}
enum|;
comment|// Object file classes.
enum|enum
block|{
name|ELFCLASS32
init|=
literal|1
block|,
comment|// 32-bit object file
name|ELFCLASS64
init|=
literal|2
comment|// 64-bit object file
block|}
enum|;
comment|// Object file byte orderings.
enum|enum
block|{
name|ELFDATA2LSB
init|=
literal|1
block|,
comment|// Little-endian object file
name|ELFDATA2MSB
init|=
literal|2
comment|// Big-endian object file
block|}
enum|;
comment|// Section header.
struct|struct
name|Elf32_Shdr
block|{
name|Elf32_Word
name|sh_name
decl_stmt|;
comment|// Section name (index into string table)
name|Elf32_Word
name|sh_type
decl_stmt|;
comment|// Section type (SHT_*)
name|Elf32_Word
name|sh_flags
decl_stmt|;
comment|// Section flags (SHF_*)
name|Elf32_Addr
name|sh_addr
decl_stmt|;
comment|// Address where section is to be loaded
name|Elf32_Off
name|sh_offset
decl_stmt|;
comment|// File offset of section data, in bytes
name|Elf32_Word
name|sh_size
decl_stmt|;
comment|// Size of section, in bytes
name|Elf32_Word
name|sh_link
decl_stmt|;
comment|// Section type-specific header table index link
name|Elf32_Word
name|sh_info
decl_stmt|;
comment|// Section type-specific extra information
name|Elf32_Word
name|sh_addralign
decl_stmt|;
comment|// Section address alignment
name|Elf32_Word
name|sh_entsize
decl_stmt|;
comment|// Size of records contained within the section
block|}
struct|;
comment|// Section header for ELF64 - same fields as ELF32, different types.
struct|struct
name|Elf64_Shdr
block|{
name|Elf64_Half
name|sh_name
decl_stmt|;
name|Elf64_Half
name|sh_type
decl_stmt|;
name|Elf64_Xword
name|sh_flags
decl_stmt|;
name|Elf64_Addr
name|sh_addr
decl_stmt|;
name|Elf64_Off
name|sh_offset
decl_stmt|;
name|Elf64_Xword
name|sh_size
decl_stmt|;
name|Elf64_Half
name|sh_link
decl_stmt|;
name|Elf64_Half
name|sh_info
decl_stmt|;
name|Elf64_Xword
name|sh_addralign
decl_stmt|;
name|Elf64_Xword
name|sh_entsize
decl_stmt|;
block|}
struct|;
comment|// Special section indices.
enum|enum
block|{
name|SHN_UNDEF
init|=
literal|0
block|,
comment|// Undefined, missing, irrelevant, or meaningless
name|SHN_LORESERVE
init|=
literal|0xff00
block|,
comment|// Lowest reserved index
name|SHN_LOPROC
init|=
literal|0xff00
block|,
comment|// Lowest processor-specific index
name|SHN_HIPROC
init|=
literal|0xff1f
block|,
comment|// Highest processor-specific index
name|SHN_ABS
init|=
literal|0xfff1
block|,
comment|// Symbol has absolute value; does not need relocation
name|SHN_COMMON
init|=
literal|0xfff2
block|,
comment|// FORTRAN COMMON or C external global variables
name|SHN_HIRESERVE
init|=
literal|0xffff
comment|// Highest reserved index
block|}
enum|;
comment|// Section types.
enum|enum
block|{
name|SHT_NULL
init|=
literal|0
block|,
comment|// No associated section (inactive entry).
name|SHT_PROGBITS
init|=
literal|1
block|,
comment|// Program-defined contents.
name|SHT_SYMTAB
init|=
literal|2
block|,
comment|// Symbol table.
name|SHT_STRTAB
init|=
literal|3
block|,
comment|// String table.
name|SHT_RELA
init|=
literal|4
block|,
comment|// Relocation entries; explicit addends.
name|SHT_HASH
init|=
literal|5
block|,
comment|// Symbol hash table.
name|SHT_DYNAMIC
init|=
literal|6
block|,
comment|// Information for dynamic linking.
name|SHT_NOTE
init|=
literal|7
block|,
comment|// Information about the file.
name|SHT_NOBITS
init|=
literal|8
block|,
comment|// Data occupies no space in the file.
name|SHT_REL
init|=
literal|9
block|,
comment|// Relocation entries; no explicit addends.
name|SHT_SHLIB
init|=
literal|10
block|,
comment|// Reserved.
name|SHT_DYNSYM
init|=
literal|11
block|,
comment|// Symbol table.
name|SHT_LOPROC
init|=
literal|0x70000000
block|,
comment|// Lowest processor architecture-specific type.
name|SHT_HIPROC
init|=
literal|0x7fffffff
block|,
comment|// Highest processor architecture-specific type.
name|SHT_LOUSER
init|=
literal|0x80000000
block|,
comment|// Lowest type reserved for applications.
name|SHT_HIUSER
init|=
literal|0xffffffff
comment|// Highest type reserved for applications.
block|}
enum|;
comment|// Section flags.
enum|enum
block|{
name|SHF_WRITE
init|=
literal|0x1
block|,
comment|// Section data should be writable during execution.
name|SHF_ALLOC
init|=
literal|0x2
block|,
comment|// Section occupies memory during program execution.
name|SHF_EXECINSTR
init|=
literal|0x4
block|,
comment|// Section contains executable machine instructions.
name|SHF_MASKPROC
init|=
literal|0xf0000000
comment|// Bits indicating processor-specific flags.
block|}
enum|;
comment|// Symbol table entries.
struct|struct
name|Elf32_Sym
block|{
name|Elf32_Word
name|st_name
decl_stmt|;
comment|// Symbol name (index into string table)
name|Elf32_Addr
name|st_value
decl_stmt|;
comment|// Value or address associated with the symbol
name|Elf32_Word
name|st_size
decl_stmt|;
comment|// Size of the symbol
name|unsigned
name|char
name|st_info
decl_stmt|;
comment|// Symbol's type and binding attributes
name|unsigned
name|char
name|st_other
decl_stmt|;
comment|// Must be zero; reserved
name|Elf32_Half
name|st_shndx
decl_stmt|;
comment|// Which section (header table index) it's defined in
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
block|}
struct|;
comment|// Symbol bindings.
enum|enum
block|{
name|STB_LOCAL
init|=
literal|0
block|,
comment|// Local symbol, not visible outside obj file containing def
name|STB_GLOBAL
init|=
literal|1
block|,
comment|// Global symbol, visible to all object files being combined
name|STB_WEAK
init|=
literal|2
block|,
comment|// Weak symbol, like global but lower-precedence
name|STB_LOPROC
init|=
literal|13
block|,
comment|// Lowest processor-specific binding type
name|STB_HIPROC
init|=
literal|15
comment|// Highest processor-specific binding type
block|}
enum|;
comment|// Symbol types.
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
block|,
comment|// Local, absolute symbol that refers to a file
name|STT_LOPROC
init|=
literal|13
block|,
comment|// Lowest processor-specific symbol type
name|STT_HIPROC
init|=
literal|15
comment|// Highest processor-specific symbol type
block|}
enum|;
comment|// Relocation entry, without explicit addend.
struct|struct
name|Elf32_Rel
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|// Location (file byte offset, or program virtual addr)
name|Elf32_Word
name|r_info
decl_stmt|;
comment|// Symbol table index and type of relocation to apply
comment|// These accessors and mutators correspond to the ELF32_R_SYM, ELF32_R_TYPE,
comment|// and ELF32_R_INFO macros defined in the ELF specification:
name|Elf32_Word
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
operator|(
name|r_info
operator|>>
literal|8
operator|)
return|;
block|}
name|unsigned
name|char
name|getType
argument_list|()
specifier|const
block|{
return|return
call|(
name|unsigned
name|char
call|)
argument_list|(
name|r_info
operator|&
literal|0x0ff
argument_list|)
return|;
block|}
name|void
name|setSymbol
parameter_list|(
name|Elf32_Word
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
name|void
name|setSymbolAndType
parameter_list|(
name|Elf32_Word
name|s
parameter_list|,
name|unsigned
name|char
name|t
parameter_list|)
block|{
name|r_info
operator|=
operator|(
name|s
operator|<<
literal|8
operator|)
operator|+
name|t
expr_stmt|;
block|}
empty_stmt|;
block|}
struct|;
comment|// Relocation entry with explicit addend.
struct|struct
name|Elf32_Rela
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|// Location (file byte offset, or program virtual addr)
name|Elf32_Word
name|r_info
decl_stmt|;
comment|// Symbol table index and type of relocation to apply
name|Elf32_Sword
name|r_addend
decl_stmt|;
comment|// Compute value for relocatable field by adding this
comment|// These accessors and mutators correspond to the ELF32_R_SYM, ELF32_R_TYPE,
comment|// and ELF32_R_INFO macros defined in the ELF specification:
name|Elf32_Word
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
operator|(
name|r_info
operator|>>
literal|8
operator|)
return|;
block|}
name|unsigned
name|char
name|getType
argument_list|()
specifier|const
block|{
return|return
call|(
name|unsigned
name|char
call|)
argument_list|(
name|r_info
operator|&
literal|0x0ff
argument_list|)
return|;
block|}
name|void
name|setSymbol
parameter_list|(
name|Elf32_Word
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
name|void
name|setSymbolAndType
parameter_list|(
name|Elf32_Word
name|s
parameter_list|,
name|unsigned
name|char
name|t
parameter_list|)
block|{
name|r_info
operator|=
operator|(
name|s
operator|<<
literal|8
operator|)
operator|+
name|t
expr_stmt|;
block|}
empty_stmt|;
block|}
struct|;
comment|// Program header.
struct|struct
name|Elf32_Phdr
block|{
name|Elf32_Word
name|p_type
decl_stmt|;
comment|// Type of segment
name|Elf32_Off
name|p_offset
decl_stmt|;
comment|// File offset where segment is located, in bytes
name|Elf32_Addr
name|p_vaddr
decl_stmt|;
comment|// Virtual address of beginning of segment
name|Elf32_Addr
name|p_paddr
decl_stmt|;
comment|// Physical address of beginning of segment (OS-specific)
name|Elf32_Word
name|p_filesz
decl_stmt|;
comment|// Num. of bytes in file image of segment (may be zero)
name|Elf32_Word
name|p_memsz
decl_stmt|;
comment|// Num. of bytes in mem image of segment (may be zero)
name|Elf32_Word
name|p_flags
decl_stmt|;
comment|// Segment flags
name|Elf32_Word
name|p_align
decl_stmt|;
comment|// Segment alignment constraint
block|}
struct|;
comment|// Segment types.
enum|enum
block|{
name|PT_NULL
init|=
literal|0
block|,
comment|// Unused segment.
name|PT_LOAD
init|=
literal|1
block|,
comment|// Loadable segment.
name|PT_DYNAMIC
init|=
literal|2
block|,
comment|// Dynamic linking information.
name|PT_INTERP
init|=
literal|3
block|,
comment|// Interpreter pathname.
name|PT_NOTE
init|=
literal|4
block|,
comment|// Auxiliary information.
name|PT_SHLIB
init|=
literal|5
block|,
comment|// Reserved.
name|PT_PHDR
init|=
literal|6
block|,
comment|// The program header table itself.
name|PT_LOPROC
init|=
literal|0x70000000
block|,
comment|// Lowest processor-specific program hdr entry type.
name|PT_HIPROC
init|=
literal|0x7fffffff
comment|// Highest processor-specific program hdr entry type.
block|}
enum|;
comment|// Segment flag bits.
enum|enum
block|{
name|PF_X
init|=
literal|1
block|,
comment|// Execute
name|PF_W
init|=
literal|2
block|,
comment|// Write
name|PF_R
init|=
literal|4
block|,
comment|// Read
name|PF_MASKPROC
init|=
literal|0xf0000000
comment|// Unspecified
block|}
enum|;
block|}
comment|// end namespace ELF
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

