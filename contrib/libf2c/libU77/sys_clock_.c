begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1996, 1998 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|HAVE_SYS_TIMES_H
end_if

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|int
name|G77_system_clock_0
argument_list|(
name|count
argument_list|,
name|count_rate
argument_list|,
name|count_max
argument_list|)
name|integer
modifier|*
name|count
decl_stmt|,
modifier|*
name|count_rate
decl_stmt|,
modifier|*
name|count_max
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|G77_system_clock_0
parameter_list|(
name|integer
modifier|*
name|count
parameter_list|,
name|integer
modifier|*
name|count_rate
parameter_list|,
name|integer
modifier|*
name|count_max
parameter_list|)
endif|#
directive|endif
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TIMES
argument_list|)
name|struct
name|tms
name|buffer
decl_stmt|;
name|unsigned
name|long
name|cnt
decl_stmt|;
if|if
condition|(
name|count_rate
condition|)
block|{
ifdef|#
directive|ifdef
name|_SC_CLK_TCK
operator|*
name|count_rate
operator|=
name|sysconf
argument_list|(
name|_SC_CLK_TCK
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
name|CLOCKS_PER_SECOND
operator|*
name|count_rate
operator|=
name|CLOCKS_PER_SECOND
expr_stmt|;
elif|#
directive|elif
name|defined
name|CLK_TCK
operator|*
name|count_rate
operator|=
name|CLK_TCK
expr_stmt|;
elif|#
directive|elif
name|defined
name|HZ
operator|*
name|count_rate
operator|=
name|HZ
expr_stmt|;
else|#
directive|else
error|#
directive|error
error|Dont know clock tick length
endif|#
directive|endif
block|}
if|if
condition|(
name|count_max
condition|)
comment|/* optional arg present? */
operator|*
name|count_max
operator|=
name|INT_MAX
expr_stmt|;
comment|/* dubious */
name|cnt
operator|=
name|times
argument_list|(
operator|&
name|buffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|cnt
operator|>
call|(
name|unsigned
name|long
call|)
argument_list|(
name|INT_MAX
argument_list|)
condition|)
operator|*
name|count
operator|=
name|INT_MAX
expr_stmt|;
comment|/* also dubious */
else|else
operator|*
name|count
operator|=
name|cnt
expr_stmt|;
return|return
literal|0
return|;
else|#
directive|else
comment|/* ! HAVE_TIMES */
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
endif|#
directive|endif
comment|/* ! HAVE_TIMES */
block|}
end_function

end_unit

