begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Sun assembler syntax for the Intel 80386.    Copyright (C) 1988, 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Include common aspects of all 386 Unix assemblers.  */
end_comment

begin_include
include|#
directive|include
file|"i386/unix.h"
end_include

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (80386, Sun syntax)");
end_define

begin_comment
comment|/* Define the syntax of instructions and addresses.  */
end_comment

begin_comment
comment|/* Prefix for internally generated assembler labels.  */
end_comment

begin_define
define|#
directive|define
name|LPREFIX
value|".L"
end_define

begin_comment
comment|/* Define the syntax of pseudo-ops, labels and comments.  */
end_comment

begin_comment
comment|/* Assembler pseudos to introduce constants of various size.  */
end_comment

begin_define
define|#
directive|define
name|ASM_BYTE_OP
value|"\t.byte"
end_define

begin_define
define|#
directive|define
name|ASM_SHORT
value|"\t.value"
end_define

begin_define
define|#
directive|define
name|ASM_LONG
value|"\t.long"
end_define

begin_define
define|#
directive|define
name|ASM_DOUBLE
value|"\t.double"
end_define

begin_comment
comment|/* How to output an ASCII string constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|p
parameter_list|,
name|size
parameter_list|)
define|\
value|do								\ { int i = 0; 							\   while (i< (size))						\     { if (i%10 == 0) { if (i!=0) fprintf ((FILE), "\n");	\ 		       fprintf ((FILE), "%s ", ASM_BYTE_OP); }	\       else fprintf ((FILE), ",");				\       fprintf ((FILE), "0x%x", ((p)[i++]& 0377)) ;}		\       fprintf ((FILE), "\n");					\ } while (0)
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
value|do {							\     extern char *version_string, *language_string;	\     {							\       int len = strlen (main_input_filename);		\       char *na = main_input_filename + len;		\       char shorter[15];					\
comment|/* NA gets MAIN_INPUT_FILENAME sans directory names.  */
value|\       while (na> main_input_filename)			\ 	{						\ 	  if (na[-1] == '/')				\ 	    break;					\ 	  na--;						\ 	}						\       strncpy (shorter, na, 14);			\       shorter[14] = 0;					\       fprintf (FILE, "\t.file\t");			\       output_quoted_string (FILE, shorter);		\       fprintf (FILE, "\n");				\     }							\     fprintf (FILE, "\t.version\t\"%s %s\"\n",		\ 	     language_string, version_string);		\     if (optimize) ASM_FILE_START_1 (FILE);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_FILE_START_1
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "\t.optim\n")
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

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
comment|/* This is how to output an assembler line    that says to advance the location counter by SIZE bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf ((FILE), "\t.set\t.,.+%u\n", (SIZE))
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* Define the syntax of labels and symbol definitions/declarations.  */
end_comment

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
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
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

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

begin_comment
comment|/* This is how to store into the string BUF    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|BUF
parameter_list|,
name|PREFIX
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUF), "*.%s%d", (PREFIX), (NUMBER))
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols. */
end_comment

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, ".%s%d:\n", PREFIX, NUM)
end_define

end_unit

