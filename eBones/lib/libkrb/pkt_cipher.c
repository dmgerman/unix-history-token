begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: pkt_cipher.c,v 4.8 89/01/13 17:46:14 steiner Exp $  * $FreeBSD$  */
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
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_comment
comment|/*  * This routine takes a reply packet from the Kerberos ticket-granting  * service and returns a pointer to the beginning of the ciphertext in it.  *  * See "prot.h" for packet format.  */
end_comment

begin_function
name|KTEXT
name|pkt_cipher
parameter_list|(
name|packet
parameter_list|)
name|KTEXT
name|packet
decl_stmt|;
block|{
name|unsigned
name|char
modifier|*
name|ptr
init|=
name|pkt_a_realm
argument_list|(
name|packet
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
name|packet
argument_list|)
argument_list|)
decl_stmt|;
comment|/* Skip a few more fields */
name|ptr
operator|+=
literal|3
operator|+
literal|4
expr_stmt|;
comment|/* add 4 for exp_date */
comment|/* And return the pointer */
return|return
operator|(
operator|(
name|KTEXT
operator|)
name|ptr
operator|)
return|;
block|}
end_function

end_unit

