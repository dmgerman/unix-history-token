begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for AT&T assembler syntax for the Intel 80386.    Copyright (C) 1988, 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|fprintf (stderr, " (80386, ATT syntax)");
end_define

begin_escape
end_escape

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
comment|/* Assembler pseudos to introduce constants of various size.  */
end_comment

begin_comment
comment|/* #define ASM_BYTE_OP "\t.byte"  Now in svr3.h or svr4.h.  */
end_comment

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
value|do								\ { int i = 0; 							\   while (i< (size))						\     { if (i%10 == 0) { if (i!=0) fprintf ((FILE), "\n");	\ 		       fprintf ((FILE), "%s ", ASM_BYTE_OP); }	\       else fprintf ((FILE), ",");				\ 	fprintf ((FILE), "0x%x", ((p)[i++]& 0377)) ;}		\       fprintf ((FILE), "\n");					\ } while (0)
end_define

begin_comment
comment|/* Do use .optim by default on this machine.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START_1
end_undef

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
value|fprintf ((FILE), "\t.set .,.+%u\n", (SIZE))
end_define

begin_comment
comment|/* Can't use ASM_OUTPUT_SKIP in text section; it doesn't leave 0s.  */
end_comment

begin_define
define|#
directive|define
name|ASM_NO_SKIP_IN_TEXT
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the syntax of labels and symbol definitions/declarations.  */
end_comment

begin_comment
comment|/* This is how to store into the string BUF    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

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
value|sprintf ((BUF), ".%s%d", (PREFIX), (NUMBER))
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

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

begin_comment
comment|/* The prefix to add to user-visible assembler symbols. */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

end_unit

