begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF spec for AMD 290*0     Contributed by David Wood @ New York University.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMD
end_ifndef

begin_define
define|#
directive|define
name|AMD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************/
end_comment

begin_comment
comment|/* ** File Header and related definitions */
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
comment|/* magic number		 */
name|char
name|f_nscns
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sections	   */
name|char
name|f_timdat
index|[
literal|4
index|]
decl_stmt|;
comment|/* time& date stamp	    */
name|char
name|f_symptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file pointer to symtab       */
name|char
name|f_nsyms
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of symtab entries     */
name|char
name|f_opthdr
index|[
literal|2
index|]
decl_stmt|;
comment|/* sizeof(optional hdr)	 */
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
value|sizeof (FILHDR)
end_define

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Magic numbers for Am29000  **	(AT&T will assign the "real" magic number)   */
end_comment

begin_define
define|#
directive|define
name|SIPFBOMAGIC
value|0572
end_define

begin_comment
comment|/* Am29000 (Byte 0 is MSB) */
end_comment

begin_define
define|#
directive|define
name|SIPRBOMAGIC
value|0573
end_define

begin_comment
comment|/* Am29000 (Byte 0 is LSB) */
end_comment

begin_define
define|#
directive|define
name|A29K_MAGIC_BIG
value|SIPFBOMAGIC
end_define

begin_define
define|#
directive|define
name|A29K_MAGIC_LITTLE
value|SIPRBOMAGIC
end_define

begin_define
define|#
directive|define
name|A29KBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic!=A29K_MAGIC_BIG)&& \ 			  ((x).f_magic!=A29K_MAGIC_LITTLE))
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|A29K_MAGIC_BIG
end_define

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** File header flags currently known to us. ** ** Am29000 will use the F_AR32WR and F_AR32W flags to indicate ** the byte ordering in the file. */
end_comment

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ** Optional (a.out) header  */
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
comment|/* type of file			 */
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
comment|/* uninitialized data "   "	     */
name|char
name|entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry pt.			    */
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
block|}
name|AOUTHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AOUTSZ
value|(sizeof(AOUTHDR))
end_define

begin_define
define|#
directive|define
name|AOUTHDRSZ
value|(sizeof(AOUTHDR))
end_define

begin_comment
comment|/* aouthdr magic numbers */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* separate i/d executable */
end_comment

begin_define
define|#
directive|define
name|SHMAGIC
value|0406
end_define

begin_comment
comment|/* NYU/Ultra3 shared data executable  				   (writable text) */
end_comment

begin_define
define|#
directive|define
name|_ETEXT
value|"_etext"
end_define

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ** Section header and related definitions */
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
comment|/* section name		 */
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
comment|/* virtual address	      */
name|char
name|s_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* section size		 */
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
comment|/* file ptr to relocation       */
name|char
name|s_lnnoptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to line numbers     */
name|char
name|s_nreloc
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of relocation entries */
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
value|struct	external_scnhdr
end_define

begin_define
define|#
directive|define
name|SCNHSZ
value|sizeof	(SCNHDR)
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

begin_define
define|#
directive|define
name|_LIT
value|".lit"
end_define

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Section types - with additional section type for global  ** registers which will be relocatable for the Am29000. ** ** In instances where it is necessary for a linker to produce an ** output file which contains text or data not based at virtual ** address 0, e.g. for a ROM, then the linker should accept ** address base information as command input and use PAD sections ** to skip over unused addresses. */
end_comment

begin_define
define|#
directive|define
name|STYP_BSSREG
value|0x1200
end_define

begin_comment
comment|/* Global register area (like STYP_INFO) */
end_comment

begin_define
define|#
directive|define
name|STYP_ENVIR
value|0x2200
end_define

begin_comment
comment|/* Environment (like STYP_INFO) */
end_comment

begin_define
define|#
directive|define
name|STYP_ABS
value|0x4000
end_define

begin_comment
comment|/* Absolute (allocated, not reloc, loaded) */
end_comment

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ** Relocation information declaration and related definitions */
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
comment|/* (virtual) address of reference */
name|char
name|r_symndx
index|[
literal|4
index|]
decl_stmt|;
comment|/* index into symbol table */
name|char
name|r_type
index|[
literal|2
index|]
decl_stmt|;
comment|/* relocation type */
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

