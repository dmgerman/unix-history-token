begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Function to parse a `long long int' from text.    Copyright (C) 1995, 1996, 1997, 1999, 2001 Free Software Foundation, Inc.    This file is part of the GNU C Library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|QUAD
value|1
end_define

begin_include
include|#
directive|include
file|"strtol.c"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SHARED
end_ifdef

begin_include
include|#
directive|include
file|<shlib-compat.h>
end_include

begin_if
if|#
directive|if
name|SHLIB_COMPAT
argument_list|(
name|libc
operator|,
name|GLIBC_2_0
operator|,
name|GLIBC_2_2
argument_list|)
end_if

begin_expr_stmt
name|compat_symbol
argument_list|(
name|libc
argument_list|,
name|__strtoll_internal
argument_list|,
name|__strtoq_internal
argument_list|,
name|GLIBC_2_0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|weak_alias
argument_list|(
argument|strtoll
argument_list|,
argument|strtoq
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

