begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration file for an alpha OpenBSD target.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* We settle for little endian for now.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ENDIAN_DEFAULT
value|0
end_define

begin_include
include|#
directive|include
file|<alpha/alpha.h>
end_include

begin_define
define|#
directive|define
name|OBSD_NO_DYNAMIC_LIBRARIES
end_define

begin_define
define|#
directive|define
name|OBSD_HAS_DECLARE_FUNCTION_NAME
end_define

begin_define
define|#
directive|define
name|OBSD_HAS_DECLARE_FUNCTION_SIZE
end_define

begin_define
define|#
directive|define
name|OBSD_HAS_DECLARE_OBJECT
end_define

begin_comment
comment|/* alpha ecoff supports only weak aliases, see below.  */
end_comment

begin_define
define|#
directive|define
name|ASM_WEAKEN_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|ASM_OUTPUT_WEAK_ALIAS (FILE,NAME,0)
end_define

begin_include
include|#
directive|include
file|<openbsd.h>
end_include

begin_comment
comment|/* Controlling the compilation driver.  */
end_comment

begin_comment
comment|/* alpha needs __start.  */
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
value|"%{!nostdlib:%{!r*:%{!e*:-e __start}}} -dc -dp %{assert*}"
end_define

begin_comment
comment|/* run-time target specifications */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__unix__ -D__ANSI_COMPAT -Asystem(unix) \ -D__OpenBSD__ -D__alpha__ -D__alpha"
end_define

begin_comment
comment|/* Layout of source language data types.  */
end_comment

begin_comment
comment|/* This must agree with<machine/ansi.h> */
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
value|"long int"
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
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_escape
end_escape

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

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* We don't have an init section yet.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_comment
comment|/* collect2 support (assembler format: macros for initialization).  */
end_comment

begin_comment
comment|/* Don't tell collect2 we use COFF as we don't have (yet ?) a dynamic ld    library with the proper functions to handle this -> collect2 will    default to using nm.  */
end_comment

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

begin_comment
comment|/* Assembler format: exception region output.  */
end_comment

begin_comment
comment|/* All configurations that don't use elf must be explicit about not using    dwarf unwind information. egcs doesn't try too hard to check internal    configuration files...  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INCOMING_RETURN_ADDR_RTX
end_ifdef

begin_undef
undef|#
directive|undef
name|DWARF2_UNWIND_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Assembler format: file framework.  */
end_comment

begin_comment
comment|/* Taken from alpha/osf.h. This used to be common to all alpha    configurations, but elf has departed from it.    Check alpha/alpha.h, alpha/osf.h for it when egcs is upgraded.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FILE_START
end_ifndef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{								\   alpha_write_verstamp (FILE);					\   fprintf (FILE, "\t.set noreorder\n");				\   fprintf (FILE, "\t.set volatile\n");                          \   fprintf (FILE, "\t.set noat\n");				\   if (TARGET_SUPPORT_ARCH)					\     fprintf (FILE, "\t.arch %s\n",				\              alpha_cpu == PROCESSOR_EV6 ? "ev6"			\ 	     : (alpha_cpu == PROCESSOR_EV5			\ 		? (TARGET_MAX ? "pca56" : TARGET_BWX ? "ev56" : "ev5") \ 		: "ev4"));					\ 								\   ASM_OUTPUT_SOURCE_FILENAME (FILE, main_input_filename);	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Assembler format: label output.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_WEAK_ALIAS
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {						\   fputs ("\t.weakext\t", FILE);			\   assemble_name (FILE, NAME);			\   if (VALUE)					\     {						\       fputs (" , ", FILE);			\       assemble_name (FILE, VALUE);		\     }						\   fputc ('\n', FILE);				\  } while (0)
end_define

end_unit

