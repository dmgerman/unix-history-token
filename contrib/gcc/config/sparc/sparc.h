begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for Sun SPARC.    Copyright (C) 1987, 1988, 1989, 1992, 1994, 1995, 1996, 1997, 1998, 1999    2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@cygnus.com).    64 bit SPARC V9 support by Michael Tiemann, Jim Wilson, and Doug Evans,    at Cygnus Support.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm.h files include this one and then override    whatever definitions are necessary.  */
end_comment

begin_comment
comment|/* Specify this in a cover file to provide bi-architecture (32/64) support.  */
end_comment

begin_comment
comment|/* #define SPARC_BI_ARCH */
end_comment

begin_comment
comment|/* Macro used later in this file to determine default architecture.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ARCH32_P
value|((TARGET_DEFAULT& MASK_64BIT) == 0)
end_define

begin_comment
comment|/* TARGET_ARCH{32,64} are the main macros to decide which of the two    architectures to compile for.  We allow targets to choose compile time or    runtime selection.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparcv9
argument_list|)
operator|||
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_ARCH32
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ARCH32
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc64 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_define
define|#
directive|define
name|TARGET_ARCH32
value|(! TARGET_64BIT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ARCH32
value|(DEFAULT_ARCH32_P)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPARC_BI_ARCH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_LIBGCC2 */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH64
value|(! TARGET_ARCH32)
end_define

begin_comment
comment|/* Code model selection.    -mcmodel is used to select the v9 code model.    Different code models aren't supported for v7/8 code.     TARGET_CM_32:     32 bit address space, top 32 bits = 0, 		     pointers are 32 bits.  Note that this isn't intended                      to imply a v7/8 abi.     TARGET_CM_MEDLOW: 32 bit address space, top 32 bits = 0,                      avoid generating %uhi and %ulo terms, 		     pointers are 64 bits.     TARGET_CM_MEDMID: 64 bit address space.                      The executable must be in the low 16 TB of memory.                      This corresponds to the low 44 bits, and the %[hml]44                      relocs are used.  The text segment has a maximum size                      of 31 bits.     TARGET_CM_MEDANY: 64 bit address space.                      The text and data segments have a maximum size of 31                      bits and may be located anywhere.  The maximum offset                      from any instruction to the label _GLOBAL_OFFSET_TABLE_                      is 31 bits.     TARGET_CM_EMBMEDANY: 64 bit address space.                      The text and data segments have a maximum size of 31 bits                      and may be located anywhere.  Register %g4 contains                      the start address of the data segment. */
end_comment

begin_enum
enum|enum
name|cmodel
block|{
name|CM_32
block|,
name|CM_MEDLOW
block|,
name|CM_MEDMID
block|,
name|CM_MEDANY
block|,
name|CM_EMBMEDANY
block|}
enum|;
end_enum

begin_comment
comment|/* Value of -mcmodel specified by user.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sparc_cmodel_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One of CM_FOO.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|cmodel
name|sparc_cmodel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* V9 code model selection.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CM_MEDLOW
value|(sparc_cmodel == CM_MEDLOW)
end_define

begin_define
define|#
directive|define
name|TARGET_CM_MEDMID
value|(sparc_cmodel == CM_MEDMID)
end_define

begin_define
define|#
directive|define
name|TARGET_CM_MEDANY
value|(sparc_cmodel == CM_MEDANY)
end_define

begin_define
define|#
directive|define
name|TARGET_CM_EMBMEDANY
value|(sparc_cmodel == CM_EMBMEDANY)
end_define

begin_define
define|#
directive|define
name|SPARC_DEFAULT_CMODEL
value|CM_32
end_define

begin_comment
comment|/* This is call-clobbered in the normal ABI, but is reserved in the    home grown (aka upward compatible) embedded ABI.  */
end_comment

begin_define
define|#
directive|define
name|EMBMEDANY_BASE_REG
value|"%g4"
end_define

begin_escape
end_escape

begin_comment
comment|/* Values of TARGET_CPU_DEFAULT, set via -D in the Makefile,    and specified by the user via --with-cpu=foo.    This specifies the cpu implementation, not the architecture size.  */
end_comment

begin_comment
comment|/* Note that TARGET_CPU_v9 is assumed to start the list of 64-bit     capable cpu's.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_sparc
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_v7
value|0
end_define

begin_comment
comment|/* alias for previous */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_sparclet
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_sparclite
value|2
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_v8
value|3
end_define

begin_comment
comment|/* generic v8 implementation */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_supersparc
value|4
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_hypersparc
value|5
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_sparc86x
value|6
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_sparclite86x
value|6
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_v9
value|7
end_define

begin_comment
comment|/* generic v9 implementation */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_sparcv9
value|7
end_define

begin_comment
comment|/* alias */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_sparc64
value|7
end_define

begin_comment
comment|/* alias */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_ultrasparc
value|8
end_define

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
expr|\
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_define
define|#
directive|define
name|CPP_CPU32_DEFAULT_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|""
end_define

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
end_if

begin_comment
comment|/* ??? What does Sun's CC pass?  */
end_comment

begin_define
define|#
directive|define
name|CPP_CPU64_DEFAULT_SPEC
value|"-D__sparc_v9__"
end_define

begin_comment
comment|/* ??? It's not clear how other assemblers will handle this, so by default    use GAS.  Sun's Solaris assembler recognizes -xarch=v8plus, but this case    is handled in sol2.h.  */
end_comment

begin_define
define|#
directive|define
name|ASM_CPU64_DEFAULT_SPEC
value|"-Av9"
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
name|TARGET_CPU_ultrasparc
end_if

begin_define
define|#
directive|define
name|CPP_CPU64_DEFAULT_SPEC
value|"-D__sparc_v9__"
end_define

begin_define
define|#
directive|define
name|ASM_CPU64_DEFAULT_SPEC
value|"-Av9a"
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
name|CPP_CPU64_DEFAULT_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|ASM_CPU64_DEFAULT_SPEC
value|""
end_define

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_sparc
expr|\
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v8
end_if

begin_define
define|#
directive|define
name|CPP_CPU32_DEFAULT_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|""
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
name|TARGET_CPU_sparclet
end_if

begin_define
define|#
directive|define
name|CPP_CPU32_DEFAULT_SPEC
value|"-D__sparclet__"
end_define

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|"-Asparclet"
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
name|TARGET_CPU_sparclite
end_if

begin_define
define|#
directive|define
name|CPP_CPU32_DEFAULT_SPEC
value|"-D__sparclite__"
end_define

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|"-Asparclite"
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
name|TARGET_CPU_supersparc
end_if

begin_define
define|#
directive|define
name|CPP_CPU32_DEFAULT_SPEC
value|"-D__supersparc__ -D__sparc_v8__"
end_define

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|""
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
name|TARGET_CPU_hypersparc
end_if

begin_define
define|#
directive|define
name|CPP_CPU32_DEFAULT_SPEC
value|"-D__hypersparc__ -D__sparc_v8__"
end_define

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|""
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
name|TARGET_CPU_sparclite86x
end_if

begin_define
define|#
directive|define
name|CPP_CPU32_DEFAULT_SPEC
value|"-D__sparclite86x__"
end_define

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|"-Asparclite"
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
operator|!
name|defined
argument_list|(
name|CPP_CPU32_DEFAULT_SPEC
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|CPP_CPU64_DEFAULT_SPEC
argument_list|)
end_if

begin_expr_stmt
name|Unrecognized
name|value
name|in
name|TARGET_CPU_DEFAULT
operator|.
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? "\ %{m64:" CPP_CPU64_DEFAULT_SPEC "} \ %{!m64:" CPP_CPU32_DEFAULT_SPEC "} \ " : "\ %{m32:" CPP_CPU32_DEFAULT_SPEC "} \ %{!m32:" CPP_CPU64_DEFAULT_SPEC "} \ ")
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? "\ %{m64:" ASM_CPU64_DEFAULT_SPEC "} \ %{!m64:" ASM_CPU32_DEFAULT_SPEC "} \ " : "\ %{m32:" ASM_CPU32_DEFAULT_SPEC "} \ %{!m32:" ASM_CPU64_DEFAULT_SPEC "} \ ")
else|#
directive|else
comment|/* !SPARC_BI_ARCH */
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
value|(DEFAULT_ARCH32_P ? CPP_CPU32_DEFAULT_SPEC : CPP_CPU64_DEFAULT_SPEC)
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
value|(DEFAULT_ARCH32_P ? ASM_CPU32_DEFAULT_SPEC : ASM_CPU64_DEFAULT_SPEC)
endif|#
directive|endif
comment|/* !SPARC_BI_ARCH */
comment|/* Define macros to distinguish architectures.  */
comment|/* Common CPP definitions used by CPP_SPEC amongst the various targets    for handling -mcpu=xxx switches.  */
define|#
directive|define
name|CPP_CPU_SPEC
value|"\ %{msoft-float:-D_SOFT_FLOAT} \ %{mcypress:} \ %{msparclite:-D__sparclite__} \ %{mf930:-D__sparclite__} %{mf934:-D__sparclite__} \ %{mv8:-D__sparc_v8__} \ %{msupersparc:-D__supersparc__ -D__sparc_v8__} \ %{mcpu=sparclet:-D__sparclet__} %{mcpu=tsc701:-D__sparclet__} \ %{mcpu=sparclite:-D__sparclite__} \ %{mcpu=f930:-D__sparclite__} %{mcpu=f934:-D__sparclite__} \ %{mcpu=v8:-D__sparc_v8__} \ %{mcpu=supersparc:-D__supersparc__ -D__sparc_v8__} \ %{mcpu=hypersparc:-D__hypersparc__ -D__sparc_v8__} \ %{mcpu=sparclite86x:-D__sparclite86x__} \ %{mcpu=v9:-D__sparc_v9__} \ %{mcpu=ultrasparc:-D__sparc_v9__} \ %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:%(cpp_cpu_default)}}}}}}} \ "
comment|/* ??? The GCC_NEW_VARARGS macro is now obsolete, because gcc always uses    the right varags.h file when bootstrapping.  */
comment|/* ??? It's not clear what value we want to use for -Acpu/machine for    sparc64 in 32 bit environments, so for now we only use `sparc64' in    64 bit environments.  */
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
define|#
directive|define
name|CPP_ARCH32_SPEC
value|"-D__SIZE_TYPE__=unsigned\\ int -D__PTRDIFF_TYPE__=int \ -D__GCC_NEW_VARARGS__ -Acpu=sparc -Amachine=sparc"
define|#
directive|define
name|CPP_ARCH64_SPEC
value|"-D__SIZE_TYPE__=long\\ unsigned\\ int -D__PTRDIFF_TYPE__=long\\ int \ -D__arch64__ -Acpu=sparc64 -Amachine=sparc64"
else|#
directive|else
define|#
directive|define
name|CPP_ARCH32_SPEC
value|"-D__GCC_NEW_VARARGS__ -Acpu=sparc -Amachine=sparc"
define|#
directive|define
name|CPP_ARCH64_SPEC
value|"-D__arch64__ -Acpu=sparc64 -Amachine=sparc64"
endif|#
directive|endif
define|#
directive|define
name|CPP_ARCH_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? CPP_ARCH32_SPEC : CPP_ARCH64_SPEC)
define|#
directive|define
name|CPP_ARCH_SPEC
value|"\ %{m32:%(cpp_arch32)} \ %{m64:%(cpp_arch64)} \ %{!m32:%{!m64:%(cpp_arch_default)}} \ "
comment|/* Macros to distinguish endianness.  */
define|#
directive|define
name|CPP_ENDIAN_SPEC
value|"\ %{mlittle-endian:-D__LITTLE_ENDIAN__} \ %{mlittle-endian-data:-D__LITTLE_ENDIAN_DATA__}"
comment|/* Macros to distinguish the particular subtarget.  */
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|""
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %(cpp_arch) %(cpp_endian) %(cpp_subtarget)"
comment|/* Prevent error on `-sun4' and `-target sun4' options.  */
comment|/* This used to translate -dalign to -malign, but that is no good    because it can't turn off the usual meaning of making debugging dumps.  */
comment|/* Translate old style -m<cpu> into new style -mcpu=<cpu>.    ??? Delete support for -m<cpu> for 2.9.  */
define|#
directive|define
name|CC1_SPEC
value|"\ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ "
comment|/* Override in target specific files.  */
define|#
directive|define
name|ASM_CPU_SPEC
value|"\ %{mcpu=sparclet:-Asparclet} %{mcpu=tsc701:-Asparclet} \ %{msparclite:-Asparclite} \ %{mf930:-Asparclite} %{mf934:-Asparclite} \ %{mcpu=sparclite:-Asparclite} \ %{mcpu=sparclite86x:-Asparclite} \ %{mcpu=f930:-Asparclite} %{mcpu=f934:-Asparclite} \ %{mv8plus:-Av8plus} \ %{mcpu=v9:-Av9} \ %{mcpu=ultrasparc:%{!mv8plus:-Av9a}} \ %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:%(asm_cpu_default)}}}}}}} \ "
comment|/* Word size selection, among other things.    This is what GAS uses.  Add %(asm_arch) to ASM_SPEC to enable.  */
define|#
directive|define
name|ASM_ARCH32_SPEC
value|"-32"
ifdef|#
directive|ifdef
name|HAVE_AS_REGISTER_PSEUDO_OP
define|#
directive|define
name|ASM_ARCH64_SPEC
value|"-64 -no-undeclared-regs"
else|#
directive|else
define|#
directive|define
name|ASM_ARCH64_SPEC
value|"-64"
endif|#
directive|endif
define|#
directive|define
name|ASM_ARCH_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? ASM_ARCH32_SPEC : ASM_ARCH64_SPEC)
define|#
directive|define
name|ASM_ARCH_SPEC
value|"\ %{m32:%(asm_arch32)} \ %{m64:%(asm_arch64)} \ %{!m32:%{!m64:%(asm_arch_default)}} \ "
ifdef|#
directive|ifdef
name|HAVE_AS_RELAX_OPTION
define|#
directive|define
name|ASM_RELAX_SPEC
value|"%{!mno-relax:-relax}"
else|#
directive|else
define|#
directive|define
name|ASM_RELAX_SPEC
value|""
endif|#
directive|endif
comment|/* Special flags to the Sun-4 assembler when using pipe for input.  */
define|#
directive|define
name|ASM_SPEC
value|"\ %| %{R} %{!pg:%{!p:%{fpic:-k} %{fPIC:-k}}} %{keep-local-as-symbols:-L} \ %(asm_cpu) %(asm_relax)"
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GNU CC driver    program.     Do not define this macro if it does not need to do anything.  */
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "cpp_cpu",		CPP_CPU_SPEC },		\   { "cpp_cpu_default",	CPP_CPU_DEFAULT_SPEC },	\   { "cpp_arch32",	CPP_ARCH32_SPEC },	\   { "cpp_arch64",	CPP_ARCH64_SPEC },	\   { "cpp_arch_default",	CPP_ARCH_DEFAULT_SPEC },\   { "cpp_arch",		CPP_ARCH_SPEC },	\   { "cpp_endian",	CPP_ENDIAN_SPEC },	\   { "cpp_subtarget",	CPP_SUBTARGET_SPEC },	\   { "asm_cpu",		ASM_CPU_SPEC },		\   { "asm_cpu_default",	ASM_CPU_DEFAULT_SPEC },	\   { "asm_arch32",	ASM_ARCH32_SPEC },	\   { "asm_arch64",	ASM_ARCH64_SPEC },	\   { "asm_relax",	ASM_RELAX_SPEC },	\   { "asm_arch_default",	ASM_ARCH_DEFAULT_SPEC },\   { "asm_arch",		ASM_ARCH_SPEC },	\   SUBTARGET_EXTRA_SPECS
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
define|#
directive|define
name|NO_BUILTIN_PTRDIFF_TYPE
define|#
directive|define
name|NO_BUILTIN_SIZE_TYPE
endif|#
directive|endif
define|#
directive|define
name|PTRDIFF_TYPE
value|(TARGET_ARCH64 ? "long int" : "int")
define|#
directive|define
name|SIZE_TYPE
value|(TARGET_ARCH64 ? "long unsigned int" : "unsigned int")
comment|/* ??? This should be 32 bits for v9 but what can we do?  */
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
define|#
directive|define
name|MAX_WCHAR_TYPE_SIZE
value|16
comment|/* Show we can debug even without a frame pointer.  */
define|#
directive|define
name|CAN_DEBUG_WITHOUT_FP
comment|/* To make profiling work with -f{pic,PIC}, we need to emit the profiling    code into the rtl.  Also, if we are profiling, we cannot eliminate    the frame pointer (because the return address will get smashed).  */
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|do {									\     if (profile_flag || profile_arc_flag)				\       {									\ 	if (flag_pic)							\ 	  {								\ 	    const char *const pic_string = (flag_pic == 1) ? "-fpic" : "-fPIC";\ 	    warning ("%s and profiling conflict: disabling %s",		\ 		     pic_string, pic_string);				\ 	    flag_pic = 0;						\ 	  }								\ 	flag_omit_frame_pointer = 0;					\       }									\     sparc_override_options ();						\     SUBTARGET_OVERRIDE_OPTIONS;						\   } while (0)
comment|/* This is meant to be redefined in the host dependent files.  */
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
comment|/* Generate DBX debugging information.  */
define|#
directive|define
name|DBX_DEBUGGING_INFO
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
expr|extern
name|int
name|target_flags
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero if we should generate code to use the fpu.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FPU
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_FPU
value|(target_flags& MASK_FPU)
end_define

