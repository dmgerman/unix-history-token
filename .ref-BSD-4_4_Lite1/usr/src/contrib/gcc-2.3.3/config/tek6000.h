begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Generic Tektronix 6000 series NS32000 version.    See tek6100.h and tek6200.h, which include this file.    Copyright (C) 1990 Free Software Foundation, Inc.    Created by Snoopy  (sopwith.uucp!snoopy).    Based on work by Mark Mason (mason@reed.bitnet,    pyramid!unify!mason@uunet.uu.net) and Keith Packard.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Generate syntax for the UTek assembler. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTEK_ASM
end_ifndef

begin_define
define|#
directive|define
name|UTEK_ASM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Two flags to control how addresses are printed in assembler insns.  */
end_comment

begin_comment
comment|/* The way PUT_ABSOLUTE_PREFIX in ns32k.h works, setting it to 0 will  * turn it off.  Define ABSOLUTE_PREFIX before including ns32k.h.  */
end_comment

begin_define
define|#
directive|define
name|ABSOLUTE_PREFIX
value|0
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

begin_comment
comment|/* Define these after ns32k.c so we will notice if gcc tries to  * output external mode addressing.  UTek's as and ld do not support  * external mode addressing, according to Daryl McDaniel (illian.uucp!darylm).  * Hopefully the UTek assembler will complain if gcc feeds it this stuff.  * They don't seem to do anything, I think that gcc is not actually  * trying to generate external mode operands.  */
end_comment

begin_undef
undef|#
directive|undef
name|PUT_EXTERNAL_PREFIX
end_undef

begin_define
define|#
directive|define
name|PUT_EXTERNAL_PREFIX
parameter_list|(
name|arg
parameter_list|)
value|fprintf(arg, "  Should not be using external mode under UTek.  ")
end_define

begin_define
define|#
directive|define
name|EXTERNAL_PREFIX
value|'%'
end_define

begin_comment
comment|/* Used in ns32k.c to control syntax. */
end_comment

begin_define
define|#
directive|define
name|NO_ABSOLUTE_PREFIX_IF_SYMBOLIC
end_define

begin_define
define|#
directive|define
name|NO_IMMEDIATE_PREFIX_IF_SYMBOLIC
end_define

begin_comment
comment|/* Used in ns32k.md to specify syntax of bsr/jsr operand. */
end_comment

begin_define
define|#
directive|define
name|CALL_MEMREF_IMPLICIT
end_define

begin_comment
comment|/* #define PC_RELATIVE */
end_comment

begin_comment
comment|/* Seems to break things. */
end_comment

begin_define
define|#
directive|define
name|BASE_REG_NEEDED
end_define

begin_comment
comment|/* Seems to fix problem where external mode 				 * syntax was being generated. 				 */
end_comment

begin_comment
comment|/*  ------------   Debugging Support   ----------------------------- */
end_comment

begin_comment
comment|/* The sdb support does not yet work with UTek.  Need to teach gcc  * how to create sdb type stabs as well as dbx style stabs.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* #define SDB_DEBUGGING_INFO */
end_comment

begin_comment
comment|/* Act the same as the UTek complier: -g for dbx, -go for sdb.  * This is used in toplev.c.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
define|\
value|((len> 1&& !strncmp(str, "go", len)) ? SDB_DEBUG : DBX_DEBUG )
end_define

begin_comment
comment|/* Sequent has some changes in the format of DBX symbols.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
value|1
end_define

begin_comment
comment|/* Don't split DBX symbols into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* ------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_comment
comment|/* These control the C++ compiler somehow.  */
end_comment

begin_define
define|#
directive|define
name|FASCIST_ASSEMBLER
end_define

begin_define
define|#
directive|define
name|USE_COLLECT
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
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
value|fprintf (stderr, " (ns32k, UTek syntax)");
end_define

begin_comment
comment|/* The tek6100.h and tek6200.h files add stratos or merlin respectively. */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES_Tek6000
define|\
value|"-Dns16000 -Dns32000 -Dns32k -Dns32016 -DUTek -DUTEK -Dbsd -DBSD"
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
value|"CPP_PREDEFINES_Tek6000"
end_define

begin_comment
comment|/* This is how to align the code that follows an unconditional branch.    Don't define it, since it confuses the assembler (we hear).  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN_CODE
end_undef

begin_comment
comment|/* Assembler pseudo-op for shared data segment. */
end_comment

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|".shdata"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UTEK_ASM
end_ifdef

begin_undef
undef|#
directive|undef
name|FUNCTION_PROLOGUE
end_undef

