begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Output variables, constants and external declarations, for GNU compiler.    Copyright (C) 1996, 1997, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|OPEN_VMS
value|1
end_define

begin_comment
comment|/* This enables certain macros in alpha.h, which will make an indirect    reference to an external symbol an invalid address.  This needs to be    defined before we include alpha.h, since it determines which macros    are used for GO_IF_*.  */
end_comment

begin_define
define|#
directive|define
name|NO_EXTERNAL_INDIRECT_ADDRESS
end_define

begin_include
include|#
directive|include
file|"alpha/alpha.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-D__ALPHA -Dvms -DVMS -D__vms__ -D__VMS__ -Asystem(vms)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|"\ %{mfloat-ieee:-D__IEEE_FLOAT} \ %{mfloat-vax:-D__G_FLOAT} \ %{!mfloat-vax:-D__IEEE_FLOAT}"
end_define

begin_comment
comment|/* Under OSF4, -p and -pg require -lprof1, and -lprof1 requires -lpdf.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-lprof1 -lpdf} %{pg:-lprof1 -lpdf} %{a:-lprof2} -lc"
end_define

begin_comment
comment|/* Pass "-G 8" to ld because Alpha's CC does.  Pass -O3 if we are    optimizing, -O1 if we are not.  Pass -shared, -non_shared or    -call_shared as appropriate.  Also pass -pg.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"-G 8 %{O*:-O3} %{!O*:-O1} %{static:-non_shared} \    %{!static:%{shared:-shared} %{!shared:-call_shared}} %{pg} %{taso} \    %{rpath*}"
end_define

begin_comment
comment|/* We allow $'s in identifiers unless -ansi is used .. */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|2
end_define

begin_comment
comment|/* These match the definitions used in DECCRTL, the VMS C run-time library  #define SIZE_TYPE	"unsigned int" #define PTRDIFF_TYPE	"int" */
end_comment

begin_comment
comment|/* Use memcpy for structure copying, and so forth.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* By default, allow $ to be part of an identifier.  */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|2
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_FP|MASK_FPREGS|MASK_GAS)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_OPEN_VMS
end_undef

begin_define
define|#
directive|define
name|TARGET_OPEN_VMS
value|1
end_define

begin_undef
undef|#
directive|undef
name|TARGET_NAME
end_undef

begin_define
define|#
directive|define
name|TARGET_NAME
value|"OpenVMS/Alpha"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (%s)", TARGET_NAME);
end_define

begin_comment
comment|/* The structure return address arrives as an "argument" on VMS.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRUCT_VALUE_REGNUM
end_undef

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|0
end_define

begin_undef
undef|#
directive|undef
name|PCC_STATIC_STRUCT_RETURN
end_undef

begin_comment
comment|/* no floating emulation.  */
end_comment

begin_undef
undef|#
directive|undef
name|REAL_ARITHMETIC
end_undef

begin_comment
comment|/* "long" is 32 bits.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Pointer is 32 bits but the hardware has 64-bit addresses, sign extended. */
end_comment

begin_undef
undef|#
directive|undef
name|POINTER_SIZE
end_undef

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|POINTERS_EXTEND_UNSIGNED
value|0
end_define

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|524288
end_define

begin_comment
comment|/* 8 x 2^16 by DEC Ada Test CD40VRA */
end_comment

begin_undef
undef|#
directive|undef
name|FIXED_REGISTERS
end_undef

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
end_define

begin_undef
undef|#
directive|undef
name|CALL_USED_REGISTERS
end_undef

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
end_define

begin_undef
undef|#
directive|undef
name|HARD_FRAME_POINTER_REGNUM
end_undef

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
value|29
end_define

begin_undef
undef|#
directive|undef
name|CAN_ELIMINATE
end_undef