begin_comment
comment|/* Nonzero if we should use function_epilogue().  Otherwise, we    use fast return insns, but lose some generality.  */
end_comment

begin_define
define|#
directive|define
name|MASK_EPILOGUE
value|2
end_define

begin_define
define|#
directive|define
name|TARGET_EPILOGUE
value|(target_flags& MASK_EPILOGUE)
end_define

begin_comment
comment|/* Nonzero if we should assume that double pointers might be unaligned.    This can happen when linking gcc compiled code with other compilers,    because the ABI only guarantees 4 byte alignment.  */
end_comment

begin_define
define|#
directive|define
name|MASK_UNALIGNED_DOUBLES
value|4
end_define

begin_define
define|#
directive|define
name|TARGET_UNALIGNED_DOUBLES
value|(target_flags& MASK_UNALIGNED_DOUBLES)
end_define

begin_comment
comment|/* Nonzero means that we should generate code for a v8 sparc.  */
end_comment

begin_define
define|#
directive|define
name|MASK_V8
value|0x8
end_define

begin_define
define|#
directive|define
name|TARGET_V8
value|(target_flags& MASK_V8)
end_define

begin_comment
comment|/* Nonzero means that we should generate code for a sparclite.    This enables the sparclite specific instructions, but does not affect    whether FPU instructions are emitted.  */
end_comment

begin_define
define|#
directive|define
name|MASK_SPARCLITE
value|0x10
end_define

begin_define
define|#
directive|define
name|TARGET_SPARCLITE
value|(target_flags& MASK_SPARCLITE)
end_define

begin_comment
comment|/* Nonzero if we're compiling for the sparclet.  */
end_comment

begin_define
define|#
directive|define
name|MASK_SPARCLET
value|0x20
end_define

begin_define
define|#
directive|define
name|TARGET_SPARCLET
value|(target_flags& MASK_SPARCLET)
end_define

begin_comment
comment|/* Nonzero if we're compiling for v9 sparc.    Note that v9's can run in 32 bit mode so this doesn't necessarily mean    the word size is 64.  */
end_comment

begin_define
define|#
directive|define
name|MASK_V9
value|0x40
end_define

begin_define
define|#
directive|define
name|TARGET_V9
value|(target_flags& MASK_V9)
end_define

begin_comment
comment|/* Non-zero to generate code that uses the instructions deprecated in    the v9 architecture.  This option only applies to v9 systems.  */
end_comment

begin_comment
comment|/* ??? This isn't user selectable yet.  It's used to enable such insns    on 32 bit v9 systems and for the moment they're permanently disabled    on 64 bit v9 systems.  */
end_comment

begin_define
define|#
directive|define
name|MASK_DEPRECATED_V8_INSNS
value|0x80
end_define

begin_define
define|#
directive|define
name|TARGET_DEPRECATED_V8_INSNS
value|(target_flags& MASK_DEPRECATED_V8_INSNS)
end_define

begin_comment
comment|/* Mask of all CPU selection flags.  */
end_comment

begin_define
define|#
directive|define
name|MASK_ISA
define|\
value|(MASK_V8 + MASK_SPARCLITE + MASK_SPARCLET + MASK_V9 + MASK_DEPRECATED_V8_INSNS)
end_define

begin_comment
comment|/* Non-zero means don't pass `-assert pure-text' to the linker.  */
end_comment

begin_define
define|#
directive|define
name|MASK_IMPURE_TEXT
value|0x100
end_define

begin_define
define|#
directive|define
name|TARGET_IMPURE_TEXT
value|(target_flags& MASK_IMPURE_TEXT)
end_define

begin_comment
comment|/* Nonzero means that we should generate code using a flat register window    model, i.e. no save/restore instructions are generated, which is    compatible with normal sparc code.    The frame pointer is %i7 instead of %fp.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FLAT
value|0x200
end_define

begin_define
define|#
directive|define
name|TARGET_FLAT
value|(target_flags& MASK_FLAT)
end_define

begin_comment
comment|/* Nonzero means use the registers that the Sparc ABI reserves for    application software.  This must be the default to coincide with the    setting in FIXED_REGISTERS.  */
end_comment

begin_define
define|#
directive|define
name|MASK_APP_REGS
value|0x400
end_define

begin_define
define|#
directive|define
name|TARGET_APP_REGS
value|(target_flags& MASK_APP_REGS)
end_define

begin_comment
comment|/* Option to select how quad word floating point is implemented.    When TARGET_HARD_QUAD is true, we use the hardware quad instructions.    Otherwise, we use the SPARC ABI quad library functions.  */
end_comment

begin_define
define|#
directive|define
name|MASK_HARD_QUAD
value|0x800
end_define

begin_define
define|#
directive|define
name|TARGET_HARD_QUAD
value|(target_flags& MASK_HARD_QUAD)
end_define

begin_comment
comment|/* Non-zero on little-endian machines.  */
end_comment

begin_comment
comment|/* ??? Little endian support currently only exists for sparclet-aout and    sparc64-elf configurations.  May eventually want to expand the support    to all targets, but for now it's kept local to only those two.  */
end_comment

begin_define
define|#
directive|define
name|MASK_LITTLE_ENDIAN
value|0x1000
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_ENDIAN
value|(target_flags& MASK_LITTLE_ENDIAN)
end_define

begin_comment
comment|/* 0x2000, 0x4000 are unused */
end_comment

begin_comment
comment|/* Nonzero if pointers are 64 bits.  */
end_comment

begin_define
define|#
directive|define
name|MASK_PTR64
value|0x8000
end_define

begin_define
define|#
directive|define
name|TARGET_PTR64
value|(target_flags& MASK_PTR64)
end_define

begin_comment
comment|/* Nonzero if generating code to run in a 64 bit environment.    This is intended to only be used by TARGET_ARCH{32,64} as they are the    mechanism used to control compile time or run time selection.  */
end_comment

begin_define
define|#
directive|define
name|MASK_64BIT
value|0x10000
end_define

begin_define
define|#
directive|define
name|TARGET_64BIT
value|(target_flags& MASK_64BIT)
end_define

begin_comment
comment|/* 0x20000,0x40000 unused */
end_comment

begin_comment
comment|/* Non-zero means use a stack bias of 2047.  Stack offsets are obtained by    adding 2047 to %sp.  This option is for v9 only and is the default.  */
end_comment

begin_define
define|#
directive|define
name|MASK_STACK_BIAS
value|0x80000
end_define

begin_define
define|#
directive|define
name|TARGET_STACK_BIAS
value|(target_flags& MASK_STACK_BIAS)
end_define

begin_comment
comment|/* 0x100000,0x200000 unused */
end_comment

begin_comment
comment|/* Non-zero means -m{,no-}fpu was passed on the command line.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FPU_SET
value|0x400000
end_define

begin_define
define|#
directive|define
name|TARGET_FPU_SET
value|(target_flags& MASK_FPU_SET)
end_define

begin_comment
comment|/* Use the UltraSPARC Visual Instruction Set extensions.  */
end_comment

begin_define
define|#
directive|define
name|MASK_VIS
value|0x1000000
end_define

begin_define
define|#
directive|define
name|TARGET_VIS
value|(target_flags& MASK_VIS)
end_define

begin_comment
comment|/* Compile for Solaris V8+.  32 bit Solaris preserves the high bits of    the current out and global registers and Linux 2.2+ as well.  */
end_comment

begin_define
define|#
directive|define
name|MASK_V8PLUS
value|0x2000000
end_define

begin_define
define|#
directive|define
name|TARGET_V8PLUS
value|(target_flags& MASK_V8PLUS)
end_define

begin_comment
comment|/* Force a the fastest alignment on structures to take advantage of    faster copies.  */
end_comment

begin_define
define|#
directive|define
name|MASK_FASTER_STRUCTS
value|0x4000000
end_define

begin_define
define|#
directive|define
name|TARGET_FASTER_STRUCTS
value|(target_flags& MASK_FASTER_STRUCTS)
end_define

begin_comment
comment|/* Use IEEE quad long double.  */
end_comment

begin_define
define|#
directive|define
name|MASK_LONG_DOUBLE_128
value|0x8000000
end_define

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_128
value|(target_flags& MASK_LONG_DOUBLE_128)
end_define

begin_comment
comment|/* TARGET_HARD_MUL: Use hardware multiply instructions but not %y.    TARGET_HARD_MUL32: Use hardware multiply instructions with rd %y    to get high 32 bits.  False in V8+ or V9 because multiply stores    a 64 bit result in a register.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HARD_MUL32
define|\
value|((TARGET_V8 || TARGET_SPARCLITE			\     || TARGET_SPARCLET || TARGET_DEPRECATED_V8_INSNS)	\&& ! TARGET_V8PLUS&& TARGET_ARCH32)
end_define

begin_define
define|#
directive|define
name|TARGET_HARD_MUL
define|\
value|(TARGET_V8 || TARGET_SPARCLITE || TARGET_SPARCLET	\    || TARGET_DEPRECATED_V8_INSNS || TARGET_V8PLUS)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"fpu", MASK_FPU | MASK_FPU_SET,					\      N_("Use hardware fp") },						\     {"no-fpu", -MASK_FPU,						\      N_("Do not use hardware fp") },					\     {"no-fpu", MASK_FPU_SET,				NULL, },	\     {"hard-float", MASK_FPU | MASK_FPU_SET,				\      N_("Use hardware fp") },						\     {"soft-float", -MASK_FPU,						\      N_("Do not use hardware fp") },					\     {"soft-float", MASK_FPU_SET,			NULL },		\     {"epilogue", MASK_EPILOGUE,						\      N_("Use function_epilogue()") },					\     {"no-epilogue", -MASK_EPILOGUE,					\      N_("Do not use function_epilogue()") }, 				\     {"unaligned-doubles", MASK_UNALIGNED_DOUBLES,			\      N_("Assume possible double misalignment") },			\     {"no-unaligned-doubles", -MASK_UNALIGNED_DOUBLES,			\      N_("Assume all doubles are aligned") },				\     {"impure-text", MASK_IMPURE_TEXT,					\      N_("Pass -assert pure-text to linker") }, 				\     {"no-impure-text", -MASK_IMPURE_TEXT,				\      N_("Do not pass -assert pure-text to linker") }, 			\     {"flat", MASK_FLAT,							\      N_("Use flat register window model") }, 				\     {"no-flat", -MASK_FLAT,						\      N_("Do not use flat register window model") }, 			\     {"app-regs", MASK_APP_REGS,						\      N_("Use ABI reserved registers") },				\     {"no-app-regs", -MASK_APP_REGS,					\      N_("Do not use ABI reserved registers") }, 			\     {"hard-quad-float", MASK_HARD_QUAD,					\      N_("Use hardware quad fp instructions") }, 			\     {"soft-quad-float", -MASK_HARD_QUAD,				\      N_("Do not use hardware quad fp instructions") }, 			\     {"v8plus", MASK_V8PLUS,						\      N_("Compile for v8plus ABI") },					\     {"no-v8plus", -MASK_V8PLUS,						\      N_("Do not compile for v8plus ABI") }, 				\     {"vis", MASK_VIS,							\      N_("Utilize Visual Instruction Set") }, 				\     {"no-vis", -MASK_VIS,						\      N_("Do not utilize Visual Instruction Set") }, 			\
comment|/* ??? These are deprecated, coerced to -mcpu=.  Delete in 2.9.  */
value|\     {"cypress", 0,							\      N_("Optimize for Cypress processors") }, 				\     {"sparclite", 0,							\      N_("Optimize for SparcLite processors") }, 			\     {"f930", 0,								\      N_("Optimize for F930 processors") }, 				\     {"f934", 0,								\      N_("Optimize for F934 processors") }, 				\     {"v8", 0,								\      N_("Use V8 Sparc ISA") }, 						\     {"supersparc", 0,							\      N_("Optimize for SuperSparc processors") }, 			\
comment|/* End of deprecated options.  */
value|\     {"ptr64", MASK_PTR64,						\      N_("Pointers are 64-bit") }, 					\     {"ptr32", -MASK_PTR64,						\      N_("Pointers are 32-bit") }, 					\     {"32", -MASK_64BIT,							\      N_("Use 32-bit ABI") }, 						\     {"64", MASK_64BIT,							\      N_("Use 64-bit ABI") }, 						\     {"stack-bias", MASK_STACK_BIAS,					\      N_("Use stack bias") }, 						\     {"no-stack-bias", -MASK_STACK_BIAS,					\      N_("Do not use stack bias") }, 					\     {"faster-structs", MASK_FASTER_STRUCTS,				\      N_("Use structs on stronger alignment for double-word copies") }, 	\     {"no-faster-structs", -MASK_FASTER_STRUCTS,				\      N_("Do not use structs on stronger alignment for double-word copies") }, \     {"relax", 0,							\      N_("Optimize tail call instructions in assembler and linker") },	\     {"no-relax", 0,							\      N_("Do not optimize tail call instructions in assembler or linker") }, \     SUBTARGET_SWITCHES			\     { "", TARGET_DEFAULT, ""}}
end_define

