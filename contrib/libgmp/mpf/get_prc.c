begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mpf_get_prec(x) -- Return the precision in bits of x.  Copyright (C) 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
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
name|mpf_get_prec
parameter_list|(
name|mpf_srcptr
name|x
parameter_list|)
else|#
directive|else
function|mpf_get_prec
parameter_list|(
name|x
parameter_list|)
name|mpf_srcptr
name|x
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|unsigned
name|long
name|int
operator|)
name|x
operator|->
name|_mp_prec
operator|*
name|BITS_PER_MP_LIMB
operator|-
name|BITS_PER_MP_LIMB
return|;
block|}
end_function

end_unit

