begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1999-2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: signal.c,v 8.10.4.4 2000/07/14 06:16:57 msk Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_if
if|#
directive|if
name|_FFR_MILTER
end_if

begin_include
include|#
directive|include
file|"libmilter.h"
end_include

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|smutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|smutex_init
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_init(mp, NULL) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_destroy
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_destroy(mp) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_lock
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_lock(mp) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_unlock
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_unlock(mp) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_trylock
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_trylock(mp) == 0)
end_define

begin_comment
comment|/* ** thread to handle signals */
end_comment

begin_decl_stmt
specifier|static
name|smutex_t
name|M_Mutex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|MilterStop
init|=
name|MILTER_CONT
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  MI_STOP -- return value of MilterStop ** **	Parameters: **		none. ** **	Returns: **		value of MilterStop */
end_comment

begin_function
name|int
name|mi_stop
parameter_list|()
block|{
return|return
name|MilterStop
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  MI_STOP_MILTERS -- set value of MilterStop ** **	Parameters: **		v -- new value for MilterStop. ** **	Returns: **		none. */
end_comment

begin_function
name|void
name|mi_stop_milters
parameter_list|(
name|v
parameter_list|)
name|int
name|v
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|smutex_lock
argument_list|(
operator|&
name|M_Mutex
argument_list|)
expr_stmt|;
if|if
condition|(
name|MilterStop
operator|<
name|v
condition|)
name|MilterStop
operator|=
name|v
expr_stmt|;
operator|(
name|void
operator|)
name|smutex_unlock
argument_list|(
operator|&
name|M_Mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  MI_CLEAN_SIGNALS -- clean up signal handler thread ** **	Parameters: **		none. ** **	Returns: **		none. */
end_comment

begin_function
name|void
name|mi_clean_signals
parameter_list|()
block|{
operator|(
name|void
operator|)
name|smutex_destroy
argument_list|(
operator|&
name|M_Mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  MI_SIGNAL_THREAD -- thread to deal with signals ** **	Parameters: **		name -- name of milter ** **	Returns: **		NULL */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|mi_signal_thread
parameter_list|(
name|name
parameter_list|)
name|void
modifier|*
name|name
decl_stmt|;
block|{
name|int
name|sig
decl_stmt|,
name|errs
decl_stmt|;
name|sigset_t
name|set
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|set
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGTERM
argument_list|)
expr_stmt|;
comment|/* Handle Ctrl-C gracefully for debugging */
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGINT
argument_list|)
expr_stmt|;
name|errs
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|TRUE
condition|)
block|{
name|sig
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|SOLARIS
if|if
condition|(
operator|(
name|sig
operator|=
name|sigwait
argument_list|(
operator|&
name|set
argument_list|)
operator|)
operator|<
literal|0
condition|)
else|#
directive|else
comment|/* SOLARIS */
if|if
condition|(
name|sigwait
argument_list|(
operator|&
name|set
argument_list|,
operator|&
name|sig
argument_list|)
operator|!=
literal|0
condition|)
endif|#
directive|endif
comment|/* SOLARIS */
block|{
name|smi_log
argument_list|(
name|SMI_LOG_ERR
argument_list|,
literal|"%s: sigwait returned error: %s"
argument_list|,
operator|(
name|char
operator|*
operator|)
name|name
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|errs
operator|>
name|MAX_FAILS_T
condition|)
block|{
name|mi_stop_milters
argument_list|(
name|MILTER_ABRT
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
continue|continue;
block|}
name|errs
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|sig
condition|)
block|{
case|case
name|SIGHUP
case|:
case|case
name|SIGTERM
case|:
name|mi_stop_milters
argument_list|(
name|MILTER_STOP
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
case|case
name|SIGINT
case|:
name|mi_stop_milters
argument_list|(
name|MILTER_ABRT
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
default|default:
name|smi_log
argument_list|(
name|SMI_LOG_ERR
argument_list|,
literal|"%s: sigwait returned unmasked signal: %d"
argument_list|,
operator|(
name|char
operator|*
operator|)
name|name
argument_list|,
name|sig
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  MI_SPAWN_SIGNAL_THREAD -- spawn thread to handle signals ** **	Parameters: **		name -- name of milter ** **	Returns: **		MI_SUCCESS/MI_FAILURE */
end_comment

begin_function
specifier|static
name|int
name|mi_spawn_signal_thread
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|sthread_t
name|tid
decl_stmt|;
name|sigset_t
name|set
decl_stmt|;
comment|/* Mask HUP and KILL signals */
name|sigemptyset
argument_list|(
operator|&
name|set
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGTERM
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGINT
argument_list|)
expr_stmt|;
if|if
condition|(
name|pthread_sigmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|set
argument_list|,
name|NULL
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|smi_log
argument_list|(
name|SMI_LOG_ERR
argument_list|,
literal|"%s: Couldn't mask HUP and KILL signals"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|MI_FAILURE
return|;
block|}
if|if
condition|(
name|thread_create
argument_list|(
operator|&
name|tid
argument_list|,
name|mi_signal_thread
argument_list|,
operator|(
name|void
operator|*
operator|)
name|name
argument_list|)
operator|!=
name|MI_SUCCESS
condition|)
block|{
name|smi_log
argument_list|(
name|SMI_LOG_ERR
argument_list|,
literal|"%s: Couldn't start signal thread"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|MI_FAILURE
return|;
block|}
return|return
name|MI_SUCCESS
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  MI_CONTROL_STARTUP -- startup for thread to handle signals ** **	Parameters: **		name -- name of milter ** **	Returns: **		MI_SUCCESS/MI_FAILURE */
end_comment

begin_function
name|int
name|mi_control_startup
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|smutex_init
argument_list|(
operator|&
name|M_Mutex
argument_list|)
condition|)
block|{
name|smi_log
argument_list|(
name|SMI_LOG_ERR
argument_list|,
literal|"%s: Couldn't initialize control pipe mutex"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|MI_FAILURE
return|;
block|}
comment|/* 	**  spawn_signal_thread must happen before other threads are spawned 	**  off so that it can mask the right signals and other threads 	**  will inherit that mask. 	*/
if|if
condition|(
name|mi_spawn_signal_thread
argument_list|(
name|name
argument_list|)
operator|==
name|MI_FAILURE
condition|)
block|{
name|smi_log
argument_list|(
name|SMI_LOG_ERR
argument_list|,
literal|"%s: Couldn't spawn signal thread"
argument_list|,
name|name
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|smutex_destroy
argument_list|(
operator|&
name|M_Mutex
argument_list|)
expr_stmt|;
return|return
name|MI_FAILURE
return|;
block|}
return|return
name|MI_SUCCESS
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_MILTER */
end_comment

end_unit

