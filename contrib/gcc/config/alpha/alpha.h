begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for DEC Alpha.    Copyright (C) 1992, 93-98, 1999 Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@vlsi1.ultra.nyu.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Write out the correct language type definition for the header files.      Unless we have assembler language, write out the symbols for C.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{!undef:\ %{.S:-D__LANGUAGE_ASSEMBLY__ -D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY }}\ %{.cc|.cxx|.C:-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS -D__cplusplus }\ %{.m:-D__LANGUAGE_OBJECTIVE_C__ -D__LANGUAGE_OBJECTIVE_C }\ %{!.S:%{!.cc:%{!.cxx:%{!.C:%{!.m:-D__LANGUAGE_C__ -D__LANGUAGE_C %{!ansi:-DLANGUAGE_C }}}}}}\ %{mieee:-D_IEEE_FP }\ %{mieee-with-inexact:-D_IEEE_FP -D_IEEE_FP_INEXACT }}\ %(cpp_cpu) %(cpp_subtarget)"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_SUBTARGET_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the spec to use for signed char.  The default tests the above macro    but DEC's compiler can't handle the conditional in a "constant"    operand.  */
end_comment

begin_define
define|#
directive|define
name|SIGNED_CHAR_SPEC
value|"%{funsigned-char:-D__CHAR_UNSIGNED__}"
end_define

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(!strcmp (STR, "rpath") || !strcmp (STR, "include")	\   || !strcmp (STR, "imacros") || !strcmp (STR, "aux-info") \   || !strcmp (STR, "idirafter") || !strcmp (STR, "iprefix") \   || !strcmp (STR, "iwithprefix") || !strcmp (STR, "iwithprefixbefore") \   || !strcmp (STR, "isystem"))
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_comment
comment|/* Which processor to schedule for. The cpu attribute defines a list that    mirrors this list, so changes to alpha.md must be made at the same time.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_EV4
block|,
comment|/* 2106[46]{a,} */
name|PROCESSOR_EV5
block|,
comment|/* 21164{a,pc,} */
name|PROCESSOR_EV6
block|}
enum|;
end_enum