begin_comment
comment|/* MASK_APP_REGS must always be the default because that's what    FIXED_REGISTERS is set to and -ffixed- is processed before    CONDITIONAL_REGISTER_USAGE is called (where we process -mno-app-regs).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_APP_REGS + MASK_EPILOGUE + MASK_FPU)
end_define

begin_comment
comment|/* This is meant to be redefined in target specific files.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
end_define

begin_comment
comment|/* Processor type.    These must match the values for the cpu attribute in sparc.md.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_V7
block|,
name|PROCESSOR_CYPRESS
block|,
name|PROCESSOR_V8
block|,
name|PROCESSOR_SUPERSPARC
block|,
name|PROCESSOR_SPARCLITE
block|,
name|PROCESSOR_F930
block|,
name|PROCESSOR_F934
block|,
name|PROCESSOR_HYPERSPARC
block|,
name|PROCESSOR_SPARCLITE86X
block|,
name|PROCESSOR_SPARCLET
block|,
name|PROCESSOR_TSC701
block|,
name|PROCESSOR_V9
block|,
name|PROCESSOR_ULTRASPARC
block|}
enum|;
end_enum

begin_comment
comment|/* This is set from -m{cpu,tune}=xxx.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|sparc_cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Recast the cpu class to be the cpu attribute.    Every file includes us, but not every file includes insn-attr.h.  */
end_comment

begin_define
define|#
directive|define
name|sparc_cpu_attr
value|((enum attr_cpu) sparc_cpu)
end_define

begin_define
define|#
directive|define
name|TARGET_OPTIONS
define|\
value|{								\   { "cpu=",&sparc_select[1].string,				\     N_("Use features of and schedule code for given CPU") },	\   { "tune=",&sparc_select[2].string,				\     N_("Schedule code for given CPU") },			\   { "cmodel=",&sparc_cmodel_string,				\     N_("Use given Sparc code model") },				\   SUBTARGET_OPTIONS 						\ }
end_define

begin_comment
comment|/* This is meant to be redefined in target specific files.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OPTIONS
end_define

begin_comment
comment|/* sparc_select[0] is reserved for the default cpu.  */
end_comment

