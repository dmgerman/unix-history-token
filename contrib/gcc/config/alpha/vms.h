begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Output variables, constants and external declarations, for GNU compiler.    Copyright (C) 1996, 1997, 1998, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OBJECT_SUFFIX
value|".obj"
end_define

begin_define
define|#
directive|define
name|TARGET_EXECUTABLE_SUFFIX
value|".exe"
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
value|"-D__ALPHA -Dvms -DVMS -D__vms__ -D__VMS__ -Asystem=vms"
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
name|TARGET_ABI_OPEN_VMS
end_undef

begin_define
define|#
directive|define
name|TARGET_ABI_OPEN_VMS
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
comment|/* "long" is 32 bits, but 64 bits for Ada.  */
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

begin_define
define|#
directive|define
name|ADA_LONG_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* Pointer is 32 bits but the hardware has 64-bit addresses, sign extended.  */
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

begin_comment
comment|/* List the order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.     We allocate in the following order:    $f1			(nonsaved floating-point register)    $f10-$f15		(likewise)    $f22-$f30		(likewise)    $f21-$f16		(likewise, but input args)    $f0			(nonsaved, but return value)    $f2-$f9		(saved floating-point registers)    $1			(nonsaved integer registers)    $22-$25		(likewise)    $28			(likewise)    $0			(likewise, but return value)    $21-$16		(likewise, but input args)    $27			(procedure value in OSF, nonsaved in NT)    $2-$8		(saved integer registers)    $9-$14		(saved integer registers)    $26			(return PC)    $15			(frame pointer)    $29			(global pointer)    $30, $31, $f31	(stack pointer and always zero/ap& fp)  */
end_comment

begin_undef
undef|#
directive|undef
name|REG_ALLOC_ORDER
end_undef

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{33,					\    42, 43, 44, 45, 46, 47,		\    54, 55, 56, 57, 58, 59, 60, 61, 62,	\    53, 52, 51, 50, 49, 48,		\    32,					\    34, 35, 36, 37, 38, 39, 40, 41,	\    1,					\    22, 23, 24, 25,			\    28,					\    0,					\    21, 20, 19, 18, 17, 16,		\    27,					\    2, 3, 4, 5, 6, 7, 8,			\    9, 10, 11, 12, 13, 14,		\    26,					\    15,					\    29,					\    30, 31, 63 }
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

begin_comment
comment|/* Define registers used by the epilogue and return instruction.  */
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
value|((REGNO) == 26 || (REGNO) == 29)
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
value|{ if ((FROM) == FRAME_POINTER_REGNUM)					\     (OFFSET) = alpha_sa_size () + alpha_pv_save_size ();		\   else if ((FROM) == ARG_POINTER_REGNUM)				\     (OFFSET) = (ALPHA_ROUND (alpha_sa_size () + alpha_pv_save_size ()	\ 			     + get_frame_size ()			\ 			     + current_function_pretend_args_size)	\ 		- current_function_pretend_args_size);			\   else									\     abort();								\   if ((TO) == STACK_POINTER_REGNUM)					\     (OFFSET) += ALPHA_ROUND (current_function_outgoing_args_size);	\ }
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
name|int
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
comment|/* Perform any needed actions needed for a function that is receiving a    variable number of arguments.      CUM is as for INIT_CUMULATIVE_ARGS.     MODE and TYPE are the mode and type of the current parameter.     PRETEND_SIZE is a variable that should be set to the amount of stack    that must be pushed by the prolog to pretend that our caller pushed    it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.      For VMS, we allocate space for all 6 arg registers plus a count.     However, if NO registers need to be saved, don't allocate any space.    This is not only because we won't need the space, but because AP includes    the current_pretend_args_size and we don't want to mess up any    ap-relative addresses already made.  */
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
value|{ if ((CUM).num_args< 6)				\     {							\       if (! (NO_RTL))					\ 	{						\ 	  emit_move_insn (gen_rtx_REG (DImode, 1),	\ 			  virtual_incoming_args_rtx);	\ 	  emit_insn (gen_arg_home ());			\ 	}						\ 						        \       PRETEND_SIZE = 7 * UNITS_PER_WORD;		\     }							\ }
end_define

begin_comment
comment|/* ABI has stack checking, but it's broken.  */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_CHECK_BUILTIN
end_undef

begin_define
define|#
directive|define
name|STACK_CHECK_BUILTIN
value|0
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

begin_define
define|#
directive|define
name|LINK_SECTION_ASM_OP
value|"\t.link"
end_define

begin_define
define|#
directive|define
name|READONLY_SECTION_ASM_OP
value|"\t.rdata"
end_define

