begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*** coff information for we32k */
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
comment|/* Bits for f_flags:  *	F_RELFLG	relocation info stripped from file  *	F_EXEC		file is executable (no unresolved external references)  *	F_LNNO		line numbers stripped from file  *	F_LSYMS		local symbols stripped from file  *	F_AR32WR	file has byte ordering of an AR32WR machine (e.g. vax)  */
end_comment

begin_define
define|#
directive|define
name|F_RELFLG
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|F_EXEC
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|F_LNNO
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|F_LSYMS
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|F_BM32B
value|(0020000)
end_define

begin_define
define|#
directive|define
name|F_BM32MAU
value|(0040000)
end_define

begin_define
define|#
directive|define
name|WE32KMAGIC
value|0x170
end_define

begin_comment
comment|/* we32k sans transfer vector */
end_comment

begin_define
define|#
directive|define
name|FBOMAGIC
value|0x170
end_define

begin_comment
comment|/* we32k sans transfer vector */
end_comment

begin_define
define|#
directive|define
name|MTVMAGIC
value|0x171
end_define

begin_comment
comment|/* we32k with transfer vector */
end_comment

begin_define
define|#
directive|define
name|RBOMAGIC
value|0x172
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|WE32KBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic != WE32KMAGIC) \&& ((x).f_magic != FBOMAGIC) \&& ((x).f_magic != RBOMAGIC) \&& ((x).f_magic != MTVMAGIC))
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
value|sizeof(FILHDR)
end_define

begin_comment
comment|/********************** AOUT "OPTIONAL HEADER" **********************/
end_comment

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

begin_comment
comment|/********************** STORAGE CLASSES **********************/
end_comment

begin_define
define|#
directive|define
name|C_EFCN
value|-1
end_define

begin_comment
comment|/* physical end of function	*/
end_comment

begin_define
define|#
directive|define
name|C_NULL
value|0
end_define

begin_define
define|#
directive|define
name|C_AUTO
value|1
end_define

begin_comment
comment|/* automatic variable		*/
end_comment

begin_define
define|#
directive|define
name|C_EXT
value|2
end_define

begin_comment
comment|/* external symbol		*/
end_comment

begin_define
define|#
directive|define
name|C_STAT
value|3
end_define

begin_comment
comment|/* static			*/
end_comment

begin_define
define|#
directive|define
name|C_REG
value|4
end_define

begin_comment
comment|/* register variable		*/
end_comment

begin_define
define|#
directive|define
name|C_EXTDEF
value|5
end_define

begin_comment
comment|/* external definition		*/
end_comment

begin_define
define|#
directive|define
name|C_LABEL
value|6
end_define

begin_comment
comment|/* label			*/
end_comment

begin_define
define|#
directive|define
name|C_ULABEL
value|7
end_define

begin_comment
comment|/* undefined label		*/
end_comment

begin_define
define|#
directive|define
name|C_MOS
value|8
end_define

begin_comment
comment|/* member of structure		*/
end_comment

begin_define
define|#
directive|define
name|C_ARG
value|9
end_define

begin_comment
comment|/* function argument		*/
end_comment

begin_define
define|#
directive|define
name|C_STRTAG
value|10
end_define

begin_comment
comment|/* structure tag		*/
end_comment

begin_define
define|#
directive|define
name|C_MOU
value|11
end_define

begin_comment
comment|/* member of union		*/
end_comment

begin_define
define|#
directive|define
name|C_UNTAG
value|12
end_define

begin_comment
comment|/* union tag			*/
end_comment

begin_define
define|#
directive|define
name|C_TPDEF
value|13
end_define

begin_comment
comment|/* type definition		*/
end_comment

begin_define
define|#
directive|define
name|C_USTATIC
value|14
end_define

begin_comment
comment|/* undefined static		*/
end_comment

begin_define
define|#
directive|define
name|C_ENTAG
value|15
end_define

begin_comment
comment|/* enumeration tag		*/
end_comment

begin_define
define|#
directive|define
name|C_MOE
value|16
end_define

begin_comment
comment|/* member of enumeration	*/
end_comment

begin_define
define|#
directive|define
name|C_REGPARM
value|17
end_define

