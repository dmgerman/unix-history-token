begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for ARM with a.out    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2004    Free Software Foundation, Inc.    Contributed by Richard Earnshaw (rearnsha@armltd.co.uk).        This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

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
comment|/* Note: If USER_LABEL_PREFIX or LOCAL_LABEL_PREFIX are changed,    make sure that this change is reflected in the function    coff_arm_is_local_label_name() in bfd/coff-arm.c.  */
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
value|{				                   \   "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",  \   "r8", "r9", "sl", "fp", "ip", "sp", "lr", "pc",  \   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",  \   "cc", "sfp", "afp",		   		   \   "mv0",   "mv1",   "mv2",   "mv3",		   \   "mv4",   "mv5",   "mv6",   "mv7",		   \   "mv8",   "mv9",   "mv10",  "mv11",		   \   "mv12",  "mv13",  "mv14",  "mv15",		   \   "wcgr0", "wcgr1", "wcgr2", "wcgr3",		   \   "wr0",   "wr1",   "wr2",   "wr3",		   \   "wr4",   "wr5",   "wr6",   "wr7",		   \   "wr8",   "wr9",   "wr10",  "wr11",		   \   "wr12",  "wr13",  "wr14",  "wr15",		   \   "s0",  "s1",  "s2",  "s3",  "s4",  "s5",  "s6",  "s7",  \   "s8",  "s9",  "s10", "s11", "s12", "s13", "s14", "s15", \   "s16", "s17", "s18", "s19", "s20", "s21", "s22", "s23", \   "s24", "s25", "s26", "s27", "s28", "s29", "s30", "s31", \   "vfpcc"					   \ }
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
value|\   {"r15", 15},
comment|/* pc */
value|\   {"mvf0", 27},					\   {"mvf1", 28},					\   {"mvf2", 29},					\   {"mvf3", 30},					\   {"mvf4", 31},					\   {"mvf5", 32},					\   {"mvf6", 33},					\   {"mvf7", 34},					\   {"mvf8", 35},					\   {"mvf9", 36},					\   {"mvf10", 37},				\   {"mvf11", 38},				\   {"mvf12", 39},				\   {"mvf13", 40},				\   {"mvf14", 41},				\   {"mvf15", 42},				\   {"mvd0", 27},					\   {"mvd1", 28},					\   {"mvd2", 29},					\   {"mvd3", 30},					\   {"mvd4", 31},					\   {"mvd5", 32},					\   {"mvd6", 33},					\   {"mvd7", 34},					\   {"mvd8", 35},					\   {"mvd9", 36},					\   {"mvd10", 37},				\   {"mvd11", 38},				\   {"mvd12", 39},				\   {"mvd13", 40},				\   {"mvd14", 41},				\   {"mvd15", 42},				\   {"mvfx0", 27},				\   {"mvfx1", 28},				\   {"mvfx2", 29},				\   {"mvfx3", 30},				\   {"mvfx4", 31},				\   {"mvfx5", 32},				\   {"mvfx6", 33},				\   {"mvfx7", 34},				\   {"mvfx8", 35},				\   {"mvfx9", 36},				\   {"mvfx10", 37},				\   {"mvfx11", 38},				\   {"mvfx12", 39},				\   {"mvfx13", 40},				\   {"mvfx14", 41},				\   {"mvfx15", 42},				\   {"mvdx0", 27},				\   {"mvdx1", 28},				\   {"mvdx2", 29},				\   {"mvdx3", 30},				\   {"mvdx4", 31},				\   {"mvdx5", 32},				\   {"mvdx6", 33},				\   {"mvdx7", 34},				\   {"mvdx8", 35},				\   {"mvdx9", 36},				\   {"mvdx10", 37},				\   {"mvdx11", 38},				\   {"mvdx12", 39},				\   {"mvdx13", 40},				\   {"mvdx14", 41},				\   {"mvdx15", 42},				\   {"d0", 63},					\   {"d1", 65},					\   {"d2", 67},					\   {"d3", 69},					\   {"d4", 71},					\   {"d5", 73},					\   {"d6", 75},					\   {"d7", 77},					\   {"d8", 79},					\   {"d9", 81},					\   {"d10", 83},					\   {"d11", 85},					\   {"d12", 87},					\   {"d13", 89},					\   {"d14", 91},					\   {"d15", 93},					\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Arm Assembler barfs on dollars.  */
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
comment|/* Generate DBX debugging information.  riscix.h will undefine this because    the native assembler does not support stabs.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

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

begin_comment
comment|/* Globalizing directive for a label.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"\t.global\t"
end_define

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
value|do									\     {									\       if (TARGET_ARM)							\ 	asm_fprintf (STREAM, "\tb\t%LL%d\n", VALUE);			\       else								\ 	asm_fprintf (STREAM, "\t.word\t%LL%d-%LL%d\n", VALUE, REL);	\     }									\   while (0)
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
value|output_ascii_pseudo_op (STREAM, (const unsigned char *) (PTR), LEN)
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
value|fprintf (STREAM, "\t.space\t%d\n", (int) (NBYTES))
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
comment|/* Output a common block.  */
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
value|do							\     {							\       fprintf (STREAM, "\t.comm\t");			\       assemble_name (STREAM, NAME);			\       asm_fprintf (STREAM, ", %d\t%@ %d\n", 		\ 	           (int)(ROUNDED), (int)(SIZE));	\     }							\   while (0)
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
value|do									\     {									\       switch_to_section (bss_section);					\       ASM_OUTPUT_ALIGN (STREAM, floor_log2 (ALIGN / BITS_PER_UNIT));	\       ASM_OUTPUT_LABEL (STREAM, NAME);					\       fprintf (STREAM, "\t.space\t%d\n", (int)(SIZE));			\     }									\   while (0)
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

