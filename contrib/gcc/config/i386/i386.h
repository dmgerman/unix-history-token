begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler for IA-32.    Copyright (C) 1988, 1992, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* The purpose of this file is to define the characteristics of the i386,    independent of assembler syntax or operating system.     Three other files build on this one to describe a specific assembler syntax:    bsd386.h, att386.h, and sun386.h.     The actual tm.h file for a particular system should include    this file, and then the file for the appropriate assembler syntax.     Many macros that specify assembler syntax are omitted entirely from    this file because they really belong in the files for particular    assemblers.  These include RP, IP, LPREFIX, PUT_OP_SIZE, USE_STAR,    ADDR_BEG, ADDR_END, PRINT_IREG, PRINT_SCALE, PRINT_B_I_S, and many    that start with ASM_ or end in ASM_OP.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

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
value|error ("half-pic init called on systems that don't support it")
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
value|(X)
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

begin_comment
comment|/* Define the specific costs for a given cpu */
end_comment

begin_struct
struct|struct
name|processor_costs
block|{
specifier|const
name|int
name|add
decl_stmt|;
comment|/* cost of an add instruction */
specifier|const
name|int
name|lea
decl_stmt|;
comment|/* cost of a lea instruction */
specifier|const
name|int
name|shift_var
decl_stmt|;
comment|/* variable shift costs */
specifier|const
name|int
name|shift_const
decl_stmt|;
comment|/* constant shift costs */
specifier|const
name|int
name|mult_init
decl_stmt|;
comment|/* cost of starting a multiply */
specifier|const
name|int
name|mult_bit
decl_stmt|;
comment|/* cost of multiply per each bit set */
specifier|const
name|int
name|divide
decl_stmt|;
comment|/* cost of a divide/mod */
name|int
name|movsx
decl_stmt|;
comment|/* The cost of movsx operation.  */
name|int
name|movzx
decl_stmt|;
comment|/* The cost of movzx operation.  */
specifier|const
name|int
name|large_insn
decl_stmt|;
comment|/* insns larger than this cost more */
specifier|const
name|int
name|move_ratio
decl_stmt|;
comment|/* The threshold of number of scalar 				   memory-to-memory move insns.  */
specifier|const
name|int
name|movzbl_load
decl_stmt|;
comment|/* cost of loading using movzbl */
specifier|const
name|int
name|int_load
index|[
literal|3
index|]
decl_stmt|;
comment|/* cost of loading integer registers 				   in QImode, HImode and SImode relative 				   to reg-reg move (2).  */
specifier|const
name|int
name|int_store
index|[
literal|3
index|]
decl_stmt|;
comment|/* cost of storing integer register 				   in QImode, HImode and SImode */
specifier|const
name|int
name|fp_move
decl_stmt|;
comment|/* cost of reg,reg fld/fst */
specifier|const
name|int
name|fp_load
index|[
literal|3
index|]
decl_stmt|;
comment|/* cost of loading FP register 				   in SFmode, DFmode and XFmode */
specifier|const
name|int
name|fp_store
index|[
literal|3
index|]
decl_stmt|;
comment|/* cost of storing FP register 				   in SFmode, DFmode and XFmode */
specifier|const
name|int
name|mmx_move
decl_stmt|;
comment|/* cost of moving MMX register.  */
specifier|const
name|int
name|mmx_load
index|[
literal|2
index|]
decl_stmt|;
comment|/* cost of loading MMX register 				   in SImode and DImode */
specifier|const
name|int
name|mmx_store
index|[
literal|2
index|]
decl_stmt|;
comment|/* cost of storing MMX register 				   in SImode and DImode */
specifier|const
name|int
name|sse_move
decl_stmt|;
comment|/* cost of moving SSE register.  */
specifier|const
name|int
name|sse_load
index|[
literal|3
index|]
decl_stmt|;
comment|/* cost of loading SSE register 				   in SImode, DImode and TImode*/
specifier|const
name|int
name|sse_store
index|[
literal|3
index|]
decl_stmt|;
comment|/* cost of storing SSE register 				   in SImode, DImode and TImode*/
specifier|const
name|int
name|mmxsse_to_integer
decl_stmt|;
comment|/* cost of moving mmxsse register to 				   integer and vice versa.  */
specifier|const
name|int
name|prefetch_block
decl_stmt|;
comment|/* bytes moved to cache for prefetch.  */
specifier|const
name|int
name|simultaneous_prefetches
decl_stmt|;
comment|/* number of parallel prefetch 				   operations.  */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|processor_costs
modifier|*
name|ix86_cost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros used in the machine description to test the flags.  */
end_comment

begin_comment
comment|/* configure can arrange to make this 2, to force a 486.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CPU_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Masks for the -m switches */
end_comment

begin_define
define|#
directive|define
name|MASK_80387
value|0x00000001
end_define

begin_comment
comment|/* Hardware floating point */
end_comment

begin_define
define|#
directive|define
name|MASK_RTD
value|0x00000002
end_define

begin_comment
comment|/* Use ret that pops args */
end_comment

begin_define
define|#
directive|define
name|MASK_ALIGN_DOUBLE
value|0x00000004
end_define

begin_comment
comment|/* align doubles to 2 word boundary */
end_comment

begin_define
define|#
directive|define
name|MASK_SVR3_SHLIB
value|0x00000008
end_define

begin_comment
comment|/* Uninit locals into bss */
end_comment

begin_define
define|#
directive|define
name|MASK_IEEE_FP
value|0x00000010
end_define

begin_comment
comment|/* IEEE fp comparisons */
end_comment

begin_define
define|#
directive|define
name|MASK_FLOAT_RETURNS
value|0x00000020
end_define

begin_comment
comment|/* Return float in st(0) */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_FANCY_MATH_387
value|0x00000040
end_define

begin_comment
comment|/* Disable sin, cos, sqrt */
end_comment

begin_define
define|#
directive|define
name|MASK_OMIT_LEAF_FRAME_POINTER
value|0x080
end_define

begin_comment
comment|/* omit leaf frame pointers */
end_comment

begin_define
define|#
directive|define
name|MASK_STACK_PROBE
value|0x00000100
end_define

begin_comment
comment|/* Enable stack probing */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_ALIGN_STROPS
value|0x00000200
end_define

begin_comment
comment|/* Enable aligning of string ops.  */
end_comment

begin_define
define|#
directive|define
name|MASK_INLINE_ALL_STROPS
value|0x00000400
end_define

begin_comment
comment|/* Inline stringops in all cases */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_PUSH_ARGS
value|0x00000800
end_define

begin_comment
comment|/* Use push instructions */
end_comment

begin_define
define|#
directive|define
name|MASK_ACCUMULATE_OUTGOING_ARGS
value|0x00001000
end_define

begin_comment
comment|/* Accumulate outgoing args */
end_comment

begin_define
define|#
directive|define
name|MASK_ACCUMULATE_OUTGOING_ARGS_SET
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MASK_MMX
value|0x00004000
end_define

begin_comment
comment|/* Support MMX regs/builtins */
end_comment

begin_define
define|#
directive|define
name|MASK_MMX_SET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MASK_SSE
value|0x00010000
end_define

begin_comment
comment|/* Support SSE regs/builtins */
end_comment

begin_define
define|#
directive|define
name|MASK_SSE_SET
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MASK_SSE2
value|0x00040000
end_define

begin_comment
comment|/* Support SSE2 regs/builtins */
end_comment

begin_define
define|#
directive|define
name|MASK_SSE2_SET
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MASK_3DNOW
value|0x00100000
end_define

begin_comment
comment|/* Support 3Dnow builtins */
end_comment

begin_define
define|#
directive|define
name|MASK_3DNOW_SET
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MASK_3DNOW_A
value|0x00400000
end_define

begin_comment
comment|/* Support Athlon 3Dnow builtins */
end_comment

begin_define
define|#
directive|define
name|MASK_3DNOW_A_SET
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MASK_128BIT_LONG_DOUBLE
value|0x01000000
end_define

begin_comment
comment|/* long double size is 128bit */
end_comment

begin_define
define|#
directive|define
name|MASK_64BIT
value|0x02000000
end_define

begin_comment
comment|/* Produce 64bit code */
end_comment

begin_comment
comment|/* ... overlap with subtarget options starts by 0x04000000.  */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_RED_ZONE
value|0x04000000
end_define

begin_comment
comment|/* Do not use red zone */
end_comment

begin_comment
comment|/* Use the floating point instructions */
end_comment

begin_define
define|#
directive|define
name|TARGET_80387
value|(target_flags& MASK_80387)
end_define

begin_comment
comment|/* Compile using ret insn that pops args.    This will not work unless you use prototypes at least    for all functions that can take varying numbers of args.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_RTD
value|(target_flags& MASK_RTD)
end_define

begin_comment
comment|/* Align doubles to a two word boundary.  This breaks compatibility with    the published ABI's for structures containing doubles, but produces    faster code on the pentium.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ALIGN_DOUBLE
value|(target_flags& MASK_ALIGN_DOUBLE)
end_define

begin_comment
comment|/* Use push instructions to save outgoing args.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PUSH_ARGS
value|(!(target_flags& MASK_NO_PUSH_ARGS))
end_define

begin_comment
comment|/* Accumulate stack adjustments to prologue/epilogue.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ACCUMULATE_OUTGOING_ARGS
define|\
value|(target_flags& MASK_ACCUMULATE_OUTGOING_ARGS)
end_define

begin_comment
comment|/* Put uninitialized locals into bss, not data.    Meaningful only on svr3.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SVR3_SHLIB
value|(target_flags& MASK_SVR3_SHLIB)
end_define

begin_comment
comment|/* Use IEEE floating point comparisons.  These handle correctly the cases    where the result of a comparison is unordered.  Normally SIGFPE is    generated in such cases, in which case this isn't needed.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_IEEE_FP
value|(target_flags& MASK_IEEE_FP)
end_define

begin_comment
comment|/* Functions that return a floating point value may return that value    in the 387 FPU or in 386 integer registers.  If set, this flag causes    the 387 to be used, which is compatible with most calling conventions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLOAT_RETURNS_IN_80387
value|(target_flags& MASK_FLOAT_RETURNS)
end_define

begin_comment
comment|/* Long double is 128bit instead of 96bit, even when only 80bits are used.    This mode wastes cache, but avoid misaligned data accesses and simplifies    address calculations.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_128BIT_LONG_DOUBLE
value|(target_flags& MASK_128BIT_LONG_DOUBLE)
end_define

begin_comment
comment|/* Disable generation of FP sin, cos and sqrt operations for 387.    This is because FreeBSD lacks these in the math-emulator-code */
end_comment

begin_define
define|#
directive|define
name|TARGET_NO_FANCY_MATH_387
value|(target_flags& MASK_NO_FANCY_MATH_387)
end_define

begin_comment
comment|/* Don't create frame pointers for leaf functions */
end_comment

begin_define
define|#
directive|define
name|TARGET_OMIT_LEAF_FRAME_POINTER
define|\
value|(target_flags& MASK_OMIT_LEAF_FRAME_POINTER)
end_define

begin_comment
comment|/* Debug GO_IF_LEGITIMATE_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEBUG_ADDR
value|(ix86_debug_addr_string != 0)
end_define

begin_comment
comment|/* Debug FUNCTION_ARG macros */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEBUG_ARG
value|(ix86_debug_arg_string != 0)
end_define

begin_comment
comment|/* 64bit Sledgehammer mode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_BI_ARCH
end_ifdef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|(target_flags& MASK_64BIT)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_64BIT_DEFAULT
end_ifdef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_64BIT
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

begin_define
define|#
directive|define
name|TARGET_386
value|(ix86_cpu == PROCESSOR_I386)
end_define

begin_define
define|#
directive|define
name|TARGET_486
value|(ix86_cpu == PROCESSOR_I486)
end_define

begin_define
define|#
directive|define
name|TARGET_PENTIUM
value|(ix86_cpu == PROCESSOR_PENTIUM)
end_define

begin_define
define|#
directive|define
name|TARGET_PENTIUMPRO
value|(ix86_cpu == PROCESSOR_PENTIUMPRO)
end_define

begin_define
define|#
directive|define
name|TARGET_K6
value|(ix86_cpu == PROCESSOR_K6)
end_define

begin_define
define|#
directive|define
name|TARGET_ATHLON
value|(ix86_cpu == PROCESSOR_ATHLON)
end_define

begin_define
define|#
directive|define
name|TARGET_PENTIUM4
value|(ix86_cpu == PROCESSOR_PENTIUM4)
end_define

begin_define
define|#
directive|define
name|CPUMASK
value|(1<< ix86_cpu)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_leave
decl_stmt|,
name|x86_push_memory
decl_stmt|,
name|x86_zero_extend_with_and
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_bit_test
decl_stmt|,
name|x86_cmove
decl_stmt|,
name|x86_deep_branch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_branch_hints
decl_stmt|,
name|x86_unroll_strlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_double_with_add
decl_stmt|,
name|x86_partial_reg_stall
decl_stmt|,
name|x86_movx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_loop
decl_stmt|,
name|x86_use_fiop
decl_stmt|,
name|x86_use_mov0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_cltd
decl_stmt|,
name|x86_read_modify_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_read_modify
decl_stmt|,
name|x86_split_long_moves
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_promote_QImode
decl_stmt|,
name|x86_single_stringop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_himode_math
decl_stmt|,
name|x86_qimode_math
decl_stmt|,
name|x86_promote_qi_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_promote_hi_regs
decl_stmt|,
name|x86_integer_DFmode_moves
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_add_esp_4
decl_stmt|,
name|x86_add_esp_8
decl_stmt|,
name|x86_sub_esp_4
decl_stmt|,
name|x86_sub_esp_8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_partial_reg_dependency
decl_stmt|,
name|x86_memory_mismatch_stall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_accumulate_outgoing_args
decl_stmt|,
name|x86_prologue_using_move
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_epilogue_using_move
decl_stmt|,
name|x86_decompose_lea
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x86_prefetch_sse
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_USE_LEAVE
value|(x86_use_leave& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PUSH_MEMORY
value|(x86_push_memory& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_ZERO_EXTEND_WITH_AND
value|(x86_zero_extend_with_and& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_BIT_TEST
value|(x86_use_bit_test& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_UNROLL_STRLEN
value|(x86_unroll_strlen& CPUMASK)
end_define

begin_comment
comment|/* For sane SSE instruction set generation we need fcomi instruction.  It is    safe to enable all CMOVE instructions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CMOVE
value|((x86_cmove& (1<< ix86_arch)) || TARGET_SSE)
end_define

begin_define
define|#
directive|define
name|TARGET_DEEP_BRANCH_PREDICTION
value|(x86_deep_branch& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_BRANCH_PREDICTION_HINTS
value|(x86_branch_hints& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_DOUBLE_WITH_ADD
value|(x86_double_with_add& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_SAHF
value|((x86_use_sahf& CPUMASK)&& !TARGET_64BIT)
end_define

begin_define
define|#
directive|define
name|TARGET_MOVX
value|(x86_movx& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PARTIAL_REG_STALL
value|(x86_partial_reg_stall& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_LOOP
value|(x86_use_loop& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_FIOP
value|(x86_use_fiop& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_MOV0
value|(x86_use_mov0& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_CLTD
value|(x86_use_cltd& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SPLIT_LONG_MOVES
value|(x86_split_long_moves& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_READ_MODIFY_WRITE
value|(x86_read_modify_write& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_READ_MODIFY
value|(x86_read_modify& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_QImode
value|(x86_promote_QImode& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SINGLE_STRINGOP
value|(x86_single_stringop& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_QIMODE_MATH
value|(x86_qimode_math& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_HIMODE_MATH
value|(x86_himode_math& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_QI_REGS
value|(x86_promote_qi_regs& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_HI_REGS
value|(x86_promote_hi_regs& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_ADD_ESP_4
value|(x86_add_esp_4& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_ADD_ESP_8
value|(x86_add_esp_8& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SUB_ESP_4
value|(x86_sub_esp_4& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SUB_ESP_8
value|(x86_sub_esp_8& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_INTEGER_DFMODE_MOVES
value|(x86_integer_DFmode_moves& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PARTIAL_REG_DEPENDENCY
value|(x86_partial_reg_dependency& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_MEMORY_MISMATCH_STALL
value|(x86_memory_mismatch_stall& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROLOGUE_USING_MOVE
value|(x86_prologue_using_move& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_EPILOGUE_USING_MOVE
value|(x86_epilogue_using_move& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_DECOMPOSE_LEA
value|(x86_decompose_lea& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PREFETCH_SSE
value|(x86_prefetch_sse)
end_define

begin_define
define|#
directive|define
name|TARGET_STACK_PROBE
value|(target_flags& MASK_STACK_PROBE)
end_define

begin_define
define|#
directive|define
name|TARGET_ALIGN_STRINGOPS
value|(!(target_flags& MASK_NO_ALIGN_STROPS))
end_define

begin_define
define|#
directive|define
name|TARGET_INLINE_ALL_STRINGOPS
value|(target_flags& MASK_INLINE_ALL_STROPS)
end_define

begin_define
define|#
directive|define
name|ASSEMBLER_DIALECT
value|(ix86_asm_dialect)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE
value|((target_flags& (MASK_SSE | MASK_SSE2)) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE2
value|((target_flags& MASK_SSE2) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE_MATH
value|((ix86_fpmath& FPMATH_SSE) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_MIX_SSE_I387
value|((ix86_fpmath& FPMATH_SSE) \&& (ix86_fpmath& FPMATH_387))
end_define

begin_define
define|#
directive|define
name|TARGET_MMX
value|((target_flags& MASK_MMX) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_3DNOW
value|((target_flags& MASK_3DNOW) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_3DNOW_A
value|((target_flags& MASK_3DNOW_A) != 0)
end_define

begin_define
define|#
directive|define
name|TARGET_RED_ZONE
value|(!(target_flags& MASK_NO_RED_ZONE))
end_define

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "80387",			 MASK_80387, N_("Use hardware fp") },	      \   { "no-80387",			-MASK_80387, N_("Do not use hardware fp") },  \   { "hard-float",		 MASK_80387, N_("Use hardware fp") },	      \   { "soft-float",		-MASK_80387, N_("Do not use hardware fp") },  \   { "no-soft-float",		 MASK_80387, N_("Use hardware fp") },	      \   { "386",			 0, N_("")
comment|/*Deprecated.*/
value|},		      \   { "486",			 0, N_("")
comment|/*Deprecated.*/
value|},		      \   { "pentium",			 0, N_("")
comment|/*Deprecated.*/
value|},		      \   { "pentiumpro",		 0, N_("")
comment|/*Deprecated.*/
value|},		      \   { "intel-syntax",		 0, N_("")
comment|/*Deprecated.*/
value|},	 	      \   { "no-intel-syntax",		 0, N_("")
comment|/*Deprecated.*/
value|},	 	      \   { "rtd",			 MASK_RTD,				      \     N_("Alternate calling convention") },				      \   { "no-rtd",			-MASK_RTD,				      \     N_("Use normal calling convention") },				      \   { "align-double",		 MASK_ALIGN_DOUBLE,			      \     N_("Align some doubles on dword boundary") },			      \   { "no-align-double",		-MASK_ALIGN_DOUBLE,			      \     N_("Align doubles on word boundary") },				      \   { "svr3-shlib",		 MASK_SVR3_SHLIB,			      \     N_("Uninitialized locals in .bss")  },				      \   { "no-svr3-shlib",		-MASK_SVR3_SHLIB,			      \     N_("Uninitialized locals in .data") },				      \   { "ieee-fp",			 MASK_IEEE_FP,				      \     N_("Use IEEE math for fp comparisons") },				      \   { "no-ieee-fp",		-MASK_IEEE_FP,				      \     N_("Do not use IEEE math for fp comparisons") },			      \   { "fp-ret-in-387",		 MASK_FLOAT_RETURNS,			      \     N_("Return values of functions in FPU registers") },		      \   { "no-fp-ret-in-387",		-MASK_FLOAT_RETURNS ,			      \     N_("Do not return values of functions in FPU registers")},		      \   { "no-fancy-math-387",	 MASK_NO_FANCY_MATH_387,		      \     N_("Do not generate sin, cos, sqrt for FPU") },			      \   { "fancy-math-387",		-MASK_NO_FANCY_MATH_387,		      \      N_("Generate sin, cos, sqrt for FPU")},				      \   { "omit-leaf-frame-pointer",	 MASK_OMIT_LEAF_FRAME_POINTER,		      \     N_("Omit the frame pointer in leaf functions") },			      \   { "no-omit-leaf-frame-pointer",-MASK_OMIT_LEAF_FRAME_POINTER, "" },	      \   { "stack-arg-probe",		 MASK_STACK_PROBE,			      \     N_("Enable stack probing") },					      \   { "no-stack-arg-probe",	-MASK_STACK_PROBE, "" },		      \   { "windows",			0, 0
comment|/* undocumented */
value|},		      \   { "dll",			0,  0
comment|/* undocumented */
value|},		      \   { "align-stringops",		-MASK_NO_ALIGN_STROPS,			      \     N_("Align destination of the string operations") },			      \   { "no-align-stringops",	 MASK_NO_ALIGN_STROPS,			      \     N_("Do not align destination of the string operations") },		      \   { "inline-all-stringops",	 MASK_INLINE_ALL_STROPS,		      \     N_("Inline all known string operations") },				      \   { "no-inline-all-stringops",	-MASK_INLINE_ALL_STROPS,		      \     N_("Do not inline all known string operations") },			      \   { "push-args",		-MASK_NO_PUSH_ARGS,			      \     N_("Use push instructions to save outgoing arguments") },		      \   { "no-push-args",		MASK_NO_PUSH_ARGS,			      \     N_("Do not use push instructions to save outgoing arguments") },	      \   { "accumulate-outgoing-args",	(MASK_ACCUMULATE_OUTGOING_ARGS		      \ 				 | MASK_ACCUMULATE_OUTGOING_ARGS_SET),	      \     N_("Use push instructions to save outgoing arguments") },		      \   { "no-accumulate-outgoing-args",MASK_ACCUMULATE_OUTGOING_ARGS_SET,	      \     N_("Do not use push instructions to save outgoing arguments") },	      \   { "mmx",			 MASK_MMX | MASK_MMX_SET,		      \     N_("Support MMX built-in functions") },				      \   { "no-mmx",			 -MASK_MMX,				      \     N_("Do not support MMX built-in functions") },			      \   { "no-mmx",			 MASK_MMX_SET, N_("") },		      \   { "3dnow",                     MASK_3DNOW | MASK_3DNOW_SET,		      \     N_("Support 3DNow! built-in functions") },				      \   { "no-3dnow",                  -MASK_3DNOW, N_("") },			      \   { "no-3dnow",                  MASK_3DNOW_SET,			      \     N_("Do not support 3DNow! built-in functions") },			      \   { "sse",			 MASK_SSE | MASK_SSE_SET,		      \     N_("Support MMX and SSE built-in functions and code generation") },	      \   { "no-sse",			 -MASK_SSE, N_("") },	 		      \   { "no-sse",			 MASK_SSE_SET,				      \     N_("Do not support MMX and SSE built-in functions and code generation") },\   { "sse2",			 MASK_SSE2 | MASK_SSE2_SET,		      \     N_("Support MMX, SSE and SSE2 built-in functions and code generation") }, \   { "no-sse2",			 -MASK_SSE2, N_("") },			      \   { "no-sse2",			 MASK_SSE2_SET,				      \     N_("Do not support MMX, SSE and SSE2 built-in functions and code generation") },    \   { "128bit-long-double",	 MASK_128BIT_LONG_DOUBLE,		      \     N_("sizeof(long double) is 16") },					      \   { "96bit-long-double",	-MASK_128BIT_LONG_DOUBLE,		      \     N_("sizeof(long double) is 12") },					      \   { "64",			MASK_64BIT,				      \     N_("Generate 64bit x86-64 code") },					      \   { "32",			-MASK_64BIT,				      \     N_("Generate 32bit i386 code") },					      \   { "red-zone",			-MASK_NO_RED_ZONE,			      \     N_("Use red-zone in the x86-64 code") },				      \   { "no-red-zone",		MASK_NO_RED_ZONE,			      \     N_("Do not use red-zone in the x86-64 code") },			      \   SUBTARGET_SWITCHES							      \   { "", TARGET_DEFAULT, 0 }}
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_64BIT_DEFAULT
end_ifdef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_64BIT | TARGET_SUBTARGET_DEFAULT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|TARGET_SUBTARGET_DEFAULT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Which processor to schedule for. The cpu attribute defines a list that    mirrors this list, so changes to i386.md must be made at the same time.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_I386
block|,
comment|/* 80386 */
name|PROCESSOR_I486
block|,
comment|/* 80486DX, 80486SX, 80486DX[24] */
name|PROCESSOR_PENTIUM
block|,
name|PROCESSOR_PENTIUMPRO
block|,
name|PROCESSOR_K6
block|,
name|PROCESSOR_ATHLON
block|,
name|PROCESSOR_PENTIUM4
block|,
name|PROCESSOR_max
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fpmath_unit
block|{
name|FPMATH_387
init|=
literal|1
block|,
name|FPMATH_SSE
init|=
literal|2
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|ix86_cpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|fpmath_unit
name|ix86_fpmath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ix86_arch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This macro is similar to `TARGET_SWITCHES' but defines names of    command options that have values.  Its definition is an    initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    fixed part of the option name, and the address of a variable.  The    variable, type `char *', is set to the variable part of the given    option if the fixed part matches.  The actual option name is made    by appending `-m' to the specified name.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{ { "cpu=",&ix86_cpu_string,			\     N_("Schedule code for given CPU")},				\   { "fpmath=",&ix86_fpmath_string,			\     N_("Generate floating point mathematics using given instruction set")},\   { "arch=",&ix86_arch_string,			\     N_("Generate code for given CPU")},				\   { "regparm=",&ix86_regparm_string,			\     N_("Number of registers used to pass integer arguments") },	\   { "align-loops=",&ix86_align_loops_string,		\     N_("Loop code aligned to this power of 2") },		\   { "align-jumps=",&ix86_align_jumps_string,		\     N_("Jump targets are aligned to this power of 2") },	\   { "align-functions=",&ix86_align_funcs_string,		\     N_("Function starts are aligned to this power of 2") },	\   { "preferred-stack-boundary=",				\&ix86_preferred_stack_boundary_string,			\     N_("Attempt to keep stack aligned to this power of 2") },	\   { "branch-cost=",&ix86_branch_cost_string,		\     N_("Branches are this expensive (1-5, arbitrary units)") },	\   { "cmodel=",&ix86_cmodel_string,				\     N_("Use given x86-64 code model") },			\   { "debug-arg",&ix86_debug_arg_string,			\     N_(""
comment|/* Undocumented. */
value|) },				\   { "debug-addr",&ix86_debug_addr_string,			\     N_(""
comment|/* Undocumented. */
value|) },				\   { "asm=",&ix86_asm_string,					\     N_("Use given assembler dialect") },			\   SUBTARGET_OPTIONS						\ }
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make    sense on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.     Don't use this macro to turn on various extra optimizations for    `-O'.  That is what `OPTIMIZATION_OPTIONS' is for.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|override_options ()
end_define

begin_comment
comment|/* These are meant to be redefined in the host dependent files */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
end_define

begin_define
define|#
directive|define
name|SUBTARGET_OPTIONS
end_define

begin_comment
comment|/* Define this to change the optimizations performed by default.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|optimization_options ((LEVEL), (SIZE))
end_define

begin_comment
comment|/* Specs for the compiler proper */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CC1_CPU_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CC1_CPU_SPEC
value|"\ %{!mcpu*: \ %{m386:-mcpu=i386 \ %n`-m386' is deprecated. Use `-march=i386' or `-mcpu=i386' instead.\n} \ %{m486:-mcpu=i486 \ %n`-m486' is deprecated. Use `-march=i486' or `-mcpu=i486' instead.\n} \ %{mpentium:-mcpu=pentium \ %n`-mpentium' is deprecated. Use `-march=pentium' or `-mcpu=pentium' instead.\n} \ %{mpentiumpro:-mcpu=pentiumpro \ %n`-mpentiumpro' is deprecated. Use `-march=pentiumpro' or `-mcpu=pentiumpro' instead.\n}} \ %{mintel-syntax:-masm=intel \ %n`-mintel-syntax' is deprecated. Use `-masm=intel' instead.\n} \ %{mno-intel-syntax:-masm=att \ %n`-mno-intel-syntax' is deprecated. Use `-masm=att' instead.\n}"
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
name|TARGET_CPU_DEFAULT_i386
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_i486
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_pentium
value|2
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_pentium_mmx
value|3
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_pentiumpro
value|4
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_pentium2
value|5
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_pentium3
value|6
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_pentium4
value|7
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_k6
value|8
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_k6_2
value|9
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_k6_3
value|10
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_athlon
value|11
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_athlon_sse
value|12
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_NAMES
value|{"i386", "i486", "pentium", "pentium-mmx",\ 				  "pentiumpro", "pentium2", "pentium3", \ 				  "pentium4", "k6", "k6-2", "k6-3",\ 				  "athlon", "athlon-4"}
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_CPU_DEFAULT_SPEC
end_ifndef

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_i486
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_i486__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_pentium
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_i586__ -D__tune_pentium__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_pentium_mmx
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_i586__ -D__tune_pentium__ -D__tune_pentium_mmx__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_pentiumpro
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_i686__ -D__tune_pentiumpro__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_pentium2
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_i686__ -D__tune_pentiumpro__\ -D__tune_pentium2__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_pentium3
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_i686__ -D__tune_pentiumpro__\ -D__tune_pentium2__ -D__tune_pentium3__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_pentium4
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_pentium4__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_k6
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_k6__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_k6_2
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_k6__ -D__tune_k6_2__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_k6_3
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_k6__ -D__tune_k6_3__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_athlon
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_athlon__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_DEFAULT_athlon_sse
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_athlon__ -D__tune_athlon_sse__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_CPU_DEFAULT_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"-D__tune_i386__"
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
comment|/* CPP_CPU_DEFAULT_SPEC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_BI_ARCH
end_ifdef

begin_define
define|#
directive|define
name|NO_BUILTIN_SIZE_TYPE
end_define

begin_define
define|#
directive|define
name|NO_BUILTIN_PTRDIFF_TYPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_BUILTIN_SIZE_TYPE
end_ifdef

begin_define
define|#
directive|define
name|CPP_CPU32_SIZE_TYPE_SPEC
define|\
value|" -D__SIZE_TYPE__=unsigned\\ int -D__PTRDIFF_TYPE__=int"
end_define

begin_define
define|#
directive|define
name|CPP_CPU64_SIZE_TYPE_SPEC
define|\
value|" -D__SIZE_TYPE__=unsigned\\ long\\ int -D__PTRDIFF_TYPE__=long\\ int"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_CPU32_SIZE_TYPE_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|CPP_CPU64_SIZE_TYPE_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_CPU32_SPEC
define|\
value|"-Acpu=i386 -Amachine=i386 %{!ansi:%{!std=c*:%{!std=i*:-Di386}}} -D__i386 \ -D__i386__ %(cpp_cpu32sizet)"
end_define

begin_define
define|#
directive|define
name|CPP_CPU64_SPEC
define|\
value|"-Acpu=x86_64 -Amachine=x86_64 -D__x86_64 -D__x86_64__ %(cpp_cpu64sizet)"
end_define

begin_define
define|#
directive|define
name|CPP_CPUCOMMON_SPEC
value|"\ %{march=i386:%{!mcpu*:-D__tune_i386__ }}\ %{march=i486:-D__i486 -D__i486__ %{!mcpu*:-D__tune_i486__ }}\ %{march=pentium|march=i586:-D__i586 -D__i586__ -D__pentium -D__pentium__ \   %{!mcpu*:-D__tune_i586__ -D__tune_pentium__ }}\ %{march=pentium-mmx:-D__i586 -D__i586__ -D__pentium -D__pentium__ \   -D__pentium__mmx__ \   %{!mcpu*:-D__tune_i586__ -D__tune_pentium__ -D__tune_pentium_mmx__}}\ %{march=pentiumpro|march=i686:-D__i686 -D__i686__ \   -D__pentiumpro -D__pentiumpro__ \   %{!mcpu*:-D__tune_i686__ -D__tune_pentiumpro__ }}\ %{march=k6:-D__k6 -D__k6__ %{!mcpu*:-D__tune_k6__ }}\ %{march=k6-2:-D__k6 -D__k6__ -D__k6_2__ \   %{!mcpu*:-D__tune_k6__ -D__tune_k6_2__ }}\ %{march=k6-3:-D__k6 -D__k6__ -D__k6_3__ \   %{!mcpu*:-D__tune_k6__ -D__tune_k6_3__ }}\ %{march=athlon|march=athlon-tbird:-D__athlon -D__athlon__ \   %{!mcpu*:-D__tune_athlon__ }}\ %{march=athlon-4|march=athlon-xp|march=athlon-mp:-D__athlon -D__athlon__ \   -D__athlon_sse__ \   %{!mcpu*:-D__tune_athlon__ -D__tune_athlon_sse__ }}\ %{march=pentium4:-D__pentium4 -D__pentium4__ %{!mcpu*:-D__tune_pentium4__ }}\ %{m386|mcpu=i386:-D__tune_i386__ }\ %{m486|mcpu=i486:-D__tune_i486__ }\ %{mpentium|mcpu=pentium|mcpu=i586|mcpu=pentium-mmx:-D__tune_i586__ -D__tune_pentium__ }\ %{mpentiumpro|mcpu=pentiumpro|mcpu=i686|cpu=pentium2|cpu=pentium3:-D__tune_i686__ \ -D__tune_pentiumpro__ }\ %{mcpu=k6|mcpu=k6-2|mcpu=k6-3:-D__tune_k6__ }\ %{mcpu=athlon|mcpu=athlon-tbird|mcpu=athlon-4|mcpu=athlon-xp|mcpu=athlon-mp:\ -D__tune_athlon__ }\ %{mcpu=athlon-4|mcpu=athlon-xp|mcpu=athlon-mp:\ -D__tune_athlon_sse__ }\ %{mcpu=pentium4:-D__tune_pentium4__ }\ %{march=athlon-tbird|march=athlon-xp|march=athlon-mp|march=pentium3|march=pentium4:\ -D__SSE__ }\ %{march=pentium-mmx|march=k6|march=k6-2|march=k6-3\ march=athlon|march=athlon-tbird|march=athlon-4|march=athlon-xp\ |march=athlon-mp|march=pentium2|march=pentium3|march=pentium4: -D__MMX__ }\ %{march=k6-2|march=k6-3\ march=athlon|march=athlon-tbird|march=athlon-4|march=athlon-xp\ |march=athlon-mp: -D__3dNOW__ }\ %{march=athlon|march=athlon-tbird|march=athlon-4|march=athlon-xp\ |march=athlon-mp: -D__3dNOW_A__ }\ %{march=pentium4: -D__SSE2__ }\ %{!march*:%{!mcpu*:%{!m386:%{!m486:%{!mpentium*:%(cpp_cpu_default)}}}}}"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_CPU_SPEC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_BI_ARCH
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_64BIT_DEFAULT
end_ifdef

begin_define
define|#
directive|define
name|CPP_CPU_SPEC
value|"%{m32:%(cpp_cpu32)}%{!m32:%(cpp_cpu64)} %(cpp_cpucommon)"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_CPU_SPEC
value|"%{m64:%(cpp_cpu64)}%{!m64:%(cpp_cpu32)} %(cpp_cpucommon)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_64BIT_DEFAULT
end_ifdef

begin_define
define|#
directive|define
name|CPP_CPU_SPEC
value|"%(cpp_cpu64) %(cpp_cpucommon)"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_CPU_SPEC
value|"%(cpp_cpu32) %(cpp_cpucommon)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CC1_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%(cc1_cpu) "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro defines names of additional specifications to put in the    specs that can be used in various specifications like CC1_SPEC.  Its    definition is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GNU CC driver    program.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_SPECS
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "cpp_cpu_default",	CPP_CPU_DEFAULT_SPEC },				\   { "cpp_cpu",	CPP_CPU_SPEC },						\   { "cpp_cpu32", CPP_CPU32_SPEC },					\   { "cpp_cpu64", CPP_CPU64_SPEC },					\   { "cpp_cpu32sizet", CPP_CPU32_SIZE_TYPE_SPEC },			\   { "cpp_cpu64sizet", CPP_CPU64_SIZE_TYPE_SPEC },			\   { "cpp_cpucommon", CPP_CPUCOMMON_SPEC },				\   { "cc1_cpu",  CC1_CPU_SPEC },						\   SUBTARGET_EXTRA_SPECS
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define for XFmode or TFmode extended real floating point support.    This will automatically cause REAL_ARITHMETIC to be defined.      The XFmode is specified by i386 ABI, while TFmode may be faster    due to alignment and simplifications in the address calculations.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(TARGET_128BIT_LONG_DOUBLE ? 128 : 96)
end_define

begin_define
define|#
directive|define
name|MAX_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|96
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tell real.c that this is the 80-bit Intel extended float format    packaged in a 128-bit or 96bit entity.  */
end_comment

begin_define
define|#
directive|define
name|INTEL_EXTENDED_IEEE_FORMAT
value|1
end_define

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_define
define|#
directive|define
name|MAX_WCHAR_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|DOUBLE_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|64
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_BI_ARCH
argument_list|)
operator|||
name|defined
argument_list|(
name|TARGET_64BIT_DEFAULT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
value|64
end_define

begin_define
define|#
directive|define
name|MAX_LONG_TYPE_SIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
value|32
end_define

begin_define
define|#
directive|define
name|MAX_LONG_TYPE_SIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you don't want extended real, but do want to use the    software floating point emulator for REAL_ARITHMETIC and    decimal<-> binary conversion.  */
end_comment

begin_comment
comment|/* #define REAL_ARITHMETIC */
end_comment

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* That is true on the 80386.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* That is not true on the 80386.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is the lowest    numbered.  */
end_comment

begin_comment
comment|/* Not true for 80386 */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* number of bits in an addressable storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 80386, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|(TARGET_64BIT ? 64 : 32)
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_define
define|#
directive|define
name|MIN_UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Boundary (in *bits*) on which the stack pointer preferrs to be    aligned; the compiler cannot rely on having this alignment.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_STACK_BOUNDARY
value|ix86_preferred_stack_boundary
end_define

begin_comment
comment|/* As of July 2001, many runtimes to not align the stack properly when    entering main.  This causes expand_main_function to forcably align    the stack, which results in aligned frames for functions called from    main, though it does nothing for the alignment of main itself.  */
end_comment

begin_define
define|#
directive|define
name|FORCE_PREFERRED_STACK_BOUNDARY_IN_MAIN
define|\
value|(ix86_preferred_stack_boundary> STACK_BOUNDARY&& !TARGET_64BIT)
end_define

begin_comment
comment|/* Allocation boundary for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|16
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Minimum size in bits of the largest boundary to which any    and all fundamental data types supported by the hardware    might need to be aligned. No data type wants to be aligned    rounder than this.        Pentium+ preferrs DFmode values to be aligned to 64 bit boundary    and Pentium Pro XFmode values at 128 bit boundaries.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|128
end_define

begin_comment
comment|/* Decide whether a variable of mode MODE must be 128 bit aligned.  */
end_comment

begin_define
define|#
directive|define
name|ALIGN_MODE_128
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == XFmode || (MODE) == TFmode || ((MODE) == TImode) \   || (MODE) == V4SFmode	|| (MODE) == V4SImode)
end_define

