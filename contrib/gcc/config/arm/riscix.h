begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ARM RISCiX version.    Copyright (C) 1993, 1994, 1995, 1997, 1999, 2000    Free Software Foundation, Inc.    Contributed by Richard Earnshaw (rwe11@cl.cam.ac.uk), based on original 	      work by Pieter `Tiggr' Schoenmakers (rcpieter@win.tue.nl)    	      and Martin Simmons (@harleqn.co.uk).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Translation to find startup files.  On RISC iX boxes,    crt0, mcrt0 and gcrt0.o are in /usr/lib.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\   %{pg:/usr/lib/gcrt0.o%s}\   %{!pg:%{p:/usr/lib/mcrt0.o%s}\         %{!p:/usr/lib/crt0.o%s}}"
end_define

begin_comment
comment|/* RISC iX has no concept of -lg */
end_comment

begin_comment
comment|/* If -static is specified then link with -lc_n */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"\   %{g*:-lg}\   %{!p:%{!pg:%{!static:-lc}%{static:-lc_n}}}\   %{p:-lc_p}\   %{pg:-lc_p}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The RISC iX assembler never deletes any symbols from the object module;    and, by default, ld doesn't either.  -X causes local symbols starting    with 'L' to be deleted, which is what we want.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-X"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Darm -Driscix -Dunix -Asystem=unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISCiX has some weird symbol name munging, that is done to the object module    after assembly, which enables multiple libraries to be supported within    one (possibly shared) library.  It basically changes the symbol name of    certain symbols (for example _bcopy is converted to _$bcopy if using BSD)    Symrename's parameters are determined as follows:      -mno-symrename	Don't run symrename      -mbsd	symrename -BSD<file>      -mxopen	symrename -XOPEN<file>      -ansi	symrename -<file><none>	symrename -BSD<file>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FINAL_SPEC
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CROSS_COMPILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASM_FINAL_SPEC
value|"\ %{!mno-symrename: \ 	\n /usr/bin/symrename \ 	-%{mbsd:%{pedantic:%e-mbsd and -pedantic incompatible}BSD}\ %{mxopen:%{mbsd:%e-mbsd and -mxopen incompatible}\ %{pedantic:%e-mxopen and -pedantic incompatible}XOPEN}\ %{!mbsd:%{!mxopen:%{!ansi:BSD}}} %{c:%{o*:%*}%{!o*:%b.o}}%{!c:%U.o}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* None of these is actually used in cc1.  If we don't define them in target    switches cc1 complains about them.  For the sake of argument lets allocate    bit 31 of target flags for such options.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{"bsd",	   0x80000000, N_("Do symbol renaming for BSD")},	\   {"xopen",	   0x80000000, N_("Do symbol renaming for X/OPEN")},	\   {"no-symrename", 0x80000000, N_("Don't do symbol renaming")},
end_define

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
define|\
value|fputs (" (ARM/RISCiX)", stderr);
end_define

begin_comment
comment|/* This is used in ASM_FILE_START */
end_comment

begin_define
define|#
directive|define
name|ARM_OS_NAME
value|"RISCiX"
end_define

begin_comment
comment|/* Unsigned chars produces much better code than signed.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_comment
comment|/* Some systems use __main in a way incompatible with its use in gcc, in these    cases use the macros NAME__MAIN to give a quoted symbol and SYMBOL__MAIN to    give the same symbol without quotes for an alternative entry point.  You    must define both, or neither. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAME__MAIN
end_ifndef

begin_define
define|#
directive|define
name|NAME__MAIN
value|"__gccmain"
end_define

begin_define
define|#
directive|define
name|SYMBOL__MAIN
value|__gccmain
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* size_t is "unsigned int" in RISCiX */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_comment
comment|/* ptrdiff_t is "int" in RISCiX */
end_comment

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_comment
comment|/* Maths operation domain error number, EDOM */
end_comment

begin_define
define|#
directive|define
name|TARGET_EDOM
value|33
end_define

begin_comment
comment|/* Override the normal default CPU */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_arm2
end_define

begin_comment
comment|/* r10 is reserved by RISCiX  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_CONDITIONAL_REGISTER_USAGE
define|\
value|fixed_regs[10] = 1;				\   call_used_regs[10] = 1;
end_define

begin_include
include|#
directive|include
file|"arm/aout.h"
end_include

begin_comment
comment|/* The RISCiX assembler does not understand .set */
end_comment

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_comment
comment|/* Add to CPP_SPEC, we want to add the right #defines when using the include    files.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"\ 	%{mbsd:%{pedantic:%e-mbsd and -pedantic incompatible} -D_BSD_C} \ 	%{mxopen:%{mbsd:%e-mbsd and -mxopen incompatible} 		\ 	  %{pedantic:%e-mxopen and -pedantic incompatible} -D_XOPEN_C}  \ 	%{!mbsd:%{!mxopen:%{!ansi: -D_BSD_C}}}"
end_define

begin_comment
comment|/* The native RISCiX assembler does not support stabs of any kind; because    the native assembler is not used by the compiler, Acorn didn't feel it was    necessary to put them in!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DBX_DEBUGGING_INFO
end_ifdef

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

