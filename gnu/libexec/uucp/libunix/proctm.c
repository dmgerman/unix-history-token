begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* proctm.c    Get the time spent in the process.     Copyright (C) 1992, 1993 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIMITS_H
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prefer gettimeofday to ftime to times.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_GETTIMEOFDAY
operator|||
name|HAVE_FTIME
end_if

begin_undef
undef|#
directive|undef
name|HAVE_TIMES
end_undef

begin_define
define|#
directive|define
name|HAVE_TIMES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_GETTIMEOFDAY
end_if

begin_undef
undef|#
directive|undef
name|HAVE_FTIME
end_undef

begin_define
define|#
directive|define
name|HAVE_FTIME
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_TIME_H
operator|&&
operator|(
name|TIME_WITH_SYS_TIME
operator|||
operator|!
name|HAVE_GETTIMEOFDAY
operator|)
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_GETTIMEOFDAY
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_FTIME
end_if

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_TIMES
end_if

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

begin_if
if|#
directive|if
name|TIMES_DECLARATION_OK
end_if

begin_comment
comment|/* We use a macro to protect this because times really returns clock_t    and on some systems, such as Ultrix 4.0, clock_t is int.  We don't    leave it out entirely because on some systems, such as System III,    the declaration is necessary for correct compilation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|times
end_ifndef

begin_function_decl
specifier|extern
name|long
name|times
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIMES_DECLARATION_OK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SC_CLK_TCK
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SC_CLK_TCK
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_SC_CLK_TCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIMES_TICK may have been set in policy.h, or we may be able to get    it using sysconf.  If neither is the case, try to find a useful    definition from the system header files.  */
end_comment

