begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  HP-UX 68000/68020 version.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define USE_GAS if GCC is supposed to work with the GNU assembler,    GNU linker and GNU debugger using DBX debugging information.    (In other words, much of HPUX has been cast aside.)    Undefine USE_GAS if you want GCC to feed the HP assembler.  */
end_comment

begin_comment
comment|/* #define USE_GAS */
end_comment

begin_comment
comment|/* Use hp320g.h if you want this.  */
end_comment

begin_comment
comment|/* Control assembler-syntax conditionals in m68k.md.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GAS
end_ifndef

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
name|HPUX_ASM
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CROSS_COMPILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_BUGS
argument_list|)
end_if

begin_comment
comment|/* The assembler on HP 9k3xx machines running HPUX 8.0 doesn't translate    floating point constants behind some operands.  The workaround is to    use hex constants.  Reported by Thomas Nau (nau@medizin.uni-ulm.de).  */
end_comment

begin_define
define|#
directive|define
name|AS_BUG_FLOATING_CONSTANT
end_define

begin_comment
comment|/* The assembler on HP 9k3xx machines running HPUX 8.0 doesn't accept    labels followed by a text, data, or other section directive.  Reported    by Thomas Nau (nau@medizin.uni-ulm.de).  */
end_comment

begin_define
define|#
directive|define
name|AS_BUG_TRAILING_LABEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gcc.c should find libgcc.a itself rather than expecting linker to.  */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
end_define

begin_comment
comment|/* The arguments of -L must be a separate argv element.  */
end_comment

begin_define
define|#
directive|define
name|SPACE_AFTER_L_OPTION
end_define

begin_comment
comment|/* HP/UX doesn't have libg.a.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Be compatible with system stddef.h.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_comment
comment|/* Use atexit for static constructors/destructors, instead of defining    our own exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

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
comment|/* Define __HAVE_68881__ in preprocessor, unless -msoft-float is specified.    This will control the use of inline 68881 insns in certain macros.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_ASM
end_ifdef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m68000:+X}%{mc68000:+X}"
end_define

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|02
end_if

begin_comment
comment|/* -m68881 is the default */
end_comment

begin_comment
comment|/* These definitions differ from those used for GAS by defining __HPUX_ASM__.    This is needed because some programs, particularly GDB, need to    know which assembler is being used so that the correct `asm'    instructions can be used. */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{!msoft-float:-D__HAVE_68881__ }\ %{!ansi:%{!mc68000:%{!m68000:-Dmc68020}} -D_HPUX_SOURCE} -D__HPUX_ASM__"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* default is -msoft-float */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{m68881:-D__HAVE_68881__ }\ %{!ansi:%{!mc68000:%{!m68000:-Dmc68020}} -D_HPUX_SOURCE} -D__HPUX_ASM__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default is -msoft-float */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HPUX_ASM */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|02
end_if

begin_comment
comment|/* -m68881 is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{!msoft-float:-D__HAVE_68881__ }\ %{!ansi:%{!mc68000:%{!m68000:-Dmc68020}} -D_HPUX_SOURCE}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* default is -msoft-float */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{m68881:-D__HAVE_68881__ }\ %{!ansi:%{!mc68000:%{!m68000:-Dmc68020}} -D_HPUX_SOURCE}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default is -msoft-float */
end_comment

begin_comment
comment|/* -m68000 requires special flags to the assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68000:-mc68000}%{mc68000:-mc68000}%{!mc68000:%{!m68000:-mc68020}}"
end_define

begin_comment
comment|/* Tell GCC to put a space after -L when generating such options.  */
end_comment

begin_define
define|#
directive|define
name|SPACE_AFTER_L_OPTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not HPUX_ASM */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine    (for non-strict-ANSI programs only).  */
end_comment

begin_comment
comment|/* These are the ones defined by HPUX cc, plus mc68000 for uniformity with    GCC on other 68000 systems.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dhp9000s200 -Dhp9000s300 -DPWB -Dhpux -Dunix -D__hp9000s300 -D__hp9000s200 -D__PWB -D__hpux -D__unix"
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
comment|/* hpux doesn't use static area for struct returns. */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_STATIC_STRUCT_RETURN
end_undef

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* No longer correct in HPUX version 6.5.  */
end_comment

