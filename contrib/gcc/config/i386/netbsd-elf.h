begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for i386/ELF NetBSD systems.    Copyright (C) 2001, 2002 Free Software Foundation, Inc.    Contributed by matthew green<mrg@eterna.com.au>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Provide a LINK_SPEC appropriate for a NetBSD/i386 ELF target.    This is a copy of LINK_SPEC from<netbsd-elf.h> tweaked for    the i386 target.  */
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
value|"%{assert*} %{R*}							\   %{shared:-shared}							\   %{!shared:								\     -dc -dp								\     %{!nostdlib:							\       %{!r*:								\ 	%{!e*:-e __start}}}						\     %{!static:								\       %{rdynamic:-export-dynamic}					\       %{!dynamic-linker:-dynamic-linker /usr/libexec/ld.elf_so}}	\     %{static:-static}}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-D__NetBSD__ -D__ELF__ -Asystem=unix -Asystem=NetBSD"
end_define

begin_comment
comment|/* Make gcc agree with<machine/ansi.h> */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

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
name|WCHAR_UNSIGNED
end_undef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|0
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

begin_undef
undef|#
directive|undef
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
value|svr4_dbx_register_map[n]
end_define

begin_comment
comment|/* Output assembler code to FILE to call the profiler.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_PROFILE_COUNTERS
end_undef

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

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
value|{									\   if (flag_pic)								\     fprintf (FILE, "\tcall __mcount@PLT\n");				\   else									\     fprintf (FILE, "\tcall __mcount\n");				\ }
end_define

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_comment
comment|/* This is how we tell the assembler that two symbols have the same value.  */
end_comment

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
value|do { assemble_name(FILE, NAME1); 	 \        fputs(" = ", FILE);		 \        assemble_name(FILE, NAME2);	 \        fputc('\n', FILE); } while (0)
end_define

begin_comment
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This is used to align code labels according to Intel recommendations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

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
value|if ((LOG) != 0) {							\     if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG));	\     else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We always use gas here, so we don't worry about ECOFF assembler    problems.  */
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
comment|/* Default to pcc-struct-return, because this is the ELF abi and    we don't care about compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|1
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
value|fprintf (stderr, " (NetBSD/i386 ELF)");
end_define

end_unit

