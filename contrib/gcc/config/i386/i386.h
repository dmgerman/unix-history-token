begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler for Intel X86    (386, 486, Pentium).    Copyright (C) 1988, 92, 94, 95, 96, 97, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* The purpose of this file is to define the characteristics of the i386,    independent of assembler syntax or operating system.     Three other files build on this one to describe a specific assembler syntax:    bsd386.h, att386.h, and sun386.h.     The actual tm.h file for a particular system should include    this file, and then the file for the appropriate assembler syntax.     Many macros that specify assembler syntax are omitted entirely from    this file because they really belong in the files for particular    assemblers.  These include AS1, AS2, AS3, RP, IP, LPREFIX, L_SIZE,    PUT_OP_SIZE, USE_STAR, ADDR_BEG, ADDR_END, PRINT_IREG, PRINT_SCALE,    PRINT_B_I_S, and many that start with ASM_ or end in ASM_OP.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|I386
value|1
end_define

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

begin_comment
comment|/* Define the specific costs for a given cpu */
end_comment

begin_struct
struct|struct
name|processor_costs
block|{
name|int
name|add
decl_stmt|;
comment|/* cost of an add instruction */
name|int
name|lea
decl_stmt|;
comment|/* cost of a lea instruction */
name|int
name|shift_var
decl_stmt|;
comment|/* variable shift costs */
name|int
name|shift_const
decl_stmt|;
comment|/* constant shift costs */
name|int
name|mult_init
decl_stmt|;
comment|/* cost of starting a multiply */
name|int
name|mult_bit
decl_stmt|;
comment|/* cost of multiply per each bit set */
name|int
name|divide
decl_stmt|;
comment|/* cost of a divide/mod */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
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
value|000000000001
end_define

begin_comment
comment|/* Hardware floating point */
end_comment

begin_define
define|#
directive|define
name|MASK_NOTUSED1
value|000000000002
end_define

begin_comment
comment|/* bit not currently used */
end_comment

begin_define
define|#
directive|define
name|MASK_NOTUSED2
value|000000000004
end_define

begin_comment
comment|/* bit not currently used */
end_comment

begin_define
define|#
directive|define
name|MASK_RTD
value|000000000010
end_define

begin_comment
comment|/* Use ret that pops args */
end_comment

begin_define
define|#
directive|define
name|MASK_ALIGN_DOUBLE
value|000000000020
end_define

begin_comment
comment|/* align doubles to 2 word boundary */
end_comment

begin_define
define|#
directive|define
name|MASK_SVR3_SHLIB
value|000000000040
end_define

begin_comment
comment|/* Uninit locals into bss */
end_comment

begin_define
define|#
directive|define
name|MASK_IEEE_FP
value|000000000100
end_define

begin_comment
comment|/* IEEE fp comparisons */
end_comment

begin_define
define|#
directive|define
name|MASK_FLOAT_RETURNS
value|000000000200
end_define

begin_comment
comment|/* Return float in st(0) */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_FANCY_MATH_387
value|000000000400
end_define

begin_comment
comment|/* Disable sin, cos, sqrt */
end_comment

begin_define
define|#
directive|define
name|MASK_OMIT_LEAF_FRAME_POINTER
value|0x00000800
end_define

begin_comment
comment|/* omit leaf frame pointers */
end_comment

begin_comment
comment|/* Temporary codegen switches */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_ADDR
value|000001000000
end_define

begin_comment
comment|/* Debug GO_IF_LEGITIMATE_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_WIDE_MULTIPLY
value|000002000000
end_define

begin_comment
comment|/* Disable 32x32->64 multiplies */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_MOVE
value|000004000000
end_define

begin_comment
comment|/* Don't generate mem->mem */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_PSEUDO
value|000010000000
end_define

begin_comment
comment|/* Move op's args -> pseudos */
end_comment

begin_define
define|#
directive|define
name|MASK_DEBUG_ARG
value|000020000000
end_define

begin_comment
comment|/* Debug function_arg */
end_comment

begin_define
define|#
directive|define
name|MASK_SCHEDULE_PROLOGUE
value|000040000000
end_define

begin_comment
comment|/* Emit prologue as rtl */
end_comment

begin_define
define|#
directive|define
name|MASK_STACK_PROBE
value|000100000000
end_define

begin_comment
comment|/* Enable stack probing */
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
comment|/* Functions that return a floating point value may return that value    in the 387 FPU or in 386 integer registers.  If set, this flag causes    the 387 to be used, which is compatible with most calling conventions. */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLOAT_RETURNS_IN_80387
value|(target_flags& MASK_FLOAT_RETURNS)
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
value|(target_flags& MASK_OMIT_LEAF_FRAME_POINTER)
end_define

begin_comment
comment|/* Temporary switches for tuning code generation */
end_comment

begin_comment
comment|/* Disable 32x32->64 bit multiplies that are used for long long multiplies    and division by constants, but sometimes cause reload problems.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_NO_WIDE_MULTIPLY
value|(target_flags& MASK_NO_WIDE_MULTIPLY)
end_define

begin_define
define|#
directive|define
name|TARGET_WIDE_MULTIPLY
value|(!TARGET_NO_WIDE_MULTIPLY)
end_define

begin_comment
comment|/* Emit/Don't emit prologue as rtl */
end_comment

begin_define
define|#
directive|define
name|TARGET_SCHEDULE_PROLOGUE
value|(target_flags& MASK_SCHEDULE_PROLOGUE)
end_define

begin_comment
comment|/* Debug GO_IF_LEGITIMATE_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEBUG_ADDR
value|(target_flags& MASK_DEBUG_ADDR)
end_define

begin_comment
comment|/* Debug FUNCTION_ARG macros */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEBUG_ARG
value|(target_flags& MASK_DEBUG_ARG)
end_define

begin_comment
comment|/* Hack macros for tuning code generation */
end_comment

begin_define
define|#
directive|define
name|TARGET_MOVE
value|((target_flags& MASK_NO_MOVE) == 0)
end_define

begin_comment
comment|/* Don't generate memory->memory */
end_comment

begin_define
define|#
directive|define
name|TARGET_PSEUDO
value|((target_flags& MASK_NO_PSEUDO) == 0)
end_define

begin_comment
comment|/* Move op's args into pseudos */
end_comment

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
name|x86_unroll_strlen
decl_stmt|,
name|x86_use_q_reg
decl_stmt|,
name|x86_use_any_reg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|x86_double_with_add
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

begin_define
define|#
directive|define
name|TARGET_USE_Q_REG
value|(x86_use_q_reg& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_USE_ANY_REG
value|(x86_use_any_reg& CPUMASK)
end_define

begin_define
define|#
directive|define
name|TARGET_CMOVE
value|(x86_cmove& (1<< ix86_arch))
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
name|TARGET_DOUBLE_WITH_ADD
value|(x86_double_with_add& CPUMASK)
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
name|TARGET_SWITCHES
define|\
value|{ { "80387",			 MASK_80387, "Use hardware fp" },	\   { "no-80387",			-MASK_80387, "Do not use hardware fp" },\   { "hard-float",		 MASK_80387, "Use hardware fp" },	\   { "soft-float",		-MASK_80387, "Do not use hardware fp" },\   { "no-soft-float",		 MASK_80387, "Use hardware fp" },	\   { "386",			 0, "Same as -mcpu=i386" },		\   { "486",			 0, "Same as -mcpu=i486" },		\   { "pentium",			 0, "Same as -mcpu=pentium" },		\   { "pentiumpro",		 0, "Same as -mcpu=pentiumpro" },	\   { "rtd",			 MASK_RTD, "Alternate calling convention" },\   { "no-rtd",			-MASK_RTD, "Use normal calling convention" },\   { "align-double",		 MASK_ALIGN_DOUBLE, "Align some doubles on dword boundary" },\   { "no-align-double",		-MASK_ALIGN_DOUBLE, "Align doubles on word boundary" },		\   { "svr3-shlib",		 MASK_SVR3_SHLIB, "Uninitialized locals in .bss"  },			\   { "no-svr3-shlib",		-MASK_SVR3_SHLIB, "Uninitialized locals in .data" },			\   { "ieee-fp",			 MASK_IEEE_FP, "Use IEEE math for fp comparisons" },	\   { "no-ieee-fp",		-MASK_IEEE_FP, "Do not use IEEE math for fp comparisons" },			\   { "fp-ret-in-387",		 MASK_FLOAT_RETURNS, "Return values of functions in FPU registers" },			\   { "no-fp-ret-in-387",		-MASK_FLOAT_RETURNS , "Do not return values of functions in FPU registers"},			\   { "no-fancy-math-387",	 MASK_NO_FANCY_MATH_387, "Do not generate sin, cos, sqrt for 387" },		\   { "fancy-math-387",		-MASK_NO_FANCY_MATH_387, "Generate sin, cos, sqrt for FPU"},		\   { "omit-leaf-frame-pointer",	 MASK_OMIT_LEAF_FRAME_POINTER, "Omit the frame pointer in leaf functions" }, 	\   { "no-omit-leaf-frame-pointer",-MASK_OMIT_LEAF_FRAME_POINTER, "" },       \   { "no-wide-multiply",		 MASK_NO_WIDE_MULTIPLY, "multiplies of 32 bits constrained to 32 bits" },		\   { "wide-multiply",		-MASK_NO_WIDE_MULTIPLY, "multiplies of 32 bits are 64 bits" },		\   { "schedule-prologue",	 MASK_SCHEDULE_PROLOGUE, "Schedule function prologues" },		\   { "no-schedule-prologue",	-MASK_SCHEDULE_PROLOGUE, "" },		\   { "debug-addr",		 MASK_DEBUG_ADDR, 0
comment|/* intentionally undoc */
value|},			\   { "no-debug-addr",		-MASK_DEBUG_ADDR, 0
comment|/* intentionally undoc */
value|},			\   { "move",			-MASK_NO_MOVE, "Generate mem-mem moves" },			\   { "no-move",			 MASK_NO_MOVE, "Don't generate mem-mem moves" },			\   { "debug-arg",		 MASK_DEBUG_ARG, 0
comment|/* intentionally undoc */
value|},			\   { "no-debug-arg",		-MASK_DEBUG_ARG, 0
comment|/* intentionally undoc */
value|},			\   { "stack-arg-probe",		 MASK_STACK_PROBE, "Enable stack probing" },			\   { "no-stack-arg-probe",	-MASK_STACK_PROBE, "" },			\   { "windows",			0, 0
comment|/* intentionally undoc */
value|},					\   { "dll",			0, 0
comment|/* intentionally undoc */
value|},					\   SUBTARGET_SWITCHES							\   { "", MASK_SCHEDULE_PROLOGUE | TARGET_DEFAULT, 0 }}
end_define

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
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PROCESSOR_I386_STRING
value|"i386"
end_define

begin_define
define|#
directive|define
name|PROCESSOR_I486_STRING
value|"i486"
end_define

begin_define
define|#
directive|define
name|PROCESSOR_I586_STRING
value|"i586"
end_define

begin_define
define|#
directive|define
name|PROCESSOR_PENTIUM_STRING
value|"pentium"
end_define

begin_define
define|#
directive|define
name|PROCESSOR_I686_STRING
value|"i686"
end_define

begin_define
define|#
directive|define
name|PROCESSOR_PENTIUMPRO_STRING
value|"pentiumpro"
end_define

begin_define
define|#
directive|define
name|PROCESSOR_K6_STRING
value|"k6"
end_define

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|ix86_cpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ix86_arch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the default processor.  This is overridden by other tm.h files.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|(enum processor_type) TARGET_CPU_DEFAULT
end_define

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT_STRING
define|\
value|(PROCESSOR_DEFAULT == PROCESSOR_I486 ? PROCESSOR_I486_STRING  \   : PROCESSOR_DEFAULT == PROCESSOR_PENTIUM ? PROCESSOR_PENTIUM_STRING  \   : PROCESSOR_DEFAULT == PROCESSOR_PENTIUMPRO ? PROCESSOR_PENTIUMPRO_STRING  \   : PROCESSOR_DEFAULT == PROCESSOR_K6 ? PROCESSOR_K6_STRING  \   : PROCESSOR_I386_STRING)
end_define

begin_comment
comment|/* This macro is similar to `TARGET_SWITCHES' but defines names of    command options that have values.  Its definition is an    initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    fixed part of the option name, and the address of a variable.  The    variable, type `char *', is set to the variable part of the given    option if the fixed part matches.  The actual option name is made    by appending `-m' to the specified name.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{ { "cpu=",&ix86_cpu_string, "Schedule code for given CPU"}, \   { "arch=",&ix86_arch_string, "Generate code for given CPU"}, \   { "reg-alloc=",&i386_reg_alloc_order, "Control allocation order of integer registers" }, \   { "regparm=",&i386_regparm_string, "Number of registers used to pass integer arguments" }, \   { "align-loops=",&i386_align_loops_string, "Loop code aligned to this power of 2" }, \   { "align-jumps=",&i386_align_jumps_string, "Jump targets are aligned to this power of 2" }, \   { "align-functions=",&i386_align_funcs_string, "Function starts are aligned to this power of 2" }, \   { "preferred-stack-boundary=",&i386_preferred_stack_boundary_string, "Attempt to keep stack aligned to this power of 2" }, \   { "branch-cost=",&i386_branch_cost_string, "Branches are this expensive (1-5, arbitrary units)" },			\   SUBTARGET_OPTIONS							\ }
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
value|optimization_options(LEVEL,SIZE)
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
value|"\ %{!mcpu*: \ %{m386:-mcpu=i386 -march=i386} \ %{m486:-mcpu=i486 -march=i486} \ %{mpentium:-mcpu=pentium} \ %{mpentiumpro:-mcpu=pentiumpro}}"
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
name|CPP_486_SPEC
value|"%{!ansi:-Di486} -D__i486 -D__i486__"
end_define

begin_define
define|#
directive|define
name|CPP_586_SPEC
value|"%{!ansi:-Di586 -Dpentium} \ 	-D__i586 -D__i586__ -D__pentium -D__pentium__"
end_define

begin_define
define|#
directive|define
name|CPP_K6_SPEC
value|"%{!ansi:-Di586 -Dk6} \ 	-D__i586 -D__i586__ -D__k6 -D__k6__"
end_define

begin_define
define|#
directive|define
name|CPP_686_SPEC
value|"%{!ansi:-Di686 -Dpentiumpro} \ 	-D__i686 -D__i686__ -D__pentiumpro -D__pentiumpro__"
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
literal|1
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"%(cpp_486)"
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
literal|2
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"%(cpp_586)"
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
literal|3
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"%(cpp_686)"
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
literal|4
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|"%(cpp_k6)"
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
value|""
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

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_CPU_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_CPU_SPEC
value|"\ -Acpu(i386) -Amachine(i386) \ %{!ansi:-Di386} -D__i386 -D__i386__ \ %{mcpu=i486:%(cpp_486)} %{m486:%(cpp_486)} \ %{mpentium:%(cpp_586)} %{mcpu=pentium:%(cpp_586)} \ %{mpentiumpro:%(cpp_686)} %{mcpu=pentiumpro:%(cpp_686)} \ %{mcpu=k6:%(cpp_k6)} \ %{!mcpu*:%{!m486:%{!mpentium*:%(cpp_cpu_default)}}}"
end_define

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
value|"%(cc1_spec) "
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
value|{ "cpp_486", CPP_486_SPEC},						\   { "cpp_586", CPP_586_SPEC},						\   { "cpp_k6", CPP_K6_SPEC},						\   { "cpp_686", CPP_686_SPEC},						\   { "cpp_cpu_default",	CPP_CPU_DEFAULT_SPEC },				\   { "cpp_cpu",	CPP_CPU_SPEC },						\   { "cc1_cpu",  CC1_CPU_SPEC },						\   SUBTARGET_EXTRA_SPECS
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define for XFmode extended real floating point support.    This will automatically cause REAL_ARITHMETIC to be defined.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|96
end_define

begin_comment
comment|/* Define if you don't want extended real, but do want to use the    software floating point emulator for REAL_ARITHMETIC and    decimal<-> binary conversion. */
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
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
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
comment|/* Boundary (in *bits*) on which the stack pointer must be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_comment
comment|/* Boundary (in *bits*) on which the stack pointer preferrs to be    aligned; the compiler cannot rely on having this alignment.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_STACK_BOUNDARY
value|i386_preferred_stack_boundary
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.    For i486, we get better performance by aligning to a cache    line (i.e. 16 byte) boundary.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|(1<< (i386_align_funcs + 3))
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure. */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_comment
comment|/* Minimum size in bits of the largest boundary to which any    and all fundamental data types supported by the hardware    might need to be aligned. No data type wants to be aligned    rounder than this.  The i386 supports 64-bit floating point    quantities, but these can be aligned on any 32-bit boundary.    The published ABIs say that doubles should be aligned on word    boundaries, but the Pentium gets better performance with them    aligned on 64 bit boundaries. */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|(TARGET_ALIGN_DOUBLE ? 64 : 32)
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
value|(TREE_CODE (EXP) == REAL_CST						\     ? ((TYPE_MODE (TREE_TYPE (EXP)) == DFmode&& (ALIGN)< 64)		\ 	? 64								\    	: (TYPE_MODE (TREE_TYPE (EXP)) == XFmode&& (ALIGN)< 128)	\ 	? 128								\ 	: (ALIGN))							\     : TREE_CODE (EXP) == STRING_CST					\     ? ((TREE_STRING_LENGTH (EXP)>= 31&& (ALIGN)< 256)		\ 	? 256								\ 	: (ALIGN))							\     : (ALIGN))
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
define|\
value|((AGGREGATE_TYPE_P (TYPE)						\&& TYPE_SIZE (TYPE)							\&& TREE_CODE (TYPE_SIZE (TYPE)) == INTEGER_CST			\&& (TREE_INT_CST_LOW (TYPE_SIZE (TYPE))>= 256			\ 	|| TREE_INT_CST_HIGH (TYPE_SIZE (TYPE)))&& (ALIGN)< 256)	\     ? 256								\     : TREE_CODE (TYPE) == ARRAY_TYPE					\     ? ((TYPE_MODE (TREE_TYPE (TYPE)) == DFmode&& (ALIGN)< 64)	\ 	? 64								\    	: (TYPE_MODE (TREE_TYPE (TYPE)) == XFmode&& (ALIGN)< 128)	\ 	? 128								\ 	: (ALIGN))							\     : TREE_CODE (TYPE) == COMPLEX_TYPE					\     ? ((TYPE_MODE (TYPE) == DCmode&& (ALIGN)< 64)			\ 	? 64								\    	: (TYPE_MODE (TYPE) == XCmode&& (ALIGN)< 128)			\ 	? 128								\ 	: (ALIGN))							\     : ((TREE_CODE (TYPE) == RECORD_TYPE					\ 	|| TREE_CODE (TYPE) == UNION_TYPE				\ 	|| TREE_CODE (TYPE) == QUAL_UNION_TYPE)				\&& TYPE_FIELDS (TYPE))						\     ? ((DECL_MODE (TYPE_FIELDS (TYPE)) == DFmode&& (ALIGN)< 64)	\ 	? 64								\ 	: (DECL_MODE (TYPE_FIELDS (TYPE)) == XFmode&& (ALIGN)< 128)	\ 	? 128								\ 	: (ALIGN))							\     : TREE_CODE (TYPE) == REAL_TYPE					\     ? ((TYPE_MODE (TYPE) == DFmode&& (ALIGN)< 64)			\ 	? 64								\    	: (TYPE_MODE (TYPE) == XFmode&& (ALIGN)< 128)			\ 	? 128								\ 	: (ALIGN))							\     : (ALIGN))
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
define|\
value|(TREE_CODE (TYPE) == ARRAY_TYPE					\     ? ((TYPE_MODE (TREE_TYPE (TYPE)) == DFmode&& (ALIGN)< 64)		\ 	? 64								\    	: (TYPE_MODE (TREE_TYPE (TYPE)) == XFmode&& (ALIGN)< 128)	\ 	? 128								\ 	: (ALIGN))							\     : TREE_CODE (TYPE) == COMPLEX_TYPE					\     ? ((TYPE_MODE (TYPE) == DCmode&& (ALIGN)< 64)			\ 	? 64								\    	: (TYPE_MODE (TYPE) == XCmode&& (ALIGN)< 128)			\ 	? 128								\ 	: (ALIGN))							\     : ((TREE_CODE (TYPE) == RECORD_TYPE					\ 	|| TREE_CODE (TYPE) == UNION_TYPE				\ 	|| TREE_CODE (TYPE) == QUAL_UNION_TYPE)				\&& TYPE_FIELDS (TYPE))						\     ? ((DECL_MODE (TYPE_FIELDS (TYPE)) == DFmode&& (ALIGN)< 64)	\ 	? 64								\ 	: (DECL_MODE (TYPE_FIELDS (TYPE)) == XFmode&& (ALIGN)< 128)	\ 	? 128								\ 	: (ALIGN))							\     : TREE_CODE (TYPE) == REAL_TYPE					\     ? ((TYPE_MODE (TYPE) == DFmode&& (ALIGN)< 64)			\ 	? 64								\    	: (TYPE_MODE (TYPE) == XFmode&& (ALIGN)< 128)			\ 	? 128								\ 	: (ALIGN))							\     : (ALIGN))
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

begin_comment
comment|/* Maximum power of 2 that code can be aligned to.  */
end_comment

begin_define
define|#
directive|define
name|MAX_CODE_ALIGN
value|6
end_define

begin_comment
comment|/* 64 byte alignment */
end_comment

begin_comment
comment|/* Align loop starts for optimal branching.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_ALIGN
parameter_list|(
name|LABEL
parameter_list|)
value|(i386_align_loops)
end_define

begin_define
define|#
directive|define
name|LOOP_ALIGN_MAX_SKIP
value|(i386_align_loops_string ? 0 : 7)
end_define

begin_comment
comment|/* This is how to align an instruction for optimal branching.    On i486 we'll get better performance by aligning on a    cache line (i.e. 16 byte) boundary.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_ALIGN_AFTER_BARRIER
parameter_list|(
name|LABEL
parameter_list|)
value|(i386_align_jumps)
end_define

begin_define
define|#
directive|define
name|LABEL_ALIGN_AFTER_BARRIER_MAX_SKIP
value|(i386_align_jumps_string ? 0 : 7)
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* This processor has special stack-like registers.  See reg-stack.c    for details. */
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
name|mode
parameter_list|)
value|(mode==DFmode || mode==SFmode || mode==XFmode)
end_define

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     In the 80386 we give the 8 general purpose registers the numbers 0-7.    We number the floating point registers 8-15.    Note that registers 0-7 can be accessed as a  short or int,    while only 0-3 may be used with byte `mov' instructions.     Reg 16 does not correspond to any hardware register, but instead    appears in the RTL as an argument pointer prior to reload, and is    eliminated during reloading in favor of either the stack or frame    pointer. */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|17
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the 80386, the stack pointer is such, as is the arg pointer. */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7,arg*/
define|\
value|{  0, 0, 0, 0, 0, 0, 0, 1, 0,  0,  0,  0,  0,  0,  0,  0,  1 }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7,arg*/
define|\
value|{  1, 1, 1, 0, 0, 0, 0, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1 }
end_define

begin_comment
comment|/* Order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.  List frame pointer    late and fixed registers last.  Note that, in general, we prefer    registers listed in CALL_USED_REGISTERS, keeping the others    available for storage of persistent values.     Three different versions of REG_ALLOC_ORDER have been tried:     If the order is edx, ecx, eax, ... it produces a slightly faster compiler,    but slower code on simple functions returning values in eax.     If the order is eax, ecx, edx, ... it causes reload to abort when compiling    perl 4.036 due to not being able to create a DImode register (to hold a 2    word union).     If the order is eax, edx, ecx, ... it produces better code for simple    functions, and a slightly slower compiler.  Users complained about the code    generated by allocating edx first, so restore the 'natural' order of things. */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
comment|/*ax,dx,cx,bx,si,di,bp,sp,st,st1,st2,st3,st4,st5,st6,st7,arg*/
define|\
value|{  0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16 }
end_define

begin_comment
comment|/* A C statement (sans semicolon) to choose the order in which to    allocate hard registers for pseudo-registers local to a basic    block.     Store the desired register order in the array `reg_alloc_order'.    Element 0 should be the register to allocate first; element 1, the    next register; and so on.     The macro body should not assume anything about the contents of    `reg_alloc_order' before execution of the macro.     On most machines, it is not necessary to define this macro.  */
end_comment

begin_define
define|#
directive|define
name|ORDER_REGS_FOR_LOCAL_ALLOC
value|order_regs_for_local_alloc ()
end_define

begin_comment
comment|/* Macro to conditionally modify fixed_regs/call_used_regs.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{							\     if (flag_pic)					\       {							\ 	fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;	\ 	call_used_regs[PIC_OFFSET_TABLE_REGNUM] = 1;	\       }							\     if (! TARGET_80387&& ! TARGET_FLOAT_RETURNS_IN_80387) \       { 						\ 	int i; 						\ 	HARD_REG_SET x;					\         COPY_HARD_REG_SET (x, reg_class_contents[(int)FLOAT_REGS]); \         for (i = 0; i< FIRST_PSEUDO_REGISTER; i++ )	\          if (TEST_HARD_REG_BIT (x, i)) 			\ 	  fixed_regs[i] = call_used_regs[i] = 1; 	\       }							\   }
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
value|(FP_REGNO_P (REGNO) ? 1 \    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the 80386, the first 4 cpu registers can hold any mode    while the floating point registers may hold only floating point.    Make it clear that the fp regs could not hold a 16-byte float.  */
end_comment

begin_comment
comment|/* The casts to int placate a compiler on a microvax,    for cross-compiler testing.  */
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
value|((REGNO)< 4 ? 1						\    : FP_REGNO_P (REGNO)						\    ? (((int) GET_MODE_CLASS (MODE) == (int) MODE_FLOAT		\        || (int) GET_MODE_CLASS (MODE) == (int) MODE_COMPLEX_FLOAT)	\&& GET_MODE_UNIT_SIZE (MODE)<= (LONG_DOUBLE_TYPE_SIZE == 96 ? 12 : 8))\    : (int) (MODE) != (int) QImode ? 1				\    : (reload_in_progress | reload_completed) == 1)
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
value|((MODE1) == (MODE2)						\    || ((MODE1) == SImode&& (MODE2) == HImode)			\    || ((MODE1) == HImode&& (MODE2) == SImode))
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
name|FRAME_POINTER_REGNUM
value|6
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

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|(TARGET_OMIT_LEAF_FRAME_POINTER&& !leaf_function_p ())
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
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|2
end_define

begin_comment
comment|/* Register to hold the addressing base for position independent    code access to data items.  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|3
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
value|((TYPE_MODE (TYPE) == BLKmode) || int_size_in_bytes (TYPE)> 12)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.     It might seem that class BREG is unnecessary, since no useful 386    opcode needs reg %ebx.  But some systems pass args to the OS in ebx,    and the "b" register constraint is useful in asms for syscalls.  */
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
name|AD_REGS
block|,
comment|/* %eax/%edx for DImode */
name|Q_REGS
block|,
comment|/* %eax %ebx %ecx %edx */
name|SIREG
block|,
name|DIREG
block|,
name|INDEX_REGS
block|,
comment|/* %eax %ebx %ecx %edx %esi %edi %ebp */
name|GENERAL_REGS
block|,
comment|/* %eax %ebx %ecx %edx %esi %edi %ebp %esp */
name|FP_TOP_REG
block|,
name|FP_SECOND_REG
block|,
comment|/* %st(0) %st(1) */
name|FLOAT_REGS
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
value|(int) LIM_REG_CLASSES
end_define

begin_define
define|#
directive|define
name|FLOAT_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
value|(reg_class_subset_p (CLASS, FLOAT_REGS))
end_define

begin_comment
comment|/* Give names of register classes as strings for dump file.   */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{  "NO_REGS",				\    "AREG", "DREG", "CREG", "BREG",	\    "AD_REGS",				\    "Q_REGS",				\    "SIREG", "DIREG",			\    "INDEX_REGS",			\    "GENERAL_REGS",			\    "FP_TOP_REG", "FP_SECOND_REG",	\    "FLOAT_REGS",			\    "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{      {0},							\      {0x1},    {0x2},  {0x4},	 {0x8},
comment|/* AREG, DREG, CREG, BREG */
value|\      {0x3},
comment|/* AD_REGS */
value|\      {0xf},
comment|/* Q_REGS */
value|\     {0x10},   {0x20},
comment|/* SIREG, DIREG */
value|\  {0x7f},
comment|/* INDEX_REGS */
value|\  {0x100ff},
comment|/* GENERAL_REGS */
value|\   {0x0100}, {0x0200},
comment|/* FP_TOP_REG, FP_SECOND_REG */
value|\   {0xff00},
comment|/* FLOAT_REGS */
value|\  {0x1ffff}}
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
comment|/* When defined, the compiler allows registers explicitly used in the    rtl to be used as spill registers but prevents the compiler from    extending the lifetime of these registers. */
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
name|n
parameter_list|)
value|((n)>= FIRST_STACK_REG&& (n)<= LAST_STACK_REG)
end_define

