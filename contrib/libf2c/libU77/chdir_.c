begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995, 1997 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
name|void
name|g_char
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|integer
name|G77_chdir_0
argument_list|(
name|name
argument_list|,
name|Lname
argument_list|)
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lname
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|g_char
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|ftnlen
name|alen
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|integer
name|G77_chdir_0
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|ftnlen
name|Lname
parameter_list|)
endif|#
directive|endif
block|{
name|char
modifier|*
name|buff
decl_stmt|;
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|blast
decl_stmt|;
name|int
name|i
decl_stmt|;
name|buff
operator|=
name|malloc
argument_list|(
name|Lname
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|buff
condition|)
return|return
operator|-
literal|1
return|;
name|g_char
argument_list|(
name|name
argument_list|,
name|Lname
argument_list|,
name|buff
argument_list|)
expr_stmt|;
name|i
operator|=
name|chdir
argument_list|(
name|buff
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|buff
argument_list|)
expr_stmt|;
return|return
name|i
condition|?
name|errno
else|:
literal|0
return|;
block|}
end_function

end_unit