begin_comment
comment|/* 21264 */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|alpha_cpu
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|alpha_trap_precision
block|{
name|ALPHA_TP_PROG
block|,
comment|/* No precision (default).  */
name|ALPHA_TP_FUNC
block|,
comment|/* Trap contained within originating function.  */
name|ALPHA_TP_INSN
comment|/* Instruction accuracy and code is resumption safe. */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|alpha_fp_rounding_mode
block|{
name|ALPHA_FPRM_NORM
block|,
comment|/* Normal rounding mode.  */
name|ALPHA_FPRM_MINF
block|,
comment|/* Round towards minus-infinity.  */
name|ALPHA_FPRM_CHOP
block|,
comment|/* Chopped rounding mode (towards 0). */
name|ALPHA_FPRM_DYN
comment|/* Dynamic rounding mode.  */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|alpha_fp_trap_mode
block|{
name|ALPHA_FPTM_N
block|,
comment|/* Normal trap mode. */
name|ALPHA_FPTM_U
block|,
comment|/* Underflow traps enabled.  */
name|ALPHA_FPTM_SU
block|,
comment|/* Software completion, w/underflow traps */
name|ALPHA_FPTM_SUI
comment|/* Software completion, w/underflow& inexact traps */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|alpha_trap_precision
name|alpha_tp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|alpha_fp_rounding_mode
name|alpha_fprm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|alpha_fp_trap_mode
name|alpha_fptm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This means that floating-point support exists in the target implementation    of the Alpha architecture.  This is usually the default.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TARGET_FP
value|(target_flags& MASK_FP)
end_define

begin_comment
comment|/* This means that floating-point registers are allowed to be used.  Note    that Alpha implementations without FP operations are required to    provide the FP registers.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FPREGS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TARGET_FPREGS
value|(target_flags& MASK_FPREGS)
end_define

begin_comment
comment|/* This means that gas is used to process the assembler file.  */
end_comment

begin_define
define|#
directive|define
name|MASK_GAS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TARGET_GAS
value|(target_flags& MASK_GAS)
end_define

begin_comment
comment|/* This means that we should mark procedures as IEEE conformant. */
end_comment

begin_define
define|#
directive|define
name|MASK_IEEE_CONFORMANT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TARGET_IEEE_CONFORMANT
value|(target_flags& MASK_IEEE_CONFORMANT)
end_define

begin_comment
comment|/* This means we should be IEEE-compliant except for inexact.  */
end_comment

begin_define
define|#
directive|define
name|MASK_IEEE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TARGET_IEEE
value|(target_flags& MASK_IEEE)
end_define

begin_comment
comment|/* This means we should be fully IEEE-compliant.  */
end_comment

begin_define
define|#
directive|define
name|MASK_IEEE_WITH_INEXACT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TARGET_IEEE_WITH_INEXACT
value|(target_flags& MASK_IEEE_WITH_INEXACT)
end_define

begin_comment
comment|/* This means we must construct all constants rather than emitting    them as literal data.  */
end_comment

begin_define
define|#
directive|define
name|MASK_BUILD_CONSTANTS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|TARGET_BUILD_CONSTANTS
value|(target_flags& MASK_BUILD_CONSTANTS)
end_define

begin_comment
comment|/* This means we handle floating points in VAX F- (float)    or G- (double) Format.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FLOAT_VAX
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|TARGET_FLOAT_VAX
value|(target_flags& MASK_FLOAT_VAX)
end_define

begin_comment
comment|/* This means that the processor has byte and half word loads and stores    (the BWX extension).  */
end_comment

begin_define
define|#
directive|define
name|MASK_BWX
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|TARGET_BWX
value|(target_flags& MASK_BWX)
end_define

begin_comment
comment|/* This means that the processor has the MAX extension.  */
end_comment

begin_define
define|#
directive|define
name|MASK_MAX
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|TARGET_MAX
value|(target_flags& MASK_MAX)
end_define

begin_comment
comment|/* This means that the processor has the FIX extension.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FIX
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|TARGET_FIX
value|(target_flags& MASK_FIX)
end_define

begin_comment
comment|/* This means that the processor has the CIX extension.  */
end_comment

begin_define
define|#
directive|define
name|MASK_CIX
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|TARGET_CIX
value|(target_flags& MASK_CIX)
end_define

begin_comment
comment|/* This means that the processor is an EV5, EV56, or PCA56.  This is defined    only in TARGET_CPU_DEFAULT.  */
end_comment

begin_define
define|#
directive|define
name|MASK_CPU_EV5
value|(1<< 28)
end_define

begin_comment
comment|/* Likewise for EV6.  */
end_comment

begin_define
define|#
directive|define
name|MASK_CPU_EV6
value|(1<< 29)
end_define

begin_comment
comment|/* This means we support the .arch directive in the assembler.  Only    defined in TARGET_CPU_DEFAULT.  */
end_comment

begin_define
define|#
directive|define
name|MASK_SUPPORT_ARCH
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|TARGET_SUPPORT_ARCH
value|(target_flags& MASK_SUPPORT_ARCH)
end_define

begin_comment
comment|/* These are for target os support and cannot be changed at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_WINDOWS_NT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_WINDOWS_NT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_OPEN_VMS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_OPEN_VMS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_AS_CAN_SUBTRACT_LABELS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_AS_CAN_SUBTRACT_LABELS
value|TARGET_GAS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_CAN_FAULT_IN_PROLOGUE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_CAN_FAULT_IN_PROLOGUE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"no-soft-float", MASK_FP, "Use hardware fp"},			\     {"soft-float", - MASK_FP, "Do not use hardware fp"},		\     {"fp-regs", MASK_FPREGS, "Use fp registers"},			\     {"no-fp-regs", - (MASK_FP|MASK_FPREGS), "Do not use fp registers"},	\     {"alpha-as", -MASK_GAS, "Do not assume GAS"},			\     {"gas", MASK_GAS, "Assume GAS"},					\     {"ieee-conformant", MASK_IEEE_CONFORMANT,				\      "Request IEEE-conformant math library routines (OSF/1)"},		\     {"ieee", MASK_IEEE|MASK_IEEE_CONFORMANT,				\      "Emit IEEE-conformant code, without inexact exceptions"},		\     {"ieee-with-inexact", MASK_IEEE_WITH_INEXACT|MASK_IEEE_CONFORMANT,	\      "Emit IEEE-conformant code, with inexact exceptions"},		\     {"build-constants", MASK_BUILD_CONSTANTS,				\      "Do not emit complex integer constants to read-only memory"},	\     {"float-vax", MASK_FLOAT_VAX, "Use VAX fp"},			\     {"float-ieee", -MASK_FLOAT_VAX, "Do not use VAX fp"},		\     {"bwx", MASK_BWX, "Emit code for the byte/word ISA extension"},	\     {"no-bwx", -MASK_BWX, ""},						\     {"max", MASK_MAX, "Emit code for the motion video ISA extension"},	\     {"no-max", -MASK_MAX, ""},						\     {"fix", MASK_FIX, "Emit code for the fp move and sqrt ISA extension"}, \     {"no-fix", -MASK_FIX, ""},						\     {"cix", MASK_CIX, "Emit code for the counting ISA extension"},	\     {"no-cix", -MASK_CIX, ""},						\     {"", TARGET_DEFAULT | TARGET_CPU_DEFAULT, ""} }
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|MASK_FP|MASK_FPREGS
end_define

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
comment|/* This macro is similar to `TARGET_SWITCHES' but defines names of    command options that have values.  Its definition is an initializer    with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the fixed    part of the option name, and the address of a variable.  The    variable, type `char *', is set to the variable part of the given    option if the fixed part matches.  The actual option name is made    by appending `-m' to the specified name.     Here is an example which defines `-mshort-data-NUMBER'.  If the    given option is `-mshort-data-512', the variable `m88k_short_data'    will be set to the string `"512"'.  	extern char *m88k_short_data; 	#define TARGET_OPTIONS { { "short-data-",&m88k_short_data } }  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|alpha_cpu_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For -mcpu= */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|alpha_fprm_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For -mfp-rounding-mode=[n|m|c|d] */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|alpha_fptm_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For -mfp-trap-mode=[n|u|su|sui]  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|alpha_tp_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For -mtrap-precision=[p|f|i] */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|alpha_mlat_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For -mmemory-latency= */
end_comment

begin_define
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{							\   {"cpu=",&alpha_cpu_string,		\    "Generate code for a given CPU"},			\   {"fp-rounding-mode=",&alpha_fprm_string,		\    "Control the generated fp rounding mode"},		\   {"fp-trap-mode=",&alpha_fptm_string,		\    "Control the IEEE trap mode"},			\   {"trap-precision=",&alpha_tp_string,		\    "Control the precision given to fp exceptions"},	\   {"memory-latency=",&alpha_mlat_string,		\    "Tune expected memory latency"},			\ }
end_define

begin_comment
comment|/* Attempt to describe CPU characteristics to the preprocessor.  */
end_comment

begin_comment
comment|/* Corresponding to amask... */
end_comment

begin_define
define|#
directive|define
name|CPP_AM_BWX_SPEC
value|"-D__alpha_bwx__ -Acpu(bwx)"
end_define

begin_define
define|#
directive|define
name|CPP_AM_MAX_SPEC
value|"-D__alpha_max__ -Acpu(max)"
end_define

begin_define
define|#
directive|define
name|CPP_AM_FIX_SPEC
value|"-D__alpha_fix__ -Acpu(fix)"
end_define

begin_define
define|#
directive|define
name|CPP_AM_CIX_SPEC
value|"-D__alpha_cix__ -Acpu(cix)"
end_define

begin_comment
comment|/* Corresponding to implver... */
end_comment

begin_define
define|#
directive|define
name|CPP_IM_EV4_SPEC
value|"-D__alpha_ev4__ -Acpu(ev4)"
end_define

begin_define
define|#
directive|define
name|CPP_IM_EV5_SPEC
value|"-D__alpha_ev5__ -Acpu(ev5)"
end_define

begin_define
define|#
directive|define
name|CPP_IM_EV6_SPEC
value|"-D__alpha_ev6__ -Acpu(ev6)"
end_define

begin_comment
comment|/* Common combinations.  */
end_comment

begin_define
define|#
directive|define
name|CPP_CPU_EV4_SPEC
value|"%(cpp_im_ev4)"
end_define

begin_define
define|#
directive|define
name|CPP_CPU_EV5_SPEC
value|"%(cpp_im_ev5)"
end_define

begin_define
define|#
directive|define
name|CPP_CPU_EV56_SPEC
value|"%(cpp_im_ev5) %(cpp_am_bwx)"
end_define

begin_define
define|#
directive|define
name|CPP_CPU_PCA56_SPEC
value|"%(cpp_im_ev5) %(cpp_am_bwx) %(cpp_am_max)"
end_define

begin_define
define|#
directive|define
name|CPP_CPU_EV6_SPEC
value|"%(cpp_im_ev6) %(cpp_am_bwx) %(cpp_am_max) %(cpp_am_fix)"
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
operator|&
name|MASK_CPU_EV6
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|CPP_CPU_EV6_SPEC
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|&
name|MASK_CPU_EV5
end_if

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|&
name|MASK_MAX
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|CPP_CPU_PCA56_SPEC
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|&
name|MASK_BWX
end_if

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|CPP_CPU_EV56_SPEC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|CPP_CPU_EV5_SPEC
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|CPP_CPU_DEFAULT_SPEC
value|CPP_CPU_EV4_SPEC
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
value|"\ %{!undef:-Acpu(alpha) -Amachine(alpha) -D__alpha -D__alpha__ \ %{mcpu=ev4|mcpu=21064:%(cpp_cpu_ev4) }\ %{mcpu=ev5|mcpu=21164:%(cpp_cpu_ev5) }\ %{mcpu=ev56|mcpu=21164a:%(cpp_cpu_ev56) }\ %{mcpu=pca56|mcpu=21164pc|mcpu=21164PC:%(cpp_cpu_pca56) }\ %{mcpu=ev6|mcpu=21264:%(cpp_cpu_ev6) }\ %{!mcpu*:%(cpp_cpu_default) }}"
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
value|{ "cpp_am_bwx", CPP_AM_BWX_SPEC },		\   { "cpp_am_max", CPP_AM_MAX_SPEC },		\   { "cpp_am_fix", CPP_AM_FIX_SPEC },		\   { "cpp_am_cix", CPP_AM_CIX_SPEC },		\   { "cpp_im_ev4", CPP_IM_EV4_SPEC },		\   { "cpp_im_ev5", CPP_IM_EV5_SPEC },		\   { "cpp_im_ev6", CPP_IM_EV6_SPEC },		\   { "cpp_cpu_ev4", CPP_CPU_EV4_SPEC },		\   { "cpp_cpu_ev5", CPP_CPU_EV5_SPEC },		\   { "cpp_cpu_ev56", CPP_CPU_EV56_SPEC },	\   { "cpp_cpu_pca56", CPP_CPU_PCA56_SPEC },	\   { "cpp_cpu_ev6", CPP_CPU_EV6_SPEC },		\   { "cpp_cpu_default", CPP_CPU_DEFAULT_SPEC },	\   { "cpp_cpu", CPP_CPU_SPEC },			\   { "cpp_subtarget", CPP_SUBTARGET_SPEC },	\   SUBTARGET_EXTRA_SPECS
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.     On the Alpha, it is used to translate target-option strings into    numeric values.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|override_options
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|override_options ()
end_define

begin_comment
comment|/* Define this macro to change register usage conditional on target flags.     On the Alpha, we use this to disable the floating-point registers when    they don't exist.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|if (! TARGET_FPREGS)			\     for (i = 32; i< 63; i++)		\       fixed_regs[i] = call_used_regs[i] = 1;
end_define

begin_comment
comment|/* Show we can debug even without a frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|CAN_DEBUG_WITHOUT_FP
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define to enable software floating point emulation. */
end_comment

begin_define
define|#
directive|define
name|REAL_ARITHMETIC
end_define

begin_comment
comment|/* The following #defines are used when compiling the routines in    libgcc1.c.  Since the Alpha calling conventions require single    precision floats to be passed in the floating-point registers    (rather than in the general registers) we have to build the    libgcc1.c routines in such a way that they know the actual types    of their formal arguments and the actual types of their return    values.  Otherwise, gcc will generate calls to the libgcc1.c    routines, passing arguments in the floating-point registers,    but the libgcc1.c routines will expect their arguments on the    stack (where the Alpha calling conventions require structs&    unions to be passed).  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_VALUE_TYPE
value|double
end_define

begin_define
define|#
directive|define
name|INTIFY
parameter_list|(
name|FLOATVAL
parameter_list|)
value|(FLOATVAL)
end_define

begin_define
define|#
directive|define
name|FLOATIFY
parameter_list|(
name|INTVAL
parameter_list|)
value|(INTVAL)
end_define

begin_define
define|#
directive|define
name|FLOAT_ARG_TYPE
value|double
end_define

begin_comment
comment|/* Define the size of `int'.  The default is the same as the word size.  */
end_comment

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Define the size of `long long'.  The default is the twice the word size.  */
end_comment

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* The two floating-point formats we support are S-floating, which is    4 bytes, and T-floating, which is 8 bytes.  `float' is S and `double'    and `long double' are T.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
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
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Define this macro if it is advisable to hold scalars in registers    in a wider mode than that declared by the program.  In such cases,     the value is constrained to be within the bounds of the declared    type, but kept valid in the wider mode.  The signedness of the    extension may differ from that of the type.     For Alpha, we always store objects in a full register.  32-bit objects    are always sign-extended, but smaller objects retain their signedness.  */
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
value|if (GET_MODE_CLASS (MODE) == MODE_INT		\&& GET_MODE_SIZE (MODE)< UNITS_PER_WORD)	\     {						\       if ((MODE) == SImode)			\ 	(UNSIGNEDP) = 0;			\       (MODE) = DImode;				\     }
end_define

begin_comment
comment|/* Define this if function arguments should also be promoted using the above    procedure.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_ARGS
end_define

begin_comment
comment|/* Likewise, if the function return value is promoted.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_RETURN
end_define

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.     There are no such instructions on the Alpha, but the documentation    is little endian.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.    This is false on the Alpha.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered.     For Alpha we can decide arbitrarily since there are no machine instructions    for them.  Might as well be consistent with bytes. */
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
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 68000, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|64
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|8
end_define

begin_comment
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|64
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|64
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|64
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|256
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|64
end_define

begin_comment
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* A bitfield declared as `int' forces `int' alignment for the struct.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Align loop starts for optimal branching.       ??? Kludge this and the next macro for the moment by not doing anything if    we don't optimize and also if we are writing ECOFF symbols to work around    a bug in DEC's assembler. */
end_comment

begin_define
define|#
directive|define
name|LOOP_ALIGN
parameter_list|(
name|LABEL
parameter_list|)
define|\
value|(optimize> 0&& write_symbols != SDB_DEBUG ? 4 : 0)
end_define

begin_comment
comment|/* This is how to align an instruction for optimal branching.  On    Alpha we'll get better performance by aligning on an octaword    boundary.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_ALIGN_AFTER_BARRIER
parameter_list|(
name|FILE
parameter_list|)
define|\
value|(optimize> 0&& write_symbols != SDB_DEBUG ? 4 : 0)
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* For atomic access to objects, must have at least 32-bit alignment    unless the machine has byte operations.  */
end_comment

begin_define
define|#
directive|define
name|MINIMUM_ATOMIC_ALIGNMENT
value|(TARGET_BWX ? 8 : 32)
end_define

begin_comment
comment|/* Align all constants and variables to at least a word boundary so    we can pick up pieces of them faster.  */
end_comment

begin_comment
comment|/* ??? Only if block-move stuff knows about different source/destination    alignment.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|CONSTANT_ALIGNMENT
parameter_list|(
name|EXP
parameter_list|,
name|ALIGN
parameter_list|)
value|MAX ((ALIGN), BITS_PER_WORD)
end_define

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|EXP
parameter_list|,
name|ALIGN
parameter_list|)
value|MAX ((ALIGN), BITS_PER_WORD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set this non-zero if move instructions will actually fail to work    when given unaligned data.     Since we get an error message when we do one, call them invalid.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* Set this non-zero if unaligned move instructions are extremely slow.     On the Alpha, they trap.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_UNALIGNED_ACCESS
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     We define all 32 integer registers, even though $31 is always zero,    and all 32 floating-point registers, even though $f31 is also    always zero.  We do not bother defining the FP status register and    there are no other registers.      Since $31 is always zero, we will use register number 31 as the    argument pointer.  It will never appear in the generated code    because we will always be eliminating it in favor of the stack    pointer or hardware frame pointer.     Likewise, we use $f31 for the frame pointer, which will always    be eliminated in favor of the hardware frame pointer or the    stack pointer.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|64
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, \   1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
end_define

begin_comment
comment|/* List the order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.     We allocate in the following order:    $f10-$f15		(nonsaved floating-point register)    $f22-$f30		(likewise)    $f21-$f16		(likewise, but input args)    $f0			(nonsaved, but return value)    $f1			(nonsaved, but immediate before saved)    $f2-$f9		(saved floating-point registers)    $1-$8		(nonsaved integer registers)    $22-$25		(likewise)    $28			(likewise)    $0			(likewise, but return value)    $21-$16		(likewise, but input args)    $27			(procedure value in OSF, nonsaved in NT)    $9-$14		(saved integer registers)    $26			(return PC)    $15			(frame pointer)    $29			(global pointer)    $30, $31, $f31	(stack pointer and always zero/ap& fp)  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{42, 43, 44, 45, 46, 47,		\    54, 55, 56, 57, 58, 59, 60, 61, 62,	\    53, 52, 51, 50, 49, 48,		\    32, 33,				\    34, 35, 36, 37, 38, 39, 40, 41,	\    1, 2, 3, 4, 5, 6, 7, 8,		\    22, 23, 24, 25,			\    28,					\    0,					\    21, 20, 19, 18, 17, 16,		\    27,					\    9, 10, 11, 12, 13, 14,		\    26,					\    15,					\    29,					\    30, 31, 63 }
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.  */
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
value|((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On Alpha, the integer registers can hold any mode.  The floating-point    registers can hold 32-bit and 64-bit integers as well, but not 16-bit    or 8-bit values.  */
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
value|((REGNO)>= 32&& (REGNO)<= 62 					\    ? GET_MODE_UNIT_SIZE (MODE) == 8 || GET_MODE_UNIT_SIZE (MODE) == 4	\    : 1)
end_define

begin_comment
comment|/* A C expression that is nonzero if a value of mode    MODE1 is accessible in mode MODE2 without copying.     This asymmetric test is true when MODE1 could be put    in an FP register but MODE2 could not.  */
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
value|(HARD_REGNO_MODE_OK (32, (MODE1))				\    ? HARD_REGNO_MODE_OK (32, (MODE2))				\    : 1)
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* Alpha pc isn't overloaded on a register that the compiler knows about.  */
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
value|30
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
value|15
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|0
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|31
end_define

begin_comment
comment|/* Base register for access to local variables of function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|63
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.      For the Alpha, this is based on an example; the calling sequence    doesn't seem to specify this.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|1
end_define

begin_comment
comment|/* Register in which address to store a structure value    arrives in the function.  On the Alpha, the address is passed    as a hidden argument.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|0
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
name|GENERAL_REGS
block|,
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

begin_comment
comment|/* Give names of register classes as strings for dump file.   */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{"NO_REGS", "GENERAL_REGS", "FLOAT_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{ {0, 0}, {~0, 0x80000000}, {0, 0x7fffffff}, {~0, ~0} }
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
define|\
value|((REGNO)>= 32&& (REGNO)<= 62 ? FLOAT_REGS : GENERAL_REGS)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|NO_REGS
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
value|((C) == 'f' ? FLOAT_REGS : NO_REGS)
end_define

begin_comment
comment|/* Define this macro to change register usage conditional on target flags.  */
end_comment

begin_comment
comment|/* #define CONDITIONAL_REGISTER_USAGE  */
end_comment

begin_comment
comment|/* The letters I, J, K, L, M, N, O, and P in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     For Alpha:    `I' is used for the range of constants most insns can contain.    `J' is the constant zero.    `K' is used for the constant in an LDA insn.    `L' is used for the constant in a LDAH insn.    `M' is used for the constants that can be AND'ed with using a ZAP insn.    `N' is used for complemented 8-bit constants.    `O' is used for negated 8-bit constants.    `P' is used for the constants 1, 2 and 3.  */
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
value|((C) == 'I' ? (unsigned HOST_WIDE_INT) (VALUE)< 0x100	\    : (C) == 'J' ? (VALUE) == 0					\    : (C) == 'K' ? (unsigned HOST_WIDE_INT) ((VALUE) + 0x8000)< 0x10000	\    : (C) == 'L' ? (((VALUE)& 0xffff) == 0			\&& (((VALUE))>> 31 == -1 || (VALUE)>> 31 == 0)) \    : (C) == 'M' ? zap_mask (VALUE)				\    : (C) == 'N' ? (unsigned HOST_WIDE_INT) (~ (VALUE))< 0x100	\    : (C) == 'O' ? (unsigned HOST_WIDE_INT) (- (VALUE))< 0x100	\    : (C) == 'P' ? (VALUE) == 1 || (VALUE) == 2 || (VALUE) == 3	\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating or large integer constants, and defining letters    G and H.   Here VALUE is the CONST_DOUBLE rtx itself.     For Alpha, `G' is the floating-point constant zero.  `H' is a CONST_DOUBLE    that is the operand of a ZAP insn.  */
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
value|((C) == 'G' ? (GET_MODE_CLASS (GET_MODE (VALUE)) == MODE_FLOAT	\&& (VALUE) == CONST0_RTX (GET_MODE (VALUE)))		\    : (C) == 'H' ? (GET_MODE (VALUE) == VOIDmode				\&& zap_mask (CONST_DOUBLE_LOW (VALUE))		\&& zap_mask (CONST_DOUBLE_HIGH (VALUE)))		\    : 0)
end_define

begin_comment
comment|/* Optional extra constraints for this machine.     For the Alpha, `Q' means that this is a memory operand but not a    reference to an unaligned location.     `R' is a SYMBOL_REF that has SYMBOL_REF_FLAG set or is the current    function.     'S' is a 6-bit constant (valid for a shift insn).  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT
parameter_list|(
name|OP
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'Q' ? normal_memory_operand (OP, VOIDmode)			\    : (C) == 'R' ? current_file_function_operand (OP, Pmode)		\    : (C) == 'S' ? (GET_CODE (OP) == CONST_INT				\&& (unsigned HOST_WIDE_INT) INTVAL (OP)< 64)	\    : 0)
end_define

begin_function_decl
specifier|extern
name|int
name|normal_memory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.     On the Alpha, all constants except zero go into a floating-point    register via memory.  */
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
value|(CONSTANT_P (X)&& (X) != const0_rtx&& (X) != CONST0_RTX (GET_MODE (X)) \    ? ((CLASS) == FLOAT_REGS || (CLASS) == NO_REGS ? NO_REGS : GENERAL_REGS)\    : (CLASS))
end_define

begin_comment
comment|/* Loading and storing HImode or QImode values to and from memory    usually requires a scratch register.  The exceptions are loading    QImode and HImode from an aligned address to a general register    unless byte instructions are permitted.    We also cannot load an unaligned address or a paradoxical SUBREG into an    FP register.   */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_INPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|IN
parameter_list|)
define|\
value|(((GET_CODE (IN) == MEM 						\    || (GET_CODE (IN) == REG&& REGNO (IN)>= FIRST_PSEUDO_REGISTER)	\    || (GET_CODE (IN) == SUBREG						\&& (GET_CODE (SUBREG_REG (IN)) == MEM				\ 	   || (GET_CODE (SUBREG_REG (IN)) == REG			\&& REGNO (SUBREG_REG (IN))>= FIRST_PSEUDO_REGISTER))))	\&& (((CLASS) == FLOAT_REGS						\&& ((MODE) == SImode || (MODE) == HImode || (MODE) == QImode))	\       || (((MODE) == QImode || (MODE) == HImode)			\&& ! TARGET_BWX&& ! aligned_memory_operand (IN, MODE))))	\  ? GENERAL_REGS								\  : ((CLASS) == FLOAT_REGS&& GET_CODE (IN) == MEM			\&& GET_CODE (XEXP (IN, 0)) == AND) ? GENERAL_REGS			\  : ((CLASS) == FLOAT_REGS&& GET_CODE (IN) == SUBREG			\&& (GET_MODE_SIZE (GET_MODE (IN))					\> GET_MODE_SIZE (GET_MODE (SUBREG_REG (IN))))) ? GENERAL_REGS	\  : NO_REGS)
end_define

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
value|(((GET_CODE (OUT) == MEM 						\    || (GET_CODE (OUT) == REG&& REGNO (OUT)>= FIRST_PSEUDO_REGISTER)	\    || (GET_CODE (OUT) == SUBREG						\&& (GET_CODE (SUBREG_REG (OUT)) == MEM				\ 	   || (GET_CODE (SUBREG_REG (OUT)) == REG			\&& REGNO (SUBREG_REG (OUT))>= FIRST_PSEUDO_REGISTER)))) \&& ((((MODE) == HImode || (MODE) == QImode)				\&& (! TARGET_BWX || (CLASS) == FLOAT_REGS))			\       || ((MODE) == SImode&& (CLASS) == FLOAT_REGS)))			\  ? GENERAL_REGS								\  : ((CLASS) == FLOAT_REGS&& GET_CODE (OUT) == MEM			\&& GET_CODE (XEXP (OUT, 0)) == AND) ? GENERAL_REGS			\  : ((CLASS) == FLOAT_REGS&& GET_CODE (OUT) == SUBREG			\&& (GET_MODE_SIZE (GET_MODE (OUT))					\> GET_MODE_SIZE (GET_MODE (SUBREG_REG (OUT))))) ? GENERAL_REGS	\  : NO_REGS)
end_define

begin_comment
comment|/* If we are copying between general and FP registers, we need a memory    location unless the FIX extension is available.  */
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
value|(! TARGET_FIX&& (CLASS1) != (CLASS2))
end_define

begin_comment
comment|/* Specify the mode to be used for memory when a secondary memory    location is needed.  If MODE is floating-point, use it.  Otherwise,    widen to a word like the default.  This is needed because we always    store integers in FP registers in quadword format.  This whole    area is very tricky! */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_MEMORY_NEEDED_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT ? (MODE)		\    : GET_MODE_SIZE (MODE)>= 4 ? (MODE)			\    : mode_for_size (BITS_PER_WORD, GET_MODE_CLASS (MODE), 0))
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
value|((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* If defined, gives a class of registers that cannot be used as the    operand of a SUBREG that changes the size of the object.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_CANNOT_CHANGE_SIZE
value|FLOAT_REGS
end_define

begin_comment
comment|/* Define the cost of moving between registers of various classes.  Moving    between FLOAT_REGS and anything else except float regs is expensive.     In fact, we make it quite expensive because we really don't want to    do these moves unless it is clearly worth it.  Optimizations may    reduce the impact of not being able to allocate a pseudo to a    hard register.  */
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
value|(((CLASS1) == FLOAT_REGS) == ((CLASS2) == FLOAT_REGS)	\    ? 2							\    : TARGET_FIX ? 3 : 4+2*alpha_memory_latency)
end_define

begin_comment
comment|/* A C expressions returning the cost of moving data of MODE from a register to    or from memory.     On the Alpha, bump this up a bit.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alpha_memory_latency
decl_stmt|;
end_decl_stmt

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
value|(2*alpha_memory_latency)
end_define

begin_comment
comment|/* Provide the cost of a branch.  Exact meaning under development.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
value|5
end_define

begin_comment
comment|/* Adjust the cost of dependencies.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_COST
parameter_list|(
name|INSN
parameter_list|,
name|LINK
parameter_list|,
name|DEP
parameter_list|,
name|COST
parameter_list|)
define|\
value|(COST) = alpha_adjust_cost (INSN, LINK, DEP, COST)
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
value|0
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On Alpha, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Define this to be nonzero if stack checking is built into the ABI.  */
end_comment

begin_define
define|#
directive|define
name|STACK_CHECK_BUILTIN
value|1
end_define

begin_comment
comment|/* Define this if the maximum size of all the outgoing args is to be    accumulated and pushed during the prologue.  The amount can be    found in the variable current_function_outgoing_args_size.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
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
comment|/* Definitions for register eliminations.     We have two registers that can be eliminated on the Alpha.  First, the    frame pointer register can often be eliminated in favor of the stack    pointer register.  Secondly, the argument pointer register can always be    eliminated; it is replaced with either the stack or frame pointer. */
end_comment

begin_comment
comment|/* This is an array of structures.  Each structure initializes one pair    of eliminable registers.  The "from" register number is given first,    followed by "to".  Eliminations of the same "from" register are listed    in order of preference.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ ARG_POINTER_REGNUM, STACK_POINTER_REGNUM},	     \  { ARG_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM},   \  { FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},	     \  { FRAME_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM}}
end_define

begin_comment
comment|/* Given FROM and TO register numbers, say whether this elimination is allowed.    Frame pointer elimination is automatically handled.     All eliminations are valid since the cases where FP can't be    eliminated are already handled.  */
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
value|1
end_define

begin_comment
comment|/* Round up to a multiple of 16 bytes.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_ROUND
parameter_list|(
name|X
parameter_list|)
value|(((X) + 15)& ~ 15)
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
value|{ if ((FROM) == FRAME_POINTER_REGNUM)					\     (OFFSET) = (ALPHA_ROUND (current_function_outgoing_args_size)	\ 		+ alpha_sa_size ());					\   else if ((FROM) == ARG_POINTER_REGNUM)				\     (OFFSET) = (ALPHA_ROUND (current_function_outgoing_args_size)	\ 		+ alpha_sa_size ()					\ 		+ (ALPHA_ROUND (get_frame_size ()			\ 			       + current_function_pretend_args_size)	\ 		   - current_function_pretend_args_size));		\ }
end_define

begin_comment
comment|/* Define this if stack space is still allocated for a parameter passed    in a register.  */
end_comment

begin_comment
comment|/* #define REG_PARM_STACK_SPACE */
end_comment

begin_comment
comment|/* Value is the number of bytes of arguments automatically    popped when returning from a subroutine call.    FUNDECL is the declaration node of the function (as a tree),    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.  */
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
value|0
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.     On Alpha the value is found in $0 for integer functions and    $f0 for floating-point functions.  */
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
value|gen_rtx_REG (((INTEGRAL_TYPE_P (VALTYPE)			\&& TYPE_PRECISION (VALTYPE)< BITS_PER_WORD)	\ 	        || POINTER_TYPE_P (VALTYPE))			\ 	       ? word_mode : TYPE_MODE (VALTYPE),		\ 	       ((TARGET_FPREGS					\&& (TREE_CODE (VALTYPE) == REAL_TYPE		\ 		     || TREE_CODE (VALTYPE) == COMPLEX_TYPE))	\ 	        ? 32 : 0))
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
value|gen_rtx_REG (MODE,						\ 	        (TARGET_FPREGS					\&& (GET_MODE_CLASS (MODE) == MODE_FLOAT	\ 		     || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT) \ 	         ? 32 : 0))
end_define

begin_comment
comment|/* The definition of this macro implies that there are cases where    a scalar value cannot be returned in registers.     For the Alpha, any structure or union type is returned in memory, as    are integers whose size is larger than 64 bits.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_MODE (TYPE) == BLKmode \    || (TREE_CODE (TYPE) == INTEGER_TYPE&& TYPE_PRECISION (TYPE)> 64))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == 0 || (N) == 1 || (N) == 32 || (N) == 33)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On Alpha, these are $16-$21 and $f16-$f21.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)>= 16&& (N)<= 21) || ((N)>= 16 + 32&& (N)<= 21 + 32))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On Alpha, this is a single integer, which is a number of words    of arguments scanned so far.    Thus 6 or more means all following args should go on the stack.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

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
value|(CUM) = 0
end_define

begin_comment
comment|/* Define intermediate macro to compute the size (in registers) of an argument    for the Alpha.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_ARG_SIZE
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|((MODE) != BLKmode							\  ? (GET_MODE_SIZE (MODE) + (UNITS_PER_WORD - 1)) / UNITS_PER_WORD 	\  : (int_size_in_bytes (TYPE) + (UNITS_PER_WORD - 1)) / UNITS_PER_WORD)
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
value|if (MUST_PASS_IN_STACK (MODE, TYPE))					\     (CUM) = 6;								\   else									\     (CUM) += ALPHA_ARG_SIZE (MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On Alpha the first 6 words of args are normally in registers    and the rest are pushed.  */
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
value|((CUM)< 6&& ! MUST_PASS_IN_STACK (MODE, TYPE)	\  ? gen_rtx(REG, (MODE),				\ 	   (CUM) + 16 + ((TARGET_FPREGS		\&& (GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT  \ 			      || GET_MODE_CLASS (MODE) == MODE_FLOAT)) \ 			 * 32))			\  : 0)
end_define

begin_comment
comment|/* Specify the padding direction of arguments.     On the Alpha, we must pad upwards in order to be able to pass args in    registers.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
value|upward
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
value|((CUM)< 6&& 6< (CUM) + ALPHA_ARG_SIZE (MODE, TYPE, NAMED)	\  ? 6 - (CUM) : 0)
end_define

begin_comment
comment|/* Perform any needed actions needed for a function that is receiving a    variable number of arguments.      CUM is as above.     MODE and TYPE are the mode and type of the current parameter.     PRETEND_SIZE is a variable that should be set to the amount of stack    that must be pushed by the prolog to pretend that our caller pushed    it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.      On the Alpha, we allocate space for all 12 arg registers, but only    push those that are remaining.     However, if NO registers need to be saved, don't allocate any space.    This is not only because we won't need the space, but because AP includes    the current_pretend_args_size and we don't want to mess up any    ap-relative addresses already made.     If we are not to use the floating-point registers, save the integer    registers where we would put the floating-point registers.  This is    not the most efficient way to implement varargs with just one register    class, but it isn't worth doing anything more efficient in this rare    case.  */
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
value|{ if ((CUM)< 6)							\     {									\       if (! (NO_RTL))							\ 	{								\ 	  move_block_from_reg						\ 	    (16 + CUM,							\ 	     gen_rtx (MEM, BLKmode,					\ 		      plus_constant (virtual_incoming_args_rtx,		\ 				     ((CUM) + 6)* UNITS_PER_WORD)),	\ 	     6 - (CUM), (6 - (CUM)) * UNITS_PER_WORD);			\ 	  move_block_from_reg						\ 	    (16 + (TARGET_FPREGS ? 32 : 0) + CUM,			\ 	     gen_rtx (MEM, BLKmode,					\ 		      plus_constant (virtual_incoming_args_rtx,		\ 				     (CUM) * UNITS_PER_WORD)),		\ 	     6 - (CUM), (6 - (CUM)) * UNITS_PER_WORD);			\ 	   emit_insn (gen_blockage ());					\ 	 }								\       PRETEND_SIZE = 12 * UNITS_PER_WORD;				\     }									\ }
end_define

begin_comment
comment|/* Try to output insns to set TARGET equal to the constant C if it can be    done in less than N insns.  Do all computations in MODE.  Returns the place    where the output has been placed if it can be done and the insns have been    emitted.  If it would take more than N insns, zero is returned and no    insns and emitted.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_emit_set_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_emit_set_long_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_emit_conditional_branch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_emit_conditional_move
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Generate necessary RTL for __builtin_saveregs().    ARGLIST is the argument list; see expr.c.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_builtin_saveregs
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_SAVEREGS
parameter_list|(
name|ARGLIST
parameter_list|)
value|alpha_builtin_saveregs (ARGLIST)
end_define

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_compare_op0
decl_stmt|,
modifier|*
name|alpha_compare_op1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|alpha_compare_fp_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the information needed to modify the epilogue for EH.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_eh_epilogue_sp_ofs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make (or fake) .linkage entry for function call.    IS_LOCAL is 0 if name is used in call, 1 if name is used in definition.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|alpha_need_linkage
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* This macro defines the start of an assembly comment.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|" #"
end_define

begin_comment
comment|/* This macro produces the initial definition of a function.  */
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
value|alpha_start_function(FILE,NAME,DECL);
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_start_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* This macro closes up a function definition for the assembler.  */
end_comment

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
value|alpha_end_function(FILE,NAME,DECL)
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_end_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* This macro notes the end of the prologue.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_END_PROLOGUE
parameter_list|(
name|FILE
parameter_list|)
value|output_end_prologue (FILE)
end_define

begin_function_decl
specifier|extern
name|void
name|output_end_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Output any profiling code before the prologue.  */
end_comment

begin_define
define|#
directive|define
name|PROFILE_BEFORE_PROLOGUE
value|1
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  Under OSF/1, profiling is enabled    by simply passing -pg to the assembler and linker.  */
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
end_define

begin_comment
comment|/* Output assembler code to FILE to initialize this source file's    basic block profiling info, if that has not already been done.    This assumes that __bb_init_func doesn't garble a1-a5. */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BLOCK_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|do {							\ 	ASM_OUTPUT_REG_PUSH (FILE, 16);				\ 	fputs ("\tlda $16,$PBX32\n", (FILE));			\ 	fputs ("\tldq $26,0($16)\n", (FILE));			\ 	fputs ("\tbne $26,1f\n", (FILE));			\ 	fputs ("\tlda $27,__bb_init_func\n", (FILE));		\ 	fputs ("\tjsr $26,($27),__bb_init_func\n", (FILE));	\ 	fputs ("\tldgp $29,0($26)\n", (FILE));			\ 	fputs ("1:\n", (FILE));					\ 	ASM_OUTPUT_REG_POP (FILE, 16);				\     } while (0);
end_define

begin_comment
comment|/* Output assembler code to FILE to increment the entry-count for    the BLOCKNO'th basic block in this source file.  */
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
value|do {							\ 	int blockn = (BLOCKNO);					\ 	fputs ("\tsubq $30,16,$30\n", (FILE));			\ 	fputs ("\tstq $26,0($30)\n", (FILE));			\ 	fputs ("\tstq $27,8($30)\n", (FILE));			\ 	fputs ("\tlda $26,$PBX34\n", (FILE));			\ 	fprintf ((FILE), "\tldq $27,%d($26)\n", 8*blockn);	\ 	fputs ("\taddq $27,1,$27\n", (FILE));			\ 	fprintf ((FILE), "\tstq $27,%d($26)\n", 8*blockn);	\ 	fputs ("\tldq $26,0($30)\n", (FILE));			\ 	fputs ("\tldq $27,8($30)\n", (FILE));			\ 	fputs ("\taddq $30,16,$30\n", (FILE));			\     } while (0)
end_define

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
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     The trampoline should set the static chain pointer to value placed    into the trampoline and should branch to the specified routine.      Note that $27 has been set to the address of the trampoline, so we can    use it for addressability of the two data items.  Trampolines are always    aligned to FUNCTION_BOUNDARY, which is 64 bits.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {						\   fprintf (FILE, "\tldq $1,24($27)\n");		\   fprintf (FILE, "\tldq $27,16($27)\n");	\   fprintf (FILE, "\tjmp $31,($27),0\n");	\   fprintf (FILE, "\tnop\n");			\   fprintf (FILE, "\t.quad 0,0\n");		\ } while (0)
end_define

begin_comment
comment|/* Section in which to place the trampoline.  On Alpha, instructions    may only be placed in a text segment.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SECTION
value|text_section
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|32
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
value|alpha_initialize_trampoline (TRAMP, FNADDR, CXT, 16, 24, 8)
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_initialize_trampoline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A C expression whose value is RTL representing the value of the return    address for the frame COUNT steps up from the current frame.    FRAMEADDR is the frame pointer of the COUNT frame, or the frame pointer of    the COUNT-1 frame if RETURN_ADDR_IN_PREVIOUS_FRAME is defined.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_RTX
value|alpha_return_addr
end_define

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|alpha_return_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Before the prologue, RA lives in $26. */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
value|gen_rtx_REG (Pmode, 26)
end_define

begin_comment
comment|/* Initialize data used by insn expanders.  This is called from insn_emit,    once for every function before code is generated.  */
end_comment

begin_define
define|#
directive|define
name|INIT_EXPANDERS
value|alpha_init_expanders ()
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_init_expanders
parameter_list|()
function_decl|;
end_function_decl

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
value|0
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32  \  || (REGNO) == 63 || reg_renumber[REGNO] == 63)
end_define

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
comment|/* Recognize any constant value that is a valid address.  For the Alpha,    there are only constants none since we want to use LDA to load any    symbolic addresses into registers.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT	\&& (unsigned HOST_WIDE_INT) (INTVAL (X) + 0x8000)< 0x10000)
end_define

begin_comment
comment|/* Include all constant integers and constant doubles, but not    floating-point, except for floating-point zero.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_MODE_CLASS (GET_MODE (X)) != MODE_FLOAT	\    || (X) == CONST0_RTX (GET_MODE (X)))
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Source files for reload pass need to be strict.    After reload, it makes no difference, since pseudo regs have    been eliminated by then.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index    or if it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg    or if it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)< 32 || REGNO (X) == 63 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_comment
comment|/* ??? Nonzero if X is the frame pointer, or some virtual register    that may eliminate to the frame pointer.  These will be allowed to    have offsets greater than 32K.  This is done because register    elimination offsets will change the hi/lo split, and if we split    before reload, we will require additional instructions.   */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FP_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X) == 31 || REGNO (X) == 63		\    || (REGNO (X)>= FIRST_PSEUDO_REGISTER	\&& REGNO (X)< LAST_VIRTUAL_REGISTER))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_BASE_P (REGNO (X))
end_define

begin_define
define|#
directive|define
name|REG_OK_FP_BASE_P
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.      For Alpha, we have either a constant address or the sum of a register    and a constant address, or just a register.  For DImode, any of those    forms can be surrounded with an AND that clear the low-order three bits;    this is an "unaligned" access.     First define the basic valid address.  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_SIMPLE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{									\   rtx tmp = (X);							\   if (GET_CODE (tmp) == SUBREG						\&& (GET_MODE_SIZE (GET_MODE (tmp))				\< GET_MODE_SIZE (GET_MODE (SUBREG_REG (tmp)))))		\     tmp = SUBREG_REG (tmp);						\   if (REG_P (tmp)&& REG_OK_FOR_BASE_P (tmp))				\     goto ADDR;								\   if (CONSTANT_ADDRESS_P (X))						\     goto ADDR;								\   if (GET_CODE (X) == PLUS)						\     {									\       tmp = XEXP (X, 0);						\       if (GET_CODE (tmp) == SUBREG					\&& (GET_MODE_SIZE (GET_MODE (tmp))				\< GET_MODE_SIZE (GET_MODE (SUBREG_REG (tmp)))))		\         tmp = SUBREG_REG (tmp);						\       if (REG_P (tmp))							\ 	{								\ 	  if (REG_OK_FP_BASE_P (tmp)					\&& GET_CODE (XEXP (X, 1)) == CONST_INT)			\ 	    goto ADDR;							\ 	  if (REG_OK_FOR_BASE_P (tmp)					\&& CONSTANT_ADDRESS_P (XEXP (X, 1)))			\ 	    goto ADDR;							\ 	}								\     }									\ }
end_define

begin_comment
comment|/* Now accept the simple address, or, for DImode only, an AND of a simple    address that turns off the low three bits.  */
end_comment

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
value|{ GO_IF_LEGITIMATE_SIMPLE_ADDRESS (MODE, X, ADDR); \   if ((MODE) == DImode				\&& GET_CODE (X) == AND			\&& GET_CODE (XEXP (X, 1)) == CONST_INT	\&& INTVAL (XEXP (X, 1)) == -8)		\     GO_IF_LEGITIMATE_SIMPLE_ADDRESS (MODE, XEXP (X, 0), ADDR); \ }
end_define

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.      For the Alpha, there are three cases we handle:     (1) If the address is (plus reg const_int) and the CONST_INT is not a        valid offset, compute the high part of the constant and add it to the        register.  Then our address is (plus temp low-part-const).    (2) If the address is (const (plus FOO const_int)), find the low-order        part of the CONST_INT.  Then load FOO plus any high-order part of the        CONST_INT into a register.  Our address is (plus reg low-part-const).        This is done to reduce the number of GOT entries.    (3) If we have a (plus reg const), emit the load as in (2), then add        the two registers, and finally generate (plus reg low-part-const) as        our address.  */
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
value|{ if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == REG	\&& GET_CODE (XEXP (X, 1)) == CONST_INT			\&& ! CONSTANT_ADDRESS_P (XEXP (X, 1)))			\     {								\       HOST_WIDE_INT val = INTVAL (XEXP (X, 1));			\       HOST_WIDE_INT lowpart = (val& 0xffff) - 2 * (val& 0x8000); \       HOST_WIDE_INT highpart = val - lowpart;			\       rtx high = GEN_INT (highpart);				\       rtx temp = expand_binop (Pmode, add_optab, XEXP (x, 0),	\ 			       high, NULL_RTX, 1, OPTAB_LIB_WIDEN); \ 								\       (X) = plus_constant (temp, lowpart);			\       goto WIN;							\     }								\   else if (GET_CODE (X) == CONST				\&& GET_CODE (XEXP (X, 0)) == PLUS			\&& GET_CODE (XEXP (XEXP (X, 0), 1)) == CONST_INT)	\     {								\       HOST_WIDE_INT val = INTVAL (XEXP (XEXP (X, 0), 1));	\       HOST_WIDE_INT lowpart = (val& 0xffff) - 2 * (val& 0x8000); \       HOST_WIDE_INT highpart = val - lowpart;			\       rtx high = XEXP (XEXP (X, 0), 0);				\ 								\       if (highpart)						\ 	high = plus_constant (high, highpart);			\ 								\       (X) = plus_constant (force_reg (Pmode, high), lowpart);	\       goto WIN;							\     }								\   else if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == REG \&& GET_CODE (XEXP (X, 1)) == CONST			\&& GET_CODE (XEXP (XEXP (X, 1), 0)) == PLUS		\&& GET_CODE (XEXP (XEXP (XEXP (X, 1), 0), 1)) == CONST_INT) \     {								\       HOST_WIDE_INT val = INTVAL (XEXP (XEXP (XEXP (X, 1), 0), 1)); \       HOST_WIDE_INT lowpart = (val& 0xffff) - 2 * (val& 0x8000); \       HOST_WIDE_INT highpart = val - lowpart;			\       rtx high = XEXP (XEXP (XEXP (X, 1), 0), 0);		\ 								\       if (highpart)						\ 	high = plus_constant (high, highpart);			\ 								\       high = expand_binop (Pmode, add_optab, XEXP (X, 0),	\ 			   force_reg (Pmode, high),		\ 			   high, 1, OPTAB_LIB_WIDEN);		\       (X) = plus_constant (high, lowpart);			\       goto WIN;							\     }								\ }
end_define

begin_comment
comment|/* Try a machine-dependent way of reloading an illegitimate address    operand.  If we find one, push the reload and jump to WIN.  This    macro is used in only one place: `find_reloads_address' in reload.c.     For the Alpha, we wish to handle large displacements off a base    register by splitting the addend across an ldah and the mem insn.    This cuts number of extra insns needed from 3 to 1.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMIZE_RELOAD_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|,
name|OPNUM
parameter_list|,
name|TYPE
parameter_list|,
name|IND_LEVELS
parameter_list|,
name|WIN
parameter_list|)
define|\
value|do {									\
comment|/* We must recognize output that we have already generated ourselves.  */
value|\   if (GET_CODE (X) == PLUS						\&& GET_CODE (XEXP (X, 0)) == PLUS					\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == REG			\&& GET_CODE (XEXP (XEXP (X, 0), 1)) == CONST_INT			\&& GET_CODE (XEXP (X, 1)) == CONST_INT)				\     {									\       push_reload (XEXP (X, 0), NULL_RTX,&XEXP (X, 0), NULL_PTR,	\ 		   BASE_REG_CLASS, GET_MODE (X), VOIDmode, 0, 0,	\ 		   OPNUM, TYPE);					\       goto WIN;								\     }									\   if (GET_CODE (X) == PLUS						\&& GET_CODE (XEXP (X, 0)) == REG					\&& REGNO (XEXP (X, 0))< FIRST_PSEUDO_REGISTER			\&& REG_MODE_OK_FOR_BASE_P (XEXP (X, 0), MODE)			\&& GET_CODE (XEXP (X, 1)) == CONST_INT)				\     {									\       HOST_WIDE_INT val = INTVAL (XEXP (X, 1));				\       HOST_WIDE_INT low = ((val& 0xffff) ^ 0x8000) - 0x8000;		\       HOST_WIDE_INT high						\ 	= (((val - low)& 0xffffffff) ^ 0x80000000) - 0x80000000;	\ 									\
comment|/* Check for 32-bit overflow.  */
value|\       if (high + low != val)						\ 	break;								\ 									\
comment|/* Reload the high part into a base reg; leave the low part	\ 	 in the mem directly.  */
value|\ 									\       X = gen_rtx_PLUS (GET_MODE (X),					\ 			gen_rtx_PLUS (GET_MODE (X), XEXP (X, 0),	\ 				      GEN_INT (high)),			\ 			GEN_INT (low));					\ 	  								\       push_reload (XEXP (X, 0), NULL_RTX,&XEXP (X, 0), NULL_PTR,	\ 		   BASE_REG_CLASS, GET_MODE (X), VOIDmode, 0, 0,	\ 		   OPNUM, TYPE);					\       goto WIN;								\     }									\ } while (0)
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the Alpha this is true only for the unaligned modes.   We can    simplify this test since we know that the address must be valid.  */
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
value|{ if (GET_CODE (ADDR) == AND) goto LABEL; }
end_define

begin_comment
comment|/* Compute the cost of an address.  For the Alpha, all valid addresses are    the same cost.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_comment
comment|/* Machine-dependent reorg pass.   */
end_comment

begin_define
define|#
directive|define
name|MACHINE_DEPENDENT_REORG
parameter_list|(
name|X
parameter_list|)
value|alpha_reorg(X)
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
comment|/* Define as C expression which evaluates to nonzero if the tablejump    instruction expects the table to contain offsets from the address of the    table.     Do not define this if the table should contain absolute addresses.    On the Alpha, the table is really GP-relative, not relative to the PC    of the table, but we pretend that it is PC-relative; this should be OK,    but we should try to find some better way sometime.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_PC_RELATIVE
value|1
end_define

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

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* This flag, if defined, says the same insns that convert to a signed fixnum    also convert validly to an unsigned one.     We actually lie a bit here as overflow conditions are different.  But    they aren't being checked anyway.  */
end_comment

begin_define
define|#
directive|define
name|FIXUNS_TRUNC_LIKE_FIX_TRUNC
end_define

begin_comment
comment|/* Max number of bytes we can move to or from memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|8
end_define

begin_comment
comment|/* If a memory-to-memory move would take MOVE_RATIO or more simple    move-instruction pairs, we will do a movstr or libcall instead.     Without byte/word accesses, we want no more than four instructions;    with, several single byte accesses are better.   */
end_comment

begin_define
define|#
directive|define
name|MOVE_RATIO
value|(TARGET_BWX ? 7 : 2)
end_define

begin_comment
comment|/* Largest number of bytes of an object that can be placed in a register.    On the Alpha we have plenty of registers, so use TImode.  */
end_comment

begin_define
define|#
directive|define
name|MAX_FIXED_MODE_SIZE
value|GET_MODE_BITSIZE (TImode)
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is no faster than for words.    Also non-zero if doing byte operations (specifically shifts) in registers    is undesirable.      On the Alpha, we want to not use the byte operation and instead use    masking operations to access fields; these will save instructions.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|1
end_define

begin_comment
comment|/* Define if operations between registers always perform the operation    on the full register even if a narrower mode is specified.  */
end_comment

begin_define
define|#
directive|define
name|WORD_REGISTER_OPERATIONS
end_define

begin_comment
comment|/* Define if loading in MODE, an integral mode narrower than BITS_PER_WORD    will either zero-extend or sign-extend.  The value of this macro should    be the code that says which one of the two operations is implicitly    done, NIL if none.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_EXTEND_OP
parameter_list|(
name|MODE
parameter_list|)
value|((MODE) == SImode ? SIGN_EXTEND : ZERO_EXTEND)
end_define

begin_comment
comment|/* Define if loading short immediate values into registers sign extends.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_IMMEDIATES_SIGN_EXTEND
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
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_comment
comment|/* Define the value returned by a floating-point comparison instruction.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_STORE_FLAG_VALUE
value|(TARGET_FLOAT_VAX ? 0.5 : 2.0)
end_define

begin_comment
comment|/* Canonicalize a comparison from one we don't have to one we do have.  */
end_comment

begin_define
define|#
directive|define
name|CANONICALIZE_COMPARISON
parameter_list|(
name|CODE
parameter_list|,
name|OP0
parameter_list|,
name|OP1
parameter_list|)
define|\
value|do {									\     if (((CODE) == GE || (CODE) == GT || (CODE) == GEU || (CODE) == GTU) \&& (GET_CODE (OP1) == REG || (OP1) == const0_rtx))		\       {									\ 	rtx tem = (OP0);						\ 	(OP0) = (OP1);							\ 	(OP1) = tem;							\ 	(CODE) = swap_condition (CODE);					\       }									\     if (((CODE) == LT || (CODE) == LTU)					\&& GET_CODE (OP1) == CONST_INT&& INTVAL (OP1) == 256)		\       {									\ 	(CODE) = (CODE) == LT ? LE : LEU;				\ 	(OP1) = GEN_INT (255);						\       }									\   } while (0)
end_define

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|DImode
end_define

begin_comment
comment|/* Mode of a function address in a call instruction (for indexing purposes). */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|Pmode
end_define

begin_comment
comment|/* Define this if addresses of constant functions    shouldn't be put through pseudo regs where they can be cse'd.    Desirable on machines where ordinary constants are expensive    but a CALL with constant address is cheap.     We define this on the Alpha so that gen_call and gen_call_value    get to see the SYMBOL_REF (for the hint field of the jsr).  It will    then copy it into a register, thus actually letting the address be    cse'ed.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* Define this to be nonzero if shift instructions ignore all but the low-order    few bits. */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
value|1
end_define

begin_comment
comment|/* Use atexit for static constructors/destructors, instead of defining    our own exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* The EV4 is dual issue; EV5/EV6 are quad issue.  */
end_comment

begin_define
define|#
directive|define
name|ISSUE_RATE
value|(alpha_cpu == PROCESSOR_EV4 ? 2 : 4)
end_define

begin_comment
comment|/* Describe the fact that MULTI instructions are multiple instructions    and so to assume they don't pair with anything.  */
end_comment

begin_define
define|#
directive|define
name|MD_SCHED_VARIABLE_ISSUE
parameter_list|(
name|DUMP
parameter_list|,
name|SCHED_VERBOSE
parameter_list|,
name|INSN
parameter_list|,
name|CAN_ISSUE_MORE
parameter_list|)
define|\
value|if (recog_memoized (INSN)< 0 || get_attr_type (INSN) == TYPE_MULTI)	   \      (CAN_ISSUE_MORE) = 0
end_define

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX    whose rtx-code is CODE.  The body of this macro is a portion    of a switch statement.  If the code is computed here,    return it with a return statement.  Otherwise, break from the switch.     If this is an 8-bit constant, return zero since it can be used    nearly anywhere with no cost.  If it is a valid operand for an    ADD or AND, likewise return 0 if we know it will be used in that    context.  Otherwise, return 2 since it might be used there later.    All other constants take at least two insns.  */
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
value|case CONST_INT:						\     if (INTVAL (RTX)>= 0&& INTVAL (RTX)< 256)		\       return 0;							\   case CONST_DOUBLE:						\     if ((RTX) == CONST0_RTX (GET_MODE (RTX)))			\       return 0;							\     else if (((OUTER_CODE) == PLUS&& add_operand (RTX, VOIDmode)) \ 	|| ((OUTER_CODE) == AND&& and_operand (RTX, VOIDmode))) \       return 0;							\     else if (add_operand (RTX, VOIDmode) || and_operand (RTX, VOIDmode)) \       return 2;							\     else							\       return COSTS_N_INSNS (2);					\   case CONST:							\   case SYMBOL_REF:						\   case LABEL_REF:						\   switch (alpha_cpu)						\     {								\     case PROCESSOR_EV4:						\       return COSTS_N_INSNS (3);					\     case PROCESSOR_EV5:						\     case PROCESSOR_EV6:						\       return COSTS_N_INSNS (2);					\     default: abort();						\     }
end_define

begin_comment
comment|/* Provide the costs of a rtl expression.  This is in the body of a    switch on CODE.  */
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
value|case PLUS:  case MINUS:				\     if (FLOAT_MODE_P (GET_MODE (X)))			\       switch (alpha_cpu)				\         {						\         case PROCESSOR_EV4:				\           return COSTS_N_INSNS (6);			\         case PROCESSOR_EV5:				\         case PROCESSOR_EV6:				\           return COSTS_N_INSNS (4); 			\ 	default: abort();				\ 	}						\     else if (GET_CODE (XEXP (X, 0)) == MULT		\&& const48_operand (XEXP (XEXP (X, 0), 1), VOIDmode)) \       return (2 + rtx_cost (XEXP (XEXP (X, 0), 0), OUTER_CODE)	\ 	      + rtx_cost (XEXP (X, 1), OUTER_CODE));	\     break;						\   case MULT:						\     switch (alpha_cpu)					\       {							\       case PROCESSOR_EV4:				\         if (FLOAT_MODE_P (GET_MODE (X)))		\           return COSTS_N_INSNS (6);			\         return COSTS_N_INSNS (23);			\       case PROCESSOR_EV5:				\         if (FLOAT_MODE_P (GET_MODE (X)))		\           return COSTS_N_INSNS (4);			\         else if (GET_MODE (X) == DImode)		\           return COSTS_N_INSNS (12);			\         else						\           return COSTS_N_INSNS (8);			\       case PROCESSOR_EV6:				\ 	if (FLOAT_MODE_P (GET_MODE (X)))		\ 	  return COSTS_N_INSNS (4);			\ 	else 						\ 	  return COSTS_N_INSNS (7);			\       default: abort();					\       }							\   case ASHIFT:						\     if (GET_CODE (XEXP (X, 1)) == CONST_INT		\&& INTVAL (XEXP (X, 1))<= 3)			\       break;						\
comment|/* ... fall through ... */
value|\   case ASHIFTRT:  case LSHIFTRT:			\     switch (alpha_cpu)					\       {							\       case PROCESSOR_EV4:				\         return COSTS_N_INSNS (2);			\       case PROCESSOR_EV5:				\       case PROCESSOR_EV6:				\         return COSTS_N_INSNS (1); 			\       default: abort();					\       }							\   case IF_THEN_ELSE:					\     switch (alpha_cpu)					\       {							\       case PROCESSOR_EV4:				\       case PROCESSOR_EV6:				\         return COSTS_N_INSNS (2);			\       case PROCESSOR_EV5:				\         return COSTS_N_INSNS (1); 			\       default: abort();					\       }							\   case DIV:  case UDIV:  case MOD:  case UMOD:		\     switch (alpha_cpu)					\       {							\       case PROCESSOR_EV4:				\         if (GET_MODE (X) == SFmode)			\           return COSTS_N_INSNS (34);			\         else if (GET_MODE (X) == DFmode)		\           return COSTS_N_INSNS (63);			\         else						\           return COSTS_N_INSNS (70);			\       case PROCESSOR_EV5:				\         if (GET_MODE (X) == SFmode)			\           return COSTS_N_INSNS (15);			\         else if (GET_MODE (X) == DFmode)		\           return COSTS_N_INSNS (22);			\         else						\           return COSTS_N_INSNS (70);
comment|/* ??? */
value|\       case PROCESSOR_EV6:				\ 	if (GET_MODE (X) == SFmode)			\ 	  return COSTS_N_INSNS (12);			\         else if (GET_MODE (X) == DFmode)		\           return COSTS_N_INSNS (15);			\         else						\           return COSTS_N_INSNS (70);
comment|/* ??? */
value|\       default: abort();					\       }							\   case MEM:						\     switch (alpha_cpu)					\       {							\       case PROCESSOR_EV4:				\       case PROCESSOR_EV6:				\         return COSTS_N_INSNS (3);			\       case PROCESSOR_EV5:				\         return COSTS_N_INSNS (2); 			\       default: abort();					\       }							\   case NEG:  case ABS:					\     if (! FLOAT_MODE_P (GET_MODE (X)))			\       break;						\
comment|/* ... fall through ... */
value|\   case FLOAT:  case UNSIGNED_FLOAT:  case FIX:  case UNSIGNED_FIX: \   case FLOAT_EXTEND:  case FLOAT_TRUNCATE:		\     switch (alpha_cpu)					\       {							\       case PROCESSOR_EV4:				\         return COSTS_N_INSNS (6);			\       case PROCESSOR_EV5:				\       case PROCESSOR_EV6:				\         return COSTS_N_INSNS (4); 			\       default: abort();					\       }
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* We don't emit these labels, so as to avoid getting linker errors about    missing exception handling info.  If we emit a gcc_compiled. label into    text, and the file has no code, then the DEC assembler gives us a zero    sized text section with no associated exception handling info.  The    DEC linker sees this text section, and gives a warning saying that    the exception handling info is missing.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASM_IDENTIFY_LANGUAGE
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|".rdata"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* Define an extra section for read-only data, a routine to enter it, and    indicate that it is for read-only data.     The first time we enter the readonly data section for a file, we write    eight bytes of zero.  This works around a bug in DEC's assembler in    some versions of OSF/1 V3.x.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|readonly_data
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|void								\ literal_section ()						\ {								\   if (in_section != readonly_data)				\     {								\       static int firsttime = 1;				        \ 								\       fprintf (asm_out_file, "%s\n", READONLY_DATA_SECTION_ASM_OP); \       if (firsttime)						\ 	{							\ 	  firsttime = 0;				        \ 	  ASM_OUTPUT_DOUBLE_INT (asm_out_file, const0_rtx);	\ 	}							\ 								\       in_section = readonly_data;				\     }								\ }								\  #define READONLY_DATA_SECTION	literal_section
end_define

begin_comment
comment|/* If we are referencing a function that is static, make the SYMBOL_REF    special.  We use this to see indicate we can branch to this function    without setting PV or restoring GP.  */
end_comment

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|if (TREE_CODE (DECL) == FUNCTION_DECL&& ! TREE_PUBLIC (DECL)) \     SYMBOL_REF_FLAG (XEXP (DECL_RTL (DECL), 0)) = 1;
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"$0", "$1", "$2", "$3", "$4", "$5", "$6", "$7", "$8",		\  "$9", "$10", "$11", "$12", "$13", "$14", "$15",		\  "$16", "$17", "$18", "$19", "$20", "$21", "$22", "$23",	\  "$24", "$25", "$26", "$27", "$28", "$29", "$30", "AP",		\  "$f0", "$f1", "$f2", "$f3", "$f4", "$f5", "$f6", "$f7", "$f8",	\  "$f9", "$f10", "$f11", "$f12", "$f13", "$f14", "$f15",		\  "$f16", "$f17", "$f18", "$f19", "$f20", "$f21", "$f22", "$f23",\  "$f24", "$f25", "$f26", "$f27", "$f28", "$f29", "$f30", "FP"}
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
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
value|do { assemble_name (FILE, NAME); fputs (":\n", FILE); } while (0)
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.globl ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols. */
end_comment

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, "$%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output a label for a jump table.  Arguments are the same as    for ASM_OUTPUT_INTERNAL_LABEL, except the insn for the jump table is    passed. */
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
value|{ ASM_OUTPUT_ALIGN (FILE, 2); ASM_OUTPUT_INTERNAL_LABEL (FILE, PREFIX, NUM); }
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
value|sprintf ((LABEL), "*$%s%ld", (PREFIX), (long)(NUM))
end_define

