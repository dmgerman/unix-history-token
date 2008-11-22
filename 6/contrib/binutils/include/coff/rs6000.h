begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IBM RS/6000 "XCOFF" file definitions for BFD.    Copyright (C) 1990, 1991 Free Software Foundation, Inc.    FIXME: Can someone provide a transliteration of this name into ASCII?    Using the following chars caused a compiler warning on HIUX (so I replaced    them with octal escapes), and isn't useful without an understanding of what    character set it is.    Written by Mimi Ph\373\364ng-Th\345o V\365 of IBM    and John Gilmore of Cygnus Support.  */
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

begin_comment
comment|/* IBM RS/6000 */
end_comment

begin_define
define|#
directive|define
name|U802WRMAGIC
value|0730
end_define

begin_comment
comment|/* writeable text segments **chh**      */
end_comment

begin_define
define|#
directive|define
name|U802ROMAGIC
value|0735
end_define

begin_comment
comment|/* readonly sharable text segments      */
end_comment

begin_define
define|#
directive|define
name|U802TOCMAGIC
value|0737
end_define

begin_comment
comment|/* readonly text segments and TOC       */
end_comment

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
define|\
value|((x).f_magic != U802ROMAGIC&& (x).f_magic != U802WRMAGIC&& \ 	 (x).f_magic != U802TOCMAGIC)
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
value|20
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
name|tsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry */
name|unsigned
name|char
name|dsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* initialized data "  "	*/
name|unsigned
name|char
name|bsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* uninitialized data "   "	*/
name|unsigned
name|char
name|entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry pt.			*/
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
name|o_toc
index|[
literal|4
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
name|o_maxstack
index|[
literal|4
index|]
decl_stmt|;
comment|/* max stack size (??) */
name|unsigned
name|char
name|o_maxdata
index|[
literal|4
index|]
decl_stmt|;
comment|/* max data size (??) */
name|unsigned
name|char
name|o_resv2
index|[
literal|12
index|]
decl_stmt|;
comment|/* reserved */
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AOUTSZ
value|72
end_define

begin_define
define|#
directive|define
name|SMALL_AOUTSZ
value|(28)
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
literal|2
index|]
decl_stmt|;
comment|/* number of relocation entries	*/
name|char
name|s_nlnno
index|[
literal|2
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
value|40
end_define

begin_comment
comment|/********************** LINE NUMBERS **********************/
end_comment

begin_comment
comment|/* 1 line number entry for every "breakpointable" source line in a section.  * Line numbers are grouped on a per function basis; first entry in a function  * grouping will have l_lnno = 0 and in place of physical address will be the  * symbol table index of the function name.  */
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
literal|2
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
value|6
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
block|{
comment|/* if ISFCN, tag, or .bb */
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
block|{
comment|/* if ISARY, up to 4 dimen. */
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
struct|struct
block|{
name|unsigned
name|char
name|x_scnlen
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
name|x_stab
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|x_snstab
index|[
literal|2
index|]
decl_stmt|;
block|}
name|x_csect
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
value|10
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
name|l_impoff
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
name|l_stoff
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
name|LDHDRSZ
value|(8 * 4)
end_define

begin_struct
struct|struct
name|external_ldsym
block|{
union|union
block|{
name|bfd_byte
name|_l_name
index|[
name|SYMNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|bfd_byte
name|_l_zeroes
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|_l_offset
index|[
literal|4
index|]
decl_stmt|;
block|}
name|_l_l
struct|;
block|}
name|_l
union|;
name|bfd_byte
name|l_value
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
value|(8 + 3 * 4 + 2 + 2)
end_define

begin_struct
struct|struct
name|external_ldrel
block|{
name|bfd_byte
name|l_vaddr
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|l_symndx
index|[
literal|4
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LDRELSZ
value|(2 * 4 + 2 * 2)
end_define

end_unit

