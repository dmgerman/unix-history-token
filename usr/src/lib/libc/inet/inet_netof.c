begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)inet_netof.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

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
comment|/*  * Return the network number from an internet  * address; handles class a/b/c network #'s.  */
end_comment

begin_macro
name|inet_netof
argument_list|(
argument|in
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|in_addr
name|in
decl_stmt|;
end_decl_stmt

begin_block
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
operator|(
name|i
operator|)
operator|&
name|IN_CLASSA_NET
operator|)
operator|>>
name|IN_CLASSA_NSHIFT
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
operator|(
name|i
operator|)
operator|&
name|IN_CLASSB_NET
operator|)
operator|>>
name|IN_CLASSB_NSHIFT
operator|)
return|;
else|else
return|return
operator|(
operator|(
operator|(
name|i
operator|)
operator|&
name|IN_CLASSC_NET
operator|)
operator|>>
name|IN_CLASSC_NSHIFT
operator|)
return|;
block|}
end_block

end_unit

