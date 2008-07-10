begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* intprops.h -- properties of integer types     Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* The extra casts in the following macros work around compiler bugs,    e.g., in Cray C 5.0.3.0.  */
end_comment

begin_comment
comment|/* True if the arithmetic type T is an integer type.  bool counts as    an integer.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_IS_INTEGER
parameter_list|(
name|t
parameter_list|)
value|((t) 1.5 == 1)
end_define

begin_comment
comment|/* True if negative values of the signed integer type T use two's    complement, ones' complement, or signed magnitude representation,    respectively.  Much GNU code assumes two's complement, but some    people like to be portable to all possible C hosts.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_TWOS_COMPLEMENT
parameter_list|(
name|t
parameter_list|)
value|((t) ~ (t) 0 == (t) -1)
end_define

begin_define
define|#
directive|define
name|TYPE_ONES_COMPLEMENT
parameter_list|(
name|t
parameter_list|)
value|((t) ~ (t) 0 == 0)
end_define

begin_define
define|#
directive|define
name|TYPE_SIGNED_MAGNITUDE
parameter_list|(
name|t
parameter_list|)
value|((t) ~ (t) 0< (t) -1)
end_define

begin_comment
comment|/* True if the arithmetic type T is signed.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_comment
comment|/* The maximum and minimum values for the integer type T.  These    macros have undefined behavior if T is signed and has padding bits.    If this is a problem for you, please let us know how to fix it for    your host.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
define|\
value|((t) (! TYPE_SIGNED (t) \ 	? (t) 0 \ 	: TYPE_SIGNED_MAGNITUDE (t) \ 	? ~ (t) 0 \ 	: ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1)))
end_define

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
define|\
value|((t) (! TYPE_SIGNED (t) \ 	? (t) -1 \ 	: ~ (~ (t) 0<< (sizeof (t) * CHAR_BIT - 1))))
end_define

begin_comment
comment|/* Return zero if T can be determined to be an unsigned type.    Otherwise, return 1.    When compiling with GCC, INT_STRLEN_BOUND uses this macro to obtain a    tighter bound.  Otherwise, it overestimates the true bound by one byte    when applied to unsigned types of size 2, 4, 16, ... bytes.    The symbol signed_type_or_expr__ is private to this header file.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_define
define|#
directive|define
name|signed_type_or_expr__
parameter_list|(
name|t
parameter_list|)
value|TYPE_SIGNED (__typeof__ (t))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|signed_type_or_expr__
parameter_list|(
name|t
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bound on length of the string representing an integer type or expression T.    Subtract 1 for the sign bit if T is signed; log10 (2.0)< 146/485;    add 1 for integer division truncation; add 1 more for a minus sign    if needed.  */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_BOUND
parameter_list|(
name|t
parameter_list|)
define|\
value|((sizeof (t) * CHAR_BIT - signed_type_or_expr__ (t)) * 146 / 485 \    + signed_type_or_expr__ (t) + 1)
end_define

begin_comment
comment|/* Bound on buffer size needed to represent an integer type or expression T,    including the terminating null.  */
end_comment

begin_define
define|#
directive|define
name|INT_BUFSIZE_BOUND
parameter_list|(
name|t
parameter_list|)
value|(INT_STRLEN_BOUND (t) + 1)
end_define

end_unit

