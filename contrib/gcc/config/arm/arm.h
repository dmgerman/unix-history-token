begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for ARM.    Copyright (C) 1991, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002 Free Software Foundation, Inc.    Contributed by Pieter `Tiggr' Schoenmakers (rcpieter@win.tue.nl)    and Martin Simmons (@harleqn.co.uk).    More major hacks by Richard Earnshaw (rearnsha@arm.com)    Minor hacks by Nick Clifton (nickc@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_ARM_H
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm2
value|0x0000
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm250
value|0x0000
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm3
value|0x0000
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm6
value|0x0001
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm600
value|0x0001
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm610
value|0x0002
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7
value|0x0001
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7m
value|0x0004
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7dm
value|0x0004
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7dmi
value|0x0004
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm700
value|0x0001
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm710
value|0x0002
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7100
value|0x0002
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7500
value|0x0002
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7500fe
value|0x1001
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm7tdmi
value|0x0008
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm8
value|0x0010
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm810
value|0x0020
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_strongarm
value|0x0040
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_strongarm110
value|0x0040
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_strongarm1100
value|0x0040
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm9
value|0x0080
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_arm9tdmi
value|0x0080
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_xscale
value|0x0100
end_define

begin_comment
comment|/* Configure didn't specify.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_generic
value|0x8000
end_define

begin_typedef
typedef|typedef
enum|enum
name|arm_cond_code
block|{
name|ARM_EQ
init|=
literal|0
block|,
name|ARM_NE
block|,
name|ARM_CS
block|,
name|ARM_CC
block|,
name|ARM_MI
block|,
name|ARM_PL
block|,
name|ARM_VS
block|,
name|ARM_VC
block|,
name|ARM_HI
block|,
name|ARM_LS
block|,
name|ARM_GE
block|,
name|ARM_LT
block|,
name|ARM_GT
block|,
name|ARM_LE
block|,
name|ARM_AL
block|,
name|ARM_NV
block|}
name|arm_cc
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|arm_cc
name|arm_current_cc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ARM_INVERSE_CONDITION_CODE
parameter_list|(
name|X
parameter_list|)
value|((arm_cc) (((int)X) ^ 1))
end_define

begin_decl_stmt
specifier|extern
name|int
name|arm_target_label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_ccfsm_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|arm_target_insn
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
comment|/* The floating point instruction architecture, can be 2 or 3 */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|target_fp_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the information needed to generate branch insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|arm_compare_op0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|arm_compare_op1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The label of the current constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|pool_vector_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 1 when a return insn is output, this means that the epilogue    is not needed. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|return_used_this_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the prologue must setup `fp'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_anonymous_args
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Just in case configure has failed to define anything. */
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
value|TARGET_CPU_generic
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the configuration file doesn't specify the cpu, the subtarget may    override it.  If it doesn't, then default to an ARM6.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_generic
end_if

begin_undef
undef|#
directive|undef
name|TARGET_CPU_DEFAULT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|SUBTARGET_CPU_DEFAULT
end_ifdef

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT
value|SUBTARGET_CPU_DEFAULT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT
value|TARGET_CPU_arm6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm2
end_if

begin_define
define|#
directive|define
name|CPP_ARCH_DEFAULT_SPEC
value|"-D__ARM_ARCH_2__"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm6
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm610
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm7500fe
end_if

begin_define
define|#
directive|define
name|CPP_ARCH_DEFAULT_SPEC
value|"-D__ARM_ARCH_3__"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm7m
end_if

begin_define
define|#
directive|define
name|CPP_ARCH_DEFAULT_SPEC
value|"-D__ARM_ARCH_3M__"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm7tdmi
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm9
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm9tdmi
end_if

begin_define
define|#
directive|define
name|CPP_ARCH_DEFAULT_SPEC
value|"-D__ARM_ARCH_4T__"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm8
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_arm810
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_strongarm
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_strongarm110
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_strongarm1100
end_if

begin_define
define|#
directive|define
name|CPP_ARCH_DEFAULT_SPEC
value|"-D__ARM_ARCH_4__"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_xscale
end_if

