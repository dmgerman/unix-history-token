begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for IBM RS/6000.    Copyright (C) 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@vlsi1.ultra.nyu.edu)     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm.h files include this one and then override    many of the definitions.  */
end_comment

begin_comment
comment|/* Definitions for the object file format.  These are set at    compile-time.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_XCOFF
value|1
end_define

begin_define
define|#
directive|define
name|OBJECT_ELF
value|2
end_define

begin_define
define|#
directive|define
name|OBJECT_PEF
value|3
end_define

begin_define
define|#
directive|define
name|OBJECT_MACHO
value|4
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|(TARGET_OBJECT_FORMAT == OBJECT_ELF)
end_define

begin_define
define|#
directive|define
name|TARGET_XCOFF
value|(TARGET_OBJECT_FORMAT == OBJECT_XCOFF)
end_define

begin_define
define|#
directive|define
name|TARGET_MACOS
value|(TARGET_OBJECT_FORMAT == OBJECT_PEF)
end_define

begin_define
define|#
directive|define
name|TARGET_MACHO
value|(TARGET_OBJECT_FORMAT == OBJECT_MACHO)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_AIX
end_ifndef

begin_define
define|#
directive|define
name|TARGET_AIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default string to use for cpu if not specified.  */
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
value|((char *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Common ASM definitions used by ASM_SPEC among the various targets    for handling -mcpu=xxx switches.  */
end_comment

begin_define
define|#
directive|define
name|ASM_CPU_SPEC
define|\
value|"%{!mcpu*: \   %{mpower: %{!mpower2: -mpwr}} \   %{mpower2: -mpwrx} \   %{mpowerpc64*: -mppc64} \   %{!mpowerpc64*: %{mpowerpc*: -mppc}} \   %{mno-power: %{!mpowerpc*: -mcom}} \   %{!mno-power: %{!mpower*: %(asm_default)}}} \ %{mcpu=common: -mcom} \ %{mcpu=power: -mpwr} \ %{mcpu=power2: -mpwrx} \ %{mcpu=power3: -mppc64} \ %{mcpu=power4: -mpower4} \ %{mcpu=power5: -mpower4} \ %{mcpu=powerpc: -mppc} \ %{mcpu=rios: -mpwr} \ %{mcpu=rios1: -mpwr} \ %{mcpu=rios2: -mpwrx} \ %{mcpu=rsc: -mpwr} \ %{mcpu=rsc1: -mpwr} \ %{mcpu=rs64a: -mppc64} \ %{mcpu=401: -mppc} \ %{mcpu=403: -m403} \ %{mcpu=405: -m405} \ %{mcpu=405fp: -m405} \ %{mcpu=440: -m440} \ %{mcpu=440fp: -m440} \ %{mcpu=505: -mppc} \ %{mcpu=601: -m601} \ %{mcpu=602: -mppc} \ %{mcpu=603: -mppc} \ %{mcpu=603e: -mppc} \ %{mcpu=ec603e: -mppc} \ %{mcpu=604: -mppc} \ %{mcpu=604e: -mppc} \ %{mcpu=620: -mppc64} \ %{mcpu=630: -mppc64} \ %{mcpu=740: -mppc} \ %{mcpu=750: -mppc} \ %{mcpu=G3: -mppc} \ %{mcpu=7400: -mppc -maltivec} \ %{mcpu=7450: -mppc -maltivec} \ %{mcpu=G4: -mppc -maltivec} \ %{mcpu=801: -mppc} \ %{mcpu=821: -mppc} \ %{mcpu=823: -mppc} \ %{mcpu=860: -mppc} \ %{mcpu=970: -mpower4 -maltivec} \ %{mcpu=G5: -mpower4 -maltivec} \ %{mcpu=8540: -me500} \ %{maltivec: -maltivec} \ -many"
end_define

begin_define
define|#
directive|define
name|CPP_DEFAULT_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|""
end_define

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GCC driver    program.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
end_define

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "cpp_default",		CPP_DEFAULT_SPEC },			\   { "asm_cpu",			ASM_CPU_SPEC },				\   { "asm_default",		ASM_DEFAULT_SPEC },			\   SUBTARGET_EXTRA_SPECS
end_define

begin_comment
comment|/* Architecture type.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use POWER architecture instructions and MQ register.  */
end_comment

begin_define
define|#
directive|define
name|MASK_POWER
value|0x00000001
end_define

begin_comment
comment|/* Use POWER2 extensions to POWER architecture.  */
end_comment

begin_define
define|#
directive|define
name|MASK_POWER2
value|0x00000002
end_define

begin_comment
comment|/* Use PowerPC architecture instructions.  */
end_comment

begin_define
define|#
directive|define
name|MASK_POWERPC
value|0x00000004
end_define

begin_comment
comment|/* Use PowerPC General Purpose group optional instructions, e.g. fsqrt.  */
end_comment

begin_define
define|#
directive|define
name|MASK_PPC_GPOPT
value|0x00000008
end_define

begin_comment
comment|/* Use PowerPC Graphics group optional instructions, e.g. fsel.  */
end_comment

begin_define
define|#
directive|define
name|MASK_PPC_GFXOPT
value|0x00000010
end_define

begin_comment
comment|/* Use PowerPC-64 architecture instructions.  */
end_comment

begin_define
define|#
directive|define
name|MASK_POWERPC64
value|0x00000020
end_define

begin_comment
comment|/* Use revised mnemonic names defined for PowerPC architecture.  */
end_comment

begin_define
define|#
directive|define
name|MASK_NEW_MNEMONICS
value|0x00000040
end_define

begin_comment
comment|/* Disable placing fp constants in the TOC; can be turned on when the    TOC overflows.  */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_FP_IN_TOC
value|0x00000080
end_define

begin_comment
comment|/* Disable placing symbol+offset constants in the TOC; can be turned on when    the TOC overflows.  */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_SUM_IN_TOC
value|0x00000100
end_define

begin_comment
comment|/* Output only one TOC entry per module.  Normally linking fails if    there are more than 16K unique variables/constants in an executable.  With    this option, linking fails only if there are more than 16K modules, or    if there are more than 16K unique variables/constant in a single module.     This is at the cost of having 2 extra loads and one extra store per    function, and one less allocable register.  */
end_comment

begin_define
define|#
directive|define
name|MASK_MINIMAL_TOC
value|0x00000200
end_define

begin_comment
comment|/* Nonzero for the 64 bit ABIs: longs and pointers are 64 bits.  The    chip is running in "64-bit mode", in which CR0 is set in dot    operations based on all 64 bits of the register, bdnz works on 64-bit    ctr, lr is 64 bits, and so on.  Requires MASK_POWERPC64.  */
end_comment

begin_define
define|#
directive|define
name|MASK_64BIT
value|0x00000400
end_define

begin_comment
comment|/* Disable use of FPRs.  */
end_comment

begin_define
define|#
directive|define
name|MASK_SOFT_FLOAT
value|0x00000800
end_define

begin_comment
comment|/* Enable load/store multiple, even on PowerPC */
end_comment

begin_define
define|#
directive|define
name|MASK_MULTIPLE
value|0x00001000
end_define

begin_comment
comment|/* Use string instructions for block moves */
end_comment

begin_define
define|#
directive|define
name|MASK_STRING
value|0x00002000
end_define

begin_comment
comment|/* Disable update form of load/store */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_UPDATE
value|0x00004000
end_define

begin_comment
comment|/* Disable fused multiply/add operations */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_FUSED_MADD
value|0x00008000
end_define

begin_comment
comment|/* Nonzero if we need to schedule the prolog and epilog.  */
end_comment

begin_define
define|#
directive|define
name|MASK_SCHED_PROLOG
value|0x00010000
end_define

begin_comment
comment|/* Use AltiVec instructions.  */
end_comment

begin_define
define|#
directive|define
name|MASK_ALTIVEC
value|0x00020000
end_define

begin_comment
comment|/* Return small structures in memory (as the AIX ABI requires).  */
end_comment

begin_define
define|#
directive|define
name|MASK_AIX_STRUCT_RET
value|0x00040000
end_define

begin_comment
comment|/* Use single field mfcr instruction.  */
end_comment

begin_define
define|#
directive|define
name|MASK_MFCRF
value|0x00080000
end_define

begin_comment
comment|/* The only remaining free bits are 0x00600000.  linux64.h uses    0x00100000, and sysv4.h uses 0x00800000 -> 0x40000000.    0x80000000 is not available because target_flags is signed.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_POWER
value|(target_flags& MASK_POWER)
end_define

begin_define
define|#
directive|define
name|TARGET_POWER2
value|(target_flags& MASK_POWER2)
end_define

begin_define
define|#
directive|define
name|TARGET_POWERPC
value|(target_flags& MASK_POWERPC)
end_define

begin_define
define|#
directive|define
name|TARGET_PPC_GPOPT
value|(target_flags& MASK_PPC_GPOPT)
end_define

begin_define
define|#
directive|define
name|TARGET_PPC_GFXOPT
value|(target_flags& MASK_PPC_GFXOPT)
end_define

begin_define
define|#
directive|define
name|TARGET_NEW_MNEMONICS
value|(target_flags& MASK_NEW_MNEMONICS)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_FP_IN_TOC
value|(target_flags& MASK_NO_FP_IN_TOC)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_SUM_IN_TOC
value|(target_flags& MASK_NO_SUM_IN_TOC)
end_define

begin_define
define|#
directive|define
name|TARGET_MINIMAL_TOC
value|(target_flags& MASK_MINIMAL_TOC)
end_define

begin_define
define|#
directive|define
name|TARGET_64BIT
value|(target_flags& MASK_64BIT)
end_define

begin_define
define|#
directive|define
name|TARGET_SOFT_FLOAT
value|(target_flags& MASK_SOFT_FLOAT)
end_define

begin_define
define|#
directive|define
name|TARGET_MULTIPLE
value|(target_flags& MASK_MULTIPLE)
end_define

begin_define
define|#
directive|define
name|TARGET_STRING
value|(target_flags& MASK_STRING)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_UPDATE
value|(target_flags& MASK_NO_UPDATE)
end_define

begin_define
define|#
directive|define
name|TARGET_NO_FUSED_MADD
value|(target_flags& MASK_NO_FUSED_MADD)
end_define

begin_define
define|#
directive|define
name|TARGET_SCHED_PROLOG
value|(target_flags& MASK_SCHED_PROLOG)
end_define

begin_define
define|#
directive|define
name|TARGET_ALTIVEC
value|(target_flags& MASK_ALTIVEC)
end_define

begin_define
define|#
directive|define
name|TARGET_AIX_STRUCT_RET
value|(target_flags& MASK_AIX_STRUCT_RET)
end_define

begin_comment
comment|/* Define TARGET_MFCRF if the target assembler supports the optional    field operand for mfcr and the target processor supports the    instruction.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_MFCRF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_MFCRF
value|(target_flags& MASK_MFCRF)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_MFCRF
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_32BIT
value|(! TARGET_64BIT)
end_define

begin_define
define|#
directive|define
name|TARGET_HARD_FLOAT
value|(! TARGET_SOFT_FLOAT)
end_define

begin_define
define|#
directive|define
name|TARGET_UPDATE
value|(! TARGET_NO_UPDATE)
end_define

begin_define
define|#
directive|define
name|TARGET_FUSED_MADD
value|(! TARGET_NO_FUSED_MADD)
end_define

begin_comment
comment|/* Emit a dtp-relative reference to a TLS variable.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_TLS
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DWARF_DTPREL
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|,
name|X
parameter_list|)
define|\
value|rs6000_output_dwarf_dtprel (FILE, SIZE, X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_AS_TLS
end_ifndef

begin_define
define|#
directive|define
name|HAVE_AS_TLS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_comment
comment|/* For libgcc2 we make sure this is a compile time constant */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__64BIT__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_POWERPC64
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_POWERPC64
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

begin_define
define|#
directive|define
name|TARGET_POWERPC64
value|(target_flags& MASK_POWERPC64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_XL_COMPAT
value|0
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.     Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{{"power",		MASK_POWER  | MASK_MULTIPLE | MASK_STRING,	\ 			N_("Use POWER instruction set")},		\   {"power2",		(MASK_POWER | MASK_MULTIPLE | MASK_STRING	\ 			 | MASK_POWER2),				\ 			N_("Use POWER2 instruction set")},		\   {"no-power2",		- MASK_POWER2,					\ 			N_("Do not use POWER2 instruction set")},	\   {"no-power",		- (MASK_POWER | MASK_POWER2 | MASK_MULTIPLE	\ 			   | MASK_STRING),				\ 			N_("Do not use POWER instruction set")},	\   {"powerpc",		MASK_POWERPC,					\ 			N_("Use PowerPC instruction set")},		\   {"no-powerpc",	- (MASK_POWERPC | MASK_PPC_GPOPT		\ 			   | MASK_PPC_GFXOPT | MASK_POWERPC64),		\ 			N_("Do not use PowerPC instruction set")},	\   {"powerpc-gpopt",	MASK_POWERPC | MASK_PPC_GPOPT,			\ 			N_("Use PowerPC General Purpose group optional instructions")},\   {"no-powerpc-gpopt",	- MASK_PPC_GPOPT,				\ 			N_("Do not use PowerPC General Purpose group optional instructions")},\   {"powerpc-gfxopt",	MASK_POWERPC | MASK_PPC_GFXOPT,			\ 			N_("Use PowerPC Graphics group optional instructions")},\   {"no-powerpc-gfxopt",	- MASK_PPC_GFXOPT,				\ 			N_("Do not use PowerPC Graphics group optional instructions")},\   {"powerpc64",		MASK_POWERPC64,					\ 			N_("Use PowerPC-64 instruction set")},		\   {"no-powerpc64",	- MASK_POWERPC64,				\ 			N_("Do not use PowerPC-64 instruction set")},	\   {"altivec",		MASK_ALTIVEC ,					\ 			N_("Use AltiVec instructions")},		\   {"no-altivec",	- MASK_ALTIVEC ,					\ 			N_("Do not use AltiVec instructions")},	\   {"new-mnemonics",	MASK_NEW_MNEMONICS,				\ 			N_("Use new mnemonics for PowerPC architecture")},\   {"old-mnemonics",	-MASK_NEW_MNEMONICS,				\ 			N_("Use old mnemonics for PowerPC architecture")},\   {"full-toc",		- (MASK_NO_FP_IN_TOC | MASK_NO_SUM_IN_TOC	\ 			   | MASK_MINIMAL_TOC),				\ 			N_("Put everything in the regular TOC")},	\   {"fp-in-toc",		- MASK_NO_FP_IN_TOC,				\ 			N_("Place floating point constants in TOC")},	\   {"no-fp-in-toc",	MASK_NO_FP_IN_TOC,				\ 			N_("Do not place floating point constants in TOC")},\   {"sum-in-toc",	- MASK_NO_SUM_IN_TOC,				\ 			N_("Place symbol+offset constants in TOC")},	\   {"no-sum-in-toc",	MASK_NO_SUM_IN_TOC,				\ 			N_("Do not place symbol+offset constants in TOC")},\   {"minimal-toc",	MASK_MINIMAL_TOC,				\ 			"Use only one TOC entry per procedure"},	\   {"minimal-toc",	- (MASK_NO_FP_IN_TOC | MASK_NO_SUM_IN_TOC),	\ 			""},						\   {"no-minimal-toc",	- MASK_MINIMAL_TOC,				\ 			N_("Place variable addresses in the regular TOC")},\   {"hard-float",	- MASK_SOFT_FLOAT,				\ 			N_("Use hardware floating point")},		\   {"soft-float",	MASK_SOFT_FLOAT,				\ 			N_("Do not use hardware floating point")},	\   {"multiple",		MASK_MULTIPLE,					\ 			N_("Generate load/store multiple instructions")},	\   {"no-multiple",	- MASK_MULTIPLE,				\ 			N_("Do not generate load/store multiple instructions")},\   {"string",		MASK_STRING,					\ 			N_("Generate string instructions for block moves")},\   {"no-string",		- MASK_STRING,					\ 			N_("Do not generate string instructions for block moves")},\   {"update",		- MASK_NO_UPDATE,				\ 			N_("Generate load/store with update instructions")},\   {"no-update",		MASK_NO_UPDATE,					\ 			N_("Do not generate load/store with update instructions")},\   {"fused-madd",	- MASK_NO_FUSED_MADD,				\ 			N_("Generate fused multiply/add instructions")},\   {"no-fused-madd",	MASK_NO_FUSED_MADD,				\ 			N_("Do not generate fused multiply/add instructions")},\   {"sched-prolog",      MASK_SCHED_PROLOG,                              \ 			""},						\   {"no-sched-prolog",   -MASK_SCHED_PROLOG,                             \ 			N_("Do not schedule the start and end of the procedure")},\   {"sched-epilog",      MASK_SCHED_PROLOG,                              \ 			""},						\   {"no-sched-epilog",   -MASK_SCHED_PROLOG,                             \ 			""},						\   {"aix-struct-return",	MASK_AIX_STRUCT_RET,				\ 			N_("Return all structures in memory (AIX default)")},\   {"svr4-struct-return", - MASK_AIX_STRUCT_RET,				\ 			N_("Return small structures in registers (SVR4 default)")},\   {"no-aix-struct-return", - MASK_AIX_STRUCT_RET,			\ 			""},						\   {"no-svr4-struct-return", MASK_AIX_STRUCT_RET,			\ 			""},						\   {"mfcrf",		MASK_MFCRF,					\ 			N_("Generate single field mfcr instruction")},	\   {"no-mfcrf",		- MASK_MFCRF,					\ 			N_("Do not generate single field mfcr instruction")},\   SUBTARGET_SWITCHES							\   {"",			TARGET_DEFAULT | MASK_SCHED_PROLOG,		\ 			""}}
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_POWER | MASK_MULTIPLE | MASK_STRING)
end_define

begin_comment
comment|/* This is meant to be redefined in the host dependent files */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
end_define

begin_comment
comment|/* Processor type.  Order must match cpu attribute in MD file.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_RIOS1
block|,
name|PROCESSOR_RIOS2
block|,
name|PROCESSOR_RS64A
block|,
name|PROCESSOR_MPCCORE
block|,
name|PROCESSOR_PPC403
block|,
name|PROCESSOR_PPC405
block|,
name|PROCESSOR_PPC440
block|,
name|PROCESSOR_PPC601
block|,
name|PROCESSOR_PPC603
block|,
name|PROCESSOR_PPC604
block|,
name|PROCESSOR_PPC604e
block|,
name|PROCESSOR_PPC620
block|,
name|PROCESSOR_PPC630
block|,
name|PROCESSOR_PPC750
block|,
name|PROCESSOR_PPC7400
block|,
name|PROCESSOR_PPC7450
block|,
name|PROCESSOR_PPC8540
block|,
name|PROCESSOR_POWER4
block|,
name|PROCESSOR_POWER5
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|rs6000_cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Recast the processor type to the cpu attribute.  */
end_comment

begin_define
define|#
directive|define
name|rs6000_cpu_attr
value|((enum attr_cpu)rs6000_cpu)
end_define

begin_comment
comment|/* Define generic processor types based upon current deployment.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_COMMON
value|PROCESSOR_PPC601
end_define

begin_define
define|#
directive|define
name|PROCESSOR_POWER
value|PROCESSOR_RIOS1
end_define

begin_define
define|#
directive|define
name|PROCESSOR_POWERPC
value|PROCESSOR_PPC604
end_define

begin_define
define|#
directive|define
name|PROCESSOR_POWERPC64
value|PROCESSOR_RS64A
end_define

begin_comment
comment|/* Define the default processor.  This is overridden by other tm.h files.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|PROCESSOR_RIOS1
end_define

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT64
value|PROCESSOR_RS64A
end_define

begin_comment
comment|/* Specify the dialect of assembler to use.  New mnemonics is dialect one    and the old mnemonics are dialect zero.  */
end_comment

begin_define
define|#
directive|define
name|ASSEMBLER_DIALECT
value|(TARGET_NEW_MNEMONICS ? 1 : 0)
end_define

begin_comment
comment|/* Types of costly dependences.  */
end_comment

begin_enum
enum|enum
name|rs6000_dependence_cost
block|{
name|max_dep_latency
init|=
literal|1000
block|,
name|no_dep_costly
block|,
name|all_deps_costly
block|,
name|true_store_to_load_dep_costly
block|,
name|store_to_load_dep_costly
block|}
enum|;
end_enum

begin_comment
comment|/* Types of nop insertion schemes in sched target hook sched_finish.  */
end_comment

begin_enum
enum|enum
name|rs6000_nop_insertion
block|{
name|sched_finish_regroup_exact
init|=
literal|1000
block|,
name|sched_finish_pad_groups
block|,
name|sched_finish_none
block|}
enum|;
end_enum

begin_comment
comment|/* Dispatch group termination caused by an insn.  */
end_comment

begin_enum
enum|enum
name|group_termination
block|{
name|current_group
block|,
name|previous_group
block|}
enum|;
end_enum

begin_comment
comment|/* This is meant to be overridden in target specific files.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OPTIONS
end_define

begin_define
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{									\    {"cpu=",&rs6000_select[1].string,					\     N_("Use features of and schedule code for given CPU"), 0},		\    {"tune=",&rs6000_select[2].string,					\     N_("Schedule code for given CPU"), 0},				\    {"debug=",&rs6000_debug_name, N_("Enable debug output"), 0},	\    {"traceback=",&rs6000_traceback_name,				\     N_("Select full, part, or no traceback table"), 0},			\    {"abi=",&rs6000_abi_string, N_("Specify ABI to use"), 0},		\    {"long-double-",&rs6000_long_double_size_string,			\     N_("Specify size of long double (64 or 128 bits)"), 0},		\    {"isel=",&rs6000_isel_string,                                       \     N_("Specify yes/no if isel instructions should be generated"), 0},  \    {"spe=",&rs6000_spe_string,                                         \     N_("Specify yes/no if SPE SIMD instructions should be generated"), 0},\    {"float-gprs=",&rs6000_float_gprs_string,                           \     N_("Specify yes/no if using floating point in the GPRs"), 0},       \    {"vrsave=",&rs6000_altivec_vrsave_string,                           \     N_("Specify yes/no if VRSAVE instructions should be generated for AltiVec"), 0}, \    {"longcall",&rs6000_longcall_switch,				\     N_("Avoid all range limits on call instructions"), 0},		\    {"no-longcall",&rs6000_longcall_switch, "", 0},			\    {"warn-altivec-long",&rs6000_warn_altivec_long_switch, \     N_("Warn about deprecated 'vector long ...' AltiVec type usage"), 0}, \    {"no-warn-altivec-long",&rs6000_warn_altivec_long_switch, "", 0}, \    {"sched-costly-dep=",&rs6000_sched_costly_dep_str,                  \     N_("Determine which dependences between insns are considered costly"), 0}, \    {"insert-sched-nops=",&rs6000_sched_insert_nops_str,                \     N_("Specify which post scheduling nop insertion scheme to apply"), 0}, \    {"align-",&rs6000_alignment_string,					\     N_("Specify alignment of structure fields default/natural"), 0},	\    {"prioritize-restricted-insns=",&rs6000_sched_restricted_insns_priority_str, \     N_("Specify scheduling priority for dispatch slot restricted insns"), 0}, \    SUBTARGET_OPTIONS							\ }
end_define

begin_comment
comment|/* Support for a compile-time default CPU, et cetera.  The rules are:    --with-cpu is ignored if -mcpu is specified.    --with-tune is ignored if -mtune is specified.    --with-float is ignored if -mhard-float or -msoft-float are     specified.  */
end_comment

begin_define
define|#
directive|define
name|OPTION_DEFAULT_SPECS
define|\
value|{"cpu", "%{!mcpu=*:-mcpu=%(VALUE)}" }, \   {"tune", "%{!mtune=*:-mtune=%(VALUE)}" }, \   {"float", "%{!msoft-float:%{!mhard-float:-m%(VALUE)-float}}" }
end_define

begin_comment
comment|/* rs6000_select[0] is reserved for the default cpu defined via --with-cpu */
end_comment

begin_struct
struct|struct
name|rs6000_cpu_select
block|{
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|set_tune_p
decl_stmt|;
name|int
name|set_arch_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|rs6000_cpu_select
name|rs6000_select
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug support */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_debug_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name for -mdebug-xxxx option */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_abi_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for -mabi={sysv,darwin,eabi,aix,altivec} */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rs6000_debug_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug stack applications */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rs6000_debug_arg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug argument handling */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEBUG_STACK
value|rs6000_debug_stack
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_ARG
value|rs6000_debug_arg
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_traceback_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of traceback table.  */
end_comment

begin_comment
comment|/* These are separate from target_flags because we've run out of bits    there.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_long_double_size_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_long_double_type_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_altivec_abi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_spe_abi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_isel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_spe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_float_gprs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_float_gprs_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_isel_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_spe_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_altivec_vrsave_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_altivec_vrsave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_longcall_switch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_default_long_calls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_alignment_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_alignment_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_sched_restricted_insns_priority_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_sched_restricted_insns_priority
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_sched_costly_dep_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|rs6000_dependence_cost
name|rs6000_sched_costly_dep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_sched_insert_nops_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|rs6000_nop_insertion
name|rs6000_sched_insert_nops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_warn_altivec_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|rs6000_warn_altivec_long_switch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Alignment options for fields in structures for sub-targets following    AIX-like ABI.    ALIGN_POWER word-aligns FP doubles (default AIX ABI).    ALIGN_NATURAL doubleword-aligns FP doubles (align to object size).     Override the macro definitions when compiling libobjc to avoid undefined    reference to rs6000_alignment_flags due to library's use of GCC alignment    macros which use the macros below.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN_TARGET_LIBS
end_ifndef

begin_define
define|#
directive|define
name|MASK_ALIGN_POWER
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MASK_ALIGN_NATURAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TARGET_ALIGN_NATURAL
value|(rs6000_alignment_flags& MASK_ALIGN_NATURAL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ALIGN_NATURAL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_128
value|(rs6000_long_double_type_size == 128)
end_define

begin_define
define|#
directive|define
name|TARGET_ALTIVEC_ABI
value|rs6000_altivec_abi
end_define

begin_define
define|#
directive|define
name|TARGET_ALTIVEC_VRSAVE
value|rs6000_altivec_vrsave
end_define

begin_define
define|#
directive|define
name|TARGET_SPE_ABI
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_SPE
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_E500
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_ISEL
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_FPRS
value|1
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.     Do not use this macro to turn on various extra optimizations for    `-O'.  That is what `OPTIMIZATION_OPTIONS' is for.     On the RS/6000 this is used to define the target cpu type.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|rs6000_override_options (TARGET_CPU_DEFAULT)
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
comment|/* Show we can debug even without a frame pointer.  */
end_comment

begin_define
define|#
directive|define
name|CAN_DEBUG_WITHOUT_FP
end_define

begin_comment
comment|/* Target pragma.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_TARGET_PRAGMAS
parameter_list|()
value|do {				\   c_register_pragma (0, "longcall", rs6000_pragma_longcall);	\ } while (0)
end_define

begin_comment
comment|/* Target #defines.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|rs6000_cpu_cpp_builtins (pfile)
end_define

begin_comment
comment|/* This is used by rs6000_cpu_cpp_builtins to indicate the byte order    we're compiling for.  Some configurations may need to override it.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_CPU_CPP_ENDIAN_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       if (BYTES_BIG_ENDIAN)			\ 	{					\ 	  builtin_define ("__BIG_ENDIAN__");	\ 	  builtin_define ("_BIG_ENDIAN");	\ 	  builtin_assert ("machine=bigendian");	\ 	}					\       else					\ 	{					\ 	  builtin_define ("__LITTLE_ENDIAN__");	\ 	  builtin_define ("_LITTLE_ENDIAN");	\ 	  builtin_assert ("machine=littleendian"); \ 	}					\     }						\   while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Target machine storage layout.  */
end_comment

begin_comment
comment|/* Define this macro if it is advisable to hold scalars in registers    in a wider mode than that declared by the program.  In such cases,    the value is constrained to be within the bounds of the declared    type, but kept valid in the wider mode.  The signedness of the    extension may differ from that of the type.  */
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
value|if (GET_MODE_CLASS (MODE) == MODE_INT		\&& GET_MODE_SIZE (MODE)< UNITS_PER_WORD) \     (MODE) = TARGET_32BIT ? SImode : DImode;
end_define

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.  */
end_comment

begin_comment
comment|/* That is true on RS/6000.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* That is true on RS/6000.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered.     For RS/6000 we can decide arbitrarily since there are no machine    instructions for them.  Might as well be consistent with bits and bytes.  */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
value|64
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|(! TARGET_POWERPC64 ? 4 : 8)
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
value|UNITS_PER_WORD
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

begin_define
define|#
directive|define
name|UNITS_PER_FP_WORD
value|8
end_define

begin_define
define|#
directive|define
name|UNITS_PER_ALTIVEC_WORD
value|16
end_define

begin_define
define|#
directive|define
name|UNITS_PER_SPE_WORD
value|8
end_define

begin_comment
comment|/* Type used for ptrdiff_t, as a string used in a declaration.  */
end_comment

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_comment
comment|/* Type used for size_t, as a string used in a declaration.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_comment
comment|/* Type used for wchar_t, as a string used in a declaration.  */
end_comment

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_comment
comment|/* Width of wchar_t in bits.  */
end_comment

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
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
comment|/* A C expression for the size in bits of the type `int' on the    target machine.  If you don't define this, the default is one    word.  */
end_comment

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* A C expression for the size in bits of the type `long' on the    target machine.  If you don't define this, the default is one    word.  */
end_comment

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|(TARGET_32BIT ? 32 : 64)
end_define

begin_define
define|#
directive|define
name|MAX_LONG_TYPE_SIZE
value|64
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
value|rs6000_long_double_type_size
end_define

begin_comment
comment|/* Constant which presents upper bound of the above value.  */
end_comment

begin_define
define|#
directive|define
name|MAX_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_comment
comment|/* Define this to set long double type size to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LONG_DOUBLE_128__
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
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Work around rs6000_long_double_type_size dependency in ada/targtyps.c.  */
end_comment

begin_define
define|#
directive|define
name|WIDEST_HARDWARE_FP_SIZE
value|64
end_define

begin_comment
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|(TARGET_32BIT ? 32 : 64)
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|(TARGET_32BIT ? 32 : 64)
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
define|\
value|((TARGET_32BIT&& !TARGET_ALTIVEC&& !TARGET_ALTIVEC_ABI) ? 64 : 128)
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
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|128
end_define

begin_comment
comment|/* A C expression to compute the alignment for a variables in the    local store.  TYPE is the data type, and ALIGN is the alignment    that the object would ordinarily have.  */
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
value|((TARGET_ALTIVEC&& TREE_CODE (TYPE) == VECTOR_TYPE) ? 128 :	\     (TARGET_SPE&& TREE_CODE (TYPE) == VECTOR_TYPE) ? 64 : ALIGN)
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

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* Return 1 if a structure or array containing FIELD should be    accessed using `BLKMODE'.     For the SPE, simd types are V2SI, and gcc can be tempted to put the    entire thing in a DI and use subregs to access the internals.    store_bit_field() will force (subreg:DI (reg:V2SI x))'s to the    back-end.  Because a single GPR can hold a V2SI, but not a DI, the    best thing to do is set structs to BLKmode and avoid Severe Tire    Damage.  */
end_comment

begin_define
define|#
directive|define
name|MEMBER_TYPE_FORCES_BLK
parameter_list|(
name|FIELD
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TARGET_SPE&& TREE_CODE (TREE_TYPE (FIELD)) == VECTOR_TYPE)
end_define

begin_comment
comment|/* A bit-field declared as `int' forces `int' alignment for the struct.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Make strings word-aligned so strcpy from constants will be faster.    Make vector constants quadword aligned.  */
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
value|(TREE_CODE (EXP) == STRING_CST	                         \&& (ALIGN)< BITS_PER_WORD                                    \    ? BITS_PER_WORD                                               \    : (ALIGN))
end_define

begin_comment
comment|/* Make arrays of chars word-aligned for the same reasons.    Align vectors to 128 bits.  */
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
value|(TREE_CODE (TYPE) == VECTOR_TYPE ? (TARGET_SPE_ABI ? 64 : 128)	\    : TREE_CODE (TYPE) == ARRAY_TYPE		\&& TYPE_MODE (TREE_TYPE (TYPE)) == QImode	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
end_define

begin_comment
comment|/* Nonzero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|0
end_define

begin_comment
comment|/* Define this macro to be the value 1 if unaligned accesses have a cost    many times greater than aligned accesses, for example if they are    emulated in a trap handler.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_UNALIGNED_ACCESS
parameter_list|(
name|MODE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|(STRICT_ALIGNMENT							\    || (((MODE) == SFmode || (MODE) == DFmode || (MODE) == TFmode	\ 	|| (MODE) == DImode)						\&& (ALIGN)< 32))
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     RS/6000 has 32 fixed-point registers, 32 floating-point registers,    an MQ register, a count register, a link register, and 8 condition    register fields, which we view here as separate registers.  AltiVec    adds 32 vector registers and a VRsave register.     In addition, the difference between the frame and argument pointers is    a function of the number of registers saved, so we need to have a    register for AP that will later be eliminated in favor of SP or FP.    This is a normal register, but it is fixed.     We also create a pseudo register for float/int conversions, that will    really represent the memory location used.  It is represented here as    a register, in order to work around problems in allocating stack storage    in inline functions.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|113
end_define

begin_comment
comment|/* This must be included for pre gcc 3.0 glibc compatibility.  */
end_comment

begin_define
define|#
directive|define
name|PRE_GCC3_DWARF_FRAME_REGISTERS
value|77
end_define

begin_comment
comment|/* Add 32 dwarf columns for synthetic SPE registers.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_REGISTERS
value|(FIRST_PSEUDO_REGISTER + 32)
end_define

begin_comment
comment|/* The SPE has an additional 32 synthetic registers, with DWARF debug    info numbering for these registers starting at 1200.  While eh_frame    register numbering need not be the same as the debug info numbering,    we choose to number these regs for eh_frame at 1200 too.  This allows    future versions of the rs6000 backend to add hard registers and    continue to use the gcc hard register numbering for eh_frame.  If the    extra SPE registers in eh_frame were numbered starting from the    current value of FIRST_PSEUDO_REGISTER, then if FIRST_PSEUDO_REGISTER    changed we'd need to introduce a mapping in DWARF_FRAME_REGNUM to    avoid invalidating older SPE eh_frame info.     We must map them here to avoid huge unwinder tables mostly consisting    of unused space.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_REG_TO_UNWIND_COLUMN
parameter_list|(
name|r
parameter_list|)
define|\
value|((r)> 1200 ? ((r) - 1200 + FIRST_PSEUDO_REGISTER) : (r))
end_define

begin_comment
comment|/* Use gcc hard register numbering for eh_frame.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_REGNUM
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.     On RS/6000, r1 is used for the stack.  On Darwin, r2 is available    as a local register; for all other OS's r2 is the TOC pointer.     cr5 is not supposed to be used.     On System V implementations, r13 is fixed and not available for use.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 1, FIXED_R2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FIXED_R13, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1,	   \
comment|/* AltiVec registers.  */
value|\    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1						   \    , 1, 1                                          \ }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, FIXED_R13, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,	   \
comment|/* AltiVec registers.  */
value|\    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1						   \    , 1, 1                                          \ }
end_define

begin_comment
comment|/* Like `CALL_USED_REGISTERS' except this macro doesn't require that    the entire set of `FIXED_REGISTERS' be included.    (`CALL_USED_REGISTERS' must be a superset of `FIXED_REGISTERS').    This macro is optional.  If not specified, it defaults to the value    of `CALL_USED_REGISTERS'.  */
end_comment

begin_define
define|#
directive|define
name|CALL_REALLY_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, FIXED_R13, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,	   \
comment|/* AltiVec registers.  */
value|\    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0						   \    , 0, 0                                          \ }
end_define

