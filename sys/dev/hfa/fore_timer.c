begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Timer processing  *  */
end_comment

begin_include
include|#
directive|include
file|<dev/hfa/fore_include.h>
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

begin_comment
comment|/*  * Process a Fore timer tick  *   * This function is called every FORE_TIME_TICK seconds in order to update  * all of the unit watchdog timers.    *  * Called at splnet.  *  * Arguments:  *	tip	pointer to fore timer control block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|fore_timeout
parameter_list|(
name|tip
parameter_list|)
name|struct
name|atm_time
modifier|*
name|tip
decl_stmt|;
block|{
name|Fore_unit
modifier|*
name|fup
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* 	 * Schedule next timeout 	 */
name|atm_timeout
argument_list|(
operator|&
name|fore_timer
argument_list|,
name|ATM_HZ
operator|*
name|FORE_TIME_TICK
argument_list|,
name|fore_timeout
argument_list|)
expr_stmt|;
comment|/* 	 * Run through all units, updating each active timer. 	 * If an expired timer is found, notify that unit. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|fore_nunits
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|fup
operator|=
name|fore_units
index|[
name|i
index|]
operator|)
operator|==
name|NULL
condition|)
continue|continue;
comment|/* 		 * Decrement timer, if it's active 		 */
if|if
condition|(
name|fup
operator|->
name|fu_timer
operator|&&
operator|(
operator|--
name|fup
operator|->
name|fu_timer
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* 			 * Timeout occurred - go check out the queues 			 */
name|ATM_DEBUG0
argument_list|(
literal|"fore_timeout\n"
argument_list|)
expr_stmt|;
name|DEVICE_LOCK
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|)
name|fup
argument_list|)
expr_stmt|;
name|fore_watchdog
argument_list|(
name|fup
argument_list|)
expr_stmt|;
name|DEVICE_UNLOCK
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|)
name|fup
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

