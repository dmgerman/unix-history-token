begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.      SysV68 Motorola 3300 Delta Series     Written by Abramo and Roberto Bagnara    after Alex Crain's 3B1 definitions.     Bug reports to bagnara@dipisa.di.unipi.it     Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|MOTOROLA
end_define

begin_comment
comment|/* Use Motorola syntax rather than "MIT" */
end_comment

begin_define
define|#
directive|define
name|SGS
end_define

begin_comment
comment|/* Uses SGS assembler */
end_comment

begin_define
define|#
directive|define
name|SGS_CMP_ORDER
end_define

begin_comment
comment|/* Takes cmp operands in reverse order */
end_comment

begin_define
define|#
directive|define
name|SGS_SWAP_W
end_define

begin_comment
comment|/* Use swap.w rather than just plain swap */
end_comment

begin_define
define|#
directive|define
name|SGS_SWITCH_TABLES
end_define

begin_comment
comment|/* Different switch table handling */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* See m68k.h.  7 means 68020 with 68881.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NYI: FP= is equivalent to -msoft-float  */
end_comment

begin_comment
comment|/* We use /lib/libp/lib* when profiling.  */
end_comment

begin_comment
comment|/* NYI: if FP=M68881U library is -lc881u  */
end_comment

begin_comment
comment|/* NYI: if FP= library is -lc.  */
end_comment

begin_comment
comment|/* Default for us: FP=M68881 library is -lc881  */
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
value|"%{!shlib:%{p:-L/usr/lib/libp} %{pg:-L/usr/lib/libp} -lc881}"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!msoft-float:-D__HAVE_68881__}"
end_define

