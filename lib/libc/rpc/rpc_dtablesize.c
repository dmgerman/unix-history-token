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
comment|/*static char *sccsid = "from: @(#)rpc_dtablesize.c 1.2 87/08/11 Copyr 1987 Sun Micro";*/
end_comment

begin_comment
comment|/*static char *sccsid = "from: @(#)rpc_dtablesize.c	2.1 88/07/29 4.0 RPCSRC";*/
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/*  * Cache the result of getdtablesize(), so we don't have to do an  * expensive system call every time.  */
end_comment

begin_comment
comment|/*  * XXX In FreeBSD 2.x, you can have the maximum number of open file  * descriptors be greater than FD_SETSIZE (which us 256 by default).  *  * Since old programs tend to use this call to determine the first arg  * for select(), having this return> FD_SETSIZE is a Bad Idea(TM)!  */
end_comment

begin_function
name|int
name|_rpc_dtablesize
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|size
decl_stmt|;
if|if
condition|(
name|size
operator|==
literal|0
condition|)
block|{
name|size
operator|=
name|getdtablesize
argument_list|()
expr_stmt|;
if|if
condition|(
name|size
operator|>
name|FD_SETSIZE
condition|)
name|size
operator|=
name|FD_SETSIZE
expr_stmt|;
block|}
return|return
operator|(
name|size
operator|)
return|;
block|}
end_function

end_unit

