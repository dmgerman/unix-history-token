begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * UNI IP interface module  *  */
end_comment

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_include
include|#
directive|include
file|<netatm/ipatm/ipatm_var.h>
end_include

begin_include
include|#
directive|include
file|<netatm/ipatm/ipatm_serv.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/uniip_var.h>
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

begin_decl_stmt
specifier|static
name|int
name|uniip_ipact
name|__P
argument_list|(
operator|(
expr|struct
name|ip_nif
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|uniip_ipdact
name|__P
argument_list|(
operator|(
expr|struct
name|ip_nif
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
name|struct
name|uniip
modifier|*
name|uniip_head
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ip_serv
name|uniip_ipserv
init|=
block|{
name|uniip_ipact
block|,
name|uniip_ipdact
block|,
name|uniarp_ioctl
block|,
name|uniarp_pvcopen
block|,
name|uniarp_svcout
block|,
name|uniarp_svcin
block|,
name|uniarp_svcactive
block|,
name|uniarp_vcclose
block|,
name|NULL
block|,
block|{
block|{
name|ATM_AAL5
block|,
name|ATM_ENC_LLC
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local variables  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sp_info
name|uniip_pool
init|=
block|{
literal|"uni ip pool"
block|,
comment|/* si_name */
sizeof|sizeof
argument_list|(
expr|struct
name|uniip
argument_list|)
block|,
comment|/* si_blksiz */
literal|2
block|,
comment|/* si_blkcnt */
literal|100
comment|/* si_maxallow */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Process module loading notification  *   * Called whenever the uni module is initializing.    *  * Arguments:  *	none  *  * Returns:  *	0	initialization successful  *	errno	initialization failed - reason indicated  *  */
end_comment

begin_function
name|int
name|uniip_start
parameter_list|()
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Tell arp to initialize stuff 	 */
name|err
operator|=
name|uniarp_start
argument_list|()
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Process module unloading notification  *   * Called whenever the uni module is about to be unloaded.  All signalling  * instances will have been previously detached.  All uniip resources  * must be freed now.  *  * Arguments:  *	none  *  * Returns:  *	0	shutdown was successful   *	errno	shutdown failed - reason indicated  *  */
end_comment

begin_function
name|int
name|uniip_stop
parameter_list|()
block|{
comment|/* 	 * All IP interfaces should be gone 	 */
if|if
condition|(
name|uniip_head
condition|)
return|return
operator|(
name|EBUSY
operator|)
return|;
comment|/* 	 * Tell arp to stop 	 */
name|uniarp_stop
argument_list|()
expr_stmt|;
comment|/* 	 * Free our storage pools 	 */
name|atm_release_pool
argument_list|(
operator|&
name|uniip_pool
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
comment|/*  * Process IP Network Interface Activation  *   * Called whenever an IP network interface becomes active.  *  * Called at splnet.  *  * Arguments:  *	inp	pointer to IP network interface  *  * Returns:  *	0 	command successful  *	errno	command failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uniip_ipact
parameter_list|(
name|inp
parameter_list|)
name|struct
name|ip_nif
modifier|*
name|inp
decl_stmt|;
block|{
name|struct
name|uniip
modifier|*
name|uip
decl_stmt|;
comment|/* 	 * Make sure we don't already have this interface 	 */
for|for
control|(
name|uip
operator|=
name|uniip_head
init|;
name|uip
condition|;
name|uip
operator|=
name|uip
operator|->
name|uip_next
control|)
block|{
if|if
condition|(
name|uip
operator|->
name|uip_ipnif
operator|==
name|inp
condition|)
return|return
operator|(
name|EEXIST
operator|)
return|;
block|}
comment|/* 	 * Get a new interface control block 	 */
name|uip
operator|=
operator|(
expr|struct
name|uniip
operator|*
operator|)
name|atm_allocate
argument_list|(
operator|&
name|uniip_pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|uip
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENOMEM
operator|)
return|;
comment|/* 	 * Initialize and link up 	 */
name|uip
operator|->
name|uip_ipnif
operator|=
name|inp
expr_stmt|;
name|LINK2TAIL
argument_list|(
name|uip
argument_list|,
expr|struct
name|uniip
argument_list|,
name|uniip_head
argument_list|,
name|uip_next
argument_list|)
expr_stmt|;
comment|/* 	 * Link from IP world 	 */
name|inp
operator|->
name|inf_isintf
operator|=
operator|(
name|caddr_t
operator|)
name|uip
expr_stmt|;
comment|/* 	 * Tell arp about new interface 	 */
name|uniarp_ipact
argument_list|(
name|uip
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
comment|/*  * Process IP Network Interface Deactivation  *   * Called whenever an IP network interface becomes inactive.  *  * Called at splnet.  *  * Arguments:  *	inp	pointer to IP network interface  *  * Returns:  *	0 	command successful  *	errno	command failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uniip_ipdact
parameter_list|(
name|inp
parameter_list|)
name|struct
name|ip_nif
modifier|*
name|inp
decl_stmt|;
block|{
name|struct
name|uniip
modifier|*
name|uip
decl_stmt|;
comment|/* 	 * Get the appropriate IP interface block 	 */
name|uip
operator|=
operator|(
expr|struct
name|uniip
operator|*
operator|)
name|inp
operator|->
name|inf_isintf
expr_stmt|;
if|if
condition|(
name|uip
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* 	 * Let arp know about this 	 */
name|uniarp_ipdact
argument_list|(
name|uip
argument_list|)
expr_stmt|;
comment|/* 	 * Free interface info 	 */
name|UNLINK
argument_list|(
name|uip
argument_list|,
expr|struct
name|uniip
argument_list|,
name|uniip_head
argument_list|,
name|uip_next
argument_list|)
expr_stmt|;
if|if
condition|(
name|uip
operator|->
name|uip_prefix
operator|!=
name|NULL
condition|)
name|KM_FREE
argument_list|(
name|uip
operator|->
name|uip_prefix
argument_list|,
name|uip
operator|->
name|uip_nprefix
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|uniarp_prf
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
name|atm_free
argument_list|(
operator|(
name|caddr_t
operator|)
name|uip
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

