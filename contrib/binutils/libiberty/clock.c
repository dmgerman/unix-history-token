begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ANSI-compatible clock function.    Copyright (C) 1994, 1995, 1999 Free Software Foundation, Inc.  This file is part of the libiberty library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

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

begin_comment
comment|/* FIXME: should be able to declare as clock_t. */
end_comment

begin_function
name|long
name|clock
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
ifdef|#
directive|ifdef
name|VMS
struct|struct
block|{
name|int
name|proc_user_time
decl_stmt|;
name|int
name|proc_system_time
decl_stmt|;
name|int
name|child_user_time
decl_stmt|;
name|int
name|child_system_time
decl_stmt|;
block|}
name|vms_times
struct|;
name|times
argument_list|(
operator|&
name|vms_times
argument_list|)
expr_stmt|;
return|return
operator|(
name|vms_times
operator|.
name|proc_user_time
operator|+
name|vms_times
operator|.
name|proc_system_time
operator|)
operator|*
literal|10000
return|;
else|#
directive|else
comment|/* A fallback, if nothing else available. */
return|return
literal|0
return|;
endif|#
directive|endif
comment|/* VMS */
endif|#
directive|endif
comment|/* HAVE_TIMES */
endif|#
directive|endif
comment|/* HAVE_GETRUSAGE */
block|}
end_function

end_unit