begin_define
define|#
directive|define
name|CPP_ARCH_DEFAULT_SPEC
value|"-D__ARM_ARCH_5TE__ -D__XSCALE__"
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|Unrecognized
name|value
name|in
name|TARGET_CPU_DEFAULT
operator|.
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
undef|#
directive|undef
name|CPP_SPEC
define|#
directive|define
name|CPP_SPEC
value|"\ %(cpp_cpu_arch) %(cpp_apcs_pc) %(cpp_float) \ %(cpp_endian) %(subtarget_cpp_spec) %(cpp_isa) %(cpp_interwork)"
define|#
directive|define
name|CPP_ISA_SPEC
value|"%{mthumb:-D__thumb__} %{!mthumb:-D__arm__}"
comment|/* Set the architecture define -- if -march= is set, then it overrides    the -mcpu= setting.  */
define|#
directive|define
name|CPP_CPU_ARCH_SPEC
value|"\ -Acpu=arm -Amachine=arm \ %{march=arm2:-D__ARM_ARCH_2__} \ %{march=arm250:-D__ARM_ARCH_2__} \ %{march=arm3:-D__ARM_ARCH_2__} \ %{march=arm6:-D__ARM_ARCH_3__} \ %{march=arm600:-D__ARM_ARCH_3__} \ %{march=arm610:-D__ARM_ARCH_3__} \ %{march=arm7:-D__ARM_ARCH_3__} \ %{march=arm700:-D__ARM_ARCH_3__} \ %{march=arm710:-D__ARM_ARCH_3__} \ %{march=arm720:-D__ARM_ARCH_3__} \ %{march=arm7100:-D__ARM_ARCH_3__} \ %{march=arm7500:-D__ARM_ARCH_3__} \ %{march=arm7500fe:-D__ARM_ARCH_3__} \ %{march=arm7m:-D__ARM_ARCH_3M__} \ %{march=arm7dm:-D__ARM_ARCH_3M__} \ %{march=arm7dmi:-D__ARM_ARCH_3M__} \ %{march=arm7tdmi:-D__ARM_ARCH_4T__} \ %{march=arm8:-D__ARM_ARCH_4__} \ %{march=arm810:-D__ARM_ARCH_4__} \ %{march=arm9:-D__ARM_ARCH_4T__} \ %{march=arm920:-D__ARM_ARCH_4__} \ %{march=arm920t:-D__ARM_ARCH_4T__} \ %{march=arm9tdmi:-D__ARM_ARCH_4T__} \ %{march=strongarm:-D__ARM_ARCH_4__} \ %{march=strongarm110:-D__ARM_ARCH_4__} \ %{march=strongarm1100:-D__ARM_ARCH_4__} \ %{march=xscale:-D__ARM_ARCH_5TE__} \ %{march=xscale:-D__XSCALE__} \ %{march=armv2:-D__ARM_ARCH_2__} \ %{march=armv2a:-D__ARM_ARCH_2__} \ %{march=armv3:-D__ARM_ARCH_3__} \ %{march=armv3m:-D__ARM_ARCH_3M__} \ %{march=armv4:-D__ARM_ARCH_4__} \ %{march=armv4t:-D__ARM_ARCH_4T__} \ %{march=armv5:-D__ARM_ARCH_5__} \ %{march=armv5t:-D__ARM_ARCH_5T__} \ %{march=armv5e:-D__ARM_ARCH_5E__} \ %{march=armv5te:-D__ARM_ARCH_5TE__} \ %{!march=*: \  %{mcpu=arm2:-D__ARM_ARCH_2__} \  %{mcpu=arm250:-D__ARM_ARCH_2__} \  %{mcpu=arm3:-D__ARM_ARCH_2__} \  %{mcpu=arm6:-D__ARM_ARCH_3__} \  %{mcpu=arm600:-D__ARM_ARCH_3__} \  %{mcpu=arm610:-D__ARM_ARCH_3__} \  %{mcpu=arm7:-D__ARM_ARCH_3__} \  %{mcpu=arm700:-D__ARM_ARCH_3__} \  %{mcpu=arm710:-D__ARM_ARCH_3__} \  %{mcpu=arm720:-D__ARM_ARCH_3__} \  %{mcpu=arm7100:-D__ARM_ARCH_3__} \  %{mcpu=arm7500:-D__ARM_ARCH_3__} \  %{mcpu=arm7500fe:-D__ARM_ARCH_3__} \  %{mcpu=arm7m:-D__ARM_ARCH_3M__} \  %{mcpu=arm7dm:-D__ARM_ARCH_3M__} \  %{mcpu=arm7dmi:-D__ARM_ARCH_3M__} \  %{mcpu=arm7tdmi:-D__ARM_ARCH_4T__} \  %{mcpu=arm8:-D__ARM_ARCH_4__} \  %{mcpu=arm810:-D__ARM_ARCH_4__} \  %{mcpu=arm9:-D__ARM_ARCH_4T__} \  %{mcpu=arm920:-D__ARM_ARCH_4__} \  %{mcpu=arm920t:-D__ARM_ARCH_4T__} \  %{mcpu=arm9tdmi:-D__ARM_ARCH_4T__} \  %{mcpu=strongarm:-D__ARM_ARCH_4__} \  %{mcpu=strongarm110:-D__ARM_ARCH_4__} \  %{mcpu=strongarm1100:-D__ARM_ARCH_4__} \  %{mcpu=xscale:-D__ARM_ARCH_5TE__} \  %{mcpu=xscale:-D__XSCALE__} \  %{!mcpu*:%(cpp_cpu_arch_default)}} \ "
comment|/* Define __APCS_26__ if the PC also contains the PSR */
define|#
directive|define
name|CPP_APCS_PC_SPEC
value|"\ %{mapcs-32:%{mapcs-26:%e-mapcs-26 and -mapcs-32 may not be used together} \  -D__APCS_32__} \ %{mapcs-26:-D__APCS_26__} \ %{!mapcs-32: %{!mapcs-26:%(cpp_apcs_pc_default)}} \ "
ifndef|#
directive|ifndef
name|CPP_APCS_PC_DEFAULT_SPEC
define|#
directive|define
name|CPP_APCS_PC_DEFAULT_SPEC
value|"-D__APCS_26__"
endif|#
directive|endif
define|#
directive|define
name|CPP_FLOAT_SPEC
value|"\ %{msoft-float:\   %{mhard-float:%e-msoft-float and -mhard_float may not be used together} \   -D__SOFTFP__} \ %{!mhard-float:%{!msoft-float:%(cpp_float_default)}} \ "
comment|/* Default is hard float, which doesn't define anything */
define|#
directive|define
name|CPP_FLOAT_DEFAULT_SPEC
value|""
define|#
directive|define
name|CPP_ENDIAN_SPEC
value|"\ %{mbig-endian:								\   %{mlittle-endian:							\     %e-mbig-endian and -mlittle-endian may not be used together}	\   -D__ARMEB__ %{mwords-little-endian:-D__ARMWEL__} %{mthumb:-D__THUMBEB__}}\ %{mlittle-endian:-D__ARMEL__ %{mthumb:-D__THUMBEL__}}			\ %{!mlittle-endian:%{!mbig-endian:%(cpp_endian_default)}}		\ "
comment|/* Default is little endian.  */
define|#
directive|define
name|CPP_ENDIAN_DEFAULT_SPEC
value|"-D__ARMEL__ %{mthumb:-D__THUMBEL__}"
comment|/* Add a define for interworking.  Needed when building libgcc.a.      This must define __THUMB_INTERWORK__ to the pre-processor if    interworking is enabled by default.  */
ifndef|#
directive|ifndef
name|CPP_INTERWORK_DEFAULT_SPEC
define|#
directive|define
name|CPP_INTERWORK_DEFAULT_SPEC
value|""
endif|#
directive|endif
define|#
directive|define
name|CPP_INTERWORK_SPEC
value|"						\ %{mthumb-interwork:							\   %{mno-thumb-interwork: %eincompatible interworking options}		\   -D__THUMB_INTERWORK__}						\ %{!mthumb-interwork:%{!mno-thumb-interwork:%(cpp_interwork_default)}}	\ "
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
define|#
directive|define
name|CPP_PREDEFINES
value|""
endif|#
directive|endif
ifndef|#
directive|ifndef
name|CC1_SPEC
define|#
directive|define
name|CC1_SPEC
value|""
endif|#
directive|endif
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GNU CC driver    program.     Do not define this macro if it does not need to do anything.  */
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "cpp_cpu_arch",		CPP_CPU_ARCH_SPEC },		\   { "cpp_cpu_arch_default",	CPP_ARCH_DEFAULT_SPEC },	\   { "cpp_apcs_pc",		CPP_APCS_PC_SPEC },		\   { "cpp_apcs_pc_default",	CPP_APCS_PC_DEFAULT_SPEC },	\   { "cpp_float",		CPP_FLOAT_SPEC },		\   { "cpp_float_default",	CPP_FLOAT_DEFAULT_SPEC },	\   { "cpp_endian",		CPP_ENDIAN_SPEC },		\   { "cpp_endian_default",	CPP_ENDIAN_DEFAULT_SPEC },	\   { "cpp_isa",			CPP_ISA_SPEC },			\   { "cpp_interwork",		CPP_INTERWORK_SPEC },		\   { "cpp_interwork_default",	CPP_INTERWORK_DEFAULT_SPEC },	\   { "subtarget_cpp_spec",	SUBTARGET_CPP_SPEC },           \   SUBTARGET_EXTRA_SPECS
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_SPECS
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SUBTARGET_CPP_SPEC
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|""
endif|#
directive|endif
comment|/* Run-time Target Specification.  */
ifndef|#
directive|ifndef
name|TARGET_VERSION
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/generic)", stderr);
endif|#
directive|endif
comment|/* Nonzero if the function prologue (and epilogue) should obey    the ARM Procedure Call Standard.  */
define|#
directive|define
name|ARM_FLAG_APCS_FRAME
value|(1<< 0)
comment|/* Nonzero if the function prologue should output the function name to enable    the post mortem debugger to print a backtrace (very useful on RISCOS,    unused on RISCiX).  Specifying this flag also enables    -fno-omit-frame-pointer.    XXX Must still be implemented in the prologue.  */
define|#
directive|define
name|ARM_FLAG_POKE
value|(1<< 1)
comment|/* Nonzero if floating point instructions are emulated by the FPE, in which    case instruction scheduling becomes very uninteresting.  */
define|#
directive|define
name|ARM_FLAG_FPE
value|(1<< 2)
comment|/* Nonzero if destined for a processor in 32-bit program mode.  Takes out bit    that assume restoration of the condition flags when returning from a    branch and link (ie a function).  */
define|#
directive|define
name|ARM_FLAG_APCS_32
value|(1<< 3)
comment|/* FLAGS 0x0008 and 0x0010 are now spare (used to be arm3/6 selection).  */
comment|/* Nonzero if stack checking should be performed on entry to each function    which allocates temporary variables on the stack.  */
define|#
directive|define
name|ARM_FLAG_APCS_STACK
value|(1<< 4)
comment|/* Nonzero if floating point parameters should be passed to functions in    floating point registers.  */
define|#
directive|define
name|ARM_FLAG_APCS_FLOAT
value|(1<< 5)
comment|/* Nonzero if re-entrant, position independent code should be generated.    This is equivalent to -fpic.  */
define|#
directive|define
name|ARM_FLAG_APCS_REENT
value|(1<< 6)
comment|/* Nonzero if the MMU will trap unaligned word accesses, so shorts must    be loaded using either LDRH or LDRB instructions.  */
define|#
directive|define
name|ARM_FLAG_MMU_TRAPS
value|(1<< 7)
comment|/* Nonzero if all floating point instructions are missing (and there is no    emulator either).  Generate function calls for all ops in this case.  */
define|#
directive|define
name|ARM_FLAG_SOFT_FLOAT
value|(1<< 8)
comment|/* Nonzero if we should compile with BYTES_BIG_ENDIAN set to 1.  */
define|#
directive|define
name|ARM_FLAG_BIG_END
value|(1<< 9)
comment|/* Nonzero if we should compile for Thumb interworking.  */
define|#
directive|define
name|ARM_FLAG_INTERWORK
value|(1<< 10)
comment|/* Nonzero if we should have little-endian words even when compiling for    big-endian (for backwards compatibility with older versions of GCC).  */
define|#
directive|define
name|ARM_FLAG_LITTLE_WORDS
value|(1<< 11)
comment|/* Nonzero if we need to protect the prolog from scheduling */
define|#
directive|define
name|ARM_FLAG_NO_SCHED_PRO
value|(1<< 12)
comment|/* Nonzero if a call to abort should be generated if a noreturn     function tries to return.  */
define|#
directive|define
name|ARM_FLAG_ABORT_NORETURN
value|(1<< 13)
comment|/* Nonzero if function prologues should not load the PIC register. */
define|#
directive|define
name|ARM_FLAG_SINGLE_PIC_BASE
value|(1<< 14)
comment|/* Nonzero if all call instructions should be indirect.  */
define|#
directive|define
name|ARM_FLAG_LONG_CALLS
value|(1<< 15)
comment|/* Nonzero means that the target ISA is the THUMB, not the ARM.  */
define|#
directive|define
name|ARM_FLAG_THUMB
value|(1<< 16)
comment|/* Set if a TPCS style stack frame should be generated, for non-leaf    functions, even if they do not need one.  */
define|#
directive|define
name|THUMB_FLAG_BACKTRACE
value|(1<< 17)
comment|/* Set if a TPCS style stack frame should be generated, for leaf    functions, even if they do not need one.  */
define|#
directive|define
name|THUMB_FLAG_LEAF_BACKTRACE
value|(1<< 18)
comment|/* Set if externally visible functions should assume that they    might be called in ARM mode, from a non-thumb aware code.  */
define|#
directive|define
name|THUMB_FLAG_CALLEE_SUPER_INTERWORKING
value|(1<< 19)
comment|/* Set if calls via function pointers should assume that their    destination is non-Thumb aware.  */
define|#
directive|define
name|THUMB_FLAG_CALLER_SUPER_INTERWORKING
value|(1<< 20)
define|#
directive|define
name|TARGET_APCS_FRAME
value|(target_flags& ARM_FLAG_APCS_FRAME)
define|#
directive|define
name|TARGET_POKE_FUNCTION_NAME
value|(target_flags& ARM_FLAG_POKE)
define|#
directive|define
name|TARGET_FPE
value|(target_flags& ARM_FLAG_FPE)
define|#
directive|define
name|TARGET_APCS_32
value|(target_flags& ARM_FLAG_APCS_32)
define|#
directive|define
name|TARGET_APCS_STACK
value|(target_flags& ARM_FLAG_APCS_STACK)
define|#
directive|define
name|TARGET_APCS_FLOAT
value|(target_flags& ARM_FLAG_APCS_FLOAT)
define|#
directive|define
name|TARGET_APCS_REENT
value|(target_flags& ARM_FLAG_APCS_REENT)
define|#
directive|define
name|TARGET_MMU_TRAPS
value|(target_flags& ARM_FLAG_MMU_TRAPS)
define|#
directive|define
name|TARGET_SOFT_FLOAT
value|(target_flags& ARM_FLAG_SOFT_FLOAT)
define|#
directive|define
name|TARGET_HARD_FLOAT
value|(! TARGET_SOFT_FLOAT)
define|#
directive|define
name|TARGET_BIG_END
value|(target_flags& ARM_FLAG_BIG_END)
define|#
directive|define
name|TARGET_INTERWORK
value|(target_flags& ARM_FLAG_INTERWORK)
define|#
directive|define
name|TARGET_LITTLE_WORDS
value|(target_flags& ARM_FLAG_LITTLE_WORDS)
define|#
directive|define
name|TARGET_NO_SCHED_PRO
value|(target_flags& ARM_FLAG_NO_SCHED_PRO)
define|#
directive|define
name|TARGET_ABORT_NORETURN
value|(target_flags& ARM_FLAG_ABORT_NORETURN)
define|#
directive|define
name|TARGET_SINGLE_PIC_BASE
value|(target_flags& ARM_FLAG_SINGLE_PIC_BASE)
define|#
directive|define
name|TARGET_LONG_CALLS
value|(target_flags& ARM_FLAG_LONG_CALLS)
define|#
directive|define
name|TARGET_THUMB
value|(target_flags& ARM_FLAG_THUMB)
define|#
directive|define
name|TARGET_ARM
value|(! TARGET_THUMB)
define|#
directive|define
name|TARGET_EITHER
value|1
comment|/* (TARGET_ARM | TARGET_THUMB) */
define|#
directive|define
name|TARGET_CALLEE_INTERWORKING
value|(target_flags& THUMB_FLAG_CALLEE_SUPER_INTERWORKING)
define|#
directive|define
name|TARGET_CALLER_INTERWORKING
value|(target_flags& THUMB_FLAG_CALLER_SUPER_INTERWORKING)
define|#
directive|define
name|TARGET_BACKTRACE
value|(leaf_function_p ()	      			\ 				         ? (target_flags& THUMB_FLAG_LEAF_BACKTRACE)	\ 				         : (target_flags& THUMB_FLAG_BACKTRACE))
comment|/* SUBTARGET_SWITCHES is used to add flags on a per-config basis.    Bit 31 is reserved.  See riscix.h.  */
ifndef|#
directive|ifndef
name|SUBTARGET_SWITCHES
define|#
directive|define
name|SUBTARGET_SWITCHES
endif|#
directive|endif
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{									\   {"apcs",			ARM_FLAG_APCS_FRAME, "" },		\   {"apcs-frame",		ARM_FLAG_APCS_FRAME,			\    N_("Generate APCS conformant stack frames") },			\   {"no-apcs-frame",	       -ARM_FLAG_APCS_FRAME, "" },		\   {"poke-function-name",	ARM_FLAG_POKE,				\    N_("Store function names in object code") },				\   {"no-poke-function-name",    -ARM_FLAG_POKE, "" },			\   {"fpe",			ARM_FLAG_FPE,  "" },			\   {"apcs-32",			ARM_FLAG_APCS_32,			\    N_("Use the 32-bit version of the APCS") },				\   {"apcs-26",		       -ARM_FLAG_APCS_32,			\    N_("Use the 26-bit version of the APCS") },				\   {"apcs-stack-check",		ARM_FLAG_APCS_STACK, "" },		\   {"no-apcs-stack-check",      -ARM_FLAG_APCS_STACK, "" },		\   {"apcs-float",		ARM_FLAG_APCS_FLOAT,			\    N_("Pass FP arguments in FP registers") },				\   {"no-apcs-float",	       -ARM_FLAG_APCS_FLOAT, "" },		\   {"apcs-reentrant",		ARM_FLAG_APCS_REENT,			\    N_("Generate re-entrant, PIC code") },				\   {"no-apcs-reentrant",	       -ARM_FLAG_APCS_REENT, "" },		\   {"alignment-traps",           ARM_FLAG_MMU_TRAPS,			\    N_("The MMU will trap on unaligned accesses") },			\   {"no-alignment-traps",       -ARM_FLAG_MMU_TRAPS, "" },		\   {"short-load-bytes",		ARM_FLAG_MMU_TRAPS, "" },		\   {"no-short-load-bytes",      -ARM_FLAG_MMU_TRAPS, "" },		\   {"short-load-words",	       -ARM_FLAG_MMU_TRAPS, "" },		\   {"no-short-load-words",	ARM_FLAG_MMU_TRAPS, "" },		\   {"soft-float",		ARM_FLAG_SOFT_FLOAT,			\    N_("Use library calls to perform FP operations") },			\   {"hard-float",	       -ARM_FLAG_SOFT_FLOAT,			\    N_("Use hardware floating point instructions") },			\   {"big-endian",		ARM_FLAG_BIG_END,			\    N_("Assume target CPU is configured as big endian") },		\   {"little-endian",	       -ARM_FLAG_BIG_END,			\    N_("Assume target CPU is configured as little endian") },		\   {"words-little-endian",       ARM_FLAG_LITTLE_WORDS,			\    N_("Assume big endian bytes, little endian words") },		\   {"thumb-interwork",		ARM_FLAG_INTERWORK,			\    N_("Support calls between Thumb and ARM instruction sets") },	\   {"no-thumb-interwork",       -ARM_FLAG_INTERWORK, "" },		\   {"abort-on-noreturn",         ARM_FLAG_ABORT_NORETURN,		\    N_("Generate a call to abort if a noreturn function returns")},	\   {"no-abort-on-noreturn",     -ARM_FLAG_ABORT_NORETURN, "" },		\   {"no-sched-prolog",           ARM_FLAG_NO_SCHED_PRO,			\    N_("Do not move instructions into a function's prologue") },		\   {"sched-prolog",             -ARM_FLAG_NO_SCHED_PRO, "" },		\   {"single-pic-base",		ARM_FLAG_SINGLE_PIC_BASE,		\    N_("Do not load the PIC register in function prologues") },		\   {"no-single-pic-base",       -ARM_FLAG_SINGLE_PIC_BASE, "" },		\   {"long-calls",		ARM_FLAG_LONG_CALLS,			\    N_("Generate call insns as indirect calls, if necessary") },		\   {"no-long-calls",	       -ARM_FLAG_LONG_CALLS, "" },		\   {"thumb",                     ARM_FLAG_THUMB,				\    N_("Compile for the Thumb not the ARM") },				\   {"no-thumb",                 -ARM_FLAG_THUMB, "" },			\   {"arm",                      -ARM_FLAG_THUMB, "" },			\   {"tpcs-frame",		    THUMB_FLAG_BACKTRACE,		\    N_("Thumb: Generate (non-leaf) stack frames even if not needed") },	   \   {"no-tpcs-frame",                -THUMB_FLAG_BACKTRACE, "" },		   \   {"tpcs-leaf-frame",	  	    THUMB_FLAG_LEAF_BACKTRACE,		   \    N_("Thumb: Generate (leaf) stack frames even if not needed") },	   \   {"no-tpcs-leaf-frame",           -THUMB_FLAG_LEAF_BACKTRACE, "" },	   \   {"callee-super-interworking",	    THUMB_FLAG_CALLEE_SUPER_INTERWORKING,  \    N_("Thumb: Assume non-static functions may be called from ARM code") }, \   {"no-callee-super-interworking", -THUMB_FLAG_CALLEE_SUPER_INTERWORKING,  \      "" },								   \   {"caller-super-interworking",	    THUMB_FLAG_CALLER_SUPER_INTERWORKING,  \    N_("Thumb: Assume function pointers may go to non-Thumb aware code") }, \   {"no-caller-super-interworking", -THUMB_FLAG_CALLER_SUPER_INTERWORKING,  \    "" },								   \   SUBTARGET_SWITCHES							   \   {"",				TARGET_DEFAULT, "" }			   \ }
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{								\   {"cpu=",& arm_select[0].string,				\    N_("Specify the name of the target CPU") },			\   {"arch=",& arm_select[1].string,				\    N_("Specify the name of the target architecture") }, 	\   {"tune=",& arm_select[2].string, "" }, 			\   {"fpe=",& target_fp_name, "" }, 				\   {"fp=",& target_fp_name,					\    N_("Specify the version of the floating point emulator") },	\   {"structure-size-boundary=",& structure_size_string, 	\    N_("Specify the minimum bit alignment of structures") }, 	\   {"pic-register=",& arm_pic_register_string,			\    N_("Specify the register to be used for PIC addressing") }	\ }
expr|struct
name|arm_cpu_select
block|{
specifier|const
name|char
operator|*
name|string
block|;
specifier|const
name|char
operator|*
name|name
block|;
specifier|const
expr|struct
name|processors
operator|*
name|processors
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* This is a magic array.  If the user specifies a command line switch    which matches one of the entries in TARGET_OPTIONS then the corresponding    string pointer will be set to the value specified by the user.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|arm_cpu_select
name|arm_select
index|[]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|prog_mode_type
block|{
name|prog_mode26
block|,
name|prog_mode32
block|}
enum|;
end_enum

begin_comment
comment|/* Recast the program mode class to be the prog_mode attribute */
end_comment

begin_define
define|#
directive|define
name|arm_prog_mode
value|((enum attr_prog_mode) arm_prgmode)
end_define

begin_decl_stmt
specifier|extern
name|enum
name|prog_mode_type
name|arm_prgmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What sort of floating point unit do we have? Hardware or software.    If software, is it issue 2 or issue 3?  */
end_comment

begin_enum
enum|enum
name|floating_point_type
block|{
name|FP_HARD
block|,
name|FP_SOFT2
block|,
name|FP_SOFT3
block|}
enum|;
end_enum

begin_comment
comment|/* Recast the floating point class to be the floating point attribute.  */
end_comment

begin_define
define|#
directive|define
name|arm_fpu_attr
value|((enum attr_fpu) arm_fpu)
end_define

begin_comment
comment|/* What type of floating point to tune for */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|floating_point_type
name|arm_fpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What type of floating point instructions are available */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|floating_point_type
name|arm_fpu_arch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default floating point architecture.  Override in sub-target if    necessary.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FP_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|FP_DEFAULT
value|FP_SOFT2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if the processor has a fast multiply insn, and one that does    a 64-bit multiply of two 32-bit values.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_fast_multiply
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 4 extensions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 5 extensions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 5E extensions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch5e
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip can benefit from load scheduling.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_ld_sched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if generating thumb code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|thumb_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip is a StrongARM.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_is_strong
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip is an XScale.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_is_xscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip is an ARM6 or an ARM7.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_is_6_or_7
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(ARM_FLAG_APCS_FRAME)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The frame pointer register used in gcc has nothing to do with debugging;    that is controlled by the APCS-FRAME option.  */
end_comment

begin_define
define|#
directive|define
name|CAN_DEBUG_WITHOUT_FP
end_define

begin_undef
undef|#
directive|undef
name|TARGET_MEM_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
value|1
end_define

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|arm_override_options ()
end_define

begin_comment
comment|/* Nonzero if PIC code requires explicit qualifiers to generate    PLT and GOT relocs rather than the assembler doing so implicitly.    Subtargets can override these if required.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_GOT_RELOC
end_ifndef

begin_define
define|#
directive|define
name|NEED_GOT_RELOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_PLT_RELOC
end_ifndef

begin_define
define|#
directive|define
name|NEED_PLT_RELOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if we need to refer to the GOT with a PC-relative    offset.  In other words, generate     .word	_GLOBAL_OFFSET_TABLE_ - [. - (.Lxx + 8)]       rather than     .word	_GLOBAL_OFFSET_TABLE_ - (.Lxx + 8)     The default is true, which matches NetBSD.  Subtargets can     override this if required.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOT_PCREL
end_ifndef

begin_define
define|#
directive|define
name|GOT_PCREL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Target machine storage Layout.  */
end_comment

begin_comment
comment|/* Define this macro if it is advisable to hold scalars in registers    in a wider mode than that declared by the program.  In such cases,    the value is constrained to be within the bounds of the declared    type, but kept valid in the wider mode.  The signedness of the    extension may differ from that of the type.  */
end_comment

begin_comment
comment|/* It is far faster to zero extend chars than to sign extend them */
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
value|if (GET_MODE_CLASS (MODE) == MODE_INT		\&& GET_MODE_SIZE (MODE)< 4)      	\     {						\       if (MODE == QImode)			\ 	UNSIGNEDP = 1;				\       else if (MODE == HImode)			\ 	UNSIGNEDP = TARGET_MMU_TRAPS != 0;	\       (MODE) = SImode;				\     }
end_define

begin_comment
comment|/* Define this macro if the promotion described by `PROMOTE_MODE'    should also be done for outgoing function arguments.  */
end_comment

begin_comment
comment|/* This is required to ensure that push insns always push a word.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_ARGS
end_define

begin_comment
comment|/* Define for XFmode extended real floating point support.    This will automatically cause REAL_ARITHMETIC to be defined.  */
end_comment

begin_comment
comment|/* For the ARM:    I think I have added all the code to make this work.  Unfortunately,    early releases of the floating point emulation code on RISCiX used a    different format for extended precision numbers.  On my RISCiX box there    is a bug somewhere which causes the machine to lock up when running enquire    with long doubles.  There is the additional aspect that Norcroft C    treats long doubles as doubles and we ought to remain compatible.    Perhaps someone with an FPA coprocessor and not running RISCiX would like    to try this someday. */
end_comment

begin_comment
comment|/* #define LONG_DOUBLE_TYPE_SIZE 96 */
end_comment

begin_comment
comment|/* Disable XFmode patterns in md file */
end_comment

begin_define
define|#
directive|define
name|ENABLE_XF_PATTERNS
value|0
end_define

begin_comment
comment|/* Define if you don't want extended real, but do want to use the    software floating point emulator for REAL_ARITHMETIC and    decimal<-> binary conversion. */
end_comment

begin_comment
comment|/* See comment above */
end_comment

begin_define
define|#
directive|define
name|REAL_ARITHMETIC
end_define

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.      Most ARM processors are run in little endian mode, so that is the default.    If you want to have it run-time selectable, change the definition in a    cover file to be TARGET_BIG_ENDIAN.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|(TARGET_BIG_END != 0)
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is the lowest    numbered.    This is always false, even when in big-endian mode.  */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|(BYTES_BIG_ENDIAN&& ! TARGET_LITTLE_WORDS)
end_define

begin_comment
comment|/* LIBGCC2_WORDS_BIG_ENDIAN has to be a constant, so we define this based    on processor pre-defineds when compiling libgcc2.c.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARMEB__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ARMWEL__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this if most significant word of doubles is the lowest numbered.    This is always true, even when in little-endian mode.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Number of bits in an addressable storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
end_define

begin_comment
comment|/* The lowest bit is used to indicate Thumb-mode functions, so the    vbit must go into the delta field of pointers to member    functions.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PTRMEMFUNC_VBIT_LOCATION
value|ptrmemfunc_vbit_in_delta
end_define

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|32
end_define

begin_comment
comment|/* Make strings word-aligned so strcpy from constants will be faster.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ALIGNMENT_FACTOR
value|(TARGET_THUMB || ! arm_is_xscale ? 1 : 2)
end_define

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
value|((TREE_CODE (EXP) == STRING_CST				\&& (ALIGN)< BITS_PER_WORD * CONSTANT_ALIGNMENT_FACTOR)	\    ? BITS_PER_WORD * CONSTANT_ALIGNMENT_FACTOR : (ALIGN))
end_define

begin_comment
comment|/* Setting STRUCTURE_SIZE_BOUNDARY to 32 produces more efficient code, but the    value set in previous versions of this toolchain was 8, which produces more    compact structures.  The command line option -mstructure_size_boundary=<n>    can be used to change this value.  For compatibility with the ARM SDK    however the value should be left at 32.  ARM SDT Reference Manual (ARM DUI    0020D) page 2-20 says "Structures are aligned on word boundaries".  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|arm_structure_size_boundary
end_define

begin_decl_stmt
specifier|extern
name|int
name|arm_structure_size_boundary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the value used to initialise arm_structure_size_boundary.  If a    particular arm target wants to change the default value it should change    the definition of this macro, not STRUCTRUE_SIZE_BOUNDARY.  See netbsd.h    for an example of this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_STRUCTURE_SIZE_BOUNDARY
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_STRUCTURE_SIZE_BOUNDARY
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Used when parsing command line option -mstructure_size_boundary.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|structure_size_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_FLOAT_FORMAT
value|IEEE_FLOAT_FORMAT
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Register allocation in ARM Procedure Call Standard (as used on RISCiX):    (S - saved over call).  	r0	   *	argument word/integer result 	r1-r3		argument word  	r4-r8	     S	register variable 	r9	     S	(rfp) register variable (real frame pointer) 	 	r10  	   F S	(sl) stack limit (used by -mapcs-stack-check) 	r11 	   F S	(fp) argument pointer 	r12		(ip) temp workspace 	r13  	   F S	(sp) lower end of current stack frame 	r14		(lr) link address/workspace 	r15	   F	(pc) program counter  	f0		floating point result 	f1-f3		floating point scratch  	f4-f7	     S	floating point variable  	cc		This is NOT a real register, but is used internally 	                to represent things that use or set the condition 			codes. 	sfp             This isn't either.  It is used during rtl generation 	                since the offset between the frame pointer and the 			auto's isn't known until after register allocation. 	afp		Nor this, we only need this because of non-local 	                goto.  Without it fp appears to be used and the 			elimination code won't get rid of sfp.  It tracks 			fp exactly at all times.     *: See CONDITIONAL_REGISTER_USAGE  */
end_comment

begin_comment
comment|/* The stack backtrace structure is as follows:   fp points to here:  |  save code pointer  |      [fp]                       |  return link value  |      [fp, #-4]                       |  return sp value    |      [fp, #-8]                       |  return fp value    |      [fp, #-12]                      [|  saved r10 value    |]                      [|  saved r9 value     |]                      [|  saved r8 value     |]                      [|  saved r7 value     |]                      [|  saved r6 value     |]                      [|  saved r5 value     |]                      [|  saved r4 value     |]                      [|  saved r3 value     |]                      [|  saved r2 value     |]                      [|  saved r1 value     |]                      [|  saved r0 value     |]                      [|  saved f7 value     |]     three words                      [|  saved f6 value     |]     three words                      [|  saved f5 value     |]     three words                      [|  saved f4 value     |]     three words   r0-r3 are not normally saved in a C function.  */
end_comment

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{                        \   0,0,0,0,0,0,0,0,	 \   0,0,0,0,0,1,0,1,	 \   0,0,0,0,0,0,0,0,	 \   1,1,1			 \ }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.    The CC is not preserved over function calls on the ARM 6, so it is     easier to assume this for all.  SFP is preserved, since FP is. */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{                            \   1,1,1,1,0,0,0,0,	     \   0,0,0,0,1,1,1,1,	     \   1,1,1,1,0,0,0,0,	     \   1,1,1			     \ }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CONDITIONAL_REGISTER_USAGE
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CONDITIONAL_REGISTER_USAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{								\   int regno;							\ 								\   if (TARGET_SOFT_FLOAT || TARGET_THUMB)			\     {								\       for (regno = FIRST_ARM_FP_REGNUM;				\ 	   regno<= LAST_ARM_FP_REGNUM; ++regno)		\ 	fixed_regs[regno] = call_used_regs[regno] = 1;		\     }								\   if (flag_pic)							\     {								\       fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;			\       call_used_regs[PIC_OFFSET_TABLE_REGNUM] = 1;		\     }								\   else if (TARGET_APCS_STACK)					\     {								\       fixed_regs[10]     = 1;					\       call_used_regs[10] = 1;					\     }								\   if (TARGET_APCS_FRAME)					\     {								\       fixed_regs[ARM_HARD_FRAME_POINTER_REGNUM] = 1;		\       call_used_regs[ARM_HARD_FRAME_POINTER_REGNUM] = 1;	\     }								\   SUBTARGET_CONDITIONAL_REGISTER_USAGE				\ }
end_define

begin_comment
comment|/* These are a couple of extensions to the formats accecpted    by asm_fprintf:      %@ prints out ASM_COMMENT_START      %r prints out REGISTER_PREFIX reg_names[arg]  */
end_comment

begin_define
define|#
directive|define
name|ASM_FPRINTF_EXTENSIONS
parameter_list|(
name|FILE
parameter_list|,
name|ARGS
parameter_list|,
name|P
parameter_list|)
define|\
value|case '@':						\     fputs (ASM_COMMENT_START, FILE);			\     break;						\ 							\   case 'r':						\     fputs (REGISTER_PREFIX, FILE);			\     fputs (reg_names [va_arg (ARGS, int)], FILE);	\     break;
end_define

begin_comment
comment|/* Round X up to the nearest word.  */
end_comment

begin_define
define|#
directive|define
name|ROUND_UP
parameter_list|(
name|X
parameter_list|)
value|(((X) + 3)& ~3)
end_define

begin_comment
comment|/* Convert fron bytes to ints.  */
end_comment

begin_define
define|#
directive|define
name|NUM_INTS
parameter_list|(
name|X
parameter_list|)
value|(((X) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* The number of (integer) registers required to hold a quantity of type MODE.  */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|NUM_INTS (GET_MODE_SIZE (MODE))
end_define

begin_comment
comment|/* The number of (integer) registers required to hold a quantity of TYPE MODE.  */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS2
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|NUM_INTS ((MODE) == BLKmode ? 		\   int_size_in_bytes (TYPE) : GET_MODE_SIZE (MODE))
end_define

begin_comment
comment|/* The number of (integer) argument register available.  */
end_comment

begin_define
define|#
directive|define
name|NUM_ARG_REGS
value|4
end_define

begin_comment
comment|/* Return the regiser number of the N'th (integer) argument.  */
end_comment

begin_define
define|#
directive|define
name|ARG_REGISTER
parameter_list|(
name|N
parameter_list|)
value|(N - 1)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* FIXME: The ARM backend has special code to handle structure 	 returns, and will reserve its own hidden first argument.  So 	 if this macro is enabled a *second* hidden argument will be 	 reserved, which will break binary compatibility with old 	 toolchains and also thunk handling.  One day this should be 	 fixed.  */
end_comment

begin_comment
comment|/* RTX for structure returns.  NULL means use a hidden first argument.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Register in which address to store a structure value    is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|ARG_REGISTER (1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* The number of the last argument register.  */
end_comment

begin_define
define|#
directive|define
name|LAST_ARG_REGNUM
value|ARG_REGISTER (NUM_ARG_REGS)
end_define

begin_comment
comment|/* The number of the last "lo" register (thumb).  */
end_comment

begin_define
define|#
directive|define
name|LAST_LO_REGNUM
value|7
end_define

begin_comment
comment|/* The register that holds the return address in exception handlers.  */
end_comment

begin_define
define|#
directive|define
name|EXCEPTION_LR_REGNUM
value|2
end_define

begin_comment
comment|/* The native (Norcroft) Pascal compiler for the ARM passes the static chain    as an invisible last argument (possible since varargs don't exist in    Pascal), so the following is not true.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|(TARGET_ARM ? 12 : 9)
end_define

begin_comment
comment|/* Define this to be where the real frame pointer is if it is not possible to    work out the offset between the frame pointer and the automatic variables    until after register allocation has taken place.  FRAME_POINTER_REGNUM    should point to a special register that we will make sure is eliminated.     For the Thumb we have another problem.  The TPCS defines the frame pointer    as r11, and GCC belives that it is always possible to use the frame pointer    as base register for addressing purposes.  (See comments in    find_reloads_address()).  But - the Thumb does not allow high registers,    including r11, to be used as base address registers.  Hence our problem.     The solution used here, and in the old thumb port is to use r7 instead of    r11 as the hard frame pointer and to have special code to generate    backtrace structures on the stack (if required to do so via a command line    option) using r11.  This is the only 'user visable' use of r11 as a frame    pointer.  */
end_comment

begin_define
define|#
directive|define
name|ARM_HARD_FRAME_POINTER_REGNUM
value|11
end_define

begin_define
define|#
directive|define
name|THUMB_HARD_FRAME_POINTER_REGNUM
value|7
end_define

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
define|\
value|(TARGET_ARM					\    ? ARM_HARD_FRAME_POINTER_REGNUM		\    : THUMB_HARD_FRAME_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|FP_REGNUM
value|HARD_FRAME_POINTER_REGNUM
end_define

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|SP_REGNUM
end_define

begin_comment
comment|/* ARM floating pointer registers.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_ARM_FP_REGNUM
value|16
end_define

begin_define
define|#
directive|define
name|LAST_ARM_FP_REGNUM
value|23
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|25
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|26
end_define

begin_comment
comment|/* The number of hard registers is 16 ARM + 8 FPU + 1 CC + 1 SFP.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|27
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms may be accessed    via the stack pointer) in functions that seem suitable.      If we have to have a frame pointer we might as well make use of it.    APCS says that the frame pointer does not need to be pushed in leaf    functions, or simple tail call functions.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
define|\
value|(current_function_has_nonlocal_label				\    || (TARGET_ARM&& TARGET_APCS_FRAME&& ! leaf_function_p ()))
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the ARM regs are UNITS_PER_WORD bits wide; FPU regs can hold any FP    mode.  */
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
value|((TARGET_ARM 				\&& REGNO>= FIRST_ARM_FP_REGNUM	\&& REGNO != FRAME_POINTER_REGNUM	\&& REGNO != ARG_POINTER_REGNUM)	\    ? 1 : NUM_REGS (MODE))
end_define

begin_comment
comment|/* Return true if REGNO is suitable for holding a quantity of type MODE.  */
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
value|arm_hard_regno_mode_ok ((REGNO), (MODE))
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
value|(GET_MODE_CLASS (MODE1) == GET_MODE_CLASS (MODE2))
end_define

begin_comment
comment|/* The order in which register should be allocated.  It is good to use ip    since no saving is required (though calls clobber it) and it never contains    function parameters.  It is quite good to use lr since other calls may    clobber it anyway.  Allocate r0 through r3 in reverse order since r3 is     least likely to contain a function parameter; in addition results are    returned in r0.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{                                   \      3,  2,  1,  0, 12, 14,  4,  5, \      6,  7,  8, 10,  9, 11, 13, 15, \     16, 17, 18, 19, 20, 21, 22, 23, \     24, 25, 26			    \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Register and constant classes.  */
end_comment

begin_comment
comment|/* Register classes: used to be simple, just all ARM regs or all FPU regs    Now that the Thumb is involved it has become more complicated.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|FPU_REGS
block|,
name|LO_REGS
block|,
name|STACK_REG
block|,
name|BASE_REGS
block|,
name|HI_REGS
block|,
name|CC_REG
block|,
name|GENERAL_REGS
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
value|{			\   "NO_REGS",		\   "FPU_REGS",		\   "LO_REGS",		\   "STACK_REG",		\   "BASE_REGS",		\   "HI_REGS",		\   "CC_REG",		\   "GENERAL_REGS",	\   "ALL_REGS",		\ }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{					\   { 0x0000000 },
comment|/* NO_REGS  */
value|\   { 0x0FF0000 },
comment|/* FPU_REGS */
value|\   { 0x00000FF },
comment|/* LO_REGS */
value|\   { 0x0002000 },
comment|/* STACK_REG */
value|\   { 0x00020FF },
comment|/* BASE_REGS */
value|\   { 0x000FF00 },
comment|/* HI_REGS */
value|\   { 0x1000000 },
comment|/* CC_REG */
value|\   { 0x200FFFF },
comment|/* GENERAL_REGS */
value|\   { 0x2FFFFFF }
comment|/* ALL_REGS */
value|\ }
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
value|arm_regno_class (REGNO)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|(TARGET_THUMB ? LO_REGS : GENERAL_REGS)
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|(TARGET_THUMB ? BASE_REGS : GENERAL_REGS)
end_define

begin_comment
comment|/* For the Thumb the high registers cannot be used as base    registers when addressing quanitities in QI or HI mode.  */
end_comment

begin_define
define|#
directive|define
name|MODE_BASE_REG_CLASS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARM ? BASE_REGS :						\      (((MODE) == QImode || (MODE) == HImode || (MODE) == VOIDmode)	\      ? LO_REGS : BASE_REGS))
end_define

begin_comment
comment|/* When SMALL_REGISTER_CLASSES is nonzero, the compiler allows    registers explicitly used in the rtl to be used as spill registers    but prevents the compiler from extending the lifetime of these    registers. */
end_comment

begin_define
define|#
directive|define
name|SMALL_REGISTER_CLASSES
value|TARGET_THUMB
end_define

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine description.    We only need constraint `f' for FPU_REGS (`r' == GENERAL_REGS) for the    ARM, but several more letters for the Thumb.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|(  (C) == 'f' ? FPU_REGS		\    : (C) == 'l' ? (TARGET_ARM ? GENERAL_REGS : LO_REGS)	\    : TARGET_ARM ? NO_REGS		\    : (C) == 'h' ? HI_REGS		\    : (C) == 'b' ? BASE_REGS		\    : (C) == 'k' ? STACK_REG		\    : (C) == 'c' ? CC_REG		\    : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C. 	I: immediate arithmetic operand (i.e. 8 bits shifted as required). 	J: valid indexing constants.   	K: ~value ok in rhs argument of data operand. 	L: -value ok in rhs argument of data operand.          M: 0..32, or a power of 2  (for shifts, or mult done by shift).  */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_ARM_LETTER
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'I' ? const_ok_for_arm (VALUE) :		\    (C) == 'J' ? ((VALUE)< 4096&& (VALUE)> -4096) :	\    (C) == 'K' ? (const_ok_for_arm (~(VALUE))) :		\    (C) == 'L' ? (const_ok_for_arm (-(VALUE))) :		\    (C) == 'M' ? (((VALUE>= 0&& VALUE<= 32))		\ 		 || (((VALUE)& ((VALUE) - 1)) == 0))	\    : 0)
end_define

begin_define
define|#
directive|define
name|CONST_OK_FOR_THUMB_LETTER
parameter_list|(
name|VAL
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'I' ? (unsigned HOST_WIDE_INT) (VAL)< 256 :	\    (C) == 'J' ? (VAL)> -256&& (VAL)< 0 :		\    (C) == 'K' ? thumb_shiftable_const (VAL) :		\    (C) == 'L' ? (VAL)> -8&& (VAL)< 8	:		\    (C) == 'M' ? ((unsigned HOST_WIDE_INT) (VAL)< 1024	\&& ((VAL)& 3) == 0) :		\    (C) == 'N' ? ((unsigned HOST_WIDE_INT) (VAL)< 32) :	\    (C) == 'O' ? ((VAL)>= -508&& (VAL)<= 508)		\    : 0)
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
value|(TARGET_ARM ?								\    CONST_OK_FOR_ARM_LETTER (VALUE, C) : CONST_OK_FOR_THUMB_LETTER (VALUE, C))
end_define

begin_comment
comment|/* Constant letter 'G' for the FPU immediate constants.     'H' means the same constant negated.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_ARM_LETTER
parameter_list|(
name|X
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'G' ? const_double_rtx_ok_for_fpu (X) :		\      (C) == 'H' ? neg_const_double_rtx_ok_for_fpu (X) : 0)
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|X
parameter_list|,
name|C
parameter_list|)
define|\
value|(TARGET_ARM ?							\    CONST_DOUBLE_OK_FOR_ARM_LETTER (X, C) : 0)
end_define

begin_comment
comment|/* For the ARM, `Q' means that this is a memory operand that is just    an offset from a register.      `S' means any symbol that has the SYMBOL_REF_FLAG set or a CONSTANT_POOL    address.  This means that the symbol is in the text segment and can be    accessed without using a load. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_ARM
parameter_list|(
name|OP
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'Q' ? GET_CODE (OP) == MEM&& GET_CODE (XEXP (OP, 0)) == REG :    \    (C) == 'R' ? (GET_CODE (OP) == MEM					    \&& GET_CODE (XEXP (OP, 0)) == SYMBOL_REF		    \&& CONSTANT_POOL_ADDRESS_P (XEXP (OP, 0))) :		    \    (C) == 'S' ? (optimize> 0&& CONSTANT_ADDRESS_P (OP))		    \    : 0)
end_define

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_THUMB
parameter_list|(
name|X
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'Q' ? (GET_CODE (X) == MEM					\&& GET_CODE (XEXP (X, 0)) == LABEL_REF) : 0)
end_define

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT
parameter_list|(
name|X
parameter_list|,
name|C
parameter_list|)
define|\
value|(TARGET_ARM ?								\    EXTRA_CONSTRAINT_ARM (X, C) : EXTRA_CONSTRAINT_THUMB (X, C))
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS, but for the Thumb we prefer    a LO_REGS class or a subset.  */
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
value|(TARGET_ARM ? (CLASS) :			\    ((CLASS) == BASE_REGS ? (CLASS) : LO_REGS))
end_define

begin_comment
comment|/* Must leave BASE_REGS reloads alone */
end_comment

begin_define
define|#
directive|define
name|THUMB_SECONDARY_INPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|((CLASS) != LO_REGS&& (CLASS) != BASE_REGS				\    ? ((true_regnum (X) == -1 ? LO_REGS					\        : (true_regnum (X) + HARD_REGNO_NREGS (0, MODE)> 8) ? LO_REGS	\        : NO_REGS)) 							\    : NO_REGS)
end_define

begin_define
define|#
directive|define
name|THUMB_SECONDARY_OUTPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|((CLASS) != LO_REGS				 			\    ? ((true_regnum (X) == -1 ? LO_REGS					\        : (true_regnum (X) + HARD_REGNO_NREGS (0, MODE)> 8) ? LO_REGS	\        : NO_REGS)) 							\    : NO_REGS)
end_define

begin_comment
comment|/* Return the register class of a scratch register needed to copy IN into    or out of a register in CLASS in MODE.  If it can be done directly,    NO_REGS is returned.  */
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
name|X
parameter_list|)
define|\
value|(TARGET_ARM ?							\    (((MODE) == HImode&& ! arm_arch4&& true_regnum (X) == -1)	\     ? GENERAL_REGS : NO_REGS)					\    : THUMB_SECONDARY_OUTPUT_RELOAD_CLASS (CLASS, MODE, X))
end_define

