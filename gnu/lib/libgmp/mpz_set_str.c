begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mpz_set_str(mp_dest, string, base) -- Convert the \0-terminated    string STRING in base BASE to multiple precision integer in    MP_DEST.  Allow white space in the string.  If BASE == 0 determine    the base in the C standard way, i.e.  0xhh...h means base 16,    0oo...o means base 8, otherwise assume base 10.  Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with the GNU MP Library; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_function
name|int
ifdef|#
directive|ifdef
name|__STDC__
name|mpz_set_str
parameter_list|(
name|MP_INT
modifier|*
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|base
parameter_list|)
else|#
directive|else
function|mpz_set_str
parameter_list|(
name|x
parameter_list|,
name|str
parameter_list|,
name|base
parameter_list|)
name|MP_INT
modifier|*
name|x
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
name|int
name|base
decl_stmt|;
endif|#
directive|endif
block|{
comment|/* Go via _mpz_set_str, as that can be used by BSD compatible functions.  */
return|return
name|_mpz_set_str
argument_list|(
name|x
argument_list|,
name|str
argument_list|,
name|base
argument_list|)
return|;
block|}
end_function

end_unit

