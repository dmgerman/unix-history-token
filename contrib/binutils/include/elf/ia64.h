begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IA-64 ELF support for BFD.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.    Contributed by David Mosberger-Tang<davidm@hpl.hp.com>  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_IA64_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_IA64_H
end_define

begin_comment
comment|/* Bits in the e_flags field of the Elf64_Ehdr:  */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_MASKOS
value|0x0000000f
end_define

begin_comment
comment|/* os-specific flags */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_ARCH
value|0xff000000
end_define

begin_comment
comment|/* arch. version mask */
end_comment

begin_comment
comment|/* ??? These four definitions are not part of the SVR4 ABI.    They were present in David's initial code drop, so it is probable    that they are used by HP/UX.  */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_TRAPNIL
value|(1<< 0)
end_define

begin_comment
comment|/* trap NIL pointer dereferences */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_EXT
value|(1<< 2)
end_define

begin_comment
comment|/* program uses arch. extensions */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_BE
value|(1<< 3)
end_define

begin_comment
comment|/* PSR BE bit set (big-endian) */
end_comment

begin_define
define|#
directive|define
name|EFA_IA_64_EAS2_3
value|0x23000000
end_define

begin_comment
comment|/* ia64 EAS 2.3 */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_ABI64
value|(1<< 4)
end_define

begin_comment
comment|/* 64-bit ABI */
end_comment

begin_comment
comment|/* Not used yet.  */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_REDUCEDFP
value|(1<< 5)
end_define

begin_comment
comment|/* Only FP6-FP11 used.  */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_CONS_GP
value|(1<< 6)
end_define

begin_comment
comment|/* gp as program wide constant. */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_NOFUNCDESC_CONS_GP
value|(1<< 7)
end_define

begin_comment
comment|/* And no function descriptors. */
end_comment

begin_comment
comment|/* Not used yet.  */
end_comment

begin_define
define|#
directive|define
name|EF_IA_64_ABSOLUTE
value|(1<< 8)
end_define

begin_comment
comment|/* Load at absolute addresses.  */
end_comment

begin_define
define|#
directive|define
name|ELF_STRING_ia64_archext
value|".IA_64.archext"
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ia64_pltoff
value|".IA_64.pltoff"
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ia64_unwind
value|".IA_64.unwind"
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ia64_unwind_info
value|".IA_64.unwind_info"
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ia64_unwind_once
value|".gnu.linkonce.ia64unw."
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ia64_unwind_info_once
value|".gnu.linkonce.ia64unwi."
end_define

begin_comment
comment|/* Bits in the sh_flags field of Elf64_Shdr:  */
end_comment

begin_define
define|#
directive|define
name|SHF_IA_64_SHORT
value|0x10000000
end_define

begin_comment
comment|/* section near gp */
end_comment

begin_define
define|#
directive|define
name|SHF_IA_64_NORECOV
value|0x20000000
end_define

begin_comment
comment|/* spec insns w/o recovery */
end_comment

begin_comment
comment|/* Possible values for sh_type in Elf64_Shdr: */
end_comment

begin_define
define|#
directive|define
name|SHT_IA_64_EXT
value|(SHT_LOPROC + 0)
end_define

begin_comment
comment|/* extension bits */
end_comment

begin_define
define|#
directive|define
name|SHT_IA_64_UNWIND
value|(SHT_LOPROC + 1)
end_define

begin_comment
comment|/* unwind bits */
end_comment

begin_comment
comment|/* Bits in the p_flags field of Elf64_Phdr:  */
end_comment

begin_define
define|#
directive|define
name|PF_IA_64_NORECOV
value|0x80000000
end_define

begin_comment
comment|/* Possible values for p_type in Elf64_Phdr:  */
end_comment

begin_define
define|#
directive|define
name|PT_IA_64_ARCHEXT
value|(PT_LOPROC + 0)
end_define

begin_comment
comment|/* arch extension bits */
end_comment

begin_define
define|#
directive|define
name|PT_IA_64_UNWIND
value|(PT_LOPROC + 1)
end_define

begin_comment
comment|/* ia64 unwind bits */
end_comment

begin_comment
comment|/* Possible values for d_tag in Elf64_Dyn:  */
end_comment

begin_define
define|#
directive|define
name|DT_IA_64_PLT_RESERVE
value|(DT_LOPROC + 0)
end_define

begin_comment
comment|/* ia64-specific relocation types: */
end_comment

begin_comment
comment|/* Relocs apply to specific instructions within a bundle.  The least    significant 2 bits of the address indicate which instruction in the    bundle the reloc refers to (0=first slot, 1=second slow, 2=third    slot, 3=undefined) and the remaining bits give the address of the    bundle (16 byte aligned).     The top 5 bits of the reloc code specifies the expression type, the    low 3 bits the format of the data word being relocated.  */
end_comment

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_ia64_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_NONE
argument_list|,
literal|0x00
argument_list|)
end_macro

