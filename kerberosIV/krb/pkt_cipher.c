begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/pkt_cipher.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
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
name|rcsid_pkt_cipher_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/pkt_cipher.c,v 4.9 90/06/25 20:57:02 kfall Exp $"
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

