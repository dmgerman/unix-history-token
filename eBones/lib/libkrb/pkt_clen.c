begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: pkt_clen.c,v 4.7 88/11/15 16:56:36 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char *rcsid = "$FreeBSD$";
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
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

begin_decl_stmt
specifier|extern
name|int
name|krb_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swap_bytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Given a pointer to an AUTH_MSG_KDC_REPLY packet, return the length of  * its ciphertext portion.  The external variable "swap_bytes" is assumed  * to have been set to indicate whether or not the packet is in local  * byte order.  pkt_clen() takes this into account when reading the  * ciphertext length out of the packet.  */
end_comment

begin_function
name|int
name|pkt_clen
parameter_list|(
name|pkt
parameter_list|)
name|KTEXT
name|pkt
decl_stmt|;
block|{
specifier|static
name|unsigned
name|short
name|temp
decl_stmt|,
name|temp2
decl_stmt|;
name|int
name|clen
init|=
literal|0
decl_stmt|;
comment|/* Start of ticket list */
name|unsigned
name|char
modifier|*
name|ptr
init|=
name|pkt_a_realm
argument_list|(
name|pkt
argument_list|)
operator|+
literal|10
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
comment|/* Finally the length */
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|++
name|ptr
operator|)
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|temp
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|/* alignment */
if|if
condition|(
name|swap_bytes
condition|)
block|{
comment|/* assume a short is 2 bytes?? */
name|swab
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|temp
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|temp2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|temp
operator|=
name|temp2
expr_stmt|;
block|}
name|clen
operator|=
operator|(
name|int
operator|)
name|temp
expr_stmt|;
if|if
condition|(
name|krb_debug
condition|)
name|printf
argument_list|(
literal|"Clen is %d\n"
argument_list|,
name|clen
argument_list|)
expr_stmt|;
return|return
operator|(
name|clen
operator|)
return|;
block|}
end_function

end_unit

