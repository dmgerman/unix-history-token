begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target macros for mips*-elf targets.    Copyright (C) 1994, 1997, 1999, 2000, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* MIPS assemblers don't have the usual .set foo,bar construct;    .set is used for assembler options instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do								\     {								\       fputc ('\t', FILE);					\       assemble_name (FILE, LABEL1);				\       fputs (" = ", FILE);					\       assemble_name (FILE, LABEL2);				\       fputc ('\n', FILE);					\     }								\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
value|mips_declare_object_name
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINISH_DECLARE_OBJECT
end_undef

begin_define
define|#
directive|define
name|ASM_FINISH_DECLARE_OBJECT
value|mips_finish_declare_object
end_define

begin_comment
comment|/* Leave the linker script to choose the appropriate libraries.  */
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
value|""
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
value|"crti%O%s crtbegin%O%s"
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
value|"crtend%O%s crtn%O%s"
end_define

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
value|1
end_define

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
value|1
end_define

end_unit