begin_comment
comment|/* Check a floating-point value for validity for a particular machine mode.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_FLOAT_VALUE
parameter_list|(
name|MODE
parameter_list|,
name|D
parameter_list|,
name|OVERFLOW
parameter_list|)
define|\
value|((OVERFLOW) = check_float_value (MODE,&D, OVERFLOW))
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
value|{									\     if (REAL_VALUE_ISINF (VALUE)					\         || REAL_VALUE_ISNAN (VALUE)					\ 	|| REAL_VALUE_MINUS_ZERO (VALUE))				\       {									\ 	long t[2];							\ 	REAL_VALUE_TO_TARGET_DOUBLE ((VALUE), t);			\ 	fprintf (FILE, "\t.quad 0x%lx%08lx\n",				\ 		t[1]& 0xffffffff, t[0]& 0xffffffff);			\       }									\     else								\       {									\ 	char str[30];							\ 	REAL_VALUE_TO_DECIMAL (VALUE, "%.20e", str);			\ 	fprintf (FILE, "\t.%c_floating %s\n", (TARGET_FLOAT_VAX)?'g':'t', str);			\       }									\   }
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
value|do {								\     long t;							\     REAL_VALUE_TO_TARGET_SINGLE ((VALUE), t);			\     fprintf (FILE, "\t.long 0x%lx\n", t& 0xffffffff);		\ } while (0)
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
value|( fprintf (FILE, "\t.long "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `long' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE_INT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.quad "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
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
value|fprintf (FILE, "\t.word %d\n",		\     (int)(GET_CODE (VALUE) == CONST_INT		\      ? INTVAL (VALUE)& 0xffff : (abort (), 0)))
end_define

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
value|fprintf (FILE, "\t.byte %d\n",		\     (int)(GET_CODE (VALUE) == CONST_INT		\      ? INTVAL (VALUE)& 0xff : (abort (), 0)))
end_define

begin_comment
comment|/* We use the default ASCII-output routine, except that we don't write more    than 50 characters since the assembler doesn't support very long lines.  */
end_comment

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
value|do {									      \     FILE *_hide_asm_out_file = (MYFILE);				      \     unsigned char *_hide_p = (unsigned char *) (MYSTRING);		      \     int _hide_thissize = (MYLENGTH);					      \     int _size_so_far = 0;						      \     {									      \       FILE *asm_out_file = _hide_asm_out_file;				      \       unsigned char *p = _hide_p;					      \       int thissize = _hide_thissize;					      \       int i;								      \       fprintf (asm_out_file, "\t.ascii \"");				      \ 									      \       for (i = 0; i< thissize; i++)					      \ 	{								      \ 	  register int c = p[i];					      \ 									      \ 	  if (_size_so_far ++> 50&& i< thissize - 4)			      \ 	    _size_so_far = 0, fprintf (asm_out_file, "\"\n\t.ascii \"");      \ 									      \ 	  if (c == '\"' || c == '\\')					      \ 	    putc ('\\', asm_out_file);					      \ 	  if (c>= ' '&& c< 0177)					      \ 	    putc (c, asm_out_file);					      \ 	  else								      \ 	    {								      \ 	      fprintf (asm_out_file, "\\%o", c);			      \
comment|/* After an octal-escape, if a digit follows,		      \ 		 terminate one string constant and start another.	      \ 		 The Vax assembler fails to stop reading the escape	      \ 		 after three digits, so this is the only way we		      \ 		 can get it to parse the data properly.  */
value|\ 	      if (i< thissize - 1					      \&& p[i + 1]>= '0'&& p[i + 1]<= '9')		      \ 		_size_so_far = 0, fprintf (asm_out_file, "\"\n\t.ascii \"");  \ 	  }								      \ 	}								      \       fprintf (asm_out_file, "\"\n");					      \     }									      \   }									      \   while (0)
end_define

