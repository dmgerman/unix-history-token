begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC for IA-32.    Copyright (C) 1988, 1992, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* The purpose of this file is to define the characteristics of the i386,    independent of assembler syntax or operating system.     Three other files build on this one to describe a specific assembler syntax:    bsd386.h, att386.h, and sun386.h.     The actual tm.h file for a particular system should include    this file, and then the file for the appropriate assembler syntax.     Many macros that specify assembler syntax are omitted entirely from    this file because they really belong in the files for particular    assemblers.  These include RP, IP, LPREFIX, PUT_OP_SIZE, USE_STAR,    ADDR_BEG, ADDR_END, PRINT_IREG, PRINT_SCALE, PRINT_B_I_S, and many    that start with ASM_ or end in ASM_OP.  */
end_comment

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
index|[
literal|5
index|]
decl_stmt|;
comment|/* cost of starting a multiply 				   in QImode, HImode, SImode, DImode, TImode*/
specifier|const
name|int
name|mult_bit
decl_stmt|;
comment|/* cost of multiply per each bit set */
specifier|const
name|int
name|divide
index|[
literal|5
index|]
decl_stmt|;
comment|/* cost of a divide/mod 				   in QImode, HImode, SImode, DImode, TImode*/
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
specifier|const
name|int
name|branch_cost
decl_stmt|;
comment|/* Default value for BRANCH_COST.  */
specifier|const
name|int
name|fadd
decl_stmt|;
comment|/* cost of FADD and FSUB instructions.  */
specifier|const
name|int
name|fmul
decl_stmt|;
comment|/* cost of FMUL instruction.  */
specifier|const
name|int
name|fdiv
decl_stmt|;
comment|/* cost of FDIV instruction.  */
specifier|const
name|int
name|fabs
decl_stmt|;
comment|/* cost of FABS instruction.  */
specifier|const
name|int
name|fchs
decl_stmt|;
comment|/* cost of FCHS instruction.  */
specifier|const
name|int
name|fsqrt
decl_stmt|;
comment|/* cost of FSQRT instruction.  */
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
value|TARGET_CPU_DEFAULT_generic
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FPMATH_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FPMATH_DEFAULT
define|\
value|(TARGET_64BIT&& TARGET_SSE ? FPMATH_SSE : FPMATH_387)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_FLOAT_RETURNS_IN_80387
value|TARGET_FLOAT_RETURNS
end_define

