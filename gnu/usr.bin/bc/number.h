begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* number.h: Arbitrary precision numbers header file. */
end_comment

begin_comment
comment|/*  This file is part of bc written for MINIX.     Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2 of the License , or     (at your option) any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; see the file COPYING.  If not, write to     the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.      You may contact the author by:        e-mail:  phil@cs.wwu.edu       us-mail:  Philip A. Nelson                 Computer Science Department, 9062                 Western Washington University                 Bellingham, WA 98226-9062  *************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PLUS
block|,
name|MINUS
block|}
name|sign
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|sign
name|n_sign
decl_stmt|;
name|int
name|n_len
decl_stmt|;
comment|/* The number of digits before the decimal point. */
name|int
name|n_scale
decl_stmt|;
comment|/* The number of digits after the decimal point. */
name|int
name|n_refs
decl_stmt|;
comment|/* The number of pointers to this number. */
name|char
name|n_value
index|[
literal|1
index|]
decl_stmt|;
comment|/* The storage. Not zero char terminated. It is       			   allocated with all other fields.  */
block|}
name|bc_struct
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bc_struct
modifier|*
name|bc_num
typedef|;
end_typedef

begin_comment
comment|/*  Some useful macros and constants. */
end_comment

begin_define
define|#
directive|define
name|CH_VAL
parameter_list|(
name|c
parameter_list|)
value|(c - '0')
end_define

begin_define
define|#
directive|define
name|BCD_CHAR
parameter_list|(
name|d
parameter_list|)
value|(d + '0')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MIN
end_ifdef

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a>b?a:b)
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a>b?b:a)
end_define

begin_define
define|#
directive|define
name|ODD
parameter_list|(
name|a
parameter_list|)
value|(a&1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

