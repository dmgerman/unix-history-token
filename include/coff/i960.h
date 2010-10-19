begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* coff information for 80960.  Origins: Intel corp, natch.        Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* NOTE: Tagentries (cf TAGBITS) are no longer used by the 960 */
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

begin_define
define|#
directive|define
name|OMAGIC
value|(0407)
end_define

begin_comment
comment|/* old impure format. data immediately                                    follows text. both sections are rw. */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|(0410)
end_define

begin_comment
comment|/* split i&d, read-only text */
end_comment

begin_comment
comment|/* *	Intel 80960 (I960) processor flags. *	F_I960TYPE == mask for processor type field.  */
end_comment

begin_define
define|#
directive|define
name|F_I960TYPE
value|(0xf000)
end_define

begin_define
define|#
directive|define
name|F_I960CORE
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|F_I960KB
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|F_I960SB
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|F_I960MC
value|(0x3000)
end_define

begin_define
define|#
directive|define
name|F_I960XA
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|F_I960CA
value|(0x5000)
end_define

begin_define
define|#
directive|define
name|F_I960KA
value|(0x6000)
end_define

begin_define
define|#
directive|define
name|F_I960SA
value|(0x6000)
end_define

begin_define
define|#
directive|define
name|F_I960JX
value|(0x7000)
end_define

begin_define
define|#
directive|define
name|F_I960HX
value|(0x8000)
end_define

begin_comment
comment|/** i80960 Magic Numbers */
end_comment

begin_define
define|#
directive|define
name|I960ROMAGIC
value|(0x160)
end_define

begin_comment
comment|/* read-only text segments */
end_comment

begin_define
define|#
directive|define
name|I960RWMAGIC
value|(0x161)
end_define

begin_comment
comment|/* read-write text segments */
end_comment

begin_define
define|#
directive|define
name|I960BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic!=I960ROMAGIC)&& ((x).f_magic!=I960RWMAGIC))
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
name|long
name|phys_addr
decl_stmt|;
name|unsigned
name|long
name|bitarray
decl_stmt|;
block|}
name|TAGBITS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
comment|/* base of text used for this file */
name|char
name|data_start
index|[
literal|4
index|]
decl_stmt|;
comment|/* base of data used for this file */
name|char
name|tagentries
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of tag entries to follow */
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_comment
comment|/* return a pointer to the tag bits array */
end_comment

begin_define
define|#
directive|define
name|TAGPTR
parameter_list|(
name|aout
parameter_list|)
value|((TAGBITS *) (&(aout.tagentries)+1))
end_define

begin_comment
comment|/* compute size of a header */
end_comment

begin_comment
comment|/*#define AOUTSZ(aout) (sizeof(AOUTHDR)+(aout.tagentries*sizeof(TAGBITS)))*/
end_comment

begin_define
define|#
directive|define
name|AOUTSZ
value|32
end_define

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|32
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
name|char
name|s_align
index|[
literal|4
index|]
decl_stmt|;
comment|/* section alignment		*/
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
comment|/*  * names of "special" sections  */
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
name|char
name|padding
index|[
literal|2
index|]
decl_stmt|;
comment|/* force alignment	*/
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
value|8
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
name|e_flags
index|[
literal|2
index|]
decl_stmt|;
name|char
name|e_type
index|[
literal|4
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
value|(0x1f)
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|(0x60)
end_define

begin_define
define|#
directive|define
name|N_BTSHFT
value|(5)
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
comment|/******************************************    *  I960-specific *2nd* aux. entry formats    ******************************************/
struct|struct
block|{
comment|/* This is a very old typo that keeps getting propagated. */
define|#
directive|define
name|x_stdindx
value|x_stindx
name|char
name|x_stindx
index|[
literal|4
index|]
decl_stmt|;
comment|/* sys. table entry */
block|}
name|x_sc
struct|;
comment|/* system call entry */
struct|struct
block|{
name|char
name|x_balntry
index|[
literal|4
index|]
decl_stmt|;
comment|/* BAL entry point */
block|}
name|x_bal
struct|;
comment|/* BAL-callable function */
struct|struct
block|{
name|char
name|x_timestamp
index|[
literal|4
index|]
decl_stmt|;
comment|/* time stamp */
name|char
name|x_idstring
index|[
literal|20
index|]
decl_stmt|;
comment|/* producer identity string */
block|}
name|x_ident
struct|;
comment|/* Producer ident info */
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
value|24
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
value|24
end_define

begin_define
define|#
directive|define
name|_ETEXT
value|"_etext"
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
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* r_type values for the i960.  */
end_comment

begin_comment
comment|/* The i960 uses R_RELLONG, which is defined in internal.h as 0x11.    It is an absolute 32 bit relocation.  */
end_comment

begin_define
define|#
directive|define
name|R_IPRMED
value|(0x19)
end_define

begin_comment
comment|/* 24-bit ip-relative relocation */
end_comment

begin_define
define|#
directive|define
name|R_OPTCALL
value|(0x1b)
end_define

begin_comment
comment|/* 32-bit optimizable call (leafproc/sysproc) */
end_comment

begin_define
define|#
directive|define
name|R_OPTCALLX
value|(0x1c)
end_define

begin_comment
comment|/* 64-bit optimizable call (leafproc/sysproc) */
end_comment

begin_comment
comment|/* The following relocation types are defined use by relaxing linkers,    which convert 32 bit calls (which require a 64 bit instruction)    into 24 bit calls (which require a 32 bit instruction) when    possible.  It will be possible whenever the target of the call is    within a 24 bit range of the call instruction.     It is always safe to ignore these relocations.  They only serve to    mark points which the relaxing linker will have to consider.  The    assembler must ensure that the correct code is generated even if    the relocations are ignored.  In particular, this means that the    R_IPR13 relocation may not appear with an external symbol.  */
end_comment

begin_define
define|#
directive|define
name|R_IPR13
value|(0x1d)
end_define

begin_comment
comment|/* 13 bit ip-relative branch */
end_comment

begin_define
define|#
directive|define
name|R_ALIGN
value|(0x1e)
end_define

begin_comment
comment|/* alignment marker.  This has no 				   associated symbol.  Instead, the 				   r_symndx field indicates the 				   require alignment at this point in 				   the file.  It must be a power of 2.  */
end_comment

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

end_unit

