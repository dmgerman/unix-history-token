begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  MIPS version.    Contributed by   A. Lichnewsky,	lich@inria.inria.fr    Changed by Michael Meissner,		meissner@osf.org    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Make Saber happier on obstack.[ch].  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|||
name|defined
argument_list|(
name|mips
argument_list|)
end_if

begin_define
define|#
directive|define
name|__PTR_TO_INT
parameter_list|(
name|P
parameter_list|)
value|((int)(P))
end_define

begin_define
define|#
directive|define
name|__INT_TO_PTR
parameter_list|(
name|P
parameter_list|)
value|((char *)(P))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Standard GCC variables that we reference.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|asm_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|call_used_regs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_omit_frame_pointer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frame_pointer_needed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|language_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|may_call_alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optimize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|save_argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|version_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIPS external variables defined in mips.c.  */
end_comment

begin_comment
comment|/* comparison type */
end_comment

begin_enum
enum|enum
name|cmp_type
block|{
name|CMP_SI
block|,
comment|/* compare integers */
name|CMP_SF
block|,
comment|/* compare single precision floats */
name|CMP_DF
block|,
comment|/* compare double precision floats */
name|CMP_MAX
comment|/* max comparison type */
block|}
enum|;
end_enum

begin_comment
comment|/* types of delay slot */
end_comment

begin_enum
enum|enum
name|delay_type
block|{
name|DELAY_NONE
block|,
comment|/* no delay slot */
name|DELAY_LOAD
block|,
comment|/* load from memory delay */
name|DELAY_HILO
block|,
comment|/* move from/to hi/lo registers */
name|DELAY_FCMP
comment|/* delay after doing c.<xx>.{d,s} */
block|}
enum|;
end_enum

begin_comment
comment|/* Which processor to schedule for.  Since there is no difference between    a R2000 and R3000 in terms of the scheduler, we collapse them into    just an R3000.  The elements of the enumeration must match exactly    the cpu attribute in the mips.md machine description.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_DEFAULT
block|,
name|PROCESSOR_R3000
block|,
name|PROCESSOR_R6000
block|,
name|PROCESSOR_R4000
block|}
enum|;
end_enum

begin_comment
comment|/* Recast the cpu class to be the cpu attribute.  */
end_comment

begin_define
define|#
directive|define
name|mips_cpu_attr
value|((enum attr_cpu)mips_cpu)
end_define

begin_comment
comment|/* Which type of block move to do (whether or not the last store is    split out so it can fill a branch delay slot).  */
end_comment