begin_comment
comment|/* register parameter		*/
end_comment

begin_define
define|#
directive|define
name|C_FIELD
value|18
end_define

begin_comment
comment|/* bit field			*/
end_comment

begin_define
define|#
directive|define
name|C_AUTOARG
value|19
end_define

begin_comment
comment|/* auto argument		*/
end_comment

begin_define
define|#
directive|define
name|C_LASTENT
value|20
end_define

begin_comment
comment|/* dummy entry (end of block)	*/
end_comment

begin_define
define|#
directive|define
name|C_BLOCK
value|100
end_define

begin_comment
comment|/* ".bb" or ".eb"		*/
end_comment

begin_define
define|#
directive|define
name|C_FCN
value|101
end_define

begin_comment
comment|/* ".bf" or ".ef"		*/
end_comment

begin_define
define|#
directive|define
name|C_EOS
value|102
end_define

begin_comment
comment|/* end of structure		*/
end_comment

begin_define
define|#
directive|define
name|C_FILE
value|103
end_define

begin_comment
comment|/* file name			*/
end_comment

begin_define
define|#
directive|define
name|C_LINE
value|104
end_define

begin_comment
comment|/* line # reformatted as symbol table entry */
end_comment

begin_define
define|#
directive|define
name|C_ALIAS
value|105
end_define

begin_comment
comment|/* duplicate tag		*/
end_comment

begin_define
define|#
directive|define
name|C_HIDDEN
value|106
end_define

begin_comment
comment|/* ext symbol in dmert public lib */
end_comment

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
name|_TV
value|".tv"
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

begin_comment
comment|/*  * s_flags "type"  */
end_comment

begin_define
define|#
directive|define
name|STYP_REG
value|(0x0000)
end_define

begin_comment
comment|/* "regular": allocated, relocated, loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_DSECT
value|(0x0001)
end_define

begin_comment
comment|/* "dummy":  relocated only*/
end_comment

begin_define
define|#
directive|define
name|STYP_NOLOAD
value|(0x0002)
end_define

begin_comment
comment|/* "noload": allocated, relocated, not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_GROUP
value|(0x0004)
end_define

begin_comment
comment|/* "grouped": formed of input sections */
end_comment

begin_define
define|#
directive|define
name|STYP_PAD
value|(0x0008)
end_define

begin_comment
comment|/* "padding": not allocated, not relocated, loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_COPY
value|(0x0010)
end_define

begin_comment
comment|/* "copy": for decision function used by field update;  not allocated, not relocated, 				     loaded; reloc& lineno entries processed normally */
end_comment

begin_define
define|#
directive|define
name|STYP_TEXT
value|(0x0020)
end_define

begin_comment
comment|/* section contains text only */
end_comment

begin_define
define|#
directive|define
name|S_SHRSEG
value|(0x0020)
end_define

begin_comment
comment|/* In 3b Update files (output of ogen), sections which appear in SHARED segments of the Pfile 				     will have the S_SHRSEG flag set by ogen, to inform dufr that updating 1 copy of the proc. will 				     update all process invocations. */
end_comment

begin_define
define|#
directive|define
name|STYP_DATA
value|(0x0040)
end_define

begin_comment
comment|/* section contains data only */
end_comment

begin_define
define|#
directive|define
name|STYP_BSS
value|(0x0080)
end_define

begin_comment
comment|/* section contains bss only */
end_comment

begin_define
define|#
directive|define
name|S_NEWFCN
value|(0x0100)
end_define

begin_comment
comment|/* In a minimal file or an update file, a new function (as compared with a replaced function) */
end_comment

begin_define
define|#
directive|define
name|STYP_INFO
value|(0x0200)
end_define

begin_comment
comment|/* comment: not allocated not relocated, not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_OVER
value|(0x0400)
end_define

begin_comment
comment|/* overlay: relocated not allocated or loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_LIB
value|(0x0800)
end_define

begin_comment
comment|/* for .lib: same as INFO */
end_comment

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
value|sizeof(SCNHDR)
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
value|sizeof(LINENO)
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

begin_comment
comment|/*  * Relocatable symbols have number of the section in which they are defined,  * or one of the following:  */
end_comment

