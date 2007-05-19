begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for ARM.    Copyright (C) 1991, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by Pieter `Tiggr' Schoenmakers (rcpieter@win.tue.nl)    and Martin Simmons (@harleqn.co.uk).    More major hacks by Richard Earnshaw (rearnsha@arm.com)    Minor hacks by Nick Clifton (nickc@cygnus.com)     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
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

begin_comment
comment|/* The architecture define.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|arm_arch_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Target CPU builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do							\     {							\
comment|/* Define __arm__ even when in thumb mode, for	\ 	   consistency with armcc.  */
value|\ 	builtin_define ("__arm__");			\ 	builtin_define ("__APCS_32__");			\ 	if (TARGET_THUMB)				\ 	  builtin_define ("__thumb__");			\ 							\ 	if (TARGET_BIG_END)				\ 	  {						\ 	    builtin_define ("__ARMEB__");		\ 	    if (TARGET_THUMB)				\ 	      builtin_define ("__THUMBEB__");		\ 	    if (TARGET_LITTLE_WORDS)			\ 	      builtin_define ("__ARMWEL__");		\ 	  }						\         else						\ 	  {						\ 	    builtin_define ("__ARMEL__");		\ 	    if (TARGET_THUMB)				\ 	      builtin_define ("__THUMBEL__");		\ 	  }						\ 							\ 	if (TARGET_SOFT_FLOAT)				\ 	  builtin_define ("__SOFTFP__");		\ 							\ 	if (TARGET_VFP)					\ 	  builtin_define ("__VFP_FP__");		\ 							\
comment|/* Add a define for interworking.		\ 	   Needed when building libgcc.a.  */
value|\ 	if (arm_cpp_interwork)				\ 	  builtin_define ("__THUMB_INTERWORK__");	\ 							\ 	builtin_assert ("cpu=arm");			\ 	builtin_assert ("machine=arm");			\ 							\ 	builtin_define (arm_arch_name);			\ 	if (arm_arch_cirrus)				\ 	  builtin_define ("__MAVERICK__");		\ 	if (arm_arch_xscale)				\ 	  builtin_define ("__XSCALE__");		\ 	if (arm_arch_iwmmxt)				\ 	  builtin_define ("__IWMMXT__");		\ 	if (TARGET_AAPCS_BASED)				\ 	  builtin_define ("__ARM_EABI__");		\     } while (0)
end_define

begin_comment
comment|/* The various ARM cores.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
define|#
directive|define
name|ARM_CORE
parameter_list|(
name|NAME
parameter_list|,
name|IDENT
parameter_list|,
name|ARCH
parameter_list|,
name|FLAGS
parameter_list|,
name|COSTS
parameter_list|)
define|\
value|IDENT,
include|#
directive|include
file|"arm-cores.def"
undef|#
directive|undef
name|ARM_CORE
comment|/* Used to indicate that no processor has been specified.  */
name|arm_none
block|}
enum|;
end_enum

begin_enum
enum|enum
name|target_cpus
block|{
define|#
directive|define
name|ARM_CORE
parameter_list|(
name|NAME
parameter_list|,
name|IDENT
parameter_list|,
name|ARCH
parameter_list|,
name|FLAGS
parameter_list|,
name|COSTS
parameter_list|)
define|\
value|TARGET_CPU_##IDENT,
include|#
directive|include
file|"arm-cores.def"
undef|#
directive|undef
name|ARM_CORE
name|TARGET_CPU_generic
block|}
enum|;
end_enum

begin_comment
comment|/* The processor for which instructions should be scheduled.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|arm_tune
decl_stmt|;
end_decl_stmt

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

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|arm_target_insn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the information needed to generate branch insns.  This is    stored from the compare operation.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|arm_compare_op0
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|arm_compare_op1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The label of the current constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|pool_vector_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 1 when a return insn is output, this means that the epilogue    is not needed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|return_used_this_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used to produce AOF syntax assembler.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|aof_pic_label
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Just in case configure has failed to define anything.  */
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

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(subtarget_cpp_spec)					\ %{msoft-float:%{mhard-float:						\ 	%e-msoft-float and -mhard_float may not be used together}}	\ %{mbig-endian:%{mlittle-endian:						\ 	%e-mbig-endian and -mlittle-endian may not be used together}}"
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
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GCC driver    program.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "subtarget_cpp_spec",	SUBTARGET_CPP_SPEC },           \   SUBTARGET_EXTRA_SPECS
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/generic)", stderr);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_SOFT_FLOAT
value|(arm_float_abi == ARM_FLOAT_ABI_SOFT)
end_define

begin_comment
comment|/* Use hardware floating point instructions. */
end_comment

begin_define
define|#
directive|define
name|TARGET_HARD_FLOAT
value|(arm_float_abi != ARM_FLOAT_ABI_SOFT)
end_define

begin_comment
comment|/* Use hardware floating point calling convention.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HARD_FLOAT_ABI
value|(arm_float_abi == ARM_FLOAT_ABI_HARD)
end_define

begin_define
define|#
directive|define
name|TARGET_FPA
value|(arm_fp_model == ARM_FP_MODEL_FPA)
end_define

begin_define
define|#
directive|define
name|TARGET_MAVERICK
value|(arm_fp_model == ARM_FP_MODEL_MAVERICK)
end_define

begin_define
define|#
directive|define
name|TARGET_VFP
value|(arm_fp_model == ARM_FP_MODEL_VFP)
end_define

begin_define
define|#
directive|define
name|TARGET_IWMMXT
value|(arm_arch_iwmmxt)
end_define

begin_define
define|#
directive|define
name|TARGET_REALLY_IWMMXT
value|(TARGET_IWMMXT&& TARGET_ARM)
end_define

begin_define
define|#
directive|define
name|TARGET_IWMMXT_ABI
value|(TARGET_ARM&& arm_abi == ARM_ABI_IWMMXT)
end_define

begin_define
define|#
directive|define
name|TARGET_ARM
value|(! TARGET_THUMB)
end_define

begin_define
define|#
directive|define
name|TARGET_EITHER
value|1
end_define

begin_comment
comment|/* (TARGET_ARM | TARGET_THUMB) */
end_comment

begin_define
define|#
directive|define
name|TARGET_BACKTRACE
value|(leaf_function_p () \ 				         ? TARGET_TPCS_LEAF_FRAME \ 				         : TARGET_TPCS_FRAME)
end_define

begin_define
define|#
directive|define
name|TARGET_LDRD
value|(arm_arch5e&& ARM_DOUBLEWORD_ALIGN)
end_define

begin_define
define|#
directive|define
name|TARGET_AAPCS_BASED
define|\
value|(arm_abi != ARM_ABI_APCS&& arm_abi != ARM_ABI_ATPCS)
end_define

begin_define
define|#
directive|define
name|TARGET_HARD_TP
value|(target_thread_pointer == TP_CP15)
end_define

begin_define
define|#
directive|define
name|TARGET_SOFT_TP
value|(target_thread_pointer == TP_SOFT)
end_define

begin_comment
comment|/* True iff the full BPABI is being used.  If TARGET_BPABI is true,    then TARGET_AAPCS_BASED must be true -- but the converse does not    hold.  TARGET_BPABI implies the use of the BPABI runtime library,    etc., in addition to just the AAPCS calling conventions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BPABI
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BPABI
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support for a compile-time default CPU, et cetera.  The rules are:    --with-arch is ignored if -march or -mcpu are specified.    --with-cpu is ignored if -march or -mcpu are specified, and is overridden     by --with-arch.    --with-tune is ignored if -mtune or -mcpu are specified (but not affected      by -march).    --with-float is ignored if -mhard-float, -msoft-float or -mfloat-abi are    specified.    --with-fpu is ignored if -mfpu is specified.    --with-abi is ignored is -mabi is specified.  */
end_comment

begin_define
define|#
directive|define
name|OPTION_DEFAULT_SPECS
define|\
value|{"arch", "%{!march=*:%{!mcpu=*:-march=%(VALUE)}}" }, \   {"cpu", "%{!march=*:%{!mcpu=*:-mcpu=%(VALUE)}}" }, \   {"tune", "%{!mcpu=*:%{!mtune=*:-mtune=%(VALUE)}}" }, \   {"float", \     "%{!msoft-float:%{!mhard-float:%{!mfloat-abi=*:-mfloat-abi=%(VALUE)}}}" }, \   {"fpu", "%{!mfpu=*:-mfpu=%(VALUE)}"}, \   {"abi", "%{!mabi=*:-mabi=%(VALUE)}"}, \   {"mode", "%{!marm:%{!mthumb:-m%(VALUE)}}"},
end_define

begin_comment
comment|/* Which floating point model to use.  */
end_comment

begin_enum
enum|enum
name|arm_fp_model
block|{
name|ARM_FP_MODEL_UNKNOWN
block|,
comment|/* FPA model (Hardware or software).  */
name|ARM_FP_MODEL_FPA
block|,
comment|/* Cirrus Maverick floating point model.  */
name|ARM_FP_MODEL_MAVERICK
block|,
comment|/* VFP floating point model.  */
name|ARM_FP_MODEL_VFP
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|arm_fp_model
name|arm_fp_model
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which floating point hardware is available.  Also update    fp_model_for_fpu in arm.c when adding entries to this list.  */
end_comment

begin_enum
enum|enum
name|fputype
block|{
comment|/* No FP hardware.  */
name|FPUTYPE_NONE
block|,
comment|/* Full FPA support.  */
name|FPUTYPE_FPA
block|,
comment|/* Emulated FPA hardware, Issue 2 emulator (no LFM/SFM).  */
name|FPUTYPE_FPA_EMU2
block|,
comment|/* Emulated FPA hardware, Issue 3 emulator.  */
name|FPUTYPE_FPA_EMU3
block|,
comment|/* Cirrus Maverick floating point co-processor.  */
name|FPUTYPE_MAVERICK
block|,
comment|/* VFP.  */
name|FPUTYPE_VFP
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
value|((enum attr_fpu) arm_fpu_tune)
end_define

begin_comment
comment|/* What type of floating point to tune for */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|fputype
name|arm_fpu_tune
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What type of floating point instructions are available */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|fputype
name|arm_fpu_arch
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|float_abi_type
block|{
name|ARM_FLOAT_ABI_SOFT
block|,
name|ARM_FLOAT_ABI_SOFTFP
block|,
name|ARM_FLOAT_ABI_HARD
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|float_abi_type
name|arm_float_abi
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT_FLOAT_ABI
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT_FLOAT_ABI
value|ARM_FLOAT_ABI_SOFT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Which ABI to use.  */
end_comment

begin_enum
enum|enum
name|arm_abi_type
block|{
name|ARM_ABI_APCS
block|,
name|ARM_ABI_ATPCS
block|,
name|ARM_ABI_AAPCS
block|,
name|ARM_ABI_IWMMXT
block|,
name|ARM_ABI_AAPCS_LINUX
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|arm_abi_type
name|arm_abi
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_DEFAULT_ABI
end_ifndef

begin_define
define|#
directive|define
name|ARM_DEFAULT_ABI
value|ARM_ABI_APCS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Which thread pointer access sequence to use.  */
end_comment

begin_enum
enum|enum
name|arm_tp_type
block|{
name|TP_AUTO
block|,
name|TP_SOFT
block|,
name|TP_CP15
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|arm_tp_type
name|target_thread_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 3M extensions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch3m
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 4 extensions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 4T extensions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch4t
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 5 extensions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 5E extensions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch5e
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports the ARM Architecture 6 extensions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch6
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
name|arm_tune_strongarm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip is a Cirrus variant.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch_cirrus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip supports Intel XScale with Wireless MMX technology.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch_iwmmxt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if this chip is an XScale.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_arch_xscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if tuning for XScale.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_tune_xscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if tuning for stores via the write buffer.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_tune_wbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we should define __THUMB_INTERWORK__ in the    preprocessor.    XXX This is a bit of a hack, it's intended to help work around    problems in GLD which doesn't understand that armv5t code is    interworking clean.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_cpp_interwork
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
value|(MASK_APCS_FRAME)
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
comment|/* Nonzero if we need to refer to the GOT with a PC-relative    offset.  In other words, generate     .word	_GLOBAL_OFFSET_TABLE_ - [. - (.Lxx + 8)]     rather than     .word	_GLOBAL_OFFSET_TABLE_ - (.Lxx + 8)     The default is true, which matches NetBSD.  Subtargets can    override this if required.  */
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
value|if (GET_MODE_CLASS (MODE) == MODE_INT		\&& GET_MODE_SIZE (MODE)< 4)      	\     {						\       if (MODE == QImode)			\ 	UNSIGNEDP = 1;				\       else if (MODE == HImode)			\ 	UNSIGNEDP = 1;				\       (MODE) = SImode;				\     }
end_define

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_MODE
parameter_list|(
name|MODE
parameter_list|,
name|UNSIGNEDP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|if ((GET_MODE_CLASS (MODE) == MODE_INT		\        || GET_MODE_CLASS (MODE) == MODE_COMPLEX_INT)    \&& GET_MODE_SIZE (MODE)< 4)                      \     (MODE) = SImode;
end_define

begin_comment
unit|\
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.    Most ARM processors are run in little endian mode, so that is the default.    If you want to have it run-time selectable, change the definition in a    cover file to be TARGET_BIG_ENDIAN.  */
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
comment|/* Define this if most significant word of doubles is the lowest numbered.    The rules are different based on whether or not we use FPA-format,    VFP-format or some other floating point co-processor's format doubles.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_WORDS_BIG_ENDIAN
value|(arm_float_words_big_endian ())
end_define

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* True if natural alignment is used for doubleword types.  */
end_comment

begin_define
define|#
directive|define
name|ARM_DOUBLEWORD_ALIGN
value|TARGET_AAPCS_BASED
end_define

begin_define
define|#
directive|define
name|DOUBLEWORD_ALIGNMENT
value|64
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
value|(ARM_DOUBLEWORD_ALIGN ? DOUBLEWORD_ALIGNMENT : 32)
end_define

begin_define
define|#
directive|define
name|PREFERRED_STACK_BOUNDARY
define|\
value|(arm_abi == ARM_ABI_ATPCS ? 64 : STACK_BOUNDARY)
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
value|(ARM_DOUBLEWORD_ALIGN ? DOUBLEWORD_ALIGNMENT : 32)
end_define

begin_comment
comment|/* XXX Blah -- this macro is used directly by libobjc.  Since it    supports no vector modes, cut out the complexity and fall back    on BIGGEST_FIELD_ALIGNMENT.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_TARGET_LIBS
end_ifdef

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make strings word-aligned so strcpy from constants will be faster.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ALIGNMENT_FACTOR
value|(TARGET_THUMB || ! arm_tune_xscale ? 1 : 2)
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
value|((TREE_CODE (EXP) == STRING_CST				\&& (ALIGN)< BITS_PER_WORD * CONSTANT_ALIGNMENT_FACTOR)	\     ? BITS_PER_WORD * CONSTANT_ALIGNMENT_FACTOR : (ALIGN))
end_define

begin_comment
comment|/* Setting STRUCTURE_SIZE_BOUNDARY to 32 produces more efficient code, but the    value set in previous versions of this toolchain was 8, which produces more    compact structures.  The command line option -mstructure_size_boundary=<n>    can be used to change this value.  For compatibility with the ARM SDK    however the value should be left at 32.  ARM SDT Reference Manual (ARM DUI    0020D) page 2-20 says "Structures are aligned on word boundaries".    The AAPCS specifies a value of 8.  */
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
comment|/* This is the value used to initialize arm_structure_size_boundary.  If a    particular arm target wants to change the default value it should change    the definition of this macro, not STRUCTURE_SIZE_BOUNDARY.  See netbsd.h    for an example of this.  */
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
comment|/* Nonzero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* wchar_t is unsigned under the AAPCS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_TYPE
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|(TARGET_AAPCS_BASED ? "unsigned int" : "int")
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|(TARGET_AAPCS_BASED ? "unsigned int" : "long unsigned int")
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
value|(TARGET_AAPCS_BASED ? "int" : "long int")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AAPCS requires that structure alignment is affected by bitfields.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCC_BITFIELD_TYPE_MATTERS
end_ifndef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|TARGET_AAPCS_BASED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Register allocation in ARM Procedure Call Standard (as used on RISCiX):    (S - saved over call).  	r0	   *	argument word/integer result 	r1-r3		argument word  	r4-r8	     S	register variable 	r9	     S	(rfp) register variable (real frame pointer)  	r10  	   F S	(sl) stack limit (used by -mapcs-stack-check) 	r11 	   F S	(fp) argument pointer 	r12		(ip) temp workspace 	r13  	   F S	(sp) lower end of current stack frame 	r14		(lr) link address/workspace 	r15	   F	(pc) program counter  	f0		floating point result 	f1-f3		floating point scratch  	f4-f7	     S	floating point variable  	cc		This is NOT a real register, but is used internally 	                to represent things that use or set the condition 			codes. 	sfp             This isn't either.  It is used during rtl generation 	                since the offset between the frame pointer and the 			auto's isn't known until after register allocation. 	afp		Nor this, we only need this because of non-local 	                goto.  Without it fp appears to be used and the 			elimination code won't get rid of sfp.  It tracks 			fp exactly at all times.     *: See CONDITIONAL_REGISTER_USAGE  */
end_comment

begin_comment
comment|/*   	mvf0		Cirrus floating point result 	mvf1-mvf3	Cirrus floating point scratch 	mvf4-mvf15   S	Cirrus floating point variable.  */
end_comment

begin_comment
comment|/*	s0-s15		VFP scratch (aka d0-d7). 	s16-s31	      S	VFP variable (aka d8-d15). 	vfpcc		Not a real register.  Represents the VFP condition 			code flags.  */
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
value|{                       \   0,0,0,0,0,0,0,0,	\   0,0,0,0,0,1,0,1,	\   0,0,0,0,0,0,0,0,	\   1,1,1,		\   1,1,1,1,1,1,1,1,	\   1,1,1,1,1,1,1,1,	\   1,1,1,1,1,1,1,1,	\   1,1,1,1,1,1,1,1,	\   1,1,1,1,		\   1,1,1,1,1,1,1,1,	\   1,1,1,1,1,1,1,1,	\   1,1,1,1,1,1,1,1,	\   1,1,1,1,1,1,1,1,	\   1			\ }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.    The CC is not preserved over function calls on the ARM 6, so it is    easier to assume this for all.  SFP is preserved, since FP is.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{                            \   1,1,1,1,0,0,0,0,	     \   0,0,0,0,1,1,1,1,	     \   1,1,1,1,0,0,0,0,	     \   1,1,1,		     \   1,1,1,1,1,1,1,1,	     \   1,1,1,1,1,1,1,1,	     \   1,1,1,1,1,1,1,1,	     \   1,1,1,1,1,1,1,1,	     \   1,1,1,1,		     \   1,1,1,1,1,1,1,1,	     \   1,1,1,1,1,1,1,1,	     \   1,1,1,1,1,1,1,1,	     \   1,1,1,1,1,1,1,1,	     \   1			     \ }
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
value|{								\   int regno;							\ 								\   if (TARGET_SOFT_FLOAT || TARGET_THUMB || !TARGET_FPA)		\     {								\       for (regno = FIRST_FPA_REGNUM;				\ 	   regno<= LAST_FPA_REGNUM; ++regno)			\ 	fixed_regs[regno] = call_used_regs[regno] = 1;		\     }								\ 								\   if (TARGET_THUMB&& optimize_size)				\     {								\
comment|/* When optimizing for size, it's better not to use	\ 	 the HI regs, because of the overhead of stacking 	\ 	 them.  */
value|\       for (regno = FIRST_HI_REGNUM;				\ 	   regno<= LAST_HI_REGNUM; ++regno)			\ 	fixed_regs[regno] = call_used_regs[regno] = 1;		\     }								\ 								\
comment|/* The link register can be clobbered by any branch insn,	\      but we have no way to track that at present, so mark	\      it as unavailable.  */
value|\   if (TARGET_THUMB)						\     fixed_regs[LR_REGNUM] = call_used_regs[LR_REGNUM] = 1;	\ 								\   if (TARGET_ARM&& TARGET_HARD_FLOAT)				\     {								\       if (TARGET_MAVERICK)					\ 	{							\ 	  for (regno = FIRST_FPA_REGNUM;			\ 	       regno<= LAST_FPA_REGNUM; ++ regno)		\ 	    fixed_regs[regno] = call_used_regs[regno] = 1;	\ 	  for (regno = FIRST_CIRRUS_FP_REGNUM;			\ 	       regno<= LAST_CIRRUS_FP_REGNUM; ++ regno)	\ 	    {							\ 	      fixed_regs[regno] = 0;				\ 	      call_used_regs[regno] = regno< FIRST_CIRRUS_FP_REGNUM + 4; \ 	    }							\ 	}							\       if (TARGET_VFP)						\ 	{							\ 	  for (regno = FIRST_VFP_REGNUM;			\ 	       regno<= LAST_VFP_REGNUM; ++ regno)		\ 	    {							\ 	      fixed_regs[regno] = 0;				\ 	      call_used_regs[regno] = regno< FIRST_VFP_REGNUM + 16; \ 	    }							\ 	}							\     }								\ 								\   if (TARGET_REALLY_IWMMXT)					\     {								\       regno = FIRST_IWMMXT_GR_REGNUM;				\
comment|/* The 2002/10/09 revision of the XScale ABI has wCG0     \          and wCG1 as call-preserved registers.  The 2002/11/21  \          revision changed this so that all wCG registers are    \          scratch registers.  */
value|\       for (regno = FIRST_IWMMXT_GR_REGNUM;			\ 	   regno<= LAST_IWMMXT_GR_REGNUM; ++ regno)		\ 	fixed_regs[regno] = 0;					\
comment|/* The XScale ABI has wR0 - wR9 as scratch registers,     \ 	 the rest as call-preserved registers.  */
value|\       for (regno = FIRST_IWMMXT_REGNUM;				\ 	   regno<= LAST_IWMMXT_REGNUM; ++ regno)		\ 	{							\ 	  fixed_regs[regno] = 0;				\ 	  call_used_regs[regno] = regno< FIRST_IWMMXT_REGNUM + 10; \ 	}							\     }								\ 								\   if ((unsigned) PIC_OFFSET_TABLE_REGNUM != INVALID_REGNUM)	\     {								\       fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;			\       call_used_regs[PIC_OFFSET_TABLE_REGNUM] = 1;		\     }								\   else if (TARGET_APCS_STACK)					\     {								\       fixed_regs[10]     = 1;					\       call_used_regs[10] = 1;					\     }								\
comment|/* -mcaller-super-interworking reserves r11 for calls to	\      _interwork_r11_call_via_rN().  Making the register global	\      is an easy way of ensuring that it remains valid for all	\      calls.  */
value|\   if (TARGET_APCS_FRAME || TARGET_CALLER_INTERWORKING		\       || TARGET_TPCS_FRAME || TARGET_TPCS_LEAF_FRAME)		\     {								\       fixed_regs[ARM_HARD_FRAME_POINTER_REGNUM] = 1;		\       call_used_regs[ARM_HARD_FRAME_POINTER_REGNUM] = 1;	\       if (TARGET_CALLER_INTERWORKING)				\ 	global_regs[ARM_HARD_FRAME_POINTER_REGNUM] = 1;		\     }								\   SUBTARGET_CONDITIONAL_REGISTER_USAGE				\ }
end_define

begin_comment
comment|/* These are a couple of extensions to the formats accepted    by asm_fprintf:      %@ prints out ASM_COMMENT_START      %r prints out REGISTER_PREFIX reg_names[arg]  */
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
name|ROUND_UP_WORD
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
name|ARM_NUM_INTS
parameter_list|(
name|X
parameter_list|)
value|(((X) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* The number of (integer) registers required to hold a quantity of type MODE.    Also used for VFP registers.  */
end_comment

begin_define
define|#
directive|define
name|ARM_NUM_REGS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|ARM_NUM_INTS (GET_MODE_SIZE (MODE))
end_define

begin_comment
comment|/* The number of (integer) registers required to hold a quantity of TYPE MODE.  */
end_comment

begin_define
define|#
directive|define
name|ARM_NUM_REGS2
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|ARM_NUM_INTS ((MODE) == BLKmode ? 		\   int_size_in_bytes (TYPE) : GET_MODE_SIZE (MODE))
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
comment|/* Return the register number of the N'th (integer) argument.  */
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
comment|/* The numbers of the Thumb register ranges.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_LO_REGNUM
value|0
end_define

begin_define
define|#
directive|define
name|LAST_LO_REGNUM
value|7
end_define

begin_define
define|#
directive|define
name|FIRST_HI_REGNUM
value|8
end_define

begin_define
define|#
directive|define
name|LAST_HI_REGNUM
value|11
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_UNWIND_INFO
end_ifndef

begin_comment
comment|/* We use sjlj exceptions for backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|MUST_USE_SJLJ_EXCEPTIONS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We can generate DWARF2 Unwind info, even though we don't use it.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_comment
comment|/* Use r0 and r1 to pass exception handling information.  */
end_comment

begin_define
define|#
directive|define
name|EH_RETURN_DATA_REGNO
parameter_list|(
name|N
parameter_list|)
value|(((N)< 2) ? N : INVALID_REGNUM)
end_define

begin_comment
comment|/* The register that holds the return address in exception handlers.  */
end_comment

begin_define
define|#
directive|define
name|ARM_EH_STACKADJ_REGNUM
value|2
end_define

begin_define
define|#
directive|define
name|EH_RETURN_STACKADJ_RTX
value|gen_rtx_REG (SImode, ARM_EH_STACKADJ_REGNUM)
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
comment|/* Define this to be where the real frame pointer is if it is not possible to    work out the offset between the frame pointer and the automatic variables    until after register allocation has taken place.  FRAME_POINTER_REGNUM    should point to a special register that we will make sure is eliminated.     For the Thumb we have another problem.  The TPCS defines the frame pointer    as r11, and GCC believes that it is always possible to use the frame pointer    as base register for addressing purposes.  (See comments in    find_reloads_address()).  But - the Thumb does not allow high registers,    including r11, to be used as base address registers.  Hence our problem.     The solution used here, and in the old thumb port is to use r7 instead of    r11 as the hard frame pointer and to have special code to generate    backtrace structures on the stack (if required to do so via a command line    option) using r11.  This is the only 'user visible' use of r11 as a frame    pointer.  */
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
name|FIRST_FPA_REGNUM
value|16
end_define

begin_define
define|#
directive|define
name|LAST_FPA_REGNUM
value|23
end_define

begin_define
define|#
directive|define
name|IS_FPA_REGNUM
parameter_list|(
name|REGNUM
parameter_list|)
define|\
value|(((REGNUM)>= FIRST_FPA_REGNUM)&& ((REGNUM)<= LAST_FPA_REGNUM))
end_define

begin_define
define|#
directive|define
name|FIRST_IWMMXT_GR_REGNUM
value|43
end_define

begin_define
define|#
directive|define
name|LAST_IWMMXT_GR_REGNUM
value|46
end_define

begin_define
define|#
directive|define
name|FIRST_IWMMXT_REGNUM
value|47
end_define

begin_define
define|#
directive|define
name|LAST_IWMMXT_REGNUM
value|62
end_define

begin_define
define|#
directive|define
name|IS_IWMMXT_REGNUM
parameter_list|(
name|REGNUM
parameter_list|)
define|\
value|(((REGNUM)>= FIRST_IWMMXT_REGNUM)&& ((REGNUM)<= LAST_IWMMXT_REGNUM))
end_define

begin_define
define|#
directive|define
name|IS_IWMMXT_GR_REGNUM
parameter_list|(
name|REGNUM
parameter_list|)
define|\
value|(((REGNUM)>= FIRST_IWMMXT_GR_REGNUM)&& ((REGNUM)<= LAST_IWMMXT_GR_REGNUM))
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

begin_define
define|#
directive|define
name|FIRST_CIRRUS_FP_REGNUM
value|27
end_define

begin_define
define|#
directive|define
name|LAST_CIRRUS_FP_REGNUM
value|42
end_define

begin_define
define|#
directive|define
name|IS_CIRRUS_REGNUM
parameter_list|(
name|REGNUM
parameter_list|)
define|\
value|(((REGNUM)>= FIRST_CIRRUS_FP_REGNUM)&& ((REGNUM)<= LAST_CIRRUS_FP_REGNUM))
end_define

begin_define
define|#
directive|define
name|FIRST_VFP_REGNUM
value|63
end_define

begin_define
define|#
directive|define
name|LAST_VFP_REGNUM
value|94
end_define

begin_define
define|#
directive|define
name|IS_VFP_REGNUM
parameter_list|(
name|REGNUM
parameter_list|)
define|\
value|(((REGNUM)>= FIRST_VFP_REGNUM)&& ((REGNUM)<= LAST_VFP_REGNUM))
end_define

begin_comment
comment|/* The number of hard registers is 16 ARM + 8 FPA + 1 CC + 1 SFP + 1 AFP.  */
end_comment

begin_comment
comment|/* + 16 Cirrus registers take us up to 43.  */
end_comment

begin_comment
comment|/* Intel Wireless MMX Technology registers add 16 + 4 more.  */
end_comment

begin_comment
comment|/* VFP adds 32 + 1 more.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|96
end_define

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|arm_dbx_register_number (REGNO)
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms may be accessed    via the stack pointer) in functions that seem suitable.    If we have to have a frame pointer we might as well make use of it.    APCS says that the frame pointer does not need to be pushed in leaf    functions, or simple tail call functions.  */
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

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
define|\
value|(current_function_has_nonlocal_label				\    || SUBTARGET_FRAME_POINTER_REQUIRED				\    || (TARGET_ARM&& TARGET_APCS_FRAME&& ! leaf_function_p ()))
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the ARM regs are UNITS_PER_WORD bits wide; FPA regs can hold any FP    mode.  */
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
value|((TARGET_ARM 				\&& REGNO>= FIRST_FPA_REGNUM	\&& REGNO != FRAME_POINTER_REGNUM	\&& REGNO != ARG_POINTER_REGNUM)	\&& !IS_VFP_REGNUM (REGNO)		\    ? 1 : ARM_NUM_REGS (MODE))
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

begin_define
define|#
directive|define
name|VALID_IWMMXT_REG_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(arm_vector_mode_supported_p (MODE) || (MODE) == DImode)
end_define

begin_comment
comment|/* The order in which register should be allocated.  It is good to use ip    since no saving is required (though calls clobber it) and it never contains    function parameters.  It is quite good to use lr since other calls may    clobber it anyway.  Allocate r0 through r3 in reverse order since r3 is    least likely to contain a function parameter; in addition results are    returned in r0.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{                                   \      3,  2,  1,  0, 12, 14,  4,  5, \      6,  7,  8, 10,  9, 11, 13, 15, \     16, 17, 18, 19, 20, 21, 22, 23, \     27, 28, 29, 30, 31, 32, 33, 34, \     35, 36, 37, 38, 39, 40, 41, 42, \     43, 44, 45, 46, 47, 48, 49, 50, \     51, 52, 53, 54, 55, 56, 57, 58, \     59, 60, 61, 62,		    \     24, 25, 26,			    \     78, 77, 76, 75, 74, 73, 72, 71, \     70, 69, 68, 67, 66, 65, 64, 63, \     79, 80, 81, 82, 83, 84, 85, 86, \     87, 88, 89, 90, 91, 92, 93, 94, \     95				    \ }
end_define

begin_comment
comment|/* Interrupt functions can only use registers that have already been    saved by the prologue, even if they would normally be    call-clobbered.  */
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
value|(! IS_INTERRUPT (cfun->machine->func_type) ||			\ 		regs_ever_live[DST])
end_define

begin_escape
end_escape

begin_comment
comment|/* Register and constant classes.  */
end_comment

begin_comment
comment|/* Register classes: used to be simple, just all ARM regs or all FPA regs    Now that the Thumb is involved it has become more complicated.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|FPA_REGS
block|,
name|CIRRUS_REGS
block|,
name|VFP_REGS
block|,
name|IWMMXT_GR_REGS
block|,
name|IWMMXT_REGS
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
name|VFPCC_REG
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
comment|/* Give names of register classes as strings for dump file.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{			\   "NO_REGS",		\   "FPA_REGS",		\   "CIRRUS_REGS",	\   "VFP_REGS",		\   "IWMMXT_GR_REGS",	\   "IWMMXT_REGS",	\   "LO_REGS",		\   "STACK_REG",		\   "BASE_REGS",		\   "HI_REGS",		\   "CC_REG",		\   "VFPCC_REG",		\   "GENERAL_REGS",	\   "ALL_REGS",		\ }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{								\   { 0x00000000, 0x00000000, 0x00000000 },
comment|/* NO_REGS  */
value|\   { 0x00FF0000, 0x00000000, 0x00000000 },
comment|/* FPA_REGS */
value|\   { 0xF8000000, 0x000007FF, 0x00000000 },
comment|/* CIRRUS_REGS */
value|\   { 0x00000000, 0x80000000, 0x7FFFFFFF },
comment|/* VFP_REGS  */
value|\   { 0x00000000, 0x00007800, 0x00000000 },
comment|/* IWMMXT_GR_REGS */
value|\   { 0x00000000, 0x7FFF8000, 0x00000000 },
comment|/* IWMMXT_REGS */
value|\   { 0x000000FF, 0x00000000, 0x00000000 },
comment|/* LO_REGS */
value|\   { 0x00002000, 0x00000000, 0x00000000 },
comment|/* STACK_REG */
value|\   { 0x000020FF, 0x00000000, 0x00000000 },
comment|/* BASE_REGS */
value|\   { 0x0000FF00, 0x00000000, 0x00000000 },
comment|/* HI_REGS */
value|\   { 0x01000000, 0x00000000, 0x00000000 },
comment|/* CC_REG */
value|\   { 0x00000000, 0x00000000, 0x80000000 },
comment|/* VFPCC_REG */
value|\   { 0x0200FFFF, 0x00000000, 0x00000000 },
comment|/* GENERAL_REGS */
value|\   { 0xFAFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF }
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
comment|/* FPA registers can't do subreg as all values are reformatted to internal    precision.  VFP registers may only be accessed in the mode they    were set.  */
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
value|(GET_MODE_SIZE (FROM) != GET_MODE_SIZE (TO)		\    ? reg_classes_intersect_p (FPA_REGS, (CLASS))	\      || reg_classes_intersect_p (VFP_REGS, (CLASS))	\    : 0)
end_define

begin_comment
comment|/* We need to define this for LO_REGS on thumb.  Otherwise we can end up    using r0-r4 for function arguments, r7 for the stack frame and don't    have enough left over to do doubleword arithmetic.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_LIKELY_SPILLED_P
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|((TARGET_THUMB&& (CLASS) == LO_REGS)	\      || (CLASS) == CC_REG)
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
value|(TARGET_THUMB ? LO_REGS : GENERAL_REGS)
end_define

begin_comment
comment|/* For the Thumb the high registers cannot be used as base registers    when addressing quantities in QI or HI mode; if we don't know the    mode, then we must be conservative.  */
end_comment

begin_define
define|#
directive|define
name|MODE_BASE_REG_CLASS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARM ? GENERAL_REGS :					\      (((MODE) == SImode) ? BASE_REGS : LO_REGS))
end_define

begin_comment
comment|/* For Thumb we can not support SP+reg addressing, so we return LO_REGS    instead of BASE_REGS.  */
end_comment

begin_define
define|#
directive|define
name|MODE_BASE_REG_REG_CLASS
parameter_list|(
name|MODE
parameter_list|)
value|BASE_REG_CLASS
end_define

begin_comment
comment|/* When SMALL_REGISTER_CLASSES is nonzero, the compiler allows    registers explicitly used in the rtl to be used as spill registers    but prevents the compiler from extending the lifetime of these    registers.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_REGISTER_CLASSES
value|TARGET_THUMB
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
value|((CLASS) != LO_REGS&& (CLASS) != BASE_REGS				\    ? ((true_regnum (X) == -1 ? LO_REGS					\        : (true_regnum (X) + HARD_REGNO_NREGS (0, MODE)> 8) ? LO_REGS	\        : NO_REGS)) 							\    : NO_REGS)
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
comment|/* Restrict which direct reloads are allowed for VFP/iWMMXt regs.  */
define|\
value|((TARGET_VFP&& TARGET_HARD_FLOAT				\&& (CLASS) == VFP_REGS)					\    ? coproc_secondary_reload_class (MODE, X, FALSE)		\    : (TARGET_IWMMXT&& (CLASS) == IWMMXT_REGS)			\    ? coproc_secondary_reload_class (MODE, X, TRUE)		\    : TARGET_ARM							\    ? (((MODE) == HImode&& ! arm_arch4&& true_regnum (X) == -1) \     ? GENERAL_REGS : NO_REGS)					\    : THUMB_SECONDARY_OUTPUT_RELOAD_CLASS (CLASS, MODE, X))
end_define

begin_comment
comment|/* If we need to load shorts byte-at-a-time, then we need a scratch.  */
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
comment|/* Restrict which direct reloads are allowed for VFP/iWMMXt regs.  */
define|\
value|((TARGET_VFP&& TARGET_HARD_FLOAT				\&& (CLASS) == VFP_REGS)					\     ? coproc_secondary_reload_class (MODE, X, FALSE) :		\     (TARGET_IWMMXT&& (CLASS) == IWMMXT_REGS) ?			\     coproc_secondary_reload_class (MODE, X, TRUE) :		\
comment|/* Cannot load constants into Cirrus registers.  */
value|\    (TARGET_MAVERICK&& TARGET_HARD_FLOAT			\&& (CLASS) == CIRRUS_REGS					\&& (CONSTANT_P (X) || GET_CODE (X) == SYMBOL_REF))		\     ? GENERAL_REGS :						\   (TARGET_ARM ?							\    (((CLASS) == IWMMXT_REGS || (CLASS) == IWMMXT_GR_REGS)	\&& CONSTANT_P (X))					\    ? GENERAL_REGS :						\    (((MODE) == HImode&& ! arm_arch4				\&& (GET_CODE (X) == MEM					\ 	 || ((GET_CODE (X) == REG || GET_CODE (X) == SUBREG)	\&& true_regnum (X) == -1)))			\     ? GENERAL_REGS : NO_REGS)					\    : THUMB_SECONDARY_INPUT_RELOAD_CLASS (CLASS, MODE, X)))
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
value|do									   \     {									   \       if (GET_CODE (X) == PLUS						   \&& GET_CODE (XEXP (X, 0)) == REG				   \&& REGNO (XEXP (X, 0))< FIRST_PSEUDO_REGISTER		   \&& REG_MODE_OK_FOR_BASE_P (XEXP (X, 0), MODE)			   \&& GET_CODE (XEXP (X, 1)) == CONST_INT)			   \ 	{								   \ 	  HOST_WIDE_INT val = INTVAL (XEXP (X, 1));			   \ 	  HOST_WIDE_INT low, high;					   \ 									   \ 	  if (MODE == DImode || (MODE == DFmode&& TARGET_SOFT_FLOAT))	   \ 	    low = ((val& 0xf) ^ 0x8) - 0x8;				   \ 	  else if (TARGET_MAVERICK&& TARGET_HARD_FLOAT)		   \
comment|/* Need to be careful, -256 is not a valid offset.  */
value|\ 	    low = val>= 0 ? (val& 0xff) : -((-val)& 0xff);		   \ 	  else if (MODE == SImode					   \ 		   || (MODE == SFmode&& TARGET_SOFT_FLOAT)		   \ 		   || ((MODE == HImode || MODE == QImode)&& ! arm_arch4)) \
comment|/* Need to be careful, -4096 is not a valid offset.  */
value|\ 	    low = val>= 0 ? (val& 0xfff) : -((-val)& 0xfff);		   \ 	  else if ((MODE == HImode || MODE == QImode)&& arm_arch4)	   \
comment|/* Need to be careful, -256 is not a valid offset.  */
value|\ 	    low = val>= 0 ? (val& 0xff) : -((-val)& 0xff);		   \ 	  else if (GET_MODE_CLASS (MODE) == MODE_FLOAT			   \&& TARGET_HARD_FLOAT&& TARGET_FPA)			   \
comment|/* Need to be careful, -1024 is not a valid offset.  */
value|\ 	    low = val>= 0 ? (val& 0x3ff) : -((-val)& 0x3ff);		   \ 	  else								   \ 	    break;							   \ 									   \ 	  high = ((((val - low)& (unsigned HOST_WIDE_INT) 0xffffffff)	   \ 		   ^ (unsigned HOST_WIDE_INT) 0x80000000)		   \ 		  - (unsigned HOST_WIDE_INT) 0x80000000);		   \
comment|/* Check for overflow or zero */
value|\ 	  if (low == 0 || high == 0 || (high + low != val))		   \ 	    break;							   \ 									   \
comment|/* Reload the high part into a base reg; leave the low part	   \ 	     in the mem.  */
value|\ 	  X = gen_rtx_PLUS (GET_MODE (X),				   \ 			    gen_rtx_PLUS (GET_MODE (X), XEXP (X, 0),	   \ 					  GEN_INT (high)),		   \ 			    GEN_INT (low));				   \ 	  push_reload (XEXP (X, 0), NULL_RTX,&XEXP (X, 0), NULL,	   \ 		       MODE_BASE_REG_CLASS (MODE), GET_MODE (X), 	   \ 		       VOIDmode, 0, 0, OPNUM, TYPE);			   \ 	  goto WIN;							   \ 	}								   \     }									   \   while (0)
end_define

begin_comment
comment|/* XXX If an HImode FP+large_offset address is converted to an HImode    SP+large_offset address, then reload won't know how to fix it.  It sees    only that SP isn't valid for HImode, and so reloads the SP into an index    register, but the resulting address is still invalid because the offset    is too big.  We fix it here instead by reloading the entire address.  */
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
name|IND_L
parameter_list|,
name|WIN
parameter_list|)
define|\
value|do {									      \   rtx new_x = thumb_legitimize_reload_address (&X, MODE, OPNUM, TYPE, IND_L); \   if (new_x)								      \     {									      \       X = new_x;							      \       goto WIN;								      \     }									      \ } while (0)
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
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.    ARM regs are UNITS_PER_WORD bits while FPA regs can hold any FP mode */
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
value|(((CLASS) == FPA_REGS || (CLASS) == CIRRUS_REGS) ? 1 : ARM_NUM_REGS (MODE))
end_define

begin_comment
comment|/* If defined, gives a class of registers that cannot be used as the    operand of a SUBREG that changes the mode of the object illegally.  */
end_comment

begin_comment
comment|/* Moves between FPA_REGS and GENERAL_REGS are two memory insns.  */
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
value|(TARGET_ARM ?						\    ((FROM) == FPA_REGS&& (TO) != FPA_REGS ? 20 :	\     (FROM) != FPA_REGS&& (TO) == FPA_REGS ? 20 :	\     (FROM) == VFP_REGS&& (TO) != VFP_REGS ? 10 :  \     (FROM) != VFP_REGS&& (TO) == VFP_REGS ? 10 :  \     (FROM) == IWMMXT_REGS&& (TO) != IWMMXT_REGS ? 4 :  \     (FROM) != IWMMXT_REGS&& (TO) == IWMMXT_REGS ? 4 :  \     (FROM) == IWMMXT_GR_REGS || (TO) == IWMMXT_GR_REGS ? 20 :  \     (FROM) == CIRRUS_REGS&& (TO) != CIRRUS_REGS ? 20 :	\     (FROM) != CIRRUS_REGS&& (TO) == CIRRUS_REGS ? 20 :	\    2)							\    :							\    ((FROM) == HI_REGS || (TO) == HI_REGS) ? 4 : 2)
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
comment|/* Define this to nonzero if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
value|1
end_define

begin_comment
comment|/* The amount of scratch space needed by _interwork_{r7,r11}_call_via_rN().    When present, it is one word in size, and sits at the top of the frame,    between the soft frame pointer and either r7 or r11.     We only need _interwork_rM_call_via_rN() for -mcaller-super-interworking,    and only then if some outgoing arguments are passed on the stack.  It would    be tempting to also check whether the stack arguments are passed by indirect    calls, but there seems to be no reason in principle why a post-reload pass    couldn't convert a direct call into an indirect one.  */
end_comment

begin_define
define|#
directive|define
name|CALLER_INTERWORKING_SLOT_SIZE
define|\
value|(TARGET_CALLER_INTERWORKING				\&& current_function_outgoing_args_size != 0		\    ? UNITS_PER_WORD : 0)
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
comment|/* The push insns do not do this rounding implicitly.    So don't define this.  */
end_comment

begin_comment
comment|/* #define PUSH_ROUNDING(NPUSHED)  ROUND_UP_WORD (NPUSHED) */
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
value|(TARGET_ARM&& TARGET_HARD_FLOAT_ABI&& TARGET_FPA			\&& GET_MODE_CLASS (MODE) == MODE_FLOAT				\    ? gen_rtx_REG (MODE, FIRST_FPA_REGNUM)				\    : TARGET_ARM&& TARGET_HARD_FLOAT_ABI&& TARGET_MAVERICK		\&& GET_MODE_CLASS (MODE) == MODE_FLOAT				\    ? gen_rtx_REG (MODE, FIRST_CIRRUS_FP_REGNUM) 			\    : TARGET_IWMMXT_ABI&& arm_vector_mode_supported_p (MODE)    	\    ? gen_rtx_REG (MODE, FIRST_IWMMXT_REGNUM) 				\    : gen_rtx_REG (MODE, ARG_REGISTER (1)))
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
value|arm_function_value (VALTYPE, FUNC);
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the ARM, only r0 and f0 can return results.  */
end_comment

begin_comment
comment|/* On a Cirrus chip, mvf0 can return results.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO) == ARG_REGISTER (1) \    || (TARGET_ARM&& ((REGNO) == FIRST_CIRRUS_FP_REGNUM)		\&& TARGET_HARD_FLOAT_ABI&& TARGET_MAVERICK)			\    || ((REGNO) == FIRST_IWMMXT_REGNUM&& TARGET_IWMMXT_ABI) \    || (TARGET_ARM&& ((REGNO) == FIRST_FPA_REGNUM)			\&& TARGET_HARD_FLOAT_ABI&& TARGET_FPA))
end_define

begin_comment
comment|/* Amount of memory needed for an untyped call to save all possible return    registers.  */
end_comment

begin_define
define|#
directive|define
name|APPLY_RESULT_SIZE
value|arm_apply_result_size()
end_define

begin_comment
comment|/* How large values are returned */
end_comment

begin_comment
comment|/* A C expression which can inhibit the returning of certain function values    in registers, based on the type of value.  */
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
comment|/* Define DEFAULT_PCC_STRUCT_RETURN to 1 if all structure and union return    values must be in memory.  On the ARM, they need only do so if larger    than a word, or if they contain elements offset from zero in the struct.  */
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
comment|/* These bits describe the different types of function supported    by the ARM backend.  They are exclusive.  i.e. a function cannot be both a    normal function and an interworked function, for example.  Knowing the    type of a function is important for determining its prologue and    epilogue sequences.    Note value 7 is currently unassigned.  Also note that the interrupt    function types all have bit 2 set, so that they can be tested for easily.    Note that 0 is deliberately chosen for ARM_FT_UNKNOWN so that when the    machine_function structure is initialized (to zero) func_type will    default to unknown.  This will force the first use of arm_current_func_type    to call arm_compute_func_type.  */
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
comment|/* Embedded inside another func.  */
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
comment|/* Structure used to hold the function stack frame layout.  Offsets are    relative to the stack pointer on function entry.  Positive offsets are    in the direction of stack growth.    Only soft_frame is used in thumb mode.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|arm_stack_offsets
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|int
name|saved_args
block|;
comment|/* ARG_POINTER_REGNUM.  */
name|int
name|frame
block|;
comment|/* ARM_HARD_FRAME_POINTER_REGNUM.  */
name|int
name|saved_regs
block|;
name|int
name|soft_frame
block|;
comment|/* FRAME_POINTER_REGNUM.  */
name|int
name|locals_base
block|;
comment|/* THUMB_HARD_FRAME_POINTER_REGNUM.  */
name|int
name|outgoing_args
block|;
comment|/* STACK_POINTER_REGNUM.  */
block|}
end_typedef

begin_expr_stmt
name|arm_stack_offsets
expr_stmt|;
end_expr_stmt

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
comment|/* Additional stack adjustment in __builtin_eh_throw.  */
name|rtx
name|eh_epilogue_sp_ofs
block|;
comment|/* Records if LR has to be saved for far jumps.  */
name|int
name|far_jump_used
block|;
comment|/* Records if ARG_POINTER was ever live.  */
name|int
name|arg_pointer_live
block|;
comment|/* Records if the save of LR has been eliminated.  */
name|int
name|lr_save_eliminated
block|;
comment|/* The size of the stack frame.  Only valid after reload.  */
name|arm_stack_offsets
name|stack_offsets
block|;
comment|/* Records the type of the current function.  */
name|unsigned
name|long
name|func_type
block|;
comment|/* Record if the function has a variable argument list.  */
name|int
name|uses_anonymous_args
block|;
comment|/* Records if sibcalls are blocked because an argument      register is needed to preserve stack alignment.  */
name|int
name|sibcall_blocked
block|;
comment|/* The PIC register for this function.  This might be a pseudo.  */
name|rtx
name|pic_reg
block|;
comment|/* Labels for per-function Thumb call-via stubs.  One per potential calling      register.  We can never call via LR or PC.  We can call via SP if a      trampoline happens to be on the top of the stack.  */
name|rtx
name|call_via
index|[
literal|14
index|]
block|; }
end_typedef

begin_expr_stmt
name|machine_function
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* As in the machine_function, a global set of call-via labels, for code     that is in text_section.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|thumb_call_via_label
index|[
literal|14
index|]
decl_stmt|;
end_decl_stmt

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
comment|/* This is the number of iWMMXt register arguments scanned so far.  */
name|int
name|iwmmxt_nregs
decl_stmt|;
name|int
name|named_count
decl_stmt|;
name|int
name|nargs
decl_stmt|;
comment|/* One of CALL_NORMAL, CALL_LONG or CALL_SHORT.  */
name|int
name|call_cookie
decl_stmt|;
name|int
name|can_split
decl_stmt|;
block|}
name|CUMULATIVE_ARGS
typedef|;
end_typedef

begin_comment
comment|/* Define where to put the arguments to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On the ARM, normally the first 16 bytes are passed in registers r0-r3; all    other arguments are passed on the stack.  If (NAMED == 0) (which happens    only in assign_parms, since TARGET_SETUP_INCOMING_VARARGS is    defined), say it is passed in the stack (function_prologue will    indeed make it pass in the stack if necessary).  */
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

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(arm_pad_arg_upward (MODE, TYPE) ? upward : downward)
end_define

begin_define
define|#
directive|define
name|BLOCK_REG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|FIRST
parameter_list|)
define|\
value|(arm_pad_reg_upward (MODE, TYPE, FIRST) ? upward : downward)
end_define

begin_comment
comment|/* For AAPCS, padding should never be below the argument. For other ABIs,  * mimic the default.  */
end_comment

begin_define
define|#
directive|define
name|PAD_VARARGS_DOWN
define|\
value|((TARGET_AAPCS_BASED) ? 0 : BYTES_BIG_ENDIAN)
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
name|FNDECL
parameter_list|,
name|N_NAMED_ARGS
parameter_list|)
define|\
value|arm_init_cumulative_args (&(CUM), (FNTYPE), (LIBNAME), (FNDECL))
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
value|(CUM).nargs += 1;					\   if (arm_vector_mode_supported_p (MODE)	       	\&& (CUM).named_count> (CUM).nargs)		\     (CUM).iwmmxt_nregs += 1;				\   else							\     (CUM).nregs += ARM_NUM_REGS2 (MODE, TYPE)
end_define

begin_comment
comment|/* If defined, a C expression that gives the alignment boundary, in bits, of an    argument with the specified mode and type.  If it is not defined,    `PARM_BOUNDARY' is used for all arguments.  */
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
value|((ARM_DOUBLEWORD_ALIGN&& arm_needs_doubleword_align (MODE, TYPE)) \    ? DOUBLEWORD_ALIGNMENT \    : PARM_BOUNDARY )
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
define|\
value|(IN_RANGE ((REGNO), 0, 3)		\     || (TARGET_IWMMXT_ABI		\&& IN_RANGE ((REGNO), FIRST_IWMMXT_REGNUM, FIRST_IWMMXT_REGNUM + 9)))
end_define