begin_define
define|#
directive|define
name|STACK_REG_P
parameter_list|(
name|xop
parameter_list|)
value|(REG_P (xop)&&		       	\ 			  REGNO (xop)>= FIRST_STACK_REG&&	\ 			  REGNO (xop)<= LAST_STACK_REG)
end_define

begin_define
define|#
directive|define
name|NON_STACK_REG_P
parameter_list|(
name|xop
parameter_list|)
value|(REG_P (xop)&& ! STACK_REG_P (xop))
end_define

begin_define
define|#
directive|define
name|STACK_TOP_P
parameter_list|(
name|xop
parameter_list|)
value|(REG_P (xop)&& REGNO (xop) == FIRST_STACK_REG)
end_define

begin_comment
comment|/* 1 if register REGNO can magically overlap other regs.    Note that nonzero values work only in very special circumstances. */
end_comment

begin_comment
comment|/* #define OVERLAPPING_REGNO_P(REGNO) FP_REGNO_P (REGNO) */
end_comment

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
value|((C) == 'r' ? GENERAL_REGS :					\    (C) == 'q' ? Q_REGS :					\    (C) == 'f' ? (TARGET_80387 || TARGET_FLOAT_RETURNS_IN_80387	\ 		 ? FLOAT_REGS					\ 		 : NO_REGS) :					\    (C) == 't' ? (TARGET_80387 || TARGET_FLOAT_RETURNS_IN_80387	\ 		 ? FP_TOP_REG					\ 		 : NO_REGS) :					\    (C) == 'u' ? (TARGET_80387 || TARGET_FLOAT_RETURNS_IN_80387	\ 		 ? FP_SECOND_REG				\ 		 : NO_REGS) :					\    (C) == 'a' ? AREG :						\    (C) == 'b' ? BREG :						\    (C) == 'c' ? CREG :						\    (C) == 'd' ? DREG :						\    (C) == 'A' ? AD_REGS :					\    (C) == 'D' ? DIREG :						\    (C) == 'S' ? SIREG : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     I is for non-DImode shifts.    J is for DImode shifts.    K and L are for an `andsi' optimization.    M is for shifts that can be executed by the "lea" opcode.    */
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
value|((C) == 'I' ? (VALUE)>= 0&& (VALUE)<= 31 :	\    (C) == 'J' ? (VALUE)>= 0&& (VALUE)<= 63 :	\    (C) == 'K' ? (VALUE) == 0xff :		\    (C) == 'L' ? (VALUE) == 0xffff :		\    (C) == 'M' ? (VALUE)>= 0&& (VALUE)<= 3 :	\    (C) == 'N' ? (VALUE)>= 0&& (VALUE)<= 255 :\    (C) == 'O' ? (VALUE)>= 0&& (VALUE)<= 32 :	\    0)
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
value|((C) == 'G' ? standard_80387_constant_p (VALUE) : 0)
end_define

begin_comment
comment|/* Place additional restrictions on the register class to use when it    is necessary to be able to hold a value of mode MODE in a reload    register for which class CLASS would ordinarily be used. */
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
value|((MODE) == QImode&& ((CLASS) == ALL_REGS || (CLASS) == GENERAL_REGS) \    ? Q_REGS : (CLASS))
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.    On the 80386 series, we prevent floating constants from being    reloaded into floating registers (since no move-insn can do that)    and we ensure that QImodes aren't reloaded into the esi or edi reg.  */
end_comment

begin_comment
comment|/* Put float CONST_DOUBLE in the constant pool instead of fp regs.    QImode must go into class Q_REGS.    Narrow ALL_REGS to GENERAL_REGS.  This supports allowing movsf and    movdf to do mem-to-mem moves through integer regs. */
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
value|(GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) != VOIDmode		\    ? (standard_80387_constant_p (X)					\       ? reg_class_subset_p (CLASS, FLOAT_REGS) ? CLASS : FLOAT_REGS	\       : NO_REGS)							\    : GET_MODE (X) == QImode&& ! reg_class_subset_p (CLASS, Q_REGS) ? Q_REGS \    : ((CLASS) == ALL_REGS						\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT) ? GENERAL_REGS	\    : (CLASS))
end_define

begin_comment
comment|/* If we are copying between general and FP registers, we need a memory    location.  */
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
value|((FLOAT_CLASS_P (CLASS1)&& ! FLOAT_CLASS_P (CLASS2))	\    || (! FLOAT_CLASS_P (CLASS1)&& FLOAT_CLASS_P (CLASS2)))
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
value|(FLOAT_CLASS_P (CLASS) ? 1 :		\   ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
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
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On 386 pushw decrements by exactly 2 no matter what the position was.    On the 386 there is no pushb; we use pushw instead, and this    has the effect of rounding up to 2.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|BYTES
parameter_list|)
value|(((BYTES) + 1)& (-2))
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
value|(i386_return_pops_args (FUNDECL, FUNTYPE, SIZE))
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
value|gen_rtx_REG (TYPE_MODE (VALTYPE), \ 	    VALUE_REGNO (TYPE_MODE (VALTYPE)))
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
value|gen_rtx_REG (MODE, VALUE_REGNO (MODE))
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
value|((N)>= 0&& (N)< REGPARM_MAX)
end_define

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|i386_args
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
value|(init_cumulative_args (&CUM, FNTYPE, LIBNAME))
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
value|(function_arg_advance (&CUM, MODE, TYPE, NAMED))
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
value|(function_arg (&CUM, MODE, TYPE, NAMED))
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
define|\
value|(function_arg_partial_nregs (&CUM, MODE, TYPE, NAMED))
end_define

begin_comment
comment|/* This macro is invoked just before the start of a function.    It is used here to output code for -fpic that will load the    return address into %ebx.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FUNCTION_PREFIX
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FUNCTION_PREFIX
parameter_list|(
name|FILE
parameter_list|,
name|FNNAME
parameter_list|)
define|\
value|asm_output_function_prefix (FILE, FNNAME)
end_define

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
define|\
value|function_prologue (FILE, SIZE)
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
value|{									\   if (flag_pic)								\     {									\       fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%edx\n",		\ 	       LPREFIX, (LABELNO));					\       fprintf (FILE, "\tcall *_mcount@GOT(%%ebx)\n");			\     }									\   else									\     {									\       fprintf (FILE, "\tmovl $%sP%d,%%edx\n", LPREFIX, (LABELNO));	\       fprintf (FILE, "\tcall _mcount\n");				\     }									\ }
end_define

begin_comment
comment|/* There are three profiling modes for basic blocks available.    The modes are selected at compile time by using the options    -a or -ax of the gnu compiler.    The variable `profile_block_flag' will be set according to the    selected option.     profile_block_flag == 0, no option used:        No profiling done.     profile_block_flag == 1, -a option used.        Count frequency of execution of every basic block.     profile_block_flag == 2, -ax option used.        Generate code to allow several different profiling modes at run time.        Available modes are:              Produce a trace of all basic blocks.              Count frequency of jump instructions executed.       In every mode it is possible to start profiling upon entering       certain functions and to disable profiling of some other functions.      The result of basic-block profiling will be written to a file `bb.out'.     If the -ax option is used parameters for the profiling will be read     from file `bb.in'.  */
end_comment

begin_comment
comment|/* The following macro shall output assembler code to FILE    to initialize basic-block profiling.     If profile_block_flag == 2  	Output code to call the subroutine `__bb_init_trace_func' 	and pass two parameters to it. The first parameter is 	the address of a block allocated in the object module. 	The second parameter is the number of the first basic block 	of the function.  	The name of the block is a local symbol made with this statement: 	 	    ASM_GENERATE_INTERNAL_LABEL (BUFFER, "LPBX", 0);  	Of course, since you are writing the definition of 	`ASM_GENERATE_INTERNAL_LABEL' as well as that of this macro, you 	can take a short cut in the definition of this macro and use the 	name that you know will result.  	The number of the first basic block of the function is 	passed to the macro in BLOCK_OR_LABEL.  	If described in a virtual assembler language the code to be 	output looks like:  		parameter1<- LPBX0 		parameter2<- BLOCK_OR_LABEL 		call __bb_init_trace_func      else if profile_block_flag != 0  	Output code to call the subroutine `__bb_init_func' 	and pass one single parameter to it, which is the same 	as the first parameter to `__bb_init_trace_func'.  	The first word of this parameter is a flag which will be nonzero if 	the object module has already been initialized.  So test this word 	first, and do not call `__bb_init_func' if the flag is nonzero. 	Note: When profile_block_flag == 2 the test need not be done 	but `__bb_init_trace_func' *must* be called.  	BLOCK_OR_LABEL may be used to generate a label number as a 	branch destination in case `__bb_init_func' will not be called.  	If described in a virtual assembler language the code to be 	output looks like:  		cmp (LPBX0),0 		jne local_label 		parameter1<- LPBX0 		call __bb_init_func local_label:  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_BLOCK_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_BLOCK_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|BLOCK_OR_LABEL
parameter_list|)
define|\
value|do									\   {									\     static int num_func = 0;						\     rtx xops[8];							\     char block_table[80], false_label[80];				\ 									\     ASM_GENERATE_INTERNAL_LABEL (block_table, "LPBX", 0);		\ 									\     xops[1] = gen_rtx_SYMBOL_REF (VOIDmode, block_table);		\     xops[5] = stack_pointer_rtx;					\     xops[7] = gen_rtx_REG (Pmode, 0);
comment|/* eax */
value|\ 									\     CONSTANT_POOL_ADDRESS_P (xops[1]) = TRUE;				\ 									\     switch (profile_block_flag) 					\       {									\ 									\       case 2:								\ 									\         xops[2] = GEN_INT ((BLOCK_OR_LABEL));				\         xops[3] = gen_rtx_MEM (Pmode, gen_rtx_SYMBOL_REF (VOIDmode, "__bb_init_trace_func")); \         xops[6] = GEN_INT (8);						\     									\         output_asm_insn (AS1(push%L2,%2), xops);			\         if (!flag_pic)							\           output_asm_insn (AS1(push%L1,%1), xops);			\         else								\           {								\             output_asm_insn (AS2 (lea%L7,%a1,%7), xops);		\             output_asm_insn (AS1 (push%L7,%7), xops);			\           }								\     									\         output_asm_insn (AS1(call,%P3), xops);				\         output_asm_insn (AS2(add%L0,%6,%5), xops);			\ 									\         break;								\ 									\       default:								\ 									\         ASM_GENERATE_INTERNAL_LABEL (false_label, "LPBZ", num_func);	\     									\         xops[0] = const0_rtx;						\         xops[2] = gen_rtx_MEM (Pmode, gen_rtx_SYMBOL_REF (VOIDmode, false_label)); \         xops[3] = gen_rtx_MEM (Pmode, gen_rtx_SYMBOL_REF (VOIDmode, "__bb_init_func")); \         xops[4] = gen_rtx_MEM (Pmode, xops[1]);			\         xops[6] = GEN_INT (4);						\     									\         CONSTANT_POOL_ADDRESS_P (xops[2]) = TRUE;			\     									\         output_asm_insn (AS2(cmp%L4,%0,%4), xops);			\         output_asm_insn (AS1(jne,%2), xops);				\     									\         if (!flag_pic)							\           output_asm_insn (AS1(push%L1,%1), xops);			\         else								\           {								\             output_asm_insn (AS2 (lea%L7,%a1,%7), xops);		\             output_asm_insn (AS1 (push%L7,%7), xops);			\           }								\     									\         output_asm_insn (AS1(call,%P3), xops);				\         output_asm_insn (AS2(add%L0,%6,%5), xops);			\         ASM_OUTPUT_INTERNAL_LABEL (FILE, "LPBZ", num_func);		\         num_func++;							\ 									\         break;								\ 									\     }									\   }									\ while (0)
end_define

