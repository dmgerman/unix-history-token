begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mpz_scan1(op, startbit) -- Scan for the next set bit, starting at startbit.  Copyright (C) 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
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
name|unsigned
name|long
name|int
if|#
directive|if
name|__STDC__
name|mpz_scan1
parameter_list|(
name|mpz_srcptr
name|u
parameter_list|,
name|unsigned
name|long
name|int
name|starting_bit
parameter_list|)
else|#
directive|else
function|mpz_scan1
parameter_list|(
name|u
parameter_list|,
name|starting_bit
parameter_list|)
name|mpz_srcptr
name|u
decl_stmt|;
name|unsigned
name|long
name|int
name|starting_bit
decl_stmt|;
endif|#
directive|endif
block|{
return|return
name|mpn_scan1
argument_list|(
name|u
operator|->
name|_mp_d
argument_list|,
name|starting_bit
argument_list|)
return|;
block|}
end_function

end_unit

