begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * SCSP-ATMARP server interface: timer routines  *  */
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"../scspd/scsp_msg.h"
end_include

begin_include
include|#
directive|include
file|"../scspd/scsp_if.h"
end_include

begin_include
include|#
directive|include
file|"../scspd/scsp_var.h"
end_include

begin_include
include|#
directive|include
file|"atmarp_var.h"
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
comment|/*  * Cache update timeout processing  *  * When the cache update timer fires, we read the cache from the  * kernel, update the internal cache, and restart the timer.  *  * Arguments:  *	tp	pointer to a HARP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|atmarp_cache_timeout
parameter_list|(
name|tp
parameter_list|)
name|Harp_timer
modifier|*
name|tp
decl_stmt|;
block|{
name|Atmarp_intf
modifier|*
name|aip
decl_stmt|;
comment|/* 	 * Verify the status of all configured interfaces 	 */
for|for
control|(
name|aip
operator|=
name|atmarp_intf_head
init|;
name|aip
condition|;
name|aip
operator|=
name|aip
operator|->
name|ai_next
control|)
block|{
if|if
condition|(
name|atmarp_if_ready
argument_list|(
name|aip
argument_list|)
condition|)
block|{
comment|/* 			 * The interface is up but we don't have 			 * a connection to SCSP--make a connection 			 */
if|if
condition|(
name|aip
operator|->
name|ai_state
operator|==
name|AI_STATE_NULL
condition|)
operator|(
name|void
operator|)
name|atmarp_scsp_connect
argument_list|(
name|aip
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 			 * The interface is down--disconnect from SCSP 			 */
if|if
condition|(
name|aip
operator|->
name|ai_state
operator|!=
name|AI_STATE_NULL
condition|)
operator|(
name|void
operator|)
name|atmarp_scsp_disconnect
argument_list|(
name|aip
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	 * Read the cache from the kernel 	 */
name|atmarp_get_updated_cache
argument_list|()
expr_stmt|;
comment|/* 	 * Restart the cache update timer 	 */
name|HARP_TIMER
argument_list|(
name|tp
argument_list|,
name|ATMARP_CACHE_INTERVAL
argument_list|,
name|atmarp_cache_timeout
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Permanent cache entry timer processing  *  * Permanent cache entries (entries that are administratively added  * and the entry for the server itself) don't ever get refreshed, so  * we broadcast updates for them every 10 minutes so they won't get  * deleted from the remote servers' caches  *  * Arguments:  *	tp	pointer to a HARP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|atmarp_perm_timeout
parameter_list|(
name|tp
parameter_list|)
name|Harp_timer
modifier|*
name|tp
decl_stmt|;
block|{
name|int
name|i
decl_stmt|,
name|rc
decl_stmt|;
name|Atmarp_intf
modifier|*
name|aip
decl_stmt|;
name|Atmarp
modifier|*
name|aap
decl_stmt|;
comment|/* 	 * Loop through all interfaces 	 */
for|for
control|(
name|aip
operator|=
name|atmarp_intf_head
init|;
name|aip
condition|;
name|aip
operator|=
name|aip
operator|->
name|ai_next
control|)
block|{
comment|/* 		 * Loop through the interface's cache 		 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ATMARP_HASHSIZ
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|aap
operator|=
name|aip
operator|->
name|ai_arptbl
index|[
name|i
index|]
init|;
name|aap
condition|;
name|aap
operator|=
name|aap
operator|->
name|aa_next
control|)
block|{
comment|/* 				 * Find and update permanent entries 				 */
if|if
condition|(
operator|(
name|aap
operator|->
name|aa_flags
operator|&
operator|(
name|AAF_PERM
operator||
name|AAF_SERVER
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|aap
operator|->
name|aa_seq
operator|++
expr_stmt|;
name|rc
operator|=
name|atmarp_scsp_update
argument_list|(
name|aap
argument_list|,
name|SCSP_ASTATE_UPD
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
comment|/* 	 * Restart the permanent cache entry timer 	 */
name|HARP_TIMER
argument_list|(
name|tp
argument_list|,
name|ATMARP_PERM_INTERVAL
argument_list|,
name|atmarp_perm_timeout
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Keepalive timeout processing  *  * When the keepalive timer fires, we send a NOP to SCSP.  This  * will help us detect a broken connection.  *  * Arguments:  *	tp	pointer to a HARP timer block  *  * Returns:  *	None  *  */
end_comment

begin_function
name|void
name|atmarp_keepalive_timeout
parameter_list|(
name|tp
parameter_list|)
name|Harp_timer
modifier|*
name|tp
decl_stmt|;
block|{
name|Atmarp_intf
modifier|*
name|aip
decl_stmt|;
name|Scsp_if_msg
modifier|*
name|msg
decl_stmt|;
comment|/* 	 * Back off to start of DCS entry 	 */
name|aip
operator|=
operator|(
name|Atmarp_intf
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|tp
operator|-
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
name|Atmarp_intf
operator|*
operator|)
literal|0
operator|)
operator|->
name|ai_keepalive_t
argument_list|)
operator|)
expr_stmt|;
comment|/* 	 * Get a message buffer 	 */
name|msg
operator|=
operator|(
name|Scsp_if_msg
operator|*
operator|)
name|UM_ALLOC
argument_list|(
sizeof|sizeof
argument_list|(
name|Scsp_if_msg
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|msg
condition|)
block|{ 	}
name|UM_ZERO
argument_list|(
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|Scsp_if_msg
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Build a NOP message 	 */
name|msg
operator|->
name|si_type
operator|=
name|SCSP_NOP_REQ
expr_stmt|;
name|msg
operator|->
name|si_proto
operator|=
name|SCSP_PROTO_ATMARP
expr_stmt|;
name|msg
operator|->
name|si_len
operator|=
sizeof|sizeof
argument_list|(
name|Scsp_if_msg_hdr
argument_list|)
expr_stmt|;
comment|/* 	 * Send the message to SCSP 	 */
operator|(
name|void
operator|)
name|atmarp_scsp_out
argument_list|(
name|aip
argument_list|,
operator|(
name|char
operator|*
operator|)
name|msg
argument_list|,
name|msg
operator|->
name|si_len
argument_list|)
expr_stmt|;
name|UM_FREE
argument_list|(
name|msg
argument_list|)
expr_stmt|;
comment|/* 	 * Restart the keepalive timer 	 */
name|HARP_TIMER
argument_list|(
operator|&
name|aip
operator|->
name|ai_keepalive_t
argument_list|,
name|ATMARP_KEEPALIVE_INTERVAL
argument_list|,
name|atmarp_keepalive_timeout
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

