begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* human.h -- print human readable file size     Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert and Larry McVoy.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HUMAN_H_
end_ifndef

begin_define
define|#
directive|define
name|HUMAN_H_
value|1
end_define

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

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

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

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A conservative bound on the maximum length of a human-readable string.    The output can be the square of the largest uintmax_t, so double    its size before converting to a bound.    302 / 1000 is ceil (log10 (2.0)).  Add 1 for integer division truncation.    Also, the output can have a thousands separator between every digit,    so multiply by MB_LEN_MAX + 1 and then subtract MB_LEN_MAX.    Finally, append 3, the maximum length of a suffix.  */
end_comment

begin_define
define|#
directive|define
name|LONGEST_HUMAN_READABLE
define|\
value|((2 * sizeof (uintmax_t) * CHAR_BIT * 302 / 1000 + 1) * (MB_LEN_MAX + 1) \    - MB_LEN_MAX + 3)
end_define

begin_comment
comment|/* Options for human_readable.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* Unless otherwise specified these options may be ORed together.  */
comment|/* The following three options are mutually exclusive.  */
comment|/* Round to plus infinity (default).  */
name|human_ceiling
init|=
literal|0
block|,
comment|/* Round to nearest, ties to even.  */
name|human_round_to_nearest
init|=
literal|1
block|,
comment|/* Round to minus infinity.  */
name|human_floor
init|=
literal|2
block|,
comment|/* Group digits together, e.g. `1,000,000'.  This uses the      locale-defined grouping; the traditional C locale does not group,      so this has effect only if some other locale is in use.  */
name|human_group_digits
init|=
literal|4
block|,
comment|/* When autoscaling, suppress ".0" at end.  */
name|human_suppress_point_zero
init|=
literal|8
block|,
comment|/* Scale output and use SI-style units, ignoring the output block size.  */
name|human_autoscale
init|=
literal|16
block|,
comment|/* Prefer base 1024 to base 1000.  */
name|human_base_1024
init|=
literal|32
block|,
comment|/* Append SI prefix, e.g. "k" or "M".  */
name|human_SI
init|=
literal|64
block|,
comment|/* Append "B" (if base 1000) or "iB" (if base 1024) to SI prefix.  */
name|human_B
init|=
literal|128
block|}
enum|;
end_enum

begin_function_decl
name|char
modifier|*
name|human_readable
parameter_list|(
name|uintmax_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uintmax_t
parameter_list|,
name|uintmax_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|human_options
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|uintmax_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HUMAN_H_ */
end_comment

end_unit

