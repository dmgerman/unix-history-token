begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)fixunsdfdi.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_define
define|#
directive|define
name|HIGH_WORD_COEFF
value|(((long long) 1)<< BITS_PER_WORD)
end_define

begin_function
name|long
name|long
name|__fixunsdfdi
parameter_list|(
name|a
parameter_list|)
name|double
name|a
decl_stmt|;
block|{
name|double
name|b
decl_stmt|;
name|unsigned
name|long
name|long
name|v
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|/* Compute high word of result, as a flonum.  */
name|b
operator|=
operator|(
name|a
operator|/
name|HIGH_WORD_COEFF
operator|)
expr_stmt|;
comment|/* Convert that to fixed (but not to long long!),      and shift it into the high word.  */
name|v
operator|=
operator|(
name|unsigned
name|long
name|int
operator|)
name|b
expr_stmt|;
name|v
operator|<<=
name|BITS_PER_WORD
expr_stmt|;
comment|/* Remove high part from the double, leaving the low part as flonum.  */
name|a
operator|-=
operator|(
name|double
operator|)
name|v
expr_stmt|;
comment|/* Convert that to fixed (but not to long long!) and add it in.      Sometimes A comes out negative.  This is significant, since      A has more bits than a long int does.  */
if|if
condition|(
name|a
operator|<
literal|0
condition|)
name|v
operator|-=
call|(
name|unsigned
name|long
name|int
call|)
argument_list|(
operator|-
name|a
argument_list|)
expr_stmt|;
else|else
name|v
operator|+=
operator|(
name|unsigned
name|long
name|int
operator|)
name|a
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

end_unit

