begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_timer.c,v 3.1 1993/07/06 01:11:29 jbj Exp  * ntp_event.c - event timer support routines  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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

begin_comment
comment|/*  * These routines provide support for the event timer.  The timer is  * implemented by an interrupt routine which sets a flag once every  * 2**EVENT_TIMEOUT seconds (currently 4), and a timer routine which  * is called when the mainline code gets around to seeing the flag.  * The timer routine dispatches the clock adjustment code if its time  * has come, then searches the timer queue for expiries which are  * dispatched to the transmit procedure.  Finally, we call the hourly  * procedure to do cleanup and print a message.  */
end_comment

begin_comment
comment|/*  * Alarm flag.  The mainline code imports this.  */
end_comment

begin_decl_stmt
name|int
name|alarm_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * adjust and hourly counters  */
end_comment

begin_decl_stmt
specifier|static
name|U_LONG
name|adjust_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|U_LONG
name|hourly_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Imported from the leap module.  The leap timer.  */
end_comment

begin_decl_stmt
specifier|extern
name|U_LONG
name|leap_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Statistics counter for the interested.  */
end_comment

begin_decl_stmt
name|U_LONG
name|alarm_overflow
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HOUR
value|(60*60)
end_define

begin_comment
comment|/*  * Current_time holds the number of seconds since we started, in  * increments of 2**EVENT_TIMEOUT seconds.  The timer queue is the  * hash into which we sort timer entries.  */
end_comment

begin_decl_stmt
name|U_LONG
name|current_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|event
name|timerqueue
index|[
name|TIMER_NSLOTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Stats.  Number of overflows and number of calls to transmit().  */
end_comment

begin_decl_stmt
name|U_LONG
name|timer_timereset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U_LONG
name|timer_overflows
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U_LONG
name|timer_xmtcalls
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/*  * init_timer - initialize the timer data structures  */
end_comment

begin_function
name|void
name|init_timer
parameter_list|()
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|struct
name|itimerval
name|itimer
decl_stmt|;
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
operator|(
literal|1
operator|<<
name|CLOCK_ADJ
operator|)
expr_stmt|;
name|hourly_timer
operator|=
name|HOUR
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
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|TIMER_NSLOTS
condition|;
name|i
operator|++
control|)
block|{
comment|/* 		 * Queue pointers should point at themselves.  Event 		 * times must be set to 0 since this is used to 		 * detect the queue end. 		 */
name|timerqueue
index|[
name|i
index|]
operator|.
name|next
operator|=
operator|&
name|timerqueue
index|[
name|i
index|]
expr_stmt|;
name|timerqueue
index|[
name|i
index|]
operator|.
name|prev
operator|=
operator|&
name|timerqueue
index|[
name|i
index|]
expr_stmt|;
name|timerqueue
index|[
name|i
index|]
operator|.
name|event_time
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 	 * Set up the alarm interrupt.  The first comes 2**EVENT_TIMEOUT 	 * seconds from now and they continue on every 2**EVENT_TIMEOUT 	 * seconds. 	 */
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
block|}
end_function

begin_comment
comment|/*  * timer - dispatch anyone who needs to be  */
end_comment

begin_function
name|void
name|timer
parameter_list|()
block|{
specifier|register
name|struct
name|event
modifier|*
name|ev
decl_stmt|;
specifier|register
name|struct
name|event
modifier|*
name|tq
decl_stmt|;
name|current_time
operator|+=
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
expr_stmt|;
comment|/* 	 * Adjustment timeout first 	 */
if|if
condition|(
name|adjust_timer
operator|<=
name|current_time
condition|)
block|{
name|adjust_timer
operator|+=
operator|(
literal|1
operator|<<
name|CLOCK_ADJ
operator|)
expr_stmt|;
name|adj_host_clock
argument_list|()
expr_stmt|;
block|}
comment|/* 	 * Leap timer next. 	 */
if|if
condition|(
name|leap_timer
operator|!=
literal|0
operator|&&
name|leap_timer
operator|<=
name|current_time
condition|)
name|leap_process
argument_list|()
expr_stmt|;
comment|/* 	 * Now dispatch any peers whose event timer has expired. 	 */
name|tq
operator|=
operator|&
name|timerqueue
index|[
name|TIMER_SLOT
argument_list|(
name|current_time
argument_list|)
index|]
expr_stmt|;
name|ev
operator|=
name|tq
operator|->
name|next
expr_stmt|;
while|while
condition|(
name|ev
operator|->
name|event_time
operator|!=
literal|0
operator|&&
name|ev
operator|->
name|event_time
operator|<
operator|(
name|current_time
operator|+
operator|(
literal|1
operator|<<
name|EVENT_TIMEOUT
operator|)
operator|)
condition|)
block|{
name|tq
operator|->
name|next
operator|=
name|ev
operator|->
name|next
expr_stmt|;
name|tq
operator|->
name|next
operator|->
name|prev
operator|=
name|tq
expr_stmt|;
name|ev
operator|->
name|prev
operator|=
name|ev
operator|->
name|next
operator|=
literal|0
expr_stmt|;
name|timer_xmtcalls
operator|++
expr_stmt|;
name|ev
operator|->
name|event_handler
argument_list|(
name|ev
operator|->
name|peer
argument_list|)
expr_stmt|;
name|ev
operator|=
name|tq
operator|->
name|next
expr_stmt|;
block|}
comment|/* 	 * Finally, call the hourly routine 	 */
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

begin_comment
comment|/*  * alarming - tell the world we've been alarmed  */
end_comment

begin_function
specifier|static
name|RETSIGTYPE
name|alarming
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
specifier|extern
name|int
name|initializing
decl_stmt|;
comment|/* from main line code */
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
block|}
end_function

begin_comment
comment|/*  * timer_clr_stats - clear timer module stat counters  */
end_comment

begin_function
name|void
name|timer_clr_stats
parameter_list|()
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