begin_comment
comment|/* The published ABIs say that doubles should be aligned on word    boundaries, so lower the aligment for structure fields unless    -malign-double is set.  */
end_comment

begin_comment
comment|/* BIGGEST_FIELD_ALIGNMENT is also used in libobjc, where it must be    constant.  Use the smaller value in that context.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN_TARGET_LIBS
end_ifndef

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|(TARGET_64BIT ? 128 : (TARGET_ALIGN_DOUBLE ? 64 : 32))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If defined, a C expression to compute the alignment given to a    constant that is being placed in memory.  EXP is the constant    and ALIGN is the alignment that the object would ordinarily have.    The value of this macro is used instead of that alignment to align    the object.     If this macro is not defined, then ALIGN is used.     The typical use of this macro is to increase alignment for string    constants to be word aligned so that `strcpy' calls that copy    constants can be done inline.  */
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
value|ix86_constant_alignment ((EXP), (ALIGN))
end_define

begin_comment
comment|/* If defined, a C expression to compute the alignment for a static    variable.  TYPE is the data type, and ALIGN is the alignment that    the object would ordinarily have.  The value of this macro is used    instead of that alignment to align the object.     If this macro is not defined, then ALIGN is used.     One use of this macro is to increase alignment of medium-size    data to make it all fit in fewer cache lines.  Another is to    cause character arrays to be word-aligned so that `strcpy' calls    that copy constants to character arrays can be done inline.  */
end_comment

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|TYPE
parameter_list|,
name|ALIGN
parameter_list|)
value|ix86_data_alignment ((TYPE), (ALIGN))
end_define