begin_comment
comment|/* none */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_IMM14
argument_list|,
literal|0x21
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, add imm14 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_IMM22
argument_list|,
literal|0x22
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, add imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_IMM64
argument_list|,
literal|0x23
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, mov imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DIR32MSB
argument_list|,
literal|0x24
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DIR32LSB
argument_list|,
literal|0x25
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DIR64MSB
argument_list|,
literal|0x26
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DIR64LSB
argument_list|,
literal|0x27
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_GPREL22
argument_list|,
literal|0x2a
argument_list|)
end_macro

begin_comment
comment|/* @gprel(sym+add), add imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_GPREL64I
argument_list|,
literal|0x2b
argument_list|)
end_macro

begin_comment
comment|/* @gprel(sym+add), mov imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_GPREL32MSB
argument_list|,
literal|0x2c
argument_list|)
end_macro

begin_comment
comment|/* @gprel(sym+add), data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_GPREL32LSB
argument_list|,
literal|0x2d
argument_list|)
end_macro

begin_comment
comment|/* @gprel(sym+add), data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_GPREL64MSB
argument_list|,
literal|0x2e
argument_list|)
end_macro

begin_comment
comment|/* @gprel(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_GPREL64LSB
argument_list|,
literal|0x2f
argument_list|)
end_macro

begin_comment
comment|/* @gprel(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF22
argument_list|,
literal|0x32
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(sym+add), add imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF64I
argument_list|,
literal|0x33
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(sym+add), mov imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PLTOFF22
argument_list|,
literal|0x3a
argument_list|)
end_macro

begin_comment
comment|/* @pltoff(sym+add), add imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PLTOFF64I
argument_list|,
literal|0x3b
argument_list|)
end_macro

begin_comment
comment|/* @pltoff(sym+add), mov imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PLTOFF64MSB
argument_list|,
literal|0x3e
argument_list|)
end_macro

begin_comment
comment|/* @pltoff(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PLTOFF64LSB
argument_list|,
literal|0x3f
argument_list|)
end_macro

begin_comment
comment|/* @pltoff(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_FPTR64I
argument_list|,
literal|0x43
argument_list|)
end_macro

begin_comment
comment|/* @fptr(sym+add), mov imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_FPTR32MSB
argument_list|,
literal|0x44
argument_list|)
end_macro

begin_comment
comment|/* @fptr(sym+add), data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_FPTR32LSB
argument_list|,
literal|0x45
argument_list|)
end_macro

begin_comment
comment|/* @fptr(sym+add), data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_FPTR64MSB
argument_list|,
literal|0x46
argument_list|)
end_macro

begin_comment
comment|/* @fptr(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_FPTR64LSB
argument_list|,
literal|0x47
argument_list|)
end_macro

begin_comment
comment|/* @fptr(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL60B
argument_list|,
literal|0x48
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), brl */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL21B
argument_list|,
literal|0x49
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), ptb, call */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL21M
argument_list|,
literal|0x4a
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), chk.s */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL21F
argument_list|,
literal|0x4b
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), fchkf */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL32MSB
argument_list|,
literal|0x4c
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL32LSB
argument_list|,
literal|0x4d
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL64MSB
argument_list|,
literal|0x4e
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL64LSB
argument_list|,
literal|0x4f
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_FPTR22
argument_list|,
literal|0x52
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@fptr(s+a)), imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_FPTR64I
argument_list|,
literal|0x53
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@fptr(s+a)), imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_FPTR32MSB
argument_list|,
literal|0x54
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@fptr(s+a)), 4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_FPTR32LSB
argument_list|,
literal|0x55
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@fptr(s+a)), 4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_FPTR64MSB
argument_list|,
literal|0x56
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@fptr(s+a)), 8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_FPTR64LSB
argument_list|,
literal|0x57
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@fptr(s+a)), 8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SEGREL32MSB
argument_list|,
literal|0x5c
argument_list|)
end_macro

