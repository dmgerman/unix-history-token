begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|ECOFF_H
end_ifndef

begin_define
define|#
directive|define
name|ECOFF_H
end_define

begin_comment
comment|/* Generic ECOFF support.    This does not include symbol information, found in sym.h and    symconst.h.  */
end_comment

begin_comment
comment|/* Mips magic numbers used in filehdr.  MIPS_MAGIC_LITTLE is used on    little endian machines.  MIPS_MAGIC_BIG is used on big endian    machines.  Where is MIPS_MAGIC_1 from?  */
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
name|MIPS_MAGIC_LITTLE
value|0x0162
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_BIG
value|0x0160
end_define

begin_comment
comment|/* These are the magic numbers used for MIPS code compiled at ISA    level 2.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_MAGIC_LITTLE2
value|0x0166
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_BIG2
value|0x0163
end_define

begin_comment
comment|/* These are the magic numbers used for MIPS code compiled at ISA    level 3.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_MAGIC_LITTLE3
value|0x142
end_define

begin_define
define|#
directive|define
name|MIPS_MAGIC_BIG3
value|0x140
end_define

begin_comment
comment|/* Alpha magic numbers used in filehdr.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_MAGIC
value|0x183
end_define

begin_comment
comment|/* Magic numbers used in a.out header.  */
end_comment

begin_define
define|#
directive|define
name|ECOFF_AOUT_OMAGIC
value|0407
end_define

begin_comment
comment|/* not demand paged (ld -N).  */
end_comment

begin_define
define|#
directive|define
name|ECOFF_AOUT_ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format, eg normal ld output */
end_comment

begin_comment
comment|/* Names of special sections.  */
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
name|_RDATA
value|".rdata"
end_define

begin_define
define|#
directive|define
name|_SDATA
value|".sdata"
end_define

begin_define
define|#
directive|define
name|_SBSS
value|".sbss"
end_define

begin_define
define|#
directive|define
name|_LIT4
value|".lit4"
end_define

begin_define
define|#
directive|define
name|_LIT8
value|".lit8"
end_define

begin_define
define|#
directive|define
name|_LIB
value|".lib"
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
comment|/* ECOFF uses some additional section flags.  */
end_comment

begin_define
define|#
directive|define
name|STYP_RDATA
value|0x100
end_define

begin_define
define|#
directive|define
name|STYP_SDATA
value|0x200
end_define

begin_define
define|#
directive|define
name|STYP_SBSS
value|0x400
end_define

begin_define
define|#
directive|define
name|STYP_ECOFF_FINI
value|0x1000000
end_define

begin_define
define|#
directive|define
name|STYP_LIT8
value|0x8000000
end_define

begin_define
define|#
directive|define
name|STYP_LIT4
value|0x10000000
end_define

begin_define
define|#
directive|define
name|STYP_ECOFF_INIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|STYP_OTHER_LOAD
value|(STYP_ECOFF_INIT | STYP_ECOFF_FINI)
end_define

begin_comment
comment|/* The linker needs a section to hold small common variables while    linking.  There is no convenient way to create it when the linker    needs it, so we always create one for each BFD.  We then avoid    writing it out.  */
end_comment

begin_define
define|#
directive|define
name|SCOMMON
value|".scommon"
end_define

begin_comment
comment|/* The ECOFF a.out header carries information about register masks and    the gp value.  The assembler needs to be able to write out this    information, and objcopy needs to be able to copy it from one file    to another.  To handle this in BFD, we use a dummy section to hold    the information.  We call this section .reginfo, since MIPS ELF has    a .reginfo section which serves a similar purpose.  When BFD    recognizes an ECOFF object, it copies the information into a    private data structure.  When the .reginfo section is read, the    information is retrieved from the private data structure.  When the    .reginfo section is written, the information in the private data    structure is updated.  The contents of the .reginfo section, as    seen by programs outside BFD, is a ecoff_reginfo structure.  The    contents of the structure are as seen on the host, so no swapping    issues arise.     The assembler used to update the private BFD data structures    directly.  With this approach, it instead just creates a .reginfo    section and updates that.  The real advantage of this approach is    that objcopy works automatically.  */
end_comment

