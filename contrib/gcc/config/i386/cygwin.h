begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows32, using a Unix style C library and tools.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_define
define|#
directive|define
name|TARGET_EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"i386/gas.h"
end_include

begin_include
include|#
directive|include
file|"dbxcoff.h"
end_include

begin_comment
comment|/* Augment TARGET_SWITCHES with the cygwin/no-cygwin options.  */
end_comment

begin_define
define|#
directive|define
name|MASK_WIN32
value|0x40000000
end_define

begin_comment
comment|/* Use -lming32 interface */
end_comment

begin_define
define|#
directive|define
name|MASK_CYGWIN
value|0x20000000
end_define

begin_comment
comment|/* Use -lcygwin interface */
end_comment

begin_define
define|#
directive|define
name|MASK_WINDOWS
value|0x10000000
end_define

begin_comment
comment|/* Use windows interface */
end_comment

begin_define
define|#
directive|define
name|MASK_DLL
value|0x08000000
end_define

begin_comment
comment|/* Use dll interface    */
end_comment

begin_define
define|#
directive|define
name|MASK_NOP_FUN_DLLIMPORT
value|0x20000
end_define

begin_comment
comment|/* Ignore dllimport for functions */
end_comment

begin_define
define|#
directive|define
name|TARGET_WIN32
value|(target_flags& MASK_WIN32)
end_define

begin_define
define|#
directive|define
name|TARGET_CYGWIN
value|(target_flags& MASK_CYGWIN)
end_define

begin_define
define|#
directive|define
name|TARGET_WINDOWS
value|(target_flags& MASK_WINDOWS)
end_define

begin_define
define|#
directive|define
name|TARGET_DLL
value|(target_flags& MASK_DLL)
end_define

begin_define
define|#
directive|define
name|TARGET_NOP_FUN_DLLIMPORT
value|(target_flags& MASK_NOP_FUN_DLLIMPORT)
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
value|{ "cygwin",		  MASK_CYGWIN,					\   N_("Use the Cygwin interface") },					\ { "no-cygwin",		  MASK_WIN32,					\   N_("Use the Mingw32 interface") },					\ { "windows",		  MASK_WINDOWS, N_("Create GUI application") },	\ { "no-win32",		  -MASK_WIN32, N_("Don't set Windows defines") },\ { "win32",		  0, N_("Set Windows defines") },		\ { "console",		  -MASK_WINDOWS,				\   N_("Create console application") }, 					\ { "dll",		  MASK_DLL, N_("Generate code for a DLL") },	\ { "nop-fun-dllimport",	  MASK_NOP_FUN_DLLIMPORT,			\   N_("Ignore dllimport for functions") }, 				\ { "no-nop-fun-dllimport", -MASK_NOP_FUN_DLLIMPORT, "" }, \ { "threads",		  0, N_("Use Mingw-specific thread support") },
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
value|"-D_X86_=1 -Asystem=winnt"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_define
define|#
directive|define
name|CYGWIN_INCLUDES
value|"%{!nostdinc:-idirafter " CYGWIN_CROSS_DIR "/include}"
end_define

begin_define
define|#
directive|define
name|W32API_INC
value|"%{!nostdinc:-idirafter " CYGWIN_CROSS_DIR "/include/w32api}"
end_define

begin_define
define|#
directive|define
name|W32API_LIB
value|"-L" CYGWIN_CROSS_DIR "/lib/w32api/"
end_define

begin_define
define|#
directive|define
name|CYGWIN_LIB
value|CYGWIN_CROSS_DIR "/lib"
end_define

begin_define
define|#
directive|define
name|MINGW_LIBS
value|"-L" CYGWIN_CROSS_DIR "/lib/mingw"
end_define

begin_define
define|#
directive|define
name|MINGW_INCLUDES
value|"%{!nostdinc:-isystem " CYGWIN_CROSS_DIR "/include/mingw/g++-3 "\ 		       "-isystem " CYGWIN_CROSS_DIR "/include/mingw/g++ "\ 		       "-idirafter " CYGWIN_CROSS_DIR "/include/mingw}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CYGWIN_INCLUDES
value|"%{!nostdinc:-isystem /usr/local/include "\ 		           "-idirafter " CYGWIN_CROSS_DIR "/include "\ 		           "-idirafter /usr/include}"
end_define

begin_define
define|#
directive|define
name|W32API_INC
value|"%{!nostdinc:"\ 		      "-idirafter " CYGWIN_CROSS_DIR "/include/w32api "\ 		      "-idirafter /usr/include/w32api}"
end_define

begin_define
define|#
directive|define
name|W32API_LIB
value|"-L" CYGWIN_CROSS_DIR "/lib/w32api/ -L/usr/lib/w32api/"
end_define

