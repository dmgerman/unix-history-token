begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_timer.c - event timer support routines  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_IO_COMPLETION_PORT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ntp_iocompletionport.h"
end_include

begin_include
include|#
directive|include
file|"ntp_timer.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUBKEY
end_ifdef

begin_include
include|#
directive|include
file|"ntp_crypto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUBKEY */
end_comment

begin_comment
comment|/*  * These routines provide support for the event timer.	The timer is  * implemented by an interrupt routine which sets a flag once every  * 2**EVENT_TIMEOUT seconds (currently 4), and a timer routine which  * is called when the mainline code gets around to seeing the flag.  * The timer routine dispatches the clock adjustment code if its time  * has come, then searches the timer queue for expiries which are  * dispatched to the transmit procedure.  Finally, we call the hourly  * procedure to do cleanup and print a message.  */
end_comment

begin_comment
comment|/*  * Alarm flag.	The mainline code imports this.  */
end_comment

begin_decl_stmt
specifier|volatile
name|int
name|alarm_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The counters  */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|adjust_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* second timer */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|keys_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minute timer */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|hourly_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hour timer */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|huffpuff_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* huff-n'-puff timer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTOKEY
end_ifdef

begin_decl_stmt
specifier|static
name|u_long
name|revoke_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keys revoke timer */
end_comment

begin_decl_stmt
name|u_long
name|sys_revoke
init|=
literal|1
operator|<<
name|KEY_REVOKE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keys revoke timeout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOKEY */
end_comment

begin_comment
comment|/*  * Statistics counter for the interested.  */
end_comment

begin_decl_stmt
specifier|volatile
name|u_long
name|alarm_overflow
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MINUTE
value|60
end_define

begin_define
define|#
directive|define
name|HOUR
value|(60*60)
end_define

begin_decl_stmt
name|u_long
name|current_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Stats.  Number of overflows and number of calls to transmit().  */
end_comment

begin_decl_stmt
name|u_long
name|timer_timereset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|timer_overflows
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|timer_xmtcalls
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|int
name|vmstimer
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time for next timer AST */
end_comment

begin_decl_stmt
specifier|static
name|int
name|vmsinc
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timer increment */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_if
if|#
directive|if
name|defined
name|SYS_WINNT
end_if

begin_decl_stmt
specifier|static
name|HANDLE
name|WaitableTimerHandle
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|RETSIGTYPE
name|alarming
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_comment
comment|/*  * init_timer - initialize the timer data structures  */
end_comment

