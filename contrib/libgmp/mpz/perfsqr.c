begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mpz_perfect_square_p(arg) -- Return non-zero if ARG is a perfect square,    zero otherwise.  Copyright (C) 1991, 1993, 1994, 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|"gmp.h"
end_include

begin_include
include|#
directive|include
file|"gmp-impl.h"
end_include

begin_function
name|int
if|#
directive|if
name|__STDC__
name|mpz_perfect_square_p
parameter_list|(
name|mpz_srcptr
name|a
parameter_list|)
else|#
directive|else
function|mpz_perfect_square_p
parameter_list|(
name|a
parameter_list|)
name|mpz_srcptr
name|a
decl_stmt|;
endif|#
directive|endif
block|{
name|mp_size_t
name|asize
init|=
name|a
operator|->
name|_mp_size
decl_stmt|;
comment|/* No negative numbers are perfect squares.  */
if|if
condition|(
name|asize
operator|<
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|mpn_perfect_square_p
argument_list|(
name|a
operator|->
name|_mp_d
argument_list|,
name|asize
argument_list|)
return|;
block|}
end_function

end_unit