begin_comment
comment|/* If we need to load shorts byte-at-a-time, then we need a scratch. */
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
name|X
parameter_list|)
define|\
value|(TARGET_ARM ?							\    (((MODE) == HImode&& ! arm_arch4&& TARGET_MMU_TRAPS	\&& (GET_CODE (X) == MEM					\ 	 || ((GET_CODE (X) == REG || GET_CODE (X) == SUBREG)	\&& true_regnum (X) == -1)))			\     ? GENERAL_REGS : NO_REGS)					\    : THUMB_SECONDARY_INPUT_RELOAD_CLASS (CLASS, MODE, X))
end_define

begin_comment
comment|/* Try a machine-dependent way of reloading an illegitimate address    operand.  If we find one, push the reload and jump to WIN.  This    macro is used in only one place: `find_reloads_address' in reload.c.     For the ARM, we wish to handle large displacements off a base    register by splitting the addend across a MOV and the mem insn.    This can cut the number of reloads needed.  */
end_comment

begin_define
define|#
directive|define
name|ARM_LEGITIMIZE_RELOAD_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|,
name|OPNUM
parameter_list|,
name|TYPE
parameter_list|,
name|IND
parameter_list|,
name|WIN
parameter_list|)
define|\
value|do									   \     {									   \       if (GET_CODE (X) == PLUS						   \&& GET_CODE (XEXP (X, 0)) == REG				   \&& REGNO (XEXP (X, 0))< FIRST_PSEUDO_REGISTER		   \&& REG_MODE_OK_FOR_BASE_P (XEXP (X, 0), MODE)			   \&& GET_CODE (XEXP (X, 1)) == CONST_INT)			   \ 	{								   \ 	  HOST_WIDE_INT val = INTVAL (XEXP (X, 1));			   \ 	  HOST_WIDE_INT low, high;					   \ 									   \ 	  if (MODE == DImode || (TARGET_SOFT_FLOAT&& MODE == DFmode))	   \ 	    low = ((val& 0xf) ^ 0x8) - 0x8;				   \ 	  else if (MODE == SImode					   \ 		   || (MODE == SFmode&& TARGET_SOFT_FLOAT)		   \ 		   || ((MODE == HImode || MODE == QImode)&& ! arm_arch4)) \
comment|/* Need to be careful, -4096 is not a valid offset.  */
value|\ 	    low = val>= 0 ? (val& 0xfff) : -((-val)& 0xfff);		   \ 	  else if ((MODE == HImode || MODE == QImode)&& arm_arch4)	   \
comment|/* Need to be careful, -256 is not a valid offset.  */
value|\ 	    low = val>= 0 ? (val& 0xff) : -((-val)& 0xff);		   \ 	  else if (GET_MODE_CLASS (MODE) == MODE_FLOAT			   \&& TARGET_HARD_FLOAT)				   \
comment|/* Need to be careful, -1024 is not a valid offset.  */
value|\ 	    low = val>= 0 ? (val& 0x3ff) : -((-val)& 0x3ff);		   \ 	  else								   \ 	    break;							   \ 									   \ 	  high = ((((val - low)& (unsigned HOST_WIDE_INT) 0xffffffff)	   \ 		   ^ (unsigned HOST_WIDE_INT) 0x80000000)		   \ 		  - (unsigned HOST_WIDE_INT) 0x80000000);		   \
comment|/* Check for overflow or zero */
value|\ 	  if (low == 0 || high == 0 || (high + low != val))		   \ 	    break;							   \ 									   \
comment|/* Reload the high part into a base reg; leave the low part	   \ 	     in the mem.  */
value|\ 	  X = gen_rtx_PLUS (GET_MODE (X),				   \ 			    gen_rtx_PLUS (GET_MODE (X), XEXP (X, 0),	   \ 					  GEN_INT (high)),		   \ 			    GEN_INT (low));				   \ 	  push_reload (XEXP (X, 0), NULL_RTX,&XEXP (X, 0), NULL,	   \ 		       MODE_BASE_REG_CLASS (MODE), GET_MODE (X), 	   \ 		       VOIDmode, 0, 0, OPNUM, TYPE);			   \ 	  goto WIN;							   \ 	}								   \     }									   \   while (0)
end_define