begin_comment
comment|/* Shared libraries need to use crt0s.o  */
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
value|"%{!shlib:%{pg:mcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}\    %{shlib:crt0s.o%s shlib.ifile%s} "
end_define

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* size_t is unsigned int.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_comment
comment|/* Every structure or union's size must be a multiple of 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* cpp has to support a #sccs directive for the /usr/include files */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Make output for SDB.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%d0", "%d1", "%d2", "%d3", "%d4", "%d5", "%d6", "%d7",	\  "%a0", "%a1", "%a2", "%a3", "%a4", "%a5", "%fp", "%sp",	\  "%fp0", "%fp1", "%fp2", "%fp3", "%fp4", "%fp5", "%fp6", "%fp7"}
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_PROLOGUE
end_undef

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
value|{ register int regno;						\   register int mask = 0;					\   extern char call_used_regs[];					\   int fsize = (SIZE);						\   if (frame_pointer_needed)					\     { if (fsize< 0x8000)					\         fprintf (FILE, "\tlink.w %%fp,&%d\n", -fsize);		\       else if (TARGET_68020)					\         fprintf (FILE, "\tlink.l %%fp,&%d\n", -fsize);		\       else							\ 	fprintf (FILE, "\tlink.w %%fp,&0\n\tsub.l&%d,%%sp\n", fsize); }  \   for (regno = 16; regno< FIRST_PSEUDO_REGISTER; regno++)	\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\        mask |= 1<< (regno - 16);				\   if (mask != 0)						\     fprintf (FILE, "\tfmovem&0x%x,-(%%sp)\n", mask& 0xff);	\   mask = 0;							\   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\        mask |= 1<< (15 - regno);				\   if (frame_pointer_needed)					\     mask&= ~ (1<< (15-FRAME_POINTER_REGNUM));			\   if (exact_log2 (mask)>= 0)					\     fprintf (FILE, "\tmov.l %s,-(%%sp)\n", reg_names[15 - exact_log2 (mask)]);  \   else if (mask) fprintf (FILE, "\tmovm.l&0x%x,-(%%sp)\n", mask); }
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABEL_NO
parameter_list|)
define|\
value|fprintf (FILE, "\tmov.l&LP%%%d,%%a0\n\tjsr mcount%%\n", (LABEL_NO))
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_EPILOGUE
end_undef

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
value|{ register int regno;						\   register int mask, fmask;					\   register int nregs;						\   int offset, foffset;						\   extern char call_used_regs[];					\   int fsize = (SIZE);						\   int big = 0;							\   nregs = 0;  fmask = 0;					\   for (regno = 16; regno< FIRST_PSEUDO_REGISTER; regno++)	\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       { nregs++; fmask |= 1<< (23 - regno); }			\   foffset = nregs * 12;						\   nregs = 0;  mask = 0;						\   if (frame_pointer_needed) regs_ever_live[FRAME_POINTER_REGNUM] = 0; \   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       { nregs++; mask |= 1<< regno; }				\   offset = foffset + nregs * 4;					\   if (offset + fsize>= 0x8000&& frame_pointer_needed)		\     { fprintf (FILE, "\tmov.l&%d,%%a0\n", -fsize);		\       fsize = 0, big = 1; }					\   if (exact_log2 (mask)>= 0) {					\     if (big)							\       fprintf (FILE, "\tmov.l -%d(%%fp,%%a0.l),%s\n",		\ 	       offset + fsize, reg_names[exact_log2 (mask)]);	\     else if (! frame_pointer_needed)				\       fprintf (FILE, "\tmov.l (%%sp)+,%s\n",			\ 	       reg_names[exact_log2 (mask)]);			\     else							\       fprintf (FILE, "\tmov.l -%d(%%fp),%s\n",			\ 	       offset + fsize, reg_names[exact_log2 (mask)]); }	\   else if (mask) {						\     if (big)							\       fprintf (FILE, "\tmovm.l -%d(%%fp,%%a0.l),&0x%x\n",	\ 	       offset + fsize, mask);				\     else if (! frame_pointer_needed)				\       fprintf (FILE, "\tmovm.l (%%sp)+,&0x%x\n", mask);		\     else							\       fprintf (FILE, "\tmovm.l -%d(%%fp),&0x%x\n",		\ 	       offset + fsize, mask); }				\   if (fmask) {							\     if (big)							\       fprintf (FILE, "\tfmovem -%d(%%fp,%%a0.l),&0x%x\n",	\ 	       foffset + fsize, fmask);				\     else if (! frame_pointer_needed)				\       fprintf (FILE, "\tfmovem (%%sp)+,&0x%x\n", fmask);	\     else							\       fprintf (FILE, "\tfmovem -%d(%%fp),&0x%x\n",		\ 	       foffset + fsize, fmask); }			\   if (frame_pointer_needed)					\     fprintf (FILE, "\tunlk %%fp\n");				\   if (current_function_pops_args)				\     fprintf (FILE, "\trtd&%d\n", current_function_pops_args);	\   else fprintf (FILE, "\trts\n"); }
end_define

begin_comment
comment|/* This is how to output an insn to push a register on the stack.    It need not be very fast code.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_PUSH
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tmov.l %s,-(%%sp)\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an insn to pop a register from the stack.    It need not be very fast code.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_POP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tmov.l (%%sp)+,%s\n", reg_names[REGNO])
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
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
value|"text"
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
value|"data"
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
value|"byte"
end_define

begin_comment
comment|/* The file command should always begin the output.  */
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
value|output_file_directive ((FILE), main_input_filename)
end_define

begin_comment
comment|/* Don't try to define `gcc_compiled.' since the assembler might not    accept symbols with periods and GDB doesn't run on this machine anyway.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_comment
comment|/* ihnp4!lmayk!lgm@eddie.mit.edu says mc68000 and m68k should not be here,    on the other hand I don't care what he says.  */
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
value|"-Dm68k -Dunix -DsysV68"
end_define

begin_comment
comment|/* Specify how to pad function arguments.    Value should be `upward', `downward' or `none'.    Same as the default, except no padding for large or variable-size args.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(((MODE) == BLKmode							\     ? ((TYPE)&& TREE_CODE (TYPE_SIZE (TYPE))	== INTEGER_CST		\&& int_size_in_bytes (TYPE)< PARM_BOUNDARY / BITS_PER_UNIT)	\     : GET_MODE_BITSIZE (MODE)< PARM_BOUNDARY)				\    ? downward : none)
end_define

begin_comment
comment|/* Override part of the obstack macros.  */
end_comment

