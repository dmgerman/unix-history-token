begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows NT 3.x, using a Unix style C library and tools,    as distinct from winnt.h, which is used to build GCC for use with a    windows style library and tool set and uses the Microsoft tools.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
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
comment|/* Augment TARGET_SWITCHES with the cygwin/win32 options.  */
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
value|{ "win32",			MASK_WIN32,				\       N_("Use Mingw32 interface") },					\     { "cygwin",			MASK_CYGWIN,				\       N_("Use Cygwin interface")  },					\     { "windows",		MASK_WINDOWS,				\       N_("Use bare Windows interface") },				\     { "dll",			MASK_DLL,				\       N_("Generate code for a DLL") },					\     { "nop-fun-dllimport",	MASK_NOP_FUN_DLLIMPORT,			\       N_("Ignore dllimport for functions") }, 				\     { "no-nop-fun-dllimport",	MASK_NOP_FUN_DLLIMPORT, "" },
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
value|"-D_WIN32 -DWINNT -D_X86_=1 \   -D__stdcall=__attribute__((__stdcall__)) \   -D__cdecl=__attribute__((__cdecl__)) \   -Asystem=winnt"
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
value|"%{mdll:dllcrt0%O%s} %{!mdll: %{!mcygwin:mcrt0%O%s} \                         %{mcygwin:crt0%O%s} %{pg:gcrt0%O%s}}"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE} \   %{!mcygwin:-iwithprefixbefore include/mingw32 -D__MINGW32__}    \   %{mcygwin:-D__CYGWIN32__ -D__CYGWIN__}"
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
value|"%{pg:-lgmon}						\ 		  %{!mcygwin:-lmingw32 -lmoldname -lmsvcrt -lcrtdll}	\                   %{mcygwin:-lcygwin} %{mwindows:-luser32 -lgdi32 -lcomdlg32} \                   -lkernel32 -ladvapi32 -lshell32"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{mwindows:--subsystem windows} \   %{mdll:--dll -e _DllMainCRTStartup@12}"
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

begin_comment
comment|/* Currently we do not have the atexit() function,    so take that from libgcc2.c */
end_comment

begin_define
define|#
directive|define
name|NEED_ATEXIT
value|1
end_define

begin_comment
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     On i386, if using PIC, mark a SYMBOL_REF for a non-global symbol    so that we may access it directly in the GOT.     On i386 running Windows NT, modify the assembler name with a suffix     consisting of an atsign (@) followed by string of digits that represents    the number of bytes of arguments passed to the function, if it has the     attribute STDCALL.  */
end_comment

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

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|do									\   {									\     if (flag_pic)							\       {									\ 	rtx rtl = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'		\ 		   ? TREE_CST_RTL (DECL) : DECL_RTL (DECL));		\ 	SYMBOL_REF_FLAG (XEXP (rtl, 0))					\ 	  = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'			\ 	     || ! TREE_PUBLIC (DECL));					\       }									\     if (TREE_CODE (DECL) == FUNCTION_DECL) 				\       if (lookup_attribute ("stdcall",					\ 			    TYPE_ATTRIBUTES (TREE_TYPE (DECL))))	\         XEXP (DECL_RTL (DECL), 0) = 					\           gen_rtx (SYMBOL_REF, Pmode, gen_stdcall_suffix (DECL)); 	\   }									\ while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro gets just the user-specified name    out of the string in a SYMBOL_REF.  Discard    trailing @[NUM] encoded by ENCODE_SECTION_INFO.     Do we need the stripping of leading '*'?  */
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
value|do {									\   const char *_p;							\   const char *const _name = ((SYMBOL_NAME) + ((SYMBOL_NAME)[0] == '*'));\   for (_p = _name; *_p&& *_p != '@'; ++_p)				\     ;									\   if (*_p == '@')							\     {									\       int _len = _p - _name;						\       char *_new_name = (char *) alloca (_len + 1);			\       strncpy (_new_name, _name, _len);					\       _new_name[_len] = '\0';						\       (VAR) = _new_name;						\     }									\   else									\     (VAR) = _name;							\ } while (0)
end_define

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

begin_function_decl
specifier|extern
name|void
name|i386_pe_unique_section
parameter_list|()
function_decl|;
end_function_decl

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
value|if (current_function_profile						\&& MAIN_NAME_P (DECL_NAME (current_function_decl))		\      {									\       rtx xops[1];							\       xops[0] = gen_rtx_MEM (FUNCTION_MODE,				\ 			 gen_rtx (SYMBOL_REF, Pmode, "_monstartup"));	\       emit_call_insn (gen_rtx (CALL, VOIDmode, xops[0], const0_rtx));	\      }
end_define

end_unit