begin_comment
comment|/* If defined, a C expression to compute the alignment for a local    variable.  TYPE is the data type, and ALIGN is the alignment that    the object would ordinarily have.  The value of this macro is used    instead of that alignment to align the object.     If this macro is not defined, then ALIGN is used.     One use of this macro is to increase alignment of medium-size    data to make it all fit in fewer cache lines.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_ALIGNMENT
parameter_list|(
name|TYPE
parameter_list|,
name|ALIGN
parameter_list|)
value|ix86_local_alignment ((TYPE), (ALIGN))
end_define

begin_comment
comment|/* If defined, a C expression that gives the alignment boundary, in    bits, of an argument with the specified mode and type.  If it is    not defined, `PARM_BOUNDARY' is used for all arguments.  */
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
value|ix86_function_arg_boundary ((MODE), (TYPE))
end_define

begin_comment
comment|/* Set this non-zero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|0
end_define

begin_comment
comment|/* If bit field type is int, don't let it cross an int,    and give entire struct the alignment of an int.  */
end_comment

begin_comment
comment|/* Required on the 386 since it doesn't have bitfield insns.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* This processor has special stack-like registers.  See reg-stack.c    for details.  */
end_comment

begin_define
define|#
directive|define
name|STACK_REGS
end_define

begin_define
define|#
directive|define
name|IS_STACK_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == DFmode || (MODE) == SFmode || (MODE) == XFmode	\    || (MODE) == TFmode)
end_define

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     In the 80386 we give the 8 general purpose registers the numbers 0-7.    We number the floating point registers 8-15.    Note that registers 0-7 can be accessed as a  short or int,    while only 0-3 may be used with byte `mov' instructions.     Reg 16 does not correspond to any hardware register, but instead    appears in the RTL as an argument pointer prior to reload, and is    eliminated during reloading in favor of either the stack or frame    pointer.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|53
end_define

begin_comment
comment|/* Number of hardware registers that go into the DWARF-2 unwind info.    If not defined, equals FIRST_PSEUDO_REGISTER.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_REGISTERS
value|17
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the 80386, the stack pointer is such, as is the arg pointer.      The value is an mask - bit 1 is set for fixed registers    for 32bit target, while 2 is set for fixed registers for 64bit.    Proper value is computed in the CONDITIONAL_REGISTER_USAGE.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7*/
define|\
value|{  0, 0, 0, 0, 0, 0, 0, 3, 0,  0,  0,  0,  0,  0,  0,  0,	\
comment|/*arg,flags,fpsr,dir,frame*/
value|\     3,    3,   3,  3,    3,					\
comment|/*xmm0,xmm1,xmm2,xmm3,xmm4,xmm5,xmm6,xmm7*/
value|\      0,   0,   0,   0,   0,   0,   0,   0,			\
comment|/*mmx0,mmx1,mmx2,mmx3,mmx4,mmx5,mmx6,mmx7*/
value|\      0,   0,   0,   0,   0,   0,   0,   0,			\
comment|/*  r8,  r9, r10, r11, r12, r13, r14, r15*/
value|\      1,   1,   1,   1,   1,   1,   1,   1,			\
comment|/*xmm8,xmm9,xmm10,xmm11,xmm12,xmm13,xmm14,xmm15*/
value|\      1,   1,    1,    1,    1,    1,    1,    1}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.       The value is an mask - bit 1 is set for call used    for 32bit target, while 2 is set for call used for 64bit.    Proper value is computed in the CONDITIONAL_REGISTER_USAGE. */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7*/
define|\
value|{  3, 3, 3, 0, 2, 2, 0, 3, 3,  3,  3,  3,  3,  3,  3,  3,	\
comment|/*arg,flags,fpsr,dir,frame*/
value|\      3,   3,   3,  3,    3,					\
comment|/*xmm0,xmm1,xmm2,xmm3,xmm4,xmm5,xmm6,xmm7*/
value|\      3,   3,   3,   3,   3,  3,    3,   3,			\
comment|/*mmx0,mmx1,mmx2,mmx3,mmx4,mmx5,mmx6,mmx7*/
value|\      3,   3,   3,   3,   3,   3,   3,   3,			\
comment|/*  r8,  r9, r10, r11, r12, r13, r14, r15*/
value|\      3,   3,   3,   3,   1,   1,   1,   1,			\
comment|/*xmm8,xmm9,xmm10,xmm11,xmm12,xmm13,xmm14,xmm15*/
value|\      3,   3,    3,    3,    3,    3,    3,    3}
end_define

begin_comment
unit|\
comment|/* Order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.  List frame pointer    late and fixed registers last.  Note that, in general, we prefer    registers listed in CALL_USED_REGISTERS, keeping the others    available for storage of persistent values.     Three different versions of REG_ALLOC_ORDER have been tried:     If the order is edx, ecx, eax, ... it produces a slightly faster compiler,    but slower code on simple functions returning values in eax.     If the order is eax, ecx, edx, ... it causes reload to abort when compiling    perl 4.036 due to not being able to create a DImode register (to hold a 2    word union).     If the order is eax, edx, ecx, ... it produces better code for simple    functions, and a slightly slower compiler.  Users complained about the code    generated by allocating edx first, so restore the 'natural' order of things.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
comment|/*ax,dx,cx,*/
define|\
value|{  0, 1, 2,							\
comment|/* bx,si,di,bp,sp,*/
value|\    3, 4, 5, 6, 7,						\
comment|/*r8,r9,r10,r11,*/
value|\   37,38, 39, 40,						\
comment|/*r12,r15,r14,r13*/
value|\   41, 44, 43, 42,						\
comment|/*xmm0,xmm1,xmm2,xmm3,xmm4,xmm5,xmm6,xmm7*/
value|\     21,  22,  23,  24,  25,  26,  27,  28,			\
comment|/*xmm8,xmm9,xmm10,xmm11,xmm12,xmm13,xmm14,xmm15*/
value|\     45,  46,   47,   48,   49,   50,   51,   52,		\
comment|/*st,st1,st2,st3,st4,st5,st6,st7*/
value|\    8,  9, 10, 11, 12, 13, 14, 15,				\
comment|/*,arg,cc,fpsr,dir,frame*/
value|\      16,17, 18, 19,   20,					\
comment|/*mmx0,mmx1,mmx2,mmx3,mmx4,mmx5,mmx6,mmx7*/
value|\     29,  30,  31,  32,  33,  34,  35,  36 }
end_define

begin_comment
comment|/* Macro to conditionally modify fixed_regs/call_used_regs.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|do {									\     int i;								\     for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)				\       {									\         fixed_regs[i] = (fixed_regs[i]& (TARGET_64BIT ? 2 : 1)) != 0;	\         call_used_regs[i] = (call_used_regs[i]				\& (TARGET_64BIT ? 2 : 1)) != 0;		\       }									\     if (flag_pic)							\       {									\ 	fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;			\ 	call_used_regs[PIC_OFFSET_TABLE_REGNUM] = 1;			\       }									\     if (! TARGET_MMX)							\       {									\ 	int i;								\         for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)			\           if (TEST_HARD_REG_BIT (reg_class_contents[(int)MMX_REGS], i))	\ 	    fixed_regs[i] = call_used_regs[i] = 1;		 	\       }									\     if (! TARGET_SSE)							\       {									\ 	int i;								\         for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)			\           if (TEST_HARD_REG_BIT (reg_class_contents[(int)SSE_REGS], i))	\ 	    fixed_regs[i] = call_used_regs[i] = 1;		 	\       }									\     if (! TARGET_80387&& ! TARGET_FLOAT_RETURNS_IN_80387)		\       {									\ 	int i;								\ 	HARD_REG_SET x;							\         COPY_HARD_REG_SET (x, reg_class_contents[(int)FLOAT_REGS]);	\         for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)			\           if (TEST_HARD_REG_BIT (x, i)) 				\ 	    fixed_regs[i] = call_used_regs[i] = 1;			\       }									\   } while (0)
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     Actually there are no two word move instructions for consecutive     registers.  And only registers 0-3 may have mov byte instructions    applied to them.    */
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
value|(FP_REGNO_P (REGNO) || SSE_REGNO_P (REGNO) || MMX_REGNO_P (REGNO)	\    ? (COMPLEX_MODE_P (MODE) ? 2 : 1)					\    : ((MODE) == TFmode							\       ? (TARGET_64BIT ? 2 : 3)						\       : (MODE) == TCmode						\       ? (TARGET_64BIT ? 4 : 6)						\       : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)))
end_define

begin_define
define|#
directive|define
name|VALID_SSE_REG_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == TImode || (MODE) == V4SFmode || (MODE) == V4SImode	\      || (MODE) == SFmode						\      || (TARGET_SSE2&& ((MODE) == DFmode || VALID_MMX_REG_MODE (MODE))))
end_define

begin_define
define|#
directive|define
name|VALID_MMX_REG_MODE_3DNOW
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == V2SFmode || (MODE) == SFmode)
end_define

begin_define
define|#
directive|define
name|VALID_MMX_REG_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == DImode || (MODE) == V8QImode || (MODE) == V4HImode	\      || (MODE) == V2SImode || (MODE) == SImode)
end_define

begin_define
define|#
directive|define
name|VECTOR_MODE_SUPPORTED_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(VALID_SSE_REG_MODE (MODE)&& TARGET_SSE ? 1			\      : VALID_MMX_REG_MODE (MODE)&& TARGET_MMX ? 1			\      : VALID_MMX_REG_MODE_3DNOW (MODE)&& TARGET_3DNOW ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|VALID_FP_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == SFmode || (MODE) == DFmode || (MODE) == TFmode		\      || (!TARGET_64BIT&& (MODE) == XFmode)				\      || (MODE) == SCmode || (MODE) == DCmode || (MODE) == TCmode	\      || (!TARGET_64BIT&& (MODE) == XCmode))
end_define

begin_define
define|#
directive|define
name|VALID_INT_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == QImode || (MODE) == HImode || (MODE) == SImode		\      || (MODE) == DImode						\      || (MODE) == CQImode || (MODE) == CHImode || (MODE) == CSImode	\      || (MODE) == CDImode						\      || (TARGET_64BIT&& ((MODE) == TImode || (MODE) == CTImode)))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.  */
end_comment

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
value|ix86_hard_regno_mode_ok ((REGNO), (MODE))
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
value|((MODE1) == (MODE2)						\    || (((MODE1) == HImode || (MODE1) == SImode			\ 	|| ((MODE1) == QImode					\&& (TARGET_64BIT || !TARGET_PARTIAL_REG_STALL))	\         || ((MODE1) == DImode&& TARGET_64BIT))			\&& ((MODE2) == HImode || (MODE2) == SImode		\ 	   || ((MODE1) == QImode				\&& (TARGET_64BIT || !TARGET_PARTIAL_REG_STALL))	\ 	   || ((MODE2) == DImode&& TARGET_64BIT))))
end_define

begin_comment
comment|/* Specify the modes required to caller save a given hard regno.    We do this on i386 to prevent flags from being saved at all.     Kill any attempts to combine saving of modes.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_CALLER_SAVE_MODE
parameter_list|(
name|REGNO
parameter_list|,
name|NREGS
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(CC_REGNO_P (REGNO) ? VOIDmode					\    : (MODE) == VOIDmode&& (NREGS) != 1 ? VOIDmode			\    : (MODE) == VOIDmode ? choose_hard_reg_mode ((REGNO), (NREGS))	\    : (MODE) == HImode&& !TARGET_PARTIAL_REG_STALL ? SImode		\    : (MODE) == QImode&& (REGNO)>= 4&& !TARGET_64BIT ? SImode 	\    : (MODE))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* on the 386 the pc register is %eip, and is not usable as a general    register.  The ordinary mov instructions won't work */
end_comment

begin_comment
comment|/* #define PC_REGNUM  */
end_comment

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|7
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
value|6
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|20
end_define

begin_comment
comment|/* First floating point reg */
end_comment

begin_define
define|#
directive|define
name|FIRST_FLOAT_REG
value|8
end_define

begin_comment
comment|/* First& last stack-like regs */
end_comment

begin_define
define|#
directive|define
name|FIRST_STACK_REG
value|FIRST_FLOAT_REG
end_define

begin_define
define|#
directive|define
name|LAST_STACK_REG
value|(FIRST_FLOAT_REG + 7)
end_define

begin_define
define|#
directive|define
name|FLAGS_REG
value|17
end_define

begin_define
define|#
directive|define
name|FPSR_REG
value|18
end_define

begin_define
define|#
directive|define
name|DIRFLAG_REG
value|19
end_define

begin_define
define|#
directive|define
name|FIRST_SSE_REG
value|(FRAME_POINTER_REGNUM + 1)
end_define

begin_define
define|#
directive|define
name|LAST_SSE_REG
value|(FIRST_SSE_REG + 7)
end_define

begin_define
define|#
directive|define
name|FIRST_MMX_REG
value|(LAST_SSE_REG + 1)
end_define

begin_define
define|#
directive|define
name|LAST_MMX_REG
value|(FIRST_MMX_REG + 7)
end_define

begin_define
define|#
directive|define
name|FIRST_REX_INT_REG
value|(LAST_MMX_REG + 1)
end_define

begin_define
define|#
directive|define
name|LAST_REX_INT_REG
value|(FIRST_REX_INT_REG + 7)
end_define

begin_define
define|#
directive|define
name|FIRST_REX_SSE_REG
value|(LAST_REX_INT_REG + 1)
end_define

begin_define
define|#
directive|define
name|LAST_REX_SSE_REG
value|(FIRST_REX_SSE_REG + 7)
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|ix86_frame_pointer_required ()
end_define

begin_comment
comment|/* Override this in other tm.h files to cope with various OS losage    requiring a frame pointer.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_FRAME_POINTER_REQUIRED
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_FRAME_POINTER_REQUIRED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make sure we can access arbitrary call frames.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_FRAME_ADDRESSES
parameter_list|()
value|ix86_setup_frame_addresses ()
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|16
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.    We do use ECX as static chain register for 32 bit ABI.  On the    64bit ABI, ECX is an argument register, so we use R10 instead.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|(TARGET_64BIT ? FIRST_REX_INT_REG + 10 - 8 : 2)
end_define

begin_comment
comment|/* Register to hold the addressing base for position independent    code access to data items.    We don't use PIC pointer for 64bit mode.  Define the regnum to    dummy value to prevent gcc from pessimizing code dealing with EBX.  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|(TARGET_64BIT ? INVALID_REGNUM : 3)
end_define

begin_comment
comment|/* Register in which address to store a structure value    arrives in the function.  On the 386, the prologue    copies this from the stack to register %eax.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_INCOMING
value|0
end_define

begin_comment
comment|/* Place in which caller passes the structure value address.    0 means push the value on the stack like an argument.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|0
end_define

begin_comment
comment|/* A C expression which can inhibit the returning of certain function    values in registers, based on the type of value.  A nonzero value    says to return the function value in memory, just as large    structures are always returned.  Here TYPE will be a C expression    of type `tree', representing the data type of the value.     Note that values of mode `BLKmode' must be explicitly handled by    this macro.  Also, the option `-fpcc-struct-return' takes effect    regardless of this macro.  On most systems, it is possible to    leave the macro undefined; this causes a default definition to be    used, whose value is the constant 1 for `BLKmode' values, and 0    otherwise.     Do not use this macro to indicate that structures and unions    should always be returned in memory.  You should instead use    `DEFAULT_PCC_STRUCT_RETURN' to indicate this.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|ix86_return_in_memory (TYPE)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.     It might seem that class BREG is unnecessary, since no useful 386    opcode needs reg %ebx.  But some systems pass args to the OS in ebx,    and the "b" register constraint is useful in asms for syscalls.     The flags and fpsr registers are in no class.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|AREG
block|,
name|DREG
block|,
name|CREG
block|,
name|BREG
block|,
name|SIREG
block|,
name|DIREG
block|,
name|AD_REGS
block|,
comment|/* %eax/%edx for DImode */
name|Q_REGS
block|,
comment|/* %eax %ebx %ecx %edx */
name|NON_Q_REGS
block|,
comment|/* %esi %edi %ebp %esp */
name|INDEX_REGS
block|,
comment|/* %eax %ebx %ecx %edx %esi %edi %ebp */
name|LEGACY_REGS
block|,
comment|/* %eax %ebx %ecx %edx %esi %edi %ebp %esp */
name|GENERAL_REGS
block|,
comment|/* %eax %ebx %ecx %edx %esi %edi %ebp %esp %r8 - %r15*/
name|FP_TOP_REG
block|,
name|FP_SECOND_REG
block|,
comment|/* %st(0) %st(1) */
name|FLOAT_REGS
block|,
name|SSE_REGS
block|,
name|MMX_REGS
block|,
name|FP_TOP_SSE_REGS
block|,
name|FP_SECOND_SSE_REGS
block|,
name|FLOAT_SSE_REGS
block|,
name|FLOAT_INT_REGS
block|,
name|INT_SSE_REGS
block|,
name|FLOAT_INT_SSE_REGS
block|,
name|ALL_REGS
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|((int) LIM_REG_CLASSES)
end_define

