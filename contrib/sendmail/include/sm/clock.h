begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: clock.h,v 1.11 2001/05/14 23:25:37 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  CLOCK.H -- for co-ordinating timed events */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SM_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_SM_CLOCK_H
value|1
end_define

begin_include
include|#
directive|include
file|<sm/signal.h>
end_include

begin_if
if|#
directive|if
name|SM_CONF_SETITIMER
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

begin_comment
comment|/* SM_CONF_SETITIMER */
end_comment

begin_comment
comment|/* **  STRUCT SM_EVENT -- event queue. ** **	Maintained in sorted order. ** **	We store the pid of the process that set this event to insure **	that when we fork we will not take events intended for the parent. */
end_comment

begin_struct
struct|struct
name|sm_event
block|{
if|#
directive|if
name|SM_CONF_SETITIMER
name|struct
name|timeval
name|ev_time
decl_stmt|;
comment|/* time of the call (microseconds) */
else|#
directive|else
comment|/* SM_CONF_SETITIMER */
name|time_t
name|ev_time
decl_stmt|;
comment|/* time of the call (seconds) */
endif|#
directive|endif
comment|/* SM_CONF_SETITIMER */
name|void
argument_list|(
argument|*ev_func
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* function to call */
name|int
name|ev_arg
decl_stmt|;
comment|/* argument to ev_func */
name|pid_t
name|ev_pid
decl_stmt|;
comment|/* pid that set this event */
name|struct
name|sm_event
modifier|*
name|ev_link
decl_stmt|;
comment|/* link to next item */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sm_event
name|SM_EVENT
typedef|;
end_typedef

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sm_clrevent
name|__P
argument_list|(
operator|(
name|SM_EVENT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_clear_events
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_EVENT
modifier|*
name|sm_setevent
name|__P
argument_list|(
operator|(
name|time_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_EVENT
modifier|*
name|sm_seteventm
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_EVENT
modifier|*
name|sm_sigsafe_seteventm
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SIGFUNC_DECL
name|sm_tick
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  SM_SETEVENT -- set an event to happen at a specific time in seconds. ** **	Translates the seconds into millseconds and calls sm_seteventm() **	to get a specific event to happen in the future at a specific time. ** **	Parameters: **		t -- intvl until next event occurs (seconds). **		f -- function to call on event. **		a -- argument to func on event. ** **	Returns: **		result of sm_seteventm(). ** **	Side Effects: **		Any that sm_seteventm() have. */
end_comment

begin_define
define|#
directive|define
name|sm_setevent
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|sm_seteventm((int)((t) * 1000), (f), (a))
end_define

begin_define
define|#
directive|define
name|sm_sigsafe_setevent
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|sm_sigsafe_seteventm((int)((t) * 1000), (f), (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SM_CLOCK_H */
end_comment

end_unit

