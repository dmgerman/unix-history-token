begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine GNU compiler.  IA-64/AIX version.    Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Timothy Wall (twall@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* AIX5 (aka Monterey): a mix of AIX and UnixWare.      This file is loosely based on ia64/linux.h.  */
end_comment

begin_comment
comment|/* This macro is a C statement to print on `stderr' a string describing the    particular machine description choice.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (IA-64) AIX");
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

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

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

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/lib/ia64l64/"
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
value|do {									\ 	output_file_directive (FILE, main_input_filename);		\ 	fprintf (FILE, "\t.version\t\"01.01\"\n");			\   } while (0)
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for AIX.  Here we add    the crti C++ startup files file which provide part of the support    for getting C++ file-scope static object constructed before entering    `main'.  */
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
value|"%{!shared: \    %{pg:gcrt1_64.o%s} %{!pg:%{p:mcrt1_64.o%s} \                         %{!p:%{profile:gcrt1_64.o%s} \                           %{!profile:crt1_64.o%s}}}} \  crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for AIX.  Here we tack on    the crtn file which provides termination of the support for getting C++    file-scope static object constructed before entering `main'.  */
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
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_comment
comment|/* Define this so we can compile MS code for use with WINE.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
end_define

begin_comment
comment|/* A C string constant that tells the GNU CC driver program options to pass to    CPP.  It can also specify how to translate options you give to GNU CC into    options for GNU CC to pass to the CPP.  */
end_comment

begin_comment
comment|/* If -ansi, we need to define _ANSI_C_SOURCE to get the right headers.  */
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
value|"\ %{mcpu=itanium:-D__itanium__} %{mbig-endian:-D__BIG_ENDIAN__} \ %{ansi:-D_ANSI_C_SOURCE} \ %{posix:-D_POSIX_SOURCE} \ %{cpp_cpu} \ -D__LONG_MAX__=9223372036854775807L"
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
value|"\ -D__ia64 -D__ia64__ -D_AIX -D_AIX64 -D_LONGLONG -Dunix \ -D__LP64__ -D__ELF__ -Asystem=unix -Asystem=aix -Acpu=ia64 -Amachine=ia64 \ -D__64BIT__ -D_LONG_LONG -D_IA64 -D__int128=__size128_t"
end_define

begin_comment
comment|/* The GNU C++ standard library requires that these macros be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUSPLUS_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
define|\
value|"-D_XOPEN_SOURCE=500                          \    -D_XOPEN_SOURCE_EXTENDED=1                   \    -D_LARGE_FILE_API                            \    -D_ALL_SOURCE                                \    -D__LONG_MAX__=9223372036854775807L          \    %{cpp_cpu}"
end_define

begin_comment
comment|/* ia64-specific options for gas */
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
value|"-x %{mconstant-gp} %{mauto-pic}"
end_define

begin_comment
comment|/* Define this for shared library support.  */
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
value|"\ %{shared:-shared} \ %{!shared: \   %{!static: \     %{rdynamic:-export-dynamic} \     %{!dynamic-linker:-dynamic-linker /usr/lib/ia64l64/libc.so.1}} \     %{static:-static}}"
end_define

begin_define
define|#
directive|define
name|DONT_USE_BUILTIN_SETJMP
end_define

begin_define
define|#
directive|define
name|JMP_BUF_SIZE
value|85
end_define

begin_comment
comment|/* Output any profiling code before the prologue.  */
end_comment

begin_undef
undef|#
directive|undef
name|PROFILE_BEFORE_PROLOGUE
end_undef

begin_define
define|#
directive|define
name|PROFILE_BEFORE_PROLOGUE
value|1
end_define

begin_comment
comment|/* A C statement or compound statement to output to FILE some assembler code to    call the profiling subroutine `mcount'.       FIXME this is not supported until xlC supports it and can thus tell us    how to do it. */
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
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|do {							\ } while (0)
end_define

begin_comment
comment|/* Tell the linker where to find the crt*.o files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_undef
undef|#
directive|undef
name|STANDARD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/lib/ia64l64/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Override SELECT_SECTION and SELECT_RTX_SECTION from config/ia64/sysv4.h;      these definitions ignore flag_pic as if it were always set;     it is illegal to have relocations in shared segments on AIX.  */
end_comment

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
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{									\   if (TREE_CODE (DECL) == STRING_CST)					\     {									\       if (! flag_writable_strings)					\ 	const_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (DECL) == VAR_DECL)				\     {									\       if (XSTR (XEXP (DECL_RTL (DECL), 0), 0)[0]			\ 	  == SDATA_NAME_FLAG_CHAR)					\         sdata_section ();						\
comment|/* ??? We need the extra ! RELOC check, because the default is to \ 	 only check RELOC if flag_pic is set, and we don't set flag_pic \ 	 (yet?).  */
value|\       else if (DECL_READONLY_SECTION (DECL, RELOC)&& ! (RELOC))	\ 	const_section ();						\       else								\ 	data_section ();						\     }									\
comment|/* This could be a CONSTRUCTOR containing ADDR_EXPR of a VAR_DECL,	\      in which case we can't put it in a shared library rodata.  */
value|\   else if (RELOC)                                                       \     data_section ();							\   else									\     const_section ();							\ }
end_define

begin_comment
comment|/* Similarly for constant pool data.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|ia64_section_threshold
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{									\   if (GET_MODE_SIZE (MODE)> 0						\&& GET_MODE_SIZE (MODE)<= ia64_section_threshold)		\     sdata_section ();							\   else if (symbolic_operand ((RTX), (MODE)))		                \     data_section ();							\   else									\     const_section ();							\ }
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
value|do								\     {								\       int len;							\       int sec;							\       const char *name;						\       char *string;						\       const char *prefix;					\       static const char *const prefixes[
comment|/*4*/
value|3][2] =		\       {								\ 	{ ".text.",   ".gnu.linkonce.t." },			\ 	{ ".rodata.", ".gnu.linkonce.r." },			\ 	{ ".data.",   ".gnu.linkonce.d." }			\
comment|/* Do not generate unique sections for uninitialised 	\ 	   data since we do not have support for this in the    \ 	   linker scripts yet...				\         ,{ ".bss.",    ".gnu.linkonce.b." }  */
value|\       };							\       								\       if (TREE_CODE (DECL) == FUNCTION_DECL)			\ 	sec = 0;						\
comment|/*  else if (DECL_INITIAL (DECL) == 0				\ 	       || DECL_INITIAL (DECL) == error_mark_node)	\         sec =  3; */
value|\       else if (DECL_READONLY_SECTION (DECL, RELOC)&& ! (RELOC))\ 	sec = 1;						\       else							\ 	sec = 2;						\       								\       name   = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (DECL));	\
comment|/* Strip off any encoding in name.  */
value|\       STRIP_NAME_ENCODING (name, name);				\       prefix = prefixes[sec][DECL_ONE_ONLY(DECL)];		\       len    = strlen (name) + strlen (prefix);			\       string = alloca (len + 1);				\       								\       sprintf (string, "%s%s", prefix, name);			\       								\       DECL_SECTION_NAME (DECL) = build_string (len, string);	\     }								\   while (0)
end_define

begin_comment
comment|/* Override ia64/sysv4.h setting with that used by AIX5.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__64BIT__
end_ifdef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned short"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the `__builtin_va_list' type for AIX.  Use char* b/c that's what the    system headers expect.  */
end_comment

begin_define
define|#
directive|define
name|BUILD_VA_LIST_TYPE
parameter_list|(
name|VALIST
parameter_list|)
define|\
value|(VALIST) = build_pointer_type(char_type_node)
end_define

begin_comment
comment|/* End of aix.h */
end_comment

end_unit

