begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_comment
comment|/*static char *sccsid = "from: @(#)svc_auth.c 1.19 87/08/11 Copyr 1984 Sun Micro";*/
end_comment

begin_comment
comment|/*static char *sccsid = "from: @(#)svc_auth.c	2.1 88/08/07 4.0 RPCSRC";*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * svc_auth_nodes.c, Server-side rpc authenticator interface,  * *WITHOUT* DES authentication.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_comment
comment|/*  * svcauthsw is the bdevsw of server side authentication.  *  * Server side authenticators are called from authenticate by  * using the client auth struct flavor field to index into svcauthsw.  * The server auth flavors must implement a routine that looks  * like:  *  *	enum auth_stat  *	flavorx_auth(rqst, msg)  *		register struct svc_req *rqst;  *		register struct rpc_msg *msg;  *  */
end_comment

begin_function_decl
name|enum
name|auth_stat
name|_svcauth_null
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* no authentication */
end_comment

begin_function_decl
name|enum
name|auth_stat
name|_svcauth_unix
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* unix style (uid, gids) */
end_comment

begin_function_decl
name|enum
name|auth_stat
name|_svcauth_short
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* short hand unix style */
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|enum
name|auth_stat
function_decl|(
modifier|*
name|authenticator
function_decl|)
parameter_list|()
function_decl|;
block|}
name|svcauthsw
index|[]
init|=
block|{
name|_svcauth_null
block|,
comment|/* AUTH_NULL */
name|_svcauth_unix
block|,
comment|/* AUTH_UNIX */
name|_svcauth_short
block|,
comment|/* AUTH_SHORT */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AUTH_MAX
value|2
end_define

begin_comment
comment|/* HIGHEST AUTH NUMBER */
end_comment

begin_comment
comment|/*  * The call rpc message, msg has been obtained from the wire.  The msg contains  * the raw form of credentials and verifiers.  authenticate returns AUTH_OK  * if the msg is successfully authenticated.  If AUTH_OK then the routine also  * does the following things:  * set rqst->rq_xprt->verf to the appropriate response verifier;  * sets rqst->rq_client_cred to the "cooked" form of the credentials.  *  * NB: rqst->rq_cxprt->verf must be pre-alloctaed;  * its length is set appropriately.  *  * The caller still owns and is responsible for msg->u.cmb.cred and  * msg->u.cmb.verf.  The authentication system retains ownership of  * rqst->rq_client_cred, the cooked credentials.  *  * There is an assumption that any flavour less than AUTH_NULL is  * invalid.  */
end_comment

begin_function
name|enum
name|auth_stat
name|_authenticate
parameter_list|(
name|rqst
parameter_list|,
name|msg
parameter_list|)
specifier|register
name|struct
name|svc_req
modifier|*
name|rqst
decl_stmt|;
name|struct
name|rpc_msg
modifier|*
name|msg
decl_stmt|;
block|{
specifier|register
name|int
name|cred_flavor
decl_stmt|;
name|rqst
operator|->
name|rq_cred
operator|=
name|msg
operator|->
name|rm_call
operator|.
name|cb_cred
expr_stmt|;
name|rqst
operator|->
name|rq_xprt
operator|->
name|xp_verf
operator|.
name|oa_flavor
operator|=
name|_null_auth
operator|.
name|oa_flavor
expr_stmt|;
name|rqst
operator|->
name|rq_xprt
operator|->
name|xp_verf
operator|.
name|oa_length
operator|=
literal|0
expr_stmt|;
name|cred_flavor
operator|=
name|rqst
operator|->
name|rq_cred
operator|.
name|oa_flavor
expr_stmt|;
if|if
condition|(
operator|(
name|cred_flavor
operator|<=
name|AUTH_MAX
operator|)
operator|&&
operator|(
name|cred_flavor
operator|>=
name|AUTH_NULL
operator|)
condition|)
block|{
return|return
operator|(
operator|(
operator|*
operator|(
name|svcauthsw
index|[
name|cred_flavor
index|]
operator|.
name|authenticator
operator|)
operator|)
operator|(
name|rqst
operator|,
name|msg
operator|)
operator|)
return|;
block|}
return|return
operator|(
name|AUTH_REJECTEDCRED
operator|)
return|;
block|}
end_function

begin_function
name|enum
name|auth_stat
name|_svcauth_null
parameter_list|(
comment|/*rqst, msg*/
parameter_list|)
comment|/*struct svc_req *rqst; 	struct rpc_msg *msg;*/
block|{
return|return
operator|(
name|AUTH_OK
operator|)
return|;
block|}
end_function

end_unit

