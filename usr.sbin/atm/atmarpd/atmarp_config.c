begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * SCSP-ATMARP server interface: configuration support  *  */
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
comment|/*  * Configure network interface for ATMARP cache synchronization  *  * Verify the network interface name and set the appropriate fields  * in the ATMARP interface entry.  *  * Arguments:  *	netif	pointer to network interface name  *  * Returns:  *	0	success  *	errno	reason for failure  *  */
end_comment

begin_function
name|int
name|atmarp_cfg_netif
parameter_list|(
name|netif
parameter_list|)
name|char
modifier|*
name|netif
decl_stmt|;
block|{
name|int
name|rc
decl_stmt|;
name|Atmarp_intf
modifier|*
name|aip
init|=
operator|(
name|Atmarp_intf
operator|*
operator|)
literal|0
decl_stmt|;
comment|/* 	 * Get an ATMARP interface block 	 */
name|aip
operator|=
operator|(
name|Atmarp_intf
operator|*
operator|)
name|UM_ALLOC
argument_list|(
sizeof|sizeof
argument_list|(
name|Atmarp_intf
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|aip
condition|)
name|atmarp_mem_err
argument_list|(
literal|"atmarp_cfg_netif: sizeof(Atmarp_intf)"
argument_list|)
expr_stmt|;
name|UM_ZERO
argument_list|(
name|aip
argument_list|,
sizeof|sizeof
argument_list|(
name|Atmarp_intf
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Make sure we're configuring a valid 	 * network interface 	 */
name|rc
operator|=
name|verify_nif_name
argument_list|(
name|netif
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: \"%s\" is not a valid network interface\n"
argument_list|,
name|prog
argument_list|,
name|netif
argument_list|)
expr_stmt|;
name|rc
operator|=
name|EINVAL
expr_stmt|;
goto|goto
name|cfg_fail
goto|;
block|}
elseif|else
if|if
condition|(
name|rc
operator|<
literal|0
condition|)
block|{
name|rc
operator|=
name|errno
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: can't verify network interface \"%s\"\n"
argument_list|,
name|prog
argument_list|,
name|netif
argument_list|)
expr_stmt|;
goto|goto
name|cfg_fail
goto|;
block|}
comment|/* 	 * Update the interface entry 	 */
name|strcpy
argument_list|(
name|aip
operator|->
name|ai_intf
argument_list|,
name|netif
argument_list|)
expr_stmt|;
name|aip
operator|->
name|ai_state
operator|=
name|AI_STATE_NULL
expr_stmt|;
name|aip
operator|->
name|ai_scsp_sock
operator|=
operator|-
literal|1
expr_stmt|;
name|LINK2TAIL
argument_list|(
name|aip
argument_list|,
name|Atmarp_intf
argument_list|,
name|atmarp_intf_head
argument_list|,
name|ai_next
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
name|cfg_fail
label|:
if|if
condition|(
name|aip
condition|)
name|UM_FREE
argument_list|(
name|aip
argument_list|)
expr_stmt|;
return|return
operator|(
name|rc
operator|)
return|;
block|}
end_function

end_unit