begin_define
define|#
directive|define
name|CAN_ELIMINATE
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|((TO) != STACK_POINTER_REGNUM || ! alpha_using_fp ())
end_define

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
value|{ if ((FROM) == FRAME_POINTER_REGNUM)					\     (OFFSET) = alpha_sa_size () + alpha_pv_save_size ();		\   else if ((FROM) == ARG_POINTER_REGNUM)				\     (OFFSET) = (ALPHA_ROUND (alpha_sa_size () + alpha_pv_save_size ()	\ 			     + get_frame_size ()			\ 			     + current_function_pretend_args_size)	\ 		- current_function_pretend_args_size);			\   if ((TO) == STACK_POINTER_REGNUM)					\     (OFFSET) += ALPHA_ROUND (current_function_outgoing_args_size);	\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On Alpha/VMS, this is a structure that contains the number of    arguments and, for each argument, the datatype of that argument.     The number of arguments is a number of words of arguments scanned so far.    Thus 6 or more means all following args should go on the stack.  */
end_comment

begin_enum
enum|enum
name|avms_arg_type
block|{
name|I64
block|,
name|FF
block|,
name|FD
block|,
name|FG
block|,
name|FS
block|,
name|FT
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|num_args
decl_stmt|;
name|enum
name|avms_arg_type
name|atypes
index|[
literal|6
index|]
decl_stmt|;
block|}
name|avms_arg_info
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
value|avms_arg_info
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.  */
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
parameter_list|)
define|\
value|(CUM).num_args = 0;						\   (CUM).atypes[0] = (CUM).atypes[1] = (CUM).atypes[2] = I64;	\   (CUM).atypes[3] = (CUM).atypes[4] = (CUM).atypes[5] = I64;
end_define

begin_comment
comment|/* Update the data in CUM to advance over an argument    of mode MODE and data type TYPE.    (TYPE is null for libcalls where that information may not be available.)  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|avms_arg_type
name|alpha_arg_type
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode (or VOIDmode for no more args).    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On Alpha the first 6 words of args are normally in registers    and the rest are pushed.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_arg_info_reg_val
parameter_list|()
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|FUNCTION_ARG
end_undef

begin_define
define|#
directive|define
name|FUNCTION_ARG
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
value|((MODE) == VOIDmode ? alpha_arg_info_reg_val (CUM)		\  : ((CUM.num_args)< 6&& ! MUST_PASS_IN_STACK (MODE, TYPE)	\     ? gen_rtx(REG, (MODE),					\ 	      ((CUM).num_args + 16				\ 	       + ((TARGET_FPREGS				\&& (GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT \ 		       || GET_MODE_CLASS (MODE) == MODE_FLOAT)) \ 		  * 32)))			\     : 0))
end_define

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
value|if (MUST_PASS_IN_STACK (MODE, TYPE))					\     (CUM).num_args += 6;						\   else									\     {									\       if ((CUM).num_args< 6)						\         (CUM).atypes[(CUM).num_args] = alpha_arg_type (MODE);		\ 									\      (CUM).num_args += ALPHA_ARG_SIZE (MODE, TYPE, NAMED);		\     }
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    For args passed entirely in registers or entirely in memory, zero.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_ARG_PARTIAL_NREGS
end_undef

begin_define
define|#
directive|define
name|FUNCTION_ARG_PARTIAL_NREGS
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
value|((CUM).num_args< 6&& 6< (CUM).num_args				\    + ALPHA_ARG_SIZE (MODE, TYPE, NAMED)					\  ? 6 - (CUM).num_args : 0)
end_define

begin_comment
comment|/* Perform any needed actions needed for a function that is receiving a    variable number of arguments.      CUM is as for INIT_CUMULATIVE_ARGS.     MODE and TYPE are the mode and type of the current parameter.     PRETEND_SIZE is a variable that should be set to the amount of stack    that must be pushed by the prolog to pretend that our caller pushed    it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.      For VMS, we allocate space for all 6 arg registers plus a count.     However, if NO registers need to be saved, don't allocate any space.    This is not only because we won't need the space, but because AP includes    the current_pretend_args_size and we don't want to mess up any    ap-relative addresses already made.   */
end_comment

begin_undef
undef|#
directive|undef
name|SETUP_INCOMING_VARARGS
end_undef

