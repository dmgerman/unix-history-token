begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    DECstation (OSF/1 reference port with OSF/rose) version.    Copyright (C) 1991, 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|DECSTATION
end_define

begin_define
define|#
directive|define
name|OSF_OS
end_define

begin_define
define|#
directive|define
name|HALF_PIC_DEBUG
value|TARGET_DEBUG_B_MODE
end_define

begin_define
define|#
directive|define
name|HALF_PIC_PREFIX
value|"$Lp."
end_define

begin_include
include|#
directive|include
file|"halfpic.h"
end_include

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(!strcmp (STR, "Tdata") || !strcmp (STR, "Ttext")			\   || !strcmp (STR, "Tbss") || !strcmp (STR, "include")			\   || !strcmp (STR, "imacros") || !strcmp (STR, "aux-info")		\   || !strcmp (STR, "pic-names"))
end_define

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-DOSF -DOSF1 -Dbsd4_2 -DMIPSEL -Dhost_mips -Dmips -Dunix -DR3000 -DSYSTYPE_BSD"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{mmips-as: \ 	%{pipe:%e:-pipe not supported} \ 	%{EL} %{!EL:-EL} \ 	%{EB: %e-EB not supported} \ 	%{!mrnames: %{!.s:-nocpp} %{.s: %{cpp} %{nocpp}}} \ 	%{mips1} %{mips2} %{mips3} \ 	%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3} \ 	%{g} %{g0} %{g1} %{g2} %{g3} \ 	%{K} %{Q}} \ 	%{v*: -v} \ 	%{G*}"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|ASM_FINAL_SPEC
value|"\ %{mmips-as: %{!mno-mips-tfile: \ 	\n mips-tfile %{v*: -v} %{d*} \ 			%{K: -I %b.o~} \ 			%{!K: %{save-temps: -I %b.o~}} \ 			%{c:%W{o*}%{!o*:-o %b.o}}%{!c:-o %U.o} \ 			%{.s:%i} %{!.s:%g.s}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_define
define|#
directive|define
name|ASM_FINAL_SPEC
value|"\ %{mmips-as: %{mmips-tfile: \ 	\n mips-tfile %{v*: -v} %{d*} \ 			%{K: -I %b.o~} \ 			%{!K: %{save-temps: -I %b.o~}} \ 			%{c:%W{o*}%{!o*:-o %b.o}}%{!c:-o %U.o} \ 			%{.s:%i} %{!.s:%g.s}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{.S:	-D__LANGUAGE_ASSEMBLY__ -D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY} \ 	-ULANGUAGE_C -U__LANGUAGE_C__} \ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C__ -D__LANGUAGE_OBJECTIVE_C} \ %{!.S:	-D__LANGUAGE_C__  -D__LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %{G*} \ %{mmips-as: \ 	%{EL} %{!EL: -EL} \ 	%{EB: %e-EB not supported} \ 	%{mips1} %{mips2} %{mips3} \ 	%{bestGnum}} \ %{!mmips-as: \  	%{v*: -v} \ 	%{!noshrlib: %{pic-none: -noshrlib} %{!pic-none: -warn_nopic}} \ 	%{nostdlib} %{noshrlib} %{glue}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-lc"
end_define

begin_comment
comment|/* Define this macro meaning that `gcc' should find the library    `libgcc.a' by hand, rather than passing the argument `-lgcc' to    tell the linker to do the search. */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
value|1
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"DECstation with OSF/rose objects"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MD_EXEC_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/ccs/gcc/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MD_STARTFILE_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/ccs/lib/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Turn on -mpic-extern by default.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{O*: %{!mno-gpOPT:%{!mno-gpopt: -mgpopt}}} \ %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \ %{G*} \ %{pic-none:   -mno-half-pic} \ %{pic-lib:    -mhalf-pic} \ %{pic-extern: -mhalf-pic} \ %{pic-calls:  -mhalf-pic} \ %{pic-names*: -mhalf-pic} \ %{!pic-*:     -mhalf-pic}"
end_define

begin_comment
comment|/* Specify size_t, ptrdiff_t, and wchar_t types.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|((TARGET_WC8)					\ 				? "unsigned char"			\ 				: ((TARGET_WC16)			\ 					? "short unsigned int"		\ 					: "long unsigned int"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|MASK_GAS
end_define

begin_comment
comment|/* OSF/rose uses stabs, not ECOFF.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* Tell collect that the object format is OSF/rose.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ROSE
end_define

begin_comment
comment|/* Tell collect where the appropriate binaries are.  */
end_comment

begin_define
define|#
directive|define
name|REAL_LD_FILE_NAME
value|"/usr/ccs/gcc/gld"
end_define

begin_define
define|#
directive|define
name|REAL_NM_FILE_NAME
value|"/usr/ccs/bin/nm"
end_define

begin_define
define|#
directive|define
name|REAL_STRIP_FILE_NAME
value|"/usr/ccs/bin/strip"
end_define

begin_comment
comment|/* Use atexit for static constructors/destructors, instead of defining    our own exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Generate calls to memcpy, etc., not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* A C statement to output assembler commands which will identify    the object file as having been compiled with GNU CC (or another    GNU compiler).     If you don't define this macro, the string `gcc2_compiled.:' is    output.  This string is calculated to define a symbol which, on    BSD systems, will never be defined for any other reason.  GDB    checks for the presence of this symbol when reading the symbol    table of an executable.     On non-BSD systems, you must arrange communication with GDB in    some other fashion.  If GDB is not used on your system, you can    define this macro with an empty body.     On OSF/1, gcc2_compiled. confuses the kernel debugger, so don't    put it out.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|STREAM
parameter_list|)
end_define

begin_include
include|#
directive|include
file|"mips.h"
end_include

end_unit