begin_comment
comment|/* 64bit Sledgehammer mode.  For libgcc2 we make sure this is a    compile-time constant.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
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

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BI_ARCH
end_ifndef

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_if
if|#
directive|if
name|TARGET_64BIT_DEFAULT
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAS_LONG_COND_BRANCH
value|1
end_define

begin_define
define|#
directive|define
name|HAS_LONG_UNCOND_BRANCH
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_386
value|(ix86_tune == PROCESSOR_I386)
end_define

begin_define
define|#
directive|define
name|TARGET_486
value|(ix86_tune == PROCESSOR_I486)
end_define

begin_define
define|#
directive|define
name|TARGET_PENTIUM
value|(ix86_tune == PROCESSOR_PENTIUM)
end_define

begin_define
define|#
directive|define
name|TARGET_PENTIUMPRO
value|(ix86_tune == PROCESSOR_PENTIUMPRO)
end_define

begin_define
define|#
directive|define
name|TARGET_GEODE
value|(ix86_tune == PROCESSOR_GEODE)
end_define

begin_define
define|#
directive|define
name|TARGET_K6
value|(ix86_tune == PROCESSOR_K6)
end_define

begin_define
define|#
directive|define
name|TARGET_ATHLON
value|(ix86_tune == PROCESSOR_ATHLON)
end_define

begin_define
define|#
directive|define
name|TARGET_PENTIUM4
value|(ix86_tune == PROCESSOR_PENTIUM4)
end_define

begin_define
define|#
directive|define
name|TARGET_K8
value|(ix86_tune == PROCESSOR_K8)
end_define

begin_define
define|#
directive|define
name|TARGET_ATHLON_K8
value|(TARGET_K8 || TARGET_ATHLON)
end_define

begin_define
define|#
directive|define
name|TARGET_NOCONA
value|(ix86_tune == PROCESSOR_NOCONA)
end_define

begin_define
define|#
directive|define
name|TARGET_CORE2
value|(ix86_tune == PROCESSOR_CORE2)
end_define

begin_define
define|#
directive|define
name|TARGET_GENERIC32
value|(ix86_tune == PROCESSOR_GENERIC32)
end_define

begin_define
define|#
directive|define
name|TARGET_GENERIC64
value|(ix86_tune == PROCESSOR_GENERIC64)
end_define

begin_define
define|#
directive|define
name|TARGET_GENERIC
value|(TARGET_GENERIC32 || TARGET_GENERIC64)
end_define

begin_define
define|#
directive|define
name|TARGET_AMDFAM10
value|(ix86_tune == PROCESSOR_AMDFAM10)
end_define

begin_define
define|#
directive|define
name|TUNEMASK
value|(1<< ix86_tune)
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
name|x86_use_himode_fiop
decl_stmt|,
name|x86_use_simode_fiop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_mov0
decl_stmt|,
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
decl_stmt|,
name|x86_fast_prefix
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
specifier|const
name|int
name|x86_arch_always_fancy_math_387
decl_stmt|,
name|x86_shift1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_sse_partial_reg_dependency
decl_stmt|,
name|x86_sse_split_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_sse_unaligned_move_optimal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_sse_typeless_stores
decl_stmt|,
name|x86_sse_load0_by_pxor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_ffreep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_inter_unit_moves
decl_stmt|,
name|x86_schedule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_bt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_cmpxchg
decl_stmt|,
name|x86_cmpxchg8b
decl_stmt|,
name|x86_xadd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_use_incdec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_pad_returns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_partial_flag_reg_stall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x86_prefetch_sse
decl_stmt|,
name|x86_cmpxchg16b
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_USE_LEAVE
value|(x86_use_leave& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PUSH_MEMORY
value|(x86_push_memory& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_ZERO_EXTEND_WITH_AND
value|(x86_zero_extend_with_and& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_BIT_TEST
value|(x86_use_bit_test& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_UNROLL_STRLEN
value|(x86_unroll_strlen& TUNEMASK)
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
name|TARGET_FISTTP
value|(TARGET_SSE3&& TARGET_80387)
end_define

begin_define
define|#
directive|define
name|TARGET_DEEP_BRANCH_PREDICTION
value|(x86_deep_branch& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_BRANCH_PREDICTION_HINTS
value|(x86_branch_hints& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_DOUBLE_WITH_ADD
value|(x86_double_with_add& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_SAHF
value|((x86_use_sahf& TUNEMASK)&& !TARGET_64BIT)
end_define

begin_define
define|#
directive|define
name|TARGET_MOVX
value|(x86_movx& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PARTIAL_REG_STALL
value|(x86_partial_reg_stall& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PARTIAL_FLAG_REG_STALL
value|(x86_partial_flag_reg_stall& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_HIMODE_FIOP
value|(x86_use_himode_fiop& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_SIMODE_FIOP
value|(x86_use_simode_fiop& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_MOV0
value|(x86_use_mov0& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_CLTD
value|(x86_use_cltd& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SPLIT_LONG_MOVES
value|(x86_split_long_moves& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_READ_MODIFY_WRITE
value|(x86_read_modify_write& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_READ_MODIFY
value|(x86_read_modify& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_QImode
value|(x86_promote_QImode& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_FAST_PREFIX
value|(x86_fast_prefix& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SINGLE_STRINGOP
value|(x86_single_stringop& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_QIMODE_MATH
value|(x86_qimode_math& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_HIMODE_MATH
value|(x86_himode_math& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_QI_REGS
value|(x86_promote_qi_regs& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROMOTE_HI_REGS
value|(x86_promote_hi_regs& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_ADD_ESP_4
value|(x86_add_esp_4& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_ADD_ESP_8
value|(x86_add_esp_8& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SUB_ESP_4
value|(x86_sub_esp_4& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SUB_ESP_8
value|(x86_sub_esp_8& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_INTEGER_DFMODE_MOVES
value|(x86_integer_DFmode_moves& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PARTIAL_REG_DEPENDENCY
value|(x86_partial_reg_dependency& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE_PARTIAL_REG_DEPENDENCY
define|\
value|(x86_sse_partial_reg_dependency& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE_UNALIGNED_MOVE_OPTIMAL
define|\
value|(x86_sse_unaligned_move_optimal& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE_SPLIT_REGS
value|(x86_sse_split_regs& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE_TYPELESS_STORES
value|(x86_sse_typeless_stores& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SSE_LOAD0_BY_PXOR
value|(x86_sse_load0_by_pxor& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_MEMORY_MISMATCH_STALL
value|(x86_memory_mismatch_stall& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PROLOGUE_USING_MOVE
value|(x86_prologue_using_move& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_EPILOGUE_USING_MOVE
value|(x86_epilogue_using_move& TUNEMASK)
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
name|TARGET_SHIFT1
value|(x86_shift1& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_FFREEP
value|(x86_use_ffreep& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_REP_MOVL_OPTIMAL
value|(x86_rep_movl_optimal& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_INTER_UNIT_MOVES
value|(x86_inter_unit_moves& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_FOUR_JUMP_LIMIT
value|(x86_four_jump_limit& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_SCHEDULE
value|(x86_schedule& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_BT
value|(x86_use_bt& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_INCDEC
value|(x86_use_incdec& TUNEMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_PAD_RETURNS
value|(x86_pad_returns& TUNEMASK)
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
name|TARGET_GNU_TLS
value|(ix86_tls_dialect == TLS_DIALECT_GNU)
end_define

begin_define
define|#
directive|define
name|TARGET_GNU2_TLS
value|(ix86_tls_dialect == TLS_DIALECT_GNU2)
end_define

begin_define
define|#
directive|define
name|TARGET_ANY_GNU_TLS
value|(TARGET_GNU_TLS || TARGET_GNU2_TLS)
end_define

begin_define
define|#
directive|define
name|TARGET_SUN_TLS
value|(ix86_tls_dialect == TLS_DIALECT_SUN)
end_define

begin_define
define|#
directive|define
name|TARGET_CMPXCHG
value|(x86_cmpxchg& (1<< ix86_arch))
end_define

begin_define
define|#
directive|define
name|TARGET_CMPXCHG8B
value|(x86_cmpxchg8b& (1<< ix86_arch))
end_define

begin_define
define|#
directive|define
name|TARGET_CMPXCHG16B
value|(x86_cmpxchg16b)
end_define

begin_define
define|#
directive|define
name|TARGET_XADD
value|(x86_xadd& (1<< ix86_arch))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_64BIT_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_64BIT_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Once GDB has been enhanced to deal with functions without frame    pointers, we can change this to allow for elimination of    the frame pointer in leaf functions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_comment
comment|/* This is not really a target flag, but is done this way so that    it's analogous to similar code for Mach-O on PowerPC.  darwin.h    redefines this to 1.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MACHO
value|0
end_define

begin_comment
comment|/* Subtargets may reset this to 1 in order to enable 96-bit long double    with the rounding mode forced to 53 bits.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_96_ROUND_53_LONG_DOUBLE
value|0
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
comment|/* -march=native handling only makes sense with compiler running on    an x86 or x86_64 chip.  If changing this condition, also change    the condition in driver-i386.c.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_comment
comment|/* In driver-i386.c.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|host_detect_local_cpu
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|EXTRA_SPEC_FUNCTIONS
define|\
value|{ "local_cpu_detect", host_detect_local_cpu },
end_define

begin_define
define|#
directive|define
name|HAVE_LOCAL_CPU_DETECT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support for configure-time defaults of some command line options.    The order here is important so that -march doesn't squash the    tune or cpu values.  */
end_comment

begin_define
define|#
directive|define
name|OPTION_DEFAULT_SPECS
define|\
value|{"tune", "%{!mtune=*:%{!mcpu=*:%{!march=*:-mtune=%(VALUE)}}}" }, \   {"cpu", "%{!mtune=*:%{!mcpu=*:%{!march=*:-mtune=%(VALUE)}}}" }, \   {"arch", "%{!march=*:-march=%(VALUE)}"}
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
name|CC1_CPU_SPEC_1
value|"\ %{!mtune*: \ %{m386:mtune=i386 \ %n`-m386' is deprecated. Use `-march=i386' or `-mtune=i386' instead.\n} \ %{m486:-mtune=i486 \ %n`-m486' is deprecated. Use `-march=i486' or `-mtune=i486' instead.\n} \ %{mpentium:-mtune=pentium \ %n`-mpentium' is deprecated. Use `-march=pentium' or `-mtune=pentium' instead.\n} \ %{mpentiumpro:-mtune=pentiumpro \ %n`-mpentiumpro' is deprecated. Use `-march=pentiumpro' or `-mtune=pentiumpro' instead.\n} \ %{mcpu=*:-mtune=%* \ %n`-mcpu=' is deprecated. Use `-mtune=' or '-march=' inst<mcpu=* \ %{mintel-syntax:-masm=intel \ %n`-mintel-syntax' is deprecated. Use `-masm=intel' instead.\n} \ %{mno-intel-syntax:-masm=att \ %n`-mno-intel-syntax' is deprecated. Use `-masm=att' instead.\n}"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LOCAL_CPU_DETECT
end_ifndef