begin_define
define|#
directive|define
name|SETUP_INCOMING_VARARGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|PRETEND_SIZE
parameter_list|,
name|NO_RTL
parameter_list|)
define|\
value|{ if ((CUM).num_args< 6)				\     {							\       if (! (NO_RTL))					\ 	{						\ 	  emit_move_insn (gen_rtx (REG, DImode, 1),	\ 			  virtual_incoming_args_rtx);	\ 	  emit_insn (gen_arg_home ());			\ 	}						\ 						        \       PRETEND_SIZE = 7 * UNITS_PER_WORD;		\     }							\ }
end_define

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
name|FILE
parameter_list|)
define|\
value|{								\   alpha_write_verstamp (FILE);					\   fprintf (FILE, "\t.set noreorder\n");				\   fprintf (FILE, "\t.set volatile\n");				\   ASM_OUTPUT_SOURCE_FILENAME (FILE, main_input_filename);	\ }
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\     if (REAL_VALUE_ISINF (VALUE)					\         || REAL_VALUE_ISNAN (VALUE)					\ 	|| REAL_VALUE_MINUS_ZERO (VALUE))				\       {									\ 	long t;								\ 	REAL_VALUE_TO_TARGET_SINGLE ((VALUE), t);			\ 	fprintf (FILE, "\t.long 0x%lx\n", t& 0xffffffff);		\       }									\     else								\       {									\ 	char str[30];							\ 	REAL_VALUE_TO_DECIMAL ((VALUE), "%.20e", str);			\ 	fprintf (FILE, "\t.%c_floating %s\n", (TARGET_FLOAT_VAX)?'f':'s', str);	\       }									\   }
end_define

begin_define
define|#
directive|define
name|LINK_SECTION_ASM_OP
value|".link"
end_define

begin_define
define|#
directive|define
name|READONLY_SECTION_ASM_OP
value|".rdata"
end_define

begin_define
define|#
directive|define
name|LITERALS_SECTION_ASM_OP
value|".literals"
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".ctors"
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".dtors"
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
value|in_link, in_rdata, in_literals, in_ctors, in_dtors
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
value|void								\ readonly_section ()						\ {								\   if (in_section != in_rdata)				\     {								\       fprintf (asm_out_file, "%s\n", READONLY_SECTION_ASM_OP);	\       in_section = in_rdata;				\     }								\ }								\ void								\ link_section ()							\ {								\   if (in_section != in_link)					\     {								\       fprintf (asm_out_file, "%s\n", LINK_SECTION_ASM_OP); 	\       in_section = in_link;					\     }								\ }                                                               \ void								\ literals_section ()						\ {								\   if (in_section != in_literals)				\     {								\       fprintf (asm_out_file, "%s\n", LITERALS_SECTION_ASM_OP); 	\       in_section = in_literals;					\     }								\ }								\ void								\ ctors_section ()						\ {								\   if (in_section != in_ctors)					\     {								\       fprintf (asm_out_file, "%s\n", CTORS_SECTION_ASM_OP);	\       in_section = in_ctors;					\     }								\ }								\ void								\ dtors_section ()						\ {								\   if (in_section != in_dtors)					\     {								\       fprintf (asm_out_file, "%s\n", DTORS_SECTION_ASM_OP);	\       in_section = in_dtors;					\     }								\ }
end_define

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

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION
end_undef

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
value|readonly_section
end_define

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
value|alpha_write_linkage (FILE);
end_define

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
value|{ ASM_OUTPUT_ALIGN (FILE, 3); ASM_OUTPUT_INTERNAL_LABEL (FILE, PREFIX, NUM); }
end_define

