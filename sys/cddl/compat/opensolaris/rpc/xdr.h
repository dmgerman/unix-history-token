begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_RPC_XDR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_RPC_XDR_H_
end_define

begin_empty
empty|#include_next<rpc/xdr.h>
end_empty

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|/*  * Taken from sys/xdr/xdr_mem.c.  *  * FreeBSD's userland XDR doesn't implement control method (only the kernel),  * but OpenSolaris nvpair still depend on it, so we have to implement it here.  */
end_comment

begin_function
specifier|static
name|__inline
name|bool_t
name|xdrmem_control
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|int
name|request
parameter_list|,
name|void
modifier|*
name|info
parameter_list|)
block|{
name|xdr_bytesrec
modifier|*
name|xptr
decl_stmt|;
switch|switch
condition|(
name|request
condition|)
block|{
case|case
name|XDR_GET_BYTES_AVAIL
case|:
name|xptr
operator|=
operator|(
name|xdr_bytesrec
operator|*
operator|)
name|info
expr_stmt|;
name|xptr
operator|->
name|xc_is_last_record
operator|=
name|TRUE
expr_stmt|;
name|xptr
operator|->
name|xc_num_avail
operator|=
name|xdrs
operator|->
name|x_handy
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
default|default:
name|assert
argument_list|(
operator|!
literal|"unexpected request"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|XDR_CONTROL
end_undef

begin_define
define|#
directive|define
name|XDR_CONTROL
parameter_list|(
name|xdrs
parameter_list|,
name|req
parameter_list|,
name|op
parameter_list|)
define|\
value|(((xdrs)->x_ops->x_control == NULL) ?				\ 	    xdrmem_control((xdrs), (req), (op)) :			\ 	    (*(xdrs)->x_ops->x_control)(xdrs, req, op))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_RPC_XDR_H_ */
end_comment

end_unit

