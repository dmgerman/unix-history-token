begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for DEC AXP Alpha running FreeBSD using the ELF format    Copyright (C) 2000 Free Software Foundation, Inc.    Contributed by David O'Brien<obrien@FreeBSD.org>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This is used on Alpha platforms that use the ELF format.    This was taken from the NetBSD configuration, and modified    for FreeBSD/Alpha by Hidetoshi Shimokawa<simokawa@FreeBSD.ORG> */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.    XXX FreeBSD, by convention, shouldn't do __alpha, but lots of applications    expect it because that's what OSF/1 does.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-D__alpha__ -D__alpha -Acpu(alpha) -Amachine(alpha)"			\   FBSD_CPP_PREDEFINES
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf64alpha					\   %{p:%e`-p' not supported; use `-pg' and gprof(1)}			\   %{Wl,*:%*}								\   %{assert*} %{R*} %{rpath*} %{defsym*}					\   %{shared:-Bshareable %{h*} %{soname*}}				\   %{symbolic:-Bsymbolic}						\   %{!shared:								\     %{!static:								\       %{rdynamic:-export-dynamic}					\       %{!dynamic-linker:-dynamic-linker /usr/libexec/ld-elf.so.1}}	\     %{static:-Bstatic}}"
end_define

begin_comment
comment|/* Provide an ASM_SPEC appropriate for a FreeBSD/Alpha target.  This differs    from the generic FreeBSD ASM_SPEC in that no special handling of PIC is    necessary on the Alpha.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %| %{mcpu=*:-m%*}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_comment
comment|/* Provide a STARTFILE_SPEC for FreeBSD that is compatible with the    non-aout version used on i386.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}}	\      crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for ELF.  Here we tack on the    magical crtend.o file which provides part of the support for    getting C++ file-scope static object constructed before entering    `main', followed by a normal ELF "finalizer" file, `crtn.o'.  */
end_comment

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
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.      Needs to agree with<machine/ansi.h>.  GCC defaults come from c-decl.c,    c-common.c, and config/<arch>/<arch>.h.  */
end_comment

begin_comment
comment|/* alpha.h gets this wrong for FreeBSD.  We use the GCC defaults instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_comment
comment|/* Handle cross-compilation on 32-bits machines (such as i386) for 64-bits    machines (Alpha in this case).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_LONG
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|32
end_define

begin_undef
undef|#
directive|undef
name|HOST_WIDE_INT
end_undef

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_WIDE_INT
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the pseudo-op used to generate a 64-bit word of data with a    specific value in some section.  */
end_comment

begin_undef
undef|#
directive|undef
name|INT_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INT_ASM_OP
value|".quad"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD/Alpha ELF)");
end_define

begin_define
define|#
directive|define
name|TARGET_AOUT
value|(0)
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|(1)
end_define

begin_define
define|#
directive|define
name|TARGET_UNDERSCORES
value|(0)
end_define

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_COFF
end_undef

begin_undef
undef|#
directive|undef
name|EXTENDED_COFF
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_FP | MASK_FPREGS | MASK_GAS)
end_define

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_comment
comment|/* Show that we need a GP when profiling.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_PROFILING_NEEDS_GP
end_undef

begin_define
define|#
directive|define
name|TARGET_PROFILING_NEEDS_GP
end_define

begin_comment
comment|/* We always use gas here, so we don't worry about ECOFF assembler problems.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_GAS
end_undef

begin_define
define|#
directive|define
name|TARGET_GAS
value|1
end_define

begin_comment
comment|/************************[  Assembler stuff  ]********************************/
end_comment

begin_comment
comment|/* This is how to begin an assembly language file.    ELF also needs a .version.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{									\     alpha_write_verstamp (FILE);					\     output_file_directive ((FILE), main_input_filename);		\     fprintf ((FILE), "\t.version\t\"01.01\"\n");			\     fprintf ((FILE), "\t.set noat\n");					\   }
end_define

begin_function_decl
specifier|extern
name|void
name|output_file_directive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_output_lineno
parameter_list|()
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

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
value|alpha_output_lineno ((STREAM), (LINE))
end_define

begin_comment
comment|/* Switch into a generic section.    This is currently only used to support section attributes.     We make the section read-only and executable for a function decl,    read-only for a const data decl, and writable for a non-const data decl.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SECTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SECTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|fprintf ((FILE), ".section\t%s,\"%s\",@progbits\n", (NAME),		\ 	   (DECL)&& TREE_CODE (DECL) == FUNCTION_DECL ? "ax" :		\ 	   (DECL)&& DECL_READONLY_SECTION ((DECL), (RELOC)) ? "a" : "aw")
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of DECL.  DECL is either a `VAR_DECL' node    or a constant of some sort.  RELOC indicates whether forming    the initial value of DECL requires link-time relocations.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|{									\     if (TREE_CODE (DECL) == STRING_CST)					\       {									\ 	if (! flag_writable_strings)					\ 	  const_section ();						\ 	else								\ 	  data_section ();						\       }									\     else if (TREE_CODE (DECL) == VAR_DECL)				\       {									\ 	if ((flag_pic&& (RELOC))					\ 	    || !TREE_READONLY (DECL) || TREE_SIDE_EFFECTS (DECL)	\ 	    || !DECL_INITIAL (DECL)					\ 	    || (DECL_INITIAL (DECL) != error_mark_node			\&& !TREE_CONSTANT (DECL_INITIAL (DECL))))			\ 	  data_section ();						\         else								\ 	  const_section ();						\       }									\     else								\       const_section ();							\   }
end_define

begin_comment
comment|/* This is how we tell the assembler that two symbols have the same value.  */
end_comment

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
name|NAME1
parameter_list|,
name|NAME2
parameter_list|)
define|\
value|do {									\     assemble_name((FILE), (NAME1));					\     fputs(" = ", (FILE));						\     assemble_name((FILE), (NAME2));					\     fputc('\n', (FILE));						\   } while (0)
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

end_unit

