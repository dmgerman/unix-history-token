begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * User Space Library Functions  * ----------------------------  *  * Timer functions  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/queue.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"libatm.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|Harp_timer
modifier|*
name|harp_timer_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|harp_timer_exec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Process a HARP timer tick  *  * This function is called via the SIGALRM signal.  It increments  * harp_timer_exec.  The user should check this flag frequently and  * call timer_proc when it is set.  *  * Arguments:  *	None  *  * Returns:  *	None  *  */
end_comment

begin_function
specifier|static
name|void
name|timer_tick
parameter_list|()
block|{
comment|/* 	 * Bump the timer flag 	 */
name|harp_timer_exec
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Process HARP timers  *  * This function is called after a SIGALRM signal is posted.  It runs  * down the list of timer entries, calling the specified functions  * for any timers that have expired.  *  * Arguments:  *	None  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|timer_proc
parameter_list|()
block|{
name|Harp_timer
modifier|*
name|htp
decl_stmt|;
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
function_decl|;
comment|/* 	 * Reset marks in all timers on the queue 	 */
for|for
control|(
name|htp
operator|=
name|harp_timer_head
init|;
name|htp
condition|;
name|htp
operator|=
name|htp
operator|->
name|ht_next
control|)
block|{
name|htp
operator|->
name|ht_mark
operator|=
operator|-
literal|1
expr_stmt|;
block|}
comment|/* 	 * Run through timer chain decrementing each timer. 	 * If an expired timer is found, take the timer block 	 * off the chain and call the specified function.  A 	 * timer's action can result in other timers being 	 * cancelled (taken off the queue), so every time we 	 * call a user function, we start over from the top of 	 * the list. 	 */
name|timer_cont
label|:
for|for
control|(
name|htp
operator|=
name|harp_timer_head
init|;
name|htp
condition|;
name|htp
operator|=
name|htp
operator|->
name|ht_next
control|)
block|{
comment|/* 		 * Make sure we only process each entry once and 		 * don't process entries that are put on the queue 		 * by user functions we call for this tick 		 */
if|if
condition|(
name|htp
operator|->
name|ht_mark
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* 			 * Decrement the timer and mark that we've 			 * processed the entry 			 */
name|htp
operator|->
name|ht_ticks
operator|-=
name|harp_timer_exec
expr_stmt|;
name|htp
operator|->
name|ht_mark
operator|=
literal|1
expr_stmt|;
comment|/* 			 * Check whether the timer is expired 			 */
if|if
condition|(
name|htp
operator|->
name|ht_ticks
operator|<=
literal|0
condition|)
block|{
comment|/* 				 * Unlink the timer block and call 				 * the user function 				 */
name|f
operator|=
name|htp
operator|->
name|ht_func
expr_stmt|;
name|UNLINK
argument_list|(
name|htp
argument_list|,
name|Harp_timer
argument_list|,
name|harp_timer_head
argument_list|,
name|ht_next
argument_list|)
expr_stmt|;
name|f
argument_list|(
name|htp
argument_list|)
expr_stmt|;
comment|/* 				 * Start over 				 */
goto|goto
name|timer_cont
goto|;
block|}
block|}
block|}
comment|/* 	 * Reset the timer exec flag 	 */
name|harp_timer_exec
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Start the timer  *  * Set up the SIGALRM signal handler and set up the real-time  * timer to tick once per second.  *  * Arguments:  *	None  *  * Returns:  *	0	success  *	errno	reason for failure  *  */
end_comment

begin_function
name|int
name|init_timer
parameter_list|()
block|{
name|int
name|rc
init|=
literal|0
decl_stmt|;
name|struct
name|itimerval
name|timeval
decl_stmt|;
comment|/* 	 * Clear the timer flag 	 */
name|harp_timer_exec
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Set up signal handler 	 */
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|timer_tick
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
return|return
operator|(
name|errno
operator|)
return|;
block|}
comment|/* 	 * Start timer 	 */
name|timeval
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
literal|1
expr_stmt|;
name|timeval
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|timeval
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
literal|1
expr_stmt|;
name|timeval
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|timeval
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|rc
operator|=
name|errno
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|rc
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Block timers from firing  *  * Block the SIGALRM signal.  *  * Arguments:  *	None  *  * Returns:  *	mask	the previous blocked signal mask  *  */
end_comment

begin_function
name|int
name|block_timer
parameter_list|()
block|{
comment|/* 	 * Block the SIGALRM signal 	 */
return|return
operator|(
name|sigblock
argument_list|(
name|sigmask
argument_list|(
name|SIGALRM
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Re-enable timers  *  * Restore the signal mask (presumably one that was returned by  * block_timer).  *  * Arguments:  *	mask	the signal mask to be restored  *  * Returns:  *	mask	the previous blocked signal mask  *  */
end_comment

begin_function
name|void
name|enable_timer
parameter_list|(
name|mask
parameter_list|)
name|int
name|mask
decl_stmt|;
block|{
comment|/* 	 * Set the signal mask 	 */
name|sigsetmask
argument_list|(
name|mask
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