begin_function
name|void
name|init_timer
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
if|#
directive|if
operator|!
name|defined
name|SYS_WINNT
operator|||
name|defined
argument_list|(
name|SYS_CYGWIN32
argument_list|)
ifndef|#
directive|ifndef
name|HAVE_TIMER_SETTIME
name|struct
name|itimerval
name|itimer
decl_stmt|;
else|#
directive|else
specifier|static
name|timer_t
name|ntpd_timerid
decl_stmt|;
comment|/* should be global if we ever want */
comment|/* to kill timer without rebooting ... */
name|struct
name|itimerspec
name|itimer
decl_stmt|;
endif|#
directive|endif
comment|/* HAVE_TIMER_SETTIME */
else|#
directive|else
comment|/* SYS_WINNT */
name|HANDLE
name|hToken
decl_stmt|;
name|TOKEN_PRIVILEGES
name|tkp
decl_stmt|;
endif|#
directive|endif
comment|/* SYS_WINNT */
endif|#
directive|endif
comment|/* !VMS */
comment|/* 	 * Initialize... 	 */
name|alarm_flag
operator|=
literal|0
expr_stmt|;
name|alarm_overflow
operator|=
literal|0
expr_stmt|;
name|adjust_timer
operator|=
literal|1
expr_stmt|;
name|hourly_timer
operator|=
name|HOUR
expr_stmt|;
name|huffpuff_timer
operator|=
literal|0
expr_stmt|;
name|current_time
operator|=
literal|0
expr_stmt|;
name|timer_overflows
operator|=
literal|0
expr_stmt|;
name|timer_xmtcalls
operator|=
literal|0
expr_stmt|;
name|timer_timereset
operator|=
literal|0
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
comment|/* 	 * Set up the alarm interrupt.	The first comes 2**EVENT_TIMEOUT 	 * seconds from now and they continue on every 2**EVENT_TIMEOUT 	 * seconds. 	 */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TIMER_CREATE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_TIMER_SETTIME
argument_list|)
if|if
condition|(
name|timer_create
argument_list|(
name|CLOCK_REALTIME
argument_list|,
name|NULL
argument_list|,
operator|&
name|ntpd_timerid
argument_list|)
operator|==
ifdef|#
directive|ifdef
name|SYS_VXWORKS
name|ERROR
else|#
directive|else
operator|-
literal|1
endif|#
directive|endif
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"timer create FAILED\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|signal_no_reset
argument_list|(
name|SIGALRM
argument_list|,
name|alarming
argument_list|)
expr_stmt|;
name|itimer
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|itimer
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
expr_stmt|;
name|itimer
operator|.
name|it_interval
operator|.
name|tv_nsec
operator|=
name|itimer
operator|.
name|it_value
operator|.
name|tv_nsec
operator|=
literal|0
expr_stmt|;
name|timer_settime
argument_list|(
name|ntpd_timerid
argument_list|,
literal|0
comment|/*!TIMER_ABSTIME*/
argument_list|,
operator|&
name|itimer
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|signal_no_reset
argument_list|(
name|SIGALRM
argument_list|,
name|alarming
argument_list|)
expr_stmt|;
name|itimer
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|itimer
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
expr_stmt|;
name|itimer
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
name|itimer
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|itimer
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
comment|/* VMS */
name|vmsinc
index|[
literal|0
index|]
operator|=
literal|10000000
expr_stmt|;
comment|/* 1 sec */
name|vmsinc
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|lib$emul
argument_list|(
operator|&
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
argument_list|,
operator|&
name|vmsinc
argument_list|,
operator|&
literal|0
argument_list|,
operator|&
name|vmsinc
argument_list|)
expr_stmt|;
name|sys$gettim
argument_list|(
operator|&
name|vmstimer
argument_list|)
expr_stmt|;
comment|/* that's "now" as abstime */
name|lib$addx
argument_list|(
operator|&
name|vmsinc
argument_list|,
operator|&
name|vmstimer
argument_list|,
operator|&
name|vmstimer
argument_list|)
expr_stmt|;
name|sys$setimr
argument_list|(
literal|0
argument_list|,
operator|&
name|vmstimer
argument_list|,
name|alarming
argument_list|,
name|alarming
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
else|#
directive|else
comment|/* SYS_WINNT */
name|_tzset
argument_list|()
expr_stmt|;
comment|/* 	 * Get privileges needed for fiddling with the clock 	 */
comment|/* get the current process token handle */
if|if
condition|(
operator|!
name|OpenProcessToken
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|,
name|TOKEN_ADJUST_PRIVILEGES
operator||
name|TOKEN_QUERY
argument_list|,
operator|&
name|hToken
argument_list|)
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"OpenProcessToken failed: %m"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* get the LUID for system-time privilege. */
name|LookupPrivilegeValue
argument_list|(
name|NULL
argument_list|,
name|SE_SYSTEMTIME_NAME
argument_list|,
operator|&
name|tkp
operator|.
name|Privileges
index|[
literal|0
index|]
operator|.
name|Luid
argument_list|)
expr_stmt|;
name|tkp
operator|.
name|PrivilegeCount
operator|=
literal|1
expr_stmt|;
comment|/* one privilege to set */
name|tkp
operator|.
name|Privileges
index|[
literal|0
index|]
operator|.
name|Attributes
operator|=
name|SE_PRIVILEGE_ENABLED
expr_stmt|;
comment|/* get set-time privilege for this process. */
name|AdjustTokenPrivileges
argument_list|(
name|hToken
argument_list|,
name|FALSE
argument_list|,
operator|&
name|tkp
argument_list|,
literal|0
argument_list|,
operator|(
name|PTOKEN_PRIVILEGES
operator|)
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* cannot test return value of AdjustTokenPrivileges. */
if|if
condition|(
name|GetLastError
argument_list|()
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"AdjustTokenPrivileges failed: %m"
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Set up timer interrupts for every 2**EVENT_TIMEOUT seconds 	 * Under Windows/NT,  	 */
name|WaitableTimerHandle
operator|=
name|CreateWaitableTimer
argument_list|(
name|NULL
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|WaitableTimerHandle
operator|==
name|NULL
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"CreateWaitableTimer failed: %m"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|DWORD
name|Period
init|=
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
operator|*
literal|1000
decl_stmt|;
name|LARGE_INTEGER
name|DueTime
decl_stmt|;
name|DueTime
operator|.
name|QuadPart
operator|=
name|Period
operator|*
literal|10000i
literal|64
expr_stmt|;
if|if
condition|(
operator|!
name|SetWaitableTimer
argument_list|(
name|WaitableTimerHandle
argument_list|,
operator|&
name|DueTime
argument_list|,
name|Period
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|FALSE
argument_list|)
operator|!=
name|NO_ERROR
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"SetWaitableTimer failed: %m"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* SYS_WINNT */
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
end_if

begin_function
specifier|extern
name|HANDLE
name|get_timer_handle
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|WaitableTimerHandle
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * timer - dispatch anyone who needs to be  */
end_comment

begin_function
name|void
name|timer
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|struct
name|peer
modifier|*
name|peer
decl_stmt|,
modifier|*
name|next_peer
decl_stmt|;
name|u_int
name|n
decl_stmt|;
name|current_time
operator|+=
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
expr_stmt|;
comment|/* 	 * Adjustment timeout first. 	 */
if|if
condition|(
name|adjust_timer
operator|<=
name|current_time
condition|)
block|{
name|adjust_timer
operator|+=
literal|1
expr_stmt|;
name|adj_host_clock
argument_list|()
expr_stmt|;
block|}
comment|/* 	 * Now dispatch any peers whose event timer has expired. Be careful 	 * here, since the peer structure might go away as the result of 	 * the call. 	 */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|HASH_SIZE
condition|;
name|n
operator|++
control|)
block|{
for|for
control|(
name|peer
operator|=
name|peer_hash
index|[
name|n
index|]
init|;
name|peer
operator|!=
literal|0
condition|;
name|peer
operator|=
name|next_peer
control|)
block|{
name|next_peer
operator|=
name|peer
operator|->
name|next
expr_stmt|;
if|if
condition|(
name|peer
operator|->
name|action
operator|&&
name|peer
operator|->
name|nextaction
operator|<=
name|current_time
condition|)
name|peer
operator|->
name|action
argument_list|(
name|peer
argument_list|)
expr_stmt|;
if|if
condition|(
name|peer
operator|->
name|nextdate
operator|<=
name|current_time
condition|)
block|{
ifdef|#
directive|ifdef
name|REFCLOCK
if|if
condition|(
name|peer
operator|->
name|flags
operator|&
name|FLAG_REFCLOCK
condition|)
name|refclock_transmit
argument_list|(
name|peer
argument_list|)
expr_stmt|;
else|else
name|transmit
argument_list|(
name|peer
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* REFCLOCK */
name|transmit
argument_list|(
name|peer
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* REFCLOCK */
block|}
block|}
block|}
comment|/* 	 * Garbage collect expired keys. 	 */
if|if
condition|(
name|keys_timer
operator|<=
name|current_time
condition|)
block|{
name|keys_timer
operator|+=
name|MINUTE
expr_stmt|;
name|auth_agekeys
argument_list|()
expr_stmt|;
block|}
comment|/* 	 * Huff-n'-puff filter 	 */
if|if
condition|(
name|huffpuff_timer
operator|<=
name|current_time
condition|)
block|{
name|huffpuff_timer
operator|+=
name|HUFFPUFF
expr_stmt|;
name|huffpuff
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/* 	 * Garbage collect old keys and generate new private value 	 */
if|if
condition|(
name|revoke_timer
operator|<=
name|current_time
condition|)
block|{
name|revoke_timer
operator|+=
name|sys_revoke
expr_stmt|;
name|expire_all
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
name|printf
argument_list|(
literal|"key expire: at %lu next %lu\n"
argument_list|,
name|current_time
argument_list|,
name|revoke_timer
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/* 	 * Finally, call the hourly routine. 	 */
if|if
condition|(
name|hourly_timer
operator|<=
name|current_time
condition|)
block|{
name|hourly_timer
operator|+=
name|HOUR
expr_stmt|;
name|hourly_stats
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_comment
comment|/*  * alarming - tell the world we've been alarmed  */
end_comment

begin_function
specifier|static
name|RETSIGTYPE
name|alarming
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
if|if
condition|(
name|initializing
condition|)
return|return;
if|if
condition|(
name|alarm_flag
condition|)
name|alarm_overflow
operator|++
expr_stmt|;
else|else
name|alarm_flag
operator|++
expr_stmt|;
else|#
directive|else
comment|/* VMS AST routine */
if|if
condition|(
operator|!
name|initializing
condition|)
block|{
if|if
condition|(
name|alarm_flag
condition|)
name|alarm_overflow
operator|++
expr_stmt|;
else|else
name|alarm_flag
operator|=
literal|1
expr_stmt|;
comment|/* increment is no good */
block|}
name|lib$addx
argument_list|(
operator|&
name|vmsinc
argument_list|,
operator|&
name|vmstimer
argument_list|,
operator|&
name|vmstimer
argument_list|)
expr_stmt|;
name|sys$setimr
argument_list|(
literal|0
argument_list|,
operator|&
name|vmstimer
argument_list|,
name|alarming
argument_list|,
name|alarming
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_comment
comment|/*  * timer_clr_stats - clear timer module stat counters  */
end_comment

begin_function
name|void
name|timer_clr_stats
parameter_list|(
name|void
parameter_list|)
block|{
name|timer_overflows
operator|=
literal|0
expr_stmt|;
name|timer_xmtcalls
operator|=
literal|0
expr_stmt|;
name|timer_timereset
operator|=
name|current_time
expr_stmt|;
block|}
end_function

end_unit