begin_comment
comment|/* The following macro shall output assembler code to FILE    to increment a counter associated with basic block number BLOCKNO.     If profile_block_flag == 2  	Output code to initialize the global structure `__bb' and 	call the function `__bb_trace_func' which will increment the 	counter.  	`__bb' consists of two words. In the first word the number 	of the basic block has to be stored. In the second word 	the address of a block allocated in the object module  	has to be stored.  	The basic block number is given by BLOCKNO.  	The address of the block is given by the label created with   	    ASM_GENERATE_INTERNAL_LABEL (BUFFER, "LPBX", 0);  	by FUNCTION_BLOCK_PROFILER.  	Of course, since you are writing the definition of 	`ASM_GENERATE_INTERNAL_LABEL' as well as that of this macro, you 	can take a short cut in the definition of this macro and use the 	name that you know will result.  	If described in a virtual assembler language the code to be 	output looks like:  		move BLOCKNO -> (__bb) 		move LPBX0 -> (__bb+4) 		call __bb_trace_func  	Note that function `__bb_trace_func' must not change the 	machine state, especially the flag register. To grant 	this, you must output code to save and restore registers 	either in this macro or in the macros MACHINE_STATE_SAVE 	and MACHINE_STATE_RESTORE. The last two macros will be 	used in the function `__bb_trace_func', so you must make 	sure that the function prologue does not change any  	register prior to saving it with MACHINE_STATE_SAVE.     else if profile_block_flag != 0  	Output code to increment the counter directly. 	Basic blocks are numbered separately from zero within each 	compiled object module. The count associated with block number 	BLOCKNO is at index BLOCKNO in an array of words; the name of  	this array is a local symbol made with this statement:  	    ASM_GENERATE_INTERNAL_LABEL (BUFFER, "LPBX", 2);  	Of course, since you are writing the definition of 	`ASM_GENERATE_INTERNAL_LABEL' as well as that of this macro, you 	can take a short cut in the definition of this macro and use the 	name that you know will result.   	If described in a virtual assembler language the code to be 	output looks like:  		inc (LPBX2+4*BLOCKNO)  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|BLOCKNO
parameter_list|)
define|\
value|do									\   {									\     rtx xops[8], cnt_rtx;						\     char counts[80];							\     char *block_table = counts;						\ 									\     switch (profile_block_flag) 					\       {									\ 									\       case 2:								\ 									\         ASM_GENERATE_INTERNAL_LABEL (block_table, "LPBX", 0);		\ 									\ 	xops[1] = gen_rtx_SYMBOL_REF (VOIDmode, block_table);		\         xops[2] = GEN_INT ((BLOCKNO));					\         xops[3] = gen_rtx_MEM (Pmode, gen_rtx_SYMBOL_REF (VOIDmode, "__bb_trace_func")); \         xops[4] = gen_rtx_SYMBOL_REF (VOIDmode, "__bb");		\ 	xops[5] = plus_constant (xops[4], 4);				\ 	xops[0] = gen_rtx_MEM (SImode, xops[4]);			\ 	xops[6] = gen_rtx_MEM (SImode, xops[5]);			\ 									\ 	CONSTANT_POOL_ADDRESS_P (xops[1]) = TRUE;			\ 									\ 	fprintf(FILE, "\tpushf\n");					\         output_asm_insn (AS2(mov%L0,%2,%0), xops);			\ 	if (flag_pic)							\ 	  {								\             xops[7] = gen_rtx_REG (Pmode, 0);
comment|/* eax */
value|\             output_asm_insn (AS1(push%L7,%7), xops);			\             output_asm_insn (AS2(lea%L7,%a1,%7), xops);			\             output_asm_insn (AS2(mov%L6,%7,%6), xops);			\             output_asm_insn (AS1(pop%L7,%7), xops);			\ 	  }								\         else								\           output_asm_insn (AS2(mov%L6,%1,%6), xops);			\         output_asm_insn (AS1(call,%P3), xops);				\ 	fprintf(FILE, "\tpopf\n");					\ 									\         break;								\ 									\       default:								\ 									\         ASM_GENERATE_INTERNAL_LABEL (counts, "LPBX", 2);		\         cnt_rtx = gen_rtx_SYMBOL_REF (VOIDmode, counts);		\         SYMBOL_REF_FLAG (cnt_rtx) = TRUE;				\ 									\         if (BLOCKNO)							\           cnt_rtx = plus_constant (cnt_rtx, (BLOCKNO)*4);		\ 									\         if (flag_pic)							\           cnt_rtx = gen_rtx_PLUS (Pmode, pic_offset_table_rtx, cnt_rtx);	\ 									\         xops[0] = gen_rtx_MEM (SImode, cnt_rtx);			\         output_asm_insn (AS1(inc%L0,%0), xops);				\ 									\         break;								\ 									\     }									\   }									\ while (0)
end_define

