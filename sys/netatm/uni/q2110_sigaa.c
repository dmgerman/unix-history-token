begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * ITU-T Q.2110 - Process AA-signals (SAP_SSCOP)  *  */
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
comment|/*  * Local functions  */
end_comment

begin_function_decl
specifier|static
name|void
name|sscop_resreq_ready
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sscop_resrsp_inresyn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sscop_recrsp_recovrsp
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sscop_recrsp_inrecov
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Stack command state lookup tables  */
end_comment

begin_comment
comment|/* SSCOP_INIT */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_init_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|sscop_init_inst
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|NULL
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|NULL
operator|,
comment|/* SOS_INRESYN */
function_decl|NULL
operator|,
comment|/* SOS_OUTRECOV */
function_decl|NULL
operator|,
comment|/* SOS_RECOVRSP */
function_decl|NULL
operator|,
comment|/* SOS_INRECOV */
function_decl|NULL
operator|,
comment|/* SOS_READY */
function_decl|NULL
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_TERM */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_term_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|sscop_term_all
operator|,
comment|/* SOS_INST */
function_decl|sscop_term_all
operator|,
comment|/* SOS_IDLE */
function_decl|sscop_term_all
operator|,
comment|/* SOS_OUTCONN */
function_decl|sscop_term_all
operator|,
comment|/* SOS_INCONN */
function_decl|sscop_term_all
operator|,
comment|/* SOS_OUTDISC */
function_decl|sscop_term_all
operator|,
comment|/* SOS_OUTRESYN */
function_decl|sscop_term_all
operator|,
comment|/* SOS_INRESYN */
function_decl|sscop_term_all
operator|,
comment|/* SOS_OUTRECOV */
function_decl|sscop_term_all
operator|,
comment|/* SOS_RECOVRSP */
function_decl|sscop_term_all
operator|,
comment|/* SOS_INRECOV */
function_decl|sscop_term_all
operator|,
comment|/* SOS_READY */
function_decl|sscop_term_all
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_ESTABLISH_REQ */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_estreq_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|sscop_estreq_idle
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|NULL
operator|,
comment|/* SOS_INCONN */
function_decl|sscop_estreq_idle
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|NULL
operator|,
comment|/* SOS_INRESYN */
function_decl|NULL
operator|,
comment|/* SOS_OUTRECOV */
function_decl|NULL
operator|,
comment|/* SOS_RECOVRSP */
function_decl|NULL
operator|,
comment|/* SOS_INRECOV */
function_decl|NULL
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_1
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_ESTABLISH_RSP */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_estrsp_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|sscop_estrsp_inconn
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|NULL
operator|,
comment|/* SOS_INRESYN */
function_decl|NULL
operator|,
comment|/* SOS_OUTRECOV */
function_decl|NULL
operator|,
comment|/* SOS_RECOVRSP */
function_decl|NULL
operator|,
comment|/* SOS_INRECOV */
function_decl|NULL
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_1
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_RELEASE_REQ */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_relreq_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|sscop_relreq_outconn
operator|,
comment|/* SOS_OUTCONN */
function_decl|sscop_relreq_inconn
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|sscop_relreq_outconn
operator|,
comment|/* SOS_OUTRESYN */
function_decl|sscop_relreq_outconn
operator|,
comment|/* SOS_INRESYN */
function_decl|sscop_relreq_ready
operator|,
comment|/* SOS_OUTRECOV */
function_decl|sscop_relreq_outconn
operator|,
comment|/* SOS_RECOVRSP */
function_decl|sscop_relreq_outconn
operator|,
comment|/* SOS_INRECOV */
function_decl|sscop_relreq_ready
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_1
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_DATA_REQ */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_datreq_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|NULL
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|NULL
operator|,
comment|/* SOS_INRESYN */
function_decl|sscop_aa_noop_1
operator|,
comment|/* SOS_OUTRECOV */
function_decl|NULL
operator|,
comment|/* SOS_RECOVRSP */
function_decl|NULL
operator|,
comment|/* SOS_INRECOV */
function_decl|sscop_datreq_ready
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_1
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_RESYNC_REQ */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_resreq_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|NULL
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|NULL
operator|,
comment|/* SOS_INRESYN */
function_decl|sscop_resreq_ready
operator|,
comment|/* SOS_OUTRECOV */
function_decl|sscop_resreq_ready
operator|,
comment|/* SOS_RECOVRSP */
function_decl|sscop_resreq_ready
operator|,
comment|/* SOS_INRECOV */
function_decl|sscop_resreq_ready
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_1
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_RESYNC_RSP */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_resrsp_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|NULL
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|sscop_resrsp_inresyn
operator|,
comment|/* SOS_INRESYN */
function_decl|NULL
operator|,
comment|/* SOS_OUTRECOV */
function_decl|NULL
operator|,
comment|/* SOS_RECOVRSP */
function_decl|NULL
operator|,
comment|/* SOS_INRECOV */
function_decl|NULL
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_0
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_RECOVER_RSP */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_recrsp_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|NULL
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|NULL
operator|,
comment|/* SOS_INRESYN */
function_decl|NULL
operator|,
comment|/* SOS_OUTRECOV */
function_decl|sscop_recrsp_recovrsp
operator|,
comment|/* SOS_RECOVRSP */
function_decl|sscop_recrsp_inrecov
operator|,
comment|/* SOS_INRECOV */
function_decl|NULL
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_0
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_UNITDATA_REQ */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_udtreq_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_IDLE */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_OUTCONN */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_INCONN */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_OUTDISC */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_OUTRESYN */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_INRESYN */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_OUTRECOV */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_RECOVRSP */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_INRECOV */
function_decl|sscop_udtreq_all
operator|,
comment|/* SOS_READY */
function_decl|sscop_aa_noop_1
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/* SSCOP_RETRIEVE_REQ */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|sscop_retreq_tab
index|[
name|SOS_NUMSTATES
index|]
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|NULL
operator|,
comment|/* SOS_INST */
function_decl|NULL
operator|,
comment|/* SOS_IDLE */
function_decl|NULL
operator|,
comment|/* SOS_OUTCONN */
function_decl|NULL
operator|,
comment|/* SOS_INCONN */
function_decl|NULL
operator|,
comment|/* SOS_OUTDISC */
function_decl|NULL
operator|,
comment|/* SOS_OUTRESYN */
function_decl|NULL
operator|,
comment|/* SOS_INRESYN */
function_decl|NULL
operator|,
comment|/* SOS_OUTRECOV */
function_decl|NULL
operator|,
comment|/* SOS_RECOVRSP */
function_decl|NULL
operator|,
comment|/* SOS_INRECOV */
function_decl|NULL
operator|,
comment|/* SOS_READY */
function_decl|NULL
end_function_decl

