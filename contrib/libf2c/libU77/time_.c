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

begin_comment
comment|/* As well as this external function some compilers have an intrinsic    subroutine which fills a character argument (which is the VMS way)    -- caveat emptor. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_expr_stmt
name|longint
name|G77_time_0
argument_list|()
else|#
directive|else
name|longint
name|G77_time_0
argument_list|(
argument|void
argument_list|)
endif|#
directive|endif
block|{
comment|/* There are potential problems with the cast of the time_t here. */
return|return
name|time
argument_list|(
name|NULL
argument_list|)
return|;
block|}
end_expr_stmt

end_unit