begin_comment
comment|/* The following macro shall output assembler code to FILE    to indicate a return from function during basic-block profiling.     If profiling_block_flag == 2:  	Output assembler code to call function `__bb_trace_ret'.  	Note that function `__bb_trace_ret' must not change the 	machine state, especially the flag register. To grant 	this, you must output code to save and restore registers 	either in this macro or in the macros MACHINE_STATE_SAVE_RET 	and MACHINE_STATE_RESTORE_RET. The last two macros will be 	used in the function `__bb_trace_ret', so you must make 	sure that the function prologue does not change any  	register prior to saving it with MACHINE_STATE_SAVE_RET.     else if profiling_block_flag != 0:  	The macro will not be used, so it need not distinguish 	these cases. */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BLOCK_PROFILER_EXIT
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do									\   {									\     rtx xops[1];							\ 									\     xops[0] = gen_rtx_MEM (Pmode, gen_rtx_SYMBOL_REF (VOIDmode, "__bb_trace_ret")); \ 									\     output_asm_insn (AS1(call,%P0), xops);				\ 									\   }									\ while (0)
end_define

begin_comment
comment|/* The function `__bb_trace_func' is called in every basic block    and is not allowed to change the machine state. Saving (restoring)    the state can either be done in the BLOCK_PROFILER macro,    before calling function (rsp. after returning from function)    `__bb_trace_func', or it can be done inside the function by    defining the macros:  	MACHINE_STATE_SAVE(ID) 	MACHINE_STATE_RESTORE(ID)     In the latter case care must be taken, that the prologue code    of function `__bb_trace_func' does not already change the    state prior to saving it with MACHINE_STATE_SAVE.     The parameter `ID' is a string identifying a unique macro use.     On the i386 the initialization code at the begin of    function `__bb_trace_func' contains a `sub' instruction    therefore we handle save and restore of the flag register     in the BLOCK_PROFILER macro. */
end_comment

