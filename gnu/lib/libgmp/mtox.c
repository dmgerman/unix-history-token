begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mtox -- Convert OPERAND to hexadecimal and return a malloc'ed string    with the result of the conversion.  Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with the GNU MP Library; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"mp.h"
end_include

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
name|char
modifier|*
ifdef|#
directive|ifdef
name|__STDC__
name|mtox
parameter_list|(
specifier|const
name|MINT
modifier|*
name|operand
parameter_list|)
else|#
directive|else
function|mtox
parameter_list|(
name|operand
parameter_list|)
specifier|const
name|MINT
modifier|*
name|operand
decl_stmt|;
endif|#
directive|endif
block|{
comment|/* Call MP_GET_STR with a NULL pointer as string argument, so that it      allocates space for the result.  */
return|return
name|_mpz_get_str
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|16
argument_list|,
name|operand
argument_list|)
return|;
block|}
end_function

end_unit

