begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * ITU-T Q.SAAL1 - Subroutines  *  */
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
comment|/*  * Re-establish a new SSCOP Connection  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|qsaal1_reestablish
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * Stop polling timers 	 */
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
name|so_flags
operator|&=
operator|~
name|SOF_KEEPALIVE
expr_stmt|;
comment|/* 	 * Note that we're reestablishing a connection 	 */
name|sop
operator|->
name|so_flags
operator||=
name|SOF_REESTAB
expr_stmt|;
comment|/* 	 * Send first BGN PDU 	 */
name|sop
operator|->
name|so_connctl
operator|=
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|sscop_send_bgn
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Reset transmit variables 	 */
name|qsaal1_reset_xmit
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
comment|/* 	 * Wait for BGAK 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_OUTCONN
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Reset connection's transmitter state  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|qsaal1_reset_xmit
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * Drain the transmission queues 	 */
name|sscop_xmit_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Reset transmit variables 	 */
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_send
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_pollsend
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_ack
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_pollack
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sop
operator|->
name|so_state
operator|!=
name|SOS_INCONN
condition|)
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_sendmax
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sop
operator|->
name|so_polldata
operator|=
literal|0
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Reset connection's receiver state  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|qsaal1_reset_rcvr
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * Drain the receiver queues 	 */
name|sscop_rcvr_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Reset transmit variables 	 */
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_rcvnext
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_rcvhigh
argument_list|,
literal|0
argument_list|)
expr_stmt|;
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
return|return;
block|}
end_function

begin_comment
comment|/*  * Clear connection's connection data  *   * Arguments:  *	sop	pointer to sscop connection block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|qsaal1_clear_connection
parameter_list|(
name|sop
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
block|{
comment|/* 	 * Can we clear transmit buffers ?? 	 */
if|if
condition|(
operator|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_NOCLRBUF
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* 		 * Yes, drain the transmission queues 		 */
name|sscop_xmit_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Clear service required flag 	 */
name|sop
operator|->
name|so_flags
operator|&=
operator|~
name|SOF_XMITSRVC
expr_stmt|;
comment|/* 	 * Drain receive queue buffers 	 */
name|sscop_rcvr_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

