begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for ARM with a.out    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.    Contributed by Richard Earnshaw (rearnsha@armltd.co.uk).     This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_OS_NAME
end_ifndef

begin_define
define|#
directive|define
name|ARM_OS_NAME
value|"(generic)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The text to go at the start of the assembler file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FILE_START
end_ifndef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|{					    \   asm_fprintf (STREAM,"%Rrfp\t.req\t%Rr9\n"); \   asm_fprintf (STREAM,"%Rsl\t.req\t%Rr10\n"); \   asm_fprintf (STREAM,"%Rfp\t.req\t%Rr11\n"); \   asm_fprintf (STREAM,"%Rip\t.req\t%Rr12\n"); \   asm_fprintf (STREAM,"%Rsp\t.req\t%Rr13\n"); \   asm_fprintf (STREAM,"%Rlr\t.req\t%Rr14\n"); \   asm_fprintf (STREAM,"%Rpc\t.req\t%Rr15\n"); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_APP_ON
end_ifndef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_APP_OFF
end_ifndef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Switch to the text or data segment.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.bss"
end_define

begin_comment
comment|/* Note: If USER_LABEL_PREFIX or LOCAL_LABEL_PREFIX are changed,    make sure that this change is reflected in the function    coff_arm_is_local_label_name() in bfd/coff-arm.c  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGISTER_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USER_LABEL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABEL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The assembler's names for the registers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGISTER_NAMES
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{				                   \   "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",  \   "r8", "r9", "sl", "fp", "ip", "sp", "lr", "pc",  \   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",  \   "cc", "sfp", "afp"		   		   \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ADDITIONAL_REGISTER_NAMES
end_ifndef

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{						\   {"a1", 0},					\   {"a2", 1},					\   {"a3", 2},					\   {"a4", 3},					\   {"v1", 4},					\   {"v2", 5},					\   {"v3", 6},					\   {"v4", 7},					\   {"v5", 8},					\   {"v6", 9},					\   {"rfp", 9},
comment|/* Gcc used to call it this */
value|\   {"sb", 9},					\   {"v7", 10},					\   {"r10", 10},
comment|/* sl */
value|\   {"r11", 11},
comment|/* fp */
value|\   {"r12", 12},
comment|/* ip */
value|\   {"r13", 13},
comment|/* sp */
value|\   {"r14", 14},
comment|/* lr */
value|\   {"r15", 15}
comment|/* pc */
value|\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Arm Assembler barfs on dollars */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DOLLAR_IN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Generate DBX debugging information.  riscix.h will undefine this because    the native assembler does not support stabs. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBX_DEBUGGING_INFO
end_ifndef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Acorn dbx moans about continuation chars, so don't use any.  */
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
comment|/* Output a source filename for the debugger. RISCiX dbx insists that the    ``desc'' field is set to compiler version number>= 315 (sic).  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILENAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do									\     {									\       fprintf (STREAM, ".stabs ");					\       output_quoted_string (STREAM, NAME);				\       fprintf (STREAM, ",%d,0,315,%s\n", N_SO,&ltext_label_name[1]);	\       text_section ();							\       ASM_OUTPUT_INTERNAL_LABEL (STREAM, "Ltext", 0);			\     }									\   while (0)
end_define

begin_comment
comment|/* Output a function label definition.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_FUNCTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do							\     {							\       ARM_DECLARE_FUNCTION_NAME (STREAM, NAME, DECL);   \       ASM_OUTPUT_LABEL (STREAM, NAME);			\     }							\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do						\     {						\       assemble_name (STREAM,NAME);		\       fputs (":\n", STREAM);			\     }						\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a globalising directive for a label.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_GLOBALIZE_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do						\     {						\       fprintf (STREAM, "\t.global\t");		\       assemble_name (STREAM, NAME);		\       fputc ('\n',STREAM);			\     }						\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make an internal label into a string.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_GENERATE_INTERNAL_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|STRING
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (STRING, "*%s%s%u", LOCAL_LABEL_PREFIX, PREFIX, (unsigned int)(NUM))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Construct a private name.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTVAR
parameter_list|,
name|NAME
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|((OUTVAR) = (char *) alloca (strlen (NAME) + 10),  \    sprintf (OUTVAR, "%s.%d", NAME, NUMBER))
end_define

begin_comment
comment|/* Output an element of a dispatch table.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|asm_fprintf (STREAM, "\t.word\t%LL%d\n", VALUE)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|asm_fprintf (STREAM, "\tb\t%LL%d\n", VALUE)
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
name|STREAM
parameter_list|,
name|PTR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|output_ascii_pseudo_op (STREAM, (const unsigned char *)(PTR), LEN)
end_define

begin_comment
comment|/* Output a gap.  In fact we fill it with nulls.  */
end_comment

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
name|STREAM
parameter_list|,
name|NBYTES
parameter_list|)
define|\
value|fprintf (STREAM, "\t.space\t%d\n", NBYTES)
end_define

begin_comment
comment|/* Align output to a power of two.  Horrible /bin/as.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|POWER
parameter_list|)
define|\
value|do							\     {							\       register int amount = 1<< (POWER);		\ 							\       if (amount == 2)					\ 	fprintf (STREAM, "\t.even\n");			\       else if (amount != 1)				\ 	fprintf (STREAM, "\t.align\t%d\n", amount - 4);	\     }							\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a common block */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_COMMON
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do							\     {							\       fprintf (STREAM, "\t.comm\t");			\       assemble_name (STREAM, NAME);			\       asm_fprintf (STREAM, ", %d\t%@ %d\n", 		\ 	           ROUNDED, SIZE);			\     }							\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a local common block.  /bin/as can't do this, so hack a    `.space' into the bss segment.  Note that this is *bad* practice,    which is guaranteed NOT to work since it doesn't define STATIC    COMMON space but merely STATIC BSS space.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do									\     {									\       bss_section ();							\       ASM_OUTPUT_ALIGN (STREAM, floor_log2 (ALIGN / BITS_PER_UNIT));	\       ASM_OUTPUT_LABEL (STREAM, NAME);					\       fprintf (STREAM, "\t.space\t%d\n", SIZE);				\     }									\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a zero-initialized block.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ALIGNED_BSS
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|STREAM
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
value|asm_output_aligned_bss (STREAM, DECL, NAME, SIZE, ALIGN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a source line for the debugger.  */
end_comment

begin_comment
comment|/* #define ASM_OUTPUT_SOURCE_LINE(STREAM,LINE) */
end_comment

begin_comment
comment|/* Output a #ident directive.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_IDENT
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|STREAM
parameter_list|,
name|STRING
parameter_list|)
define|\
value|asm_fprintf (STREAM, "%@ - - - ident %s\n", STRING)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_COMMENT_START
end_ifndef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"@"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This works for GAS and some other assemblers.  */
end_comment

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

end_unit