begin_comment
comment|/* ??? If an HImode FP+large_offset address is converted to an HImode    SP+large_offset address, then reload won't know how to fix it.  It sees    only that SP isn't valid for HImode, and so reloads the SP into an index    register, but the resulting address is still invalid because the offset    is too big.  We fix it here instead by reloading the entire address.  */
end_comment

begin_comment
comment|/* We could probably achieve better results by defining PROMOTE_MODE to help    cope with the variances between the Thumb's signed and unsigned byte and    halfword load instructions.  */
end_comment

begin_define
define|#
directive|define
name|THUMB_LEGITIMIZE_RELOAD_ADDRESS
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
value|{									\   if (GET_CODE (X) == PLUS						\&& GET_MODE_SIZE (MODE)< 4					\&& GET_CODE (XEXP (X, 0)) == REG					\&& XEXP (X, 0) == stack_pointer_rtx				\&& GET_CODE (XEXP (X, 1)) == CONST_INT				\&& ! THUMB_LEGITIMATE_OFFSET (MODE, INTVAL (XEXP (X, 1))))	\     {									\       rtx orig_X = X;							\       X = copy_rtx (X);							\       push_reload (orig_X, NULL_RTX,&X, NULL,				\ 		   MODE_BASE_REG_CLASS (MODE),				\ 		   Pmode, VOIDmode, 0, 0, OPNUM, TYPE);			\       goto WIN;								\     }									\ }
end_define

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
value|if (TARGET_ARM)							   \     ARM_LEGITIMIZE_RELOAD_ADDRESS (X, MODE, OPNUM, TYPE, IND_LEVELS, WIN); \   else									   \     THUMB_LEGITIMIZE_RELOAD_ADDRESS (X, MODE, OPNUM, TYPE, IND_LEVELS, WIN)
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.    ARM regs are UNITS_PER_WORD bits while FPU regs can hold any FP mode */
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
value|((CLASS) == FPU_REGS ? 1 : NUM_REGS (MODE))
end_define

begin_comment
comment|/* Moves between FPU_REGS and GENERAL_REGS are two memory insns.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|(TARGET_ARM ?						\    ((FROM) == FPU_REGS&& (TO) != FPU_REGS ? 20 :	\     (FROM) != FPU_REGS&& (TO) == FPU_REGS ? 20 : 2)	\    :							\    ((FROM) == HI_REGS || (TO) == HI_REGS) ? 4 : 2)
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
value|1
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
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
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.  */
end_comment

begin_comment
comment|/* The push insns do not do this rounding implicitly.    So don't define this. */
end_comment

begin_comment
comment|/* #define PUSH_ROUNDING(NPUSHED)  ROUND_UP (NPUSHED) */
end_comment

begin_comment
comment|/* Define this if the maximum size of all the outgoing args is to be    accumulated and pushed during the prologue.  The amount can be    found in the variable current_function_outgoing_args_size.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
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
value|(TARGET_ARM ? 4 : 0)
end_define

begin_comment
comment|/* Value is the number of byte of arguments automatically    popped when returning from a subroutine call.    FUNDECL is the declaration node of the function (as a tree),    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.     On the ARM, the caller does not pop any of its arguments that were passed    on the stack.  */
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
value|(TARGET_ARM&& TARGET_HARD_FLOAT&& GET_MODE_CLASS (MODE) == MODE_FLOAT \    ? gen_rtx_REG (MODE, FIRST_ARM_FP_REGNUM) \    : gen_rtx_REG (MODE, ARG_REGISTER (1)))
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
value|LIBCALL_VALUE (TYPE_MODE (VALTYPE))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the ARM, only r0 and f0 can return results.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO) == ARG_REGISTER (1) \    || (TARGET_ARM&& ((REGNO) == FIRST_ARM_FP_REGNUM)&& TARGET_HARD_FLOAT))
end_define

begin_comment
comment|/* How large values are returned */
end_comment

begin_comment
comment|/* A C expression which can inhibit the returning of certain function values    in registers, based on the type of value. */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
value|arm_return_in_memory (TYPE)
end_define

begin_comment
comment|/* Define DEFAULT_PCC_STRUCT_RETURN to 1 if all structure and union return    values must be in memory.  On the ARM, they need only do so if larger    than a word, or if they contain elements offset from zero in the struct. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* Flags for the call/call_value rtl operations set up by function_arg.  */
end_comment

begin_define
define|#
directive|define
name|CALL_NORMAL
value|0x00000000
end_define

begin_comment
comment|/* No special processing.  */
end_comment

begin_define
define|#
directive|define
name|CALL_LONG
value|0x00000001
end_define

begin_comment
comment|/* Always call indirect.  */
end_comment

begin_define
define|#
directive|define
name|CALL_SHORT
value|0x00000002
end_define

begin_comment
comment|/* Never call indirect.  */
end_comment

begin_comment
comment|/* These bits describe the different types of function supported    by the ARM backend.  They are exclusive.  ie a function cannot be both a    normal function and an interworked function, for example.  Knowing the    type of a function is important for determining its prologue and    epilogue sequences.    Note value 7 is currently unassigned.  Also note that the interrupt    function types all have bit 2 set, so that they can be tested for easily.    Note that 0 is deliberately chosen for ARM_FT_UNKNOWN so that when the    machine_function structure is initialised (to zero) func_type will    default to unknown.  This will force the first use of arm_current_func_type    to call arm_compute_func_type.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_UNKNOWN
value|0
end_define

begin_comment
comment|/* Type has not yet been determined.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_NORMAL
value|1
end_define

begin_comment
comment|/* Your normal, straightforward function.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_INTERWORKED
value|2
end_define

begin_comment
comment|/* A function that supports interworking.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_EXCEPTION_HANDLER
value|3
end_define

begin_comment
comment|/* A C++ exception handler.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_ISR
value|4
end_define

begin_comment
comment|/* An interrupt service routine.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_FIQ
value|5
end_define

begin_comment
comment|/* A fast interrupt service routine.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_EXCEPTION
value|6
end_define

begin_comment
comment|/* An ARM exception handler (subcase of ISR).  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_TYPE_MASK
value|((1<< 3) - 1)
end_define

begin_comment
comment|/* In addition functions can have several type modifiers,    outlined by these bit masks:  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_INTERRUPT
value|(1<< 2)
end_define

begin_comment
comment|/* Note overlap with FT_ISR and above.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_NAKED
value|(1<< 3)
end_define

begin_comment
comment|/* No prologue or epilogue.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_VOLATILE
value|(1<< 4)
end_define

begin_comment
comment|/* Does not return.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FT_NESTED
value|(1<< 5)
end_define

begin_comment
comment|/* Embedded inside another func. */
end_comment