begin_struct
struct|struct
name|sparc_cpu_select
block|{
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
specifier|const
name|int
name|set_tune_p
decl_stmt|;
specifier|const
name|int
name|set_arch_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sparc_cpu_select
name|sparc_select
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define for cross-compilation to a sparc target with no TFmode from a host    with a different float format (e.g. VAX).  */
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
value|1
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is the lowest    numbered.  */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this to set the endianness to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__LITTLE_ENDIAN_DATA__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(TARGET_ARCH64 ? 64 : 32)
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
value|(TARGET_ARCH64 ? 8 : 4)
end_define

begin_define
define|#
directive|define
name|MIN_UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* Now define the sizes of the C data types.  */
end_comment

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
name|LONG_TYPE_SIZE
value|(TARGET_ARCH64 ? 64 : 32)
end_define

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|64
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
name|DOUBLE_TYPE_SIZE
value|64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_define
define|#
directive|define
name|MAX_LONG_TYPE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* ??? This does not work in SunOS 4.x, so it is not enabled here.    Instead, it is enabled in sol2.h, because it does work under Solaris.  */
end_comment

begin_comment
comment|/* Define for support of TFmode long double and REAL_ARITHMETIC.    Sparc ABI says that long double is 4 words.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|(TARGET_PTR64 ? 64 : 32)
end_define

begin_comment
comment|/* If we have to extend pointers (only when TARGET_ARCH64 and not    TARGET_PTR64), we want to do it unsigned.   This macro does nothing    if ptr_mode and Pmode are the same.  */
end_comment

begin_define
define|#
directive|define
name|POINTERS_EXTEND_UNSIGNED
value|1
end_define

begin_comment
comment|/* A macro to update MODE and UNSIGNEDP when an object whose type    is TYPE and which has the specified mode and signedness is to be    stored in a register.  This macro is only called when TYPE is a    scalar type.  */
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
value|if (TARGET_ARCH64				\&& GET_MODE_CLASS (MODE) == MODE_INT	\&& GET_MODE_SIZE (MODE)< UNITS_PER_WORD)	\   (MODE) = DImode;
end_define

begin_comment
comment|/* Define this macro if the promotion described by PROMOTE_MODE    should also be done for outgoing function arguments.  */
end_comment

begin_comment
comment|/* This is only needed for TARGET_ARCH64, but since PROMOTE_MODE is a no-op    for TARGET_ARCH32 this is ok.  Otherwise we'd need to add a runtime test    for this value.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_ARGS
end_define

begin_comment
comment|/* Define this macro if the promotion described by PROMOTE_MODE    should also be done for the return value of functions.    If this macro is defined, FUNCTION_VALUE must perform the same    promotions done by PROMOTE_MODE.  */
end_comment

begin_comment
comment|/* This is only needed for TARGET_ARCH64, but since PROMOTE_MODE is a no-op    for TARGET_ARCH32 this is ok.  Otherwise we'd need to add a runtime test    for this value.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_RETURN
end_define

begin_comment
comment|/* Define this macro if the promotion described by PROMOTE_MODE    should _only_ be performed for outgoing function arguments or    function return values, as specified by PROMOTE_FUNCTION_ARGS    and PROMOTE_FUNCTION_RETURN, respectively.  */
end_comment

begin_comment
comment|/* This is only needed for TARGET_ARCH64, but since PROMOTE_MODE is a no-op    for TARGET_ARCH32 this is ok.  Otherwise we'd need to add a runtime test    for this value.  For TARGET_ARCH64 we need it, as we don't have instructions    for arithmetic operations which do zero/sign extension at the same time,    so without this we end up with a srl/sra after every assignment to an    user variable,  which means very very bad code.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FOR_CALL_ONLY
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|(TARGET_ARCH64 ? 64 : 32)
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|(TARGET_ARCH64 ? 128 : 64)
end_define

begin_comment
comment|/* ALIGN FRAMES on double word boundaries */
end_comment

begin_define
define|#
directive|define
name|SPARC_STACK_ALIGN
parameter_list|(
name|LOC
parameter_list|)
define|\
value|(TARGET_ARCH64 ? (((LOC)+15)& ~15) : (((LOC)+7)& ~7))
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
value|(TARGET_ARCH64 ? 64 : 32)
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
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|(TARGET_ARCH64 ? 128 : 64)
end_define

begin_comment
comment|/* The best alignment to use in cases where we have a choice.  */
end_comment

begin_define
define|#
directive|define
name|FASTEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* Define this macro as an expression for the alignment of a structure    (given by STRUCT as a tree node) if the alignment computed in the    usual way is COMPUTED and the alignment explicitly specified was    SPECIFIED.     The default is to use SPECIFIED if it is larger; otherwise, use    the smaller of COMPUTED and `BIGGEST_ALIGNMENT' */
end_comment

begin_define
define|#
directive|define
name|ROUND_TYPE_ALIGN
parameter_list|(
name|STRUCT
parameter_list|,
name|COMPUTED
parameter_list|,
name|SPECIFIED
parameter_list|)
define|\
value|(TARGET_FASTER_STRUCTS ?				\   ((TREE_CODE (STRUCT) == RECORD_TYPE			\     || TREE_CODE (STRUCT) == UNION_TYPE                 \     || TREE_CODE (STRUCT) == QUAL_UNION_TYPE)           \&& TYPE_FIELDS (STRUCT) != 0                         \      ? MAX (MAX ((COMPUTED), (SPECIFIED)), BIGGEST_ALIGNMENT) \      : MAX ((COMPUTED), (SPECIFIED)))			\    :  MAX ((COMPUTED), (SPECIFIED)))
end_define

begin_comment
comment|/* Make strings word-aligned so strcpy from constants will be faster.  */
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
value|((TREE_CODE (EXP) == STRING_CST	\&& (ALIGN)< FASTEST_ALIGNMENT)	\    ? FASTEST_ALIGNMENT : (ALIGN))
end_define

begin_comment
comment|/* Make arrays of chars word-aligned for the same reasons.  */
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
value|(TREE_CODE (TYPE) == ARRAY_TYPE		\&& TYPE_MODE (TREE_TYPE (TYPE)) == QImode	\&& (ALIGN)< FASTEST_ALIGNMENT ? FASTEST_ALIGNMENT : (ALIGN))
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
comment|/* Things that must be doubleword aligned cannot go in the text section,    because the linker fails to align the text section enough!    Put them in the data section.  This macro is only used in this file.  */
end_comment

begin_define
define|#
directive|define
name|MAX_TEXT_ALIGN
value|32
end_define

begin_comment
comment|/* This forces all variables and constants to the data section when PIC.    This is because the SunOS 4 shared library scheme thinks everything in    text is a function, and patches the address to point to a loader stub.  */
end_comment

begin_comment
comment|/* This is defined to zero for every system which doesn't use the a.out object    file format.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUNOS4_SHARED_LIBRARIES
end_ifndef

begin_define
define|#
directive|define
name|SUNOS4_SHARED_LIBRARIES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use text section for a constant    unless we need more alignment than that offers.  */
end_comment

begin_comment
comment|/* This is defined differently for v9 in a cover file.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{						\   if (GET_MODE_BITSIZE (MODE)<= MAX_TEXT_ALIGN \&& ! (flag_pic&& (symbolic_operand ((X), (MODE)) || SUNOS4_SHARED_LIBRARIES)))  \     text_section ();				\   else						\     data_section ();				\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     SPARC has 32 integer registers and 32 floating point registers.    64 bit SPARC has 32 additional fp regs, but the odd numbered ones are not    accessible.  We still account for them to simplify register computations    (eg: in CLASS_MAX_NREGS).  There are also 4 fp condition code registers, so    32+32+32+4 == 100.    Register 100 is used as the integer condition code register.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|101
end_define

begin_define
define|#
directive|define
name|SPARC_FIRST_FP_REG
value|32
end_define

begin_comment
comment|/* Additional V9 fp regs.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_FIRST_V9_FP_REG
value|64
end_define

begin_define
define|#
directive|define
name|SPARC_LAST_V9_FP_REG
value|95
end_define

begin_comment
comment|/* V9 %fcc[0123].  V8 uses (figuratively) %fcc0.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_FIRST_V9_FCC_REG
value|96
end_define

begin_define
define|#
directive|define
name|SPARC_LAST_V9_FCC_REG
value|99
end_define

begin_comment
comment|/* V8 fcc reg.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_FCC_REG
value|96
end_define

begin_comment
comment|/* Integer CC reg.  We don't distinguish %icc from %xcc.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_ICC_REG
value|100
end_define

begin_comment
comment|/* Nonzero if REGNO is an fp reg.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_FP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)>= SPARC_FIRST_FP_REG&& (REGNO)<= SPARC_LAST_V9_FP_REG)
end_define

begin_comment
comment|/* Argument passing regs.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_OUTGOING_INT_ARG_FIRST
value|8
end_define

begin_define
define|#
directive|define
name|SPARC_INCOMING_INT_ARG_FIRST
value|(TARGET_FLAT ? 8 : 24)
end_define

begin_define
define|#
directive|define
name|SPARC_FP_ARG_FIRST
value|32
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.     On non-v9 systems:    g1 is free to use as temporary.    g2-g4 are reserved for applications.  Gcc normally uses them as    temporaries, but this can be disabled via the -mno-app-regs option.    g5 through g7 are reserved for the operating system.     On v9 systems:    g1,g5 are free to use as temporaries, and are free to use between calls    if the call is to an external function via the PLT.    g4 is free to use as a temporary in the non-embedded case.    g4 is reserved in the embedded case.    g2-g3 are reserved for applications.  Gcc normally uses them as    temporaries, but this can be disabled via the -mno-app-regs option.    g6-g7 are reserved for the operating system (or application in    embedded case).    ??? Register 1 is used as a temporary by the 64 bit sethi pattern, so must    currently be a fixed register until this pattern is rewritten.    Register 1 is also used when restoring call-preserved registers in large    stack frames.     Registers fixed in arch32 and not arch64 (or vice-versa) are marked in    CONDITIONAL_REGISTER_USAGE in order to properly handle -ffixed-. */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{1, 0, 2, 2, 2, 2, 1, 1,	\   0, 0, 0, 0, 0, 0, 1, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 1, 1,	\ 				\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\ 				\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\ 				\   0, 0, 0, 0, 0}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 1, 1,	\ 				\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\ 				\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\ 				\   1, 1, 1, 1, 1}
end_define

begin_comment
comment|/* If !TARGET_FPU, then make the fp registers and fp cc regs fixed so that    they won't be allocated.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|do								\   {								\     if (flag_pic)						\       {								\ 	fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;		\ 	call_used_regs[PIC_OFFSET_TABLE_REGNUM] = 1;		\       }								\
comment|/* If the user has passed -f{fixed,call-{used,saved}}-g5 */
value|\
comment|/* then honour it.  */
value|\     if (TARGET_ARCH32&& fixed_regs[5])				\       fixed_regs[5] = 1;					\     else if (TARGET_ARCH64&& fixed_regs[5] == 2)		\       fixed_regs[5] = 0;					\     if (! TARGET_V9)						\       {								\ 	int regno;						\ 	for (regno = SPARC_FIRST_V9_FP_REG;			\ 	     regno<= SPARC_LAST_V9_FP_REG;			\ 	     regno++)						\ 	  fixed_regs[regno] = 1;				\
comment|/* %fcc0 is used by v8 and v9.  */
value|\ 	for (regno = SPARC_FIRST_V9_FCC_REG + 1;		\ 	     regno<= SPARC_LAST_V9_FCC_REG;			\ 	     regno++)						\ 	  fixed_regs[regno] = 1;				\       }								\     if (! TARGET_FPU)						\       {								\ 	int regno;						\ 	for (regno = 32; regno< SPARC_LAST_V9_FCC_REG; regno++) \ 	  fixed_regs[regno] = 1;				\       }								\
comment|/* If the user has passed -f{fixed,call-{used,saved}}-g2 */
value|\
comment|/* then honour it.  Likewise with g3 and g4.  */
value|\     if (fixed_regs[2] == 2)					\       fixed_regs[2] = ! TARGET_APP_REGS;			\     if (fixed_regs[3] == 2)					\       fixed_regs[3] = ! TARGET_APP_REGS;			\     if (TARGET_ARCH32&& fixed_regs[4] == 2)			\       fixed_regs[4] = ! TARGET_APP_REGS;			\     else if (TARGET_CM_EMBMEDANY)				\       fixed_regs[4] = 1;					\     else if (fixed_regs[4] == 2)				\       fixed_regs[4] = 0;					\     if (TARGET_FLAT)						\       {								\
comment|/* Let the compiler believe the frame pointer is still	\ 	   %fp, but output it as %i7.  */
value|\ 	fixed_regs[31] = 1;					\ 	reg_names[FRAME_POINTER_REGNUM] = "%i7";		\
comment|/* Disable leaf functions */
value|\ 	memset (sparc_leaf_regs, 0, FIRST_PSEUDO_REGISTER);	\       }								\   }								\ while (0)
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On SPARC, ordinary registers hold 32 bits worth;    this means both integer and floating point registers.    On v9, integer regs hold 64 bits worth; floating point regs hold    32 bits worth (this includes the new fp regs as even the odd ones are    included in the hard register count).  */
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
value|(TARGET_ARCH64							\    ?  ((REGNO)< 32							\        ? (GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD	\        : (GET_MODE_SIZE (MODE) + 3) / 4)				\    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Due to the ARCH64 descrepancy above we must override this next    macro too.  */
end_comment

begin_define
define|#
directive|define
name|REGMODE_NATURAL_SIZE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((TARGET_ARCH64&& FLOAT_MODE_P (MODE)) ? 4 : UNITS_PER_WORD)
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    See sparc.c for how we initialize this.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
modifier|*
name|hard_regno_mode_classes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sparc_mode_class
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ??? Because of the funny way we pass parameters we should allow certain    ??? types of float/complex values to be in integer registers during    ??? RTL generation.  This only matters on arch32.  */
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
value|((hard_regno_mode_classes[REGNO]& sparc_mode_class[MODE]) != 0)
end_define

begin_comment
comment|/* Value is 1 if it is a good idea to tie two pseudo registers    when one has mode MODE1 and one has mode MODE2.    If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,    for any hard reg, then this must be 0 for correct output.     For V9: SFmode can't be combined with other float modes, because they can't    be allocated to the %d registers.  Also, DFmode won't fit in odd %f    registers, but SFmode will.  */
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
value|((MODE1) == (MODE2)						\    || (GET_MODE_CLASS (MODE1) == GET_MODE_CLASS (MODE2)		\&& (! TARGET_V9						\ 	   || (GET_MODE_CLASS (MODE1) != MODE_FLOAT		\ 	       || (MODE1 != SFmode&& MODE2 != SFmode)))))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* SPARC pc isn't overloaded on a register that the compiler knows about.  */
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
value|14
end_define

begin_comment
comment|/* Actual top-of-stack address is 92/176 greater than the contents of the    stack pointer register for !v9/v9.  That is:    - !v9: 64 bytes for the in and local registers, 4 bytes for structure return      address, and 6*4 bytes for the 6 register parameters.    - v9: 128 bytes for the in and local registers + 6*8 bytes for the integer      parameter regs.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|FIRST_PARM_OFFSET(0)
end_define

begin_comment
comment|/* The stack bias (amount by which the hardware register is offset by).  */
end_comment

begin_define
define|#
directive|define
name|SPARC_STACK_BIAS
value|((TARGET_ARCH64&& TARGET_STACK_BIAS) ? 2047 : 0)
end_define

begin_comment
comment|/* Is stack biased? */
end_comment

begin_define
define|#
directive|define
name|STACK_BIAS
value|SPARC_STACK_BIAS
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|30
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Register that is used for the return address for the flat model.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_REGNUM
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.    Used in flow.c, global.c, and reload1.c.     Being a non-leaf function does not mean a frame pointer is needed in the    flat window model.  However, the debugger won't be able to backtrace through    us with out it.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
define|\
value|(TARGET_FLAT ? (current_function_calls_alloca || current_function_varargs \ 		  || !leaf_function_p ()) \    : ! (leaf_function_p ()&& only_leaf_regs_used ()))
end_define

begin_comment
comment|/* C statement to store the difference between the frame pointer    and the stack pointer values immediately after the function prologue.     Note, we always pretend that this is a leaf function because if    it's not, there's no point in trying to eliminate the    frame pointer.  If it is a leaf function, we guessed right!  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|VAR
parameter_list|)
define|\
value|((VAR) = (TARGET_FLAT ? sparc_flat_compute_frame_size (get_frame_size ()) \ 	    : compute_frame_size (get_frame_size (), 1)))
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|FRAME_POINTER_REGNUM
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  This must    not be a register used by the prologue.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|(TARGET_ARCH64 ? 5 : 2)
end_define

begin_comment
comment|/* Register which holds offset table for position-independent    data references.  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|23
end_define

begin_comment
comment|/* Pick a default value we can notice from override_options:    !v9: Default is on.    v9: Default is off.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|-1
end_define

begin_comment
comment|/* Sparc ABI says that quad-precision floats and all structures are returned    in memory.    For v9: unions<= 32 bytes in size are returned in int regs,    structures up to 32 bytes are returned in int and fp regs.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TARGET_ARCH32						\  ? (TYPE_MODE (TYPE) == BLKmode				\     || TYPE_MODE (TYPE) == TFmode			\     || TYPE_MODE (TYPE) == TCmode)			\  : (TYPE_MODE (TYPE) == BLKmode				\&& (unsigned HOST_WIDE_INT) int_size_in_bytes (TYPE)> 32))
end_define

begin_comment
comment|/* Functions which return large structures get the address    to place the wanted value at offset 64 from the frame.    Must reserve 64 bytes for the in and local registers.    v9: Functions which return large structures get the address to place the    wanted value from an invisible first argument.  */
end_comment

begin_comment
comment|/* Used only in other #defines in this file.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_OFFSET
value|64
end_define

begin_define
define|#
directive|define
name|STRUCT_VALUE
define|\
value|(TARGET_ARCH64					\    ? 0							\    : gen_rtx_MEM (Pmode, plus_constant (stack_pointer_rtx, \ 					STRUCT_VALUE_OFFSET)))
end_define

begin_define
define|#
directive|define
name|STRUCT_VALUE_INCOMING
define|\
value|(TARGET_ARCH64						\    ? 0								\    : gen_rtx_MEM (Pmode, plus_constant (frame_pointer_rtx,	\ 					STRUCT_VALUE_OFFSET)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The SPARC has various kinds of registers: general, floating point,    and condition codes [well, it has others as well, but none that we    care directly about].     For v9 we must distinguish between the upper and lower floating point    registers because the upper ones can't hold SFmode values.    HARD_REGNO_MODE_OK won't help here because reload assumes that register(s)    satisfying a group need for a class will also satisfy a single need for    that class.  EXTRA_FP_REGS is a bit of a misnomer as it covers all 64 fp    regs.     It is important that one class contains all the general and all the standard    fp regs.  Otherwise find_reg() won't properly allocate int regs for moves,    because reg_class_record() will bias the selection in favor of fp regs,    because reg_class_subunion[GENERAL_REGS][FP_REGS] will yield FP_REGS,    because FP_REGS> GENERAL_REGS.     It is also important that one class contain all the general and all the    fp regs.  Otherwise when spilling a DFmode reg, it may be from EXTRA_FP_REGS    but find_reloads() may use class GENERAL_OR_FP_REGS. This will cause    allocate_reload_reg() to bypass it causing an abort because the compiler    thinks it doesn't have a spill reg when in fact it does.     v9 also has 4 floating point condition code registers.  Since we don't    have a class that is the union of FPCC_REGS with either of the others,    it is important that it appear first.  Otherwise the compiler will die    trying to compile _fixunsdfsi because fix_truncdfsi2 won't match its    constraints.     It is important that SPARC_ICC_REG have class NO_REGS.  Otherwise combine    may try to use it to hold an SImode value.  See register_operand.    ??? Should %fcc[0123] be handled similarly? */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|FPCC_REGS
block|,
name|I64_REGS
block|,
name|GENERAL_REGS
block|,
name|FP_REGS
block|,
name|EXTRA_FP_REGS
block|,
name|GENERAL_OR_FP_REGS
block|,
name|GENERAL_OR_EXTRA_FP_REGS
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
value|{ "NO_REGS", "FPCC_REGS", "I64_REGS", "GENERAL_REGS", "FP_REGS",	\      "EXTRA_FP_REGS", "GENERAL_OR_FP_REGS", "GENERAL_OR_EXTRA_FP_REGS",	\      "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{{0, 0, 0, 0}, {0, 0, 0, 0xf}, {0xffff, 0, 0, 0}, \    {-1, 0, 0, 0}, {0, -1, 0, 0}, {0, -1, -1, 0}, \    {-1, -1, 0, 0}, {-1, -1, -1, 0}, {-1, -1, -1, 0x1f}}
end_define

begin_comment
comment|/* The same information, inverted:    Return the class number of the smallest class containing    reg number REGNO.  This could be a conditional expression    or could index an array.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|sparc_regno_reg_class
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|sparc_regno_reg_class[(REGNO)]
end_define

begin_comment
comment|/* This is the order in which to allocate registers normally.          We put %f0/%f1 last among the float registers, so as to make it more    likely that a pseudo-register which dies in the float return register    will get allocated to the float return register, thus saving a move    instruction at the end of the function.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{ 8, 9, 10, 11, 12, 13, 2, 3,		\   15, 16, 17, 18, 19, 20, 21, 22,	\   23, 24, 25, 26, 27, 28, 29, 31,	\   34, 35, 36, 37, 38, 39,
comment|/* %f2-%f7 */
value|\   40, 41, 42, 43, 44, 45, 46, 47,
comment|/* %f8-%f15 */
value|\   48, 49, 50, 51, 52, 53, 54, 55,
comment|/* %f16-%f23 */
value|\   56, 57, 58, 59, 60, 61, 62, 63,
comment|/* %f24-%f31 */
value|\   64, 65, 66, 67, 68, 69, 70, 71,
comment|/* %f32-%f39 */
value|\   72, 73, 74, 75, 76, 77, 78, 79,
comment|/* %f40-%f47 */
value|\   80, 81, 82, 83, 84, 85, 86, 87,
comment|/* %f48-%f55 */
value|\   88, 89, 90, 91, 92, 93, 94, 95,
comment|/* %f56-%f63 */
value|\   32, 33,
comment|/* %f0,%f1 */
value|\   96, 97, 98, 99, 100,
comment|/* %fcc0-3, %icc */
value|\   1, 4, 5, 6, 7, 0, 14, 30}
end_define

begin_comment
comment|/* This is the order in which to allocate registers for    leaf functions.  If all registers can fit in the "gi" registers,    then we have the possibility of having a leaf function.  */
end_comment

begin_define
define|#
directive|define
name|REG_LEAF_ALLOC_ORDER
define|\
value|{ 2, 3, 24, 25, 26, 27, 28, 29,		\   4, 5, 6, 7, 1,			\   15, 8, 9, 10, 11, 12, 13,		\   16, 17, 18, 19, 20, 21, 22, 23,	\   34, 35, 36, 37, 38, 39,		\   40, 41, 42, 43, 44, 45, 46, 47,	\   48, 49, 50, 51, 52, 53, 54, 55,	\   56, 57, 58, 59, 60, 61, 62, 63,	\   64, 65, 66, 67, 68, 69, 70, 71,	\   72, 73, 74, 75, 76, 77, 78, 79,	\   80, 81, 82, 83, 84, 85, 86, 87,	\   88, 89, 90, 91, 92, 93, 94, 95,	\   32, 33,				\   96, 97, 98, 99, 100,			\   0, 14, 30, 31}
end_define

begin_define
define|#
directive|define
name|ORDER_REGS_FOR_LOCAL_ALLOC
value|order_regs_for_local_alloc ()
end_define

begin_decl_stmt
specifier|extern
name|char
name|sparc_leaf_regs
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LEAF_REGISTERS
value|sparc_leaf_regs
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|leaf_reg_remap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LEAF_REG_REMAP
parameter_list|(
name|REGNO
parameter_list|)
value|(leaf_reg_remap[REGNO])
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
value|GENERAL_REGS
end_define

begin_comment
comment|/* Local macro to handle the two v9 classes of FP regs.  */
end_comment

begin_define
define|#
directive|define
name|FP_REG_CLASS_P
parameter_list|(
name|CLASS
parameter_list|)
value|((CLASS) == FP_REGS || (CLASS) == EXTRA_FP_REGS)
end_define

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine description.    In the not-v9 case, coerce v9's 'e' class to 'f', so we can use 'e' in the    .md file for v8 and v9.    'd' and 'b' are used for single and double precision VIS operations,    if TARGET_VIS.    'h' is used for V8+ 64 bit global and out registers.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|(TARGET_V9					\  ? ((C) == 'f' ? FP_REGS			\     : (C) == 'e' ? EXTRA_FP_REGS 		\     : (C) == 'c' ? FPCC_REGS			\     : ((C) == 'd'&& TARGET_VIS) ? FP_REGS\     : ((C) == 'b'&& TARGET_VIS) ? EXTRA_FP_REGS\     : ((C) == 'h'&& TARGET_V8PLUS) ? I64_REGS\     : NO_REGS)					\  : ((C) == 'f' ? FP_REGS			\     : (C) == 'e' ? FP_REGS			\     : (C) == 'c' ? FPCC_REGS			\     : NO_REGS))
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     `I' is used for the range of constants an insn can actually contain.    `J' is used for the range which is just zero (since that is R0).    `K' is used for constants which can be loaded with a single sethi insn.    `L' is used for the range of constants supported by the movcc insns.    `M' is used for the range of constants supported by the movrcc insns.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_SIMM10_P
parameter_list|(
name|X
parameter_list|)
value|((unsigned HOST_WIDE_INT) (X) + 0x200< 0x400)
end_define

begin_define
define|#
directive|define
name|SPARC_SIMM11_P
parameter_list|(
name|X
parameter_list|)
value|((unsigned HOST_WIDE_INT) (X) + 0x400< 0x800)
end_define

begin_define
define|#
directive|define
name|SPARC_SIMM13_P
parameter_list|(
name|X
parameter_list|)
value|((unsigned HOST_WIDE_INT) (X) + 0x1000< 0x2000)
end_define

begin_comment
comment|/* 10 and 11 bit immediates are only used for a few specific insns.    SMALL_INT is used throughout the port so we continue to use it.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_INT
parameter_list|(
name|X
parameter_list|)
value|(SPARC_SIMM13_P (INTVAL (X)))
end_define

begin_comment
comment|/* 13 bit immediate, considering only the low 32 bits */
end_comment

begin_define
define|#
directive|define
name|SMALL_INT32
parameter_list|(
name|X
parameter_list|)
value|(SPARC_SIMM13_P ((int)INTVAL (X)& 0xffffffff))
end_define

begin_define
define|#
directive|define
name|SPARC_SETHI_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(((unsigned HOST_WIDE_INT) (X)& \   (TARGET_ARCH64 ? ~(unsigned HOST_WIDE_INT) 0xfffffc00 : 0x3ff)) == 0)
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
value|((C) == 'I' ? SPARC_SIMM13_P (VALUE)			\    : (C) == 'J' ? (VALUE) == 0				\    : (C) == 'K' ? SPARC_SETHI_P (VALUE)			\    : (C) == 'L' ? SPARC_SIMM11_P (VALUE)		\    : (C) == 'M' ? SPARC_SIMM10_P (VALUE)		\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.  */
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
value|((C) == 'G' ? fp_zero_operand (VALUE, GET_MODE (VALUE))	\    : (C) == 'H' ? arith_double_operand (VALUE, DImode)		\    : 0)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
end_comment

begin_comment
comment|/* - We can't load constants into FP registers.    - We can't load FP constants into integer registers when soft-float,      because there is no soft-float pattern with a r/F constraint.    - We can't load FP constants into integer registers for TFmode unless      it is 0.0L, because there is no movtf pattern with a r/F constraint.    - Try and reload integer constants (symbolic or otherwise) back into      registers directly, rather than having them dumped to memory.  */
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
value|(CONSTANT_P (X)					\    ? ((FP_REG_CLASS_P (CLASS)				\        || (GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT	\&& ! TARGET_FPU)				\        || (GET_MODE (X) == TFmode			\&& ! fp_zero_operand (X, TFmode)))		\       ? NO_REGS						\       : (!FP_REG_CLASS_P (CLASS)			\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_INT)	\       ? GENERAL_REGS					\       : (CLASS))					\    : (CLASS))
end_define

begin_comment
comment|/* Return the register class of a scratch register needed to load IN into    a register of class CLASS in MODE.     We need a temporary when loading/storing a HImode/QImode value    between memory and the FPU registers.  This can happen when combine puts    a paradoxical subreg in a float/fix conversion insn.  */
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
value|((FP_REG_CLASS_P (CLASS)					\&& ((MODE) == HImode || (MODE) == QImode)			\&& (GET_CODE (IN) == MEM					\         || ((GET_CODE (IN) == REG || GET_CODE (IN) == SUBREG)	\&& true_regnum (IN) == -1)))			\    ? GENERAL_REGS						\    : (((TARGET_CM_MEDANY					\&& symbolic_operand ((IN), (MODE)))			\        || (TARGET_CM_EMBMEDANY					\&& text_segment_operand ((IN), (MODE))))		\&& !flag_pic)						\      ? GENERAL_REGS						\      : NO_REGS)
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
value|((FP_REG_CLASS_P (CLASS)					\&& ((MODE) == HImode || (MODE) == QImode)			\&& (GET_CODE (IN) == MEM					\          || ((GET_CODE (IN) == REG || GET_CODE (IN) == SUBREG)	\&& true_regnum (IN) == -1)))			\     ? GENERAL_REGS						\    : (((TARGET_CM_MEDANY					\&& symbolic_operand ((IN), (MODE)))			\        || (TARGET_CM_EMBMEDANY					\&& text_segment_operand ((IN), (MODE))))		\&& !flag_pic)						\      ? GENERAL_REGS						\      : NO_REGS)
end_define

begin_comment
comment|/* On SPARC it is not possible to directly move data between     GENERAL_REGS and FP_REGS.  */
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
value|(FP_REG_CLASS_P (CLASS1) != FP_REG_CLASS_P (CLASS2))
end_define

begin_comment
comment|/* Return the stack location to use for secondary memory needed reloads.    We want to use the reserved location just below the frame pointer.    However, we must ensure that there is a frame, so use assign_stack_local    if the frame size is zero.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_MEMORY_NEEDED_RTX
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(get_frame_size () == 0						\    ? assign_stack_local (MODE, GET_MODE_SIZE (MODE), 0)			\    : gen_rtx_MEM (MODE, plus_constant (frame_pointer_rtx,		\ 				       STARTING_FRAME_OFFSET)))
end_define

begin_comment
comment|/* Get_secondary_mem widens its argument to BITS_PER_WORD which loses on v9    because the movsi and movsf patterns don't handle r/f moves.    For v8 we copy the default definition.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_MEMORY_NEEDED_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARCH64						\    ? (GET_MODE_BITSIZE (MODE)< 32				\       ? mode_for_size (32, GET_MODE_CLASS (MODE), 0)		\       : MODE)							\    : (GET_MODE_BITSIZE (MODE)< BITS_PER_WORD			\       ? mode_for_size (BITS_PER_WORD, GET_MODE_CLASS (MODE), 0)	\       : MODE))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On SPARC, this is the size of MODE in words.  */
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
value|(FP_REG_CLASS_P (CLASS) ? (GET_MODE_SIZE (MODE) + 3) / 4 \    : (GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Define the number of register that can hold parameters.    This macro is only used in other macro definitions below and in sparc.c.    MODE is the mode of the argument.    !v9: All args are passed in %o0-%o5.    v9: %o0-%o5 and %f0-%f31 are cumulatively used to pass values.    See the description in sparc.c.  */
end_comment

begin_define
define|#
directive|define
name|NPARM_REGS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARCH64 \  ? (GET_MODE_CLASS (MODE) == MODE_FLOAT ? 32 : 6) \  : 6)
end_define

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

begin_comment
comment|/* This allows space for one TFmode floating point value.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
define|\
value|(TARGET_ARCH64 ? (SPARC_STACK_BIAS - 16) \    : (-SPARC_STACK_ALIGN (LONG_DOUBLE_TYPE_SIZE / BITS_PER_UNIT)))
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On SPARC, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    !v9: This is 64 for the ins and locals, plus 4 for the struct-return reg    even if this function isn't going to use it.    v9: This is 128 for the ins and locals.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
define|\
value|(TARGET_ARCH64 ? (SPARC_STACK_BIAS + 16 * UNITS_PER_WORD) \    : (STRUCT_VALUE_OFFSET + UNITS_PER_WORD))
end_define

begin_comment
comment|/* Offset from the argument pointer register value to the CFA.    This is different from FIRST_PARM_OFFSET because the register window    comes between the CFA and the arguments.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_CFA_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|SPARC_STACK_BIAS
end_define

begin_comment
comment|/* When a parameter is passed in a register, stack space is still    allocated for it.    !v9: All 6 possible integer registers have backing store allocated.    v9: Only space for the arguments passed is allocated.  */
end_comment

begin_comment
comment|/* ??? Ideally, we'd use zero here (as the minimum), but zero has special    meaning to the backend.  Further, we need to be able to detect if a    varargs/unprototyped function is called, as they may want to spill more    registers than we've provided space.  Ugly, ugly.  So for now we retain    all 6 slots even for v9.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|DECL
parameter_list|)
value|(6 * UNITS_PER_WORD)
end_define

begin_comment
comment|/* Keep the stack pointer constant throughout the function.    This is both an optimization and a necessity: longjmp    doesn't behave itself when the stack pointer moves within    the function!  */
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
comment|/* Some subroutine macros specific to this machine.    When !TARGET_FPU, put float return values in the general registers,    since we don't have any fp registers.  */
end_comment

begin_define
define|#
directive|define
name|BASE_RETURN_VALUE_REG
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARCH64							\    ? (TARGET_FPU&& FLOAT_MODE_P (MODE) ? 32 : 8)			\    : (((MODE) == SFmode || (MODE) == DFmode)&& TARGET_FPU ? 32 : 8))
end_define

begin_define
define|#
directive|define
name|BASE_OUTGOING_VALUE_REG
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARCH64						\    ? (TARGET_FPU&& FLOAT_MODE_P (MODE) ? 32			\       : TARGET_FLAT ? 8 : 24)					\    : (((MODE) == SFmode || (MODE) == DFmode)&& TARGET_FPU ? 32	\       : (TARGET_FLAT ? 8 : 24)))
end_define

begin_define
define|#
directive|define
name|BASE_PASSING_ARG_REG
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARCH64						\    ? (TARGET_FPU&& FLOAT_MODE_P (MODE) ? 32 : 8)		\    : 8)
end_define

