begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Interrupt processing  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_cm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_aali.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_slave.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_stats.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_var.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_comment
comment|/*  * Polling interrupt routine  *   * Polling interrupts are handled by calling all interrupt service   * routines for a given level until someone claims to have "handled" the   * interrupt.  *  * Called at interrupt level.  *  * Arguments:  *	none  *  * Returns:  *	1 		an interrupt has been serviced  *	0		no interrupts serviced  *  */
end_comment

begin_function
name|int
name|fore_poll
parameter_list|()
block|{
name|int
name|serviced
init|=
literal|0
decl_stmt|;
name|int
name|unit
decl_stmt|;
comment|/* 	 * See if any of our devices are interrupting 	 */
for|for
control|(
name|unit
operator|=
literal|0
init|;
name|unit
operator|<
name|fore_nunits
condition|;
name|unit
operator|++
control|)
block|{
name|Fore_unit
modifier|*
name|fup
init|=
name|fore_units
index|[
name|unit
index|]
decl_stmt|;
if|if
condition|(
name|fup
operator|==
name|NULL
condition|)
continue|continue;
name|serviced
operator|+=
name|fore_intr
argument_list|(
operator|(
name|void
operator|*
operator|)
name|fup
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Indicate if we handled an interrupt 	 */
return|return
operator|(
name|serviced
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(sun) */
end_comment

begin_comment
comment|/*  * Device interrupt routine  *   * Called at interrupt level.  *  * Arguments:  *	arg		pointer to device unit structure  *  * Returns:  *	1 		device interrupt was serviced  *	0		no interrupts serviced  *  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|<=
literal|199306
operator|)
operator|)
end_if

begin_function
name|int
else|#
directive|else
name|void
endif|#
directive|endif
name|fore_intr
parameter_list|(
name|arg
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|Fore_unit
modifier|*
name|fup
init|=
name|arg
decl_stmt|;
name|Aali
modifier|*
name|aap
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|<=
literal|199306
operator|)
operator|)
name|int
name|serviced
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* 	 * Try to prevent stuff happening after we've paniced 	 */
if|if
condition|(
name|panicstr
condition|)
block|{
goto|goto
name|done
goto|;
block|}
comment|/* 	 * Get to the microcode shared memory interface 	 */
if|if
condition|(
operator|(
name|aap
operator|=
name|fup
operator|->
name|fu_aali
operator|)
operator|==
name|NULL
condition|)
goto|goto
name|done
goto|;
comment|/* 	 * Has this card issued an interrupt?? 	 */
if|if
condition|(
operator|*
name|fup
operator|->
name|fu_psr
condition|)
block|{
comment|/* 		 * Indicate that we've serviced an interrupt.  		 */
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|<=
literal|199306
operator|)
operator|)
name|serviced
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* 		 * Clear the device interrupt 		 */
switch|switch
condition|(
name|fup
operator|->
name|fu_config
operator|.
name|ac_device
condition|)
block|{
case|case
name|DEV_FORE_PCA200E
case|:
name|PCA200E_HCR_SET
argument_list|(
operator|*
name|fup
operator|->
name|fu_ctlreg
argument_list|,
name|PCA200E_CLR_HBUS_INT
argument_list|)
expr_stmt|;
break|break;
block|}
name|aap
operator|->
name|aali_intr_sent
operator|=
name|CP_WRITE
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* 		 * Reset the watchdog timer 		 */
name|fup
operator|->
name|fu_timer
operator|=
name|FORE_WATCHDOG
expr_stmt|;
comment|/* 		 * Device initialization handled separately 		 */
if|if
condition|(
operator|(
name|fup
operator|->
name|fu_flags
operator|&
name|CUF_INITED
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* 			 * We're just initializing device now, so see if 			 * the initialization command has completed 			 */
if|if
condition|(
name|CP_READ
argument_list|(
name|aap
operator|->
name|aali_init
operator|.
name|init_status
argument_list|)
operator|&
name|QSTAT_COMPLETED
condition|)
name|fore_initialize_complete
argument_list|(
name|fup
argument_list|)
expr_stmt|;
comment|/* 			 * If we're still not inited, none of the host 			 * queues are setup yet 			 */
if|if
condition|(
operator|(
name|fup
operator|->
name|fu_flags
operator|&
name|CUF_INITED
operator|)
operator|==
literal|0
condition|)
goto|goto
name|done
goto|;
block|}
comment|/* 		 * Drain the queues of completed work 		 */
name|fore_cmd_drain
argument_list|(
name|fup
argument_list|)
expr_stmt|;
name|fore_recv_drain
argument_list|(
name|fup
argument_list|)
expr_stmt|;
name|fore_xmit_drain
argument_list|(
name|fup
argument_list|)
expr_stmt|;
comment|/* 		 * Supply more buffers to the CP 		 */
name|fore_buf_supply
argument_list|(
name|fup
argument_list|)
expr_stmt|;
block|}
name|done
label|:
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|<=
literal|199306
operator|)
operator|)
return|return
operator|(
name|serviced
operator|)
return|;
else|#
directive|else
return|return;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Watchdog timeout routine  *   * Called when we haven't heard from the card in a while.  Just in case  * we missed an interrupt, we'll drain the queues and try to resupply the  * CP with more receive buffers.  If the CP is partially wedged, hopefully  * this will be enough to get it going again.  *  * Called with interrupts locked out.  *  * Arguments:  *	fup		pointer to device unit structure  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|fore_watchdog
parameter_list|(
name|fup
parameter_list|)
name|Fore_unit
modifier|*
name|fup
decl_stmt|;
block|{
comment|/* 	 * Try to prevent stuff happening after we've paniced 	 */
if|if
condition|(
name|panicstr
condition|)
block|{
return|return;
block|}
comment|/* 	 * Reset the watchdog timer 	 */
name|fup
operator|->
name|fu_timer
operator|=
name|FORE_WATCHDOG
expr_stmt|;
comment|/* 	 * If the device is initialized, nudge it (wink, wink) 	 */
if|if
condition|(
name|fup
operator|->
name|fu_flags
operator|&
name|CUF_INITED
condition|)
block|{
comment|/* 		 * Drain the queues of completed work 		 */
name|fore_cmd_drain
argument_list|(
name|fup
argument_list|)
expr_stmt|;
name|fore_recv_drain
argument_list|(
name|fup
argument_list|)
expr_stmt|;
name|fore_xmit_drain
argument_list|(
name|fup
argument_list|)
expr_stmt|;
comment|/* 		 * Supply more buffers to the CP 		 */
name|fore_buf_supply
argument_list|(
name|fup
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

end_unit

