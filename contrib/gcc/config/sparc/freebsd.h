begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Sun SPARC64 running FreeBSD using the ELF format    Copyright (C) 2001, 2002, 2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by David E. O'Brien<obrien@FreeBSD.org> and BSDi.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "fbsd_dynamic_linker", FBSD_DYNAMIC_LINKER }
end_define

begin_comment
comment|/* FreeBSD needs the platform name (sparc64) defined.    Emacs needs to know if the arch is 64 or 32-bits.    This also selects which targets are available via -mcpu.  */
end_comment

begin_undef
undef|#
directive|undef
name|FBSD_TARGET_CPU_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|FBSD_TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       builtin_define ("__LP64__");		\       builtin_define ("__sparc64__");		\       builtin_define ("__sparc_v9__");		\       builtin_define ("__sparcv9");		\       builtin_define ("__sparc__");		\       builtin_define ("__arch64__");		\     }						\   while (0)
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%(link_arch)						\   %{!mno-relax:%{!r:-relax}}						\   %{p:%nconsider using `-pg' instead of `-p' with gprof(1)}		\   %{assert*} %{R*} %{rpath*} %{defsym*}					\   %{shared:-Bshareable %{h*} %{soname*}}				\   %{symbolic:-Bsymbolic}						\   %{!shared:								\     %{!static:								\       %{rdynamic:-export-dynamic}					\       %{!dynamic-linker:-dynamic-linker %(fbsd_dynamic_linker) }}	\     %{static:-Bstatic}}"
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.      Needs to agree with<machine/ansi.h>.  GCC defaults come from c-decl.c,    c-common.c, and config/<arch>/<arch>.h.  */
end_comment

begin_comment
comment|/* Earlier headers may get this wrong for FreeBSD.    We use the GCC defaults instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Define for support of TFmode long double.    SPARC ABI says that long double is 4 words.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(TARGET_LONG_DOUBLE_128 ? 128 : 64)
end_define

begin_comment
comment|/* Define this to set long double type size to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__LONG_DOUBLE_128__
argument_list|)
end_if

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
comment|/* Definitions for 64-bit SPARC running systems with ELF. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD/sparc64 ELF)");
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|1
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* A 64 bit v9 compiler with stack-bias,    in a Medium/mid code model environment.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
define|\
value|(MASK_V9 + MASK_64BIT + MASK_PTR64
comment|/* + MASK_FASTER_STRUCTS */
value|\    + MASK_STACK_BIAS + MASK_APP_REGS + MASK_FPU \    + MASK_LONG_DOUBLE_128
comment|/* + MASK_HARD_QUAD */
value|)
end_define

begin_comment
comment|/* The default code model.  */
end_comment

begin_undef
undef|#
directive|undef
name|SPARC_DEFAULT_CMODEL
end_undef

begin_define
define|#
directive|define
name|SPARC_DEFAULT_CMODEL
value|CM_MEDLOW
end_define

begin_define
define|#
directive|define
name|ENABLE_EXECUTE_STACK
define|\
value|static int need_enable_exec_stack;					\   static void check_enabling(void) __attribute__ ((constructor));	\   static void check_enabling(void)					\   {									\     extern int sysctlbyname(const char *, void *, size_t *, void *, size_t);\     int prot = 0;							\     size_t len = sizeof(prot);						\ 									\     sysctlbyname ("kern.stackprot",&prot,&len, NULL, 0);		\     if (prot != 7)							\       need_enable_exec_stack = 1;					\   }									\   extern void __enable_execute_stack (void *);				\   void __enable_execute_stack (void *addr)				\   {									\     if (!need_enable_exec_stack)					\       return;								\     else {								\
comment|/* 7 is PROT_READ | PROT_WRITE | PROT_EXEC */
value|\       if (mprotect (addr, TRAMPOLINE_SIZE, 7)< 0)			\         perror ("mprotect of trampoline code");				\     }									\   }
end_define

begin_comment
comment|/************************[  Assembler stuff  ]********************************/
end_comment

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* XXX2 */
end_comment

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

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
value|sprintf (LABEL, "*.L%s%lu", PREFIX, (unsigned long)(NUM))
end_define

begin_comment
comment|/************************[  Debugger stuff  ]*********************************/
end_comment

begin_comment
comment|/* This is the char to use for continuation (in case we need to turn    continuation back on).  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_CHAR
end_undef

begin_define
define|#
directive|define
name|DBX_CONTIN_CHAR
value|'?'
end_define

begin_comment
comment|/* DWARF bits.  */
end_comment

begin_comment
comment|/* Follow Irix 6 and not the Dwarf2 draft in using 64-bit offsets.     Obviously the Dwarf2 folks havn't tried to actually build systems    with their spec.  On a 64-bit system, only 64-bit relocs become    RELATIVE relocations.  */
end_comment

begin_comment
comment|/* #define DWARF_OFFSET_SIZE PTR_SIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_AS_TLS
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_SUN_TLS
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_GNU_TLS
end_undef

begin_define
define|#
directive|define
name|TARGET_SUN_TLS
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_GNU_TLS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
define|\
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} "	\   FBSD_ENDFILE_SPEC
end_define

begin_comment
comment|/* We use GNU ld so undefine this so that attribute((init_priority)) works.  */
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

end_unit

