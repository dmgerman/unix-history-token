begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC,    for SPARC running in an embedded environment using the ELF file format.    Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|"crt0.o%s crti.o%s crtbegin.o%s"
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
define|\
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \    crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* Use the default.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_comment
comment|/* Don't set the target flags, this is done by the linker script */
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
value|""
end_define

begin_comment
comment|/* FIXME: until fixed */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* This solaris2 define does not apply.  */
end_comment

begin_undef
undef|#
directive|undef
name|STDC_0_IN_SYSTEM_HEADERS
end_undef

begin_comment
comment|/* We don't want to use the Solaris2 specific long long int conversion    routines or 64-bit integer multiply and divide routines.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUN_CONVERSION_LIBFUNCS
end_undef

begin_define
define|#
directive|define
name|SUN_CONVERSION_LIBFUNCS
value|0
end_define

begin_undef
undef|#
directive|undef
name|SUN_INTEGER_MULTIPLY_64
end_undef

begin_define
define|#
directive|define
name|SUN_INTEGER_MULTIPLY_64
value|0
end_define

end_unit

