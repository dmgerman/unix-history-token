begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ARM RISCiX 1.1x version.    Copyright (C) 1993, 1995, 1997, 1999 Free Software Foundation, Inc.    Contributed by Richard Earnshaw (rwe11@cl.cam.ac.uk), based on original 	      work by Pieter `Tiggr' Schoenmakers (rcpieter@win.tue.nl)    	      and Martin Simmons (@harleqn.co.uk).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* RISCiX 1.1x is basically the same as 1.2x except that it doesn't have    symrename or atexit. */
end_comment

begin_comment
comment|/* Translation to find startup files.  On RISCiX boxes, gcrt0.o is in    /usr/lib.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:/usr/lib/gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Darm -Driscix -Dunix -Asystem=unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Riscix 1.1 doesn't have X/OPEN support, so only accept -mbsd (but ignore    it).      By not having -mxopen and -mno-symrename, we get warning messages,    but everything still compiles.  */
end_comment

begin_comment
comment|/* None of these is actually used in cc1, so they modify bit 31 */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{"bsd", 0x80000000, ""},
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

begin_ifdef
ifdef|#
directive|ifdef
name|riscos
end_ifdef

begin_define
define|#
directive|define
name|TARGET_WHEN_DEBUGGING
value|3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_WHEN_DEBUGGING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 'char' is signed by default on RISCiX, unsigned on RISCOS.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|riscos
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this if the target system lacks the function atexit from the    ANSI C standard.  If this is defined, and ON_EXIT is not    defined, a default exit function will be provided to support C++.      The man page only describes on_exit, but atexit is also there.      This seems to be missing in early versions.     FIXME Should we define ON_EXIT here?  */
end_comment

begin_define
define|#
directive|define
name|NEED_ATEXIT
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

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"%{!ansi: -D_BSD_C}"
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