begin_define
define|#
directive|define
name|MACHINE_STATE_SAVE
parameter_list|(
name|ID
parameter_list|)
define|\
value|asm ("	pushl %eax"); \   asm ("	pushl %ecx"); \   asm ("	pushl %edx"); \   asm ("	pushl %esi");
end_define

begin_define
define|#
directive|define
name|MACHINE_STATE_RESTORE
parameter_list|(
name|ID
parameter_list|)
define|\
value|asm ("	popl %esi"); \   asm ("	popl %edx"); \   asm ("	popl %ecx"); \   asm ("	popl %eax");
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
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.     The function epilogue should not depend on the current stack pointer!    It should use the frame pointer only.  This is mandatory because    of alloca; we also take advantage of it to omit stack adjustments    before returning.     If the last non-note insn in the function is a BARRIER, then there    is no need to emit a function prologue, because control does not fall    off the end.  This happens if the function ends in an "exit" call, or    if a `return' insn is emitted directly into the function. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|FUNCTION_BEGIN_EPILOGUE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {						\   rtx last = get_last_insn ();			\   if (last&& GET_CODE (last) == NOTE)		\     last = prev_nonnote_insn (last);		\
comment|/*  if (! last || GET_CODE (last) != BARRIER)	\     function_epilogue (FILE, SIZE);*/
value|\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FUNCTION_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|function_epilogue (FILE, SIZE)
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
value|10
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
value|{									\
comment|/* Compute offset from the end of the jmp to the target function.  */
value|\   rtx disp = expand_binop (SImode, sub_optab, FNADDR,			\ 			   plus_constant (TRAMP, 10),			\ 			   NULL_RTX, 1, OPTAB_DIRECT);			\   emit_move_insn (gen_rtx_MEM (QImode, TRAMP), GEN_INT (0xb9));		\   emit_move_insn (gen_rtx_MEM (SImode, plus_constant (TRAMP, 1)), CXT); \   emit_move_insn (gen_rtx_MEM (QImode, plus_constant (TRAMP, 5)), GEN_INT (0xe9));\   emit_move_insn (gen_rtx_MEM (SImode, plus_constant (TRAMP, 6)), disp); \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Definitions for register eliminations.     This is an array of structures.  Each structure initializes one pair    of eliminable registers.  The "from" register number is given first,    followed by "to".  Eliminations of the same "from" register are listed    in order of preference.     We have two registers that can be eliminated on the i386.  First, the    frame pointer register can often be eliminated in favor of the stack    pointer register.  Secondly, the argument pointer register can always be    eliminated; it is replaced with either the stack or frame pointer. */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ ARG_POINTER_REGNUM, STACK_POINTER_REGNUM},	\  { ARG_POINTER_REGNUM, FRAME_POINTER_REGNUM},   \  { FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM}}
end_define

begin_comment
comment|/* Given FROM and TO register numbers, say whether this elimination is allowed.    Frame pointer elimination is automatically handled.     For the i386, if frame pointer elimination is being done, we would like to    convert ap into sp, not fp.     All other eliminations are valid.  */
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
value|((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM	\   ? ! frame_pointer_needed					\   : 1)
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
value|{									\   if ((FROM) == ARG_POINTER_REGNUM&& (TO) == FRAME_POINTER_REGNUM)	\     (OFFSET) = 8;
comment|/* Skip saved PC and previous frame pointer */
value|\   else									\     {									\       int nregs;							\       int offset;							\       int preferred_alignment = PREFERRED_STACK_BOUNDARY / BITS_PER_UNIT; \       HOST_WIDE_INT tsize = ix86_compute_frame_size (get_frame_size (),	\&nregs);		\ 									\       (OFFSET) = (tsize + nregs * UNITS_PER_WORD);			\ 									\       offset = 4;							\       if (frame_pointer_needed)						\ 	offset += UNITS_PER_WORD;					\ 									\       if ((FROM) == ARG_POINTER_REGNUM)					\ 	(OFFSET) += offset;						\       else								\ 	(OFFSET) -= ((offset + preferred_alignment - 1)			\& -preferred_alignment) - offset;			\     }									\ }
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
value|((REGNO)< STACK_POINTER_REGNUM \    || (unsigned) reg_renumber[REGNO]< STACK_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)<= STACK_POINTER_REGNUM \    || (REGNO) == ARG_POINTER_REGNUM \    || (unsigned) reg_renumber[REGNO]<= STACK_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_SIREG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == 4 || reg_renumber[REGNO] == 4)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_DIREG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == 5 || reg_renumber[REGNO] == 5)
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
value|(REGNO (X)< STACK_POINTER_REGNUM					\    || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_NONSTRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)<= STACK_POINTER_REGNUM					\    || REGNO (X) == ARG_POINTER_REGNUM					\    || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_STRREG_NONSTRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X) == 4 || REGNO (X) == 5 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
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

begin_define
define|#
directive|define
name|REG_OK_FOR_STRREG_STRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO_OK_FOR_DIREG_P (REGNO (X)) || REGNO_OK_FOR_SIREG_P (REGNO (X)))
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
value|REG_OK_FOR_INDEX_NONSTRICT_P(X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_BASE_NONSTRICT_P(X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_STRREG_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_STRREG_NONSTRICT_P(X)
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
value|REG_OK_FOR_INDEX_STRICT_P(X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_BASE_STRICT_P(X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_STRREG_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_STRREG_STRICT_P(X)
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
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF	\    || GET_CODE (X) == CONST_INT || GET_CODE (X) == CONST)
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
define|\
value|(GET_CODE (X) == CONST_DOUBLE ? standard_80387_constant_p (X) : 1)
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
value|{									\   if (legitimate_address_p (MODE, X, 1))				\     goto ADDR;								\ }
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
value|{									\   if (legitimate_address_p (MODE, X, 0))				\     goto ADDR;								\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|{									\   (X) = legitimize_address (X, OLDX, MODE);				\   if (memory_address_p (MODE, X))					\     goto WIN;								\ }
end_define

begin_define
define|#
directive|define
name|REWRITE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|rewrite_address(x)
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
value|(! SYMBOLIC_CONST (X) || legitimate_pic_address_disp_p (X))
end_define

begin_define
define|#
directive|define
name|SYMBOLIC_CONST
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF						\  || GET_CODE (X) == LABEL_REF						\  || (GET_CODE (X) == CONST&& symbolic_reference_mentioned_p (X)))
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
value|if (GET_CODE (ADDR) == POST_INC || GET_CODE (ADDR) == POST_DEC) goto LABEL
end_define

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
value|do									\   {									\     if (flag_pic)							\       {									\ 	rtx rtl = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'		\ 		   ? TREE_CST_RTL (DECL) : DECL_RTL (DECL));		\ 									\ 	if (TARGET_DEBUG_ADDR						\&& TREE_CODE_CLASS (TREE_CODE (DECL)) == 'd')		\ 	  {								\ 	    fprintf (stderr, "Encode %s, public = %d\n",		\ 		     IDENTIFIER_POINTER (DECL_NAME (DECL)),		\ 		     TREE_PUBLIC (DECL));				\ 	  }								\ 									\ 	SYMBOL_REF_FLAG (XEXP (rtl, 0))					\ 	  = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'			\ 	     || ! TREE_PUBLIC (DECL));					\       }									\   }									\ while (0)
end_define

begin_comment
comment|/* Initialize data used by insn expanders.  This is called from    init_emit, once for each function, before code is generated.    For 386, clear stack slot assignments remembered from previous    functions. */
end_comment

begin_define
define|#
directive|define
name|INIT_EXPANDERS
value|clear_386_stack_locals ()
end_define

begin_comment
comment|/* The `FINALIZE_PIC' macro serves as a hook to emit these special    codes once the function is being compiled into assembly code, but    not before.  (It is not done before, because in the case of    compiling an inline function, it would lead to multiple PIC    prologues being included in functions which used inline functions    and were compiled to assembly language.)  */
end_comment

