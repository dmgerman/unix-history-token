begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ENCORE NS32000 version.    Copyright (C) 1988 Free Software Foundation, Inc.    Adapted by Robert Brown (brown@harvard.harvard.edu) from the Sequent      version by Michael Tiemann (tiemann@mcc.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_PREFIX
value|'?'
end_define

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|'$'
end_define

begin_include
include|#
directive|include
file|"ns32k.h"
end_include

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
end_define

begin_comment
comment|/* Cause long-jump assembler to be used,    since otherwise some files fail to be assembled right.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-j"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_BOUNDARY
end_undef

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND
end_undef

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND_ADDRESS
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF_AS_INT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|9
end_define

begin_comment
comment|/* 32332 with 32081.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (32000, Encore syntax)");
end_define

begin_comment
comment|/* Note Encore does not standardly do -Dencore.  */
end_comment

begin_comment
comment|/* budd: should have a -ns32332 (or -apc) switch! but no harm for now */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dns32000 -Dn16 -Dns16000 -Dns32332 -Dunix"
end_define

begin_comment
comment|/* Ignore certain cpp directives used in header files on sysV.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Output #ident as a .ident.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|fprintf (FILE, "\t.ident \"%s\"\n", NAME);
end_define

begin_comment
comment|/* The .file command should always begin the output.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|output_file_directive ((FILE), main_input_filename)
end_define

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|128
end_define

begin_comment
comment|/* speed optimization */
end_comment

begin_comment
comment|/*  *  The Encore assembler uses ".align 2" to align on 2-byte boundaries.  */
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
value|fprintf (FILE, "\t.align %d\n", 1<< (LOG))
end_define

begin_comment
comment|/*  *  Internal labels are prefixed with a period.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (LABEL, "*.%s%d", PREFIX, NUM)
end_define

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

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (FILE, "\t.word .L%d-.LI%d\n", VALUE, REL)
end_define

begin_comment
comment|/*  *  Different syntax for integer constants, double constants, and  *  uninitialized locals.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.double "),					\   output_addr_const (FILE, (VALUE)),				\   fprintf (FILE, "\n"))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF_AS_INT
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "\t.double\t");					\   ASM_OUTPUT_LABELREF (STREAM, NAME);					\   fprintf (STREAM, "\n");						\ } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.long 0f%.20e\n", (VALUE))
end_define

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
value|( fputs ("\t.bss ", (FILE)),					\   assemble_name ((FILE), (NAME)),				\   fprintf ((FILE), ",%u,%u\n", (SIZE), (ROUNDED)))
end_define

begin_comment
comment|/*   *  Encore assembler can't handle huge string constants like the one in   *  gcc.c.  If the default routine in varasm.c were more conservative, this   *  code could be eliminated.  It starts a new .ascii directive every 40   *  characters.   */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|file
parameter_list|,
name|p
parameter_list|,
name|size
parameter_list|)
define|\
value|{							\   for (i = 0; i< (size); i++)				\     {							\       register int c = (p)[i];				\       if ((i / 40) * 40 == i)				\       if (i == 0)					\         fprintf ((file), "\t.ascii \"");		\       else						\         fprintf ((file), "\"\n\t.ascii \"");		\       if (c == '\"' || c == '\\')			\         putc ('\\', (file));				\       if (c>= ' '&& c< 0177)				\         putc (c, (file));				\       else						\         {						\           fprintf ((file), "\\%o", c);			\           if (i< (size) - 1 				\&& (p)[i + 1]>= '0'&& (p)[i + 1]<= '9')\           fprintf ((file), "\"\n\t.ascii \"");		\         }						\     }							\   fprintf ((file), "\"\n");				\ }
end_define

begin_comment
comment|/* Modify syntax of jsr instructions.  */
end_comment

begin_define
define|#
directive|define
name|CALL_MEMREF_IMPLICIT
end_define

begin_define
define|#
directive|define
name|NO_ABSOLUTE_PREFIX_IF_SYMBOLIC
end_define

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
value|print_operand(FILE, X, CODE)
end_define

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
value|print_operand_address(FILE, ADDR)
end_define

begin_escape
end_escape

begin_comment
comment|/* Change the way in which data is allocated and initialized on the    encore so that both private and shared data are supported.  Shared data    that is initialized must be contained in the ".shrdata" section    of the program.  This is accomplished by defining the SHARED_SECTION_ASM_OP    macro.  Share data that is simply allocated, and not initialized must    be prefixed with the ".shrcomm" or ".shrbss" pseudo op, for common or    local data respectively.  This is accomplished by redefining the    ASM_OUTPUT_COMMON and ASM_OUTPUT_LOCAL macros. */
end_comment

begin_comment
comment|/* Assembler pseudo-op for shared data segment. */
end_comment

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|".shrdata"
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a shared common symbol. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHARED_COMMON
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
value|( fputs (".shrcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%d\n", (ROUNDED)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a shared local symbol. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHARED_LOCAL
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
value|( fputs ("\t.shrbss ", (FILE)),				\   assemble_name ((FILE), (NAME)),			\   fprintf ((FILE), ",%d,%d\n", (SIZE), (ROUNDED)))
end_define

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fprintf (FILE, "\taddr .LP%d,r0\n\tjsr mcount\n", (LABELNO))
end_define

begin_define
define|#
directive|define
name|ENCORE_ASM
end_define

end_unit

