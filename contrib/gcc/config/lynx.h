begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target independent definitions for LynxOS.    Copyright (C) 1993, 1994, 1995, 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* LynxOS is a multi-platform Unix, similar to SVR3, but not identical.    We can get quite a bit from generic svr3, but have to do some overrides. */
end_comment

begin_include
include|#
directive|include
file|"svr3.h"
end_include

begin_comment
comment|/* Define various macros, depending on the combination of flags. */
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
value|"%{mthreads:-D_MULTITHREADED}  \   %{mposix:-D_POSIX_SOURCE}  \   %{msystem-v:-I/usr/include_v}"
end_define

begin_comment
comment|/* No asm spec needed, since using GNU assembler always. */
end_comment

begin_comment
comment|/* No linker spec needed, since using GNU linker always. */
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
value|"%{mthreads:-L/lib/thread/}  \   %{msystem-v:-lc_v}  \   %{!msystem-v:%{mposix:-lc_p} -lc -lm}"
end_define

begin_comment
comment|/* Set the appropriate names for the Lynx startfiles. */
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
value|"%{p:%{mthreads:thread/pinit1.o%s}%{!mthreads:pinit1.o%s}}%{!p:%{msystem-v:vinit1.o%s -e_start}%{!msystem-v:%{mthreads:thread/init1.o%s}%{!mthreads:init1.o%s}}}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"%{p:_etext.o%s}%{!p:initn.o%s}"
end_define

begin_comment
comment|/* Override the svr3 versions. */
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
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_comment
comment|/* We want to output DBX (stabs) debugging information normally.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* It is convenient to be able to generate standard coff debugging    if requested via -gcoff. */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* Be function-relative for block and source line stab directives. */
end_comment

begin_define
define|#
directive|define
name|DBX_BLOCKS_FUNCTION_RELATIVE
value|1
end_define

begin_comment
comment|/* but, to make this work, functions must appear prior to line info */
end_comment

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
end_define

begin_comment
comment|/* Generate a blank trailing N_SO to mark the end of the .o file, since    we can't depend upon the linker to mark .o file boundaries with    embedded stabs.  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|fprintf (FILE,							\ 	   "\t.text\n\t.stabs \"\",%d,0,0,Letext\nLetext:\n", N_SO)
end_define

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
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|{ static int sym_lineno = 1;				\     fprintf (file, ".stabn 68,0,%d,.LM%d-",		\ 	     line, sym_lineno);				\     assemble_name (file,				\ 		   XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0)); \     fprintf (file, "\n.LM%d:\n", sym_lineno);		\     sym_lineno += 1; }
end_define

begin_comment
comment|/* Handle #pragma pack and sometimes #pragma weak.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* Some additional command-line options. */
end_comment

begin_define
define|#
directive|define
name|TARGET_THREADS
value|(target_flags& MASK_THREADS)
end_define

begin_define
define|#
directive|define
name|MASK_THREADS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TARGET_POSIX
value|(target_flags& MASK_POSIX)
end_define

begin_define
define|#
directive|define
name|MASK_POSIX
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TARGET_SYSTEM_V
value|(target_flags& MASK_SYSTEM_V)
end_define

begin_define
define|#
directive|define
name|MASK_SYSTEM_V
value|0x10000000
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
value|{"threads",		MASK_THREADS},		\     {"posix",		MASK_POSIX},		\     {"system-v",	MASK_SYSTEM_V},
end_define

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
value|do {								\   if (TARGET_SYSTEM_V&& profile_flag)				\     warning ("-msystem-v and -p are incompatible");		\   if (TARGET_SYSTEM_V&& TARGET_THREADS)			\     warning ("-msystem-v and -mthreads are incompatible");	\ } while (0)
end_define

begin_comment
comment|/* Define this so that C++ destructors will use atexit, since LynxOS    calls exit after main returns.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Since init.o et al put all sorts of stuff into the init section,    we can't use the standard init section support in crtbegin.o. */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
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
value|in_const, in_ctors, in_dtors, in_fini
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
value|CONST_SECTION_FUNCTION					\   CTORS_SECTION_FUNCTION					\   DTORS_SECTION_FUNCTION					\   FINI_SECTION_FUNCTION
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors"
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t.dtors"
end_define

begin_define
define|#
directive|define
name|INT_ASM_OP
value|".long"
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global constructors.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CONSTRUCTOR
end_undef

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
value|do {									\     ctors_section ();							\     fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\     assemble_name (FILE, NAME);						\     fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global destructors.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DESTRUCTOR
end_undef

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
value|do {									\     dtors_section ();                   				\     fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\     assemble_name (FILE, NAME);              				\     fprintf (FILE, "\n");						\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_CTORS_BODY
end_undef

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_DTORS_BODY
end_undef

begin_comment
comment|/* LynxOS doesn't have mcount. */
end_comment

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
name|file
parameter_list|,
name|profile_label_no
parameter_list|)
end_define

end_unit