begin_define
define|#
directive|define
name|REGINFO
value|".reginfo"
end_define

begin_struct
struct|struct
name|ecoff_reginfo
block|{
name|bfd_vma
name|gp_value
decl_stmt|;
comment|/* GP register value.		*/
name|unsigned
name|long
name|gprmask
decl_stmt|;
comment|/* General registers used.	*/
name|unsigned
name|long
name|cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* Coprocessor registers used.	*/
name|unsigned
name|long
name|fprmask
decl_stmt|;
comment|/* Floating pointer registers used.  */
block|}
struct|;
end_struct

begin_comment
comment|/* If the extern bit in a reloc is 1, then r_symndx is an index into    the external symbol table.  If the extern bit is 0, then r_symndx    indicates a section, and is one of the following values.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_SECTION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_TEXT
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_RDATA
value|2
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_DATA
value|3
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_SDATA
value|4
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_SBSS
value|5
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_BSS
value|6
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_INIT
value|7
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_LIT8
value|8
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_LIT4
value|9
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_XDATA
value|10
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_PDATA
value|11
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_FINI
value|12
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_LITA
value|13
end_define

begin_define
define|#
directive|define
name|RELOC_SECTION_ABS
value|14
end_define

begin_comment
comment|/********************** STABS **********************/
end_comment

begin_comment
comment|/* gcc uses mips-tfile to output type information in special stabs    entries.  These must match the corresponding definition in    gcc/config/mips.h.  At some point, these should probably go into a    shared include file, but currently gcc and gdb do not share any    directories. */
end_comment

begin_define
define|#
directive|define
name|CODE_MASK
value|0x8F300
end_define

begin_define
define|#
directive|define
name|ECOFF_IS_STAB
parameter_list|(
name|sym
parameter_list|)
value|(((sym)->index& 0xFFF00) == CODE_MASK)
end_define

begin_define
define|#
directive|define
name|ECOFF_MARK_STAB
parameter_list|(
name|code
parameter_list|)
value|((code)+CODE_MASK)
end_define

begin_define
define|#
directive|define
name|ECOFF_UNMARK_STAB
parameter_list|(
name|code
parameter_list|)
value|((code)-CODE_MASK)
end_define

begin_define
define|#
directive|define
name|STABS_SYMBOL
value|"@stabs"
end_define

begin_comment
comment|/********************** COFF **********************/
end_comment

begin_comment
comment|/* gcc also uses mips-tfile to output COFF debugging information.    These are the values it uses when outputting the .type directive.    These should also be in a shared include file.  */
end_comment

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

begin_comment
comment|/********************** AUX **********************/
end_comment

begin_comment
comment|/* The auxiliary type information is the same on all known ECOFF    targets.  I can't see any reason that it would ever change, so I am    going to gamble and define the external structures here, in the    target independent ECOFF header file.  The internal forms are    defined in coff/sym.h, which was originally donated by MIPS    Computer Systems.  */
end_comment

begin_comment
comment|/* Type information external record */
end_comment

