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
comment|// The details of the ELF32 bits in this file are largely based on the Tool
end_comment

begin_comment
comment|// Interface Standard (TIS) Executable and Linking Format (ELF) Specification
end_comment

begin_comment
comment|// Version 1.2, May 1995. The ELF64 stuff is based on ELF-64 Object File Format
end_comment

begin_comment
comment|// Version 1.5, Draft 2, May 1998 as well as OpenBSD header files.
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
comment|// e_ident size and indices.
enum|enum
block|{
name|EI_MAG0
init|=
literal|0
block|,
comment|// File identification index.
name|EI_MAG1
init|=
literal|1
block|,
comment|// File identification index.
name|EI_MAG2
init|=
literal|2
block|,
comment|// File identification index.
name|EI_MAG3
init|=
literal|3
block|,
comment|// File identification index.
name|EI_CLASS
init|=
literal|4
block|,
comment|// File class.
name|EI_DATA
init|=
literal|5
block|,
comment|// Data encoding.
name|EI_VERSION
init|=
literal|6
block|,
comment|// File version.
name|EI_OSABI
init|=
literal|7
block|,
comment|// OS/ABI identification.
name|EI_ABIVERSION
init|=
literal|8
block|,
comment|// ABI version.
name|EI_PAD
init|=
literal|9
block|,
comment|// Start of padding bytes.
name|EI_NIDENT
init|=
literal|16
comment|// Number of bytes in e_ident.
block|}
enum|;
struct|struct
name|Elf32_Ehdr
block|{
name|unsigned
name|char
name|e_ident
index|[
name|EI_NIDENT
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
name|EI_CLASS
index|]
return|;
block|}
name|unsigned
name|char
name|getDataEncoding
argument_list|()
specifier|const
block|{
return|return
name|e_ident
index|[
name|EI_DATA
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
name|EI_NIDENT
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
name|EI_CLASS
index|]
return|;
block|}
name|unsigned
name|char
name|getDataEncoding
argument_list|()
specifier|const
block|{
return|return
name|e_ident
index|[
name|EI_DATA
index|]
return|;
block|}
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
name|EM_PPC64
init|=
literal|21
block|,
comment|// PowerPC64
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
name|ELFDATANONE
init|=
literal|0
block|,
comment|// Invalid data encoding.
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
comment|// OS ABI identification.
enum|enum
block|{
name|ELFOSABI_NONE
init|=
literal|0
block|,
comment|// UNIX System V ABI
name|ELFOSABI_HPUX
init|=
literal|1
block|,
comment|// HP-UX operating system
name|ELFOSABI_NETBSD
init|=
literal|2
block|,
comment|// NetBSD
name|ELFOSABI_LINUX
init|=
literal|3
block|,
comment|// GNU/Linux
name|ELFOSABI_HURD
init|=
literal|4
block|,
comment|// GNU/Hurd
name|ELFOSABI_SOLARIS
init|=
literal|6
block|,
comment|// Solaris
name|ELFOSABI_AIX
init|=
literal|7
block|,
comment|// AIX
name|ELFOSABI_IRIX
init|=
literal|8
block|,
comment|// IRIX
name|ELFOSABI_FREEBSD
init|=
literal|9
block|,
comment|// FreeBSD
name|ELFOSABI_TRU64
init|=
literal|10
block|,
comment|// TRU64 UNIX
name|ELFOSABI_MODESTO
init|=
literal|11
block|,
comment|// Novell Modesto
name|ELFOSABI_OPENBSD
init|=
literal|12
block|,
comment|// OpenBSD
name|ELFOSABI_OPENVMS
init|=
literal|13
block|,
comment|// OpenVMS
name|ELFOSABI_NSK
init|=
literal|14
block|,
comment|// Hewlett-Packard Non-Stop Kernel
name|ELFOSABI_AROS
init|=
literal|15
block|,
comment|// AROS
name|ELFOSABI_FENIXOS
init|=
literal|16
block|,
comment|// FenixOS
name|ELFOSABI_C6000_ELFABI
init|=
literal|64
block|,
comment|// Bare-metal TMS320C6000
name|ELFOSABI_C6000_LINUX
init|=
literal|65
block|,
comment|// Linux TMS320C6000
name|ELFOSABI_ARM
init|=
literal|97
block|,
comment|// ARM
name|ELFOSABI_STANDALONE
init|=
literal|255
comment|// Standalone (embedded) application
block|}
enum|;
comment|// X86_64 relocations.
enum|enum
block|{
name|R_X86_64_NONE
init|=
literal|0
block|,
name|R_X86_64_64
init|=
literal|1
block|,
name|R_X86_64_PC32
init|=
literal|2
block|,
name|R_X86_64_GOT32
init|=
literal|3
block|,
name|R_X86_64_PLT32
init|=
literal|4
block|,
name|R_X86_64_COPY
init|=
literal|5
block|,
name|R_X86_64_GLOB_DAT
init|=
literal|6
block|,
name|R_X86_64_JUMP_SLOT
init|=
literal|7
block|,
name|R_X86_64_RELATIVE
init|=
literal|8
block|,
name|R_X86_64_GOTPCREL
init|=
literal|9
block|,
name|R_X86_64_32
init|=
literal|10
block|,
name|R_X86_64_32S
init|=
literal|11
block|,
name|R_X86_64_16
init|=
literal|12
block|,
name|R_X86_64_PC16
init|=
literal|13
block|,
name|R_X86_64_8
init|=
literal|14
block|,
name|R_X86_64_PC8
init|=
literal|15
block|,
name|R_X86_64_DTPMOD64
init|=
literal|16
block|,
name|R_X86_64_DTPOFF64
init|=
literal|17
block|,
name|R_X86_64_TPOFF64
init|=
literal|18
block|,
name|R_X86_64_TLSGD
init|=
literal|19
block|,
name|R_X86_64_TLSLD
init|=
literal|20
block|,
name|R_X86_64_DTPOFF32
init|=
literal|21
block|,
name|R_X86_64_GOTTPOFF
init|=
literal|22
block|,
name|R_X86_64_TPOFF32
init|=
literal|23
block|,
name|R_X86_64_PC64
init|=
literal|24
block|,
name|R_X86_64_GOTOFF64
init|=
literal|25
block|,
name|R_X86_64_GOTPC32
init|=
literal|26
block|,
name|R_X86_64_SIZE32
init|=
literal|32
block|,
name|R_X86_64_SIZE64
init|=
literal|33
block|,
name|R_X86_64_GOTPC32_TLSDESC
init|=
literal|34
block|,
name|R_X86_64_TLSDESC_CALL
init|=
literal|35
block|,
name|R_X86_64_TLSDESC
init|=
literal|36
block|}
enum|;
comment|// i386 relocations.
comment|// TODO: this is just a subset
enum|enum
block|{
name|R_386_NONE
init|=
literal|0
block|,
name|R_386_32
init|=
literal|1
block|,
name|R_386_PC32
init|=
literal|2
block|,
name|R_386_GOT32
init|=
literal|3
block|,
name|R_386_PLT32
init|=
literal|4
block|,
name|R_386_COPY
init|=
literal|5
block|,
name|R_386_GLOB_DAT
init|=
literal|6
block|,
name|R_386_JUMP_SLOT
init|=
literal|7
block|,
name|R_386_RELATIVE
init|=
literal|8
block|,
name|R_386_GOTOFF
init|=
literal|9
block|,
name|R_386_GOTPC
init|=
literal|10
block|,
name|R_386_32PLT
init|=
literal|11
block|,
name|R_386_16
init|=
literal|20
block|,
name|R_386_PC16
init|=
literal|21
block|,
name|R_386_8
init|=
literal|22
block|,
name|R_386_PC8
init|=
literal|23
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
name|SHT_INIT_ARRAY
init|=
literal|14
block|,
comment|// Pointers to initialisation functions.
name|SHT_FINI_ARRAY
init|=
literal|15
block|,
comment|// Pointers to termination functions.
name|SHT_PREINIT_ARRAY
init|=
literal|16
block|,
comment|// Pointers to pre-init functions.
name|SHT_GROUP
init|=
literal|17
block|,
comment|// Section group.
name|SHT_SYMTAB_SHNDX
init|=
literal|18
block|,
comment|// Indicies for SHN_XINDEX entries.
name|SHT_LOOS
init|=
literal|0x60000000
block|,
comment|// Lowest operating system-specific type.
name|SHT_HIOS
init|=
literal|0x6fffffff
block|,
comment|// Highest operating system-specific type.
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
comment|// Symbol table entries for ELF32.
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
comment|// Symbol table entries for ELF64.
struct|struct
name|Elf64_Sym
block|{
name|Elf64_Word
name|st_name
decl_stmt|;
comment|// Symbol name (index into string table)
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
name|Elf64_Half
name|st_shndx
decl_stmt|;
comment|// Which section (header table index) it's defined in
name|Elf64_Addr
name|st_value
decl_stmt|;
comment|// Value or address associated with the symbol
name|Elf64_Xword
name|st_size
decl_stmt|;
comment|// Size of the symbol
comment|// These accessors and mutators are identical to those defined for ELF32
comment|// symbol table entries.
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
comment|// The size (in bytes) of symbol table entries.
enum|enum
block|{
name|SYMENTRY_SIZE32
init|=
literal|16
block|,
comment|// 32-bit symbol entry size
name|SYMENTRY_SIZE64
init|=
literal|24
comment|// 64-bit symbol entry size.
block|}
enum|;
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
name|STT_COMMON
init|=
literal|5
block|,
comment|// An uninitialised common block
name|STT_TLS
init|=
literal|6
block|,
comment|// Thread local data object
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
block|}
struct|;
comment|// Relocation entry, without explicit addend.
struct|struct
name|Elf64_Rel
block|{
name|Elf64_Addr
name|r_offset
decl_stmt|;
comment|// Location (file byte offset, or program virtual addr).
name|Elf64_Xword
name|r_info
decl_stmt|;
comment|// Symbol table index and type of relocation to apply.
comment|// These accessors and mutators correspond to the ELF64_R_SYM, ELF64_R_TYPE,
comment|// and ELF64_R_INFO macros defined in the ELF specification:
name|Elf64_Xword
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
operator|(
name|r_info
operator|>>
literal|32
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
literal|0xffffffffL
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
name|Elf64_Xword
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
literal|32
operator|)
operator|+
operator|(
name|t
operator|&
literal|0xffffffffL
operator|)
expr_stmt|;
block|}
block|}
struct|;
comment|// Relocation entry with explicit addend.
struct|struct
name|Elf64_Rela
block|{
name|Elf64_Addr
name|r_offset
decl_stmt|;
comment|// Location (file byte offset, or program virtual addr).
name|Elf64_Xword
name|r_info
decl_stmt|;
comment|// Symbol table index and type of relocation to apply.
name|Elf64_Sxword
name|r_addend
decl_stmt|;
comment|// Compute value for relocatable field by adding this.
comment|// These accessors and mutators correspond to the ELF64_R_SYM, ELF64_R_TYPE,
comment|// and ELF64_R_INFO macros defined in the ELF specification:
name|Elf64_Xword
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
operator|(
name|r_info
operator|>>
literal|32
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
literal|0xffffffffL
argument_list|)
return|;
block|}
name|void
name|setSymbol
parameter_list|(
name|Elf64_Xword
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
name|Elf64_Xword
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
literal|32
operator|)
operator|+
operator|(
name|t
operator|&
literal|0xffffffffL
operator|)
expr_stmt|;
block|}
block|}
struct|;
comment|// Program header for ELF32.
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
comment|// Program header for ELF64.
struct|struct
name|Elf64_Phdr
block|{
name|Elf64_Word
name|p_type
decl_stmt|;
comment|// Type of segment
name|Elf64_Word
name|p_flags
decl_stmt|;
comment|// Segment flags
name|Elf64_Off
name|p_offset
decl_stmt|;
comment|// File offset where segment is located, in bytes
name|Elf64_Addr
name|p_vaddr
decl_stmt|;
comment|// Virtual address of beginning of segment
name|Elf64_Addr
name|p_paddr
decl_stmt|;
comment|// Physical address of beginning of segment (OS-specific)
name|Elf64_Xword
name|p_filesz
decl_stmt|;
comment|// Num. of bytes in file image of segment (may be zero)
name|Elf64_Xword
name|p_memsz
decl_stmt|;
comment|// Num. of bytes in mem image of segment (may be zero)
name|Elf64_Xword
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
comment|// Dynamic table entry for ELF32.
struct|struct
name|Elf32_Dyn
block|{
name|Elf32_Sword
name|d_tag
decl_stmt|;
comment|// Type of dynamic table entry.
union|union
block|{
name|Elf32_Word
name|d_val
decl_stmt|;
comment|// Integer value of entry.
name|Elf32_Addr
name|d_ptr
decl_stmt|;
comment|// Pointer value of entry.
block|}
name|d_un
union|;
block|}
struct|;
comment|// Dynamic table entry for ELF64.
struct|struct
name|Elf64_Dyn
block|{
name|Elf64_Sxword
name|d_tag
decl_stmt|;
comment|// Type of dynamic table entry.
union|union
block|{
name|Elf64_Xword
name|d_val
decl_stmt|;
comment|// Integer value of entry.
name|Elf64_Addr
name|d_ptr
decl_stmt|;
comment|// Pointer value of entry.
block|}
name|d_un
union|;
block|}
struct|;
comment|// Dynamic table entry tags.
enum|enum
block|{
name|DT_NULL
init|=
literal|0
block|,
comment|// Marks end of dynamic array.
name|DT_NEEDED
init|=
literal|1
block|,
comment|// String table offset of needed library.
name|DT_PLTRELSZ
init|=
literal|2
block|,
comment|// Size of relocation entries in PLT.
name|DT_PLTGOT
init|=
literal|3
block|,
comment|// Address associated with linkage table.
name|DT_HASH
init|=
literal|4
block|,
comment|// Address of symbolic hash table.
name|DT_STRTAB
init|=
literal|5
block|,
comment|// Address of dynamic string table.
name|DT_SYMTAB
init|=
literal|6
block|,
comment|// Address of dynamic symbol table.
name|DT_RELA
init|=
literal|7
block|,
comment|// Address of relocation table (Rela entries).
name|DT_RELASZ
init|=
literal|8
block|,
comment|// Size of Rela relocation table.
name|DT_RELAENT
init|=
literal|9
block|,
comment|// Size of a Rela relocation entry.
name|DT_STRSZ
init|=
literal|10
block|,
comment|// Total size of the string table.
name|DT_SYMENT
init|=
literal|11
block|,
comment|// Size of a symbol table entry.
name|DT_INIT
init|=
literal|12
block|,
comment|// Address of initialization function.
name|DT_FINI
init|=
literal|13
block|,
comment|// Address of termination function.
name|DT_SONAME
init|=
literal|14
block|,
comment|// String table offset of a shared objects name.
name|DT_RPATH
init|=
literal|15
block|,
comment|// String table offset of library search path.
name|DT_SYMBOLIC
init|=
literal|16
block|,
comment|// Changes symbol resolution algorithm.
name|DT_REL
init|=
literal|17
block|,
comment|// Address of relocation table (Rel entries).
name|DT_RELSZ
init|=
literal|18
block|,
comment|// Size of Rel relocation table.
name|DT_RELENT
init|=
literal|19
block|,
comment|// Size of a Rel relocation entry.
name|DT_PLTREL
init|=
literal|20
block|,
comment|// Type of relocation entry used for linking.
name|DT_DEBUG
init|=
literal|21
block|,
comment|// Reserved for debugger.
name|DT_TEXTREL
init|=
literal|22
block|,
comment|// Relocations exist for non-writable segements.
name|DT_JMPREL
init|=
literal|23
block|,
comment|// Address of relocations associated with PLT.
name|DT_BIND_NOW
init|=
literal|24
block|,
comment|// Process all relocations before execution.
name|DT_INIT_ARRAY
init|=
literal|25
block|,
comment|// Pointer to array of initialization functions.
name|DT_FINI_ARRAY
init|=
literal|26
block|,
comment|// Pointer to array of termination functions.
name|DT_INIT_ARRAYSZ
init|=
literal|27
block|,
comment|// Size of DT_INIT_ARRAY.
name|DT_FINI_ARRAYSZ
init|=
literal|28
block|,
comment|// Size of DT_FINI_ARRAY.
name|DT_LOOS
init|=
literal|0x60000000
block|,
comment|// Start of environment specific tags.
name|DT_HIOS
init|=
literal|0x6FFFFFFF
block|,
comment|// End of environment specific tags.
name|DT_LOPROC
init|=
literal|0x70000000
block|,
comment|// Start of processor specific tags.
name|DT_HIPROC
init|=
literal|0x7FFFFFFF
comment|// End of processor specific tags.
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