begin_comment
comment|/* ??? FIXME -- seems wrong for v9 structure passing...  */
end_comment

begin_define
define|#
directive|define
name|BASE_INCOMING_ARG_REG
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_ARCH64						\    ? (TARGET_FPU&& FLOAT_MODE_P (MODE) ? 32			\       : TARGET_FLAT ? 8 : 24)					\    : (TARGET_FLAT ? 8 : 24))
end_define

begin_comment
comment|/* Define this macro if the target machine has "register windows".  This    C expression returns the register number as seen by the called function    corresponding to register number OUT as seen by the calling function.    Return OUT if register number OUT is not an outbound register.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_REGNO
parameter_list|(
name|OUT
parameter_list|)
define|\
value|((TARGET_FLAT || (OUT)< 8 || (OUT)> 15) ? (OUT) : (OUT) + 16)
end_define

begin_comment
comment|/* Define this macro if the target machine has "register windows".  This    C expression returns the register number as seen by the calling function    corresponding to register number IN as seen by the called function.    Return IN if register number IN is not an inbound register.  */
end_comment

begin_define
define|#
directive|define
name|OUTGOING_REGNO
parameter_list|(
name|IN
parameter_list|)
define|\
value|((TARGET_FLAT || (IN)< 24 || (IN)> 31) ? (IN) : (IN) - 16)
end_define

begin_comment
comment|/* Define this macro if the target machine has register windows.  This    C expression returns true if the register is call-saved but is in the    register window.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_REGNO
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(TARGET_FLAT ? 0 : (REGNO)>= 16&& (REGNO)<= 31)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_comment
comment|/* On SPARC the value is found in the first "output" register.  */
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
value|function_value ((VALTYPE), TYPE_MODE (VALTYPE), 1)
end_define

begin_comment
comment|/* But the called function leaves it in the first "input" register.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_OUTGOING_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|function_value ((VALTYPE), TYPE_MODE (VALTYPE), 0)
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
value|function_value (NULL_TREE, (MODE), 1)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.    On SPARC, the first "output" reg is used for integer values,    and the first floating point register is used for floating point values.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 8 || (N) == 32)
end_define

begin_comment
comment|/* Define the size of space to allocate for the return value of an    untyped_call.  */
end_comment

begin_define
define|#
directive|define
name|APPLY_RESULT_SIZE
value|16
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On SPARC, these are the "output" registers.  v9 also uses %f0-%f31.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|(TARGET_ARCH64 \  ? (((N)>= 8&& (N)<= 13) || ((N)>= 32&& (N)<= 63)) \  : ((N)>= 8&& (N)<= 13))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On SPARC (!v9), this is a single integer, which is a number of words    of arguments scanned so far (including the invisible argument,    if any, which holds the structure-value-address).    Thus 7 or more means all following args should go on the stack.     For v9, we also need to know whether a prototype is present.  */
end_comment

