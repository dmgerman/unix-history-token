begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Base configuration file for all FreeBSD targets.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Common FreeBSD configuration.     All FreeBSD architectures should include this file, which will specify    their commonalities.    Adapted from /usr/src/contrib/gcc/config/i386/freebsd.h&     egcs/gcc/config/i386/freebsd-elf.h version by David O'Brien  */
end_comment

begin_comment
comment|/* Don't assume anything about the header files. */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* This defines which switch letters take arguments.  On svr4, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker).  We have a slightly different mix.  We    have -R (alias --rpath), no -z, --soname (-h), --assert etc. */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(   (CHAR) == 'D' \    || (CHAR) == 'U' \    || (CHAR) == 'o' \    || (CHAR) == 'e' \    || (CHAR) == 'T' \    || (CHAR) == 'u' \    || (CHAR) == 'I' \    || (CHAR) == 'm' \    || (CHAR) == 'x' \    || (CHAR) == 'L' \    || (CHAR) == 'A' \    || (CHAR) == 'V' \    || (CHAR) == 'B' \    || (CHAR) == 'b' \    || (CHAR) == 'h' \    || (CHAR) == 'z'
comment|/* ignored by ld */
value|\    || (CHAR) == 'R')
end_define

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\    || !strcmp (STR, "rpath") || !strcmp (STR, "rpath-link")		\    || !strcmp (STR, "soname") || !strcmp (STR, "defsym") 		\    || !strcmp (STR, "assert") || !strcmp (STR, "dynamic-linker"))
end_define

begin_define
define|#
directive|define
name|CPP_FBSD_PREDEFINES
value|"-Dunix -D__ELF__ -D__FreeBSD__=4 -D__FreeBSD_cc_version=400002 -Asystem(unix) -Asystem(FreeBSD)"
end_define

begin_comment
comment|/* Code generation parameters.  */
end_comment

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions.      (even though the svr4 ABI for the i386 says that records and unions are    returned in memory)  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* Ensure we the configuration knows our system correctly so we can link with    libraries compiled with the native cc. */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* Miscellaneous parameters.  */
end_comment

begin_comment
comment|/* Tell libgcc2.c that FreeBSD targets support atexit(3).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* FREEBSD_NATIVE is defined when gcc is integrated into the FreeBSD    source tree so it can be configured appropriately without using    the GNU configure/build mechanism. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FREEBSD_NATIVE
end_ifdef

begin_comment
comment|/* Look for the include files in the system-defined places.  */
end_comment

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/include/g++"
end_define

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"/usr/include"
end_define

begin_comment
comment|/* Now that GCC knows what the include path applies to, put the G++ one first.    C++ can now have include files that override the default C ones.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{						\     { GPLUSPLUS_INCLUDE_DIR, "C++", 1, 1 },	\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },		\     { 0, 0, 0, 0 }				\   }
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the compiler back ends is the    /usr/libexec directory.  */
end_comment

begin_define
define|#
directive|define
name|STANDARD_EXEC_PREFIX
value|"/usr/libexec/"
end_define

begin_define
define|#
directive|define
name|TOOLDIR_BASE_PREFIX
value|"/usr/libexec/"
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
end_comment

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/lib/"
end_define

begin_comment
comment|/* FreeBSD is 4.4BSD derived */
end_comment

begin_define
define|#
directive|define
name|bsd4_4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FREEBSD_NATIVE */
end_comment

end_unit