begin_comment
comment|/* To get unaligned data, we have to turn off auto alignment.  */
end_comment

begin_define
define|#
directive|define
name|UNALIGNED_SHORT_ASM_OP
value|".align 0\n\t.word"
end_define

begin_define
define|#
directive|define
name|UNALIGNED_INT_ASM_OP
value|".align 0\n\t.long"
end_define

begin_define
define|#
directive|define
name|UNALIGNED_DOUBLE_INT_ASM_OP
value|".align 0\n\t.quad"
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
value|fprintf (FILE, "\tsubq $30,8,$30\n\tst%s $%s%d,0($30)\n",		\ 	  (REGNO)> 32 ? "t" : "q", (REGNO)> 32 ? "f" : "",		\ 	  (REGNO)& 31);
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
value|fprintf (FILE, "\tld%s $%s%d,0($30)\n\taddq $30,8,$30\n",		\ 	  (REGNO)> 32 ? "t" : "q", (REGNO)> 32 ? "f" : "",		\ 	  (REGNO)& 31);
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
value|fprintf (FILE, "\t.byte 0x%x\n", (int) ((VALUE)& 0xff))
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    (Alpha does not use such vectors, but we must define this macro anyway.)  */
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
value|abort ()
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
value|fprintf (FILE, "\t.%s $L%d\n", TARGET_WINDOWS_NT ? "long" : "gprel32", \ 	   (VALUE))
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

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
value|if ((LOG) != 0)			\     fprintf (FILE, "\t.align %d\n", LOG);
end_define