begin_define
define|#
directive|define
name|MQ_REGNO
value|64
end_define

begin_define
define|#
directive|define
name|CR0_REGNO
value|68
end_define

begin_define
define|#
directive|define
name|CR1_REGNO
value|69
end_define

begin_define
define|#
directive|define
name|CR2_REGNO
value|70
end_define

begin_define
define|#
directive|define
name|CR3_REGNO
value|71
end_define

begin_define
define|#
directive|define
name|CR4_REGNO
value|72
end_define

begin_define
define|#
directive|define
name|MAX_CR_REGNO
value|75
end_define

begin_define
define|#
directive|define
name|XER_REGNO
value|76
end_define

begin_define
define|#
directive|define
name|FIRST_ALTIVEC_REGNO
value|77
end_define

begin_define
define|#
directive|define
name|LAST_ALTIVEC_REGNO
value|108
end_define

begin_define
define|#
directive|define
name|TOTAL_ALTIVEC_REGS
value|(LAST_ALTIVEC_REGNO - FIRST_ALTIVEC_REGNO + 1)
end_define

begin_define
define|#
directive|define
name|VRSAVE_REGNO
value|109
end_define

begin_define
define|#
directive|define
name|VSCR_REGNO
value|110
end_define

begin_define
define|#
directive|define
name|SPE_ACC_REGNO
value|111
end_define