begin_comment
comment|/* Some macros to test these flags.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FUNC_TYPE
parameter_list|(
name|t
parameter_list|)
value|(t& ARM_FT_TYPE_MASK)
end_define

begin_define
define|#
directive|define
name|IS_INTERRUPT
parameter_list|(
name|t
parameter_list|)
value|(t& ARM_FT_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|IS_VOLATILE
parameter_list|(
name|t
parameter_list|)
value|(t& ARM_FT_VOLATILE)
end_define

begin_define
define|#
directive|define
name|IS_NAKED
parameter_list|(
name|t
parameter_list|)
value|(t& ARM_FT_NAKED)
end_define

begin_define
define|#
directive|define
name|IS_NESTED
parameter_list|(
name|t
parameter_list|)
value|(t& ARM_FT_NESTED)
end_define

begin_comment
comment|/* A C structure for machine-specific, per-function data.    This is added to the cfun structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|machine_function
block|{
comment|/* Additionsl stack adjustment in __builtin_eh_throw.  */
name|struct
name|rtx_def
modifier|*
name|eh_epilogue_sp_ofs
decl_stmt|;
comment|/* Records if LR has to be saved for far jumps.  */
name|int
name|far_jump_used
decl_stmt|;
comment|/* Records if ARG_POINTER was ever live.  */
name|int
name|arg_pointer_live
decl_stmt|;
comment|/* Records if the save of LR has been eliminated.  */
name|int
name|lr_save_eliminated
decl_stmt|;
comment|/* Records the type of the current function.  */
name|unsigned
name|long
name|func_type
decl_stmt|;
block|}
name|machine_function
typedef|;
end_typedef

begin_comment
comment|/* A C type for declaring a variable that is used as the first argument of    `FUNCTION_ARG' and other related values.  For some target machines, the    type `int' suffices and can hold the number of bytes of argument so far.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* This is the number of registers of arguments scanned so far.  */
name|int
name|nregs
decl_stmt|;
comment|/* One of CALL_NORMAL, CALL_LONG or CALL_SHORT . */
name|int
name|call_cookie
decl_stmt|;
block|}
name|CUMULATIVE_ARGS
typedef|;
end_typedef

begin_comment
comment|/* Define where to put the arguments to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On the ARM, normally the first 16 bytes are passed in registers r0-r3; all    other arguments are passed on the stack.  If (NAMED == 0) (which happens    only in assign_parms, since SETUP_INCOMING_VARARGS is defined), say it is    passed in the stack (function_prologue will indeed make it pass in the    stack if necessary).  */
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
value|arm_function_arg (&(CUM), (MODE), (TYPE), (NAMED))
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
value|(    NUM_ARG_REGS> (CUM).nregs				\&& (NUM_ARG_REGS< ((CUM).nregs + NUM_REGS2 (MODE, TYPE)))	\    ?   NUM_ARG_REGS - (CUM).nregs : 0)
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.    On the ARM, the offset starts at 0.  */
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
value|arm_init_cumulative_args (&(CUM), (FNTYPE), (LIBNAME), (INDIRECT))
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
value|(CUM).nregs += NUM_REGS2 (MODE, TYPE)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On the ARM, r0-r3 are used to pass args.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
value|(IN_RANGE ((REGNO), 0, 3))
end_define

begin_escape
end_escape

begin_comment
comment|/* Tail calling.  */
end_comment

begin_comment
comment|/* A C expression that evaluates to true if it is ok to perform a sibling    call to DECL.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_OK_FOR_SIBCALL
parameter_list|(
name|DECL
parameter_list|)
value|arm_function_ok_for_sibcall ((DECL))
end_define

begin_comment
comment|/* Perform any actions needed for a function that is receiving a variable    number of arguments.  CUM is as above.  MODE and TYPE are the mode and type    of the current parameter.  PRETEND_SIZE is a variable that should be set to    the amount of stack that must be pushed by the prolog to pretend that our    caller pushed it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.     On the ARM, PRETEND_SIZE is set in order to have the prologue push the last    named arg and all anonymous args onto the stack.    XXX I know the prologue shouldn't be pushing registers, but it is faster    that way.  */
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
value|{									\   extern int current_function_anonymous_args;				\   current_function_anonymous_args = 1;					\   if ((CUM).nregs< NUM_ARG_REGS)					\     (PRETEND_SIZE) = (NUM_ARG_REGS - (CUM).nregs) * UNITS_PER_WORD;	\ }
end_define

begin_comment
comment|/* If your target environment doesn't prefix user functions with an    underscore, you may wish to re-define this to prevent any conflicts.    e.g. AOF may prefix mcount with an underscore.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_MCOUNT_NAME
end_ifndef

begin_define
define|#
directive|define
name|ARM_MCOUNT_NAME
value|"*mcount"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Call the function profiler with a given profile label.  The Acorn    compiler puts this BEFORE the prolog but gcc puts it afterwards.    On the ARM the full profile code will look like: 	.data 	LP1 		.word	0 	.text 		mov	ip, lr 		bl	mcount 		.word	LP1     profile_function() in final.c outputs the .data section, FUNCTION_PROFILER    will output the .text section.     The ``mov ip,lr'' seems like a good idea to stick with cc convention.    ``prof'' doesn't seem to mind about this!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_FUNCTION_PROFILER
end_ifndef

begin_define
define|#
directive|define
name|ARM_FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{							\   char temp[20];					\   rtx sym;						\ 							\   asm_fprintf (STREAM, "\tmov\t%r, %r\n\tbl\t",		\ 	   IP_REGNUM, LR_REGNUM);			\   assemble_name (STREAM, ARM_MCOUNT_NAME);		\   fputc ('\n', STREAM);					\   ASM_GENERATE_INTERNAL_LABEL (temp, "LP", LABELNO);	\   sym = gen_rtx (SYMBOL_REF, Pmode, temp);		\   assemble_aligned_integer (UNITS_PER_WORD, sym);	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|THUMB_FUNCTION_PROFILER
end_ifndef

begin_define
define|#
directive|define
name|THUMB_FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{							\   fprintf (STREAM, "\tmov\tip, lr\n");			\   fprintf (STREAM, "\tbl\tmcount\n");			\   fprintf (STREAM, "\t.word\tLP%d\n", LABELNO);		\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|if (TARGET_ARM)					\     ARM_FUNCTION_PROFILER (STREAM, LABELNO)		\   else							\     THUMB_FUNCTION_PROFILER (STREAM, LABELNO)
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.     On the ARM, the function epilogue recovers the stack pointer from the    frame.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_define
define|#
directive|define
name|EPILOGUE_USES
parameter_list|(
name|REGNO
parameter_list|)
value|(reload_completed&& (REGNO) == LR_REGNUM)
end_define

begin_comment
comment|/* Determine if the epilogue should be output as RTL.    You should override this if you define FUNCTION_EXTRA_EPILOGUE.  */
end_comment

begin_define
define|#
directive|define
name|USE_RETURN_INSN
parameter_list|(
name|ISCOND
parameter_list|)
define|\
value|(TARGET_ARM ? use_return_insn (ISCOND) : 0)
end_define

begin_comment
comment|/* Definitions for register eliminations.     This is an array of structures.  Each structure initializes one pair    of eliminable registers.  The "from" register number is given first,    followed by "to".  Eliminations of the same "from" register are listed    in order of preference.     We have two registers that can be eliminated on the ARM.  First, the    arg pointer register can often be eliminated in favor of the stack    pointer register.  Secondly, the pseudo frame pointer register can always    be eliminated; it is replaced with either the stack or the real frame    pointer.  Note we have to use {ARM|THUMB}_HARD_FRAME_POINTER_REGNUM    because the definition of HARD_FRAME_POINTER_REGNUM is not a constant.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ ARG_POINTER_REGNUM,        STACK_POINTER_REGNUM            },\  { ARG_POINTER_REGNUM,        FRAME_POINTER_REGNUM            },\  { ARG_POINTER_REGNUM,        ARM_HARD_FRAME_POINTER_REGNUM   },\  { ARG_POINTER_REGNUM,        THUMB_HARD_FRAME_POINTER_REGNUM },\  { FRAME_POINTER_REGNUM,      STACK_POINTER_REGNUM            },\  { FRAME_POINTER_REGNUM,      ARM_HARD_FRAME_POINTER_REGNUM   },\  { FRAME_POINTER_REGNUM,      THUMB_HARD_FRAME_POINTER_REGNUM }}
end_define

begin_comment
comment|/* Given FROM and TO register numbers, say whether this elimination is    allowed.  Frame pointer elimination is automatically handled.     All eliminations are permissible.  Note that ARG_POINTER_REGNUM and    HARD_FRAME_POINTER_REGNUM are in fact the same thing.  If we need a frame    pointer, we must eliminate FRAME_POINTER_REGNUM into    HARD_FRAME_POINTER_REGNUM and not into STACK_POINTER_REGNUM or    ARG_POINTER_REGNUM.  */
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
value|(((TO) == FRAME_POINTER_REGNUM&& (FROM) == ARG_POINTER_REGNUM) ? 0 :	\    ((TO) == STACK_POINTER_REGNUM&& frame_pointer_needed) ? 0 :		\    ((TO) == ARM_HARD_FRAME_POINTER_REGNUM&& TARGET_THUMB) ? 0 :	\    ((TO) == THUMB_HARD_FRAME_POINTER_REGNUM&& TARGET_ARM) ? 0 :	\    1)
end_define

begin_comment
comment|/* Define the offset between two registers, one to be eliminated, and the    other its replacement, at the start of a routine.  */
end_comment

begin_define
define|#
directive|define
name|ARM_INITIAL_ELIMINATION_OFFSET
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|do									\     {									\       (OFFSET) = arm_compute_initial_elimination_offset (FROM, TO);	\     }									\   while (0)
end_define

begin_comment
comment|/* Note:  This macro must match the code in thumb_function_prologue().  */
end_comment

begin_define
define|#
directive|define
name|THUMB_INITIAL_ELIMINATION_OFFSET
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|{									\   (OFFSET) = 0;								\   if ((FROM) == ARG_POINTER_REGNUM)					\     {									\       int count_regs = 0;						\       int regno;							\       for (regno = 8; regno< 13; regno ++)				\ 	if (regs_ever_live[regno]&& ! call_used_regs[regno])		\ 	  count_regs ++;						\       if (count_regs)							\ 	(OFFSET) += 4 * count_regs;					\       count_regs = 0;							\       for (regno = 0; regno<= LAST_LO_REGNUM; regno ++)		\ 	if (regs_ever_live[regno]&& ! call_used_regs[regno])		\ 	  count_regs ++;						\       if (count_regs || ! leaf_function_p () || thumb_far_jump_used_p (0))\ 	(OFFSET) += 4 * (count_regs + 1);				\       if (TARGET_BACKTRACE)						\         {								\ 	  if ((count_regs& 0xFF) == 0&& (regs_ever_live[3] != 0))	\ 	    (OFFSET) += 20;						\ 	  else								\ 	    (OFFSET) += 16;						\         }								\     }									\   if ((TO) == STACK_POINTER_REGNUM)					\     {									\       (OFFSET) += current_function_outgoing_args_size;			\       (OFFSET) += ROUND_UP (get_frame_size ());				\      }									\ }
end_define

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
value|if (TARGET_ARM)							\     ARM_INITIAL_ELIMINATION_OFFSET (FROM, TO, OFFSET);			\   else									\     THUMB_INITIAL_ELIMINATION_OFFSET (FROM, TO, OFFSET)
end_define

begin_comment
comment|/* Special case handling of the location of arguments passed on the stack.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGGER_ARG_OFFSET
parameter_list|(
name|value
parameter_list|,
name|addr
parameter_list|)
value|value ? value : arm_debugger_arg_offset (value, addr)
end_define

begin_comment
comment|/* Initialize data used by insn expanders.  This is called from insn_emit,    once for every function before code is generated.  */
end_comment

begin_define
define|#
directive|define
name|INIT_EXPANDERS
value|arm_init_expanders ()
end_define

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     On the ARM, (if r8 is the static chain regnum, and remembering that    referencing pc adds an offset of 8) the trampoline looks like: 	   ldr 		r8, [pc, #0] 	   ldr		pc, [pc] 	   .word	static chain value 	   .word	function's address    ??? FIXME: When the trampoline returns, r8 will be clobbered.  */
end_comment

begin_define
define|#
directive|define
name|ARM_TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{								\   asm_fprintf (FILE, "\tldr\t%r, [%r, #0]\n",			\ 	       STATIC_CHAIN_REGNUM, PC_REGNUM);			\   asm_fprintf (FILE, "\tldr\t%r, [%r, #0]\n",			\ 	       PC_REGNUM, PC_REGNUM);				\   assemble_aligned_integer (UNITS_PER_WORD, const0_rtx);	\   assemble_aligned_integer (UNITS_PER_WORD, const0_rtx);	\ }
end_define

begin_comment
comment|/* On the Thumb we always switch into ARM mode to execute the trampoline.    Why - because it is easier.  This code will always be branched to via    a BX instruction and since the compiler magically generates the address    of the function the linker has no opportunity to ensure that the    bottom bit is set.  Thus the processor will be in ARM mode when it    reaches this code.  So we duplicate the ARM trampoline code and add    a switch into Thumb mode as well.  */
end_comment

begin_define
define|#
directive|define
name|THUMB_TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{						\   fprintf (FILE, "\t.code 32\n");		\   fprintf (FILE, ".Ltrampoline_start:\n");	\   asm_fprintf (FILE, "\tldr\t%r, [%r, #8]\n",	\ 	       STATIC_CHAIN_REGNUM, PC_REGNUM);	\   asm_fprintf (FILE, "\tldr\t%r, [%r, #8]\n",	\ 	       IP_REGNUM, PC_REGNUM);		\   asm_fprintf (FILE, "\torr\t%r, %r, #1\n",     \ 	       IP_REGNUM, IP_REGNUM);     	\   asm_fprintf (FILE, "\tbx\t%r\n", IP_REGNUM);	\   fprintf (FILE, "\t.word\t0\n");		\   fprintf (FILE, "\t.word\t0\n");		\   fprintf (FILE, "\t.code 16\n");		\ }
end_define

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|if (TARGET_ARM)				\     ARM_TRAMPOLINE_TEMPLATE (FILE)		\   else						\     THUMB_TRAMPOLINE_TEMPLATE (FILE)
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|(TARGET_ARM ? 16 : 24)
end_define

begin_comment
comment|/* Alignment required for a trampoline in bits.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGNMENT
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
value|{											\   emit_move_insn									\     (gen_rtx_MEM (SImode, plus_constant (TRAMP, TARGET_ARM ? 8 : 16)), CXT);		\   emit_move_insn									\     (gen_rtx_MEM (SImode, plus_constant (TRAMP, TARGET_ARM ? 12 : 20)),	FNADDR);	\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POST_INCREMENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PRE_INCREMENT
value|TARGET_ARM
end_define

begin_define
define|#
directive|define
name|HAVE_POST_DECREMENT
value|TARGET_ARM
end_define

begin_define
define|#
directive|define
name|HAVE_PRE_DECREMENT
value|TARGET_ARM
end_define

begin_comment
comment|/* Macros to check register numbers against specific register classes.  */
end_comment

begin_comment
comment|/* These assume that REGNO is a hard or pseudo reg number.    They give nonzero only if REGNO is a hard reg of the suitable class    or a pseudo reg currently allocated to a suitable hard reg.    Since they use reg_renumber, they are safe only once reg_renumber    has been allocated, which happens in local-alloc.c. */
end_comment

begin_define
define|#
directive|define
name|TEST_REGNO
parameter_list|(
name|R
parameter_list|,
name|TEST
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|((R TEST VALUE) || ((unsigned) reg_renumber[R] TEST VALUE))
end_define

begin_comment
comment|/*   On the ARM, don't allow the pc to be used.  */
end_comment

begin_define
define|#
directive|define
name|ARM_REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(TEST_REGNO (REGNO,<, PC_REGNUM)			\    || TEST_REGNO (REGNO, ==, FRAME_POINTER_REGNUM)	\    || TEST_REGNO (REGNO, ==, ARG_POINTER_REGNUM))
end_define

begin_define
define|#
directive|define
name|THUMB_REGNO_MODE_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TEST_REGNO (REGNO,<=, LAST_LO_REGNUM)			\    || (GET_MODE_SIZE (MODE)>= 4				\&& TEST_REGNO (REGNO, ==, STACK_POINTER_REGNUM)))
end_define

begin_define
define|#
directive|define
name|REGNO_MODE_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TARGET_THUMB						\    ? THUMB_REGNO_MODE_OK_FOR_BASE_P (REGNO, MODE)	\    : ARM_REGNO_OK_FOR_BASE_P (REGNO))
end_define

begin_comment
comment|/* For ARM code, we don't care about the mode, but for Thumb, the index    must be suitable for use in a QImode load.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|REGNO_MODE_OK_FOR_BASE_P (REGNO, QImode)
end_define

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.    Shifts in addresses can't be by a register. */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|2
end_define

