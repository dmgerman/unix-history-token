begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Motorola m88100 running the AT&T/Unisoft/Motorola V.3 reference port.    Copyright (C) 1990, 1991 Free Software Foundation, Inc.    Contributed by Ray Essick (ressick@mot.com)    Currently supported by Tom Wood (wood@dg-rtp.dg.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m88k.h"
end_include

begin_comment
comment|/* Default switches */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_CHECK_ZERO_DIV	| \ 			 MASK_OCS_DEBUG_INFO	| \ 			 MASK_OCS_FRAME_POSITION)
end_define

begin_comment
comment|/* Macros to be automatically defined.  */
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
value|"-Dm88000 -Dm88k -Dunix -DsysV88 -D__CLASSIFY_TYPE__=2"
end_define

begin_comment
comment|/* Override svr3.h to link with ?crt0.o instead of ?crt1.o and ?crtn.o.    From arul@sdsu.edu.  */
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
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}} crtbegin.o%s"
end_define

begin_comment
comment|/* Profiled libraries live in a different directory but keep the same    names other than that.  arul@sdsu.edu says -lg is always needed.  */
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
value|"%{p:-L/lib/libp}%{pg:%{!p:-L/lib/libp}} -lg -lc crtend.o%s"
end_define

begin_comment
comment|/* Hot version of the profiler that uses r10 to pass the address of    the counter.  the _gcc_mcount routine knows not to screw with    the parameter registers.     DG/UX does this; i wrote a gnu-c/88k specific version and put it    in libgcc2.c -- RBE; this macro knows about the leading underscore    convention.  */
end_comment

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
name|LABELNO
parameter_list|)
define|\
value|output_function_profiler (FILE, LABELNO, "_gcc_mcount", 0)
end_define

begin_comment
comment|/* Various other changes that we want to have in place without    too many changes to the m88k.h file.  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_LIBG
end_undef

begin_define
define|#
directive|define
name|USE_LIBG
end_define

begin_comment
comment|/* Define a few machine-specific details of the implementation of    constructors.  */
end_comment

begin_comment
comment|/* Although the .init section is used, it is not automatically invoked.  */
end_comment

begin_define
define|#
directive|define
name|INVOKE__main
end_define

begin_comment
comment|/* State that atexit exists so __do_global_ctors will register    __do_global_dtors.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
define|\
value|asm (INIT_SECTION_ASM_OP);		\   asm ("\tsubu\t r31,r31,16");
comment|/* (STACK_BOUNDARY / BITS_PER_UNIT) == 16 */
value|\   asm ("\tst\t r0,r31,32");
end_define

begin_comment
comment|/* REG_PARM_STACK_SPACE (0) == 32 */
end_comment

begin_define
define|#
directive|define
name|CTOR_LIST_END
end_define

begin_comment
comment|/* ASM_OUTPUT_CONSTRUCTOR outputs code into the .init section to push the    address of the constructor.  This becomes the body of __do_global_ctors    in crtstuff.c.  r13 is a temporary register.  */
end_comment

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
value|do {									\     init_section ();							\     fprintf (FILE, "\tor.u\t r13,r0,hi16(");				\     assemble_name (FILE, NAME);						\     fprintf (FILE, ")\n\tor\t r13,r13,lo16(");				\     assemble_name (FILE, NAME);						\     fprintf (FILE, ")\n\tsubu\t r31,r31,%d\n\tst\t r13,r31,%d\n",	\ 	     STACK_BOUNDARY / BITS_PER_UNIT, REG_PARM_STACK_SPACE (0));	\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_CTORS_BODY
end_undef

begin_define
define|#
directive|define
name|DO_GLOBAL_CTORS_BODY
define|\
value|do {									\   func_ptr *__CTOR_LIST__ = __builtin_alloca (0), *p;			\   for (p = __CTOR_LIST__; *p; p += 4)					\     (*p) ();								\ } while (0)
end_define

begin_define
define|#
directive|define
name|DTOR_LIST_BEGIN
define|\
value|asm (FINI_SECTION_ASM_OP);						\   func_ptr __DTOR_LIST__[4] = { (func_ptr) (-1), (func_ptr) (-1),	\ 				(func_ptr) (-1), (func_ptr) (-1) }
end_define

begin_define
define|#
directive|define
name|DTOR_LIST_END
define|\
value|asm (FINI_SECTION_ASM_OP);						\   func_ptr __DTOR_END__[4] = { (func_ptr) 0, (func_ptr) 0,		\ 			       (func_ptr) 0, (func_ptr) 0 }
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global destructors.  The table is constructed in the .fini section    so that an explicit linker script is not required.  The complication    is that this section is padded with NOP instructions and to either    8 or 16 byte alignment depending on the specific system.  A clever    way to avoid trouble is to output a block of 16 bytes where the    extra words are known values (-1).  */
end_comment

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
value|do {						\     register int i;				\     fini_section ();				\     fprintf (FILE, "\t%s\t ", ASM_LONG);	\     assemble_name (FILE,NAME);			\     fprintf (FILE, "\n");			\     for (i = 1; i< 4; i++)			\       fprintf (FILE, "\t%s\t -1\n", ASM_LONG);	\     } while (0)
end_define

begin_comment
comment|/* Walk the list looking for the terminating zero and ignoring all values of    -1.  */
end_comment

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_DTORS_BODY
end_undef

begin_define
define|#
directive|define
name|DO_GLOBAL_DTORS_BODY
define|\
value|do {						\     int i;					\     for (i = 0; __DTOR_LIST__[i] != 0; i++)	\       if (((int *)__DTOR_LIST__)[i] != -1)	\ 	__DTOR_LIST__[i] ();			\   } while (0)
end_define

end_unit

