begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * Signalling AAL SSCF at the UNI  *  */
end_comment

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/uni.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscf_uni_var.h>
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
name|sscf_uni_vccnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local functions  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|sscf_uni_inst
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
name|sp_info
name|sscf_uni_pool
init|=
block|{
literal|"sscf uni pool"
block|,
comment|/* si_name */
sizeof|sizeof
argument_list|(
expr|struct
name|univcc
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

begin_decl_stmt
specifier|static
name|struct
name|stack_defn
name|sscf_uni_service
init|=
block|{
name|NULL
block|,
name|SAP_SSCF_UNI
block|,
literal|0
block|,
name|sscf_uni_inst
block|,
name|sscf_uni_lower
block|,
name|sscf_uni_upper
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|t_atm_cause
name|sscf_uni_cause
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

begin_comment
comment|/*  * Initialize SSCF UNI processing  *   * This will be called during module loading.  We will register our stack  * service and wait for someone to talk to us.  *  * Arguments:  *	none  *  * Returns:  *	0 	initialization was successful   *	errno	initialization failed - reason indicated  *  */
end_comment

begin_function
name|int
name|sscf_uni_start
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
name|sscf_uni_service
argument_list|)
operator|)
operator|!=
literal|0
condition|)
goto|goto
name|done
goto|;
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
comment|/*  * Terminate SSCF UNI processing   *   * This will be called just prior to unloading the module from memory.  All   * signalling instances should have been terminated by now, so we just free  * up all of our resources.  *  * Called at splnet.  *  * Arguments:  *	none  *  * Returns:  *	0 	termination was successful   *	errno	termination failed - reason indicated  *  */
end_comment

begin_function
name|int
name|sscf_uni_stop
parameter_list|()
block|{
comment|/* 	 * Any connections still exist?? 	 */
if|if
condition|(
name|sscf_uni_vccnt
condition|)
block|{
comment|/* 		 * Yes, can't stop yet 		 */
return|return
operator|(
name|EBUSY
operator|)
return|;
block|}
comment|/* 	 * Deregister the stack service 	 */
operator|(
name|void
operator|)
name|atm_stack_deregister
argument_list|(
operator|&
name|sscf_uni_service
argument_list|)
expr_stmt|;
comment|/* 	 * Free our storage pools 	 */
name|atm_release_pool
argument_list|(
operator|&
name|sscf_uni_pool
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * SSCF_UNI Stack Instantiation   *   * Called at splnet.  *  * Arguments:  *	ssp	pointer to array of stack definition pointers for connection  *		ssp[0] points to upper layer's stack service definition  *		ssp[1] points to this layer's stack service definition  *		ssp[2] points to lower layer's stack service definition  *	cvp	pointer to connection vcc for this stack  *  * Returns:  *	0 	instantiation successful  *	errno	instantiation failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|sscf_uni_inst
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
name|univcc
modifier|*
name|uvp
decl_stmt|;
name|int
name|err
decl_stmt|;
name|ATM_DEBUG2
argument_list|(
literal|"sscf_uni_inst: ssp=%p, cvp=%p\n"
argument_list|,
name|ssp
argument_list|,
name|cvp
argument_list|)
expr_stmt|;
comment|/* 	 * Validate lower SAP 	 */
if|if
condition|(
name|sdp_low
operator|->
name|sd_sap
operator|!=
name|SAP_SSCOP
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* 	 * Allocate our control block 	 */
name|uvp
operator|=
operator|(
expr|struct
name|univcc
operator|*
operator|)
name|atm_allocate
argument_list|(
operator|&
name|sscf_uni_pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|uvp
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENOMEM
operator|)
return|;
name|uvp
operator|->
name|uv_ustate
operator|=
name|UVU_INST
expr_stmt|;
name|uvp
operator|->
name|uv_lstate
operator|=
name|UVL_INST
expr_stmt|;
name|uvp
operator|->
name|uv_connvc
operator|=
name|cvp
expr_stmt|;
name|uvp
operator|->
name|uv_toku
operator|=
name|sdp_up
operator|->
name|sd_toku
expr_stmt|;
name|uvp
operator|->
name|uv_upper
operator|=
name|sdp_up
operator|->
name|sd_upper
expr_stmt|;
name|sscf_uni_vccnt
operator|++
expr_stmt|;
comment|/* 	 * Store my token into service definition 	 */
name|sdp_me
operator|->
name|sd_toku
operator|=
name|uvp
expr_stmt|;
comment|/* 	 * Update and save input buffer headroom 	 */
name|HEADIN
argument_list|(
name|cvp
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* uvp->uv_headin = cvp->cvc_attr.headin; */
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
name|uvp
argument_list|)
expr_stmt|;
name|sscf_uni_vccnt
operator|--
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
comment|/* 	 * Save and update output buffer headroom 	 */
comment|/* uvp->uv_headout = cvp->cvc_attr.headout; */
name|HEADOUT
argument_list|(
name|cvp
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Save lower layer's interface info 	 */
name|uvp
operator|->
name|uv_lower
operator|=
name|sdp_low
operator|->
name|sd_lower
expr_stmt|;
name|uvp
operator|->
name|uv_tokl
operator|=
name|sdp_low
operator|->
name|sd_toku
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Abort an SSCF_UNI connection  *   * Called when an unrecoverable or "should never happen" error occurs.  * We just log a message and request the signalling manager to abort the  * connection.  *  * Arguments:  *	uvp	pointer to univcc control block  *	msg	pointer to error message  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscf_uni_abort
parameter_list|(
name|uvp
parameter_list|,
name|msg
parameter_list|)
name|struct
name|univcc
modifier|*
name|uvp
decl_stmt|;
name|char
modifier|*
name|msg
decl_stmt|;
block|{
comment|/* 	 * Log error message 	 */
name|log
argument_list|(
name|LOG_ERR
argument_list|,
name|msg
argument_list|)
expr_stmt|;
comment|/* 	 * Set termination states 	 */
name|uvp
operator|->
name|uv_ustate
operator|=
name|UVU_TERM
expr_stmt|;
name|uvp
operator|->
name|uv_lstate
operator|=
name|UVL_TERM
expr_stmt|;
comment|/* 	 * Tell Connection Manager to abort this connection 	 */
operator|(
name|void
operator|)
name|atm_cm_abort
argument_list|(
name|uvp
operator|->
name|uv_connvc
argument_list|,
operator|&
name|sscf_uni_cause
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Print an SSCF PDU  *   * Arguments:  *	uvp	pointer to univcc control block  *	m	pointer to pdu buffer chain  *	msg	pointer to message string  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscf_uni_pdu_print
parameter_list|(
name|uvp
parameter_list|,
name|m
parameter_list|,
name|msg
parameter_list|)
name|struct
name|univcc
modifier|*
name|uvp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|char
modifier|*
name|msg
decl_stmt|;
block|{
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|struct
name|vccb
modifier|*
name|vcp
decl_stmt|;
name|vcp
operator|=
name|uvp
operator|->
name|uv_connvc
operator|->
name|cvc_vcc
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"sscf_uni %s: vcc=(%d,%d)\n"
argument_list|,
name|msg
argument_list|,
name|vcp
operator|->
name|vc_vpi
argument_list|,
name|vcp
operator|->
name|vc_vci
argument_list|)
expr_stmt|;
name|atm_pdu_print
argument_list|(
name|m
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

