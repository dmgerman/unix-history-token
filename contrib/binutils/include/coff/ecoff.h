begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic ECOFF support.    This does not include symbol information, found in sym.h and    symconst.h.     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ECOFF_H
end_ifndef

begin_define
define|#
directive|define
name|ECOFF_H
end_define

begin_comment
comment|/* Mips magic numbers used in filehdr.  MIPS_MAGIC_LITTLE is used on    little endian machines.  MIPS_MAGIC_BIG is used on big endian    machines.  Where is MIPS_MAGIC_1 from?  */
end_comment

begin_define
define|#
directive|define
name|MIPS_MAGIC_1
value|0x0180
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_LITTLE
value|0x0162
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_BIG
value|0x0160
end_define

begin_comment
comment|/* These are the magic numbers used for MIPS code compiled at ISA    level 2.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_MAGIC_LITTLE2
value|0x0166
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_BIG2
value|0x0163
end_define

begin_comment
comment|/* These are the magic numbers used for MIPS code compiled at ISA    level 3.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_MAGIC_LITTLE3
value|0x142
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_BIG3
value|0x140
end_define

begin_comment
comment|/* Alpha magic numbers used in filehdr.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MAGIC
value|0x183
end_define

begin_define
define|#
directive|define
name|ALPHA_MAGIC_BSD
value|0x185
end_define

begin_comment
comment|/* Magic numbers used in a.out header.  */
end_comment

begin_define
define|#
directive|define
name|ECOFF_AOUT_OMAGIC
value|0407
end_define

begin_comment
comment|/* not demand paged (ld -N).  */
end_comment

begin_define
define|#
directive|define
name|ECOFF_AOUT_ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format, eg normal ld output */
end_comment

begin_comment
comment|/* Names of special sections.  */
end_comment

begin_define
define|#
directive|define
name|_TEXT
value|".text"
end_define

begin_define
define|#
directive|define
name|_DATA
value|".data"
end_define

begin_define
define|#
directive|define
name|_BSS
value|".bss"
end_define

begin_define
define|#
directive|define
name|_RDATA
value|".rdata"
end_define

begin_define
define|#
directive|define
name|_SDATA
value|".sdata"
end_define

begin_define
define|#
directive|define
name|_SBSS
value|".sbss"
end_define

begin_define
define|#
directive|define
name|_LITA
value|".lita"
end_define

begin_define
define|#
directive|define
name|_LIT4
value|".lit4"
end_define

begin_define
define|#
directive|define
name|_LIT8
value|".lit8"
end_define

begin_define
define|#
directive|define
name|_LIB
value|".lib"
end_define

begin_define
define|#
directive|define
name|_INIT
value|".init"
end_define

begin_define
define|#
directive|define
name|_FINI
value|".fini"
end_define

begin_define
define|#
directive|define
name|_PDATA
value|".pdata"
end_define

begin_define
define|#
directive|define
name|_XDATA
value|".xdata"
end_define

begin_define
define|#
directive|define
name|_GOT
value|".got"
end_define

begin_define
define|#
directive|define
name|_HASH
value|".hash"
end_define

begin_define
define|#
directive|define
name|_DYNSYM
value|".dynsym"
end_define

begin_define
define|#
directive|define
name|_DYNSTR
value|".dynstr"
end_define

begin_define
define|#
directive|define
name|_RELDYN
value|".rel.dyn"
end_define

begin_define
define|#
directive|define
name|_CONFLIC
value|".conflic"
end_define

begin_define
define|#
directive|define
name|_COMMENT
value|".comment"
end_define

begin_define
define|#
directive|define
name|_LIBLIST
value|".liblist"
end_define

begin_define
define|#
directive|define
name|_DYNAMIC
value|".dynamic"
end_define

begin_define
define|#
directive|define
name|_RCONST
value|".rconst"
end_define

begin_comment
comment|/* ECOFF uses some additional section flags.  */
end_comment

begin_define
define|#
directive|define
name|STYP_RDATA
value|0x100
end_define

begin_define
define|#
directive|define
name|STYP_SDATA
value|0x200
end_define