begin_comment
comment|/* @segrel(sym+add), data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SEGREL32LSB
argument_list|,
literal|0x5d
argument_list|)
end_macro

begin_comment
comment|/* @segrel(sym+add), data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SEGREL64MSB
argument_list|,
literal|0x5e
argument_list|)
end_macro

begin_comment
comment|/* @segrel(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SEGREL64LSB
argument_list|,
literal|0x5f
argument_list|)
end_macro

begin_comment
comment|/* @segrel(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SECREL32MSB
argument_list|,
literal|0x64
argument_list|)
end_macro

begin_comment
comment|/* @secrel(sym+add), data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SECREL32LSB
argument_list|,
literal|0x65
argument_list|)
end_macro

begin_comment
comment|/* @secrel(sym+add), data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SECREL64MSB
argument_list|,
literal|0x66
argument_list|)
end_macro

begin_comment
comment|/* @secrel(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_SECREL64LSB
argument_list|,
literal|0x67
argument_list|)
end_macro

begin_comment
comment|/* @secrel(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_REL32MSB
argument_list|,
literal|0x6c
argument_list|)
end_macro

begin_comment
comment|/* data 4 + REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_REL32LSB
argument_list|,
literal|0x6d
argument_list|)
end_macro

begin_comment
comment|/* data 4 + REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_REL64MSB
argument_list|,
literal|0x6e
argument_list|)
end_macro

begin_comment
comment|/* data 8 + REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_REL64LSB
argument_list|,
literal|0x6f
argument_list|)
end_macro

begin_comment
comment|/* data 8 + REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTV32MSB
argument_list|,
literal|0x74
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTV32LSB
argument_list|,
literal|0x75
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTV64MSB
argument_list|,
literal|0x76
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTV64LSB
argument_list|,
literal|0x77
argument_list|)
end_macro

begin_comment
comment|/* symbol + addend, data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL21BI
argument_list|,
literal|0x79
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), ptb, call */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL22
argument_list|,
literal|0x7a
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_PCREL64I
argument_list|,
literal|0x7b
argument_list|)
end_macro

begin_comment
comment|/* @pcrel(sym+add), imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_IPLTMSB
argument_list|,
literal|0x80
argument_list|)
end_macro

begin_comment
comment|/* dynamic reloc, imported PLT, MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_IPLTLSB
argument_list|,
literal|0x81
argument_list|)
end_macro

begin_comment
comment|/* dynamic reloc, imported PLT, LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_COPY
argument_list|,
literal|0x84
argument_list|)
end_macro

begin_comment
comment|/* dynamic reloc, data copy */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF22X
argument_list|,
literal|0x86
argument_list|)
end_macro

begin_comment
comment|/* LTOFF22, relaxable.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LDXMOV
argument_list|,
literal|0x87
argument_list|)
end_macro

begin_comment
comment|/* Use of LTOFF22X.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_TPREL14
argument_list|,
literal|0x91
argument_list|)
end_macro

begin_comment
comment|/* @tprel(sym+add), add imm14 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_TPREL22
argument_list|,
literal|0x92
argument_list|)
end_macro

begin_comment
comment|/* @tprel(sym+add), add imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_TPREL64I
argument_list|,
literal|0x93
argument_list|)
end_macro

begin_comment
comment|/* @tprel(sym+add), add imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_TPREL64MSB
argument_list|,
literal|0x96
argument_list|)
end_macro

begin_comment
comment|/* @tprel(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_TPREL64LSB
argument_list|,
literal|0x97
argument_list|)
end_macro

begin_comment
comment|/* @tprel(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_TP22
argument_list|,
literal|0x9a
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@tprel(s+a)), add imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPMOD64MSB
argument_list|,
literal|0xa6
argument_list|)
end_macro

begin_comment
comment|/* @dtpmod(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPMOD64LSB
argument_list|,
literal|0xa7
argument_list|)
end_macro

begin_comment
comment|/* @dtpmod(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_DTPMOD22
argument_list|,
literal|0xaa
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@dtpmod(s+a)), imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPREL14
argument_list|,
literal|0xb1
argument_list|)
end_macro

begin_comment
comment|/* @dtprel(sym+add), imm14 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPREL22
argument_list|,
literal|0xb2
argument_list|)
end_macro

begin_comment
comment|/* @dtprel(sym+add), imm22 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPREL64I
argument_list|,
literal|0xb3
argument_list|)
end_macro

begin_comment
comment|/* @dtprel(sym+add), imm64 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPREL32MSB
argument_list|,
literal|0xb4
argument_list|)
end_macro

begin_comment
comment|/* @dtprel(sym+add), data4 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPREL32LSB
argument_list|,
literal|0xb5
argument_list|)
end_macro

begin_comment
comment|/* @dtprel(sym+add), data4 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPREL64MSB
argument_list|,
literal|0xb6
argument_list|)
end_macro

begin_comment
comment|/* @dtprel(sym+add), data8 MSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_DTPREL64LSB
argument_list|,
literal|0xb7
argument_list|)
end_macro

begin_comment
comment|/* @dtprel(sym+add), data8 LSB */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IA64_LTOFF_DTPREL22
argument_list|,
literal|0xba
argument_list|)
end_macro

begin_comment
comment|/* @ltoff(@dtprel(s+a)), imm22 */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_IA64_MAX_RELOC_CODE
argument_list|,
literal|0xba
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_IA64_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_IA64_H */
end_comment

end_unit

