begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)quad.h	5.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* More subroutines needed by GCC output code on some machines.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|(NBBY * sizeof(long))
end_define

begin_comment
comment|/* We need this union to unpack/pack longlongs, since we don't have    any arithmetic yet.  Incoming long long parameters are stored    into the `ll' field, and the unpacked result is read from the struct    longlong.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|long
name|long
name|ll
decl_stmt|;
struct|struct
block|{
name|long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|s
struct|;
block|}
name|long_long
typedef|;
end_typedef

begin_define
define|#
directive|define
name|high
value|val[_QUAD_HIGHWORD]
end_define

begin_define
define|#
directive|define
name|low
value|val[_QUAD_LOWWORD]
end_define

begin_define
define|#
directive|define
name|HIGH
value|_QUAD_HIGHWORD
end_define

begin_define
define|#
directive|define
name|LOW
value|_QUAD_LOWWORD
end_define

begin_comment
comment|/* Internally, long long ints are strings of unsigned shorts in the    order determined by BYTE_ORDER.  */
end_comment

begin_define
define|#
directive|define
name|B
value|0x10000
end_define

begin_define
define|#
directive|define
name|low16
value|(B - 1)
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|big_end
parameter_list|(
name|n
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|little_end
parameter_list|(
name|n
parameter_list|)
value|((n) - 1)
end_define

begin_define
define|#
directive|define
name|next_msd
parameter_list|(
name|i
parameter_list|)
value|((i) - 1)
end_define

begin_define
define|#
directive|define
name|next_lsd
parameter_list|(
name|i
parameter_list|)
value|((i) + 1)
end_define

begin_define
define|#
directive|define
name|is_not_msd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)>= 0)
end_define

begin_define
define|#
directive|define
name|is_not_lsd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)< (n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|big_end
parameter_list|(
name|n
parameter_list|)
value|((n) - 1)
end_define

begin_define
define|#
directive|define
name|little_end
parameter_list|(
name|n
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|next_msd
parameter_list|(
name|i
parameter_list|)
value|((i) + 1)
end_define

begin_define
define|#
directive|define
name|next_lsd
parameter_list|(
name|i
parameter_list|)
value|((i) - 1)
end_define

begin_define
define|#
directive|define
name|is_not_msd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)< (n))
end_define

begin_define
define|#
directive|define
name|is_not_lsd
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)>= 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

