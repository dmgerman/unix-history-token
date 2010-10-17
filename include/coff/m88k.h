begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for 88k bcs        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|DO_NOT_DEFINE_SCNHDR
end_define

begin_define
define|#
directive|define
name|L_LNNO_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|DO_NOT_DEFINE_SYMENT
end_define

begin_define
define|#
directive|define
name|DO_NOT_DEFINE_AUXENT
end_define

begin_include
include|#
directive|include
file|"coff/external.h"
end_include

begin_define
define|#
directive|define
name|MC88MAGIC
value|0540
end_define

begin_comment
comment|/* 88k BCS executable */
end_comment

begin_define
define|#
directive|define
name|MC88DMAGIC
value|0541
end_define

begin_comment
comment|/* DG/UX executable   */
end_comment

begin_define
define|#
directive|define
name|MC88OMAGIC
value|0555
end_define

begin_comment
comment|/* Object file        */
end_comment

begin_define
define|#
directive|define
name|MC88BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != MC88MAGIC) \&& ((x).f_magic != MC88DMAGIC) \&& ((x).f_magic != MC88OMAGIC))
end_define

begin_define
define|#
directive|define
name|PAGEMAGIC3
value|0414
end_define

begin_comment
comment|/* Split i&d, zero mapped */
end_comment

begin_define
define|#
directive|define
name|PAGEMAGICBCS
value|0413
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
literal|4
index|]
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|char
name|s_vaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* virtual address		*/
name|char
name|s_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* section size			*/
name|char
name|s_scnptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to raw data for section */
name|char
name|s_relptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to relocation	*/
name|char
name|s_lnnoptr
index|[
literal|4
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
value|44
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
name|char
name|pad2
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
name|N_BTMASK
value|017
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|060
end_define

begin_define
define|#
directive|define
name|N_BTSHFT
value|4
end_define

begin_define
define|#
directive|define
name|N_TSHIFT
value|2
end_define

begin_comment
comment|/* Note that this isn't the same shape as other coffs */
end_comment

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
comment|/* 4 */
union|union
block|{
name|char
name|x_fsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* size of function */
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
literal|4
index|]
decl_stmt|;
comment|/* str/union/array size */
block|}
name|x_lnsz
struct|;
block|}
name|x_misc
union|;
comment|/* 12 */
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
comment|/* 20 */
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
literal|4
index|]
decl_stmt|;
comment|/* # relocation entries */
name|char
name|x_nlinno
index|[
literal|4
index|]
decl_stmt|;
comment|/* # line numbers */
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
name|GET_LNSZ_SIZE
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_32 (abfd, ext->x_sym.x_misc.x_lnsz.x_size)
end_define

begin_define
define|#
directive|define
name|GET_LNSZ_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_32 (abfd, ext->x_sym.x_misc.x_lnsz.x_lnno)
end_define

begin_define
define|#
directive|define
name|PUT_LNSZ_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_32 (abfd, in, ext->x_sym.x_misc.x_lnsz.x_lnno)
end_define

begin_define
define|#
directive|define
name|PUT_LNSZ_SIZE
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_32 (abfd, in, ext->x_sym.x_misc.x_lnsz.x_size)
end_define

begin_define
define|#
directive|define
name|GET_SCN_NRELOC
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_32 (abfd, ext->x_scn.x_nreloc)
end_define

begin_define
define|#
directive|define
name|GET_SCN_NLINNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_32 (abfd, ext->x_scn.x_nlinno)
end_define

begin_define
define|#
directive|define
name|PUT_SCN_NRELOC
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_32 (abfd, in, ext->x_scn.x_nreloc)
end_define

begin_define
define|#
directive|define
name|PUT_SCN_NLINNO
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_32 (abfd,in, ext->x_scn.x_nlinno)
end_define

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
value|20
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
value|20
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
literal|4
index|]
decl_stmt|;
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
name|char
name|r_type
index|[
literal|2
index|]
decl_stmt|;
name|char
name|r_offset
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
name|RELOC
value|struct external_reloc
end_define

begin_define
define|#
directive|define
name|RELSZ
value|12
end_define

begin_define
define|#
directive|define
name|NO_TVNDX
end_define

end_unit