begin_if
if|#
directive|if
name|TIMES_TICK
operator|==
literal|0
operator|&&
operator|(
operator|!
name|HAVE_SYSCONF
operator|||
operator|!
name|HAVE_SC_CLK_TCK
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|CLK_TCK
end_ifdef

begin_undef
undef|#
directive|undef
name|TIMES_TICK
end_undef

begin_define
define|#
directive|define
name|TIMES_TICK
value|CLK_TCK
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (CLK_TCK) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HZ
end_ifdef

begin_undef
undef|#
directive|undef
name|TIMES_TICK
end_undef

begin_define
define|#
directive|define
name|TIMES_TICK
value|HZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (HZ) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (CLK_TCK) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIMES_TICK == 0&& (! HAVE_SYSCONF || ! HAVE_SC_CLK_TCK) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TIMES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|time
end_ifndef

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYSCONF
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|sysconf
end_ifndef

begin_function_decl
specifier|extern
name|long
name|sysconf
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the time in seconds and microseconds; this need only work    within the process when called from the system independent code.    It is also called by ixsysdep_time.  */
end_comment

begin_function
name|long
name|ixsysdep_process_time
parameter_list|(
name|pimicros
parameter_list|)
name|long
modifier|*
name|pimicros
decl_stmt|;
block|{
if|#
directive|if
name|HAVE_GETTIMEOFDAY
name|struct
name|timeval
name|stime
decl_stmt|;
name|struct
name|timezone
name|stz
decl_stmt|;
operator|(
name|void
operator|)
name|gettimeofday
argument_list|(
operator|&
name|stime
argument_list|,
operator|&
name|stz
argument_list|)
expr_stmt|;
if|if
condition|(
name|pimicros
operator|!=
name|NULL
condition|)
operator|*
name|pimicros
operator|=
operator|(
name|long
operator|)
name|stime
operator|.
name|tv_usec
expr_stmt|;
return|return
operator|(
name|long
operator|)
name|stime
operator|.
name|tv_sec
return|;
endif|#
directive|endif
comment|/* HAVE_GETTIMEOFDAY */
if|#
directive|if
name|HAVE_FTIME
specifier|static
name|boolean
name|fbad
decl_stmt|;
if|if
condition|(
operator|!
name|fbad
condition|)
block|{
name|struct
name|timeb
name|stime
decl_stmt|;
specifier|static
name|struct
name|timeb
name|slast
decl_stmt|;
operator|(
name|void
operator|)
name|ftime
argument_list|(
operator|&
name|stime
argument_list|)
expr_stmt|;
comment|/* On some systems, such as SCO 3.2.2, ftime can go backwards in 	 time.  If we detect this, we switch to using time.  */
if|if
condition|(
name|slast
operator|.
name|time
operator|!=
literal|0
operator|&&
operator|(
name|stime
operator|.
name|time
operator|<
name|slast
operator|.
name|time
operator|||
operator|(
name|stime
operator|.
name|time
operator|==
name|slast
operator|.
name|time
operator|&&
name|stime
operator|.
name|millitm
operator|<
name|slast
operator|.
name|millitm
operator|)
operator|)
condition|)
name|fbad
operator|=
name|TRUE
expr_stmt|;
else|else
block|{
name|slast
operator|=
name|stime
expr_stmt|;
if|if
condition|(
name|pimicros
operator|!=
name|NULL
condition|)
operator|*
name|pimicros
operator|=
operator|(
name|long
operator|)
name|stime
operator|.
name|millitm
operator|*
operator|(
name|long
operator|)
literal|1000
expr_stmt|;
return|return
operator|(
name|long
operator|)
name|stime
operator|.
name|time
return|;
block|}
block|}
if|if
condition|(
name|pimicros
operator|!=
name|NULL
condition|)
operator|*
name|pimicros
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|long
operator|)
name|time
argument_list|(
operator|(
name|time_t
operator|*
operator|)
name|NULL
argument_list|)
return|;
endif|#
directive|endif
comment|/* HAVE_FTIME */
if|#
directive|if
name|HAVE_TIMES
name|struct
name|tms
name|s
decl_stmt|;
name|long
name|i
decl_stmt|;
specifier|static
name|int
name|itick
decl_stmt|;
if|if
condition|(
name|itick
operator|==
literal|0
condition|)
block|{
if|#
directive|if
name|TIMES_TICK
operator|==
literal|0
if|#
directive|if
name|HAVE_SYSCONF
operator|&&
name|HAVE_SC_CLK_TCK
name|itick
operator|=
operator|(
name|int
operator|)
name|sysconf
argument_list|(
name|_SC_CLK_TCK
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ! HAVE_SYSCONF || ! HAVE_SC_CLK_TCK */
specifier|const
name|char
modifier|*
name|z
decl_stmt|;
name|z
operator|=
name|getenv
argument_list|(
literal|"HZ"
argument_list|)
expr_stmt|;
if|if
condition|(
name|z
operator|!=
name|NULL
condition|)
name|itick
operator|=
operator|(
name|int
operator|)
name|strtol
argument_list|(
name|z
argument_list|,
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|/* If we really couldn't get anything, just use 60.  */
if|if
condition|(
name|itick
operator|==
literal|0
condition|)
name|itick
operator|=
literal|60
expr_stmt|;
endif|#
directive|endif
comment|/* ! HAVE_SYSCONF || ! HAVE_SC_CLK_TCK */
else|#
directive|else
comment|/* TIMES_TICK != 0 */
name|itick
operator|=
name|TIMES_TICK
expr_stmt|;
endif|#
directive|endif
comment|/* TIMES_TICK == 0 */
block|}
name|i
operator|=
operator|(
name|long
operator|)
name|times
argument_list|(
operator|&
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|pimicros
operator|!=
name|NULL
condition|)
operator|*
name|pimicros
operator|=
operator|(
name|i
operator|%
operator|(
name|long
operator|)
name|itick
operator|)
operator|*
operator|(
operator|(
name|long
operator|)
literal|1000000
operator|/
operator|(
name|long
operator|)
name|itick
operator|)
expr_stmt|;
return|return
name|i
operator|/
operator|(
name|long
operator|)
name|itick
return|;
endif|#
directive|endif
comment|/* HAVE_TIMES */
if|#
directive|if
operator|!
name|HAVE_GETTIMEOFDAY
operator|&&
operator|!
name|HAVE_FTIME
operator|&&
operator|!
name|HAVE_TIMES
if|if
condition|(
name|pimicros
operator|!=
name|NULL
condition|)
operator|*
name|pimicros
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|long
operator|)
name|time
argument_list|(
operator|(
name|time_t
operator|*
operator|)
name|NULL
argument_list|)
return|;
endif|#
directive|endif
comment|/* ! HAVE_GETTIMEOFDAY&& ! HAVE_FTIME&& ! HAVE_TIMES  */
block|}
end_function

end_unit