begin_escape
end_escape

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
comment|/* Call the function profiler with a given profile label.  The Acorn    compiler puts this BEFORE the prolog but gcc puts it afterwards.    On the ARM the full profile code will look like: 	.data 	LP1 		.word	0 	.text 		mov	ip, lr 		bl	mcount 		.word	LP1     profile_function() in final.c outputs the .data section, FUNCTION_PROFILER    will output the .text section.     The ``mov ip,lr'' seems like a good idea to stick with cc convention.    ``prof'' doesn't seem to mind about this!     Note - this version of the code is designed to work in both ARM and    Thumb modes.  */
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
value|{							\   char temp[20];					\   rtx sym;						\ 							\   asm_fprintf (STREAM, "\tmov\t%r, %r\n\tbl\t",		\ 	   IP_REGNUM, LR_REGNUM);			\   assemble_name (STREAM, ARM_MCOUNT_NAME);		\   fputc ('\n', STREAM);					\   ASM_GENERATE_INTERNAL_LABEL (temp, "LP", LABELNO);	\   sym = gen_rtx_SYMBOL_REF (Pmode, temp);		\   assemble_aligned_integer (UNITS_PER_WORD, sym);	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|THUMB_FUNCTION_PROFILER
end_ifdef

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

begin_else
else|#
directive|else
end_else

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
value|ARM_FUNCTION_PROFILER (STREAM, LABELNO)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(TARGET_ARM ? use_return_insn (ISCOND, NULL) : 0)
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
name|INITIAL_ELIMINATION_OFFSET
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|if (TARGET_ARM)							\     (OFFSET) = arm_compute_initial_elimination_offset (FROM, TO);	\   else									\     (OFFSET) = thumb_compute_initial_elimination_offset (FROM, TO)
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
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     On the ARM, (if r8 is the static chain regnum, and remembering that    referencing pc adds an offset of 8) the trampoline looks like: 	   ldr 		r8, [pc, #0] 	   ldr		pc, [pc] 	   .word	static chain value 	   .word	function's address    XXX FIXME: When the trampoline returns, r8 will be clobbered.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|INITIALIZE_TRAMPOLINE
end_ifndef

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
value|{									\   emit_move_insn (gen_rtx_MEM (SImode,					\ 			       plus_constant (TRAMP,			\ 					      TARGET_ARM ? 8 : 16)),	\ 		  CXT);							\   emit_move_insn (gen_rtx_MEM (SImode,					\ 			       plus_constant (TRAMP,			\ 					      TARGET_ARM ? 12 : 20)),	\ 		  FNADDR);						\   emit_library_call (gen_rtx_SYMBOL_REF (Pmode, "__clear_cache"),	\ 		     0, VOIDmode, 2, TRAMP, Pmode,			\ 		     plus_constant (TRAMP, TRAMPOLINE_SIZE), Pmode);	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|HAVE_PRE_MODIFY_DISP
value|TARGET_ARM
end_define

begin_define
define|#
directive|define
name|HAVE_POST_MODIFY_DISP
value|TARGET_ARM
end_define

begin_define
define|#
directive|define
name|HAVE_PRE_MODIFY_REG
value|TARGET_ARM
end_define

begin_define
define|#
directive|define
name|HAVE_POST_MODIFY_REG
value|TARGET_ARM
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
comment|/* Nonzero if X can be the base register in a reg+reg addressing mode.    For Thumb, we can not use SP + reg, so reject SP.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_MODE_OK_FOR_REG_BASE_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|REGNO_OK_FOR_INDEX_P (X)
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
comment|/* Maximum number of registers that can appear in a valid memory address.    Shifts in addresses can't be by a register.  */
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
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     On the ARM, allow any integer (invalid ones are removed later by insn    patterns), nice doubles and symbol_refs which refer to the function's    constant pool XXX.     When generating pic allow anything.  */
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
value|(   GET_CODE (X) == CONST_INT		\   || GET_CODE (X) == CONST_DOUBLE	\   || CONSTANT_ADDRESS_P (X)		\   || flag_pic)
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(!arm_tls_referenced_p (X)				\&& (TARGET_ARM ? ARM_LEGITIMATE_CONSTANT_P (X)	\ 		  : THUMB_LEGITIMATE_CONSTANT_P (X)))
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
comment|/* This is a C fragment for the inside of a switch statement.    Each case label should return the number of characters to    be stripped from the start of a function's name, if that    name starts with the indicated character.  */
end_comment

begin_define
define|#
directive|define
name|ARM_NAME_ENCODING_LENGTHS
define|\
value|case SHORT_CALL_FLAG_CHAR: return 1;		\   case LONG_CALL_FLAG_CHAR:  return 1;		\   case '*':  return 1;				\   SUBTARGET_NAME_ENCODING_LENGTHS
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
value|arm_asm_output_labelref (FILE, NAME)
end_define

begin_comment
comment|/* The EABI specifies that constructors should go in .init_array.    Other targets use .ctors for compatibility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_EABI_CTORS_SECTION_OP
end_ifndef

begin_define
define|#
directive|define
name|ARM_EABI_CTORS_SECTION_OP
define|\
value|"\t.section\t.init_array,\"aw\",%init_array"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_EABI_DTORS_SECTION_OP
end_ifndef

begin_define
define|#
directive|define
name|ARM_EABI_DTORS_SECTION_OP
define|\
value|"\t.section\t.fini_array,\"aw\",%fini_array"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARM_CTORS_SECTION_OP
define|\
value|"\t.section\t.ctors,\"aw\",%progbits"
end_define

begin_define
define|#
directive|define
name|ARM_DTORS_SECTION_OP
define|\
value|"\t.section\t.dtors,\"aw\",%progbits"
end_define

begin_comment
comment|/* Define CTORS_SECTION_ASM_OP.  */
end_comment

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|IN_LIBGCC2
end_ifndef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
define|\
value|(TARGET_AAPCS_BASED ? ARM_EABI_CTORS_SECTION_OP : ARM_CTORS_SECTION_OP)
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
define|\
value|(TARGET_AAPCS_BASED ? ARM_EABI_DTORS_SECTION_OP : ARM_DTORS_SECTION_OP)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined (IN_LIBGCC2) */
end_comment

begin_comment
comment|/* In libgcc, CTORS_SECTION_ASM_OP must be a compile-time constant,    so we cannot use the definition above.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_EABI__
end_ifdef

begin_comment
comment|/* The .ctors section is not part of the EABI, so we do not define    CTORS_SECTION_ASM_OP when in libgcc; that prevents crtstuff    from trying to use it.  We do define it when doing normal    compilation, as .init_array can be used instead of .ctors.  */
end_comment

begin_comment
comment|/* There is no need to emit begin or end markers when using    init_array; the dynamic linker will compute the size of the    array itself based on special symbols created by the static    linker.  However, we do need to arrange to set up    exception-handling here.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
value|asm (ARM_EABI_CTORS_SECTION_OP)
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_END
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|DTOR_LIST_BEGIN
value|asm (ARM_EABI_DTORS_SECTION_OP)
end_define

begin_define
define|#
directive|define
name|DTOR_LIST_END
end_define

begin_comment
comment|/* empty */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined (__ARM_EABI__) */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|ARM_CTORS_SECTION_OP
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|ARM_DTORS_SECTION_OP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (__ARM_EABI__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (IN_LIBCC2) */
end_comment

begin_comment
comment|/* True if the operating system can merge entities with vague linkage    (e.g., symbols in COMDAT group) during dynamic linking.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ARM_DYNAMIC_VAGUE_LINKAGE_P
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ARM_DYNAMIC_VAGUE_LINKAGE_P
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the short-call flag for any function compiled in the current    compilation unit.  We skip this for functions with the section    attribute when long-calls are in effect as this tells the compiler    that the section might be placed a long way from the caller.    See arm_is_longcall_p() for more information.  */
end_comment

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
value|if (!TARGET_LONG_CALLS || ! DECL_SECTION_NAME (DECL)) \     arm_encode_call_attribute (DECL, SHORT_CALL_FLAG_CHAR)
end_define

begin_define
define|#
directive|define
name|ARM_OUTPUT_FN_UNWIND
parameter_list|(
name|F
parameter_list|,
name|PROLOGUE
parameter_list|)
value|arm_output_fn_unwind (F, PROLOGUE)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_UNWIND_INFO
end_ifdef

begin_define
define|#
directive|define
name|ARM_EABI_UNWIND_TABLES
define|\
value|((!USING_SJLJ_EXCEPTIONS&& flag_exceptions) || flag_unwind_tables)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_EABI_UNWIND_TABLES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|REG_STRICT_P
value|0
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

begin_define
define|#
directive|define
name|REG_STRICT_P
value|1
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

begin_comment
comment|/* Nonzero if X can be the base register in a reg+reg addressing mode.    For Thumb, we can not use SP + reg, so reject SP.  */
end_comment

begin_define
define|#
directive|define
name|REG_MODE_OK_FOR_REG_BASE_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|REG_OK_FOR_INDEX_P (X)
end_define

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.  */
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

begin_define
define|#
directive|define
name|ARM_GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|WIN
parameter_list|)
define|\
value|{								\     if (arm_legitimate_address_p (MODE, X, SET, REG_STRICT_P))	\       goto WIN;							\   }
end_define

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
value|{								\     if (thumb_legitimate_address_p (MODE, X, REG_STRICT_P))	\       goto WIN;							\   }
end_define

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

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.  */
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
value|do {							\   X = arm_legitimize_address (X, OLDX, MODE);		\ } while (0)
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
value|do {							\   X = thumb_legitimize_address (X, OLDX, MODE);		\ } while (0)
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
value|do {							\   if (TARGET_ARM)					\     ARM_LEGITIMIZE_ADDRESS (X, OLDX, MODE, WIN);	\   else							\     THUMB_LEGITIMIZE_ADDRESS (X, OLDX, MODE, WIN);	\ 							\   if (memory_address_p (MODE, X))			\     goto WIN;						\ } while (0)
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
value|(arm_tune_xscale ? 4 : 2)
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
comment|/* Define if loading in MODE, an integral mode narrower than BITS_PER_WORD    will either zero-extend or sign-extend.  The value of this macro should    be the code that says which one of the two operations is implicitly    done, UNKNOWN if none.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_EXTEND_OP
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_THUMB ? ZERO_EXTEND :						\    ((arm_arch4 || (MODE) == QImode) ? ZERO_EXTEND			\     : ((BYTES_BIG_ENDIAN&& (MODE) == HImode) ? SIGN_EXTEND : UNKNOWN)))
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
comment|/* This is all wrong.  Defining SHIFT_COUNT_TRUNCATED tells combine that    code like (X<< (Y % 32)) for register X, Y is equivalent to (X<< Y).    On the arm, Y in a register is used modulo 256 for the shift. Only for    rotates is modulo 32 used.  */
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
name|unsigned
name|arm_pic_register
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

begin_comment
comment|/* We can't directly access anything that contains a symbol,    nor can we indirect via the constant pool.  One exception is    UNSPEC_TLS, which is always PIC.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(!(symbol_mentioned_p (X)					\ 	   || label_mentioned_p (X)					\ 	   || (GET_CODE (X) == SYMBOL_REF				\&& CONSTANT_POOL_ADDRESS_P (X)				\&& (symbol_mentioned_p (get_pool_constant (X))		\ 		   || label_mentioned_p (get_pool_constant (X)))))	\ 	 || tls_mentioned_p (X))
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
parameter_list|()
value|do {					\   c_register_pragma (0, "long_calls", arm_pr_long_calls);		\   c_register_pragma (0, "no_long_calls", arm_pr_no_long_calls);		\   c_register_pragma (0, "long_calls_off", arm_pr_long_calls_off);	\ } while (0)
end_define

begin_comment
comment|/* Condition code information.  */
end_comment

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.  */
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
value|arm_select_cc_mode (OP, X, Y)
end_define

begin_define
define|#
directive|define
name|REVERSIBLE_CC_MODE
parameter_list|(
name|MODE
parameter_list|)
value|1
end_define

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
value|(((MODE) == CCFPmode || (MODE) == CCFPEmode) \    ? reverse_condition_maybe_unordered (code) \    : reverse_condition (code))
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
value|do									\     {									\       if (GET_CODE (OP1) == CONST_INT					\&& ! (const_ok_for_arm (INTVAL (OP1))				\ 	        || (const_ok_for_arm (- INTVAL (OP1)))))		\         {								\           rtx const_op = OP1;						\           CODE = arm_canonicalize_comparison ((CODE), GET_MODE (OP0),	\&const_op);		\           OP1 = const_op;						\         }								\     }									\   while (0)
end_define

begin_comment
comment|/* The arm5 clz instruction returns 32.  */
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
value|((VALUE) = 32, 1)
end_define

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|(TARGET_THUMB ? "\t.code\t16\n" : "")
end_define

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
value|do							\     {							\       if (TARGET_ARM)					\ 	asm_fprintf (STREAM,"\tstmfd\t%r!,{%r}\n",	\ 		     STACK_POINTER_REGNUM, REGNO);	\       else						\ 	asm_fprintf (STREAM, "\tpush {%r}\n", REGNO);	\     } while (0)
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
value|do							\     {							\       if (TARGET_ARM)					\ 	asm_fprintf (STREAM, "\tldmfd\t%r!,{%r}\n",	\ 		     STACK_POINTER_REGNUM, REGNO);	\       else						\ 	asm_fprintf (STREAM, "\tpop {%r}\n", REGNO);	\     } while (0)
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
value|do								\     {								\       if (TARGET_THUMB)						\         ASM_OUTPUT_ALIGN (FILE, 2);				\       (*targetm.asm_out.internal_label) (FILE, PREFIX, NUM);	\     }								\   while (0)
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
value|do							\     {							\       if (TARGET_THUMB) 				\         {						\           if (is_called_in_ARM_mode (DECL)      \ 			  || current_function_is_thunk)		\             fprintf (STREAM, "\t.code 32\n") ;		\           else						\            fprintf (STREAM, "\t.code 16\n\t.thumb_func\n") ;	\         }						\       if (TARGET_POKE_FUNCTION_NAME)			\         arm_poke_function_name (STREAM, (char *) NAME);	\     }							\   while (0)
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
value|if ((LOG) != 0)						\     {								\       if ((MAX_SKIP) == 0)					\         fprintf ((FILE), "\t.p2align %d\n", (int) (LOG));	\       else							\         fprintf ((FILE), "\t.p2align %d,,%d\n",			\                  (int) (LOG), (int) (MAX_SKIP));		\     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Only perform branch elimination (by making instructions conditional) if    we're optimizing.  Otherwise it's of no use anyway.  */
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
value|{									\     int is_minus = GET_CODE (X) == MINUS;				\ 									\     if (GET_CODE (X) == REG)						\       asm_fprintf (STREAM, "[%r, #0]", REGNO (X));			\     else if (GET_CODE (X) == PLUS || is_minus)				\       {									\ 	rtx base = XEXP (X, 0);						\ 	rtx index = XEXP (X, 1);					\ 	HOST_WIDE_INT offset = 0;					\ 	if (GET_CODE (base) != REG)					\ 	  {								\
comment|/* Ensure that BASE is a register.  */
value|\
comment|/* (one of them must be).  */
value|\ 	    rtx temp = base;						\ 	    base = index;						\ 	    index = temp;						\ 	  }								\ 	switch (GET_CODE (index))					\ 	  {								\ 	  case CONST_INT:						\ 	    offset = INTVAL (index);					\ 	    if (is_minus)						\ 	      offset = -offset;						\ 	    asm_fprintf (STREAM, "[%r, #%wd]",				\ 		         REGNO (base), offset);				\ 	    break;							\ 									\ 	  case REG:							\ 	    asm_fprintf (STREAM, "[%r, %s%r]",				\ 		     REGNO (base), is_minus ? "-" : "",			\ 		     REGNO (index));					\ 	    break;							\ 									\ 	  case MULT:							\ 	  case ASHIFTRT:						\ 	  case LSHIFTRT:						\ 	  case ASHIFT:							\ 	  case ROTATERT:						\ 	  {								\ 	    asm_fprintf (STREAM, "[%r, %s%r",				\ 		         REGNO (base), is_minus ? "-" : "",		\                          REGNO (XEXP (index, 0)));			\ 	    arm_print_operand (STREAM, index, 'S');			\ 	    fputs ("]", STREAM);					\ 	    break;							\ 	  }								\ 									\ 	  default:							\ 	    gcc_unreachable ();						\ 	}								\     }									\   else if (GET_CODE (X) == PRE_INC || GET_CODE (X) == POST_INC		\ 	   || GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_DEC)	\     {									\       extern enum machine_mode output_memory_reference_mode;		\ 									\       gcc_assert (GET_CODE (XEXP (X, 0)) == REG);			\ 									\       if (GET_CODE (X) == PRE_DEC || GET_CODE (X) == PRE_INC)		\ 	asm_fprintf (STREAM, "[%r, #%s%d]!",				\ 		     REGNO (XEXP (X, 0)),				\ 		     GET_CODE (X) == PRE_DEC ? "-" : "",		\ 		     GET_MODE_SIZE (output_memory_reference_mode));	\       else								\ 	asm_fprintf (STREAM, "[%r], #%s%d",				\ 		     REGNO (XEXP (X, 0)),				\ 		     GET_CODE (X) == POST_DEC ? "-" : "",		\ 		     GET_MODE_SIZE (output_memory_reference_mode));	\     }									\   else if (GET_CODE (X) == PRE_MODIFY)					\     {									\       asm_fprintf (STREAM, "[%r, ", REGNO (XEXP (X, 0)));		\       if (GET_CODE (XEXP (XEXP (X, 1), 1)) == CONST_INT)		\ 	asm_fprintf (STREAM, "#%wd]!", 					\ 		     INTVAL (XEXP (XEXP (X, 1), 1)));			\       else								\ 	asm_fprintf (STREAM, "%r]!", 					\ 		     REGNO (XEXP (XEXP (X, 1), 1)));			\     }									\   else if (GET_CODE (X) == POST_MODIFY)					\     {									\       asm_fprintf (STREAM, "[%r], ", REGNO (XEXP (X, 0)));		\       if (GET_CODE (XEXP (XEXP (X, 1), 1)) == CONST_INT)		\ 	asm_fprintf (STREAM, "#%wd", 					\ 		     INTVAL (XEXP (XEXP (X, 1), 1)));			\       else								\ 	asm_fprintf (STREAM, "%r", 					\ 		     REGNO (XEXP (XEXP (X, 1), 1)));			\     }									\   else output_addr_const (STREAM, X);					\ }
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
value|{							\   if (GET_CODE (X) == REG)				\     asm_fprintf (STREAM, "[%r]", REGNO (X));		\   else if (GET_CODE (X) == POST_INC)			\     asm_fprintf (STREAM, "%r!", REGNO (XEXP (X, 0)));	\   else if (GET_CODE (X) == PLUS)			\     {							\       gcc_assert (GET_CODE (XEXP (X, 0)) == REG);	\       if (GET_CODE (XEXP (X, 1)) == CONST_INT)		\ 	asm_fprintf (STREAM, "[%r, #%wd]", 		\ 		     REGNO (XEXP (X, 0)),		\ 		     INTVAL (XEXP (X, 1)));		\       else						\ 	asm_fprintf (STREAM, "[%r, %r]",		\ 		     REGNO (XEXP (X, 0)),		\ 		     REGNO (XEXP (X, 1)));		\     }							\   else							\     output_addr_const (STREAM, X);			\ }
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

begin_define
define|#
directive|define
name|OUTPUT_ADDR_CONST_EXTRA
parameter_list|(
name|file
parameter_list|,
name|x
parameter_list|,
name|fail
parameter_list|)
define|\
value|if (arm_output_addr_const_extra (file, x) == FALSE)	\     goto fail
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
comment|/* Mask of the bits in the PC that contain the real return address    when running in 26-bit mode.  */
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
value|((arm_arch4 || TARGET_THUMB)						\    ? (gen_int_mode ((unsigned long)0xffffffff, Pmode))			\    : arm_gen_return_addr_mask ())
end_define

begin_escape
end_escape

begin_enum
enum|enum
name|arm_builtins
block|{
name|ARM_BUILTIN_GETWCX
block|,
name|ARM_BUILTIN_SETWCX
block|,
name|ARM_BUILTIN_WZERO
block|,
name|ARM_BUILTIN_WAVG2BR
block|,
name|ARM_BUILTIN_WAVG2HR
block|,
name|ARM_BUILTIN_WAVG2B
block|,
name|ARM_BUILTIN_WAVG2H
block|,
name|ARM_BUILTIN_WACCB
block|,
name|ARM_BUILTIN_WACCH
block|,
name|ARM_BUILTIN_WACCW
block|,
name|ARM_BUILTIN_WMACS
block|,
name|ARM_BUILTIN_WMACSZ
block|,
name|ARM_BUILTIN_WMACU
block|,
name|ARM_BUILTIN_WMACUZ
block|,
name|ARM_BUILTIN_WSADB
block|,
name|ARM_BUILTIN_WSADBZ
block|,
name|ARM_BUILTIN_WSADH
block|,
name|ARM_BUILTIN_WSADHZ
block|,
name|ARM_BUILTIN_WALIGN
block|,
name|ARM_BUILTIN_TMIA
block|,
name|ARM_BUILTIN_TMIAPH
block|,
name|ARM_BUILTIN_TMIABB
block|,
name|ARM_BUILTIN_TMIABT
block|,
name|ARM_BUILTIN_TMIATB
block|,
name|ARM_BUILTIN_TMIATT
block|,
name|ARM_BUILTIN_TMOVMSKB
block|,
name|ARM_BUILTIN_TMOVMSKH
block|,
name|ARM_BUILTIN_TMOVMSKW
block|,
name|ARM_BUILTIN_TBCSTB
block|,
name|ARM_BUILTIN_TBCSTH
block|,
name|ARM_BUILTIN_TBCSTW
block|,
name|ARM_BUILTIN_WMADDS
block|,
name|ARM_BUILTIN_WMADDU
block|,
name|ARM_BUILTIN_WPACKHSS
block|,
name|ARM_BUILTIN_WPACKWSS
block|,
name|ARM_BUILTIN_WPACKDSS
block|,
name|ARM_BUILTIN_WPACKHUS
block|,
name|ARM_BUILTIN_WPACKWUS
block|,
name|ARM_BUILTIN_WPACKDUS
block|,
name|ARM_BUILTIN_WADDB
block|,
name|ARM_BUILTIN_WADDH
block|,
name|ARM_BUILTIN_WADDW
block|,
name|ARM_BUILTIN_WADDSSB
block|,
name|ARM_BUILTIN_WADDSSH
block|,
name|ARM_BUILTIN_WADDSSW
block|,
name|ARM_BUILTIN_WADDUSB
block|,
name|ARM_BUILTIN_WADDUSH
block|,
name|ARM_BUILTIN_WADDUSW
block|,
name|ARM_BUILTIN_WSUBB
block|,
name|ARM_BUILTIN_WSUBH
block|,
name|ARM_BUILTIN_WSUBW
block|,
name|ARM_BUILTIN_WSUBSSB
block|,
name|ARM_BUILTIN_WSUBSSH
block|,
name|ARM_BUILTIN_WSUBSSW
block|,
name|ARM_BUILTIN_WSUBUSB
block|,
name|ARM_BUILTIN_WSUBUSH
block|,
name|ARM_BUILTIN_WSUBUSW
block|,
name|ARM_BUILTIN_WAND
block|,
name|ARM_BUILTIN_WANDN
block|,
name|ARM_BUILTIN_WOR
block|,
name|ARM_BUILTIN_WXOR
block|,
name|ARM_BUILTIN_WCMPEQB
block|,
name|ARM_BUILTIN_WCMPEQH
block|,
name|ARM_BUILTIN_WCMPEQW
block|,
name|ARM_BUILTIN_WCMPGTUB
block|,
name|ARM_BUILTIN_WCMPGTUH
block|,
name|ARM_BUILTIN_WCMPGTUW
block|,
name|ARM_BUILTIN_WCMPGTSB
block|,
name|ARM_BUILTIN_WCMPGTSH
block|,
name|ARM_BUILTIN_WCMPGTSW
block|,
name|ARM_BUILTIN_TEXTRMSB
block|,
name|ARM_BUILTIN_TEXTRMSH
block|,
name|ARM_BUILTIN_TEXTRMSW
block|,
name|ARM_BUILTIN_TEXTRMUB
block|,
name|ARM_BUILTIN_TEXTRMUH
block|,
name|ARM_BUILTIN_TEXTRMUW
block|,
name|ARM_BUILTIN_TINSRB
block|,
name|ARM_BUILTIN_TINSRH
block|,
name|ARM_BUILTIN_TINSRW
block|,
name|ARM_BUILTIN_WMAXSW
block|,
name|ARM_BUILTIN_WMAXSH
block|,
name|ARM_BUILTIN_WMAXSB
block|,
name|ARM_BUILTIN_WMAXUW
block|,
name|ARM_BUILTIN_WMAXUH
block|,
name|ARM_BUILTIN_WMAXUB
block|,
name|ARM_BUILTIN_WMINSW
block|,
name|ARM_BUILTIN_WMINSH
block|,
name|ARM_BUILTIN_WMINSB
block|,
name|ARM_BUILTIN_WMINUW
block|,
name|ARM_BUILTIN_WMINUH
block|,
name|ARM_BUILTIN_WMINUB
block|,
name|ARM_BUILTIN_WMULUM
block|,
name|ARM_BUILTIN_WMULSM
block|,
name|ARM_BUILTIN_WMULUL
block|,
name|ARM_BUILTIN_PSADBH
block|,
name|ARM_BUILTIN_WSHUFH
block|,
name|ARM_BUILTIN_WSLLH
block|,
name|ARM_BUILTIN_WSLLW
block|,
name|ARM_BUILTIN_WSLLD
block|,
name|ARM_BUILTIN_WSRAH
block|,
name|ARM_BUILTIN_WSRAW
block|,
name|ARM_BUILTIN_WSRAD
block|,
name|ARM_BUILTIN_WSRLH
block|,
name|ARM_BUILTIN_WSRLW
block|,
name|ARM_BUILTIN_WSRLD
block|,
name|ARM_BUILTIN_WRORH
block|,
name|ARM_BUILTIN_WRORW
block|,
name|ARM_BUILTIN_WRORD
block|,
name|ARM_BUILTIN_WSLLHI
block|,
name|ARM_BUILTIN_WSLLWI
block|,
name|ARM_BUILTIN_WSLLDI
block|,
name|ARM_BUILTIN_WSRAHI
block|,
name|ARM_BUILTIN_WSRAWI
block|,
name|ARM_BUILTIN_WSRADI
block|,
name|ARM_BUILTIN_WSRLHI
block|,
name|ARM_BUILTIN_WSRLWI
block|,
name|ARM_BUILTIN_WSRLDI
block|,
name|ARM_BUILTIN_WRORHI
block|,
name|ARM_BUILTIN_WRORWI
block|,
name|ARM_BUILTIN_WRORDI
block|,
name|ARM_BUILTIN_WUNPCKIHB
block|,
name|ARM_BUILTIN_WUNPCKIHH
block|,
name|ARM_BUILTIN_WUNPCKIHW
block|,
name|ARM_BUILTIN_WUNPCKILB
block|,
name|ARM_BUILTIN_WUNPCKILH
block|,
name|ARM_BUILTIN_WUNPCKILW
block|,
name|ARM_BUILTIN_WUNPCKEHSB
block|,
name|ARM_BUILTIN_WUNPCKEHSH
block|,
name|ARM_BUILTIN_WUNPCKEHSW
block|,
name|ARM_BUILTIN_WUNPCKEHUB
block|,
name|ARM_BUILTIN_WUNPCKEHUH
block|,
name|ARM_BUILTIN_WUNPCKEHUW
block|,
name|ARM_BUILTIN_WUNPCKELSB
block|,
name|ARM_BUILTIN_WUNPCKELSH
block|,
name|ARM_BUILTIN_WUNPCKELSW
block|,
name|ARM_BUILTIN_WUNPCKELUB
block|,
name|ARM_BUILTIN_WUNPCKELUH
block|,
name|ARM_BUILTIN_WUNPCKELUW
block|,
name|ARM_BUILTIN_THREAD_POINTER
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

