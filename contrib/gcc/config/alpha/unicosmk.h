begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for DEC Alpha on Cray    T3E running Unicos/Mk.    Copyright (C) 2001, 2002    Free Software Foundation, Inc.    Contributed by Roman Lechtchinsky (rl@cs.tu-berlin.de)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ABI_UNICOSMK
end_undef

begin_define
define|#
directive|define
name|TARGET_ABI_UNICOSMK
value|1
end_define

begin_comment
comment|/* CAM requires a slash before floating-pointing instruction suffixes.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_AS_SLASH_BEFORE_SUFFIX
end_undef

begin_define
define|#
directive|define
name|TARGET_AS_SLASH_BEFORE_SUFFIX
value|1
end_define

begin_comment
comment|/* The following defines are necessary for the standard headers to work    correctly.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {							\ 	builtin_define ("__unix");				\ 	builtin_define ("_UNICOS=205");				\ 	builtin_define ("_CRAY");				\ 	builtin_define ("_CRAYT3E");				\ 	builtin_define ("_CRAYMPP");				\ 	builtin_define ("_CRAYIEEE");				\ 	builtin_define ("_ADDR64");				\ 	builtin_define ("_LD64");				\ 	builtin_define ("__UNICOSMK__");			\     } while (0)
end_define

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|32
end_define

begin_undef
undef|#
directive|undef
name|INT_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* This is consistent with the definition Cray CC uses.  */
end_comment

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
value|64
end_define

begin_comment
comment|/* #define SIZE_TYPE "unsigned int" #define PTRDIFF_TYPE "int" */
end_comment

begin_comment
comment|/* Alphas are operated in big endian mode on the Cray T3E.  */
end_comment

begin_undef
undef|#
directive|undef
name|BITS_BIG_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|BYTES_BIG_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|WORDS_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRUCTURE_SIZE_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|64
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|256
end_define

begin_comment
comment|/* Include the frame pointer in fixed_regs and call_used_regs as it can't be     used as a general-purpose register even in frameless functions.    ??? The global_regs hack is needed for now because -O2 sometimes tries to     eliminate $15 increments/decrements in frameless functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|CONDITIONAL_REGISTER_USAGE
end_undef

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|do {					\     fixed_regs[15] = 1;			\     call_used_regs[15] = 1;		\     global_regs[15] = 1;		\   } while(0)
end_define

begin_escape
end_escape

begin_comment
comment|/* The stack frame grows downward.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Define the offset between two registers, one to be eliminated, and the    other its replacement, at the start of a routine. This is somewhat    complicated on the T3E which is why we use a function.  */
end_comment

begin_undef
undef|#
directive|undef
name|INITIAL_ELIMINATION_OFFSET
end_undef

begin_define
define|#
directive|define
name|INITIAL_ELIMINATION_OFFSET
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|do {									\     (OFFSET) = unicosmk_initial_elimination_offset ((FROM), (TO));	\   } while (0)
end_define

begin_comment
comment|/* Define this if stack space is still allocated for a parameter passed    in a register. On the T3E, stack space is preallocated for all outgoing    arguments, including those passed in registers. To avoid problems, we    assume that at least 48 bytes (i.e. enough space for all arguments passed    in registers) are allocated.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|DECL
parameter_list|)
value|48
end_define

begin_define
define|#
directive|define
name|OUTGOING_REG_PARM_STACK_SPACE
end_define

begin_comment
comment|/* If an argument can't be passed in registers even though not all argument    registers have been used yet, it is passed on the stack in the space     preallocated for these registers.  */
end_comment

begin_define
define|#
directive|define
name|STACK_PARMS_IN_REG_PARM_AREA
end_define

begin_comment
comment|/* This evaluates to nonzero if we do not know how to pass TYPE solely in    registers. This is the case for all arguments that do not fit in two    registers.  */
end_comment