begin_define
define|#
directive|define
name|CC1_CPU_SPEC
value|CC1_CPU_SPEC_1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CC1_CPU_SPEC
value|CC1_CPU_SPEC_1 \ "%{march=native:%<march=native %:local_cpu_detect(arch) \   %{!mtune=*:%<mtune=native %:local_cpu_detect(tune)}} \ %{mtune=native:%<mtune=native %:local_cpu_detect(tune)}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Target CPU builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\       size_t arch_len = strlen (ix86_arch_string);		\       size_t tune_len = strlen (ix86_tune_string);		\       int last_arch_char = ix86_arch_string[arch_len - 1];	\       int last_tune_char = ix86_tune_string[tune_len - 1];		\ 								\       if (TARGET_64BIT)						\ 	{							\ 	  builtin_assert ("cpu=x86_64");			\ 	  builtin_assert ("machine=x86_64");			\ 	  builtin_define ("__amd64");				\ 	  builtin_define ("__amd64__");				\ 	  builtin_define ("__x86_64");				\ 	  builtin_define ("__x86_64__");			\ 	}							\       else							\ 	{							\ 	  builtin_assert ("cpu=i386");				\ 	  builtin_assert ("machine=i386");			\ 	  builtin_define_std ("i386");				\ 	}							\ 								\
comment|/* Built-ins based on -mtune= (or -march= if no		\ 	 -mtune= given).  */
value|\       if (TARGET_386)						\ 	builtin_define ("__tune_i386__");			\       else if (TARGET_486)					\ 	builtin_define ("__tune_i486__");			\       else if (TARGET_PENTIUM)					\ 	{							\ 	  builtin_define ("__tune_i586__");			\ 	  builtin_define ("__tune_pentium__");			\ 	  if (last_tune_char == 'x')				\ 	    builtin_define ("__tune_pentium_mmx__");		\ 	}							\       else if (TARGET_PENTIUMPRO)				\ 	{							\ 	  builtin_define ("__tune_i686__");			\ 	  builtin_define ("__tune_pentiumpro__");		\ 	  switch (last_tune_char)				\ 	    {							\ 	    case '3':						\ 	      builtin_define ("__tune_pentium3__");		\
comment|/* FALLTHRU */
value|\ 	    case '2':						\ 	      builtin_define ("__tune_pentium2__");		\ 	      break;						\ 	    }							\ 	}							\       else if (TARGET_GEODE)					\ 	{							\ 	  builtin_define ("__tune_geode__");			\ 	}							\       else if (TARGET_K6)					\ 	{							\ 	  builtin_define ("__tune_k6__");			\ 	  if (last_tune_char == '2')				\ 	    builtin_define ("__tune_k6_2__");			\ 	  else if (last_tune_char == '3')			\ 	    builtin_define ("__tune_k6_3__");			\ 	}							\       else if (TARGET_ATHLON)					\ 	{							\ 	  builtin_define ("__tune_athlon__");			\
comment|/* Plain "athlon"& "athlon-tbird" lacks SSE.  */
value|\ 	  if (last_tune_char != 'n'&& last_tune_char != 'd')	\ 	    builtin_define ("__tune_athlon_sse__");		\ 	}							\       else if (TARGET_K8)					\ 	builtin_define ("__tune_k8__");				\       else if (TARGET_AMDFAM10)					\ 	builtin_define ("__tune_amdfam10__");			\       else if (TARGET_PENTIUM4)					\ 	builtin_define ("__tune_pentium4__");			\       else if (TARGET_NOCONA)					\ 	builtin_define ("__tune_nocona__");			\       else if (TARGET_CORE2)					\ 	builtin_define ("__tune_core2__");			\ 								\       if (TARGET_MMX)						\ 	builtin_define ("__MMX__");				\       if (TARGET_3DNOW)						\ 	builtin_define ("__3dNOW__");				\       if (TARGET_3DNOW_A)					\ 	builtin_define ("__3dNOW_A__");				\       if (TARGET_SSE)						\ 	builtin_define ("__SSE__");				\       if (TARGET_SSE2)						\ 	builtin_define ("__SSE2__");				\       if (TARGET_SSE3)						\ 	builtin_define ("__SSE3__");				\       if (TARGET_SSSE3)						\ 	builtin_define ("__SSSE3__");				\       if (TARGET_SSE4A)					\  	builtin_define ("__SSE4A__");		                \       if (TARGET_SSE_MATH&& TARGET_SSE)			\ 	builtin_define ("__SSE_MATH__");			\       if (TARGET_SSE_MATH&& TARGET_SSE2)			\ 	builtin_define ("__SSE2_MATH__");			\ 								\
comment|/* Built-ins based on -march=.  */
value|\       if (ix86_arch == PROCESSOR_I486)				\ 	{							\ 	  builtin_define ("__i486");				\ 	  builtin_define ("__i486__");				\ 	}							\       else if (ix86_arch == PROCESSOR_PENTIUM)			\ 	{							\ 	  builtin_define ("__i586");				\ 	  builtin_define ("__i586__");				\ 	  builtin_define ("__pentium");				\ 	  builtin_define ("__pentium__");			\ 	  if (last_arch_char == 'x')				\ 	    builtin_define ("__pentium_mmx__");			\ 	}							\       else if (ix86_arch == PROCESSOR_PENTIUMPRO)		\ 	{							\ 	  builtin_define ("__i686");				\ 	  builtin_define ("__i686__");				\ 	  builtin_define ("__pentiumpro");			\ 	  builtin_define ("__pentiumpro__");			\ 	}							\       else if (ix86_arch == PROCESSOR_GEODE)			\ 	{							\ 	  builtin_define ("__geode");				\ 	  builtin_define ("__geode__");				\ 	}							\       else if (ix86_arch == PROCESSOR_K6)			\ 	{							\ 								\ 	  builtin_define ("__k6");				\ 	  builtin_define ("__k6__");				\ 	  if (last_arch_char == '2')				\ 	    builtin_define ("__k6_2__");			\ 	  else if (last_arch_char == '3')			\ 	    builtin_define ("__k6_3__");			\ 	}							\       else if (ix86_arch == PROCESSOR_ATHLON)			\ 	{							\ 	  builtin_define ("__athlon");				\ 	  builtin_define ("__athlon__");			\
comment|/* Plain "athlon"& "athlon-tbird" lacks SSE.  */
value|\ 	  if (last_tune_char != 'n'&& last_tune_char != 'd')	\ 	    builtin_define ("__athlon_sse__");			\ 	}							\       else if (ix86_arch == PROCESSOR_K8)			\ 	{							\ 	  builtin_define ("__k8");				\ 	  builtin_define ("__k8__");				\ 	}							\       else if (ix86_arch == PROCESSOR_AMDFAM10)			\ 	{							\ 	  builtin_define ("__amdfam10");			\ 	  builtin_define ("__amdfam10__");			\ 	}							\       else if (ix86_arch == PROCESSOR_PENTIUM4)			\ 	{							\ 	  builtin_define ("__pentium4");			\ 	  builtin_define ("__pentium4__");			\ 	}							\       else if (ix86_arch == PROCESSOR_NOCONA)			\ 	{							\ 	  builtin_define ("__nocona");				\ 	  builtin_define ("__nocona__");			\ 	}							\       else if (ix86_arch == PROCESSOR_CORE2)			\ 	{							\ 	  builtin_define ("__core2");				\ 	  builtin_define ("__core2__");				\ 	}							\     }								\   while (0)
end_define

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
name|TARGET_CPU_DEFAULT_geode
value|8
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_k6
value|9
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_k6_2
value|10
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_k6_3
value|11
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_athlon
value|12
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_athlon_sse
value|13
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_k8
value|14
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_pentium_m
value|15
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_prescott
value|16
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_nocona
value|17
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_core2
value|18
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_generic
value|19
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_amdfam10
value|20
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT_NAMES
value|{"i386", "i486", "pentium", "pentium-mmx",\ 				  "pentiumpro", "pentium2", "pentium3", \                                   "pentium4", "geode", "k6", "k6-2", "k6-3", \ 				  "athlon", "athlon-4", "k8", \ 				  "pentium-m", "prescott", "nocona", \ 				  "core2", "generic", "amdfam10"}
end_define

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
comment|/* This macro defines names of additional specifications to put in the    specs that can be used in various specifications like CC1_SPEC.  Its    definition is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GCC driver    program.     Do not define this macro if it does not need to do anything.  */
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
value|{ "cc1_cpu",  CC1_CPU_SPEC },						\   SUBTARGET_EXTRA_SPECS
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|80
end_define

