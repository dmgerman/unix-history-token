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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Subroutine */
end_comment

begin_decl_stmt
name|int
name|G77_itime_0
argument_list|(
name|tarray
argument_list|)
name|integer
name|tarray
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Subroutine */
end_comment

begin_function
name|int
name|G77_itime_0
parameter_list|(
name|integer
name|tarray
index|[
literal|3
index|]
parameter_list|)
endif|#
directive|endif
block|{
name|struct
name|tm
modifier|*
name|lt
decl_stmt|;
name|time_t
name|tim
decl_stmt|;
name|tim
operator|=
name|time
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|lt
operator|=
name|localtime
argument_list|(
operator|&
name|tim
argument_list|)
expr_stmt|;
name|tarray
index|[
literal|0
index|]
operator|=
name|lt
operator|->
name|tm_hour
expr_stmt|;
name|tarray
index|[
literal|1
index|]
operator|=
name|lt
operator|->
name|tm_min
expr_stmt|;
name|tarray
index|[
literal|2
index|]
operator|=
name|lt
operator|->
name|tm_sec
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