begin_comment
comment|/* sizeof (RELOC) */
end_comment

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Relocation types for the Am29000  */
end_comment

begin_define
define|#
directive|define
name|R_ABS
value|0
end_define

begin_comment
comment|/* reference is absolute */
end_comment

begin_define
define|#
directive|define
name|R_IREL
value|030
end_define

begin_comment
comment|/* instruction relative (jmp/call) */
end_comment

begin_define
define|#
directive|define
name|R_IABS
value|031
end_define

begin_comment
comment|/* instruction absolute (jmp/call) */
end_comment

begin_define
define|#
directive|define
name|R_ILOHALF
value|032
end_define

begin_comment
comment|/* instruction low half  (const)  */
end_comment

begin_define
define|#
directive|define
name|R_IHIHALF
value|033
end_define

begin_comment
comment|/* instruction high half (consth) part 1 */
end_comment

begin_define
define|#
directive|define
name|R_IHCONST
value|034
end_define

begin_comment
comment|/* instruction high half (consth) part 2 */
end_comment

begin_comment
comment|/* constant offset of R_IHIHALF relocation */
end_comment

begin_define
define|#
directive|define
name|R_BYTE
value|035
end_define

begin_comment
comment|/* relocatable byte value */
end_comment

begin_define
define|#
directive|define
name|R_HWORD
value|036
end_define

begin_comment
comment|/* relocatable halfword value */
end_comment

begin_define
define|#
directive|define
name|R_WORD
value|037
end_define

begin_comment
comment|/* relocatable word value */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRC
value|040
end_define

begin_comment
comment|/* instruction global register RC */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRA
value|041
end_define

begin_comment
comment|/* instruction global register RA */
end_comment

begin_define
define|#
directive|define
name|R_IGLBLRB
value|042
end_define

begin_comment
comment|/* instruction global register RB */
end_comment

begin_comment
comment|/* NOTE: All the "I" forms refer to 29000 instruction formats.  The linker is  expected to know how the numeric information is split and/or aligned within the instruction word(s).  R_BYTE works for instructions, too.  If the parameter to a CONSTH instruction is a relocatable type, two  relocation records are written.  The first has an r_type of R_IHIHALF  (33 octal) and a normal r_vaddr and r_symndx.  The second relocation  record has an r_type of R_IHCONST (34 octal), a normal r_vaddr (which  is redundant), and an r_symndx containing the 32-bit constant offset  to the relocation instead of the actual symbol table index.  This  second record is always written, even if the constant offset is zero. The constant fields of the instruction are set to zero. */
end_comment

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ** Line number entry declaration and related definitions */
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
comment|/* (physical) address of line number    */
block|}
name|l_addr
union|;
name|char
name|l_lnno
index|[
literal|2
index|]
decl_stmt|;
comment|/* line number	  */
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
comment|/* sizeof (LINENO) */
end_comment

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ** Symbol entry declaration and related definitions */
end_comment

begin_define
define|#
directive|define
name|E_SYMNMLEN
value|8
end_define

begin_comment
comment|/* Number of characters in a symbol name */
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
value|sizeof(SYMENT)
end_define

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Storage class definitions - new classes for global registers. */
end_comment

begin_define
define|#
directive|define
name|C_GLBLREG
value|19
end_define

begin_comment
comment|/* global register */
end_comment

begin_define
define|#
directive|define
name|C_EXTREG
value|20
end_define

begin_comment
comment|/* external global register */
end_comment

begin_define
define|#
directive|define
name|C_DEFREG
value|21
end_define

begin_comment
comment|/* ext. def. of global register */
end_comment

begin_comment
comment|/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
end_comment

begin_comment
comment|/* ** Derived symbol mask/shifts. */
end_comment

begin_define
define|#
directive|define
name|N_BTMASK
value|(0xf)
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
name|N_TMASK
value|(0x30)
end_define

begin_define
define|#
directive|define
name|N_TSHIFT
value|(2)
end_define

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/* ** Auxiliary symbol table entry declaration and related  ** definitions. */
end_comment

begin_define
define|#
directive|define
name|E_FILNMLEN
value|14
end_define

begin_comment
comment|/* # characters in a file name	  */
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

end_unit