begin_define
define|#
directive|define
name|CYGWIN_LIB
value|"/usr/lib"
end_define

begin_define
define|#
directive|define
name|MINGW_LIBS
value|"-L/usr/local/lib/mingw -L/usr/lib/mingw"
end_define

begin_define
define|#
directive|define
name|MINGW_INCLUDES
value|"%{!nostdinc:-isystem /usr/include/mingw/g++-3 "\ 		       "-isystem /usr/include/mingw/g++ "\ 		       "-isystem /usr/local/include/mingw "\ 		       "-idirafter " CYGWIN_CROSS_DIR "/include/mingw "\ 		       "-idirafter /usr/include/mingw}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get tree.c to declare a target-specific specialization of    merge_decl_attributes.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
end_define

begin_comment
comment|/* Support the __declspec keyword by turning them into attributes.    We currently only support: dllimport and dllexport.    Note that the current way we do this may result in a collision with    predefined attributes later on.  This can be solved by using one attribute,    say __declspec__, and passing args to it.  The problem with that approach    is that args are not accumulated: each new appearance would clobber any    existing args.  */
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
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE} \   -D__stdcall=__attribute__((__stdcall__)) \   -D__cdecl=__attribute__((__cdecl__)) \   %{!ansi:-D_stdcall=__attribute__((__stdcall__)) \     -D_cdecl=__attribute__((__cdecl__))} \   -D__declspec(x)=__attribute__((x)) \   -D__i386__ -D__i386 \   %{mno-win32:%{mno-cygwin: %emno-cygwin and mno-win32 are not compatible}} \   %{mno-cygwin:-D__MSVCRT__ -D__MINGW32__ %{mthreads:-D_MT} "\     MINGW_INCLUDES "} \   %{!mno-cygwin:-D__CYGWIN32__ -D__CYGWIN__ %{!ansi:-Dunix} -D__unix__ -D__unix "\     CYGWIN_INCLUDES "}\   %{mwin32|mno-cygwin:-DWIN32 -D_WIN32 -D__WIN32 -D__WIN32__ %{!ansi:-DWINNT}}\   %{!mno-win32:" W32API_INC "}\ "
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\   %{shared|mdll: %{mno-cygwin:" MINGW_LIBS " dllcrt2%O%s}}\   %{!shared: %{!mdll: %{!mno-cygwin:crt0%O%s} %{mno-cygwin:" MINGW_LIBS " crt2%O%s}\   %{pg:gcrt0%O%s}}}\ "
end_define

begin_comment
comment|/* Normally, -lgcc is not needed since everything in it is in the DLL, but we    want to allow things to be added to it when installing new versions of    GCC without making a new CYGWIN.DLL, so we leave it.  Profiling is handled    by calling the init function from the prologue.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"%{mno-cygwin: %{mthreads:-lmingwthrd} -lmingw32} -lgcc %{mno-cygwin:-lmoldname -lmsvcrt}"
end_define

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GNU CC driver    program.     Do not define this macro if it does not need to do anything.  */
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
value|{ "mingw_include_path", DEFAULT_TARGET_MACHINE }
end_define

begin_comment
comment|/* We have to dynamic link to get to the system DLLs.  All of libc, libm and    the Unix stuff is in cygwin.dll.  The import library is called    'libcygwin.a'.  For Windows applications, include more libraries, but    always include kernel32.  We'd like to specific subsystem windows to    ld, but that doesn't work just yet.  */
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
value|"\   %{pg:-lgmon} \   %{!mno-cygwin:-lcygwin} \   %{mno-cygwin:%{mthreads:-lmingwthrd} -lmingw32} \   %{mwindows:-lgdi32 -lcomdlg32} \   -luser32 -lkernel32 -ladvapi32 -lshell32"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|W32API_LIB "\   %{mwindows:--subsystem windows} \   %{mconsole:--subsystem console} \   %{shared: %{mdll: %eshared and mdll are not compatible}} \   %{shared: --shared} %{mdll:--dll} \   %{static:-Bstatic} %{!static:-Bdynamic} \   %{shared|mdll: -e \     %{mno-cygwin:_DllMainCRTStartup@12} \     %{!mno-cygwin:__cygwin_dll_entry@12}}\   --dll-search-prefix=cyg"
end_define

begin_undef
undef|#
directive|undef
name|MATH_LIBRARY
end_undef

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|""
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|1
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_escape
end_escape

