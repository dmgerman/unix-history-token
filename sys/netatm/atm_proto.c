begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM socket protocol family support definitions  *  */
end_comment

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
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

begin_decl_stmt
name|struct
name|protosw
name|atmsw
index|[]
init|=
block|{
block|{
name|SOCK_DGRAM
block|,
comment|/* ioctl()-only */
operator|&
name|atmdomain
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* pr_input */
literal|0
block|,
comment|/* pr_output */
literal|0
block|,
comment|/* pr_ctlinput */
literal|0
block|,
comment|/* pr_ctloutput */
literal|0
block|,
comment|/* pr_ousrreq */
literal|0
block|,
comment|/* pr_init */
literal|0
block|,
comment|/* pr_fasttimo */
literal|0
block|,
comment|/* pr_slowtimo */
literal|0
block|,
comment|/* pr_drain */
operator|&
name|atm_dgram_usrreqs
block|,
comment|/* pr_usrreqs */
block|}
block|,
block|{
name|SOCK_SEQPACKET
block|,
comment|/* AAL-5 */
operator|&
name|atmdomain
block|,
name|ATM_PROTO_AAL5
block|,
name|PR_ATOMIC
operator||
name|PR_CONNREQUIRED
block|,
literal|0
block|,
comment|/* pr_input */
literal|0
block|,
comment|/* pr_output */
literal|0
block|,
comment|/* pr_ctlinput */
name|atm_aal5_ctloutput
block|,
comment|/* pr_ctloutput */
literal|0
block|,
comment|/* pr_ousrreq */
literal|0
block|,
comment|/* pr_init */
literal|0
block|,
comment|/* pr_fasttimo */
literal|0
block|,
comment|/* pr_slowtimo */
literal|0
block|,
comment|/* pr_drain */
operator|&
name|atm_aal5_usrreqs
block|,
comment|/* pr_usrreqs */
block|}
block|,
ifdef|#
directive|ifdef
name|XXX
block|{
name|SOCK_SEQPACKET
block|,
comment|/* SSCOP */
operator|&
name|atmdomain
block|,
name|ATM_PROTO_SSCOP
block|,
name|PR_ATOMIC
operator||
name|PR_CONNREQUIRED
operator||
name|PR_WANTRCVD
block|,
name|x
block|,
comment|/* pr_input */
name|x
block|,
comment|/* pr_output */
name|x
block|,
comment|/* pr_ctlinput */
name|x
block|,
comment|/* pr_ctloutput */
literal|0
block|,
comment|/* pr_ousrreq */
literal|0
block|,
comment|/* pr_init */
literal|0
block|,
comment|/* pr_fasttimo */
literal|0
block|,
comment|/* pr_slowtimo */
name|x
block|,
comment|/* pr_drain */
name|x
block|,
comment|/* pr_usrreqs */
block|}
block|,
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|atmdomain
init|=
block|{
name|AF_ATM
block|,
literal|"atm"
block|,
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|atm_initialize
block|,
else|#
directive|else
literal|0
block|,
endif|#
directive|endif
literal|0
block|,
literal|0
block|,
name|atmsw
block|,
operator|&
name|atmsw
index|[
sizeof|sizeof
argument_list|(
name|atmsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|atmsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_expr_stmt
name|DOMAIN_SET
argument_list|(
name|atm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199506
operator|)
operator|)
end_if

begin_comment
comment|/*  * Protocol request not supported  *  * Arguments:  *	so	pointer to socket  *  * Returns:  *	errno	error - operation not supported  *  */
end_comment

begin_function
name|int
name|atm_proto_notsupp1
parameter_list|(
name|so
parameter_list|)
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Protocol request not supported  *  * Arguments:  *	so	pointer to socket  *	addr	pointer to protocol address  *	p	pointer to process  *  * Returns:  *	errno	error - operation not supported  *  */
end_comment

begin_function
name|int
name|atm_proto_notsupp2
parameter_list|(
name|so
parameter_list|,
name|addr
parameter_list|,
name|p
parameter_list|)
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Protocol request not supported  *  * Arguments:  *	so	pointer to socket  *	addr	pointer to pointer to protocol address  *  * Returns:  *	errno	error - operation not supported  *  */
end_comment

begin_function
name|int
name|atm_proto_notsupp3
parameter_list|(
name|so
parameter_list|,
name|addr
parameter_list|)
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
name|struct
name|sockaddr
modifier|*
modifier|*
name|addr
decl_stmt|;
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Protocol request not supported  *  * Arguments:  *	so	pointer to socket  *	i	integer  *	m	pointer to kernel buffer  *	addr	pointer to protocol address  *	m2	pointer to kernel buffer  *	p	pointer to process  *  * Returns:  *	errno	error - operation not supported  *  */
end_comment

begin_function
name|int
name|atm_proto_notsupp4
parameter_list|(
name|so
parameter_list|,
name|i
parameter_list|,
name|m
parameter_list|,
name|addr
parameter_list|,
name|m2
parameter_list|,
name|p
parameter_list|)
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
name|int
name|i
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
name|KBuffer
modifier|*
name|m2
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(__FreeBSD__)&& (BSD>= 199506)) */
end_comment

end_unit

