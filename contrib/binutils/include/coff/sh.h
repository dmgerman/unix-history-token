begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*** coff information for Hitachi SH */
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
name|SH_ARCH_MAGIC_BIG
value|0x0500
end_define

begin_define
define|#
directive|define
name|SH_ARCH_MAGIC_LITTLE
value|0x0550
end_define

begin_comment
comment|/* Little endian SH */
end_comment

begin_define
define|#
directive|define
name|SH_ARCH_MAGIC_WINCE
value|0x01a2
end_define

begin_comment
comment|/* Windows CE - little endian */
end_comment

begin_define
define|#
directive|define
name|SH_PE_MAGIC
value|0x010b
end_define

begin_define
define|#
directive|define
name|SHBADMAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x).f_magic!=SH_ARCH_MAGIC_BIG)&& \   ((x).f_magic!=SH_ARCH_MAGIC_WINCE)&& \   ((x).f_magic!=SH_ARCH_MAGIC_LITTLE))
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
name|AOUTHDRSZ
value|28
end_define

begin_define
define|#
directive|define
name|AOUTSZ
value|28
end_define

begin_comment
comment|/* Define some NT default values.  */
end_comment

begin_comment
comment|/*  #define NT_IMAGE_BASE        0x400000 moved to internal.h */
end_comment

begin_define
define|#
directive|define
name|NT_SECTION_ALIGNMENT
value|0x1000
end_define

begin_define
define|#
directive|define
name|NT_FILE_ALIGNMENT
value|0x200
end_define

begin_define
define|#
directive|define
name|NT_DEF_RESERVE
value|0x100000
end_define

begin_define
define|#
directive|define
name|NT_DEF_COMMIT
value|0x1000
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
ifdef|#
directive|ifdef
name|COFF_WITH_PE
name|char
name|l_lnno
index|[
literal|2
index|]
decl_stmt|;
comment|/* line number		*/
else|#
directive|else
name|char
name|l_lnno
index|[
literal|4
index|]
decl_stmt|;
comment|/* line number		*/
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GET_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
value|bfd_h_get_32(abfd, (bfd_byte *) (ext->l_lnno));
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
value|bfd_h_put_32(abfd,val,  (bfd_byte *) (ext->l_lnno));
end_define

begin_define
define|#
directive|define
name|LINENO
value|struct external_lineno
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_WITH_PE
end_ifdef

begin_define
define|#
directive|define
name|LINESZ
value|6
end_define

begin_undef
undef|#
directive|undef
name|GET_LINENO_LNNO
end_undef

begin_define
define|#
directive|define
name|GET_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
value|bfd_h_get_16(abfd, (bfd_byte *) (ext->l_lnno));
end_define

begin_undef
undef|#
directive|undef
name|PUT_LINENO_LNNO
end_undef

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
value|bfd_h_put_16(abfd,val,  (bfd_byte *) (ext->l_lnno));
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINESZ
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|char
name|x_checksum
index|[
literal|4
index|]
decl_stmt|;
comment|/* section COMDAT checksum */
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
comment|/* COMDAT selection number */
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

begin_comment
comment|/********************** RELOCATION DIRECTIVES **********************/
end_comment

begin_comment
comment|/* The external reloc has an offset field, because some of the reloc    types on the h8 don't have room in the instruction for the entire    offset - eg the strange jump and high page addressing modes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_WITH_PE
end_ifndef

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
name|r_offset
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
name|r_stuff
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RELOC
value|struct external_reloc
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_WITH_PE
end_ifdef

begin_define
define|#
directive|define
name|RELSZ
value|10
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RELSZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SH relocation types.  Not all of these are actually used.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_UNUSED
value|0
end_define

begin_comment
comment|/* only used internally */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM32CE
value|2
end_define

begin_comment
comment|/* 32 bit immediate for WinCE */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCREL8
value|3
end_define

begin_comment
comment|/*  8 bit pcrel 	*/
end_comment

begin_define
define|#
directive|define
name|R_SH_PCREL16
value|4
end_define

begin_comment
comment|/* 16 bit pcrel 	*/
end_comment

begin_define
define|#
directive|define
name|R_SH_HIGH8
value|5
end_define

begin_comment
comment|/* high 8 bits of 24 bit address */
end_comment

begin_define
define|#
directive|define
name|R_SH_LOW16
value|7
end_define