begin_comment
comment|/* Enable parsing of #pragma pack(push,<n>) and #pragma pack(pop).  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
value|1
end_define

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_define
define|#
directive|define
name|TREE
value|union tree_node *
end_define

begin_comment
comment|/* Used to implement dllexport overriding dllimport semantics.  It's also used    to handle vtables - the first pass won't do anything because    DECL_CONTEXT (DECL) will be 0 so i386_pe_dll{ex,im}port_p will return 0.    It's also used to handle dllimport override semantics.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|REDO_SECTION_INFO_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|((DECL_ATTRIBUTES (DECL) != NULL_TREE) \    || (TREE_CODE (DECL) == VAR_DECL&& DECL_VIRTUAL_P (DECL)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REDO_SECTION_INFO_P
parameter_list|(
name|DECL
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_drectve
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
value|DRECTVE_SECTION_FUNCTION					\   SWITCH_TO_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|DRECTVE_SECTION_FUNCTION
define|\
value|void									\ drectve_section ()							\ {									\   if (in_section != in_drectve)						\     {									\       fprintf (asm_out_file, "%s\n", "\t.section .drectve\n");		\       in_section = in_drectve;						\     }									\ }
end_define

begin_decl_stmt
name|void
name|drectve_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch to SECTION (an `enum in_section').     ??? This facility should be provided by GCC proper.    The problem is that we want to temporarily switch sections in    ASM_DECLARE_OBJECT_NAME and then switch back to the original section    afterwards.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TO_SECTION_FUNCTION
define|\
value|void switch_to_section PARAMS ((enum in_section, tree));        \ void 								\ switch_to_section (section, decl) 				\      enum in_section section; 					\      tree decl; 						\ { 								\   switch (section) 						\     { 								\       case in_text: text_section (); break; 			\       case in_data: data_section (); break; 			\       case in_named: named_section (decl, NULL, 0); break; 	\       case in_drectve: drectve_section (); break; 		\       default: abort (); break; 				\     } 								\ }
end_define

begin_comment
comment|/* Don't allow flag_pic to propagate since gas may produce invalid code    otherwise.  */
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
value|do {									\   if (flag_pic)								\     {									\       warning ("-f%s ignored for target (all code is position independent)",\ 	       (flag_pic> 1) ? "PIC" : "pic");				\       flag_pic = 0;							\     }									\ } while (0)
end_define

