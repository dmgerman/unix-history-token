begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright 1990, 1992 Free Software Foundation, Inc.  *  *   This code was donated by Intel Corp.  *  * This is a coff version of a.out.h to support 80960 debugging from  * a Unix (possibly BSD) host.  It's used by:  *	o gdb960 to symbols in code generated with Intel (non-GNU) tools.  *	o comm960 to convert a b.out file to a coff file for download.  */
end_comment

begin_comment
comment|/********************** FILE HEADER **********************/
end_comment

begin_struct
struct|struct
name|filehdr
block|{
name|unsigned
name|short
name|f_magic
decl_stmt|;
comment|/* magic number			*/
name|unsigned
name|short
name|f_nscns
decl_stmt|;
comment|/* number of sections		*/
name|long
name|f_timdat
decl_stmt|;
comment|/* time& date stamp		*/
name|long
name|f_symptr
decl_stmt|;
comment|/* file pointer to symtab	*/
name|long
name|f_nsyms
decl_stmt|;
comment|/* number of symtab entries	*/
name|unsigned
name|short
name|f_opthdr
decl_stmt|;
comment|/* sizeof(optional hdr)		*/
name|unsigned
name|short
name|f_flags
decl_stmt|;
comment|/* flags			*/
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for f_flags:  *	F_RELFLG	relocation info stripped from file  *	F_EXEC		file is executable (no unresolved externel references)  *	F_LNNO		line nunbers stripped from file  *	F_LSYMS		local symbols stripped from file  *	F_AR32WR	file has byte ordering of an AR32WR machine (e.g. vax)  */
end_comment

begin_define
define|#
directive|define
name|F_RELFLG
value|0000001
end_define

begin_define
define|#
directive|define
name|F_EXEC
value|0000002
end_define

begin_define
define|#
directive|define
name|F_LNNO
value|0000004
end_define

begin_define
define|#
directive|define
name|F_LSYMS
value|0000010
end_define

begin_define
define|#
directive|define
name|F_AR32WR
value|0000400
end_define

begin_comment
comment|/*  *	Intel 80960 (I960) processor flags.  *	F_I960TYPE == mask for processor type field.   */
end_comment

begin_define
define|#
directive|define
name|F_I960TYPE
value|0170000
end_define

begin_define
define|#
directive|define
name|F_I960CA
value|0010000
end_define

begin_define
define|#
directive|define
name|F_I960FLOAT
value|0020000
end_define

begin_define
define|#
directive|define
name|F_I960BA
value|0030000
end_define

begin_define
define|#
directive|define
name|F_I960XA
value|0040000
end_define

begin_comment
comment|/*  * i80960 Magic Numbers  */
end_comment

begin_define
define|#
directive|define
name|I960ROMAGIC
value|0540
end_define

begin_comment
comment|/* read-only text segments	*/
end_comment

begin_define
define|#
directive|define
name|I960RWMAGIC
value|0541
end_define

begin_comment
comment|/* read-write text segments	*/
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
value|struct filehdr
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
name|aouthdr
block|{
name|short
name|magic
decl_stmt|;
comment|/* type of file				*/
name|short
name|vstamp
decl_stmt|;
comment|/* version stamp			*/
name|unsigned
name|long
name|tsize
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry*/
name|unsigned
name|long
name|dsize
decl_stmt|;
comment|/* initialized data "  "		*/
name|unsigned
name|long
name|bsize
decl_stmt|;
comment|/* uninitialized data "   "		*/
if|#
directive|if
name|U3B
name|unsigned
name|long
name|dum1
decl_stmt|;
name|unsigned
name|long
name|dum2
decl_stmt|;
comment|/* pad to entry point	*/
endif|#
directive|endif
name|unsigned
name|long
name|entry
decl_stmt|;
comment|/* entry pt.				*/
name|unsigned
name|long
name|text_start
decl_stmt|;
comment|/* base of text used for this file */
name|unsigned
name|long
name|data_start
decl_stmt|;
comment|/* base of data used for this file */
name|unsigned
name|long
name|tagentries
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

begin_define
define|#
directive|define
name|AOUTSZ
parameter_list|(
name|aout
parameter_list|)
value|(sizeof(AOUTHDR)+(aout.tagentries*sizeof(TAGBITS)))
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
comment|/* New storage classes for 80960 */
end_comment

begin_define
define|#
directive|define
name|C_SCALL
value|107
end_define

begin_comment
comment|/* Procedure reachable via system call	*/
end_comment

begin_define
define|#
directive|define
name|C_LEAFPROC
value|108
end_define

begin_comment
comment|/* Leaf procedure, "call" via BAL	*/
end_comment

begin_comment
comment|/********************** SECTION HEADER **********************/
end_comment

begin_struct
struct|struct
name|scnhdr
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* section name			*/
name|long
name|s_paddr
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|long
name|s_vaddr
decl_stmt|;
comment|/* virtual address		*/
name|long
name|s_size
decl_stmt|;
comment|/* section size			*/
name|long
name|s_scnptr
decl_stmt|;
comment|/* file ptr to raw data for section */
name|long
name|s_relptr
decl_stmt|;
comment|/* file ptr to relocation	*/
name|long
name|s_lnnoptr
decl_stmt|;
comment|/* file ptr to line numbers	*/
name|unsigned
name|short
name|s_nreloc
decl_stmt|;
comment|/* number of relocation entries	*/
name|unsigned
name|short
name|s_nlnno
decl_stmt|;
comment|/* number of line number entries*/
name|long
name|s_flags
decl_stmt|;
comment|/* flags			*/
name|unsigned
name|long
name|s_align
decl_stmt|;
comment|/* section alignment		*/
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

begin_comment
comment|/*  * s_flags "type"  */
end_comment

begin_define
define|#
directive|define
name|STYP_TEXT
value|0x20
end_define

begin_comment
comment|/* section contains text only	*/
end_comment

begin_define
define|#
directive|define
name|STYP_DATA
value|0x40
end_define

begin_comment
comment|/* section contains data only	*/
end_comment

begin_define
define|#
directive|define
name|STYP_BSS
value|0x80
end_define

begin_comment
comment|/* section contains bss only	*/
end_comment

begin_define
define|#
directive|define
name|SCNHDR
value|struct scnhdr
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
name|lineno
block|{
union|union
block|{
name|long
name|l_symndx
decl_stmt|;
comment|/* function name symbol index, iff l_lnno == 0*/
name|long
name|l_paddr
decl_stmt|;
comment|/* (physical) address of line number	*/
block|}
name|l_addr
union|;
name|unsigned
name|short
name|l_lnno
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
value|struct lineno
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
name|SYMNMLEN
value|8
end_define

begin_comment
comment|/* # characters in a symbol name	*/
end_comment

begin_define
define|#
directive|define
name|FILNMLEN
value|14
end_define

begin_comment
comment|/* # characters in a file name		*/
end_comment

begin_define
define|#
directive|define
name|DIMNUM
value|4
end_define

begin_comment
comment|/* # array dimensions in auxiliary entry */
end_comment

begin_struct
struct|struct
name|syment
block|{
union|union
block|{
name|char
name|_n_name
index|[
name|SYMNMLEN
index|]
decl_stmt|;
comment|/* old COFF version	*/
struct|struct
block|{
name|long
name|_n_zeroes
decl_stmt|;
comment|/* new == 0		*/
name|long
name|_n_offset
decl_stmt|;
comment|/* offset into string table */
block|}
name|_n_n
struct|;
name|char
modifier|*
name|_n_nptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* allows for overlaying	*/
block|}
name|_n
union|;
name|long
name|n_value
decl_stmt|;
comment|/* value of symbol		*/
name|short
name|n_scnum
decl_stmt|;
comment|/* section number		*/
name|char
name|pad1
index|[
literal|2
index|]
decl_stmt|;
comment|/* force alignment		*/
name|unsigned
name|long
name|n_type
decl_stmt|;
comment|/* type and derived type	*/
name|char
name|n_sclass
decl_stmt|;
comment|/* storage class		*/
name|char
name|n_numaux
decl_stmt|;
comment|/* number of aux. entries	*/
name|char
name|pad2
index|[
literal|2
index|]
decl_stmt|;
comment|/* force alignment		*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|n_name
value|_n._n_name
end_define

begin_define
define|#
directive|define
name|n_zeroes
value|_n._n_n._n_zeroes
end_define

begin_define
define|#
directive|define
name|n_offset
value|_n._n_n._n_offset
end_define

begin_comment
comment|/*  * Relocatable symbols have number of the section in which they are defined,  * or one of the following:  */
end_comment

begin_define
define|#
directive|define
name|N_UNDEF
value|0
end_define

begin_comment
comment|/* undefined symbol				*/
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|-1
end_define

begin_comment
comment|/* value of symbol is absolute			*/
end_comment

begin_define
define|#
directive|define
name|N_DEBUG
value|-2
end_define

begin_comment
comment|/* debugging symbol -- symbol value is meaningless */
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
comment|/*  * derived types  */
end_comment

begin_define
define|#
directive|define
name|DT_PTR
value|1
end_define

begin_comment
comment|/* pointer	*/
end_comment

begin_define
define|#
directive|define
name|DT_FCN
value|2
end_define

begin_comment
comment|/* function	*/
end_comment

begin_define
define|#
directive|define
name|DT_ARY
value|3
end_define

begin_comment
comment|/* array	*/
end_comment

begin_define
define|#
directive|define
name|N_BTMASK
value|037
end_define

begin_define
define|#
directive|define
name|N_TMASK
value|0140
end_define

begin_define
define|#
directive|define
name|N_BTSHFT
value|5
end_define

begin_define
define|#
directive|define
name|N_TSHIFT
value|2
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
name|auxent
block|{
struct|struct
block|{
name|long
name|x_tagndx
decl_stmt|;
comment|/* str, un, or enum tag indx */
union|union
block|{
struct|struct
block|{
name|unsigned
name|short
name|x_lnno
decl_stmt|;
comment|/* declaration line number */
name|unsigned
name|short
name|x_size
decl_stmt|;
comment|/* str/union/array size */
block|}
name|x_lnsz
struct|;
name|long
name|x_fsize
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
name|long
name|x_lnnoptr
decl_stmt|;
comment|/* ptr to fcn line # */
name|long
name|x_endndx
decl_stmt|;
comment|/* entry ndx past block end */
block|}
name|x_fcn
struct|;
struct|struct
block|{
comment|/* if ISARY, up to 4 dimen. */
name|unsigned
name|short
name|x_dimen
index|[
name|DIMNUM
index|]
decl_stmt|;
block|}
name|x_ary
struct|;
block|}
name|x_fcnary
union|;
name|unsigned
name|short
name|x_tvndx
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
name|FILNMLEN
index|]
decl_stmt|;
struct|struct
block|{
name|long
name|x_zeroes
decl_stmt|;
name|long
name|x_offset
decl_stmt|;
block|}
name|x_n
struct|;
block|}
name|x_file
union|;
struct|struct
block|{
name|long
name|x_scnlen
decl_stmt|;
comment|/* section length */
name|unsigned
name|short
name|x_nreloc
decl_stmt|;
comment|/* # relocation entries */
name|unsigned
name|short
name|x_nlinno
decl_stmt|;
comment|/* # line numbers */
block|}
name|x_scn
struct|;
struct|struct
block|{
name|long
name|x_stdindx
decl_stmt|;
block|}
name|x_sc
struct|;
struct|struct
block|{
name|unsigned
name|long
name|x_balntry
decl_stmt|;
block|}
name|x_bal
struct|;
name|char
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|syment
argument_list|)
index|]
decl_stmt|;
comment|/* force auxent/syment sizes to match */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|SYMENT
value|struct syment
end_define

begin_define
define|#
directive|define
name|SYMESZ
value|sizeof(SYMENT)
end_define

begin_define
define|#
directive|define
name|AUXENT
value|union auxent
end_define

begin_define
define|#
directive|define
name|AUXESZ
value|sizeof(AUXENT)
end_define

begin_if
if|#
directive|if
name|VAX
operator|||
name|I960
end_if

begin_define
define|#
directive|define
name|_ETEXT
value|"_etext"
end_define

begin_else
else|#
directive|else
end_else

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
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_struct
struct|struct
name|reloc
block|{
name|long
name|r_vaddr
decl_stmt|;
comment|/* Virtual address of reference */
name|long
name|r_symndx
decl_stmt|;
comment|/* Index into symbol table	*/
name|unsigned
name|short
name|r_type
decl_stmt|;
comment|/* Relocation type		*/
name|char
name|pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Unused			*/
block|}
struct|;
end_struct

begin_comment
comment|/* Only values of r_type GNU/960 cares about */
end_comment

begin_define
define|#
directive|define
name|R_RELLONG
value|17
end_define

begin_comment
comment|/* Direct 32-bit relocation		*/
end_comment

begin_define
define|#
directive|define
name|R_IPRMED
value|25
end_define

begin_comment
comment|/* 24-bit ip-relative relocation	*/
end_comment

begin_define
define|#
directive|define
name|R_OPTCALL
value|27
end_define

begin_comment
comment|/* 32-bit optimizable call (leafproc/sysproc) */
end_comment

begin_define
define|#
directive|define
name|RELOC
value|struct reloc
end_define

begin_define
define|#
directive|define
name|RELSZ
value|sizeof(RELOC)
end_define

end_unit

