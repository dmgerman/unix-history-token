begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Timing variables for measuring compiler performance.    Copyright (C) 2000 Free Software Foundation, Inc.    Contributed by Alex Samuel<samuel@codesourcery.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"intl.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMES_H
end_ifdef

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
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_CLOCK_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|clock_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_TMS
end_ifndef

begin_struct
struct|struct
name|tms
block|{
name|clock_t
name|tms_utime
decl_stmt|;
name|clock_t
name|tms_stime
decl_stmt|;
name|clock_t
name|tms_cutime
decl_stmt|;
name|clock_t
name|tms_cstime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|HAVE_DECL_GETRUSAGE
operator|&&
operator|!
name|HAVE_DECL_GETRUSAGE
end_if

begin_decl_stmt
specifier|extern
name|int
name|getrusage
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|rusage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|HAVE_DECL_TIMES
operator|&&
operator|!
name|HAVE_DECL_TIMES
end_if

begin_decl_stmt
specifier|extern
name|clock_t
name|times
name|PARAMS
argument_list|(
operator|(
expr|struct
name|tms
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|HAVE_DECL_CLOCK
operator|&&
operator|!
name|HAVE_DECL_CLOCK
end_if

begin_decl_stmt
specifier|extern
name|clock_t
name|clock
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RUSAGE_SELF
end_ifndef

begin_define
define|#
directive|define
name|RUSAGE_SELF
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Calculation of scale factor to convert ticks to microseconds.    We mustn't use CLOCKS_PER_SEC except with clock().  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYSCONF
operator|&&
name|defined
name|_SC_CLK_TCK
end_if

begin_define
define|#
directive|define
name|TICKS_PER_SECOND
value|sysconf (_SC_CLK_TCK)
end_define

begin_comment
comment|/* POSIX 1003.1-1996 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CLK_TCK
end_ifdef

begin_define
define|#
directive|define
name|TICKS_PER_SECOND
value|CLK_TCK
end_define

begin_comment
comment|/* POSIX 1003.1-1988; obsolescent */
end_comment

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
name|TICKS_PER_SECOND
value|HZ
end_define

begin_comment
comment|/* traditional UNIX */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TICKS_PER_SECOND
value|100
end_define

begin_comment
comment|/* often the correct value */
end_comment

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
comment|/* Prefer times to getrusage to clock (each gives successively less    information).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIMES
end_ifdef

begin_define
define|#
directive|define
name|USE_TIMES
end_define

begin_define
define|#
directive|define
name|HAVE_USER_TIME
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME
end_define

begin_define
define|#
directive|define
name|HAVE_WALL_TIME
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETRUSAGE
end_ifdef

begin_define
define|#
directive|define
name|USE_GETRUSAGE
end_define

begin_define
define|#
directive|define
name|HAVE_USER_TIME
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CLOCK
end_ifdef

begin_define
define|#
directive|define
name|USE_CLOCK
end_define

begin_define
define|#
directive|define
name|HAVE_USER_TIME
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
comment|/* libc is very likely to have snuck a call to sysconf() into one of    the underlying constants, and that can be very slow, so we have to    precompute them.  Whose wonderful idea was it to make all those    _constants_ variable at run time, anyway?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_TIMES
end_ifdef

begin_decl_stmt
specifier|static
name|float
name|ticks_to_msec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TICKS_TO_MSEC
value|(1 / (float)TICKS_PER_SECOND)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_CLOCK
end_ifdef

begin_decl_stmt
specifier|static
name|float
name|clocks_to_msec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CLOCKS_TO_MSEC
value|(1 / (float)CLOCKS_PER_SEC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"timevar.h"
end_include

begin_comment
comment|/* See timevar.h for an explanation of timing variables.  */
end_comment

begin_comment
comment|/* This macro evaluates to non-zero if timing variables are enabled.  */
end_comment

begin_define
define|#
directive|define
name|TIMEVAR_ENABLE
value|(time_report)
end_define

begin_comment
comment|/* A timing variable.  */
end_comment

begin_struct
struct|struct
name|timevar_def
block|{
comment|/* Elapsed time for this variable.  */
name|struct
name|timevar_time_def
name|elapsed
decl_stmt|;
comment|/* If this variable is timed independently of the timing stack,      using timevar_start, this contains the start time.  */
name|struct
name|timevar_time_def
name|start_time
decl_stmt|;
comment|/* The name of this timing variable.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Non-zero if this timing variable is running as a standalone      timer.  */
name|unsigned
name|standalone
range|:
literal|1
decl_stmt|;
comment|/* Non-zero if this timing variable was ever started or pushed onto      the timing stack.  */
name|unsigned
name|used
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An element on the timing stack.  Elapsed time is attributed to the    topmost timing variable on the stack.  */
end_comment

begin_struct
struct|struct
name|timevar_stack_def
block|{
comment|/* The timing variable at this stack level.  */
name|struct
name|timevar_def
modifier|*
name|timevar
decl_stmt|;
comment|/* The next lower timing variable context in the stack.  */
name|struct
name|timevar_stack_def
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Declared timing variables.  Constructed from the contents of    timevar.def.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timevar_def
name|timevars
index|[
name|TIMEVAR_LAST
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The top of the timing stack.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timevar_stack_def
modifier|*
name|stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of unused (i.e. allocated and subsequently popped)    timevar_stack_def instances.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timevar_stack_def
modifier|*
name|unused_stack_instances
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The time at which the topmost element on the timing stack was    pushed.  Time elapsed since then is attributed to the topmost    element.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|timevar_time_def
name|start_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|get_time
name|PARAMS
argument_list|(
operator|(
expr|struct
name|timevar_time_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|timevar_accumulate
name|PARAMS
argument_list|(
operator|(
expr|struct
name|timevar_time_def
operator|*
operator|,
expr|struct
name|timevar_time_def
operator|*
operator|,
expr|struct
name|timevar_time_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fill the current times into TIME.  The definition of this function    also defines any or all of the HAVE_USER_TIME, HAVE_SYS_TIME, and    HAVA_WALL_TIME macros.  */
end_comment

begin_function
specifier|static
name|void
name|get_time
parameter_list|(
name|now
parameter_list|)
name|struct
name|timevar_time_def
modifier|*
name|now
decl_stmt|;
block|{
name|now
operator|->
name|user
operator|=
literal|0
expr_stmt|;
name|now
operator|->
name|sys
operator|=
literal|0
expr_stmt|;
name|now
operator|->
name|wall
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|TIMEVAR_ENABLE
condition|)
return|return;
block|{
ifdef|#
directive|ifdef
name|USE_TIMES
name|struct
name|tms
name|tms
decl_stmt|;
name|now
operator|->
name|wall
operator|=
name|times
argument_list|(
operator|&
name|tms
argument_list|)
operator|*
name|ticks_to_msec
expr_stmt|;
name|now
operator|->
name|user
operator|=
name|tms
operator|.
name|tms_utime
operator|*
name|ticks_to_msec
expr_stmt|;
name|now
operator|->
name|sys
operator|=
name|tms
operator|.
name|tms_stime
operator|*
name|ticks_to_msec
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_GETRUSAGE
name|struct
name|rusage
name|rusage
decl_stmt|;
name|getrusage
argument_list|(
name|RUSAGE_SELF
argument_list|,
operator|&
name|rusage
argument_list|)
expr_stmt|;
name|now
operator|->
name|user
operator|=
name|rusage
operator|.
name|ru_utime
operator|.
name|tv_sec
operator|+
name|rusage
operator|.
name|ru_utime
operator|.
name|tv_usec
operator|*
literal|1e-6
expr_stmt|;
name|now
operator|->
name|sys
operator|=
name|rusage
operator|.
name|ru_stime
operator|.
name|tv_sec
operator|+
name|rusage
operator|.
name|ru_stime
operator|.
name|tv_usec
operator|*
literal|1e-6
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_CLOCK
name|now
operator|->
name|user
operator|=
name|clock
argument_list|()
operator|*
name|clocks_to_msec
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function

begin_comment
comment|/* Add the difference between STOP_TIME and START_TIME to TIMER.  */
end_comment

begin_function
specifier|static
name|void
name|timevar_accumulate
parameter_list|(
name|timer
parameter_list|,
name|start_time
parameter_list|,
name|stop_time
parameter_list|)
name|struct
name|timevar_time_def
modifier|*
name|timer
decl_stmt|;
name|struct
name|timevar_time_def
modifier|*
name|start_time
decl_stmt|;
name|struct
name|timevar_time_def
modifier|*
name|stop_time
decl_stmt|;
block|{
name|timer
operator|->
name|user
operator|+=
name|stop_time
operator|->
name|user
operator|-
name|start_time
operator|->
name|user
expr_stmt|;
name|timer
operator|->
name|sys
operator|+=
name|stop_time
operator|->
name|sys
operator|-
name|start_time
operator|->
name|sys
expr_stmt|;
name|timer
operator|->
name|wall
operator|+=
name|stop_time
operator|->
name|wall
operator|-
name|start_time
operator|->
name|wall
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Initialize timing variables.  */
end_comment

begin_function
name|void
name|init_timevar
parameter_list|()
block|{
if|if
condition|(
operator|!
name|TIMEVAR_ENABLE
condition|)
return|return;
comment|/* Zero all elapsed times.  */
name|memset
argument_list|(
operator|(
name|void
operator|*
operator|)
name|timevars
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|timevars
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Initialize the names of timing variables.  */
define|#
directive|define
name|DEFTIMEVAR
parameter_list|(
name|identifier__
parameter_list|,
name|name__
parameter_list|)
define|\
value|timevars[identifier__].name = name__;
include|#
directive|include
file|"timevar.def"
undef|#
directive|undef
name|DEFTIMEVAR
ifdef|#
directive|ifdef
name|USE_TIMES
name|ticks_to_msec
operator|=
name|TICKS_TO_MSEC
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_CLOCK
name|clocks_to_msec
operator|=
name|CLOCKS_TO_MSEC
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Push TIMEVAR onto the timing stack.  No further elapsed time is    attributed to the previous topmost timing variable on the stack;    subsequent elapsed time is attributed to TIMEVAR, until it is    popped or another element is pushed on top.      TIMEVAR cannot be running as a standalone timer.  */
end_comment

begin_function
name|void
name|timevar_push
parameter_list|(
name|timevar
parameter_list|)
name|timevar_id_t
name|timevar
decl_stmt|;
block|{
name|struct
name|timevar_def
modifier|*
name|tv
init|=
operator|&
name|timevars
index|[
name|timevar
index|]
decl_stmt|;
name|struct
name|timevar_stack_def
modifier|*
name|context
decl_stmt|;
name|struct
name|timevar_time_def
name|now
decl_stmt|;
if|if
condition|(
operator|!
name|TIMEVAR_ENABLE
condition|)
return|return;
comment|/* Mark this timing variable as used.  */
name|tv
operator|->
name|used
operator|=
literal|1
expr_stmt|;
comment|/* Can't push a standalone timer.  */
if|if
condition|(
name|tv
operator|->
name|standalone
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|/* What time is it?  */
name|get_time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* If the stack isn't empty, attribute the current elapsed time to      the old topmost element.  */
if|if
condition|(
name|stack
condition|)
name|timevar_accumulate
argument_list|(
operator|&
name|stack
operator|->
name|timevar
operator|->
name|elapsed
argument_list|,
operator|&
name|start_time
argument_list|,
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* Reset the start time; from now on, time is attributed to      TIMEVAR.  */
name|start_time
operator|=
name|now
expr_stmt|;
comment|/* See if we have a previously-allocated stack instance.  If so,      take it off the list.  If not, malloc a new one.  */
if|if
condition|(
name|unused_stack_instances
operator|!=
name|NULL
condition|)
block|{
name|context
operator|=
name|unused_stack_instances
expr_stmt|;
name|unused_stack_instances
operator|=
name|unused_stack_instances
operator|->
name|next
expr_stmt|;
block|}
else|else
name|context
operator|=
operator|(
expr|struct
name|timevar_stack_def
operator|*
operator|)
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|timevar_stack_def
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Fill it in and put it on the stack.  */
name|context
operator|->
name|timevar
operator|=
name|tv
expr_stmt|;
name|context
operator|->
name|next
operator|=
name|stack
expr_stmt|;
name|stack
operator|=
name|context
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Pop the topmost timing variable element off the timing stack.  The    popped variable must be TIMEVAR.  Elapsed time since the that    element was pushed on, or since it was last exposed on top of the    stack when the element above it was popped off, is credited to that    timing variable.  */
end_comment

begin_function
name|void
name|timevar_pop
parameter_list|(
name|timevar
parameter_list|)
name|timevar_id_t
name|timevar
decl_stmt|;
block|{
name|struct
name|timevar_time_def
name|now
decl_stmt|;
name|struct
name|timevar_stack_def
modifier|*
name|popped
init|=
name|stack
decl_stmt|;
if|if
condition|(
operator|!
name|TIMEVAR_ENABLE
condition|)
return|return;
if|if
condition|(
operator|&
name|timevars
index|[
name|timevar
index|]
operator|!=
name|stack
operator|->
name|timevar
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|/* What time is it?  */
name|get_time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* Attribute the elapsed time to the element we're popping.  */
name|timevar_accumulate
argument_list|(
operator|&
name|popped
operator|->
name|timevar
operator|->
name|elapsed
argument_list|,
operator|&
name|start_time
argument_list|,
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* Reset the start time; from now on, time is attributed to the      element just exposed on the stack.  */
name|start_time
operator|=
name|now
expr_stmt|;
comment|/* Take the item off the stack.  */
name|stack
operator|=
name|stack
operator|->
name|next
expr_stmt|;
comment|/* Don't delete the stack element; instead, add it to the list of      unused elements for later use.  */
name|popped
operator|->
name|next
operator|=
name|unused_stack_instances
expr_stmt|;
name|unused_stack_instances
operator|=
name|popped
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Start timing TIMEVAR independently of the timing stack.  Elapsed    time until timevar_stop is called for the same timing variable is    attributed to TIMEVAR.  */
end_comment

begin_function
name|void
name|timevar_start
parameter_list|(
name|timevar
parameter_list|)
name|timevar_id_t
name|timevar
decl_stmt|;
block|{
name|struct
name|timevar_def
modifier|*
name|tv
init|=
operator|&
name|timevars
index|[
name|timevar
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|TIMEVAR_ENABLE
condition|)
return|return;
comment|/* Mark this timing variable as used.  */
name|tv
operator|->
name|used
operator|=
literal|1
expr_stmt|;
comment|/* Don't allow the same timing variable to be started more than      once.  */
if|if
condition|(
name|tv
operator|->
name|standalone
condition|)
name|abort
argument_list|()
expr_stmt|;
name|tv
operator|->
name|standalone
operator|=
literal|1
expr_stmt|;
name|get_time
argument_list|(
operator|&
name|tv
operator|->
name|start_time
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Stop timing TIMEVAR.  Time elapsed since timevar_start was called    is attributed to it.  */
end_comment

begin_function
name|void
name|timevar_stop
parameter_list|(
name|timevar
parameter_list|)
name|timevar_id_t
name|timevar
decl_stmt|;
block|{
name|struct
name|timevar_def
modifier|*
name|tv
init|=
operator|&
name|timevars
index|[
name|timevar
index|]
decl_stmt|;
name|struct
name|timevar_time_def
name|now
decl_stmt|;
if|if
condition|(
operator|!
name|TIMEVAR_ENABLE
condition|)
return|return;
comment|/* TIMEVAR must have been started via timevar_start.  */
if|if
condition|(
operator|!
name|tv
operator|->
name|standalone
condition|)
name|abort
argument_list|()
expr_stmt|;
name|get_time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
name|timevar_accumulate
argument_list|(
operator|&
name|tv
operator|->
name|elapsed
argument_list|,
operator|&
name|tv
operator|->
name|start_time
argument_list|,
operator|&
name|now
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Fill the elapsed time for TIMEVAR into ELAPSED.  Returns    update-to-date information even if TIMEVAR is currently running.  */
end_comment

begin_function
name|void
name|timevar_get
parameter_list|(
name|timevar
parameter_list|,
name|elapsed
parameter_list|)
name|timevar_id_t
name|timevar
decl_stmt|;
name|struct
name|timevar_time_def
modifier|*
name|elapsed
decl_stmt|;
block|{
name|struct
name|timevar_def
modifier|*
name|tv
init|=
operator|&
name|timevars
index|[
name|timevar
index|]
decl_stmt|;
name|struct
name|timevar_time_def
name|now
decl_stmt|;
operator|*
name|elapsed
operator|=
name|tv
operator|->
name|elapsed
expr_stmt|;
comment|/* Is TIMEVAR currently running as a standalone timer?  */
if|if
condition|(
name|tv
operator|->
name|standalone
condition|)
block|{
name|get_time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
name|timevar_accumulate
argument_list|(
name|elapsed
argument_list|,
operator|&
name|tv
operator|->
name|start_time
argument_list|,
operator|&
name|now
argument_list|)
expr_stmt|;
block|}
comment|/* Or is TIMEVAR at the top of the timer stack?  */
elseif|else
if|if
condition|(
name|stack
operator|->
name|timevar
operator|==
name|tv
condition|)
block|{
name|get_time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
name|timevar_accumulate
argument_list|(
name|elapsed
argument_list|,
operator|&
name|start_time
argument_list|,
operator|&
name|now
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Summarize timing variables to FP.  The timing variable TV_TOTAL has    a special meaning -- it's considered to be the total elapsed time,    for normalizing the others, and is displayed last.  */
end_comment

begin_function
name|void
name|timevar_print
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
comment|/* Only print stuff if we have some sort of time information.  */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_USER_TIME
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_SYS_TIME
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_WALL_TIME
argument_list|)
name|unsigned
name|int
comment|/* timevar_id_t */
name|id
decl_stmt|;
name|struct
name|timevar_time_def
modifier|*
name|total
init|=
operator|&
name|timevars
index|[
name|TV_TOTAL
index|]
operator|.
name|elapsed
decl_stmt|;
name|struct
name|timevar_time_def
name|now
decl_stmt|;
if|if
condition|(
operator|!
name|TIMEVAR_ENABLE
condition|)
return|return;
comment|/* Update timing information in case we're calling this from GDB.  */
if|if
condition|(
name|fp
operator|==
literal|0
condition|)
name|fp
operator|=
name|stderr
expr_stmt|;
comment|/* What time is it?  */
name|get_time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* If the stack isn't empty, attribute the current elapsed time to      the old topmost element.  */
if|if
condition|(
name|stack
condition|)
name|timevar_accumulate
argument_list|(
operator|&
name|stack
operator|->
name|timevar
operator|->
name|elapsed
argument_list|,
operator|&
name|start_time
argument_list|,
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* Reset the start time; from now on, time is attributed to      TIMEVAR.  */
name|start_time
operator|=
name|now
expr_stmt|;
name|fputs
argument_list|(
name|_
argument_list|(
literal|"\nExecution times (seconds)\n"
argument_list|)
argument_list|,
name|fp
argument_list|)
expr_stmt|;
for|for
control|(
name|id
operator|=
literal|0
init|;
name|id
operator|<
operator|(
name|unsigned
name|int
operator|)
name|TIMEVAR_LAST
condition|;
operator|++
name|id
control|)
block|{
name|struct
name|timevar_def
modifier|*
name|tv
init|=
operator|&
name|timevars
index|[
operator|(
name|timevar_id_t
operator|)
name|id
index|]
decl_stmt|;
specifier|const
name|float
name|tiny
init|=
literal|5e-3
decl_stmt|;
comment|/* Don't print the total execution time here; that goes at the 	 end.  */
if|if
condition|(
operator|(
name|timevar_id_t
operator|)
name|id
operator|==
name|TV_TOTAL
condition|)
continue|continue;
comment|/* Don't print timing variables that were never used.  */
if|if
condition|(
operator|!
name|tv
operator|->
name|used
condition|)
continue|continue;
comment|/* Don't print timing variables if we're going to get a row of          zeroes.  */
if|if
condition|(
name|tv
operator|->
name|elapsed
operator|.
name|user
operator|<
name|tiny
operator|&&
name|tv
operator|->
name|elapsed
operator|.
name|sys
operator|<
name|tiny
operator|&&
name|tv
operator|->
name|elapsed
operator|.
name|wall
operator|<
name|tiny
condition|)
continue|continue;
comment|/* The timing variable name.  */
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|" %-22s:"
argument_list|,
name|tv
operator|->
name|name
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_USER_TIME
comment|/* Print user-mode time for this process.  */
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%7.2f (%2.0f%%) usr"
argument_list|,
name|tv
operator|->
name|elapsed
operator|.
name|user
argument_list|,
operator|(
name|total
operator|->
name|user
operator|==
literal|0
condition|?
literal|0
else|:
name|tv
operator|->
name|elapsed
operator|.
name|user
operator|/
name|total
operator|->
name|user
operator|)
operator|*
literal|100
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_USER_TIME */
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME
comment|/* Print system-mode time for this process.  */
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%7.2f (%2.0f%%) sys"
argument_list|,
name|tv
operator|->
name|elapsed
operator|.
name|sys
argument_list|,
operator|(
name|total
operator|->
name|sys
operator|==
literal|0
condition|?
literal|0
else|:
name|tv
operator|->
name|elapsed
operator|.
name|sys
operator|/
name|total
operator|->
name|sys
operator|)
operator|*
literal|100
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SYS_TIME */
ifdef|#
directive|ifdef
name|HAVE_WALL_TIME
comment|/* Print wall clock time elapsed.  */
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%7.2f (%2.0f%%) wall"
argument_list|,
name|tv
operator|->
name|elapsed
operator|.
name|wall
argument_list|,
operator|(
name|total
operator|->
name|wall
operator|==
literal|0
condition|?
literal|0
else|:
name|tv
operator|->
name|elapsed
operator|.
name|wall
operator|/
name|total
operator|->
name|wall
operator|)
operator|*
literal|100
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_WALL_TIME */
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|fp
argument_list|)
expr_stmt|;
block|}
comment|/* Print total time.  */
name|fputs
argument_list|(
name|_
argument_list|(
literal|" TOTAL                 :"
argument_list|)
argument_list|,
name|fp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_USER_TIME
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%7.2f          "
argument_list|,
name|total
operator|->
name|user
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%7.2f          "
argument_list|,
name|total
operator|->
name|sys
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_WALL_TIME
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%7.2f\n"
argument_list|,
name|total
operator|->
name|wall
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* defined (HAVE_USER_TIME) || defined (HAVE_SYS_TIME)  	  || defined (HAVE_WALL_TIME) */
block|}
end_function

begin_comment
comment|/* Returns time (user + system) used so far by the compiler process,    in microseconds.  */
end_comment

begin_function
name|long
name|get_run_time
parameter_list|()
block|{
name|struct
name|timevar_time_def
name|total_elapsed
decl_stmt|;
name|timevar_get
argument_list|(
name|TV_TOTAL
argument_list|,
operator|&
name|total_elapsed
argument_list|)
expr_stmt|;
return|return
name|total_elapsed
operator|.
name|user
operator|+
name|total_elapsed
operator|.
name|sys
return|;
block|}
end_function

begin_comment
comment|/* Prints a message to stderr stating that time elapsed in STR is    TOTAL (given in microseconds).  */
end_comment

begin_function
name|void
name|print_time
parameter_list|(
name|str
parameter_list|,
name|total
parameter_list|)
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
name|long
name|total
decl_stmt|;
block|{
name|long
name|all_time
init|=
name|get_run_time
argument_list|()
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|_
argument_list|(
literal|"time in %s: %ld.%06ld (%ld%%)\n"
argument_list|)
argument_list|,
name|str
argument_list|,
name|total
operator|/
literal|1000000
argument_list|,
name|total
operator|%
literal|1000000
argument_list|,
name|all_time
operator|==
literal|0
condition|?
literal|0
else|:
call|(
name|long
call|)
argument_list|(
operator|(
operator|(
literal|100.0
operator|*
operator|(
name|double
operator|)
name|total
operator|)
operator|/
operator|(
name|double
operator|)
name|all_time
operator|)
operator|+
literal|.5
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

