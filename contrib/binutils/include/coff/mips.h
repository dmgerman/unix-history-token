begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ECOFF support on MIPS machines.    coff/ecoff.h must be included before this file.        Copyright 1999, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|DO_NOT_DEFINE_AOUTHDR
end_define

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|4
end_define

begin_include
include|#
directive|include
file|"coff/external.h"
end_include

begin_comment
comment|/* Magic numbers are defined in coff/ecoff.h.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_ECOFF_BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic!=MIPS_MAGIC_1)&& \ 			      ((x).f_magic!=MIPS_MAGIC_LITTLE)&&\ 			      ((x).f_magic!=MIPS_MAGIC_BIG)&& \ 			      ((x).f_magic!=MIPS_MAGIC_LITTLE2)&& \ 			      ((x).f_magic!=MIPS_MAGIC_BIG2)&& \ 			      ((x).f_magic!=MIPS_MAGIC_LITTLE3)&& \ 			      ((x).f_magic!=MIPS_MAGIC_BIG3))
end_define

begin_comment
comment|/********************** AOUT "OPTIONAL HEADER" **********************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|external_aouthdr
block|{
name|unsigned
name|char
name|magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* type of file				*/
name|unsigned
name|char
name|vstamp
index|[
literal|2
index|]
decl_stmt|;
comment|/* version stamp			*/
name|unsigned
name|char
name|tsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry*/
name|unsigned
name|char
name|dsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* initialized data "  "		*/
name|unsigned
name|char
name|bsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* uninitialized data "   "		*/
name|unsigned
name|char
name|entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry pt.				*/
name|unsigned
name|char
name|text_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of text used for this file */
name|unsigned
name|char
name|data_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of data used for this file */
name|unsigned
name|char
name|bss_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of bss used for this file */
name|unsigned
name|char
name|gprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* ?? */
name|unsigned
name|char
name|cprmask
index|[
literal|4
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* ?? */
name|unsigned
name|char
name|gp_value
index|[
literal|4
index|]
decl_stmt|;
comment|/* value for gp register */
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_comment
comment|/* compute size of a header */
end_comment

begin_define
define|#
directive|define
name|AOUTSZ
value|56
end_define

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|56
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_struct
struct|struct
name|external_reloc
block|{
name|unsigned
name|char
name|r_vaddr
index|[
literal|4
index|]
decl_stmt|;
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
name|RELOC
value|struct external_reloc
end_define

begin_define
define|#
directive|define
name|RELSZ
value|8
end_define

begin_comment
comment|/* MIPS ECOFF uses a packed 8 byte format for relocs.  These constants    are used to unpack the r_bits field.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_BITS0_SYMNDX_SH_LEFT_BIG
value|16
end_define

begin_define
define|#
directive|define
name|RELOC_BITS0_SYMNDX_SH_LEFT_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_SYMNDX_SH_LEFT_BIG
value|8
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_SYMNDX_SH_LEFT_LITTLE
value|8
end_define

begin_define
define|#
directive|define
name|RELOC_BITS2_SYMNDX_SH_LEFT_BIG
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_BITS2_SYMNDX_SH_LEFT_LITTLE
value|16
end_define

begin_comment
comment|/* Originally, ECOFF used four bits for the reloc type and had three    reserved bits.  Irix 4 added another bit for the reloc type, which    was easy because it was big endian and one of the spare bits became    the new most significant bit.  To make this also work for little    endian ECOFF, we need to wrap one of the reserved bits around to    become the most significant bit of the reloc type.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_BITS3_TYPE_BIG
value|0x3E
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_TYPE_SH_BIG
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_TYPE_LITTLE
value|0x78
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_TYPE_SH_LITTLE
value|3
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_TYPEHI_LITTLE
value|0x04
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_TYPEHI_SH_LITTLE
value|2
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_EXTERN_BIG
value|0x01
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_EXTERN_LITTLE
value|0x80
end_define

begin_comment
comment|/* The r_type field in a reloc is one of the following values.  I    don't know if any other values can appear.  These seem to be all    that occur in the Ultrix 4.2 libraries.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|MIPS_R_REFHALF
value|1
end_define

begin_define
define|#
directive|define
name|MIPS_R_REFWORD
value|2
end_define

begin_define
define|#
directive|define
name|MIPS_R_JMPADDR
value|3
end_define

begin_define
define|#
directive|define
name|MIPS_R_REFHI
value|4
end_define

begin_define
define|#
directive|define
name|MIPS_R_REFLO
value|5
end_define

begin_define
define|#
directive|define
name|MIPS_R_GPREL
value|6
end_define

begin_define
define|#
directive|define
name|MIPS_R_LITERAL
value|7
end_define

begin_comment
comment|/* FIXME: This relocation is used (internally only) to represent branches    when assembling.  It should never appear in output files, and      be removed.  (It used to be used for embedded-PIC support.)  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R_PCREL16
value|12
end_define

begin_comment
comment|/********************** STABS **********************/
end_comment

begin_define
define|#
directive|define
name|MIPS_IS_STAB
value|ECOFF_IS_STAB
end_define

begin_define
define|#
directive|define
name|MIPS_MARK_STAB
value|ECOFF_MARK_STAB
end_define

begin_define
define|#
directive|define
name|MIPS_UNMARK_STAB
value|ECOFF_UNMARK_STAB
end_define

begin_comment
comment|/********************** SYMBOLIC INFORMATION **********************/
end_comment

begin_comment
comment|/* Written by John Gilmore.  */
end_comment

begin_comment
comment|/* ECOFF uses COFF-like section structures, but its own symbol format.    This file defines the symbol format in fields whose size and alignment    will not vary on different host systems.  */
end_comment

begin_comment
comment|/* File header as a set of bytes */
end_comment

begin_struct
struct|struct
name|hdr_ext
block|{
name|unsigned
name|char
name|h_magic
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|h_vstamp
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|h_ilineMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbLine
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbLineOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_idnMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbDnOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_ipdMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbPdOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_isymMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbSymOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_ioptMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbOptOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_iauxMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbAuxOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_issMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbSsOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_issExtMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbSsExtOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_ifdMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbFdOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_crfd
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbRfdOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_iextMax
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbExtOffset
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* File descriptor external record */
end_comment

begin_struct
struct|struct
name|fdr_ext
block|{
name|unsigned
name|char
name|f_adr
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_rss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_issBase
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cbSs
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_isymBase
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_csym
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_ilineBase
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cline
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_ioptBase
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_copt
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_ipdFirst
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cpd
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|f_iauxBase
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_caux
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_rfdBase
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_crfd
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_bits1
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|f_bits2
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cbLineOffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cbLine
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
name|FDR_BITS1_LANG_BIG
value|0xF8
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_LANG_SH_BIG
value|3
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_LANG_LITTLE
value|0x1F
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_LANG_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_FMERGE_BIG
value|0x04
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_FMERGE_LITTLE
value|0x20
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_FREADIN_BIG
value|0x02
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_FREADIN_LITTLE
value|0x40
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_FBIGENDIAN_BIG
value|0x01
end_define

begin_define
define|#
directive|define
name|FDR_BITS1_FBIGENDIAN_LITTLE
value|0x80
end_define

begin_define
define|#
directive|define
name|FDR_BITS2_GLEVEL_BIG
value|0xC0
end_define

begin_define
define|#
directive|define
name|FDR_BITS2_GLEVEL_SH_BIG
value|6
end_define

begin_define
define|#
directive|define
name|FDR_BITS2_GLEVEL_LITTLE
value|0x03
end_define

begin_define
define|#
directive|define
name|FDR_BITS2_GLEVEL_SH_LITTLE
value|0
end_define

begin_comment
comment|/* We ignore the `reserved' field in bits2. */
end_comment

begin_comment
comment|/* Procedure descriptor external record */
end_comment

begin_struct
struct|struct
name|pdr_ext
block|{
name|unsigned
name|char
name|p_adr
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_isym
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_iline
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_regmask
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_regoffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_iopt
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_fregmask
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_fregoffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_frameoffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_framereg
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|p_pcreg
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|p_lnLow
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_lnHigh
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_cbLineOffset
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Runtime procedure table */
end_comment

begin_struct
struct|struct
name|rpdr_ext
block|{
name|unsigned
name|char
name|p_adr
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_regmask
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_regoffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_fregmask
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_fregoffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_frameoffset
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_framereg
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|p_pcreg
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|p_irpss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_reserved
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|p_exception_info
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Line numbers */
end_comment

begin_struct
struct|struct
name|line_ext
block|{
name|unsigned
name|char
name|l_line
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Symbol external record */
end_comment

begin_struct
struct|struct
name|sym_ext
block|{
name|unsigned
name|char
name|s_iss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|s_value
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|s_bits1
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|s_bits2
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|s_bits3
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|s_bits4
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
name|SYM_BITS1_ST_BIG
value|0xFC
end_define

begin_define
define|#
directive|define
name|SYM_BITS1_ST_SH_BIG
value|2
end_define

begin_define
define|#
directive|define
name|SYM_BITS1_ST_LITTLE
value|0x3F
end_define

begin_define
define|#
directive|define
name|SYM_BITS1_ST_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|SYM_BITS1_SC_BIG
value|0x03
end_define

begin_define
define|#
directive|define
name|SYM_BITS1_SC_SH_LEFT_BIG
value|3
end_define

begin_define
define|#
directive|define
name|SYM_BITS1_SC_LITTLE
value|0xC0
end_define

begin_define
define|#
directive|define
name|SYM_BITS1_SC_SH_LITTLE
value|6
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_SC_BIG
value|0xE0
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_SC_SH_BIG
value|5
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_SC_LITTLE
value|0x07
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_SC_SH_LEFT_LITTLE
value|2
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_RESERVED_BIG
value|0x10
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_RESERVED_LITTLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_INDEX_BIG
value|0x0F
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_INDEX_SH_LEFT_BIG
value|16
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_INDEX_LITTLE
value|0xF0
end_define

begin_define
define|#
directive|define
name|SYM_BITS2_INDEX_SH_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|SYM_BITS3_INDEX_SH_LEFT_BIG
value|8
end_define

begin_define
define|#
directive|define
name|SYM_BITS3_INDEX_SH_LEFT_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|SYM_BITS4_INDEX_SH_LEFT_BIG
value|0
end_define

begin_define
define|#
directive|define
name|SYM_BITS4_INDEX_SH_LEFT_LITTLE
value|12
end_define

begin_comment
comment|/* External symbol external record */
end_comment

begin_struct
struct|struct
name|ext_ext
block|{
name|unsigned
name|char
name|es_bits1
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|es_bits2
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|es_ifd
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|sym_ext
name|es_asym
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXT_BITS1_JMPTBL_BIG
value|0x80
end_define

begin_define
define|#
directive|define
name|EXT_BITS1_JMPTBL_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|EXT_BITS1_COBOL_MAIN_BIG
value|0x40
end_define

begin_define
define|#
directive|define
name|EXT_BITS1_COBOL_MAIN_LITTLE
value|0x02
end_define

begin_define
define|#
directive|define
name|EXT_BITS1_WEAKEXT_BIG
value|0x20
end_define

begin_define
define|#
directive|define
name|EXT_BITS1_WEAKEXT_LITTLE
value|0x04
end_define

begin_comment
comment|/* Dense numbers external record */
end_comment

begin_struct
struct|struct
name|dnr_ext
block|{
name|unsigned
name|char
name|d_rfd
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|d_index
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Relative file descriptor */
end_comment

begin_struct
struct|struct
name|rfd_ext
block|{
name|unsigned
name|char
name|rfd
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Optimizer symbol external record */
end_comment

begin_struct
struct|struct
name|opt_ext
block|{
name|unsigned
name|char
name|o_bits1
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|o_bits2
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|o_bits3
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|o_bits4
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|rndx_ext
name|o_rndx
decl_stmt|;
name|unsigned
name|char
name|o_offset
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
name|OPT_BITS2_VALUE_SH_LEFT_BIG
value|16
end_define

begin_define
define|#
directive|define
name|OPT_BITS2_VALUE_SH_LEFT_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|OPT_BITS3_VALUE_SH_LEFT_BIG
value|8
end_define

begin_define
define|#
directive|define
name|OPT_BITS3_VALUE_SH_LEFT_LITTLE
value|8
end_define

begin_define
define|#
directive|define
name|OPT_BITS4_VALUE_SH_LEFT_BIG
value|0
end_define

begin_define
define|#
directive|define
name|OPT_BITS4_VALUE_SH_LEFT_LITTLE
value|16
end_define

end_unit