begin_define
define|#
directive|define
name|FINALIZE_PIC
define|\
value|do									\   {									\     extern int current_function_uses_pic_offset_table;			\ 									\     current_function_uses_pic_offset_table |= profile_flag | profile_block_flag; \   }									\ while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* If defined, a C expression whose value is nonzero if IDENTIFIER    with arguments ARGS is a valid machine specific attribute for DECL.    The attributes in ATTRIBUTES have previously been assigned to DECL.  */
end_comment

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
value|(i386_valid_decl_attribute_p (DECL, ATTRIBUTES, NAME, ARGS))
end_define

begin_comment
comment|/* If defined, a C expression whose value is nonzero if IDENTIFIER    with arguments ARGS is a valid machine specific attribute for TYPE.    The attributes in ATTRIBUTES have previously been assigned to TYPE.  */
end_comment

begin_define
define|#
directive|define
name|VALID_MACHINE_TYPE_ATTRIBUTE
parameter_list|(
name|TYPE
parameter_list|,
name|ATTRIBUTES
parameter_list|,
name|NAME
parameter_list|,
name|ARGS
parameter_list|)
define|\
value|(i386_valid_type_attribute_p (TYPE, ATTRIBUTES, NAME, ARGS))
end_define

begin_comment
comment|/* If defined, a C expression whose value is zero if the attributes on    TYPE1 and TYPE2 are incompatible, one if they are compatible, and    two if they are nearly compatible (which causes a warning to be    generated).  */
end_comment

begin_define
define|#
directive|define
name|COMP_TYPE_ATTRIBUTES
parameter_list|(
name|TYPE1
parameter_list|,
name|TYPE2
parameter_list|)
define|\
value|(i386_comp_type_attributes (TYPE1, TYPE2))
end_define

begin_comment
comment|/* If defined, a C statement that assigns default attributes to newly    defined TYPE.  */
end_comment

begin_comment
comment|/* #define SET_DEFAULT_TYPE_ATTRIBUTES (TYPE) */
end_comment

begin_comment
comment|/* Max number of args passed in registers.  If this is more than 3, we will    have problems with ebx (register #4), since it is a caller save register and    is also used as the pic register in ELF.  So for now, don't allow more than    3 registers to be passed in registers.  */
end_comment

begin_define
define|#
directive|define
name|REGPARM_MAX
value|3
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
value|Pmode
end_define

begin_comment
comment|/* Define as C expression which evaluates to nonzero if the tablejump    instruction expects the table to contain offsets from the address of the    table.    Do not define this if the table should contain absolute addresses. */
end_comment

begin_comment
comment|/* #define CASE_VECTOR_PC_RELATIVE 1 */
end_comment

begin_comment
comment|/* Specify the tree operation to be used to convert reals to integers.    This should be changed to take advantage of fist --wfs ??  */
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

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

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
comment|/* If a memory-to-memory move would take MOVE_RATIO or more simple    move-instruction pairs, we will do a movstr or libcall instead.    Increasing the value will always make code faster, but eventually    incurs high cost in increased code size.     If you don't define this, a reasonable default is used.     Make this large on i386, since the block move is very inefficient with small    blocks, and the hard register needs of the block move require much reload    work. */
end_comment

begin_define
define|#
directive|define
name|MOVE_RATIO
value|5
end_define

begin_comment
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.  */
end_comment

begin_comment
comment|/* On i386, shifts do truncate the count.  But bit opcodes don't. */
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
end_define

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
value|case CONST_INT:						\     return (unsigned) INTVAL (RTX)< 256 ? 0 : 1;		\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return flag_pic&& SYMBOLIC_CONST (RTX) ? 2 : 1;		\ 								\   case CONST_DOUBLE:						\     {								\       int code;							\       if (GET_MODE (RTX) == VOIDmode)				\ 	return 2;						\ 								\       code = standard_80387_constant_p (RTX);			\       return code == 1 ? 0 :					\ 	     code == 2 ? 1 :					\ 			 2;					\     }
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
value|{total = COSTS_N_INSNS (N); break;}
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
value|case ASHIFT:								\     if (GET_CODE (XEXP (X, 1)) == CONST_INT				\&& GET_MODE (XEXP (X, 0)) == SImode)				\       {									\ 	HOST_WIDE_INT value = INTVAL (XEXP (X, 1));			\ 									\ 	if (value == 1)							\ 	  return COSTS_N_INSNS (ix86_cost->add) 			\ 				+ rtx_cost(XEXP (X, 0), OUTER_CODE);	\ 									\ 	if (value == 2 || value == 3)					\ 	  return COSTS_N_INSNS (ix86_cost->lea)				\ 				 + rtx_cost(XEXP (X, 0), OUTER_CODE);	\       }									\
comment|/* fall through */
value|\ 		  							\   case ROTATE:								\   case ASHIFTRT:							\   case LSHIFTRT:							\   case ROTATERT:							\     if (GET_MODE (XEXP (X, 0)) == DImode)				\       {									\ 	if (GET_CODE (XEXP (X, 1)) == CONST_INT)			\ 	  {								\ 	    if (INTVAL (XEXP (X, 1))> 32)				\ 	      return COSTS_N_INSNS(ix86_cost->shift_const + 2);		\ 	    return COSTS_N_INSNS(ix86_cost->shift_const * 2);		\ 	  }								\ 	return ((GET_CODE (XEXP (X, 1)) == AND				\ 		 ? COSTS_N_INSNS(ix86_cost->shift_var * 2)		\ 		 : COSTS_N_INSNS(ix86_cost->shift_var * 6 + 2))		\ 		+ rtx_cost(XEXP (X, 0), OUTER_CODE));			\       }									\     return COSTS_N_INSNS (GET_CODE (XEXP (X, 1)) == CONST_INT		\ 			  ? ix86_cost->shift_const			\ 			  : ix86_cost->shift_var)			\       + rtx_cost(XEXP (X, 0), OUTER_CODE);				\ 									\   case MULT:								\     if (GET_CODE (XEXP (X, 1)) == CONST_INT)				\       {									\ 	unsigned HOST_WIDE_INT value = INTVAL (XEXP (X, 1));		\ 	int nbits = 0;							\ 									\ 	if (value == 2)							\ 	  return COSTS_N_INSNS (ix86_cost->add)				\ 				 + rtx_cost(XEXP (X, 0), OUTER_CODE);	\ 	if (value == 4 || value == 8)					\ 	  return COSTS_N_INSNS (ix86_cost->lea)				\ 				 + rtx_cost(XEXP (X, 0), OUTER_CODE);	\ 									\ 	while (value != 0)						\ 	  {								\ 	    nbits++;							\ 	    value>>= 1;						\ 	  } 								\ 									\ 	if (nbits == 1)							\ 	  return COSTS_N_INSNS (ix86_cost->shift_const)			\ 	    + rtx_cost(XEXP (X, 0), OUTER_CODE);			\ 									\ 	return COSTS_N_INSNS (ix86_cost->mult_init			\ 			      + nbits * ix86_cost->mult_bit)		\ 	  + rtx_cost(XEXP (X, 0), OUTER_CODE);				\       }									\ 									\     else
comment|/* This is arbitrary */
value|\       TOPLEVEL_COSTS_N_INSNS (ix86_cost->mult_init			\ 			      + 7 * ix86_cost->mult_bit);		\ 									\   case DIV:								\   case UDIV:								\   case MOD:								\   case UMOD:								\     TOPLEVEL_COSTS_N_INSNS (ix86_cost->divide);				\ 									\   case PLUS:								\     if (GET_CODE (XEXP (X, 0)) == REG					\&& GET_MODE (XEXP (X, 0)) == SImode				\&& GET_CODE (XEXP (X, 1)) == PLUS)				\       return COSTS_N_INSNS (ix86_cost->lea);				\ 									\
comment|/* fall through */
value|\   case AND:								\   case IOR:								\   case XOR:								\   case MINUS:								\     if (GET_MODE (X) == DImode)						\       return COSTS_N_INSNS (ix86_cost->add) * 2				\ 	+ (rtx_cost (XEXP (X, 0), OUTER_CODE)				\<< (GET_MODE (XEXP (X, 0)) != DImode))			\ 	+ (rtx_cost (XEXP (X, 1), OUTER_CODE)				\<< (GET_MODE (XEXP (X, 1)) != DImode));			\   case NEG:								\   case NOT:								\     if (GET_MODE (X) == DImode)						\       TOPLEVEL_COSTS_N_INSNS (ix86_cost->add * 2)			\     TOPLEVEL_COSTS_N_INSNS (ix86_cost->add)
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
value|((CONSTANT_P (RTX)						\     || (GET_CODE (RTX) == PLUS&& CONSTANT_P (XEXP (RTX, 1))	\&& REG_P (XEXP (RTX, 0)))) ? 0				\    : REG_P (RTX) ? 1						\    : 2)
end_define

