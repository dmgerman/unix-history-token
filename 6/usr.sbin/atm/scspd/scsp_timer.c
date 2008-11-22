begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * Timer processing  *  */
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
file|<libatm.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"scsp_msg.h"
end_include

begin_include
include|#
directive|include
file|"scsp_if.h"
end_include

begin_include
include|#
directive|include
file|"scsp_var.h"
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
comment|/*  * Process an SCSP Open timeout  *  * The open timer is set when an attempt to open a VCC to a DCS fails.  * This routine will be called when the timer fires and will retry  * the open.  Retries can continue indefinitely.  *  * Arguments:  *	stp	pointer to an SCSP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|scsp_open_timeout
parameter_list|(
name|stp
parameter_list|)
name|Harp_timer
modifier|*
name|stp
decl_stmt|;
block|{
name|Scsp_dcs
modifier|*
name|dcsp
decl_stmt|;
comment|/* 	 * Back off to start of DCS entry 	 */
name|dcsp
operator|=
operator|(
name|Scsp_dcs
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|stp
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
name|Scsp_dcs
operator|*
operator|)
literal|0
operator|)
operator|->
name|sd_open_t
argument_list|)
operator|)
expr_stmt|;
comment|/* 	 * Retry the connection 	 */
if|if
condition|(
name|scsp_dcs_connect
argument_list|(
name|dcsp
argument_list|)
condition|)
block|{
comment|/* 		 * Connect failed -- we hope the error was temporary 		 * and set the timer to try again later 		 */
name|HARP_TIMER
argument_list|(
operator|&
name|dcsp
operator|->
name|sd_open_t
argument_list|,
name|SCSP_Open_Interval
argument_list|,
name|scsp_open_timeout
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Process an SCSP Hello timeout  *  * The Hello timer fires every SCSP_HELLO_Interval seconds.  This  * routine will notify the Hello FSM when the timer fires.  *  * Arguments:  *	stp	pointer to an SCSP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|scsp_hello_timeout
parameter_list|(
name|stp
parameter_list|)
name|Harp_timer
modifier|*
name|stp
decl_stmt|;
block|{
name|Scsp_dcs
modifier|*
name|dcsp
decl_stmt|;
comment|/* 	 * Back off to start of DCS entry 	 */
name|dcsp
operator|=
operator|(
name|Scsp_dcs
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|stp
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
name|Scsp_dcs
operator|*
operator|)
literal|0
operator|)
operator|->
name|sd_hello_h_t
argument_list|)
operator|)
expr_stmt|;
comment|/* 	 * Call the Hello FSM 	 */
operator|(
name|void
operator|)
name|scsp_hfsm
argument_list|(
name|dcsp
argument_list|,
name|SCSP_HFSM_HELLO_T
argument_list|,
operator|(
name|Scsp_msg
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Process an SCSP receive timeout  *  * The receive timer is started whenever the Hello FSM receives a  * Hello message from its DCS.  If the timer fires, it means that no  * Hello messages have been received in the DCS's Hello interval.  *  * Arguments:  *	stp	pointer to an SCSP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|scsp_hello_rcv_timeout
parameter_list|(
name|stp
parameter_list|)
name|Harp_timer
modifier|*
name|stp
decl_stmt|;
block|{
name|Scsp_dcs
modifier|*
name|dcsp
decl_stmt|;
comment|/* 	 * Back off to start of DCS entry 	 */
name|dcsp
operator|=
operator|(
name|Scsp_dcs
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|stp
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
name|Scsp_dcs
operator|*
operator|)
literal|0
operator|)
operator|->
name|sd_hello_rcv_t
argument_list|)
operator|)
expr_stmt|;
comment|/* 	 * Call the Hello FSM 	 */
operator|(
name|void
operator|)
name|scsp_hfsm
argument_list|(
name|dcsp
argument_list|,
name|SCSP_HFSM_RCV_T
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Process an SCSP CA retransmit timeout  *  * Arguments:  *	stp	pointer to an SCSP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|scsp_ca_retran_timeout
parameter_list|(
name|stp
parameter_list|)
name|Harp_timer
modifier|*
name|stp
decl_stmt|;
block|{
name|Scsp_dcs
modifier|*
name|dcsp
decl_stmt|;
comment|/* 	 * Back off to start of DCS entry 	 */
name|dcsp
operator|=
operator|(
name|Scsp_dcs
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|stp
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
name|Scsp_dcs
operator|*
operator|)
literal|0
operator|)
operator|->
name|sd_ca_rexmt_t
argument_list|)
operator|)
expr_stmt|;
comment|/* 	 * Call the CA FSM 	 */
operator|(
name|void
operator|)
name|scsp_cafsm
argument_list|(
name|dcsp
argument_list|,
name|SCSP_CAFSM_CA_T
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Process an SCSP CSUS retransmit timeout  *  * Arguments:  *	stp	pointer to an SCSP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|scsp_csus_retran_timeout
parameter_list|(
name|stp
parameter_list|)
name|Harp_timer
modifier|*
name|stp
decl_stmt|;
block|{
name|Scsp_dcs
modifier|*
name|dcsp
decl_stmt|;
comment|/* 	 * Back off to start of DCS entry 	 */
name|dcsp
operator|=
operator|(
name|Scsp_dcs
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|stp
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
name|Scsp_dcs
operator|*
operator|)
literal|0
operator|)
operator|->
name|sd_csus_rexmt_t
argument_list|)
operator|)
expr_stmt|;
comment|/* 	 * Call the CA FSM 	 */
operator|(
name|void
operator|)
name|scsp_cafsm
argument_list|(
name|dcsp
argument_list|,
name|SCSP_CAFSM_CSUS_T
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Process an SCSP CSU Req retransmit timeout  *  * Arguments:  *	stp	pointer to an SCSP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|scsp_csu_req_retran_timeout
parameter_list|(
name|stp
parameter_list|)
name|Harp_timer
modifier|*
name|stp
decl_stmt|;
block|{
name|Scsp_csu_rexmt
modifier|*
name|rxp
decl_stmt|;
name|Scsp_dcs
modifier|*
name|dcsp
decl_stmt|;
comment|/* 	 * Back off to start of CSU Request retransmission entry 	 */
name|rxp
operator|=
operator|(
name|Scsp_csu_rexmt
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|stp
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
name|Scsp_csu_rexmt
operator|*
operator|)
literal|0
operator|)
operator|->
name|sr_t
argument_list|)
operator|)
expr_stmt|;
name|dcsp
operator|=
name|rxp
operator|->
name|sr_dcs
expr_stmt|;
comment|/* 	 * Call the CA FSM 	 */
operator|(
name|void
operator|)
name|scsp_cafsm
argument_list|(
name|dcsp
argument_list|,
name|SCSP_CAFSM_CSU_T
argument_list|,
operator|(
name|void
operator|*
operator|)
name|rxp
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