begin_enum
enum|enum
name|block_move_type
block|{
name|BLOCK_MOVE_NORMAL
block|,
comment|/* generate complete block move */
name|BLOCK_MOVE_NOT_LAST
block|,
comment|/* generate all but last store */
name|BLOCK_MOVE_LAST
comment|/* generate just the last store */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|char
name|mips_reg_names
index|[]
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register names (a0 vs. $4). */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|mips_print_operand_punct
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print_operand punctuation chars */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current function being compiled */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filename current function is in */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_source_filenames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current .file # */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inside_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if inside of a function */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ignore_line_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are to ignore next .loc */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|file_in_function_warning
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* warning given about .file in func */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sdb_label_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block start/end next label # */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_section_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # bytes of data/sdata cutoff */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g_switch_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of the -G xx switch */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g_switch_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whether -G xx was passed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sym_lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sgi next label # for each stmt */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_noreorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set noreorder's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_nomacro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set nomacro's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_noat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set noat's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_volatile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nested .set volatile's  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_branch_likely
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* emit 'l' after br (branch likely) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_dbx_regno
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map register # to debug register # */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|mips_rtx_classify
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* classify an RTX code */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|branch_cmp
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operands for compare */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|cmp_type
name|branch_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what type of branch to use */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|mips_cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which cpu are we scheduling for */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_isa
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* architectural level */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mips_cpu_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for -mcpu=<xxx> */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mips_isa_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for -mips{1,2,3} */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dslots_load_total
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total # load related delay slots */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dslots_load_filled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # filled load delay slots */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dslots_jump_total
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total # jump related delay slots */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dslots_jump_filled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # filled jump delay slots */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dslots_number_nops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of nops needed by previous insn */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_refs
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # 1/2/3 word references */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|mips_load_reg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register to check for load delay */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|mips_load_reg2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2nd reg to check for load delay */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|mips_load_reg3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3rd reg to check for load delay */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|mips_load_reg4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4th reg to check for load delay */
end_comment

begin_comment
comment|/* Functions within mips.c that we reference.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|abort_with_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|arith32_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|arith_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cmp_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cmp2_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|compute_frame_size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|epilogue_reg_mentioned_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_block_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|equality_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fcmp_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|final_prescan_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fpsw_register_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|function_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|function_arg_advance
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|function_arg_partial_nregs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|function_epilogue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|function_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_conditional_branch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|gen_int_relational
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_cumulative_args
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|large_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|md_register_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mips_address_cost
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_asm_file_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_asm_file_start
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mips_const_double_ok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_count_memory_refs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mips_debugger_offset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_declare_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mips_epilogue_delay_slots
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_expand_epilogue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_expand_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mips_fill_delay_slot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mips_move_1word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mips_move_2words
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_output_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mips_output_external
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_output_float
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_output_filename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mips_output_lineno
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_block_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|override_options
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pc_or_label_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_operand_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_options
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_or_0_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|simple_epilogue_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|simple_memory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|small_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uns_arith_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uns_cmp_op
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Recognition functions that return if a condition is true.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|address_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|const_double_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|const_int_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|general_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|immediate_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|memory_address_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|memory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nonimmediate_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nonmemory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|register_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scratch_operand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions to change what output section we are using.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|data_section
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rdata_section
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|readonly_data_section
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sdata_section
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|text_section
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in the rest of the compiler that we reference.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|abort_with_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fatal_io_error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_frame_size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|offsettable_address_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|permalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_mentioned_p
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in the standard library that we reference.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atoi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Stubs for half-pic support if not OSF/1 reference platform.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HALF_PIC_P
end_ifndef

begin_define
define|#
directive|define
name|HALF_PIC_P
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|HALF_PIC_NUMBER_PTRS
value|0
end_define

begin_define
define|#
directive|define
name|HALF_PIC_NUMBER_REFS
value|0
end_define

begin_define
define|#
directive|define
name|HALF_PIC_ENCODE
parameter_list|(
name|DECL
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_DECLARE
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_INIT
parameter_list|()
value|error ("half-pic init called on systems that don't support it.")
end_define

begin_define
define|#
directive|define
name|HALF_PIC_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|HALF_PIC_PTR
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_define
define|#
directive|define
name|HALF_PIC_FINISH
parameter_list|(
name|STREAM
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Switch  Recognition by gcc.c.  Add -G xx support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SWITCH_TAKES_ARG
end_ifdef

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|((CHAR) == 'D' || (CHAR) == 'U' || (CHAR) == 'o'			\    || (CHAR) == 'e' || (CHAR) == 'T' || (CHAR) == 'u'			\    || (CHAR) == 'I' || (CHAR) == 'm'					\    || (CHAR) == 'L' || (CHAR) == 'A' || (CHAR) == 'G')
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.     On the MIPS, it is used to handle -G.  We also use it to set up all    of the tables referenced in the other macros.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|override_options ()
end_define

begin_comment
comment|/* Zero or more C statements that may conditionally modify two    variables `fixed_regs' and `call_used_regs' (both of type `char    []') after they have been initialized from the two preceding    macros.     This is necessary in case the fixed or call-clobbered registers    depend on target flags.     You need not define this macro if it has no work to do.     If the usage of an entire class of registers depends on the target    flags, you may indicate this to GCC by using this macro to modify    `fixed_regs' and `call_used_regs' to 1 for each of the registers in    the classes which should not be used by GCC.  Also define the macro    `REG_CLASS_FROM_LETTER' to return `NO_REGS' if it is called with a    letter for a class that shouldn't be used.     (However, if this class is not included in `GENERAL_REGS' and all    of the insn patterns whose constraints permit this class are    controlled by target switches, then GCC will automatically avoid    using these registers when the target switches are opposed to    them.)  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|do									\   {									\     if (!TARGET_HARD_FLOAT)						\       {									\ 	int regno;							\ 									\ 	for (regno = FP_REG_FIRST; regno<= FP_REG_LAST; regno++)	\ 	  fixed_regs[regno] = call_used_regs[regno] = 1;		\       }									\   }									\ while (0)
end_define

begin_comment
comment|/* Some machines may desire to change what optimizations are    performed for various optimization levels.   This macro, if    defined, is executed once just after the optimization level is    determined and before the remainder of the command options have    been parsed.  Values set in this macro are used as the default    values for the other command line options.     LEVEL is the optimization level specified; 2 if -O2 is    specified, 1 if -O is specified, and 0 if neither is specified.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|{									\   flag_no_function_cse			= TRUE;				\   flag_gnu_linker			= FALSE;			\ 									\   if (LEVEL)								\     {									\       flag_omit_frame_pointer		= TRUE;				\       flag_delayed_branch		= TRUE;				\       flag_thread_jumps			= TRUE;				\       flag_schedule_insns_after_reload	= TRUE;				\     }									\ 									\   if (LEVEL>= 2)							\     {									\       flag_strength_reduce		= TRUE;				\       flag_cse_follow_jumps		= TRUE;				\       flag_expensive_optimizations	= TRUE;				\       flag_rerun_cse_after_loop		= TRUE;				\       flag_schedule_insns		= TRUE;				\     }									\ 									\   if (LEVEL>= 3)							\     {									\       flag_inline_functions		= TRUE;				\     }									\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Complain about missing specs and predefines that should be defined in each    of the target tm files to override the defaults.  This is mostly a place-    holder until I can get each of the files updated [mm].  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OSF_OS
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|DECSTATION
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|SGI_TARGET
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|MIPS_NEWS
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|MIPS_SYSV
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|MIPS_SVR4
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|MIPS_BSD43
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_error
error|#
directive|error
literal|"Define CPP_PREDEFINES in the appropriate tm.h file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_SPEC
end_ifndef

begin_error
error|#
directive|error
literal|"Define CPP_SPEC in the appropriate tm.h file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_error
error|#
directive|error
literal|"Define LINK_SPEC in the appropriate tm.h file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_error
error|#
directive|error
literal|"Define LIB_SPEC in the appropriate tm.h file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_SPEC
end_ifndef

begin_error
error|#
directive|error
literal|"Define STARTFILE_SPEC in the appropriate tm.h file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_TYPE
end_ifndef

begin_error
error|#
directive|error
literal|"Define MACHINE_TYPE in the appropriate tm.h file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tell collect what flags to pass to nm.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_FLAGS
end_ifndef

begin_define
define|#
directive|define
name|NM_FLAGS
value|"-Bp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmips -Dunix -Dhost_mips -DMIPSEB -DR3000 -DSYSTYPE_BSD43 \ -D_mips -D_unix -D_host_mips -D_MIPSEB -D_R3000 -D_SYSTYPE_BSD43"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extra switches sometimes passed to the assembler.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{!mgas: \ 	%{!mrnames: %{!.s:-nocpp} %{.s: %{cpp} %{nocpp}}} \ 	%{pipe: %e-pipe is not supported.} \ 	%{EB} %{!EB:-EB} \ 	%{EL: %e-EL not supported} \ 	%{mips1} %{mips2} %{mips3} \ 	%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3} \ 	%{g} %{g0} %{g1} %{g2} %{g3} %{v} %{K}} \ %{G*}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASM_SPEC */
end_comment

begin_comment
comment|/* Specify to run a post-processor, mips-tfile after the assembler    has run to stuff the mips debug information into the object file.    This is needed because the $#!%^ MIPS assembler provides no way    of specifying such information in the assembly file.  If we are    cross compiling, disable mips-tfile unless the user specifies    -mmips-tfile.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FINAL_SPEC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|ASM_FINAL_SPEC
value|"\ %{!mgas: %{!mno-mips-tfile: \ 	\n mips-tfile %{v*: -v} \ 		%{K: -I %b.o~} \ 		%{!K: %{save-temps: -I %b.o~}} \ 		%{c:%W{o*}%{!o*:-o %b.o}}%{!c:-o %U.o} \ 		%{.s:%i} %{!.s:%g.s}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_define
define|#
directive|define
name|ASM_FINAL_SPEC
value|"\ %{!mgas: %{mmips-tfile: \ 	\n mips-tfile %{v*: -v} \ 		%{K: -I %b.o~} \ 		%{!K: %{save-temps: -I %b.o~}} \ 		%{c:%W{o*}%{!o*:-o %b.o}}%{!c:-o %U.o} \ 		%{.s:%i} %{!.s:%g.s}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASM_FINAL_SPEC */
end_comment

begin_comment
comment|/* Redefinition of libraries used.  Mips doesn't support normal    UNIX style profiling via calling _mcount.  It does offer    profiling that samples the PC, so do what we can... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:-lprof1} %{p:-lprof1} -lc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extra switches sometimes passed to the linker.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %{G*} \ %{!mgas: \ 	%{pipe: %e-pipe is not supported.} \ 	%{EB} %{!EB:-EB} \ 	%{EL: %e-EL not supported} \ 	%{mips1} %{mips2} %{mips3} \ 	%{bestGnum} %{shared} %{non_shared}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINK_SPEC defined */
end_comment

begin_comment
comment|/* Specs for the compiler proper */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CC1_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{O*: %{!mno-gpOPT:%{!mno-gpopt: -mgpopt}}} \ %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \ %{G*} \ %{pic-none:   -mno-half-pic} \ %{pic-lib:    -mhalf-pic} \ %{pic-extern: -mhalf-pic} \ %{pic-calls:  -mhalf-pic} \ %{save-temps: }"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Preprocessor specs */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS -D_LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS -D_LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS -D_LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C -D_LANGUAGE_OBJECTIVE_C} \ %{.S:	-D__LANGUAGE_ASSEMBLY -D_LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{!.S:	-D__LANGUAGE_C -D_LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If defined, this macro is an additional prefix to try after    `STANDARD_EXEC_PREFIX'.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MD_EXEC_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/lib/cmplrs/cc/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MD_STARTFILE_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/lib/cmplrs/cc/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_VERSION
value|"[AL 1.1, MM 33]"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"BSD Mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION_INTERNAL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION_INTERNAL
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|fprintf (STREAM, " %s %s", MIPS_VERSION, MACHINE_TYPE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|TARGET_VERSION_INTERNAL (stderr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* generate info for mips-tfile */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* generate stabs (OSF/rose) */
end_comment

begin_define
define|#
directive|define
name|MIPS_DEBUGGING_INFO
end_define

begin_comment
comment|/* MIPS specific debugging info */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREFERRED_DEBUGGING_TYPE
end_ifndef

begin_comment
comment|/* assume SDB_DEBUGGING_INFO */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|((len> 1&& !strncmp (str, "ggdb", len)) ? DBX_DEBUG : SDB_DEBUG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, turn on GDB extensions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|1
end_define

begin_comment
comment|/* If we are passing smuggling stabs through the MIPS ECOFF object    format, put a comment in front of the .stab<x> operation so    that the MIPS assembler does not choke.  The mips-tfile program    will correctly put the stab into the object file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_STABS_OP
value|((TARGET_GAS) ? ".stabs" : " #.stabs")
end_define

begin_define
define|#
directive|define
name|ASM_STABN_OP
value|((TARGET_GAS) ? ".stabn" : " #.stabn")
end_define

begin_define
define|#
directive|define
name|ASM_STABD_OP
value|((TARGET_GAS) ? ".stabd" : " #.stabd")
end_define

begin_comment
comment|/* Forward references to tags are allowed.  */
end_comment

begin_define
define|#
directive|define
name|SDB_ALLOW_FORWARD_REFERENCES
end_define

begin_comment
comment|/* Unknown tags are also allowed.  */
end_comment

begin_define
define|#
directive|define
name|SDB_ALLOW_UNKNOWN_REFERENCES
end_define

begin_comment
comment|/* On Sun 4, this limit is 2048.  We use 1500 to be safe,    since the length can run past this up to a continuation point.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|1500
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb. */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|mips_dbx_regno[ (REGNO) ]
end_define

begin_comment
comment|/* Overrides for the COFF debug format.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_SCL
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.scl\t%d;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_INT_VAL
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.val\t%d;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_VAL
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fputs ("\t.val\t", asm_out_text_file);		\   output_addr_const (asm_out_text_file, (a));		\   fputc (';', asm_out_text_file);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t#.def\t");		\   ASM_OUTPUT_LABELREF (asm_out_text_file, a); 		\   fputc (';', asm_out_text_file);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_PLAIN_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t#.def\t.%s;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_ENDEF
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.endef\n");		\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_TYPE
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.type\t0x%x;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_SIZE
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.size\t%d;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_DIM
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.dim\t%d;", (a));	\ } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SDB_START_DIM
end_ifndef

begin_define
define|#
directive|define
name|PUT_SDB_START_DIM
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.dim\t");		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SDB_NEXT_DIM
end_ifndef

begin_define
define|#
directive|define
name|PUT_SDB_NEXT_DIM
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "%d,", a);		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SDB_LAST_DIM
end_ifndef

begin_define
define|#
directive|define
name|PUT_SDB_LAST_DIM
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "%d;", a);		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PUT_SDB_TAG
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.tag\t");		\   ASM_OUTPUT_LABELREF (asm_out_text_file, a); 		\   fputc (';', asm_out_text_file);			\ } while (0)
end_define

begin_comment
comment|/* For block start and end, we create labels, so that    later we can figure out where the correct offset is.    The normal .ent/.end serve well enough for functions,    so those are just commented out.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file,				\ 	   "$Lb%d:\n\t#.begin\t$Lb%d\t%d\n",		\ 	   sdb_label_count,				\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file,				\ 	   "$Le%d:\n\t#.bend\t$Le%d\t%d\n",		\ 	   sdb_label_count,				\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_START
parameter_list|(
name|LINE
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_END
parameter_list|(
name|LINE
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_EPILOGUE_END
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDB_GENERATE_FAKE
parameter_list|(
name|BUFFER
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUFFER), ".%dfake", (NUMBER));
end_define

begin_comment
comment|/* Correct the offset of automatic variables and arguments.  Note that    the MIPS debug format wants all automatic variables and arguments    to be in terms of the virtual frame pointer (stack pointer before    any adjustment in the function), while the MIPS 3.0 linker wants    the frame pointer to be the stack pointer after the initial    adjustment.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGGER_AUTO_OFFSET
parameter_list|(
name|X
parameter_list|)
value|mips_debugger_offset (X, 0)
end_define

begin_define
define|#
directive|define
name|DEBUGGER_ARG_OFFSET
parameter_list|(
name|OFFSET
parameter_list|,
name|X
parameter_list|)
value|mips_debugger_offset (X, OFFSET)
end_define

begin_comment
comment|/* Tell collect that the object format is ECOFF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBJECT_FORMAT_ROSE
end_ifndef

begin_define
define|#
directive|define
name|OBJECT_FORMAT_COFF
end_define

begin_comment
comment|/* Object file looks like COFF */
end_comment

begin_define
define|#
directive|define
name|EXTENDED_COFF
end_define

begin_comment
comment|/* ECOFF, not normal coff */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't use the default definitions, because we don't have gld.    Also, we don't want stabs when generating ECOFF output.    Instead we depend on collect to handle these.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CONSTRUCTOR
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_DESTRUCTOR
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
end_define

begin_escape
end_escape

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_comment
comment|/* Macros used in the machine description to test the flags.  */
end_comment

begin_comment
comment|/* Bits for real switches */
end_comment

begin_define
define|#
directive|define
name|MASK_INT64
value|0x00000001
end_define

begin_comment
comment|/* ints are 64 bits */
end_comment

begin_define
define|#
directive|define
name|MASK_LONG64
value|0x00000002
end_define

begin_comment
comment|/* longs are 64 bits */
end_comment

begin_define
define|#
directive|define
name|MASK_LLONG128
value|0x00000004
end_define

begin_comment
comment|/* long longs are 128 bits */
end_comment

begin_define
define|#
directive|define
name|MASK_GPOPT
value|0x00000008
end_define

begin_comment
comment|/* Optimize for global pointer */
end_comment

begin_define
define|#
directive|define
name|MASK_GAS
value|0x00000010
end_define

begin_comment
comment|/* Gas used instead of MIPS as */
end_comment

begin_define
define|#
directive|define
name|MASK_NAME_REGS
value|0x00000020
end_define

begin_comment
comment|/* Use MIPS s/w reg name convention */
end_comment

begin_define
define|#
directive|define
name|MASK_STATS
value|0x00000040
end_define

begin_comment
comment|/* print statistics to stderr */
end_comment

begin_define
define|#
directive|define
name|MASK_MEMCPY
value|0x00000080
end_define

begin_comment
comment|/* call memcpy instead of inline code*/
end_comment

begin_define
define|#
directive|define
name|MASK_SOFT_FLOAT
value|0x00000100
end_define

begin_comment
comment|/* software floating point */
end_comment

begin_define
define|#
directive|define
name|MASK_FLOAT64
value|0x00000200
end_define

begin_comment
comment|/* fp registers are 64 bits */
end_comment

begin_define
define|#
directive|define
name|MASK_ABICALLS
value|0x00000400
end_define

begin_comment
comment|/* emit .abicalls/.cprestore/.cpload */
end_comment

begin_define
define|#
directive|define
name|MASK_HALF_PIC
value|0x00000800
end_define

begin_comment
comment|/* Emit OSF-style pic refs to externs*/
end_comment

begin_define
define|#
directive|define
name|MASK_UNUSED1
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MASK_UNUSED2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MASK_UNUSED3
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MASK_UNUSED4
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MASK_UNUSED5
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MASK_UNUSED6
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MASK_UNUSED7
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MASK_UNUSED8
value|0x00080000
end_define

begin_comment
comment|/* Dummy switches used only in spec's*/
end_comment

begin_define
define|#
directive|define
name|MASK_MIPS_TFILE
value|0x00000000
end_define

begin_comment
comment|/* flag for mips-tfile usage */
end_comment

begin_comment
comment|/* switches not used yet */
end_comment

begin_define
define|#
directive|define
name|MASK_WC8
value|0x00000000
end_define

begin_comment
comment|/* wchar's are  8 bits, not 32 */
end_comment

begin_define
define|#
directive|define
name|MASK_WC16
value|0x00000000
end_define

begin_comment
comment|/* wchar's are 16 bits, not 32 */
end_comment

begin_define
define|#
directive|define
name|MASK_WC32
value|0x00000000
end_define

begin_comment
comment|/* dummy for consistency */
end_comment

begin_comment
comment|/* Debug switches, not documented */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG
value|0x40000000
end_define

begin_comment
comment|/* Eliminate version # in .s file */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_A
value|0x20000000
end_define

begin_comment
comment|/* don't allow<label>($reg) addrs */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_B
value|0x10000000
end_define

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS debug */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_C
value|0x08000000
end_define

begin_comment
comment|/* don't expand seq, etc. */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_D
value|0x04000000
end_define

begin_comment
comment|/* don't do define_split's */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_E
value|0x02000000
end_define

begin_comment
comment|/* function_arg debug */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_F
value|0x01000000
end_define

begin_comment
comment|/* don't try to suppress load nop's */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_G
value|0x00800000
end_define

begin_comment
comment|/* don't support 64 bit arithmetic */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_H
value|0x00400000
end_define

begin_comment
comment|/* allow ints in FP registers */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_I
value|0x00200000
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_J
value|0x00100000
end_define

begin_comment
comment|/* unused */
end_comment

begin_comment
comment|/* r4000 64 bit sizes */
end_comment

begin_define
define|#
directive|define
name|TARGET_INT64
value|(target_flags& MASK_INT64)
end_define

begin_define
define|#
directive|define
name|TARGET_LONG64
value|(target_flags& MASK_LONG64)
end_define

begin_define
define|#
directive|define
name|TARGET_LLONG128
value|(target_flags& MASK_LLONG128)
end_define

begin_define
define|#
directive|define
name|TARGET_FLOAT64
value|(target_flags& MASK_FLOAT64)
end_define

begin_comment
comment|/* Mips vs. GNU assembler */
end_comment

begin_define
define|#
directive|define
name|TARGET_GAS
value|(target_flags& MASK_GAS)
end_define

begin_define
define|#
directive|define
name|TARGET_UNIX_ASM
value|(!TARGET_GAS)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS_AS
value|TARGET_UNIX_ASM
end_define

begin_comment
comment|/* Debug Mode */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEBUG_MODE
value|(target_flags& MASK_DEBUG)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_A_MODE
value|(target_flags& MASK_DEBUG_A)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_B_MODE
value|(target_flags& MASK_DEBUG_B)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_C_MODE
value|(target_flags& MASK_DEBUG_C)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_D_MODE
value|(target_flags& MASK_DEBUG_D)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_E_MODE
value|(target_flags& MASK_DEBUG_E)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_F_MODE
value|(target_flags& MASK_DEBUG_F)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_G_MODE
value|(target_flags& MASK_DEBUG_G)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_H_MODE
value|(target_flags& MASK_DEBUG_H)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_I_MODE
value|(target_flags& MASK_DEBUG_I)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_J_MODE
value|(target_flags& MASK_DEBUG_J)
end_define

begin_comment
comment|/* Reg. Naming in .s ($21 vs. $a0) */
end_comment

begin_define
define|#
directive|define
name|TARGET_NAME_REGS
value|(target_flags& MASK_NAME_REGS)
end_define

begin_comment
comment|/* Optimize for Sdata/Sbss */
end_comment

begin_define
define|#
directive|define
name|TARGET_GP_OPT
value|(target_flags& MASK_GPOPT)
end_define

begin_comment
comment|/* print program statistics */
end_comment

begin_define
define|#
directive|define
name|TARGET_STATS
value|(target_flags& MASK_STATS)
end_define

begin_comment
comment|/* call memcpy instead of inline code */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEMCPY
value|(target_flags& MASK_MEMCPY)
end_define

begin_comment
comment|/* .abicalls, etc from Pyramid V.4 */
end_comment

begin_define
define|#
directive|define
name|TARGET_ABICALLS
value|(target_flags& MASK_ABICALLS)
end_define

begin_comment
comment|/* OSF pic references to externs */
end_comment

begin_define
define|#
directive|define
name|TARGET_HALF_PIC
value|(target_flags& MASK_HALF_PIC)
end_define

begin_comment
comment|/* wchar size */
end_comment

begin_define
define|#
directive|define
name|TARGET_WC8
value|(target_flags& MASK_WC8)
end_define

begin_define
define|#
directive|define
name|TARGET_WC16
value|(target_flags& MASK_WC16)
end_define

begin_define
define|#
directive|define
name|TARGET_WC32
value|((target_flags& (MASK_WC8 | MASK_WC16)) == 0)
end_define

begin_comment
comment|/* software floating point */
end_comment

begin_define
define|#
directive|define
name|TARGET_SOFT_FLOAT
value|(target_flags& MASK_SOFT_FLOAT)
end_define

begin_define
define|#
directive|define
name|TARGET_HARD_FLOAT
value|(! TARGET_SOFT_FLOAT)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{									\   {"int64",		  MASK_INT64 | MASK_LONG64},			\   {"long64",		  MASK_LONG64},					\   {"longlong128",	  MASK_INT64 | MASK_LONG64 | MASK_LLONG128},	\   {"mips-as",		 -MASK_GAS},					\   {"gas",		  MASK_GAS},					\   {"rnames",		  MASK_NAME_REGS},				\   {"no-rnames",		 -MASK_NAME_REGS},				\   {"gpOPT",		  MASK_GPOPT},					\   {"gpopt",		  MASK_GPOPT},					\   {"no-gpOPT",		 -MASK_GPOPT},					\   {"no-gpopt",		 -MASK_GPOPT},					\   {"stats",		  MASK_STATS},					\   {"no-stats",		 -MASK_STATS},					\   {"memcpy",		  MASK_MEMCPY},					\   {"no-memcpy",		 -MASK_MEMCPY},					\   {"wc8",		  MASK_WC8},					\   {"wc16",		  MASK_WC16},					\   {"wc32",		  MASK_WC32},					\   {"mips-tfile",	  MASK_MIPS_TFILE},				\   {"no-mips-tfile",	 -MASK_MIPS_TFILE},				\   {"soft-float",	  MASK_SOFT_FLOAT},				\   {"hard-float",	 -MASK_SOFT_FLOAT},				\   {"fp64",		  MASK_FLOAT64},				\   {"fp32",		 -MASK_FLOAT64},				\   {"abicalls",		  MASK_ABICALLS},				\   {"no-abicalls",	 -MASK_ABICALLS},				\   {"half-pic",		  MASK_HALF_PIC},				\   {"no-half-pic",	 -MASK_HALF_PIC},				\   {"debug",		  MASK_DEBUG},					\   {"debuga",		  MASK_DEBUG_A},				\   {"debugb",		  MASK_DEBUG_B},				\   {"debugc",		  MASK_DEBUG_C},				\   {"debugd",		  MASK_DEBUG_D},				\   {"debuge",		  MASK_DEBUG_E},				\   {"debugf",		  MASK_DEBUG_F},				\   {"debugg",		  MASK_DEBUG_G},				\   {"debugh",		  MASK_DEBUG_H},				\   {"debugi",		  MASK_DEBUG_I},				\   {"debugj",		  MASK_DEBUG_J},				\   {"",			  TARGET_DEFAULT}				\ }
end_define

begin_comment
comment|/* Default target_flags if no switches are specified  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro is similar to `TARGET_SWITCHES' but defines names of    command options that have values.  Its definition is an    initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    fixed part of the option name, and the address of a variable.     The variable, type `char *', is set to the variable part of the    given option if the fixed part matches.  The actual option name    is made by appending `-m' to the specified name.     Here is an example which defines `-mshort-data-NUMBER'.  If the    given option is `-mshort-data-512', the variable `m88k_short_data'    will be set to the string `"512"'.  	extern char *m88k_short_data; 	#define TARGET_OPTIONS { { "short-data-",&m88k_short_data } }  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{									\   { "cpu=",&mips_cpu_string	},				\   { "ips",&mips_isa_string	}				\ }
end_define

begin_comment
comment|/* Macros to decide whether certain features are available or not,    depending on the instruction set architecture level.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_LIKELY_P
parameter_list|()
value|(mips_isa>= 2)
end_define

begin_define
define|#
directive|define
name|HAVE_64BIT_P
parameter_list|()
value|(mips_isa>= 3)
end_define

begin_define
define|#
directive|define
name|HAVE_SQRT_P
parameter_list|()
value|(mips_isa>= 2)
end_define

begin_escape
end_escape

begin_comment
comment|/* Target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields. */
end_comment

begin_comment
comment|/* #define BITS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTES_BIG_ENDIAN
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this if most significant word of a multiword number is the lowest. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WORDS_BIG_ENDIAN
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define macros to easily access the most and least significant words    without a lot of #ifdef's.  */
end_comment

begin_if
if|#
directive|if
name|WORDS_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|MOST_SIGNIFICANT_WORD
value|0
end_define

begin_define
define|#
directive|define
name|LEAST_SIGNIFICANT_WORD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MOST_SIGNIFICANT_WORD
value|1
end_define

begin_define
define|#
directive|define
name|LEAST_SIGNIFICANT_WORD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in an addressable storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 68000, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `int' on the    target machine.  If you don't define this, the default is one    word.  */
end_comment

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `short' on the    target machine.  If you don't define this, the default is half a    word.  (If this would be less than one storage unit, it is    rounded up to one unit.)  */
end_comment

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|16
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `long' on the    target machine.  If you don't define this, the default is one    word.  */
end_comment

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `long long' on the    target machine.  If you don't define this, the default is two    words.  */
end_comment

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `char' on the    target machine.  If you don't define this, the default is one    quarter of a word.  (If this would be less than one storage unit,    it is rounded up to one unit.)  */
end_comment

begin_define
define|#
directive|define
name|CHAR_TYPE_SIZE
value|BITS_PER_UNIT
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `float' on the    target machine.  If you don't define this, the default is one    word.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `double' on the    target machine.  If you don't define this, the default is two    words.  */
end_comment

begin_define
define|#
directive|define
name|DOUBLE_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `long double' on    the target machine.  If you don't define this, the default is two    words.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing pointers in memory.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_BOUNDARY
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_comment
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_comment
comment|/* 8 is observed right on a DECstation and on riscos 4.02.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* There is no point aligning anything to a rounder boundary than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* Biggest alignment any structure field can require in bits.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|64
end_define

begin_comment
comment|/* Set this nonzero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* Define this if you wish to imitate the way many other C compilers    handle alignment of bitfields and the structures that contain    them.     The behavior is that the type written for a bitfield (`int',    `short', or other integer type) imposes an alignment for the    entire structure, as if the structure really did contain an    ordinary field of that type.  In addition, the bitfield is placed    within the structure so that it would fit within such a field,    not crossing a boundary for it.     Thus, on most machines, a bitfield whose type is written as `int'    would not cross a four-byte boundary, and would force four-byte    alignment for the whole structure.  (The alignment used may not    be four bytes; it is controlled by the other alignment    parameters.)     If the macro is defined, its definition should be a C expression;    a nonzero value for the expression enables this behavior.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* If defined, a C expression to compute the alignment given to a    constant that is being placed in memory.  CONSTANT is the constant    and ALIGN is the alignment that the object would ordinarily have.    The value of this macro is used instead of that alignment to align    the object.     If this macro is not defined, then ALIGN is used.     The typical use of this macro is to increase alignment for string    constants to be word aligned so that `strcpy' calls that copy    constants can be done inline.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ALIGNMENT
parameter_list|(
name|EXP
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|((TREE_CODE (EXP) == STRING_CST  || TREE_CODE (EXP) == CONSTRUCTOR)	\&& (ALIGN)< BITS_PER_WORD						\ 	? BITS_PER_WORD							\ 	: (ALIGN))
end_define

begin_comment
comment|/* If defined, a C expression to compute the alignment for a static    variable.  TYPE is the data type, and ALIGN is the alignment that    the object would ordinarily have.  The value of this macro is used    instead of that alignment to align the object.     If this macro is not defined, then ALIGN is used.     One use of this macro is to increase alignment of medium-size    data to make it all fit in fewer cache lines.  Another is to    cause character arrays to be word-aligned so that `strcpy' calls    that copy constants to character arrays can be done inline.  */
end_comment

begin_undef
undef|#
directive|undef
name|DATA_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|TYPE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|((((ALIGN)< BITS_PER_WORD)						\&& (TREE_CODE (TYPE) == ARRAY_TYPE					\ 	|| TREE_CODE (TYPE) == UNION_TYPE				\ 	|| TREE_CODE (TYPE) == RECORD_TYPE)) ? BITS_PER_WORD : (ALIGN))
end_define

begin_comment
comment|/* Define this macro if an argument declared as `char' or `short' in a    prototype should actually be passed as an `int'.  In addition to    avoiding errors in certain cases of mismatch, it also makes for    better code on certain machines. */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
end_define

begin_comment
comment|/* Define this macro if an instruction to load a value narrower    than a word from memory into a register also zero-extends the    value to the whole  register.  */
end_comment

begin_define
define|#
directive|define
name|BYTE_LOADS_ZERO_EXTEND
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     On the Mips, we have 32 integer registers, 32 floating point registers    and the special registers hi, lo, and fp status.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|67
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.     On the MIPS, see conventions, page D-2  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{									\   1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   1, 1, 1								\ }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{									\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,			\   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,			\   1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,			\   1, 1, 1								\ }
end_define

begin_comment
comment|/* Internal macros to classify a register number as to whether it's a    general purpose register, a floating point register, a    multiply/divide register, or a status register.     The macro FP_CALL_REG_P also allows registers $4 and $6 as floating    point registers to pass floating point as per MIPS spec. */
end_comment

begin_define
define|#
directive|define
name|GP_REG_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|GP_REG_LAST
value|31
end_define

begin_define
define|#
directive|define
name|GP_REG_NUM
value|(GP_REG_LAST - GP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|GP_DBX_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|FP_REG_FIRST
value|32
end_define

begin_define
define|#
directive|define
name|FP_REG_LAST
value|63
end_define

begin_define
define|#
directive|define
name|FP_REG_NUM
value|(FP_REG_LAST - FP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|FP_DBX_FIRST
value|((write_symbols == DBX_DEBUG) ? 38 : 32)
end_define

begin_define
define|#
directive|define
name|MD_REG_FIRST
value|64
end_define

begin_define
define|#
directive|define
name|MD_REG_LAST
value|65
end_define

begin_define
define|#
directive|define
name|MD_REG_NUM
value|(MD_REG_LAST - MD_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|ST_REG_FIRST
value|66
end_define

begin_define
define|#
directive|define
name|ST_REG_LAST
value|66
end_define

begin_define
define|#
directive|define
name|ST_REG_NUM
value|(ST_REG_LAST - ST_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|AT_REGNUM
value|(GP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|HI_REGNUM
value|(MD_REG_FIRST + 0)
end_define

begin_define
define|#
directive|define
name|LO_REGNUM
value|(MD_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|FPSW_REGNUM
value|ST_REG_FIRST
end_define

begin_define
define|#
directive|define
name|GP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((unsigned) ((REGNO) - GP_REG_FIRST)< GP_REG_NUM)
end_define

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((unsigned) ((REGNO) - FP_REG_FIRST)< FP_REG_NUM)
end_define

begin_define
define|#
directive|define
name|MD_REG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((unsigned) ((REGNO) - MD_REG_FIRST)< MD_REG_NUM)
end_define

begin_define
define|#
directive|define
name|ST_REG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == ST_REG_FIRST)
end_define

begin_define
define|#
directive|define
name|FP_CALL_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(FP_REG_P (REGNO)						\    || (REGNO) == (4 + GP_REG_FIRST)				\    || (REGNO) == (6 + GP_REG_FIRST))
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the MIPS, all general registers are one word long.  Except on    the R4000 with the FR bit set, the floating point uses register    pairs, with the second register not being allocatable.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(! FP_REG_P (REGNO)							\ 	? ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD) \ 	: (((GET_MODE_SIZE (MODE) + (2*UNITS_PER_WORD) - 1) / (2*UNITS_PER_WORD)) \<< (TARGET_FLOAT64 == 0)))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode    MODE.  Require that DImode and DFmode be in even registers.  For    DImode, this makes some of the insns easier to write, since you    don't have to worry about a DImode value in registers 3& 4,    producing a result in 4& 5.     To make the code simpler HARD_REGNO_MODE_OK now just references an    array built in override_options.  Because machmodes.h is not yet    included before this file is processed, the MODE bound can't be    expressed here.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|mips_hard_regno_mode_ok
index|[]
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|mips_hard_regno_mode_ok[ (int)(MODE) ][ (REGNO) ]
end_define

begin_comment
comment|/* Value is 1 if it is a good idea to tie two pseudo registers    when one has mode MODE1 and one has mode MODE2.    If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,    for any hard reg, then this must be 0 for correct output.  */
end_comment

begin_define
define|#
directive|define
name|MODES_TIEABLE_P
parameter_list|(
name|MODE1
parameter_list|,
name|MODE2
parameter_list|)
define|\
value|((GET_MODE_CLASS (MODE1) == MODE_FLOAT ||				\     GET_MODE_CLASS (MODE1) == MODE_COMPLEX_FLOAT)			\    == (GET_MODE_CLASS (MODE2) == MODE_FLOAT ||				\        GET_MODE_CLASS (MODE2) == MODE_COMPLEX_FLOAT))
end_define

begin_comment
comment|/* MIPS pc is not overloaded on a register.	*/
end_comment

begin_comment
comment|/* #define PC_REGNUM xx				*/
end_comment

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|(GP_REG_FIRST + 29)
end_define

begin_comment
comment|/* Offset from the stack pointer to the first available location.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|0
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|(GP_REG_FIRST + 30)
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|(current_function_calls_alloca)
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|GP_REG_FIRST
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|(GP_REG_FIRST + 2)
end_define

begin_comment
comment|/* If the structure value address is passed in a register, then    `STRUCT_VALUE_REGNUM' should be the number of that register.  */
end_comment

begin_comment
comment|/* #define STRUCT_VALUE_REGNUM (GP_REG_FIRST + 4) */
end_comment

begin_comment
comment|/* If the structure value address is not passed in a register, define    `STRUCT_VALUE' as an expression returning an RTX for the place    where the address is passed.  If it returns 0, the address is    passed as an "invisible" first argument.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|((rtx)0)
end_define

begin_comment
comment|/* Mips registers used in prologue/epilogue code when the stack frame    is larger than 32K bytes.  These registers must come from the    scratch register set, and not used for passing and returning    arguments and any other information used in the calling sequence    (such as pic).  */
end_comment

begin_define
define|#
directive|define
name|MIPS_TEMP1_REGNUM
value|(GP_REG_FIRST + 8)
end_define

begin_define
define|#
directive|define
name|MIPS_TEMP2_REGNUM
value|(GP_REG_FIRST + 9)
end_define

begin_comment
comment|/* Define this macro if it is as good or better to call a constant    function address than to call an address kept in a register.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
value|1
end_define

begin_comment
comment|/* Define this macro if it is as good or better for a function to    call itself with an explicit address than to call an address    kept in a register.  */
end_comment

begin_define
define|#
directive|define
name|NO_RECURSIVE_FUNCTION_CSE
value|1
end_define

begin_comment
comment|/* The register number of the register used to address a table of    static data addresses in memory.  In some cases this register is    defined by a processor's "application binary interface" (ABI).     When this macro is defined, RTL is generated for this register    once, as with the stack pointer and frame pointer registers.  If    this macro is not defined, it is up to the machine-dependent    files to allocate such a register (if necessary).  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|(GP_REG_FIRST + 28)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
comment|/* no registers in set */
name|GR_REGS
block|,
comment|/* integer registers */
name|FP_REGS
block|,
comment|/* floating point registers */
name|HI_REG
block|,
comment|/* hi register */
name|LO_REG
block|,
comment|/* lo register */
name|MD_REGS
block|,
comment|/* multiply/divide registers (hi/lo) */
name|ST_REGS
block|,
comment|/* status registers (fp status) */
name|ALL_REGS
block|,
comment|/* all registers */
name|LIM_REG_CLASSES
comment|/* max value + 1 */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|(int) LIM_REG_CLASSES
end_define

begin_define
define|#
directive|define
name|GENERAL_REGS
value|GR_REGS
end_define

begin_comment
comment|/* An initializer containing the names of the register classes as C    string constants.  These names are used in writing some of the    debugging dumps.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{									\   "NO_REGS",								\   "GR_REGS",								\   "FP_REGS",								\   "HI_REG",								\   "LO_REG",								\   "MD_REGS",								\   "ST_REGS",								\   "ALL_REGS"								\ }
end_define

begin_comment
comment|/* An initializer containing the contents of the register classes,    as integers which are bit masks.  The Nth integer specifies the    contents of class N.  The way the integer MASK is interpreted is    that register R is in the class if `MASK& (1<< R)' is 1.     When the machine has more than 32 registers, an integer does not    suffice.  Then the integers are replaced by sub-initializers,    braced groupings containing several integers.  Each    sub-initializer must be suitable as an initializer for the type    `HARD_REG_SET' which is defined in `hard-reg-set.h'.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{									\   { 0x00000000, 0x00000000, 0x00000000 },
comment|/* no registers */
value|\   { 0xffffffff, 0x00000000, 0x00000000 },
comment|/* integer registers */
value|\   { 0x00000000, 0xffffffff, 0x00000000 },
comment|/* floating registers*/
value|\   { 0x00000000, 0x00000000, 0x00000001 },
comment|/* hi register */
value|\   { 0x00000000, 0x00000000, 0x00000002 },
comment|/* lo register */
value|\   { 0x00000000, 0x00000000, 0x00000003 },
comment|/* mul/div registers */
value|\   { 0x00000000, 0x00000000, 0x00000004 },
comment|/* status registers */
value|\   { 0xffffffff, 0xffffffff, 0x00000007 }
comment|/* all registers */
value|\ }
end_define

begin_comment
comment|/* A C expression whose value is a register class containing hard    register REGNO.  In general there is more that one such class;    choose a class which is "minimal", meaning that no smaller class    also contains the register.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|mips_regno_to_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|mips_regno_to_class[ (REGNO) ]
end_define

begin_comment
comment|/* A macro whose definition is the name of the class to which a    valid base register must belong.  A base register is one used in    an address which is the register value plus a displacement.  */
end_comment

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|GR_REGS
end_define

begin_comment
comment|/* A macro whose definition is the name of the class to which a    valid index register must belong.  An index register is one used    in an address where its value is either multiplied by a scale    factor or added to another register (as well as added to a    displacement).  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|GR_REGS
end_define

begin_comment
comment|/* REGISTER AND CONSTANT CLASSES */
end_comment

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine    description.     DEFINED REGISTER CLASSES:     'd'  General (aka integer) registers    'f'	Floating point registers    'h'	Hi register    'l'	Lo register    'x'	Multiply/divide registers    'z'	FP Status register */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|mips_char_to_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
value|mips_char_to_class[ (C) ]
end_define

begin_comment
comment|/* The letters I, J, K, L, M, N, O, and P in a register constraint    string can be used to stand for particular ranges of immediate    operands.  This macro defines what the ranges are.  C is the    letter, and VALUE is a constant value.  Return 1 if VALUE is    in the range specified by C.  */
end_comment

begin_comment
comment|/* For MIPS:     `I'	is used for the range of constants an arithmetic insn can 	actually contain (16 bits signed integers).     `J'	is used for the range which is just zero (ie, $r0).     `K'	is used for the range of constants a logical insn can actually 	contain (16 bit zero-extended integers).     `L'	is used for the range of constants that be loaded with lui 	(ie, the bottom 16 bits are zero).     `M'	is used for the range of constants that take two words to load 	(ie, not matched by `I', `K', and `L').     `N'	is used for negative 16 bit constants.     `O'	is an exact power of 2 (not yet used in the md file).     `P'	is used for positive 16 bit constants.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_INT
parameter_list|(
name|X
parameter_list|)
value|((unsigned) (INTVAL (X) + 0x8000)< 0x10000)
end_define

begin_define
define|#
directive|define
name|SMALL_INT_UNSIGNED
parameter_list|(
name|X
parameter_list|)
value|((unsigned) (INTVAL (X))< 0x10000)
end_define

begin_define
define|#
directive|define
name|CONST_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'I' ? ((unsigned) ((VALUE) + 0x8000)< 0x10000)		\    : (C) == 'J' ? ((VALUE) == 0)					\    : (C) == 'K' ? ((unsigned) (VALUE)< 0x10000)			\    : (C) == 'L' ? (((VALUE)& 0xffff0000) == (VALUE))			\    : (C) == 'M' ? ((((VALUE)& ~0x0000ffff) != 0)			\&& (((VALUE)& ~0x0000ffff) != ~0x0000ffff)		\&& ((VALUE)& 0x0000ffff) != 0)			\    : (C) == 'N' ? (((VALUE)& ~0x0000ffff) == ~0x0000ffff)		\    : (C) == 'O' ? (exact_log2 (VALUE)>= 0)				\    : (C) == 'P' ? ((VALUE) != 0&& (((VALUE)& ~0x0000ffff) == 0))	\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.  */
end_comment

begin_comment
comment|/* For Mips    'G'	: Floating point 0 */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'G'								\&& CONST_DOUBLE_HIGH (VALUE) == 0					\&& CONST_DOUBLE_LOW (VALUE) == 0)
end_define

begin_comment
comment|/* Letters in the range `Q' through `U' may be defined in a    machine-dependent fashion to stand for arbitrary operand types.     The machine description macro `EXTRA_CONSTRAINT' is passed the    operand as its first argument and the constraint letter as its    second operand.     `Q'	is for memory references which take more than 1 instruction.    `R'	is for memory references which take 1 word for the instruction.    `S'	is for references to extern items which are PIC for OSF/rose.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT
parameter_list|(
name|OP
parameter_list|,
name|CODE
parameter_list|)
define|\
value|((GET_CODE (OP) != MEM) ? FALSE					\    : ((CODE) == 'Q')	  ? !simple_memory_operand (OP, GET_MODE (OP))	\    : ((CODE) == 'R')	  ? simple_memory_operand (OP, GET_MODE (OP))	\    : ((CODE) == 'S')	  ? (HALF_PIC_P ()&& CONSTANT_P (OP)		\&& HALF_PIC_ADDRESS_P (OP))		\    : FALSE)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|((GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT				\      || GET_MODE_CLASS (GET_MODE (X)) == MODE_COMPLEX_FLOAT)		\ 	    ? (TARGET_SOFT_FLOAT ? GR_REGS : FP_REGS)			\ 	    : ((GET_MODE (X) == VOIDmode)				\ 		? GR_REGS						\ 		: CLASS))
end_define

begin_comment
comment|/* Certain machines have the property that some registers cannot be    copied to some other registers without using memory.  Define this    macro on those machines to be a C expression that is non-zero if    objects of mode MODE in registers of CLASS1 can only be copied to    registers of class CLASS2 by storing a register of CLASS1 into    memory and loading that memory location into a register of CLASS2.     Do not define this macro if its value would always be zero.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_MEMORY_NEEDED
parameter_list|(
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(!TARGET_DEBUG_H_MODE							\&& GET_MODE_CLASS (MODE) == MODE_INT					\&& ((CLASS1 == FP_REGS&& CLASS2 == GR_REGS)				\        || (CLASS1 == GR_REGS&& CLASS2 == FP_REGS)))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_MAX_NREGS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((((MODE) == DFmode) || ((MODE) == SFmode)) ? 2			\   : ((MODE) == VOIDmode)? ((CLASS) == FP_REGS ? 2 : 1)			\   : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* If defined, this is a C expression whose value should be    nonzero if the insn INSN has the effect of mysteriously    clobbering the contents of hard register number REGNO.  By    "mysterious" we mean that the insn's RTL expression doesn't    describe such an effect.     If this macro is not defined, it means that no insn clobbers    registers mysteriously.  This is the usual situation; all else    being equal, it is best for the RTL expression to show all the    activity.  */
end_comment

begin_comment
comment|/* #define INSN_CLOBBERS_REGNO_P(INSN, REGNO) */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Define this if pushing a word on the stack    makes the stack pointer a smaller address.  */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_comment
comment|/* #define FRAME_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|current_function_outgoing_args_size
end_define

begin_comment
comment|/* Offset from the stack pointer register to an item dynamically    allocated on the stack, e.g., by `alloca'.     The default value for this macro is `STACK_POINTER_OFFSET' plus the    length of the outgoing arguments.  The default is correct for most    machines.  See `function.c' for details.     The MIPS ABI states that functions which dynamically allocate the    stack must not have 0 for STACK_DYNAMIC_OFFSET, since it looks like    we are trying to create a second frame pointer to the function, so    allocate some stack space to make it happy.     However, the linker currently complains about linking any code that    dynamically allocates stack space, and there seems to be a bug in    STACK_DYNAMIC_OFFSET, so don't define this right now.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|STACK_DYNAMIC_OFFSET
parameter_list|(
name|FUNDECL
parameter_list|)
define|\
value|((current_function_outgoing_args_size == 0&& current_function_calls_alloca) \ 	? 4*UNITS_PER_WORD						\ 	: current_function_outgoing_args_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Structure to be filled in by compute_frame_size with register    save masks, and offsets for the current function.  */
end_comment

begin_struct
struct|struct
name|mips_frame_info
block|{
name|long
name|total_size
decl_stmt|;
comment|/* # bytes that the entire frame takes up */
name|long
name|var_size
decl_stmt|;
comment|/* # bytes that variables take up */
name|long
name|args_size
decl_stmt|;
comment|/* # bytes that outgoing arguments take up */
name|long
name|extra_size
decl_stmt|;
comment|/* # bytes of extra gunk */
name|int
name|gp_reg_size
decl_stmt|;
comment|/* # bytes needed to store gp regs */
name|int
name|fp_reg_size
decl_stmt|;
comment|/* # bytes needed to store fp regs */
name|long
name|mask
decl_stmt|;
comment|/* mask of saved gp registers */
name|long
name|fmask
decl_stmt|;
comment|/* mask of saved fp registers */
name|long
name|gp_save_offset
decl_stmt|;
comment|/* offset from vfp to store gp registers */
name|long
name|fp_save_offset
decl_stmt|;
comment|/* offset from vfp to store fp registers */
name|long
name|gp_sp_offset
decl_stmt|;
comment|/* offset from new sp to store gp registers */
name|long
name|fp_sp_offset
decl_stmt|;
comment|/* offset from new sp to store fp registers */
name|int
name|initialized
decl_stmt|;
comment|/* != 0 if frame size already calculated */
name|int
name|num_gp
decl_stmt|;
comment|/* number of gp registers saved */
name|int
name|num_fp
decl_stmt|;
comment|/* number of fp registers saved */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mips_frame_info
name|current_frame_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Store in the variable DEPTH the initial difference between the    frame pointer reg contents and the stack pointer reg contents,    as of the start of the function body.  This depends on the layout    of the fixed parts of the stack frame and on how registers are saved.  */
end_comment

begin_comment
comment|/* #define INITIAL_FRAME_POINTER_OFFSET(VAR)				\     ((VAR) = compute_frame_size (get_frame_size ())) */
end_comment

begin_comment
comment|/* If defined, this macro specifies a table of register pairs used to    eliminate unneeded registers that point into the stack frame.  If    it is not defined, the only elimination attempted by the compiler    is to replace references to the frame pointer with references to    the stack pointer.     The definition of this macro is a list of structure    initializations, each of which specifies an original and    replacement register.     On some machines, the position of the argument pointer is not    known until the compilation is completed.  In such a case, a    separate hard register must be used for the argument pointer.     This register can be eliminated by replacing it with either the    frame pointer or the argument pointer, depending on whether or not    the frame pointer has been eliminated.     In this case, you might specify:         #define ELIMINABLE_REGS  \         {{ARG_POINTER_REGNUM, STACK_POINTER_REGNUM}, \          {ARG_POINTER_REGNUM, FRAME_POINTER_REGNUM}, \          {FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM}}     Note that the elimination of the argument pointer with the stack    pointer is specified first since that is the preferred elimination.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ ARG_POINTER_REGNUM,   STACK_POINTER_REGNUM},				\  { ARG_POINTER_REGNUM,   FRAME_POINTER_REGNUM},				\  { FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM}}
end_define

begin_comment
comment|/* A C expression that returns non-zero if the compiler is allowed to    try to replace register number FROM-REG with register number    TO-REG.  This macro need only be defined if `ELIMINABLE_REGS' is    defined, and will usually be the constant 1, since most of the    cases preventing register elimination are things that the compiler    already knows about.  */
end_comment

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
value|(!frame_pointer_needed						\    || ((FROM) == ARG_POINTER_REGNUM&& (TO) == FRAME_POINTER_REGNUM))
end_define

begin_comment
comment|/* This macro is similar to `INITIAL_FRAME_POINTER_OFFSET'.  It    specifies the initial difference between the specified pair of    registers.  This macro must be defined if `ELIMINABLE_REGS' is    defined.  */
end_comment

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
value|{  compute_frame_size (get_frame_size ());				 \   if ((FROM) == FRAME_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM)	 \     (OFFSET) = 0;							 \   else if ((FROM) == ARG_POINTER_REGNUM&& (TO) == FRAME_POINTER_REGNUM) \     (OFFSET) = current_frame_info.total_size;				 \   else if ((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM) \     (OFFSET) = current_frame_info.total_size;				 \   else									 \     abort ();								 \ }
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On the vax, sp@- in a byte insn really pushes a word.  */
end_comment

begin_comment
comment|/* #define PUSH_ROUNDING(BYTES) 0 */
end_comment

begin_comment
comment|/* If defined, the maximum amount of space required for outgoing    arguments will be computed and placed into the variable    `current_function_outgoing_args_size'.  No space will be pushed    onto the stack for each call; instead, the function prologue    should increase the stack frame size by this amount.     It is not proper to define both `PUSH_ROUNDING' and    `ACCUMULATE_OUTGOING_ARGS'.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
end_define

begin_comment
comment|/* Offset from the argument pointer register to the first argument's    address.  On some machines it may depend on the data type of the    function.     If `ARGS_GROW_DOWNWARD', this is the offset to the location above    the first argument's address.     On the MIPS, we must skip the first argument position if we are    returning a structure or a union, to account for it's address being    passed in $4.  However, at the current time, this produces a compiler    that can't bootstrap, so comment it out for now.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
define|\
value|(FNDECL != 0								\&& TREE_TYPE (FNDECL) != 0						\&& TREE_TYPE (TREE_TYPE (FNDECL)) != 0				\&& (TREE_CODE (TREE_TYPE (TREE_TYPE (FNDECL))) == RECORD_TYPE	\        || TREE_CODE (TREE_TYPE (TREE_TYPE (FNDECL))) == UNION_TYPE)	\ 		? UNITS_PER_WORD					\ 		: 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* When a parameter is passed in a register, stack space is still    allocated for it.  For the MIPS, stack space must be allocated, cf    Asm Lang Prog Guide page 7-8.     BEWARE that some space is also allocated for non existing arguments    in register. In case an argument list is of form GF used registers    are a0 (a2,a3), but we should push over a1...  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|FNDECL
parameter_list|)
value|((4*UNITS_PER_WORD) - FIRST_PARM_OFFSET (FNDECL))
end_define

begin_comment
comment|/* Define this if it is the responsibility of the caller to    allocate the area reserved for arguments passed in registers.     If `ACCUMULATE_OUTGOING_ARGS' is also defined, the only effect    of this macro is to determine whether the space is included in     `current_function_outgoing_args_size'.  */
end_comment

begin_define
define|#
directive|define
name|OUTGOING_REG_PARM_STACK_SPACE
end_define

begin_comment
comment|/* Align stack frames on 64 bits (Double Word ).  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|64
end_define

begin_comment
comment|/* Make sure 16 bytes are always allocated on the stack.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_ARGS_ADJUST
end_ifndef

begin_define
define|#
directive|define
name|STACK_ARGS_ADJUST
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|{									\   if (SIZE.constant< 16)						\     SIZE.constant = 16;							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* A C expression that should indicate the number of bytes of its    own arguments that a function function pops on returning, or 0    if the function pops no arguments and the caller must therefore    pop them all after the function returns.     FUNTYPE is a C variable whose value is a tree node that    describes the function in question.  Normally it is a node of    type `FUNCTION_TYPE' that describes the data type of the function.    From this it is possible to obtain the data types of the value    and arguments (if known).     When a call to a library function is being considered, FUNTYPE    will contain an identifier node for the library function.  Thus,    if you need to distinguish among various library functions, you    can do so by their names.  Note that "library function" in this    context means a function used to perform arithmetic, whose name    is known specially in the compiler and was not mentioned in the    C code being compiled.     STACK-SIZE is the number of bytes of arguments passed on the    stack.  If a variable number of bytes is passed, it is zero, and    argument popping will always be the responsibility of the    calling function.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
value|0
end_define

begin_comment
comment|/* Symbolic macros for the registers used to return integer and floating    point values.  */
end_comment

begin_define
define|#
directive|define
name|GP_RETURN
value|(GP_REG_FIRST + 2)
end_define

begin_define
define|#
directive|define
name|FP_RETURN
value|((TARGET_SOFT_FLOAT) ? GP_RETURN : (FP_REG_FIRST + 0))
end_define

begin_comment
comment|/* Symbolic macros for the first/last argument registers.  */
end_comment

begin_define
define|#
directive|define
name|GP_ARG_FIRST
value|(GP_REG_FIRST + 4)
end_define

begin_define
define|#
directive|define
name|GP_ARG_LAST
value|(GP_REG_FIRST + 7)
end_define

begin_define
define|#
directive|define
name|FP_ARG_FIRST
value|(FP_REG_FIRST + 12)
end_define

begin_define
define|#
directive|define
name|FP_ARG_LAST
value|(FP_REG_FIRST + 15)
end_define

begin_define
define|#
directive|define
name|MAX_ARGS_IN_REGISTERS
value|4
end_define

begin_comment
comment|/* Define how to find the value returned by a library function    assuming the value has mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|gen_rtx (REG, MODE,							\ 	   (GET_MODE_CLASS (MODE) == MODE_FLOAT)			\ 		? FP_RETURN						\ 		: GP_RETURN)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
value|LIBCALL_VALUE (TYPE_MODE (VALTYPE))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the MIPS, R2 R3 and F0 F2 are the only register thus used.    Currently, R2 and F0 are only implemented  here (C has no complex type)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == GP_RETURN || (N) == FP_RETURN)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|(((N)>= GP_ARG_FIRST&& (N)<= GP_ARG_LAST)   \ 				 || ((N)>= FP_ARG_FIRST&& (N)<= FP_ARG_LAST \&& (0 == (N) % 2)))
end_define

begin_comment
comment|/* A C expression which can inhibit the returning of certain function    values in registers, based on the type of value.  A nonzero value says    to return the function value in memory, just as large structures are    always returned.  Here TYPE will be a C expression of type    `tree', representing the data type of the value.     Note that values of mode `BLKmode' are returned in memory    regardless of this macro.  Also, the option `-fpcc-struct-return'    takes effect regardless of this macro.  On most systems, it is    possible to leave the macro undefined; this causes a default    definition to be used, whose value is the constant 0.     GCC normally converts 1 byte structures into chars, 2 byte    structs into shorts, and 4 byte structs into ints, and returns    them this way.  Defining the following macro overrides this,    to give us MIPS cc compatibility.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|((TREE_CODE (TYPE) == RECORD_TYPE) || (TREE_CODE (TYPE) == UNION_TYPE))
end_define

begin_escape
end_escape

begin_comment
comment|/* A code distinguishing the floating point format of the target    machine.  There are three defined values: IEEE_FLOAT_FORMAT,    VAX_FLOAT_FORMAT, and UNKNOWN_FLOAT_FORMAT.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLOAT_FORMAT
value|IEEE_FLOAT_FORMAT
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mips_args
block|{
name|int
name|gp_reg_found
decl_stmt|;
comment|/* whether a gp register was found yet */
name|int
name|arg_number
decl_stmt|;
comment|/* argument number */
name|int
name|arg_words
decl_stmt|;
comment|/* # total words the arguments take */
name|int
name|num_adjusts
decl_stmt|;
comment|/* number of adjustments made */
comment|/* Adjustments made to args pass in regs.  */
name|struct
name|rtx_def
modifier|*
name|adjust
index|[
name|MAX_ARGS_IN_REGISTERS
index|]
decl_stmt|;
block|}
name|CUMULATIVE_ARGS
typedef|;
end_typedef

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.  */
end_comment

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
parameter_list|)
define|\
value|init_cumulative_args (&CUM, FNTYPE, LIBNAME)
end_define

begin_comment
unit|\
comment|/* Update the data in CUM to advance over an argument    of mode MODE and data type TYPE.    (TYPE is null for libcalls where that information may not be available.)  */
end_comment

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
value|function_arg_advance (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
end_comment

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
value|function_arg(&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    For args passed entirely in registers or entirely in memory, zero. */
end_comment

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
value|function_arg_partial_nregs (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* If defined, a C expression that gives the alignment boundary, in    bits, of an argument with the specified mode and type.  If it is    not defined,  `PARM_BOUNDARY' is used for all arguments.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_BOUNDARY
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(((TYPE) != 0)							\ 	? ((TYPE_ALIGN(TYPE)<= PARM_BOUNDARY)				\ 		? PARM_BOUNDARY						\ 		: TYPE_ALIGN(TYPE))					\ 	: ((GET_MODE_ALIGNMENT(MODE)<= PARM_BOUNDARY)			\ 		? PARM_BOUNDARY						\ 		: GET_MODE_ALIGNMENT(MODE)))
end_define

begin_escape
end_escape

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROLOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
value|function_prologue(FILE, SIZE)
end_define

begin_comment
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
value|function_epilogue(FILE, SIZE)
end_define

begin_comment
comment|/* Define the number of delay slots needed for the function epilogue.     On the mips, we need a slot if either no stack has been allocated,    or the only register saved is the return register.  */
end_comment

begin_define
define|#
directive|define
name|DELAY_SLOTS_FOR_EPILOGUE
value|mips_epilogue_delay_slots ()
end_define

begin_comment
comment|/* Define whether INSN can be placed in delay slot N for the epilogue.    No references to the stack must be made, since on the MIPS, the    delay slot is done after the stack has been cleaned up.  */
end_comment

begin_define
define|#
directive|define
name|ELIGIBLE_FOR_EPILOGUE_DELAY
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
define|\
value|(get_attr_dslot (INSN) == DSLOT_NO					\&& get_attr_length (INSN) == 1					\&& ! epilogue_reg_mentioned_p (PATTERN (INSN)))
end_define

begin_comment
comment|/* Tell prologue and epilogue if register REGNO should be saved / restored.  */
end_comment

begin_define
define|#
directive|define
name|MUST_SAVE_REGISTER
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regs_ever_live[regno]&& !call_used_regs[regno])		\   || (regno == FRAME_POINTER_REGNUM&& frame_pointer_needed)	\   || (regno == (GP_REG_FIRST + 31)&& regs_ever_live[GP_REG_FIRST + 31]))
end_define

begin_comment
comment|/* ALIGN FRAMES on double word boundaries */
end_comment

begin_define
define|#
directive|define
name|MIPS_STACK_ALIGN
parameter_list|(
name|LOC
parameter_list|)
value|(((LOC)+7)& ~7)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{									\   fprintf (FILE, "\t.set\tnoreorder\n");				\   fprintf (FILE, "\t.set\tnoat\n");					\   fprintf (FILE, "\tmove\t%s,%s\t\t# save current return address\n",	\ 	   reg_names[GP_REG_FIRST + 1], reg_names[GP_REG_FIRST + 31]);	\   fprintf (FILE, "\tjal\t_mcount\n");					\   fprintf (FILE, "\tsubu\t%s,%s,8\t\t# _mcount pops 2 words from  stack\n", \ 	   reg_names[STACK_POINTER_REGNUM],				\ 	   reg_names[STACK_POINTER_REGNUM]);				\   fprintf (FILE, "\t.set\treorder\n");					\   fprintf (FILE, "\t.set\tat\n");					\ }
end_define

begin_comment
comment|/* Define this macro if the code for function profiling should come    before the function prologue.  Normally, the profiling code comes    after.  */
end_comment

begin_comment
comment|/* #define PROFILE_BEFORE_PROLOGUE */
end_comment

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* A C statement to output, on the stream FILE, assembler code for a    block of data that contains the constant parts of a trampoline.     This code should not include a label--the label is taken care of    automatically.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|{									 \   fprintf (STREAM, "\t.word\t0x03e00821\t\t# move   $1,$31\n");		\   fprintf (STREAM, "\t.word\t0x04110001\t\t# bgezal $0,.+8\n");		\   fprintf (STREAM, "\t.word\t0x00000000\t\t# nop\n");			\   fprintf (STREAM, "\t.word\t0x8fe30010\t\t# lw     $3,16($31)\n");	\   fprintf (STREAM, "\t.word\t0x8fe20014\t\t# lw     $2,20($31)\n");	\   fprintf (STREAM, "\t.word\t0x00600008\t\t# jr     $3\n");		\   fprintf (STREAM, "\t.word\t0x0020f821\t\t# move   $31,$1\n");		\   fprintf (STREAM, "\t.word\t0x00000000\t\t#<function address>\n");	\   fprintf (STREAM, "\t.word\t0x00000000\t\t#<static chain value>\n");	\ }
end_define

begin_comment
comment|/* A C expression for the size in bytes of the trampoline, as an    integer.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|(9*4)
end_define

begin_comment
comment|/* Alignment required for trampolines, in bits.     If you don't define this macro, the value of `BIGGEST_ALIGNMENT'    is used for aligning trampolines.  */
end_comment

begin_comment
comment|/* #define TRAMPOLINE_ALIGNMENT 32 */
end_comment

begin_comment
comment|/* A C statement to initialize the variable parts of a trampoline.     ADDR is an RTX for the address of the trampoline; FNADDR is an    RTX for the address of the nested function; STATIC_CHAIN is an    RTX for the static chain value that should be passed to the    function when it is called.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|ADDR
parameter_list|,
name|FUNC
parameter_list|,
name|CHAIN
parameter_list|)
define|\
value|{									    \   rtx addr = ADDR;							    \   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (addr, 28)), FUNC);   \   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (addr, 32)), CHAIN);  \ 									    \
comment|/* Attempt to make stack executable */
value|\   emit_library_call (gen_rtx (SYMBOL_REF, Pmode, "__enable_execute_stack"), \ 		     0, VOIDmode, 1, addr, Pmode);			    \ }
end_define

begin_comment
comment|/* Attempt to turn on access permissions for the stack.  */
end_comment

begin_define
define|#
directive|define
name|TRANSFER_FROM_TRAMPOLINE
define|\ 									\
value|void									\ __enable_execute_stack (addr)						\      char *addr;							\ {									\   int size = getpagesize ();						\   int mask = ~(size-1);							\   char *page = (char *) (((int) addr)& mask);				\   char *end  = (char *) ((((int) (addr + TRAMPOLINE_SIZE))& mask) + size); \ 									\
comment|/* 7 is PROT_READ | PROT_WRITE | PROT_EXEC */
value|\   if (mprotect (page, end - page, 7)< 0)				\     perror ("mprotect of trampoline code");				\ 									\
comment|/*									\   if (cacheflush (addr, TRAMPOLINE_SIZE, 1)< 0)			\     perror ("cacheflush of trampoline code");				\  */
value|\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_comment
comment|/* #define HAVE_POST_INCREMENT */
end_comment

begin_comment
comment|/* #define HAVE_POST_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_INCREMENT */
end_comment

begin_comment
comment|/* These assume that REGNO is a hard or pseudo reg number.    They give nonzero only if REGNO is a hard reg of the suitable class    or a pseudo reg currently allocated to a suitable hard reg.    These definitions are NOT overridden anywhere.  */
end_comment

begin_define
define|#
directive|define
name|GP_REG_OR_PSEUDO_STRICT_P
parameter_list|(
name|regno
parameter_list|)
define|\
value|GP_REG_P((regno< FIRST_PSEUDO_REGISTER) ? regno : reg_renumber[regno])
end_define

begin_define
define|#
directive|define
name|GP_REG_OR_PSEUDO_NONSTRICT_P
parameter_list|(
name|regno
parameter_list|)
define|\
value|(((regno)>= FIRST_PSEUDO_REGISTER) || (GP_REG_P (regno)))
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|regno
parameter_list|)
value|GP_REG_OR_PSEUDO_STRICT_P (regno)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|regno
parameter_list|)
value|GP_REG_OR_PSEUDO_STRICT_P (regno)
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects them all.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Some source files that are used after register allocation    need to be strict.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_define
define|#
directive|define
name|REG_OK_STRICT_P
value|0
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|GP_REG_OR_PSEUDO_NONSTRICT_P (REGNO (X))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|GP_REG_OR_PSEUDO_NONSTRICT_P (REGNO (X))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_OK_STRICT_P
value|1
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_BASE_P  (REGNO (X))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|1
end_define

begin_comment
comment|/* A C compound statement with a conditional `goto LABEL;' executed    if X (an RTX) is a legitimate memory address on the target    machine for a memory operand of mode MODE.     It usually pays to define several simpler macros to serve as    subroutines for this one.  Otherwise it may be too complicated    to understand.     This macro must exist in two variants: a strict variant and a    non-strict one.  The strict variant is used in the reload pass.     It must be defined so that any pseudo-register that has not been    allocated a hard register is considered a memory reference.  In    contexts where some kind of register is required, a    pseudo-register with no hard register must be rejected.     The non-strict variant is used in other passes.  It must be    defined to accept all pseudo-registers in every context where    some kind of register is required.     Compiler source files that want to use the strict variant of    this macro define the macro `REG_OK_STRICT'.  You should use an    `#ifdef REG_OK_STRICT' conditional to define the strict variant    in that case and the non-strict variant otherwise.     Typically among the subroutines used to define    `GO_IF_LEGITIMATE_ADDRESS' are subroutines to check for    acceptable registers for various purposes (one for base    registers, one for index registers, and so on).  Then only these    subroutine macros need have two variants; the higher levels of    macros may be the same whether strict or not.     Normally, constant addresses which are the sum of a `symbol_ref'    and an integer are stored inside a `const' RTX to mark them as    constant.  Therefore, there is no need to recognize such sums    specifically as legitimate addresses.  Normally you would simply    recognize any `const' as legitimate.     Usually `PRINT_OPERAND_ADDRESS' is not prepared to handle    constant sums that are not marked with  `const'.  It assumes    that a naked `plus' indicates indexing.  If so, then you *must*    reject such naked constant sums as illegitimate addresses, so    that none of them will be given to `PRINT_OPERAND_ADDRESS'.     On some machines, whether a symbolic address is legitimate    depends on the section that the address refers to.  On these    machines, define the macro `ENCODE_SECTION_INFO' to store the    information into the `symbol_ref', and then check for it here.     When you see a `const', you will have to look inside it to find    the `symbol_ref' in order to determine the section.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|GO_PRINTF
parameter_list|(
name|x
parameter_list|)
value|trace(x)
end_define

begin_define
define|#
directive|define
name|GO_PRINTF2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|trace(x,y)
end_define

begin_define
define|#
directive|define
name|GO_DEBUG_RTX
parameter_list|(
name|x
parameter_list|)
value|debug_rtx(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GO_PRINTF
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GO_PRINTF2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GO_DEBUG_RTX
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{									\   register rtx xinsn = (X);						\ 									\   if (TARGET_DEBUG_B_MODE)						\     {									\       GO_PRINTF2 ("\n========== GO_IF_LEGITIMATE_ADDRESS, %sstrict\n",	\ 		  (REG_OK_STRICT_P) ? "" : "not ");			\       GO_DEBUG_RTX (xinsn);						\     }									\ 									\   if (GET_CODE (xinsn) == REG&& REG_OK_FOR_BASE_P (xinsn))		\     goto ADDR;								\ 									\   if (CONSTANT_ADDRESS_P (xinsn))					\     goto ADDR;								\ 									\   if (GET_CODE (xinsn) == PLUS)						\     {									\       register rtx xplus0 = XEXP (xinsn, 0);				\       register rtx xplus1 = XEXP (xinsn, 1);				\       register enum rtx_code code0 = GET_CODE (xplus0);			\       register enum rtx_code code1 = GET_CODE (xplus1);			\ 									\       if (code0 != REG&& code1 == REG)					\ 	{								\ 	  xplus0 = XEXP (xinsn, 1);					\ 	  xplus1 = XEXP (xinsn, 0);					\ 	  code0 = GET_CODE (xplus0);					\ 	  code1 = GET_CODE (xplus1);					\ 	}								\ 									\       if (code0 == REG&& REG_OK_FOR_BASE_P (xplus0))			\ 	{								\ 	  if (code1 == CONST_INT)					\ 	    {								\ 	      register unsigned adj_offset = INTVAL (xplus1) + 0x8000;	\ 									\ 	      if ((adj_offset<= 0xffff)				\&& (adj_offset + GET_MODE_SIZE (MODE) - 1<= 0xffff))	\ 		goto ADDR;						\ 	    }								\ 									\
comment|/* For some code sequences, you actually get better code by	\ 	     pretending that the MIPS supports an address mode of a	\ 	     constant address + a register, even though the real	\ 	     machine doesn't support it.  This is because the		\ 	     assembler can use $r1 to load just the high 16 bits, add	\ 	     in the register, and fold the low 16 bits into the memory	\ 	     reference, whereas the compiler generates a 4 instruction	\ 	     sequence.  On the other hand, CSE is not as effective.	\ 	     It would be a win to generate the lui directly, but the	\ 	     MIPS assembler does not have syntax to generate the	\ 	     appropriate relocation.  */
value|\ 									\ 	  else if (!TARGET_DEBUG_A_MODE					\&& code0 == REG					\&& CONSTANT_ADDRESS_P (xplus1))			\ 	    goto ADDR;							\ 	}								\     }									\ 									\   if (TARGET_DEBUG_B_MODE)						\     GO_PRINTF ("Not a legitimate address\n");				\ }
end_define

begin_comment
comment|/* A C expression that is 1 if the RTX X is a constant which is a    valid address.  On most machines, this can be defined as    `CONSTANT_P (X)', but a few machines are more restrictive in    which constant addresses are supported.     `CONSTANT_P' accepts integer-values expressions whose values are    not explicitly known, such as `symbol_ref', `label_ref', and    `high' expressions and `const' arithmetic expressions, in    addition to `const_int' and `const_double' expressions.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_P (X)&& (!HALF_PIC_P () || !HALF_PIC_ADDRESS_P (X)))
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     At present, GAS doesn't understand li.[sd], so don't allow it    to be generated at present.  Also, the MIPS assembler does not    grok li.d Infinity.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) != CONST_DOUBLE || mips_const_double_ok (X, GET_MODE (X)))
end_define

begin_comment
comment|/* A C compound statement that attempts to replace X with a valid    memory address for an operand of mode MODE.  WIN will be a C    statement label elsewhere in the code; the macro definition may    use            GO_IF_LEGITIMATE_ADDRESS (MODE, X, WIN);     to avoid further processing if the address has become legitimate.     X will always be the result of a call to `break_out_memory_refs',    and OLDX will be the operand that was given to that function to    produce X.     The code generated by this macro should not alter the    substructure of X.  If it transforms X into a more legitimate    form, it should assign X (which will always be a C variable) a    new value.     It is not necessary for this macro to come up with a legitimate    address.  The compiler has standard ways of doing so in all    cases.  In fact, it is safe for this macro to do nothing.  But    often a machine-dependent strategy can generate better code.     For the MIPS, transform:  	memory(X +<large int>)     into:  	Y =<large int>& ~0x7fff; 	Z = X + Y 	memory (Z + (<large int>& 0x7fff));     This is for CSE to find several similar references, and only use one Z.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMIZE_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|OLDX
parameter_list|,
name|MODE
parameter_list|,
name|WIN
parameter_list|)
define|\
value|{									\   register rtx xinsn = (X);						\ 									\   if (TARGET_DEBUG_B_MODE)						\     {									\       GO_PRINTF ("\n========== LEGITIMIZE_ADDRESS\n");			\       GO_DEBUG_RTX (xinsn);						\     }									\ 									\   if (GET_CODE (xinsn) == PLUS)						\     {									\       register rtx xplus0 = XEXP (xinsn, 0);				\       register rtx xplus1 = XEXP (xinsn, 1);				\       register enum rtx_code code0 = GET_CODE (xplus0);			\       register enum rtx_code code1 = GET_CODE (xplus1);			\ 									\       if (code0 != REG&& code1 == REG)					\ 	{								\ 	  xplus0 = XEXP (xinsn, 1);					\ 	  xplus1 = XEXP (xinsn, 0);					\ 	  code0 = GET_CODE (xplus0);					\ 	  code1 = GET_CODE (xplus1);					\ 	}								\ 									\       if (code0 == REG&& REG_OK_FOR_BASE_P (xplus0)			\&& code1 == CONST_INT&& !SMALL_INT (xplus1))			\ 	{								\ 	  rtx int_reg = gen_reg_rtx (Pmode);				\ 	  rtx ptr_reg = gen_reg_rtx (Pmode);				\ 									\ 	  emit_move_insn (int_reg,					\ 			  GEN_INT (INTVAL (xplus1)& ~ 0x7fff));	\ 									\ 	  emit_insn (gen_rtx (SET, VOIDmode,				\ 			      ptr_reg,					\ 			      gen_rtx (PLUS, Pmode, xplus0, int_reg)));	\ 									\ 	  X = gen_rtx (PLUS, Pmode, ptr_reg,				\ 		       GEN_INT (INTVAL (xplus1)& 0x7fff));		\ 	  goto WIN;							\ 	}								\     }									\ 									\   if (TARGET_DEBUG_B_MODE)						\     GO_PRINTF ("LEGITIMIZE_ADDRESS could not fix.\n");			\ }
end_define

begin_comment
comment|/* A C statement or compound statement with a conditional `goto    LABEL;' executed if memory address X (an RTX) can have different    meanings depending on the machine mode of the memory reference it    is used for.     Autoincrement and autodecrement addresses typically have    mode-dependent effects because the amount of the increment or    decrement is the size of the operand being addressed.  Some    machines have other mode-dependent addresses.  Many RISC machines    have no mode-dependent addresses.     You may assume that ADDR is a valid address for the machine.  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_MODE_DEPENDENT_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|LABEL
parameter_list|)
value|{}
end_define

begin_comment
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     The macro definition, if any, is executed immediately after the    rtl for DECL has been created and stored in `DECL_RTL (DECL)'.     The value of the rtl will be a `mem' whose address is a    `symbol_ref'.     The usual thing for this macro to do is to a flag in the    `symbol_ref' (such as `SYMBOL_REF_FLAG') or to store a modified    name string in the `symbol_ref' (if one bit is not enough    information).     The best way to modify the name string is by adding text to the    beginning, with suitable punctuation to prevent any ambiguity.     Allocate the new name in `saveable_obstack'.  You will have to    modify `ASM_OUTPUT_LABELREF' to remove and decode the added text    and output the name accordingly.     You can also check the information stored in the `symbol_ref' in    the definition of `GO_IF_LEGITIMATE_ADDRESS' or    `PRINT_OPERAND_ADDRESS'. */
end_comment

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|do									\   {									\     if (optimize&& mips_section_threshold> 0&& TARGET_GP_OPT		\&& TREE_CODE (DECL) == VAR_DECL)				\       {									\ 	int size = int_size_in_bytes (TREE_TYPE (DECL));		\ 									\ 	if (size> 0&& size<= mips_section_threshold)			\ 	  SYMBOL_REF_FLAG (XEXP (DECL_RTL (DECL), 0)) = 1;		\       }									\ 									\     else if (HALF_PIC_P ())						\       HALF_PIC_ENCODE (DECL);						\   }									\ while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|SImode
end_define

begin_comment
comment|/* Define this if the tablejump instruction expects the table    to contain offsets from the address of the table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_comment
comment|/* #define CASE_VECTOR_PC_RELATIVE */
end_comment

begin_comment
comment|/* Specify the tree operation to be used to convert reals to integers.  */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT_FIX_EXPR
value|FIX_ROUND_EXPR
end_define

begin_comment
comment|/* This is the kind of divide that is easiest to do in the general case.  */
end_comment

begin_define
define|#
directive|define
name|EASY_DIV_EXPR
value|TRUNC_DIV_EXPR
end_define

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_SIGNED_CHAR
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|4
end_define

begin_comment
comment|/* Define this macro as a C expression which is nonzero if    accessing less than a word of memory (i.e. a `char' or a    `short') is no faster than accessing a word of memory, i.e., if    such access require more than one instruction or if there is no    difference in cost between byte and (aligned) word loads.     On RISC machines, it tends to generate better code to define    this as 1, since it avoids making a QI or HI mode register.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|1
end_define

begin_comment
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_comment
comment|/* Define this if zero-extension is slow (more than one real instruction).  */
end_comment

begin_define
define|#
directive|define
name|SLOW_ZERO_EXTEND
end_define

begin_comment
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.     Only 5 bits are used in SLLV and SRLV */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
end_define

begin_comment
comment|/* Value is 1 if truncating an integer of INPREC bits to OUTPREC bits    is done just by pretending it is already truncated.  */
end_comment

begin_define
define|#
directive|define
name|TRULY_NOOP_TRUNCATION
parameter_list|(
name|OUTPREC
parameter_list|,
name|INPREC
parameter_list|)
value|1
end_define

begin_comment
comment|/* Define this macro to control use of the character `$' in    identifier names.  The value should be 0, 1, or 2.  0 means `$'    is not allowed by default; 1 means it is allowed by default if    `-traditional' is used; 2 means it is allowed by default provided    `-ansi' is not used.  1 is the default; there is no need to    define this macro in that case. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOLLARS_IN_IDENTIFIERS
end_ifndef

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_comment
comment|/* A function address in a call instruction    is a word address (for indexing purposes)    so give the MEM rtx a words's mode.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|SImode
end_define

begin_comment
comment|/* Define TARGET_MEM_FUNCTIONS if we want to use calls to memcpy and    memset, instead of the BSD functions bcopy and bzero.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPS_SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|OSF_OS
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* A part of a C `switch' statement that describes the relative    costs of constant RTL expressions.  It must contain `case'    labels for expression codes `const_int', `const', `symbol_ref',    `label_ref' and `const_double'.  Each case must ultimately reach    a `return' statement to return the relative cost of the use of    that kind of constant value in an expression.  The cost may    depend on the precise value of the constant, which is available    for examination in X.     CODE is the expression code--redundant, since it can be obtained    with `GET_CODE (X)'.  */
end_comment

begin_define
define|#
directive|define
name|CONST_COSTS
parameter_list|(
name|X
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case CONST_INT:							\
comment|/* Always return 0, since we don't have different sized		\        instructions, hence different costs according to Richard		\        Kenner */
value|\     return COSTS_N_INSNS (0);						\ 									\   case LABEL_REF:							\     return COSTS_N_INSNS (2);						\ 									\   case CONST:								\     {									\       rtx offset = const0_rtx;						\       rtx symref = eliminate_constant_term (X,&offset);		\ 									\       if (GET_CODE (symref) == LABEL_REF)				\ 	return COSTS_N_INSNS (2);					\ 									\       if (GET_CODE (symref) != SYMBOL_REF)				\ 	return COSTS_N_INSNS (4);					\ 									\
comment|/* let's be paranoid.... */
value|\       if (INTVAL (offset)< -32768 || INTVAL (offset)> 32767)		\ 	return COSTS_N_INSNS (2);					\ 									\       return COSTS_N_INSNS (SYMBOL_REF_FLAG (symref) ? 1 : 2);		\     }									\ 									\   case SYMBOL_REF:							\     return COSTS_N_INSNS (SYMBOL_REF_FLAG (X) ? 1 : 2);			\ 									\   case CONST_DOUBLE:							\     return COSTS_N_INSNS ((CONST_DOUBLE_HIGH (X) == 0			\&& CONST_DOUBLE_LOW (X)) ? 2 : 4);
end_define

begin_comment
comment|/* Like `CONST_COSTS' but applies to nonconstant RTL expressions.    This can be used, for example, to indicate how costly a multiply    instruction is.  In writing this macro, you can use the construct    `COSTS_N_INSNS (N)' to specify a cost equal to N fast instructions.     This macro is optional; do not define it if the default cost    assumptions are adequate for the target machine.     If -mdebugd is used, change the multiply cost to 2, so multiply by    a constant isn't converted to a series of shifts.  This helps    strength reduction, and also makes it easier to identify what the    compiler is doing.  */
end_comment

begin_define
define|#
directive|define
name|RTX_COSTS
parameter_list|(
name|X
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case MEM:								\     {									\       int num_words = (GET_MODE_SIZE (GET_MODE (X))> UNITS_PER_WORD) ? 2 : 1; \       if (simple_memory_operand (X, GET_MODE (X)))			\ 	return COSTS_N_INSNS (num_words);				\ 									\       return COSTS_N_INSNS (2*num_words);				\     }									\ 									\   case FFS:								\     return COSTS_N_INSNS (6);						\ 									\   case NOT:								\     return COSTS_N_INSNS ((GET_MODE (X) == DImode) ? 2 : 1);		\ 									\   case AND:								\   case IOR:								\   case XOR:								\     if (GET_MODE (X) == DImode)						\       return COSTS_N_INSNS (2);						\ 									\     if (GET_CODE (XEXP (X, 1)) == CONST_INT)				\       {									\ 	rtx number = XEXP (X, 1);					\ 	if (SMALL_INT_UNSIGNED (number))				\ 	  return COSTS_N_INSNS (1);					\ 									\ 	else if (SMALL_INT (number))					\ 	  return COSTS_N_INSNS (2);					\ 									\ 	return COSTS_N_INSNS (3);					\       }									\ 									\     return COSTS_N_INSNS (1);						\ 									\   case ASHIFT:								\   case ASHIFTRT:							\   case LSHIFT:								\   case LSHIFTRT:							\     if (GET_MODE (X) == DImode)						\       return COSTS_N_INSNS ((GET_CODE (XEXP (X, 1)) == CONST_INT) ? 12 : 4); \ 									\     return COSTS_N_INSNS (1);						\ 									\   case ABS:								\     {									\       enum machine_mode xmode = GET_MODE (X);				\       if (xmode == SFmode || xmode == DFmode)				\ 	return COSTS_N_INSNS (1);					\ 									\       return COSTS_N_INSNS (4);						\     }									\ 									\   case PLUS:								\   case MINUS:								\     {									\       enum machine_mode xmode = GET_MODE (X);				\       if (xmode == SFmode || xmode == DFmode)				\ 	return COSTS_N_INSNS (2);					\ 									\       if (xmode == DImode)						\ 	return COSTS_N_INSNS (4);					\ 									\       return COSTS_N_INSNS (1);						\     }									\ 									\   case NEG:								\     return COSTS_N_INSNS ((GET_MODE (X) == DImode) ? 4 : 1);		\ 									\   case MULT:								\     {									\       enum machine_mode xmode = GET_MODE (X);				\       if (xmode == SFmode)						\ 	return COSTS_N_INSNS (4);					\ 									\       if (xmode == DFmode)						\ 	return COSTS_N_INSNS (5);					\ 									\       return COSTS_N_INSNS (12);					\     }									\ 									\   case DIV:								\   case MOD:								\     {									\       enum machine_mode xmode = GET_MODE (X);				\       if (xmode == SFmode)						\ 	return COSTS_N_INSNS (12);					\ 									\       if (xmode == DFmode)						\ 	return COSTS_N_INSNS (19);					\     }									\
comment|/* fall through */
value|\ 									\   case UDIV:								\   case UMOD:								\     return COSTS_N_INSNS (35);
end_define

begin_comment
comment|/* An expression giving the cost of an addressing mode that    contains ADDRESS.  If not defined, the cost is computed from the    form of the ADDRESS expression and the `CONST_COSTS' values.     For most CISC machines, the default cost is a good approximation    of the true cost of the addressing mode.  However, on RISC    machines, all instructions normally have the same length and    execution time.  Hence all addresses will have equal costs.     In cases where more than one form of an address is known, the    form with the lowest cost will be used.  If multiple forms have    the same, lowest, cost, the one that is the most complex will be    used.     For example, suppose an address that is equal to the sum of a    register and a constant is used twice in the same basic block.     When this macro is not defined, the address will be computed in    a register and memory references will be indirect through that    register.  On machines where the cost of the addressing mode    containing the sum is no higher than that of a simple indirect    reference, this will produce an additional instruction and    possibly require an additional register.  Proper specification    of this macro eliminates this overhead for such machines.     Similar use of this macro is made in strength reduction of loops.     ADDRESS need not be valid as an address.  In such a case, the    cost is not relevant and can be any value; invalid addresses    need not be assigned a different cost.     On machines where an address involving more than one register is    as cheap as an address computation involving only one register,    defining `ADDRESS_COST' to reflect this can cause two registers    to be live over a region of code where only one would have been    if `ADDRESS_COST' were not defined in that manner.  This effect    should be considered in the definition of this macro.     Equivalent costs should probably only be given to addresses with    different numbers of registers on machines with lots of registers.     This macro will normally either not be defined or be defined as    a constant. */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|ADDR
parameter_list|)
value|(REG_P (ADDR) ? 1 : mips_address_cost (ADDR))
end_define

begin_comment
comment|/* A C expression for the cost of moving data from a register in    class FROM to one in class TO.  The classes are expressed using    the enumeration values such as `GENERAL_REGS'.  A value of 2 is    the default; other values are interpreted relative to that.     It is not required that the cost always equal 2 when FROM is the    same as TO; on some machines it is expensive to move between    registers if they are not general registers.     If reload sees an insn consisting of a single `set' between two    hard registers, and if `REGISTER_MOVE_COST' applied to their    classes returns a value of 2, reload does not check to ensure    that the constraints of the insn are met.  Setting a cost of    other than 2 will allow reload to verify that the constraints are    met.  You should do this if the `movM' pattern's constraints do    not allow such copying.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|)
value|4
end_define

begin_comment
comment|/* force reload to use constraints */
end_comment

begin_comment
comment|/* A C expression for the cost of a branch instruction.  A value of    1 is the default; other values are interpreted relative to that.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
define|\
value|((mips_cpu == PROCESSOR_R4000 || mips_cpu == PROCESSOR_R6000) ? 2 : 1)
end_define

begin_escape
end_escape

begin_comment
comment|/* Used in by the peephole code.  */
end_comment

begin_define
define|#
directive|define
name|classify_op
parameter_list|(
name|op
parameter_list|,
name|mode
parameter_list|)
value|(mips_rtx_classify[ (int)GET_CODE (op) ])
end_define

begin_define
define|#
directive|define
name|additive_op
parameter_list|(
name|op
parameter_list|,
name|mode
parameter_list|)
value|((classify_op (op,mode)& CLASS_ADD_OP)      != 0)
end_define

begin_define
define|#
directive|define
name|divmod_op
parameter_list|(
name|op
parameter_list|,
name|mode
parameter_list|)
value|((classify_op (op,mode)& CLASS_DIVMOD_OP)   != 0)
end_define

begin_define
define|#
directive|define
name|unsigned_op
parameter_list|(
name|op
parameter_list|,
name|mode
parameter_list|)
value|((classify_op (op,mode)& CLASS_UNSIGNED_OP) != 0)
end_define

begin_define
define|#
directive|define
name|CLASS_ADD_OP
value|0x01
end_define

begin_comment
comment|/* operator is PLUS/MINUS */
end_comment

begin_define
define|#
directive|define
name|CLASS_DIVMOD_OP
value|0x02
end_define

begin_comment
comment|/* operator is {,U}{DIV,MOD} */
end_comment

begin_define
define|#
directive|define
name|CLASS_UNSIGNED_OP
value|0x04
end_define

begin_comment
comment|/* operator is U{DIV,MOD} */
end_comment

begin_define
define|#
directive|define
name|CLASS_CMP_OP
value|0x08
end_define

begin_comment
comment|/* operator is comparison */
end_comment

begin_define
define|#
directive|define
name|CLASS_EQUALITY_OP
value|0x10
end_define

begin_comment
comment|/* operator is == or != */
end_comment

begin_define
define|#
directive|define
name|CLASS_FCMP_OP
value|0x08
end_define

begin_comment
comment|/* operator is fp. compare */
end_comment

begin_define
define|#
directive|define
name|CLASS_UNS_CMP_OP
value|(CLASS_UNSIGNED_OP | CLASS_CMP_OP)
end_define

begin_escape
end_escape

begin_comment
comment|/* Optionally define this if you have added predicates to    `MACHINE.c'.  This macro is called within an initializer of an    array of structures.  The first field in the structure is the    name of a predicate and the second field is an array of rtl    codes.  For each predicate, list all rtl codes that can be in    expressions matched by the predicate.  The list should have a    trailing comma.  Here is an example of two entries in the list    for a typical RISC machine:     #define PREDICATE_CODES \      {"gen_reg_rtx_operand", {SUBREG, REG}},  \      {"reg_or_short_cint_operand", {SUBREG, REG, CONST_INT}},     Defining this macro does not affect the generated code (however,    incorrect definitions that omit an rtl code that may be matched    by the predicate can cause the compiler to malfunction).     Instead, it allows the table built by `genrecog' to be more    compact and efficient, thus speeding up the compiler.  The most    important predicates to include in the list specified by this    macro are thoses used in the most insn patterns.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"uns_arith_operand",		{ REG, CONST_INT, SUBREG }},		\   {"arith_operand",		{ REG, CONST_INT, SUBREG }},		\   {"arith32_operand",		{ REG, CONST_INT, SUBREG }},		\   {"reg_or_0_operand",		{ REG, CONST_INT, SUBREG }},		\   {"small_int",			{ CONST_INT }},				\   {"large_int",			{ CONST_INT }},				\   {"md_register_operand",	{ REG }},				\   {"mips_const_double_ok",	{ CONST_DOUBLE }},			\   {"simple_memory_operand",	{ MEM, SUBREG }},			\   {"equality_op",		{ EQ, NE }},				\   {"cmp_op",			{ EQ, NE, GT, GE, GTU, GEU, LT, LE,	\ 				  LTU, LEU }},				\   {"cmp2_op",			{ EQ, NE, GT, GE, GTU, GEU, LT, LE,	\ 				  LTU, LEU }},				\   {"fcmp_op",			{ EQ, NE, GT, GE, LT, LE }},		\   {"uns_cmp_op",		{ GTU, GEU, LTU, LEU }},
end_define

begin_escape
end_escape

begin_comment
comment|/* If defined, a C statement to be executed just prior to the    output of assembler code for INSN, to modify the extracted    operands so they will be output differently.     Here the argument OPVEC is the vector containing the operands    extracted from INSN, and NOPERANDS is the number of elements of    the vector which contain meaningful data for this insn.  The    contents of this vector are what will be used to convert the    insn template into assembler code, so you can change the    assembler output by changing the contents of the vector.     We use it to check if the current insn needs a nop in front of it    because of load delays, and also to update the delay slot    statistics.  */
end_comment

begin_define
define|#
directive|define
name|FINAL_PRESCAN_INSN
parameter_list|(
name|INSN
parameter_list|,
name|OPVEC
parameter_list|,
name|NOPERANDS
parameter_list|)
define|\
value|final_prescan_insn (INSN, OPVEC, NOPERANDS)
end_define

begin_escape
end_escape

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.    Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  */
end_comment

begin_comment
comment|/* A C compound statement to set the components of `cc_status'    appropriately for an insn INSN whose body is EXP.  It is this    macro's responsibility to recognize insns that set the condition    code as a byproduct of other activity as well as those that    explicitly set `(cc0)'.     This macro is not used on machines that do not use `cc0'.  */
end_comment

begin_define
define|#
directive|define
name|NOTICE_UPDATE_CC
parameter_list|(
name|EXP
parameter_list|,
name|INSN
parameter_list|)
define|\
value|do									\   {									\     enum attr_type type = get_attr_type (INSN);				\     if (type == TYPE_ICMP || type == TYPE_FCMP)				\       CC_STATUS_INIT;							\   }									\ while (0)
end_define

begin_comment
comment|/* A list of names to be used for additional modes for condition code    values in registers.  These names are added to `enum machine_mode'    and all have class `MODE_CC'.  By convention, they should start    with `CC' and end with `mode'.     You should only define this macro if your machine does not use    `cc0' and only if additional modes are required.     On the MIPS, we use CC_FPmode for all floating point except for not    equal, CC_REV_FPmode for not equal (to reverse the sense of the    jump), CC_EQmode for integer equality/inequality comparisons,    CC_0mode for comparisons against 0, and CCmode for other integer    comparisons. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
value|CC_EQmode, CC_FPmode, CC_0mode, CC_REV_FPmode
end_define

begin_comment
comment|/* A list of C strings giving the names for the modes listed in    `EXTRA_CC_MODES'.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_NAMES
value|"CC_EQ", "CC_FP", "CC_0", "CC_REV_FP"
end_define

begin_comment
comment|/* Returns a mode from class `MODE_CC' to be used when comparison    operation code OP is applied to rtx X.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_CC_MODE
parameter_list|(
name|OP
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|(GET_MODE_CLASS (GET_MODE (X)) != MODE_FLOAT				\ 	? SImode							\ 	: ((OP == NE) ? CC_REV_FPmode : CC_FPmode))
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.    If we are optimizing to use the global pointer, create a temporary    file to hold all of the text stuff, and write it out to the end.    This is needed because the MIPS assembler is evidently one pass,    and if it hasn't seen the relevant .comm/.lcomm/.extern/.sdata    declaration when the code is processed, it generates a two    instruction sequence.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|STREAM
parameter_list|)
value|mips_asm_file_start (STREAM)
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|" #APP\n"
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|" #NO_APP\n"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).     In order to support the two different conventions for register names,    we use the name of a table set up in mips.c, which is overwritten    if -mrnames is used.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{									\&mips_reg_names[ 0][0],						\&mips_reg_names[ 1][0],						\&mips_reg_names[ 2][0],						\&mips_reg_names[ 3][0],						\&mips_reg_names[ 4][0],						\&mips_reg_names[ 5][0],						\&mips_reg_names[ 6][0],						\&mips_reg_names[ 7][0],						\&mips_reg_names[ 8][0],						\&mips_reg_names[ 9][0],						\&mips_reg_names[10][0],						\&mips_reg_names[11][0],						\&mips_reg_names[12][0],						\&mips_reg_names[13][0],						\&mips_reg_names[14][0],						\&mips_reg_names[15][0],						\&mips_reg_names[16][0],						\&mips_reg_names[17][0],						\&mips_reg_names[18][0],						\&mips_reg_names[19][0],						\&mips_reg_names[20][0],						\&mips_reg_names[21][0],						\&mips_reg_names[22][0],						\&mips_reg_names[23][0],						\&mips_reg_names[24][0],						\&mips_reg_names[25][0],						\&mips_reg_names[26][0],						\&mips_reg_names[27][0],						\&mips_reg_names[28][0],						\&mips_reg_names[29][0],						\&mips_reg_names[30][0],						\&mips_reg_names[31][0],						\&mips_reg_names[32][0],						\&mips_reg_names[33][0],						\&mips_reg_names[34][0],						\&mips_reg_names[35][0],						\&mips_reg_names[36][0],						\&mips_reg_names[37][0],						\&mips_reg_names[38][0],						\&mips_reg_names[39][0],						\&mips_reg_names[40][0],						\&mips_reg_names[41][0],						\&mips_reg_names[42][0],						\&mips_reg_names[43][0],						\&mips_reg_names[44][0],						\&mips_reg_names[45][0],						\&mips_reg_names[46][0],						\&mips_reg_names[47][0],						\&mips_reg_names[48][0],						\&mips_reg_names[49][0],						\&mips_reg_names[50][0],						\&mips_reg_names[51][0],						\&mips_reg_names[52][0],						\&mips_reg_names[53][0],						\&mips_reg_names[54][0],						\&mips_reg_names[55][0],						\&mips_reg_names[56][0],						\&mips_reg_names[57][0],						\&mips_reg_names[58][0],						\&mips_reg_names[59][0],						\&mips_reg_names[60][0],						\&mips_reg_names[61][0],						\&mips_reg_names[62][0],						\&mips_reg_names[63][0],						\&mips_reg_names[64][0],						\&mips_reg_names[65][0],						\&mips_reg_names[66][0],						\ }
end_define

begin_comment
comment|/* print-rtl.c can't use REGISTER_NAMES, since it depends on mips.c.    So define this for it.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_REGISTER_NAMES
define|\
value|{									\   "$0",   "at",   "v0",   "v1",   "a0",   "a1",   "a2",   "a3",		\   "t0",   "t1",   "t2",   "t3",   "t4",   "t5",   "t6",   "t7",		\   "s0",   "s1",   "s2",   "s3",   "s4",   "s5",   "s6",   "s7",		\   "t8",   "t9",   "k0",   "k1",   "gp",   "sp",   "$fp",   "ra",	\   "$f0",  "$f1",  "$f2",  "$f3",  "$f4",  "$f5",  "$f6",  "$f7",	\   "$f8",  "$f9",  "$f10", "$f11", "$f12", "$f13", "$f14", "$f15",	\   "$f16", "$f17", "$f18", "$f19", "$f20", "$f21", "$f22", "$f23",	\   "$f24", "$f25", "$f26", "$f27", "$f28", "$f29", "$f30", "$f31",	\   "hi",   "lo",   "$fcr31"						\ }
end_define

begin_comment
comment|/* If defined, a C initializer for an array of structures    containing a name and a register number.  This macro defines    additional names for hard registers, thus allowing the `asm'    option in declarations to refer to registers using alternate    names.     We define both names for the integer registers here.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{									\   { "$0",	 0 + GP_REG_FIRST },					\   { "$1",	 1 + GP_REG_FIRST },					\   { "$2",	 2 + GP_REG_FIRST },					\   { "$3",	 3 + GP_REG_FIRST },					\   { "$4",	 4 + GP_REG_FIRST },					\   { "$5",	 5 + GP_REG_FIRST },					\   { "$6",	 6 + GP_REG_FIRST },					\   { "$7",	 7 + GP_REG_FIRST },					\   { "$8",	 8 + GP_REG_FIRST },					\   { "$9",	 9 + GP_REG_FIRST },					\   { "$10",	10 + GP_REG_FIRST },					\   { "$11",	11 + GP_REG_FIRST },					\   { "$12",	12 + GP_REG_FIRST },					\   { "$13",	13 + GP_REG_FIRST },					\   { "$14",	14 + GP_REG_FIRST },					\   { "$15",	15 + GP_REG_FIRST },					\   { "$16",	16 + GP_REG_FIRST },					\   { "$17",	17 + GP_REG_FIRST },					\   { "$18",	18 + GP_REG_FIRST },					\   { "$19",	19 + GP_REG_FIRST },					\   { "$20",	20 + GP_REG_FIRST },					\   { "$21",	21 + GP_REG_FIRST },					\   { "$22",	22 + GP_REG_FIRST },					\   { "$23",	23 + GP_REG_FIRST },					\   { "$24",	24 + GP_REG_FIRST },					\   { "$25",	25 + GP_REG_FIRST },					\   { "$26",	26 + GP_REG_FIRST },					\   { "$27",	27 + GP_REG_FIRST },					\   { "$28",	28 + GP_REG_FIRST },					\   { "$29",	29 + GP_REG_FIRST },					\   { "$30",	30 + GP_REG_FIRST },					\   { "$31",	31 + GP_REG_FIRST },					\   { "$sp",	29 + GP_REG_FIRST },					\   { "$fp",	30 + GP_REG_FIRST },					\   { "at",	 1 + GP_REG_FIRST },					\   { "v0",	 2 + GP_REG_FIRST },					\   { "v1",	 3 + GP_REG_FIRST },					\   { "a0",	 4 + GP_REG_FIRST },					\   { "a1",	 5 + GP_REG_FIRST },					\   { "a2",	 6 + GP_REG_FIRST },					\   { "a3",	 7 + GP_REG_FIRST },					\   { "t0",	 8 + GP_REG_FIRST },					\   { "t1",	 9 + GP_REG_FIRST },					\   { "t2",	10 + GP_REG_FIRST },					\   { "t3",	11 + GP_REG_FIRST },					\   { "t4",	12 + GP_REG_FIRST },					\   { "t5",	13 + GP_REG_FIRST },					\   { "t6",	14 + GP_REG_FIRST },					\   { "t7",	15 + GP_REG_FIRST },					\   { "s0",	16 + GP_REG_FIRST },					\   { "s1",	17 + GP_REG_FIRST },					\   { "s2",	18 + GP_REG_FIRST },					\   { "s3",	19 + GP_REG_FIRST },					\   { "s4",	20 + GP_REG_FIRST },					\   { "s5",	21 + GP_REG_FIRST },					\   { "s6",	22 + GP_REG_FIRST },					\   { "s7",	23 + GP_REG_FIRST },					\   { "t8",	24 + GP_REG_FIRST },					\   { "t9",	25 + GP_REG_FIRST },					\   { "k0",	26 + GP_REG_FIRST },					\   { "k1",	27 + GP_REG_FIRST },					\   { "gp",	28 + GP_REG_FIRST },					\   { "sp",	29 + GP_REG_FIRST },					\   { "fp",	30 + GP_REG_FIRST },					\   { "ra",	31 + GP_REG_FIRST },					\   { "$sp",	29 + GP_REG_FIRST },					\   { "$fp",	30 + GP_REG_FIRST },					\   { "cc",	FPSW_REGNUM },						\ }
end_define

begin_comment
comment|/* Define results of standard character escape sequences.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BELL
value|007
end_define

begin_define
define|#
directive|define
name|TARGET_BS
value|010
end_define

begin_define
define|#
directive|define
name|TARGET_TAB
value|011
end_define

begin_define
define|#
directive|define
name|TARGET_NEWLINE
value|012
end_define

begin_define
define|#
directive|define
name|TARGET_VT
value|013
end_define

begin_define
define|#
directive|define
name|TARGET_FF
value|014
end_define

begin_define
define|#
directive|define
name|TARGET_CR
value|015
end_define

begin_comment
comment|/* A C compound statement to output to stdio stream STREAM the    assembler syntax for an instruction operand X.  X is an RTL    expression.     CODE is a value that can be used to specify one of several ways    of printing the operand.  It is used when identical operands    must be printed differently depending on the context.  CODE    comes from the `%' specification that was used to request    printing of the operand.  If the specification was just `%DIGIT'    then CODE is 0; if the specification was `%LTR DIGIT' then CODE    is the ASCII code for LTR.     If X is a register, this macro should print the register's name.    The names can be found in an array `reg_names' whose type is    `char *[]'.  `reg_names' is initialized from `REGISTER_NAMES'.     When the machine description has a specification `%PUNCT' (a `%'    followed by a punctuation character), this macro is called with    a null pointer for X and the punctuation character for CODE.     See mips.c for the MIPS specific codes.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
value|print_operand (FILE, X, CODE)
end_define

begin_comment
comment|/* A C expression which evaluates to true if CODE is a valid    punctuation character for use in the `PRINT_OPERAND' macro.  If    `PRINT_OPERAND_PUNCT_VALID_P' is not defined, it means that no    punctuation characters (except for the standard one, `%') are    used in this way.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
value|mips_print_operand_punct[CODE]
end_define

begin_comment
comment|/* A C compound statement to output to stdio stream STREAM the    assembler syntax for an instruction operand that is a memory    reference whose address is ADDR.  ADDR is an RTL expression.     On some machines, the syntax for a symbolic address depends on    the section that the address refers to.  On these machines,    define the macro `ENCODE_SECTION_INFO' to store the information    into the `symbol_ref', and then check for it here.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
value|print_operand_address (FILE, ADDR)
end_define

begin_comment
comment|/* A C statement, to be executed after all slot-filler instructions    have been output.  If necessary, call `dbr_sequence_length' to    determine the number of slots filled in a sequence (zero if not    currently outputting a sequence), to decide how many no-ops to    output, or whatever.     Don't define this macro if it has nothing to do, but it is    helpful in reading assembly output if the extent of the delay    sequence is made explicit (e.g. with white space).     Note that output routines for instructions with delay slots must    be prepared to deal with not being output as part of a sequence    (i.e.  when the scheduling pass is not run, or when no slot    fillers could be found.)  The variable `final_sequence' is null    when not processing a sequence, otherwise it contains the    `sequence' rtx being output.  */
end_comment

begin_define
define|#
directive|define
name|DBR_OUTPUT_SEQEND
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|do									\   {									\     if (set_nomacro> 0&& --set_nomacro == 0)				\       fputs ("\t.set\tmacro\n", STREAM);				\ 									\     if (set_noreorder> 0&& --set_noreorder == 0)			\       fputs ("\t.set\treorder\n", STREAM);				\ 									\     dslots_jump_filled++;						\     fputs ("\n", STREAM);						\   }									\ while (0)
end_define

begin_comment
comment|/* How to tell the debugger about changes of source files.  Note, the    mips ECOFF format cannot deal with changes of files inside of    functions, which means the output of parser generators like bison    is generally not debuggable without using the -l switch.  Lose,    lose, lose.  Silicon graphics seems to want all .file's hardwired    to 1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SET_FILE_NUMBER
end_ifndef

begin_define
define|#
directive|define
name|SET_FILE_NUMBER
parameter_list|()
value|++num_source_filenames
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|mips_output_filename (STREAM, NAME)
end_define

begin_comment
comment|/* This is how to output a note the debugger telling it the line number    to which the following sequence of instructions corresponds.    Silicon graphics puts a label after each .loc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LABEL_AFTER_LOC
end_ifndef

begin_define
define|#
directive|define
name|LABEL_AFTER_LOC
parameter_list|(
name|STREAM
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|STREAM
parameter_list|,
name|LINE
parameter_list|)
define|\
value|mips_output_lineno (STREAM, LINE)
end_define

begin_comment
comment|/* The MIPS implementation uses some labels for it's own purposed.  The    following lists what labels are created, and are all formed by the    pattern $L[a-z].*.  The machine independent portion of GCC creates    labels matching:  $L[A-Z][0-9]+ and $L[0-9]+.  	LM[0-9]+	Silicon Graphics/ECOFF stabs label before each stmt. 	$Lb[0-9]+	Begin blocks for MIPS debug support 	$Lc[0-9]+	Label for use in s<xx> operation. 	$Le[0-9]+	End blocks for MIPS debug support 	$Lp\..+		Half-pic labels. */
end_comment

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.     If we are optimizing the gp, remember that this label has been put    out, so we know not to emit an .extern for it in mips_asm_file_end.    We use one of the common bits in the IDENTIFIER tree node for this,    since those bits seem to be unused, and we don't have any method    of getting the decl nodes from the name.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   assemble_name (STREAM, NAME);						\   fputs (":\n", STREAM);						\ } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream    STREAM any text necessary for declaring the name NAME of an    initialized variable which is being defined.  This macro must    output the label definition (perhaps using `ASM_OUTPUT_LABEL').     The argument DECL is the `VAR_DECL' tree node representing the    variable.     If this macro is not defined, then the variable name is defined    in the usual manner as a label (by means of `ASM_OUTPUT_LABEL').  */
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
value|do									\  {									\    mips_declare_object (STREAM, NAME, "", ":\n", 0);			\    HALF_PIC_DECLARE (NAME);						\  }									\ while (0)
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     fputs ("\t.globl\t", STREAM);					\     assemble_name (STREAM, NAME);					\     fputs ("\n", STREAM);						\   } while (0)
end_define

begin_comment
comment|/* This says how to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|mips_declare_object (STREAM, NAME, "\n\t.comm\t", ",%u\n", (ROUNDED))
end_define

begin_comment
comment|/* This says how to define a local common symbol (ie, not visible to    linker).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|mips_declare_object (STREAM, NAME, "\n\t.lcomm\t", ",%u\n", (ROUNDED))
end_define

begin_comment
comment|/* This says how to output an external.  It would be possible not to    output anything and let undefined symbol become external. However    the assembler uses length information on externals to allocate in    data/sdata bss/sbss, thereby saving exec time.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|mips_output_external(STREAM,DECL,NAME)
end_define

begin_comment
comment|/* This says what to print at the end of the assembly file */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|STREAM
parameter_list|)
value|mips_asm_file_end(STREAM)
end_define

begin_comment
comment|/* This is how to declare a function name.  The actual work of    emitting the label is moved to function_prologue, so that we can    get the line number correctly emitted before the .ent directive,    and after any .file directives.     Also, switch files if we are optimizing the global pointer.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|{									\   extern FILE *asm_out_text_file;					\   if (TARGET_GP_OPT)							\     STREAM = asm_out_text_file;						\ 									\   current_function_name = NAME;						\   HALF_PIC_DECLARE (NAME);						\ }
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
value|fprintf (STREAM, "%s", NAME)
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (STREAM, "$%s%d:\n", PREFIX, NUM)
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
value|sprintf (LABEL, "*$%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|mips_output_double (STREAM, VALUE)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|mips_output_float (STREAM, VALUE)
end_define

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "\t.word\t");					\   output_addr_const (STREAM, (VALUE));					\   fprintf (STREAM, "\n");						\ } while (0)
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.half\t");					\   output_addr_const (STREAM, (VALUE));					\   fprintf (STREAM, "\n");						\ }
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CHAR
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.byte\t");					\   output_addr_const (STREAM, (VALUE));					\   fprintf (STREAM, "\n");						\ }
end_define

begin_comment
comment|/* This is how to output an assembler line for a numeric constant byte.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_BYTE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.byte\t0x%x\n", (VALUE))
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.word\t$L%d\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (We  do not use such vectors,    but we must define this macro anyway.)  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (STREAM, "\t.word\t$L%d-$L%d\n", VALUE, REL)
end_define

begin_comment
comment|/* This is how to emit the initial label for switch statements.  We    need to put the switch labels somewhere else from the text section,    because the MIPS assembler gets real confused about line numbers if    .word's appear in the text section.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|JUMPTABLE
parameter_list|)
define|\
value|{									\   rdata_section ();							\   ASM_OUTPUT_ALIGN (STREAM, 2);						\   ASM_OUTPUT_INTERNAL_LABEL (STREAM, PREFIX, NUM);			\ }
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|LOG
parameter_list|)
define|\
value|{									\   int mask = (1<< (LOG)) - 1;						\   fprintf (STREAM, "\t.align\t%d\n", (LOG));				\ }
end_define

begin_comment
comment|/* This is how to output an assembler line to to advance the location    counter by SIZE bytes.  */
end_comment

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
value|fprintf (STREAM, "\t.space\t%u\n", (SIZE))
end_define

begin_comment
comment|/* This is how to output a string.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|STREAM
parameter_list|,
name|STRING
parameter_list|,
name|LEN
parameter_list|)
define|\
value|do {									\   register int i, c, len = (LEN), cur_pos = 17;				\   register unsigned char *string = (unsigned char *)(STRING);		\   fprintf ((STREAM), "\t.ascii\t\"");					\   for (i = 0; i< len; i++)						\     {									\       register int c = string[i];					\ 									\       switch (c)							\ 	{								\ 	case '\"':							\ 	case '\\':							\ 	  putc ('\\', (STREAM));					\ 	  putc (c, (STREAM));						\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_NEWLINE:						\ 	  fputs ("\\n", (STREAM));					\ 	  if (i+1< len							\&& (((c = string[i+1])>= '\040'&& c<= '~')		\ 		  || c == TARGET_TAB))					\ 	    cur_pos = 32767;
comment|/* break right here */
value|\ 	  else								\ 	    cur_pos += 2;						\ 	  break;							\ 									\ 	case TARGET_TAB:						\ 	  fputs ("\\t", (STREAM));					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_FF:							\ 	  fputs ("\\f", (STREAM));					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_BS:							\ 	  fputs ("\\b", (STREAM));					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_CR:							\ 	  fputs ("\\r", (STREAM));					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	default:							\ 	  if (c>= ' '&& c< 0177)					\ 	    {								\ 	      putc (c, (STREAM));					\ 	      cur_pos++;						\ 	    }								\ 	  else								\ 	    {								\ 	      fprintf ((STREAM), "\\%03o", c);				\ 	      cur_pos += 4;						\ 	    }								\ 	}								\ 									\       if (cur_pos> 72&& i+1< len)					\ 	{								\ 	  cur_pos = 17;							\ 	  fprintf ((STREAM), "\"\n\t.ascii\t\"");			\ 	}								\     }									\   fprintf ((STREAM), "\"\n");						\ } while (0)
end_define