begin_comment
unit|\
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     On i386 running Windows NT, modify the assembler name with a suffix     consisting of an atsign (@) followed by string of digits that represents    the number of bytes of arguments passed to the function, if it has the     attribute STDCALL.     In addition, we must mark dll symbols specially. Definitions of     dllexport'd objects install some info in the .drectve section.      References to dllimport'd objects are fetched indirectly via    _imp__.  If both are declared, dllexport overrides.  This is also     needed to implement one-only vtables: they go into their own    section and we need to set DECL_SECTION_NAME so we do that here.    Note that we can be called twice on the same decl.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_encode_section_info
name|PARAMS
argument_list|(
operator|(
name|TREE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ENCODE_SECTION_INFO
end_ifdef

begin_undef
undef|#
directive|undef
name|ENCODE_SECTION_INFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
value|i386_pe_encode_section_info (DECL)
end_define

begin_comment
comment|/* Utility used only in this file.  */
end_comment

begin_define
define|#
directive|define
name|I386_PE_STRIP_ENCODING
parameter_list|(
name|SYM_NAME
parameter_list|)
define|\
value|((SYM_NAME) + ((SYM_NAME)[0] == '@' \ 		  ? ((SYM_NAME)[3] == '*' ? 4 : 3) : 0) \ 	      + ((SYM_NAME)[0] == '*' ? 1 : 0))
end_define

begin_comment
comment|/* This macro gets just the user-specified name    out of the string in a SYMBOL_REF.  Discard    trailing @[NUM] encoded by ENCODE_SECTION_INFO.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRIP_NAME_ENCODING
end_undef

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|do {									\   const char *_p;							\   const char *_name = I386_PE_STRIP_ENCODING (SYMBOL_NAME);		\   for (_p = _name; *_p&& *_p != '@'; ++_p)				\     ;									\   if (*_p == '@')							\     {									\       int _len = _p - _name;						\       char *_new_name = (char *) alloca (_len + 1);			\       strncpy (_new_name, _name, _len);					\       _new_name[_len] = '\0';						\       (VAR) = _new_name;						\     }									\   else									\     (VAR) = _name;							\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output a reference to a label.  */
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
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (STREAM, "%s%s", USER_LABEL_PREFIX, 		\ 	   I386_PE_STRIP_ENCODING (NAME))
end_define

begin_comment
unit|\
comment|/* Output a common block.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do {							\   if (i386_pe_dllexport_name_p (NAME))			\     i386_pe_record_exported_symbol (NAME, 1);		\   if (! i386_pe_dllimport_name_p (NAME))		\     {							\       fprintf ((STREAM), "\t.comm\t"); 			\       assemble_name ((STREAM), (NAME));			\       fprintf ((STREAM), ", %d\t%s %d\n",		\ 	       (ROUNDED), ASM_COMMENT_START, (SIZE));	\     }							\ } while (0)
end_define

begin_comment
comment|/* Output the label for an initialized variable.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {							\   if (i386_pe_dllexport_name_p (NAME))			\     i386_pe_record_exported_symbol (NAME, 1);		\   ASM_OUTPUT_LABEL ((STREAM), (NAME));			\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Emit code to check the stack when allocating more that 4000    bytes in one go.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_STACK_LIMIT
value|4000
end_define

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387 and needs stack probes */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_STACK_PROBE)
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
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d\n", 1<<(LOG))
end_define

begin_comment
comment|/* Define this macro if in some cases global symbols from one translation    unit may not be bound to undefined symbols in another translation unit    without user intervention.  For instance, under Microsoft Windows    symbols must be explicitly imported from shared libraries (DLLs).  */
end_comment

begin_define
define|#
directive|define
name|MULTIPLE_SYMBOL_SPACES
end_define

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_unique_section
name|PARAMS
argument_list|(
operator|(
name|TREE
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNIQUE_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
value|i386_pe_unique_section (DECL, RELOC)
end_define

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|1
end_define

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|i386_pe_asm_named_section
end_define

begin_comment
comment|/* Select attributes for named sections.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SECTION_TYPE_FLAGS
value|i386_pe_section_type_flags
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare a function    properly.  If we are generating SDB debugging information, this    will happen automatically, so we only need to handle other cases.  */
end_comment

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
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\     {									\       if (i386_pe_dllexport_name_p (NAME))				\ 	i386_pe_record_exported_symbol (NAME, 0);			\       if (write_symbols != SDB_DEBUG)					\ 	i386_pe_declare_function_type (FILE, NAME, TREE_PUBLIC (DECL));	\       ASM_OUTPUT_LABEL (FILE, NAME);					\     }									\   while (0)
end_define

begin_comment
comment|/* Add an external function to the list of functions to be declared at    the end of the file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do									\     {									\       if (TREE_CODE (DECL) == FUNCTION_DECL)				\ 	i386_pe_record_external_function (NAME);			\     }									\   while (0)
end_define

begin_comment
comment|/* Declare the type properly for any external libcall.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|FILE
parameter_list|,
name|FUN
parameter_list|)
define|\
value|i386_pe_declare_function_type (FILE, XSTR (FUN, 0), 1)
end_define

begin_comment
comment|/* This says out to put a global symbol in the BSS section.  */
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
comment|/* Output function declarations at the end of the file.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|i386_pe_asm_file_end (FILE)
end_define

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|" #"
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
name|SUBTARGET_PROLOGUE
define|\
value|if (current_function_profile						\&& MAIN_NAME_P (DECL_NAME (current_function_decl)))		\      {									\       emit_call_insn (gen_rtx (CALL, VOIDmode, 				\ 	gen_rtx_MEM (FUNCTION_MODE,					\ 		     gen_rtx_SYMBOL_REF (Pmode, "_monstartup")),	\ 	const0_rtx));							\      }
end_define

begin_comment
comment|/* External function declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_record_external_function
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_declare_function_type
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_record_exported_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_asm_file_end
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386_pe_dllexport_name_p
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386_pe_dllimport_name_p
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For Win32 ABI compatibility */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|128
end_define

begin_comment
comment|/* Native complier aligns internal doubles in structures on dword boundaries.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_FIELD_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|64
end_define

begin_comment
comment|/* A bitfield declared as `int' forces `int' alignment for the struct.  */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_BITFIELD_TYPE_MATTERS
end_undef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_define
define|#
directive|define
name|GROUP_BITFIELDS_BY_ALIGN
value|TYPE_NATIVE(rec)
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
comment|/* Override GCC's relative pathname lookup (ie., relocatability) unless    otherwise told by other subtargets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32_NO_ABSOLUTE_INST_DIRS
end_ifndef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/lib/"
end_define

begin_undef
undef|#
directive|undef
name|STANDARD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/lib/mingw/"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_undef
undef|#
directive|undef
name|LOCAL_INCLUDE_DIR
end_undef

begin_undef
undef|#
directive|undef
name|TOOL_INCLUDE_DIR
end_undef

begin_undef
undef|#
directive|undef
name|SYSTEM_INCLUDE_DIR
end_undef

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CROSS_COMPILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not WIN32_NO_ABSOLUTE_INST_DIRS */
end_comment

begin_undef
undef|#
directive|undef
name|TREE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_undef
undef|#
directive|undef
name|FILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