begin_define
define|#
directive|define
name|STYP_SBSS
value|0x400
end_define

begin_define
define|#
directive|define
name|STYP_GOT
value|0x1000
end_define

begin_define
define|#
directive|define
name|STYP_DYNAMIC
value|0x2000
end_define

begin_define
define|#
directive|define
name|STYP_DYNSYM
value|0x4000
end_define

begin_define
define|#
directive|define
name|STYP_RELDYN
value|0x8000
end_define

begin_define
define|#
directive|define
name|STYP_DYNSTR
value|0x10000
end_define

begin_define
define|#
directive|define
name|STYP_HASH
value|0x20000
end_define

begin_define
define|#
directive|define
name|STYP_LIBLIST
value|0x40000
end_define

begin_define
define|#
directive|define
name|STYP_CONFLIC
value|0x100000
end_define

begin_define
define|#
directive|define
name|STYP_ECOFF_FINI
value|0x1000000
end_define

begin_define
define|#
directive|define
name|STYP_EXTENDESC
value|0x2000000
end_define

begin_comment
comment|/* 0x02FFF000 bits => scn type, rest clr */
end_comment

begin_define
define|#
directive|define
name|STYP_LITA
value|0x4000000
end_define

begin_define
define|#
directive|define
name|STYP_LIT8
value|0x8000000
end_define

begin_define
define|#
directive|define
name|STYP_LIT4
value|0x10000000
end_define

begin_define
define|#
directive|define
name|STYP_ECOFF_LIB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|STYP_ECOFF_INIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|STYP_OTHER_LOAD
value|(STYP_ECOFF_INIT | STYP_ECOFF_FINI)
end_define

begin_comment
comment|/* extended section types */
end_comment

begin_define
define|#
directive|define
name|STYP_COMMENT
value|0x2100000
end_define

begin_define
define|#
directive|define
name|STYP_RCONST
value|0x2200000
end_define

begin_define
define|#
directive|define
name|STYP_XDATA
value|0x2400000
end_define

begin_define
define|#
directive|define
name|STYP_PDATA
value|0x2800000
end_define

begin_comment
comment|/* The linker needs a section to hold small common variables while    linking.  There is no convenient way to create it when the linker    needs it, so we always create one for each BFD.  We then avoid    writing it out.  */
end_comment

begin_define
define|#
directive|define
name|SCOMMON
value|".scommon"
end_define

begin_comment
comment|/* If the extern bit in a reloc is 1, then r_symndx is an index into    the external symbol table.  If the extern bit is 0, then r_symndx    indicates a section, and is one of the following values.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_SECTION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_TEXT
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_RDATA
value|2
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_DATA
value|3
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_SDATA
value|4
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_SBSS
value|5
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_BSS
value|6
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_INIT
value|7
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_LIT8
value|8
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_LIT4
value|9
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_XDATA
value|10
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_PDATA
value|11
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_FINI
value|12
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_LITA
value|13
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_ABS
value|14
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_RCONST
value|15
end_define

begin_define
define|#
directive|define
name|NUM_RELOC_SECTIONS
value|16
end_define

begin_comment
comment|/********************** STABS **********************/
end_comment

begin_comment
comment|/* gcc uses mips-tfile to output type information in special stabs    entries.  These must match the corresponding definition in    gcc/config/mips.h.  At some point, these should probably go into a    shared include file, but currently gcc and gdb do not share any    directories. */
end_comment

begin_define
define|#
directive|define
name|CODE_MASK
value|0x8F300
end_define

begin_define
define|#
directive|define
name|ECOFF_IS_STAB
parameter_list|(
name|sym
parameter_list|)
value|(((sym)->index& 0xFFF00) == CODE_MASK)
end_define

begin_define
define|#
directive|define
name|ECOFF_MARK_STAB
parameter_list|(
name|code
parameter_list|)
value|((code)+CODE_MASK)
end_define

begin_define
define|#
directive|define
name|ECOFF_UNMARK_STAB
parameter_list|(
name|code
parameter_list|)
value|((code)-CODE_MASK)
end_define