begin_struct
struct|struct
name|tir_ext
block|{
name|unsigned
name|char
name|t_bits1
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|t_tq45
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|t_tq01
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|t_tq23
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
name|TIR_BITS1_FBITFIELD_BIG
value|0x80
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_FBITFIELD_LITTLE
value|0x01
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_CONTINUED_BIG
value|0x40
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_CONTINUED_LITTLE
value|0x02
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_BIG
value|0x3F
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_LITTLE
value|0xFC
end_define

begin_define
define|#
directive|define
name|TIR_BITS1_BT_SH_LITTLE
value|2
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_BIG
value|0xF0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_BIG
value|0x0F
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_LITTLE
value|0x0F
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ4_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_LITTLE
value|0xF0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ5_SH_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_BIG
value|0xF0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_BIG
value|0x0F
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_LITTLE
value|0x0F
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ0_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_LITTLE
value|0xF0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ1_SH_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_BIG
value|0xF0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_BIG
value|0x0F
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_SH_BIG
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_LITTLE
value|0x0F
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ2_SH_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_LITTLE
value|0xF0
end_define

begin_define
define|#
directive|define
name|TIR_BITS_TQ3_SH_LITTLE
value|4
end_define

begin_comment
comment|/* Relative symbol external record */
end_comment

begin_struct
struct|struct
name|rndx_ext
block|{
name|unsigned
name|char
name|r_bits
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
name|RNDX_BITS0_RFD_SH_LEFT_BIG
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_BIG
value|0xF0
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_SH_BIG
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS0_RFD_SH_LEFT_LITTLE
value|0
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_LITTLE
value|0x0F
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_RFD_SH_LEFT_LITTLE
value|8
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_BIG
value|0x0F
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_SH_LEFT_BIG
value|16
end_define

begin_define
define|#
directive|define
name|RNDX_BITS2_INDEX_SH_LEFT_BIG
value|8
end_define

begin_define
define|#
directive|define
name|RNDX_BITS3_INDEX_SH_LEFT_BIG
value|0
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_LITTLE
value|0xF0
end_define

begin_define
define|#
directive|define
name|RNDX_BITS1_INDEX_SH_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS2_INDEX_SH_LEFT_LITTLE
value|4
end_define

begin_define
define|#
directive|define
name|RNDX_BITS3_INDEX_SH_LEFT_LITTLE
value|12
end_define

begin_comment
comment|/* Auxiliary symbol information external record */
end_comment

begin_union
union|union
name|aux_ext
block|{
name|struct
name|tir_ext
name|a_ti
decl_stmt|;
name|struct
name|rndx_ext
name|a_rndx
decl_stmt|;
name|unsigned
name|char
name|a_dnLow
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_dnHigh
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_isym
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_iss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_width
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|a_count
index|[
literal|4
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|AUX_GET_ANY
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|,
name|field
parameter_list|)
define|\
value|((bigend) ? bfd_getb32 ((ax)->field) : bfd_getl32 ((ax)->field))
end_define

begin_define
define|#
directive|define
name|AUX_GET_DNLOW
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_dnLow)
end_define

begin_define
define|#
directive|define
name|AUX_GET_DNHIGH
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_dnHigh)
end_define

begin_define
define|#
directive|define
name|AUX_GET_ISYM
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_isym)
end_define

begin_define
define|#
directive|define
name|AUX_GET_ISS
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_iss)
end_define

begin_define
define|#
directive|define
name|AUX_GET_WIDTH
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_width)
end_define

begin_define
define|#
directive|define
name|AUX_GET_COUNT
parameter_list|(
name|bigend
parameter_list|,
name|ax
parameter_list|)
value|AUX_GET_ANY ((bigend), (ax), a_count)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_ANY
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|,
name|field
parameter_list|)
define|\
value|((bigend) \    ? (bfd_putb32 ((bfd_vma) (val), (ax)->field), 0) \    : (bfd_putl32 ((bfd_vma) (val), (ax)->field), 0))
end_define

begin_define
define|#
directive|define
name|AUX_PUT_DNLOW
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_dnLow)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_DNHIGH
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_dnHigh)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_ISYM
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_isym)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_ISS
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_iss)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_WIDTH
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_width)
end_define

begin_define
define|#
directive|define
name|AUX_PUT_COUNT
parameter_list|(
name|bigend
parameter_list|,
name|val
parameter_list|,
name|ax
parameter_list|)
define|\
value|AUX_PUT_ANY ((bigend), (val), (ax), a_count)
end_define

begin_comment
comment|/* Prototypes for the swapping functions.  These require that sym.h be    included before this file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_swap_tir_in
name|PARAMS
argument_list|(
operator|(
name|int
name|bigend
operator|,
expr|struct
name|tir_ext
operator|*
operator|,
name|TIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_swap_tir_out
name|PARAMS
argument_list|(
operator|(
name|int
name|bigend
operator|,
name|TIR
operator|*
operator|,
expr|struct
name|tir_ext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_swap_rndx_in
name|PARAMS
argument_list|(
operator|(
name|int
name|bigend
operator|,
expr|struct
name|rndx_ext
operator|*
operator|,
name|RNDXR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_swap_rndx_out
name|PARAMS
argument_list|(
operator|(
name|int
name|bigend
operator|,
name|RNDXR
operator|*
operator|,
expr|struct
name|rndx_ext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (ECOFF_H) */
end_comment

end_unit