begin_define
define|#
directive|define
name|MUST_PASS_IN_STACK
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((TYPE) != 0                                          		\&& (TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST      		\        || (TREE_ADDRESSABLE (TYPE) || ALPHA_ARG_SIZE (MODE, TYPE, 0)> 2)))
end_define

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On Unicos/Mk, this is a structure that contains various information for    the static subroutine information block (SSIB) and the call information    word (CIW).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The overall number of arguments.  */
name|int
name|num_args
decl_stmt|;
comment|/* The overall size of the arguments in words.  */
name|int
name|num_arg_words
decl_stmt|;
comment|/* The number of words passed in registers.  */
name|int
name|num_reg_words
decl_stmt|;
comment|/* If an argument must be passed in the stack, all subsequent arguments      must be passed there, too. This flag indicates whether this is the      case.  */
name|int
name|force_stack
decl_stmt|;
comment|/* This array indicates whether a word is passed in an integer register or      a floating point one.  */
comment|/* For each of the 6 register arguments, the corresponding flag in this      array indicates whether the argument is passed in an integer or a      floating point register.  */
name|int
name|reg_args_type
index|[
literal|6
index|]
decl_stmt|;
block|}
name|unicosmk_arg_info
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|CUMULATIVE_ARGS
end_undef

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|unicosmk_arg_info
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS for a call to a    function whose data type is FNTYPE.  For a library call, FNTYPE is 0.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_CUMULATIVE_ARGS
end_undef

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|LIBNAME
parameter_list|,
name|INDIRECT
parameter_list|,
name|N_NAMED_ARGS
parameter_list|)
define|\
value|do { (CUM).num_args = 0;					\        (CUM).num_arg_words = 0;					\        (CUM).num_reg_words = 0;					\        (CUM).force_stack = 0;					\   } while(0)
end_define

begin_comment
comment|/* Update the data in CUM to advance over an argument of mode MODE and data    type TYPE. (TYPE is null for libcalls where that information may not be    available.)     On Unicos/Mk, at most 6 words can be passed in registers. Structures    which fit in two words are passed in registers, larger structures are    passed on stack.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_ARG_ADVANCE
end_undef

begin_define
define|#
directive|define
name|FUNCTION_ARG_ADVANCE
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|do {								\   int size;							\ 								\   size = ALPHA_ARG_SIZE (MODE, TYPE, NAMED);			\                                                                 \   if (size> 2 || MUST_PASS_IN_STACK (MODE, TYPE)		\       || (CUM).num_reg_words + size> 6)			\     (CUM).force_stack = 1;					\                                                                 \   if (! (CUM).force_stack)					\     {								\       int i;							\       int isfloat;						\       isfloat = (GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT	\               || GET_MODE_CLASS (MODE) == MODE_FLOAT);		\       for (i = 0; i< size; i++)				\         {							\           (CUM).reg_args_type[(CUM).num_reg_words] = isfloat;	\           ++(CUM).num_reg_words;				\         }							\     }								\   (CUM).num_arg_words += size;					\   ++(CUM).num_args;						\ } while(0)
end_define

begin_comment
comment|/* An argument is passed either entirely in registers or entirely on stack.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_ARG_PARTIAL_NREGS
end_undef

begin_comment
comment|/* #define FUNCTION_ARG_PARTIAL_NREGS(CUM,MODE,TYPE,NAMED) 0 */
end_comment

begin_comment
comment|/* This ensures that $15 increments/decrements in leaf functions won't get    eliminated.  */
end_comment

begin_undef
undef|#
directive|undef
name|EPILOGUE_USES
end_undef

begin_define
define|#
directive|define
name|EPILOGUE_USES
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == 26 || (REGNO) == 15)
end_define

begin_comment
comment|/* Would have worked, only the stack doesn't seem to be executable #undef TRAMPOLINE_TEMPLATE #define TRAMPOLINE_TEMPLATE(FILE)			\ do { fprintf (FILE, "\tbr $1,0\n");			\      fprintf (FILE, "\tldq $0,12($1)\n");		\      fprintf (FILE, "\tldq $1,20($1)\n");		\      fprintf (FILE, "\tjmp $31,(r0)\n");		\      fprintf (FILE, "\tbis $31,$31,$31\n");		\      fprintf (FILE, "\tbis $31,$31,$31\n");		\ } while (0) */
end_comment

begin_comment
comment|/* We don't support nested functions (yet).  */
end_comment

begin_undef
undef|#
directive|undef
name|TRAMPOLINE_TEMPLATE
end_undef

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
value|abort ()
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses for the index in the    tablejump instruction. On Unicos/Mk, we don't support relative case    vectors yet, thus the entries should be absolute addresses.  */
end_comment

begin_undef
undef|#
directive|undef
name|CASE_VECTOR_MODE
end_undef

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|DImode
end_define