begin_define
define|#
directive|define
name|LITERALS_SECTION_ASM_OP
value|"\t.literals"
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.ctors"
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.dtors"
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
value|in_link, in_rdata, in_literals
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
value|void								\ readonly_section ()						\ {								\   if (in_section != in_rdata)				\     {								\       fprintf (asm_out_file, "%s\n", READONLY_SECTION_ASM_OP);	\       in_section = in_rdata;				\     }								\ }								\ void								\ link_section ()							\ {								\   if (in_section != in_link)					\     {								\       fprintf (asm_out_file, "%s\n", LINK_SECTION_ASM_OP); 	\       in_section = in_link;					\     }								\ }                                                               \ void								\ literals_section ()						\ {								\   if (in_section != in_literals)				\     {								\       fprintf (asm_out_file, "%s\n", LITERALS_SECTION_ASM_OP); 	\       in_section = in_literals;					\     }								\ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|readonly_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|link_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|literals_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|"\t.comm\t"
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
value|do {									\   fprintf ((FILE), "%s", COMMON_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     The trampoline should set the static chain pointer to value placed    into the trampoline and should branch to the specified routine.      Note that $27 has been set to the address of the trampoline, so we can    use it for addressability of the two data items.  */
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
comment|/* The alignment of a trampoline, in bits.  */
end_comment

begin_undef
undef|#
directive|undef
name|TRAMPOLINE_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGNMENT
value|64
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
comment|/* Control how constructors and destructors are emitted.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|vms_asm_out_constructor
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|vms_asm_out_destructor
end_define

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

begin_define
define|#
directive|define
name|VMS_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_undef
undef|#
directive|undef
name|EH_RETURN_HANDLER_RTX
end_undef

begin_define
define|#
directive|define
name|EH_RETURN_HANDLER_RTX
define|\
value|gen_rtx_MEM (Pmode, plus_constant (stack_pointer_rtx, 8))
end_define

begin_define
define|#
directive|define
name|LINK_EH_SPEC
value|"vms-dwarf2eh.o%s "
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_include
include|#
directive|include
file|<libicb.h>
end_include

begin_include
include|#
directive|include
file|<pdscdef.h>
end_include

begin_define
define|#
directive|define
name|MD_FALLBACK_FRAME_STATE_FOR
parameter_list|(
name|CONTEXT
parameter_list|,
name|FS
parameter_list|,
name|SUCCESS
parameter_list|)
define|\
value|do {									\   unsigned long handle;							\   PDSCDEF *pv;								\   INVO_CONTEXT_BLK invo;						\ 									\   memset (&invo, 0, sizeof (INVO_CONTEXT_BLK));				\ 									\   invo.libicb$q_ireg [29] = *((long long *) (CONTEXT)->reg [29]);	\   invo.libicb$q_ireg [30] = (long long) (CONTEXT)->cfa;			\   handle = LIB$GET_INVO_HANDLE (&invo);					\   LIB$GET_INVO_CONTEXT (handle,&invo);					\   pv = (PDSCDEF *) invo.libicb$ph_procedure_descriptor;			\ 									\   if (pv&& ((pv->pdsc$w_flags& 0xf) == PDSC$K_KIND_FP_STACK))		\     {									\       int i, j;								\ 									\       (FS)->cfa_offset = pv->pdsc$l_size;				\       (FS)->cfa_reg = pv->pdsc$w_flags& PDSC$M_BASE_REG_IS_FP ? 29 : 30; \       (FS)->retaddr_column = 26;					\       (FS)->cfa_how = CFA_REG_OFFSET;					\       (FS)->regs.reg[27].loc.offset = -pv->pdsc$l_size;			\       (FS)->regs.reg[27].how = REG_SAVED_OFFSET;			\       (FS)->regs.reg[26].loc.offset					\ 	 = -(pv->pdsc$l_size - pv->pdsc$w_rsa_offset);			\       (FS)->regs.reg[26].how = REG_SAVED_OFFSET;			\ 									\       for (i = 0, j = 0; i< 32; i++)					\ 	if (1<<i& pv->pdsc$l_ireg_mask)				\ 	  {								\ 	    (FS)->regs.reg[i].loc.offset				\ 	      = -(pv->pdsc$l_size - pv->pdsc$w_rsa_offset - 8 * ++j);	\ 	    (FS)->regs.reg[i].how = REG_SAVED_OFFSET;			\ 	  }								\ 									\       goto SUCCESS;							\     }									\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|vms_asm_named_section
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
value|VMS_AND_DWARF2_DEBUG
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

begin_comment
comment|/* The VMS convention is to always provide minimal debug info    for a traceback unless specifically overridden.  Defaulting this here    is a kludge.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|OPTIMIZE
parameter_list|,
name|OPTIMIZE_SIZE
parameter_list|)
define|\
value|{                                                  \    write_symbols = VMS_DEBUG;                      \    debug_info_level = (enum debug_info_level) 1;   \ }
end_define

begin_comment
comment|/* Override traceback debug info on -g0.  */
end_comment

begin_undef
undef|#
directive|undef
name|OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{                                                  \    if (write_symbols == NO_DEBUG)                  \      debug_info_level = (enum debug_info_level) 0; \    override_options ();                            \ }
end_define

begin_comment
comment|/* Link with vms-dwarf2.o if -g (except -g0). This causes the    VMS link to pull all the dwarf2 debug sections together. */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{g:-g vms-dwarf2.o%s} %{g0} %{g1:-g1 vms-dwarf2.o%s} \ %{g2:-g2 vms-dwarf2.o%s} %{g3:-g3 vms-dwarf2.o%s} %{shared} %{v} %{map}"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared:%{mvms-return-codes:vcrt0.o%s} \ %{!mvms-return-codes:pcrt0.o%s}}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-lc"
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
name|NAME__MAIN
value|"__gccmain"
end_define

begin_define
define|#
directive|define
name|SYMBOL__MAIN
value|__gccmain
end_define

begin_comment
comment|/* Specify the list of include file directories.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{					\   { "/gnu_gxx_include", 0, 1, 1 },	\   { "/gnu_cc_include", 0, 0, 0 },	\   { "/gnu/include", 0, 0, 0 },	        \   { 0, 0, 0, 0 }			\ }
end_define

end_unit

