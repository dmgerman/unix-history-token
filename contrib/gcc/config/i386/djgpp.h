begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running MS-DOS with DJGPP.    Copyright (C) 1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"dbxcoff.h"
end_include

begin_comment
comment|/* Support generation of DWARF2 debugging info.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
end_define

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* Enable parsing of #pragma pack(push,<n>) and #pragma pack(pop).  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
value|1
end_define

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"i386/gas.h"
end_include

begin_comment
comment|/* If defined, a C expression whose value is a string containing the    assembler operation to identify the following data as    uninitialized global data.  If not defined, and neither    `ASM_OUTPUT_BSS' nor `ASM_OUTPUT_ALIGNED_BSS' are defined,    uninitialized global data will be output in the data section if    `-fno-common' is passed, otherwise `ASM_OUTPUT_COMMON' will be    used.  */
end_comment

begin_undef
undef|#
directive|undef
name|BSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t.bss"
end_define

begin_comment
comment|/* Define the name of the .data section.  */
end_comment

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.section .data"
end_define

begin_comment
comment|/* Define the name of the .ident op.  */
end_comment

begin_undef
undef|#
directive|undef
name|IDENT_ASM_OP
end_undef

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|"\t.ident\t"
end_define

begin_comment
comment|/* Enable alias attribute support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SET_ASM_OP
end_ifndef

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the name of the .text section.  */
end_comment

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.section .text"
end_define

begin_comment
comment|/* Define standard DJGPP installation paths.                             */
end_comment

begin_comment
comment|/* We override default /usr or /usr/local part with /dev/env/DJDIR which */
end_comment

begin_comment
comment|/* points to actual DJGPP instalation directory.                         */
end_comment

begin_comment
comment|/* Standard include directory */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|"/dev/env/DJDIR/include/"
end_define

begin_comment
comment|/* Search for as.exe and ld.exe in DJGPP's binary directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/dev/env/DJDIR/bin/"
end_define

begin_comment
comment|/* Standard DJGPP library and startup files */
end_comment

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/dev/env/DJDIR/lib/"
end_define

begin_comment
comment|/* Correctly handle absolute filename detection in cp/xref.c */
end_comment

begin_define
define|#
directive|define
name|FILE_NAME_ABSOLUTE_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(((NAME)[0] == '/') || ((NAME)[0] == '\\') || \         (((NAME)[0]>= 'A')&& ((NAME)[0]<= 'z')&& ((NAME)[1] == ':')))
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__MSDOS__ -D__GO32__ -Asystem=msdos"
end_define

begin_comment
comment|/* Include<sys/version.h> so __DJGPP__ and __DJGPP_MINOR__ are defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"-remap %(cpp_cpu) %{posix:-D_POSIX_SOURCE} \   %{!ansi:%{!std=c*:%{!std=i*:-DMSDOS}}} %{!ansi:%{!std=c*:%{!std=i*:-DGO32}}} \   -imacros %s../include/sys/version.h"
end_define

begin_comment
comment|/* We need to override link_command_spec in gcc.c so support -Tdjgpp.djl.    This cannot be done in LINK_SPECS as that LINK_SPECS is processed    before library search directories are known by the linker.    This avoids problems when specs file is not available. An alternate way,    suggested by Robert Hoehne, is to use SUBTARGET_EXTRA_SPECS instead. */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_COMMAND_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_COMMAND_SPEC
define|\
value|"%{!fsyntax-only: \ %{!c:%{!M:%{!MM:%{!E:%{!S:%(linker) %l %X %{o*} %{A} %{d} %{e*} %{m} %{N} %{n} \ \t%{r} %{s} %{t} %{u*} %{x} %{z} %{Z}\ \t%{!A:%{!nostdlib:%{!nostartfiles:%S}}}\ \t%{static:} %{L*} %D %o\ \t%{!nostdlib:%{!nodefaultlibs:%G %L %G}}\ \t%{!A:%{!nostdlib:%{!nostartfiles:%E}}}\ \t-Tdjgpp.djl %{T*}}}}}}}\n\ %{!c:%{!M:%{!MM:%{!E:%{!S:stubify %{v} %{o*:%*} %{!o*:a.out} }}}}}"
end_define