begin_define
define|#
directive|define
name|STABS_SYMBOL
value|"@stabs"
end_define

begin_comment
comment|/********************** COFF **********************/
end_comment

begin_comment
comment|/* gcc also uses mips-tfile to output COFF debugging information.    These are the values it uses when outputting the .type directive.    These should also be in a shared include file.  */
end_comment

begin_define
define|#
directive|define
name|N_BTMASK
value|(017)
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|(060)
end_define

begin_define
define|#
directive|define
name|N_BTSHFT
value|(4)
end_define

begin_define
define|#
directive|define
name|N_TSHIFT
value|(2)
end_define

begin_comment
comment|/********************** AUX **********************/
end_comment

begin_comment
comment|/* The auxiliary type information is the same on all known ECOFF    targets.  I can't see any reason that it would ever change, so I am    going to gamble and define the external structures here, in the    target independent ECOFF header file.  The internal forms are    defined in coff/sym.h, which was originally donated by MIPS    Computer Systems.  */
end_comment

begin_comment
comment|/* Type information external record */
end_comment

begin_struct
struct|struct
name|tir_ext
block|{
name|unsigned
name|char
name|t_bits1
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|t_tq45
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|t_tq01
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|t_tq23
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIR_BITS1_FBITFIELD_BIG
value|((unsigned int) 0x80)
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_FBITFIELD_LITTLE
value|((unsigned int) 0x01)
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_CONTINUED_BIG
value|((unsigned int) 0x40)
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_CONTINUED_LITTLE
value|((unsigned int) 0x02)
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_BIG
value|((unsigned int) 0x3F)
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_LITTLE
value|((unsigned int) 0xFC)
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_SH_LITTLE
value|2
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_BIG
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_BIG
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_LITTLE
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_LITTLE
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_SH_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_BIG
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_BIG
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_LITTLE
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_LITTLE
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_SH_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_BIG
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_BIG
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_LITTLE
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_LITTLE
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_SH_LITTLE
value|4
end_define

begin_comment
comment|/* Relative symbol external record */
end_comment

begin_struct
struct|struct
name|rndx_ext
block|{
name|unsigned
name|char
name|r_bits
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RNDX_BITS0_RFD_SH_LEFT_BIG
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_BIG
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS0_RFD_SH_LEFT_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_LITTLE
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_SH_LEFT_LITTLE
value|8
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_BIG
value|((unsigned int) 0x0F)
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_SH_LEFT_BIG
value|16
end_define

begin_define
define|#
directive|define
name|RNDX_BITS2_INDEX_SH_LEFT_BIG
value|8
end_define

begin_define
define|#
directive|define
name|RNDX_BITS3_INDEX_SH_LEFT_BIG
value|0
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_LITTLE
value|((unsigned int) 0xF0)
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_SH_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS2_INDEX_SH_LEFT_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS3_INDEX_SH_LEFT_LITTLE
value|12
end_define

begin_comment
comment|/* Auxiliary symbol information external record */
end_comment

begin_union
union|union
name|aux_ext
block|{
name|struct
name|tir_ext
name|a_ti
decl_stmt|;
name|struct
name|rndx_ext
name|a_rndx
decl_stmt|;
name|unsigned
name|char
name|a_dnLow
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_dnHigh
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_isym
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_iss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_width
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_count
index|[
literal|4
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|AUX_GET_ANY
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|,
name|field
parameter_list|)
define|\
value|((bigend) ? bfd_getb32 ((ax)->field) : bfd_getl32 ((ax)->field))
end_define

begin_define
define|#
directive|define
name|AUX_GET_DNLOW
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_dnLow)
end_define

begin_define
define|#
directive|define
name|AUX_GET_DNHIGH
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_dnHigh)
end_define

begin_define
define|#
directive|define
name|AUX_GET_ISYM
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_isym)
end_define

begin_define
define|#
directive|define
name|AUX_GET_ISS
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_iss)
end_define

begin_define
define|#
directive|define
name|AUX_GET_WIDTH
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_width)
end_define

