begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Base configuration file for all FreeBSD targets.    Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Common FreeBSD configuration.     All FreeBSD architectures should include this file, which will specify    their commonalities.    Adapted from gcc/config/i386/freebsd-elf.h by     David O'Brien<obrien@FreeBSD.org>.      Further work by David O'Brien<obrien@FreeBSD.org> and    Loren J. Rittle<ljrittle@acm.org>.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* In case we need to know.  */
end_comment

begin_define
define|#
directive|define
name|USING_CONFIG_FREEBSD
value|1
end_define

begin_comment
comment|/* This defines which switch letters take arguments.  On FreeBSD, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker) (coming from SVR4).    We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */
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
value|(FBSD_SWITCH_TAKES_ARG(CHAR))
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
value|(FBSD_WORD_SWITCH_TAKES_ARG(STR))
end_define

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
value|FBSD_TARGET_OS_CPP_BUILTINS()
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|FBSD_CPP_SPEC
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|FBSD_STARTFILE_SPEC
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|FBSD_ENDFILE_SPEC
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|FBSD_LIB_SPEC
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* All FreeBSD Architectures support the ELF object file format.  */
end_comment

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_ELF
end_undef

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ELF
value|1
end_define

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
value|1
end_define

begin_comment
comment|/* Make gcc agree with FreeBSD's standard headers (<machine/ansi.h>, etc...)  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FREEBSD_NATIVE
end_ifdef

begin_define
define|#
directive|define
name|LIBSTDCXX_PROFILE
value|"-lstdc++_p"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MATH_LIBRARY_PROFILE
value|"-lm_p"
end_define

begin_comment
comment|/* Code generation parameters.  */
end_comment

begin_comment
comment|/* Writing `int' for a bitfield forces int alignment for the structure.  */
end_comment

begin_comment
comment|/* XXX: ok for Alpha??  */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_BITFIELD_TYPE_MATTERS
end_undef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Use periods rather than dollar signs in special g++ assembler names.    This ensures the configuration knows our system correctly so we can link    with libraries compiled with the native cc.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* Used by libgcc2.c.  We support file locking with fcntl / F_SETLKW.    This enables the test coverage code to use file locking when exiting a    program, which avoids race conditions if the program has forked.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HAS_F_SETLKW
value|1
end_define

end_unit

