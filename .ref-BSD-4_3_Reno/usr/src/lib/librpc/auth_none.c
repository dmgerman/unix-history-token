begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)auth_none.c 1.4 85/03/17 Copyr 1984 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * auth_none.c  * Creates a client authentication handle for passing "null"   * credentials and verifiers to remote systems.   *   * Copyright (C) 1984, Sun Microsystems, Inc.   */
end_comment

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"xdr.h"
end_include

begin_include
include|#
directive|include
file|"auth.h"
end_include

begin_define
define|#
directive|define
name|NULL
value|((caddr_t)0)
end_define

begin_define
define|#
directive|define
name|MAX_MARSHEL_SIZE
value|20
end_define

begin_comment
comment|/*  * Authenticator operations routines  */
end_comment

begin_function_decl
specifier|static
name|void
name|authnone_verf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|authnone_destroy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool_t
name|authnone_marshal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool_t
name|authnone_validate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool_t
name|authnone_refresh
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|auth_ops
name|ops
init|=
block|{
name|authnone_verf
block|,
name|authnone_marshal
block|,
name|authnone_validate
block|,
name|authnone_refresh
block|,
name|authnone_destroy
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|AUTH
name|no_client
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|marshalled_client
index|[
name|MAX_MARSHEL_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|mcnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|AUTH
modifier|*
name|authnone_create
parameter_list|()
block|{
name|XDR
name|xdr_stream
decl_stmt|;
specifier|register
name|XDR
modifier|*
name|xdrs
decl_stmt|;
if|if
condition|(
operator|!
name|mcnt
condition|)
block|{
name|no_client
operator|.
name|ah_cred
operator|=
name|no_client
operator|.
name|ah_verf
operator|=
name|_null_auth
expr_stmt|;
name|no_client
operator|.
name|ah_ops
operator|=
operator|&
name|ops
expr_stmt|;
name|xdrs
operator|=
operator|&
name|xdr_stream
expr_stmt|;
name|xdrmem_create
argument_list|(
name|xdrs
argument_list|,
name|marshalled_client
argument_list|,
operator|(
name|u_int
operator|)
name|MAX_MARSHEL_SIZE
argument_list|,
name|XDR_ENCODE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|!
name|xdr_opaque_auth
argument_list|(
name|xdrs
argument_list|,
operator|&
name|no_client
operator|.
name|ah_cred
argument_list|)
operator|)
operator|||
operator|(
operator|!
name|xdr_opaque_auth
argument_list|(
name|xdrs
argument_list|,
operator|&
name|no_client
operator|.
name|ah_verf
argument_list|)
operator|)
condition|)
block|{ 		}
else|else
block|{
name|mcnt
operator|=
name|XDR_GETPOS
argument_list|(
name|xdrs
argument_list|)
expr_stmt|;
block|}
name|XDR_DESTROY
argument_list|(
name|xdrs
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
operator|&
name|no_client
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool_t
comment|/* ARGSUSED */
name|authnone_marshal
parameter_list|(
name|client
parameter_list|,
name|xdrs
parameter_list|)
name|AUTH
modifier|*
name|client
decl_stmt|;
name|XDR
modifier|*
name|xdrs
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|xdrs
operator|->
name|x_ops
operator|->
name|x_putbytes
call|)
argument_list|(
name|xdrs
argument_list|,
name|marshalled_client
argument_list|,
name|mcnt
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|authnone_verf
parameter_list|()
block|{ }
end_function

begin_function
specifier|static
name|bool_t
name|authnone_validate
parameter_list|()
block|{
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool_t
name|authnone_refresh
parameter_list|()
block|{
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|authnone_destroy
parameter_list|()
block|{ }
end_function

end_unit