begin_undef
undef|#
directive|undef
name|CASE_VECTOR_PC_RELATIVE
end_undef

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_comment
comment|/* #define DEFAULT_SIGNED_CHAR 1 */
end_comment

begin_comment
comment|/* The Cray assembler is really weird with respect to sections. It has only    named sections and you can't reopen a section once it has been closed.    This means that we have to generate unique names whenever we want to    reenter the text or the data section. The following is a rather bad hack    as TEXT_SECTION_ASM_OP and DATA_SECTION_ASM_OP are supposed to be    constants.  */
end_comment

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|unicosmk_text_section ()
end_define

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|unicosmk_data_section ()
end_define

begin_comment
comment|/* There are no read-only sections on Unicos/Mk.  */
end_comment

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
value|data_section
end_define

begin_comment
comment|/* Define extra sections for common data and SSIBs (static subroutine    information blocks). The actual section header is output by the callers    of these functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_common, in_ssib
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|COMMON_SECTION			\ SSIB_SECTION
end_define

begin_function_decl
specifier|extern
name|void
name|common_section
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|COMMON_SECTION
define|\
value|void				\ common_section (void)		\ {				\   in_section = in_common;	\ }
end_define

begin_function_decl
specifier|extern
name|void
name|ssib_section
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SSIB_SECTION
define|\
value|void				\ ssib_section (void)		\ {				\   in_section = in_ssib;		\ }
end_define

begin_comment
comment|/* We take care of this in unicosmk_file_start.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_FILENAME
end_undef

begin_comment
comment|/* This is how to output a label for a jump table.  Arguments are the same as    for (*targetm.asm_out.internal_label), except the insn for the jump table is    passed.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_LABEL
end_undef

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
value|(*targetm.asm_out.internal_label) (FILE, PREFIX, NUM)
end_define

begin_comment
comment|/* CAM has some restrictions with respect to string literals. It won't    accept lines with more that 256 characters which means that we have    to split long strings. Moreover, it only accepts escape sequences of    the form \nnn in the range 0 to 127. We generate .byte directives for    escapes characters greater than 127. And finally, ` must be escaped.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|MYFILE
parameter_list|,
name|MYSTRING
parameter_list|,
name|MYLENGTH
parameter_list|)
define|\
value|do {									      \     FILE *_hide_asm_out_file = (MYFILE);				      \     const unsigned char *_hide_p = (const unsigned char *) (MYSTRING);	      \     int _hide_thissize = (MYLENGTH);					      \     int _size_so_far = 0;						      \     {									      \       FILE *asm_out_file = _hide_asm_out_file;				      \       const unsigned char *p = _hide_p;					      \       int thissize = _hide_thissize;					      \       int in_ascii = 0;							      \       int i;								      \ 									      \       for (i = 0; i< thissize; i++)					      \ 	{								      \ 	  register int c = p[i];					      \ 									      \ 	  if (c> 127)							      \ 	    {								      \ 	      if (in_ascii)						      \ 		{							      \ 		  fprintf (asm_out_file, "\"\n");			      \ 		  in_ascii = 0;						      \ 		}							      \ 									      \ 	      fprintf (asm_out_file, "\t.byte\t%d\n", c);		      \ 	    }								      \ 	  else								      \ 	    {								      \ 	      if (! in_ascii)						      \ 		{							      \ 		  fprintf (asm_out_file, "\t.ascii\t\"");		      \ 		  in_ascii = 1;						      \ 		  _size_so_far = 0;					      \ 		}							      \ 	      else if (_size_so_far>= 64)				      \ 		{							      \ 		  fprintf (asm_out_file, "\"\n\t.ascii\t\"");		      \ 		  _size_so_far = 0;					      \ 		}							      \ 									      \ 	      if (c == '\"' || c == '\\' || c == '`')			      \ 		putc ('\\', asm_out_file);				      \ 	      if (c>= ' ')						      \ 		putc (c, asm_out_file);					      \ 	      else							      \ 		fprintf (asm_out_file, "\\%.3o", c);			      \ 	      ++ _size_so_far;						      \ 	    }								      \ 	}								      \       if (in_ascii)							      \ 	fprintf (asm_out_file, "\"\n");					      \     }									      \   } while(0)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_VEC_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.quad $L%d\n", (VALUE))
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (Unicos/Mk does not use such vectors yet).  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
value|abort ()
end_define

begin_comment
comment|/* We can't output case vectors in the same section as the function code    because CAM doesn't allow data definitions in code sections. Thus, we    simply record the case vectors and put them in a separate section after    the function.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC
parameter_list|(
name|LAB
parameter_list|,
name|VEC
parameter_list|)
define|\
value|unicosmk_defer_case_vector ((LAB),(VEC))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_VEC
parameter_list|(
name|LAB
parameter_list|,
name|VEC
parameter_list|)
value|abort ()
end_define

begin_comment
comment|/* This is how to output an assembler line that says to advance the location    counter to a multiple of 2**LOG bytes. Annoyingly, CAM always uses zeroes    to fill the unused space which does not work in code sections. We have to     be careful not to use the .align directive in code sections.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|LOG
parameter_list|)
value|unicosmk_output_align (STREAM, LOG)
end_define

begin_comment
comment|/* This is how to advance the location counter by SIZE bytes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|STREAM
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf ((STREAM), "\t.byte\t0:"HOST_WIDE_INT_PRINT_UNSIGNED"\n",\ 	   (SIZE));
end_define

begin_comment
comment|/* This says how to output an assembler line to define a global common    symbol. We need the alignment information because it has to be supplied    in the section header.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

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
value|unicosmk_output_common ((FILE), (NAME), (SIZE), (ALIGN))
end_define

begin_comment
comment|/* This says how to output an assembler line to define a local symbol.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
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
value|do { data_section ();					\        fprintf (FILE, "\t.align\t%d\n", floor_log2 ((ALIGN) / BITS_PER_UNIT));\        ASM_OUTPUT_LABEL ((FILE), (NAME));		\        fprintf (FILE, "\t.byte 0:"HOST_WIDE_INT_PRINT_UNSIGNED"\n",(SIZE));\   } while (0)
end_define

begin_comment
comment|/* CAM does not allow us to declare a symbol as external first and then    define it in the same file later. Thus, we keep a list of all external    references, remove all symbols defined locally from it and output it at    the end of the asm file.  */
end_comment

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
value|unicosmk_add_extern ((NAME))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|STREAM
parameter_list|,
name|SYMREF
parameter_list|)
define|\
value|unicosmk_add_extern (XSTR ((SYMREF), 0))
end_define

