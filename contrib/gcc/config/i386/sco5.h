begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running SCO Unix System V 3.2 Version 5.    Copyright (C) 1992, 95-98, 1999 Free Software Foundation, Inc.    Contributed by Kean Johnston (hug@netcom.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/i386.h"
end_include

begin_comment
comment|/* Base i386 target definitions */
end_comment

begin_include
include|#
directive|include
file|"i386/att.h"
end_include

begin_comment
comment|/* Use AT&T i386 assembler syntax */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386, SCO OpenServer 5 Syntax)");
end_define

begin_undef
undef|#
directive|undef
name|LPREFIX
end_undef

begin_define
define|#
directive|define
name|LPREFIX
value|".L"
end_define

begin_undef
undef|#
directive|undef
name|ALIGN_ASM_OP
end_undef

begin_define
define|#
directive|define
name|ALIGN_ASM_OP
value|"\t.align"
end_define

begin_undef
undef|#
directive|undef
name|ASCII_DATA_ASM_OP
end_undef

begin_define
define|#
directive|define
name|ASCII_DATA_ASM_OP
value|"\t.ascii"
end_define

begin_undef
undef|#
directive|undef
name|ASM_BYTE_OP
end_undef

begin_define
define|#
directive|define
name|ASM_BYTE_OP
value|"\t.byte"
end_define

begin_undef
undef|#
directive|undef
name|IDENT_ASM_OP
end_undef

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|"\t.ident"
end_define

begin_undef
undef|#
directive|undef
name|COMMON_ASM_OP
end_undef

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|"\t.comm"
end_define

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set"
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_ASM_OP
end_undef

begin_define
define|#
directive|define
name|LOCAL_ASM_OP
value|"\t.local"
end_define

begin_undef
undef|#
directive|undef
name|INT_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INT_ASM_OP
value|"\t.long"
end_define

begin_undef
undef|#
directive|undef
name|ASM_SHORT
end_undef

begin_define
define|#
directive|define
name|ASM_SHORT
value|"\t.value"
end_define

begin_undef
undef|#
directive|undef
name|ASM_LONG
end_undef

begin_define
define|#
directive|define
name|ASM_LONG
value|"\t.long"
end_define

begin_undef
undef|#
directive|undef
name|ASM_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_DOUBLE
value|"\t.double"
end_define

begin_undef
undef|#
directive|undef
name|TYPE_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|"\t.type"
end_define

begin_undef
undef|#
directive|undef
name|SIZE_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|"\t.size"
end_define

begin_undef
undef|#
directive|undef
name|STRING_ASM_OP
end_undef

begin_define
define|#
directive|define
name|STRING_ASM_OP
value|"\t.string"
end_define

begin_undef
undef|#
directive|undef
name|SKIP_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SKIP_ASM_OP
value|"\t.zero"
end_define

begin_undef
undef|#
directive|undef
name|GLOBAL_ASM_OP
end_undef

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"\t.globl"
end_define

begin_undef
undef|#
directive|undef
name|EH_FRAME_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_ASM_OP_COFF
value|"\t.section\t.ehfram, \"x\""
end_define

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_ASM_OP_ELF
value|"\t.section\t.eh_frame, \"aw\""
end_define

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_ASM_OP
define|\
value|((TARGET_ELF) ? EH_FRAME_SECTION_ASM_OP_ELF : EH_FRAME_SECTION_ASM_OP_COFF)
end_define

begin_comment
comment|/* Avoid problems (long sectino names, forward assembler refs) with DWARF    exception unwinding when we're generating COFF */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
define|\
value|((TARGET_ELF) ? 1 : 0 )
end_define

begin_undef
undef|#
directive|undef
name|CONST_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP_COFF
value|"\t.section\t.rodata, \"x\""
end_define

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP_ELF
value|"\t.section\t.rodata"
end_define

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
define|\
value|((TARGET_ELF) ? CONST_SECTION_ASM_OP_ELF : CONST_SECTION_ASM_OP_COFF)
end_define

begin_undef
undef|#
directive|undef
name|USE_CONST_SECTION
end_undef

begin_define
define|#
directive|define
name|USE_CONST_SECTION_ELF
value|1
end_define

begin_define
define|#
directive|define
name|USE_CONST_SECTION_COFF
value|0
end_define