begin_comment
comment|/* Recognize any constant value that is a valid address.  */
end_comment

begin_comment
comment|/* XXX We can address any constant, eventually...  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AOF_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF&& CONSTANT_POOL_ADDRESS_P (X))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF 			\&& (CONSTANT_POOL_ADDRESS_P (X)		\        || (TARGET_ARM&& optimize> 0&& SYMBOL_REF_FLAG (X))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AOF_ASSEMBLER */
end_comment

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     On the ARM, allow any integer (invalid ones are removed later by insn    patterns), nice doubles and symbol_refs which refer to the function's    constant pool XXX.        When generating pic allow anything.  */
end_comment

begin_define
define|#
directive|define
name|ARM_LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
value|(flag_pic || ! label_mentioned_p (X))
end_define

begin_define
define|#
directive|define
name|THUMB_LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(   GET_CODE (X) == CONST_INT		\   || GET_CODE (X) == CONST_DOUBLE	\   || CONSTANT_ADDRESS_P (X))
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(TARGET_ARM ? ARM_LEGITIMATE_CONSTANT_P (X) : THUMB_LEGITIMATE_CONSTANT_P (X))
end_define

begin_comment
comment|/* Special characters prefixed to function names    in order to encode attribute like information.    Note, '@' and '*' have already been taken.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_CALL_FLAG_CHAR
value|'^'
end_define

begin_define
define|#
directive|define
name|LONG_CALL_FLAG_CHAR
value|'#'
end_define

begin_define
define|#
directive|define
name|ENCODED_SHORT_CALL_ATTR_P
parameter_list|(
name|SYMBOL_NAME
parameter_list|)
define|\
value|(*(SYMBOL_NAME) == SHORT_CALL_FLAG_CHAR)
end_define

begin_define
define|#
directive|define
name|ENCODED_LONG_CALL_ATTR_P
parameter_list|(
name|SYMBOL_NAME
parameter_list|)
define|\
value|(*(SYMBOL_NAME) == LONG_CALL_FLAG_CHAR)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_NAME_ENCODING_LENGTHS
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_NAME_ENCODING_LENGTHS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is a C fragement for the inside of a switch statement.    Each case label should return the number of characters to    be stripped from the start of a function's name, if that    name starts with the indicated character.  */
end_comment

begin_define
define|#
directive|define
name|ARM_NAME_ENCODING_LENGTHS
define|\
value|case SHORT_CALL_FLAG_CHAR: return 1;		\   case LONG_CALL_FLAG_CHAR:  return 1;		\   case '*':  return 1;				\   SUBTARGET_NAME_ENCODING_LENGTHS
end_define

begin_comment
comment|/* This has to be handled by a function because more than part of the    ARM backend uses function name prefixes to encode attributes.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRIP_NAME_ENCODING
end_undef

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|(VAR) = arm_strip_name_encoding (SYMBOL_NAME)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
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
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|asm_fprintf (FILE, "%U%s", arm_strip_name_encoding (NAME))
end_define

begin_comment
comment|/* If we are referencing a function that is weak then encode a long call    flag in the function name, otherwise if the function is static or    or known to be defined in this file then encode a short call flag.    This macro is used inside the ENCODE_SECTION macro.  */
end_comment

begin_define
define|#
directive|define
name|ARM_ENCODE_CALL_TYPE
parameter_list|(
name|decl
parameter_list|)
define|\
value|if (TREE_CODE (decl) == FUNCTION_DECL)				\     {									\       if (DECL_WEAK (decl))						\         arm_encode_call_attribute (decl, LONG_CALL_FLAG_CHAR);		\       else if (! TREE_PUBLIC (decl))        				\         arm_encode_call_attribute (decl, SHORT_CALL_FLAG_CHAR);		\     }
end_define

begin_comment
comment|/* Symbols in the text segment can be accessed without indirecting via the    constant pool; it may take an extra binary operation, but this is still    faster than indirecting via memory.  Don't do this when not optimizing,    since we won't be calculating al of the offsets necessary to do this    simplification.  */
end_comment

begin_comment
comment|/* This doesn't work with AOF syntax, since the string table may be in    a different AREA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AOF_ASSEMBLER
end_ifndef

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|decl
parameter_list|)
define|\
value|{									\   if (optimize> 0&& TREE_CONSTANT (decl)				\&& (!flag_writable_strings || TREE_CODE (decl) != STRING_CST))	\     {									\       rtx rtl = (TREE_CODE_CLASS (TREE_CODE (decl)) != 'd'		\                  ? TREE_CST_RTL (decl) : DECL_RTL (decl));		\       SYMBOL_REF_FLAG (XEXP (rtl, 0)) = 1;				\     }									\   ARM_ENCODE_CALL_TYPE (decl)						\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|decl
parameter_list|)
define|\
value|{									\   ARM_ENCODE_CALL_TYPE (decl)						\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|arm_encode_call_attribute (DECL, SHORT_CALL_FLAG_CHAR)
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_define
define|#
directive|define
name|ARM_REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)<= LAST_ARM_REGNUM			\    || REGNO (X)>= FIRST_PSEUDO_REGISTER	\    || REGNO (X) == FRAME_POINTER_REGNUM		\    || REGNO (X) == ARG_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|THUMB_REG_MODE_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(REGNO (X)<= LAST_LO_REGNUM			\    || REGNO (X)>= FIRST_PSEUDO_REGISTER	\    || (GET_MODE_SIZE (MODE)>= 4		\&& (REGNO (X) == STACK_POINTER_REGNUM	\ 	   || (X) == hard_frame_pointer_rtx	\ 	   || (X) == arg_pointer_rtx)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* REG_OK_STRICT */
end_comment

begin_define
define|#
directive|define
name|ARM_REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|ARM_REGNO_OK_FOR_BASE_P (REGNO (X))
end_define

begin_define
define|#
directive|define
name|THUMB_REG_MODE_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|THUMB_REGNO_MODE_OK_FOR_BASE_P (REGNO (X), MODE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REG_OK_STRICT */
end_comment

begin_comment
comment|/* Now define some helpers in terms of the above.  */
end_comment

begin_define
define|#
directive|define
name|REG_MODE_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TARGET_THUMB					\    ? THUMB_REG_MODE_OK_FOR_BASE_P (X, MODE)	\    : ARM_REG_OK_FOR_BASE_P (X))
end_define

begin_define
define|#
directive|define
name|ARM_REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|ARM_REG_OK_FOR_BASE_P (X)
end_define

begin_comment
comment|/* For Thumb, a valid index register is anything that can be used in    a byte load instruction.  */
end_comment

begin_define
define|#
directive|define
name|THUMB_REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|THUMB_REG_MODE_OK_FOR_BASE_P (X, QImode)
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index    or if it is a pseudo reg.  On the Thumb, the stack pointer    is not suitable.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(TARGET_THUMB					\    ? THUMB_REG_OK_FOR_INDEX_P (X)		\    : ARM_REG_OK_FOR_INDEX_P (X))
end_define

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS. */
end_comment

begin_comment
comment|/* --------------------------------arm version----------------------------- */
end_comment

begin_define
define|#
directive|define
name|ARM_BASE_REGISTER_RTX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& ARM_REG_OK_FOR_BASE_P (X))
end_define

begin_define
define|#
directive|define
name|ARM_INDEX_REGISTER_RTX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& ARM_REG_OK_FOR_INDEX_P (X))
end_define

begin_comment
comment|/* A C statement (sans semicolon) to jump to LABEL for legitimate index RTXs    used by the macro GO_IF_LEGITIMATE_ADDRESS.  Floating point indices can    only be small constants. */
end_comment

begin_define
define|#
directive|define
name|ARM_GO_IF_LEGITIMATE_INDEX
parameter_list|(
name|MODE
parameter_list|,
name|BASE_REGNO
parameter_list|,
name|INDEX
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|do									\     {									\       HOST_WIDE_INT range;						\       enum rtx_code code = GET_CODE (INDEX);				\ 									\       if (TARGET_HARD_FLOAT&& GET_MODE_CLASS (MODE) == MODE_FLOAT)	\ 	{								\ 	  if (code == CONST_INT&& INTVAL (INDEX)< 1024		\&& INTVAL (INDEX)> -1024					\&& (INTVAL (INDEX)& 3) == 0)				\ 	    goto LABEL;							\ 	}								\       else								\ 	{								\ 	  if (ARM_INDEX_REGISTER_RTX_P (INDEX)				\&& GET_MODE_SIZE (MODE)<= 4)				\ 	    goto LABEL;							\ 	  if (GET_MODE_SIZE (MODE)<= 4&& code == MULT		\&& (! arm_arch4 || (MODE) != HImode))			\ 	    {								\ 	      rtx xiop0 = XEXP (INDEX, 0);				\ 	      rtx xiop1 = XEXP (INDEX, 1);				\ 	      if (ARM_INDEX_REGISTER_RTX_P (xiop0)			\&& power_of_two_operand (xiop1, SImode))		\ 		goto LABEL;						\ 	      if (ARM_INDEX_REGISTER_RTX_P (xiop1)			\&& power_of_two_operand (xiop0, SImode))		\ 		goto LABEL;						\ 	    }								\ 	  if (GET_MODE_SIZE (MODE)<= 4					\&& (code == LSHIFTRT || code == ASHIFTRT			\ 		  || code == ASHIFT || code == ROTATERT)		\&& (! arm_arch4 || (MODE) != HImode))			\ 	    {								\ 	      rtx op = XEXP (INDEX, 1);					\ 	      if (ARM_INDEX_REGISTER_RTX_P (XEXP (INDEX, 0))		\&& GET_CODE (op) == CONST_INT&& INTVAL (op)> 0	\&& INTVAL (op)<= 31)					\ 		goto LABEL;						\ 	    }								\
comment|/* NASTY: Since this limits the addressing of unsigned	\ 	     byte loads.  */
value|\ 	  range = ((MODE) == HImode || (MODE) == QImode)		\ 	    ? (arm_arch4 ? 256 : 4095) : 4096;				\ 	  if (code == CONST_INT&& INTVAL (INDEX)< range		\&& INTVAL (INDEX)> -range)				\ 	    goto LABEL;							\ 	}								\     }									\   while (0)
end_define

begin_comment
comment|/* Jump to LABEL if X is a valid address RTX.  This must take    REG_OK_STRICT into account when deciding about valid registers.     Allow REG, REG+REG, REG+INDEX, INDEX+REG, REG-INDEX, and non    floating SYMBOL_REF to the constant pool.  Allow REG-only and    AUTINC-REG if handling TImode or HImode.  Other symbol refs must be    forced though a static cell to ensure addressability.  */
end_comment

begin_define
define|#
directive|define
name|ARM_GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|{									\   if (ARM_BASE_REGISTER_RTX_P (X))					\     goto LABEL;								\   else if ((GET_CODE (X) == POST_INC || GET_CODE (X) == PRE_DEC)	\&& GET_CODE (XEXP (X, 0)) == REG				\&& ARM_REG_OK_FOR_BASE_P (XEXP (X, 0)))			\     goto LABEL;								\   else if (GET_MODE_SIZE (MODE)>= 4&& reload_completed		\&& (GET_CODE (X) == LABEL_REF				\ 	       || (GET_CODE (X) == CONST				\&& GET_CODE (XEXP ((X), 0)) == PLUS			\&& GET_CODE (XEXP (XEXP ((X), 0), 0)) == LABEL_REF	\&& GET_CODE (XEXP (XEXP ((X), 0), 1)) == CONST_INT)))\     goto LABEL;								\   else if ((MODE) == TImode)						\     ;									\   else if ((MODE) == DImode || (TARGET_SOFT_FLOAT&& (MODE) == DFmode))	\     {									\       if (GET_CODE (X) == PLUS&& ARM_BASE_REGISTER_RTX_P (XEXP (X, 0))	\&& GET_CODE (XEXP (X, 1)) == CONST_INT)			\ 	{								\ 	  HOST_WIDE_INT val = INTVAL (XEXP (X, 1));			\           if (val == 4 || val == -4 || val == -8)			\ 	    goto LABEL;							\ 	}								\     }									\   else if (GET_CODE (X) == PLUS)					\     {									\       rtx xop0 = XEXP (X, 0);						\       rtx xop1 = XEXP (X, 1);						\ 									\       if (ARM_BASE_REGISTER_RTX_P (xop0))				\ 	ARM_GO_IF_LEGITIMATE_INDEX (MODE, REGNO (xop0), xop1, LABEL);	\       else if (ARM_BASE_REGISTER_RTX_P (xop1))				\ 	ARM_GO_IF_LEGITIMATE_INDEX (MODE, REGNO (xop1), xop0, LABEL);	\     }									\
comment|/* Reload currently can't handle MINUS, so disable this for now */
value|\
comment|/* else if (GET_CODE (X) == MINUS)					\     {									\       rtx xop0 = XEXP (X,0);						\       rtx xop1 = XEXP (X,1);						\ 									\       if (ARM_BASE_REGISTER_RTX_P (xop0))				\ 	ARM_GO_IF_LEGITIMATE_INDEX (MODE, -1, xop1, LABEL);		\     } */
value|\   else if (GET_MODE_CLASS (MODE) != MODE_FLOAT				\&& GET_CODE (X) == SYMBOL_REF				\&& CONSTANT_POOL_ADDRESS_P (X)				\&& ! (flag_pic						\&& symbol_mentioned_p (get_pool_constant (X))))	\     goto LABEL;								\   else if ((GET_CODE (X) == PRE_INC || GET_CODE (X) == POST_DEC)	\&& (GET_MODE_SIZE (MODE)<= 4)				\&& GET_CODE (XEXP (X, 0)) == REG				\&& ARM_REG_OK_FOR_BASE_P (XEXP (X, 0)))			\     goto LABEL;								\ }
end_define

begin_comment
comment|/* ---------------------thumb version----------------------------------*/
end_comment

begin_define
define|#
directive|define
name|THUMB_LEGITIMATE_OFFSET
parameter_list|(
name|MODE
parameter_list|,
name|VAL
parameter_list|)
define|\
value|(GET_MODE_SIZE (MODE) == 1 ? ((unsigned HOST_WIDE_INT) (VAL)< 32)	\    : GET_MODE_SIZE (MODE) == 2 ? ((unsigned HOST_WIDE_INT) (VAL)< 64	\&& ((VAL)& 1) == 0)			\    : ((VAL)>= 0&& ((VAL) + GET_MODE_SIZE (MODE))<= 128		\&& ((VAL)& 3) == 0))
end_define

begin_comment
comment|/* The AP may be eliminated to either the SP or the FP, so we use the    least common denominator, e.g. SImode, and offsets from 0 to 64.  */
end_comment

begin_comment
comment|/* ??? Verify whether the above is the right approach.  */
end_comment

begin_comment
comment|/* ??? Also, the FP may be eliminated to the SP, so perhaps that    needs special handling also.  */
end_comment

begin_comment
comment|/* ??? Look at how the mips16 port solves this problem.  It probably uses    better ways to solve some of these problems.  */
end_comment

begin_comment
comment|/* Although it is not incorrect, we don't accept QImode and HImode    addresses based on the frame pointer or arg pointer until the    reload pass starts.  This is so that eliminating such addresses    into stack based ones won't produce impossible code.  */
end_comment

begin_define
define|#
directive|define
name|THUMB_GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|WIN
parameter_list|)
define|\
value|{									\
comment|/* ??? Not clear if this is right.  Experiment.  */
value|\   if (GET_MODE_SIZE (MODE)< 4						\&& ! (reload_in_progress || reload_completed)			\&& (   reg_mentioned_p (frame_pointer_rtx, X)			\ 	  || reg_mentioned_p (arg_pointer_rtx, X)			\ 	  || reg_mentioned_p (virtual_incoming_args_rtx, X)		\ 	  || reg_mentioned_p (virtual_outgoing_args_rtx, X)		\ 	  || reg_mentioned_p (virtual_stack_dynamic_rtx, X)		\ 	  || reg_mentioned_p (virtual_stack_vars_rtx, X)))		\     ;									\
comment|/* Accept any base register.  SP only in SImode or larger.  */
value|\   else if (GET_CODE (X) == REG						\&& THUMB_REG_MODE_OK_FOR_BASE_P (X, MODE))			\     goto WIN;								\
comment|/* This is PC relative data before MACHINE_DEPENDENT_REORG runs.  */
value|\   else if (GET_MODE_SIZE (MODE)>= 4&& CONSTANT_P (X)			\&& CONSTANT_POOL_ADDRESS_P (X)&& ! flag_pic)		\     goto WIN;								\
comment|/* This is PC relative data after MACHINE_DEPENDENT_REORG runs.  */
value|\   else if (GET_MODE_SIZE (MODE)>= 4&& reload_completed		\&& (GET_CODE (X) == LABEL_REF				\ 	       || (GET_CODE (X) == CONST				\&& GET_CODE (XEXP (X, 0)) == PLUS			\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == LABEL_REF	\&& GET_CODE (XEXP (XEXP (X, 0), 1)) == CONST_INT)))	\     goto WIN;								\
comment|/* Post-inc indexing only supported for SImode and larger.  */
value|\   else if (GET_CODE (X) == POST_INC&& GET_MODE_SIZE (MODE)>= 4	\&& GET_CODE (XEXP (X, 0)) == REG				\&& THUMB_REG_OK_FOR_INDEX_P (XEXP (X, 0)))			\     goto WIN;								\   else if (GET_CODE (X) == PLUS)					\     {									\
comment|/* REG+REG address can be any two index registers.  */
value|\
comment|/* We disallow FRAME+REG addressing since we know that FRAME	\ 	 will be replaced with STACK, and SP relative addressing only	\ 	 permits SP+OFFSET.  */
value|\       if (GET_MODE_SIZE (MODE)<= 4					\&& GET_CODE (XEXP (X, 0)) == REG				\&& GET_CODE (XEXP (X, 1)) == REG				\&& XEXP (X, 0) != frame_pointer_rtx				\&& XEXP (X, 1) != frame_pointer_rtx				\&& XEXP (X, 0) != virtual_stack_vars_rtx			\&& XEXP (X, 1) != virtual_stack_vars_rtx			\&& THUMB_REG_OK_FOR_INDEX_P (XEXP (X, 0))			\&& THUMB_REG_OK_FOR_INDEX_P (XEXP (X, 1)))			\ 	goto WIN;							\
comment|/* REG+const has 5-7 bit offset for non-SP registers.  */
value|\       else if (GET_CODE (XEXP (X, 0)) == REG				\&& (THUMB_REG_OK_FOR_INDEX_P (XEXP (X, 0))		\ 		   || XEXP (X, 0) == arg_pointer_rtx)			\&& GET_CODE (XEXP (X, 1)) == CONST_INT			\&& THUMB_LEGITIMATE_OFFSET (MODE, INTVAL (XEXP (X, 1))))	\ 	goto WIN;							\
comment|/* REG+const has 10 bit offset for SP, but only SImode and	\ 	 larger is supported.  */
value|\
comment|/* ??? Should probably check for DI/DFmode overflow here		\ 	 just like GO_IF_LEGITIMATE_OFFSET does.  */
value|\       else if (GET_CODE (XEXP (X, 0)) == REG				\&& REGNO (XEXP (X, 0)) == STACK_POINTER_REGNUM		\&& GET_MODE_SIZE (MODE)>= 4				\&& GET_CODE (XEXP (X, 1)) == CONST_INT			\&& ((unsigned HOST_WIDE_INT) INTVAL (XEXP (X, 1))	\ 		   + GET_MODE_SIZE (MODE))<= 1024			\&& (INTVAL (XEXP (X, 1))& 3) == 0)			\ 	goto WIN;							\       else if (GET_CODE (XEXP (X, 0)) == REG				\&& REGNO (XEXP (X, 0)) == FRAME_POINTER_REGNUM		\&& GET_MODE_SIZE (MODE)>= 4				\&& GET_CODE (XEXP (X, 1)) == CONST_INT			\&& (INTVAL (XEXP (X, 1))& 3) == 0)			\ 	goto WIN;							\     }									\   else if (GET_MODE_CLASS (MODE) != MODE_FLOAT				\&& GET_CODE (X) == SYMBOL_REF				\&& CONSTANT_POOL_ADDRESS_P (X)				\&& ! (flag_pic						\&& symbol_mentioned_p (get_pool_constant (X))))	\     goto WIN;								\ }
end_define