begin_struct
struct|struct
name|sparc_args
block|{
name|int
name|words
decl_stmt|;
comment|/* number of words passed so far */
name|int
name|prototype_p
decl_stmt|;
comment|/* non-zero if a prototype is present */
name|int
name|libcall_p
decl_stmt|;
comment|/* non-zero if a library call */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|struct sparc_args
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
define|\
value|init_cumulative_args (& (CUM), (FNTYPE), (LIBNAME), (INDIRECT));
end_define

begin_comment
comment|/* Update the data in CUM to advance over an argument    of mode MODE and data type TYPE.    TYPE is null for libcalls where that information may not be available.  */
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
value|function_arg_advance (& (CUM), (MODE), (TYPE), (NAMED))
end_define

begin_comment
comment|/* Nonzero if we do not know how to pass TYPE solely in registers.  */
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
value|((TYPE) != 0						\&& (TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST	\        || TREE_ADDRESSABLE (TYPE)))
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
value|function_arg (& (CUM), (MODE), (TYPE), (NAMED), 0)
end_define

begin_comment
comment|/* Define where a function finds its arguments.    This is different from FUNCTION_ARG because of register windows.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_INCOMING_ARG
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
value|function_arg (& (CUM), (MODE), (TYPE), (NAMED), 1)
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
value|function_arg_partial_nregs (& (CUM), (MODE), (TYPE), (NAMED))
end_define

begin_comment
comment|/* A C expression that indicates when an argument must be passed by reference.    If nonzero for an argument, a copy of that argument is made in memory and a    pointer to the argument is passed instead of the argument itself.    The pointer is passed in whatever way is appropriate for passing a pointer    to that type.  */
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
value|function_arg_pass_by_reference (& (CUM), (MODE), (TYPE), (NAMED))
end_define

begin_comment
comment|/* If defined, a C expression which determines whether, and in which direction,    to pad out an argument with extra space.  The value should be of type    `enum direction': either `upward' to pad above the argument,    `downward' to pad below, or `none' to inhibit padding.  */
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
define|\
value|function_arg_padding ((MODE), (TYPE))
end_define

begin_comment
comment|/* If defined, a C expression that gives the alignment boundary, in bits,    of an argument with the specified mode and type.  If it is not defined,    PARM_BOUNDARY is used for all arguments.    For sparc64, objects requiring 16 byte alignment are passed that way.  */
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
value|((TARGET_ARCH64					\&& (GET_MODE_ALIGNMENT (MODE) == 128		\       || ((TYPE)&& TYPE_ALIGN (TYPE) == 128)))	\  ? 128 : PARM_BOUNDARY)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|sparc_compare_op0
decl_stmt|,
modifier|*
name|sparc_compare_op1
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Generate the special assembly code needed to tell the assembler whatever    it might need to know about the return value of a function.     For Sparc assemblers, we need to output a .proc pseudo-op which conveys    information to the assembler relating to peephole optimization (done in    the assembler).  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_RESULT
parameter_list|(
name|FILE
parameter_list|,
name|RESULT
parameter_list|)
define|\
value|fprintf ((FILE), "\t.proc\t0%lo\n", sparc_type_code (TREE_TYPE (RESULT)))
end_define

begin_comment
comment|/* Output the special assembly code needed to tell the assembler some    register is used as global register variable.       SPARC 64bit psABI declares registers %g2 and %g3 as application    registers and %g6 and %g7 as OS registers.  Any object using them    should declare (for %g2/%g3 has to, for %g6/%g7 can) that it uses them    and how they are used (scratch or some global variable).    Linker will then refuse to link together objects which use those    registers incompatibly.     Unless the registers are used for scratch, two different global    registers cannot be declared to the same name, so in the unlikely    case of a global register variable occupying more than one register    we prefix the second and following registers with .gnu.part1. etc.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|sparc_hard_reg_printed
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_REGISTER_PSEUDO_OP
end_ifdef

begin_define
define|#
directive|define
name|ASM_DECLARE_REGISTER_GLOBAL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|REGNO
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   if (TARGET_ARCH64)							\     {									\       int end = HARD_REGNO_NREGS ((REGNO), DECL_MODE (decl)) + (REGNO); \       int reg;								\       for (reg = (REGNO); reg< 8&& reg< end; reg++)			\ 	if ((reg& ~1) == 2 || (reg& ~1) == 6)				\ 	  {								\ 	    if (reg == (REGNO))						\ 	      fprintf ((FILE), "\t.register\t%%g%d, %s\n", reg, (NAME)); \ 	    else							\ 	      fprintf ((FILE), "\t.register\t%%g%d, .gnu.part%d.%s\n",	\ 		       reg, reg - (REGNO), (NAME));			\ 	    sparc_hard_reg_printed[reg] = 1;				\ 	  }								\     }									\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|sparc_function_profiler(FILE, LABELNO)
end_define

begin_comment
comment|/* Set the name of the mcount function for the system.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_FUNCTION
value|"*mcount"
end_define

begin_escape
end_escape

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
define|\
value|(get_frame_size () != 0	\   || current_function_calls_alloca || current_function_outgoing_args_size)
end_define

begin_define
define|#
directive|define
name|DELAY_SLOTS_FOR_EPILOGUE
define|\
value|(TARGET_FLAT ? sparc_flat_epilogue_delay_slots () : 1)
end_define

begin_define
define|#
directive|define
name|ELIGIBLE_FOR_EPILOGUE_DELAY
parameter_list|(
name|trial
parameter_list|,
name|slots_filled
parameter_list|)
define|\
value|(TARGET_FLAT ? sparc_flat_eligible_for_epilogue_delay (trial, slots_filled) \    : eligible_for_epilogue_delay (trial, slots_filled))
end_define

begin_comment
comment|/* Define registers used by the epilogue and return instruction.  */
end_comment

begin_define
define|#
directive|define
name|EPILOGUE_USES
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(!TARGET_FLAT&& REGNO == 31)
end_define

begin_escape
end_escape

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|(TARGET_ARCH64 ? 32 : 16)
end_define

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGNMENT
value|128
end_define

begin_comment
comment|/* 16 bytes */
end_comment

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
value|if (TARGET_ARCH64)						\       sparc64_initialize_trampoline (TRAMP, FNADDR, CXT);	\     else							\       sparc_initialize_trampoline (TRAMP, FNADDR, CXT)
end_define

begin_escape
end_escape

begin_comment
comment|/* Generate necessary RTL for __builtin_saveregs().  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_SAVEREGS
parameter_list|()
value|sparc_builtin_saveregs ()
end_define

begin_comment
comment|/* Implement `va_start' for varargs and stdarg.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_START
parameter_list|(
name|stdarg
parameter_list|,
name|valist
parameter_list|,
name|nextarg
parameter_list|)
define|\
value|sparc_va_start (stdarg, valist, nextarg)
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
value|sparc_va_arg (valist, type)
end_define

begin_comment
comment|/* Define this macro if the location where a function argument is passed    depends on whether or not it is a named argument.     This macro controls how the NAMED argument to FUNCTION_ARG    is set for varargs and stdarg functions.  With this macro defined,    the NAMED argument is always true for named arguments, and false for    unnamed arguments.  If this is not defined, but SETUP_INCOMING_VARARGS    is defined, then all arguments are treated as named.  Otherwise, all named    arguments except the last are treated as named.    For the v9 we want NAMED to mean what it says it means.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ARGUMENT_NAMING
value|TARGET_V9
end_define

begin_comment
comment|/* We do not allow sibling calls if -mflat, nor    we do not allow indirect calls to be optimized into sibling calls.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_OK_FOR_SIBCALL
parameter_list|(
name|DECL
parameter_list|)
value|(DECL&& ! TARGET_FLAT)
end_define

begin_comment
comment|/* Generate RTL to flush the register windows so as to make arbitrary frames    available.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_FRAME_ADDRESSES
parameter_list|()
define|\
value|emit_insn (gen_flush_register_windows ())
end_define

begin_comment
comment|/* Given an rtx for the address of a frame,    return an rtx for the address of the word in the frame    that holds the dynamic chain--the previous frame's address.    ??? -mflat support? */
end_comment

begin_define
define|#
directive|define
name|DYNAMIC_CHAIN_ADDRESS
parameter_list|(
name|frame
parameter_list|)
value|plus_constant (frame, 14 * UNITS_PER_WORD)
end_define

begin_comment
comment|/* The return address isn't on the stack, it is in a register, so we can't    access it from the current frame pointer.  We can access it from the    previous frame pointer though by reading a value from the register window    save area.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_IN_PREVIOUS_FRAME
end_define

begin_comment
comment|/* This is the offset of the return address to the true next instruction to be    executed for the current function.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_OFFSET
define|\
value|(8 + 4 * (! TARGET_ARCH64&& current_function_returns_struct))
end_define

begin_comment
comment|/* The current return address is in %i7.  The return address of anything    farther back is in the register window save area at [%fp+60].  */
end_comment

begin_comment
comment|/* ??? This ignores the fact that the actual return address is +8 for normal    returns, and +12 for structure returns.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_RTX
parameter_list|(
name|count
parameter_list|,
name|frame
parameter_list|)
define|\
value|((count == -1)				\    ? gen_rtx_REG (Pmode, 31)			\    : gen_rtx_MEM (Pmode,			\ 		  memory_address (Pmode, plus_constant (frame, \ 							15 * UNITS_PER_WORD))))
end_define

begin_comment
comment|/* Before the prologue, the return address is %o7 + 8.  OK, sometimes it's    +12, but always using +8 is close enough for frame unwind purposes.    Actually, just using %o7 is close enough for unwinding, but %o7+8    is something you can return to.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
define|\
value|plus_constant (gen_rtx_REG (word_mode, 15), 8)
end_define

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|DWARF_FRAME_REGNUM (15)
end_define

begin_comment
comment|/* The offset from the incoming value of %sp to the top of the stack frame    for the current function.  On sparc64, we have to account for the stack    bias if present.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_FRAME_SP_OFFSET
value|SPARC_STACK_BIAS
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
value|((N)< 4 ? (N) + 24 : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|EH_RETURN_STACKADJ_RTX
value|gen_rtx_REG (Pmode, 1)
end_define

begin_comment
comment|/* %g1 */
end_comment

begin_define
define|#
directive|define
name|EH_RETURN_HANDLER_RTX
value|gen_rtx_REG (Pmode, 31)
end_define

begin_comment
comment|/* %i7 */
end_comment

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.     If assembler and linker properly support .uaword %r_disp32(foo),    then use PC relative 32-bit relocations instead of absolute relocs    for shared libraries.  On sparc64, use pc relative 32-bit relocs even    for binaries, to save memory.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_SPARC_UA_PCREL
end_ifdef

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
value|(flag_pic								\    ? (GLOBAL ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel | DW_EH_PE_sdata4\    : ((TARGET_ARCH64&& ! GLOBAL)					\       ? (DW_EH_PE_pcrel | DW_EH_PE_sdata4)				\       : DW_EH_PE_absptr))
end_define

begin_comment
comment|/* Emit a PC-relative relocation.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DWARF_PCREL
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|do {							\     fputs (integer_asm_op (SIZE, FALSE), FILE);		\     fprintf (FILE, "%%r_disp%d(", SIZE * 8);		\     assemble_name (FILE, LABEL);			\     fputc (')', FILE);					\   } while (0)
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
value|((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< (unsigned)32)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< (unsigned)32)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FP_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((unsigned) (REGNO) - 32< (TARGET_V9 ? (unsigned)64 : (unsigned)32)) \    || ((unsigned) reg_renumber[REGNO] - 32< (TARGET_V9 ? (unsigned)64 : (unsigned)32)))
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_CCFP_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(TARGET_V9 \&& (((unsigned) (REGNO) - 96< (unsigned)4) \       || ((unsigned) reg_renumber[REGNO] - 96< (unsigned)4)))
end_define

begin_comment
comment|/* Now macros that check whether X is a register and also,    strictly, whether it is in a specified class.     These macros are specific to the SPARC, and may be used only    in code for printing assembler insns and in conditions for    define_optimization.  */
end_comment

begin_comment
comment|/* 1 if X is an fp register.  */
end_comment

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REGNO_OK_FOR_FP_P (REGNO (X)))
end_define

begin_comment
comment|/* Is X, a REG, an in or global register?  i.e. is regno 0..7 or 24..31 */
end_comment

begin_define
define|#
directive|define
name|IN_OR_GLOBAL_P
parameter_list|(
name|X
parameter_list|)
value|(REGNO (X)< 8 || (REGNO (X)>= 24&& REGNO (X)<= 31))
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
comment|/* Recognize any constant value that is a valid address.    When PIC, we do not accept an address that would require a scratch reg    to load into a register.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF		\    || GET_CODE (X) == CONST_INT || GET_CODE (X) == HIGH			\    || (GET_CODE (X) == CONST						\&& ! (flag_pic&& pic_address_needs_scratch (X))))
end_define

begin_comment
comment|/* Define this, so that when PIC, reload won't try to reload invalid    addresses which require two reload registers.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
value|(! pic_address_needs_scratch (X))
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    Anything can be made to work except floating point constants.    If TARGET_VIS, 0.0 can be made to work as well.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) != CONST_DOUBLE || GET_MODE (X) == VOIDmode || 		\    (TARGET_VIS&&							\     (GET_MODE (X) == SFmode || GET_MODE (X) == DFmode ||		\      GET_MODE (X) == TFmode)&&						\     fp_zero_operand (X, GET_MODE (X))))
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Source files for reload pass need to be strict.    After reload, it makes no difference, since pseudo regs have    been eliminated by then.  */
end_comment

begin_comment
comment|/* Optional extra constraints for this machine.     'Q' handles floating point constants which can be moved into        an integer register with a single sethi instruction.     'R' handles floating point constants which can be moved into        an integer register with a single mov instruction.     'S' handles floating point constants which can be moved into        an integer register using a high/lo_sum sequence.     'T' handles memory addresses where the alignment is known to        be at least 8 bytes.     `U' handles all pseudo registers or a hard even numbered        integer register, needed for ldd/std instructions.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_BASE
parameter_list|(
name|OP
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'Q' ? fp_sethi_p(OP)        \     : (C) == 'R' ? fp_mov_p(OP)        \     : (C) == 'S' ? fp_high_losum_p(OP) \     : 0)
end_define

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
define|\
value|(((unsigned) REGNO (X)) - 32>= (FIRST_PSEUDO_REGISTER - 32))
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
value|(((unsigned) REGNO (X)) - 32>= (FIRST_PSEUDO_REGISTER - 32))
end_define

begin_comment
comment|/* 'T', 'U' are for aligned memory loads which aren't needed for arch64.  */
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
value|(EXTRA_CONSTRAINT_BASE(OP, C)                        \     || ((! TARGET_ARCH64&& (C) == 'T')			\         ? (mem_min_alignment (OP, 8))			\         : ((! TARGET_ARCH64&& (C) == 'U')		\             ? (register_ok_for_ldd (OP))		\             : 0)))
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
name|EXTRA_CONSTRAINT
parameter_list|(
name|OP
parameter_list|,
name|C
parameter_list|)
define|\
value|(EXTRA_CONSTRAINT_BASE(OP, C)                        \     || ((! TARGET_ARCH64&& (C) == 'T')			\         ? mem_min_alignment (OP, 8)&& strict_memory_address_p (Pmode, XEXP (OP, 0)) \         : ((! TARGET_ARCH64&& (C) == 'U')		\            ? (GET_CODE (OP) == REG			\&& (REGNO (OP)< FIRST_PSEUDO_REGISTER	\ 	          || reg_renumber[REGNO (OP)]>= 0)	\&& register_ok_for_ldd (OP))		\            : 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Should gcc use [%reg+%lo(xx)+offset] addresses?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_OFFSETABLE_LO10
end_ifdef

begin_define
define|#
directive|define
name|USE_AS_OFFSETABLE_LO10
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE_AS_OFFSETABLE_LO10
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On SPARC, the actual legitimate addresses must be REG+REG or REG+SMALLINT    ordinarily.  This changes a bit when generating PIC.     If you change this, execute "rm explow.o recog.o reload.o".  */
end_comment

begin_define
define|#
directive|define
name|RTX_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\   || (GET_CODE (X) == SUBREG						\&& GET_CODE (SUBREG_REG (X)) == REG				\&& REG_OK_FOR_BASE_P (SUBREG_REG (X))))
end_define

begin_define
define|#
directive|define
name|RTX_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == REG&& REG_OK_FOR_INDEX_P (X))			\   || (GET_CODE (X) == SUBREG						\&& GET_CODE (SUBREG_REG (X)) == REG				\&& REG_OK_FOR_INDEX_P (SUBREG_REG (X))))
end_define

begin_define
define|#
directive|define
name|RTX_OK_FOR_OFFSET_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT&& INTVAL (X)>= -0x1000&& INTVAL (X)< 0x1000 - 8)
end_define

begin_define
define|#
directive|define
name|RTX_OK_FOR_OLO10_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT&& INTVAL (X)>= -0x1000&& INTVAL (X)< 0xc00 - 8)
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
name|ADDR
parameter_list|)
define|\
value|{ if (RTX_OK_FOR_BASE_P (X))				\     goto ADDR;						\   else if (GET_CODE (X) == PLUS)			\     {							\       register rtx op0 = XEXP (X, 0);			\       register rtx op1 = XEXP (X, 1);			\       if (flag_pic&& op0 == pic_offset_table_rtx)	\ 	{						\ 	  if (RTX_OK_FOR_BASE_P (op1))			\ 	    goto ADDR;					\ 	  else if (flag_pic == 1			\&& GET_CODE (op1) != REG		\&& GET_CODE (op1) != LO_SUM		\&& GET_CODE (op1) != MEM		\&& (GET_CODE (op1) != CONST_INT	\ 		       || SMALL_INT (op1)))		\ 	    goto ADDR;					\ 	}						\       else if (RTX_OK_FOR_BASE_P (op0))			\ 	{						\ 	  if ((RTX_OK_FOR_INDEX_P (op1)			\
comment|/* We prohibit REG + REG for TFmode when	\ 		 there are no instructions which accept	\ 		 REG+REG instructions.  We do this	\ 		 because REG+REG is not an offsetable	\ 		 address.  If we get the situation	\ 		 in reload where source and destination	\ 		 of a movtf pattern are both MEMs with	\ 		 REG+REG address, then only one of them	\ 		 gets converted to an offsetable	\ 		 address.  */
value|\&& (MODE != TFmode			\ 		   || (TARGET_FPU&& TARGET_ARCH64	\&& TARGET_V9			\&& TARGET_HARD_QUAD))		\
comment|/* We prohibit REG + REG on ARCH32 if	\ 		 not optimizing for DFmode/DImode	\ 		 because then mem_min_alignment is	\ 		 likely to be zero after reload and the \ 		 forced split would lack a matching	\ 		 splitter pattern.  */
value|\&& (TARGET_ARCH64 || optimize		\ 		   || (MODE != DFmode			\&& MODE != DImode)))		\ 	      || RTX_OK_FOR_OFFSET_P (op1))		\ 	    goto ADDR;					\ 	}						\       else if (RTX_OK_FOR_BASE_P (op1))			\ 	{						\ 	  if ((RTX_OK_FOR_INDEX_P (op0)			\
comment|/* See the previous comment.  */
value|\&& (MODE != TFmode			\ 		  || (TARGET_FPU&& TARGET_ARCH64	\&& TARGET_V9			\&& TARGET_HARD_QUAD))		\&& (TARGET_ARCH64 || optimize		\ 		   || (MODE != DFmode			\&& MODE != DImode)))		\ 	      || RTX_OK_FOR_OFFSET_P (op0))		\ 	    goto ADDR;					\ 	}						\       else if (USE_AS_OFFSETABLE_LO10			\&& GET_CODE (op0) == LO_SUM		\&& TARGET_ARCH64				\&& ! TARGET_CM_MEDMID			\&& RTX_OK_FOR_OLO10_P (op1))		\ 	{						\ 	  register rtx op00 = XEXP (op0, 0);		\ 	  register rtx op01 = XEXP (op0, 1);		\ 	  if (RTX_OK_FOR_BASE_P (op00)			\&& CONSTANT_P (op01))			\ 	    goto ADDR;					\ 	}						\       else if (USE_AS_OFFSETABLE_LO10			\&& GET_CODE (op1) == LO_SUM		\&& TARGET_ARCH64				\&& ! TARGET_CM_MEDMID			\&& RTX_OK_FOR_OLO10_P (op0))		\ 	{						\ 	  register rtx op10 = XEXP (op1, 0);		\ 	  register rtx op11 = XEXP (op1, 1);		\ 	  if (RTX_OK_FOR_BASE_P (op10)			\&& CONSTANT_P (op11))			\ 	    goto ADDR;					\ 	}						\     }							\   else if (GET_CODE (X) == LO_SUM)			\     {							\       register rtx op0 = XEXP (X, 0);			\       register rtx op1 = XEXP (X, 1);			\       if (RTX_OK_FOR_BASE_P (op0)			\&& CONSTANT_P (op1)				\
comment|/* We can't allow TFmode, because an offset	\ 	     greater than or equal to the alignment (8)	\ 	     may cause the LO_SUM to overflow if !v9.  */
value|\&& (MODE != TFmode || TARGET_V9))		\ 	goto ADDR;					\     }							\   else if (GET_CODE (X) == CONST_INT&& SMALL_INT (X))	\     goto ADDR;						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.  */
end_comment

begin_comment
comment|/* On SPARC, change REG+N into REG+REG, and REG+(X*Y) into REG+REG.  */
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
value|{ rtx sparc_x = (X);						\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == MULT)	\     (X) = gen_rtx_PLUS (Pmode, XEXP (X, 1),			\ 			force_operand (XEXP (X, 0), NULL_RTX));	\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 1)) == MULT)	\     (X) = gen_rtx_PLUS (Pmode, XEXP (X, 0),			\ 			force_operand (XEXP (X, 1), NULL_RTX));	\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == PLUS)	\     (X) = gen_rtx_PLUS (Pmode, force_operand (XEXP (X, 0), NULL_RTX),\ 			XEXP (X, 1));				\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 1)) == PLUS)	\     (X) = gen_rtx_PLUS (Pmode, XEXP (X, 0),			\ 			force_operand (XEXP (X, 1), NULL_RTX));	\   if (sparc_x != (X)&& memory_address_p (MODE, X))		\     goto WIN;							\   if (flag_pic) (X) = legitimize_pic_address (X, MODE, 0);	\   else if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 1)))	\     (X) = gen_rtx_PLUS (Pmode, XEXP (X, 0),			\ 			copy_to_mode_reg (Pmode, XEXP (X, 1)));	\   else if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 0)))	\     (X) = gen_rtx_PLUS (Pmode, XEXP (X, 1),			\ 			copy_to_mode_reg (Pmode, XEXP (X, 0)));	\   else if (GET_CODE (X) == SYMBOL_REF || GET_CODE (X) == CONST	\ 	   || GET_CODE (X) == LABEL_REF)			\     (X) = copy_to_suggested_reg (X, NULL_RTX, Pmode); 		\   if (memory_address_p (MODE, X))				\     goto WIN; }
end_define

