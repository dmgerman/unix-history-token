begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for MIPS running Linux-based GNU systems with ELF format.    Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

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
comment|/* If defined, a C expression whose value is a string containing the    assembler operation to identify the following data as    uninitialized global data.  If not defined, and neither    `ASM_OUTPUT_BSS' nor `ASM_OUTPUT_ALIGNED_BSS' are defined,    uninitialized global data will be output in the data section if    `-fno-common' is passed, otherwise `ASM_OUTPUT_COMMON' will be    used.  */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t.bss"
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
value|mips_output_aligned_bss
end_define

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
value|mips_declare_object_name
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_if
if|#
directive|if
name|TARGET_ENDIAN_DEFAULT
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (MIPSel GNU/Linux with ELF)");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (MIPS GNU/Linux with ELF)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_comment
comment|/* If we don't set MASK_ABICALLS, we can't default to PIC.  */
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
value|MASK_ABICALLS
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {								\     LINUX_TARGET_OS_CPP_BUILTINS();				\
comment|/* The GNU C++ standard library requires this.  */
value|\     if (c_dialect_cxx ())					\       builtin_define ("_GNU_SOURCE");				\     								\     if (mips_abi == ABI_N32)					\       {								\         builtin_define ("_ABIN32=2");				\         builtin_define ("_MIPS_SIM=_ABIN32");			\         builtin_define ("_MIPS_SZLONG=32");			\         builtin_define ("_MIPS_SZPTR=32");			\       }								\     else if (mips_abi == ABI_64)				\       {								\         builtin_define ("_ABI64=3");				\         builtin_define ("_MIPS_SIM=_ABI64");			\         builtin_define ("_MIPS_SZLONG=64");			\         builtin_define ("_MIPS_SZPTR=64");			\       }								\     else							\       {								\ 	builtin_define ("_ABIO32=1");				\ 	builtin_define ("_MIPS_SIM=_ABIO32");			\         builtin_define ("_MIPS_SZLONG=32");			\         builtin_define ("_MIPS_SZPTR=32");			\       }								\     if (TARGET_FLOAT64)						\       builtin_define ("_MIPS_FPSET=32");			\     else							\       builtin_define ("_MIPS_FPSET=16");			\     								\     builtin_define ("_MIPS_SZINT=32");				\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
end_define

begin_comment
comment|/* A standard GNU/Linux mapping.  On most targets, it is included in    CC1_SPEC itself by config/linux.h, but mips.h overrides CC1_SPEC    and provides this hook instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CC1_SPEC
value|"%{profile:-p}"
end_define

begin_comment
comment|/* From iris5.h */
end_comment

begin_comment
comment|/* -G is incompatible with -KPIC which is the default, so only allow objects    in the small data section if the user explicitly asks for it.  */
end_comment

begin_undef
undef|#
directive|undef
name|MIPS_DEFAULT_GVALUE
end_undef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_GVALUE
value|0
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER
value|"/lib/ld.so.1"
end_define

begin_comment
comment|/* Borrowed from sparc/linux.h */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%(endian_spec) \   %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker " LINUX_DYNAMIC_LINKER "}} \         %{static:-static}}}"
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_SPEC
value|"%{mabi=64: -64} %{!mno-abicalls:-KPIC}"
end_define

begin_comment
comment|/* The MIPS assembler has different syntax for .set. We set it to    .dummy to trap any errors.  */
end_comment

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.dummy\t"
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DEF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do {									\ 	fputc ( '\t', FILE);						\ 	assemble_name (FILE, LABEL1);					\ 	fputs ( " = ", FILE);						\ 	assemble_name (FILE, LABEL2);					\ 	fputc ( '\n', FILE);						\  } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

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
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\ 	fputs ("\t.ent\t", STREAM);					\ 	assemble_name (STREAM, NAME);					\ 	putc ('\n', STREAM);						\       }									\     ASM_OUTPUT_TYPE_DIRECTIVE (STREAM, NAME, "function");		\     assemble_name (STREAM, NAME);					\     fputs (":\n", STREAM);						\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_SIZE
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\ 	fputs ("\t.end\t", STREAM);					\ 	assemble_name (STREAM, NAME);					\ 	putc ('\n', STREAM);						\       }									\   } while (0)
end_define

begin_comment
comment|/* Tell function_prologue in mips.c that we have already output the .ent/.end    pseudo-ops.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_NAME_ALREADY_DECLARED
end_undef

begin_define
define|#
directive|define
name|FUNCTION_NAME_ALREADY_DECLARED
value|1
end_define

begin_comment
comment|/* The glibc _mcount stub will save $v0 for us.  Don't mess with saving    it, since ASM_OUTPUT_REG_PUSH/ASM_OUTPUT_REG_POP do not work in the    presence of $gp-relative calls.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_PUSH
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_POP
end_undef

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"\ %{shared: -lc} \ %{!shared: %{pthread:-lpthread} \   %{profile:-lc_p} %{!profile: -lc}}"
end_define

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/mips/linux-unwind.h"
end_define

end_unit

