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

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_comment
comment|/* Subroutine */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|void
name|G77_vxttime_0
argument_list|(
name|chtime
argument_list|,
name|Lchtime
argument_list|)
name|char
name|chtime
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lchtime
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|G77_vxttime_0
parameter_list|(
name|char
name|chtime
index|[
literal|8
index|]
parameter_list|,
specifier|const
name|ftnlen
name|Lchtime
parameter_list|)
endif|#
directive|endif
block|{
name|time_t
name|tim
decl_stmt|;
name|char
modifier|*
name|ctim
decl_stmt|;
name|tim
operator|=
name|time
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|ctim
operator|=
name|ctime
argument_list|(
operator|&
name|tim
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|chtime
argument_list|,
name|ctim
operator|+
literal|11
argument_list|,
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

