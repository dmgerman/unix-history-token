begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for some generic XCOFF file format    Copyright (C) 2001, 2002, 2003, 2004, 2007 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OBJECT_FORMAT
value|OBJECT_XCOFF
end_define

begin_comment
comment|/* The RS/6000 uses the XCOFF format.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* Define if the object format being used is COFF or a superset.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_COFF
end_define

begin_comment
comment|/* Define the magic numbers that we recognize as COFF.       AIX 4.3 adds U803XTOCMAGIC (0757) for 64-bit objects and AIX V5 adds     U64_TOCMAGIC (0767), but collect2.c does not include files in the     correct order to conditionally define the symbolic name in this macro.       The AIX linker accepts import/export files as object files,     so accept "#!" (0x2321) magic number.  */
end_comment

begin_define
define|#
directive|define
name|MY_ISCOFF
parameter_list|(
name|magic
parameter_list|)
define|\
value|((magic) == U802WRMAGIC || (magic) == U802ROMAGIC \    || (magic) == U802TOCMAGIC || (magic) == 0757 || (magic) == 0767 \    || (magic) == 0x2321)
end_define

begin_comment
comment|/* We don't have GAS for the RS/6000 yet, so don't write out special     .stabs in cc1plus.  */
end_comment

begin_define
define|#
directive|define
name|FASCIST_ASSEMBLER
end_define

begin_comment
comment|/* We define this to prevent the name mangler from putting dollar signs into    function names.  */
end_comment

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
end_define

begin_comment
comment|/* We define this to 0 so that gcc will never accept a dollar sign in a    variable name.  This is needed because the AIX assembler will not accept    dollar signs.  */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|0
end_define

begin_comment
comment|/* AIX .align pseudo-op accept value from 0 to 12, corresponding to    log base 2 of the alignment in bytes; 12 = 4096 bytes = 32768 bits.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|32768
end_define

begin_comment
comment|/* Return nonzero if this entry is to be written into the constant    pool in a special way.  We do so if this is a SYMBOL_REF, LABEL_REF    or a CONST containing one of them.  If -mfp-in-toc (the default),    we also do this for floating-point constants.  We actually can only    do this if the FP formats of the target and host machines are the    same, but we can't check that since not every file that uses    GO_IF_LEGITIMATE_ADDRESS_P includes real.h.  We also do this when    we can write the entry into the TOC and the entry is not larger    than a TOC entry.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TARGET_TOC								\&& (GET_CODE (X) == SYMBOL_REF					\        || (GET_CODE (X) == CONST&& GET_CODE (XEXP (X, 0)) == PLUS	\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == SYMBOL_REF)		\        || GET_CODE (X) == LABEL_REF					\        || (GET_CODE (X) == CONST_INT 					\&& GET_MODE_BITSIZE (MODE)<= GET_MODE_BITSIZE (Pmode))	\        || (GET_CODE (X) == CONST_DOUBLE					\&& (TARGET_POWERPC64						\ 	       || TARGET_MINIMAL_TOC					\ 	       || (SCALAR_FLOAT_MODE_P (GET_MODE (X))			\&& ! TARGET_NO_FP_IN_TOC)))))
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_OUTPUT_ANCHOR
value|rs6000_xcoff_asm_output_anchor
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_GLOBALIZE_LABEL
value|rs6000_xcoff_asm_globalize_label
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_INIT_SECTIONS
value|rs6000_xcoff_asm_init_sections
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_RELOC_RW_MASK
value|rs6000_xcoff_reloc_rw_mask
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|rs6000_xcoff_asm_named_section
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_SECTION
value|rs6000_xcoff_select_section
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_RTX_SECTION
value|rs6000_xcoff_select_rtx_section
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_UNIQUE_SECTION
value|rs6000_xcoff_unique_section
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FUNCTION_RODATA_SECTION
value|default_no_function_rodata_section
end_define

begin_define
define|#
directive|define
name|TARGET_STRIP_NAME_ENCODING
value|rs6000_xcoff_strip_name_encoding
end_define

begin_define
define|#
directive|define
name|TARGET_SECTION_TYPE_FLAGS
value|rs6000_xcoff_section_type_flags
end_define

begin_comment
comment|/* FP save and restore routines.  */
end_comment

begin_define
define|#
directive|define
name|SAVE_FP_PREFIX
value|"._savef"
end_define

begin_define
define|#
directive|define
name|SAVE_FP_SUFFIX
value|""
end_define

begin_define
define|#
directive|define
name|RESTORE_FP_PREFIX
value|"._restf"
end_define

begin_define
define|#
directive|define
name|RESTORE_FP_SUFFIX
value|""
end_define

begin_comment
comment|/* Function name to call to do profiling.  */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_MCOUNT
end_undef

begin_define
define|#
directive|define
name|RS6000_MCOUNT
value|".__mcount"
end_define