begin_define
define|#
directive|define
name|SPEFSCR_REGNO
value|112
end_define

begin_comment
comment|/* List the order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.     We allocate in the following order: 	fp0		(not saved or used for anything) 	fp13 - fp2	(not saved; incoming fp arg registers) 	fp1		(not saved; return value)  	fp31 - fp14	(saved; order given to save least number) 	cr7, cr6	(not saved or special) 	cr1		(not saved, but used for FP operations) 	cr0		(not saved, but used for arithmetic operations) 	cr4, cr3, cr2	(saved)         r0		(not saved; cannot be base reg) 	r9		(not saved; best for TImode) 	r11, r10, r8-r4	(not saved; highest used first to make less conflict) 	r3     		(not saved; return value register) 	r31 - r13	(saved; order given to save least number) 	r12		(not saved; if used for DImode or DFmode would use r13) 	mq		(not saved; best to use it if we can) 	ctr		(not saved; when we have the choice ctr is better) 	lr		(saved)         cr5, r1, r2, ap, xer, vrsave, vscr (fixed) 	spe_acc, spefscr (fixed)  	AltiVec registers: 	v0 - v1         (not saved or used for anything) 	v13 - v3        (not saved; incoming vector arg registers) 	v2              (not saved; incoming vector arg reg; return value) 	v19 - v14       (not saved or used for anything) 	v31 - v20       (saved; order given to save least number) */
end_comment

begin_if
if|#
directive|if
name|FIXED_R2
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|MAYBE_R2_AVAILABLE
end_define

begin_define
define|#
directive|define
name|MAYBE_R2_FIXED
value|2,
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAYBE_R2_AVAILABLE
value|2,
end_define

begin_define
define|#
directive|define
name|MAYBE_R2_FIXED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{32, 							\    45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34,	\    33,							\    63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51,	\    50, 49, 48, 47, 46, 					\    75, 74, 69, 68, 72, 71, 70,				\    0, MAYBE_R2_AVAILABLE				\    9, 11, 10, 8, 7, 6, 5, 4,				\    3,							\    31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19,	\    18, 17, 16, 15, 14, 13, 12,				\    64, 66, 65, 						\    73, 1, MAYBE_R2_FIXED 67, 76,			\
comment|/* AltiVec registers.  */
value|\    77, 78,						\    90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80,		\    79,							\    96, 95, 94, 93, 92, 91,				\    108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98,	\    97, 109, 110						\    , 111, 112                                              \ }
end_define

begin_comment
comment|/* True if register is floating-point.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= 32&& (N)<= 63)
end_define

begin_comment
comment|/* True if register is a condition register.  */
end_comment

begin_define
define|#
directive|define
name|CR_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= 68&& (N)<= 75)
end_define

begin_comment
comment|/* True if register is a condition register, but not cr0.  */
end_comment

begin_define
define|#
directive|define
name|CR_REGNO_NOT_CR0_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= 69&& (N)<= 75)
end_define

begin_comment
comment|/* True if register is an integer register.  */
end_comment

begin_define
define|#
directive|define
name|INT_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)<= 31 || (N) == ARG_POINTER_REGNUM)
end_define

begin_comment
comment|/* SPE SIMD registers are just the GPRs.  */
end_comment

begin_define
define|#
directive|define
name|SPE_SIMD_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)<= 31)
end_define

begin_comment
comment|/* True if register is the XER register.  */
end_comment

begin_define
define|#
directive|define
name|XER_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == XER_REGNO)
end_define

begin_comment
comment|/* True if register is an AltiVec register.  */
end_comment

begin_define
define|#
directive|define
name|ALTIVEC_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= FIRST_ALTIVEC_REGNO&& (N)<= LAST_ALTIVEC_REGNO)
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     For the SPE, GPRs are 64 bits but only 32 bits are visible in    scalar instructions.  The upper 32 bits are only available to the    SIMD instructions.     POWER and PowerPC GPRs hold 32 bits worth;    PowerPC64 GPRs and FPRs point register holds 64 bits worth.  */
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
value|(FP_REGNO_P (REGNO)							\    ? ((GET_MODE_SIZE (MODE) + UNITS_PER_FP_WORD - 1) / UNITS_PER_FP_WORD) \    : (SPE_SIMD_REGNO_P (REGNO)&& TARGET_SPE&& SPE_VECTOR_MODE (MODE))   \    ? ((GET_MODE_SIZE (MODE) + UNITS_PER_SPE_WORD - 1) / UNITS_PER_SPE_WORD) \    : ALTIVEC_REGNO_P (REGNO)						\    ? ((GET_MODE_SIZE (MODE) + UNITS_PER_ALTIVEC_WORD - 1) / UNITS_PER_ALTIVEC_WORD) \    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_define
define|#
directive|define
name|HARD_REGNO_CALL_PART_CLOBBERED
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((TARGET_32BIT&& TARGET_POWERPC64			\&& (MODE == DImode || MODE == DFmode)		\&& INT_REGNO_P (REGNO)) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|ALTIVEC_VECTOR_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == V16QImode		\ 	  || (MODE) == V8HImode		\ 	  || (MODE) == V4SFmode		\ 	  || (MODE) == V4SImode)
end_define

begin_define
define|#
directive|define
name|SPE_VECTOR_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == V4HImode          	\          || (MODE) == V2SFmode          \          || (MODE) == V1DImode          \          || (MODE) == V2SImode)
end_define

begin_comment
comment|/* Define this macro to be nonzero if the port is prepared to handle    insns involving vector mode MODE.  At the very least, it must have    move patterns for this mode.  */
end_comment

begin_define
define|#
directive|define
name|VECTOR_MODE_SUPPORTED_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((TARGET_SPE&& SPE_VECTOR_MODE (MODE))		\ 	 || (TARGET_ALTIVEC&& ALTIVEC_VECTOR_MODE (MODE)))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    For POWER and PowerPC, the GPRs can hold any mode, but values bigger    than one register cannot go past R31.  The float    registers only can hold floating modes and DImode, and CR register only    can hold CC modes.  We cannot put TImode anywhere except general    register and it must be able to fit within the register set.  */
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
value|(INT_REGNO_P (REGNO) ?						\      INT_REGNO_P (REGNO + HARD_REGNO_NREGS (REGNO, MODE) - 1)	        \    : FP_REGNO_P (REGNO) ?						\      ((GET_MODE_CLASS (MODE) == MODE_FLOAT				\&& FP_REGNO_P (REGNO + HARD_REGNO_NREGS (REGNO, MODE) - 1))	\       || (GET_MODE_CLASS (MODE) == MODE_INT				\&& GET_MODE_SIZE (MODE) == UNITS_PER_FP_WORD))		\    : ALTIVEC_REGNO_P (REGNO) ? ALTIVEC_VECTOR_MODE (MODE)		\    : SPE_SIMD_REGNO_P (REGNO)&& TARGET_SPE&& SPE_VECTOR_MODE (MODE) ? 1 \    : CR_REGNO_P (REGNO) ? GET_MODE_CLASS (MODE) == MODE_CC		\    : XER_REGNO_P (REGNO) ? (MODE) == PSImode				\    : GET_MODE_SIZE (MODE)<= UNITS_PER_WORD)
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
value|(GET_MODE_CLASS (MODE1) == MODE_FLOAT		\    ? GET_MODE_CLASS (MODE2) == MODE_FLOAT	\    : GET_MODE_CLASS (MODE2) == MODE_FLOAT	\    ? GET_MODE_CLASS (MODE1) == MODE_FLOAT	\    : GET_MODE_CLASS (MODE1) == MODE_CC		\    ? GET_MODE_CLASS (MODE2) == MODE_CC		\    : GET_MODE_CLASS (MODE2) == MODE_CC		\    ? GET_MODE_CLASS (MODE1) == MODE_CC		\    : SPE_VECTOR_MODE (MODE1)			\    ? SPE_VECTOR_MODE (MODE2)			\    : SPE_VECTOR_MODE (MODE2)			\    ? SPE_VECTOR_MODE (MODE1)			\    : ALTIVEC_VECTOR_MODE (MODE1)		\    ? ALTIVEC_VECTOR_MODE (MODE2)		\    : ALTIVEC_VECTOR_MODE (MODE2)		\    ? ALTIVEC_VECTOR_MODE (MODE1)		\    : 1)
end_define

begin_comment
comment|/* Post-reload, we can't use any new AltiVec registers, as we already    emitted the vrsave mask.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_RENAME_OK
parameter_list|(
name|SRC
parameter_list|,
name|DST
parameter_list|)
define|\
value|(! ALTIVEC_REGNO_P (DST) || regs_ever_live[DST])
end_define

begin_comment
comment|/* A C expression returning the cost of moving data from a register of class    CLASS1 to one of CLASS2.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
value|rs6000_register_move_cost
end_define

begin_comment
comment|/* A C expressions returning the cost of moving data of MODE from a register to    or from memory.  */
end_comment

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
value|rs6000_memory_move_cost
end_define

begin_comment
comment|/* Specify the cost of a branch insn; roughly the number of extra insns that    should be added to avoid a branch.     Set this to 3 on the RS/6000 since that is roughly the average cost of an    unscheduled conditional branch.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
value|3
end_define

begin_comment
comment|/* Override BRANCH_COST heuristic which empirically produces worse    performance for fold_range_test().  */
end_comment

begin_define
define|#
directive|define
name|RANGE_TEST_NON_SHORT_CIRCUIT
value|0
end_define

begin_comment
comment|/* A fixed register used at prologue and epilogue generation to fix    addressing modes.  The SPE needs heavy addressing fixes at the last    minute, and it's best to save a register for it.     AltiVec also needs fixes, but we've gotten around using r11, which    is actually wrong because when use_backchain_to_restore_sp is true,    we end up clobbering r11.     The AltiVec case needs to be fixed.  Dunno if we should break ABI    compatibility and reserve a register for it as well..  */
end_comment

begin_define
define|#
directive|define
name|FIXED_SCRATCH
value|(TARGET_SPE ? 14 : 11)
end_define

begin_comment
comment|/* Define this macro to change register usage conditional on target flags.    Set MQ register fixed (already call_used) if not POWER architecture    (RIOS1, RIOS2, RSC, and PPC601) so that it will not be allocated.    64-bit AIX reserves GPR13 for thread-private data.    Conditionally disable FPRs.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{									\   int i;								\   if (! TARGET_POWER)							\     fixed_regs[64] = 1;							\   if (TARGET_64BIT)							\     fixed_regs[13] = call_used_regs[13]					\       = call_really_used_regs[13] = 1; 					\   if (TARGET_SOFT_FLOAT || !TARGET_FPRS)				\     for (i = 32; i< 64; i++)						\       fixed_regs[i] = call_used_regs[i]					\         = call_really_used_regs[i] = 1;					\   if (DEFAULT_ABI == ABI_V4						\&& PIC_OFFSET_TABLE_REGNUM != INVALID_REGNUM			\&& flag_pic == 2)							\     fixed_regs[RS6000_PIC_OFFSET_TABLE_REGNUM] = 1;			\   if (DEFAULT_ABI == ABI_V4						\&& PIC_OFFSET_TABLE_REGNUM != INVALID_REGNUM			\&& flag_pic == 1)							\     fixed_regs[RS6000_PIC_OFFSET_TABLE_REGNUM]				\       = call_used_regs[RS6000_PIC_OFFSET_TABLE_REGNUM]			\       = call_really_used_regs[RS6000_PIC_OFFSET_TABLE_REGNUM] = 1;	\   if (DEFAULT_ABI == ABI_DARWIN						\&& PIC_OFFSET_TABLE_REGNUM != INVALID_REGNUM)			\     global_regs[RS6000_PIC_OFFSET_TABLE_REGNUM]				\       = fixed_regs[RS6000_PIC_OFFSET_TABLE_REGNUM]			\       = call_used_regs[RS6000_PIC_OFFSET_TABLE_REGNUM]			\       = call_really_used_regs[RS6000_PIC_OFFSET_TABLE_REGNUM] = 1;	\   if (TARGET_TOC&& TARGET_MINIMAL_TOC)					\     fixed_regs[RS6000_PIC_OFFSET_TABLE_REGNUM]				\       = call_used_regs[RS6000_PIC_OFFSET_TABLE_REGNUM] = 1;		\   if (TARGET_ALTIVEC)                                                   \     global_regs[VSCR_REGNO] = 1;                                        \   if (TARGET_SPE)							\     {                                                                   \       global_regs[SPEFSCR_REGNO] = 1;					\       fixed_regs[FIXED_SCRATCH]						\         = call_used_regs[FIXED_SCRATCH]					\ 	= call_really_used_regs[FIXED_SCRATCH] = 1; 			\     }                                                                   \   if (! TARGET_ALTIVEC)							\     {									\       for (i = FIRST_ALTIVEC_REGNO; i<= LAST_ALTIVEC_REGNO; ++i)	\ 	fixed_regs[i] = call_used_regs[i] = call_really_used_regs[i] = 1; \       call_really_used_regs[VRSAVE_REGNO] = 1;				\     }									\   if (TARGET_ALTIVEC_ABI)						\     for (i = FIRST_ALTIVEC_REGNO; i< FIRST_ALTIVEC_REGNO + 20; ++i)	\       call_used_regs[i] = call_really_used_regs[i] = 1;			\ }
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* RS/6000 pc isn't overloaded on a register that the compiler knows about.  */
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
value|1
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|31
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
value|67
end_define

begin_comment
comment|/* Place to put static chain when calling a function that requires it.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|11
end_define

begin_comment
comment|/* Link register number.  */
end_comment

begin_define
define|#
directive|define
name|LINK_REGISTER_REGNUM
value|65
end_define

begin_comment
comment|/* Count register number.  */
end_comment

