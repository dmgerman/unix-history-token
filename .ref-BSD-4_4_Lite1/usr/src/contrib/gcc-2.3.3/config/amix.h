begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Commodore Amiga A3000UX version.     Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m68kv4.h"
end_include

begin_comment
comment|/* Alter assembler syntax for fsgldiv and fsglmul.    It is highly likely that this is a generic SGS m68k assembler dependency.    If so, it should eventually be handled in the m68ksgs.h ASM_OUTPUT_OPCODE    macro, like the other SGS assembler quirks.  -fnf */
end_comment

begin_define
define|#
directive|define
name|FSGLDIV_USE_S
end_define

begin_comment
comment|/* Use fsgldiv.s, not fsgldiv.x */
end_comment

begin_define
define|#
directive|define
name|FSGLMUL_USE_S
end_define

begin_comment
comment|/* Use fsglmul.s, not fsglmul.x */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  For the    Amiga, these definitions match those of the native AT&T compiler.  Note    that we override the definition in m68kv4.h, where SVR4 is defined and    AMIX isn't. */
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
define|\
value|"-Dm68k -Dunix -DAMIX -Amachine(m68k) -Acpu(m68k) -Asystem(unix) -Alint(off)"
end_define

begin_comment
comment|/* At end of a switch table, define LDnnn iff the symbol LInnn was defined.    Some SGS assemblers have a bug such that "Lnnn-LInnn-2.b(pc,d0.l*2)"    fails to assemble.  Luckily "Lnnn(pc,d0.l*2)" produces the results    we want.  This difference can be accommodated by making the assembler    define such "LDnnn" to be either "Lnnn-LInnn-2.b", "Lnnn", or any other    string, as necessary.  This is accomplished via the ASM_OUTPUT_CASE_END    macro. (the Amiga assembler has this bug) */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_END
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_END
parameter_list|(
name|FILE
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|do {									\   if (switch_table_difference_label_flag)				\     asm_fprintf ((FILE), "\t%s %LLD%d,%LL%d\n", SET_ASM_OP, (NUM), (NUM));\   switch_table_difference_label_flag = 0;				\ } while (0)
end_define

begin_decl_stmt
name|int
name|switch_table_difference_label_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized external linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.    [This macro overrides the one in svr4.h because the amix assembler     has a minimum default alignment of 4, and will not accept any     explicit alignment smaller than this.  -fnf] */
end_comment

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
value|do {									\   fputs ("\t.comm\t", (FILE));						\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), ",%u,%u\n", (SIZE), MAX ((ALIGN) / BITS_PER_UNIT, 4)); \ } while (0)
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized internal linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.    [This macro overrides the one in svr4.h because the amix assembler     has a minimum default alignment of 4, and will not accept any     explicit alignment smaller than this.  -fnf] */
end_comment

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
value|do {									\   fprintf ((FILE), "\t%s\t%s,%u,%u\n",					\ 	   BSS_ASM_OP, (NAME), (SIZE), MAX ((ALIGN) / BITS_PER_UNIT, 4)); \ } while (0)
end_define

begin_comment
comment|/* This definition of ASM_OUTPUT_ASCII is the same as the one in m68ksgs.h,    which has been overridden by the one in svr4.h.  However, we can't use    the one in svr4.h because the amix assembler croaks on some of the    strings that it emits (such as .string "\"%s\"\n"). */
end_comment

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
name|PTR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|{								\   register int sp = 0, lp = 0, ch;				\   fprintf ((FILE), "\t%s ", BYTE_ASM_OP);				\   do {								\     ch = (PTR)[sp];						\     if (ch> ' '&& ! (ch& 0x80)&& ch != '\\')		\       {								\ 	fprintf ((FILE), "'%c", ch);				\       }								\     else							\       {								\ 	fprintf ((FILE), "0x%x", ch);				\       }								\     if (++sp< (LEN))						\       {								\ 	if ((sp % 10) == 0)					\ 	  {							\ 	    fprintf ((FILE), "\n\t%s ", BYTE_ASM_OP);		\ 	  }							\ 	else							\ 	  {							\ 	    putc (',', (FILE));					\ 	  }							\       }								\   } while (sp< (LEN));						\   putc ('\n', (FILE));						\ }
end_define

end_unit