begin_comment
comment|/* Set the value of FLT_EVAL_METHOD in float.h.  When using only the    FPU, assume that the fpcw is set to extended precision; when using    only SSE, rounding is correct; when using both SSE and the FPU,    the rounding precision is indeterminate, since either may be chosen    apparently at random.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLT_EVAL_METHOD
define|\
value|(TARGET_MIX_SSE_I387 ? -1 : TARGET_SSE_MATH ? 0 : 2)
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

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|TARGET_64BIT_DEFAULT
end_if

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_define
define|#
directive|define
name|MIN_UNITS_PER_WORD
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MIN_UNITS_PER_WORD
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Boundary (in *bits*) on which the stack pointer prefers to be    aligned; the compiler cannot rely on having this alignment.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_STACK_BOUNDARY
value|ix86_preferred_stack_boundary
end_define

begin_comment
comment|/* As of July 2001, many runtimes do not align the stack properly when    entering main.  This causes expand_main_function to forcibly align    the stack, which results in aligned frames for functions called from    main, though it does nothing for the alignment of main itself.  */
end_comment

begin_define
define|#
directive|define
name|FORCE_PREFERRED_STACK_BOUNDARY_IN_MAIN
define|\
value|(ix86_preferred_stack_boundary> STACK_BOUNDARY&& !TARGET_64BIT)
end_define

begin_comment
comment|/* Minimum allocation boundary for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|8
end_define

begin_comment
comment|/* C++ stores the virtual bit in the lowest bit of function pointers.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PTRMEMFUNC_VBIT_LOCATION
value|ptrmemfunc_vbit_in_pfn
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
comment|/* Minimum size in bits of the largest boundary to which any    and all fundamental data types supported by the hardware    might need to be aligned. No data type wants to be aligned    rounder than this.     Pentium+ prefers DFmode values to be aligned to 64 bit boundary    and Pentium Pro XFmode values at 128 bit boundaries.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|128
end_define

begin_comment
comment|/* Decide whether a variable of mode MODE should be 128 bit aligned.  */
end_comment

begin_define
define|#
directive|define
name|ALIGN_MODE_128
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == XFmode || SSE_REG_MODE_P (MODE))
end_define

begin_comment
comment|/* The published ABIs say that doubles should be aligned on word    boundaries, so lower the alignment for structure fields unless    -malign-double is set.  */
end_comment

begin_comment
comment|/* ??? Blah -- this macro is used directly by libobjc.  Since it    supports no vector modes, cut out the complexity and fall back    on BIGGEST_FIELD_ALIGNMENT.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_TARGET_LIBS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|128
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ADJUST_FIELD_ALIGN
parameter_list|(
name|FIELD
parameter_list|,
name|COMPUTED
parameter_list|)
define|\
value|x86_field_alignment (FIELD, COMPUTED)
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
comment|/* Set this nonzero if move instructions will actually fail to work    when given unaligned data.  */
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
comment|/* Required on the 386 since it doesn't have bit-field insns.  */
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
value|(((MODE) == SFmode&& (!TARGET_SSE || !TARGET_SSE_MATH))	\    || ((MODE) == DFmode&& (!TARGET_SSE2 || !TARGET_SSE_MATH))  \    || (MODE) == XFmode)
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
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the 80386, the stack pointer is such, as is the arg pointer.     The value is zero if the register is not fixed on either 32 or    64 bit targets, one if the register if fixed on both 32 and 64    bit targets, two if it is only fixed on 32bit targets and three    if its only fixed on 64bit targets.    Proper values are computed in the CONDITIONAL_REGISTER_USAGE.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7*/
define|\
value|{  0, 0, 0, 0, 0, 0, 0, 1, 0,  0,  0,  0,  0,  0,  0,  0,	\
comment|/*arg,flags,fpsr,dir,frame*/
value|\     1,    1,   1,  1,    1,					\
comment|/*xmm0,xmm1,xmm2,xmm3,xmm4,xmm5,xmm6,xmm7*/
value|\      0,   0,   0,   0,   0,   0,   0,   0,			\
comment|/*mmx0,mmx1,mmx2,mmx3,mmx4,mmx5,mmx6,mmx7*/
value|\      0,   0,   0,   0,   0,   0,   0,   0,			\
comment|/*  r8,  r9, r10, r11, r12, r13, r14, r15*/
value|\      2,   2,   2,   2,   2,   2,   2,   2,			\
comment|/*xmm8,xmm9,xmm10,xmm11,xmm12,xmm13,xmm14,xmm15*/
value|\      2,   2,    2,    2,    2,    2,    2,    2}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.     The value is zero if the register is not call used on either 32 or    64 bit targets, one if the register if call used on both 32 and 64    bit targets, two if it is only call used on 32bit targets and three    if its only call used on 64bit targets.    Proper values are computed in the CONDITIONAL_REGISTER_USAGE. */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7*/
define|\
value|{  1, 1, 1, 0, 3, 3, 0, 1, 1,  1,  1,  1,  1,  1,  1,  1,	\
comment|/*arg,flags,fpsr,dir,frame*/
value|\      1,   1,   1,  1,    1,					\
comment|/*xmm0,xmm1,xmm2,xmm3,xmm4,xmm5,xmm6,xmm7*/
value|\      1,   1,   1,   1,   1,  1,    1,   1,			\
comment|/*mmx0,mmx1,mmx2,mmx3,mmx4,mmx5,mmx6,mmx7*/
value|\      1,   1,   1,   1,   1,   1,   1,   1,			\
comment|/*  r8,  r9, r10, r11, r12, r13, r14, r15*/
value|\      1,   1,   1,   1,   2,   2,   2,   2,			\
comment|/*xmm8,xmm9,xmm10,xmm11,xmm12,xmm13,xmm14,xmm15*/
value|\      1,   1,    1,    1,    1,    1,    1,    1}
end_define