begin_comment
comment|/* This says how to output assembler code to declare an                    uninitialized external linkage data object.  */
end_comment

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|".comm"
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
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
value|do {									\   fprintf ((FILE), "\t%s\t", COMMON_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|NO_MD_PROTOTYPES
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     The trampoline should set the static chain pointer to value placed    into the trampoline and should branch to the specified routine.      Note that $27 has been set to the address of the trampoline, so we can    use it for addressability of the two data items.  Trampolines are always    aligned to FUNCTION_BOUNDARY, which is 64 bits.  */
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
define|\
value|{						\   fprintf (FILE, "\t.quad 0\n");		\   fprintf (FILE, "\t.linkage __tramp\n");	\   fprintf (FILE, "\t.quad 0\n");		\ }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_undef
undef|#
directive|undef
name|TRAMPOLINE_SIZE
end_undef

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|32
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.  */
end_comment

begin_undef
undef|#
directive|undef
name|INITIALIZE_TRAMPOLINE
end_undef

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|TRAMP
parameter_list|,
name|FNADDR
parameter_list|,
name|CXT
parameter_list|)
define|\
value|alpha_initialize_trampoline (TRAMP, FNADDR, CXT, 16, 24, -1)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global constructors.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CONSTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {							\     ctors_section ();					\     fprintf (FILE, "\t.quad "); 			\     assemble_name (FILE, NAME); 			\     fprintf (FILE, "\n");				\   } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global destructors.	*/
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DESTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {							\     dtors_section ();					\     fprintf (FILE, "\t.quad "); 			\     assemble_name (FILE, NAME); 			\     fprintf (FILE, "\n");				\   } while (0)
end_define

begin_define
define|#
directive|define
name|VALID_MACHINE_DECL_ATTRIBUTE
parameter_list|(
name|DECL
parameter_list|,
name|ATTRIBUTES
parameter_list|,
name|NAME
parameter_list|,
name|ARGS
parameter_list|)
define|\
value|(vms_valid_decl_attribute_p (DECL, ATTRIBUTES, NAME, ARGS))
end_define

begin_function_decl
specifier|extern
name|int
name|vms_valid_decl_attribute_p
parameter_list|()
function_decl|;
end_function_decl

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

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
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
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|fprintf (FILE, "\t.align %d\n", LOG);
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SECTION
parameter_list|(
name|FILE
parameter_list|,
name|SECTION
parameter_list|)
define|\
value|(strcmp (SECTION, ".text") == 0)				\      ? text_section ()						\      : named_section (NULL_TREE, SECTION, 0),			\        ASM_OUTPUT_ALIGN (FILE, 0)				\  #define ASM_OUTPUT_SECTION_NAME(FILE,DECL,NAME,RELOC)		\   do								\     {								\       char *flags;					 	\       int ovr = 0;						\       if (DECL&& DECL_MACHINE_ATTRIBUTES (DECL)		\&& lookup_attribute					\ 	      ("overlaid", DECL_MACHINE_ATTRIBUTES (DECL)))	\ 	flags = ",OVR", ovr = 1;				\       else if (strncmp (NAME,".debug", 6) == 0)			\ 	flags = ",NOWRT";					\       else							\ 	flags = "";						\       fputc ('\n', (FILE));					\       fprintf (FILE, ".section\t%s%s\n", NAME, flags);		\       if (ovr)							\         (NAME) = "";						\     } while (0)
end_define

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
value|do {	literals_section();                                             \ 	fprintf ((FILE), "\t");						\ 	assemble_name (FILE, LABEL1);					\ 	fprintf (FILE, " = ");						\ 	assemble_name (FILE, LABEL2);					\ 	fprintf (FILE, "\n");						\   } while (0)
end_define

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

begin_undef
undef|#
directive|undef
name|ASM_FORMAT_PRIVATE_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 12),	\   sprintf ((OUTPUT), "%s___%d", (NAME), (LABELNO)))
end_define

begin_comment
comment|/* ??? VMS uses different linkage.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_MI_THUNK
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-nocpp %{pg}"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{g3:-g3} %{g0:-g0} %{shared:-shared} %{v:-v}"
end_define

begin_comment
comment|/* Define the names of the division and modulus functions.  */
end_comment

begin_define
define|#
directive|define
name|DIVSI3_LIBCALL
value|"OTS$DIV_I"
end_define

begin_define
define|#
directive|define
name|DIVDI3_LIBCALL
value|"OTS$DIV_L"
end_define

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"OTS$DIV_UI"
end_define

begin_define
define|#
directive|define
name|UDIVDI3_LIBCALL
value|"OTS$DIV_UL"
end_define

begin_define
define|#
directive|define
name|MODSI3_LIBCALL
value|"OTS$REM_I"
end_define

begin_define
define|#
directive|define
name|MODDI3_LIBCALL
value|"OTS$REM_L"
end_define

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"OTS$REM_UI"
end_define

begin_define
define|#
directive|define
name|UMODDI3_LIBCALL
value|"OTS$REM_UL"
end_define

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|']'
end_define

begin_define
define|#
directive|define
name|PREFIX
value|"GNU_ROOT:"
end_define

end_unit

