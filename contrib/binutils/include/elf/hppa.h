begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HPPA ELF support for BFD.    Copyright 1993, 1994, 1995, 1998, 1999, 2000    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the HPPA ELF ABI.  Note    that most of this is not actually implemented by BFD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_HPPA_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_HPPA_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* Trap null address dereferences.  */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_TRAPNIL
value|0x00010000
end_define

begin_comment
comment|/* .PARISC.archext section is present.  */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_EXT
value|0x00020000
end_define

begin_comment
comment|/* Program expects little-endian mode.  */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_LSB
value|0x00040000
end_define

begin_comment
comment|/* Program expects wide mode.  */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_WIDE
value|0x00080000
end_define

begin_comment
comment|/* Do not allow kernel-assisted branch prediction.  */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_NO_KABP
value|0x00100000
end_define

begin_comment
comment|/* Allow lazy swap for dynamically allocated program segments.  */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_LAZYSWAP
value|0x00400000
end_define

begin_comment
comment|/* Architecture version */
end_comment

begin_define
define|#
directive|define
name|EF_PARISC_ARCH
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EFA_PARISC_1_0
value|0x020b
end_define

begin_define
define|#
directive|define
name|EFA_PARISC_1_1
value|0x0210
end_define

begin_define
define|#
directive|define
name|EFA_PARISC_2_0
value|0x0214
end_define

begin_comment
comment|/* Special section indices.  */
end_comment

begin_comment
comment|/* A symbol that has been declared as a tentative definition in an ANSI C    compilation.  */
end_comment

begin_define
define|#
directive|define
name|SHN_PARISC_ANSI_COMMON
value|0xff00
end_define

begin_comment
comment|/* A symbol that has been declared as a common block using the    huge memory model.  */
end_comment

begin_define
define|#
directive|define
name|SHN_PARISC_HUGE_COMMON
value|0xff01
end_define

begin_comment
comment|/* Processor specific section types.  */
end_comment

begin_comment
comment|/* Section contains product specific extension bits.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_EXT
value|0x70000000
end_define

begin_comment
comment|/* Section contains unwind table entries.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_UNWIND
value|0x70000001
end_define

begin_comment
comment|/* Section contains debug information for optimized code.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_DOC
value|0x70000002
end_define

begin_comment
comment|/* Section contains code annotations.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_ANNOT
value|0x70000003
end_define

begin_comment
comment|/* These are strictly for compatibility with the older elf32-hppa    implementation.  Hopefully we can eliminate them in the future.  */
end_comment

begin_comment
comment|/* Optional section holding argument location/relocation info.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_SYMEXTN
value|SHT_LOPROC+8
end_define

begin_comment
comment|/* Option section for linker stubs.  */
end_comment

begin_define
define|#
directive|define
name|SHT_PARISC_STUBS
value|SHT_LOPROC+9
end_define

begin_comment
comment|/* Processor specific section flags.  */
end_comment

begin_comment
comment|/* Section contains code compiled for static branch prediction.  */
end_comment

begin_define
define|#
directive|define
name|SHF_PARISC_SBP
value|0x80000000
end_define

begin_comment
comment|/* Section should be allocated from from GP.  */
end_comment

begin_define
define|#
directive|define
name|SHF_PARISC_HUGE
value|0x40000000
end_define

begin_comment
comment|/* Section should go near GP.  */
end_comment

begin_define
define|#
directive|define
name|SHF_PARISC_SHORT
value|0x20000000
end_define

begin_comment
comment|/* Identifies the entry point of a millicode routine.  */
end_comment

begin_define
define|#
directive|define
name|STT_PARISC_MILLI
value|13
end_define

begin_comment
comment|/* ELF/HPPA relocation types */
end_comment

begin_comment
comment|/* Note: PA-ELF is defined to use only RELA relocations.  */
end_comment

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_hppa_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* No reloc */
end_comment

begin_comment
comment|/*		Data / Inst. Format	   Relocation Expression	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR32
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/*		32-bit word            	   symbol + addend    		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR21L
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)	   LR(symbol, addend) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR17R
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/*		branch external (19)	   RR(symbol, addend) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR17F
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*		branch external (19)	   symbol + addend    		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR14R
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)		   RR(symbol, addend) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR14F
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)		   symbol, addend 		  */
end_comment