begin_comment
comment|/* This is how to advance the location counter by SIZE bytes.  */
end_comment

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
value|fprintf (FILE, "\t.space %d\n", (SIZE))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
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
value|( fputs ("\t.comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%d\n", (SIZE)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

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
value|( fputs ("\t.lcomm ", (FILE)),				\   assemble_name ((FILE), (NAME)),			\   fprintf ((FILE), ",%d\n", (SIZE)))
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
comment|/* Output code to add DELTA to the first argument, and then jump to FUNCTION.    Used for C++ multiple inheritance.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_MI_THUNK
parameter_list|(
name|FILE
parameter_list|,
name|THUNK_FNDECL
parameter_list|,
name|DELTA
parameter_list|,
name|FUNCTION
parameter_list|)
define|\
value|do {									\   char *fn_name = XSTR (XEXP (DECL_RTL (FUNCTION), 0), 0);		\   int reg;								\ 									\
comment|/* Mark end of prologue.  */
value|\   output_end_prologue (FILE);						\ 									\
comment|/* Rely on the assembler to macro expand a large delta.  */
value|\   reg = aggregate_value_p (TREE_TYPE (TREE_TYPE (FUNCTION))) ? 17 : 16;	\   fprintf (FILE, "\tlda $%d,%ld($%d)\n", reg, (long)(DELTA), reg);	\ 									\   if (current_file_function_operand (XEXP (DECL_RTL (FUNCTION), 0)))	\     {									\       fprintf (FILE, "\tbr $31,$");					\       assemble_name (FILE, fn_name);					\       fprintf (FILE, "..ng\n");						\     }									\   else									\     {									\       fprintf (FILE, "\tjmp $31,");					\       assemble_name (FILE, fn_name);					\       fputc ('\n', FILE);						\     }									\ } while (0)
end_define

begin_escape
end_escape

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
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.  */
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
comment|/* Determine which codes are valid without a following integer.  These must    not be alphabetic (the characters are chosen so that    PRINT_OPERAND_PUNCT_VALID_P translates into a simple range change when    using ASCII).&	Generates fp-rounding mode suffix: nothing for normal, 'c' for    	chopped, 'm' for minus-infinity, and 'd' for dynamic rounding 	mode.  alpha_fprm controls which suffix is generated.     '	Generates trap-mode suffix for instructions that accept the         su suffix only (cmpt et al).     `    Generates trap-mode suffix for instructions that accept the 	v and sv suffix.  The only instruction that needs this is cvtql.     (	Generates trap-mode suffix for instructions that accept the 	v, sv, and svi suffix.  The only instruction that needs this 	is cvttq.     )    Generates trap-mode suffix for instructions that accept the 	u, su, and sui suffix.  This is the bulk of the IEEE floating 	point instructions (addt et al).     +    Generates trap-mode suffix for instructions that accept the 	sui suffix (cvtqt and cvtqs).     ,    Generates single precision suffix for floating point 	instructions (s for IEEE, f for VAX)     -	Generates double precision suffix for floating point 	instructions (t for IEEE, g for VAX)    */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '&' || (CODE) == '`' || (CODE) == '\'' || (CODE) == '('	\    || (CODE) == ')' || (CODE) == '+' || (CODE) == ',' || (CODE) == '-')
end_define