begin_define
define|#
directive|define
name|USE_CONST_SECTION
define|\
value|((TARGET_ELF) ? USE_CONST_SECTION_ELF : USE_CONST_SECTION_COFF)
end_define

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP_ELF
value|"\t.section\t.init"
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP_COFF
value|"\t.section\t.init ,\"x\""
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
define|\
value|((TARGET_ELF) ? INIT_SECTION_ASM_OP_ELF : INIT_SECTION_ASM_OP_COFF)
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP_ELF
value|"\t.section\t.ctors,\"aw\""
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP_COFF
value|INIT_SECTION_ASM_OP_COFF
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
define|\
value|((TARGET_ELF) ? CTORS_SECTION_ASM_OP_ELF : CTORS_SECTION_ASM_OP_COFF)
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP_ELF
value|"\t.section\t.dtors, \"aw\""
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP_COFF
value|FINI_SECTION_ASM_OP_COFF
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
define|\
value|((TARGET_ELF) ? DTORS_SECTION_ASM_OP_ELF : DTORS_SECTION_ASM_OP_COFF)
end_define

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP_ELF
value|"\t.section\t.fini"
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP_COFF
value|"\t.section\t.fini, \"x\""
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
define|\
value|((TARGET_ELF) ? FINI_SECTION_ASM_OP_ELF : FINI_SECTION_ASM_OP_COFF)
end_define

begin_undef
undef|#
directive|undef
name|BSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.data"
end_define

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"@%s"
end_define

begin_undef
undef|#
directive|undef
name|APPLY_RESULT_SIZE
end_undef

begin_define
define|#
directive|define
name|APPLY_RESULT_SIZE
define|\
value|(TARGET_ELF) ? size : 116
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_RESULT
end_ifndef

begin_define
define|#
directive|define
name|ASM_DECLARE_RESULT
parameter_list|(
name|FILE
parameter_list|,
name|RESULT
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCO_DEFAULT_ASM_COFF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\       ASM_OUTPUT_LABEL (FILE, NAME);					\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

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
value|do {									\     if (TARGET_ELF) {							\       fprintf (FILE, "%s\t ", TYPE_ASM_OP);				\       assemble_name (FILE, NAME);					\       putc (',', FILE);							\       fprintf (FILE, TYPE_OPERAND_FMT, "function");			\       putc ('\n', FILE);						\       ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\       ASM_OUTPUT_LABEL(FILE, NAME);					\     } else								\       SCO_DEFAULT_ASM_COFF(FILE, NAME);					\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_SIZE
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|FILE
parameter_list|,
name|FNAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF) { if (!flag_inhibit_size_directive)			\       {									\ 	fprintf (FILE, "%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\         fprintf (FILE, ",.-");						\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }	}								\   } while (0)
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
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF) {							\       fprintf (FILE, "%s\t ", TYPE_ASM_OP);				\       assemble_name (FILE, NAME);					\       putc (',', FILE);							\       fprintf (FILE, TYPE_OPERAND_FMT, "object");			\       putc ('\n', FILE);						\       size_directive_output = 0;					\       if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\         {								\   	size_directive_output = 1;					\ 	fprintf (FILE, "%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL)));	\         }								\       ASM_OUTPUT_LABEL(FILE, NAME);					\     } else								\       SCO_DEFAULT_ASM_COFF(FILE, NAME);					\   } while (0)
end_define

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
end_define

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
value|do {									\   output_file_directive((FILE),main_input_filename);			\   fprintf ((FILE), "\t.version\t\"01.01\"\n");				\ } while (0)
end_define

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
value|do {									\      if (!flag_no_ident)						\ 	fprintf ((FILE), "%s\t\"GCC: (GNU) %s\"\n",			\ 		 IDENT_ASM_OP, version_string);				\ } while (0)
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
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|TOP_LEVEL
parameter_list|,
name|AT_END
parameter_list|)
define|\
value|do {									 \   if (TARGET_ELF) {							\      char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);			 \      if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)		 \&& ! AT_END&& TOP_LEVEL					 \&& DECL_INITIAL (DECL) == error_mark_node			 \&& !size_directive_output)					 \        {								 \ 	 size_directive_output = 1;					 \ 	 fprintf (FILE, "%s\t ", SIZE_ASM_OP);			 	 \ 	 assemble_name (FILE, name);					 \ 	 fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL))); \        }								 \     }									 \ } while (0)
end_define

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
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF)							\     sprintf (LABEL, "*.%s%d", (PREFIX), (NUM));				\   else									\     sprintf (LABEL, ".%s%d", (PREFIX), (NUM));				\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF)							\     fprintf (FILE, "%s _GLOBAL_OFFSET_TABLE_+[.-%s%d]\n", ASM_LONG, LPREFIX, VALUE); \   else									\     fprintf (FILE, "\t.word %s%d-%s%d\n", LPREFIX,VALUE,LPREFIX,REL);	\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\   fprintf ((FILE), "%s\t", COMMON_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   if (TARGET_ELF)							\     fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\   else									\     fprintf ((FILE), ",%u\n", (SIZE));					\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF) {							\     fprintf ((FILE), "%s\t", LOCAL_ASM_OP);				\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), "\n");						\     ASM_OUTPUT_ALIGNED_COMMON (FILE, NAME, SIZE, ALIGN);		\   } else {								\     int align = exact_log2 (ALIGN);					\     if (align> 2) align = 2;						\     if (TARGET_SVR3_SHLIB)						\       data_section ();							\     else								\       bss_section ();							\     ASM_OUTPUT_ALIGN ((FILE), align == -1 ? 2 : align);			\     fprintf ((FILE), "%s\t", "\t.lcomm");				\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), ",%u\n", (SIZE));					\    }									\ } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream    FILE the assembler definition of uninitialized global DECL named    NAME whose size is SIZE bytes and alignment is ALIGN bytes.    Try to use asm_output_aligned_bss to implement this macro.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
end_define