begin_define
define|#
directive|define
name|INTEGER_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_class_subset_p ((CLASS), GENERAL_REGS)
end_define

begin_define
define|#
directive|define
name|FLOAT_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_class_subset_p ((CLASS), FLOAT_REGS)
end_define

begin_define
define|#
directive|define
name|SSE_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_class_subset_p ((CLASS), SSE_REGS)
end_define

begin_define
define|#
directive|define
name|MMX_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_class_subset_p ((CLASS), MMX_REGS)
end_define

begin_define
define|#
directive|define
name|MAYBE_INTEGER_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_classes_intersect_p ((CLASS), GENERAL_REGS)
end_define

begin_define
define|#
directive|define
name|MAYBE_FLOAT_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_classes_intersect_p ((CLASS), FLOAT_REGS)
end_define

begin_define
define|#
directive|define
name|MAYBE_SSE_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_classes_intersect_p (SSE_REGS, (CLASS))
end_define

begin_define
define|#
directive|define
name|MAYBE_MMX_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_classes_intersect_p (MMX_REGS, (CLASS))
end_define

begin_define
define|#
directive|define
name|Q_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|reg_class_subset_p ((CLASS), Q_REGS)
end_define

begin_comment
comment|/* Give names of register classes as strings for dump file.   */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{  "NO_REGS",				\    "AREG", "DREG", "CREG", "BREG",	\    "SIREG", "DIREG",			\    "AD_REGS",				\    "Q_REGS", "NON_Q_REGS",		\    "INDEX_REGS",			\    "LEGACY_REGS",			\    "GENERAL_REGS",			\    "FP_TOP_REG", "FP_SECOND_REG",	\    "FLOAT_REGS",			\    "SSE_REGS",				\    "MMX_REGS",				\    "FP_TOP_SSE_REGS",			\    "FP_SECOND_SSE_REGS",		\    "FLOAT_SSE_REGS",			\    "FLOAT_INT_REGS",			\    "INT_SSE_REGS",			\    "FLOAT_INT_SSE_REGS",		\    "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{     { 0x00,     0x0 },						\       { 0x01,     0x0 }, { 0x02, 0x0 },
comment|/* AREG, DREG */
value|\       { 0x04,     0x0 }, { 0x08, 0x0 },
comment|/* CREG, BREG */
value|\       { 0x10,     0x0 }, { 0x20, 0x0 },
comment|/* SIREG, DIREG */
value|\       { 0x03,     0x0 },
comment|/* AD_REGS */
value|\       { 0x0f,     0x0 },
comment|/* Q_REGS */
value|\   { 0x1100f0,  0x1fe0 },
comment|/* NON_Q_REGS */
value|\       { 0x7f,  0x1fe0 },
comment|/* INDEX_REGS */
value|\   { 0x1100ff,  0x0 },
comment|/* LEGACY_REGS */
value|\   { 0x1100ff,  0x1fe0 },
comment|/* GENERAL_REGS */
value|\      { 0x100,     0x0 }, { 0x0200, 0x0 },
comment|/* FP_TOP_REG, FP_SECOND_REG */
value|\     { 0xff00,     0x0 },
comment|/* FLOAT_REGS */
value|\ { 0x1fe00000,0x1fe000 },
comment|/* SSE_REGS */
value|\ { 0xe0000000,    0x1f },
comment|/* MMX_REGS */
value|\ { 0x1fe00100,0x1fe000 },
comment|/* FP_TOP_SSE_REG */
value|\ { 0x1fe00200,0x1fe000 },
comment|/* FP_SECOND_SSE_REG */
value|\ { 0x1fe0ff00,0x1fe000 },
comment|/* FLOAT_SSE_REGS */
value|\    { 0x1ffff,  0x1fe0 },
comment|/* FLOAT_INT_REGS */
value|\ { 0x1fe100ff,0x1fffe0 },
comment|/* INT_SSE_REGS */
value|\ { 0x1fe1ffff,0x1fffe0 },
comment|/* FLOAT_INT_SSE_REGS */
value|\ { 0xffffffff,0x1fffff }							\ }
end_define

begin_comment
comment|/* The same information, inverted:    Return the class number of the smallest class containing    reg number REGNO.  This could be a conditional expression    or could index an array.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|(regclass_map[REGNO])
end_define

begin_comment
comment|/* When defined, the compiler allows registers explicitly used in the    rtl to be used as spill registers but prevents the compiler from    extending the lifetime of these registers.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_REGISTER_CLASSES
value|1
end_define

begin_define
define|#
directive|define
name|QI_REG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REG_P (X)&& REGNO (X)< 4)
end_define

begin_define
define|#
directive|define
name|GENERAL_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< 8 || REX_INT_REGNO_P (N))
end_define

begin_define
define|#
directive|define
name|GENERAL_REG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REG_P (X)&& GENERAL_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|ANY_QI_REG_P
parameter_list|(
name|X
parameter_list|)
value|(TARGET_64BIT ? GENERAL_REG_P(X) : QI_REG_P (X))
end_define

begin_define
define|#
directive|define
name|NON_QI_REG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REG_P (X)&& REGNO (X)>= 4&& REGNO (X)< FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|REX_INT_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= FIRST_REX_INT_REG&& (N)<= LAST_REX_INT_REG)
end_define

begin_define
define|#
directive|define
name|REX_INT_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REX_INT_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& FP_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|FP_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= FIRST_STACK_REG&& (N)<= LAST_STACK_REG)
end_define

begin_define
define|#
directive|define
name|ANY_FP_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& ANY_FP_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|ANY_FP_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|(FP_REGNO_P (N) || SSE_REGNO_P (N))
end_define

begin_define
define|#
directive|define
name|SSE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)>= FIRST_SSE_REG&& (N)<= LAST_SSE_REG) \    || ((N)>= FIRST_REX_SSE_REG&& (N)<= LAST_REX_SSE_REG))
end_define

begin_define
define|#
directive|define
name|SSE_REGNO
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< 8 ? FIRST_SSE_REG + (N) : FIRST_REX_SSE_REG + (N) - 8)
end_define

begin_define
define|#
directive|define
name|SSE_REG_P
parameter_list|(
name|N
parameter_list|)
value|(REG_P (N)&& SSE_REGNO_P (REGNO (N)))
end_define

begin_define
define|#
directive|define
name|SSE_FLOAT_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((TARGET_SSE_MATH&& (MODE) == SFmode) || (TARGET_SSE2&& (MODE) == DFmode))
end_define

begin_define
define|#
directive|define
name|MMX_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= FIRST_MMX_REG&& (N)<= LAST_MMX_REG)
end_define

begin_define
define|#
directive|define
name|MMX_REG_P
parameter_list|(
name|XOP
parameter_list|)
value|(REG_P (XOP)&& MMX_REGNO_P (REGNO (XOP)))
end_define

begin_define
define|#
directive|define
name|STACK_REG_P
parameter_list|(
name|XOP
parameter_list|)
define|\
value|(REG_P (XOP)&&		       	\    REGNO (XOP)>= FIRST_STACK_REG&&	\    REGNO (XOP)<= LAST_STACK_REG)
end_define

begin_define
define|#
directive|define
name|NON_STACK_REG_P
parameter_list|(
name|XOP
parameter_list|)
value|(REG_P (XOP)&& ! STACK_REG_P (XOP))
end_define

begin_define
define|#
directive|define
name|STACK_TOP_P
parameter_list|(
name|XOP
parameter_list|)
value|(REG_P (XOP)&& REGNO (XOP) == FIRST_STACK_REG)
end_define

begin_define
define|#
directive|define
name|CC_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& CC_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|CC_REGNO_P
parameter_list|(
name|X
parameter_list|)
value|((X) == FLAGS_REG || (X) == FPSR_REG)
end_define

begin_comment
comment|/* Indicate whether hard register numbered REG_NO should be converted    to SSA form.  */
end_comment

