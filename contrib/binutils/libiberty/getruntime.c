begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return time used so far, in microseconds.    Copyright (C) 1994, 1999 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_comment
comment|/* There are several ways to get elapsed execution time; unfortunately no    single way is available for all host systems, nor are there reliable    ways to find out which way is correct for a given host. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIME_H
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETRUSAGE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_RESOURCE_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIMES
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is a fallback; if wrong, it will likely make obviously wrong    results. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLOCKS_PER_SEC
end_ifndef

begin_define
define|#
directive|define
name|CLOCKS_PER_SEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SC_CLK_TCK
end_ifdef

begin_define
define|#
directive|define
name|GNU_HZ
value|sysconf(_SC_CLK_TCK)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HZ
end_ifdef

begin_define
define|#
directive|define
name|GNU_HZ
value|HZ
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCKS_PER_SEC
end_ifdef

begin_define
define|#
directive|define
name|GNU_HZ
value|CLOCKS_PER_SEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|long
name|get_run_time
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETRUSAGE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_RESOURCE_H
argument_list|)
name|struct
name|rusage
name|rusage
decl_stmt|;
name|getrusage
argument_list|(
literal|0
argument_list|,
operator|&
name|rusage
argument_list|)
expr_stmt|;
return|return
operator|(
name|rusage
operator|.
name|ru_utime
operator|.
name|tv_sec
operator|*
literal|1000000
operator|+
name|rusage
operator|.
name|ru_utime
operator|.
name|tv_usec
operator|+
name|rusage
operator|.
name|ru_stime
operator|.
name|tv_sec
operator|*
literal|1000000
operator|+
name|rusage
operator|.
name|ru_stime
operator|.
name|tv_usec
operator|)
return|;
else|#
directive|else
comment|/* ! HAVE_GETRUSAGE */
ifdef|#
directive|ifdef
name|HAVE_TIMES
name|struct
name|tms
name|tms
decl_stmt|;
name|times
argument_list|(
operator|&
name|tms
argument_list|)
expr_stmt|;
return|return
operator|(
name|tms
operator|.
name|tms_utime
operator|+
name|tms
operator|.
name|tms_stime
operator|)
operator|*
operator|(
literal|1000000
operator|/
name|GNU_HZ
operator|)
return|;
else|#
directive|else
comment|/* ! HAVE_TIMES */
comment|/* Fall back on clock and hope it's correctly implemented. */
specifier|const
name|long
name|clocks_per_sec
init|=
name|CLOCKS_PER_SEC
decl_stmt|;
if|if
condition|(
name|clocks_per_sec
operator|<=
literal|1000000
condition|)
return|return
name|clock
argument_list|()
operator|*
operator|(
literal|1000000
operator|/
name|clocks_per_sec
operator|)
return|;
else|else
return|return
name|clock
argument_list|()
operator|/
name|clocks_per_sec
return|;
endif|#
directive|endif
comment|/* HAVE_TIMES */
endif|#
directive|endif
comment|/* HAVE_GETRUSAGE */
block|}
end_function

end_unit