begin_undef
undef|#
directive|undef
name|ESCAPES
end_undef

begin_define
define|#
directive|define
name|ESCAPES
define|\
value|"\1\1\1\1\1\1\1\1btn\1fr\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \0\0\"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\\\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1"
end_define

begin_undef
undef|#
directive|undef
name|STRING_LIMIT
end_undef

begin_define
define|#
directive|define
name|STRING_LIMIT
value|((unsigned) 256)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LIMITED_STRING
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LIMITED_STRING
parameter_list|(
name|FILE
parameter_list|,
name|STR
parameter_list|)
define|\
value|do									\     {									\       register unsigned char *_limited_str = (unsigned char *) (STR);	\       register unsigned ch;						\       fprintf ((FILE), "%s\t\"", STRING_ASM_OP);			\       for (; (ch = *_limited_str); _limited_str++)			\         {								\ 	  register int escape;						\ 	  switch (escape = ESCAPES[ch])					\ 	    {								\ 	    case 0:							\ 	      putc (ch, (FILE));					\ 	      break;							\ 	    case 1:							\ 	      fprintf ((FILE), "\\%03o", ch);				\ 	      break;							\ 	    default:							\ 	      putc ('\\', (FILE));					\ 	      putc (escape, (FILE));					\ 	      break;							\ 	    }								\         }								\       fprintf ((FILE), "\"\n");						\     }									\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|STR
parameter_list|,
name|LENGTH
parameter_list|)
define|\
value|do {									\       register unsigned char *_ascii_bytes = (unsigned char *) (STR);	\       register unsigned char *limit = _ascii_bytes + (LENGTH);		\       register unsigned bytes_in_chunk = 0;				\       for (; _ascii_bytes< limit; _ascii_bytes++)			\         {								\ 	  register unsigned char *p;					\ 	  if (bytes_in_chunk>= 64)					\ 	    {								\ 	      fputc ('\n', (FILE));					\ 	      bytes_in_chunk = 0;					\ 	    }								\ 	  for (p = _ascii_bytes; p< limit&& *p != '\0'; p++)		\ 	    continue;							\ 	  if (p< limit&& (p - _ascii_bytes)<= STRING_LIMIT)		\ 	    {								\ 	      if (bytes_in_chunk> 0)					\ 		{							\ 		  fputc ('\n', (FILE));					\ 		  bytes_in_chunk = 0;					\ 		}							\ 	      ASM_OUTPUT_LIMITED_STRING ((FILE), _ascii_bytes);		\ 	      _ascii_bytes = p;						\ 	    }								\ 	  else								\ 	    {								\ 	      if (bytes_in_chunk == 0)					\ 		fprintf ((FILE), "%s\t", ASM_BYTE_OP);			\ 	      else							\ 		fputc (',', (FILE));					\ 	      fprintf ((FILE), "0x%02x", *_ascii_bytes);		\ 	      bytes_in_chunk += 5;					\ 	    }								\ 	}								\       if (bytes_in_chunk> 0)						\         fprintf ((FILE), "\n");						\ } while (0)
end_define