begin_define
define|#
directive|define
name|CONVERT_HARD_REGISTER_TO_SSA_P
parameter_list|(
name|REG_NO
parameter_list|)
define|\
value|((REG_NO) == FLAGS_REG || (REG_NO) == ARG_POINTER_REGNUM)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|INDEX_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|GENERAL_REGS
end_define

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine description.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'r' ? GENERAL_REGS :					\    (C) == 'R' ? LEGACY_REGS :					\    (C) == 'q' ? TARGET_64BIT ? GENERAL_REGS : Q_REGS :		\    (C) == 'Q' ? Q_REGS :					\    (C) == 'f' ? (TARGET_80387 || TARGET_FLOAT_RETURNS_IN_80387	\ 		 ? FLOAT_REGS					\ 		 : NO_REGS) :					\    (C) == 't' ? (TARGET_80387 || TARGET_FLOAT_RETURNS_IN_80387	\ 		 ? FP_TOP_REG					\ 		 : NO_REGS) :					\    (C) == 'u' ? (TARGET_80387 || TARGET_FLOAT_RETURNS_IN_80387	\ 		 ? FP_SECOND_REG				\ 		 : NO_REGS) :					\    (C) == 'a' ? AREG :						\    (C) == 'b' ? BREG :						\    (C) == 'c' ? CREG :						\    (C) == 'd' ? DREG :						\    (C) == 'x' ? TARGET_SSE ? SSE_REGS : NO_REGS :		\    (C) == 'Y' ? TARGET_SSE2? SSE_REGS : NO_REGS :		\    (C) == 'y' ? TARGET_MMX ? MMX_REGS : NO_REGS :		\    (C) == 'A' ? AD_REGS :					\    (C) == 'D' ? DIREG :						\    (C) == 'S' ? SIREG : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     I is for non-DImode shifts.    J is for DImode shifts.    K is for signed imm8 operands.    L is for andsi as zero-extending move.    M is for shifts that can be executed by the "lea" opcode.    N is for immedaite operands for out/in instructions (0-255)    */
end_comment

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
value|((C) == 'I' ? (VALUE)>= 0&& (VALUE)<= 31			\    : (C) == 'J' ? (VALUE)>= 0&& (VALUE)<= 63			\    : (C) == 'K' ? (VALUE)>= -128&& (VALUE)<= 127		\    : (C) == 'L' ? (VALUE) == 0xff || (VALUE) == 0xffff		\    : (C) == 'M' ? (VALUE)>= 0&& (VALUE)<= 3			\    : (C) == 'N' ? (VALUE)>= 0&& (VALUE)<= 255		\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.  We allow constants even if    TARGET_387 isn't set, because the stack register converter may need to    load 0.0 into the function value register.  */
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
value|((C) == 'G' ? standard_80387_constant_p (VALUE) \    : ((C) == 'H' ? standard_sse_constant_p (VALUE) : 0))
end_define

begin_comment
comment|/* A C expression that defines the optional machine-dependent    constraint letters that can be used to segregate specific types of    operands, usually memory references, for the target machine.  Any    letter that is not elsewhere defined and not matched by    `REG_CLASS_FROM_LETTER' may be used.  Normally this macro will not    be defined.     If it is required for a particular target machine, it should    return 1 if VALUE corresponds to the operand type represented by    the constraint letter C.  If C is not defined as an extra    constraint, the value returned should be 0 regardless of VALUE.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'e' ? x86_64_sign_extended_value (VALUE)		\    : (C) == 'Z' ? x86_64_zero_extended_value (VALUE)		\    : 0)
end_define

begin_comment
comment|/* Place additional restrictions on the register class to use when it    is necessary to be able to hold a value of mode MODE in a reload    register for which class CLASS would ordinarily be used.  */
end_comment

begin_define
define|#
directive|define
name|LIMIT_RELOAD_CLASS
parameter_list|(
name|MODE
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|((MODE) == QImode&& !TARGET_64BIT				\&& ((CLASS) == ALL_REGS || (CLASS) == GENERAL_REGS		\        || (CLASS) == LEGACY_REGS || (CLASS) == INDEX_REGS)	\    ? Q_REGS : (CLASS))
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.    On the 80386 series, we prevent floating constants from being    reloaded into floating registers (since no move-insn can do that)    and we ensure that QImodes aren't reloaded into the esi or edi reg.  */
end_comment

begin_comment
comment|/* Put float CONST_DOUBLE in the constant pool instead of fp regs.    QImode must go into class Q_REGS.    Narrow ALL_REGS to GENERAL_REGS.  This supports allowing movsf and    movdf to do mem-to-mem moves through integer regs.  */
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
value|ix86_preferred_reload_class ((X), (CLASS))
end_define

begin_comment
comment|/* If we are copying between general and FP registers, we need a memory    location. The same is true for SSE and MMX registers.  */
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
value|ix86_secondary_memory_needed ((CLASS1), (CLASS2), (MODE), 1)
end_define

begin_comment
comment|/* QImode spills from non-QI registers need a scratch.  This does not    happen often -- the only example so far requires an uninitialized     pseudo.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_OUTPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|OUT
parameter_list|)
define|\
value|(((CLASS) == GENERAL_REGS || (CLASS) == LEGACY_REGS			\     || (CLASS) == INDEX_REGS)&& !TARGET_64BIT&& (MODE) == QImode	\    ? Q_REGS : NO_REGS)
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On the 80386, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.    The TFmodes are really just 80bit values, so we use only 3 registers    to hold them, instead of 4, as the size would suggest.  */
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
value|(!MAYBE_INTEGER_CLASS_P (CLASS)					\   ? (COMPLEX_MODE_P (MODE) ? 2 : 1)					\   : ((GET_MODE_SIZE ((MODE) == TFmode ? XFmode : (MODE))		\      + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* A C expression whose value is nonzero if pseudos that have been    assigned to registers of class CLASS would likely be spilled    because registers of CLASS are needed for spill registers.     The default value of this macro returns 1 if CLASS has exactly one    register and zero otherwise.  On most machines, this default    should be used.  Only define this macro to some other expression    if pseudo allocated by `local-alloc.c' end up in memory because    their hard registers were needed for spill registers.  If this    macro returns nonzero for those classes, those pseudos will only    be allocated by `global.c', which knows how to reallocate the    pseudo to another register.  If there would not be another    register available for reallocation, you should not change the    definition of this macro since the only effect of such a    definition would be to slow down register allocation.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_LIKELY_SPILLED_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|(((CLASS) == AREG)							\    || ((CLASS) == DREG)							\    || ((CLASS) == CREG)							\    || ((CLASS) == BREG)							\    || ((CLASS) == AD_REGS)						\    || ((CLASS) == SIREG)						\    || ((CLASS) == DIREG))
end_define

begin_comment
comment|/* A C statement that adds to CLOBBERS any hard regs the port wishes    to automatically clobber for all asms.      We do this in the new i386 backend to maintain source compatibility    with the old cc0-based compiler.  */
end_comment

begin_define
define|#
directive|define
name|MD_ASM_CLOBBERS
parameter_list|(
name|CLOBBERS
parameter_list|)
define|\
value|do {									\     (CLOBBERS) = tree_cons (NULL_TREE, build_string (5, "flags"),	\ 			    (CLOBBERS));				\     (CLOBBERS) = tree_cons (NULL_TREE, build_string (4, "fpsr"),	\ 			    (CLOBBERS));				\     (CLOBBERS) = tree_cons (NULL_TREE, build_string (7, "dirflag"),	\ 			    (CLOBBERS));				\   } while (0)
end_define

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

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|0
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On 386 pushw decrements by exactly 2 no matter what the position was.    On the 386 there is no pushb; we use pushw instead, and this    has the effect of rounding up to 2.      For 64bit ABI we round up to 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|BYTES
parameter_list|)
define|\
value|(TARGET_64BIT		     \    ? (((BYTES) + 7)& (-8))  \    : (((BYTES) + 1)& (-2)))
end_define

begin_comment
comment|/* If defined, the maximum amount of space required for outgoing arguments will    be computed and placed into the variable    `current_function_outgoing_args_size'.  No space will be pushed onto the    stack for each call; instead, the function prologue should increase the stack    frame size by this amount.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
value|TARGET_ACCUMULATE_OUTGOING_ARGS
end_define

begin_comment
comment|/* If defined, a C expression whose value is nonzero when we want to use PUSH    instructions to pass outgoing arguments.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ARGS
value|(TARGET_PUSH_ARGS&& !ACCUMULATE_OUTGOING_ARGS)
end_define

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_comment
comment|/* Define this macro if functions should assume that stack space has been    allocated for arguments even when their values are passed in registers.     The value of this macro is the size, in bytes, of the area reserved for    arguments passed in registers for the function represented by FNDECL.     This space can be allocated by the caller, or be a part of the    machine-dependent stack frame: `OUTGOING_REG_PARM_STACK_SPACE' says    which.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_comment
comment|/* Define as a C expression that evaluates to nonzero if we do not know how    to pass TYPE solely in registers.  The file expr.h defines a    definition that is usually appropriate, refer to expr.h for additional    documentation. If `REG_PARM_STACK_SPACE' is defined, the argument will be    computed in the stack and then loaded into a register.  */
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
value|((TYPE) != 0							\&& (TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST		\        || TREE_ADDRESSABLE (TYPE)				\        || ((MODE) == TImode)					\        || ((MODE) == BLKmode 					\&& ! ((TYPE) != 0					\&& TREE_CODE (TYPE_SIZE (TYPE)) == INTEGER_CST \&& 0 == (int_size_in_bytes (TYPE)		\ 			  % (PARM_BOUNDARY / BITS_PER_UNIT)))	\&& (FUNCTION_ARG_PADDING (MODE, TYPE)		\ 	       == (BYTES_BIG_ENDIAN ? upward : downward)))))
end_define

begin_comment
comment|/* Value is the number of bytes of arguments automatically    popped when returning from a subroutine call.    FUNDECL is the declaration node of the function (as a tree),    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.     On the 80386, the RTD insn may be used to pop them if the number      of args is fixed, but if the number is variable then the caller      must pop them all.  RTD can't be used for library calls now      because the library is compiled with the Unix compiler.    Use of RTD is a selectable option, since it is incompatible with    standard Unix calling sequences.  If the option is not selected,    the caller must always pop the args.     The attribute stdcall is equivalent to RTD on a per module basis.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|ix86_return_pops_args ((FUNDECL), (FUNTYPE), (SIZE))
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
define|\
value|ix86_function_value (VALTYPE)
end_define

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|ix86_function_value_regno_p (N)
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
value|ix86_libcall_value (MODE)
end_define

begin_comment
comment|/* Define the size of the result block used for communication between    untyped_call and untyped_return.  The block contains a DImode value    followed by the block used by fnsave and frstor.  */
end_comment

begin_define
define|#
directive|define
name|APPLY_RESULT_SIZE
value|(8+108)
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
value|ix86_function_arg_regno_p (N)
end_define

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ix86_args
block|{
name|int
name|words
decl_stmt|;
comment|/* # words passed so far */
name|int
name|nregs
decl_stmt|;
comment|/* # registers available for passing */
name|int
name|regno
decl_stmt|;
comment|/* next available register number */
name|int
name|sse_words
decl_stmt|;
comment|/* # sse words passed so far */
name|int
name|sse_nregs
decl_stmt|;
comment|/* # sse registers available for passing */
name|int
name|sse_regno
decl_stmt|;
comment|/* next available sse register number */
name|int
name|maybe_vaarg
decl_stmt|;
comment|/* true for calls to possibly vardic fncts.  */
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
parameter_list|,
name|INDIRECT
parameter_list|)
define|\
value|init_cumulative_args (&(CUM), (FNTYPE), (LIBNAME))
end_define

begin_comment
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
value|function_arg_advance (&(CUM), (MODE), (TYPE), (NAMED))
end_define

begin_comment
comment|/* Define where to put the arguments to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
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
value|function_arg (&(CUM), (MODE), (TYPE), (NAMED))
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    For args passed entirely in registers or entirely in memory, zero.  */
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
value|0
end_define

begin_comment
comment|/* If PIC, we cannot make sibling calls to global functions    because the PLT requires %ebx live.    If we are returning floats on the register stack, we cannot make    sibling calls to functions that return floats.  (The stack adjust    instruction will wind up after the sibcall jump, and not be executed.) */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_OK_FOR_SIBCALL
parameter_list|(
name|DECL
parameter_list|)
define|\
value|((DECL)								\&& (! flag_pic || ! TREE_PUBLIC (DECL))				\&& (! TARGET_FLOAT_RETURNS_IN_80387					\        || ! FLOAT_MODE_P (TYPE_MODE (TREE_TYPE (TREE_TYPE (DECL))))	\        || FLOAT_MODE_P (TYPE_MODE (TREE_TYPE (TREE_TYPE (cfun->decl))))))
end_define

begin_comment
comment|/* Perform any needed actions needed for a function that is receiving a    variable number of arguments.     CUM is as above.     MODE and TYPE are the mode and type of the current parameter.     PRETEND_SIZE is a variable that should be set to the amount of stack    that must be pushed by the prolog to pretend that our caller pushed    it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.  */
end_comment

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
value|ix86_setup_incoming_varargs (&(CUM), (MODE), (TYPE),&(PRETEND_SIZE), \ 			       (NO_RTL))
end_define

begin_comment
comment|/* Define the `__builtin_va_list' type for the ABI.  */
end_comment

begin_define
define|#
directive|define
name|BUILD_VA_LIST_TYPE
parameter_list|(
name|VALIST
parameter_list|)
define|\
value|((VALIST) = ix86_build_va_list ())
end_define

begin_comment
comment|/* Implement `va_start' for varargs and stdarg.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_START
parameter_list|(
name|STDARG
parameter_list|,
name|VALIST
parameter_list|,
name|NEXTARG
parameter_list|)
define|\
value|ix86_va_start ((STDARG), (VALIST), (NEXTARG))
end_define

begin_comment
comment|/* Implement `va_arg'.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_ARG
parameter_list|(
name|VALIST
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|ix86_va_arg ((VALIST), (TYPE))
end_define

begin_comment
comment|/* This macro is invoked at the end of compilation.  It is used here to    output code for -fpic that will load the return address into %ebx.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
value|ix86_asm_file_end (FILE)
end_define

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
value|do {									\   if (flag_pic)								\     {									\       fprintf ((FILE), "\tleal\t%sP%d@GOTOFF(%%ebx),%%edx\n",		\ 	       LPREFIX, (LABELNO));					\       fprintf ((FILE), "\tcall\t*_mcount@GOT(%%ebx)\n");		\     }									\   else									\     {									\       fprintf ((FILE), "\tmovl\t$%sP%d,%%edx\n", LPREFIX, (LABELNO));	\       fprintf ((FILE), "\tcall\t_mcount\n");				\     }									\ } while (0)
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_comment
comment|/* Note on the 386 it might be more efficient not to define this since     we have to restore it ourselves from the frame pointer, in order to    use pop */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.  */
end_comment

begin_comment
comment|/* On the 386, the trampoline contains two instructions:      mov #STATIC,ecx      jmp FUNCTION    The trampoline is generated entirely at runtime.  The operand of JMP    is the address of FUNCTION relative to the instruction following the    JMP (which is 5 bytes long).  */
end_comment

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|(TARGET_64BIT ? 23 : 10)
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.  */
end_comment

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
value|x86_initialize_trampoline ((TRAMP), (FNADDR), (CXT))
end_define

begin_escape
end_escape

begin_comment
comment|/* Definitions for register eliminations.     This is an array of structures.  Each structure initializes one pair    of eliminable registers.  The "from" register number is given first,    followed by "to".  Eliminations of the same "from" register are listed    in order of preference.     There are two registers that can always be eliminated on the i386.    The frame pointer and the arg pointer can be replaced by either the    hard frame pointer or to the stack pointer, depending upon the    circumstances.  The hard frame pointer is not used before reload and    so it is not eligible for elimination.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ ARG_POINTER_REGNUM, STACK_POINTER_REGNUM},		\  { ARG_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM},	\  { FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},		\  { FRAME_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM}}
end_define

begin_comment
unit|\
comment|/* Given FROM and TO register numbers, say whether this elimination is    allowed.  Frame pointer elimination is automatically handled.     All other eliminations are valid.  */
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
value|((TO) == STACK_POINTER_REGNUM ? ! frame_pointer_needed : 1)
end_define

begin_comment
comment|/* Define the offset between two registers, one to be eliminated, and the other    its replacement, at the start of a routine.  */
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
value|((OFFSET) = ix86_initial_elimination_offset ((FROM), (TO)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_comment
comment|/* #define HAVE_POST_INCREMENT 0 */
end_comment

begin_comment
comment|/* #define HAVE_POST_DECREMENT 0 */
end_comment

begin_comment
comment|/* #define HAVE_PRE_DECREMENT 0 */
end_comment

begin_comment
comment|/* #define HAVE_PRE_INCREMENT 0 */
end_comment

begin_comment
comment|/* Macros to check register numbers against specific register classes.  */
end_comment

begin_comment
comment|/* These assume that REGNO is a hard or pseudo reg number.    They give nonzero only if REGNO is a hard reg of the suitable class    or a pseudo reg currently allocated to a suitable hard reg.    Since they use reg_renumber, they are safe only once reg_renumber    has been allocated, which happens in local-alloc.c.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< STACK_POINTER_REGNUM 					\    || (REGNO>= FIRST_REX_INT_REG					\&& (REGNO)<= LAST_REX_INT_REG)					\    || ((unsigned) reg_renumber[(REGNO)]>= FIRST_REX_INT_REG		\&& (unsigned) reg_renumber[(REGNO)]<= LAST_REX_INT_REG)		\    || (unsigned) reg_renumber[(REGNO)]< STACK_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)<= STACK_POINTER_REGNUM 					\    || (REGNO) == ARG_POINTER_REGNUM 					\    || (REGNO) == FRAME_POINTER_REGNUM 					\    || (REGNO>= FIRST_REX_INT_REG					\&& (REGNO)<= LAST_REX_INT_REG)					\    || ((unsigned) reg_renumber[(REGNO)]>= FIRST_REX_INT_REG		\&& (unsigned) reg_renumber[(REGNO)]<= LAST_REX_INT_REG)		\    || (unsigned) reg_renumber[(REGNO)]<= STACK_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_SIREG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO) == 4 || reg_renumber[(REGNO)] == 4)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_DIREG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO) == 5 || reg_renumber[(REGNO)] == 5)
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Source files for reload pass need to be strict.    After reload, it makes no difference, since pseudo regs have    been eliminated by then.  */
end_comment

begin_comment
comment|/* Non strict versions, pseudos are ok */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_NONSTRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)< STACK_POINTER_REGNUM					\    || (REGNO (X)>= FIRST_REX_INT_REG					\&& REGNO (X)<= LAST_REX_INT_REG)				\    || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_NONSTRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)<= STACK_POINTER_REGNUM					\    || REGNO (X) == ARG_POINTER_REGNUM					\    || REGNO (X) == FRAME_POINTER_REGNUM 				\    || (REGNO (X)>= FIRST_REX_INT_REG					\&& REGNO (X)<= LAST_REX_INT_REG)				\    || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_comment
comment|/* Strict versions, hard registers only */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_STRICT_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_STRICT_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_BASE_P (REGNO (X))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_INDEX_NONSTRICT_P (X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_BASE_NONSTRICT_P (X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_INDEX_STRICT_P (X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_BASE_STRICT_P (X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS,    except for CONSTANT_ADDRESS_P which is usually machine-independent.     See legitimize_pic_address in i386.c for details as to what    constitutes a legitimate address when -fpic is used.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|2
end_define

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF	\    || GET_CODE (X) == CONST_INT || GET_CODE (X) == CONST	\    || GET_CODE (X) == CONST_DOUBLE)
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REG_OK_STRICT
end_ifdef

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
value|do {									\   if (legitimate_address_p ((MODE), (X), 1))				\     goto ADDR;								\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

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
value|do {									\   if (legitimate_address_p ((MODE), (X), 0))				\     goto ADDR;								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If defined, a C expression to determine the base term of address X.    This macro is used in only one place: `find_base_term' in alias.c.     It is always safe for this macro to not be defined.  It exists so    that alias analysis can understand machine-dependent addresses.     The typical use of this macro is to handle addresses containing    a label_ref or symbol_ref within an UNSPEC.  */
end_comment

begin_define
define|#
directive|define
name|FIND_BASE_TERM
parameter_list|(
name|X
parameter_list|)
value|ix86_find_base_term (X)
end_define

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the 80386, we handle X+REG by loading X into a register R and    using R+REG.  R will go in a general reg and indexing will be used.    However, if REG is a broken-out memory address or multiplication,    nothing needs to be done because REG can certainly go in a general reg.     When -fpic is used, special handling is needed for symbolic references.    See comments by legitimize_pic_address in i386.c for details.  */
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
value|do {									\   (X) = legitimize_address ((X), (OLDX), (MODE));			\   if (memory_address_p ((MODE), (X)))					\     goto WIN;								\ } while (0)
end_define

begin_define
define|#
directive|define
name|REWRITE_ADDRESS
parameter_list|(
name|X
parameter_list|)
value|rewrite_address (X)
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand    when generating PIC code.  It is given that flag_pic is on and     that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(! SYMBOLIC_CONST (X)				\    || legitimate_pic_address_disp_p (X))
end_define

begin_define
define|#
directive|define
name|SYMBOLIC_CONST
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF						\    || GET_CODE (X) == LABEL_REF						\    || (GET_CODE (X) == CONST&& symbolic_reference_mentioned_p (X)))
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the 80386, only postdecrement and postincrement address depend thus    (the amount of decrement or increment being the length of the operand).  */
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
define|\
value|do {							\  if (GET_CODE (ADDR) == POST_INC			\      || GET_CODE (ADDR) == POST_DEC)			\    goto LABEL;						\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Codes for all the SSE/MMX builtins.  */
end_comment

begin_enum
enum|enum
name|ix86_builtins
block|{
name|IX86_BUILTIN_ADDPS
block|,
name|IX86_BUILTIN_ADDSS
block|,
name|IX86_BUILTIN_DIVPS
block|,
name|IX86_BUILTIN_DIVSS
block|,
name|IX86_BUILTIN_MULPS
block|,
name|IX86_BUILTIN_MULSS
block|,
name|IX86_BUILTIN_SUBPS
block|,
name|IX86_BUILTIN_SUBSS
block|,
name|IX86_BUILTIN_CMPEQPS
block|,
name|IX86_BUILTIN_CMPLTPS
block|,
name|IX86_BUILTIN_CMPLEPS
block|,
name|IX86_BUILTIN_CMPGTPS
block|,
name|IX86_BUILTIN_CMPGEPS
block|,
name|IX86_BUILTIN_CMPNEQPS
block|,
name|IX86_BUILTIN_CMPNLTPS
block|,
name|IX86_BUILTIN_CMPNLEPS
block|,
name|IX86_BUILTIN_CMPNGTPS
block|,
name|IX86_BUILTIN_CMPNGEPS
block|,
name|IX86_BUILTIN_CMPORDPS
block|,
name|IX86_BUILTIN_CMPUNORDPS
block|,
name|IX86_BUILTIN_CMPNEPS
block|,
name|IX86_BUILTIN_CMPEQSS
block|,
name|IX86_BUILTIN_CMPLTSS
block|,
name|IX86_BUILTIN_CMPLESS
block|,
name|IX86_BUILTIN_CMPGTSS
block|,
name|IX86_BUILTIN_CMPGESS
block|,
name|IX86_BUILTIN_CMPNEQSS
block|,
name|IX86_BUILTIN_CMPNLTSS
block|,
name|IX86_BUILTIN_CMPNLESS
block|,
name|IX86_BUILTIN_CMPNGTSS
block|,
name|IX86_BUILTIN_CMPNGESS
block|,
name|IX86_BUILTIN_CMPORDSS
block|,
name|IX86_BUILTIN_CMPUNORDSS
block|,
name|IX86_BUILTIN_CMPNESS
block|,
name|IX86_BUILTIN_COMIEQSS
block|,
name|IX86_BUILTIN_COMILTSS
block|,
name|IX86_BUILTIN_COMILESS
block|,
name|IX86_BUILTIN_COMIGTSS
block|,
name|IX86_BUILTIN_COMIGESS
block|,
name|IX86_BUILTIN_COMINEQSS
block|,
name|IX86_BUILTIN_UCOMIEQSS
block|,
name|IX86_BUILTIN_UCOMILTSS
block|,
name|IX86_BUILTIN_UCOMILESS
block|,
name|IX86_BUILTIN_UCOMIGTSS
block|,
name|IX86_BUILTIN_UCOMIGESS
block|,
name|IX86_BUILTIN_UCOMINEQSS
block|,
name|IX86_BUILTIN_CVTPI2PS
block|,
name|IX86_BUILTIN_CVTPS2PI
block|,
name|IX86_BUILTIN_CVTSI2SS
block|,
name|IX86_BUILTIN_CVTSS2SI
block|,
name|IX86_BUILTIN_CVTTPS2PI
block|,
name|IX86_BUILTIN_CVTTSS2SI
block|,
name|IX86_BUILTIN_MAXPS
block|,
name|IX86_BUILTIN_MAXSS
block|,
name|IX86_BUILTIN_MINPS
block|,
name|IX86_BUILTIN_MINSS
block|,
name|IX86_BUILTIN_LOADAPS
block|,
name|IX86_BUILTIN_LOADUPS
block|,
name|IX86_BUILTIN_STOREAPS
block|,
name|IX86_BUILTIN_STOREUPS
block|,
name|IX86_BUILTIN_LOADSS
block|,
name|IX86_BUILTIN_STORESS
block|,
name|IX86_BUILTIN_MOVSS
block|,
name|IX86_BUILTIN_MOVHLPS
block|,
name|IX86_BUILTIN_MOVLHPS
block|,
name|IX86_BUILTIN_LOADHPS
block|,
name|IX86_BUILTIN_LOADLPS
block|,
name|IX86_BUILTIN_STOREHPS
block|,
name|IX86_BUILTIN_STORELPS
block|,
name|IX86_BUILTIN_MASKMOVQ
block|,
name|IX86_BUILTIN_MOVMSKPS
block|,
name|IX86_BUILTIN_PMOVMSKB
block|,
name|IX86_BUILTIN_MOVNTPS
block|,
name|IX86_BUILTIN_MOVNTQ
block|,
name|IX86_BUILTIN_PACKSSWB
block|,
name|IX86_BUILTIN_PACKSSDW
block|,
name|IX86_BUILTIN_PACKUSWB
block|,
name|IX86_BUILTIN_PADDB
block|,
name|IX86_BUILTIN_PADDW
block|,
name|IX86_BUILTIN_PADDD
block|,
name|IX86_BUILTIN_PADDSB
block|,
name|IX86_BUILTIN_PADDSW
block|,
name|IX86_BUILTIN_PADDUSB
block|,
name|IX86_BUILTIN_PADDUSW
block|,
name|IX86_BUILTIN_PSUBB
block|,
name|IX86_BUILTIN_PSUBW
block|,
name|IX86_BUILTIN_PSUBD
block|,
name|IX86_BUILTIN_PSUBSB
block|,
name|IX86_BUILTIN_PSUBSW
block|,
name|IX86_BUILTIN_PSUBUSB
block|,
name|IX86_BUILTIN_PSUBUSW
block|,
name|IX86_BUILTIN_PAND
block|,
name|IX86_BUILTIN_PANDN
block|,
name|IX86_BUILTIN_POR
block|,
name|IX86_BUILTIN_PXOR
block|,
name|IX86_BUILTIN_PAVGB
block|,
name|IX86_BUILTIN_PAVGW
block|,
name|IX86_BUILTIN_PCMPEQB
block|,
name|IX86_BUILTIN_PCMPEQW
block|,
name|IX86_BUILTIN_PCMPEQD
block|,
name|IX86_BUILTIN_PCMPGTB
block|,
name|IX86_BUILTIN_PCMPGTW
block|,
name|IX86_BUILTIN_PCMPGTD
block|,
name|IX86_BUILTIN_PEXTRW
block|,
name|IX86_BUILTIN_PINSRW
block|,
name|IX86_BUILTIN_PMADDWD
block|,
name|IX86_BUILTIN_PMAXSW
block|,
name|IX86_BUILTIN_PMAXUB
block|,
name|IX86_BUILTIN_PMINSW
block|,
name|IX86_BUILTIN_PMINUB
block|,
name|IX86_BUILTIN_PMULHUW
block|,
name|IX86_BUILTIN_PMULHW
block|,
name|IX86_BUILTIN_PMULLW
block|,
name|IX86_BUILTIN_PSADBW
block|,
name|IX86_BUILTIN_PSHUFW
block|,
name|IX86_BUILTIN_PSLLW
block|,
name|IX86_BUILTIN_PSLLD
block|,
name|IX86_BUILTIN_PSLLQ
block|,
name|IX86_BUILTIN_PSRAW
block|,
name|IX86_BUILTIN_PSRAD
block|,
name|IX86_BUILTIN_PSRLW
block|,
name|IX86_BUILTIN_PSRLD
block|,
name|IX86_BUILTIN_PSRLQ
block|,
name|IX86_BUILTIN_PSLLWI
block|,
name|IX86_BUILTIN_PSLLDI
block|,
name|IX86_BUILTIN_PSLLQI
block|,
name|IX86_BUILTIN_PSRAWI
block|,
name|IX86_BUILTIN_PSRADI
block|,
name|IX86_BUILTIN_PSRLWI
block|,
name|IX86_BUILTIN_PSRLDI
block|,
name|IX86_BUILTIN_PSRLQI
block|,
name|IX86_BUILTIN_PUNPCKHBW
block|,
name|IX86_BUILTIN_PUNPCKHWD
block|,
name|IX86_BUILTIN_PUNPCKHDQ
block|,
name|IX86_BUILTIN_PUNPCKLBW
block|,
name|IX86_BUILTIN_PUNPCKLWD
block|,
name|IX86_BUILTIN_PUNPCKLDQ
block|,
name|IX86_BUILTIN_SHUFPS
block|,
name|IX86_BUILTIN_RCPPS
block|,
name|IX86_BUILTIN_RCPSS
block|,
name|IX86_BUILTIN_RSQRTPS
block|,
name|IX86_BUILTIN_RSQRTSS
block|,
name|IX86_BUILTIN_SQRTPS
block|,
name|IX86_BUILTIN_SQRTSS
block|,
name|IX86_BUILTIN_UNPCKHPS
block|,
name|IX86_BUILTIN_UNPCKLPS
block|,
name|IX86_BUILTIN_ANDPS
block|,
name|IX86_BUILTIN_ANDNPS
block|,
name|IX86_BUILTIN_ORPS
block|,
name|IX86_BUILTIN_XORPS
block|,
name|IX86_BUILTIN_EMMS
block|,
name|IX86_BUILTIN_LDMXCSR
block|,
name|IX86_BUILTIN_STMXCSR
block|,
name|IX86_BUILTIN_SFENCE
block|,
comment|/* 3DNow! Original */
name|IX86_BUILTIN_FEMMS
block|,
name|IX86_BUILTIN_PAVGUSB
block|,
name|IX86_BUILTIN_PF2ID
block|,
name|IX86_BUILTIN_PFACC
block|,
name|IX86_BUILTIN_PFADD
block|,
name|IX86_BUILTIN_PFCMPEQ
block|,
name|IX86_BUILTIN_PFCMPGE
block|,
name|IX86_BUILTIN_PFCMPGT
block|,
name|IX86_BUILTIN_PFMAX
block|,
name|IX86_BUILTIN_PFMIN
block|,
name|IX86_BUILTIN_PFMUL
block|,
name|IX86_BUILTIN_PFRCP
block|,
name|IX86_BUILTIN_PFRCPIT1
block|,
name|IX86_BUILTIN_PFRCPIT2
block|,
name|IX86_BUILTIN_PFRSQIT1
block|,
name|IX86_BUILTIN_PFRSQRT
block|,
name|IX86_BUILTIN_PFSUB
block|,
name|IX86_BUILTIN_PFSUBR
block|,
name|IX86_BUILTIN_PI2FD
block|,
name|IX86_BUILTIN_PMULHRW
block|,
comment|/* 3DNow! Athlon Extensions */
name|IX86_BUILTIN_PF2IW
block|,
name|IX86_BUILTIN_PFNACC
block|,
name|IX86_BUILTIN_PFPNACC
block|,
name|IX86_BUILTIN_PI2FW
block|,
name|IX86_BUILTIN_PSWAPDSI
block|,
name|IX86_BUILTIN_PSWAPDSF
block|,
name|IX86_BUILTIN_SSE_ZERO
block|,
name|IX86_BUILTIN_MMX_ZERO
block|,
name|IX86_BUILTIN_MAX
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     On i386, if using PIC, mark a SYMBOL_REF for a non-global symbol    so that we may access it directly in the GOT.  */
end_comment

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|do {								\     if (flag_pic)						\       {								\ 	rtx rtl = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'	\ 		   ? TREE_CST_RTL (DECL) : DECL_RTL (DECL));	\ 								\ 	if (GET_CODE (rtl) == MEM)				\ 	  {							\ 	    if (TARGET_DEBUG_ADDR				\&& TREE_CODE_CLASS (TREE_CODE (DECL)) == 'd')	\ 	      {							\ 		fprintf (stderr, "Encode %s, public = %d\n",	\ 			 IDENTIFIER_POINTER (DECL_NAME (DECL)),	\ 			 TREE_PUBLIC (DECL));			\ 	      }							\ 	    							\ 	    SYMBOL_REF_FLAG (XEXP (rtl, 0))			\ 	      = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'	\ 		 || ! TREE_PUBLIC (DECL));			\ 	  }							\       }								\ } while (0)
end_define

begin_comment
comment|/* The `FINALIZE_PIC' macro serves as a hook to emit these special    codes once the function is being compiled into assembly code, but    not before.  (It is not done before, because in the case of    compiling an inline function, it would lead to multiple PIC    prologues being included in functions which used inline functions    and were compiled to assembly language.)  */
end_comment

begin_define
define|#
directive|define
name|FINALIZE_PIC
define|\
value|(current_function_uses_pic_offset_table |= current_function_profile)
end_define

begin_escape
end_escape

begin_comment
comment|/* Max number of args passed in registers.  If this is more than 3, we will    have problems with ebx (register #4), since it is a caller save register and    is also used as the pic register in ELF.  So for now, don't allow more than    3 registers to be passed in registers.  */
end_comment

begin_define
define|#
directive|define
name|REGPARM_MAX
value|(TARGET_64BIT ? 6 : 3)
end_define

begin_define
define|#
directive|define
name|SSE_REGPARM_MAX
value|(TARGET_64BIT ? 8 : 0)
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
value|(!TARGET_64BIT || flag_pic ? SImode : DImode)
end_define

begin_comment
comment|/* Define as C expression which evaluates to nonzero if the tablejump    instruction expects the table to contain offsets from the address of the    table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_comment
comment|/* #define CASE_VECTOR_PC_RELATIVE 1 */
end_comment

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* Number of bytes moved into a data cache for a single prefetch operation.  */
end_comment

begin_define
define|#
directive|define
name|PREFETCH_BLOCK
value|ix86_cost->prefetch_block
end_define

begin_comment
comment|/* Number of prefetch operations that can be done in parallel.  */
end_comment

begin_define
define|#
directive|define
name|SIMULTANEOUS_PREFETCHES
value|ix86_cost->simultaneous_prefetches
end_define

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|16
end_define

begin_comment
comment|/* MOVE_MAX_PIECES is the number of bytes at a time which we can    move efficiently, as opposed to  MOVE_MAX which is the maximum    number of bytes we can move with a single instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX_PIECES
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_comment
comment|/* If a memory-to-memory move would take MOVE_RATIO or more simple    move-instruction pairs, we will do a movstr or libcall instead.    Increasing the value will always make code faster, but eventually    incurs high cost in increased code size.     If you don't define this, a reasonable default is used.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_RATIO
value|(optimize_size ? 3 : ix86_cost->move_ratio)
end_define

begin_comment
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.  */
end_comment

begin_comment
comment|/* On i386, shifts do truncate the count.  But bit opcodes don't.  */
end_comment

begin_comment
comment|/* #define SHIFT_COUNT_TRUNCATED */
end_comment

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
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_comment
comment|/* When a prototype says `char' or `short', really pass an `int'.    (The 386 can't easily push less than an int.)  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
value|1
end_define

begin_comment
comment|/* A macro to update M and UNSIGNEDP when an object whose type is    TYPE and which has the specified mode and signedness is to be    stored in a register.  This macro is only called when TYPE is a    scalar type.     On i386 it is sometimes useful to promote HImode and QImode    quantities to SImode.  The choice depends on target type.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_MODE
parameter_list|(
name|MODE
parameter_list|,
name|UNSIGNEDP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|do {							\   if (((MODE) == HImode&& TARGET_PROMOTE_HI_REGS)	\       || ((MODE) == QImode&& TARGET_PROMOTE_QI_REGS))	\     (MODE) = SImode;					\ } while (0)
end_define

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|(TARGET_64BIT ? DImode : SImode)
end_define

begin_comment
comment|/* A function address in a call instruction    is a byte address (for indexing purposes)    so give the MEM rtx a byte's mode.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|QImode
end_define

begin_escape
end_escape

begin_comment
comment|/* A part of a C `switch' statement that describes the relative costs    of constant RTL expressions.  It must contain `case' labels for    expression codes `const_int', `const', `symbol_ref', `label_ref'    and `const_double'.  Each case must ultimately reach a `return'    statement to return the relative cost of the use of that kind of    constant value in an expression.  The cost may depend on the    precise value of the constant, which is available for examination    in X, and the rtx code of the expression in which it is contained,    found in OUTER_CODE.       CODE is the expression code--redundant, since it can be obtained    with `GET_CODE (X)'.  */
end_comment

begin_define
define|#
directive|define
name|CONST_COSTS
parameter_list|(
name|RTX
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case CONST_INT:						\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     if (TARGET_64BIT&& !x86_64_sign_extended_value (RTX))	\       return 3;							\     if (TARGET_64BIT&& !x86_64_zero_extended_value (RTX))	\       return 2;							\     return flag_pic&& SYMBOLIC_CONST (RTX) ? 1 : 0;		\ 								\   case CONST_DOUBLE:						\     {								\       int code;							\       if (GET_MODE (RTX) == VOIDmode)				\ 	return 0;						\ 								\       code = standard_80387_constant_p (RTX);			\       return code == 1 ? 1 :					\ 	     code == 2 ? 2 :					\ 			 3;					\     }
end_define

begin_comment
comment|/* Delete the definition here when TOPLEVEL_COSTS_N_INSNS gets added to cse.c */
end_comment

begin_define
define|#
directive|define
name|TOPLEVEL_COSTS_N_INSNS
parameter_list|(
name|N
parameter_list|)
define|\
value|do { total = COSTS_N_INSNS (N); goto egress_rtx_costs; } while (0)
end_define

begin_comment
comment|/* Like `CONST_COSTS' but applies to nonconstant RTL expressions.    This can be used, for example, to indicate how costly a multiply    instruction is.  In writing this macro, you can use the construct    `COSTS_N_INSNS (N)' to specify a cost equal to N fast    instructions.  OUTER_CODE is the code of the expression in which X    is contained.     This macro is optional; do not define it if the default cost    assumptions are adequate for the target machine.  */
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
value|case ZERO_EXTEND:							\
comment|/* The zero extensions is often completely free on x86_64, so make	\        it as cheap as possible.  */
value|\     if (TARGET_64BIT&& GET_MODE (X) == DImode				\&& GET_MODE (XEXP (X, 0)) == SImode)				\       {									\ 	total = 1; goto egress_rtx_costs;				\       } 								\     else								\       TOPLEVEL_COSTS_N_INSNS (TARGET_ZERO_EXTEND_WITH_AND ?		\ 			      ix86_cost->add : ix86_cost->movzx);	\     break;								\   case SIGN_EXTEND:							\     TOPLEVEL_COSTS_N_INSNS (ix86_cost->movsx);				\     break;								\   case ASHIFT:								\     if (GET_CODE (XEXP (X, 1)) == CONST_INT				\&& (GET_MODE (XEXP (X, 0)) != DImode || TARGET_64BIT))		\       {									\ 	HOST_WIDE_INT value = INTVAL (XEXP (X, 1));			\ 	if (value == 1)							\ 	  TOPLEVEL_COSTS_N_INSNS (ix86_cost->add);			\ 	if ((value == 2 || value == 3)					\&& !TARGET_DECOMPOSE_LEA					\&& ix86_cost->lea<= ix86_cost->shift_const)		\ 	  TOPLEVEL_COSTS_N_INSNS (ix86_cost->lea);			\       }									\
comment|/* fall through */
value|\ 		  							\   case ROTATE:								\   case ASHIFTRT:							\   case LSHIFTRT:							\   case ROTATERT:							\     if (!TARGET_64BIT&& GET_MODE (XEXP (X, 0)) == DImode)		\       {									\ 	if (GET_CODE (XEXP (X, 1)) == CONST_INT)			\ 	  {								\ 	    if (INTVAL (XEXP (X, 1))> 32)				\ 	      TOPLEVEL_COSTS_N_INSNS(ix86_cost->shift_const + 2);	\ 	    else							\ 	      TOPLEVEL_COSTS_N_INSNS(ix86_cost->shift_const * 2);	\ 	  }								\ 	else								\ 	  {								\ 	    if (GET_CODE (XEXP (X, 1)) == AND)				\ 	      TOPLEVEL_COSTS_N_INSNS(ix86_cost->shift_var * 2);		\ 	    else							\ 	      TOPLEVEL_COSTS_N_INSNS(ix86_cost->shift_var * 6 + 2);	\ 	  }								\       }									\     else								\       {									\ 	if (GET_CODE (XEXP (X, 1)) == CONST_INT)			\ 	  TOPLEVEL_COSTS_N_INSNS (ix86_cost->shift_const);		\ 	else								\ 	  TOPLEVEL_COSTS_N_INSNS (ix86_cost->shift_var);		\       }									\     break;								\ 									\   case MULT:								\     if (GET_CODE (XEXP (X, 1)) == CONST_INT)				\       {									\ 	unsigned HOST_WIDE_INT value = INTVAL (XEXP (X, 1));		\ 	int nbits = 0;							\ 									\ 	while (value != 0)						\ 	  {								\ 	    nbits++;							\ 	    value>>= 1;						\ 	  } 								\ 									\ 	TOPLEVEL_COSTS_N_INSNS (ix86_cost->mult_init			\ 			        + nbits * ix86_cost->mult_bit);		\       }									\     else
comment|/* This is arbitrary */
value|\       TOPLEVEL_COSTS_N_INSNS (ix86_cost->mult_init			\ 			      + 7 * ix86_cost->mult_bit);		\ 									\   case DIV:								\   case UDIV:								\   case MOD:								\   case UMOD:								\     TOPLEVEL_COSTS_N_INSNS (ix86_cost->divide);				\ 									\   case PLUS:								\     if (!TARGET_DECOMPOSE_LEA						\&& INTEGRAL_MODE_P (GET_MODE (X))				\&& GET_MODE_BITSIZE (GET_MODE (X))<= GET_MODE_BITSIZE (Pmode))	\       {									\         if (GET_CODE (XEXP (X, 0)) == PLUS				\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == MULT			\&& GET_CODE (XEXP (XEXP (XEXP (X, 0), 0), 1)) == CONST_INT	\&& CONSTANT_P (XEXP (X, 1)))				\ 	  {								\ 	    HOST_WIDE_INT val = INTVAL (XEXP (XEXP (XEXP (X, 0), 0), 1));\ 	    if (val == 2 || val == 4 || val == 8)			\ 	      {								\ 		return (COSTS_N_INSNS (ix86_cost->lea)			\ 			+ rtx_cost (XEXP (XEXP (X, 0), 1),		\ 				    (OUTER_CODE))			\ 			+ rtx_cost (XEXP (XEXP (XEXP (X, 0), 0), 0),	\ 				    (OUTER_CODE))			\ 			+ rtx_cost (XEXP (X, 1), (OUTER_CODE)));	\ 	      }								\ 	  }								\ 	else if (GET_CODE (XEXP (X, 0)) == MULT				\&& GET_CODE (XEXP (XEXP (X, 0), 1)) == CONST_INT)	\ 	  {								\ 	    HOST_WIDE_INT val = INTVAL (XEXP (XEXP (X, 0), 1));		\ 	    if (val == 2 || val == 4 || val == 8)			\ 	      {								\ 		return (COSTS_N_INSNS (ix86_cost->lea)			\ 			+ rtx_cost (XEXP (XEXP (X, 0), 0),		\ 				    (OUTER_CODE))			\ 			+ rtx_cost (XEXP (X, 1), (OUTER_CODE)));	\ 	      }								\ 	  }								\ 	else if (GET_CODE (XEXP (X, 0)) == PLUS)			\ 	  {								\ 	    return (COSTS_N_INSNS (ix86_cost->lea)			\ 		    + rtx_cost (XEXP (XEXP (X, 0), 0), (OUTER_CODE))	\ 		    + rtx_cost (XEXP (XEXP (X, 0), 1), (OUTER_CODE))	\ 		    + rtx_cost (XEXP (X, 1), (OUTER_CODE)));		\ 	  }								\       }									\ 									\
comment|/* fall through */
value|\   case AND:								\   case IOR:								\   case XOR:								\   case MINUS:								\     if (!TARGET_64BIT&& GET_MODE (X) == DImode)			\       return (COSTS_N_INSNS (ix86_cost->add) * 2			\ 	      + (rtx_cost (XEXP (X, 0), (OUTER_CODE))			\<< (GET_MODE (XEXP (X, 0)) != DImode))			\ 	      + (rtx_cost (XEXP (X, 1), (OUTER_CODE))			\<< (GET_MODE (XEXP (X, 1)) != DImode)));		\ 									\
comment|/* fall through */
value|\   case NEG:								\   case NOT:								\     if (!TARGET_64BIT&& GET_MODE (X) == DImode)			\       TOPLEVEL_COSTS_N_INSNS (ix86_cost->add * 2);			\     TOPLEVEL_COSTS_N_INSNS (ix86_cost->add);				\ 									\   egress_rtx_costs:							\     break;
end_define

begin_comment
comment|/* An expression giving the cost of an addressing mode that contains    ADDRESS.  If not defined, the cost is computed from the ADDRESS    expression and the `CONST_COSTS' values.     For most CISC machines, the default cost is a good approximation    of the true cost of the addressing mode.  However, on RISC    machines, all instructions normally have the same length and    execution time.  Hence all addresses will have equal costs.     In cases where more than one form of an address is known, the form    with the lowest cost will be used.  If multiple forms have the    same, lowest, cost, the one that is the most complex will be used.     For example, suppose an address that is equal to the sum of a    register and a constant is used twice in the same basic block.    When this macro is not defined, the address will be computed in a    register and memory references will be indirect through that    register.  On machines where the cost of the addressing mode    containing the sum is no higher than that of a simple indirect    reference, this will produce an additional instruction and    possibly require an additional register.  Proper specification of    this macro eliminates this overhead for such machines.     Similar use of this macro is made in strength reduction of loops.     ADDRESS need not be valid as an address.  In such a case, the cost    is not relevant and can be any value; invalid addresses need not be    assigned a different cost.     On machines where an address involving more than one register is as    cheap as an address computation involving only one register,    defining `ADDRESS_COST' to reflect this can cause two registers to    be live over a region of code where only one would have been if    `ADDRESS_COST' were not defined in that manner.  This effect should    be considered in the definition of this macro.  Equivalent costs    should probably only be given to addresses with different numbers    of registers on machines with lots of registers.     This macro will normally either not be defined or be defined as a    constant.     For i386, it is better to use a complex address than let gcc copy    the address into a reg and make a new pseudo.  But not if the address    requires to two regs - that would mean more pseudos with longer    lifetimes.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
define|\
value|ix86_address_cost (RTX)
end_define

begin_comment
comment|/* A C expression for the cost of moving data from a register in class FROM to    one in class TO.  The classes are expressed using the enumeration values    such as `GENERAL_REGS'.  A value of 2 is the default; other values are    interpreted relative to that.     It is not required that the cost always equal 2 when FROM is the same as TO;    on some machines it is expensive to move between registers if they are not    general registers.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|)
define|\
value|ix86_register_move_cost ((MODE), (CLASS1), (CLASS2))
end_define

begin_comment
comment|/* A C expression for the cost of moving data of mode M between a    register and memory.  A value of 2 is the default; this cost is    relative to those in `REGISTER_MOVE_COST'.     If moving between registers and memory is more expensive than    between two registers, you should define this macro to express the    relative cost.  */
end_comment

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|CLASS
parameter_list|,
name|IN
parameter_list|)
define|\
value|ix86_memory_move_cost ((MODE), (CLASS), (IN))
end_define

begin_comment
comment|/* A C expression for the cost of a branch instruction.  A value of 1    is the default; other values are interpreted relative to that.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
value|ix86_branch_cost
end_define

begin_comment
comment|/* Define this macro as a C expression which is nonzero if accessing    less than a word of memory (i.e. a `char' or a `short') is no    faster than accessing a word of memory, i.e., if such access    require more than one instruction or if there is no difference in    cost between byte and (aligned) word loads.     When this macro is not defined, the compiler will access a field by    finding the smallest containing object; when it is defined, a    fullword load will be used if alignment permits.  Unless bytes    accesses are faster than word accesses, using word accesses is    preferable since it may eliminate subsequent memory access if    subsequent accesses occur to other fields in the same word of the    structure, but to different bytes.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
end_define

begin_comment
comment|/* Nonzero if access to memory by shorts is slow and undesirable.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_SHORT_ACCESS
value|0
end_define

begin_comment
comment|/* Define this macro to be the value 1 if unaligned accesses have a    cost many times greater than aligned accesses, for example if they    are emulated in a trap handler.     When this macro is non-zero, the compiler will act as if    `STRICT_ALIGNMENT' were non-zero when generating code for block    moves.  This can cause significantly more instructions to be    produced.  Therefore, do not set this macro non-zero if unaligned    accesses only add a cycle or two to the time for a memory access.     If the value of this macro is always zero, it need not be defined.  */
end_comment

begin_comment
comment|/* #define SLOW_UNALIGNED_ACCESS(MODE, ALIGN) 0 */
end_comment

begin_comment
comment|/* Define this macro to inhibit strength reduction of memory    addresses.  (On some machines, such strength reduction seems to do    harm rather than good.)  */
end_comment

begin_comment
comment|/* #define DONT_REDUCE_ADDR */
end_comment

begin_comment
comment|/* Define this macro if it is as good or better to call a constant    function address than to call an address kept in a register.     Desirable on the 386 because a CALL with a constant address is    faster than one with a register address.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* Define this macro if it is as good or better for a function to call    itself with an explicit address than to call an address kept in a    register.  */
end_comment

begin_define
define|#
directive|define
name|NO_RECURSIVE_FUNCTION_CSE
end_define

begin_escape
end_escape

begin_comment
comment|/* Add any extra modes needed to represent the condition code.     For the i386, we need separate modes when floating-point    equality comparisons are being done.         Add CCNO to indicate comparisons against zero that requires    Overflow flag to be unset.  Sign bit test is used instead and    thus can be used to form "a&b>0" type of tests.     Add CCGC to indicate comparisons agains zero that allows    unspecified garbage in the Carry flag.  This mode is used    by inc/dec instructions.     Add CCGOC to indicate comparisons agains zero that allows    unspecified garbage in the Carry and Overflow flag. This    mode is used to simulate comparisons of (a-b) and (a+b)    against zero using sub/cmp/add operations.     Add CCZ to indicate that only the Zero flag is valid.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
define|\
value|CC (CCGCmode, "CCGC")	\ 	CC (CCGOCmode, "CCGOC")	\ 	CC (CCNOmode, "CCNO")	\ 	CC (CCZmode, "CCZ")	\ 	CC (CCFPmode, "CCFP")	\ 	CC (CCFPUmode, "CCFPU")
end_define

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.     For floating-point equality comparisons, CCFPEQmode should be used.    VOIDmode should be used in all other cases.     For integer comparisons against zero, reduce to CCNOmode or CCZmode if    possible, to allow for more combinations.  */
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
value|ix86_cc_mode ((OP), (X), (Y))
end_define

begin_comment
comment|/* Return non-zero if MODE implies a floating point inequality can be    reversed.  */
end_comment

begin_define
define|#
directive|define
name|REVERSIBLE_CC_MODE
parameter_list|(
name|MODE
parameter_list|)
value|1
end_define

begin_comment
comment|/* A C expression whose value is reversed condition code of the CODE for    comparison done in CC_MODE mode.  */
end_comment

begin_define
define|#
directive|define
name|REVERSE_CONDITION
parameter_list|(
name|CODE
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((MODE) != CCFPmode&& (MODE) != CCFPUmode ? reverse_condition (CODE) \    : reverse_condition_maybe_unordered (CODE))
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output, to the extent    this does not vary between assemblers.  */
end_comment

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_comment
comment|/* In order to refer to the first 8 regs as 32 bit regs prefix an "e"    For non floating point regs, the following are the HImode names.     For float regs, the stack top is sometimes referred to as "%st(0)"    instead of just "%st".  PRINT_REG handles this with the "y" code.  */
end_comment

begin_undef
undef|#
directive|undef
name|HI_REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|HI_REGISTER_NAMES
define|\
value|{"ax","dx","cx","bx","si","di","bp","sp",				\  "st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)","",	\  "flags","fpsr", "dirflag", "frame",					\  "xmm0","xmm1","xmm2","xmm3","xmm4","xmm5","xmm6","xmm7",		\  "mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7"	,		\  "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",			\  "xmm8", "xmm9", "xmm10", "xmm11", "xmm12", "xmm13", "xmm14", "xmm15"}
end_define

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|HI_REGISTER_NAMES
end_define

begin_comment
comment|/* Table of additional register names to use in user input.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{ { "eax", 0 }, { "edx", 1 }, { "ecx", 2 }, { "ebx", 3 },	\   { "esi", 4 }, { "edi", 5 }, { "ebp", 6 }, { "esp", 7 },	\   { "rax", 0 }, { "rdx", 1 }, { "rcx", 2 }, { "rbx", 3 },	\   { "rsi", 4 }, { "rdi", 5 }, { "rbp", 6 }, { "rsp", 7 },	\   { "al", 0 }, { "dl", 1 }, { "cl", 2 }, { "bl", 3 },		\   { "ah", 0 }, { "dh", 1 }, { "ch", 2 }, { "bh", 3 },		\   { "mm0", 8},  { "mm1", 9},  { "mm2", 10}, { "mm3", 11},	\   { "mm4", 12}, { "mm5", 13}, { "mm6", 14}, { "mm7", 15} }
end_define

begin_comment
comment|/* Note we are omitting these since currently I don't know how to get gcc to use these, since they want the same but different number as al, and ax. */
end_comment

begin_define
define|#
directive|define
name|QI_REGISTER_NAMES
define|\
value|{"al", "dl", "cl", "bl", "sil", "dil", "bpl", "spl",}
end_define

begin_comment
comment|/* These parallel the array above, and can be used to access bits 8:15    of regs 0 through 3.  */
end_comment

begin_define
define|#
directive|define
name|QI_HIGH_REGISTER_NAMES
define|\
value|{"ah", "dh", "ch", "bh", }
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|N
parameter_list|)
define|\
value|(TARGET_64BIT ? dbx64_register_map[(N)] : dbx_register_map[(N)])
end_define

begin_decl_stmt
specifier|extern
name|int
specifier|const
name|dbx_register_map
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
specifier|const
name|dbx64_register_map
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
specifier|const
name|svr4_dbx_register_map
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Before the prologue, RA is at 0(%esp).  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
define|\
value|gen_rtx_MEM (VOIDmode, gen_rtx_REG (VOIDmode, STACK_POINTER_REGNUM))
end_define

begin_comment
comment|/* After the prologue, RA is at -4(AP) in the current frame.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_RTX
parameter_list|(
name|COUNT
parameter_list|,
name|FRAME
parameter_list|)
define|\
value|((COUNT) == 0								   \    ? gen_rtx_MEM (Pmode, plus_constant (arg_pointer_rtx, -UNITS_PER_WORD)) \    : gen_rtx_MEM (Pmode, plus_constant (FRAME, UNITS_PER_WORD)))
end_define

begin_comment
comment|/* PC is dbx register 8; let's use that column for RA.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|(TARGET_64BIT ? 16 : 8)
end_define

begin_comment
comment|/* Before the prologue, the top of the frame is at 4(%esp).  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_FRAME_SP_OFFSET
value|UNITS_PER_WORD
end_define

begin_comment
comment|/* Describe how we implement __builtin_eh_return.  */
end_comment

begin_define
define|#
directive|define
name|EH_RETURN_DATA_REGNO
parameter_list|(
name|N
parameter_list|)
value|((N)< 2 ? (N) : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|EH_RETURN_STACKADJ_RTX
value|gen_rtx_REG (Pmode, 2)
end_define

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.     ??? All x86 object file formats are capable of representing this.    After all, the relocation needed is the same as for the call insn.    Whether or not a particular assembler allows us to enter such, I    guess we'll have to see.  */
end_comment

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
define|\
value|(flag_pic								\     ? ((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel | DW_EH_PE_sdata4\    : DW_EH_PE_absptr)
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
value|(assemble_name ((FILE), (NAME)), fputs (":\n", (FILE)))
end_define

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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\   sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
end_define

begin_comment
comment|/* This is how to output an insn to push a register on the stack.    It need not be very fast code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|asm_fprintf ((FILE), "\tpush{l}\t%%e%s\n", reg_names[(REGNO)])
end_define

begin_comment
comment|/* This is how to output an insn to pop a register from the stack.    It need not be very fast code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|asm_fprintf ((FILE), "\tpop{l}\t%%e%s\n", reg_names[(REGNO)])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
end_comment

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
value|ix86_output_addr_vec_elt ((FILE), (VALUE))
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.  */
end_comment

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
define|\
value|ix86_output_addr_diff_elt ((FILE), (VALUE), (REL))
end_define

begin_comment
comment|/* Under some conditions we need jump tables in the text section, because    the assembler cannot handle label differences between sections.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
define|\
value|(!TARGET_64BIT&& flag_pic&& !HAVE_AS_GOTOFF_IN_DATA)
end_define

begin_comment
comment|/* A C statement that outputs an address constant appropriate to     for DWARF debugging.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DWARF_ADDR_CONST
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|)
define|\
value|i386_dwarf_output_addr_const ((FILE), (X))
end_define

begin_comment
comment|/* Either simplify a location expression, or return the original.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SIMPLIFY_DWARF_ADDR
parameter_list|(
name|X
parameter_list|)
define|\
value|i386_simplify_dwarf_addr (X)
end_define

begin_comment
comment|/* Switch to init or fini section via SECTION_OP, emit a call to FUNC,    and switch back.  For x86 we do this only to save a few bytes that    would otherwise be unused in the text section.  */
end_comment

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|asm (SECTION_OP "\n\t"				\ 	"call " USER_LABEL_PREFIX #FUNC "\n"		\ 	TEXT_SECTION_ASM_OP);
end_define

begin_escape
end_escape

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    Effect of various CODE letters is described in i386.c near    print_operand function.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '*' || (CODE) == '+')
end_define

begin_comment
comment|/* Print the name of a register based on its machine mode and number.    If CODE is 'w', pretend the mode is HImode.    If CODE is 'b', pretend the mode is QImode.    If CODE is 'k', pretend the mode is SImode.    If CODE is 'q', pretend the mode is DImode.    If CODE is 'h', pretend the reg is the `high' byte register.    If CODE is 'y', print "st(0)" instead of "st", if the reg is stack op.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_REG
parameter_list|(
name|X
parameter_list|,
name|CODE
parameter_list|,
name|FILE
parameter_list|)
define|\
value|print_reg ((X), (CODE), (FILE))
end_define

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
define|\
value|print_operand ((FILE), (X), (CODE))
end_define

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|print_operand_address ((FILE), (ADDR))
end_define

begin_comment
comment|/* Print the name of a register for based on its machine mode and number.    This macro is used to print debugging output.    This macro is different from PRINT_REG in that it may be used in    programs that are not linked with aux-output.o.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_PRINT_REG
parameter_list|(
name|X
parameter_list|,
name|CODE
parameter_list|,
name|FILE
parameter_list|)
define|\
value|do { static const char * const hi_name[] = HI_REGISTER_NAMES;	\        static const char * const qi_name[] = QI_REGISTER_NAMES;	\        fprintf ((FILE), "%d ", REGNO (X));		\        if (REGNO (X) == FLAGS_REG)			\ 	 { fputs ("flags", (FILE)); break; }		\        if (REGNO (X) == DIRFLAG_REG)			\ 	 { fputs ("dirflag", (FILE)); break; }		\        if (REGNO (X) == FPSR_REG)			\ 	 { fputs ("fpsr", (FILE)); break; }		\        if (REGNO (X) == ARG_POINTER_REGNUM)		\ 	 { fputs ("argp", (FILE)); break; }		\        if (REGNO (X) == FRAME_POINTER_REGNUM)		\ 	 { fputs ("frame", (FILE)); break; }		\        if (STACK_TOP_P (X))				\ 	 { fputs ("st(0)", (FILE)); break; }		\        if (FP_REG_P (X))				\ 	 { fputs (hi_name[REGNO(X)], (FILE)); break; }	\        if (REX_INT_REG_P (X))				\ 	 {						\ 	   switch (GET_MODE_SIZE (GET_MODE (X)))	\ 	     {						\ 	     default:					\ 	     case 8:					\ 	       fprintf ((FILE), "r%i", REGNO (X)	\ 			- FIRST_REX_INT_REG + 8);	\ 	       break;					\ 	     case 4:					\ 	       fprintf ((FILE), "r%id", REGNO (X)	\ 			- FIRST_REX_INT_REG + 8);	\ 	       break;					\ 	     case 2:					\ 	       fprintf ((FILE), "r%iw", REGNO (X)	\ 			- FIRST_REX_INT_REG + 8);	\ 	       break;					\ 	     case 1:					\ 	       fprintf ((FILE), "r%ib", REGNO (X)	\ 			- FIRST_REX_INT_REG + 8);	\ 	       break;					\ 	     }						\ 	   break;					\ 	 }						\        switch (GET_MODE_SIZE (GET_MODE (X)))		\ 	 {						\ 	 case 8:					\ 	   fputs ("r", (FILE));				\ 	   fputs (hi_name[REGNO (X)], (FILE));		\ 	   break;					\ 	 default:					\ 	   fputs ("e", (FILE));				\ 	 case 2:					\ 	   fputs (hi_name[REGNO (X)], (FILE));		\ 	   break;					\ 	 case 1:					\ 	   fputs (qi_name[REGNO (X)], (FILE));		\ 	   break;					\ 	 }						\      } while (0)
end_define

begin_comment
comment|/* a letter which is not needed by the normal asm syntax, which    we can use for operand syntax in the extended asm */
end_comment

begin_define
define|#
directive|define
name|ASM_OPERAND_LETTER
value|'#'
end_define

begin_define
define|#
directive|define
name|RET
value|return ""
end_define

begin_define
define|#
directive|define
name|AT_SP
parameter_list|(
name|MODE
parameter_list|)
value|(gen_rtx_MEM ((MODE), stack_pointer_rtx))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the codes that are matched by predicates in i386.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"x86_64_immediate_operand", {CONST_INT, SUBREG, REG,			\ 				SYMBOL_REF, LABEL_REF, CONST}},		\   {"x86_64_nonmemory_operand", {CONST_INT, SUBREG, REG,			\ 				SYMBOL_REF, LABEL_REF, CONST}},		\   {"x86_64_movabs_operand", {CONST_INT, SUBREG, REG,			\ 				SYMBOL_REF, LABEL_REF, CONST}},		\   {"x86_64_szext_nonmemory_operand", {CONST_INT, SUBREG, REG,		\ 				     SYMBOL_REF, LABEL_REF, CONST}},	\   {"x86_64_general_operand", {CONST_INT, SUBREG, REG, MEM,		\ 			      SYMBOL_REF, LABEL_REF, CONST}},		\   {"x86_64_szext_general_operand", {CONST_INT, SUBREG, REG, MEM,	\ 				   SYMBOL_REF, LABEL_REF, CONST}},	\   {"x86_64_zext_immediate_operand", {CONST_INT, CONST_DOUBLE, CONST,	\ 				       SYMBOL_REF, LABEL_REF}},		\   {"shiftdi_operand", {SUBREG, REG, MEM}},				\   {"const_int_1_operand", {CONST_INT}},					\   {"symbolic_operand", {SYMBOL_REF, LABEL_REF, CONST}},			\   {"aligned_operand", {CONST_INT, CONST_DOUBLE, CONST, SYMBOL_REF,	\ 		       LABEL_REF, SUBREG, REG, MEM}},			\   {"pic_symbolic_operand", {CONST}},					\   {"call_insn_operand", {REG, SUBREG, MEM, SYMBOL_REF}},		\   {"constant_call_address_operand", {SYMBOL_REF, CONST}},		\   {"const0_operand", {CONST_INT, CONST_DOUBLE}},			\   {"const1_operand", {CONST_INT}},					\   {"const248_operand", {CONST_INT}},					\   {"incdec_operand", {CONST_INT}},					\   {"mmx_reg_operand", {REG}},						\   {"reg_no_sp_operand", {SUBREG, REG}},					\   {"general_no_elim_operand", {CONST_INT, CONST_DOUBLE, CONST,		\ 			SYMBOL_REF, LABEL_REF, SUBREG, REG, MEM}},	\   {"nonmemory_no_elim_operand", {CONST_INT, REG, SUBREG}},		\   {"q_regs_operand", {SUBREG, REG}},					\   {"non_q_regs_operand", {SUBREG, REG}},				\   {"fcmov_comparison_operator", {EQ, NE, LTU, GTU, LEU, GEU, UNORDERED, \ 				 ORDERED, LT, UNLT, GT, UNGT, LE, UNLE,	\ 				 GE, UNGE, LTGT, UNEQ}},		\   {"sse_comparison_operator", {EQ, LT, LE, UNORDERED, NE, UNGE, UNGT,	\ 			       ORDERED, UNEQ, UNLT, UNLE, LTGT, GE, GT	\ 			       }},					\   {"ix86_comparison_operator", {EQ, NE, LE, LT, GE, GT, LEU, LTU, GEU,	\ 			       GTU, UNORDERED, ORDERED, UNLE, UNLT,	\ 			       UNGE, UNGT, LTGT, UNEQ }},		\   {"cmp_fp_expander_operand", {CONST_DOUBLE, SUBREG, REG, MEM}},	\   {"ext_register_operand", {SUBREG, REG}},				\   {"binary_fp_operator", {PLUS, MINUS, MULT, DIV}},			\   {"mult_operator", {MULT}},						\   {"div_operator", {DIV}},						\   {"arith_or_logical_operator", {PLUS, MULT, AND, IOR, XOR, SMIN, SMAX, \ 				 UMIN, UMAX, COMPARE, MINUS, DIV, MOD,	\ 				 UDIV, UMOD, ASHIFT, ROTATE, ASHIFTRT,	\ 				 LSHIFTRT, ROTATERT}},			\   {"promotable_binary_operator", {PLUS, MULT, AND, IOR, XOR, ASHIFT}},	\   {"memory_displacement_operand", {MEM}},				\   {"cmpsi_operand", {CONST_INT, CONST_DOUBLE, CONST, SYMBOL_REF,	\ 		     LABEL_REF, SUBREG, REG, MEM, AND}},		\   {"long_memory_operand", {MEM}},
end_define

begin_comment
comment|/* A list of predicates that do special things with modes, and so    should not elicit warnings for VOIDmode match_operand.  */
end_comment

begin_define
define|#
directive|define
name|SPECIAL_MODE_PREDICATES
define|\
value|"ext_register_operand",
end_define

begin_escape
end_escape

begin_comment
comment|/* CM_32 is used by 32bit ABI    CM_SMALL is small model assuming that all code and data fits in the first    31bits of address space.    CM_KERNEL is model assuming that all code and data fits in the negative    31bits of address space.    CM_MEDIUM is model assuming that code fits in the first 31bits of address    space.  Size of data is unlimited.    CM_LARGE is model making no assumptions about size of particular sections.       CM_SMALL_PIC is model for PIC libraries assuming that code+data+got/plt    tables first in 31bits of address space.  */
end_comment

begin_enum
enum|enum
name|cmodel
block|{
name|CM_32
block|,
name|CM_SMALL
block|,
name|CM_KERNEL
block|,
name|CM_MEDIUM
block|,
name|CM_LARGE
block|,
name|CM_SMALL_PIC
block|}
enum|;
end_enum

begin_comment
comment|/* Size of the RED_ZONE area.  */
end_comment

begin_define
define|#
directive|define
name|RED_ZONE_SIZE
value|128
end_define

begin_comment
comment|/* Reserved area of the red zone for temporaries.  */
end_comment

begin_define
define|#
directive|define
name|RED_ZONE_RESERVE
value|8
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_debug_arg_string
decl_stmt|,
modifier|*
name|ix86_debug_addr_string
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|asm_dialect
block|{
name|ASM_ATT
block|,
name|ASM_INTEL
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_asm_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|asm_dialect
name|ix86_asm_dialect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Value of -mcmodel specified by user.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_cmodel_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|cmodel
name|ix86_cmodel
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Variables in i386.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_cpu_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for -mcpu=<xxx> */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_arch_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for -march=<xxx> */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_fpmath_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for -mfpmath=<xxx> */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_regparm_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # registers to use to pass args */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_align_loops_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for loops */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_align_jumps_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for non-loop jumps */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_align_funcs_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for functions */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_preferred_stack_boundary_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for stack boundary */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ix86_branch_cost_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values 1-5: see jump.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ix86_regparm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ix86_regparm_string as a number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ix86_preferred_stack_boundary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preferred stack boundary alignment in bits */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ix86_branch_cost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values 1-5: see jump.c */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
specifier|const
name|regclass_map
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* smalled class containing REGNO */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|ix86_compare_op0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operand 0 for comparisons */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|ix86_compare_op1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operand 1 for comparisons */
end_comment

begin_escape
end_escape

begin_comment
comment|/* To properly truncate FP values into integers, we need to set i387 control    word.  We can't emit proper mode switching code before reload, as spills    generated by reload may truncate values incorrectly, but we still can avoid    redundant computation of new control word by the mode switching pass.    The fldcw instructions are still emitted redundantly, but this is probably    not going to be noticeable problem, as most CPUs do have fast path for    the sequence.       The machinery is to emit simple truncation instructions and split them    before reload to instructions having USEs of two memory locations that    are filled by this code to old and new control word.      Post-reload pass may be later used to eliminate the redundant fildcw if    needed.  */
end_comment

begin_enum
enum|enum
name|fp_cw_mode
block|{
name|FP_CW_STORED
block|,
name|FP_CW_UNINITIALIZED
block|,
name|FP_CW_ANY
block|}
enum|;
end_enum

begin_comment
comment|/* Define this macro if the port needs extra instructions inserted    for mode switching in an optimizing compilation.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZE_MODE_SWITCHING
parameter_list|(
name|ENTITY
parameter_list|)
value|1
end_define

begin_comment
comment|/* If you define `OPTIMIZE_MODE_SWITCHING', you have to define this as    initializer for an array of integers.  Each initializer element N    refers to an entity that needs mode switching, and specifies the    number of different modes that might need to be set for this    entity.  The position of the initializer in the initializer -    starting counting at zero - determines the integer that is used to    refer to the mode-switched entity in question.  */
end_comment

begin_define
define|#
directive|define
name|NUM_MODES_FOR_MODE_SWITCHING
value|{ FP_CW_ANY }
end_define

begin_comment
comment|/* ENTITY is an integer specifying a mode-switched entity.  If    `OPTIMIZE_MODE_SWITCHING' is defined, you must define this macro to    return an integer value not larger than the corresponding element    in `NUM_MODES_FOR_MODE_SWITCHING', to denote the mode that ENTITY    must be switched into prior to the execution of INSN.  */
end_comment

begin_define
define|#
directive|define
name|MODE_NEEDED
parameter_list|(
name|ENTITY
parameter_list|,
name|I
parameter_list|)
define|\
value|(GET_CODE (I) == CALL_INSN						\    || (GET_CODE (I) == INSN&& (asm_noperands (PATTERN (I))>= 0 	\ 				|| GET_CODE (PATTERN (I)) == ASM_INPUT))\    ? FP_CW_UNINITIALIZED						\    : recog_memoized (I)< 0 || get_attr_type (I) != TYPE_FISTP		\    ? FP_CW_ANY								\    : FP_CW_STORED)
end_define

begin_comment
comment|/* This macro specifies the order in which modes for ENTITY are    processed.  0 is the highest priority.  */
end_comment

begin_define
define|#
directive|define
name|MODE_PRIORITY_TO_MODE
parameter_list|(
name|ENTITY
parameter_list|,
name|N
parameter_list|)
value|(N)
end_define

begin_comment
comment|/* Generate one or more insns to set ENTITY to MODE.  HARD_REG_LIVE    is the set of hard registers live at the point where the insn(s)    are to be inserted.  */
end_comment

begin_define
define|#
directive|define
name|EMIT_MODE_SET
parameter_list|(
name|ENTITY
parameter_list|,
name|MODE
parameter_list|,
name|HARD_REGS_LIVE
parameter_list|)
define|\
value|((MODE) == FP_CW_STORED						\    ? emit_i387_cw_initialization (assign_386_stack_local (HImode, 1),	\ 				  assign_386_stack_local (HImode, 2)), 0\    : 0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Avoid renaming of stack registers, as doing so in combination with    scheduling just increases amount of live registers at time and in    the turn amount of fxch instructions needed.     ??? Maybe Pentium chips benefits from renaming, someone can try...  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_RENAME_OK
parameter_list|(
name|SRC
parameter_list|,
name|TARGET
parameter_list|)
define|\
value|((SRC)< FIRST_STACK_REG || (SRC)> LAST_STACK_REG)
end_define

begin_escape
end_escape

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

