begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    Windows NT 3.x on an i386.    Copyright (C) 1994, 1995 Free Software Foundation, Inc.    Contributed by Douglas B. Rupp (drupp@cs.washington.edu).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

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
value|"-Dunix -Di386 -DWIN32 -D_WIN32 \   -DWINNT -D_M_IX86=300 -D_X86_=1 -D__STDC__=0 -DALMOST_STDC -D_MSC_VER=800 \   -D__stdcall=__attribute__((__stdcall__)) \   -D__cdecl=__attribute__((__cdecl__)) \   -D_cdecl=__attribute__((__cdecl__)) \   -Asystem(unix) -Asystem(winnt) -Acpu(i386) -Amachine(i386)"
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

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|HAVE_ATEXIT
value|1
end_define

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
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     On i386, if using PIC, mark a SYMBOL_REF for a non-global symbol    so that we may access it directly in the GOT.     On i386 running Windows NT, modify the assembler name with a suffix     consisting of an atsign (@) followed by string of digits that represents    the number of bytes of arguments passed to the function, if it has the     attribute STDCALL. */
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
comment|/* The global __fltused is necessary to cause the printf/scanf routines    for outputting/inputting floating point numbers to be loaded.  Since this    is kind of hard to detect, we just do it all the time. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_FILE_START
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {	output_file_directive (FILE, main_input_filename);	\         fprintf (FILE, ".global\t__fltused\n");			\   } while (0)
end_define

begin_comment
comment|/* if the switch "-mwindows" is passed to ld, then specify to the Microsoft    linker the proper switches and libraries to build a graphical program */
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
value|"%{mwindows:-subsystem windows -e _WinMainCRTStartup \   USER32.LIB%s GDI32.LIB%s COMDLG32.LIB%s WINSPOOL.LIB%s} \  %{!mwindows:-subsystem console -e _mainCRTStartup} \  %{mcrtmt:LIBCMT.LIB%s KERNEL32.LIB%s ADVAPI32.LIB%s} \  %{!mcrtmt:LIBC.LIB%s KERNEL32.LIB%s ADVAPI32.LIB%s} \  %{v}"
end_define

begin_include
include|#
directive|include
file|"winnt/win-nt.h"
end_include

end_unit