begin_escape
end_escape

begin_comment
comment|/* Print a memory address as an operand to reference that memory location.  */
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
define|\
value|print_operand_address((FILE), (ADDR))
end_define

begin_comment
comment|/* Define the codes that are matched by predicates in alpha.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"reg_or_0_operand", {SUBREG, REG, CONST_INT}},			\   {"reg_or_6bit_operand", {SUBREG, REG, CONST_INT}},			\   {"reg_or_8bit_operand", {SUBREG, REG, CONST_INT}},			\   {"cint8_operand", {CONST_INT}},					\   {"reg_or_cint_operand", {SUBREG, REG, CONST_INT}},			\   {"add_operand", {SUBREG, REG, CONST_INT}},				\   {"sext_add_operand", {SUBREG, REG, CONST_INT}},			\   {"const48_operand", {CONST_INT}},					\   {"and_operand", {SUBREG, REG, CONST_INT}},				\   {"or_operand", {SUBREG, REG, CONST_INT}},				\   {"mode_mask_operand", {CONST_INT}},					\   {"mul8_operand", {CONST_INT}},					\   {"mode_width_operand", {CONST_INT}},					\   {"reg_or_fp0_operand", {SUBREG, REG, CONST_DOUBLE}},			\   {"alpha_comparison_operator", {EQ, LE, LT, LEU, LTU}},		\   {"alpha_swapped_comparison_operator", {EQ, GE, GT, GEU, GTU}},	\   {"signed_comparison_operator", {EQ, NE, LE, LT, GE, GT}},		\   {"divmod_operator", {DIV, MOD, UDIV, UMOD}},				\   {"fp0_operand", {CONST_DOUBLE}},					\   {"current_file_function_operand", {SYMBOL_REF}},			\   {"call_operand", {REG, SYMBOL_REF}},					\   {"input_operand", {SUBREG, REG, MEM, CONST_INT, CONST_DOUBLE,		\ 		     SYMBOL_REF, CONST, LABEL_REF}},			\   {"some_operand", {SUBREG, REG, MEM, CONST_INT, CONST_DOUBLE,		\ 		    SYMBOL_REF, CONST, LABEL_REF}},			\   {"aligned_memory_operand", {MEM}},					\   {"unaligned_memory_operand", {MEM}},					\   {"reg_or_unaligned_mem_operand", {SUBREG, REG, MEM}},			\   {"any_memory_operand", {MEM}},					\   {"hard_fp_register_operand", {SUBREG, REG}},				\   {"reg_not_elim_operand", {SUBREG, REG}},				\   {"reg_no_subreg_operand", {REG}},
end_define

begin_escape
end_escape

begin_comment
comment|/* Tell collect that the object format is ECOFF.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_COFF
end_define

begin_define
define|#
directive|define
name|EXTENDED_COFF
end_define

begin_comment
comment|/* If we use NM, pass -g to it so it only lists globals.  */
end_comment