begin_comment
comment|/* ------------------------------------------------------------------- */
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
name|WIN
parameter_list|)
define|\
value|if (TARGET_ARM)							\     ARM_GO_IF_LEGITIMATE_ADDRESS (MODE, X, WIN)  			\   else
comment|/* if (TARGET_THUMB) */
value|\     THUMB_GO_IF_LEGITIMATE_ADDRESS (MODE, X, WIN)
end_define

begin_comment
comment|/* ------------------------------------------------------------------- */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     On the ARM, try to convert [REG, #BIGCONST]    into ADD BASE, REG, #UPPERCONST and [BASE, #VALIDCONST],    where VALIDCONST == 0 in case of TImode.  */
end_comment

begin_define
define|#
directive|define
name|ARM_LEGITIMIZE_ADDRESS
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
value|{									 \   if (GET_CODE (X) == PLUS)						 \     {									 \       rtx xop0 = XEXP (X, 0);						 \       rtx xop1 = XEXP (X, 1);						 \ 									 \       if (CONSTANT_P (xop0)&& ! symbol_mentioned_p (xop0))		 \ 	xop0 = force_reg (SImode, xop0);				 \       if (CONSTANT_P (xop1)&& ! symbol_mentioned_p (xop1))		 \ 	xop1 = force_reg (SImode, xop1);				 \       if (ARM_BASE_REGISTER_RTX_P (xop0)				 \&& GET_CODE (xop1) == CONST_INT)				 \ 	{								 \ 	  HOST_WIDE_INT n, low_n;					 \ 	  rtx base_reg, val;						 \ 	  n = INTVAL (xop1);						 \ 									 \ 	  if (MODE == DImode || (TARGET_SOFT_FLOAT&& MODE == DFmode))	 \ 	    {								 \ 	      low_n = n& 0x0f;						 \ 	      n&= ~0x0f;						 \ 	      if (low_n> 4)						 \ 		{							 \ 		  n += 16;						 \ 		  low_n -= 16;						 \ 		}							 \ 	    }								 \ 	  else								 \ 	    {								 \ 	      low_n = ((MODE) == TImode ? 0				 \ 		       : n>= 0 ? (n& 0xfff) : -((-n)& 0xfff));	 \ 	      n -= low_n;						 \ 	    }								 \ 	  base_reg = gen_reg_rtx (SImode);				 \ 	  val = force_operand (gen_rtx_PLUS (SImode, xop0,		 \ 					     GEN_INT (n)), NULL_RTX);	 \ 	  emit_move_insn (base_reg, val);				 \ 	  (X) = (low_n == 0 ? base_reg					 \ 		 : gen_rtx_PLUS (SImode, base_reg, GEN_INT (low_n)));	 \ 	}								 \       else if (xop0 != XEXP (X, 0) || xop1 != XEXP (x, 1))		 \ 	(X) = gen_rtx_PLUS (SImode, xop0, xop1);			 \     }									 \   else if (GET_CODE (X) == MINUS)					 \     {									 \       rtx xop0 = XEXP (X, 0);						 \       rtx xop1 = XEXP (X, 1);						 \ 									 \       if (CONSTANT_P (xop0))						 \ 	xop0 = force_reg (SImode, xop0);				 \       if (CONSTANT_P (xop1)&& ! symbol_mentioned_p (xop1))		 \ 	xop1 = force_reg (SImode, xop1);				 \       if (xop0 != XEXP (X, 0) || xop1 != XEXP (X, 1))			 \ 	(X) = gen_rtx_MINUS (SImode, xop0, xop1);			 \     }									 \   if (flag_pic)								 \     (X) = legitimize_pic_address (OLDX, MODE, NULL_RTX);		 \   if (memory_address_p (MODE, X))					 \     goto WIN;								 \ }
end_define

begin_define
define|#
directive|define
name|THUMB_LEGITIMIZE_ADDRESS
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
value|if (flag_pic)						\     (X) = legitimize_pic_address (OLDX, MODE, NULL_RTX);
end_define

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
value|if (TARGET_ARM)				\     ARM_LEGITIMIZE_ADDRESS (X, OLDX, MODE, WIN)	\   else						\     THUMB_LEGITIMIZE_ADDRESS (X, OLDX, MODE, WIN)
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.  */
end_comment

begin_define
define|#
directive|define
name|ARM_GO_IF_MODE_DEPENDENT_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|{									\   if (   GET_CODE (ADDR) == PRE_DEC || GET_CODE (ADDR) == POST_DEC	\       || GET_CODE (ADDR) == PRE_INC || GET_CODE (ADDR) == POST_INC)	\     goto LABEL;								\ }
end_define

begin_comment
comment|/* Nothing helpful to do for the Thumb */
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
value|if (TARGET_ARM)					\     ARM_GO_IF_MODE_DEPENDENT_ADDRESS (ADDR, LABEL)
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
comment|/* signed 'char' is most compatible, but RISC OS wants it unsigned.    unsigned is probably best, but may break some code.  */
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
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't cse the address of the function being compiled.  */
end_comment

begin_define
define|#
directive|define
name|NO_RECURSIVE_FUNCTION_CSE
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

begin_undef
undef|#
directive|undef
name|MOVE_RATIO
end_undef

begin_define
define|#
directive|define
name|MOVE_RATIO
value|(arm_is_xscale ? 4 : 2)
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
define|\
value|(TARGET_THUMB ? ZERO_EXTEND :						\    ((arm_arch4 || (MODE) == QImode) ? ZERO_EXTEND			\     : ((BYTES_BIG_ENDIAN&& (MODE) == HImode) ? SIGN_EXTEND : NIL)))
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is slow and undesirable.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
end_define

begin_define
define|#
directive|define
name|SLOW_UNALIGNED_ACCESS
parameter_list|(
name|MODE
parameter_list|,
name|ALIGN
parameter_list|)
value|1
end_define

begin_comment
comment|/* Immediate shift counts are truncated by the output routines (or was it    the assembler?).  Shift counts in a register are truncated by ARM.  Note    that the native compiler puts too large (> 32) immediate shift counts    into a register and shifts by the register, letting the ARM decide what    to do instead of doing that itself.  */
end_comment

begin_comment
comment|/* This is all wrong.  Defining SHIFT_COUNT_TRUNCATED tells combine that    code like (X<< (Y % 32)) for register X, Y is equivalent to (X<< Y).    On the arm, Y in a register is used modulo 256 for the shift. Only for    rotates is modulo 32 used. */
end_comment

begin_comment
comment|/* #define SHIFT_COUNT_TRUNCATED 1 */
end_comment

begin_comment
comment|/* All integers have the same format so truncation is easy.  */
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
comment|/* Calling from registers is a massive pain.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
value|1
end_define

begin_comment
comment|/* Chars and shorts should be passed as ints.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
value|1
end_define

begin_comment
comment|/* The machine modes of pointers and functions */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|Pmode
end_define

begin_define
define|#
directive|define
name|ARM_FRAME_RTX
parameter_list|(
name|X
parameter_list|)
define|\
value|(   (X) == frame_pointer_rtx || (X) == stack_pointer_rtx	\    || (X) == arg_pointer_rtx)
end_define

begin_define
define|#
directive|define
name|DEFAULT_RTX_COSTS
parameter_list|(
name|X
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|return arm_rtx_costs (X, CODE, OUTER_CODE);
end_define

begin_comment
comment|/* Moves to and from memory are quite expensive */
end_comment

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|M
parameter_list|,
name|CLASS
parameter_list|,
name|IN
parameter_list|)
define|\
value|(TARGET_ARM ? 10 :					\    ((GET_MODE_SIZE (M)< 4 ? 8 : 2 * GET_MODE_SIZE (M))	\     * (CLASS == LO_REGS ? 1 : 2)))
end_define

begin_comment
comment|/* All address computations that can be done are free, but rtx cost returns    the same for practically all of them.  So we weight the different types    of address here in the order (most pref first):    PRE/POST_INC/DEC, SHIFT or NON-INT sum, INT sum, REG, MEM or LABEL. */
end_comment

begin_define
define|#
directive|define
name|ARM_ADDRESS_COST
parameter_list|(
name|X
parameter_list|)
define|\
value|(10 - ((GET_CODE (X) == MEM || GET_CODE (X) == LABEL_REF		     \ 	  || GET_CODE (X) == SYMBOL_REF)				     \ 	 ? 0								     \ 	 : ((GET_CODE (X) == PRE_INC || GET_CODE (X) == PRE_DEC		     \ 	     || GET_CODE (X) == POST_INC || GET_CODE (X) == POST_DEC)	     \ 	    ? 10							     \ 	    : (((GET_CODE (X) == PLUS || GET_CODE (X) == MINUS)		     \ 		? 6 + (GET_CODE (XEXP (X, 1)) == CONST_INT ? 2 		     \ 		       : ((GET_RTX_CLASS (GET_CODE (XEXP (X, 0))) == '2'     \ 			   || GET_RTX_CLASS (GET_CODE (XEXP (X, 0))) == 'c'  \ 			   || GET_RTX_CLASS (GET_CODE (XEXP (X, 1))) == '2'  \ 			   || GET_RTX_CLASS (GET_CODE (XEXP (X, 1))) == 'c') \ 			  ? 1 : 0))					     \ 		: 4)))))
end_define

begin_define
define|#
directive|define
name|THUMB_ADDRESS_COST
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == REG 					\     || (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == REG	\&& GET_CODE (XEXP (X, 1)) == CONST_INT))		\    ? 1 : 2)
end_define

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|X
parameter_list|)
define|\
value|(TARGET_ARM ? ARM_ADDRESS_COST (X) : THUMB_ADDRESS_COST (X))
end_define

begin_comment
comment|/* Try to generate sequences that don't involve branches, we can then use    conditional instructions */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
define|\
value|(TARGET_ARM ? 4 : (optimize> 1 ? 1 : 0))
end_define

begin_escape
end_escape

begin_comment
comment|/* Position Independent Code.  */
end_comment

begin_comment
comment|/* We decide which register to use based on the compilation options and    the assembler in use; this is more general than the APCS restriction of    using sb (r9) all the time.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_pic_register
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used when parsing command line option -mpic-register=.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|arm_pic_register_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The register number of the register used to address a table of static    data addresses in memory.  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|arm_pic_register
end_define

begin_define
define|#
directive|define
name|FINALIZE_PIC
value|arm_finalize_pic (1)
end_define

begin_comment
comment|/* We can't directly access anything that contains a symbol,    nor can we indirect via the constant pool.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(   ! symbol_mentioned_p (X)					\&& ! label_mentioned_p (X)					\&& (! CONSTANT_POOL_ADDRESS_P (X)				\ 	     || (   ! symbol_mentioned_p (get_pool_constant (X))  	\&& ! label_mentioned_p (get_pool_constant (X)))))
end_define

begin_comment
comment|/* We need to know when we are making a constant pool; this determines    whether data needs to be in the GOT or can be referenced via a GOT    offset.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|making_const_table
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Handle pragmas for compatibility with Intel's compilers.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_TARGET_PRAGMAS
parameter_list|(
name|PFILE
parameter_list|)
value|do { \   cpp_register_pragma (PFILE, 0, "long_calls", arm_pr_long_calls); \   cpp_register_pragma (PFILE, 0, "no_long_calls", arm_pr_no_long_calls); \   cpp_register_pragma (PFILE, 0, "long_calls_off", arm_pr_long_calls_off); \ } while (0)
end_define

begin_comment
comment|/* Condition code information. */
end_comment

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.     CCFPEmode should be used with floating inequalities,    CCFPmode should be used with floating equalities.    CC_NOOVmode should be used with SImode integer equalities.    CC_Zmode should be used if only the Z flag is set correctly    CCmode should be used otherwise. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
define|\
value|CC(CC_NOOVmode, "CC_NOOV") \         CC(CC_Zmode, "CC_Z") \         CC(CC_SWPmode, "CC_SWP") \         CC(CCFPmode, "CCFP") \         CC(CCFPEmode, "CCFPE") \         CC(CC_DNEmode, "CC_DNE") \         CC(CC_DEQmode, "CC_DEQ") \         CC(CC_DLEmode, "CC_DLE") \         CC(CC_DLTmode, "CC_DLT") \         CC(CC_DGEmode, "CC_DGE") \         CC(CC_DGTmode, "CC_DGT") \         CC(CC_DLEUmode, "CC_DLEU") \         CC(CC_DLTUmode, "CC_DLTU") \         CC(CC_DGEUmode, "CC_DGEU") \         CC(CC_DGTUmode, "CC_DGTU") \         CC(CC_Cmode, "CC_C")
end_define

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
value|arm_select_cc_mode (OP, X, Y)
end_define

