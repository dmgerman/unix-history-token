begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for some    embedded system running pSOS. We assume GNU tools with ELF, but    try to maintain compatibility with the MRI tools. Based on svr4.h.    Copyright (C) 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     To use this file, make up a file with a name like:  	?????-psos.h     where ????? is replaced by the name of the basic hardware that you    are targeting for.  Then, in the file ?????-psos.h, put something    like:  	#include "?????.h" 	#include "psos.h"     followed by any really system-specific defines (or overrides of    defines) which you find that you need. */
end_comment

begin_comment
comment|/* Define a symbol indicating that we are using psos.h.  */
end_comment

begin_define
define|#
directive|define
name|USING_PSOS_H
end_define

begin_comment
comment|/* All pSOS targets currently use the ELF object file format.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ELF
end_define

begin_comment
comment|/* Provide a NULL STARTFILE_SPEC. The startfile cannot be specified    here because it depends on the architecture (e.g. 68K), the    board-support package (e.g. M162) and the run-time configuration    (e.g. application vs. ram-image vs. rom-image). Specify the    startfile in a linker-script created from the generic    architecture-specific linker-scripts. */
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
value|""
end_define

begin_comment
comment|/* Predefined macros (independent of processor type). */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dpsos"
end_define

begin_comment
comment|/* Implicit library calls should use ANSI memcpy rather than BSD    bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* When using stabs, gcc2_compiled must be a stabs entry, not an    ordinary symbol, or gdb won't see it.  The stabs entry must be    before the N_SO in order for gdb to find it.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do									\   {									\     fputs (".stabs \"gcc2_compiled.\", 0x3c, 0, 0, 0\n", FILE);	\   }									\ while (0)
end_define

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.  */
end_comment

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
value|do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while (0)
end_define

begin_comment
comment|/* Switch into a generic section. */
end_comment

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
value|fprintf (FILE, ".section\t%s,\"%s\",@progbits\n", NAME, \ 	   (DECL)&& TREE_CODE (DECL) == FUNCTION_DECL ? "ax" : \ 	   (DECL)&& DECL_READONLY_SECTION (DECL, RELOC) ? "a" : "aw")
end_define

begin_comment
comment|/* Define the pseudo-ops used to switch to the .ctors and .dtors    sections. */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors,\"aw\""
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t.dtors,\"aw\""
end_define

begin_comment
comment|/* A default list of other sections which we might be "in" at any given    time.  For targets that use additional sections (e.g. .tdesc) you    should override this definition in the target-specific file which    includes this file.  */
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
comment|/* A default list of extra section function definitions.  For targets    that use additional sections (e.g. .tdesc) you should override this    definition in the target-specific file which includes this file.  */
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

begin_function_decl
specifier|extern
name|void
name|text_section
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global constructors.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_ASM_OP
end_ifndef

begin_define
define|#
directive|define
name|INT_ASM_OP
value|".long"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Use DBX debugging info by default.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREFERRED_DEBUGGING_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For pSOS we use DBX debugging info.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Prevent generation of an exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

end_unit