begin_define
define|#
directive|define
name|N_UNDEF
value|((short)0)
end_define

begin_comment
comment|/* undefined symbol */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|((short)-1)
end_define

begin_comment
comment|/* value of symbol is absolute */
end_comment

begin_define
define|#
directive|define
name|N_DEBUG
value|((short)-2)
end_define

begin_comment
comment|/* debugging symbol -- value is meaningless */
end_comment

begin_define
define|#
directive|define
name|N_TV
value|((short)-3)
end_define

begin_comment
comment|/* indicates symbol needs preload transfer vector */
end_comment

begin_define
define|#
directive|define
name|P_TV
value|((short)-4)
end_define

begin_comment
comment|/* indicates symbol needs postload transfer vector*/
end_comment

begin_comment
comment|/*  * Type of a symbol, in low 4 bits of the word  */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|0
end_define

begin_define
define|#
directive|define
name|T_VOID
value|1
end_define

begin_comment
comment|/* function argument (only used by compiler) */
end_comment

begin_define
define|#
directive|define
name|T_CHAR
value|2
end_define

begin_comment
comment|/* character		*/
end_comment

begin_define
define|#
directive|define
name|T_SHORT
value|3
end_define

begin_comment
comment|/* short integer	*/
end_comment

begin_define
define|#
directive|define
name|T_INT
value|4
end_define

begin_comment
comment|/* integer		*/
end_comment

begin_define
define|#
directive|define
name|T_LONG
value|5
end_define

begin_comment
comment|/* long integer		*/
end_comment

begin_define
define|#
directive|define
name|T_FLOAT
value|6
end_define

begin_comment
comment|/* floating point	*/
end_comment

begin_define
define|#
directive|define
name|T_DOUBLE
value|7
end_define

begin_comment
comment|/* double word		*/
end_comment

begin_define
define|#
directive|define
name|T_STRUCT
value|8
end_define

begin_comment
comment|/* structure 		*/
end_comment

begin_define
define|#
directive|define
name|T_UNION
value|9
end_define

begin_comment
comment|/* union 		*/
end_comment

begin_define
define|#
directive|define
name|T_ENUM
value|10
end_define

begin_comment
comment|/* enumeration 		*/
end_comment

begin_define
define|#
directive|define
name|T_MOE
value|11
end_define

begin_comment
comment|/* member of enumeration*/
end_comment

begin_define
define|#
directive|define
name|T_UCHAR
value|12
end_define

begin_comment
comment|/* unsigned character	*/
end_comment

begin_define
define|#
directive|define
name|T_USHORT
value|13
end_define

begin_comment
comment|/* unsigned short	*/
end_comment

begin_define
define|#
directive|define
name|T_UINT
value|14
end_define

begin_comment
comment|/* unsigned integer	*/
end_comment

begin_define
define|#
directive|define
name|T_ULONG
value|15
end_define

begin_comment
comment|/* unsigned long	*/
end_comment

begin_define
define|#
directive|define
name|T_LNGDBL
value|16
end_define

begin_comment
comment|/* long double		*/
end_comment

begin_comment
comment|/*  * derived types, in n_type */
end_comment

begin_define
define|#
directive|define
name|DT_NON
value|(0)
end_define

begin_comment
comment|/* no derived type */
end_comment

begin_define
define|#
directive|define
name|DT_PTR
value|(1)
end_define

begin_comment
comment|/* pointer */
end_comment

begin_define
define|#
directive|define
name|DT_FCN
value|(2)
end_define

begin_comment
comment|/* function */
end_comment

begin_define
define|#
directive|define
name|DT_ARY
value|(3)
end_define

begin_comment
comment|/* array */
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
name|N_TMASK
value|(0x30)
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

begin_define
define|#
directive|define
name|BTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& N_BTMASK)
end_define

begin_define
define|#
directive|define
name|ISPTR
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_PTR<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|ISFCN
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_FCN<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|ISARY
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_ARY<< N_BTSHFT))
end_define

begin_define
define|#
directive|define
name|DECREF
parameter_list|(
name|x
parameter_list|)
value|((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
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
name|_ETEXT
value|"etext"
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
value|sizeof(RELOC)
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

end_unit

