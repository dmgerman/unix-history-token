begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for "naked" Intel 386 using coff object format files    and coff debugging info.     Copyright (C) 1994 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Di386"
end_define

begin_comment
comment|/* We want to be able to get DBX debugging information via -gstabs.  */
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

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|SDB_DEBUG
end_define

begin_comment
comment|/* Support the ctors and dtors sections for g++.  */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors,\"x\""
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t.dtors,\"x\""
end_define

begin_comment
comment|/* A list of other sections which the compiler might be "in" at any    given time.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_ctors, in_dtors
end_define

begin_comment
comment|/* A list of extra section function definitions.  */
end_comment

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
value|CTORS_SECTION_FUNCTION						\   DTORS_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_FUNCTION
define|\
value|void									\ ctors_section ()							\ {									\   if (in_section != in_ctors)						\     {									\       fprintf (asm_out_file, "%s\n", CTORS_SECTION_ASM_OP);		\       in_section = in_ctors;						\     }									\ }
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_FUNCTION
define|\
value|void									\ dtors_section ()							\ {									\   if (in_section != in_dtors)						\     {									\       fprintf (asm_out_file, "%s\n", DTORS_SECTION_ASM_OP);		\       in_section = in_dtors;						\     }									\ }
end_define

begin_define
define|#
directive|define
name|INT_ASM_OP
value|".long"
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global constructors.  */
end_comment

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
value|do {									\     ctors_section ();							\     fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\     assemble_name (FILE, NAME);						\     fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global destructors.  */
end_comment

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
value|do {									\     dtors_section ();                   				\     fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\     assemble_name (FILE, NAME);              				\     fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* end of i386-coff.h */
end_comment

end_unit

