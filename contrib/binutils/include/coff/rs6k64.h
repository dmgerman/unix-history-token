begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IBM RS/6000 "XCOFF64" file definitions for BFD.    Copyright (C) 2000, 2002 Free Software Foundation, Inc.       This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/********************** FILE HEADER **********************/
end_comment

begin_struct
struct|struct
name|external_filehdr
block|{
name|char
name|f_magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* magic number			*/
name|char
name|f_nscns
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sections		*/
name|char
name|f_timdat
index|[
literal|4
index|]
decl_stmt|;
comment|/* time& date stamp		*/
name|char
name|f_symptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file pointer to symtab 	*/
name|char
name|f_opthdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* sizeof(optional hdr)		*/
name|char
name|f_flags
index|[
literal|2
index|]
decl_stmt|;
comment|/* flags			*/
name|char
name|f_nsyms
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of symtab entries	*/
block|}
struct|;
end_struct

begin_comment
comment|/* IBM RS/6000.  */
end_comment

begin_define
define|#
directive|define
name|U803XTOCMAGIC
value|0757
end_define

begin_comment
comment|/* Aix 4.3 64-bit XCOFF */
end_comment

begin_define
define|#
directive|define
name|U64_TOCMAGIC
value|0767
end_define

begin_comment
comment|/* AIX 5+ 64-bit XCOFF */
end_comment

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != U803XTOCMAGIC&& (x).f_magic != U64_TOCMAGIC)
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
block|{
name|unsigned
name|char
name|magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* type of file			*/
name|unsigned
name|char
name|vstamp
index|[
literal|2
index|]
decl_stmt|;
comment|/* version stamp		*/
name|unsigned
name|char
name|o_debugger
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved 			*/
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
name|o_toc
index|[
literal|8
index|]
decl_stmt|;
comment|/* address of TOC */
name|unsigned
name|char
name|o_snentry
index|[
literal|2
index|]
decl_stmt|;
comment|/* section number of entry point */
name|unsigned
name|char
name|o_sntext
index|[
literal|2
index|]
decl_stmt|;
comment|/* section number of .text section */
name|unsigned
name|char
name|o_sndata
index|[
literal|2
index|]
decl_stmt|;
comment|/* section number of .data section */
name|unsigned
name|char
name|o_sntoc
index|[
literal|2
index|]
decl_stmt|;
comment|/* section number of TOC */
name|unsigned
name|char
name|o_snloader
index|[
literal|2
index|]
decl_stmt|;
comment|/* section number of .loader section */
name|unsigned
name|char
name|o_snbss
index|[
literal|2
index|]
decl_stmt|;
comment|/* section number of .bss section */
name|unsigned
name|char
name|o_algntext
index|[
literal|2
index|]
decl_stmt|;
comment|/* .text alignment */
name|unsigned
name|char
name|o_algndata
index|[
literal|2
index|]
decl_stmt|;
comment|/* .data alignment */
name|unsigned
name|char
name|o_modtype
index|[
literal|2
index|]
decl_stmt|;
comment|/* module type (??) */
name|unsigned
name|char
name|o_cputype
index|[
literal|2
index|]
decl_stmt|;
comment|/* cpu type */
name|unsigned
name|char
name|o_resv2
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved 			*/
name|unsigned
name|char
name|tsize
index|[
literal|8
index|]
decl_stmt|;
comment|/* text size bytes, padded to FW bdry */
name|unsigned
name|char
name|dsize
index|[
literal|8
index|]
decl_stmt|;
comment|/* initialized data "  "	*/
name|unsigned
name|char
name|bsize
index|[
literal|8
index|]
decl_stmt|;
comment|/* uninitialized data "   "	*/
name|unsigned
name|char
name|entry
index|[
literal|8
index|]
decl_stmt|;
comment|/* entry pt.			*/
name|unsigned
name|char
name|o_maxstack
index|[
literal|8
index|]
decl_stmt|;
comment|/* max stack size (??) 		*/
name|unsigned
name|char
name|o_maxdata
index|[
literal|8
index|]
decl_stmt|;
comment|/* max data size (??) 		*/
name|unsigned
name|char
name|o_resv3
index|[
literal|16
index|]
decl_stmt|;
comment|/* reserved 			*/
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AOUTSZ
value|120
end_define

begin_define
define|#
directive|define
name|SMALL_AOUTSZ
value|(0)
end_define

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|72
end_define

begin_comment
comment|/********************** SECTION HEADER **********************/
end_comment

begin_struct
struct|struct
name|external_scnhdr
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* section name			*/
name|char
name|s_paddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|char
name|s_vaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* virtual address		*/
name|char
name|s_size
index|[
literal|8
index|]
decl_stmt|;
comment|/* section size			*/
name|char
name|s_scnptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file ptr to raw data for section */
name|char
name|s_relptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file ptr to relocation	*/
name|char
name|s_lnnoptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* file ptr to line numbers	*/
name|char
name|s_nreloc
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of relocation entries	*/
name|char
name|s_nlnno
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of line number entries*/
name|char
name|s_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* flags			*/
name|char
name|s_pad
index|[
literal|4
index|]
decl_stmt|;
comment|/* padding */
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
value|72
end_define

begin_comment
comment|/********************** LINE NUMBERS **********************/
end_comment

begin_comment
comment|/* 1 line number entry for every "breakpointable" source line in a section.    Line numbers are grouped on a per function basis; first entry in a function    grouping will have l_lnno = 0 and in place of physical address will be the    symbol table index of the function name.  */
end_comment

begin_struct
struct|struct
name|external_lineno
block|{
union|union
block|{
name|char
name|l_symndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* function name symbol index, iff l_lnno == 0*/
name|char
name|l_paddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* (physical) address of line number	*/
block|}
name|l_addr
union|;
name|char
name|l_lnno
index|[
literal|4
index|]
decl_stmt|;
comment|/* line number		*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LINENO
value|struct external_lineno
end_define

begin_define
define|#
directive|define
name|LINESZ
value|12
end_define

begin_comment
comment|/********************** SYMBOLS **********************/
end_comment

begin_define
define|#
directive|define
name|E_SYMNMLEN
value|8
end_define

begin_comment
comment|/* # characters in a symbol name	*/
end_comment

begin_define
define|#
directive|define
name|E_FILNMLEN
value|14
end_define

begin_comment
comment|/* # characters in a file name		*/
end_comment

begin_define
define|#
directive|define
name|E_DIMNUM
value|4
end_define

begin_comment
comment|/* # array dimensions in auxiliary entry */
end_comment

begin_struct
struct|struct
name|external_syment
block|{
name|char
name|e_value
index|[
literal|8
index|]
decl_stmt|;
name|char
name|e_offset
index|[
literal|4
index|]
decl_stmt|;
name|char
name|e_scnum
index|[
literal|2
index|]
decl_stmt|;
name|char
name|e_type
index|[
literal|2
index|]
decl_stmt|;
name|char
name|e_sclass
index|[
literal|1
index|]
decl_stmt|;
name|char
name|e_numaux
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

begin_union
union|union
name|external_auxent
block|{
struct|struct
block|{
union|union
block|{
struct|struct
block|{
name|char
name|x_lnno
index|[
literal|4
index|]
decl_stmt|;
comment|/* declaration line number */
name|char
name|x_size
index|[
literal|2
index|]
decl_stmt|;
comment|/* str/union/array size */
block|}
name|x_lnsz
struct|;
struct|struct
block|{
name|char
name|x_lnnoptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* ptr to fcn line */
name|char
name|x_fsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* size of function */
name|char
name|x_endndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry ndx past block end */
block|}
name|x_fcn
struct|;
block|}
name|x_fcnary
union|;
block|}
name|x_sym
struct|;
union|union
block|{
name|char
name|x_fname
index|[
name|E_FILNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|char
name|x_zeroes
index|[
literal|4
index|]
decl_stmt|;
name|char
name|x_offset
index|[
literal|4
index|]
decl_stmt|;
name|char
name|x_pad
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|char
name|x_ftype
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|x_resv
index|[
literal|2
index|]
decl_stmt|;
block|}
name|x_n
struct|;
block|}
name|x_file
union|;
struct|struct
block|{
name|char
name|x_exptr
index|[
literal|8
index|]
decl_stmt|;
name|char
name|x_fsize
index|[
literal|4
index|]
decl_stmt|;
name|char
name|x_endndx
index|[
literal|4
index|]
decl_stmt|;
name|char
name|x_pad
index|[
literal|1
index|]
decl_stmt|;
block|}
name|x_except
struct|;
struct|struct
block|{
name|unsigned
name|char
name|x_scnlen_lo
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|x_parmhash
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|x_snhash
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|x_smtyp
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|x_smclas
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|x_scnlen_hi
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|x_pad
index|[
literal|1
index|]
decl_stmt|;
block|}
name|x_csect
struct|;
struct|struct
block|{
name|char
name|x_pad
index|[
literal|17
index|]
decl_stmt|;
name|char
name|x_auxtype
index|[
literal|1
index|]
decl_stmt|;
block|}
name|x_auxtype
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|SYMENT
value|struct external_syment
end_define

begin_define
define|#
directive|define
name|SYMESZ
value|18
end_define

begin_define
define|#
directive|define
name|AUXENT
value|union external_auxent
end_define

begin_define
define|#
directive|define
name|AUXESZ
value|18
end_define

begin_define
define|#
directive|define
name|DBXMASK
value|0x80
end_define

begin_comment
comment|/* for dbx storage mask */
end_comment

begin_define
define|#
directive|define
name|SYMNAME_IN_DEBUG
parameter_list|(
name|symptr
parameter_list|)
value|((symptr)->n_sclass& DBXMASK)
end_define

begin_comment
comment|/* Values for auxtype field in XCOFF64, taken from AIX 4.3 sym.h.  */
end_comment

begin_define
define|#
directive|define
name|_AUX_EXCEPT
value|255
end_define

begin_define
define|#
directive|define
name|_AUX_FCN
value|254
end_define

begin_define
define|#
directive|define
name|_AUX_SYM
value|253
end_define

begin_define
define|#
directive|define
name|_AUX_FILE
value|252
end_define

begin_define
define|#
directive|define
name|_AUX_CSECT
value|251
end_define

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_struct
struct|struct
name|external_reloc
block|{
name|char
name|r_vaddr
index|[
literal|8
index|]
decl_stmt|;
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
name|char
name|r_size
index|[
literal|1
index|]
decl_stmt|;
name|char
name|r_type
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
name|RELOC
value|struct external_reloc
end_define

begin_define
define|#
directive|define
name|RELSZ
value|14
end_define

begin_define
define|#
directive|define
name|DEFAULT_DATA_SECTION_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_BSS_SECTION_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_TEXT_SECTION_ALIGNMENT
value|4
end_define

begin_comment
comment|/* For new sections we havn't heard of before */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SECTION_ALIGNMENT
value|4
end_define

begin_comment
comment|/* The ldhdr structure.  This appears at the start of the .loader    section.  */
end_comment

begin_struct
struct|struct
name|external_ldhdr
block|{
name|bfd_byte
name|l_version
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_nsyms
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_nreloc
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_istlen
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_nimpid
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_stlen
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_impoff
index|[
literal|8
index|]
decl_stmt|;
name|bfd_byte
name|l_stoff
index|[
literal|8
index|]
decl_stmt|;
name|bfd_byte
name|l_symoff
index|[
literal|8
index|]
decl_stmt|;
name|bfd_byte
name|l_rldoff
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LDHDRSZ
value|(56)
end_define

begin_struct
struct|struct
name|external_ldsym
block|{
name|bfd_byte
name|l_value
index|[
literal|8
index|]
decl_stmt|;
name|bfd_byte
name|l_offset
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_scnum
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|l_smtype
index|[
literal|1
index|]
decl_stmt|;
name|bfd_byte
name|l_smclas
index|[
literal|1
index|]
decl_stmt|;
name|bfd_byte
name|l_ifile
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_parm
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
name|LDSYMSZ
value|(24)
end_define

begin_struct
struct|struct
name|external_ldrel
block|{
name|bfd_byte
name|l_vaddr
index|[
literal|8
index|]
decl_stmt|;
name|bfd_byte
name|l_rtype
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|l_rsecnm
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|l_symndx
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
name|LDRELSZ
value|(16)
end_define

end_unit