begin_comment
comment|/* PC-relative relocation types    Typically used for calls.    Note PCREL17C and PCREL17F differ only in overflow handling.    PCREL17C never reports a relocation error.     When supporting argument relocations, function calls must be    accompanied by parameter relocation information.  This information is    carried in the ten high-order bits of the addend field.  The remaining    22 bits of of the addend field are sign-extended to form the Addend.     Note the code to build argument relocations depends on the    addend being zero.  A consequence of this limitation is GAS    can not perform relocation reductions for function symbols.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL12F
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/*		op& branch (17)	   symbol - PC - 8 + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL32
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/*		32-bit word		   symbol - PC - 8 + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL21L
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)	   L(symbol - PC - 8 + addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL17R
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/*		branch external (19)	   R(symbol - PC - 8 + addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL17F
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/*		branch (20)		   symbol - PC - 8 + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL17C
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/*		branch (20)		   symbol - PC - 8 + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL14R
argument_list|,
literal|14
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)		   R(symbol - PC - 8 + addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL14F
argument_list|,
literal|15
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol - PC - 8 + addend    	  */
end_comment

begin_comment
comment|/* DP-relative relocation types.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DPREL21L
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         LR(symbol - GP, addend)  	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DPREL14WR
argument_list|,
literal|19
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  RR(symbol - GP, addend)  	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DPREL14DR
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  RR(symbol - GP, addend)  	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DPREL14R
argument_list|,
literal|22
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             RR(symbol - GP, addend)  	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DPREL14F
argument_list|,
literal|23
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol - GP + addend     	  */
end_comment

begin_comment
comment|/* Data linkage table (DLT) relocation types     SOM DLT_REL fixup requests are used to for static data references    from position-independent code within shared libraries.  They are    similar to the GOT relocation types in some SVR4 implementations.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTREL21L
argument_list|,
literal|26
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         LR(symbol - GP, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTREL14R
argument_list|,
literal|30
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             RR(symbol - GP, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTREL14F
argument_list|,
literal|31
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol - GP + addend    	  */
end_comment

begin_comment
comment|/* DLT indirect relocation types  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTIND21L
argument_list|,
literal|34
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         L(ltoff(symbol + addend)) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTIND14R
argument_list|,
literal|38
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             R(ltoff(symbol + addend)) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTIND14F
argument_list|,
literal|39
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             ltoff(symbol + addend)    	  */
end_comment

begin_comment
comment|/* Base relative relocation types.  Ugh.  These imply lots of state */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_SETBASE
argument_list|,
literal|40
argument_list|)
end_macro

begin_comment
comment|/*		none                       no reloc; base := sym     	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_SECREL32
argument_list|,
literal|41
argument_list|)
end_macro

begin_comment
comment|/*		32-bit word                symbol - SECT + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_BASEREL21L
argument_list|,
literal|42
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         LR(symbol - base, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_BASEREL17R
argument_list|,
literal|43
argument_list|)
end_macro

begin_comment
comment|/*		branch external (19)       RR(symbol - base, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_BASEREL17F
argument_list|,
literal|44
argument_list|)
end_macro

begin_comment
comment|/*		branch external (19)       symbol - base + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_BASEREL14R
argument_list|,
literal|46
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             RR(symbol - base, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_BASEREL14F
argument_list|,
literal|47
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol - base, addend     	  */
end_comment

begin_comment
comment|/* Segment relative relocation types.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_SEGBASE
argument_list|,
literal|48
argument_list|)
end_macro

begin_comment
comment|/*		none                       no relocation; SB := sym  	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_SEGREL32
argument_list|,
literal|49
argument_list|)
end_macro

begin_comment
comment|/*		32-bit word                symbol - SB + addend 	  */
end_comment

begin_comment
comment|/* Offsets from the PLT.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF21L
argument_list|,
literal|50
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         LR(pltoff(symbol), addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF14R
argument_list|,
literal|54
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             RR(pltoff(symbol), addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF14F
argument_list|,
literal|55
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             pltoff(symbol) + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR32
argument_list|,
literal|57
argument_list|)
end_macro

begin_comment
comment|/*		32-bit word                ltoff(fptr(symbol+addend))     */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR21L
argument_list|,
literal|58
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         L(ltoff(fptr(symbol+addend)))  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR14R
argument_list|,
literal|62
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             R(ltoff(fptr(symbol+addend)))  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_FPTR64
argument_list|,
literal|64
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          fptr(symbol+addend) 		  */
end_comment