begin_comment
comment|/* Function calls don't save any fp registers on hpux.  */
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
value|{1, 1, 0, 0, 0, 0, 0, 0,						\   1, 1, 0, 0, 0, 0, 0, 1,						\   1, 1, 1, 1, 1, 1, 1, 1}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_ASM
end_ifdef

begin_comment
comment|/* Override parts of m68k.h to fit the HPUX assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_PROLOGUE
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_EPILOGUE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_PUSH
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_POP
end_undef

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SHORT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CHAR
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_BYTE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_VEC_ELT
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
name|ASM_OUTPUT_SKIP
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_FORMAT_PRIVATE_NAME
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
name|FUNCTION_PROFILER
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|GLOBAL_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (68k, SGS/hpux syntax)");
end_define

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%d0", "%d1", "%d2", "%d3", "%d4", "%d5", "%d6", "%d7",	\  "%a0", "%a1", "%a2", "%a3", "%a4", "%a5", "%fp", "%sp",	\  "%fp0", "%fp1", "%fp2", "%fp3", "%fp4", "%fp5", "%fp6", "%fp7"}
end_define

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
value|{ register int regno;						\   register int mask = 0;					\   extern char call_used_regs[];					\   int fsize = (SIZE);						\   if (frame_pointer_needed)					\     { if (fsize< 0x8000)					\         fprintf (FILE, "\tlink.w %%a6,&%d\n", -fsize);		\       else if (TARGET_68020)					\         fprintf (FILE, "\tlink.l %%a6,&%d\n", -fsize);		\       else							\ 	fprintf (FILE, "\tlink.w %%a6,&0\n\tsub.l&%d,%%sp\n", fsize); }  \   for (regno = 16; regno< FIRST_PSEUDO_REGISTER; regno++)	\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\        mask |= 1<< (regno - 16);				\   if (mask != 0)						\     fprintf (FILE, "\tfmovem&0x%x,-(%%sp)\n", mask& 0xff);       \   mask = 0;							\   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\        mask |= 1<< (15 - regno);				\   if (frame_pointer_needed)					\     mask&= ~ (1<< (15-FRAME_POINTER_REGNUM));			\   if (exact_log2 (mask)>= 0)					\     fprintf (FILE, "\tmov.l %s,-(%%sp)\n", reg_names[15 - exact_log2 (mask)]);  \   else if (mask) fprintf (FILE, "\tmovm.l&0x%x,-(%%sp)\n", mask); }
end_define

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
value|fprintf (FILE, "\tmov.l&LP%d,%%a0\n\tjsr mcount\n", (LABEL_NO));
end_define

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
value|{ register int regno;						\   register int mask, fmask;					\   register int nregs;						\   int offset, foffset;						\   extern char call_used_regs[];					\   int fsize = (SIZE);						\   int big = 0;							\   nregs = 0;  fmask = 0;					\   for (regno = 16; regno< FIRST_PSEUDO_REGISTER; regno++)	\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       { nregs++; fmask |= 1<< (23 - regno); }			\   foffset = nregs * 12;						\   nregs = 0;  mask = 0;						\   if (frame_pointer_needed) regs_ever_live[FRAME_POINTER_REGNUM] = 0; \   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       { nregs++; mask |= 1<< regno; }				\   offset = foffset + nregs * 4;					\   if (offset + fsize>= 0x8000&& frame_pointer_needed)		\     { fprintf (FILE, "\tmov.l&%d,%%a0\n", -fsize);		\       fsize = 0, big = 1; }					\   if (exact_log2 (mask)>= 0) {					\     if (big)							\       fprintf (FILE, "\tmov.l -%d(%%a6,%%a0.l),%s\n",		\ 	       offset + fsize, reg_names[exact_log2 (mask)]);	\     else if (! frame_pointer_needed)				\       fprintf (FILE, "\tmov.l (%%sp)+,%s\n",			\ 	       reg_names[exact_log2 (mask)]);			\     else							\       fprintf (FILE, "\tmov.l -%d(%%a6),%s\n",			\ 	       offset + fsize, reg_names[exact_log2 (mask)]); }	\   else if (mask) {						\     if (big)							\       fprintf (FILE, "\tmovm.l -%d(%%a6,%%a0.l),&0x%x\n",	\ 	       offset + fsize, mask);				\     else if (! frame_pointer_needed)				\       fprintf (FILE, "\tmovm.l (%%sp)+,&0x%x\n", mask);		\     else							\       fprintf (FILE, "\tmovm.l -%d(%%a6),&0x%x\n",		\ 	       offset + fsize, mask); }				\   if (fmask) {							\     if (big)							\       fprintf (FILE, "\tfmovem -%d(%%a6,%%a0.l),&0x%x\n",	\ 	       foffset + fsize, fmask);				\     else if (! frame_pointer_needed)				\       fprintf (FILE, "\tfmovem (%%sp)+,&0x%x\n", fmask);	\     else							\       fprintf (FILE, "\tfmovem -%d(%%a6),&0x%x\n",		\ 	       foffset + fsize, fmask); }			\   if (frame_pointer_needed)					\     fprintf (FILE, "\tunlk %%a6\n");				\   if (current_function_pops_args)				\     fprintf (FILE, "\trtd&%d\n", current_function_pops_args);	\   else fprintf (FILE, "\trts\n"); }
end_define

begin_comment
comment|/* This is how to output an insn to push a register on the stack.    It need not be very fast code.  */
end_comment

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