begin_comment
comment|/* This is how to declare an object. We don't have to output anything if    it is a global variable because those go into unique `common' sections    and the section name is globally visible. For local variables, we simply    output the label. In any case, we have to record that no extern    declaration should be generated for the symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do { tree name_tree;					\        name_tree = get_identifier ((NAME));		\        TREE_ASM_WRITTEN (name_tree) = 1;		\        if (!TREE_PUBLIC (DECL))				\ 	 {						\ 	   assemble_name (STREAM, NAME);		\ 	   fputs (":\n", STREAM);			\          }						\   } while(0)
end_define

begin_comment
comment|/* #define ASM_OUTPUT_SECTION_NAME(STREAM, DECL, NAME, RELOC)	\   unicosmk_output_section_name ((STREAM), (DECL), (NAME), (RELOC)) */
end_comment

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|unicosmk_asm_named_section
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_MAX_SKIP_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|POWER
parameter_list|,
name|MAXSKIP
parameter_list|)
end_define

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|NM_FLAGS
end_undef

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_COFF
end_undef

begin_comment
comment|/* We cannot generate debugging information on Unicos/Mk.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|MIPS_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DWARF2_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DWARF2_UNWIND_INFO
end_undef

begin_undef
undef|#
directive|undef
name|INCOMING_RETURN_ADDR_RTX
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

begin_comment
comment|/* We don't need a start file.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|""
end_define

begin_comment
comment|/* These are the libraries we have to link with.    ??? The Craylibs directory should be autoconfed.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-L/opt/ctl/craylibs/craylibs -lu -lm -lc -lsma"
end_define

begin_undef
undef|#
directive|undef
name|EXPAND_BUILTIN_VA_START
end_undef

begin_undef
undef|#
directive|undef
name|EXPAND_BUILTIN_VA_ARG
end_undef

begin_define
define|#
directive|define
name|EH_FRAME_IN_DATA_SECTION
value|1
end_define

end_unit