begin_define
define|#
directive|define
name|__PTR_TO_INT
parameter_list|(
name|P
parameter_list|)
value|((int)(P))
end_define

begin_define
define|#
directive|define
name|__INT_TO_PTR
parameter_list|(
name|P
parameter_list|)
value|((char *)(P))
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (68k, SGS/AT&T sysV68 syntax)");
end_define

begin_comment
comment|/* Function calls save all but a0, a1, d0, d1, fp0, fp1.  */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_USED_REGISTERS
end_undef

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 0, 0, 0, 0, 0, 0,						\   1, 1, 0, 0, 0, 0, 0, 1,						\   1, 1, 0, 0, 0, 0, 0, 0}
end_define

begin_comment
comment|/* If TARGET_68881, return SF and DF values in fp0 instead of d0.  */
end_comment

begin_comment
comment|/* NYI: If FP=M68881U return SF and DF values in d0. */
end_comment

begin_comment
comment|/* NYI: If -mold return pointer in a0 and d0 */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_VALUE
end_undef

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
value|LIBCALL_VALUE(TYPE_MODE(VALTYPE))
end_define

begin_comment
comment|/* sysV68 (brain damaged) cc convention support. */
end_comment

begin_comment
comment|/* Commented out until we find a safe way to make it optional.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|(TREE_CODE (VALTYPE) == REAL_TYPE&& TARGET_68881 	\    ? gen_rtx (REG, TYPE_MODE (VALTYPE), 16)		\    : (TREE_CODE (VALTYPE) == POINTER_TYPE 		\       ? gen_rtx (REG, TYPE_MODE (VALTYPE), 8)		\       : gen_rtx (REG, TYPE_MODE (VALTYPE), 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If TARGET_68881, SF and DF values are returned in fp0 instead of d0.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIBCALL_VALUE
end_undef

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|gen_rtx (REG, (MODE), ((TARGET_68881&& ((MODE) == SFmode || (MODE) == DFmode)) ? 16 : 0))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    d0 may be used, and fp0 as well if -msoft-float is not specified.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_VALUE_REGNO_P
end_undef

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == 0 || (TARGET_68881&& (N) == 16))
end_define

begin_comment
comment|/* sysV68 (brain damaged) cc convention support. */
end_comment

begin_comment
comment|/* Commented out until we find a safe way to make it optional.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == 0 || (N) == 8 || (TARGET_68881&& (N) == 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_undef
undef|#
directive|undef
name|GLOBAL_ASM_OP
end_undef

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"global"
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FORMAT_PRIVATE_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 12),	\   sprintf ((OUTPUT), "%s_%%%d", (NAME), (LABELNO)))
end_define

begin_comment
comment|/* The sysV68 as doesn't know about double's and float's.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

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
value|do { union { double d; long l[2]; } tem;			\      tem.d = (VALUE);						\      fprintf(FILE, "\tlong 0x%x,0x%x\n", tem.l[0], tem.l[1]);	\    } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { union { float f; long l;} tem;			\      tem.f = (VALUE);					\      fprintf (FILE, "\tlong 0x%x\n", tem.l);		\    } while (0)
end_define

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INT
end_undef

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
value|( fprintf (FILE, "\tlong "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SHORT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\tshort "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CHAR
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CHAR
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\tbyte "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* This is how to output an assembler line for a numeric constant byte.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_BYTE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_BYTE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\tbyte 0x%x\n", (VALUE))
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

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
value|if ((LOG) == 1)			\     fprintf (FILE, "\teven\n");		\   else if ((LOG) != 0)			\     abort ();
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
value|fprintf (FILE, "\tspace %u\n", (SIZE))
end_define

begin_comment
comment|/* Can't use ASM_OUTPUT_SKIP in text section.  */
end_comment

begin_define
define|#
directive|define
name|ASM_NO_SKIP_IN_TEXT
value|1
end_define