begin_comment
comment|/* For HPUX versions before 6.5, define this macro as empty.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|if (TARGET_68020)							\     {									\       if (TARGET_68881)							\ 	 fprintf (FILE, "\tversion 3\n");
comment|/* 68020 fp regs saved */
value|\       else								\ 	 fprintf (FILE, "\tversion 2\n");
comment|/* 68020 no fp regs saved */
value|\     }									\   else									\     fprintf (FILE, "\tversion 1\n");
end_define

begin_comment
comment|/* 68010 */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AS_BUG_TRAILING_LABEL
end_ifdef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\tlalign\t1\ntext"
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\tlalign\t1\ndata"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"text"
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"data"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASCII_DATA_ASM_OP
value|"byte"
end_define

begin_comment
comment|/* This is the command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"global"
end_define

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
value|( fputs ("\tcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
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
value|( fputs ("\tlcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,2\n", (ROUNDED)))
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 12),	\   sprintf ((OUTPUT), "%s___%d", (NAME), (LABELNO)))
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
value|do{  if (PREFIX[0] == 'L'&& PREFIX[1] == 'I')		\     fprintf(FILE, "\tset %s%d,.+2\n", PREFIX, NUM);	\   else							\     fprintf (FILE, "%s%d:\n", PREFIX, NUM);		\ } while(0)
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
value|fprintf (FILE, "\tdouble 0f%.20g\n", (VALUE))
end_define

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
value|fprintf (FILE, "\tfloat 0f%.9g\n", (VALUE))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AS_BUG_FLOATING_CONSTANT
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {								\     union { double d; int i[2]; } dummy_u;			\     dummy_u.d = (VALUE);					\     asm_fprintf (FILE, "%I0x%x%08x", dummy_u.i[0], dummy_u.i[1]); \
end_define

begin_expr_stmt
unit|} while
operator|(
literal|0
operator|)
end_expr_stmt

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {								\     union { float f; int i; } dummy_u;				\     dummy_u.f = (VALUE);					\     asm_fprintf (FILE, "%I0x%08x", dummy_u.i);			\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AS_BUG_FLOATING_CONSTANT */
end_comment

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant.  */
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
value|( fprintf (FILE, "\tlong "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

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
value|fprintf (FILE, "\tlong L%d\n", VALUE)
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
value|fprintf (FILE, "\tshort L%d-L%d\n", VALUE, REL)
end_define

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
value|if ((LOG) == 1)			\     fprintf (FILE, "\tlalign 2\n");	\   else if ((LOG) != 0)			\     abort ();
end_define

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

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|FILE
parameter_list|,
name|LINENO
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AS_BUG_FLOATING_CONSTANT
end_ifdef

begin_define
define|#
directive|define
name|PRINT_OPERAND_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|CODE
parameter_list|,
name|FLOAT
parameter_list|,
name|INT
parameter_list|)
define|\
value|fprintf (FILE, "&0x%x", (INT))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRINT_OPERAND_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|CODE
parameter_list|,
name|FLOAT
parameter_list|,
name|INT
parameter_list|)
define|\
value|if (CODE == 'f')					\     fprintf (FILE, "&0f%.9g", (FLOAT));			\   else							\     fprintf (FILE, "&0x%x", (INT))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AS_BUG_FLOATING_CONSTANT */
end_comment

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
value|{ if (CODE == '.') fprintf (FILE, ".");					\   else if (CODE == '#') fprintf (FILE, "&");				\   else if (CODE == '-') fprintf (FILE, "-(%%sp)");			\   else if (CODE == '+') fprintf (FILE, "(%%sp)+");			\   else if (CODE == '@') fprintf (FILE, "(%%sp)");			\   else if (CODE == '!') fprintf (FILE, "%%fpcr");			\   else if (CODE == '$') { if (TARGET_68040_ONLY) fprintf (FILE, "s"); } \   else if (CODE == '&') { if (TARGET_68040_ONLY) fprintf (FILE, "d"); } \   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_names[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     output_address (XEXP (X, 0));					\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) == SFmode)	\     { union { double d; int i[2]; } u;					\       union { float f; int i; } u1;					\       u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\       u1.f = u.d;							\       PRINT_OPERAND_FLOAT (FILE,CODE, u1.f, u1.i); }			\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) == DFmode)	\     { union { double d; int i[2]; } u;					\       u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\       fprintf (FILE, "&0f%.20g", u.d); }				\   else { putc ('&', FILE); output_addr_const (FILE, X); }}
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
define|\
value|{ register rtx reg1, reg2, breg, ireg;					\   register rtx addr = ADDR;						\   rtx offset;								\   switch (GET_CODE (addr))						\     {									\     case REG:								\       fprintf (FILE, "(%s)", reg_names[REGNO (addr)]);			\       break;								\     case PRE_DEC:							\       fprintf (FILE, "-(%s)", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case POST_INC:							\       fprintf (FILE, "(%s)+", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case PLUS:								\       reg1 = 0;	reg2 = 0;						\       ireg = 0;	breg = 0;						\       offset = 0;							\       if (CONSTANT_ADDRESS_P (XEXP (addr, 0)))				\ 	{								\ 	  offset = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (CONSTANT_ADDRESS_P (XEXP (addr, 1)))			\ 	{								\ 	  offset = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) != PLUS) ;					\       else if (GET_CODE (XEXP (addr, 0)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) == REG || GET_CODE (addr) == MULT		\ 	  || GET_CODE (addr) == SIGN_EXTEND)				\ 	{ if (reg1 == 0) reg1 = addr; else reg2 = addr; addr = 0; }	\
comment|/*  for OLD_INDEXING							\       else if (GET_CODE (addr) == PLUS)					\ 	{								\ 	  if (GET_CODE (XEXP (addr, 0)) == REG)				\ 	    {								\ 	      reg2 = XEXP (addr, 0);					\ 	      addr = XEXP (addr, 1);					\ 	    }								\ 	  else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	    {								\ 	      reg2 = XEXP (addr, 1);					\ 	      addr = XEXP (addr, 0);					\ 	    }								\ 	}								\   */
value|\       if (offset != 0) { if (addr != 0) abort (); addr = offset; }	\       if ((reg1&& (GET_CODE (reg1) == SIGN_EXTEND			\ 		    || GET_CODE (reg1) == MULT))			\ 	  || (reg2 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg2))))		\ 	{ breg = reg2; ireg = reg1; }					\       else if (reg1 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg1)))		\ 	{ breg = reg1; ireg = reg2; }					\       if (ireg != 0&& breg == 0&& GET_CODE (addr) == LABEL_REF)	\         { int scale = 1;						\ 	  if (GET_CODE (ireg) == MULT)					\ 	    { scale = INTVAL (XEXP (ireg, 1));				\ 	      ireg = XEXP (ireg, 0); }					\ 	  if (GET_CODE (ireg) == SIGN_EXTEND)				\ 	    fprintf (FILE, "L%d-LI%d(%%pc,%s.w",			\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     reg_names[REGNO (XEXP (ireg, 0))]); 		\ 	  else								\ 	    fprintf (FILE, "L%d-LI%d(%%pc,%s.l",			\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     reg_names[REGNO (ireg)]);				\ 	  if (scale != 1) fprintf (FILE, "*%d", scale);			\ 	  putc (')', FILE);						\ 	  break; }							\       if (ireg != 0 || breg != 0)					\ 	{ int scale = 1;						\ 	  if (breg == 0)						\ 	    abort ();							\ 	  if (addr != 0)						\ 	    output_addr_const (FILE, addr);				\ 	  fprintf (FILE, "(%s", reg_names[REGNO (breg)]);		\ 	  if (ireg != 0)						\ 	    putc (',', FILE);						\ 	  if (ireg != 0&& GET_CODE (ireg) == MULT)			\ 	    { scale = INTVAL (XEXP (ireg, 1));				\ 	      ireg = XEXP (ireg, 0); }					\ 	  if (ireg != 0&& GET_CODE (ireg) == SIGN_EXTEND)		\ 	    fprintf (FILE, "%s.w", reg_names[REGNO (XEXP (ireg, 0))]);	\ 	  else if (ireg != 0)						\ 	    fprintf (FILE, "%s.l", reg_names[REGNO (ireg)]);		\ 	  if (scale != 1) fprintf (FILE, "*%d", scale);			\ 	  putc (')', FILE);						\ 	  break;							\ 	}								\       else if (reg1 != 0&& GET_CODE (addr) == LABEL_REF)		\ 	{ fprintf (FILE, "L%d-LI%d(%%pc,%s.w)",				\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   reg_names[REGNO (reg1)]);				\ 	  break; }							\     default:								\       if (GET_CODE (addr) == CONST_INT					\&& INTVAL (addr)< 0x8000					\&& INTVAL (addr)>= -0x8000)					\ 	fprintf (FILE, "%d.w", INTVAL (addr));				\       else								\         output_addr_const (FILE, addr);					\     }}
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|,
name|size
parameter_list|)
define|\
value|{ register int i;			\   int inside;				\   inside = FALSE;			\   for (i = 0; i< (size); i++) {	\     if (i % 8 == 0) {			\       if (i != 0) {			\ 	if (inside)			\ 	  putc('"', (f));		\ 	putc('\n', (f));		\ 	inside = FALSE;			\       }					\       fprintf((f), "\t%s ", ASCII_DATA_ASM_OP);	\     }					\     if ((p)[i]< 32 || (p)[i] == '\\' || (p)[i] == '"' || (p)[i] == 127) {	\       if (inside) {			\ 	putc('"', (f));			\ 	inside = FALSE;			\       }					\       if (i % 8 != 0)			\ 	putc(',', (f));			\       fprintf((f), "%d", (p)[i]);	\     } else {				\       if (!inside) {			\ 	if (i % 8 != 0)			\ 	  putc(',', (f));		\ 	putc('"', (f));			\ 	inside = TRUE;			\       }					\       putc((p)[i], (f));		\     }					\   }					\   if (inside)				\     putc('"', (f));			\   putc('\n', (f));			\ }
end_define

