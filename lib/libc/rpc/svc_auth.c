begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986-1991 by Sun Microsystems Inc.   */
end_comment

begin_empty
empty|#ident	"@(#)svc_auth.c	1.16	94/04/24 SMI"
end_empty

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
name|defined
argument_list|(
name|SCCSIDS
argument_list|)
end_if

begin_if
if|#
directive|if
literal|0
end_if

begin_else
unit|static char sccsid[] = "@(#)svc_auth.c 1.26 89/02/07 Copyr 1984 Sun Micro";
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * svc_auth.c, Server-side rpc authenticator interface.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_include
include|#
directive|include
file|<rpc/auth.h>
end_include

begin_include
include|#
directive|include
file|<rpc/clnt.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc_msg.h>
end_include

begin_include
include|#
directive|include
file|<rpc/svc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/svc_auth.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
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
comment|/* (system) unix style (uid, gids) */
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

begin_function_decl
name|enum
name|auth_stat
name|_svcauth_des
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* des style */
end_comment

begin_comment
comment|/* declarations to allow servers to specify new authentication flavors */
end_comment

begin_struct
struct|struct
name|authsvc
block|{
name|int
name|flavor
decl_stmt|;
name|enum
name|auth_stat
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|()
function_decl|;
name|struct
name|authsvc
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|authsvc
modifier|*
name|Auths
init|=
name|NULL
decl_stmt|;
end_decl_stmt

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
specifier|register
name|struct
name|authsvc
modifier|*
name|asp
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
switch|switch
condition|(
name|cred_flavor
condition|)
block|{
case|case
name|AUTH_NULL
case|:
return|return
operator|(
name|_svcauth_null
argument_list|(
name|rqst
argument_list|,
name|msg
argument_list|)
operator|)
return|;
case|case
name|AUTH_UNIX
case|:
return|return
operator|(
name|_svcauth_unix
argument_list|(
name|rqst
argument_list|,
name|msg
argument_list|)
operator|)
return|;
case|case
name|AUTH_SHORT
case|:
return|return
operator|(
name|_svcauth_short
argument_list|(
name|rqst
argument_list|,
name|msg
argument_list|)
operator|)
return|;
comment|/* 	 * We leave AUTH_DES turned off by default because svcauth_des() 	 * needs getpublickey(), which is in librpcsvc, not libc. If we  	 * included AUTH_DES as a built-in flavor, programs that don't 	 * have -lrpcsvc in their Makefiles wouldn't link correctly, even 	 * though they don't use AUTH_DES. And I'm too lazy to go through 	 * the tree looking for all of them. 	 */
ifdef|#
directive|ifdef
name|DES_BUILTIN
case|case
name|AUTH_DES
case|:
return|return
operator|(
name|_svcauth_des
argument_list|(
name|rqst
argument_list|,
name|msg
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
comment|/* flavor doesn't match any of the builtin types, so try new ones */
for|for
control|(
name|asp
operator|=
name|Auths
init|;
name|asp
condition|;
name|asp
operator|=
name|asp
operator|->
name|next
control|)
block|{
if|if
condition|(
name|asp
operator|->
name|flavor
operator|==
name|cred_flavor
condition|)
block|{
name|enum
name|auth_stat
name|as
decl_stmt|;
name|as
operator|=
call|(
modifier|*
name|asp
operator|->
name|handler
call|)
argument_list|(
name|rqst
argument_list|,
name|msg
argument_list|)
expr_stmt|;
return|return
operator|(
name|as
operator|)
return|;
block|}
block|}
return|return
operator|(
name|AUTH_REJECTEDCRED
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|enum
name|auth_stat
name|_svcauth_null
parameter_list|(
name|rqst
parameter_list|,
name|msg
parameter_list|)
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
return|return
operator|(
name|AUTH_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *  Allow the rpc service to register new authentication types that it is  *  prepared to handle.  When an authentication flavor is registered,  *  the flavor is checked against already registered values.  If not  *  registered, then a new Auths entry is added on the list.  *  *  There is no provision to delete a registration once registered.  *  *  This routine returns:  *	 0 if registration successful  *	 1 if flavor already registered  *	-1 if can't register (errno set)  */
end_comment

begin_decl_stmt
name|int
name|svc_auth_reg
argument_list|(
name|cred_flavor
argument_list|,
name|handler
argument_list|)
decl|register
name|int
name|cred_flavor
decl_stmt|;
end_decl_stmt

begin_function_decl
name|enum
name|auth_stat
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
specifier|register
name|struct
name|authsvc
modifier|*
name|asp
decl_stmt|;
switch|switch
condition|(
name|cred_flavor
condition|)
block|{
case|case
name|AUTH_NULL
case|:
case|case
name|AUTH_UNIX
case|:
case|case
name|AUTH_SHORT
case|:
ifdef|#
directive|ifdef
name|DES_BUILTIN
case|case
name|AUTH_DES
case|:
endif|#
directive|endif
comment|/* already registered */
return|return
operator|(
literal|1
operator|)
return|;
default|default:
for|for
control|(
name|asp
operator|=
name|Auths
init|;
name|asp
condition|;
name|asp
operator|=
name|asp
operator|->
name|next
control|)
block|{
if|if
condition|(
name|asp
operator|->
name|flavor
operator|==
name|cred_flavor
condition|)
block|{
comment|/* already registered */
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
comment|/* this is a new one, so go ahead and register it */
name|asp
operator|=
operator|(
expr|struct
name|authsvc
operator|*
operator|)
name|mem_alloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|asp
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|asp
operator|==
name|NULL
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|asp
operator|->
name|flavor
operator|=
name|cred_flavor
expr_stmt|;
name|asp
operator|->
name|handler
operator|=
name|handler
expr_stmt|;
name|asp
operator|->
name|next
operator|=
name|Auths
expr_stmt|;
name|Auths
operator|=
name|asp
expr_stmt|;
break|break;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

