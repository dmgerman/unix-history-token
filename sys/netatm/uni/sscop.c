begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * Service Specific Connection Oriented Protocol (SSCOP)  *  */
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
file|<netatm/uni/sscop_pdu.h>
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
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
name|int
name|sscop_vccnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sscop
modifier|*
name|sscop_head
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sscop_stat
name|sscop_stat
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|atm_time
name|sscop_timer
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sp_info
name|sscop_pool
init|=
block|{
literal|"sscop pool"
block|,
comment|/* si_name */
sizeof|sizeof
argument_list|(
expr|struct
name|sscop
argument_list|)
block|,
comment|/* si_blksiz */
literal|5
block|,
comment|/* si_blkcnt */
literal|100
comment|/* si_maxallow */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local functions  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|sscop_inst
name|__P
argument_list|(
operator|(
expr|struct
name|stack_defn
operator|*
operator|*
operator|,
name|Atm_connvc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local variables  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|stack_defn
name|sscop_service
init|=
block|{
name|NULL
block|,
name|SAP_SSCOP
block|,
literal|0
block|,
name|sscop_inst
block|,
name|sscop_lower
block|,
name|sscop_upper
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|t_atm_cause
name|sscop_cause
init|=
block|{
name|T_ATM_ITU_CODING
block|,
name|T_ATM_LOC_USER
block|,
name|T_ATM_CAUSE_TEMPORARY_FAILURE
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_char
name|sscop_maa_log
index|[
name|MAA_ERROR_COUNT
index|]
init|=
block|{
literal|1
block|,
comment|/* A */
literal|1
block|,
comment|/* B */
literal|1
block|,
comment|/* C */
literal|1
block|,
comment|/* D */
literal|1
block|,
comment|/* E */
literal|1
block|,
comment|/* F */
literal|1
block|,
comment|/* G */
literal|1
block|,
comment|/* H */
literal|1
block|,
comment|/* I */
literal|1
block|,
comment|/* J */
literal|1
block|,
comment|/* K */
literal|1
block|,
comment|/* L */
literal|1
block|,
comment|/* M */
literal|0
block|,
comment|/* N */
literal|0
block|,
comment|/* O */
literal|0
block|,
comment|/* P */
literal|1
block|,
comment|/* Q */
literal|1
block|,
comment|/* R */
literal|1
block|,
comment|/* S */
literal|1
block|,
comment|/* T */
literal|1
block|,
comment|/* U */
literal|0
block|,
comment|/* V */
literal|0
block|,
comment|/* W */
literal|0
block|,
comment|/* X */
literal|1
comment|/* INVAL */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialize SSCOP processing  *   * This will be called during module loading.  We will register our stack  * service and wait for someone to talk to us.  *  * Arguments:  *	none  *  * Returns:  *	0 	initialization was successful   *	errno	initialization failed - reason indicated  *  */
end_comment

begin_function
name|int
name|sscop_start
parameter_list|()
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* 	 * Register stack service 	 */
if|if
condition|(
operator|(
name|err
operator|=
name|atm_stack_register
argument_list|(
operator|&
name|sscop_service
argument_list|)
operator|)
operator|!=
literal|0
condition|)
goto|goto
name|done
goto|;
comment|/* 	 * Start up timer 	 */
name|atm_timeout
argument_list|(
operator|&
name|sscop_timer
argument_list|,
name|ATM_HZ
operator|/
name|SSCOP_HZ
argument_list|,
name|sscop_timeout
argument_list|)
expr_stmt|;
name|done
label|:
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Terminate SSCOP processing   *   * This will be called just prior to unloading the module from memory.  All   * signalling instances should have been terminated by now, so we just free  * up all of our resources.  *  * Called at splnet.  *  * Arguments:  *	none  *  * Returns:  *	0 	termination was successful   *	errno	termination failed - reason indicated  *  */
end_comment

begin_function
name|int
name|sscop_stop
parameter_list|()
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* 	 * Any connections still exist?? 	 */
if|if
condition|(
name|sscop_vccnt
condition|)
block|{
comment|/* 		 * Yes, can't stop yet 		 */
return|return
operator|(
name|EBUSY
operator|)
return|;
block|}
comment|/* 	 * Stop our timer 	 */
operator|(
name|void
operator|)
name|atm_untimeout
argument_list|(
operator|&
name|sscop_timer
argument_list|)
expr_stmt|;
comment|/* 	 * Deregister the stack service 	 */
operator|(
name|void
operator|)
name|atm_stack_deregister
argument_list|(
operator|&
name|sscop_service
argument_list|)
expr_stmt|;
comment|/* 	 * Free our storage pools 	 */
name|atm_release_pool
argument_list|(
operator|&
name|sscop_pool
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * SSCOP Stack Instantiation   *   * Called at splnet.  *  * Arguments:  *	ssp	pointer to array of stack definition pointers for connection  *		ssp[0] points to upper layer's stack service definition  *		ssp[1] points to this layer's stack service definition  *		ssp[2] points to lower layer's stack service definition  *	cvp	pointer to connection vcc for this stack  *  * Returns:  *	0 	instantiation successful  *	errno	instantiation failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|sscop_inst
parameter_list|(
name|ssp
parameter_list|,
name|cvp
parameter_list|)
name|struct
name|stack_defn
modifier|*
modifier|*
name|ssp
decl_stmt|;
name|Atm_connvc
modifier|*
name|cvp
decl_stmt|;
block|{
name|struct
name|stack_defn
modifier|*
name|sdp_up
init|=
name|ssp
index|[
literal|0
index|]
decl_stmt|,
modifier|*
name|sdp_me
init|=
name|ssp
index|[
literal|1
index|]
decl_stmt|,
modifier|*
name|sdp_low
init|=
name|ssp
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|err
decl_stmt|;
name|ATM_DEBUG2
argument_list|(
literal|"sscop_inst: ssp=%p, cvp=%p\n"
argument_list|,
name|ssp
argument_list|,
name|cvp
argument_list|)
expr_stmt|;
comment|/* 	 * Validate lower SAP 	 */
if|if
condition|(
operator|(
name|sdp_low
operator|->
name|sd_sap
operator|&
name|SAP_CLASS_MASK
operator|)
operator|!=
name|SAP_CPCS
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* 	 * Allocate our control block 	 */
name|sop
operator|=
operator|(
expr|struct
name|sscop
operator|*
operator|)
name|atm_allocate
argument_list|(
operator|&
name|sscop_pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|sop
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENOMEM
operator|)
return|;
name|sop
operator|->
name|so_state
operator|=
name|SOS_INST
expr_stmt|;
name|sop
operator|->
name|so_connvc
operator|=
name|cvp
expr_stmt|;
name|sop
operator|->
name|so_toku
operator|=
name|sdp_up
operator|->
name|sd_toku
expr_stmt|;
name|sop
operator|->
name|so_upper
operator|=
name|sdp_up
operator|->
name|sd_upper
expr_stmt|;
comment|/* 	 * Store my token into service definition 	 */
name|sdp_me
operator|->
name|sd_toku
operator|=
name|sop
expr_stmt|;
comment|/* 	 * Update and save input buffer headroom 	 */
name|HEADIN
argument_list|(
name|cvp
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pdu_hdr
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* sop->so_headin = cvp->cvc_attr.headin; */
comment|/* 	 * Pass instantiation down the stack 	 */
name|err
operator|=
name|sdp_low
operator|->
name|sd_inst
argument_list|(
name|ssp
operator|+
literal|1
argument_list|,
name|cvp
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* 		 * Lower layer instantiation failed, free our resources 		 */
name|atm_free
argument_list|(
operator|(
name|caddr_t
operator|)
name|sop
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
comment|/* 	 * Link in connection block 	 */
name|LINK2TAIL
argument_list|(
name|sop
argument_list|,
expr|struct
name|sscop
argument_list|,
name|sscop_head
argument_list|,
name|so_next
argument_list|)
expr_stmt|;
name|sscop_vccnt
operator|++
expr_stmt|;
name|sscop_stat
operator|.
name|sos_connects
operator|++
expr_stmt|;
comment|/* 	 * Save and update output buffer headroom 	 */
name|sop
operator|->
name|so_headout
operator|=
name|cvp
operator|->
name|cvc_attr
operator|.
name|headout
expr_stmt|;
name|HEADOUT
argument_list|(
name|cvp
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pdu_hdr
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Save lower layer's interface info 	 */
name|sop
operator|->
name|so_lower
operator|=
name|sdp_low
operator|->
name|sd_lower
expr_stmt|;
name|sop
operator|->
name|so_tokl
operator|=
name|sdp_low
operator|->
name|sd_toku
expr_stmt|;
comment|/* 	 * Initialize version (until INIT received) 	 */
name|sop
operator|->
name|so_vers
operator|=
name|SSCOP_VERS_Q2110
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Report Management Error  *   * Called to report an error to the layer management entity.  *  * Arguments:  *	sop	pointer to sscop control block  *	code	error code  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscop_maa_error
parameter_list|(
name|sop
parameter_list|,
name|code
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|code
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
comment|/* 	 * Validate error code 	 */
if|if
condition|(
operator|(
name|code
operator|<
name|MAA_ERROR_MIN
operator|)
operator|||
operator|(
name|code
operator|>
name|MAA_ERROR_MAX
operator|)
condition|)
name|code
operator|=
name|MAA_ERROR_INVAL
expr_stmt|;
name|i
operator|=
name|code
operator|-
name|MAA_ERROR_MIN
expr_stmt|;
comment|/* 	 * Bump statistics counters 	 */
name|sscop_stat
operator|.
name|sos_maa_error
index|[
name|i
index|]
operator|++
expr_stmt|;
comment|/* 	 * Log error message 	 */
if|if
condition|(
name|sscop_maa_log
index|[
name|i
index|]
operator|!=
literal|0
condition|)
block|{
name|struct
name|vccb
modifier|*
name|vcp
init|=
name|sop
operator|->
name|so_connvc
operator|->
name|cvc_vcc
decl_stmt|;
name|struct
name|atm_pif
modifier|*
name|pip
init|=
name|vcp
operator|->
name|vc_pif
decl_stmt|;
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sscop_maa_error: intf=%s%d vpi=%d vci=%d code=%c state=%d\n"
argument_list|,
name|pip
operator|->
name|pif_name
argument_list|,
name|pip
operator|->
name|pif_unit
argument_list|,
name|vcp
operator|->
name|vc_vpi
argument_list|,
name|vcp
operator|->
name|vc_vci
argument_list|,
name|code
argument_list|,
name|sop
operator|->
name|so_state
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Abort an SSCOP connection  *   * Called when an unrecoverable or "should never happen" error occurs.  * We log a message, send an END PDU to our peer and request the signalling  * manager to abort the connection.  *  * Arguments:  *	sop	pointer to sscop control block  *	msg	pointer to error message  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscop_abort
parameter_list|(
name|sop
parameter_list|,
name|msg
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|char
modifier|*
name|msg
decl_stmt|;
block|{
name|Atm_connvc
modifier|*
name|cvp
init|=
name|sop
operator|->
name|so_connvc
decl_stmt|;
comment|/* 	 * Log and count error 	 */
name|log
argument_list|(
name|LOG_ERR
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|sscop_stat
operator|.
name|sos_aborts
operator|++
expr_stmt|;
comment|/* 	 * Send an END PDU as a courtesy to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_end
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Set termination state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_TERM
expr_stmt|;
comment|/* 	 * Flush all of our queues 	 */
name|sscop_xmit_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
name|sscop_rcvr_drain
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Tell Connection Manager to abort this connection 	 */
operator|(
name|void
operator|)
name|atm_cm_abort
argument_list|(
name|cvp
argument_list|,
operator|&
name|sscop_cause
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

