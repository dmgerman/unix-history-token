begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nextstep.h -- operating system specific defines to be used when    targeting GCC for NeXTSTEP.    Copyright (C) 1989, 1990, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* changed for NeXTStep 2.1, Ch. Kranz, 2/94, 3/94 */
end_comment

begin_include
include|#
directive|include
file|"nextstep.h"
end_include

begin_comment
comment|/* set flag_gnu_linker=0, use collect2 for linking */
end_comment

begin_undef
undef|#
directive|undef
name|USE_COLLECT2
end_undef

begin_define
define|#
directive|define
name|USE_COLLECT2
end_define

begin_comment
comment|/* use this until a newer gdb for NeXTStep21 is available */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|0
end_define

begin_comment
comment|/* we need the call to __main to start all global destructors and constructors    correctly, so undef INIT_SECTION_ASM_OP, (see libgcc2.c line 1965)     and define INVOKE_main */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INVOKE__main
end_define

begin_comment
comment|/* We call the global destructors, constructors from __main */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CONSTRUCTOR
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DESTRUCTOR
end_undef

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
value|do {								\     extern char *language_string;				\       if (strcmp (language_string, "GNU C++") == 0)		\       {								\ 	ASM_OUTPUT_ALIGN (FILE, 1);				\       }								\   } while (0)
end_define

begin_comment
comment|/* deleted: destructor_section ();				\ */
end_comment

begin_comment
comment|/* deleted: constructor_section ();				\ */
end_comment

begin_comment
comment|/* Ensure correct alignment of bss data.  */
end_comment

begin_comment
comment|/* ASM_OUTPUT_ALIGNED_LOCAL not needed */
end_comment

begin_comment
comment|/* need ASM_OUTPUT_LOCAL instead for old NeXT-as */
end_comment

begin_comment
comment|/* look in varasm.c, line 1062 and 1476 */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs (".lcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
end_define

end_unit

