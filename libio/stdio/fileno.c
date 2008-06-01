begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1993, 1995, 1996, 1997 Free Software Foundation, Inc.    This file is part of the GNU IO Library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this library; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.     As a special exception, if you link this library with files    compiled with a GNU compiler to produce an executable, this does    not cause the resulting executable to be covered by the GNU General    Public License.  This exception does not however invalidate any    other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_function
name|int
name|fileno
parameter_list|(
name|fp
parameter_list|)
name|_IO_FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|CHECK_FILE
argument_list|(
name|fp
argument_list|,
name|EOF
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|fp
operator|->
name|_flags
operator|&
name|_IO_IS_FILEBUF
operator|)
condition|)
return|return
name|EOF
return|;
return|return
name|_IO_fileno
argument_list|(
name|fp
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_IO_MTSAFE_IO
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|weak_alias
end_ifdef

begin_comment
comment|/* The fileno implementation for libio does not require locking because    it only accesses once a single variable and this is already atomic    (at least at thread level).  */
end_comment

begin_macro
name|weak_alias
argument_list|(
argument|fileno
argument_list|,
argument|fileno_unlocked
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