begin_define
define|#
directive|define
name|COUNT_REGISTER_REGNUM
value|66
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The RS/6000 has three types of registers, fixed-point, floating-point,    and condition registers, plus three special registers, MQ, CTR, and the    link register.  AltiVec adds a vector register class.     However, r0 is special in that it cannot be used as a base register.    So make a class for registers valid as base registers.     Also, cr0 is the only condition code register that can be used in    arithmetic insns, so make a separate class for it.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|BASE_REGS
block|,
name|GENERAL_REGS
block|,
name|FLOAT_REGS
block|,
name|ALTIVEC_REGS
block|,
name|VRSAVE_REGS
block|,
name|VSCR_REGS
block|,
name|SPE_ACC_REGS
block|,
name|SPEFSCR_REGS
block|,
name|NON_SPECIAL_REGS
block|,
name|MQ_REGS
block|,
name|LINK_REGS
block|,
name|CTR_REGS
block|,
name|LINK_OR_CTR_REGS
block|,
name|SPECIAL_REGS
block|,
name|SPEC_OR_GEN_REGS
block|,
name|CR0_REGS
block|,
name|CR_REGS
block|,
name|NON_FLOAT_REGS
block|,
name|XER_REGS
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
comment|/* Give names of register classes as strings for dump file.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{									\   "NO_REGS",								\   "BASE_REGS",								\   "GENERAL_REGS",							\   "FLOAT_REGS",								\   "ALTIVEC_REGS",							\   "VRSAVE_REGS",							\   "VSCR_REGS",								\   "SPE_ACC_REGS",                                                       \   "SPEFSCR_REGS",                                                       \   "NON_SPECIAL_REGS",							\   "MQ_REGS",								\   "LINK_REGS",								\   "CTR_REGS",								\   "LINK_OR_CTR_REGS",							\   "SPECIAL_REGS",							\   "SPEC_OR_GEN_REGS",							\   "CR0_REGS",								\   "CR_REGS",								\   "NON_FLOAT_REGS",							\   "XER_REGS",								\   "ALL_REGS"								\ }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{									     \   { 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
comment|/* NO_REGS */
value|\   { 0xfffffffe, 0x00000000, 0x00000008, 0x00000000 },
comment|/* BASE_REGS */
value|\   { 0xffffffff, 0x00000000, 0x00000008, 0x00000000 },
comment|/* GENERAL_REGS */
value|\   { 0x00000000, 0xffffffff, 0x00000000, 0x00000000 },
comment|/* FLOAT_REGS */
value|\   { 0x00000000, 0x00000000, 0xffffe000, 0x00001fff },
comment|/* ALTIVEC_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000000, 0x00002000 },
comment|/* VRSAVE_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000000, 0x00004000 },
comment|/* VSCR_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000000, 0x00008000 },
comment|/* SPE_ACC_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000000, 0x00010000 },
comment|/* SPEFSCR_REGS */
value|\   { 0xffffffff, 0xffffffff, 0x00000008, 0x00000000 },
comment|/* NON_SPECIAL_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000001, 0x00000000 },
comment|/* MQ_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000002, 0x00000000 },
comment|/* LINK_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000004, 0x00000000 },
comment|/* CTR_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000006, 0x00000000 },
comment|/* LINK_OR_CTR_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000007, 0x00002000 },
comment|/* SPECIAL_REGS */
value|\   { 0xffffffff, 0x00000000, 0x0000000f, 0x00000000 },
comment|/* SPEC_OR_GEN_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000010, 0x00000000 },
comment|/* CR0_REGS */
value|\   { 0x00000000, 0x00000000, 0x00000ff0, 0x00000000 },
comment|/* CR_REGS */
value|\   { 0xffffffff, 0x00000000, 0x0000efff, 0x00000000 },
comment|/* NON_FLOAT_REGS */
value|\   { 0x00000000, 0x00000000, 0x00001000, 0x00000000 },
comment|/* XER_REGS */
value|\   { 0xffffffff, 0xffffffff, 0xffffffff, 0x00003fff }
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
define|\
value|((REGNO) == 0 ? GENERAL_REGS			\   : (REGNO)< 32 ? BASE_REGS			\   : FP_REGNO_P (REGNO) ? FLOAT_REGS		\   : ALTIVEC_REGNO_P (REGNO) ? ALTIVEC_REGS	\   : (REGNO) == CR0_REGNO ? CR0_REGS		\   : CR_REGNO_P (REGNO) ? CR_REGS		\   : (REGNO) == MQ_REGNO ? MQ_REGS		\   : (REGNO) == LINK_REGISTER_REGNUM ? LINK_REGS	\   : (REGNO) == COUNT_REGISTER_REGNUM ? CTR_REGS	\   : (REGNO) == ARG_POINTER_REGNUM ? BASE_REGS	\   : (REGNO) == XER_REGNO ? XER_REGS		\   : (REGNO) == VRSAVE_REGNO ? VRSAVE_REGS	\   : (REGNO) == VSCR_REGNO ? VRSAVE_REGS	\   : (REGNO) == SPE_ACC_REGNO ? SPE_ACC_REGS	\   : (REGNO) == SPEFSCR_REGNO ? SPEFSCR_REGS	\   : NO_REGS)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|GENERAL_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|BASE_REGS
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
value|((C) == 'f' ? FLOAT_REGS	\    : (C) == 'b' ? BASE_REGS	\    : (C) == 'h' ? SPECIAL_REGS	\    : (C) == 'q' ? MQ_REGS	\    : (C) == 'c' ? CTR_REGS	\    : (C) == 'l' ? LINK_REGS	\    : (C) == 'v' ? ALTIVEC_REGS	\    : (C) == 'x' ? CR0_REGS	\    : (C) == 'y' ? CR_REGS	\    : (C) == 'z' ? XER_REGS	\    : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L, M, N, and P in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     `I' is a signed 16-bit constant    `J' is a constant with only the high-order 16 bits nonzero    `K' is a constant with only the low-order 16 bits nonzero    `L' is a signed 16-bit constant shifted left 16 bits    `M' is a constant that is greater than 31    `N' is a positive constant that is an exact power of two    `O' is the constant zero    `P' is a constant whose negation is a signed 16-bit constant */
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
value|( (C) == 'I' ? (unsigned HOST_WIDE_INT) ((VALUE) + 0x8000)< 0x10000	\    : (C) == 'J' ? ((VALUE)& (~ (unsigned HOST_WIDE_INT) 0xffff0000)) == 0 \    : (C) == 'K' ? ((VALUE)& (~ (HOST_WIDE_INT) 0xffff)) == 0		\    : (C) == 'L' ? (((VALUE)& 0xffff) == 0				\&& ((VALUE)>> 31 == -1 || (VALUE)>> 31 == 0))	\    : (C) == 'M' ? (VALUE)> 31						\    : (C) == 'N' ? (VALUE)> 0&& exact_log2 (VALUE)>= 0		\    : (C) == 'O' ? (VALUE) == 0						\    : (C) == 'P' ? (unsigned HOST_WIDE_INT) ((- (VALUE)) + 0x8000)< 0x10000 \    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.     We flag for special constants when we can copy the constant into    a general register in two insns for DF/DI and one insn for SF.     'H' is used for DI/DF constants that take 3 insns.  */
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
value|(  (C) == 'G' ? (num_insns_constant (VALUE, GET_MODE (VALUE))		\ 		   == ((GET_MODE (VALUE) == SFmode) ? 1 : 2))		\    : (C) == 'H' ? (num_insns_constant (VALUE, GET_MODE (VALUE)) == 3)	\    : 0)
end_define

begin_comment
comment|/* Optional extra constraints for this machine.     'Q' means that is a memory operand that is just an offset from a reg.    'R' is for AIX TOC entries.    'S' is a constant that can be placed into a 64-bit mask operand    'T' is a constant that can be placed into a 32-bit mask operand    'U' is for V.4 small data references.    'W' is a vector constant that can be easily generated (no mem refs).    'Y' is a indexed or word-aligned displacement memory operand.     't' is for AND masks that can be performed by two rldic{l,r} insns.  */
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
value|((C) == 'Q' ? GET_CODE (OP) == MEM&& GET_CODE (XEXP (OP, 0)) == REG	\    : (C) == 'R' ? legitimate_constant_pool_address_p (OP)		\    : (C) == 'S' ? mask64_operand (OP, DImode)				\    : (C) == 'T' ? mask_operand (OP, SImode)				\    : (C) == 'U' ? (DEFAULT_ABI == ABI_V4				\&& small_data_operand (OP, GET_MODE (OP)))		\    : (C) == 't' ? (mask64_2_operand (OP, DImode)			\&& (fixed_regs[CR0_REGNO]				\ 		       || !logical_operand (OP, DImode))		\&& !mask64_operand (OP, DImode))			\    : (C) == 'W' ? (easy_vector_constant (OP, GET_MODE (OP)))		\    : (C) == 'Y' ? (word_offset_memref_operand (OP, GET_MODE (OP)))      \    : 0)
end_define

begin_comment
comment|/* Defining, which contraints are memory contraints. Tells reload,    that any memory address can be reloaded by copying the     memory address into a base register if required.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_MEMORY_CONSTRAINT
parameter_list|(
name|C
parameter_list|,
name|STR
parameter_list|)
define|\
value|((C) == 'Q' || (C) == 'Y')
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.     On the RS/6000, we have to return NO_REGS when we want to reload a    floating-point CONST_DOUBLE to force it to be copied to memory.       We also don't want to reload integer values into floating-point    registers if we can at all help it.  In fact, this can    cause reload to abort, if it tries to generate a reload of CTR    into a FP register and discovers it doesn't have the memory location    required.     ??? Would it be a good idea to have reload do the converse, that is    try to reload floating modes into FP registers if possible?  */
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
value|(((GET_CODE (X) == CONST_DOUBLE			\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT)	\     ? NO_REGS 						\     : (GET_MODE_CLASS (GET_MODE (X)) == MODE_INT 	\&& (CLASS) == NON_SPECIAL_REGS)			\     ? GENERAL_REGS					\     : (CLASS)))
end_define

begin_define
define|#
directive|define
name|DISPARAGE_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|(GET_CODE (X) == REG						\&& REGNO (X)< FIRST_PSEUDO_REGISTER				\&& SECONDARY_MEMORY_NEEDED (GET_MODE_CLASS (GET_MODE (X)),	\ 			       CLASS, GET_MODE (X))		\    ? 6 : 0)
end_define

begin_comment
comment|/* Return the register class of a scratch register needed to copy IN into    or out of a register in CLASS in MODE.  If it can be done directly,    NO_REGS is returned.  */
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
value|secondary_reload_class (CLASS, MODE, IN, 1)
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
name|IN
parameter_list|)
define|\
value|secondary_reload_class (CLASS, MODE, IN, 0)
end_define

begin_comment
comment|/* If we are copying between FP or AltiVec registers and anything    else, we need a memory location.  */
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
value|((CLASS1) != (CLASS2)&& ((CLASS1) == FLOAT_REGS		\ 			   || (CLASS2) == FLOAT_REGS		\ 			   || (CLASS1) == ALTIVEC_REGS		\ 			   || (CLASS2) == ALTIVEC_REGS))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.     On RS/6000, this is the size of MODE in words,    except in the FP regs, where a single reg is enough for two words.  */
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
value|(((CLASS) == FLOAT_REGS) 						\   ? ((GET_MODE_SIZE (MODE) + UNITS_PER_FP_WORD - 1) / UNITS_PER_FP_WORD) \   : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
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
value|(((DEFAULT_ABI == ABI_AIX || DEFAULT_ABI == ABI_DARWIN)		  \&& GET_MODE_SIZE (FROM)>= 8&& GET_MODE_SIZE (TO)>= 8)		  \    ? 0									  \    : GET_MODE_SIZE (FROM) != GET_MODE_SIZE (TO)				  \    ? reg_classes_intersect_p (FLOAT_REGS, CLASS)			  \    : (TARGET_SPE&& (SPE_VECTOR_MODE (FROM) + SPE_VECTOR_MODE (TO)) == 1) \    ? reg_classes_intersect_p (GENERAL_REGS, CLASS)			  \    : 0)
end_define

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Enumeration to give which calling sequence to use.  */
end_comment

begin_enum
enum|enum
name|rs6000_abi
block|{
name|ABI_NONE
block|,
name|ABI_AIX
block|,
comment|/* IBM's AIX */
name|ABI_V4
block|,
comment|/* System V.4/eabi */
name|ABI_DARWIN
comment|/* Apple's Darwin (OS X kernel) */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|rs6000_abi
name|rs6000_current_abi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* available for use by subtarget */
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
comment|/* Offsets recorded in opcodes are a multiple of this alignment factor.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_CIE_DATA_ALIGNMENT
value|(-((int) (TARGET_32BIT ? 4 : 8)))
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.     On the RS/6000, we grow upwards, from the area after the outgoing    arguments.  */
end_comment

begin_comment
comment|/* #define FRAME_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Size of the outgoing register save area */
end_comment

begin_define
define|#
directive|define
name|RS6000_REG_SAVE
value|((DEFAULT_ABI == ABI_AIX			\ 			  || DEFAULT_ABI == ABI_DARWIN)			\ 			 ? (TARGET_64BIT ? 64 : 32)			\ 			 : 0)
end_define

begin_comment
comment|/* Size of the fixed area on the stack */
end_comment

begin_define
define|#
directive|define
name|RS6000_SAVE_AREA
define|\
value|(((DEFAULT_ABI == ABI_AIX || DEFAULT_ABI == ABI_DARWIN) ? 24 : 8)	\<< (TARGET_64BIT ? 1 : 0))
end_define

begin_comment
comment|/* MEM representing address to save the TOC register */
end_comment

begin_define
define|#
directive|define
name|RS6000_SAVE_TOC
value|gen_rtx_MEM (Pmode, \ 				     plus_constant (stack_pointer_rtx, \ 						    (TARGET_32BIT ? 20 : 40)))
end_define

begin_comment
comment|/* Size of the V.4 varargs area if needed */
end_comment

begin_define
define|#
directive|define
name|RS6000_VARARGS_AREA
value|0
end_define

begin_comment
comment|/* Align an address */
end_comment

begin_define
define|#
directive|define
name|RS6000_ALIGN
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
value|(((n) + (a) - 1)& ~((a) - 1))
end_define

begin_comment
comment|/* Size of V.4 varargs area in bytes */
end_comment

begin_define
define|#
directive|define
name|RS6000_VARARGS_SIZE
define|\
value|((GP_ARG_NUM_REG * (TARGET_32BIT ? 4 : 8)) + (FP_ARG_NUM_REG * 8) + 8)
end_define

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.     On the RS/6000, the frame pointer is the same as the stack pointer,    except for dynamic allocations.  So we start after the fixed area and    outgoing parameter area.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
define|\
value|(RS6000_ALIGN (current_function_outgoing_args_size,			\ 		 TARGET_ALTIVEC ? 16 : 8)				\    + RS6000_VARARGS_AREA						\    + RS6000_SAVE_AREA)
end_define

begin_comment
comment|/* Offset from the stack pointer register to an item dynamically    allocated on the stack, e.g., by `alloca'.     The default value for this macro is `STACK_POINTER_OFFSET' plus the    length of the outgoing arguments.  The default is correct for most    machines.  See `function.c' for details.  */
end_comment

begin_define
define|#
directive|define
name|STACK_DYNAMIC_OFFSET
parameter_list|(
name|FUNDECL
parameter_list|)
define|\
value|(RS6000_ALIGN (current_function_outgoing_args_size,			\ 		 TARGET_ALTIVEC ? 16 : 8)				\    + (STACK_POINTER_OFFSET))
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On RS/6000, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    On the RS/6000, we define the argument pointer to the start of the fixed    area.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|RS6000_SAVE_AREA
end_define

begin_comment
comment|/* Offset from the argument pointer register value to the top of    stack.  This is different from FIRST_PARM_OFFSET because of the    register save area.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_CFA_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_comment
comment|/* Define this if stack space is still allocated for a parameter passed    in a register.  The value is the number of bytes allocated to this    area.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|FNDECL
parameter_list|)
value|RS6000_REG_SAVE
end_define

begin_comment
comment|/* Define this if the above stack space is to be considered part of the    space allocated by the caller.  */
end_comment

begin_define
define|#
directive|define
name|OUTGOING_REG_PARM_STACK_SPACE
end_define

begin_comment
comment|/* This is the difference between the logical top of stack and the actual sp.     For the RS/6000, sp points past the fixed area.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|RS6000_SAVE_AREA
end_define

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
value|rs6000_function_value ((VALTYPE), (FUNC))
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
value|rs6000_libcall_value ((MODE))
end_define

begin_comment
comment|/* DRAFT_V4_STRUCT_RET defaults off.  */
end_comment

begin_define
define|#
directive|define
name|DRAFT_V4_STRUCT_RET
value|0
end_define

begin_comment
comment|/* Let RETURN_IN_MEMORY control what happens.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* Mode of stack savearea.    FUNCTION is VOIDmode because calling convention maintains SP.    BLOCK needs Pmode for SP.    NONLOCAL needs twice Pmode to maintain both backchain and SP.  */
end_comment

begin_define
define|#
directive|define
name|STACK_SAVEAREA_MODE
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|(LEVEL == SAVE_FUNCTION ? VOIDmode	\   : LEVEL == SAVE_NONLOCAL ? (TARGET_32BIT ? DImode : TImode) : Pmode)
end_define

begin_comment
comment|/* Minimum and maximum general purpose registers used to hold arguments.  */
end_comment

begin_define
define|#
directive|define
name|GP_ARG_MIN_REG
value|3
end_define

begin_define
define|#
directive|define
name|GP_ARG_MAX_REG
value|10
end_define

begin_define
define|#
directive|define
name|GP_ARG_NUM_REG
value|(GP_ARG_MAX_REG - GP_ARG_MIN_REG + 1)
end_define

begin_comment
comment|/* Minimum and maximum floating point registers used to hold arguments.  */
end_comment

begin_define
define|#
directive|define
name|FP_ARG_MIN_REG
value|33
end_define

begin_define
define|#
directive|define
name|FP_ARG_AIX_MAX_REG
value|45
end_define

begin_define
define|#
directive|define
name|FP_ARG_V4_MAX_REG
value|40
end_define

begin_define
define|#
directive|define
name|FP_ARG_MAX_REG
value|((DEFAULT_ABI == ABI_AIX				\ 			 || DEFAULT_ABI == ABI_DARWIN)			\ 			? FP_ARG_AIX_MAX_REG : FP_ARG_V4_MAX_REG)
end_define

begin_define
define|#
directive|define
name|FP_ARG_NUM_REG
value|(FP_ARG_MAX_REG - FP_ARG_MIN_REG + 1)
end_define

begin_comment
comment|/* Minimum and maximum AltiVec registers used to hold arguments.  */
end_comment

begin_define
define|#
directive|define
name|ALTIVEC_ARG_MIN_REG
value|(FIRST_ALTIVEC_REGNO + 2)
end_define

begin_define
define|#
directive|define
name|ALTIVEC_ARG_MAX_REG
value|(ALTIVEC_ARG_MIN_REG + 11)
end_define

begin_define
define|#
directive|define
name|ALTIVEC_ARG_NUM_REG
value|(ALTIVEC_ARG_MAX_REG - ALTIVEC_ARG_MIN_REG + 1)
end_define

begin_comment
comment|/* Return registers */
end_comment

begin_define
define|#
directive|define
name|GP_ARG_RETURN
value|GP_ARG_MIN_REG
end_define

begin_define
define|#
directive|define
name|FP_ARG_RETURN
value|FP_ARG_MIN_REG
end_define

begin_define
define|#
directive|define
name|ALTIVEC_ARG_RETURN
value|(FIRST_ALTIVEC_REGNO + 2)
end_define

begin_comment
comment|/* Flags for the call/call_value rtl operations set up by function_arg */
end_comment

begin_define
define|#
directive|define
name|CALL_NORMAL
value|0x00000000
end_define

begin_comment
comment|/* no special processing */
end_comment

begin_comment
comment|/* Bits in 0x00000001 are unused.  */
end_comment

begin_define
define|#
directive|define
name|CALL_V4_CLEAR_FP_ARGS
value|0x00000002
end_define

begin_comment
comment|/* V.4, no FP args passed */
end_comment

begin_define
define|#
directive|define
name|CALL_V4_SET_FP_ARGS
value|0x00000004
end_define

begin_comment
comment|/* V.4, FP args were passed */
end_comment

begin_define
define|#
directive|define
name|CALL_LONG
value|0x00000008
end_define

begin_comment
comment|/* always call indirect */
end_comment

begin_define
define|#
directive|define
name|CALL_LIBCALL
value|0x00000010
end_define

begin_comment
comment|/* libcall */
end_comment

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.     On RS/6000, this is r3, fp1, and v2 (for AltiVec).  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == GP_ARG_RETURN							\    || ((N) == FP_ARG_RETURN&& TARGET_HARD_FLOAT)			\    || ((N) == ALTIVEC_ARG_RETURN&& TARGET_ALTIVEC&& TARGET_ALTIVEC_ABI))
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On RS/6000, these are r3-r10 and fp1-fp13.    On AltiVec, v2 - v13 are used for passing vectors.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((unsigned) (N) - GP_ARG_MIN_REG< GP_ARG_NUM_REG			\    || ((unsigned) (N) - ALTIVEC_ARG_MIN_REG< ALTIVEC_ARG_NUM_REG	\&& TARGET_ALTIVEC&& TARGET_ALTIVEC_ABI)				\    || ((unsigned) (N) - FP_ARG_MIN_REG< FP_ARG_NUM_REG			\&& TARGET_HARD_FLOAT))
end_define

begin_escape
end_escape

begin_comment
comment|/* A C structure for machine-specific, per-function data.    This is added to the cfun structure.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|machine_function
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Whether a System V.4 varargs area was created.  */
name|int
name|sysv_varargs_p
block|;
comment|/* Flags if __builtin_return_address (n) with n>= 1 was used.  */
name|int
name|ra_needs_full_frame
block|;
comment|/* Some local-dynamic symbol.  */
specifier|const
name|char
modifier|*
name|some_ld_name
block|;
comment|/* Whether the instruction chain has been scanned already.  */
name|int
name|insn_chain_scanned_p
block|;
comment|/* Flags if __builtin_return_address (0) was used.  */
name|int
name|ra_need_lr
block|; }
end_typedef

begin_expr_stmt
name|machine_function
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the RS/6000, this is a structure.  The first element is the number of    total argument words, the second is used to store the next    floating-point register number, and the third says how many more args we    have prototype types for.     For ABI_V4, we treat these slightly differently -- `sysv_gregno' is    the next available GP register, `fregno' is the next available FP    register, and `words' is the number of words used on the stack.     The varargs/stdarg support requires that this structure's size    be a multiple of sizeof(int).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rs6000_args
block|{
name|int
name|words
decl_stmt|;
comment|/* # words used for passing GP registers */
name|int
name|fregno
decl_stmt|;
comment|/* next available FP register */
name|int
name|vregno
decl_stmt|;
comment|/* next available AltiVec register */
name|int
name|nargs_prototype
decl_stmt|;
comment|/* # args left in the current prototype */
name|int
name|prototype
decl_stmt|;
comment|/* Whether a prototype was defined */
name|int
name|stdarg
decl_stmt|;
comment|/* Whether function is a stdarg function.  */
name|int
name|call_cookie
decl_stmt|;
comment|/* Do special things for this call */
name|int
name|sysv_gregno
decl_stmt|;
comment|/* next available GP register */
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
parameter_list|,
name|N_NAMED_ARGS
parameter_list|)
define|\
value|init_cumulative_args (&CUM, FNTYPE, LIBNAME, FALSE, FALSE, N_NAMED_ARGS)
end_define

begin_comment
comment|/* Similar, but when scanning the definition of a procedure.  We always    set NARGS_PROTOTYPE large so we never return an EXPR_LIST.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_INCOMING_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|LIBNAME
parameter_list|)
define|\
value|init_cumulative_args (&CUM, FNTYPE, LIBNAME, TRUE, FALSE, 1000)
end_define

begin_comment
comment|/* Like INIT_CUMULATIVE_ARGS' but only used for outgoing libcalls.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_LIBCALL_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|LIBNAME
parameter_list|)
define|\
value|init_cumulative_args (&CUM, NULL_TREE, LIBNAME, FALSE, TRUE, 0)
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
value|function_arg_advance (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On RS/6000 the first eight words of non-FP are normally in registers    and the rest are pushed.  The first 13 FP args are in registers.     If this is floating-point and no prototype is specified, we use    both an FP and integer register (or possibly FP reg and stack).  Library    functions (when TYPE is zero) always have the proper types for args,    so we can pass the FP value just in one register.  emit_library_function    doesn't support EXPR_LIST anyway.  */
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
value|function_arg (&CUM, MODE, TYPE, NAMED)
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
value|function_arg_partial_nregs (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* A C expression that indicates when an argument must be passed by    reference.  If nonzero for an argument, a copy of that argument is    made in memory and a pointer to the argument is passed instead of    the argument itself.  The pointer is passed in whatever way is    appropriate for passing a pointer to that type.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PASS_BY_REFERENCE
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
value|function_arg_pass_by_reference(&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* If defined, a C expression which determines whether, and in which    direction, to pad out an argument with extra space.  The value    should be of type `enum direction': either `upward' to pad above    the argument, `downward' to pad below, or `none' to inhibit    padding.  */
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
value|function_arg_padding (MODE, TYPE)
end_define

begin_comment
comment|/* If defined, a C expression that gives the alignment boundary, in bits,    of an argument with the specified mode and type.  If it is not defined,    PARM_BOUNDARY is used for all arguments.  */
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
value|function_arg_boundary (MODE, TYPE)
end_define

begin_comment
comment|/* Implement `va_start' for varargs and stdarg.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_START
parameter_list|(
name|valist
parameter_list|,
name|nextarg
parameter_list|)
define|\
value|rs6000_va_start (valist, nextarg)
end_define

begin_comment
comment|/* Implement `va_arg'.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_ARG
parameter_list|(
name|valist
parameter_list|,
name|type
parameter_list|)
define|\
value|rs6000_va_arg (valist, type)
end_define

begin_define
define|#
directive|define
name|PAD_VARARGS_DOWN
define|\
value|(FUNCTION_ARG_PADDING (TYPE_MODE (type), type) == downward)
end_define

begin_comment
comment|/* Define this macro to be a nonzero value if the location where a function    argument is passed depends on whether or not it is a named argument.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ARGUMENT_NAMING
value|1
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
value|output_function_profiler ((FILE), (LABELNO));
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter. No definition is equivalent to    always zero.     On the RS/6000, this is nonzero because we can restore the stack from    its backpointer, which we maintain.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_comment
comment|/* Define this macro as a C expression that is nonzero for registers    that are used by the epilogue or the return' pattern.  The stack    and frame pointer registers are already be assumed to be used as    needed.  */
end_comment

begin_define
define|#
directive|define
name|EPILOGUE_USES
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((reload_completed&& (REGNO) == LINK_REGISTER_REGNUM)	\    || (TARGET_ALTIVEC&& (REGNO) == VRSAVE_REGNO)		\    || (current_function_calls_eh_return				\&& TARGET_AIX						\&& (REGNO) == 2))
end_define

begin_escape
end_escape

begin_comment
comment|/* TRAMPOLINE_TEMPLATE deleted */
end_comment

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|rs6000_trampoline_size ()
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|ADDR
parameter_list|,
name|FNADDR
parameter_list|,
name|CXT
parameter_list|)
define|\
value|rs6000_initialize_trampoline (ADDR, FNADDR, CXT)
end_define

begin_escape
end_escape

begin_comment
comment|/* Definitions for __builtin_return_address and __builtin_frame_address.    __builtin_return_address (0) should give link register (65), enable    this.  */
end_comment

begin_comment
comment|/* This should be uncommented, so that the link register is used, but    currently this would result in unmatched insns and spilling fixed    registers so we'll leave it for another day.  When these problems are    taken care of one additional fetch will be necessary in RETURN_ADDR_RTX.    (mrs) */
end_comment

begin_comment
comment|/* #define RETURN_ADDR_IN_PREVIOUS_FRAME */
end_comment

begin_comment
comment|/* Number of bytes into the frame return addresses can be found.  See    rs6000_stack_info in rs6000.c for more information on how the different    abi's store the return address.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDRESS_OFFSET
define|\
value|((DEFAULT_ABI == ABI_AIX						\    || DEFAULT_ABI == ABI_DARWIN)	? (TARGET_32BIT ? 8 : 16) :	\   (DEFAULT_ABI == ABI_V4)		? 4 :				\   (internal_error ("RETURN_ADDRESS_OFFSET not supported"), 0))
end_define

begin_comment
comment|/* The current return address is in link register (65).  The return address    of anything farther back is accessed normally at an offset of 8 from the    frame pointer.  */
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
value|(rs6000_return_addr (COUNT, FRAME))
end_define

begin_escape
end_escape

begin_comment
comment|/* Definitions for register eliminations.     We have two registers that can be eliminated on the RS/6000.  First, the    frame pointer register can often be eliminated in favor of the stack    pointer register.  Secondly, the argument pointer register can always be    eliminated; it is replaced with either the stack or frame pointer.     In addition, we use the elimination mechanism to see if r30 is needed    Initially we assume that it isn't.  If it is, we spill it.  This is done    by making it an eliminable register.  We replace it with itself so that    if it isn't needed, then existing uses won't be modified.  */
end_comment

begin_comment
comment|/* This is an array of structures.  Each structure initializes one pair    of eliminable registers.  The "from" register number is given first,    followed by "to".  Eliminations of the same "from" register are listed    in order of preference.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},	\  { ARG_POINTER_REGNUM, STACK_POINTER_REGNUM},	\  { ARG_POINTER_REGNUM, FRAME_POINTER_REGNUM},	\  { RS6000_PIC_OFFSET_TABLE_REGNUM, RS6000_PIC_OFFSET_TABLE_REGNUM } }
end_define

begin_comment
comment|/* Given FROM and TO register numbers, say whether this elimination is allowed.    Frame pointer elimination is automatically handled.     For the RS/6000, if frame pointer elimination is being done, we would like    to convert ap into fp, not sp.     We need r30 if -mminimal-toc was specified, and there are constant pool    references.  */
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
value|((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM		\   ? ! frame_pointer_needed						\   : (FROM) == RS6000_PIC_OFFSET_TABLE_REGNUM 				\   ? ! TARGET_MINIMAL_TOC || TARGET_NO_TOC || get_pool_size () == 0	\   : 1)
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
value|((OFFSET) = rs6000_initial_elimination_offset(FROM, TO))
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRE_DECREMENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PRE_INCREMENT
value|1
end_define

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
value|((REGNO)< FIRST_PSEUDO_REGISTER				\  ? (REGNO)<= 31 || (REGNO) == 67				\  : (reg_renumber[REGNO]>= 0					\&& (reg_renumber[REGNO]<= 31 || reg_renumber[REGNO] == 67)))
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< FIRST_PSEUDO_REGISTER				\  ? ((REGNO)> 0&& (REGNO)<= 31) || (REGNO) == 67		\  : (reg_renumber[REGNO]> 0					\&& (reg_renumber[REGNO]<= 31 || reg_renumber[REGNO] == 67)))
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
value|2
end_define

begin_comment
comment|/* Recognize any constant value that is a valid address.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF		\    || GET_CODE (X) == CONST_INT || GET_CODE (X) == CONST		\    || GET_CODE (X) == HIGH)
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     On the RS/6000, all integer constants are acceptable, most won't be valid    for particular insns, though.  Only easy FP constants are    acceptable.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(((GET_CODE (X) != CONST_DOUBLE				\&& GET_CODE (X) != CONST_VECTOR)				\     || GET_MODE (X) == VOIDmode					\     || (TARGET_POWERPC64&& GET_MODE (X) == DImode)		\     || easy_fp_constant (X, GET_MODE (X))			\     || easy_vector_constant (X, GET_MODE (X)))			\&& !rs6000_tls_referenced_p (X))
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Source files for reload pass need to be strict.    After reload, it makes no difference, since pseudo regs have    been eliminated by then.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REG_OK_STRICT
end_ifdef

begin_define
define|#
directive|define
name|REG_OK_STRICT_FLAG
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_OK_STRICT_FLAG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index    or if it is a pseudo reg in the non-strict case.  */
end_comment

begin_define
define|#
directive|define
name|INT_REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|,
name|STRICT
parameter_list|)
define|\
value|((! (STRICT)							\&& (REGNO (X)<= 31						\ 	|| REGNO (X) == ARG_POINTER_REGNUM			\ 	|| REGNO (X)>= FIRST_PSEUDO_REGISTER))			\    || ((STRICT)&& REGNO_OK_FOR_INDEX_P (REGNO (X))))
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg    or if it is a pseudo reg in the non-strict case.  */
end_comment

begin_define
define|#
directive|define
name|INT_REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|,
name|STRICT
parameter_list|)
define|\
value|(REGNO (X)> 0&& INT_REG_OK_FOR_INDEX_P (X, (STRICT)))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|INT_REG_OK_FOR_INDEX_P (X, REG_OK_STRICT_FLAG)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|INT_REG_OK_FOR_BASE_P (X, REG_OK_STRICT_FLAG)
end_define

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On the RS/6000, there are four valid address: a SYMBOL_REF that    refers to a constant pool entry of an address (or the sum of it    plus a constant), a short (16-bit signed) constant plus a register,    the sum of two registers, or a register indirect, possibly with an    auto-increment.  For DFmode and DImode with a constant plus register,    we must ensure that both words are addressable or PowerPC64 with offset    word aligned.     For modes spanning multiple registers (DFmode in 32-bit GPRs,    32-bit DImode, TImode), indexed addressing cannot be used because    adjacent memory cells are accessed by adding word-sized offsets    during assembly output.  */
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
value|{ if (rs6000_legitimate_address (MODE, X, REG_OK_STRICT_FLAG))	\     goto ADDR;							\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     On RS/6000, first check for the sum of a register with a constant    integer that is out of range.  If so, generate code to add the    constant with the low-order 16 bits masked to the register and force    this result into another register (this can be done with `cau').    Then generate an address of REG+(CONST&0xffff), allowing for the    possibility of bit 16 being a one.     Then check for the sum of a register and something not constant, try to    load the other things into a register and return the sum.  */
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
value|{  rtx result = rs6000_legitimize_address (X, OLDX, MODE);	\    if (result != NULL_RTX)					\      {								\        (X) = result;						\        goto WIN;						\      }								\ }
end_define

begin_comment
comment|/* Try a machine-dependent way of reloading an illegitimate address    operand.  If we find one, push the reload and jump to WIN.  This    macro is used in only one place: `find_reloads_address' in reload.c.     Implemented on rs6000 by rs6000_legitimize_reload_address.      Note that (X) is evaluated twice; this is safe in current usage.  */
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
value|do {									     \   int win;								     \   (X) = rs6000_legitimize_reload_address ((X), (MODE), (OPNUM),		     \ 			(int)(TYPE), (IND_LEVELS),&win);		     \   if ( win )								     \     goto WIN;								     \ } while (0)
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.  */
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
value|do {								\   if (rs6000_mode_dependent_address (ADDR))			\     goto LABEL;							\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* The register number of the register used to address a table of    static data addresses in memory.  In some cases this register is    defined by a processor's "application binary interface" (ABI).    When this macro is defined, RTL is generated for this register    once, as with the stack pointer and frame pointer registers.  If    this macro is not defined, it is up to the machine-dependent files    to allocate such a register (if necessary).  */
end_comment

begin_define
define|#
directive|define
name|RS6000_PIC_OFFSET_TABLE_REGNUM
value|30
end_define

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|(flag_pic ? RS6000_PIC_OFFSET_TABLE_REGNUM : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|TOC_REGISTER
value|(TARGET_MINIMAL_TOC ? RS6000_PIC_OFFSET_TABLE_REGNUM : 2)
end_define

begin_comment
comment|/* Define this macro if the register defined by    `PIC_OFFSET_TABLE_REGNUM' is clobbered by calls.  Do not define    this macro if `PIC_OFFSET_TABLE_REGNUM' is not defined.  */
end_comment

begin_comment
comment|/* #define PIC_OFFSET_TABLE_REG_CALL_CLOBBERED */
end_comment

begin_comment
comment|/* By generating position-independent code, when two different    programs (A and B) share a common library (libC.a), the text of    the library can be shared whether or not the library is linked at    the same address for both programs.  In some of these    environments, position-independent code requires not only the use    of different addressing modes, but also special code to enable the    use of these addressing modes.     The `FINALIZE_PIC' macro serves as a hook to emit these special    codes once the function is being compiled into assembly code, but    not before.  (It is not done before, because in the case of    compiling an inline function, it would lead to multiple PIC    prologues being included in functions which used inline functions    and were compiled to assembly language.)  */
end_comment

begin_comment
comment|/* #define FINALIZE_PIC */
end_comment

begin_comment
comment|/* A C expression that is nonzero if X is a legitimate immediate    operand on the target machine when generating position independent    code.  You can assume that X satisfies `CONSTANT_P', so you need    not check this.  You can also assume FLAG_PIC is true, so you need    not check it either.  You need not define this macro if all    constants (including `SYMBOL_REF') can be immediate operands when    generating position independent code.  */
end_comment

begin_comment
comment|/* #define LEGITIMATE_PIC_OPERAND_P (X) */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Define this if some processing needs to be done immediately before    emitting code for an insn.  */
end_comment

begin_comment
comment|/* #define FINAL_PRESCAN_INSN(INSN,OPERANDS,NOPERANDS) */
end_comment

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
comment|/* Define as C expression which evaluates to nonzero if the tablejump    instruction expects the table to contain offsets from the address of the    table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_PC_RELATIVE
value|1
end_define

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_comment
comment|/* This flag, if defined, says the same insns that convert to a signed fixnum    also convert validly to an unsigned one.  */
end_comment

begin_comment
comment|/* #define FIXUNS_TRUNC_LIKE_FIX_TRUNC */
end_comment

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|(! TARGET_POWERPC64 ? 4 : 8)
end_define

begin_define
define|#
directive|define
name|MAX_MOVE_MAX
value|8
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is no faster than for words.    Also nonzero if doing byte operations (specifically shifts) in registers    is undesirable.  */
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
value|ZERO_EXTEND
end_define

begin_comment
comment|/* Define if loading short immediate values into registers sign extends.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_IMMEDIATES_SIGN_EXTEND
end_define

begin_escape
end_escape

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
comment|/* The cntlzw and cntlzd instructions return 32 and 64 for input of zero.  */
end_comment

begin_define
define|#
directive|define
name|CLZ_DEFINED_VALUE_AT_ZERO
parameter_list|(
name|MODE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|((VALUE) = ((MODE) == SImode ? 32 : 64))
end_define

begin_comment
comment|/* The CTZ patterns return -1 for input of zero.  */
end_comment

begin_define
define|#
directive|define
name|CTZ_DEFINED_VALUE_AT_ZERO
parameter_list|(
name|MODE
parameter_list|,
name|VALUE
parameter_list|)
value|((VALUE) = -1)
end_define

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|(TARGET_32BIT ? SImode : DImode)
end_define

begin_comment
comment|/* Supply definition of STACK_SIZE_MODE for allocate_dynamic_stack_space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_SIZE_MODE
value|(TARGET_32BIT ? SImode : DImode)
end_define

begin_comment
comment|/* Mode of a function address in a call instruction (for indexing purposes).    Doesn't matter on RS/6000.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|SImode
end_define

begin_comment
comment|/* Define this if addresses of constant functions    shouldn't be put through pseudo regs where they can be cse'd.    Desirable on machines where ordinary constants are expensive    but a CALL with constant address is cheap.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* Define this to be nonzero if shift instructions ignore all but the low-order    few bits.     The sle and sre instructions which allow SHIFT_COUNT_TRUNCATED    have been dropped from the PowerPC architecture.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
value|(TARGET_POWER ? 1 : 0)
end_define

begin_comment
comment|/* Adjust the length of an INSN.  LENGTH is the currently-computed length and    should be adjusted to reflect any required changes.  This macro is used when    there is some systematic length adjustment required that would be difficult    to express in the length attribute.  */
end_comment

begin_comment
comment|/* #define ADJUST_INSN_LENGTH(X,LENGTH) */
end_comment

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a    COMPARE, return the mode to be used for the comparison.  For    floating-point, CCFPmode should be used.  CCUNSmode should be used    for unsigned comparisons.  CCEQmode should be used when we are    doing an inequality comparison on the result of a    comparison.  CCmode should be used in all other cases.  */
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
value|(GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT ? CCFPmode	\    : (OP) == GTU || (OP) == LTU || (OP) == GEU || (OP) == LEU ? CCUNSmode \    : (((OP) == EQ || (OP) == NE)&& GET_RTX_CLASS (GET_CODE (X)) == '<'   \       ? CCEQmode : CCmode))
end_define

begin_comment
comment|/* Can the condition code MODE be safely reversed?  This is safe in    all cases on this port, because at present it doesn't use the    trapping FP comparisons (fcmpo).  */
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
comment|/* Given a condition code and a mode, return the inverse condition.  */
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
value|rs6000_reverse_condition (MODE, CODE)
end_define

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|rs6000_compare_op0
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|rs6000_compare_op1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_compare_fp_p
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* A C string constant describing how to begin a comment in the target    assembler language.  The compiler assumes that the comment will end at    the end of the line.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|" #"
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Flag to say the TOC is initialized */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|toc_initialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro to output a special constant pool entry.  Go to WIN if we output    it.  Otherwise, it is written the usual way.     On the RS/6000, toc entries are handled this way.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|MODE
parameter_list|,
name|ALIGN
parameter_list|,
name|LABELNO
parameter_list|,
name|WIN
parameter_list|)
define|\
value|{ if (ASM_OUTPUT_SPECIAL_POOL_ENTRY_P (X, MODE))			  \     {									  \       output_toc (FILE, X, LABELNO, MODE);				  \       goto WIN;								  \     }									  \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_WEAK
end_ifdef

begin_define
define|#
directive|define
name|RS6000_WEAK
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RS6000_WEAK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|RS6000_WEAK
end_if

begin_comment
comment|/* Used in lieu of ASM_WEAKEN_LABEL.  */
end_comment

begin_define
define|#
directive|define
name|ASM_WEAKEN_DECL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|VAL
parameter_list|)
define|\
value|do									\     {									\       fputs ("\t.weak\t", (FILE));					\       RS6000_OUTPUT_BASENAME ((FILE), (NAME)); 			\       if ((DECL)&& TREE_CODE (DECL) == FUNCTION_DECL			\&& DEFAULT_ABI == ABI_AIX)					\ 	{								\ 	  if (TARGET_XCOFF)						\ 	    fputs ("[DS]", (FILE));					\ 	  fputs ("\n\t.weak\t.", (FILE));				\ 	  RS6000_OUTPUT_BASENAME ((FILE), (NAME)); 			\ 	}								\       fputc ('\n', (FILE));						\       if (VAL)								\ 	{								\ 	  ASM_OUTPUT_DEF ((FILE), (NAME), (VAL));			\ 	  if ((DECL)&& TREE_CODE (DECL) == FUNCTION_DECL		\&& DEFAULT_ABI == ABI_AIX)				\ 	    {								\ 	      fputs ("\t.set\t.", (FILE));				\ 	      RS6000_OUTPUT_BASENAME ((FILE), (NAME));			\ 	      fputs (",.", (FILE));					\ 	      RS6000_OUTPUT_BASENAME ((FILE), (VAL));			\ 	      fputc ('\n', (FILE));					\ 	    }								\ 	}								\     }									\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This implements the `alias' attribute.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DEF_FROM_DECLS
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF_FROM_DECLS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|TARGET
parameter_list|)
define|\
value|do									\     {									\       const char *alias = XSTR (XEXP (DECL_RTL (DECL), 0), 0);		\       const char *name = IDENTIFIER_POINTER (TARGET);			\       if (TREE_CODE (DECL) == FUNCTION_DECL				\&& DEFAULT_ABI == ABI_AIX)					\ 	{								\ 	  if (TREE_PUBLIC (DECL))					\ 	    {								\ 	      if (!RS6000_WEAK || !DECL_WEAK (DECL))			\ 		{							\ 		  fputs ("\t.globl\t.", FILE);				\ 		  RS6000_OUTPUT_BASENAME (FILE, alias);			\ 		  putc ('\n', FILE);					\ 		}							\ 	    }								\ 	  else if (TARGET_XCOFF)					\ 	    {								\ 	      fputs ("\t.lglobl\t.", FILE);				\ 	      RS6000_OUTPUT_BASENAME (FILE, alias);			\ 	      putc ('\n', FILE);					\ 	    }								\ 	  fputs ("\t.set\t.", FILE);					\ 	  RS6000_OUTPUT_BASENAME (FILE, alias);				\ 	  fputs (",.", FILE);						\ 	  RS6000_OUTPUT_BASENAME (FILE, name);				\ 	  fputc ('\n', FILE);						\ 	}								\       ASM_OUTPUT_DEF (FILE, alias, name);				\     }									\    while (0)
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START
value|rs6000_file_start
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

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rs6000_reg_names
index|[]
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register names (0 vs. %r0).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{									\&rs6000_reg_names[ 0][0],
comment|/* r0   */
value|\&rs6000_reg_names[ 1][0],
comment|/* r1	*/
value|\&rs6000_reg_names[ 2][0],
comment|/* r2	*/
value|\&rs6000_reg_names[ 3][0],
comment|/* r3	*/
value|\&rs6000_reg_names[ 4][0],
comment|/* r4	*/
value|\&rs6000_reg_names[ 5][0],
comment|/* r5	*/
value|\&rs6000_reg_names[ 6][0],
comment|/* r6	*/
value|\&rs6000_reg_names[ 7][0],
comment|/* r7	*/
value|\&rs6000_reg_names[ 8][0],
comment|/* r8	*/
value|\&rs6000_reg_names[ 9][0],
comment|/* r9	*/
value|\&rs6000_reg_names[10][0],
comment|/* r10  */
value|\&rs6000_reg_names[11][0],
comment|/* r11  */
value|\&rs6000_reg_names[12][0],
comment|/* r12  */
value|\&rs6000_reg_names[13][0],
comment|/* r13  */
value|\&rs6000_reg_names[14][0],
comment|/* r14  */
value|\&rs6000_reg_names[15][0],
comment|/* r15  */
value|\&rs6000_reg_names[16][0],
comment|/* r16  */
value|\&rs6000_reg_names[17][0],
comment|/* r17  */
value|\&rs6000_reg_names[18][0],
comment|/* r18  */
value|\&rs6000_reg_names[19][0],
comment|/* r19  */
value|\&rs6000_reg_names[20][0],
comment|/* r20  */
value|\&rs6000_reg_names[21][0],
comment|/* r21  */
value|\&rs6000_reg_names[22][0],
comment|/* r22  */
value|\&rs6000_reg_names[23][0],
comment|/* r23  */
value|\&rs6000_reg_names[24][0],
comment|/* r24  */
value|\&rs6000_reg_names[25][0],
comment|/* r25  */
value|\&rs6000_reg_names[26][0],
comment|/* r26  */
value|\&rs6000_reg_names[27][0],
comment|/* r27  */
value|\&rs6000_reg_names[28][0],
comment|/* r28  */
value|\&rs6000_reg_names[29][0],
comment|/* r29  */
value|\&rs6000_reg_names[30][0],
comment|/* r30  */
value|\&rs6000_reg_names[31][0],
comment|/* r31  */
value|\ 									\&rs6000_reg_names[32][0],
comment|/* fr0  */
value|\&rs6000_reg_names[33][0],
comment|/* fr1  */
value|\&rs6000_reg_names[34][0],
comment|/* fr2  */
value|\&rs6000_reg_names[35][0],
comment|/* fr3  */
value|\&rs6000_reg_names[36][0],
comment|/* fr4  */
value|\&rs6000_reg_names[37][0],
comment|/* fr5  */
value|\&rs6000_reg_names[38][0],
comment|/* fr6  */
value|\&rs6000_reg_names[39][0],
comment|/* fr7  */
value|\&rs6000_reg_names[40][0],
comment|/* fr8  */
value|\&rs6000_reg_names[41][0],
comment|/* fr9  */
value|\&rs6000_reg_names[42][0],
comment|/* fr10 */
value|\&rs6000_reg_names[43][0],
comment|/* fr11 */
value|\&rs6000_reg_names[44][0],
comment|/* fr12 */
value|\&rs6000_reg_names[45][0],
comment|/* fr13 */
value|\&rs6000_reg_names[46][0],
comment|/* fr14 */
value|\&rs6000_reg_names[47][0],
comment|/* fr15 */
value|\&rs6000_reg_names[48][0],
comment|/* fr16 */
value|\&rs6000_reg_names[49][0],
comment|/* fr17 */
value|\&rs6000_reg_names[50][0],
comment|/* fr18 */
value|\&rs6000_reg_names[51][0],
comment|/* fr19 */
value|\&rs6000_reg_names[52][0],
comment|/* fr20 */
value|\&rs6000_reg_names[53][0],
comment|/* fr21 */
value|\&rs6000_reg_names[54][0],
comment|/* fr22 */
value|\&rs6000_reg_names[55][0],
comment|/* fr23 */
value|\&rs6000_reg_names[56][0],
comment|/* fr24 */
value|\&rs6000_reg_names[57][0],
comment|/* fr25 */
value|\&rs6000_reg_names[58][0],
comment|/* fr26 */
value|\&rs6000_reg_names[59][0],
comment|/* fr27 */
value|\&rs6000_reg_names[60][0],
comment|/* fr28 */
value|\&rs6000_reg_names[61][0],
comment|/* fr29 */
value|\&rs6000_reg_names[62][0],
comment|/* fr30 */
value|\&rs6000_reg_names[63][0],
comment|/* fr31 */
value|\ 									\&rs6000_reg_names[64][0],
comment|/* mq   */
value|\&rs6000_reg_names[65][0],
comment|/* lr   */
value|\&rs6000_reg_names[66][0],
comment|/* ctr  */
value|\&rs6000_reg_names[67][0],
comment|/* ap   */
value|\ 									\&rs6000_reg_names[68][0],
comment|/* cr0  */
value|\&rs6000_reg_names[69][0],
comment|/* cr1  */
value|\&rs6000_reg_names[70][0],
comment|/* cr2  */
value|\&rs6000_reg_names[71][0],
comment|/* cr3  */
value|\&rs6000_reg_names[72][0],
comment|/* cr4  */
value|\&rs6000_reg_names[73][0],
comment|/* cr5  */
value|\&rs6000_reg_names[74][0],
comment|/* cr6  */
value|\&rs6000_reg_names[75][0],
comment|/* cr7  */
value|\ 									\&rs6000_reg_names[76][0],
comment|/* xer  */
value|\ 									\&rs6000_reg_names[77][0],
comment|/* v0  */
value|\&rs6000_reg_names[78][0],
comment|/* v1  */
value|\&rs6000_reg_names[79][0],
comment|/* v2  */
value|\&rs6000_reg_names[80][0],
comment|/* v3  */
value|\&rs6000_reg_names[81][0],
comment|/* v4  */
value|\&rs6000_reg_names[82][0],
comment|/* v5  */
value|\&rs6000_reg_names[83][0],
comment|/* v6  */
value|\&rs6000_reg_names[84][0],
comment|/* v7  */
value|\&rs6000_reg_names[85][0],
comment|/* v8  */
value|\&rs6000_reg_names[86][0],
comment|/* v9  */
value|\&rs6000_reg_names[87][0],
comment|/* v10  */
value|\&rs6000_reg_names[88][0],
comment|/* v11  */
value|\&rs6000_reg_names[89][0],
comment|/* v12  */
value|\&rs6000_reg_names[90][0],
comment|/* v13  */
value|\&rs6000_reg_names[91][0],
comment|/* v14  */
value|\&rs6000_reg_names[92][0],
comment|/* v15  */
value|\&rs6000_reg_names[93][0],
comment|/* v16  */
value|\&rs6000_reg_names[94][0],
comment|/* v17  */
value|\&rs6000_reg_names[95][0],
comment|/* v18  */
value|\&rs6000_reg_names[96][0],
comment|/* v19  */
value|\&rs6000_reg_names[97][0],
comment|/* v20  */
value|\&rs6000_reg_names[98][0],
comment|/* v21  */
value|\&rs6000_reg_names[99][0],
comment|/* v22  */
value|\&rs6000_reg_names[100][0],
comment|/* v23  */
value|\&rs6000_reg_names[101][0],
comment|/* v24  */
value|\&rs6000_reg_names[102][0],
comment|/* v25  */
value|\&rs6000_reg_names[103][0],
comment|/* v26  */
value|\&rs6000_reg_names[104][0],
comment|/* v27  */
value|\&rs6000_reg_names[105][0],
comment|/* v28  */
value|\&rs6000_reg_names[106][0],
comment|/* v29  */
value|\&rs6000_reg_names[107][0],
comment|/* v30  */
value|\&rs6000_reg_names[108][0],
comment|/* v31  */
value|\&rs6000_reg_names[109][0],
comment|/* vrsave  */
value|\&rs6000_reg_names[110][0],
comment|/* vscr  */
value|\&rs6000_reg_names[111][0],
comment|/* spe_acc */
value|\&rs6000_reg_names[112][0],
comment|/* spefscr */
value|\ }
end_define

begin_comment
comment|/* Table of additional register names to use in user input.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{{"r0",    0}, {"r1",    1}, {"r2",    2}, {"r3",    3},	\   {"r4",    4}, {"r5",    5}, {"r6",    6}, {"r7",    7},	\   {"r8",    8}, {"r9",    9}, {"r10",  10}, {"r11",  11},	\   {"r12",  12}, {"r13",  13}, {"r14",  14}, {"r15",  15},	\   {"r16",  16}, {"r17",  17}, {"r18",  18}, {"r19",  19},	\   {"r20",  20}, {"r21",  21}, {"r22",  22}, {"r23",  23},	\   {"r24",  24}, {"r25",  25}, {"r26",  26}, {"r27",  27},	\   {"r28",  28}, {"r29",  29}, {"r30",  30}, {"r31",  31},	\   {"fr0",  32}, {"fr1",  33}, {"fr2",  34}, {"fr3",  35},	\   {"fr4",  36}, {"fr5",  37}, {"fr6",  38}, {"fr7",  39},	\   {"fr8",  40}, {"fr9",  41}, {"fr10", 42}, {"fr11", 43},	\   {"fr12", 44}, {"fr13", 45}, {"fr14", 46}, {"fr15", 47},	\   {"fr16", 48}, {"fr17", 49}, {"fr18", 50}, {"fr19", 51},	\   {"fr20", 52}, {"fr21", 53}, {"fr22", 54}, {"fr23", 55},	\   {"fr24", 56}, {"fr25", 57}, {"fr26", 58}, {"fr27", 59},	\   {"fr28", 60}, {"fr29", 61}, {"fr30", 62}, {"fr31", 63},	\   {"v0",   77}, {"v1",   78}, {"v2",   79}, {"v3",   80},       \   {"v4",   81}, {"v5",   82}, {"v6",   83}, {"v7",   84},       \   {"v8",   85}, {"v9",   86}, {"v10",  87}, {"v11",  88},       \   {"v12",  89}, {"v13",  90}, {"v14",  91}, {"v15",  92},       \   {"v16",  93}, {"v17",  94}, {"v18",  95}, {"v19",  96},       \   {"v20",  97}, {"v21",  98}, {"v22",  99}, {"v23",  100},	\   {"v24",  101},{"v25",  102},{"v26",  103},{"v27",  104},      \   {"v28",  105},{"v29",  106},{"v30",  107},{"v31",  108},      \   {"vrsave", 109}, {"vscr", 110},				\   {"spe_acc", 111}, {"spefscr", 112},				\
comment|/* no additional names for: mq, lr, ctr, ap */
value|\   {"cr0",  68}, {"cr1",  69}, {"cr2",  70}, {"cr3",  71},	\   {"cr4",  72}, {"cr5",  73}, {"cr6",  74}, {"cr7",  75},	\   {"cc",   68}, {"sp",    1}, {"toc",   2} }
end_define

begin_comment
comment|/* Text to write out after a CALL that may be replaced by glue code by    the loader.  This depends on the AIX version.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_CALL_GLUE
value|"cror 31,31,31"
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
value|do { char buf[100];					\        fputs ("\t.long ", FILE);			\        ASM_GENERATE_INTERNAL_LABEL (buf, "L", VALUE);	\        assemble_name (FILE, buf);			\        putc ('-', FILE);				\        ASM_GENERATE_INTERNAL_LABEL (buf, "L", REL);	\        assemble_name (FILE, buf);			\        putc ('\n', FILE);				\      } while (0)
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
value|if ((LOG) != 0)			\     fprintf (FILE, "\t.align %d\n", (LOG))
end_define

begin_comment
comment|/* Pick up the return address upon entry to a procedure. Used for    dwarf2 unwind information.  This also enables the table driven    mechanism.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
value|gen_rtx_REG (Pmode, LINK_REGISTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|DWARF_FRAME_REGNUM (LINK_REGISTER_REGNUM)
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
value|((N)< 4 ? (N) + 3 : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|EH_RETURN_STACKADJ_RTX
value|gen_rtx_REG (Pmode, 10)
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
comment|/* Define which CODE values are valid.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '.' || (CODE) == '&')
end_define

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
value|print_operand_address (FILE, ADDR)
end_define

begin_comment
comment|/* Define the codes that are matched by predicates in rs6000.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"any_operand", {CONST_INT, CONST_DOUBLE, CONST, SYMBOL_REF,		   \ 		   LABEL_REF, SUBREG, REG, MEM, PARALLEL}},		   \   {"zero_constant", {CONST_INT, CONST_DOUBLE, CONST, SYMBOL_REF,	   \ 		    LABEL_REF, SUBREG, REG, MEM}},			   \   {"short_cint_operand", {CONST_INT}},					   \   {"u_short_cint_operand", {CONST_INT}},				   \   {"non_short_cint_operand", {CONST_INT}},				   \   {"exact_log2_cint_operand", {CONST_INT}},				   \   {"gpc_reg_operand", {SUBREG, REG}},					   \   {"cc_reg_operand", {SUBREG, REG}},					   \   {"cc_reg_not_cr0_operand", {SUBREG, REG}},				   \   {"reg_or_short_operand", {SUBREG, REG, CONST_INT}},			   \   {"reg_or_neg_short_operand", {SUBREG, REG, CONST_INT}},		   \   {"reg_or_aligned_short_operand", {SUBREG, REG, CONST_INT}},		   \   {"reg_or_u_short_operand", {SUBREG, REG, CONST_INT}},			   \   {"reg_or_cint_operand", {SUBREG, REG, CONST_INT}},			   \   {"reg_or_arith_cint_operand", {SUBREG, REG, CONST_INT}},		   \   {"reg_or_add_cint64_operand", {SUBREG, REG, CONST_INT}},		   \   {"reg_or_sub_cint64_operand", {SUBREG, REG, CONST_INT}},		   \   {"reg_or_logical_cint_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}}, \   {"got_operand", {SYMBOL_REF, CONST, LABEL_REF}},			   \   {"got_no_const_operand", {SYMBOL_REF, LABEL_REF}},			   \   {"easy_fp_constant", {CONST_DOUBLE}},					   \   {"easy_vector_constant", {CONST_VECTOR}},				   \   {"easy_vector_constant_add_self", {CONST_VECTOR}},			   \   {"zero_fp_constant", {CONST_DOUBLE}},					   \   {"reg_or_mem_operand", {SUBREG, MEM, REG}},				   \   {"lwa_operand", {SUBREG, MEM, REG}},					   \   {"volatile_mem_operand", {MEM}},					   \   {"offsettable_mem_operand", {MEM}},					   \   {"invalid_gpr_mem", {MEM}},						   \   {"base_reg_operand", {REG}},						   \   {"mem_or_easy_const_operand", {SUBREG, MEM, CONST_DOUBLE}},		   \   {"add_operand", {SUBREG, REG, CONST_INT}},				   \   {"non_add_cint_operand", {CONST_INT}},				   \   {"and_operand", {SUBREG, REG, CONST_INT}},				   \   {"and64_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}},		   \   {"and64_2_operand", {SUBREG, REG, CONST_INT}},			   \   {"logical_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}},		   \   {"non_logical_cint_operand", {CONST_INT, CONST_DOUBLE}},		   \   {"mask_operand", {CONST_INT}},					   \   {"mask_operand_wrap", {CONST_INT}},					   \   {"mask64_operand", {CONST_INT}},					   \   {"mask64_2_operand", {CONST_INT}},					   \   {"count_register_operand", {REG}},					   \   {"xer_operand", {REG}},						   \   {"symbol_ref_operand", {SYMBOL_REF}},					   \   {"rs6000_tls_symbol_ref", {SYMBOL_REF}},				   \   {"call_operand", {SYMBOL_REF, REG}},					   \   {"current_file_function_operand", {SYMBOL_REF}},			   \   {"input_operand", {SUBREG, MEM, REG, CONST_INT,			   \ 		     CONST_DOUBLE, SYMBOL_REF}},			   \   {"load_multiple_operation", {PARALLEL}},				   \   {"store_multiple_operation", {PARALLEL}},				   \   {"vrsave_operation", {PARALLEL}},					   \   {"branch_comparison_operator", {EQ, NE, LE, LT, GE,			   \ 				  GT, LEU, LTU, GEU, GTU,		   \ 				  UNORDERED, ORDERED,			   \ 				  UNGE, UNLE }},			   \   {"branch_positive_comparison_operator", {EQ, LT, GT, LTU, GTU,	   \ 					   UNORDERED }},		   \   {"scc_comparison_operator", {EQ, NE, LE, LT, GE,			   \ 			       GT, LEU, LTU, GEU, GTU,			   \ 			       UNORDERED, ORDERED,			   \ 			       UNGE, UNLE }},				   \   {"trap_comparison_operator", {EQ, NE, LE, LT, GE,			   \ 				GT, LEU, LTU, GEU, GTU}},		   \   {"boolean_operator", {AND, IOR, XOR}},				   \   {"boolean_or_operator", {IOR, XOR}},					   \   {"altivec_register_operand", {REG}},	                                   \   {"min_max_operator", {SMIN, SMAX, UMIN, UMAX}},
end_define

begin_comment
comment|/* uncomment for disabling the corresponding default options */
end_comment

begin_comment
comment|/* #define  MACHINE_no_sched_interblock */
end_comment

begin_comment
comment|/* #define  MACHINE_no_sched_speculative */
end_comment

begin_comment
comment|/* #define  MACHINE_no_sched_speculative_load */
end_comment

begin_comment
comment|/* General flags.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pic
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
name|int
name|flag_expensive_optimizations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frame_pointer_needed
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|rs6000_builtins
block|{
comment|/* AltiVec builtins.  */
name|ALTIVEC_BUILTIN_ST_INTERNAL_4si
block|,
name|ALTIVEC_BUILTIN_LD_INTERNAL_4si
block|,
name|ALTIVEC_BUILTIN_ST_INTERNAL_8hi
block|,
name|ALTIVEC_BUILTIN_LD_INTERNAL_8hi
block|,
name|ALTIVEC_BUILTIN_ST_INTERNAL_16qi
block|,
name|ALTIVEC_BUILTIN_LD_INTERNAL_16qi
block|,
name|ALTIVEC_BUILTIN_ST_INTERNAL_4sf
block|,
name|ALTIVEC_BUILTIN_LD_INTERNAL_4sf
block|,
name|ALTIVEC_BUILTIN_VADDUBM
block|,
name|ALTIVEC_BUILTIN_VADDUHM
block|,
name|ALTIVEC_BUILTIN_VADDUWM
block|,
name|ALTIVEC_BUILTIN_VADDFP
block|,
name|ALTIVEC_BUILTIN_VADDCUW
block|,
name|ALTIVEC_BUILTIN_VADDUBS
block|,
name|ALTIVEC_BUILTIN_VADDSBS
block|,
name|ALTIVEC_BUILTIN_VADDUHS
block|,
name|ALTIVEC_BUILTIN_VADDSHS
block|,
name|ALTIVEC_BUILTIN_VADDUWS
block|,
name|ALTIVEC_BUILTIN_VADDSWS
block|,
name|ALTIVEC_BUILTIN_VAND
block|,
name|ALTIVEC_BUILTIN_VANDC
block|,
name|ALTIVEC_BUILTIN_VAVGUB
block|,
name|ALTIVEC_BUILTIN_VAVGSB
block|,
name|ALTIVEC_BUILTIN_VAVGUH
block|,
name|ALTIVEC_BUILTIN_VAVGSH
block|,
name|ALTIVEC_BUILTIN_VAVGUW
block|,
name|ALTIVEC_BUILTIN_VAVGSW
block|,
name|ALTIVEC_BUILTIN_VCFUX
block|,
name|ALTIVEC_BUILTIN_VCFSX
block|,
name|ALTIVEC_BUILTIN_VCTSXS
block|,
name|ALTIVEC_BUILTIN_VCTUXS
block|,
name|ALTIVEC_BUILTIN_VCMPBFP
block|,
name|ALTIVEC_BUILTIN_VCMPEQUB
block|,
name|ALTIVEC_BUILTIN_VCMPEQUH
block|,
name|ALTIVEC_BUILTIN_VCMPEQUW
block|,
name|ALTIVEC_BUILTIN_VCMPEQFP
block|,
name|ALTIVEC_BUILTIN_VCMPGEFP
block|,
name|ALTIVEC_BUILTIN_VCMPGTUB
block|,
name|ALTIVEC_BUILTIN_VCMPGTSB
block|,
name|ALTIVEC_BUILTIN_VCMPGTUH
block|,
name|ALTIVEC_BUILTIN_VCMPGTSH
block|,
name|ALTIVEC_BUILTIN_VCMPGTUW
block|,
name|ALTIVEC_BUILTIN_VCMPGTSW
block|,
name|ALTIVEC_BUILTIN_VCMPGTFP
block|,
name|ALTIVEC_BUILTIN_VEXPTEFP
block|,
name|ALTIVEC_BUILTIN_VLOGEFP
block|,
name|ALTIVEC_BUILTIN_VMADDFP
block|,
name|ALTIVEC_BUILTIN_VMAXUB
block|,
name|ALTIVEC_BUILTIN_VMAXSB
block|,
name|ALTIVEC_BUILTIN_VMAXUH
block|,
name|ALTIVEC_BUILTIN_VMAXSH
block|,
name|ALTIVEC_BUILTIN_VMAXUW
block|,
name|ALTIVEC_BUILTIN_VMAXSW
block|,
name|ALTIVEC_BUILTIN_VMAXFP
block|,
name|ALTIVEC_BUILTIN_VMHADDSHS
block|,
name|ALTIVEC_BUILTIN_VMHRADDSHS
block|,
name|ALTIVEC_BUILTIN_VMLADDUHM
block|,
name|ALTIVEC_BUILTIN_VMRGHB
block|,
name|ALTIVEC_BUILTIN_VMRGHH
block|,
name|ALTIVEC_BUILTIN_VMRGHW
block|,
name|ALTIVEC_BUILTIN_VMRGLB
block|,
name|ALTIVEC_BUILTIN_VMRGLH
block|,
name|ALTIVEC_BUILTIN_VMRGLW
block|,
name|ALTIVEC_BUILTIN_VMSUMUBM
block|,
name|ALTIVEC_BUILTIN_VMSUMMBM
block|,
name|ALTIVEC_BUILTIN_VMSUMUHM
block|,
name|ALTIVEC_BUILTIN_VMSUMSHM
block|,
name|ALTIVEC_BUILTIN_VMSUMUHS
block|,
name|ALTIVEC_BUILTIN_VMSUMSHS
block|,
name|ALTIVEC_BUILTIN_VMINUB
block|,
name|ALTIVEC_BUILTIN_VMINSB
block|,
name|ALTIVEC_BUILTIN_VMINUH
block|,
name|ALTIVEC_BUILTIN_VMINSH
block|,
name|ALTIVEC_BUILTIN_VMINUW
block|,
name|ALTIVEC_BUILTIN_VMINSW
block|,
name|ALTIVEC_BUILTIN_VMINFP
block|,
name|ALTIVEC_BUILTIN_VMULEUB
block|,
name|ALTIVEC_BUILTIN_VMULESB
block|,
name|ALTIVEC_BUILTIN_VMULEUH
block|,
name|ALTIVEC_BUILTIN_VMULESH
block|,
name|ALTIVEC_BUILTIN_VMULOUB
block|,
name|ALTIVEC_BUILTIN_VMULOSB
block|,
name|ALTIVEC_BUILTIN_VMULOUH
block|,
name|ALTIVEC_BUILTIN_VMULOSH
block|,
name|ALTIVEC_BUILTIN_VNMSUBFP
block|,
name|ALTIVEC_BUILTIN_VNOR
block|,
name|ALTIVEC_BUILTIN_VOR
block|,
name|ALTIVEC_BUILTIN_VSEL_4SI
block|,
name|ALTIVEC_BUILTIN_VSEL_4SF
block|,
name|ALTIVEC_BUILTIN_VSEL_8HI
block|,
name|ALTIVEC_BUILTIN_VSEL_16QI
block|,
name|ALTIVEC_BUILTIN_VPERM_4SI
block|,
name|ALTIVEC_BUILTIN_VPERM_4SF
block|,
name|ALTIVEC_BUILTIN_VPERM_8HI
block|,
name|ALTIVEC_BUILTIN_VPERM_16QI
block|,
name|ALTIVEC_BUILTIN_VPKUHUM
block|,
name|ALTIVEC_BUILTIN_VPKUWUM
block|,
name|ALTIVEC_BUILTIN_VPKPX
block|,
name|ALTIVEC_BUILTIN_VPKUHSS
block|,
name|ALTIVEC_BUILTIN_VPKSHSS
block|,
name|ALTIVEC_BUILTIN_VPKUWSS
block|,
name|ALTIVEC_BUILTIN_VPKSWSS
block|,
name|ALTIVEC_BUILTIN_VPKUHUS
block|,
name|ALTIVEC_BUILTIN_VPKSHUS
block|,
name|ALTIVEC_BUILTIN_VPKUWUS
block|,
name|ALTIVEC_BUILTIN_VPKSWUS
block|,
name|ALTIVEC_BUILTIN_VREFP
block|,
name|ALTIVEC_BUILTIN_VRFIM
block|,
name|ALTIVEC_BUILTIN_VRFIN
block|,
name|ALTIVEC_BUILTIN_VRFIP
block|,
name|ALTIVEC_BUILTIN_VRFIZ
block|,
name|ALTIVEC_BUILTIN_VRLB
block|,
name|ALTIVEC_BUILTIN_VRLH
block|,
name|ALTIVEC_BUILTIN_VRLW
block|,
name|ALTIVEC_BUILTIN_VRSQRTEFP
block|,
name|ALTIVEC_BUILTIN_VSLB
block|,
name|ALTIVEC_BUILTIN_VSLH
block|,
name|ALTIVEC_BUILTIN_VSLW
block|,
name|ALTIVEC_BUILTIN_VSL
block|,
name|ALTIVEC_BUILTIN_VSLO
block|,
name|ALTIVEC_BUILTIN_VSPLTB
block|,
name|ALTIVEC_BUILTIN_VSPLTH
block|,
name|ALTIVEC_BUILTIN_VSPLTW
block|,
name|ALTIVEC_BUILTIN_VSPLTISB
block|,
name|ALTIVEC_BUILTIN_VSPLTISH
block|,
name|ALTIVEC_BUILTIN_VSPLTISW
block|,
name|ALTIVEC_BUILTIN_VSRB
block|,
name|ALTIVEC_BUILTIN_VSRH
block|,
name|ALTIVEC_BUILTIN_VSRW
block|,
name|ALTIVEC_BUILTIN_VSRAB
block|,
name|ALTIVEC_BUILTIN_VSRAH
block|,
name|ALTIVEC_BUILTIN_VSRAW
block|,
name|ALTIVEC_BUILTIN_VSR
block|,
name|ALTIVEC_BUILTIN_VSRO
block|,
name|ALTIVEC_BUILTIN_VSUBUBM
block|,
name|ALTIVEC_BUILTIN_VSUBUHM
block|,
name|ALTIVEC_BUILTIN_VSUBUWM
block|,
name|ALTIVEC_BUILTIN_VSUBFP
block|,
name|ALTIVEC_BUILTIN_VSUBCUW
block|,
name|ALTIVEC_BUILTIN_VSUBUBS
block|,
name|ALTIVEC_BUILTIN_VSUBSBS
block|,
name|ALTIVEC_BUILTIN_VSUBUHS
block|,
name|ALTIVEC_BUILTIN_VSUBSHS
block|,
name|ALTIVEC_BUILTIN_VSUBUWS
block|,
name|ALTIVEC_BUILTIN_VSUBSWS
block|,
name|ALTIVEC_BUILTIN_VSUM4UBS
block|,
name|ALTIVEC_BUILTIN_VSUM4SBS
block|,
name|ALTIVEC_BUILTIN_VSUM4SHS
block|,
name|ALTIVEC_BUILTIN_VSUM2SWS
block|,
name|ALTIVEC_BUILTIN_VSUMSWS
block|,
name|ALTIVEC_BUILTIN_VXOR
block|,
name|ALTIVEC_BUILTIN_VSLDOI_16QI
block|,
name|ALTIVEC_BUILTIN_VSLDOI_8HI
block|,
name|ALTIVEC_BUILTIN_VSLDOI_4SI
block|,
name|ALTIVEC_BUILTIN_VSLDOI_4SF
block|,
name|ALTIVEC_BUILTIN_VUPKHSB
block|,
name|ALTIVEC_BUILTIN_VUPKHPX
block|,
name|ALTIVEC_BUILTIN_VUPKHSH
block|,
name|ALTIVEC_BUILTIN_VUPKLSB
block|,
name|ALTIVEC_BUILTIN_VUPKLPX
block|,
name|ALTIVEC_BUILTIN_VUPKLSH
block|,
name|ALTIVEC_BUILTIN_MTVSCR
block|,
name|ALTIVEC_BUILTIN_MFVSCR
block|,
name|ALTIVEC_BUILTIN_DSSALL
block|,
name|ALTIVEC_BUILTIN_DSS
block|,
name|ALTIVEC_BUILTIN_LVSL
block|,
name|ALTIVEC_BUILTIN_LVSR
block|,
name|ALTIVEC_BUILTIN_DSTT
block|,
name|ALTIVEC_BUILTIN_DSTST
block|,
name|ALTIVEC_BUILTIN_DSTSTT
block|,
name|ALTIVEC_BUILTIN_DST
block|,
name|ALTIVEC_BUILTIN_LVEBX
block|,
name|ALTIVEC_BUILTIN_LVEHX
block|,
name|ALTIVEC_BUILTIN_LVEWX
block|,
name|ALTIVEC_BUILTIN_LVXL
block|,
name|ALTIVEC_BUILTIN_LVX
block|,
name|ALTIVEC_BUILTIN_STVX
block|,
name|ALTIVEC_BUILTIN_STVEBX
block|,
name|ALTIVEC_BUILTIN_STVEHX
block|,
name|ALTIVEC_BUILTIN_STVEWX
block|,
name|ALTIVEC_BUILTIN_STVXL
block|,
name|ALTIVEC_BUILTIN_VCMPBFP_P
block|,
name|ALTIVEC_BUILTIN_VCMPEQFP_P
block|,
name|ALTIVEC_BUILTIN_VCMPEQUB_P
block|,
name|ALTIVEC_BUILTIN_VCMPEQUH_P
block|,
name|ALTIVEC_BUILTIN_VCMPEQUW_P
block|,
name|ALTIVEC_BUILTIN_VCMPGEFP_P
block|,
name|ALTIVEC_BUILTIN_VCMPGTFP_P
block|,
name|ALTIVEC_BUILTIN_VCMPGTSB_P
block|,
name|ALTIVEC_BUILTIN_VCMPGTSH_P
block|,
name|ALTIVEC_BUILTIN_VCMPGTSW_P
block|,
name|ALTIVEC_BUILTIN_VCMPGTUB_P
block|,
name|ALTIVEC_BUILTIN_VCMPGTUH_P
block|,
name|ALTIVEC_BUILTIN_VCMPGTUW_P
block|,
name|ALTIVEC_BUILTIN_ABSS_V4SI
block|,
name|ALTIVEC_BUILTIN_ABSS_V8HI
block|,
name|ALTIVEC_BUILTIN_ABSS_V16QI
block|,
name|ALTIVEC_BUILTIN_ABS_V4SI
block|,
name|ALTIVEC_BUILTIN_ABS_V4SF
block|,
name|ALTIVEC_BUILTIN_ABS_V8HI
block|,
name|ALTIVEC_BUILTIN_ABS_V16QI
block|,
name|ALTIVEC_BUILTIN_COMPILETIME_ERROR
block|,
comment|/* SPE builtins.  */
name|SPE_BUILTIN_EVADDW
block|,
name|SPE_BUILTIN_EVAND
block|,
name|SPE_BUILTIN_EVANDC
block|,
name|SPE_BUILTIN_EVDIVWS
block|,
name|SPE_BUILTIN_EVDIVWU
block|,
name|SPE_BUILTIN_EVEQV
block|,
name|SPE_BUILTIN_EVFSADD
block|,
name|SPE_BUILTIN_EVFSDIV
block|,
name|SPE_BUILTIN_EVFSMUL
block|,
name|SPE_BUILTIN_EVFSSUB
block|,
name|SPE_BUILTIN_EVLDDX
block|,
name|SPE_BUILTIN_EVLDHX
block|,
name|SPE_BUILTIN_EVLDWX
block|,
name|SPE_BUILTIN_EVLHHESPLATX
block|,
name|SPE_BUILTIN_EVLHHOSSPLATX
block|,
name|SPE_BUILTIN_EVLHHOUSPLATX
block|,
name|SPE_BUILTIN_EVLWHEX
block|,
name|SPE_BUILTIN_EVLWHOSX
block|,
name|SPE_BUILTIN_EVLWHOUX
block|,
name|SPE_BUILTIN_EVLWHSPLATX
block|,
name|SPE_BUILTIN_EVLWWSPLATX
block|,
name|SPE_BUILTIN_EVMERGEHI
block|,
name|SPE_BUILTIN_EVMERGEHILO
block|,
name|SPE_BUILTIN_EVMERGELO
block|,
name|SPE_BUILTIN_EVMERGELOHI
block|,
name|SPE_BUILTIN_EVMHEGSMFAA
block|,
name|SPE_BUILTIN_EVMHEGSMFAN
block|,
name|SPE_BUILTIN_EVMHEGSMIAA
block|,
name|SPE_BUILTIN_EVMHEGSMIAN
block|,
name|SPE_BUILTIN_EVMHEGUMIAA
block|,
name|SPE_BUILTIN_EVMHEGUMIAN
block|,
name|SPE_BUILTIN_EVMHESMF
block|,
name|SPE_BUILTIN_EVMHESMFA
block|,
name|SPE_BUILTIN_EVMHESMFAAW
block|,
name|SPE_BUILTIN_EVMHESMFANW
block|,
name|SPE_BUILTIN_EVMHESMI
block|,
name|SPE_BUILTIN_EVMHESMIA
block|,
name|SPE_BUILTIN_EVMHESMIAAW
block|,
name|SPE_BUILTIN_EVMHESMIANW
block|,
name|SPE_BUILTIN_EVMHESSF
block|,
name|SPE_BUILTIN_EVMHESSFA
block|,
name|SPE_BUILTIN_EVMHESSFAAW
block|,
name|SPE_BUILTIN_EVMHESSFANW
block|,
name|SPE_BUILTIN_EVMHESSIAAW
block|,
name|SPE_BUILTIN_EVMHESSIANW
block|,
name|SPE_BUILTIN_EVMHEUMI
block|,
name|SPE_BUILTIN_EVMHEUMIA
block|,
name|SPE_BUILTIN_EVMHEUMIAAW
block|,
name|SPE_BUILTIN_EVMHEUMIANW
block|,
name|SPE_BUILTIN_EVMHEUSIAAW
block|,
name|SPE_BUILTIN_EVMHEUSIANW
block|,
name|SPE_BUILTIN_EVMHOGSMFAA
block|,
name|SPE_BUILTIN_EVMHOGSMFAN
block|,
name|SPE_BUILTIN_EVMHOGSMIAA
block|,
name|SPE_BUILTIN_EVMHOGSMIAN
block|,
name|SPE_BUILTIN_EVMHOGUMIAA
block|,
name|SPE_BUILTIN_EVMHOGUMIAN
block|,
name|SPE_BUILTIN_EVMHOSMF
block|,
name|SPE_BUILTIN_EVMHOSMFA
block|,
name|SPE_BUILTIN_EVMHOSMFAAW
block|,
name|SPE_BUILTIN_EVMHOSMFANW
block|,
name|SPE_BUILTIN_EVMHOSMI
block|,
name|SPE_BUILTIN_EVMHOSMIA
block|,
name|SPE_BUILTIN_EVMHOSMIAAW
block|,
name|SPE_BUILTIN_EVMHOSMIANW
block|,
name|SPE_BUILTIN_EVMHOSSF
block|,
name|SPE_BUILTIN_EVMHOSSFA
block|,
name|SPE_BUILTIN_EVMHOSSFAAW
block|,
name|SPE_BUILTIN_EVMHOSSFANW
block|,
name|SPE_BUILTIN_EVMHOSSIAAW
block|,
name|SPE_BUILTIN_EVMHOSSIANW
block|,
name|SPE_BUILTIN_EVMHOUMI
block|,
name|SPE_BUILTIN_EVMHOUMIA
block|,
name|SPE_BUILTIN_EVMHOUMIAAW
block|,
name|SPE_BUILTIN_EVMHOUMIANW
block|,
name|SPE_BUILTIN_EVMHOUSIAAW
block|,
name|SPE_BUILTIN_EVMHOUSIANW
block|,
name|SPE_BUILTIN_EVMWHSMF
block|,
name|SPE_BUILTIN_EVMWHSMFA
block|,
name|SPE_BUILTIN_EVMWHSMI
block|,
name|SPE_BUILTIN_EVMWHSMIA
block|,
name|SPE_BUILTIN_EVMWHSSF
block|,
name|SPE_BUILTIN_EVMWHSSFA
block|,
name|SPE_BUILTIN_EVMWHUMI
block|,
name|SPE_BUILTIN_EVMWHUMIA
block|,
name|SPE_BUILTIN_EVMWLSMIAAW
block|,
name|SPE_BUILTIN_EVMWLSMIANW
block|,
name|SPE_BUILTIN_EVMWLSSIAAW
block|,
name|SPE_BUILTIN_EVMWLSSIANW
block|,
name|SPE_BUILTIN_EVMWLUMI
block|,
name|SPE_BUILTIN_EVMWLUMIA
block|,
name|SPE_BUILTIN_EVMWLUMIAAW
block|,
name|SPE_BUILTIN_EVMWLUMIANW
block|,
name|SPE_BUILTIN_EVMWLUSIAAW
block|,
name|SPE_BUILTIN_EVMWLUSIANW
block|,
name|SPE_BUILTIN_EVMWSMF
block|,
name|SPE_BUILTIN_EVMWSMFA
block|,
name|SPE_BUILTIN_EVMWSMFAA
block|,
name|SPE_BUILTIN_EVMWSMFAN
block|,
name|SPE_BUILTIN_EVMWSMI
block|,
name|SPE_BUILTIN_EVMWSMIA
block|,
name|SPE_BUILTIN_EVMWSMIAA
block|,
name|SPE_BUILTIN_EVMWSMIAN
block|,
name|SPE_BUILTIN_EVMWHSSFAA
block|,
name|SPE_BUILTIN_EVMWSSF
block|,
name|SPE_BUILTIN_EVMWSSFA
block|,
name|SPE_BUILTIN_EVMWSSFAA
block|,
name|SPE_BUILTIN_EVMWSSFAN
block|,
name|SPE_BUILTIN_EVMWUMI
block|,
name|SPE_BUILTIN_EVMWUMIA
block|,
name|SPE_BUILTIN_EVMWUMIAA
block|,
name|SPE_BUILTIN_EVMWUMIAN
block|,
name|SPE_BUILTIN_EVNAND
block|,
name|SPE_BUILTIN_EVNOR
block|,
name|SPE_BUILTIN_EVOR
block|,
name|SPE_BUILTIN_EVORC
block|,
name|SPE_BUILTIN_EVRLW
block|,
name|SPE_BUILTIN_EVSLW
block|,
name|SPE_BUILTIN_EVSRWS
block|,
name|SPE_BUILTIN_EVSRWU
block|,
name|SPE_BUILTIN_EVSTDDX
block|,
name|SPE_BUILTIN_EVSTDHX
block|,
name|SPE_BUILTIN_EVSTDWX
block|,
name|SPE_BUILTIN_EVSTWHEX
block|,
name|SPE_BUILTIN_EVSTWHOX
block|,
name|SPE_BUILTIN_EVSTWWEX
block|,
name|SPE_BUILTIN_EVSTWWOX
block|,
name|SPE_BUILTIN_EVSUBFW
block|,
name|SPE_BUILTIN_EVXOR
block|,
name|SPE_BUILTIN_EVABS
block|,
name|SPE_BUILTIN_EVADDSMIAAW
block|,
name|SPE_BUILTIN_EVADDSSIAAW
block|,
name|SPE_BUILTIN_EVADDUMIAAW
block|,
name|SPE_BUILTIN_EVADDUSIAAW
block|,
name|SPE_BUILTIN_EVCNTLSW
block|,
name|SPE_BUILTIN_EVCNTLZW
block|,
name|SPE_BUILTIN_EVEXTSB
block|,
name|SPE_BUILTIN_EVEXTSH
block|,
name|SPE_BUILTIN_EVFSABS
block|,
name|SPE_BUILTIN_EVFSCFSF
block|,
name|SPE_BUILTIN_EVFSCFSI
block|,
name|SPE_BUILTIN_EVFSCFUF
block|,
name|SPE_BUILTIN_EVFSCFUI
block|,
name|SPE_BUILTIN_EVFSCTSF
block|,
name|SPE_BUILTIN_EVFSCTSI
block|,
name|SPE_BUILTIN_EVFSCTSIZ
block|,
name|SPE_BUILTIN_EVFSCTUF
block|,
name|SPE_BUILTIN_EVFSCTUI
block|,
name|SPE_BUILTIN_EVFSCTUIZ
block|,
name|SPE_BUILTIN_EVFSNABS
block|,
name|SPE_BUILTIN_EVFSNEG
block|,
name|SPE_BUILTIN_EVMRA
block|,
name|SPE_BUILTIN_EVNEG
block|,
name|SPE_BUILTIN_EVRNDW
block|,
name|SPE_BUILTIN_EVSUBFSMIAAW
block|,
name|SPE_BUILTIN_EVSUBFSSIAAW
block|,
name|SPE_BUILTIN_EVSUBFUMIAAW
block|,
name|SPE_BUILTIN_EVSUBFUSIAAW
block|,
name|SPE_BUILTIN_EVADDIW
block|,
name|SPE_BUILTIN_EVLDD
block|,
name|SPE_BUILTIN_EVLDH
block|,
name|SPE_BUILTIN_EVLDW
block|,
name|SPE_BUILTIN_EVLHHESPLAT
block|,
name|SPE_BUILTIN_EVLHHOSSPLAT
block|,
name|SPE_BUILTIN_EVLHHOUSPLAT
block|,
name|SPE_BUILTIN_EVLWHE
block|,
name|SPE_BUILTIN_EVLWHOS
block|,
name|SPE_BUILTIN_EVLWHOU
block|,
name|SPE_BUILTIN_EVLWHSPLAT
block|,
name|SPE_BUILTIN_EVLWWSPLAT
block|,
name|SPE_BUILTIN_EVRLWI
block|,
name|SPE_BUILTIN_EVSLWI
block|,
name|SPE_BUILTIN_EVSRWIS
block|,
name|SPE_BUILTIN_EVSRWIU
block|,
name|SPE_BUILTIN_EVSTDD
block|,
name|SPE_BUILTIN_EVSTDH
block|,
name|SPE_BUILTIN_EVSTDW
block|,
name|SPE_BUILTIN_EVSTWHE
block|,
name|SPE_BUILTIN_EVSTWHO
block|,
name|SPE_BUILTIN_EVSTWWE
block|,
name|SPE_BUILTIN_EVSTWWO
block|,
name|SPE_BUILTIN_EVSUBIFW
block|,
comment|/* Compares.  */
name|SPE_BUILTIN_EVCMPEQ
block|,
name|SPE_BUILTIN_EVCMPGTS
block|,
name|SPE_BUILTIN_EVCMPGTU
block|,
name|SPE_BUILTIN_EVCMPLTS
block|,
name|SPE_BUILTIN_EVCMPLTU
block|,
name|SPE_BUILTIN_EVFSCMPEQ
block|,
name|SPE_BUILTIN_EVFSCMPGT
block|,
name|SPE_BUILTIN_EVFSCMPLT
block|,
name|SPE_BUILTIN_EVFSTSTEQ
block|,
name|SPE_BUILTIN_EVFSTSTGT
block|,
name|SPE_BUILTIN_EVFSTSTLT
block|,
comment|/* EVSEL compares.  */
name|SPE_BUILTIN_EVSEL_CMPEQ
block|,
name|SPE_BUILTIN_EVSEL_CMPGTS
block|,
name|SPE_BUILTIN_EVSEL_CMPGTU
block|,
name|SPE_BUILTIN_EVSEL_CMPLTS
block|,
name|SPE_BUILTIN_EVSEL_CMPLTU
block|,
name|SPE_BUILTIN_EVSEL_FSCMPEQ
block|,
name|SPE_BUILTIN_EVSEL_FSCMPGT
block|,
name|SPE_BUILTIN_EVSEL_FSCMPLT
block|,
name|SPE_BUILTIN_EVSEL_FSTSTEQ
block|,
name|SPE_BUILTIN_EVSEL_FSTSTGT
block|,
name|SPE_BUILTIN_EVSEL_FSTSTLT
block|,
name|SPE_BUILTIN_EVSPLATFI
block|,
name|SPE_BUILTIN_EVSPLATI
block|,
name|SPE_BUILTIN_EVMWHSSMAA
block|,
name|SPE_BUILTIN_EVMWHSMFAA
block|,
name|SPE_BUILTIN_EVMWHSMIAA
block|,
name|SPE_BUILTIN_EVMWHUSIAA
block|,
name|SPE_BUILTIN_EVMWHUMIAA
block|,
name|SPE_BUILTIN_EVMWHSSFAN
block|,
name|SPE_BUILTIN_EVMWHSSIAN
block|,
name|SPE_BUILTIN_EVMWHSMFAN
block|,
name|SPE_BUILTIN_EVMWHSMIAN
block|,
name|SPE_BUILTIN_EVMWHUSIAN
block|,
name|SPE_BUILTIN_EVMWHUMIAN
block|,
name|SPE_BUILTIN_EVMWHGSSFAA
block|,
name|SPE_BUILTIN_EVMWHGSMFAA
block|,
name|SPE_BUILTIN_EVMWHGSMIAA
block|,
name|SPE_BUILTIN_EVMWHGUMIAA
block|,
name|SPE_BUILTIN_EVMWHGSSFAN
block|,
name|SPE_BUILTIN_EVMWHGSMFAN
block|,
name|SPE_BUILTIN_EVMWHGSMIAN
block|,
name|SPE_BUILTIN_EVMWHGUMIAN
block|,
name|SPE_BUILTIN_MTSPEFSCR
block|,
name|SPE_BUILTIN_MFSPEFSCR
block|,
name|SPE_BUILTIN_BRINC
block|}
enum|;
end_enum

end_unit