begin_comment
comment|/* Try a machine-dependent way of reloading an illegitimate address    operand.  If we find one, push the reload and jump to WIN.  This    macro is used in only one place: `find_reloads_address' in reload.c.     For Sparc 32, we wish to handle addresses by splitting them into    HIGH+LO_SUM pairs, retaining the LO_SUM in the memory reference.     This cuts the number of extra insns by one.     Do nothing when generating PIC code and the address is a    symbolic operand or requires a scratch register.  */
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
value|do {                                                                    \
comment|/* Decompose SImode constants into hi+lo_sum.  We do have to 		\      rerecognize what we produce, so be careful.  */
value|\   if (CONSTANT_P (X)							\&& (MODE != TFmode || TARGET_V9)					\&& GET_MODE (X) == SImode						\&& GET_CODE (X) != LO_SUM&& GET_CODE (X) != HIGH			\&& ! (flag_pic							\&& (symbolic_operand (X, Pmode)				\ 		|| pic_address_needs_scratch (X))))			\     {									\       X = gen_rtx_LO_SUM (GET_MODE (X),					\ 			  gen_rtx_HIGH (GET_MODE (X), X), X);		\       push_reload (XEXP (X, 0), NULL_RTX,&XEXP (X, 0), NULL,		\                    BASE_REG_CLASS, GET_MODE (X), VOIDmode, 0, 0,	\                    OPNUM, TYPE);					\       goto WIN;								\     }									\
comment|/* ??? 64-bit reloads.  */
value|\ } while (0)
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the SPARC this is never true.  */
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
end_define

begin_comment
comment|/* If we are referencing a function make the SYMBOL_REF special.    In the Embedded Medium/Anywhere code model, %g4 points to the data segment    so we must not add it to function addresses.  */
end_comment

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|do {							\     if (TARGET_CM_EMBMEDANY&& TREE_CODE (DECL) == FUNCTION_DECL) \       SYMBOL_REF_FLAG (XEXP (DECL_RTL (DECL), 0)) = 1;	\   } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.  */
end_comment

begin_comment
comment|/* If we ever implement any of the full models (such as CM_FULLANY),    this has to be DImode in that case */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_SUBSECTION_ORDERING
end_ifdef

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
define|\
value|(! TARGET_PTR64 ? SImode : flag_pic ? SImode : TARGET_CM_MEDLOW ? SImode : DImode)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If assembler does not have working .subsection -1, we use DImode for pic, as otherwise    we have to sign extend which slows things down.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
define|\
value|(! TARGET_PTR64 ? SImode : flag_pic ? DImode : TARGET_CM_MEDLOW ? SImode : DImode)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|8
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Sun 4 has matherr, so this is no good.  */
end_comment

begin_comment
comment|/* This is the value of the error code EDOM for this machine,    used by the sqrt instruction.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_EDOM
value|33
end_define

begin_comment
comment|/* This is how to refer to the variable errno.  */
end_comment

