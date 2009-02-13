begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Override definitions in elfos.h/svr4.h to be correct for IA64.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_INIT_LIBFUNCS
end_undef

begin_define
define|#
directive|define
name|TARGET_INIT_LIBFUNCS
value|ia64_sysv4_init_libfuncs
end_define

begin_comment
comment|/* We want DWARF2 as specified by the IA64 ABI.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_comment
comment|/* Stabs does not work properly for 64-bit targets.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_comment
comment|/* Various pseudo-ops for which the Intel assembler uses non-standard    definitions.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRING_ASM_OP
end_undef

begin_define
define|#
directive|define
name|STRING_ASM_OP
value|"\tstringz\t"
end_define

begin_undef
undef|#
directive|undef
name|SKIP_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SKIP_ASM_OP
value|"\t.skip\t"
end_define

begin_undef
undef|#
directive|undef
name|COMMON_ASM_OP
end_undef

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|"\t.common\t"
end_define

begin_undef
undef|#
directive|undef
name|ASCII_DATA_ASM_OP
end_undef

begin_define
define|#
directive|define
name|ASCII_DATA_ASM_OP
value|"\tstring\t"
end_define

begin_comment
comment|/* ia64-specific options for gas    ??? ia64 gas doesn't accept standard svr4 assembler options?  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-x %{mconstant-gp} %{mauto-pic} %(asm_extra)"
end_define

begin_comment
comment|/* ??? Unfortunately, .lcomm doesn't work, because it puts things in either    .bss or .sbss, and we can't control the decision of which is used.  When    I use .lcomm, I get a cryptic "Section group has no member" error from    the Intel simulator.  So we must explicitly put variables in .bss    instead.  This matters only if we care about the Intel assembler.  */
end_comment

begin_comment
comment|/* This is asm_output_aligned_bss from varasm.c without the    (*targetm.asm_out.globalize_label) call at the beginning.  */
end_comment

begin_comment
comment|/* This is for final.c, because it is used by ASM_DECLARE_OBJECT_NAME.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|size_directive_output
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_DECL_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\   if ((DECL)&& sdata_symbolic_operand (XEXP (DECL_RTL (DECL), 0), Pmode)) \     switch_to_section (sbss_section);					\   else									\     switch_to_section (bss_section);					\   ASM_OUTPUT_ALIGN (FILE, floor_log2 ((ALIGN) / BITS_PER_UNIT));	\   ASM_DECLARE_OBJECT_NAME (FILE, NAME, DECL);				\   ASM_OUTPUT_SKIP (FILE, SIZE ? SIZE : 1);				\ } while (0)
end_define

begin_comment
comment|/* The # tells the Intel assembler that this is not a register name.    However, we can't emit the # in a label definition, so we set a variable    in ASM_OUTPUT_LABEL to control whether we want the postfix here or not.    We append the # to the label name, but since NAME can be an expression    we have to scan it for a non-label character and insert the # there.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {						\   const char *name_ = NAME;			\   if (*name_ == '*')				\     name_++;					\   else						\     fputs (user_label_prefix, STREAM);		\   fputs (name_, STREAM);			\   if (!ia64_asm_output_label)			\     fputc ('#', STREAM);			\ } while (0)
end_define

begin_comment
comment|/* Intel assembler requires both flags and type if declaring a non-predefined    section.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section\t.init,\"ax\",\"progbits\""
end_define

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|"\t.section\t.fini,\"ax\",\"progbits\""
end_define

begin_comment
comment|/* svr4.h undefines this, so we need to define it here.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|ia64_dbx_register_number(REGNO)
end_define

begin_comment
comment|/* Things that svr4.h defines to the wrong type, because it assumes 32 bit    ints and 32 bit longs.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* We redefine this to use the ia64 .proc pseudo-op.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\   fputs ("\t.proc ", FILE);						\   assemble_name (FILE, NAME);						\   fputc ('\n', FILE);							\   ASM_OUTPUT_LABEL (FILE, NAME);					\ } while (0)
end_define

begin_comment
comment|/* We redefine this to use the ia64 .endp pseudo-op.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_SIZE
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\   fputs ("\t.endp ", FILE);						\   assemble_name (FILE, NAME);						\   fputc ('\n', FILE);							\ } while (0)
end_define

begin_comment
comment|/* Override default elf definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_RELOC_RW_MASK
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_RELOC_RW_MASK
value|ia64_reloc_rw_mask
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_RTX_SECTION
value|ia64_select_rtx_section
end_define

begin_define
define|#
directive|define
name|SDATA_SECTION_ASM_OP
value|"\t.sdata"
end_define

begin_define
define|#
directive|define
name|SBSS_SECTION_ASM_OP
value|"\t.sbss"
end_define

end_unit