begin_comment
unit|\
comment|/* Order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.  List frame pointer    late and fixed registers last.  Note that, in general, we prefer    registers listed in CALL_USED_REGISTERS, keeping the others    available for storage of persistent values.     The ORDER_REGS_FOR_LOCAL_ALLOC actually overwrite the order,    so this is just empty initializer for array.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,\    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,	\    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,  \    48, 49, 50, 51, 52 }
end_define

begin_comment
comment|/* ORDER_REGS_FOR_LOCAL_ALLOC is a macro which permits reg_alloc_order    to be rearranged based on a particular function.  When using sse math,    we want to allocate SSE before x87 registers and vice vera.  */
end_comment

begin_define
define|#
directive|define
name|ORDER_REGS_FOR_LOCAL_ALLOC
value|x86_order_regs_for_local_alloc ()
end_define

begin_comment
comment|/* Macro to conditionally modify fixed_regs/call_used_regs.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|do {									\     int i;								\     for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)				\       {									\ 	if (fixed_regs[i]> 1)						\ 	  fixed_regs[i] = (fixed_regs[i] == (TARGET_64BIT ? 3 : 2));	\ 	if (call_used_regs[i]> 1)					\ 	  call_used_regs[i] = (call_used_regs[i]			\ 			       == (TARGET_64BIT ? 3 : 2));		\       }									\     if (PIC_OFFSET_TABLE_REGNUM != INVALID_REGNUM)			\       {									\ 	fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;			\ 	call_used_regs[PIC_OFFSET_TABLE_REGNUM] = 1;			\       }									\     if (! TARGET_MMX)							\       {									\ 	int i;								\         for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)			\           if (TEST_HARD_REG_BIT (reg_class_contents[(int)MMX_REGS], i))	\ 	    fixed_regs[i] = call_used_regs[i] = 1, reg_names[i] = "";	\       }									\     if (! TARGET_SSE)							\       {									\ 	int i;								\         for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)			\           if (TEST_HARD_REG_BIT (reg_class_contents[(int)SSE_REGS], i))	\ 	    fixed_regs[i] = call_used_regs[i] = 1, reg_names[i] = "";	\       }									\     if (! TARGET_80387&& ! TARGET_FLOAT_RETURNS_IN_80387)		\       {									\ 	int i;								\ 	HARD_REG_SET x;							\         COPY_HARD_REG_SET (x, reg_class_contents[(int)FLOAT_REGS]);	\         for (i = 0; i< FIRST_PSEUDO_REGISTER; i++)			\           if (TEST_HARD_REG_BIT (x, i)) 				\ 	    fixed_regs[i] = call_used_regs[i] = 1, reg_names[i] = "";	\       }									\     if (! TARGET_64BIT)							\       {									\ 	int i;								\ 	for (i = FIRST_REX_INT_REG; i<= LAST_REX_INT_REG; i++)		\ 	  reg_names[i] = "";						\ 	for (i = FIRST_REX_SSE_REG; i<= LAST_REX_SSE_REG; i++)		\ 	  reg_names[i] = "";						\       }									\   } while (0)
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     Actually there are no two word move instructions for consecutive    registers.  And only registers 0-3 may have mov byte instructions    applied to them.    */
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
value|(FP_REGNO_P (REGNO) || SSE_REGNO_P (REGNO) || MMX_REGNO_P (REGNO)	\    ? (COMPLEX_MODE_P (MODE) ? 2 : 1)					\    : ((MODE) == XFmode							\       ? (TARGET_64BIT ? 2 : 3)						\       : (MODE) == XCmode						\       ? (TARGET_64BIT ? 4 : 6)						\       : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)))
end_define

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS_HAS_PADDING
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((TARGET_128BIT_LONG_DOUBLE&& !TARGET_64BIT)				\    ? (FP_REGNO_P (REGNO) || SSE_REGNO_P (REGNO) || MMX_REGNO_P (REGNO)	\       ? 0								\       : ((MODE) == XFmode || (MODE) == XCmode))				\    : 0)
end_define

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS_WITH_PADDING
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
value|((MODE) == XFmode ? 4 : 8)
end_define

begin_define
define|#
directive|define
name|VALID_SSE2_REG_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == V16QImode || (MODE) == V8HImode || (MODE) == V2DFmode    \      || (MODE) == V2DImode || (MODE) == DFmode)
end_define

begin_define
define|#
directive|define
name|VALID_SSE_REG_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == TImode || (MODE) == V4SFmode || (MODE) == V4SImode	\      || (MODE) == SFmode || (MODE) == TFmode)
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

begin_comment
comment|/* ??? No autovectorization into MMX or 3DNOW until we can reliably    place emms and femms instructions.  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_SIMD_WORD
value|(TARGET_SSE ? 16 : UNITS_PER_WORD)
end_define

begin_define
define|#
directive|define
name|VALID_FP_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == SFmode || (MODE) == DFmode || (MODE) == XFmode		\      || (MODE) == SCmode || (MODE) == DCmode || (MODE) == XCmode)	\  #define VALID_INT_MODE_P(MODE)						\     ((MODE) == QImode || (MODE) == HImode || (MODE) == SImode		\      || (MODE) == DImode						\      || (MODE) == CQImode || (MODE) == CHImode || (MODE) == CSImode	\      || (MODE) == CDImode						\      || (TARGET_64BIT&& ((MODE) == TImode || (MODE) == CTImode		\          || (MODE) == TFmode || (MODE) == TCmode)))
end_define

begin_comment
comment|/* Return true for modes passed in SSE registers.  */
end_comment

begin_define
define|#
directive|define
name|SSE_REG_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == TImode || (MODE) == V16QImode || (MODE) == TFmode		\    || (MODE) == V8HImode || (MODE) == V2DFmode || (MODE) == V2DImode	\    || (MODE) == V4SFmode || (MODE) == V4SImode)
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
value|ix86_modes_tieable_p (MODE1, MODE2)
end_define