begin_comment
comment|/* low 16 bits of 24 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM24
value|6
end_define

begin_comment
comment|/* 24 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP8BY4
value|9
end_define

begin_comment
comment|/* PC rel 8 bits *4 +ve */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP8BY2
value|10
end_define

begin_comment
comment|/* PC rel 8 bits *2 +ve */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP8
value|11
end_define

begin_comment
comment|/* 8 bit branch */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCDISP
value|12
end_define

begin_comment
comment|/* 12 bit branch */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM32
value|14
end_define

begin_comment
comment|/* 32 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM8
value|16
end_define

begin_comment
comment|/* 8 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMAGEBASE
value|16
end_define

begin_comment
comment|/* Windows CE */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM8BY2
value|17
end_define

begin_comment
comment|/* 8 bit immediate *2 */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM8BY4
value|18
end_define

begin_comment
comment|/* 8 bit immediate *4 */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM4
value|19
end_define

begin_comment
comment|/* 4 bit immediate */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM4BY2
value|20
end_define

begin_comment
comment|/* 4 bit immediate *2 */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM4BY4
value|21
end_define

begin_comment
comment|/* 4 bit immediate *4 */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCRELIMM8BY2
value|22
end_define

begin_comment
comment|/* PC rel 8 bits *2 unsigned */
end_comment

begin_define
define|#
directive|define
name|R_SH_PCRELIMM8BY4
value|23
end_define

begin_comment
comment|/* PC rel 8 bits *4 unsigned */
end_comment

begin_define
define|#
directive|define
name|R_SH_IMM16
value|24
end_define

begin_comment
comment|/* 16 bit immediate */
end_comment

begin_comment
comment|/* The switch table reloc types are used for relaxing.  They are    generated for expressions such as      .word L1 - L2    The r_offset field holds the difference between the reloc address    and L2.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_SWITCH8
value|33
end_define

begin_comment
comment|/* 8 bit switch table entry */
end_comment

begin_define
define|#
directive|define
name|R_SH_SWITCH16
value|25
end_define

begin_comment
comment|/* 16 bit switch table entry */
end_comment

begin_define
define|#
directive|define
name|R_SH_SWITCH32
value|26
end_define

begin_comment
comment|/* 32 bit switch table entry */
end_comment

begin_comment
comment|/* The USES reloc type is used for relaxing.  The compiler will    generate .uses pseudo-ops when it finds a function call which it    can relax.  The r_offset field of the USES reloc holds the PC    relative offset to the instruction which loads the register used in    the function call.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_USES
value|27
end_define

begin_comment
comment|/* .uses pseudo-op */
end_comment

begin_comment
comment|/* The COUNT reloc type is used for relaxing.  The assembler will    generate COUNT relocs for addresses referred to by the register    loads associated with USES relocs.  The r_offset field of the COUNT    reloc holds the number of times the address is referenced in the    object file.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_COUNT
value|28
end_define

begin_comment
comment|/* Count of constant pool uses */
end_comment

begin_comment
comment|/* The ALIGN reloc type is used for relaxing.  The r_offset field is    the power of two to which subsequent portions of the object file    must be aligned.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_ALIGN
value|29
end_define

begin_comment
comment|/* .align pseudo-op */
end_comment

begin_comment
comment|/* The CODE and DATA reloc types are used for aligning load and store    instructions.  The assembler will generate a CODE reloc before a    block of instructions.  It will generate a DATA reloc before data.    A section should be processed assuming it contains data, unless a    CODE reloc is seen.  The only relevant pieces of information in the    CODE and DATA relocs are the section and the address.  The symbol    and offset are meaningless.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_CODE
value|30
end_define

begin_comment
comment|/* start of code */
end_comment

begin_define
define|#
directive|define
name|R_SH_DATA
value|31
end_define

begin_comment
comment|/* start of data */
end_comment

begin_comment
comment|/* The LABEL reloc type is used for aligning load and store    instructions.  The assembler will generate a LABEL reloc for each    label within a block of instructions.  This permits the linker to    avoid swapping instructions which are the targets of branches.  */
end_comment

begin_define
define|#
directive|define
name|R_SH_LABEL
value|32
end_define

begin_comment
comment|/* label */
end_comment

begin_comment
comment|/* NB: R_SH_SWITCH8 is 33 */
end_comment

end_unit