begin_comment
comment|/* Plabel relocation types.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLABEL32
argument_list|,
literal|65
argument_list|)
end_macro

begin_comment
comment|/*		32-bit word	  	   fptr(symbol) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLABEL21L
argument_list|,
literal|66
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         L(fptr(symbol))		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLABEL14R
argument_list|,
literal|70
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             R(fptr(symbol))		  */
end_comment

begin_comment
comment|/* PCREL relocations.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL64
argument_list|,
literal|72
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          symbol - PC - 8 + addend       */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL22C
argument_list|,
literal|73
argument_list|)
end_macro

begin_comment
comment|/*		branch& link (21)         symbol - PC - 8 + addend       */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL22F
argument_list|,
literal|74
argument_list|)
end_macro

begin_comment
comment|/*		branch& link (21)         symbol - PC - 8 + addend       */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL14WR
argument_list|,
literal|75
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  R(symbol - PC - 8 + addend)    */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL14DR
argument_list|,
literal|76
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  R(symbol - PC - 8 + addend)    */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL16F
argument_list|,
literal|77
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol - PC - 8 + addend       */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL16WF
argument_list|,
literal|78
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  symbol - PC - 8 + addend       */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PCREL16DF
argument_list|,
literal|79
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  symbol - PC - 8 + addend       */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR64
argument_list|,
literal|80
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          symbol + addend    		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR64WR
argument_list|,
literal|81
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          RR(symbol, addend) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR64DR
argument_list|,
literal|82
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          RR(symbol, addend) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR14WR
argument_list|,
literal|83
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  RR(symbol, addend) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR14DR
argument_list|,
literal|84
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  RR(symbol, addend) 		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR16F
argument_list|,
literal|85
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol + addend    		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR16WF
argument_list|,
literal|86
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  symbol + addend    		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DIR16DF
argument_list|,
literal|87
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  symbol + addend    		  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_GPREL64
argument_list|,
literal|88
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          symbol - GP + addend 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTREL14WR
argument_list|,
literal|91
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  RR(symbol - GP, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTREL14DR
argument_list|,
literal|92
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  RR(symbol - GP, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_GPREL16F
argument_list|,
literal|93
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol - GP + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_GPREL16WF
argument_list|,
literal|94
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  symbol - GP + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_GPREL16DF
argument_list|,
literal|95
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  symbol - GP + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF64
argument_list|,
literal|96
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          ltoff(symbol + addend)    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTIND14WR
argument_list|,
literal|99
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  R(ltoff(symbol + addend)) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_DLTIND14DR
argument_list|,
literal|100
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  R(ltoff(symbol + addend)) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF16F
argument_list|,
literal|101
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             ltoff(symbol + addend)    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF16WF
argument_list|,
literal|102
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  ltoff(symbol + addend)    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF16DF
argument_list|,
literal|103
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  ltoff(symbol + addend)    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_SECREL64
argument_list|,
literal|104
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          symbol - SECT + addend 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_BASEREL14WR
argument_list|,
literal|107
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  RR(symbol - base, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_BASEREL14DR
argument_list|,
literal|108
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  RR(symbol - base, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_SEGREL64
argument_list|,
literal|112
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          symbol - SB + addend 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF14WR
argument_list|,
literal|115
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  RR(pltoff(symbol), addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF14DR
argument_list|,
literal|116
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  RR(pltoff(symbol), addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF16F
argument_list|,
literal|117
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             pltoff(symbol) + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF16WF
argument_list|,
literal|118
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  pltoff(symbol) + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_PLTOFF16DF
argument_list|,
literal|119
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  pltoff(symbol) + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR64
argument_list|,
literal|120
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          ltoff(fptr(symbol+addend))     */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR14WR
argument_list|,
literal|123
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  R(ltoff(fptr(symbol+addend)))  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR14DR
argument_list|,
literal|124
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  R(ltoff(fptr(symbol+addend)))  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR16F
argument_list|,
literal|125
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             ltoff(fptr(symbol+addend))     */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR16WF
argument_list|,
literal|126
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  ltoff(fptr(symbol+addend))     */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_FPTR16DF
argument_list|,
literal|127
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  ltoff(fptr(symbol+addend))     */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_COPY
argument_list|,
literal|128
argument_list|)
end_macro

begin_comment
comment|/*		data                       Dynamic relocations only 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_IPLT
argument_list|,
literal|129
argument_list|)
end_macro

begin_comment
comment|/*		plt                                                 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_EPLT
argument_list|,
literal|130
argument_list|)
end_macro

begin_comment
comment|/*		plt                                                 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL32
argument_list|,
literal|153
argument_list|)
end_macro

begin_comment
comment|/*		32-bit word                symbol - TP + addend    	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL21L
argument_list|,
literal|154
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         LR(symbol - TP, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL14R
argument_list|,
literal|158
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             RR(symbol - TP, addend) 	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP21L
argument_list|,
literal|162
argument_list|)
end_macro

begin_comment
comment|/*		long immediate (7)         L(ltoff(symbol - TP + addend)) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP14R
argument_list|,
literal|166
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             R(ltoff(symbol - TP + addend)) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP14F
argument_list|,
literal|167
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             ltoff(symbol - TP + addend)    */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL64
argument_list|,
literal|216
argument_list|)
end_macro

begin_comment
comment|/*		64-bit word                symbol - TP + addend        	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL14WR
argument_list|,
literal|219
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  RR(symbol - TP, addend)     	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL14DR
argument_list|,
literal|220
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  RR(symbol - TP, addend)     	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL16F
argument_list|,
literal|221
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             symbol - TP + addend        	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL16WF
argument_list|,
literal|222
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  symbol - TP + addend        	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_TPREL16DF
argument_list|,
literal|223
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  symbol - TP + addend        	  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP64
argument_list|,
literal|224
argument_list|)
end_macro

begin_comment
comment|/*		64-bit doubleword          ltoff(symbol - TP + addend)    */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP14WR
argument_list|,
literal|227
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  R(ltoff(symbol - TP + addend)) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP14DR
argument_list|,
literal|228
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  R(ltoff(symbol - TP + addend)) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP16F
argument_list|,
literal|229
argument_list|)
end_macro

begin_comment
comment|/*		load/store (1)             ltoff(symbol - TP + addend)    */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP16WF
argument_list|,
literal|230
argument_list|)
end_macro

begin_comment
comment|/*		load/store mod. comp. (2)  ltoff(symbol - TP + addend)    */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_LTOFF_TP16DF
argument_list|,
literal|231
argument_list|)
end_macro

begin_comment
comment|/*		load/store doubleword (3)  ltoff(symbol - TP + addend)    */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_GNU_VTENTRY
argument_list|,
literal|232
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PARISC_GNU_VTINHERIT
argument_list|,
literal|233
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_PARISC_UNIMPLEMENTED
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_MACROS_GEN_FUNC
end_ifndef

begin_typedef
typedef|typedef
name|enum
name|elf_hppa_reloc_type
name|elf_hppa_reloc_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PT_PARISC_ARCHEXT
value|0x70000000
end_define

begin_define
define|#
directive|define
name|PT_PARISC_UNWIND
value|0x70000001
end_define

begin_define
define|#
directive|define
name|PF_PARISC_SBP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PF_HP_PAGE_SIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PF_HP_FAR_SHARED
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PF_HP_NEAR_SHARED
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PF_HP_CODE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PF_HP_MODIFY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PF_HP_LAZYSWAP
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PF_HP_SBP
value|0x08000000
end_define

begin_escape
end_escape

begin_comment
comment|/* Processor specific dynamic array tags.  */
end_comment

begin_comment
comment|/* Arggh.  HP's tools define these symbols based on the    old value of DT_LOOS.  So we must do the same to be    compatible.  */
end_comment

begin_define
define|#
directive|define
name|DT_HP_LOAD_MAP
value|(OLD_DT_LOOS + 0x0)
end_define

begin_define
define|#
directive|define
name|DT_HP_DLD_FLAGS
value|(OLD_DT_LOOS + 0x1)
end_define

begin_define
define|#
directive|define
name|DT_HP_DLD_HOOK
value|(OLD_DT_LOOS + 0x2)
end_define

begin_define
define|#
directive|define
name|DT_HP_UX10_INIT
value|(OLD_DT_LOOS + 0x3)
end_define

begin_define
define|#
directive|define
name|DT_HP_UX10_INITSZ
value|(OLD_DT_LOOS + 0x4)
end_define

begin_define
define|#
directive|define
name|DT_HP_PREINIT
value|(OLD_DT_LOOS + 0x5)
end_define

begin_define
define|#
directive|define
name|DT_HP_PREINITSZ
value|(OLD_DT_LOOS + 0x6)
end_define

begin_define
define|#
directive|define
name|DT_HP_NEEDED
value|(OLD_DT_LOOS + 0x7)
end_define

begin_define
define|#
directive|define
name|DT_HP_TIME_STAMP
value|(OLD_DT_LOOS + 0x8)
end_define

begin_define
define|#
directive|define
name|DT_HP_CHECKSUM
value|(OLD_DT_LOOS + 0x9)
end_define

begin_define
define|#
directive|define
name|DT_HP_GST_SIZE
value|(OLD_DT_LOOS + 0xa)
end_define

begin_define
define|#
directive|define
name|DT_HP_GST_VERSION
value|(OLD_DT_LOOS + 0xb)
end_define

begin_define
define|#
directive|define
name|DT_HP_GST_HASHVAL
value|(OLD_DT_LOOS + 0xc)
end_define

begin_comment
comment|/* Values for DT_HP_DLD_FLAGS.  */
end_comment

begin_define
define|#
directive|define
name|DT_HP_DEBUG_PRIVATE
value|0x0001
end_define

begin_comment
comment|/* Map text private */
end_comment

begin_define
define|#
directive|define
name|DT_HP_DEBUG_CALLBACK
value|0x0002
end_define

begin_comment
comment|/* Callback */
end_comment

begin_define
define|#
directive|define
name|DT_HP_DEBUG_CALLBACK_BOR
value|0x0004
end_define

begin_comment
comment|/* BOR callback */
end_comment

begin_define
define|#
directive|define
name|DT_HP_NO_ENVVAR
value|0x0008
end_define

begin_comment
comment|/* No env var */
end_comment

begin_define
define|#
directive|define
name|DT_HP_BIND_NOW
value|0x0010
end_define

begin_comment
comment|/* Bind now */
end_comment

begin_define
define|#
directive|define
name|DT_HP_BIND_NONFATAL
value|0x0020
end_define

begin_comment
comment|/* Bind non-fatal */
end_comment

begin_define
define|#
directive|define
name|DT_HP_BIND_VERBOSE
value|0x0040
end_define

begin_comment
comment|/* Bind verbose */
end_comment

begin_define
define|#
directive|define
name|DT_HP_BIND_RESTRICTED
value|0x0080
end_define

begin_comment
comment|/* Bind restricted */
end_comment

begin_define
define|#
directive|define
name|DT_HP_BIND_SYMBOLIC
value|0x0100
end_define

begin_comment
comment|/* Bind symbolic */
end_comment

begin_define
define|#
directive|define
name|DT_HP_RPATH_FIRST
value|0x0200
end_define

begin_comment
comment|/* RPATH first */
end_comment

begin_define
define|#
directive|define
name|DT_HP_BIND_DEPTH_FIRST
value|0x0400
end_define

begin_comment
comment|/* Bind depth-first */
end_comment

begin_comment
comment|/* Program header extensions.  */
end_comment

begin_define
define|#
directive|define
name|PT_HP_TLS
value|(PT_LOOS + 0x0)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_NONE
value|(PT_LOOS + 0x1)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_VERSION
value|(PT_LOOS + 0x2)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_KERNEL
value|(PT_LOOS + 0x3)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_COMM
value|(PT_LOOS + 0x4)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_PROC
value|(PT_LOOS + 0x5)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_LOADABLE
value|(PT_LOOS + 0x6)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_STACK
value|(PT_LOOS + 0x7)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_SHM
value|(PT_LOOS + 0x8)
end_define

begin_define
define|#
directive|define
name|PT_HP_CORE_MMF
value|(PT_LOOS + 0x9)
end_define

begin_define
define|#
directive|define
name|PT_HP_PARALLEL
value|(PT_LOOS + 0x10)
end_define

begin_define
define|#
directive|define
name|PT_HP_FASTBIND
value|(PT_LOOS + 0x11)
end_define

begin_comment
comment|/* Additional symbol types.  */
end_comment

begin_define
define|#
directive|define
name|STT_HP_OPAQUE
value|(STT_LOOS + 0x1)
end_define

begin_define
define|#
directive|define
name|STT_HP_STUB
value|(STT_LOOS + 0x2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_HPPA_H */
end_comment

end_unit