begin_comment
comment|/* Translate Motorola opcodes such as `jbeq'    into SGS opcodes such as `beq.w'.    Delete the `e' in `move...' and `fmove'.    Change `ftst' to `ftest'.  */
end_comment

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
value|{ if ((PTR)[0] == 'j'&& (PTR)[1] == 'b')		\     { ++(PTR);						\       while (*(PTR) != ' ')				\ 	{ putc (*(PTR), (FILE)); ++(PTR); }		\       fprintf ((FILE), ".w"); }				\   else if ((PTR)[0] == 'f')				\     {							\       if (!strncmp ((PTR), "fmove", 5))			\ 	{ fprintf ((FILE), "fmov"); (PTR) += 5; }	\       else if (!strncmp ((PTR), "ftst", 4))		\ 	{ fprintf ((FILE), "ftest"); (PTR) += 4; }	\     }							\   else if ((PTR)[0] == 'm'&& (PTR)[1] == 'o'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 'e')	\     { fprintf ((FILE), "mov"); (PTR) += 4; }		\ }
end_define

begin_comment
comment|/* Prevent output of `gcc_compiled.:'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HPUX_ASM */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_comment
comment|/* HP-UX needs the call to mcount before the link instruction.    Copy the return address onto the stack before the call to fake it out.  */
end_comment

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
value|fprintf (FILE, "\tmovel a6@(4),sp@-\n" \                   "\tmovl #LP%d,a0\n\tjsr mcount\n" \                   "\taddqw #4,sp\n", (LABEL_NO));
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HPUX_ASM */
end_comment

end_unit

