begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ECOFF support on Alpha machines.    coff/ecoff.h must be included before this file.     Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/********************** FILE HEADER **********************/
end_comment

begin_struct
struct|struct
name|external_filehdr
block|{
name|unsigned
name|char
name|f_magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* magic number			*/
name|unsigned
name|char
name|f_nscns
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sections		*/
name|unsigned
name|char
name|f_timdat
index|[
literal|4
index|]
decl_stmt|;
comment|/* time& date stamp		*/
name|unsigned
name|char
name|f_symptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file pointer to symtab	*/
name|unsigned
name|char
name|f_nsyms
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of symtab entries	*/
name|unsigned
name|char
name|f_opthdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* sizeof(optional hdr)		*/
name|unsigned
name|char
name|f_flags
index|[
literal|2
index|]
decl_stmt|;
comment|/* flags			*/
block|}
struct|;
end_struct

begin_comment
comment|/* Magic numbers are defined in coff/ecoff.h.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_ECOFF_BADMAG
parameter_list|(
name|x
parameter_list|)
define|\
value|((x).f_magic != ALPHA_MAGIC&& (x).f_magic != ALPHA_MAGIC_BSD)
end_define

begin_comment
comment|/* The object type is encoded in the f_flags.  */
end_comment

begin_define
define|#
directive|define
name|F_ALPHA_OBJECT_TYPE_MASK
value|0x3000
end_define

begin_define
define|#
directive|define
name|F_ALPHA_NO_SHARED
value|0x1000
end_define

begin_define
define|#
directive|define
name|F_ALPHA_SHARABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|F_ALPHA_CALL_SHARED
value|0x3000
end_define

begin_define
define|#
directive|define
name|FILHDR
value|struct external_filehdr
end_define

