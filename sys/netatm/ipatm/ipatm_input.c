begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  */
end_comment

begin_comment
comment|/*  * IP Over ATM Support  * -------------------  *  * Process stack and data input  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
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
file|<netatm/ipatm/ipatm_var.h>
end_include

begin_comment
comment|/*  * Process VCC Input Data  *   * Arguments:  *	tok	ipatm connection token (pointer to ipvcc)  *	m	pointer to input packet buffer chain  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|ipatm_cpcs_data
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
name|ipvcc
modifier|*
name|ivp
init|=
name|tok
decl_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
name|ipatm_print
condition|)
block|{
name|atm_pdu_print
argument_list|(
name|m
argument_list|,
literal|"ipatm_input"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 	 * Handle input packet 	 */
if|if
condition|(
name|ivp
operator|->
name|iv_state
operator|!=
name|IPVCC_ACTIVE
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|ipatm_stat
operator|.
name|ias_rcvstate
operator|++
expr_stmt|;
return|return;
block|}
comment|/* 	 * IP packet - reset idle timer 	 */
name|ivp
operator|->
name|iv_idle
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Pass packet to IP 	 */
operator|(
name|void
operator|)
name|ipatm_ipinput
argument_list|(
name|ivp
operator|->
name|iv_ipnif
argument_list|,
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * IP Input Packet Handler  *   * All IP packets received from various ATM sources will be sent here  * for final queuing to the IP layer.  *  * Arguments:  *	inp	pointer to packet's receiving IP network interface  *	m	pointer to packet buffer chain  *  * Returns:  *	0	packet successfully queued to IP layer  *	else	error queuing packet, buffer chain freed  *  */
end_comment

begin_function
name|int
name|ipatm_ipinput
parameter_list|(
name|inp
parameter_list|,
name|m
parameter_list|)
name|struct
name|ip_nif
modifier|*
name|inp
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
name|ipatm_print
condition|)
block|{
name|atm_pdu_print
argument_list|(
name|m
argument_list|,
literal|"ipatm_ipinput"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
operator|!
name|KB_ISPKT
argument_list|(
name|m
argument_list|)
condition|)
block|{
name|panic
argument_list|(
literal|"ipatm_ipinput: no packet header"
argument_list|)
expr_stmt|;
block|}
block|{
name|int
name|cnt
init|=
literal|0
decl_stmt|;
name|KBuffer
modifier|*
name|m0
init|=
name|m
decl_stmt|;
while|while
condition|(
name|m0
condition|)
block|{
name|cnt
operator|+=
name|KB_LEN
argument_list|(
name|m0
argument_list|)
expr_stmt|;
name|m0
operator|=
name|KB_NEXT
argument_list|(
name|m0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m
operator|->
name|m_pkthdr
operator|.
name|len
operator|!=
name|cnt
condition|)
block|{
name|panic
argument_list|(
literal|"ipatm_ipinput: packet length incorrect"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* 	 * Save the input ifnet pointer in the packet header 	 */
name|m
operator|->
name|m_pkthdr
operator|.
name|rcvif
operator|=
operator|(
expr|struct
name|ifnet
operator|*
operator|)
name|inp
operator|->
name|inf_nif
expr_stmt|;
comment|/* 	 * Finally, hand packet off to IP. 	 * 	 * NB: Since we're already in the softint kernel state, we 	 * just call IP directly to avoid the extra unnecessary  	 * kernel scheduling. 	 */
name|netisr_dispatch
argument_list|(
name|NETISR_IP
argument_list|,
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

end_unit

