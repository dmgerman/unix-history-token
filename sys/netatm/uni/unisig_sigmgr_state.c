begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI 3.0/3.1 Signalling Manager  * ----------------------------------------  *  * Signalling manager finite state machine  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
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
file|<netatm/atm_sap.h>
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
file|<netatm/atm_vc.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sigmgr.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_stack.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_var.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/uni.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/unisig.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/unisig_var.h>
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
comment|/*  * Local functions  */
end_comment

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_invalid
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act01
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act02
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act03
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act04
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act05
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act06
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act07
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act08
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act09
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act10
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act11
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act12
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act13
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|unisig_sigmgr_act14
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * State table.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|sigmgr_state_table
index|[
literal|10
index|]
index|[
literal|7
index|]
init|=
block|{
comment|/*     0   1   2   3   4   5				*/
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* 0 - Time out		*/
block|{
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|5
block|,
literal|0
block|}
block|,
comment|/* 1 - SSCF estab ind	*/
block|{
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|5
block|,
literal|0
block|}
block|,
comment|/* 2 - SSCF estab cnf	*/
block|{
literal|0
block|,
literal|0
block|,
literal|4
block|,
literal|6
block|,
literal|0
block|}
block|,
comment|/* 3 - SSCF release ind	*/
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|6
block|,
literal|0
block|}
block|,
comment|/* 4 - SSCF release cnf	*/
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|7
block|,
literal|0
block|}
block|,
comment|/* 5 - SSCF data ind	*/
block|{
literal|0
block|,
literal|0
block|,
literal|2
block|,
literal|2
block|,
literal|0
block|}
block|,
comment|/* 6 - SSCF unit data ind */
block|{
literal|0
block|,
literal|0
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|}
block|,
comment|/* 7 - Call cleared	*/
block|{
literal|14
block|,
literal|14
block|,
literal|14
block|,
literal|14
block|,
literal|0
block|}
block|,
comment|/* 8 - Detach		*/
block|{
literal|13
block|,
literal|13
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
comment|/* 9 - Address set	*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Action vector  */
end_comment

begin_define
define|#
directive|define
name|MAX_ACTION
value|15
end_define

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|unisig_sigmgr_act_vec
index|[
name|MAX_ACTION
index|]
function_decl|)
parameter_list|(
name|struct
name|unisig
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
init|=
block|{
name|unisig_sigmgr_invalid
operator|,
function_decl|unisig_sigmgr_act01
operator|,
function_decl|unisig_sigmgr_act02
operator|,
function_decl|unisig_sigmgr_act03
operator|,
function_decl|unisig_sigmgr_act04
operator|,
function_decl|unisig_sigmgr_act05
operator|,
function_decl|unisig_sigmgr_act06
operator|,
function_decl|unisig_sigmgr_act07
operator|,
function_decl|unisig_sigmgr_act08
operator|,
function_decl|unisig_sigmgr_act09
operator|,
function_decl|unisig_sigmgr_act10
operator|,
function_decl|unisig_sigmgr_act11
operator|,
function_decl|unisig_sigmgr_act12
operator|,
function_decl|unisig_sigmgr_act13
operator|,
function_decl|unisig_sigmgr_act14
end_function_decl

begin_comment
unit|};
comment|/*  * ATM endpoint for UNI signalling channel  */
end_comment

begin_decl_stmt
specifier|static
name|Atm_endpoint
name|unisig_endpt
init|=
block|{
name|NULL
block|,
comment|/* ep_next */
name|ENDPT_UNI_SIG
block|,
comment|/* ep_id */
name|NULL
block|,
comment|/* ep_ioctl */
name|unisig_getname
block|,
comment|/* ep_getname */
name|unisig_connected
block|,
comment|/* ep_connected */
name|unisig_cleared
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
name|NULL
block|,
comment|/* ep_cpcs_data */
name|unisig_saal_ctl
block|,
comment|/* ep_saal_ctl */
name|unisig_saal_data
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
name|unisig_attr
init|=
block|{
name|NULL
block|,
comment|/* nif */
name|CMAPI_SAAL
block|,
comment|/* api */
name|UNI_VERS_3_0
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
name|ATM_AAL5
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
comment|/*  * Finite state machine for the UNISIG signalling manager  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	event	indication of the event to be processed  *	m	pointer to a buffer with a message (optional)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
name|int
name|unisig_sigmgr_state
parameter_list|(
name|usp
parameter_list|,
name|event
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|int
name|event
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|int
name|action
decl_stmt|,
name|err
init|=
literal|0
decl_stmt|;
comment|/* 	 * Cancel any signalling manager timer 	 */
name|UNISIG_CANCEL
argument_list|(
name|usp
argument_list|)
expr_stmt|;
comment|/* 	 * Select an action based on the incoming event and 	 * the signalling manager's state 	 */
name|action
operator|=
name|sigmgr_state_table
index|[
name|event
index|]
index|[
name|usp
operator|->
name|us_state
index|]
expr_stmt|;
name|ATM_DEBUG4
argument_list|(
literal|"unisig_sigmgr_state: usp=%p, state=%d, event=%d, action=%d\n"
argument_list|,
name|usp
argument_list|,
name|usp
operator|->
name|us_state
argument_list|,
name|event
argument_list|,
name|action
argument_list|)
expr_stmt|;
if|if
condition|(
name|action
operator|>=
name|MAX_ACTION
operator|||
name|action
operator|<
literal|0
condition|)
block|{
name|panic
argument_list|(
literal|"unisig_sigmgr_state: invalid action\n"
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Perform the requested action 	 */
name|err
operator|=
name|unisig_sigmgr_act_vec
index|[
name|action
index|]
operator|(
name|usp
operator|,
name|m
operator|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 0  *  * Invalid action  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_invalid
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"unisig_sigmgr_state: unexpected action\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
name|KB_FREEALL
argument_list|(
name|m
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
comment|/*  * Signalling manager state machine action 1  *  * The kickoff timer has expired at attach time; go to  * UNISIG_ADDR_WAIT state.  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act01
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
comment|/* 	 * Set the new state 	 */
name|usp
operator|->
name|us_state
operator|=
name|UNISIG_ADDR_WAIT
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 2  *  * Ignore the event  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act02
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
comment|/* 	 * Ignore event, discard message if present 	 */
if|if
condition|(
name|m
condition|)
name|KB_FREEALL
argument_list|(
name|m
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
comment|/*  * Signalling manager state machine action 3  *  * SSCF session on signalling channel has come up  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act03
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|struct
name|unisig_vccb
modifier|*
name|uvp
decl_stmt|,
modifier|*
name|vnext
decl_stmt|;
comment|/* 	 * Log the activation 	 */
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"unisig: signalling channel active\n"
argument_list|)
expr_stmt|;
comment|/* 	 * Go to ACTIVE state 	 */
name|usp
operator|->
name|us_state
operator|=
name|UNISIG_ACTIVE
expr_stmt|;
comment|/* 	 * Notify the VC state machine that the channel is up 	 */
for|for
control|(
name|uvp
operator|=
name|Q_HEAD
argument_list|(
name|usp
operator|->
name|us_vccq
argument_list|,
expr|struct
name|unisig_vccb
argument_list|)
init|;
name|uvp
condition|;
name|uvp
operator|=
name|vnext
control|)
block|{
name|vnext
operator|=
name|Q_NEXT
argument_list|(
name|uvp
argument_list|,
expr|struct
name|unisig_vccb
argument_list|,
name|uv_sigelem
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|unisig_vc_state
argument_list|(
name|usp
argument_list|,
name|uvp
argument_list|,
name|UNI_VC_SAAL_ESTAB
argument_list|,
operator|(
expr|struct
name|unisig_msg
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 4  *  * A SSCF release indication was received.  Try to establish an  * SSCF session on the signalling PVC.  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act04
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Try to establish an SSCF session. 	 */
name|err
operator|=
name|atm_cm_saal_ctl
argument_list|(
name|SSCF_UNI_ESTABLISH_REQ
argument_list|,
name|usp
operator|->
name|us_conn
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
name|panic
argument_list|(
literal|"unisig_sigmgr_act04: SSCF_UNI_ESTABLISH_REQ"
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
comment|/*  * Signalling manager state machine action 5  *  * SSCF session on signalling channel has been reset  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act05
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|struct
name|unisig_vccb
modifier|*
name|uvp
decl_stmt|,
modifier|*
name|vnext
decl_stmt|;
comment|/* 	 * Log the reset 	 */
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"unisig: signalling channel reset\n"
argument_list|)
expr_stmt|;
comment|/* 	 * Notify the VC state machine of the reset 	 */
for|for
control|(
name|uvp
operator|=
name|Q_HEAD
argument_list|(
name|usp
operator|->
name|us_vccq
argument_list|,
expr|struct
name|unisig_vccb
argument_list|)
init|;
name|uvp
condition|;
name|uvp
operator|=
name|vnext
control|)
block|{
name|vnext
operator|=
name|Q_NEXT
argument_list|(
name|uvp
argument_list|,
expr|struct
name|unisig_vccb
argument_list|,
name|uv_sigelem
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|unisig_vc_state
argument_list|(
name|usp
argument_list|,
name|uvp
argument_list|,
name|UNI_VC_SAAL_ESTAB
argument_list|,
operator|(
expr|struct
name|unisig_msg
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 6  *  * SSCF session on signalling channel has been lost  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act06
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|struct
name|unisig_vccb
modifier|*
name|uvp
decl_stmt|,
modifier|*
name|vnext
decl_stmt|;
comment|/* 	 * Log the fact that the session has been lost 	 */
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"unisig: signalling channel SSCF session lost\n"
argument_list|)
expr_stmt|;
comment|/* 	 * Notify the VC state machine of the loss 	 */
for|for
control|(
name|uvp
operator|=
name|Q_HEAD
argument_list|(
name|usp
operator|->
name|us_vccq
argument_list|,
expr|struct
name|unisig_vccb
argument_list|)
init|;
name|uvp
condition|;
name|uvp
operator|=
name|vnext
control|)
block|{
name|vnext
operator|=
name|Q_NEXT
argument_list|(
name|uvp
argument_list|,
expr|struct
name|unisig_vccb
argument_list|,
name|uv_sigelem
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|unisig_vc_state
argument_list|(
name|usp
argument_list|,
name|uvp
argument_list|,
name|UNI_VC_SAAL_FAIL
argument_list|,
operator|(
expr|struct
name|unisig_msg
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Try to restart the SSCF session 	 */
operator|(
name|void
operator|)
name|unisig_sigmgr_act04
argument_list|(
name|usp
argument_list|,
operator|(
name|KBuffer
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Go to INIT state 	 */
name|usp
operator|->
name|us_state
operator|=
name|UNISIG_INIT
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 7  *  * A Q.2931 signalling message has been received  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act07
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Pass the Q.2931 signalling message on 	 * to the VC state machine 	 */
name|err
operator|=
name|unisig_rcv_msg
argument_list|(
name|usp
argument_list|,
name|m
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
comment|/*  * Signalling manager state machine action 8  *  * Process a CALL_CLOSED event for the signalling PVC  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act08
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
comment|/* 	 * Signalling manager is now incommunicado 	 */
if|if
condition|(
name|usp
operator|->
name|us_state
operator|!=
name|UNISIG_DETACH
condition|)
block|{
comment|/* 		 * Log an error and set the state to NULL if 		 * we're not detaching 		 */
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"unisig: signalling channel closed\n"
argument_list|)
expr_stmt|;
name|usp
operator|->
name|us_state
operator|=
name|UNISIG_NULL
expr_stmt|;
block|}
name|usp
operator|->
name|us_conn
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 9  *  * Not used  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act09
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"unisig_sigmgr_act09: unexpected action\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
name|KB_FREEALL
argument_list|(
name|m
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
comment|/*  * Signalling manager state machine action 10  *  * Not used  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act10
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 11  *  * Not used  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act11
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"unisig_sigmgr_act11: unexpected action\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
name|KB_FREEALL
argument_list|(
name|m
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
comment|/*  * Signalling manager state machine action 12  *  * Not used  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act12
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"unisig_sigmgr_act11: unexpected action\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
name|KB_FREEALL
argument_list|(
name|m
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
comment|/*  * Signalling manager state machine action 13  *  * NSAP prefix has been set  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act13
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
name|Atm_addr_pvc
modifier|*
name|pvcp
decl_stmt|;
comment|/* 	 * Set UNI signalling channel connection attributes 	 */
if|if
condition|(
name|usp
operator|->
name|us_proto
operator|==
name|ATM_SIG_UNI30
condition|)
name|unisig_attr
operator|.
name|api_init
operator|=
name|UNI_VERS_3_0
expr_stmt|;
else|else
name|unisig_attr
operator|.
name|api_init
operator|=
name|UNI_VERS_3_1
expr_stmt|;
name|unisig_attr
operator|.
name|nif
operator|=
name|usp
operator|->
name|us_pif
operator|->
name|pif_nif
expr_stmt|;
name|unisig_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal5
operator|.
name|forward_max_SDU_size
operator|=
name|ATM_NIF_MTU
expr_stmt|;
name|unisig_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal5
operator|.
name|backward_max_SDU_size
operator|=
name|ATM_NIF_MTU
expr_stmt|;
name|unisig_attr
operator|.
name|aal
operator|.
name|v
operator|.
name|aal5
operator|.
name|SSCS_type
operator|=
name|T_ATM_SSCS_SSCOP_REL
expr_stmt|;
name|unisig_attr
operator|.
name|called
operator|.
name|tag
operator|=
name|T_ATM_PRESENT
expr_stmt|;
name|unisig_attr
operator|.
name|called
operator|.
name|addr
operator|.
name|address_format
operator|=
name|T_ATM_PVC_ADDR
expr_stmt|;
name|unisig_attr
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
name|unisig_attr
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
name|UNISIG_SIG_VPI
argument_list|)
expr_stmt|;
name|ATM_PVC_SET_VCI
argument_list|(
name|pvcp
argument_list|,
name|UNISIG_SIG_VCI
argument_list|)
expr_stmt|;
name|unisig_attr
operator|.
name|called
operator|.
name|subaddr
operator|.
name|address_format
operator|=
name|T_ATM_ABSENT
expr_stmt|;
name|unisig_attr
operator|.
name|called
operator|.
name|subaddr
operator|.
name|address_length
operator|=
literal|0
expr_stmt|;
name|unisig_attr
operator|.
name|traffic
operator|.
name|v
operator|.
name|forward
operator|.
name|PCR_all_traffic
operator|=
name|usp
operator|->
name|us_pif
operator|->
name|pif_pcr
expr_stmt|;
name|unisig_attr
operator|.
name|traffic
operator|.
name|v
operator|.
name|backward
operator|.
name|PCR_all_traffic
operator|=
name|usp
operator|->
name|us_pif
operator|->
name|pif_pcr
expr_stmt|;
comment|/* 	 * Create UNISIG signalling channel 	 */
name|err
operator|=
name|atm_cm_connect
argument_list|(
operator|&
name|unisig_endpt
argument_list|,
name|usp
argument_list|,
operator|&
name|unisig_attr
argument_list|,
operator|&
name|usp
operator|->
name|us_conn
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
return|return
operator|(
name|err
operator|)
return|;
block|}
comment|/* 	 * Establish the SSCF session 	 */
name|err
operator|=
name|atm_cm_saal_ctl
argument_list|(
name|SSCF_UNI_ESTABLISH_REQ
argument_list|,
name|usp
operator|->
name|us_conn
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
name|panic
argument_list|(
literal|"unisig_sigmgr_act13: SSCF_UNI_ESTABLISH_REQ"
argument_list|)
expr_stmt|;
comment|/* 	 * Set the new state 	 */
name|usp
operator|->
name|us_state
operator|=
name|UNISIG_INIT
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Signalling manager state machine action 14  *  * Process a detach event  *  * Arguments:  *	usp	pointer to the UNISIG protocol control block  *	m	buffer pointer (may be NULL)  *  * Returns:  *	0	success  *	errno	error encountered  *  */
end_comment

begin_function
specifier|static
name|int
name|unisig_sigmgr_act14
parameter_list|(
name|usp
parameter_list|,
name|m
parameter_list|)
name|struct
name|unisig
modifier|*
name|usp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
name|struct
name|unisig_vccb
modifier|*
name|sig_vccb
decl_stmt|,
modifier|*
name|uvp
decl_stmt|,
modifier|*
name|vnext
decl_stmt|;
name|struct
name|atm_pif
modifier|*
name|pip
decl_stmt|;
name|struct
name|t_atm_cause
name|cause
decl_stmt|;
comment|/* 	 * Locate the signalling channel's VCCB 	 */
name|sig_vccb
operator|=
operator|(
expr|struct
name|unisig_vccb
operator|*
operator|)
literal|0
expr_stmt|;
if|if
condition|(
name|usp
operator|->
name|us_conn
operator|&&
name|usp
operator|->
name|us_conn
operator|->
name|co_connvc
condition|)
name|sig_vccb
operator|=
operator|(
expr|struct
name|unisig_vccb
operator|*
operator|)
name|usp
operator|->
name|us_conn
operator|->
name|co_connvc
operator|->
name|cvc_vcc
expr_stmt|;
comment|/* 	 * Terminate all of our VCCs 	 */
for|for
control|(
name|uvp
operator|=
name|Q_HEAD
argument_list|(
name|usp
operator|->
name|us_vccq
argument_list|,
expr|struct
name|unisig_vccb
argument_list|)
init|;
name|uvp
condition|;
name|uvp
operator|=
name|vnext
control|)
block|{
name|vnext
operator|=
name|Q_NEXT
argument_list|(
name|uvp
argument_list|,
expr|struct
name|unisig_vccb
argument_list|,
name|uv_sigelem
argument_list|)
expr_stmt|;
comment|/* 		 * Don't close the signalling VCC yet 		 */
if|if
condition|(
name|uvp
operator|==
name|sig_vccb
condition|)
continue|continue;
comment|/* 		 * Close VCC and notify owner 		 */
name|err
operator|=
name|unisig_clear_vcc
argument_list|(
name|usp
argument_list|,
name|uvp
argument_list|,
name|T_ATM_CAUSE_NORMAL_CALL_CLEARING
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Close the signalling channel 	 */
if|if
condition|(
name|usp
operator|->
name|us_conn
condition|)
block|{
name|cause
operator|.
name|coding_standard
operator|=
name|T_ATM_ITU_CODING
expr_stmt|;
name|cause
operator|.
name|coding_standard
operator|=
name|T_ATM_LOC_USER
expr_stmt|;
name|cause
operator|.
name|coding_standard
operator|=
name|T_ATM_CAUSE_UNSPECIFIED_NORMAL
expr_stmt|;
name|err
operator|=
name|atm_cm_release
argument_list|(
name|usp
operator|->
name|us_conn
argument_list|,
operator|&
name|cause
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
name|panic
argument_list|(
literal|"unisig_sigmgr_act14: close failed\n"
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Get rid of protocol instance if there are no VCCs queued 	 */
name|pip
operator|=
name|usp
operator|->
name|us_pif
expr_stmt|;
if|if
condition|(
name|Q_HEAD
argument_list|(
name|usp
operator|->
name|us_vccq
argument_list|,
expr|struct
name|vccb
argument_list|)
operator|==
name|NULL
operator|&&
name|pip
operator|->
name|pif_sigmgr
condition|)
block|{
name|struct
name|sigmgr
modifier|*
name|smp
init|=
name|pip
operator|->
name|pif_sigmgr
decl_stmt|;
name|int
name|s
init|=
name|splimp
argument_list|()
decl_stmt|;
name|pip
operator|->
name|pif_sigmgr
operator|=
name|NULL
expr_stmt|;
name|pip
operator|->
name|pif_siginst
operator|=
name|NULL
expr_stmt|;
operator|(
name|void
operator|)
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|UNLINK
argument_list|(
operator|(
expr|struct
name|siginst
operator|*
operator|)
name|usp
argument_list|,
expr|struct
name|siginst
argument_list|,
name|smp
operator|->
name|sm_prinst
argument_list|,
name|si_next
argument_list|)
expr_stmt|;
name|KM_FREE
argument_list|(
name|usp
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|unisig
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * Otherwise, set new signalling manager state and 		 * wait for protocol instance to be freed during  		 * unisig_free processing for the last queued VCC 		 */
name|usp
operator|->
name|us_state
operator|=
name|UNISIG_DETACH
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

