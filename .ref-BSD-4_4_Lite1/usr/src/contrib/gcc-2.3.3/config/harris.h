begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Harris tahoe version.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tahoe.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dtahoe -Dunix -Dhcx"
end_define

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_comment
comment|/* urem and udiv don't exist on this system.  */
end_comment

begin_undef
undef|#
directive|undef
name|UDIVSI3_LIBCALL
end_undef

begin_undef
undef|#
directive|undef
name|UMODSI3_LIBCALL
end_undef

begin_comment
comment|/* Operand of .align is not logarithmic.  */
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
value|LOG ? fprintf (FILE, "\t.align %d\n", 1<< (LOG)) : 0
end_define

begin_comment
comment|/* For the same reason, we need .align 2 after casesi.  */
end_comment

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND
end_undef

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
define|\
value|{ if (CODE == '@')							\     putc ('2', FILE);							\   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_names[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     output_address (XEXP (X, 0));					\   else { putc ('$', FILE); output_addr_const (FILE, X); }}
end_define

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
value|( fputs (".bss ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,4\n", (ROUNDED)))
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
value|output_file_directive ((FILE), main_input_filename);
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|PTR
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{							\   unsigned char *_p = (PTR);				\   int _thissize = (SIZE);				\   fprintf ((FILE), "\t.ascii \"");			\   for (i = 0; i< _thissize; i++)			\     {							\       register int c = _p[i];				\       if (c>= ' '&& c< 0177&& c != '\"'&& c != '\\') \ 	putc (c, (FILE));				\       else						\ 	{						\ 	  fprintf ((FILE), "\\%o", c);			\ 	  if (i< _thissize - 1				\&& _p[i + 1]>= '0'&& _p[i + 1]<= '9')	\ 	    fprintf ((FILE), "\"\n\t.ascii \"");	\ 	}						\     }							\   fprintf ((FILE), "\"\n");				\ }
end_define

end_unit