begin_comment
comment|/* SOS_TERM */
end_comment

begin_comment
unit|};
comment|/*  * Stack command lookup table  */
end_comment

begin_expr_stmt
name|void
argument_list|(
operator|*
operator|(
operator|*
name|sscop_q2110_aatab
index|[
name|SSCOP_CMD_SIZE
index|]
operator|)
argument_list|)
argument_list|(
expr|struct
name|sscop
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
operator|=
block|{
name|NULL
block|,
name|sscop_init_tab
block|,
name|sscop_term_tab
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|sscop_estreq_tab
block|,
name|NULL
block|,
name|sscop_estrsp_tab
block|,
name|NULL
block|,
name|sscop_relreq_tab
block|,
name|NULL
block|,
name|NULL
block|,
name|sscop_datreq_tab
block|,
name|NULL
block|,
name|sscop_resreq_tab
block|,
name|NULL
block|,
name|sscop_resrsp_tab
block|,
name|NULL
block|,
name|NULL
block|,
name|sscop_recrsp_tab
block|,
name|sscop_udtreq_tab
block|,
name|NULL
block|,
name|sscop_retreq_tab
block|,
name|NULL
block|,
name|NULL
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * SSCOP_RESYNC_REQ / SOS_READY Command Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	pointer to buffer containing SSCOP-UU data  *	arg2	unused  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_resreq_ready
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
comment|/* 	 * We don't support SSCOP-UU data 	 */
if|if
condition|(
name|arg1
operator|!=
name|SSCOP_UU_NULL
condition|)
name|KB_FREEALL
argument_list|(
operator|(
name|KBuffer
operator|*
operator|)
name|arg1
argument_list|)
expr_stmt|;
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
comment|/* 	 * Send first RS PDU 	 */
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
name|sscop_send_rs
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Drain transmit and receive queues 	 */
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
comment|/* 	 * Wait for RSAK 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_OUTRESYN
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SSCOP_RESYNC_RSP / SOS_INRESYN Command Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	unused  *	arg2	unused  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_resrsp_inresyn
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
comment|/* 	 * Clear transmitter buffers 	 */
name|q2110_clear_xmit
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/*  	 * Initialize state variables 	 */
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
name|q2110_init_state
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Send RSAK PDU 	 */
operator|(
name|void
operator|)
name|sscop_send_rsak
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Start data transfer timers 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_POLL
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timepoll
expr_stmt|;
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timeresp
expr_stmt|;
comment|/* 	 * Back to data transfer state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_READY
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SSCOP_RECOVER_RSP / SOS_RECOVRSP Command Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	unused  *	arg2	unused  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_recrsp_recovrsp
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
comment|/* 	 * Clear transmitter buffers, if not done earlier 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_NOCLRBUF
condition|)
name|q2110_clear_xmit
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/*  	 * Initialize state variables 	 */
name|q2110_init_state
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Start data transfer timers 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_POLL
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timepoll
expr_stmt|;
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timeresp
expr_stmt|;
comment|/* 	 * Back to data transfer state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_READY
expr_stmt|;
comment|/* 	 * See if transmit queues need servicing 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_XMITSRVC
condition|)
name|sscop_service_xmit
argument_list|(
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SSCOP_RECOVER_RSP / SOS_INRECOV Command Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	unused  *	arg2	unused  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_recrsp_inrecov
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
comment|/* 	 * Clear transmitter buffers, if not done earlier 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_NOCLRBUF
condition|)
name|q2110_clear_xmit
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/*  	 * Initialize state variables 	 */
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
name|q2110_init_state
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Send ERAK PDU 	 */
operator|(
name|void
operator|)
name|sscop_send_erak
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Start data transfer timers 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_POLL
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timepoll
expr_stmt|;
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timeresp
expr_stmt|;
comment|/* 	 * Back to data transfer state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_READY
expr_stmt|;
comment|/* 	 * See if transmit queues need servicing 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_XMITSRVC
condition|)
name|sscop_service_xmit
argument_list|(
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