begin_comment
comment|/* This outputs NAME to FILE up to the first null or '['.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_OUTPUT_BASENAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|assemble_name ((FILE), (*targetm.strip_name_encoding) (NAME))
end_define

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { RS6000_OUTPUT_BASENAME (FILE, NAME); fputs (":\n", FILE); } while (0)
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_comment
comment|/* Globalizing directive for a label.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"\t.globl "
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START
value|rs6000_xcoff_file_start
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|rs6000_xcoff_file_end
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
value|false
end_define

begin_comment
comment|/* This macro produces the initial definition of a function name.    On the RS/6000, we need to place an extra '.' in the function name and    output the function descriptor.     The csect for the function will have already been created when    text_section was selected.  We do have to go back to that csect, however.     The third and fourth parameters to the .function pseudo-op (16 and 044)    are placeholders which no longer have any use.  */
end_comment

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
value|{ if (TREE_PUBLIC (DECL))					\     {								\       if (!RS6000_WEAK || !DECL_WEAK (decl))			\ 	{							\ 	  fputs ("\t.globl .", FILE);				\ 	  RS6000_OUTPUT_BASENAME (FILE, NAME);			\ 	  putc ('\n', FILE);					\ 	}							\     }								\   else								\     {								\       fputs ("\t.lglobl .", FILE);				\       RS6000_OUTPUT_BASENAME (FILE, NAME);			\       putc ('\n', FILE);					\     }								\   fputs ("\t.csect ", FILE);					\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fputs (TARGET_32BIT ? "[DS]\n" : "[DS],3\n", FILE);		\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fputs (":\n", FILE);						\   fputs (TARGET_32BIT ? "\t.long ." : "\t.llong .", FILE);	\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fputs (", TOC[tc0], 0\n", FILE);				\   in_section = NULL;						\   switch_to_section (function_section (DECL));			\   putc ('.', FILE);						\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fputs (":\n", FILE);						\   if (write_symbols != NO_DEBUG)				\     xcoffout_declare_function (FILE, DECL, NAME);		\ }
end_define

begin_comment
comment|/* Output a reference to SYM on FILE.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SYMBOL_REF
parameter_list|(
name|FILE
parameter_list|,
name|SYM
parameter_list|)
define|\
value|rs6000_output_symbol_ref (FILE, SYM)
end_define

begin_comment
comment|/* This says how to output an external.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_EXTERNAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|{ rtx _symref = XEXP (DECL_RTL (DECL), 0);				\   if ((TREE_CODE (DECL) == VAR_DECL					\        || TREE_CODE (DECL) == FUNCTION_DECL)				\&& (NAME)[strlen (NAME) - 1] != ']')				\     {									\       XSTR (_symref, 0) = concat (XSTR (_symref, 0),			\ 				  (TREE_CODE (DECL) == FUNCTION_DECL	\ 				   ? "[DS]" : "[RW]"),			\ 				  NULL);				\     }									\ }
end_define

begin_comment
comment|/* This is how to output an internal label prefix.  rs6000.c uses this    when generating traceback tables.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL_PREFIX
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|)
define|\
value|fprintf (FILE, "%s..", PREFIX)
end_define

begin_comment
comment|/* This is how to output a label for a jump table.  Arguments are the same as    for (*targetm.asm_out.internal_label), except the insn for the jump table is    passed.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLEINSN
parameter_list|)
define|\
value|{ ASM_OUTPUT_ALIGN (FILE, 2); (*targetm.asm_out.internal_label) (FILE, PREFIX, NUM); }
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (LABEL, "*%s..%u", (PREFIX), (unsigned) (NUM))
end_define

begin_comment
comment|/* This is how to output an assembler line to define N characters starting    at P to FILE.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|P
parameter_list|,
name|N
parameter_list|)
value|output_ascii ((FILE), (P), (N))
end_define

begin_comment
comment|/* This is how to advance the location counter by SIZE bytes.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_ASM_OP
value|"\t.space "
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf (FILE, "%s"HOST_WIDE_INT_PRINT_UNSIGNED"\n", SKIP_ASM_OP, (SIZE))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|"\t.comm "
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do { fputs (COMMON_ASM_OP, (FILE));			\        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\        if ((ALIGN)> 32)				\ 	 fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n", (SIZE), \ 		  exact_log2 ((ALIGN) / BITS_PER_UNIT)); \        else if ((SIZE)> 4)				\          fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",3\n", (SIZE)); \        else						\ 	 fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE)); \   } while (0)
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.    Alignment cannot be specified, but we can try to maintain    alignment after preceding TOC section if it was aligned    for 64-bit mode.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_COMMON_ASM_OP
value|"\t.lcomm "
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do { fputs (LOCAL_COMMON_ASM_OP, (FILE));		\        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\        fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%s\n", \ 		(TARGET_32BIT ? (SIZE) : (ROUNDED)),	\ 		xcoff_bss_section_name);		\      } while (0)
end_define

begin_comment
comment|/* This is how we tell the assembler that two symbols have the same value.  */
end_comment

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set "
end_define

begin_comment
comment|/* This is how we tell the assembler to equate two values.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do {	fprintf ((FILE), "%s", SET_ASM_OP);				\ 	RS6000_OUTPUT_BASENAME (FILE, LABEL1);				\ 	fprintf (FILE, ",");						\ 	RS6000_OUTPUT_BASENAME (FILE, LABEL2);				\ 	fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* Used by rs6000_assemble_integer, among others.  */
end_comment

begin_define
define|#
directive|define
name|DOUBLE_INT_ASM_OP
value|"\t.llong\t"
end_define

begin_comment
comment|/* Output before instructions.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.csect .text[PR]"
end_define

begin_comment
comment|/* Output before writable data.    Align entire section to BIGGEST_ALIGNMENT.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.csect .data[RW],3"
end_define

begin_comment
comment|/* Define to prevent DWARF2 unwind info in the data section rather    than in the .eh_frame section.  We do this because the AIX linker    would otherwise garbage collect these sections.  */
end_comment

begin_define
define|#
directive|define
name|EH_FRAME_IN_DATA_SECTION
value|1
end_define

end_unit

