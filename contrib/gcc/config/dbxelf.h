begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions needed when using stabs embedded in ELF sections.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file may be included by any ELF target which wishes to    support -gstabs generating stabs in sections, as produced by gas    and understood by gdb.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DBX_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|__DBX_ELF_H
end_define

begin_comment
comment|/* Output DBX (stabs) debugging information if doing -gstabs.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Make LBRAC and RBRAC addresses relative to the start of the    function.  The native Solaris stabs debugging format works this    way, gdb expects it, and it reduces the number of relocation    entries...  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_BLOCKS_FUNCTION_RELATIVE
end_undef

begin_define
define|#
directive|define
name|DBX_BLOCKS_FUNCTION_RELATIVE
value|1
end_define

begin_comment
comment|/* ... but, to make this work, functions must appear prior to line info.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_FUNCTION_FIRST
end_undef

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
end_define

begin_comment
comment|/* When generating stabs debugging, use N_BINCL entries.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_USE_BINCL
end_undef

begin_define
define|#
directive|define
name|DBX_USE_BINCL
end_define

begin_comment
comment|/* There is no limit to the length of stabs strings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBX_CONTIN_LENGTH
end_ifndef

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* When using stabs, gcc2_compiled must be a stabs entry, not an    ordinary symbol, or gdb won't see it.  Furthermore, since gdb reads    the input piecemeal, starting with each N_SO, it's a lot easier if    the gcc2 flag symbol is *after* the N_SO rather than before it.  So    we emit an N_OPT stab there.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do									\   {									\     if (write_symbols != DBX_DEBUG)					\       fputs ("gcc2_compiled.:\n", FILE);				\   }									\ while (0)
end_define

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC_AFTER_SOURCE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do									\   {									\     if (write_symbols == DBX_DEBUG)					\       fputs ("\t.stabs\t\"gcc2_compiled.\", 0x3c, 0, 0, 0\n", FILE);	\   }									\ while (0)
end_define

begin_comment
comment|/* Like block addresses, stabs line numbers are relative to the    current function.  */
end_comment

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
name|FILE
parameter_list|,
name|LINE
parameter_list|)
define|\
value|do									\   {									\     static int sym_lineno = 1;						\     char temp[256];							\     ASM_GENERATE_INTERNAL_LABEL (temp, "LM", sym_lineno);		\     fprintf (FILE, ".stabn 68,0,%d,", LINE);				\     assemble_name (FILE, temp);						\     putc ('-', FILE);							\     assemble_name (FILE,						\ 		   XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));\     putc ('\n', FILE);							\     ASM_OUTPUT_INTERNAL_LABEL (FILE, "LM", sym_lineno);			\     sym_lineno += 1;							\   }									\ while (0)
end_define

begin_comment
comment|/* Generate a blank trailing N_SO to mark the end of the .o file, since    we can't depend upon the linker to mark .o file boundaries with    embedded stabs.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
end_undef

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
value|asm_fprintf (FILE,							\ 	       "\t.text\n\t.stabs \"\",%d,0,0,%LLetext\n%LLetext:\n", N_SO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DBX_ELF_H */
end_comment

end_unit