begin_comment
comment|/* It is possible to write patterns to move flags; but until someone    does it,  */
end_comment

begin_define
define|#
directive|define
name|AVOID_CCMODE_COPIES
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
value|(CC_REGNO_P (REGNO) ? VOIDmode					\    : (MODE) == VOIDmode&& (NREGS) != 1 ? VOIDmode			\    : (MODE) == VOIDmode ? choose_hard_reg_mode ((REGNO), (NREGS), false)\    : (MODE) == HImode&& !TARGET_PARTIAL_REG_STALL ? SImode		\    : (MODE) == QImode&& (REGNO)>= 4&& !TARGET_64BIT ? SImode 	\    : (MODE))
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
comment|/* Override this in other tm.h files to cope with various OS lossage    requiring a frame pointer.  */
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
comment|/* Register to hold the addressing base for position independent    code access to data items.  We don't use PIC pointer for 64bit    mode.  Define the regnum to dummy value to prevent gcc from    pessimizing code dealing with EBX.     To avoid clobbering a call-saved register unnecessarily, we renumber    the pic register when possible.  The change is visible after the    prologue has been emitted.  */
end_comment

begin_define
define|#
directive|define
name|REAL_PIC_OFFSET_TABLE_REGNUM
value|3
end_define

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
define|\
value|((TARGET_64BIT&& ix86_cmodel == CM_SMALL_PIC)	\    || !flag_pic ? INVALID_REGNUM			\    : reload_completed ? REGNO (pic_offset_table_rtx)	\    : REAL_PIC_OFFSET_TABLE_REGNUM)
end_define

begin_define
define|#
directive|define
name|GOT_SYMBOL_NAME
value|"_GLOBAL_OFFSET_TABLE_"
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

begin_comment
comment|/* This is overridden by<cygwin.h>.  */
end_comment

begin_define
define|#
directive|define
name|MS_AGGREGATE_RETURN
value|0
end_define

begin_comment
comment|/* This is overridden by<netware.h>.  */
end_comment

begin_define
define|#
directive|define
name|KEEP_AGGREGATE_RETURN_POINTER
value|0
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
value|((CLASS) == SSE_REGS)
end_define