begin_comment
comment|/* Always just link in 'libc.a'.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-lc"
end_define

begin_comment
comment|/* Pick the right startup code depending on the -pg flag.  */
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
value|"%{pg:gcrt0.o%s}%{!pg:crt0.o%s}"
end_define

begin_comment
comment|/* Make sure that gcc will not look for .h files in /usr/local/include     unless user explicitly requests it.  */
end_comment

begin_undef
undef|#
directive|undef
name|LOCAL_INCLUDE_DIR
end_undef

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|default_coff_asm_named_section
end_define

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_comment
comment|/* The .file command should always begin the output.  */
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
value|do {									\ 	output_file_directive (FILE, main_input_filename);		\   } while (0)
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

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
value|if ((LOG) != 0) fprintf ((FILE), "\t.p2align %d\n", LOG)
end_define

begin_comment
comment|/* This is how to output a global symbol in the BSS section.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_BSS
end_undef

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
value|asm_output_aligned_bss ((FILE), (DECL), (NAME), (SIZE), (ALIGN))
end_define

begin_comment
comment|/* This is how to tell assembler that a symbol is weak  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_WEAKEN_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_WEAKEN_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while (0)
end_define

begin_comment
comment|/* djgpp automatically calls its own version of __main, so don't define one    in libgcc, nor call one in main().  */
end_comment

begin_define
define|#
directive|define
name|HAS_INIT_SECTION
end_define

begin_comment
comment|/* Definitions for types and sizes. Wide characters are 16-bits long so    Win32 compiler add-ons will be wide character compatible.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_UNSIGNED
end_undef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|1
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
value|16
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
value|"short unsigned int"
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
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
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

begin_comment
comment|/* Used to be defined in xm-djgpp.h, but moved here for cross-compilers.  */
end_comment

begin_define
define|#
directive|define
name|LIBSTDCXX
value|"-lstdcxx"
end_define

begin_comment
comment|/* -mbnu210 is now ignored and obsolete. It was used to enable support for    weak symbols, and .gnu.linkonce support.  */
end_comment

begin_undef
undef|#
directive|undef
name|MASK_BNU210
end_undef

begin_define
define|#
directive|define
name|MASK_BNU210
value|(0x40000000)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{ "no-bnu210", -MASK_BNU210, "Ignored (obsolete)" }, \   { "bnu210", MASK_BNU210, "Ignored (obsolete)" },
end_define

begin_comment
comment|/* Warn that -mbnu210 is now obsolete.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do \   { \     if (target_flags& MASK_BNU210) \       {	\         warning ("-mbnu210 is ignored (option is obsolete)"); \       }	\   } \ while (0)
end_define

begin_comment
comment|/* Support for C++ templates.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAKE_DECL_ONE_ONLY
end_undef

begin_define
define|#
directive|define
name|MAKE_DECL_ONE_ONLY
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_WEAK (DECL) = 1)
end_define

begin_undef
undef|#
directive|undef
name|UNIQUE_SECTION
end_undef

begin_define
define|#
directive|define
name|UNIQUE_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|do {								\   int len;							\   const char *name, *prefix;					\   char *string;							\ 								\   name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (DECL));	\
comment|/* Strip off any encoding in fnname.  */
value|\   STRIP_NAME_ENCODING (name, name);                             \ 								\   if (! DECL_ONE_ONLY (DECL))					\     {								\       if (TREE_CODE (DECL) == FUNCTION_DECL)			\ 	prefix = ".text.";					\       else if (DECL_READONLY_SECTION (DECL, RELOC))		\ 	prefix = ".rodata.";					\       else							\ 	prefix = ".data.";					\     }								\   else if (TREE_CODE (DECL) == FUNCTION_DECL)			\     prefix = ".gnu.linkonce.t.";				\   else if (DECL_READONLY_SECTION (DECL, RELOC))			\     prefix = ".gnu.linkonce.r.";				\   else								\     prefix = ".gnu.linkonce.d.";				\ 								\   len = strlen (name) + strlen (prefix);			\   string = alloca (len + 1);					\   sprintf (string, "%s%s", prefix, name);			\ 								\   DECL_SECTION_NAME (DECL) = build_string (len, string);	\ } while (0)
end_define

end_unit

