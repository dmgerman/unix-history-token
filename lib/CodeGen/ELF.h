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
file|"llvm/Support/DataTypes.h"
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
name|class
name|GlobalVariable
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
comment|/// ELFSection - This struct contains information about each section that is
comment|/// emitted to the file.  This is eventually turned into the section header
comment|/// table at the end of the file.
struct|struct
name|ELFSection
block|{
comment|// ELF specific fields
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|// Name of the section.
name|unsigned
name|NameIdx
decl_stmt|;
comment|// Index in .shstrtab of name, once emitted.
name|unsigned
name|Type
decl_stmt|;
name|unsigned
name|Flags
decl_stmt|;
name|uint64_t
name|Addr
decl_stmt|;
name|unsigned
name|Offset
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|unsigned
name|Link
decl_stmt|;
name|unsigned
name|Info
decl_stmt|;
name|unsigned
name|Align
decl_stmt|;
name|unsigned
name|EntSize
decl_stmt|;
comment|// Section Header Flags
enum|enum
block|{
name|SHF_WRITE
init|=
literal|1
operator|<<
literal|0
block|,
comment|// Writable
name|SHF_ALLOC
init|=
literal|1
operator|<<
literal|1
block|,
comment|// Mapped into the process addr space
name|SHF_EXECINSTR
init|=
literal|1
operator|<<
literal|2
block|,
comment|// Executable
name|SHF_MERGE
init|=
literal|1
operator|<<
literal|4
block|,
comment|// Might be merged if equal
name|SHF_STRINGS
init|=
literal|1
operator|<<
literal|5
block|,
comment|// Contains null-terminated strings
name|SHF_INFO_LINK
init|=
literal|1
operator|<<
literal|6
block|,
comment|// 'sh_info' contains SHT index
name|SHF_LINK_ORDER
init|=
literal|1
operator|<<
literal|7
block|,
comment|// Preserve order after combining
name|SHF_OS_NONCONFORMING
init|=
literal|1
operator|<<
literal|8
block|,
comment|// nonstandard OS support required
name|SHF_GROUP
init|=
literal|1
operator|<<
literal|9
block|,
comment|// Section is a member of a group
name|SHF_TLS
init|=
literal|1
operator|<<
literal|10
comment|// Section holds thread-local data
block|}
enum|;
comment|// Section Types
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
comment|/// SectionIdx - The number of the section in the Section Table.
name|unsigned
name|short
name|SectionIdx
decl_stmt|;
comment|/// SectionData - The actual data for this section which we are building
comment|/// up for emission to the file.
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|SectionData
expr_stmt|;
name|ELFSection
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
operator|:
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|Type
argument_list|(
literal|0
argument_list|)
operator|,
name|Flags
argument_list|(
literal|0
argument_list|)
operator|,
name|Addr
argument_list|(
literal|0
argument_list|)
operator|,
name|Offset
argument_list|(
literal|0
argument_list|)
operator|,
name|Size
argument_list|(
literal|0
argument_list|)
operator|,
name|Link
argument_list|(
literal|0
argument_list|)
operator|,
name|Info
argument_list|(
literal|0
argument_list|)
operator|,
name|Align
argument_list|(
literal|0
argument_list|)
operator|,
name|EntSize
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|/// ELFSym - This struct contains information about each symbol that is
comment|/// added to logical symbol table for the module.  This is eventually
comment|/// turned into a real symbol table in the file.
struct|struct
name|ELFSym
block|{
specifier|const
name|GlobalValue
modifier|*
name|GV
decl_stmt|;
comment|// The global value this corresponds to.
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
enum|enum
block|{
name|STB_LOCAL
init|=
literal|0
block|,
name|STB_GLOBAL
init|=
literal|1
block|,
name|STB_WEAK
init|=
literal|2
block|}
enum|;
enum|enum
block|{
name|STT_NOTYPE
init|=
literal|0
block|,
name|STT_OBJECT
init|=
literal|1
block|,
name|STT_FUNC
init|=
literal|2
block|,
name|STT_SECTION
init|=
literal|3
block|,
name|STT_FILE
init|=
literal|4
block|}
enum|;
name|ELFSym
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|gv
argument_list|)
operator|:
name|GV
argument_list|(
name|gv
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
literal|0
argument_list|)
operator|,
name|SectionIdx
argument_list|(
argument|ELFSection::SHN_UNDEF
argument_list|)
block|{}
name|void
name|SetBind
argument_list|(
argument|unsigned X
argument_list|)
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
block|;
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
block|;     }
name|void
name|SetType
argument_list|(
argument|unsigned X
argument_list|)
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
block|;
name|Info
operator|=
operator|(
name|Info
operator|&
literal|0xF0
operator|)
operator||
name|X
block|;     }
block|}
struct|;
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

