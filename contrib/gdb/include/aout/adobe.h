begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* `a.out.adobe' differences from standard a.out files */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__A_OUT_ADOBE_H__
end_ifndef

begin_define
define|#
directive|define
name|__A_OUT_ADOBE_H__
end_define

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_comment
comment|/* Struct external_exec is the same.  */
end_comment

begin_comment
comment|/* This is the layout on disk of the 32-bit or 64-bit exec header. */
end_comment

begin_struct
struct|struct
name|external_exec
block|{
name|bfd_byte
name|e_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* magic number and stuff		*/
name|bfd_byte
name|e_text
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of text section in bytes	*/
name|bfd_byte
name|e_data
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of data section in bytes	*/
name|bfd_byte
name|e_bss
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of bss area in bytes 		*/
name|bfd_byte
name|e_syms
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of symbol table in bytes 	*/
name|bfd_byte
name|e_entry
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* start address 			*/
name|bfd_byte
name|e_trsize
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of text relocation info	*/
name|bfd_byte
name|e_drsize
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* length of data relocation info 	*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXEC_BYTES_SIZE
value|(4 + BYTES_IN_WORD * 7)
end_define

begin_comment
comment|/* Magic numbers for a.out files */
end_comment

begin_undef
undef|#
directive|undef
name|ZMAGIC
end_undef

begin_define
define|#
directive|define
name|ZMAGIC
value|0xAD0BE
end_define

begin_comment
comment|/* Cute, eh?  */
end_comment

begin_undef
undef|#
directive|undef
name|OMAGIC
end_undef

begin_undef
undef|#
directive|undef
name|NMAGIC
end_undef

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).a_info != ZMAGIC)
end_define

begin_comment
comment|/* By default, segment size is constant.  But some machines override this    to be a function of the a.out header (e.g. machine type).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_SEGSIZE
end_ifndef

begin_define
define|#
directive|define
name|N_SEGSIZE
parameter_list|(
name|x
parameter_list|)
value|SEGMENT_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|N_SEGSIZE
end_undef

begin_comment
comment|/* FIXMEXXXX */
end_comment

begin_comment
comment|/* Segment information for the a.out.Adobe format is specified after the    file header.  It contains N segment descriptors, followed by one with    a type of zero.       The actual text of the segments starts at N_TXTOFF in the file,    regardless of how many or how few segment headers there are.  */
end_comment

begin_struct
struct|struct
name|external_segdesc
block|{
name|unsigned
name|char
name|e_type
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|e_size
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|e_virtbase
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_filebase
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|internal_segdesc
block|{
name|unsigned
name|int
name|a_type
range|:
literal|8
decl_stmt|;
comment|/* Segment type N_TEXT, N_DATA, 0 */
name|unsigned
name|int
name|a_size
range|:
literal|24
decl_stmt|;
comment|/* Segment size */
name|bfd_vma
name|a_virtbase
decl_stmt|;
comment|/* Virtual address */
name|unsigned
name|int
name|a_filebase
decl_stmt|;
comment|/* Base address in object file */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
unit|\
comment|/* This is documented to be at 1024, but appears to really be at 2048.    FIXME?!  */
end_comment

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|2048
end_define

begin_define
define|#
directive|define
name|N_TXTSIZE
parameter_list|(
name|x
parameter_list|)
value|((x).a_text)
end_define

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|N_BSSADDR
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* Offsets of the various portions of the file after the text segment.  */
end_comment

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TXTOFF(x) + N_TXTSIZE(x) )
end_define

begin_define
define|#
directive|define
name|N_TRELOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DATOFF(x) + (x).a_data )
end_define

begin_define
define|#
directive|define
name|N_DRELOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TRELOFF(x) + (x).a_trsize )
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DRELOFF(x) + (x).a_drsize )
end_define

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|x
parameter_list|)
value|( N_SYMOFF(x) + (x).a_syms )
end_define

begin_escape
end_escape

begin_comment
comment|/* Symbols */
end_comment

begin_struct
struct|struct
name|external_nlist
block|{
name|bfd_byte
name|e_strx
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* index into string table of name */
name|bfd_byte
name|e_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* type of symbol */
name|bfd_byte
name|e_other
index|[
literal|1
index|]
decl_stmt|;
comment|/* misc info (usually empty) */
name|bfd_byte
name|e_desc
index|[
literal|2
index|]
decl_stmt|;
comment|/* description field */
name|bfd_byte
name|e_value
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* value of symbol */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXTERNAL_NLIST_SIZE
value|(BYTES_IN_WORD+4+BYTES_IN_WORD)
end_define

begin_struct
struct|struct
name|internal_nlist
block|{
name|unsigned
name|long
name|n_strx
decl_stmt|;
comment|/* index into string table of name */
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* type of symbol */
name|unsigned
name|char
name|n_other
decl_stmt|;
comment|/* misc info (usually empty) */
name|unsigned
name|short
name|n_desc
decl_stmt|;
comment|/* description field */
name|bfd_vma
name|n_value
decl_stmt|;
comment|/* value of symbol */
block|}
struct|;
end_struct

begin_comment
comment|/* The n_type field is the symbol type, containing:  */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0
end_define

begin_comment
comment|/* Undefined symbol */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|2
end_define

begin_comment
comment|/* Absolute symbol -- defined at particular addr */
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|4
end_define

begin_comment
comment|/* Text sym -- defined at offset in text seg */
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|6
end_define

begin_comment
comment|/* Data sym -- defined at offset in data seg */
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|8
end_define

begin_comment
comment|/* BSS  sym -- defined at offset in zero'd seg */
end_comment

begin_define
define|#
directive|define
name|N_COMM
value|0x12
end_define

begin_comment
comment|/* Common symbol (visible after shared lib dynlink) */
end_comment

begin_define
define|#
directive|define
name|N_FN
value|0x1f
end_define

begin_comment
comment|/* File name of .o file */
end_comment

begin_define
define|#
directive|define
name|N_FN_SEQ
value|0x0C
end_define

begin_comment
comment|/* N_FN from Sequent compilers (sigh) */
end_comment

begin_comment
comment|/* Note: N_EXT can only be usefully OR-ed with N_UNDF, N_ABS, N_TEXT,    N_DATA, or N_BSS.  When the low-order bit of other types is set,    (e.g. N_WARNING versus N_FN), they are two different types.  */
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|1
end_define

begin_comment
comment|/* External symbol (as opposed to local-to-this-file) */
end_comment

begin_define
define|#
directive|define
name|N_TYPE
value|0x1e
end_define

begin_define
define|#
directive|define
name|N_STAB
value|0xe0
end_define

begin_comment
comment|/* If any of these bits are on, it's a debug symbol */
end_comment

begin_define
define|#
directive|define
name|N_INDR
value|0x0a
end_define

begin_comment
comment|/* The following symbols refer to set elements.    All the N_SET[ATDB] symbols with the same name form one set.    Space is allocated for the set in the text section, and each set    elements value is stored into one word of the space.    The first word of the space is the length of the set (number of elements).     The address of the set is made into an N_SETV symbol    whose name is the same as the name of the set.    This symbol acts like a N_DATA global symbol    in that it can satisfy undefined external references.  */
end_comment

begin_comment
comment|/* These appear as input to LD, in a .o file.  */
end_comment

begin_define
define|#
directive|define
name|N_SETA
value|0x14
end_define

begin_comment
comment|/* Absolute set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETT
value|0x16
end_define

begin_comment
comment|/* Text set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETD
value|0x18
end_define

begin_comment
comment|/* Data set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETB
value|0x1A
end_define

begin_comment
comment|/* Bss set element symbol */
end_comment

begin_comment
comment|/* This is output from LD.  */
end_comment

begin_define
define|#
directive|define
name|N_SETV
value|0x1C
end_define

begin_comment
comment|/* Pointer to set vector in data area.  */
end_comment

begin_comment
comment|/* Warning symbol. The text gives a warning message, the next symbol    in the table will be undefined. When the symbol is referenced, the    message is printed.  */
end_comment

begin_define
define|#
directive|define
name|N_WARNING
value|0x1e
end_define

begin_comment
comment|/* Relocations     There	are two types of relocation flavours for a.out systems,   standard and extended. The standard form is used on systems where the   instruction has room for all the bits of an offset to the operand, whilst   the extended form is used when an address operand has to be split over n   instructions. Eg, on the 68k, each move instruction can reference   the target with a displacement of 16 or 32 bits. On the sparc, move   instructions use an offset of 14 bits, so the offset is stored in   the reloc field, and the data in the section is ignored. */
end_comment

begin_comment
comment|/* This structure describes a single relocation to be performed.    The text-relocation section of the file is a vector of these structures,    all of which apply to the text section.    Likewise, the data-relocation section applies to the data section.  */
end_comment

begin_struct
struct|struct
name|reloc_std_external
block|{
name|bfd_byte
name|r_address
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* offset of of data to relocate */
name|bfd_byte
name|r_index
index|[
literal|3
index|]
decl_stmt|;
comment|/* symbol table index of symbol 	*/
name|bfd_byte
name|r_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* relocation type			*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC_STD_BITS_PCREL_BIG
value|0x80
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_PCREL_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_BIG
value|0x60
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_SH_BIG
value|5
end_define

begin_comment
comment|/* To shift to units place */
end_comment

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_LITTLE
value|0x06
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_LENGTH_SH_LITTLE
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_EXTERN_BIG
value|0x10
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_EXTERN_LITTLE
value|0x08
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_BASEREL_BIG
value|0x08
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_BASEREL_LITTLE
value|0x08
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_JMPTABLE_BIG
value|0x04
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_JMPTABLE_LITTLE
value|0x04
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_RELATIVE_BIG
value|0x02
end_define

begin_define
define|#
directive|define
name|RELOC_STD_BITS_RELATIVE_LITTLE
value|0x02
end_define

begin_define
define|#
directive|define
name|RELOC_STD_SIZE
value|(BYTES_IN_WORD + 3 + 1)
end_define

begin_comment
comment|/* Bytes per relocation entry */
end_comment

begin_struct
struct|struct
name|reloc_std_internal
block|{
name|bfd_vma
name|r_address
decl_stmt|;
comment|/* Address (within segment) to be relocated.  */
comment|/* The meaning of r_symbolnum depends on r_extern.  */
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|;
comment|/* Nonzero means value is a pc-relative offset      and it should be relocated for changes in its own address      as well as for changes in the symbol or section specified.  */
name|unsigned
name|int
name|r_pcrel
range|:
literal|1
decl_stmt|;
comment|/* Length (as exponent of 2) of the field to be relocated.      Thus, a value of 2 indicates 1<<2 bytes.  */
name|unsigned
name|int
name|r_length
range|:
literal|2
decl_stmt|;
comment|/* 1 => relocate with value of symbol.      r_symbolnum is the index of the symbol      in files the symbol table.      0 => relocate with the address of a segment.      r_symbolnum is N_TEXT, N_DATA, N_BSS or N_ABS      (the N_EXT bit may be set also, but signifies nothing).  */
name|unsigned
name|int
name|r_extern
range|:
literal|1
decl_stmt|;
comment|/* The next three bits are for SunOS shared libraries, and seem to      be undocumented.  */
name|unsigned
name|int
name|r_baserel
range|:
literal|1
decl_stmt|;
comment|/* Linkage table relative */
name|unsigned
name|int
name|r_jmptable
range|:
literal|1
decl_stmt|;
comment|/* pc-relative to jump table */
name|unsigned
name|int
name|r_relative
range|:
literal|1
decl_stmt|;
comment|/* "relative relocation" */
comment|/* unused */
name|unsigned
name|int
name|r_pad
range|:
literal|1
decl_stmt|;
comment|/* Padding -- set to zero */
block|}
struct|;
end_struct

begin_comment
comment|/* EXTENDED RELOCS  */
end_comment

begin_struct
struct|struct
name|reloc_ext_external
block|{
name|bfd_byte
name|r_address
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* offset of of data to relocate 	*/
name|bfd_byte
name|r_index
index|[
literal|3
index|]
decl_stmt|;
comment|/* symbol table index of symbol 	*/
name|bfd_byte
name|r_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* relocation type			*/
name|bfd_byte
name|r_addend
index|[
name|BYTES_IN_WORD
index|]
decl_stmt|;
comment|/* datum addend				*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_EXTERN_BIG
value|0x80
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_EXTERN_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_BIG
value|0x1F
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_LITTLE
value|0xF8
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_SH_LITTLE
value|3
end_define

begin_comment
comment|/* Bytes per relocation entry */
end_comment

begin_define
define|#
directive|define
name|RELOC_EXT_SIZE
value|(BYTES_IN_WORD + 3 + 1 + BYTES_IN_WORD)
end_define

begin_enum
enum|enum
name|reloc_type
block|{
comment|/* simple relocations */
name|RELOC_8
block|,
comment|/* data[0:7] = addend + sv 		*/
name|RELOC_16
block|,
comment|/* data[0:15] = addend + sv 		*/
name|RELOC_32
block|,
comment|/* data[0:31] = addend + sv 		*/
comment|/* pc-rel displacement */
name|RELOC_DISP8
block|,
comment|/* data[0:7] = addend - pc + sv 	*/
name|RELOC_DISP16
block|,
comment|/* data[0:15] = addend - pc + sv 	*/
name|RELOC_DISP32
block|,
comment|/* data[0:31] = addend - pc + sv 	*/
comment|/* Special */
name|RELOC_WDISP30
block|,
comment|/* data[0:29] = (addend + sv - pc)>>2 	*/
name|RELOC_WDISP22
block|,
comment|/* data[0:21] = (addend + sv - pc)>>2 	*/
name|RELOC_HI22
block|,
comment|/* data[0:21] = (addend + sv)>>10 	*/
name|RELOC_22
block|,
comment|/* data[0:21] = (addend + sv) 		*/
name|RELOC_13
block|,
comment|/* data[0:12] = (addend + sv)		*/
name|RELOC_LO10
block|,
comment|/* data[0:9] = (addend + sv)		*/
name|RELOC_SFA_BASE
block|,
name|RELOC_SFA_OFF13
block|,
comment|/* P.I.C. (base-relative) */
name|RELOC_BASE10
block|,
comment|/* Not sure - maybe we can do this the */
name|RELOC_BASE13
block|,
comment|/* right way now */
name|RELOC_BASE22
block|,
comment|/* for some sort of pc-rel P.I.C. (?) */
name|RELOC_PC10
block|,
name|RELOC_PC22
block|,
comment|/* P.I.C. jump table */
name|RELOC_JMP_TBL
block|,
comment|/* reputedly for shared libraries somehow */
name|RELOC_SEGOFF16
block|,
name|RELOC_GLOB_DAT
block|,
name|RELOC_JMP_SLOT
block|,
name|RELOC_RELATIVE
block|,
name|RELOC_11
block|,
name|RELOC_WDISP2_14
block|,
name|RELOC_WDISP19
block|,
name|RELOC_HHI22
block|,
comment|/* data[0:21] = (addend + sv)>> 42     */
name|RELOC_HLO10
block|,
comment|/* data[0:9] = (addend + sv)>> 32      */
comment|/* 29K relocation types */
name|RELOC_JUMPTARG
block|,
name|RELOC_CONST
block|,
name|RELOC_CONSTH
block|,
name|NO_RELOC
block|}
enum|;
end_enum

begin_struct
struct|struct
name|reloc_internal
block|{
name|bfd_vma
name|r_address
decl_stmt|;
comment|/* offset of of data to relocate 	*/
name|long
name|r_index
decl_stmt|;
comment|/* symbol table index of symbol 	*/
name|enum
name|reloc_type
name|r_type
decl_stmt|;
comment|/* relocation type			*/
name|bfd_vma
name|r_addend
decl_stmt|;
comment|/* datum addend				*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __A_OUT_ADOBE_H__ */
end_comment

end_unit

