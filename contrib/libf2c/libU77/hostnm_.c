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
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* for ENOSYS */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|integer
name|G77_hostnm_0
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|ftnlen
name|Lname
parameter_list|)
block|{
name|int
name|ret
decl_stmt|,
name|i
decl_stmt|;
if|#
directive|if
name|HAVE_GETHOSTNAME
name|ret
operator|=
name|gethostname
argument_list|(
name|name
argument_list|,
name|Lname
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
block|{
comment|/* Pad with blanks (assuming gethostname will make an error            return if it can't fit in the null). */
for|for
control|(
name|i
operator|=
name|strlen
argument_list|(
name|name
argument_list|)
init|;
name|i
operator|<
name|Lname
condition|;
name|i
operator|++
control|)
name|name
index|[
name|i
index|]
operator|=
literal|' '
expr_stmt|;
block|}
return|return
name|ret
return|;
else|#
directive|else
return|return
name|errno
operator|=
name|ENOSYS
return|;
endif|#
directive|endif
block|}
end_function

end_unit

