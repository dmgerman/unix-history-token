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
literal|"@(#)getnetbyaddr.c	5.3 (Berkeley) 5/19/86"
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
file|<netdb.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|_net_stayopen
decl_stmt|;
end_decl_stmt

begin_function
name|struct
name|netent
modifier|*
name|getnetbyaddr
parameter_list|(
name|net
parameter_list|,
name|type
parameter_list|)
specifier|register
name|int
name|net
decl_stmt|,
name|type
decl_stmt|;
block|{
specifier|register
name|struct
name|netent
modifier|*
name|p
decl_stmt|;
name|setnetent
argument_list|(
name|_net_stayopen
argument_list|)
expr_stmt|;
while|while
condition|(
name|p
operator|=
name|getnetent
argument_list|()
condition|)
if|if
condition|(
name|p
operator|->
name|n_addrtype
operator|==
name|type
operator|&&
name|p
operator|->
name|n_net
operator|==
name|net
condition|)
break|break;
if|if
condition|(
operator|!
name|_net_stayopen
condition|)
name|endnetent
argument_list|()
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

end_unit

