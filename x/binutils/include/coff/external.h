begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* external.h  -- External COFF structures        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_EXTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|COFF_EXTERNAL_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DO_NOT_DEFINE_FILHDR
end_ifndef

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
literal|4
index|]
decl_stmt|;
comment|/* file pointer to symtab	*/
name|char
name|f_nsyms
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of symtab entries	*/
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
block|}
struct|;
end_struct

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
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DO_NOT_DEFINE_AOUTHDR
end_ifndef

begin_comment
comment|/********************** AOUT "OPTIONAL HEADER" **********************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|external_aouthdr
block|{
name|char
name|magic
index|[
literal|2
index|]
decl_stmt|;
comment|/* type of file				*/
name|char
name|vstamp
index|[
literal|2
index|]
decl_stmt|;
comment|/* version stamp			*/
name|char
name|tsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry*/
name|char
name|dsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* initialized data "  "		*/
name|char
name|bsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* uninitialized data "   "		*/
name|char
name|entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry pt.				*/
name|char
name|text_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of text used for this file 	*/
name|char
name|data_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of data used for this file 	*/
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|28
end_define

begin_define
define|#
directive|define
name|AOUTSZ
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DO_NOT_DEFINE_SCNHDR
end_ifndef

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
comment|/* section name				*/
name|char
name|s_paddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* physical address, aliased s_nlib 	*/
name|char
name|s_vaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* virtual address			*/
name|char
name|s_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* section size				*/
name|char
name|s_scnptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to raw data for section 	*/
name|char
name|s_relptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to relocation		*/
name|char
name|s_lnnoptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to line numbers		*/
name|char
name|s_nreloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of relocation entries		*/
name|char
name|s_nlnno
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of line number entries	*/
name|char
name|s_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* flags				*/
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
value|40
end_define

begin_comment
comment|/* Names of "special" sections.  */
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
name|_COMMENT
value|".comment"
end_define

begin_define
define|#
directive|define
name|_LIB
value|".lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DO_NOT_DEFINE_SCNHDR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DO_NOT_DEFINE_LINENO
end_ifndef

begin_comment
comment|/********************** LINE NUMBERS **********************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|L_LNNO_SIZE
end_ifndef

begin_error
error|#
directive|error
error|L_LNNO_SIZE needs to be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

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
literal|4
index|]
decl_stmt|;
comment|/* (physical) address of line number	*/
block|}
name|l_addr
union|;
name|char
name|l_lnno
index|[
name|L_LNNO_SIZE
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
value|(4 + L_LNNO_SIZE)
end_define

begin_if
if|#
directive|if
name|L_LNNO_SIZE
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|GET_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
value|H_GET_32 (abfd,      (ext->l_lnno))
end_define

begin_define
define|#
directive|define
name|PUT_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ext
parameter_list|)
value|H_PUT_32 (abfd, val, (ext->l_lnno))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|L_LNNO_SIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|GET_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
value|H_GET_16 (abfd,      (ext->l_lnno))
end_define

begin_define
define|#
directive|define
name|PUT_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ext
parameter_list|)
value|H_PUT_16 (abfd, val, (ext->l_lnno))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DO_NOT_DEFINE_LINENO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DO_NOT_DEFINE_SYMENT
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|E_FILNMLEN
end_ifndef

begin_define
define|#
directive|define
name|E_FILNMLEN
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

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
union|union
block|{
name|char
name|e_name
index|[
name|E_SYMNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|char
name|e_zeroes
index|[
literal|4
index|]
decl_stmt|;
name|char
name|e_offset
index|[
literal|4
index|]
decl_stmt|;
block|}
name|e
struct|;
block|}
name|e
union|;
name|char
name|e_value
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
name|SYMENT
value|struct external_syment
end_define

begin_define
define|#
directive|define
name|SYMESZ
value|18
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|N_BTMASK
end_ifndef

begin_define
define|#
directive|define
name|N_BTMASK
value|0xf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_TMASK
end_ifndef

begin_define
define|#
directive|define
name|N_TMASK
value|0x30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_BTSHFT
end_ifndef

begin_define
define|#
directive|define
name|N_BTSHFT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_TSHIFT
end_ifndef

begin_define
define|#
directive|define
name|N_TSHIFT
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DO_NOT_DEFINE_SYMENT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DO_NOT_DEFINE_AUXENT
end_ifndef

begin_union
union|union
name|external_auxent
block|{
struct|struct
block|{
name|char
name|x_tagndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* str, un, or enum tag indx */
union|union
block|{
struct|struct
block|{
name|char
name|x_lnno
index|[
literal|2
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
name|char
name|x_fsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* size of function */
block|}
name|x_misc
union|;
union|union
block|{
struct|struct
comment|/* if ISFCN, tag, or .bb */
block|{
name|char
name|x_lnnoptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* ptr to fcn line # */
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
struct|struct
comment|/* if ISARY, up to 4 dimen. */
block|{
name|char
name|x_dimen
index|[
name|E_DIMNUM
index|]
index|[
literal|2
index|]
decl_stmt|;
block|}
name|x_ary
struct|;
block|}
name|x_fcnary
union|;
name|char
name|x_tvndx
index|[
literal|2
index|]
decl_stmt|;
comment|/* tv index */
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
block|}
name|x_n
struct|;
block|}
name|x_file
union|;
struct|struct
block|{
name|char
name|x_scnlen
index|[
literal|4
index|]
decl_stmt|;
comment|/* section length */
name|char
name|x_nreloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* # relocation entries */
name|char
name|x_nlinno
index|[
literal|2
index|]
decl_stmt|;
comment|/* # line numbers */
ifdef|#
directive|ifdef
name|INCLUDE_COMDAT_FIELDS_IN_AUXENT
name|char
name|x_checksum
index|[
literal|4
index|]
decl_stmt|;
comment|/* section COMDAT checksum	      */
name|char
name|x_associated
index|[
literal|2
index|]
decl_stmt|;
comment|/* COMDAT associated section index */
name|char
name|x_comdat
index|[
literal|1
index|]
decl_stmt|;
comment|/* COMDAT selection number	      */
endif|#
directive|endif
block|}
name|x_scn
struct|;
struct|struct
block|{
name|char
name|x_tvfill
index|[
literal|4
index|]
decl_stmt|;
comment|/* tv fill value */
name|char
name|x_tvlen
index|[
literal|2
index|]
decl_stmt|;
comment|/* length of .tv */
name|char
name|x_tvran
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* tv range */
block|}
name|x_tv
struct|;
comment|/* info about .tv section (in auxent of symbol .tv)) */
block|}
union|;
end_union

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
name|_ETEXT
value|"etext"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DO_NOT_DEFINE_AUXENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF_EXTERNAL_H */
end_comment

end_unit