begin_define
define|#
directive|define
name|NM_FLAGS
value|"-pg"
end_define

begin_comment
comment|/* Definitions for debugging.  */
end_comment

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
comment|/* generate embedded stabs */
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
value|SDB_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Correct the offset of automatic variables and arguments.  Note that    the Alpha debug format wants all automatic variables and arguments    to be in terms of two different offsets from the virtual frame pointer,    which is the stack pointer before any adjustment in the function.    The offset for the argument pointer is fixed for the native compiler,    it is either zero (for the no arguments case) or large enough to hold    all argument registers.    The offset for the auto pointer is the fourth argument to the .frame    directive (local_offset).    To stay compatible with the native tools we use the same offsets    from the virtual frame pointer and adjust the debugger arg/auto offsets    accordingly. These debugger offsets are set up in output_prolog.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|alpha_arg_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|alpha_auto_offset
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEBUGGER_AUTO_OFFSET
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == PLUS ? INTVAL (XEXP (X, 1)) : 0) + alpha_auto_offset)
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
value|(OFFSET + alpha_arg_offset)
end_define

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
value|alpha_output_lineno (STREAM, LINE)
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_output_lineno
parameter_list|()
function_decl|;
end_function_decl

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
value|alpha_output_filename (STREAM, NAME)
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_output_filename
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* mips-tfile.c limits us to strings of one page.  We must underestimate this    number, because the real length runs past this up to the next    continuation point.  This is really a dbxout.c bug.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|3000
end_define

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
comment|/* Stabs-in-ECOFF can't handle dbxout_function_end().  */
end_comment