begin_comment
comment|/* The beginnings of sdb support...  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_FILENAME
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|fprintf (FILE, "\tfile\t\"%s\"\n", FILENAME)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|FILE
parameter_list|,
name|LINENO
parameter_list|)
define|\
value|fprintf (FILE, "\tln\t%d\n",			\ 	   (sdb_begin_function_line		\ 	    ? last_linenum - sdb_begin_function_line : 1))
end_define

begin_comment
comment|/* Yet another null terminated string format.  */
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
value|{ register int sp = 0, lp = 0;				\     fprintf ((FILE), "\tbyte\t");				\   loop:								\     if ((PTR)[sp]> ' '&& ! ((PTR)[sp]& 0x80)&& (PTR)[sp] != '\\')	\       { lp += 3;						\ 	fprintf ((FILE), "'%c", (PTR)[sp]); }			\     else							\       { lp += 5;						\ 	fprintf ((FILE), "0x%x", (PTR)[sp]); }			\     if (++sp< (LEN))						\       {	if (lp> 60)						\ 	  { lp = 0;						\ 	    fprintf ((FILE), "\n\t%s ", ASCII_DATA_ASM_OP); }	\ 	else							\ 	  putc (',', (FILE));					\ 	goto loop; }						\     putc ('\n', (FILE)); }
end_define

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.     On the 68000, we use several CODE characters:    '.' for dot needed in Motorola-style opcode names.    '-' for an operand pushing on the stack:        sp@-, -(sp) or -(%sp) depending on the style of syntax.    '+' for an operand pushing on the stack:        sp@+, (sp)+ or (%sp)+ depending on the style of syntax.    '@' for a reference to the top word on the stack:        sp@, (sp) or (%sp) depending on the style of syntax.    '#' for an immediate operand prefix (# in MIT and Motorola syntax        but& in SGS syntax).    '!' for the fpcr register (used in some float-to-fixed conversions).    '$' for the letter `s' in an op code, but only on the 68040.    '&' for the letter `d' in an op code, but only on the 68040.     'b' for byte insn (no effect, on the Sun; this is for the ISI).    'd' to force memory addressing to be absolute, not relative.    'f' for float insn (print a CONST_DOUBLE as a float rather than in hex)    'w' for FPA insn (print a CONST_DOUBLE as a SunFPA constant rather        than directly).  Second part of 'y' below.    'x' for float insn (print a CONST_DOUBLE as a float rather than in hex),        or print pair of registers as rx:ry.    'y' for a FPA insn (print pair of registers as rx:ry).  This also outputs        CONST_DOUBLE's as SunFPA constant RAM registers if        possible, so it should not be used except for the SunFPA.  */
end_comment

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND
end_undef

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
define|\
value|{ if (CODE == '.') fprintf (FILE, ".");					\   else if (CODE == '#') fprintf (FILE, "&");				\   else if (CODE == '-') fprintf (FILE, "-(%%sp)");			\   else if (CODE == '+') fprintf (FILE, "(%%sp)+");			\   else if (CODE == '@') fprintf (FILE, "(%%sp)");			\   else if (CODE == '!') fprintf (FILE, "%%fpcr");			\   else if (CODE == '$') { if (TARGET_68040_ONLY) fprintf (FILE, "s"); }	\   else if (CODE == '&') { if (TARGET_68040_ONLY) fprintf (FILE, "d"); }	\   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_names[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     output_address (XEXP (X, 0));					\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) == SFmode)	\     { union { double d; int i[2]; } u;					\       union { float f; int i; } u1;					\       u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\       u1.f = u.d;							\
comment|/* Use hex representation even if CODE is f.  as needs it.  */
value|\       if (CODE == 'f')							\         fprintf (FILE, "&0x%x", u1.i);					\       else								\         fprintf (FILE, "&0x%x", u1.i); }				\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) == DFmode)	\     { union { double d; int i[2]; } u;					\       PRINT_OPERAND_EXTRACT_FLOAT (X);					\       fprintf (FILE, "&0x%08x%08x", u.i[0], u.i[1]); }			\   else { putc ('&', FILE); output_addr_const (FILE, X); }}
end_define

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
define|\
value|{ register rtx reg1, reg2, breg, ireg;					\   register rtx addr = ADDR;						\   rtx offset;								\   switch (GET_CODE (addr))						\     {									\     case REG:								\       fprintf (FILE, "(%s)", reg_names[REGNO (addr)]);			\       break;								\     case PRE_DEC:							\       fprintf (FILE, "-(%s)", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case POST_INC:							\       fprintf (FILE, "(%s)+", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case PLUS:								\       reg1 = 0;	reg2 = 0;						\       ireg = 0;	breg = 0;						\       offset = 0;							\       if (CONSTANT_ADDRESS_P (XEXP (addr, 0)))				\ 	{								\ 	  offset = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (CONSTANT_ADDRESS_P (XEXP (addr, 1)))			\ 	{								\ 	  offset = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) != PLUS) ;					\       else if (GET_CODE (XEXP (addr, 0)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) == REG || GET_CODE (addr) == MULT		\ 	  || GET_CODE (addr) == SIGN_EXTEND)				\ 	{ if (reg1 == 0) reg1 = addr; else reg2 = addr; addr = 0; }	\
comment|/*  for OLD_INDEXING							\       else if (GET_CODE (addr) == PLUS)					\ 	{								\ 	  if (GET_CODE (XEXP (addr, 0)) == REG)				\ 	    {								\ 	      reg2 = XEXP (addr, 0);					\ 	      addr = XEXP (addr, 1);					\ 	    }								\ 	  else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	    {								\ 	      reg2 = XEXP (addr, 1);					\ 	      addr = XEXP (addr, 0);					\ 	    }								\ 	}								\   */
value|\       if (offset != 0) { if (addr != 0) abort (); addr = offset; }	\       if ((reg1&& (GET_CODE (reg1) == SIGN_EXTEND			\ 		    || GET_CODE (reg1) == MULT))			\ 	  || (reg2 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg2))))		\ 	{ breg = reg2; ireg = reg1; }					\       else if (reg1 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg1)))		\ 	{ breg = reg1; ireg = reg2; }					\       if (ireg != 0&& breg == 0&& GET_CODE (addr) == LABEL_REF)	\         { int scale = 1;						\ 	  if (GET_CODE (ireg) == MULT)					\ 	    { scale = INTVAL (XEXP (ireg, 1));				\ 	      ireg = XEXP (ireg, 0); }					\ 	  if (GET_CODE (ireg) == SIGN_EXTEND)				\ 	    fprintf (FILE, "12(%%pc,%s.w",				\ 		     reg_names[REGNO (XEXP (ireg, 0))]); 		\ 	  else								\ 	    fprintf (FILE, "12(%%pc,%s.l",				\ 		     reg_names[REGNO (ireg)]);				\ 	  if (scale != 1) fprintf (FILE, "*%d", scale);			\ 	  fprintf (FILE, ")");						\ 	  break; }							\       if (breg != 0&& ireg == 0&& GET_CODE (addr) == LABEL_REF)	\         { fprintf (FILE, "12(%%pc,%s.l",				\ 		   reg_names[REGNO (breg)]);				\ 	  putc (')', FILE);						\ 	  break; }							\       if (ireg != 0 || breg != 0)					\ 	{ int scale = 1;						\ 	  if (breg == 0)						\ 	    abort ();							\ 	  if (addr != 0)						\ 	    output_addr_const (FILE, addr);				\ 	  fprintf (FILE, "(%s", reg_names[REGNO (breg)]);		\ 	  if (ireg != 0)					        \ 	    putc (',', FILE);						\ 	  if (ireg != 0&& GET_CODE (ireg) == MULT)			\ 	    { scale = INTVAL (XEXP (ireg, 1));				\ 	      ireg = XEXP (ireg, 0); }					\ 	  if (ireg != 0&& GET_CODE (ireg) == SIGN_EXTEND)		\ 	    fprintf (FILE, "%s.w", reg_names[REGNO (XEXP (ireg, 0))]);	\ 	  else if (ireg != 0)						\ 	    fprintf (FILE, "%s.l", reg_names[REGNO (ireg)]);		\ 	  if (scale != 1) fprintf (FILE, "*%d", scale);			\ 	  putc (')', FILE);						\ 	  break;							\ 	}								\       else if (reg1 != 0&& GET_CODE (addr) == LABEL_REF)		\ 	{ fprintf (FILE, "12(%%pc,%s.w)",				\ 		   reg_names[REGNO (reg1)]);				\ 	  break; }							\     default:								\       if (GET_CODE (addr) == CONST_INT					\&& INTVAL (addr)< 0x8000					\&& INTVAL (addr)>= -0x8000)					\ 	fprintf (FILE, "%d", INTVAL (addr));				\       else								\         output_addr_const (FILE, addr);					\     }}
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
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
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf ((LABEL), "%s%%%d", (PREFIX), (NUM))
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
value|fprintf (FILE, "%s%%%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "%s", NAME)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    (The 68000 does not use such vectors,    but we must define this macro anyway.)  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_VEC_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\tlong L%%%d\n", (VALUE))
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.  */
end_comment

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
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (FILE, "\tshort L%%%d-L%%%d\n", (VALUE), (REL))
end_define

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
name|TABLE
parameter_list|)
define|\
value|fprintf (FILE, "\tswbeg&%d\n%s%%%d:\n",				\ 	     XVECLEN (PATTERN (TABLE), 1), (PREFIX), (NUM))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* At end of a switch table, define LD%n iff the symbol LI%n was defined.  */
end_comment

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
value|{ if (switch_table_difference_label_flag)		\     asm_fprintf (FILE, "\t%s %LLD%d,%LL%d-%LLI%d-2.b\n",\ 		 SET_ASM_OP, (NUM), (NUM), (NUM))	\   switch_table_difference_label_flag = 0; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We have to define this to avoid errors.  */
end_comment

begin_decl_stmt
name|int
name|switch_table_difference_label_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate some opcodes to fit the sysV68 assembler syntax.  */
end_comment

begin_comment
comment|/* The opcodes fdmov and fsmov are guesses.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_JUMP_MATCH
value|"jmp 6(%%pc,"
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_OPCODE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|FILE
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{ if ((PTR)[0] == 'j'&& (PTR)[1] == 'b')		\     { ++(PTR);						\       while (*(PTR) != ' ')				\ 	{ putc (*(PTR), (FILE)); ++(PTR); }		\       fprintf ((FILE), ".w"); }				\   else if ((PTR)[0] == 's')				\     {							\       if (!strncmp ((PTR), "swap", 4))			\ 	{ fprintf ((FILE), "swap.w"); (PTR) += 4; }	\     }							\   else if ((PTR)[0] == 'f')				\     {							\       if (!strncmp ((PTR), "fmove", 5))			\ 	{ fprintf ((FILE), "fmov"); (PTR) += 5; }	\       else if (!strncmp ((PTR), "f%$move", 7))		\ 	{ if (TARGET_68040_ONLY)			\ 	    { fprintf ((FILE), "fsmov"); (PTR) += 7; }	\ 	  else						\ 	    { fprintf ((FILE), "fmov"); (PTR) += 7; } }	\       else if (!strncmp ((PTR), "f%&move", 7))		\ 	{ if (TARGET_68040_ONLY)			\ 	    { fprintf ((FILE), "fdmov"); (PTR) += 7; }	\ 	  else						\ 	    { fprintf ((FILE), "fmov"); (PTR) += 7; } }	\       else if (!strncmp ((PTR), "ftst", 4))		\ 	{ fprintf ((FILE), "ftest"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "fbne", 4))		\ 	{ fprintf ((FILE), "fbneq"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "fsne", 4))		\ 	{ fprintf ((FILE), "fsneq"); (PTR) += 4; }	\     }							\
comment|/* MOVE, MOVEA, MOVEQ, MOVEC ==> MOV	*/
value|\   else if ((PTR)[0] == 'm'&& (PTR)[1] == 'o'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 'e')	\     { fprintf ((FILE), "mov"); (PTR) += 4;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'a'		\ 	   || (PTR)[0] == 'c') (PTR)++; }		\
comment|/* SUB, SUBQ, SUBA, SUBI ==> SUB */
value|\   else if ((PTR)[0] == 's'&& (PTR)[1] == 'u' 		\&& (PTR)[2] == 'b')				\     { fprintf ((FILE), "sub"); (PTR) += 3;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'a') (PTR)++; }		\
comment|/* CMP, CMPA, CMPI, CMPM ==> CMP	*/
value|\   else if ((PTR)[0] == 'c'&& (PTR)[1] == 'm'		\&& (PTR)[2] == 'p')				\     { fprintf ((FILE), "cmp"); (PTR) += 3;		\        if ((PTR)[0] == 'a' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'm') (PTR)++; }		\
comment|/* JMP to switch label */
value|\   else if (!strncmp((PTR), (SWITCH_JUMP_MATCH), sizeof(SWITCH_JUMP_MATCH) - 1)) \     { while (*(PTR)++ != '(');				\       fprintf ((FILE), "jmp 8("); }			\ }
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

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
value|( fputs ("\tcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

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
value|( fputs ("\tlcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Override usual definitions of SDB output macros.    These definitions differ only in the absence of the period    at the beginning of the name of the directive    and in the use of `~' as the symbol for the current location.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_SCL
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "\tscl\t%d;", (a))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_INT_VAL
parameter_list|(
name|a
parameter_list|)
value|fprintf (asm_out_file, "\tval\t%d;", (a))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_VAL
parameter_list|(
name|a
parameter_list|)
define|\
value|( fputs ("\tval\t", asm_out_file),		\   output_addr_const (asm_out_file, (a)),	\   fputc (';', asm_out_file))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do { fprintf (asm_out_file, "\tdef\t");	\      ASM_OUTPUT_LABELREF (asm_out_file, a); 	\      fprintf (asm_out_file, ";"); } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_PLAIN_DEF
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file,"\tdef\t~%s;",a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_ENDEF
value|fputs("\tendef\n", asm_out_file)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_TYPE
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "\ttype\t0%o;", a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_SIZE
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "\tsize\t%d;", a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_START_DIM
value|fprintf(asm_out_file, "\tdim\t")
end_define

begin_define
define|#
directive|define
name|PUT_SDB_NEXT_DIM
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "%d,", a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_LAST_DIM
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "%d;", a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_TAG
parameter_list|(
name|a
parameter_list|)
define|\
value|do { fprintf (asm_out_file, "\ttag\t");	\      ASM_OUTPUT_LABELREF (asm_out_file, a);	\      fprintf (asm_out_file, ";"); } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~bb;\tval\t~;\tscl\t100;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~eb;\tval\t~;\tscl\t100;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~bf;\tval\t~;\tscl\t101;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~ef;\tval\t~;\tscl\t101;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_EPILOGUE_END
parameter_list|(
name|NAME
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t%s;\tval\t~;\tscl\t-1;\tendef\n",	\ 	   (NAME))
end_define

begin_define
define|#
directive|define
name|SDB_GENERATE_FAKE
parameter_list|(
name|BUFFER
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUFFER), "~%dfake", (NUMBER));
end_define

begin_comment
comment|/* Define subroutines to call to handle multiply, divide, and remainder.    Use the subroutines that the 3b1's library provides.    The `*' prevents an underscore from being prepended by the compiler.  */
end_comment

begin_define
define|#
directive|define
name|DIVSI3_LIBCALL
value|"*ldiv"
end_define

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"*uldiv"
end_define

begin_define
define|#
directive|define
name|MODSI3_LIBCALL
value|"*lrem"
end_define

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"*ulrem"
end_define

begin_define
define|#
directive|define
name|MULSI3_LIBCALL
value|"*lmul"
end_define

begin_define
define|#
directive|define
name|UMULSI3_LIBCALL
value|"*ulmul"
end_define

end_unit

