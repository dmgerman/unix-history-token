begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Rudimentary ECOFF support on MIPS machines.     This lacks symbol information, normally provided on MIPS Unix systems    in the files<sym.h> and<symconst.h>.  */
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
literal|4
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
comment|/* Mips magics */
end_comment

begin_define
define|#
directive|define
name|MIPS_MAGIC_1
value|0x0180
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_2
value|0x0162
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_3
value|0x0160
end_define

begin_define
define|#
directive|define
name|ECOFFBADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).f_magic!=MIPS_MAGIC_1)&& \ 			((x).f_magic!=MIPS_MAGIC_2)&&\ 			((x).f_magic!=MIPS_MAGIC_3))
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
name|tsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* text size in bytes, padded to FW bdry*/
name|unsigned
name|char
name|dsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* initialized data "  "		*/
name|unsigned
name|char
name|bsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* uninitialized data "   "		*/
name|unsigned
name|char
name|entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* entry pt.				*/
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
value|(sizeof(AOUTHDR))
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
literal|4
index|]
decl_stmt|;
comment|/* physical address, aliased s_nlib */
name|unsigned
name|char
name|s_vaddr
index|[
literal|4
index|]
decl_stmt|;
comment|/* virtual address		*/
name|unsigned
name|char
name|s_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* section size			*/
name|unsigned
name|char
name|s_scnptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to raw data for section */
name|unsigned
name|char
name|s_relptr
index|[
literal|4
index|]
decl_stmt|;
comment|/* file ptr to relocation	*/
name|unsigned
name|char
name|s_lnnoptr
index|[
literal|4
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
value|sizeof(SCNHDR)
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
value|16
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
literal|4
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
name|r_type
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
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
comment|/* Relevent values for r_type and ecoff.  Would someone please document them */
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