begin_define
define|#
directive|define
name|NO_DBX_FUNCTION_END
value|1
end_define

begin_comment
comment|/* If we are smuggling stabs through the ALPHA ECOFF object    format, put a comment in front of the .stab<x> operation so    that the ALPHA assembler does not choke.  The mips-tfile program    will correctly put the stab into the object file.  */
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

begin_define
define|#
directive|define
name|PUT_SDB_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file, "\t%s.def\t",			\ 	   (TARGET_GAS) ? "" : "#");			\   ASM_OUTPUT_LABELREF (asm_out_file, a); 		\   fputc (';', asm_out_file);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_PLAIN_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file, "\t%s.def\t.%s;",		\ 	   (TARGET_GAS) ? "" : "#", (a));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_TYPE
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file, "\t.type\t0x%x;", (a));	\ } while (0)
end_define

begin_comment
comment|/* For block start and end, we create labels, so that    later we can figure out where the correct offset is.    The normal .ent/.end serve well enough for functions,    so those are just commented out.  */
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

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file,				\ 	   "$Lb%d:\n\t%s.begin\t$Lb%d\t%d\n",		\ 	   sdb_label_count,				\ 	   (TARGET_GAS) ? "" : "#",			\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file,				\ 	   "$Le%d:\n\t%s.bend\t$Le%d\t%d\n",		\ 	   sdb_label_count,				\ 	   (TARGET_GAS) ? "" : "#",			\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
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
value|((void)(NAME))
end_define

begin_comment
comment|/* Macros for mips-tfile.c to encapsulate stabs in ECOFF, and for    mips-tdump.c to print them out.     These must match the corresponding definitions in gdb/mipsread.c.    Unfortunately, gcc and gdb do not currently share any directories. */
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

begin_comment
comment|/* Override some mips-tfile definitions.  */
end_comment

begin_define
define|#
directive|define
name|SHASH_SIZE
value|511
end_define

begin_define
define|#
directive|define
name|THASH_SIZE
value|55
end_define

begin_comment
comment|/* Align ecoff symbol tables to avoid OSF1/1.3 nm complaints.  */
end_comment

begin_define
define|#
directive|define
name|ALIGN_SYMTABLE_OFFSET
parameter_list|(
name|OFFSET
parameter_list|)
value|(((OFFSET) + 7)& ~7)
end_define

begin_comment
comment|/* The linker will stick __main into the .init section.  */
end_comment

begin_define
define|#
directive|define
name|HAS_INIT_SECTION
end_define

begin_define
define|#
directive|define
name|LD_INIT_SWITCH
value|"-init"
end_define

begin_define
define|#
directive|define
name|LD_FINI_SWITCH
value|"-fini"
end_define

begin_comment
comment|/* The system headers under Alpha systems are generally C++-aware.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Prototypes for alpha.c functions used in the md file& elsewhere.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|get_unaligned_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_write_verstamp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_reorg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_float_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|direct_return
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|const48_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|add_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|and_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unaligned_memory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|zap_mask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|current_file_function_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alpha_sa_size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alpha_adjust_cost
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
name|int
name|reg_or_0_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_or_8bit_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mul8_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_or_6bit_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alpha_comparison_operator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alpha_swapped_comparison_operator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sext_add_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cint8_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mode_mask_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|or_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mode_width_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_or_fp0_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signed_comparison_operator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fp0_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|some_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|input_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|divmod_operator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|call_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_or_cint_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hard_fp_register_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reg_not_elim_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_set_memflags
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aligned_memory_operand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_aligned_mem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_expand_unaligned_load
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_expand_unaligned_store
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alpha_expand_block_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|alpha_expand_block_clear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_expand_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_expand_epilogue
parameter_list|()
function_decl|;
end_function_decl

end_unit

