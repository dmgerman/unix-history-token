begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * ITU-T Q.2110 - Subroutines  *  */
end_comment

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop_misc.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop_var.h>
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
comment|/*  * Conditionally Clear Transmission Queues  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|q2110_clear_xmit
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * Only clear queues if 'Clear Buffers' == No 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_NOCLRBUF
condition|)
name|sscop_xmit_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Initialize Data Transfer State Variables  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|q2110_init_state
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * Initialize for entry into Data Transfer Ready state 	 */
name|sop
operator|->
name|so_send
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_pollsend
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_ack
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_pollack
operator|=
literal|1
expr_stmt|;
name|sop
operator|->
name|so_polldata
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_rcvhigh
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_rcvnext
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Prepare Queues for Data Retrieval  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|q2110_prep_retrieve
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * If 'Clear Buffers' == No, just clear retransmit queue, 	 * else clear all transmission queues 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_NOCLRBUF
condition|)
block|{
name|sop
operator|->
name|so_rexmit_hd
operator|=
name|NULL
expr_stmt|;
name|sop
operator|->
name|so_rexmit_tl
operator|=
name|NULL
expr_stmt|;
block|}
else|else
name|sscop_xmit_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Clear receiver queue 	 */
name|sscop_rcvr_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Prepare Queues for Error Recovery  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|q2110_prep_recovery
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * If 'Clear Buffers' == No, just clear retransmit queue, 	 * else clear all transmission queues 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_NOCLRBUF
condition|)
block|{
name|sop
operator|->
name|so_rexmit_hd
operator|=
name|NULL
expr_stmt|;
name|sop
operator|->
name|so_rexmit_tl
operator|=
name|NULL
expr_stmt|;
block|}
else|else
name|sscop_xmit_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Conditionally Deliver Received Data to User  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|q2110_deliver_data
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * If 'Clear Buffers' == No, give data to user 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_NOCLRBUF
condition|)
block|{
comment|/* 		 * We don't support 'Clear Buffers' == No, so don't bother 		 */
block|}
comment|/* 	 * Clear receiver queue 	 */
name|sscop_rcvr_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Enter Connection Recovery Mode  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|q2110_error_recovery
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * Stop data transfer timers 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_POLL
index|]
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_IDLE
index|]
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_flags
operator|&=
operator|~
name|SOF_KEEPALIVE
expr_stmt|;
comment|/*  	 * Initialize receiver window 	 */
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_rcvmax
argument_list|,
name|sop
operator|->
name|so_parm
operator|.
name|sp_rcvwin
argument_list|)
expr_stmt|;
comment|/* 	 * Send first ER PDU 	 */
name|sop
operator|->
name|so_connctl
operator|=
literal|1
expr_stmt|;
name|SEQ_INCR
argument_list|(
name|sop
operator|->
name|so_sendconn
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sscop_send_er
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Set retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timecc
expr_stmt|;
comment|/* 	 * Clear out appropriate queues 	 */
name|q2110_prep_recovery
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Wait for ERAK 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_OUTRECOV
expr_stmt|;
return|return;
block|}
end_function

end_unit

