begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_comment
comment|/* We could presumably do much better than the traditional libc    version, though at least the glibc one is reasonable, it seems.    For the sake of the innocent, I'm not sure we should really do    this... */
end_comment

begin_comment
comment|/* Note this is per SunOS -- other s may have no arg. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|integer
name|G77_irand_0
argument_list|(
name|flag
argument_list|)
name|integer
modifier|*
name|flag
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|integer
name|G77_irand_0
parameter_list|(
name|integer
modifier|*
name|flag
parameter_list|)
endif|#
directive|endif
block|{
switch|switch
condition|(
operator|*
name|flag
condition|)
block|{
case|case
literal|0
case|:
break|break;
case|case
literal|1
case|:
name|srand
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Arbitrary choice of initialiser. */
break|break;
default|default:
name|srand
argument_list|(
operator|*
name|flag
argument_list|)
expr_stmt|;
block|}
return|return
name|rand
argument_list|()
return|;
block|}
end_function

end_unit