begin_define
define|#
directive|define
name|AUX_GET_COUNT
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_count)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_ANY
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|,
name|field
parameter_list|)
define|\
value|((bigend) \    ? (bfd_putb32 ((bfd_vma) (val), (ax)->field), 0) \    : (bfd_putl32 ((bfd_vma) (val), (ax)->field), 0))
end_define

begin_define
define|#
directive|define
name|AUX_PUT_DNLOW
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_dnLow)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_DNHIGH
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_dnHigh)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_ISYM
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_isym)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_ISS
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_iss)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_WIDTH
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_width)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_COUNT
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_count)
end_define

begin_comment
comment|/********************** SYMBOLS **********************/
end_comment

begin_comment
comment|/* For efficiency, gdb deals directly with the unswapped symbolic    information (that way it only takes the time to swap information    that it really needs to read).  gdb originally retrieved the    information directly from the BFD backend information, but that    strategy, besides being sort of ugly, does not work for MIPS ELF,    which also uses ECOFF debugging information.  This structure holds    pointers to the (mostly) unswapped symbolic information.  */
end_comment

begin_struct
struct|struct
name|ecoff_debug_info
block|{
comment|/* The swapped ECOFF symbolic header.  */
name|HDRR
name|symbolic_header
decl_stmt|;
comment|/* Pointers to the unswapped symbolic information.  Note that the      pointers to external structures point to different sorts of      information on different ECOFF targets.  The ecoff_debug_swap      structure provides the sizes of the structures and the functions      needed to swap the information in and out.  These pointers are      all pointers to arrays, not single structures.  They will be NULL      if there are no instances of the relevant structure.  These      fields are also used by the assembler to output ECOFF debugging      information.  */
name|unsigned
name|char
modifier|*
name|line
decl_stmt|;
name|PTR
name|external_dnr
decl_stmt|;
comment|/* struct dnr_ext */
name|PTR
name|external_pdr
decl_stmt|;
comment|/* struct pdr_ext */
name|PTR
name|external_sym
decl_stmt|;
comment|/* struct sym_ext */
name|PTR
name|external_opt
decl_stmt|;
comment|/* struct opt_ext */
name|union
name|aux_ext
modifier|*
name|external_aux
decl_stmt|;
name|char
modifier|*
name|ss
decl_stmt|;
name|char
modifier|*
name|ssext
decl_stmt|;
name|PTR
name|external_fdr
decl_stmt|;
comment|/* struct fdr_ext */
name|PTR
name|external_rfd
decl_stmt|;
comment|/* struct rfd_ext */
name|PTR
name|external_ext
decl_stmt|;
comment|/* struct ext_ext */
comment|/* These fields are used when linking.  They may disappear at some      point.  */
name|char
modifier|*
name|ssext_end
decl_stmt|;
name|PTR
name|external_ext_end
decl_stmt|;
comment|/* When linking, this field holds a mapping from the input FDR      numbers to the output numbers, and is used when writing out the      external symbols.  It is NULL if no mapping is required.  */
name|RFDT
modifier|*
name|ifdmap
decl_stmt|;
comment|/* The swapped FDR information.  Currently this is never NULL, but      code using this structure should probably double-check in case      this changes in the future.  This is a pointer to an array, not a      single structure.  */
name|FDR
modifier|*
name|fdr
decl_stmt|;
comment|/* When relaxing MIPS embedded PIC code, we may need to adjust      symbol values when they are output.  This is a linked list of      structures indicating how values should be adjusted.  There is no      requirement that the entries be in any order, or that they not      overlap.  This field is normally NULL, in which case no      adjustments need to be made.  */
name|struct
name|ecoff_value_adjust
modifier|*
name|adjust
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure describes how to adjust symbol values when    outputting MIPS embedded PIC code.  These adjustments only apply to    the internal symbols, as the external symbol values will come from    the hash table and have already been adjusted.  */
end_comment

begin_struct
struct|struct
name|ecoff_value_adjust
block|{
comment|/* Next entry on adjustment list.  */
name|struct
name|ecoff_value_adjust
modifier|*
name|next
decl_stmt|;
comment|/* Starting VMA of adjustment.  This is the VMA in the ECOFF file,      not the offset from the start of the section.  Thus it should      indicate a particular section.  */
name|bfd_vma
name|start
decl_stmt|;
comment|/* Ending VMA of adjustment.  */
name|bfd_vma
name|end
decl_stmt|;
comment|/* Adjustment.  This should be added to the value of the symbol, or      FDR.  This is zero for the last entry in the array.  */
name|long
name|adjust
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These structures are used by the ECOFF find_nearest_line function.  */
end_comment

begin_struct
struct|struct
name|ecoff_fdrtab_entry
block|{
comment|/* Base address in .text of this FDR.  */
name|bfd_vma
name|base_addr
decl_stmt|;
name|FDR
modifier|*
name|fdr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecoff_find_line
block|{
comment|/* Allocated memory to hold function and file names.  */
name|char
modifier|*
name|find_buffer
decl_stmt|;
comment|/* FDR table, sorted by address: */
name|long
name|fdrtab_len
decl_stmt|;
name|struct
name|ecoff_fdrtab_entry
modifier|*
name|fdrtab
decl_stmt|;
comment|/* Cache entry for most recently found line information.  The sect      field is NULL if this cache does not contain valid information.  */
struct|struct
block|{
name|asection
modifier|*
name|sect
decl_stmt|;
name|bfd_vma
name|start
decl_stmt|;
name|bfd_vma
name|stop
decl_stmt|;
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
specifier|const
name|char
modifier|*
name|functionname
decl_stmt|;
name|unsigned
name|int
name|line_num
decl_stmt|;
block|}
name|cache
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/********************** SWAPPING **********************/
end_comment

begin_comment
comment|/* The generic ECOFF code needs to be able to swap debugging    information in and out in the specific format used by a particular    ECOFF implementation.  This structure provides the information    needed to do this.  */
end_comment

begin_struct
struct|struct
name|ecoff_debug_swap
block|{
comment|/* Symbol table magic number.  */
name|int
name|sym_magic
decl_stmt|;
comment|/* Alignment of debugging information.  E.g., 4.  */
name|bfd_size_type
name|debug_align
decl_stmt|;
comment|/* Sizes of external symbolic information.  */
name|bfd_size_type
name|external_hdr_size
decl_stmt|;
name|bfd_size_type
name|external_dnr_size
decl_stmt|;
name|bfd_size_type
name|external_pdr_size
decl_stmt|;
name|bfd_size_type
name|external_sym_size
decl_stmt|;
name|bfd_size_type
name|external_opt_size
decl_stmt|;
name|bfd_size_type
name|external_fdr_size
decl_stmt|;
name|bfd_size_type
name|external_rfd_size
decl_stmt|;
name|bfd_size_type
name|external_ext_size
decl_stmt|;
comment|/* Functions to swap in external symbolic data.  */
name|void
argument_list|(
argument|*swap_hdr_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|HDRR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_dnr_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|DNR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_pdr_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PDR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_sym_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|SYMR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_opt_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|OPTR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_fdr_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|FDR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_rfd_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|RFDT
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_ext_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|EXTR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_tir_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|tir_ext
operator|*
operator|,
name|TIR
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_rndx_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|rndx_ext
operator|*
operator|,
name|RNDXR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Functions to swap out external symbolic data.  */
name|void
argument_list|(
argument|*swap_hdr_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|HDRR
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_dnr_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|DNR
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_pdr_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|PDR
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_sym_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|SYMR
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_opt_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|OPTR
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_fdr_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|FDR
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_rfd_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|RFDT
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_ext_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|EXTR
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_tir_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|TIR
operator|*
operator|,
expr|struct
name|tir_ext
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_rndx_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|RNDXR
operator|*
operator|,
expr|struct
name|rndx_ext
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Function to read symbol data and set up pointers in      ecoff_debug_info structure.  The section argument is used for      ELF, not straight ECOFF.  */
name|boolean
argument_list|(
argument|*read_debug_info
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
expr|struct
name|ecoff_debug_info
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (ECOFF_H) */
end_comment

end_unit

