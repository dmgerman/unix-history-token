begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/get_request.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_get_request_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/get_request.c,v 4.8 90/06/25 20:56:06 kfall Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_comment
comment|/*  * This procedure is obsolete.  It is used in the kerberos_slave  * code for Version 3 tickets.  *  * This procedure sets s_name, and instance to point to  * the corresponding fields from tne nth request in the packet.  * it returns the lifetime requested.  Garbage will be returned  * if there are less than n requests in the packet.  */
end_comment

begin_macro
name|get_request
argument_list|(
argument|pkt
argument_list|,
argument|n
argument_list|,
argument|s_name
argument_list|,
argument|instance
argument_list|)
end_macro

begin_decl_stmt
name|KTEXT
name|pkt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The packet itself */
end_comment

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which request do we want */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|s_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Service name to be filled in */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|instance
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Instance name to be filled in */
end_comment

begin_block
block|{
comment|/* Go to the beginning of the request list */
name|char
modifier|*
name|ptr
init|=
operator|(
name|char
operator|*
operator|)
name|pkt_a_realm
argument_list|(
name|pkt
argument_list|)
operator|+
literal|6
operator|+
name|strlen
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pkt_a_realm
argument_list|(
name|pkt
argument_list|)
argument_list|)
decl_stmt|;
comment|/* Read requests until we hit the right one */
while|while
condition|(
name|n
operator|--
operator|>
literal|1
condition|)
block|{
name|ptr
operator|++
expr_stmt|;
name|ptr
operator|+=
literal|1
operator|+
name|strlen
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
name|ptr
operator|+=
literal|1
operator|+
name|strlen
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
comment|/* Set the arguments to point to the right place */
operator|*
name|s_name
operator|=
literal|1
operator|+
name|ptr
expr_stmt|;
operator|*
name|instance
operator|=
literal|2
operator|+
name|ptr
operator|+
name|strlen
argument_list|(
operator|*
name|s_name
argument_list|)
expr_stmt|;
comment|/* Return the requested lifetime */
return|return
operator|(
operator|(
name|int
operator|)
operator|*
name|ptr
operator|)
return|;
block|}
end_block

end_unit

