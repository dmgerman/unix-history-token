begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.     Citicorp/TTI Unicom PBB version (using GAS with a %-register prefix)     Copyright (C) 1987, 1988, 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note:   This config uses a version of gas with a postprocessing stage that    converts the output of gas to coff containing stab debug symbols.    (See vasta@apollo.com or mb@soldev.tti.com) */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* See m68k.h.  5 means 68020 without 68881.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|5
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
comment|/* Define __HAVE_68881__ in preprocessor if -m68881 is specified.    This will control the use of inline 68881 insns in certain macros.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881:-D__HAVE_68881__}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dm68k -Dunix -DUnicomPBB -Dmc68k -Dmc68020 -Dmc68k32"
end_define

begin_comment
comment|/* We want DBX format for use with gdb under COFF.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
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
comment|/* -m68000 requires special flags to the assembler. */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|" %{m68000:-mc68010}%{mc68000:-mc68010}"
end_define

begin_comment
comment|/* we use /lib/libp/lib*  when profiling */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-L/usr/lib/libp} %{pg:-L/usr/lib/libp} -lc"
end_define

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_comment
comment|/*  * The loader directive file gcc.ifile defines how to merge the constructor   * sections into the data section.  Also, since gas only puts out those   * sections in response to N_SETT stabs, and does not (yet) have a   * ".sections" directive, gcc.ifile also defines the list symbols   * __DTOR_LIST__ and __CTOR_LIST__.  *   * Finally, we must explicitly specify the file from libgcc.a that defines  * exit(), otherwise if the user specifies (for example) "-lc_s" on the   * command line, the wrong exit() will be used and global destructors will   * not get called .  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!r: gcc.ifile%s} %{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}} \ %{!r:_exit.o%s}"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtn.o%s"
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
comment|/* GAS register prefix assembly syntax: */
end_comment

begin_comment
comment|/* User labels have no prefix */
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
comment|/* local labels are prefixed with ".L" */
end_comment

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* registers are prefixed with "%" */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_PREFIX
end_undef

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|"%"
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
value|{"%d0", "%d1", "%d2", "%d3", "%d4", "%d5", "%d6", "%d7",	\  "%a0", "%a1", "%a2", "%a3", "%a4", "%a5", "%a6", "%sp",	\  "%fp0", "%fp1", "%fp2", "%fp3", "%fp4", "%fp5", "%fp6", "%fp7"}
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_EXTRA_EPILOGUE
end_undef

begin_define
define|#
directive|define
name|FUNCTION_EXTRA_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{ extern int current_function_returns_pointer;			\     if ((current_function_returns_pointer)&&				\       ! find_equiv_reg (0, get_last_insn (), 0, 0, 0, 8, Pmode))        \       asm_fprintf (FILE, "\tmovl %Rd0,%Ra0\n"); }
end_define

begin_define
define|#
directive|define
name|ASM_RETURN_CASE_JUMP
value|return "jmp %%pc@(2,%0:w)"
end_define

begin_comment
comment|/* Although the gas we use can create .ctor and .dtor sections from N_SETT    stabs, it does not support section directives, so we need to have the loader    define the lists.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_LISTS_DEFINED_EXTERNALLY
end_define

begin_comment
comment|/* similar to default, but allows for the table defined by ld with gcc.ifile.     nptrs is always 0.  So we need to instead check that __DTOR_LIST__[1] != 0.    The old check is left in so that the same macro can be used if and when      a future version of gas does support section directives. */
end_comment

begin_define
define|#
directive|define
name|DO_GLOBAL_DTORS_BODY
value|{int nptrs = *(int *)__DTOR_LIST__; int i; \   if (nptrs == -1 || (__DTOR_LIST__[0] == 0&& __DTOR_LIST__[1] != 0))  \     for (nptrs = 0; __DTOR_LIST__[nptrs + 1] != 0; nptrs++); 		\   for (i = nptrs; i>= 1; i--)						\     __DTOR_LIST__[i] (); }
end_define

begin_comment
comment|/*   * Here is an example gcc.ifile.  I've tested it on PBB 68k and on sco 386  * systems. The NEXT(0x200000) works on just about all 386 and m68k systems,   * but can be reduced to any power of 2 that is>= NBPS (0x10000 on a pbb).     SECTIONS {        .text BIND(0x200200) BLOCK (0x200) :  		{ *(.init) *(.text) vfork = fork; *(.fini) }        	GROUP BIND( NEXT(0x200000) + ADDR(.text) + SIZEOF(.text)): 	{      .data : { __CTOR_LIST__ = . ; . += 4; *(.ctor) . += 4 ; 		       	 __DTOR_LIST__ = . ; . += 4; *(.dtor) . += 4 ; } 	       .bss : { }        }   }  */
end_comment

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

