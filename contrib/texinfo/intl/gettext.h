begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal header for GNU gettext internationalization functions    Copyright (C) 1995, 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GETTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|_GETTEXT_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|HAVE_LIMITS_H
operator|||
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ end of prolog @@ */
end_comment

begin_comment
comment|/* The magic number of the GNU message catalog format.  */
end_comment

begin_define
define|#
directive|define
name|_MAGIC
value|0x950412de
end_define

begin_define
define|#
directive|define
name|_MAGIC_SWAPPED
value|0xde120495
end_define

begin_comment
comment|/* Revision number of the currently used .mo (binary) file format.  */
end_comment

begin_define
define|#
directive|define
name|MO_REVISION_NUMBER
value|0
end_define

begin_comment
comment|/* The following contortions are an attempt to use the C preprocessor    to determine an unsigned integral type that is 32 bits wide.  An    alternative approach is to use autoconf's AC_CHECK_SIZEOF macro, but    doing that would require that the configure script compile and *run*    the resulting executable.  Locally running cross-compiled executables    is usually not possible.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|UINT_MAX_32_BITS
value|4294967295U
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UINT_MAX_32_BITS
value|0xFFFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If UINT_MAX isn't defined, assume it's a 32-bit type.    This should be valid for all systems GNU cares about because    that doesn't include 16-bit systems, and only modern systems    (that certainly have<limits.h>) have 64+-bit integral types.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UINT_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT_MAX
value|UINT_MAX_32_BITS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|UINT_MAX
operator|==
name|UINT_MAX_32_BITS
end_if

begin_typedef
typedef|typedef
name|unsigned
name|nls_uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|USHRT_MAX
operator|==
name|UINT_MAX_32_BITS
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|nls_uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|ULONG_MAX
operator|==
name|UINT_MAX_32_BITS
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|nls_uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The following line is intended to throw an error.  Using #error is      not portable enough.  */
end_comment

begin_expr_stmt
literal|"Cannot determine unsigned 32-bit data type."
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
comment|/* Header for binary .mo file format.  */
expr|struct
name|mo_file_header
block|{
comment|/* The magic number.  */
name|nls_uint32
name|magic
block|;
comment|/* The revision number of the file format.  */
name|nls_uint32
name|revision
block|;
comment|/* The number of strings pairs.  */
name|nls_uint32
name|nstrings
block|;
comment|/* Offset of table with start offsets of original strings.  */
name|nls_uint32
name|orig_tab_offset
block|;
comment|/* Offset of table with start offsets of translation strings.  */
name|nls_uint32
name|trans_tab_offset
block|;
comment|/* Size of hashing table.  */
name|nls_uint32
name|hash_tab_size
block|;
comment|/* Offset of first hashing entry.  */
name|nls_uint32
name|hash_tab_offset
block|; }
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|string_desc
block|{
comment|/* Length of addressed string.  */
name|nls_uint32
name|length
decl_stmt|;
comment|/* Offset of string in file.  */
name|nls_uint32
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* @@ begin of epilog @@ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gettext.h  */
end_comment

end_unit

