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
comment|// See current registered ELF machine architectures at:
comment|//    http://www.uxsglobal.com/developers/gabi/latest/ch4.eheader.html
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
name|EM_IAMCU
init|=
literal|6
block|,
comment|// Intel MCU
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
block|,
comment|// Freescale 56800EX Digital Signal Controller (DSC)
name|EM_BA1
init|=
literal|201
block|,
comment|// Beyond BA1 CPU architecture
name|EM_BA2
init|=
literal|202
block|,
comment|// Beyond BA2 CPU architecture
name|EM_XCORE
init|=
literal|203
block|,
comment|// XMOS xCORE processor family
name|EM_MCHP_PIC
init|=
literal|204
block|,
comment|// Microchip 8-bit PIC(r) family
name|EM_INTEL205
init|=
literal|205
block|,
comment|// Reserved by Intel
name|EM_INTEL206
init|=
literal|206
block|,
comment|// Reserved by Intel
name|EM_INTEL207
init|=
literal|207
block|,
comment|// Reserved by Intel
name|EM_INTEL208
init|=
literal|208
block|,
comment|// Reserved by Intel
name|EM_INTEL209
init|=
literal|209
block|,
comment|// Reserved by Intel
name|EM_KM32
init|=
literal|210
block|,
comment|// KM211 KM32 32-bit processor
name|EM_KMX32
init|=
literal|211
block|,
comment|// KM211 KMX32 32-bit processor
name|EM_KMX16
init|=
literal|212
block|,
comment|// KM211 KMX16 16-bit processor
name|EM_KMX8
init|=
literal|213
block|,
comment|// KM211 KMX8 8-bit processor
name|EM_KVARC
init|=
literal|214
block|,
comment|// KM211 KVARC processor
name|EM_CDP
init|=
literal|215
block|,
comment|// Paneve CDP architecture family
name|EM_COGE
init|=
literal|216
block|,
comment|// Cognitive Smart Memory Processor
name|EM_COOL
init|=
literal|217
block|,
comment|// iCelero CoolEngine
name|EM_NORC
init|=
literal|218
block|,
comment|// Nanoradio Optimized RISC
name|EM_CSR_KALIMBA
init|=
literal|219
block|,
comment|// CSR Kalimba architecture family
name|EM_AMDGPU
init|=
literal|224
block|,
comment|// AMD GPU architecture
name|EM_RISCV
init|=
literal|243
block|,
comment|// RISC-V
name|EM_LANAI
init|=
literal|244
block|,
comment|// Lanai 32-bit processor
name|EM_BPF
init|=
literal|247
block|,
comment|// Linux kernel bpf virtual machine
comment|// A request has been made to the maintainer of the official registry for
comment|// such numbers for an official value for WebAssembly. As soon as one is
comment|// allocated, this enum will be updated to use it.
name|EM_WEBASSEMBLY
init|=
literal|0x4157
block|,
comment|// WebAssembly architecture
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
name|ELFOSABI_CLOUDABI
init|=
literal|17
block|,
comment|// Nuxi CloudABI
name|ELFOSABI_C6000_ELFABI
init|=
literal|64
block|,
comment|// Bare-metal TMS320C6000
name|ELFOSABI_AMDGPU_HSA
init|=
literal|64
block|,
comment|// AMD HSA runtime
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
define|#
directive|define
name|ELF_RELOC
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
value|name = value,
comment|// X86_64 relocations.
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/x86_64.def"
block|}
enum|;
comment|// i386 relocations.
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/i386.def"
block|}
enum|;
comment|// ELF Relocation types for PPC32
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/PowerPC.def"
block|}
enum|;
comment|// Specific e_flags for PPC64
enum|enum
block|{
comment|// e_flags bits specifying ABI:
comment|// 1 for original ABI using function descriptors,
comment|// 2 for revised ABI without function descriptors,
comment|// 0 for unspecified or not using any features affected by the differences.
name|EF_PPC64_ABI
init|=
literal|3
block|}
enum|;
comment|// Special values for the st_other field in the symbol table entry for PPC64.
enum|enum
block|{
name|STO_PPC64_LOCAL_BIT
init|=
literal|5
block|,
name|STO_PPC64_LOCAL_MASK
init|=
operator|(
literal|7
operator|<<
name|STO_PPC64_LOCAL_BIT
operator|)
block|}
enum|;
specifier|static
specifier|inline
name|int64_t
name|decodePPC64LocalEntryOffset
parameter_list|(
name|unsigned
name|Other
parameter_list|)
block|{
name|unsigned
name|Val
init|=
operator|(
name|Other
operator|&
name|STO_PPC64_LOCAL_MASK
operator|)
operator|>>
name|STO_PPC64_LOCAL_BIT
decl_stmt|;
return|return
operator|(
operator|(
literal|1
operator|<<
name|Val
operator|)
operator|>>
literal|2
operator|)
operator|<<
literal|2
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|encodePPC64LocalEntryOffset
parameter_list|(
name|int64_t
name|Offset
parameter_list|)
block|{
name|unsigned
name|Val
init|=
operator|(
name|Offset
operator|>=
literal|4
operator|*
literal|4
condition|?
operator|(
name|Offset
operator|>=
literal|8
operator|*
literal|4
condition|?
operator|(
name|Offset
operator|>=
literal|16
operator|*
literal|4
condition|?
literal|6
else|:
literal|5
operator|)
else|:
literal|4
operator|)
else|:
operator|(
name|Offset
operator|>=
literal|2
operator|*
literal|4
condition|?
literal|3
else|:
operator|(
name|Offset
operator|>=
literal|1
operator|*
literal|4
condition|?
literal|2
else|:
literal|0
operator|)
operator|)
operator|)
decl_stmt|;
return|return
name|Val
operator|<<
name|STO_PPC64_LOCAL_BIT
return|;
block|}
comment|// ELF Relocation types for PPC64
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/PowerPC64.def"
block|}
enum|;
comment|// ELF Relocation types for AArch64
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/AArch64.def"
block|}
enum|;
comment|// ARM Specific e_flags
enum_decl|enum :
name|unsigned
block|{
name|EF_ARM_SOFT_FLOAT
init|=
literal|0x00000200U
block|,
name|EF_ARM_VFP_FLOAT
init|=
literal|0x00000400U
block|,
name|EF_ARM_EABI_UNKNOWN
init|=
literal|0x00000000U
block|,
name|EF_ARM_EABI_VER1
init|=
literal|0x01000000U
block|,
name|EF_ARM_EABI_VER2
init|=
literal|0x02000000U
block|,
name|EF_ARM_EABI_VER3
init|=
literal|0x03000000U
block|,
name|EF_ARM_EABI_VER4
init|=
literal|0x04000000U
block|,
name|EF_ARM_EABI_VER5
init|=
literal|0x05000000U
block|,
name|EF_ARM_EABIMASK
init|=
literal|0xFF000000U
block|}
enum_decl|;
comment|// ELF Relocation types for ARM
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/ARM.def"
block|}
enum|;
comment|// AVR specific e_flags
enum_decl|enum :
name|unsigned
block|{
name|EF_AVR_ARCH_AVR1
init|=
literal|1
block|,
name|EF_AVR_ARCH_AVR2
init|=
literal|2
block|,
name|EF_AVR_ARCH_AVR25
init|=
literal|25
block|,
name|EF_AVR_ARCH_AVR3
init|=
literal|3
block|,
name|EF_AVR_ARCH_AVR31
init|=
literal|31
block|,
name|EF_AVR_ARCH_AVR35
init|=
literal|35
block|,
name|EF_AVR_ARCH_AVR4
init|=
literal|4
block|,
name|EF_AVR_ARCH_AVR5
init|=
literal|5
block|,
name|EF_AVR_ARCH_AVR51
init|=
literal|51
block|,
name|EF_AVR_ARCH_AVR6
init|=
literal|6
block|,
name|EF_AVR_ARCH_AVRTINY
init|=
literal|100
block|,
name|EF_AVR_ARCH_XMEGA1
init|=
literal|101
block|,
name|EF_AVR_ARCH_XMEGA2
init|=
literal|102
block|,
name|EF_AVR_ARCH_XMEGA3
init|=
literal|103
block|,
name|EF_AVR_ARCH_XMEGA4
init|=
literal|104
block|,
name|EF_AVR_ARCH_XMEGA5
init|=
literal|105
block|,
name|EF_AVR_ARCH_XMEGA6
init|=
literal|106
block|,
name|EF_AVR_ARCH_XMEGA7
init|=
literal|107
block|}
enum_decl|;
comment|// ELF Relocation types for AVR
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/AVR.def"
block|}
enum|;
comment|// Mips Specific e_flags
enum_decl|enum :
name|unsigned
block|{
name|EF_MIPS_NOREORDER
init|=
literal|0x00000001
block|,
comment|// Don't reorder instructions
name|EF_MIPS_PIC
init|=
literal|0x00000002
block|,
comment|// Position independent code
name|EF_MIPS_CPIC
init|=
literal|0x00000004
block|,
comment|// Call object with Position independent code
name|EF_MIPS_ABI2
init|=
literal|0x00000020
block|,
comment|// File uses N32 ABI
name|EF_MIPS_32BITMODE
init|=
literal|0x00000100
block|,
comment|// Code compiled for a 64-bit machine
comment|// in 32-bit mode
name|EF_MIPS_FP64
init|=
literal|0x00000200
block|,
comment|// Code compiled for a 32-bit machine
comment|// but uses 64-bit FP registers
name|EF_MIPS_NAN2008
init|=
literal|0x00000400
block|,
comment|// Uses IEE 754-2008 NaN encoding
comment|// ABI flags
name|EF_MIPS_ABI_O32
init|=
literal|0x00001000
block|,
comment|// This file follows the first MIPS 32 bit ABI
name|EF_MIPS_ABI_O64
init|=
literal|0x00002000
block|,
comment|// O32 ABI extended for 64-bit architecture.
name|EF_MIPS_ABI_EABI32
init|=
literal|0x00003000
block|,
comment|// EABI in 32 bit mode.
name|EF_MIPS_ABI_EABI64
init|=
literal|0x00004000
block|,
comment|// EABI in 64 bit mode.
name|EF_MIPS_ABI
init|=
literal|0x0000f000
block|,
comment|// Mask for selecting EF_MIPS_ABI_ variant.
comment|// MIPS machine variant
name|EF_MIPS_MACH_NONE
init|=
literal|0x00000000
block|,
comment|// A standard MIPS implementation.
name|EF_MIPS_MACH_3900
init|=
literal|0x00810000
block|,
comment|// Toshiba R3900
name|EF_MIPS_MACH_4010
init|=
literal|0x00820000
block|,
comment|// LSI R4010
name|EF_MIPS_MACH_4100
init|=
literal|0x00830000
block|,
comment|// NEC VR4100
name|EF_MIPS_MACH_4650
init|=
literal|0x00850000
block|,
comment|// MIPS R4650
name|EF_MIPS_MACH_4120
init|=
literal|0x00870000
block|,
comment|// NEC VR4120
name|EF_MIPS_MACH_4111
init|=
literal|0x00880000
block|,
comment|// NEC VR4111/VR4181
name|EF_MIPS_MACH_SB1
init|=
literal|0x008a0000
block|,
comment|// Broadcom SB-1
name|EF_MIPS_MACH_OCTEON
init|=
literal|0x008b0000
block|,
comment|// Cavium Networks Octeon
name|EF_MIPS_MACH_XLR
init|=
literal|0x008c0000
block|,
comment|// RMI Xlr
name|EF_MIPS_MACH_OCTEON2
init|=
literal|0x008d0000
block|,
comment|// Cavium Networks Octeon2
name|EF_MIPS_MACH_OCTEON3
init|=
literal|0x008e0000
block|,
comment|// Cavium Networks Octeon3
name|EF_MIPS_MACH_5400
init|=
literal|0x00910000
block|,
comment|// NEC VR5400
name|EF_MIPS_MACH_5900
init|=
literal|0x00920000
block|,
comment|// MIPS R5900
name|EF_MIPS_MACH_5500
init|=
literal|0x00980000
block|,
comment|// NEC VR5500
name|EF_MIPS_MACH_9000
init|=
literal|0x00990000
block|,
comment|// Unknown
name|EF_MIPS_MACH_LS2E
init|=
literal|0x00a00000
block|,
comment|// ST Microelectronics Loongson 2E
name|EF_MIPS_MACH_LS2F
init|=
literal|0x00a10000
block|,
comment|// ST Microelectronics Loongson 2F
name|EF_MIPS_MACH_LS3A
init|=
literal|0x00a20000
block|,
comment|// Loongson 3A
name|EF_MIPS_MACH
init|=
literal|0x00ff0000
block|,
comment|// EF_MIPS_MACH_xxx selection mask
comment|// ARCH_ASE
name|EF_MIPS_MICROMIPS
init|=
literal|0x02000000
block|,
comment|// microMIPS
name|EF_MIPS_ARCH_ASE_M16
init|=
literal|0x04000000
block|,
comment|// Has Mips-16 ISA extensions
name|EF_MIPS_ARCH_ASE_MDMX
init|=
literal|0x08000000
block|,
comment|// Has MDMX multimedia extensions
name|EF_MIPS_ARCH_ASE
init|=
literal|0x0f000000
block|,
comment|// Mask for EF_MIPS_ARCH_ASE_xxx flags
comment|// ARCH
name|EF_MIPS_ARCH_1
init|=
literal|0x00000000
block|,
comment|// MIPS1 instruction set
name|EF_MIPS_ARCH_2
init|=
literal|0x10000000
block|,
comment|// MIPS2 instruction set
name|EF_MIPS_ARCH_3
init|=
literal|0x20000000
block|,
comment|// MIPS3 instruction set
name|EF_MIPS_ARCH_4
init|=
literal|0x30000000
block|,
comment|// MIPS4 instruction set
name|EF_MIPS_ARCH_5
init|=
literal|0x40000000
block|,
comment|// MIPS5 instruction set
name|EF_MIPS_ARCH_32
init|=
literal|0x50000000
block|,
comment|// MIPS32 instruction set per linux not elf.h
name|EF_MIPS_ARCH_64
init|=
literal|0x60000000
block|,
comment|// MIPS64 instruction set per linux not elf.h
name|EF_MIPS_ARCH_32R2
init|=
literal|0x70000000
block|,
comment|// mips32r2, mips32r3, mips32r5
name|EF_MIPS_ARCH_64R2
init|=
literal|0x80000000
block|,
comment|// mips64r2, mips64r3, mips64r5
name|EF_MIPS_ARCH_32R6
init|=
literal|0x90000000
block|,
comment|// mips32r6
name|EF_MIPS_ARCH_64R6
init|=
literal|0xa0000000
block|,
comment|// mips64r6
name|EF_MIPS_ARCH
init|=
literal|0xf0000000
comment|// Mask for applying EF_MIPS_ARCH_ variant
block|}
enum_decl|;
comment|// ELF Relocation types for Mips
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/Mips.def"
block|}
enum|;
comment|// Special values for the st_other field in the symbol table entry for MIPS.
enum|enum
block|{
name|STO_MIPS_OPTIONAL
init|=
literal|0x04
block|,
comment|// Symbol whose definition is optional
name|STO_MIPS_PLT
init|=
literal|0x08
block|,
comment|// PLT entry related dynamic table record
name|STO_MIPS_PIC
init|=
literal|0x20
block|,
comment|// PIC func in an object mixes PIC/non-PIC
name|STO_MIPS_MICROMIPS
init|=
literal|0x80
block|,
comment|// MIPS Specific ISA for MicroMips
name|STO_MIPS_MIPS16
init|=
literal|0xf0
comment|// MIPS Specific ISA for Mips16
block|}
enum|;
comment|// .MIPS.options section descriptor kinds
enum|enum
block|{
name|ODK_NULL
init|=
literal|0
block|,
comment|// Undefined
name|ODK_REGINFO
init|=
literal|1
block|,
comment|// Register usage information
name|ODK_EXCEPTIONS
init|=
literal|2
block|,
comment|// Exception processing options
name|ODK_PAD
init|=
literal|3
block|,
comment|// Section padding options
name|ODK_HWPATCH
init|=
literal|4
block|,
comment|// Hardware patches applied
name|ODK_FILL
init|=
literal|5
block|,
comment|// Linker fill value
name|ODK_TAGS
init|=
literal|6
block|,
comment|// Space for tool identification
name|ODK_HWAND
init|=
literal|7
block|,
comment|// Hardware AND patches applied
name|ODK_HWOR
init|=
literal|8
block|,
comment|// Hardware OR patches applied
name|ODK_GP_GROUP
init|=
literal|9
block|,
comment|// GP group to use for text/data sections
name|ODK_IDENT
init|=
literal|10
block|,
comment|// ID information
name|ODK_PAGESIZE
init|=
literal|11
comment|// Page size information
block|}
enum|;
comment|// Hexagon-specific e_flags
enum|enum
block|{
comment|// Object processor version flags, bits[11:0]
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
name|EF_HEXAGON_MACH_V55
init|=
literal|0x00000005
block|,
comment|// Hexagon V55
name|EF_HEXAGON_MACH_V60
init|=
literal|0x00000060
block|,
comment|// Hexagon V60
name|EF_HEXAGON_MACH_V62
init|=
literal|0x00000062
block|,
comment|// Hexagon V62
comment|// Highest ISA version flags
name|EF_HEXAGON_ISA_MACH
init|=
literal|0x00000000
block|,
comment|// Same as specified in bits[11:0]
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
block|,
comment|// Hexagon V5 ISA
name|EF_HEXAGON_ISA_V55
init|=
literal|0x00000050
block|,
comment|// Hexagon V55 ISA
name|EF_HEXAGON_ISA_V60
init|=
literal|0x00000060
block|,
comment|// Hexagon V60 ISA
name|EF_HEXAGON_ISA_V62
init|=
literal|0x00000062
block|,
comment|// Hexagon V62 ISA
block|}
enum|;
comment|// Hexagon-specific section indexes for common small data
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
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/Hexagon.def"
block|}
enum|;
comment|// ELF Relocation type for Lanai.
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/Lanai.def"
block|}
enum|;
comment|// ELF Relocation types for RISC-V
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/RISCV.def"
block|}
enum|;
comment|// ELF Relocation types for S390/zSeries
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/SystemZ.def"
block|}
enum|;
comment|// ELF Relocation type for Sparc.
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/Sparc.def"
block|}
enum|;
comment|// ELF Relocation types for WebAssembly
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/WebAssembly.def"
block|}
enum|;
comment|// ELF Relocation types for AMDGPU
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/AMDGPU.def"
block|}
enum|;
comment|// ELF Relocation types for BPF
enum|enum
block|{
include|#
directive|include
file|"ELFRelocs/BPF.def"
block|}
enum|;
undef|#
directive|undef
name|ELF_RELOC
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
enum_decl|enum :
name|unsigned
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
comment|// Pointers to initialization functions.
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
comment|// Indices for SHN_XINDEX entries.
name|SHT_LOOS
init|=
literal|0x60000000
block|,
comment|// Lowest operating system-specific type.
name|SHT_GNU_ATTRIBUTES
init|=
literal|0x6ffffff5
block|,
comment|// Object attributes.
name|SHT_GNU_HASH
init|=
literal|0x6ffffff6
block|,
comment|// GNU-style hash table.
name|SHT_GNU_verdef
init|=
literal|0x6ffffffd
block|,
comment|// GNU version definitions.
name|SHT_GNU_verneed
init|=
literal|0x6ffffffe
block|,
comment|// GNU version references.
name|SHT_GNU_versym
init|=
literal|0x6fffffff
block|,
comment|// GNU symbol versions table.
name|SHT_HIOS
init|=
literal|0x6fffffff
block|,
comment|// Highest operating system-specific type.
name|SHT_LOPROC
init|=
literal|0x70000000
block|,
comment|// Lowest processor arch-specific type.
comment|// Fixme: All this is duplicated in MCSectionELF. Why??
comment|// Exception Index table
name|SHT_ARM_EXIDX
init|=
literal|0x70000001U
block|,
comment|// BPABI DLL dynamic linking pre-emption map
name|SHT_ARM_PREEMPTMAP
init|=
literal|0x70000002U
block|,
comment|//  Object file compatibility attributes
name|SHT_ARM_ATTRIBUTES
init|=
literal|0x70000003U
block|,
name|SHT_ARM_DEBUGOVERLAY
init|=
literal|0x70000004U
block|,
name|SHT_ARM_OVERLAYSECTION
init|=
literal|0x70000005U
block|,
name|SHT_HEX_ORDERED
init|=
literal|0x70000000
block|,
comment|// Link editor is to sort the entries in
comment|// this section based on their sizes
name|SHT_X86_64_UNWIND
init|=
literal|0x70000001
block|,
comment|// Unwind information
name|SHT_MIPS_REGINFO
init|=
literal|0x70000006
block|,
comment|// Register usage information
name|SHT_MIPS_OPTIONS
init|=
literal|0x7000000d
block|,
comment|// General options
name|SHT_MIPS_DWARF
init|=
literal|0x7000001e
block|,
comment|// DWARF debugging section.
name|SHT_MIPS_ABIFLAGS
init|=
literal|0x7000002a
block|,
comment|// ABI information.
name|SHT_HIPROC
init|=
literal|0x7fffffff
block|,
comment|// Highest processor arch-specific type.
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
enum_decl|;
comment|// Section flags.
enum_decl|enum :
name|unsigned
block|{
comment|// Section data should be writable during execution.
name|SHF_WRITE
init|=
literal|0x1
block|,
comment|// Section occupies memory during program execution.
name|SHF_ALLOC
init|=
literal|0x2
block|,
comment|// Section contains executable machine instructions.
name|SHF_EXECINSTR
init|=
literal|0x4
block|,
comment|// The data in this section may be merged.
name|SHF_MERGE
init|=
literal|0x10
block|,
comment|// The data in this section is null-terminated strings.
name|SHF_STRINGS
init|=
literal|0x20
block|,
comment|// A field in this section holds a section header table index.
name|SHF_INFO_LINK
init|=
literal|0x40U
block|,
comment|// Adds special ordering requirements for link editors.
name|SHF_LINK_ORDER
init|=
literal|0x80U
block|,
comment|// This section requires special OS-specific processing to avoid incorrect
comment|// behavior.
name|SHF_OS_NONCONFORMING
init|=
literal|0x100U
block|,
comment|// This section is a member of a section group.
name|SHF_GROUP
init|=
literal|0x200U
block|,
comment|// This section holds Thread-Local Storage.
name|SHF_TLS
init|=
literal|0x400U
block|,
comment|// Identifies a section containing compressed data.
name|SHF_COMPRESSED
init|=
literal|0x800U
block|,
comment|// This section is excluded from the final executable or shared library.
name|SHF_EXCLUDE
init|=
literal|0x80000000U
block|,
comment|// Start of target-specific flags.
name|SHF_MASKOS
init|=
literal|0x0ff00000
block|,
comment|// Bits indicating processor-specific flags.
name|SHF_MASKPROC
init|=
literal|0xf0000000
block|,
comment|/// All sections with the "d" flag are grouped together by the linker to form
comment|/// the data section and the dp register is set to the start of the section by
comment|/// the boot code.
name|XCORE_SHF_DP_SECTION
init|=
literal|0x10000000
block|,
comment|/// All sections with the "c" flag are grouped together by the linker to form
comment|/// the constant pool and the cp register is set to the start of the constant
comment|/// pool by the boot code.
name|XCORE_SHF_CP_SECTION
init|=
literal|0x20000000
block|,
comment|// If an object file section does not have this flag set, then it may not hold
comment|// more than 2GB and can be freely referred to in objects using smaller code
comment|// models. Otherwise, only objects using larger code models can refer to them.
comment|// For example, a medium code model object can refer to data in a section that
comment|// sets this flag besides being able to refer to data in a section that does
comment|// not set it; likewise, a small code model object can refer only to code in a
comment|// section that does not set this flag.
name|SHF_X86_64_LARGE
init|=
literal|0x10000000
block|,
comment|// All sections with the GPREL flag are grouped into a global data area
comment|// for faster accesses
name|SHF_HEX_GPREL
init|=
literal|0x10000000
block|,
comment|// Section contains text/data which may be replicated in other sections.
comment|// Linker must retain only one copy.
name|SHF_MIPS_NODUPES
init|=
literal|0x01000000
block|,
comment|// Linker must generate implicit hidden weak names.
name|SHF_MIPS_NAMES
init|=
literal|0x02000000
block|,
comment|// Section data local to process.
name|SHF_MIPS_LOCAL
init|=
literal|0x04000000
block|,
comment|// Do not strip this section.
name|SHF_MIPS_NOSTRIP
init|=
literal|0x08000000
block|,
comment|// Section must be part of global data area.
name|SHF_MIPS_GPREL
init|=
literal|0x10000000
block|,
comment|// This section should be merged.
name|SHF_MIPS_MERGE
init|=
literal|0x20000000
block|,
comment|// Address size to be inferred from section entry size.
name|SHF_MIPS_ADDR
init|=
literal|0x40000000
block|,
comment|// Section data is string data by default.
name|SHF_MIPS_STRING
init|=
literal|0x80000000
block|,
comment|// Make code section unreadable when in execute-only mode
name|SHF_ARM_PURECODE
init|=
literal|0x20000000
block|,
name|SHF_AMDGPU_HSA_GLOBAL
init|=
literal|0x00100000
block|,
name|SHF_AMDGPU_HSA_READONLY
init|=
literal|0x00200000
block|,
name|SHF_AMDGPU_HSA_CODE
init|=
literal|0x00400000
block|,
name|SHF_AMDGPU_HSA_AGENT
init|=
literal|0x00800000
block|}
enum_decl|;
comment|// Section Group Flags
enum_decl|enum :
name|unsigned
block|{
name|GRP_COMDAT
init|=
literal|0x1
block|,
name|GRP_MASKOS
init|=
literal|0x0ff00000
block|,
name|GRP_MASKPROC
init|=
literal|0xf0000000
block|}
enum_decl|;
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
name|STB_GNU_UNIQUE
init|=
literal|10
block|,
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
name|STT_GNU_IFUNC
init|=
literal|10
block|,
comment|// GNU indirect function
name|STT_LOOS
init|=
literal|10
block|,
comment|// Lowest operating system-specific symbol type
name|STT_HIOS
init|=
literal|12
block|,
comment|// Highest operating system-specific symbol type
name|STT_LOPROC
init|=
literal|13
block|,
comment|// Lowest processor-specific symbol type
name|STT_HIPROC
init|=
literal|15
block|,
comment|// Highest processor-specific symbol type
comment|// AMDGPU symbol types
name|STT_AMDGPU_HSA_KERNEL
init|=
literal|10
block|,
name|STT_AMDGPU_HSA_INDIRECT_FUNCTION
init|=
literal|11
block|,
name|STT_AMDGPU_HSA_METADATA
init|=
literal|12
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
comment|// Special relocation symbols used in the MIPS64 ELF relocation entries
enum|enum
block|{
name|RSS_UNDEF
init|=
literal|0
block|,
comment|// None
name|RSS_GP
init|=
literal|1
block|,
comment|// Value of gp
name|RSS_GP0
init|=
literal|2
block|,
comment|// Value of gp used to create object being relocated
name|RSS_LOC
init|=
literal|3
comment|// Address of location being relocated
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
name|PT_OPENBSD_RANDOMIZE
init|=
literal|0x65a3dbe6
block|,
comment|// Fill with random data.
name|PT_OPENBSD_WXNEEDED
init|=
literal|0x65a3dbe7
block|,
comment|// Program does W^X violations.
name|PT_OPENBSD_BOOTDATA
init|=
literal|0x65a41be6
block|,
comment|// Section for boot arguments.
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
block|,
comment|// Options segment.
name|PT_MIPS_ABIFLAGS
init|=
literal|0x70000003
block|,
comment|// Abiflags segment.
comment|// AMDGPU program header types.
name|PT_AMDGPU_HSA_LOAD_GLOBAL_PROGRAM
init|=
literal|0x60000000
block|,
name|PT_AMDGPU_HSA_LOAD_GLOBAL_AGENT
init|=
literal|0x60000001
block|,
name|PT_AMDGPU_HSA_LOAD_READONLY_AGENT
init|=
literal|0x60000002
block|,
name|PT_AMDGPU_HSA_LOAD_CODE_AGENT
init|=
literal|0x60000003
block|,
comment|// WebAssembly program header types.
name|PT_WEBASSEMBLY_FUNCTIONS
init|=
name|PT_LOPROC
operator|+
literal|0
block|,
comment|// Function definitions.
block|}
enum|;
comment|// Segment flag bits.
enum_decl|enum :
name|unsigned
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
name|PF_MASKOS
init|=
literal|0x0ff00000
block|,
comment|// Bits for operating system-specific semantics.
name|PF_MASKPROC
init|=
literal|0xf0000000
comment|// Bits for processor-specific semantics.
block|}
enum_decl|;
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
name|DT_GNU_HASH
init|=
literal|0x6FFFFEF5
block|,
comment|// Reference to the GNU hash table.
name|DT_TLSDESC_PLT
init|=
literal|0x6FFFFEF6
block|,
comment|// Location of PLT entry for TLS descriptor resolver calls.
name|DT_TLSDESC_GOT
init|=
literal|0x6FFFFEF7
block|,
comment|// Location of GOT entry used by TLS descriptor
comment|// resolver PLT entry.
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
comment|// Hexagon specific dynamic table entries
name|DT_HEXAGON_SYMSZ
init|=
literal|0x70000000
block|,
name|DT_HEXAGON_VER
init|=
literal|0x70000001
block|,
name|DT_HEXAGON_PLT
init|=
literal|0x70000002
block|,
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
block|,
comment|// Points to the base
comment|// of a writable PLT.
name|DT_MIPS_RLD_MAP_REL
init|=
literal|0x70000035
block|,
comment|// Relative offset of run time loader
comment|// map, used for debugging.
comment|// Sun machine-independent extensions.
name|DT_AUXILIARY
init|=
literal|0x7FFFFFFD
block|,
comment|// Shared object to load before self
name|DT_FILTER
init|=
literal|0x7FFFFFFF
comment|// Shared object to get values from
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
block|,
comment|// Disp reloc applied at run-time.
name|DF_1_NODIRECT
init|=
literal|0x00020000
block|,
comment|// Object has no-direct binding.
name|DF_1_IGNMULDEF
init|=
literal|0x00040000
block|,
name|DF_1_NOKSYMS
init|=
literal|0x00080000
block|,
name|DF_1_NOHDR
init|=
literal|0x00100000
block|,
name|DF_1_EDITED
init|=
literal|0x00200000
block|,
comment|// Object is modified after built.
name|DF_1_NORELOC
init|=
literal|0x00400000
block|,
name|DF_1_SYMINTPOSE
init|=
literal|0x00800000
block|,
comment|// Object has individual interposers.
name|DF_1_GLOBAUDIT
init|=
literal|0x01000000
block|,
comment|// Global auditing required.
name|DF_1_SINGLETON
init|=
literal|0x02000000
comment|// Singleton symbols are used.
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
comment|// SHT_NOTE section types
enum|enum
block|{
name|NT_FREEBSD_THRMISC
init|=
literal|7
block|,
name|NT_FREEBSD_PROCSTAT_PROC
init|=
literal|8
block|,
name|NT_FREEBSD_PROCSTAT_FILES
init|=
literal|9
block|,
name|NT_FREEBSD_PROCSTAT_VMMAP
init|=
literal|10
block|,
name|NT_FREEBSD_PROCSTAT_GROUPS
init|=
literal|11
block|,
name|NT_FREEBSD_PROCSTAT_UMASK
init|=
literal|12
block|,
name|NT_FREEBSD_PROCSTAT_RLIMIT
init|=
literal|13
block|,
name|NT_FREEBSD_PROCSTAT_OSREL
init|=
literal|14
block|,
name|NT_FREEBSD_PROCSTAT_PSSTRINGS
init|=
literal|15
block|,
name|NT_FREEBSD_PROCSTAT_AUXV
init|=
literal|16
block|, }
enum|;
enum|enum
block|{
name|NT_GNU_ABI_TAG
init|=
literal|1
block|,
name|NT_GNU_HWCAP
init|=
literal|2
block|,
name|NT_GNU_BUILD_ID
init|=
literal|3
block|,
name|NT_GNU_GOLD_VERSION
init|=
literal|4
block|, }
enum|;
enum|enum
block|{
name|GNU_ABI_TAG_LINUX
init|=
literal|0
block|,
name|GNU_ABI_TAG_HURD
init|=
literal|1
block|,
name|GNU_ABI_TAG_SOLARIS
init|=
literal|2
block|,
name|GNU_ABI_TAG_FREEBSD
init|=
literal|3
block|,
name|GNU_ABI_TAG_NETBSD
init|=
literal|4
block|,
name|GNU_ABI_TAG_SYLLABLE
init|=
literal|5
block|,
name|GNU_ABI_TAG_NACL
init|=
literal|6
block|, }
enum|;
comment|// Compressed section header for ELF32.
struct|struct
name|Elf32_Chdr
block|{
name|Elf32_Word
name|ch_type
decl_stmt|;
name|Elf32_Word
name|ch_size
decl_stmt|;
name|Elf32_Word
name|ch_addralign
decl_stmt|;
block|}
struct|;
comment|// Compressed section header for ELF64.
struct|struct
name|Elf64_Chdr
block|{
name|Elf64_Word
name|ch_type
decl_stmt|;
name|Elf64_Word
name|ch_reserved
decl_stmt|;
name|Elf64_Xword
name|ch_size
decl_stmt|;
name|Elf64_Xword
name|ch_addralign
decl_stmt|;
block|}
struct|;
comment|// Legal values for ch_type field of compressed section header.
enum|enum
block|{
name|ELFCOMPRESS_ZLIB
init|=
literal|1
block|,
comment|// ZLIB/DEFLATE algorithm.
name|ELFCOMPRESS_LOOS
init|=
literal|0x60000000
block|,
comment|// Start of OS-specific.
name|ELFCOMPRESS_HIOS
init|=
literal|0x6fffffff
block|,
comment|// End of OS-specific.
name|ELFCOMPRESS_LOPROC
init|=
literal|0x70000000
block|,
comment|// Start of processor-specific.
name|ELFCOMPRESS_HIPROC
init|=
literal|0x7fffffff
comment|// End of processor-specific.
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