begin_comment
comment|/* Must use data section for relocatable constants when pic.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|)
define|\
value|{									\   if (TARGET_ELF) {							\     if (flag_pic&& symbolic_operand (RTX))				\       data_section ();							\     else								\       const_section ();							\   } else								\     readonly_data_section();						\ }
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|JUMPTABLE
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF)							\     ASM_OUTPUT_ALIGN ((FILE), 2);					\   ASM_OUTPUT_INTERNAL_LABEL((FILE),(PREFIX),(NUM));			\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CONSTRUCTOR
end_undef

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
value|do {									\   if (TARGET_ELF) {							\      ctors_section ();							\      fprintf (FILE, "%s\t ", INT_ASM_OP);				\      assemble_name (FILE, NAME);					\      fprintf (FILE, "\n");						\   } else {								\     init_section ();							\     fprintf (FILE, "\tpushl $");					\     assemble_name (FILE, NAME);						\     fprintf (FILE, "\n"); }						\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DESTRUCTOR
end_undef

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
value|do {									\   if (TARGET_ELF) {							\     dtors_section ();                   				\     fprintf (FILE, "%s\t ", INT_ASM_OP);				\     assemble_name (FILE, NAME);              				\     fprintf (FILE, "\n");						\   } else {								\     fini_section ();                   					\     fprintf (FILE, "%s\t ", ASM_LONG);					\     assemble_name (FILE, NAME);              				\     fprintf (FILE, "\n"); }						\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_IDENT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "%s\t\"%s\"\n", IDENT_ASM_OP, NAME);
end_define

begin_undef
undef|#
directive|undef
name|ASM_GLOBALIZE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|(fprintf ((FILE), "%s ", GLOBAL_ASM_OP), assemble_name (FILE, NAME), fputs ("\n", FILE))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_EXTERNAL_LIBCALL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|FILE
parameter_list|,
name|FUN
parameter_list|)
define|\
value|if (TARGET_ELF) ASM_GLOBALIZE_LABEL (FILE, XSTR (FUN, 0))
end_define

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

begin_comment
comment|/*   * Compensate for the difference between ELF and COFF assembler syntax.  * Otherwise, this is cribbed from ../svr4.h.  * We rename 'gcc_except_table' to the shorter name in preparation  * for the day when we're ready to do DWARF2 eh unwinding under COFF   */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SECTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SECTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|do {									\   static struct section_info                                            \     {                                                                   \       struct section_info *next;                                        \       char *name;                                                       \       enum sect_enum {SECT_RW, SECT_RO, SECT_EXEC} type;                \     } *sections;                                                        \   struct section_info *s;                                               \   char *mode;                                                           \   enum sect_enum type;                                                  \   char *sname = NAME ;							\   if (strcmp(NAME, ".gcc_except_table") == 0) sname = ".gccexc" ;	\                                                                         \   for (s = sections; s; s = s->next)                                    \     if (!strcmp (NAME, s->name))                                        \       break;                                                            \                                                                         \   if (DECL&& TREE_CODE (DECL) == FUNCTION_DECL)                        \     type = SECT_EXEC, mode = (TARGET_ELF) ? "ax" : "x" ;                \   else if (DECL&& DECL_READONLY_SECTION (DECL, RELOC))                 \     type = SECT_RO, mode = "a";                                         \   else                                                                  \     type = SECT_RW, mode = (TARGET_ELF) ? "aw" : "w" ;                  \                                                                         \   if (s == 0)                                                           \     {                                                                   \       s = (struct section_info *) xmalloc (sizeof (struct section_info));  \       s->name = xmalloc ((strlen (NAME) + 1) * sizeof (*NAME));         \       strcpy (s->name, NAME);                                           \       s->type = type;                                                   \       s->next = sections;                                               \       sections = s;                                                     \       fprintf (FILE, ".section\t%s,\"%s\"%s\n", sname, mode,		\ 		(TARGET_ELF) ? ",@progbits" : "" );    			\     }                                                                   \   else                                                                  \     {                                                                   \       if (DECL&& s->type != type)                                      \         error_with_decl (DECL, "%s causes a section type conflict");    \                                                                         \       fprintf (FILE, ".section\t%s\n", sname);                          \     }                                                                   \ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

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
value|do {									\   if (TARGET_ELF)							\     fprintf (FILE, "%s\t%u\n", SKIP_ASM_OP, (SIZE));			\   else									\     fprintf ((FILE), "%s\t.,.+%u\n", SET_ASM_OP, (SIZE));		\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|CTOR_LIST_BEGIN
end_undef

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
define|\
value|do {									\   asm (CTORS_SECTION_ASM_OP);						\   if (TARGET_ELF)							\     STATIC func_ptr __CTOR_LIST__[1] = { (func_ptr) (-1) };		\   else									\     asm ("pushl $0");							\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|CTOR_LIST_END
end_undef

begin_define
define|#
directive|define
name|CTOR_LIST_END
define|\
value|do {									\   if (TARGET_ELF) {							\     asm (CTORS_SECTION_ASM_OP);						\     STATIC func_ptr __CTOR_LIST__[1] = { (func_ptr) (0) };		\   } else {								\     CTOR_LIST_BEGIN;							\   }									\ } while (0)
end_define

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

begin_undef
undef|#
directive|undef
name|DBX_FUNCTION_FIRST
end_undef

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
value|1
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
name|n
parameter_list|)
define|\
value|((TARGET_ELF) ?								\  ((n) == 0 ? 0 								\   : (n) == 1 ? 2 							\   : (n) == 2 ? 1 							\   : (n) == 3 ? 3 							\   : (n) == 4 ? 6 							\   : (n) == 5 ? 7 							\   : (n) == 6 ? 5 							\   : (n) == 7 ? 4 							\   : ((n)>= FIRST_STACK_REG&& (n)<= LAST_STACK_REG) ? (n)+3 		\   : (-1))								\  :									\  ((n) == 0 ? 0 : 							\   (n) == 1 ? 2 : 							\   (n) == 2 ? 1 : 							\   (n) == 3 ? 3 : 							\   (n) == 4 ? 6 : 							\   (n) == 5 ? 7 : 							\   (n) == 6 ? 4 : 							\   (n) == 7 ? 5 : 							\   (n) + 4))
end_define

begin_undef
undef|#
directive|undef
name|DWARF_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|DWARF_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
define|\
value|((TARGET_ELF) ? DWARF_DEBUG: SDB_DEBUG)
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_const, in_init, in_fini, in_ctors, in_dtors
end_define

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
value|CONST_SECTION_FUNCTION						\   INIT_SECTION_FUNCTION							\   FINI_SECTION_FUNCTION							\   CTORS_SECTION_FUNCTION						\   DTORS_SECTION_FUNCTION
end_define

begin_undef
undef|#
directive|undef
name|CONST_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|CONST_SECTION_FUNCTION
define|\
value|void									\ const_section ()							\ {									\   extern void text_section();						\   if (!USE_CONST_SECTION)						\     text_section();							\   else if (in_section != in_const)					\     {									\       fprintf (asm_out_file, "%s\n", CONST_SECTION_ASM_OP);		\       in_section = in_const;						\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|FINI_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|FINI_SECTION_FUNCTION
define|\
value|void									\ fini_section ()								\ {									\   if ((!TARGET_ELF)&& in_section != in_fini)				\     {									\       fprintf (asm_out_file, "%s\n", FINI_SECTION_ASM_OP);		\       in_section = in_fini;						\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|INIT_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_FUNCTION
define|\
value|void									\ init_section ()								\ {									\   if ((!TARGET_ELF)&& in_section != in_init)				\     {									\       fprintf (asm_out_file, "%s\n", INIT_SECTION_ASM_OP);		\       in_section = in_init;						\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_FUNCTION
define|\
value|void									\ ctors_section ()							\ {									\   if (in_section != in_ctors)						\     {									\       fprintf (asm_out_file, "%s\n", CTORS_SECTION_ASM_OP);		\       in_section = in_ctors;						\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_FUNCTION
define|\
value|void									\ dtors_section ()							\ {									\   if (in_section != in_dtors)						\     {									\       fprintf (asm_out_file, "%s\n", DTORS_SECTION_ASM_OP);		\       in_section = in_dtors;						\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|FRAME_POINTER_REQUIRED
end_undef

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
define|\
value|((TARGET_ELF) ? 0 : 							\    (current_function_calls_setjmp || current_function_calls_longjmp))
end_define

begin_undef
undef|#
directive|undef
name|JUMP_TABLES_IN_TEXT_SECTION
end_undef

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|(TARGET_ELF&& flag_pic)
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
define|\
value|((TARGET_ELF) ? "" : ".")
end_define

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/ccs/bin/"
end_define

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/ccs/lib/"
end_define

begin_undef
undef|#
directive|undef
name|NON_SAVING_SETJMP
end_undef

begin_define
define|#
directive|define
name|NON_SAVING_SETJMP
define|\
value|((TARGET_ELF) ? 0 : 							\    (current_function_calls_setjmp&& current_function_calls_longjmp))
end_define

begin_undef
undef|#
directive|undef
name|NO_IMPLICIT_EXTERN_C
end_undef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
value|1
end_define

begin_comment
comment|/* JKJ FIXME - examine the ramifications of RETURN_IN_MEMORY and    RETURN_POPS_ARGS */
end_comment

begin_undef
undef|#
directive|undef
name|RETURN_POPS_ARGS
end_undef

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|((TARGET_ELF) ?							\   (i386_return_pops_args (FUNDECL, FUNTYPE, SIZE)) : 			\   (((FUNDECL)&& (TREE_CODE (FUNDECL) == IDENTIFIER_NODE)) ? 0		\    : (TARGET_RTD							\&& (TYPE_ARG_TYPES (FUNTYPE) == 0					\ 	  || (TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE)))		\ 	      == void_type_node))) ? (SIZE)				\    : 0))
end_define

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|{									\   if (TARGET_ELF&& flag_pic&& RELOC)					\      data_section ();							\   else if (TREE_CODE (DECL) == STRING_CST)				\     {									\       if (! flag_writable_strings)					\ 	const_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (DECL) == VAR_DECL)				\     {									\       if (! DECL_READONLY_SECTION (DECL, RELOC)) 			\ 	data_section ();						\       else								\ 	const_section ();						\     }									\   else									\     const_section ();							\ }
end_define

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR)					\    || (CHAR) == 'h' 							\    || (CHAR) == 'R' 							\    || (CHAR) == 'Y' 							\    || (CHAR) == 'z')
end_define

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\&& strcmp (STR, "Tdata")&& strcmp (STR, "Ttext")			\&& strcmp (STR, "Tbss"))
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS)
end_define

begin_undef
undef|#
directive|undef
name|HANDLE_SYSV_PRAGMA
end_undef

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

begin_comment
comment|/* Though OpenServer support .weak in COFF, g++ doesn't play nice with it  * so we'll punt on it for now  */
end_comment

begin_define
define|#
directive|define
name|SUPPORTS_WEAK
value|(TARGET_ELF)
end_define

begin_define
define|#
directive|define
name|ASM_WEAKEN_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME);		\ 	fputc ('\n', FILE); } while (0)
end_define

begin_undef
undef|#
directive|undef
name|SCCS_DIRECTIVE
end_undef

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
value|1
end_define

begin_comment
comment|/*  * Define sizes and types  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|96
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/*  * New for multilib support. Set the default switches for multilib,  * which is -melf.  */
end_comment

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "melf" }
end_define

begin_escape
end_escape

begin_comment
comment|/* Please note that these specs may look messy but they are required in    order to emulate the SCO Development system as closely as possible.    With SCO Open Server 5.0, you now get the linker and assembler free,    so that is what these specs are targeted for. These utilities are    very argument sensitive: a space in the wrong place breaks everything.    So RMS, please forgive this mess. It works.     Parameters which can be passed to gcc, and their SCO equivalents:    GCC Parameter                SCO Equivalent    -ansi                        -a ansi    -posix                       -a posix    -Xpg4                        -a xpg4    -Xpg4plus                    -a xpg4plus    -Xods30                      -a ods30     As with SCO, the default is XPG4 plus mode. SCO also allows you to    specify a C dialect with -Xt, -Xa, -Xc, -Xk and -Xm. These are passed    on to the assembler and linker in the same way that the SCO compiler    does.     SCO also allows you to compile, link and generate either ELF or COFF    binaries. With gcc, unlike the SCO compiler, the default is ELF.    Specify -mcoff to gcc to produce COFF binaries. -fpic will get the    assembler and linker to produce PIC code. */
end_comment

begin_comment
comment|/* Set up assembler flags for PIC and ELF compilations */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_if
if|#
directive|if
name|USE_GAS
end_if

begin_comment
comment|/* Leave ASM_SPEC undefined so we pick up the master copy from gcc.c     * Undef MD_EXEC_PREFIX becuase we don't know where GAS is, but it's not    * likely in /usr/ccs/bin/     */
end_comment

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"-b %{!mcoff:elf}%{mcoff:coff \      %{static:%e-static not valid with -mcoff} \      %{shared:%e-shared not valid with -mcoff} \      %{symbolic:%e-symbolic not valid with -mcoff}} \     %{Ym,*} %{Yd,*} %{Wa,*:%*} \     %{!mcoff:-E%{Xa:a}%{!Xa:%{Xc:c}%{!Xc:%{Xk:k}%{!Xk:%{Xt:t}%{!Xt:a}}}},%{ansi:ansi}%{!ansi:%{posix:posix}%{!posix:%{Xpg4:xpg4}%{!Xpg4:%{Xpg4plus:XPG4PLUS}%{!Xpg4plus:%{Xods30:ods30}%{!Xods30:XPG4PLUS}}}}},ELF %{Qn:} %{!Qy:-Qn}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{shared: %{!mcoff: crti.o%s}} \   %{!shared:\    %{!symbolic: \     %{pg:gcrt.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}}} \   %{ansi:values-Xc.o%s} \   %{!ansi: \    %{traditional:values-Xt.o%s} \     %{!traditional: \      %{Xa:values-Xa.o%s} \       %{!Xa:%{Xc:values-Xc.o%s} \        %{!Xc:%{Xk:values-Xk.o%s} \         %{!Xk:%{Xt:values-Xt.o%s} \          %{!Xt:values-Xa.o%s}}}}}} \   %{mcoff:crtbeginS.o%s} %{!mcoff:crtbegin.o%s}"
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
define|\
value|"%{!mcoff:crtend.o%s} \   %{mcoff:crtendS.o%s} \   %{pg:gcrtn.o%s}%{!pg:crtn.o%s}"
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Asystem(svr3)"
end_define

begin_comment
comment|/* You are in a maze of GCC specs ... all alike */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) \   %{fpic:%{mcoff:%e-fpic is not valid with -mcoff}} \   %{fPIC:%{mcoff:%e-fPIC is not valid with -mcoff}} \   -D__i386 -D__unix -D_SCO_DS=1 -D_M_I386 -D_M_XENIX -D_M_UNIX \   %{!Xods30:-D_STRICT_NAMES} \   %{!ansi:%{!posix:%{!Xods30:-D_SCO_XPG_VERS=4}}} \   %{ansi:-isystem include/ansi%s -isystem /usr/include/ansi -D_STRICT_ANSI} \   %{!ansi: \    %{posix:-isystem include/posix%s -isystem /usr/include/posix \            -D_POSIX_C_SOURCE=2 -D_POSIX_SOURCE=1} \     %{!posix:%{Xpg4:-isystem include/xpg4%s -isystem /usr/include/xpg4 \                     -D_XOPEN_SOURCE=1} \      %{!Xpg4:-D_M_I86 -D_M_I86SM -D_M_INTERNAT -D_M_SDATA -D_M_STEXT \              -D_M_BITFIELDS -D_M_SYS5 -D_M_SYSV -D_M_SYSIII \              -D_M_WORDSWAP -Dunix -DM_I386 -DM_UNIX -DM_XENIX \              %{Xods30:-isystem include/ods_30_compat%s \                       -isystem /usr/include/ods_30_compat \                       -D_SCO_ODS_30 -DM_I86 -DM_I86SM -DM_SDATA -DM_STEXT \                       -DM_BITFIELDS -DM_SYS5 -DM_SYSV -DM_INTERNAT -DM_SYSIII \                       -DM_WORDSWAP}}}} \   %{scointl:-DM_INTERNAT -D_M_INTERNAT} \   %{traditional:-D_KR -D_SVID -D_NO_PROTOTYPE} \   %{!mcoff:-D_SCO_ELF} \   %{mcoff:-D_M_COFF -D_SCO_COFF} \   %{!mcoff:%{fpic:-D__PIC__ -D__pic__} \          %{fPIC:%{!fpic:-D__PIC__ -D__pic__}}} \   %{Xa:-D_SCO_C_DIALECT=1} \   %{!Xa:%{Xc:-D_SCO_C_DIALECT=3} \    %{!Xc:%{Xk:-D_SCO_C_DIALECT=4} \     %{!Xk:%{Xt:-D_SCO_C_DIALECT=2} \      %{!Xt:-D_SCO_C_DIALECT=1}}}} \   %{traditional:-traditional -D_KR -D_NO_PROTOTYPE}"
end_define

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
value|"-b %{!mcoff:elf}%{mcoff:coff \    %{static:%e-static not valid with -mcoff} \    %{shared:%e-shared not valid with -mcoff} \    %{symbolic:%e-symbolic not valid with -mcoff} \    %{fpic:%e-fpic not valid with -mcoff} \    %{fPIC:%e-fPIC not valid with -mcoff}} \   -R%{Xa:a}%{!Xa:%{Xc:c}%{!Xc:%{Xk:k}%{!Xk:%{Xt:t}%{!Xt:a}}}},%{ansi:ansi}%{!ansi:%{posix:posix}%{!posix:%{Xpg4:xpg4}%{!Xpg4:%{Xpg4plus:XPG4PLUS}%{!Xpg4plus:%{Xods30:ods30}%{!Xods30:XPG4PLUS}}}}},%{mcoff:COFF}%{!mcoff:ELF} \   %{Wl,*%*} %{YP,*} %{YL,*} %{YU,*} \   %{!YP,*:%{p:-YP,/usr/ccs/libp:/lib/libp:/usr/lib/libp:/usr/ccs/lib:/lib:/usr/lib} \    %{!p:-YP,/usr/ccs/lib:/lib:/usr/lib}} \   %{h*} %{static:-dn -Bstatic} %{shared:-G -dy %{!z*:-z text}} \   %{symbolic:-Bsymbolic -G -dy %{!z*:-z text}} %{z*} %{R*} %{Y*} \   %{G:-G} %{!mcoff:%{Qn:} %{!Qy:-Qn}}"
end_define

begin_comment
comment|/* The SCO COFF linker gets confused on the difference between "-ofoo"    and "-o foo".   So we just always force a single space. */
end_comment

begin_define
define|#
directive|define
name|SWITCHES_NEED_SPACES
value|"o"
end_define

begin_comment
comment|/* Library spec. If we are not building a shared library, provide the    standard libraries, as per the SCO compiler.  */
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
define|\
value|"%{shared:pic/libgcc.a%s}%{!shared:%{!symbolic:-lcrypt -lgen -lc}}"
end_define

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
define|\
value|"%{!shared:-lgcc}"
end_define

begin_define
define|#
directive|define
name|MASK_COFF
value|010000000000
end_define

begin_comment
comment|/* Mask for elf generation */
end_comment

begin_define
define|#
directive|define
name|TARGET_COFF
value|(target_flags& MASK_COFF)
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|(!(target_flags& MASK_COFF))
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{ "coff", MASK_COFF, "Generate COFF output" }, 		\ 	{ "elf", -MASK_COFF, "Generate ELF output"  },
end_define

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  They are     faster on OpenServer libraries. */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Biggest alignment supported by the object file format of this    machine.  Use this macro to limit the alignment which can be    specified using the `__attribute__ ((aligned (N)))' construct.  If    not defined, the default value is `BIGGEST_ALIGNMENT'.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|(32768*8)
end_define

begin_comment
comment|/* Here comes some major hackery to get the crt stuff to compile properly. Since we can (and do) compile for both COFF and ELF environments, we set things up accordingly, based on the pre-processor defines for ELF and COFF. This is insane, but then I guess having one compiler with a single back-end supporting two vastly different file format types is a little insane too. But it is not impossible and we get a useful compiler at the end of the day. Onward we go ... */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRT_BEGIN
argument_list|)
operator|||
name|defined
argument_list|(
name|CRT_END
argument_list|)
operator|||
name|defined
argument_list|(
name|IN_LIBGCC2
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_ELF
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_ATEXIT
end_undef

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|EH_FRAME_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|CTOR_LIST_BEGIN
end_undef

begin_undef
undef|#
directive|undef
name|CTOR_LIST_END
end_undef

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_CTORS_BODY
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SCO_ELF
argument_list|)
end_if

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ELF
end_define

begin_define
define|#
directive|define
name|HAVE_ATEXIT
value|1
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|INIT_SECTION_ASM_OP_ELF
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|FINI_SECTION_ASM_OP_ELF
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|DTORS_SECTION_ASM_OP_ELF
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|CTORS_SECTION_ASM_OP_ELF
end_define

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_ASM_OP
value|EH_FRAME_SECTION_ASM_OP_ELF
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _SCO_ELF */
end_comment

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|INIT_SECTION_ASM_OP_COFF
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|FINI_SECTION_ASM_OP_COFF
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|DTORS_SECTION_ASM_OP_COFF
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|CTORS_SECTION_ASM_OP_COFF
end_define

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_ASM_OP
value|""
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
value|asm (INIT_SECTION_ASM_OP); asm ("pushl $0")
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_END
value|CTOR_LIST_BEGIN
end_define

begin_define
define|#
directive|define
name|DO_GLOBAL_CTORS_BODY
define|\
value|do {									\      func_ptr *p, *beg = alloca(0);					\      for (p = beg; *p;)							\       (*p++) ();							\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SCO_ELF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRT_BEGIN !! CRT_END */
end_comment

end_unit

