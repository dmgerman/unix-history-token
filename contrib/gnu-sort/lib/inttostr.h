begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inttostr.h -- convert integers to printable strings     Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Upper bound on the string length of an integer converted to string.    302 / 1000 is ceil (log10 (2.0)).  Subtract 1 for the sign bit;    add 1 for integer division truncation; add 1 more for a minus sign.  */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_BOUND
parameter_list|(
name|t
parameter_list|)
value|((sizeof (t) * CHAR_BIT - 1) * 302 / 1000 + 2)
end_define

begin_define
define|#
directive|define
name|INT_BUFSIZE_BOUND
parameter_list|(
name|t
parameter_list|)
value|(INT_STRLEN_BOUND (t) + 1)
end_define

begin_function_decl
name|char
modifier|*
name|offtostr
parameter_list|(
name|off_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|imaxtostr
parameter_list|(
name|intmax_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|umaxtostr
parameter_list|(
name|uintmax_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

