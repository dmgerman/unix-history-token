begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running MS-DOS with DJGPP.    Copyright (C) 1997, 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"dbxcoff.h"
end_include

begin_comment
comment|/* Don't assume anything about the header files. */
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
value|"\t.set"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Search for as.exe and ld.exe in DJGPP's binary directory. */
end_comment

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"$DJDIR/bin/"
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

begin_ifdef
ifdef|#
directive|ifdef
name|CPP_PREDEFINES
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -DGO32 -DDJGPP=2 -DMSDOS \   -Asystem(unix) -Asystem(msdos) -Acpu(i386) -Amachine(i386)"
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

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_ctor, in_dtor
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|CTOR_SECTION_FUNCTION						\   DTOR_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|CTOR_SECTION_FUNCTION
define|\
value|void								\ ctor_section ()							\ {								\   if (in_section != in_ctor)					\     {								\       fprintf (asm_out_file, "\t.section .ctor\n");		\       in_section = in_ctor;					\     }								\ }
end_define

begin_define
define|#
directive|define
name|DTOR_SECTION_FUNCTION
define|\
value|void								\ dtor_section ()							\ {								\   if (in_section != in_dtor)					\     {								\       fprintf (asm_out_file, "\t.section .dtor\n");		\       in_section = in_dtor;					\     }								\ }
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CONSTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {						\     ctor_section ();				\     fprintf (FILE, "%s\t", ASM_LONG);		\     assemble_name (FILE, NAME);			\     fprintf (FILE, "\n");			\   } while (0)
end_define

begin_comment
comment|/* Allow (eg) __attribute__((section "locked")) to work */
end_comment

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
value|do {						\     fprintf (FILE, "\t.section %s\n", NAME);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_DESTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {						\     dtor_section ();                   		\     fprintf (FILE, "%s\t", ASM_LONG);		\     assemble_name (FILE, NAME);              	\     fprintf (FILE, "\n");			\   } while (0)
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
comment|/* djgpp has atexit ().  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ATEXIT
end_undef

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* djgpp automatically calls its own version of __main, so don't define one    in libgcc, nor call one in main().  */
end_comment

begin_define
define|#
directive|define
name|HAS_INIT_SECTION
end_define

end_unit

