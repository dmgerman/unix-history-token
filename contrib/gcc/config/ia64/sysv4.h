begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Override definitions in elfos.h/svr4.h to be correct for IA64.  */
end_comment

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
comment|/* ??? Unfortunately, .lcomm doesn't work, because it puts things in either    .bss or .sbss, and we can't control the decision of which is used.  When    I use .lcomm, I get a cryptic "Section group has no member" error from    the Intel simulator.  So we must explicitly put variables in .bss    instead.  This matters only if we care about the Intel assembler.  */
end_comment

begin_comment
comment|/* This is asm_output_aligned_bss from varasm.c without the ASM_GLOBALIZE_LABEL    call at the beginning.  */
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
value|do {									\   if ((DECL)								\&& XSTR (XEXP (DECL_RTL (DECL), 0), 0)[0] == SDATA_NAME_FLAG_CHAR) \     sbss_section ();							\   else									\     bss_section ();							\   ASM_OUTPUT_ALIGN (FILE, floor_log2 ((ALIGN) / BITS_PER_UNIT));	\   ASM_DECLARE_OBJECT_NAME (FILE, NAME, DECL);				\   ASM_OUTPUT_SKIP (FILE, SIZE ? SIZE : 1);				\ } while (0)
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
value|do {						\   const char *name_ = NAME;			\   if (*name_ == SDATA_NAME_FLAG_CHAR)		\     name_++;					\   if (*name_ == '*')				\     name_++;					\   else						\     fputs (user_label_prefix, STREAM);		\   fputs (name_, STREAM);			\   if (!ia64_asm_output_label)			\     fputc ('#', STREAM);			\ } while (0)
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
comment|/* A C expression which outputs to the stdio stream STREAM some appropriate    text to go at the start of an assembler file.  */
end_comment

begin_comment
comment|/* ??? Looks like almost every port, except for a few original ones, get this    wrong.  Must emit #NO_APP as first line of file to turn of special assembler    preprocessing of files.  */
end_comment

begin_comment
comment|/* ??? Even worse, it doesn't work, because gas does not accept the tab chars    that dwarf2out.c emits when #NO_APP.  */
end_comment

begin_comment
comment|/* ??? Unrelated, but dwarf2out.c emits unnecessary newlines after strings,    may as well fix at the same time.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|do {									\   output_file_directive (STREAM, main_input_filename);			\   emit_safe_across_calls (STREAM);					\ } while (0)
end_define

begin_comment
comment|/* We override svr4.h so that we can support the sdata section.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{									\   if (TREE_CODE (DECL) == STRING_CST)					\     {									\       if (! flag_writable_strings)					\ 	mergeable_string_section ((DECL), (ALIGN), 0);			\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (DECL) == VAR_DECL)				\     {									\       if (XSTR (XEXP (DECL_RTL (DECL), 0), 0)[0]			\ 	  == SDATA_NAME_FLAG_CHAR)					\         sdata_section ();						\
comment|/* ??? We need the extra RELOC check, because the default is to	\ 	 only check RELOC if flag_pic is set, and we don't set flag_pic \ 	 (yet?).  */
value|\       else if (!DECL_READONLY_SECTION (DECL, RELOC) || (RELOC))		\ 	data_section ();						\       else if (flag_merge_constants< 2)				\
comment|/* C and C++ don't allow different variables to share		\ 	   the same location.  -fmerge-all-constants allows		\ 	   even that (at the expense of not conforming).  */
value|\ 	const_section ();						\       else if (TREE_CODE (DECL_INITIAL (DECL)) == STRING_CST)		\ 	mergeable_string_section (DECL_INITIAL (DECL), (ALIGN), 0);	\       else								\ 	mergeable_constant_section (DECL_MODE (DECL), (ALIGN), 0);	\     }									\
comment|/* This could be a CONSTRUCTOR containing ADDR_EXPR of a VAR_DECL,	\      in which case we can't put it in a shared library rodata.  */
value|\   else if (flag_pic&& (RELOC))						\     data_section ();							\   else									\     const_section ();							\ }
end_define

begin_comment
comment|/* Similarly for constant pool data.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|ia64_section_threshold
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{									\   if (GET_MODE_SIZE (MODE)> 0						\&& GET_MODE_SIZE (MODE)<= ia64_section_threshold)		\     sdata_section ();							\   else if (flag_pic&& symbolic_operand ((RTX), (MODE)))		\     data_section ();							\   else									\     mergeable_constant_section ((MODE), (ALIGN), 0);			\ }
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_const, in_sdata, in_sbss
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|CONST_SECTION_FUNCTION						\   SDATA_SECTION_FUNCTION						\   SBSS_SECTION_FUNCTION
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
name|SDATA_SECTION_FUNCTION
define|\
value|void									\ sdata_section ()							\ {									\   if (in_section != in_sdata)						\     {									\       fprintf (asm_out_file, "%s\n", SDATA_SECTION_ASM_OP);		\       in_section = in_sdata;						\     }									\ }
end_define

begin_define
define|#
directive|define
name|SBSS_SECTION_ASM_OP
value|"\t.sbss"
end_define

begin_define
define|#
directive|define
name|SBSS_SECTION_FUNCTION
define|\
value|void									\ sbss_section ()								\ {									\   if (in_section != in_sbss)						\     {									\       fprintf (asm_out_file, "%s\n", SBSS_SECTION_ASM_OP);		\       in_section = in_sbss;						\     }									\ }
end_define

end_unit