begin_comment
comment|/* This differs from the one in ns32k.h in printing a bitmask    rather than a register list in the enter or save instruction.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROLOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{ register int regno, g_regs_used = 0;				\   int used_regs_buf[8], *bufp = used_regs_buf;			\   int used_fregs_buf[8], *fbufp = used_fregs_buf;		\   extern char call_used_regs[];					\   MAIN_FUNCTION_PROLOGUE;					\   for (regno = 0; regno< 8; regno++)				\     if (regs_ever_live[regno]					\&& ! call_used_regs[regno])				\     {								\       *bufp++ = regno; g_regs_used++;				\     }								\   *bufp = -1;							\   for (; regno< 16; regno++)					\     if (regs_ever_live[regno]&& !call_used_regs[regno]) {	\       *fbufp++ = regno;						\     }								\   *fbufp = -1;							\   bufp = used_regs_buf;						\   if (frame_pointer_needed)					\     fprintf (FILE, "\tenter ");					\   else if (g_regs_used)						\     fprintf (FILE, "\tsave ");					\   if (frame_pointer_needed || g_regs_used)			\     {								\       char mask = 0;						\       while (*bufp>= 0)					\ 	mask |= 1<< *bufp++;					\       fprintf (FILE, "$0x%x", (int) mask& 0xff);		\     }								\   if (frame_pointer_needed)					\     fprintf (FILE, ",$%d\n", SIZE);				\   else if (g_regs_used)						\     fprintf (FILE, "\n");					\   fbufp = used_fregs_buf;					\   while (*fbufp>= 0)						\     {								\       if ((*fbufp& 1) || (fbufp[0] != fbufp[1] - 1))		\ 	fprintf (FILE, "\tmovf f%d,tos\n", *fbufp++ - 8);	\       else							\ 	{							\ 	  fprintf (FILE, "\tmovl f%d,tos\n", fbufp[0] - 8);	\ 	  fbufp += 2;						\ 	}							\     }								\ }
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_EPILOGUE
end_undef

begin_comment
comment|/* This differs from the one in ns32k.h in printing a bitmask    rather than a register list in the exit or restore instruction.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{ register int regno, g_regs_used = 0, f_regs_used = 0;		\   int used_regs_buf[8], *bufp = used_regs_buf;			\   int used_fregs_buf[8], *fbufp = used_fregs_buf;		\   extern char call_used_regs[];					\   *fbufp++ = -2;						\   for (regno = 8; regno< 16; regno++)				\     if (regs_ever_live[regno]&& !call_used_regs[regno]) {	\        *fbufp++ = regno; f_regs_used++;				\     }								\   fbufp--;							\   for (regno = 0; regno< 8; regno++)				\     if (regs_ever_live[regno]					\&& ! call_used_regs[regno])				\     {                                                         	\       *bufp++ = regno; g_regs_used++;				\     }                                                         	\   while (fbufp> used_fregs_buf)				\     {								\       if ((*fbufp& 1)&& fbufp[0] == fbufp[-1] + 1)		\ 	{							\ 	  fprintf (FILE, "\tmovl tos,f%d\n", fbufp[-1] - 8);	\ 	  fbufp -= 2;						\ 	}							\       else fprintf (FILE, "\tmovf tos,f%d\n", *fbufp-- - 8);	\     }								\   if (frame_pointer_needed)					\     fprintf (FILE, "\texit ");					\   else if (g_regs_used)						\     fprintf (FILE, "\trestore ");				\   if (g_regs_used || frame_pointer_needed)			\     {								\       char mask = 0;						\ 								\       while (bufp> used_regs_buf)				\ 	{							\
comment|/* Utek assembler takes care of reversing this */
value|\ 	  mask |= 1<< *--bufp;					\ 	}							\       fprintf (FILE, "$0x%x\n", (int) mask& 0xff);		\     }								\   if (current_function_pops_args)				\     fprintf (FILE, "\tret $%d\n", current_function_pops_args);	\   else fprintf (FILE, "\tret $0\n"); }
end_define

begin_comment
comment|/* UTek assembler needs "ret $0", not "ret 0". */
end_comment

begin_undef
undef|#
directive|undef
name|TRANSFER_FROM_TRAMPOLINE
end_undef

begin_define
define|#
directive|define
name|TRANSFER_FROM_TRAMPOLINE
define|\
value|void					\ __transfer_from_trampoline ()		\ {					\   asm ("___trampoline:");		\   asm ("movd 16(r2),tos");		\   asm ("movd 12(r2),r2");		\   asm ("ret $0");			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTEK_ASM */
end_comment

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND_ADDRESS
end_undef

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

begin_comment
comment|/* The UTek library supplies bcopy() and friends, not memcpy(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_MEM_FUNCTIONS
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_MEM_FUNCTIONS
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

