begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: freebsd.h,v 1.15 1999/07/02 19:26:45 obrien Exp $ */
end_comment

begin_comment
comment|/* Base configuration file for all FreeBSD targets.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Common FreeBSD configuration.     All FreeBSD architectures should include this file, which will specify    their commonalities.    Adapted from /usr/src/contrib/gcc/config/i386/freebsd.h&     egcs/gcc/config/i386/freebsd-elf.h version by David O'Brien  */
end_comment

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_IMPLICIT_EXTERN_C
end_undef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* This defines which switch letters take arguments.  On FreeBSD, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker) (comming from svr4).    We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR) \    || (CHAR) == 'h' \    || (CHAR) == 'z'
comment|/* ignored by ld */
value|\    || (CHAR) == 'R')
end_define

begin_define
define|#
directive|define
name|FBSD_WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\    || !strcmp (STR, "rpath") || !strcmp (STR, "rpath-link")		\    || !strcmp (STR, "soname") || !strcmp (STR, "defsym") 		\    || !strcmp (STR, "assert") || !strcmp (STR, "dynamic-linker"))
end_define

begin_comment
comment|/* Place spaces around this string.  We depend on string splicing to produce    the final CPP_PREDEFINES value.  */
end_comment

begin_define
define|#
directive|define
name|CPP_FBSD_PREDEFINES
value|" -Dunix -D__FreeBSD__=4 -D__FreeBSD_cc_version=400002 -Asystem(unix) -Asystem(FreeBSD) "
end_define

begin_comment
comment|/* Provide a LIB_SPEC appropriate for FreeBSD.  Just select the appropriate    libc, depending on whether we're doing profiling.     (like the default, except no -lg, and no -p).  */
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
value|"%{!shared:%{!pg:%{!pthread:%{!kthread:-lc}%{kthread:-lpthread -lc}}%{pthread:-lc_r}}%{pg:%{!pthread:%{!kthread:-lc_p}%{kthread:-lpthread_p -lc_p}}%{pthread:-lc_r_p}}}"
end_define

begin_comment
comment|/* Code generation parameters.  */
end_comment

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions    (even though the svr4 ABI for the i386 says that records and unions are    returned in memory).  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* Ensure we the configuration knows our system correctly so we can link with    libraries compiled with the native cc.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* Use more efficient ``thunks'' to implement C++ vtables.  XXX note that     this setting is claimed to have a few bugs by the EGCS maintainers.  They    believe the bugs will be worked out in EGCS 1.2.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_VTABLE_THUNKS
end_undef

begin_define
define|#
directive|define
name|DEFAULT_VTABLE_THUNKS
value|1
end_define

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
comment|/* Our malloc can allocte pagesized blocks efficiently.  The default size     of 4072 bytes is not optimal on the i386 nor the Alpha.  */
end_comment

begin_define
define|#
directive|define
name|OBSTACK_CHUNK_SIZE
value|(getpagesize())
end_define

end_unit