begin_comment
comment|/* Handle certain cpp directives used in header files on sysV.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Output #ident as a in the read-only data section.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|STRING
parameter_list|)
define|\
value|{									\   char *p = STRING;							\   int size = strlen (p) + 1;						\   rdata_section ();							\   assemble_string (p, size);						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the strings to put out for each section in the object file.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_comment
comment|/* instructions */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_comment
comment|/* large data */
end_comment

begin_define
define|#
directive|define
name|SDATA_SECTION_ASM_OP
value|"\t.sdata"
end_define

begin_comment
comment|/* small data */
end_comment

begin_define
define|#
directive|define
name|RDATA_SECTION_ASM_OP
value|"\t.rdata"
end_define

begin_comment
comment|/* read-only data */
end_comment

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
value|rdata_section
end_define

begin_comment
comment|/* What other sections we support other than the normal .data/.text.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_sdata, in_rdata, in_last_p1
end_define

begin_comment
comment|/* Define the additional functions to select our additional sections.  */
end_comment

begin_comment
comment|/* on the MIPS it is not a good idea to put constants in the text    section, since this defeats the sdata/data mechanism. This is    especially true when -O is used. In this case an effort is made to    address with faster (gp) register relative addressing, which can    only get at sdata and sbss items (there is no stext !!)  However,    if the constant is too large for sdata, and it's readonly, it    will go into the .rdata section. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|void									\ sdata_section ()							\ {									\   if (in_section != in_sdata)						\     {									\       fprintf (asm_out_file, "%s\n", SDATA_SECTION_ASM_OP);		\       in_section = in_sdata;						\     }									\ }									\ 									\ void									\ rdata_section ()							\ {									\   if (in_section != in_rdata)						\     {									\       fprintf (asm_out_file, "%s\n", RDATA_SECTION_ASM_OP);		\       in_section = in_rdata;						\     }									\ }
end_define

begin_comment
comment|/* Given a decl node or constant node, choose the section to output it in    and select that section.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|)
define|\
value|{									\   if ((GET_MODE_SIZE(MODE) / BITS_PER_UNIT)<= mips_section_threshold	\&& mips_section_threshold> 0)					\     sdata_section ();							\   else									\     rdata_section ();							\ }									\  #define SELECT_SECTION(DECL,RELOC)					\ {									\   if (int_size_in_bytes (TREE_TYPE (DECL))<= mips_section_threshold	\&& mips_section_threshold> 0)					\     sdata_section ();							\   else if (TREE_CODE (DECL) == STRING_CST)				\     {									\       if (flag_writable_strings)					\ 	data_section ();						\       else								\ 	rdata_section ();						\     }									\   else if (TREE_CODE (DECL) != VAR_DECL)				\     rdata_section ();							\   else if (!TREE_READONLY (DECL))					\     data_section ();							\   else									\     rdata_section ();							\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),			\   sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do									\   {									\     fprintf (STREAM, "\tsubu\t%s,%s,8\n\tsw\t%s,0(%s)\n",		\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     reg_names[REGNO],						\ 	     reg_names[STACK_POINTER_REGNUM]);				\   }									\ while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do									\   {									\     if (! set_noreorder)						\       fprintf (STREAM, "\t.set\tnoreorder\n");				\ 									\     dslots_load_total++;						\     dslots_load_filled++;						\     fprintf (STREAM, "\tlw\t%s,0(%s)\n\taddu\t%s,%s,8\n",		\ 	     reg_names[REGNO],						\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     reg_names[STACK_POINTER_REGNUM],				\ 	     reg_names[STACK_POINTER_REGNUM]);				\ 									\     if (! set_noreorder)						\       fprintf (STREAM, "\t.set\treorder\n");				\   }									\ while (0)
end_define

begin_comment
comment|/* Define the parentheses used to group arithmetic operations    in assembler code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OPEN_PAREN
value|"("
end_define

begin_define
define|#
directive|define
name|ASM_CLOSE_PAREN
value|")"
end_define

begin_comment
comment|/* How to start an assembler comment.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_COMMENT_START
end_ifndef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"\t\t# "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Macros for mips-tfile.c to encapsulate stabs in ECOFF, and for    and mips-tdump.c to print them out.     These must match the corresponding definitions in gdb/mipsread.c.    Unfortunately, gcc and gdb do not currently share any directories. */
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
name|MIPS_IS_STAB
parameter_list|(
name|sym
parameter_list|)
value|(((sym)->index& 0xFFF00) == CODE_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS_MARK_STAB
parameter_list|(
name|code
parameter_list|)
value|((code)+CODE_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS_UNMARK_STAB
parameter_list|(
name|code
parameter_list|)
value|((code)-CODE_MASK)
end_define

begin_escape
end_escape

begin_comment
comment|/* Default definitions for size_t and ptrdiff_t.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