begin_define
define|#
directive|define
name|MMX_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|((CLASS) == MMX_REGS)
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
comment|/* Give names of register classes as strings for dump file.  */
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
name|REX_SSE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)>= FIRST_REX_SSE_REG&& (N)<= LAST_REX_SSE_REG)
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
value|((TARGET_SSE&& (MODE) == SFmode) || (TARGET_SSE2&& (MODE) == DFmode))
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
comment|/* Discourage putting floating-point values in SSE registers unless    SSE math is being used, and likewise for the 387 registers.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_OUTPUT_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|ix86_preferred_output_reload_class ((X), (CLASS))
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
comment|/* QImode spills from non-QI registers need a scratch.  This does not    happen often -- the only example so far requires an uninitialized    pseudo.  */
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
comment|/* On the 80386, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.  */
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
value|(!MAYBE_INTEGER_CLASS_P (CLASS)					\   ? (COMPLEX_MODE_P (MODE) ? 2 : 1)					\   : (((((MODE) == XFmode ? 12 : GET_MODE_SIZE (MODE)))			\       + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
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
value|(((CLASS) == AREG)							\    || ((CLASS) == DREG)							\    || ((CLASS) == CREG)							\    || ((CLASS) == BREG)							\    || ((CLASS) == AD_REGS)						\    || ((CLASS) == SIREG)						\    || ((CLASS) == DIREG)						\    || ((CLASS) == FP_TOP_REG)						\    || ((CLASS) == FP_SECOND_REG))
end_define

begin_comment
comment|/* Return a class of registers that cannot change FROM mode to TO mode.  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_CHANGE_MODE_CLASS
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|ix86_cannot_change_mode_class (FROM, TO, CLASS)
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
comment|/* Define this to nonzero if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
value|1
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
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On 386, we have pushw instruction that decrements by exactly 2 no    matter what the position was, there is no pushb.    But as CIE data alignment factor on this arch is -4, we need to make    sure all stack pointer adjustments are in multiple of 4.     For 64bit ABI we round up to 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|BYTES
parameter_list|)
define|\
value|(TARGET_64BIT		     \    ? (((BYTES) + 7)& (-8))  \    : (((BYTES) + 3)& (-4)))
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
comment|/* We want the stack and args grow in opposite directions, even if    PUSH_ARGS is 0.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ARGS_REVERSED
value|1
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
name|fastcall
decl_stmt|;
comment|/* fastcall calling convention is used */
name|int
name|sse_words
decl_stmt|;
comment|/* # sse words passed so far */
name|int
name|sse_nregs
decl_stmt|;
comment|/* # sse registers available for passing */
name|int
name|warn_sse
decl_stmt|;
comment|/* True when we want to warn about SSE ABI.  */
name|int
name|warn_mmx
decl_stmt|;
comment|/* True when we want to warn about MMX ABI.  */
name|int
name|sse_regno
decl_stmt|;
comment|/* next available sse register number */
name|int
name|mmx_words
decl_stmt|;
comment|/* # mmx words passed so far */
name|int
name|mmx_nregs
decl_stmt|;
comment|/* # mmx registers available for passing */
name|int
name|mmx_regno
decl_stmt|;
comment|/* next available mmx register number */
name|int
name|maybe_vaarg
decl_stmt|;
comment|/* true for calls to possibly vardic fncts.  */
name|int
name|float_in_sse
decl_stmt|;
comment|/* 1 if in 32-bit mode SFmode (2 for DFmode) should 				   be passed in SSE registers.  Otherwise 0.  */
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
name|FNDECL
parameter_list|,
name|N_NAMED_ARGS
parameter_list|)
define|\
value|init_cumulative_args (&(CUM), (FNTYPE), (LIBNAME), (FNDECL))
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
comment|/* Implement `va_start' for varargs and stdarg.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_START
parameter_list|(
name|VALIST
parameter_list|,
name|NEXTARG
parameter_list|)
define|\
value|ix86_va_start (VALIST, NEXTARG)
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|ix86_file_end
end_define

begin_define
define|#
directive|define
name|NEED_INDICATE_EXEC_STACK
value|0
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
value|x86_function_profiler (FILE, LABELNO)
end_define

begin_define
define|#
directive|define
name|MCOUNT_NAME
value|"_mcount"
end_define

begin_define
define|#
directive|define
name|PROFILE_COUNT_REGISTER
value|"edx"
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_comment
comment|/* Note on the 386 it might be more efficient not to define this since    we have to restore it ourselves from the frame pointer, in order to    use pop */
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
comment|/* Non strict versions, pseudos are ok.  */
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
value|constant_address_p (X)
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
value|legitimate_constant_p (X)
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
comment|/* Nonzero if the constant value X is a legitimate general operand    when generating PIC code.  It is given that flag_pic is on and    that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
value|legitimate_pic_operand_p (X)
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
value|(TARGET_64BIT ? 8 : (TARGET_SSE ? 3 : 0))
end_define

begin_define
define|#
directive|define
name|MMX_REGPARM_MAX
value|(TARGET_64BIT ? 0 : (TARGET_MMX ? 3 : 0))
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
comment|/* If a memory-to-memory move would take MOVE_RATIO or more simple    move-instruction pairs, we will do a movmem or libcall instead.    Increasing the value will always make code faster, but eventually    incurs high cost in increased code size.     If you don't define this, a reasonable default is used.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_RATIO
value|(optimize_size ? 3 : ix86_cost->move_ratio)
end_define

begin_comment
comment|/* If a clear memory operation would take CLEAR_RATIO or more simple    move-instruction sequences, we will do a clrmem or libcall instead.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_RATIO
value|(optimize_size ? 2 \ 		     : ix86_cost->move_ratio> 6 ? 6 : ix86_cost->move_ratio)
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
comment|/* Define this macro to be the value 1 if unaligned accesses have a    cost many times greater than aligned accesses, for example if they    are emulated in a trap handler.     When this macro is nonzero, the compiler will act as if    `STRICT_ALIGNMENT' were nonzero when generating code for block    moves.  This can cause significantly more instructions to be    produced.  Therefore, do not set this macro nonzero if unaligned    accesses only add a cycle or two to the time for a memory access.     If the value of this macro is always zero, it need not be defined.  */
end_comment

begin_comment
comment|/* #define SLOW_UNALIGNED_ACCESS(MODE, ALIGN) 0 */
end_comment

begin_comment
comment|/* Define this macro if it is as good or better to call a constant    function address than to call an address kept in a register.     Desirable on the 386 because a CALL with a constant address is    faster than one with a register address.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_escape
end_escape

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
comment|/* Return nonzero if MODE implies a floating point inequality can be    reversed.  */
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
value|ix86_reverse_condition ((CODE), (MODE))
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
comment|/* In order to refer to the first 8 regs as 32 bit regs, prefix an "e".    For non floating point regs, the following are the HImode names.     For float regs, the stack top is sometimes referred to as "%st(0)"    instead of just "%st".  PRINT_OPERAND handles this with the "y" code.  */
end_comment

begin_define
define|#
directive|define
name|HI_REGISTER_NAMES
define|\
value|{"ax","dx","cx","bx","si","di","bp","sp",				\  "st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)",		\  "argp", "flags", "fpsr", "dirflag", "frame",				\  "xmm0","xmm1","xmm2","xmm3","xmm4","xmm5","xmm6","xmm7",		\  "mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7"	,		\  "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",			\  "xmm8", "xmm9", "xmm10", "xmm11", "xmm12", "xmm13", "xmm14", "xmm15"}
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
value|{ { "eax", 0 }, { "edx", 1 }, { "ecx", 2 }, { "ebx", 3 },	\   { "esi", 4 }, { "edi", 5 }, { "ebp", 6 }, { "esp", 7 },	\   { "rax", 0 }, { "rdx", 1 }, { "rcx", 2 }, { "rbx", 3 },	\   { "rsi", 4 }, { "rdi", 5 }, { "rbp", 6 }, { "rsp", 7 },	\   { "al", 0 }, { "dl", 1 }, { "cl", 2 }, { "bl", 3 },		\   { "ah", 0 }, { "dh", 1 }, { "ch", 2 }, { "bh", 3 } }
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
value|asm_preferred_eh_data_format ((CODE), (GLOBAL))
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
value|do {									\   if (TARGET_64BIT)							\     asm_fprintf ((FILE), "\tpush{q}\t%%r%s\n",				\ 		 reg_names[(REGNO)] + (REX_INT_REGNO_P (REGNO) != 0));	\   else									\     asm_fprintf ((FILE), "\tpush{l}\t%%e%s\n", reg_names[(REGNO)]);	\ } while (0)
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
value|do {									\   if (TARGET_64BIT)							\     asm_fprintf ((FILE), "\tpop{q}\t%%r%s\n",				\ 		 reg_names[(REGNO)] + (REX_INT_REGNO_P (REGNO) != 0));	\   else									\     asm_fprintf ((FILE), "\tpop{l}\t%%e%s\n", reg_names[(REGNO)]);	\ } while (0)
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
comment|/* Under some conditions we need jump tables in the text section,    because the assembler cannot handle label differences between    sections.  This is the case for x86_64 on Mach-O for example.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
define|\
value|(flag_pic&& ((TARGET_MACHO&& TARGET_64BIT) \    || (!TARGET_64BIT&& !HAVE_AS_GOTOFF_IN_DATA)))
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
value|((CODE) == '*' || (CODE) == '+' || (CODE) == '&')
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

begin_define
define|#
directive|define
name|OUTPUT_ADDR_CONST_EXTRA
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|FAIL
parameter_list|)
define|\
value|do {						\   if (! output_addr_const_extra (FILE, (X)))	\     goto FAIL;					\ } while (0);
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
name|PROCESSOR_GEODE
block|,
name|PROCESSOR_K6
block|,
name|PROCESSOR_ATHLON
block|,
name|PROCESSOR_PENTIUM4
block|,
name|PROCESSOR_K8
block|,
name|PROCESSOR_NOCONA
block|,
name|PROCESSOR_CORE2
block|,
name|PROCESSOR_GENERIC32
block|,
name|PROCESSOR_GENERIC64
block|,
name|PROCESSOR_AMDFAM10
block|,
name|PROCESSOR_max
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|ix86_tune
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|ix86_arch
decl_stmt|;
end_decl_stmt

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
name|fpmath_unit
name|ix86_fpmath
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|tls_dialect
block|{
name|TLS_DIALECT_GNU
block|,
name|TLS_DIALECT_GNU2
block|,
name|TLS_DIALECT_SUN
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|tls_dialect
name|ix86_tls_dialect
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|cmodel
block|{
name|CM_32
block|,
comment|/* The traditional 32-bit ABI.  */
name|CM_SMALL
block|,
comment|/* Assumes all code and data fits in the low 31 bits.  */
name|CM_KERNEL
block|,
comment|/* Assumes all code and data fits in the high 31 bits.  */
name|CM_MEDIUM
block|,
comment|/* Assumes code fits in the low 31 bits; data unlimited.  */
name|CM_LARGE
block|,
comment|/* No assumptions.  */
name|CM_SMALL_PIC
block|,
comment|/* Assumes code+data+got/plt fits in a 31 bit region.  */
name|CM_MEDIUM_PIC
comment|/* Assumes code+got/plt fits in a 31 bit region.  */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|cmodel
name|ix86_cmodel
decl_stmt|;
end_decl_stmt

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
name|enum
name|asm_dialect
name|ix86_asm_dialect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|ix86_preferred_stack_boundary
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ix86_branch_cost
decl_stmt|,
name|ix86_section_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Smallest class containing REGNO.  */
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

begin_decl_stmt
specifier|extern
name|rtx
name|ix86_compare_emitted
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* To properly truncate FP values into integers, we need to set i387 control    word.  We can't emit proper mode switching code before reload, as spills    generated by reload may truncate values incorrectly, but we still can avoid    redundant computation of new control word by the mode switching pass.    The fldcw instructions are still emitted redundantly, but this is probably    not going to be noticeable problem, as most CPUs do have fast path for    the sequence.     The machinery is to emit simple truncation instructions and split them    before reload to instructions having USEs of two memory locations that    are filled by this code to old and new control word.     Post-reload pass may be later used to eliminate the redundant fildcw if    needed.  */
end_comment

begin_enum
enum|enum
name|ix86_entity
block|{
name|I387_TRUNC
init|=
literal|0
block|,
name|I387_FLOOR
block|,
name|I387_CEIL
block|,
name|I387_MASK_PM
block|,
name|MAX_386_ENTITIES
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ix86_stack_slot
block|{
name|SLOT_VIRTUAL
init|=
literal|0
block|,
name|SLOT_TEMP
block|,
name|SLOT_CW_STORED
block|,
name|SLOT_CW_TRUNC
block|,
name|SLOT_CW_FLOOR
block|,
name|SLOT_CW_CEIL
block|,
name|SLOT_CW_MASK_PM
block|,
name|MAX_386_STACK_LOCALS
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
define|\
value|ix86_optimize_mode_switching[(ENTITY)]
end_define

begin_comment
comment|/* If you define `OPTIMIZE_MODE_SWITCHING', you have to define this as    initializer for an array of integers.  Each initializer element N    refers to an entity that needs mode switching, and specifies the    number of different modes that might need to be set for this    entity.  The position of the initializer in the initializer -    starting counting at zero - determines the integer that is used to    refer to the mode-switched entity in question.  */
end_comment

begin_define
define|#
directive|define
name|NUM_MODES_FOR_MODE_SWITCHING
define|\
value|{ I387_CW_ANY, I387_CW_ANY, I387_CW_ANY, I387_CW_ANY }
end_define

begin_comment
comment|/* ENTITY is an integer specifying a mode-switched entity.  If    `OPTIMIZE_MODE_SWITCHING' is defined, you must define this macro to    return an integer value not larger than the corresponding element    in `NUM_MODES_FOR_MODE_SWITCHING', to denote the mode that ENTITY    must be switched into prior to the execution of INSN. */
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
value|ix86_mode_needed ((ENTITY), (I))
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
value|((MODE) != I387_CW_ANY&& (MODE) != I387_CW_UNINITIALIZED		\    ? emit_i387_cw_initialization (MODE), 0				\    : 0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Avoid renaming of stack registers, as doing so in combination with    scheduling just increases amount of live registers at time and in    the turn amount of fxch instructions needed.     ??? Maybe Pentium chips benefits from renaming, someone can try....  */
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

begin_define
define|#
directive|define
name|DLL_IMPORT_EXPORT_PREFIX
value|'#'
end_define

begin_define
define|#
directive|define
name|FASTCALL_PREFIX
value|'@'
end_define

begin_escape
end_escape

begin_decl_stmt
name|struct
name|machine_function
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|stack_local_entry
modifier|*
name|stack_locals
decl_stmt|;
specifier|const
name|char
modifier|*
name|some_ld_name
decl_stmt|;
name|rtx
name|force_align_arg_pointer
decl_stmt|;
name|int
name|save_varrargs_registers
decl_stmt|;
name|int
name|accesses_prev_frame
decl_stmt|;
name|int
name|optimize_mode_switching
index|[
name|MAX_386_ENTITIES
index|]
decl_stmt|;
comment|/* Set by ix86_compute_frame_layout and used by prologue/epilogue expander to      determine the style used.  */
name|int
name|use_fast_prologue_epilogue
decl_stmt|;
comment|/* Number of saved registers USE_FAST_PROLOGUE_EPILOGUE has been computed      for.  */
name|int
name|use_fast_prologue_epilogue_nregs
decl_stmt|;
comment|/* If true, the current function needs the default PIC register, not      an alternate register (on x86) and must not use the red zone (on      x86_64), even if it's a leaf function.  We don't want the      function to be regarded as non-leaf because TLS calls need not      affect register allocation.  This flag is set when a TLS call      instruction is expanded within a function, and never reset, even      if all such instructions are optimized away.  Use the      ix86_current_function_calls_tls_descriptor macro for a better      approximation.  */
name|int
name|tls_descriptor_call_expanded_p
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|ix86_stack_locals
value|(cfun->machine->stack_locals)
end_define

begin_define
define|#
directive|define
name|ix86_save_varrargs_registers
value|(cfun->machine->save_varrargs_registers)
end_define

begin_define
define|#
directive|define
name|ix86_optimize_mode_switching
value|(cfun->machine->optimize_mode_switching)
end_define

begin_define
define|#
directive|define
name|ix86_tls_descriptor_calls_expanded_in_cfun
define|\
value|(cfun->machine->tls_descriptor_call_expanded_p)
end_define

begin_comment
comment|/* Since tls_descriptor_call_expanded is not cleared, even if all TLS    calls are optimized away, we try to detect cases in which it was    optimized away.  Since such instructions (use (reg REG_SP)), we can    verify whether there's any such instruction live by testing that    REG_SP is live.  */
end_comment

begin_define
define|#
directive|define
name|ix86_current_function_calls_tls_descriptor
define|\
value|(ix86_tls_descriptor_calls_expanded_in_cfun&& regs_ever_live[SP_REG])
end_define

begin_comment
comment|/* Control behavior of x86_file_start.  */
end_comment

begin_define
define|#
directive|define
name|X86_FILE_START_VERSION_DIRECTIVE
value|false
end_define

begin_define
define|#
directive|define
name|X86_FILE_START_FLTUSED
value|false
end_define

begin_comment
comment|/* Flag to mark data that is in the large address area.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_FLAG_FAR_ADDR
value|(SYMBOL_FLAG_MACH_DEP<< 0)
end_define

begin_define
define|#
directive|define
name|SYMBOL_REF_FAR_ADDR_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((SYMBOL_REF_FLAGS (X)& SYMBOL_FLAG_FAR_ADDR) != 0)
end_define

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

