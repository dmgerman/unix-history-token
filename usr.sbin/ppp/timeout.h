begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIMEOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_TIMEOUT_H_
end_define

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

begin_define
define|#
directive|define
name|TICKUNIT
value|100000
end_define

begin_comment
comment|/* Unit in usec */
end_comment

begin_define
define|#
directive|define
name|SECTICKS
value|(1000000/TICKUNIT)
end_define

begin_struct
struct|struct
name|pppTimer
block|{
name|int
name|state
decl_stmt|;
name|u_long
name|rest
decl_stmt|;
comment|/* Ticks to expire */
name|u_long
name|load
decl_stmt|;
comment|/* Initial load value */
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
comment|/* Function called when timer is expired */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* Argument passed to timeout function */
name|struct
name|pppTimer
modifier|*
name|next
decl_stmt|;
comment|/* Link to next timer */
name|struct
name|pppTimer
modifier|*
name|enext
decl_stmt|;
comment|/* Link to next expired timer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIMER_STOPPED
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|TIMER_EXPIRED
value|2
end_define

begin_decl_stmt
name|struct
name|pppTimer
modifier|*
name|TimerList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|StartTimer
name|__P
argument_list|(
operator|(
expr|struct
name|pppTimer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|StopTimer
name|__P
argument_list|(
operator|(
expr|struct
name|pppTimer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|TimerService
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
name|void
name|InitTimerService
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
name|void
name|TermTimerService
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
name|void
name|StartIdleTimer
name|__P
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

begin_comment
comment|/* _TIMEOUT_H_ */
end_comment

end_unit