begin_define
define|#
directive|define
name|GEN_ERRNO_RTX
define|\
value|gen_rtx_MEM (SImode, gen_rtx_SYMBOL_REF (Pmode, "errno"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

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
comment|/* Nonzero if access to memory by bytes is slow and undesirable.    For RISC chips, it means that access to memory by bytes is no    better than access by words when possible, so grab a whole word    and maybe make use of that.  */
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
comment|/* When a prototype says `char' or `short', really pass an `int'.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
value|(TARGET_ARCH32)
end_define

begin_comment
comment|/* Define this to be nonzero if shift instructions ignore all but the low-order    few bits.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
value|1
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
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|(TARGET_ARCH64 ? DImode : SImode)
end_define

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Add any extra modes needed to represent the condition code.     On the Sparc, we have a "no-overflow" mode which is used when an add or    subtract insn is used to set the condition code.  Different branches are    used in this case for some operations.     We also have two modes to indicate that the relevant condition code is    in the floating-point condition code register.  One for comparisons which    will generate an exception if the result is unordered (CCFPEmode) and    one for comparisons which will never trap (CCFPmode).     CCXmode and CCX_NOOVmode are only used by v9.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
define|\
value|CC(CCXmode,	     "CCX")		\     CC(CC_NOOVmode,  "CC_NOOV")		\     CC(CCX_NOOVmode, "CCX_NOOV")	\     CC(CCFPmode,     "CCFP")		\     CC(CCFPEmode,    "CCFPE")
end_define

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.  For floating-point,    CCFP[E]mode is used.  CC_NOOVmode should be used when the first operand    is a PLUS, MINUS, NEG, or ASHIFT.  CCmode should be used when no special    processing is needed.  */
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
value|select_cc_mode ((OP), (X), (Y))
end_define

begin_comment
comment|/* Return non-zero if MODE implies a floating point inequality can be    reversed.  For Sparc this is always true because we have a full    compliment of ordered and unordered comparisons, but until generic    code knows how to reverse it correctly we keep the old definition.  */
end_comment

begin_define
define|#
directive|define
name|REVERSIBLE_CC_MODE
parameter_list|(
name|MODE
parameter_list|)
value|((MODE) != CCFPEmode&& (MODE) != CCFPmode)
end_define

begin_comment
comment|/* A function address in a call instruction for indexing purposes.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|Pmode
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
comment|/* alloca should avoid clobbering the old register save area.  */
end_comment

begin_define
define|#
directive|define
name|SETJMP_VIA_SAVE_AREA
end_define

begin_comment
comment|/* Define subroutines to call to handle multiply and divide.    Use the subroutines that Sun's library provides.    The `*' prevents an underscore from being prepended by the compiler.  */
end_comment

begin_define
define|#
directive|define
name|DIVSI3_LIBCALL
value|"*.div"
end_define

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"*.udiv"
end_define

begin_define
define|#
directive|define
name|MODSI3_LIBCALL
value|"*.rem"
end_define

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"*.urem"
end_define

begin_comment
comment|/* .umul is a little faster than .mul.  */
end_comment

begin_define
define|#
directive|define
name|MULSI3_LIBCALL
value|"*.umul"
end_define

begin_comment
comment|/* Define library calls for quad FP operations.  These are all part of the    SPARC 32bit ABI.  */
end_comment

begin_define
define|#
directive|define
name|ADDTF3_LIBCALL
value|"_Q_add"
end_define

begin_define
define|#
directive|define
name|SUBTF3_LIBCALL
value|"_Q_sub"
end_define

begin_define
define|#
directive|define
name|NEGTF2_LIBCALL
value|"_Q_neg"
end_define

begin_define
define|#
directive|define
name|MULTF3_LIBCALL
value|"_Q_mul"
end_define

begin_define
define|#
directive|define
name|DIVTF3_LIBCALL
value|"_Q_div"
end_define

begin_define
define|#
directive|define
name|FLOATSITF2_LIBCALL
value|"_Q_itoq"
end_define

begin_define
define|#
directive|define
name|FIX_TRUNCTFSI2_LIBCALL
value|"_Q_qtoi"
end_define

begin_define
define|#
directive|define
name|FIXUNS_TRUNCTFSI2_LIBCALL
value|"_Q_qtou"
end_define

begin_define
define|#
directive|define
name|EXTENDSFTF2_LIBCALL
value|"_Q_stoq"
end_define

begin_define
define|#
directive|define
name|TRUNCTFSF2_LIBCALL
value|"_Q_qtos"
end_define

begin_define
define|#
directive|define
name|EXTENDDFTF2_LIBCALL
value|"_Q_dtoq"
end_define

begin_define
define|#
directive|define
name|TRUNCTFDF2_LIBCALL
value|"_Q_qtod"
end_define

begin_define
define|#
directive|define
name|EQTF2_LIBCALL
value|"_Q_feq"
end_define

begin_define
define|#
directive|define
name|NETF2_LIBCALL
value|"_Q_fne"
end_define

begin_define
define|#
directive|define
name|GTTF2_LIBCALL
value|"_Q_fgt"
end_define

begin_define
define|#
directive|define
name|GETF2_LIBCALL
value|"_Q_fge"
end_define

begin_define
define|#
directive|define
name|LTTF2_LIBCALL
value|"_Q_flt"
end_define

begin_define
define|#
directive|define
name|LETF2_LIBCALL
value|"_Q_fle"
end_define

begin_comment
comment|/* We can define the TFmode sqrt optab only if TARGET_FPU.  This is because    with soft-float, the SFmode and DFmode sqrt instructions will be absent,    and the compiler will notice and try to use the TFmode sqrt instruction    for calls to the builtin function sqrt, but this fails.  */
end_comment

begin_define
define|#
directive|define
name|INIT_TARGET_OPTABS
define|\
value|do {									\     if (TARGET_ARCH32)							\       {									\ 	add_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (ADDTF3_LIBCALL);				\ 	sub_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (SUBTF3_LIBCALL);				\ 	neg_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (NEGTF2_LIBCALL);				\ 	smul_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (MULTF3_LIBCALL);				\ 	sdiv_optab->handlers[(int) TFmode].libfunc			\ 	  = init_one_libfunc (DIVTF3_LIBCALL);				\ 	eqtf2_libfunc = init_one_libfunc (EQTF2_LIBCALL);		\ 	netf2_libfunc = init_one_libfunc (NETF2_LIBCALL);		\ 	gttf2_libfunc = init_one_libfunc (GTTF2_LIBCALL);		\ 	getf2_libfunc = init_one_libfunc (GETF2_LIBCALL);		\ 	lttf2_libfunc = init_one_libfunc (LTTF2_LIBCALL);		\ 	letf2_libfunc = init_one_libfunc (LETF2_LIBCALL);		\ 	trunctfsf2_libfunc = init_one_libfunc (TRUNCTFSF2_LIBCALL);	\ 	trunctfdf2_libfunc = init_one_libfunc (TRUNCTFDF2_LIBCALL);	\ 	extendsftf2_libfunc = init_one_libfunc (EXTENDSFTF2_LIBCALL);	\ 	extenddftf2_libfunc = init_one_libfunc (EXTENDDFTF2_LIBCALL);	\ 	floatsitf_libfunc = init_one_libfunc (FLOATSITF2_LIBCALL);	\ 	fixtfsi_libfunc = init_one_libfunc (FIX_TRUNCTFSI2_LIBCALL);	\ 	fixunstfsi_libfunc						\ 	  = init_one_libfunc (FIXUNS_TRUNCTFSI2_LIBCALL);		\ 	if (TARGET_FPU)							\ 	  sqrt_optab->handlers[(int) TFmode].libfunc			\ 	    = init_one_libfunc ("_Q_sqrt");				\       }									\     INIT_SUBTARGET_OPTABS;						\   } while (0)
end_define

begin_comment
comment|/* This is meant to be redefined in the host dependent files */
end_comment

begin_define
define|#
directive|define
name|INIT_SUBTARGET_OPTABS
end_define

begin_comment
comment|/* Nonzero if a floating point comparison library call for    mode MODE that will return a boolean value.  Zero if one    of the libgcc2 functions is used.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_LIB_COMPARE_RETURNS_BOOL
parameter_list|(
name|MODE
parameter_list|,
name|COMPARISON
parameter_list|)
value|((MODE) == TFmode)
end_define

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX    whose rtx-code is CODE.  The body of this macro is a portion    of a switch statement.  If the code is computed here,    return it with a return statement.  Otherwise, break from the switch.  */
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
value|case CONST_INT:						\     if (INTVAL (RTX)< 0x1000&& INTVAL (RTX)>= -0x1000)	\       return 0;							\   case HIGH:							\     return 2;							\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 4;							\   case CONST_DOUBLE:						\     if (GET_MODE (RTX) == DImode)				\       if ((XINT (RTX, 3) == 0					\&& (unsigned) XINT (RTX, 2)< 0x1000)		\ 	  || (XINT (RTX, 3) == -1				\&& XINT (RTX, 2)< 0				\&& XINT (RTX, 2)>= -0x1000))			\ 	return 0;						\     return 8;
end_define

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
value|1
end_define

begin_comment
comment|/* Compute extra cost of moving data between one register class    and another.  */
end_comment

begin_define
define|#
directive|define
name|GENERAL_OR_I64
parameter_list|(
name|C
parameter_list|)
value|((C) == GENERAL_REGS || (C) == I64_REGS)
end_define

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
value|(((FP_REG_CLASS_P (CLASS1)&& GENERAL_OR_I64 (CLASS2)) \     || (GENERAL_OR_I64 (CLASS1)&& FP_REG_CLASS_P (CLASS2)) \     || (CLASS1) == FPCC_REGS || (CLASS2) == FPCC_REGS)		\    ? (sparc_cpu == PROCESSOR_ULTRASPARC ? 12 : 6) : 2)
end_define

begin_comment
comment|/* Provide the costs of a rtl expression.  This is in the body of a    switch on CODE.  The purpose for the cost of MULT is to encourage    `synth_mult' to find a synthetic multiply when reasonable.     If we need more than 12 insns to do a multiply, then go out-of-line,    since the call overhead will be< 10% of the cost of the multiply.  */
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
value|case MULT:						\     if (sparc_cpu == PROCESSOR_ULTRASPARC)		\       return (GET_MODE (X) == DImode ?			\               COSTS_N_INSNS (34) : COSTS_N_INSNS (19));	\     return TARGET_HARD_MUL ? COSTS_N_INSNS (5) : COSTS_N_INSNS (25); \   case DIV:						\   case UDIV:						\   case MOD:						\   case UMOD:						\     if (sparc_cpu == PROCESSOR_ULTRASPARC)		\       return (GET_MODE (X) == DImode ?			\               COSTS_N_INSNS (68) : COSTS_N_INSNS (37));	\     return COSTS_N_INSNS (25);				\
comment|/* Make FLOAT and FIX more expensive than CONST_DOUBLE,\      so that cse will favor the latter.  */
value|\   case FLOAT:						\   case FIX:						\     return 19;
end_define

begin_comment
comment|/* Conditional branches with empty delay slots have a length of two.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_INSN_LENGTH
parameter_list|(
name|INSN
parameter_list|,
name|LENGTH
parameter_list|)
define|\
value|do {									\   if (GET_CODE (INSN) == CALL_INSN					\       || (GET_CODE (INSN) == JUMP_INSN&& ! simplejump_p (insn)))	\     LENGTH += 1;							\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|file
parameter_list|)
end_define

begin_comment
comment|/* A C string constant describing how to begin a comment in the target    assembler language.  The compiler assumes that the comment will end at    the end of the line.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"!"
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
comment|/* ??? Try to make the style consistent here (_OP?).  */
end_comment

begin_define
define|#
directive|define
name|ASM_FLOAT
value|".single"
end_define

begin_define
define|#
directive|define
name|ASM_DOUBLE
value|".double"
end_define

begin_define
define|#
directive|define
name|ASM_LONGDOUBLE
value|".xxx"
end_define

begin_comment
comment|/* ??? Not known (or used yet).  */
end_comment

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%g0", "%g1", "%g2", "%g3", "%g4", "%g5", "%g6", "%g7",		\  "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%sp", "%o7",		\  "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", "%l7",		\  "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%fp", "%i7",		\  "%f0", "%f1", "%f2", "%f3", "%f4", "%f5", "%f6", "%f7",		\  "%f8", "%f9", "%f10", "%f11", "%f12", "%f13", "%f14", "%f15",		\  "%f16", "%f17", "%f18", "%f19", "%f20", "%f21", "%f22", "%f23",	\  "%f24", "%f25", "%f26", "%f27", "%f28", "%f29", "%f30", "%f31",	\  "%f32", "%f33", "%f34", "%f35", "%f36", "%f37", "%f38", "%f39",	\  "%f40", "%f41", "%f42", "%f43", "%f44", "%f45", "%f46", "%f47",	\  "%f48", "%f49", "%f50", "%f51", "%f52", "%f53", "%f54", "%f55",	\  "%f56", "%f57", "%f58", "%f59", "%f60", "%f61", "%f62", "%f63",	\  "%fcc0", "%fcc1", "%fcc2", "%fcc3", "%icc"}
end_define

begin_comment
comment|/* Define additional names for use in asm clobbers and asm declarations.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{{"ccr", SPARC_ICC_REG}, {"cc", SPARC_ICC_REG}}
end_define

begin_comment
comment|/* On Sun 4, this limit is 2048.  We use 1000 to be safe, since the length    can run past this up to a continuation point.  Once we used 1500, but    a single entry in C++ can run more than 500 bytes, due to the length of    mangled symbol names.  dbxout.c should really be fixed to do    continuations when they are actually needed instead of trying to    guess...  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|1000
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
value|do { fputs ("\t.global ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols.  */
end_comment

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
end_define

begin_comment
comment|/* This is how to output a definition of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
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
value|fprintf (FILE, "%s%d:\n", PREFIX, NUM)
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
value|sprintf ((LABEL), "*%s%ld", (PREFIX), (long)(NUM))
end_define

begin_comment
comment|/* This is how we hook in and defer the case-vector until the end of    the function.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC
parameter_list|(
name|LAB
parameter_list|,
name|VEC
parameter_list|)
define|\
value|sparc_defer_case_vector ((LAB),(VEC), 0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_VEC
parameter_list|(
name|LAB
parameter_list|,
name|VEC
parameter_list|)
define|\
value|sparc_defer_case_vector ((LAB),(VEC), 1)
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
value|do {									\   char label[30];							\   ASM_GENERATE_INTERNAL_LABEL (label, "L", VALUE);			\   if (CASE_VECTOR_MODE == SImode)					\     fprintf (FILE, "\t.word\t");					\   else									\     fprintf (FILE, "\t.xword\t");					\   assemble_name (FILE, label);						\   fputc ('\n', FILE);							\ } while (0)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (SPARC uses such vectors only when generating PIC.)  */
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
value|do {									\   char label[30];							\   ASM_GENERATE_INTERNAL_LABEL (label, "L", (VALUE));			\   if (CASE_VECTOR_MODE == SImode)					\     fprintf (FILE, "\t.word\t");					\   else									\     fprintf (FILE, "\t.xword\t");					\   assemble_name (FILE, label);						\   ASM_GENERATE_INTERNAL_LABEL (label, "L", (REL));			\   fputc ('-', FILE);							\   assemble_name (FILE, label);						\   fputc ('\n', FILE);							\ } while (0)
end_define

begin_comment
comment|/* This is what to output before and after case-vector (both    relative and absolute).  If .subsection -1 works, we put case-vectors    at the beginning of the current section.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_SUBSECTION_ORDERING
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf(FILE, "\t.subsection\t-1\n")
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf(FILE, "\t.previous\n")
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|if ((LOG) != 0)			\     fprintf (FILE, "\t.align %d\n", (1<<(LOG)))
end_define

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
value|fprintf (FILE, "\t.skip %u\n", (SIZE))
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
value|( fputs ("\t.common ", (FILE)),		\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,\"bss\"\n", (SIZE)))
end_define

begin_comment
comment|/* This says how to output an assembler line to define a local common    symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGNED
parameter_list|)
define|\
value|( fputs ("\t.reserve ", (FILE)),					\   assemble_name ((FILE), (NAME)),					\   fprintf ((FILE), ",%u,\"bss\",%u\n",					\ 	   (SIZE), ((ALIGNED) / BITS_PER_UNIT)))
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream    FILE the assembler definition of uninitialized global DECL named    NAME whose size is SIZE bytes and alignment is ALIGN bytes.    Try to use asm_output_aligned_bss to implement this macro.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {								\     fputs (".globl ", (FILE));					\     assemble_name ((FILE), (NAME));				\     fputs ("\n", (FILE));					\     ASM_OUTPUT_ALIGNED_LOCAL (FILE, NAME, SIZE, ALIGN);		\   } while (0)
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

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|"\t.ident\t"
end_define

begin_comment
comment|/* Output #ident as a .ident.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "%s\"%s\"\n", IDENT_ASM_OP, NAME);
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
value|do {									\   int reg = 0;								\ 									\   if (TARGET_ARCH64							\&& aggregate_value_p (TREE_TYPE (TREE_TYPE (FUNCTION))))		\     reg = 1;								\   if ((DELTA)>= 4096 || (DELTA)< -4096)				\     fprintf (FILE, "\tset\t%d, %%g1\n\tadd\t%%o%d, %%g1, %%o%d\n",	\ 	     (int)(DELTA), reg, reg);					\   else									\     fprintf (FILE, "\tadd\t%%o%d, %d, %%o%d\n", reg, (int)(DELTA), reg);\   fprintf (FILE, "\tor\t%%o7, %%g0, %%g1\n");				\   fprintf (FILE, "\tcall\t");						\   assemble_name (FILE, XSTR (XEXP (DECL_RTL (FUNCTION), 0), 0));	\   fprintf (FILE, ", 0\n");						\   fprintf (FILE, "\t or\t%%g1, %%g0, %%o7\n");				\ } while (0)
end_define

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|((CHAR) == '#' || (CHAR) == '*' || (CHAR) == '^' || (CHAR) == '(' || (CHAR) == '_')
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
value|{ register rtx base, index = 0;					\   int offset = 0;						\   register rtx addr = ADDR;					\   if (GET_CODE (addr) == REG)					\     fputs (reg_names[REGNO (addr)], FILE);			\   else if (GET_CODE (addr) == PLUS)				\     {								\       if (GET_CODE (XEXP (addr, 0)) == CONST_INT)		\ 	offset = INTVAL (XEXP (addr, 0)), base = XEXP (addr, 1);\       else if (GET_CODE (XEXP (addr, 1)) == CONST_INT)		\ 	offset = INTVAL (XEXP (addr, 1)), base = XEXP (addr, 0);\       else							\ 	base = XEXP (addr, 0), index = XEXP (addr, 1);		\       if (GET_CODE (base) == LO_SUM)				\ 	{							\ 	  if (! USE_AS_OFFSETABLE_LO10				\ 	      || TARGET_ARCH32					\ 	      || TARGET_CM_MEDMID)				\ 	    abort ();						\ 	  output_operand (XEXP (base, 0), 0);			\ 	  fputs ("+%lo(", FILE);				\ 	  output_address (XEXP (base, 1));			\ 	  fprintf (FILE, ")+%d", offset);			\ 	}							\       else							\ 	{							\ 	  fputs (reg_names[REGNO (base)], FILE);		\ 	  if (index == 0)					\ 	    fprintf (FILE, "%+d", offset);			\ 	  else if (GET_CODE (index) == REG)			\ 	    fprintf (FILE, "+%s", reg_names[REGNO (index)]);	\ 	  else if (GET_CODE (index) == SYMBOL_REF		\ 		   || GET_CODE (index) == CONST)		\ 	    fputc ('+', FILE), output_addr_const (FILE, index);	\ 	  else abort ();					\ 	}							\     }								\   else if (GET_CODE (addr) == MINUS				\&& GET_CODE (XEXP (addr, 1)) == LABEL_REF)		\     {								\       output_addr_const (FILE, XEXP (addr, 0));			\       fputs ("-(", FILE);					\       output_addr_const (FILE, XEXP (addr, 1));			\       fputs ("-.)", FILE);					\     }								\   else if (GET_CODE (addr) == LO_SUM)				\     {								\       output_operand (XEXP (addr, 0), 0);			\       if (TARGET_CM_MEDMID)					\         fputs ("+%l44(", FILE);					\       else							\         fputs ("+%lo(", FILE);					\       output_address (XEXP (addr, 1));				\       fputc (')', FILE);					\     }								\   else if (flag_pic&& GET_CODE (addr) == CONST			\&& GET_CODE (XEXP (addr, 0)) == MINUS		\&& GET_CODE (XEXP (XEXP (addr, 0), 1)) == CONST	\&& GET_CODE (XEXP (XEXP (XEXP (addr, 0), 1), 0)) == MINUS	\&& XEXP (XEXP (XEXP (XEXP (addr, 0), 1), 0), 1) == pc_rtx)	\     {								\       addr = XEXP (addr, 0);					\       output_addr_const (FILE, XEXP (addr, 0));			\
comment|/* Group the args of the second CONST in parenthesis.  */
value|\       fputs ("-(", FILE);					\
comment|/* Skip past the second CONST--it does nothing for us.  */
value|\       output_addr_const (FILE, XEXP (XEXP (addr, 1), 0));	\
comment|/* Close the parenthesis.  */
value|\       fputc (')', FILE);					\     }								\   else								\     {								\       output_addr_const (FILE, addr);				\     }								\ }
end_define

begin_comment
comment|/* Define the codes that are matched by predicates in sparc.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"reg_or_0_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}},		\ {"fp_zero_operand", {CONST_DOUBLE}},					\ {"intreg_operand", {SUBREG, REG}},					\ {"fcc_reg_operand", {REG}},						\ {"icc_or_fcc_reg_operand", {REG}},					\ {"restore_operand", {REG}},						\ {"call_operand", {MEM}},						\ {"call_operand_address", {SYMBOL_REF, LABEL_REF, CONST, CONST_DOUBLE,	\ 	ADDRESSOF, SUBREG, REG, PLUS, LO_SUM, CONST_INT}},		\ {"symbolic_operand", {SYMBOL_REF, LABEL_REF, CONST}},			\ {"symbolic_memory_operand", {SUBREG, MEM}},				\ {"label_ref_operand", {LABEL_REF}},					\ {"sp64_medium_pic_operand", {CONST}},					\ {"data_segment_operand", {SYMBOL_REF, PLUS, CONST}},			\ {"text_segment_operand", {LABEL_REF, SYMBOL_REF, PLUS, CONST}},		\ {"reg_or_nonsymb_mem_operand", {SUBREG, REG, MEM}},			\ {"splittable_symbolic_memory_operand", {MEM}},				\ {"splittable_immediate_memory_operand", {MEM}},				\ {"eq_or_neq", {EQ, NE}},						\ {"normal_comp_operator", {GE, GT, LE, LT, GTU, LEU}},			\ {"noov_compare_op", {NE, EQ, GE, GT, LE, LT, GEU, GTU, LEU, LTU}},	\ {"v9_regcmp_op", {EQ, NE, GE, LT, LE, GT}},				\ {"extend_op", {SIGN_EXTEND, ZERO_EXTEND}},				\ {"cc_arithop", {AND, IOR, XOR}},					\ {"cc_arithopn", {AND, IOR}},						\ {"arith_operand", {SUBREG, REG, CONST_INT}},				\ {"arith_add_operand", {SUBREG, REG, CONST_INT}},			\ {"arith11_operand", {SUBREG, REG, CONST_INT}},				\ {"arith10_operand", {SUBREG, REG, CONST_INT}},				\ {"arith_double_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}},	\ {"arith_double_add_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}},	\ {"arith11_double_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}},	\ {"arith10_double_operand", {SUBREG, REG, CONST_INT, CONST_DOUBLE}},	\ {"small_int", {CONST_INT}},						\ {"small_int_or_double", {CONST_INT, CONST_DOUBLE}},			\ {"uns_small_int", {CONST_INT}},						\ {"uns_arith_operand", {SUBREG, REG, CONST_INT}},			\ {"clobbered_register", {REG}},						\ {"input_operand", {SUBREG, REG, CONST_INT, MEM, CONST}},		\ {"const64_operand", {CONST_INT, CONST_DOUBLE}},				\ {"const64_high_operand", {CONST_INT, CONST_DOUBLE}},
end_define

begin_comment
comment|/* The number of Pmode words for the setjmp buffer.  */
end_comment

begin_define
define|#
directive|define
name|JMP_BUF_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|DONT_ACCESS_GBLS_AFTER_EPILOGUE
value|(flag_pic)
end_define

end_unit

