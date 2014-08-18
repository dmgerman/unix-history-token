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
file|"llvm/Support/Compiler.h"
end_include

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
name|namespace
name|ELF
block|{
typedef|typedef
name|uint32_t
name|Elf32_Addr
typedef|;
comment|// Program address
typedef|typedef
name|uint32_t
name|Elf32_Off
typedef|;
comment|// File offset
typedef|typedef
name|uint16_t
name|Elf32_Half
typedef|;
typedef|typedef
name|uint32_t
name|Elf32_Word
typedef|;
typedef|typedef
name|int32_t
name|Elf32_Sword
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
name|uint16_t
name|Elf64_Half
typedef|;
typedef|typedef
name|uint32_t
name|Elf64_Word
typedef|;
typedef|typedef
name|int32_t
name|Elf64_Sword
typedef|;
typedef|typedef
name|uint64_t
name|Elf64_Xword
typedef|;
typedef|typedef
name|int64_t
name|Elf64_Sxword
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
name|Elf64_Half
name|e_type
decl_stmt|;
name|Elf64_Half
name|e_machine
decl_stmt|;
name|Elf64_Word
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
name|Elf64_Word
name|e_flags
decl_stmt|;
name|Elf64_Half
name|e_ehsize
decl_stmt|;
name|Elf64_Half
name|e_phentsize
decl_stmt|;
name|Elf64_Half
name|e_phnum
decl_stmt|;
name|Elf64_Half
name|e_shentsize
decl_stmt|;
name|Elf64_Half
name|e_shnum
decl_stmt|;
name|Elf64_Half
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
name|EM_S370
init|=
literal|9
block|,
comment|// IBM System/370
name|EM_MIPS_RS3_LE
init|=
literal|10
block|,
comment|// MIPS RS3000 Little-endian
name|EM_PARISC
init|=
literal|15
block|,
comment|// Hewlett-Packard PA-RISC
name|EM_VPP500
init|=
literal|17
block|,
comment|// Fujitsu VPP500
name|EM_SPARC32PLUS
init|=
literal|18
block|,
comment|// Enhanced instruction set SPARC
name|EM_960
init|=
literal|19
block|,
comment|// Intel 80960
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
name|EM_S390
init|=
literal|22
block|,
comment|// IBM System/390
name|EM_SPU
init|=
literal|23
block|,
comment|// IBM SPU/SPC
name|EM_V800
init|=
literal|36
block|,
comment|// NEC V800
name|EM_FR20
init|=
literal|37
block|,
comment|// Fujitsu FR20
name|EM_RH32
init|=
literal|38
block|,
comment|// TRW RH-32
name|EM_RCE
init|=
literal|39
block|,
comment|// Motorola RCE
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
name|EM_SH
init|=
literal|42
block|,
comment|// Hitachi SH
name|EM_SPARCV9
init|=
literal|43
block|,
comment|// SPARC V9
name|EM_TRICORE
init|=
literal|44
block|,
comment|// Siemens TriCore
name|EM_ARC
init|=
literal|45
block|,
comment|// Argonaut RISC Core
name|EM_H8_300
init|=
literal|46
block|,
comment|// Hitachi H8/300
name|EM_H8_300H
init|=
literal|47
block|,
comment|// Hitachi H8/300H
name|EM_H8S
init|=
literal|48
block|,
comment|// Hitachi H8S
name|EM_H8_500
init|=
literal|49
block|,
comment|// Hitachi H8/500
name|EM_IA_64
init|=
literal|50
block|,
comment|// Intel IA-64 processor architecture
name|EM_MIPS_X
init|=
literal|51
block|,
comment|// Stanford MIPS-X
name|EM_COLDFIRE
init|=
literal|52
block|,
comment|// Motorola ColdFire
name|EM_68HC12
init|=
literal|53
block|,
comment|// Motorola M68HC12
name|EM_MMA
init|=
literal|54
block|,
comment|// Fujitsu MMA Multimedia Accelerator
name|EM_PCP
init|=
literal|55
block|,
comment|// Siemens PCP
name|EM_NCPU
init|=
literal|56
block|,
comment|// Sony nCPU embedded RISC processor
name|EM_NDR1
init|=
literal|57
block|,
comment|// Denso NDR1 microprocessor
name|EM_STARCORE
init|=
literal|58
block|,
comment|// Motorola Star*Core processor
name|EM_ME16
init|=
literal|59
block|,
comment|// Toyota ME16 processor
name|EM_ST100
init|=
literal|60
block|,
comment|// STMicroelectronics ST100 processor
name|EM_TINYJ
init|=
literal|61
block|,
comment|// Advanced Logic Corp. TinyJ embedded processor family
name|EM_X86_64
init|=
literal|62
block|,
comment|// AMD x86-64 architecture
name|EM_PDSP
init|=
literal|63
block|,
comment|// Sony DSP Processor
name|EM_PDP10
init|=
literal|64
block|,
comment|// Digital Equipment Corp. PDP-10
name|EM_PDP11
init|=
literal|65
block|,
comment|// Digital Equipment Corp. PDP-11
name|EM_FX66
init|=
literal|66
block|,
comment|// Siemens FX66 microcontroller
name|EM_ST9PLUS
init|=
literal|67
block|,
comment|// STMicroelectronics ST9+ 8/16 bit microcontroller
name|EM_ST7
init|=
literal|68
block|,
comment|// STMicroelectronics ST7 8-bit microcontroller
name|EM_68HC16
init|=
literal|69
block|,
comment|// Motorola MC68HC16 Microcontroller
name|EM_68HC11
init|=
literal|70
block|,
comment|// Motorola MC68HC11 Microcontroller
name|EM_68HC08
init|=
literal|71
block|,
comment|// Motorola MC68HC08 Microcontroller
name|EM_68HC05
init|=
literal|72
block|,
comment|// Motorola MC68HC05 Microcontroller
name|EM_SVX
init|=
literal|73
block|,
comment|// Silicon Graphics SVx
name|EM_ST19
init|=
literal|74
block|,
comment|// STMicroelectronics ST19 8-bit microcontroller
name|EM_VAX
init|=
literal|75
block|,
comment|// Digital VAX
name|EM_CRIS
init|=
literal|76
block|,
comment|// Axis Communications 32-bit embedded processor
name|EM_JAVELIN
init|=
literal|77
block|,
comment|// Infineon Technologies 32-bit embedded processor
name|EM_FIREPATH
init|=
literal|78
block|,
comment|// Element 14 64-bit DSP Processor
name|EM_ZSP
init|=
literal|79
block|,
comment|// LSI Logic 16-bit DSP Processor
name|EM_MMIX
init|=
literal|80
block|,
comment|// Donald Knuth's educational 64-bit processor
name|EM_HUANY
init|=
literal|81
block|,
comment|// Harvard University machine-independent object files
name|EM_PRISM
init|=
literal|82
block|,
comment|// SiTera Prism
name|EM_AVR
init|=
literal|83
block|,
comment|// Atmel AVR 8-bit microcontroller
name|EM_FR30
init|=
literal|84
block|,
comment|// Fujitsu FR30
name|EM_D10V
init|=
literal|85
block|,
comment|// Mitsubishi D10V
name|EM_D30V
init|=
literal|86
block|,
comment|// Mitsubishi D30V
name|EM_V850
init|=
literal|87
block|,
comment|// NEC v850
name|EM_M32R
init|=
literal|88
block|,
comment|// Mitsubishi M32R
name|EM_MN10300
init|=
literal|89
block|,
comment|// Matsushita MN10300
name|EM_MN10200
init|=
literal|90
block|,
comment|// Matsushita MN10200
name|EM_PJ
init|=
literal|91
block|,
comment|// picoJava
name|EM_OPENRISC
init|=
literal|92
block|,
comment|// OpenRISC 32-bit embedded processor
name|EM_ARC_COMPACT
init|=
literal|93
block|,
comment|// ARC International ARCompact processor (old
comment|// spelling/synonym: EM_ARC_A5)
name|EM_XTENSA
init|=
literal|94
block|,
comment|// Tensilica Xtensa Architecture
name|EM_VIDEOCORE
init|=
literal|95
block|,
comment|// Alphamosaic VideoCore processor
name|EM_TMM_GPP
init|=
literal|96
block|,
comment|// Thompson Multimedia General Purpose Processor
name|EM_NS32K
init|=
literal|97
block|,
comment|// National Semiconductor 32000 series
name|EM_TPC
init|=
literal|98
block|,
comment|// Tenor Network TPC processor
name|EM_SNP1K
init|=
literal|99
block|,
comment|// Trebia SNP 1000 processor
name|EM_ST200
init|=
literal|100
block|,
comment|// STMicroelectronics (www.st.com) ST200
name|EM_IP2K
init|=
literal|101
block|,
comment|// Ubicom IP2xxx microcontroller family
name|EM_MAX
init|=
literal|102
block|,
comment|// MAX Processor
name|EM_CR
init|=
literal|103
block|,
comment|// National Semiconductor CompactRISC microprocessor
name|EM_F2MC16
init|=
literal|104
block|,
comment|// Fujitsu F2MC16
name|EM_MSP430
init|=
literal|105
block|,
comment|// Texas Instruments embedded microcontroller msp430
name|EM_BLACKFIN
init|=
literal|106
block|,
comment|// Analog Devices Blackfin (DSP) processor
name|EM_SE_C33
init|=
literal|107
block|,
comment|// S1C33 Family of Seiko Epson processors
name|EM_SEP
init|=
literal|108
block|,
comment|// Sharp embedded microprocessor
name|EM_ARCA
init|=
literal|109
block|,
comment|// Arca RISC Microprocessor
name|EM_UNICORE
init|=
literal|110
block|,
comment|// Microprocessor series from PKU-Unity Ltd. and MPRC
comment|// of Peking University
name|EM_EXCESS
init|=
literal|111
block|,
comment|// eXcess: 16/32/64-bit configurable embedded CPU
name|EM_DXP
init|=
literal|112
block|,
comment|// Icera Semiconductor Inc. Deep Execution Processor
name|EM_ALTERA_NIOS2
init|=
literal|113
block|,
comment|// Altera Nios II soft-core processor
name|EM_CRX
init|=
literal|114
block|,
comment|// National Semiconductor CompactRISC CRX
name|EM_XGATE
init|=
literal|115
block|,
comment|// Motorola XGATE embedded processor
name|EM_C166
init|=
literal|116
block|,
comment|// Infineon C16x/XC16x processor
name|EM_M16C
init|=
literal|117
block|,
comment|// Renesas M16C series microprocessors
name|EM_DSPIC30F
init|=
literal|118
block|,
comment|// Microchip Technology dsPIC30F Digital Signal
comment|// Controller
name|EM_CE
init|=
literal|119
block|,
comment|// Freescale Communication Engine RISC core
name|EM_M32C
init|=
literal|120
block|,
comment|// Renesas M32C series microprocessors
name|EM_TSK3000
init|=
literal|131
block|,
comment|// Altium TSK3000 core
name|EM_RS08
init|=
literal|132
block|,
comment|// Freescale RS08 embedded processor
name|EM_SHARC
init|=
literal|133
block|,
comment|// Analog Devices SHARC family of 32-bit DSP
comment|// processors
name|EM_ECOG2
init|=
literal|134
block|,
comment|// Cyan Technology eCOG2 microprocessor
name|EM_SCORE7
init|=
literal|135
block|,
comment|// Sunplus S+core7 RISC processor
name|EM_DSP24
init|=
literal|136
block|,
comment|// New Japan Radio (NJR) 24-bit DSP Processor
name|EM_VIDEOCORE3
init|=
literal|137
block|,
comment|// Broadcom VideoCore III processor
name|EM_LATTICEMICO32
init|=
literal|138
block|,
comment|// RISC processor for Lattice FPGA architecture
name|EM_SE_C17
init|=
literal|139
block|,
comment|// Seiko Epson C17 family
name|EM_TI_C6000
init|=
literal|140
block|,
comment|// The Texas Instruments TMS320C6000 DSP family
name|EM_TI_C2000
init|=
literal|141
block|,
comment|// The Texas Instruments TMS320C2000 DSP family
name|EM_TI_C5500
init|=
literal|142
block|,
comment|// The Texas Instruments TMS320C55x DSP family
name|EM_MMDSP_PLUS
init|=
literal|160
block|,
comment|// STMicroelectronics 64bit VLIW Data Signal Processor
name|EM_CYPRESS_M8C
init|=
literal|161
block|,
comment|// Cypress M8C microprocessor
name|EM_R32C
init|=
literal|162
block|,
comment|// Renesas R32C series microprocessors
name|EM_TRIMEDIA
init|=
literal|163
block|,
comment|// NXP Semiconductors TriMedia architecture family
name|EM_HEXAGON
init|=
literal|164
block|,
comment|// Qualcomm Hexagon processor
name|EM_8051
init|=
literal|165
block|,
comment|// Intel 8051 and variants
name|EM_STXP7X
init|=
literal|166
block|,
comment|// STMicroelectronics STxP7x family of configurable
comment|// and extensible RISC processors
name|EM_NDS32
init|=
literal|167
block|,
comment|// Andes Technology compact code size embedded RISC
comment|// processor family
name|EM_ECOG1
init|=
literal|168
block|,
comment|// Cyan Technology eCOG1X family
name|EM_ECOG1X
init|=
literal|168
block|,
comment|// Cyan Technology eCOG1X family
name|EM_MAXQ30
init|=
literal|169
block|,
comment|// Dallas Semiconductor MAXQ30 Core Micro-controllers
name|EM_XIMO16
init|=
literal|170
block|,
comment|// New Japan Radio (NJR) 16-bit DSP Processor
name|EM_MANIK
init|=
literal|171
block|,
comment|// M2000 Reconfigurable RISC Microprocessor
name|EM_CRAYNV2
init|=
literal|172
block|,
comment|// Cray Inc. NV2 vector architecture
name|EM_RX
init|=
literal|173
block|,
comment|// Renesas RX family
name|EM_METAG
init|=
literal|174
block|,
comment|// Imagination Technologies META processor
comment|// architecture
name|EM_MCST_ELBRUS
init|=
literal|175
block|,
comment|// MCST Elbrus general purpose hardware architecture
name|EM_ECOG16
init|=
literal|176
block|,
comment|// Cyan Technology eCOG16 family
name|EM_CR16
init|=
literal|177
block|,
comment|// National Semiconductor CompactRISC CR16 16-bit
comment|// microprocessor
name|EM_ETPU
init|=
literal|178
block|,
comment|// Freescale Extended Time Processing Unit
name|EM_SLE9X
init|=
literal|179
block|,
comment|// Infineon Technologies SLE9X core
name|EM_L10M
init|=
literal|180
block|,
comment|// Intel L10M
name|EM_K10M
init|=
literal|181
block|,
comment|// Intel K10M
name|EM_AARCH64
init|=
literal|183
block|,
comment|// ARM AArch64
name|EM_AVR32
init|=
literal|185
block|,
comment|// Atmel Corporation 32-bit microprocessor family
name|EM_STM8
init|=
literal|186
block|,
comment|// STMicroeletronics STM8 8-bit microcontroller
name|EM_TILE64
init|=
literal|187
block|,
comment|// Tilera TILE64 multicore architecture family
name|EM_TILEPRO
init|=
literal|188
block|,
comment|// Tilera TILEPro multicore architecture family
name|EM_CUDA
init|=
literal|190
block|,
comment|// NVIDIA CUDA architecture
name|EM_TILEGX
init|=
literal|191
block|,
comment|// Tilera TILE-Gx multicore architecture family
name|EM_CLOUDSHIELD
init|=
literal|192
block|,
comment|// CloudShield architecture family
name|EM_COREA_1ST
init|=
literal|193
block|,
comment|// KIPO-KAIST Core-A 1st generation processor family
name|EM_COREA_2ND
init|=
literal|194
block|,
comment|// KIPO-KAIST Core-A 2nd generation processor family
name|EM_ARC_COMPACT2
init|=
literal|195
block|,
comment|// Synopsys ARCompact V2
name|EM_OPEN8
init|=
literal|196
block|,
comment|// Open8 8-bit RISC soft processor core
name|EM_RL78
init|=
literal|197
block|,
comment|// Renesas RL78 family
name|EM_VIDEOCORE5
init|=
literal|198
block|,
comment|// Broadcom VideoCore V processor
name|EM_78KOR
init|=
literal|199
block|,
comment|// Renesas 78KOR family
name|EM_56800EX
init|=
literal|200
comment|// Freescale 56800EX Digital Signal Controller (DSC)
block|}
enum|;
comment|// Object file classes.
enum|enum
block|{
name|ELFCLASSNONE
init|=
literal|0
block|,
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
name|ELFOSABI_GNU
init|=
literal|3
block|,
comment|// GNU/Linux
name|ELFOSABI_LINUX
init|=
literal|3
block|,
comment|// Historical alias for ELFOSABI_GNU.
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
name|R_X86_64_GOT64
init|=
literal|27
block|,
name|R_X86_64_GOTPCREL64
init|=
literal|28
block|,
name|R_X86_64_GOTPC64
init|=
literal|29
block|,
name|R_X86_64_GOTPLT64
init|=
literal|30
block|,
name|R_X86_64_PLTOFF64
init|=
literal|31
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
block|,
name|R_X86_64_IRELATIVE
init|=
literal|37
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
name|R_386_TLS_TPOFF
init|=
literal|14
block|,
name|R_386_TLS_IE
init|=
literal|15
block|,
name|R_386_TLS_GOTIE
init|=
literal|16
block|,
name|R_386_TLS_LE
init|=
literal|17
block|,
name|R_386_TLS_GD
init|=
literal|18
block|,
name|R_386_TLS_LDM
init|=
literal|19
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
block|,
name|R_386_TLS_GD_32
init|=
literal|24
block|,
name|R_386_TLS_GD_PUSH
init|=
literal|25
block|,
name|R_386_TLS_GD_CALL
init|=
literal|26
block|,
name|R_386_TLS_GD_POP
init|=
literal|27
block|,
name|R_386_TLS_LDM_32
init|=
literal|28
block|,
name|R_386_TLS_LDM_PUSH
init|=
literal|29
block|,
name|R_386_TLS_LDM_CALL
init|=
literal|30
block|,
name|R_386_TLS_LDM_POP
init|=
literal|31
block|,
name|R_386_TLS_LDO_32
init|=
literal|32
block|,
name|R_386_TLS_IE_32
init|=
literal|33
block|,
name|R_386_TLS_LE_32
init|=
literal|34
block|,
name|R_386_TLS_DTPMOD32
init|=
literal|35
block|,
name|R_386_TLS_DTPOFF32
init|=
literal|36
block|,
name|R_386_TLS_TPOFF32
init|=
literal|37
block|,
name|R_386_TLS_GOTDESC
init|=
literal|39
block|,
name|R_386_TLS_DESC_CALL
init|=
literal|40
block|,
name|R_386_TLS_DESC
init|=
literal|41
block|,
name|R_386_IRELATIVE
init|=
literal|42
block|,
name|R_386_NUM
init|=
literal|43
block|}
enum|;
comment|// ELF Relocation types for PPC32
enum|enum
block|{
name|R_PPC_NONE
init|=
literal|0
block|,
comment|/* No relocation. */
name|R_PPC_ADDR32
init|=
literal|1
block|,
name|R_PPC_ADDR24
init|=
literal|2
block|,
name|R_PPC_ADDR16
init|=
literal|3
block|,
name|R_PPC_ADDR16_LO
init|=
literal|4
block|,
name|R_PPC_ADDR16_HI
init|=
literal|5
block|,
name|R_PPC_ADDR16_HA
init|=
literal|6
block|,
name|R_PPC_ADDR14
init|=
literal|7
block|,
name|R_PPC_ADDR14_BRTAKEN
init|=
literal|8
block|,
name|R_PPC_ADDR14_BRNTAKEN
init|=
literal|9
block|,
name|R_PPC_REL24
init|=
literal|10
block|,
name|R_PPC_REL14
init|=
literal|11
block|,
name|R_PPC_REL14_BRTAKEN
init|=
literal|12
block|,
name|R_PPC_REL14_BRNTAKEN
init|=
literal|13
block|,
name|R_PPC_GOT16
init|=
literal|14
block|,
name|R_PPC_GOT16_LO
init|=
literal|15
block|,
name|R_PPC_GOT16_HI
init|=
literal|16
block|,
name|R_PPC_GOT16_HA
init|=
literal|17
block|,
name|R_PPC_PLTREL24
init|=
literal|18
block|,
name|R_PPC_REL32
init|=
literal|26
block|,
name|R_PPC_TLS
init|=
literal|67
block|,
name|R_PPC_DTPMOD32
init|=
literal|68
block|,
name|R_PPC_TPREL16
init|=
literal|69
block|,
name|R_PPC_TPREL16_LO
init|=
literal|70
block|,
name|R_PPC_TPREL16_HI
init|=
literal|71
block|,
name|R_PPC_TPREL16_HA
init|=
literal|72
block|,
name|R_PPC_TPREL32
init|=
literal|73
block|,
name|R_PPC_DTPREL16
init|=
literal|74
block|,
name|R_PPC_DTPREL16_LO
init|=
literal|75
block|,
name|R_PPC_DTPREL16_HI
init|=
literal|76
block|,
name|R_PPC_DTPREL16_HA
init|=
literal|77
block|,
name|R_PPC_DTPREL32
init|=
literal|78
block|,
name|R_PPC_GOT_TLSGD16
init|=
literal|79
block|,
name|R_PPC_GOT_TLSGD16_LO
init|=
literal|80
block|,
name|R_PPC_GOT_TLSGD16_HI
init|=
literal|81
block|,
name|R_PPC_GOT_TLSGD16_HA
init|=
literal|82
block|,
name|R_PPC_GOT_TLSLD16
init|=
literal|83
block|,
name|R_PPC_GOT_TLSLD16_LO
init|=
literal|84
block|,
name|R_PPC_GOT_TLSLD16_HI
init|=
literal|85
block|,
name|R_PPC_GOT_TLSLD16_HA
init|=
literal|86
block|,
name|R_PPC_GOT_TPREL16
init|=
literal|87
block|,
name|R_PPC_GOT_TPREL16_LO
init|=
literal|88
block|,
name|R_PPC_GOT_TPREL16_HI
init|=
literal|89
block|,
name|R_PPC_GOT_TPREL16_HA
init|=
literal|90
block|,
name|R_PPC_GOT_DTPREL16
init|=
literal|91
block|,
name|R_PPC_GOT_DTPREL16_LO
init|=
literal|92
block|,
name|R_PPC_GOT_DTPREL16_HI
init|=
literal|93
block|,
name|R_PPC_GOT_DTPREL16_HA
init|=
literal|94
block|,
name|R_PPC_TLSGD
init|=
literal|95
block|,
name|R_PPC_TLSLD
init|=
literal|96
block|,
name|R_PPC_REL16
init|=
literal|249
block|,
name|R_PPC_REL16_LO
init|=
literal|250
block|,
name|R_PPC_REL16_HI
init|=
literal|251
block|,
name|R_PPC_REL16_HA
init|=
literal|252
block|}
enum|;
comment|// ELF Relocation types for PPC64
enum|enum
block|{
name|R_PPC64_NONE
init|=
literal|0
block|,
name|R_PPC64_ADDR32
init|=
literal|1
block|,
name|R_PPC64_ADDR24
init|=
literal|2
block|,
name|R_PPC64_ADDR16
init|=
literal|3
block|,
name|R_PPC64_ADDR16_LO
init|=
literal|4
block|,
name|R_PPC64_ADDR16_HI
init|=
literal|5
block|,
name|R_PPC64_ADDR16_HA
init|=
literal|6
block|,
name|R_PPC64_ADDR14
init|=
literal|7
block|,
name|R_PPC64_ADDR14_BRTAKEN
init|=
literal|8
block|,
name|R_PPC64_ADDR14_BRNTAKEN
init|=
literal|9
block|,
name|R_PPC64_REL24
init|=
literal|10
block|,
name|R_PPC64_REL14
init|=
literal|11
block|,
name|R_PPC64_REL14_BRTAKEN
init|=
literal|12
block|,
name|R_PPC64_REL14_BRNTAKEN
init|=
literal|13
block|,
name|R_PPC64_GOT16
init|=
literal|14
block|,
name|R_PPC64_GOT16_LO
init|=
literal|15
block|,
name|R_PPC64_GOT16_HI
init|=
literal|16
block|,
name|R_PPC64_GOT16_HA
init|=
literal|17
block|,
name|R_PPC64_REL32
init|=
literal|26
block|,
name|R_PPC64_ADDR64
init|=
literal|38
block|,
name|R_PPC64_ADDR16_HIGHER
init|=
literal|39
block|,
name|R_PPC64_ADDR16_HIGHERA
init|=
literal|40
block|,
name|R_PPC64_ADDR16_HIGHEST
init|=
literal|41
block|,
name|R_PPC64_ADDR16_HIGHESTA
init|=
literal|42
block|,
name|R_PPC64_REL64
init|=
literal|44
block|,
name|R_PPC64_TOC16
init|=
literal|47
block|,
name|R_PPC64_TOC16_LO
init|=
literal|48
block|,
name|R_PPC64_TOC16_HI
init|=
literal|49
block|,
name|R_PPC64_TOC16_HA
init|=
literal|50
block|,
name|R_PPC64_TOC
init|=
literal|51
block|,
name|R_PPC64_ADDR16_DS
init|=
literal|56
block|,
name|R_PPC64_ADDR16_LO_DS
init|=
literal|57
block|,
name|R_PPC64_GOT16_DS
init|=
literal|58
block|,
name|R_PPC64_GOT16_LO_DS
init|=
literal|59
block|,
name|R_PPC64_TOC16_DS
init|=
literal|63
block|,
name|R_PPC64_TOC16_LO_DS
init|=
literal|64
block|,
name|R_PPC64_TLS
init|=
literal|67
block|,
name|R_PPC64_DTPMOD64
init|=
literal|68
block|,
name|R_PPC64_TPREL16
init|=
literal|69
block|,
name|R_PPC64_TPREL16_LO
init|=
literal|70
block|,
name|R_PPC64_TPREL16_HI
init|=
literal|71
block|,
name|R_PPC64_TPREL16_HA
init|=
literal|72
block|,
name|R_PPC64_TPREL64
init|=
literal|73
block|,
name|R_PPC64_DTPREL16
init|=
literal|74
block|,
name|R_PPC64_DTPREL16_LO
init|=
literal|75
block|,
name|R_PPC64_DTPREL16_HI
init|=
literal|76
block|,
name|R_PPC64_DTPREL16_HA
init|=
literal|77
block|,
name|R_PPC64_DTPREL64
init|=
literal|78
block|,
name|R_PPC64_GOT_TLSGD16
init|=
literal|79
block|,
name|R_PPC64_GOT_TLSGD16_LO
init|=
literal|80
block|,
name|R_PPC64_GOT_TLSGD16_HI
init|=
literal|81
block|,
name|R_PPC64_GOT_TLSGD16_HA
init|=
literal|82
block|,
name|R_PPC64_GOT_TLSLD16
init|=
literal|83
block|,
name|R_PPC64_GOT_TLSLD16_LO
init|=
literal|84
block|,
name|R_PPC64_GOT_TLSLD16_HI
init|=
literal|85
block|,
name|R_PPC64_GOT_TLSLD16_HA
init|=
literal|86
block|,
name|R_PPC64_GOT_TPREL16_DS
init|=
literal|87
block|,
name|R_PPC64_GOT_TPREL16_LO_DS
init|=
literal|88
block|,
name|R_PPC64_GOT_TPREL16_HI
init|=
literal|89
block|,
name|R_PPC64_GOT_TPREL16_HA
init|=
literal|90
block|,
name|R_PPC64_GOT_DTPREL16_DS
init|=
literal|91
block|,
name|R_PPC64_GOT_DTPREL16_LO_DS
init|=
literal|92
block|,
name|R_PPC64_GOT_DTPREL16_HI
init|=
literal|93
block|,
name|R_PPC64_GOT_DTPREL16_HA
init|=
literal|94
block|,
name|R_PPC64_TPREL16_DS
init|=
literal|95
block|,
name|R_PPC64_TPREL16_LO_DS
init|=
literal|96
block|,
name|R_PPC64_TPREL16_HIGHER
init|=
literal|97
block|,
name|R_PPC64_TPREL16_HIGHERA
init|=
literal|98
block|,
name|R_PPC64_TPREL16_HIGHEST
init|=
literal|99
block|,
name|R_PPC64_TPREL16_HIGHESTA
init|=
literal|100
block|,
name|R_PPC64_DTPREL16_DS
init|=
literal|101
block|,
name|R_PPC64_DTPREL16_LO_DS
init|=
literal|102
block|,
name|R_PPC64_DTPREL16_HIGHER
init|=
literal|103
block|,
name|R_PPC64_DTPREL16_HIGHERA
init|=
literal|104
block|,
name|R_PPC64_DTPREL16_HIGHEST
init|=
literal|105
block|,
name|R_PPC64_DTPREL16_HIGHESTA
init|=
literal|106
block|,
name|R_PPC64_TLSGD
init|=
literal|107
block|,
name|R_PPC64_TLSLD
init|=
literal|108
block|,
name|R_PPC64_REL16
init|=
literal|249
block|,
name|R_PPC64_REL16_LO
init|=
literal|250
block|,
name|R_PPC64_REL16_HI
init|=
literal|251
block|,
name|R_PPC64_REL16_HA
init|=
literal|252
block|}
enum|;
comment|// ELF Relocation types for AArch64
enum|enum
block|{
name|R_AARCH64_NONE
init|=
literal|0x100
block|,
name|R_AARCH64_ABS64
init|=
literal|0x101
block|,
name|R_AARCH64_ABS32
init|=
literal|0x102
block|,
name|R_AARCH64_ABS16
init|=
literal|0x103
block|,
name|R_AARCH64_PREL64
init|=
literal|0x104
block|,
name|R_AARCH64_PREL32
init|=
literal|0x105
block|,
name|R_AARCH64_PREL16
init|=
literal|0x106
block|,
name|R_AARCH64_MOVW_UABS_G0
init|=
literal|0x107
block|,
name|R_AARCH64_MOVW_UABS_G0_NC
init|=
literal|0x108
block|,
name|R_AARCH64_MOVW_UABS_G1
init|=
literal|0x109
block|,
name|R_AARCH64_MOVW_UABS_G1_NC
init|=
literal|0x10a
block|,
name|R_AARCH64_MOVW_UABS_G2
init|=
literal|0x10b
block|,
name|R_AARCH64_MOVW_UABS_G2_NC
init|=
literal|0x10c
block|,
name|R_AARCH64_MOVW_UABS_G3
init|=
literal|0x10d
block|,
name|R_AARCH64_MOVW_SABS_G0
init|=
literal|0x10e
block|,
name|R_AARCH64_MOVW_SABS_G1
init|=
literal|0x10f
block|,
name|R_AARCH64_MOVW_SABS_G2
init|=
literal|0x110
block|,
name|R_AARCH64_LD_PREL_LO19
init|=
literal|0x111
block|,
name|R_AARCH64_ADR_PREL_LO21
init|=
literal|0x112
block|,
name|R_AARCH64_ADR_PREL_PG_HI21
init|=
literal|0x113
block|,
name|R_AARCH64_ADD_ABS_LO12_NC
init|=
literal|0x115
block|,
name|R_AARCH64_LDST8_ABS_LO12_NC
init|=
literal|0x116
block|,
name|R_AARCH64_TSTBR14
init|=
literal|0x117
block|,
name|R_AARCH64_CONDBR19
init|=
literal|0x118
block|,
name|R_AARCH64_JUMP26
init|=
literal|0x11a
block|,
name|R_AARCH64_CALL26
init|=
literal|0x11b
block|,
name|R_AARCH64_LDST16_ABS_LO12_NC
init|=
literal|0x11c
block|,
name|R_AARCH64_LDST32_ABS_LO12_NC
init|=
literal|0x11d
block|,
name|R_AARCH64_LDST64_ABS_LO12_NC
init|=
literal|0x11e
block|,
name|R_AARCH64_LDST128_ABS_LO12_NC
init|=
literal|0x12b
block|,
name|R_AARCH64_ADR_GOT_PAGE
init|=
literal|0x137
block|,
name|R_AARCH64_LD64_GOT_LO12_NC
init|=
literal|0x138
block|,
name|R_AARCH64_TLSLD_MOVW_DTPREL_G2
init|=
literal|0x20b
block|,
name|R_AARCH64_TLSLD_MOVW_DTPREL_G1
init|=
literal|0x20c
block|,
name|R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC
init|=
literal|0x20d
block|,
name|R_AARCH64_TLSLD_MOVW_DTPREL_G0
init|=
literal|0x20e
block|,
name|R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC
init|=
literal|0x20f
block|,
name|R_AARCH64_TLSLD_ADD_DTPREL_HI12
init|=
literal|0x210
block|,
name|R_AARCH64_TLSLD_ADD_DTPREL_LO12
init|=
literal|0x211
block|,
name|R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC
init|=
literal|0x212
block|,
name|R_AARCH64_TLSLD_LDST8_DTPREL_LO12
init|=
literal|0x213
block|,
name|R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC
init|=
literal|0x214
block|,
name|R_AARCH64_TLSLD_LDST16_DTPREL_LO12
init|=
literal|0x215
block|,
name|R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC
init|=
literal|0x216
block|,
name|R_AARCH64_TLSLD_LDST32_DTPREL_LO12
init|=
literal|0x217
block|,
name|R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC
init|=
literal|0x218
block|,
name|R_AARCH64_TLSLD_LDST64_DTPREL_LO12
init|=
literal|0x219
block|,
name|R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC
init|=
literal|0x21a
block|,
name|R_AARCH64_TLSIE_MOVW_GOTTPREL_G1
init|=
literal|0x21b
block|,
name|R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC
init|=
literal|0x21c
block|,
name|R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21
init|=
literal|0x21d
block|,
name|R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC
init|=
literal|0x21e
block|,
name|R_AARCH64_TLSIE_LD_GOTTPREL_PREL19
init|=
literal|0x21f
block|,
name|R_AARCH64_TLSLE_MOVW_TPREL_G2
init|=
literal|0x220
block|,
name|R_AARCH64_TLSLE_MOVW_TPREL_G1
init|=
literal|0x221
block|,
name|R_AARCH64_TLSLE_MOVW_TPREL_G1_NC
init|=
literal|0x222
block|,
name|R_AARCH64_TLSLE_MOVW_TPREL_G0
init|=
literal|0x223
block|,
name|R_AARCH64_TLSLE_MOVW_TPREL_G0_NC
init|=
literal|0x224
block|,
name|R_AARCH64_TLSLE_ADD_TPREL_HI12
init|=
literal|0x225
block|,
name|R_AARCH64_TLSLE_ADD_TPREL_LO12
init|=
literal|0x226
block|,
name|R_AARCH64_TLSLE_ADD_TPREL_LO12_NC
init|=
literal|0x227
block|,
name|R_AARCH64_TLSLE_LDST8_TPREL_LO12
init|=
literal|0x228
block|,
name|R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC
init|=
literal|0x229
block|,
name|R_AARCH64_TLSLE_LDST16_TPREL_LO12
init|=
literal|0x22a
block|,
name|R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC
init|=
literal|0x22b
block|,
name|R_AARCH64_TLSLE_LDST32_TPREL_LO12
init|=
literal|0x22c
block|,
name|R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC
init|=
literal|0x22d
block|,
name|R_AARCH64_TLSLE_LDST64_TPREL_LO12
init|=
literal|0x22e
block|,
name|R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC
init|=
literal|0x22f
block|,
name|R_AARCH64_TLSDESC_ADR_PAGE
init|=
literal|0x232
block|,
name|R_AARCH64_TLSDESC_LD64_LO12_NC
init|=
literal|0x233
block|,
name|R_AARCH64_TLSDESC_ADD_LO12_NC
init|=
literal|0x234
block|,
name|R_AARCH64_TLSDESC_CALL
init|=
literal|0x239
block|}
enum|;
comment|// ARM Specific e_flags
name|enum
name|LLVM_ENUM_INT_TYPE
function|(
name|unsigned
function|)
block|{
name|EF_ARM_SOFT_FLOAT
operator|=
literal|0x00000200U
operator|,
name|EF_ARM_VFP_FLOAT
operator|=
literal|0x00000400U
operator|,
name|EF_ARM_EABI_UNKNOWN
operator|=
literal|0x00000000U
operator|,
name|EF_ARM_EABI_VER1
operator|=
literal|0x01000000U
operator|,
name|EF_ARM_EABI_VER2
operator|=
literal|0x02000000U
operator|,
name|EF_ARM_EABI_VER3
operator|=
literal|0x03000000U
operator|,
name|EF_ARM_EABI_VER4
operator|=
literal|0x04000000U
operator|,
name|EF_ARM_EABI_VER5
operator|=
literal|0x05000000U
operator|,
name|EF_ARM_EABIMASK
operator|=
literal|0xFF000000U
block|}
empty_stmt|;
comment|// ELF Relocation types for ARM
comment|// Meets 2.08 ABI Specs.
enum|enum
block|{
name|R_ARM_NONE
init|=
literal|0x00
block|,
name|R_ARM_PC24
init|=
literal|0x01
block|,
name|R_ARM_ABS32
init|=
literal|0x02
block|,
name|R_ARM_REL32
init|=
literal|0x03
block|,
name|R_ARM_LDR_PC_G0
init|=
literal|0x04
block|,
name|R_ARM_ABS16
init|=
literal|0x05
block|,
name|R_ARM_ABS12
init|=
literal|0x06
block|,
name|R_ARM_THM_ABS5
init|=
literal|0x07
block|,
name|R_ARM_ABS8
init|=
literal|0x08
block|,
name|R_ARM_SBREL32
init|=
literal|0x09
block|,
name|R_ARM_THM_CALL
init|=
literal|0x0a
block|,
name|R_ARM_THM_PC8
init|=
literal|0x0b
block|,
name|R_ARM_BREL_ADJ
init|=
literal|0x0c
block|,
name|R_ARM_TLS_DESC
init|=
literal|0x0d
block|,
name|R_ARM_THM_SWI8
init|=
literal|0x0e
block|,
name|R_ARM_XPC25
init|=
literal|0x0f
block|,
name|R_ARM_THM_XPC22
init|=
literal|0x10
block|,
name|R_ARM_TLS_DTPMOD32
init|=
literal|0x11
block|,
name|R_ARM_TLS_DTPOFF32
init|=
literal|0x12
block|,
name|R_ARM_TLS_TPOFF32
init|=
literal|0x13
block|,
name|R_ARM_COPY
init|=
literal|0x14
block|,
name|R_ARM_GLOB_DAT
init|=
literal|0x15
block|,
name|R_ARM_JUMP_SLOT
init|=
literal|0x16
block|,
name|R_ARM_RELATIVE
init|=
literal|0x17
block|,
name|R_ARM_GOTOFF32
init|=
literal|0x18
block|,
name|R_ARM_BASE_PREL
init|=
literal|0x19
block|,
name|R_ARM_GOT_BREL
init|=
literal|0x1a
block|,
name|R_ARM_PLT32
init|=
literal|0x1b
block|,
name|R_ARM_CALL
init|=
literal|0x1c
block|,
name|R_ARM_JUMP24
init|=
literal|0x1d
block|,
name|R_ARM_THM_JUMP24
init|=
literal|0x1e
block|,
name|R_ARM_BASE_ABS
init|=
literal|0x1f
block|,
name|R_ARM_ALU_PCREL_7_0
init|=
literal|0x20
block|,
name|R_ARM_ALU_PCREL_15_8
init|=
literal|0x21
block|,
name|R_ARM_ALU_PCREL_23_15
init|=
literal|0x22
block|,
name|R_ARM_LDR_SBREL_11_0_NC
init|=
literal|0x23
block|,
name|R_ARM_ALU_SBREL_19_12_NC
init|=
literal|0x24
block|,
name|R_ARM_ALU_SBREL_27_20_CK
init|=
literal|0x25
block|,
name|R_ARM_TARGET1
init|=
literal|0x26
block|,
name|R_ARM_SBREL31
init|=
literal|0x27
block|,
name|R_ARM_V4BX
init|=
literal|0x28
block|,
name|R_ARM_TARGET2
init|=
literal|0x29
block|,
name|R_ARM_PREL31
init|=
literal|0x2a
block|,
name|R_ARM_MOVW_ABS_NC
init|=
literal|0x2b
block|,
name|R_ARM_MOVT_ABS
init|=
literal|0x2c
block|,
name|R_ARM_MOVW_PREL_NC
init|=
literal|0x2d
block|,
name|R_ARM_MOVT_PREL
init|=
literal|0x2e
block|,
name|R_ARM_THM_MOVW_ABS_NC
init|=
literal|0x2f
block|,
name|R_ARM_THM_MOVT_ABS
init|=
literal|0x30
block|,
name|R_ARM_THM_MOVW_PREL_NC
init|=
literal|0x31
block|,
name|R_ARM_THM_MOVT_PREL
init|=
literal|0x32
block|,
name|R_ARM_THM_JUMP19
init|=
literal|0x33
block|,
name|R_ARM_THM_JUMP6
init|=
literal|0x34
block|,
name|R_ARM_THM_ALU_PREL_11_0
init|=
literal|0x35
block|,
name|R_ARM_THM_PC12
init|=
literal|0x36
block|,
name|R_ARM_ABS32_NOI
init|=
literal|0x37
block|,
name|R_ARM_REL32_NOI
init|=
literal|0x38
block|,
name|R_ARM_ALU_PC_G0_NC
init|=
literal|0x39
block|,
name|R_ARM_ALU_PC_G0
init|=
literal|0x3a
block|,
name|R_ARM_ALU_PC_G1_NC
init|=
literal|0x3b
block|,
name|R_ARM_ALU_PC_G1
init|=
literal|0x3c
block|,
name|R_ARM_ALU_PC_G2
init|=
literal|0x3d
block|,
name|R_ARM_LDR_PC_G1
init|=
literal|0x3e
block|,
name|R_ARM_LDR_PC_G2
init|=
literal|0x3f
block|,
name|R_ARM_LDRS_PC_G0
init|=
literal|0x40
block|,
name|R_ARM_LDRS_PC_G1
init|=
literal|0x41
block|,
name|R_ARM_LDRS_PC_G2
init|=
literal|0x42
block|,
name|R_ARM_LDC_PC_G0
init|=
literal|0x43
block|,
name|R_ARM_LDC_PC_G1
init|=
literal|0x44
block|,
name|R_ARM_LDC_PC_G2
init|=
literal|0x45
block|,
name|R_ARM_ALU_SB_G0_NC
init|=
literal|0x46
block|,
name|R_ARM_ALU_SB_G0
init|=
literal|0x47
block|,
name|R_ARM_ALU_SB_G1_NC
init|=
literal|0x48
block|,
name|R_ARM_ALU_SB_G1
init|=
literal|0x49
block|,
name|R_ARM_ALU_SB_G2
init|=
literal|0x4a
block|,
name|R_ARM_LDR_SB_G0
init|=
literal|0x4b
block|,
name|R_ARM_LDR_SB_G1
init|=
literal|0x4c
block|,
name|R_ARM_LDR_SB_G2
init|=
literal|0x4d
block|,
name|R_ARM_LDRS_SB_G0
init|=
literal|0x4e
block|,
name|R_ARM_LDRS_SB_G1
init|=
literal|0x4f
block|,
name|R_ARM_LDRS_SB_G2
init|=
literal|0x50
block|,
name|R_ARM_LDC_SB_G0
init|=
literal|0x51
block|,
name|R_ARM_LDC_SB_G1
init|=
literal|0x52
block|,
name|R_ARM_LDC_SB_G2
init|=
literal|0x53
block|,
name|R_ARM_MOVW_BREL_NC
init|=
literal|0x54
block|,
name|R_ARM_MOVT_BREL
init|=
literal|0x55
block|,
name|R_ARM_MOVW_BREL
init|=
literal|0x56
block|,
name|R_ARM_THM_MOVW_BREL_NC
init|=
literal|0x57
block|,
name|R_ARM_THM_MOVT_BREL
init|=
literal|0x58
block|,
name|R_ARM_THM_MOVW_BREL
init|=
literal|0x59
block|,
name|R_ARM_TLS_GOTDESC
init|=
literal|0x5a
block|,
name|R_ARM_TLS_CALL
init|=
literal|0x5b
block|,
name|R_ARM_TLS_DESCSEQ
init|=
literal|0x5c
block|,
name|R_ARM_THM_TLS_CALL
init|=
literal|0x5d
block|,
name|R_ARM_PLT32_ABS
init|=
literal|0x5e
block|,
name|R_ARM_GOT_ABS
init|=
literal|0x5f
block|,
name|R_ARM_GOT_PREL
init|=
literal|0x60
block|,
name|R_ARM_GOT_BREL12
init|=
literal|0x61
block|,
name|R_ARM_GOTOFF12
init|=
literal|0x62
block|,
name|R_ARM_GOTRELAX
init|=
literal|0x63
block|,
name|R_ARM_GNU_VTENTRY
init|=
literal|0x64
block|,
name|R_ARM_GNU_VTINHERIT
init|=
literal|0x65
block|,
name|R_ARM_THM_JUMP11
init|=
literal|0x66
block|,
name|R_ARM_THM_JUMP8
init|=
literal|0x67
block|,
name|R_ARM_TLS_GD32
init|=
literal|0x68
block|,
name|R_ARM_TLS_LDM32
init|=
literal|0x69
block|,
name|R_ARM_TLS_LDO32
init|=
literal|0x6a
block|,
name|R_ARM_TLS_IE32
init|=
literal|0x6b
block|,
name|R_ARM_TLS_LE32
init|=
literal|0x6c
block|,
name|R_ARM_TLS_LDO12
init|=
literal|0x6d
block|,
name|R_ARM_TLS_LE12
init|=
literal|0x6e
block|,
name|R_ARM_TLS_IE12GP
init|=
literal|0x6f
block|,
name|R_ARM_PRIVATE_0
init|=
literal|0x70
block|,
name|R_ARM_PRIVATE_1
init|=
literal|0x71
block|,
name|R_ARM_PRIVATE_2
init|=
literal|0x72
block|,
name|R_ARM_PRIVATE_3
init|=
literal|0x73
block|,
name|R_ARM_PRIVATE_4
init|=
literal|0x74
block|,
name|R_ARM_PRIVATE_5
init|=
literal|0x75
block|,
name|R_ARM_PRIVATE_6
init|=
literal|0x76
block|,
name|R_ARM_PRIVATE_7
init|=
literal|0x77
block|,
name|R_ARM_PRIVATE_8
init|=
literal|0x78
block|,
name|R_ARM_PRIVATE_9
init|=
literal|0x79
block|,
name|R_ARM_PRIVATE_10
init|=
literal|0x7a
block|,
name|R_ARM_PRIVATE_11
init|=
literal|0x7b
block|,
name|R_ARM_PRIVATE_12
init|=
literal|0x7c
block|,
name|R_ARM_PRIVATE_13
init|=
literal|0x7d
block|,
name|R_ARM_PRIVATE_14
init|=
literal|0x7e
block|,
name|R_ARM_PRIVATE_15
init|=
literal|0x7f
block|,
name|R_ARM_ME_TOO
init|=
literal|0x80
block|,
name|R_ARM_THM_TLS_DESCSEQ16
init|=
literal|0x81
block|,
name|R_ARM_THM_TLS_DESCSEQ32
init|=
literal|0x82
block|}
enum|;
comment|// Mips Specific e_flags
name|enum
name|LLVM_ENUM_INT_TYPE
function|(
name|unsigned
function|)
block|{
name|EF_MIPS_NOREORDER
operator|=
literal|0x00000001
operator|,
comment|// Don't reorder instructions
name|EF_MIPS_PIC
operator|=
literal|0x00000002
operator|,
comment|// Position independent code
name|EF_MIPS_CPIC
operator|=
literal|0x00000004
operator|,
comment|// Call object with Position independent code
name|EF_MIPS_ABI_O32
operator|=
literal|0x00001000
operator|,
comment|// This file follows the first MIPS 32 bit ABI
comment|//ARCH_ASE
name|EF_MIPS_MICROMIPS
operator|=
literal|0x02000000
operator|,
comment|// microMIPS
name|EF_MIPS_ARCH_ASE_M16
operator|=
literal|0x04000000
operator|,
comment|// Has Mips-16 ISA extensions
comment|//ARCH
name|EF_MIPS_ARCH_1
operator|=
literal|0x00000000
operator|,
comment|// MIPS1 instruction set
name|EF_MIPS_ARCH_2
operator|=
literal|0x10000000
operator|,
comment|// MIPS2 instruction set
name|EF_MIPS_ARCH_3
operator|=
literal|0x20000000
operator|,
comment|// MIPS3 instruction set
name|EF_MIPS_ARCH_4
operator|=
literal|0x30000000
operator|,
comment|// MIPS4 instruction set
name|EF_MIPS_ARCH_5
operator|=
literal|0x40000000
operator|,
comment|// MIPS5 instruction set
name|EF_MIPS_ARCH_32
operator|=
literal|0x50000000
operator|,
comment|// MIPS32 instruction set per linux not elf.h
name|EF_MIPS_ARCH_64
operator|=
literal|0x60000000
operator|,
comment|// MIPS64 instruction set per linux not elf.h
name|EF_MIPS_ARCH_32R2
operator|=
literal|0x70000000
operator|,
comment|// mips32r2
name|EF_MIPS_ARCH_64R2
operator|=
literal|0x80000000
operator|,
comment|// mips64r2
name|EF_MIPS_ARCH
operator|=
literal|0xf0000000
comment|// Mask for applying EF_MIPS_ARCH_ variant
block|}
empty_stmt|;
comment|// ELF Relocation types for Mips
comment|// .
enum|enum
block|{
name|R_MIPS_NONE
init|=
literal|0
block|,
name|R_MIPS_16
init|=
literal|1
block|,
name|R_MIPS_32
init|=
literal|2
block|,
name|R_MIPS_REL32
init|=
literal|3
block|,
name|R_MIPS_26
init|=
literal|4
block|,
name|R_MIPS_HI16
init|=
literal|5
block|,
name|R_MIPS_LO16
init|=
literal|6
block|,
name|R_MIPS_GPREL16
init|=
literal|7
block|,
name|R_MIPS_LITERAL
init|=
literal|8
block|,
name|R_MIPS_GOT16
init|=
literal|9
block|,
name|R_MIPS_GOT
init|=
literal|9
block|,
name|R_MIPS_PC16
init|=
literal|10
block|,
name|R_MIPS_CALL16
init|=
literal|11
block|,
name|R_MIPS_GPREL32
init|=
literal|12
block|,
name|R_MIPS_UNUSED1
init|=
literal|13
block|,
name|R_MIPS_UNUSED2
init|=
literal|14
block|,
name|R_MIPS_SHIFT5
init|=
literal|16
block|,
name|R_MIPS_SHIFT6
init|=
literal|17
block|,
name|R_MIPS_64
init|=
literal|18
block|,
name|R_MIPS_GOT_DISP
init|=
literal|19
block|,
name|R_MIPS_GOT_PAGE
init|=
literal|20
block|,
name|R_MIPS_GOT_OFST
init|=
literal|21
block|,
name|R_MIPS_GOT_HI16
init|=
literal|22
block|,
name|R_MIPS_GOT_LO16
init|=
literal|23
block|,
name|R_MIPS_SUB
init|=
literal|24
block|,
name|R_MIPS_INSERT_A
init|=
literal|25
block|,
name|R_MIPS_INSERT_B
init|=
literal|26
block|,
name|R_MIPS_DELETE
init|=
literal|27
block|,
name|R_MIPS_HIGHER
init|=
literal|28
block|,
name|R_MIPS_HIGHEST
init|=
literal|29
block|,
name|R_MIPS_CALL_HI16
init|=
literal|30
block|,
name|R_MIPS_CALL_LO16
init|=
literal|31
block|,
name|R_MIPS_SCN_DISP
init|=
literal|32
block|,
name|R_MIPS_REL16
init|=
literal|33
block|,
name|R_MIPS_ADD_IMMEDIATE
init|=
literal|34
block|,
name|R_MIPS_PJUMP
init|=
literal|35
block|,
name|R_MIPS_RELGOT
init|=
literal|36
block|,
name|R_MIPS_JALR
init|=
literal|37
block|,
name|R_MIPS_TLS_DTPMOD32
init|=
literal|38
block|,
name|R_MIPS_TLS_DTPREL32
init|=
literal|39
block|,
name|R_MIPS_TLS_DTPMOD64
init|=
literal|40
block|,
name|R_MIPS_TLS_DTPREL64
init|=
literal|41
block|,
name|R_MIPS_TLS_GD
init|=
literal|42
block|,
name|R_MIPS_TLS_LDM
init|=
literal|43
block|,
name|R_MIPS_TLS_DTPREL_HI16
init|=
literal|44
block|,
name|R_MIPS_TLS_DTPREL_LO16
init|=
literal|45
block|,
name|R_MIPS_TLS_GOTTPREL
init|=
literal|46
block|,
name|R_MIPS_TLS_TPREL32
init|=
literal|47
block|,
name|R_MIPS_TLS_TPREL64
init|=
literal|48
block|,
name|R_MIPS_TLS_TPREL_HI16
init|=
literal|49
block|,
name|R_MIPS_TLS_TPREL_LO16
init|=
literal|50
block|,
name|R_MIPS_GLOB_DAT
init|=
literal|51
block|,
name|R_MIPS_COPY
init|=
literal|126
block|,
name|R_MIPS_JUMP_SLOT
init|=
literal|127
block|,
name|R_MICROMIPS_26_S1
init|=
literal|133
block|,
name|R_MICROMIPS_HI16
init|=
literal|134
block|,
name|R_MICROMIPS_LO16
init|=
literal|135
block|,
name|R_MICROMIPS_GOT16
init|=
literal|138
block|,
name|R_MICROMIPS_PC16_S1
init|=
literal|141
block|,
name|R_MICROMIPS_CALL16
init|=
literal|142
block|,
name|R_MICROMIPS_GOT_DISP
init|=
literal|145
block|,
name|R_MICROMIPS_GOT_PAGE
init|=
literal|146
block|,
name|R_MICROMIPS_GOT_OFST
init|=
literal|147
block|,
name|R_MICROMIPS_TLS_DTPREL_HI16
init|=
literal|164
block|,
name|R_MICROMIPS_TLS_DTPREL_LO16
init|=
literal|165
block|,
name|R_MICROMIPS_TLS_TPREL_HI16
init|=
literal|169
block|,
name|R_MICROMIPS_TLS_TPREL_LO16
init|=
literal|170
block|,
name|R_MIPS_NUM
init|=
literal|218
block|}
enum|;
comment|// Special values for the st_other field in the symbol table entry for MIPS.
enum|enum
block|{
name|STO_MIPS_MICROMIPS
init|=
literal|0x80
comment|// MIPS Specific ISA for MicroMips
block|}
enum|;
comment|// Hexagon Specific e_flags
comment|// Release 5 ABI
enum|enum
block|{
comment|// Object processor version flags, bits[3:0]
name|EF_HEXAGON_MACH_V2
init|=
literal|0x00000001
block|,
comment|// Hexagon V2
name|EF_HEXAGON_MACH_V3
init|=
literal|0x00000002
block|,
comment|// Hexagon V3
name|EF_HEXAGON_MACH_V4
init|=
literal|0x00000003
block|,
comment|// Hexagon V4
name|EF_HEXAGON_MACH_V5
init|=
literal|0x00000004
block|,
comment|// Hexagon V5
comment|// Highest ISA version flags
name|EF_HEXAGON_ISA_MACH
init|=
literal|0x00000000
block|,
comment|// Same as specified in bits[3:0]
comment|// of e_flags
name|EF_HEXAGON_ISA_V2
init|=
literal|0x00000010
block|,
comment|// Hexagon V2 ISA
name|EF_HEXAGON_ISA_V3
init|=
literal|0x00000020
block|,
comment|// Hexagon V3 ISA
name|EF_HEXAGON_ISA_V4
init|=
literal|0x00000030
block|,
comment|// Hexagon V4 ISA
name|EF_HEXAGON_ISA_V5
init|=
literal|0x00000040
comment|// Hexagon V5 ISA
block|}
enum|;
comment|// Hexagon specific Section indexes for common small data
comment|// Release 5 ABI
enum|enum
block|{
name|SHN_HEXAGON_SCOMMON
init|=
literal|0xff00
block|,
comment|// Other access sizes
name|SHN_HEXAGON_SCOMMON_1
init|=
literal|0xff01
block|,
comment|// Byte-sized access
name|SHN_HEXAGON_SCOMMON_2
init|=
literal|0xff02
block|,
comment|// Half-word-sized access
name|SHN_HEXAGON_SCOMMON_4
init|=
literal|0xff03
block|,
comment|// Word-sized access
name|SHN_HEXAGON_SCOMMON_8
init|=
literal|0xff04
comment|// Double-word-size access
block|}
enum|;
comment|// ELF Relocation types for Hexagon
comment|// Release 5 ABI
enum|enum
block|{
name|R_HEX_NONE
init|=
literal|0
block|,
name|R_HEX_B22_PCREL
init|=
literal|1
block|,
name|R_HEX_B15_PCREL
init|=
literal|2
block|,
name|R_HEX_B7_PCREL
init|=
literal|3
block|,
name|R_HEX_LO16
init|=
literal|4
block|,
name|R_HEX_HI16
init|=
literal|5
block|,
name|R_HEX_32
init|=
literal|6
block|,
name|R_HEX_16
init|=
literal|7
block|,
name|R_HEX_8
init|=
literal|8
block|,
name|R_HEX_GPREL16_0
init|=
literal|9
block|,
name|R_HEX_GPREL16_1
init|=
literal|10
block|,
name|R_HEX_GPREL16_2
init|=
literal|11
block|,
name|R_HEX_GPREL16_3
init|=
literal|12
block|,
name|R_HEX_HL16
init|=
literal|13
block|,
name|R_HEX_B13_PCREL
init|=
literal|14
block|,
name|R_HEX_B9_PCREL
init|=
literal|15
block|,
name|R_HEX_B32_PCREL_X
init|=
literal|16
block|,
name|R_HEX_32_6_X
init|=
literal|17
block|,
name|R_HEX_B22_PCREL_X
init|=
literal|18
block|,
name|R_HEX_B15_PCREL_X
init|=
literal|19
block|,
name|R_HEX_B13_PCREL_X
init|=
literal|20
block|,
name|R_HEX_B9_PCREL_X
init|=
literal|21
block|,
name|R_HEX_B7_PCREL_X
init|=
literal|22
block|,
name|R_HEX_16_X
init|=
literal|23
block|,
name|R_HEX_12_X
init|=
literal|24
block|,
name|R_HEX_11_X
init|=
literal|25
block|,
name|R_HEX_10_X
init|=
literal|26
block|,
name|R_HEX_9_X
init|=
literal|27
block|,
name|R_HEX_8_X
init|=
literal|28
block|,
name|R_HEX_7_X
init|=
literal|29
block|,
name|R_HEX_6_X
init|=
literal|30
block|,
name|R_HEX_32_PCREL
init|=
literal|31
block|,
name|R_HEX_COPY
init|=
literal|32
block|,
name|R_HEX_GLOB_DAT
init|=
literal|33
block|,
name|R_HEX_JMP_SLOT
init|=
literal|34
block|,
name|R_HEX_RELATIVE
init|=
literal|35
block|,
name|R_HEX_PLT_B22_PCREL
init|=
literal|36
block|,
name|R_HEX_GOTREL_LO16
init|=
literal|37
block|,
name|R_HEX_GOTREL_HI16
init|=
literal|38
block|,
name|R_HEX_GOTREL_32
init|=
literal|39
block|,
name|R_HEX_GOT_LO16
init|=
literal|40
block|,
name|R_HEX_GOT_HI16
init|=
literal|41
block|,
name|R_HEX_GOT_32
init|=
literal|42
block|,
name|R_HEX_GOT_16
init|=
literal|43
block|,
name|R_HEX_DTPMOD_32
init|=
literal|44
block|,
name|R_HEX_DTPREL_LO16
init|=
literal|45
block|,
name|R_HEX_DTPREL_HI16
init|=
literal|46
block|,
name|R_HEX_DTPREL_32
init|=
literal|47
block|,
name|R_HEX_DTPREL_16
init|=
literal|48
block|,
name|R_HEX_GD_PLT_B22_PCREL
init|=
literal|49
block|,
name|R_HEX_GD_GOT_LO16
init|=
literal|50
block|,
name|R_HEX_GD_GOT_HI16
init|=
literal|51
block|,
name|R_HEX_GD_GOT_32
init|=
literal|52
block|,
name|R_HEX_GD_GOT_16
init|=
literal|53
block|,
name|R_HEX_IE_LO16
init|=
literal|54
block|,
name|R_HEX_IE_HI16
init|=
literal|55
block|,
name|R_HEX_IE_32
init|=
literal|56
block|,
name|R_HEX_IE_GOT_LO16
init|=
literal|57
block|,
name|R_HEX_IE_GOT_HI16
init|=
literal|58
block|,
name|R_HEX_IE_GOT_32
init|=
literal|59
block|,
name|R_HEX_IE_GOT_16
init|=
literal|60
block|,
name|R_HEX_TPREL_LO16
init|=
literal|61
block|,
name|R_HEX_TPREL_HI16
init|=
literal|62
block|,
name|R_HEX_TPREL_32
init|=
literal|63
block|,
name|R_HEX_TPREL_16
init|=
literal|64
block|,
name|R_HEX_6_PCREL_X
init|=
literal|65
block|,
name|R_HEX_GOTREL_32_6_X
init|=
literal|66
block|,
name|R_HEX_GOTREL_16_X
init|=
literal|67
block|,
name|R_HEX_GOTREL_11_X
init|=
literal|68
block|,
name|R_HEX_GOT_32_6_X
init|=
literal|69
block|,
name|R_HEX_GOT_16_X
init|=
literal|70
block|,
name|R_HEX_GOT_11_X
init|=
literal|71
block|,
name|R_HEX_DTPREL_32_6_X
init|=
literal|72
block|,
name|R_HEX_DTPREL_16_X
init|=
literal|73
block|,
name|R_HEX_DTPREL_11_X
init|=
literal|74
block|,
name|R_HEX_GD_GOT_32_6_X
init|=
literal|75
block|,
name|R_HEX_GD_GOT_16_X
init|=
literal|76
block|,
name|R_HEX_GD_GOT_11_X
init|=
literal|77
block|,
name|R_HEX_IE_32_6_X
init|=
literal|78
block|,
name|R_HEX_IE_16_X
init|=
literal|79
block|,
name|R_HEX_IE_GOT_32_6_X
init|=
literal|80
block|,
name|R_HEX_IE_GOT_16_X
init|=
literal|81
block|,
name|R_HEX_IE_GOT_11_X
init|=
literal|82
block|,
name|R_HEX_TPREL_32_6_X
init|=
literal|83
block|,
name|R_HEX_TPREL_16_X
init|=
literal|84
block|,
name|R_HEX_TPREL_11_X
init|=
literal|85
block|}
enum|;
comment|// ELF Relocation types for S390/zSeries
enum|enum
block|{
name|R_390_NONE
init|=
literal|0
block|,
name|R_390_8
init|=
literal|1
block|,
name|R_390_12
init|=
literal|2
block|,
name|R_390_16
init|=
literal|3
block|,
name|R_390_32
init|=
literal|4
block|,
name|R_390_PC32
init|=
literal|5
block|,
name|R_390_GOT12
init|=
literal|6
block|,
name|R_390_GOT32
init|=
literal|7
block|,
name|R_390_PLT32
init|=
literal|8
block|,
name|R_390_COPY
init|=
literal|9
block|,
name|R_390_GLOB_DAT
init|=
literal|10
block|,
name|R_390_JMP_SLOT
init|=
literal|11
block|,
name|R_390_RELATIVE
init|=
literal|12
block|,
name|R_390_GOTOFF
init|=
literal|13
block|,
name|R_390_GOTPC
init|=
literal|14
block|,
name|R_390_GOT16
init|=
literal|15
block|,
name|R_390_PC16
init|=
literal|16
block|,
name|R_390_PC16DBL
init|=
literal|17
block|,
name|R_390_PLT16DBL
init|=
literal|18
block|,
name|R_390_PC32DBL
init|=
literal|19
block|,
name|R_390_PLT32DBL
init|=
literal|20
block|,
name|R_390_GOTPCDBL
init|=
literal|21
block|,
name|R_390_64
init|=
literal|22
block|,
name|R_390_PC64
init|=
literal|23
block|,
name|R_390_GOT64
init|=
literal|24
block|,
name|R_390_PLT64
init|=
literal|25
block|,
name|R_390_GOTENT
init|=
literal|26
block|,
name|R_390_GOTOFF16
init|=
literal|27
block|,
name|R_390_GOTOFF64
init|=
literal|28
block|,
name|R_390_GOTPLT12
init|=
literal|29
block|,
name|R_390_GOTPLT16
init|=
literal|30
block|,
name|R_390_GOTPLT32
init|=
literal|31
block|,
name|R_390_GOTPLT64
init|=
literal|32
block|,
name|R_390_GOTPLTENT
init|=
literal|33
block|,
name|R_390_PLTOFF16
init|=
literal|34
block|,
name|R_390_PLTOFF32
init|=
literal|35
block|,
name|R_390_PLTOFF64
init|=
literal|36
block|,
name|R_390_TLS_LOAD
init|=
literal|37
block|,
name|R_390_TLS_GDCALL
init|=
literal|38
block|,
name|R_390_TLS_LDCALL
init|=
literal|39
block|,
name|R_390_TLS_GD32
init|=
literal|40
block|,
name|R_390_TLS_GD64
init|=
literal|41
block|,
name|R_390_TLS_GOTIE12
init|=
literal|42
block|,
name|R_390_TLS_GOTIE32
init|=
literal|43
block|,
name|R_390_TLS_GOTIE64
init|=
literal|44
block|,
name|R_390_TLS_LDM32
init|=
literal|45
block|,
name|R_390_TLS_LDM64
init|=
literal|46
block|,
name|R_390_TLS_IE32
init|=
literal|47
block|,
name|R_390_TLS_IE64
init|=
literal|48
block|,
name|R_390_TLS_IEENT
init|=
literal|49
block|,
name|R_390_TLS_LE32
init|=
literal|50
block|,
name|R_390_TLS_LE64
init|=
literal|51
block|,
name|R_390_TLS_LDO32
init|=
literal|52
block|,
name|R_390_TLS_LDO64
init|=
literal|53
block|,
name|R_390_TLS_DTPMOD
init|=
literal|54
block|,
name|R_390_TLS_DTPOFF
init|=
literal|55
block|,
name|R_390_TLS_TPOFF
init|=
literal|56
block|,
name|R_390_20
init|=
literal|57
block|,
name|R_390_GOT20
init|=
literal|58
block|,
name|R_390_GOTPLT20
init|=
literal|59
block|,
name|R_390_TLS_GOTIE20
init|=
literal|60
block|,
name|R_390_IRELATIVE
init|=
literal|61
block|}
enum|;
comment|// ELF Relocation type for Sparc.
enum|enum
block|{
name|R_SPARC_NONE
init|=
literal|0
block|,
name|R_SPARC_8
init|=
literal|1
block|,
name|R_SPARC_16
init|=
literal|2
block|,
name|R_SPARC_32
init|=
literal|3
block|,
name|R_SPARC_DISP8
init|=
literal|4
block|,
name|R_SPARC_DISP16
init|=
literal|5
block|,
name|R_SPARC_DISP32
init|=
literal|6
block|,
name|R_SPARC_WDISP30
init|=
literal|7
block|,
name|R_SPARC_WDISP22
init|=
literal|8
block|,
name|R_SPARC_HI22
init|=
literal|9
block|,
name|R_SPARC_22
init|=
literal|10
block|,
name|R_SPARC_13
init|=
literal|11
block|,
name|R_SPARC_LO10
init|=
literal|12
block|,
name|R_SPARC_GOT10
init|=
literal|13
block|,
name|R_SPARC_GOT13
init|=
literal|14
block|,
name|R_SPARC_GOT22
init|=
literal|15
block|,
name|R_SPARC_PC10
init|=
literal|16
block|,
name|R_SPARC_PC22
init|=
literal|17
block|,
name|R_SPARC_WPLT30
init|=
literal|18
block|,
name|R_SPARC_COPY
init|=
literal|19
block|,
name|R_SPARC_GLOB_DAT
init|=
literal|20
block|,
name|R_SPARC_JMP_SLOT
init|=
literal|21
block|,
name|R_SPARC_RELATIVE
init|=
literal|22
block|,
name|R_SPARC_UA32
init|=
literal|23
block|,
name|R_SPARC_PLT32
init|=
literal|24
block|,
name|R_SPARC_HIPLT22
init|=
literal|25
block|,
name|R_SPARC_LOPLT10
init|=
literal|26
block|,
name|R_SPARC_PCPLT32
init|=
literal|27
block|,
name|R_SPARC_PCPLT22
init|=
literal|28
block|,
name|R_SPARC_PCPLT10
init|=
literal|29
block|,
name|R_SPARC_10
init|=
literal|30
block|,
name|R_SPARC_11
init|=
literal|31
block|,
name|R_SPARC_64
init|=
literal|32
block|,
name|R_SPARC_OLO10
init|=
literal|33
block|,
name|R_SPARC_HH22
init|=
literal|34
block|,
name|R_SPARC_HM10
init|=
literal|35
block|,
name|R_SPARC_LM22
init|=
literal|36
block|,
name|R_SPARC_PC_HH22
init|=
literal|37
block|,
name|R_SPARC_PC_HM10
init|=
literal|38
block|,
name|R_SPARC_PC_LM22
init|=
literal|39
block|,
name|R_SPARC_WDISP16
init|=
literal|40
block|,
name|R_SPARC_WDISP19
init|=
literal|41
block|,
name|R_SPARC_7
init|=
literal|43
block|,
name|R_SPARC_5
init|=
literal|44
block|,
name|R_SPARC_6
init|=
literal|45
block|,
name|R_SPARC_DISP64
init|=
literal|46
block|,
name|R_SPARC_PLT64
init|=
literal|47
block|,
name|R_SPARC_HIX22
init|=
literal|48
block|,
name|R_SPARC_LOX10
init|=
literal|49
block|,
name|R_SPARC_H44
init|=
literal|50
block|,
name|R_SPARC_M44
init|=
literal|51
block|,
name|R_SPARC_L44
init|=
literal|52
block|,
name|R_SPARC_REGISTER
init|=
literal|53
block|,
name|R_SPARC_UA64
init|=
literal|54
block|,
name|R_SPARC_UA16
init|=
literal|55
block|,
name|R_SPARC_TLS_GD_HI22
init|=
literal|56
block|,
name|R_SPARC_TLS_GD_LO10
init|=
literal|57
block|,
name|R_SPARC_TLS_GD_ADD
init|=
literal|58
block|,
name|R_SPARC_TLS_GD_CALL
init|=
literal|59
block|,
name|R_SPARC_TLS_LDM_HI22
init|=
literal|60
block|,
name|R_SPARC_TLS_LDM_LO10
init|=
literal|61
block|,
name|R_SPARC_TLS_LDM_ADD
init|=
literal|62
block|,
name|R_SPARC_TLS_LDM_CALL
init|=
literal|63
block|,
name|R_SPARC_TLS_LDO_HIX22
init|=
literal|64
block|,
name|R_SPARC_TLS_LDO_LOX10
init|=
literal|65
block|,
name|R_SPARC_TLS_LDO_ADD
init|=
literal|66
block|,
name|R_SPARC_TLS_IE_HI22
init|=
literal|67
block|,
name|R_SPARC_TLS_IE_LO10
init|=
literal|68
block|,
name|R_SPARC_TLS_IE_LD
init|=
literal|69
block|,
name|R_SPARC_TLS_IE_LDX
init|=
literal|70
block|,
name|R_SPARC_TLS_IE_ADD
init|=
literal|71
block|,
name|R_SPARC_TLS_LE_HIX22
init|=
literal|72
block|,
name|R_SPARC_TLS_LE_LOX10
init|=
literal|73
block|,
name|R_SPARC_TLS_DTPMOD32
init|=
literal|74
block|,
name|R_SPARC_TLS_DTPMOD64
init|=
literal|75
block|,
name|R_SPARC_TLS_DTPOFF32
init|=
literal|76
block|,
name|R_SPARC_TLS_DTPOFF64
init|=
literal|77
block|,
name|R_SPARC_TLS_TPOFF32
init|=
literal|78
block|,
name|R_SPARC_TLS_TPOFF64
init|=
literal|79
block|,
name|R_SPARC_GOTDATA_HIX22
init|=
literal|80
block|,
name|R_SPARC_GOTDATA_LOX22
init|=
literal|81
block|,
name|R_SPARC_GOTDATA_OP_HIX22
init|=
literal|82
block|,
name|R_SPARC_GOTDATA_OP_LOX22
init|=
literal|83
block|,
name|R_SPARC_GOTDATA_OP
init|=
literal|84
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
name|Elf64_Word
name|sh_name
decl_stmt|;
name|Elf64_Word
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
name|Elf64_Word
name|sh_link
decl_stmt|;
name|Elf64_Word
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
name|SHN_LOOS
init|=
literal|0xff20
block|,
comment|// Lowest operating system-specific index
name|SHN_HIOS
init|=
literal|0xff3f
block|,
comment|// Highest operating system-specific index
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
name|SHN_XINDEX
init|=
literal|0xffff
block|,
comment|// Mark that the index is>= SHN_LORESERVE
name|SHN_HIRESERVE
init|=
literal|0xffff
comment|// Highest reserved index
block|}
enum|;
comment|// Section types.
name|enum
name|LLVM_ENUM_INT_TYPE
function|(
name|unsigned
function|)
block|{
name|SHT_NULL
operator|=
literal|0
operator|,
comment|// No associated section (inactive entry).
name|SHT_PROGBITS
operator|=
literal|1
operator|,
comment|// Program-defined contents.
name|SHT_SYMTAB
operator|=
literal|2
operator|,
comment|// Symbol table.
name|SHT_STRTAB
operator|=
literal|3
operator|,
comment|// String table.
name|SHT_RELA
operator|=
literal|4
operator|,
comment|// Relocation entries; explicit addends.
name|SHT_HASH
operator|=
literal|5
operator|,
comment|// Symbol hash table.
name|SHT_DYNAMIC
operator|=
literal|6
operator|,
comment|// Information for dynamic linking.
name|SHT_NOTE
operator|=
literal|7
operator|,
comment|// Information about the file.
name|SHT_NOBITS
operator|=
literal|8
operator|,
comment|// Data occupies no space in the file.
name|SHT_REL
operator|=
literal|9
operator|,
comment|// Relocation entries; no explicit addends.
name|SHT_SHLIB
operator|=
literal|10
operator|,
comment|// Reserved.
name|SHT_DYNSYM
operator|=
literal|11
operator|,
comment|// Symbol table.
name|SHT_INIT_ARRAY
operator|=
literal|14
operator|,
comment|// Pointers to initialization functions.
name|SHT_FINI_ARRAY
operator|=
literal|15
operator|,
comment|// Pointers to termination functions.
name|SHT_PREINIT_ARRAY
operator|=
literal|16
operator|,
comment|// Pointers to pre-init functions.
name|SHT_GROUP
operator|=
literal|17
operator|,
comment|// Section group.
name|SHT_SYMTAB_SHNDX
operator|=
literal|18
operator|,
comment|// Indices for SHN_XINDEX entries.
name|SHT_LOOS
operator|=
literal|0x60000000
operator|,
comment|// Lowest operating system-specific type.
name|SHT_GNU_ATTRIBUTES
operator|=
literal|0x6ffffff5
operator|,
comment|// Object attributes.
name|SHT_GNU_HASH
operator|=
literal|0x6ffffff6
operator|,
comment|// GNU-style hash table.
name|SHT_GNU_verdef
operator|=
literal|0x6ffffffd
operator|,
comment|// GNU version definitions.
name|SHT_GNU_verneed
operator|=
literal|0x6ffffffe
operator|,
comment|// GNU version references.
name|SHT_GNU_versym
operator|=
literal|0x6fffffff
operator|,
comment|// GNU symbol versions table.
name|SHT_HIOS
operator|=
literal|0x6fffffff
operator|,
comment|// Highest operating system-specific type.
name|SHT_LOPROC
operator|=
literal|0x70000000
operator|,
comment|// Lowest processor arch-specific type.
comment|// Fixme: All this is duplicated in MCSectionELF. Why??
comment|// Exception Index table
name|SHT_ARM_EXIDX
operator|=
literal|0x70000001U
operator|,
comment|// BPABI DLL dynamic linking pre-emption map
name|SHT_ARM_PREEMPTMAP
operator|=
literal|0x70000002U
operator|,
comment|//  Object file compatibility attributes
name|SHT_ARM_ATTRIBUTES
operator|=
literal|0x70000003U
operator|,
name|SHT_ARM_DEBUGOVERLAY
operator|=
literal|0x70000004U
operator|,
name|SHT_ARM_OVERLAYSECTION
operator|=
literal|0x70000005U
operator|,
name|SHT_HEX_ORDERED
operator|=
literal|0x70000000
operator|,
comment|// Link editor is to sort the entries in
comment|// this section based on their sizes
name|SHT_X86_64_UNWIND
operator|=
literal|0x70000001
operator|,
comment|// Unwind information
name|SHT_MIPS_REGINFO
operator|=
literal|0x70000006
operator|,
comment|// Register usage information
name|SHT_MIPS_OPTIONS
operator|=
literal|0x7000000d
operator|,
comment|// General options
name|SHT_HIPROC
operator|=
literal|0x7fffffff
operator|,
comment|// Highest processor arch-specific type.
name|SHT_LOUSER
operator|=
literal|0x80000000
operator|,
comment|// Lowest type reserved for applications.
name|SHT_HIUSER
operator|=
literal|0xffffffff
comment|// Highest type reserved for applications.
block|}
empty_stmt|;
comment|// Section flags.
name|enum
name|LLVM_ENUM_INT_TYPE
function|(
name|unsigned
function|)
block|{
comment|// Section data should be writable during execution.
name|SHF_WRITE
operator|=
literal|0x1
operator|,
comment|// Section occupies memory during program execution.
name|SHF_ALLOC
operator|=
literal|0x2
operator|,
comment|// Section contains executable machine instructions.
name|SHF_EXECINSTR
operator|=
literal|0x4
operator|,
comment|// The data in this section may be merged.
name|SHF_MERGE
operator|=
literal|0x10
operator|,
comment|// The data in this section is null-terminated strings.
name|SHF_STRINGS
operator|=
literal|0x20
operator|,
comment|// A field in this section holds a section header table index.
name|SHF_INFO_LINK
operator|=
literal|0x40U
operator|,
comment|// Adds special ordering requirements for link editors.
name|SHF_LINK_ORDER
operator|=
literal|0x80U
operator|,
comment|// This section requires special OS-specific processing to avoid incorrect
comment|// behavior.
name|SHF_OS_NONCONFORMING
operator|=
literal|0x100U
operator|,
comment|// This section is a member of a section group.
name|SHF_GROUP
operator|=
literal|0x200U
operator|,
comment|// This section holds Thread-Local Storage.
name|SHF_TLS
operator|=
literal|0x400U
operator|,
comment|// This section is excluded from the final executable or shared library.
name|SHF_EXCLUDE
operator|=
literal|0x80000000U
operator|,
comment|// Start of target-specific flags.
comment|/// XCORE_SHF_CP_SECTION - All sections with the "c" flag are grouped
comment|/// together by the linker to form the constant pool and the cp register is
comment|/// set to the start of the constant pool by the boot code.
name|XCORE_SHF_CP_SECTION
operator|=
literal|0x800U
operator|,
comment|/// XCORE_SHF_DP_SECTION - All sections with the "d" flag are grouped
comment|/// together by the linker to form the data section and the dp register is
comment|/// set to the start of the section by the boot code.
name|XCORE_SHF_DP_SECTION
operator|=
literal|0x1000U
operator|,
name|SHF_MASKOS
operator|=
literal|0x0ff00000
operator|,
comment|// Bits indicating processor-specific flags.
name|SHF_MASKPROC
operator|=
literal|0xf0000000
operator|,
comment|// If an object file section does not have this flag set, then it may not hold
comment|// more than 2GB and can be freely referred to in objects using smaller code
comment|// models. Otherwise, only objects using larger code models can refer to them.
comment|// For example, a medium code model object can refer to data in a section that
comment|// sets this flag besides being able to refer to data in a section that does
comment|// not set it; likewise, a small code model object can refer only to code in a
comment|// section that does not set this flag.
name|SHF_X86_64_LARGE
operator|=
literal|0x10000000
operator|,
comment|// All sections with the GPREL flag are grouped into a global data area
comment|// for faster accesses
name|SHF_HEX_GPREL
operator|=
literal|0x10000000
operator|,
comment|// Section contains text/data which may be replicated in other sections.
comment|// Linker must retain only one copy.
name|SHF_MIPS_NODUPES
operator|=
literal|0x01000000
operator|,
comment|// Linker must generate implicit hidden weak names.
name|SHF_MIPS_NAMES
operator|=
literal|0x02000000
operator|,
comment|// Section data local to process.
name|SHF_MIPS_LOCAL
operator|=
literal|0x04000000
operator|,
comment|// Do not strip this section.
name|SHF_MIPS_NOSTRIP
operator|=
literal|0x08000000
operator|,
comment|// Section must be part of global data area.
name|SHF_MIPS_GPREL
operator|=
literal|0x10000000
operator|,
comment|// This section should be merged.
name|SHF_MIPS_MERGE
operator|=
literal|0x20000000
operator|,
comment|// Address size to be inferred from section entry size.
name|SHF_MIPS_ADDR
operator|=
literal|0x40000000
operator|,
comment|// Section data is string data by default.
name|SHF_MIPS_STRING
operator|=
literal|0x80000000
block|}
empty_stmt|;
comment|// Section Group Flags
name|enum
name|LLVM_ENUM_INT_TYPE
function|(
name|unsigned
function|)
block|{
name|GRP_COMDAT
operator|=
literal|0x1
operator|,
name|GRP_MASKOS
operator|=
literal|0x0ff00000
operator|,
name|GRP_MASKPROC
operator|=
literal|0xf0000000
block|}
empty_stmt|;
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
comment|// Which section (header tbl index) it's defined in
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
name|STB_LOOS
init|=
literal|10
block|,
comment|// Lowest operating system-specific binding type
name|STB_HIOS
init|=
literal|12
block|,
comment|// Highest operating system-specific binding type
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
comment|// An uninitialized common block
name|STT_TLS
init|=
literal|6
block|,
comment|// Thread local data object
name|STT_LOOS
init|=
literal|7
block|,
comment|// Lowest operating system-specific symbol type
name|STT_HIOS
init|=
literal|8
block|,
comment|// Highest operating system-specific symbol type
name|STT_GNU_IFUNC
init|=
literal|10
block|,
comment|// GNU indirect function
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
comment|// Symbol number.
enum|enum
block|{
name|STN_UNDEF
init|=
literal|0
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
name|Elf64_Word
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
name|Elf64_Word
name|getType
argument_list|()
specifier|const
block|{
return|return
call|(
name|Elf64_Word
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
name|Elf64_Word
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
name|Elf64_Word
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
name|Elf64_Word
name|s
parameter_list|,
name|Elf64_Word
name|t
parameter_list|)
block|{
name|r_info
operator|=
operator|(
operator|(
name|Elf64_Xword
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
name|Elf64_Word
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
name|Elf64_Word
name|getType
argument_list|()
specifier|const
block|{
return|return
call|(
name|Elf64_Word
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
name|Elf64_Word
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
name|Elf64_Word
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
name|Elf64_Word
name|s
parameter_list|,
name|Elf64_Word
name|t
parameter_list|)
block|{
name|r_info
operator|=
operator|(
operator|(
name|Elf64_Xword
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
comment|// Physical addr of beginning of segment (OS-specific)
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
name|PT_TLS
init|=
literal|7
block|,
comment|// The thread-local storage template.
name|PT_LOOS
init|=
literal|0x60000000
block|,
comment|// Lowest operating system-specific pt entry type.
name|PT_HIOS
init|=
literal|0x6fffffff
block|,
comment|// Highest operating system-specific pt entry type.
name|PT_LOPROC
init|=
literal|0x70000000
block|,
comment|// Lowest processor-specific program hdr entry type.
name|PT_HIPROC
init|=
literal|0x7fffffff
block|,
comment|// Highest processor-specific program hdr entry type.
comment|// x86-64 program header types.
comment|// These all contain stack unwind tables.
name|PT_GNU_EH_FRAME
init|=
literal|0x6474e550
block|,
name|PT_SUNW_EH_FRAME
init|=
literal|0x6474e550
block|,
name|PT_SUNW_UNWIND
init|=
literal|0x6464e550
block|,
name|PT_GNU_STACK
init|=
literal|0x6474e551
block|,
comment|// Indicates stack executability.
name|PT_GNU_RELRO
init|=
literal|0x6474e552
block|,
comment|// Read-only after relocation.
comment|// ARM program header types.
name|PT_ARM_ARCHEXT
init|=
literal|0x70000000
block|,
comment|// Platform architecture compatibility info
comment|// These all contain stack unwind tables.
name|PT_ARM_EXIDX
init|=
literal|0x70000001
block|,
name|PT_ARM_UNWIND
init|=
literal|0x70000001
block|,
comment|// MIPS program header types.
name|PT_MIPS_REGINFO
init|=
literal|0x70000000
block|,
comment|// Register usage information.
name|PT_MIPS_RTPROC
init|=
literal|0x70000001
block|,
comment|// Runtime procedure table.
name|PT_MIPS_OPTIONS
init|=
literal|0x70000002
comment|// Options segment.
block|}
enum|;
comment|// Segment flag bits.
name|enum
name|LLVM_ENUM_INT_TYPE
function|(
name|unsigned
function|)
block|{
name|PF_X
operator|=
literal|1
operator|,
comment|// Execute
name|PF_W
operator|=
literal|2
operator|,
comment|// Write
name|PF_R
operator|=
literal|4
operator|,
comment|// Read
name|PF_MASKOS
operator|=
literal|0x0ff00000
operator|,
comment|// Bits for operating system-specific semantics.
name|PF_MASKPROC
operator|=
literal|0xf0000000
comment|// Bits for processor-specific semantics.
block|}
empty_stmt|;
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
comment|// Relocations exist for non-writable segments.
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
name|DT_RUNPATH
init|=
literal|29
block|,
comment|// String table offset of lib search path.
name|DT_FLAGS
init|=
literal|30
block|,
comment|// Flags.
name|DT_ENCODING
init|=
literal|32
block|,
comment|// Values from here to DT_LOOS follow the rules
comment|// for the interpretation of the d_un union.
name|DT_PREINIT_ARRAY
init|=
literal|32
block|,
comment|// Pointer to array of preinit functions.
name|DT_PREINIT_ARRAYSZ
init|=
literal|33
block|,
comment|// Size of the DT_PREINIT_ARRAY array.
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
block|,
comment|// End of processor specific tags.
name|DT_RELACOUNT
init|=
literal|0x6FFFFFF9
block|,
comment|// ELF32_Rela count.
name|DT_RELCOUNT
init|=
literal|0x6FFFFFFA
block|,
comment|// ELF32_Rel count.
name|DT_FLAGS_1
init|=
literal|0X6FFFFFFB
block|,
comment|// Flags_1.
name|DT_VERSYM
init|=
literal|0x6FFFFFF0
block|,
comment|// The address of .gnu.version section.
name|DT_VERDEF
init|=
literal|0X6FFFFFFC
block|,
comment|// The address of the version definition table.
name|DT_VERDEFNUM
init|=
literal|0X6FFFFFFD
block|,
comment|// The number of entries in DT_VERDEF.
name|DT_VERNEED
init|=
literal|0X6FFFFFFE
block|,
comment|// The address of the version Dependency table.
name|DT_VERNEEDNUM
init|=
literal|0X6FFFFFFF
block|,
comment|// The number of entries in DT_VERNEED.
comment|// Mips specific dynamic table entry tags.
name|DT_MIPS_RLD_VERSION
init|=
literal|0x70000001
block|,
comment|// 32 bit version number for runtime
comment|// linker interface.
name|DT_MIPS_TIME_STAMP
init|=
literal|0x70000002
block|,
comment|// Time stamp.
name|DT_MIPS_ICHECKSUM
init|=
literal|0x70000003
block|,
comment|// Checksum of external strings
comment|// and common sizes.
name|DT_MIPS_IVERSION
init|=
literal|0x70000004
block|,
comment|// Index of version string
comment|// in string table.
name|DT_MIPS_FLAGS
init|=
literal|0x70000005
block|,
comment|// 32 bits of flags.
name|DT_MIPS_BASE_ADDRESS
init|=
literal|0x70000006
block|,
comment|// Base address of the segment.
name|DT_MIPS_MSYM
init|=
literal|0x70000007
block|,
comment|// Address of .msym section.
name|DT_MIPS_CONFLICT
init|=
literal|0x70000008
block|,
comment|// Address of .conflict section.
name|DT_MIPS_LIBLIST
init|=
literal|0x70000009
block|,
comment|// Address of .liblist section.
name|DT_MIPS_LOCAL_GOTNO
init|=
literal|0x7000000a
block|,
comment|// Number of local global offset
comment|// table entries.
name|DT_MIPS_CONFLICTNO
init|=
literal|0x7000000b
block|,
comment|// Number of entries
comment|// in the .conflict section.
name|DT_MIPS_LIBLISTNO
init|=
literal|0x70000010
block|,
comment|// Number of entries
comment|// in the .liblist section.
name|DT_MIPS_SYMTABNO
init|=
literal|0x70000011
block|,
comment|// Number of entries
comment|// in the .dynsym section.
name|DT_MIPS_UNREFEXTNO
init|=
literal|0x70000012
block|,
comment|// Index of first external dynamic symbol
comment|// not referenced locally.
name|DT_MIPS_GOTSYM
init|=
literal|0x70000013
block|,
comment|// Index of first dynamic symbol
comment|// in global offset table.
name|DT_MIPS_HIPAGENO
init|=
literal|0x70000014
block|,
comment|// Number of page table entries
comment|// in global offset table.
name|DT_MIPS_RLD_MAP
init|=
literal|0x70000016
block|,
comment|// Address of run time loader map,
comment|// used for debugging.
name|DT_MIPS_DELTA_CLASS
init|=
literal|0x70000017
block|,
comment|// Delta C++ class definition.
name|DT_MIPS_DELTA_CLASS_NO
init|=
literal|0x70000018
block|,
comment|// Number of entries
comment|// in DT_MIPS_DELTA_CLASS.
name|DT_MIPS_DELTA_INSTANCE
init|=
literal|0x70000019
block|,
comment|// Delta C++ class instances.
name|DT_MIPS_DELTA_INSTANCE_NO
init|=
literal|0x7000001A
block|,
comment|// Number of entries
comment|// in DT_MIPS_DELTA_INSTANCE.
name|DT_MIPS_DELTA_RELOC
init|=
literal|0x7000001B
block|,
comment|// Delta relocations.
name|DT_MIPS_DELTA_RELOC_NO
init|=
literal|0x7000001C
block|,
comment|// Number of entries
comment|// in DT_MIPS_DELTA_RELOC.
name|DT_MIPS_DELTA_SYM
init|=
literal|0x7000001D
block|,
comment|// Delta symbols that Delta
comment|// relocations refer to.
name|DT_MIPS_DELTA_SYM_NO
init|=
literal|0x7000001E
block|,
comment|// Number of entries
comment|// in DT_MIPS_DELTA_SYM.
name|DT_MIPS_DELTA_CLASSSYM
init|=
literal|0x70000020
block|,
comment|// Delta symbols that hold
comment|// class declarations.
name|DT_MIPS_DELTA_CLASSSYM_NO
init|=
literal|0x70000021
block|,
comment|// Number of entries
comment|// in DT_MIPS_DELTA_CLASSSYM.
name|DT_MIPS_CXX_FLAGS
init|=
literal|0x70000022
block|,
comment|// Flags indicating information
comment|// about C++ flavor.
name|DT_MIPS_PIXIE_INIT
init|=
literal|0x70000023
block|,
comment|// Pixie information.
name|DT_MIPS_SYMBOL_LIB
init|=
literal|0x70000024
block|,
comment|// Address of .MIPS.symlib
name|DT_MIPS_LOCALPAGE_GOTIDX
init|=
literal|0x70000025
block|,
comment|// The GOT index of the first PTE
comment|// for a segment
name|DT_MIPS_LOCAL_GOTIDX
init|=
literal|0x70000026
block|,
comment|// The GOT index of the first PTE
comment|// for a local symbol
name|DT_MIPS_HIDDEN_GOTIDX
init|=
literal|0x70000027
block|,
comment|// The GOT index of the first PTE
comment|// for a hidden symbol
name|DT_MIPS_PROTECTED_GOTIDX
init|=
literal|0x70000028
block|,
comment|// The GOT index of the first PTE
comment|// for a protected symbol
name|DT_MIPS_OPTIONS
init|=
literal|0x70000029
block|,
comment|// Address of `.MIPS.options'.
name|DT_MIPS_INTERFACE
init|=
literal|0x7000002A
block|,
comment|// Address of `.interface'.
name|DT_MIPS_DYNSTR_ALIGN
init|=
literal|0x7000002B
block|,
comment|// Unknown.
name|DT_MIPS_INTERFACE_SIZE
init|=
literal|0x7000002C
block|,
comment|// Size of the .interface section.
name|DT_MIPS_RLD_TEXT_RESOLVE_ADDR
init|=
literal|0x7000002D
block|,
comment|// Size of rld_text_resolve
comment|// function stored in the GOT.
name|DT_MIPS_PERF_SUFFIX
init|=
literal|0x7000002E
block|,
comment|// Default suffix of DSO to be added
comment|// by rld on dlopen() calls.
name|DT_MIPS_COMPACT_SIZE
init|=
literal|0x7000002F
block|,
comment|// Size of compact relocation
comment|// section (O32).
name|DT_MIPS_GP_VALUE
init|=
literal|0x70000030
block|,
comment|// GP value for auxiliary GOTs.
name|DT_MIPS_AUX_DYNAMIC
init|=
literal|0x70000031
block|,
comment|// Address of auxiliary .dynamic.
name|DT_MIPS_PLTGOT
init|=
literal|0x70000032
block|,
comment|// Address of the base of the PLTGOT.
name|DT_MIPS_RWPLT
init|=
literal|0x70000034
comment|// Points to the base
comment|// of a writable PLT.
block|}
enum|;
comment|// DT_FLAGS values.
enum|enum
block|{
name|DF_ORIGIN
init|=
literal|0x01
block|,
comment|// The object may reference $ORIGIN.
name|DF_SYMBOLIC
init|=
literal|0x02
block|,
comment|// Search the shared lib before searching the exe.
name|DF_TEXTREL
init|=
literal|0x04
block|,
comment|// Relocations may modify a non-writable segment.
name|DF_BIND_NOW
init|=
literal|0x08
block|,
comment|// Process all relocations on load.
name|DF_STATIC_TLS
init|=
literal|0x10
comment|// Reject attempts to load dynamically.
block|}
enum|;
comment|// State flags selectable in the `d_un.d_val' element of the DT_FLAGS_1 entry.
enum|enum
block|{
name|DF_1_NOW
init|=
literal|0x00000001
block|,
comment|// Set RTLD_NOW for this object.
name|DF_1_GLOBAL
init|=
literal|0x00000002
block|,
comment|// Set RTLD_GLOBAL for this object.
name|DF_1_GROUP
init|=
literal|0x00000004
block|,
comment|// Set RTLD_GROUP for this object.
name|DF_1_NODELETE
init|=
literal|0x00000008
block|,
comment|// Set RTLD_NODELETE for this object.
name|DF_1_LOADFLTR
init|=
literal|0x00000010
block|,
comment|// Trigger filtee loading at runtime.
name|DF_1_INITFIRST
init|=
literal|0x00000020
block|,
comment|// Set RTLD_INITFIRST for this object.
name|DF_1_NOOPEN
init|=
literal|0x00000040
block|,
comment|// Set RTLD_NOOPEN for this object.
name|DF_1_ORIGIN
init|=
literal|0x00000080
block|,
comment|// $ORIGIN must be handled.
name|DF_1_DIRECT
init|=
literal|0x00000100
block|,
comment|// Direct binding enabled.
name|DF_1_TRANS
init|=
literal|0x00000200
block|,
name|DF_1_INTERPOSE
init|=
literal|0x00000400
block|,
comment|// Object is used to interpose.
name|DF_1_NODEFLIB
init|=
literal|0x00000800
block|,
comment|// Ignore default lib search path.
name|DF_1_NODUMP
init|=
literal|0x00001000
block|,
comment|// Object can't be dldump'ed.
name|DF_1_CONFALT
init|=
literal|0x00002000
block|,
comment|// Configuration alternative created.
name|DF_1_ENDFILTEE
init|=
literal|0x00004000
block|,
comment|// Filtee terminates filters search.
name|DF_1_DISPRELDNE
init|=
literal|0x00008000
block|,
comment|// Disp reloc applied at build time.
name|DF_1_DISPRELPND
init|=
literal|0x00010000
comment|// Disp reloc applied at run-time.
block|}
enum|;
comment|// DT_MIPS_FLAGS values.
enum|enum
block|{
name|RHF_NONE
init|=
literal|0x00000000
block|,
comment|// No flags.
name|RHF_QUICKSTART
init|=
literal|0x00000001
block|,
comment|// Uses shortcut pointers.
name|RHF_NOTPOT
init|=
literal|0x00000002
block|,
comment|// Hash size is not a power of two.
name|RHS_NO_LIBRARY_REPLACEMENT
init|=
literal|0x00000004
block|,
comment|// Ignore LD_LIBRARY_PATH.
name|RHF_NO_MOVE
init|=
literal|0x00000008
block|,
comment|// DSO address may not be relocated.
name|RHF_SGI_ONLY
init|=
literal|0x00000010
block|,
comment|// SGI specific features.
name|RHF_GUARANTEE_INIT
init|=
literal|0x00000020
block|,
comment|// Guarantee that .init will finish
comment|// executing before any non-init
comment|// code in DSO is called.
name|RHF_DELTA_C_PLUS_PLUS
init|=
literal|0x00000040
block|,
comment|// Contains Delta C++ code.
name|RHF_GUARANTEE_START_INIT
init|=
literal|0x00000080
block|,
comment|// Guarantee that .init will start
comment|// executing before any non-init
comment|// code in DSO is called.
name|RHF_PIXIE
init|=
literal|0x00000100
block|,
comment|// Generated by pixie.
name|RHF_DEFAULT_DELAY_LOAD
init|=
literal|0x00000200
block|,
comment|// Delay-load DSO by default.
name|RHF_REQUICKSTART
init|=
literal|0x00000400
block|,
comment|// Object may be requickstarted
name|RHF_REQUICKSTARTED
init|=
literal|0x00000800
block|,
comment|// Object has been requickstarted
name|RHF_CORD
init|=
literal|0x00001000
block|,
comment|// Generated by cord.
name|RHF_NO_UNRES_UNDEF
init|=
literal|0x00002000
block|,
comment|// Object contains no unresolved
comment|// undef symbols.
name|RHF_RLD_ORDER_SAFE
init|=
literal|0x00004000
comment|// Symbol table is in a safe order.
block|}
enum|;
comment|// ElfXX_VerDef structure version (GNU versioning)
enum|enum
block|{
name|VER_DEF_NONE
init|=
literal|0
block|,
name|VER_DEF_CURRENT
init|=
literal|1
block|}
enum|;
comment|// VerDef Flags (ElfXX_VerDef::vd_flags)
enum|enum
block|{
name|VER_FLG_BASE
init|=
literal|0x1
block|,
name|VER_FLG_WEAK
init|=
literal|0x2
block|,
name|VER_FLG_INFO
init|=
literal|0x4
block|}
enum|;
comment|// Special constants for the version table. (SHT_GNU_versym/.gnu.version)
enum|enum
block|{
name|VER_NDX_LOCAL
init|=
literal|0
block|,
comment|// Unversioned local symbol
name|VER_NDX_GLOBAL
init|=
literal|1
block|,
comment|// Unversioned global symbol
name|VERSYM_VERSION
init|=
literal|0x7fff
block|,
comment|// Version Index mask
name|VERSYM_HIDDEN
init|=
literal|0x8000
comment|// Hidden bit (non-default version)
block|}
enum|;
comment|// ElfXX_VerNeed structure version (GNU versioning)
enum|enum
block|{
name|VER_NEED_NONE
init|=
literal|0
block|,
name|VER_NEED_CURRENT
init|=
literal|1
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

