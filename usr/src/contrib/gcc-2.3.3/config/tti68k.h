begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.     Citicorp/TTI Unicom PBB version    (using GAS and encapsulated COFF)     Copyright (C) 1987, 1988, 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* Without STRUCTURE_SIZE_BOUNDARY, we can't ensure that structures are    aligned such that we can correctly extract bitfields from them.    Someone should check whether the usual compiler on this machine    provides the equivalent behavior of STRUCTURE_SIZE_BOUNDARY.  */
end_comment

begin_comment
comment|/* Alternative solutions are (1) define PCC_BITFIELD_TYPE_MATTERS,    if that fits what the usual compiler does,    or disable the -m68000 and -mnobitfield options.  */
end_comment

begin_error
error|#
directive|error
error|This doesn't define STRUCTURE_SIZE_BOUNDARY
end_error

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
comment|/* Define __HAVE_68881__ in preprocessor if -m68881 is specified.    This will control the use of inline 68881 insns in certain macros.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881:-D__HAVE_68881__}"
end_define

begin_comment
comment|/* Since some host machines will have to avoid generating code that    knows the format of floating point numbers on the tti68K,    we force all of them to avoid it when compiling for this    target, so that they will all generate exactly the same assembler    code as a result.  Otherwise code cross-hosted from a Vax would    differ from native-compiled code.  The performance penalty should    be minor in most cases.  Note that we still do constant folding    in the host float format, so things might be a few bits off here    or there.  */
end_comment

begin_define
define|#
directive|define
name|CAN_EXAMINE_68K_REAL_GUTS
value|0
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
comment|/* We want DBX format for use with gdb under encapsulated coff.  */
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
comment|/* -m68000 requires special flags to the assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68000:-mc68010}%{mc68000:-mc68010}"
end_define

begin_comment
comment|/* we use /lib/libp/lib*  when profiling */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!shlib:%{p:-L/lib/libp} %{pg:-L/lib/libp} -lc}"
end_define

begin_comment
comment|/* shared libraries need to use crt1.o  */
end_comment

begin_comment
comment|/*#define STARTFILE_SPEC*/
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shlib:%{pg:mcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}\    %{shlib:crt1.o%s shlib.ifile%s} "
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
comment|/* Define subroutines to call to handle multiply, divide, and remainder.    Use the subroutines that the 3b1's library provides.    The `*' prevents an underscore from being prepended by the compiler.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notnow
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|USE_C_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return pointer values in both d0 and a0.  */
end_comment

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
value|{								\   extern int current_function_returns_pointer;			\   if ((current_function_returns_pointer)&& 			\       ! find_equiv_reg (0, get_last_insn (), 0, 0, 0, 8, Pmode))\     fprintf (FILE, "\tmovel d0,a0\n");				\ }
end_define

end_unit

