begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * SPANS Signalling Manager  * ---------------------------  *  * SPANS protocol processing module.  *  */
end_comment

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_include
include|#
directive|include
file|"spans_xdr.h"
end_include

begin_include
include|#
directive|include
file|<netatm/spans/spans_var.h>
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
comment|/*  * Internal functions  */
end_comment

begin_decl_stmt
name|caddr_t
name|spans_getname
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_connected
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_cleared
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|t_atm_cause
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spans_cpcs_data
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|KBuffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ATM endpoint for SPANS signalling channel  */
end_comment

begin_decl_stmt
specifier|static
name|Atm_endpoint
name|spans_endpt
init|=
block|{
name|NULL
block|,
comment|/* ep_next */
name|ENDPT_SPANS_SIG
block|,
comment|/* ep_id */
name|NULL
block|,
comment|/* ep_ioctl */
name|spans_getname
block|,
comment|/* ep_getname */
name|spans_connected
block|,
comment|/* ep_connected */
name|spans_cleared
block|,
comment|/* ep_cleared */
name|NULL
block|,
comment|/* ep_incoming */
name|NULL
block|,
comment|/* ep_addparty */
name|NULL
block|,
comment|/* ep_dropparty */
name|NULL
block|,
comment|/* ep_cpcs_ctl */
name|spans_cpcs_data
block|,
comment|/* ep_cpcs_data */
name|NULL
block|,
comment|/* ep_saal_ctl */
name|NULL
block|,
comment|/* ep_saal_data */
name|NULL
block|,
comment|/* ep_sscop_ctl */
name|NULL
comment|/* ep_sscop_data */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ATM connection attributes for UNI signalling channel  */
end_comment

begin_decl_stmt
specifier|static
name|Atm_attributes
name|spans_attr
init|=
block|{
name|NULL
block|,
comment|/* nif */
name|CMAPI_CPCS
block|,
comment|/* api */
literal|0
block|,
comment|/* api_init */
literal|0
block|,
comment|/* headin */
literal|0
block|,
comment|/* headout */
block|{
comment|/* aal */
name|T_ATM_PRESENT
block|,
comment|/* aal.tag */
name|ATM_AAL3_4
comment|/* aal.aal_type */
block|}
block|,
block|{
comment|/* traffic */
name|T_ATM_PRESENT
block|,
comment|/* traffic.tag */
block|{
comment|/* traffic.v */
block|{
comment|/* traffic.v.forward */
name|T_ATM_ABSENT
block|,
comment|/* PCR_high */
literal|0
block|,
comment|/* PCR_all */
name|T_ATM_ABSENT
block|,
comment|/* SCR_high */
name|T_ATM_ABSENT
block|,
comment|/* SCR_all */
name|T_ATM_ABSENT
block|,
comment|/* MBS_high */
name|T_ATM_ABSENT
block|,
comment|/* MBS_all */
name|T_NO
block|,
comment|/* tagging */
block|}
block|,
block|{
comment|/* traffic.v.backward */
name|T_ATM_ABSENT
block|,
comment|/* PCR_high */
literal|0
block|,
comment|/* PCR_all */
name|T_ATM_ABSENT
block|,
comment|/* SCR_high */
name|T_ATM_ABSENT
block|,
comment|/* SCR_all */
name|T_ATM_ABSENT
block|,
comment|/* MBS_high */
name|T_ATM_ABSENT
block|,
comment|/* MBS_all */
name|T_NO
block|,
comment|/* tagging */
block|}
block|,
name|T_YES
block|,
comment|/* best_effort */
block|}
block|}
block|,
block|{
comment|/* bearer */
name|T_ATM_PRESENT
block|,
comment|/* bearer.tag */
block|{
comment|/* bearer.v */
name|T_ATM_CLASS_X
block|,
comment|/* class */
name|T_ATM_NULL
block|,
comment|/* traffic_type */
name|T_ATM_NO_END_TO_END
block|,
comment|/* timing_req */
name|T_NO
block|,
comment|/* clipping */
name|T_ATM_1_TO_1
block|,
comment|/* conn_conf */
block|}
block|}
block|,
block|{
comment|/* bhli */
name|T_ATM_ABSENT
block|,
comment|/* bhli.tag */
block|}
block|,
block|{
comment|/* blli */
name|T_ATM_ABSENT
block|,
comment|/* blli.tag_l2 */
name|T_ATM_ABSENT
block|,
comment|/* blli.tag_l3 */
block|}
block|,
block|{
comment|/* llc */
name|T_ATM_ABSENT
block|,
comment|/* llc.tag */
block|}
block|,
block|{
comment|/* called */
name|T_ATM_PRESENT
block|,
comment|/* called.tag */
block|}
block|,
block|{
comment|/* calling */
name|T_ATM_ABSENT
block|,
comment|/* calling.tag */
block|}
block|,
block|{
comment|/* qos */
name|T_ATM_PRESENT
block|,
comment|/* qos.tag */
block|{
comment|/* qos.v */
name|T_ATM_NETWORK_CODING
block|,
comment|/* coding_standard */
block|{
comment|/* qos.v.forward */
name|T_ATM_QOS_CLASS_0
block|,
comment|/* class */
block|}
block|,
block|{
comment|/* qos.v.backward */
name|T_ATM_QOS_CLASS_0
block|,
comment|/* class */
block|}
block|}
block|}
block|,
block|{
comment|/* transit */
name|T_ATM_ABSENT
block|,
comment|/* transit.tag */
block|}
block|,
block|{
comment|/* cause */
name|T_ATM_ABSENT
block|,
comment|/* cause.tag */
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * SPANS cause structre  */
end_comment

begin_decl_stmt
name|struct
name|t_atm_cause
name|spans_cause
init|=
block|{
name|T_ATM_ITU_CODING
block|,
comment|/* coding_standard */
name|T_ATM_LOC_USER
block|,
comment|/* location */
name|T_ATM_CAUSE_UNSPECIFIED_NORMAL
block|,
comment|/* cause_value */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
comment|/* diagnostics */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Process a SPANS timeout  *  * Called when a previously scheduled spans control block timer expires.  * Processing will based on the current SPANS state.  *  * Called at splnet.  *  * Arguments:  *	tip	pointer to spans timer control block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|spans_timer
parameter_list|(
name|tip
parameter_list|)
name|struct
name|atm_time
modifier|*
name|tip
decl_stmt|;
block|{
name|struct
name|spans
modifier|*
name|spp
decl_stmt|;
name|spans_msg
modifier|*
name|msg
decl_stmt|;
name|Atm_addr_pvc
modifier|*
name|pvcp
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* 	 * Back-off to SPANS control block 	 */
name|spp
operator|=
operator|(
expr|struct
name|spans
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|tip
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
expr|struct
name|spans
operator|*
operator|)
literal|0
operator|)
operator|->
name|sp_time
argument_list|)
operator|)
expr_stmt|;
name|ATM_DEBUG2
argument_list|(
literal|"spans_timer: spp=%p,state=%d\n"
argument_list|,
name|spp
argument_list|,
name|spp
operator|->
name|sp_state
argument_list|)
expr_stmt|;
comment|/* 	 * Process timeout based on protocol state 	 */
switch|switch
condition|(
name|spp
operator|->
name|sp_state
condition|)
block|{
case|case
name|SPANS_INIT
case|:
comment|/* 		 * Open signalling channel 		 */
name|spans_attr
operator|.
name|nif
operator|=
name|spp
operator|->
name|sp_pif
operator|->
name|pif_nif
expr_stmt|;
name|spans_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal4
operator|.
name|forward_max_SDU_size
operator|=
name|ATM_NIF_MTU
expr_stmt|;
name|spans_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal4
operator|.
name|backward_max_SDU_size
operator|=
name|ATM_NIF_MTU
expr_stmt|;
name|spans_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal4
operator|.
name|SSCS_type
operator|=
name|T_ATM_SSCS_SSCOP_UNREL
expr_stmt|;
name|spans_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal4
operator|.
name|mid_low
operator|=
literal|0
expr_stmt|;
name|spans_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal4
operator|.
name|mid_high
operator|=
literal|0
expr_stmt|;
name|spans_attr
operator|.
name|called
operator|.
name|tag
operator|=
name|T_ATM_PRESENT
expr_stmt|;
name|spans_attr
operator|.
name|called
operator|.
name|addr
operator|.
name|address_format
operator|=
name|T_ATM_PVC_ADDR
expr_stmt|;
name|spans_attr
operator|.
name|called
operator|.
name|addr
operator|.
name|address_length
operator|=
sizeof|sizeof
argument_list|(
name|Atm_addr_pvc
argument_list|)
expr_stmt|;
name|pvcp
operator|=
operator|(
name|Atm_addr_pvc
operator|*
operator|)
name|spans_attr
operator|.
name|called
operator|.
name|addr
operator|.
name|address
expr_stmt|;
name|ATM_PVC_SET_VPI
argument_list|(
name|pvcp
argument_list|,
name|SPANS_SIG_VPI
argument_list|)
expr_stmt|;
name|ATM_PVC_SET_VCI
argument_list|(
name|pvcp
argument_list|,
name|SPANS_SIG_VCI
argument_list|)
expr_stmt|;
name|spans_attr
operator|.
name|called
operator|.
name|subaddr
operator|.
name|address_format
operator|=
name|T_ATM_ABSENT
expr_stmt|;
name|spans_attr
operator|.
name|called
operator|.
name|subaddr
operator|.
name|address_length
operator|=
literal|0
expr_stmt|;
name|spans_attr
operator|.
name|traffic
operator|.
name|v
operator|.
name|forward
operator|.
name|PCR_all_traffic
operator|=
name|spp
operator|->
name|sp_pif
operator|->
name|pif_pcr
expr_stmt|;
name|spans_attr
operator|.
name|traffic
operator|.
name|v
operator|.
name|backward
operator|.
name|PCR_all_traffic
operator|=
name|spp
operator|->
name|sp_pif
operator|->
name|pif_pcr
expr_stmt|;
name|err
operator|=
name|atm_cm_connect
argument_list|(
operator|&
name|spans_endpt
argument_list|,
name|spp
argument_list|,
operator|&
name|spans_attr
argument_list|,
operator|&
name|spp
operator|->
name|sp_conn
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"spans: signalling channel setup failed\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 		 * Signalling channel open, start probing 		 */
name|spp
operator|->
name|sp_state
operator|=
name|SPANS_PROBE
expr_stmt|;
comment|/* FALLTHRU */
case|case
name|SPANS_PROBE
case|:
case|case
name|SPANS_ACTIVE
case|:
comment|/* 		 * Send out SPANS_STAT_REQ message 		 */
name|msg
operator|=
operator|(
name|spans_msg
operator|*
operator|)
name|atm_allocate
argument_list|(
operator|&
name|spans_msgpool
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|==
name|NULL
condition|)
block|{
comment|/* Retry later if no memory */
name|SPANS_TIMER
argument_list|(
name|spp
argument_list|,
name|SPANS_PROBE_ERR_WAIT
argument_list|)
expr_stmt|;
break|break;
block|}
name|msg
operator|->
name|sm_vers
operator|=
name|SPANS_VERS_1_0
expr_stmt|;
name|msg
operator|->
name|sm_type
operator|=
name|SPANS_STAT_REQ
expr_stmt|;
name|msg
operator|->
name|sm_stat_req
operator|.
name|streq_es_epoch
operator|=
name|spp
operator|->
name|sp_h_epoch
expr_stmt|;
if|if
condition|(
name|spans_send_msg
argument_list|(
name|spp
argument_list|,
name|msg
argument_list|)
condition|)
block|{
comment|/* Retry later if send fails */
name|SPANS_TIMER
argument_list|(
name|spp
argument_list|,
name|SPANS_PROBE_ERR_WAIT
argument_list|)
expr_stmt|;
name|atm_free
argument_list|(
name|msg
argument_list|)
expr_stmt|;
break|break;
block|}
name|atm_free
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|spp
operator|->
name|sp_probe_ct
operator|++
expr_stmt|;
comment|/* 		 * Check whether we're getting an answer to our probes 		 */
if|if
condition|(
name|spp
operator|->
name|sp_state
operator|==
name|SPANS_ACTIVE
operator|&&
name|spp
operator|->
name|sp_probe_ct
operator|>
name|SPANS_PROBE_THRESH
condition|)
block|{
comment|/* 			 * Interface is down, notify VCC owners 			 */
name|spans_switch_reset
argument_list|(
name|spp
argument_list|,
name|SPANS_UNI_DOWN
argument_list|)
expr_stmt|;
comment|/* 			 * Set new state and increment host epoch so 			 * switch knows we reset everyting. 			 */
name|spp
operator|->
name|sp_state
operator|=
name|SPANS_PROBE
expr_stmt|;
name|spp
operator|->
name|sp_h_epoch
operator|++
expr_stmt|;
name|spp
operator|->
name|sp_s_epoch
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 		 * Keep sending status requests 		 */
name|SPANS_TIMER
argument_list|(
name|spp
argument_list|,
name|SPANS_PROBE_INTERVAL
argument_list|)
expr_stmt|;
break|break;
case|case
name|SPANS_DETACH
case|:
comment|/* 		 * Try to terminate the SPANS signalling PVC 		 */
name|err
operator|=
name|atm_cm_release
argument_list|(
name|spp
operator|->
name|sp_conn
argument_list|,
operator|&
name|spans_cause
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"spans: can't close signalling channel\n"
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"spans: timer state: spp=%p, state=%d\n"
argument_list|,
name|spp
argument_list|,
name|spp
operator|->
name|sp_state
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Process a SPANS VCC timeout  *  * Called when a previously scheduled SPANS VCCB timer expires.  * Processing will based on the current VCC state.  *  * Called at splnet.  *  * Arguments:  *	tip	pointer to vccb timer control block  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|spans_vctimer
parameter_list|(
name|tip
parameter_list|)
name|struct
name|atm_time
modifier|*
name|tip
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
name|struct
name|spans
modifier|*
name|spp
decl_stmt|;
name|struct
name|spans_vccb
modifier|*
name|svp
decl_stmt|;
comment|/* 	 * Get VCCB and SPANS control block addresses 	 */
name|svp
operator|=
operator|(
expr|struct
name|spans_vccb
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|tip
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
expr|struct
name|vccb
operator|*
operator|)
literal|0
operator|)
operator|->
name|vc_time
argument_list|)
operator|)
expr_stmt|;
name|spp
operator|=
operator|(
expr|struct
name|spans
operator|*
operator|)
name|svp
operator|->
name|sv_pif
operator|->
name|pif_siginst
expr_stmt|;
name|ATM_DEBUG3
argument_list|(
literal|"spans_vctimer: svp=%p, sstate=%d, ustate=%d\n"
argument_list|,
name|svp
argument_list|,
name|svp
operator|->
name|sv_sstate
argument_list|,
name|svp
operator|->
name|sv_ustate
argument_list|)
expr_stmt|;
comment|/* 	 * Process timeout based on protocol state 	 */
switch|switch
condition|(
name|svp
operator|->
name|sv_sstate
condition|)
block|{
case|case
name|SPANS_VC_ABORT
case|:
comment|/* 		 * Kill the VCCB and notify the owner 		 */
name|err
operator|=
name|spans_clear_vcc
argument_list|(
name|spp
argument_list|,
name|svp
argument_list|)
expr_stmt|;
break|break;
case|case
name|SPANS_VC_FREE
case|:
comment|/* 		 * Free VCCB storage 		 */
name|svp
operator|->
name|sv_ustate
operator|=
name|VCCU_CLOSED
expr_stmt|;
name|svp
operator|->
name|sv_sstate
operator|=
name|SPANS_VC_FREE
expr_stmt|;
name|spans_free
argument_list|(
operator|(
expr|struct
name|vccb
operator|*
operator|)
name|svp
argument_list|)
expr_stmt|;
break|break;
case|case
name|SPANS_VC_POPEN
case|:
comment|/* 		 * Issued open request, but didn't get response. 		 */
if|if
condition|(
name|svp
operator|->
name|sv_retry
operator|<
name|SV_MAX_RETRY
condition|)
block|{
comment|/* 			 * Retransmit the open request 			 */
name|err
operator|=
name|spans_send_open_req
argument_list|(
name|spp
argument_list|,
name|svp
argument_list|)
expr_stmt|;
name|svp
operator|->
name|sv_retry
operator|++
expr_stmt|;
name|SPANS_VC_TIMER
argument_list|(
operator|(
expr|struct
name|vccb
operator|*
operator|)
name|svp
argument_list|,
name|SV_TIMEOUT
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * Retry limit exceeded--report the open failed 			 */
name|svp
operator|->
name|sv_ustate
operator|=
name|VCCU_CLOSED
expr_stmt|;
name|svp
operator|->
name|sv_sstate
operator|=
name|SPANS_VC_FREE
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|tag
operator|=
name|T_ATM_PRESENT
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|coding_standard
operator|=
name|T_ATM_ITU_CODING
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|location
operator|=
name|T_ATM_LOC_USER
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|cause_value
operator|=
name|T_ATM_CAUSE_NO_USER_RESPONDING
expr_stmt|;
name|KM_ZERO
argument_list|(
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|diagnostics
argument_list|,
sizeof|sizeof
argument_list|(
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|diagnostics
argument_list|)
argument_list|)
expr_stmt|;
name|atm_cm_cleared
argument_list|(
name|svp
operator|->
name|sv_connvc
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|SPANS_VC_CLOSE
case|:
comment|/* 		 * Issued close request, but didn't get response. 		 */
if|if
condition|(
name|svp
operator|->
name|sv_retry
operator|<
name|SV_MAX_RETRY
condition|)
block|{
comment|/* 			 * Retransmit the close request 			 */
name|err
operator|=
name|spans_send_close_req
argument_list|(
name|spp
argument_list|,
name|svp
argument_list|)
expr_stmt|;
name|svp
operator|->
name|sv_retry
operator|++
expr_stmt|;
name|SPANS_VC_TIMER
argument_list|(
operator|(
expr|struct
name|vccb
operator|*
operator|)
name|svp
argument_list|,
name|SV_TIMEOUT
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * Retry limit exceeded--just finish the close 			 */
name|svp
operator|->
name|sv_sstate
operator|=
name|SPANS_VC_FREE
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|tag
operator|=
name|T_ATM_PRESENT
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|coding_standard
operator|=
name|T_ATM_ITU_CODING
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|location
operator|=
name|T_ATM_LOC_USER
expr_stmt|;
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|cause_value
operator|=
name|T_ATM_CAUSE_NO_USER_RESPONDING
expr_stmt|;
name|KM_ZERO
argument_list|(
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|diagnostics
argument_list|,
sizeof|sizeof
argument_list|(
name|svp
operator|->
name|sv_connvc
operator|->
name|cvc_attr
operator|.
name|cause
operator|.
name|v
operator|.
name|diagnostics
argument_list|)
argument_list|)
expr_stmt|;
name|atm_cm_cleared
argument_list|(
name|svp
operator|->
name|sv_connvc
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|SPANS_VC_ACTIVE
case|:
case|case
name|SPANS_VC_ACT_DOWN
case|:
comment|/* 		 * Shouldn't happen 		 */
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"spans_vctimer: unexpected state %d\n"
argument_list|,
name|svp
operator|->
name|sv_sstate
argument_list|)
expr_stmt|;
break|break;
default|default:
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"spans: vctimer state: svp=%p, sstate=%d\n"
argument_list|,
name|svp
argument_list|,
name|svp
operator|->
name|sv_sstate
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * SPANS name routine  *  * Arguments:  *	tok	SPANS signalling channel token (ignored)  *  * Returns:  *	pointer to a string identifying the SPANS signalling manager  *  */
end_comment

begin_function
name|caddr_t
name|spans_getname
parameter_list|(
name|tok
parameter_list|)
name|void
modifier|*
name|tok
decl_stmt|;
block|{
return|return
operator|(
literal|"SPANS"
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Process a VCC connection notification  *  * Should never be called  *  * Arguments:  *	tok	user's connection token (SPANS protocol block)  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|spans_connected
parameter_list|(
name|tok
parameter_list|)
name|void
modifier|*
name|tok
decl_stmt|;
block|{
name|struct
name|spans
modifier|*
name|spp
init|=
operator|(
expr|struct
name|spans
operator|*
operator|)
name|tok
decl_stmt|;
name|ATM_DEBUG2
argument_list|(
literal|"spans_connected: spp=%p,state=%d\n"
argument_list|,
name|spp
argument_list|,
name|spp
operator|->
name|sp_state
argument_list|)
expr_stmt|;
comment|/* 	 * Connected routine shouldn't ever get called for a PVC 	 */
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"spans: connected function called, tok=%p\n"
argument_list|,
name|spp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Process a VCC close notification  *  * Called when the SPANS signalling channel is closed  *  * Arguments:  *	tok	user's connection token (spans protocol block)  *	cp	pointer to cause structure  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|spans_cleared
parameter_list|(
name|tok
parameter_list|,
name|cp
parameter_list|)
name|void
modifier|*
name|tok
decl_stmt|;
name|struct
name|t_atm_cause
modifier|*
name|cp
decl_stmt|;
block|{
name|struct
name|spans
modifier|*
name|spp
init|=
operator|(
expr|struct
name|spans
operator|*
operator|)
name|tok
decl_stmt|;
comment|/* 	 * VCC has been closed. 	 */
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"spans: signalling channel closed\n"
argument_list|)
expr_stmt|;
name|SPANS_CANCEL
argument_list|(
name|spp
argument_list|)
expr_stmt|;
name|spp
operator|->
name|sp_conn
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * SPANS CPCS data handler  *  * This is the module which receives data on the SPANS signalling  * channel.  Processing is based on the indication received from the  * AAL and the protocol state.  *  * Arguments:  *	tok	session token (pointer to spans protocol control block)  *	m	pointer to buffer with data  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|spans_cpcs_data
parameter_list|(
name|tok
parameter_list|,
name|m
parameter_list|)
name|void
modifier|*
name|tok
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|struct
name|spans
modifier|*
name|spp
init|=
name|tok
decl_stmt|;
name|ATM_DEBUG3
argument_list|(
literal|"spans_cpcs_data: spp=%p,state=%d,m=%p,\n"
argument_list|,
name|spp
argument_list|,
name|spp
operator|->
name|sp_state
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* 	 * Process data 	 */
name|spans_rcv_msg
argument_list|(
name|spp
argument_list|,
name|m
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

