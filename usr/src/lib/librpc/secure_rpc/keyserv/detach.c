begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)detach.c	2.2 88/08/10 4.0 RPCSRC"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/*  * detach from tty  */
end_comment

begin_macro
name|detachfromtty
argument_list|()
end_macro

begin_block
block|{
name|int
name|tt
decl_stmt|;
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|2
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|fork
argument_list|()
condition|)
block|{
case|case
operator|-
literal|1
case|:
name|perror
argument_list|(
literal|"fork"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0
case|:
break|break;
default|default:
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|tt
operator|=
name|open
argument_list|(
literal|"/dev/tty"
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|tt
operator|>
literal|0
condition|)
block|{
name|ioctl
argument_list|(
name|tt
argument_list|,
name|TIOCNOTTY
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|tt
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|dup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