begin_comment
comment|/* A C expression for the cost of moving data of mode M between a    register and memory.  A value of 2 is the default; this cost is    relative to those in `REGISTER_MOVE_COST'.     If moving between registers and memory is more expensive than    between two registers, you should define this macro to express the    relative cost.     On the i386, copying between floating-point and fixed-point    registers is expensive.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|)
define|\
value|(((FLOAT_CLASS_P (CLASS1)&& ! FLOAT_CLASS_P (CLASS2))		\     || (! FLOAT_CLASS_P (CLASS1)&& FLOAT_CLASS_P (CLASS2))) ? 10	\    : 2)
end_define

begin_comment
comment|/* A C expression for the cost of moving data of mode M between a    register and memory.  A value of 2 is the default; this cost is    relative to those in `REGISTER_MOVE_COST'.     If moving between registers and memory is more expensive than    between two registers, you should define this macro to express the    relative cost.  */
end_comment

begin_comment
comment|/* #define MEMORY_MOVE_COST(M,C,I) 2  */
end_comment

begin_comment
comment|/* A C expression for the cost of a branch instruction.  A value of 1    is the default; other values are interpreted relative to that.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
value|i386_branch_cost
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
comment|/* Define this macro if zero-extension (of a `char' or `short' to an    `int') can be done faster if the destination is a register that is    known to be zero.     If you define this macro, you must have instruction patterns that    recognize RTL structures like this:            (set (strict_low_part (subreg:QI (reg:SI ...) 0)) ...)     and likewise for `HImode'.  */
end_comment

begin_comment
comment|/* #define SLOW_ZERO_EXTEND */
end_comment

begin_comment
comment|/* Define this macro to be the value 1 if unaligned accesses have a    cost many times greater than aligned accesses, for example if they    are emulated in a trap handler.     When this macro is non-zero, the compiler will act as if    `STRICT_ALIGNMENT' were non-zero when generating code for block    moves.  This can cause significantly more instructions to be    produced.  Therefore, do not set this macro non-zero if unaligned    accesses only add a cycle or two to the time for a memory access.     If the value of this macro is always zero, it need not be defined.  */
end_comment

begin_comment
comment|/* #define SLOW_UNALIGNED_ACCESS 0 */
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

begin_comment
comment|/* A C statement (sans semicolon) to update the integer variable COST    based on the relationship between INSN that is dependent on    DEP_INSN through the dependence LINK.  The default is to make no    adjustment to COST.  This can be used for example to specify to    the scheduler that an output- or anti-dependence does not incur    the same cost as a data-dependence.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_COST
parameter_list|(
name|insn
parameter_list|,
name|link
parameter_list|,
name|dep_insn
parameter_list|,
name|cost
parameter_list|)
define|\
value|(cost) = x86_adjust_cost(insn, link, dep_insn, cost)
end_define

begin_define
define|#
directive|define
name|ADJUST_BLOCKAGE
parameter_list|(
name|last_insn
parameter_list|,
name|insn
parameter_list|,
name|blockage
parameter_list|)
define|\
value|{									\   if (is_fp_store (last_insn)&& is_fp_insn (insn)			\&& NEXT_INSN (last_insn)&& NEXT_INSN (NEXT_INSN (last_insn))	\&& NEXT_INSN (NEXT_INSN (NEXT_INSN (last_insn)))			\&& (GET_CODE (NEXT_INSN (last_insn)) == INSN)			\&& (GET_CODE (NEXT_INSN (NEXT_INSN (last_insn))) == JUMP_INSN)	\&& (GET_CODE (NEXT_INSN (NEXT_INSN (NEXT_INSN (last_insn)))) == NOTE) \&& (NOTE_LINE_NUMBER (NEXT_INSN (NEXT_INSN (NEXT_INSN (last_insn)))) \ 	  == NOTE_INSN_LOOP_END))					\     {									\       (blockage) = 3;							\     }									\ }
end_define

begin_define
define|#
directive|define
name|ISSUE_RATE
value|((int)ix86_cpu> (int)PROCESSOR_I486 ? 2 : 1)
end_define

begin_escape
end_escape

begin_comment
comment|/* Add any extra modes needed to represent the condition code.     For the i386, we need separate modes when floating-point equality    comparisons are being done.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
value|CCFPEQmode
end_define

begin_comment
comment|/* Define the names for the modes specified above.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_NAMES
value|"CCFPEQ"
end_define

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.     For floating-point equality comparisons, CCFPEQmode should be used.    VOIDmode should be used in all other cases.  */
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
value|(GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT			\&& ((OP) == EQ || (OP) == NE) ? CCFPEQmode : VOIDmode)
end_define

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
argument_list|(
operator|*
name|i386_compare_gen
argument_list|)
argument_list|()
decl_stmt|,
modifier|*
argument_list|(
operator|*
name|i386_compare_gen_eq
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  */
end_comment

begin_comment
comment|/* Set if the cc value was actually from the 80387 and    we are testing eax directly (i.e. no sahf) */
end_comment

begin_define
define|#
directive|define
name|CC_TEST_AX
value|020000
end_define

begin_comment
comment|/* Set if the cc value is actually in the 80387, so a floating point    conditional branch must be output.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_80387
value|04000
end_define

begin_comment
comment|/* Set if the CC value was stored in a nonstandard way, so that    the state of equality is indicated by zero in the carry bit.  */
end_comment

begin_define
define|#
directive|define
name|CC_Z_IN_NOT_C
value|010000
end_define

begin_comment
comment|/* Set if the CC value was actually from the 80387 and loaded directly    into the eflags instead of via eax/sahf.  */
end_comment

begin_define
define|#
directive|define
name|CC_FCOMI
value|040000
end_define

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
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
value|notice_update_cc((EXP))
end_define

begin_comment
comment|/* Output a signed jump insn.  Use template NORMAL ordinarily, or    FLOAT following a floating point comparison.    Use NO_OV following an arithmetic insn that set the cc's    before a test insn that was deleted.    NO_OV may be zero, meaning final should reinsert the test insn    because the jump cannot be handled properly without it.  */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_JUMP
parameter_list|(
name|NORMAL
parameter_list|,
name|FLOAT
parameter_list|,
name|NO_OV
parameter_list|)
define|\
value|{								\   if (cc_prev_status.flags& CC_IN_80387)			\     return FLOAT;						\   if (cc_prev_status.flags& CC_NO_OVERFLOW)			\     return NO_OV;						\   return NORMAL;						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output, to the extent    this does not vary between assemblers.  */
end_comment

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above). */
end_comment

begin_comment
comment|/* In order to refer to the first 8 regs as 32 bit regs prefix an "e"    For non floating point regs, the following are the HImode names.     For float regs, the stack top is sometimes referred to as "%st(0)"    instead of just "%st".  PRINT_REG handles this with the "y" code.  */
end_comment

begin_define
define|#
directive|define
name|HI_REGISTER_NAMES
define|\
value|{"ax","dx","cx","bx","si","di","bp","sp",          \  "st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)","" }
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
value|{ { "eax", 0 }, { "edx", 1 }, { "ecx", 2 }, { "ebx", 3 },	\   { "esi", 4 }, { "edi", 5 }, { "ebp", 6 }, { "esp", 7 },	\   { "al", 0 }, { "dl", 1 }, { "cl", 2 }, { "bl", 3 },		\   { "ah", 0 }, { "dh", 1 }, { "ch", 2 }, { "bh", 3 } }
end_define

begin_comment
comment|/* Note we are omitting these since currently I don't know how to get gcc to use these, since they want the same but different number as al, and ax. */
end_comment

begin_comment
comment|/* note the last four are not really qi_registers, but    the md will have to never output movb into one of them    only a movw .  There is no movb into the last four regs */
end_comment

begin_define
define|#
directive|define
name|QI_REGISTER_NAMES
define|\
value|{"al", "dl", "cl", "bl", "si", "di", "bp", "sp",}
end_define

begin_comment
comment|/* These parallel the array above, and can be used to access bits 8:15    of regs 0 through 3. */
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

begin_comment
comment|/* {0,2,1,3,6,7,4,5,12,13,14,15,16,17}  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|((n) == 0 ? 0 : \  (n) == 1 ? 2 : \  (n) == 2 ? 1 : \  (n) == 3 ? 3 : \  (n) == 4 ? 6 : \  (n) == 5 ? 7 : \  (n) == 6 ? 4 : \  (n) == 7 ? 5 : \  (n) + 4)
end_define

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
value|((COUNT) == 0								\    ? gen_rtx_MEM (Pmode, gen_rtx_PLUS (Pmode, arg_pointer_rtx, GEN_INT(-4)))\    : gen_rtx_MEM (Pmode, gen_rtx_PLUS (Pmode, (FRAME), GEN_INT(4))))
end_define

begin_comment
comment|/* PC is dbx register 8; let's use that column for RA. */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|8
end_define

begin_comment
comment|/* Before the prologue, the top of the frame is at 4(%esp).  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_FRAME_SP_OFFSET
value|4
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
value|(assemble_name (FILE, NAME), fputs (":\n", FILE))
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { long l[2];								\      REAL_VALUE_TO_TARGET_DOUBLE (VALUE, l);				\      fprintf (FILE, "%s 0x%lx,0x%lx\n", ASM_LONG, l[0], l[1]);		\    } while (0)
end_define

begin_comment
comment|/* This is how to output a `long double' extended real constant. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LONG_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LONG_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { long l[3];						\      REAL_VALUE_TO_TARGET_LONG_DOUBLE (VALUE, l);	\      fprintf (FILE, "%s 0x%lx,0x%lx,0x%lx\n", ASM_LONG, l[0], l[1], l[2]); \    } while (0)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

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
value|do { long l;						\      REAL_VALUE_TO_TARGET_SINGLE (VALUE, l);		\      fprintf ((FILE), "%s 0x%lx\n", ASM_LONG, l);	\    } while (0)
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
comment|/* This is how to output an assembler line defining an `int' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "%s ", ASM_LONG),		\   output_addr_const (FILE,(VALUE)),		\   putc('\n',FILE))
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

begin_comment
comment|/* is this supposed to do align too?? */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "%s ", ASM_SHORT),		\   output_addr_const (FILE,(VALUE)),		\   putc('\n',FILE))
end_define