begin_define
define|#
directive|define
name|FILHSZ
value|24
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
name|bldrev
index|[
literal|2
index|]
decl_stmt|;
comment|/* ?? */
name|unsigned
name|char
name|padding
index|[
literal|2
index|]
decl_stmt|;
comment|/* pad to quadword boundary		*/
name|unsigned
name|char
name|tsize
index|[
literal|8
index|]
decl_stmt|;
comment|/* text size in bytes			*/
name|unsigned
name|char
name|dsize
index|[
literal|8
index|]
decl_stmt|;
comment|/* initialized data "  "		*/
name|unsigned
name|char
name|bsize
index|[
literal|8
index|]
decl_stmt|;
comment|/* uninitialized data "   "		*/
name|unsigned
name|char
name|entry
index|[
literal|8
index|]
decl_stmt|;
comment|/* entry pt.				*/
name|unsigned
name|char
name|text_start
index|[
literal|8
index|]
decl_stmt|;
comment|/* base of text used for this file */
name|unsigned
name|char
name|data_start
index|[
literal|8
index|]
decl_stmt|;
comment|/* base of data used for this file */
name|unsigned
name|char
name|bss_start
index|[
literal|8
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
comment|/* bitmask of general registers used */
name|unsigned
name|char
name|fprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* bitmask of floating point registers used */
name|unsigned
name|char
name|gp_value
index|[
literal|8
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
value|80
end_define

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|80
end_define

begin_comment
comment|/********************** SECTION HEADER **********************/
end_comment

begin_struct
struct|struct
name|external_scnhdr
block|{
name|unsigned
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* section name			*/
name|unsigned
name|char
name|s_paddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|unsigned
name|char
name|s_vaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* virtual address		*/
name|unsigned
name|char
name|s_size
index|[
literal|8
index|]
decl_stmt|;
comment|/* section size			*/
name|unsigned
name|char
name|s_scnptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file ptr to raw data for section */
name|unsigned
name|char
name|s_relptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file ptr to relocation	*/
name|unsigned
name|char
name|s_lnnoptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file ptr to line numbers	*/
name|unsigned
name|char
name|s_nreloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of relocation entries	*/
name|unsigned
name|char
name|s_nlnno
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of line number entries*/
name|unsigned
name|char
name|s_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* flags			*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCNHDR
value|struct external_scnhdr
end_define

begin_define
define|#
directive|define
name|SCNHSZ
value|64
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
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|r_symndx
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
value|16
end_define

begin_comment
comment|/* Constants to unpack the r_bits field.  The Alpha seems to always be    little endian, so I haven't bothered to define big endian variants    of these.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_BITS0_TYPE_LITTLE
value|0xff
end_define

begin_define
define|#
directive|define
name|RELOC_BITS0_TYPE_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_EXTERN_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_OFFSET_LITTLE
value|0x7e
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_OFFSET_SH_LITTLE
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_RESERVED_LITTLE
value|0x80
end_define

begin_define
define|#
directive|define
name|RELOC_BITS1_RESERVED_SH_LITTLE
value|7
end_define

begin_define
define|#
directive|define
name|RELOC_BITS2_RESERVED_LITTLE
value|0xff
end_define

begin_define
define|#
directive|define
name|RELOC_BITS2_RESERVED_SH_LEFT_LITTLE
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_RESERVED_LITTLE
value|0x03
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_RESERVED_SH_LEFT_LITTLE
value|9
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_SIZE_LITTLE
value|0xfc
end_define

begin_define
define|#
directive|define
name|RELOC_BITS3_SIZE_SH_LITTLE
value|2
end_define

begin_comment
comment|/* The r_type field in a reloc is one of the following values.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_R_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|ALPHA_R_REFLONG
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_R_REFQUAD
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPREL32
value|3
end_define

begin_define
define|#
directive|define
name|ALPHA_R_LITERAL
value|4
end_define

begin_define
define|#
directive|define
name|ALPHA_R_LITUSE
value|5
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPDISP
value|6
end_define

begin_define
define|#
directive|define
name|ALPHA_R_BRADDR
value|7
end_define

begin_define
define|#
directive|define
name|ALPHA_R_HINT
value|8
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL16
value|9
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL32
value|10
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL64
value|11
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PUSH
value|12
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_STORE
value|13
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PSUB
value|14
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PRSHIFT
value|15
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPVALUE
value|16
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPRELHIGH
value|17
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPRELLOW
value|18
end_define

begin_define
define|#
directive|define
name|ALPHA_R_IMMED
value|19
end_define

begin_comment
comment|/* Overloaded reloc value used by Net- and OpenBSD.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_R_LITERALSLEAZY
value|17
end_define

begin_comment
comment|/* With ALPHA_R_LITUSE, the r_size field is one of the following values.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_R_LU_BASE
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_R_LU_BYTOFF
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_R_LU_JSR
value|3
end_define

begin_comment
comment|/* With ALPHA_R_IMMED, the r_size field is one of the following values.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_R_IMMED_GP_16
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_R_IMMED_GP_HI32
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_R_IMMED_SCN_HI32
value|3
end_define

begin_define
define|#
directive|define
name|ALPHA_R_IMMED_BR_HI32
value|4
end_define

begin_define
define|#
directive|define
name|ALPHA_R_IMMED_LO32
value|5
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
name|h_idnMax
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
name|h_isymMax
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
name|h_iauxMax
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
name|h_issExtMax
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
name|h_crfd
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
name|h_cbLine
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbLineOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbDnOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbPdOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbSymOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbOptOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbAuxOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbSsOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbSsExtOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbFdOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbRfdOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|h_cbExtOffset
index|[
literal|8
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
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cbLineOffset
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cbLine
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cbSs
index|[
literal|8
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
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|f_cpd
index|[
literal|4
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
name|f_padding
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
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|p_cbLineOffset
index|[
literal|8
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
name|p_gp_prologue
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|p_bits1
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|p_bits2
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|p_localoff
index|[
literal|1
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PDR_BITS1_GP_USED_BIG
value|0x80
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_REG_FRAME_BIG
value|0x40
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_PROF_BIG
value|0x20
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_RESERVED_BIG
value|0x1f
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_RESERVED_SH_LEFT_BIG
value|8
end_define

begin_define
define|#
directive|define
name|PDR_BITS2_RESERVED_BIG
value|0xff
end_define

begin_define
define|#
directive|define
name|PDR_BITS2_RESERVED_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_GP_USED_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_REG_FRAME_LITTLE
value|0x02
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_PROF_LITTLE
value|0x04
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_RESERVED_LITTLE
value|0xf8
end_define

begin_define
define|#
directive|define
name|PDR_BITS1_RESERVED_SH_LITTLE
value|3
end_define

begin_define
define|#
directive|define
name|PDR_BITS2_RESERVED_LITTLE
value|0xff
end_define

begin_define
define|#
directive|define
name|PDR_BITS2_RESERVED_SH_LEFT_LITTLE
value|5
end_define

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
name|s_value
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|s_iss
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
name|struct
name|sym_ext
name|es_asym
decl_stmt|;
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
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|es_ifd
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

