begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return time used so far, in microseconds.    Copyright (C) 1994 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* These should go away when libiberty uses autoconf. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSCONF
end_ifdef

begin_define
define|#
directive|define
name|HAVE_TIMES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETRUSAGE
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYS_PARAM_H
end_ifndef

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

begin_function
name|long
name|get_run_time
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_GETRUSAGE
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
name|HZ
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

