begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)inet_lnaof.c	5.5 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/*  * Return the local network address portion of an  * internet address; handles class a/b/c network  * number formats.  */
end_comment

begin_function
name|u_long
name|inet_lnaof
parameter_list|(
name|in
parameter_list|)
name|struct
name|in_addr
name|in
decl_stmt|;
block|{
specifier|register
name|u_long
name|i
init|=
name|ntohl
argument_list|(
name|in
operator|.
name|s_addr
argument_list|)
decl_stmt|;
if|if
condition|(
name|IN_CLASSA
argument_list|(
name|i
argument_list|)
condition|)
return|return
operator|(
operator|(
name|i
operator|)
operator|&
name|IN_CLASSA_HOST
operator|)
return|;
elseif|else
if|if
condition|(
name|IN_CLASSB
argument_list|(
name|i
argument_list|)
condition|)
return|return
operator|(
operator|(
name|i
operator|)
operator|&
name|IN_CLASSB_HOST
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|i
operator|)
operator|&
name|IN_CLASSC_HOST
operator|)
return|;
block|}
end_function

end_unit