begin_define
define|#
directive|define
name|REVERSIBLE_CC_MODE
parameter_list|(
name|MODE
parameter_list|)
value|((MODE) != CCFPEmode)
end_define

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
value|do									\     {									\       if (GET_CODE (OP1) == CONST_INT					\&& ! (const_ok_for_arm (INTVAL (OP1))				\ 	        || (const_ok_for_arm (- INTVAL (OP1)))))		\         {								\           rtx const_op = OP1;						\           CODE = arm_canonicalize_comparison ((CODE),&const_op);	\           OP1 = const_op;						\         }								\     }									\   while (0)
end_define

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Gcc puts the pool in the wrong place for ARM, since we can only    load addresses a limited distance around the pc.  We do some    special munging to move the constant pool values to the correct    point in the code.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE_DEPENDENT_REORG
parameter_list|(
name|INSN
parameter_list|)
define|\
value|arm_reorg (INSN);			\  #undef  ASM_APP_OFF
end_define

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|(TARGET_THUMB ? "\t.code\t16\n" : "")
end_define

begin_comment
comment|/* Output an internal label definition.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_INTERNAL_LABEL
end_ifndef

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
value|do								\     {								\       char * s = (char *) alloca (40 + strlen (PREFIX));	\ 								\       if (arm_ccfsm_state == 3&& arm_target_label == (NUM)	\&& !strcmp (PREFIX, "L"))				\ 	{							\ 	  arm_ccfsm_state = 0;					\ 	  arm_target_insn = NULL;				\ 	}							\       ASM_GENERATE_INTERNAL_LABEL (s, (PREFIX), (NUM));		\       ASM_OUTPUT_LABEL (STREAM, s);		                \     }								\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a push or a pop instruction (only used when profiling).  */
end_comment

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
value|if (TARGET_ARM)					\     asm_fprintf (STREAM,"\tstmfd\t%r!,{%r}\n", 		\ 		 STACK_POINTER_REGNUM, REGNO);		\   else							\     asm_fprintf (STREAM, "\tpush {%r}\n", REGNO)
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
value|if (TARGET_ARM)					\     asm_fprintf (STREAM, "\tldmfd\t%r!,{%r}\n",		\                  STACK_POINTER_REGNUM, REGNO);		\   else							\     asm_fprintf (STREAM, "\tpop {%r}\n", REGNO)
end_define

begin_comment
comment|/* This is how to output a label which precedes a jumptable.  Since    Thumb instructions are 2 bytes, we may need explicit alignment here.  */
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
name|JUMPTABLE
parameter_list|)
define|\
value|do								\     {								\       if (TARGET_THUMB)						\         ASM_OUTPUT_ALIGN (FILE, 2);				\       ASM_OUTPUT_INTERNAL_LABEL (FILE, PREFIX, NUM);		\     }								\   while (0)
end_define

begin_define
define|#
directive|define
name|ARM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do							\     {							\       if (TARGET_THUMB) 				\         {						\           if (is_called_in_ARM_mode (DECL))		\             fprintf (STREAM, "\t.code 32\n") ;		\           else						\            fprintf (STREAM, "\t.thumb_func\n") ;	\         }						\       if (TARGET_POKE_FUNCTION_NAME)			\         arm_poke_function_name (STREAM, (char *) NAME);	\     }							\   while (0)
end_define

begin_comment
comment|/* For aliases of functions we use .thumb_set instead.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF_FROM_DECLS
parameter_list|(
name|FILE
parameter_list|,
name|DECL1
parameter_list|,
name|DECL2
parameter_list|)
define|\
value|do						   		\     {								\       const char *const LABEL1 = XSTR (XEXP (DECL_RTL (decl), 0), 0); \       const char *const LABEL2 = IDENTIFIER_POINTER (DECL2);	\ 								\       if (TARGET_THUMB&& TREE_CODE (DECL1) == FUNCTION_DECL)	\ 	{							\ 	  fprintf (FILE, "\t.thumb_set ");			\ 	  assemble_name (FILE, LABEL1);			   	\ 	  fprintf (FILE, ",");			   		\ 	  assemble_name (FILE, LABEL2);		   		\ 	  fprintf (FILE, "\n");					\ 	}							\       else							\ 	ASM_OUTPUT_DEF (FILE, LABEL1, LABEL2);			\     }								\   while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_comment
comment|/* To support -falign-* switches we need to use .p2align so    that alignment directives in code sections will be padded    with no-op instructions, rather than zeroes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|if ((LOG) != 0)						\     {								\       if ((MAX_SKIP) == 0)					\         fprintf ((FILE), "\t.p2align %d\n", (LOG));		\       else							\         fprintf ((FILE), "\t.p2align %d,,%d\n",			\                  (LOG), (MAX_SKIP));				\     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Only perform branch elimination (by making instructions conditional) if    we're optimising.  Otherwise it's of no use anyway.  */
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
value|if (TARGET_ARM&& optimize)				\     arm_final_prescan_insn (INSN);			\   else if (TARGET_THUMB)				\     thumb_final_prescan_insn (INSN)
end_define

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|(CODE == '@' || CODE == '|'			\    || (TARGET_ARM&& (CODE == '?'))		\    || (TARGET_THUMB&& (CODE == '_')))
end_define

begin_comment
comment|/* Output an operand of an instruction.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
define|\
value|arm_print_operand (STREAM, X, CODE)
end_define

begin_define
define|#
directive|define
name|ARM_SIGN_EXTEND
parameter_list|(
name|x
parameter_list|)
value|((HOST_WIDE_INT)			\   (HOST_BITS_PER_WIDE_INT<= 32 ? (unsigned HOST_WIDE_INT) (x)	\    : ((((unsigned HOST_WIDE_INT)(x))& (unsigned HOST_WIDE_INT) 0xffffffff) |\       ((((unsigned HOST_WIDE_INT)(x))& (unsigned HOST_WIDE_INT) 0x80000000) \        ? ((~ (unsigned HOST_WIDE_INT) 0)			\& ~ (unsigned HOST_WIDE_INT) 0xffffffff)		\        : 0))))
end_define

begin_comment
comment|/* Output the address of an operand.  */
end_comment

begin_define
define|#
directive|define
name|ARM_PRINT_OPERAND_ADDRESS
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|)
define|\
value|{								\     int is_minus = GET_CODE (X) == MINUS;			\ 								\     if (GET_CODE (X) == REG)					\       asm_fprintf (STREAM, "[%r, #0]", REGNO (X));		\     else if (GET_CODE (X) == PLUS || is_minus)			\       {								\ 	rtx base = XEXP (X, 0);					\ 	rtx index = XEXP (X, 1);				\ 	HOST_WIDE_INT offset = 0;				\ 	if (GET_CODE (base) != REG)				\ 	  {							\
comment|/* Ensure that BASE is a register */
value|\
comment|/* (one of them must be). */
value|\ 	    rtx temp = base;					\ 	    base = index;					\ 	    index = temp;					\ 	  }							\ 	switch (GET_CODE (index))				\ 	  {							\ 	  case CONST_INT:					\ 	    offset = INTVAL (index);				\ 	    if (is_minus)					\ 	      offset = -offset;					\ 	    asm_fprintf (STREAM, "[%r, #%d]", 			\ 		         REGNO (base), offset);			\ 	    break;						\ 								\ 	  case REG:						\ 	    asm_fprintf (STREAM, "[%r, %s%r]", 			\ 		     REGNO (base), is_minus ? "-" : "",		\ 		     REGNO (index));				\ 	    break;						\ 								\ 	  case MULT:						\ 	  case ASHIFTRT:					\ 	  case LSHIFTRT:					\ 	  case ASHIFT:						\ 	  case ROTATERT:					\ 	  {							\ 	    asm_fprintf (STREAM, "[%r, %s%r", 			\ 		         REGNO (base), is_minus ? "-" : "", 	\                          REGNO (XEXP (index, 0)));		\ 	    arm_print_operand (STREAM, index, 'S');		\ 	    fputs ("]", STREAM);				\ 	    break;						\ 	  }							\ 	    							\ 	  default:						\ 	    abort();						\ 	}							\     }							        \   else if (   GET_CODE (X) == PRE_INC || GET_CODE (X) == POST_INC\ 	   || GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_DEC)\     {								\       extern int output_memory_reference_mode;			\       								\       if (GET_CODE (XEXP (X, 0)) != REG)			\ 	abort ();						\ 								\       if (GET_CODE (X) == PRE_DEC || GET_CODE (X) == PRE_INC)	\ 	asm_fprintf (STREAM, "[%r, #%s%d]!", 			\ 		     REGNO (XEXP (X, 0)),			\ 		     GET_CODE (X) == PRE_DEC ? "-" : "",	\ 		     GET_MODE_SIZE (output_memory_reference_mode));\       else							\ 	asm_fprintf (STREAM, "[%r], #%s%d", 			\ 		     REGNO (XEXP (X, 0)),			\ 		     GET_CODE (X) == POST_DEC ? "-" : "",	\ 		     GET_MODE_SIZE (output_memory_reference_mode));\     }								\   else output_addr_const (STREAM, X);				\ }
end_define

begin_define
define|#
directive|define
name|THUMB_PRINT_OPERAND_ADDRESS
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|)
define|\
value|{							\   if (GET_CODE (X) == REG)				\     asm_fprintf (STREAM, "[%r]", REGNO (X));		\   else if (GET_CODE (X) == POST_INC)			\     asm_fprintf (STREAM, "%r!", REGNO (XEXP (X, 0)));	\   else if (GET_CODE (X) == PLUS)			\     {							\       if (GET_CODE (XEXP (X, 1)) == CONST_INT)		\ 	asm_fprintf (STREAM, "[%r, #%d]", 		\ 		     REGNO (XEXP (X, 0)),		\ 		     (int) INTVAL (XEXP (X, 1)));	\       else						\ 	asm_fprintf (STREAM, "[%r, %r]",		\ 		     REGNO (XEXP (X, 0)),		\ 		     REGNO (XEXP (X, 1)));		\     }							\   else							\     output_addr_const (STREAM, X);			\ }
end_define

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|)
define|\
value|if (TARGET_ARM)				\     ARM_PRINT_OPERAND_ADDRESS (STREAM, X)	\   else						\     THUMB_PRINT_OPERAND_ADDRESS (STREAM, X)
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
value|do										\     {										\       int mi_delta = (DELTA);							\       const char *const mi_op = mi_delta< 0 ? "sub" : "add";			\       int shift = 0;								\       int this_regno = (aggregate_value_p (TREE_TYPE (TREE_TYPE (FUNCTION)))	\ 		        ? 1 : 0);						\       if (mi_delta< 0)								\         mi_delta = - mi_delta;							\       while (mi_delta != 0)							\         {									\           if ((mi_delta& (3<< shift)) == 0)					\ 	    shift += 2;								\           else									\ 	    {									\ 	      asm_fprintf (FILE, "\t%s\t%r, %r, #%d\n",				\ 		           mi_op, this_regno, this_regno,			\ 		           mi_delta& (0xff<< shift));				\ 	      mi_delta&= ~(0xff<< shift);					\ 	      shift += 8;							\ 	    }									\         }									\       fputs ("\tb\t", FILE);							\       assemble_name (FILE, XSTR (XEXP (DECL_RTL (FUNCTION), 0), 0));		\       if (NEED_PLT_RELOC)							\         fputs ("(PLT)", FILE);							\       fputc ('\n', FILE);							\     }										\   while (0)
end_define

begin_comment
comment|/* A C expression whose value is RTL representing the value of the return    address for the frame COUNT steps up from the current frame.  */
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
value|arm_return_addr (COUNT, FRAME)
end_define

begin_comment
comment|/* Mask of the bits in the PC that contain the real return address     when running in 26-bit mode.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_MASK26
value|(0x03fffffc)
end_define

begin_comment
comment|/* Pick up the return address upon entry to a procedure. Used for    dwarf2 unwind information.  This also enables the table driven    mechanism.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
value|gen_rtx_REG (Pmode, LR_REGNUM)
end_define

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|DWARF_FRAME_REGNUM (LR_REGNUM)
end_define

begin_comment
comment|/* Used to mask out junk bits from the return address, such as    processor state, interrupt status, condition codes and the like.  */
end_comment

begin_define
define|#
directive|define
name|MASK_RETURN_ADDR
define|\
comment|/* If we are generating code for an ARM2/ARM3 machine or for an ARM6	\      in 26 bit mode, the condition codes must be masked out of the	\      return address.  This does not apply to ARM6 and later processors	\      when running in 32 bit mode.  */
define|\
value|((!TARGET_APCS_32) ? (GEN_INT (RETURN_ADDR_MASK26))			\    : (GEN_INT ((unsigned long)0xffffffff)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the codes that are matched by predicates in arm.c */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"s_register_operand", {SUBREG, REG}},				\   {"arm_hard_register_operand", {REG}},					\   {"f_register_operand", {SUBREG, REG}},				\   {"arm_add_operand",    {SUBREG, REG, CONST_INT}},			\   {"fpu_add_operand",    {SUBREG, REG, CONST_DOUBLE}},			\   {"fpu_rhs_operand",    {SUBREG, REG, CONST_DOUBLE}},			\   {"arm_rhs_operand",    {SUBREG, REG, CONST_INT}},			\   {"arm_not_operand",    {SUBREG, REG, CONST_INT}},			\   {"reg_or_int_operand", {SUBREG, REG, CONST_INT}},			\   {"index_operand",      {SUBREG, REG, CONST_INT}},			\   {"thumb_cmp_operand",  {SUBREG, REG, CONST_INT}},			\   {"offsettable_memory_operand", {MEM}},				\   {"bad_signed_byte_operand", {MEM}},					\   {"alignable_memory_operand", {MEM}},					\   {"shiftable_operator", {PLUS, MINUS, AND, IOR, XOR}},			\   {"minmax_operator", {SMIN, SMAX, UMIN, UMAX}},			\   {"shift_operator", {ASHIFT, ASHIFTRT, LSHIFTRT, ROTATERT, MULT}},	\   {"di_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE, MEM}},		\   {"nonimmediate_di_operand", {SUBREG, REG, MEM}},			\   {"soft_df_operand", {SUBREG, REG, CONST_DOUBLE, MEM}},		\   {"nonimmediate_soft_df_operand", {SUBREG, REG, MEM}},			\   {"load_multiple_operation",  {PARALLEL}},				\   {"store_multiple_operation", {PARALLEL}},				\   {"equality_operator", {EQ, NE}},					\   {"arm_comparison_operator", {EQ, NE, LE, LT, GE, GT, GEU, GTU, LEU,	\ 			       LTU, UNORDERED, ORDERED, UNLT, UNLE,	\ 			       UNGE, UNGT}},				\   {"arm_rhsm_operand", {SUBREG, REG, CONST_INT, MEM}},			\   {"const_shift_operand", {CONST_INT}},					\   {"multi_register_push", {PARALLEL}},					\   {"cc_register", {REG}},						\   {"logical_binary_operator", {AND, IOR, XOR}},				\   {"dominant_cc_register", {REG}},
end_define

begin_comment
comment|/* Define this if you have special predicates that know special things    about modes.  Genrecog will warn about certain forms of    match_operand without a mode; if the operand predicate is listed in    SPECIAL_MODE_PREDICATES, the warning will be suppressed. */
end_comment

begin_define
define|#
directive|define
name|SPECIAL_MODE_PREDICATES
define|\
value|"cc_register", "dominant_cc_register",
end_define

begin_enum
enum|enum
name|arm_builtins
block|{
name|ARM_BUILTIN_CLZ
block|,
name|ARM_BUILTIN_MAX
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_ARM_H */
end_comment

end_unit