begin_comment
comment|/* #define ASM_OUTPUT_SHORT(FILE,VALUE)  \ ( fprintf (FILE, "%s ", ASM_BYTE_OP),		\   output_addr_const (FILE,(VALUE)),		\   fputs (",", FILE),		      		\   output_addr_const (FILE,(VALUE)),		\   fputs (">> 8\n",FILE)) */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CHAR
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "%s ", ASM_BYTE_OP),		\   output_addr_const (FILE, (VALUE)),		\   putc ('\n', FILE))
end_define

begin_comment
comment|/* This is how to output an assembler line for a numeric constant byte.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_BYTE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf ((FILE), "%s 0x%x\n", ASM_BYTE_OP, (VALUE))
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
value|fprintf (FILE, "\tpushl %%e%s\n", reg_names[REGNO])
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
value|fprintf (FILE, "\tpopl %%e%s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.      */
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
value|fprintf (FILE, "%s %s%d\n", ASM_LONG, LPREFIX, VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    We don't use these on the 386 yet, because the ATT assembler can't do    forward reference the differences.    */
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
value|fprintf (FILE, "\t.word %s%d-%s%d\n",LPREFIX, VALUE,LPREFIX, REL)
end_define

begin_comment
comment|/* Define the parentheses used to group arithmetic operations    in assembler code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OPEN_PAREN
value|""
end_define

begin_define
define|#
directive|define
name|ASM_CLOSE_PAREN
value|""
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

begin_escape
end_escape

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    The CODE z takes the size of operand from the following digit, and    outputs b,w,or l respectively.     On the 80386, we use several such letters:    f -- float insn (print a CONST_DOUBLE as a float rather than in hex).    L,W,B,Q,S,T -- print the opcode suffix for specified size of operand.    R -- print the prefix for register names.    z -- print the opcode suffix for the size of the current operand.    * -- print a star (in certain assembler syntax)    P -- if PIC, print an @PLT suffix.    X -- don't print any sort of PIC '@' suffix for a symbol.    J -- print jump insn for arithmetic_comparison_operator.    s -- ??? something to do with double shifts.  not actually used, afaik.    C -- print a conditional move suffix corresponding to the op code.    c -- likewise, but reverse the condition.    F,f -- likewise, but for floating-point.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '*' || (CODE) == '_')
end_define

begin_comment
comment|/* Print the name of a register based on its machine mode and number.    If CODE is 'w', pretend the mode is HImode.    If CODE is 'b', pretend the mode is QImode.    If CODE is 'k', pretend the mode is SImode.    If CODE is 'h', pretend the reg is the `high' byte register.    If CODE is 'y', print "st(0)" instead of "st", if the reg is stack op. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hi_reg_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|qi_reg_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|qi_high_reg_name
index|[]
decl_stmt|;
end_decl_stmt

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
value|do { if (REGNO (X) == ARG_POINTER_REGNUM)		\ 	 abort ();					\        fprintf (FILE, "%s", RP);			\        switch ((CODE == 'w' ? 2 			\ 		: CODE == 'b' ? 1			\ 		: CODE == 'k' ? 4			\ 		: CODE == 'y' ? 3			\ 		: CODE == 'h' ? 0			\ 		: GET_MODE_SIZE (GET_MODE (X))))	\ 	 {						\ 	 case 3:					\ 	   if (STACK_TOP_P (X))				\ 	     {						\ 	       fputs ("st(0)", FILE);			\ 	       break;					\ 	     }						\ 	 case 4:					\ 	 case 8:					\ 	 case 12:					\ 	   if (! FP_REG_P (X)) fputs ("e", FILE);	\ 	 case 2:					\ 	   fputs (hi_reg_name[REGNO (X)], FILE);	\ 	   break;					\ 	 case 1:					\ 	   fputs (qi_reg_name[REGNO (X)], FILE);	\ 	   break;					\ 	 case 0:					\ 	   fputs (qi_high_reg_name[REGNO (X)], FILE);	\ 	   break;					\ 	 }						\      } while (0)
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
value|print_operand (FILE, X, CODE)
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
value|print_operand_address (FILE, ADDR)
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
value|do { static char *hi_name[] = HI_REGISTER_NAMES;	\        static char *qi_name[] = QI_REGISTER_NAMES;	\        fprintf (FILE, "%d %s", REGNO (X), RP);	\        if (REGNO (X) == ARG_POINTER_REGNUM)		\ 	 { fputs ("argp", FILE); break; }		\        if (STACK_TOP_P (X))				\ 	 { fputs ("st(0)", FILE); break; }		\        if (FP_REG_P (X))				\ 	 { fputs (hi_name[REGNO(X)], FILE); break; }	\        switch (GET_MODE_SIZE (GET_MODE (X)))		\ 	 {						\ 	 default:					\ 	   fputs ("e", FILE);				\ 	 case 2:					\ 	   fputs (hi_name[REGNO (X)], FILE);		\ 	   break;					\ 	 case 1:					\ 	   fputs (qi_name[REGNO (X)], FILE);		\ 	   break;					\ 	 }						\      } while (0)
end_define

begin_comment
comment|/* Output the prefix for an immediate operand, or for an offset operand.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_IMMED_PREFIX
parameter_list|(
name|FILE
parameter_list|)
value|fputs (IP, (FILE))
end_define

begin_define
define|#
directive|define
name|PRINT_OFFSET_PREFIX
parameter_list|(
name|FILE
parameter_list|)
value|fputs (IP, (FILE))
end_define

begin_comment
comment|/* Routines in libgcc that return floats must return them in an fp reg,    just as other functions do which return such values.    These macros make that happen.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_VALUE_TYPE
value|float
end_define

begin_define
define|#
directive|define
name|INTIFY
parameter_list|(
name|FLOATVAL
parameter_list|)
value|FLOATVAL
end_define

begin_comment
comment|/* Nonzero if INSN magically clobbers register REGNO.  */
end_comment

begin_comment
comment|/* #define INSN_CLOBBERS_REGNO_P(INSN, REGNO)	\     (FP_REGNO_P (REGNO)				\&& (GET_CODE (INSN) == JUMP_INSN || GET_CODE (INSN) == BARRIER)) */
end_comment

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
name|mode
parameter_list|)
value|(gen_rtx_MEM ((mode), stack_pointer_rtx))
end_define

begin_escape
end_escape

begin_comment
comment|/* Helper macros to expand a binary/unary operator if needed */
end_comment

begin_define
define|#
directive|define
name|IX86_EXPAND_BINARY_OPERATOR
parameter_list|(
name|OP
parameter_list|,
name|MODE
parameter_list|,
name|OPERANDS
parameter_list|)
define|\
value|do {									\   if (!ix86_expand_binary_operator (OP, MODE, OPERANDS))		\     FAIL;								\ } while (0)
end_define

begin_define
define|#
directive|define
name|IX86_EXPAND_UNARY_OPERATOR
parameter_list|(
name|OP
parameter_list|,
name|MODE
parameter_list|,
name|OPERANDS
parameter_list|)
define|\
value|do {									\   if (!ix86_expand_unary_operator (OP, MODE, OPERANDS,))		\     FAIL;								\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Functions in i386.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|override_options
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|order_regs_for_local_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_strlen_unroll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|i386_sext16_if_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_aligned_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_cc_probably_useless_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_valid_decl_attribute_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_valid_type_attribute_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_return_pops_args
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_comp_type_attributes
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
name|void
name|function_arg_advance
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
name|int
name|function_arg_partial_nregs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_strlen_unroll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|singlemove_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_move_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_move_pushmem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|standard_80387_constant_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_move_const_single
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbolic_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|call_insn_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|expander_call_insn_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbolic_reference_mentioned_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ix86_expand_binary_operator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ix86_binary_operator_ok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ix86_expand_unary_operator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ix86_unary_operator_ok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emit_pic_move
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
name|int
name|simple_386_epilogue
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
name|int
name|legitimate_address_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|legitimize_pic_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|legitimize_address
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
name|print_operand_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|notice_update_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|split_di
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|binary_387_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shift_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|VOIDmode_compare_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_387_binary_op
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_fix_trunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_float_extend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_float_compare
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_fp_cc0_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|save_386_machine_status
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restore_386_machine_status
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_386_stack_locals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|assign_386_stack_local
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_mul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_div
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|last_to_set_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|doesnt_set_condition_code
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sets_condition_code
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|str_immediate_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_fp_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_fp_dest
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_fp_store
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|agi_dependent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_mentioned_in_mem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_int_conditional_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_fp_conditional_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ix86_can_use_return_insn_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|small_shift_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_ashl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|memory_address_info
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOTYET
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|copy_all_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rewrite_address
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Variables in i386.c */
end_comment

begin_decl_stmt
specifier|extern
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
name|char
modifier|*
name|i386_reg_alloc_order
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register allocation order */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|i386_regparm_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # registers to use to pass args */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|i386_align_loops_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for loops */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|i386_align_jumps_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for non-loop jumps */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|i386_align_funcs_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for functions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|i386_preferred_stack_boundary_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for stack boundary */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|i386_branch_cost_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values 1-5: see jump.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i386_regparm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* i386_regparm_string as a number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i386_align_loops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for loops */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i386_align_jumps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for non-loop jumps */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i386_align_funcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* power of two alignment for functions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i386_preferred_stack_boundary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preferred stack boundary alignment in bits */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i386_branch_cost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values 1-5: see jump.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hi_reg_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names for 16 bit regs */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|qi_reg_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names for 8 bit regs (low) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|qi_high_reg_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names for 8 bit regs (high) */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|regclass_map
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* smalled class containing REGNO */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|i386_compare_op0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operand 0 for comparisons */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|i386_compare_op1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operand 1 for comparisons */
end_comment

begin_comment
comment|/* External variables used */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optimize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optimization level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|obey_regdecls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if stupid register allocation */
end_comment

begin_comment
comment|/* External functions used */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|force_operand
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

