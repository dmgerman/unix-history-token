begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for SPARC using a.out.    Copyright (C) 1994, 1996 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (sparc)");
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.    ??? It would be nice to not include any subtarget specific values here,    however there's no way to portably provide subtarget values to    CPP_PREFINES.  Also, -D values in CPP_SUBTARGET_SPEC don't get turned into    foo, __foo and __foo__.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dsparc -Acpu=sparc -Amachine=sparc"
end_define

begin_comment
comment|/* These compiler options take an argument.  We ignore -target for now.  */
end_comment

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)				\   || !strcmp (STR, "target") || !strcmp (STR, "assert"))
end_define

begin_comment
comment|/* This is defined differently for v9 in a cover file.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|T
parameter_list|,
name|RELOC
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{									\   if (TREE_CODE (T) == VAR_DECL)					\     {									\       if (TREE_READONLY (T)&& ! TREE_SIDE_EFFECTS (T)			\&& DECL_INITIAL (T)						\&& (DECL_INITIAL (T) == error_mark_node			\ 	      || TREE_CONSTANT (DECL_INITIAL (T)))			\&& DECL_ALIGN (T)<= MAX_TEXT_ALIGN				\&& ! (flag_pic&& ((RELOC) || SUNOS4_SHARED_LIBRARIES)))	\ 	text_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (T) == CONSTRUCTOR)				\     {									\       if (flag_pic&& ((RELOC) || SUNOS4_SHARED_LIBRARIES))		\ 	data_section ();						\     }									\   else if (TREE_CODE_CLASS (TREE_CODE (T)) == 'c')			\     {									\       if ((TREE_CODE (T) == STRING_CST&& flag_writable_strings)	\ 	  || TYPE_ALIGN (TREE_TYPE (T))> MAX_TEXT_ALIGN		\ 	  || (flag_pic&& ((RELOC) || SUNOS4_SHARED_LIBRARIES)))	\ 	data_section ();						\       else								\ 	text_section ();						\     }									\ }
end_define

begin_comment
comment|/* Output the label for a function definition.  */
end_comment

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
value|do {									\   ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\   ASM_OUTPUT_LABEL (FILE, NAME);					\ } while (0)
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.  In the flat model, the frame    pointer is really %i7.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(TARGET_FLAT&& REGNO == FRAME_POINTER_REGNUM ? 31 : REGNO)
end_define

begin_comment
comment|/* This is how to output a note to DBX telling it the line number    to which the following sequence of instructions corresponds.     This is needed for SunOS 4.0, and should not hurt for 3.2    versions either.  */
end_comment

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
value|{ static int sym_lineno = 1;				\     fprintf (file, ".stabn 68,0,%d,LM%d\nLM%d:\n",	\ 	     line, sym_lineno, sym_lineno);		\     sym_lineno += 1; }
end_define

end_unit

