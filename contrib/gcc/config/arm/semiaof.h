begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ARM on semi-hosted platform    AOF Syntax assembler.    Copyright (C) 1995, 1996, 1997, 2004 Free Software Foundation, Inc.    Contributed by Richard Earnshaw (richard.earnshaw@armltd.co.uk)     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {					\ 	builtin_define_std ("arm");		\ 	builtin_define_std ("semi");		\     } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{g -g} -arch 4 -apcs 3/32bit"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{Eb: armlib_h.32b%s}%{!Eb: armlib_h.32l%s}"
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/semi-hosted)", stderr);
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT_FLOAT_ABI
value|ARM_FLOAT_ABI_HARD
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(0)
end_define

begin_comment
comment|/* The Norcroft C library defines size_t as "unsigned int".  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

end_unit

